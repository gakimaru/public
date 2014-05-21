#include "sub.h"

//テストループ回数
//#define NOLOOP//それぞれ1回だけのテストにする場合は、このマクロを有効化する
#ifdef NOLOOP
	//最適化①：メモリアクセスの抑制：一時変数の活用
	static const int LOOP_OPT01_TYPE1 = 1;
	//最適化②：メモリアクセスの抑制：アドレス計算の削減
	static const int LOOP_OPT02_TYPE1 = 1;
	//最適化③：メモリアクセスの抑制：関数呼び出しの削減
	static const int LOOP_OPT03_TYPE1 = 1;
	static const int LOOP_OPT03_TYPE2 = 1;
	static const int LOOP_OPT03_TYPE3 = 1;
	//最適化④：除算の抑制：乗算に変更
	static const int LOOP_OPT04_TYPE1 = 1;
	//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更
	static const int LOOP_OPT05_TYPE1 = 1;
	//最適化⑥：乗算／除算の抑制：演算の共通化
	static const int LOOP_OPT06_TYPE1 = 1;
	//最適化⑦：SIMD演算を活用する
	static const int LOOP_OPT07_TYPE1 = 1;
	static const int LOOP_OPT07_TYPE2 = 1;
#else//NOLOOP
	#if _ELEMENT_SIZE >= 10000
		#ifdef _DEBUG
			//最適化①：メモリアクセスの抑制：一時変数の活用
			static const int LOOP_OPT01_TYPE1 = 1000;
			//最適化②：メモリアクセスの抑制：アドレス計算の削減
			static const int LOOP_OPT02_TYPE1 = 1000;
			//最適化③：メモリアクセスの抑制：関数呼び出しの削減
			static const int LOOP_OPT03_TYPE1 = 10000000;
			static const int LOOP_OPT03_TYPE2 = 10000000;
			static const int LOOP_OPT03_TYPE3 = 1000;
			//最適化④：除算の抑制：乗算に変更
			static const int LOOP_OPT04_TYPE1 = 1000;
			//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更
			static const int LOOP_OPT05_TYPE1 = 100000;
			//最適化⑥：乗算／除算の抑制：演算の共通化
			static const int LOOP_OPT06_TYPE1 = 1000;
			//最適化⑦：SIMD演算を活用する
			static const int LOOP_OPT07_TYPE1 = 100000;
			static const int LOOP_OPT07_TYPE2 = 10000;
		#else//_DEBUG
			//最適化①：メモリアクセスの抑制：一時変数の活用
			static const int LOOP_OPT01_TYPE1 = 10000;
			//最適化②：メモリアクセスの抑制：アドレス計算の削減
			static const int LOOP_OPT02_TYPE1 = 10000;
			//最適化③：メモリアクセスの抑制：関数呼び出しの削減
			static const int LOOP_OPT03_TYPE1 = 100000000;
			static const int LOOP_OPT03_TYPE2 = 100000000;
			static const int LOOP_OPT03_TYPE3 = 10000;
			//最適化④：除算の抑制：乗算に変更
			static const int LOOP_OPT04_TYPE1 = 10000;
			//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更
			static const int LOOP_OPT05_TYPE1 = 10000000;
			//最適化⑥：乗算／除算の抑制：演算の共通化
			static const int LOOP_OPT06_TYPE1 = 10000;
			//最適化⑦：SIMD演算を活用する
			static const int LOOP_OPT07_TYPE1 = 10000000;
			static const int LOOP_OPT07_TYPE2 = 1000000;
		#endif//_DEBUG
	#else//_ELEMENT_SIZE < 1000
		#ifdef _DEBUG
			//最適化①：メモリアクセスの抑制：一時変数の活用
			static const int LOOP_OPT01_TYPE1 = 100000;
			//最適化②：メモリアクセスの抑制：アドレス計算の削減
			static const int LOOP_OPT02_TYPE1 = 100000;
			//最適化③：メモリアクセスの抑制：関数呼び出しの削減
			static const int LOOP_OPT03_TYPE1 = 10000000;
			static const int LOOP_OPT03_TYPE2 = 10000000;
			static const int LOOP_OPT03_TYPE3 = 100000;
			//最適化④：除算の抑制：乗算に変更
			static const int LOOP_OPT04_TYPE1 = 100000;
			//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更
			static const int LOOP_OPT05_TYPE1 = 1000000;
			//最適化⑥：乗算／除算の抑制：演算の共通化
			static const int LOOP_OPT06_TYPE1 = 100000;
			//最適化⑦：SIMD演算を活用する
			static const int LOOP_OPT07_TYPE1 = 100000;
			static const int LOOP_OPT07_TYPE2 = 10000;
		#else//_DEBUG
			//最適化①：メモリアクセスの抑制：一時変数の活用
			static const int LOOP_OPT01_TYPE1 = 1000000;
			//最適化②：メモリアクセスの抑制：アドレス計算の削減
			static const int LOOP_OPT02_TYPE1 = 1000000;
			//最適化③：メモリアクセスの抑制：関数呼び出しの削減
			static const int LOOP_OPT03_TYPE1 = 100000000;
			static const int LOOP_OPT03_TYPE2 = 100000000;
			static const int LOOP_OPT03_TYPE3 = 1000000;
			//最適化④：除算の抑制：乗算に変更
			static const int LOOP_OPT04_TYPE1 = 1000000;
			//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更
			static const int LOOP_OPT05_TYPE1 = 10000000;
			//最適化⑥：乗算／除算の抑制：演算の共通化
			static const int LOOP_OPT06_TYPE1 = 1000000;
			//最適化⑦：SIMD演算を活用する
			static const int LOOP_OPT07_TYPE1 = 100000000;
			static const int LOOP_OPT07_TYPE2 = 10000000;
		#endif//_DEBUG
	#endif//_ELEMENT_SIZE < 1000
#endif//NOLOOP

#include <stdio.h>
#include <stdlib.h>

#include <chrono>//C++11 時間関数用
#include <random>//C++11 std::radom用

//----------------------------------------
//経過時間を表示
void printElapsedTime(const std::chrono::system_clock::time_point& prev_time, const bool is_not_cr = false)
{
	auto now_time = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - prev_time);
	double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
	printf("*elapsed time=%.9lf", elapsed_time);
	if (!is_not_cr)
		printf("\n");
}
inline void printElapsedTimeWithoutCR(const std::chrono::system_clock::time_point& prev_time)
{
	printElapsedTime(prev_time, true);
}

