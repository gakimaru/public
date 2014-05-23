#pragma once
#ifndef __SUB_H_
#define __SUB_H_

//--------------------------------------------------------------------------------
//�R���p�C���X�C�b�`

//#define USE_GCC//GCC���g�p����ꍇ�A���̃}�N����L��������

//#define STRLEN_FAST_IS_NOT_FAST//strlen_fast�̎��̂�W�����C�u�����̊֐��ɂ���ꍇ�́A���̃}�N����L��������
//#define STRCMP_FAST_IS_NOT_FAST//strcmp_fast�̎��̂�W�����C�u�����̊֐��ɂ���ꍇ�́A���̃}�N����L��������
//#define STRNCMP_FAST_IS_NOT_FAST//strncmp_fast�̎��̂�W�����C�u�����̊֐��ɂ���ꍇ�́A���̃}�N����L��������
//#define STRCHR_FAST_IS_NOT_FAST//strchr_fast�̎��̂�W�����C�u�����̊֐��ɂ���ꍇ�́A���̃}�N����L��������
//#define STRRCHR_FAST_IS_NOT_FAST//strrchr_fast�̎��̂�W�����C�u�����̊֐��ɂ���ꍇ�́A���̃}�N����L��������
//#define STRSTR_FAST_IS_NOT_FAST//strstr_fast�̎��̂�W�����C�u�����̊֐��ɂ���ꍇ�́A���̃}�N����L��������
//#define STRNCPY_PADDING_ZERO//strncpy_fast��{���̎d�l�i�]���0�Ŗ��߂�j�Ŏ�������ꍇ�́A���̃}�N����L��������
                              //�����������́A�Ō�Ƀ^�[�~�l�[�^����t�����邾���i�����j

#include <cstddef>//std::szie_t�p

#ifndef USE_GCC
#define alignas(n) __declspec(align(n))
#define constexpr//�_�~�[
#else//USE_GCC
#define alignas(n) __attribute__((aligned(n)))
#endif//USE_GCC

//--------------------------------------------------------------------------------
//�e�X�g�p�萔

#define _VALUE_RANGE (10 + 1)//�l�̕��@�����z�W�v���̃��[�v�����ɉe������
//#define _VALUE_RANGE (1000 + 1)//�l�̕��@���i����j

//#define _ELEMENT_SIZE 100//�z��v�f���@���W�v���̃��[�v�����ɉe������
#define _ELEMENT_SIZE 10000//�z��v�f���@���i����j

//----------------------------------------
//�œK���@�F�������A�N�Z�X�̗}���F�ꎞ�ϐ��̊��p

//�e�X�g�p�\����
struct dataOpt01_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value;
	};
	
	int sum;
	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt01(dataOpt01_t& data);
//�y�^�C�v�P�z�œK���O
void testOpt01_Type1_Before(dataOpt01_t& data);
//�y�^�C�v�P�z�œK����P
void testOpt01_Type1_After1(dataOpt01_t& data);
//�y�^�C�v�P�z�œK����Q
void testOpt01_Type1_After2(dataOpt01_t& data);
//�y�^�C�v�P�z�y�Q�l�zC++11�ł����Ƃ��Ȍ��ȋL�q
void testOpt01_Type1_Appendix(dataOpt01_t& data);

//----------------------------------------
//�œK���A�F�������A�N�Z�X�̗}���F�A�h���X�v�Z�̍팸

//�e�X�g�p�\����
struct dataOpt02_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value;
	};
	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt02(dataOpt02_t& data);
//�y�^�C�v�P�z�œK���O
int testOpt02_Type1_Before(dataOpt02_t& data);
//�y�^�C�v�P�z�œK����P
int testOpt02_Type1_After1(dataOpt02_t& data);
//�y�^�C�v�P�z�œK����Q
int testOpt02_Type1_After2(dataOpt02_t& data);

//----------------------------------------
//�œK���B�F�������A�N�Z�X�̗}���F�֐��Ăяo���̍팸

//�e�X�g�p�\����
struct dataOpt03_t
{
	static const std::size_t VALUE_RANGE = _VALUE_RANGE;
	int values[_ELEMENT_SIZE];
};

//�y�^�C�v�P�z�œK���O
int testOpt03_Type1_Before(int a, int b, int c);
//�y�^�C�v�P�z�œK����
inline int testOpt03_Type1_After(int a, int b, int c)
{
	return a * b + c;
}

