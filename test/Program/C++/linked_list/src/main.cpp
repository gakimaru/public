//--------------------------------------------------------------------------------
//�o�����A�����X�g�e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
static const int TEST_DATA_NUM = 10;//��ʓo�^�e�X�g�f�[�^�̓o�^��
//static const int TEST_DATA_NUM = 20000;//��ʓo�^�e�X�g�f�[�^�̓o�^��

static const int TEST_DATA_FIND_NUM = 1000;//��ʃe�X�g�̐��`�T����
static const int TEST_DATA_FIND_STEP = TEST_DATA_NUM > TEST_DATA_FIND_NUM ? TEST_DATA_NUM / TEST_DATA_FIND_NUM : 1;//��ʃe�X�g�̐��`���s�X�e�b�v

#define ENABLE_SORT_TEST//��ʃf�[�^�e�X�g�Ń\�[�g�����s����ꍇ�A���̃}�N����L��������

#define PRINT_TEST_DATA_DETAIL//�e�X�g�f�[�^�̏ڍ׃^��\������ꍇ�́A���̃}�N����L��������
//#define TEST_DATA_WATCH_CONSTRUCTOR//�R���X�g���N�^�^�f�X�g���N�^�^������Z�q�̓�����m�F����ꍇ�A���̃}�N����L��������

//--------------------------------------------------------------------------------
//�o�����A�����X�g�̃R���p�C���X�C�b�`
//#define ENABLE_BINARY_SEARCH//�񕪒T����L���ɂ���
//#define ENABLE_STABLE_SORT//����\�[�g��L���ɂ���
//#define USE_SHELL_SORT//�ʏ�\�[�g�ɃV�F���\�[�g���g�p����i���������͑}���\�[�g���g�p�j

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------
//���샍�b�N�N���X
//--------------------------------------------------------------------------------

#include <atomic>//C++11 std::atomic�p
#include <thread>//C++11 std::this_thread::sleep_for�p
#include <chrono>//C++11 std::chrono::milliseconds�p

//--------------------------------------------------------------------------------
//�X�s�����b�N
//--------------------------------------------------------------------------------

//----------------------------------------
//�X�s�����b�N�N���X
//���T�C�Y��4�o�C�g(std::atomic_flag����̃T�C�Y)
class spin_lock
{
public:
	//�萔
	static const int DEFAULT_SPIN_COUNT = 1000;//�X�s�����b�N�J�E���g�̃f�t�H���g�l
public:
	//���b�N�擾
	void lock(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (true)
		{
			if (!m_lock.test_and_set())
				return;
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//�R���e�L�X�g�X�C�b�`�i�[���X���[�v�j
				spin_count_now = spin_count;
			}
		}
	}
	//���b�N�擾�����s
	//���擾�ɐ��������ꍇ�Atrue���Ԃ�̂ŁA���b�N���������K�v������
	inline bool try_lock()
	{
		return m_lock.test_and_set() == false;
	}
	//���b�N���
	inline void unlock()
	{
		m_lock.clear();
	}
public:
	//�R���X�g���N�^
	inline spin_lock()
	{
		m_lock.clear();
	}
	//�f�X�g���N�^
	inline ~spin_lock()
	{}
private:
	//�t�B�[���h
	std::atomic_flag m_lock;//���b�N�p�t���O
};

//----------------------------------------
//�X�s�����b�N�N���X�i�y�ʔŁj
//���T�C�Y��1�o�C�g
//��spin_lock�̕�������
class lw_spin_lock
{
public:
	//���b�N�擾
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (true)
		{
			bool prev = false;
			if (!m_lock.compare_exchange_weak(prev, true))
				return;
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//�R���e�L�X�g�X�C�b�`�i�[���X���[�v�j
				spin_count_now = spin_count;
			}
		}
	}
	//���b�N�擾�����s
	//���擾�ɐ��������ꍇ�Atrue���Ԃ�̂ŁA���b�N���������K�v������
	inline bool try_lock()
	{
		bool prev = false;
		return m_lock.compare_exchange_weak(prev, true) == false;
	}
	//���b�N���
	inline void unlock()
	{
		m_lock.store(false);
	}
public:
	//�R���X�g���N�^
	inline lw_spin_lock()
	{
		m_lock.store(false);//���b�N�p�t���O
	}
	//�f�X�g���N�^
	inline ~lw_spin_lock()
	{}
private:
	//�t�B�[���h
	std::atomic_bool m_lock;//���b�N�p�t���O
};

//----------------------------------------
//���L�i���[�h�E���C�g�j�X�s�����b�N�N���X
//���T�C�Y��4�o�C�g
//���r�����b�N�i���C�g���b�N�j��D�悷��
//���ǂݍ��ݑ���i���L���b�N�j�����ݍ����Ă���r���Ŋ��荞���
//�@�������ݑ���i�r�����b�N�j���s���������ɗp����
//���r�����b�N����ɍŗD�悳���킯�ł͂Ȃ��B
//�@���L���b�N�����b�N���J������O�ɔr�����b�N�����b�N��
//�@�擾���邱�Ƃ�������d�g�݂Ŏ�������B���̏ꍇ�A
//�@���L���b�N���S�ĉ�������̂�҂��Ă��珈���𑱍s����B
//�@���̂��߁A�ʂ̔r�����b�N���҂���ԂɂȂ��Ă��A
//�@���L���b�N����Ƀ��b�N���擾���邱�Ƃ͕ۏ؂��Ȃ��B
class shared_spin_lock
{
public:
	//�萔
	static const int DEFAULT_COUNTER = 0x01000000;//���b�N���擾����Ă��Ȃ����̃f�t�H���g�̃J�E���^

public:
	//���L���b�N�i���[�h���b�N�j�擾
	void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(1);//�J�E���^���X�V
			if (lock_counter > 0)
				return;//���b�N�擾����
			m_lockCounter.fetch_add(1);//�J�E���^��߂��ă��g���C
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//�R���e�L�X�g�X�C�b�`�i�[���X���[�v�j
				spin_count_now = spin_count;
			}
		}
	}
	//���L���b�N�i���[�h���b�N�j�擾�����s
	//���擾�ɐ��������ꍇ�Atrue���Ԃ�̂ŁA���b�N���������K�v������
	bool try_lock_shared()
	{
		const int lock_counter = m_lockCounter.fetch_sub(1);//�J�E���^���X�V
		if (lock_counter >= 0)
			return true;//���b�N�擾����
		m_lockCounter.fetch_add(1);//�J�E���^��߂�
		return false;//���b�N�擾���s
	}
	//�r�����b�N�i���C�g���b�N�j�擾
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(DEFAULT_COUNTER);//�J�E���^���X�V
			if (lock_counter == DEFAULT_COUNTER)
				return;//���b�N�擾����
			if (lock_counter > 0)	//�����r�����b�N���擾���Ă��Ȃ��̂ŁA���݂̋��L���b�N���S�ĉ�������̂�҂�
			{						//���J�E���^���X�V�����܂܂Ȃ̂ŁA�㑱�̋��L���b�N�^�r�����b�N�͎擾�ł��Ȃ��B
				while (m_lockCounter.load() != 0)//�J�E���^��0�ɂȂ�̂�҂�
				{
					if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
					{
						std::this_thread::sleep_for(std::chrono::milliseconds(0));//�R���e�L�X�g�X�C�b�`�i�[���X���[�v�j
						spin_count_now = spin_count;
					}
				}
				return;//���b�N�擾����
			}
			m_lockCounter.fetch_add(DEFAULT_COUNTER);//�J�E���^��߂��ă��g���C
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//�R���e�L�X�g�X�C�b�`�i�[���X���[�v�j
				spin_count_now = spin_count;
			}
		}
	}
	//�r�����b�N�i���C�g���b�N�j�擾�����s
	//���擾�ɐ��������ꍇ�Atrue���Ԃ�̂ŁA���b�N���������K�v������
	bool try_lock()
	{
		const int lock_counter = m_lockCounter.fetch_sub(DEFAULT_COUNTER);//�J�E���^���X�V
		if (lock_counter == DEFAULT_COUNTER)
			return true;//���b�N�擾����
		m_lockCounter.fetch_add(DEFAULT_COUNTER);//�J�E���^��߂�
		return false;//���b�N�擾���s
	}
	//���L���b�N�i���[�h���b�N�j���
	inline void unlock_shared()
	{
		m_lockCounter.fetch_add(1);//�J�E���^��߂�
	}
	//�r�����b�N�i���C�g���b�N�j���
	inline void unlock()
	{
		m_lockCounter.fetch_add(DEFAULT_COUNTER);//�J�E���^��߂�
	}
public:
	//�R���X�g���N�^
	inline shared_spin_lock() :
		m_lockCounter(DEFAULT_COUNTER)
	{}
	//�f�X�g���N�^
	inline ~shared_spin_lock()
	{}
private:
	//�t�B�[���h
	std::atomic<int> m_lockCounter;//���b�N�J�E���^
};

//----------------------------------------
//���L�i���[�h�E���C�g�j�X�s�����b�N�N���X�i�y�ʔŁj
//���T�C�Y��4�o�C�g
//���r�����b�N�i���C�g���b�N�j��D�悵�Ȃ�
//���ǂݍ��ݑ���i���L���b�N�j�����ݍ����Ă���ƁA
//�@�������ݑ���i�r�����b�N�j���҂������̂Œ��ӁB
class lw_shared_spin_lock
{
public:
	//���L���b�N�i���[�h���b�N�j�擾
	void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(1);//�J�E���^���X�V
			if (lock_counter > 0)
				return;//���b�N�擾����
			m_lockCounter.fetch_add(1);//�J�E���^��߂��ă��g���C
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//�R���e�L�X�g�X�C�b�`�i�[���X���[�v�j
				spin_count_now = spin_count;
			}
		}
	}
	//���L���b�N�i���[�h���b�N�j�擾�����s
	//���擾�ɐ��������ꍇ�Atrue���Ԃ�̂ŁA���b�N���������K�v������
	bool try_lock_shared()
	{
		const int lock_counter = m_lockCounter.fetch_sub(1);//�J�E���^���X�V
		if (lock_counter >= 0)
			return true;//���b�N�擾����
		m_lockCounter.fetch_add(1);//�J�E���^��߂�
		return false;//���b�N�擾���s
	}
	//�r�����b�N�i���C�g���b�N�j�擾
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(shared_spin_lock::DEFAULT_COUNTER);//�J�E���^���X�V
			if (lock_counter == shared_spin_lock::DEFAULT_COUNTER)
				return;//���b�N�擾����
			m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//�J�E���^��߂��ă��g���C
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//�R���e�L�X�g�X�C�b�`�i�[���X���[�v�j
				spin_count_now = spin_count;
			}
		}
	}
	//�r�����b�N�i���C�g���b�N�j�擾�����s
	//���擾�ɐ��������ꍇ�Atrue���Ԃ�̂ŁA���b�N���������K�v������
	bool try_lock()
	{
		const int lock_counter = m_lockCounter.fetch_sub(shared_spin_lock::DEFAULT_COUNTER);//�J�E���^���X�V
		if (lock_counter == shared_spin_lock::DEFAULT_COUNTER)
			return true;//���b�N�擾����
		m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//�J�E���^��߂�
		return false;//���b�N�擾���s
	}
	//���L���b�N�i���[�h���b�N�j���
	inline void unlock_shared()
	{
		m_lockCounter.fetch_add(1);//�J�E���^��߂�
	}
	//�r�����b�N�i���C�g���b�N�j���
	inline void unlock()
	{
		m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//�J�E���^��߂�
	}
public:
	//�R���X�g���N�^
	inline lw_shared_spin_lock() :
		m_lockCounter(shared_spin_lock::DEFAULT_COUNTER)
	{}
	//�f�X�g���N�^
	inline ~lw_shared_spin_lock()
	{}
private:
	//�t�B�[���h
	std::atomic<int> m_lockCounter;//���b�N�J�E���^
};

