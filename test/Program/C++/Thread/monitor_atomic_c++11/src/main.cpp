#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <atomic>

#include <chrono> //���Ԍv���p
#include <random> //���������p

//�X���b�h���
static const int FOLLOW_THREAD_MAX = 10;          //�㑱�X���b�h�ő吔
static volatile int s_followThreadNum = 0;        //�㑱�X���b�h��
static std::atomic<int> s_followThreadNo = 0;     //�㑱�X���b�h�ԍ����ԗp
static volatile bool s_IsQuirProiorThread = false;//��s�X���b�h�I���t���O

//���j�^�[�p�ϐ�
enum E_PROCESS
{
	PRIOR_RUNNING, //��s�������s��
	PRIOR_IDLE,    //��s�����A�C�h�����
	FOLLOW_RUNNING,//�㑱�������s��
	FOLLOW_IDLE,   //�㑱�����A�C�h�����
};
static std::atomic<E_PROCESS> s_followFinished[FOLLOW_THREAD_MAX];//�㑱�X���b�h���������t���O

//���L�f�[�^
static int s_commonData = 0;

//�X���b�h�ŗL�f�[�^
__declspec(thread) int s_tlsData = 0;
//thread_local int s_tlsData = 0;//Visual C++ 2013 �ł� thread_local �L�[���[�h���g���Ȃ�

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

	//����
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time(0, 499);

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
			while (!s_followFinished[i].compare_exchange_weak(prev, E_PROCESS::PRIOR_RUNNING)){ prev = E_PROCESS::FOLLOW_IDLE; }
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
				s_followFinished[i].store(E_PROCESS::PRIOR_IDLE);
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
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

		//�f�[�^�����߂�
		s_commonData = common_data;
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("(P)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//��s�X���b�h���������F�S�ҋ@�X���b�h���N��
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			s_followFinished[i].store(E_PROCESS::PRIOR_IDLE);
		}

		//�X���b�h�؂�ւ��̂��߂̃X���[�v
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	//	//�X���b�h�؂�ւ�
	//	std::this_thread::yield();//OS�ɔC���čăX�P�W���[�����O
	}

	//�I��
	printf("- end:(P)%s -\n", name);
	fflush(stdout);
}