//�y�^�C�v�Q�z�œK���O
int testOpt03_Type2_Before(int a, int b, int c, int d, int e, int f, int g, int h);
//�y�^�C�v�Q�z�œK����
inline int testOpt03_Type2_After(int a, int b, int c, int d, int e, int f, int g, int h)
{
	return a * b + c - d * e + f - g * h;
}

//�y�^�C�v�R�z������
void initOpt03_Type3(dataOpt03_t& data);
//�y�^�C�v�R�z�œK���O
int testOpt03_Type3_Before(dataOpt03_t& data);
//�y�^�C�v�R�z�œK����
int testOpt03_Type3_After(dataOpt03_t& data);

//----------------------------------------
//�œK���C�F���Z�̗}���F��Z�ɕύX

//�e�X�g�p�\����
struct dataOpt04_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value;
		float ratio;
	};
	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt04(dataOpt04_t& data);

//�y�^�C�v�P�z�œK���O
void testOpt04_Type1_Before(dataOpt04_t& data);
//�y�^�C�v�P�z�œK����P
void testOpt04_Type1_After1(dataOpt04_t& data);
//�y�^�C�v�P�z�œK����Q
void testOpt04_Type1_After2(dataOpt04_t& data);

//----------------------------------------
//�œK���D�F��Z�^���Z�̗}���F�V�t�g���Z������Z�ɕύX

//�y�^�C�v�P�z�œK���O
int testOpt05_Type1_Before(const int val,
                           int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						   int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						   int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24);
//�y�^�C�v�P�z�œK����
int testOpt05_Type1_After(const int val,
                          int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						  int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						  int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24);

//----------------------------------------
//�œK���E�F��Z�^���Z�̗}���F���Z�̋��ʉ�

//�e�X�g�p�\����
struct dataOpt06_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		float value;
		float result;
	};
	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt06(dataOpt06_t& data);

//�y�^�C�v�P�z�œK���O
void testOpt06_Type1_Before(dataOpt06_t& data, const float mul1, const float mul2, const float div);
//�y�^�C�v�P�z�œK����P
void testOpt06_Type1_After(dataOpt06_t& data, const float mul1, const float mul2, const float div);

//----------------------------------------
//�œK���F�FSIMD���Z�����p����

template<std::size_t N, std::size_t M>
struct matrix
{
	float value[N][M];
	inline float& operator()(const std::size_t row, const std::size_t col){ return value[row][col]; }
	inline const float& operator()(const std::size_t row, const std::size_t col) const { return value[row][col]; }
};
template<>
struct matrix<4, 4>
{
	float alignas(16) value[4][4];
	inline float& operator()(const std::size_t row, const std::size_t col){ return value[row][col]; }
	inline const float& operator()(const std::size_t row, const std::size_t col) const { return value[row][col]; }
};
using matrix4x4 = matrix<4, 4>;
using matrix1x4 = matrix<1, 4>;
using matrix1x3 = matrix<1, 3>;
using matrix3x4 = matrix<3, 4>;

//�y�^�C�v�P�z�œK���O
template<std::size_t N, std::size_t M, std::size_t NM>
void testOpt07_Type1_Before(const int dummy, matrix<N, M>& add0, matrix<N, M>& mul0a, matrix<N, M>& mul0b, const matrix<N, M>& add1, const matrix<N, M>& add2, const matrix<N, M>& mul1a, const float mul2a, const matrix<N, NM>& mul1b, const matrix<NM, M>& mul2b);
//�y�^�C�v�P�z�œK����
template<std::size_t N, std::size_t M, std::size_t NM>
void testOpt07_Type1_After(const int dummy, matrix<N, M>& add0, matrix<N, M>& mul0a, matrix<N, M>& mul0b, const matrix<N, M>& add1, const matrix<N, M>& add2, const matrix<N, M>& mul1a, const float mul2a, const matrix<N, NM>& mul1b, const matrix<NM, M>& mul2b);

