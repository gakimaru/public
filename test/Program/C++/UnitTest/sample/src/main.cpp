#include <stdio.h>
#include <stdlib.h>

#include "game/game_main.h"

int main(const int argc, const char* argv[])
{
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

