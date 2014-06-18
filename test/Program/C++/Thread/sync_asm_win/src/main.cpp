//�R���p�C���X�C�b�`
#define CODE_TYPE 4// 0 ... CMPXCHG����
                   // 1 ... CMPXCHG����{�E�F�C�g���[�v
                   // 2 ... XCHG����
                   // 3 ... XCHG����{�E�F�C�g���[�v
                   // 4 ... BTS����
                   // 5 ... BTS����{�E�F�C�g���[�v
                   // 6 ... C++11 atomic
                   //-1 ... ���b�N�Ȃ�

#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

#if CODE_TYPE != 6//C++11 std::atomic����
//���b�N�擾�p�ϐ�
static int s_lock = 0;
#else//CODE_TYPE == 6//C++11 std::atomic����
#include <atomic>//C++11 �A�g�~�b�N�^
std::atomic_flag s_lock;//���b�N�p�ϐ�
#endif//CODE_TYPE

//���L�f�[�^
static int s_commonData = 0;

//�X���b�h�ŗL�f�[�^
__declspec(thread) int s_tlsData = 0;

//���b�N�擾
//��CAS�����
void lock()
{
#if CODE_TYPE == 0//CMPXCHG����
	__asm								//�C�����C���A�Z���u���iVC++�`��)
	{
	lock_loop:							//���[�v�p���x��
		//���b�N�擾����
		mov				eax, 0			//EAX �� 0�i���҂���t���O�̒l�j
		mov				edx, 1			//EDX �� 1�i���b�N�擾���̃t���O�̒l�j
		lock cmpxchg	[s_lock], edx	//LOCK�v���t�B�b�N�X�ŃA�g�~�b�N����w��
										//[s_lock] == EAX(0�j�Ȃ� [s_lock] �� EDX(1)
										//[s_lock] != EAX(0�j�Ȃ� EAX �� [s_lock]
		jnz				lock_loop		//NZ(Non Zero)�� [s_lock] != EAX �ł������ꍇ�ɊY��
										//���̃X���b�h�����b�N�擾���Ƃ������ƂȂ̂ŁA
										//���[�v�ʒu�ɃW�����v���Ă�蒼��
	}
#elif CODE_TYPE == 1//CMPXCHG����{�E�F�C�g���[�v
	__asm								//�C�����C���A�Z���u���iVC++�`��)
	{
	lock_loop:							//���[�v�p���x��
		//���b�N�擾�\��Ԋm�F
		mov				eax, [s_lock]	//EAX �� [s_lock]
		test			eax, eax		//EAX & EAX ? ��EAX == 0 ���`�F�b�N
		jnz				lock_loop		//EAX != 0 �Ȃ�A���̃X���b�h�����b�N�擾���Ƃ������ƂȂ̂ŁA
										//���[�v�ʒu�ɃW�����v���Ă�蒼��
		//���ۂ̃��b�N�擾����
		mov				edx, 1			//EDX �� 1�i���b�N�擾���̃t���O�̒l�j
		lock cmpxchg	[s_lock], edx	//LOCK�v���t�B�b�N�X�ŃA�g�~�b�N����w��
										//[s_lock] == EAX(0�j�Ȃ� [s_lock] �� EDX(1)
										//[s_lock] != EAX(0�j�Ȃ� EAX �� [s_lock]
		jnz				lock_loop		//NZ(Non Zero)�� [s_lock] != EAX �ł������ꍇ�ɊY��
										//���̃X���b�h�ɐ���z����Ă��܂����̂ŁA
										//���[�v�ʒu�ɃW�����v���Ă�蒼��
	}
#elif CODE_TYPE == 2//XCHG����
	__asm						//�C�����C���A�Z���u���iVC++�`��)
	{
	lock_loop:					//���[�v�p���x��
		//���b�N�擾����
		mov		eax, 1			//EAX �� 1�i���b�N�擾���̃t���O�̒l�j
		xchg	eax, [s_lock]	//XCHG���߂͈ÖٓI��LOCK�v���t�B�b�N�X�ŃA�g�~�b�N����w��
								//EAX ���� [s_lock] �i�����j
								//��EAX �� [s_lock], [s_lock] �� 1 �ɂȂ�
		test	eax, eax		//EAX & EAX ? ��EAX == 0 ���`�F�b�N
		jnz		lock_loop		//EAX == 0 �Ȃ�A���b�N�擾�����Ȃ̂ŏI��
								//EAX != 0�Ȃ�A���̃X���b�h�����b�N�擾���Ƃ������ƂȂ̂ŁA
								//���[�v�ʒu�ɃW�����v���Ă�蒼��
	}
#elif CODE_TYPE == 3//XCHG����{�E�F�C�g���[�v
	__asm						//�C�����C���A�Z���u���iVC++�`��)
	{
	lock_loop:					//���[�v�p���x��
		//���b�N�擾�\��Ԋm�F
		mov		eax, [s_lock]	//EAX �� [s_lock]
		test	eax, eax		//EAX & EAX ? ��EAX == 0 ���`�F�b�N
		jnz		lock_loop		//EAX != 0 �Ȃ�A���̃X���b�h�����b�N�擾���Ƃ������ƂȂ̂ŁA
								//���[�v�ʒu�ɃW�����v���Ă�蒼��
		//���ۂ̃��b�N�擾����
		mov		eax, 1			//EAX �� 1�i���b�N�擾���̃t���O�̒l�j
		xchg	eax, [s_lock]	//XCHG���߂͈ÖٓI��LOCK�v���t�B�b�N�X�ŃA�g�~�b�N����w��
								//EAX ���� [s_lock] �i�����j
								//��EAX �� [s_lock], [s_lock] �� 1 �ɂȂ�
		test	eax, eax		//EAX & EAX ? ��EAX == 0 ���`�F�b�N
		jnz		lock_loop		//EAX != 0�Ȃ�A���̃X���b�h�ɐ���z����Ă��܂����̂ŁA
								//���[�v�ʒu�ɃW�����v���Ă�蒼��
	}
#elif CODE_TYPE == 4//BTS����
	__asm						//�C�����C���A�Z���u���iVC++�`��)
	{
	lock_loop:					//���[�v�p���x��
		//���b�N�擾����
		lock bts	[s_lock], 0		//LOCK�v���t�B�b�N�X�ŃA�g�~�b�N����w��
									//CF �� [s_lock:0], [s_lock:0] �� 1
		setb		al				//AL �� CF
		movzx		eax, al			//EAX �� AL
		test		eax, eax		//EAX & EAX ? ��EAX == 0 ���`�F�b�N
		jnz			lock_loop		//EAX != 0�Ȃ�A���̃X���b�h�����b�N�擾���Ƃ������ƂȂ̂ŁA
									//���[�v�ʒu�ɃW�����v���Ă�蒼��
	}
#elif CODE_TYPE == 5//BTS����{�E�F�C�g���[�v
	__asm						//�C�����C���A�Z���u���iVC++�`��)
	{
	lock_loop:					//���[�v�p���x��
		//���b�N�擾�\��Ԋm�F
		mov			eax, [s_lock]	//EAX �� [s_lock]
		test		eax, eax		//EAX & EAX ? ��EAX == 0 ���`�F�b�N
		jnz			lock_loop		//EAX != 0 �Ȃ�A���̃X���b�h�����b�N�擾���Ƃ������ƂȂ̂ŁA
									//���[�v�ʒu�ɃW�����v���Ă�蒼��
		//���ۂ̃��b�N�擾����
		lock bts[s_lock], 0			//LOCK�v���t�B�b�N�X�ŃA�g�~�b�N����w��
									//CF �� [s_lock:0], [s_lock:0] �� 1
		setb		al				//AL �� CF
		movzx		eax, al			//EAX �� AL
		test		eax, eax		//EAX & EAX ? ��EAX == 0 ���`�F�b�N
		jnz			lock_loop		//EAX != 0�Ȃ�A���̃X���b�h�ɐ���z����Ă��܂����̂ŁA
									//���[�v�ʒu�ɃW�����v���Ă�蒼��
	}
#elif CODE_TYPE == 6//C++11 std::atomic����
	while (s_lock.test_and_set());//���b�N���擾����܂őҋ@
#endif//CODE_TYPE
}

