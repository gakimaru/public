//--------------------------------------------------------------------------------
//���I�z��e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
static const int TEST_DATA_NUM = 10;//��ʓo�^�e�X�g�f�[�^�̓o�^��
//static const int TEST_DATA_NUM = 10000000;//��ʓo�^�e�X�g�f�[�^�̓o�^��

#define PRINT_TEST_DATA_DETAIL//�e�X�g�f�[�^�̏ڍ׃^��\������ꍇ�́A���̃}�N����L��������
//#define TEST_DATA_WATCH_CONSTRUCTOR//�R���X�g���N�^�^�f�X�g���N�^�^������Z�q�̓�����m�F����ꍇ�A���̃}�N����L��������

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
//�T���p�W���v���f�B�P�[�g�֐��I�u�W�F�N�g�Feqal_to
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
//�T���p�W����r�֐��I�u�W�F�N�g�Fcompare_to
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

//----------------------------------------
//��r�\�[�g�����I�[�o�[���[�h�֐��p�}�N��
//���v���f�B�P�[�g�֐��w���
#define sortFuncSetByUserPredicate(func_name) \
	template<class T, std::size_t N, class PREDICATE> \
	inline std::size_t func_name(T(&array)[N], PREDICATE predicate) \
	{ \
		return func_name(array, N, predicate); \
	} \
	template<class T, class PREDICATE> \
	inline std::size_t func_name(T* begin, T* end, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(begin, size, predicate); \
	} \
	template<class ITERATOR, class PREDICATE> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(&begin[0], size, predicate); \
	} \
	template<class CONTAINER, class PREDICATE> \
	inline std::size_t func_name(CONTAINER& con, PREDICATE predicate) \
	{ \
		std::size_t size = con.size(); \
		return size == 0 ? 0 : func_name(&(con.at(0)), size, predicate); \
	}
//���W���v���f�B�P�[�g�֐��g�p��
#define sortFuncSetByDefaultPredicate(func_name) \
	template<class T> \
	inline std::size_t func_name(T* array, const std::size_t size) \
	{ \
		return func_name(array, size, less<T>()); \
	} \
	template<class T, std::size_t N> \
	inline std::size_t func_name(T(&array)[N]) \
	{ \
		return func_name(array, less<T>()); \
	} \
	template<class T> \
	inline std::size_t func_name(T* begin, T* end) \
	{ \
		return func_name(begin, end, less<T>()); \
	} \
	template<class ITERATOR> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end) \
	{ \
		return func_name(begin, end, less<typename ITERATOR::value_type>()); \
	} \
	template<class CONTAINER> \
	inline std::size_t func_name(CONTAINER& con) \
	{ \
		return func_name(con, less<typename CONTAINER::value_type>()); \
	}
#define sortFuncSet(func_name) \
	sortFuncSetByUserPredicate(func_name) \
	sortFuncSetByDefaultPredicate(func_name)

//----------------------------------------
//���r�\�[�g�����I�[�o�[���[�h�֐��p�}�N��
//���L�[�擾�p�֐��I�u�W�F�N�g�w���
#define distributedSortFuncSetByUserFunctor(func_name) \
	template<class T, std::size_t N, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(T(&array)[N], GET_KEY_FUNCTOR get_key_functor) \
	{ \
		return func_name(array, N, get_key_functor); \
	} \
	template<class T, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(T* begin, T* end, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(begin, size, get_key_functor); \
	} \
	template<class ITERATOR, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(&begin[0], size, get_key_functor); \
	} \
	template<class CONTAINER, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(CONTAINER& con, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		std::size_t size = con.size(); \
		return size == 0 ? 0 : func_name(&(con.at(0)), size, get_key_functor); \
	}
#define distributedSortFuncSet(func_name) \
	distributedSortFuncSetByUserFunctor(func_name)

//----------------------------------------
//�T�������I�[�o�[���[�h�֐��p�}�N��
#define searchFuncSetByUserFunc(func_name) \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T* array, const std::size_t size, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(const_cast<T*>(array), size, predicate_or_comparison); \
	} \
	template<class T, std::size_t N, class PREDICATE_OR_COMPARISON> \
	inline T* func_name(T(&array)[N], PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(array, N, predicate_or_comparison); \
	} \
	template<class T, std::size_t N, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T(&array)[N], PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(const_cast<T*>(array), N, predicate_or_comparison); \
	} \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline T* func_name(T* begin, T* end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(begin, size, predicate_or_comparison); \
	} \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T* begin, const T* end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, predicate_or_comparison); \
	} \
	template<class ITERATOR, class PREDICATE_OR_COMPARISON> \
	inline typename ITERATOR::value_type* func_name(ITERATOR& begin, ITERATOR& end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(&begin[0], size, predicate_or_comparison); \
	} \
	template<class ITERATOR, class PREDICATE_OR_COMPARISON> \
	inline const typename ITERATOR::value_type* func_name(const ITERATOR& begin, const ITERATOR& end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, predicate_or_comparison); \
	} \
	template<class CONTAINER, class PREDICATE_OR_COMPARISON> \
	inline typename CONTAINER::value_type* func_name(CONTAINER& con, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = con.size(); \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, predicate_or_comparison); \
	} \
	template<class CONTAINER, class PREDICATE_OR_COMPARISON> \
	inline const typename CONTAINER::value_type* func_name(const CONTAINER& con, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = con.size(); \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, predicate_or_comparison); \
	}
//���T���l�w��ŁF�v���f�B�P�[�g�֐��ƒl�Ŕ�r
#define searchFuncSetPredicateAndValue(func_name) \
	template<class T, typename V, class PREDICATE> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(array, size, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _equal); \
	} \
	template<class T, std::size_t N, typename V, class PREDICATE> \
	inline T* func_name##Value(T(&array)[N], const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(array, N, _equal); \
	} \
	template<class T, std::size_t N, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T(&array)[N], const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline T* func_name##Value(T* begin, T* end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _equal); \
	} \
	template<class ITERATOR, typename V, class PREDICATE> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const typename ITERATOR::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _equal); \
	} \
	template<class ITERATOR, typename V, class PREDICATE> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const typename ITERATOR::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _equal); \
	} \
	template<class CONTAINER, typename V, class PREDICATE> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value, &predicate](const typename CONTAINER::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _equal); \
	} \
	template<class CONTAINER, typename V, class PREDICATE> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value, &predicate](const typename CONTAINER::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _equal); \
	}
//���T���l�w��ŁF�W���̃v���f�B�P�[�g�֐��ƒl�Ŕ�r
#define searchFuncSetByDefaultPredicateAndValue(func_name) \
	template<class T, typename V> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value) \
	{ \
		auto _equal = [&value](T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(array, size, _equal); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _equal); \
	} \
	template<class T, std::size_t N, typename V> \
	inline T* func_name##Value(T(&array)[N], const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(array, N, _equal); \
	} \
	template<class T, std::size_t N, typename V> \
	inline const T* func_name##Value(const T(&array)[N], const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _equal); \
	} \
	template<class T, typename V> \
	inline T* func_name##Value(T* begin, T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _equal); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _equal); \
	} \
	template<class ITERATOR, typename V> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const typename ITERATOR::value_type& val1) -> bool { return equal_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _equal); \
	} \
	template<class ITERATOR, typename V> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const typename ITERATOR::value_type& val1) -> bool { return equal_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _equal); \
	} \
	template<class CONTAINER, typename V> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value](const typename CONTAINER::value_type& val1) -> bool { return equal_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _equal); \
	} \
	template<class CONTAINER, typename V> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value](const typename CONTAINER::value_type& val1) -> bool { return equal_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _equal); \
	}
#define searchFuncSetByPredicate(func_name) \
	searchFuncSetByUserFunc(func_name) \
	searchFuncSetPredicateAndValue(func_name) \
	searchFuncSetByDefaultPredicateAndValue(func_name)
//���T���l�w��ŁF��r�֐��ƒl�Ŕ�r
#define searchFuncSetByComparisonAndValue(func_name) \
	template<class T, typename V, class COMPARISON> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](T& val1) -> int { return comparison(val1, value); }; \
		return func_name(array, size, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _comparison); \
	} \
	template<class T, std::size_t N, typename V, class COMPARISON> \
	inline T* func_name##Value(T(&array)[N], const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(array, N, _comparison); \
	} \
	template<class T, std::size_t N, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T(&array)[N], const V &value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline T* func_name##Value(T* begin, T* end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _comparison); \
	} \
	template<class ITERATOR, typename V, class COMPARISON> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const typename ITERATOR::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _comparison); \
	} \
	template<class ITERATOR, typename V, class COMPARISON> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const typename ITERATOR::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _comparison); \
	} \
	template<class CONTAINER, typename V, class COMPARISON> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value, &comparison](const typename CONTAINER::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _comparison); \
	} \
	template<class CONTAINER, typename V, class COMPARISON> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value, &comparison](const typename CONTAINER::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _comparison); \
	}
//���T���l�w��ŁF�W����r�֐��ƒl�Ŕ�r
#define searchFuncSetByDefaultComparisonAndValue(func_name) \
	template<class T, typename V> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value) \
	{ \
		auto _comparison = [&value](T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(array, size, _comparison); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _comparison); \
	} \
	template<class T, std::size_t N, typename V> \
	inline T* func_name##Value(T(&array)[N], const V& value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(array, N, _comparison); \
	} \
	template<class T, std::size_t N, typename V> \
	inline const T* func_name##Value(const T(&array)[N], const V &value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _comparison); \
	} \
	template<class T, typename V> \
	inline T* func_name##Value(T* begin, T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _comparison); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _comparison); \
	} \
	template<class ITERATOR, typename V> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const typename ITERATOR::value_type& val1) -> int { return compare_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _comparison); \
	} \
	template<class ITERATOR, typename V> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const typename ITERATOR::value_type& val1) -> int { return compare_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _comparison); \
	} \
	template<class CONTAINER, typename V> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value](const typename CONTAINER::value_type& val1) -> int { return compare_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _comparison); \
	} \
	template<class CONTAINER, typename V> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value](const typename CONTAINER::value_type& val1) -> int { return compare_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _comparison); \
	}
#define searchFuncSetByComparison(func_name) \
	searchFuncSetByUserFunc(func_name) \
	searchFuncSetByComparisonAndValue(func_name) \
	searchFuncSetByDefaultComparisonAndValue(func_name)

//----------------------------------------
//�����Ԋm�F
template<class T, class PREDICATE>
inline std::size_t calcUnordered(const T* array, const std::size_t size, PREDICATE predicate)
{
	std::size_t unordered = 0;
	const T* prev = array;
	const T* now = prev + 1;
	for (std::size_t i = 1; i < size; ++i, ++now, ++prev)
	{
		if (predicate(*now, *prev))
			++unordered;
	}
	return unordered;
}
sortFuncSet(calcUnordered);

