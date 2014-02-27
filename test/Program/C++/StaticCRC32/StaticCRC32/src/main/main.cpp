//----- メイン処理 -----
//【main.cpp】

//インクルード
#include <stdlib.h>
#include "test/test_crc32.h"
#include "test/test_size.h"

//メイン関数
int main(const int argc, const char* argv[])
{
	//CRC32テスト
	Test_StaticCRC32();
	Test_DynamicCRC32();
	
	//サイズ取得処理テスト
	Test_Size();

	//constexpr/ユーザー定義リテラルのテスト
	extern void test_constexpr();
	test_constexpr();

	//終了
	return EXIT_SUCCESS;
}

// End of file
