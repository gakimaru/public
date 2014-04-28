#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>//qsort関数用
#include <stdint.h>//intptr_t用
#include <crtdefs.h>//ptrdiff_t用
#include <cstddef>//std::size_t用
#include <functional>//C++11 std::function用

//--------------------------------------------------------------------------------
//ソートアルゴリズム

//========================================
//ソート補助処理
//========================================

//----------------------------------------
//ソート処理オーバーロード関数用マクロ
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
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	std::size_t end = size - 1;
	//for (std::size_t i = 0; i < end - 1; ++i)
	while (true)
	{
		bool is_swapped = false;
		T* now = array;
		T* next = now + 1;
		for (std::size_t ii = 0; ii < end; ++ii, ++now, ++next)
		{
			if (comparison(*next, *now))
			{
				tmp = *next;
				*next = *now;
				*now = tmp;
				is_swapped = true;
				++swapped_count;
			}
		}
		--end;
		if (end == 0 || !is_swapped)
			break;
	}
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
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	std::size_t begin = 0;
	std::size_t end = size - 1;
	while(true)
	{
		bool is_swapped = false;
		T* now = array + begin;
		T* next = now + 1;
		for (std::size_t i = begin; i < end; ++i, ++now, ++next)
		{
			if (comparison(*next, *now))
			{
				tmp = *next;
				*next = *now;
				*now = tmp;
				is_swapped = true;
				++swapped_count;
			}
		}
		--end;
		if (begin == end || !is_swapped)
			break;
		is_swapped = false;
		now = array + end;
		T* prev = now - 1;
		for (std::size_t i = end; i > begin; --i, --now, --prev)
		{
			if (comparison(*now, *prev))
			{
				tmp = *prev;
				*prev = *now;
				*now = tmp;
				is_swapped = true;
				++swapped_count;
			}
		}
		++begin;
		if (begin == end || !is_swapped)
			break;
	}
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
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	std::size_t end = size - 1;
	bool is_swapped = true;
	while (is_swapped)
	{
		is_swapped = false;
		for (std::size_t odd_even = 0; odd_even < 2; ++odd_even)
		{
			std::size_t i;
			T* now;
			T* next;
			tmp;
		#pragma omp parallel for reduction(+:swapped_count) private(now, next, tmp)
			for (i = odd_even; i < end; i += 2)
			{
				now = array + i;
				next = now + 1;
				if (comparison(*next, *now))
				{
					tmp = *next;
					*next = *now;
					*now = tmp;
					is_swapped = true;
					++swapped_count;
				}
			}
		}
	}
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
#include <math.h>//sqrt()用
template<class T, class COMPARE>
std::size_t shearSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	std::size_t row;
	std::size_t col;
	std::size_t row_min;
	std::size_t col_min;
	std::size_t rows_col;
	std::size_t cols_row;
	std::size_t rows_1_col;
	std::size_t cols_1_row;
	T* now;
	T* min;
	T* check;
	bool is_odd;
	std::size_t rows = static_cast<std::size_t>(sqrt(size));//正方形のデータとして扱うための行数算出
	std::size_t over = size % rows;//余り算出
	if (over > 0 && (rows & 0x1) == 0x1)//余りが出た場合、（余りを除く）行数が偶数になるように調整
	{
		--rows;
		over = size % rows;
	}
	const std::size_t cols = size / rows;//1行当たりの列数算出
	auto log2 = [](std::size_t val) -> std::size_t
	{
		std::size_t result = 0;
		while (val >>= 1)
			++result;
		return result;
	};
	const int sorting_count = log2(rows) + 1;//ソート実行回数を算出
	for (int i = 0; i < sorting_count; ++i)
	{
		//各行ごとに、列方向にソート
		//※偶数行は小さい順、奇数行は大きい順にソート
	#pragma omp parallel for reduction(+:swapped_count) private(col, col_min, cols_row, cols_1_row, now, min, check, tmp, is_odd)
		for (row = 0; row <= rows; ++row)
		{
			cols_row = row == rows ? over : cols;
			if (cols_row > 1)
			{
				is_odd = ((row & 0x1) == 0x1);
				//選択ソート
				now = array + row * cols;
				cols_1_row = cols_row - 1;
				for (col = 0; col < cols_1_row; ++col, ++now)
				{
					min = now;
					check = now;
					for (col_min = col + 1; col_min < cols_row; ++col_min)
					{
						++check;
						if ((!is_odd && comparison(*check, *min)) ||//偶数行は小さい順
						    ( is_odd && comparison(*min, *check)))  //奇数行は大きい順
							min = check;
					}
					if (now != min)
					{
						tmp = *min;
						*min = *now;
						*now = tmp;
						++swapped_count;
					}
				}
			}
		}
		//各列ごとに、行方向にソート
		//※小さい順にソート
	#pragma omp parallel for reduction(+:swapped_count) private(row, row_min, rows_col, rows_1_col, now, min, check, tmp)
		for (col = 0; col < cols; ++col)
		{
			rows_col = rows + (col < over ? 1 : 0);
			//選択ソート
			now = array + col;
			rows_1_col = rows_col - 1;
			for (row = 0; row < rows_1_col; ++row, now += cols)
			{
				min = now;
				check = now;
				for (row_min = row + 1; row_min < rows_col; ++row_min)
				{
					check += cols;
					if (comparison(*check, *min))
						min = check;
				}
				if (now != min)
				{
					tmp = *min;
					*min = *now;
					*now = tmp;
					++swapped_count;
				}
			}
		}
	}
	{
		//各行ごとに、列方向にソート
		//※小さい順にソート
	#pragma omp parallel for reduction(+:swapped_count) private(col, col_min, cols_row, cols_1_row, now, min, check, tmp)
		for (row = 0; row <= rows; ++row)
		{
			cols_row = row == rows ? over : cols;
			if (cols_row > 1)
			{
				//選択ソート
				now = array + row * cols;
				cols_1_row = cols_row - 1;
				for (col = 0; col < cols_1_row; ++col, ++now)
				{
					min = now;
					check = now;
					for (col_min = col + 1; col_min < cols_row; ++col_min)
					{
						++check;
						if (comparison(*check, *min))
							min = check;
					}
					if (now != min)
					{
						tmp = *min;
						*min = *now;
						*now = tmp;
						++swapped_count;
					}
				}
			}
		}
	}
	return swapped_count;
}
sortFuncSet(shearSort);

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
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	std::size_t h = size;
	const T* end = array + size;
	while (true)
	{
		h = h == 1 ? 1 : h * 10 / 13;
		bool is_swapped = false;
		T* now = array;
		T* next = now + h;
		while (next < end)
		{
			if (comparison(*next, *now))
			{
				tmp = *next;
				*next = *now;
				*now = tmp;
				is_swapped = true;
				++swapped_count;
			}
			++now;
			++next;
		}
		if (h == 1 && !is_swapped)
			break;
	}
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
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	const T* end = array + size;
	T* now = array;
	T* next = now + 1;
	while (next < end)
	{
		if (comparison(*next, *now))
		{
			T* prev = now;
			now = next;
			while (prev >= array)
			{
				if (comparison(*now, *prev))
				{
					tmp = *prev;
					*prev = *now;
					*now = tmp;
					++swapped_count;
				}
				now = prev;
				--prev;
			}
		}
		now = next;
		++next;
	}
	return swapped_count;
}
sortFuncSet(gnomeSort);

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
std::size_t _quickSort(T* array, const std::size_t size, COMPARE comparison)
{
//#define USE_RECURSIVE_CALL//再帰処理版を有効にする場合は、このマクロを有効にする
#ifdef USE_RECURSIVE_CALL
	//--------------------
	//再帰処理版
	if (size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	//配列の範囲情報
	const T* term = array + size;
	T* begin = array;
	T* end = array + size - 1;
	//中央値を決定
	const T* med = array + (size >> 1);
	const T* pivot =
		comparison(*begin, *med) ?
			comparison(*med, *end) ?
				med :
				comparison(*end, *begin) ?
					begin :
					end :
			comparison(*end, *med) ?
				med :
				comparison(*begin, *end) ?
					begin :
					end;
	//中央値未満の配列と中央値以上の配列に二分
	while (true)
	{
		while (comparison(*begin, *pivot))
			++begin;
		while (comparison(*pivot, *end))
			--end;
		if (begin >= end)
			break;
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		pivot = pivot == begin ? end : pivot == end ? begin : pivot;//中央値の位置調整（中央値の位置も入れ替わるため）
		++swapped_count;
		++begin;
		--end;
	}
	//再帰処理
	swapped_count += _quickSort(array, begin - array, comparison);//中央値未満の配列
	swapped_count += _quickSort(end + 1, term - end - 1, comparison);//中央値以上の配列
	return swapped_count;
#else//USE_RECURSIVE_CALL
	//--------------------
	//スタック処理版
	std::size_t swapped_count = 0;
	T tmp;
	struct stack_t
	{
		T* array;
		std::size_t size;
	};
	static const int STACK_MAX = 32 * 2;
	stack_t stack[STACK_MAX];
	//最初の配列をスタックにプッシュ
	stack_t* stack_p = &stack[0];
	stack_p->array = array;
	stack_p->size = size;
	int stack_curr = 1;//スタック位置
	while(stack_curr > 0)
	{
		//配列をスタックから取得
		stack_p = &stack[--stack_curr];
		T* _array = stack_p->array;
		const size_t _size = stack_p->size;
		//配列の範囲情報
		const T* term = _array + _size;
		T* begin = _array;
		T* end = _array + _size - 1;
		//中央値を決定
		const T* med = _array + (_size >> 1);
		const T* pivot =
			comparison(*begin, *med) ?
				comparison(*med, *end) ?
					med :
					comparison(*end, *begin) ?
						begin :
						end :
				comparison(*end, *med) ?
					med :
					comparison(*begin, *end) ?
						begin :
						end;
		//中央値未満の配列と中央値以上の配列に二分
		while (true)
		{
			while (comparison(*begin, *pivot))
				++begin;
			while (comparison(*pivot, *end))
				--end;
			if (begin >= end)
				break;
			tmp = *begin;
			*begin = *end;
			*end = tmp;
			pivot = pivot == begin ? end : pivot == end ? begin : pivot;//中央値の位置調整（中央値の位置も入れ替わるため）
			++swapped_count;
			++begin;
			--end;
		}
		//recursive = 0 : 中央値未満の配列をプッシュ
		//            1 : 中央値以上の配列をプッシュ
		for (int recursive = 0; recursive < 2; ++recursive)
		{
			T* new_array = recursive == 0 ? _array : end + 1;
			const std::size_t new_size = recursive == 0 ? begin - _array : term - end - 1;
			if (new_size >= 1)
			{
				stack_p = &stack[stack_curr++];
				stack_p->array = new_array;
				stack_p->size = new_size;
			}
		}
	}
	return swapped_count;
#endif//USE_RECURSIVE_CALL
}
template<class T, class COMPARE>
inline std::size_t quickSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size <= 1)
		return 0;
	return _quickSort(array, size, comparison);
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
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
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
			tmp = *min;
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
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	//二分ヒープ登録
	for (std::size_t heap_size = 1; heap_size < size; ++heap_size)
	{
		T* now = array + heap_size;
		//アップヒープ
		std::size_t parent_i = heap_size;
		while (parent_i > 0)
		{
			parent_i = (parent_i - 1) >> 1;
			T* parent = array + parent_i;
			if (comparison(*parent, *now))
			{
				tmp = *parent;
				*parent = *now;
				*now = tmp;
				++swapped_count;
			}
			else
				break;
			now = parent;
		}
	}
	//二分ヒープ取り出し
	for (std::size_t heap_size = size - 1; heap_size > 0; --heap_size)
	{
		T* now = array + heap_size;
		//ダウンヒープ
		{
			tmp = *array;
			*array = *now;
			*now = tmp;
			++swapped_count;
		}
		now = array;
		std::size_t child_i = 0;
		while (true)
		{
			child_i = (child_i << 1) + 1;
			if (child_i >= heap_size)
				break;
			T* child = array + child_i;
			T* child_r = child_i + 1 < heap_size ? child + 1 : nullptr;
			if (child_r && comparison(*child, *child_r))
			{
				child = child_r;
				++child_i;
			}
			if(comparison(*now, *child))
			{
				tmp = *child;
				*child = *now;
				*now = tmp;
				++swapped_count;
			}
			else
				break;
			now = child;
		}
	}
	return swapped_count;
}
sortFuncSet(heapSort);

