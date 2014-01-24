#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#include <windows.h>
#include <process.h>

//�X���b�h���[�J���X�g���[�W(TLS)�e�X�g
__declspec(thread) unsigned int tls_tid = 0;//Visual C++�ŗL��TLS�w��
//thread_local unsigned int tls_tid = 0;//C++11�d�l��TLS�w��FVisual C++ 2013 �ł͖��Ή�

//�e�X�g�p���
struct TEST_INFO
{
	const char* text;//������
	int value;       //���l
	int loop_max;    //�e�X�g���[�v��
	int start_i;     //�X���b�h�������[�v�J�n�l
};

//�X���b�h���
struct THREAD_INFO
{
	int level;              //�q�X���b�h���x��
	unsigned int parent_tid;//�e�X���b�hID
	bool is_root_thread;    //�匳�̃X���b�h����p�t���O
};

//�X���b�h�󂯓n�����
struct THREAD_PARAM
{
	TEST_INFO test;    //�e�X�g�p���
	THREAD_INFO thread;//�X���b�h���
};

//�q�X���b�h�̐����ƏI���҂�
extern void createChildThreads(const char* thread_name, TEST_INFO& test, THREAD_INFO& tinfo);

//�X���b�h�֐�
unsigned int WINAPI threadFunc(void* param_p)
{
	//�p�����[�^�󂯎��
	TEST_INFO test;
	THREAD_INFO tinfo;
	{
		THREAD_PARAM* param = (THREAD_PARAM*)param_p;
		memcpy(&test, &param->test, sizeof(TEST_INFO));
		memcpy(&tinfo, &param->thread, sizeof(THREAD_INFO));
	}

	//�X���b�h���
	unsigned int tid_tmp = GetCurrentThreadId();

	//�X���b�h���[�J���X�g���[�W(TLS)�e�X�g
	tls_tid = tid_tmp;

	//�匳�̃X���b�h����p�t���O��OFF
	tinfo.is_root_thread = false;

	//�X���b�h�����쐬
	++tinfo.level;
	char thread_name[32];
	sprintf_s(thread_name, sizeof(thread_name), "C%d(%5d,%5d)", tinfo.level, tid_tmp, tinfo.parent_tid);
	// C + �q�X���b�h�̃��x�� + ( ���X���b�hID , �e�X���b�hID )

	//�q�X���b�h�J�n���b�Z�[�W
	printf("START: %s\n", thread_name);
	fflush(stdout);

	//�e�X�g�p�ϐ����X�V
	++test.value;
	++test.loop_max;

	//�e�X���b�hID���i�[
	tinfo.parent_tid = tid_tmp;

	//1�b�X���[�v
	Sleep(1000);

	//�q�X���b�h�̐����ƏI���҂�
	createChildThreads(thread_name, test, tinfo);

	//�q�X���b�h�I�����b�Z�[�W
	printf("END: %s\n", thread_name);
	fflush(stdout);

	return 0;
}