//----------------------------------------
//�f�[�^�̓���ւ�
template<class T>
struct _swapArithmetic{
	inline static void exec(T& val1, T& val2)
	{
		T tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapArithmetic<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		T* tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapObjects{
	inline static void exec(T& val1, T& val2)
	{
	#if 1//���[�u�R���X�g���N�^�ƃ��[�u�I�y���[�^���g�p���ē���ւ��i#include <utility> �� std::swap() �Ɠ����j
		T tmp = std::move(val2);
		val2 = std::move(val1);
		val1 = std::move(tmp);
	#else//�R���X�g���N�^�^�I�y���[�^�̌Ăяo��������ĒP���ȃ������R�s�[
		char tmp[sizeof(T)];
		memcpy(tmp, &val2, sizeof(T));
		memcpy(&val2, &val1, sizeof(T));
		memcpy(&val1, tmp, sizeof(T));
	#endif
	}
};
template<class T>
struct _swapObjects<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		_swapArithmetic<T*>::exec(val1, val2);
	}
};
//�f�[�^����ւ��֐��i���ڎg�p����֐��j
template<class T>
inline void swapValues(T& val1, T& val2)
{
	std::conditional<std::is_arithmetic<T>::value,
		_swapArithmetic<T>,
		_swapObjects<T>
	>::type::exec(val1, val2);
}

//----------------------------------------
//�f�[�^�̃��[�e�[�V����
template<class T>
struct _rotateArithmetic{
	inline static void exec(T* val1, T* val2, int step)
	{
		T tmp;
		tmp = *val2;
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			*val2 = *val2_prev;
			val2 = val2_prev;
		}
		*val1 = tmp;
	}
};
template<class T>
struct _rotateArithmetic<T*>{
	inline static void exec(T** val1, T** val2, int step)
	{
		T* tmp;
		tmp = *val2;
		while (val1 != val2)
		{
			T** val2_prev = val2 - step;
			*val2 = *val2_prev;
			val2 = val2_prev;
		}
		*val1 = tmp;
	}
};
template<class T>
struct _rotateObjects{
	inline static void exec(T* val1, T* val2, int step)
	{
	#if 1//���[�u�R���X�g���N�^�ƃ��[�u�I�y���[�^���g�p���ē���ւ�
		T tmp = std::move(*val2);
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			*val2 = std::move(*val2_prev);
			val2 = val2_prev;
		}
		*val1 = std::move(tmp);
	#else//�R���X�g���N�^�^�I�y���[�^�̌Ăяo��������ĒP���ȃ������R�s�[
		char tmp[sizeof(T)];
		memcpy(tmp, val2, sizeof(T));
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			memcpy(val2, val2_prev, sizeof(T));
			val2 = val2_prev;
		}
		memcpy(val1, tmp, sizeof(T));
	#endif
	}
};
template<class T>
struct _rotateObjects<T*>{
	inline static void exec(T** val1, T** val2, int step)
	{
		_rotateArithmetic<T*>::exec(val1, val2, step);
	}
};
//�f�[�^���[�e�[�V�����֐��i���ڎg�p����֐��j
template<class T>
inline void rotateValues(T* val1, T* val2, int step)
{
	std::conditional<std::is_arithmetic<T>::value,
		_rotateArithmetic<T>,
		_rotateObjects<T>
	>::type::exec(val1, val2, step);
}

//========================================
//�\�[�g�A���S���Y�����ށF�}���\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�}���\�[�g
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(n)
//�E���όv�Z���ԁFO(n^2)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
//----------------------------------------
template<class T, class PREDICATE>
std::size_t insertionSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	const T* end = array + size;
	T* now = array;
	T* next = now + 1;
	while (next < end)
	{
		if (predicate(*next, *now))
		{
			T* min = now;
			T* prev = now - 1;
			while (prev >= array)
			{
				if (predicate(*next, *prev))
					min = prev;
				else
					break;
				--prev;
			}
			rotateValues(min, next, 1);
			++swapped_count;
		}
		++now;
		++next;
	}
	return swapped_count;
}
sortFuncSet(insertionSort);

//----------------------------------------
//�A���S���Y���F�V�F���\�[�g
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(n)
//�E���όv�Z���ԁFO(n log^2 n) or O(n^3/2)
//�E�ň��v�Z���ԁFO(n log^2 n)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
//----------------------------------------
template<class T, class PREDICATE>
std::size_t shellSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	const T* end = array + size;
	const std::size_t h_max = size / 3;
	std::size_t h = 1;
	while (h <= h_max)
		h = 3 * h + 1;
	while (h > 0)
	{
		T* now = array;
		T* next = now + h;
		while (next < end)
		{
			if (predicate(*next, *now))
			{
				T* min = now;
				T* prev = now - h;
				while (prev >= array)
				{
					if (predicate(*next, *prev))
						min = prev;
					else
						break;
					prev -= h;
				}
				rotateValues(min, next, h);
				++swapped_count;
			}
			++now;
			++next;
		}
		h = (h - 1) / 3;
	}
	return swapped_count;
}
sortFuncSet(shellSort);

//========================================
//�\�[�g�A���S���Y�����ށF�����\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�C���g���\�[�g
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(n log n)
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n log n)
//�E�������g�p�ʁFO(n log n) �����[�v�����ł� O(32*2)
//�E���萫�F�@�@�@�~
//----------------------------------------
template<class T, class PREDICATE>
std::size_t _introSort(T* array, const std::size_t size, PREDICATE predicate)
{
	int depth_max = 0;//�q�[�v�\�[�g�ɐ؂�ւ���ċA�i�X�^�b�N�j�̐[��
	for (std::size_t size_tmp = size; size_tmp > 1; size_tmp >>= 1, ++depth_max);
	//--------------------
	//�N�C�b�N�\�[�g�F�X�^�b�N������
	//���ċA�����ł͏ȗ�
	static const std::size_t SIZE_THRESHOLD = 16;//32;//�}���\�[�g�ɐ؂�ւ��錏��
	std::size_t swapped_count = 0;
	struct stack_t
	{
		T* array;
		std::size_t size;
		int depth;
	};
	static const int STACK_DEPTH_MAX = 32 * 2;
	stack_t stack[STACK_DEPTH_MAX];
	//�ŏ��̔z����X�^�b�N�Ƀv�b�V��
	stack_t* stack_p = &stack[0];
	stack_p->array = array;
	stack_p->size = size;
	stack_p->depth = depth_max;
	int stack_curr = 1;//�X�^�b�N�ʒu
	while (stack_curr > 0)
	{
		//�z����X�^�b�N����擾
		stack_p = &stack[--stack_curr];
		T* _array = stack_p->array;
		const size_t _size = stack_p->size;
		const int _depth = stack_p->depth;
		//�z��͈̔͏��
		const T* term = _array + _size;
		T* begin = _array;
		T* end = _array + _size - 1;
		//��������
		const T* mid = _array + (_size >> 1);
		const T* pivot =
			predicate(*begin, *mid) ?
			predicate(*mid, *end) ?
		mid :
			predicate(*end, *begin) ?
		begin :
		  end :
			  predicate(*end, *mid) ?
		  mid :
			  predicate(*begin, *end) ?
		  begin :
				end;
		//�������̔z��Ǝ��ȏ�̔z��ɓ�
		while (true)
		{
			while (predicate(*begin, *pivot))
				++begin;
			while (predicate(*pivot, *end))
				--end;
			if (begin >= end)
				break;
			swapValues(*begin, *end);
			pivot = pivot == begin ? end : pivot == end ? begin : pivot;//���̈ʒu�����i���̈ʒu������ւ�邽�߁j
			++swapped_count;
			++begin;
			--end;
		}
		//recursive = 0 : �������̔z����v�b�V��
		//            1 : ���ȏ�̔z����v�b�V��
		for (int recursive = 0; recursive < 2; ++recursive)
		{
			T* new_array = recursive == 0 ? _array : end + 1;
			const std::size_t new_size = recursive == 0 ? begin - _array : term - end - 1;
			const int new_depth = _depth - 1;
			if (new_size >= 1)
			{
				if (new_size < SIZE_THRESHOLD)
				{
					//swapped_count += insertionSort(new_array, new_size, predicate);//�y�{���̏����z�}���\�[�g�ɐ؂�ւ�
					//swapped_count += combSort(new_array, new_size, predicate);//�y���ǁz�R���\�[�g�ɐ؂�ւ�
					swapped_count += shellSort(new_array, new_size, predicate);//�y���ǁz�V�F���\�[�g�ɐ؂�ւ�
				}
				else if (new_depth == 0)
				{
					//swapped_count += heapSort(new_array, new_size, predicate);//�y�{���̏����z�q�[�v�\�[�g�ɐ؂�ւ�
					//swapped_count += combSort(new_array, new_size, predicate);//�y���ǁz�R���\�[�g�ɐ؂�ւ�
					swapped_count += shellSort(new_array, new_size, predicate);//�y���ǁz�V�F���\�[�g�ɐ؂�ւ�
				}
				else
				{
					//�ċA
					stack_p = &stack[stack_curr++];
					stack_p->array = new_array;
					stack_p->size = new_size;
					stack_p->depth = new_depth;
				}
			}
		}
	}
	return swapped_count;
}
template<class T, class PREDICATE>
inline std::size_t introSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	if (calcUnordered(array, size, predicate) == 0)
		return 0;
	return _introSort(array, size, predicate);
}
sortFuncSet(introSort);

//========================================
//�T���A���S���Y��
//========================================

//----------------------------------------
//�A���S���Y���F���`�T��
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(1)
//�E���όv�Z���ԁFO(n/2)
//�E�ň��v�Z���ԁFO(n)
//�E�T�����s���F  O(n)
//----------------------------------------
template<class T, class PREDICATE>
T* linearSearch(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size == 0)
		return nullptr;
	T* now = array;
	for (std::size_t i = 0; i < size; ++i, ++now)//�����T��
	{
		if (predicate(*now))//�T���L�[�ƈ�v������I��
			return now;
	}
	return nullptr;//�T�����s
}
searchFuncSetByPredicate(linearSearch);

//----------------------------------------
//�A���S���Y���F�񕪒T��
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(1)
//�E���όv�Z���ԁFO(log n)
//�E�ň��v�Z���ԁFO(log n)
//�E�T�����s���F  O(log n)
//----------------------------------------
template<class T, class COMPARISON>
T* binarySearch(T* array, const std::size_t size, COMPARISON comparison)
{
	if (!array || size == 0)
		return nullptr;
	std::size_t range = size;
	T* begin = array;
	while (true)
	{
		const std::size_t range_half = range / 2;//�T���͈͂̔����͈̔�
		T* mid = begin + range_half;//�T���͈͂̒��S�v�f
		const int comp = comparison(*mid);//���S�v�f��T���L�[�Ɣ�r
		if (comp == 0)//���S�v�f���T���L�[�ƈ�v
		{
			//�k���ăL�[�̊J�n�_��T��
			while (mid > array)
			{
				T* prev = mid - 1;
				if (comparison(*prev) != 0)
					break;
				mid = prev;
			}
			return mid;//�T���I��
		}
		if (range_half == 0)//�T���͈͂��c���Ă��Ȃ���ΒT�����s
			return nullptr;
		if (comp < 0)//�T���L�[�����S�v�f��菬���������ꍇ�A���ɒ��S���O�͈̔͂ɍi���ĒT������
			range = range_half;
		else//if (comp > 0)//�T���L�[�����S�v�f���傫�������ꍇ�A���ɒ��S����͈̔͂ɍi���ĒT������
		{
			begin = mid + 1;
			range -= (range_half + 1);
		}
	}
	return nullptr;
}
searchFuncSetByComparison(binarySearch);

