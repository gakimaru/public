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
#include "unit_test_id.h"
UT_BEGIN(CModuleA, UT_GROUP_USER_A)//モジュール名とグループIDを指定　※特定のモジュール名やグループIDに絞ったテストを実行可能
{
	CModuleA _CModuleA;
	UT_EXPECT(_CModuleA.func(1, 2), == , 3);
	UT_EXPECT(_CModuleA.func(3, 4), == , 7);
	UT_EXPECT(_CModuleA.func(4, 5), != , 9);
}
UT_END()

// End of file
