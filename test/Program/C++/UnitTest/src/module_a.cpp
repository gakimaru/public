#include "unit_test.h"

class CModuleA
{
public:
	int func(int p1, int p2)
	{
		return p1 + p2;
	}
};

//���j�b�g�e�X�g
#include "unit_test_id.h"
UT_BEGIN(CModuleA, UT_GROUP_USER_A)//���W���[�����ƃO���[�vID���w��@������̃��W���[������O���[�vID�ɍi�����e�X�g�����s�\
{
	CModuleA _CModuleA;
	UT_EXPECT(_CModuleA.func(1, 2), == , 3);
	UT_EXPECT(_CModuleA.func(3, 4), == , 7);
	UT_EXPECT(_CModuleA.func(4, 5), != , 9);
}
UT_END()

// End of file
