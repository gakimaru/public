//--------------------------------------------------------------------------------
//�n�b�V���e�[�u���e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
static const int TEST_DATA_TABLE_SIZE = 500000;//�e�X�g�f�[�^�e�[�u���T�C�Y
//static const int TEST_DATA_TABLE_SIZE = 20;//�e�X�g�f�[�^�e�[�u���T�C�Y

//#define PRINT_TEST_DATA_DETAIL//�e�X�g�f�[�̏ڍ׃^��\������ꍇ�́A���̃}�N����L��������
//#define TEST_DATA_WATCH_CONSTRUCTOR//�R���X�g���N�^�^�f�X�g���N�^�^������Z�q�̓�����m�F����ꍇ�A���̃}�N����L��������

//#define USE_GCC//GCC�łŃR���p�C������Ƃ��́A���̃}�N����L��������

#include <cstddef>//s��d::size_t�p

//�yC++11�d�l�zthread_local�F�X���b�h���[�J���X�g���[�W�iTLS�j�C���q
#ifdef USE_GCC
#define thread_local __thread//GCC�p
#else//USE_GCC
#define thread_local __declspec(thread)//VC++�p
#endif//USE_GCC

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------
//�f���v�Z
//--------------------------------------------------------------------------------

#include <cstddef>//srd::size_t�p
#include <type_traits>//C++11 std::conditional, std:integral_constant�p

//----------------------------------------
//�y�����^�C���Łz
//----------------------------------------

