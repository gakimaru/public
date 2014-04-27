#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>//qsort関数用
#include <stdint.h>//intptr_t用
#include <cstddef>//std::size_t用
#include <functional>//C++11 std::function用
//#include <crtdefs.h>//ptrdiff_t用

//--------------------------------------------------------------------------------
//ソートアルゴリズム

//========================================
//ソート補助処理
//========================================

//----------------------------------------
//処理共通化用マクロ
#define sortFuncSet(func_name) \
	template<class T, std::size_t N, class COMPARE> \
	inline std::size_t func_name(T(&array)[N], COMPARE comparison) \
	{ \
		return func_name(array, N, comparison); \
	} \
	template<class T, class COMPARE> \
	inline std::size_t func_name(T* begin, T* end, COMPARE comparison) \
	{ \
		return func_name(begin, end - begin, comparison); \
	} \
	template<class ITERATOR, class COMPARE> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end, COMPARE comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(&begin[0], size, comparison); \
	} \
	template<class CONTAINER, class COMPARE> \
	inline std::size_t func_name(CONTAINER& con, COMPARE comparison) \
	{ \
		std::size_t size = con.size(); \
		return size == 0 ? 0 : func_name(&(con.at(0)), size, comparison); \
	}

//----------------------------------------
//整列状態確認
template<class T, class COMPARE>
inline std::size_t calcUnordered(const T* array, const std::size_t size, COMPARE comparison)
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
sortFuncSet(calcUnordered);

//========================================
//ソートアルゴリズムの説明
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
//----------------------------------------
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
//※交換発生有無のチェックを行い、最適化する
//----------------------------------------
template<class T, class COMPARE>
std::size_t bubbleSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(bubbleSort);

//----------------------------------------
//アルゴリズム：シェーカーソート
//----------------------------------------
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
//※交換発生有無のチェックを行い、最適化する
//----------------------------------------
template<class T, class COMPARE>
std::size_t shakerSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(shakerSort);

//----------------------------------------
//アルゴリズム：奇遇転置ソート
//----------------------------------------
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
//※OpenMPを使用し、並列化で最適化する
//----------------------------------------
template<class T, class COMPARE>
std::size_t oddEvenSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(oddEvenSort);

//----------------------------------------
//アルゴリズム：シェアソート
//----------------------------------------
//・平均計算時間：-
//・最悪計算時間：O(n^1.5)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
//※OpenMPを使用し、並列化で最適化する
//----------------------------------------
template<class T, class COMPARE>
std::size_t shareSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(shareSort);

//----------------------------------------
//アルゴリズム：コムソート
//----------------------------------------
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class COMPARE>
std::size_t combSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(combSort);

//----------------------------------------
//アルゴリズム：ノームソート
//----------------------------------------
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
template<class T, class COMPARE>
std::size_t gnomeSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(gnomeSort);

//----------------------------------------
//アルゴリズム：シェーカーノームソート
//----------------------------------------
//・平均計算時間：-
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
template<class T, class COMPARE>
std::size_t shakerGnomeSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(shakerGnomeSort);

//----------------------------------------
//アルゴリズム：クイックソート
//----------------------------------------
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(log n)
//・安定性：　　　×
//----------------------------------------
//※再帰処理を使用せずに最適化（最大件数を log2(4294967296) = 32 とする）
//----------------------------------------
template<class T, class COMPARE>
std::size_t quickSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(quickSort);

//========================================
//ソートアルゴリズム分類：選択ソート
//========================================

//----------------------------------------
//アルゴリズム：選択ソート
//----------------------------------------
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class COMPARE>
std::size_t selectionSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	T* now = array;
	const std::size_t size_1 = size - 1;
	for (std::size_t i = 0; i < size_1; ++i, ++now)
	{
		T* min = now;
		T* check = now;
		for (std::size_t ii = i + 1; ii < size; ++ii)
		{
			++check;
			if (comparison(*check, *min))
				min = check;
		}
		if (now != min)
		{
			T tmp = *min;
			*min = *now;
			*now = tmp;
			++swapped_count;
		}
	}
	return swapped_count;
}
sortFuncSet(selectionSort);

//----------------------------------------
//アルゴリズム：ヒープソート
//----------------------------------------
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class COMPARE>
std::size_t heapSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(heapSort);

//========================================
//ソートアルゴリズム分類：挿入ソート
//========================================

//----------------------------------------
//アルゴリズム：挿入ソート
//----------------------------------------
//・平均計算時間：O(n + d) ※d = O(n^2
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
template<class T, class COMPARE>
std::size_t insertionSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(insertionSort);

