//【要約】
//・C++テンプレートを用いて、安全性の高い proxy パターン（変形proxyパターン）の実装を考える。
//【要件】
//・インターフェースに必要なメンバーが実装されなかった場合、コンパイル時点でエラーが出ること。
//　（virtual を使用した単純な方法だと、メンバー名やパラメータが間違っていてもコンパイルエラーにならず、オーバーロード関数として扱われてしまう問題を解消する事が狙い）
//・virtual メンバーは使用しない（vtableを保持しない）。

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "process/process.h"

int main(const int argc, const char* argv[])
{
	test();
	
	return EXIT_SUCCESS;
}

// End of file
