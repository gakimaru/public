#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#include <unistd.h>
#include <sys/wait.h>

//fork �e�X�g
int main(const int argc, const char* argv[])
{
	//�v���O�������s�J�n
	printf("- Start Fork Test -\n");
	fflush(stdout);
	
	//�e�X�g�p�ϐ�
	const char* test_text = "TEST";
	int test_value = 1000;
	int test_loop_max = 1;
	
	//�v���Z�X�����쐬
	// P + �q�v���Z�X�̃��x�� + ( ���v���Z�XID , �e�v���Z�XID )
	char process_name[32];
	sprintf(process_name, "P0(%5d,%5d)", getpid(), getppid());
	int level = 0;
	
	//�匳�̃v���Z�X����p�t���O�i�����l�� true�j
	bool is_root_process = true;
	
	//�q�v���Z�X�������[�v
	const int CHILD_THREAD_NUM = 3;
	pid_t pid[CHILD_THREAD_NUM];//���������q�v���Z�X�̃v���Z�XID
	for(int i = 0; i < CHILD_THREAD_NUM; ++i)
	{
		//�q�v���Z�X����
		pid_t pid_tmp = fork();
		//��fork()�����s���ꂽ�u�ԂɎq�v���Z�X�����������B
		//���q�v���Z�X�́A�e�v���Z�X�̐ÓI�ϐ���X�^�b�N�i�����ϐ��j�A���s�ʒu�i�v���O�����J�E���^�j�A
		//�@����сA�I�[�v�����̃t�@�C���f�B�X�N���v�^���R�s�[���āA�V�����v���Z�X�����B
		//�����s�ʒu���R�s�[����邽�߁A�q�v���Z�X�͂��̈ʒu����X�^�[�g����B
		//�@���ׂĂ̕ϐ��̒l�������p�����邪�A�����������L����킯�ł͂Ȃ��B
		//�@�����܂ł����̎��_�̓��e���R�s�[����邾���B
		
		//�������ʊm�F
		switch(pid_tmp)
		{
		//fork �����F���v���Z�X���u�������ꂽ�q�v���Z�X�v�̏ꍇ
		case 0:
			//�匳�̃v���Z�X����p�t���O��OFF
			is_root_process = false;
			
			//�v���Z�X�����쐬
			++ level;
			sprintf(process_name, "C%d(%5d,%5d)", level, getpid(), getppid());
			// C + �q�v���Z�X�̃��x�� + ( ���v���Z�XID , �e�v���Z�XID )
			
			//�q�v���Z�X�J�n���b�Z�[�W
			printf("START: %s\n", process_name);
			fflush(stdout);
			
			//�e�X�g�p�ϐ����X�V
			++test_value;
			++test_loop_max;
			
			//�e�v���Z�X�����������q�v���Z�X��ID�̃R�s�[����Ă��܂��Ă���̂ŃN���A����
			for(int ii = 0; ii <= i; ++ ii)
				pid[ii] = -1;
			
			//1�b�X���[�v
			sleep(1);
			
			break;
		
		//fork ���s
		case -1:
			//�G���[���b�Z�[�W
			if(is_root_process)
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", process_name, i, errno);
			else
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", process_name, i, errno);
			fflush(stderr);
			
			//1�b�X���[�v
			sleep(1);
			
			break;
		
		//fork �����F�q�v���Z�X�̐����ɐ������A�q�v���Z�X�̃v���Z�XID���擾
		default:
			//�q�v���Z�X�̃v���Z�XID���L�^�i�Ō�̏I���҂��p�j
			pid[i] = pid_tmp;
			
			//�q�v���Z�X�������b�Z�[�W
			if(is_root_process)
				printf("%s -> [%d] CREATED:C%d(%5d,%5d)\n", process_name, i, level + 1, pid_tmp, getpid());
			else
				printf("%s -> [%d] CREATED:C%d(%5d,%5d)\n", process_name, i, level + 1, pid_tmp, getpid());
			fflush(stdout);
			
			//2�b�X���[�v
			sleep(2);
			
			break;
		}
	}
	
	//�_�~�[����
	for(int i = 0; i < test_loop_max; ++i)
	{
		//�_�~�[���b�Z�[�W�\��
		printf("[%s] ... Process(%d/%d): text=\"%s\",value=%d\n", process_name, i + 1, test_loop_max, test_text, test_value);
		fflush(stdout);
		test_value += 10;
		
		//1�b�X���[�v
		sleep(1);
	}
	
	//�q�v���Z�X�̏I���҂�
	for(int i = 0; i < CHILD_THREAD_NUM; ++i)
	{
		pid_t pid_tmp = pid[i];
		if(pid_tmp > 0)
		{
			//�E�F�C�g�J�n���b�Z�[�W
			printf("[%s] ... Wait(%5d) ...\n", process_name, pid_tmp);
			fflush(stdout);
			
			//�E�F�C�g
			int status = -1;
			waitpid(pid_tmp, &status, WUNTRACED);
			
			//�E�F�C�g�������b�Z�[�W
			printf("[%s] ... Wait(%5d) End status=%d\n", process_name, pid_tmp, status);
			fflush(stdout);
		}
	}
	
	//���v���Z�X���q�v���Z�X�Ȃ炱�̎��_�Ŏ��s�I��
	if(!is_root_process)
	{
		//�q�v���Z�X�I�����b�Z�[�W
		printf("END: %s\n", process_name);
		fflush(stdout);
		
		//�v���Z�X�I��
		exit(0);
	}
	
	//�v���O�������s�I��
	printf("- End Fork Test -\n");
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