//----------------------------------------
//�y�����^�C���Łz�f������
bool isPrime(const std::size_t n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if ((n & 0x1) == 0x0)//��������
		return false;
	for (std::size_t div = 3; div <= n / div; div += 2)
	{
		if (n % div == 0)
			return false;
	}
	return true;
}
//----------------------------------------
//�y�����^�C���Łz�O�̑f���𐶐�
std::size_t makePrimePrev(const std::size_t n)
{
	if (n <= 2)
		return 0;
	else if (n == 3)
		return 2;
	for (std::size_t nn = n - ((n & 0x1) == 0x0 ? 1 : 2);; nn -= 2)//�������͔��肵�Ȃ�
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//----------------------------------------
//�y�����^�C���Łz���̑f���𐶐�
std::size_t makePrimeNext(const std::size_t n)
{
	if (n < 2)
		return 2;
	for (std::size_t nn = n + ((n & 0x1) == 0x0 ? 1 : 2);; nn += 2)//�������͔��肵�Ȃ�
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//----------------------------------------
//�y�����^�C���Łz�w��̒l�Ɠ������A�O�̑f���𐶐�
std::size_t makePrimeEqPrev(const std::size_t n)
{
	return isPrime(n) ? n : makePrimePrev(n);
}
//----------------------------------------
//�y�����^�C���Łz�w��̒l�Ɠ������A���̑f���𐶐�
std::size_t makePrimeEqNext(const std::size_t n)
{
	return isPrime(n) ? n : makePrimeNext(n);
}

//----------------------------------------
//�y���^�v���O���~���O�Łz
//----------------------------------------
//�y���Ӂz
// ���^�v���O���~���O�łł́A�R���p�C���ɉ����ăe���v���[�g�̍ċA���x���̌��E������B
// ���̂��߁A���� 100001 ���炢�܂ł̑f�����������Ȃ��_�ɒ��ӁB
// ���̃e���v���[�g���Ŏg���ƁA�����Ɛ�����󂯂�_�ɂ����ӁB
// �܂��A�R���p�C�����Ԃɉe��������_�ɂ����ӁB
//----------------------------------------

//----------------------------------------
//�y���^�v���O���~���O�Łz�f������
//�������̔��������邽�߂ɊK�w������
template <std::size_t N, std::size_t DIV>//�ċA�N���X
struct _isPrimeMeta{
	typedef
		typename std::conditional<
			(DIV > N / DIV),
			std::integral_constant<bool, true>,
			typename std::conditional<
				(N % DIV == 0),
				std::integral_constant<bool, false>,
				_isPrimeMeta<N, DIV + 2>
			>::type
		>::type
		type;
	static const bool value = type::value;
};
template <std::size_t N>//�f������N���X
struct isPrimeMeta{
	typedef
		typename std::conditional<
			(N & 0x1) == 0x0,
			std::integral_constant<bool, false>,
			typename _isPrimeMeta<N, 3>::type
		>::type
		type;
	static const bool value = type::value;
};
template <>
struct isPrimeMeta<0>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<1>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<2>{
	static const bool value = true;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz�O�̑f���𐶐�
//�������̔��������邽�߂ɊK�w������
template<std::size_t N>//�ċA�N���X
struct _makePrimePrevMeta{
	typedef
		typename std::conditional<
			isPrimeMeta<N>::value,
			std::integral_constant<std::size_t, N>,
			_makePrimePrevMeta<N - 2>
		>::type
		type;
	static const std::size_t value = type::value;
};
template<std::size_t N>//�O�̑f�������N���X
struct makePrimePrevMeta{
	typedef
		typename std::conditional<
			(N & 0x1) == 0x0,
			_makePrimePrevMeta<N - 1>,
			_makePrimePrevMeta<N - 2>
		>::type
		type;
	static const std::size_t value = type::value;
};
template<>
struct makePrimePrevMeta<0>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<1>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<2>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<3>{
	static const std::size_t value = 2;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz���̑f���𐶐�
//�������̔��������邽�߂ɊK�w������
template<std::size_t N>//�ċA�N���X
struct _makePrimeNextMeta{
	typedef
		typename std::conditional<
			isPrimeMeta<N>::value,
			std::integral_constant<std::size_t, N>,
			_makePrimeNextMeta<N + 2>
		>::type
		type;
	static const std::size_t value = type::value;
};
template<std::size_t N>//���̑f�������N���X
struct makePrimeNextMeta{
	typedef
		typename std::conditional<
			(N & 0x1) == 0x0,
			_makePrimeNextMeta<N + 1>,
			_makePrimeNextMeta<N + 2>
		>::type
		type;
	static const std::size_t value = type::value;
};
template<>
struct makePrimeNextMeta<0>{
	static const std::size_t value = 2;
};
template<>
struct makePrimeNextMeta<1>{
	static const std::size_t value = 2;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz�w��̒l�Ɠ������A�O�̑f���𐶐�
template<std::size_t N>
struct makePrimeEqPrevMeta{
	typedef
		typename std::conditional<
			isPrimeMeta<N>::value,
			std::integral_constant<std::size_t, N>,
			makePrimePrevMeta<N>
		>::type
		type;
	static const std::size_t value = type::value;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz�w��̒l�Ɠ������A���̑f���𐶐�
template<std::size_t N>
struct makePrimeEqNextMeta{
	typedef
		typename std::conditional<
			isPrimeMeta<N>::value,
			std::integral_constant<std::size_t, N>,
			makePrimeNextMeta<N>
		>::type
		type;
	static const std::size_t value = type::value;
};

//--------------------------------------------------------------------------------
//���샊�[�h�E���C�g���b�N�N���X
//--------------------------------------------------------------------------------

#include <thread>
#include <atomic>

//--------------------------------------------------------------------------------
//�X���b�hID�N���X
//--------------------------------------------------------------------------------
//��ID���n�b�V���������ꍇ�ATLS�����p���č�����
//--------------------------------------------------------------------------------

//�X���b�hID�^
#define THREAD_ID_IS_HASH//�X���b�hID���n�b�V���^�ň����ꍇ�͂��̃}�N����L��������i�n�b�V���̕��������j
#ifdef THREAD_ID_IS_HASH
typedef std::size_t THREAD_ID;//(�n�b�V��)
static const THREAD_ID INVALID_THREAD_ID = std::hash<std::thread::id>()(std::thread::id());//�����ȃX���b�hID(�n�b�V��)
static const THREAD_ID INITIAL_THREAD_ID = static_cast<THREAD_ID>(~0);//�����X���b�hID(�n�b�V��)
#else//THREAD_ID_IS_HASH
typedef std::thread::id THREAD_ID;
static const THREAD_ID INVALID_THREAD_ID = std::thread::id();//�����ȃX���b�hID
#endif//THREAD_ID_IS_HASH

//���݂̃X���b�hID�擾�֐�
#ifdef THREAD_ID_IS_HASH
inline THREAD_ID GetThisThreadID(){ return std::hash<std::thread::id>()(std::this_thread::get_id()); }//(�n�b�V��)
#else//THREAD_ID_IS_HASH
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id(); }
#endif//THREAD_ID_IS_HASH

//�X���b�hID�N���X
class CThreadID
{
public:
	//�A�N�Z�b�T
	const THREAD_ID getID() const { return m_threadId; }//�X���b�hID���擾
	const char* getName() const { return m_threadName; }//�X���b�h�����擾
public:
	//�A�N�Z�b�T�istatic�j
#ifdef THREAD_ID_IS_HASH
	static THREAD_ID getThisID(){ return m_thisThreadID; }//���݂̃X���b�h�̃X���b�hID���擾(�n�b�V��)
#else//THREAD_ID_IS_HASH
	static THREAD_ID getThisID(){ return GetThisThreadID(); }//���݂̃X���b�h�̃X���b�hID���擾
#endif//THREAD_ID_IS_HASH
	static const char* getThisName(){ return m_thisThreadName; }//���݂̃X���b�h�̃X���b�h�����擾
public:
	//���\�b�h
	bool isThisThread() const { return m_threadId == getThisID(); }//���݂̃X���b�h�Ɠ����X���b�h������
private:
	//���\�b�h(static)
	static void setThisThread()//���݂̃X���b�h�̃X���b�hID���Z�b�g
	{
#ifdef THREAD_ID_IS_HASH
		if (m_thisThreadID == INITIAL_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
#endif//THREAD_ID_IS_HASH
	}
	static void resetThisThread(const char* name)//���݂̃X���b�h�̃X���b�hID�����Z�b�g
	{
#ifdef THREAD_ID_IS_HASH
		m_thisThreadID = GetThisThreadID();
#endif//THREAD_ID_IS_HASH
		m_thisThreadName = name;
	}
public:
	//�I�y���[�^�i���j
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID��v����
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID�s��v����
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID��v����
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID�s��v����
	CThreadID& operator=(const CThreadID& o)//�R�s�[���Z�q
	{
		m_threadId = o.m_threadId;
		m_threadName = o.m_threadName;
		return *this;
	}
private:
	//�I�y���[�^�i�֎~�j
	CThreadID& operator=(const THREAD_ID& id) { return *this; }//�R�s�[���Z�q�i�֎~�j
public:
	//�R�s�[�R���X�g���N�^�i���j
	explicit CThreadID(const CThreadID& o) :
		m_threadId(o.m_threadId),
		m_threadName(o.m_threadName)
	{
	}
private:
	//�R�s�[�R���X�g���N�^�i�֎~�j
	explicit CThreadID(const THREAD_ID& id){}
public:
	//�R���X�g���N�^
	//���X���b�h�����w�肵�A�����Ō��݂̃X���b�hID���擾���ĕێ�
	//��TLS�ɂ��L�^
	CThreadID(const char* name)
	{
		resetThisThread(name);
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
	//�f�t�H���g�R���X�g���N�^
	//������TLS�ɋL�^�ς݂̃X���b�hID�i�Ɩ��O�j���擾
	CThreadID()
	{
		setThisThread();
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
private:
	//�t�B�[���h
	THREAD_ID m_threadId;//�X���b�hID�i�I�u�W�F�N�g�ɕۑ�����l�j
	const char* m_threadName;//�X���b�h���i�I�u�W�F�N�g�ɕۑ�����l�j
#ifdef THREAD_ID_IS_HASH
	static thread_local THREAD_ID m_thisThreadID;//���݂̃X���b�h�̃X���b�hID(TLS)
#endif//THREAD_ID_IS_HASH
	static thread_local const char* m_thisThreadName;//���݂̃X���b�h��(TLS)
};
//static�ϐ��̃C���X�^���X��
#ifdef THREAD_ID_IS_HASH
thread_local THREAD_ID CThreadID::m_thisThreadID = INITIAL_THREAD_ID;//�X���b�hID(TLS)
#endif//THREAD_ID_IS_HASH
thread_local const char* CThreadID::m_thisThreadName = nullptr;//�X���b�h��(TLS)

//--------------------------------------------------------------------------------
//�y�ʃX�s�����b�N
//--------------------------------------------------------------------------------

//----------------------------------------
//�y�ʃX�s�����b�N
//����y�Ɏg����X�s�����b�N
//�����񐔂̃X���[�v���ƂɃX���[�v�i�R���e�L�X�g�X�C�b�`�j���s��
//���e�ʂ�4�o�C�g(std::atomic_flag����̃T�C�Y)
//���v���O���~���O��̈��S���͒Ⴂ�̂ŋC����Ɏg���ׂ��ł͂Ȃ�
//�@�@�˃��b�N�擾��Ԃ��m�F�����ɃA�����b�N����
#define SPIN_LOCK_USE_ATOMIC_FLAG//std::atomic_flag�Łi�����j
//#define SPIN_LOCK_USE_ATOMIC_BOOL//std::atomic_bool�Łi�y�ʁj
class CSpinLock
{
public:
	//�萔
	static const int DEFAULT_SPIN_COUNT = 1000;//�X�s�����b�N�J�E���g�̃f�t�H���g�l
public:
	//���b�N�擾
	void lock(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = 0;
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		while (m_lock.test_and_set())//std::atomic_flag�Łi�����j
		{
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		bool prev = false;
		while (m_lock.compare_exchange_weak(prev, true))//std::atomic_bool�Łi�y�ʁj
		{
			prev = false;
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
			if (spin_count == 0 || ++spin_count_now % spin_count == 0)
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//�X���[�v�i�R���e�L�X�g�X�C�b�`�j
		}
	}
	//���b�N���
	void unlock()
	{
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.clear();//std::atomic_flag�Łi�����j
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.store(false);//std::atomic_bool�Łi�y�ʁj
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
	}
public:
	//�R���X�g���N�^
	CSpinLock()
	{
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.clear();//���b�N�p�t���O�i�����j
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.store(false);//���b�N�p�t���O�i�y�ʁj
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
	}
	//�f�X�g���N�^
	~CSpinLock()
	{
	}
private:
	//�t�B�[���h
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
	std::atomic_flag m_lock;//���b�N�p�t���O�i�����j
#else//SPIN_LOCK_USE_ATOMIC_FLAG
	std::atomic_bool m_lock;//���b�N�p�t���O�i�y�ʁj
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
};

//--------------------------------------------------------------------------------
//���[�h�E���C�g���b�N�N���X
//--------------------------------------------------------------------------------
//���e�ʐߖ�̂��߂ɁAPOSIX�X���b�h���C�u�����ł̂悤�ɁA���݂̃X���b�h�̃��b�N��Ԃ�ێ����Ȃ�
//���K�����b�N�N���X CRWLock::LockR, CRWLock::LockR_AsNecessary, CRWLock::LockW ���g�p���A
//�@�����Ɍ��݂̃��b�N��Ԃ�ێ�����
//--------------------------------------------------------------------------------

//----------------------------------------
//�N���X�錾
class CRWLockHelper;

//----------------------------------------
//���[�h�E���C�g���b�N�N���X
class CRWLock
{
	friend class CRWLockHelper;//�蓮�Ń��b�N�^�A�����b�N�𑀍삷�邽�߂̃w���p�[�N���X
public:
	//�萔
	enum E_WLOCK_PRIORITY//���C�g���b�N�D��x
	{
		WLOCK_PRIORITIZED,//���C�g���b�N�D��
		NOT_WLOCK_PRIORITIZED,//���C�g���b�N�D�悵�Ȃ�
		ALL_WLOCK//�S�ă��C�g���b�N�ɂ���i���[�h���b�N�������I�Ƀ��C�g���b�N�ɂȂ�j
	};
public:
	//----------------------------------------
	//�y�N���X���N���X�z�N���X�錾
	class RLock;
	class RLockAsNecessary;
	class WLock;
	//----------------------------------------
	//�y�N���X���N���X�z���b�N�N���X�@���p����p
	class Lock
	{
		friend class CRWLock;
	public:
		//�A�N�Z�b�T
		bool isWriteLock() const { return m_isWriteLock; }//���C�g���b�N���[�h���H
		bool isUnlocked() const { return m_isUnlocked; }//���݃A�����b�N��Ԃ��H�i���b�N��ԂȂ̂����ʁj
	public:
		//���\�b�h

		//�����I�ȃ��[�h���b�N
		//�����[�h���b�N�����u�K�v�ɉ����ă��[�h���b�N�v�Ȃ瓯������ɂȂ�
		//�������I�ȃ��b�N�����p���\�b�h
		//���ʏ�̓R���X�g���N�^�Ń��b�N����̂Ŏg�p���Ȃ�
		void rlock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
		{
			if (!m_isUnlocked)
				return;
			m_lock.rlock(spin_count, m_ignoreThreadId);
			m_isWriteLock = false;
			m_isUnlocked = false;
		}
		//�����I�ȃ��C�g���b�N
		//�������I�ȃ��b�N�����p���\�b�h
		//���ʏ�̓R���X�g���N�^�Ń��b�N����̂Ŏg�p���Ȃ�
		void wlock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
		{
			if (!m_isUnlocked)
				return;
			m_lock.wlock(spin_count);
			m_isWriteLock = true;
			m_isUnlocked = false;
		}
		//�����I�ȃA�����b�N
		//���ʏ�̓f�X�g���N�^�ŃA�����b�N����̂Ŏg�p���Ȃ�
		void unlock()
		{
			if (m_isUnlocked)
				return;
			if (m_isWriteLock)
				m_lock.wunlock();
			else
				m_lock.runlock();
			m_isUnlocked = true;
		}
	private:
		//�I�y���[�^
		Lock& operator=(const Lock& o){ return *this; }//�R�s�[���Z�q�i�֎~�j
	private:
		//�R���X�g���N�^
		explicit Lock(const Lock& o) :m_lock(o.m_lock){}//�R�s�[�R���X�g���N�^�i�֎~�j
	public:
		//���[�u�R���X�g���N�^
		inline Lock(Lock&& lock) :
			m_lock(lock.m_lock),
			m_ignoreThreadId(lock.m_ignoreThreadId),
			m_isWriteLock(lock.m_isWriteLock),
			m_isUnlocked(lock.m_isUnlocked)
		{
			//�ړ����̃��b�N�I�u�W�F�N�g�̓A�����b�N�����ɂ��āA
			//�f�X�g���N�^�ŃA�����b�N���Ă��܂����Ƃ�h��
			lock.m_isUnlocked = true;
		}
	protected:
		//�R���X�g���N�^�@���e�탍�b�N�N���X����̂ݎg�p

		//���[�h���b�N�p�R���X�g���N�^
		inline Lock(const RLock*, CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(INVALID_THREAD_ID),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//���[�h���b�N
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		//�K�v�ɉ����ă��[�h���b�N�p�R���X�g���N�^
		inline Lock(const RLockAsNecessary*, CRWLock& lock, const CThreadID& ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(ignore_thread_id.getID()),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//�K�v�ɉ����ă��[�h���b�N
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		inline Lock(const RLockAsNecessary*, CRWLock& lock, const THREAD_ID ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(ignore_thread_id),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//�K�v�ɉ����ă��[�h���b�N
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		//���C�g���b�N�p�R���X�g���N�^
		inline Lock(const WLock*, CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(INVALID_THREAD_ID),
			m_isWriteLock(true),
			m_isUnlocked(false)
		{
			//���C�g���b�N
			m_lock.wlock(spin_count);
		}
	public:
		//�f�X�g���N�^
		//���A�����b�N
		~Lock()
		{
			unlock();
		}
	private:
		//�t�B�[���h
		CRWLock& m_lock;//���[�h�E���C�g�I�u�W�F�N�g�̎Q��
		THREAD_ID m_ignoreThreadId;//���[�h���b�N�𖳎�����X���b�hID
		bool m_isWriteLock;//���C�g���b�N���[�h���H
		bool m_isUnlocked;//�A�����b�N��Ԃ��H
	};
public:
	//----------------------------------------
	//�y�N���X���N���X�z���[�h���b�N�N���X
	class RLock : public Lock
	{
	private:
		//�I�y���[�^
		RLock& operator=(const RLock& o){ return *this; }//�R�s�[���Z�q�i�֎~�j
	private:
		//�R���X�g���N�^
		explicit RLock(const Lock& o) :Lock(o){}//�R�s�[�R���X�g���N�^�i�֎~�j
	public:
		//���[�u�R���X�g���N�^
		inline RLock(RLock&& lock) :
			Lock(std::move(lock))
		{
		}
	public:
		//�R���X�g���N�^
		inline RLock(CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, spin_count)
		{}
		//�f�X�g���N�^
		inline ~RLock()
		{}
	};
	//----------------------------------------
	//�y�N���X���N���X�z�K�v�ɉ����ă��[�h���b�N�N���X
	class RLockAsNecessary : public Lock
	{
	private:
		//�I�y���[�^
		RLockAsNecessary& operator=(const RLockAsNecessary& o){ return *this; }//�R�s�[���Z�q�i�֎~�j
	private:
		//�R���X�g���N�^
		explicit RLockAsNecessary(const RLockAsNecessary& o) :Lock(o){}//�R�s�[�R���X�g���N�^�i�֎~�j
	public:
		//���[�u�R���X�g���N�^
		inline RLockAsNecessary(RLockAsNecessary&& lock) :
			Lock(std::move(lock))
		{}
	public:
		//�R���X�g���N�^
		inline RLockAsNecessary(CRWLock& lock, const CThreadID& ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, ignore_thread_id, spin_count)
		{}
		inline RLockAsNecessary(CRWLock& lock, const THREAD_ID ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, ignore_thread_id, spin_count)
		{}
		inline RLockAsNecessary(CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, CThreadID::getThisID(), spin_count)
		{}
		//�f�X�g���N�^
		inline ~RLockAsNecessary()
		{}
	};
	//----------------------------------------
	//�y�N���X���N���X�z���C�g���b�N�N���X
	class WLock : public Lock
	{
	private:
		//�I�y���[�^
		WLock& operator=(const WLock& lock){ return *this; }//�R�s�[���Z�q�i�֎~�j
	private:
		//�R���X�g���N�^
		explicit WLock(const WLock& lock) :Lock(lock){}//�R�s�[�R���X�g���N�^�i�֎~�j
	public:
		//���[�u�R���X�g���N�^
		inline WLock(WLock&& lock) :
			Lock(std::move(lock))
		{}
	public:
		//�R���X�g���N�^
		inline WLock(CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, spin_count)
		{}
		//�f�X�g���N�^
		inline ~WLock()
		{}
	};
	//----------------------------------------
	//�y�N���X���N���X�z�i�ȏ�ŏI���j

public:
	//�y���b�N�I�u�W�F�N�g��Ԃ����b�N���\�b�h�z
	//���E�Ӓl�Q�Ƃ��g�p���邱�Ƃɂ��A�u�R�s�[�R���X�g���N�^�v��
	//�@��ʂ��āu���[�u�R���X�g���N�^�v���L�q�ł���
	//������𗘗p���āA�֐��̓����ō쐬�����I�u�W�F�N�g�̓��e��
	//�@�Ăяo�����̃I�u�W�F�N�g�Ɉړ�����B
	//�@���[�u�R���X�g���N�^�ł́A�ړ����I�u�W�F�N�g��
	//�@�A�����b�N�ς݈����ɂ��Ă����̂ŁA�֐��I������
	//�@���[�J���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo����Ă��A
	//�@�A�����b�N���Ă��܂����Ƃ��Ȃ��B

	//�y���b�N�I�u�W�F�N�g��Ԃ����b�N���\�b�h�z���[�h���b�N
	RLock rLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RLock lock(*this, spin_count);
		return std::move(lock);
	}
	//�y���b�N�I�u�W�F�N�g��Ԃ����b�N���\�b�h�z�K�v�ɉ����ă��[�h���b�N
	RLockAsNecessary rLockAsNecessary(const CThreadID& ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, ignore_thread_id, spin_count);
		return std::move(lock);
	}
	RLockAsNecessary rLockAsNecessary(const THREAD_ID ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, ignore_thread_id, spin_count);
		return std::move(lock);
	}
	RLockAsNecessary rLockAsNecessary(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, spin_count);
		return std::move(lock);
	}
	//�y���b�N�I�u�W�F�N�g��Ԃ����b�N���\�b�h�z���C�g���b�N
	WLock wLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		WLock lock(*this, spin_count);
		return std::move(lock);
	}

private:
	//���\�b�h�@�����b�N�N���X����̂ݎg�p

	//���[�h���b�N�擾
	//���K�v�ɉ����ă��[�h���b�N�̋@�\�������
	void rlock(const int spin_count, const THREAD_ID ignore_thread_id)
	{
		//�S�ă��C�g���b�N�ɂ��郂�[�h�p����
		if (m_wlockPrioritized == ALL_WLOCK)
		{
			wlock(spin_count);
			return;
		}

		//���[�h���b�N�X�L�b�v�`�F�b�N
		//�����[�h�E���C�g���b�N�I�u�W�F�N�g�C���X�^���X�������A����сA���[�h���b�N���ɁA
		//�@���ɃX���b�hID���w�肳��Ă����ꍇ�A���A���ꂪ����ID�ł������ꍇ�A
		//�@���[�h���b�N���X�L�b�v����
		if (ignore_thread_id != INVALID_THREAD_ID && m_ignoreThreadId == ignore_thread_id)//&& m_writeLock.load() == false)
			//�����C�g���b�N��Ԃ̓`�F�b�N���Ȃ�
			//���v���O������M�����č�������O�ꂷ��
			//�����ɂ��̔�����s���Ă��Am_lock �ŕی삵�Ȃ�����͕s�m���ȃu���b�N
		{
			m_readLock.fetch_add(1);
			return;
		}

		//���[�h���b�N�\��J�E���g�A�b�v
		//�������͕K�v�Ȃ����A���ǐՎ��̎Q�l�p
		m_readLockReserved.fetch_add(1);

		//���[�h���b�N�ҋ@���[�v
		while (1)
		{
			//�����ϐ��X�V���b�N�擾
			m_lock.lock(spin_count);

			//�����ϐ��X�V���b�N���擾�ł����̂ŁA���C�g���b�N�̏�Ԃ��`�F�b�N
			if (m_writeLock.load() == false &&//���C�g���b�N��Ԃł͂Ȃ�
				(m_wlockPrioritized != WLOCK_PRIORITIZED ||//���C�g���b�N�D�惂�[�h�ł͂Ȃ�
				m_wlockPrioritized == WLOCK_PRIORITIZED && m_writeLockReserved.load() == 0))//���C�g���b�N�D�惂�[�h�Ȃ�A���C�g���b�N�\�񂪂Ȃ����Ƃ��`�F�b�N
			{
				//���[�h���b�NOK
				m_readLock.fetch_add(1);//���[�h���b�N�J�E���g�A�b�v
				m_lock.unlock();//�����ϐ��X�V���b�N���
				break;
			}

			//�����ϐ��X�V���b�N���
			//�����[�h���b�N���擾�ł���܂ōĂёҋ@
			m_lock.unlock();//�����ϐ��X�V���b�N���
		}

		//���[�h���b�N�\��J�E���g�_�E��
		//�������͕K�v�Ȃ����A���ǐՎ��̎Q�l�p
		m_readLockReserved.fetch_sub(1);
	}
	//���C�g���b�N�擾
	void wlock(const int spin_count)
	{
		//���C�g���b�N�\��J�E���g�A�b�v
		m_writeLockReserved.fetch_add(1);

		//���C�g���b�N�ҋ@���[�v
		while (1)
		{
			//�����ϐ��X�V���b�N�擾
			m_lock.lock(spin_count);

			//�����ϐ��X�V���b�N���擾�ł����̂ŁA���[�h���b�N�ƃ��C�g���b�N�̏�Ԃ��`�F�b�N
			if (m_readLock.load() == 0 && m_writeLock.load() == false)
			{
				//���C�g���b�NOK
				m_writeLock.store(true);//���C�g���b�NON
				m_lock.unlock();//�����ϐ��X�V���b�N���
				break;
			}

			//�����ϐ��X�V���b�N���
			//�����C�g���b�N���擾�ł���܂ōĂёҋ@
			m_lock.unlock();//�����ϐ��X�V���b�N���
		}

		//���C�g���b�N�\��J�E���g�_�E��
		m_writeLockReserved.fetch_sub(1);
	}
	//���[�h���b�N���
	void runlock()
	{
		//�S�ă��C�g���b�N�ɂ��郂�[�h�p����
		if (m_wlockPrioritized == ALL_WLOCK)
		{
			wunlock();
			return;
		}

		//���[�h���b�N�J�E���g�_�E��
		m_readLock.fetch_sub(1);
	}
	//���C�g���b�N���
	void wunlock()
	{
		//���C�g���b�NOFF
		m_writeLock.store(false);
	}
public:
	//�A�N�Z�b�T
	THREAD_ID getIgnoreThreadID() const { return m_ignoreThreadId; }//�u�K�v�ɉ����ă��[�h���b�N�v�p�̃X���b�hID
	void setIgnoreThreadID(const THREAD_ID thread_id) { m_ignoreThreadId = thread_id; }//�u�K�v�ɉ����ă��[�h���b�N�v�p�̃X���b�hID���X�V
	int getReadLockReserved() const { return m_readLockReserved.load(); }//���[�h���b�N�\��J�E���^ �������͕K�v�Ȃ����A���ǐՎ��̎Q�l�p
	int getReadLock() const { return m_readLock.load(); }//���[�h���b�N�J�E���^
	int getWriteLockReserved() const { return m_writeLockReserved.load(); }//���C�g���b�N�\��J�E���^
	bool getWriteLock() const { return m_writeLock.load(); }//���C�g���b�N�t���O
	E_WLOCK_PRIORITY getWlockPrioritized() const { return m_wlockPrioritized; }//���C�g���b�N�D��x
public:
	//�R���X�g���N�^
	CRWLock(const THREAD_ID ignore_thread_id, const E_WLOCK_PRIORITY wlock_prioritized) :
		m_ignoreThreadId(ignore_thread_id),
		m_readLockReserved(0),
		m_readLock(0),
		m_writeLockReserved(0),
		m_writeLock(false),
		m_wlockPrioritized(wlock_prioritized)
	{}
	CRWLock(const CThreadID& ignore_thread_id, const E_WLOCK_PRIORITY wlock_prioritized) :
		CRWLock(ignore_thread_id.getID(), wlock_prioritized)
	{}
	CRWLock(const CThreadID& ignore_thread_id) :
		CRWLock(ignore_thread_id.getID(), WLOCK_PRIORITIZED)
	{}
	CRWLock(const THREAD_ID ignore_thread_id) :
		CRWLock(ignore_thread_id, WLOCK_PRIORITIZED)
	{}
	CRWLock(const E_WLOCK_PRIORITY wlock_prioritized) :
		CRWLock(CThreadID::getThisID(), wlock_prioritized)
	{}
	CRWLock() :
		CRWLock(CThreadID::getThisID(), WLOCK_PRIORITIZED)
	{}
	//�f�X�g���N�^
	~CRWLock()
	{}
private:
	//�t�B�[���h
	THREAD_ID m_ignoreThreadId;//�u�K�v�ɉ����ă��[�h���b�N�v�p�̃X���b�hID
	std::atomic<int> m_readLockReserved;//���[�h���b�N�\��J�E���^ �������͕K�v�Ȃ����A���ǐՎ��̎Q�l�p
	std::atomic<int> m_readLock;//���[�h���b�N�J�E���^
	std::atomic<int> m_writeLockReserved;//���C�g���b�N�\��J�E���^
	std::atomic<bool> m_writeLock;//���C�g���b�N�t���O
	CSpinLock m_lock;//�����ϐ��X�V�p���b�N�t���O
	E_WLOCK_PRIORITY m_wlockPrioritized;//���C�g���b�N�D��x
};

//�u���[�h���b�N�N���X�v�u�K�v�ɉ����ă��[�h���b�N�N���X�v�u���C�g���b�N�N���X�v�̕ʖ���ݒ�
typedef CRWLock::RLock CRWLockR;
typedef CRWLock::RLockAsNecessary CRWLockR_AsNecessary;
typedef CRWLock::WLock CRWLockW;

//�yC++11�X�^�C���z�u���[�h���b�N�N���X�v�u�K�v�ɉ����ă��[�h���b�N�N���X�v�u���C�g���b�N�N���X�v�̕ʖ���ݒ�
//using CRWLockR = CRWLock::RLock;
//using CRWLockR_AsNecessary = CRWLock::RLockAsNecessary;
//using CRWLockW = CRWLock::WLock;

//----------------------------------------
//���[�h�E���C�g���b�N�w���p�[�N���X
//�����b�N�N���X��p�����ɁA���ڃ��[�h�E���C�g���b�N�𑀍삷�邽�߂̃N���X
//�����p�֎~
class CRWLockHelper
{
public:
	//���\�b�h

	//���[�h���b�N�擾
	void rLock(const int spin_count)
	{
		m_lock.rlock(spin_count, INVALID_THREAD_ID);
	}
	//�K�v�ɉ����ă��[�h���b�N�擾
	void rLockAsNecessary(const CThreadID& ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		m_lock.rlock(spin_count, ignore_thread_id.getID());
	}
	void rLockAsNecessary(const THREAD_ID ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		m_lock.rlock(spin_count, ignore_thread_id);
	}
	void rLockAsNecessary(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		m_lock.rlock(spin_count, CThreadID::getThisID());
	}
	//���C�g���b�N�擾
	void wLock(const int spin_count)
	{
		m_lock.wlock(spin_count);
	}
	//���[�h���b�N���
	void rUnlock()
	{
		m_lock.runlock();
	}
	//���C�g���b�N���
	void wUnlock()
	{
		m_lock.wunlock();
	}
public:
	//�R���X�g���N�^
	CRWLockHelper(CRWLock& lock) :
		m_lock(lock)
	{}
	//�f�X�g���N�^
	~CRWLockHelper()
	{}
private:
	//�t�B�[���h
	CRWLock& m_lock;//���[�h�E���C�g�I�u�W�F�N�g�̎Q��
};

//--------------------------------------------------------------------------------
//�n�b�V���e�[�u��
//--------------------------------------------------------------------------------
//�f�[�^�\���ƃA���S���Y��
//�y�����z
//�E�_�u���n�b�V���A���S���Y�����̗p�B
//�@  - �n�b�V���@ ... �ŏ��̃C���f�b�N�X�B�L�[�ɉ����Đ����B
//�@  - �n�b�V���A ... �Փ˂̍ۂ̃C���f�b�N�X�̕����B�L�[�ɉ����Đ����B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y�{�v���O�����ɂ���������v���z
//�E�Œ�z��Ŏ������A��؃������m�ہE�폜�����Ȃ��B
//�E�L�[�d�������e���Ȃ��A���S���Y���Ƃ���B
//�E������istd::string/char*�j�̃L�[���T�|�[�g���Ȃ��B
//�E����ɁA������L�[�͎����I��crc32�ϊ����s���B�i������͕ێ����Ȃ��j
//�E�����������̂��߂ɁA�f�[�^�̍폜���͎��ۂɍ폜�����A
//�@�폜�ς݃t���O��p������̂Ƃ���B
//�@�����������́A�폜�ς݂̃f�[�^�����o���Ă��ł��؂�Ȃ����ƂŌ���������B
//�@�����̂��߁A�p�ɂɓo�^�^�폜���J��Ԃ��ƁA���o�^�f�[�^��������
//�@�@���x���򉻂���\��������B
//�ESTL�istd::unodered_map�j�Ƃ̈Ⴂ�͉��L�̒ʂ�
//    - �Œ蒷�z��ł���B�iSTL�͎����g������j
//    - �Փˎ��͊J�Ԓn����p���ď������A������������s��Ȃ��B
//        ��STL�́i�����炭�j�A���@�BSTL�̕����������A��葽���̃�������K�v�Ƃ���B
//    - ���n�b�V���͍폜�ς݃f�[�^��|������̂݁B
//    - �L�[�ƒl�̃y�A�istd::pair�j�ň��킸�A��{�I�ɃL�[�ƒl�𒼐ڈ����B
//      ���̑���A�C�e���[�^�ɂ̓C���f�b�N�X��L�[�Ȃǂ̏����܂ށB
//�@�@- insert/erase���̃C�e���[�^�w��ɑΉ����Ȃ��B
//    - �ԍ��؃R���e�i�irb_tree�j�̎����ƍ��킹���\���ɂ��Ă���A
//�@�@  ����p�e���v���[�g�\���̂�p����B
//--------------------------------------------------------------------------------

#include <bitset>//std::bitset�p
#include <cstddef>//srd::size_t�p
#include <iterator>//std::iterator�p
#include <utility>//std::move�p
#include <string>//std::string�p

#ifdef USE_GCC
#include "../StaticCRC32_unix/constexpr.h"
#else//USE_GCC
#include "../../StaticCRC32/StaticCRC32/src/constexpr/constexpr.h"
#endif//USE_GCC

namespace hash_table
{
	//--------------------
	//�n�b�V���e�[�u���f�[�^����p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public hash_table::base_ope_t<�h���\����, �L�[�^, �l�^, �L�[�̍ŏ��l= 0u, �L�[�̍ő�l = 0xffffffffu, �s���ȃL�[ = 0xffffffffu>
	//	struct ope_t : public hash_table::ope_t<ope_t, crc32_t, data_t, 500>
	//	{
	//		//�L�[���擾
	//		inline static key_type getKey(const value_type& value){ return ???; }
	//	};
	template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	struct base_ope_t
	{
		//�萔
		static const KEY_TYPE KEY_MIN = _KEY_MIN;//�L�[�̍ŏ��l
		static const KEY_TYPE KEY_MAX = _KEY_MAX;//�L�[�̍ő�l
		static const KEY_TYPE INVALID_KEY = _INVALID_KEY;//�s���ȃL�[

		//�^
		typedef OPE_TYPE ope_type;//�f�[�^����^
		typedef VALUE_TYPE value_type;//�l�^
		typedef KEY_TYPE key_type;//�L�[�^

		//�f�X�g���N�^�Ăяo��
		static void callDestructor(value_type* obj){ obj->~VALUE_TYPE(); }
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::value_type value_type; \
		typedef typename ope_type::key_type key_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type;
	
	//----------------------------------------
	//�n�b�V���e�[�u���R���e�i�p�萔
	enum replace_attr_t : unsigned char//�f�[�^�u������
	{
		NEVER_REPLACE,//�L�[���d������f�[�^�͓o�^�ł��Ȃ��i�u�����Ȃ��j
		REPLACE,//�L�[���d������f�[�^�͒u�����ēo�^����
	};
	enum auto_lock_attr_t : unsigned char//�������b�N����
	{
		NEVER_LOCK,//���b�N���Ȃ�
		AUTO_WRITE_LOCK,//�������C�g���b�N
	};
	//----------------------------------------
	//�n�b�V���e�[�u���R���e�i
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _AUTO_REHASH_RATIO = 25, int _FINDING_CYCLE_LIMIT = 0, std::size_t _INDEX_STEP_BASE = 5>
	class container
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//�萔
		static const size_type ORIGINAL_TABLE_SIZE = _TABLE_SIZE;//�e�[�u���T�C�Y�i���X�w�肳�ꂽ�T�C�Y�j
		static const size_type TABLE_SIZE = makePrimeEqNextMeta<ORIGINAL_TABLE_SIZE>::value;//�e�[�u���T�C�Y�i�w��T�C�Y�Ɠ������A������傫���f���j
		static const size_type TABLE_SIZE_EXTENDED = TABLE_SIZE - ORIGINAL_TABLE_SIZE;//�w��T�C�Y����g�������T�C�Y
		static const size_type  AUTO_REHASH_RATIO = _AUTO_REHASH_RATIO;//�������n�b�V�����s�̊���� ���폜�ς݌������S�̃T�C�Y�̈�芄���ȏ�ɂȂ����玩�����n�b�V�� ��0�Ŏ������n�b�V���Ȃ�
		static const size_type  AUTO_REHASH_SIZE = AUTO_REHASH_RATIO == 0 ? 0 : TABLE_SIZE * AUTO_REHASH_RATIO / 100;//�������n�b�V�����s�̊�T�C�Y �������ƃe�[�u���T�C�Y����v�Z
		static const int FINDING_CYCLE_LIMIT = _FINDING_CYCLE_LIMIT;//�������̏���񐔂̐��� ��0�Ŗ�����
		static const key_type KEY_MIN = ope_type::KEY_MIN;//�L�[�̍ŏ��l
		static const key_type KEY_MAX = ope_type::KEY_MAX;//�L�[�̍ő�l
		static const index_type INDEX_STEP_BASE = _INDEX_STEP_BASE;//�������񎞂̃C���f�b�N�X�̃X�����̊�l ���K���f���łȂ���΂Ȃ�Ȃ�
		static const index_type INVALID_INDEX = 0xffffffffu;//�����ȃC���f�b�N�X
	public:
		//���^�֐�
		//�L�[�͈͒萔�v�Z�i�Q�o���G�[�V�����j
		template <bool COND, typename size_type, typename key_type, key_type KEY_MIN, key_type KEY_MAX>
		struct calcKeyRangeImpl{
			static const key_type value = KEY_MAX - KEY_MIN + 1;
		};
		template <typename size_type, typename key_type, key_type KEY_MIN, key_type KEY_MAX>
		struct calcKeyRangeImpl<true, size_type, key_type, KEY_MIN, KEY_MAX>{
			static const key_type value = 0;
		};
		//�C���f�b�N�X�v�Z�֐��i�Q�o���G�[�V�����j
		template <bool COND, typename size_type, typename index_type, typename key_type, size_type TABLE_SIZE, key_type KEY_MIN, key_type KEY_RANGE>
		struct calcIndexImpl{
			inline static index_type calc(const key_type key){ return (key - KEY_MIN) % TABLE_SIZE; }//�L�[����C���f�b�N�X���v�Z ���L�[�͈̔͂��e�[�u���T�C�Y���傫���ꍇ
		};
		template <typename size_type, typename index_type, typename key_type, size_type TABLE_SIZE, key_type KEY_MIN, key_type KEY_RANGE>
		struct calcIndexImpl<true, size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE>{
			inline static index_type calc(const key_type key){ return (key - KEY_MIN) * (TABLE_SIZE / KEY_RANGE) % TABLE_SIZE; }//�L�[����C���f�b�N�X���v�Z ���L�[�͈̔͂��e�[�u���T�C�Y�ȉ��̏ꍇ
		};
	public:
		//�萔
		static const key_type KEY_RANGE = calcKeyRangeImpl<((KEY_MIN == 0u && KEY_MAX == 0xffffffffu) || KEY_MIN >= KEY_MAX), size_type, key_type, KEY_MIN, KEY_MAX>::value;//�L�[�͈̔�
		//�ÓI�A�T�[�V����
		static_assert(TABLE_SIZE > INDEX_STEP_BASE, "hash_table::container: TABLE_SIZE is required larger than INDEX_STEP_BASE.");
		static_assert(isPrimeMeta<INDEX_STEP_BASE>::value == true, "hash_table::container: INDEX_STEP_BASE is required prime.");
	public:
		//--------------------
		//�C�e���[�^�p�̌^
		struct set
		{
			//�t�B�[���h
			index_type m_index;//�i���ۂ́j�C���f�b�N�X
			index_type m_primaryIndex;//�{���̃C���f�b�N�X
			key_type m_key;//���݂̃L�[
			value_type* m_value;//���݂̒l
			bool m_isDeleted;//�폜�ς�

			//�I�y���[�^
			inline const value_type& operator*() const { return m_value; }
			inline value_type& operator*(){ return m_value; }
			inline const value_type* operator->() const { return m_value; }
			inline value_type* operator->(){ return m_value; }

			//���\�b�h
			inline bool isPrimaryIndex() const { return m_index == m_primaryIndex; }//���ۂ̃C���f�b�N�X�́A�{���̃C���f�b�N�X�ƈ�v���邩�H
			void update(const index_type index, const index_type primary_index, const key_type key, const value_type* value, const bool is_deleted)
			{
				m_index = index;
				m_primaryIndex = primary_index;
				m_key = key;
				m_value = const_cast<value_type*>(value);
				m_isDeleted = is_deleted;
			}

			//�R�X�g���N�^
			set(const index_type index, const index_type primary_index, const key_type key, const value_type* value, const bool is_deleted) :
				m_index(index),
				m_primaryIndex(primary_index),
				m_key(key),
				m_value(const_cast<value_type*>(value)),
				m_isDeleted(is_deleted)
			{}
		};
	public:
		//--------------------
		//�C�e���[�^
		class iterator;
		typedef const iterator const_iterator;
		class iterator : public std::iterator<std::forward_iterator_tag, value_type>
		{
			friend class container;
		public:
			//�L���X�g�I�y���[�^
			inline operator const set() const { return *m_set; }
			inline operator set&(){ return *m_set; }
			inline operator const value_type() const { return *m_set.m_value; }
			inline operator value_type&(){ return *m_set.m_value; }
			inline operator const value_type*() const { return m_set.m_value; }
			inline operator value_type*(){ return m_set.m_value; }
			inline operator key_type() const { return m_set.m_key; }
		public:
			//�I�y���[�^
			inline const set& operator*() const { return m_set; }
			inline set& operator*(){ return m_set; }
			inline const value_type* operator->() const { return m_set.value; }
			inline value_type* operator->(){ return m_set.value; }
			//��r�I�y���[�^
			inline bool operator==(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX && rhs.m_set.m_index == INVALID_INDEX ? true :
				       m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index == rhs.m_set.index;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX && rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? true :
				       m_set.m_index != rhs.m_set.m_index;
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index > rhs.m_set.m_index;
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index >= rhs.m_set.m_index;
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index < rhs.m_set.m_index;
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index <= rhs.m_set.m_index;
			}
			//���Z�I�y���[�^
			inline const_iterator& operator++() const
			{
				updateSet(m_con.getNextIndex(m_set.m_index));
				return *this;
			}
			inline const_iterator& operator--() const
			{
				updateSet(m_con.getPrevIndex(m_set.m_index));
				return *this;
			}
			inline iterator& operator++()
			{
				updateSet(m_con.getNextIndex(m_set.m_index));
				return *this;
			}
			inline iterator& operator--()
			{
				updateSet(m_con.getPrevIndex(m_set.m_index));
				return *this;
			}
			const_iterator operator++(int) const
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			const_iterator& operator+=(const int val) const
			{
				for (int i = 0; i < val; ++i)
					++(*this);
				return *this;
			}
			const_iterator& operator-=(const int val) const
			{
				for (int i = 0; i < val; ++i)
					--(*this);
				return *this;
			}
			iterator& operator+=(const int val)
			{
				for (int i = 0; i < val; ++i)
					++(*this);
				return *this;
			}
			iterator& operator-=(const int val)
			{
				for (int i = 0; i < val; ++i)
					--(*this);
				return *this;
			}
			const_iterator operator+(const int val) const
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			const_iterator operator-(const int val) const
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
			iterator operator+(const int val)
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			iterator operator-(const int val)
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
		public:
			//���[�u�I�y���[�^
			iterator& operator=(const_iterator&& rhs)
			{
				m_set = rhs.m_set;
				return *this;
			}
			//�R�s�[�I�y���[�^
			inline iterator& operator=(const_iterator& rhs)
			{
				return operator=(std::move(rhs));
			}
		public:
			//�A�N�Z�b�T
			inline index_type getIndex() const { return m_set.m_index; }//�i���ۂ́j�C���f�b�N�X
			inline index_type getPrimaryIndex() const { return m_set.m_primaryIndex; }//�{���̃C���f�b�N�X
			inline key_type getKey() const { return m_set.m_key; }//���݂̃L�[
			inline const value_type* getValue() const { return m_set.m_value; }//���݂̒l
			inline value_type* getValue(){ return m_set.m_value; }//���݂̒l
			inline bool isDeleted() const { return m_set.m_isDeleted; }//�폜�ς�
			inline bool isPrimaryIndex() const { return m_set.isPrimaryIndex(); }//�{���̃C���f�b�N�X���H
		private:
			//���\�b�h
			void updateSet(const index_type index) const
			{
				if (index == INVALID_INDEX)
					m_set.update(INVALID_INDEX, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
				else
					m_set.update(index, m_con.calcIndex(m_con.m_keyTable[index]), m_con.m_keyTable[index], reinterpret_cast<const value_type*>(m_con.m_table[index]), m_con.m_deleted[index]);
			}
		public:
			//���[�u�R���X�g���N�^
			iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_set(obj.m_set)
			{}
			//�R�s�[�R���X�g���N�^
			inline iterator(const_iterator& obj) :
				iterator(std::move(obj))
			{}
			//�R���X�g���N�^
			iterator(const container& con) :
				m_con(con),
				m_set(0, nullptr, false)
			{}
			iterator(const container& con, const index_type index, const key_type key, const value_type* value, const bool is_deleted) :
				m_con(con),
				m_set(index, con.calcIndex(key), key, value, is_deleted)
			{}
			//�f�X�g���N�^
			inline ~iterator()
			{}
		protected:
			//�t�B�[���h
			const container& m_con;//�R���e�i
			mutable set m_set;//���݂̃L�[/�l/�폜�ς݃t���O
		};
	public:
		//�A�N�Z�b�T
		inline replace_attr_t getReplaceAttr() const { return m_replaceAttr; }//�u���������擾
		inline auto_lock_attr_t getAutoLockAttr() const { return m_autoLockAttr; }//�������b�N�������擾
		inline size_type getOriginalTableSize() const { return ORIGINAL_TABLE_SIZE; }//�w�肳�ꂽ�e�[�u���T�C�Y���擾
		inline size_type getTableSize() const { return TABLE_SIZE; }//�i���ۂ́j�e�[�u���T�C�Y���擾
		inline size_type getTableSizeExtended() const { return TABLE_SIZE_EXTENDED; }//�w��̃e�[�u���T�C�Y����̑������擾
		inline size_type getAutoRehashRatio() const { return AUTO_REHASH_RATIO; }//�������n�b�V�����s�̊����
		inline size_type getAutoRehashSize() const { return AUTO_REHASH_SIZE; }//�������n�b�V�����s�̊�T�C�Y
		inline int getFindingCycleLimit() const { return FINDING_CYCLE_LIMIT; }//�������̏���񐔂̐������擾
		inline key_type getKeyMin() const { return KEY_MIN; }//�L�[�̍ŏ��l���擾
		inline key_type getKeyMax() const { return KEY_MAX; }//�L�[�̍ő�l���擾
		inline key_type getKeyRange() const { return KEY_RANGE; }//�L�[�͈̔͂��擾
		inline index_type getIndexStepBase() const { return INDEX_STEP_BASE; }//�������񎞂̃C���f�b�N�X�̕����̊�l�i���ۂ̃X�e�b�v���́A���̒l���W���ɃL�[����Z�o����j
		inline int getUsingCount() const { return m_usingCount; }//�g�p���f�[�^�����擾
		inline int getDeletedCount() const { return m_deletedCount; }//�폜�ς݃f�[�^�����擾
		inline int getMaxFindingCycle() const { return m_maxFindingCycle; }//�������̍ő叄��񐔂��擾
		int getNotOptimizedCount() const//�œK������Ă��Ȃ��f�[�^�������擾 �������̍ۂ�2��ȏ�̏��񂪕K�v�ȃf�[�^ = �{���̃C���f�b�N�X�Ǝ��ۂ̃C���f�b�N�X���قȂ�f�[�^
		{
			int count = 0;
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || m_deleted[index])
					continue;
				if (index != calcIndex(m_keyTable[index]))
					++count;
			}
			return count;
		}
	public:
		inline size_type max_size() const { return TABLE_SIZE; }//�ő�v�f�����擾
		//inline size_type capacity() const { return TABLE_SIZE; }//�ő�v�f�����擾
		inline bool empty() const { return size() == 0; }//�󂩁H
		inline size_type bucket_count() const { return TABLE_SIZE; }//�ő�v�f�����擾
		inline size_type max_bucket_count() const { return TABLE_SIZE; }//�ő�v�f�����擾
		inline size_type size() const { return m_usingCount - m_deletedCount; }//�g�p���̗v�f�����擾
		inline size_type bucket(const key_type key) const { return findIndex(key); }//�L�[�ɑΉ�����C���f�b�N�X���擾
		inline size_type bucket(const char* key) const { return findIndex(key); }//�L�[�ɑΉ�����C���f�b�N�X���擾
		inline size_type bucket(const std::string key) const { return findIndex(key); }//�L�[�ɑΉ�����C���f�b�N�X���擾
		inline size_type bucket(const value_type& value) const { return findIndex(value); }//�L�[�ɑΉ�����C���f�b�N�X���擾
		inline size_type bucket_size(const index_type index) const { return m_using[index] && !m_deleted[index] ? 1 : 0; }//����o�P�b�g���̗v�f�����擾
	public:
		//�����n�A�N�Z�b�T�F�L�[�Ō������Ēl��Ԃ�
		//���}���`�X���b�h�ŏ�������ۂ́A��A�̏����u���b�N�S�̂̑O���
		//�@���[�h���b�N�̎擾���s���悤�ɂ��邱�ƁB
		value_type* at(const key_type key){ return findValue(key); }
		value_type* at(const char* key){ return findValue(key); }
		value_type* at(const std::string& key){ return findValue(key); }
		value_type* at(const value_type& value){ return findValue(value); }
		const value_type* at(const key_type key) const { return findValue(key); }
		const value_type* at(const char* key) const { return findValue(key); }
		const value_type* at(const std::string& key) const { return findValue(key); }
		const value_type* at(const value_type& value) const { return findValue(value); }
		value_type* operator[](const key_type key){ return findValue(key); }
		value_type* operator[](const char* key){ return findValue(key); }
		value_type* operator[](const std::string& key){ return findValue(key); }
		value_type* operator[](const value_type& value){ return findValue(value); }
		const value_type* operator[](const key_type key) const { return findValue(key); }
		const value_type* operator[](const char* key) const { return findValue(key); }
		const value_type* operator[](const std::string& key) const { return findValue(key); }
		const value_type* operator[](const value_type& value) const { return findValue(value); }
	public:
		//�L���X�g�I�y���[�^
		operator CRWLock&(){ return m_lock; }//���[�h�E���C�g���b�N
		//�y���b�N�̎g�p���@�z
		//{
		//    CRWLock::RLock lock(container);//�����Ƀn�b�V���e�[�u���R���e�i��n�����ƂŁA���[�h���b�N���擾
		//    //�����̏����u���b�N�𔲂���Ǝ����I�Ƀ��b�N���
		//    data_t* obj = container[key];//�f�[�^�A�N�Z�X
		//}
		//�����C�g���b�N�����l�̕��@�Ŗ����I�Ƀ��b�N�ł��邪�A
		//�@�R���e�i�������ɃR���X�g���N�^�����Ŏ������b�N�������w�肷������ǂ��B
	public:
		//���\�b�h
		inline index_type calcIndexStep(const key_type key) const { return INDEX_STEP_BASE - key % INDEX_STEP_BASE; }//�L�[����C���f�b�N�X�̕����i���n�b�V���j���v�Z
		inline index_type calcIndex(const key_type key) const { return calcIndexImpl<(TABLE_SIZE >= KEY_RANGE && KEY_RANGE > 0), size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE >::calc(key); }//�L�[����C���f�b�N�X�i���n�b�V���j���v�Z
		inline index_type calcNextIndex(const key_type key, const index_type index) const { return (index + calcIndexStep(key)) % TABLE_SIZE; }//���̃C���f�b�N�X���v�Z�i�w��̃C���f�b�N�X�ɕ��������Z�j
	public:
		//�C���f�b�N�X���擾
		//���}���`�X���b�h�ŏ�������ۂ́A��A�̏����u���b�N�S�̂̑O���
		//�@���[�h���b�N�̎擾���s���悤�ɂ��邱�ƁB
		index_type getFirstIndex() const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (m_using[index])
					return index;
			}
			return INVALID_INDEX;
		}
		index_type getLastIndex() const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (index_type index = TABLE_SIZE; index > 0; --index)
			{
				if (m_using[index - 1])
					return index - 1;
			}
			return INVALID_INDEX;
		}
		index_type getNextIndex(const index_type index) const
		{
			index_type next_index = index == INVALID_INDEX ? 0 : index + 1;
			if (index < 0 || index >= TABLE_SIZE - 1 || m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (; next_index < TABLE_SIZE; ++next_index)
			{
				if (m_using[next_index])
					return next_index;
			}
			return INVALID_INDEX;
		}
		index_type getPrevIndex(const index_type index) const
		{
			index_type now_index = index == INVALID_INDEX ? TABLE_SIZE : index;
			if (index <= 0 || index >= TABLE_SIZE || m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (; now_index > 0; --now_index)
			{
				if (m_using[now_index - 1])
					return now_index - 1;
			}
			return INVALID_INDEX;
		}
		//�C�e���[�^���擾
		//���}���`�X���b�h�ŏ�������ۂ́A��A�̏����u���b�N�S�̂̑O���
		//�@���[�h���b�N�̎擾���s���悤�ɂ��邱�ƁB
		inline const_iterator begin() const
		{
			const index_type index = getFirstIndex();//�擪�C���f�b�N�X���擾
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, index, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator end() const
		{
			return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
		}
		inline iterator begin(){ return const_cast<const container*>(this)->begin(); }
		inline iterator end(){ return const_cast<const container*>(this)->end(); }
		inline const_iterator cbegin() const { return this->begin(); }
		inline const_iterator cend() const { return this->end(); }
	private:
		//�L�[�Ō������ăC���f�b�N�X���擾�i�{�́j
		index_type _findIndex(const key_type key) const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			const index_type index_first = calcIndex(key);//�L�[����C���f�b�N�X�i�n�b�V���j���v�Z
			index_type index = index_first;
			do
			{
				if (!m_using[index])//���g�p�C���f�b�N�X�Ȃ猟�����s
					break;
				if (!m_deleted[index] && m_keyTable[index] == key)//�L�[����v����C���f�b�N�X�Ȃ猟������
					return index;
				index = calcNextIndex(key, index);//���̃C���f�b�N�X��
			} while (index != index_first);//�ŏ��̃C���f�b�N�X�ɖ߂�����I���i�������s�j
			return INVALID_INDEX;
		}
		//�L�[�Ō������ăC���f�b�N�X���擾
		//���}���`�X���b�h�ŏ�������ۂ́A��A�̏����u���b�N�S�̂̑O���
		//�@���[�h���b�N�̎擾���s���悤�ɂ��邱�ƁB
		inline index_type findIndex(const key_type key) const{ return _findIndex(key); }
		inline index_type findIndex(const char* key) const{ return _findIndex(calcCRC32(key)); }
		inline index_type findIndex(const std::string& key) const{ return _findIndex(key.c_str()); }
		inline index_type findIndex(const value_type& value) const{ return _findIndex(ope_type::getKey(value)); }
	private:
		//�L�[�Ō������Ēl���擾�i�{�́j
		inline const value_type* _findValue(const key_type key) const
		{
			const index_type index = findIndex(key);//�������ăC���f�b�N�X���擾
			if (index == INVALID_INDEX)
				return nullptr;
			return reinterpret_cast<const value_type*>(&m_table[index]);
		}
	public:
		//�L�[�Ō������Ēl���擾
		//���}���`�X���b�h�ŏ�������ۂ́A��A�̏����u���b�N�S�̂̑O���
		//�@���[�h���b�N�̎擾���s���悤�ɂ��邱�ƁB
		inline const value_type* findValue(const key_type key) const { return _findValue(key); }
		inline const value_type* findValue(const char* key) const { return _findValue(calcCRC32(key)); }
		inline const value_type* findValue(const std::string& key) const { return _findValue(key.c_str()); }
		inline const value_type* findValue(const value_type& value) const { return _findValue(ope_type::getKey(value)); }
		inline value_type* findValue(const key_type key){ return const_cast<value_type*>(_findValue(key)); }
		inline value_type* findValue(const char* key){ return const_cast<value_type*>(_findValue(calcCRC32(key))); }
		inline value_type* findValue(const std::string& key){ return const_cast<value_type*>(_findValue(key.c_str())); }
		inline value_type* findValue(const value_type& value){ return const_cast<value_type*>(_findValue(ope_type::getKey(value))); }
		//�L�[�Ō������ăC�e���[�^���擾
		//���}���`�X���b�h�ŏ�������ۂ́A��A�̏����u���b�N�S�̂̑O���
		//�@���[�h���b�N�̎擾���s���悤�ɂ��邱�ƁB
		const_iterator find(const key_type key) const
		{
			const index_type index = findIndex(key);
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, index, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator find(const char* key) const { return find(calcCRC32(key)); }
		inline const_iterator find(const std::string& key) const { return find(key.c_str()); }
		inline const_iterator find(const value_type& value) const { return find(ope_type::getKey(value)); }
		inline iterator find(const key_type key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const char* key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const std::string& key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const value_type value){ return const_cast<const container*>(this)->find(value); }
	private:
		//�L�[���蓖�āi�{�́j
		//�����蓖�Ă��z��v�f�i�f�[�^�e�[�u���j�̃|�C���^��Ԃ�
		value_type* _assign(const key_type key)
		{
			if (m_usingCount == TABLE_SIZE && m_deletedCount == 0)
				return nullptr;
			index_type index = _findIndex(key);
			if (m_replaceAttr == NEVER_REPLACE && index != INVALID_INDEX)//�����L�[�����Ɋ��蓖�čς݂Ȃ犄�蓖�Ď��s
				return nullptr;
			int find_cycle = 0;
			if (index != INVALID_INDEX)
			{
				//�u��
				_eraseByIndex(index);//�f�X�g���N�^�̌Ăяo������
			}
			else
			{
				//�V�K�o�^
				const index_type index_first = calcIndex(key);//�L�[����C���f�b�N�X�i�n�b�V���j���v�Z
				index = index_first;
				do
				{
					++find_cycle;
					if (!m_using[index] || m_deleted[index])//���g�p�^�폜�ς݃C���f�b�N�X�Ȃ犄�蓖�Đ���
						break;
					if (FINDING_CYCLE_LIMIT > 0 && find_cycle == FINDING_CYCLE_LIMIT)//����񐔂������ɒB�����犄�蓖�Ď��s
						return nullptr;
					index = calcNextIndex(key, index);//���̃C���f�b�N�X��
				} while (index != index_first);//�ŏ��̃C���f�b�N�X�ɖ߂�����I���i���蓖�Ď��s�j
			}
			m_keyTable[index] = key;//�L�[�e�[�u���ɃL�[�o�^
			if (!m_using[index])//���g�p�C���f�b�N�X�̊��蓖�ĂȂ�g�p�����𒲐�
			{
				m_using[index] = true;//�g�p���t���O���Z�b�g
				++m_usingCount;//�g�p�������J�E���g�A�b�v
			}
			if (m_deleted[index])//�폜�ς݃C���f�b�N�X�̍Ċ��蓖�ĂȂ�폜���𒲐�
			{
				m_deleted[index] = false;//�폜�ς݃t���O�����Z�b�g
				--m_deletedCount;//�폜�ςݐ����J�E���g�_�E��
			}
			m_maxFindingCycle = m_maxFindingCycle >= find_cycle ? m_maxFindingCycle : find_cycle;//�ő叄��񐔂��X�V
			return reinterpret_cast<value_type*>(&m_table[index]);
		}
	public:
		//�L�[���蓖��
		//�����蓖�Ă��z��v�f�i�f�[�^�e�[�u���j�̃|�C���^��Ԃ�
		//���������A���C�g���b�N���擾����i�������C�g���b�N�����ݒ莞�j
		inline value_type* assign(const key_type key)
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//���C�g���b�N
				return _assign(key);
			}
			return _assign(key);
		}
		inline value_type* assign(const char* key){ return assign(calcCRC32(key)); }
		inline value_type* assign(const std::string& key){ return assign(key.c_str()); }
		inline value_type* assign(const value_type& value){ return assign(ope_type::getKey(value)); }
	private:
		//�L�[���蓖�Ă��Ēl��}���i�R�s�[�j�i�{�́j
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ���
		value_type* _insert(const key_type key, const value_type& value)
		{
			value_type* assigned_value = _assign(key);
			if (!assigned_value)
				return nullptr;
			*assigned_value = value;
			return assigned_value;
		}
	public:
		//�L�[���蓖�Ă��Ēl��}���i�R�s�[�j
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ���
		//���������A���C�g���b�N���擾����i�������C�g���b�N�����ݒ莞�j
		inline value_type* insert(const key_type key, const value_type& value)
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//���C�g���b�N
				return _insert(key, value);
			}
			return _insert(key, value);
		}
		inline value_type* insert(const char* key, const value_type& value){ return insert(calcCRC32(key), value); }
		inline value_type* insert(const std::string& key, const value_type& value){ return insert(key.c_str(), value); }
		//�l��}���i�R�s�[�j���A�L�[�͎������蓖��
		//������p�N���X base_ope_t �̔h���N���X�ŁAgetKey() ����������K�v����
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ���
		inline value_type* insertAuto(const value_type& value){ return insert(ope_type::getKey(value), value); }
	private:
		//�L�[���蓖�Ă��Ēl���������i�{�́j
		//���R���X�g���N�^���Ăяo�����
		template<typename... Tx>
		value_type* _emplace(const key_type key, Tx... args)//const Tx&... args �Ƃ�������
		{
			value_type* assigned_value = _assign(key);
			if (!assigned_value)
				return nullptr;
			assigned_value = new(assigned_value) value_type(args...);//�R���X�g���N�^�Ăяo��
			return assigned_value;
		}
	public:
		//�L�[���蓖�Ă��Ēl��������
		//���R���X�g���N�^���Ăяo�����
		//���������A���C�g���b�N���擾����i�������C�g���b�N�����ݒ莞�j
		template<typename... Tx>
		inline value_type* emplace(const key_type key, Tx... args)//const Tx&... args �Ƃ�������
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//���C�g���b�N
				return _emplace(key, args...);
			}
			return _emplace(key, args...);
		}
		template<typename... Tx>
		inline value_type* emplace(const char* key, Tx... args){ return emplace(calcCRC32(key), args...); }
		template<typename... Tx>
		inline value_type* emplace(const std::string& key, Tx... args){ return emplace(key.c_str(), args...); }
		//�l�����������Ď����I�ɃL�[���蓖��
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ���
		//������p�N���X base_ope_t �̔h���N���X�ŁAgetKey() ����������K�v����
		//���������A���C�g���b�N���擾����
		template<typename... Tx>
		inline value_type* emplaceAuto(Tx... args)
		{
			value_type value(args...);
			return insertAuto(value);
		}
	private:
		//�C���f�b�N�X���w�肵�č폜
		void _eraseByIndex(const index_type index)
		{
			value_type* data_p = reinterpret_cast<value_type*>(&m_table[index]);
			ope_type::callDestructor(data_p);//�f�X�g���N�^�Ăяo��
			operator delete(data_p, data_p);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			m_deleted[index] = true;//�폜�ς݃C���f�b�N�X���X�V
			++m_deletedCount;//�폜�ςݐ����J�E���g�A�b�v
		}
		//�L�[���폜�i�{�́j
		bool _erase(const key_type key)
		{
			const index_type index = findIndex(key);//�������ăC���f�b�N�X���擾
			if (index == INVALID_INDEX)//�������s�Ȃ�폜���s
				return false;
			_eraseByIndex(index);
			if (m_usingCount == m_deletedCount || m_deletedCount == AUTO_REHASH_SIZE)//�������n�b�V��
				_rehash();
			return true;
		}
	public:
		//�L�[���폜
		//���������A���C�g���b�N���擾����i�������C�g���b�N�����ݒ莞�j
		inline bool erase(const key_type key)
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//���C�g���b�N
				return _erase(key);
			}
			return _erase(key);
		}
		inline bool erase(const char* key){ return erase(calcCRC32(key)); }
		inline bool erase(const std::string& key){ return erase(key.c_str()); }
		//�L�[���폜
		//������p�N���X base_ope_t �̔h���N���X�ŁAgetKey() ����������K�v����
		inline bool eraseAuto(const value_type& value){ return erase(ope_type::getKey(value)); }
	private:
		//���n�b�V���i�{�́j
		bool _rehash()
		{
			if (m_usingCount == 0 || m_deletedCount == 0)
				return false;
			if (m_usingCount == m_deletedCount)
			{
				_clear();
				return true;
			}
			m_maxFindingCycle = 1;//�ő叄��񐔂�1�Ƀ��Z�b�g
			//�l�̈ړ�
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || m_deleted[index])//���g�p�C���f�b�N�X�܂��͍폜�ς݃C���f�b�N�X�͏������X�L�b�v
					continue;
				const key_type key = m_keyTable[index];//�L�[���擾
				if (calcIndex(key) == index)//�L�[���{���̃C���f�b�N�X�ƈقȂ�ꍇ�A�ړ������݂�
					continue;
				value_type* value = reinterpret_cast<value_type*>(m_table[index]);//���݂̒l���L��
				m_deleted[index] = true;//��U�폜�ς݂ɂ���
				++m_deletedCount;       //�i����j
				value_type* value_new = _assign(key);//���߂ăL�[�����蓖��
				if (value_new != value)//�C���f�b�N�X������Ă����Ȃ�l���ړ�
				{
				#if 1
					*value_new = std::move(*value);//���[�u���Z�q�ňړ�
				#else
					memcpy(value_new, value, sizeof(value_type));//memcpy�ňړ�
				#endif
				}
			}
			//�폜�ς݃C���f�b�N�X�̃N���A
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || !m_deleted[index])//���g�p�C���f�b�N�X�܂��͖��폜�C���f�b�N�X�͏������X�L�b�v
					continue;
				m_deleted[index] = false;//�폜�ς݂���������
				--m_deletedCount;       //�i����j
				m_using[index] = false;//�g�p������������
				--m_usingCount;        //�i����j
			}
			return true;
		}
	public:
		//���n�b�V��
		//���e�[�u�����g��E�č\�z����̂ł͂Ȃ��A�폜�ς݃f�[�^�����S�ɍ폜���邾���B
		//�@���̂��߂ɁA�폜�ς݃f�[�^�̈ʒu�Ɉړ��\�ȃf�[�^���ړ�����B
		//���������A���C�g���b�N���擾����i�������C�g���b�N�����ݒ莞�j
		inline bool rehash()
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//���C�g���b�N
				return _rehash();
			}
			return _rehash();
		}
	private:
		//�N���A�i�{�́j
		void _clear()
		{
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (m_using[index] && !m_deleted[index])//�g�p���f�[�^�̓f�X�g���N�^�Ăяo��
					_eraseByIndex(index);
			}
			m_using.reset();
			m_deleted.reset();
			m_usingCount = 0;
			m_deletedCount = 0;
			m_maxFindingCycle = 0;
		}
	public:
		//�N���A
		//���������A���C�g���b�N���擾����
		inline void clear()
		{
			CRWLock::WLock lock(m_lock);//���C�g���b�N
			_clear();
		}
	public:
		//�R���X�g���N�^
		container(const replace_attr_t replace_attr = NEVER_REPLACE, const auto_lock_attr_t auto_lock_attr = NEVER_LOCK, const CRWLock::E_WLOCK_PRIORITY wlock_prioritized = CRWLock::WLOCK_PRIORITIZED) :
			m_using(),
			m_deleted(),
			m_usingCount(0),
			m_deletedCount(0),
			m_maxFindingCycle(0),
			m_replaceAttr(replace_attr),
			m_autoLockAttr(auto_lock_attr),
			m_lock(wlock_prioritized)
		{}
		//�f�X�g���N�^
		~container()
		{}
	private:
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//�f�[�^�e�[�u���i�o�P�b�g�j
		key_type m_keyTable[TABLE_SIZE];//�L�[�e�[�u��
		std::bitset<TABLE_SIZE> m_using;//�L�[�ݒ�ς݃t���O ���o�^���폜���Ă�false�ɂȂ�Ȃ��i���n�b�V�����ɂ͒��������j
		std::bitset<TABLE_SIZE> m_deleted;//�폜�ς݃t���O
		int m_usingCount;//�g�p���f�[�^�� ���o�^���폜���Ă�����Ȃ��i���n�b�V�����ɂ͒��������j
		int m_deletedCount;//�폜�ς݃f�[�^��
		int m_maxFindingCycle;//�������̍ő叄��� ���o�^���폜���Ă�����Ȃ��i���n�b�V�����ɂ͒��������j
		replace_attr_t m_replaceAttr;//�f�[�^�u������
		auto_lock_attr_t m_autoLockAttr;//�������b�N����
		CRWLock m_lock;//���[�h�E���C�g���b�N
	};
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace hash_table

