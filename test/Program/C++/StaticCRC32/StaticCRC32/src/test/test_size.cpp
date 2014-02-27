//----- サイズ取得処理テスト -----
//【test_crc32.cpp】

//インクルード
#include <stdio.h>
#include "common/size.h"

REF_STR_AND_LEN(TEXT_A);
REF_STR_AND_LEN(TEXT_B);
REF_STR_AND_LEN(TEXT_C);
REF_STATIC_STR_AND_LEN(S_TEXT_A);
REF_STATIC_STR_AND_LEN(S_TEXT_B);
REF_STATIC_STR_AND_LEN(S_TEXT_C);

//テスト関数
void Test_Size()
{
	printf("\n");
	printf("<Test: Size>\n");
	printf(" TEXT_A = \"%s\"(%d)(%d)\n", TEXT_A, TEXT_A_LEN, TEXT_A_SIZE);
	printf(" TEXT_B = \"%s\"(%d)(%d)\n", TEXT_B, TEXT_B_LEN, TEXT_B_SIZE);
	printf(" TEXT_C = \"%s\"(%d)(%d)\n", TEXT_C, TEXT_C_LEN, TEXT_C_SIZE);
	printf(" S_TEXT_A = \"%s\"(%d)(%d)\n", S_TEXT_A, S_TEXT_A_LEN, S_TEXT_A_SIZE);
	printf(" S_TEXT_B = \"%s\"(%d)(%d)\n", S_TEXT_B, S_TEXT_B_LEN, S_TEXT_B_SIZE);
	printf(" S_TEXT_C = \"%s\"(%d)(%d)\n", S_TEXT_C, S_TEXT_C_LEN, S_TEXT_C_SIZE);
}

DEF_STR_AND_LEN(TEXT_A, "a");
DEF_STR_AND_LEN(TEXT_B, "ab");
DEF_STR_AND_LEN(TEXT_C, "ab\0c");
DEF_STATIC_STR_AND_LEN(S_TEXT_A, "s_a");
DEF_STATIC_STR_AND_LEN(S_TEXT_B, "s_ab");
DEF_STATIC_STR_AND_LEN(S_TEXT_C, "s_ab\0c");

// End of file
