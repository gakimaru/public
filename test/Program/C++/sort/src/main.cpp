//static const int TEST_DATA_COUNT = 1000000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 100000;//�e�X�g�f�[�^�����i�ő�j
static const int TEST_DATA_COUNT = 100;//�e�X�g�f�[�^�����i�ő�j

#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>//qsort�֐��p
#include <crtdefs.h>//ptrdiff_t�p
#include <functional>//C++11 std::function�p
#include <type_traits>//C++11 std::function�p

//--------------------------------------------------------------------------------
//�\�[�g�A���S���Y��

//========================================
//�\�[�g�⏕����
//========================================

//----------------------------------------
//�����Ԋm�F
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
//�\�[�g�A���S���Y������
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
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
//�����������L���̃`�F�b�N���s���A�œK������
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
//�A���S���Y���F�V�F�[�J�[�\�[�g
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
//�����������L���̃`�F�b�N���s���A�œK������
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
//�A���S���Y���F����]�u�\�[�g
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
//��OpenMP���g�p���A���񉻂ōœK������
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
//�A���S���Y���F�R���\�[�g
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
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
//�A���S���Y���F�m�[���\�[�g
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
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
//�A���S���Y���F�V�F�[�J�[�m�[���\�[�g
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
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
//�A���S���Y���F�N�C�b�N�\�[�g
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(log n)
//�E���萫�F�@�@�@�~
//���ċA�������g�p�����ɍœK���i�ő匏���� log2(4294967296) = 32 �Ƃ���j
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
//�\�[�g�A���S���Y�����ށF�I���\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�I���\�[�g
//�E���όv�Z���ԁFO(n^2)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
//�����������L���̃`�F�b�N���s���A�œK������
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
//�A���S���Y���F�V�F�[�J�[�I���\�[�g
//�E���όv�Z���ԁFO(n^2)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
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
//�A���S���Y���F�q�[�v�\�[�g
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n log n)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
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
//�\�[�g�A���S���Y�����ށF�}���\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�}���\�[�g
//�E���όv�Z���ԁFO(n + d) ��d = O(n^2
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
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
//�A���S���Y���F�V�F���\�[�g
//�E���όv�Z���ԁF-
//�E�ň��v�Z���ԁFO(n log^2 n)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
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
//�\�[�g�A���S���Y�����ށF�����\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�C���g���\�[�g
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n log n)
//�E�������g�p�ʁFO(n log n)
//�E���萫�F�@�@�@�~
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
//�A���S���Y���F���O�`�F�b�N�\�[�g
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n log n)
//�E�������g�p�ʁFO(n log n)
//�E���萫�F�@�@�@��
//������\�[�g�݂̂��g�p���A��������ǋ�
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
//�e�X�g

#include <algorithm>//std::sort, std::for_each�p
#include <array>//C++11 std::array�p
#include <random>//C++11 random�p
#include <chrono>//C++11 std::chrono�p

#include "sub.h"

//----------------------------------------
//�e�X�g�p�\���̂̔z��^
typedef std::array<data_t, TEST_DATA_COUNT> array_t;

//----------------------------------------
//�e�X�g�p�̔�r����
//qsort�p�֐�
int compare_func_qsort(const void*lhs, const void*rhs)
{
	return reinterpret_cast<const data_t*>(lhs)->m_key - reinterpret_cast<const data_t*>(rhs)->m_key;
}
//�ʏ�֐�
extern bool compare_func(const data_t& lhs, const data_t& rhs);
//�C�����C���֐�
inline bool compare_func_inline(const data_t& lhs, const data_t& rhs)
{
	return lhs.m_key < rhs.m_key;
}
//�֐��I�u�W�F�N�g
struct compare_functor{
	inline bool operator()(const data_t& lhs, const data_t& rhs)
	{
		return lhs.m_key < rhs.m_key;
	}
};
//�����_�֐�
auto compare_lambda = [](const data_t& lhs, const data_t& rhs) -> bool
{
	return lhs.m_key < rhs.m_key;
};

