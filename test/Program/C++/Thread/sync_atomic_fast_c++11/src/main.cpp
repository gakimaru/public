#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <atomic>

#include <chrono> //���Ԍv���p
#include <random> //���������p

//�A�g�~�b�N����p�ϐ�
static std::atomic_flag s_lock = ATOMIC_FLAG_INIT;

//���L�f�[�^
static int s_commonData = 0;

//�X���b�h�ŗL�f�[�^
__declspec(thread) int s_tlsData = 0;
//thread_local int s_tlsData = 0;//Visual C++ 2013 �ł� thread_local �L�[���[�h���g���Ȃ�

//�X���b�h
void threadFunc(const char* name)
{
	//�J�n
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//����
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time(0, 4);

	//����
	for (int i = 0; i < 3; ++i)
	{
		//�A�g�~�b�N����Ń��b�N�擾�҂�
		while (s_lock.test_and_set()){}

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
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

		//�f�[�^�����߂�
		s_commonData = common_data;
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//�A�g�~�b�N����Ń��b�N���
		s_lock.clear();

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
	//�A�g�~�b�N����p�ϐ�������
	s_lock.clear();

	//�X���b�h�쐬
	std::thread thread_obj1 = std::thread(threadFunc, "���Y");
	std::thread thread_obj2 = std::thread(threadFunc, "���Y");
	std::thread thread_obj3 = std::thread(threadFunc, "�O�Y");

	//�X���b�h�I���҂�
	thread_obj1.join();
	thread_obj2.join();
	thread_obj3.join();

	//�A�g�~�b�N����Ń��b�N�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (s_lock.test_and_set()){}
			s_lock.clear();
		}	
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Atomic * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//�A�g�~�b�N����Ń��b�N�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��(2)�F�������o���A��ݒ�
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (s_lock.test_and_set(std::memory_order_seq_cst)){}
			s_lock.clear(std::memory_order_release);
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Atomic * %d (memolry barrier free) = %.6f sec\n", TEST_TIMES, duration);
	}

	return EXIT_SUCCESS;
}

// End of file