//----------------------------------------
//最適化①：メモリアクセスの抑制：一時変数の活用
void runTestOpt01()
{
	printf("----------------------------------------\n");
	printf("[Optimize Test 01]\n");

	//初期化
	dataOpt01_t data;
	initOpt01(data);

	//【タイプ１】
	extern void runTestOpt01_Type1(dataOpt01_t& data);
	runTestOpt01_Type1(data);
}
//【タイプ１】
void runTestOpt01_Type1(dataOpt01_t& data)
{
	printf("Type1: *repeated * %d times.\n", LOOP_OPT01_TYPE1);
	extern void runTestOpt01_Type1_Before(dataOpt01_t& data);
	extern void runTestOpt01_Type1_After1(dataOpt01_t& data);
	extern void runTestOpt01_Type1_After2(dataOpt01_t& data);
	extern void runTestOpt01_Type1_Appendix(dataOpt01_t& data);
	runTestOpt01_Type1_Before(data);
	runTestOpt01_Type1_After1(data);
	runTestOpt01_Type1_After2(data);
	runTestOpt01_Type1_Appendix(data);
}
//最適化前
void runTestOpt01_Type1_Before(dataOpt01_t& data)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT01_TYPE1; ++loop)
		testOpt01_Type1_Before(data);
	printElapsedTime(prev_time);
}
//最適化後１
void runTestOpt01_Type1_After1(dataOpt01_t& data)
{
	printf("  After1   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT01_TYPE1; ++loop)
		testOpt01_Type1_After1(data);
	printElapsedTime(prev_time);
}
//最適化後２
void runTestOpt01_Type1_After2(dataOpt01_t& data)
{
	printf("  After2   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT01_TYPE1; ++loop)
		testOpt01_Type1_After2(data);
	printElapsedTime(prev_time);
}
//【参考】C++11でもっとも簡潔な記述
void runTestOpt01_Type1_Appendix(dataOpt01_t& data)
{
	printf("  Appendix ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT01_TYPE1; ++loop)
		testOpt01_Type1_Appendix(data);
	printElapsedTimeWithoutCR(prev_time);
	printf("  *Appendix is most brief style with C++11\n");
}

//----------------------------------------
//最適化②：メモリアクセスの抑制：アドレス計算の削減
void runTestOpt02()
{
	printf("----------------------------------------\n");
	printf("[Optimize Test 02]\n");

	//初期化
	dataOpt02_t data;
	initOpt02(data);

	//【タイプ１】
	extern void runTestOpt02_Type1(dataOpt02_t& data);
	runTestOpt02_Type1(data);
}
//【タイプ１】
void runTestOpt02_Type1(dataOpt02_t& data)
{
	printf("Type1: *repeated * %d times.\n", LOOP_OPT02_TYPE1);
	extern void runTestOpt02_Type1_Before(dataOpt02_t& data);
	extern void runTestOpt02_Type1_After1(dataOpt02_t& data);
	extern void runTestOpt02_Type1_After2(dataOpt02_t& data);
	runTestOpt02_Type1_Before(data);
	runTestOpt02_Type1_After1(data);
	runTestOpt02_Type1_After2(data);
}
//最適化前
void runTestOpt02_Type1_Before(dataOpt02_t& data)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT02_TYPE1; ++loop)
		testOpt02_Type1_Before(data);
	printElapsedTime(prev_time);
}
//最適化後１
void runTestOpt02_Type1_After1(dataOpt02_t& data)
{
	printf("  After1   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT02_TYPE1; ++loop)
		testOpt02_Type1_After1(data);
	printElapsedTime(prev_time);
}
//最適化後２
void runTestOpt02_Type1_After2(dataOpt02_t& data)
{
	printf("  After2   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT02_TYPE1; ++loop)
		testOpt02_Type1_After2(data);
	printElapsedTime(prev_time);
}

//----------------------------------------
//最適化③：メモリアクセスの抑制：関数呼び出しの削減
void runTestOpt03()
{
	printf("----------------------------------------\n");
	printf("[Optimize Test 03]\n");

	//【タイプ１】
	extern void runTestOpt03_Type1();
	runTestOpt03_Type1();

	//【タイプ２】
	extern void runTestOpt03_Type2();
	runTestOpt03_Type2();

	//【タイプ３】
	extern void runTestOpt03_Type3();
	runTestOpt03_Type3();
}
//【タイプ１】
void runTestOpt03_Type1()
{
	//初期化
	std::mt19937 rnd_engine;
	auto rnd = [&rnd_engine]() -> int
	{
		std::uniform_int_distribution<int> dist(0, 9);
		return dist(rnd_engine);
	};
	const int coef1 = rnd();
	const int coef2 = rnd();
	
	printf("Type1: *repeated * %d times.\n", LOOP_OPT03_TYPE1);
	extern void runTestOpt03_Type1_Before(const int coef1, const int coef2);
	extern void runTestOpt03_Type1_After(const int coef1, const int coef2);
	runTestOpt03_Type1_Before(coef1, coef2);
	runTestOpt03_Type1_After(coef1, coef2);
}
//最適化前
void runTestOpt03_Type1_Before(const int coef1, const int coef2)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	int sum = 0;
	for (int loop = 0; loop < LOOP_OPT03_TYPE1; ++loop)
		sum += testOpt03_Type1_Before(loop, coef1, coef2);
	printElapsedTimeWithoutCR(prev_time);
	printf("  sum=%d\n", sum);
}
//最適化後
void runTestOpt03_Type1_After(const int coef1, const int coef2)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	int sum = 0;
	for (int loop = 0; loop < LOOP_OPT03_TYPE1; ++loop)
		sum += testOpt03_Type1_After(loop, coef1, coef2);
	printElapsedTimeWithoutCR(prev_time);
	printf("  sum=%d\n", sum);
}
//【タイプ２】
void runTestOpt03_Type2()
{
	//初期化
	std::mt19937 rnd_engine;
	auto rnd = [&rnd_engine]() -> int
	{
		std::uniform_int_distribution<int> dist(0, 9);
		return dist(rnd_engine);
	};
	const int coef1 = rnd();
	const int coef2 = rnd();
	const int coef3 = rnd();
	const int coef4 = rnd();
	const int coef5 = rnd();
	const int coef6 = rnd();
	const int coef7 = rnd();

	printf("Type2: *repeated * %d times.\n", LOOP_OPT03_TYPE2);
	extern void runTestOpt03_Type2_Before(const int coef1, const int coef2, const int coef3, const int coef4, const int coef5, const int coef6, const int coef7);
	extern void runTestOpt03_Type2_After(const int coef1, const int coef2, const int coef3, const int coef4, const int coef5, const int coef6, const int coef7);
	runTestOpt03_Type2_Before(coef1, coef2, coef3, coef4, coef5, coef6, coef7);
	runTestOpt03_Type2_After(coef1, coef2, coef3, coef4, coef5, coef6, coef7);
}
//最適化前
void runTestOpt03_Type2_Before(const int coef1, const int coef2, const int coef3, const int coef4, const int coef5, const int coef6, const int coef7)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	int sum = 0;
	for (int loop = 0; loop < LOOP_OPT03_TYPE2; ++loop)
		sum += testOpt03_Type2_Before(loop, coef1, coef2, coef3, coef4, coef5, coef6, coef7);
	printElapsedTimeWithoutCR(prev_time);
	printf("  sum=%d\n", sum);
}
//最適化後
void runTestOpt03_Type2_After(const int coef1, const int coef2, const int coef3, const int coef4, const int coef5, const int coef6, const int coef7)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	int sum = 0;
	for (int loop = 0; loop < LOOP_OPT03_TYPE2; ++loop)
		sum += testOpt03_Type2_After(loop, coef1, coef2, coef3, coef4, coef5, coef6, coef7);
	printElapsedTimeWithoutCR(prev_time);
	printf("  sum=%d\n", sum);
}
//【タイプ３】
void runTestOpt03_Type3()
{
	printf("Type3: *repeated * %d times.\n", LOOP_OPT03_TYPE3);
	extern void runTestOpt03_Type3_Before();
	extern void runTestOpt03_Type3_After();
	runTestOpt03_Type3_Before();
	runTestOpt03_Type3_After();
}
//最適化前
void runTestOpt03_Type3_Before()
{
	dataOpt03_t data;
	initOpt03_Type3(data);
	
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	int count = 0;
	for (int loop = 0; loop < LOOP_OPT03_TYPE3; ++loop)
		count += testOpt03_Type3_Before(data);
	printElapsedTimeWithoutCR(prev_time);
	printf("  count=%d\n", count);
}
//最適化後
void runTestOpt03_Type3_After()
{
	dataOpt03_t data;
	initOpt03_Type3(data);

	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	int count = 0;
	for (int loop = 0; loop < LOOP_OPT03_TYPE3; ++loop)
		count += testOpt03_Type3_After(data);
	printElapsedTimeWithoutCR(prev_time);
	printf("  count=%d\n", count);
}

