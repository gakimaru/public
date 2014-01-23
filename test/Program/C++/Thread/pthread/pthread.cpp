#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#include <pthread.h>
#include <unistd.h>

//�X���b�h���[�J���X�g���[�W(TLS)�e�X�g
__thread pthread_t tls_pth = 0;//CC��TLS�w��
//thread_local pthread_t tls_pth = 0;//C++11�d�l��

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
	int level;           //�q�X���b�h���x��
	pthread_t parent_pth;//�e�X���b�h_t
	bool is_root_thread; //�匳�̃X���b�h����p�t���O
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
void* threadFunc(void* param_p)
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
	pthread_t pth_tmp = pthread_self();
	
	//�X���b�h���[�J���X�g���[�W(TLS)�e�X�g
	tls_pth = pth_tmp;
	
	//�匳�̃X���b�h����p�t���O��OFF
	tinfo.is_root_thread = false;
	
	//�X���b�h�����쐬
	++ tinfo.level;
	char thread_name[32];
	sprintf(thread_name, "C%d(%010p,%010p)", tinfo.level, pth_tmp, tinfo.parent_pth);
	// C + �q�X���b�h�̃��x�� + ( ���X���b�h_t , �e�X���b�h_t )
	
	//�q�X���b�h�J�n���b�Z�[�W
	printf("START: %s\n", thread_name);
	fflush(stdout);
	
	//�e�X�g�p�ϐ����X�V
	++ test.value;
	++ test.loop_max;
	
	//�e�X���b�h_t���i�[
	tinfo.parent_pth = pth_tmp;
	
	//1�b�X���[�v
	sleep(1);
	
	//�q�X���b�h�̐����ƏI���҂�
	createChildThreads(thread_name, test, tinfo);
	
	//�q�X���b�h�I�����b�Z�[�W
	printf("END: %s\n", thread_name);
	fflush(stdout);
	
	return NULL;
}

//�q�X���b�h�̐����ƏI���҂�
void createChildThreads(const char* thread_name, TEST_INFO& test, THREAD_INFO& tinfo)
{
	//�q�X���b�h�������[�v
	const int CHILD_THREAD_NUM = 3;
	pthread_t pth[CHILD_THREAD_NUM];      //���������q�X���b�h�̃X���b�h_t
	THREAD_PARAM* param[CHILD_THREAD_NUM];//�X���b�h�󂯓n���p�f�[�^
	for(int i = 0; i < test.start_i; ++i)
	{
		pth[i] = 0;
		param[i] = NULL;
	}
	for(int i = test.start_i; i < CHILD_THREAD_NUM; ++i)
	{
		//�q�X���b�h�p�p�����[�^�쐬
		param[i] = (THREAD_PARAM*)malloc(sizeof(THREAD_PARAM));
		memcpy(&param[i]->test, &test, sizeof(TEST_INFO));
		memcpy(&param[i]->thread, &tinfo, sizeof(THREAD_INFO));
		param[i]->test.start_i = i + 1;
		
		//�q�X���b�h����
		pthread_t pth_tmp = 0;
		int ret = pthread_create((pthread_t*)&pth_tmp, NULL, threadFunc, (void*)(param[i]));
		if(ret != 0)
		{
			//�q�X���b�h�������s
			free(param[i]);
			param[i] = NULL;
			
			//�G���[���b�Z�[�W
			if(tinfo.is_root_thread)
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", thread_name, i, ret, errno);
			else
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", thread_name, i, ret, errno);
			fflush(stderr);
			
			//1�b�X���[�v
			sleep(1);
		}
		else
		{
			//�q�X���b�h��������
			
			//�q�X���b�h�̃X���b�h_t���L�^�i�Ō�̏I���҂��p�j
			pth[i] = pth_tmp;
			
			//�q�X���b�h�������b�Z�[�W
			if(tinfo.is_root_thread)
				printf("%s -> [%d] CREATED:C%d(%010p,%010p)\n", thread_name, i, tinfo.level + 1, pth_tmp, tinfo.parent_pth);
			else
				printf("%s -> [%d] CREATED:C%d(%010p,%010p)\n", thread_name, i, tinfo.level + 1, pth_tmp, tinfo.parent_pth);
			fflush(stdout);
			
			//2�b�X���[�v
			sleep(2);
		}
	}
	
	//�_�~�[����
	for(int i = 0; i < test.loop_max; ++i)
	{
		//�_�~�[���b�Z�[�W�\��
		printf("[%s] ... Process(%d/%d): text=\"%s\",value=%d (tls_tid=%010p)\n", thread_name, i + 1, test.loop_max, test.text, test.value, tls_pth);
		fflush(stdout);
		test.value += 10;
		
		//1�b�X���[�v
		sleep(1);
	}
	
	//�q�X���b�h�̏I���҂�
	for(int i = 0; i < CHILD_THREAD_NUM; ++i)
	{
		pthread_t pth_tmp = pth[i];
		if(pth_tmp > 0)
		{
			//�E�F�C�g�J�n���b�Z�[�W
			printf("[%s] ... Wait(%010p) ...\n", thread_name, pth_tmp);
			fflush(stdout);
			
			//�E�F�C�g
			pthread_join((pthread_t)pth_tmp, NULL);
			
			//���������
			free(param[i]);
			param[i] = NULL;
			
			//�E�F�C�g�������b�Z�[�W
			printf("[%s] ... Wait(%010p) End\n", thread_name, pth_tmp);
			fflush(stdout);
		}
	}
}

//posix thread �e�X�g
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
		pthread_self(),
		     //pareant_pth
		true,//is_root_thread
	};
	
	//�X���b�h���[�J���X�g���[�W(TLS)�e�X�g
	tls_pth = tinfo.parent_pth;
	
	//�X���b�h�����쐬
	// P + �q�X���b�h�̃��x�� + ( ���X���b�h_t , �e�X���b�h_t )
	char thread_name[32];
	sprintf(thread_name, "P0(%010p,%010p)", tinfo.parent_pth, 0);
	
	//�q�X���b�h�̐����ƏI���҂�
	createChildThreads(thread_name, test, tinfo);
	
	//�v���O�������s�I��
	printf("- End Thread Test -\n");
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