//--------------------------------------------------------------------------------
//�n�b�V���e�[�u�����f���v�Z�e�X�g
//--------------------------------------------------------------------------------

#include <chrono>//C++11 ���Ԍv���p
#include <unordered_map>//C++11 std::unordered_map
#include <map>//C++11 std::map
#include <string.h>//strcpy�p

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
//�����񑀍�֐�
#ifdef USE_GCC
inline char* strcpy_s(char* dst, const std::size_t size, const char* src)
{
	return strcpy(dst, src);
}
inline char* strncpy_s(char* dst, const std::size_t size, const char* src, const std::size_t max)
{
	return strncpy(dst, src, max);
}
template<typename... Tx>
inline int sprintf_s(char* dst, const std::size_t size, const char* fmt, Tx... args)
{
	return sprintf(dst, fmt, args...);
}
#endif//USE_GCC

//----------------------------------------
//�f���v�Z�e�X�g

//�y�����^�C���Łz�f���\��
void printPrime(const std::size_t min, const std::size_t max)
{
	if (max > min)
		printPrime(min, max - 1);
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", max, isPrime(max) ? "PRIME.    " : "not prime.", makePrimePrev(max), makePrimeEqPrev(max), makePrimeNext(max), makePrimeEqNext(max));
}

//�y���^�v���O���~���O�Łz�f���\��
template<std::size_t N>
void _printPrimeCommon()
{
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", N, isPrimeMeta<N>::value ? "PRIME.    " : "not prime.", makePrimePrevMeta<N>::value, makePrimeEqPrevMeta<N>::value, makePrimeNextMeta<N>::value, makePrimeEqNextMeta<N>::value);
}
template<std::size_t MIN, std::size_t MAX>
struct printPrimeMeta{
	void operator()()
	{
		printPrimeMeta<MIN, MAX - 1>()();
		_printPrimeCommon<MAX>();
	}
};
template<std::size_t MIN>
struct printPrimeMeta<MIN, MIN>{
	void operator()()
	{
		_printPrimeCommon<MIN>();
	}
};

