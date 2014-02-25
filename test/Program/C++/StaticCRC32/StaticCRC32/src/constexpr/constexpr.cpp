//C++11用の constexpr / ユーザー定義リテラルを使ったコンパイル時CRC計算テスト

//#define ENABLE_CONSTEXPR//constexprを有効にする時はこのマクロを有効にする
//#define ENABLE_USER_DEFINED_LITERALS//ユーザー定義リテラルを有効にする時はこのマクロを有効にする
#define USE_CRC_CALC_TABLE//CRC計算の際に、事前計算済みのCRC計算テーブルを使用するならこのマクロを有効にする
//#define CONST_ALL//全てをconstにして全てをコンパイル時計算する時はこのマクロを有効にする
#define ENABLE_MORE_TEST//追加テスト処理を有効にする時はこのマクロを有効にする
//#define ENABLE_MAIN//メイン関数を有効にする時はこのマクロを有効にする

#include <stdio.h>
#include <stdlib.h>
#include <cstddef>//std::size_t用
#include <assert.h>//assert用

//C++11互換用マクロ
#ifndef ENABLE_CONSTEXPR
#define constexpr const
#endif//ENABLE_CONSTEXPR

#ifdef CONST_ALL
#define NOCONST const
#else//CONST_ALL
#define NOCONST
#endif//CONST_ALL

