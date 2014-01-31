#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>

#include <sys/time.h> //時間計測用

//スレッド情報
static const int FOLLOW_THREAD_MAX = 10;          //後続スレッド最大数
static volatile int s_followThreadNum = 0;        //後続スレッド数
static volatile int s_followThreadNo = 0;         //後続スレッド番号発番用
static volatile bool s_IsQuirProiorThread = false;//先行スレッド終了フラグ
static pthread_mutex_t s_followThreadMutex = PTHREAD_MUTEX_INITIALIZER;//後続スレッド番号発番用ミューテックス

//条件変数
//※条件変数は、必ず条件変数＋ミューテックス＋変数のセットで扱う
static pthread_cond_t s_followCond[FOLLOW_THREAD_MAX];      //後続スレッド処理完了条件変数
static pthread_mutex_t s_followCondMutex[FOLLOW_THREAD_MAX];//後続スレッド処理完了条件変数ミューテックス
static volatile bool s_followFinished[FOLLOW_THREAD_MAX];   //後続スレッド処理完了フラグ

//【バリア処理追加】バリア
static pthread_barrier_t s_barrier;

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__thread int s_tlsData = 0;

//【処理説明】
//先行スレッドが共有データを作成し、それが完了したら
//複数の後続スレッドがスタート。
//後続スレッドは共有データを読み込むだけのため、並列で動作。
//後続スレッドの処理が全て完了したら、また先行スレッドが稼働。
//【バリア処理追加】後続スレッドの処理完了時は、バリアで足並みを揃える。
//以上を何度か繰り返し、先行スレッドが終了したら全スレッド終了。
//※メインループ⇒描画スレッドのようなリレー処理への応用を想定。

//先行スレッド
void* priorThreadFunc(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);
	
	//開始
	printf("- begin:(P)%s -\n", name);
	fflush(stdout);

	//初期化
	s_IsQuirProiorThread = false;//先行処理終了フラグ

	//処理
	static const int LOOP_COUNT_MAX = 3;
	int loop_counter = 0;
	while (1)
	{
		//全後続スレッド処理完了待ち
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			pthread_mutex_lock(&s_followCondMutex[i]);//ロック取得
			while (!s_followFinished[i])//待機終了条件を満たしていない場合
				pthread_cond_wait(&s_followCond[i], &s_followCondMutex[i]);//待機（ロック開放→待機→待機終了→ロック取得が行われる）
			pthread_mutex_unlock(&s_followCondMutex[i]);//ロック解放
			//※待機をタイムアウトさせたい場合は pthread_cond_timedwait() 関数を用いる。
		}

		//ループカウンタ進行＆終了判定
		if (loop_counter++ == LOOP_COUNT_MAX)
		{
			//処理終了
			printf("(P)%s: [QUIT]\n", name);
			fflush(stdout);
			
			//先行スレッド終了フラグ
			s_IsQuirProiorThread = true;
			
			//先行スレッド処理完了：全待機スレッドを起床
			for (int i = 0; i < s_followThreadNum; ++i)
			{
				pthread_mutex_lock(&s_followCondMutex[i]);//ロック取得
				s_followFinished[i] = false;//後続スレッドの処理完了状態を解除
				pthread_cond_signal(&s_followCond[i]);//解除待ちしているスレッドに通知
				pthread_mutex_unlock(&s_followCondMutex[i]);//ロック解放
			}

			break;
		}

		//データ表示（前）
		printf("(P)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//データ更新
		++common_data;
		++tls_data;

		//若干ランダムでスリープ（0～499 msec）
		usleep((rand() % 500) * 1000);

		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("(P)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//先行スレッド処理完了：全待機スレッドを起床
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			pthread_mutex_lock(&s_followCondMutex[i]);//ロック取得
			s_followFinished[i] = false;//後続スレッドの処理完了状態を解除
			pthread_cond_signal(&s_followCond[i]);//解除待ちしているスレッドに通知
			pthread_mutex_unlock(&s_followCondMutex[i]);//ロック解放
			//※一つの条件変数で多数のスレッドを待機させている場合は、
			//　pthread_cond_broadcast() 関数も使える。
		}

		//スレッド切り替えのためのスリープ
		usleep(0);
	//	//スレッド切り替え
	//	sched_yield();//同じ優先度の他のスレッドに切り替え
	}

	//終了
	printf("- end:(P)%s -\n", name);
	fflush(stdout);
	return 0;
}

