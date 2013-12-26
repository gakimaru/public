#include "unit_test.h"

class CModuleA
{
public:
	int func(int p1, int p2)
	{
		return p1 + p2;
	}
};

//ユニットテスト
#define UT_IS_ESPECIALLY false //通常はこのマクロを有効化した状態でコミットする事！
//#define UT_IS_ESPECIALLY true //単独実行したい時だけ一時的にこのマクロを有効化して、ユニットテストを単独モードで実行する
UT_BEGIN(CModuleA, UT_IS_ESPECIALLY)//モジュール名を指定する。　※他のユニットテストモジュールと名前が重複しないように注意！
                                    //                          ※モジュール名をマクロで指定する事も不可！（マクロ名がモジュール名になってしまう）
{
	CModuleA _CModuleA;
	UT_EXPECT(_CModuleA.func(1, 2), == , 3);
	UT_EXPECT(_CModuleA.func(3, 4), == , 7);
	UT_EXPECT(_CModuleA.func(4, 5), != , 9);
}
UT_END()

// End of file
