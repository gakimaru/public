#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>

#include <sys/time.h> //時間計測用

//CygwinのGCCではこの拡張定数が使えない
//#define PTHREAD_MUTEX_FAST_NP       (0)
//#define PTHREAD_MUTEX_RECURSIVE_NP  (1)
//#define PTHREAD_MUTEX_ERRORCHECK_NP (2)

//ミューテックス
static pthread_mutex_t s_mutex = PTHREAD_MUTEX_INITIALIZER;

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__thread int s_tlsData = 0;

//スレッド
void* threadFunc(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);

	//開始
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//処理
	for (int i = 0; i < 3; ++i)
	{
		//ミューテックス取得
		pthread_mutex_lock(&s_mutex);
	//	pthread_mutex_trylock(&s_mutex);//取得できない時に他の処理を行いたい場合は pthread_mutex_trylock() を使用する
		
		//データ表示（前）
		printf("%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//データ更新
		++common_data;
		++tls_data;

		//若干ランダムでスリープ（0～4 msec）
		usleep((rand() % 5) * 1000);
		
		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//ミューテックス解放
		pthread_mutex_unlock(&s_mutex);
		
		//スレッド切り替えのためのスリープ
		usleep(0);
	//	//スレッド切り替え
	//	sched_yield();//同じ優先度の他のスレッドに切り替え
	}

	//終了
	printf("- end:%s -\n", name);
	fflush(stdout);
	return 0;
}

//テスト
int main(const int argc, const char* argv[])
{
	//ミューテックス生成
	//※PTHREAD_MUTEX_INITIALIZER で初期化している場合は不要
	{
	//	pthread_mutexattr_t attr;
	//	pthread_mutexattr_init(&attr);
	//	pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_PRIVATE);//単独プロセス専用　※デフォルト
	//	pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);//プロセス間で共有
	//	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_FAST_NP);//高速（Fast）ミューテックス属性　※デフォルト
	//	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);//再帰的な (recursive) ミューテックス属性　※多重ロックに対して多重開放が必要
	//	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);//エラー検査を行う (error checking) ミューテックス属性　※デッドロック検出（pthread_mutex_lock() がエラーコード EDEADLK を返す）
	//	pthread_mutex_init(&s_mutex, &attr);
	}
	
	//スレッド作成
	static const int THREAD_NUM = 3;
	pthread_t pth[THREAD_NUM];
	{
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setstacksize(&attr, 1024);//スタックサイズ指定
		pthread_create(&pth[0], &attr, threadFunc, (void*)"太郎");
		pthread_create(&pth[1], &attr, threadFunc, (void*)"次郎");
		pthread_create(&pth[2], &attr, threadFunc, (void*)"三郎");
	}
	
	//スレッド終了待ち
	for(int i = 0; i < THREAD_NUM; ++i)
	{
		pthread_join(pth[i], NULL);
	}
	
	//ミューテックスの取得と解放を大量に実行して時間を計測
	{
		struct timeval begin;
		gettimeofday(&begin, NULL);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			pthread_mutex_lock(&s_mutex);
			pthread_mutex_unlock(&s_mutex);
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
		printf("Mutex * %d = %d.%06d sec\n", TEST_TIMES, duration.tv_sec, duration.tv_usec);
	}
	
	//ミューテックス破棄
	//※PTHREAD_MUTEX_INITIALIZER で初期化している場合は不要
	{
	//	pthread_mutex_destroy(&s_mutex);
	}
	
	return EXIT_SUCCESS;
}

// End of file