//========================================
//ソートアルゴリズム分類：挿入ソート
//========================================

//----------------------------------------
//アルゴリズム：挿入ソート
//----------------------------------------
//・平均計算時間：O(n + d) ※d = O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
template<class T, class COMPARE>
std::size_t insertionSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	const T* end = array + size;
	T* now = array;
	T* next = now + 1;
	while (next < end)
	{
		if (comparison(*next, *now))
		{
			T* min = now;
			T* prev = now - 1;
			while (prev >= array)
			{
				if (comparison(*next, *prev))
					min = prev;
				--prev;
			}
			tmp = *next;
			//※VC++2013では、memmove関数を使うよりも、直接メモリ操作する方が速い（関数呼び出しのせいか？）
			//memmove(min + 1, min, reinterpret_cast<uintptr_t>(next) - reinterpret_cast<uintptr_t>(min));
			{
				const int move_num = next - min;
				T* dst = min + 1 + move_num;
				const T* src = min + move_num;
				for (int move = 0; move < move_num; ++move)
					*(--dst) = *(--src);
			}
			*min = tmp;
			++swapped_count;
		}
		++now;
		++next;
	}
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
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	const T* end = array + size;
	std::size_t h_stack[32];
	h_stack[0] = 1;
	int h_stack_p = 1;
	std::size_t h = 1;
	while (true)
	{
		h = 3 * h + 1;
		if (h >= size)
			break;
		h_stack[h_stack_p++] = h;
	}
	while (true)
	{
		h = h_stack[--h_stack_p];
		if (h == 1)
			break;
		T* now = array;
		T* next = now + h;
		while (next < end)
		{
			if (comparison(*next, *now))
			{
				T* min = now;
				T* prev = now - h;
				while (prev >= array)
				{
					if (comparison(*next, *prev))
						min = prev;
					prev -= h;
				}
				tmp = *next;
				T* move = next;
				while (move > min)
				{
					T* move_prev = move - h;
					*move = *move_prev;
					move = move_prev;
				}
				*min = tmp;
				++swapped_count;
			}
			++now;
			++next;
		}
	}
	swapped_count += insertionSort(array, size, comparison);//最後に挿入ソート
	return swapped_count;
}
sortFuncSet(shellSort);

