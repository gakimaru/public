#pragma once
#ifndef __SUB_H_
#define __SUB_H_

//--------------------------------------------------------------------------------
//コンパイラスイッチ

#define USE_GCC//GCCを使用する場合、このマクロを有効化する

//#define STRLEN_FAST_IS_NOT_FAST//strlen_fastの実体を標準ライブラリの関数にする場合は、このマクロを有効化する
//#define STRCMP_FAST_IS_NOT_FAST//strcmp_fastの実体を標準ライブラリの関数にする場合は、このマクロを有効化する
//#define STRNCMP_FAST_IS_NOT_FAST//strncmp_fastの実体を標準ライブラリの関数にする場合は、このマクロを有効化する
//#define STRCHR_FAST_IS_NOT_FAST//strchr_fastの実体を標準ライブラリの関数にする場合は、このマクロを有効化する
//#define STRRCHR_FAST_IS_NOT_FAST//strrchr_fastの実体を標準ライブラリの関数にする場合は、このマクロを有効化する
//#define STRSTR_FAST_IS_NOT_FAST//strstr_fastの実体を標準ライブラリの関数にする場合は、このマクロを有効化する
//#define STRNCPY_PADDING_ZERO//strncpy_fastを本来の仕様（余りを0で埋める）で実装する場合は、このマクロを有効化する
                              //※無効化時は、最後にターミネータを一つ付加するだけ（高速）

#include <cstddef>//std::szie_t用

#ifndef USE_GCC
#define alignas(n) __declspec(align(n))
#define constexpr//ダミー
#else//USE_GCC
#define alignas(n) __attribute__((aligned(n)))
#endif//USE_GCC

//--------------------------------------------------------------------------------
//テスト用定数

#define _VALUE_RANGE (10 + 1)//値の幅　※分布集計時のループ処理に影響あり
//#define _VALUE_RANGE (1000 + 1)//値の幅　※（同上）

//#define _ELEMENT_SIZE 100//配列要素数　※集計時のループ処理に影響あり
#define _ELEMENT_SIZE 10000//配列要素数　※（同上）

//----------------------------------------
//最適化①：メモリアクセスの抑制：一時変数の活用

//テスト用構造体
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

//初期化
void initOpt01(dataOpt01_t& data);
//【タイプ１】最適化前
void testOpt01_Type1_Before(dataOpt01_t& data);
//【タイプ１】最適化後１
void testOpt01_Type1_After1(dataOpt01_t& data);
//【タイプ１】最適化後２
void testOpt01_Type1_After2(dataOpt01_t& data);
//【タイプ１】最適化後３
void testOpt01_Type1_After3(dataOpt01_t& data);
//【タイプ１】最適化後４
void testOpt01_Type1_After4(dataOpt01_t& data);
//【タイプ１】【参考】C++11でもっとも簡潔な記述
void testOpt01_Type1_Appendix(dataOpt01_t& data);

//----------------------------------------
//最適化②：メモリアクセスの抑制：アドレス計算の削減

//テスト用構造体
struct dataOpt02_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value;
	};
	elem_t elems[_ELEMENT_SIZE];
};

//初期化
void initOpt02(dataOpt02_t& data);
//【タイプ１】最適化前
int testOpt02_Type1_Before(dataOpt02_t& data);
//【タイプ１】最適化後１
int testOpt02_Type1_After1(dataOpt02_t& data);
//【タイプ１】最適化後２
int testOpt02_Type1_After2(dataOpt02_t& data);
//【タイプ１】最適化後３
int testOpt02_Type1_After3(dataOpt02_t& data);

//----------------------------------------
//最適化③：メモリアクセスの抑制：関数呼び出しの削減

//テスト用構造体
struct dataOpt03_t
{
	static const std::size_t VALUE_RANGE = _VALUE_RANGE;
	int values[_ELEMENT_SIZE];
};

//【タイプ１】最適化前
int testOpt03_Type1_Before(int a, int b, int c);
//【タイプ１】最適化後
inline int testOpt03_Type1_After(int a, int b, int c)
{
	return a * b + c;
}

