//--------------------------------------------------------------------------------
//�y�ӎ��z
//���̃v���O�����̃A���S���Y���́A���L�̌l�T�C�g�ɂĔ��\����Ă���܂��A
//�T�C�g��l���J�����ꂽ�A���S���Y�����Q�l�ɂ������܂����B
//    URL�F http ://www.moon.sannet.ne.jp/okahisa/rb-tree/rb-tree.html
//    �L���F�uRed - Black Tree by Java -- ����ŕ��������ԍ��؁v
//          �g�b�v�y�[�WURL : http ://www.moon.sannet.ne.jp/okahisa/
//                           �uOK��������̃z�[���y�[�W�v
//�ƂĂ�������Ղ��D�ꂽ�A���S���Y���ł���A���Ȃ��v���O�������쐬�ł�
//�܂������Ƃ����ӂ������܂��B
//�Ȃ��A�\�[�X�R�[�h�͈��p���Ă���܂���B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�ԍ��؃e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
static const int TEST_DATA_KEY_MIN = 1;//�e�X�g�f�[�^�̍ŏ��L�[
static const int TEST_DATA_KEY_MAX = 10;//�e�X�g�f�[�^�̍ő�L�[
static const int TEST_DATA_REG_NUM = 20;//�e�X�g�f�[�^�̓o�^��
static const int TEST_DATA_STACK_DEPTH_MAX = 32;//�e�X�g�f�[�^�̐ԍ��ؑ���p�X�^�b�N�̍ő�̐[���i�f�t�H���g��32�ŁA���t�؂Ȃ�10�����͈�����j
//#define REGIST_TEST_DATA_SEQUENTIALLY//�f�[�^���V�[�P���V�����ɓo�^����ꍇ�́A���̃}�N����L��������i���������̓����_���j
#define PRINT_TEST_DATA_TREE//�e�X�g�f�[�^�̖؂�\������ꍇ�́A���̃}�N����L��������i�\�����Ȃ��Ă������͎��s����j
#define PRINT_TEST_DATA_SEARCH//�e�X�g�f�[���̌������ʂ�\������ꍇ�́A���̃}�N����L��������i�\�����Ȃ��Ă������͎��s����j
#define PRINT_TEST_DATA_COLOR_COUNT//�e�X�g�f�[�^�̐ԍ��J�E���g���v����\������ꍇ�́A���̃}�N����L��������
#define PRINT_TEST_DATA_DETAIL//�e�X�g�f�[�^�̏ڍׂ�\������ꍇ�́A���̃}�N����L��������
//#define ENABLE_CALC_COUNT_PERFORMANCE//�f�[�^�����J�E���g�̏������Ԃ��v������ꍇ�́A���̃}�N����L��������

//�e�X�g�f�[�^���Œ菇�ɓo�^����ꍇ�́A���̃}�N����L��������i�������̓����_���A�������AREGIST_TEST_DATA_SEQUENTIALLY���D��j
//#define TEST_DATA_REGISTRATION_LIST { 54, 59, 71, 84, 60, 85, 54, 84, 42, 62, 64, 38, 43, 29, 89, 5, 96, 27, 38, 47, 79, 81, 52, 47, 56, 39, 92, 83, 7, 33, 8, 64, 2, 36, 83, 95, 77, 14, 87, 87, 97, 47, 79, 80, 46, 52, 78, 67, 11, 72, 63, 58, 14, 53, 94, 75, 52, 10, 41, 47, 26, 18, 77, 73, 45, 21, 56, 13, 1, 32, 61, 14, 61, 22, 61, 38, 94, 90, 68, 44, 35, 61, 43, 90, 69, 9, 6, 96, 66, 65, 67, 17, 21, 35, 12, 75, 31, 60, 36, 32}

//�e�X�g�f�[�^���Œ菇�ɍ폜����ꍇ�́A���̃}�N����L��������i�������̓����_���j
//#define TEST_DATA_REMOVING_LIST { 41, 72, 12, 14, 9, 39, 18, 38, 66, 53, 84, 31, 68, 52, 44, 87 }

//--------------------------------------------------------------------------------
//�ԍ��؃A���S���Y���p�R���p�C���X�C�b�`
//#define DISABLE_COLOR_FOR_ADD//�m�[�h�ǉ����̐F����Ɖ�]�����𖳌�������ꍇ�́A���̃}�N����L��������
//#define DISABLE_COLOR_FOR_REMOVE//�m�[�h�폜���̐F����Ɖ�]�����𖳌�������ꍇ�́A���̃}�N����L��������
//#define DEBUG_PRINT_FOR_ADD//�m�[�h�ǉ����̃f�o�b�O���\����L��������ꍇ�́A���̃}�N����L��������
//#define DEBUG_PRINT_FOR_REMOVE//�m�[�h�폜���̃f�o�b�O���\����L��������ꍇ�́A���̃}�N����L��������

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
//�ԍ��؁ired-black tree�j
//--------------------------------------------------------------------------------
//�f�[�^�\���ƃA���S���Y��
//�y�����z
//�E�񕪒T���؂ł���B
//	  - �m�[�h�̍����̎q�ɂ́A�L�[�̒l���������m�[�h��A���B
//	  - �m�[�h�̉E���̎q�ɂ́A�L�[�̒l���傫�����������m�[�h��A���B
//�E���t�؂ł���B
//	  - ��ɍ��E�̖؂̃o�����X��ۂB
//�E�ȏ�̓����ɂ��A�T���E�ǉ��E�폜�̎��Ԃ��A���O(log n)�ɕۂ����B
//�y�����z
//�E�����@�F�e�m�[�h�́u�ԁv���u���v�́u�F�v�����B
//�E�����A�F�u���v�iroot�j�͕K���u���v�B
//�E�����B�F�u�ԁv�̎q�͕K���u���v�B
//	          - �΋�ɂ��A�u�ԁv�̐e�͕K���u���v�B
//	          - �u���v�̎q�́u�ԁv�ł��u���v�ł��ǂ��B
//�E�����C�F�u���v����u�t�v�܂ł̌o�H��ɂ���u���v�̐��́A
//�@�@�@�@�@������o�H�ň��B
//            - �u�t�v�Ƃ́A���[��nullptr�ł�����̂Ƃ���B
//            - �u�t�v�inullptr�j�̐F�́u���v�ł�����̂Ƃ���B
//              �܂�A�u�ԁv�̎q��nullptr�ł����Ă��ǂ��B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y�{�v���O�����ɂ���������v���z
//�E�������ߖ�̂��߂ɁA�e�m�[�h�ւ̃����N�������Ȃ��f�[�^�\���Ƃ���B
//�E����ɁA�������̊֐����s���ɊO������X�^�b�N��n�����Őe��H�邱�Ƃ��\�B
//�E�e���v���[�g�ɂ��A�A���S���Y����ėp���B
//�E�L�[�d���i���L�[�̃m�[�h�����������ԁj�����e����A���S���Y���Ƃ���B
//�E�����N�̕��@�ɏ_����������A���Avirtual��K�{�Ƃ��Ȃ��悤�ɁA
//�@�f�[�^�\���͎��R�Ƃ���B
//�@�i�����N�̕ϐ����|�C���^�ɂ��悤���C���f�b�N�X�ɂ��悤�����R�j
//�E����ɁA�f�[�^�����p�̃N���X�����[�U�[��`���邱�ƂŁA
//�@�����ɔėp������������B
//�E��؃���������͍s�킸�A�m�[�h�̃I�u�W�F�N�g���󂯎���đ��삷��
//�@�A���S���Y���݂̂�񋟂���B
//�Estd::map��͂����R���e�i�ƃC�e���[�^�𗘗p�\�Ƃ���B
//�E�R���e�i�́A���m�[�h�݂̂�ێ����A��؃��������삵�Ȃ����̂Ƃ���B
//�E�C�e���[�^�́A��q�̃X�^�b�N������B�؂�����B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y��̓I�Ȋ��p�̑z��z���ȉ��A�������Ǘ������ɓK�p���邱�Ƃ�z�肵���v���B
//�E�������}�l�[�W���̊Ǘ����̘A���Ɏg�p���邱�Ƃ�z��B
//�E�󂫃������T�C�Y���̘A�����s�����߁A�L�[�d�������e����K�v������B
//�E�܂��A�A�����X�g����剻���邱�Ƃ�����邽�߁A�e�m�[�h�ւ̃����N����
//�@�����Ȃ��B
//�E�K�v�ʈȏ�̋󂫃������̃m�[�h�����������̂��A�A���C�������g����������
//�@��ŗ��p�\�ȃm�[�h�����m�F���A����傫�ȃm�[�h��H���čœK��
//�@�m�[�h��T���o���B
//�E�m�[�h�Ԃ̃����N���́A64bit�|�C���^�ϐ��ɂ���剻���N����Ȃ��悤�ɁA
//�@��������Ԃ̐擪����I�t�Z�b�g���ꂽ32bit�̑��΃|�C���^�������B
//�E��̃������Ǘ������A2��ނ̖؂ɐU�蕪���Ďg�p����B
//�@�폜�ς݃������m�[�h�̓񕪒T���؂̓T�C�Y���L�[�ɂ��A
//�@�g�p���������m�[�h�̓񕪒T���؂̓|�C���^���L�[�ɂ���B
//�E���̂悤�ȗ��p���\�Ƃ��邽�߂ɁA�f�[�^�\���ƃA���S���Y�������S��
//�@�؂藣�����\���ɂ���B
//--------------------------------------------------------------------------------

#include <memory.h>//memcpy�p
#include <assert.h>//assert�p
#include <cstddef>//srd::size_t�p
#include <iterator>//std::iterator�p
#include <utility>//std::move�p

namespace rb_tree
{
	//--------------------
	//�ԍ��؃m�[�h����p���e���v���[�g�N���X
	//�����L�̂悤�Ȕh���N���X�iCRTP�j���`���Ďg�p����
	//  //struct �N���X�� : public rb_tree::base_ope_t<�N���X��, �m�[�h�^, �L�[�^, �X�^�b�N�̍ő�̐[�� = 32>
	//	struct ope_t : public rb_tree::base_ope_t<ope_t, data_t, int>
	//	{
	//		//�q�m�[�h���擾
	//		inline static const node_type* getChildL(const node_type& node){ return ???; }//��i�E�j��
	//		inline static const node_type* getChildS(const node_type& node){ return ???; }//���i���j��
	//		//�q�m�[�h��ύX
	//		inline static void setChildL(node_type& node, const node_type* child){ ??? = child; }//��i�E�j��
	//		inline static void setChildS(node_type& node, const node_type* child){ ??? = child; }//���i���j��
	//		
	//		//�m�[�h�̐F���擾
	//		inline static color_t getColor(const node_type& node){ return ??? ? BLACK : RED; }
	//		//�m�[�h�̐F��ύX
	//		inline static void setColor(node_type& node, const color_t color){ ??? = color == BLACK; }
	//		
	//		//�L�[���擾
	//		inline static key_type getKey(const node_type& node){ return ???; }
	//		
	//		//�L�[���r ���K�v�ɉ����Ē�`
	//		inline static int compareKey(const key_type lhs, const key_type rhs){ return ???; }
	//		
	//		//���b�N�^ ���K�v�ɉ����Ē�`
	//		//�����L���b�N�i���[�h�E���C�g���b�N�j�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
	//		//�@�L���ȋ��L���b�N�^�ishared_spin_lock�Ȃǁj�� lock_type �^�Ƃ��Ē�`����B
	//		typedef shared_spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, typename KEY_TYPE, int _STACK_DEPTH_MAX = 32>
	struct base_ope_t
	{
		//�萔
		static const int STACK_DEPTH_MAX = _STACK_DEPTH_MAX;//�X�^�b�N�̍ő�̐[��
		enum color_t//�F
		{
			RED = 0,//��
			BLACK = 1,//��
		};

		//�^
		typedef OPE_TYPE ope_type;//�m�[�h����^
		typedef NODE_TYPE node_type;//�m�[�h�^
		typedef KEY_TYPE key_type;//�L�[�^

		//���b�N�^
		typedef dummy_shared_lock lock_type;//���b�N�I�u�W�F�N�g�^
		//���f�t�H���g�̓_�~�[�̂��߁A��؃��b�N���䂵�Ȃ��B
		//�����L���b�N�i���[�h�E���C�g���b�N�j�ŃR���e�i������X���b�h�Z�[�t�ɂ������ꍇ�́A
		//�@base_ope_t�̔h���N���X�ɂāA�L���ȋ��L���b�N�^�ishared_spin_lock �Ȃǁj��
		//�@lock_type �^�Ƃ��čĒ�`����B
		//�y�⑫�@�z�R���e�i�ɂ́A���炩���߃��b�N����̂��߂̎d�g�݂��\�[�X�R�[�h���x����
		//�@�@�@�@�@�d����ł��邪�A�L���Ȍ^��^���Ȃ�����́A���s���̃I�[�o�[�w�b�h�͈�؂Ȃ��B
		//�y�⑫�A�z�X���b�h�Z�[�t�������ꍇ�A�������ݎ��̔r�����b�N�͍s����悤�ɂȂ邪�A
		//�@�@�@�@�@�ǂݍ��ݎ��̋��L���b�N�͍s���Ă��Ȃ��B�ǂݍ��ݎ��̃��b�N�͋Ǐ��I�ȃ��b�N��
		//�@�@�@�@�@�ς܂Ȃ����߁A���[�U�[���C�ӂɑΉ����Ȃ���΂Ȃ�Ȃ��B
		//�@�@�@�@�@�i��j
		//�@�@�@�@�@    {
		//�@�@�@�@�@        shared_lock_guard lock(container);//�R���e�i�I�u�W�F�N�g��n���ċ��L���b�N
		//�@�@�@�@�@                                          //���R���e�i�I�u�W�F�N�g�̓��b�N
		//�@�@�@�@�@                                          //�@�I�u�W�F�N�g�ilock_type�j�Ƃ��ĐU�镑����
		//�@�@�@�@�@        //...
		//�@�@�@�@�@        //��A�̃C�e���[�^����Ȃ�
		//�@�@�@�@�@        //...
		//�@�@�@�@�@    }//�X�R�[�v�𔲂��鎞�Ɏ����I�Ƀ��b�N���

		//�q�m�[�h���擾 ��const�O��(remove_const)
		inline static node_type* getChildL_rc(node_type& node){ return const_cast<node_type*>(ope_type::getChildL(const_cast<const node_type&>(node))); }//��i�E�j��
		inline static node_type* getChildS_rc(node_type& node){ return const_cast<node_type*>(ope_type::getChildS(const_cast<const node_type&>(node))); }//���i���j��
		//�q�m�[�h���擾
		inline static const node_type* getChild(const node_type& node, const bool child_is_large)
		{
			return child_is_large ?
				ope_type::getChildL(node) ://��i�E�j��
				ope_type::getChildS(node); //���i���j��
		}
		inline static node_type* getChild_rc(node_type& node, const bool child_is_large){ return const_cast<node_type*>(getChild(const_cast<const node_type&>(node), child_is_large)); }
		//�q�m�[�h��ύX
		inline static void setChild(node_type& node, const bool child_is_large, const node_type* child)
		{
			if (child_is_large)
				ope_type::setChildL(node, child);//��i�E�j��
			else
				ope_type::setChildS(node, child);//���i���j��
		}

		//�L�[���r
		//���f�t�H���g
		//Return value:
		//  0     ... lhs == rhs
		//  1�ȏ� ... lhs > rhs
		// -1�ȉ� ... lhs < rhs
		inline static int compareKey(const key_type lhs, const key_type rhs)
		{
			return static_cast<int>(lhs) - static_cast<int>(rhs);
		}

		//�m�[�h�ƃL�[���r
		inline static int compare(const node_type& lhs, const node_type& rhs)
		{
			return ope_type::compareKey(ope_type::getKey(lhs), ope_type::getKey(rhs));
		}
		inline static int compare(const node_type& lhs, const key_type rhs)
		{
			return ope_type::compareKey(ope_type::getKey(lhs), rhs);
		}
		inline static int compare(const key_type lhs, const node_type& rhs)
		{
			return ope_type::compareKey(lhs, ope_type::getKey(rhs));
		}
		inline static int compare(const key_type lhs, const key_type rhs)
		{
			return ope_type::compareKey(lhs, rhs);
		}
		inline static bool eq(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) == 0; }
		inline static bool eq(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) == 0; }
		inline static bool eq(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) == 0; }
		inline static bool ne(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) != 0; }
		inline static bool ne(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) != 0; }
		inline static bool ne(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) != 0; }
		inline static bool gt(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) > 0; }
		inline static bool gt(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) > 0; }
		inline static bool gt(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) > 0; }
		inline static bool ge(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool ge(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool ge(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool lt(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) < 0; }
		inline static bool lt(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) < 0; }
		inline static bool lt(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) < 0; }
		inline static bool le(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) <= 0; }
		inline static bool le(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) <= 0; }
		inline static bool le(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) <= 0; }

		//�F����
		inline static bool isBlack(const node_type& node){ return ope_type::getColor(node) == BLACK; }
		inline static bool isRed(const node_type& node){ return ope_type::getColor(node) == RED; }
		//�F�X�V
		inline static void setBlack(node_type& node){ ope_type::setColor(node, BLACK); }
		inline static void setRed(node_type& node){ ope_type::setColor(node, RED); }
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef typename ope_type::key_type key_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef stack_t<ope_type> stack_type; \
		typedef typename stack_type::info_t stack_info_type; \
		typedef typename ope_type::lock_type lock_type;
	//----------------------------------------
	//�f�o�b�O�p�⏕�֐�
