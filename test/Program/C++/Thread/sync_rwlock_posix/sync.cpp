#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>

#include <sys/time.h> //時間計測用

//リード／ライトロック
static pthread_rwlock_t s_lock = PTHREAD_RWLOCK_INITIALIZER;

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__thread int s_tlsData = 0;

//書き込みスレッド
void* threadFuncW(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);

	//開始
	printf("- begin:(W)%s -\n", name);
	fflush(stdout);

	//若干ランダムでスリープ（0～499 msec）
	usleep((rand() % 500) * 1000);

	//処理
	for (int i = 0; i < 3; ++i)
	{
		//ライトロック取得
		pthread_rwlock_wrlock(&s_lock);
	//	pthread_rwlock_trywrlock(&s_lock);//取得できない時に他の処理を行いたい場合は pthread_rwlock_trywrlock() を使用する
		
		//データ表示（前）
		printf("(W)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
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
		printf("(W)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);
		
		//ライトロック解放
		pthread_rwlock_unlock(&s_lock);
		
		//若干ランダムでスリープ（0～499 msec）
		usleep((rand() % 500) * 1000);
	}
	
	//終了
	printf("- end:(W)%s -\n", name);
	fflush(stdout);
	return 0;
}

//読み込みスレッド
void* threadFuncR(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);

	//開始
	printf("- begin:(R)%s -\n", name);
	fflush(stdout);

	//若干ランダムでスリープ（0～499 msec）
	usleep((rand() % 500) * 1000);

	//処理
	for (int i = 0; i < 3; ++i)
	{
		//リードロック取得
		pthread_rwlock_rdlock(&s_lock);
	//	pthread_rwlock_tryrdlock(&s_lock);//取得できない時に他の処理を行いたい場合は pthread_rwlock_tryrdlock() を使用する
	//	pthread_rwlock_wrlock(&s_lock);//全てライトロックだった場合と処理効率を比較
		
		//データ表示（前）
		printf("(R)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);
		
		//若干ランダムでスリープ（0～499 msec）
		usleep((rand() % 500) * 1000);
		
		//データ表示（後）
		printf("(R)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);
		
		//リードロック解放
		pthread_rwlock_unlock(&s_lock);
		
		//若干ランダムでスリープ（0～499 msec）
		usleep((rand() % 500) * 1000);
	}
	
	//終了
	printf("- end:(R)%s -\n", name);
	fflush(stdout);
	return 0;
}

//テスト
int main(const int argc, const char* argv[])
{
	//リード／ライトロック生成
	//※PTHREAD_RWLOCK_INITIALIZER で初期化している場合は不要
	{
	//	pthread_rwlockattr_t attr;
	//	pthread_rwlockattr_init(&attr);
	//	pthread_rwlockattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);//プロセス間で共有
	//	pthread_rwlockattr_setpshared(&attr, PTHREAD_PROCESS_PRIVATE);//単独プロセス専用　※デフォルト
	//	pthread_rwlock_init(&s_lock, &attr);
	}
	
	//スレッド作成
	static const int THREAD_NUM = 6;
	pthread_t pth[THREAD_NUM];
	{
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setstacksize(&attr, 1024);//スタックサイズ指定
		pthread_create(&pth[0], &attr, threadFuncR, (void*)"太郎");
		pthread_create(&pth[1], &attr, threadFuncR, (void*)"次郎");
		pthread_create(&pth[2], &attr, threadFuncR, (void*)"三郎");
		usleep(1);
		pthread_create(&pth[3], &attr, threadFuncW, (void*)"松子");
		pthread_create(&pth[4], &attr, threadFuncW, (void*)"竹子");
		pthread_create(&pth[5], &attr, threadFuncW, (void*)"梅子");
	}
	
	//スレッド終了待ち
	{
		struct timeval begin;
		gettimeofday(&begin, NULL);
		
		for(int i = 0; i < THREAD_NUM; ++i)
		{
			pthread_join(pth[i], NULL);
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
		printf("Time = %d.%06d sec\n", duration.tv_sec, duration.tv_usec);
	}
	
	//リード／ライトロックの取得と解放を大量に実行して時間を計測
	{
		struct timeval begin;
		gettimeofday(&begin, NULL);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			pthread_rwlock_wrlock(&s_lock);
			pthread_rwlock_unlock(&s_lock);
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
		printf("Read-WriteLock * %d = %d.%06d sec\n", TEST_TIMES, duration.tv_sec, duration.tv_usec);
	}
	
	//リード／ライトロック破棄
	//※PTHREAD_RWLOCK_INITIALIZER で初期化している場合は不要
	{
	//	pthread_rwlock_destroy(&s_lock);
	}
	
	return EXIT_SUCCESS;
}

// End of file
