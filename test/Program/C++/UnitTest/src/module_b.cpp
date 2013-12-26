#include "unit_test.h"

class CModuleB
{
public:
	int func1(int p1, int p2, int p3)
	{
		return p1 * p2 * p3;
	}
	void func2(int p1, int p2, int& ret)
	{
		ret = p1 * p2;
	}
};

class CModuleC
{
public:
	int func(int p1, int p2, int& ret1, int& ret2)
	{
		ret1 = p1 + p2;
		ret2 = p1 - p2;
		return p1 * p2;
	}
};

//ユニットテスト
#include "unit_test_id.h"
UT_BEGIN(CModuleB, UT_GROUP_USER_B)//モジュール名とグループIDを指定　※特定のモジュール名やグループIDに絞ったテストを実行可能
{
	CModuleB _CModuleB;
	int ret_int = 0;
	UT_EXPECT(_CModuleB.func1(1, 2, 3), == , 6);
	UT_EXPECT(_CModuleB.func1(3, 4, 5), >, 60);
	UT_EXPR(_CModuleB.func2(1, 2, ret_int)); UT_EXPECT_CHILD(ret_int, ==, 2);
	UT_EXPR(_CModuleB.func2(3, 4, ret_int)); UT_EXPECT_CHILD(ret_int, <, 12);
}
UT_END()
UT_BEGIN(CModuleC, UT_GROUP_USER_B)//モジュール名とグループIDを指定　※特定のモジュール名やグループIDに絞ったテストを実行可能
{
	CModuleC _CModuleC;
	int ret_int1 = 0;
	int ret_int2 = 0;
	UT_EXPR_WITH_RET(_CModuleC.func(1, 2, ret_int1, ret_int2)); UT_EXPECT_CHILD(ret_int1, == , 2); UT_EXPECT_CHILD(ret_int2, <, 0);
	UT_EXPR_WITH_RET(_CModuleC.func(3, 4, ret_int1, ret_int2)); UT_EXPECT_CHILD(ret_int1, != , 7); UT_EXPECT_CHILD(ret_int2, >, 0);
}
UT_END()

// End of file
