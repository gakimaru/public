#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//�X���b�h���
static const int FOLLOW_THREAD_MAX = 10;          //�㑱�X���b�h�ő吔
static volatile LONG s_followThreadNum = 0;       //�㑱�X���b�h��
static volatile LONG s_followThreadNo = 0;        //�㑱�X���b�h�ԍ����ԗp
static volatile bool s_IsQuirProiorThread = false;//��s�X���b�h�I���t���O

//���j�^�[�p�ϐ�
enum E_PROCESS
{
	PRIOR_RUNNING, //��s�������s��
	PRIOR_IDLE,    //��s�����A�C�h�����
	FOLLOW_RUNNING,//�㑱�������s��
	FOLLOW_IDLE,   //�㑱�����A�C�h�����
};
static LONG s_followFinished[FOLLOW_THREAD_MAX];//�㑱�X���b�h���������t���O

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
unsigned int WINAPI priorThreadFunc(void* param_p)
{
	//�p�����[�^�󂯎��
	const char* name = static_cast<const char*>(param_p);

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
			E_PROCESS prev = E_PROCESS::FOLLOW_IDLE;
			while (InterlockedCompareExchange(&s_followFinished[i], E_PROCESS::PRIOR_RUNNING, E_PROCESS::FOLLOW_IDLE) != E_PROCESS::FOLLOW_IDLE){}
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
				s_followFinished[i] = E_PROCESS::PRIOR_IDLE;
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
			s_followFinished[i] = E_PROCESS::PRIOR_IDLE;
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
	return 0;
}

//�㑱�X���b�h
unsigned int WINAPI followThreadFunc(void* param_p)
{
	//�p�����[�^�󂯎��
	const char* name = static_cast<const char*>(param_p);

	//�㑱�X���b�h���J�E���g�A�b�v
	LONG thread_no = InterlockedIncrement(&s_followThreadNo) - 1;

	//�J�n
	printf("- begin:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);

	//�p���X���b�h���������F�ҋ@�X���b�h���N��
	s_followFinished[thread_no] = E_PROCESS::FOLLOW_IDLE;

	//����
	while (1)
	{
		//��s�X���b�h���������҂�
		while (InterlockedCompareExchange(&s_followFinished[thread_no], E_PROCESS::FOLLOW_RUNNING, E_PROCESS::PRIOR_IDLE) != E_PROCESS::PRIOR_IDLE){}

		//�I���m�F
		if (s_IsQuirProiorThread)
		{
			//�����I��
			printf("(F)[%d]%s: [QUIT]\n", thread_no, name);
			fflush(stdout);

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
		s_followFinished[thread_no] = E_PROCESS::FOLLOW_IDLE;

		//�X���b�h�؂�ւ��̂��߂̃X���[�v
		Sleep(0);
	//	//�X���b�h�؂�ւ�
	//	SwitchToThread();//OS�ɔC���čăX�P�W���[�����O
	//	Yield();//�p�~
	}

	//�I��
	printf("- end:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);
	return 0;
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	//������
	for (int i = 0; i < s_followThreadNum; ++i)
		s_followFinished[i] = E_PROCESS::FOLLOW_IDLE;

	//�X���b�h�쐬
	static const int FOLLOW_THREAD_NUM = 5;
	static const int THREAD_NUM = 1 + FOLLOW_THREAD_NUM;
	static_assert(FOLLOW_THREAD_NUM <= FOLLOW_THREAD_MAX, "FOLLOW_THREAD_NUM is over.");
	s_followThreadNum = FOLLOW_THREAD_NUM;
	unsigned int tid[THREAD_NUM] = {};
	HANDLE hThread[THREAD_NUM] =
	{
		(HANDLE)_beginthreadex(nullptr, 0, priorThreadFunc, "��s", 0, &tid[0]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "�㑱01", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "�㑱02", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "�㑱03", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "�㑱04", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "�㑱05", 0, &tid[1]),
	};
	
	//�X���b�h�I���҂�
	WaitForMultipleObjects(THREAD_NUM, hThread, true, INFINITE);

	//�X���b�h�n���h���N���[�Y
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		CloseHandle(hThread[i]);
	}

	//�C���^�[���b�N������ʂɎ��s���Ď��Ԃ��v��
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		s_followFinished[0] = E_PROCESS::FOLLOW_IDLE;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (InterlockedCompareExchange(&s_followFinished[0], E_PROCESS::PRIOR_RUNNING, E_PROCESS::FOLLOW_IDLE) != E_PROCESS::FOLLOW_IDLE){}
			while (InterlockedCompareExchange(&s_followFinished[0], E_PROCESS::PRIOR_IDLE, E_PROCESS::PRIOR_RUNNING) != E_PROCESS::PRIOR_RUNNING){}
			while (InterlockedCompareExchange(&s_followFinished[0], E_PROCESS::FOLLOW_RUNNING, E_PROCESS::PRIOR_IDLE) != E_PROCESS::PRIOR_IDLE){}
			while (InterlockedCompareExchange(&s_followFinished[0], E_PROCESS::FOLLOW_IDLE, E_PROCESS::FOLLOW_RUNNING) != E_PROCESS::FOLLOW_RUNNING){}
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Event * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	return EXIT_SUCCESS;
}

// End of file