//���b�N���
void unlock()
{
#if CODE_TYPE == 0 || CODE_TYPE == 1 || CODE_TYPE == 2 || CODE_TYPE == 3//CMPXCHG���� or XCHG����
	__asm						//�C�����C���A�Z���u���iVC++�`��)
	{
		mov		eax, 0			//EAX �� 0�i���b�N������̃t���O�̒l�j
		xchg	eax, [s_lock]	//XCHG���߂͈ÖٓI��LOCK�v���t�B�b�N�X�ŃA�g�~�b�N����w��
								//EAX ���� [s_lock] �i�����j
								//��EAX �� [s_lock], [s_lock] �� 0 �ɂȂ�
	}
#elif CODE_TYPE == 4 || CODE_TYPE == 5//BTS����
	__asm						//�C�����C���A�Z���u���iVC++�`��)
	{
		mov		eax, 0			//EAX �� 0�i���b�N������̃t���O�̒l�j
		xchg	eax, [s_lock]	//XCHG���߂͈ÖٓI��LOCK�v���t�B�b�N�X�ŃA�g�~�b�N����w��
								//EAX ���� [s_lock] �i�����j
								//��EAX �� [s_lock], [s_lock] �� 0 �ɂȂ�
	}
#elif CODE_TYPE == 6//C++11 std::atomic����
	s_lock.clear();//���b�N���
#endif//CODE_TYPE
}

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
		//���b�N�擾
		lock();

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

		//���b�N���
		unlock();

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
#if CODE_TYPE == 6//C++11 std::atomic����
	s_lock.clear();//���b�N��Ԃ�������
#endif//CODE_TYPE

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

	//�C�����C���A�Z���u���Ń��b�N�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			//���b�N�擾
			lock();
			//���b�N���
			unlock();
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Assembler * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	return EXIT_SUCCESS;
}

// End of file
