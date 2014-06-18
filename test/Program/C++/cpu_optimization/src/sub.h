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
//�y�^�C�v�P�z�œK����R
void testOpt01_Type1_After3(dataOpt01_t& data);
//�y�^�C�v�P�z�œK����S
void testOpt01_Type1_After4(dataOpt01_t& data);
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
//�y�^�C�v�P�z�œK����R
int testOpt02_Type1_After3(dataOpt02_t& data);

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
//�y�^�C�v�R�z�œK����1
int testOpt03_Type3_After1(dataOpt03_t& data);
//�y�^�C�v�R�z�œK����2
int testOpt03_Type3_After2(dataOpt03_t& data);
//�y�^�C�v�R�z�œK����3
int testOpt03_Type3_After3(dataOpt03_t& data);
//�y�^�C�v�R�z�y�Q�l�zA-1
int testOpt03_Type3_AppendixA1(dataOpt03_t& data);
//�y�^�C�v�R�z�y�Q�l�zA-2
int testOpt03_Type3_AppendixA2(dataOpt03_t& data);
//�y�^�C�v�R�z�y�Q�l�zA-3
int testOpt03_Type3_AppendixA3(dataOpt03_t& data);
//�y�^�C�v�R�z�y�Q�l�zB-1
int testOpt03_Type3_AppendixB1(dataOpt03_t& data);
//�y�^�C�v�R�z�y�Q�l�zB-2
int testOpt03_Type3_AppendixB2(dataOpt03_t& data);
//�y�^�C�v�R�z�y�Q�l�zB-3
int testOpt03_Type3_AppendixB3(dataOpt03_t& data);

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

#if 0
//�y�^�C�v�P�z�œK���O
float testOpt04_Type1_Before(const float value);
//�y�^�C�v�P�z�œK����
float testOpt04_Type1_After(const float value);
#else
//�y�^�C�v�P�z�œK���O
//���萔�ɂ�鏜�Z
inline float testOpt04_Type1_Before(const float value)
{
	return value / 1.2f;
}

//�y�^�C�v�P�z�œK����
//���萔�ɂ�鏜�Z����Z�ɕύX
inline float testOpt04_Type1_After(const float value)
{
	return value * (1.f / 1.2f);
}
#endif

//�y�^�C�v�Q�z�œK���O
void testOpt04_Type2_Before(dataOpt04_t& data);
//�y�^�C�v�Q�z�œK����P
void testOpt04_Type2_After1(dataOpt04_t& data);
//�y�^�C�v�Q�z�œK����Q
void testOpt04_Type2_After2(dataOpt04_t& data);

#if 0
//�y�^�C�v�R�z�œK���O
float testOpt04_Type3_Before(const float value, const float div);
//�y�^�C�v�R�z�œK����
float testOpt04_Type3_After(const float value, const float div);
#else

#include <xmmintrin.h>//SSE1
//�y�^�C�v�R�z�œK���O
//���ϐ��ɂ�鏜�Z
inline float testOpt04_Type3_Before(const float value, const float div)
{
	//return value / div;
	//���Z
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _div_m128 = _mm_set1_ps(div);
	const __m128 _result_m128 = _mm_div_ss(_value_m128, _div_m128);
	//�v�Z���ʎ擾
	float result;
	_mm_store_ss(&result, _result_m128);
	return result;
}

//�y�^�C�v�R�z�œK����1
//���ϐ��ɂ�鏜�Z����Z�ɕύX
inline float testOpt04_Type3_After1(const float value, const float div)
{
	//const float rcp = 1.f / div;
	//return value * rcp;
	//�t���Z�o
	const __m128 _div_m128 = _mm_set1_ps(div);
	const __m128 _rcp_m128 = _mm_rcp_ss(_div_m128);
	//��Z
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _result_m128 = _mm_mul_ss(_value_m128, _rcp_m128);
	//�v�Z���ʎ擾
	float result;
	_mm_store_ss(&result, _result_m128);
	return result;
}

