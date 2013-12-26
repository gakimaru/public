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

//���j�b�g�e�X�g
//#define UT_IS_ESPECIALLY false //�ʏ�͂��̃}�N����L����������ԂŃR�~�b�g���鎖�I
#define UT_IS_ESPECIALLY true //�P�Ǝ��s�������������ꎞ�I�ɂ��̃}�N����L�������āA���j�b�g�e�X�g��P�ƃ��[�h�Ŏ��s����
UT_BEGIN(CModuleB, UT_IS_ESPECIALLY)//���W���[�������w�肷��B�@�����̃��j�b�g�e�X�g���W���[���Ɩ��O���d�����Ȃ��悤�ɒ��ӁI
                                    //                          �����W���[�������}�N���Ŏw�肷�鎖���s�I�i�}�N���������W���[�����ɂȂ��Ă��܂��j
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
