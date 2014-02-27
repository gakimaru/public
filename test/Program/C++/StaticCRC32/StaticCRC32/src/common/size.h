//----- サイズ計算 -----
//【size.h】

#pragma once
#ifndef __SIZE_H_
#define __SIZE_H_

//配列のサイズ（要素数）を取得
//※最適化により、関数が消滅してプログラムコード上で直値が扱われる
template<typename T, size_t SIZE>
size_t GetArraySize(const T (&)[SIZE])
{
	return SIZE;
}

//（旧来からの）配列サイズ取得マクロ
#define GET_ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

//配列の長さを取得
//※'\0'をターミネーターとする要素数で、ターミネーター分含まない長さ
//※ターミネーターが見つからない場合、配列の要素数が返る
//※最適化により、関数が直接処理コード上に展開される
template<typename T, size_t SIZE>
size_t GetArrayLen(const T (&arr)[SIZE])
{
	size_t len = 0;
	for(; arr[len] && len < SIZE; ++ len){}
	return len;
}

//文字列に基づいて、文字列と文字列長および文字列サイズの定数を定義
//※文字列長は自動計算
#define DEF_STR_AND_LEN_COMMON(STATIC, NAME, STR) \
	STATIC const char* NAME = STR; \
	STATIC const char NAME##_ARRAY[] = {STR}; \
	STATIC const size_t NAME##_LEN = GetArrayLen(NAME##_ARRAY); \
	STATIC const size_t NAME##_SIZE = GetArraySize(NAME##_ARRAY);
#define DEF_STATIC_STR_AND_LEN(NAME, STR) \
	DEF_STR_AND_LEN_COMMON(static, NAME, STR)
#define DEF_STR_AND_LEN(NAME, STR) \
	DEF_STR_AND_LEN_COMMON(, NAME, STR)

//文字列に基づいて、文字列と文字列長および文字列サイズの定数を参照
#define REF_STR_AND_LEN_COMMON(STATIC, NAME) \
	extern STATIC const char* NAME; \
	extern STATIC const char NAME##_ARRAY_[]; \
	extern STATIC const size_t NAME##_LEN; \
	extern STATIC const size_t NAME##_SIZE;
#define REF_STATIC_STR_AND_LEN(NAME) \
	REF_STR_AND_LEN_COMMON(, NAME)
#define REF_STR_AND_LEN(NAME) \
	REF_STR_AND_LEN_COMMON(, NAME)

#endif//__SIZE_H_

// End of file