//�y�^�C�v�R�z�œK����2
//���ϐ��ɂ�鏜�Z����Z�ɕύX
//���j���[�g���@�ŋt���̐��x�����߂�
inline float testOpt04_Type3_After2(const float value, const float div)
{
	//const float rcp = 1.f / div;
	//return value * rcp;
	//�t���Z�o
	const __m128 _div_m128 = _mm_set1_ps(div);
	__m128 _rcp_m128 = _mm_rcp_ss(_div_m128);
	//�j���[�g���@�ŋt���̐��x�����߂�
	//�j���[�g���@�ɂ��Q�����Frcp = rcp * (2.f - div * rcp)
	//  rcp   = 1 / div
	//  f(x)  = div * x - 1
	//  f(x)  = 1 / x - div
	//  f'(x) = -(1 / x ^ 2)
	//  x[i+1] = x[i] - f(x[i]) / f'(x[i])
	//         = x[i] - (1 / x[i] - div) / -(1 / x[i] ^ 2)
	//         = x[i] + x[i] * (1 - div * x[i])
	//         = x[i] * (2 - div * x[i])
	const __m128 _2_m128 = _mm_set1_ps(2.f);
	_rcp_m128 = _mm_mul_ss(_rcp_m128, _mm_sub_ss(_2_m128, _mm_mul_ss(_div_m128, _rcp_m128)));
	//��Z
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _result_m128 = _mm_mul_ss(_value_m128, _rcp_m128);
	//�v�Z���ʎ擾
	float result;
	_mm_store_ss(&result, _result_m128);
	return result;
}

//�y�^�C�v�R�z�œK����3
//���ϐ��ɂ�鏜�Z����Z�ɕύX
//���j���[�g���@��2��J��Ԃ��A���t���̐��x�����߂�
inline float testOpt04_Type3_After3(const float value, const float div)
{
	//const float rcp = 1.f / div;
	//return value * rcp;
	//�t���Z�o
	const __m128 _div_m128 = _mm_set1_ps(div);
	__m128 _rcp_m128 = _mm_rcp_ss(_div_m128);
	//�j���[�g���@�ŋt���̐��x�����߂�
	const __m128 _2_m128 = _mm_set1_ps(2.f);
	_rcp_m128 = _mm_mul_ss(_rcp_m128, _mm_sub_ss(_2_m128, _mm_mul_ss(_div_m128, _rcp_m128)));
	_rcp_m128 = _mm_mul_ss(_rcp_m128, _mm_sub_ss(_2_m128, _mm_mul_ss(_div_m128, _rcp_m128)));
	//��Z
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _result_m128 = _mm_mul_ss(_value_m128, _rcp_m128);
	//�v�Z���ʎ擾
	float result;
	_mm_store_ss(&result, _result_m128);
	return result;
}
#endif

#if 0
//�y�^�C�v�S�z�œK���O
float testOpt04_Type4_Before(const float value);
//�y�^�C�v�S�z�œK����
float testOpt04_Type4_After(const float value);
#else
//�y�^�C�v�S�z�œK���O
//��������
#include <xmmintrin.h>//SSE1
inline float testOpt04_Type4_Before(const float value)
{
	//return sqrt(value);
	//�������Z�o
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _sqrt_m128 = _mm_sqrt_ss(_value_m128);
	//�v�Z���ʎ擾
	float sqrt;
	_mm_store_ss(&sqrt, _sqrt_m128);
	return sqrt;
}

//�y�^�C�v�S�z�œK����1
//���������̋t�����g�p����������
inline float testOpt04_Type4_After1(const float value)
{
	//const float rsqrt = rsqrt(value);
	//return value * rsqrt;
	//�������̋t���Z�o
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _rsqrt_m128 = _mm_rsqrt_ss(_value_m128);
	//��Z
	const __m128 _sqrt_m128 = _mm_mul_ss(_value_m128, _rsqrt_m128);
	//�v�Z���ʎ擾
	float sqrt;
	_mm_store_ss(&sqrt, _sqrt_m128);
	return sqrt;
}