#ifdef DEBUG_PRINT_FOR_ADD
	template<typename... Tx>
	inline int printf_dbg_add(const char* fmt, Tx... args)
	{
		return printf(fmt, args...);
	}
#else//DEBUG_PRINT_FOR_ADD
	inline int printf_dbg_add(const char* fmt, ...){ return 0; }
#endif//DEBUG_PRINT_FOR_ADD
#ifdef DEBUG_PRINT_FOR_REMOVE
	template<typename... Tx>
	inline int printf_dbg_remove(const char* fmt, Tx... args)
	{
		return printf(fmt, args...);
	}
#else//DEBUG_PRINT_FOR_REMOVE
	inline int printf_dbg_remove(const char* fmt, ...){ return 0; }
#endif//DEBUG_PRINT_FOR_REMOVE
	//--------------------
	//�ԍ��؏����p�X�^�b�N�N���X
	//���ԍ��؂̃m�[�h��������
	template<class OPE_TYPE>
	class stack_t
	{
	public:
		//��{�^
		typedef OPE_TYPE ope_type;
		typedef typename OPE_TYPE::node_type node_type;
	public:
		//�萔
		static const int DEPTH_MAX = ope_type::STACK_DEPTH_MAX;//�ő�̐[���i�X�^�b�N�����p�j
	public:
		//�^
		//�m�[�h���^
		struct info_t
		{
			const node_type* m_nodeRef;//�m�[�h�Q��
			bool m_isLarge;//��i�E�j���ɘA�����H
		};
	public:
		//�X�^�b�N�Ƀm�[�h�����L�^
		info_t* push(const node_type* node, const bool is_large)
		{
			assert(m_depth < DEPTH_MAX);
			info_t* stack_node = &m_array[m_depth++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
			return stack_node;
		}
		//�X�^�b�N����m�[�h�����擾
		info_t* pop()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[--m_depth];
		}
		//�X�^�b�N�̐擪�̃m�[�h�����Q��
		//���v�f������Ȃ�
		info_t* top()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[m_depth - 1];
		}
		//�X�^�b�N�̌��݂̐[�����擾
		int getDepth() const { return m_depth; }
		//�X�^�b�N�̌��݂̐[�����X�V
		void setDepth(const int depth)
		{
			if (depth < 0)
				m_depth = 0;
			else if (depth < m_depth)
				m_depth = depth;
		}
		//�X�^�b�N�̌��݂̐[�������Z�b�g
		void reset()
		{
			m_depth = 0;
		}
		//�X�^�b�N�̌��݂̕����Z�o
		//���u���v���X�^�b�N�̌��݂̐[���܂ł̑召�A���̍��v�l���Z�o
		//��������-1�A�呤��+1�Ƃ��Čv�Z
		long long calcBreadth()
		{
			long long breadth = 0;
			for (int depth = 0; depth < m_depth; ++depth)
			{
				breadth *= 2ll;
				breadth += (m_array[depth].m_isLarge ? 1ll : 0ll);
			}
			return breadth;
		}
		//���[�u�I�y���[�^
		inline stack_t& operator=(const stack_t&& rhs)
		{
			m_depth = rhs.m_depth;
			if (m_depth > 0)
				memcpy(m_array, rhs.m_array, sizeof(info_t)* m_depth);
			return *this;
		}
		//�R�s�[�I�y���[�^
		inline stack_t& operator=(const stack_t& rhs)
		{
			//return operator=(std::move(rhs));
			m_depth = rhs.m_depth;
			if (m_depth > 0)
				memcpy(m_array, rhs.m_array, sizeof(info_t)* m_depth);
			return *this;
		}
		//���[�u�R���X�g���N�^
		inline stack_t(const stack_t&& obj) :
			m_depth(obj.m_depth)
		{
			if (m_depth > 0)
				memcpy(m_array, obj.m_array, sizeof(info_t)* m_depth);
		}
		//�R�s�[�R���X�g���N�^
		inline stack_t(const stack_t& obj) :
			m_depth(obj.m_depth)
		{
			if (m_depth > 0)
				memcpy(m_array, obj.m_array, sizeof(info_t)* m_depth);
		}
		//�R���X�g���N�^
		inline stack_t() :
			m_depth(0)
		{}
	private:
		//�t�B�[���h
		info_t m_array[DEPTH_MAX];//�m�[�h���̔z��i�X�^�b�N�j
		int m_depth;//�X�^�b�N�̃J�����g�̐[��
	};
	//--------------------
	//�ԍ��ؑ���֐��F�ŏ��m�[�h�T��
	//���ォ��get**Node()��searchNode()�����s�ł���悤�ɁA�X�^�b�N��n���K�v����
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getSmallestNode(const typename OPE_TYPE::node_type* root, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* curr_node = root;//���݂̒T���m�[�h
		while (true)
		{
			const node_type* child_node = ope_type::getChildS(*curr_node);//���i���j���̎q�m�[�h���擾
			if (!child_node)//�q��������ΏI��
				return  curr_node;
			stack.push(curr_node, false);//�e�m�[�h���X�^�b�N�ɋL�^
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�ő�m�[�h�T��
	//���ォ��get**Node()��searchNode()�����s�ł���悤�ɁA�X�^�b�N��n���K�v����
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getLargestNode(const typename OPE_TYPE::node_type* root, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* curr_node = root;//���݂̒T���m�[�h
		while (true)
		{
			const node_type* child_node = ope_type::getChildL(*curr_node);//��i�E�j���̎q�m�[�h���擾
			if (!child_node)//�q��������ΏI��
				return  curr_node;
			stack.push(curr_node, true);//�e�m�[�h���X�^�b�N�ɋL�^
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//�ԍ��ؑ���֐��F���m�[�h�T���i�J�����g�m�[�h�̎��ɑ傫���m�[�h��T���j
	//��get**Node()��searchNode()�ŃJ�����g�m�[�h���擾�����ۂ̃X�^�b�N��n���K�v����
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getNextNode(const typename OPE_TYPE::node_type* curr_node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!curr_node)
			return nullptr;
		const node_type* child_node_l = ope_type::getChildL(*curr_node);//��i�E�j���̎q�m�[�h���擾
		if (child_node_l)//�q������ꍇ
		{
			stack.push(curr_node, true);//�e�m�[�h���X�^�b�N�ɋL�^
			return getSmallestNode<ope_type>(child_node_l, stack);//�q�����ԏ������q���m�[�h���擾
		}
		else//if(!child_node_l)//�q���Ȃ��ꍇ
		{
			const stack_info_type* stack_node = nullptr;
			while (stack_node = stack.pop())//�e�m�[�h���擾
			{
				if (stack_node->m_isLarge == false)//���i���j���̎q�̐e�Ȃ�I��
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�O�m�[�h�T���i�J�����g�m�[�h�̎��ɏ������m�[�h��T���j
	//��get**Node()��searchNode()�ŃJ�����g�m�[�h���擾�����ۂ̃X�^�b�N��n���K�v����
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getPrevNode(const typename OPE_TYPE::node_type* curr_node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!curr_node)
			return nullptr;
		const node_type* child_node_s = ope_type::getChildS(*curr_node);//���i���j���̎q�m�[�h���擾
		if (child_node_s)//�q������ꍇ
		{
			stack.push(curr_node, false);//�e�m�[�h���X�^�b�N�ɋL�^
			return getLargestNode<ope_type>(child_node_s, stack);//�q�����ԑ傫���q���m�[�h���擾
		}
		else//if(!child_node_s)//�q���Ȃ��ꍇ
		{
			const stack_info_type* stack_node = nullptr;
			while (stack_node = stack.pop())//�e�m�[�h���擾
			{
				if (stack_node->m_isLarge == true)//��i�E�j���̎q�̐e�Ȃ�I��
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h�T���i�w��̃L�[�ƈ�v����m�[�h�A�������́A�w��̃L�[�ɍł��߂��m�[�h�������j
	//���ォ��get**Node()��searchNode()�����s�ł���悤�ɁA�X�^�b�N��n���K�v����
	//����v�m�[�h����������ꍇ�A�ŏ��ʒu�ɂ���m�[�h��Ԃ�
	//���w��̃L�[�̓��ւōł��߂��m�[�h�Ɠ��L�[�̃m�[�h����������ꍇ�A���̍Ō�̃m�[�h��Ԃ�
	//���w��̃L�[���傫���ł��߂��m�[�h�Ɠ��L�[�̃m�[�h����������ꍇ�A���̍ŏ��̃m�[�h��Ԃ�
	enum match_type_t
	{
		FOR_MATCH = 0,//��v�m�[�h������
		FOR_NEAREST_SMALLER,//��v�m�[�h�A�������́A���ւōł��߂��m�[�h������
		FOR_NEAREST_LARGER,//��v�m�[�h�A�������́A������傫���ł��߂��m�[�h������
	};
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* searchNode(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::key_type key, stack_t<OPE_TYPE>& stack, const match_type_t search_type = FOR_MATCH)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* match_node = nullptr;//��v�m�[�h
		int match_stack_depth = -1;//��v�m�[�h���o���̃X�^�b�N�ʒu
		const node_type* nearest_node = nullptr;//�ŋ߃m�[�h
		int nearest_stack_depth = -1;//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu
		const node_type* curr_node = root;//���݂̒T���m�[�h
		while (true)
		{
			const int cmp = ope_type::compare(*curr_node, key);//�w��̃L�[�Ƒ召��r
			if (cmp == 0)//�w��̃L�[�ƈ�v
			{
				//���L�[�d�������e����A���S���Y���̂��߁A
				//�@��v�m�[�h���L�^������Ō����𑱍s����
				match_node = curr_node;//��v�m�[�h���L�^
				match_stack_depth = stack.getDepth();//��v�m�[�h���o���̃X�^�b�N�ʒu���L�^
				stack.push(curr_node, false);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = ope_type::getChildS(*curr_node);//���i���j���̎q�̕��Ɍ����𑱍s
				if (!curr_node)//�q��������ΒT���I��
					break;
			}
			else if (cmp < 0)//�w��̃L�[��菬����
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && ope_type::le(*nearest_node, *curr_node)))
				{
					nearest_node = curr_node;//�ŋ߃m�[�h���L�^
					nearest_stack_depth = stack.getDepth();//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu���L�^
				}
				const node_type* child_node = ope_type::getChildL(*curr_node);//��i�E�j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
					break;
				stack.push(curr_node, true);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = child_node;
			}
			else//if (cmp > 0)//�w��̃L�[���傫��
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && ope_type::ge(*nearest_node, *curr_node)))
				{
					nearest_node = curr_node;//�ŋ߃m�[�h���L�^
					nearest_stack_depth = stack.getDepth();//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu���L�^
				}
				const node_type* child_node = ope_type::getChildS(*curr_node);//���i���j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
					break;
				stack.push(curr_node, false);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = child_node;
			}
		}
		if (match_node)//��v�m�[�h���o��
		{
			stack.setDepth(match_stack_depth);//��v�m�[�h���o���̃X�^�b�N�ʒu�ɖ߂�
			return match_node;//��v�m�[�h��Ԃ�
		}
		else//if (!match_node)
		{
			if (nearest_node)//�ŋ߃m�[�h���o��
			{
				stack.setDepth(nearest_stack_depth);//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu�ɖ߂�
				return nearest_node;//�ŋ߃m�[�h��Ԃ�
			}
		}
		return nullptr;//�������s
	}
	//�����m�[�h�T�� ���L�[���w�肷�����ɁA�����̃m�[�h��n���ĒT������
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* searchNode(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::node_type* node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const key_type key = ope_type::getKey(*node);//�L�[���擾
		node_type* target_node = const_cast<node_type*>(searchNode<ope_type>(root, key, stack));//�L�[����v����m�[�h������
		if (!target_node)//�L�[����v����m�[�h���Ȃ���ΏI��
			return nullptr;
		while (target_node != node && ope_type::eq(*target_node, key))//�w��m�[�h�i�Ɠ����A�h���X�j������
			target_node = const_cast<node_type*>(getNextNode<ope_type>(target_node, stack));
		if (target_node != node)
			return nullptr;
		return target_node;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�؂̍ő�[�x���v��
	//�������ŃX�^�b�N���쐬
	//��-1�Ń��X�g�Ȃ�
	template<class OPE_TYPE>
	int getDepthMax(const typename OPE_TYPE::node_type* root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return -1;
		int depth_max = 0;//�ő�̐[��
		stack_type stack;//�X�^�b�N���쐬
		const node_type* node = getSmallestNode<ope_type>(root, stack);//�ŏ��m�[�h�擾
		while (node)
		{
			const int depth = stack.getDepth();//�[�����擾
			depth_max = depth_max >= depth ? depth_max : depth;//�ő�̐[�����X�V
			node = getNextNode<ope_type>(node, stack);//���̃m�[�h�擾
		}
		return depth_max;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�؂̃m�[�h�����v��
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type* node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
	#if 0
		//�ċA������
		return !node ? 0 : 1 + countNodes<ope_type>(ope_type::getChildL(*node)) +
		                       countNodes<ope_type>(ope_type::getChildS(*node));
	#else
		//���[�v������
		//���ċA�����ł������[�v�����ł̕�������
		//�@�����ۂɏ������Ԃ𑪒肵�Ċm�F
		//�@�@�ȉ��A�m�[�h��100�̌v����10000000��s��������
		//�@�@�E�ċA�����ŁF�@3.443212500 sec
		//�@�@�E���[�v�����ŁF1.663094300 sec
		int count = 0;
		const node_type* stack[stack_type::DEPTH_MAX];
		int stack_pos = 0;
		while (node)
		{
			while (node)
			{
				++count;
				stack[stack_pos++] = node;
				node = ope_type::getChildS(*node);
			}
			while (!node && stack_pos != 0)
				node = ope_type::getChildL(*stack[--stack_pos]);
		}
		return count;
	#endif
	}
	//--------------------
	//�ԍ��ؑ���֐��F�w��̃L�[�̃m�[�h�����v��
	//���֐����ŃX�^�b�N���g�p
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::key_type key)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return 0;
		stack_type stack;
		const node_type* node = searchNode<ope_type>(root, key, stack, FOR_MATCH);
		if (!node)
			return 0;
		int count = 0;//�m�[�h��
		while (node && ope_type::eq(*node, key))
		{
			++count;
			node = getNextNode<ope_type>(node, stack);
		}
		return count;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h�ǉ����̐ԍ��o�����X����
	template<class OPE_TYPE>
	void _balanceForAdd(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* curr_node, bool child_is_large, typename OPE_TYPE::node_type* child_node);
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h��ǉ�
	//���֐����ŃX�^�b�N���g�p
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* addNode(typename OPE_TYPE::node_type* new_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!new_node)
			return nullptr;
		ope_type::setChildL(*new_node, nullptr);//�V�K�m�[�h�̓����N���N���A�F��i�E�j��
		ope_type::setChildS(*new_node, nullptr);//�V�K�m�[�h�̓����N���N���A�F���i���j��
		if (!root)//���m�[�h�����o�^�̏ꍇ
		{
			root = new_node;//���m�[�h�ɓo�^
		#ifndef DISABLE_COLOR_FOR_ADD
			ope_type::setBlack(*root);//���m�[�h�͍�
		#endif//DISABLE_COLOR_FOR_ADD
			return new_node;//���̎��_�ŏ����I��
		}
	#ifndef DISABLE_COLOR_FOR_ADD
		ope_type::setRed(*new_node);//�V�K�m�[�h�͎b��Ő�
	#endif//DISABLE_COLOR_FOR_ADD
		key_type new_key = ope_type::getKey(*new_node);//�V�K�m�[�h�̃L�[���擾
		stack_type stack;//�X�^�b�N��p��
		node_type* curr_node = root;//���݂̒T���m�[�h
		bool new_key_is_large = false;
		while (true)
		{
			new_key_is_large = ope_type::ge(new_key, *curr_node);//�w��̃L�[�ƈ�v�������͎w��̃L�[�̕����傫�����true
			node_type* child_node = ope_type::getChild_rc(*curr_node, new_key_is_large);//�q�m�[�h���擾
			if (!child_node)//�q�m�[�h��������΂����ɐV�K�m�[�h��ǉ����ďI��
			{
				ope_type::setChild(*curr_node, new_key_is_large, new_node);//�q�m�[�h�Ƃ��ĐV�K�m�[�h��ǉ�
				break;
			}
			stack.push(curr_node, new_key_is_large);//�e�m�[�h���X�^�b�N�ɋL�^
			curr_node = child_node;
		}
	#ifndef DISABLE_COLOR_FOR_ADD
		//�ԍ��o�����X����
		_balanceForAdd<ope_type>(root, stack, curr_node, new_key_is_large, new_node);
	#endif//DISABLE_COLOR_FOR_ADD
		return new_node;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h�폜���̐ԍ��o�����X����
	template<class OPE_TYPE>
	void _balanceForRemove(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* removing_node, typename OPE_TYPE::node_type* replacing_node);
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h���폜
	//���֐����ŃX�^�b�N���g�p
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* removeNode(const typename OPE_TYPE::node_type* target_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!target_node || !root)
			return nullptr;
		stack_type stack;//�X�^�b�N��p��
		node_type* removing_node = const_cast<node_type*>(searchNode<ope_type>(root, target_node, stack));//�폜�m�[�h���������ăX�^�b�N�����
		if (!removing_node)//�����Ɏ��s������I��
			return nullptr;
		//�폜�J�n
		node_type* parent_node = nullptr;//�폜�m�[�h�̐e�m�[�h
		bool curr_is_large = false;//�폜�m�[�h�̐e�m�[�h����̘A������
		{
			stack_info_type* parent_info = stack.top();//�e�m�[�h�Q�Ə����擾
			if (parent_info)
			{
				parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//�e�m�[�h���擾
				curr_is_large = parent_info->m_isLarge;//�e�m�[�h����̘A������
			}
		}
		node_type* child_node_l = ope_type::getChildL_rc(*removing_node);//��i�E�j���̎q�m�[�h���擾
		node_type* child_node_s = ope_type::getChildS_rc(*removing_node);//���i���j���̎q�m�[�h���擾
		node_type* descendant_node = nullptr;//�폜�m�[�h�̍ő�q���m�[�h�i�폜�m�[�h�̎��ɏ������m�[�h�j
		node_type* replacing_node = nullptr;//�폜�m�[�h�ƒu��������m�[�h
		//�폜�m�[�h�ƒu��������m�[�h�̑I�o����
		//-------------------------------------------------------------------------
		//�y�؂̐����̖}��z
		//�E�u(S)�v�́A���i���j���̃m�[�h�������B
		//�E�u(L)�v�́A��i�E�j���̃m�[�h�������B
		//�E�u(SL)�v�́A���i���j���̎q�̑�i�E�j���̃m�[�h�������B
		//�@�i�u(LS)�v[(SS)�v�u(SSL)�v�Ȃǂ̃p�^�[�������l�j
		//�E�u(null)�v�́A�m�[�h���Ȃ����Ƃ������B
		//-------------------------------------------------------------------------
		if (child_node_s && !child_node_l)
		{
			//�폜�m�[�h�̏��i���j���ɂ̂ݎq�m�[�h������ꍇ�A�����u�������m�[�h�Ƃ���
			//-------------------------------------------------------------------------
			//            .-------[removing_node]------.                               
			//   .--[replacing_node]--.             (null)                             
			// [(SS)]              [(SL)]                                              
			//-------------------------------------------------------------------------
			//                          ���y�u�������z                                 
			//                 .--[replacing_node]--.                                  
			//               [(SS)]              [(SL)]                                
			//-------------------------------------------------------------------------
			replacing_node = child_node_s;//�폜�m�[�h�ƒu��������m�[�h���Z�b�g
		}
		else if (!child_node_s && child_node_l)
		{
			//�폜�m�[�h�̑�i�E�j���ɂ̂ݎq�m�[�h������ꍇ�A�����u�������m�[�h�Ƃ���
			//-------------------------------------------------------------------------
			//            .-------[removing_node]------.                               
			//          (null)              .--[replacing_node]--.                     
			//                            [(LS)]              [(LL)]                   
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                          ���y�u�������z                                 
			//                 .--[replacing_node]--.                                  
			//               [(LS)]              [(LL)]                                
			//-------------------------------------------------------------------------
			replacing_node = child_node_l;//�폜�m�[�h�ƒu��������m�[�h���Z�b�g
		}
		else if (child_node_s && child_node_l)
		{
			//�폜�m�[�h�̏��i���j���Ƒ�i�E�j���̗����̎q�m�[�h������ꍇ�A�O�m�[�h�i�ő�q���m�[�h�j��u�������m�[�h�Ƃ���
			//-------------------------------------------------------------------------
			//�y�P�[�X�@�z                                                             
			//            .---------------[removing_node]---------------.              
			//          [(S)]----.                                    [(L)]            
			//                   .(�ő�q��)                                           
			//           .--[replacing_node]--.                                        
			//         [(SLS)]             (null)                                      
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                                 ���y�u�������z                          
			//            .---------------[replacing_node]--------------.              
			//          [(S)]----.                                    [(L)]            
			//                   .(�ő�q��)                                           
			//                [(SLS)]                                                  
			//-------------------------------------------------------------------------
			//�y�P�[�X�A�z                                                             
			//            .---------------[removing_node]---------------.              
			//    .--[replacing_node]--.                              [(L)]            
			//  [(SLS)]             (null)                                             
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                                 ���y�u�������z                          
			//            .---------------[replacing_node]--------------.              
			//         [(SLS)]                                        [(L)]            
			//-------------------------------------------------------------------------
			stack_info_type* remove_info = stack.push(removing_node, false);//�X�^�b�N�ɍ폜�m�[�h��ǉ�
			descendant_node = const_cast<node_type*>(getLargestNode<ope_type>(child_node_s, stack));//�ő�q���m�[�h���擾
			replacing_node = descendant_node;//�폜�m�[�h�ƒu��������m�[�h���Z�b�g
			if (replacing_node != child_node_s)
			{
				//�y�P�[�X�@�F�O�m�[�h�i�ő�q���m�[�h�j���폜�m�[�h�̏��i���j���̎q�̍ő�q���z
				stack_info_type* descendant_parent_info = stack.top();//�ő�q���m�[�h�̐e�m�[�h���擾
				node_type* descendant_parent_node = const_cast<node_type*>(descendant_parent_info->m_nodeRef);//�ő�q���m�[�h�̐e�m�[�h���擾
				ope_type::setChildL(*descendant_parent_node, ope_type::getChildS(*replacing_node));//�ő�q���m�[�h�̐e�m�[�h�̑�i�E�j���̎q�m�[�h��ύX
				ope_type::setChildS(*replacing_node, child_node_s);//�u�������m�[�h�̏��i���j���̎q�m�[�h��ύX
			}
			else//if (descendant_node == child_node_s)
			{
				//�y�P�[�X�A�F�O�m�[�h�i�ő�q���m�[�h�j���폜�m�[�h�̏��i���j���̎q�z
				//�Ȃɂ����Ȃ�
			}
			ope_type::setChildL(*replacing_node, child_node_l);//�u�������m�[�h�̑�i�E�j���̎q�m�[�h��ύX
			remove_info->m_nodeRef = replacing_node;//�X�^�b�N��̍폜�m�[�h�Q�Ƃ�u�������m�[�h�Q�Ƃɏ�������
		}
		//else//if (!child_node_s && !child_node_l)
		//{
		//	//�폜�m�[�h�̏��i���j���Ƒ�i�E�j���̗����̎q�m�[�h���Ȃ��ꍇ�A�u�������m�[�h��nullptr
		//	replacing_node = nullptr;//�폜�m�[�h�ƒu��������m�[�h���Z�b�g
		//}
		//�폜�m�[�h�̒u����������
		ope_type::setChildL(*removing_node, nullptr);
		ope_type::setChildS(*removing_node, nullptr);
		if (!parent_node)//�e�m�[�h���Ȃ��ꍇ �� ���m�[�h���폜���ꂽ�ꍇ�ł���
		{
			root = replacing_node;//���m�[�h��u������
			if (!root)//���m�[�h���Ȃ��Ȃ�����A���̎��_�ŏ����I��
				return removing_node;
		}
		else//if(parent_node)//�e�m�[�h������ꍇ
		{
			ope_type::setChild(*parent_node, curr_is_large, replacing_node);//�e�m�[�h�̎q�m�[�h��u������
		}
	#ifndef DISABLE_COLOR_FOR_REMOVE
		//�ԍ��o�����X����
		_balanceForRemove<ope_type>(root, stack, removing_node, replacing_node);
	#endif//DISABLE_COLOR_FOR_REMOVE
		return removing_node;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�y�ėp�����z�m�[�h����]����
	//-------------------------------------------------------------------------
	//              .--------------[curr_node]--------------.                  
	//       [child_node_s]                     .----[child_node_l]            
	//                                    [child_node_ls]                      
	//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	//                               ���y����]�z                              
	//              .-------------[child_node_l]                               
	//      .-----[curr_node]----.                                             
	// [child_node_s]  [child_node_ls]                                         
	//-------------------------------------------------------------------------
	template<class OPE_TYPE>
	inline typename OPE_TYPE::node_type* _rotateL(typename OPE_TYPE::node_type* curr_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		node_type* child_node_l = ope_type::getChildL_rc(*curr_node);
		node_type* child_node_ls = ope_type::getChildS_rc(*child_node_l);
		ope_type::setChildS(*child_node_l, curr_node);
		ope_type::setChildL(*curr_node, child_node_ls);
		return child_node_l;
	};
	//--------------------
	//�ԍ��ؑ���֐��F�y�ėp�����z�m�[�h�E��]����
	//-------------------------------------------------------------------------
	//        .--------------[curr_node]--------------.                        
	// [child_node_s]----.                       [child_node_l]                
	//          [child_node_sl]                                                
	//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	//                            ���y�E��]�z                                 
	//                      [child_node_s]------------.                        
	//                                      .----[curr_node]----.              
	//                                 [child_node_sl]  [child_node_l]         
	//-------------------------------------------------------------------------
	template<class OPE_TYPE>
	inline typename OPE_TYPE::node_type* _rotateR(typename OPE_TYPE::node_type* curr_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		node_type* child_node_s = ope_type::getChildS_rc(*curr_node);
		node_type* child_node_sl = ope_type::getChildL_rc(*child_node_s);
		ope_type::setChildL(*child_node_s, curr_node);
		ope_type::setChildS(*curr_node, child_node_sl);
		return child_node_s;
	};
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h�ǉ����̐ԍ��o�����X����
	template<class OPE_TYPE>
	void _balanceForAdd(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* curr_node, bool child_is_large, typename OPE_TYPE::node_type* child_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		bool is_rotated = false;//��]�����ς݃t���O
		bool is_balanced = false;//���t��Ԍ��o�t���O
		while (true)
		{
			stack_info_type* parent_info = stack.pop();//�X�^�b�N����e�m�[�h���擾
			if (!parent_info)
				break;
			node_type* parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//�e�m�[�h�擾
			bool curr_is_large = parent_info->m_isLarge;//�e�m�[�h����̑召�A�����擾
			if (is_rotated)//�O���]�����ς݂Ȃ�e�m�[�h�̎q�m�[�h��A��������
			{
				ope_type::setChild(*parent_node, curr_is_large, curr_node);
				is_rotated = false;//��]�����ςݏ�ԃ��Z�b�g
			}
			//��]����
			//-------------------------------------------------------------------------
			//�y�؂̐����̖}��z
			//�E�u:B�v�́A���������B
			//�E�u:R�v�́A�Ԃ������B
			//�E�u:+B�v�́A���ɕύX���邱�Ƃ������B
			//�E�u:+R�v�́A�ԂɕύX���邱�Ƃ������B
			//�E�u(S)�v�́A���i���j���̃m�[�h�������B
			//�E�u(L)�v�́A��i�E�j���̃m�[�h�������B
			//�E�u(SL)�v�́A���i���j���̎q�̑�i�E�j���̃m�[�h�������B
			//�@�i�u(LS)�v[(SS)�v�u(SSL)�v�Ȃǂ̃p�^�[�������l�j
			//�E�u(null)�v�́A�m�[�h���Ȃ����Ƃ������B
			//-------------------------------------------------------------------------
			if (!is_balanced && ope_type::isBlack(*curr_node))//���݃m�[�h�����Ȃ畽�t��Ԍ��o�i�Ȍ�̏����ᔽ�`�F�b�N�͕s�v�j
				is_balanced = true;
			if (!is_balanced && ope_type::isRed(*child_node))//�ԃm�[�h����A�����Ă���������ᔽ�̂��߁A��]����
			{
				//�y���ʏ����z�e�m�[�h������]����
				//-------------------------------------------------------------------------
				//             .-------[parent_node:B]--------.                            
				//           [(S)]                    .--[curr_node:R]--.                  
				//                                  [(LS)]       [child_node:R]            
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ���y����]�z                                   
				//          .-----------[curr_node:R]---------.                            
				//   .--[parent_node:B]--.               [child_node:R]                    
				// [(S)]              [(LS)]                                               
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ���y�ϐ��ƐF�𒲐��z                           
				//                                                  ����                   
				//            .--------[parent_node:R]--------.      ��                    
				//   .------[(S):B]------.                [curr_node:+B]                   
				// [(SS)]             [(SL)]                                               
				//-------------------------------------------------------------------------
				auto rotateParentL = [&]() -> const node_type*
				{
					parent_node = _rotateL<ope_type>(parent_node);//����]����
					curr_is_large = true;
					curr_node = child_node;
					ope_type::setBlack(*curr_node);//�m�[�h�����ɂ���
					//child_is_large = true;
					//child_node = nullptr;
					return parent_node;
				};
				//�y���ʏ����z�e�m�[�h���E��]����
				//-------------------------------------------------------------------------
				//               .-----[parent_node:B]-----.                               
				//       .--[curr_node:R]--.             [(L)]                             
				// [child_node:R]       [(SL)]                                             
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                            ���y�E��]�z                                 
				//               .-------[curr_node:R]-------.                             
				//          [child_node:R]         .--[parent_node:B]--.                   
				//                               [(SL)]              [(L)]                 
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                            ���y�ϐ��ƐF�𒲐��z                         
				//               .-------[parent_node:R]-----.                             
				//           [curr_node:+B]        .------[(L):B]------.                   
				//                      ��       [(LS)]             [(LL)]                 
				//                     ����                                                
				//-------------------------------------------------------------------------
				auto rotateParentR = [&]() -> const node_type*
				{
					parent_node = _rotateR<ope_type>(parent_node);//�E��]����
					curr_is_large = false;
					curr_node = child_node;
					ope_type::setBlack(*curr_node);//�m�[�h�����ɂ���
					//child_is_large = false;
					//child_node = nullptr;
					return parent_node;
				};
				//�y���ʏ����z���݂̃m�[�h������]����
				//-------------------------------------------------------------------------
				//           .-------[curr_node:R]-------.                                 
				//         [(S)]                .--[child_node:R]                          
				//                            [(LS)]                                       
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ���y����]�z                                   
				//           .-------[child_node:R]                                        
				//   .--[curr_node:R]--.                                                   
				// [(S)]            [(LS)]                                                 
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ���y�ϐ��𒲐��z���F�̒����͂��Ȃ�             
				//           .--------[curr_node:R]                                        
				//   .--[child_node:R]--.                                                  
				// [(SS)]            [(SL)]                                                
				//-------------------------------------------------------------------------
				auto rotateCurrL = [&]() -> const node_type*
				{
					node_type* curr_node_tmp = curr_node;
					curr_node = _rotateL<ope_type>(curr_node);//����]����
					child_is_large = false;
					child_node = curr_node_tmp;
					return curr_node;
				};
				//�y���ʏ����z���݂̃m�[�h���E��]����
				//-------------------------------------------------------------------------
				//       .--------[curr_node:R]--------.                                   
				// [child_node:R]--.                 [(L)]                                 
				//              [(SS)]                                                     
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                     ���y�E��]�z                                        
				//               [child_node:R]-------.                                    
				//                           .--[curr_node:R]--.                           
				//                         [(SS)]            [(L)]                         
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                     ���y�ϐ��𒲐��z���F�̒����͂��Ȃ�                  
				//                [curr_node:R]-------.                                    
				//                          .--[child_node:R]--.                           
				//                        [(LS)]            [(LL)]                         
				//-------------------------------------------------------------------------
				auto rotateCurrR = [&]() -> const node_type*
				{
					node_type* curr_node_tmp = curr_node;
					curr_node = _rotateR<ope_type>(curr_node);//�E��]����
					child_is_large = true;
					child_node = curr_node_tmp;
					return curr_node;
				};
				//�e��Ԃɍ��킹����]����
				if (!curr_is_large && !child_is_large)
				{
					//�y��]�P�[�X[S-S]�F�m���i���j���̎q�F�ԁn���m���i���j���̎q�F�ԁn�z
					//-------------------------------------------------------------------------
					//               .-----[parent_node:B]-----.                               
					//       .--[curr_node:R]--.             [(L)]                             
					// [child_node:R]       [(SL)]                                             
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                            ���y�e�m�[�h���E��]�z                       
					//               .-------[curr_node:R]-------.                             
					//          [child_node:R]         .--[parent_node:B]--.                   
					//                               [(SL)]              [(L)]                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                            ���y�ϐ��ƐF�𒲐��z                         
					//               .-------[parent_node:R]-----.                             
					//           [curr_node:+B]         .------[(L):B]------.                  
					//                      ��        [(LS)]             [(LL)]                
					//                     ����                                                
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-SS-[%d:B]��[%d:R]��[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					rotateParentR();//�e�m�[�h���E��]����
				}
				else if (!curr_is_large &&  child_is_large)
				{
					//�y��]�P�[�X[S-L]�F�m���i���j���̎q�F�ԁn���m��i�E�j���̎q�F�ԁn�z
					//-------------------------------------------------------------------------
					//                       .-----------------[parent_node:B]-------.         
					//               .--[curr_node:R]--.                           [(L)]       
					//             [(SS)]        .--[child_node:R]--.                          
					//                        [(SLS)]          [(SLL)]                         
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ���y���݃m�[�h������]�z  
					//                        .----------------[parent_node:B]-------.         
					//           .------[child_node:R]------.                      [(L)]       
					//   .--[curr_node:R]--.            [(SLL)]                                
					// [(SS)]          [(SLS)]                                                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ���y�e�m�[�h���E��]�z    
					//                        .-----------------[child_node:R]-------.         
					//                .--[curr_node:R]--.               .--[parent_node:B]--.  
					//              [(SS)]           [(SLS)]          [(SLL)]             [(L)]
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ���y�ϐ��ƐF�𒲐��z      
					//                        .-----------------[parent_node:R]-----.          
					//                .--[curr_node:+B]--.                  .-----[(L):B]---.  
					//               [(SS)])        �� [(SL)]             [(LS)]         [(LL)]
					//                             ����                                        
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-SL-[%d:B]��[%d:R]��[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					ope_type::setChildS(*parent_node, rotateCurrL());//���݂̃m�[�h������]����
					rotateParentR();//�e�m�[�h���E��]����
				}
				else if (curr_is_large && !child_is_large)
				{
					//�y��]�P�|�X[L-S]�F�m��i�E�j���̎q�F�ԁn���m���i���j���̎q�F�ԁn�z
					//---------------------------------------------------------------------------------
					//             .-------[parent_node:B]----------------.                            
					//           [(S)]                       .-------[curr_node:R]-------.             
					//                               .--[child_node:R]--.              [(LL)]          
					//                             [(LSS)]          [(LSL)]                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ���y���݃m�[�h���E��]�z                               
					//             .-------[parent_node:B]-----------------.                           
					//           [(S)]                       .-------[child_node:R]-------.            
					//                                     [(LSS)]                .--[curr_node:R]--.  
					//                                                          [(LSL)]          [(LL)]
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ���y�e�m�[�h������]�z                                 
					//           .----------[child_node:R]---------.                                   
					//   .--[parent_node:B]--.             .--[curr_node:R]--.                         
					// [(S)]             [(LSS)]         [(LSL)]          [(LL)]                       
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ���y�ϐ��ƐF�𒲐��z                                   
					//            .--------[parent_node:R]--------.       ������                       
					//   .------[(S):B]------.              .--[curr_node:+B]--.                       
					// [(SS)]             [(SL)]          [(LSL)]           [(LL)]                     
					//---------------------------------------------------------------------------------
					printf_dbg_add("<ADD-LS-[%d:B]��[%d:R]��[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					ope_type::setChildL(*parent_node, rotateCurrR());//���݂̃m�[�h���E��]����
					rotateParentL();//�e�m�[�h������]����
				}
				else//if (!curr_is_large && !child_is_large)
				{
					//�y��]�P�[�X[L-L]�F�m��i�E�j���̎q�F�ԁn���m��i�E�j���̎q�F�ԁn�z
					//-------------------------------------------------------------------------
					//             .-------[parent_node:B]--------.                            
					//           [(S)]                    .--[curr_node:R]--.                  
					//                                  [(LS)]       [child_node:R]            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ���y�e�m�[�h������]�z                         
					//          .-----------[curr_node:R]---------.                            
					//   .--[parent_node:B]--.               [child_node:R]                    
					// [(S)]              [(LS)]                                               
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ���y�ϐ��ƐF�𒲐��z                           
					//            .--------[parent_node:R]--------.      �� ����               
					//   .------[(S):B]------.                [curr_node:+B]                   
					// [(SS)]             [(SL)]                                               
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-LL-[%d:B]��[%d:R]��[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					rotateParentL();//�e�m�[�h������]����
				}
				is_rotated = true;//��]�ς�
			}
			//�e�m�[�h�ɏ������ڂ�
			child_is_large = curr_is_large;
			child_node = curr_node;
			curr_node = parent_node;
		}
		if (curr_node)
		{
			root = curr_node;//���m�[�h���X�V
			ope_type::setBlack(*root);//���m�[�h�͍�
		}
	}
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h�폜���̐ԍ��o�����X����
	template<class OPE_TYPE>
	void _balanceForRemove(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* removing_node, typename OPE_TYPE::node_type* replacing_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		bool is_necessary_rotate = false;//��]�����K�v�H
		bool remove_node_is_black = ope_type::isBlack(*removing_node);
		bool replace_node_is_black = replacing_node ? ope_type::isBlack(*replacing_node) : false;
		//��]�����K�v����
		//-------------------------------------------------------------------------
		//�y�؂̐����̖}��z
		//�E�u:B�v�́A���������B
		//�E�u:R�v�́A�Ԃ������B
		//�E�u:R/n�v�́A�ԁA�������́A�m�[�h���Ȃ����Ƃ������B
		//�E�u:+B�v�́A���ɕύX���邱�Ƃ������B
		//�E�u:+R�v�́A�ԂɕύX���邱�Ƃ������B
		//�E�u(S)�v�́A���i���j���̃m�[�h�������B
		//�E�u(L)�v�́A��i�E�j���̃m�[�h�������B
		//�E�u(SS)�v�́A���i���j���̎q�̏��i���j���̃m�[�h�������B
		//�E�u(SL)�v�́A���i���j���̎q�̑�i�E�j���̃m�[�h�������B
		//�@�i�u(LS)�v[(SS)�v�u(SSL)�v�Ȃǂ̃p�^�[�������l�j
		//�E�u(null)�v�́A�m�[�h���Ȃ����Ƃ������B
		//-------------------------------------------------------------------------
		if (!remove_node_is_black)//�폜�m�[�h���Ԃ̏ꍇ
		{
			if (!replacing_node)//�u�������m�[�h���Ȃ��ꍇ
			{
				//�y����P�[�X[R-on-null]�F�폜�m�[�h���ԁA�u�������m�[�h���Ȃ��z�F��]�����s�v
				//-------------------------------------------------------------------------
				//    .--[removing_node:R]--.                                              
				// (null)                 (null)                                           
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//             ���y�폜�z                                                  
				//           (null)                                                        
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//����������Ȃ��̂ŁA�؂ɉe�����Ȃ��B                                     
				//-------------------------------------------------------------------------
				//�y�ŏI��Ԃ̓����z                                                       
				//�E�ԍ��̈ʒu�֌W�i�����B�j��                                             
				//�@���̃o�����X�i�����C�j������Ȃ��B                                     
				//-------------------------------------------------------------------------
				printf_dbg_remove("<DEL-Rn-[%d:R]��(null)=END", ope_type::getKey(*removing_node));
				//is_necessary_rotate = false;//��]�����s�v
			}
			else//if(replacing_node)//�u�������m�[�h������ꍇ
			{
				if (!replace_node_is_black)//�u�������m�[�h�����̏ꍇ
				{
					//�y����P�[�X[R-on-R]�F�폜�m�[�h���ԁA�u�������m�[�h���ԁz�F��]�����s�v
					//-------------------------------------------------------------------------
					//     .---------------------[removing_node:R]-----.                       
					//  [(S:B)]---------.                           [(L:B)]                    
					//                  .(�ő�q��)                                            
					//         .--[replacing_node:R]--.                                        
					//      [(SLS)]                 (null)                                     
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�u�������z                         
					//     .---------------------[replacing_node:R]----.                       
					//  [(S:B)]---------.                           [(L:B)]                    
					//                  .(�ő�q��)                                            
					//               [(SLS)]                                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//����������Ȃ��̂ŁA�؂ɉe�����Ȃ��B                                     
					//-------------------------------------------------------------------------
					//�y���̃P�[�X�z                                                           
					//���u�������m�[�h���폜�m�[�h�̎q�ł���P�[�X�͂Ȃ��B                     
					//�@�i�Ԃ̎q���Ԃł����Ă͂����Ȃ����[���̂��߁j                           
					//-------------------------------------------------------------------------
					//�y�ŏI��Ԃ̓����z                                                       
					//�E�ԍ��̈ʒu�֌W�i�����B�j��                                             
					//�@���̃o�����X�i�����C�j������Ȃ��B                                     
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-RR-[%d:R]��[%d:R]=END>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					//is_necessary_rotate = false;//��]�����s�v
				}
				else//if (replace_node_is_black)//�u�������m�[�h�����̏ꍇ
				{
					//�y����P�[�X[R-on-B]�F�폜�m�[�h���ԁA�u�������m�[�h�����z�F��]�����K�v
					//-------------------------------------------------------------------------
					//�y�P�[�X�@�z                                                             
					//     .---------------------[removing_node:R]-----.                       
					//  [(S:B)]---------.                           [(L:B)]                    
					//                  .(�ő�q��)                                            
					//         .--[replacing_node:B]--.                                        
					//      [(SLS)]                 (null)                                     
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�u�������z                         
					//     .---------------------[replacing_node:B]----.                       
					//  [(S:B)]---------.                           [(L:B)]                    
					//                  .(�ő�q��)                                            
					//               [(SLS)]                                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�F�𒲐��z                         
					//     .---------------------[replacing_node:+R]----.                      
					//  [(S:B)]---------.                        ��  [(L:B)]                   
					//                  .(�ő�q��)             �Ԃ�                           
					//               [(SLS)]                                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//���u(SLS)�v�Ƃ��̌Z��ō��̃o�����X�������̂ŁA                        
					//�@�u(SLS)�v���璲���i��]�����j���K�v�B                                  
					//-------------------------------------------------------------------------
					//�y�P�[�X�A�z                                                             
					//                    .------[removing_node:R]-----.                       
					//     .----[replacing_node:B]----.             [(L:B)]                    
					// [(SS:R/n)]                   (null)                                     
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�u�������z                         
					//       .-------------------[replacing_node:B]----.                       
					//   [(SS:R/n)]----.                            [(L:B)]                    
					//               (null)                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�F�𒲐��z                         
					//       .-------------------[replacing_node:+R]---.                       
					//   [(SS:R/n)]----.                            [(L:B)]                    
					//               (null)                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//���u(SS:R/n)�v�Ɓu(L:B)�v�ō��̃o�����X�������̂ŁA                    
					//�@�u(SS:R/n)�v���璲���i��]�����j���K�v�B                               
					//-------------------------------------------------------------------------
					//�y�Q�l�P�[�X�@�z�����̏�Ԃ͊��ɏ����C�Ɉᔽ���Ă��邽�߁A���肦�Ȃ�     
					//              .-----[removing_node:R]-----.                              
					//   .--[replacing_node:B]--.             (null)                           
					// [(SS)]                [(SL)]                                            
					//-------------------------------------------------------------------------
					//�y�Q�l�P�[�X�A�z�����̏�Ԃ͊��ɏ����C�Ɉᔽ���Ă��邽�߁A���肦�Ȃ�     
					//      .-----[removing_node:R]-----.                                      
					//    (null)           .--[replacing_node:B]--.                            
					//                   [(LS)]                [(LL)]                          
					//-------------------------------------------------------------------------
					//�y�ŏI��Ԃ̓����z                                                       
					//�E�u���������̈ʒu�ŁA���̃o�����X�i�����C�j�������B                   
					//�E�u���������̈ʒu�ŁA�ԁ��Ԃ̘A���i�����B�ᔽ�j���N����\��������B   
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-RB-[%d:R]��[%d:B]=ROT>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					is_necessary_rotate = true;//��]�����K�v
					ope_type::setRed(*replacing_node);//�u�������m�[�h��Ԃɂ���
					//remove_node_is_black = true;//�폜�m�[�h�͍�
					//                            //���u���������̃m�[�h���폜���ꂽ���̂Ƃ��ď�������
				}
			}
		}
		else//if (remove_node_is_black)//�폜�m�[�h�����̏ꍇ
		{
			if (!replacing_node)//�u�������m�[�h���Ȃ��ꍇ
			{
				//�y����P�[�X[B-on-null]�F�폜�m�[�h�����A�u�������m�[�h���Ȃ��z�F��]�����K�v
				//-------------------------------------------------------------------------
				//    .--[removing_node:B]--.                                              
				// (null)                 (null)                                           
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//             ���y�폜�z                                                  
				//           (null)                                                        
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//�����������̂ŁA                                                     
				//�@�e�ɑk���Ė؂̒����i��]�����j���K�v�B                                 
				//-------------------------------------------------------------------------
				//�y�ŏI��Ԃ̓����z                                                       
				//�E�u���������̈ʒu�ŁA���̃o�����X�i�����C�j�������B                   
				//�E�u���������̈ʒu�ŁA�ԁ��Ԃ̘A���i�����B�ᔽ�j���N����\��������B   
				//-------------------------------------------------------------------------
				printf_dbg_remove("<DEL-Bn-[%d:B]��(null)=ROT>", ope_type::getKey(*removing_node));
				is_necessary_rotate = true;//��]�����K�v
			}
			else//if(replacing_node)//�u�������m�[�h������ꍇ
			{
				if (!replace_node_is_black)//�u�������m�[�h���Ԃ̏ꍇ
				{
					//�y����P�[�X[B-on-R]�F�폜�m�[�h�����A�u�������m�[�h���ԁz�F��]�����s�v
					//-------------------------------------------------------------------------
					//�y�P�[�X�@�z                                                             
					//     .---------------------[removing_node:B]-----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(�ő�q��)                                             
					//        .--[replacing_node:R]--.                                         
					//     [(SLS)]                (null)                                       
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�u�������z                         
					//     .---------------------[replacing_node:R]----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(�ő�q��)                                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�F�𒲐��z                         
					//     .---------------------[replacing_node:+B]----.                      
					//   [(S)]---------.                       ��     [(L)]                    
					//                 .(�ő�q��)            ����                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//�����ʓI�ɍ�������Ȃ��̂ŁA�؂ɉe�����Ȃ��B                             
					//-------------------------------------------------------------------------
					//�y�P�[�X�A�z                                                             
					//               .-----[removing_node:B]-----.                             
					//    .--[replacing_node:R]--.            [(L:R/n)]                        
					// [(null)]               [(null)]                                         
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ���y�u�������z                                 
					//               .-----[replacing_node:R]-----.                            
					//            [(null)]                     [(L:R/n)]                       
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ���y�F�𒲐��z                                 
					//               .-----[replacing_node:+B]----.                            
					//            [(null)]                 ��  [(L:R/n)]                       
					//                                    ����                                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//�����ʓI�ɍ�������Ȃ��̂ŁA�؂ɉe�����Ȃ��B                             
					//-------------------------------------------------------------------------
					//�y�P�[�X�B�z                                                             
					//      .-----[removing_node:B]-----.                                      
					//    (null)           .--[replacing_node:R]--.                            
					//                  [(null)]               [(null)]                        
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ���y�u�������z                                       
					//      .-----[replacing_node:R]-----.                                     
					//   [(null)]                     [(null)]                                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ���y�F�𒲐��z                                       
					//      .-----[replacing_node:+B]----.                                     
					//   [(null)]                ��   [(null)]                                 
					//                         ����                                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//�����ʓI�ɍ�������Ȃ��̂ŁA�؂ɉe�����Ȃ��B                             
					//-------------------------------------------------------------------------
					//�y�ŏI��Ԃ̓����z                                                       
					//�E�ԍ��̈ʒu�֌W�i�����B�j��                                             
					//�@���̃o�����X�i�����C�j������Ȃ��B                                     
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-BR-[%d:B]��[%d:R]=END>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					//is_necessary_rotate = false;//��]�����s�v
					ope_type::setBlack(*replacing_node);//�u�������m�[�h�����ɂ���
					//remove_node_is_black = false;//�폜�m�[�h�͐�
					//                             //���u���������̃m�[�h���폜���ꂽ���̂Ƃ��ď�������
				}
				else//if (replace_node_is_black)//�u�������m�[�h�����̏ꍇ
				{
					//�y�͈̓P�[�X[B-on-B]�F�폜�m�[�h�����A�u�������m�[�h�����z�F��]�����K�v
					//-------------------------------------------------------------------------
					//�y�P�[�X�@�z                                                             
					//     .---------------------[removing_node:B]-----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(�ő�q��)                                             
					//        .--[replacing_node:B]--.                                         
					//     [(SLS)]              (null)                                         
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�u�������z                         
					//     .---------------------[replacing_node:B]----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(�ő�q��)                                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//���u(SLS)�v�Ƃ��̌Z��ō��̃o�����X�������̂ŁA                        
					//�@�u(SLS)�v���璲���i��]�����j���K�v�B                                  
					//-------------------------------------------------------------------------
					//�y�P�[�X�A�z                                                             
					//                    .------[removing_node:B]-----.                       
					//     .----[replacing_node:B]----.              [(L)]                     
					// [(SS:R/n)]                   (null)                                     
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ���y�u�������z                         
					//       .-------------------[replacing_node:B]----.                       
					//   [(SS:R/n)]----.                             [(L)]                     
					//               (null)                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//���u(SS:R/n)�v�Ɓu(L)�v�ō��̃o�����X�������̂ŁA                      
					//�@�u(SS:R/n)�v���璲���i��]�����j���K�v�B                               
					//-------------------------------------------------------------------------
					//�y�Q�l�P�[�X�@�z�����̏�Ԃ͊��ɏ����C�Ɉᔽ���Ă��邽�߁A���肦�Ȃ�     
					//              .-----[removing_node:B]-----.                              
					//   .--[replacing_node:B]--.             (null)                           
					// [(SS)]                [(SL)]                                            
					//-------------------------------------------------------------------------
					//�y�Q�l�P�[�X�A�z�����̏�Ԃ͊��ɏ����C�Ɉᔽ���Ă��邽�߁A���肦�Ȃ�     
					//      .-----[removing_node:B]-----.                                      
					//    (null)           .--[replacing_node:B]--.                            
					//                   [(LS)]              [(LL)]                            
					//-------------------------------------------------------------------------
					//�y�ŏI��Ԃ̓����z                                                       
					//�E�ԍ��̈ʒu�֌W�i�����B�j�͕ۂ���邪�A                                 
					//�@���̃o�����X�i�����C�j�������B                                       
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-BB-[%d:B]��[%d:B]=ROT>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					is_necessary_rotate = true;//��]�����K�v
				}
			}
		}
		//��]����
		//�����m�[�h���폜���ꂽ���̂݉�]���s��
		//-------------------------------------------------------------------------
		//�y�؂̐����̖}��z
		//�E�u:B�v�́A���������B
		//�E�u:R�v�́A�Ԃ������B
		//�E�u:?�v�́A���������͐Ԃ������B
		//�E�u:?/n�v�́A���������͐ԁA�������́A�m�[�h���Ȃ����Ƃ������B
		//�E�u:B/n�v�́A���A�������́A�m�[�h���Ȃ����Ƃ������B
		//�E�u:-B�v�́A���̃m�[�h�A�������́A���̎q���ŁA���m�[�h�̍폜�����������Ƃ������B
		//�E�u:+B�v�́A���ɕύX���邱�Ƃ������B
		//�E�u:+R�v�́A�ԂɕύX���邱�Ƃ������B
		//�E�u:+?�v�́A���̈ʒu�Ɠ����F�ɕύX���邱�Ƃ������B
		//�E�u(S)�v�́A���i���j���̃m�[�h�������B
		//�E�u(L)�v�́A��i�E�j���̃m�[�h�������B
		//�E�u(SL)�v�́A���i���j���̎q�̑�i�E�j���̃m�[�h�������B
		//�@�i�u(LS)�v[(SS)�v�u(SSL)�v�Ȃǂ̃p�^�[�������l�j
		//�E�u(null)�v�́A�m�[�h���Ȃ����Ƃ������B
		//-------------------------------------------------------------------------
		if (is_necessary_rotate)
		{
			node_type* parent_node = nullptr;//�e�m�[�h
			node_type* parent_node_prev = nullptr;//�O��̃��[�v�����ł̐e�m�[�h
			bool curr_is_large = false;//�e�m�[�h����̘A������
			while (true)
			{
				stack_info_type* parent_info = stack.pop();//�e�m�[�h�����擾
				if (!parent_info)
					break;
				parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//�e�m�[�h���擾
				curr_is_large = parent_info->m_isLarge;//�e�m�[�h����̘A���������擾
				if (parent_node_prev)//�O��̃��[�v�����ł̐e�m�[�h��e�q�A��
				{
					ope_type::setChild(*parent_node, curr_is_large, parent_node_prev);
					parent_node_prev = nullptr;//�O��̃��[�v�����ł̐e�m�[�h���N���A
				}
				if (is_necessary_rotate)//��]�������K�v
				{
					node_type* curr_node =//���݂̃m�[�h�擾 �����̑��ō��m�[�h����������Ă���
						parent_node ?
							ope_type::getChild_rc(*parent_node, curr_is_large) :
							nullptr;
					node_type* sibling_node =//�Z��m�[�h�擾
						parent_node ?
							ope_type::getChild_rc(*parent_node, !curr_is_large) :
							nullptr;
					node_type* sibling_node_s =//�Z��m�[�h�̏��i���j���̎q�m�[�h�擾
						sibling_node ?
							ope_type::getChildS_rc(*sibling_node) :
							nullptr;
					node_type* sibling_node_l =//�Z��m�[�h�̑�i�E�j���̎q�m�[�h�擾
						sibling_node ?
							ope_type::getChildL_rc(*sibling_node) :
							nullptr;
					if (sibling_node)//�Z��m�[�h�����݂���ꍇ
					{
						if (!curr_is_large)//�y�P�[�X�F�m���i���j���F���n���폜�z
						{
							if (ope_type::isBlack(*sibling_node))//�y�P�[�X�F�폜���̌Z�킪�m��i�E�j���F���n�z
							{
								if (sibling_node_s && ope_type::isRed(*sibling_node_s))//�y�P�[�X�F�Z��̎q���m���i���j���̎q�F�ԁn�z
								{
									//�y��]�P�[�X[S-1]�F�m�폜�F���i���j���F���n���m�Z��F��i�E�j���F���n���m���i���j���̎q�F�ԁn�z
									//-------------------------------------------------------------------------------------------------
									//              .----------[parent_node:?]-------------------.                                     
									//        [curr_node:-B]                      .------[sibling_node:B]------.                       
									//                                   .--[sibling_node_s:R]--.      [sibling_node_l:?/n]            
									//                                [(LSS)]                [(LSL)]                                   
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ���y�Z��m�[�h���E��]�z                                          
									//              .----------[parent_node:?]-------------------.                                     
									//        [curr_node:-B]                      .------[sibling_node_s:R]------.                     
									//                                         [(LSS)]                .--[sibling_node:B]--.           
									//                                                             [(LSL)]         [sibling_node_l:?/n]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ���y�e�m�[�h������]�z                                            
									//              .----------[sibling_node_s:R]----------------.                                     
									//     .--[parent_node:?]--.                   .------[sibling_node:B]------.                      
									// [curr_node:-B]       [(LSS)]             [(LSL)]                 [sibling_node_l:?/n]           
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ���y�F�𒲐��z                                                    
									//                                         ������parent_node�Ɠ����F��                             
									//              .----------[sibling_node_s:+?]----------------.                                    
									//     .--[parent_node:+B]--.                   .------[sibling_node:B]------.                     
									// [curr_node:?]       ��[(LSS)]             [(LSL)]                 [sibling_node_l:?/n]          
									//           ��       ����                                                                         
									//          ��́u+B�v�ɂ��A���́u-B�v������                                                     
									//-------------------------------------------------------------------------------------------------
									//�y�ŏI��Ԃ̓����z                                                                               
									//�E�ԍ��̈ʒu�֌W�i�����B�j�͕ۂ����B                                                           
									//�E�����؂̏��i���j���ɍ���������邱�ƂŁA                                                     
									//�@�ؑS�̂̃o�����X�i�����C�j���񕜂��A�؂̒����͊�������B                                       
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//�y������Ԃ̍l�@�z                                                                               
									//�E�ucurr_node�v�ȉ��̍��̐��́A                                                                  
									//�@�usibling_node�v�ȉ��̍��̐�������Ȃ��B                                                   
									//�E�u(LSS)�v�ȉ��Ɓu(LSL)�v�ȉ��Ɓusibling_node_l�v�ȉ��̍��̐��́A���ꂼ��                       
									//�@�usibling_node�v�ȉ��̍��̐�������Ȃ��B                                                   
									//�E�ucurr_node�v�ȉ��Ɓu(LSS)�v�ȉ��Ɓu(LSL)�v�ȉ��Ɓusibling_node_l�v�ȉ���                      
									//�@���̐��́A���ׂē����B                                                                         
									//�E�ucurr_node�v�Ɓuparent_node�v�����ɐԁi�����B�ᔽ�j�̉\��������B                           
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//�y�ŏI��Ԃ̍l�@�z                                                                               
									//�E�����؂̑�i�E�j���̍��̐��͕ω����Ȃ��B                                                       
									//�E�����؂̏��i���j���̍��̐��͈������B                                                       
									//�E�ؑS�̂̍��̐��͕ω����Ȃ��B                                                                   
									//�E������ԂŁucurr_node�v�Ɓuparent_node�v�����ɐԁi�����B�ᔽ�j�������ꍇ�A��肪���������B   
									//-------------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-S1-[%d:?]��[%d:B]��[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_s));
									ope_type::setChildL(*parent_node, _rotateR<ope_type>(sibling_node));//�Z��m�[�h���E��]����
									_rotateL<ope_type>(parent_node);//�e�m�[�h������]����
									ope_type::setColor(*sibling_node_s, ope_type::getColor(*parent_node));//�e�m�[�h������parent_node�Ɠ����F��
									ope_type::setBlack(*parent_node);//�폜���m�[�h������
									parent_node_prev = sibling_node_s;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
									is_necessary_rotate = false;//��������
								}
								else if (sibling_node_l && ope_type::isRed(*sibling_node_l))//�y�P�[�X�F�Z��̎q���m��i�E�j���̎q�F�ԁn�z
								{
									//�y��]�P�[�X[S-2]�F�m�폜�F���i���j���F���n���m�Z��F��i�E�j���F���n���m��i�E�j���̎q�F�ԁn�z
									//-----------------------------------------------------------------------------------------
									//              .----------[parent_node:?]-------------------.                             
									//        [curr_node:-B]                      .------[sibling_node:B]------.               
									//                                      [sibling_node_s:B/n]    .--[sibling_node_l:R]--.   
									//                                                           [(LLS)]                [(LLL)]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ���y�e�m�[�h������]�z                                    
									//              .-----------[sibling_node:B]----------------.                              
									//     .--[parent_node:?]--.                  .------[sibling_node_l:R]------.             
									// [curr_node:-B] [sibling_node_s:B/n]     [(LLS)]                        [(LLL)]          
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ���y�F�𒲐��z                                            
									//                                        ������parent_node�Ɠ����F��                      
									//              .-----------[sibling_node:+?]----------------.                             
									//     .--[parent_node:+B]--.                 .------[sibling_node_l:+B]-----.             
									// [curr_node:?]  [sibling_node_s:B/n]     [(LLS)]                   ��   [(LLL)]          
									//           ��       ������                                        ����                   
									//          ��́u+B�v�ɂ��A���́u-B�v������                                             
									//-----------------------------------------------------------------------------------------
									//�y�ŏI��Ԃ̓����z                                                                       
									//�E�ԍ��̈ʒu�֌W�i�����B�j�͕ۂ����B                                                   
									//�E�����؂̏��i���j���ɍ���������邱�ƂŁA                                             
									//�@�ؑS�̂̃o�����X�i�����C�j���񕜂��A�؂̒����͊�������B                               
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//�y������Ԃ̍l�@�z                                                                       
									//�E�ucurr_node�v�ȉ��̍��̐��́A                                                          
									//�@�usibling_node�v�ȉ��̍��̐�������Ȃ��B                                           
									//�E�u(LLS)�v�ȉ��Ɓu(LLL)�v�ȉ��Ɓusibling_node_s�v�ȉ��̍��̐��́A���ꂼ��               
									//�@�usibling_node�v�ȉ��̍��̐�������Ȃ��B                                           
									//�E�ucurr_node�v�ȉ��Ɓu(LLS)�v�ȉ��Ɓu(LLL)�v�ȉ��Ɓusibling_node_s�v�ȉ���              
									//�@���̐��́A���ׂē����B                                                                 
									//�E�ucurr_node�v�Ɓuparent_node�v�����ɐԁi�����B�ᔽ�j�̉\��������B                           
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//�y�ŏI��Ԃ̍l�@�z                                                                       
									//�E�����؂̑�i�E�j���̍��̐��͕ω����Ȃ��B                                               
									//�E�����؂̏��i���j���̍��̐��͈������B                                               
									//�E�ؑS�̂̍��̐��͕ω����Ȃ��B                                                           
									//�E������ԂŁucurr_node�v�Ɓuparent_node�v�����ɐԁi�����B�ᔽ�j�������ꍇ�A��肪���������B
									//-----------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-S2-[%d:?]��[%d:B]��[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_l));
									_rotateL<ope_type>(parent_node);//�e�m�[�h������]����
									ope_type::setColor(*sibling_node, ope_type::getColor(*parent_node));//�e�m�[�h������parent_node�Ɠ����F��
									ope_type::setBlack(*parent_node);//�폜���m�[�h������
									ope_type::setBlack(*sibling_node_l);//�Z��m�[�h������
									parent_node_prev = sibling_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
									is_necessary_rotate = false;//��������
								}
								else//�y�P�[�X�F�Z��̎q���召�i���E�j�����Ƃ����������̓k���z
								{
									if (ope_type::isRed(*parent_node))//�y�P�[�X�F�폜�m�[�h�̐e���ԁz
									{
										//�y��]�P�[�X[S-3a]�F�m�폜�F���i���j���F���n���m�e�F�ԁn���m�Z��F��i�E�j���F���n���m�召�i���E�j�����̎q�F�ԈȊO�n�z
										//------------------------------------------------------------------------------
										//       .----------[parent_node:R]-------------------.                         
										// [curr_node:-B]                      .------[sibling_node:B]------.           
										//                               [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ------
										//                        ���y�F�𒲐��z                                        
										//       .----------[parent_node:+B]-------------------.   ���Ԃ�               
										// [curr_node:?]             ���Ɂ�   .------[sibling_node:+R]------.           
										//           ��                  [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//           ��́u+B�v�ɂ��A���́u-B�v������                                 
										//------------------------------------------------------------------------------
										//�y�ŏI��Ԃ̓����z                                                            
										//�E�ԍ��̈ʒu�֌W�i�����B�j�͕ۂ����B                                        
										//�E�����؂̑�i�E�j���̍�������邱�ƂŁA                                    
										//�@�����؂̃o�����X���񕜂��A                                                  
										//�@�X�ɁA�����؂̍��ɍ���������邱�ƂŁA                                    
										//�@�ؑS�̂̃o�����X�i�����C�j���񕜂��A�؂̒����͊�������B                    
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
										//�y������Ԃ̍l�@�z                                                            
										//�E�ucurr_node�v�ȉ��̍��̐��́A                                               
										//�@�usibling_node�v�ȉ��̍��̐�������Ȃ��B                                
										//�E�usibling_node_s�v�ȉ��Ɓusibling_node_l�v�ȉ��̍��̐��́A                  
										//�@���ꂼ��usibling_node�v�ȉ��̍��̐�������Ȃ��B                        
										//�E�ucurr_node�v�ȉ��Ɓusibling_node_s�v�ȉ��Ɓusibling_node_l�v�ȉ���         
										//�@���̐��́A���ׂē����B                                                      
										//�E�ucurr_node�v�Ɓuparent_node�v�����ɐԁi�����B�ᔽ�j�̉\��������B                           
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
										//�y�ŏI��Ԃ̍l�@�z                                                            
										//�E�����؂̑�i�E�j���̍��̐��́}�O�B                                          
										//�E�����؂̏��i���j���̍��̐��͈������B                                    
										//�E�ؑS�̂̍��̐��͕ω����Ȃ��B                                                
										//�E������ԂŁucurr_node�v�Ɓuparent_node�v�����ɐԁi�����B�ᔽ�j�������ꍇ�A��肪���������B
										//------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-S3a-[%d:R]��[%d:B]��[*:B/n]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setBlack(*parent_node);//�e�m�[�h������
										ope_type::setRed(*sibling_node);//�Z��m�[�h��Ԃ�
										parent_node_prev = parent_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
										is_necessary_rotate = false;//��������
									}
									else//if (ope_type::isBlack(*parent_node))//�y�P�[�X�F�폜�m�[�h�̐e�����z
									{
										//�y��]�P�[�X[S-3b]�F�m�폜�F���i���j���F���n���m�e�F���n���m�Z��F��i�E�j���F���n���m�召�i���E�j�����̎q�F�ԈȊO�n�z
										//-------------------------------------------------------------------------------------
										//              .----------[parent_node:B]-------------------.                         
										//        [curr_node:-B]                      .------[sibling_node:B]------.           
										//                                      [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                               ���y�F�𒲐��z                                        
										//              .----------[parent_node:B]--------------------.   ���Ԃ�               
										//        [curr_node:?]                      .------[sibling_node:+R]------.           
										//                  ��                  [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//                  �E�́u+R�v�ɂ��A���́u-B�v�������i�E���������������̂Łj         
										//-------------------------------------------------------------------------------------
										//�y�ŏI��Ԃ̓����z                                                                   
										//�E�ԍ��̈ʒu�֌W�i�����B�j�͕ۂ����B                                               
										//�E�����؂̑�i�E�j���̍�������邱�ƂŁA                                           
										//�@�����؂̃o�����X���񕜂��邪�A                                                     
										//�@�����ؑS�̂ł͍������������Ԃ̂��߁A                                           
										//�@�e�ɑk���Ė؂̒������K�v�B                                                         
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//�y������Ԃ̍l�@�z                                                                   
										//�E�ucurr_node�v�ȉ��̍��̐��́A                                                      
										//�@�usibling_node�v�ȉ��̍��̐�������Ȃ��B                                       
										//�E�usibling_node_s�v�ȉ��Ɓusibling_node_l�v�ȉ��̍��̐��́A                         
										//�@���ꂼ��usibling_node�v�ȉ��̍��̐�������Ȃ��B                               
										//�E�ucurr_node�v�ȉ��Ɓusibling_node_s�v�ȉ��Ɓusibling_node_l�v�ȉ���                
										//�@���̐��́A���ׂē����B                                                             
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//�y�ŏI��Ԃ̍l�@�z                                                                   
										//�E�����؂̑�i�E�j���̍��̐��͈����B                                             
										//�E�����؂̏��i���j���̍��̐��͕ς��Ȃ��B                                           
										//�E�����؂̃o�����X�͎��邪�A                                                       
										//�@�����ؑS�̂ō��̐�������Ȃ��B                                                   
										//-------------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-S3b-[%d:B]��[%d:B]��[*:B/n]=NEXT>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setRed(*sibling_node);//�Z��m�[�h��Ԃ�
										parent_node_prev = parent_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
										//is_necessary_rotate = true;//�������s
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//�y�P�[�X�F�폜���̌Z�킪�m��i�E�j���F�ԁn�z
							{
								//���Z�킪�Ԃł��邽�߁A�u�����B�v�ɂ��A�K�R�I�ɐe�͍��ɂȂ�
								//�y��]�P�[�X[S-4]�F�m�폜�F���i���j���F���n���m�e�F���n���m�Z��F��i�E�j���F�ԁn�z
								//--------------------------------------------------------------------------------------
								//                 .--------------[parent_node:B]---------------.                       
								//        [curr_node:-B]                         .------[sibling_node:R]------.         
								//                                         [sibling_node_s:B]       [sibling_node_l:B]  
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                      ���y�e�m�[�h������]�z                          
								//                 .--------------[sibling_node:R]--------------.                       
								//      .----[parent_node:B]----.                      [sibling_node_l:B]               
								// [curr_node:-B]   [sibling_node_s:B]                                                  
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                      ���y�F�𒲐��z                                  
								//                 .--------------[sibling_node:+B]-------------.                       
								//      .----[parent_node:+R]----.              ������ [sibling_node_l:B]               
								// [curr_node:-B]   [sibling_node_s:B]                                                  
								//            ��          ���ԂɁicurr_node���Ԃ��ƁA�u�����B�v�������j               
								//            ���́u-B�v�͉�������Ȃ�                                                  
								//--------------------------------------------------------------------------------------
								//�y�ŏI��Ԃ̓����z                                                                    
								//�E�ԍ��̈ʒu�֌W�i�����B�j�������\�������邪�A                                    
								//�@���̌�̏����ŕK��curr_node�̐e�����ɂȂ�̂Ŗ��Ȃ��B                             
								//�E�����؂̃o�����X�͉񕜂��Ȃ��B                                                      
								//�E���̏�Ԃ�parent_node��curr_node�����؂ɑ΂��āA                                    
								//�@�ċA�I�Ɂy�P�[�X[�@�`�B]�z�����s����ƁA�����؂�                                    
								//�@�o�����X���ۂ����B                                                                
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//�y������Ԃ̍l�@�z                                                                    
								//�E�ucurr_node�v�ȉ��̍��̐��́A                                                       
								//�@�usibling_node_s�v�^�usibling_node_l�v�ȉ��̍��̐�������Ȃ��B                  
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//�y�ŏI��Ԃ̍l�@�z                                                                    
								//�E�����؂̑�i�E�j���̍��̐��͕ω����Ȃ��B                                            
								//�E�����؂̏��i���j���̓o�����X������邽�߁A                                          
								//�@����ɂ��̕����؂Ńo�����X�𒲐�����B                                              
								//--------------------------------------------------------------------------------------
								printf_dbg_remove("<ROT-S4-[%d:B]��[%d:R]��[*:B/n]=RETRY>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
								_rotateL<ope_type>(parent_node);//�e�m�[�h������]����
								ope_type::setRed(*parent_node);//�폜���m�[�h��Ԃ�
								ope_type::setBlack(*sibling_node);//�e�m�[�h������
								stack_info_type* ancestor_info = stack.top();//�X�^�b�N���猻�݂̐e�����擾
								const bool parent_is_large = ancestor_info ? ancestor_info->m_isLarge : false;//�e�̐e����̘A������
								if (ancestor_info)
								{
									node_type* ancestor_node = const_cast<node_type*>(ancestor_info->m_nodeRef);
									ope_type::setChild(*ancestor_node, parent_is_large, sibling_node);//�e�̐e�ɐV�����e��A��
								}
								stack.push(sibling_node, false);//������x���������؂���]���삷�邽�߂ɁA�Z��m�[�h���X�^�b�N�Ƀv�b�V��
								stack.push(parent_node, false);//������x���������؂���]���삷�邽�߂ɁA�e�m�[�h���X�^�b�N�Ƀv�b�V��
								parent_node_prev = curr_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
								//is_necessary_rotate = true;//�ċA�I�ɒ������s
							}
						}
						else//if (curr_is_large)//�y�P�[�X�F�m��i�E�j���F���n���폜�z
						{
							if (ope_type::isBlack(*sibling_node))//�y�P�[�X�F�폜���̌Z�킪�m���i���j���F���n�z
							{
								if (sibling_node_l && ope_type::isRed(*sibling_node_l))//�y�P�[�X�F�Z��̎q���m��i�E�j���̎q�F�ԁn�z
								{
									//�y��]�P�[�X[L-1]�F�m�폜�F��i�E�j���F���n���m�Z��F���i���j���F���n���m��i�E�j���̎q�F�ԁn�z
									//--------------------------------------------------------------------------------------------
									//                               .-------------------[parent_node:?]----------.               
									//                 .------[sibling_node:B]------.                      [curr_node:-B]         
									//       [sibling_node_s:?/n]      .--[sibling_node_l:R]--.                                   
									//                              [(SLS)]                [(SLL)]                                
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ���y�Z��m�[�h������]�z           
									//                               .-------------------[parent_node:?]----------.               
									//                 .------[sibling_node_l:R]------.                    [curr_node:-B]         
									//           .--[sibling_node:B]--.            [(SLL)]                                        
									// [sibling_node_s:?/n]        [(SLS)]                                                        
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ���y�e�m�[�h���E��]�z             
									//                               .-----------------[sibling_node_l:R]---------.               
									//                 .------[sibling_node:B]------.                .--[parent_node:?]--.        
									//           [sibling_node_s:?/n]            [(SLS)]          [(SLL)]          [curr_node:-B] 
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ���y�F�𒲐��z                     
									//                                                                 ������parent_node�Ɠ����F��
									//                               .-----------------[sibling_node_l:+?]--------.  ������       
									//                 .------[sibling_node:B]------.                .--[parent_node:+B]--.       
									//           [sibling_node_s:?/n]            [(SLS)]          [(SLL)]          [curr_node:?]  
									//                                                     ��́u+B�v�ɂ��A���́u-B�v��������   
									//--------------------------------------------------------------------------------------------
									//�����������B                                                                                
									//�������͏ȗ��B�y�P�[�X[S-1]�z�Ɠ���                                                         
									//--------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-L1-[%d:?]��[%d:B]��[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_l));
									ope_type::setChildS(*parent_node, _rotateL<ope_type>(sibling_node));//�Z��m�[�h������]����
									_rotateR<ope_type>(parent_node);//�e�m�[�h���E��]����
									ope_type::setColor(*sibling_node_l, ope_type::getColor(*parent_node));//�e�m�[�h������parent_node�Ɠ����F��
									ope_type::setBlack(*parent_node);//�폜���m�[�h������
									parent_node_prev = sibling_node_l;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
									is_necessary_rotate = false;//��������
								}
								else if (sibling_node_s && ope_type::isRed(*sibling_node_s))//�y�P�[�X�F�Z��̎q���m���i���j���̎q�F�ԁn�z
								{
									//�y��]�P�[�X[L-2]�F�m�폜�F��i�E�j���F���n���m�Z��F���i���j���F���n���m���i���j���̎q�F�ԁn�z
									//---------------------------------------------------------------------------------------------
									//                               .-------------------[parent_node:?]----------.                
									//                 .------[sibling_node:B]------.                      [curr_node:-B]          
									//    .--[sibling_node_s:R]--.      [sibling_node_l:B/n]                                       
									// [(SLS)]                [(SLL)]                                                              
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                                                        ���y�e�m�[�h���E��]�z               
									//                               .------------------[sibling_node:R]----------.                
									//                 .------[sibling_node_s:R]------.                .--[parent_node:?]--.       
									//              [(SLS)]                        [(SLL)]    [sibling_node_l:B/n]   [curr_node:-B]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -                    
									//                                                        ���y�F�𒲐��z                       
									//                                                                ������parent_node�Ɠ����F��  
									//                               .------------------[sibling_node:+?]---------.   ������       
									//                 .------[sibling_node_s:+B]-----.               .--[parent_node:+B]--.       
									//              [(SLS)]                   ��   [(SLL)]    [sibling_node_l:B/n]   [curr_node:?] 
									//                                       ����            ��́u+B�v�ɂ��A���́u-B�v��������  
									//---------------------------------------------------------------------------------------------
									//�����������B                                                                                 
									//�������͏ȗ��B�y�P�[�X[S-2]�z�Ɠ���                                                          
									//---------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-L2-[%d:?]��[%d:B]��[%d:R]=OK>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_s));
									_rotateR<ope_type>(parent_node);//�e�m�[�h���E��]����
									ope_type::setColor(*sibling_node, ope_type::getColor(*parent_node));//�e�m�[�h������parent_node�Ɠ����F��
									ope_type::setBlack(*parent_node);//�폜���m�[�h������
									ope_type::setBlack(*sibling_node_s);//�Z��m�[�h������
									parent_node_prev = sibling_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
									is_necessary_rotate = false;//��������
								}
								else//�y�P�[�X�F�Z��̎q���召�i���E�j�����Ƃ����������̓k���z
								{
									if (ope_type::isRed(*parent_node))//�y�P�[�X�F�폜�m�[�h�̐e���ԁz
									{
										//�y��]�P�[�X[L-3a]�F�m�폜�F��i�E�j���F���n���m�e�F�ԁn���m�Z��F���i���j���F���n���m�召�i���E�j�����̎q�F�ԈȊO�n�z
										//---------------------------------------------------------------------------------
										//                       .-------------------[parent_node:R]----------.            
										//         .------[sibling_node:B]------.                      [curr_node:-B]      
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]                                   
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                                                 ���y�F�𒲐��z                  
										//                       .-------------------[parent_node:+B]---------.            
										//         .------[sibling_node:+B]-----.                 ��   [curr_node:?]       
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]         ����			 ��        
										//                              ���Ԃ�                         ��́u + B�v�ɂ��A
										//                                                             ���́u - B�v������  
										//---------------------------------------------------------------------------------
										//�����������B                                                                     
										//�������͏ȗ��B�y�P�[�X[S-3a]�z�Ɠ���                                             
										//---------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-L3a-[%d:R]��[%d:B]��[*:B/n]=OK>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setBlack(*parent_node);//�e�m�[�h������
										ope_type::setRed(*sibling_node);//�Z��m�[�h��Ԃ�
										parent_node_prev = parent_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
										is_necessary_rotate = false;//��������
									}
									else//if (ope_type::isBlack(*parent_node))//�y�P�[�X�F�폜�m�[�h�̐e�����z
									{
										//�y��]�P�[�X[L-3b]�F�m�폜�F��i�E�j���F���n���m�e�F���n���m�Z��F���i���j���F���n���m�召�i���E�j�����̎q�F�ԈȊO�n�z
										//---------------------------------------------------------------------------
										//                       .-------------------[parent_node:B]----------.      
										//         .------[sibling_node:B]------.                      [curr_node:-B]
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]                             
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                                                 ���y�F�𒲐��z            
										//                       .-------------------[parent_node:B]---------.       
										//         .------[sibling_node:+R]-----.                      [curr_node:?] 
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]       ���́u+R�v�ɂ��A��  
										//                              ���Ԃ�                 ���́u-B�v������      
										//                                                   �i�����������������̂Łj
										//---------------------------------------------------------------------------
										//���������s�B                                                               
										//�������͏ȗ��B�y�P�[�X[S-3b]�z�Ɠ���                                       
										//---------------------------------------------------------------------------
										printf_dbg_remove("<ROT-L3b-[%d:B]��[%d:B]��[*:B/n]=NEXT>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setRed(*sibling_node);//�Z��m�[�h��Ԃ�
										parent_node_prev = parent_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
										//is_necessary_rotate = true;//�������s
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//�y�P�[�X�F�폜���̌Z�킪�m���i���j���F�ԁn�z
							{
								//���Z�킪�Ԃł��邽�߁A�u�����B�v�ɂ��A�K�R�I�ɐe�͍��ɂȂ�
								//�y��]�P�[�X[L-4]�F�m�폜�F��i�E�j���F���n���m�e�F���n���m�Z��F���i���j���F�ԁn�z
								//--------------------------------------------------------------------------------------------------------
								//                         .-------------------[parent_node:B]----------.                                 
								//           .------[sibling_node:R]------.                      [curr_node:-B]                           
								// [sibling_node_s:B]          [sibling_node_l:B]                                                         
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                                   ���y�e�m�[�h���E��]�z                               
								//                         .------------------[sibling_node:R]----------.                                 
								//                 [sibling_node_s:B]                         .--[parent_node:B]--.                       
								//                                                    [sibling_node_l:B]     [curr_node:-B]               
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                                   ���y�F�𒲐��z                                       
								//                         .-----------------[sibling_node:+B]----------.     ���ԂɁicurr_node���Ԃ��ƁA 
								//                 [sibling_node_s:B]                  ���Ɂ� .--[parent_node:+R]--.  �u�����B�v�������j
								//                                                    [sibling_node_l:B]     [curr_node:-B]               
								//                                                                                      ��                
								//                                                                 ���́u-B�v�͉�������Ȃ�               
								//--------------------------------------------------------------------------------------------------------
								//���ċA�I�ɒ������s�B                                                                                    
								//�������͏ȗ��B�y�P�[�X[S-4]�z�Ɠ���                                                                     
								//--------------------------------------------------------------------------------------------------------
								printf_dbg_remove("<ROT-L4-[%d:B]��[%d:R]��[*:B/n]=RETRY>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
								_rotateR<ope_type>(parent_node);//�e�m�[�h���E��]����
								ope_type::setRed(*parent_node);//�폜���m�[�h��Ԃ�
								ope_type::setBlack(*sibling_node);//�e�m�[�h������
								stack_info_type* ancestor_info = stack.top();//�X�^�b�N���猻�݂̐e�����擾
								const bool parent_is_large = ancestor_info ? ancestor_info->m_isLarge : false;//�e�̐e����̘A������
								if (ancestor_info)
								{
									node_type* ancestor_node = const_cast<node_type*>(ancestor_info->m_nodeRef);
									ope_type::setChild(*ancestor_node, parent_is_large, sibling_node);//�e�̐e�ɐV�����e��A��
								}
								stack.push(sibling_node, true);//������x���������؂���]���삷�邽�߂ɁA�Z��m�[�h���X�^�b�N�Ƀv�b�V��
								stack.push(parent_node, true);//������x���������؂���]���삷�邽�߂ɁA�e�m�[�h���X�^�b�N�Ƀv�b�V��
								parent_node_prev = curr_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
								//is_necessary_rotate = true;//�ċA�I�ɒ������s
							}
						}
					}
					else//if (!sibling_node)//�Z��m�[�h�����݂��Ȃ��ꍇ
					{
						//���m�[�h�i�폜�Ώۃm�[�h�j�̌Z��m�[�h�����݂��Ȃ����Ƃ͖{�����肦�Ȃ�
						//���u�����C�v�ɂ��A������t�܂ł̂�����o�H�ō��̐��͈��̂��߁A
						//�@���m�[�h���폜�����ꍇ�A�K���Z��m�[�h�������͂��̎q���ɍ�������B
						printf_dbg_remove("�y�ԍ��؂Ƀo�O����I�z���m�[�h�i�폜�j�̌Z��m�[�h�����݂��Ȃ�\n");
						assert(sibling_node != nullptr);
						parent_node_prev = parent_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
					}
				}
				else//if (!is_necessary_rotate)//��]�������s�v
				{
					parent_node_prev = parent_node;//�e�m�[�h���L�^�i���̃��[�v�����̐e�̎q�ɘA������j
				}
			}
			if (parent_node_prev)
			{
				root = parent_node_prev;
				ope_type::setBlack(*root);
			}
		}
	}

	//----------------------------------------
	//�ԍ��؃R���e�i
	//�����m�[�h�����̂�
	//��std::map��͂����\��
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
			inline operator key_type() const { return ope_type::getKey(*getNode()); }
		public:
			//�I�y���[�^
			inline const_reference operator*() const { return *getNode(); }
			inline reference operator*(){ return *getNode(); }
			inline const_pointer operator->() const { return getNode(); }
			inline pointer operator->(){ return getNode(); }
		#if 1//std::bidirectional_iterator_tag �ɂ͖{���K�v�ł͂Ȃ�
			inline const_iterator operator[](const int index) const
			{
				iterator ite(m_root, false);
				ite += index;
				return std::move(ite);
			}
			inline iterator operator[](const int index)
			{
				iterator ite(m_root, false);
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
				       ope_type::eq(*m_node, *rhs);
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? false :
				       m_isEnd || rhs.m_isEnd ? true :
				       ope_type::ne(*m_node, *rhs);
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && !rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       ope_type::gt(*m_node, *rhs);
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd && !rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       ope_type::ge(*m_node, *rhs);
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       !m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       ope_type::lt(*m_node, *rhs);
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       !m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       ope_type::le(*m_node, *rhs);
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
		public:
			//���[�u�I�y���[�^
			inline iterator& operator=(const_iterator&& rhs)
			{
				m_stack = std::move(rhs.m_stack);
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			iterator& operator=(const_reverse_iterator&& rhs);
			//�R�s�[�I�y���[�^
			inline iterator& operator=(const_iterator& rhs)
			{
				m_stack = rhs.m_stack;
				m_root = rhs.m_root;
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
			inline const node_type* getRoot() const { return m_root; }//���m�[�h
			inline node_type* getRoot(){ return m_root; }//���m�[�h
			inline const node_type* getNode() const { return m_node; }//���݂̃m�[�h
			inline node_type* getNode(){ return m_node; }//���݂̃m�[�h
		private:
			//���\�b�h
			inline void updateNext() const
			{
				node_type* prev = m_node;
				m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
				m_isEnd = (prev && !m_node);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					m_stack.reset();
					m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
					m_isEnd = false;
					return;
				}
				m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
				m_isEnd = false;
			}
			void updateForward(const int step) const
			{
				int _step = step;
				node_type* prev = m_node;
				while (_step > 0 && m_node)
				{
					m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
					--_step;
				}
				m_isEnd = (prev && !m_node && _step == 0);
			}
			void updateBackward(const int step) const
			{
				int _step = step;
				if (_step > 0 && m_isEnd)
				{
					m_stack.reset();
					m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
					--_step;
				}
				while (_step > 0 && m_node)
				{
					m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
					--_step;
				}
				m_isEnd = false;
			}
		public:
			//���[�u�R���X�g���N�^
			inline iterator(const_iterator&& obj) :
				m_stack(std::move(obj.m_stack)),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			iterator(const_reverse_iterator&& obj);
			//�R�s�[�R���X�g���N�^
			inline iterator(const_iterator& obj) :
				m_stack(obj.m_stack),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			iterator(const_reverse_iterator& obj);
			//�R���X�g���N�^
			inline iterator(const node_type* root, const bool is_end) :
				m_stack(),
				m_root(root),
				m_node(nullptr),
				m_isEnd(is_end)
			{
				if (!is_end)
					m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
			}
			inline iterator(stack_type&& stack, const node_type* root, node_type* node, const bool is_end) :
				m_stack(std::move(stack)),
				m_root(root),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline iterator(stack_type& stack, const node_type* root, node_type* node, const bool is_end) :
				m_stack(stack),
				m_root(root),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline iterator() :
				m_stack(),
				m_root(nullptr),
				m_node(nullptr),
				m_isEnd(false)
			{}
			//�f�X�g���N�^
			inline ~iterator()
			{}
		protected:
			//�t�B�[���h
			mutable stack_type m_stack;//�X�^�b�N
			const node_type* m_root;//���m�[�h
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
			inline operator key_type() const { return ope_type::getKey(*getNode()); }
		public:
			//�I�y���[�^
			inline const_reference operator*() const { return *getNode(); }
			inline reference operator*(){ return *getNode(); }
			inline const_pointer operator->() const { return getNode(); }
			inline pointer operator->(){ return getNode(); }
		#if 1//std::bidirectional_iterator_tag �ɂ͖{���K�v�ł͂Ȃ�
			inline const_reverse_iterator operator[](const int index) const
			{
				reverse_iterator ite(m_root, false);
				ite += index;
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(m_root, false);
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
				       ope_type::eq(*rhs, *m_node);
			}
			inline bool operator!=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? false :
				       rhs.m_isEnd || m_isEnd ? true :
					   ope_type::ne(*rhs, *m_node);
			}
			inline bool operator>(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && !m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       ope_type::gt(*rhs, *m_node);
			}
			inline bool operator>=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd && !m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       ope_type::ge(*rhs, *m_node);
			}
			inline bool operator<(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       !rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       ope_type::lt(*rhs, *m_node);
			}
			inline bool operator<=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       !rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       ope_type::le(*rhs, *m_node);
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
		public:
			//���[�u�I�y���[�^
			inline reverse_iterator& operator=(const_reverse_iterator&& rhs)
			{
				m_stack = std::move(rhs.m_stack);
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator&& rhs)
			{
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = false;
				if (m_node)
				{
					m_stack = std::move(rhs.m_stack);
					++(*this);
				}
				else
				{
					m_stack.reset();
					if (rhs.m_isEnd)
						m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
				}
				return *this;
			}
			//�R�s�[�I�y���[�^
			inline reverse_iterator& operator=(const_reverse_iterator& rhs)
			{
				m_stack = rhs.m_stack;
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator& rhs)
			{
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = false;
				if (m_node)
				{
					m_stack = rhs.m_stack;
					++(*this);
				}
				else
				{
					m_stack.reset();
					if (rhs.m_isEnd)
						m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
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
			inline const node_type* getRoot() const { return m_root; }//���m�[�h
			inline node_type* getRoot(){ return m_root; }//���m�[�h
			inline const node_type* getNode() const { return m_node; }//���݂̃m�[�h
			inline node_type* getNode(){ return m_node; }//���݂̃m�[�h
		public:
			//���\�b�h
			inline void updateNext() const
			{
				node_type* prev = m_node;
				m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
				m_isEnd = (prev && !m_node);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					m_stack.reset();
					m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
					m_isEnd = false;
					return;
				}
				m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
				m_isEnd = false;
			}
			void updateForward(const int step) const
			{
				int _step = step;
				node_type* prev = m_node;
				while (_step > 0 && m_node)
				{
					m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
					--_step;
				}
				m_isEnd = (prev && !m_node && _step == 0);
			}
			void updateBackward(const int step) const
			{
				int _step = step;
				if (_step > 0 && m_isEnd)
				{
					m_stack.reset();
					m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
					--_step;
				}
				while (_step > 0 && m_node)
				{
					m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
					--_step;
				}
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
				m_stack(std::move(obj.m_stack)),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator&& obj) :
				m_stack(),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(false)
			{
				if (m_node)
				{
					m_stack = std::move(obj.m_stack);
					++(*this);
				}
				else
				{
					m_stack.reset();
					if (obj.m_isEnd)
						m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
				}
			}
			//�R�s�[�R���X�g���N�^
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_stack(obj.m_stack),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_stack(),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{
				if (m_node)
				{
					m_stack = obj.m_stack;
					++(*this);
				}
				else
				{
					m_stack.reset();
					if (obj.m_isEnd)
						m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
				}
			}
			//�R���X�g���N�^
			inline reverse_iterator(const node_type* root, const bool is_end) :
				m_stack(),
				m_root(root),
				m_node(nullptr),
				m_isEnd(is_end)
			{
				if (!is_end)
					m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
			}
			inline reverse_iterator(stack_type&& stack, const node_type* root, node_type* node, const bool is_end) :
				m_stack(std::move(stack)),
				m_root(root),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline reverse_iterator(stack_type& stack, const node_type* root, node_type* node, const bool is_end) :
				m_stack(stack),
				m_root(root),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline reverse_iterator() :
				m_stack(),
				m_root(nullptr),
				m_node(nullptr),
				m_isEnd(false)
			{}
			//�f�X�g���N�^
			inline ~reverse_iterator()
			{}
		protected:
			//�t�B�[���h
			mutable stack_type m_stack;//�X�^�b�N
			const node_type* m_root;//���m�[�h
			mutable node_type* m_node;//���݂̃m�[�h
			mutable bool m_isEnd;//�I�[���H
		};
	public:
		//�A�N�Z�b�T
		inline const node_type* root() const { return m_root; }//���m�[�h���擾
		inline node_type* root(){ return m_root; }//���m�[�h���擾
		inline node_type*& root_ref(){ return m_root; }//���m�[�h�̎Q�Ƃ��擾
	public:
		//�L���X�g�I�y���[�^
		inline operator lock_type&(){ return m_lock; }//���b�N�I�u�W�F�N�g
		inline operator lock_type&() const { return m_lock; }//���b�N�I�u�W�F�N�g ��mutable
	public:
		//���\�b�h�F�C�e���[�^�n
		//�������I�ȋ��L���b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�S�̂̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
		inline const_iterator cbegin() const
		{
			iterator ite(m_root, false);
			return std::move(ite);
		}
		inline const_iterator cend() const
		{
			iterator ite(m_root, true);
			return std::move(ite);
		}
		inline const_iterator begin() const
		{
			iterator ite(m_root, false);
			return std::move(ite);
		}
		inline const_iterator end() const
		{
			iterator ite(m_root, true);
			return std::move(ite);
		}
		inline iterator begin()
		{
			iterator ite(m_root, false);
			return std::move(ite);
		}
		inline iterator end()
		{
			iterator ite(m_root, true);
			return std::move(ite);
		}
		//���\�b�h�F���o�[�X�C�e���[�^�n
		//�������I�ȋ��L���b�N�擾�͍s��Ȃ��̂ŁA�}���`�X���b�h�ŗ��p����ۂ́A
		//�@��A�̏����u���b�N�S�̂̑O��ŋ��L���b�N�i���[�h���b�N�j�̎擾�Ɖ�����s���K�v������
		inline const_reverse_iterator crbegin() const
		{
			reverse_iterator ite(m_root, false);
			return std::move(ite);
		}
		inline const_reverse_iterator crend() const
		{
			reverse_iterator ite(m_root, true);
			return std::move(ite);
		}
		inline const_reverse_iterator rbegin() const
		{
			reverse_iterator ite(m_root, false);
			return std::move(ite);
		}
		inline const_reverse_iterator rend() const
		{
			reverse_iterator ite(m_root, true);
			return std::move(ite);
		}
		inline reverse_iterator rbegin()
		{
			reverse_iterator ite(m_root, false);
			return std::move(ite);
		}
		inline reverse_iterator rend()
		{
			reverse_iterator ite(m_root, true);
			return std::move(ite);
		}
		//���\�b�h�F�e�ʌn
		//inline std::size_t max_size() const { return (�s��); }
		//inline std::size_t capacity() const { return (�s��); }
		inline std::size_t size() const { return countNodes<ope_type>(m_root); }//�m�[�h�����擾
		inline bool empty() const { return m_root == nullptr; }//�؂��󂩁H
		inline int depth_max() const { return getDepthMax<ope_type>(m_root); }//�؂̐[�����擾
		//���\�b�h�F�v�f�A�N�Z�X�n
		//��std::map�ƈقȂ�A�m�[�h�̃|�C���^��Ԃ�
		const node_type* at(const key_type key) const
		{
			stack_type stack;
			return searchNode<ope_type>(m_root, key, stack, FOR_MATCH);
		}
		inline node_type* at(const key_type key){ return const_cast<node_type*>(const_cast<const container*>(this)->at(key)); }
		inline const node_type* operator[](const key_type key) const { return at(key); }
		inline node_type* operator[](const key_type key){ return at(key); }
		//���\�b�h�F�ǉ��^�폜�n
		//��std::map�ƈقȂ�A�m�[�h�𒼐ڎw�肵�A���ʂ�bool�^�Ŏ󂯎��
		//���v�f�̃������m�ہ^�폜���s��Ȃ��_�ɒ���
		//���������A�r�����b�N�i���C�g���b�N�j���擾����
		inline node_type* insert(const node_type& node)
		{
			lock_guard<lock_type> lock(m_lock);//�r�����b�N�i���C�g���b�N�j�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return addNode<ope_type>(const_cast<node_type*>(&node), m_root);
		}
		inline node_type* erase(const node_type& node)
		{
			lock_guard<lock_type> lock(m_lock);//�r�����b�N�i���C�g���b�N�j�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return removeNode<ope_type>(&node, m_root);
		}
		inline node_type* erase(const key_type key)
		{
			lock_guard<lock_type> lock(m_lock);//�r�����b�N�i���C�g���b�N�j�擾�i�֐��𔲂��鎞�Ɏ����J���j
			return removeNode<ope_type>(at(key), m_root);
		}
		node_type* clear()
		{ 
			lock_guard<lock_type> lock(m_lock);//�r�����b�N�i���C�g���b�N�j�擾�i�֐��𔲂��鎞�Ɏ����J���j
			node_type* root = m_root;
			m_root = nullptr;
			return root;
		}
		//���\�b�h�F�����n
		//��lower_bound(), upper_bound()�ɂ͔�Ή�
		//������ɁAfind_nearest�ɑΉ�
		inline const_iterator& _find(const_iterator& ite, const key_type key, const match_type_t type = FOR_MATCH) const
		{
			ite.m_node = const_cast<node_type*>(searchNode<ope_type>(m_root, key, ite.m_stack, type));
			return ite;
		}
		inline const_iterator find(const key_type key, const match_type_t type = FOR_MATCH) const
		{
			const_iterator ite;
			return std::move(_find(ite, key, type));
		}
		inline iterator find(const key_type key, const match_type_t type = FOR_MATCH)
		{
			iterator ite;
			return std::move(_find(ite, key, type));
		}
		inline std::size_t count(const key_type key) const { return countNodes<ope_type>(m_root, key); }
		const_iterator& _equal_range(const_iterator& ite, const key_type key) const
		{
			ite.m_node = const_cast<node_type*>(searchNode<ope_type>(m_root, key, ite.m_stack, FOR_MATCH));
			while (ite.m_node && ope_type::getKey(*ite) == key)
				++ite;
			return ite;
		}
		inline const_iterator equal_range(const key_type key) const
		{
			const_iterator ite;
			return std::move(_equal_range(ite, key));
		}
		inline iterator equal_range(const key_type key)
		{
			iterator ite;
			return std::move(_equal_range(ite, key));
		}
	public:
		//���[�u�R���X�g���N�^
		container(const container&& con) :
			m_root(con.m_root)
		{}
		//�R�s�[�R���X�g���N�^
		container(const container& con) :
			m_root(con.m_root)
		{}
		//�R���X�g���N�^
		container() :
			m_root(nullptr)
		{}
		//�f�X�g���N�^
		~container()
		{}
	private:
		//�t�B�[���h
		node_type* m_root;//���m�[�h
		mutable lock_type m_lock;//���b�N�I�u�W�F�N�g
	};
	//�C�e���[�^�̃��[�u�I�y���[�^
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator&& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator&& rhs)//VC++��OK
	{
		m_root = rhs.m_root;
		m_node = rhs.m_node;
		m_isEnd = false;
		if (m_node)
		{
			m_stack = std::move(rhs.m_stack);
			++(*this);
		}
		else
		{
			m_stack.reset();
			if (rhs.m_isEnd)
				m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
		}
		return *this;
	}
	//�C�e���[�^�̃R�s�[�I�y���[�^
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator& rhs)//GCC��OK, VC++��NG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator& rhs)//VC++��OK
	{
		m_root = rhs.m_root;
		m_node = rhs.m_node;
		m_isEnd = false;
		if (m_node)
		{
			m_stack = rhs.m_stack;
			++(*this);
		}
		else
		{
			m_stack.reset();
			if (rhs.m_isEnd)
				m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
		}
		return *this;
	}
	//�C�e���[�^�̃��[�u�R���X�g���N�^
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator&& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator&& obj) ://VC++��OK
		m_stack(),
		m_root(obj.m_root),
		m_node(obj.m_node),
		m_isEnd(false)
	{
		if (m_node)
		{
			m_stack = std::move(obj.m_stack);
			++(*this);
		}
		else
		{
			m_stack.reset();
			if (obj.m_isEnd)
				m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
		}
	}
	//�C�e���[�^�̃R�s�[�R���X�g���N�^
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator& obj) ://GCC��OK, VC++��NG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator& obj) ://VC++��OK
		m_stack(),
		m_root(obj.m_root),
		m_node(obj.m_node),
		m_isEnd(false)
	{
		if (m_node)
		{
			m_stack = obj.m_stack;
			++(*this);
		}
		else
		{
			m_stack.reset();
			if (obj.m_isEnd)
				m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
		}
	}
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace rb_tree

//--------------------------------------------------------------------------------
//�ԍ��؃e�X�g
//--------------------------------------------------------------------------------

#include <algorithm>//for_each�p
#include <random>//C++11 std::random�p
#include <chrono>//C++11 ���Ԍv���p
#include <type_traits>//C++11 ���Ԍv���p

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
	//�R���X�g���N�^
	data_t(const int key) :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_key(key)
	{}
	data_t() :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_key(0)
	{}

	//�t�B�[���h
	const data_t* m_nodeS;//���i���j���̎q�m�[�h
	const data_t* m_nodeL;//��i�E�j���̎q�m�[�h
	bool m_isBlack;//�m�[�h�̐F
	int m_key;//�L�[
};
//----------------------------------------
//�e�X�g�f�[�^�����m�[�h����p�N���X�iCRTP�j
struct ope_t : public rb_tree::base_ope_t<ope_t, data_t, int, TEST_DATA_STACK_DEPTH_MAX>
{
	//�q�m�[�h���擾
	inline static const node_type* getChildL(const node_type& node){ return node.m_nodeL; }//��i�E�j��
	inline static const node_type* getChildS(const node_type& node){ return node.m_nodeS; }//���i���j��
	//�q�m�[�h��ύX
	inline static void setChildL(node_type& node, const node_type* child){ node.m_nodeL = child; }//��i�E�j��
	inline static void setChildS(node_type& node, const node_type* child){ node.m_nodeS = child; }//���i���j��

	//�m�[�h�̐F���擾
	inline static color_t getColor(const node_type& node){ return node.m_isBlack ? BLACK : RED; }
	//�m�[�h�̐F��ύX
	inline static void setColor(node_type& node, const color_t color){ node.m_isBlack = color == BLACK; }
	
	//�L�[���擾
	inline static key_type getKey(const node_type& node){ return node.m_key; }

	//�L�[���r
	//���f�t�H���g�̂܂܂Ƃ���
	//inline static int compareKey(const key_type lhs, const key_type rhs);

	//���b�N�^
	//���f�t�H���g�idummy_shared_lock�j�̂܂܂Ƃ���
	//typedef shared_spin_lock lock_type;//���b�N�I�u�W�F�N�g�^
};

//----------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//�^
	typedef rb_tree::container<ope_t> container_t;
	typedef container_t::iterator iterator;
	typedef container_t::const_iterator const_iterator;
	typedef container_t::reverse_iterator reverse_iterator;
	typedef container_t::const_reverse_iterator const_reverse_iterator;
	
	//�ԍ��؃R���e�i
	container_t con;

	//�������Ԍv���J�n
	const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point prev_time = begin_time;

	//�f�[�^��o�^
	auto regList = [&con]()
	{
		printf("--- Make table ---\n");
		auto insert = [&con](const int key)
		{
			data_t* new_node = new data_t(key);
			printf_detail("[%2d] ", new_node->m_key);
			con.insert(*new_node);
			rb_tree::printf_dbg_add("\n");
		};
	#ifdef REGIST_TEST_DATA_SEQUENTIALLY
		//�V�[�P���V�����Ƀf�[�^�o�^
		for (int i = 0; i < TEST_DATA_REG_NUM; ++i)
		{
			const int key = TEST_DATA_KEY_MIN + i % (TEST_DATA_KEY_MAX - TEST_DATA_KEY_MIN + 1);
			insert(key);
		}
	#else//REGIST_TEST_DATA_SEQUENTIALLY
	#ifndef TEST_DATA_REGISTRATION_LIST
		//�����_���Ƀf�[�^�o�^
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_KEY_MIN, TEST_DATA_KEY_MAX);
		for (int i = 0; i < TEST_DATA_REG_NUM; ++i)
			insert(rand_dist(rand_engine));
	#else//TEST_DATA_REGISTRATION_LIST
		//�Œ菇�Ƀf�[�^�o�^
		const int key_list[] = TEST_DATA_REGISTRATION_LIST;
		for (int key : key_list)
			insert(key);
	#endif//TEST_DATA_REGISTRATION_LIST
	#endif//REGIST_TEST_DATA_SEQUENTIALLY
		printf_detail("\n");
		printf("%d registered.\n", TEST_DATA_REG_NUM);
	};
	regList();

	//�o�ߎ��Ԃ�\��
	auto printElapsedTime = [](const std::chrono::system_clock::time_point& prev_time) -> std::chrono::system_clock::time_point
	{
		//�ŏI�o�ߎ��ԕ\��
		const auto now_time = std::chrono::system_clock::now();
		const auto duration = now_time - prev_time;
		const double elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()) / 1000000000.;
		printf("*elapsed_time=%.9llf sec\n", elapsed_time);
		return now_time;
	};
	prev_time = printElapsedTime(prev_time);

	//�؂�\��
	auto showTree = [&con]()
	{
		printf("--- Show tree (count=%d) ---\n", con.size());
		//static const int depth_limit = 5;//�ő�ł�5�i�K�ڂ܂ł�\���i0�i�K�ڂ��琔����̂ōő��6�i�K�\������遨�ő�F1+2+4+8+16+32=63�j
		static const int depth_limit = 4;//�ő�ł�4�i�K�ڂ܂ł�\���i0�i�K�ڂ��琔����̂ōő��5�i�K�\������遨�ő�F1+2+4+8+16=31�j
		const int _depth_max = con.depth_max();
		printf("depth_max=%d (limit for showing=%d)\n", _depth_max, depth_limit);
	#ifdef PRINT_TEST_DATA_TREE
		const int depth_max = _depth_max <= depth_limit ? _depth_max : depth_limit;
		const int width_max = depth_max < 0 ? 0 : 1 << depth_max;//static_cast<int>(std::pow(2, depth_max));
		for (int depth = 0; depth <= depth_max; ++depth)
		{
			const int width = 1 << depth;//static_cast<int>(std::pow(2, depth));
			static const int label_len = 6;
			const int print_width = (width_max * label_len) / width;
			const int print_indent = (print_width - label_len) / 2;
			for (int breath = 0; breath < width; ++breath)
			{
				const data_t* node = con.root();
				int breath_tmp = breath;
				for (int depth_tmp = depth - 1; node; --depth_tmp)
				{
					if (depth_tmp < 0)
						break;
					node = ope_t::getChild(*node, (breath_tmp & (0x1 << depth_tmp)) != 0x0);
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (ope_t::getChildS(*node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(ope_t::getChildS(*node) ? "-" : " ");
					}
					printf("%s%2d:%c%s", ope_t::getChildS(*node) ? "{" : "[", node->m_key, ope_t::isBlack(*node) ? 'B' : 'R', ope_t::getChildL(*node) ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(ope_t::getChildL(*node) ? "-" : " ");
						if (ope_t::getChildL(*node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(" ");
					}
				}
				else
				{
					for (int c = 0; c < print_width; ++c)
						printf(" ");
				}
			}
			printf("\n");
		}
	#endif//PRINT_TEST_DATA_TREE
	};
	showTree();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

#ifdef ENABLE_CALC_COUNT_PERFORMANCE
	//�m�[�h���J�E���g�̎��Ԍv��
	auto calcNodesCount = [&con]()
	{
		static const int loop_max = 10000000;
		printf("--- Calc count (%d times) ---\n", loop_max);
		long long count = 0;
		for (int i = 0; i < loop_max; ++i)
			count += con.size();
		printf("count=%lld\n", count);
	};
	calcNodesCount();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��
#endif//ENABLE_CALC_COUNT_PERFORMANCE

	//�e�}�܂ł̃m�[�h����\��
	//�������B�Ə����C�ᔽ�m�F
	auto showNodesCount = [&con]()
	{
		printf("--- Show nodes count (count=%d) ---\n", con.size());
		const int depth_max = con.depth_max();
		const unsigned long long width_max = depth_max < 0 ? 0llu : 1llu << depth_max;//static_cast<long long>(std::pow(2, static_cast<long long>(depth_max)));
		printf("depth_max=%d, width_max=%llu\n", depth_max, width_max);
		if(depth_max > 63)
		{
			printf("'depth_max' is over 63. aborting therefor.\n");
			return;
		}
	#ifdef PRINT_TEST_DATA_COLOR_COUNT
		const data_t* prev_node = nullptr;
		int blacks_min = -1;
		int blacks_max = -1;
		int reds_min = -1;
		int reds_max = -1;
		int total_min = -1;
		int total_max = -1;
		int total_illegal_connects = 0;
		for (unsigned long long breath = 0; breath < width_max; ++breath)
		{
			int blacks = 0;
			int reds = 0;
			int illegal_connects = 0;
			const data_t* last_node = nullptr;
			const data_t* parent_node = nullptr;
			const data_t* node = con.root();
			long long breath_tmp = breath;
			for (long long depth_tmp = depth_max - 1; node; --depth_tmp)
			{
				last_node = node;
				if (ope_t::isBlack(*node))
					++blacks;
				else//if (ope_t::isRed(*node))
				{
					++reds;
					if (parent_node && ope_t::isRed(*parent_node))
					{
						++illegal_connects;
					}
				}
				if (depth_tmp < 0)
					break;
				parent_node = node;
				node = ope_t::getChild(*node, (breath_tmp & (0x1ll << depth_tmp)) != 0x0ll);
			}
			int total = blacks + reds;
			blacks_min = blacks_min > blacks || blacks_min == -1 ? blacks : blacks_min;
			blacks_max = blacks_max < blacks || blacks_max == -1 ? blacks : blacks_max;
			reds_min = reds_min > reds || reds_min == -1 ? reds : reds_min;
			reds_max = reds_max < reds || reds_max == -1 ? reds : reds_max;
			total_min = total_min > total || total_min == -1 ? total : total_min;
			total_max = total_max < total || total_max == -1 ? total : total_max;
			total_illegal_connects += illegal_connects;
			if (prev_node != last_node)
			{
			#ifdef PRINT_TEST_DATA_DETAIL
				printf("%5lld:[%2d] blacks=%d, reds=%d, total=%d (illegal=%d)\n", breath, last_node->m_key, blacks, reds, total, illegal_connects);
			#endif//PRINT_TEST_DATA_DETAIL
			}
			prev_node = last_node;
		}
		blacks_min = blacks_min >= 0 ? blacks_min : 0;
		blacks_max = blacks_max >= 0 ? blacks_max : 0;
		reds_min = reds_min >= 0 ? reds_min : 0;
		reds_max = reds_max >= 0 ? reds_max : 0;
		total_min = total_min >= 0 ? total_min : 0;
		total_max = total_max >= 0 ? total_max : 0;
		printf("max: blacks=%d, reds=%d, total=%d\n", blacks_max, reds_max, total_max);
		printf("min: blacks=%d, reds=%d, total=%d\n", blacks_min, reds_min, total_min);
		printf("diff:blacks=%d, reds=%d, total=%d (illegal=%d)\n", blacks_max - blacks_min, reds_max - reds_min, total_max - total_min, total_illegal_connects);
	#endif//PRINT_TEST_DATA_COLOR_COUNT
	};
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	auto showListAsc = [&con]()
	{
		printf("--- Show nodes ascending (count=%d) ---\n", con.size());
		bool is_found = false;
		for (const data_t& obj : con)//���C�e���[�^�i.begin() , .end()�j���ÖٓI�Ɏg�p�����
		{
			if (!is_found)
				is_found = true;
			printf_detail("[%2d] ", obj.m_key);
		}
		//���C�e���[�^�̕ϐ��錾�ƒl�̍X�V�𕪂��������኱�����I
		//const_reverse_iterator ite;con._begin(ite);
		//const_reverse_iterator end;con._end(end);
		//for (; ite != end; ++ite)
		//{
		//	const data_t& obj = *ite;
		//	...
		//}
		if (is_found)
			printf_detail("\n");
		else
			printf("(nothing)\n");
	};
	showListAsc();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//��ԑ傫���m�[�h����~���ɑS�m�[�h�����X�g�A�b�v
	auto showListDesc = [&con]()
	{
		printf("--- Show nodes descending (count=%d) ---\n", con.size());
		bool is_found = false;
		std::for_each(con.rbegin(), con.rend(),//���o�[�X�C�e���[�^
			[&is_found](const data_t& obj)
			{
				if (!is_found)
					is_found = true;
				printf_detail("[%2d] ", obj.m_key);
			}
		);
		//���C�e���[�^�̕ϐ��錾�ƒl�̍X�V�𕪂������������I
		//const_reverse_iterator ite;con._rbegin(ite);
		//const_reverse_iterator end;con._rend(end);
		//for (; ite != end; ++ite)
		//{
		//	const data_t& obj = *ite;
		//	...
		//}
		if (is_found)
			printf_detail("\n");
		else
			printf("(nothing)\n");
	};
	showListDesc();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

#if 0//�C�e���[�^�ƃ��b�N�擾�̃e�X�g
	{
		shared_lock_guard<container_t::lock_type> lock(con);
		container_t::iterator ite = con.begin();
		container_t::reverse_iterator rite = con.rbegin();
		container_t::iterator ite_end = con.end();
		container_t::reverse_iterator rite_end = con.rend();
		container_t::iterator ite2 = con.rbegin();
		container_t::reverse_iterator rite2 = con.begin();
		container_t::iterator ite2_end = con.rend();
		container_t::reverse_iterator rite2_end = con.end();
		printf("constructor\n");
		if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
		if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
		if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
		if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
		if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
		if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
		if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
		if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
		printf("copy operator\n");
		ite = con.begin();
		rite = con.rbegin();
		ite_end = con.end();
		rite_end = con.rend();
		ite2 = con.rbegin();
		rite2 = con.begin();
		ite2_end = con.rend();
		rite2_end = con.end();
		if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
		if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
		if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
		if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
		if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
		if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
		if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
		if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
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
			if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
			if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
			if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
			if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
			if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
			if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
			if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
			if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
		}
		printf("+= 7\n");
		ite += 7;
		rite += 7;
		ite_end += 7;
		rite_end += 7;
		ite2 += 7;
		rite2 += 7;
		ite2_end += 7;
		rite2_end += 7;
		if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
		if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
		if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
		if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
		if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
		if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
		if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
		if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
		printf("-= 7\n");
		ite -= 7;
		rite -= 7;
		ite_end -= 7;
		rite_end -= 7;
		ite2 -= 7;
		rite2 -= 7;
		ite2_end -= 7;
		rite2_end -= 7;
		if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
		if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
		if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
		if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
		if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
		if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
		if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
		if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
	}
#endif

	//�w��̃L�[�̃m�[�h���������A�����L�[�̃m�[�h�����X�g�A�b�v
	auto searchData = [&con]()
	{
		printf("--- Search node ---\n");
		for (int search_key = TEST_DATA_KEY_MIN; search_key <= TEST_DATA_KEY_MAX; ++search_key)
		{
			static const int print_count_limit = 10;
			int print_count = 0;
			bool is_found = false;
			std::for_each(con.find(search_key), con.equal_range(search_key),
				[&con, &is_found, &search_key, &print_count](const data_t& obj)
				{
					if (!is_found)
					{
						printf_dbg_search("%2d(%d):", search_key, con.count(search_key));
						is_found = true;
					}
					if (print_count < print_count_limit)
						printf_dbg_search("[%2d] ", obj.m_key);
					else if (print_count == print_count_limit)
						printf_dbg_search("...");
					++print_count;
				}
			);
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂������������I
			//const_iterator ite;con._find(ite, search_key);
			//const_iterator end;con._equal_range(end, search_key);
			//for (; ite != end; ++ite)
			//{
			//	const data_t& obj = *ite;
			//	...
			//}
			if (is_found)
				printf_dbg_search("\n");
		}
	};
	searchData();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�w��̃L�[�̃m�[�h������
	//����v�m�[�h�͕\�����ȗ�
	//���ŋ߃m�[�h���琔�m�[�h��\��
	auto searchNearestData = [&con](const rb_tree::match_type_t search_type)
	{
		printf("--- Search nearest node for %s ---\n", search_type == rb_tree::FOR_NEAREST_SMALLER ? "smaller" : search_type == rb_tree::FOR_NEAREST_LARGER ? "larger" : "same");
		for (int search_key = TEST_DATA_KEY_MIN; search_key <= TEST_DATA_KEY_MAX; ++search_key)
		{
			bool is_found = false;
			const_iterator ite(con.find(search_key, search_type));
			const_iterator end(con.end());
			for (int i = 0; ite != end && ite->m_key != search_key && i < 4; ++i, ++ite)
			{
				const data_t& obj = *ite;
				if (!is_found)
				{
					printf_dbg_search("%2d:", search_key);
					is_found = true;
				}
				printf_dbg_search("[%2d] ", obj.m_key);
			}
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂��������኱�����I
			//const_iterator ite;con._find(ite, search_key, search_type);
			//const_iterator end;con._end(end);
			//...
			if (is_found)
				printf_dbg_search("\n");
		}
	};
	//�w��̃L�[�Ɠ��������ւň�ԋ߂��m�[�h������
	searchNearestData(rb_tree::FOR_NEAREST_SMALLER);
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�w��̃L�[�Ɠ�����������傫���ŋ߃m�[�h������
	searchNearestData(rb_tree::FOR_NEAREST_LARGER);
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�m�[�h���폜
	//������̃L�[���폜
	auto removeNodes = [&con]()
	{
		printf("--- Remove nodes ---\n");
		auto erase = [&con](const int remove_key) -> bool
		{
			data_t* removed_node = con.erase(remove_key);
			if (removed_node)
			{
				delete removed_node;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
				return true;
			}
			return false;
		};
		int removed_count = 0;
	#ifndef TEST_DATA_REMOVING_LIST
		//�����_���Ƀf�[�^�폜
		std::mt19937 rand_engine;
		rand_engine.seed(1);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_KEY_MIN, TEST_DATA_KEY_MAX);
		const int removed_count_max = TEST_DATA_REG_NUM / 4;
		while (removed_count < removed_count_max)
		{
			const bool result = erase(rand_dist(rand_engine));
			if (result)
				++removed_count;
		}
	#else//TEST_DATA_REMOVING_LIST
		//�Œ菇�Ƀf�[�^�폜
		const int key_list[] = TEST_DATA_REMOVING_LIST;
		for (int key : key_list)
		{
			const bool result = erase(key);
			if (result)
				++removed_count;
		}
	#endif//TEST_DATA_REMOVING_LIST
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeNodes();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�e�}�܂ł̃m�[�h����\��
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�m�[�h���폜
	//�����ׂĂ̒l�̃L�[������폜
	auto removeEachKeyNodes = [&con]()
	{
		printf("--- Remove each-key nodes ---\n");
		int removed_count = 0;
		for (int remove_key = TEST_DATA_KEY_MIN; remove_key <= TEST_DATA_KEY_MAX; ++remove_key)
		{
			const_iterator ite(con.find(remove_key));
			data_t* removed_node = con.erase(*ite);
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂��������኱�����I
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (removed_node)
			{
				delete removed_node;
				++removed_count;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
			}
		}
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeEachKeyNodes();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�e�}�܂ł̃m�[�h����\��
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�m�[�h��S�폜
	//�����ׂĂ̒l�̃L�[�ɑ΂��āA�폜�����s����܂ō폜�����s
	auto removeAllNodes = [&con]()
	{
		printf("--- Remove all nodes ---\n");
		int removed_count = 0;
		for (int remove_key = TEST_DATA_KEY_MIN; remove_key <= TEST_DATA_KEY_MAX;)
		{
			const_iterator ite(con.find(remove_key));
			data_t* removed_node = con.erase(*ite);
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂��������኱�����I
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (removed_node)
			{
				delete removed_node;
				++removed_count;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
			}
			else
				++remove_key;
		}
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeAllNodes();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�؂�\��
	showTree();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�e�}�܂ł̃m�[�h����\��
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();
	prev_time = printElapsedTime(prev_time);//�o�ߎ��Ԃ�\��

	//�I��
	printf("--- end ---\n");
	printElapsedTime(begin_time);//�o�ߎ��Ԃ�\��

	return EXIT_SUCCESS;
}

// End of file
