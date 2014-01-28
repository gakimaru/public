#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <pthread.h>
#include <unistd.h>

#include <signal.h>

#include <sys/time.h> //時間計測用

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__thread int s_tlsData = 0;

//スレッド情報
pthread_t s_threadWathc;
pthread_t s_threadSyncSignal;

//受信シグナルバッファ（シグナルハンドラ内処理用）
//※シグナルハンドラ内では「非同期安全な関数」以外使用できない。malloc や prnitf もNG。
//　そのため、シグナルハンドラで受信したシグナルをプールし、
//　専用の処理スレッドに受け渡すようにする。
struct SIG_INFO
{
	int sig;
	pthread_t pth;
	int tls;
	SIG_INFO& operator =(const SIG_INFO& o)
	{
		memcpy(this, &o, sizeof(*this));
		return *this;
	}
};
static const int SIGNAL_RCV_MAX = 5;      //最大受信シグナル数
static volatile int s_sigBuffCnt = 0;     //受信シグナル数
static SIG_INFO s_sigBuff[SIGNAL_RCV_MAX];//受信シグナルバッファ
static pthread_cond_t s_sigBuffC = PTHREAD_COND_INITIALIZER;  //受信シグナルバッファ用条件変数
static pthread_mutex_t s_sigBuffM = PTHREAD_MUTEX_INITIALIZER;//受信シグナルバッファ用ミューテックス

//同期シグナル用のシグナルマスク
static sigset_t s_sigSet;

//シグナル受信バッファ登録
bool pushSigBuff(SIG_INFO& info)
{
	bool result = false;
	pthread_mutex_lock(&s_sigBuffM);
	if(s_sigBuffCnt < SIGNAL_RCV_MAX)
	{
		s_sigBuff[s_sigBuffCnt++] = info;
		pthread_cond_signal(&s_sigBuffC);
		result = true;
	}
	pthread_mutex_unlock(&s_sigBuffM);
	return result;
}
//シグナル受信バッファ取り出し
SIG_INFO popSigBuff(bool is_lock = true)
{
	SIG_INFO info = {-1, 0, 0};
	if(is_lock)
		pthread_mutex_lock(&s_sigBuffM);
	if(s_sigBuffCnt > 0)
	{
		info = s_sigBuff[0];
		--s_sigBuffCnt;
		for(int i = 0; i < s_sigBuffCnt; ++i)
		{
			s_sigBuff[i] = s_sigBuff[i + 1];
		}
	}
	if(is_lock)
		pthread_mutex_unlock(&s_sigBuffM);
	return info;
}
//シグナル受信待ち受け
SIG_INFO watchSigBuff()
{
	//シグナル受信バッファへの登録待ち
	pthread_mutex_lock(&s_sigBuffM);
	while (s_sigBuffCnt == 0)
		pthread_cond_wait(&s_sigBuffC, &s_sigBuffM);
	SIG_INFO info = popSigBuff(false);
	pthread_mutex_unlock(&s_sigBuffM);
	return info;
}

//シグナル名取得
const char* getSigName(int sig)
{
#define CASE_TO_STR(x) case x: return #x; break
	switch(sig)
	{
	CASE_TO_STR(SIGINT);
	CASE_TO_STR(SIGTSTP);
	CASE_TO_STR(SIGCONT);
	CASE_TO_STR(SIGQUIT);
	CASE_TO_STR(SIGTRAP);
	CASE_TO_STR(SIGUSR1);
	CASE_TO_STR(SIGUSR2);
	CASE_TO_STR(SIGALRM);
	}
#undef  CASE_TO_STR
	static char unknown[32];
	sprintf(unknown, "(unknown:%d)", sig);
	return unknown;
}

//シグナル情報作成
SIG_INFO makeSigInfo(int sig)
{
	SIG_INFO info = {sig, pthread_self(), s_tlsData};
	return info;
}

//シグナル情報表示
void printSigInfo(SIG_INFO& info)
{
	printf("[%s] (thread=%x) tls=%d\n", getSigName(info.sig), info.pth, info.tls);
	fflush(stdout);
}
void printSigInfo(int sig)
{
	SIG_INFO info = makeSigInfo(sig);
	printSigInfo(info);
}

//汎用シグナルハンドラ関数（スレッドではない）
//※シグナルハンドラは「プロセス」に対するシグナルをハンドリングする関数
void signalHandler(int sig)
{
	SIG_INFO info = makeSigInfo(sig);
	pushSigBuff(info);
}

//アラーム用シグナルハンドラ関数
void alarmFunc(int sig)
{
	if(s_tlsData++ < 10)
	{
		//汎用シグナルハンドラ処理
		signalHandler(sig);
		
		//1秒後に再アラーム
		alarm(1);
	}
	else
	{
		//規定回数アラームを発行したら終了する
		
		//汎用シグナルハンドラでSIGINT（割り込み：CTRL + C）を処理
		signalHandler(SIGINT);
	}
}

//同期シグナルを送信
void sendSyncSignal(int sig)
{
	//同期シグナルスレッドが受け付け可能なシグナルを送信
	if(sigismember(&s_sigSet, sig))
	{
		printf("sendSyncSignal:[%s] (thread=%x) tls=%d\n", getSigName(sig), pthread_self(), s_tlsData);
		fflush(stdout);
		
		//シグナル送信
		pthread_kill(s_threadSyncSignal, sig);
	}
}