//【タイプ２】最適化前
int testOpt03_Type2_Before(int a, int b, int c, int d, int e, int f, int g, int h);
//【タイプ２】最適化後
inline int testOpt03_Type2_After(int a, int b, int c, int d, int e, int f, int g, int h)
{
	return a * b + c - d * e + f - g * h;
}

//【タイプ３】初期化
void initOpt03_Type3(dataOpt03_t& data);
//【タイプ３】最適化前
int testOpt03_Type3_Before(dataOpt03_t& data);
//【タイプ３】最適化後1
int testOpt03_Type3_After1(dataOpt03_t& data);
//【タイプ３】最適化後2
int testOpt03_Type3_After2(dataOpt03_t& data);
//【タイプ３】最適化後3
int testOpt03_Type3_After3(dataOpt03_t& data);
//【タイプ３】【参考】A-1
int testOpt03_Type3_AppendixA1(dataOpt03_t& data);
//【タイプ３】【参考】A-2
int testOpt03_Type3_AppendixA2(dataOpt03_t& data);
//【タイプ３】【参考】A-3
int testOpt03_Type3_AppendixA3(dataOpt03_t& data);
//【タイプ３】【参考】B-1
int testOpt03_Type3_AppendixB1(dataOpt03_t& data);
//【タイプ３】【参考】B-2
int testOpt03_Type3_AppendixB2(dataOpt03_t& data);
//【タイプ３】【参考】B-3
int testOpt03_Type3_AppendixB3(dataOpt03_t& data);

//----------------------------------------
//最適化④：除算の抑制：乗算に変更

//テスト用構造体
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

//初期化
void initOpt04(dataOpt04_t& data);

#if 0
//【タイプ１】最適化前
float testOpt04_Type1_Before(const float value);
//【タイプ１】最適化後
float testOpt04_Type1_After(const float value);
#else
//【タイプ１】最適化前
//※定数による除算
inline float testOpt04_Type1_Before(const float value)
{
	return value / 1.2f;
}

//【タイプ１】最適化後
//※定数による除算を乗算に変更
inline float testOpt04_Type1_After(const float value)
{
	return value * (1.f / 1.2f);
}
#endif

//【タイプ２】最適化前
void testOpt04_Type2_Before(dataOpt04_t& data);
//【タイプ２】最適化後１
void testOpt04_Type2_After1(dataOpt04_t& data);
//【タイプ２】最適化後２
void testOpt04_Type2_After2(dataOpt04_t& data);

#if 0
//【タイプ３】最適化前
float testOpt04_Type3_Before(const float value, const float div);
//【タイプ３】最適化後
float testOpt04_Type3_After(const float value, const float div);
#else

#include <xmmintrin.h>//SSE1
//【タイプ３】最適化前
//※変数による除算
inline float testOpt04_Type3_Before(const float value, const float div)
{
	//return value / div;
	//除算
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _div_m128 = _mm_set1_ps(div);
	const __m128 _result_m128 = _mm_div_ss(_value_m128, _div_m128);
	//計算結果取得
	float result;
	_mm_store_ss(&result, _result_m128);
	return result;
}

//【タイプ３】最適化後1
//※変数による除算を乗算に変更
inline float testOpt04_Type3_After1(const float value, const float div)
{
	//const float rcp = 1.f / div;
	//return value * rcp;
	//逆数算出
	const __m128 _div_m128 = _mm_set1_ps(div);
	const __m128 _rcp_m128 = _mm_rcp_ss(_div_m128);
	//乗算
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _result_m128 = _mm_mul_ss(_value_m128, _rcp_m128);
	//計算結果取得
	float result;
	_mm_store_ss(&result, _result_m128);
	return result;
}

//【タイプ３】最適化後2
//※変数による除算を乗算に変更
//※ニュートン法で逆数の精度を高める
inline float testOpt04_Type3_After2(const float value, const float div)
{
	//const float rcp = 1.f / div;
	//return value * rcp;
	//逆数算出
	const __m128 _div_m128 = _mm_set1_ps(div);
	__m128 _rcp_m128 = _mm_rcp_ss(_div_m128);
	//ニュートン法で逆数の精度を高める
	//ニュートン法による漸化式：rcp = rcp * (2.f - div * rcp)
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
	//乗算
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _result_m128 = _mm_mul_ss(_value_m128, _rcp_m128);
	//計算結果取得
	float result;
	_mm_store_ss(&result, _result_m128);
	return result;
}