//----------------------------------------
//���C��
int main(const int argc, const char* argv[])
{
	//���Ԍv��
	auto begin_time = std::chrono::system_clock::now();
	auto prev_time = begin_time;

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

	//�z���ԕ\��
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

	//�\�[�g
	typedef std::function<void(array_t*)> sort_procedure;
	auto sort = [](array_t*& array, sort_procedure sort_proc)
	{
		printf("----- Sort -----\n");
		sort_proc(array);
	};

	//�z��폜
	auto termArray = [](array_t*& array)
	{
		printf("----- Delete array -----\n");
		delete array;
		array = nullptr;
	};
	
	//�v��
	auto measure = [&](const init_type_t type, const char* type_name, sort_procedure sort_proc) -> double
	{
		printf("\n");
		printf("------------------------------\n");
		printf("Measure type: %s\n", type_name);
		printf("------------------------------\n");
		array_t* array = nullptr;//�z��
		makeArray(array, type, type_name);//�z�񏉊���
		showArrayCondition(array);//�z���ԕ\��
		prev_time = printElapsedTime(prev_time);//�������ԕ\��
		sort(array, sort_proc);//�\�[�g
		const double elapsed_time = getElapsedTime(prev_time);//�\�[�g�̏������Ԃ��v��
		showArrayCondition(array);//�z���ԕ\��
		prev_time = printElapsedTimeDirect(elapsed_time);//�������ԕ\��
		termArray(array);//�z��폜
		prev_time = printElapsedTime(prev_time);//�������ԕ\��
		return elapsed_time;
	};

	//���Ϗ������ԕ\��
	auto printAverageTime = [](const char* sort_type_name, const double sorting_time, const int measure_count)
	{
		const auto average_time = sorting_time / static_cast<double>(measure_count);
		printf("\n");
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("*** sorting time=%.9llf sec ---> average time=%.9llf sec\n", sorting_time, average_time);
		printf("============================================================\n");
	};

	//�܂Ƃ߂Čv��
	auto measureAll = [&](const char* sort_type_name, sort_procedure sort_proc)
	{
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("============================================================\n");

		#define pair(x) init_##x, #x

		double sorting_time = 0.;//�\�[�g��������
		
		//�V���b�t���p�^�[���P
		sorting_time += measure(pair(shuffle1), sort_proc);

		//�V���b�t���p�^�[���Q
		sorting_time += measure(pair(shuffle2), sort_proc);

		//�V���b�t���p�^�[���R
		sorting_time += measure(pair(shuffle3), sort_proc);

		//����ς݃p�^�[��
		sorting_time += measure(pair(ordered), sort_proc);

		//�t������ς݃p�^�[��
		sorting_time += measure(pair(reversed), sort_proc);

		//����ς݃p�^�[���i�������A�n�[�ƏI�[�̂ݓ���ւ��j
		sorting_time += measure(pair(ordered_without_both_ends), sort_proc);
		
		printAverageTime(sort_type_name, sorting_time, init_pattern_num);//���σ\�[�g�������ԕ\��
		
		#undef pair
	};

	//----------------------------------------
	//�W�����C�u�����ɂ��\�[�g

	//C���C�u�����Fqsort�֐�
	//�A���S���Y���F�N�C�b�N�\�[�g
	auto clib_qsort = [](array_t* array)
	{
		qsort(&array->at(0), array->size(),sizeof(data_t), compare_func_qsort);
	};
	measureAll("C-Lib qsort", clib_qsort);
	printf("\n");
	printf("\n");

	//STL�\�[�g1�F�ʏ�֐��Ŕ�r
	//�A���S���Y���F�C���g���\�[�g�i�N�C�b�N�\�[�g�{�q�[�v�\�[�g�{�}���\�[�g�j
	auto stl_sort1 = [](array_t* array)
	{
		std::sort(array->begin(), array->end(), compare_func);
	};
	measureAll("STL sort(with function)", stl_sort1);
	printf("\n");
	printf("\n");

	//STL�\�[�g2�F�C�����C���֐��Ŕ�r
	//�A���S���Y���F�i����j
	auto stl_sort2 = [](array_t* array)
	{
		std::sort(array->begin(), array->end(), compare_func_inline);
	};
	measureAll("STL sort(with inline function)", stl_sort2);
	printf("\n");
	printf("\n");

	//STL�\�[�g3�F�֐��I�u�W�F�N�g�Ŕ�r
	//�A���S���Y���F�i����j
	auto stl_sort3 = [](array_t* array)
	{
		std::sort(array->begin(), array->end(), compare_functor());
	};
	measureAll("STL sort(with functor)", stl_sort3);
	printf("\n");
	printf("\n");

	//STL�\�[�g4�F�����_�֐��Ŕ�r
	//�A���S���Y���F�i����j
	auto stl_sort4 = [](array_t* array)
	{
		std::sort(array->begin(), array->end(), compare_lambda);
	};
	measureAll("STL sort(with lamda)", stl_sort4);
	printf("\n");
	printf("\n");
	
	//----------------------------------------
	//�����\�[�g

	//�A���S���Y���F�o�u���\�[�g
	auto bubble_sort = [](array_t* array)
	{
		bubbleSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Bubble sort", bubble_sort);
	printf("\n");
	printf("\n");
	
	//�A���S���Y���F�V�F�[�J�[�\�[�g
	auto shaker_sort = [](array_t* array)
	{
		shakerSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Shaker sort", shaker_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F����]�u�\�[�g
	auto odd_even_sort = [](array_t* array)
	{
		oddEvenSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Odd-Even sort", odd_even_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�R���\�[�g
	auto comb_sort = [](array_t* array)
	{
		combSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Comb sort", comb_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�m�[���\�[�g
	auto gnome_sort = [](array_t* array)
	{
		gnomeSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Gnome sort", gnome_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�V�F�[�J�[�m�[���\�[�g
	auto shaker_gnome_sort = [](array_t* array)
	{
		shakerGnomeSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Shaker Gnome sort", shaker_gnome_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�N�C�b�N�\�[�g
	auto quick_sort = [](array_t* array)
	{
		quickSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Quick sort", quick_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//�I���\�[�g

	//�A���S���Y���F�I���\�[�g
	auto selection_sort = [](array_t* array)
	{
		selectionSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Selection sort", selection_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�V�F�[�J�[�I���\�[�g
	auto shaker_selection_sort = [](array_t* array)
	{
		shakerSelectionSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Shaker Selection sort", shaker_selection_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�q�[�v�\�[�g
	auto heap_sort = [](array_t* array)
	{
		heapSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Heap sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//�}���\�[�g

	//�A���S���Y���F�}���\�[�g
	auto insertion_sort = [](array_t* array)
	{
		insertionSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Insertion sort", insertion_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F�V�F���\�[�g
	auto shell_sort = [](array_t* array)
	{
		shellSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Shell sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//�����\�[�g

	//�A���S���Y���F�C���g���\�[�g
	auto intro_sort = [](array_t* array)
	{
		introSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Intro sort", heap_sort);
	printf("\n");
	printf("\n");

	//�A���S���Y���F���O�`�F�b�N�\�[�g
	auto pre_check_sort = [](array_t* array)
	{
		preCheckSort(&array->at(0), array->size(), compare_functor());
	};
	measureAll("Pre-Check sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//�I��
	printf("- End -\n");
	printElapsedTime(begin_time);//�������ԕ\��

	return EXIT_SUCCESS;
}

// End of file
