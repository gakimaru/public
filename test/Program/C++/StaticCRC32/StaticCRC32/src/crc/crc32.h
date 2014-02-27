//----- CRC32処理 -----
//【crc32.h】

#pragma once
#ifndef __CRC32_H_
#define __CRC32_H_

//CRC32型
typedef unsigned int CRC32T;

//CRC32生成関数
CRC32T CalcCRC32(const char* str);

//静的CRC32定義参照用マクロ
#define REF_CRC32_BY_STR(NAME) \
	extern const char* NAME; \
	extern const CRC32T NAME##_CRC;

#endif//__CRC32_H_

// End of file