//----------------------------------------
//アルゴリズム：インプレースマージソート
//----------------------------------------
//・平均計算時間：-
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
template<class T, class COMPARE>
std::size_t inplaceMergeSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T tmp;
	std::size_t block_size = 1;//ブロックサイズ（隣り合ったブロックをマージし、ループごとにブロックサイズを倍にする）
	while (block_size < size)
	{
		const std::size_t block_size_over = size % block_size;
		const std::size_t merge_size = block_size << 1;
		const std::size_t merge_size_over = size % merge_size;
		const std::size_t merge_sets = size / merge_size + (merge_size_over != 0 ? 1 : 0);
		std::size_t merge_pos = 0;
		for (std::size_t merge_set = 0; merge_set < merge_sets; ++merge_set)
		{
			std::size_t merge_pos_next = merge_pos + block_size;
			if (merge_pos_next >= size)//二つ分のブロックが残っていなければこのループは終了（次回のループでマージ）
				break;
			merge_pos_next += block_size;
			const std::size_t block_size_right = merge_pos_next <= size ? block_size : block_size_over;
			T* left_begin = array + merge_pos;
			T* left_end = left_begin + block_size;
			T* right_begin = left_end;
			T* right_end = right_begin + block_size_right;
			T* left = left_end - 1;
			T* right = right_begin;
			while (right < right_end)
			{
				if (comparison(*right, *left))//左ブロックの右端と右ブロックの左端をチェック
				{
					//挿入位置検索
				#if 1
					std::size_t search_range = (right - left_begin) >> 1;
					std::size_t search_pos = search_range;
					T* left_ins = left_begin + search_pos;
					while (search_range != 0)
					{
						const std::size_t search_range_prev = search_range;
						search_range = search_range >> 1;
						left_ins = left_begin + search_pos;
						if (comparison(*right, *left_ins))
							search_pos = search_pos - search_range_prev + search_range;
						else
							search_pos = search_pos + search_range;
					}
					while (left_ins < right && comparison(*left_ins, *right))
						++left_ins;
				#else
					T* left_ins = left;
				#endif
					while (left_ins >= left_begin && comparison(*right, *left_ins))
						--left_ins;
					++left_ins;
					//挿入
					tmp = *right;
					//※VC++2013では、memmove関数を使うよりも、直接メモリ操作する方が速い（関数呼び出しのせいか？）
					//memmove(left_ins, left_ins + 1, reinterpret_cast<uintptr_t>(right) - reinterpret_cast<uintptr_t>(left_ins));
					{
						const std::size_t move_elems = right - left_ins;
						T* dst = right;
						T* src = dst - 1;
						for (std::size_t move_elem = 0; move_elem < move_elems; ++move_elem)
							*(dst--) = *(src--);
					}
					*left_ins = tmp;
					++swapped_count;
					++left;
					++right;
				}
				else
					break;
			}
			merge_pos = merge_pos_next;
		}
		block_size <<= 1;
	}
	return swapped_count;
}
sortFuncSet(inplaceMergeSort);

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
//※再帰処理を使用せずに最適化（最大件数を log2(4294967296) = 32 とする）
//※挿入ソート切り替えタイミングを16に設定
//※挿入ソートではなく、コムソートを使用するスタイルに改良
//※ヒープソートではなく、コムソートを使用するスタイルに改良
//----------------------------------------
template<class T, class COMPARE>
std::size_t _introSort(T* array, const std::size_t size, COMPARE comparison)
{
	int depth_max = 0;//ヒープソートに切り替える再帰（スタック）の深さ
	for (std::size_t size_tmp = size; size_tmp > 1; size_tmp >>= 1, ++depth_max);
	//--------------------
	//クイックソート：スタック処理版
	//※再帰処理版は省略
	static const std::size_t SIZE_THRESHOLD = 16;//挿入ソートに切り替える件数　※VC++のSTLでは32
	std::size_t swapped_count = 0;
	T tmp;
	struct stack_t
	{
		T* array;
		std::size_t size;
		int depth;
	};
	static const int STACK_MAX = 32 * 2;
	stack_t stack[STACK_MAX];
	//最初の配列をスタックにプッシュ
	stack_t* stack_p = &stack[0];
	stack_p->array = array;
	stack_p->size = size;
	stack_p->depth = depth_max;
	int stack_curr = 1;//スタック位置
	while (stack_curr > 0)
	{
		//配列をスタックから取得
		stack_p = &stack[--stack_curr];
		T* _array = stack_p->array;
		const size_t _size = stack_p->size;
		const int _depth = stack_p->depth;
		//配列の範囲情報
		const T* term = _array + _size;
		T* begin = _array;
		T* end = _array + _size - 1;
		//中央値を決定
		const T* med = _array + (_size >> 1);
		const T* pivot =
			comparison(*begin, *med) ?
				comparison(*med, *end) ?
					med :
					comparison(*end, *begin) ?
						begin :
						end :
				comparison(*end, *med) ?
					med :
					comparison(*begin, *end) ?
						begin :
						end;
		//中央値未満の配列と中央値以上の配列に二分
		while (true)
		{
			while (comparison(*begin, *pivot))
				++begin;
			while (comparison(*pivot, *end))
				--end;
			if (begin >= end)
				break;
			tmp = *begin;
			*begin = *end;
			*end = tmp;
			pivot = pivot == begin ? end : pivot == end ? begin : pivot;//中央値の位置調整（中央値の位置も入れ替わるため）
			++swapped_count;
			++begin;
			--end;
		}
		//recursive = 0 : 中央値未満の配列をプッシュ
		//            1 : 中央値以上の配列をプッシュ
		for (int recursive = 0; recursive < 2; ++recursive)
		{
			T* new_array = recursive == 0 ? _array : end + 1;
			const std::size_t new_size = recursive == 0 ? begin - _array : term - end - 1;
			const int new_depth = _depth - 1;
			if (new_size >= 1)
			{
				if (new_size < SIZE_THRESHOLD)
				{
					//swapped_count += insertionSort(new_array, new_size, comparison);//挿入ソートに切り替え ※標準は挿入ソート
					swapped_count += combSort(new_array, new_size, comparison);//【改良】コムソートに切り替え
				}
				else if (new_depth == 0)
				{
					//swapped_count += heapSort(new_array, new_size, comparison);//ヒープソートに切り替え
					swapped_count += combSort(new_array, new_size, comparison);//【改良】コムソートに切り替え
				}
				else
				{
					//再帰
					stack_p = &stack[stack_curr++];
					stack_p->array = new_array;
					stack_p->size = new_size;
					stack_p->depth = new_depth;
				}
			}
		}
	}
	return swapped_count;
}
template<class T, class COMPARE>
inline std::size_t introSort(T* array, const std::size_t size, COMPARE comparison)
{
	if (!array || size <= 1)
		return 0;
	return _introSort(array, size, comparison);
}
sortFuncSet(introSort);

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
inline int comparison_func_qsort(const void*lhs, const void*rhs)
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
			printf("*elapsed time=%.9llf sec.\n", elapsed_time);
		return std::chrono::system_clock::now();
	};
	auto printElapsedTime = [&calcElapsedTime, &printElapsedTimeDirect](const std::chrono::system_clock::time_point& prev_time, const bool is_print) -> std::chrono::system_clock::time_point
	{
		const auto now_time = std::chrono::system_clock::now();
		const auto elapsed_time = calcElapsedTime(now_time, prev_time);
		return printElapsedTimeDirect(elapsed_time, is_print);
	};

	//配列状態表示
	auto showArrayCondition = [&prev_time, &printElapsedTime](const array_t* array)
	{
		int ng = calcUnordered(*array, comparison_default);
		if (ng == 0)
			printf("Array is ordered. [record(s)=%d]\n", array->size());
		else
			printf("[NG] Array is NOT ordered! [NG=%d / record(s)=%d]\n", ng, array->size());
		{
			const std::size_t size = array->size();
			const data_t* prev = &array->at(0);
			const data_t* now = prev + 1;
			for (std::size_t i = 1; i < size; ++i, ++now, ++prev)
			{
				if (now->m_key == prev->m_key)
				{
					printf("[NG] Sorting program failure !!\n");
					break;
				}
			}
		}
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
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
	auto makeArray = [&prev_time, &printElapsedTime, &showArrayCondition](array_t*& array, const init_type_t type, const char* type_name)
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
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
		showArrayCondition(array);
	#if 0
		const data_t* element0_p = &(*array)[0];
		const data_t* element1_p = &(*array)[1];
		const std::size_t data_size = sizeof(data_t);
		const std::size_t element_size = reinterpret_cast<intptr_t>(element1_p)-reinterpret_cast<intptr_t>(element0_p);
		const std::size_t array_size = sizeof(*array);
		const std::size_t element_count = array->size();
		printf("array_size=%d, element_count=%d, element_size=%d, data_size=%d, element0_p=%p, element1_p=%p\n", array_size, element_count, element_size, data_size, element0_p, element1_p);
	#endif
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
		//printf("----- Copy Work Array(%s) -----\n", type_name);
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
		const bool is_print = false;
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
		//printf("----- Delete Work Array(%s) -----\n", type_name);
		delete array;
		array = nullptr;
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};

	//ソート
	typedef std::function<std::size_t(array_t*)> sort_procedure;
	auto sort = [&prev_time, &getElapsedTime, &printElapsedTimeDirect, &showArrayCondition](array_t*& array, sort_procedure sort_proc, double& elapsed_time, std::size_t& swapped_count)
	{
		//printf("----- Sort -----\n");
		prev_time = std::chrono::system_clock::now();
		swapped_count = sort_proc(array);
		elapsed_time = getElapsedTime(prev_time);
		const bool is_print = true;
		prev_time = printElapsedTimeDirect(elapsed_time, is_print);
		showArrayCondition(array);
		if (swapped_count != 0xffffffff)
			printf("[swapped=%d count(s)]\n", swapped_count);
	};
	
	//計測
	auto measure = [&copyWorkArray, &sort, &deleteWorkArray](const init_type_t type, const char* type_name, sort_procedure sort_proc, double& elapsed_time, std::size_t& swapped_count)
	{
		printf("\n");
		printf("------------------------------\n");
		printf("Sort array(%s)\n", type_name);
		printf("------------------------------\n");
		array_t* array = nullptr;//配列
		copyWorkArray(array, type, type_name);//配列初期化
		sort(array, sort_proc, elapsed_time, swapped_count);//ソート
		deleteWorkArray(array, type_name);//配列削除
	};

	//ソート処理時間集計用構造体
	struct sum_t
	{
		int count;
		double elapsed_time_sum;
		double elapsed_time_avg;
		double elapsed_time_min;
		double elapsed_time_max;
		std::size_t swapped_count_sum;
		std::size_t swapped_count_avg;
		std::size_t swapped_count_min;
		std::size_t swapped_count_max;
		void add(const double elapsed_time, const std::size_t swapped_count)
		{
			++count;
			if (elapsed_time_sum == -1.)
				elapsed_time_sum = 0.;
			elapsed_time_sum += elapsed_time;
			elapsed_time_avg = elapsed_time_sum / static_cast<double>(count);
			if (elapsed_time_min == -1. || elapsed_time_min > elapsed_time)
				elapsed_time_min = elapsed_time;
			if (elapsed_time_max == -1. || elapsed_time_max < elapsed_time)
				elapsed_time_max = elapsed_time;
			if (swapped_count != 0xffffffff)
			{
				if (swapped_count_sum == 0xffffffff)
					swapped_count_sum = 0;
				swapped_count_sum += swapped_count;
				swapped_count_avg = swapped_count_sum / static_cast<std::size_t>(count);
				if (swapped_count_min == 0xffffffff || swapped_count_min > swapped_count)
					swapped_count_min = swapped_count;
				if (swapped_count_max == 0xffffffff || swapped_count_max < swapped_count)
					swapped_count_max = swapped_count;
			}
		}
		sum_t() :
			count(0),
			elapsed_time_sum(-1.),
			elapsed_time_avg(-1.),
			elapsed_time_min(-1.),
			elapsed_time_max(-1.),
			swapped_count_sum(0xffffffff),
			swapped_count_avg(0xffffffff),
			swapped_count_min(0xffffffff),
			swapped_count_max(0xffffffff)
		{}
	};
	
	//まとめて計測
	auto measureAll = [&measure](const char* sort_type_name, sort_procedure sort_proc) -> sum_t
	{
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("============================================================\n");

		#define PARAM(x) init_##x, #x

		//ソート処理時間集計
		sum_t sum;
		double elapsed_time;
		std::size_t swapped_count;

		//シャッフルパターン１
		measure(PARAM(shuffle1), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//シャッフルパターン２
		measure(PARAM(shuffle2), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//シャッフルパターン３
		measure(PARAM(shuffle3), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//整列済みパターン
		measure(PARAM(ordered), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//逆順整列済みパターン
		measure(PARAM(reversed), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//整列済みパターン（ただし、始端と終端のみ入れ替え）
		measure(PARAM(ordered_without_both_ends), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		#undef PARAM

		printf("\n");
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("* Total time       = %.9llf sec.\n", sum.elapsed_time_sum);
		printf("* Average time     = %.9llf sec.\n", sum.elapsed_time_avg);
		printf("* Min time         = %.9llf sec.\n", sum.elapsed_time_min);
		printf("* Max time         = %.9llf sec.\n", sum.elapsed_time_max);
		if (sum.swapped_count_sum != 0xffffffff)
		{
			printf("* Total Swapped    = %9u count(s)\n", sum.swapped_count_sum);
			printf("* Average  Swapped = %9u count(s)\n", sum.swapped_count_avg);
			printf("* Min Swapped      = %9u count(s)\n", sum.swapped_count_min);
			printf("* Max Swapped      = %9u count(s)\n", sum.swapped_count_max);
		}
		printf("============================================================\n");

		return sum;
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
	const sum_t sum_clib_qsort = measureAll("C-Library qsort", clib_qsort);
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
	const sum_t sum_stl1 = measureAll("STL std::sort(with function)", stl_sort1);
	printf("\n");
	printf("\n");

	//STLソート2：インライン関数で比較
	//アルゴリズム：（同上）
	auto stl_sort2 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_func_inline);
		return 0xffffffff;
	};
	const sum_t sum_stl2 = measureAll("STL std::sort(with inline function)", stl_sort2);
	printf("\n");
	printf("\n");

	//STLソート3：関数オブジェクトで比較
	//アルゴリズム：（同上）
	auto stl_sort3 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_functor());
		return 0xffffffff;
	};
	const sum_t sum_stl3 = measureAll("STL std::sort(with functor)", stl_sort3);
	printf("\n");
	printf("\n");

	//STLソート4：ラムダ関数で比較
	//アルゴリズム：（同上）
	auto stl_sort4 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_lambda);
		return 0xffffffff;
	};
	const sum_t sum_stl4 = measureAll("STL std::sort(with lamda)", stl_sort4);
	printf("\n");
	printf("\n");
	
	//----------------------------------------
	//交換ソート

	//アルゴリズム：バブルソート
	auto bubble_sort = [](array_t* array) -> std::size_t
	{
		return bubbleSort(&array->at(0), array->size(), comparison_default);
	};
	const sum_t sum_bubble = measureAll("Bubble sort", bubble_sort);
	printf("\n");
	printf("\n");
	
	//アルゴリズム：シェーカーソート
	auto shaker_sort = [](array_t* array) -> std::size_t
	{
		return shakerSort(*array, comparison_default);
	};
	const sum_t sum_shaker = measureAll("Shaker sort", shaker_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：奇遇転置ソート
	auto odd_even_sort = [](array_t* array) -> std::size_t
	{
		return oddEvenSort(*array, comparison_default);
	};
	const sum_t sum_odd_even = measureAll("Odd-Even sort", odd_even_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェアソート
	auto shear_sort = [](array_t* array) -> std::size_t
	{
		return shearSort(*array, comparison_default);
	};
	const sum_t sum_shear = measureAll("Shear sort", shear_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：コムソート
	auto comb_sort = [](array_t* array) -> std::size_t
	{
		return combSort(*array, comparison_default);
	};
	const sum_t sum_comb = measureAll("Comb sort", comb_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：ノームソート
	auto gnome_sort = [](array_t* array) -> std::size_t
	{
		return gnomeSort(*array, comparison_default);
	};
	const sum_t sum_gnome = measureAll("Gnome sort", gnome_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：クイックソート
	auto quick_sort = [](array_t* array) -> std::size_t
	{
		return quickSort(*array, comparison_default);
	};
	const sum_t sum_quick = measureAll("Quick sort", quick_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//選択ソート

	//アルゴリズム：選択ソート
	auto selection_sort = [](array_t* array) -> std::size_t
	{
		return selectionSort(*array, comparison_default);
	};
	const sum_t sum_selection = measureAll("Selection sort", selection_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：ヒープソート
	auto heap_sort = [](array_t* array) -> std::size_t
	{
		return heapSort(*array, comparison_default);
	};
	const sum_t sum_heap = measureAll("Heap sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//挿入ソート

	//アルゴリズム：挿入ソート
	auto insertion_sort = [](array_t* array) -> std::size_t
	{
		return insertionSort(*array, comparison_default);
	};
	const sum_t sum_insertion = measureAll("Insertion sort", insertion_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェルソート
	auto shell_sort = [](array_t* array) -> std::size_t
	{
		return shellSort(*array, comparison_default);
	};
	const sum_t sum_shell = measureAll("Shell sort", shell_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//マージソート

	//アルゴリズム：インプレースマージソート
	auto inplace_merge_sort = [](array_t* array) -> std::size_t
	{
		return inplaceMergeSort(*array, comparison_default);
	};
	const sum_t sum_inplace_merge = measureAll("Inplace Merge sort", inplace_merge_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//混成ソート

	//アルゴリズム：イントロソート
	auto intro_sort = [](array_t* array) -> std::size_t
	{
		return introSort(*array, comparison_default);
	};
	const sum_t sum_intro = measureAll("Intro sort", intro_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//測定終了

	//結果を表示
	auto printLine = [](const char* name, const sum_t& sum)
	{
		printf("- %-23s %12.9llf/%12.9llf/%12.9llf/%12.9llf",
			name,
			sum.elapsed_time_sum,
			sum.elapsed_time_avg,
			sum.elapsed_time_min,
			sum.elapsed_time_max);
		if (sum.swapped_count_sum != 0xffffffff)
		{
			printf("%10u/%10u/%10u/%10u",
				sum.swapped_count_sum,
				sum.swapped_count_avg,
				sum.swapped_count_min,
				sum.swapped_count_max);
		}
		printf("\n");
	};
	printf("============================================================\n");
	printf("Result(Summary)\n");
	printf("============================================================\n");
	printf("Array Element size = %d Bytes\n", sizeof(data_t));
	printf("Array Element(s)   = %d Count(s)\n", array_shuffle1->size());
	printf("Total Array size   = %d Bytes\n", sizeof(*array_shuffle1));
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("- (Sort Name):          Elapsed Time (Sum/Average/Min/Max) sec.             Swapped (Sum/Average/Min/Max) count(s)\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("[C-Library sort](Quick sort)\n");
	printLine("qsort(inline-function):", sum_clib_qsort);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("[STL sort](Intro sort)\n");
	printLine("std::sort(function):", sum_stl1);
	printLine("std::sort(inline-func):", sum_stl2);
	printLine("std::sort(functor):", sum_stl3);
	printLine("std::sort(lambda):", sum_stl4);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Exchange sorts]\n");
	printLine("Bubble sort<S>:", sum_bubble);
	printLine("Shaker sort<S>:", sum_shaker);
	printLine("Odd-Even sort<S>:", sum_odd_even);
	printLine("Shear sort:", sum_shear);
	printLine("Comb sort:", sum_comb);
	printLine("Gnome sort<S>:", sum_gnome);
	printLine("Quick sort:", sum_quick);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Selection sorts]\n");
	printLine("Selection sort:", sum_selection);
	printLine("Heap sort:", sum_heap);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Insertion sorts]\n");
	printLine("Insertion sort<S>:", sum_insertion);
	printLine("Shell sort:", sum_shell);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Merge sorts]\n");
	printLine("Inplace-Merge sort<S>:", sum_inplace_merge);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Hybrid sorts]\n");
	printLine("Intro sort:", sum_intro);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("* <S> ... Stable sort algorithm.\n");
	printf("\n");

	//----------------------------------------
	//測定終了
	printf("============================================================\n");
	printf("Finalize\n");
	printf("============================================================\n");
	deleteArraySet();
	printf("\n");
	printf("\n");
	printf("============================================================\n");
	printf("End\n");
	printf("============================================================\n");
	printElapsedTime(begin_time, true);//処理時間表示

	return EXIT_SUCCESS;
}

// End of file