//【タイプ３】最適化後3
//※変数による除算を乗算に変更
//※ニュートン法を2回繰り返し、より逆数の精度を高める
inline float testOpt04_Type3_After3(const float value, const float div)
{
	//const float rcp = 1.f / div;
	//return value * rcp;
	//逆数算出
	const __m128 _div_m128 = _mm_set1_ps(div);
	__m128 _rcp_m128 = _mm_rcp_ss(_div_m128);
	//ニュートン法で逆数の精度を高める
	const __m128 _2_m128 = _mm_set1_ps(2.f);
	_rcp_m128 = _mm_mul_ss(_rcp_m128, _mm_sub_ss(_2_m128, _mm_mul_ss(_div_m128, _rcp_m128)));
	_rcp_m128 = _mm_mul_ss(_rcp_m128, _mm_sub_ss(_2_m128, _mm_mul_ss(_div_m128, _rcp_m128)));
	//乗算
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _result_m128 = _mm_mul_ss(_value_m128, _rcp_m128);
	//計算結果取得
	float result;
	_mm_store_ss(&result, _result_m128);
	return result;
}
#endif

#if 0
//【タイプ４】最適化前
float testOpt04_Type4_Before(const float value);
//【タイプ４】最適化後
float testOpt04_Type4_After(const float value);
#else
//【タイプ４】最適化前
//※平方根
#include <xmmintrin.h>//SSE1
inline float testOpt04_Type4_Before(const float value)
{
	//return sqrt(value);
	//平方根算出
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _sqrt_m128 = _mm_sqrt_ss(_value_m128);
	//計算結果取得
	float sqrt;
	_mm_store_ss(&sqrt, _sqrt_m128);
	return sqrt;
}

//【タイプ４】最適化後1
//※平方根の逆数を使用した平方根
inline float testOpt04_Type4_After1(const float value)
{
	//const float rsqrt = rsqrt(value);
	//return value * rsqrt;
	//平方根の逆数算出
	const __m128 _value_m128 = _mm_set1_ps(value);
	const __m128 _rsqrt_m128 = _mm_rsqrt_ss(_value_m128);
	//乗算
	const __m128 _sqrt_m128 = _mm_mul_ss(_value_m128, _rsqrt_m128);
	//計算結果取得
	float sqrt;
	_mm_store_ss(&sqrt, _sqrt_m128);
	return sqrt;
}

//【タイプ４】最適化後2
//※平方根の逆数を使用した平方根
//※ニュートン法で逆数の精度を高める
inline float testOpt04_Type4_After2(const float value)
{
	//const float rsqrt = rsqrt(value);
	//return value * rsqrt;
	//平方根の逆数算出
	const __m128 _value_m128 = _mm_set1_ps(value);
	__m128 _rsqrt_m128 = _mm_rsqrt_ss(_value_m128);
	//ニュートン法で逆数の精度を高める
	//ニュートン法による漸化式：rsqrt = rsqrt * (3 - value * rsqrt * rsqrt) * 0.5f
	//  平方根の漸化式:      x[i+1] = (x[i] + value / x[i]) * 0.5
	//  平方根の逆数の漸化式:x[i+1] = x[i] * (3 - value * x[i] ^ 2) * 0.5
	const __m128 _3_m128 = _mm_set1_ps(3.f);
	const __m128 _05_m128 = _mm_set1_ps(0.5f);
	_rsqrt_m128 = _mm_mul_ss(_mm_mul_ss(_rsqrt_m128, _mm_sub_ss(_3_m128, _mm_mul_ss(_value_m128, _mm_mul_ss(_rsqrt_m128, _rsqrt_m128)))), _05_m128);
	//乗算
	const __m128 _sqrt_m128 = _mm_mul_ss(_value_m128, _rsqrt_m128);
	//計算結果取得
	float sqrt;
	_mm_store_ss(&sqrt, _sqrt_m128);
	return sqrt;
}

