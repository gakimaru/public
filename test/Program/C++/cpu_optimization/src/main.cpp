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
	extern void runTestOpt07_Type2();
	runTestOpt07_Type2();
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
//【タイプ２】
void runTestOpt07_Type2()
{
	printf("Type2: *repeated * %d times.\n", LOOP_OPT07_TYPE2);
	extern void runTestOpt07_Type2_Before(char* str0_a, const char* str1_a, const char* str2_a, const char* str3_a, const char c_a,
	                                      char* str0_b, const char* str1_b, const char* str2_b, const char* str3_b, const char c_b,
	                                      char* str0_c, const char* str1_c, const char* str2_c, const char* str3_c, const char c_c);
	extern void runTestOpt07_Type2_After(char* str0_a, const char* str1_a, const char* str2_a, const char* str3_a, const char c_a,
	                                     char* str0_b, const char* str1_b, const char* str2_b, const char* str3_b, const char c_b,
	                                     char* str0_c, const char* str1_c, const char* str2_c, const char* str3_c, const char c_c);
	char str0_a[128];
	char str0_b[128];
	char str0_c[128];
	const char* str1_a = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str2_a = "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_";
	const char* str3_a = "ABC";
	const char c_a = '!';
	const char* str1_b = "1234567890abcdef";
	const char* str2_b = "1234567890abcdefg";
	const char* str3_b = "efgh";
	const char c_b = '!';
	const char* str1_c = "";
	const char* str2_c = "";
	const char* str3_c = "";
	const char c_c = '\0';
	runTestOpt07_Type2_Before(str0_a, str1_a, str2_a, str3_a, c_a,
	                          str0_b, str1_b, str2_b, str3_b, c_b,
	                          str0_c, str1_c, str2_c, str3_c, c_c);
	runTestOpt07_Type2_After(str0_a, str1_a, str2_a, str3_a, c_a,
	                         str0_b, str1_b, str2_b, str3_b, c_b,
	                         str0_c, str1_c, str2_c, str3_c, c_c);
}
//最適化前
void runTestOpt07_Type2_Before(char* str0_a, const char* str1_a, const char* str2_a, const char* str3_a, const char c_a,
                               char* str0_b, const char* str1_b, const char* str2_b, const char* str3_b, const char c_b,
                               char* str0_c, const char* str1_c, const char* str2_c, const char* str3_c, const char c_c)
{
	printf("  Before   ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_Before(loop, str0_a, str1_a, str2_a, str3_a, c_a);
		testOpt07_Type2_Before(loop, str0_b, str1_b, str2_b, str3_b, c_b);
		testOpt07_Type2_Before(loop, str0_c, str1_c, str2_c, str3_c, c_c);
	}
	printElapsedTime(prev_time);
}
//最適化後
void runTestOpt07_Type2_After(char* str0_a, const char* str1_a, const char* str2_a, const char* str3_a, const char c_a,
                              char* str0_b, const char* str1_b, const char* str2_b, const char* str3_b, const char c_b,
                              char* str0_c, const char* str1_c, const char* str2_c, const char* str3_c, const char c_c)
{
	printf("  After    ... ");
	const auto prev_time = std::chrono::system_clock::now();
	for (int loop = 0; loop < LOOP_OPT07_TYPE2; ++loop)
	{
		testOpt07_Type2_After(loop, str0_a, str1_a, str2_a, str3_a, c_a);
		testOpt07_Type2_After(loop, str0_b, str1_b, str2_b, str3_b, c_b);
		testOpt07_Type2_After(loop, str0_c, str1_c, str2_c, str3_c, c_c);
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
