#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <mutex>

#include <Windows.h> //���Ԍv���p

//�~���[�e�b�N�X�I�u�W�F�N�g
std::mutex s_mutex;

//���L�f�[�^
static int s_commonData = 0;

//�X���b�h�ŗL�f�[�^
__declspec(thread) int s_tlsData = 0;

//�X���b�h
void threadFunc(const char* name)
{
	//�J�n
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//����
	for (int i = 0; i < 3; ++i)
	{
		//�~���[�e�b�N�X�擾
		s_mutex.lock();
	//	s_mutex.try_lock();//�擾�ł��Ȃ����ɑ��̏������s�������ꍇ�� try_lock() ���g�p����

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
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 5));

		//�f�[�^�����߂�
		s_commonData = common_data;
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//�~���[�e�b�N�X���
		s_mutex.unlock();
		
		//�X���b�h�؂�ւ��̂��߂̃X���[�v
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	//	//�X���b�h�؂�ւ�
	//	std::this_thread::yield();//OS�ɔC���čăX�P�W���[�����O
	}

	//�I��
	printf("- end:%s -\n", name);
	fflush(stdout);
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	//�X���b�h�쐬
	std::thread thread_obj1 = std::thread(threadFunc, "���Y");
	std::thread thread_obj2 = std::thread(threadFunc, "���Y");
	std::thread thread_obj3 = std::thread(threadFunc, "�O�Y");
	
	//�X���b�h�I���҂�
	thread_obj1.join();
	thread_obj2.join();
	thread_obj3.join();

	//�~���[�e�b�N�X�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			s_mutex.lock();
			s_mutex.unlock();
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float time = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Mutex * %d = %.6f sec\n", TEST_TIMES, time);
	}

	return EXIT_SUCCESS;
}

// End of file