//----------------------------------------
//�n�b�V���e�[�u���p�e�X�g�f�[�^
struct data_t
{
	crc32_t m_key;//�L�[ �����O�̃n�b�V���l
	int m_value;//�l
	char m_name[20];//���O

	//�R���X�g���N�^
	data_t(const char* name, const int value) :
		m_key(calcCRC32(name)),
		m_value(value)
	{
		strncpy_s(m_name, sizeof(m_name), name, sizeof(m_name) - 1);
		m_name[sizeof(m_name)-1] = '\0';
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(\"%s\", value)\n", name, value);
		//printf("    m_key=%d, m_name=[%s], m_value=%d\n", m_key, m_name, m_value);
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
	//�f�t�H���g�R���X�g���N�^
	data_t():
		m_key(0),
		m_value(0)
	{
		m_name[0] = '\0';
		printf("data_t::constructor\n");
	}
	//�f�X�g���N�^
	~data_t()
	{
		printf("data_t::destructor\n");
		//printf("  m_key=%d, m_name=[%s]\n", m_key, m_name);
	}
#endif//TEST_DATA_WATCH_CONSTRUCTOR
};

//----------------------------------------
//�e�X�g�f�[�^����N���X
#include <functional>//C++11 std::function�p
struct ope_t : public hash_table::base_ope_t<ope_t, crc32_t, data_t>
{
	//�L�[���擾
	inline static key_type getKey(const value_type& value){ return value.m_key; }
};

//----------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//���Ԍv��
	auto begin_time = std::chrono::system_clock::now();
	auto prev_time = begin_time;

