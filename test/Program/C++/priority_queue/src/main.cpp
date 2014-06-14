//--------------------------------------------------------------------------------
//�񕪃q�[�v�e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
static const int TEST_DATA_PRIOR_MIN = 1;//�e�X�g�f�[�^�̍ŏ��v���C�I���e�B
static const int TEST_DATA_PRIOR_MAX = 5;//�e�X�g�f�[�^�̍ő�v���C�I���e�B
static const int TEST_DATA_MAX = 128;//�e�X�g�f�[�^�̍ő�o�^�\��
static const int TEST_DATA_REG_NUM = 20;//�e�X�g�f�[�^�̓o�^��
//static const int TEST_DATA_MAX = 1000000;//�e�X�g�f�[�^�̍ő�o�^�\��
//static const int TEST_DATA_REG_NUM = 1000000;//�e�X�g�f�[�^�̓o�^��

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
//���ʏ���
//--------------------------------------------------------------------------------

#include <type_traits>//C++11 std::is_class, std::conditional�p
#include <utility>//C++11 std::move�p

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
	#if 1//���[�u�I�y���[�^���g�p���ē���ւ��i#include <utility> �� std::swap() �Ɠ����j
		T tmp = std::move(std::move(val2));
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
template<class T>
inline void swapValues(T& val1, T& val2)
{
	std::conditional<std::is_arithmetic<T>::value,
		_swapArithmetic<T>,
		_swapObjects<T>
	>::type::exec(val1, val2);
}

//--------------------------------------------------------------------------------
//�񕪃q�[�v
//--------------------------------------------------------------------------------
//�f�[�^�\���ƃA���S���Y��
//�y�����z
//�E�񕪖؂ł���B
//	  - �m�[�h�̎q�i���E�����j�ɂ́A���g���L�[���������m�[�h��A���B
//	  - �Z��m�[�h�Ԃ̃L�[�̑召�͕s��B
//�E���t�؂ł���B
//	  - �؂̃o�����X�͏�ɕۂ����B
//�E�ȏ�̓����ɂ��A�ł��L�[���傫���m�[�h�̒T�����Ԃ��A���O(1)�ɕۂ����B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y�{�v���O�����ɂ���������v���z
//�E�Œ�z��Ŏ������A��؃������m�ہE�폜�����Ȃ��B
//�E�m�[�h�A���̃|�C���^���g�p���Ȃ��B
//�@��ʓI�ȓ񕪃q�[�v�Ɠ������A�z��̏����Ɋ�Â��ĘA������B
//�E���̓񕪃q�[�v���v���C�I���e�B�L���[�ɗ��p�����ꍇ�A
//�@�f�L���[�ipop�j���ɁA�G���L���[�ipush�j�̏������͕ۏ؂���Ȃ��B
//�@�����̋�����STL�Ɠ����B
//�E�������A�i�񕪃q�[�v������j�v���C�I���e�B�L���[�ł́A�L�[�̔�r��
//�@�v���C�I���e�B�ƃV�[�P���X�ԍ��𕹗p���邱�ƂŁA��������ۏ؂���B
//�ESTL�istd::priority_queue�j�Ƃ̈Ⴂ�͉��L�̒ʂ�
//    - �Œ蒷�z��ł���B�iSTL�͓�����std::vector���g�p���Ă���A�����g������j
//    - �ԍ��؃R���e�i�irb_tree�j�̎����ƍ��킹���\���ɂ��Ă���A
//�@�@  ����p�e���v���[�g�\���̂�p����B
//�@�@  ��STL�Ŏg�p�����r�p�̊֐��I�u�W�F�N�g�N���X(less)�͗p���Ȃ��B
//�@�@- C++11�́u�͈͂Ɋ�Â�for���[�v�v�ƁASTL�́ustd::for_each()�v���g�p�\�B
//�@�@  �P���ɔz��̓��e��񋓂���B
//    - �������̂��߂ɁA�I�u�W�F�N�g�̃R�s�[�𔺂�������A
//      �����I�ȃ��\�b�h�ipushCoping/ popCoping�j�ɂ��Ă���B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y��̓I�Ȋ��p�̑z��z
//�E�C�ӂ̍\���̃v���C�I���e�B�L���[�ɓK�p�B
//--------------------------------------------------------------------------------

#include <cstddef>//std::size_t, std::ptrdiff_t�p
//#include <cstdint>//std::intptr_t�p
#include <iterator>//std::iterator�p
#include <new>//�z�unew,�z�udelete�p

namespace binary_heap
{
	//--------------------
	//�񕪃q�[�v����p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename NODE_TYPE>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public binary_heap::base_ope_t<�h���\����, �m�[�h�^>
	//	struct ope_t : public binary_heap::base_ope_t<ope_t, data_t>
	//	{
	//		//�L�[���r
	//		//��lhs�̕�������������� true ��Ԃ�
	//		inline static bool less(const node_type& lhs, const node_type& rhs)
	//		{
	//			return lhs.m_key < rhs.m_key;
	//		}
	//		
	//		//���b�N�^ ���K�v�ɉ����Ē�`
	//		//�����b�N�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
	//		//�@�L���ȃ��b�N�^�ispin_lock�Ȃǁj�� lock_type �^�Ƃ��Ē�`����B
	//		typedef spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
	//	};
	template<class OPE_TYPE, typename NODE_TYPE>
	struct base_ope_t
	{
		//�^
		typedef OPE_TYPE ope_type;//�m�[�h����^
		typedef NODE_TYPE node_type;//�m�[�h�^

		//���b�N�^
		typedef dummy_lock lock_type;//���b�N�I�u�W�F�N�g�^
		//���f�t�H���g�̓_�~�[�̂��߁A��؃��b�N���䂵�Ȃ��B
		//�����b�N�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
		//�@base_ope_t�̔h���N���X�ɂāA�L���ȃ��b�N�^�ispin_lock �Ȃǁj��
		//�@lock_type �^�Ƃ��čĒ�`����B
		//�y�⑫�z�R���e�i�ɂ́A���炩���߃��b�N����̂��߂̎d�g�݂��\�[�X�R�[�h���x����
		//�@�@�@�@�d����ł��邪�A�L���Ȍ^��^���Ȃ�����́A���s���̃I�[�o�[�w�b�h�͈�؂Ȃ��B

		//�L�[���r
		//��lhs�̕�������������� true ��Ԃ�
		//���h���N���X�ł̎������K�v
		//inline static bool less(const node_type& lhs, const node_type& rhs)

		//STL��std::priority_queue�Ƌ��p���邽�߂̊֐��I�u�W�F�N�g
		inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return ope_type::less(lhs, rhs); }

