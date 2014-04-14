#include "constexpr_test.h"

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>//assert用

#include <chrono>//処理時間計測用

//--------------------------------------------------------------------------------
//テスト

#ifdef ENABLE_MORE_TEST
//--------------------
//追加テスト用データ定義
static const char* TEXT1 = "1";
static const char* TEXT2 = "12";
static const char* TEXT3 = "123";
static const char* TEXT4 = "1234";
static const char* TEXT5 = "12345";
static const char* TEXT6 = "123456";
static const char* TEXT7 = "1234567";
static const char* TEXT8 = "12345678";
static const char* TEXT9 = "123456789";
static const char* TEXT10 = "1234567890";
#endif//ENABLE_MORE_TEST

//--------------------
//constexpr / ユーザー定義リテラルによるCRC計算のテスト
void test_constexpr()
{
#ifdef USE_MAKE_STATIC_TABLE
	{
		printf("\n");
		makePolyTable();//CRC多項式テーブルを作成
	}
#endif//USE_MAKE_STATIC_TABLE
#ifdef ENABLE_CONSTEXPR_TEST
	{
		printf("\n");
		CONST crc32_t crc = calcConstCRC32("1234567890");//constexprでコンパイル時に計算 ※文字列リテラルも消滅 ※const変数に代入しないとコンパイル時に計算されないので注意
	#ifdef USE_STATIC_ASSERT
	#ifndef USE_CRC32C
		static_assert(crc == 0x261daee5u, "invalid crc");//OK：コンパイル時に評価
	#else//USE_CRC32C
		static_assert(crc == 0xf3dbd4feu, "invalid crc");//OK：コンパイル時に評価
	#endif//USE_CRC32C
	#else//USE_STATIC_ASSERT
	#ifndef USE_CRC32C
		assert(crc == 0x261daee5u);//OK：ランタイム時に評価
	#else//USE_CRC32C
		assert(crc == 0xf3dbd4feu);//OK：ランタイム時に評価
	#endif//USE_CRC32C
	#endif//USE_STATIC_ASSERT
		printf("constexpr によるCRC計算結果=0x%08x\n", crc);
	#ifdef ENABLE_MORE_TEST
		CONST crc32_t TEXT1_CRC = calcConstCRC32(TEXT1);
		CONST crc32_t TEXT2_CRC = calcConstCRC32(TEXT2);
		CONST crc32_t TEXT3_CRC = calcConstCRC32(TEXT3);
		CONST crc32_t TEXT4_CRC = calcConstCRC32(TEXT4);
		CONST crc32_t TEXT5_CRC = calcConstCRC32(TEXT5);
		CONST crc32_t TEXT6_CRC = calcConstCRC32(TEXT6);
		CONST crc32_t TEXT7_CRC = calcConstCRC32(TEXT7);
		CONST crc32_t TEXT8_CRC = calcConstCRC32(TEXT8);
		CONST crc32_t TEXT9_CRC = calcConstCRC32(TEXT9);
		CONST crc32_t TEXT10_CRC = calcConstCRC32(TEXT10);
		printf(" CRC32:TEXT1:\"%s\" = 0x%08x(%u)\n", TEXT1, TEXT1_CRC, TEXT1_CRC);
		printf(" CRC32:TEXT2:\"%s\" = 0x%08x(%u)\n", TEXT2, TEXT2_CRC, TEXT2_CRC);
		printf(" CRC32:TEXT3:\"%s\" = 0x%08x(%u)\n", TEXT3, TEXT3_CRC, TEXT3_CRC);
		printf(" CRC32:TEXT4:\"%s\" = 0x%08x(%u)\n", TEXT4, TEXT4_CRC, TEXT4_CRC);
		printf(" CRC32:TEXT5:\"%s\" = 0x%08x(%u)\n", TEXT5, TEXT5_CRC, TEXT5_CRC);
		printf(" CRC32:TEXT6:\"%s\" = 0x%08x(%u)\n", TEXT6, TEXT6_CRC, TEXT6_CRC);
		printf(" CRC32:TEXT7:\"%s\" = 0x%08x(%u)\n", TEXT7, TEXT7_CRC, TEXT7_CRC);
		printf(" CRC32:TEXT8:\"%s\" = 0x%08x(%u)\n", TEXT8, TEXT8_CRC, TEXT8_CRC);
		printf(" CRC32:TEXT9:\"%s\" = 0x%08x(%u)\n", TEXT9, TEXT9_CRC, TEXT9_CRC);
		printf(" CRC32:TEXT10:\"%s\" = 0x%08x(%u)\n", TEXT10, TEXT10_CRC, TEXT10_CRC);
	#endif//ENABLE_MORE_TEST
	}
#endif//ENABLE_CONSTEXPR_TEST
#ifdef ENABLE_USER_DEFINED_LITERALS_TEST
	{
		printf("\n");
		CONST crc32_t crc = "1234567890"_crc32;//ユーザー定義リテラルでコンパイル時に計算 ※文字列リテラルも消滅 ※const変数に代入しないとコンパイル時に計算されないので注意
	#ifdef USE_STATIC_ASSERT
	#ifndef USE_CRC32C
		static_assert(crc == 0x261daee5u, "invalid crc");//OK：コンパイル時に評価
	#else//USE_CRC32C
		static_assert(crc == 0xf3dbd4feu, "invalid crc");//OK：コンパイル時に評価
	#endif//USE_CRC32C
	#else//USE_STATIC_ASSERT
	#ifndef USE_CRC32C
		assert(crc == 0x261daee5u);//OK：ランタイム時に評価
	#else//USE_CRC32C
		assert(crc == 0xf3dbd4feu);//OK：ランタイム時に評価
	#endif//USE_CRC32C
	#endif//USE_STATIC_ASSERT
		printf("ユーザー定義リテラルによるCRC計算結果=0x%08x\n", crc);
	#ifdef ENABLE_MORE_TEST
		CONST crc32_t TEXT1_CRC = "1"_crc32;
		CONST crc32_t TEXT2_CRC = "12"_crc32;
		CONST crc32_t TEXT3_CRC = "123"_crc32;
		CONST crc32_t TEXT4_CRC = "1234"_crc32;
		CONST crc32_t TEXT5_CRC = "12345"_crc32;
		CONST crc32_t TEXT6_CRC = "123456"_crc32;
		CONST crc32_t TEXT7_CRC = "1234567"_crc32;
		CONST crc32_t TEXT8_CRC = "12345678"_crc32;
		CONST crc32_t TEXT9_CRC = "123456789"_crc32;
		CONST crc32_t TEXT10_CRC = "1234567890"_crc32;
		printf(" CRC32:TEXT1:\"%s\" = 0x%08x(%u)\n", TEXT1, TEXT1_CRC, TEXT1_CRC);
		printf(" CRC32:TEXT2:\"%s\" = 0x%08x(%u)\n", TEXT2, TEXT2_CRC, TEXT2_CRC);
		printf(" CRC32:TEXT3:\"%s\" = 0x%08x(%u)\n", TEXT3, TEXT3_CRC, TEXT3_CRC);
		printf(" CRC32:TEXT4:\"%s\" = 0x%08x(%u)\n", TEXT4, TEXT4_CRC, TEXT4_CRC);
		printf(" CRC32:TEXT5:\"%s\" = 0x%08x(%u)\n", TEXT5, TEXT5_CRC, TEXT5_CRC);
		printf(" CRC32:TEXT6:\"%s\" = 0x%08x(%u)\n", TEXT6, TEXT6_CRC, TEXT6_CRC);
		printf(" CRC32:TEXT7:\"%s\" = 0x%08x(%u)\n", TEXT7, TEXT7_CRC, TEXT7_CRC);
		printf(" CRC32:TEXT8:\"%s\" = 0x%08x(%u)\n", TEXT8, TEXT8_CRC, TEXT8_CRC);
		printf(" CRC32:TEXT9:\"%s\" = 0x%08x(%u)\n", TEXT9, TEXT9_CRC, TEXT9_CRC);
		printf(" CRC32:TEXT10:\"%s\" = 0x%08x(%u)\n", TEXT10, TEXT10_CRC, TEXT10_CRC);
	#endif//ENABLE_MORE_TEST
	}
#endif//ENABLE_USER_DEFINED_LITERALS_TEST
#ifdef ENABLE_RUNTIME_TEST
	{
		printf("\n");
		NOCONST crc32_t crc = calcCRC32("1234567890");//通常関数でランタイム時に計算
	#ifndef USE_CRC32C
		assert(crc == 0x261daee5u);//OK：ランタイム時に評価
	#else//USE_CRC32C
		assert(crc == 0xf3dbd4feu);//OK：ランタイム時に評価
	#endif//USE_CRC32C
		printf("ランタイム関数によるCRC計算結果=0x%08x\n", crc);
	#ifdef ENABLE_MORE_TEST
		NOCONST crc32_t TEXT1_CRC = calcCRC32(TEXT1);
		NOCONST crc32_t TEXT2_CRC = calcCRC32(TEXT2);
		NOCONST crc32_t TEXT3_CRC = calcCRC32(TEXT3);
		NOCONST crc32_t TEXT4_CRC = calcCRC32(TEXT4);
		NOCONST crc32_t TEXT5_CRC = calcCRC32(TEXT5);
		NOCONST crc32_t TEXT6_CRC = calcCRC32(TEXT6);
		NOCONST crc32_t TEXT7_CRC = calcCRC32(TEXT7);
		NOCONST crc32_t TEXT8_CRC = calcCRC32(TEXT8);
		NOCONST crc32_t TEXT9_CRC = calcCRC32(TEXT9);
		NOCONST crc32_t TEXT10_CRC = calcCRC32(TEXT10);
		printf(" CRC32:TEXT1:\"%s\" = 0x%08x(%u)\n", TEXT1, TEXT1_CRC, TEXT1_CRC);
		printf(" CRC32:TEXT2:\"%s\" = 0x%08x(%u)\n", TEXT2, TEXT2_CRC, TEXT2_CRC);
		printf(" CRC32:TEXT3:\"%s\" = 0x%08x(%u)\n", TEXT3, TEXT3_CRC, TEXT3_CRC);
		printf(" CRC32:TEXT4:\"%s\" = 0x%08x(%u)\n", TEXT4, TEXT4_CRC, TEXT4_CRC);
		printf(" CRC32:TEXT5:\"%s\" = 0x%08x(%u)\n", TEXT5, TEXT5_CRC, TEXT5_CRC);
		printf(" CRC32:TEXT6:\"%s\" = 0x%08x(%u)\n", TEXT6, TEXT6_CRC, TEXT6_CRC);
		printf(" CRC32:TEXT7:\"%s\" = 0x%08x(%u)\n", TEXT7, TEXT7_CRC, TEXT7_CRC);
		printf(" CRC32:TEXT8:\"%s\" = 0x%08x(%u)\n", TEXT8, TEXT8_CRC, TEXT8_CRC);
		printf(" CRC32:TEXT9:\"%s\" = 0x%08x(%u)\n", TEXT9, TEXT9_CRC, TEXT9_CRC);
		printf(" CRC32:TEXT10:\"%s\" = 0x%08x(%u)\n", TEXT10, TEXT10_CRC, TEXT10_CRC);
	#endif//ENABLE_MORE_TEST
	}
#endif//ENABLE_RUNTIME_TEST
#ifdef ENABLE_PERFORMANCE_TEST
	{
		printf("\n");
		const auto begin_time = std::chrono::system_clock::now();
		const int repeat= 100000000;
		crc32_t crc = 0;
		static const char* str = "1234567890";
		for (int loop = 0; loop < repeat; ++loop)
		{
			extern crc32_t test_performance(const char* str, const int dummy);
			crc = test_performance(str, loop);
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration_time = end_time - begin_time;
		const float elapsed_time = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(duration_time).count()) / 1000000.);
		printf("perfomance test(%d times calculate): str=\"%s\", crc=0x%08x, elapsed-time=%.06f sec\n", repeat, str, crc, elapsed_time);
	}
#endif//ENABLE_PERFORMANCE_TEST
}

#ifdef ENABLE_MAIN
//テスト
int main(const int arcg, const char* argv[])
{
	test_constexpr();

	return EXIT_SUCCESS;
}
#endif

// End of file