	//�������Ԍv��
	auto calcElapsedTime = [](const std::chrono::system_clock::time_point& now_time, const std::chrono::system_clock::time_point& prev_time) -> double
	{
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - prev_time);
		const auto elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		return elapsed_time;
	};
	auto getElapsedTime = [&calcElapsedTime](const std::chrono::system_clock::time_point& prev_time) -> double
	{
		return calcElapsedTime(std::chrono::system_clock::now(), prev_time);
	};

	//�������ԕ\��
	auto printElapsedTimeDirect = [&calcElapsedTime](const double elapsed_time, const bool is_preint) -> std::chrono::system_clock::time_point
	{
		if (is_preint)
			printf("*elapsed time=%.9llf sec.\n", elapsed_time);
		return std::chrono::system_clock::now();
	};
	auto printElapsedTime = [&calcElapsedTime, &printElapsedTimeDirect](const std::chrono::system_clock::time_point& prev_time, const bool is_print) -> std::chrono::system_clock::time_point
	{
		const auto now_time = std::chrono::system_clock::now();
		const auto elapsed_time = calcElapsedTime(now_time, prev_time);
		return printElapsedTimeDirect(elapsed_time, is_print);
	};

#if 0
	//--------------------
	//�f���R���p�C�����v�Z�̍ċA���x�����E�`�F�b�N
	static const std::size_t x = 9999;
	printf("x=%d\n", x);
	printf("  isPrime=%s\n", isPrimeMeta<x>::value ? "true" : "False");
	printf("  prev=%d\n", makePrimePrevMeta<x>::value);
	printf("  next=%d\n", makePrimeNextMeta<x>::value);
	printf("  equalPrev=%d\n", makePrimeEqPrevMeta<x>::value);
	printf("  equalNext=%d\n", makePrimeEqNextMeta<x>::value);