		//�f�X�g���N�^�Ăяo��
		inline static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type; \
		typedef typename ope_type::lock_type lock_type;
	//--------------------
	//�񕪃q�[�v����֐��F�e�̃C���f�b�N�X�v�Z
	inline static std::size_t calcParent(const std::size_t index){ return (index - 1) >> 1; }
	//--------------------
	//�񕪃q�[�v����֐��F�q�̃C���f�b�N�X�v�Z
	inline static std::size_t calcChildL(const std::size_t index){ return (index << 1) + 1; }
	inline static std::size_t calcChildR(const std::size_t index){ return calcChildL(index) + 1; }
	//--------------------
	//�񕪃q�[�v����֐��F�A�b�v�q�[�v
	//���m�[�h������Ɉړ�
	template<class OPE_TYPE, class PREDICATE>
	static typename OPE_TYPE::node_type* upHeap(typename OPE_TYPE::node_type* top, const std::size_t size, typename OPE_TYPE::node_type* now, PREDICATE less)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		std::ptrdiff_t index = now - top;
		std::ptrdiff_t _size = static_cast<std::ptrdiff_t>(size);
		if (index < 0 || index >= _size)
			return nullptr;
		while (index != 0)
		{
			index = calcParent(index);
			node_type* parent = top + index;
			if (!less(*parent, *now))
				break;
			swapValues(*parent, *now);
			now = parent;
		}
		return now;
	}
	//--------------------
	//�񕪃q�[�v����֐��F�_�E���q�[�v
	//���m�[�h�������Ɉړ�
	template<class OPE_TYPE, class PREDICATE>
	static typename OPE_TYPE::node_type* downHeap(typename OPE_TYPE::node_type* top, const std::size_t size, typename OPE_TYPE::node_type* now, PREDICATE less)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		std::ptrdiff_t index = now - top;
		std::ptrdiff_t _size = static_cast<std::ptrdiff_t>(size);
		if (index < 0 || index >= _size)
			return nullptr;
		while (true)
		{
			index = calcChildL(index);
			if (index >= _size)
				break;
			node_type* child = top + index;
			node_type* child_r = child + 1;
			bool is_swap = false;
			if (index + 1 < _size && !less(*child_r, *child) && !less(*child_r, *now))
			{
				is_swap = true;
				child = child_r;
				++index;
			}
			else if (!less(*child, *now))
			{
				is_swap = true;
			}
			if (!is_swap)
				break;
			swapValues(*child, *now);
			now = child;
		}
		return now;
	}
	
	//----------------------------------------
	//�񕪃q�[�v�R���e�i
	//���Œ�z��Ǝg�p���̗v�f��������
	//��std::vector��std::priority_queue����ɂ����悤�ȃR���e�i�B
	//�@�Ȃ��Aemplace()���\�b�h�ɂ͔�Ή��B
	//���f�[�^�̃R�s�[������ď������������コ���邽�߂ɁA
	//�@pushBegin()�`pushEnd()�ApopBegin()�`popEnd()
	//�@�Ƃ������\�b�h��p�ӂ��Ă���B�����̃o�b�t�@�𒼐ڎQ�Ƃ���̂ō����B
	//�@�Ȃ��Abegin�`end �̊Ԃ̓��b�N���s����_�ɒ��ӁB
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	class container
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//�萔
		static const size_type TABLE_SIZE = _TABLE_SIZE;//�z��v�f��
		static const index_type INVALID_INDEX = 0xffffffffu;//�����ȃC���f�b�N�X
		enum status_t//�X�e�[�^�X
		{
			IDLE = 0,//�A�C�h��
			PUSH_BEGINNING,//�v�b�V���J�n��
			PUSH_ENDED,//�v�b�V���I������
			PUSH_CANCELLED,//�v�b�V����������
			POP_BEGINNING,//�|�b�v�J�n��
			POP_ENDED,//�|�b�v�I������
			POP_CANCELLED,//�|�b�v��������
		};
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
			inline bool isExist() const { return m_index != INVALID_INDEX && m_index < m_con->m_used; }
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
				//if (index == INVALID_INDEX || index < 0 || index > static_cast<index_type>(m_con->m_used))
				if (index > static_cast<index_type>(m_con->m_used))
				{
					m_index = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_index = index;
					m_value = const_cast<value_type*>(m_con->_ref_node(m_index));
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
					update(m_con->m_used);//�����f�[�^
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
				ite.update(m_con->m_used - index);
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(*m_con, false);
				ite.update(m_con->m_used - index);
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
				m_value = rhs.m_value;
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
				m_value = rhs.m_value;
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
			inline const value_type* getValue() const { return m_value - 1; }//���݂̒l
			inline value_type* getValue(){ return m_value - 1; }//���݂̒l
		private:
			//���\�b�h
			void update(const index_type index) const
			{
				//if (index == INVALID_INDEX || index < 0 || index > static_cast<index_type>(m_con->m_used))
				if (index > static_cast<index_type>(m_con->m_used))
				{
					m_index = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_index = index;
					m_value = const_cast<value_type*>(m_con->_ref_node(m_index));
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
				m_value(obj.m_value)
			{}
			//�R�s�[�R���X�g���N�^
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			//�R���X�g���N�^
			inline reverse_iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				if (!is_end)
					update(m_con->m_used);//�����f�[�^
				else
					update(0);//�擪�f�[�^
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
		inline const node_type* at(const int index) const { return ref_node(index); }
		inline node_type* at(const int index){ return ref_node(index); }
		inline const node_type* operator[](const int index) const { return ref_node(index); }
		inline node_type* operator[](const int index){ return ref_node(index); }
		inline status_t status() const { return m_status; }
	public:
		//�L���X�g�I�y���[�^
		inline operator lock_type&(){ return m_lock; }//���L���b�N�I�u�W�F�N�g
		inline operator lock_type&() const { return m_lock; }//���L���b�N�I�u�W�F�N�g ��mutable
	public:
		//���\�b�h
		inline size_type max_size() const { return TABLE_SIZE; }//�ő�v�f�����擾
		inline size_type capacity() const { return TABLE_SIZE; }//�ő�v�f�����擾
		inline size_type size() const { return m_used; }//�g�p���̗v�f�����擾
		inline bool empty() const { return m_used == 0; }//�󂩁H
	public:
		int depth_max() const//�ő�̐[�����擾
		{
			if (m_used == 0)
				return -1;
			int depth = 0;
			int used = m_used >> 1;
			while (used != 0)
			{
				++depth;
				used >>= 1;
			}
			return depth;
		}
	private:
		inline const node_type* _ref_node(const int index) const { return reinterpret_cast<const node_type*>(&m_table[index]); }//�m�[�h�Q��
		inline const node_type* _ref_top() const { return _ref_node(0); }//�擪�m�[�h�Q��
		inline const node_type* _ref_bottom() const { return _ref_node(m_used - 1); }//�I�[�m�[�h�Q��
		inline const node_type* _ref_new() const { return _ref_node(m_used); }//�V�K�m�[�h�Q��
		inline node_type* _ref_node(const int index){ return reinterpret_cast<node_type*>(&m_table[index]); }//�m�[�h�Q��
		inline node_type* _ref_top(){ return _ref_node(0); }//�擪�m�[�h�Q��
		inline node_type* _ref_bottom(){ return _ref_node(m_used - 1); }//�I�[�m�[�h�Q��
		inline node_type* _ref_new(){ return _ref_node(m_used); }//�V�K�m�[�h�Q��
	public:
		inline const node_type* ref_node(const int index) const { return index >= 0 && index < static_cast<int>(m_used) ? _ref_node(index) : nullptr; }//�m�[�h�Q��
		inline const node_type* ref_top() const { return m_used == 0 ? nullptr : _ref_top(); }//�擪�m�[�h�Q��
		inline const node_type* ref_bottom() const { return m_used == 0 ? nullptr : _ref_bottom(); }//�I�[�m�[�h�Q��
		inline const node_type* ref_new() const { return m_used == TABLE_SIZE ? nullptr : _ref_new(); }//�V�K�m�[�h�Q��
		inline node_type* ref_node(const int index){ return  const_cast<node_type*>(const_cast<const container*>(this)->ref_node()); }//�m�[�h�Q��
		inline node_type* ref_top(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_top()); }//�擪�m�[�h�Q��
		inline node_type* ref_bottom(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_bottom()); }//�I�[�m�[�h�Q��
		inline node_type* ref_new(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_new()); }//�V�K�m�[�h�Q��
	private:
		inline int _adj_index(const int index) const { return index >= 0 && index < TABLE_SIZE ? index : -1; }//�C���f�b�N�X��͈͓��ɕ␳
		inline int _ref_index(const node_type* node) const{ return node - _ref_top(); }//�m�[�h���C���f�b�N�X�ɕϊ� ���͈̓`�F�b�N�Ȃ�
		inline int _calc_parent(const int index) const { return binary_heap::calcParent(index); }//�e�C���f�b�N�X�v�Z ���͈̓`�F�b�N�Ȃ�
		inline int _calc_child_l(const int index) const { return binary_heap::calcChildL(index); }//�����̎q�C���f�b�N�X�v�Z ���͈̓`�F�b�N�Ȃ�
		inline int _calc_child_r(const int index) const { return binary_heap::calcChildR(index); }//�E���̎q�C���f�b�N�X�v�Z ���͈̓`�F�b�N�Ȃ�
	public:
		inline int ref_index(const node_type* node) const{ return _adj_index(_ref_index(node)); }//�m�[�h���C���f�b�N�X�ɕϊ�
		inline int calc_parent(const int index) const { return _adj_index(_calc_parent(index)); }//�e�C���f�b�N�X�v�Z
		inline int calc_child_l(const int index) const { return _adj_index(_calc_child_l(index)); }//�����̎q�C���f�b�N�X�v�Z
		inline int calc_child_r(const int index) const { return _adj_index(_calc_child_r(index)); }//�E���̎q�C���f�b�N�X�v�Z
		inline int calc_child(const int index, const bool is_right) const { return is_right ? calc_child_r(index) : calc_child_l(index); }//�q�C���f�b�N�X�v�Z
		inline const node_type* ref_parent(const node_type* node) const { return ref_node(_calc_parent(_ref_index(node))); }//�e�m�[�h�Q��
		inline const node_type* ref_child_l(const node_type* node) const { return ref_node(_calc_child_l(_ref_index(node))); }//�����̎q�m�[�h�Q��
		inline const node_type* ref_child_r(const node_type* node) const { return ref_node(_calc_child_r(_ref_index(node))); }//�����̎q�m�[�h�Q��
		inline const node_type* ref_child(const node_type* node, const bool is_right) const { return is_right ? ref_child_r(node) : ref_child_l(node); }//�q�m�[�h�Q��
		inline node_type* ref_parent(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_parent(index)); }//�e�m�[�h�Q��
		inline node_type* ref_child_l(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child_l(index)); }//�����̎q�m�[�h�Q��
		inline node_type* ref_child_r(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child_r(index)); }//�����̎q�m�[�h�Q��
		inline node_type* ref_child(const int index, const bool is_right){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child(index, is_right)); }//�q�m�[�h�Q��
	public:
		inline const node_type* top() const { return ref_top(); }//�擪�m�[�h�Q��
		inline node_type* top(){ return ref_top(); }//�擪�m�[�h�Q��
		inline bool less(const node_type& lhs, const node_type& rhs) const { return ope_type::less(lhs, rhs); }//�L�[��r
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
	private:
		//�v�b�V���i�{�́j�F���[�u
		node_type* _pushCopying(const node_type&& src)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			*obj = std::move(src);
			m_status = PUSH_BEGINNING;
			return pushEnd();
		}
		//�v�b�V���i�{�́j�F�R�s�[
		node_type* _pushCopying(const node_type& src)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			*obj = src;
			m_status = PUSH_BEGINNING;
			return pushEnd();
		}
	public:
		//�v�b�V��
		//���I�u�W�F�N�g�n��
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ��Ӂi�����x���Ȃ�j
		//�����[�u�I�y���[�^���g�p���ăR�s�[����_�ɒ���
		//���������A���b�N���擾����
		inline node_type* pushCopying(const node_type&& src)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _pushCopying(std::move(src));
		}
		inline node_type* pushCopying(const node_type& src)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _pushCopying(src);
		}
	private:
		//�v�b�V���i�{�́j
		template<typename... Tx>
		node_type* _push(Tx... args)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = pushBegin(args...);
			if (!obj)
				return nullptr;
			return pushEnd();
		}
	public:
		//�v�b�V��
		//���p�����[�^�n��
		//���I�u�W�F�N�g�̃R���X�g���N�^���Ăяo�����
		//���������A���b�N���擾����
		template<typename... Tx>
		inline node_type* push(Tx... args)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _push(args...);
		}
	private:
		//�v�b�V���J�n�i�{�́j
		template<typename... Tx>
		node_type* _pushBegin(Tx... args)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			obj = new(obj)node_type(args...);//�R���X�g���N�^�Ăяo��
			if (obj)
				m_status = PUSH_BEGINNING;
			return obj;
		}
	public:
		//�v�b�V���J�n
		//���󂫃m�[�h���擾���A�R���X�g���N�^���Ăяo�����
		//����������������ƁA���b�N���擾������ԂɂȂ�ipushEnd�ŉ������j
		template<typename... Tx>
		inline node_type* pushBegin(Tx... args)
		{
			m_lock.lock();//���b�N���擾�i���̂܂܊֐��𔲂���j
			node_type* obj = _pushBegin(args...);//�v�b�V���J�n
			if (!obj)
				m_lock.unlock();//�v�b�V�����s���̓��b�N���
			return obj;
		}
	private:
		//�v�b�V���I���i�{�́j
		node_type* _pushEnd()
		{
			if (m_status != PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			++m_used;
			m_status = PUSH_ENDED;
			//���[�̗t�m�[�h�Ƃ��ēo�^���ꂽ�V�K�m�[�h������Ɉړ�
			return upHeap(obj);
		}
	public:
		//�v�b�V���I��
		//���ǉ������V�K�m�[�h����Ɉړ�
		//��pushBegin�Ŏ擾�������b�N���������
		inline node_type* pushEnd()
		{
			const bool unlock = (m_status == PUSH_BEGINNING);//�v�b�V���J�n���Ȃ�A�����b�N����
			node_type* new_obj = _pushEnd();//�v�b�V���I��
			if (unlock)
				m_lock.unlock();//���b�N���
			return new_obj;
		}
	private:
		//�v�b�V���������i�{�́j
		bool _pushCancel()
		{
			if (m_status != PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_status = PUSH_CANCELLED;
			return true;
		}
	public:
		//�v�b�V��������
		//��pushBegin�Ŏ擾�������b�N���������
		inline bool pushCancel()
		{
			const bool unlock = (m_status == PUSH_BEGINNING);//�v�b�V���J�n���Ȃ�A�����b�N����
			const bool result = _pushCancel();//�v�b�V��������
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
	private:
		//�|�b�v�i�{�́j
		bool _popCopying(node_type& dst)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return false;
			const node_type* obj = popBegin();
			if (!obj)
				return false;
			dst = *obj;
			return popEnd();
		}
	public:
		//�|�b�v
		//���I�u�W�F�N�g�̃R�s�[���󂯎��̈��n��
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo����� ���R�s�[��Ɏ��s
		//���������A���b�N���擾����
		inline bool popCopying(node_type& dst)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _popCopying(dst);
		}
	private:
		//�|�b�v�J�n�i�{�́j
		node_type* _popBegin()
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_top();
			if (obj)
				m_status = POP_BEGINNING;
			return obj;
		}
	public:
		//�|�b�v�J�n
		//�����m�[�h�擾
		//����������������ƁA���b�N���擾������ԂɂȂ�ipopEnd�ŉ������j
		node_type* popBegin()
		{
			m_lock.lock();//���b�N���擾�i���̂܂܊֐��𔲂���j
			node_type* obj = _popBegin();//�|�b�v�J�n
			if (!obj)
				m_lock.unlock();//�v�b�V�����s���̓��b�N���
			return obj;
		}
	private:
		//�|�b�v�I���i�{�́j
		bool _popEnd()
		{
			if (m_status != POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			node_type* obj = ref_bottom();
			if (!obj)
				return false;
			ope_type::callDestructor(obj);//�f�X�g���N�^�Ăяo��
			operator delete(obj, obj);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			m_status = POP_ENDED;
			//���m�[�h���|�b�v���ꂽ�̂ŁA���[�̗t�m�[�h�����m�[�h�ɏ㏑��������ŁA����������Ɉړ�
			node_type* top_obj = _ref_top();
			*top_obj = std::move(*obj);
			--m_used;
			downHeap(top_obj);
			return true;
		}
	public:
		//�|�b�v�I��
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo�����
		//���폜�������m�[�h�̌��Ԃ𖄂߂邽�߂ɁA�ȍ~�̃m�[�h����Ɉړ�
		//��popBegin�Ŏ擾�������b�N���������
		inline bool popEnd()
		{
			const bool unlock = (m_status == POP_BEGINNING);//�|�b�v�J�n���Ȃ�A�����b�N����
			const bool result = _popEnd();//�|�b�v�I��
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
	private:
		//�|�b�v�������i�{�́j
		bool _popCancel()
		{
			if (m_status != POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_status = POP_CANCELLED;
			return true;
		}
	public:
		//�|�b�v������
		//��popBegin�Ŏ擾�������b�N���������
		inline bool popCancel()
		{
			const bool unlock = (m_status == POP_BEGINNING);//�|�b�v�J�n���Ȃ�A�����b�N����
			const bool result = _popCancel();//�|�b�v������
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
	public:
		//�m�[�h������Ɉړ�
		//�����b�N���擾���Ȃ��ŏ�������̂Œ��ӁI
		//�@�i�Ǐ��I�ȃ��b�N�ōςޏ����ł͂Ȃ����߁j
		//�@�K���Ăяo�����Ń��b�N���擾���邱�ƁI
		node_type* upHeap(node_type* obj)
		{
			return binary_heap::upHeap<ope_type>(_ref_top(), m_used, obj, ope_type::less);
		}
		//�m�[�h�������Ɉړ�
		//�����b�N���擾���Ȃ��ŏ�������̂Œ��ӁI
		//�@�i�Ǐ��I�ȃ��b�N�ōςޏ����ł͂Ȃ����߁j
		//�@�K���Ăяo�����Ń��b�N���擾���邱�ƁI
		node_type* downHeap(node_type* obj)
		{
			return binary_heap::downHeap<ope_type>(_ref_top(), m_used, obj, ope_type::less);
		}
	private:
		//�N���A�i�{�́j
		void _clear()
		{
			if (m_used == 0)
				return;
			node_type* obj_end = _ref_top() + m_used;
			for (node_type* obj = _ref_top(); obj < obj_end; ++obj)
			{
				ope_type::callDestructor(obj);//�f�X�g���N�^�Ăяo��
				operator delete(obj, obj);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			}
			m_used = 0;
		}
	public:
		//�N���A
		//���������A���b�N���擾����
		inline void clear()
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			_clear();
		}
	public:
		//�R���X�g���N�^
		container() :
			m_used(0),
			m_status(IDLE)
		{}
		//�f�X�g���N�^
		~container()
		{
			pushCancel();//�v�b�V��������
			popCancel();//�|�b�v������
		}
	private:
		//�t�B�[���h
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//�f�[�^�e�[�u��
		size_type m_used;//�g�p��
		status_t m_status;//�X�e�[�^�X
		mutable lock_type m_lock;//���b�N�I�u�W�F�N�g
	};
	//�C�e���[�^�̃��[�u�I�y���[�^
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	//typename container<OPE_TYPE, _TABLE_SIZE>::iterator& container<OPE_TYPE, _TABLE_SIZE>::iterator::operator=(typename container<OPE_TYPE, _TABLE_SIZE>::const_reverse_iterator&& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE, _TABLE_SIZE>::iterator& container<OPE_TYPE, _TABLE_SIZE>::iterator::operator=(const typename container<OPE_TYPE, _TABLE_SIZE>::reverse_iterator&& rhs)//VC++��OK
	{
		m_con = rhs.m_con;
		m_index = rhs.m_index;
		m_value = rhs.m_value;
		return *this;
	}
	//�C�e���[�^�̃R�s�[�I�y���[�^
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	//typename container<OPE_TYPE, _TABLE_SIZE>::iterator& container<OPE_TYPE, _TABLE_SIZE>::iterator::operator=(typename container<OPE_TYPE, _TABLE_SIZE>::const_reverse_iterator& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE, _TABLE_SIZE>::iterator& container<OPE_TYPE, _TABLE_SIZE>::iterator::operator=(const typename container<OPE_TYPE, _TABLE_SIZE>::reverse_iterator& rhs)//VC++��OK
	{
		m_con = rhs.m_con;
		m_index = rhs.m_index;
		m_value = rhs.m_value;
		return *this;
	}
	//�C�e���[�^�̃��[�u�R���X�g���N�^
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	//container<OPE_TYPE, _TABLE_SIZE>::iterator::iterator(typename container<OPE_TYPE, _TABLE_SIZE>::const_reverse_iterator&& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE, _TABLE_SIZE>::iterator::iterator(const typename container<OPE_TYPE, _TABLE_SIZE>::reverse_iterator&& obj) ://VC++��OK
		m_con(obj.m_con),
		m_index(obj.m_index),
		m_value(obj.m_value)
	{}
	//�C�e���[�^�̃R�s�[�R���X�g���N�^
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	//container<OPE_TYPE, _TABLE_SIZE>::iterator::iterator(typename container<OPE_TYPE, _TABLE_SIZE>::const_reverse_iterator& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE, _TABLE_SIZE>::iterator::iterator(const typename container<OPE_TYPE, _TABLE_SIZE>::reverse_iterator& obj) ://VC++��OK
		m_con(obj.m_con),
		m_index(obj.m_index),
		m_value(obj.m_value)
	{}
	//--------------------
	//���S�ȃv�b�V���^�|�b�v����N���X
	//�������Ԃ��L�����A�f�X�g���N�^�ŕK������������
	template<class CON>
	class operation_guard
	{
	public:
		//�^
		typedef CON container_type;//�R���e�i�^
		typedef typename CON::node_type node_type;//�m�[�h�^
		typedef typename CON::status_t status_t;//�X�e�[�^�X�^
	public:
		//�A�N�Z�b�T
		status_t status() const { return m_status; }//�X�e�[�^�X���擾
	public:
		//�v�b�V���J�n
		template<typename... Tx>
		node_type* pushBegin(Tx... args)
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.pushBegin(args...);//�v�b�V���J�n
			if (node)
				m_status = status_t::PUSH_BEGINNING;//�X�e�[�^�X�ύX
			return node;
		}
		//�v�b�V���I��
		node_type* pushEnd()
		{
			if (m_status != status_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.pushEnd();//�v�b�V���I��
			m_status = status_t::PUSH_ENDED;//�X�e�[�^�X�ύX
			return node;
		}
		//�v�b�V��������
		bool pushCancel()
		{
			if (m_status != status_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_container.pushCancel();//�v�b�V��������
			m_status = status_t::PUSH_CANCELLED;//�X�e�[�^�X�ύX
			return true;
		}
		//�|�b�v�J�n
		node_type* popBegin()
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.popBegin();//�|�b�v�J�n
			if (node)
				m_status = status_t::POP_BEGINNING;//�X�e�[�^�X�ύX
			return node;
		}
		//�|�b�v�I��
		bool popEnd()
		{
			if (m_status != status_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			const bool result = m_container.popEnd();//�|�b�v�I��
			m_status = status_t::POP_ENDED;//�X�e�[�^�X�ύX
			return result;
		}
		//�|�b�v������
		bool popCancel()
		{
			if (m_status != status_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_container.popCancel();//�|�b�v������
			m_status = status_t::POP_CANCELLED;//�X�e�[�^�X�ύX
			return true;
		}
	public:
		//�R���X�g���N�^
		operation_guard(container_type& container) :
			m_container(container),
			m_status(status_t::IDLE)
		{}
		//�f�X�g���N�^
		~operation_guard()
		{
			pushEnd();//�v�b�V���I��
			popEnd();//�|�b�v�I��
		}
	private:
		//�t�B�[���h
		container_type& m_container;//�R���e�i
		status_t m_status;//�X�e�[�^�X
	};
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace binary_heap

//--------------------------------------------------------------------------------
//�v���C�I���e�B�L���[
//���v���C�I���e�B�ƂƂ��ɁA�V�[�P���X�ԍ����������ƂŁA�L���[�C���O�̏�������ۏ؂���B
//--------------------------------------------------------------------------------

#include <utility>//C++11 std::move�p

namespace priority_queue
{
	//--------------------
	//�v���C�I���e�B�L���[����p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename NODE_TYPE, int _NODES_MAX>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public priority_queue::base_ope_t<�h���\����, �m�[�h�^, �D��x�^, �V�[�P���X�ԍ��^>
	//	struct ope_t : public priority_queue::base_ope_t<ope_t, data_t, int, unsigned int>
	//	{
	//		//�D��x���擾
	//		inline static priority_type getPriority(const node_type& node){ return node.m_priority; }
	//		//�D��x���X�V
	//		inline static void setPriority(node_type& node, const priority_type priority){ node.m_priority = priority; }
	//		
	//		//�V�[�P���X�ԍ����擾
	//		inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//		//�V�[�P���X�ԍ����X�V
	//		inline static void setSeqNo(node_type& node, const seq_type seq_no) const { node.m_seqNo = seq_no; }
	//		
	//		//�D��x���r ���K�v�ɉ����Ē�`
	//		inline static int compareProior(const priority_type lhs, const priority_type rhs){ return ???; }
	//		
	//		//���b�N�^ ���K�v�ɉ����Ē�`
	//		//�����b�N�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
	//		//�@�L���ȃ��b�N�^�ispin_lock�Ȃǁj�� lock_type �^�Ƃ��Ē�`����B
	//		typedef spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, typename PRIOR_TYPE = int, typename SEQ_TYPE = unsigned int>
	struct base_ope_t
	{
		//�^
		typedef OPE_TYPE ope_type;//�m�[�h����^
		typedef NODE_TYPE node_type;//�m�[�h�^
		typedef PRIOR_TYPE priority_type;//�D��x�^
		typedef SEQ_TYPE seq_type;//�V�[�P���X�ԍ��^
		
		//���b�N�^
		typedef dummy_lock lock_type;//���b�N�I�u�W�F�N�g�^
		//���f�t�H���g�̓_�~�[�̂��߁A��؃��b�N���䂵�Ȃ��B
		//�����b�N�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
		//�@base_ope_t�̔h���N���X�ɂāA�L���ȃ��b�N�^�ispin_lock �Ȃǁj��
		//�@lock_type �^�Ƃ��čĒ�`����B
		//�y�⑫�z�R���e�i�ɂ́A���炩���߃��b�N����̂��߂̎d�g�݂��\�[�X�R�[�h���x����
		//�@�@�@�@�d����ł��邪�A�L���Ȍ^��^���Ȃ�����́A���s���̃I�[�o�[�w�b�h�͈�؂Ȃ��B

		//�V�[�P���X�ԍ����r
		inline static bool lessSeqNo(const seq_type lhs, const seq_type rhs)
		{
			return lhs > rhs;
		}

		//�D��x���r
		//���f�t�H���g
		//Return value:
		//  0     ... lhs == rhs
		//  1�ȏ� ... lhs > rhs
		// -1�ȉ� ... lhs < rhs
		inline static int comparePriority(const priority_type lhs, const priority_type rhs)
		{
			return static_cast<int>(lhs)-static_cast<int>(rhs);
		}

		//�L�[���r
		//��lhs�̕�������������� true ��Ԃ�
		inline static bool _lessSeqNo(const int compare_priority, const seq_type lhs, const seq_type rhs)
		{
			return compare_priority < 0 ? true : compare_priority > 0 ? false : ope_type::lessSeqNo(lhs, rhs);
		}
		inline static bool less(const node_type& lhs, const node_type& rhs)
		{
			return _lessSeqNo(ope_type::comparePriority(ope_type::getPriority(lhs), ope_type::getPriority(rhs)), ope_type::getSeqNo(lhs), ope_type::getSeqNo(rhs));
		}

		//STL��std::priority_queue�Ƌ��p���邽�߂̊֐��I�u�W�F�N�g
		inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return ope_type::less(lhs, rhs); }

		//�f�X�g���N�^�Ăяo��
		static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }

		//�R���e�i����^
		struct container_ope_type
		{
			typedef OPE_TYPE adapter_ope_type;//�R���e�i�A�_�v�^�̃m�[�h����^
			typedef container_ope_type ope_type;//�m�[�h����^
			typedef NODE_TYPE node_type;//�m�[�h�^
			
			//�L�[���r
			//��lhs�̕�������������� true ��Ԃ�
			inline static bool less(const node_type& lhs, const node_type& rhs)
			{
				return adapter_ope_type::less(lhs, rhs);
			}

			//STL��std::priority_queue�Ƌ��p���邽�߂̊֐��I�u�W�F�N�g
			inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return adapter_ope_type::less(lhs, rhs); }

			//�f�X�g���N�^�Ăяo��
			static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
			
			//���b�N�^
			typedef dummy_lock lock_type;//���b�N�I�u�W�F�N�g�^
			//���R���e�i���ł̃��b�N�͎g�p���Ȃ�
		};
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef typename ope_type::priority_type priority_type; \
		typedef typename ope_type::seq_type seq_type; \
		typedef typename ope_type::lock_type lock_type;
	//----------------------------------------
	//�v���C�I���e�B�L���[�R���e�i�A�_�v�^
	//���R���e�i�̃f�t�H���g�͓񕪃q�[�v�ibinary_heap::container�j�B
	//�@�����C���^�[�t�F�[�X���������N���X�Ȃ�A�u�������Ďg�p�\�B
	//��std::priority_queue�Ƃ͂��܂�݊������Ȃ��A�C�e���[�^�ɂ��Ή����Ȃ�
	//���C�e���[�^���K�v�Ȃ�Acontainer_adapter::container_type �ɃL���X�g����
	//�@�R���e�i�����o���Α���\�B
	//���f�[�^�̃R�s�[������ď������������コ���邽�߂ɁA
	//�@enqueueBegin()�`enqueueEnd()�AdequeueBegin()�`dequeueEnd()
	//�@�Ƃ������\�b�h��p�ӂ��Ă���B�����̃o�b�t�@�𒼐ڎQ�Ƃ���̂ō����B
	//�@�Ȃ��Abegin�`end �̊Ԃ̓��b�N���s����_�ɒ��ӁB
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, class CONTAINER_TYPE = binary_heap::container<typename OPE_TYPE::container_ope_type, _TABLE_SIZE> >
	class container_adapter
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
		typedef CONTAINER_TYPE container_type;//�R���e�i�^
		typedef typename container_type::status_t status_t;//�X�e�[�^�X�^
	public:
		//�A�N�Z�b�T
		inline const container_type& getContainer() const { return m_container; }//�R���e�i�擾
		inline container_type& getContainer(){ return m_container; }//�R���e�i�擾
	public:
		//�L���X�g�I�y���[�^
		inline operator const container_type&() const{ return m_container; }//�R���e�i��Ԃ�
		inline operator container_type&(){ return m_container; }//�R���e�i��Ԃ�
		inline operator lock_type&(){ return m_lock; }//���L���b�N�I�u�W�F�N�g
		inline operator lock_type&() const { return m_lock; }//���L���b�N�I�u�W�F�N�g ��mutable
	public:
		//���\�b�h
		inline size_type max_size() const { return m_container.max_aize(); }//�ő�v�f�����擾
		inline size_type capacity() const { return m_container.capacity(); }//�ő�v�f�����擾
		inline size_type size() const { return m_container.size(); }//�g�p���̗v�f�����擾
		inline bool empty() const { return m_container.empty(); }//�󂩁H
	private:
		//�V�[�P���X�ԍ����s
		inline seq_type getNextSeqNo(){ return m_seqNo++; }
		//�\�Ȃ�V�[�P���X�ԍ������Z�b�g
		inline void checkAndResetSeqNo()
		{
			if (m_container.empty())
				m_seqNo = 0;
		}
	private:
		//�G���L���[�i�{�́j�F���[�u
		node_type* _enqueueCopying(const node_type&& obj)
		{
			if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type obj_tmp(std::move(obj));//�ꎞ�I�u�W�F�N�g�Ƀ��[�u
			ope_type::setSeqNo(obj_tmp, getNextSeqNo());//�V�[�P���X�ԍ����Z�b�g
			return m_container.pushCopying(std::move(obj_tmp));//�R���e�i�Ƀv�b�V���i���[�u�j
		}
		//�G���L���[�i�{�́j�F�R�s�[
		node_type* _enqueueCopying(const node_type& obj)
		{
			if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type obj_tmp(obj);//�ꎞ�I�u�W�F�N�g�ɃR�s�[
			ope_type::setSeqNo(obj_tmp, getNextSeqNo());//�V�[�P���X�ԍ����Z�b�g
			return m_container.pushCopying(std::move(obj_tmp));//�R���e�i�Ƀv�b�V���i���[�u�j
		}
	public:
		//�G���L���[
		//���I�u�W�F�N�g�n��
		//���I�u�W�F�N�g�ɂ́A���炩���ߗD��x��ݒ肵�Ă����K�v������
		//���I�u�W�F�N�g�̃R�s�[���Q�񔭐�����_�ɒ��Ӂi�����x���Ȃ�j
		//�@�i�V�[�P���X�ԍ����Z�b�g���邽�߂�1��e���|�����ɃR�s�[���A�v�b�V�����ɂ���ɃR�s�[����B�j
		//�����[�u�R���X�g���N�^�ƃ��[�u�I�y���[�^���g�p���ăR�s�[����_�ɒ���
		//���������A���b�N���擾����
		inline node_type* enqueueCopying(const node_type&& obj)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _enqueueCopying(std::move(obj));
		}
		inline node_type* enqueueCopying(const node_type& obj)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _enqueueCopying(obj);
		}
	private:
		//�G���L���[�i�{�́j
		template<typename... Tx>
		node_type* _enqueue(const priority_type priority, Tx... args)
		{
			//if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
			//	return nullptr;
			node_type* obj = m_container.pushBegin(args...);//�R���e�i�Ƀv�b�V���J�n
			if (!obj)
				return nullptr;
			ope_type::setPriority(*obj, priority);//�D��x��ݒ�
			ope_type::setSeqNo(*obj, getNextSeqNo());//�V�[�P���X�ԍ����Z�b�g
			obj = m_container.pushEnd();//�R���e�i�Ƀv�b�V���I��
			return obj;
		}
	public:
		//�G���L���[
		//���p�����[�^�n��
		//���I�u�W�F�N�g�̃R���X�g���N�^���Ăяo�����
		//���I�u�W�F�N�g�ɂ́A�V�[�P���X�ԍ����������܂��
		//���������A���b�N���擾����
		template<typename... Tx>
		inline node_type* enqueue(const priority_type priority, Tx... args)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _enqueue(priority, args...);
		}
	private:
		//�G���L���[�J�n�i�{�́j
		template<typename... Tx>
		node_type* _enqueueBegin(const priority_type priority, Tx... args)
		{
			//if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
			//	return nullptr;
			node_type* obj = m_container.pushBegin(args...);//�R���e�i�Ƀv�b�V���J�n
			if (!obj)
				return nullptr;
			ope_type::setPriority(*obj, priority);//�D��x��ݒ�
			ope_type::setSeqNo(*obj, getNextSeqNo());//�V�[�P���X�ԍ���ݒ�
			return obj;
		}
	public:
		//�G���L���[�J�n
		//���󂫃L���[�擾
		//���G���L���[�������� enqueueEnd ���Ăяo���K�v����
		//�����̎��_�ŁA�D��x�ƃV�[�P���X�ԍ����������܂��
		//����������������ƁA���b�N���擾������ԂɂȂ�ienqueueEnd�ŉ������j
		template<typename... Tx>
		inline node_type* enqueueBegin(const priority_type priority, Tx... args)
		{
			m_lock.lock();//���b�N���擾�i���̂܂܊֐��𔲂���j
			node_type* obj = _enqueueBegin(args...);//�G���L���[�J�n
			if (!obj)
				m_lock.unlock();//�v�b�V�����s���̓��b�N���
			return obj;
		}
	private:
		//�G���L���[�I���i�{�́j
		inline node_type* _enqueueEnd()
		{
			//if (m_container.status() != status_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
			//	return;
			return m_container.pushEnd();//�R���e�i�Ƀv�b�V���I��
		}
	public:
		//�G���L���[�I��
		//��enqueueBegin�Ŏ擾�������b�N���������
		inline node_type* enqueueEnd()
		{
			const bool unlock = (m_container.status() == status_t::PUSH_BEGINNING);//�v�b�V���J�n���Ȃ�A�����b�N����
			node_type* new_obj = _enqueueEnd();//�G���L���[�I��
			if (unlock)
				m_lock.unlock();//���b�N���
			return new_obj;
		}
	private:
		//�G���L���[�������i�{�́j
		inline bool _enqueueCancel()
		{
			//if (m_container.status() != status_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
			//	return;
			return m_container.pushCancel();//�v�b�V��������
		}
	public:
		//�G���L���[������
		//��enqueueBegin�Ŏ擾�������b�N���������
		inline bool enqueueCancel()
		{
			const bool unlock = (m_container.status() == status_t::PUSH_BEGINNING);//�v�b�V���J�n���Ȃ�A�����b�N����
			const bool result = m_container.pushCancel();//�v�b�V��������
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
	private:
		//�f�L���[�i�{�́j
		bool _dequeueCopying(node_type& dst)
		{
			//if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
			//	return nullptr;
			const bool result = m_container.popCopying(dst);//�R���e�i����|�b�v
			if (!result)
				return false;
			checkAndResetSeqNo();//�L���[����ɂȂ�����V�[�P���X�ԍ������Z�b�g����
			return true;
		}
	public:
		//�f�L���[
		//���I�u�W�F�N�g�̃R�s�[���󂯎��̈��n��
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo����� ���R�s�[��Ɏ��s
		//���������A���b�N���擾����
		inline bool dequeueCopying(node_type& dst)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _dequeueCopying(dst);
		}
	private:
		//�f�L���[�J�n�i�{�́j
		//���f�L���[�������� dequeueEnd ���Ăяo���K�v����
		node_type* _dequeueBegin()
		{
			//if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
			//	return nullptr;
			node_type* obj = m_container.popBegin();//�R���e�i����|�b�v�J�n
			if (!obj)
				return nullptr;
			return obj;
		}
	public:
		//�f�L���[�J�n
		//���f�L���[�������� dequeueEnd ���Ăяo���K�v����
		//����������������ƁA���b�N���擾������ԂɂȂ�idequeueEnd�ŉ������j
		inline node_type* dequeueBegin()
		{
			m_lock.lock();//���b�N���擾�i���̂܂܊֐��𔲂���j
			node_type* obj = _dequeueBegin();//�f�L���[�J�n
			if (!obj)
				m_lock.unlock();//�v�b�V�����s���̓��b�N���
			return obj;
		}
	private:
		//�f�L���[�I���i�{�́j
		bool _dequeueEnd()
		{
			//if (m_container.status() != status_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
			//	return false;
			const bool result = m_container.popEnd();//�R���e�i����|�b�v�I��
			checkAndResetSeqNo();//�L���[����ɂȂ�����V�[�P���X�ԍ������Z�b�g����
			return result;
		}
	public:
		//�f�L���[�I��
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo�����
		//��dequeueBegin�Ŏ擾�������b�N���������
		inline bool dequeueEnd()
		{
			const bool unlock = (m_container.status() == status_t::POP_BEGINNING);//�|�b�v�J�n���Ȃ�A�����b�N����
			const bool result = _dequeueEnd();//�f�L���[�I��
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
	private:
		//�f�L���[�������i�{�́j
		bool _dequeueCancel()
		{
			//if (m_container.status() != status_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
			//	return false;
			return m_container.popCancel();//�|�b�v������
		}
	public:
		//�f�L���[������
		//��dequeueBegin�Ŏ擾�������b�N���������
		inline bool dequeueCancel()
		{
			const bool unlock = (m_container.status() == status_t::POP_BEGINNING);//�|�b�v�J�n���Ȃ�A�����b�N����
			const bool result = _dequeueCancel();//�f�L���[������
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
		//�擪�i���j�L���[���Q��
		//���f�L���[���Ȃ�
		inline const node_type* top() const
		{
			return m_container.top();//�R���e�i�̐擪�i���j�m�[�h���擾
		}
	private:
		//�擪�i���j�L���[�̃v���C�I���e�B�ύX�i�{�́j
		node_type* _changePriorityOnTop(const priority_type priority)
		{
			node_type* obj = m_container.top();
			if (!obj)
				return nullptr;
			ope_type::setPriority(*obj, priority);//�D��x���X�V
			ope_type::setSeqNo(*obj, getNextSeqNo());//�V�[�P���X�ԍ����X�V
			return m_container.downHeap(obj);//�_�E���q�[�v
		}
	public:
		//�擪�i���j�L���[�̃v���C�I���e�B�ύX
		//���v���C�I���e�B��ύX�������_�ŃL���[�̈ʒu������ւ��
		//���V�[�P���X�ԍ����čX�V����
		//�������v���C�I���e�B�ɕύX�����ꍇ�A�����v���C�I���e�B�̃L���[�̈�ԍŌ�ɉ񂳂��
		//���������A���b�N���擾����
		inline node_type* changePriorityOnTop(const priority_type priority)
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return _changePriorityOnTop(priority);
		}
		//�����b�N�Ȃ��Łitop()�Q�Ɓ`�v���C�I���e�B�ύX�܂ł�C�ӂɃ��b�N����Ȃ炱������g�p����j
		inline node_type* changePriorityOnTopWithoutLock(const priority_type priority)
		{
			return _changePriorityOnTop(priority);
		}
	private:
		//�N���A�i�{�́j
		inline void _clear()
		{
			m_container.clear();
		}
	public:
		//�N���A
		//���������A���b�N���擾����
		inline void clear()
		{
			lock_guard<lock_type> lock(m_lock);//���b�N�擾�i�֐��𔲂��鎞�Ɏ����J���j
			_clear();
		}
	public:
		//�R���X�g���N�^
		container_adapter() :
			m_container(),
			m_seqNo(0),
			m_lock()
		{}
		//�f�X�g���N�^
		~container_adapter()
		{
			enqueueCancel();//�G���L���[������
			dequeueCancel();//�f�L���[������
		}
	private:
		//�t�B�[���h
		container_type m_container;//�R���e�i
		int m_dummy;
		seq_type m_seqNo;//�V�[�P���X�ԍ� ��mutable�C���q
		mutable lock_type m_lock;//���b�N�I�u�W�F�N�g
	};
	//--------------------
	//���S�ȃG���L���[�^�f�L���[����N���X
	//�������Ԃ��L�����A�f�X�g���N�^�ŕK������������
	template<class CON>
	class operation_guard
	{
	public:
		//�^
		typedef CON container_adapter_type;//�R���e�i�A�_�v�^�[�^
		typedef typename CON::node_type node_type;//�m�[�h�^
		typedef typename CON::status_t status_t;//�X�e�[�^�X�^
	public:
		//�A�N�Z�b�T
		status_t status() const { return m_status; }//�X�e�[�^�X���擾
	public:
		//�G���L���[�J�n
		template<typename... Tx>
		node_type* enqueueBegin(const typename CON::priority_type priority, Tx... args)
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_containerAdapter.enqueueBegin(priority, args...);//�G���L���[�J�n
			if (node)
				m_status = status_t::PUSH_BEGINNING;//�X�e�[�^�X�ύX
			return node;
		}
		//�G���L���[�I��
		node_type* enqueueEnd()
		{
			if (m_status != status_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_containerAdapter.enqueueEnd();//�G���L���[�I��
			m_status = status_t::PUSH_ENDED;//�X�e�[�^�X�ύX
			return node;
		}
		//�G���L���[������
		bool enqueueCancel()
		{
			if (m_status != status_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return nullptr;
			m_containerAdapter.enqueueCancel();//�G���L���[������
			m_status = status_t::PUSH_CANCELLED;//�X�e�[�^�X�ύX
			return true;
		}
		//�f�L���[�J�n
		node_type* dequeueBegin()
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_containerAdapter.dequeueBegin();//�f�L���[�J�n
			if (node)
				m_status = status_t::POP_BEGINNING;//�X�e�[�^�X�ύX
			return node;
		}
		//�f�L���[�I��
		bool dequeueEnd()
		{
			if (m_status != status_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			const bool result = m_containerAdapter.dequeueEnd();//�f�L���[�I��
			m_status = status_t::POP_ENDED;//�X�e�[�^�X�ύX
			return result;
		}
		//�f�L���[������
		bool dequeueCancel()
		{
			if (m_status != status_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_containerAdapter.dequeueCancel();//�f�L���[������
			m_status = status_t::POP_CANCELLED;//�X�e�[�^�X�ύX
			return true;
		}
	public:
		//�R���X�g���N�^
		operation_guard(container_adapter_type& container_adapter) :
			m_containerAdapter(container_adapter),
			m_status(status_t::IDLE)
		{}
		//�f�X�g���N�^
		~operation_guard()
		{
			enqueueEnd();//�G���L���[�I��
			dequeueEnd();//�f�L���[�I��
		}
	private:
		//�t�B�[���h
		container_adapter_type& m_containerAdapter;//�R���e�i�A�_�v�^
		status_t m_status;//�X�e�[�^�X
	};
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace priority_queue

//--------------------------------------------------------------------------------
//�v���C�I���e�B�L���[�e�X�g
//--------------------------------------------------------------------------------

#include <memory.h>//memcpy�p
#include <random>//C++11 std::random�p
#include <algorithm>//std::for_each�p
#include <queue>//std::priority_queue�p����r�e�X�g�p

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
enum PRIORITY : short
{
	HIGHEST = 5,
	HIGHER = 4,
	NORMAL = 3,
	LOWER = 2,
	LOWEST = 1,
};
struct data_t
{
	PRIORITY m_priority;//�D��x
	unsigned int m_seqNo;//�V�[�P���X�ԍ�
	int m_val;//�f�[�^
	int m_data[2];

	//�R���X�g���N�^
	data_t(const PRIORITY priority, const int val) :
		m_priority(priority),
		m_seqNo(0),
		m_val(val)
	{
		m_data[0] = 99;
		m_data[1] = 99;
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d, %d)\n", priority, val);
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	data_t(const int val) :
		m_priority(NORMAL),
		m_seqNo(0),
		m_val(val)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d)\n", val);
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
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
	//�f�t�H���g�R���X�g���N�^
	data_t() :
		m_priority(NORMAL),
		m_seqNo(0),
		m_val(0)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor\n");
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	//�f�X�g���N�^
	~data_t()
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::destructor\n");
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
};
//----------------------------------------
//�e�X�g�f�[�^����N���X
struct heap_ope_t : public binary_heap::base_ope_t<heap_ope_t, data_t>
{
	//�L�[���r
	//��lhs�̕�������������� true ��Ԃ�
	//���h���N���X�ł̎������K�v
	inline static bool less(const node_type& lhs, const node_type& rhs)
	{
		return lhs.m_priority < rhs.m_priority;//�D��x�݂̂��r
	}
	
	//���b�N�^
	//���f�t�H���g�idummy_lock�j�̂܂܂Ƃ���
	//typedef spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
};
//----------------------------------------
//�e�X�g�f�[�^����N���X
struct ope_t : public priority_queue::base_ope_t<ope_t, data_t, PRIORITY, int>
{
	//�D��x���擾
	inline static priority_type getPriority(const node_type& node){ return node.m_priority; }
	//�D��x���X�V
	inline static void setPriority(node_type& node, const priority_type priority){ node.m_priority = priority; }
	
	//�V�[�P���X�ԍ����擾
	inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//�V�[�P���X�ԍ����X�V
	inline static void setSeqNo(node_type& node, const seq_type seq_no){ node.m_seqNo = seq_no; }

	//���b�N�^
	//���f�t�H���g�idummy_lock�j�̂܂܂Ƃ���
	//typedef spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
};

//----------------------------------------
//�؂�\��
template<class HEAP>
void showTree(const HEAP& heap)
{
	printf_detail("\n");
	printf_detail("--- Show tree (count=%d) ---\n", heap.size());
	//static const int depth_limit = 5;//�ő�ł�5�i�K�ڂ܂ł�\���i0�i�K�ڂ��琔����̂ōő��6�i�K�\������遨�ő�F1+2+4+8+16+32=63�j
	static const int depth_limit = 4;//�ő�ł�4�i�K�ڂ܂ł�\���i0�i�K�ڂ��琔����̂ōő��5�i�K�\������遨�ő�F1+2+4+8+16=31�j
	const int _depth_max = heap.depth_max();
	printf_detail("depth_max=%d (limit for showing=%d)\n", _depth_max, depth_limit);
	const int depth_max = _depth_max <= depth_limit ? _depth_max : depth_limit;
	const int width_max = static_cast<int>(std::pow(2, depth_max));
	for (int depth = 0; depth <= depth_max; ++depth)
	{
		const int width = static_cast<int>(std::pow(2, depth));
		static const int label_len = 6;
		const int print_width = (width_max * label_len) / width;
		const int print_indent = (print_width - label_len) / 2;
		for (int breath = 0; breath < width; ++breath)
		{
			const data_t* node = heap.ref_top();
			int breath_tmp = breath;
			for (int depth_tmp = depth - 1; node; --depth_tmp)
			{
				if (depth_tmp < 0)
					break;
				node = heap.ref_child(node, (breath_tmp & (0x1 << depth_tmp)) != 0x0);
			}
			if (node)
			{
				{
					int c = 0;
					for (; c < print_indent / 2; ++c)
						printf_detail(" ");
					if (heap.ref_child_l(node) && c < print_indent)
					{
						printf_detail(".");
						++c;
					}
					for (; c < print_indent; ++c)
						printf_detail(heap.ref_child_l(node) ? "-" : " ");
				}
				printf_detail("%s%1d:%2d%s", heap.ref_child_l(node) ? "{" : "[", node->m_priority, node->m_val, heap.ref_child_r(node) ? "}" : "]");
				{
					int c = 0;
					for (; c < print_indent / 2; ++c)
						printf_detail(heap.ref_child_r(node) ? "-" : " ");
					if (heap.ref_child_r(node) && c < print_indent)
					{
						printf_detail(".");
						++c;
					}
					for (; c < print_indent; ++c)
						printf_detail(" ");
				}
			}
			else
			{
				for (int c = 0; c < print_width; ++c)
					printf_detail(" ");
			}
		}
		printf_detail("\n");
	}
};

//----------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//�v���C�I���e�B�L���[�R���e�i����
	typedef priority_queue::container_adapter<ope_t, TEST_DATA_MAX> pqueue_t;
	pqueue_t* con = new pqueue_t();

	//�������Ԍv���J�n
	const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point prev_time = begin_time;

	//--------------------
	//�v���C�I���e�B�L���[�̃e�X�g
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container_adapter(Priority Queue)]\n");

	//�G���L���[
	auto enqueue = [&con]()
	{
		printf("\n");
		printf("--- Enqueue ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj = con->enqueue(NORMAL, 0);
			printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			#define USE_ENQUEUE_TYPE 2
			//�y�G���L���[���@�@�z�I�u�W�F�N�g���󂯓n�����@
			//���I�u�W�F�N�g�̃R�s�[����������̂ŏ����x���B
			#if USE_ENQUEUE_TYPE == 1
			{
				data_t new_obj(priority, val);
				data_t* obj = con->enqueueCopying(new_obj);
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//�y�����z�y�G���L���[���@�A�z�R���X�g���N�^�p�����[�^��n���ēo�^������@
			//���I�u�W�F�N�g�̃R�s�[�͔������Ȃ��B
			//���R���X�g���N�^���Ăяo�����B
			#elif USE_ENQUEUE_TYPE == 2
			{
				data_t* obj = con->enqueue(priority, val);//�D��x�ƃR���X�g���N�^�p�����[�^��n���ēo�^
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//�y�G���L���[���@�B�z�V�K�L���[�i�I�u�W�F�N�g�j�̎Q�Ƃ��󂯎���Ēl���Z�b�g������@
			//���I�u�W�F�N�g�̃R�s�[�͔������Ȃ��B
			//���ŏ��ɃR���X�g���N�^���Ăяo�����B
			//�������I�ɏI���������Ăяo���A���b�N��������Ȃ���΂Ȃ�Ȃ��_�ɒ��ӁB
			//�@�i�G���L���[�^�f�L���[����p�N���X���g�p���邱�ƂŁA�����u���b�N�𔲂��鎞�Ɏ����G�Ƀ��b�N����������j
			//���G���L���[�I�����ɂ̓|�C���^���ς��_�ɂ����ӁB
			#elif USE_ENQUEUE_TYPE == 3
			{
				priority_queue::operation_guard<pqueue_t> ope(*con);//�G���L���[�^�f�L���[����p�N���X
				data_t* obj = ope.enqueueBegin(priority);//���̎��_�ŗD��x�ƃV�[�P���X�ԍ����Z�b�g����A���b�N���擾�����
				                                         //���߂�l�́A�����u���b�N���ł����ienqueueEnd/enqueueCancel�Ăяo���܂ł����j�L���ł͂Ȃ��|�C���^�Ȃ̂Œ���
				obj->m_val = val;
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
				//�����u���b�N�𔲂��鎞�Ɏ����I�Ƀf�L���[���I�����A���b�N����������B
				//���󂯎�����|�C���^�������u���b�N�̊O�ŎQ�Ƃ���ƁA����������Q�Ƃ��邱�ƂɂȂ�̂Œ��ӁB
				//�������I�ɃG���L���[�I���^�����������s���邱�Ƃ��\�B
				//obj = ope.enqueueEnd();//�����I�ȃG���L���[�I�����s���ƁA�������I�u�W�F�N�g�̎Q�Ƃ��擾�ł���
				//ope.enqueueCancel();
			}
			#endif//USE_ENQUEUE_TYPE
		}
	};
	enqueue();

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
	prev_time = printElapsedTime(prev_time, true);

#if 0
	//�͈͂Ɋ�Â�for���[�v�e�X�g
	auto printNodesTest1 = [&con]()
	{
		printf("\n");
		printf("--- Test for C++11 for(:) ---\n");
		typedef pqueue_t::container_type container_t;
		container_t& heap = *con;
		for (const data_t& o : heap)
			printf("[%1d:%2d] ", o.m_priority, o.m_val);
		printf("\n");
	};
	printNodesTest1();
#endif

#if 0
	//std::for_each�e�X�g
	auto printNodesTest2 = [&con]()
	{
		printf("\n");
		printf("--- Test for std::for_each() ---\n");
		typedef pqueue_t::container_type container_t;
		container_t& heap = *con;
		printf("iterator:         ");
		std::for_each(heap.begin(), heap.end(), [](data_t& o)
			{
				printf("[%1d:%2d] ", o.m_priority, o.m_val);
			}
		);
		printf("\n");
		printf("reverse_iterator: ");
		std::for_each(heap.rbegin(), heap.rend(), [](data_t& o)
			{
				printf("[%1d:%2d] ", o.m_priority, o.m_val);
			}
		);
		printf("\n");
	};
	printNodesTest2();
#endif

#if 0//�C�e���[�^�ƃ��b�N�擾�̃e�X�g
	{
		printf("\n");
		typedef pqueue_t::container_type container_t;
		container_t& heap = *con;
		lock_guard<container_t::lock_type> lock(heap);
		container_t::iterator ite = heap.begin();
		container_t::reverse_iterator rite = heap.rbegin();
		container_t::iterator ite_end = heap.end();
		container_t::reverse_iterator rite_end = heap.rend();
		container_t::iterator ite2 = heap.rbegin();
		container_t::reverse_iterator rite2 = heap.begin();
		container_t::iterator ite2_end = heap.rend();
		container_t::reverse_iterator rite2_end = heap.end();
		printf("constructor\n");
		if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
		if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
		if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
		if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
		if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
		if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
		if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
		if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
		printf("copy operator\n");
		ite = heap.begin();
		rite = heap.rbegin();
		ite_end = heap.end();
		rite_end = heap.rend();
		ite2 = heap.rbegin();
		rite2 = heap.begin();
		ite2_end = heap.rend();
		rite2_end = heap.end();
		if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
		if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
		if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
		if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
		if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
		if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
		if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
		if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
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
			if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
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
		if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
		if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
		if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
		if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
		if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
		if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
		if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
		if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
		printf("-= 3\n");
		ite -= 3;
		rite -= 3;
		ite_end -= 3;
		rite_end -= 3;
		ite2 -= 3;
		rite2 -= 3;
		ite2_end -= 3;
		rite2_end -= 3;
		if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
		if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
		if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
		if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
		if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
		if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
		if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
		if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
	}
#endif

	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	//�f�L���[
	auto dequeue = [&con](const int pop_limit)
	{
		printf("\n");
		printf("--- Dequeue ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			#define USE_DEQUEUE_TYPE 1
			//�y�����z�y�f�L���[���@�@�z���擾�p�̃I�u�W�F�N�g���󂯓n��
			//���I�u�W�F�N�g�̃R�s�[����������B
			//���f�X�g���N�^���Ăяo�����B�i�R�s�[��Ɏ��s�j
			#if USE_DEQUEUE_TYPE == 1
			{
				data_t node;
				const bool result = con->dequeueCopying(node);
				if (!result)
					break;
				printf_detail("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//�y�f�L���[���@�A�z�L���[�i�I�u�W�F�N�g�j�̎Q�Ƃ��󂯎����@
			//���I�u�W�F�N�g�̃R�s�[�͔������Ȃ��B
			//�������I�ɏI���������Ăяo���A���b�N��������Ȃ���΂Ȃ�Ȃ��_�ɒ��ӁB
			//�@�i�G���L���[�^�f�L���[����p�N���X���g�p���邱�ƂŁA�����u���b�N�𔲂��鎞�Ɏ����G�Ƀ��b�N����������j
			//���Ō�Ƀf�X�g���N�^���Ăяo�����B
			#elif USE_DEQUEUE_TYPE == 2
			{
				priority_queue::operation_guard<pqueue_t> ope(*con);//�G���L���[�^�f�L���[����p�N���X
				data_t* obj = ope.dequeueBegin();//���̎��_�Ń��b�N���擾�����
				                                 //���߂�l�́A�����u���b�N���ł����idequeueEnd/dequeueCancel�Ăяo���܂ł����j�L���ł͂Ȃ��|�C���^�Ȃ̂Œ���
				if (!obj)
					break;
				printf_detail("[%1d:%2d] ", obj->m_priority, obj->m_val);
				//�����u���b�N�𔲂��鎞�Ɏ����I�Ƀf�L���[���I�����A���b�N����������B
				//���󂯎�����|�C���^�������u���b�N�̊O�ŎQ�Ƃ���ƁA����������Q�Ƃ��邱�ƂɂȂ�̂Œ��ӁB
				//�������I�Ƀf�L���[�I���^�����������s���邱�Ƃ��\�B
				//ope.dequeueEnd();
				//ope.dequeueCancel();
			}
			#endif//USE_DEQUEUE_TYPE
		}
		printf_detail("\n");
	};
	dequeue(3);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	//�擪�i���j�m�[�h�̗D��x��ύX
	auto changePriorityOnTop = [&con](const PRIORITY new_priority)
	{
		printf("\n");
		printf("--- Change Priority ---\n");
		const data_t* node = con->top();//�擪�m�[�h���擾�i�|�b�v����Ȃ��j
		printf("[%1d:%2d(seq=%d)]", node->m_priority, node->m_val, node->m_seqNo);
		node = con->changePriorityOnTop(new_priority);//�D��x��ύX�i�ύX��A�L���[���Ĕz�u�����j
		printf(" -> [%1d:%2d(seq=%d)]\n", node->m_priority, node->m_val, node->m_seqNo);
	};
	changePriorityOnTop(HIGHEST);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	changePriorityOnTop(LOWER);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	changePriorityOnTop(HIGHER);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��
	
	//�f�L���[
	dequeue(TEST_DATA_REG_NUM / 2);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	//�f�L���[
	dequeue(TEST_DATA_REG_NUM);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	//--------------------
	//�y������r�p�z�񕪃q�[�v�̃e�X�g
	//���v���C�I���e�B�L���[�ƈقȂ�A�|�b�v���ɁA�v�b�V�����i�G���L���[���j�̏��������ۏ؂���Ă��Ȃ����Ƃ��m�F�ł���
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for binary_heap::container(Binary Heap)]\n");

	//�q�[�v�R���e�i����
	typedef binary_heap::container<heap_ope_t, TEST_DATA_MAX> heap_t;
	heap_t* heap = new heap_t();

	//�񕪃q�[�v�Ńm�[�h���v�b�V��
	auto pushNodesBinHeap = [&heap]()
	{
		printf("\n");
		printf("--- Push nodes(Binary Heap) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj =heap->push(NORMAL, 0);
			printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			//����L�v���C�I���e�B�L���[�Ő��������A�R��ނ̃v�b�V�����@���g����
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			#define USE_PUSH_TYPE 2
			//�y�v�b�V�����@�@�z
			#if USE_PUSH_TYPE == 1
			{
				data_t new_obj(priority, val);
				data_t* obj = heap->pushCopying(new_obj);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//�y�����z�y�v�b�V�����@�A�z
			#elif USE_PUSH_TYPE == 2
			{
				data_t* obj = heap->push(priority, val);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//�y�v�b�V�����@�B�z
			#elif USE_PUSH_TYPE == 3
			{
				binary_heap::operation_guard<container_type> ope(*heap);
				data_t* obj = ope.pushBegin(priority, val);//���߂�l�́A�����u���b�N���ł����ipushEnd/pushCancel�Ăяo���܂ł����j�L���ł͂Ȃ��|�C���^�Ȃ̂Œ���
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
				//obj = ope.popEnd();//�����I�ȃ|�b�v�I�����s���ƁA�������I�u�W�F�N�g�̎Q�Ƃ��擾�ł���
			}
			#endif//USE_PUSH_TYPE
		}
	};
	pushNodesBinHeap();
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree(*heap);
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��
	
	//�񕪃q�[�v�Ńm�[�h���|�b�v
	auto popNodesBinHeap  = [&heap](const int pop_limit)
	{
		printf("\n");
		printf("--- Pop nodes(Binary Heap) ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			//����L�v���C�I���e�B�L���[�Ő��������A�Q��ނ̃|�b�v���@���g����
			#define USE_POP_TYPE 1
			//�y�����z�y�|�b�v���@�@�z
			#if USE_POP_TYPE == 1
			{
				data_t node;
				const bool result = heap->popCopying(node);
				if (!result)
					break;
				printf_detail("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//�y�|�b�v���@�A�z
			#elif USE_POP_TYPE == 2
			{
				binary_heap::operation_guard<heap_t> ope(*heap);
				data_t* obj = ope.popBegin();//���߂�l�́A�����u���b�N���ł����ipopEnd/popCancel�Ăяo���܂ł����j�L���ł͂Ȃ��|�C���^�Ȃ̂Œ���
				if (!obj)
					break;
				printf_detail("[%1d:%2d] ", obj->m_priority, obj->m_val);
			}
			#endif//USE_POP_TYPE
		}
		printf_detail("\n");
	};
	popNodesBinHeap(TEST_DATA_REG_NUM / 2);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree(*heap);
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	//�m�[�h���|�b�v
	popNodesBinHeap(TEST_DATA_REG_NUM);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree(*heap);
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	//�C���X�^���X��j��
	delete heap;
	heap = nullptr;

	//--------------------
	//�y������r�p�zSTL��std::priority_queue�e�X�g
	//���v���C�I���e�B�L���[�ƈقȂ�A�|�b�v���ɁA�v�b�V�����i�G���L���[���j�̏��������ۏ؂���Ă��Ȃ����Ƃ��m�F�ł���
	//��STL�Ɠ񕪃q�[�v�̋����i�|�b�v�����j���S���������Ƃ��m�F�ł���
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for std::priority_queue(STL)]\n");
	
	//�D��x�t���L���[�R���e�i����
	typedef std::priority_queue<data_t, std::vector<data_t>, heap_ope_t> stl_container_type;
	//typedef std::priority_queue<data_t, std::vector<data_t>, ope_t> stl_container_type;
	stl_container_type* stl_heap = new stl_container_type();

	//STL�Ńm�[�h���v�b�V��
	auto pushNodesSTL = [&stl_heap]()
	{
		printf("\n");
		printf("--- Push nodes(STL) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t obj(NORMAL, 0);
			stl_heap->push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			data_t obj(priority, val);
			stl_heap->push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
	};
	pushNodesSTL();
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��

	//STL�Ńm�[�h���|�b�v
	auto popNodesSTL = [&stl_heap](const int pop_limit)
	{
		printf("\n");
		printf("--- Pop nodes(STL) ---\n");
		for (int i = 0; i < pop_limit && !stl_heap->empty(); ++i)
		{
			data_t node = stl_heap->top();
			printf_detail("[%1d:%2d] ", node.m_priority, node.m_val);
			stl_heap->pop();
		}
		printf_detail("\n");
	};
	popNodesSTL(TEST_DATA_REG_NUM / 2);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	popNodesSTL(TEST_DATA_REG_NUM);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��

	//�C���X�^���X��j��
	delete stl_heap;
	stl_heap = nullptr;

	//--------------------
	//�y������r�p�z�v���C�I���e�B�L���[�̍ăe�X�g
	//����L�̓񕪃q�[�v�^STL�̃e�X�g�Ɠ���̗���̃e�X�g�����{
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container_adapter(Priority Queue)] *Second time\n");

	//�G���L���[
	enqueue();
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��
	
	//�f�L���[
	dequeue(TEST_DATA_REG_NUM / 2);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��
	
	//�f�L���[
	dequeue(TEST_DATA_REG_NUM);
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��
	
	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	//--------------------
	//�v���C�I���e�B�L���[�̃N���A�̃e�X�g
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container_adapter(Priority Queue)] *Clear\n");
		
	//�G���L���[
	enqueue();
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	printf("\n");
	printf("--- Clear ---\n");
	
	//�N���A
	con->clear();
	printf("OK\n");
	prev_time = printElapsedTime(prev_time, true);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//�o�ߎ��Ԃ�\��

	//�C���X�^���X��j��
	delete con;
	con = nullptr;

	//--------------------
	//�|�C���^�ϐ����L���[�C���O����ꍇ�̃e�X�g
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for priority_queue::container_adapter(Priority Queue)] *Pointer\n");
		printf("\n");

		//����^
		struct p_ope_t : public priority_queue::base_ope_t<p_ope_t, data_t*, PRIORITY, int>
		{
			inline static priority_type getPriority(const node_type& node){ return node->m_priority; }
			inline static void setPriority(node_type& node, const priority_type priority){ node->m_priority = priority; }
			inline static seq_type getSeqNo(const node_type& node){ return node->m_seqNo; }
			inline static void setSeqNo(node_type& node, const seq_type seq_no){ node->m_seqNo = seq_no; }

			//���b�N�^
			//���f�t�H���g�idummy_lock�j�̂܂܂Ƃ���
			//typedef spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
		};
		
		//�v���C�I���e�B�L���[
		priority_queue::container_adapter<p_ope_t, 100> p_con;
		
		//�G���L���[
		data_t obj1(NORMAL, 1);
		data_t obj2(HIGHER, 2);
		data_t obj3(LOWER, 3);
		data_t obj4(HIGHEST, 4);
		data_t obj5(LOWEST, 5);
		p_con.enqueueCopying(&obj1);
		p_con.enqueueCopying(&obj2);
		p_con.enqueueCopying(&obj3);
		p_con.enqueueCopying(&obj4);
		p_con.enqueueCopying(&obj5);

		//�f�L���[
		auto dequeuObj = [&p_con]()
		{
			data_t* obj_p = nullptr;
			p_con.dequeueCopying(obj_p);
			printf_detail("pop: [%1d:%2d](seq=%d)\n", obj_p->m_priority, obj_p->m_val, obj_p->m_seqNo);
		};
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
	}

	//�I��
	printf("\n");
	printf("--- end ---\n");
	printElapsedTime(begin_time, true);//�o�ߎ��Ԃ�\��

	return EXIT_SUCCESS;
}

// End of file
