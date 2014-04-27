#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>//qsort�֐��p
#include <stdint.h>//intptr_t�p
#include <cstddef>//std::size_t�p
#include <functional>//C++11 std::function�p
//#include <crtdefs.h>//ptrdiff_t�p

//--------------------------------------------------------------------------------
//�\�[�g�A���S���Y��

//========================================
//�\�[�g�⏕����
//========================================

//----------------------------------------
//�������ʉ��p�}�N��
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
//�����Ԋm�F
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
//�\�[�g�A���S���Y���̐���
//========================================

//�E�v�Z���ԁF
//    - O(n)       ... �f�[�^�������̎���
//    - O(n ^ 2)   ... �f�[�^�����̂Q�敪�̎���
//    - O(log n)   ... log2(�f�[�^����)���̎��ԁi4��, 16��4, 1024��10,1048576��20�j
//    - O(n log n) ... n�~log n ���̎���
//�E�������g�p�ʁF
//    - O(1)       ... �P�����̃��������K�v
//    - O(n)       ... �f�[�^�������̃��������K�v
//    - O(log n)   ... log2(�f�[�^����)���̃��������K�v
//�E���萫�F
//    - ��         ... �L�[�������f�[�^�̏��������ێ�����邱�Ƃ�ۏ؂���
//                     ��F{ 3-a, 5-b, 4-c, 5-d, 9-e, 3-f, 4-g, 3-h, 5-i } �� { 3-a, 3-f, 3-h, 4-c, 4-g, 5-b, 5-d, 5-i, 9-e }
//    - �~         ... ��F(����)                                          �� { 3-a, 3-h, 3-f, 4-c, 4-g, 5-i, 5-d, 5-b, 9-e }

//========================================
//�\�[�g�A���S���Y�����ށF�����\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�o�u���\�[�g
//----------------------------------------
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
//----------------------------------------
//�����������L���̃`�F�b�N���s���A�œK������
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
//�A���S���Y���F�V�F�[�J�[�\�[�g
//----------------------------------------
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
//----------------------------------------
//�����������L���̃`�F�b�N���s���A�œK������
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
//�A���S���Y���F����]�u�\�[�g
//----------------------------------------
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
//----------------------------------------
//��OpenMP���g�p���A���񉻂ōœK������
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
//�A���S���Y���F�V�F�A�\�[�g
//----------------------------------------
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^1.5)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
//----------------------------------------
//��OpenMP���g�p���A���񉻂ōœK������
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
//�A���S���Y���F�R���\�[�g
//----------------------------------------
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
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
//�A���S���Y���F�m�[���\�[�g
//----------------------------------------
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
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
//�A���S���Y���F�V�F�[�J�[�m�[���\�[�g
//----------------------------------------
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
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
//�A���S���Y���F�N�C�b�N�\�[�g
//----------------------------------------
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(log n)
//�E���萫�F�@�@�@�~
//----------------------------------------
//���ċA�������g�p�����ɍœK���i�ő匏���� log2(4294967296) = 32 �Ƃ���j
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
//�\�[�g�A���S���Y�����ށF�I���\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�I���\�[�g
//----------------------------------------
//�E���όv�Z���ԁFO(n^2)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
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
//�A���S���Y���F�q�[�v�\�[�g
//----------------------------------------
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n log n)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
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
//�\�[�g�A���S���Y�����ށF�}���\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�}���\�[�g
//----------------------------------------
//�E���όv�Z���ԁFO(n + d) ��d = O(n^2
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
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
//�A���S���Y���F�V�F���\�[�g
//----------------------------------------
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n log^2 n)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
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
//�\�[�g�A���S���Y�����ށF�����\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�C���g���\�[�g
//----------------------------------------
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n log n)
//�E�������g�p�ʁFO(n log n)
//�E���萫�F�@�@�@�~
//----------------------------------------
//���N�C�b�N�\�[�g�̍ċA���x���� log n �ɒB������A
//�@�q�[�v�\�[�g�ɐ؂�ւ���B
//�@�܂��A�ċN�̖��A�\�[�g�̑Ώی�������萔�i32�Ȃǁj������
//�@�Ȃ�����A�}���\�[�g�ɐ؂�ւ���B
//��STL��std::sort()�Ɠ��l�̎�@�B
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
//�A���S���Y���F���O�`�F�b�N�\�[�g
//----------------------------------------
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n log n)
//�E�������g�p�ʁFO(n log n)
//�E���萫�F�@�@�@��
//----------------------------------------
//������\�[�g�݂̂��g�p���A��������ǋ�
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
//�e�X�g

#include <memory.h>//_aligned_malloc,memalign�p
#include <algorithm>//std::sort, std::for_each�p
#include <array>//C++11 std::array�p
#include <random>//C++11 random�p
#include <chrono>//C++11 std::chrono�p

#include "sub.h"