//【タイプ４】最適化後3
//※平方根の逆数を使用した平方根
//※ニュートン法を2回繰り返し、より逆数の精度を高める
inline float testOpt04_Type4_After3(const float value)
{
	//const float rsqrt = rsqrt(value);
	//return value * rsqrt;
	//平方根の逆数算出
	const __m128 _value_m128 = _mm_set1_ps(value);
	__m128 _rsqrt_m128 = _mm_rsqrt_ss(_value_m128);
	//ニュートン法で逆数の精度を高める
	const __m128 _3_m128 = _mm_set1_ps(3.f);
	const __m128 _05_m128 = _mm_set1_ps(0.5f);
	_rsqrt_m128 = _mm_mul_ss(_mm_mul_ss(_rsqrt_m128, _mm_sub_ss(_3_m128, _mm_mul_ss(_value_m128, _mm_mul_ss(_rsqrt_m128, _rsqrt_m128)))), _05_m128);
	_rsqrt_m128 = _mm_mul_ss(_mm_mul_ss(_rsqrt_m128, _mm_sub_ss(_3_m128, _mm_mul_ss(_value_m128, _mm_mul_ss(_rsqrt_m128, _rsqrt_m128)))), _05_m128);
	//乗算
	const __m128 _sqrt_m128 = _mm_mul_ss(_value_m128, _rsqrt_m128);
	//計算結果取得
	float sqrt;
	_mm_store_ss(&sqrt, _sqrt_m128);
	return sqrt;
}
#endif

//----------------------------------------
//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更

//【タイプ１】最適化前
int testOpt05_Type1_Before(int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						   int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						   int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24);
//【タイプ１】最適化後
int testOpt05_Type1_After(int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						  int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						  int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24);

//----------------------------------------
//最適化⑥：乗算／除算の抑制：計算結果の共通利用

//テスト用構造体
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

//初期化
void initOpt06(dataOpt06_t& data);

//【タイプ１】最適化前
float testOpt06_Type1_Before(dataOpt06_t& data, const float mul1, const float mul2, const float div);
//【タイプ１】最適化後１
float testOpt06_Type1_After(dataOpt06_t& data, const float mul1, const float mul2, const float div);

//----------------------------------------
//最適化⑦：SIMD演算の活用

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

//【タイプ１】最適化前
template<std::size_t N, std::size_t M, std::size_t NM>
void testOpt07_Type1_Before(const int dummy, matrix<N, M>& add0, matrix<N, M>& mul0a, matrix<N, M>& mul0b, const matrix<N, M>& add1, const matrix<N, M>& add2, const matrix<N, M>& mul1a, const float mul2a, const matrix<N, NM>& mul1b, const matrix<NM, M>& mul2b);
//【タイプ１】最適化後
template<std::size_t N, std::size_t M, std::size_t NM>
void testOpt07_Type1_After(const int dummy, matrix<N, M>& add0, matrix<N, M>& mul0a, matrix<N, M>& mul0b, const matrix<N, M>& add1, const matrix<N, M>& add2, const matrix<N, M>& mul1a, const float mul2a, const matrix<N, NM>& mul1b, const matrix<NM, M>& mul2b);

//【タイプ２】最適化前
std::size_t testOpt07_Type2_strlen_Before(const int dummy, const char* str);
int testOpt07_Type2_strcmp_Before(const int dummy, const char* str1, const char* str2);
int testOpt07_Type2_strncmp_Before(const int dummy, const char* str1, const char* str2, const std::size_t max_len);
const char* testOpt07_Type2_strchr_Before(const int dummy, const char* str, const char c);
const char* testOpt07_Type2_strrchr_Before(const int dummy, const char* str, const char c);
const char* testOpt07_Type2_strstr_Before(const int dummy, const char* str1, const char* str2);
const char* testOpt07_Type2_strcpy_Before(const int dummy, char* dst, const char* src);
const char* testOpt07_Type2_strncpy_Before(const int dummy, char* dst, const char* src, const std::size_t max_len);
//【タイプ２】最適化後
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
//最適化⑧：条件分岐の削減

