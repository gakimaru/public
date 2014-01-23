#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#include <pthread.h>
#include <unistd.h>

//スレッドローカルストレージ(TLS)テスト
__thread pthread_t tls_pth = 0;//CC版TLS指定
//thread_local pthread_t tls_pth = 0;//C++11仕様版

//テスト用情報
struct TEST_INFO
{
	const char* text;//文字列
	int value;       //数値
	int loop_max;    //テストループ回数
	int start_i;     //スレッド生成ループ開始値
};

//スレッド情報
struct THREAD_INFO
{
	int level;           //子スレッドレベル
	pthread_t parent_pth;//親スレッド_t
	bool is_root_thread; //大元のスレッド判定用フラグ
};

//スレッド受け渡し情報
struct THREAD_PARAM
{
	TEST_INFO test;    //テスト用情報
	THREAD_INFO thread;//スレッド情報
};

//子スレッドの生成と終了待ち
extern void createChildThreads(const char* thread_name, TEST_INFO& test, THREAD_INFO& tinfo);

//スレッド関数
void* threadFunc(void* param_p)
{
	//パラメータ受け取り
	TEST_INFO test;
	THREAD_INFO tinfo;
	{
		THREAD_PARAM* param = (THREAD_PARAM*)param_p;
		memcpy(&test, &param->test, sizeof(TEST_INFO));
		memcpy(&tinfo, &param->thread, sizeof(THREAD_INFO));
	}
	
	//スレッド情報
	pthread_t pth_tmp = pthread_self();
	
	//スレッドローカルストレージ(TLS)テスト
	tls_pth = pth_tmp;
	
	//大元のスレッド判定用フラグをOFF
	tinfo.is_root_thread = false;
	
	//スレッド名を作成
	++ tinfo.level;
	char thread_name[32];
	sprintf(thread_name, "C%d(%010p,%010p)", tinfo.level, pth_tmp, tinfo.parent_pth);
	// C + 子スレッドのレベル + ( 自スレッド_t , 親スレッド_t )
	
	//子スレッド開始メッセージ
	printf("START: %s\n", thread_name);
	fflush(stdout);
	
	//テスト用変数を更新
	++ test.value;
	++ test.loop_max;
	
	//親スレッド_tを格納
	tinfo.parent_pth = pth_tmp;
	
	//1秒スリープ
	sleep(1);
	
	//子スレッドの生成と終了待ち
	createChildThreads(thread_name, test, tinfo);
	
	//子スレッド終了メッセージ
	printf("END: %s\n", thread_name);
	fflush(stdout);
	
	return NULL;
}

//子スレッドの生成と終了待ち
void createChildThreads(const char* thread_name, TEST_INFO& test, THREAD_INFO& tinfo)
{
	//子スレッド生成ループ
	const int CHILD_THREAD_NUM = 3;
	pthread_t pth[CHILD_THREAD_NUM];      //生成した子スレッドのスレッド_t
	THREAD_PARAM* param[CHILD_THREAD_NUM];//スレッド受け渡し用データ
	for(int i = 0; i < test.start_i; ++i)
	{
		pth[i] = 0;
		param[i] = NULL;
	}
	for(int i = test.start_i; i < CHILD_THREAD_NUM; ++i)
	{
		//子スレッド用パラメータ作成
		param[i] = (THREAD_PARAM*)malloc(sizeof(THREAD_PARAM));
		memcpy(&param[i]->test, &test, sizeof(TEST_INFO));
		memcpy(&param[i]->thread, &tinfo, sizeof(THREAD_INFO));
		param[i]->test.start_i = i + 1;
		
		//子スレッド生成
		pthread_t pth_tmp = 0;
		int ret = pthread_create((pthread_t*)&pth_tmp, NULL, threadFunc, (void*)(param[i]));
		if(ret != 0)
		{
			//子スレッド生成失敗
			free(param[i]);
			param[i] = NULL;
			
			//エラーメッセージ
			if(tinfo.is_root_thread)
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", thread_name, i, ret, errno);
			else
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", thread_name, i, ret, errno);
			fflush(stderr);
			
			//1秒スリープ
			sleep(1);
		}
		else
		{
			//子スレッド生成成功
			
			//子スレッドのスレッド_tを記録（最後の終了待ち用）
			pth[i] = pth_tmp;
			
			//子スレッド生成メッセージ
			if(tinfo.is_root_thread)
				printf("%s -> [%d] CREATED:C%d(%010p,%010p)\n", thread_name, i, tinfo.level + 1, pth_tmp, tinfo.parent_pth);
			else
				printf("%s -> [%d] CREATED:C%d(%010p,%010p)\n", thread_name, i, tinfo.level + 1, pth_tmp, tinfo.parent_pth);
			fflush(stdout);
			
			//2秒スリープ
			sleep(2);
		}
	}
	
	//ダミー処理
	for(int i = 0; i < test.loop_max; ++i)
	{
		//ダミーメッセージ表示
		printf("[%s] ... Process(%d/%d): text=\"%s\",value=%d (tls_tid=%010p)\n", thread_name, i + 1, test.loop_max, test.text, test.value, tls_pth);
		fflush(stdout);
		test.value += 10;
		
		//1秒スリープ
		sleep(1);
	}
	
	//子スレッドの終了待ち
	for(int i = 0; i < CHILD_THREAD_NUM; ++i)
	{
		pthread_t pth_tmp = pth[i];
		if(pth_tmp > 0)
		{
			//ウェイト開始メッセージ
			printf("[%s] ... Wait(%010p) ...\n", thread_name, pth_tmp);
			fflush(stdout);
			
			//ウェイト
			pthread_join((pthread_t)pth_tmp, NULL);
			
			//メモリ解放
			free(param[i]);
			param[i] = NULL;
			
			//ウェイト完了メッセージ
			printf("[%s] ... Wait(%010p) End\n", thread_name, pth_tmp);
			fflush(stdout);
		}
	}
}

//posix thread テスト
int main(const int argc, const char* argv[])
{
	//プログラム実行開始
	printf("- Start Thread Test -\n");
	fflush(stdout);
	
	//テスト用変数
	TEST_INFO test =
	{
		"TEST",   //text
		1000,     //value
		1,        //loop_max
		0,        //start_i
	};
	
	//スレッド情報
	THREAD_INFO tinfo =
	{
		0,   //level
		pthread_self(),
		     //pareant_pth
		true,//is_root_thread
	};
	
	//スレッドローカルストレージ(TLS)テスト
	tls_pth = tinfo.parent_pth;
	
	//スレッド名を作成
	// P + 子スレッドのレベル + ( 自スレッド_t , 親スレッド_t )
	char thread_name[32];
	sprintf(thread_name, "P0(%010p,%010p)", tinfo.parent_pth, 0);
	
	//子スレッドの生成と終了待ち
	createChildThreads(thread_name, test, tinfo);
	
	//プログラム実行終了
	printf("- End Thread Test -\n");
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