//----------------------------------------
//最適化④：除算の抑制：乗算に変更
void runTestOpt04()
{
	printf("----------------------------------------\n");
	printf("[Optimize Test 04]\n");

	//初期化
	dataOpt04_t data;
	initOpt04(data);

	//【タイプ１】
	extern void runTestOpt04_Type1(dataOpt04_t& data);
	runTestOpt04_Type1(data);
}
//【タイプ１】
void runTestOpt04_Type1(dataOpt04_t& data)
{
	printf("Type1: *repeated * %d times.\n", LOOP_OPT04_TYPE1);
	extern void runTestOpt04_Type1_Before(dataOpt04_t& data);
	extern void runTestOpt04_Type1_After1(dataOpt04_t& data);
	extern void runTestOpt04_Type1_After2(dataOpt04_t& data);
	runTestOpt04_Type1_Before(data);
	runTestOpt04_Type1_After1(data);
	runTestOpt04_Type1_After2(data);
}
//最適化前
void runTestOpt04_Type1_Before(dataOpt04_t& data)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT04_TYPE1; ++loop)
		testOpt04_Type1_Before(data);
	printElapsedTime(prev_time);
}
//最適化後１
void runTestOpt04_Type1_After1(dataOpt04_t& data)
{
	printf("  After1   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT04_TYPE1; ++loop)
		testOpt04_Type1_After1(data);
	printElapsedTime(prev_time);
}
//最適化後２
void runTestOpt04_Type1_After2(dataOpt04_t& data)
{
	printf("  After2   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT04_TYPE1; ++loop)
		testOpt04_Type1_After2(data);
	printElapsedTime(prev_time);
}

//----------------------------------------
//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更
void runTestOpt05()
{
	printf("----------------------------------------\n");
	printf("[Optimize Test 05]\n");

	//【タイプ１】
	extern void runTestOpt05_Type1();
	runTestOpt05_Type1();
}
//【タイプ１】
void runTestOpt05_Type1()
{
	printf("Type1: *repeated * %d times.\n", LOOP_OPT05_TYPE1);
	extern void runTestOpt05_Type1_Before();
	extern void runTestOpt05_Type1_After();
	runTestOpt05_Type1_Before();
	runTestOpt05_Type1_After();
}
//最適化前
void runTestOpt05_Type1_Before()
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	int sum = 0;
	for (int loop = 0; loop < LOOP_OPT05_TYPE1; ++loop)
	{
		int m2, m3, m4, m5, m10, m16, m24;
		int d2, d3, d4, d5, d10, d16, d24;
		int r2, r3, r4, r5, r10, r16, r24;
		sum += testOpt05_Type1_Before(loop, m2, m3, m4, m5, m10, m16, m24,
		                                    d2, d3, d4, d5, d10, d16, d24,
		                                    r2, r3, r4, r5, r10, r16, r24);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt05_Type1_After()
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	int sum = 0;
	for (int loop = 0; loop < LOOP_OPT05_TYPE1; ++loop)
	{
		int m2, m3, m4, m5, m10, m16, m24;
		int d2, d3, d4, d5, d10, d16, d24;
		int r2, r3, r4, r5, r10, r16, r24;
		sum += testOpt05_Type1_After(loop, m2, m3, m4, m5, m10, m16, m24,
		                                   d2, d3, d4, d5, d10, d16, d24,
		                                   r2, r3, r4, r5, r10, r16, r24);
	}
	printElapsedTime(prev_time);
}

//----------------------------------------
//最適化⑥：乗算／除算の抑制：演算の共通化
void runTestOpt06()
{
	printf("----------------------------------------\n");
	printf("[Optimize Test 06]\n");

	//初期化
	dataOpt06_t data;
	initOpt06(data);
	
	//係数初期化
	std::mt19937 rnd_engine;
	auto rnd = [&rnd_engine]() -> float
	{
		std::uniform_real_distribution<float> dist(0.f, 10.f);
		return dist(rnd_engine);
	};
	const float mul1 = rnd();
	const float mul2 = rnd();
	const float div = rnd();

	//【タイプ１】
	extern void runTestOpt06_Type1(dataOpt06_t& data, const float mul1, const float mul2, const float div);
	runTestOpt06_Type1(data, mul1, mul2, div);
}
//【タイプ１】
void runTestOpt06_Type1(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	printf("Type1: *repeated * %d times.\n", LOOP_OPT06_TYPE1);
	extern void runTestOpt06_Type1_Before(dataOpt06_t& data, const float mul1, const float mul2, const float div);
	extern void runTestOpt06_Type1_After(dataOpt06_t& data, const float mul1, const float mul2, const float div);
	runTestOpt06_Type1_Before(data, mul1, mul2, div);
	runTestOpt06_Type1_After(data, mul1, mul2, div);
}
//最適化前
void runTestOpt06_Type1_Before(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT06_TYPE1; ++loop)
		testOpt06_Type1_Before(data, mul1, mul2, div);
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt06_Type1_After(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT06_TYPE1; ++loop)
		testOpt06_Type1_After(data, mul1, mul2, div);
	printElapsedTime(prev_time);
}

//----------------------------------------
//最適化⑦：SIMD演算を活用する
void runTestOpt07()
{
	printf("----------------------------------------\n");
	printf("[Optimize Test 07]\n");

	//【タイプ１】
	extern void runTestOpt07_Type1();
	runTestOpt07_Type1();

	//【タイプ２】
	extern void runTestOpt07_Type2_strlen();
	extern void runTestOpt07_Type2_strcmp();
	extern void runTestOpt07_Type2_strncmp();
	extern void runTestOpt07_Type2_strchr();
	extern void runTestOpt07_Type2_strrchr();
	extern void runTestOpt07_Type2_strstr();
	extern void runTestOpt07_Type2_strcpy();
	extern void runTestOpt07_Type2_strncpy();
	runTestOpt07_Type2_strlen();
	runTestOpt07_Type2_strcmp();
	runTestOpt07_Type2_strncmp();
	runTestOpt07_Type2_strchr();
	runTestOpt07_Type2_strrchr();
	runTestOpt07_Type2_strstr();
	runTestOpt07_Type2_strcpy();
	runTestOpt07_Type2_strncpy();
}
//【タイプ１】
void runTestOpt07_Type1()
{
	printf("Type1: *repeated * %d times.\n", LOOP_OPT07_TYPE1);
	extern void runTestOpt07_Type1_Before();
	extern void runTestOpt07_Type1_After();
	runTestOpt07_Type1_Before();
	runTestOpt07_Type1_After();
}
//最適化前
void runTestOpt07_Type1_Before()
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	{
		matrix4x4 add0;
		matrix4x4 mul0a;
		matrix4x4 mul0b;
		matrix4x4 add1;
		matrix4x4 add2;
		matrix4x4 mul1a;
		const float mul2a = 5.f;
		matrix4x4 mul1b;
		matrix4x4 mul2b;
		float _add1 = 0.f;
		float _add2 = 100.f;
		float _mul1a = 0.f;
		float _mul1b = 0.f;
		float _mul2b = 100.f;
		for (int n = 0; n < 4; ++n)
		{
			for (int m = 0; m < 4; ++m)
			{
				add1(n, m) = _add1;
				add2(n, m) = _add2;
				mul1a(n, m) = _mul1a;
				mul1b(n, m) = _mul1b;
				mul2b(n, m) = _mul2b;
				_add1 += 1.f;
				_add2 += 1.f;
				_mul1a += 1.f;
				_mul1b += 1.f;
				_mul2b += 1.f;
			}
		}
		for (int loop = 0; loop < LOOP_OPT07_TYPE1; ++loop)
		{
			testOpt07_Type1_Before(loop, add0, mul0a, mul0b, add1, add2, mul1a, mul2a, mul1b, mul2b);
		}
	}
	{
		matrix1x4 add0;
		matrix1x4 mul0a;
		matrix1x4 mul0b;
		matrix1x4 add1;
		matrix1x4 add2;
		matrix1x4 mul1a;
		const float mul2a = 5.f;
		matrix1x3 mul1b;
		matrix3x4 mul2b;
		float _add1 = 0.f;
		float _add2 = 100.f;
		float _mul1a = 0.f;
		float _mul1b = 0.f;
		float _mul2b = 100.f;
		for (int n = 0; n < 1; ++n)
		{
			for (int m = 0; m < 4; ++m)
			{
				add1(n, m) = _add1;
				add2(n, m) = _add2;
				mul1a(n, m) = _mul1a;
				_add1 += 1.f;
				_add2 += 1.f;
				_mul1a += 1.f;
			}
		}
		for (int n = 0; n < 1; ++n)
		{
			for (int m = 0; m < 3; ++m)
			{
				mul1b(n, m) = _mul1b;
				_mul1b += 1.f;
			}
		}
		for (int n = 0; n < 3; ++n)
		{
			for (int m = 0; m < 4; ++m)
			{
				mul2b(n, m) = _mul2b;
				_mul2b += 1.f;
			}
		}
		for (int loop = 0; loop < LOOP_OPT07_TYPE1; ++loop)
		{
			testOpt07_Type1_Before(loop, add0, mul0a, mul0b, add1, add2, mul1a, mul2a, mul1b, mul2b);
		}
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type1_After()
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	{
		matrix4x4 add0;
		matrix4x4 mul0a;
		matrix4x4 mul0b;
		matrix4x4 add1;
		matrix4x4 add2;
		matrix4x4 mul1a;
		const float mul2a = 5.f;
		matrix4x4 mul1b;
		matrix4x4 mul2b;
		float _add1 = 0.f;
		float _add2 = 100.f;
		float _mul1a = 0.f;
		float _mul1b = 0.f;
		float _mul2b = 100.f;
		for (int n = 0; n < 4; ++n)
		{
			for (int m = 0; m < 4; ++m)
			{
				add1(n, m) = _add1;
				add2(n, m) = _add2;
				mul1a(n, m) = _mul1a;
				mul1b(n, m) = _mul1b;
				mul2b(n, m) = _mul2b;
				_add1 += 1.f;
				_add2 += 1.f;
				_mul1a += 1.f;
				_mul1b += 1.f;
				_mul2b += 1.f;
			}
		}
		for (int loop = 0; loop < LOOP_OPT07_TYPE1; ++loop)
		{
			testOpt07_Type1_After(loop, add0, mul0a, mul0b, add1, add2, mul1a, mul2a, mul1b, mul2b);
		}
	}
	{
		matrix1x4 add0;
		matrix1x4 mul0a;
		matrix1x4 mul0b;
		matrix1x4 add1;
		matrix1x4 add2;
		matrix1x4 mul1a;
		const float mul2a = 5.f;
		matrix1x3 mul1b;
		matrix3x4 mul2b;
		float _add1 = 0.f;
		float _add2 = 100.f;
		float _mul1a = 0.f;
		float _mul1b = 0.f;
		float _mul2b = 100.f;
		for (int n = 0; n < 1; ++n)
		{
			for (int m = 0; m < 4; ++m)
			{
				add1(n, m) = _add1;
				add2(n, m) = _add2;
				mul1a(n, m) = _mul1a;
				_add1 += 1.f;
				_add2 += 1.f;
				_mul1a += 1.f;
			}
		}
		for (int n = 0; n < 1; ++n)
		{
			for (int m = 0; m < 3; ++m)
			{
				mul1b(n, m) = _mul1b;
				_mul1b += 1.f;
			}
		}
		for (int n = 0; n < 3; ++n)
		{
			for (int m = 0; m < 4; ++m)
			{
				mul2b(n, m) = _mul2b;
				_mul2b += 1.f;
			}
		}
		for (int loop = 0; loop < LOOP_OPT07_TYPE1; ++loop)
		{
			testOpt07_Type1_After(loop, add0, mul0a, mul0b, add1, add2, mul1a, mul2a, mul1b, mul2b);
		}
	}
	printElapsedTime(prev_time);
}
//【タイプ２】(strlen)
void runTestOpt07_Type2_strlen()
{
	printf("Type2(strlen): *repeated * %d times.\n", LOOP_OPT07_TYPE2);
	
	const char* str_a = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str_b = "1234567890abcdefg";
	const char* str_c = "1234567890abcdef";
	const char* str_d = "123";
	const char* str_e = "";
	
	extern void runTestOpt07_Type2_strlen_Before(const char* str_a,
		                                         const char* str_b,
												 const char* str_c,
												 const char* str_d,
												 const char* str_e);
	extern void runTestOpt07_Type2_strlen_After(const char* str_a,
		                                        const char* str_b,
												const char* str_c,
												const char* str_d,
												const char* str_e);
	runTestOpt07_Type2_strlen_Before(str_a,
		                             str_b,
									 str_c,
									 str_d,
									 str_e);
	runTestOpt07_Type2_strlen_After(str_a,
		                            str_b,
									str_c,
									str_d,
									str_e);
}
//最適化前
void runTestOpt07_Type2_strlen_Before(const char* str_a, const char* str_b, const char* str_c, const char* str_d, const char* str_e)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strlen_Before(loop, str_a);
		testOpt07_Type2_strlen_Before(loop, str_b);
		testOpt07_Type2_strlen_Before(loop, str_c);
		testOpt07_Type2_strlen_Before(loop, str_d);
		testOpt07_Type2_strlen_Before(loop, str_e);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_strlen_After(const char* str_a, const char* str_b, const char* str_c, const char* str_d, const char* str_e)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strlen_After(loop, str_a);
		testOpt07_Type2_strlen_After(loop, str_b);
		testOpt07_Type2_strlen_After(loop, str_c);
		testOpt07_Type2_strlen_After(loop, str_d);
		testOpt07_Type2_strlen_After(loop, str_e);
	}
	printElapsedTime(prev_time);
}
//【タイプ２】(strcmp)
void runTestOpt07_Type2_strcmp()
{
	printf("Type2(strcmp): *repeated * %d times.\n", LOOP_OPT07_TYPE2);

	const char* str_a1 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str_a2 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str_b1 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str_b2 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_!";
	const char* str_c1 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_!";
	const char* str_c2 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str_d1 = "1234567890abcdef";
	const char* str_d2 = "1234567890abcdef";
	const char* str_e1 = "1234567890abcdef";
	const char* str_e2 = "1234567890abcdef!";
	const char* str_f1 = "1234567890abcdef!";
	const char* str_f2 = "1234567890abcdef";
	const char* str_g1 = "123";
	const char* str_g2 = "123";
	const char* str_h1 = "123";
	const char* str_h2 = "123!";
	const char* str_i1 = "123!";
	const char* str_i2 = "123";
	const char* str_j1 = "";
	const char* str_j2 = "";

	extern void runTestOpt07_Type2_strcmp_Before(const char* str_a1, const char* str_a2,
		                                         const char* str_b1, const char* str_b2,
												 const char* str_c1, const char* str_c2,
												 const char* str_d1, const char* str_d2,
												 const char* str_e1, const char* str_e2,
												 const char* str_f1, const char* str_f2,
												 const char* str_g1, const char* str_g2,
												 const char* str_h1, const char* str_h2,
												 const char* str_i1, const char* str_i2,
												 const char* str_j1, const char* str_j2);
	extern void runTestOpt07_Type2_strcmp_After(const char* str_a1, const char* str_a2,
		                                        const char* str_b1, const char* str_b2,
												const char* str_c1, const char* str_c2,
												const char* str_d1, const char* str_d2,
												const char* str_e1, const char* str_e2,
												const char* str_f1, const char* str_f2,
												const char* str_g1, const char* str_g2,
												const char* str_h1, const char* str_h2,
												const char* str_i1, const char* str_i2,
												const char* str_j1, const char* str_j2);
	runTestOpt07_Type2_strcmp_Before(str_a1, str_a2,
		                             str_b1, str_b2,
									 str_c1, str_c2,
									 str_d1, str_d2,
									 str_e1, str_e2,
									 str_f1, str_f2,
									 str_g1, str_g2,
									 str_h1, str_h2,
									 str_i1, str_i2,
									 str_j1, str_j2);
	runTestOpt07_Type2_strcmp_After(str_a1, str_a2,
		                            str_b1, str_b2,
									str_c1, str_c2,
									str_d1, str_d2,
									str_e1, str_e2,
									str_f1, str_f2,
									str_g1, str_g2,
									str_h1, str_h2,
									str_i1, str_i2,
									str_j1, str_j2);
}
//最適化前
void runTestOpt07_Type2_strcmp_Before(const char* str_a1, const char* str_a2,
	                                  const char* str_b1, const char* str_b2,
									  const char* str_c1, const char* str_c2,
									  const char* str_d1, const char* str_d2,
									  const char* str_e1, const char* str_e2,
									  const char* str_f1, const char* str_f2,
									  const char* str_g1, const char* str_g2,
									  const char* str_h1, const char* str_h2,
									  const char* str_i1, const char* str_i2,
									  const char* str_j1, const char* str_j2)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strcmp_Before(loop, str_a1, str_a2);
		testOpt07_Type2_strcmp_Before(loop, str_b1, str_b2);
		testOpt07_Type2_strcmp_Before(loop, str_c1, str_c2);
		testOpt07_Type2_strcmp_Before(loop, str_d1, str_d2);
		testOpt07_Type2_strcmp_Before(loop, str_e1, str_e2);
		testOpt07_Type2_strcmp_Before(loop, str_f1, str_f2);
		testOpt07_Type2_strcmp_Before(loop, str_g1, str_g2);
		testOpt07_Type2_strcmp_Before(loop, str_h1, str_h2);
		testOpt07_Type2_strcmp_Before(loop, str_i1, str_i2);
		testOpt07_Type2_strcmp_Before(loop, str_j1, str_j2);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_strcmp_After(const char* str_a1, const char* str_a2,
	                                 const char* str_b1, const char* str_b2,
									 const char* str_c1, const char* str_c2,
									 const char* str_d1, const char* str_d2,
									 const char* str_e1, const char* str_e2,
									 const char* str_f1, const char* str_f2,
									 const char* str_g1, const char* str_g2,
									 const char* str_h1, const char* str_h2,
									 const char* str_i1, const char* str_i2,
									 const char* str_j1, const char* str_j2)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strcmp_After(loop, str_a1, str_a2);
		testOpt07_Type2_strcmp_After(loop, str_b1, str_b2);
		testOpt07_Type2_strcmp_After(loop, str_c1, str_c2);
		testOpt07_Type2_strcmp_After(loop, str_d1, str_d2);
		testOpt07_Type2_strcmp_After(loop, str_e1, str_e2);
		testOpt07_Type2_strcmp_After(loop, str_f1, str_f2);
		testOpt07_Type2_strcmp_After(loop, str_g1, str_g2);
		testOpt07_Type2_strcmp_After(loop, str_h1, str_h2);
		testOpt07_Type2_strcmp_After(loop, str_i1, str_i2);
		testOpt07_Type2_strcmp_After(loop, str_j1, str_j2);
	}
	printElapsedTime(prev_time);
}
//【タイプ２】(strncmp)
void runTestOpt07_Type2_strncmp()
{
	printf("Type2(strncmp): *repeated * %d times.\n", LOOP_OPT07_TYPE2);

	const char* str_a1 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str_a2 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const std::size_t max_len_a1 = 171;
	const std::size_t max_len_a2 = 170;
	const std::size_t max_len_a3 = 169;
	const char* str_b1 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str_b2 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_!";
	const std::size_t max_len_b1 = 171;
	const std::size_t max_len_b2 = 170;
	const std::size_t max_len_b3 = 169;
	const char* str_c1 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_!";
	const char* str_c2 = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const std::size_t max_len_c1 = 171;
	const std::size_t max_len_c2 = 170;
	const std::size_t max_len_c3 = 169;
	const char* str_d1 = "1234567890abcdef";
	const char* str_d2 = "1234567890abcdef";
	const std::size_t max_len_d1 = 17;
	const std::size_t max_len_d2 = 16;
	const std::size_t max_len_d3 = 15;
	const char* str_e1 = "1234567890abcdef";
	const char* str_e2 = "1234567890abcdef!";
	const std::size_t max_len_e1 = 17;
	const std::size_t max_len_e2 = 16;
	const std::size_t max_len_e3 = 15;
	const char* str_f1 = "1234567890abcdef!";
	const char* str_f2 = "1234567890abcdef";
	const std::size_t max_len_f1 = 17;
	const std::size_t max_len_f2 = 16;
	const std::size_t max_len_f3 = 15;
	const char* str_g1 = "123";
	const char* str_g2 = "123";
	const std::size_t max_len_g1 = 4;
	const std::size_t max_len_g2 = 3;
	const std::size_t max_len_g3 = 2;
	const char* str_h1 = "123";
	const char* str_h2 = "123!";
	const std::size_t max_len_h1 = 4;
	const std::size_t max_len_h2 = 3;
	const std::size_t max_len_h3 = 2;
	const char* str_i1 = "123!";
	const char* str_i2 = "123";
	const std::size_t max_len_i1 = 4;
	const std::size_t max_len_i2 = 3;
	const std::size_t max_len_i3 = 2;
	const char* str_j1 = "";
	const char* str_j2 = "";
	const std::size_t max_len_j1 = 2;
	const std::size_t max_len_j2 = 1;
	const std::size_t max_len_j3 = 0;

	extern void runTestOpt07_Type2_strncmp_Before(const char* str_a1, const char* str_a2, const std::size_t max_len_a1, const std::size_t max_len_a2, const std::size_t max_len_a3,
		                                          const char* str_b1, const char* str_b2, const std::size_t max_len_b1, const std::size_t max_len_b2, const std::size_t max_len_b3,
												  const char* str_c1, const char* str_c2, const std::size_t max_len_c1, const std::size_t max_len_c2, const std::size_t max_len_c3,
												  const char* str_d1, const char* str_d2, const std::size_t max_len_d1, const std::size_t max_len_d2, const std::size_t max_len_d3,
												  const char* str_e1, const char* str_e2, const std::size_t max_len_e1, const std::size_t max_len_e2, const std::size_t max_len_e3,
												  const char* str_f1, const char* str_f2, const std::size_t max_len_f1, const std::size_t max_len_f2, const std::size_t max_len_f3,
												  const char* str_g1, const char* str_g2, const std::size_t max_len_g1, const std::size_t max_len_g2, const std::size_t max_len_g3,
												  const char* str_h1, const char* str_h2, const std::size_t max_len_h1, const std::size_t max_len_h2, const std::size_t max_len_h3,
												  const char* str_i1, const char* str_i2, const std::size_t max_len_i1, const std::size_t max_len_i2, const std::size_t max_len_i3,
												  const char* str_j1, const char* str_j2, const std::size_t max_len_j1, const std::size_t max_len_j2, const std::size_t max_len_j3);
	extern void runTestOpt07_Type2_strncmp_After(const char* str_a1, const char* str_a2, const std::size_t max_len_a1, const std::size_t max_len_a2, const std::size_t max_len_a3,
		                                         const char* str_b1, const char* str_b2, const std::size_t max_len_b1, const std::size_t max_len_b2, const std::size_t max_len_b3,
												 const char* str_c1, const char* str_c2, const std::size_t max_len_c1, const std::size_t max_len_c2, const std::size_t max_len_c3,
												 const char* str_d1, const char* str_d2, const std::size_t max_len_d1, const std::size_t max_len_d2, const std::size_t max_len_d3,
												 const char* str_e1, const char* str_e2, const std::size_t max_len_e1, const std::size_t max_len_e2, const std::size_t max_len_e3,
												 const char* str_f1, const char* str_f2, const std::size_t max_len_f1, const std::size_t max_len_f2, const std::size_t max_len_f3,
												 const char* str_g1, const char* str_g2, const std::size_t max_len_g1, const std::size_t max_len_g2, const std::size_t max_len_g3,
												 const char* str_h1, const char* str_h2, const std::size_t max_len_h1, const std::size_t max_len_h2, const std::size_t max_len_h3,
												 const char* str_i1, const char* str_i2, const std::size_t max_len_i1, const std::size_t max_len_i2, const std::size_t max_len_i3,
												 const char* str_j1, const char* str_j2, const std::size_t max_len_j1, const std::size_t max_len_j2, const std::size_t max_len_j3);
	runTestOpt07_Type2_strncmp_Before(str_a1, str_a2, max_len_a1, max_len_a2, max_len_a3,
	                                  str_b1, str_b2, max_len_b1, max_len_b2, max_len_b3,
									  str_c1, str_c2, max_len_c1, max_len_c2, max_len_c3,
									  str_d1, str_d2, max_len_d1, max_len_d2, max_len_d3,
									  str_e1, str_e2, max_len_e1, max_len_e2, max_len_e3,
									  str_f1, str_f2, max_len_f1, max_len_f2, max_len_f3,
									  str_g1, str_g2, max_len_g1, max_len_g2, max_len_g3,
									  str_h1, str_h2, max_len_h1, max_len_h2, max_len_h3,
									  str_i1, str_i2, max_len_i1, max_len_i2, max_len_i3,
									  str_j1, str_j2, max_len_j1, max_len_j2, max_len_j3);
	runTestOpt07_Type2_strncmp_After(str_a1, str_a2, max_len_a1, max_len_a2, max_len_a3,
	                                 str_b1, str_b2, max_len_b1, max_len_b2, max_len_b3,
									 str_c1, str_c2, max_len_c1, max_len_c2, max_len_c3,
									 str_d1, str_d2, max_len_d1, max_len_d2, max_len_d3,
									 str_e1, str_e2, max_len_e1, max_len_e2, max_len_e3,
									 str_f1, str_f2, max_len_f1, max_len_f2, max_len_f3,
									 str_g1, str_g2, max_len_g1, max_len_g2, max_len_g3,
									 str_h1, str_h2, max_len_h1, max_len_h2, max_len_h3,
									 str_i1, str_i2, max_len_i1, max_len_i2, max_len_i3,
									 str_j1, str_j2, max_len_j1, max_len_j2, max_len_j3);
}
//最適化前
void runTestOpt07_Type2_strncmp_Before(const char* str_a1, const char* str_a2, const std::size_t max_len_a1, const std::size_t max_len_a2, const std::size_t max_len_a3,
	                                   const char* str_b1, const char* str_b2, const std::size_t max_len_b1, const std::size_t max_len_b2, const std::size_t max_len_b3,
									   const char* str_c1, const char* str_c2, const std::size_t max_len_c1, const std::size_t max_len_c2, const std::size_t max_len_c3,
									   const char* str_d1, const char* str_d2, const std::size_t max_len_d1, const std::size_t max_len_d2, const std::size_t max_len_d3,
									   const char* str_e1, const char* str_e2, const std::size_t max_len_e1, const std::size_t max_len_e2, const std::size_t max_len_e3,
									   const char* str_f1, const char* str_f2, const std::size_t max_len_f1, const std::size_t max_len_f2, const std::size_t max_len_f3,
									   const char* str_g1, const char* str_g2, const std::size_t max_len_g1, const std::size_t max_len_g2, const std::size_t max_len_g3,
									   const char* str_h1, const char* str_h2, const std::size_t max_len_h1, const std::size_t max_len_h2, const std::size_t max_len_h3,
									   const char* str_i1, const char* str_i2, const std::size_t max_len_i1, const std::size_t max_len_i2, const std::size_t max_len_i3,
									   const char* str_j1, const char* str_j2, const std::size_t max_len_j1, const std::size_t max_len_j2, const std::size_t max_len_j3)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strncmp_Before(loop, str_a1, str_a2, max_len_a1);
		testOpt07_Type2_strncmp_Before(loop, str_a1, str_a2, max_len_a2);
		testOpt07_Type2_strncmp_Before(loop, str_a1, str_a2, max_len_a3);
		testOpt07_Type2_strncmp_Before(loop, str_b1, str_b2, max_len_b1);
		testOpt07_Type2_strncmp_Before(loop, str_b1, str_b2, max_len_b2);
		testOpt07_Type2_strncmp_Before(loop, str_b1, str_b2, max_len_b3);
		testOpt07_Type2_strncmp_Before(loop, str_c1, str_c2, max_len_c1);
		testOpt07_Type2_strncmp_Before(loop, str_c1, str_c2, max_len_c2);
		testOpt07_Type2_strncmp_Before(loop, str_c1, str_c2, max_len_c3);
		testOpt07_Type2_strncmp_Before(loop, str_d1, str_d2, max_len_d1);
		testOpt07_Type2_strncmp_Before(loop, str_d1, str_d2, max_len_d2);
		testOpt07_Type2_strncmp_Before(loop, str_d1, str_d2, max_len_d3);
		testOpt07_Type2_strncmp_Before(loop, str_e1, str_e2, max_len_e1);
		testOpt07_Type2_strncmp_Before(loop, str_e1, str_e2, max_len_e2);
		testOpt07_Type2_strncmp_Before(loop, str_e1, str_e2, max_len_e3);
		testOpt07_Type2_strncmp_Before(loop, str_f1, str_f2, max_len_f1);
		testOpt07_Type2_strncmp_Before(loop, str_f1, str_f2, max_len_f2);
		testOpt07_Type2_strncmp_Before(loop, str_f1, str_f2, max_len_f3);
		testOpt07_Type2_strncmp_Before(loop, str_g1, str_g2, max_len_g1);
		testOpt07_Type2_strncmp_Before(loop, str_g1, str_g2, max_len_g2);
		testOpt07_Type2_strncmp_Before(loop, str_g1, str_g2, max_len_g3);
		testOpt07_Type2_strncmp_Before(loop, str_h1, str_h2, max_len_h1);
		testOpt07_Type2_strncmp_Before(loop, str_h1, str_h2, max_len_h2);
		testOpt07_Type2_strncmp_Before(loop, str_h1, str_h2, max_len_h3);
		testOpt07_Type2_strncmp_Before(loop, str_i1, str_i2, max_len_i1);
		testOpt07_Type2_strncmp_Before(loop, str_i1, str_i2, max_len_i2);
		testOpt07_Type2_strncmp_Before(loop, str_i1, str_i2, max_len_i3);
		testOpt07_Type2_strncmp_Before(loop, str_j1, str_j2, max_len_j1);
		testOpt07_Type2_strncmp_Before(loop, str_j1, str_j2, max_len_j2);
		testOpt07_Type2_strncmp_Before(loop, str_j1, str_j2, max_len_j3);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_strncmp_After(const char* str_a1, const char* str_a2, const std::size_t max_len_a1, const std::size_t max_len_a2, const std::size_t max_len_a3,
	                                  const char* str_b1, const char* str_b2, const std::size_t max_len_b1, const std::size_t max_len_b2, const std::size_t max_len_b3,
									  const char* str_c1, const char* str_c2, const std::size_t max_len_c1, const std::size_t max_len_c2, const std::size_t max_len_c3,
									  const char* str_d1, const char* str_d2, const std::size_t max_len_d1, const std::size_t max_len_d2, const std::size_t max_len_d3,
									  const char* str_e1, const char* str_e2, const std::size_t max_len_e1, const std::size_t max_len_e2, const std::size_t max_len_e3,
									  const char* str_f1, const char* str_f2, const std::size_t max_len_f1, const std::size_t max_len_f2, const std::size_t max_len_f3,
									  const char* str_g1, const char* str_g2, const std::size_t max_len_g1, const std::size_t max_len_g2, const std::size_t max_len_g3,
									  const char* str_h1, const char* str_h2, const std::size_t max_len_h1, const std::size_t max_len_h2, const std::size_t max_len_h3,
									  const char* str_i1, const char* str_i2, const std::size_t max_len_i1, const std::size_t max_len_i2, const std::size_t max_len_i3,
									  const char* str_j1, const char* str_j2, const std::size_t max_len_j1, const std::size_t max_len_j2, const std::size_t max_len_j3)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strncmp_After(loop, str_a1, str_a2, max_len_a1);
		testOpt07_Type2_strncmp_After(loop, str_a1, str_a2, max_len_a2);
		testOpt07_Type2_strncmp_After(loop, str_a1, str_a2, max_len_a3);
		testOpt07_Type2_strncmp_After(loop, str_b1, str_b2, max_len_b1);
		testOpt07_Type2_strncmp_After(loop, str_b1, str_b2, max_len_b2);
		testOpt07_Type2_strncmp_After(loop, str_b1, str_b2, max_len_b3);
		testOpt07_Type2_strncmp_After(loop, str_c1, str_c2, max_len_c1);
		testOpt07_Type2_strncmp_After(loop, str_c1, str_c2, max_len_c2);
		testOpt07_Type2_strncmp_After(loop, str_c1, str_c2, max_len_c3);
		testOpt07_Type2_strncmp_After(loop, str_d1, str_d2, max_len_d1);
		testOpt07_Type2_strncmp_After(loop, str_d1, str_d2, max_len_d2);
		testOpt07_Type2_strncmp_After(loop, str_d1, str_d2, max_len_d3);
		testOpt07_Type2_strncmp_After(loop, str_e1, str_e2, max_len_e1);
		testOpt07_Type2_strncmp_After(loop, str_e1, str_e2, max_len_e2);
		testOpt07_Type2_strncmp_After(loop, str_e1, str_e2, max_len_e3);
		testOpt07_Type2_strncmp_After(loop, str_f1, str_f2, max_len_f1);
		testOpt07_Type2_strncmp_After(loop, str_f1, str_f2, max_len_f2);
		testOpt07_Type2_strncmp_After(loop, str_f1, str_f2, max_len_f3);
		testOpt07_Type2_strncmp_After(loop, str_g1, str_g2, max_len_g1);
		testOpt07_Type2_strncmp_After(loop, str_g1, str_g2, max_len_g2);
		testOpt07_Type2_strncmp_After(loop, str_g1, str_g2, max_len_g3);
		testOpt07_Type2_strncmp_After(loop, str_h1, str_h2, max_len_h1);
		testOpt07_Type2_strncmp_After(loop, str_h1, str_h2, max_len_h2);
		testOpt07_Type2_strncmp_After(loop, str_h1, str_h2, max_len_h3);
		testOpt07_Type2_strncmp_After(loop, str_i1, str_i2, max_len_i1);
		testOpt07_Type2_strncmp_After(loop, str_i1, str_i2, max_len_i2);
		testOpt07_Type2_strncmp_After(loop, str_i1, str_i2, max_len_i3);
		testOpt07_Type2_strncmp_After(loop, str_j1, str_j2, max_len_j1);
		testOpt07_Type2_strncmp_After(loop, str_j1, str_j2, max_len_j2);
		testOpt07_Type2_strncmp_After(loop, str_j1, str_j2, max_len_j3);
	}
	printElapsedTime(prev_time);
}
//【タイプ２】(strchr)
void runTestOpt07_Type2_strchr()
{
	printf("Type2(strchr): *repeated * %d times.\n", LOOP_OPT07_TYPE2);

	const char* str_a = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char c_a1 = '1';
	const char c_a2 = '!';
	const char c_a3 = '_';
	const char c_a4 = '.';
	const char* str_b = "1234567812345678";
	const char c_b1 = '1';
	const char c_b2 = '5';
	const char c_b3 = '8';
	const char c_b4 = '.';
	const char* str_c = "123123";
	const char c_c1 = '1';
	const char c_c2 = '2';
	const char c_c3 = '3';
	const char c_c4 = '.';
	const char* str_d = "";
	const char c_d1 = '1';
	const char c_d2 = '2';
	const char c_d3 = '3';
	const char c_d4 = '.';

	extern void runTestOpt07_Type2_strchr_Before(const char* str_a, const char c_a1, const char c_a2, const char c_a3, const char c_a4,
		                                         const char* str_b, const char c_b1, const char c_b2, const char c_b3, const char c_b4,
												 const char* str_c, const char c_c1, const char c_c2, const char c_c3, const char c_c4,
												 const char* str_d, const char c_d1, const char c_d2, const char c_d3, const char c_d4);
	extern void runTestOpt07_Type2_strchr_After(const char* str_a, const char c_a1, const char c_a2, const char c_a3, const char c_a4,
		                                        const char* str_b, const char c_b1, const char c_b2, const char c_b3, const char c_b4,
												const char* str_c, const char c_c1, const char c_c2, const char c_c3, const char c_c4,
												const char* str_d, const char c_d1, const char c_d2, const char c_d3, const char c_d4);
	runTestOpt07_Type2_strchr_Before(str_a, c_a1, c_a2, c_a3, c_a4,
		                             str_b, c_b1, c_b2, c_b3, c_b4,
									 str_c, c_c1, c_c2, c_c3, c_c4,
									 str_d, c_d1, c_d2, c_d3, c_d4);
	runTestOpt07_Type2_strchr_After(str_a, c_a1, c_a2, c_a3, c_a4,
		                            str_b, c_b1, c_b2, c_b3, c_b4,
									str_c, c_c1, c_c2, c_c3, c_c4,
									str_d, c_d1, c_d2, c_d3, c_d4);
}
//最適化前
void runTestOpt07_Type2_strchr_Before(const char* str_a, const char c_a1, const char c_a2, const char c_a3, const char c_a4,
		                              const char* str_b, const char c_b1, const char c_b2, const char c_b3, const char c_b4,
									  const char* str_c, const char c_c1, const char c_c2, const char c_c3, const char c_c4,
									  const char* str_d, const char c_d1, const char c_d2, const char c_d3, const char c_d4)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strchr_Before(loop, str_a, c_a1);
		testOpt07_Type2_strchr_Before(loop, str_a, c_a2);
		testOpt07_Type2_strchr_Before(loop, str_a, c_a3);
		testOpt07_Type2_strchr_Before(loop, str_a, c_a4);
		testOpt07_Type2_strchr_Before(loop, str_b, c_b1);
		testOpt07_Type2_strchr_Before(loop, str_b, c_b2);
		testOpt07_Type2_strchr_Before(loop, str_b, c_b3);
		testOpt07_Type2_strchr_Before(loop, str_b, c_b4);
		testOpt07_Type2_strchr_Before(loop, str_c, c_c1);
		testOpt07_Type2_strchr_Before(loop, str_c, c_c2);
		testOpt07_Type2_strchr_Before(loop, str_c, c_c3);
		testOpt07_Type2_strchr_Before(loop, str_c, c_c4);
		testOpt07_Type2_strchr_Before(loop, str_d, c_d1);
		testOpt07_Type2_strchr_Before(loop, str_d, c_d2);
		testOpt07_Type2_strchr_Before(loop, str_d, c_d3);
		testOpt07_Type2_strchr_Before(loop, str_d, c_d4);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_strchr_After(const char* str_a, const char c_a1, const char c_a2, const char c_a3, const char c_a4,
		                             const char* str_b, const char c_b1, const char c_b2, const char c_b3, const char c_b4,
									 const char* str_c, const char c_c1, const char c_c2, const char c_c3, const char c_c4,
									 const char* str_d, const char c_d1, const char c_d2, const char c_d3, const char c_d4)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strchr_After(loop, str_a, c_a1);
		testOpt07_Type2_strchr_After(loop, str_a, c_a2);
		testOpt07_Type2_strchr_After(loop, str_a, c_a3);
		testOpt07_Type2_strchr_After(loop, str_a, c_a4);
		testOpt07_Type2_strchr_After(loop, str_b, c_b1);
		testOpt07_Type2_strchr_After(loop, str_b, c_b2);
		testOpt07_Type2_strchr_After(loop, str_b, c_b3);
		testOpt07_Type2_strchr_After(loop, str_b, c_b4);
		testOpt07_Type2_strchr_After(loop, str_c, c_c1);
		testOpt07_Type2_strchr_After(loop, str_c, c_c2);
		testOpt07_Type2_strchr_After(loop, str_c, c_c3);
		testOpt07_Type2_strchr_After(loop, str_c, c_c4);
		testOpt07_Type2_strchr_After(loop, str_d, c_d1);
		testOpt07_Type2_strchr_After(loop, str_d, c_d2);
		testOpt07_Type2_strchr_After(loop, str_d, c_d3);
		testOpt07_Type2_strchr_After(loop, str_d, c_d4);
	}
	printElapsedTime(prev_time);
}
//【タイプ２】(strrchr)
void runTestOpt07_Type2_strrchr()
{
	printf("Type2(strrchr): *repeated * %d times.\n", LOOP_OPT07_TYPE2);

	const char* str_a = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char c_a1 = '1';
	const char c_a2 = '!';
	const char c_a3 = '_';
	const char c_a4 = '.';
	const char* str_b = "1234567812345678";
	const char c_b1 = '1';
	const char c_b2 = '5';
	const char c_b3 = '8';
	const char c_b4 = '.';
	const char* str_c = "123123";
	const char c_c1 = '1';
	const char c_c2 = '2';
	const char c_c3 = '3';
	const char c_c4 = '.';
	const char* str_d = "";
	const char c_d1 = '1';
	const char c_d2 = '2';
	const char c_d3 = '3';
	const char c_d4 = '.';

	extern void runTestOpt07_Type2_strrchr_Before(const char* str_a, const char c_a1, const char c_a2, const char c_a3, const char c_a4,
		                                          const char* str_b, const char c_b1, const char c_b2, const char c_b3, const char c_b4,
										 	 	  const char* str_c, const char c_c1, const char c_c2, const char c_c3, const char c_c4,
										 		  const char* str_d, const char c_d1, const char c_d2, const char c_d3, const char c_d4);
	extern void runTestOpt07_Type2_strrchr_After(const char* str_a, const char c_a1, const char c_a2, const char c_a3, const char c_a4,
		                                         const char* str_b, const char c_b1, const char c_b2, const char c_b3, const char c_b4,
												 const char* str_c, const char c_c1, const char c_c2, const char c_c3, const char c_c4,
												 const char* str_d, const char c_d1, const char c_d2, const char c_d3, const char c_d4);
	runTestOpt07_Type2_strrchr_Before(str_a, c_a1, c_a2, c_a3, c_a4,
		                              str_b, c_b1, c_b2, c_b3, c_b4,
									  str_c, c_c1, c_c2, c_c3, c_c4,
									  str_d, c_d1, c_d2, c_d3, c_d4);
	runTestOpt07_Type2_strrchr_After(str_a, c_a1, c_a2, c_a3, c_a4,
		                             str_b, c_b1, c_b2, c_b3, c_b4,
									 str_c, c_c1, c_c2, c_c3, c_c4,
									 str_d, c_d1, c_d2, c_d3, c_d4);
}
//最適化前
void runTestOpt07_Type2_strrchr_Before(const char* str_a, const char c_a1, const char c_a2, const char c_a3, const char c_a4,
		                               const char* str_b, const char c_b1, const char c_b2, const char c_b3, const char c_b4,
									   const char* str_c, const char c_c1, const char c_c2, const char c_c3, const char c_c4,
									   const char* str_d, const char c_d1, const char c_d2, const char c_d3, const char c_d4)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strrchr_Before(loop, str_a, c_a1);
		testOpt07_Type2_strrchr_Before(loop, str_a, c_a2);
		testOpt07_Type2_strrchr_Before(loop, str_a, c_a3);
		testOpt07_Type2_strrchr_Before(loop, str_a, c_a4);
		testOpt07_Type2_strrchr_Before(loop, str_b, c_b1);
		testOpt07_Type2_strrchr_Before(loop, str_b, c_b2);
		testOpt07_Type2_strrchr_Before(loop, str_b, c_b3);
		testOpt07_Type2_strrchr_Before(loop, str_b, c_b4);
		testOpt07_Type2_strrchr_Before(loop, str_c, c_c1);
		testOpt07_Type2_strrchr_Before(loop, str_c, c_c2);
		testOpt07_Type2_strrchr_Before(loop, str_c, c_c3);
		testOpt07_Type2_strrchr_Before(loop, str_c, c_c4);
		testOpt07_Type2_strrchr_Before(loop, str_d, c_d1);
		testOpt07_Type2_strrchr_Before(loop, str_d, c_d2);
		testOpt07_Type2_strrchr_Before(loop, str_d, c_d3);
		testOpt07_Type2_strrchr_Before(loop, str_d, c_d4);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_strrchr_After(const char* str_a, const char c_a1, const char c_a2, const char c_a3, const char c_a4,
		                              const char* str_b, const char c_b1, const char c_b2, const char c_b3, const char c_b4,
									  const char* str_c, const char c_c1, const char c_c2, const char c_c3, const char c_c4,
									  const char* str_d, const char c_d1, const char c_d2, const char c_d3, const char c_d4)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strrchr_After(loop, str_a, c_a1);
		testOpt07_Type2_strrchr_After(loop, str_a, c_a2);
		testOpt07_Type2_strrchr_After(loop, str_a, c_a3);
		testOpt07_Type2_strrchr_After(loop, str_a, c_a4);
		testOpt07_Type2_strrchr_After(loop, str_b, c_b1);
		testOpt07_Type2_strrchr_After(loop, str_b, c_b2);
		testOpt07_Type2_strrchr_After(loop, str_b, c_b3);
		testOpt07_Type2_strrchr_After(loop, str_b, c_b4);
		testOpt07_Type2_strrchr_After(loop, str_c, c_c1);
		testOpt07_Type2_strrchr_After(loop, str_c, c_c2);
		testOpt07_Type2_strrchr_After(loop, str_c, c_c3);
		testOpt07_Type2_strrchr_After(loop, str_c, c_c4);
		testOpt07_Type2_strrchr_After(loop, str_d, c_d1);
		testOpt07_Type2_strrchr_After(loop, str_d, c_d2);
		testOpt07_Type2_strrchr_After(loop, str_d, c_d3);
		testOpt07_Type2_strrchr_After(loop, str_d, c_d4);
	}
	printElapsedTime(prev_time);
}
//【タイプ２】(strstr)
void runTestOpt07_Type2_strstr()
{
	printf("Type2(strstr): *repeated * %d times.\n", LOOP_OPT07_TYPE2);

	const char* str_a = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str_a1 = "1";
	const char* str_a2 = "12";
	const char* str_a3 = "1x";
	const char* str_a4 = "1234567980!abcde";
	const char* str_a5 = "1234567980!abcdef";
	const char* str_a6 = "1234567980!abcdx";
	const char* str_a7 = "1234567980!abcdefx";
	const char* str_a8 = "A";
	const char* str_a9 = "AB";
	const char* str_a10 = "ABCDEFGHIJKLMNOP";
	const char* str_a11 = "ABCDEFGHIJKLMNOPQ";
	const char* str_a12 = "ABCDEFGHIJKLMNOx";
	const char* str_a13 = "ABCDEFGHIJKLMNOPx";
	const char* str_a14 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&(";
	const char* str_a15 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&(.";
	const char* str_a16 = ".";
	const char* str_b = "1234567812345678";
	const char* str_b1 = "1";
	const char* str_b2 = "12";
	const char* str_b3 = "1x";
	const char* str_b4 = "1234567812345678";
	const char* str_b5 = "1234567812345678x";
	const char* str_b6 = "8";
	const char* str_b7 = "78";
	const char* str_b8 = "678";
	const char* str_b9 = "7x";
	const char* str_b10 = "234567812345678";
	const char* str_b11 = ".";
	const char* str_c = "123123";
	const char* str_c1 = "1";
	const char* str_c2 = "12";
	const char* str_c3 = "1x";
	const char* str_c4 = "23";
	const char* str_c5 = ".";
	const char* str_d = "";
	const char* str_d1 = ".";

	extern void runTestOpt07_Type2_strstr_Before(const char* str_a, const char* str_a1, const char* str_a2, const char* str_a3, const char* str_a4, const char* str_a5, const char* str_a6, const char* str_a7, const char* str_a8, const char* str_a9, const char* str_a10, const char* str_a11, const char* str_a12, const char* str_a13, const char* str_a14, const char* str_a15, const char* str_a16,
	                                             const char* str_b, const char* str_b1, const char* str_b2, const char* str_b3, const char* str_b4, const char* str_b5, const char* str_b6, const char* str_b7, const char* str_b8, const char* str_b9, const char* str_b10, const char* str_b11,
												 const char* str_c, const char* str_c1, const char* str_c2, const char* str_c3, const char* str_c4, const char* str_c5,
										 		 const char* str_d, const char* str_d1);
	extern void runTestOpt07_Type2_strstr_After(const char* str_a, const char* str_a1, const char* str_a2, const char* str_a3, const char* str_a4, const char* str_a5, const char* str_a6, const char* str_a7, const char* str_a8, const char* str_a9, const char* str_a10, const char* str_a11, const char* str_a12, const char* str_a13, const char* str_a14, const char* str_a15, const char* str_a16,
	                                            const char* str_b, const char* str_b1, const char* str_b2, const char* str_b3, const char* str_b4, const char* str_b5, const char* str_b6, const char* str_b7, const char* str_b8, const char* str_b9, const char* str_b10, const char* str_b11,
												const char* str_c, const char* str_c1, const char* str_c2, const char* str_c3, const char* str_c4, const char* str_c5,
										 		const char* str_d, const char* str_d1);
	runTestOpt07_Type2_strstr_Before(str_a, str_a1, str_a2, str_a3, str_a4, str_a5, str_a6, str_a7, str_a8, str_a9, str_a10, str_a11, str_a12, str_a13, str_a14, str_a15, str_a16,
	                                 str_b, str_b1, str_b2, str_b3, str_b4, str_b5, str_b6, str_b7, str_b8, str_b9, str_b10, str_b11,
									 str_c, str_c1, str_c2, str_c3, str_c4, str_c5,
									 str_d, str_d1);
	runTestOpt07_Type2_strstr_After(str_a, str_a1, str_a2, str_a3, str_a4, str_a5, str_a6, str_a7, str_a8, str_a9, str_a10, str_a11, str_a12, str_a13, str_a14, str_a15, str_a16,
	                                str_b, str_b1, str_b2, str_b3, str_b4, str_b5, str_b6, str_b7, str_b8, str_b9, str_b10, str_b11,
									str_c, str_c1, str_c2, str_c3, str_c4, str_c5,
									str_d, str_d1);
}
//最適化前
void runTestOpt07_Type2_strstr_Before(const char* str_a, const char* str_a1, const char* str_a2, const char* str_a3, const char* str_a4, const char* str_a5, const char* str_a6, const char* str_a7, const char* str_a8, const char* str_a9, const char* str_a10, const char* str_a11, const char* str_a12, const char* str_a13, const char* str_a14, const char* str_a15, const char* str_a16,
	                                  const char* str_b, const char* str_b1, const char* str_b2, const char* str_b3, const char* str_b4, const char* str_b5, const char* str_b6, const char* str_b7, const char* str_b8, const char* str_b9, const char* str_b10, const char* str_b11,
									  const char* str_c, const char* str_c1, const char* str_c2, const char* str_c3, const char* str_c4, const char* str_c5,
									  const char* str_d, const char* str_d1)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strstr_Before(loop, str_a, str_a1);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a2);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a3);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a4);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a5);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a6);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a7);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a8);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a9);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a10);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a11);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a12);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a13);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a14);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a15);
		testOpt07_Type2_strstr_Before(loop, str_a, str_a16);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b1);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b2);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b3);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b4);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b5);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b6);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b7);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b8);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b9);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b10);
		testOpt07_Type2_strstr_Before(loop, str_b, str_b11);
		testOpt07_Type2_strstr_Before(loop, str_c, str_c1);
		testOpt07_Type2_strstr_Before(loop, str_c, str_c2);
		testOpt07_Type2_strstr_Before(loop, str_c, str_c3);
		testOpt07_Type2_strstr_Before(loop, str_c, str_c4);
		testOpt07_Type2_strstr_Before(loop, str_c, str_c5);
		testOpt07_Type2_strstr_Before(loop, str_d, str_d1);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_strstr_After(const char* str_a, const char* str_a1, const char* str_a2, const char* str_a3, const char* str_a4, const char* str_a5, const char* str_a6, const char* str_a7, const char* str_a8, const char* str_a9, const char* str_a10, const char* str_a11, const char* str_a12, const char* str_a13, const char* str_a14, const char* str_a15, const char* str_a16,
	                                 const char* str_b, const char* str_b1, const char* str_b2, const char* str_b3, const char* str_b4, const char* str_b5, const char* str_b6, const char* str_b7, const char* str_b8, const char* str_b9, const char* str_b10, const char* str_b11,
									 const char* str_c, const char* str_c1, const char* str_c2, const char* str_c3, const char* str_c4, const char* str_c5,
									 const char* str_d, const char* str_d1)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strstr_After(loop, str_a, str_a1);
		testOpt07_Type2_strstr_After(loop, str_a, str_a2);
		testOpt07_Type2_strstr_After(loop, str_a, str_a3);
		testOpt07_Type2_strstr_After(loop, str_a, str_a4);
		testOpt07_Type2_strstr_After(loop, str_a, str_a5);
		testOpt07_Type2_strstr_After(loop, str_a, str_a6);
		testOpt07_Type2_strstr_After(loop, str_a, str_a7);
		testOpt07_Type2_strstr_After(loop, str_a, str_a8);
		testOpt07_Type2_strstr_After(loop, str_a, str_a9);
		testOpt07_Type2_strstr_After(loop, str_a, str_a10);
		testOpt07_Type2_strstr_After(loop, str_a, str_a11);
		testOpt07_Type2_strstr_After(loop, str_a, str_a12);
		testOpt07_Type2_strstr_After(loop, str_a, str_a13);
		testOpt07_Type2_strstr_After(loop, str_a, str_a14);
		testOpt07_Type2_strstr_After(loop, str_a, str_a15);
		testOpt07_Type2_strstr_After(loop, str_a, str_a16);
		testOpt07_Type2_strstr_After(loop, str_b, str_b1);
		testOpt07_Type2_strstr_After(loop, str_b, str_b2);
		testOpt07_Type2_strstr_After(loop, str_b, str_b3);
		testOpt07_Type2_strstr_After(loop, str_b, str_b4);
		testOpt07_Type2_strstr_After(loop, str_b, str_b5);
		testOpt07_Type2_strstr_After(loop, str_b, str_b6);
		testOpt07_Type2_strstr_After(loop, str_b, str_b7);
		testOpt07_Type2_strstr_After(loop, str_b, str_b8);
		testOpt07_Type2_strstr_After(loop, str_b, str_b9);
		testOpt07_Type2_strstr_After(loop, str_b, str_b10);
		testOpt07_Type2_strstr_After(loop, str_b, str_b11);
		testOpt07_Type2_strstr_After(loop, str_c, str_c1);
		testOpt07_Type2_strstr_After(loop, str_c, str_c2);
		testOpt07_Type2_strstr_After(loop, str_c, str_c3);
		testOpt07_Type2_strstr_After(loop, str_c, str_c4);
		testOpt07_Type2_strstr_After(loop, str_c, str_c5);
		testOpt07_Type2_strstr_After(loop, str_d, str_d1);
	}
	printElapsedTime(prev_time);
}
//【タイプ２】(strcpy)
void runTestOpt07_Type2_strcpy()
{
	printf("Type2(strcpy): *repeated * %d times.\n", LOOP_OPT07_TYPE2);

	char dst[1024];
	const char* src_a = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* src_b = "1234567890abcdefg";
	const char* src_c = "1234567890abcdef";
	const char* src_d = "123";
	const char* src_e = "";

	extern void runTestOpt07_Type2_strcpy_Before(char* dst,
		                                         const char* src_a,
												 const char* src_b,
												 const char* src_c,
												 const char* src_d,
												 const char* src_e);
	extern void runTestOpt07_Type2_strcpy_After(char* dst,
		                                        const char* src_a,
												const char* src_b,
												const char* src_c,
												const char* src_d,
												const char* src_e);
	runTestOpt07_Type2_strcpy_Before(dst,
		                             src_a,
									 src_b,
									 src_c,
									 src_d,
									 src_e);
	runTestOpt07_Type2_strcpy_After(dst,
		                            src_a,
									src_b,
									src_c,
									src_d,
									src_e);
}
//最適化前
void runTestOpt07_Type2_strcpy_Before(char* dst, const char* src_a, const char* src_b, const char* src_c, const char* src_d, const char* src_e)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strcpy_Before(loop, dst, src_a);
		testOpt07_Type2_strcpy_Before(loop, dst, src_b);
		testOpt07_Type2_strcpy_Before(loop, dst, src_c);
		testOpt07_Type2_strcpy_Before(loop, dst, src_d);
		testOpt07_Type2_strcpy_Before(loop, dst, src_e);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_strcpy_After(char* dst, const char* src_a, const char* src_b, const char* src_c, const char* src_d, const char* src_e)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strcpy_After(loop, dst, src_a);
		testOpt07_Type2_strcpy_After(loop, dst, src_b);
		testOpt07_Type2_strcpy_After(loop, dst, src_c);
		testOpt07_Type2_strcpy_After(loop, dst, src_d);
		testOpt07_Type2_strcpy_After(loop, dst, src_e);
	}
	printElapsedTime(prev_time);
}
//【タイプ２】(strncpy)
void runTestOpt07_Type2_strncpy()
{
	printf("Type2(strncpy): *repeated * %d times.\n", LOOP_OPT07_TYPE2);

	char dst[1024];
	const char* src_a = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const std::size_t max_len_a1 = 171;
	const std::size_t max_len_a2 = 170;
	const std::size_t max_len_a3 = 169;
	const char* src_b = "1234567890abcdefg";
	const std::size_t max_len_b1 = 18;
	const std::size_t max_len_b2 = 17;
	const std::size_t max_len_b3 = 16;
	const char* src_c = "1234567890abcdef";
	const std::size_t max_len_c1 = 17;
	const std::size_t max_len_c2 = 16;
	const std::size_t max_len_c3 = 15;
	const char* src_d = "123";
	const std::size_t max_len_d1 = 4;
	const std::size_t max_len_d2 = 3;
	const std::size_t max_len_d3 = 2;
	const char* src_e = "";
	const std::size_t max_len_e1 = 2;
	const std::size_t max_len_e2 = 1;
	const std::size_t max_len_e3 = 0;

	extern void runTestOpt07_Type2_strncpy_Before(char* dst,
	                                              const char* src_a, const std::size_t max_len_a1, const std::size_t max_len_a2, const std::size_t max_len_a3,
												  const char* src_b, const std::size_t max_len_b1, const std::size_t max_len_b2, const std::size_t max_len_b3,
												  const char* src_c, const std::size_t max_len_c1, const std::size_t max_len_c2, const std::size_t max_len_c3,
												  const char* src_d, const std::size_t max_len_d1, const std::size_t max_len_d2, const std::size_t max_len_d3,
												  const char* src_e, const std::size_t max_len_e1, const std::size_t max_len_e2, const std::size_t max_len_e3);
	extern void runTestOpt07_Type2_strncpy_After(char* dst,
	                                              const char* src_a, const std::size_t max_len_a1, const std::size_t max_len_a2, const std::size_t max_len_a3,
												  const char* src_b, const std::size_t max_len_b1, const std::size_t max_len_b2, const std::size_t max_len_b3,
												  const char* src_c, const std::size_t max_len_c1, const std::size_t max_len_c2, const std::size_t max_len_c3,
												  const char* src_d, const std::size_t max_len_d1, const std::size_t max_len_d2, const std::size_t max_len_d3,
												  const char* src_e, const std::size_t max_len_e1, const std::size_t max_len_e2, const std::size_t max_len_e3);
	runTestOpt07_Type2_strncpy_Before(dst,
	                                  src_a, max_len_a1, max_len_a2, max_len_a3,
									  src_b, max_len_b1, max_len_b2, max_len_b3,
									  src_c, max_len_c1, max_len_c2, max_len_c3,
									  src_d, max_len_d1, max_len_d2, max_len_d3,
									  src_e, max_len_e1, max_len_e2, max_len_e3);
	runTestOpt07_Type2_strncpy_After(dst,
	                                 src_a, max_len_a1, max_len_a2, max_len_a3,
									 src_b, max_len_b1, max_len_b2, max_len_b3,
									 src_c, max_len_c1, max_len_c2, max_len_c3,
									 src_d, max_len_d1, max_len_d2, max_len_d3,
									 src_e, max_len_e1, max_len_e2, max_len_e3);
}
//最適化前
void runTestOpt07_Type2_strncpy_Before(char* dst,
	                                   const char* src_a, const std::size_t max_len_a1, const std::size_t max_len_a2, const std::size_t max_len_a3,
									   const char* src_b, const std::size_t max_len_b1, const std::size_t max_len_b2, const std::size_t max_len_b3,
									   const char* src_c, const std::size_t max_len_c1, const std::size_t max_len_c2, const std::size_t max_len_c3,
									   const char* src_d, const std::size_t max_len_d1, const std::size_t max_len_d2, const std::size_t max_len_d3,
									   const char* src_e, const std::size_t max_len_e1, const std::size_t max_len_e2, const std::size_t max_len_e3)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strncpy_Before(loop, dst, src_a, max_len_a1);
		testOpt07_Type2_strncpy_Before(loop, dst, src_a, max_len_a2);
		testOpt07_Type2_strncpy_Before(loop, dst, src_a, max_len_a3);
		testOpt07_Type2_strncpy_Before(loop, dst, src_b, max_len_b1);
		testOpt07_Type2_strncpy_Before(loop, dst, src_b, max_len_b2);
		testOpt07_Type2_strncpy_Before(loop, dst, src_b, max_len_b3);
		testOpt07_Type2_strncpy_Before(loop, dst, src_c, max_len_c1);
		testOpt07_Type2_strncpy_Before(loop, dst, src_c, max_len_c2);
		testOpt07_Type2_strncpy_Before(loop, dst, src_c, max_len_c3);
		testOpt07_Type2_strncpy_Before(loop, dst, src_d, max_len_d1);
		testOpt07_Type2_strncpy_Before(loop, dst, src_d, max_len_d2);
		testOpt07_Type2_strncpy_Before(loop, dst, src_d, max_len_d3);
		testOpt07_Type2_strncpy_Before(loop, dst, src_e, max_len_e1);
		testOpt07_Type2_strncpy_Before(loop, dst, src_e, max_len_e2);
		testOpt07_Type2_strncpy_Before(loop, dst, src_e, max_len_e3);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_strncpy_After(char* dst,
	                                  const char* src_a, const std::size_t max_len_a1, const std::size_t max_len_a2, const std::size_t max_len_a3,
									  const char* src_b, const std::size_t max_len_b1, const std::size_t max_len_b2, const std::size_t max_len_b3,
									  const char* src_c, const std::size_t max_len_c1, const std::size_t max_len_c2, const std::size_t max_len_c3,
									  const char* src_d, const std::size_t max_len_d1, const std::size_t max_len_d2, const std::size_t max_len_d3,
									  const char* src_e, const std::size_t max_len_e1, const std::size_t max_len_e2, const std::size_t max_len_e3)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_strncpy_After(loop, dst, src_a, max_len_a1);
		testOpt07_Type2_strncpy_After(loop, dst, src_a, max_len_a2);
		testOpt07_Type2_strncpy_After(loop, dst, src_a, max_len_a3);
		testOpt07_Type2_strncpy_After(loop, dst, src_b, max_len_b1);
		testOpt07_Type2_strncpy_After(loop, dst, src_b, max_len_b2);
		testOpt07_Type2_strncpy_After(loop, dst, src_b, max_len_b3);
		testOpt07_Type2_strncpy_After(loop, dst, src_c, max_len_c1);
		testOpt07_Type2_strncpy_After(loop, dst, src_c, max_len_c2);
		testOpt07_Type2_strncpy_After(loop, dst, src_c, max_len_c3);
		testOpt07_Type2_strncpy_After(loop, dst, src_d, max_len_d1);
		testOpt07_Type2_strncpy_After(loop, dst, src_d, max_len_d2);
		testOpt07_Type2_strncpy_After(loop, dst, src_d, max_len_d3);
		testOpt07_Type2_strncpy_After(loop, dst, src_e, max_len_e1);
		testOpt07_Type2_strncpy_After(loop, dst, src_e, max_len_e2);
		testOpt07_Type2_strncpy_After(loop, dst, src_e, max_len_e3);
	}
	printElapsedTime(prev_time);
}