//--------------------------------------------------------------------------------
//���I�z��
//--------------------------------------------------------------------------------
//�f�[�^�\���ƃA���S���Y��
//�y�����z
//�E�P���Ȉꎟ�z��ł���B
//�E�z��̗v�f���𒴂��Ȃ��͈͂ŁA�L���v�f���𓮓I�ɕω������ĊǗ�����B
//�E�L���v�f�̑����ɔ����A�R���X�g���N�^�^�f�X�g���N�^�̌Ăяo�����s���B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y�{�v���O�����ɂ���������v���z
//�E�A���S���Y���ƃf�[�^�{�̂𕪗������R���e�i�Ƃ���B
//�E�R���e�i���̂͗v�f�̎��̂��������������m�ۂ��s��Ȃ��B
//�E�R���X�g���N�^�Ŏ󂯂Ƃ����z��̎Q�Ƃ������B
//�ESTL�istd::vector�j�Ƃ̈Ⴂ�͉��L�̒ʂ�
//    - �Œ蒷�z��ł���B
//    - �ԍ��؃R���e�i�irb_tree�j�̎����ƍ��킹���\���ɂ��Ă���A
//�@�@  ����p�e���v���[�g�\���̂�p����B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y��̓I�Ȋ��p�̑z��z
//�E�R���e�i�N���X�Ɩ��֌W�̔z����A�ꎞ�I�ɃR���e�i�N���X�����đ��삷��B
//--------------------------------------------------------------------------------

#include <cstddef>//std::size_t, std::ptrdiff_t�p
//#include <cstdint>//std::intptr_t�p
#include <iterator>//std::iterator�p
#include <new>//�z�unew,�z�udelete�p
#include <algorithm>//C++11 std::move�p

namespace dynamic_array
{
	//--------------------
	//���I�z�񑀍�p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename VALUE_TYPE>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public dynamic_array::base_ope_t<�h���\����, �v�f�^>
	//	struct ope_t : public dynamic_array::base_ope_t<ope_t, data_t>
	//	{
	//		//�\�[�g�p�v���f�B�P�[�g�֐��I�u�W�F�N�g
	//		//���K�v�ɉ����Ď�������
	//		struct sort_predicate{
	//			inline bool operator()(const value_type& lhs, const value_type& rhs) const { return lhs.??? < rhs.???; }
	//		};
	//
	//		//�T���p�v���f�B�P�[�g�֐��I�u�W�F�N�g
	//		//���K�v�ɉ����Ď�������
	//		struct find_predicate{
	//			inline bool operator()(const value_type& lhs, const ???& rhs) const { return lhs.??? == rhs; }
	//		};
	//		
	//		//�T���p��r�֐��I�u�W�F�N�g
	//		//���K�v�ɉ����Ď�������
	//		struct search_comparison{
	//			inline int operator()(const value_type& lhs, const ???& rhs) const { return rhs - lhs.???; }
	//		};
	//		
	//		//���b�N�^ ���K�v�ɉ����Ē�`
	//		//�����b�N�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
	//		//�@�L���ȃ��b�N�^�ispin_lock�Ȃǁj�� lock_type �^�Ƃ��Ē�`����B
	//		typedef shared_spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
	//
	//		//�f�X�g���N�^�Ăяo�� ���K�v�ɉ����Ď���
	//		//���f�X�g���N�^�Ăяo����}���������ꍇ�Ȃǂɒ�`����B
	//		inline static void callDestructor(value_type* obj)
	//		{
	//			//�Ȃɂ����Ȃ�
	//		}
	//	};
	template<class OPE_TYPE, typename VALUE_TYPE>
	struct base_ope_t
	{
		//�^
		typedef OPE_TYPE ope_type;//�v�f����^
		typedef VALUE_TYPE value_type;//�v�f�^

		//���b�N�^
		typedef dummy_shared_lock lock_type;//���b�N�I�u�W�F�N�g�^
		//���f�t�H���g�̓_�~�[�̂��߁A��؃��b�N���䂵�Ȃ��B
		//�����b�N�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
		//�@base_ope_t�̔h���N���X�ɂāA�L���ȃ��b�N�^�ishared_spin_lock �Ȃǁj��
		//�@lock_type �^�Ƃ��čĒ�`����B

		//�f�X�g���N�^�Ăяo��
		inline static void callDestructor(value_type* obj){ obj->~VALUE_TYPE(); }
		//���f�X�g���N�^�̌Ăяo�����֎~�������ꍇ�A
		//�@base_ope_t�̔h���N���X�ɂāA�Ȃɂ����Ȃ�
		//�@callDestructor ���\�b�h���Ē�`����B

		//�\�[�g�p�v���f�B�P�[�g�֐��I�u�W�F�N�g
		//��true��lhs�̕����������i���я����������j
		struct sort_predicate{
			inline bool operator()(const value_type& lhs, const value_type& rhs) const { return less<value_type>()(lhs, rhs); }
		};

		//�T���p�v���f�B�P�[�g�֐��I�u�W�F�N�g
		//��true�ň�v�i�T�������j
		struct find_predicate{
			template<typename V>
			inline bool operator()(const value_type& lhs, const V& rhs) const { return equal_to<value_type>()(lhs, rhs); }
		};

