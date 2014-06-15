//--------------------------------------------------------------------------------
//�����O�o�b�t�@�e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
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

//----------------------------------------
//�����Ԋm�F ���C�e���[�^�Ή���
template<class ITERATOR, class PREDICATE>
inline std::size_t iteratorCalcUnordered(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	std::size_t unordered = 0;
	ITERATOR prev = begin;
	ITERATOR now = begin;
	++now;
	for (;now != end; ++now, ++prev)
	{
		if (predicate(*now, *prev))
			++unordered;
	}
	return unordered;
}
iteratorSortFuncSet(iteratorCalcUnordered);

//----------------------------------------
//�f�[�^�̓���ւ� ���C�e���[�^�Ή���
template<class ITERATOR>
inline void iteratorSwapValues(ITERATOR val1, ITERATOR val2)
{
	typedef typename ITERATOR::value_type value_type;
#if 1//���[�u�R���X�g���N�^�ƃ��[�u�I�y���[�^���g�p���ē���ւ��i#include <utility> �� std::swap() �Ɠ����j
	value_type tmp = std::move(*val2);
	*val2 = std::move(*val1);
	*val1 = std::move(tmp);
#else//�R���X�g���N�^�^�I�y���[�^�̌Ăяo��������ĒP���ȃ������R�s�[
	char tmp[sizeof(value_type)];
	memcpy(tmp, &*val2, sizeof(value_type));
	memcpy(&*val2, &*val1, sizeof(value_type));
	memcpy(&*val1, tmp, sizeof(value_type));
#endif
}

//----------------------------------------
//�f�[�^�̃��[�e�[�V���� ���C�e���[�^�Ή���
template<class ITERATOR>
inline void iteratorRotateValues(ITERATOR val1, ITERATOR val2, int step)
{
	typedef typename ITERATOR::value_type value_type;
#if 1//���[�u�R���X�g���N�^�ƃ��[�u�I�y���[�^���g�p���ē���ւ�
	value_type tmp = std::move(*val2);
	while (val1 != val2)
	{
		ITERATOR val2_prev = val2 - step;
		*val2 = std::move(*val2_prev);
		val2 = val2_prev;
	}
	*val1 = std::move(tmp);
#else//�R���X�g���N�^�^�I�y���[�^�̌Ăяo��������ĒP���ȃ������R�s�[
	char tmp[sizeof(value_type)];
	memcpy(tmp, &*val2, sizeof(value_type));
	while (val1 != val2)
	{
		ITERATOR val2_prev = val2 - step;
		memcpy(&*val2, &*val2_prev, sizeof(value_type));
		val2 = val2_prev;
	}
	memcpy(&*val1, tmp, sizeof(value_type));
#endif
}

//----------------------------------------
//�C�e���[�^�̍��i�v�f���j��Ԃ�
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::input_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin < end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::output_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin < end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::forward_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin < end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::bidirectional_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin < end; ++begin)
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
	for (; begin < end; ++begin)
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
	while (begin > end)
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
//�\�[�g�A���S���Y�����ށF�}���\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�}���\�[�g ���C�e���[�^�Ή���
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(n)
//�E���όv�Z���ԁFO(n^2)
//�E�ň��v�Z���ԁFO(n^2)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@��
//----------------------------------------
template<class ITERATOR, class PREDICATE>
std::size_t iteratorInsertionSort(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	if (begin == end)
		return 0;
	std::size_t swapped_count = 0;
	ITERATOR now = begin;
	ITERATOR next = begin;
	++next;
	while (next < end)
	{
		if (predicate(*next, *now))
		{
			ITERATOR min = now;
			ITERATOR prev = now;
			--prev;
			while (prev >= begin)
			{
				if (predicate(*next, *prev))
					min = prev;
				else
					break;
				--prev;
			}
			iteratorRotateValues(min, next, 1);
			++swapped_count;
		}
		++now;
		++next;
	}
	return swapped_count;
}
iteratorSortFuncSet(iteratorInsertionSort);

//----------------------------------------
//�A���S���Y���F�V�F���\�[�g ���C�e���[�^�Ή���
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(n)
//�E���όv�Z���ԁFO(n log^2 n) or O(n^3/2)
//�E�ň��v�Z���ԁFO(n log^2 n)
//�E�������g�p�ʁFO(1)
//�E���萫�F�@�@�@�~
//----------------------------------------
template<class ITERATOR, class PREDICATE>
std::size_t iteratorShellSort(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	if (begin == end)
		return 0;
	std::size_t swapped_count = 0;
	const typename ITERATOR::difference_type size = iteratorDifference(begin, end);
	const int h_max = size / 3;
	int h = 1;
	while (h <= h_max)
		h = 3 * h + 1;
	while (h > 0)
	{
		ITERATOR now = begin;
		ITERATOR next = begin;
		next += h;
		while (next < end)
		{
			if (predicate(*next, *now))
			{
				ITERATOR min = now;
				ITERATOR prev = now;
				prev -= h;
				while (prev >= begin)
				{
					if (predicate(*next, *prev))
						min = prev;
					else
						break;
					prev -= h;
				}
				iteratorRotateValues(min, next, h);
				++swapped_count;
			}
			++now;
			++next;
		}
		h = (h - 1) / 3;
	}
	return swapped_count;
}
iteratorSortFuncSet(iteratorShellSort);

//========================================
//�\�[�g�A���S���Y�����ށF�����\�[�g
//========================================

