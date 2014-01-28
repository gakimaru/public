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
	auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
	
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
	auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);

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
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		
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
	//※大量にバッファを消費する。また、アルゴリズムを高速化できてもバッファコピーに時間がかかる。
	{
		//時間計測開始
		auto begin = std::chrono::high_resolution_clock::now();

		//処理準備：シャッフル済みリストをコピー
		std::vector<int> list = list_org;
		
		//4分割で並列クイックソート
		std::vector<int> list_tmp_a[4];
		std::future<void> r_a[4];
		const int list_size = list.size() / 4;
		{
			auto sort_lambda = [&r_a, &list, &list_tmp_a, &list_size](const int index)
			{
				std::vector<int>::iterator ite_begin = list.begin() + index * list_size;
				std::vector<int>::iterator ite_end = ite_begin + list_size;
				list_tmp_a[index] = std::vector<int>(ite_begin, ite_end);
				std::sort(list_tmp_a[index].begin(), list_tmp_a[index].end());
			};
			r_a[0] = std::async(sort_lambda, 0);
			r_a[1] = std::async(sort_lambda, 1);
			r_a[2] = std::async(sort_lambda, 2);
			r_a[3] = std::async(sort_lambda, 3);
		}
		
		//2分割で並列マージソート
		std::vector<int> list_tmp_b[2];
		std::future<void> r_b[2];
		{
			auto merge_sort_lambda = [&r_a, &list_tmp_a, &list_tmp_b, &list_size](const int index)
			{
				list_tmp_b[index] = std::vector<int>(list_size * 2);
				const int i1 = index * 2 + 0;
				const int i2 = index * 2 + 1;
				r_a[i1].wait();
				r_a[i2].wait();
				std::merge(list_tmp_a[i1].begin(), list_tmp_a[i1].end(), list_tmp_a[i2].begin(), list_tmp_a[i2].end(), list_tmp_b[index].begin());
			};
			r_b[0] = std::async(merge_sort_lambda, 0);
			r_b[1] = std::async(merge_sort_lambda, 1);
		}
		
		//マージソート（完了）
		r_b[0].wait();
		r_b[1].wait();
		std::merge(list_tmp_b[0].begin(), list_tmp_b[0].end(), list_tmp_b[1].begin(), list_tmp_b[1].end(), list.begin());

		//時間計測終了
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		
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
