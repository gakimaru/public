//----- CRC32処理テスト -----
//【test_crc32.cpp】

//インクルード
#include <stdio.h>
#include "crc/crc32.h"
#include "test/test_crc32.h"
#include "test/test_def_crc_a.h"
#include "test/test_def_crc_b.h"

//テスト関数
void Test_StaticCRC32()
{
	printf("\n");
	printf("<Test: Static CRC32>\n");
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
}
void Test_DynamicCRC32()
{
	const CRC32T D_TEXT1_CRC = CalcCRC32(TEXT1);
	const CRC32T D_TEXT2_CRC = CalcCRC32(TEXT2);
	const CRC32T D_TEXT3_CRC = CalcCRC32(TEXT3);
	const CRC32T D_TEXT4_CRC = CalcCRC32(TEXT4);
	const CRC32T D_TEXT5_CRC = CalcCRC32(TEXT5);
	const CRC32T D_TEXT6_CRC = CalcCRC32(TEXT6);
	const CRC32T D_TEXT7_CRC = CalcCRC32(TEXT7);
	const CRC32T D_TEXT8_CRC = CalcCRC32(TEXT8);
	const CRC32T D_TEXT9_CRC = CalcCRC32(TEXT9);
	const CRC32T D_TEXT10_CRC = CalcCRC32(TEXT10);
	
	printf("\n");
	printf("<Test: Dynamic CRC32>\n");
	printf(" CRC32:TEXT1:\"%s\" = 0x%08x(%u)\n", TEXT1, D_TEXT1_CRC, D_TEXT1_CRC);
	printf(" CRC32:TEXT2:\"%s\" = 0x%08x(%u)\n", TEXT2, D_TEXT2_CRC, D_TEXT2_CRC);
	printf(" CRC32:TEXT3:\"%s\" = 0x%08x(%u)\n", TEXT3, D_TEXT3_CRC, D_TEXT3_CRC);
	printf(" CRC32:TEXT4:\"%s\" = 0x%08x(%u)\n", TEXT4, D_TEXT4_CRC, D_TEXT4_CRC);
	printf(" CRC32:TEXT5:\"%s\" = 0x%08x(%u)\n", TEXT5, D_TEXT5_CRC, D_TEXT5_CRC);
	printf(" CRC32:TEXT6:\"%s\" = 0x%08x(%u)\n", TEXT6, D_TEXT6_CRC, D_TEXT6_CRC);
	printf(" CRC32:TEXT7:\"%s\" = 0x%08x(%u)\n", TEXT7, D_TEXT7_CRC, D_TEXT7_CRC);
	printf(" CRC32:TEXT8:\"%s\" = 0x%08x(%u)\n", TEXT8, D_TEXT8_CRC, D_TEXT8_CRC);
	printf(" CRC32:TEXT9:\"%s\" = 0x%08x(%u)\n", TEXT9, D_TEXT9_CRC, D_TEXT9_CRC);
	printf(" CRC32:TEXT10:\"%s\" = 0x%08x(%u)\n", TEXT10, D_TEXT10_CRC, D_TEXT10_CRC);
}

// End of file
