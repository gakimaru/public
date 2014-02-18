#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char binary_test_txt_start[];//test.txt の先頭の位置
extern char binary_test_txt_end[];//test.txt の終端+1の位置
extern char binary_test_txt_size[];//test.txt のサイズ
//_binary_ + (ファイル名) + _ + (拡張子) + _start / _end / _size というシンボルが objcopy で作られる
//Cygwinの場合は注意！
//GCCでコンパイルしても、Visual C++ と同じく、コンパイル時に
//自動的にシンボル名の先頭にアンダースコアを付加する。
//そのため、C/C++のコード上では先頭のアンダースコアを付けない。

int main(const int argc, const char* argv[])
{
	const char *txt_top = binary_test_txt_start;//test.txt の先頭の位置を取得
	const char *txt_end = binary_test_txt_end;//test.txt の終端+1の位置を取得
	const size_t txt_size = reinterpret_cast<size_t>(binary_test_txt_size);//test.txt のサイズを取得
	
	//test.txt の内容をコピー
	char* txt = new char[txt_size + 1];
	strncpy(txt, txt_top, txt_size);
	txt[txt_size] = '\0';
	
	//text.txt の内容を表示
	printf("test.txt = \"%s\"\n", txt);
	
	//バッファを破棄
	delete txt;
	
	return EXIT_SUCCESS;
}

// End of file