//----------------------------------------
//�e�X�g�p�\���̂̔z��^
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
//�e�X�g�p�̔�r����
//qsort�p�֐�
int comparison_func_qsort(const void*lhs, const void*rhs)
{
	return reinterpret_cast<const data_t*>(lhs)->m_key - reinterpret_cast<const data_t*>(rhs)->m_key;
}
//�ʏ�֐�
extern bool comparison_func(const data_t& lhs, const data_t& rhs);
//�C�����C���֐�
inline bool comparison_func_inline(const data_t& lhs, const data_t& rhs)
{
	return lhs.m_key < rhs.m_key;
}
//�֐��I�u�W�F�N�g
struct comparison_functor{
	inline bool operator()(const data_t& lhs, const data_t& rhs)
	{
		return lhs.m_key < rhs.m_key;
	}
};
//�����_�֐�
auto comparison_lambda = [](const data_t& lhs, const data_t& rhs) -> bool
{
	return lhs.m_key < rhs.m_key;
};
//�f�t�H���g
//#define comparison_default comparison_func
//#define comparison_default comparison_func_inline
//#define comparison_default comparison_functor()
#define comparison_default comparison_lambda

//----------------------------------------
//���C��
int main(const int argc, const char* argv[])
{

	//���Ԍv��
	auto begin_time = std::chrono::system_clock::now();
	auto prev_time = begin_time;

	//�������Ԍv��
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

	//�������ԕ\��
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

	//�z�񏉊���
	enum init_type_t
	{
		init_shuffle1 = 0,//�V���b�t���p�^�[��1
		init_shuffle2,//�V���b�t���p�^�[��2
		init_shuffle3,//�V���b�t���p�^�[��3
		init_ordered,//����ς݃p�^�[��
		init_reversed,//�t������ς݃p�^�[��
		init_ordered_without_both_ends,//����ς݃p�^�[���i�������A�n�[�ƏI�[�̂ݓ���ւ��j
		init_pattern_num//�������p�^�[����
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

	//�z��폜
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

	//�z���ԕ\��
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

	//�\�[�g
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
	
	//�v��
	auto measure = [&](const init_type_t type, const char* type_name, sort_procedure sort_proc) -> double
	{
		printf("\n");
		printf("------------------------------\n");
		printf("Measure type: %s\n", type_name);
		printf("------------------------------\n");
		array_t* array = nullptr;//�z��
		copyWorkArray(array, type, type_name);//�z�񏉊���
		showArrayCondition(array);//�z���ԕ\��
		double elapsed_time = sort(array, sort_proc);//�\�[�g
		showArrayCondition(array);//�z���ԕ\��
		deleteWorkArray(array, type_name);//�z��폜
		return elapsed_time;
	};

	//���Ϗ������ԕ\��
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

	//�܂Ƃ߂Čv��
	auto measureAll = [&](const char* sort_type_name, sort_procedure sort_proc) -> double
	{
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("============================================================\n");

		double sorting_time = 0.;//�\�[�g��������
		
		#define PARAM(x) init_##x, #x

		//�V���b�t���p�^�[���P
		sorting_time += measure(PARAM(shuffle1), sort_proc);

		//�V���b�t���p�^�[���Q
		sorting_time += measure(PARAM(shuffle2), sort_proc);

		//�V���b�t���p�^�[���R
		sorting_time += measure(PARAM(shuffle3), sort_proc);

		//����ς݃p�^�[��
		sorting_time += measure(PARAM(ordered), sort_proc);

		//�t������ς݃p�^�[��
		sorting_time += measure(PARAM(reversed), sort_proc);

		//����ς݃p�^�[���i�������A�n�[�ƏI�[�̂ݓ���ւ��j
		sorting_time += measure(PARAM(ordered_without_both_ends), sort_proc);

		#undef PARAM

		return printAverageTime(sort_type_name, sorting_time, init_pattern_num);//���σ\�[�g�������ԕ\��
	};

	//----------------------------------------
	//����J�n
	printf("============================================================\n");
	printf("Initialize\n");
	printf("============================================================\n");
	makeArraySet();
	printf("\n");
	printf("\n");

	//----------------------------------------
	//�W�����C�u�����ɂ��\�[�g

	//--------------------
	//C���C�u�����Fqsort�֐�
	//�A���S���Y���F�N�C�b�N�\�[�g
	auto clib_qsort = [](array_t* array) -> std::size_t
	{
		qsort(&array->at(0), array->size(),sizeof(data_t), comparison_func_qsort);
		return 0xffffffff;
	};
	const double avg_clib_qsort = measureAll("C-Library qsort", clib_qsort);
	printf("\n");
	printf("\n");

	//--------------------
	//STL�\�[�g1�F�ʏ�֐��Ŕ�r
	//�A���S���Y���F�C���g���\�[�g�i�N�C�b�N�\�[�g�{�q�[�v�\�[�g�{�}���\�[�g�j
	auto stl_sort1 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_func);
		return 0xffffffff;
	};
	const double avg_stl1 = measureAll("STL std::sort(with function)", stl_sort1);
	printf("\n");
	printf("\n");

	//STL�\�[�g2�F�C�����C���֐��Ŕ�r
	//�A���S���Y���F�i����j
	auto stl_sort2 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_func_inline);
		return 0xffffffff;
	};
	const double avg_stl2 = measureAll("STL std::sort(with inline function)", stl_sort2);
	printf("\n");
	printf("\n");

	//STL�\�[�g3�F�֐��I�u�W�F�N�g�Ŕ�r
	//�A���S���Y���F�i����j
	auto stl_sort3 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_functor());
		return 0xffffffff;
	};
	const double avg_stl3 = measureAll("STL std::sort(with functor)", stl_sort3);
	printf("\n");
	printf("\n");

	//STL�\�[�g4�F�����_�֐��Ŕ�r
	//�A���S���Y���F�i����j
	auto stl_sort4 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), comparison_lambda);
		return 0xffffffff;
	};
	const double avg_stl4 = measureAll("STL std::sort(with lamda)", stl_sort4);
	printf("\n");
	printf("\n");
	
	//----------------------------------------
	//�����\�[�g

	//�A���S���Y���F�o�u���\�[�g
	auto bubble_sort = [](array_t* array) -> std::size_t
	{
		return bubbleSort(&array->at(0), array->size(), comparison_default);
	};
	const double avg_bubble = measureAll("Bubble sort", bubble_sort);
	printf("\n");
	printf("\n");
	
	//�A���S���Y���F�V�F�[�J�[�\�[�g
	auto shaker_sort = [](array_t* array) -> std::size_t
	{
		return shakerSort(*array, comparison_default);
	};
	const double avg_shaker = measureAll("Shaker sort", shaker_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F����]�u�\�[�g
	auto odd_even_sort = [](array_t* array) -> std::size_t
	{
		return oddEvenSort(*array, comparison_default);
	};
	const double avg_odd_even = measureAll("Odd-Even sort", odd_even_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�V�F�A�\�[�g
	auto share_sort = [](array_t* array) -> std::size_t
	{
		return shareSort(*array, comparison_default);
	};
	const double avg_share = measureAll("Share sort", share_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�R���\�[�g
	auto comb_sort = [](array_t* array) -> std::size_t
	{
		return combSort(*array, comparison_default);
	};
	const double avg_comb = measureAll("Comb sort", comb_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�m�[���\�[�g
	auto gnome_sort = [](array_t* array) -> std::size_t
	{
		return gnomeSort(*array, comparison_default);
	};
	const double avg_gnome = measureAll("Gnome sort", gnome_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�V�F�[�J�[�m�[���\�[�g
	auto shaker_gnome_sort = [](array_t* array) -> std::size_t
	{
		return shakerGnomeSort(*array, comparison_default);
	};
	const double avg_shaker_gnome = measureAll("Shaker Gnome sort", shaker_gnome_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�N�C�b�N�\�[�g
	auto quick_sort = [](array_t* array) -> std::size_t
	{
		return quickSort(*array, comparison_default);
	};
	const double avg_quick = measureAll("Quick sort", quick_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//�I���\�[�g

	//�A���S���Y���F�I���\�[�g
	auto selection_sort = [](array_t* array) -> std::size_t
	{
		return selectionSort(*array, comparison_default);
	};
	const double avg_selection = measureAll("Selection sort", selection_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�q�[�v�\�[�g
	auto heap_sort = [](array_t* array) -> std::size_t
	{
		return heapSort(*array, comparison_default);
	};
	const double avg_heap = measureAll("Heap sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//�}���\�[�g

	//�A���S���Y���F�}���\�[�g
	auto insertion_sort = [](array_t* array) -> std::size_t
	{
		return insertionSort(*array, comparison_default);
	};
	const double avg_insertion = measureAll("Insertion sort", insertion_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�V�F���\�[�g
	auto shell_sort = [](array_t* array) -> std::size_t
	{
		return shellSort(*array, comparison_default);
	};
	const double avg_shell = measureAll("Shell sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//�����\�[�g

	//�A���S���Y���F�C���g���\�[�g
	auto intro_sort = [](array_t* array) -> std::size_t
	{
		return introSort(*array, comparison_default);
	};
	const double avg_intro = measureAll("Intro sort", heap_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F���O�`�F�b�N�\�[�g
	auto pre_check_sort = [](array_t* array) -> std::size_t
	{
		return preCheckSort(*array, comparison_default);
	};
	const double avg_pre_check = measureAll("Pre-Check sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//����I��
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
	printElapsedTime(begin_time, true);//�������ԕ\��

	return EXIT_SUCCESS;
}

// End of file