//非同期シグナル受信バッファ監視スレッド
void* threadFuncWatch(void* param_p)
{
	//開始
	printf("- begin:threadFuncWatch(%x) -\n", pthread_self());
	fflush(stdout);
	
	//非同期シグナルバッファ受信処理
	while(1)
	{
		//受信バッファが溜まるまで待機
		SIG_INFO info = watchSigBuff();
		
		//受信したシグナルを表示
		printSigInfo(info);
		
		//シグナルをリレーする
		sendSyncSignal(info.sig);
		
		//シグナルがSIGINTなら終了
		if(info.sig == SIGINT)
		{
			//同期シグナルに SIGTRAP を送って終了をうながす
			sendSyncSignal(SIGTRAP);
			break;
		}
	}
	
	//若干スリープ
	sleep(1);
	
	//終了
	printf("- end:threadFuncWatch(%x) -\n", pthread_self());
	fflush(stdout);
	return 0;
}

//同期シグナルスレッド
void* threadFuncSyncSignal(void* param_p)
{
	//開始
	printf("- begin:threadFuncSyncSignal(%x) -\n", pthread_self());
	fflush(stdout);
	
	//joinせずにスレッドを終了させるために、スレッドをデタッチする
	//※スレッド生成時に最初からデタッチ状態の属性を与えることも可能。
	pthread_detach(pthread_self());
	
	//シグナルマスクをセット
	pthread_sigmask(SIG_BLOCK, &s_sigSet, NULL);
	//※これにより、ここで設定したシグナルは、このスレッドに
	//　キューイングされるようになり、sigwait() で取り出せるようになる。
	//【Linuxの挙動】
	//※プロセスに対するシグナルには反応しない。
	//【Cygwinの挙動】
	//※プロセスに対するシグナルに反応する。
	//　先に同じシグナルに対するシグナルハンドラーが設定されていても、
	//　こちらが優先される。（両方は反応しない）
	
	//同期シグナル処理
	while(1)
	{
		//シグナル受信待ち
		//【Linuxの挙動】
		//※マスク対象シグナル以外のシグナルが直接送られてくると
		//　普通に受信するものの、キューから削除されず復帰できない。
		//【Cygwinの挙動】
		//※マスク対象シグナル以外のシグナルが直接送られてくると
		//　sigwait() がエラーを返す。
		//　キューから削除されないので、復帰できない。
		int sig;
		if(sigwait(&s_sigSet, &sig) != 0)
		{
			fprintf(stderr, "sigwait() failed.\n");
			fflush(stderr);
			break;
		}
		
		//カウンターを進める
		++s_tlsData;
		
		//シグナル表示
		printSigInfo(sig);
		
		//シグナルがSIGINTもしくはSIGTRAPなら終了
		if(sig == SIGINT || sig == SIGTRAP)
			break;
	}
	
	//終了
	printf("- end:threadFuncSyncSignal(%x) -\n", pthread_self());
	fflush(stdout);
	return 0;
}

//テスト
int main(const int argc, const char* argv[])
{
	//開始
	printf("- begin:main(%x) -\n", pthread_self());
	fflush(stdout);
	
	//同期シグナル用のシグナルマスク作成
	sigemptyset(&s_sigSet);
//	sigaddset(&s_sigSet, SIGINT); //割り込み（CTRL + C）
	sigaddset(&s_sigSet, SIGQUIT);//終了とコアダンプ（CTRL + \）
	sigaddset(&s_sigSet, SIGCONT);//停止していれば再開
	sigaddset(&s_sigSet, SIGTSTP);//端末からの中断シグナル（CTRL + Z）
	sigaddset(&s_sigSet, SIGTRAP);//トレース/ブレークポイントによるトラップ
//	sigaddset(&s_sigSet, SIGUSR1);//ユーザー定義シグナル 1
	sigaddset(&s_sigSet, SIGUSR2);//ユーザー定義シグナル 2
	
	//スレッド作成
	static const int THREAD_NUM = 1;
	pthread_t pth[THREAD_NUM];
	{
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setstacksize(&attr, 1024);//スタックサイズ指定
		pthread_create(&s_threadSyncSignal, &attr, threadFuncSyncSignal, NULL);//同期シグナルスレッド
		pthread_create(&s_threadWathc, &attr, threadFuncWatch, NULL);  //非同期シグナル受信バッファ監視スレッド
	}
	
	//シグナルハンドラを登録　※非同期シグナル処理
	signal(SIGINT,  signalHandler);//割り込み（CTRL + C）
	signal(SIGQUIT, signalHandler);//終了とコアダンプ（CTRL + \）
	signal(SIGCONT, signalHandler);//停止していれば再開
	signal(SIGTSTP, signalHandler);//端末からの中断シグナル（CTRL + Z）
//	signal(SIGTRAP, signalHandler);//トレース/ブレークポイントによるトラップ
	signal(SIGUSR1, signalHandler);//ユーザー定義シグナル 1
//	signal(SIGUSR2, signalHandler);//ユーザー定義シグナル 2
	
	//アラーム用のシグナルハンドラを登録　※非同期シグナル処理
	signal(SIGALRM, alarmFunc);
	
	//1秒後にアラーム
	//※アラームとスリープを同時に使用すると、sleepが効かないので注意！
	alarm(1);
	
	//スレッド終了待ち
	pthread_join(s_threadWathc, NULL);
	
	//終了
	printf("- end:main(%x) -\n", pthread_self());
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