//--------------------
//CRC算出関数
typedef unsigned int crc32_t;//CRC32型
namespace crc_inner_calc//直接使用しない処理を隠ぺいするためのネームスペース
{
#ifndef USE_CRC_CALC_TABLE
	//CRC生成多項式計算（再帰処理）
	constexpr crc32_t calcPoly(crc32_t poly, const int n)
	{
		return n == 0 ? poly : calcPoly(poly & 1 ? 0xedb88320u ^ (poly >> 1) : (poly >> 1), n - 1);
	}
#else//USE_CRC_CALC_TABLE
	//CRC生成多項式計算計算済みテーブル
	constexpr crc32_t s_calcTable[] =
	{
		0x00000000u, 0x77073096u, 0xee0e612cu, 0x990951bau, 0x076dc419u, 0x706af48fu, 0xe963a535u, 0x9e6495a3u,
		0x0edb8832u, 0x79dcb8a4u, 0xe0d5e91eu, 0x97d2d988u, 0x09b64c2bu, 0x7eb17cbdu, 0xe7b82d07u, 0x90bf1d91u,
		0x1db71064u, 0x6ab020f2u, 0xf3b97148u, 0x84be41deu, 0x1adad47du, 0x6ddde4ebu, 0xf4d4b551u, 0x83d385c7u,
		0x136c9856u, 0x646ba8c0u, 0xfd62f97au, 0x8a65c9ecu, 0x14015c4fu, 0x63066cd9u, 0xfa0f3d63u, 0x8d080df5u,
		0x3b6e20c8u, 0x4c69105eu, 0xd56041e4u, 0xa2677172u, 0x3c03e4d1u, 0x4b04d447u, 0xd20d85fdu, 0xa50ab56bu,
		0x35b5a8fau, 0x42b2986cu, 0xdbbbc9d6u, 0xacbcf940u, 0x32d86ce3u, 0x45df5c75u, 0xdcd60dcfu, 0xabd13d59u,
		0x26d930acu, 0x51de003au, 0xc8d75180u, 0xbfd06116u, 0x21b4f4b5u, 0x56b3c423u, 0xcfba9599u, 0xb8bda50fu,
		0x2802b89eu, 0x5f058808u, 0xc60cd9b2u, 0xb10be924u, 0x2f6f7c87u, 0x58684c11u, 0xc1611dabu, 0xb6662d3du,
		0x76dc4190u, 0x01db7106u, 0x98d220bcu, 0xefd5102au, 0x71b18589u, 0x06b6b51fu, 0x9fbfe4a5u, 0xe8b8d433u,
		0x7807c9a2u, 0x0f00f934u, 0x9609a88eu, 0xe10e9818u, 0x7f6a0dbbu, 0x086d3d2du, 0x91646c97u, 0xe6635c01u,
		0x6b6b51f4u, 0x1c6c6162u, 0x856530d8u, 0xf262004eu, 0x6c0695edu, 0x1b01a57bu, 0x8208f4c1u, 0xf50fc457u,
		0x65b0d9c6u, 0x12b7e950u, 0x8bbeb8eau, 0xfcb9887cu, 0x62dd1ddfu, 0x15da2d49u, 0x8cd37cf3u, 0xfbd44c65u,
		0x4db26158u, 0x3ab551ceu, 0xa3bc0074u, 0xd4bb30e2u, 0x4adfa541u, 0x3dd895d7u, 0xa4d1c46du, 0xd3d6f4fbu,
		0x4369e96au, 0x346ed9fcu, 0xad678846u, 0xda60b8d0u, 0x44042d73u, 0x33031de5u, 0xaa0a4c5fu, 0xdd0d7cc9u,
		0x5005713cu, 0x270241aau, 0xbe0b1010u, 0xc90c2086u, 0x5768b525u, 0x206f85b3u, 0xb966d409u, 0xce61e49fu,
		0x5edef90eu, 0x29d9c998u, 0xb0d09822u, 0xc7d7a8b4u, 0x59b33d17u, 0x2eb40d81u, 0xb7bd5c3bu, 0xc0ba6cadu,
		0xedb88320u, 0x9abfb3b6u, 0x03b6e20cu, 0x74b1d29au, 0xead54739u, 0x9dd277afu, 0x04db2615u, 0x73dc1683u,
		0xe3630b12u, 0x94643b84u, 0x0d6d6a3eu, 0x7a6a5aa8u, 0xe40ecf0bu, 0x9309ff9du, 0x0a00ae27u, 0x7d079eb1u,
		0xf00f9344u, 0x8708a3d2u, 0x1e01f268u, 0x6906c2feu, 0xf762575du, 0x806567cbu, 0x196c3671u, 0x6e6b06e7u,
		0xfed41b76u, 0x89d32be0u, 0x10da7a5au, 0x67dd4accu, 0xf9b9df6fu, 0x8ebeeff9u, 0x17b7be43u, 0x60b08ed5u,
		0xd6d6a3e8u, 0xa1d1937eu, 0x38d8c2c4u, 0x4fdff252u, 0xd1bb67f1u, 0xa6bc5767u, 0x3fb506ddu, 0x48b2364bu,
		0xd80d2bdau, 0xaf0a1b4cu, 0x36034af6u, 0x41047a60u, 0xdf60efc3u, 0xa867df55u, 0x316e8eefu, 0x4669be79u,
		0xcb61b38cu, 0xbc66831au, 0x256fd2a0u, 0x5268e236u, 0xcc0c7795u, 0xbb0b4703u, 0x220216b9u, 0x5505262fu,
		0xc5ba3bbeu, 0xb2bd0b28u, 0x2bb45a92u, 0x5cb36a04u, 0xc2d7ffa7u, 0xb5d0cf31u, 0x2cd99e8bu, 0x5bdeae1du,
		0x9b64c2b0u, 0xec63f226u, 0x756aa39cu, 0x026d930au, 0x9c0906a9u, 0xeb0e363fu, 0x72076785u, 0x05005713u,
		0x95bf4a82u, 0xe2b87a14u, 0x7bb12baeu, 0x0cb61b38u, 0x92d28e9bu, 0xe5d5be0du, 0x7cdcefb7u, 0x0bdbdf21u,
		0x86d3d2d4u, 0xf1d4e242u, 0x68ddb3f8u, 0x1fda836eu, 0x81be16cdu, 0xf6b9265bu, 0x6fb077e1u, 0x18b74777u,
		0x88085ae6u, 0xff0f6a70u, 0x66063bcau, 0x11010b5cu, 0x8f659effu, 0xf862ae69u, 0x616bffd3u, 0x166ccf45u,
		0xa00ae278u, 0xd70dd2eeu, 0x4e048354u, 0x3903b3c2u, 0xa7672661u, 0xd06016f7u, 0x4969474du, 0x3e6e77dbu,
		0xaed16a4au, 0xd9d65adcu, 0x40df0b66u, 0x37d83bf0u, 0xa9bcae53u, 0xdebb9ec5u, 0x47b2cf7fu, 0x30b5ffe9u,
		0xbdbdf21cu, 0xcabac28au, 0x53b39330u, 0x24b4a3a6u, 0xbad03605u, 0xcdd70693u, 0x54de5729u, 0x23d967bfu,
		0xb3667a2eu, 0xc4614ab8u, 0x5d681b02u, 0x2a6f2b94u, 0xb40bbe37u, 0xc30c8ea1u, 0x5a05df1bu, 0x2d02ef8du
	};
#endif//USE_CRC_CALC_TABLE
	//文字列からCRC算出用（再帰処理）
	constexpr crc32_t calcStr(const crc32_t crc, const char* str)
	{
#ifndef USE_CRC_CALC_TABLE
		return *str == '\0' ? crc : calcStr(calcPoly(static_cast<crc32_t>((crc ^ *str) & 0xffu), 8) ^ (crc >> 8), str + 1);//CRC生成多項式計算計算を合成
#else//USE_CRC_CALC_TABLE
		return *str == '\0' ? crc : calcStr(s_calcTable[(crc ^ *str) & 0xffu] ^ (crc >> 8), str + 1);//CRC生成多項式計算計算済みテーブルの値を合成
#endif//USE_CRC_CALC_TABLE
	}
	//データ長を指定してCRC算出用（再帰処理）
	constexpr crc32_t calcData(const crc32_t crc, const char* data, const int len)
	{
#ifndef USE_CRC_CALC_TABLE
		return len == 0 ? crc : calcData(calcPoly(static_cast<crc32_t>((crc ^ *data) & 0xffu), 8) ^ (crc >> 8), data + 1, len - 1);//CRC生成多項式計算計算を合成
#else//USE_CRC_CALC_TABLE
		return len == 0 ? crc : calcData(s_calcTable[(crc ^ *data) & 0xffu] ^ (crc >> 8), data + 1, len - 1);//CRC生成多項式計算計算済みテーブルの値を合成
#endif//USE_CRC_CALC_TABLE
	}
}
//文字列からCRC算出用
constexpr crc32_t calcCRC32(const char* str)
{
	return ~crc_inner_calc::calcStr(~0u, str);
}
//データ長を指定してCRC算出
constexpr crc32_t calcCRC32(const char* str, const int len)
{
	return ~crc_inner_calc::calcData(~0u, str, len);
}
#ifdef ENABLE_USER_DEFINED_LITERALS
//ユーザー定義リテラル
constexpr crc32_t operator "" _crc32(const char* str, std::size_t len)
{
	return calcCRC32(str, len);
}
#endif//ENABLE_USER_DEFINED_LITERALS

