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
#define UT_IS_ESPECIALLY false //�ʏ�͂��̃}�N����L����������ԂŃR�~�b�g���鎖�I
//#define UT_IS_ESPECIALLY true //�P�Ǝ��s�������������ꎞ�I�ɂ��̃}�N����L�������āA���j�b�g�e�X�g��P�ƃ��[�h�Ŏ��s����
UT_BEGIN(CModuleA, UT_IS_ESPECIALLY)//���W���[�������w�肷��B�@�����̃��j�b�g�e�X�g���W���[���Ɩ��O���d�����Ȃ��悤�ɒ��ӁI
                                    //                          �����W���[�������}�N���Ŏw�肷�鎖���s�I�i�}�N���������W���[�����ɂȂ��Ă��܂��j
{
	CModuleA _CModuleA;
	UT_EXPECT(_CModuleA.func(1, 2), == , 3);
	UT_EXPECT(_CModuleA.func(3, 4), == , 7);
	UT_EXPECT(_CModuleA.func(4, 5), != , 9);
}
UT_END()

// End of file
