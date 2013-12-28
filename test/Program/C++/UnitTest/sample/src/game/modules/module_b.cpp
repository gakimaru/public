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
	float func(float p1, float p2, float& ret1, float& ret2)
	{
		ret1 = p1 + p2;
		ret2 = p1 - p2;
		return p1 * p2;
	}
};

//���j�b�g�e�X�g
#include "game/unit_test_id.h"
UT_BEGIN(CModuleB, UT_GROUP_USER_B, UnitTest::UT_ATTR_AUTO)//���W���[�����ƃO���[�vID�A�������w�� ������̃��W���[������O���[�vID�ɍi�����e�X�g�����s�\�B
                                                           //                                     ��main���玩�����s����ɂ� UT_ATTR_AUTO ������t�^����K�v������B
														   //                                       �����͑�0�r�b�g�ڂ��������s�p�ɗ\�񂳂�Ă���ȊO�͎��R�Ɏg���ėǂ��B
														   //                                       �e�X�g���s���ɑΏۑ����̎w�肪����A�r�b�g�}�X�N�i&���Z�̌��ʂ�0�ȊO���ǂ����j�Ŏ��s�̉ۂ����肳���d�g�݁B
{
	CModuleB _CModuleB;
	int out_par = 0;
	UT_EXPECT_EQ(_CModuleB.func1(1, 2, 3), 1+2+3);
	UT_EXPECT_NE(_CModuleB.func1(3, 4, 5), 60);
	UT_EXPECT_GT(_CModuleB.func1(5, 6, 7), 10);
	UT_EXPECT_GE(_CModuleB.func1(7, 8, 9), 20);
	UT_EXPECT_LT(_CModuleB.func1(9, 10, 11), 30);
	UT_EXPECT_LE(_CModuleB.func1(11, 12, 13), 40);
	UT_EXPR(_CModuleB.func2(1, 2, out_par)); UT_EXPECT_EQ_CHILD(out_par, 2);
	UT_EXPR(_CModuleB.func2(3, 4, out_par)); UT_EXPECT_NE_CHILD(out_par, 12);
}
UT_END()
UT_BEGIN(CModuleC, UT_GROUP_USER_B, UnitTest::UT_ATTR_NOAUTO)//���W���[�����ƃO���[�vID�A�������w��
{
	CModuleC _CModuleC;
	float out_par1 = 0.f;
	float out_par2 = 0.f;
	UT_EXPR_WITH_RET(_CModuleC.func(1.1f, 2.2f, out_par1, out_par2)); UT_EXPECT_EQ_CHILD(out_par1, 2.f); UT_EXPECT_LT_CHILD(out_par2, 0.f);
	UT_EXPR_WITH_RET(_CModuleC.func(3.3f, 4.4f, out_par1, out_par2)); UT_EXPECT_NE_CHILD(out_par1, 7.f); UT_EXPECT_GT_CHILD(out_par2, 0.f);
	UT_EXPR_WITH_RET(_CModuleC.func(5.5f, 6.6f, out_par1, out_par2)); UT_EXPECT_LE_CHILD(out_par1, 20.f); UT_EXPECT_GE_CHILD(out_par2, 10.f);
	UT_EXPR_WITH_RET(_CModuleC.func(7.7f, 8.8f, out_par1, out_par2)); UT_EXPECT_LT_CHILD(out_par1, 1.f); UT_EXPECT_LE_CHILD(out_par2, 2.f);
}
UT_END()

// End of file