//----------------------------------------
//アルゴリズム：シェルソート
//----------------------------------------
//・平均計算時間：-
//・最悪計算時間：O(n log^2 n)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class COMPARE>
std::size_t shellSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(shellSort);

//========================================
//ソートアルゴリズム分類：混成ソート
//========================================

//----------------------------------------
//アルゴリズム：イントロソート
//----------------------------------------
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(n log n)
//・安定性：　　　×
//----------------------------------------
//※クイックソートの再帰レベルが log n に達したら、
//　ヒープソートに切り替える。
//　また、再起の末、ソートの対象件数が一定数（32など）未満に
//　なったら、挿入ソートに切り替える。
//※STLのstd::sort()と同様の手法。
//----------------------------------------
template<class T, class COMPARE>
std::size_t introSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(introSort);

//----------------------------------------
//アルゴリズム：事前チェックソート
//----------------------------------------
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(n log n)
//・安定性：　　　○
//----------------------------------------
//※安定ソートのみを使用し、高速性を追求
//----------------------------------------
template<class T, class COMPARE>
//----------------------------------------
std::size_t preCheckSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size == 0)
		return 0;
	std::size_t swapped_count = 0;
	return swapped_count;
}
sortFuncSet(preCheckSort);

//--------------------------------------------------------------------------------
//テスト

#include <memory.h>//_aligned_malloc,memalign用
#include <algorithm>//std::sort, std::for_each用
#include <array>//C++11 std::array用
#include <random>//C++11 random用
#include <chrono>//C++11 std::chrono用

#include "sub.h"

//----------------------------------------
//テスト用構造体の配列型
class array_t : public std::array<data_t, TEST_DATA_COUNT>
{
public:
	void* operator new(const size_t size)
	{
		return _memalign(TEST_DATA_ALIGN, sizeof(array_t));
	}
	void operator delete (void* p)
	{
		_free(p);
	}
};

//----------------------------------------
//テスト用の比較処理
//qsort用関数
int comparison_func_qsort(const void*lhs, const void*rhs)
{
	return reinterpret_cast<const data_t*>(lhs)->m_key - reinterpret_cast<const data_t*>(rhs)->m_key;
}
//通常関数
extern bool comparison_func(const data_t& lhs, const data_t& rhs);
//インライン関数
inline bool comparison_func_inline(const data_t& lhs, const data_t& rhs)
{
	return lhs.m_key < rhs.m_key;
}
//関数オブジェクト
struct comparison_functor{
	inline bool operator()(const data_t& lhs, const data_t& rhs)
	{
		return lhs.m_key < rhs.m_key;
	}
};
//ラムダ関数
auto comparison_lambda = [](const data_t& lhs, const data_t& rhs) -> bool
{
	return lhs.m_key < rhs.m_key;
};
//デフォルト
//#define comparison_default comparison_func
//#define comparison_default comparison_func_inline
//#define comparison_default comparison_functor()
#define comparison_default comparison_lambda

