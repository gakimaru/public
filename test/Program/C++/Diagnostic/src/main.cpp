#include <stdlib.h>
#include <windows.h>

int main(const int argc, const char* argv[])
{
	//�v���Z�X�D��x�ύX
	HANDLE hProcess = GetCurrentProcess();//���݂̃v���Z�X�n���h�����擾
	SetPriorityClass(hProcess, REALTIME_PRIORITY_CLASS);//�D��x�����A���^�C���i�ō��j�ɕύX
	
	//�X���b�h�D��x�ύX
	HANDLE hThread = GetCurrentThread();//���݂̃X���b�h�n���h�����擾
	SetThreadPriority(hThread, THREAD_PRIORITY_TIME_CRITICAL);//���ΗD�揇�ʂ��ō��ɕύX

	//�������[�v
	while (1);

	return EXIT_SUCCESS;
}

// End of file
