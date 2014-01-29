#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//�X���b�h���
static const int FOLLOW_THREAD_MAX = 10;          //�㑱�X���b�h�ő吔
static volatile LONG s_followThreadNum = 0;       //�㑱�X���b�h��
static volatile LONG s_followThreadNo = 0;        //�㑱�X���b�h�ԍ����ԗp
static volatile bool s_IsQuirProiorThread = false;//��s�X���b�h�I���t���O

//�C�x���g�n���h��
static HANDLE s_hPriorEvent[FOLLOW_THREAD_MAX]; //��s�X���b�h���������C�x���g
static HANDLE s_hFollowEvent[FOLLOW_THREAD_MAX];//�㑱�X���b�h���������C�x���g

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
		WaitForMultipleObjects(s_followThreadNum, s_hFollowEvent, true, INFINITE);

		//���[�v�J�E���^�i�s���I������
		if (loop_counter++ == LOOP_COUNT_MAX)
		{
			//�����I��
			printf("(P)%s: [QUIT]\n", name);
			fflush(stdout);
			
			//��s�X���b�h�I���t���O
			s_IsQuirProiorThread = true;
			
			//��s�X���b�h���������C�x���g�Z�b�g
			for (int i = 0; i < s_followThreadNum; ++i)
				SetEvent(s_hPriorEvent[i]);

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

		//��s�X���b�h���������C�x���g�Z�b�g
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			SetEvent(s_hPriorEvent[i]);
		}
		//��PulseEvent() �� SetEvent() �̂悤�ɁA��s���ăV�O�i����Ԃ����悤�Ȃ��Ƃ��ł����A
		//�@PulseEvent() ���s�̃^�C�~���O�őҋ@���Ă�����̂��J�����邾�������ł��Ȃ��B
		//�@�Ȃ̂ŁAPulseEvent() ���g�p�����A�q�̐����̃C�x���g���g�p����B

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

	//�㑱�X���b�h���������C�x���g�Z�b�g
	SetEvent(s_hFollowEvent[thread_no]);

	//����
	while (1)
	{
		//��s�X���b�h���������C�x���g�҂�
		WaitForSingleObject(s_hPriorEvent[thread_no], INFINITE);//�擾�ł��Ȃ����ɑ��̏������s�������ꍇ�̓^�C���A�E�g�l���w�肷��
		
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
		
		//�㑱�X���b�h���������C�x���g�Z�b�g
		SetEvent(s_hFollowEvent[thread_no]);

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
	//�C�x���g����
	{
		for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
		{
			s_hPriorEvent[i] = CreateEvent(nullptr, false, false, nullptr);//�蓮���Z�b�g=false�i�������Z�b�g�j, �������=false�i���Z�b�g��ԁj
			s_hFollowEvent[i] = CreateEvent(nullptr, false, false, nullptr);//�蓮���Z�b�g=false�i�������Z�b�g�j, �������=false�i���Z�b�g��ԁj
		}

	//	//�������w�肵�Đ�������ꍇ
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, true };//�q�v���Z�X�Ƀn���h�����p������
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, false };//�q�v���Z�X�Ƀn���h�����p�����Ȃ��@���f�t�H���g
	//	for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
	//	{
	//		s_hPriorEvent[i] = CreateEvent(&attr, true, false, nullptr);
	//		s_hFollowEvent[i] = CreateEvent(&attr, false, false, nullptr);
	//	}
	}

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

	//�C�x���g�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			SetEvent(s_hPriorEvent[0]);
		//	WaitForSingleObject(s_hPriorEvent[0], INFINITE);
		//	ResetEvent(s_hPriorEvent[0]);
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Event * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//�C�x���g�j��
	for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
	{
		CloseHandle(s_hPriorEvent[i]);
		s_hPriorEvent[i] = INVALID_HANDLE_VALUE;
		CloseHandle(s_hFollowEvent[i]);
		s_hFollowEvent[i] = INVALID_HANDLE_VALUE;
	}

	return EXIT_SUCCESS;
}

// End of file