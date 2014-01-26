#include <stdio.h>
#include <stdlib.h>

#include <condition_variable>
#include <mutex>
#include <thread>

#include <Windows.h> //���Ԍv���p

//�X���b�h���
static const int FOLLOW_THREAD_MAX = 10;          //�㑱�X���b�h�ő吔
static volatile LONG s_followThreadNum = 0;       //�㑱�X���b�h��
static volatile LONG s_followThreadNo = 0;        //�㑱�X���b�h�ԍ����ԗp
static volatile bool s_IsQuirProiorThread = false;//��s�X���b�h�I���t���O

//�����ϐ�
//�������ϐ��́A�K�������ϐ��{�~���[�e�b�N�X�{�ϐ��̃Z�b�g�ň���
static std::condition_variable s_followCond[FOLLOW_THREAD_MAX];//�㑱�X���b�h�������������ϐ�
static std::mutex s_followCondMutex[FOLLOW_THREAD_MAX];        //�㑱�X���b�h�������������ϐ��~���[�e�b�N�X
static volatile bool s_followFinished[FOLLOW_THREAD_MAX];      //�㑱�X���b�h���������t���O

//���L�f�[�^
static int s_commonData = 0;

//�X���b�h�ŗL�f�[�^
__declspec(thread) int s_tlsData = 0;

//�y���������z
//��s�X���b�h�����L�f�[�^���쐬���A���ꂪ����������
//�����̌㑱�X���b�h���X�^�[�g�B
//�㑱�X���b�h�͋��L�f�[�^��ǂݍ��ނ����̂��߁A����œ���B
//�㑱�X���b�h�̏������S�Ċ���������A�܂���s�X���b�h���ғ��B
//�ȏ�����x���J��Ԃ��A��s�X���b�h���I��������S�X���b�h�I���B
//�����C�����[�v�˕`��X���b�h�̂悤�ȃ����[�����ւ̉��p��z��B

//��s�X���b�h
void priorThreadFunc(const char* name)
{
	//�J�n
	printf("- begin:(P)%s -\n", name);
	fflush(stdout);

	//������
	s_IsQuirProiorThread = false;//��s�����I���t���O

	//����
	static const int LOOP_COUNT_MAX = 3;
	int loop_counter = 0;
	while (1)
	{
		//�S�㑱�X���b�h���������҂�
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			{
				std::unique_lock<std::mutex> lock(s_followCondMutex[i]);//���b�N�擾�i�u���b�N���甲���鎞�Ɏ�������j
				while (!s_followFinished[i])//�ҋ@�I�������𖞂����Ă��Ȃ��ꍇ
					s_followCond[i].wait(lock);//�ҋ@�i���b�N�J�����ҋ@���ҋ@�I�������b�N�擾���s����j
			}
		}

		//���[�v�J�E���^�i�s���I������
		if (loop_counter++ == LOOP_COUNT_MAX)
		{
			//�����I��
			printf("(P)%s: [QUIT]\n", name);
			fflush(stdout);
			
			//��s�X���b�h�I���t���O
			s_IsQuirProiorThread = true;
			
			//��s�X���b�h���������F�S�ҋ@�X���b�h���N��
			for (int i = 0; i < s_followThreadNum; ++i)
			{
				{
					std::unique_lock<std::mutex> lock(s_followCondMutex[i]);//���b�N�擾�i�u���b�N���甲���鎞�Ɏ�������j
					s_followFinished[i] = false;//�㑱�X���b�h�̏���������Ԃ�����
					s_followCond[i].notify_one();//�����҂����Ă���X���b�h�ɒʒm
				}
			}

			break;
		}

		//�f�[�^�\���i�O�j
		printf("(P)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//�f�[�^�擾
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//�f�[�^�X�V
		++common_data;
		++tls_data;

		//�኱�����_���ŃX���[�v�i0�`499 msec�j
		Sleep(rand() % 500);

		//�f�[�^�����߂�
		s_commonData = common_data;
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("(P)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//��s�X���b�h���������F�S�ҋ@�X���b�h���N��
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			{
				std::unique_lock<std::mutex> lock(s_followCondMutex[i]);//���b�N�擾�i�u���b�N���甲���鎞�Ɏ�������j
				s_followFinished[i] = false;//�㑱�X���b�h�̏���������Ԃ�����
				s_followCond[i].notify_one();//�����҂����Ă���X���b�h�ɒʒm
			}
		}

		//�X���b�h�؂�ւ��̂��߂̃X���[�v
		Sleep(0);
	//	//�X���b�h�؂�ւ�
	//	SwitchToThread();//OS�ɔC���čăX�P�W���[�����O
	//	Yield();//�p�~
	}

	//�I��
	printf("- end:(P)%s -\n", name);
	fflush(stdout);
}

