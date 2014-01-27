#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//�N���e�B�J���Z�N�V����
static CRITICAL_SECTION s_criticalSection;

//���L�f�[�^
static int s_commonData = 0;

//�X���b�h�ŗL�f�[�^
__declspec(thread) int s_tlsData = 0;

//�X���b�h
unsigned int WINAPI threadFunc(void* param_p)
{
	//�p�����[�^�󂯎��
	const char* name = static_cast<const char*>(param_p);

	//�J�n
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//����
	for (int i = 0; i < 3; ++i)
	{
		//�N���e�B�J���Z�N�V�����擾
		EnterCriticalSection(&s_criticalSection);
	//	TryEnterCriticalSection(&s_criticalSection);//�擾�ł��Ȃ����ɑ��̏������s�������ꍇ�� TryEnterCriticalSection() ���g�p����

		//�f�[�^�\���i�O�j
		printf("%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//�f�[�^�擾
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//�f�[�^�X�V
		++common_data;
		++tls_data;

		//�኱�����_���ŃX���[�v�i0�`4 msec�j
		Sleep(rand() % 5);

		//�f�[�^�����߂�
		s_commonData = common_data;
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//�N���e�B�J���Z�N�V�������
		LeaveCriticalSection(&s_criticalSection);
		
		//�X���b�h�؂�ւ��̂��߂̃X���[�v
		Sleep(0);
	//	//�X���b�h�؂�ւ�
	//	SwitchToThread();//OS�ɔC���čăX�P�W���[�����O
	//	Yield();//�p�~
	}

	//�I��
	printf("- end:%s -\n", name);
	fflush(stdout);
	return 0;
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	//�N���e�B�J���Z�N�V����������
	InitializeCriticalSection(&s_criticalSection);
//	InitializeCriticalSectionAndSpinCount(&s_criticalSection, 1000);//�X�s�����b�N�J�E���g�����w�肷��ꍇ�i�X�s�����b�N��ɑҋ@����j�F�}���`�v���Z�b�T�V�X�e����p

	//�X���b�h�쐬
	static const int THREAD_NUM = 3;
	unsigned int tid[THREAD_NUM] = {};
	HANDLE hThread[THREAD_NUM] =
	{
		(HANDLE)_beginthreadex(nullptr, 0, threadFunc, "���Y", 0, &tid[0]),
		(HANDLE)_beginthreadex(nullptr, 0, threadFunc, "���Y", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, threadFunc, "�O�Y", 0, &tid[2])
	};
	
	//�X���b�h�I���҂�
	WaitForMultipleObjects(THREAD_NUM, hThread, true, INFINITE);

	//�X���b�h�n���h���N���[�Y
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		CloseHandle(hThread[i]);
	}

	//�N���e�B�J���Z�N�V�����̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			EnterCriticalSection(&s_criticalSection);
			LeaveCriticalSection(&s_criticalSection);
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Critical Section * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//�N���e�B�J���Z�N�V�����j��
	DeleteCriticalSection(&s_criticalSection);

	return EXIT_SUCCESS;
}

// End of file