//�㑱�X���b�h
void followThreadFunc(const char* name)
{
	//�㑱�X���b�h���J�E���g�A�b�v
	const int thread_no = s_followThreadNo++;

	//�J�n
	printf("- begin:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);

	//����
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time(0, 499);

	//�㑱�X���b�h���������F�ҋ@�X���b�h���N��
	s_followFinished[thread_no].store(E_PROCESS::FOLLOW_IDLE);

	//����
	while (1)
	{
		//��s�X���b�h���������҂�
		E_PROCESS prev = E_PROCESS::PRIOR_IDLE;
		while (!s_followFinished[thread_no].compare_exchange_weak(prev, E_PROCESS::FOLLOW_RUNNING)){ prev = E_PROCESS::PRIOR_IDLE; }

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
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

		//�f�[�^�����߂�
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("(F)[%d]%s: [AFTER]  commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);
		
		//�㑱�X���b�h���������F�ҋ@�X���b�h���N��
		s_followFinished[thread_no].store(E_PROCESS::FOLLOW_IDLE);

		//�X���b�h�؂�ւ��̂��߂̃X���[�v
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	//	//�X���b�h�؂�ւ�
	//	std::this_thread::yield();//OS�ɔC���čăX�P�W���[�����O
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
	static_assert(FOLLOW_THREAD_NUM <= FOLLOW_THREAD_MAX, "FOLLOW_THREAD_NUM is over.");
	s_followThreadNum = FOLLOW_THREAD_NUM;
	for (int i = 0; i < THREAD_NUM - 1; ++i)
		s_followFinished[i] = E_PROCESS::FOLLOW_IDLE;
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

	//�A�g�~�b�N�ϐ��̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		s_followFinished[0] = E_PROCESS::FOLLOW_IDLE;
		E_PROCESS prev = E_PROCESS::FOLLOW_IDLE;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::PRIOR_RUNNING)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::PRIOR_IDLE)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::FOLLOW_RUNNING)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::FOLLOW_IDLE)){}
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Watch-atomic * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//�A�g�~�b�N������ʂɎ��s���Ď��Ԃ��v��(2)
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		s_followFinished[0] = E_PROCESS::FOLLOW_IDLE;
		E_PROCESS prev = E_PROCESS::FOLLOW_IDLE;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::PRIOR_RUNNING, std::memory_order_relaxed, std::memory_order_relaxed)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::PRIOR_IDLE, std::memory_order_relaxed, std::memory_order_relaxed)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::FOLLOW_RUNNING, std::memory_order_relaxed, std::memory_order_relaxed)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::FOLLOW_IDLE, std::memory_order_relaxed, std::memory_order_relaxed)){}
			
			//http://www.justsoftwaresolutions.co.uk/threading/intel-memory-ordering-and-c++-memory-model.html
			//�y�������I�[�_�[�̈Ӗ��z�ix86���ߑ����̏ꍇ�j
			//Memory Ordering,           Store,         Load
			//------------------------- --------------- --------------
			//std::memory_order_relaxed  MOV[mem],reg   MOV reg,[mem]                             ���������o���A�Ȃ��F�������X�V�Ɠǂݍ��݂̏�������ۏ؂��Ȃ�
			//std::memory_order_consume  (n/a)          MOV reg,[mem]  (Data-Dependency Ordering) ���ǂݍ��ݐ�p�̃������o���A�i�����ア�j���X�g�A�����Ŏg���ƃG���[�i�����j
			//std::memory_order_acquire  (n/a)          MOV reg,[mem]                             ���ǂݍ��ݐ�p�̃������o���A�@�@�@�@�@�@���X�g�A�����Ŏg���ƃG���[�i�����j
			//std::memory_order_release  MOV[mem],reg   (n/a)                                     ���������ݐ�p�̃������o���A�@�@�@�@�@�@�����[�h�����Ŏg���ƃG���[�i�����j
			//std::memory_order_acq_rel  MOV[mem],reg   MOV reg,[mem] (acquire & release)         ��������p�̃������o���A�@�@�@�@�@�@�@�@�����[�h�^�X�g�A�����Ŏg���ƃG���[
			//std::memory_order_seq_cst  XCHG[mem],reg  MOV reg,[mem] (Sequential consistency)    ���ǂݏ����������o���A�i���́j�@�@�@�@�@���f�t�H���g�i�K�������ᑬ�Ƃ����킯�łł͂Ȃ��j
			//�ELoad  ... ���W�X�^ �� ������
			//�EStore ... ���W�X�^ �� ������
			
			//�y�����T���v���z
			//std::atomic<int> o(1);
			//int v = 0;
			//v = o.load(std::memory_order_relaxed);//OK
			//v = o.load(std::memory_order_consume);//OK
			//v = o.load(std::memory_order_acquire);//OK
			////v = o.load(std::memory_order_release);//��O�FInvalid Memory Order
			////v = o.load(std::memory_order_acq_rel);//��O�FInvalid Memory Order
			//v = o.load(std::memory_order_seq_cst);//OK
			//o.store(v, std::memory_order_relaxed);//OK
			////o.store(v, std::memory_order_consume);//��O�FInvalid Memory Order
			////o.store(v, std::memory_order_acquire);//��O�FInvalid Memory Order
			//o.store(v, std::memory_order_release);//OK
			////o.store(v, std::memory_order_acq_rel);//��O�FInvalid Memory Order
			//o.store(v, std::memory_order_seq_cst);//OK
			//o.exchange(2, std::memory_order_relaxed);//OK
			//o.exchange(3, std::memory_order_consume);//OK
			//o.exchange(4, std::memory_order_acquire);//OK
			//o.exchange(5, std::memory_order_release);//OK
			//o.exchange(6, std::memory_order_acq_rel);//OK
			//o.exchange(7, std::memory_order_seq_cst);//OK
			//v = 7;
			//v = o.compare_exchange_weak(v, 7, std::memory_order_relaxed, std::memory_order_relaxed);//�����������FOK
			//v = o.compare_exchange_weak(v, 7, std::memory_order_consume, std::memory_order_consume);//�����������FOK
			//v = o.compare_exchange_weak(v, 7, std::memory_order_acquire, std::memory_order_acquire);//�����������FOK
			////v = o.compare_exchange_weak(v, 7, std::memory_order_release, std::memory_order_release);//�����������FAssertion failed! _Order2 != memory_order_release
			////v = o.compare_exchange_weak(v, 7, std::memory_order_acq_rel, std::memory_order_acq_rel);//�����������FAssertion failed! _Order2 != memory_order_acq_rel
			//v = o.compare_exchange_weak(v, 7, std::memory_order_seq_cst, std::memory_order_seq_cst);//�����������FOK
			//v = o.compare_exchange_weak(v, 8, std::memory_order_relaxed, std::memory_order_relaxed);//�����s�������FOK
			//v = o.compare_exchange_weak(v, 8, std::memory_order_consume, std::memory_order_consume);//�����s�������FOK
			//v = o.compare_exchange_weak(v, 8, std::memory_order_acquire, std::memory_order_acquire);//�����s�������FOK
			////v = o.compare_exchange_weak(v, 8, std::memory_order_release, std::memory_order_release);//�����s�������FAssertion failed! _Order2 != memory_order_release
			////v = o.compare_exchange_weak(v, 8, std::memory_order_acq_rel, std::memory_order_acq_rel);//�����s�������FAssertion failed! _Order2 != memory_order_acq_rel
			//v = o.compare_exchange_weak(v, 8, std::memory_order_seq_cst, std::memory_order_seq_cst);//�����s�������FOK

			//�y�������X�V�Ɠǂݍ��݂̏������ۏ؁z
			//CPU�̃������o���A���g�����ǂ����H
			//�i��j���L�̂悤�ȏ����ŁA�X���b�h�a�͕ϐ� b ���`�F�b�N���Ă���ɂ����ւ�炸�A
			//      ��ɍX�V���ꂽ�͂��̕ϐ� a �̒l�� 12 �ƕ\������Ȃ��悤�Ȃ��Ƃ��N���肦��B
			//      ����́ACPU�Ƀ������o���A���߂��o����ď�������ۏ؂��Ȃ��ƁACPU�̍œK���ɂ��A
			//      �X�V�̏���������ւ�邱�Ƃ����邽�߁B�i�u�A�E�g�E�I�u�E�I�[�_�[���s�v�ƌĂ΂��œK���j
			//[�O���[�o���ϐ�]
			//volatile bool flg_a;
			//volatile bool flg_b;
			//volatile int val_a;
			//volatile int val_b;
			//[�X���b�hA]
			//val_a = 123;
			//flg_a = true;
			//if(flg_b)
			//    std::cout << val_b;
			//[�X���b�hB]
			//val_b = 789;
			//flg_b = true;
			//if(flg_a)
			//    std::cout << val_a;
			//�����̖��́A�K�v�ȉӏ��ŕK�v�ȃ������o���A�𖾎����邱�ƂőΏ��ł���
			//[�O���[�o���ϐ�]
			//std::atmic<bool> flg_a;
			//std::atmic<bool> flg_b;
			//volatile int val_a;
			//volatile int val_b;
			//[�X���b�hA]
			//val_a = 123;
			//flg_a.store(true, std::memory_order_release);
			//if(flg_b.load(std::memory_order_acquire))
			//    std::cout << val_b;
			//[�X���b�hB]
			//val_b = 789;
			//flg_b.store(true, std::memory_order_release );
			//if(flg_a.load(std::memory_order_acquire))
			//    std::cout << val_a;

			//http://msdn.microsoft.com/ja-jp/library/hh874684.aspx
			//template<class Ty>
			//bool std::atomic::compare_exchange_***(Ty& Expected, Ty NewValue, std::memory_order SuccessOrder, std::memory_order FailureOrder) _NOEXCEPT;
			//�Estd::atomic::compare_exchange_weak()   ... *this  �Ŏア�A�g�~�b�N�̔�r����ь�����������s���܂��B 
			//�Estd::atomic::compare_exchange_strong() ... *this  �ɑ΂��ăA�g�~�b�N�̔�r����ь����̑�������s���܂��B 
			//�y���ʁz
			//    ���̃A�g�~�b�N�̔�r����ь����̑���ł́A*this �Ɋi�[����Ă���l�� Expected ���r���܂��B
			//    �l���������ꍇ�A����� read-modify-write ������g�p���āA
			//    SuccessOrder �ɂ���Ďw�肳�ꂽ���������������K�p���āA
			//    *this �Ɋi�[���ꂽ�l�� NewValue �ƒu�������܂��B
			//    �l���������Ȃ��ꍇ�A����� *this �Ɋi�[����Ă���l���g�p���� Expected ��u�������A
			//    FailureOrder �ɂ���Ďw�肳�ꂽ���������������K�p���܂��B 
			//
			//    2 �Ԗڂ� memory_order ���Ȃ��I�[�o�[���[�h�́ASuccessOrder �̒l�Ɋ�Â��Öق� FailureOrder ���g�p���܂��B
			//    SuccessOrder �� memory_order_acq_rel �̏ꍇ�AFailureOrder �� memory_order_acquire �ł��B
			//    SuccessOrder �� memory_order_release �̏ꍇ�AFailureOrder �� memory_order_relaxed �ł��B
			//    ���̂��ׂĂ̏ꍇ�AFailureOrder �� SuccessOrder �Ɠ������Ȃ�܂��B
			//
			//    2 �� memory_order �p�����[�^�[���󂯎��I�[�o�[���[�h�̏ꍇ�A
			//    FailureOrder �̒l�� memory_order_release �܂��� memory_order_acq_rel �ł͂Ȃ��K�v������A
			//    ���� SuccessOrder �̒l���������l�ł͂Ȃ��K�v������܂��B
			//
			//�ycompare_exchange_weak() �݂̂̉���z
			//    ��r���ꂽ�l������̏ꍇ�A�ア�A�g�~�b�N��r����ь�������͌��������s���܂��B
			//    �l�������łȂ��ꍇ�A����ɂ������̎��s�͕ۏ؂���܂���B
			//
			//�y���\�b�h�̎g�������z  http://d.hatena.ne.jp/yohhoy/20120725/p1
			//�E�A���S���Y����ACAS��������[�v�Ŋ���K�v������� compare_exchange_weak �𗘗p����B
			//�@�i��F��ʓI��Lock-Free�A���S���Y�������Ȃǁj
			//�E�A���S���Y����̐��񂪖����A����spurious failure�����e���Ȃ��ꍇ�� compare_exchange_strong �𗘗p����B
			//�@�i��Fpthread spinlock������trylock������� * 2�j
			//�y���\�b�h�̎g�������v��z
			//�E���[�v������ compare_exchange_weak ��OK�B
			//�E���[�v�����ȊO�́i�����̎�肱�ڂ��������Ă͂Ȃ�Ȃ��j��ʂł� compare_exchange_strong ���g�p�B
			//�ySuccessOrder��FailureOrder�̎g�������v��z
			//�ESuccessOrder�́A������������ *this �� NewValue �ɗp������B�u�ǂݏ����\�v�ȃ������I�[�_�[�ł���K�v������B
			//�EFailureOrder�́A�����s�������� Expected �� *this �ɗp������B�u�������݉\�v�ȃ������I�[�_�[�ł���K�v������B
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Watch-atomic * %d (memory barrier free) = %.6f sec\n", TEST_TIMES, duration);
	}

	return EXIT_SUCCESS;
}

// End of file