//�y�^�C�v�S�z�œK����2
//���������̋t�����g�p����������
//���j���[�g���@�ŋt���̐��x�����߂�
inline float testOpt04_Type4_After2(const float value)
{
	//const float rsqrt = rsqrt(value);
	//return value * rsqrt;
	//�������̋t���Z�o
	const __m128 _value_m128 = _mm_set1_ps(value);
	__m128 _rsqrt_m128 = _mm_rsqrt_ss(_value_m128);
	//�j���[�g���@�ŋt���̐��x�����߂�
	//�j���[�g���@�ɂ��Q�����Frsqrt = rsqrt * (3 - value * rsqrt * rsqrt) * 0.5f
	//  �������̑Q����:      x[i+1] = (x[i] + value / x[i]) * 0.5
	//  �������̋t���̑Q����:x[i+1] = x[i] * (3 - value * x[i] ^ 2) * 0.5
	const __m128 _3_m128 = _mm_set1_ps(3.f);
	const __m128 _05_m128 = _mm_set1_ps(0.5f);
	_rsqrt_m128 = _mm_mul_ss(_mm_mul_ss(_rsqrt_m128, _mm_sub_ss(_3_m128, _mm_mul_ss(_value_m128, _mm_mul_ss(_rsqrt_m128, _rsqrt_m128)))), _05_m128);
	//��Z
	const __m128 _sqrt_m128 = _mm_mul_ss(_value_m128, _rsqrt_m128);
	//�v�Z���ʎ擾
	float sqrt;
	_mm_store_ss(&sqrt, _sqrt_m128);
	return sqrt;
}

//�y�^�C�v�S�z�œK����3
//���������̋t�����g�p����������
//���j���[�g���@��2��J��Ԃ��A���t���̐��x�����߂�
inline float testOpt04_Type4_After3(const float value)
{
	//const float rsqrt = rsqrt(value);
	//return value * rsqrt;
	//�������̋t���Z�o
	const __m128 _value_m128 = _mm_set1_ps(value);
	__m128 _rsqrt_m128 = _mm_rsqrt_ss(_value_m128);
	//�j���[�g���@�ŋt���̐��x�����߂�
	const __m128 _3_m128 = _mm_set1_ps(3.f);
	const __m128 _05_m128 = _mm_set1_ps(0.5f);
	_rsqrt_m128 = _mm_mul_ss(_mm_mul_ss(_rsqrt_m128, _mm_sub_ss(_3_m128, _mm_mul_ss(_value_m128, _mm_mul_ss(_rsqrt_m128, _rsqrt_m128)))), _05_m128);
	_rsqrt_m128 = _mm_mul_ss(_mm_mul_ss(_rsqrt_m128, _mm_sub_ss(_3_m128, _mm_mul_ss(_value_m128, _mm_mul_ss(_rsqrt_m128, _rsqrt_m128)))), _05_m128);
	//��Z
	const __m128 _sqrt_m128 = _mm_mul_ss(_value_m128, _rsqrt_m128);
	//�v�Z���ʎ擾
	float sqrt;
	_mm_store_ss(&sqrt, _sqrt_m128);
	return sqrt;
}
#endif

//----------------------------------------
//�œK���D�F��Z�^���Z�̗}���F�V�t�g���Z������Z�ɕύX

//�y�^�C�v�P�z�œK���O
int testOpt05_Type1_Before(int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						   int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						   int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24);
//�y�^�C�v�P�z�œK����
int testOpt05_Type1_After(int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						  int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						  int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24);

//----------------------------------------
//�œK���E�F��Z�^���Z�̗}���F�v�Z���ʂ̋��ʗ��p

//�e�X�g�p�\����
struct dataOpt06_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		float value_a;
		float value_b;
		float value_c;
	};
	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt06(dataOpt06_t& data);

//�y�^�C�v�P�z�œK���O
float testOpt06_Type1_Before(dataOpt06_t& data, const float mul1, const float mul2, const float div);
//�y�^�C�v�P�z�œK����P
float testOpt06_Type1_After(dataOpt06_t& data, const float mul1, const float mul2, const float div);

//----------------------------------------
//�œK���F�FSIMD���Z�̊��p

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
//�œK���G�F��������̍팸

//�y�^�C�v�P�z�œK���O
int testOpt08_Type1_Before(const int value);
//�y�^�C�v�P�z�œK����P
int testOpt08_Type1_After1(const int value);
//�y�^�C�v�P�z�œK����Q
int testOpt08_Type1_After2(const int value);
//�y�^�C�v�P�z�œK����R
int testOpt08_Type1_After3(const int value);

//�y�^�C�v�Q�z�œK���O
int testOpt08_Type2_Before(const int value);
//�y�^�C�v�Q�z�œK����P
int testOpt08_Type2_After1(const int value);
//�y�^�C�v�Q�z�œK����Q
int testOpt08_Type2_After2(const int value);
//�y�^�C�v�Q�z�œK����R
int testOpt08_Type2_After3(const int value);

