#include <stdio.h>
#include <stdlib.h>

#include <future>//非同期関数用

#include <thread>//スリープ用
#include <chrono>//時間計測用

#include <vector>//テスト計算用
#include <algorithm>//テスト計算用

//計算用関数A
int calcSubA()
{
	//時間のかかる処理代わりのスリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return 1;
}

//計算用関数B
int calcSubB()
{
	//時間のかかる処理代わりのスリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return 2;
}

//計算用関数C
int calcSubC()
{
	//時間のかかる処理代わりのスリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return 3;
}

//通常関数処理
void testNormalCalc()
{
	//時間計測開始
	auto begin = std::chrono::high_resolution_clock::now();
	
	//処理
	int result = 0;
	static const int TEST_TIMES = 100;
	for (int i = 0; i < TEST_TIMES; ++i)
	{
		result += (calcSubA() + calcSubB() + calcSubC());
	}
	
	//時間計測終了
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);
	
	//結果表示
	printf("----------------------------------------\n");
	printf("subNormalCalc: result = %d (%.6f sec)\n", result, duration);
}

//非同期関数処理
void testAsyncCalc()
{
	//時間計測開始
	auto begin = std::chrono::high_resolution_clock::now();

	//処理
	int result = 0;
	static const int TEST_TIMES = 100;
	for (int i = 0; i < TEST_TIMES; ++i)
	{
		//未来(future)に結果が返る関数を非同期で実行
		std::future<int> r1 = std::async(calcSubA),
			             r2 = std::async(calcSubB),
			             r3 = std::async(calcSubC);
		
		//.get()メソッドは、処理の完了を待って結果を返す
		result += (r1.get() + r2.get() + r3.get());
	}
	
	//時間計測終了
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);

	//結果表示
	printf("----------------------------------------\n");
	printf("subAsyncCalc: result = %d (%.6f sec)\n", result, duration);
}

//非同期関数【応用】
void testAsyncCalcEx()
{
	//リスト作成
	static const int LIST_MAX = 10000000;
	std::vector<int> list_org;
	list_org.reserve(LIST_MAX);
	for (int i = 0; i < LIST_MAX; ++i)
	{
		list_org.push_back(i);
	}

	//リストシャッフル
	std::random_shuffle(list_org.begin(), list_org.end());
		
	//この時点のリストを表示
	printf("----------------------------------------\n");
	printf("subAsyncCalcEx: before\n");
	printf("list =");
	std::for_each(list_org.begin(), list_org.begin() + 10, [](int val){printf(" %d", val); });
	printf(" ... ");
	std::for_each(list_org.end() - 10, list_org.end(), [](int val){printf(" %d", val); });
	printf("\n");

	//通常ソート
	{
		//時間計測開始
		auto begin = std::chrono::high_resolution_clock::now();
		
		//処理準備：シャッフル済みリストをコピー
		std::vector<int> list = list_org;
		
		//クイックソート
		std::sort(list.begin(), list.end());
		
		//時間計測終了
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);
		
		//結果表示
		printf("----------------------------------------\n");
		printf("subAsyncCalcEx: normal-sort: result (%.6f sec):\n", duration);
		printf("list =");
		std::for_each(list.begin(), list.begin() + 10, [](int val){printf(" %d", val);});
		printf(" ... ");
		std::for_each(list.end() - 10, list.end(), [](int val){printf(" %d", val); });
		printf("\n");
	}
	
	//非同期関数でソート
	//※大量にバッファを消費する
	{
		//時間計測開始
		auto begin = std::chrono::high_resolution_clock::now();

		//処理準備：シャッフル済みリストをコピー
		std::vector<int> list = list_org;
		const int list_size = list.size();

		//4分割で並列クイックソート
		std::future<void> r_a[4];
		{
			//非同期処理には、関数ポインター以外にも、関数オブジェクトやラムダ式を渡すことができる
			auto sort_lambda = [&list](const int index, const int list_begin, const int list_end)
			{
				std::vector<int>::iterator ite_begin = list.begin() + list_begin;
				std::vector<int>::iterator ite_end = list.begin() + list_end;
				std::sort(ite_begin, ite_end);
			};
			r_a[0] = std::async(sort_lambda, 0, list_size / 4 * 0, list_size / 4 * 1);
			r_a[1] = std::async(sort_lambda, 1, list_size / 4 * 1, list_size / 4 * 2);
			r_a[2] = std::async(sort_lambda, 2, list_size / 4 * 2, list_size / 4 * 3);
			r_a[3] = std::async(sort_lambda, 3, list_size / 4 * 3, list_size);
		}

		//2分割で並列マージソート
		std::future<void> r_b[2];
		{
			//非同期処理には、関数ポインター以外にも、関数オブジェクトやラムダ式を渡すことができる
			auto merge_sort_lambda = [&r_a, &list](const int index, const int list_begin, const int list_mid, const int list_end)
			{
				r_a[index * 2 + 0].wait();
				r_a[index * 2 + 1].wait();
				std::vector<int>::iterator ite_begin = list.begin() + list_begin;
				std::vector<int>::iterator ite_mid = list.begin() + list_mid;
				std::vector<int>::iterator ite_end = list.begin() + list_end;
				std::inplace_merge(ite_begin, ite_mid, ite_end);//二つのリストからマージソートする場合には std::merge() が使える
			};
			r_b[0] = std::async(merge_sort_lambda, 0, list_size / 2 * 0, list_size / 2 * 0 + list_size / 4, list_size / 2 * 1);
			r_b[1] = std::async(merge_sort_lambda, 1, list_size / 2 * 1, list_size / 2 * 1 + list_size / 4, list_size);
		}
		
		//マージソート（完了）
		{
			r_b[0].wait();
			r_b[1].wait();
			std::vector<int>::iterator ite_begin = list.begin();
			std::vector<int>::iterator ite_mid = list.begin() + list_size / 2;
			std::vector<int>::iterator ite_end = list.end();
			std::inplace_merge(ite_begin, ite_mid, ite_end);//二つのリストからマージソートする場合には std::merge() が使える
		}

		//時間計測終了
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);
		
		//結果表示
		printf("----------------------------------------\n");
		printf("subAsyncCalcEx: async-sort: result (%.6f sec):\n", duration);
		printf("list =");
		std::for_each(list.begin(), list.begin() + 10, [](int val){printf(" %d", val); });
		printf(" ... ");
		std::for_each(list.end() - 10, list.end(), [](int val){printf(" %d", val); });
		printf("\n");
	}
}

//テスト
int main(const int argc, const char* argv[])
{
	//通常関数処理
	testNormalCalc();
	
	//非同期関数処理
	testAsyncCalc();

	//非同期関数応用
	testAsyncCalcEx();

	return EXIT_SUCCESS;
}

// End of file
