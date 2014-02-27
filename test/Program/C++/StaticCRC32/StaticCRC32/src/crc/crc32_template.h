//----- 静的CRC32生成テンプレート用ヘッダー -----
//【crc32_template.h】

//#pragma once
#ifndef __CRC32_TEMPLATE_H_
#define __CRC32_TEMPLATE_H_

//コンパイラスイッチ
//#define USE_CRC32_CALC_LEN //CRC32計算での文字列長計算有効化
//#define USE_CRC32_TABLE_CLASS //CRC32多項式計算テーブルクラス使用有効化　※無効化時は直接配列を使用

//インクルード
#include <stddef.h>
#include "common/size.h"
#include "crc/crc32.h"
#include "crc/crc32_table.h"

//静的CRC32生成テンプレート関数
template<typename T, size_t SIZE>
CRC32T CalcCRC32Static(const T (&arr)[SIZE])
{
#ifdef USE_CRC32_CALC_LEN
	const size_t LEN = StaticGetArrayLen(arr); //※本当はこちらの処理で文字列長を求めたいが、コードサイズが大きくなるので断念
#else//USE_CRC32_CALC_LEN
	const size_t LEN = SIZE - 1;               //※代わりに、配列の要素サイズから１引くだけとする
#endif//USE_CRC32_CALC_LEN
	
	CALC_CRC32_DEF(crc32);
	for(size_t pos = 0; pos < LEN; ++ pos)
	{
		const CRC32T val = arr[pos];
	#ifdef USE_CRC32_TABLE_CLASS
		//【できればこちらの挙動であってほしい】
		//こちら側の処理を有効にした際に、テンプレート関数がインスタンス化されず、コンパイル時にCRCを生成する挙動になるなら、こちら側の処理を有効にする
		// → ×現実は、テンプレート関数がインスタンス化されて、実行時にCRCが生成されていた（Visual Studio 2012）
		static CRC32T crc32_table[] = CRC32_TABLE_VALUES;
		CALC_CRC32_VALUE(crc32, val, crc32_table[index]);
	#else//USE_CRC32_TABLE_CLASS
		//【無理なら仕方なし】
		//上記側の処理を有効にしても、テンプレート関数がインスタンス化されて、実行時にCRCを生成する挙動になるなら、こちら側の処理を有効にする
		// → ○現実は、テンプレート関数がインスタンス化されて、実行時にCRCが生成されていた（Visual Studio 2012）
		static CCRC32Table crc32_table;
		CALC_CRC32_VALUE(crc32, val, crc32_table.GetTable(index));
	#endif//USE_CRC32_TABLE_CLASS
	}
	CALC_CRC32_END(crc32);
	return crc32;
}

//静的CRC32定義用マクロ
#define DEF_CRC32_BY_STR(NAME, STR) \
	const char* NAME = STR; \
	const char NAME##_ARRAY[] = {STR}; \
	const CRC32T NAME##_CRC = CalcCRC32Static(NAME##_ARRAY);
//#define DEF_CRC32_BY_STR(NAME, STR) \
//	const char* NAME = STR; \
//	const char NAME##_ARRAY[] = {STR}; \
//	const CRC32T NAME##_CRC = CalcCRC32(NAME##_ARRAY);

#endif//__CRC32_TEMPLATE_H_

// End of file