//�y�^�C�v�R�z�œK���O
bool testOpt08_Type3_Before(const int value1, const int value2);
//�y�^�C�v�R�z�œK����
bool testOpt08_Type3_After(const int value1, const int value2);

//�y�^�C�v�S�z�œK���O
int testOpt08_Type4_Before(const int value);
//�y�^�C�v�S�z�œK����P
int testOpt08_Type4_After1(const int value);
//�y�^�C�v�S�z�œK����Q
int testOpt08_Type4_After2(const int value);

//�y�^�C�v�T�z�œK���O
int testOpt08_Type5_Before(const int value);
//�y�^�C�v�T�z�œK����P
int testOpt08_Type5_After1(const int value);
//�y�^�C�v�T�z�œK����Q
int testOpt08_Type5_After2(const int value);
//�y�^�C�v�T�z�œK����R
int testOpt08_Type5_After3(const int value);

//�y�^�C�v�U�z�œK���O
int testOpt08_Type6_Before(const int value);
//�y�^�C�v�U�z�œK����P
int testOpt08_Type6_After1(const int value);
//�y�^�C�v�U�z�œK����Q
int testOpt08_Type6_After2(const int value);
//�y�^�C�v�U�z�œK����R
int testOpt08_Type6_After3(const int value);
//�y�^�C�v�U�z�œK����S
int testOpt08_Type6_After4(const int value);
//�y�^�C�v�U�z�œK����T
int testOpt08_Type6_After5(const int value);

//�y�^�C�v�V�z�œK���O
int testOpt08_Type7_Before(const int value);
//�y�^�C�v�V�z�œK����P
int testOpt08_Type7_After1(const int value);
//�y�^�C�v�V�z�œK����Q
int testOpt08_Type7_After2(const int value);
//�y�^�C�v�V�z�œK����R
int testOpt08_Type7_After3(const int value);
//�y�^�C�v�V�z�œK����S
int testOpt08_Type7_After4(const int value);
//�y�^�C�v�V�z�œK����T
int testOpt08_Type7_After5(const int value);

#if 0
//�y�^�C�v�W�z�œK���O
int testOpt08_Type8_Before(const int value);
//�y�^�C�v�W�z�œK����
int testOpt08_Type8_After(const int value);
//�y�^�C�v�W�z�y�Q�l�P�z
int testOpt08_Type8_Appendix1(const int value);
//�y�^�C�v�W�z�y�Q�l�Q�z
int testOpt08_Type8_Appendix2(const int value);
#else
//�y�^�C�v�W�z�œK���O
//��if���ɂ���Βl�v�Z
inline int testOpt08_Type8_Before(const int value)
{
	if (value < 0)
		return -value;
	return value;
}
//�y�^�C�v�W�z�œK����
//���v�Z���݂̂ɂ���Βl�v�Z
inline int testOpt08_Type8_After(const int value)
{
#if 1
	const int sign = value >> 31;//�����i-1��0�j���擾
	return (sign ^ value) - sign;//���̐��̎�: (0x00000000 ^ value) -  0 => value
	//���̐��̎�: (0xffffffff ^ value) - -1 => ~value + 1
#elif 1
	//�C�����C���A�Z���u���F�p�^�[���P
	__asm
	{
		mov    eax, value
		cdq
		xor    eax, edx
		sub    eax, edx
	}
#else
	//�C�����C���A�Z���u���F�p�^�[���Q
	__asm
	{
		mov    eax, value
		mov    ecx, eax
		neg    ecx
		cmovns eax, ecx
	}
#endif
}
//�y�^�C�v�W�z�y�Q�l�P�z
//���O�����Z�q�ɂ���Βl�v�Z
inline int testOpt08_Type8_Appendix1(const int value)
{
	return value < 0 ? -value : value;
}
//�y�^�C�v�W�z�y�Q�l�Q�z
//���W�����C�u�����ɂ���Βl�Z�o
#include <stdlib.h>
inline int testOpt08_Type8_Appendix2(const int value)
{
	return abs(value);
}
#endif

