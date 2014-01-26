#include <stdio.h>
#include <stdlib.h>

#include <thread>

//スレッドローカルストレージ(TLS)テスト
__declspec(thread) std::size_t tls_tid = 0;//Visual C++固有版TLS指定
//thread_local std::size_t tls_tid = 0;//C++11仕様版TLS指定：Visual C++ 2013 では未対応

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
	int level;                 //子スレッドレベル
	std::thread::id parent_tid;//親スレッドID
	bool is_root_thread;       //大元のスレッド判定用フラグ
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
void threadFunc(THREAD_PARAM param)
{
	//パラメータ受け取り
	TEST_INFO test;
	THREAD_INFO tinfo;
	{
		memcpy(&test, &param.test, sizeof(TEST_INFO));
		memcpy(&tinfo, &param.thread, sizeof(THREAD_INFO));
	}

	//スレッド情報
	std::thread::id tid_tmp = std::this_thread::get_id();

	//スレッドローカルストレージ(TLS)テスト
	tls_tid = tid_tmp.hash();	

	//大元のスレッド判定用フラグをOFF
	tinfo.is_root_thread = false;

	//スレッド名を作成
	++tinfo.level;
	char thread_name[32];
	sprintf_s(thread_name, sizeof(thread_name), "C%d(0x%08x,0x%08x)", tinfo.level, tid_tmp.hash(), tinfo.parent_tid.hash());
	// C + 子スレッドのレベル + ( 自スレッドID , 親スレッドID )

	//子スレッド開始メッセージ
	printf("START: %s\n", thread_name);
	fflush(stdout);

	//テスト用変数を更新
	++test.value;
	++test.loop_max;

	//親スレッドIDを格納
	tinfo.parent_tid = tid_tmp;

	//1秒スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	//子スレッドの生成と終了待ち
	createChildThreads(thread_name, test, tinfo);

	//子スレッド終了メッセージ
	printf("END: %s\n", thread_name);
	fflush(stdout);
}

//子スレッドの生成と終了待ち
void createChildThreads(const char* thread_name, TEST_INFO& test, THREAD_INFO& tinfo)
{
	//子スレッド生成ループ
	const int CHILD_THREAD_NUM = 3;
	std::thread* thread[CHILD_THREAD_NUM];//生成した子スレッドのスレッドハンドル
	std::thread::id tid[CHILD_THREAD_NUM];//生成した子スレッドのスレッドID
	THREAD_PARAM* param[CHILD_THREAD_NUM];//スレッド受け渡し用データ
	for (int i = 0; i < test.start_i; ++i)
	{
		thread[i] = nullptr;
		tid[i] = std::thread::id();
		param[i] = NULL;
	}
	for (int i = test.start_i; i < CHILD_THREAD_NUM; ++i)
	{
		//子スレッド用パラメータ作成
		param[i] = (THREAD_PARAM*)malloc(sizeof(THREAD_PARAM));
		memcpy(&param[i]->test, &test, sizeof(TEST_INFO));
		memcpy(&param[i]->thread, &tinfo, sizeof(THREAD_INFO));
		param[i]->test.start_i = i + 1;

		//子スレッド生成
		std::thread::id tid_tmp;
		std::thread* thread_tmp = new std::thread(threadFunc, *param[i]);
		if (thread_tmp == nullptr)
		{
			//子スレッド生成失敗
			free(param[i]);
			param[i] = NULL;

			//エラーメッセージ
			if (tinfo.is_root_thread)
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", thread_name, i, errno);
			else
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", thread_name, i, errno);
			fflush(stderr);

			//1秒スリープ
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		else
		{
			//子スレッド生成成功

			//子スレッドのスレッドオブジェクトとIDを記録（最後の終了待ち用）
			thread[i] = thread_tmp;
			tid_tmp = thread_tmp->get_id();
			tid[i] = tid_tmp;

			//子スレッド生成メッセージ
			if (tinfo.is_root_thread)
				printf("%s -> [%d] CREATED:C%d(0x%08x,0x%08x)\n", thread_name, i, tinfo.level + 1, tid_tmp.hash(), tinfo.parent_tid.hash());
			else
				printf("%s -> [%d] CREATED:C%d(0x%08x,0x%08x)\n", thread_name, i, tinfo.level + 1, tid_tmp.hash(), tinfo.parent_tid.hash());
			fflush(stdout);

			//2秒スリープ
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}

	//ダミー処理
	for (int i = 0; i < test.loop_max; ++i)
	{
		//ダミーメッセージ表示
		printf("[%s] ... Process(%d/%d): text=\"%s\",value=%d (tls_tid=0x%08x)\n", thread_name, i + 1, test.loop_max, test.text, test.value, tls_tid);
		fflush(stdout);
		test.value += 10;

		//1秒スリープ
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	//子スレッドの終了待ち
	for (int i = 0; i < CHILD_THREAD_NUM; ++i)
	{
		std::thread* thread_tmp = thread[i];
		std::thread::id tid_tmp = tid[i];
		if (thread_tmp)
		{
			//ウェイト開始メッセージ
			printf("[%s] ... Wait(0x%08x) ...\n", thread_name, tid_tmp.hash());
			fflush(stdout);

			//ウェイト
			thread_tmp->join();
			
			//子スレッドのオブジェクトを削除
			delete thread_tmp;
			thread[i] = nullptr;

			//メモリ解放
			free(param[i]);
			param[i] = NULL;

			//ウェイト完了メッセージ
			printf("[%s] ... Wait(0x%08x) End\n", thread_name, tid_tmp.hash());
			fflush(stdout);
		}
	}
}

//C++11 thread テスト
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
		std::this_thread::get_id(),
		     //parent_tid
		true,//is_root_thread
	};

	//スレッドローカルストレージ(TLS)テスト
	tls_tid = tinfo.parent_tid.hash();

	//スレッド名を作成
	// P + 子スレッドのレベル + ( 自スレッドID , 親スレッドID )
	char thread_name[32];
	sprintf_s(thread_name, sizeof(thread_name), "P0(0x%08x,0x%08x)", tinfo.parent_tid.hash(), 0);

	//子スレッドの生成と終了待ち
	createChildThreads(thread_name, test, tinfo);

	//プログラム実行終了
	printf("- End Thread Test -\n");
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