//【タイプ１】最適化前
int testOpt08_Type1_Before(const int value);
//【タイプ１】最適化後１
int testOpt08_Type1_After1(const int value);
//【タイプ１】最適化後２
int testOpt08_Type1_After2(const int value);
//【タイプ１】最適化後３
int testOpt08_Type1_After3(const int value);

//【タイプ２】最適化前
int testOpt08_Type2_Before(const int value);
//【タイプ２】最適化後１
int testOpt08_Type2_After1(const int value);
//【タイプ２】最適化後２
int testOpt08_Type2_After2(const int value);
//【タイプ２】最適化後３
int testOpt08_Type2_After3(const int value);

//【タイプ３】最適化前
bool testOpt08_Type3_Before(const int value1, const int value2);
//【タイプ３】最適化後
bool testOpt08_Type3_After(const int value1, const int value2);

//【タイプ４】最適化前
int testOpt08_Type4_Before(const int value);
//【タイプ４】最適化後１
int testOpt08_Type4_After1(const int value);
//【タイプ４】最適化後２
int testOpt08_Type4_After2(const int value);

//【タイプ５】最適化前
int testOpt08_Type5_Before(const int value);
//【タイプ５】最適化後１
int testOpt08_Type5_After1(const int value);
//【タイプ５】最適化後２
int testOpt08_Type5_After2(const int value);
//【タイプ５】最適化後３
int testOpt08_Type5_After3(const int value);

//【タイプ６】最適化前
int testOpt08_Type6_Before(const int value);
//【タイプ６】最適化後１
int testOpt08_Type6_After1(const int value);
//【タイプ６】最適化後２
int testOpt08_Type6_After2(const int value);
//【タイプ６】最適化後３
int testOpt08_Type6_After3(const int value);
//【タイプ６】最適化後４
int testOpt08_Type6_After4(const int value);
//【タイプ６】最適化後５
int testOpt08_Type6_After5(const int value);

//【タイプ７】最適化前
int testOpt08_Type7_Before(const int value);
//【タイプ７】最適化後１
int testOpt08_Type7_After1(const int value);
//【タイプ７】最適化後２
int testOpt08_Type7_After2(const int value);
//【タイプ７】最適化後３
int testOpt08_Type7_After3(const int value);
//【タイプ７】最適化後４
int testOpt08_Type7_After4(const int value);
//【タイプ７】最適化後５
int testOpt08_Type7_After5(const int value);

#if 0
//【タイプ８】最適化前
int testOpt08_Type8_Before(const int value);
//【タイプ８】最適化後
int testOpt08_Type8_After(const int value);
//【タイプ８】【参考１】
int testOpt08_Type8_Appendix1(const int value);
//【タイプ８】【参考２】
int testOpt08_Type8_Appendix2(const int value);
#else
//【タイプ８】最適化前
//※if文による絶対値計算
inline int testOpt08_Type8_Before(const int value)
{
	if (value < 0)
		return -value;
	return value;
}
//【タイプ８】最適化後
//※計算式のみによる絶対値計算
inline int testOpt08_Type8_After(const int value)
{
#if 1
	const int sign = value >> 31;//符号（-1か0）を取得
	return (sign ^ value) - sign;//正の数の時: (0x00000000 ^ value) -  0 => value
	//負の数の時: (0xffffffff ^ value) - -1 => ~value + 1
#elif 1
	//インラインアセンブラ：パターン１
	__asm
	{
		mov    eax, value
		cdq
		xor    eax, edx
		sub    eax, edx
	}
#else
	//インラインアセンブラ：パターン２
	__asm
	{
		mov    eax, value
		mov    ecx, eax
		neg    ecx
		cmovns eax, ecx
	}
#endif
}
//【タイプ８】【参考１】
//※三項演算子による絶対値計算
inline int testOpt08_Type8_Appendix1(const int value)
{
	return value < 0 ? -value : value;
}
//【タイプ８】【参考２】
//※標準ライブラリによる絶対値算出
#include <stdlib.h>
inline int testOpt08_Type8_Appendix2(const int value)
{
	return abs(value);
}
#endif