//�y�^�C�v�Q�z�œK���O
std::size_t testOpt07_Type2_strlen_Before(const int dummy, const char* str);
int testOpt07_Type2_strcmp_Before(const int dummy, const char* str1, const char* str2);
int testOpt07_Type2_strncmp_Before(const int dummy, const char* str1, const char* str2, const std::size_t max_len);
const char* testOpt07_Type2_strchr_Before(const int dummy, const char* str, const char c);
const char* testOpt07_Type2_strrchr_Before(const int dummy, const char* str, const char c);
const char* testOpt07_Type2_strstr_Before(const int dummy, const char* str1, const char* str2);
const char* testOpt07_Type2_strcpy_Before(const int dummy, char* dst, const char* src);
const char* testOpt07_Type2_strncpy_Before(const int dummy, char* dst, const char* src, const std::size_t max_len);
//�y�^�C�v�Q�z�œK����
inline std::size_t strlen_fast(const char* str)
{
#ifdef STRLEN_FAST_IS_NOT_FAST
	return strlen(str);
#else//STRLEN_FAST_IS_NOT_FAST
	extern std::size_t _strlen_fast(const char* str);
	return _strlen_fast(str);
#endif//STRLEN_FAST_IS_NOT_FAST
}
inline std::size_t strnlen_fast(const char* str, const std::size_t max_len)
{
	extern std::size_t _strnlen_fast(const char* str, const std::size_t max_len);
	return _strnlen_fast(str, max_len);
}
inline int strcmp_fast(const char* str1, const char* str2)
{
#ifdef STRCMP_FAST_IS_NOT_FAST
	return strcmp(str1, str2);
#else//STRCMP_FAST_IS_NOT_FAST
	extern int _strcmp_fast(const char* str1, const char* str2);
	return _strcmp_fast(str1, str2);
#endif//STRCMP_FAST_IS_NOT_FAST
}
inline int strncmp_fast(const char* str1, const char* str2, const std::size_t max_len)
{
#ifdef STRNCMP_FAST_IS_NOT_FAST
	return strncmp(str1, str2, max_len);
#else//STRNCMP_FAST_IS_NOT_FAST
	extern int _strncmp_fast(const char* str1, const char* str2, const std::size_t max_len);
	return _strncmp_fast(str1, str2, max_len);
#endif//STRNCMP_FAST_IS_NOT_FAST
}
inline const char* strchr_fast(const char* str, const char c)
{
#ifdef STRCHR_FAST_IS_NOT_FAST
	return strchr(str, c);
#else//STRCHR_FAST_IS_NOT_FAST
	extern const char* _strchr_fast(const char* str, const char c);
	return _strchr_fast(str, c);
#endif//STRCHR_FAST_IS_NOT_FAST
}
inline const char* strrchr_fast(const char* str, const char c)
{
#ifdef STRRCHR_FAST_IS_NOT_FAST
	return strrchr(str, c);
#else//STRRCHR_FAST_IS_NOT_FAST
	const char* _strrchr_fast(const char* str, const char c);
	return _strrchr_fast(str, c);
#endif//STRRCHR_FAST_IS_NOT_FAST
}
inline const char* strstr_fast(const char* str, const char* pattern)
{
#ifdef STRSTR_FAST_IS_NOT_FAST
	return strstr(str, pattern);
#else//STRSTR_FAST_IS_NOT_FAST
	extern const char* _strstr_fast(const char* str, const char* pattern);
	return _strstr_fast(str, pattern);
#endif//STRSTR_FAST_IS_NOT_FAST
}
inline const char* strstrbm_fast(const char* str, const char* pattern)
{
	extern const char* _strstrbm_fast(const char* str, const char* pattern);
	return _strstrbm_fast(str, pattern);
}
inline const char* strstr0_fast(const char* str, const char* pattern)
{
	extern const char* _strstr0_fast(const char* str, const char* pattern);
	return _strstr0_fast(str, pattern);
}
inline const char* strcpy_fast(char* dst, const char* src)
{
#ifdef STRCPY_FAST_IS_NOT_FAST
	return strcpy(dst, src);
#else//STRCPY_FAST_IS_NOT_FAST
	extern const char* _strcpy_fast(char* dst, const char* src);
	return _strcpy_fast(dst, src);
#endif//STRCPY_FAST_IS_NOT_FAST
}
inline const char* strncpy_fast(char* dst, const char* src, const std::size_t max_len)
{
#ifdef STRNCPY_FAST_IS_NOT_FAST
	return strncpy(dst, src, max_len);
#else//STRNCPY_FAST_IS_NOT_FAST
	extern const char* _strncpy_fast(char* dst, const char* src, const std::size_t max_len);
	return _strncpy_fast(dst, src, max_len);
#endif//STRNCPY_FAST_IS_NOT_FAST
}
void testOpt07_Type2_After_1time();
std::size_t testOpt07_Type2_strlen_After(const int dummy, const char* str);
int testOpt07_Type2_strcmp_After(const int dummy, const char* str1, const char* str2);
int testOpt07_Type2_strncmp_After(const int dummy, const char* str1, const char* str2, const std::size_t max_len);
const char* testOpt07_Type2_strchr_After(const int dummy, const char* str, const char c);
const char* testOpt07_Type2_strrchr_After(const int dummy, const char* str, const char c);
const char* testOpt07_Type2_strstr_After1(const int dummy, const char* str1, const char* str2);
const char* testOpt07_Type2_strstr_After2(const int dummy, const char* str1, const char* str2);
const char* testOpt07_Type2_strcpy_After(const int dummy, char* dst, const char* src);
const char* testOpt07_Type2_strncpy_After(const int dummy, char* dst, const char* src, const std::size_t max_len);