//----------------------------------------
//�񋤗L�i�r���j�X�s�����b�N�N���X
//���T�C�Y��4�o�C�g
//�����L���b�N�N���X�Ɠ���̃C���^�[�t�F�[�X�ŁA
//�@���L���b�N���s��Ȃ��N���X
//�����L���b�N�̃w���p�[�N���X�⃍�b�N�K�[�h���g�p���鏈���ɑ΂��āA
//�@���S�Ȕr��������s���������Ɏg�p����B
class unshared_spin_lock
{
public:
	//���L���b�N�i���[�h���b�N�j�擾
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//���L���b�N�i���[�h���b�N�j�擾�����s
	//���擾�ɐ��������ꍇ�Atrue���Ԃ�̂ŁA���b�N���������K�v������
	inline bool try_lock_shared()
	{
		return m_lock.try_lock();
	}
	//�r�����b�N�i���C�g���b�N�j�擾
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//�r�����b�N�i���C�g���b�N�j�擾�����s
	//���擾�ɐ��������ꍇ�Atrue���Ԃ�̂ŁA���b�N���������K�v������
	inline bool try_lock()
	{
		return m_lock.try_lock();
	}
	//���L���b�N�i���[�h���b�N�j���
	inline void unlock_shared()
	{
		m_lock.unlock();
	}
	//�r�����b�N�i���C�g���b�N�j���
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//�R���X�g���N�^
	unshared_spin_lock() :
		m_lock()
	{}
	//�f�X�g���N�^
	~unshared_spin_lock()
	{}
private:
	//�t�B�[���h
	spin_lock m_lock;//���b�N�I�u�W�F�N�g
};

//--------------------------------------------------------------------------------
//�_�~�[���b�N
//--------------------------------------------------------------------------------

//----------------------------------------
//�_�~�[���b�N�N���X
//��spin_lock��std::mutex�Ɠ��l�̃��b�N�C���^�[�t�F�[�X�������A���ۂɂ͉������Ȃ��N���X
class dummy_lock
{
public:
	//���b�N�擾
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//�������Ȃ�
	}
	//���b�N�擾�����s
	inline bool try_lock()
	{
		//�������Ȃ�
		return true;
	}
	//���b�N���
	inline void unlock()
	{
		//�������Ȃ�
	}
public:
	//�R���X�g���N�^
	inline dummy_lock()
	{}
	//�f�X�g���N�^
	~dummy_lock()
	{}
};

//----------------------------------------
//�_�~�[���L�i���[�h�E���C�g�j���b�N�N���X
//��shared_spin_lock��std::shared_lock�Ɠ��l�̃��b�N�C���^�[�t�F�[�X�������A���ۂɂ͉������Ȃ��N���X
class dummy_shared_lock
{
public:
	//���L���b�N�i���[�h���b�N�j�擾
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//�������Ȃ�
	}
	//���L���b�N�i���[�h���b�N�j�擾�����s
	inline bool try_lock_shared()
	{
		//�������Ȃ�
		return true;
	}
	//�r�����b�N�i���C�g���b�N�j�擾
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//�������Ȃ�
	}
	//�r�����b�N�i���C�g���b�N�j�擾�����s
	inline bool try_lock()
	{
		//�������Ȃ�
		return true;
	}
	//���L���b�N�i���[�h���b�N�j���
	inline void unlock_shared()
	{
		//�������Ȃ�
	}
	//�r�����b�N�i���C�g���b�N�j���
	inline void unlock()
	{
		//�������Ȃ�
	}
public:
	//�R���X�g���N�^
	inline dummy_shared_lock()
	{}
	//�f�X�g���N�^
	~dummy_shared_lock()
	{}
};

//--------------------------------------------------------------------------------
//���b�N�w���p�[
//--------------------------------------------------------------------------------

//----------------------------------------
//���b�N�w���p�[�N���X
//���������B�؂����ă��b�N�𑀍삷�邽�߂̃w���p�[�N���X
template<class T>
class lock_helper
{
public:
	typedef T lock_type;//���b�N�I�u�W�F�N�g�^
public:
	//���\�b�h

	//���b�N�擾
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//���b�N�擾�����s
	inline bool try_lock()
	{
		return m_lock.try_lock();
	}
	//���b�N���
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//�R���X�g���N�^
	inline lock_helper(lock_type& lock) :
		m_lock(lock)
	{}
	//�f�X�g���N�^
	inline ~lock_helper()
	{}
private:
	//�t�B�[���h
	lock_type& m_lock;//���b�N�I�u�W�F�N�g�̎Q��
};

//----------------------------------------
//���L�i���[�h�E���C�g�j���b�N�w���p�[�N���X
//���������B�؂����ċ��L�i���[�h�E���C�g�j���b�N�𑀍삷�邽�߂̃w���p�[�N���X
template<class T>
class shared_lock_helper
{
public:
	typedef T lock_type;//���b�N�I�u�W�F�N�g�^
public:
	//���\�b�h

	//���L���b�N�i���[�h���b�N�j�擾
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock_shared(spin_count);
	}
	//���L���b�N�i���[�h���b�N�j�擾�����s
	inline bool try_lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		return m_lock.try_lock_shared(spin_count);
	}
	//�r�����b�N�i���C�g���b�N�j�擾
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//�r�����b�N�i���C�g���b�N�j�擾�����s
	inline bool try_lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		return m_lock.try_lock(spin_count);
	}
	//���L���b�N�i���[�h���b�N�j���
	inline void unlock_shared()
	{
		m_lock.unlock_shared();
	}
	//�r�����b�N�i���C�g���b�N�j���
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//�R���X�g���N�^
	inline shared_lock_helper(lock_type& lock) :
		m_lock(lock)
	{}
	//�f�X�g���N�^
	inline ~shared_lock_helper()
	{}
private:
	//�t�B�[���h
	lock_type& m_lock;//���b�N�I�u�W�F�N�g�̎Q��
};

//--------------------------------------------------------------------------------
//���b�N�K�[�h�i�X�R�[�v���b�N�j
//--------------------------------------------------------------------------------

//----------------------------------------
//���b�N�K�[�h�N���X�i�X�R�[�v���b�N�j
//���X�R�[�v���b�N�Œʏ탍�b�N�������͔r�����b�N�i���C�g���b�N�j�̃��b�N�擾�Ɖ�����s��
template<class T>
class lock_guard
{
public:
	typedef T lock_type;//���b�N�I�u�W�F�N�g�^
public:
	//�R���X�g���N�^
	inline lock_guard(lock_type& lock, const int spin_count = spin_lock::DEFAULT_SPIN_COUNT) :
		m_lock(lock)
	{
		m_lock.lock(spin_count);
	}
	//�f�X�g���N�^
	inline ~lock_guard()
	{
		m_lock.unlock();
	}
private:
	//�t�B�[���h
	lock_type& m_lock;//���b�N�I�u�W�F�N�g�̎Q��
};

//----------------------------------------
//���L�i���[�h�E���C�g�j���b�N�K�[�h�N���X�i�X�R�[�v���b�N�j
//���X�R�[�v���b�N�ŋ��L���b�N�i���[�h���b�N�j�̃��b�N�擾�Ɖ�����s��
template<class T>
class shared_lock_guard
{
public:
	typedef T lock_type;//���b�N�I�u�W�F�N�g�^
public:
	//�R���X�g���N�^
	inline shared_lock_guard(lock_type& lock, const int spin_count = spin_lock::DEFAULT_SPIN_COUNT) :
		m_lock(lock)
	{
		m_lock.lock_shared(spin_count);
	}
	//�f�X�g���N�^
	inline ~shared_lock_guard()
	{
		m_lock.unlock_shared();
	}
private:
	//�t�B�[���h
	lock_type& m_lock;//���b�N�I�u�W�F�N�g�̎Q��
};

//--------------------------------------------------------------------------------
//�\�[�g�A���S���Y��
//--------------------------------------------------------------------------------

#include <algorithm>//C++11 std::move�p
#include <memory.h>//memcpy�p

//========================================
//�\�[�g�^�T���⏕����
//========================================

//----------------------------------------
//�\�[�g�p�W���v���f�B�P�[�g�֐��I�u�W�F�N�g�Fless
//���ΏۃI�u�W�F�N�g�� operator<�ɑΉ����Ă���K�v����
template<typename T>
struct less{
	inline bool operator()(const T& val1, const T& val2) const
	{
		return val1 < val2;
	}
};
//----------------------------------------
//���`�T���p�W���v���f�B�P�[�g�֐��I�u�W�F�N�g�Feqal_to
//���ΏۃI�u�W�F�N�g�� operator==�ɑΉ����Ă���K�v����
template<typename T>
struct equal_to{
	template<typename V>
	inline bool operator()(const T& val1, const V& val2) const
	{
		return val1 == val2;
	}
};
//----------------------------------------
//�񕪒T���p�W����r�֐��I�u�W�F�N�g�Fcompare_to
//���ΏۃI�u�W�F�N�g�� operator==, operator<�ɑΉ����Ă���K�v����
template<typename T>
struct compare_to{
	template<typename V>
	inline int operator()(const T& val1, const V& val2) const
	{
		if (val1 == val2)
			return 0;
		else if (val1 < val2)
			return 1;
		else//if (val1 > val2)
			return -1;
	}
};

#if 0
//----------------------------------------
//��r�\�[�g�����I�[�o�[���[�h�֐��p�}�N��
//���C�e���[�^�Ή���
//���W���v���f�B�P�[�g�֐��g�p��
#define iteratorSortFuncSetByDefaultPredicate(func_name) \
	template<class ITERATOR> \
	inline std::size_t func_name(ITERATOR begin, ITERATOR end) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		return func_name(begin, end, less<value_type>()); \
	}
#define iteratorSortFuncSet(func_name) \
	iteratorSortFuncSetByDefaultPredicate(func_name)
#endif

//----------------------------------------
//�T�������I�[�o�[���[�h�֐��p�}�N��
//���C�e���[�^�Ή���
//���T���l�w��ŁF�v���f�B�P�[�g�֐��ƒl�Ŕ�r
#define iteratorSearchFuncSetPredicateAndValue(func_name) \
	template<class ITERATOR, typename V, class PREDICATE> \
	inline ITERATOR func_name##Value(ITERATOR begin, ITERATOR end, const V& value, PREDICATE predicate) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		auto _equal = [&value, &predicate](value_type& val1) -> bool { return predicate(val1, value); }; \
		return std::move(func_name(begin, end, _equal)); \
	}
//���T���l�w��ŁF�W���̃v���f�B�P�[�g�֐��ƒl�Ŕ�r
#define iteratorSearchFuncSetByDefaultPredicateAndValue(func_name) \
	template<class ITERATOR, typename V> \
	inline ITERATOR func_name##Value(ITERATOR begin, ITERATOR end, const V& value) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		auto _equal = [&value](value_type& val1) -> bool { return equal_to<value_type>()(val1, value); }; \
		return std::move(func_name(begin, end, _equal)); \
	}
#define iteratorSearchFuncSetByPredicate(func_name) \
	iteratorSearchFuncSetPredicateAndValue(func_name) \
	iteratorSearchFuncSetByDefaultPredicateAndValue(func_name)
//���T���l�w��ŁF��r�֐��ƒl�Ŕ�r
#define iteratorSearchFuncSetByComparisonAndValue(func_name) \
	template<class ITERATOR, typename V, class COMPARISON> \
	inline ITERATOR func_name##Value(ITERATOR begin, ITERATOR end, const V& value, COMPARISON comparison) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		auto _comparison = [&value, &comparison](value_type& val1) -> int { return comparison(val1, value); }; \
		return func_name(begin, end, _comparison); \
	}
//���T���l�w��ŁF�W����r�֐��ƒl�Ŕ�r
#define iteratorSearchFuncSetByDefaultComparisonAndValue(func_name) \
	template<class ITERATOR, typename V> \
	inline ITERATOR func_name##Value(ITERATOR begin, ITERATOR end, const V& value) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		auto _comparison = [&value](value_type& val1) -> int { return compare_to<value_type>()(val1, value); }; \
		return func_name(begin, end, _comparison); \
	}
#define iteratorSearchFuncSetByComparison(func_name) \
	iteratorSearchFuncSetByComparisonAndValue(func_name) \
	iteratorSearchFuncSetByDefaultComparisonAndValue(func_name)

#if 0
//----------------------------------------
//�����Ԋm�F ���C�e���[�^�Ή���
template<class ITERATOR, class PREDICATE>
inline std::size_t iteratorCalcUnordered(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	std::size_t unordered = 0;
	ITERATOR prev = begin;
	ITERATOR now = begin;
	++now;
	for (; now != end; ++now, ++prev)
	{
		if (predicate(*now, *prev))
			++unordered;
	}
	return unordered;
}
iteratorSortFuncSet(iteratorCalcUnordered);
#endif

