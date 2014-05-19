#pragma once
#ifndef __SUB_H_
#define __SUB_H_

#define _VALUE_RANGE (10 + 1)//値の幅　※分布集計時のループ処理に影響あり
//#define _VALUE_RANGE (1000 + 1)//値の幅　※（同上）

//#define _ELEMENT_SIZE 100//配列要素数　※集計時のループ処理に影響あり
#define _ELEMENT_SIZE 10000//配列要素数　※（同上）

#include <cstddef>//std::szie_t用

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
//【タイプ３】最適化後
int testOpt03_Type3_After(dataOpt03_t& data);

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

//【タイプ１】最適化前
void testOpt04_Type1_Before(dataOpt04_t& data);
//【タイプ１】最適化後１
void testOpt04_Type1_After1(dataOpt04_t& data);
//【タイプ１】最適化後２
void testOpt04_Type1_After2(dataOpt04_t& data);

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