//�q�X���b�h�̐����ƏI���҂�
void createChildThreads(const char* thread_name, TEST_INFO& test, THREAD_INFO& tinfo)
{
	//�q�X���b�h�������[�v
	const int CHILD_THREAD_NUM = 3;
	HANDLE hthread[CHILD_THREAD_NUM];     //���������q�X���b�h�̃X���b�h�n���h��
	unsigned int tid[CHILD_THREAD_NUM];   //���������q�X���b�h�̃X���b�hID
	THREAD_PARAM* param[CHILD_THREAD_NUM];//�X���b�h�󂯓n���p�f�[�^
	for (int i = 0; i < test.start_i; ++i)
	{
		hthread[i] = INVALID_HANDLE_VALUE;
		tid[i] = 0;
		param[i] = NULL;
	}
	for (int i = test.start_i; i < CHILD_THREAD_NUM; ++i)
	{
		//�q�X���b�h�p�p�����[�^�쐬
		param[i] = (THREAD_PARAM*)malloc(sizeof(THREAD_PARAM));
		memcpy(&param[i]->test, &test, sizeof(TEST_INFO));
		memcpy(&param[i]->thread, &tinfo, sizeof(THREAD_INFO));
		param[i]->test.start_i = i + 1;

		//�q�X���b�h����
		unsigned int tid_tmp = 0;
		HANDLE hthread_tmp = (HANDLE)_beginthreadex(NULL, 0, threadFunc, (void*)(param[i]), 0, &tid_tmp);
		if (hthread_tmp == (HANDLE)1L || hthread_tmp == INVALID_HANDLE_VALUE)
		{
			//�q�X���b�h�������s
			free(param[i]);
			param[i] = NULL;

			//�G���[���b�Z�[�W
			if (tinfo.is_root_thread)
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", thread_name, i, errno);
			else
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", thread_name, i, errno);
			fflush(stderr);

			//1�b�X���[�v
			Sleep(1000);
		}
		else
		{
			//�q�X���b�h��������

			//�q�X���b�h�̃X���b�h�n���h����ID���L�^�i�Ō�̏I���҂��p�j
			hthread[i] = hthread_tmp;
			tid[i] = tid_tmp;

			//�q�X���b�h�������b�Z�[�W
			if (tinfo.is_root_thread)
				printf("%s -> [%d] CREATED:C%d(%5d,%5d)\n", thread_name, i, tinfo.level + 1, tid_tmp, tinfo.parent_tid);
			else
				printf("%s -> [%d] CREATED:C%d(%5d,%5d)\n", thread_name, i, tinfo.level + 1, tid_tmp, tinfo.parent_tid);
			fflush(stdout);

			//2�b�X���[�v
			Sleep(2000);
		}
	}

	//�_�~�[����
	for (int i = 0; i < test.loop_max; ++i)
	{
		//�_�~�[���b�Z�[�W�\��
		printf("[%s] ... Process(%d/%d): text=\"%s\",value=%d (tls_tid=%d)\n", thread_name, i + 1, test.loop_max, test.text, test.value, tls_tid);
		fflush(stdout);
		test.value += 10;

		//1�b�X���[�v
		Sleep(1000);
	}

	//�q�X���b�h�̏I���҂�
	for (int i = 0; i < CHILD_THREAD_NUM; ++i)
	{
		HANDLE hthread_tmp = hthread[i];
		unsigned int tid_tmp = tid[i];
		if (hthread_tmp != (HANDLE)1L && hthread_tmp != INVALID_HANDLE_VALUE)
		{
			//�E�F�C�g�J�n���b�Z�[�W
			printf("[%s] ... Wait(%5d) ...\n", thread_name, tid_tmp);
			fflush(stdout);

			//�E�F�C�g
			WaitForSingleObject(hthread_tmp, INFINITE);

			//���������
			free(param[i]);
			param[i] = NULL;

			//�E�F�C�g�������b�Z�[�W
			printf("[%s] ... Wait(%5d) End\n", thread_name, tid_tmp);
			fflush(stdout);
		}
	}
}

//Windows thread �e�X�g
int main(const int argc, const char* argv[])
{
	//�v���O�������s�J�n
	printf("- Start Thread Test -\n");
	fflush(stdout);

	//�e�X�g�p�ϐ�
	TEST_INFO test =
	{
		"TEST",   //text
		1000,     //value
		1,        //loop_max
		0,        //start_i
	};

	//�X���b�h���
	THREAD_INFO tinfo =
	{
		0,   //level
		GetCurrentThreadId(),
		     //parent_tid
		true,//is_root_thread
	};

	//�X���b�h���[�J���X�g���[�W(TLS)�e�X�g
	tls_tid = tinfo.parent_tid;

	//�X���b�h�����쐬
	// P + �q�X���b�h�̃��x�� + ( ���X���b�hID , �e�X���b�hID )
	char thread_name[32];
	sprintf_s(thread_name, sizeof(thread_name), "P0(%5d,%5d)", tinfo.parent_tid, 0);

	//�q�X���b�h�̐����ƏI���҂�
	createChildThreads(thread_name, test, tinfo);

	//�v���O�������s�I��
	printf("- End Thread Test -\n");
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
