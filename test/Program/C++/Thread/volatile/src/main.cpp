#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//�����I���t���O
bool s_isFinished = false;
//volatile bool s_isFinished = false;

//�X���b�h�P
unsigned int WINAPI func1(void* param_p)
{
	//�J�n
	printf("- func1(): start -\n");
	fflush(stdout);

	//����...
	printf("func1(): process ...\n");
	fflush(stdout);
	Sleep(1000);

	//�����I���ʒm
	s_isFinished = true;
	
	//�I��
	printf("- func1(): end -\n");
	fflush(stdout);
	return 0;
}

//�X���b�h�Q
unsigned int WINAPI func2(void* param_p)
{
	//�J�n
	printf("- func2(): start -\n");
	fflush(stdout);

	//�����I���҂�
	printf("func2(): wait ...\n");
	fflush(stdout);
	while (!s_isFinished){}
//	while (!s_isFinished){ Yield(); }
//	while (!s_isFinished){ Sleep(); }
	printf("func2(): ok!\n");
	fflush(stdout);

	//����...
	printf("func2(): process ...\n");
	fflush(stdout);
	Sleep(1000);

	//�I��
	printf("- func2(): end -\n");
	fflush(stdout);
	return 0;
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	//�J�n
	printf("- main(): start -\n");
	fflush(stdout);

	//�X���b�h�J�n
	HANDLE hThread[2] =
	{
		(HANDLE)_beginthreadex(nullptr, 0, func1, nullptr, 0, nullptr),
		(HANDLE)_beginthreadex(nullptr, 0, func2, nullptr, 0, nullptr)
	};

	//�X���b�h�v���C�I���e�B�e�X�g
//	SetPriorityClass(hThread[0], REALTIME_PRIORITY_CLASS);
//	SetPriorityClass(hThread[1], REALTIME_PRIORITY_CLASS);

	//�X���b�h�I���҂�
	WaitForMultipleObjects(2, hThread, true, INFINITE);


	//�I��
	printf("- main(): end -\n");
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
