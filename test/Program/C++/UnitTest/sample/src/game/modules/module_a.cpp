#include <exception>

#include "unit_test.h"

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

//���j�b�g�e�X�g
#include "game/unit_test_id.h"
UT_BEGIN(CModuleA, UT_GROUP_USER_A)//���W���[�����ƃO���[�vID���w��@������̃��W���[������O���[�vID�ɍi�����e�X�g�����s�\
{
	CModuleA _CModuleA;
	UT_EXPECT(_CModuleA.func1(1, 2), == , 3);
	UT_EXPECT(_CModuleA.func1(3, 4), == , 7);
	UT_EXPECT(_CModuleA.func1(4, 5), != , 9);
	UT_EXPECT(_CModuleA.func2(), == , true);
	UT_EXPECT(_CModuleA.func2(), != , true);
	UT_EXPECT(_CModuleA.func3(), == , true);
}
UT_END()

// End of file
