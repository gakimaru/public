#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>

//CallOnce制御用変数
pthread_once_t s_onceFlag = PTHREAD_ONCE_INIT;

//CallOnce処理関数
void callOnceFunc()
{
	//CallOnce処理開始
	printf("CallOnce処理：初期化中...\n");
	fflush(stdout);

	//1秒スリープ
	sleep(1);

	//CallOnce処理終了
	printf("CallOnce処理：終了\n");
	fflush(stdout);
}

//スレッド
void* threadFunc(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);

	//開始
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//CallOnce処理
	pthread_once(&s_onceFlag, callOnceFunc);

	//終了
	printf("- end:%s -\n", name);
	fflush(stdout);
	return 0;
}

//テスト
int main(const int argc, const char* argv[])
{
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
	
	return EXIT_SUCCESS;
}

// End of file
