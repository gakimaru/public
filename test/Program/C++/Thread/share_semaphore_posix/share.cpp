#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#include <sys/time.h> //時間計測用

//セマフォ
static sem_t s_semaphore;

//ミューテックス
static pthread_mutex_t s_mutex = PTHREAD_MUTEX_INITIALIZER;

//共有リソース
static const int COMMON_RESOURCE_NUM = 2;
static int s_commonResource[COMMON_RESOURCE_NUM]       = {};//複数の共有リソース
static bool s_usingCommonResource[COMMON_RESOURCE_NUM] = {};//共有リソース使用中フラグ

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
		//セマフォ取得
		sem_wait(&s_semaphore);
	//	sem_trywait(&s_semaphore);//取得できない時に他の処理を行いたい場合は sem_trywait() もしくは  sem_timedwait() を使用する
		
		//共有リソースを獲得
		int index = 0;
		pthread_mutex_lock(&s_mutex);
		for (; index < COMMON_RESOURCE_NUM; ++index)
		{
			if (!s_usingCommonResource[index])
				break;
		}
		s_usingCommonResource[index] = true;
		pthread_mutex_unlock(&s_mutex);
		
		//データ表示（前）
		printf("%s: [BEFORE] commonResource[%d]=%d, tlsData=%d\n", name, index, s_commonResource[index], s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonResource[index];
		int tls_data = s_tlsData;

		//データ更新
		++common_data;
		++tls_data;

		//若干ランダムでスリープ（0～4 msec）
		usleep((rand() % 5) * 1000);
		
		//データ書き戻し
		s_commonResource[index] = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("%s: [AFTER]  commonResource[%d]=%d, tlsData=%d\n", name, index, s_commonResource[index], s_tlsData);
		fflush(stdout);

		//共有リソースを解放
		s_usingCommonResource[index] = false;
		
		//セマフォ解放
		sem_post(&s_semaphore);
		
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
	//セマフォ生成
	{
		sem_init(&s_semaphore, 0, 0);//プロセス間で共有しないセマフォ
		                             //セマフォの初期値を 0にする（取得できない状態）
	}
	
	//ミューテックス生成
	//※PTHREAD_MUTEX_INITIALIZER で初期化している場合は不要
	{
	//	pthread_mutex_init(&s_mutex, NULL);
	}
	
	//スレッド作成
	static const int THREAD_NUM = 4;
	pthread_t pth[THREAD_NUM];
	{
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setstacksize(&attr, 1024);//スタックサイズ指定
		pthread_create(&pth[0], &attr, threadFunc, (void*)"太郎");
		pthread_create(&pth[1], &attr, threadFunc, (void*)"次郎");
		pthread_create(&pth[2], &attr, threadFunc, (void*)"三郎");
		pthread_create(&pth[3], &attr, threadFunc, (void*)"四朗 ");
	}

	//若干スリープ
	usleep(10 * 1000);

	//共有リソース初期化
	for (int i = 0; i < COMMON_RESOURCE_NUM; ++i)
	{
		s_commonResource[i] = 1000 * (i + 1);
	}

	//若干スリープ
	usleep(10 * 1000);

	//共有リソースの使用を許可（全セマフォ解放）
	{
		for (int i = 0; i < COMMON_RESOURCE_NUM; ++i)
		{
			sem_post(&s_semaphore);
		}
		printf("Common-resources have been prepared. (num=%d)\n", COMMON_RESOURCE_NUM);
		fflush(stdout);
	}
	
	//スレッド終了待ち
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		pthread_join(pth[i], NULL);
	}
	
	//セマフォの取得と解放を大量に実行して時間を計測
	{
		struct timeval begin;
		gettimeofday(&begin, NULL);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			sem_wait(&s_semaphore);
			sem_post(&s_semaphore);
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
		printf("Semaphore * %d = %d.%06d sec\n", TEST_TIMES, duration.tv_sec, duration.tv_usec);
	}
	
	//ミューテックス破棄
	//※PTHREAD_MUTEX_INITIALIZER で初期化している場合は不要
	{
	//	pthread_mutex_destroy(&s_mutex);
	}
	
	//セマフォ破棄
	{
		sem_destroy(&s_semaphore);
	}
	
	return EXIT_SUCCESS;
}

// End of file
