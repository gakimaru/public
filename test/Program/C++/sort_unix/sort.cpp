//static const int TEST_DATA_COUNT = 1000000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 100000;//テストデータ件数（最大）
static const int TEST_DATA_COUNT = 100;//テストデータ件数（最大）

#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>//qsort関数用
#include <crtdefs.h>//ptrdiff_t用
#include <functional>//C++11 std::function用
#include <type_traits>//C++11 std::function用

//--------------------------------------------------------------------------------
//ソートアルゴリズム

//========================================
//ソート補助処理
//========================================

//----------------------------------------
//整列状態確認
template<class T, class COMPARE>
inline std::size_t calcUnordered(const T* array, const std::size_t size, COMPARE&& comparison)
{
	std::size_t unordered = 0;
	const T* prev = array;
	const T* now = prev + 1;
	for (std::size_t i = 1; i < size; ++i, ++now, ++prev)
	{
		if (comparison(*now, *prev))
			++unordered;
	}
	return unordered;
}
template<class ITERATOR, class COMPARE>
std::size_t calcUnordered(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	return calcUnordered(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
std::size_t calcUnordered(CONTAINER& con, COMPARE&& comparison)
{
	return calcUnordered(&(con.at(0)), con.size(), comparison);
}

//========================================
//ソートアルゴリズム説明
//========================================

//・計算時間：
//    - O(n)       ... データ件数分の時間
//    - O(n ^ 2)   ... データ件数の２乗分の時間
//    - O(log n)   ... log2(データ件数)分の時間（4→, 16→4, 1024→10,1048576→20）
//    - O(n log n) ... n×log n 分の時間
//・メモリ使用量：
//    - O(1)       ... １件分のメモリが必要
//    - O(n)       ... データ件数分のメモリが必要
//    - O(log n)   ... log2(データ件数)分のメモリが必要
//・安定性：
//    - ○         ... キーが同じデータの順序性が維持されることを保証する
//                     例：{ 3-a, 5-b, 4-c, 5-d, 9-e, 3-f, 4-g, 3-h, 5-i } → { 3-a, 3-f, 3-h, 4-c, 4-g, 5-b, 5-d, 5-i, 9-e }
//    - ×         ... 例：(同上)                                          → { 3-a, 3-h, 3-f, 4-c, 4-g, 5-i, 5-d, 5-b, 9-e }

//========================================
//ソートアルゴリズム分類：交換ソート
//========================================

//----------------------------------------
//アルゴリズム：バブルソート
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//※交換発生有無のチェックを行い、最適化する
template<class T, class COMPARE>
void bubbleSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void bubbleSort(T* begin, T* end, COMPARE&& comparison)
{
	bubbleSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void bubbleSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	bubbleSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void bubbleSort(CONTAINER& con, COMPARE&& comparison)
{
	bubbleSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：シェーカーソート
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//※交換発生有無のチェックを行い、最適化する
template<class T, class COMPARE>
void shakerSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void shakerSort(T* begin, T* end, COMPARE&& comparison)
{
	shakerSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void shakerSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	shakerSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void shakerSort(CONTAINER& con, COMPARE&& comparison)
{
	shakerSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：奇遇転置ソート
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//※OpenMPを使用し、並列化で最適化する
template<class T, class COMPARE>
void oddEvenSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void oddEvenSort(T* begin, T* end, COMPARE&& comparison)
{
	oddEvenSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void oddEvenSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	oddEvenSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void oddEvenSort(CONTAINER& con, COMPARE&& comparison)
{
	oddEvenSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：コムソート
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　×
template<class T, class COMPARE>
void combSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void combSort(T* begin, T* end, COMPARE&& comparison)
{
	combSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void combSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	combSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void combSort(CONTAINER& con, COMPARE&& comparison)
{
	combSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：ノームソート
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
template<class T, class COMPARE>
void gnomeSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void gnomeSort(T* begin, T* end, COMPARE&& comparison)
{
	gnomeSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void gnomeSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	gnomeSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void gnomeSort(CONTAINER& con, COMPARE&& comparison)
{
	gnomeSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：シェーカーノームソート
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
template<class T, class COMPARE>
void shakerGnomeSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void shakerGnomeSort(T* begin, T* end, COMPARE&& comparison)
{
	shakerGnomeSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void shakerGnomeSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	shakerGnomeSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void shakerGnomeSort(CONTAINER& con, COMPARE&& comparison)
{
	shakerGnomeSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：クイックソート
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(log n)
//・安定性：　　　×
//※再帰処理を使用せずに最適化（最大件数を log2(4294967296) = 32 とする）
template<class T, class COMPARE>
void quickSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void quickSort(T* begin, T* end, COMPARE&& comparison)
{
	quickSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void quickSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	quickSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void quickSort(CONTAINER& con, COMPARE&& comparison)
{
	quickSort(&(con.at(0)), con.size(), comparison);
}

//========================================
//ソートアルゴリズム分類：選択ソート
//========================================

//----------------------------------------
//アルゴリズム：選択ソート
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　×
//※交換発生有無のチェックを行い、最適化する
template<class T, class COMPARE>
void selectionSort(T* array, const std::size_t size, COMPARE&& comparison)
{
	const T* end = array + size;
	const std::size_t size_1 = size - 1;
	bool is_swapped = true;
	for (std::size_t i = 0; i < size_1 && is_swapped; ++i)
	{
		is_swapped = false;
		T* now = array + i;
		T* min = now;
		T* check = now;
		for (std::size_t ii = i + 1; ii < size; ++ii)
		{
			++check;
			if (comparison(*check, *now))
			{
				min = check;
			}
		}
		if (now != min)
		{
			T tmp = *min;
			*min = *now;
			*now = tmp;
			is_swapped = true;
		}
	}
}
template<class T, class COMPARE>
inline void selectionSort(T* begin, T* end, COMPARE&& comparison)
{
	selectionSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void selectionSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	selectionSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void selectionSort(CONTAINER& con, COMPARE&& comparison)
{
	selectionSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：シェーカー選択ソート
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　×
template<class T, class COMPARE>
void shakerSelectionSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void shakerSelectionSort(T* begin, T* end, COMPARE&& comparison)
{
	shakerSelectionSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void shakerSelectionSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	shakerSelectionSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void shakerSelectionSort(CONTAINER& con, COMPARE&& comparison)
{
	shakerSelectionSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：ヒープソート
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(1)
//・安定性：　　　×
template<class T, class COMPARE>
void heapSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void heapSort(T* begin, T* end, COMPARE&& comparison)
{
	heapSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void heapSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	heapSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void heapSort(CONTAINER& con, COMPARE&& comparison)
{
	heapSort(&(con.at(0)), con.size(), comparison);
}

//========================================
//ソートアルゴリズム分類：挿入ソート
//========================================

//----------------------------------------
//アルゴリズム：挿入ソート
//・平均計算時間：O(n + d) ※d = O(n^2
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
template<class T, class COMPARE>
void insertionSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void insertionSort(T* begin, T* end, COMPARE&& comparison)
{
	insertionSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void insertionSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	insertionSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void insertionSort(CONTAINER& con, COMPARE&& comparison)
{
	insertionSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：シェルソート
//・平均計算時間：-
//・最悪計算時間：O(n log^2 n)
//・メモリ使用量：O(1)
//・安定性：　　　×
template<class T, class COMPARE>
void shellSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void shellSort(T* begin, T* end, COMPARE&& comparison)
{
	shellSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void shellSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	shellSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void shellSort(CONTAINER& con, COMPARE&& comparison)
{
	shellSort(&(con.at(0)), con.size(), comparison);
}

//========================================
//ソートアルゴリズム分類：混成ソート
//========================================

//----------------------------------------
//アルゴリズム：イントロソート
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(n log n)
//・安定性：　　　×
template<class T, class COMPARE>
void introSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void introSort(T* begin, T* end, COMPARE&& comparison)
{
	introSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void introSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	introSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void introSort(CONTAINER& con, COMPARE&& comparison)
{
	introSort(&(con.at(0)), con.size(), comparison);
}

//----------------------------------------
//アルゴリズム：事前チェックソート
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(n log n)
//・安定性：　　　○
//※安定ソートのみを使用し、高速性を追求
template<class T, class COMPARE>
void preCheckSort(T* array, const std::size_t size, COMPARE&& comparison)
{
}
template<class T, class COMPARE>
inline void preCheckSort(T* begin, T* end, COMPARE&& comparison)
{
	preCheckSort(begin, end - begin, comparison);
}
template<class ITERATOR, class COMPARE>
inline void preCheckSort(ITERATOR& begin, ITERATOR& end, COMPARE&& comparison)
{
	preCheckSort(&begin[0], end - begin, comparison);
}
template<class CONTAINER, class COMPARE>
inline void preCheckSort(CONTAINER& con, COMPARE&& comparison)
{
	preCheckSort(&(con.at(0)), con.size(), comparison);
}

//--------------------------------------------------------------------------------
//テスト

#include <algorithm>//std::sort, std::for_each用
#include <array>//C++11 std::array用
#include <random>//C++11 random用
#include <chrono>//C++11 std::chrono用

#include "sub.h"

//----------------------------------------
//テスト用構造体の配列型
typedef std::array<data_t, TEST_DATA_COUNT> array_t;

//----------------------------------------
//テスト用の比較処理
//qsort用関数
int compare_func_qsort(const void*lhs, const void*rhs)
{
	return reinterpret_cast<const data_t*>(lhs)->m_key - reinterpret_cast<const data_t*>(rhs)->m_key;
}
//通常関数
extern bool compare_func(const data_t& lhs, const data_t& rhs);
//インライン関数
inline bool compare_func_inline(const data_t& lhs, const data_t& rhs)
{
	return lhs.m_key < rhs.m_key;
}
//関数オブジェクト
struct compare_functor{
	inline bool operator()(const data_t& lhs, const data_t& rhs)
	{
		return lhs.m_key < rhs.m_key;
	}
};
//ラムダ関数
auto compare_lambda = [](const data_t& lhs, const data_t& rhs) -> bool
{
	return lhs.m_key < rhs.m_key;
};

//----------------------------------------
//メイン
int main(const int argc, const char* argv[])
{
	//時間計測
	auto begin_time = std::chrono::system_clock::now();
	auto prev_time = begin_time;

	//配列初期化
	enum init_type_t
	{
		init_shuffle1 = 0,//シャッフルパターン1
		init_shuffle2,//シャッフルパターン2
		init_shuffle3,//シャッフルパターン3
		init_ordered,//整列済みパターン
		init_reversed,//逆順整列済みパターン
		init_ordered_without_both_ends,//整列済みパターン（ただし、始端と終端のみ入れ替え）
		init_pattern_num//初期化パターン数
	};
	auto makeArray = [](array_t*& array, const init_type_t type, const char* type_name)
	{
		printf("----- Make Array(%s) -----\n", type_name);
		array = new array_t();
		int key = 0;
		switch (type)
		{
		case init_shuffle1:
		case init_shuffle2:
		case init_shuffle3:
		case init_ordered:
		case init_ordered_without_both_ends:
			for (data_t& obj : *array)
				obj.m_key = ++key;
			break;
		case init_reversed:
			for_each(array->rbegin(), array->rend(), [&key](data_t& obj){obj.m_key = ++key; });
			break;
		}
		switch (type)
		{
		case init_shuffle1:
		case init_shuffle2:
		case init_shuffle3:
			{
				std::mt19937 random_engine(type);
				std::shuffle(array->begin(), array->end(), random_engine);
			}
			break;
		case init_ordered_without_both_ends:
			{
				data_t tmp = (*array)[0];
				(*array)[0] = (*array)[array->size() - 1];
				(*array)[array->size() - 1] = tmp;
			}
			break;
		}
	};

	//処理時間計測
	auto calcElapsedTime = [](const std::chrono::system_clock::time_point& now_time, const std::chrono::system_clock::time_point& prev_time) -> double
	{
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - prev_time);
		const auto elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		return elapsed_time;
	};
	auto getElapsedTime = [&calcElapsedTime](const std::chrono::system_clock::time_point& prev_time) -> double
	{
		return calcElapsedTime(std::chrono::system_clock::now(), prev_time);
	};

	//処理時間表示
	auto printElapsedTimeDirect = [&calcElapsedTime](const double elapsed_time) -> std::chrono::system_clock::time_point
	{
		printf("*elapsed time=%.9llf sec\n", elapsed_time);
		return std::chrono::system_clock::now();
	};
	auto printElapsedTime = [&calcElapsedTime, &printElapsedTimeDirect](const std::chrono::system_clock::time_point& prev_time) -> std::chrono::system_clock::time_point
	{
		const auto now_time = std::chrono::system_clock::now();
		const auto elapsed_time = calcElapsedTime(now_time, prev_time);
		return printElapsedTimeDirect(elapsed_time);
	};

	//配列状態表示
	auto showArrayCondition = [](const array_t* array)
	{
		//int ng = calcUnordered(*array, compare_func);
		//int ng = calcUnordered(*array, compare_func_inline);
		int ng = calcUnordered(*array, compare_functor());
		//int ng = calcUnordered(*array, compare_lambda);
		if (ng == 0)
			printf("Array is ordered.(count=%d)\n", array->size());
		else
			printf("Attay is NOT ordered! (NG=%d/count=%d)\n", ng, array->size());
	};

	//ソート
	typedef std::function<void(array_t*)> sort_procedure;
	auto sort = [](array_t*& array, sort_procedure sort_proc)
	{
		printf("----- Sort -----\n");
		sort_proc(array);
	};

	//配列削除
	auto termArray = [](array_t*& array)
	{
		printf("----- Delete array -----\n");
		delete array;
		array = nullptr;
	};
	
	//計測
	auto measure = [&](const init_type_t type, const char* type_name, sort_procedure sort_proc) -> double
	{
		printf("\n");
		printf("------------------------------\n");
		printf("Measure type: %s\n", type_name);
		printf("------------------------------\n");
		array_t* array = nullptr;//配列
		makeArray(array, type, type_name);//配列初期化
		showArrayCondition(array);//配列状態表示
		prev_time = printElapsedTime(prev_time);//処理時間表示
		sort(array, sort_proc);//ソート
		const double elapsed_time = getElapsedTime(prev_time);//ソートの処理時間を計測
		showArrayCondition(array);//配列状態表示
		prev_time = printElapsedTimeDirect(elapsed_time);//処理時間表示
		termArray(array);//配列削除
		prev_time = printElapsedTime(prev_time);//処理時間表示
		return elapsed_time;
	};

	//平均処理時間表示
	auto printAverageTime = [](const char* sort_type_name, const double sorting_time, const int measure_count)
	{
		const auto average_time = sorting_time / static_cast<double>(measure_count);
		printf("\n");
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("*** sorting time=%.9llf sec ---> average time=%.9llf sec\n", sorting_time, average_time);
		printf("============================================================\n");
	};

	//まとめて計測
	auto measureAll = [&](const char* sort_type_name, sort_procedure sort_proc)
	{
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("============================================================\n");

		#define pair(x) init_##x, #x

		double sorting_time = 0.;//ソート処理時間
		
		//シャッフルパターン１
		sorting_time += measure(pair(shuffle1), sort_proc);

		//シャッフルパターン２
		sorting_time += measure(pair(shuffle2), sort_proc);

		//シャッフルパターン３
		sorting_time += measure(pair(shuffle3), sort_proc);

		//整列済みパターン
		sorting_time += measure(pair(ordered), sort_proc);

		//逆順整列済みパターン
		sorting_time += measure(pair(reversed), sort_proc);

		//整列済みパターン（ただし、始端と終端のみ入れ替え）
		sorting_time += measure(pair(ordered_without_both_ends), sort_proc);
		
		printAverageTime(sort_type_name, sorting_time, init_pattern_num);//平均ソート処理時間表示
		
		#undef pair
	};

	//----------------------------------------
	//標準ライブラリによるソート

	//Cライブラリ：qsort関数
	//アルゴリズム：クイックソート
	auto clib_qsort = [](array_t* array)
	{
		qsort(&array->at(0), array->size(),sizeof(data_t), compare_func_qsort);
	};
	measureAll("C-Lib qsort", clib_qsort);
	printf("\n");
	printf("\n");

	//STLソート1：通常関数で比較
	//アルゴリズム：イントロソート（クイックソート＋ヒープソート＋挿入ソート）
	auto stl_sort1 = [](array_t* array)
	{
		std::sort(array->begin(), array->end(), compare_func);
	};
	measureAll("STL sort(with function)", stl_sort1);
	printf("\n");
	printf("\n");

	//STLソート2：インライン関数で比較
	//アルゴリズム：（同上）
	auto stl_sort2 = [](array_t* array)
	{
		std::sort(array->begin(), array->end(), compare_func_inline);
	};
	measureAll("STL sort(with inline function)", stl_sort2);
	printf("\n");
	printf("\n");

	//STLソート3：関数オブジェクトで比較
	//アルゴリズム：（同上）
	auto stl_sort3 = [](array_t* array)
	{
		std::sort(array->begin(), array->end(), compare_functor());
	};
	measureAll("STL sort(with functor)", stl_sort3);
	printf("\n");
	printf("\n");

	//STLソート4：ラムダ関数で比較
	//アルゴリズム：（同上）
	auto stl_sort4 = [](array_t* array)
	{
		std::sort(array->begin(), array->end(), compare_lambda);
	};
	measureAll("STL sort(with lamda)", stl_sort4);
	printf("\n");
	printf("\n");
	
	//----------------------------------------
	//交換ソート

	//アルゴリズム：バブルソート
	auto bubble_sort = [](array_t* array)
	{
		bubbleSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Bubble sort", bubble_sort);
	printf("\n");
	printf("\n");
	
	//アルゴリズム：シェーカーソート
	auto shaker_sort = [](array_t* array)
	{
		shakerSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Shaker sort", shaker_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：奇遇転置ソート
	auto odd_even_sort = [](array_t* array)
	{
		oddEvenSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Odd-Even sort", odd_even_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：コムソート
	auto comb_sort = [](array_t* array)
	{
		combSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Comb sort", comb_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：ノームソート
	auto gnome_sort = [](array_t* array)
	{
		gnomeSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Gnome sort", gnome_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェーカーノームソート
	auto shaker_gnome_sort = [](array_t* array)
	{
		shakerGnomeSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Shaker Gnome sort", shaker_gnome_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：クイックソート
	auto quick_sort = [](array_t* array)
	{
		quickSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Quick sort", quick_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//選択ソート

	//アルゴリズム：選択ソート
	auto selection_sort = [](array_t* array)
	{
		selectionSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Selection sort", selection_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェーカー選択ソート
	auto shaker_selection_sort = [](array_t* array)
	{
		shakerSelectionSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Shaker Selection sort", shaker_selection_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：ヒープソート
	auto heap_sort = [](array_t* array)
	{
		heapSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Heap sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//挿入ソート

	//アルゴリズム：挿入ソート
	auto insertion_sort = [](array_t* array)
	{
		insertionSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Insertion sort", insertion_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェルソート
	auto shell_sort = [](array_t* array)
	{
		shellSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Shell sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//混成ソート

	//アルゴリズム：イントロソート
	auto intro_sort = [](array_t* array)
	{
		introSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Intro sort", heap_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：事前チェックソート
	auto pre_check_sort = [](array_t* array)
	{
		preCheckSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Pre-Check sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//終了
	printf("- End -\n");
	printElapsedTime(begin_time);//処理時間表示

	return EXIT_SUCCESS;
}

// End of file
