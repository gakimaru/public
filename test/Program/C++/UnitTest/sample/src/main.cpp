#include <stdio.h>
#include <stdlib.h>

#include "game/game_main.h"

//インターフェースクラス
class ISample
{
public:
	virtual const char* getMessage() const = 0;
};
//具象クラス①
class CTest1 : public ISample
{
public:
	virtual const char* getMessage() const { return "This is CTest1!"; }
};
//具象クラス②
class CTest2 : public ISample
{
public:
	virtual const char* getMessage() const { return "This is CTest2!!!"; }
};
//共通処理
void testCommon(ISample& obj)
{
	printf("[%s]\n", obj.getMessage());
}
//テスト
void testMain()
{
	CTest1 o1;
	CTest2 o2;
	testCommon(o1);
	testCommon(o2);
}

int main(const int argc, const char* argv[])
{
testMain();
	printf("- main() [BEGIN] ...\n");
	
	CGameMain* game_main = new CGameMain(argc, argv);

	//初期化処理
	game_main->initialize();

	//メイン処理
	game_main->main();

	//終了処理
	game_main->finalize(); 

	printf("- main() [END]\n");
	
	//main関数終了
//	exit(*game_main);  //exit() を実行するとデストラクタが実行されないので、
	return *game_main; //やむを得ない中断時以外はなるべく main() 関数の return を使う事。
	                   //なお、どちらを使用しても、環境変数 %ERRORLEVEL% には、きちんと結果が返される。

//	return EXIT_SUCCESS; //stdlib.h に定義されている正常時の return 値
//	return EXIT_FAILURE; //stdlib.h に定義されている異常時の return 値
}

// End of file

