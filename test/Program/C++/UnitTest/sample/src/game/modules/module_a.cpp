#include <exception>

class CModuleA
{
public:
	int func1(int p1, int p2)
	{
		return p1 + p2;
	}
	bool func2()
	{
		return true;
	}
	bool func3()
	{
		throw std::exception("Thrown message");
		return true;
	}
};

//ユニットテスト
#include "unit_test.h"
#include "game/unit_test_id.h"
UT_BEGIN(CModuleA, UT_GROUP_USER_A, UnitTest::UT_ATTR_AUTO)//モジュール名とグループID、属性を指定 ※特定のモジュール名やグループIDに絞ったテストを実行可能。
                                                           //                                     ※mainから自動実行するには UT_ATTR_AUTO 属性を付与する必要がある。
														   //                                       属性は第0ビット目が自動実行用に予約されている以外は自由に使って良い。
														   //                                       テスト実行時に対象属性の指定があり、ビットマスク（&演算の結果が0以外かどうか）で実行の可否が判定される仕組み。
{
	CModuleA _CModuleA;
	UT_EXPECT_EQ(_CModuleA.func1(1, 2), 3);
	UT_EXPECT_EQ(_CModuleA.func1(3, 4), 7);
	UT_EXPECT_NE(_CModuleA.func1(4, 5), 9);
	UT_EXPECT_EQ(_CModuleA.func2(), true);
	UT_EXPECT_NE(_CModuleA.func2(), true);
	UT_EXPECT_EQ(_CModuleA.func3(), true);
}
UT_END()

// End of file
