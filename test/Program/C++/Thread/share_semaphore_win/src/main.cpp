#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//�Z�}�t�H�n���h��
static HANDLE s_hSemaphore = INVALID_HANDLE_VALUE;

//�N���e�B�J���Z�N�V����
static CRITICAL_SECTION s_lock;

//���L���\�[�X
static const int COMMON_RESOURCE_NUM = 2;
static int s_commonResource[COMMON_RESOURCE_NUM]       = {};//�����̋��L���\�[�X
static bool s_usingCommonResource[COMMON_RESOURCE_NUM] = {};//���L���\�[�X�g�p���t���O

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
		//�Z�}�t�H�擾
		WaitForSingleObject(s_hSemaphore, INFINITE);//�擾�ł��Ȃ����ɑ��̏������s�������ꍇ�̓^�C���A�E�g�l���w�肷��

		//���L���\�[�X���l��
		int index = 0;
		EnterCriticalSection(&s_lock);//�N���e�B�J���Z�N�V�����擾
		for (; index < COMMON_RESOURCE_NUM; ++index)
		{
			if (!s_usingCommonResource[index])
				break;
		}
		s_usingCommonResource[index] = true;
		LeaveCriticalSection(&s_lock);//�N���e�B�J���Z�N�V�������

		//�f�[�^�\���i�O�j
		printf("%s: [BEFORE] commonResource[%d]=%d, tlsData=%d\n", name, index, s_commonResource[index], s_tlsData);
		fflush(stdout);

		//�f�[�^�擾
		int common_data = s_commonResource[index];
		int tls_data = s_tlsData;

		//�f�[�^�X�V
		++common_data;
		++tls_data;

		//�኱�����_���ŃX���[�v�i0�`4 msec�j
		Sleep(rand() % 5);

		//�f�[�^�����߂�
		s_commonResource[index] = common_data;
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("%s: [AFTER]  commonResource[%d]=%d, tlsData=%d\n", name, index, s_commonResource[index], s_tlsData);
		fflush(stdout);

		//���L���\�[�X�����
		s_usingCommonResource[index] = false;
		
		//�Z�}�t�H���
		LONG prev_count;
		ReleaseSemaphore(s_hSemaphore, 1, &prev_count);

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
	//�Z�}�t�H����
	{
		s_hSemaphore = CreateSemaphore(nullptr, 0, COMMON_RESOURCE_NUM, nullptr);//������Ԃ̓Z�}�t�H��S�Ďg�p���ɂ���
		
	//	//�������w�肵�Đ�������ꍇ
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, true };//�q�v���Z�X�Ƀn���h�����p������
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, false };//�q�v���Z�X�Ƀn���h�����p�����Ȃ��@���f�t�H���g
	//	s_hSemaphore = CreateSemaphore(&attr, 0, COMMON_RESOURCE_NUM, nullptr);//������Ԃ̓Z�}�t�H��S�Ďg�p���ɂ���
	}

	//�N���e�B�J���Z�N�V��������
	InitializeCriticalSectionAndSpinCount(&s_lock, 100);

	//�X���b�h�쐬
	static const int THREAD_NUM = 4;
	unsigned int tid[THREAD_NUM] = {};
	HANDLE hThread[THREAD_NUM] =
	{
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "���Y", 0, &tid[0]),
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "���Y", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "�O�Y", 0, &tid[2]),
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "�l�Y", 0, &tid[3])
	};

	//�኱�X���[�v
	Sleep(10);

	//���L���\�[�X������
	for (int i = 0; i < COMMON_RESOURCE_NUM; ++i)
	{
		s_commonResource[i] = 1000 * (i + 1);
	}

	//�኱�X���[�v
	Sleep(10);

	//���L���\�[�X�̎g�p�����i�S�Z�}�t�H����j
	{
		LONG prev_count;
		ReleaseSemaphore(s_hSemaphore, COMMON_RESOURCE_NUM, &prev_count);
		printf("Common-resources have been prepared. (num=%d -> %d)\n", prev_count, COMMON_RESOURCE_NUM);
		fflush(stdout);
	}

	//�X���b�h�I���҂�
	WaitForMultipleObjects(THREAD_NUM, hThread, true, INFINITE);

	//�X���b�h�n���h���N���[�Y
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		CloseHandle(hThread[i]);
	}

	//�Z�}�t�H�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			WaitForSingleObject(s_hSemaphore, INFINITE);
			ReleaseSemaphore(s_hSemaphore, 1, nullptr);
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Semaphore * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//�N���e�B�J���Z�N�V�����j��
	DeleteCriticalSection(&s_lock);
	
	//�Z�}�t�H�j��
	CloseHandle(s_hSemaphore);
	s_hSemaphore = INVALID_HANDLE_VALUE;

	return EXIT_SUCCESS;
}

// End of file
