#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <mutex>

#include <chrono> //時間計測用

//スレッド
void threadFunc(const char* name)
{
	//開始
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//CallOnce制御用変数
	static std::once_flag s_onceFlag;
	
	//CallOnce処理
	std::call_once(s_onceFlag, [&name]()
		{
			//ラムダ式で直接記述
			
			//CallOnce処理開始
			printf("CallOnce処理：初期化中(by %s)...\n", name);
			fflush(stdout);

			//1秒スリープ
			std::this_thread::sleep_for(std::chrono::seconds(1));

			//CallOnce処理終了
			printf("CallOnce処理：終了\n");
			fflush(stdout);
		}
	);

	//終了
	printf("- end:%s -\n", name);
	fflush(stdout);
}

//テスト
int main(const int argc, const char* argv[])
{
	//スレッド作成
	std::thread thread_obj1 = std::thread(threadFunc, "太郎");
	std::thread thread_obj2 = std::thread(threadFunc, "次郎");
	std::thread thread_obj3 = std::thread(threadFunc, "三郎");
	
	//スレッド終了待ち
	thread_obj1.join();
	thread_obj2.join();
	thread_obj3.join();

	return EXIT_SUCCESS;
}

// End of file
