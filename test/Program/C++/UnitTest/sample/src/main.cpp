#include <stdio.h>
#include <stdlib.h>

#include "game/game_main.h"

//�C���^�[�t�F�[�X�N���X
class ISample
{
public:
	virtual const char* getMessage() const = 0;
};
//��ۃN���X�@
class CTest1 : public ISample
{
public:
	virtual const char* getMessage() const { return "This is CTest1!"; }
};
//��ۃN���X�A
class CTest2 : public ISample
{
public:
	virtual const char* getMessage() const { return "This is CTest2!!!"; }
};
//���ʏ���
void testCommon(ISample& obj)
{
	printf("[%s]\n", obj.getMessage());
}
//�e�X�g
void testMain()
{
	CTest1 o1;
	CTest2 o2;
	testCommon(o1);
	testCommon(o2);
}

int main(const int argc, const char* argv[])
{
testMain();
	printf("- main() [BEGIN] ...\n");
	
	CGameMain* game_main = new CGameMain(argc, argv);

	//����������
	game_main->initialize();

	//���C������
	game_main->main();

	//�I������
	game_main->finalize(); 

	printf("- main() [END]\n");
	
	//main�֐��I��
//	exit(*game_main);  //exit() �����s����ƃf�X�g���N�^�����s����Ȃ��̂ŁA
	return *game_main; //��ނ𓾂Ȃ����f���ȊO�͂Ȃ�ׂ� main() �֐��� return ���g�����B
	                   //�Ȃ��A�ǂ�����g�p���Ă��A���ϐ� %ERRORLEVEL% �ɂ́A������ƌ��ʂ��Ԃ����B

//	return EXIT_SUCCESS; //stdlib.h �ɒ�`����Ă��鐳�펞�� return �l
//	return EXIT_FAILURE; //stdlib.h �ɒ�`����Ă���ُ펞�� return �l
}

// End of file

