#include "sub2.h"

//【タイプ３】最適化前：共通関数
//※オブザーバー（コールバック）を関数ポインタ型で受け取る
void commonProc_testOpt03_Type3_Before(int* values, std::size_t n, const int find, void(*observer)(int&))
{
	//配列から値を検索し、見つけたらオブザーバーを呼び出す
	for (int i = 0; i < n; ++i)
	{
		int& value = values[i];
		if (value == find)
			observer(value);
	}
}

// End of file