//----------------------------------------
//�A���S���Y���F�C���g���\�[�g ���C�e���[�^�Ή���
//----------------------------------------
//�E�ŗǌv�Z���ԁFO(n log n)
//�E���όv�Z���ԁFO(n log n)
//�E�ň��v�Z���ԁFO(n log n)
//�E�������g�p�ʁFO(n log n) �����[�v�����ł� O(32*2)
//�E���萫�F�@�@�@�~
//----------------------------------------
template<class ITERATOR, class PREDICATE>
std::size_t _iteratorIntroSort(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	int depth_max = 0;//�q�[�v�\�[�g�ɐ؂�ւ���ċA�i�X�^�b�N�j�̐[��
	typename ITERATOR::difference_type size = iteratorDifference(begin, end);
	for (std::size_t size_tmp = size; size_tmp > 1; size_tmp >>= 1, ++depth_max);
	//--------------------
	//�N�C�b�N�\�[�g�F�X�^�b�N������
	//���ċA�����ł͏ȗ�
	static const std::size_t SIZE_THRESHOLD = 16;//32;//�}���\�[�g�ɐ؂�ւ��錏��
	std::size_t swapped_count = 0;
	struct stack_t
	{
		ITERATOR begin;
		ITERATOR end;
		int depth;
	};
	static const int STACK_DEPTH_MAX = 32 * 2;
	stack_t stack[STACK_DEPTH_MAX];
	//�ŏ��̔z����X�^�b�N�Ƀv�b�V��
	stack_t* stack_p = &stack[0];
	stack_p->begin = begin;
	stack_p->end = end;
	stack_p->depth = depth_max;
	int stack_curr = 1;//�X�^�b�N�ʒu
	while (stack_curr > 0)
	{
		//�z����X�^�b�N����擾
		stack_p = &stack[--stack_curr];
		ITERATOR _begin_range = std::move(stack_p->begin);
		ITERATOR _end_range = std::move(stack_p->end);
		const typename ITERATOR::difference_type _size = iteratorDifference(_begin_range, _end_range);
		const int _depth = stack_p->depth;
		//�z��͈̔͏��
		ITERATOR _begin = _begin_range;
		ITERATOR _end = _end_range - 1;
		//��������
		ITERATOR _mid = _begin + (_size >> 1);
		ITERATOR _pivot =
			predicate(_begin, _mid) ?
				predicate(_mid, _end) ?
					_mid :
					predicate(_end, _begin) ?
						_begin :
						_end :
				predicate(_end, _mid) ?
					_mid :
					predicate(_begin, _end) ?
						_begin :
						_end;
		//�������̔z��Ǝ��ȏ�̔z��ɓ�
		while (true)
		{
			while (predicate(_begin, _pivot))
				++_begin;
			while (predicate(_pivot, _end))
				--_end;
			if (_begin >= _end)
				break;
			iteratorSwapValues(_begin, _end);
			_pivot = _pivot == _begin ? _end : _pivot == _end ? _begin : _pivot;//���̈ʒu�����i���̈ʒu������ւ�邽�߁j
			++swapped_count;
			++_begin;
			--_end;
		}
		//recursive = 0 : �������̔z����v�b�V��
		//            1 : ���ȏ�̔z����v�b�V��
		for (int recursive = 0; recursive < 2; ++recursive)
		{
			ITERATOR _new_begin = recursive == 0 ? _begin_range : _end + 1;
			ITERATOR _new_end = recursive == 0 ? _begin : _end_range;
			const typename ITERATOR::difference_type _new_size = _new_end - _new_begin;
			const int _new_depth = _depth - 1;
			if (_new_size >= 1)
			{
				if (_new_size < SIZE_THRESHOLD)
				{
					//swapped_count += iteratorInsertionSort(_new_begin, _new_end, predicate);//�y�{���̏����z�}���\�[�g�ɐ؂�ւ�
					//swapped_count += iteratorCombSort(_new_begin, _new_end, predicate);//�y���ǁz�R���\�[�g�ɐ؂�ւ�
					swapped_count += iteratorShellSort(_new_begin, _new_end, predicate);//�y���ǁz�V�F���\�[�g�ɐ؂�ւ�
				}
				else if (_new_depth == 0)
				{
					//swapped_count += iteratorHeapSort(_new_begin, _new_end, predicate);//�y�{���̏����z�q�[�v�\�[�g�ɐ؂�ւ�
					//swapped_count += iteratorCombSort(_new_begin, _new_end, predicate);//�y���ǁz�R���\�[�g�ɐ؂�ւ�
					swapped_count += iteratorShellSort(_new_begin, _new_end, predicate);//�y���ǁz�V�F���\�[�g�ɐ؂�ւ�
				}
				else
				{
					//�ċA
					stack_p = &stack[stack_curr++];
					stack_p->begin = _new_begin;
					stack_p->end = _new_end;
					stack_p->depth = _new_depth;
				}
			}
		}
	}
	return swapped_count;
}
template<class ITERATOR, class PREDICATE>
inline std::size_t iteratorIntroSort(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	if (begin == end)
		return 0;
	if (iteratorCalcUnordered(begin, end, predicate) == 0)
		return 0;
	return _iteratorIntroSort(begin, end, predicate);
}
iteratorSortFuncSet(iteratorIntroSort);

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
	while (true)
	{
		const int range_half = range / 2;//�T���͈͂̔����͈̔�
		ITERATOR mid = begin + range_half;//�T���͈͂̒��S�v�f
		const int comp = comparison(*mid);//���S�v�f��T���L�[�Ɣ�r
		if (comp == 0)//���S�v�f���T���L�[�ƈ�v
		{
			//�k���ăL�[�̊J�n�_��T��
			while (mid > begin)
			{
				ITERATOR prev = mid - 1;
				if (comparison(*prev) != 0)
					break;
				mid = prev;
			}
			return mid;//�T���I��
		}
		if (range_half == 0)//�T���͈͂��c���Ă��Ȃ���ΒT�����s
			return end;
		if (comp < 0)//�T���L�[�����S�v�f��菬���������ꍇ�A���ɒ��S���O�͈̔͂ɍi���ĒT������
			range = range_half;
		else//if (comp > 0)//�T���L�[�����S�v�f���傫�������ꍇ�A���ɒ��S����͈̔͂ɍi���ĒT������
		{
			begin = mid + 1;
			range -= (range_half + 1);
		}
	}
	return end;
}
iteratorSearchFuncSetByComparison(iteratorBinarySearch);

//--------------------------------------------------------------------------------
//�����O�o�b�t�@
//--------------------------------------------------------------------------------
//�f�[�^�\���ƃA���S���Y��
//�y�����z
//�E�P���Ȉꎟ�z��������O�o�b�t�@�Ƃ��ĊǗ�����B
//�E�z��̗v�f���𒴂��Ȃ��͈͂ŁA�L���v�f���𓮓I�ɕω������ĊǗ�����B
//�E�L���v�f�̑����ɔ����A�R���X�g���N�^�^�f�X�g���N�^�̌Ăяo�����s���B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y�{�v���O�����ɂ���������v���z
//�E�A���S���Y���ƃf�[�^�{�̂𕪗������R���e�i�Ƃ���B
//�E�R���e�i���̂͗v�f�̎��̂��������������m�ۂ��s��Ȃ��B
//�E�R���X�g���N�^�Ŏ󂯂Ƃ����z��̎Q�Ƃ������B
//�ESTL�istd::deque�j�Ƃ̈Ⴂ�͉��L�̒ʂ�
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