//----------------------------------------
//追加テスト：ラダムダ式のキャプチャーテスト（クロージャとしてどこまで使えるか？）
void testForClosure()
{
	extern void setLambda(int&);
	//extern void callLambda123();
	extern void callLambda13();

	printf("----------------------------------------\n");
	printf("[Test for Lambda with closure]\n");

	int counter1 = 0;
	setLambda(counter1);

	printf("Call lambda in main().\n");
	//callLambda123();//←lambda2は、ここからの呼び出しではキャプチャ変数がスコープの範囲外になっており、クロージャとして機能しない（呼び出すとハングすることがある）
	//callLambda123();
	//callLambda123();
	callLambda13();
	callLambda13();
	callLambda13();
}

//----------------------------------------
//メイン
int main(const int argc, const char* argv[])
{
	//最適化①：メモリアクセスの抑制：一時変数の活用
	runTestOpt01();

	//最適化②：メモリアクセスの抑制：アドレス計算の削減
	runTestOpt02();

	//最適化③：メモリアクセスの抑制：関数呼び出しの削減
	runTestOpt03();

	//最適化④：除算の抑制：乗算に変更
	runTestOpt04();

	//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更
	runTestOpt05();

	//最適化⑥：乗算／除算の抑制：演算の共通化
	runTestOpt06();

	//最適化⑦：SIMD演算を活用する
	runTestOpt07();

	//追加テスト：ラダムダ式のキャプチャーテスト（クロージャとしてどこまで使えるか？）
	testForClosure();

	//終了
	return EXIT_SUCCESS;
}

// End of file
