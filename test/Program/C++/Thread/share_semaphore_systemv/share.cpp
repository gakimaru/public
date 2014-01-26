#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <pthread.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <sys/stat.h>    
#include <unistd.h>
#include <errno.h>

#include <sys/time.h>

//セマフォ
static int s_semaphore;

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
		{
			struct sembuf sb = {0, -1, 0};
			semop(s_semaphore, &sb, 1);
		}
		
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
		pthread_mutex_lock(&s_mutex);
		s_usingCommonResource[index] = false;
		pthread_mutex_unlock(&s_mutex);
		
		//セマフォ解放
		{
			struct sembuf sb = {0, 1, 0};
			semop(s_semaphore, &sb, 1);
		}
		
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
		key_t key = ftok("share.cpp", 'S');//セマフォを一意に識別するためのキーとして、
		                                   //実在するファイルのユニークIDを利用
		s_semaphore = semget(key, 1, S_IRWXU|IPC_CREAT);
	//	union semun arg;
	//	arg.val = 0;
	//	semctl(s_semaphore, 0, SETVAL, arg);
		semctl(s_semaphore, 0, SETVAL, 0);
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
		pthread_create(&pth[0], &attr, threadFunc, (void*)"Taro  ");
		pthread_create(&pth[1], &attr, threadFunc, (void*)"Jiro  ");
		pthread_create(&pth[2], &attr, threadFunc, (void*)"Saburo");
		pthread_create(&pth[3], &attr, threadFunc, (void*)"Shiro ");
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
			struct sembuf sb = {0, 1, 0};
			semop(s_semaphore, &sb, 1);
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
			{
				struct sembuf sb = {0, -1, 0};
				semop(s_semaphore, &sb, 1);
			}
			{
				struct sembuf sb = {0, 1, 0};
				semop(s_semaphore, &sb, 1);
			}
		}
		struct timeval end;
		gettimeofday(&end, NULL);
		struct timeval prog;
		if( end.tv_usec >= begin.tv_usec)
		{
			prog.tv_sec = end.tv_sec - begin.tv_sec;
			prog.tv_usec = end.tv_usec - begin.tv_usec;
		}
		else
		{
			prog.tv_sec = end.tv_sec - begin.tv_sec - 1;
			prog.tv_usec = 1000000 - begin.tv_usec + end.tv_usec;
		}
		printf("Semaphore * %d = %d.%06d sec\n", TEST_TIMES, prog.tv_sec, prog.tv_usec);
	}
	
	//ミューテックス破棄
	//※PTHREAD_MUTEX_INITIALIZER で初期化している場合は不要
	{
	//	pthread_mutex_destroy(&s_mutex);
	}
	
	//セマフォ破棄
	{
	//	union semun arg;
	//	arg.val = 0;
	//	semctl(s_semaphore, 0, IPC_RMID, arg);
		semctl(s_semaphore, 0, IPC_RMID, 0);
	}
	
	return EXIT_SUCCESS;
}

// End of file