#if 0
//�y�^�C�v�X�z�œK���O
int testOpt08_Type9_Before(const int value);
//�y�^�C�v�X�z�œK����
int testOpt08_Type9_After(const int value);
//�y�^�C�v�X�z�y�Q�l�z
int testOpt08_Type9_Appendix(const int value);
#else
//�y�^�C�v�X�z�œK���O
//��if���ɂ�镄���擾
inline int testOpt08_Type9_Before(const int value)
{
	if (value < 0)
		return -1;
	else if (value > 0)
		return 1;
	return 0;
}
//�y�^�C�v�X�z�œK����
//���v�Z���݂̂ɂ�镄���擾
inline int testOpt08_Type9_After(const int value)
{
#if 1
	const int sign = value >> 31;//�����i-1��0�j���擾
	const int nz = value != 0;//��[������
	return sign | nz;
#else
	//�C�����C���A�Z���u��
	__asm
	{
		mov    eax, value
		xor    ecx, ecx
		test   eax, eax
		setne  cl
		cdq
		mov    eax, edx
		or     eax, ecx
	}
#endif
}
//�y�^�C�v�X�z�y�Q�l�z
//���O�����Z�q�ɂ�镄���擾
inline int testOpt08_Type9_Appendix(const int value)
{
	return value < 0 ? -1 : value > 0 ? 1 : 0;
}
#endif

//----------------------------------------
//�œK���H�F���[�v�񐔂̍팸�F���[�v�A�����[�����O

//�e�X�g�p�\����
struct dataOpt09_t1
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value;
	};

	elem_t elems[_ELEMENT_SIZE];
};
struct dataOpt09_t2
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value1;
		int value2;
		int others[10];
	};

	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt09_t1(dataOpt09_t1& data);
void initOpt09_t2(dataOpt09_t2& data);

//�y�^�C�v�P�z�œK���O
int testOpt09_Type1_Before(dataOpt09_t1& data);
//�y�^�C�v�P�z�œK����P
int testOpt09_Type1_After1(dataOpt09_t1& data);
//�y�^�C�v�P�z�œK����Q
int testOpt09_Type1_After2(dataOpt09_t1& data);
//�y�^�C�v�P�z�œK����R
int testOpt09_Type1_After3(dataOpt09_t1& data);
//�y�^�C�v�P�z�œK����S
int testOpt09_Type1_After4(dataOpt09_t1& data);
//�y�^�C�v�P�z�œK����T
int testOpt09_Type1_After5(dataOpt09_t1& data);
//�y�^�C�v�P�z�y�Q�l�zC++11�ł����Ƃ��Ȍ��ȋL�q
int testOpt09_Type1_Appendix(dataOpt09_t1& data);

//�y�^�C�v�Q�z�œK���O
int testOpt09_Type2_Before(dataOpt09_t2& data);
//�y�^�C�v�Q�z�œK����P
int testOpt09_Type2_After1(dataOpt09_t2& data);
//�y�^�C�v�Q�z�œK����Q
int testOpt09_Type2_After2(dataOpt09_t2& data);
//�y�^�C�v�Q�z�œK����R
int testOpt09_Type2_After3(dataOpt09_t2& data);
//�y�^�C�v�Q�z�œK����S
int testOpt09_Type2_After4(dataOpt09_t2& data);
//�y�^�C�v�Q�z�œK����T
int testOpt09_Type2_After5(dataOpt09_t2& data);
//�y�^�C�v�Q�z�œK����U
int testOpt09_Type2_After6(dataOpt09_t2& data);
//�y�^�C�v�Q�z�y�Q�l�zC++11�ł����Ƃ��Ȍ��ȋL�q
int testOpt09_Type2_Appendix(dataOpt09_t2& data);

//�y�^�C�v�R�z�œK���O
int testOpt09_Type3_Before(dataOpt09_t2::elem_t* elems, const std::size_t num);
//�y�^�C�v�R�z�œK����P
int testOpt09_Type3_After1(dataOpt09_t2::elem_t* elems, const std::size_t num);
//�y�^�C�v�R�z�œK����Q
int testOpt09_Type3_After2(dataOpt09_t2::elem_t* elems, const std::size_t num);
//�y�^�C�v�R�z�œK����R
int testOpt09_Type3_After3(dataOpt09_t2::elem_t* elems, const std::size_t num);
//�y�^�C�v�R�z�œK����S
int testOpt09_Type3_After4(dataOpt09_t2::elem_t* elems, const std::size_t num);
//�y�^�C�v�R�z�œK����T
int testOpt09_Type3_After5(dataOpt09_t2::elem_t* elems, const std::size_t num);
//�y�^�C�v�R�z�œK����U
int testOpt09_Type3_After6(dataOpt09_t2::elem_t* elems, const std::size_t num);

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