#endif

#if 0
	//--------------------
	//�f���v�Z�̃e�X�g
	static const std::size_t MIN = 1020;
	static const std::size_t MAX = 1030;
	
	printf("----- Check and Make Prime for Runtime -----\n");
	printPrime(MIN, MAX);
	
	printf("----- Check and Make Prime for Meta-Programming -----\n");
	printPrimeMeta<MIN, MAX>()();
#endif

#if 0
	//--------------------
	//�n�b�V���e�[�u���̃C���f�b�N�X�v�Z���W�b�N�e�X�g
	//���S�ẴC���f�b�N�X���A���m�Ƀe�[�u���T�C�Y�i�f���j��̍Čv�Z���s�����ŁA���̃C���f�b�N�X�ɖ߂邱�Ƃ��m�F�B
	{
		int ng_count = 0;
		const ope_t::key_type key_min = 0;// con.getKeyMin();
		const ope_t::key_type key_max = 100000;// con.getKeyMax();
		const ope_t::key_type key_step = 1;
		for (ope_t::key_type key = key_min; key <= key_max; key += key_step)
		{
			if (key % (1024 * 1024) == 0)
				printf("pass ... Key:%d\n", key);
			std::size_t count = 0;
			std::size_t first_index = con.calcIndex(key);
			std::size_t index = first_index;
			do
			{
				index = con.calcNextIndex(key, index);
				++count;
			} while (index != first_index && count < con.getTableSize());
			if (count != con.getTableSize())
			{
				printf("%u is OUT! (count=%d)\n", key, count);
				++ng_count;
			}
		}
		printf("Chek Hash Table: NG=%d/%d\n", ng_count, con.getTableSize());
		for (std::size_t key = 10; key <= 30; key += 1)
		{
			printf("Key:%u -> Index;%u\n", key, con.calcIndex(key));
		}
	}