//----------------------------------------
//メイン
int main(const int argc, const char* argv[])
{

	//時間計測
	auto begin_time = std::chrono::system_clock::now();
	auto prev_time = begin_time;

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
	auto printElapsedTimeDirect = [&calcElapsedTime](const double elapsed_time, const bool is_preint) -> std::chrono::system_clock::time_point
	{
		if (is_preint)
			printf("*elapsed time=%.9llf sec\n", elapsed_time);
		return std::chrono::system_clock::now();
	};
	auto printElapsedTime = [&calcElapsedTime, &printElapsedTimeDirect](const std::chrono::system_clock::time_point& prev_time, const bool is_print) -> std::chrono::system_clock::time_point
	{
		const auto now_time = std::chrono::system_clock::now();
		const auto elapsed_time = calcElapsedTime(now_time, prev_time);
		return printElapsedTimeDirect(elapsed_time, is_print);
	};

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
	auto makeArray = [&prev_time, &printElapsedTime](array_t*& array, const init_type_t type, const char* type_name)
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
		const bool is_print = true;
		if (is_print)
		{
			const data_t* element0_p = &(*array)[0];
			const data_t* element1_p = &(*array)[1];
			const std::size_t data_size = sizeof(data_t);
			const std::size_t element_size = reinterpret_cast<intptr_t>(element1_p)-reinterpret_cast<intptr_t>(element0_p);
			const std::size_t array_size = sizeof(*array);
			const std::size_t element_count = array->size();
			printf("array_size=%d, element_count=%d, element_size=%d, data_size=%d, element0_p=%p, element1_p=%p\n", array_size, element_count, element_size, data_size, element0_p, element1_p);
		}
		prev_time = printElapsedTime(prev_time, is_print);
	};
	array_t* array_shuffle1 = nullptr;
	array_t* array_shuffle2 = nullptr;
	array_t* array_shuffle3 = nullptr;
	array_t* array_ordered = nullptr;
	array_t* array_reversed = nullptr;
	array_t* array_ordered_without_both_ends = nullptr;
	auto makeArraySet = [&makeArray, &array_shuffle1, &array_shuffle2, &array_shuffle3, &array_ordered, &array_reversed, &array_ordered_without_both_ends]()
	{
		#define PARAM(x) array_##x, init_##x, #x
		makeArray(PARAM(shuffle1));
		makeArray(PARAM(shuffle2));
		makeArray(PARAM(shuffle3));
		makeArray(PARAM(ordered));
		makeArray(PARAM(reversed));
		makeArray(PARAM(ordered_without_both_ends));
		#undef PARAM
	};
	auto copyWorkArray = [&prev_time, &printElapsedTime, &array_shuffle1, &array_shuffle2, &array_shuffle3, &array_ordered, &array_reversed, &array_ordered_without_both_ends](array_t*& array, const init_type_t type, const char* type_name)
	{
		const bool is_print = false;
		if (is_print)
			printf("----- Copy Work Array(%s) -----\n", type_name);
		array = new array_t();
		const array_t* array_src = nullptr;
		switch (type)
		{
		case init_shuffle1:                   array_src = array_shuffle1; break;
		case init_shuffle2:                   array_src = array_shuffle2; break;
		case init_shuffle3:                   array_src = array_shuffle3; break;
		case init_ordered:                    array_src = array_ordered; break;
		case init_reversed:                   array_src = array_reversed; break;
		case init_ordered_without_both_ends:  array_src = array_ordered_without_both_ends; break;
		}
		*array = *array_src;
		prev_time = printElapsedTime(prev_time, is_print);
	};

	//配列削除
	auto deleteArray = [&prev_time, &printElapsedTime](array_t*& array, const char* type_name)
	{
		printf("----- Delete array(%s) -----\n", type_name);
		delete array;
		array = nullptr;
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	auto deleteArraySet = [&deleteArray, &array_shuffle1, &array_shuffle2, &array_shuffle3, &array_ordered, &array_reversed, &array_ordered_without_both_ends]()
	{
		#define PARAM(x) array_##x, #x
		deleteArray(PARAM(shuffle1));
		deleteArray(PARAM(shuffle2));
		deleteArray(PARAM(shuffle3));
		deleteArray(PARAM(ordered));
		deleteArray(PARAM(reversed));
		deleteArray(PARAM(ordered_without_both_ends));
		#undef PARAM
	};
	auto deleteWorkArray = [&prev_time, &printElapsedTime](array_t*& array, const char* type_name)
	{
		const bool is_print = false;
		if (is_print)
			printf("----- Delete Work Array(%s) -----\n", type_name);
		delete array;
		array = nullptr;
		prev_time = printElapsedTime(prev_time, is_print);
	};

	//配列状態表示
	auto showArrayCondition = [&prev_time, &printElapsedTime](const array_t* array)
	{
		int ng = calcUnordered(*array, comparison_default);
		if (ng == 0)
			printf("Array is ordered.(count=%d)\n", array->size());
		else
			printf("Array is NOT ordered! (NG=%d/count=%d)\n", ng, array->size());
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};

	//ソート
	typedef std::function<std::size_t(array_t*)> sort_procedure;
	auto sort = [&prev_time, &getElapsedTime, &printElapsedTimeDirect](array_t*& array, sort_procedure sort_proc) -> double
	{
		printf("----- Sort -----\n");
		prev_time = std::chrono::system_clock::now();
		const std::size_t swapped = sort_proc(array);
		double elapsed_time = getElapsedTime(prev_time);
		if (swapped != 0xffffffff)
			printf("swapped=%d\n", swapped);
		const bool is_print = true;
		prev_time = printElapsedTimeDirect(elapsed_time, is_print);
		return elapsed_time;
	};
	
	//計測
	auto measure = [&](const init_type_t type, const char* type_name, sort_procedure sort_proc) -> double
	{
		printf("\n");
		printf("------------------------------\n");
		printf("Measure type: %s\n", type_name);
		printf("------------------------------\n");
		array_t* array = nullptr;//配列
		copyWorkArray(array, type, type_name);//配列初期化
		showArrayCondition(array);//配列状態表示
		double elapsed_time = sort(array, sort_proc);//ソート
		showArrayCondition(array);//配列状態表示
		deleteWorkArray(array, type_name);//配列削除
		return elapsed_time;
	};

	//平均処理時間表示
	auto printAverageTime = [](const char* sort_type_name, const double sorting_time, const int measure_count) -> double
	{
		const auto average_time = sorting_time / static_cast<double>(measure_count);
		printf("\n");
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("*** sorting time=%.9llf sec ---> average time=%.9llf sec\n", sorting_time, average_time);
		printf("============================================================\n");
		return average_time;
	};

	//まとめて計測
	auto measureAll = [&](const char* sort_type_name, sort_procedure sort_proc) -> double
	{
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("============================================================\n");

		double sorting_time = 0.;//ソート処理時間
		
		#define PARAM(x) init_##x, #x

		//シャッフルパターン１
		sorting_time += measure(PARAM(shuffle1), sort_proc);

		//シャッフルパターン２
		sorting_time += measure(PARAM(shuffle2), sort_proc);

		//シャッフルパターン３
		sorting_time += measure(PARAM(shuffle3), sort_proc);

		//整列済みパターン
		sorting_time += measure(PARAM(ordered), sort_proc);

		//逆順整列済みパターン
		sorting_time += measure(PARAM(reversed), sort_proc);

		//整列済みパターン（ただし、始端と終端のみ入れ替え）
		sorting_time += measure(PARAM(ordered_without_both_ends), sort_proc);

		#undef PARAM

		return printAverageTime(sort_type_name, sorting_time, init_pattern_num);//平均ソート処理時間表示
	};

	//----------------------------------------
	//測定開始
	printf("============================================================\n");
	printf("Initialize\n");
	printf("============================================================\n");
	makeArraySet();
	printf("\n");
	printf("\n");

	//----------------------------------------
	//標準ライブラリによるソート

	//--------------------
	//Cライブラリ：qsort関数
	//アルゴリズム：クイックソート
	auto clib_qsort = [](array_t* array) -> std::size_t
	{
		qsort(&array->at(0), array->size(),sizeof(data_t), comparison_func_qsort);
		return 0xffffffff;
	};
	const double avg_clib_qsort = measureAll("C-Library qsort", clib_qsort);
	printf("\n");
	printf("\n");

	//--------------------
	//STLソート1：通常関数で比較
	//アルゴリズム：イントロソート（クイックソート＋ヒープソート＋挿入ソート）
	auto stl_sort1 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_func);
		return 0xffffffff;
	};
	const double avg_stl1 = measureAll("STL std::sort(with function)", stl_sort1);
	printf("\n");
	printf("\n");

	//STLソート2：インライン関数で比較
	//アルゴリズム：（同上）
	auto stl_sort2 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_func_inline);
		return 0xffffffff;
	};
	const double avg_stl2 = measureAll("STL std::sort(with inline function)", stl_sort2);
	printf("\n");
	printf("\n");

	//STLソート3：関数オブジェクトで比較
	//アルゴリズム：（同上）
	auto stl_sort3 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_functor());
		return 0xffffffff;
	};
	const double avg_stl3 = measureAll("STL std::sort(with functor)", stl_sort3);
	printf("\n");
	printf("\n");

	//STLソート4：ラムダ関数で比較
	//アルゴリズム：（同上）
	auto stl_sort4 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_lambda);
		return 0xffffffff;
	};
	const double avg_stl4 = measureAll("STL std::sort(with lamda)", stl_sort4);
	printf("\n");
	printf("\n");
	
	//----------------------------------------
	//交換ソート

	//アルゴリズム：バブルソート
	auto bubble_sort = [](array_t* array) -> std::size_t
	{
		return bubbleSort(&array->at(0), array->size(), comparison_default);
	};
	const double avg_bubble = measureAll("Bubble sort", bubble_sort);
	printf("\n");
	printf("\n");
	
	//アルゴリズム：シェーカーソート
	auto shaker_sort = [](array_t* array) -> std::size_t
	{
		return shakerSort(*array, comparison_default);
	};
	const double avg_shaker = measureAll("Shaker sort", shaker_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：奇遇転置ソート
	auto odd_even_sort = [](array_t* array) -> std::size_t
	{
		return oddEvenSort(*array, comparison_default);
	};
	const double avg_odd_even = measureAll("Odd-Even sort", odd_even_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェアソート
	auto share_sort = [](array_t* array) -> std::size_t
	{
		return shareSort(*array, comparison_default);
	};
	const double avg_share = measureAll("Share sort", share_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：コムソート
	auto comb_sort = [](array_t* array) -> std::size_t
	{
		return combSort(*array, comparison_default);
	};
	const double avg_comb = measureAll("Comb sort", comb_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：ノームソート
	auto gnome_sort = [](array_t* array) -> std::size_t
	{
		return gnomeSort(*array, comparison_default);
	};
	const double avg_gnome = measureAll("Gnome sort", gnome_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェーカーノームソート
	auto shaker_gnome_sort = [](array_t* array) -> std::size_t
	{
		return shakerGnomeSort(*array, comparison_default);
	};
	const double avg_shaker_gnome = measureAll("Shaker Gnome sort", shaker_gnome_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：クイックソート
	auto quick_sort = [](array_t* array) -> std::size_t
	{
		return quickSort(*array, comparison_default);
	};
	const double avg_quick = measureAll("Quick sort", quick_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//選択ソート

	//アルゴリズム：選択ソート
	auto selection_sort = [](array_t* array) -> std::size_t
	{
		return selectionSort(*array, comparison_default);
	};
	const double avg_selection = measureAll("Selection sort", selection_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：ヒープソート
	auto heap_sort = [](array_t* array) -> std::size_t
	{
		return heapSort(*array, comparison_default);
	};
	const double avg_heap = measureAll("Heap sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//挿入ソート

	//アルゴリズム：挿入ソート
	auto insertion_sort = [](array_t* array) -> std::size_t
	{
		return insertionSort(*array, comparison_default);
	};
	const double avg_insertion = measureAll("Insertion sort", insertion_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェルソート
	auto shell_sort = [](array_t* array) -> std::size_t
	{
		return shellSort(*array, comparison_default);
	};
	const double avg_shell = measureAll("Shell sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//混成ソート

	//アルゴリズム：イントロソート
	auto intro_sort = [](array_t* array) -> std::size_t
	{
		return introSort(*array, comparison_default);
	};
	const double avg_intro = measureAll("Intro sort", heap_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：事前チェックソート
	auto pre_check_sort = [](array_t* array) -> std::size_t
	{
		return preCheckSort(*array, comparison_default);
	};
	const double avg_pre_check = measureAll("Pre-Check sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//測定終了
	printf("============================================================\n");
	printf("Result(average elapsed-time)\n");
	printf("============================================================\n");
	printf("[C-Library sort](Quick sort)\n");
	printf("- qsort:              %12.9llf sec\n", avg_clib_qsort);
	printf("[STL sort](Intro sort)\n");
	printf("- std::sort:          %12.9llf sec (with function)\n", avg_stl1);
	printf("- std::sort:          %12.9llf sec (with inline function)\n", avg_stl2);
	printf("- std::sort:          %12.9llf sec (with functor)\n", avg_stl3);
	printf("- std::sort:          %12.9llf sec (with lambda)\n", avg_stl4);
	printf("[Exchange sorts]\n");
	printf("- Bubble sort:        %12.9llf sec\n", avg_bubble);
	printf("- Shaker sort:        %12.9llf sec\n", avg_shaker);
	printf("- Odd-Even sort:      %12.9llf sec\n", avg_odd_even);
	printf("- Share sort:         %12.9llf sec\n", avg_share);
	printf("- Comb sort:          %12.9llf sec\n", avg_comb);
	printf("- Gnome sort:         %12.9llf sec\n", avg_gnome);
	printf("- Shakere gnome sort: %12.9llf sec\n", avg_shaker_gnome);
	printf("- Quick sort:         %12.9llf sec\n", avg_quick);
	printf("[Selection sorts]\n");
	printf("- Selection sort:     %12.9llf sec\n", avg_selection);
	printf("- Heap sort:          %12.9llf sec\n", avg_heap);
	printf("[Insertion sorts]\n");
	printf("- Insertion sort:     %12.9llf sec\n", avg_insertion);
	printf("- Shell sort:         %12.9llf sec\n", avg_shell);
	printf("[Hybrid sorts]\n");
	printf("- Intro sort:         %12.9llf sec\n", avg_intro);
	printf("- Pre-Check sort:     %12.9llf sec\n", avg_pre_check);
	printf("\n");
	printf("============================================================\n");
	printf("Terminate\n");
	printf("============================================================\n");
	deleteArraySet();
	printf("\n");
	printf("- Finish -\n");
	printElapsedTime(begin_time, true);//処理時間表示

	return EXIT_SUCCESS;
}

// End of file
