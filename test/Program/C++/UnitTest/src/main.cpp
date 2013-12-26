#include <stdio.h>
#include <stdlib.h>

#include "game_main.h"

int main(const int argc, const char* argv[])
{
	CGameMain* game_main = new CGameMain(argc, argv);

	//初期化処理
	game_main->initialize();

	//メイン処理
#if !defined(UNIT_TEST_ENABLED)
	game_main->main();
#else//UNIT_TEST_ENABLED
	game_main->unitTestMain();
#endif//UNIT_TEST_ENABLED

	//終了処理
	game_main->finalize();

	//main関数終了
//	exit(*game_main);  //exit() を実行するとデストラクタが実行されないので、
	return *game_main; //やむを得ない中断時以外はなるべく main() 関数の return を使う事。
	                   //なお、どちらを使用しても、環境変数 %ERRORLEVEL% には、きちんと結果が返される。

//	return EXIT_SUCCESS; //stdlib.h に定義されている正常時の return 値
//	return EXIT_FAILURE; //stdlib.h に定義されている異常時の return 値
}

// End of file