namespace ring_buffer
{
	//--------------------
	//�����O�o�b�t�@����p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename VALUE_TYPE>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public ring_buffer::base_ope_t<�h���\����, �v�f�^>
	//	struct ope_t : public ring_buffer::base_ope_t<ope_t, data_t>
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
	//�����O�o�b�t�@�R���e�i
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
			inline const_iterator operator[](const int logical_index) const
			{
				iterator ite(*m_con, false);
				ite.update(logical_index);
				return std::move(ite);
			}
			inline iterator operator[](const int logical_index)
			{
				iterator ite(*m_con, false);
				ite.update(logical_index);
				return std::move(ite);
			}
	public:
			//��r�I�y���[�^
			inline bool operator==(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_logicalIndex == rhs.m_logicalIndex;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_logicalIndex != rhs.m_logicalIndex;
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_logicalIndex > rhs.m_logicalIndex;
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_logicalIndex >= rhs.m_logicalIndex;
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_logicalIndex < rhs.m_logicalIndex;
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_logicalIndex <= rhs.m_logicalIndex;
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
				return std::move(ite);
			}
			inline const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline const_iterator& operator+=(const typename iterator::difference_type rhs) const
			{
				addIndexAndUpdate(rhs);
				return *this;
			}
			inline const_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline const_iterator& operator-=(const typename iterator::difference_type rhs) const
			{
				addIndexAndUpdate(-rhs);
				return *this;
			}
			inline const_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator+=(const typename iterator::difference_type rhs)
			{
				addIndexAndUpdate(rhs);
				return *this;
			}
			inline iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator-=(const typename iterator::difference_type rhs)
			{
				addIndexAndUpdate(-rhs);
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
				return std::move(ite);
			}
			inline const_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline const_iterator operator-(const typename iterator::difference_type rhs) const
			{
				iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline const_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator+(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator-(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline typename iterator::difference_type operator-(const iterator rhs)
			{
				if (m_logicalIndex == INVALID_INDEX || rhs.m_logicalIndex == INVALID_INDEX || m_logicalIndex < rhs.m_logicalIndex)
					return 0;
				return m_logicalIndex - rhs.m_logicalIndex;
			}
		public:
			//���[�u�I�y���[�^
			inline iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_logicalIndex = rhs.m_logicalIndex;
				m_value = rhs.m_value;
				return *this;
			}
			iterator& operator=(const_reverse_iterator&& rhs);
			//�R�s�[�I�y���[�^
			inline iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_logicalIndex = rhs.m_logicalIndex;
				m_value = rhs.m_value;
				return *this;
			}
			iterator& operator=(const_reverse_iterator& rhs);
		public:
			//�A�N�Z�b�T
			inline bool isExist() const { return m_logicalIndex != INVALID_INDEX && m_logicalIndex < m_con->m_size; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_logicalIndex != INVALID_INDEX; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_logicalIndex == m_con->m_size; }//�I�[���H
			inline index_type getRealIndex() const { return m_logicalIndex == INVALID_INDEX ? INVALID_INDEX : m_con->_to_real_index(m_logicalIndex); }//�����C���f�b�N�X
			inline index_type getIndex() const { return m_logicalIndex; }//�_���C���f�b�N�X
			inline const value_type* getValue() const { return m_value; }//���݂̒l
			inline value_type* getValue(){ return m_value; }//���݂̒l
		private:
			//���\�b�h
			void update(const index_type logical_index) const
			{
				//if (logical_index == INVALID_INDEX || logical_index < 0 || logical_index > static_cast<index_type>(m_con->m_size))
				if (logical_index > static_cast<index_type>(m_con->m_size))
				{
					m_logicalIndex = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_logicalIndex = logical_index;
					const index_type real_index = m_con->_to_real_index(m_logicalIndex);
					m_value = const_cast<value_type*>(m_con->_ref_real_element(real_index));
				}
			}
			inline void addIndexAndUpdate(const int add) const
			{
				update(m_logicalIndex + add);
			}
		public:
			//���[�u�R���X�g���N�^
			iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_logicalIndex(obj.m_logicalIndex),
				m_value(obj.m_value)
			{}
			iterator(const_reverse_iterator&& obj);
			//�R�s�[�R���X�g���N�^
			inline iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_logicalIndex(obj.m_logicalIndex),
				m_value(obj.m_value)
			{}
			iterator(const_reverse_iterator& obj);
			//�R���X�g���N�^
			inline iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_logicalIndex(INVALID_INDEX),
				m_value(nullptr)
			{
				if (!is_end)
					update(0);//�擪�f�[�^
				else
					update(m_con->m_size);//�����f�[�^
			}
			inline iterator(const container& con, const index_type logical_index) :
				m_con(&con),
				m_logicalIndex(INVALID_INDEX),
				m_value(nullptr)
			{
				update(logical_index);
			}
			inline iterator() :
				m_con(nullptr),
				m_logicalIndex(INVALID_INDEX),
				m_value(nullptr)
			{}
			//�f�X�g���N�^
			inline ~iterator()
			{}
		protected:
			//�t�B�[���h
			const container* m_con;//�R���e�i
			mutable index_type m_logicalIndex;//���݂̘_���C���f�b�N�X
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
			inline const_reverse_iterator operator[](const int logical_index) const
			{
				reverse_iterator ite(*m_con, false);
				ite.update(m_con->m_size - logical_index);
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int logical_index)
			{
				reverse_iterator ite(*m_con, false);
				ite.update(m_con->m_size - logical_index);
				return std::move(ite);
			}
		public:
			//��r�I�y���[�^
			inline bool operator==(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_logicalIndex == m_logicalIndex;
			}
			inline bool operator!=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_logicalIndex != m_logicalIndex;
			}
			inline bool operator>(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_logicalIndex > m_logicalIndex;
			}
			inline bool operator>=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_logicalIndex >= m_logicalIndex;
			}
			inline bool operator<(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_logicalIndex < m_logicalIndex;
			}
			inline bool operator<=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_logicalIndex <= m_logicalIndex;
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
				return std::move(ite);
			}
			inline const_reverse_iterator operator--(int) const
			{
				reverse_iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline reverse_iterator operator++(int)
			{
				reverse_iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline reverse_iterator operator--(int)
			{
				reverse_iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline const_reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs) const
			{
				addIndexAndUpdate(rhs);
				return *this;
			}
			inline const_reverse_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline const_reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs) const
			{
				addIndexAndUpdate(-rhs);
				return *this;
			}
			inline const_reverse_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs)
			{
				addIndexAndUpdate(rhs);
				return *this;
			}
			inline reverse_iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs)
			{
				addIndexAndUpdate(-rhs);
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
				return std::move(ite);
			}
			inline const_reverse_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline const_reverse_iterator operator-(const typename reverse_iterator::difference_type rhs) const
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline const_reverse_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator+(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline reverse_iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator-(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline reverse_iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline typename reverse_iterator::difference_type operator-(const reverse_iterator rhs)
			{
				if (m_logicalIndex == INVALID_INDEX || rhs.m_logicalIndex == INVALID_INDEX || rhs.m_logicalIndex < m_logicalIndex)
					return 0;
				return rhs.m_logicalIndex - m_logicalIndex;
			}
		public:
			//���[�u�I�y���[�^
			inline reverse_iterator& operator=(const_reverse_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_logicalIndex = rhs.m_logicalIndex;
				m_value = rhs.m_value;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_logicalIndex = rhs.m_logicalIndex;
				update(m_logicalIndex);
				return *this;
			}
			//�R�s�[�I�y���[�^
			inline reverse_iterator& operator=(const_reverse_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_logicalIndex = rhs.m_logicalIndex;
				m_value = rhs.m_value;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_logicalIndex = rhs.m_logicalIndex;
				update(m_logicalIndex);
				return *this;
			}
		public:
			//�A�N�Z�b�T
			inline bool isExist() const { return m_logicalIndex != INVALID_INDEX && m_logicalIndex > 0; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_logicalIndex != INVALID_INDEX; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_logicalIndex == 0; }//�I�[���H
			inline index_type getRealIndex() const { return m_logicalIndex == INVALID_INDEX ? INVALID_INDEX : m_con->_to_real_index(m_logicalIndex); }//�����C���f�b�N�X
			inline index_type getIndex() const { return m_logicalIndex - 1; }//�_���C���f�b�N�X
			inline const value_type* getValue() const { return m_value; }//���݂̒l
			inline value_type* getValue(){ return m_value; }//���݂̒l
		private:
			//���\�b�h
			void update(const index_type logical_index) const
			{
				//if (logical_index == INVALID_INDEX || logical_index < 0 || index > static_cast<index_type>(m_con->m_size))
				if (logical_index > static_cast<index_type>(m_con->m_size))
				{
					m_logicalIndex = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_logicalIndex = logical_index;
					const index_type real_index = m_con->_to_real_index(m_logicalIndex);
					m_value = real_index == 0 ? const_cast<value_type*>(m_con->_ref_real_element(m_con->m_maxSize - 1)) : const_cast<value_type*>(m_con->_ref_real_element(real_index - 1));
				}
			}
			inline void addIndexAndUpdate(const int add) const
			{
				update(m_logicalIndex - add);
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
				m_logicalIndex(obj.m_logicalIndex),
				m_value(obj.m_value)
			{}
			inline reverse_iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_logicalIndex(obj.m_logicalIndex),
				m_value(nullptr)
			{
				update(m_logicalIndex);
			}
			//�R�s�[�R���X�g���N�^
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_con(obj.m_con),
				m_logicalIndex(obj.m_logicalIndex),
				m_value(obj.m_value)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_logicalIndex(obj.m_logicalIndex),
				m_value(nullptr)
			{
				update(m_logicalIndex);
			}
			//�R���X�g���N�^
			inline reverse_iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_logicalIndex(INVALID_INDEX),
				m_value(nullptr)
			{
				if (!is_end)
					update(m_con->m_size);//�����f�[�^
				else
					update(0);//�擪�f�[�^
			}
			inline reverse_iterator(const container& con, const index_type logical_index) :
				m_con(&con),
				m_logicalIndex(INVALID_INDEX),
				m_value(nullptr)
			{
				update(logical_index);
			}
			inline reverse_iterator() :
				m_con(nullptr),
				m_logicalIndex(INVALID_INDEX),
				m_value(nullptr)
			{}
			//�f�X�g���N�^
			inline ~reverse_iterator()
			{}
		protected:
			//�t�B�[���h
			const container* m_con;//�R���e�i
			mutable index_type m_logicalIndex;//���݂̕����C���f�b�N�X
			mutable value_type* m_value;//���݂̒l
		};
	public:
		//�A�N�Z�b�T
		inline const value_type* at(const int logical_index) const { return ref_element(logical_index); }
		inline value_type* at(const int logical_index){ return ref_element(logical_index); }
		inline const value_type* operator[](const int logical_index) const { return ref_element(logical_index); }
		inline value_type* operator[](const int logical_index){ return ref_element(logical_index); }
		auto_clear_attr_t getAutoClearAttr() const { return m_autoClearAttr; }//�R���e�i�j�����Ɏc���Ă���v�f�̎����N���A�������擾
		void setAutoClearAttr(const auto_clear_attr_t attr){ m_autoClearAttr = attr; }//�R���e�i�j�����Ɏc���Ă���v�f�̎����N���A������ύX
	public:
		//�L���X�g�I�y���[�^
		inline operator lock_type&(){ return m_lock; }//���L���b�N�I�u�W�F�N�g
		inline operator lock_type&() const { return m_lock; }//���L���b�N�I�u�W�F�N�g ��mutable
	public:
		//���\�b�h
		inline size_type max_size() const { return m_maxSize; }//�ő�v�f�����擾
		inline size_type capacity() const { return m_maxSize; }//�ő�v�f�����擾
		inline size_type size() const { return m_size; }//�g�p���̗v�f�����擾
		inline size_type remain() const { return m_maxSize - m_size; }//�c��̗v�f�����擾
		inline bool empty() const { return m_size == 0; }//�󂩁H
		inline bool full() const { return m_size == m_maxSize; }//���t���H
		inline index_type offset() const { return m_offset; }//�L���v�f�̐擪�C���f�b�N�X�i�I�t�Z�b�g�j
	private:
		//���͈̓`�F�b�N�Ȃ�
		inline index_type _to_real_index(const index_type logical_index) const//�_���C���f�b�N�X�𕨗��C���f�b�N�X�ɕϊ�
		{
			const index_type real_index = m_offset + logical_index;
			return real_index < m_maxSize ? real_index : real_index - m_maxSize;
		}
		inline index_type _to_logical_index(const index_type real_index) const//�����C���f�b�N�X��_���C���f�b�N�X�ɕϊ�
		{
			return real_index > m_offset ? real_index - m_offset : real_index + m_maxSize - m_offset;
		}
		inline size_type _front_new_real_index() const//�擪�̐V�K�C���f�b�N�X
		{
			return m_offset == 0 ? m_maxSize - 1 : m_offset - 1;
		}
		inline size_type _back_new_real_index() const//�����̐V�K�C���f�b�N�X
		{
			const index_type new_real_index = m_offset + m_size;
			return new_real_index < m_maxSize ? new_real_index : new_real_index - m_maxSize;
		}
		inline const value_type* _ref_real_element(const index_type real_index) const { return &m_array[real_index]; }//�v�f�Q��
		inline const value_type* _ref_element(const index_type logical_index) const { return &m_array[_to_real_index(logical_index)]; }//�v�f�Q��
		inline const value_type* _ref_front() const { return _ref_element(0); }//�擪�v�f�Q��
		inline const value_type* _ref_back() const { return _ref_element(m_size - 1); }//�����v�f�Q��
		inline const value_type* _ref_front_new() const { return _ref_real_element(_front_new_real_index()); }//�擪�̐V�K�v�f�Q��
		inline const value_type* _ref_back_new() const { return _ref_real_element(_back_new_real_index()); }//�����̐V�K�v�f�Q��
		inline value_type* _ref_real_element(const index_type real_index){ return &m_array[real_index]; }//�v�f�Q��
		inline value_type* _ref_element(const index_type logical_index){ return &m_array[_to_real_index(logical_index)]; }//�v�f�Q��
		inline value_type* _ref_front(){ return _ref_element(0); }//�擪�v�f�Q��
		inline value_type* _ref_back(){ return _ref_element(m_size - 1); }//�����v�f�Q��
		inline value_type* _ref_front_new(){ return _ref_real_element(_front_new_real_index()); }//�擪�̐V�K�v�f�Q��
		inline value_type* _ref_back_new(){ return _ref_real_element(_back_new_real_index()); }//�����̐V�K�v�f�Q��
	public:
		//���͈̓`�F�b�N����
		//inline const value_type* ref_element(const index_type logical_index) const { return logical_index >= 0 && logical_index < m_size ? _ref_element(logical_index) : nullptr; }//�v�f�Q��
		inline const value_type* ref_element(const index_type logical_index) const { return logical_index < m_size ? _ref_element(logical_index) : nullptr; }//�v�f�Q��
		inline const value_type* ref_front() const { return m_size == 0 ? nullptr : _ref_front(); }//�擪�v�f�Q��
		inline const value_type* ref_back() const { return m_size == 0 ? nullptr : _ref_back(); }//�����v�f�Q��
		inline const value_type* ref_front_new() const { return m_size == m_maxSize ? nullptr : _ref_front_new(); }//�擪�̐V�K�v�f�Q��
		inline const value_type* ref_back_new() const { return m_size == m_maxSize ? nullptr : _ref_back_new(); }//�����̐V�K�v�f�Q��
		inline value_type* ref_element(const index_type logical_index){ return  const_cast<value_type*>(const_cast<const container*>(this)->ref_element(logical_index)); }//�v�f�Q��
		inline value_type* ref_front(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_front()); }//�擪�v�f�Q��
		inline value_type* ref_back(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_back()); }//�����v�f�Q��
		inline value_type* ref_front_new(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_front_new()); }//�擪�̐V�K�v�f�Q��
		inline value_type* ref_back_new(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_back_new()); }//�����̐V�K�v�f�Q��
	private:
		inline int _adj_logical_index(const int logical_index) const { return logical_index >= 0 && logical_index < m_maxSize ? logical_index : INVALID_INDEX; }//�_���C���f�b�N�X��͈͓��ɕ␳
		inline int _ref_real_index(const value_type* node) const{ return node - _ref_front(); }//�v�f�𕨗��C���f�b�N�X�ɕϊ� ���͈̓`�F�b�N�Ȃ�
		inline int _ref_logical_index(const value_type* node) const{ return _to_logical_index(_ref_real_index(node)); }//�v�f��_���C���f�b�N�X�ɕϊ� ���͈̓`�F�b�N�Ȃ�
	public:
		inline int ref_logical_index(const value_type* node) const{ return _adj_logical_index(_ref_logical_index(node)); }//�v�f��_���C���f�b�N�X�ɕϊ�
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
			m_maxSize = max_size;
			m_size = size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size);
			m_offset = 0;
		}
		//��void�|�C���^�ƃo�b�t�@�T�C�Y���w���
		void assign_array(void* buff_ptr, const size_type buff_size, const int size = 0)
		{
			assign_array(static_cast<value_type*>(buff_ptr), buff_size / sizeof(value_type), size);
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
				for (index_type index = m_size; index < _size; ++index)
				{
					value_type* value = _ref_element(index);
					*value = new_value;//�V�����l��������
				}
			}
			else if (_size < m_size)
			{
				for (index_type index = _size; index < m_size; ++index)
				{
					value_type* value = _ref_element(index);
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
				for (index_type index = m_size; index < _size; ++index)
				{
					value_type* value = _ref_element(index);
					new(value)value_type(args...);//�R���X�g���N�^�Ăяo��
				}
			}
			else if (_size < m_size)
			{
				for (index_type index = size; index < m_size; ++index)
				{
					value_type* value = _ref_element(index);
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
			//	for (index_type index = 0; index < used_size; ++index)
			//	{
			//		value_type* value = _ref_element(index);
			//		ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
			//		operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			//	}
			//}
			{
				for (index_type index = 0; index < _size; ++index)
				{
					value_type* value = _ref_element(index);
					*value = new_value;//�f�[�^���㏑��
				}
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
				for (index_type index = 0; index < used_size; ++index)
				{
					value_type* value = _ref_element(index);
					ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
					operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
				}
			}
			{
				for (index_type index = 0; index < _size; ++index)
				{
					value_type* value = _ref_element(index);
					new(value)value_type(args...);//�R���X�g���N�^�Ăяo��
				}
			}
			if (m_size < _size)
				m_size = _size;
			return m_size;
		}
		//�擪�ɗv�f��ǉ�
		//���I�u�W�F�N�g�n��
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ��Ӂi�����x���Ȃ�j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		inline value_type* push_front(const value_type&& src)//���[�u��
		{
			value_type* obj = ref_front_new();//�T�C�Y�`�F�b�N�܂�
			if (!obj)
				return nullptr;
			*obj = std::move(src);
			++m_size;
			m_offset = m_offset == 0 ? m_maxSize - 1 : m_offset - 1;
			return obj;
		}
		inline value_type* push_front(const value_type& src)//�R�s�[��
		{
			value_type* obj = ref_front_new();//�T�C�Y�`�F�b�N�܂�
			if (!obj)
				return nullptr;
			*obj = src;
			++m_size;
			m_offset = m_offset == 0 ? m_maxSize - 1 : m_offset - 1;
			return obj;
		}
		//�擪�ɗv�f��ǉ�
		//���p�����[�^�n��
		//���I�u�W�F�N�g�̃R���X�g���N�^���Ăяo�����
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		template<typename... Tx>
		value_type* push_front(Tx... args)
		{
			value_type* obj = ref_front_new();//�T�C�Y�`�F�b�N�܂�
			if (!obj)
				return nullptr;
			new(obj)value_type(args...);//�R���X�g���N�^�Ăяo��
			++m_size;
			m_offset = m_offset == 0 ? m_maxSize - 1 : m_offset - 1;
			return obj;
		}
		//�����ɗv�f��ǉ�
		//���I�u�W�F�N�g�n��
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ��Ӂi�����x���Ȃ�j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		inline value_type* push_back(const value_type&& src)//���[�u��
		{
			value_type* obj = ref_back_new();//�T�C�Y�`�F�b�N�܂�
			if (!obj)
				return nullptr;
			*obj = std::move(src);
			++m_size;
			return obj;
		}
		inline value_type* push_back(const value_type& src)//�R�s�[��
		{
			value_type* obj = ref_back_new();//�T�C�Y�`�F�b�N�܂�
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
			value_type* obj = ref_back_new();//�T�C�Y�`�F�b�N�܂�
			if (!obj)
				return nullptr;
			new(obj)value_type(args...);//�R���X�g���N�^�Ăяo��
			++m_size;
			return obj;
		}
		//�擪�̗v�f���폜
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo�����
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		bool pop_front()
		{
			if (m_size == 0)
				return false;
			value_type* value = const_cast<value_type*>(ref_front());
			ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
			operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			--m_size;
			m_offset = m_offset == m_maxSize - 1 ? 0 : m_offset + 1;
			return true;
		}
		//���I�u�W�F�N�g�̒l���󂯎��
		bool pop_front(value_type& value)
		{
			if (m_size == 0)
				return false;
			value_type* obj = const_cast<value_type*>(ref_front());
			value = std::move(*obj);//���[�u
			ope_type::callDestructor(obj);//�f�X�g���N�^�Ăяo��
			operator delete(obj, obj);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			--m_size;
			m_offset = m_offset == m_maxSize - 1 ? 0 : m_offset + 1;
			return true;
		}
		//�����̗v�f���폜
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo�����
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		bool pop_back()
		{
			if (m_size == 0)
				return false;
			value_type* value = const_cast<value_type*>(ref_front());
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
			for (size_type i = 0; i < m_size; ++i)
			{
				value_type* value = _ref_element(i);
				ope_type::callDestructor(value);//�f�X�g���N�^�Ăяo��
				operator delete(value, value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			}
			m_size = 0;
			m_offset = 0;
		}
	private:
		//�v�f�̈ړ��i�����j
		void move_asc(const index_type dst_pos, const index_type src_pos, const size_type num)
		{
			index_type _dst_pos = dst_pos;
			index_type _src_pos = src_pos;
			for (size_type i = 0; i < num; ++i)
			{
				value_type* dst = _ref_element(_dst_pos);
				value_type* src = _ref_element(_src_pos);
				if (_dst_pos >= m_size)
					new(dst)value_type(std::move(*src));//���[�u�R���X�g���N�^
				else
					*dst = std::move(*src);//���[�u�I�y���[�^
				++_dst_pos;
				++_src_pos;
			}
		}
		//�v�f�̈ړ��i�~���j
		void move_desc(const index_type dst_pos, const index_type src_pos, const size_type num)
		{
			index_type _dst_pos = dst_pos + num - 1;
			index_type _src_pos = src_pos + num - 1;
			for (size_type i = 0; i < num; ++i)
			{
				value_type* dst = _ref_element(_dst_pos);
				value_type* src = _ref_element(_src_pos);
				if (_dst_pos >= m_size)
					new(dst)value_type(std::move(*src));//���[�u�R���X�g���N�^
				else
					*dst = std::move(*src);//���[�u�I�y���[�^
				--_dst_pos;
				--_src_pos;
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
			index_type _index = index;
			for (size_type i = 0; i < _num; ++i)
			{
				value_type* new_value = _ref_element(_index);
				*new_value = value;
				++_index;
			}
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
			index_type _index = index;
			for (size_type i = 0; i < _num; ++i)
			{
				value_type* new_value = _ref_element(_index);
				new(new_value)value_type(args...);
				++_index;
			}
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
			index_type _index = index;
			for (size_type i = 0; i < _num; ++i)
			{
				value_type* delete_value = _ref_element(_index);
				ope_type::callDestructor(delete_value);//�f�X�g���N�^�Ăяo��
				operator delete(delete_value, delete_value);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
				++_index;
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
		//���V�F���\�[�g���g�p
		//��ope_type::sort_predicate() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator<() �ɏ]���ĒT���j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		void sort()
		{
			iteratorIntroSort(begin(), end(), typename ope_type::sort_predicate());
		}
		//���v���f�B�P�[�g�֐��w���
		template<class PREDICATE>
		void sort(PREDICATE predicate)
		{
			iteratorIntroSort(begin(), end(), predicate);
		}
		//����\�[�g
		//���}���\�[�g���g�p
		//��ope_type::sort_predicate() ���g�p���ĒT���i�W���ł́A�f�[�^�^�� operator<() �ɏ]���ĒT���j
		//�������I�ȃ��b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�̑O��Ŕr�����b�N�i���C�g���b�N�j�̎擾�Ɖ�����s���K�v������
		void stable_sort()
		{
			iteratorInsertionSort(begin(), end(), typename ope_type::sort_predicate());
		}
		//���v���f�B�P�[�g�֐��w���
		template<class PREDICATE>
		void stable_sort(PREDICATE predicate)
		{
			iteratorInsertionSort(begin(), end(), predicate);
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
	public:
		//�R���X�g���N�^
		//��������ԂŎg�p���̗v�f�����w�肷��i-1�őS�v�f���g�p���ɂ���j
		//���v�f�̏������͍s��Ȃ��i�K�v�Ȃ� size �� 0 ���w�肵�āA��� resize() ���Ăяo���j
		template<size_type N>
		container(value_type(&array)[N], const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(array),
			m_maxSize(N),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_offset(0),
			m_autoClearAttr(auto_clear_attr)
		{}
		//���|�C���^�Ɣz��v�f���w���
		container(value_type* array, const size_type max_size, const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(array),
			m_maxSize(max_size),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_offset(0),
			m_autoClearAttr(auto_clear_attr)
		{}
		//��void�|�C���^�ƃo�b�t�@�T�C�Y���w���
		container(void* buff_ptr, const size_type buff_size, const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(static_cast<value_type*>(buff_ptr)),
			m_maxSize(buff_size / sizeof(value_type)),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_offset(0),
			m_autoClearAttr(auto_clear_attr)
		{}
		//�f�t�H���g�R���X�g���N�^
		container() :
			m_array(nullptr),
			m_maxSize(0),
			m_size(0),
			m_offset(0),
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
		size_type m_maxSize;//�ő�v�f���i�ォ��ύX�\�ȃT�C�Y�j
		size_type m_size;//�g�p���̗v�f��
		index_type m_offset;//�L���v�f�̐擪�C���f�b�N�X�i�I�t�Z�b�g�j
		auto_clear_attr_t m_autoClearAttr;//�R���e�i�j�����Ɏc���Ă���v�f�̎����N���A����
		mutable lock_type m_lock;//���b�N�I�u�W�F�N�g
	};
	//�C�e���[�^�̃��[�u�I�y���[�^
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator&& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator&& rhs)//VC++��OK
	{
		m_con = rhs.m_con;
		m_logicalIndex = rhs.m_logicalIndex;
		update(m_logicalIndex);
		return *this;
	}
	//�C�e���[�^�̃R�s�[�I�y���[�^
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator& rhs)//VC++��OK
	{
		m_con = rhs.m_con;
		m_logicalIndex = rhs.m_logicalIndex;
		update(m_logicalIndex);
		return *this;
	}
	//�C�e���[�^�̃��[�u�R���X�g���N�^
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator&& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator&& obj) ://VC++��OK
		m_con(obj.m_con),
		m_logicalIndex(obj.m_logicalIndex),
		m_value(nullptr)
	{
		update(m_logicalIndex);
	}
	//�C�e���[�^�̃R�s�[�R���X�g���N�^
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator& obj) ://VC++��OK
		m_con(obj.m_con),
		m_logicalIndex(obj.m_logicalIndex),
		m_value(nullptr)
	{
		update(m_logicalIndex);
	}
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace ring_buffer

//--------------------------------------------------------------------------------
//�����O�o�b�t�@�e�X�g
//--------------------------------------------------------------------------------

#include <algorithm>//std::for_each�p
#include <deque>//std::deque�p�i��r�p�j

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
//��std::binary_search���g�p����ꍇ�́A���̃I�y���[�^���K�v
static bool operator<(const int key, const data_t& rhs)
{
	return key < rhs.m_key;
}
//----------------------------------------
//�e�X�g�f�[�^����N���X�@�F�f�t�H���g�̂܂܎g��
struct ope_t : public ring_buffer::base_ope_t<ope_t, data_t>{};
//----------------------------------------
//�e�X�g�f�[�^����N���X�A�F�\�[�g�^�T�����@���f�t�H���g����ς���
struct another_ope_t : public ring_buffer::base_ope_t<ope_t, data_t>
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
struct mt_ope_t : public ring_buffer::base_ope_t<mt_ope_t, data_t>
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
	//���ꕔ�����O�o�b�t�@�ŗL�̃e�X�g���s�����A��{�I�ɓ��I�z��̃e�X�g�ƂقƂ�Ǔ���
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for ring_buffer::container(Primitive type)]\n");

		int arr[20];//�z��

		//int�^�p�̃f�[�^����N���X��`
		struct ope_t : public ring_buffer::base_ope_t<ope_t, int>{};

		//�R���e�i����
		//�������̔z���n���ă����O�o�b�t�@�R���e�i�Ƃ��Ĉ���
		ring_buffer::container<ope_t> con(arr);//�z��v�f���������擾

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("offset=%d, size=%d, max_size=%d\n", con.offset(), con.size(), con.max_size());
			printf("array=");
			if (con.empty())
				printf("(empty)");
			for (auto val : con)
				printf(" %d", val);
			printf("\n");
		};

		//�f�[�^���t���ɕ\��
		auto printReverse = [&con]()
		{
			printf("offset=%d, size=%d, max_size=%d\n", con.offset(), con.size(), con.max_size());
			printf("array(reverse)=");
			if (con.empty())
				printf("(empty)");
			std::for_each(con.rbegin(), con.rend(),
				[](int val)
				{
					printf(" %d", val);
				}
			);
			printf("\n");
		};

		//--------------------------------------------------------------------------------
		//�������O�o�b�t�@�ŗL�̃e�X�g�@�i��������j������ȊO�͓��I�z��̃e�X�g�ƂقƂ�Ǔ���
		
		//�����ɘA���v�b�V��(1)
		auto continuous_push_back = [&con](const int num)
		{
			printf("\n");
			printf("[push_back * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				const int val = i;
				printf("push_back(%d) ... ", val);
				if (con.push_back(val))
					printf("OK\n");
				else
					printf("NG!\n");
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
				int val;
				printf("pop_front() ... ");
				if (con.pop_front(val))
					printf("OK [%d]\n", val);
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
				const int val = 1000 + i;
				printf("push_front(%d) ... ", val);
				if (con.push_front(val))
					printf("OK\n");
				else
					printf("NG!\n");
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
				int val;
				printf("pop_back() ... ");
				if (con.pop_back(val))
					printf("OK [%d]\n", val);
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

		//10���قǃf�[�^�̊J�n�ʒu�����炷
		{
			for (int i = 0; i < 10; ++i)
			{
				con.push_back(0);
				con.pop_front();
			}
		}

		//--------------------------------------------------------------------------------
		//�������O�o�b�t�@�ŗL�̃e�X�g�@�i�����܂Łj

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
		//std::sort(con.begin(), con.end());//�����\�[�g(STL��)
		//std::stable_sort(con.begin(), con.end());//����\�[�g(STL��)
		printAll();//�S���\��

		//�t���Ƀ\�[�g ���J�X�^���v���f�B�P�[�g�֐����g�p
		printf("\n");
		printf("[custom sort]\n");
		auto reverse_pred = [](const int lhs, const int rhs) -> bool {return lhs > rhs; };
		con.sort(reverse_pred);//�����\�[�g
		//con.stable_sort(reverse_pred);//����\�[�g
		//std::sort(con.begin(), con.end(), reverse_pred);//�����\�[�g(STL��)
		//std::stable_sort(con.begin(), con.end(), reverse_pred);//����\�[�g(STL��)
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

		//���`����
		printf("\n");
		printf("[find]\n");
		printAll();//�S���\��
		auto find = [&con](const int val)
		{
			printf("find_value(%d)=", val);
			auto ite = con.find_value(val);//���`�T��
			//auto ite = std::find(con.begin(), con.end(), val);//���`�T��(STL��)
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
			//if(std::binary_search(con.begin(), con.end(), val))//�񕪒T��(STL��)
			//{
			//	auto ite = std::lower_bound(con.begin(), con.end(), val);
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

	#if 0
		{
			con.sort(reverse_pred);//�����\�[�g
			printAll();//�S���\��
			con.sort();//�����\�[�g
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
		}
	#endif

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

		//�f�[�^���蓖��
		printf("\n");
		printf("[assign]\n");
		con.assign(-1, 0);//��-1�ōő�v�f���S���Ɋ��蓖��
		printAll();//�S���\��

		//�N���A
		printf("\n");
		printf("[clear]\n");
		con.clear();
		printAll();//�S���\��
		//printReverse();//�S���t���\��
	}

	//--------------------
	//�e�X�g�A�F���[�U�[��`�^�������ꍇ
	//���ꕔ�����O�o�b�t�@�ŗL�̃e�X�g���s�����A��{�I�ɓ��I�z��̃e�X�g�ƂقƂ�Ǔ���
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for ring_buffer::container(User defined type)]\n");

		//�z��f�[�^
		data_t array[20];
		//�����̐錾���ƁA�f�t�H���g�R���X�g���N�^�ƃf�X�g���N�^���Ăяo�����_�ɒ���

		//�����O�o�b�t�@�R���e�i����
		typedef ring_buffer::container<ope_t> container_t;
		container_t con(array);//���z��v�f���������擾
		//container_t con(&array[0], 10);//���v�f���𖾎��I�Ɏ󂯓n�����@
		//char buff[1024];
		//container_t con(buff, sizeof(buff), ring_buffer::AUTO_CLEAR);//�o�b�t�@�ƃo�b�t�@�T�C�Y���󂯓n�����@�{�R���e�i�j�����Ɏ����N���A�����ǉ�
		//                                                             //�i�R���e�i�̃f�X�g���N�^�ŁA�c���Ă���v�f�̃f�X�g���N�^���Ăяo���B�f�t�H���g�͎����N���A�Ȃ��j
		//container_t con;//������ԂŔz��̊��蓖�Ă������ɃR���e�i�𐶐�����ꍇ

		//�ォ��z������蓖�Ă�ꍇ�� assign_array() ���g�p����
		//container_t con;//�f�t�H���g�R���X�g���N�^ ���R���e�i�������ɔz������蓖�ĂȂ�
		//con.assign_array(array);//���z��v�f���������擾
		//con.assign_array(&array[0], 10);//���v�f���𖾎��I�Ɏ󂯓n�����@
		//char buff[1024];
		//con.assign_array(buff, sizeof(buff), ring_buffer::AUTO_CLEAR);//�o�b�t�@�ƃo�b�t�@�T�C�Y���󂯓n�����@�{�R���e�i�j�����Ɏ����N���A�����ǉ�
		//                                                              //�i�R���e�i�̃f�X�g���N�^�ŁA�c���Ă���v�f�̃f�X�g���N�^���Ăяo���B�f�t�H���g�͎����N���A�Ȃ��j

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("offset=%d, size=%d, max_size=%d\n", con.offset(), con.size(), con.max_size());
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
			printf("offset=%d, size=%d, max_size=%d\n", con.offset(), con.size(), con.max_size());
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

		//--------------------------------------------------------------------------------
		//�������O�o�b�t�@�ŗL�̃e�X�g�A�i��������j������ȊO�͓��I�z��̃e�X�g�ƂقƂ�Ǔ���

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
				if (con.push_back(key, val))
					printf("OK\n");
				else
					printf("NG!\n");
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
				data_t val;
				printf("pop_front() ... ");
				if (con.pop_front(val))
					printf("OK [%d:%d]\n", val.m_key, val.m_val);
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

	#if 0
		con.sort(reverse_pred);//�����\�[�g
		printAll();//�S���\��
		con.sort();//�����\�[�g
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
				if (con.push_front(key, val))
					printf("OK\n");
				else
					printf("NG!\n");
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
				data_t val;
				printf("pop_back() ... ");
				if (con.pop_back(val))
					printf("OK [%d:%d]\n", val.m_key, val.m_val);
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

		//10���قǃf�[�^�̊J�n�ʒu�����炷
		{
			for (int i = 0; i < 10; ++i)
			{
				con.push_back(0, 0);
				con.pop_front();
			}
		}

		//--------------------------------------------------------------------------------
		//�������O�o�b�t�@�ŗL�̃e�X�g�A�i�����܂Łj

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
		//std::sort(con.begin(), con.end());//�����\�[�g(STL��)
		//std::stable_sort(con.begin(), con.end());//����\�[�g(STL��)
		printAll();//�S���\��

		//�t���Ƀ\�[�g ���J�X�^���v���f�B�P�[�g�֐����g�p
		printf("\n");
		printf("[custom sort]\n");
		auto reverse_pred = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key > rhs.m_key; };
		con.sort(reverse_pred);//�����\�[�g
		//con.stable_sort(reverse_pred);//����\�[�g
		//std::sort(con.begin(), con.end(), reverse_pred);//�����\�[�g(STL��)
		//std::stable_sort(con.begin(), con.end(), reverse_pred);//����\�[�g(STL��)
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
			if (ite.isExist()) printf("ite:[%d(%d)] key=%d, value=%d\n", ite.getIndex(), ite.getRealIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d(%d)] key=%d, value=%d\n", rite.getIndex(), rite.getRealIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d(%d)] key=%d, value=%d\n", ite_end.getIndex(), ite_end.getRealIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d(%d)] key=%d, value=%d\n", rite_end.getIndex(), rite_end.getRealIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d(%d)] key=%d, value=%d\n", ite2.getIndex(), ite2.getRealIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d(%d)] key=%d, value=%d\n", rite2.getIndex(), rite2.getRealIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d(%d)] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end.getRealIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d(%d)] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end.getRealIndex(), rite2_end->m_key, rite2_end->m_val);
			printf("copy operator\n");
			ite = con.begin();
			rite = con.rbegin();
			ite_end = con.end();
			rite_end = con.rend();
			ite2 = con.rbegin();
			rite2 = con.begin();
			ite2_end = con.rend();
			rite2_end = con.end();
			if (ite.isExist()) printf("ite:[%d(%d)] key=%d, value=%d\n", ite.getIndex(), ite.getRealIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d(%d)] key=%d, value=%d\n", rite.getIndex(), rite.getRealIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d(%d)] key=%d, value=%d\n", ite_end.getIndex(), ite_end.getRealIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d(%d)] key=%d, value=%d\n", rite_end.getIndex(), rite_end.getRealIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d(%d)] key=%d, value=%d\n", ite2.getIndex(), ite2.getRealIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d(%d)] key=%d, value=%d\n", rite2.getIndex(), rite2.getRealIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d(%d)] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end.getRealIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d(%d)] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end.getRealIndex(), rite2_end->m_key, rite2_end->m_val);
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
				if (ite.isExist()) printf("ite:[%d(%d)] key=%d, value=%d\n", ite.getIndex(), ite.getRealIndex(), ite->m_key, ite->m_val);
				if (rite.isExist()) printf("rite:[%d(%d)] key=%d, value=%d\n", rite.getIndex(), rite.getRealIndex(), rite->m_key, rite->m_val);
				if (ite_end.isExist()) printf("ite_end:[%d(%d)] key=%d, value=%d\n", ite_end.getIndex(), ite_end.getRealIndex(), ite_end->m_key, ite_end->m_val);
				if (rite_end.isExist()) printf("rite_end:[%d(%d)] key=%d, value=%d\n", rite_end.getIndex(), rite_end.getRealIndex(), rite_end->m_key, rite_end->m_val);
				if (ite2.isExist()) printf("ite2:[%d(%d)] key=%d, value=%d\n", ite2.getIndex(), ite2.getRealIndex(), ite2->m_key, ite2->m_val);
				if (rite2.isExist()) printf("rite2:[%d(%d)] key=%d, value=%d\n", rite2.getIndex(), rite2.getRealIndex(), rite2->m_key, rite2->m_val);
				if (ite2_end.isExist()) printf("ite2_end:[%d(%d)] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end.getRealIndex(), ite2_end->m_key, ite2_end->m_val);
				if (rite2_end.isExist()) printf("rite2_end:[%d(%d)] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end.getRealIndex(), rite2_end->m_key, rite2_end->m_val);
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
			if (ite.isExist()) printf("ite:[%d(%d)] key=%d, value=%d\n", ite.getIndex(), ite.getRealIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d(%d)] key=%d, value=%d\n", rite.getIndex(), rite.getRealIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d(%d)] key=%d, value=%d\n", ite_end.getIndex(), ite_end.getRealIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d(%d)] key=%d, value=%d\n", rite_end.getIndex(), rite_end.getRealIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d(%d)] key=%d, value=%d\n", ite2.getIndex(), ite2.getRealIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d(%d)] key=%d, value=%d\n", rite2.getIndex(), rite2.getRealIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d(%d)] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end.getRealIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d(%d)] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end.getRealIndex(), rite2_end->m_key, rite2_end->m_val);
			printf("-= 3\n");
			ite -= 3;
			rite -= 3;
			ite_end -= 3;
			rite_end -= 3;
			ite2 -= 3;
			rite2 -= 3;
			ite2_end -= 3;
			rite2_end -= 3;
			if (ite.isExist()) printf("ite:[%d(%d)] key=%d, value=%d\n", ite.getIndex(), ite.getRealIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d(%d)] key=%d, value=%d\n", rite.getIndex(), rite.getRealIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d(%d)] key=%d, value=%d\n", ite_end.getIndex(), ite_end.getRealIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d(%d)] key=%d, value=%d\n", rite_end.getIndex(), rite_end.getRealIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d(%d)] key=%d, value=%d\n", ite2.getIndex(), ite2.getRealIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d(%d)] key=%d, value=%d\n", rite2.getIndex(), rite2.getRealIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d(%d)] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end.getRealIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d(%d)] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end.getRealIndex(), rite2_end->m_key, rite2_end->m_val);
		}
	#endif

		//�������|�b�v(1)
		printf("\n");
		printf("[pop_back(1)]\n");
		{
			data_t* val = con.back();//�����̒l���擾
			printf("back=[%d:%d]\n", val->m_key, val->m_val);
			con.pop_back();//�������폜
			printAll();//�S���\��
		}

		//�������|�b�v(2)
		printf("\n");
		printf("[pop_back(2)]\n");
		{
			data_t val;
			con.pop_back(val);//�l�̃R�s�[���󂯎���Ė������폜
			printf("pop_back:val=[%d:%d]\n", val.m_key, val.m_val);
			printAll();//�S���\��
		}

		//���`����
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

		//�N���A
		printf("\n");
		printf("[clear]\n");
		con.clear();
		printAll();//�S���\��
		//printReverse();//�S���t���\��
	}

	//--------------------
	//�e�X�g�B�F�\�[�g�A�T���̐ݒ��ς���
	//�����I�z��̃e�X�g�ƂقƂ�Ǔ���
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for ring_buffer::container(User defined type with custom operator type)]\n");

		//�z��f�[�^
		data_t array[20];

		//�����O�o�b�t�@�R���e�i����
		typedef ring_buffer::container<another_ope_t> container_t;
		container_t con(array);

		//�R���e�i�̃C���X�^���X�������ɔz���n���Ȃ��ꍇ�́AsertArray() ���g�p����
		//container_t con;
		//con.assign_array(array);

		//10���قǃf�[�^�̊J�n�ʒu�����炷
		{
			for (int i = 0; i < 10; ++i)
			{
				con.push_back(0, 0);
				con.pop_front();
			}
		}

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
			printf("offset=%d, size=%d, max_size=%d\n", con.offset(), con.size(), con.max_size());
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
	//�����I�z��̃e�X�g�ƂقƂ�Ǔ���
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for ring_buffer::container(User defined type for existing data)]\n");

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

		//�ݒ�ς݂̃f�[�^���c�����܂܁A�����O�o�b�t�@�R���e�i�̃f�[�^�Ƃ��Ċ��p
		ring_buffer::container<ope_t> con(array, -1);//�������Ŏg�p���̃f�[�^�T�C�Y���w��i-1�őS��j

		//�R���e�i�̃C���X�^���X�������ɔz���n���Ȃ��ꍇ�́AsertArray() ���g�p����
		//ring_buffer::container<ope_t> con;
		//con.assign_array(array, -1);//�������Ŏg�p���̃f�[�^�T�C�Y���w��i-1�őS��j

		//�f�[�^��\��
		auto printAll = [&con]()
		{
			printf("offset=%d, size=%d, max_size=%d\n", con.offset(), con.size(), con.max_size());
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
	//�����I�z��̃e�X�g�ƂقƂ�Ǔ���
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for ring_buffer::container(User defined type for multi-thread)]\n");

		testThread<ring_buffer::container<ope_t> >("normal container");//���b�N�Ȃ��ł̃X���b�h
		testThread<ring_buffer::container<mt_ope_t> >("multi-thread container");//���b�N����ł̃X���b�h
	}

	//--------------------
	//�e�X�g�E�F��ʓo�^�e�X�g
	//��std::vector��std::deque�ɒu�������������ŁA���I�z��̃e�X�g�ƂقƂ�Ǔ���
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
			printf("[Test for performance ring_buffer]\n");
			
			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//�f�[�^��������
			printf("\n");
			printf("[create container & assign() * %d]\n", TEST_DATA_NUM);
			const std::size_t buff_size = sizeof(data_t)* TEST_DATA_NUM;
			char* buff = new char[buff_size];
			typedef ring_buffer::container<ope_t> container_t;
			container_t* con = new container_t(buff, buff_size, 0, ring_buffer::AUTO_CLEAR);//�R���e�i�����i�o�b�t�@�����蓖�āj
			con->assign(-1, 0, 0);//�S��������
			prev_time = printElapsedTime(prev_time, true);

			//�f�[�^���N���A
			printf("\n");
			printf("[clear() * %d]\n", TEST_DATA_NUM);
			con->clear();
			prev_time = printElapsedTime(prev_time, true);

			//5���قǃf�[�^�̊J�n�ʒu�����炷
			{
				for (int i = 0; i < 5; ++i)
				{
					con->push_back(0, 0);
					con->pop_front();
				}
			}

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

			//�C�e���[�^(1)
			printf("\n");
			printf("[iterator(1)]\n");
			{
				printf_detail("offset=%d, size=%d, max_size=%d\n", con->offset(), con->size(), con->max_size());
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

			//�t���\�[�g
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			con->sort(reverse_sort);
			prev_time = printElapsedTime(prev_time, true);

			//�C�e���[�^(2)
			printf("\n");
			printf("[iterator(2)]\n");
			{
				printf_detail("offset=%d, size=%d, max_size=%d\n", con->offset(), con->size(), con->max_size());
				printf_detail("array=");
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

			//�����\�[�g
			printf("\n");
			printf("[sort]\n");
			con->sort();
			prev_time = printElapsedTime(prev_time, true);

			//���o�[�X�C�e���[�^
			printf("\n");
			printf("[reverse_iterator]\n");
			{
				printf_detail("offset=%d, size=%d, max_size=%d\n", con->offset(), con->size(), con->max_size());
				printf_detail("array=");
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
			printf("[Test for performance std::deque]\n");

			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//�f�[�^��������
			printf("\n");
			printf("[create container & assign() * %d]\n", TEST_DATA_NUM);
			typedef std::deque<data_t> container_t;
			container_t* con = new container_t();//std::deque�R���e�i�𐶐�
			//con->reserve(TEST_DATA_NUM);//std::deque��reserve()�͂Ȃ�
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

			//5���قǃf�[�^�̊J�n�ʒu�����炷
			{
				data_t value(0, 0);
				for (int i = 0; i < 5; ++i)
				{
					con->push_back(value);
					con->pop_front();
				}
			}

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

			//�t���\�[�g
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			std::sort(con->begin(), con->end(), reverse_sort);
			prev_time = printElapsedTime(prev_time, true);

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

			//�����\�[�g
			printf("\n");
			printf("[sort]\n");
			std::sort(con->begin(), con->end());
			prev_time = printElapsedTime(prev_time, true);

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
			delete con;//std::deque�R���e�i��j��
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
//�����I�z��̃e�X�g�ƂقƂ�Ǔ���

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

	//�����O�o�b�t�@�R���e�i����
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
			printf("offset=%d, size=%d, max_size=%d\n", con.offset(), con.size(), con.max_size());
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
