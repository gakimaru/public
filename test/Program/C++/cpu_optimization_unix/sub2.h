#pragma once
#ifndef __SUB2_H_
#define __SUB2_H_

//#include "sub.h"
#include <cstddef>

//【タイプ３】最適化前：共通関数
//※オブザーバー（コールバック）を関数ポインタ型で受け取る
void commonProc_testOpt03_Type3_Before(int* values, std::size_t n, const int find, void(*observer)(int&));

//【タイプ３】最適化後：共通関数
//※オブザーバー（コールバック）をテンプレートで型展開して受け取る（std::sort などと同じやり方）
template <typename T, std::size_t N, class OBSERVER>
void commonProc_testOpt03_Type3_After(T(&values)[N], const T find, OBSERVER observer)
{
	//配列から値を検索し、見つけたらオブザーバーを呼び出す
	for (int i = 0; i < N; ++i)
	{
		T& value = values[i];
		if (value == find)
			observer(value);
	}
}

//【タイプ３】【参考】共通関数A
//※オブザーバー（コールバック）を std::function 型で受け取る
#include <functional>//C++11 std::function用
template <typename T, std::size_t N>
void commonProc_testOpt03_Type3_AppendixA(T(&values)[N], const T find, std::function<void(int&)> observer)//←std::function<void(T&)> とするとコンパイルが通らない（VC++2013, GCC共に）
{
	//配列から値を検索し、見つけたらオブザーバーを呼び出す
	for (int i = 0; i < N; ++i)
	{
		T& value = values[i];
		if (value == find)
			observer(value);
	}
}

//【タイプ３】【参考】共通関数B
//※オブザーバー（コールバック）を std::function 型で受け取る
void commonProc_testOpt03_Type3_AppendixB(int* values, std::size_t n, const int find, std::function<void(int&)> observer);

#endif//__SUB_H_

// End of file