#ifdef ENABLE_MORE_TEST
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

//constexpr / ユーザー定義リテラルによるCRC計算のテスト
void test_constexpr()
{
	{
		const crc32_t crc1 = calcCRC32("1234567890");//コンパイル時に計算（文字列リテラルも消滅）
#ifdef ENABLE_CONSTEXPR
		static_assert(crc1 == 0x261daee5, "invalid crc1");//OK：コンパイル時に評価
#endif//ENABLE_CONSTEXPR
		printf("constexpr によるコンパイル時のCRC計算結果=0x%08x\n", crc1);
#ifdef ENABLE_MORE_TEST
		const crc32_t TEXT1_CRC = calcCRC32(TEXT1);
		const crc32_t TEXT2_CRC = calcCRC32(TEXT2);
		const crc32_t TEXT3_CRC = calcCRC32(TEXT3);
		const crc32_t TEXT4_CRC = calcCRC32(TEXT4);
		const crc32_t TEXT5_CRC = calcCRC32(TEXT5);
		const crc32_t TEXT6_CRC = calcCRC32(TEXT6);
		const crc32_t TEXT7_CRC = calcCRC32(TEXT7);
		const crc32_t TEXT8_CRC = calcCRC32(TEXT8);
		const crc32_t TEXT9_CRC = calcCRC32(TEXT9);
		const crc32_t TEXT10_CRC = calcCRC32(TEXT10);
		printf("\n");
		printf("<Test: Static CRC32 by constexpr>\n");
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
	{
	NOCONST crc32_t crc2 = calcCRC32("1234567890");//ランタイム時に計算//【残念】constが付いていないとコンパイル時に計算してくれない
	assert(crc2 == 0x261daee5);//OK：ランタイム時に評価
	printf("constexpr によるランタイム時のCRC計算結果=0x%08x\n", crc2);
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
	printf("\n");
	printf("<Test: Dynamic CRC32 by constexpr>\n");
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
#ifdef ENABLE_USER_DEFINED_LITERALS
	{
		const crc32_t crc3 = "1234567890"_crc32;//コンパイル時に計算（文字列リテラルも消滅）
		static_assert(crc3 == 0x261daee5, "invalid crc2");//OK：コンパイル時に評価
		printf("ユーザー定義リテラルによるコンパイル時のCRC計算結果=0x%08x\n", crc3);
#ifdef ENABLE_MORE_TEST
		const crc32_t TEXT1_CRC = "1"_crc32;
		const crc32_t TEXT2_CRC = "12"_crc32;
		const crc32_t TEXT3_CRC = "123"_crc32;
		const crc32_t TEXT4_CRC = "1234"_crc32;
		const crc32_t TEXT5_CRC = "12345"_crc32;
		const crc32_t TEXT6_CRC = "123456"_crc32;
		const crc32_t TEXT7_CRC = "1234567"_crc32;
		const crc32_t TEXT8_CRC = "12345678"_crc32;
		const crc32_t TEXT9_CRC = "123456789"_crc32;
		const crc32_t TEXT10_CRC = "1234567890"_crc32;
		printf("\n");
		printf("<Test: Static CRC32 by user defined literals>\n");
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
#endif//ENABLE_USER_DEFINED_LITERALS
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
