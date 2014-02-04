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

//���j�b�g�e�X�g
#include "unit_test.h"
#include "game/unit_test_id.h"
UT_BEGIN(CModuleA, UT_GROUP_USER_A, UnitTest::UT_ATTR_AUTO)//���W���[�����ƃO���[�vID�A�������w�� ������̃��W���[������O���[�vID�ɍi�����e�X�g�����s�\�B
                                                           //                                     ��main���玩�����s����ɂ� UT_ATTR_AUTO ������t�^����K�v������B
														   //                                       �����͑�0�r�b�g�ڂ��������s�p�ɗ\�񂳂�Ă���ȊO�͎��R�Ɏg���ėǂ��B
														   //                                       �e�X�g���s���ɑΏۑ����̎w�肪����A�r�b�g�}�X�N�i&���Z�̌��ʂ�0�ȊO���ǂ����j�Ŏ��s�̉ۂ����肳���d�g�݁B
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