#endif

#if 0
	//--------------------
	//�n�b�V���e�[�u���e�X�g�i���j
	{
		hash_table::container<ope_t, 20> con(hash_table::AUTO_WRITE_LOCK);
		
		data_t* result;
		printf("- emplace -\n");
		result = con.emplace(110, "123", 123);
		data_t* obj = con[110];
		obj->m_value = 1234567;
		result = con.emplace(220, "456", 456);
		result = con.emplace(330, "789", 789);
		result = con.emplace(110, "123", 123);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".size()=%d\n", con.size());
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- erase -\n");
		con.erase(220);
		con.erase(330);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- emplace -\n");
		result = con.emplace(220, "456!", 4567);
		result = con.emplace("123", "123!!", 12345);
		result = con.emplaceAuto("456!!", 45679);
		result = con.emplace("789", "789!!", 78901);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- erase -\n");
		con.erase(220);
		con.erase(110);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- rehash -\n");
		con.rehash();
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
	}
#endif
	
	//--------------------
	//�n�b�V���e�[�u���e�X�g
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("Hash Table Test\n");
	printf("--------------------------------------------------------------------------------\n");
	typedef hash_table::container<ope_t, TEST_DATA_TABLE_SIZE, 0, 0> container_type;//�������n�b�V���Ȃ�, ��������񐔐����Ȃ�
	container_type* con = new container_type(hash_table::NEVER_REPLACE, hash_table::NEVER_LOCK);//�u���Ȃ��A�������b�N�Ȃ�

	//�n�b�V���e�[�u���̊�{���\��
	auto printTableParameter = [&con]()
	{
		printf("\n");
		printf("--- Table Parameter ---\n");
		printf(".max_size()=%u\n", con->max_size());
		//printf(".capacity()=%u\n", con->capacity());
		printf(".getOriginalTableSize()=%u\n", con->getOriginalTableSize());
		printf(".getTableSize()=%u\n", con->getTableSize());
		printf(".getTableSizeExtended()=%u\n", con->getTableSizeExtended());
		printf(".getAutoRehashRatio()=%u\n", con->getAutoRehashRatio());
		printf(".getAutoRehashSize()=%u\n", con->getAutoRehashSize());
		printf(".getFindingCycleLimit()=%u\n", con->getFindingCycleLimit());
		printf(".getKeyMin()=%u\n", con->getKeyMin());
		printf(".getKeyMax()=%u\n", con->getKeyMax());
		printf(".getKeyRange()=%u\n", con->getKeyRange());
		printf(".getReplaceAttr()=%u\n", con->getReplaceAttr());
		printf(".getAutoLockAttr()=%u\n", con->getAutoLockAttr());
	};
	printTableParameter();

	//�e�[�u����ԕ\��
	auto printTableStatus = [&con]()
	{
		printf("\n");
		printf("--- Table Status ---\n");
		printf(".bucket_count()=%u\n", con->bucket_count());
		printf(".max_bucket_count()=%u\n", con->max_bucket_count());
		printf(".size()=%u\n", con->size());
		printf(".empty()=%u\n", con->empty());
		printf(".getUsingCount()=%u\n", con->getUsingCount());
		printf(".getDeletedCount()=%u\n", con->getDeletedCount());
		printf(".getMaxFindingCycle()=%u\n", con->getMaxFindingCycle());
		printf(".getNotOptimizedCount()=%u\n", con->getNotOptimizedCount());
	};
	printTableStatus();

	//�n�b�V���e�[�u���ւ̃f�[�^�o�^
	auto insertData = [&con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- Insert Data ---\n");
		int insert_success = 0;
		int insert_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t* obj = nullptr;
			#define USE_INSERT_TYPE 1
			//�y�����z�y�o�^���@�@�zemplace()���\�b�h�ɃL�[�ƃR���X�g���N�^�p�����[�^��n���ēo�^������@
			//���I�u�W�F�N�g�̃R�s�[�͔������Ȃ�
			#if USE_INSERT_TYPE == 1
			{
				obj = con->emplace(calcCRC32(name), name, i);//�L�[�ƃR���X�g���N�^�p�����[�^��n���ēo�^
			}
			//�y�o�^���@�A�zemplaceAuto()���\�b�h�ɃR���X�g���N�^�p�����[�^��n���ēo�^������@
			//���I�u�W�F�N�g�̃R�s�[����������̂ŏ����x��
			#elif USE_INSERT_TYPE == 2
			{
				obj = con->emplaceAuto(name, i);//�R���X�g���N�^�p�����[�^��n���ēo�^
			}
			//�y�o�^���@�B�zinsert()���\�b�h�ɃL�[�ƃI�u�W�F�N�g��n���ēo�^������@
			//���I�u�W�F�N�g�̃R�s�[����������̂ŏ����x��
			//������p�N���X base_ope_t �̔h���N���X�ŁAgetKey() ����������K�v����
			#elif USE_INSERT_TYPE == 3
			{
				data_t new_obj(name, i);
				obj = con->insert(calcCRC32(name), new_obj);
			}
			//�y�o�^���@�C�zinsertAuto()���\�b�h�ɃI�u�W�F�N�g��n���ēo�^������@
			//���I�u�W�F�N�g�̃R�s�[����������̂ŏ����x��
			//������p�N���X base_ope_t �̔h���N���X�ŁAgetKey() ����������K�v����
			#elif USE_INSERT_TYPE == 4
			{
				data_t new_obj(name, i);
				obj = con->insertAuto(new_obj);
			}
			//�y�o�^���@�D�zassign()���\�b�h�Ńf�[�^�̃|�C���^���擾���A�����ɒl����������
			//���R���X�g���N�^�̂Ȃ��I�u�W�F�N�g�������ꍇ�ɗL��
			#elif USE_INSERT_TYPE == 5
			{
				const crc32_t key = calcCRC32(name);
				obj = con->assign(key);
				if(obj)
				{
					obj->m_key = key;
					strncpy_s(obj->m_name, sizeof(obj->m_name), name, sizeof(obj->m_name) - 1);
					obj->m_name[sizeof(obj->m_name) - 1] = '\0';
					obj->m_value = i;
				}
			}
			#endif//USE_INSERT_TYPE
			if (obj)
			{
				++insert_success;
				printf_detail("OK\n");
			}
			else
			{
				++insert_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", insert_success, insert_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	insertData(0, TEST_DATA_TABLE_SIZE / 2, 1);

	//�n�b�V���e�[�u����ԕ\��
	printTableStatus();

	//�n�b�V���e�[�u���\��
	auto printTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf_detail("\n");
		printf_detail("--- Print Table ---\n");
		//for (container_type::set& set : +con)
		for (auto& set : *con)
		{
			printf_detail("%c[%6d](%6d) key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)%s\n", set.isPrimaryIndex() ? ' ' : '*', set.m_index, set.m_primaryIndex, set.m_key, set->m_name, set->m_value, con->bucket(set.m_key), con->bucket_size(set.m_index), set.m_isDeleted ? " <DELETED>" : "");
		}
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	printTable();

	//�n�b�V���e�[�u���A�N�Z�X
	auto findTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Find Data ---\n");
		int find_success = 0;
		int find_failure = 0;
		for (int i = 0; i < TEST_DATA_TABLE_SIZE; ++i)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t* obj;
			crc32_t key;
			int index;
			int primary_index;
			bool is_primary_index;
			bool is_deleted;
			#define USE_FIND_TYPE 1
			//�y�����z�y�������@�@�z[]�I�y���[�^�ɃL�[��n���Č���������@
			//���l��Ԃ�
			#if USE_FIND_TYPE == 1
			{
				obj = (*con)[name];
				if(obj)
				{
					key = obj->m_key;
					index = con->bucket(key);
					primary_index = con->calcIndex(key);
					is_primary_index = (index == primary_index);
					is_deleted = false;
				}
			}
			//�y�������@�A�zat()���\�b�h�ɃL�[��n���Č���������@
			//���l��Ԃ��i[]�I�y���[�^�Ɠ����j
			#elif USE_FIND_TYPE == 2
			{
				obj = con->at(name);
				if(obj)
				{
					key = obj->m_key;
					index = con->bucket(key);
					primary_index = con->calcIndex(key);
					is_primary_index = (index == primary_index);
					is_deleted = false;
				}
			}
			//�y�������@�B�zfind()���\�b�h�ɃL�[��n���Č���������@
			//���C�e���[�^��Ԃ�
			#elif USE_FIND_TYPE == 3
			{
				container_type::iterator ite = con->find(name);
				obj = ite;
				if (obj)
				{
					key = ite.getKey();
					index = ite.getIndex();
					primary_index = ite.getPrimaryIndex();
					is_primary_index = ite.isPrimaryIndex();
					is_deleted = ite.isDeleted();
				}
			}
			#endif//USE_FIND_TYPE
			if (obj)
			{
				printf_detail("OK  %c[%6d](%6d) key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)%s\n", is_primary_index ? ' ' : '*', index, primary_index, key, obj->m_name, obj->m_value, con->bucket(key), con->bucket_size(index), is_deleted ? " <DELETED>" : "");
				++find_success;
			}
			else
			{
				printf_detail("NG\n");
				++find_failure;
			}
		}
		printf("success=%d, failure=%d\n", find_success, find_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	findTable();

	//�n�b�V���e�[�u������̃f�[�^�폜
	auto eraseData = [&con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- Erase Data ---\n");
		int erase_success = 0;
		int erase_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			bool result = false;
			#define USE_ERASE_TYPE 1
			//�y�����z�y�폜���@�@�zerase()���\�b�h�ɃL�[��n���č폜������@
			#if USE_ERASE_TYPE == 1
			{
				result = con->erase(calcCRC32(name));//�L�[��n���č폜
			}
			//�y�폜���@�A�zeraseAuto()���\�b�h�ɃI�u�W�F�N�g��n���č폜������@
			//������p�N���X base_ope_t �̔h���N���X�ŁAgetKey() ����������K�v����
			#elif USE_INSERT_TYPE == 2
			{
				data_t obj(name, i);
				result = con->eraseAuto(obj);//�I�u�W�F�N�g��n���č폜
			}
			#endif//USE_ERASETYPE
			if (result)
			{
				++erase_success;
				printf_detail("OK\n");
			}
			else
			{
				++erase_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", erase_success, erase_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	eraseData(0, TEST_DATA_TABLE_SIZE, 2);
	
	//�n�b�V���e�[�u����ԕ\��
	printTableStatus();

	//�n�b�V���e�[�u���\��
	printTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findTable();

	//�n�b�V���e�[�u���ւ̃f�[�^�o�^
	insertData(1, TEST_DATA_TABLE_SIZE, 2);

	//�n�b�V���e�[�u����ԕ\��
	printTableStatus();

	//�n�b�V���e�[�u���\��
	printTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findTable();

	//���n�b�V��
	auto rehashTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Rehash Table ---\n");
		con->rehash();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	rehashTable();

	//�n�b�V���e�[�u����ԕ\��
	printTableStatus();

	//�n�b�V���e�[�u���\��
	printTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findTable();

	//�N���A
	auto clearTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Clear Table ---\n");
		con->clear();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	clearTable();

	//�n�b�V���e�[�u����ԕ\��
	printTableStatus();

	//�n�b�V���e�[�u���\��
	printTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findTable();

	//�n�b�V���e�[�u���ւ̃f�[�^�o�^
	insertData(0, TEST_DATA_TABLE_SIZE, 1);

	//�n�b�V���e�[�u����ԕ\��
	printTableStatus();

	//�n�b�V���e�[�u���\��
	printTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findTable();

	//�n�b�V���e�[�u������̃f�[�^�폜
	eraseData(0, TEST_DATA_TABLE_SIZE, 1);

	//�n�b�V���e�[�u����ԕ\��
	printTableStatus();

	//�n�b�V���e�[�u���\��
	printTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findTable();
	
	//--------------------
	//�n�b�V���e�[�u���폜
	delete con;
	con = nullptr;

	printf("\n");
	printf("End\n");
	printf("============================================================\n");
	begin_time = printElapsedTime(begin_time, true);//�������ԕ\��

	//--------------------
	//�y��r�p�z�ySTL�Łz�n�b�V���e�[�u���e�X�g
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[STL] Hash Table Test\n");
	printf("--------------------------------------------------------------------------------\n");
	typedef std::unordered_map<crc32_t, data_t> stl_container_type;
	stl_container_type* stl_con = new stl_container_type();
	stl_con->reserve(TEST_DATA_TABLE_SIZE);

	//�n�b�V���e�[�u���̊�{���\��
	auto printSTLTableParameter = [&stl_con]()
	{
		printf("\n");
		printf("--- [STL] Table Parameter ---\n");
		printf(".max_size()=%u\n", stl_con->max_size());
	};
	printSTLTableParameter();

	//�e�[�u����ԕ\��
	auto printSTLTableStatus = [&stl_con]()
	{
		printf("\n");
		printf("--- [STL] Table Status ---\n");
		printf(".size()=%u\n", stl_con->size());
		printf(".empty()=%u\n", stl_con->empty());
		printf(".bucket_count()=%u\n", stl_con->bucket_count());
		printf(".max_bucket_count()=%u\n", stl_con->max_bucket_count());
		printf(".load_factor()=%u\n", stl_con->load_factor());
		printf(".max_load_factor()=%u\n", stl_con->max_load_factor());
	};
	printSTLTableStatus();

	//�n�b�V���e�[�u���ւ̃f�[�^�o�^
	auto insertSTLData = [&stl_con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- [STL] Insert Data ---\n");
		int insert_success = 0;
		int insert_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t obj(name, i);
			auto ite = stl_con->emplace(calcCRC32(name), obj);//�L�[�ƃR���X�g���N�^�p�����[�^��n���ēo�^
			if (ite.second)
			{
				++insert_success;
				printf_detail("OK\n");
			}
			else
			{
				++insert_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", insert_success, insert_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	insertSTLData(0, TEST_DATA_TABLE_SIZE / 2, 1);

	//�n�b�V���e�[�u����ԕ\��
	printSTLTableStatus();

	//�n�b�V���e�[�u���\��
	auto printSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf_detail("\n");
		printf_detail("--- [STL] Print Table ---\n");
		//for (container_type::set& set : +con)
		for (auto& pair : *stl_con)
		{
			const crc32_t key = pair.first;
			const stl_container_type::size_type index = stl_con->bucket(key);
			printf_detail("[%6d] key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)\n", index, key, pair.second.m_name, pair.second.m_value, index, stl_con->bucket_size(index));
		}
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	printSTLTable();

	//�n�b�V���e�[�u���A�N�Z�X
	auto findSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Find Data ---\n");
		int find_success = 0;
		int find_failure = 0;
		for (int i = 0; i < TEST_DATA_TABLE_SIZE; ++i)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			crc32_t key = calcCRC32(name);
			auto ite = stl_con->find(key);
			if (ite != stl_con->end())
			{
				const crc32_t key = ite->first;
				const stl_container_type::size_type index = stl_con->bucket(key);
				printf_detail("OK  key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)\n", key, ite->second.m_name, ite->second.m_value, index, stl_con->bucket_size(index));
				++find_success;
			}
			else
			{
				printf_detail("NG\n");
				++find_failure;
			}
		}
		printf("success=%d, failure=%d\n", find_success, find_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	findSTLTable();

	//�n�b�V���e�[�u������̃f�[�^�폜
	auto eraseSTLData = [&stl_con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- [STL] Erase Data ---\n");
		int erase_success = 0;
		int erase_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			crc32_t key = calcCRC32(name);
			bool result = stl_con->erase(key) == 1;
			if (result)
			{
				++erase_success;
				printf_detail("OK\n");
			}
			else
			{
				++erase_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", erase_success, erase_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	eraseSTLData(0, TEST_DATA_TABLE_SIZE, 2);

	//�n�b�V���e�[�u����ԕ\��
	printSTLTableStatus();

	//�n�b�V���e�[�u���\��
	printSTLTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findSTLTable();

	//�n�b�V���e�[�u���ւ̃f�[�^�o�^
	insertSTLData(1, TEST_DATA_TABLE_SIZE, 2);

	//�n�b�V���e�[�u����ԕ\��
	printSTLTableStatus();

	//�n�b�V���e�[�u���\��
	printSTLTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findSTLTable();

	//���n�b�V��
	auto rehashSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Rehash Table ---\n");
		stl_con->rehash(TEST_DATA_TABLE_SIZE);
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	rehashSTLTable();

	//�n�b�V���e�[�u����ԕ\��
	printSTLTableStatus();

	//�n�b�V���e�[�u���\��
	printSTLTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findSTLTable();

	//�N���A
	auto clearSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Clear Table ---\n");
		stl_con->clear();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	clearSTLTable();

	//�n�b�V���e�[�u����ԕ\��
	printSTLTableStatus();

	//�n�b�V���e�[�u���\��
	printSTLTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findSTLTable();

	//�n�b�V���e�[�u���ւ̃f�[�^�o�^
	insertSTLData(0, TEST_DATA_TABLE_SIZE, 1);

	//�n�b�V���e�[�u����ԕ\��
	printSTLTableStatus();

	//�n�b�V���e�[�u���\��
	printSTLTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findSTLTable();

	//�n�b�V���e�[�u������̃f�[�^�폜
	eraseSTLData(0, TEST_DATA_TABLE_SIZE, 1);

	//�n�b�V���e�[�u����ԕ\��
	printSTLTableStatus();

	//�n�b�V���e�[�u���\��
	printSTLTable();

	//�n�b�V���e�[�u���A�N�Z�X
	findSTLTable();

	//--------------------
	//�n�b�V���e�[�u���폜
	delete stl_con;
	stl_con = nullptr;
	
	printf("\n");
	printf("End\n");
	printf("============================================================\n");
	printElapsedTime(begin_time, true);//�������ԕ\��

	//--------------------
	//�|�C���^�^�̃n�b�V���e�[�u���e�X�g
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Hash Table Test for Pointer\n");
		printf("--------------------------------------------------------------------------------\n");

		//����^
		struct p_ope_t : public hash_table::base_ope_t<p_ope_t, int, data_t*>
		{
			//�L�[���擾
			inline static key_type getKey(const value_type& value){ return value->m_key; }
		};

		//�n�b�V���e�[�u��
		hash_table::container<p_ope_t, 100> p_con;

		//�o�^
		data_t obj1("0010", 123);
		data_t obj2("0020", 456);
		data_t obj3("0030", 789);
		p_con.insert(10, &obj1);
		p_con.insert(20, &obj2);
		p_con.insert(30, &obj3);

		//�������ĕ\��
		auto printObj = [&p_con](const int key)
		{
			printf("[%2d] ... ", key);
			data_t** p = p_con[key];
			if (p && *p)
				printf("OK  name=\"%s\", val=%d\n", (*p)->m_name, (*p)->m_value);
			else
				printf("NG\n");
		};
		printObj(10);
		printObj(20);
		printObj(30);
		printObj(40);

		//���b�N�擾�e�X�g
		{
			CRWLock::RLock lock(p_con);
			printObj(20);
		}
	}

	//--------------------
	//�֐��^�̃n�b�V���e�[�u���e�X�g
	//���X�N���v�g�Ȃǂ���֐����i������j�Ŋ֐������s����悤�ȗp�r��z��
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Hash Table Test for Function\n");
		printf("--------------------------------------------------------------------------------\n");
		
		//����^ ���P���Ȋ֐��Ăяo���p
		struct func_ope_t : public hash_table::base_ope_t<func_ope_t, crc32_t, std::function<int(int, int)>>
		{
		};
		
		//�I�u�W�F�N�g�����o�[�֐��Ăяo���e�X�g�p
		struct data_t
		{
			int calc(int a, int b)
			{
				return (a + b) * m_val;
			}
			data_t(const int val) :
				m_val(val)
			{}
		private:
			int m_val;
		};

		//����^ ���I�u�W�F�N�g�����o�[�֐��Ăяo���p
		struct obj_ope_t : public hash_table::base_ope_t<func_ope_t, crc32_t, std::function<int(data_t&, int, int)>>
		{
		};

		//�n�b�V���e�[�u��
		hash_table::container<func_ope_t, 100> func_con;
		hash_table::container<obj_ope_t, 100> obj_con;

		//�֐��^�n�b�V���e�[�u���e�X�g�p�֐��F�ʏ�֐�
		extern int func_add(int a, int b);

		//�֐��^�n�b�V���e�[�u���e�X�g�p�֐��F�֐��I�u�W�F�N�g
		struct func_sub{
			int operator()(int a, int b)
			{
				return a - b;
			};
		};

		//�֐��^�n�b�V���e�[�u���e�X�g�p�֐��F�����_�֐�
		auto func_mul = [](int a, int b) -> int
		{
			return a * b;
		};

		//�֐��^�n�b�V���e�[�u���e�X�g�p�֐��F�����_�֐�
		auto func_div = [](int a, int b) -> int
		{
			return a / b;
		};

		//�o�^
		func_con.emplace("+", func_add);
		func_con.emplace("-", func_sub());
		func_con.emplace("*", func_mul);
		func_con.emplace("/", std::bind(func_div, 50, 4));//std::bind���g�p
		obj_con.emplace("calc", std::mem_fn(&data_t::calc));//�N���X�����o�[�֐��̏ꍇ

		//�������Ď��s
		printf("50 + 4 = %d\n", (*func_con["+"])(50, 4));
		printf("50 - 4 = %d\n", (*func_con["-"])(50, 4));
		printf("50 * 4 = %d\n", (*func_con["*"])(50, 4));
		printf("50 / 4 = %d\n", (*func_con["/"])(0, 0));//std::bind()�Ŏ��O�Ƀp�����[�^���Z�b�g�ς�
		data_t obj(3);
		printf("obj.calc(1, 2) = %d\n", (*obj_con["calc"])(obj, 1, 2));//�N���X�����o�[�֐��̏ꍇ�A�I�u�W�F�N�g��n���K�v������
	}

	return EXIT_SUCCESS;
}

//�֐��^�n�b�V���e�[�u���e�X�g�p�֐��F�ʏ�֐�
int func_add(int a, int b)
{
	return a + b;
};

// End of file