//後続スレッド
void* followThreadFunc(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);
	
	//後続スレッド数カウントアップ
	pthread_mutex_lock(&s_followThreadMutex);
	int thread_no = s_followThreadNo++;
	pthread_mutex_unlock(&s_followThreadMutex);

	//開始
	printf("- begin:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);

	//後続スレッド処理完了：待機スレッドを起床
	{
		pthread_mutex_lock(&s_followCondMutex[thread_no]);//ロック取得
		s_followFinished[thread_no] = true;//後続スレッドの処理完了状態をON
		pthread_cond_signal(&s_followCond[thread_no]);//解除待ちしているスレッドに通知
		pthread_mutex_unlock(&s_followCondMutex[thread_no]);//ロック解放
	}

	//処理
	while (1)
	{
		//先行スレッド処理完了待ち
		{
			pthread_mutex_lock(&s_followCondMutex[thread_no]);//ロック取得
			while (s_followFinished[thread_no])//待機終了条件を満たしていない場合
				pthread_cond_wait(&s_followCond[thread_no], &s_followCondMutex[thread_no]);//待機（ロック開放→待機→待機終了→ロック取得が行われる）
			pthread_mutex_unlock(&s_followCondMutex[thread_no]);//ロック解放
			//※待機をタイムアウトさせたい場合は pthread_cond_timedwait() 関数を用いる。
		}

		//終了確認
		if (s_IsQuirProiorThread)
		{
			//処理終了
			printf("(F)[%d]%s: [QUIT]\n", thread_no, name);
			fflush(stdout);
			
			//後続スレッド処理完了：待機スレッドを起床
			{
				pthread_mutex_lock(&s_followCondMutex[thread_no]);//ロック取得
				s_followFinished[thread_no] = true;//後続スレッドの処理完了状態をON
				pthread_cond_signal(&s_followCond[thread_no]);//解除待ちしているスレッドに通知
				pthread_mutex_unlock(&s_followCondMutex[thread_no]);//ロック解放
			}
			
			break;
		}

		//【バリア処理追加】若干ランダムでスリープ（0～500 msec）
		//バリア処理の効果を確認するために追加した処理
		//各スレッドの処理タイミングがバラバラになるように
		usleep((rand() % 500) * 1000);

		//データ表示（前）
		printf("(F)[%d]%s: [BEFORE] commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//データ更新
		++tls_data;

		//若干ランダムでスリープ（0～500 msec）
		usleep((rand() % 500) * 1000);
		
		//【バリア処理追加】以降、バリア処理の効果を確認するために追加した処理
		//各スレッドの処理タイミングがバラバラになるようにしている
		
		//中間表示1（後）
		printf("(F)[%d]%s: [STEP1] commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);

		//若干ランダムでスリープ（0～500 msec）
		usleep((rand() % 500) * 1000);
		
		//中間表示2（後）
		printf("(F)[%d]%s: [STEP2] commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);

		//若干ランダムでスリープ（0～500 msec）
		usleep((rand() % 500) * 1000);
		
		//中間表示3（後）
		printf("(F)[%d]%s: [STEP3] commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);

		//若干ランダムでスリープ（0～500 msec）
		usleep((rand() % 500) * 1000);

		//【バリア処理追加】バリア処理の効果を確認するために追加した処理は、ここまで

		//データ書き戻し
		s_tlsData = tls_data;
		
		//【バリア処理追加】バリアにより、全後続スレッドの処理タイミングを揃える
		pthread_barrier_wait(&s_barrier);
		
		//データ表示（後）
		printf("(F)[%d]%s: [AFTER]  commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);
		
		//後続スレッド処理完了：待機スレッドを起床
		{
			pthread_mutex_lock(&s_followCondMutex[thread_no]);//ロック取得
			s_followFinished[thread_no] = true;//後続スレッドの処理完了状態をON
			pthread_cond_signal(&s_followCond[thread_no]);//解除待ちしているスレッドに通知
			pthread_mutex_unlock(&s_followCondMutex[thread_no]);//ロック取得
			//※一つの条件変数で多数のスレッドを待機させている場合は、
			//　pthread_cond_broadcast() 関数も使える。
		}

		//スレッド切り替えのためのスリープ
		usleep(0);
	//	//スレッド切り替え
	//	sched_yield();//同じ優先度の他のスレッドに切り替え
	}

	//終了
	printf("- end:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);
	return 0;
}


//テスト
int main(const int argc, const char* argv[])
{
	//条件変数＆ミューテックス生成
	//※PTHREAD_COND_INITIALIZER, PTHREAD_MUTEX_INITIALIZER で初期化している場合は不要
	{
		for(int i = 0; i < FOLLOW_THREAD_MAX; ++i)
		{
			pthread_cond_init(&s_followCond[i], NULL);
			pthread_mutex_init(&s_followCondMutex[i], NULL);
		}
	}
	
	//スレッド作成
	static const int FOLLOW_THREAD_NUM = 5;
	static const int THREAD_NUM = 1 + FOLLOW_THREAD_NUM;
	//static_assert(FOLLOW_THREAD_NUM <= FOLLOW_THREAD_MAX, "FOLLOW_THREAD_NUM is over.");
	s_followThreadNum = FOLLOW_THREAD_NUM;
	pthread_barrier_init(&s_barrier, 0, s_followThreadNum);//【バリア処理追加】バリア初期化
	for (int i = 0; i < THREAD_NUM - 1; ++i)
		s_followFinished[i] = true;
	pthread_t pth[THREAD_NUM];
	{
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setstacksize(&attr, 1024);//スタックサイズ指定
		pthread_create(&pth[0], &attr, priorThreadFunc, (void*)"先行");
		pthread_create(&pth[1], &attr, followThreadFunc, (void*)"後続01");
		pthread_create(&pth[2], &attr, followThreadFunc, (void*)"後続02");
		pthread_create(&pth[3], &attr, followThreadFunc, (void*)"後続03");
		pthread_create(&pth[4], &attr, followThreadFunc, (void*)"後続04");
		pthread_create(&pth[5], &attr, followThreadFunc, (void*)"後続05");
	}
	
	//スレッド終了待ち
	for(int i = 0; i < THREAD_NUM; ++i)
	{
		pthread_join(pth[i], NULL);
	}

	//条件変数の取得と解放を大量に実行して時間を計測
	{
		struct timeval begin;
		gettimeofday(&begin, NULL);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			pthread_mutex_lock(&s_followCondMutex[0]);
			s_followFinished[0] = true;
			pthread_cond_signal(&s_followCond[0]);
			pthread_mutex_unlock(&s_followCondMutex[0]);
		}
		struct timeval end;
		gettimeofday(&end, NULL);
		struct timeval duration;
		if( end.tv_usec >= begin.tv_usec)
		{
			duration.tv_sec = end.tv_sec - begin.tv_sec;
			duration.tv_usec = end.tv_usec - begin.tv_usec;
		}
		else
		{
			duration.tv_sec = end.tv_sec - begin.tv_sec - 1;
			duration.tv_usec = 1000000 - begin.tv_usec + end.tv_usec;
		}
		printf("Cond-Sginal * %d = %d.%06d sec\n", TEST_TIMES, duration.tv_sec, duration.tv_usec);
	}

	//【バリア処理追加】バリア破棄
	pthread_barrier_destroy(&s_barrier);
	
	//条件変数＆ミューテックス破棄
	//※PTHREAD_COND_INITIALIZER, PTHREAD_MUTEX_INITIALIZER で初期化している場合は不要
	{
		for(int i = 0; i < FOLLOW_THREAD_MAX; ++i)
		{
			pthread_cond_destroy(&s_followCond[i]);
			pthread_mutex_destroy(&s_followCondMutex[i]);
		}
	}
	
	return EXIT_SUCCESS;
}

// End of file