//�㑱�X���b�h
void followThreadFunc(const char* name)
{
	//�㑱�X���b�h���J�E���g�A�b�v
	LONG thread_no = InterlockedIncrement(&s_followThreadNo) - 1;

	//�J�n
	printf("- begin:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);

	//�p���X���b�h���������F�ҋ@�X���b�h���N��
	{
		std::unique_lock<std::mutex> lock(s_followCondMutex[thread_no]);//���b�N�擾�i�u���b�N���甲���鎞�Ɏ�������j
		s_followFinished[thread_no] = true;//�㑱�X���b�h�̏���������Ԃ�ON
		s_followCond[thread_no].notify_one();//�����҂����Ă���X���b�h�ɒʒm
	}

	//����
	while (1)
	{
		//��s�X���b�h���������҂�
		{
			std::unique_lock<std::mutex> lock(s_followCondMutex[thread_no]);//���b�N�擾�i�u���b�N���甲���鎞�Ɏ�������j
			while (s_followFinished[thread_no])//�ҋ@�I�������𖞂����Ă��Ȃ��ꍇ
				s_followCond[thread_no].wait(lock);//�ҋ@�i���b�N�J�����ҋ@���ҋ@�I�������b�N�擾���s����j
		}

		//�I���m�F
		if (s_IsQuirProiorThread)
		{
			//�����I��
			printf("(F)[%d]%s: [QUIT]\n", thread_no, name);
			fflush(stdout);
			
			//�p���X���b�h���������F�ҋ@�X���b�h���N��
			{
				std::unique_lock<std::mutex> lock(s_followCondMutex[thread_no]);//���b�N�擾�i�u���b�N���甲���鎞�Ɏ�������j
				s_followFinished[thread_no] = true;//�㑱�X���b�h�̏���������Ԃ�ON
				s_followCond[thread_no].notify_one();//�����҂����Ă���X���b�h�ɒʒm
			}
			
			break;
		}

		//�f�[�^�\���i�O�j
		printf("(F)[%d]%s: [BEFORE] commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);

		//�f�[�^�擾
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//�f�[�^�X�V
		++tls_data;

		//�኱�����_���ŃX���[�v�i0�`500 msec�j
		Sleep(rand() % 500);

		//�f�[�^�����߂�
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("(F)[%d]%s: [AFTER]  commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);
		
		//�p���X���b�h���������F�ҋ@�X���b�h���N��
		{
			std::unique_lock<std::mutex> lock(s_followCondMutex[thread_no]);//���b�N�擾�i�u���b�N���甲���鎞�Ɏ�������j
			s_followFinished[thread_no] = true;//�㑱�X���b�h�̏���������Ԃ�ON
			s_followCond[thread_no].notify_one();//�����҂����Ă���X���b�h�ɒʒm
		}

		//�X���b�h�؂�ւ��̂��߂̃X���[�v
		Sleep(0);
	//	//�X���b�h�؂�ւ�
	//	SwitchToThread();//OS�ɔC���čăX�P�W���[�����O
	//	Yield();//�p�~
	}

	//�I��
	printf("- end:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	//�X���b�h�쐬
	static const int FOLLOW_THREAD_NUM = 5;
	static const int THREAD_NUM = 1 + FOLLOW_THREAD_NUM;
	static_assert(FOLLOW_THREAD_NUM <= FOLLOW_THREAD_MAX, "THREAD_NUM is over.");
	s_followThreadNum = FOLLOW_THREAD_NUM;
	for (int i = 0; i < THREAD_NUM - 1; ++i)
		s_followFinished[i] = true;
	static_assert(THREAD_NUM - 1 <= FOLLOW_THREAD_MAX, "THREAD_NUM is over.");
	std::thread thread_obj00 = std::thread(priorThreadFunc, "��s");
	std::thread thread_obj01 = std::thread(followThreadFunc, "�㑱01");
	std::thread thread_obj02 = std::thread(followThreadFunc, "�㑱02");
	std::thread thread_obj03 = std::thread(followThreadFunc, "�㑱03");
	std::thread thread_obj04 = std::thread(followThreadFunc, "�㑱04");
	std::thread thread_obj05 = std::thread(followThreadFunc, "�㑱05");

	//�X���b�h�I���҂�
	thread_obj00.join();
	thread_obj01.join();
	thread_obj02.join();
	thread_obj03.join();
	thread_obj04.join();
	thread_obj05.join();

	//�C�x���g�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			{
				std::unique_lock<std::mutex> lock(s_followCondMutex[0]);
				s_followFinished[0] = true;
				s_followCond[0].notify_one();
			}
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float time = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Event * %d = %.6f sec\n", TEST_TIMES, time);
	}

	return EXIT_SUCCESS;
}

// End of file