#if 0
//【タイプ９】最適化前
int testOpt08_Type9_Before(const int value);
//【タイプ９】最適化後
int testOpt08_Type9_After(const int value);
//【タイプ９】【参考】
int testOpt08_Type9_Appendix(const int value);
#else
//【タイプ９】最適化前
//※if文による符号取得
inline int testOpt08_Type9_Before(const int value)
{
	if (value < 0)
		return -1;
	else if (value > 0)
		return 1;
	return 0;
}
//【タイプ９】最適化後
//※計算式のみによる符号取得
inline int testOpt08_Type9_After(const int value)
{
#if 1
	const int sign = value >> 31;//符号（-1か0）を取得
	const int nz = value != 0;//非ゼロ判定
	return sign | nz;
#else
	//インラインアセンブラ
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
//【タイプ９】【参考】
//※三項演算子による符号取得
inline int testOpt08_Type9_Appendix(const int value)
{
	return value < 0 ? -1 : value > 0 ? 1 : 0;
}
#endif

//----------------------------------------
//最適化⑨：ループ回数の削減：ループアンローリング

//テスト用構造体
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

//初期化
void initOpt09_t1(dataOpt09_t1& data);
void initOpt09_t2(dataOpt09_t2& data);

//【タイプ１】最適化前
int testOpt09_Type1_Before(dataOpt09_t1& data);
//【タイプ１】最適化後１
int testOpt09_Type1_After1(dataOpt09_t1& data);
//【タイプ１】最適化後２
int testOpt09_Type1_After2(dataOpt09_t1& data);
//【タイプ１】最適化後３
int testOpt09_Type1_After3(dataOpt09_t1& data);
//【タイプ１】最適化後４
int testOpt09_Type1_After4(dataOpt09_t1& data);
//【タイプ１】最適化後５
int testOpt09_Type1_After5(dataOpt09_t1& data);
//【タイプ１】【参考】C++11でもっとも簡潔な記述
int testOpt09_Type1_Appendix(dataOpt09_t1& data);

//【タイプ２】最適化前
int testOpt09_Type2_Before(dataOpt09_t2& data);
//【タイプ２】最適化後１
int testOpt09_Type2_After1(dataOpt09_t2& data);
//【タイプ２】最適化後２
int testOpt09_Type2_After2(dataOpt09_t2& data);
//【タイプ２】最適化後３
int testOpt09_Type2_After3(dataOpt09_t2& data);
//【タイプ２】最適化後４
int testOpt09_Type2_After4(dataOpt09_t2& data);
//【タイプ２】最適化後５
int testOpt09_Type2_After5(dataOpt09_t2& data);
//【タイプ２】最適化後６
int testOpt09_Type2_After6(dataOpt09_t2& data);
//【タイプ２】【参考】C++11でもっとも簡潔な記述
int testOpt09_Type2_Appendix(dataOpt09_t2& data);

//【タイプ３】最適化前
int testOpt09_Type3_Before(dataOpt09_t2::elem_t* elems, const std::size_t num);
//【タイプ３】最適化後１
int testOpt09_Type3_After1(dataOpt09_t2::elem_t* elems, const std::size_t num);
//【タイプ３】最適化後２
int testOpt09_Type3_After2(dataOpt09_t2::elem_t* elems, const std::size_t num);
//【タイプ３】最適化後３
int testOpt09_Type3_After3(dataOpt09_t2::elem_t* elems, const std::size_t num);
//【タイプ３】最適化後４
int testOpt09_Type3_After4(dataOpt09_t2::elem_t* elems, const std::size_t num);
//【タイプ３】最適化後５
int testOpt09_Type3_After5(dataOpt09_t2::elem_t* elems, const std::size_t num);
//【タイプ３】最適化後６
int testOpt09_Type3_After6(dataOpt09_t2::elem_t* elems, const std::size_t num);

//----------------------------------------
//共通関数

//配列情報取得
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
