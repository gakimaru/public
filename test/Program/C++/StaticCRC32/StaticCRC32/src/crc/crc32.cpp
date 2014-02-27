//----- CRC32共通処理 -----
//【crc32.cpp】

//インクルード
#include <stddef.h>
#include "crc/crc32.h"
#include "crc/crc32_table.h"

//CRC32生成関数
CRC32T CalcCRC32(const char* str)
{
	if(!str)
		return 0;
	
	CALC_CRC32_DEF(crc32);
	const char* str_p = str;
	for(; *str_p; ++ str_p)
	{
		const CRC32T val = *str_p;
		static CCRC32Table crc32_table;
		CALC_CRC32_VALUE(crc32, val, crc32_table.GetTable(index));
	}
	CALC_CRC32_END(crc32);
	return crc32;
}

// End of file
