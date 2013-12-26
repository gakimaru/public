#include "unit_test.h"

class CModuleB
{
public:
	int funcA(int p1, int p2, int p3)
	{
		return p1 * p2 * p3;
	}
	void funcB(int p1, int p2, int& ret)
	{
		ret = p1 * p2;
	}
	int funcC(int p1, int p2, int& ret1, int& ret2)
	{
		ret1 = p1 + p2;
		ret2 = p1 - p2;
		return p1 * p2;
	}
};

//ユニットテスト
//#define UT_IS_ESPECIALLY false //通常はこのマクロを有効化した状態でコミットする事！
#define UT_IS_ESPECIALLY true //単独実行したい時だけ一時的にこのマクロを有効化して、ユニットテストを単独モードで実行する
UT_BEGIN(CModuleB, UT_IS_ESPECIALLY)//モジュール名を指定する。　※他のユニットテストモジュールと名前が重複しないように注意！
                                    //                          ※モジュール名をマクロで指定する事も不可！（マクロ名がモジュール名になってしまう）
{
	CModuleB _CModuleB;
	int ret_int = 0;
	int ret_int1 = 0;
	int ret_int2 = 0;
	UT_EXPECT(_CModuleB.funcA(1, 2, 3), == , 6);
	UT_EXPECT(_CModuleB.funcA(3, 4, 5), >, 60);
	UT_EXPR(_CModuleB.funcB(1, 2, ret_int)); UT_EXPECT_CHILD(ret_int, ==, 2);
	UT_EXPR(_CModuleB.funcB(3, 4, ret_int)); UT_EXPECT_CHILD(ret_int, <, 12);
	UT_EXPR_WITH_RET(_CModuleB.funcC(1, 2, ret_int1, ret_int2)); UT_EXPECT_CHILD(ret_int1, == , 2); UT_EXPECT_CHILD(ret_int2, < , 0);
	UT_EXPR_WITH_RET(_CModuleB.funcC(3, 4, ret_int1, ret_int2)); UT_EXPECT_CHILD(ret_int1, !=, 7); UT_EXPECT_CHILD(ret_int2, >, 0);
}
UT_END()

// End of file