//----------------------------------------
//���ʊ֐�

//�z����擾
template<typename T> inline std::size_t rankof(const T& data){ return 0; }
template<typename T> inline std::size_t esizeof(const T& data){ return sizeof(T); }
template<typename T> inline std::size_t extentof(const T& data){ return 0; }
template<typename T> inline std::size_t extent1of(const T& data){ return 0; }
template<typename T> inline std::size_t extent2of(const T& data){ return 0; }
template<typename T> inline std::size_t extent3of(const T& data){ return 0; }
template<typename T> inline std::size_t extent4of(const T& data){ return 0; }

template<typename T, std::size_t N1> inline std::size_t rankof(const T(&data)[N1]){ return 1; }
template<typename T, std::size_t N1> inline std::size_t esizeof(const T(&data)[N1]){ return sizeof(T); }
template<typename T, std::size_t N1> inline std::size_t extentof(const T(&data)[N1]){ return N1; }
template<typename T, std::size_t N1> inline std::size_t extent1of(const T(&data)[N1]){ return N1; }
template<typename T, std::size_t N1> inline std::size_t extent2of(const T(&data)[N1]){ return 0; }
template<typename T, std::size_t N1> inline std::size_t extent3of(const T(&data)[N1]){ return 0; }
template<typename T, std::size_t N1> inline std::size_t extent4of(const T(&data)[N1]){ return 0; }

template<typename T, std::size_t N1, std::size_t N2> inline std::size_t rankof(const T(&data)[N1][N2]){ return 2; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t esizeof(const T(&data)[N1][N2]){ return sizeof(T); }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extentof(const T(&data)[N1][N2]){ return N1 * N2; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent1of(const T(&data)[N1][N2]){ return N1; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent2of(const T(&data)[N1][N2]){ return N2; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent3of(const T(&data)[N1][N2]){ return 0; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent4of(const T(&data)[N1][N2]){ return 0; }

template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t rankof(const T(&data)[N1][N2][N3]){ return 3; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t esizeof(const T(&data)[N1][N2][N3]){ return sizeof(T); }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extentof(const T(&data)[N1][N2][N3]){ return N1 * N2 * N3; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent1of(const T(&data)[N1][N2][N3]){ return N1; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent2of(const T(&data)[N1][N2][N3]){ return N2; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent3of(const T(&data)[N1][N2][N3]){ return N3; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent4of(const T(&data)[N1][N2][N3]){ return 0; }

template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t rankof(const T(&data)[N1][N2][N3][N4]){ return 4; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t esizeof(const T(&data)[N1][N2][N3][N4]){ return sizeof(T); }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extentof(const T(&data)[N1][N2][N3][N4]){ return N1 * N2 * N3 * N4; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent1of(const T(&data)[N1][N2][N3][N4]){ return N1; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent2of(const T(&data)[N1][N2][N3][N4]){ return N2; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent3of(const T(&data)[N1][N2][N3][N4]){ return N3; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent4of(const T(&data)[N1][N2][N3][N4]){ return N4; }

#endif//__SUB_H_

// End of file
