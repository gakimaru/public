#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <atomic>

#include <chrono> //時間計測用
#include <random> //乱数生成用

//アトミック操作用変数
static std::atomic_flag s_lock = ATOMIC_FLAG_INIT;

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

	//乱数
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time(0, 4);

	//処理
	for (int i = 0; i < 3; ++i)
	{
		//アトミック操作でロック取得待ち
		while (s_lock.test_and_set()){}

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
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//アトミック操作でロック解放
		s_lock.clear();

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
	//アトミック操作用変数初期化
	s_lock.clear();

	//スレッド作成
	std::thread thread_obj1 = std::thread(threadFunc, "太郎");
	std::thread thread_obj2 = std::thread(threadFunc, "次郎");
	std::thread thread_obj3 = std::thread(threadFunc, "三郎");

	//スレッド終了待ち
	thread_obj1.join();
	thread_obj2.join();
	thread_obj3.join();

	//アトミック操作でロックの取得と解放を大量に実行して時間を計測
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (s_lock.test_and_set()){}
			s_lock.clear();
		}	
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Atomic * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//アトミック操作でロックの取得と解放を大量に実行して時間を計測(2)：メモリバリアを設定
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (s_lock.test_and_set(std::memory_order_seq_cst)){}
			s_lock.clear(std::memory_order_release);
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Atomic * %d (memolry barrier free) = %.6f sec\n", TEST_TIMES, duration);
	}

	return EXIT_SUCCESS;
}

// End of file
