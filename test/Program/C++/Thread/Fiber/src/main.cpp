#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//�X���b�h���[�J���X�g���[�W(TLS)
#define   _TLS __declspec(thread)//Visual C++�ŗL��TLS�w��
//#define _TLS thread_local      //C++11�d�l��TLS�w��FVisual C++ 2013 �ł͖��Ή�

//�t�@�C�o�[�X���b�h�Ǘ����
static const int FIBER_MAX = 3;      //�t�@�C�o�[�X���b�h�̍ő吔
_TLS LPVOID s_pFiler[FIBER_MAX] = {};//�t�@�C�o�[�X���b�h�̃C���X�^���X�̃|�C���^�[
_TLS int s_fiberNum = 0;             //�ғ����̃t�@�C�o�[�X���b�h��
_TLS int s_fiberNow = 0;             //���݂̃t�@�C�o�[�X���b�h

//�t�@�C�o�[�X���b�h�����݂��邩�H
//���Ǘ��p�̃X���b�h�͐��Ɋ܂߂Ȃ�
bool isExistFiberThread()
{
	return s_fiberNum > 1;
}

//�t�@�C�o�[�X���b�h�؂�ւ�
void switchNextFiber()
{
	if (s_fiberNum == 0)
	{
		fprintf(stdout, "Fiber thread is nothing.\n");
		return;
	}
	s_fiberNow = (s_fiberNow + 1) % s_fiberNum;
	fprintf(stdout, "Fiber thread No.%d is switched.\n", s_fiberNow);
	SwitchToFiber(s_pFiler[s_fiberNow]);
}

//�t�@�C�o�[�X���b�h��ǉ�
template<typename T>
bool addFiber(LPFIBER_START_ROUTINE func, const size_t stack_size, T param_p)
{
	if (s_fiberNum >= FIBER_MAX)
	{
		fprintf(stderr, "Fiber thread was not more added.\n");
		return false;
	}
	fprintf(stdout, "Fiber thread No.%d was added.\n", s_fiberNum);
	s_pFiler[s_fiberNum++] = CreateFiber(stack_size, func, (LPVOID)param_p);
	return true;
}

//���݂̃t�@�C�o�[�X���b�h���폜
void removeCurrentFiber()
{
	for (int i = s_fiberNow; i < s_fiberNum - 1; ++i)
	{
		s_pFiler[i] = s_pFiler[i + 1];
	}
	--s_fiberNum;
	fprintf(stdout, "Fiber thread No.%d was removed.\n", s_fiberNow);
	if (s_fiberNum == 0)
	{
		s_fiberNow = 0;
	}
	else
	{
		s_fiberNow = (s_fiberNum + s_fiberNow - 1) % s_fiberNum;
		switchNextFiber();//���g���폜�����炷���Ɏ��̃t�@�C�o�[�X���b�h�����s����
	}
}

//�t�@�C�o�[�X���b�h�֐�
void WINAPI fiberFunc(LPVOID param_p)
{
	//�p�����[�^�󂯎��
	const char* fiber_name = reinterpret_cast<const char*>(param_p);

	//�e�X�g����
	for (int i = 0; i < 3; ++i)
	{
		printf("fiberFunc(): [%s](%d)\n", fiber_name, i);
		
		switchNextFiber();//���̃X���b�h�ɐ�����ڂ�
	}

	//�Ō�Ɏ��g���폜����i�����Ɏ��̃X���b�h�ɐ�����ڂ��j
	removeCurrentFiber();
	
	//���֐��� return ����ƁA���̎��_�ŃX���b�h�ifiberMain�j��
	//�@�I������̂Œ��ӁI
	//  �i�t�@�C�o�[�X���b�h�̐؂�ւ��́A�֐��Ăяo���ƈ����
	//  �P���ȃv���O�����J�E���^�[�̐؂�ւ��Ȃ̂ŁAreturn ����ƁA
	//  fiberMain() �� return �Ƃ݂Ȃ���Ă��܂��j
}

//�t�@�C�o�[�X���b�h�Ǘ��p�X���b�h�@���K�{
unsigned int WINAPI fiberMain(void* param_p)
{
	//�X���b�h���t�@�C�o�[�X���b�h�Ƃ��ēo�^
	//�����̃t�@�C�o�[�X���b�h�Ə�����؂�ւ���K�v�����邽��
	//�@�Ǘ��X���b�h���t�@�C�o�[�X���b�h�̈�ɂ���B
	//��main() ���猩����A���ʂ̃X���b�h�ł��邱�Ƃɕς��͂Ȃ��B
	s_pFiler[s_fiberNum++] = ConvertThreadToFiber(NULL);
	
	//�t�@�C�o�[�X���b�h��ǉ�
	addFiber(fiberFunc, 1024, "���Y");
	addFiber(fiberFunc, 1024, "���Y");
	
	//�t�@�C�o�[�X���b�h��؂�ւ��Ȃ���A�S�Ċ�������̂�҂�
	fprintf(stdout, "- loop: start -\n");
	while (isExistFiberThread())
	{
		switchNextFiber();//�t�@�C�o�[�X���b�h�̐؂�ւ�
		fprintf(stdout, "- loop -\n");
		Sleep(0);//���̃X���b�h�ɐ؂�ւ�
	}
	fprintf(stdout, "- loop: end -\n");

	//�t�@�C�o�[�X���b�h���폜
	removeCurrentFiber();
	
	return 0;
}

//���C��
int main(const int argc, const char* argv[])
{
	fprintf(stdout, "- Fiber Thread Test: BEGIN -\n");

	//�t�@�C�o�[�X���b�h�Ǘ��p�̃X���b�h�𐶐�
	unsigned int tid = 0;
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, fiberMain, nullptr, 0, &tid);

	//�t�@�C�o�[�X���b�h�Ǘ��X���b�h�I���҂�
	WaitForSingleObject(hThread, INFINITE);
	
	fprintf(stdout, "- Fiber Thread Test: END -\n");

	return EXIT_SUCCESS;
}

// End of file