		//�T���p��r�֐��I�u�W�F�N�g
		//��0�ň�v�i�T�������j�A1�ȏ��lhs�̕����傫���A-1�ȉ���rhs�̕����傫��
		struct search_comparison{
			template<typename V>
			inline int operator()(const value_type& lhs, const V& rhs) const { return compare_to<value_type>()(lhs, rhs); }
		};
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::value_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type; \
		typedef typename ope_type::lock_type lock_type;
	//----------------------------------------
	//�R���e�i�j�����̗v�f�̎����N���A����
	enum auto_clear_attr_t
	{
		NEVER_CLEAR,//�����N���A���Ȃ��i�f�t�H���g�j
		AUTO_CLEAR,//�����N���A���A�c���Ă���v�f�̃f�X�g���N�^���Ăяo��
	};
	//----------------------------------------
	//���I�z��R���e�i
	template<class OPE_TYPE>
	class container
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//�萔
		static const index_type INVALID_INDEX = 0xffffffffu;//�����ȃC���f�b�N�X
	public:
		//--------------------
		//�C�e���[�^�錾
		class iterator;
		class reverse_iterator;
		typedef const iterator const_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		//--------------------
		//�C�e���[�^
		class iterator : public std::iterator<std::random_access_iterator_tag, value_type>
		{
			friend class container;
			friend class reverse_iterator;
		public:
			//�L���X�g�I�y���[�^
			inline operator bool() const { return isExist(); }
			inline operator const value_type&() const { return *getValue(); }
			inline operator value_type&(){ return *getValue(); }
			inline operator const value_type*() const { return getValue(); }
			inline operator value_type*(){ return getValue(); }
		public:
			//�I�y���[�^
			inline const value_type& operator*() const { return *getValue(); }
			inline value_type& operator*(){ return *getValue(); }
			inline const_pointer operator->() const { return getValue(); }
			inline pointer operator->(){ return getValue(); }
			inline const_iterator operator[](const int index) const
			{
				iterator ite(*m_con, false);
				ite.update(index);
				return std::move(ite);
			}
			inline iterator operator[](const int index)
			{
				iterator ite(*m_con, false);
				ite.update(index);
				return std::move(ite);
			}
			//��r�I�y���[�^
			inline bool operator==(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index == rhs.index;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index != rhs.m_index;
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index > rhs.m_index;
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index >= rhs.m_index;
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index < rhs.m_index;
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index <= rhs.m_index;
			}
			//���Z�I�y���[�^
			inline const_iterator& operator++() const
			{
				addIndexAndUpdate(1);
				return *this;
			}
			inline const_iterator& operator--() const
			{
				addIndexAndUpdate(-1);
				return *this;
			}
			inline iterator& operator++()
			{
				addIndexAndUpdate(1);
				return *this;
			}
			inline iterator& operator--()
			{
				addIndexAndUpdate(-1);
				return *this;
			}
			inline const_iterator operator++(int) const
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			inline const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			inline iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			inline iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			inline const_iterator& operator+=(const int val) const
			{
				addIndexAndUpdate(val);
				return *this;
			}
			inline const_iterator& operator-=(const int val) const
			{
				addIndexAndUpdate(-val);
				return *this;
			}
			inline iterator& operator+=(const int val)
			{
				addIndexAndUpdate(val);
				return *this;
			}
			inline iterator& operator-=(const int val)
			{
				addIndexAndUpdate(-val);
				return *this;
			}
			inline const_iterator operator+(const int val) const
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			inline const_iterator operator-(const int val) const
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
			inline iterator operator+(const int val)
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			inline iterator operator-(const int val)
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
		public:
			//���[�u�I�y���[�^
			inline iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				m_value = rhs.m_value;
				return *this;
			}
			iterator& operator=(const_reverse_iterator&& rhs);
			//�R�s�[�I�y���[�^
			inline iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				m_value = rhs.m_value;
				return *this;
			}
			iterator& operator=(const_reverse_iterator& rhs);
		public:
			//�A�N�Z�b�T
			inline bool isExist() const { return m_index != INVALID_INDEX && m_index < m_con->m_size; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_index != INVALID_INDEX; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_index == m_con->m_size; }//�I�[���H
			inline index_type getIndex() const { return m_index; }//�C���f�b�N�X
			inline const value_type* getValue() const { return m_value; }//���݂̒l
			inline value_type* getValue(){ return m_value; }//���݂̒l
		private:
			//���\�b�h
			void update(const index_type index) const
			{
				//if (index == INVALID_INDEX || index < 0 || index > static_cast<index_type>(m_con->m_size))
				if (index > static_cast<index_type>(m_con->m_size))
				{
					m_index = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_index = index;
					m_value = const_cast<value_type*>(m_con->_ref_element(m_index));
				}
			}
			inline void addIndexAndUpdate(const int add) const
			{
				update(m_index + add);
			}
		public:
			//���[�u�R���X�g���N�^
			iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			iterator(const_reverse_iterator&& obj);
			//�R�s�[�R���X�g���N�^
			inline iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			iterator(const_reverse_iterator& obj);
			//�R���X�g���N�^
			inline iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				if (!is_end)
					update(0);//�擪�f�[�^
				else
					update(m_con->m_size);//�����f�[�^
			}
			inline iterator(const container& con, const index_type index) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				update(index);
			}
			inline iterator() :
				m_con(nullptr),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{}
			//�f�X�g���N�^
			inline ~iterator()
			{}
		protected:
			//�t�B�[���h
			const container* m_con;//�R���e�i
			mutable index_type m_index;//���݂̃C���f�b�N�X
			mutable value_type* m_value;//���݂̒l
		};
		//--------------------
		//���o�[�X�C�e���[�^
		//class reverse_iterator : public std::reverse_iterator<iterator>
		class reverse_iterator : public std::iterator<std::random_access_iterator_tag, value_type>
		{
			friend class container;
			friend class iterator;
		public:
			//�L���X�g�I�y���[�^
			inline operator bool() const { return isExist(); }
			inline operator const value_type&() const { return *getValue(); }
			inline operator value_type&(){ return *getValue(); }
			inline operator const value_type*() const { return getValue(); }
			inline operator value_type*(){ return getValue(); }
		public:
			//�I�y���[�^
			inline const value_type& operator*() const { return *getValue(); }
			inline value_type& operator*(){ return *getValue(); }
			inline const_pointer operator->() const { return getValue(); }
			inline pointer operator->(){ return getValue(); }
			inline const_reverse_iterator operator[](const int index) const
			{
				reverse_iterator ite(*m_con, false);
				ite.update(m_con->m_size - index);
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(*m_con, false);
				ite.update(m_con->m_size - index);
				return std::move(ite);
			}
		public:
			//��r�I�y���[�^
			inline bool operator==(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index == m_index;
			}
			inline bool operator!=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index != m_index;
			}
			inline bool operator>(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index > m_index;
			}
			inline bool operator>=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index >= m_index;
			}
			inline bool operator<(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index < m_index;
			}
			inline bool operator<=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index <= m_index;
			}
			//���Z�I�y���[�^
			inline const_reverse_iterator& operator++() const
			{
				addIndexAndUpdate(1);
				return *this;
			}
			inline const_reverse_iterator& operator--() const
			{
				addIndexAndUpdate(-1);
				return *this;
			}
			inline reverse_iterator& operator++()
			{
				addIndexAndUpdate(1);
				return *this;
			}
			inline reverse_iterator& operator--()
			{
				addIndexAndUpdate(-1);
				return *this;
			}
			inline const_reverse_iterator operator++(int) const
			{
				reverse_iterator ite(*this);
				++(*this);
				return ite;
			}
			inline const_reverse_iterator operator--(int) const
			{
				reverse_iterator ite(*this);
				--(*this);
				return ite;
			}
			inline reverse_iterator operator++(int)
			{
				reverse_iterator ite(*this);
				++(*this);
				return ite;
			}
			inline reverse_iterator operator--(int)
			{
				reverse_iterator ite(*this);
				--(*this);
				return ite;
			}
			inline const_reverse_iterator& operator+=(const int val) const
			{
				addIndexAndUpdate(val);
				return *this;
			}
			inline const_reverse_iterator& operator-=(const int val) const
			{
				addIndexAndUpdate(-val);
				return *this;
			}
			inline reverse_iterator& operator+=(const int val)
			{
				addIndexAndUpdate(val);
				return *this;
			}
			inline reverse_iterator& operator-=(const int val)
			{
				addIndexAndUpdate(-val);
				return *this;
			}
			inline const_reverse_iterator operator+(const int val) const
			{
				reverse_iterator ite(*this);
				ite += val;
				return ite;
			}
			inline const_reverse_iterator operator-(const int val) const
			{
				reverse_iterator ite(*this);
				ite -= val;
				return ite;
			}
			inline reverse_iterator operator+(const int val)
			{
				reverse_iterator ite(*this);
				ite += val;
				return ite;
			}
			inline reverse_iterator operator-(const int val)
			{
				reverse_iterator ite(*this);
				ite -= val;
				return ite;
			}
		public:
			//���[�u�I�y���[�^
			inline reverse_iterator& operator=(const_reverse_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				m_value = rhs.m_value;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				update(m_index);
				return *this;
			}
			//�R�s�[�I�y���[�^
			inline reverse_iterator& operator=(const_reverse_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				m_value = rhs.m_value;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				update(m_index);
				return *this;
			}
		public:
			//�A�N�Z�b�T
			inline bool isExist() const { return m_index != INVALID_INDEX && m_index > 0; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_index != INVALID_INDEX; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_index == 0; }//�I�[���H
			inline index_type getIndex() const { return m_index - 1; }//�C���f�b�N�X
			inline const value_type* getValue() const { return m_value; }//���݂̒l
			inline value_type* getValue(){ return m_value; }//���݂̒l
		private:
			//���\�b�h
			void update(const index_type index) const
			{
				//if (index == INVALID_INDEX || index < 0 || index > static_cast<index_type>(m_con->m_size))
				if (index > static_cast<index_type>(m_con->m_size))
				{
					m_index = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_index = index;
					m_value = const_cast<value_type*>(m_con->_ref_element(m_index)) - 1;
				}
			}
			inline void addIndexAndUpdate(const int add) const
			{
				update(m_index - add);
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
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			inline reverse_iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(nullptr)
			{
				update(obj.m_index);
			}
			//�R�s�[�R���X�g���N�^
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(nullptr)
			{
				update(m_index);
			}
			//�R���X�g���N�^
			inline reverse_iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				if (!is_end)
					update(m_con->m_size);//�����f�[�^
				else
					update(0);//�擪�f�[�^
			}
			inline reverse_iterator(const container& con, const index_type index) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				update(index);
			}
			inline reverse_iterator() :
				m_con(nullptr),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{}
			//�f�X�g���N�^
			inline ~reverse_iterator()
			{}
		protected:
			//�t�B�[���h
			const container* m_con;//�R���e�i
			mutable index_type m_index;//���݂̃C���f�b�N�X
			mutable value_type* m_value;//���݂̒l
		};
	public:
		//�A�N�Z�b�T
		inline const value_type* at(const int index) const { return ref_element(index); }
		inline value_type* at(const int index){ return ref_element(index); }
		inline const value_type* operator[](const int index) const { return ref_element(index); }
		inline value_type* operator[](const int index){ return ref_element(index); }
		auto_clear_attr_t getAutoClearAttr() const { return m_autoClearAttr; }//�R���e�i�j�����Ɏc���Ă���v�f�̎����N���A�������擾
		void setAutoClearAttr(const auto_clear_attr_t attr){ m_autoClearAttr = attr; }//�R���e�i�j�����Ɏc���Ă���v�f�̎����N���A������ύX
	public:
		//�L���X�g�I�y���[�^
		inline operator lock_type&(){ return m_lock; }//���L���b�N�I�u�W�F�N�g
		inline operator lock_type&() const { return m_lock; }//���L���b�N�I�u�W�F�N�g ��mutable
	public:
		//���\�b�h
		inline size_type max_size_real() const { return m_maxSizeReal; }//�ő�v�f���i���ۂ̍ő�v�f���j���擾
		inline size_type max_size() const { return m_maxSize; }//�ő�v�f�����擾
		inline size_type capacity() const { return m_maxSize; }//�ő�v�f�����擾
		inline size_type size() const { return m_size; }//�g�p���̗v�f�����擾
		inline size_type remain() const { return m_maxSize - m_size; }//�c��̗v�f�����擾
		inline bool empty() const { return m_size == 0; }//�󂩁H
		inline bool full() const { return m_size == m_maxSize; }//���t���H
	private:
		//���͈̓`�F�b�N�Ȃ�
		inline const value_type* _ref_element(const index_type index) const { return &m_array[index]; }//�v�f�Q��
		inline const value_type* _ref_front() const { return _ref_element(0); }//�擪�v�f�Q��
		inline const value_type* _ref_back() const { return _ref_element(m_size - 1); }//�����v�f�Q��
		inline const value_type* _ref_new() const { return _ref_element(m_size); }//�V�K�v�f�Q��
		inline value_type* _ref_element(const index_type index){ return &m_array[index]; }//�v�f�Q��
		inline value_type* _ref_front(){ return _ref_element(0); }//�擪�v�f�Q��
		inline value_type* _ref_back(){ return _ref_element(m_size - 1); }//�����v�f�Q��
		inline value_type* _ref_new(){ return _ref_element(m_size); }//�V�K�v�f�Q��
	public:
		//���͈̓`�F�b�N����
		//inline const value_type* ref_element(const index_type index) const { return index >= 0 && index < m_size ? _ref_element(index) : nullptr; }//�v�f�Q��
		inline const value_type* ref_element(const index_type index) const { return index < m_size ? _ref_element(index) : nullptr; }//�v�f�Q��
		inline const value_type* ref_front() const { return m_size == 0 ? nullptr : _ref_front(); }//�擪�v�f�Q��
		inline const value_type* ref_back() const { return m_size == 0 ? nullptr : _ref_back(); }//�����v�f�Q��
		inline const value_type* ref_new() const { return m_size == m_maxSize ? nullptr : _ref_new(); }//�V�K�v�f�Q��
		inline value_type* ref_element(const index_type index){ return  const_cast<value_type*>(const_cast<const container*>(this)->ref_element(index)); }//�v�f�Q��
		inline value_type* ref_front(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_front()); }//�擪�v�f�Q��
		inline value_type* ref_back(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_back()); }//�����v�f�Q��
		inline value_type* ref_new(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_new()); }//�V�K�v�f�Q��
	private:
		//inline index_type _adj_index(const index_type index) const { return index >= 0 && index < m_maxSize ? index : INVALID_INDEX; }//�C���f�b�N�X��͈͓��ɕ␳
		inline index_type _adj_index(const index_type index) const { return index < m_maxSize ? index : INVALID_INDEX; }//�C���f�b�N�X��͈͓��ɕ␳
		inline index_type _ref_index(const value_type* node) const{ return node - _ref_front(); }//�v�f���C���f�b�N�X�ɕϊ� ���͈̓`�F�b�N�Ȃ�
	public:
		inline index_type ref_index(const value_type* node) const{ return _adj_index(_ref_index(node)); }//�v�f���C���f�b�N�X�ɕϊ�
	public:
		inline const value_type* front() const { return ref_front(); }//�擪�v�f�Q��
		inline value_type* front(){ return ref_front(); }//�擪�v�f�Q��
		inline const value_type* back() const { return ref_back(); }//�����v�f�Q��
		inline value_type* back(){ return ref_back(); }//�����v�f�Q��
		//�C�e���[�^���擾
		//�������I�ȋ��L���b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
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
		//�@��A�̏����u���b�N�̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
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
	public:
		//�z��̍Ċ��蓖��
		//���R���e�i�������̃R���X�g���N�^�Ŕz����w��ł��Ȃ��������Ɏg�p����B
		//��������ԂŎg�p���̗v�f�����w�肷��i-1�őS�v�f���g�p���ɂ���j
		//���v�f�̏������͍s��Ȃ��i�K�v�Ȃ� size �� 0 ���w�肵�āA��� resize() ���Ăяo���j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		template<size_type N>
		inline void assign_array(value_type(&array)[N], const int size = 0)
		{
			assign_array(array, N, size);
		}
		//���|�C���^�Ɣz��v�f���w���
		void assign_array(value_type* array, const size_type max_size, const int size = 0)
		{
			if (m_array && m_autoClearAttr == AUTO_CLEAR)
				clear();//�N���A
			m_array = array;
			m_maxSizeReal = max_size;
			m_maxSize = max_size;
			m_size = size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size);
		}
		//��void�|�C���^�ƃo�b�t�@�T�C�Y���w���
		void assign_array(void* buff_ptr, const size_type buff_size, const int size = 0)
		{
			assign_array(static_cast<value_type*>(buff_ptr), buff_size / sizeof(value_type), size);
		}
		//�ő�v�f���̕ύX�i�V�����ő�v�f����Ԃ��j
		//�����O�ɔ����Ċg��E�k�����\
		//���g�p���̗v�f���ȉ��ɂ͂ł��Ȃ�
		//�����ۂ̍ő�v�f���ȏ�ɂ͂ł��Ȃ�
		//�����ۂ̔z��͈̔͂𒴂��Ȃ����Ƃ͕ۏ؂��Ȃ�
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		inline size_type reserve(const size_type max_size)
		{
			if (max_size < m_size)
				m_maxSize = m_size;
			else if (max_size > m_maxSizeReal)
				m_maxSize = m_maxSizeReal;
			else
				m_maxSize = max_size;
			return m_maxSize;
		}
		//�ő�v�f���̕ύX�i�V�����ő�v�f����Ԃ��j
		//�����O�ɔ����Ċg��E�k�����\
		//���g�p���̗v�f���ȉ��ɂ��ł���i�폜���ꂽ�v�f�̓f�X�g���N�^���Ăяo���j
		//�����ۂ̔z��͈̔͂𒴂��Ȃ����Ƃ͕ۏ؂��Ȃ�
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		size_type shrink(const size_type max_size)
		{
			if (max_size < m_size)
			{
				value_type* value = _ref_element(max_size);
				for (index_type index = max_size; index < m_size; ++index, ++value)
				{
					ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
					operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
				}
				m_size = max_size;
				m_maxSize = m_size;
			}
			else if (max_size > m_maxSizeReal)
				m_maxSize = m_maxSizeReal;
			else
				m_maxSize = max_size;
			return m_maxSize;
		}
		//�ő�v�f���̕ύX�i�V�����ő�v�f����Ԃ��j
		//�����ݎg�p���̃T�C�Y�ɍ��킹��
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		size_type shrink_to_fit()
		{
			m_maxSize = m_size;
			return m_maxSize;
		}
		//�g�p���̃T�C�Y��ύX�i�V�����T�C�Y��Ԃ��j
		//���V�����v�f�ɂ�new_value���Z�b�g���A�폜���ꂽ�v�f�̓f�X�g���N�^���Ăяo��
		//���ő�v�f���𒴂���T�C�Y�ɂ͂ł��Ȃ�
		//���w�萔�� -1 �Ȃ�ő�v�f���ɕύX
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		size_type resize(const int size, const value_type& new_value)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			if (_size > m_size)
			{
				value_type* value = _ref_element(m_size);
				for (index_type index = m_size; index < _size; ++index, ++value)
					*value = new_value;//�V�����l��������
			}
			else if (_size < m_size)
			{
				value_type* value = _ref_element(_size);
				for (index_type index = _size; index < m_size; ++index, ++value)
				{
					ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
					operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
				}
			}
			m_size = _size;
			return m_size;
		}
		//���R���X�g���N�^�Ăяo����
		template<typename... Tx>
		size_type resize(const int size, Tx... args)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			if (_size > m_size)
			{
				value_type* value = _ref_element(m_size);
				for (index_type index = m_size; index < _size; ++index, ++value)
					new(value)value_type(args...);//�R���X�g���N�^�Ăяo��
			}
			else if (_size < m_size)
			{
				value_type* value = _ref_element(size);
				for (index_type index = size; index < m_size; ++index, ++value)
				{
					ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
					operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
				}
			}
			m_size = _size;
			return m_size;
		}
		//�g�p���̃T�C�Y��ύX�i�V�����T�C�Y��Ԃ��j
		//���V�����l�̑�����폜���ꂽ�v�f�̃f�X�g���N�^�Ăяo�����s�킸�A
		//�@�g�p���̃T�C�Y������ύX����
		//���ő�v�f���𒴂���T�C�Y�ɂ͂ł��Ȃ�
		//���w�萔�� -1 �Ȃ�ő�v�f���ɕύX
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		size_type resize_silent(const int size)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			m_size = _size;
			return m_size;
		}
		//�擪����w�萔�̗v�f�Ƀf�[�^�����蓖�Ă�
		//��new_value�ŗv�f���㏑������
		//�������̗v�f���㏑������ۂ́A�R�s�[�I�y���[�^���g�p�i�f�X�g���N�^�͌Ăяo���Ȃ��j
		//���w�萔�� -1 �Ȃ�ő�f����Ώۂɂ���
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		size_type assign(const int size, const value_type& new_value)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			//{
			//	const size_type used_size = _size < m_size ? _size : m_size;
			//	value_type* value = _ref_front();
			//	for (index_type index = 0; index < used_size; ++index, ++value)
			//	{
			//		ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
			//		operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			//	}
			//}
			{
				value_type* value = _ref_front();
				for (index_type index = 0; index < _size; ++index, ++value)
					*value = new_value;//�f�[�^���㏑��
			}
			if(m_size < _size)
				m_size = _size;
			return m_size;
		}
		//���R���X�g���N�^�Ăяo����
		//�������̗v�f���㏑������ۂ́A��Ƀf�X�g���N�^���Ăяo��
		template<typename... Tx>
		size_type assign(const int size, Tx... args)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			{
				const size_type used_size = _size < m_size ? _size : m_size;
				value_type* value = _ref_front();
				for (index_type index = 0; index < used_size; ++index, ++value)
				{
					ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
					operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
				}
			}
			{
				value_type* value = _ref_front();
				for (index_type index = 0; index < _size; ++index, ++value)
					new(value)value_type(args...);//�R���X�g���N�^�Ăяo��
			}
			if (m_size < _size)
				m_size = _size;
			return m_size;
		}
		//�����ɗv�f��ǉ�
		//���I�u�W�F�N�g�n��
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ��Ӂi�����x���Ȃ�j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		inline value_type* push_back(const value_type&& src)//���[�u��
		{
			value_type* obj = ref_new();//�T�C�Y�`�F�b�N�܂�
			if (!obj)
				return nullptr;
			*obj = std::move(src);
			++m_size;
			return obj;
		}
		inline value_type* push_back(const value_type& src)//�R�s�[��
		{
			value_type* obj = ref_new();//�T�C�Y�`�F�b�N�܂�
			if (!obj)
				return nullptr;
			*obj = src;
			++m_size;
			return obj;
		}
		//�����ɗv�f��ǉ�
		//���p�����[�^�n��
		//���I�u�W�F�N�g�̃R���X�g���N�^���Ăяo�����
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		template<typename... Tx>
		value_type* push_back(Tx... args)
		{
			value_type* obj = ref_new();//�T�C�Y�`�F�b�N�܂�
			if (!obj)
				return nullptr;
			new(obj)value_type(args...);//�R���X�g���N�^�Ăяo��
			++m_size;
			return obj;
		}
		//�����̗v�f���폜
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo�����
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		bool pop_back()
		{
			if (m_size == 0)
				return false;
			value_type* value = const_cast<value_type*>(ref_back());
			ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
			operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			--m_size;
			return true;
		}
		//���I�u�W�F�N�g�̒l���󂯎��
		bool pop_back(value_type& value)
		{
			if (m_size == 0)
				return false;
			value_type* obj = const_cast<value_type*>(ref_back());
			value = std::move(*obj);//���[�u
			ope_type::callDestructor(obj);//�f�X�g���N�^�Ăяo��
			operator delete(obj, obj);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			--m_size;
			return true;
		}
	public:
		//�N���A
		//���f�X�g���N�^���Ăяo��
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		inline void clear()
		{
			if (m_size == 0)
				return;
			value_type* value = _ref_front();
			for (size_type i = 0; i < m_size; ++i, ++value)
			{
				ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
				operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			}
			m_size = 0;
		}
	private:
		//�v�f�̈ړ��i�����j
		void move_asc(const index_type dst_pos, const index_type src_pos, const size_type num)
		{
			value_type* dst = _ref_element(dst_pos);
			value_type* src = _ref_element(src_pos);
			for (size_type i = 0; i < num; ++i)
			{
				*dst = std::move(*src);
				++dst;
				++src;
			}
		}
		//�v�f�̈ړ��i�~���j
		void move_desc(const index_type dst_pos, const index_type src_pos, const size_type num)
		{
			value_type* dst = _ref_element(dst_pos + num - 1);
			value_type* src = _ref_element(src_pos + num - 1);
			for (size_type i = 0; i < num; ++i)
			{
				*dst = std::move(*src);
				--dst;
				--src;
			}
		}
	public:
		//�v�f�̑}��
		//��num�̑}���ɂ���čő�v�f���𒴂���ꍇ�́A�\�ȃT�C�Y�ɏk�����ĕԂ�
		//���}�������ʒu�i�擪�j�̃C�e���[�^��Ԃ�
		//���w�萔�� -1 �Ȃ�\�Ȍ���̐���}��
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		iterator insert(iterator pos, const int num, value_type& value)
		{
			if (pos.isNotEnabled() || num == 0 || m_size == m_maxSize)
			{
				iterator ite(*this, INVALID_INDEX);
				return std::move(ite);
			}
			index_type index = pos.getIndex();
			const size_type remain = m_maxSize - m_size;
			const size_type _num = num < 0 || static_cast<size_type>(num) > remain ? remain : static_cast<size_type>(num);
			//�ړ�
			move_desc(index + _num, index, _num);
			//�v�f���ύX
			m_size += _num;
			//�}��
			value_type* new_value = _ref_element(index);
			for (size_type i = 0; i < _num; ++i, ++new_value)
				*new_value = value;
			//�I��
			iterator now(*this, index);
			return std::move(now);
		}
		//���R���X�g���N�^�Ăяo����
		template<typename... Tx>
		iterator insert(iterator pos, const int num, Tx... args)
		{
			if (pos.isNotEnabled() || num == 0 || m_size == m_maxSize)
			{
				iterator ite(*this, INVALID_INDEX);
				return std::move(ite);
			}
			index_type index = pos.getIndex();
			const size_type remain = m_maxSize - m_size;
			const size_type _num = num < 0 || static_cast<size_type>(num) > remain ? remain : static_cast<size_type>(num);
			const size_type move_num = m_size - index;
			//�ړ�
			move_desc(index + _num, index, move_num);
			//�v�f���ύX
			m_size += _num;
			//�}��
			value_type* new_value = _ref_element(index);
			for (size_type i = 0; i < _num; ++i, ++new_value)
				new(new_value)value_type(args...);
			//�I��
			iterator now(*this, index);
			return std::move(now);
		}
	private:
		//�v�f�̍폜
		void _erase(const index_type index, const size_type num)
		{
			const size_type remain = m_maxSize - m_size;
			const size_type _num = num < 0 || num > remain ? remain : num;
			const size_type move_num = m_size - index;
			//�폜
			value_type* delete_value = _ref_element(index);
			for (size_type i = 0; i < _num; ++i, ++delete_value)
			{
				ope_type::callDestructor(delete_value);//�f�X�g���N�^�Ăяo��
				operator delete(delete_value, delete_value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			}
			//�ړ�
			move_asc(index, index + _num, move_num);
			//�v�f���ύX
			m_size -= _num;
		}
	public:
		//�v�f�̍폜
		//���f�X�g���N�^���Ăяo��
		//���폜���ꂽ����̗v�f�̃C�e���[�^��Ԃ�
		//���w�萔�� -1 �Ȃ�ȍ~�̑S�v�f���폜
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		iterator erase(iterator pos, const int num = 1)
		{
			if (pos.isNotExist() || num == 0 || m_size == 0)
			{
				iterator ite(*this, INVALID_INDEX);
				return std::move(ite);
			}
			const index_type index = pos.getIndex();
			//�폜
			_erase(index, num);
			//�I��
			iterator now(*this, index);
			return std::move(now);
		}
		//���͈͎w���
		iterator erase(iterator start, iterator end)
		{
			if (start.isNotExist() || end.isNotExist() || start >= end || m_size == 0)
			{
				iterator ite(*this, INVALID_INDEX);
				return std::move(ite);
			}
			index_type index = start.getIndex();
			index_type end_index = end.getIndex();
			const size_type num = end_index - index;
			//�폜
			_erase(index, num);
			//�I��
			iterator now(*this, index);
			return std::move(now);
		}
	public:
		//�\�[�g
		//���C���g���\�[�g���g�p
		//��ope_type::sort_predicate() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator<() �ɏ]���ĒT���j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		void sort()
		{
			introSort(_ref_front(), m_size, typename ope_type::sort_predicate());
		}
		//���v���f�B�P�[�g�֐��w���
		template<class PREDICATE>
		void sort(PREDICATE predicate)
		{
			introSort(_ref_front(), m_size, predicate);
		}
		//����\�[�g
		//���}���\�[�g���g�p
		//��ope_type::sort_predicate() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator<() �ɏ]���ĒT���j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		void stable_sort()
		{
			insertionSort(_ref_front(), m_size, typename ope_type::sort_predicate());
		}
		//���v���f�B�P�[�g�֐��w���
		template<class PREDICATE>
		void stable_sort(PREDICATE predicate)
		{
			insertionSort(_ref_front(), m_size, predicate);
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
			value_type* found = linearSearchValue(_ref_front(), m_size, value, typename ope_type::find_predicate());
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//����r�֐��{�l�w���
		template<typename V, class PREDICATE>
		iterator find_value(const V& value, PREDICATE predicate)
		{
			value_type* found = linearSearchValue(_ref_front(), m_size, value, predicate);
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//����r�֐��w���
		//���l�̎w��͊֐��Ɋ܂�ł����i�N���\�W����p����Ȃǂ���j
		template<class PREDICATE>
		iterator find(PREDICATE predicate)
		{
			value_type* found = linearSearch(_ref_front(), m_size, predicate);
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//�񕪒T��
		//���T���l�w���
		//��ope_type::search_comparison() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator==() �� operator<() �ɏ]���ĒT���j
		//�������I�ȋ��L���b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
		template<typename V>
		iterator binary_search_value(const V& value)
		{
			value_type* found = binarySearchValue(_ref_front(), m_size, value, typename ope_type::search_comparison());
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//����r�֐��{�l�w���
		template<typename V, class COMPARISON>
		iterator binary_search_value(const V& value, COMPARISON comparison)
		{
			value_type* found = binarySearchValue(_ref_front(), m_size, value, comparison);
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//����r�֐��w���
		//���l�̎w��͊֐��Ɋ܂�ł����i�N���\�W����p����Ȃǂ���j
		template<class COMPARISON>
		iterator binary_search(COMPARISON comparison)
		{
			value_type* found = binarySearch(_ref_front(), m_size, comparison);
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
	public:
		//�R���X�g���N�^
		//��������ԂŎg�p���̗v�f�����w�肷��i-1�őS�v�f���g�p���ɂ���j
		//���v�f�̏������͍s��Ȃ��i�K�v�Ȃ� size �� 0 ���w�肵�āA��� resize() ���Ăяo���j
		template<size_type N>
		container(value_type(&array)[N], const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(array),
			m_maxSizeReal(N),
			m_maxSize(N),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_autoClearAttr(auto_clear_attr)
		{}
		//���|�C���^�Ɣz��v�f���w���
		container(value_type* array, const size_type max_size, const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(array),
			m_maxSizeReal(max_size),
			m_maxSize(max_size),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_autoClearAttr(auto_clear_attr)
		{}
		//��void�|�C���^�ƃo�b�t�@�T�C�Y���w���
		container(void* buff_ptr, const size_type buff_size, const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(static_cast<value_type*>(buff_ptr)),
			m_maxSizeReal(buff_size / sizeof(value_type)),
			m_maxSize(m_maxSizeReal),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_autoClearAttr(auto_clear_attr)
		{}
		//�f�t�H���g�R���X�g���N�^
		container() :
			m_array(nullptr),
			m_maxSizeReal(0),
			m_maxSize(0),
			m_size(0),
			m_autoClearAttr(NEVER_CLEAR)
		{}
		//�f�X�g���N�^
		~container()
		{
			//�����N���A�������L���Ȃ�A�����N���A����
			if (m_array && m_autoClearAttr == AUTO_CLEAR)
				clear();
		}
	private:
		//�t�B�[���h
		value_type* m_array;//�z��̐擪
		size_type m_maxSizeReal;//���ہi�����j�̍ő�v�f��
		size_type m_maxSize;//�ő�v�f���i�ォ��ύX�\�ȃT�C�Y�j
		size_type m_size;//�g�p���̗v�f��
		auto_clear_attr_t m_autoClearAttr;//�R���e�i�j�����Ɏc���Ă���v�f�̎����N���A����
		mutable lock_type m_lock;//���b�N�I�u�W�F�N�g
	};
	//�C�e���[�^�̃��[�u�I�y���[�^
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator&& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator&& rhs)//VC++��OK
	{
		m_con = rhs.m_con;
		m_index = rhs.m_index;
		update(m_index);
		return *this;
	}
	//�C�e���[�^�̃R�s�[�I�y���[�^
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator& rhs)//VC++��OK
	{
		m_con = rhs.m_con;
		m_index = rhs.m_index;
		update(m_index);
		return *this;
	}
	//�C�e���[�^�̃��[�u�R���X�g���N�^
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator&& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator&& obj) ://VC++��OK
		m_con(obj.m_con),
		m_index(obj.m_index),
		m_value(nullptr)
	{
		update(m_index);
	}
	//�C�e���[�^�̃R�s�[�R���X�g���N�^
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator& obj) ://VC++��OK
		m_con(obj.m_con),
		m_index(obj.m_index),
		m_value(nullptr)
	{
		update(m_index);
	}
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace dynamic_array

//--------------------------------------------------------------------------------
//���I�z��e�X�g
//--------------------------------------------------------------------------------

#include <algorithm>//std::for_each�p
#include <vector>//std::vector�p�i��r�p�j

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

//----------------------------------------
//�e�X�g�f�[�^
struct data_t
{
	int m_key;//�L�[
	int m_val;//�f�[�^

	//�R���X�g���N�^
	data_t(const int key, const int val) :
		m_key(key),
		m_val(val)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d, %d)\n", key, val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	//�f�t�H���g�R���X�g���N�^
	data_t() :
		m_key(0),
		m_val(0)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor()\n");
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	//�f�X�g���N�^
	~data_t()
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::destructor(): key=%d, val=%d\n", m_key, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
#ifdef TEST_DATA_WATCH_CONSTRUCTOR
	//���[�u�I�y���[�^
	data_t& operator=(const data_t&& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::move_operator\n");
		return *this;
	}
	//�R�s�[�I�y���[�^
	data_t& operator=(const data_t& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::copy_operator\n");
		return *this;
	}
	//���[�u�R���X�g���N�^
	data_t(const data_t&& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::move_constructor\n");
	}
	//�R�s�[�R���X�g���N�^
	data_t(const data_t& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::copy_constructor\n");
	}
#endif//TEST_DATA_WATCH_CONSTRUCTOR
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
	inline bool operator<(const int key) const
	{
		return m_key < key;
	}
};
//----------------------------------------
//�e�X�g�f�[�^����N���X�@�F�f�t�H���g�̂܂܎g��
struct ope_t : public dynamic_array::base_ope_t<ope_t, data_t>{};
//----------------------------------------
//�e�X�g�f�[�^����N���X�A�F�\�[�g�^�T�����@���f�t�H���g����ς���
struct another_ope_t : public dynamic_array::base_ope_t<ope_t, data_t>
{
	//�\�[�g�p�v���f�B�P�[�g�֐��I�u�W�F�N�g
	//��m_val�����o�[����Ƀ\�[�g
	struct sort_predicate{
		inline bool operator()(const value_type& lhs, const value_type& rhs) const
		{
			return lhs.m_val < rhs.m_val;
		}
	};

	//���`�T���p�v���f�B�P�[�g�֐��I�u�W�F�N�g
	//��m_val�����o�[��T��
	struct find_predicate{
		inline bool operator()(const value_type& lhs, const int rhs) const
		{
			return lhs.m_val == rhs;
		}
	};

	//�񕪒T���p��r�֐��I�u�W�F�N�g
	//��m_val�����o�[���r
	struct search_comparison{
		inline int operator()(const value_type& lhs, const int rhs) const
		{
			return rhs - lhs.m_val;
		}
	};
	
	//�f�X�g���N�^�Ăяo�����֎~�������ꍇ�A
	//���̋�̃��\�b�h���`����B
	inline static void callDestructor(value_type* obj)
	{
		//�������Ȃ�
	}
};
//----------------------------------------
//�e�X�g�f�[�^����N���X�B�F���b�N��L��������
struct mt_ope_t : public dynamic_array::base_ope_t<mt_ope_t, data_t>
{
	//���b�N�^
	typedef shared_spin_lock lock_type;//���b�N�I�u�W�F�N�g���w��
};

//----------------------------------------
//�X���b�h�e�X�g�p�֐��̎Q��
template <class C>
extern void testThread(const char* container_type);

//----------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//--------------------
	//�e�X�g�@�F�v���~�e�B�u�^�̔z��������ꍇ
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(Primitive type)]\n");
		
		int arr[20];//�z��

		//int�^�p�̃f�[�^����N���X��`
		struct ope_t : public dynamic_array::base_ope_t<ope_t, int>{};

		//�R���e�i����
		//�������̔z���n���ē��I�z��R���e�i�Ƃ��Ĉ���
		dynamic_array::container<ope_t> con(arr);//�z��v�f���������擾

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array=");
			for (auto val : con)
				printf(" %d", val);
			printf("\n");
		};

		//�f�[�^���t���ɕ\��
		auto printReverse = [&con]()
		{
			printf("array(reverse)=");
			std::for_each(con.rbegin(), con.rend(),
				[](int val)
			{
				printf(" %d", val);
			}
			);
			printf("\n");
		};

		//�l��ǉ�
		printf("\n");
		printf("[push_back]\n");
		con.push_back(5);
		con.push_back(8);
		con.push_back(3);
		con.push_back(1);
		con.push_back(7);
		con.push_back(4);
		con.push_back(13);
		con.push_back(10);
		con.push_back(5);

		//�f�[�^��\��
		printAll();

		//�f�[�^���t���ɕ\��
		printReverse();

		//���T�C�Y�i�g��j
		printf("\n");
		printf("[resize(expand)]\n");
		con.resize(12, 1000);//12���Ɋg��
		printAll();//�S���\��

		//�\�\�g
		printf("\n");
		printf("[sort]\n");
		con.sort();//�����\�[�g
		//con.stable_sort();//����\�[�g
		printAll();//�S���\��

		//�t���Ƀ\�[�g ���J�X�^���v���f�B�P�[�g�֐����g�p
		printf("\n");
		printf("[custom sort]\n");
		auto reverse_pred = [](const int lhs, const int rhs) -> bool {return lhs > rhs; };
		con.sort(reverse_pred);//�����\�[�g
		//con.stable_sort(reverse_pred);//����\�[�g
		printAll();//�S���\��

		//�|�b�v(1)
		printf("\n");
		printf("[pop_back(1)]\n");
		{
			const int* val = con.back();//�����̒l���擾
			printf("back=%d\n", *val);
			con.pop_back();//�������폜
			printAll();//�S���\��
		}

		//�|�b�v(2)
		printf("\n");
		printf("[pop_back(2)]\n");
		{
			int pop_val;
			con.pop_back(pop_val);//�l�̃R�s�[���󂯎���Ė������폜
			printf("pop_back=[%d]\n", pop_val);
			printAll();//�S���\��
		}

		//����
		printf("\n");
		printf("[find]\n");
		printAll();//�S���\��
		auto find = [&con](const int val)
		{
			printf("find_value(%d)=", val);
			auto ite = con.find_value(val);//�T��
			if (ite.isExist())
			{
				printf("%d", *ite);
				++ite;
				if (ite.isExist())
					printf(" next=%d", *ite);
			}
			else
				printf("(not found)");
			printf("\n");
		};
		find(5);
		find(6);
		find(7);

		//�񕪒T���i�\�[�g�O�j
		printf("\n");
		printf("[binary search(before sort)]\n");
		printAll();//�S���\��
		auto binary_search = [&con](const int val)
		{
			printf("binary_search_value(%d)=", val);
			auto ite = con.binary_search_value(val);//�񕪒T��
			if (ite.isExist())
			{
				printf("%d", *ite);
				--ite;
				if (ite.isExist())
					printf(" prev=%d", *ite);
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

		//�폜�P�F�C�e���[�^�Ɛ��Ŏw��
		printf("\n");
		printf("[erase(1)]\n");
		{
			auto ite = con.end();
			ite -= 4;
			con.erase(ite, 2);//��납��4�ڂ̈ʒu����2���폜
			printAll();//�S���\��
		}

		//�폜�Q�F�C�e���[�^�͈̔͂Ŏw��
		printf("\n");
		printf("[erase(2)]\n");
		{
			auto start = con.end();
			start -= 4;
			auto end = start;
			end += 2;
			con.erase(start, end);//��납��4�ڂ̈ʒu����2���폜
			printAll();//�S���\��
		}

		//�}��
		printf("\n");
		printf("[insert]\n");
		{
			auto ite = con.begin();
			++ite;
			con.insert(ite, 5, 999);//�擪����2�ڂ̈ʒu��5���}��
			printAll();//�S���\��
		}

		//���T�C�Y�i�k���j
		printf("\n");
		printf("[resize(shrink)]\n");
		con.resize(5);//�v�f��=5�ɏk��
		printAll();//�S���\��

		//�ő�T�C�Y���k��
		printf("\n");
		printf("[shrink_to_fit]\n");
		con.shrink_to_fit();
		printAll();//�S���\��

		//�f�[�^���蓖��
		printf("\n");
		printf("[assign]\n");
		con.assign(-1, 0);//��-1�ōő�v�f���S���Ɋ��蓖��
		printAll();//�S���\��
	}

	//--------------------
	//�e�X�g�A�F���[�U�[��`�^�������ꍇ
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(User defined type)]\n");

		//�z��f�[�^
		data_t array[20];
		//�����̐錾���ƁA�f�t�H���g�R���X�g���N�^�ƃf�X�g���N�^���Ăяo�����_�ɒ���

		//���I�z��R���e�i����
		typedef dynamic_array::container<ope_t> container_t;
		container_t con(array);//���z��v�f���������擾
		//container_t con(&array[0], 10);//���v�f���𖾎��I�Ɏ󂯓n�����@
		//char buff[1024];
		//container_t con(buff, sizeof(buff), dynamic_array::AUTO_CLEAR);//�o�b�t�@�ƃo�b�t�@�T�C�Y���󂯓n�����@�{�R���e�i�j�����Ɏ����N���A�����ǉ�
		//                                                               //�i�R���e�i�̃f�X�g���N�^�ŁA�c���Ă���v�f�̃f�X�g���N�^���Ăяo���B�f�t�H���g�͎����N���A�Ȃ��j
		//container_t con;//������ԂŔz��̊��蓖�Ă������ɃR���e�i�𐶐�����ꍇ

		//�ォ��z������蓖�Ă�ꍇ�� assign_array() ���g�p����
		//container_t con;//�f�t�H���g�R���X�g���N�^ ���R���e�i�������ɔz������蓖�ĂȂ�
		//con.assign_array(array);//���z��v�f���������擾
		//con.assign_array(&array[0], 10);//���v�f���𖾎��I�Ɏ󂯓n�����@
		//char buff[1024];
		//con.assign_array(buff, sizeof(buff), dynamic_array::AUTO_CLEAR);//�o�b�t�@�ƃo�b�t�@�T�C�Y���󂯓n�����@�{�R���e�i�j�����Ɏ����N���A�����ǉ�
		//                                                                //�i�R���e�i�̃f�X�g���N�^�ŁA�c���Ă���v�f�̃f�X�g���N�^���Ăяo���B�f�t�H���g�͎����N���A�Ȃ��j

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array=");
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
			printf("array(reverse)=");
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

		//�f�[�^�o�^�P�Fpush_back()���\�b�h�{�R���X�g���N�^�p�����[�^�i�R���X�g���N�^�Ăяo�����s���j
		printf("\n");
		printf("[push_back(1)]\n");
		con.push_back(5, 101);
		con.push_back(8, 102);
		con.push_back(3, 103);

		//�f�[�^��\��
		printAll();

		//�f�[�^���t���ɕ\��
		printReverse();

		//�f�[�^�o�^�Q�Fpush_back()���\�b�h�{�I�u�W�F�N�g�i�I�u�W�F�N�g�̃R�s�[���s���j
		printf("\n");
		printf("[push_back(2)]\n");
		{ data_t obj(1, 104); con.push_back(obj); }//�R�s�[�Œǉ�
		{ data_t obj(7, 105); con.push_back(obj); }//�R�s�[�Œǉ�
		{ data_t obj(4, 106); con.push_back(obj); }//�R�s�[�Œǉ�
		con.push_back(data_t(13, 107));//���[�u�i�E�Ӓl�j�Œǉ�
		con.push_back(data_t(10, 108));//���[�u�i�E�Ӓl�j�Œǉ�
		con.push_back(data_t(5, 109));//���[�u�i�E�Ӓl�j�Œǉ�
		printAll();//�S���\��

		//���T�C�Y�P�Fresize()���\�b�h�{�R���X�g���N�^�p�����[�^�i�R���X�g���N�^�Ăяo�����s���j
		printf("\n");
		printf("[resize(1)]\n");
		con.resize(12, 1000, 1000);//12���Ɋg��
		printAll();

		//���T�C�Y�Q�Fresize()���\�b�h�{�I�u�W�F�N�g�i�I�u�W�F�N�g�̃R�s�[���s���j
		printf("\n");
		printf("[resize(2)]\n");
		{
			data_t prototype(1001, 1001);//�R�s�[�p�̃I�u�W�F�N�g
			con.resize(15, prototype);//15���Ɋg��
		}
		printAll();

		//�\�\�g
		printf("\n");
		printf("[sort]\n");
		con.sort();//�����\�[�g
		//con.stable_sort();//����\�[�g
		printAll();//�S���\��

		//�t���Ƀ\�[�g ���J�X�^���v���f�B�P�[�g�֐����g�p
		printf("\n");
		printf("[custom sort]\n");
		auto reverse_pred = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key > rhs.m_key; };
		con.sort(reverse_pred);//�����\�[�g
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
			if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
			printf("copy operator\n");
			ite = con.begin();
			rite = con.rbegin();
			ite_end = con.end();
			rite_end = con.rend();
			ite2 = con.rbegin();
			rite2 = con.begin();
			ite2_end = con.rend();
			rite2_end = con.end();
			if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
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
				if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
				if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
				if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
				if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
				if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
				if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
				if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
				if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
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
			if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
			printf("-= 3\n");
			ite -= 3;
			rite -= 3;
			ite_end -= 3;
			rite_end -= 3;
			ite2 -= 3;
			rite2 -= 3;
			ite2_end -= 3;
			rite2_end -= 3;
			if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
		}
	#endif

		//�|�b�v(1)
		printf("\n");
		printf("[pop_back(1)]\n");
		{
			const data_t* val = con.back();//�����̒l���擾
			printf("back=[%d:%d]\n", val->m_key, val->m_val);
			con.pop_back();//�������폜
			printAll();//�S���\��
		}

		//�|�b�v(2)
		printf("\n");
		printf("[pop_back(2)]\n");
		{
			data_t pop_val;
			con.pop_back(pop_val);//�l�̃R�s�[���󂯎���Ė������폜
			printf("pop_back=[%d:%d]\n", pop_val.m_key, pop_val.m_val);
			printAll();//�S���\��
		}

		//����
		printf("\n");
		printf("[find]\n");
		printAll();//�S���\��
		auto find = [&con](const int key)
		{
			printf("find_value(key=%d)=", key);
			auto ite = con.find_value(key);//�T��
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

		//�폜�P�F�C�e���[�^�ƍ폜���Ŏw��
		printf("\n");
		printf("[erase(1)]\n");
		{
			auto ite = con.end();
			ite -= 4;
			con.erase(ite, 2);//��납��4�ڂ̈ʒu����2���폜
			printAll();//�S���\��
		}

		//�폜�Q�F�C�e���[�^�͈̔͂Ŏw��
		printf("\n");
		printf("[erase(2)]\n");
		{
			auto start = con.end();
			start -= 4;
			auto end = start;
			end += 2;
			con.erase(start, end);//��납��4�ڂ̈ʒu����2���폜
			printAll();//�S���\��
		}

		//�}���P�Finsert()���\�b�h�{�R���X�g���N�^�p�����[�^�i�R���X�g���N�^�Ăяo�����s���j
		printf("\n");
		printf("[insert(1)]\n");
		{
			auto ite = con.begin();
			++ite;
			con.insert(ite, 5, 99, 999);//�擪����2�ڂ̈ʒu��5���}��
			printAll();//�S���\��
		}

		//�}���Q�Finsert()���\�b�h�{�I�u�W�F�N�g�i�I�u�W�F�N�g�̃R�s�[���s���j
		printf("\n");
		printf("[insert(2)]\n");
		{
			auto ite = con.begin();
			ite += 10;
			data_t prototype(88, 888);//�R�s�[�p�̃I�u�W�F�N�g
			con.insert(ite, 2, prototype);//�擪����11�ڂ̈ʒu��2���}��
			printAll();//�S���\��
		}

		//���T�C�Y�i�k���j
		printf("\n");
		printf("[resize(shrink)]\n");
		con.resize(5);//�v�f��=5�ɏk��
		printAll();//�S���\��

		//�ő�T�C�Y���k��
		printf("\n");
		printf("[shrink_to_fit]\n");
		con.shrink_to_fit();
		printAll();//�S���\��

		//�f�[�^���蓖�ĂP�Fassign()���\�b�h�{�R���X�g���N�^�p�����[�^�i�R���X�g���N�^�Ăяo�����s���j
		printf("\n");
		printf("[assign(1)]\n");
		{
			con.assign(2, 0, 0);//�擪����2���Ɋ��蓖��
			printAll();//�S���\��
		}

		//�f�[�^���蓖�ĂQ�Fassign()���\�b�h�{�I�u�W�F�N�g�i�I�u�W�F�N�g�̃R�s�[���s���j
		printf("\n");
		printf("[assign(2)]\n");
		{
			data_t prototype(-1, 0);//�R�s�[�p�̃I�u�W�F�N�g
			con.assign(-1, prototype);//��-1�ōő�v�f���S���Ɋ��蓖��
			printAll();//�S���\��
		}
	}

	//--------------------
	//�e�X�g�B�F�\�[�g�A�T���̐ݒ��ς���
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(User defined type with custom operator type)]\n");

		//�z��f�[�^
		data_t array[20];

		//���I�z��R���e�i����
		typedef dynamic_array::container<another_ope_t> container_t;
		container_t con(array);

		//�R���e�i�̃C���X�^���X�������ɔz���n���Ȃ��ꍇ�́AsertArray() ���g�p����
		//container_t con;
		//con.assign_array(array);

		//�f�[�^�o�^�P�Fpush_back()���\�b�h�{�R���X�g���N�^�p�����[�^�i�R���X�g���N�^�Ăяo�����s���j
		printf("\n");
		printf("[push_back]\n");
		con.push_back(1, 105);
		con.push_back(1, 108);
		con.push_back(2, 103);
		con.push_back(2, 101);
		con.push_back(3, 107);
		con.push_back(3, 104);
		con.push_back(4, 113);
		con.push_back(4, 111);
		con.push_back(5, 105);
		con.push_back(5, 106);

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array=");
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
		con.sort();//�����\�[�g
		//con.stable_sort();//����\�[�g
		printAll();//�S���\��

		//����
		printf("\n");
		printf("[find]\n");
		auto find = [&con](const int value)
		{
			printf("find_value(value=%d)=", value);
			auto ite = con.find_value(value);//�T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		find(101);
		find(110);
		find(103);

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

		//�J�X�^���\�[�g
		{
			printf("\n");
			printf("[sort with custom predicate]\n");
			auto predicate = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key < rhs.m_key ? true : lhs.m_key == rhs.m_key ? lhs.m_val > rhs.m_val : false; };
			con.sort(predicate);//�����\�[�g
			//con.stable_sort(reverse_pred);//����\�[�g
			printAll();//�S���\��
		}

		//�J�X�^������(1)
		printf("\n");
		printf("[find with custom predicate(1)]\n");
		auto custom_find1 = [&con](const int key, const int value)
		{
			printf("find(key=%d, value=%d)=", key, value);
			auto predicate = [&key, &value](const data_t& lhs) -> bool { return lhs.m_key == key && lhs.m_val == value; };
			auto ite = con.find(predicate);//�T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_find1(2, 101);
		custom_find1(2, 102);
		custom_find1(2, 103);

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

		//�J�X�^������(2)
		printf("\n");
		printf("[find with custom predicate(2)]\n");
		auto custom_find2 = [&con](const int key)
		{
			printf("find(key=%d)=", key);
			auto predicate = [](const data_t& lhs, const int key) -> bool { return lhs.m_key == key; };
			auto ite = con.find_value(key, predicate);//�T��
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_find2(2);
		custom_find2(7);
		custom_find2(3);

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
	}

	//--------------------
	//�e�X�g�C�F�f�[�^�ݒ�ς݂̊����̔z�������
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(User defined type for existing data)]\n");

		//�f�[�^�ݒ�ς݂̊����̔z��
		data_t array[] = 
		{
			{ 6, 111 },
			{ 2, 103 },
			{ 2, 104 },
			{ 4, 107 },
			{ 3, 105 },
			{ 3, 106 },
			{ 1, 102 },
			{ 5, 109 },
			{ 1, 101 },
			{ 4, 108 },
			{ 5, 110 },
			{ 6, 112 },
		};

		//�ݒ�ς݂̃f�[�^���c�����܂܁A���I�z��R���e�i�̃f�[�^�Ƃ��Ċ��p
		dynamic_array::container<ope_t> con(array, -1);//�������Ŏg�p���̃f�[�^�T�C�Y���w��i-1�őS��j
		
		//�R���e�i�̃C���X�^���X�������ɔz���n���Ȃ��ꍇ�́AsertArray() ���g�p����
		//dynamic_array::container<ope_t> con;
		//con.assign_array(array, -1);//�������Ŏg�p���̃f�[�^�T�C�Y���w��i-1�őS��j

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array=");
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
		printf("\n");
		printf("[sort(before)]\n");
		printAll();

		//�\�\�g
		printf("\n");
		printf("[sort(after)]\n");
		//con.sort();//�����\�[�g
		con.stable_sort();//����\�[�g
		printAll();//�S���\��
	}

	//--------------------
	//�e�X�g�D�F���b�N������s��
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(User defined type for multi-thread)]\n");

		testThread<dynamic_array::container<ope_t> >("normal container");//���b�N�Ȃ��ł̃X���b�h
		testThread<dynamic_array::container<mt_ope_t> >("multi-thread container");//���b�N����ł̃X���b�h
	}

	//--------------------
	//�e�X�g�E�F��ʓo�^�e�X�g
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
			printf("[Test for performance dynamic_array]\n");
			
			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//�f�[�^��������
			printf("\n");
			printf("[create container & assign() * %d]\n", TEST_DATA_NUM);
			const std::size_t buff_size = sizeof(data_t)* TEST_DATA_NUM;
			char* buff = new char[buff_size];
			typedef dynamic_array::container<ope_t> container_t;
			container_t* con = new container_t(buff, buff_size, 0, dynamic_array::AUTO_CLEAR);//�R���e�i�����i�o�b�t�@�����蓖�āj
			con->assign(-1, 0, 0);//�S��������
			prev_time = printElapsedTime(prev_time, true);

			//�f�[�^���N���A
			printf("\n");
			printf("[clear() * %d]\n", TEST_DATA_NUM);
			con->clear();
			prev_time = printElapsedTime(prev_time, true);

			//�f�[�^��o�^
			printf("\n");
			printf("[push_back() * %d]\n", TEST_DATA_NUM);
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					con->push_back(i, 10000000 + i);
					++num;
				}
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//�t���\�[�g
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			con->sort(reverse_sort);
			prev_time = printElapsedTime(prev_time, true);

			//�����\�[�g
			printf("\n");
			printf("[sort]\n");
			con->sort();
			prev_time = printElapsedTime(prev_time, true);

			//�C�e���[�^
			printf("\n");
			printf("[iterator]\n");
			{
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

			//���o�[�X�C�e���[�^
			printf("\n");
			printf("[reverse_iterator]\n");
			{
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

			//���`�T��
			printf("\n");
			printf("[find_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += (TEST_DATA_NUM / 100 + 1))
				{
					container_t::iterator ite = std::move(con->find_value(i));
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//�񕪒T��
			printf("\n");
			printf("[binary_search_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					container_t::iterator ite = std::move(con->binary_search_value(i));
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//�f�[�^��j��
			printf("\n");
			printf("[delete container]\n");
			delete con;//�R���e�i��j��
			con = nullptr;
			delete buff;
			buff = nullptr;
			prev_time = printElapsedTime(prev_time, true);

			//������
			printf("\n");
			printf("[finish]\n");
			printElapsedTime(begin_time, true);
		}

		{
			printf("--------------------------------------------------------------------------------\n");
			printf("[Test for performance std::vector]\n");

			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//�f�[�^��������
			printf("\n");
			printf("[create container & assign() * %d]\n", TEST_DATA_NUM);
			typedef std::vector<data_t> container_t;
			container_t* con = new container_t();//std::vector�R���e�i�𐶐�
			con->reserve(TEST_DATA_NUM);
			{
				data_t prototype(0, 0);
				con->assign(TEST_DATA_NUM, prototype);
			}
			prev_time = printElapsedTime(prev_time, true);

			//�f�[�^���N���A
			printf("\n");
			printf("[clear() * %d]\n", TEST_DATA_NUM);
			con->clear();
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

			//�t���\�[�g
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			std::sort(con->begin(), con->end(), reverse_sort);
			prev_time = printElapsedTime(prev_time, true);

			//�����\�[�g
			printf("\n");
			printf("[sort]\n");
			std::sort(con->begin(), con->end());
			prev_time = printElapsedTime(prev_time, true);

			//�C�e���[�^
			printf("\n");
			printf("[iterator]\n");
			{
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

			//���o�[�X�C�e���[�^
			printf("\n");
			printf("[reverse_iterator]\n");
			{
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

			//���`�T��
			printf("\n");
			printf("[find_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += (TEST_DATA_NUM / 100 + 1))
				{
					container_t::iterator ite = std::find(con->begin(), con->end(), i);
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//�񕪒T��
			printf("\n");
			printf("[binary_search_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					container_t::iterator ite = std::lower_bound(con->begin(), con->end(), i);
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//�f�[�^��j��
			printf("\n");
			printf("[delete container]\n");
			delete con;//std::vector�R���e�i��j��
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

//--------------------
//�e�X�g�D�F���b�N������s��

#include <thread>//C++11 std::thread�p
#include <mutex>//C++11 std::mutex�p
#include <condition_variable>//C++11 std::condition_variable�p
#include <atomic>//C++11 std::atomic�p
#include <chrono>//C++11 std::chrono�p

template <class C>
void testThread(const char* container_type)
{
	typedef C container_t;//�e���v���[�g�p�����[�^�ŁA���b�N����R���e�i���A���b�N�Ȃ��R���e�i�̌^���󂯎��
	typedef typename container_t::lock_type lock_type;//���b�N����^

	printf("\n");
	printf("[%s]\n", container_type);
	
	//�z��f�[�^
	data_t array[100];

	//���I�z��R���e�i����
	container_t con(array);

	//�����ϐ�
	std::condition_variable cond;
	std::mutex mutex;
	std::atomic<bool> is_ready;
	std::atomic<int> start_count;
	is_ready.store(false);
	auto isReady = [&is_ready]() -> bool
	{
		return is_ready.load();
	};
	start_count.store(0);

	//�X���b�h
	auto test_thread = [&con, &mutex, &cond, &start_count, &isReady](const int key, const int value)
	{
		{
			std::unique_lock<std::mutex> lock(mutex);
			cond.wait(lock, isReady);
		}
		start_count.fetch_add(1);
		std::this_thread::sleep_for(std::chrono::microseconds(1));
		//�X�^�[�g
		{
			lock_guard<lock_type> lock(con);//���C�g�E���b�N�擾 ���R���e�i��n���ăX�R�[�v���b�N
			con.push_back(key, value);
		}
		{
			lock_guard<lock_type> lock(con);//���C�g�E���b�N�擾 ���R���e�i��n���ăX�R�[�v���b�N
			auto ite = con.find_value(key);
			std::this_thread::sleep_for(std::chrono::microseconds(1));
			con.erase(ite, 1);
		}
		{
			lock_guard<lock_type> lock(con);//���C�g�E���b�N�擾 ���R���e�i��n���ăX�R�[�v���b�N
			con.push_back(key, value + 10);
		}
	};

	static const int THREAD_NUM = 10;//�������s�X���b�h��
	{
		std::thread* th[THREAD_NUM];

		//�X���b�h����
		is_ready.store(false);
		start_count.store(0);
		{
			std::lock_guard<std::mutex> lock(mutex);
			for (int i = 0; i < THREAD_NUM; ++i)
				th[i] = new std::thread(test_thread, i, i);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

		//�X���b�h�J�n
		//�������ϐ����g�p���āA�S�X���b�h�̃^�C�~���O�𑵂��Ĉ�Ăɏ����J�n
		is_ready.store(true);
		while (true)
		{
			cond.notify_all();
			//std::this_thread::sleep_for(std::chrono::milliseconds(1));
			if (start_count.load() == THREAD_NUM)
				break;
		}

		//�z���\��
		auto print_data = [&con](const char* caption)
		{
			shared_lock_guard<lock_type> lock(con);//���[�h�E���b�N�擾 ���R���e�i��n���ăX�R�[�v���b�N
			printf("(%s)\n", caption);
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			std::this_thread::sleep_for(std::chrono::microseconds(1));
			printf("array=");
			if (con.empty())
			{
				printf("(empty)");
			}
			else
			{
				for (auto& data : con)
				{
					printf(" [%d:%d]", data.m_key, data.m_val);
				}
			}
			printf("\n");
		};
		print_data("before");

		//�X���b�h�I���҂�
		for (int i = 0; i < THREAD_NUM; ++i)
		{
			th[i]->join();
			delete th[i];
			th[i] = nullptr;
		}

		//�z���\��
		print_data("after");
	}
}

// End of file