#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <mutex>

#include <chrono> //時間計測用

//ミューテックスオブジェクト
static std::mutex s_mutex;

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__declspec(thread) int s_tlsData = 0;
//thread_local int s_tlsData = 0;//Visual C++ 2013 では thread_local キーワードが使えない

//スレッド
void threadFunc(const char* name)
{
	//開始
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//処理
	for (int i = 0; i < 3; ++i)
	{
		//ミューテックス取得
		s_mutex.lock();
	//	s_mutex.try_lock();//取得できない時に他の処理を行いたい場合は try_lock() を使用する
		                   //タイムアウトしたい場合は timed_mutex クラスを使用する
		                   //再帰ロックしたい場合は recursive_mutex クラスを使用する

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
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 5));

		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//ミューテックス解放
		s_mutex.unlock();

		//スレッド切り替えのためのスリープ
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	//	//スレッド切り替え
	//	std::this_thread::yield();//OSに任せて再スケジューリング
	}

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

	//ミューテックスの取得と解放を大量に実行して時間を計測
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			s_mutex.lock();
			s_mutex.unlock();
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Mutex * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	return EXIT_SUCCESS;
}

// End of file