//----------------------------------------
//�C�e���[�^�̍��i�v�f���j��Ԃ�
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::input_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::output_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::forward_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::bidirectional_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::random_access_iterator_tag)
{
	return end - begin;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end)
{
	typename ITERATOR::iterator_category category;
	return iteratorDifference(begin, end, category);
}

//----------------------------------------
//for-each
template<class ITERATOR, class FUNCTOR>
void forEach(ITERATOR begin, ITERATOR end, FUNCTOR functor)
{
	for (; begin != end; ++begin)
	{
		functor(*begin);
	}
}
template<class CONTAINER, class FUNCTOR>
void forEach(CONTAINER container, FUNCTOR functor)
{
	typename CONTAINER::iterator begin = container.begin();
	typename CONTAINER::iterator end = container.end();
	forEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void forEach(T(&array)[N], FUNCTOR functor)
{
	T* begin = array;
	T* end = array + N;
	forEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void forEach(const T(&array)[N], FUNCTOR functor)
{
	const T* begin = array;
	const T* end = array + N;
	forEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void forEach(T* array, const std::size_t size, FUNCTOR functor)
{
	T* begin = array;
	T* end = array + size;
	forEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void forEach(const T* array, const std::size_t size, FUNCTOR functor)
{
	const T* begin = array;
	const T* end = array + size;
	forEach(begin, end, functor);
}
//----------------------------------------
//reverse for-each
template<class ITERATOR, class FUNCTOR>
void reverseForEach(ITERATOR begin, ITERATOR end, FUNCTOR functor)
{
	while (begin != end)
	{
		--begin;
		functor(*begin);
	}
}
template<class CONTAINER, class FUNCTOR>
void reverseForEach(CONTAINER container, FUNCTOR functor)
{
	typename CONTAINER::reverse_iterator rbegin = container.rbegin();
	typename CONTAINER::reverse_iterator rend = container.rend();
	forEach(rbegin, rend, functor);//���o�[�X�C�e���[�^�{forEach�ŏ���
}
template<typename T, std::size_t N, class FUNCTOR>
void reverseForEach(T(&array)[N], FUNCTOR functor)
{
	T* begin = array + N;
	T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void reverseForEach(const T(&array)[N], FUNCTOR functor)
{
	const T* begin = array + N;
	const T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void reverseForEach(T* array, const std::size_t size, FUNCTOR functor)
{
	T* begin = array + size;
	T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void reverseForEach(const T* array, const std::size_t size, FUNCTOR functor)
{
	const T* begin = array + size;
	const T* end = array;
	reverseForEach(begin, end, functor);
}

//========================================
//�T���A���S���Y��
//========================================

//----------------------------------------
//�A���S���Y���F���`�T�� ���C�e���[�^�Ή���
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(1)
//�E���όv�Z���ԁFO(n/2)
//�E�ň��v�Z���ԁFO(n)
//�E�T�����s���F  O(n)
//----------------------------------------
template<class  ITERATOR, class PREDICATE>
ITERATOR iteratorLinearSearch(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	if (begin == end)
		return end;
	ITERATOR now = begin;
	for (; now != end; ++now)//�����T��
	{
		if (predicate(*now))//�T���L�[�ƈ�v������I��
			return now;
	}
	return end;//�T�����s
}
iteratorSearchFuncSetByPredicate(iteratorLinearSearch);

//----------------------------------------
//�A���S���Y���F�񕪒T�� ���C�e���[�^�Ή���
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(1)
//�E���όv�Z���ԁFO(log n)
//�E�ň��v�Z���ԁFO(log n)
//�E�T�����s���F  O(log n)
//----------------------------------------
template<class  ITERATOR, class COMPARISON>
ITERATOR iteratorBinarySearch(ITERATOR begin, ITERATOR end, COMPARISON comparison)
{
	if (begin == end)
		return end;
	const int size = iteratorDifference(begin, end);
	int range = size;
	ITERATOR found = end;
	while (true)
	{
		const int range_half = range / 2;//�T���͈͂̔����͈̔�
		ITERATOR mid = begin + range_half;//�T���͈͂̒��S�v�f
		const int comp = comparison(*mid);//���S�v�f��T���L�[�Ɣ�r
		if (comp == 0)//���S�v�f���T���L�[�ƈ�v
			found = mid;//���������ꏊ���L�� �����������ʒu�̐擪�𔭌����邽�߁A�T���𑱍s����
		if (range_half == 0)//�T���͈͂��c���Ă��Ȃ���ΒT���I��
			break;
		if (comp <= 0)//�T���L�[�����S�v�f��菬�����������������ꍇ�A���ɒ��S���O�͈̔͂ɍi���ĒT������
			range = range_half;
		else//if (comp > 0)//�T���L�[�����S�v�f���傫�������ꍇ�A���ɒ��S����͈̔͂ɍi���ĒT������
		{
			begin = mid + 1;
			range -= (range_half + 1);
		}
	}
	if (found != end && found != begin)//���������n�_���擪�łȂ���΁A��O�𒲂ׂ�
	{
		ITERATOR found_prev = found;
		--found_prev;
		if (comparison(*found_prev) == 0)//��O����v����Ȃ炻���Ԃ�
			found = found_prev;
	}
	return found;
}
iteratorSearchFuncSetByComparison(iteratorBinarySearch);

//--------------------------------------------------------------------------------
//�o�����A�����X�g�idoubly-linked list�j
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y�{�v���O�����ɂ���������v���z
//�E�e���v���[�g�ɂ��A�A���S���Y����ėp���B
//�E�����N�̕��@�ɏ_����������A���Avirtual��K�{�Ƃ��Ȃ��悤�ɁA
//�@�f�[�^�\���͎��R�Ƃ���B
//�@�i�����N�̕ϐ����|�C���^�ɂ��悤���C���f�b�N�X�ɂ��悤�����R�j
//�E����ɁA�f�[�^�����p�̃N���X�����[�U�[��`���邱�ƂŁA
//�@�����ɔėp������������B
//�E��؃���������͍s�킸�A�m�[�h�̃I�u�W�F�N�g���󂯎���đ��삷��
//�@�A���S���Y���݂̂�񋟂���B
//�Estd::list��͂����R���e�i�ƃC�e���[�^�𗘗p�\�Ƃ���B
//�@�������A�������Ǘ����s��Ȃ����߁A���������悤�ȃ��\�b�h�ɂ͑Ή����Ȃ��B
//�E�R���e�i�́A�擪�m�[�h�Ɩ����m�[�h�݂̂�ێ����A��؃��������삵�Ȃ����̂Ƃ���B
//--------------------------------------------------------------------------------

#include <cstddef>//srd::size_t�p
#include <iterator>//std::iterator�p
#include <algorithm>//C++11 std::move�p

namespace linked_list
{
	//--------------------
	//�o�����A�����X�g�m�[�h����p���e���v���[�g�N���X
	//�����L�̂悤�Ȕh���N���X�iCRTP�j���`���Ďg�p����
	//  //struct �N���X�� : public linked_list::base_ope_t<�N���X��, �m�[�h�^>
	//	struct ope_t : public linked_list::base_ope_t<ope_t, data_t>
	//	{
	//		//�O�m�[�h���擾
	//		inline static const node_type* getPrev(const node_type& node){ return ???; }
	//		//�O�m�[�h��ύX
	//		inline static void setPrev(node_type& node, const node_type* prev){ ??? = prev; }
	//
	//		//���m�[�h���擾
	//		inline static const node_type* getNext(const node_type& node){ return ???; }
	//		//���m�[�h��ύX
	//		inline static void setNext(node_type& node, const node_type* next){ ??? = next; }
	//		
	//		//�\�[�g�p�v���f�B�P�[�g�֐��I�u�W�F�N�g
	//		//���K�v�ɉ����Ď�������
	//		struct sort_predicate{
	//			inline bool operator()(const node_type& lhs, const node_type& rhs) const { return lhs.??? < rhs.???; }
	//		};
	//
	//		//�T���p�v���f�B�P�[�g�֐��I�u�W�F�N�g
	//		//���K�v�ɉ����Ď�������
	//		struct find_predicate{
	//			inline bool operator()(const node_type& lhs, const ???& rhs) const { return lhs.??? == rhs; }
	//		};
	//		
	//		//���b�N�^ ���K�v�ɉ����Ē�`
	//		//�����L���b�N�i���[�h�E���C�g���b�N�j�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
	//		//�@�L���ȋ��L���b�N�^�ishared_spin_lock�Ȃǁj�� lock_type �^�Ƃ��Ē�`����B
	//		typedef shared_spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
	//	};
	template<class OPE_TYPE, typename NODE_TYPE>
	struct base_ope_t
	{
		//�^
		typedef OPE_TYPE ope_type;//�m�[�h����^
		typedef NODE_TYPE node_type;//�m�[�h�^

		//���b�N�^
		typedef dummy_shared_lock lock_type;//���b�N�I�u�W�F�N�g�^
		//���f�t�H���g�̓_�~�[�̂��߁A��؃��b�N���䂵�Ȃ��B
		//�����L���b�N�i���[�h�E���C�g���b�N�j�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
		//�@base_ope_t�̔h���N���X�ɂāA�L���ȋ��L���b�N�^�ishared_spin_lock �Ȃǁj��
		//�@lock_type �^�Ƃ��čĒ�`����B

		//�O�m�[�h���擾 ��const�O��(remove_const)
		inline static node_type* getPrev_rc(node_type& node){ return const_cast<node_type*>(ope_type::getPrev(const_cast<const node_type&>(node))); }
		//���m�[�h���擾 ��const�O��(remove_const)
		inline static node_type* getNext_rc(node_type& node){ return const_cast<node_type*>(ope_type::getNext(const_cast<const node_type&>(node))); }

		//�\�[�g�p�v���f�B�P�[�g�֐��I�u�W�F�N�g
		//��true��lhs�̕����������i���я����������j
		struct sort_predicate{
			inline bool operator()(const node_type& lhs, const node_type& rhs) const { return less<node_type>()(lhs, rhs); }
		};

		//���`�T���p�v���f�B�P�[�g�֐��I�u�W�F�N�g
		//��true�ň�v�i�T�������j
		struct find_predicate{
			template<typename V>
			inline bool operator()(const node_type& lhs, const V& rhs) const { return equal_to<node_type>()(lhs, rhs); }
		};

	#ifdef ENABLE_BINARY_SEARCH
		//�񕪒T���p��r�֐��I�u�W�F�N�g
		//��0�ň�v�i�T�������j�A1�ȏ��lhs�̕����傫���A-1�ȉ���rhs�̕����傫��
		struct search_comparison{
			template<typename V>
			inline int operator()(const node_type& lhs, const V& rhs) const { return compare_to<node_type>()(lhs, rhs); }
		};
	#endif//ENABLE_BINARY_SEARCH
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef node_type& reference; \
		typedef const node_type& const_reference; \
		typedef node_type* pointer; \
		typedef const node_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type; \
		typedef typename ope_type::lock_type lock_type;
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̎��m�[�h���擾
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getNextNode(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		node = ope_type::getNext(*node);
		return node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̌���̃m�[�h���擾
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getForwardNode(const typename OPE_TYPE::node_type& target, std::size_t& step)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		while (step > 0 && node)
		{
			node = ope_type::getNext(*node);
			--step;
		}
		return node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̑O�m�[�h���擾
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getPrevNode(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		node = ope_type::getPrev(*node);
		return node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̑O���̃m�[�h���擾
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getBackwardNode(const typename OPE_TYPE::node_type& target, std::size_t& step)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		while (step > 0 && node)
		{
			node = ope_type::getPrev(*node);
			--step;
		}
		return node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̐擪�m�[�h���擾
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getFirstNode(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		while (true)
		{
			const typename ope_type::node_type* prev = ope_type::getPrev(*node);
			if (!prev)
				return node;
			node = prev;
		}
		return nullptr;//�_�~�[
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̖����m�[�h���擾
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getLastNode(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		while (true)
		{
			const typename ope_type::node_type* next = ope_type::getNext(*node);
			if (!next)
				return node;
			node = next;
		}
		return nullptr;//�_�~�[
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̐��𐔂���
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		std::size_t num = 1;
		const typename ope_type::node_type* node = &target;
		while (true)
		{
			const typename ope_type::node_type* next = ope_type::getNext(*node);
			if (!next)
				return num;
			++num;
			node = next;
		}
		return 0;//�_�~�[
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̎��ɘA��
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* insertNodeAfter(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type& target, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		typename ope_type::node_type* next = const_cast<typename ope_type::node_type*>(ope_type::getNext(target));
		if (!next)
			last = &node;
		else
			ope_type::setPrev(*next, &node);
		ope_type::setPrev(node, &target);
		ope_type::setNext(target, &node);
		ope_type::setNext(node, next);
		return &node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�̑O�ɘA��
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* insertNodeBefore(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type& target, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		typename ope_type::node_type* prev = const_cast<typename ope_type::node_type*>(ope_type::getPrev(target));
		if (!prev)
			first = &node;
		else
			ope_type::setNext(*prev, &node);
		ope_type::setNext(node, &target);
		ope_type::setPrev(target, &node);
		ope_type::setPrev(node, prev);
		return &node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�擪�ɘA��
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* insertNodeBeginning(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!first)
		{
			first = &node;
			last = &node;
			ope_type::setPrev(node, nullptr);
			ope_type::setNext(node, nullptr);
			return &node;
		}
		ope_type::setNext(node, first);
		ope_type::setPrev(*first, &node);
		ope_type::setPrev(node, nullptr);
		first = &node;
		return &node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�����ɘA��
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* insertNodeEnd(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!last)
		{
			first = &node;
			last = &node;
			ope_type::setPrev(node, nullptr);
			ope_type::setNext(node, nullptr);
			return &node;
		}
		ope_type::setPrev(node, last);
		ope_type::setNext(*last, &node);
		ope_type::setNext(node, nullptr);
		last = &node;
		return &node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h��A������O��
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* removeNode(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		typename ope_type::node_type* prev = const_cast<typename ope_type::node_type*>(ope_type::getPrev(node));
		typename ope_type::node_type* next = const_cast<typename ope_type::node_type*>(ope_type::getNext(node));
		if (prev)
			ope_type::setNext(*prev, next);
		else
			first = next;
		if (next)
			ope_type::setPrev(*next, prev);
		else
			last = prev;
		ope_type::setPrev(node, nullptr);
		ope_type::setNext(node, nullptr);
		return &node;
	}
	//--------------------
	//�o�����A�����X�g����֐��F�w��m�[�h�͈̔͂�A������O��
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* removeNodes(typename OPE_TYPE::node_type& start, typename OPE_TYPE::node_type& end, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		typename ope_type::node_type* prev = const_cast<typename ope_type::node_type*>(ope_type::getPrev(start));
		typename ope_type::node_type* next = &end;
		typename ope_type::node_type* _end = next ? const_cast<typename ope_type::node_type*>(ope_type::getPrev(end)) : last;
		if (prev)
			ope_type::setNext(*prev, next);
		else
			first = next;
		if (next)
			ope_type::setPrev(*next, prev);
		else
			last = prev;
		ope_type::setPrev(start, nullptr);
		ope_type::setNext(*_end, nullptr);
		return &start;
	}

	//========================================
	//�\�[�g�A���S���Y��
	//========================================

	//----------------------------------------
	//��r�\�[�g�����I�[�o�[���[�h�֐��p�}�N��
	//���A�����X�g�Ή���
	//���W���v���f�B�P�[�g�֐��g�p��
	#define liskedListSortFuncSetByDefaultPredicate(func_name) \
		template<class OPE_TYPE> \
		inline std::size_t func_name(typename OPE_TYPE::node_type* first) \
		{ \
			typedef typename OPE_TYPE::node_type node_type; \
			return func_name<OPE_TYPE>(first, less<node_type>()); \
		}
	#define linkedListSortFuncSet(func_name) \
		liskedListSortFuncSetByDefaultPredicate(func_name)

	//----------------------------------------
	//�����Ԋm�F ���A�����X�g�Ή���
	template<class OPE_TYPE, class PREDICATE>
	inline std::size_t linkedListCalcUnordered(const typename OPE_TYPE::node_type* start, PREDICATE predicate)
	{
		typedef typename OPE_TYPE::node_type node_type;
		std::size_t unordered = 0;
		const node_type* prev = start;
		const node_type* now = OPE_TYPE::getNext(*prev);
		while(now)
		{
			if (predicate(*now, *prev))
				++unordered;
			now = OPE_TYPE::getNext(*now);
		}
		return unordered;
	}
	linkedListSortFuncSet(linkedListCalcUnordered);

	//========================================
	//�\�[�g�A���S���Y�����ށF�}���\�[�g
	//========================================

	//----------------------------------------
	//�A���S���Y���F�}���\�[�g ���o�����A�����X�g�Ή���
	//----------------------------------------
	//�E�ŗǌv�Z���ԁFO(n)
	//�E���όv�Z���ԁFO(n^2)
	//�E�ň��v�Z���ԁFO(n^2)
	//�E�������g�p�ʁFO(1)
	//�E���萫�F�@�@�@��
	//----------------------------------------
	template<class OPE_TYPE, class PREDICATE>
	std::size_t linkedListInsertionSort(typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last, PREDICATE predicate)
	{
		typedef typename OPE_TYPE::node_type node_type;
		if (!first || !OPE_TYPE::getNext(*first))
			return 0;
		std::size_t swapped_count = 0;
		node_type* now = first;
		node_type* next = const_cast<node_type*>(OPE_TYPE::getNext(*now));
		while (next)
		{
			if (predicate(*next, *now))
			{
				node_type* min = now;
				node_type* prev = const_cast<node_type*>(OPE_TYPE::getPrev(*now));
				while (prev)
				{
					if (predicate(*next, *prev))
						min = prev;
					else
						break;
					prev = const_cast<node_type*>(OPE_TYPE::getPrev(*prev));
				}
				removeNode<OPE_TYPE>(*next, first, last);
				insertNodeBefore<OPE_TYPE>(*next, *min, first, last);
				++swapped_count;
				next = const_cast<node_type*>(OPE_TYPE::getNext(*now));
			}
			else
			{
				now = next;
				next = const_cast<node_type*>(OPE_TYPE::getNext(*next));
			}
		}
		return swapped_count;
	}
	linkedListSortFuncSet(linkedListInsertionSort);

	//----------------------------------------
	//�A���S���Y���F�V�F���\�[�g ���o�����A�����X�g�Ή���
	//----------------------------------------
	//�E�ŗǌv�Z���ԁFO(n)
	//�E���όv�Z���ԁFO(n log^2 n) or O(n^3/2)
	//�E�ň��v�Z���ԁFO(n log^2 n)
	//�E�������g�p�ʁFO(1)
	//�E���萫�F�@�@�@�~
	//----------------------------------------
	template<class OPE_TYPE, class PREDICATE>
	std::size_t linkedListShellSort(typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last, PREDICATE predicate)
	{
		typedef typename OPE_TYPE::node_type node_type;
		if (!first || !OPE_TYPE::getNext(*first))
			return 0;
		std::size_t swapped_count = 0;
		std::size_t size = 0;
		{
			const node_type* node = first;
			while (node)
			{
				++size;
				node = OPE_TYPE::getNext(*node);
			}
		}
		const int h_max = size / 3;
		int h = 1;
		while (h <= h_max)
			h = 3 * h + 1;
		while (h > 0)
		{
			node_type* now = first;
			node_type* next = now;
			for (int i = 0; i < h && next; ++i)
				next = const_cast<node_type*>(OPE_TYPE::getNext(*next));
			while (next)
			{
				if (predicate(*next, *now))
				{
					node_type* min = now;
					node_type* prev = now;
					for (int i = 0; i < h && prev; ++i)
						prev = const_cast<node_type*>(OPE_TYPE::getPrev(*prev));
					while (prev)
					{
						if (predicate(*next, *prev))
							min = prev;
						else
							break;
						for (int i = 0; i < h && prev; ++i)
							prev = const_cast<node_type*>(OPE_TYPE::getPrev(*prev));
					}
					removeNode<OPE_TYPE>(*next, first, last);
					insertNodeBefore<OPE_TYPE>(*next, *min, first, last);
					++swapped_count;
					next = now;
					for (int i = 0; i < h && next; ++i)
						next = const_cast<node_type*>(OPE_TYPE::getNext(*next));
				}
				else
				{
					now = const_cast<node_type*>(OPE_TYPE::getNext(*now));
					next = const_cast<node_type*>(OPE_TYPE::getNext(*next));
				}
			}
			h = (h - 1) / 3;
		}
		return swapped_count;
	}
	linkedListSortFuncSet(linkedListShellSort);

	//----------------------------------------
	//�o�����A�����X�g�R���e�i
	//���擪�m�[�h�Ɩ����m�[�h�����̂�
	//��std::list��͂����\��
	template<class OPE_TYPE>
	class container
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//--------------------
		//�C�e���[�^�錾
		class iterator;
		class reverse_iterator;
		typedef const iterator const_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		//--------------------
		//�C�e���[�^
		class iterator : public std::iterator<std::bidirectional_iterator_tag, node_type>
		{
			friend class container;
			friend class reverse_iterator;
		public:
			//�L���X�g�I�y���[�^
			inline operator bool() const { return isExist(); }
			inline operator const node_type() const { return *getNode(); }
			inline operator node_type&(){ return *getNode(); }
		public:
			//�I�y���[�^
			inline const_reference operator*() const { return *getNode(); }
			inline reference operator*(){ return *getNode(); }
			inline const_pointer operator->() const { return getNode(); }
			inline pointer operator->(){ return getNode(); }
		#if 1//std::bidirectional_iterator_tag �ɂ͖{���K�v�ł͂Ȃ�
			inline const_iterator operator[](const int index) const
			{
				iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
			inline iterator operator[](const int index)
			{
				iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
		#endif
			//��r�I�y���[�^
			inline bool operator==(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       m_node == rhs.m_node;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? false :
				       m_isEnd || rhs.m_isEnd ? true :
					   m_node != rhs.m_node;
			}
			//���Z�I�y���[�^
			inline const_iterator& operator++() const
			{
				updateNext();
				return *this;
			}
			inline const_iterator& operator--() const
			{
				updatePrev();
				return *this;
			}
			inline iterator& operator++()
			{
				updateNext();
				return *this;
			}
			inline iterator& operator--()
			{
				updatePrev();
				return *this;
			}
			inline const_iterator operator++(int) const
			{
				iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return  std::move(ite);
			}
			inline iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return  std::move(ite);
			}
			inline iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return  std::move(ite);
			}
		#if 1//std::bidirectional_iterator_tag �ɂ͖{���K�v�ł͂Ȃ�
			inline const_iterator& operator+=(const typename iterator::difference_type rhs) const
			{
				updateForward(rhs);
				return *this;
			}
			inline const_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline const_iterator& operator-=(const typename iterator::difference_type rhs) const
			{
				updateBackward(rhs);
				return *this;
			}
			inline const_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator+=(const typename iterator::difference_type rhs)
			{
				updateForward(rhs);
				return *this;
			}
			inline iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator-=(const typename iterator::difference_type rhs)
			{
				updateBackward(rhs);
				return *this;
			}
			inline iterator& operator-=(const std::size_t rhs)
			{
				return operator-=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline const_iterator operator+(const typename iterator::difference_type rhs) const
			{
				iterator ite(*this);
				ite += rhs;
				return  std::move(ite);
			}
			inline const_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline const_iterator operator-(const typename iterator::difference_type rhs) const
			{
				iterator ite(*this);
				ite -= rhs;
				return  std::move(ite);
			}
			inline const_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator+(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite += rhs;
				return  std::move(ite);
			}
			inline iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator-(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite -= rhs;
				return  std::move(ite);
			}
			inline iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			//inline typename iterator::difference_type operator-(const iterator rhs)
			//{
			//	return ???;
			//}
		#endif
		public:
			//���[�u�I�y���[�^
			inline iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			iterator& operator=(const_reverse_iterator&& rhs);
			//�R�s�[�I�y���[�^
			inline iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			iterator& operator=(const_reverse_iterator& rhs);
		public:
			//�A�N�Z�b�T
			inline bool isExist() const { return m_node != nullptr; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_node != nullptr || m_isEnd; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_isEnd; }//�I�[���H
			inline const node_type* getNode() const { return m_node; }//���݂̃m�[�h
			inline node_type* getNode(){ return m_node; }//���݂̃m�[�h
		private:
			//���\�b�h
			inline void updateNext() const
			{
				node_type* prev = m_node;
				if (m_node)
					m_node = const_cast<node_type*>(getNextNode<ope_type>(*m_node));
				m_isEnd = (prev && !m_node);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					m_node = const_cast<node_type*>(m_con->m_last);
					m_isEnd = false;
					return;
				}
				if (m_node)
					m_node = const_cast<node_type*>(getPrevNode<ope_type>(*m_node));
				m_isEnd = false;
			}
			void updateForward(const std::size_t step) const
			{
				std::size_t _step = step;
				node_type* prev = m_node;
				if (m_node)
					m_node = const_cast<node_type*>(getForwardNode<ope_type>(*m_node, _step));
				m_isEnd = (prev && !m_node && _step == 0);
			}
			void updateBackward(const std::size_t step) const
			{
				std::size_t _step = step;
				if (_step > 0 && m_isEnd)
				{
					m_node = const_cast<node_type*>(m_con->m_last);
					--_step;
				}
				if (m_node)
					m_node = const_cast<node_type*>(getBackwardNode<ope_type>(*m_node, _step));
				m_isEnd = false;
			}
		public:
			//���[�u�R���X�g���N�^
			inline iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			iterator(const_reverse_iterator&& obj);
			//�R�s�[�R���X�g���N�^
			inline iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			iterator(const_reverse_iterator& obj);
			//�R���X�g���N�^
			inline iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_node(nullptr),
				m_isEnd(is_end)
			{
				if (!is_end)
				{
					m_node = const_cast<node_type*>(con.m_first);
					if (!m_node)
						m_isEnd = true;
				}
			}
			inline iterator(const container& con, node_type* node, const bool is_end) :
				m_con(&con),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline iterator() :
				m_con(nullptr),
				m_node(nullptr),
				m_isEnd(false)
			{}
			//�f�X�g���N�^
			inline ~iterator()
			{}
		protected:
			//�t�B�[���h
			const container* m_con;//�R���e�i
			mutable node_type* m_node;//���݂̃m�[�h
			mutable bool m_isEnd;//�I�[���H
		};
		//--------------------
		//���o�[�X�C�e���[�^
		//class reverse_iterator : public std::reverse_iterator<iterator>
		class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, node_type>
		{
			friend class container;
			friend class iterator;
		public:
			//�L���X�g�I�y���[�^
			inline operator bool() const { return isExist(); }
			inline operator const node_type() const { return *getNode(); }
			inline operator node_type&(){ return *getNode(); }
		public:
			//�I�y���[�^
			inline const_reference operator*() const { return *getNode(); }
			inline reference operator*(){ return *getNode(); }
			inline const_pointer operator->() const { return getNode(); }
			inline pointer operator->(){ return getNode(); }
		#if 1//std::bidirectional_iterator_tag �ɂ͖{���K�v�ł͂Ȃ�
			inline const_reverse_iterator operator[](const int index) const
			{
				reverse_iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
		#endif
		public:
			//��r�I�y���[�^
			inline bool operator==(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
					   m_node == rhs.m_node;
			}
			inline bool operator!=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? false :
				       rhs.m_isEnd || m_isEnd ? true :
					   m_node != rhs.m_node;
			}
			//���Z�I�y���[�^
			inline const_reverse_iterator& operator++() const
			{
				updateNext();
				return *this;
			}
			inline const_reverse_iterator& operator--() const
			{
				updatePrev();
				return *this;
			}
			inline reverse_iterator& operator++()
			{
				updateNext();
				return *this;
			}
			inline reverse_iterator& operator--()
			{
				updatePrev();
				return *this;
			}
			inline const_reverse_iterator operator++(int) const
			{
				reverse_iterator ite(*this);
				++(*this);
				return  std::move(ite);
			}
			inline const_reverse_iterator operator--(int) const
			{
				reverse_iterator ite(*this);
				--(*this);
				return  std::move(ite);
			}
			inline reverse_iterator operator++(int)
			{
				reverse_iterator ite(*this);
				++(*this);
				return  std::move(ite);
			}
			inline reverse_iterator operator--(int)
			{
				reverse_iterator ite(*this);
				--(*this);
				return  std::move(ite);
			}
		#if 1//std::bidirectional_iterator_tag �ɂ͖{���K�v�ł͂Ȃ�
			inline const_reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs) const
			{
				updateForward(rhs);
				return *this;
			}
			inline const_reverse_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline const_reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs) const
			{
				updateBackward(rhs);
				return *this;
			}
			inline const_reverse_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs)
			{
				updateForward(rhs);
				return *this;
			}
			inline reverse_iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs)
			{
				updateBackward(rhs);
				return *this;
			}
			inline reverse_iterator& operator-=(const std::size_t rhs)
			{
				return operator-=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline const_reverse_iterator operator+(const typename reverse_iterator::difference_type rhs) const
			{
				reverse_iterator ite(*this);
				ite += rhs;
				return  std::move(ite);
			}
			inline const_reverse_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline const_reverse_iterator operator-(const typename reverse_iterator::difference_type rhs) const
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return  std::move(ite);
			}
			inline const_reverse_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator+(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite += rhs;
				return  std::move(ite);
			}
			inline reverse_iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator-(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return  std::move(ite);
			}
			inline reverse_iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			//inline typename reverse_iterator::difference_type operator-(const reverse_iterator rhs)
			//{
			//	return ???;
			//}
		#endif
		public:
			//���[�u�I�y���[�^
			inline reverse_iterator& operator=(const_reverse_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = false;
				if (m_node)
				{
					++(*this);
				}
				else
				{
					if (rhs.m_isEnd)
						m_node = const_cast<node_type*>(m_con->m_last);
				}
				return *this;
			}
			//�R�s�[�I�y���[�^
			inline reverse_iterator& operator=(const_reverse_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = false;
				if (m_node)
				{
					++(*this);
				}
				else
				{
					if (rhs.m_isEnd)
						m_node = const_cast<node_type*>(m_con->m_last);
				}
				return *this;
			}
		public:
			//�A�N�Z�b�T
			inline bool isExist() const { return m_node != nullptr; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_node != nullptr || m_isEnd; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_isEnd; }//�I�[���H
			inline const node_type* getNode() const { return m_node; }//���݂̃m�[�h
			inline node_type* getNode(){ return m_node; }//���݂̃m�[�h
		public:
			//���\�b�h
			inline void updateNext() const
			{
				node_type* prev = m_node;
				if (m_node)
					m_node = const_cast<node_type*>(getPrevNode<ope_type>(*m_node));
				m_isEnd = (prev && !m_node);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					m_node = const_cast<node_type*>(m_con->m_first);
					m_isEnd = false;
					return;
				}
				if (m_node)
					m_node = const_cast<node_type*>(getNextNode<ope_type>(*m_node));
				m_isEnd = false;
			}
			void updateForward(const std::size_t step) const
			{
				std::size_t _step = step;
				node_type* prev = m_node;
				if (m_node)
					m_node = const_cast<node_type*>(getBackwardNode<ope_type>(*m_node, _step));
				m_isEnd = (prev && !m_node && _step == 0);
			}
			void updateBackward(const std::size_t step) const
			{
				std::size_t _step = step;
				if (_step > 0 && m_isEnd)
				{
					m_node = const_cast<node_type*>(m_con->m_first);
					--_step;
				}
				if (m_node)
					m_node = const_cast<node_type*>(getForwardNode<ope_type>(*m_node, _step));
				m_isEnd = false;
			}
		public:
			//�x�[�X���擾
			inline const_iterator base() const
			{
				iterator ite(*this);
				return std::move(ite);
			}
			inline iterator base()
			{
				iterator ite(*this);
				return std::move(ite);
			}
		public:
			//���[�u�R���X�g���N�^
			inline reverse_iterator(const_reverse_iterator&& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(false)
			{
				if (m_node)
				{
					++(*this);
				}
				else
				{
					if (obj.m_isEnd)
						m_node = const_cast<node_type*>(m_con->m_last);
				}
			}
			//�R�s�[�R���X�g���N�^
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{
				if (m_node)
				{
					++(*this);
				}
				else
				{
					if (obj.m_isEnd)
						m_node = const_cast<node_type*>(m_con->m_last);
				}
			}
			//�R���X�g���N�^
			inline reverse_iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_node(nullptr),
				m_isEnd(is_end)
			{
				if (!is_end)
				{
					m_node = const_cast<node_type*>(m_con->m_last);
					if (!m_node)
						m_isEnd = true;
				}
			}
			inline reverse_iterator(const container& con, node_type* node, const bool is_end) :
				m_con(con),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline reverse_iterator() :
				m_con(nullptr),
				m_node(nullptr),
				m_isEnd(false)
			{}
			//�f�X�g���N�^
			inline ~reverse_iterator()
			{}
		protected:
			//�t�B�[���h
			const container* m_con;//�R���e�i
			mutable node_type* m_node;//���݂̃m�[�h
			mutable bool m_isEnd;//�I�[���H
		};
	public:
		//�A�N�Z�b�T
		//��std::list�ƈقȂ�A�m�[�h�̃|�C���^��Ԃ�
		const node_type* at(const index_type index) const
		{
			return getForwardNode<ope_type>(m_first, index);
		}
		inline node_type* at(const index_type index){ return const_cast<node_type*>(const_cast<const container*>(this)->at(index)); }
		inline const node_type* operator[](const index_type index) const { return at(index); }
		inline node_type* operator[](const index_type index){ return at(index); }
	public:
		//�L���X�g�I�y���[�^
		inline operator lock_type&(){ return m_lock; }//���b�N�I�u�W�F�N�g
		inline operator lock_type&() const { return m_lock; }//���b�N�I�u�W�F�N�g ��mutable
	public:
		//���\�b�h
		//inline std::size_t max_size() const { return (�s��); }
		//inline std::size_t capacity() const { return (�s��); }
		inline std::size_t size() const { return m_first ? countNodes<ope_type>(*m_first) : 0; }//�m�[�h�����擾
		inline bool empty() const { return m_first == nullptr; }//�󂩁H
		inline node_type* front(){ return m_first; }//�擪�m�[�h���Q��
		inline const node_type* front() const { return m_first; }//�擪�m�[�h���Q��
		inline node_type*& first_ref(){ return m_first; }//�擪�m�[�h�̎Q�Ƃ��擾
		inline node_type* back(){ return m_last; }//�����m�[�h���Q��
		inline const node_type* back() const { return m_last; }//�����m�[�h���Q��
		inline node_type*& last_ref(){ return m_last; }//�����m�[�h�̎Q�Ƃ��擾
		//�C�e���[�^���擾
		//�������I�ȋ��L���b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�S�̂̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
		inline const_iterator cbegin() const
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_iterator cend() const
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
		inline const_iterator begin() const
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_iterator end() const
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
		inline iterator begin()
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline iterator end()
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
		//���o�[�X�C�e���[�^���擾
		//�������I�ȋ��L���b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�S�̂̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
		inline const_reverse_iterator crbegin() const
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_reverse_iterator crend() const
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
		inline const_reverse_iterator rbegin() const
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_reverse_iterator rend() const
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
		inline reverse_iterator rbegin()
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline reverse_iterator rend()
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
		
		//�ǉ��^�폜�n���\�b�h
		//��std::list�ƈقȂ�A�ǉ��^�폜�Ώۂ̃m�[�h�𒼐ڎw�肵�A���ʂ��|�C���^�Ŏ󂯎��i����������A�ǉ��^�폜�����|�C���^��Ԃ��j
		//���v�f�̃������m�ہ^������s��Ȃ��_�ɒ���
		//��assign(), remove_if(), emplace(), emplace_front(), emplase_back()�ɂ͔�Ή�
		//��insert_before()��ǉ�
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		
		//�擪�Ƀm�[�h��}���i�A���ɒǉ��j
		inline node_type* push_front(const node_type& node)
		{
			return insertNodeBeginning<ope_type>(*const_cast<node_type*>(&node), m_first, m_last);
		}
		//�����Ƀm�[�h��}���i�A���ɒǉ��j
		inline node_type* push_back(const node_type& node)
		{
			return insertNodeEnd<ope_type>(*const_cast<node_type*>(&node), m_first, m_last);
		}
		//�擪�m�[�h���폜�i�A�������j
		inline node_type* pop_front()
		{
			if (!m_first)
				return nullptr;
			return removeNode<ope_type>(*m_first, m_first, m_last);
		}
		//�����m�[�h���폜�i�A�������j
		inline node_type* pop_back()
		{
			if (!m_first)
				return nullptr;
			return removeNode<ope_type>(*m_last, m_first, m_last);
		}
		//�w��̈ʒu�̌��Ƀm�[�h��}���i�A���ɒǉ��j
		//���ʒu�̓C�e���[�^�Ŏw��
		inline node_type* insert(iterator pos, const node_type& node)
		{
			if (pos.isNotExist())
				return nullptr;
			return insertNodeAfter<ope_type>(*const_cast<node_type*>(&node), *pos, m_first, m_last);
		}
		//�w��̈ʒu�̑O�Ƀm�[�h��}���i�A���ɒǉ��j
		//���ʒu�̓C�e���[�^�Ŏw��
		inline node_type* insert_before(iterator pos, const node_type& node)
		{
			if (pos.isNotExist())
				return nullptr;
			return insertNodeBefore<ope_type>(*const_cast<node_type*>(&node), *pos, m_first, m_last);
		}
		//�w��m�[�h���폜�i�A�������j
		inline node_type* remove(node_type& node)
		{
			if (!m_first)
				return nullptr;
			return removeNode<ope_type>(node, m_first, m_last);
		}
		//�w��ʒu�̃m�[�h���폜�i�A�������j
		//���ʒu�̓C�e���[�^�Ŏw��
		inline node_type* erase(iterator pos)
		{
			if (!m_first || pos.isNotExist())
				return nullptr;
			return removeNode<ope_type>(*pos, m_first, m_last);
		}
		//�w��͈͂̃m�[�h���폜�i�A�������j
		//���͈͂̓C�e���[�^�Ŏw��
		inline node_type* erase(iterator start, iterator end)
		{
			if (!m_first || start.isNotExist() || end.isNotEnabled())
				return nullptr;
			return removeNodes<ope_type>(*start, *end, m_first, m_last);
		}
		//�S�m�[�h���N���A
		//���擪�m�[�h��Ԃ�
		inline node_type* clear()
		{ 
			node_type* first = m_first;
			m_first = nullptr;
			m_last = nullptr;
			return first;
		}
	public:
		//�\�[�g
		//���}���\�[�g���g�p�i�V�F���\�[�g�ł͂��܂葬�x���オ��Ȃ����߁j
		//��ope_type::sort_predicate() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator<() �ɏ]���ĒT���j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		void sort()
		{
		#ifdef USE_SHELL_SORT
			linkedListShellSort<OPE_TYPE>(m_first, m_last, typename ope_type::sort_predicate());
		#else//USE_SHELL_SORT
			linkedListInsertionSort<OPE_TYPE>(m_first, m_last, typename ope_type::sort_predicate());
		#endif//USE_SHELL_SORT
		}
		//���v���f�B�P�[�g�֐��w���
		template<class PREDICATE>
		void sort(PREDICATE predicate)
		{
		#ifdef USE_SHELL_SORT
			linkedListShellSort<OPE_TYPE>(m_first, m_last, predicate);
		#else//USE_SHELL_SORT
			linkedListInsertionSort<OPE_TYPE>(m_first, m_last, predicate);
		#endif//USE_SHELL_SORT
		}
	#ifdef ENABLE_STABLE_SORT
		//����\�[�g
		//���}���\�[�g���g�p
		//��ope_type::sort_predicate() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator<() �ɏ]���ĒT���j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		void stable_sort()
		{
			linkedListInsertionSort<OPE_TYPE>(m_first, m_last, typename ope_type::sort_predicate());
		}
		//���v���f�B�P�[�g�֐��w���
		template<class PREDICATE>
		void stable_sort(PREDICATE predicate)
		{
			linkedListInsertionSort<OPE_TYPE>(m_first, m_last, predicate);
		}
	#endif//ENABLE_STABLE_SORT
		//�\�[�g�ςݏ�ԃ`�F�b�N
		//��ope_type::sort_predicate() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator<() �ɏ]���ĒT���j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
		bool is_ordered() const
		{
			return linkedListCalcUnordered<OPE_TYPE>(m_first, typename ope_type::sort_predicate()) == 0;
		}
		//���v���f�B�P�[�g�֐��w���
		template<class PREDICATE>
		bool is_ordered(PREDICATE predicate) const
		{
			return linkedListCalcUnordered<OPE_TYPE>(m_first, predicate) == 0;
		}
	public:
		//���`�T��
		//���T���l�w���
		//��ope_type::find_predicate() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator==() �ɏ]���ĒT���j
		//�������I�ȋ��L���b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
		template<typename V>
		iterator find_value(const V& value)
		{
			iterator found = iteratorLinearSearchValue(begin(), end(), value, typename ope_type::find_predicate());
			return std::move(found);
		}
		//����r�֐��{�l�w���
		template<typename V, class PREDICATE>
		iterator find_value(const V& value, PREDICATE predicate)
		{
			iterator found = iteratorLinearSearchValue(begin(), end(), value, predicate);
			return std::move(found);
		}
		//����r�֐��w���
		//���l�̎w��͊֐��Ɋ܂�ł����i�N���\�W����p����Ȃǂ���j
		template<class PREDICATE>
		iterator find(PREDICATE predicate)
		{
			iterator found = iteratorLinearSearch(begin(), end(), predicate);
			return std::move(found);
		}
	#ifdef ENABLE_BINARY_SEARCH
		//�񕪒T��
		//���T���l�w���
		//��ope_type::search_comparison() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator==() �� operator<() �ɏ]���ĒT���j
		//�������I�ȋ��L���b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
		template<typename V>
		iterator binary_search_value(const V& value)
		{
			iterator found = iteratorBinarySearchValue(begin(), end(), value, typename ope_type::search_comparison());
			return std::move(found);
		}
		//����r�֐��{�l�w���
		template<typename V, class COMPARISON>
		iterator binary_search_value(const V& value, COMPARISON comparison)
		{
			iterator found = iteratorBinarySearchValue(begin(), end(), value, comparison);
			return std::move(found);
		}
		//����r�֐��w���
		//���l�̎w��͊֐��Ɋ܂�ł����i�N���\�W����p����Ȃǂ���j
		template<class COMPARISON>
		iterator binary_search(COMPARISON comparison)
		{
			iterator found = iteratorBinarySearch(begin(), end(), comparison);
			return std::move(found);
		}
	#endif//ENABLE_BINARY_SEARCH

		//���X�g����n���\�b�h
		//��merge(), splice(), reverse(), unique()�ɂ͔�Ή�

	public:
		//���[�u�R���X�g���N�^
		container(const container&& con) :
			m_first(con.m_first),
			m_last(con.m_last)
		{}
		//�R�s�[�R���X�g���N�^
		container(const container& con) :
			m_first(con.m_first),
			m_last(con.m_last)
		{}
		//�R���X�g���N�^
		container() :
			m_first(nullptr),
			m_last(nullptr)
		{}
		//�f�X�g���N�^
		~container()
		{}
	private:
		//�t�B�[���h
		node_type* m_first;//�擪�m�[�h
		node_type* m_last;//�����m�[�h
		mutable lock_type m_lock;//���b�N�I�u�W�F�N�g
	};
	//�C�e���[�^�̃��[�u�I�y���[�^
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator&& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator&& rhs)//VC++��OK
	{
		m_con = rhs.m_con;
		m_node = rhs.m_node;
		m_isEnd = false;
		if (m_node)
		{
			++(*this);
		}
		else
		{
			if (rhs.m_isEnd)
				m_node = const_cast<node_type*>(m_con->m_first);
		}
		return *this;
	}
	//�C�e���[�^�̃R�s�[�I�y���[�^
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator& rhs)//VC++��OK
	{
		m_con = rhs.m_con;
		m_node = rhs.m_node;
		m_isEnd = false;
		if (m_node)
		{
			++(*this);
		}
		else
		{
			if (rhs.m_isEnd)
				m_node = const_cast<node_type*>(m_con->m_first);
		}
		return *this;
	}
	//�C�e���[�^�̃��[�u�R���X�g���N�^
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator&& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator&& obj) ://VC++��OK
		m_con(obj.m_con),
		m_node(obj.m_node),
		m_isEnd(false)
	{
		if (m_node)
		{
			++(*this);
		}
		else
		{
			if (obj.m_isEnd)
				m_node = const_cast<node_type*>(m_con->m_first);
		}
	}
	//�C�e���[�^�̃R�s�[�R���X�g���N�^
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator& obj) ://VC++��OK
		m_con(obj.m_con),
		m_node(obj.m_node),
		m_isEnd(false)
	{
		if (m_node)
		{
			++(*this);
		}
		else
		{
			if (obj.m_isEnd)
				m_node = const_cast<node_type*>(m_con->m_first);
		}
	}
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace linked_list

//--------------------------------------------------------------------------------
//�o�����A�����X�g�e�X�g
//--------------------------------------------------------------------------------

#include <algorithm>//std::for_each�p
#include <chrono>//C++11 ���Ԍv���p
#include <list>//std::list�p�i��r�p�j
#include <assert.h>//assert�p

//----------------------------------------
//�e�X�g�p�⏕�֐�
#ifdef PRINT_TEST_DATA_DETAIL
template<typename... Tx>
inline int printf_detail(const char* fmt, Tx... args)
{
	return printf(fmt, args...);
}
#else//PRINT_TEST_DATA_DETAIL
inline int printf_detail(const char* fmt, ...){ return 0; }
#endif//PRINT_TEST_DATA_DETAIL
#ifdef PRINT_TEST_DATA_SEARCH
template<typename... Tx>
inline int printf_dbg_search(const char* fmt, Tx... args)
{
	return printf(fmt, args...);
}
#else//PRINT_TEST_DATA_SEARCH
inline int printf_dbg_search(const char* fmt, ...){ return 0; }
#endif//PRINT_TEST_DATA_SEARCH

//----------------------------------------
//�e�X�g�f�[�^
struct data_t
{
	mutable const data_t* m_prev;//�O�m�[�h
	mutable const data_t* m_next;//���m�[�h
	
	int m_key;//�L�[
	int m_val;//�l
	
	//�R���X�g���N�^
	data_t(const int key, const int val) :
		m_next(nullptr),
		m_prev(nullptr),
		m_key(key),
		m_val(val)
	{}
	data_t() :
		m_next(nullptr),
		m_prev(nullptr),
		m_key(0),
		m_val(0)
	{}

	//�f�t�H���g�̃\�[�g�p�̔�r���Z�q�i�K�{�ł͂Ȃ��j
	inline bool operator<(const data_t& rhs) const
	{
		return m_key < rhs.m_key;
	}
	//�f�t�H���g�̐��`�^�񕪒T���p�̔�r���Z�q�i�K�{�ł͂Ȃ��j
	inline bool operator==(const int key) const
	{
		return m_key == key;
	}
#ifdef ENABLE_BINARY_SEARCH
	inline bool operator<(const int key) const
	{
		return m_key < key;
	}
#endif//ENABLE_BINARY_SEARCH
};
#ifdef ENABLE_BINARY_SEARCH
//��std::binary_search���g�p����ꍇ�́A���̃I�y���[�^���K�v
static bool operator<(const int key, const data_t& rhs)
{
	return key < rhs.m_key;
}
#endif//ENABLE_BINARY_SEARCH

//----------------------------------------
//�e�X�g�f�[�^�����m�[�h����p�N���X�iCRTP�j
struct ope_t : public linked_list::base_ope_t<ope_t, data_t>
{
	//�O�m�[�h���擾
	inline static const node_type* getPrev(const node_type& node){ return node.m_prev; }
	//�O�m�[�h��ύX
	inline static void setPrev(node_type& node, const node_type* prev){ node.m_prev = prev; }
	
	//���m�[�h���擾
	inline static const node_type* getNext(const node_type& node){ return node.m_next; }
	//���m�[�h��ύX
	inline static void setNext(node_type& node, const node_type* next){ node.m_next = next; }

	//���b�N�^
	//���f�t�H���g�idummy_shared_lock�j�̂܂܂Ƃ���
	//typedef shared_spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
};

//----------------------------------------
//�e�X�g�f�[�^����N���X�A�F�\�[�g�^�T�����@���f�t�H���g����ς���
struct another_ope_t : public ope_t
{
	//�\�[�g�p�v���f�B�P�[�g�֐��I�u�W�F�N�g
	//��m_val�����o�[����Ƀ\�[�g
	struct sort_predicate{
		inline bool operator()(const node_type& lhs, const node_type& rhs) const
		{
			return lhs.m_val < rhs.m_val;
		}
	};

	//���`�T���p�v���f�B�P�[�g�֐��I�u�W�F�N�g
	//��m_val�����o�[��T��
	struct find_predicate{
		inline bool operator()(const node_type& lhs, const int rhs) const
		{
			return lhs.m_val == rhs;
		}
	};

#ifdef ENABLE_BINARY_SEARCH
	//�񕪒T���p��r�֐��I�u�W�F�N�g
	//��m_val�����o�[���r
	struct search_comparison{
		inline int operator()(const node_type& lhs, const int rhs) const
		{
			return rhs - lhs.m_val;
		}
	};
#endif//ENABLE_BINARY_SEARCH
};

//----------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//--------------------
	//�e�X�g�@�F��{���W�b�N�e�X�g
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for linked_list::container(User defined type)]\n");

		//�o�����A�����X�g�R���e�i����
		typedef linked_list::container<ope_t> container_t;
		container_t con;

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("size=%d\n", con.size());
			printf("list=");
			if (con.empty())
			{
				printf("(empty)\n");
				return;
			}
			for (auto& data : con)
			{
				printf(" [%d:%d]", data.m_key, data.m_val);
			}
			printf("\n");
		};

		//�f�[�^���t���ɕ\��
		auto printReverse = [&con]()
		{
			printf("size=%d\n", con.size());
			printf("list(reverse)=");
			if (con.empty())
			{
				printf("(empty)\n");
				return;
			}
			std::for_each(con.rbegin(), con.rend(),
				[](data_t& data)
				{
					printf(" [%d:%d]", data.m_key, data.m_val);
				}
			);
			printf("\n");
		};

		//�����ɘA���v�b�V��(1)
		auto continuous_push_back = [&con](const int num)
		{
			printf("\n");
			printf("[push_back * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				const int key = i;
				const int val = 100 + i;
				printf("push_back(%d:%d) ... ", key, val);
				data_t* data = new data_t(key, val);
				if (con.push_back(*data))
					printf("OK\n");
				else
				{
					delete data;
					printf("NG!\n");
				}
			}
		};
		continuous_push_back(10);
		printAll();//�S���\��
		//printReverse();//�S���t���\��

		//�擪����A���|�b�v(1)
		auto continuous_pop_front = [&con](const int num)
		{
			printf("\n");
			printf("[pop_front * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				printf("pop_front() ... ");
				data_t* data = con.pop_front();
				if (data)
				{
					printf("OK [%d:%d]\n", data->m_key, data->m_val);
					delete data;
				}
				else
					printf("NG!\n");
			}
		};
		continuous_pop_front(5);
		printAll();//�S���\��
		//printReverse();//�S���t���\��

		//�����ɘA���v�b�V��(2)
		continuous_push_back(20);
		printAll();//�S���\��
		//printReverse();//�S���t���\��

		//�擪����A���|�b�v(2)
		continuous_pop_front(25);
		printAll();//�S���\��
		//printReverse();//�S���t���\��

		//�擪�ɘA���v�b�V��(1)
		auto continuous_push_front = [&con](const int num)
		{
			printf("\n");
			printf("[push_front * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				const int key = 1000 + i;
				const int val = 100 + i;
				printf("push_front(%d:%d) ... ", key, val);
				data_t* data = new data_t(key, val);
				if (con.push_front(*data))
					printf("OK\n");
				else
				{
					delete data;
					printf("NG!\n");
				}
			}
		};
		continuous_push_front(10);
		printAll();//�S���\��
		//printReverse();//�S���t���\��

		//��������A���|�b�v(1)
		auto continuous_pop_back = [&con](const int num)
		{
			printf("\n");
			printf("[pop_back * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				printf("pop_back() ... ");
				data_t* data = con.pop_back();
				if (data)
				{
					printf("OK [%d:%d]\n", data->m_key, data->m_val);
					delete data;
				}
				else
					printf("NG!\n");
			}
		};
		continuous_pop_back(5);
		printAll();//�S���\��
		//printReverse();//�S���t���\��

		//�擪�ɘA���v�b�V��(2)
		continuous_push_front(20);
		printAll();//�S���\��
		//printReverse();//�S���t���\��

		//��������A���|�b�v(2)
		continuous_pop_back(25);
		printAll();//�S���\��
		//printReverse();//�S���t���\��

		//�f�[�^�o�^�Fpush_back()���\�b�h
		printf("\n");
		printf("[push_back(1)]\n");
		auto push_back = [&con](const int key, const int val)
		{
			data_t* data = new data_t(key, val);
			con.push_back(*data);
		};
		push_back(5, 101);
		push_back(8, 102);
		push_back(3, 103);
		push_back(1, 104);
		push_back(7, 105);
		push_back(4, 106);
		push_back(13, 107);
		push_back(10, 108);
		push_back(5, 109);
		
		//�f�[�^��\��
		printAll();

		//�f�[�^���t���ɕ\��
		printReverse();

		//�\�\�g
		printf("\n");
		printf("[sort]\n");
		con.sort();//�ʏ�\�[�g
		//con.stable_sort();//����\�[�g
		printAll();//�S���\��

		//�t���Ƀ\�[�g ���J�X�^���v���f�B�P�[�g�֐����g�p
		printf("\n");
		printf("[custom sort]\n");
		auto reverse_pred = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key > rhs.m_key; };
		con.sort(reverse_pred);//�ʏ�\�[�g
		//con.stable_sort(reverse_pred);//����\�[�g
		printAll();//�S���\��

	#if 0
		{
			printf("\n");
			printf("constructor\n");
			container_t::iterator ite = con.begin();
			container_t::reverse_iterator rite = con.rbegin();
			container_t::iterator ite_end = con.end();
			container_t::reverse_iterator rite_end = con.rend();
			container_t::iterator ite2 = con.rbegin();
			container_t::reverse_iterator rite2 = con.begin();
			container_t::iterator ite2_end = con.rend();
			container_t::reverse_iterator rite2_end = con.end();
			if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
			printf("copy operator\n");
			ite = con.begin();
			rite = con.rbegin();
			ite_end = con.end();
			rite_end = con.rend();
			ite2 = con.rbegin();
			rite2 = con.begin();
			ite2_end = con.rend();
			rite2_end = con.end();
			if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
			for (int i = 0; i <= 3; ++i)
			{
				printf("[%d]\n", i);
				ite = ite[i];
				rite = rite[i];
				ite_end = ite_end[i];
				rite_end = rite_end[i];
				ite2 = ite2[i];
				rite2 = rite2[i];
				ite2_end = ite2_end[i];
				rite2_end = rite2_end[i];
				if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
				if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
				if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
				if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
				if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
				if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
				if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
				if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
			}
			printf("+= 3\n");
			ite += 3;
			rite += 3;
			ite_end += 3;
			rite_end += 3;
			ite2 += 3;
			rite2 += 3;
			ite2_end += 3;
			rite2_end += 3;
			if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
			printf("-= 3\n");
			ite -= 3;
			rite -= 3;
			ite_end -= 3;
			rite_end -= 3;
			ite2 -= 3;
			rite2 -= 3;
			ite2_end -= 3;
			rite2_end -= 3;
			if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
		}
	#endif

		//���`�T��
		printf("\n");
		printf("[find]\n");
		printAll();//�S���\��
		auto find = [&con](const int key)
		{
			printf("find_value(key=%d)=", key);
			auto ite = con.find_value(key);//���`�T��
			//auto ite = std::find(con.begin(), con.end(), key);//���`�T��(STL��)
			if (ite.isExist())
			{
				printf(" [%d:%d]", ite->m_key, ite->m_val);
				++ite;
				if (ite.isExist())
					printf(" next=[%d:%d]", ite->m_key, ite->m_val);
			}
			else
				printf("(not found)");
			printf("\n");
		};
		find(5);
		find(6);
		find(7);

	#ifdef ENABLE_BINARY_SEARCH
		//�񕪒T���i�\�[�g�O�j
		printf("\n");
		printf("[binary search(before sort)]\n");
		printAll();//�S���\��
		auto binary_search = [&con](const int key)
		{
			printf("binary_search_value(key=%d)=", key);
			auto ite = con.binary_search_value(key);//�񕪒T��
			if (ite.isExist())
			{
			//if (std::binary_search(con.begin(), con.end(), key))//�񕪒T��(STL��)
			//{
			//	auto ite = std::lower_bound(con.begin(), con.end(), key);
				printf(" [%d:%d]", ite->m_key, ite->m_val);
				--ite;
				if (ite.isExist())
					printf(" prev=[%d:%d]", ite->m_key, ite->m_val);
			}
			else
				printf("(not found)");
			printf("\n");
		};
		binary_search(5);
		binary_search(6);
		binary_search(7);

		//�񕪒T���i�\�[�g��j
		printf("\n");
		printf("[binary search(after sort)]\n");
		con.sort();//�\�[�g�ςݏ�Ԃɂ���
		printAll();//�S���\��
		binary_search(5);
		binary_search(6);
		binary_search(7);
	#endif//ENABLE_BINARY_SEARCH

	#if 0
		con.sort(reverse_pred);//�ʏ�\�[�g
		printAll();//�S���\��
		con.sort();//�ʏ�\�[�g
		printAll();//�S���\��
		con.stable_sort(reverse_pred);//����\�[�g
		printAll();//�S���\��
		con.stable_sort();//����\�[�g
		printAll();//�S���\��
		find(1);
		find(2);
		find(3);
		binary_search(1);
		binary_search(2);
		binary_search(3);
	#endif

		//�폜�P�F�폜�m�[�h�Ŏw��
		printf("\n");
		printf("[remove]\n");
		{
			auto ite = con.begin();
			ite += 2;
			data_t* del = con.remove(*ite);//�O����3�ڂ̃m�[�h���폜
			if (del)
				delete del;
			printAll();//�S���\��
		}

		//�폜�Q�F�C�e���[�^�Ŏw��
		printf("\n");
		printf("[erase(1)]\n");
		{
			auto ite = con.end();
			ite -= 4;
			data_t* del = con.erase(ite);//��납��4�ڂ̈ʒu�̃m�[�h���폜
			if (del)
				delete del;
			printAll();//�S���\��
		}

		//�폜�R�F�C�e���[�^�͈̔͂Ŏw��
		printf("\n");
		printf("[erase(2)]\n");
		{
			auto start = con.end();
			start -= 4;
			auto end = start;
			end += 2;
			const data_t* del = con.erase(start, end);//��납��4�ڂ̈ʒu����2�̃m�[�h���폜
			while (del)
			{
				const data_t* next = del->m_next;
				delete del;
				del = next;
			}
			printAll();//�S���\��
		}

		//�폜�S�F�C�e���[�^�͈̔͂Ŏw��i�����܂ō폜�j
		printf("\n");
		printf("[erase(3)]\n");
		{
			auto start = con.end();
			start -= 2;
			auto end = con.end();
			const data_t* del = con.erase(start, end);//��납��2�ڂ̈ʒu���疖���܂ł̃m�[�h���폜
			while (del)
			{
				const data_t* next = del->m_next;
				delete del;
				del = next;
			}
			printAll();//�S���\��
		}

		//�}���P�Finsert()���\�b�h
		printf("\n");
		printf("[insert]\n");
		{
			auto ite = con.begin();
			++ite;
			data_t* data = new data_t(99, 999);
			con.insert(ite, *data);//�擪����2�ڂ̈ʒu�ɑ}��
			printAll();//�S���\��
		}

		//�}���Q�Finsert_before()���\�b�h
		printf("\n");
		printf("[insert_before]\n");
		{
			auto ite = con.begin();
			ite += 3;
			data_t* data = new data_t(88, 888);
			con.insert_before(ite, *data);//�擪����4�ڂ̈ʒu�̑O�ɑ}��
			printAll();//�S���\��
		}

		//�N���A
		printf("\n");
		printf("[clear]\n");
		{
			const data_t* del = con.clear();
			while (del)
			{
				const data_t* next = del->m_next;
				delete del;
				del = next;
			}
			printAll();//�S���\��
			//printReverse();//�S���t���\��
		}
	}

	//--------------------
	//�e�X�g�A�F�\�[�g�A�T���̐ݒ��ς���
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for linked_list::container(User defined type with custom operator type)]\n");

		//�o�����A�����X�g�R���e�i����
		typedef linked_list::container<another_ope_t> container_t;
		container_t con;

		//�f�[�^�o�^�P�Fpush_back()���\�b�h
		printf("\n");
		printf("[push_back]\n");
		auto push_back = [&con](const int key, const int val)
		{
			data_t* data = new data_t(key, val);
			con.push_back(*data);
		};
		push_back(1, 105);
		push_back(1, 108);
		push_back(2, 103);
		push_back(2, 101);
		push_back(3, 107);
		push_back(3, 104);
		push_back(4, 113);
		push_back(4, 111);
		push_back(5, 105);
		push_back(5, 106);

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("size=%d\n", con.size());
			printf("list=");
			if (con.empty())
			{
				printf("(empty)\n");
				return;
			}
			for (auto& data : con)
			{
				printf(" [%d:%d]", data.m_key, data.m_val);
			}
			printf("\n");
		};
		printAll();

		//�\�\�g
		printf("\n");
		printf("[sort]\n");
		con.sort();//�ʏ�\�[�g
		//con.stable_sort();//����\�[�g
		printAll();//�S���\��

		//���`�T��
		printf("\n");
		printf("[find]\n");
		auto find = [&con](const int value)
		{
			printf("find_value(value=%d)=", value);
			auto ite = con.find_value(value);//���`�T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		find(101);
		find(110);
		find(103);

	#ifdef ENABLE_BINARY_SEARCH
		//�񕪒T��
		printf("\n");
		printf("[binary search]\n");
		auto binary_search = [&con](const int value)
		{
			printf("binary_search_value(value=%d)=", value);
			auto ite = con.binary_search_value(value);//�񕪒T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		binary_search(101);
		binary_search(110);
		binary_search(103);
	#endif//ENABLE_BINARY_SEARCH

		//�J�X�^���\�[�g
		{
			printf("\n");
			printf("[sort with custom predicate]\n");
			auto predicate = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key < rhs.m_key ? true : lhs.m_key == rhs.m_key ? lhs.m_val > rhs.m_val : false; };
			con.sort(predicate);//�ʏ�\�[�g
			//con.stable_sort(reverse_pred);//����\�[�g
			printAll();//�S���\��
		}

		//�J�X�^�����`�T��(1)
		printf("\n");
		printf("[find with custom predicate(1)]\n");
		auto custom_find1 = [&con](const int key, const int value)
		{
			printf("find(key=%d, value=%d)=", key, value);
			auto predicate = [&key, &value](const data_t& lhs) -> bool { return lhs.m_key == key && lhs.m_val == value; };
			auto ite = con.find(predicate);//���`�T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_find1(2, 101);
		custom_find1(2, 102);
		custom_find1(2, 103);

	#ifdef ENABLE_BINARY_SEARCH
		//�J�X�^���񕪒T��(1)
		printf("\n");
		printf("[binary search with custom comparison(1)]\n");
		auto custom_binary_search1 = [&con](const int key, const int value)
		{
			printf("binary_search_value(key=%d, value=%d)=", key, value);
			auto comparison = [&key, &value](const data_t& lhs) -> int { return key == lhs.m_key ? lhs.m_val - value : key > lhs.m_key ? 1 : -1; };
			auto ite = con.binary_search(comparison);//�񕪒T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_binary_search1(2, 101);
		custom_binary_search1(2, 102);
		custom_binary_search1(2, 103);
	#endif//ENABLE_BINARY_SEARCH

		//�J�X�^�����`�T��(2)
		printf("\n");
		printf("[find with custom predicate(2)]\n");
		auto custom_find2 = [&con](const int key)
		{
			printf("find(key=%d)=", key);
			auto predicate = [](const data_t& lhs, const int key) -> bool { return lhs.m_key == key; };
			auto ite = con.find_value(key, predicate);//���`�T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_find2(2);
		custom_find2(7);
		custom_find2(3);

	#ifdef ENABLE_BINARY_SEARCH
		//�J�X�^���񕪒T��(2)
		printf("\n");
		printf("[binary search with custom comparison(2)]\n");
		auto custom_binary_search2 = [&con](const int key)
		{
			printf("binary_search_value(key=%d)=", key);
			auto comparison = [](const data_t& lhs, const int key) -> int { return key - lhs.m_key; };
			auto ite = con.binary_search_value(key, comparison);//�񕪒T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_binary_search2(2);
		custom_binary_search2(7);
		custom_binary_search2(3);
	#endif//ENABLE_BINARY_SEARCH
	}

	//--------------------
	//�e�X�g�B�F��ʓo�^�e�X�g
	{
		//�o�ߎ��Ԃ�\��
		auto printElapsedTime = [](const std::chrono::system_clock::time_point& prev_time, const bool is_show) -> std::chrono::system_clock::time_point
		{
			//�ŏI�o�ߎ��ԕ\��
			const auto now_time = std::chrono::system_clock::now();
			const auto duration = now_time - prev_time;
			const double elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()) / 1000000000.;
			if (is_show)
				printf("*elapsed_time=%.9llf sec\n", elapsed_time);
			return now_time;
		};

		{
			printf("--------------------------------------------------------------------------------\n");
			printf("[Test for performance linked_list]\n");

			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//�f�[�^��������
			printf("\n");
			printf("[create container]\n");
			typedef linked_list::container<ope_t> container_t;
			container_t* con = new container_t;//�R���e�i����
			prev_time = printElapsedTime(prev_time, true);

			//�f�[�^��o�^
			printf("\n");
			printf("[push_back() * %d]\n", TEST_DATA_NUM);
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					data_t* data = new data_t(i, 10000000 + i);
					con->push_back(*data);
					++num;
				}
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//�C�e���[�^(1)
			printf("\n");
			printf("[iterator(1)]\n");
			{
				printf_detail("size=%d\n", con->size());
				printf_detail("list=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				for (const data_t& value : *con)
				{
					printf_detail(" [%d:%d]", value.m_key, value.m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_SORT_TEST
			//�t���\�[�g
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			con->sort(reverse_sort);
			assert(con->is_ordered(reverse_sort));
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_SORT_TEST

			//�C�e���[�^(2)
			printf("\n");
			printf("[iterator(2)]\n");
			{
				printf_detail("size=%d\n", con->size());
				printf_detail("list=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				forEach(*con, [&num](const data_t& value)
					{
						printf_detail(" [%d:%d]", value.m_key, value.m_val);
						++num;
					}
				);
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_SORT_TEST
			//�����\�[�g
			printf("\n");
			printf("[sort]\n");
			con->sort();
			assert(con->is_ordered());
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_SORT_TEST

			//���o�[�X�C�e���[�^
			printf("\n");
			printf("[reverse_iterator]\n");
			{
				printf_detail("size=%d\n", con->size());
				printf_detail("list=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				reverseForEach(*con, [&num](const data_t& value)
					{
						printf_detail(" [%d:%d]", value.m_key, value.m_val);
						++num;
					}
				);
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_SORT_TEST
		#ifdef ENABLE_STABLE_SORT
			//�t������\�[�g
			printf("\n");
			printf("[reverse stable sort]\n");
			con->stable_sort(reverse_sort);
			assert(con->is_ordered(reverse_sort));
			prev_time = printElapsedTime(prev_time, true);

			//��������\�[�g
			printf("\n");
			printf("[stable sort]\n");
			con->stable_sort();
			assert(con->is_ordered());
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_STABLE_SORT
		#endif//ENABLE_SORT_TEST

			//���`�T��
			printf("\n");
			printf("[find_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += TEST_DATA_FIND_STEP)
				{
					container_t::iterator ite = std::move(con->find_value(i));
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_BINARY_SEARCH
			//�񕪒T��
			printf("\n");
			printf("[binary_search_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += TEST_DATA_FIND_STEP)
				{
					container_t::iterator ite = std::move(con->binary_search_value(i));
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_BINARY_SEARCH

			//�f�[�^��j��
			printf("\n");
			printf("[delete container]\n");
			{
				const data_t* data = con->clear();
				while (data)
				{
					const data_t* next = data->m_next;
					delete data;
					data = next;
				}
			}
			delete con;//�R���e�i��j��
			con = nullptr;
			prev_time = printElapsedTime(prev_time, true);

			//������
			printf("\n");
			printf("[finish]\n");
			printElapsedTime(begin_time, true);
		}

		{
			printf("--------------------------------------------------------------------------------\n");
			printf("[Test for performance std::list]\n");

			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//�f�[�^��������
			printf("\n");
			printf("[create container]\n");
			typedef std::list<data_t> container_t;
			container_t* con = new container_t();//std::list�R���e�i�𐶐�
			prev_time = printElapsedTime(prev_time, true);

			//�f�[�^��o�^
			printf("\n");
			printf("[push_back() * %d]\n", TEST_DATA_NUM);
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					data_t value(i, 10000000 + i);
					con->push_back(std::move(value));
					++num;
				}
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//�C�e���[�^(1)
			printf("\n");
			printf("[iterator(1)]\n");
			{
				printf_detail("size=%d, max_size=%d\n", con->size(), con->max_size());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				for (const data_t& value : *con)
				{
					printf_detail(" [%d:%d]", value.m_key, value.m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_SORT_TEST
			//�t���\�[�g
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			con->sort(reverse_sort);
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_SORT_TEST

			//�C�e���[�^(2)
			printf("\n");
			printf("[iterator(2)]\n");
			{
				printf_detail("size=%d, max_size=%d\n", con->size(), con->max_size());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				std::for_each(con->begin(), con->end(), [&num](const data_t& value)
					{
						printf_detail(" [%d:%d]", value.m_key, value.m_val);
						++num;
					}
				);
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_SORT_TEST
			//�����\�[�g
			printf("\n");
			printf("[sort]\n");
			con->sort();
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_SORT_TEST

			//���o�[�X�C�e���[�^
			printf("\n");
			printf("[reverse_iterator]\n");
			{
				printf_detail("size=%d, max_size=%d\n", con->size(), con->max_size());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				std::for_each(con->rbegin(), con->rend(), [&num](const data_t& value)
					{
						printf_detail(" [%d:%d]", value.m_key, value.m_val);
						++num;
					}
				);
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_SORT_TEST
		#ifdef ENABLE_STABLE_SORT
			//�t���\�[�g�@������\�[�g�̑���
			printf("\n");
			printf("[reverse (stable) sort]\n");
			con->sort(reverse_sort);
			prev_time = printElapsedTime(prev_time, true);

			//�����\�[�g�@������\�[�g�̑���
			printf("\n");
			printf("[(stable) sort]\n");
			con->sort();
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_STABLE_SORT
		#endif//ENABLE_SORT_TEST

			//���`�T��
			printf("\n");
			printf("[find_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += TEST_DATA_FIND_STEP)
				{
					container_t::iterator ite = std::find(con->begin(), con->end(), i);
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_BINARY_SEARCH
			//�񕪒T��
			printf("\n");
			printf("[binary_search_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += TEST_DATA_FIND_STEP)
				{
					container_t::iterator ite = std::lower_bound(con->begin(), con->end(), i);
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_BINARY_SEARCH

			//�f�[�^��j��
			printf("\n");
			printf("[delete container]\n");
			delete con;//std::list�R���e�i��j��
			con = nullptr;
			prev_time = printElapsedTime(prev_time, true);

			//������
			printf("\n");
			printf("[finish]\n");
			printElapsedTime(begin_time, true);
		}
	}

	printf("\n");
	printf("- end -\n");

	return EXIT_SUCCESS;
}

// End of file
