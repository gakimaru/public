#define TLS_IS_WINDOWS//�yMS�ŗL�d�l�zTLS�̐錾��Windows�X�^�C���ɂ��鎞�͂��̃}�N����L���ɂ���
#define USE_FUNCSIG//�yMS�ŗL�d�l�z�֐�����__FUNCSIG__���g�p���鎞�ɂ��̃}�N����L���ɂ���
#define USE_STRCPY_S//�yMS�ŗL�d�l�zstrcpy_s���g�p���鎞�ɂ��̃}�N����L���ɂ���
#define USE_WINDOWS_CONSOLE_COLOR//�yMS�ŗL�d�l�zWindows�X�^�C���̃R���\�[���J���[���g�p
#define USE_WINDOWS_DEBUG_BREAK//�yMS�ŗL�d�l�zWindow��DebugBreak���g�p
#define USE_ALIGNED_MALLOC//�yMS�ŗL�d�l�z_aligned_malloc���g�p���鎞�͂��̃}�N����L���ɂ���
#define USE_FRIEND_WITH_NEW_OPERATOR//�yMS�ŗL�d�l�H�zoperator new()���N���X���Ńt�����h�����鎞�͂��̃}�N����L���ɂ���

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>//valist�p
#include <assert.h>//assert�p
#include <memory.h>//memcpy�p
#include <stdint.h>//uintptr_t�p
#include <limits.h>//UCHAR_MAX�p
#include <bitset>//std::bitset�p
#include <iterator>//std::iterator�p
#include <algorithm>//std::move�p
#include <atomic>//C++11�A�g�~�b�N����
#include <vector>//vector
#include <unordered_map>//C++11�n�b�V���e�[�u��
#include <chrono>//C++11����
#include <thread>//C++11�X���b�h
#include <random>//C++11����

#ifdef USE_ALIGNED_MALLOC
#include <malloc.h>//malloc,_aligned_malloc�p
#else//USE_ALIGNED_MALLOC
#include <stdlib.h>//memalign�p
#endif//USE_ALIGNED_MALLOC

//--------------------------------------------------------------------------------
//��{�}�N��

//�u���[�N�|�C���g
#ifdef USE_WINDOWS_DEBUG_BREAK
#include <windows.h>//�u���[�N�|�C���g�p
#define BREAK_POINT() DebugBreak()
#else//USE_WINDOWS_DEBUG_BREAK
#define BREAK_POINT()
#endif//USE_WINDOWS_DEBUG_BREAK

//�f�o�b�O�v�����g
#define DEBUG_PRINT(msg, ...) printf(msg, ##__VA_ARGS__)
#define DEBUG_FPRINT(fp, msg, ...) fprintf(fp, msg, ##__VA_ARGS__)
#define DEBUG_FLUSH() fflush(stdout)
#define DEBUG_FFLUSH(fp) fflush(fp)
//#define DEBUG_PRINT(msg, ...)
//#define DEBUG_FPRINT(fp, msg, ...)
//#define DEBUG_FLUSH()
//#define DEBUG_FFLUSH(fp) fflush(fp)

//�����񉻃}�N��
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)

//�ÓI�A�T�[�V����
#define STATIC_ASSERT(expr, msg) \
	static_assert(expr, msg)

//�A�T�[�V����
#define ASSERT(expr, msg, ...) \
	if (!(expr)) \
	{ \
		DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
		"  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
		"  "  msg "\n", ##__VA_ARGS__); \
		BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//�폜�p
//#include <assert.h>//assert�p
//#define ASSERT(expr, msg, ...) assert(expr)//VC++�W����

//�X���b�h���[�J���X�g���[�W�C���q
//��C++11�d�l�U��
#ifdef TLS_IS_WINDOWS
#define thread_local __declspec(thread)//Windows�d�l
#else//TLS_IS_WINDOWS
#define thread_local __thread//POSIX�d�l
#endif//TLS_IS_WINDOWS

//�֐����擾�}�N��
#ifdef USE_FUNCSIG
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif//USE_FUNCSIG

//�\�[�X�t�@�C�������֐����擾�}�N��
#define GET_CONCATENATED_SOURCE_FILE_NAME() __FILE__ "(" TO_STRING_EX(__LINE__) ")[" __TIMESTAMP__ "]"//�t�@�C�����������擾�}�N��
#define GET_FUNC_NAME() __PRETTY_FUNCTION__//�֐����擾�}�N��

//Windows�X�^�C���J���[�p
#ifdef USE_WINDOWS_CONSOLE_COLOR
#include <windows.h>
#include <conio.h> 
#endif//USE_WINDOWS_CONSOLE_COLOR

//--------------------
//���ʊ֐�
#include <string.h>
//�t�@�C�����擾�֐��i�f�B���N�g�������������������Ԃ��j
const char* getFileName(const char* str)
{
	if (!str)
		return nullptr;
	std::size_t len = strlen(str);
	const char* p = str + len;
	for (; len > 0; --len, --p)
	{
		const char c = *(p - 1);
		if (c == '\\' || c == '/')
			return p;
	}
	return str;
}

//----------------------------------------
//�X���b�hID�N���X
//��ID���n�b�V���������ꍇ�ATLS�����p���č�����

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

#if 0
//--------------------------------------------------------------------------------
//���[�h�E���C�g���b�N�N���X
//���e�ʐߖ�̂��߂ɁAPOSIX�X���b�h���C�u�����ł̂悤�ɁA���݂̃X���b�h�̃��b�N��Ԃ�ێ����Ȃ�
//���K�����b�N�N���X CRWLock::LockR, CRWLock::LockR_AsNecessary, CRWLock::LockW ���g�p���A
//�@�����Ɍ��݂̃��b�N��Ԃ�ێ�����

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
#endif

//--------------------------------------------------------------------------------
//�X�^�b�N�A���P�[�^

//--------------------
//�X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�N���X
class IStackAllocator
{
public:
	//�萔
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//�f�t�H���g�̃A���C�������g
	//�X�^�b�N��
	enum E_ORDERED
	{
		DEFAULT = 0,//�f�t�H���g
		NORMAL = 1,//����
		REVERSE = -1,//�t��
	};
public:
	//�^
	typedef unsigned char byte;//�o�b�t�@�p
	typedef uintptr_t marker_t;//�X�^�b�N�}�[�J�[�^
public:
	//�A�N�Z�b�T
	virtual std::size_t getTotal() const = 0;//�S�̂̃������ʂ��擾
	virtual std::size_t getUsed() const = 0;//�g�p���̃������ʂ��擾
	virtual std::size_t getRemain() const = 0;//�c��̃������ʂ��擾
	virtual const byte* getNowPtr() const = 0;//���݂̃o�b�t�@�ʒu���擾
	virtual marker_t getMarker() const = 0;//���݂̃}�[�J�[���擾
public:
	//���\�b�h
	//�������m��
	virtual void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) = 0;
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	virtual void back(const marker_t marker) = 0;
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	virtual void back(const void* p) = 0;
	//�������j���i�����j
	virtual void clear() = 0;
	//�������j���i�S�āj
	virtual void clearAll() = 0;
public:
	//�f�X�g���N�^
	virtual ~IStackAllocator(){}
};
//�萔�̃G�C���A�X
static const IStackAllocator::E_ORDERED DSA_DEFAULT = IStackAllocator::DEFAULT;//�f�t�H���g
static const IStackAllocator::E_ORDERED DSA_NORMAL = IStackAllocator::NORMAL;//����
static const IStackAllocator::E_ORDERED DSA_REVERSE = IStackAllocator::REVERSE;//�t��

//--------------------
//�X�^�b�N�A���P�[�^�N���X
//����X���b�h�Z�[�t�i�������x�D��j
//���C���^�[�t�F�[�X���������邪�A�������̂��߂� virtual���\�b�h�ɗ��炸����\
class CStackAllocator : public IStackAllocator
{
public:
	//�A�N�Z�b�T
	std::size_t getTotal() const override { return m_buffSize; }//�S�̂̃������ʂ��擾
	std::size_t getUsed() const override { return m_used; }//�g�p���̃������ʂ��擾
	std::size_t getRemain() const override { return m_buffSize - m_used; }//�c��̃������ʂ��擾
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾���擾
	const byte* getNowPtrN() const { return m_buffPtr + m_used; }//���݂̃o�b�t�@�ʒu�i�����j���擾
	const byte* getNowPtr() const override { return getNowPtrN(); }//���݂̃o�b�t�@�ʒu���擾
	marker_t getMarkerN() const { return m_used; }//���݂̃}�[�J�[�i�����j���擾
	marker_t getMarker() const override { return getMarkerN(); }//���݂̃}�[�J�[���擾
public:
	//���\�b�h
	//�������m�ہi�����j
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_used;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_used + align_diff + size;//���̃}�[�J�[�Z�o
		if (next_used > m_buffSize)//�������I�[�o�[�`�F�b�N�i�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK�j
		{
			printf("stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_buffSize - m_used);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//�������m�ۃA�h���X�Z�o
		m_used = next_used;//�}�[�J�[�X�V
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocN(size, align);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���}�[�J�[�w���
	void backN(const marker_t marker)
	{
		if (marker >= m_used)//�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK
			return;
		m_used = marker;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void back(const marker_t marker) override
	{
		return backN(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���|�C���^�w���
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		back(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void back(const void* p) override
	{
		backN(p);
	}
	//�������j���i�����j
	void clearN()
	{
		m_used = 0;//�}�[�J�[�����Z�b�g
	}
	//�������j���i�����j
	void clear() override
	{
		clearN();
	}
	//�������j���i�S�āj
	void clearAll() override
	{
		clearN();
	}
public:
	//�R���X�g���N�^
	CStackAllocator(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�擪�A�h���X
		m_buffSize(buff_size),//�o�b�t�@�T�C�Y
		m_used(0)//�}�[�J�[
	{}
	//�f�X�g���N�^
	~CStackAllocator() override
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�擪�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	marker_t m_used;//�}�[�J�[�i�����j
};

//--------------------
//�o�b�t�@�t���X�^�b�N�A���P�[�^�e���v���[�g�N���X
//���ÓI�o�b�t�@���g�p��������΁A�Œ�o�b�t�@�V���O���g��������
template<std::size_t SIZE>
class CStackAllocatorWithBuff : public CStackAllocator
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = SIZE;//�o�b�t�@�T�C�Y
public:
	//�R���X�g���N�^
	CStackAllocatorWithBuff() :
		CStackAllocator(m_buff, BUFF_SIZE)
	{}
	//�f�X�g���N�^
	~CStackAllocatorWithBuff() override
	{}
private:
	//�t�B�[���h
	byte m_buff[BUFF_SIZE];//�o�b�t�@
};

#if 0
//--------------------
//�o�����X�^�b�N�A���P�[�^�N���X
//����X���b�h�Z�[�t�i�������x�D��j
//���C���^�[�t�F�[�X���������邪�A�������̂��߂� virtual���\�b�h�ɗ��炸����\
class CDualStackAllocator : public IStackAllocator
{
public:
	//�A�N�Z�b�T
	std::size_t getTotal() const override { return m_buffSize; }//�S�̂̃������ʂ��擾
	std::size_t getUsed() const override { return m_usedN + m_buffSize - m_usedR; }//�g�p���̃������ʂ��擾
	std::size_t getRemain() const override { return m_usedR - m_usedN; }//�c��̃������ʂ��擾
	E_ORDERED getDefaultOrdered() const { return m_defaultOrdered; }//�f�t�H���g�̃X�^�b�N�����擾
	void setDefaultOrdered(const E_ORDERED ordered)//�f�t�H���g�̃X�^�b�N�����X�V
	{
		m_defaultOrdered = ordered == REVERSE ? REVERSE : NORMAL;
	}
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾���擾
	const byte* getNowPtrN() const { return m_buffPtr + m_usedN; }//���݂̃o�b�t�@�ʒu�i�����j���擾
	const byte* getNowPtrR() const { return m_buffPtr + m_usedR; }//���݂̃o�b�t�@�ʒu�i�t���j���擾
	const byte* getNowPtrD() const { return getNowPtr(m_defaultOrdered); }//���݂̃o�b�t�@�ʒu���擾
	const byte* getNowPtr(const E_ORDERED ordered) const { return ordered == DEFAULT ? getNowPtrD() : ordered == REVERSE ? getNowPtrR() : getNowPtrN(); }//���݂̃o�b�t�@�ʒu���擾
	const byte* getNowPtr() const override { return getNowPtrD(); }//���݂̃o�b�t�@�ʒu���擾
	marker_t getMarkerN() const { return m_usedN; }//���݂̃}�[�J�[�i�����j���擾
	marker_t getMarkerR() const { return m_usedR; }//���݂̃}�[�J�[�i�t���j���擾
	marker_t getMarkerD() const { return getMarker(m_defaultOrdered); }//���݂̃}�[�J�[���擾
	marker_t getMarker(const E_ORDERED ordered) const { return ordered == DEFAULT ? getMarkerD() : ordered == REVERSE ? getMarkerR() : getMarkerN(); }//���݂̃}�[�J�[���擾
	marker_t getMarker() const override { return getMarkerD(); }//���݂̃}�[�J�[���擾
public:
	//���\�b�h
	//�������m�ہi�����j
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedN;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_usedN + align_diff + size;//���̃}�[�J�[�Z�o
		if (next_used > m_usedR)//�������I�[�o�[�`�F�b�N�i�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK�j
		{
			printf("normal-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR - m_usedN);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//�������m�ۃA�h���X�Z�o
		m_usedN = next_used;//�}�[�J�[�X�V
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m�ہi�t���j
	void* allocR(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedR;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t alloc_ptr_tmp = now_ptr - size;//�������m�ۃA�h���X�Z�o�i�b��j
		const uintptr_t align_diff = align > 0 ? alloc_ptr_tmp % align == 0 ? 0 : alloc_ptr_tmp % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_usedR - size - align_diff;//���̃}�[�J�[�Z�o
		if (next_used < m_usedN || next_used > m_buffSize)//�������I�[�o�[�`�F�b�N�i�I�[�o�[�t���[���Ēl���傫���Ȃ�\�����`�F�b�N�j
		{
			printf("reversed-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR - m_usedN);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr - size - align_diff;//�������m�ۃA�h���X�Z�o
		m_usedR = next_used;//�}�[�J�[�X�V
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m��
	void* allocD(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return alloc(m_defaultOrdered, size, align);
	}
	//�������m��
	void* alloc(const E_ORDERED ordered, const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return ordered == DEFAULT ? allocD(size, align) : ordered == REVERSE ? allocR(size, align) : allocN(size, align);
	}
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocD(size, align);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���}�[�J�[�w���
	void backN(const marker_t marker_n)
	{
		if (marker_n > m_usedR)//�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK
			return;
		m_usedN = marker_n;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���|�C���^�w���
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	//���}�[�J�[�w���
	void backR(const marker_t marker_r)
	{
		if (marker_r < m_usedN || marker_r > m_buffSize)//�������I�[�o�[�`�F�b�N
			return;
		m_usedR = marker_r;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	//���|�C���^�w���
	void backR(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backR(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void backD(const marker_t marker)
	{
		back(m_defaultOrdered, marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void backD(const void* p)
	{
		back(m_defaultOrdered, p);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void back(const E_ORDERED ordered, const marker_t marker)
	{
		ordered == DEFAULT ? backD(marker) : ordered == REVERSE ? backR(marker) : backN(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void back(const E_ORDERED ordered, const void* p)
	{
		ordered == DEFAULT ? backD(p) : ordered == REVERSE ? backR(p) : backN(p);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void back(const marker_t marker) override
	{
		backD(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void back(const void* p) override
	{
		backD(p);
	}
	//�������j���i�����j
	void clearN()
	{
		m_usedN = 0;
	}
	//�������j���i�t���j
	void clearR()
	{
		m_usedR = m_buffSize;
	}
	//�������j��
	void clearD()
	{
		clear(m_defaultOrdered);
	}
	//�������j���i�����j
	void clearNR()
	{
		clearN();
		clearR();
	}
	//�������j��
	void clear(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? clearD() : ordered == REVERSE ? clearR() : clearN();
	}
	//�������j��
	void clear() override
	{
		clearD();
	}
	//�������j���i�S�āj
	void clearAll() override
	{
		clearNR();
	}
public:
	//�R���X�g���N�^
	CDualStackAllocator(void* buff_p, const std::size_t buff_size, const E_ORDERED default_ordered = NORMAL) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�擪�A�h���X
		m_buffSize(buff_size),//�o�b�t�@�T�C�Y
		m_usedN(0),//�}�[�J�[�i�����j
		m_usedR(buff_size)//�}�[�J�[�i�t���j
	{
		setDefaultOrdered(default_ordered);//�f�t�H���g�̃X�^�b�N����␳
	}
	//�f�X�g���N�^
	~CDualStackAllocator() override
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�擪�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	marker_t m_usedN;//�}�[�J�[�i�����j
	marker_t m_usedR;//�}�[�J�[�i�t���j
	E_ORDERED m_defaultOrdered;//�f�t�H���g�̃X�^�b�N��
};

//--------------------
//�o�b�t�@�t���o�����X�^�b�N�A���P�[�^�e���v���[�g�N���X
//���ÓI�o�b�t�@���g�p��������΁A�Œ�o�b�t�@�V���O���g��������
template<std::size_t SIZE>
class CDualStackAllocatorWithBuff : public CDualStackAllocator
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = SIZE;//�o�b�t�@�T�C�Y
public:
	//�R���X�g���N�^
	CDualStackAllocatorWithBuff(const E_ORDERED default_ordered = NORMAL) :
		CDualStackAllocator(m_buff, BUFF_SIZE, default_ordered)
	{}
	//�f�X�g���N�^
	~CDualStackAllocatorWithBuff() override
	{}
private:
	//�t�B�[���h
	byte m_buff[BUFF_SIZE];//�o�b�t�@
};
#endif

#if 0
//--------------------
//�X�}�[�g�X�^�b�N�A���P�[�^�N���X
//����X���b�h�Z�[�t�i�������x�D��j
//���C���^�[�t�F�[�X���������邪�A�������̂��߂� virtual���\�b�h�ɗ��炸����\
class CSmartStackAllocator : public IStackAllocator
{
public:
	//�^
	typedef int counter_t;//�J�E���^�^
public:
	//�A�N�Z�b�T
	std::size_t getTotal() const override { return m_buffSize; }//�S�̂̃������ʂ��擾
	std::size_t getUsed() const override { return m_usedN.load() + m_buffSize - m_usedR.load(); }//�g�p���̃������ʂ��擾
	std::size_t getRemain() const override { return m_usedR.load() - m_usedN.load(); }//�c��̃������ʂ��擾
	E_ORDERED getDefaultOrdered() const { return m_defaultOrdered.load(); }//�f�t�H���g�̃X�^�b�N�����擾
	void setDefaultOrdered(const E_ORDERED ordered)//�f�t�H���g�̃X�^�b�N�����X�V
	{
		//m_lock.lock();//���b�N�擾�i�s�v�ˑ���ɃA�g�~�b�N�^���g�p�j
		m_defaultOrdered.store(ordered == REVERSE ? REVERSE : NORMAL);
		//m_lock.unlock();//���b�N����i�s�v�j
	}
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾���擾
	const byte* getNowPtrN() const { return m_buffPtr + m_usedN.load(); }//���݂̃o�b�t�@�ʒu�i�����j���擾
	const byte* getNowPtrR() const { return m_buffPtr + m_usedR.load(); }//���݂̃o�b�t�@�ʒu�i�t���j���擾
	const byte* getNowPtrD() const { return getNowPtr(m_defaultOrdered.load()); }//���݂̃o�b�t�@�ʒu���擾
	const byte* getNowPtr(const E_ORDERED ordered) const { return ordered == DEFAULT ? getNowPtrD() : ordered == REVERSE ? getNowPtrR() : getNowPtrN(); }//���݂̃o�b�t�@�ʒu���擾
	const byte* getNowPtr() const override { return getNowPtrD(); }//���݂̃o�b�t�@�ʒu���擾
	marker_t getMarkerN() const { return m_usedN.load(); }//���݂̃}�[�J�[�i�����j���擾
	marker_t getMarkerR() const { return m_usedR.load(); }//���݂̃}�[�J�[�i�t���j���擾
	marker_t getMarkerD() const { return getMarker(m_defaultOrdered.load()); }//���݂̃}�[�J�[���擾
	marker_t getMarker(const E_ORDERED ordered) const { return ordered == DEFAULT ? getMarkerD() : ordered == REVERSE ? getMarkerR() : getMarkerN(); }//���݂̃}�[�J�[���擾
	marker_t getMarker() const override { return getMarkerD(); }//���݂̃}�[�J�[���擾
	marker_t getBeginN() const { return m_beginN.load(); }//�J�n�}�[�J�[�i�����j���擾
	marker_t getBeginR() const { return m_beginR.load(); }//�J�n�}�[�J�[�i�t���j���擾
	marker_t getBeginD() const { return getBegin(m_defaultOrdered.load()); }//�J�n�}�[�J�[���擾
	marker_t getBegin(const E_ORDERED ordered) const { return ordered == DEFAULT ? getBeginD() : ordered == REVERSE ? getBeginR() : getBeginN(); }//�J�n�}�[�J�[���擾
	marker_t getBegin() const { return getBeginD(); }//�J�n�}�[�J�[���擾
	marker_t getCounterN() const { return m_counterN.load(); }//�������m�ۃJ�E���^�i�����j���擾
	marker_t getCounterR() const { return m_counterR.load(); }//�������m�ۃJ�E���^�i�t���j���擾
	marker_t getCounterD() const { return getCounter(m_defaultOrdered.load()); }//�������m�ۃJ�E���^���擾
	marker_t getCounter(const E_ORDERED ordered) const { return ordered == DEFAULT ? getCounterD() : ordered == REVERSE ? getCounterR() : getCounterN(); }//�������m�ۃJ�E���^���擾
	marker_t getCounter() const { return getCounterD(); }//�������m�ۃJ�E���^���擾
public:
	//���\�b�h
	//�������m�ہi�����j
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		//�������̂��߂ɁA��x���b�N�͈̔͊O�ŒP���󂫗̈攻��
		if (m_usedN.load() + size > m_usedR.load())
			return nullptr;
		m_lock.lock();//���b�N�擾
		m_counterN.fetch_add(1);
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedN.load();//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_usedN.load() + align_diff + size;//���̃}�[�J�[�Z�o
		if (next_used > m_usedR.load())//�������I�[�o�[�`�F�b�N�i�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK�j
		{
			printf("normal-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR.load() - m_usedN.load());
			m_lock.unlock();//���b�N���
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//�������m�ۃA�h���X�Z�o
		m_usedN.store(next_used);//�}�[�J�[�X�V
		m_lock.unlock();//���b�N���
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m�ہi�t���j
	void* allocR(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		//�������̂��߂ɁA��x���b�N�͈̔͊O�ŒP���󂫗̈攻��
		if (m_usedN.load() > m_usedR.load() - size)
			return nullptr;
		m_lock.lock();//���b�N�擾
		m_counterR.fetch_add(1);
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedR.load();//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t alloc_ptr_tmp = now_ptr - size;//�������m�ۃA�h���X�Z�o�i�b��j
		const uintptr_t align_diff = align > 0 ? alloc_ptr_tmp % align == 0 ? 0 : alloc_ptr_tmp % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_usedR.load() - size - align_diff;//���̃}�[�J�[�Z�o
		if (next_used < m_usedN.load() || next_used > m_buffSize)//�������I�[�o�[�`�F�b�N�i�I�[�o�[�t���[���Ēl���傫���Ȃ�\�����`�F�b�N�j
		{
			printf("reversed-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR.load() - m_usedN.load());
			m_lock.unlock();//���b�N���
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr - size - align_diff;//�������m�ۃA�h���X�Z�o
		m_usedR.store(next_used);//�}�[�J�[�X�V
		m_lock.unlock();//���b�N���
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m��
	void* allocD(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return alloc(m_defaultOrdered.load(), size, align);
	}
	//�������m��
	void* alloc(const E_ORDERED ordered, const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return ordered == DEFAULT ? allocD(size, align) : ordered == REVERSE ? allocR(size, align) : allocN(size, align);
	}
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocD(size, align);
	}
private:
	//�������j���i�����j
	void freeN(void* p)
	{
		//�|�C���^�͈̔̓`�F�b�N
		//���������̂��߂ɁA��x���b�N�͈̔͊O�Ń`�F�b�N
		//�@�i���freeN�֐���freeD����g�ŌĂяo����邽�߁j
		if (m_counterN.load() <= 0)
			return;
		const marker_t now_n = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		if (now_n < m_beginN.load() || now_n > m_usedN.load())
			return;
		//�|�C���^�������X�^�b�N�Ƃ��ēK���̂��߁A�����J�n
		m_lock.lock();//���b�N�擾
		if (m_counterN.load() <= 0 || now_n < m_beginN.load() || now_n > m_usedN.load())//�͈͂̍ă`�F�b�N
		{
			m_lock.unlock();//���b�N���
			return;
		}
		m_counterN.fetch_sub(1);
		if (m_counterN.load() == 0)
			m_usedN.store(m_beginN.load());
		m_lock.unlock();//���b�N���
	}
	//�������j���i�t���j
	void freeR(void* p)
	{
		//�|�C���^�͈̔̓`�F�b�N
		//���������̂��߂ɁA��x���b�N�͈̔͊O�Ń`�F�b�N
		//�@�i���freeN�֐���freeD����g�ŌĂяo����邽�߁j
		if (m_counterR.load() <= 0)
			return;
		const marker_t now_r = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		if (now_r >= m_beginR.load() || now_r < m_usedR.load())
			return;
		//�|�C���^���t���X�^�b�N�Ƃ��ēK���̂��߁A�����J�n
		m_lock.lock();//���b�N�擾
		if (m_counterR.load() <= 0 || now_r >= m_beginR.load() || now_r < m_usedR.load())//�͈͂̍ă`�F�b�N
		{
			m_lock.unlock();//���b�N���
			return;
		}
		m_counterR.fetch_sub(1);
		if (m_counterR.load() == 0)
			m_usedR.store(m_beginR.load());
		m_lock.unlock();//���b�N���
	}
public:
	//�������j��
	void free(void* p)
	{
		//�|�C���^���`�F�b�N���ď�������̂Ő����Ƌt���̗����̏������܂Ƃ߂Ď��s����
		freeN(p);//����
		freeR(p);//�t��
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n�i�����j
	//���������m�ۃJ�E���^�����Z�b�g
	void beginN()
	{
		m_lock.lock();//���b�N�擾
		m_beginN.store(m_usedN.load());
		m_counterN.store(0);
		m_lock.unlock();//���b�N���
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n�i�t���j
	//���������m�ۃJ�E���^�����Z�b�g
	void beginR()
	{
		m_lock.lock();//���b�N�擾
		m_beginR.store(m_usedR.load());
		m_counterR.store(0);
		m_lock.unlock();//���b�N���
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n 
	//���������m�ۃJ�E���^�����Z�b�g
	void beginD()
	{
		begin(m_defaultOrdered.load());
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n 
	//���������m�ۃJ�E���^�����Z�b�g
	void begin(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? beginD() : ordered == REVERSE ? beginR() : beginN();
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n 
	//���������m�ۃJ�E���^�����Z�b�g
	void begin()
	{
		beginD();
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void backN(const marker_t marker_n)
	{
		m_lock.lock();//���b�N�擾
		if (marker_n > m_usedR.load())//�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK
		{
			m_lock.unlock();//���b�N���
			return;
		}
		m_usedN.store(marker_n);
		m_beginN.store(marker_n);
		m_counterN.store(0);
		m_lock.unlock();//���b�N���
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void backR(const marker_t marker_r)
	{
		m_lock.lock();//���b�N�擾
		if (marker_r < m_usedN.load() || marker_r > m_buffSize)//�������I�[�o�[�`�F�b�N
		{
			return;
			m_lock.unlock();//���b�N���
		}
		m_usedR.store(marker_r);
		m_beginR.store(marker_r);
		m_counterR.store(0);
		m_lock.unlock();//���b�N���
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void backR(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backR(marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void backD(const marker_t marker)
	{
		back(m_defaultOrdered.load(), marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void backD(const void* p)
	{
		back(m_defaultOrdered.load(), p);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void back(const E_ORDERED ordered, const marker_t marker)
	{
		ordered == DEFAULT ? backD(marker) : ordered == REVERSE ? backR(marker) : backN(marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void back(const E_ORDERED ordered, const void* p)
	{
		ordered == DEFAULT ? backD(p) : ordered == REVERSE ? backR(p) : backN(p);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void back(const marker_t marker) override
	{
		backD(marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void back(const void* p) override
	{
		backD(p);
	}
	//�������j���i�����j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearN()
	{
		m_lock.lock();//���b�N�擾
		m_usedN.store(0);
		m_beginN.store(0);
		m_counterN.store(0);
		m_lock.unlock();//���b�N���
	}
	//�������j���i�t���j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearR()
	{
		m_lock.lock();//���b�N�擾
		m_usedR.store(m_buffSize);
		m_beginR.store(0);
		m_counterR.store(0);
		m_lock.unlock();//���b�N���
	}
	//�������j��
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearD()
	{
		clear(m_defaultOrdered.load());
	}
	//�������j���i�����j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearNR()
	{
		clearN();
		clearR();
	}
	//�������j��
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clear(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? clearD() : ordered == REVERSE ? clearR() : clearN();
	}
	//�������j��
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clear() override
	{
		clearD();
	}
	//�������j���i�S�āj
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearAll() override
	{
		clearNR();
	}
public:
	//�R���X�g���N�^
	CSmartStackAllocator(void* buff_p, const std::size_t buff_size, const E_ORDERED default_ordered = NORMAL) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�擪�A�h���X
		m_buffSize(buff_size)//�o�b�t�@�T�C�Y
	{
		m_usedN.store(0);//�}�[�J�[�i�����j
		m_usedR.store(buff_size);//�}�[�J�[�i�t���j
		m_beginN.store(0);//�J�n�}�[�J�[�i�����j���J�E���g���J�n�����ʒu�i�����J���ł��̈ʒu�ɖ߂��j
		m_beginR.store(buff_size);//�J�n�}�[�J�[�i�t���j���J�E���g���J�n�����ʒu�i�����J���ł��̈ʒu�ɖ߂��j
		m_counterN.store(0);//�������m�ۃJ�E���^�i�����j
		m_counterR.store(0);//�������m�ۃJ�E���^�i�t���j
		setDefaultOrdered(default_ordered);//�f�t�H���g�̃X�^�b�N��
	}
	//�f�X�g���N�^
	~CSmartStackAllocator() override
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�擪�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	std::atomic<marker_t> m_usedN;//�}�[�J�[�i�����j
	std::atomic<marker_t> m_usedR;//�}�[�J�[�i�t���j
	std::atomic<marker_t> m_beginN;//�J�n�}�[�J�[�i�����j���J�E���g���J�n�����ʒu�i�����J���ł��̈ʒu�ɖ߂��j
	std::atomic<marker_t> m_beginR;//�J�n�}�[�J�[�i�t���j���J�E���g���J�n�����ʒu�i�����J���ł��̈ʒu�ɖ߂��j
	std::atomic<counter_t> m_counterN;//�������m�ۃJ�E���^�i�����j
	std::atomic<counter_t> m_counterR;//�������m�ۃJ�E���^�i�t���j
	std::atomic<E_ORDERED> m_defaultOrdered;//�f�t�H���g�̃X�^�b�N��
	CSpinLock m_lock;//���b�N
};

//--------------------
//�o�b�t�@�t���X�}�[�g�X�^�b�N�A���P�[�^�e���v���[�g�N���X
//���ÓI�o�b�t�@���g�p��������΁A�Œ�o�b�t�@�V���O���g��������
template<std::size_t SIZE>
class CSmartStackAllocatorWithBuff : public CSmartStackAllocator
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = SIZE;//�o�b�t�@�T�C�Y
public:
	//�R���X�g���N�^
	CSmartStackAllocatorWithBuff(const E_ORDERED default_ordered = NORMAL) :
		CSmartStackAllocator(m_buff, BUFF_SIZE, default_ordered)
	{}
	//�f�X�g���N�^
	~CSmartStackAllocatorWithBuff() override
	{}
private:
	//�t�B�[���h
	byte m_buff[BUFF_SIZE];//�o�b�t�@
};
#endif

//--------------------------------------------------------------------------------
//�v�[���A���P�[�^�N���X

//----------------------------------------
//�N���X�錾
class CPoolAllocator;

//----------------------------------------
//�v�[���A���P�[�^�N���X
//���X���b�h�Z�[�t�Ή�
class CPoolAllocator
{
public:
	//�^�錾
	typedef unsigned char byte;//�o�b�t�@�p
	typedef int index_t;//�C���f�b�N�X�p
public:
	//�萔
	static const index_t INVALID_INDEX = INT_MAX;//�u���b�N�C���f�b�N�X�̖����l
public:
	//�A�N�Z�b�T
	const byte* getBuff() const { return m_pool; }//�o�b�t�@�擾
	std::size_t getBlockSize() const { return m_blockSize; }//�u���b�N�T�C�Y
	index_t getBlocksNum() const { return m_poolBlocksNum; }//�v�[���u���b�N��
	index_t getUsed() const { return m_used.load(); }//�g�p�����擾
	index_t getRemain() const { return m_poolBlocksNum - m_used.load(); }//�c���擾
	const byte* getBlockConst(const index_t index) const { return m_pool + index * m_blockSize; }//�u���b�N�擾
private:
	byte* getBlock(const index_t index){ return m_pool + index * m_blockSize; }//�u���b�N�擾
private:
	//���\�b�h
	//�������m�ۏ�ԃ��Z�b�g
	void reset()
	{
		//���b�N�擾
		m_lock.lock();

		m_used.store(0);//�g�p����
		m_next = 0;//���g�p�擪�C���f�b�N�X
		m_recycle = INVALID_INDEX;//���T�C�N���C���f�b�N�X

		//���b�N���
		m_lock.unlock();
	}
	//�������u���b�N�m��
	//���g�p���t���O�̋󂫂��������ăt���O���X�V���A
	//�@�m�ۂ����C���f�b�N�X��Ԃ�
	int assign()
	{
		//�g�p���u���b�N���`�F�b�N�́A�������̂��߂ɁA��x���b�N�͈̔͊O�ōs��
		if (m_used.load() >= m_poolBlocksNum)
			return INVALID_INDEX;//�󂫂Ȃ�

		//���b�N�擾
		m_lock.lock();

		//�g�p���u���b�N�����ă`�F�b�N
		if (m_used.load() >= m_poolBlocksNum)
		{
			m_lock.unlock();//���b�N���
			return INVALID_INDEX;//�󂫂Ȃ�
		}

		//�C���f�b�N�X�m��
		index_t index = INVALID_INDEX;
		if (m_next < m_poolBlocksNum)
		{
			//���g�p�C���f�b�N�X������ꍇ
			index = m_next++;//���g�p�擪�C���f�b�N�X�J�E���g�A�b�v
			m_used.fetch_add(1);//�g�p�����J�E���g�A�b�v
		}
		else
		{
			if (m_recycle != INVALID_INDEX)
			{
				//���T�C�N���\�ȃC���f�b�N�X������ꍇ
				index = m_recycle;//���T�C�N���C���f�b�N�X
				m_recycle = *reinterpret_cast<unsigned int*>(getBlock(index));//���T�C�N���C���f�b�N�X�X�V�i�󂫃m�[�h�̐擪�ɏ������܂�Ă���j
				m_used.fetch_add(1);//�g�p�����J�E���g�A�b�v
			}
		}

		//���b�N���
		m_lock.unlock();

		//�ŏ��Ɏg�p���u���b�N���𔻒肵�Ă���̂ŁA���̎��_�ŃC���f�b�N�X�������Ȃ���΃v���O�����ɖ�肪����͂�
		ASSERT(index != INVALID_INDEX, "Probably, mistaken logic in this program.");

		//�I��
		return index;
	}
	//�������u���b�N���
	//���w��̃C���f�b�N�X�̎g�p���t���O�����Z�b�g
	void release(const index_t index)
	{
		//�C���f�b�N�X�͈̔̓`�F�b�N�i���b�N�͈̔͊O�ōs���j
		if (index < 0 || index >= m_poolBlocksNum)
			return;

		//���b�N�擾
		m_lock.lock();

		//���T�C�N��
		*reinterpret_cast<unsigned int*>(getBlock(index)) = m_recycle;//���T�C�N���C���f�b�N�X�������݁i�󂫃m�[�h�̐擪�ɋ����ɏ������ށj
		m_recycle = index;//���T�C�N���C���f�b�N�X�g�݊���

		//�g�p�����J�E���g�_�E��
		m_used.fetch_sub(1);

		//���b�N���
		m_lock.unlock();
	}
public:
	//�������m��
	void* alloc(const std::size_t size)
	{
		//�y�A�T�[�V�����z�v���T�C�Y���u���b�N�T�C�Y�𒴂���ꍇ�͑����m�ێ��s
		ASSERT(size <= m_blockSize, "CPoolAllocator::alloc(%d) cannot allocate. Size must has been under %d.", size, m_blockSize);
		if (size > m_blockSize)
		{
			return nullptr;
		}
		//�󂫃u���b�N���m�ۂ��ĕԂ�
		const index_t index = assign();
		//�y�A�T�[�V�����z�S�u���b�N�g�p���ɂ��A�m�ێ��s
		ASSERT(index >= 0, "CPoolAllocator::alloc(%d) cannot allocate. Buffer is full. (num of blocks is %d)", size, m_poolBlocksNum);
		//�m�ۂ�����������Ԃ�
		return index == INVALID_INDEX ? nullptr : getBlock(index);
	}
	//���������
	void free(void * p)
	{
		//nullptr���͑���������s
		ASSERT(p != nullptr, "CPoolAllocator::free() cannot free. Pointer is null.");
		if (!p)
			return;
		//�|�C���^����C���f�b�N�X���Z�o
		const intptr_t diff = reinterpret_cast<intptr_t>(p)-reinterpret_cast<intptr_t>(m_pool);//�|�C���^�̍���
		const index_t index = diff / m_blockSize;//�u���b�N�T�C�Y�Ŋ����ăC���f�b�N�X�Z�o
		//�y�A�T�[�V�����z�������o�b�t�@�͈̔͊O�Ȃ珈�����s�irelease�֐����Ŏ��s����̂ł��̂܂܎��s�j
		ASSERT(index >= 0 && index < m_poolBlocksNum, "CPoolAllocator::free() cannot free. Pointer is different.");
		//�y�A�T�[�V�����z�|�C���^���e�u���b�N�̐擪���w���Ă��邩�`�F�b�N
		//�@�@�@�@�@�@�@�@�ˑ��d�p���ƃL���X�g���Ă���Ƃ���邱�Ƃ���̂ł��̖��͖������ĉ�����Ă��܂�
		//ASSERT(diff % m_blockSize == 0, "CPoolAllocator::free() cannot free. Pointer is illegal.");
		//�Z�o�����C���f�b�N�X�Ń��������
		release(index);
	}
	//�R���X�g���N�^�Ăяo���@�\�t���������m��
	//��C++11�̉ϒ��e���v���[�g�p�����[�^�����p
	template<class T, typename... Tx>
	T* create(Tx... nx)
	{
		return new(*this) T(nx...);
	}
	//�f�X�g���N�^�Ăяo���@�\�t�����������
	//�������A�|�C���^�� nullptr ���Z�b�g����
	template<class T>
	void destroy(T*& p)
	{
		if (!p)
			return;
		p->~T();//�����I�ȃf�X�g���N�^�Ăяo���i�f�X�g���N�^����`�̃N���X�ł����Ȃ��j
		operator delete(p, *this);//�z�udelete�Ăяo��
		p = nullptr;//�|�C���^�ɂ�nullptr���Z�b�g
	}
public:
	//�R���X�g���N�^
	CPoolAllocator(void* pool_buff, const std::size_t block_size, const index_t pool_blocks_num) :
		m_pool(reinterpret_cast<byte*>(pool_buff)),//�v�[���o�b�t�@
		m_blockSize(block_size),//�u���b�N�T�C�Y�@��4�{���ł��邱��
		m_poolBlocksNum(pool_blocks_num)//�v�[���u���b�N��
	{
		//�y�A�T�[�V�����z�p�����[�^�`�F�b�N
		ASSERT((m_blockSize & 0x3) == 0, "CPoolAllocator::CPoolAllocator() block size is invalid.");

		//�g�p���t���O���Z�b�g
		reset();
	}
	//�f�X�g���N�^
	~CPoolAllocator()
	{}
private:
	//�t�B�[���h
	byte* m_pool;//�v�[���o�b�t�@
	const std::size_t m_blockSize;//�u���b�N�T�C�Y
	const index_t m_poolBlocksNum;//�v�[���u���b�N��
	std::atomic<index_t> m_used;//�g�p����
	index_t m_next;//���g�p�擪�C���f�b�N�X
	index_t m_recycle;//���T�C�N���C���f�b�N�X
	CSpinLock m_lock;//���b�N
};

//----------------------------------------
//�o�b�t�@�t���v�[���A���P�[�^�N���X�F�u���b�N�T�C�Y�ƃu���b�N���w��
template<std::size_t S, int N>
class CPoolAllocatorWithBuff : public CPoolAllocator
{
public:
	//�萔
	static const std::size_t BLOCK_SIZE = (S + 3) & ~3;//�u���b�N�T�C�Y
	static const index_t POOL_BLOCKS_NUM = N;//�v�[���u���b�N��
public:
	//�R���X�g���N�^
	CPoolAllocatorWithBuff() :
		CPoolAllocator(&m_poolBuff, BLOCK_SIZE, POOL_BLOCKS_NUM)
	{}
	//�f�X�g���N�^
	~CPoolAllocatorWithBuff()
	{}
private:
	//�t�B�[���h
	byte m_poolBuff[POOL_BLOCKS_NUM][BLOCK_SIZE];//�v�[���o�b�t�@
};

#if 0
//----------------------------------------
//�o�b�t�@�t���v�[���A���P�[�^�N���X�F�f�[�^�^�ƃu���b�N���w��
template<typename T, int N>
class CPoolAllocatorWithType : public CPoolAllocatorWithBuff<sizeof(T), N>
{
public:
	//�^
	typedef T data_t;//�f�[�^�^
public:
	//�萔
	static const std::size_t TYPE_SIZE = sizeof(data_t);//�^�̃T�C�Y
public:
	//�R���X�g���N�^�Ăяo���@�\�t���������m��
	//��C++11�̉ϒ��e���v���[�g�p�����[�^�����p
	template<typename... Tx>
	data_t* createData(Tx... nx)
	{
		return CPoolAllocator::create<data_t>(nx...);
	}
	//�f�X�g���N�^�Ăяo���@�\�t�����������
	//�������A�|�C���^�� nullptr ���Z�b�g����
	void destroyData(data_t*& p)
	{
		CPoolAllocator::destroy(p);
	}
public:
	//�R���X�g���N�^
	CPoolAllocatorWithType() :
		CPoolAllocatorWithBuff<TYPE_SIZE, N>()
	{}
	//�f�X�g���N�^
	~CPoolAllocatorWithType()
	{}
};
#endif

//--------------------------------------------------------------------------------
//���ʃA���P�[�^�C���^�[�t�F�[�X

//--------------------
//�������m�ۏ��
//���f�o�b�O���i�Q�Ƃ̂݁j
struct ALLOC_INFO;

//--------------------
//���ʃA���P�[�^�C���^�[�t�F�[�X�N���X
class IAllocator
{
public:
	//�萔
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//�f�t�H���g�̃A���C�������g
public:
	//���\�b�h
	virtual const char* getName() const = 0;//�A���P�[�^���擾
	virtual std::size_t getTotal() const = 0;//�S�̃������ʁ@���Q�l���i�������l�Ƃ͌���Ȃ��j
	virtual std::size_t getUsed() const = 0;//�g�p���������ʁ@���Q�l���i�������l�Ƃ͌���Ȃ��j
	virtual std::size_t getRemain() const = 0;//�c�胁�����ʁ@���Q�l���i�������l�Ƃ͌���Ȃ��j
	//�������m��
	virtual void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) = 0;
	//���������
	virtual void free(void* p) = 0;
public:
	//�f�X�g���N�^
	virtual ~IAllocator(){}
};

//--------------------
//�W���A���P�[�^�A�_�v�^�[�N���X
//��������malloc, free���g�p
class CStdAllocAdp : public IAllocator
{
public:
	//�^
	typedef CStdAllocAdp ALLOCATOR_TYPE;//�A���P�[�^�^�i�֋X�㎩�g���`�j
	typedef unsigned char byte;//�o�b�t�@�p
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CStdAllocAdp"; }//�A���P�[�^���擾
	std::size_t getTotal() const override { return 0; }//�S�̃������ʎ擾�@���W�v�s��
	std::size_t getUsed() const override { return 0; }//�g�p���������ʎ擾�@���W�v�s��
	std::size_t getRemain() const override { return 0; }//�c�胁�����ʎ擾�@���W�v�s��
public:
	//�I�y���[�^
	//��main�֐����O�ɉ�������̃������m�ۏ��������s���ꂽ�ꍇ�A
	//�@CPolyAllocator�������I�ɂ��̃N���X������������K�v�����邽�߁A
	//�@new / delete ���Z�q�ƃC���X�^���X�p�̐ÓI�o�b�t�@����������
	static void* operator new(const std::size_t) throw(){ return m_buff; }//new���Z�q
	static void operator delete(void*) throw() {}//delete���Z�q
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		//return malloc(size);//�ʏ�malloc()
	#ifdef USE_ALIGNED_MALLOC
		return _aligned_malloc(size, align);//MS�d�l�F�A���C�������g�w���malloc
	#else//USE_ALIGNED_MALLOC
		return memalign(align, size);//GCC�p�F�A���C�������g�w���malloc
	#endif//USE_ALIGNED_MALLOC
	}
	//���������
	void free(void* p) override
	{
		if (!p)
			return;
	#ifdef USE_ALIGNED_MALLOC
		_aligned_free(p);//MS�d�l�F�A���C�������g�w���free
	#else//USE_ALIGNED_MALLOC
		::free(p);//�ʏ�free() ��memalign�Ŋm�ۂ�����������free�ŉ��
	#endif//USE_ALIGNED_MALLOC
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CStdAllocAdp()
	{}
	//�f�X�g���N�^
	~CStdAllocAdp() override
	{}
private:
	//�t�B�[���h
	static byte m_buff[];
};
//�W���A���P�[�^�A�_�v�^�[�N���X�̐ÓI�ϐ��C���X�^���X��
CStdAllocAdp::byte CStdAllocAdp::m_buff[sizeof(CStdAllocAdp)];

#if 0
//--------------------
//�P��o�b�t�@�A���P�[�^�A�_�v�^�[�N���X
//���P�Ȃ�o�b�t�@��1�񂾂��A���P�[�g���邽�߂̃N���X
//������̃o�b�t�@�ɃC���X�^���X�𐶐��������ꍇ�ɗp����
class CMonoAllocAdp : public IAllocator
{
public:
	//�^
	//typedef CMonoAllocAdp ALLOCATOR_TYPE;//�A���P�[�^�^�i�A���P�[�^�Ȃ��j
	typedef unsigned char* byte;//�o�b�t�@�p
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CMonoAllocAdp"; }//�A���P�[�^���擾
	std::size_t getTotal() const override { return m_buffSize; }//�S�̃������ʎ擾
	std::size_t getUsed() const override { return m_isAllocated ? m_buffSize : 0; }//�g�p���������ʎ擾
	std::size_t getRemain() const override { return m_isAllocated ? 0 : m_buffSize; }//�c�胁�����ʎ擾
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾
	std::size_t getBuffSize() const { return m_buffSize; }//�o�b�t�@�T�C�Y�擾
	bool isAllocated() const { return m_isAllocated; }//�������m�ۍς�
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		if (m_isAllocated)
			return nullptr;
		m_isAllocated = true;//�������m�ۍς�
		return m_buffPtr;
	}
	//���������
	void free(void* p) override
	{
		if (!p)
			return;
		if (!m_isAllocated)
			return;
		m_isAllocated = false;//�������m�ۍς݉���
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CMonoAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CMonoAllocAdp(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�A�h���X
		m_buffSize(buff_size),//�o�b�t�@�T�C�Y
		m_isAllocated(false)//�������m�ۍς�
	{}
	//�f�X�g���N�^
	~CMonoAllocAdp() override
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	bool m_isAllocated;//�������m�ۍς�
};

//--------------------
//�o�b�t�@�t���P��o�b�t�@�A���P�[�^�A�_�v�^�[�e���v���[�g�N���X
template<std::size_t SIZE>
class CMonoAllocAdpWithBuff : public CMonoAllocAdp
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = SIZE;//�o�b�t�@�T�C�Y
public:
	//�R���X�g���N�^
	CMonoAllocAdpWithBuff() :
		CMonoAllocAdp(m_buff, BUFF_SIZE)
	{}
	//�f�X�g���N�^
	~CMonoAllocAdpWithBuff() override
	{}
private:
	//�t�B�[���h
	byte m_buff[BUFF_SIZE];//�o�b�t�@
};
#endif

//--------------------
//�X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�A�_�v�^�[�N���X
//���X�^�b�N�A���P�[�^�^�o�����X�^�b�N�A���P�[�^���p�̃A�_�v�^�[
class CIStackAllocAdp : public IAllocator
{
public:
	//�^
	typedef IStackAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�萔
	//���������߂�
	enum E_AUTO_REWIND
	{
		NOREWIND = 0,//�����߂��Ȃ�
		AUTO_REWIND = 1,//�w��̃X�^�b�N���Ɋ����߂�
		BOTH_AUTO_REWIND = 2,//�������Ɋ����߂��i�o�����X�^�b�N�A���P�[�^�̂݁j
	};
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CIStackAllocAdp"; }//�A���P�[�^���擾
	std::size_t getTotal() const override { return m_allocator.getTotal(); }//�S�̃������ʎ擾
	std::size_t getUsed() const override { return m_allocator.getUsed(); }//�g�p���������ʎ擾
	std::size_t getRemain() const override { return m_allocator.getRemain(); }//�c�胁�����ʎ擾
	IStackAllocator& getAllocator(){ return m_allocator; }//�A���P�[�^�擾
	const IStackAllocator& getAllocator() const { return m_allocator; }//�A���P�[�^�擾
	E_AUTO_REWIND getAutoRewind() const { m_autoRewind; }//���������߂��w��擾
	void setAutoRewind(const E_AUTO_REWIND auto_rewind){ m_autoRewind = auto_rewind; }//���������߂��w��X�V
	IStackAllocator::marker_t getRewindMarker() const { return m_rewindMarker; }//�����߂��}�[�J�[�擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		return m_allocator.alloc(size, align);//virtual�����o�[���g��
	}
	//���������
	void free(void* p) override
	{
		//�Ȃɂ����Ȃ�
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CIStackAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CIStackAllocAdp(IStackAllocator& allocator, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		m_allocator(allocator),//�X�^�b�N�A���P�[�^
		m_autoRewind(auto_rewind)//���������߂��w��
	{
		//���������߂��ʒu�L��
		m_rewindMarker = m_allocator.getMarker();
	}
	//�f�X�g���N�^
	~CIStackAllocAdp() override
	{
		//���������߂�
		if (m_autoRewind == AUTO_REWIND)
		{
			m_allocator.back(m_rewindMarker);
		}
	}
protected:
	//�t�B�[���h
	IStackAllocator& m_allocator;//�X�^�b�N�A���P�[�^
	E_AUTO_REWIND m_autoRewind;//���������߂��w��
	IStackAllocator::marker_t m_rewindMarker;//�����߂��}�[�J�[
};

//--------------------
//�X�^�b�N�A���P�[�^�A�_�v�^�[�N���X
//���X�^�b�N�A���P�[�^�p�̃A�_�v�^�[
class CStackAllocAdp : public CIStackAllocAdp
{
public:
	//�^
	typedef CStackAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CStackAllocAdp"; }//�A���P�[�^���擾
	CStackAllocator& getAllocator(){ return *static_cast<CStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	const CStackAllocator& getAllocator() const { return *static_cast<CStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CStackAllocator& allocator = getAllocator();
		return allocator.allocN(size, align);//��virtual�����o�[���g��
	}
	//���������
	void free(void* p) override
	{
		//�Ȃɂ����Ȃ�
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CStackAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CStackAllocAdp(CStackAllocator& allocator, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		CIStackAllocAdp(allocator, auto_rewind)//�X�^�b�N�A���P�[�^
	{}
	//�f�X�g���N�^
	~CStackAllocAdp() override
	{}
};

#if 0
//--------------------
//�o�����X�^�b�N�A���P�[�^�A�_�v�^�[�N���X
class CDualStackAllocAdp : public CIStackAllocAdp
{
public:
	//�^
	typedef CDualStackAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CDualStackAllocAdp"; }//�A���P�[�^���擾
	CDualStackAllocator& getAllocator(){ return *static_cast<CDualStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	const CDualStackAllocator& getAllocator() const { return *static_cast<CDualStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	IStackAllocator::E_ORDERED getOrdered() const { return m_ordered; }//�X�^�b�N���擾
	void setOrdered(const IStackAllocator::E_ORDERED ordered){ m_ordered = ordered; }//�X�^�b�N���X�V
	IStackAllocator::marker_t getRewindMarkerN() const { return m_rewindMarker; }//�����߂��}�[�J�[�i�����j�擾
	IStackAllocator::marker_t getRewindMarkerR() const { return m_rewindMarkerR; }//�����߂��}�[�J�[�i�t���j�擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CDualStackAllocator& allocator = getAllocator();
		return allocator.alloc(m_ordered, size, align);//��virtual�����o�[���g��
	}
	//���������
	void free(void* p) override
	{
		//�Ȃɂ����Ȃ�
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CDualStackAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CDualStackAllocAdp(CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		CIStackAllocAdp(allocator, auto_rewind),//�o�����X�^�b�N�A���P�[�^
		m_ordered(ordered)//�X�^�b�N��
	{
		//���������߂��ʒu�L��
		m_rewindMarker = allocator.getMarkerN();//����
		m_rewindMarkerR = allocator.getMarkerR();//�t��
	}
	//�f�X�g���N�^
	~CDualStackAllocAdp() override
	{
		//���������߂�
		if (m_autoRewind == BOTH_AUTO_REWIND)
		{
			//�������̊����߂�
			CDualStackAllocator& allocator = getAllocator();
			allocator.backN(m_rewindMarker);//����
			allocator.backR(m_rewindMarkerR);//�t��
		}
		else if (m_autoRewind == AUTO_REWIND)
		{
			//�P�����̊����߂�
			CDualStackAllocator& allocator = getAllocator();
			if (m_ordered == IStackAllocator::NORMAL)//�����X�^�b�N�̂�
				allocator.backN(m_rewindMarker);
			else if (m_ordered == IStackAllocator::REVERSE)//�t���X�^�b�N�̂�
				allocator.backR(m_rewindMarkerR);
			else//if (m_ordered == IStackAllocator::DEFAULT)//�A���P�[�^�̃f�t�H���g�X�^�b�N���ɏ]��
			{
				//	allocator.backD(m_rewindMarker);//���̃��\�b�h�͎g��Ȃ�
				if (allocator.getDefaultOrdered() == IStackAllocator::REVERSE)//�t���X�^�b�N�̂�
					allocator.backR(m_rewindMarkerR);
				else//if (allocator.getDefaultOrdered() == IStackAllocator::NORMAL)//�����X�^�b�N�̂�
					allocator.backN(m_rewindMarker);
			}
		}
		m_autoRewind = NOREWIND;//�e�N���X�̃f�X�g���N�^�����Ŗ�肪�N����Ȃ��悤�ɐݒ�𖳌�������
	}
private:
	//�t�B�[���h
	IStackAllocator::E_ORDERED m_ordered;//�X�^�b�N��
	//IStackAllocator::marker_t m_rewindMarker;//�����߂��}�[�J�[�i�����j���e�N���X�̕ϐ����g�p
	IStackAllocator::marker_t m_rewindMarkerR;//�����߂��}�[�J�[�i�t���j
};
#endif

#if 0
//--------------------
//�X�}�[�g�X�^�b�N�A���P�[�^�A�_�v�^�[�N���X
class CSmartStackAllocAdp : public CIStackAllocAdp
{
public:
	//�^
	typedef CSmartStackAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�A�N�Z�b�T
	const char* getName() const override{ return "CSmartStackAllocAdp"; }//�A���P�[�^���擾
	CSmartStackAllocator& getAllocator(){ return *static_cast<CSmartStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	const CSmartStackAllocator& getAllocator() const { return *static_cast<CSmartStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	IStackAllocator::E_ORDERED getOrdered() const { return m_ordered; }//�X�^�b�N���擾
	void setOrdered(const IStackAllocator::E_ORDERED ordered){ m_ordered = ordered; }//�X�^�b�N���X�V
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CSmartStackAllocator& allocator = getAllocator();
		return allocator.alloc(m_ordered, size, align);//��virtual�����o�[���g��
	}
	//���������
	void free(void* p) override
	{
		CSmartStackAllocator& allocator = getAllocator();
		return allocator.free(p);
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CSmartStackAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	//�����������߂��ɂ͑Ή����Ȃ�
	CSmartStackAllocAdp(CSmartStackAllocator& stack, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) :
		CIStackAllocAdp(stack, NOREWIND),//�X�}�[�g�X�^�b�N�A���P�[�^
		m_ordered(ordered)//�X�^�b�N��
	{}
	//�f�X�g���N�^
	~CSmartStackAllocAdp() override
	{}
private:
	//�t�B�[���h
	IStackAllocator::E_ORDERED m_ordered;//�X�^�b�N��
};
#endif

//--------------------
//�v�[���A���P�[�^�A�_�v�^�[�N���X
class CPoolAllocAdp : public IAllocator
{
public:
	//�^
	typedef CPoolAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CPoolAllocAdp"; }//�A���P�[�^���擾
	std::size_t getTotal() const override { return m_allocator.getBlocksNum() * m_allocator.getBlockSize(); }//�S�̃������ʎ擾
	std::size_t getUsed() const override { return m_allocator.getUsed() * m_allocator.getBlockSize(); }//�g�p���������ʎ擾
	std::size_t getRemain() const override { return m_allocator.getRemain() * m_allocator.getBlockSize(); }//�c�胁�����ʎ擾
	CPoolAllocator& getAllocator() const { return m_allocator; }//�A���P�[�^�擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		return m_allocator.alloc(size);
	}
	//���������
	void free(void* p) override
	{
		return m_allocator.free(p);
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CPoolAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CPoolAllocAdp(CPoolAllocator& allocator) :
		m_allocator(allocator)//�v�[���A���P�[�^
	{}
	//�f�X�g���N�^
	~CPoolAllocAdp() override
	{}
private:
	//�t�B�[���h
	CPoolAllocator& m_allocator;//�v�[���A���P�[�^
};

//--------------------------------------------------------------------------------
//�O���[�o��new/delete + ���ʃA���P�[�^�C���^�[�t�F�[�X

//--------------------
//�N���X�錾
class CTempPolyAllocatorBase;//�ꎞ���ԃA���P�[�^���N���X

//--------------------
//���ԃA���P�[�^
class CPolyAllocator
{
#ifdef USE_FRIEND_WITH_NEW_OPERATOR
	//�W�� new / deleete ���Z�q���t�����h��
	//������ CPolyAllocator �N���X�𒼐ڃC���X�^���X������̂� new / delete ���Z�q�̂�
	friend void* operator new(const std::size_t size) throw();
	friend void* operator new[](const std::size_t size) throw();
	friend void operator delete(void* p) throw();
	friend void operator delete[](void* p) throw();
#endif//USE_FRIEND_WITH_NEW_OPERATOR
	friend class CTempPolyAllocatorBase;//�ꎞ���ԃA���P�[�^���N���X
public:
	//�I�y���[�^
	IAllocator* operator->(){ return m_allocator; }//�A���[���Z�q�i�v���L�V�[�j
public:
	//�A�N�Z�b�T
	//�A���P�[�^�擾
	static IAllocator* getAllocator()
	{
		return m_allocator;
	}
	//�A���P�[�^�ύX
	//���߂�Ƃ��ĕύX�O�̃A���P�[�^��Ԃ�
	//���Ȃ�ׂ����ڎg�p�֎~��CTempPoly***Allocator�N���X���g���A�R���X�g���N�^�Ŏ����I�Ɍ��ɖ߂�
	static IAllocator* setAllocator(IAllocator& new_allocator)
	{
		IAllocator* prev_allocator = m_allocator;//�ύX�O�̃A���P�[�^�擾
		m_allocator = &new_allocator;//�A���P�[�^�ύX
		return prev_allocator;//�ύX�O�̃A���P�[�^��Ԃ�
	}
	//�������m�ۏ��擾
	static const ALLOC_INFO* getAllocInfo()
	{
		return m_allocInfo;
	}
	//�������m�ۏ��擾�Ɠ����ɏ���j��
	static const ALLOC_INFO* getAllocInfoWithReset()
	{
		const ALLOC_INFO* info = m_allocInfo;
		m_allocInfo = nullptr;
		return info;
	}
	//�������m�ۏ����Z�b�g
	static void setAllocInfo(const ALLOC_INFO* info)
	{
		m_allocInfo = info;
	}
#ifdef USE_FRIEND_WITH_NEW_OPERATOR
private://���ڃC���X�^���X�����s�i�t�����h��p�j
#else//USE_FRIEND_WITH_NEW_OPERATOR
public:
#endif//USE_FRIEND_WITH_NEW_OPERATOR
	//�f�t�H���g�R���X�g���N�^
	CPolyAllocator()
	{
		if (!m_allocator)//�܂����̃A���P�[�^���ێ����Ă��Ȃ��ꍇ�W���A���P�[�^�������I�ɕێ�����
			m_allocator = new CStdAllocAdp();//�W���A���P�[�^�𖾎��I�ɏ������i�N���X��new���g�p�j
	}
public:
	//�f�X�g���N�^
	~CPolyAllocator()
	{}
protected:
	//�t�B�[���h
	static thread_local IAllocator* m_allocator;//���݂̃A���P�[�^
	static thread_local const ALLOC_INFO* m_allocInfo;//���݂̃������m�ۏ��
	//TLS�𗘗p���A�A���P�[�^�̕ύX�����̃X���b�h�ɉe�����Ȃ��悤�ɂ���
};
//--------------------
//���ԃA���P�[�^�̐ÓI�ϐ��C���X�^���X��
thread_local IAllocator* CPolyAllocator::m_allocator = nullptr;//���݂̃A���P�[�^
thread_local const ALLOC_INFO* CPolyAllocator::m_allocInfo = nullptr;//���݂̃������m�ۏ��

//--------------------
//�������m�ۏ��
//���f�o�b�O���i�Q�Ƃ̂݁j
struct ALLOC_INFO
{
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//�f�t�H���g�̃A���C�������g�T�C�Y
	const char* m_fileName;//�t�@�C����
	const char* m_funcName;//�֐���
	const char* m_callPointName;//�R�[���|�C���g��
	float m_time;//�Q�[������
	const char* m_typeName;//�^��
	std::size_t m_align;//�A���C�������g�T�C�Y
	ALLOC_INFO(const char* file_name, const char* func_name, const char* call_point_name, const float time, const char* type_name, const std::size_t align = DEFAULT_ALIGN) :
		m_fileName(file_name),
		m_funcName(func_name),
		m_callPointName(call_point_name),
		m_time(time),
		m_typeName(type_name),
		m_align(align)
	{}
};

//--------------------
//�O���[�o�����ԃA���P�[�^
//���W��new / delete ���Z�q�̒u������
//new
void* operator new(const std::size_t size) throw()
{
	CPolyAllocator allocator;
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//�������m�ۏ��擾
	if (info)
		align = info->m_align;
	void* p = allocator->alloc(size, align);
	return p;
}
//�z���
void* operator new[](const std::size_t size) throw()
{
	CPolyAllocator allocator;
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//�������m�ۏ��擾
	if (info)
		align = info->m_align;
	void* p = allocator->alloc(size, align);
	return p;
}
//delete
void operator delete(void* p) throw()
{
	CPolyAllocator allocator;
	allocator->free(p);
}
//�z���
void operator delete[](void* p) throw()
{
	CPolyAllocator allocator;
	allocator->free(p);
}

#if 0
//--------------------
//�f�o�b�O�����W�p�֐��Q��
const char* getCurrentCallPointNameDummy();//�R�[���|�C���g���擾
float getGameTimeDummy();//�Q�[�����Ԏ擾

//--------------------
//�������m�ۏ��t��NEW����
template<class T, typename... Tx>
T* newWithInfo(const char* file_name, const char* func_name, const std::size_t align, Tx ...nx)
{
	const char* call_point_name = getCurrentCallPointNameDummy();//�R�[���|�C���g���擾
	const float game_time = getGameTimeDummy();//�Q�[�����Ԏ擾
	const ALLOC_INFO info(file_name, func_name, call_point_name, game_time, typeid(T).name(), align);//�������m�ۏ�񐶐�
	CPolyAllocator::setAllocInfo(&info);//�������m�ۏ��󂯓n�� �����[�J���ϐ��̃|�C���^���󂯓n�����ƂɂȂ邪�A�㑱�̏����ł̂ݎQ�Ƃ��邱�ƂƁATLS�ŕی삳��邽�ߖ��Ȃ�
	return new T(nx...);//�������m��
}
//�z���
//���y���_�z�z��new�ɃA���C�������g���w�肳�ꂽ�ꍇ�A�������|�C���^���v�Z������Ȃ����߁A�A���C�������g�w��ɑΉ����Ȃ�
template<class T, std::size_t array_size>
T* newArrayWithInfo(const char* file_name, const char* func_name)
{
	const char* call_point_name = getCurrentCallPointNameDummy();//�R�[���|�C���g���擾
	const float game_time = getGameTimeDummy();//�Q�[�����Ԏ擾
	const ALLOC_INFO info(file_name, func_name, call_point_name, game_time, typeid(T[array_size]).name());//�������m�ۏ�񐶐�
	CPolyAllocator::setAllocInfo(&info);//�������m�ۏ��󂯓n�� �����[�J���ϐ��̃|�C���^���󂯓n�����ƂɂȂ邪�A�㑱�̏����ł̂ݎQ�Ƃ��邱�ƂƁATLS�ŕی삳��邽�ߖ��Ȃ�
	return new T[array_size];//�������m��
}

//--------------------
//NEW�}�N��
//���������m�ۏ��t��
#define NEW(T, ...) newWithInfo<T>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME(), ALLOC_INFO::DEFAULT_ALIGN, ##__VA_ARGS__)//NEW
#define NEWALIGN(T, align, ...) newWithInfo<T>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME(), align, ##__VA_ARGS__)//�A���C�������g�w��t��NEW
#define NEWARR(T, array_size) newArrayWithInfo<T, array_size>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME())//�z��NEW
//#define NEWALIGNARR(T, align, array_size)//�A���C�����g�w��t���z��NEW�͐��m�Ɍv�Z�ł��Ȃ��̂őΉ����Ȃ�
//--------------------
//DELETE�}�N��
#ifdef DELETE
#undef DELETE
#endif//DELETE
#define DELETE delete//DELETE
#define DELETEARR delete[]//�z��DELETE
#endif

//--------------------
//�ꎞ���ԃA���P�[�^
//�����ԃA���P�[�^�́u���݂̃A���P�[�^�v���ꎞ�I�ɕύX���邽�߂̃N���X
//�������u���b�N�𔲂��鎞�ɁA�f�X�g���N�^�Ŏ����I�Ɍ��̏�Ԃɖ߂�

//--------------------
//�ꎞ���ԃA���P�[�^���N���X
//���p����p�N���X
class CTempPolyAllocatorBase : public CPolyAllocator
{
protected://���ڃC���X�^���X�����s�i�p����p�j
	//�f�t�H���g�R���X�g���N�^
	CTempPolyAllocatorBase() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyAllocatorBase(IAllocator& allocator) :
		CPolyAllocator()
	{
		m_prevAllocator = setAllocator(allocator);//�A���P�[�^��ύX���āA�ύX�O�̃A���P�[�^���L��
	}
public:
	//�f�X�g���N�^
	~CTempPolyAllocatorBase()
	{
		if (m_prevAllocator)
		{
			m_allocator = m_prevAllocator;//�ύX�O�̃A���P�[�^�ɖ߂�
			m_prevAllocator = nullptr;
		}
	}
private:
	//�t�B�[���h
	IAllocator* m_prevAllocator;//�ύX�O�̃A���P�[�^
};
//--------------------
//�ꎞ���ԃA���P�[�^�e���v���[�g�N���X�F�A�_�v�^�[�ێ��^�C�v
template<class ADAPTER>
class CTempPolyAllocatorWithAdp : public CTempPolyAllocatorBase
{
public:
	//�^
	typedef ADAPTER ADAPTER_TYPE;//�A�_�v�^�[�^
	typedef typename ADAPTER::ALLOCATOR_TYPE ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyAllocatorWithAdp() :
		m_adapter(),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//�R���X�g���N�^
	CTempPolyAllocatorWithAdp(ALLOCATOR_TYPE& allocator) :
		m_adapter(allocator),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//�f�X�g���N�^
	~CTempPolyAllocatorWithAdp()
	{}
protected:
	//�t�B�[���h
	ADAPTER_TYPE m_adapter;//�A���P�[�^�A�_�v�^�[
};
//--------------------
//�ꎞ���ԃA���P�[�^�e���v���[�g�N���X�F�A�_�v�^�[���ڗ��p�^�C�v
//���A�_�v�^�[��ێ������O������󂯓n�������̂����̂܂ܗ��p����
template<class ADAPTER>
class CTempPolyAllocatorDirect : public CTempPolyAllocatorBase
{
public:
	//�^
	typedef ADAPTER ADAPTER_TYPE;//�A�_�v�^�[�^
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyAllocatorDirect() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyAllocatorDirect(ADAPTER_TYPE& adapter) :
		CTempPolyAllocatorBase(adapter)
	{}
	//�f�X�g���N�^
	~CTempPolyAllocatorDirect()
	{}
};
//--------------------
//�ꎞ���ԃA���P�[�^�e���v���[�g�N���X�F�X�^�b�N�A���P�[�^�A�_�v�^�[�ێ��^�C�v
template<class ADAPTER>
class CTempPolyAllocatorWithStackAdp : public CTempPolyAllocatorBase
{
public:
	//�^
	typedef ADAPTER ADAPTER_TYPE;//�A�_�v�^�[�^
	typedef typename ADAPTER::ALLOCATOR_TYPE ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyAllocatorWithStackAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind) :
		m_adapter(allocator, auto_rewind),
		CTempPolyAllocatorBase(m_adapter)
	{}
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const IStackAllocator::E_ORDERED ordered, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind) :
		m_adapter(allocator, ordered, auto_rewind),
		CTempPolyAllocatorBase(m_adapter)
	{}
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const IStackAllocator::E_ORDERED ordered) :
		m_adapter(allocator, ordered),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//�f�X�g���N�^
	~CTempPolyAllocatorWithStackAdp()
	{}
protected:
	//�t�B�[���h
	ADAPTER_TYPE m_adapter;//�A���P�[�^�A�_�v�^�[
};
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�W���A���P�[�^�p
using CTempPolyStdAllocator = CTempPolyAllocatorWithAdp<CStdAllocAdp>;//C++11�`��
#if 0
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�P��o�b�t�@�A���P�[�^�p
using CTempPolyMonoAllocator = CTempPolyAllocatorDirect<CMonoAllocAdp>;//C++11�`��
#endif
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�p
class CTempPolyIStackAllocator : public CTempPolyAllocatorWithStackAdp<CIStackAllocAdp>
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyIStackAllocator() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyIStackAllocator(IStackAllocator& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CIStackAllocAdp>(allocator, auto_rewind)
	{}
	//�f�X�g���N�^
	~CTempPolyIStackAllocator()
	{}
};
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�X�^�b�N�A���P�[�^�p
class CTempPolyStackAllocator : public CTempPolyAllocatorWithStackAdp<CStackAllocAdp>
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyStackAllocator() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyStackAllocator(CStackAllocator& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CStackAllocAdp>(allocator, auto_rewind)
	{}
	//�f�X�g���N�^
	~CTempPolyStackAllocator()
	{}
};
#if 0
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�o�����X�^�b�N�A���P�[�^�p
class CTempPolyDualStackAllocator : public CTempPolyAllocatorWithStackAdp<CDualStackAllocAdp>
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyDualStackAllocator() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyDualStackAllocator(CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CDualStackAllocAdp>(allocator, ordered, auto_rewind)
	{}
	//�f�X�g���N�^
	~CTempPolyDualStackAllocator()
	{}
};
#endif
#if 0
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�X�}�[�g�X�^�b�N�A���P�[�^�p
class CTempPolySmartStackAllocator : public CTempPolyAllocatorWithStackAdp<CSmartStackAllocAdp>
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolySmartStackAllocator() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolySmartStackAllocator(CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) :
		CTempPolyAllocatorWithStackAdp<CSmartStackAllocAdp>(allocator, ordered)
	{}
	//�f�X�g���N�^
	~CTempPolySmartStackAllocator()
	{}
};
#endif
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�v�[���A���P�[�^�p
using CTempPolyPoolAllocator = CTempPolyAllocatorWithAdp<CPoolAllocAdp>;//C++11�`��

//--------------------------------------------------------------------------------
//�ȈՃv���t�@�C��
namespace dbg
{
	//----------------------------------------
	//�v���t�@�C���N���X
	class CProfiler
	{
	public:
		//�萔
		static const std::size_t BUFF_SIZE = 64 * 1024;//�L�^�p�̃o�b�t�@
	public:
		//�^
		typedef CStackAllocatorWithBuff<BUFF_SIZE> buffer_t;//�o�b�t�@�^
		typedef uintptr_t key_t;//�L�[�^
		//�v���t�@�C��
		struct PROFILE
		{
			key_t m_key;//�L�[
			std::string m_name;//������
			THREAD_ID m_threadId;//�X���b�hID
			std::string m_threadName;//�X���b�h��
			std::string m_srcFileName;//�\�[�X�t�@�C����
			std::string m_funcName;//�֐���
			struct TIME
			{
				double sum;//�������Ԃ̍��v
				float max;//�ő�̏�������
				float min;//�ŏ��̏�������
				int count;//�v����
				float average() const { return count == 0 ? 0 : static_cast<float>(sum / static_cast<double>(count)); }
				//�v�����ԏW�v
				void add(const double time)
				{
					++count;
					sum += time;
					const float time_f = static_cast<float>(time);
					if (max == 0.f || max < time_f)
						max = time_f;
					if (min == 0.f || min > time_f)
						min = time_f;
				}
				//�v�����ԏW�v
				void add(const TIME& time)
				{
					count += time.count;
					sum += time.sum;
					if (max == 0.f || max < time.max)
						max = time.max;
					if (min == 0.f || min > time.min)
						min = time.min;
				}
				//�v�����ԃ��Z�b�g
				void reset()
				{
					sum = 0.;
					max = 0.f;
					min = 0.f;
					count = 0;
				}
				//�R�s�[���Z�q
				TIME& operator=(TIME& rhs)
				{
					memcpy(this, &rhs, sizeof(*this));
					return *this;
				}
			};
			TIME m_total;//�����S�̂̏W�v
			TIME m_frame;//�t���[�����̏W�v
			bool m_inCountOnFrame;//�t���[���̏W�v�����������H
			int m_frameCount;//�v���t���[����
			float m_time;//�i�O��v�����́j��������
			//�v�����Ԃ����Z
			void add(const double time)
			{
				m_time = static_cast<float>(time);
				m_frame.add(time);
				m_inCountOnFrame = true;
			}
			//�t���[���W�v
			void sumOnFrame()
			{
				if (m_inCountOnFrame)
				{
					m_inCountOnFrame = false;
					m_total.add(m_frame);
					m_frame.reset();
					++m_frameCount;
				}
			}
			//���[�u�R���X�g���N�^
			//���v�f�ǉ��̍ۂ̖��ʂȃI�u�W�F�N�g�����Ɣj����h��
			//�@�istd::string�����̑Ώ��Fstd::move()���g���Ď󂯓n���j
			PROFILE(PROFILE&& src) :
				m_key(src.m_key),
				m_name(std::move(src.m_name)),
				m_threadId(src.m_threadId),
				m_threadName(std::move(src.m_threadName)),
				m_srcFileName(std::move(src.m_srcFileName)),
				m_funcName(std::move(src.m_funcName)),
				m_inCountOnFrame(src.m_inCountOnFrame),
				m_frameCount(src.m_frameCount),
				m_time(src.m_time)
			{
				m_total = src.m_total;
				m_frame = src.m_frame;
			}
			//�R���X�g���N�^
			PROFILE(const key_t key, const char* name, const THREAD_ID thread_id, const char* thread_name, const char* src_file_name, const char* func_name) :
				m_key(key),
				m_name(name),
				m_threadId(thread_id),
				m_threadName(thread_name),
				m_srcFileName(src_file_name),
				m_funcName(func_name),
				m_inCountOnFrame(false),
				m_frameCount(0),
				m_time(0.f)
			{
				m_total.reset();
				m_frame.reset();
			}
		};
		typedef std::unordered_map<key_t, PROFILE> table_t;//�n�b�V���e�[�u���^
		typedef table_t::iterator iterator;//�C�e���[�^�^
		typedef table_t::const_iterator const_iterator;//�C�e���[�^�^
	public:
		//�A�N�Z�b�T
		std::size_t getBuffTotal()const{ return m_buff.getTotal(); }
		std::size_t getBuffUsed()const{ return m_buff.getUsed(); }
		std::size_t getBuffRemain()const{ return m_buff.getRemain(); }
	public:
		//���\�b�h
		//�v���t�@�C���ǉ��^�W�v
		void addProfile(const key_t key, const char* name, const CThreadID* thread_id, const char* src_file_name, const char* func_name, const double time)
		{
			m_lock.lock();
			THREAD_ID thread_id_ = INITIAL_THREAD_ID;
			const char* thread_name = "(unknown)";
			if (thread_id)
			{
				thread_id_ = thread_id->getID();
				thread_name = thread_id->getName();
			}
			CTempPolyStackAllocator allocator(m_buff);
			PROFILE* profile = nullptr;
			{
				table_t::iterator ite = m_table->find(key);
				if (ite != m_table->end())
					profile = &ite->second;
				else
				{
					m_table->emplace(key, std::move(PROFILE(key, name, thread_id_, thread_name, src_file_name, func_name)));
					ite = m_table->find(key);
					if (ite != m_table->end())
						profile = &ite->second;
				}
			}
			if (profile)
			{
				profile->add(time);
			}
			m_lock.unlock();
		}
		//�t���[���W�v
		void sumOnFrame()
		{
			m_lock.lock();
			for (auto& ite : *m_table)
			{
				PROFILE* profile = &ite.second;
				profile->sumOnFrame();
			}
			m_lock.unlock();
		}
		//�C�e���[�^�擾
		std::size_t size() const { return m_table->size(); }
		//table_t::iterator begin() { return m_table->begin(); }
		//table_t::iterator end() { return m_table->end(); }
		table_t::const_iterator begin() const { return m_table->begin(); }
		table_t::const_iterator end() const { return m_table->end(); }
		table_t::const_iterator cbegin() const { return m_table->cbegin(); }
		table_t::const_iterator cend() const { return m_table->cend(); }
		//�e�[�u������
		void createTable()
		{
			m_lock.lock();
			if (!m_table)
			{
				CTempPolyStackAllocator allocator(m_buff);
				m_table = new table_t();
				m_table->reserve(1024);
			}
			m_lock.unlock();
		}
		//�e�[�u���j��
		void destroyTable()
		{
			m_lock.lock();
			if (m_table)
			{
				CTempPolyStackAllocator allocator(m_buff);
				delete m_table;
				m_table = nullptr;
				m_buff.clearN();
			}
			m_lock.unlock();
		}
		//�e�[�u�������Z�b�g
		void resetTable()
		{
			destroyTable();
			createTable();
		}
	public:
		//�R���X�g���N�^
		CProfiler()
		{
			createTable();
		}
		//�f�X�g���N�^
		~CProfiler()
		{
		}
	private:
		//�t�B�[���h
		static table_t* m_table;//�n�b�V���e�[�u��
		static buffer_t m_buff;//�L�^�p�o�b�t�@
		static CSpinLock m_lock;//���b�N
	};
	//----------------------------------------
	//�v���t�@�C���̐ÓI�ϐ����C���X�^���X��
	CProfiler::table_t* CProfiler::m_table;//�n�b�V���e�[�u��
	CProfiler::buffer_t CProfiler::m_buff;//�L�^�p�o�b�t�@
	CSpinLock CProfiler::m_lock;//���b�N
}//dbg

//--------------------------------------------------------------------------------
//�f�o�b�O���b�Z�[�W
namespace dbg
{
	//----------------------------------------
	//�R���\�[���J���[�N���X
	class color
	{
	public:
		//�^
		//�n���h���^
	#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
		typedef HANDLE handle_t;
	#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
		typedef FILE* handle_t;
	#endif//USE_WINDOWS_CONSOLE_COLOR
	public:
		//�萔
		//�J���[�l
		enum color_t : unsigned char
		{
			reset = 0x10,//���Z�b�g
			through = 0x20,//�X���[�i����ێ��F�������Ȃ��j

		#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
			R = 0x04,//Red:��
			G = 0x02,//Green:��
			B = 0x01,//Blue:��
			I = 0x08,//Intensity:�N�₩
			BG_SHIFT = 4,//�w�i�F�w�莞�̃r�b�g�V�t�g��
		#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
			R = 0x01,//Red:��
			G = 0x02,//Green:��
			B = 0x04,//Blue:��
			I = 0x08,//high Intensity:�N�₩
		#endif//USE_WINDOWS_CONSOLE_COLOR

			RGB = 0x07,//RGB�}�X�N
			RGBI = 0x0f,//RGB+I�}�X�N

			//�W���J���[
			black = 0,//��
			blue = B,//��
			red = R,//��
			magenta = R | B,//��
			green = G,//��
			cyan = G | B,//��
			yellow = G | R,//��
			white = G | R | B,//��

			//�N�₩�ȃJ���[
			iBlack = I | black,//��
			iBlue = I | blue,//��
			iRed = I | red,//��
			iMagenta = I | magenta,//��
			iGreen = I | green,//��
			iCyan = I | cyan,//��
			iYellow = I | yellow ,//��
			iWhite = I | white,//��
		};
		//�Ώ�
		enum target_t : unsigned char
		{
			stdOut = 0,//�ΏہF�W���o��
			stdErr = 1,//�ΏہF�W���G���[
		};
		static const int targetNum = 2;
	public:
		//�A�N�Z�b�T
		target_t getTarget() const { return m_target; }//�Ώ�
		color_t getForeColor() const { return m_foreColor; }//�J���[�F�O��
		color_t getBackColor() const { return m_backColor; }//�J���[�F�w��
		color_t getPrevForeColor() const { return m_prevForeColor; }//�O�̃J���[:�O��
		color_t getPrevBackColor() const { return m_prevBackColor; }//�O�̃J���[:�w��
		bool isAutoRestore() const { return m_isAutoRestore; }//�����J���[�������s�w��
	public:
		//�L���X�g�I�y���[�^
		operator int() const { return static_cast<int>(m_target); }//�Ώ�
		operator target_t() const { return m_target; }//�Ώ�
	public:
		//���\�b�h
		//�J���[�ύX
		//�����ۂɃR���\�[���ɔ��f������
		void changeColor()
		{
			if (m_foreColor == through)
				return;
			changeColor(m_target, m_foreColor, m_backColor);
		}
		void changeColor(const target_t target, const color_t fore_color, const color_t back_color = black)
		{
			//�Ώۃn���h���擾
			const handle_t target_h = m_handle[target];

			//�J���[�ύX
			if (fore_color == reset)
			{
			#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
				SetConsoleTextAttribute(target_h, m_ConsoleScreenBufferInfo[target].wAttributes);
			#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
				fprintf(target_h, "\x1b[39m\x1b[49m");//"\x1b[0m"
			#endif//USE_WINDOWS_CONSOLE_COLOR
			}
			else
			{
			#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
				SetConsoleTextAttribute(target_h, ((back_color & RGBI) << BG_SHIFT) | (fore_color & RGBI));
			#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
				fprintf(target_h, "\x1b[%dm\x1b[%dm", (fore_color & I ? 90 : 30) + (fore_color & RGB), (back_color & I ? 100 : 40) + (back_color & RGB));
			#endif//USE_WINDOWS_CONSOLE_COLOR
			}
		}
	public:
		//�J���[�������i������j
		static void initializeOnce();
	public:
		//�f�t�H���g�R���X�g���N�^
		color() :
			m_target(stdOut),//�Ώ�
			m_foreColor(reset),//�J���[�F�O��
			m_backColor(reset),//�J���[�F�w��
			m_prevForeColor(reset),//�O�̃J���[�F�O�ʂ��L��
			m_prevBackColor(reset),//�O�̃J���[�F�w�ʂ��L��
			m_isAutoRestore(false)//�����J���[�������s�w��
		{
			initializeOnce();
		}
		//���[�u�R���X�g���N�^
		color(color&& src) :
			m_target(src.m_target),//�Ώ�
			m_foreColor(src.m_foreColor),//�J���[�F�O��
			m_backColor(src.m_backColor),//�J���[�F�w��
			m_prevForeColor(src.m_prevForeColor),//�O�̃J���[�F�O�ʂ��L��
			m_prevBackColor(src.m_prevBackColor),//�O�̃J���[�F�w�ʂ��L��
			m_isAutoRestore(src.m_isAutoRestore)//�����J���[�������s�w��
		{
			//���[�u�R���X�g���N�^�ɂ��A�ړ����̓��e�����ς��A�f�X�g���N�^���@�\���Ȃ��悤�ɂ���
			*const_cast<bool*>(&src.m_isAutoRestore) = false;//�����J���[�������s�w��𖳌���
		}
		//�R���X�g���N�^
		color(const target_t target, const color_t fore_color, const color_t back_color = black, const bool is_auto_restore = true) :
			m_target(target),//�Ώ�
			m_foreColor(fore_color),//�J���[�F�O��
			m_backColor(back_color),//�J���[�F�w��
			m_prevForeColor(m_nowForeColor[m_target]),//�O�̃J���[�F�O�ʂ��L��
			m_prevBackColor(m_nowBackColor[m_target]),//�O�̃J���[�F�w�ʂ��L��
			m_isAutoRestore(is_auto_restore)//�����J���[�������s�w��
		{
			if (m_foreColor == through || !m_isAutoRestore)
				return;
			m_nowForeColor[m_target] = m_foreColor;//���݂̃J���[�F�O�ʁi�L���p�j���X�V
			m_nowBackColor[m_target] = m_backColor;//���݂̃J���[�F�w�ʁi�L���p�j���X�V
			changeColor();
		}
		//�f�X�g���N�^
		~color()
		{
			if (m_foreColor == through || !m_isAutoRestore)
				return;
			m_nowForeColor[m_target] = m_prevForeColor;//���݂̃J���[�F�O�ʂ�O�̃J���[�ɖ߂�
			m_nowBackColor[m_target] = m_prevBackColor;//���݂̃J���[�F�w�ʂ�O�̃J���[�ɖ߂�
			changeColor(m_target, m_prevForeColor, m_prevBackColor);
		}
	private:
		//�t�B�[���h
		const target_t m_target;//�Ώ�
		const color_t m_foreColor;//�J���[�F�O��
		const color_t m_backColor;//�J���[�F�w��
		const color_t m_prevForeColor;//�O�̃J���[�F�O��
		const color_t m_prevBackColor;//�O�̃J���[�F�w��
		const bool m_isAutoRestore;//�����J���[�������s�w��
		static bool m_isInitialized;//�������ς�
		static color_t m_nowForeColor[color::targetNum];//���݂̃J���[�F�O�ʁi�L���p�j
		static color_t m_nowBackColor[color::targetNum];//���݂̃J���[�F�w�ʁi�L���p�j
	#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
		static handle_t m_handle[color::targetNum];//�n���h��
		static CONSOLE_SCREEN_BUFFER_INFO m_ConsoleScreenBufferInfo[color::targetNum];//�R���\�[���X�N���[���o�b�t�@�i���Z�b�g�p�j
	#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p	
		static const handle_t m_handle[color::targetNum];//�n���h��
	#endif//USE_WINDOWS_CONSOLE_COLOR
	};
	//----------------------------------------
	//�J���[�̐ÓI�ϐ����C���X�^���X��
	bool color::m_isInitialized = false;
	color::color_t color::m_nowForeColor[color::targetNum] =//���݂̃J���[�F�O�ʁi�L���p�j
	{
		color::reset,//�W���o�͗p
		color::reset,//�W���G���[�p
	};
	color::color_t color::m_nowBackColor[color::targetNum] =//���݂̃J���[�F�w�ʁi�L���p�j
	{
		color::reset,//�W���o�͗p
		color::reset,//�W���G���[�p
	};
#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
	color::handle_t color::m_handle[color::targetNum];
	CONSOLE_SCREEN_BUFFER_INFO color::m_ConsoleScreenBufferInfo[color::targetNum];//Windows�p�̃��Z�b�g�p�J���[���
#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
	const color::handle_t color::m_handle[] =
	{
		stdout,//�W���o�̓n���h��
		stderr,//�W���G���[�n���h��
	};
#endif//USE_WINDOWS_CONSOLE_COLOR
	//----------------------------------------
	//�R���\�[���J���[�������i������j
	void color::initializeOnce()
	{
		//�������ς݃`�F�b�N
		if (m_isInitialized)
			return;
		//�ÓI�ϐ���������
		m_isInitialized = true;
#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
		//�n���h��
		m_handle[stdOut] = GetStdHandle(STD_OUTPUT_HANDLE);//�W���o�̓n���h��
		m_handle[stdErr] = GetStdHandle(STD_ERROR_HANDLE);//�W���G���[�n���h��
		//�J���[�ύX�J�n
		GetConsoleScreenBufferInfo(m_handle[stdOut], &m_ConsoleScreenBufferInfo[stdOut]);
		GetConsoleScreenBufferInfo(m_handle[stdErr], &m_ConsoleScreenBufferInfo[stdErr]);
#endif//USE_WINDOWS_CONSOLE_COLOR
	}
	//----------------------------------------
	//�R���\�[���J���[�p�ϐ�
	static color s_colorForInitialize;//�������������s�̂��߂̃C���X�^���X

	//----------------------------------------
	//���x���N���X
	class level
	{
	public:
		//�^
		typedef unsigned char value_t;//�l�i���x���j
		typedef unsigned char byte;//�o�b�t�@�p
	private:
		//�萔�i�v�Z�p�j
		#define calcAsOutput(value) ((value) >> 1)//�l���o�̓��x���ɕϊ�
		#define calcAsValue(value) ((value) << 1)//�o�̓��x����l�ɕϊ�
	public:
		//�萔
		static const value_t NORMAL_NUM = 11;//�ʏ탌�x����
		static const value_t SPECIAL_NUM = 2;//���ꃌ�x����
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;//���x������
		static const value_t MIN = 0;//���x���ŏ��l
		static const value_t MAX = NUM - 1;//���x���ő�l
		static const value_t NORMAL_MIN = MIN;//�ʏ탌�x���ŏ��l
		static const value_t NORMAL_MAX = NORMAL_MIN + NORMAL_NUM - 1;//�ʏ탌�x���ő�l
		static const value_t SPECIAL_MIN = NORMAL_MAX + 1;//���ꃌ�x���ŏ��l
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//���ꃌ�x���ő�l
		static const value_t BEGIN = MIN;//���x���J�n�l�i�C�e���[�^�p�j
		static const value_t END = NUM;//���x���I�[�l�i�C�e���[�^�p�j
		static const value_t POOL_NUM = NUM + 1;//���x���L�^��
		static const value_t OUTPUT_LEVEL_MIN = calcAsOutput(NORMAL_MIN);//�o�̓��x���ŏ��l
		static const value_t OUTPUT_LEVEL_MAX = calcAsOutput(NORMAL_MAX);//�o�̓��x���ő�l
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");//�萔�`�F�b�N
	public:
		//�^
		//--------------------
		//�C�e���[�^
		class iterator : public std::iterator<std::bidirectional_iterator_tag, level>//�o�����C�e���[�^�Ƃ��Ď���
		{
		public:
			//�I�y���[�^
			const level* operator->() const { return &container::get(m_value); }
			const level& operator*() const { return container::get(m_value); }
			bool operator==(const iterator rhs) const { return m_value == rhs.m_value; }
			bool operator!=(const iterator rhs) const { return m_value != rhs.m_value; }
			const level& operator++() const { return m_value >= container::endValue() ? container::getEnd() : container::get(++m_value); }
			const level& operator++(int) const { return m_value >= container::endValue() ? container::getEnd() : container::get(m_value++); }
			const level& operator--() const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getEnd(); } return container::get(--m_value); }
			const level& operator--(int) const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getBegin(); } return container::get(m_value--); }
		public:
			//�L���X�g�I�y���[�^
			operator const level&() const { return container::get(m_value); }//�l�i���x���j
		public:
			//�R���X�g���N�^
			iterator(const value_t value) :
				m_value(value)
			{}
			iterator(const value_t value, int) :
				m_value(container::endValue())
			{}
			iterator(const level& obj) :
				m_value(obj.value())
			{}
			iterator(const level& obj, int) :
				m_value(container::endValue())
			{}
			iterator() :
				m_value(container::endValue())
			{}
			//�f�X�g���N�^
			~iterator()
			{}
		private:
			//�t�B�[���h
			value_t mutable m_value;//�l�i���x���j
		};
		//--------------------
		//const�C�e���[�^
		typedef const iterator const_iterator;
		//--------------------
		//�R���e�i�i�C�e���[�^�p�j
		class container
		{
			friend class level;
		public:
			//���\�b�h
			static const value_t beginValue(){ return BEGIN; }//�J�n�l�擾
			static const value_t endValue(){ return END; }//�I�[�l�擾
			static const level& get(const value_t value){ return m_poolPtr[value]; }//�v�f���擾
			static const level& getBegin(){ return m_poolPtr[beginValue()]; }//�J�n�v�f���擾
			static const level& getEnd(){ return m_poolPtr[endValue()]; }//�I�[�v�f���擾
		private:
			static void set(const value_t value, const level& obj)//�v�f���X�V
			{
				if (!container::m_isAlreadyPool[value])
				{
					container::m_poolPtr[value] = obj;
					container::m_isAlreadyPool[value] = true;
				}
			}
		public:
			static const iterator begin(){ return iterator(beginValue()); }//�J�n�C�e���[�^���擾
			static const iterator end()	{ return iterator(endValue()); }//�I�[�C�e���[�^���擾
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//�J�nconst�C�e���[�^���擾
			static const_iterator cend(){ return const_iterator(endValue()); }//�I�[const�C�e���[�^���擾
			//��reverse_iterator��Ή�
			//���\�b�h
			//�������i������j
			static void initializeOnce();
		private:
			//�t�B�[���h
			static bool m_isInitialized;//�������ς�
			static level* m_poolPtr;//�v�f�̃v�[���i�|�C���^�j
			static byte m_pool[];//�v�f�̃v�[���i�o�b�t�@�j���o�b�t�@�ƃ|�C���^�𕪂��Ă���̂́A�R���X�g���N�^�̎��s��h�~���邽��
			static std::bitset<POOL_NUM> m_isAlreadyPool;//�v�f�̏������ς݃t���O
		};
	public:
		//�I�y���[�^
		//���o�̓��x���Ŕ�r����
		bool operator ==(const level& rhs) const { return valueAsOutput() == rhs.valueAsOutput(); }
		bool operator !=(const level& rhs) const { return valueAsOutput() != rhs.valueAsOutput(); }
		bool operator >(const level& rhs) const { return valueAsOutput() > rhs.valueAsOutput(); }
		bool operator >=(const level& rhs) const { return valueAsOutput() >= rhs.valueAsOutput(); }
		bool operator <(const level& rhs) const { return valueAsOutput() < rhs.valueAsOutput(); }
		bool operator <=(const level& rhs) const { return valueAsOutput() <= rhs.valueAsOutput(); }
	private:
		//�R�s�[�I�y���[�^
		level& operator=(const level& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//�L���X�g�I�y���[�^
		operator int() const { return static_cast<int>(m_value); }//�l�i���x���j
		operator value_t() const { return m_value; }//�l�i���x���j
		operator const char*() const { return m_name; }//���O
	public:
		//�A�N�Z�b�T
		value_t value() const { return m_value; }//�l�i���x���j�擾
		const char* name() const { return m_name; }//���O�擾
		static value_t calcValueAsOutput(const value_t value){ return calcAsOutput(value); }//�o�̓��x���v�Z
		value_t valueAsOutput() const { return calcAsOutput(m_value); }//�o�̓��x���擾
		bool forLog() const { return m_forLog; }//���O���x���Ƃ��Ďg�p�\���H
		bool forNotice() const { return m_forNotice; }//��ʒʒm���x���Ƃ��Ďg�p�\���H
		bool forMask() const { return m_forMask; }//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
		color getColor() const { return std::move(changeColor(true)); }//�J���[�擾
		color getColorForNotice() const { return std::move(changeColorForNotice(true)); }//�J���[�擾�i��ʒʒm�p�j
	public:
		//���\�b�h
		//�J���[�ύX
		//���߂�l�󂯎��K�{
		//�@�߂�l���󂯎��Ȃ��Ƃ����Ƀf�X�g���N�^�����s����Č��̃J���[�ɖ߂�̂Ŏ��ۂɔ��f����Ȃ�
		color changeColor(const bool is_only_get = false) const
		{
			return std::move(color(color::stdOut, m_foreColor, m_backColor, !is_only_get));
		}
		//�J���[�ύX�i��ʒʒm�p�j
		//���߂�l�󂯎��K�{
		//�@�߂�l���󂯎��Ȃ��Ƃ����Ƀf�X�g���N�^�����s����Č��̃J���[�ɖ߂�̂Ŏ��ۂɔ��f����Ȃ�
		color changeColorForNotice(const bool is_only_get = false) const
		{
			return std::move(color(color::stdErr, m_foreColorForNotice, m_backColorForNotice, !is_only_get));
		}
		//�R���e�i�v�f���擾�i�V���[�g�J�b�g�p�j
		static const level& get(const value_t value){ return container::get(value); }
		//�O�̃��x�����擾
		const level& prev() const
		{
			if (valueAsOutput() <= OUTPUT_LEVEL_MIN || valueAsOutput() > OUTPUT_LEVEL_MAX || !(m_forLog || m_forNotice))
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcAsValue(calcAsOutput(m_value) - 1)];
		}
		//���̃��x�����擾
		const level& next() const
		{
			if (valueAsOutput() < OUTPUT_LEVEL_MIN || valueAsOutput() >= OUTPUT_LEVEL_MAX || !(m_forLog || m_forNotice))
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcAsValue(calcAsOutput(m_value) + 1)];
		}
	public:
		//�f�t�H���g�R���X�g���N�^
		level() :
			m_name(nullptr),
			m_value(UCHAR_MAX),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false),
			m_foreColor(color::through),
			m_backColor(color::through),
			m_foreColorForNotice(color::through),
			m_backColorForNotice(color::through)
		{
			container::initializeOnce();//�R���e�i�������i������j
		}
		//�R�s�[�R���X�g���N�^
		level(const level& src) :
			m_name(src.m_name),
			m_value(src.m_value),
			m_forLog(src.m_forLog),
			m_forNotice(src.m_forNotice),
			m_forMask(src.m_forMask),
			m_foreColor(src.m_foreColor),
			m_backColor(src.m_backColor),
			m_foreColorForNotice(src.m_foreColorForNotice),
			m_backColorForNotice(src.m_backColorForNotice)
		{
		}
		//�R���X�g���N�^
		level(const value_t value, const char* name, const bool for_log, const bool for_notice, const bool for_mask, const color::color_t fore_color, const color::color_t back_color, const color::color_t fore_color_for_notice, const color::color_t back_color_for_notice) :
			m_name(name),
			m_value(value),
			m_forLog(for_log),
			m_forNotice(for_notice),
			m_forMask(for_mask),
			m_foreColor(fore_color),
			m_backColor(back_color),
			m_foreColorForNotice(fore_color_for_notice),
			m_backColorForNotice(back_color_for_notice)
		{
			assert(value >= BEGIN && value <= END);
			container::set(m_value, *this);//�R���e�i�ɓo�^
		}
		level(const value_t value) :
			m_name(nullptr),
			m_value(value),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false),
			m_foreColor(color::through),
			m_backColor(color::through),
			m_foreColorForNotice(color::through),
			m_backColorForNotice(color::through)
		{
			assert(value >= BEGIN && value <= END);
			*this = container::get(m_value);//�R���e�i����擾���Ď��g�ɃR�s�[
		}
		//�f�X�g���N�^
		~level()
		{}
	private:
		const char* m_name;//���O
		const value_t m_value;//�l�i���x���j
		const bool m_forLog;//���O�o�̓��x���Ƃ��Ďg�p�\���H
		const bool m_forNotice;//��ʒʒm���x���Ƃ��Ďg�p�\���H
		const bool m_forMask;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
		const color::color_t m_foreColor;//�J���[�F�O��
		const color::color_t m_backColor;//�J���[�F�w��
		const color::color_t m_foreColorForNotice;//�J���[�F�O�ʁi��ʒʒm�p�j
		const color::color_t m_backColorForNotice;//�J���[�F�w�ʁi��ʒʒm�p�j
	private:
		//�}�N������
#ifndef ENABLE_CONSTEXPR
#undef calcAsOutput
#undef calcAsValue
#endif//ENABLE_CONSTEXPR
	};
	//----------------------------------------
	//���x����`�p�e���v���[�g�N���X�F�ʏ탌�x���p
	template<unsigned char V, bool for_log, bool for_notice, color::color_t fore_color, color::color_t back_color, color::color_t fore_color_for_notice, color::color_t back_color_for_notice>
	class level_normal : public level
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i���x���j
		static_assert(VALUE >= NORMAL_MIN && VALUE <= NORMAL_MAX, "out of range of level");//�l�͈̔̓`�F�b�N
		static const bool FOR_LOG = for_log;//���O���x���Ƃ��Ďg�p�\���H
		static const bool FOR_NOTICE = for_notice;//��ʒʒm���x���Ƃ��Ďg�p�\���H
		static const bool FOR_MASK = true;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
		static const color::color_t FORE_COLOR = fore_color;//�J���[�F�O��
		static const color::color_t BACK_COLOR = back_color;//�J���[�F�w��
		static const color::color_t FORE_COLOR_FOR_NOTICE = fore_color_for_notice;//�J���[�F�O�ʁi��ʒʒm�p�j
		static const color::color_t BACK_COLOR_FOR_NOTICE = back_color_for_notice;//�J���[�F�w�ʁi��ʒʒm�p�j
	public:
		//�R���X�g���N�^
		level_normal(const char* name) :
			level(VALUE, name, FOR_LOG, FOR_NOTICE, FOR_MASK, FORE_COLOR, BACK_COLOR, FORE_COLOR_FOR_NOTICE, BACK_COLOR_FOR_NOTICE)
		{}
	};
	//----------------------------------------
	//���x����`�p�e���v���[�g�N���X�F���ꃌ�x���p
	template<unsigned char V>
	class level_special : public level
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i���x���j
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of level");//�l�͈̔̓`�F�b�N
		static const bool FOR_LOG = false;//���O���x���Ƃ��Ďg�p�\���H
		static const bool FOR_NOTICE = false;//��ʒʒm���x���Ƃ��Ďg�p�\���H
		static const bool FOR_MASK = true;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	public:
		//�R���X�g���N�^
		level_special(const char* name) :
			level(VALUE, name, FOR_LOG, FOR_NOTICE, FOR_MASK, color::through, color::through, color::through, color::through)
		{}
	};
	//----------------------------------------
	//���x����`�N���X�F�I�[�p
	class level_end : public level
	{
	public:
		//�萔
		static const value_t VALUE = END;//�l�i���x���j
		static const bool FOR_LOG = false;//���O���x���Ƃ��Ďg�p�\���H
		static const bool FOR_NOTICE = false;//��ʒʒm���x���Ƃ��Ďg�p�\���H
		static const bool FOR_MASK = false;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	public:
		//�R���X�g���N�^
		level_end() :
			level(VALUE, "(END)", FOR_LOG, FOR_NOTICE, FOR_MASK, color::through, color::through, color::through, color::through)
		{}
	};
	//----------------------------------------
	//���x���萔
#define define_normalLevel(print_level, sub) (level::NORMAL_MIN + print_level * 2 + sub)
#define define_specialLevel(value) (level::SPECIAL_MIN + value)
	enum levelEnum : level::value_t
	{
		asNormal = define_normalLevel(1, 0),//�ʏ탁�b�Z�[�W
		asVerbose = define_normalLevel(0, 0),//�璷���b�Z�[�W
		asDetail = define_normalLevel(0, 1),//�ڍ׃��b�Z�[�W
		asImportant = define_normalLevel(2, 0),//�d�v���b�Z�[�W
		asWarning = define_normalLevel(3, 0),//�x�����b�Z�[�W
		asCritical = define_normalLevel(4, 0),//�d�僁�b�Z�[�W
		asAbsolute = define_normalLevel(5, 0),//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
		//�ȉ��A���O���x���^��ʒʒm���x���ύX�p
		asSilent = define_specialLevel(0),//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
		asSilentAbsolutely = define_specialLevel(1),//��ΐÎ�i�S�Ẵ��b�Z�[�W���o�͂��Ȃ��j
	};
	//----------------------------------------
	//���x����`
#define declare_normalLevel(value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice) struct level_##value : public level_normal<value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice>{ level_##value () :level_normal<value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice>(#value){} }
#define declare_specialLevel(value) struct level_##value : public level_special<value>{ level_##value () :level_special<value>(#value){} }
	//���ȉ��A�w�b�_�[�Ō��J����K�v�Ȃ�
	declare_normalLevel(asNormal, true, true, color::reset, color::reset, color::black, color::iWhite);//�ʏ탁�b�Z�[�W
	declare_normalLevel(asVerbose, true, false, color::iBlack, color::black, color::iBlack, color::iWhite);//�璷���b�Z�[�W
	declare_normalLevel(asDetail, true, false, color::iBlack, color::black, color::iBlack, color::iWhite);//�ڍ׃��b�Z�[�W
	declare_normalLevel(asImportant, true, true, color::iBlue, color::black, color::iBlue, color::iWhite);//�d�v���b�Z�[�W
	declare_normalLevel(asWarning, true, true, color::iMagenta, color::black, color::black, color::iMagenta);//�x�����b�Z�[�W
	declare_normalLevel(asCritical, true, true, color::iRed, color::black, color::iYellow, color::iRed);//�d�僁�b�Z�[�W
	declare_normalLevel(asAbsolute, true, false, color::through, color::through, color::through, color::through);//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
	//�ȉ��A���O���x���^��ʒʒm���x���ύX�p
	declare_specialLevel(asSilent);//�Î�i��΃��b�Z�\�W�ȊO�o�͂��Ȃ��j
	declare_specialLevel(asSilentAbsolutely);//��ΐÎ�i�S�Ẵ��b�Z�[�W���o�͂��Ȃ��j

	//----------------------------------------
	//���x���R���e�i�̐ÓI�ϐ����C���X�^���X��
	bool level::container::m_isInitialized = false;
	level* level::container::m_poolPtr = nullptr;
	level::byte level::container::m_pool[(POOL_NUM)* sizeof(level)];
	std::bitset<level::POOL_NUM> level::container::m_isAlreadyPool;
	//----------------------------------------
	//���x���R���e�i�������i������j
	void level::container::initializeOnce()
	{
		//�������ς݃`�F�b�N
		if (m_isInitialized)
			return;
		//�ÓI�ϐ���������
		m_isInitialized = true;
		m_isAlreadyPool.reset();
		memset(m_pool, 0, sizeof(m_pool));
		m_poolPtr = reinterpret_cast<level*>(m_pool);
		//�v�f��������
		for (level::value_t value = 0; value < level::NUM; ++value)
		{
			level(value, "(undefined)", false, false, false, color::through, color::through, color::through, color::through);
			m_isAlreadyPool[value] = false;
		}
		//���蓖�čς݃��x����ݒ�i�R���X�g���N�^�ŗv�f��o�^�j
		level_asNormal();//�ʏ탁�b�Z�[�W
		level_asVerbose();//�璷���b�Z�[�W
		level_asDetail();//�ڍ׃��b�Z�[�W
		level_asImportant();//�d�v���b�Z�[�W
		level_asWarning();//�x�����b�Z�[�W
		level_asCritical();//�d�僁�b�Z�[�W
		level_asAbsolute();//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
		level_asSilent();//�Î�i��΃��b�Z�\�W�ȊO�o�͂��Ȃ��j
		level_asSilentAbsolutely();//��ΐÎ�i�S�Ẵ��b�Z�[�W���o�͂��Ȃ��j
		level_end();//�I�[
	}
	//----------------------------------------
	//���x���p�ϐ�
	static level s_levelForInitialize;//�������������s�̂��߂̃C���X�^���X
	//----------------------------------------
	//���x���R���e�i��
	void printLevelAll()
	{
		for (auto& obj : level::container())//C++11�X�^�C��
		//for (auto ite = level::container::begin(); ite != level::container::end(); ++ite)//�����̃X�^�C��
		//for (auto ite = level::container::cbegin(); ite != level::container::cend(); ++ite)//�����̃X�^�C��
		{
			//const level& obj = ite;//�C�e���[�^��ϊ��i�C�e���[�^�̂܂܂ł��A���[���Z�q�Œ��ڒl����\�j
			color col(obj.changeColor());
			fprintf(stdout, "level=%d, name=\"%s\", valueAsOutput=%d, forLog=%d, forNotice=%d, forMask=%d\n", obj.value(), obj.name(), obj.valueAsOutput(), obj.forLog(), obj.forNotice(), obj.forMask());
			auto& prev = obj.prev();
			auto& next = obj.next();
			fprintf(stdout, "           prev=%s(%d)\n", prev.name(), prev.value());
			fprintf(stdout, "           next=%s(%d)\n", next.name(), next.value());
		}
	}

	//----------------------------------------
	//�J�e�S���N���X
	class category
	{
	public:
		//�^
		typedef unsigned char value_t;//�l�i�J�e�S���j
		typedef unsigned char byte;//�o�b�t�@�p
	public:
		//�萔
		static const value_t NORMAL_NUM = 64;//�ʏ�J�e�S����
		static const value_t ASSIGNED_NUM = 8;//���蓖�čς݃J�e�S����
		static const value_t RESERVED_NUM = NORMAL_NUM - ASSIGNED_NUM;//�\��J�e�S����
		static const value_t SPECIAL_NUM = 3;//����J�e�S����
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;//�J�e�S������
		static const value_t MIN = 0;//�J�e�S���ŏ��l
		static const value_t MAX = NUM - 1;//�J�e�S���ő�l
		static const value_t NORMAL_MIN = MIN;//�ʏ�J�e�S���ŏ��l
		static const value_t NORMAL_MAX = NORMAL_MIN + NORMAL_NUM - 1;//�ʏ�J�e�S���ő�l
		static const value_t ASSIGNED_MIN = NORMAL_MIN;//���蓖�čς݃J�e�S���ŏ��l
		static const value_t ASSIGNED_MAX = ASSIGNED_MIN + ASSIGNED_NUM - 1;//���蓖�čς݃J�e�S���ő�l
		static const value_t RESERVED_MIN = ASSIGNED_MAX + 1;//�\��J�e�S���ŏ��l
		static const value_t RESERVED_MAX = RESERVED_MIN + RESERVED_NUM - 1;//�\��J�e�S���ő�l
		static const value_t SPECIAL_MIN = NORMAL_MAX + 1;//����J�e�S���ŏ��l
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//����J�e�S���ő�l
		static const value_t BEGIN = MIN;//�J�e�S���J�n�l�i�C�e���[�^�p�j
		static const value_t END = NUM;//�J�e�S���I�[�l�i�C�e���[�^�p�j
		static const value_t POOL_NUM = NUM + 1;//�J�e�S���L�^��
		static_assert(NORMAL_MAX == RESERVED_MAX, "invalid category numbers.");//�萔�`�F�b�N
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");//�萔�`�F�b�N
	public:
		//�^
		//--------------------
		//�C�e���[�^
		class iterator : public std::iterator<std::bidirectional_iterator_tag, category>//�o�����C�e���[�^�Ƃ��Ď���
		{
		public:
			//�I�y���[�^
			const category* operator->() const { return &container::get(m_value); }
			const category& operator*() const { return container::get(m_value); }
			bool operator==(const iterator rhs) const { return m_value == rhs.m_value; }
			bool operator!=(const iterator rhs) const { return m_value != rhs.m_value; }
			const category& operator++() const { return m_value >= container::endValue() ? container::getEnd() : container::get(++m_value); }
			const category& operator++(int) const { return m_value >= container::endValue() ? container::getEnd() : container::get(m_value++); }
			const category& operator--() const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getEnd(); } return container::get(--m_value); }
			const category& operator--(int) const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getBegin(); } return container::get(m_value--); }
		public:
			//�L���X�g�I�y���[�^
			operator const category&() const { return container::get(m_value); }//�l�i�J�e�S���j
		public:
			//�R���X�g���N�^
			iterator(const value_t value) :
				m_value(value)
			{}
			iterator(const value_t value, int) :
				m_value(container::endValue())
			{}
			iterator(const category& obj) :
				m_value(obj.value())
			{}
			iterator(const category& obj, int) :
				m_value(container::endValue())
			{}
			iterator() :
				m_value(container::endValue())
			{}
			//�f�X�g���N�^
			~iterator()
			{}
		private:
			//�t�B�[���h
			value_t mutable m_value;//�l�i�J�e�S���j
		};
		//--------------------
		//const�C�e���[�^
		typedef const iterator const_iterator;
		//--------------------
		//�R���e�i�i�C�e���[�^�p�j
		class container
		{
			friend class category;
		public:
			//���\�b�h
			static const value_t beginValue(){ return BEGIN; }//�J�n�l�擾
			static const value_t endValue(){ return END; }//�I�[�l�擾
			static const category& get(const value_t value){ return m_poolPtr[value]; }//�v�f���擾
			static const category& getBegin(){ return m_poolPtr[beginValue()]; }//�J�n�v�f���擾
			static const category& getEnd(){ return m_poolPtr[endValue()]; }//�I�[�v�f���擾
		private:
			static void set(const value_t value, const category& obj)//�v�f���X�V
			{
				if (!container::m_isAlreadyPool[value])
				{
					container::m_poolPtr[value] = obj;
					container::m_isAlreadyPool[value] = true;
				}
			}
		public:
			static const iterator begin(){ return iterator(beginValue()); }//�J�n�C�e���[�^���擾
			static const iterator end()	{ return iterator(endValue()); }//�I�[�C�e���[�^���擾
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//�J�nconst�C�e���[�^���擾
			static const_iterator cend(){ return const_iterator(endValue()); }//�I�[const�C�e���[�^���擾
			//��reverse_iterator��Ή�
			//���\�b�h
			//�������i������j
			static void initializeOnce();
		private:
			//�t�B�[���h
			static bool m_isInitialized;//�������ς�
			static category* m_poolPtr;//�v�f�̃v�[���i�|�C���^�j
			static byte m_pool[];//�v�f�̃v�[���i�o�b�t�@�j���o�b�t�@�ƃ|�C���^�𕪂��Ă���̂́A�R���X�g���N�^�̎��s��h�~���邽��
			static std::bitset<POOL_NUM> m_isAlreadyPool;//�v�f�̏������ς݃t���O
		};
	public:
		//�I�y���[�^
		bool operator ==(const category& rhs) const { return m_value == rhs.m_value; }
		bool operator !=(const category& rhs) const { return m_value != rhs.m_value; }
	private:
		//�R�s�[�I�y���[�^
		category& operator=(const category& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//�L���X�g�I�y���[�^
		operator int() const { return static_cast<int>(m_value); }//�l�i�J�e�S���j
		operator value_t() const { return m_value; }//�l�i�J�e�S���j
		operator const char*() const { return m_name; }//���O
	public:
		//�A�N�Z�b�T
		value_t value() const { return m_value; }//�l�i�J�e�S���j�擾
		const char* name() const { return m_name; }//���O�擾
		bool isAssigned() const { return m_isAssigned; }//���蓖�čς݃J�e�S�����H
		bool isReserved() const { return !m_isAssigned; }//�\��J�e�S�����H
		bool forLog() const { return m_forLog; }//���O�o�͉\���H
		bool forNotice() const { return m_forNotice; }//��ʒʒm�\���H
		bool forMask() const { return m_forMask; }//�o�̓��x���}�X�N�\���H
	public:
		//���\�b�h
		//�R���e�i�v�f���擾�i�V���[�g�J�b�g�p�j
		static const category& get(const value_t value){ return container::get(value); }
	public:
		//�f�t�H���g�R���X�g���N�^
		category() :
			m_name(nullptr),
			m_value(UCHAR_MAX),
			m_isAssigned(false),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false)
		{
			container::initializeOnce();//�R���e�i�������i������j
		}
		//�R�s�[�R���X�g���N�^
		category(const category& src) :
			m_name(src.m_name),
			m_value(src.m_value),
			m_isAssigned(src.m_isAssigned),
			m_forLog(src.m_forLog),
			m_forNotice(src.m_forNotice),
			m_forMask(src.m_forMask)
		{
		}
		//�R���X�g���N�^
		category(const value_t value, const char* name, const bool is_assigned, const bool for_log, const bool for_notice, const bool for_mask) :
			m_name(name),
			m_value(value),
			m_isAssigned(is_assigned),
			m_forLog(for_log),
			m_forNotice(for_notice),
			m_forMask(for_mask)
		{
			assert(value >= BEGIN && value <= END);
			container::set(m_value, *this);//�R���e�i�ɓo�^
		}
		category(const value_t value) :
			m_name(nullptr),
			m_value(value),
			m_isAssigned(false),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false)
		{
			assert(value >= BEGIN && value <= END);
			*this = container::get(m_value);//�R���e�i����擾���Ď��g�ɃR�s�[
		}
		//�f�X�g���N�^
		~category()
		{}
	private:
		const char* m_name;//���O
		const value_t m_value;//�l�i�J�e�S���j
		const bool m_isAssigned;//���蓖�čς݃J�e�S�����H
		const bool m_forLog;//���O�o�͉\���H
		const bool m_forNotice;//��ʒʒm�\���H
		const bool m_forMask;//�o�̓��x���}�X�N�\���H
	};
	//----------------------------------------
	//�J�e�S����`�p�e���v���[�g�N���X�F���蓖�čς݃J�e�S���p
	template<unsigned char V, bool for_log, bool for_notice>
	class category_assigned : public category
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i�J�e�S���j
		static_assert(VALUE >= ASSIGNED_MIN && VALUE <= ASSIGNED_MAX, "out of range of category");//�l�͈̔̓`�F�b�N
		static const bool IS_ASSIGNED = true;//���蓖�čς݃J�e�S�����H
		static const bool FOR_LOG = for_log;//���O�o�͉\���H
		static const bool FOR_NOTICE = for_notice;//��ʒʒm�\���H
		static const bool FOR_MASK = true;//�o�̓��x���}�X�N�\���H
	public:
		//�R���X�g���N�^
		category_assigned(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//�J�e�S����`�p�e���v���[�g�N���X�F�\��J�e�S���p
	template<unsigned char V, bool for_log, bool for_notice>
	class category_reserved: public category
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i�J�e�S���j
		static_assert(VALUE >= RESERVED_MIN && VALUE <= RESERVED_MAX, "out of range of category");//�l�͈̔̓`�F�b�N
		static const bool IS_ASSIGNED = false;//���蓖�čς݃J�e�S�����H
		static const bool FOR_LOG = for_log;//���O�o�͉\���H
		static const bool FOR_NOTICE = for_notice;//��ʒʒm�\���H
		static const bool FOR_MASK = true;//�o�̓��x���}�X�N�\���H
	public:
		//�R���X�g���N�^
		category_reserved(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//�J�e�S����`�p�e���v���[�g�N���X�F����J�e�S���p
	template<unsigned char V, bool for_log, bool for_notice, bool for_mask>
	class category_special : public category
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i�J�e�S���j
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of category");//�l�͈̔̓`�F�b�N
		static const bool IS_ASSIGNED = true;//���蓖�čς݃J�e�S�����H
		static const bool FOR_LOG = for_log;//���O�o�͉\���H
		static const bool FOR_NOTICE = for_notice;//��ʒʒm�\���H
		static const bool FOR_MASK = for_mask;//�o�̓��x���}�X�N�\���H
	public:
		//�R���X�g���N�^
		category_special(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//�J�e�S����`�N���X�F�I�[�p
	class category_end : public category
	{
	public:
		//�萔
		static const value_t VALUE = END;//�l�i�J�e�S���j
		static const bool IS_ASSIGNED = true;//���蓖�čς݃J�e�S�����H
		static const bool FOR_LOG = false;//���O�o�͉\���H
		static const bool FOR_NOTICE = false;//��ʒʒm�\���H
		static const bool FOR_MASK = false;//�o�̓��x���}�X�N�\���H
	public:
		//�R���X�g���N�^
		category_end() :
			category(VALUE, "(END)", IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//�J�e�S���萔
#define define_assignedCategory(value) (category::ASSIGNED_MIN + value)
#define define_revervedCategory(value) (category::RESERVED_MIN + value)
#define define_specialCategory(value) (category::SPECIAL_MIN + value)
	enum categoryEnum : category::value_t
	{
		forAny = define_assignedCategory(0),//�Ȃ�ł��i�J�e�S���Ȃ��j
		forLogic = define_assignedCategory(1),//�v���O�����֌W
		forResource = define_assignedCategory(2),//���\�[�X�֌W
		for3D = define_assignedCategory(3),//3D�O���t�B�b�N�X�֌W
		for2D = define_assignedCategory(4),//2D�O���t�B�b�N�X�֌W
		forSound = define_assignedCategory(5),//�T�E���h�֌W
		forScript = define_assignedCategory(6),//�X�N���v�g�֌W
		forGameData = define_assignedCategory(7),//�Q�[���f�[�^�֌W
		//���O���x���^��ʒʒm���x���ύX�p
		forEvery = define_specialCategory(0),//�S���܂Ƃ߂ĕύX
		//����ȃJ�e�S���i�v�����g����p�j
		forCallPoint = define_specialCategory(1),//���߂̃R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
		forCriticalCallPoint = define_specialCategory(2),//���߂̏d��R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
	};
	//----------------------------------------
	//�J�e�S����`
#define declare_assignedCategory(value, for_log, for_notice) struct category_##value : public category_assigned<value, for_log, for_notice>{ category_##value () :category_assigned<value, for_log, for_notice>(#value){} }
#define declare_reservedCategory(value, for_log, for_notice) struct category_##value : public category_reserved<value, for_log, for_notice>{ category_##value () :category_reserved<value, for_log, for_notice>(#value){} }
#define declare_specialCategory(value, for_log, for_notice, for_mask) struct category_##value : public category_special<value, for_log, for_notice, for_mask>{ category_##value () :category_special<value, for_log, for_notice, for_mask>(#value){} }
	//���ȉ��A�w�b�_�[�Ō��J����K�v�Ȃ�
	declare_assignedCategory(forAny, true, true);//�Ȃ�ł��i�J�e�S���Ȃ��j
	declare_assignedCategory(forLogic, true, true);//�v���O�����֌W
	declare_assignedCategory(forResource, true, true);//���\�[�X�֌W
	declare_assignedCategory(for3D, true, true);//3D�O���t�B�b�N�X�֌W
	declare_assignedCategory(for2D, true, true);//2D�O���t�B�b�N�X�֌W
	declare_assignedCategory(forSound, true, true);//�T�E���h�֌W
	declare_assignedCategory(forScript, true, true);//�X�N���v�g�֌W
	declare_assignedCategory(forGameData, true, true);//�Q�[���f�[�^�֌W
	//���O���x���^��ʒʒm���x���ύX�p
	declare_specialCategory(forEvery, false, false, true);//�S���܂Ƃ߂ĕύX
	//����ȃJ�e�S���i�v�����g����p�j
	declare_specialCategory(forCallPoint, true, true, false);//���߂̃R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
	declare_specialCategory(forCriticalCallPoint, true, true, false);//���߂̏d��R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j

	//----------------------------------------
	//�J�e�S���R���e�i�̐ÓI�ϐ����C���X�^���X��
	bool category::container::m_isInitialized = false;
	category* category::container::m_poolPtr = nullptr;
	category::byte category::container::m_pool[(POOL_NUM)* sizeof(category)];
	std::bitset<category::POOL_NUM> category::container::m_isAlreadyPool;
	//----------------------------------------
	//�J�e�S���R���e�i�������i������j
	void category::container::initializeOnce()
	{
		//�������ς݃`�F�b�N
		if (m_isInitialized)
			return;
		//�ÓI�ϐ���������
		m_isInitialized = true;
		m_isAlreadyPool.reset();
		memset(m_pool, 0, sizeof(m_pool));
		m_poolPtr = reinterpret_cast<category*>(m_pool);
		//�v�f��������
		for (category::value_t value = 0; value < category::NUM; ++value)
		{
			category(value, "(undefined)", false, false, false, false);
			m_isAlreadyPool[value] = false;
		}
		//���蓖�čς݃J�e�S����ݒ�i�R���X�g���N�^�ŗv�f��o�^�j
		category_forAny();//�Ȃ�ł��i�J�e�S���Ȃ��j
		category_forLogic();//�v���O�����֌W
		category_forResource();//���\�[�X�֌W
		category_for3D();//3D�O���t�B�b�N�X�֌W
		category_for2D();//2D�O���t�B�b�N�X�֌W
		category_forSound();//�T�E���h�֌W
		category_forScript();//�X�N���v�g�֌W
		category_forGameData();//�Q�[���f�[�^�֌W
		//���O���x���^��ʒʒm���x���ύX�p
		category_forEvery();//�S���܂Ƃ߂ĕύX
		//����ȃJ�e�S���i�v�����g����p�j
		category_forCallPoint();//���߂̃R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
		category_forCriticalCallPoint();//���߂̏d��R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
		category_end();//�I�[
	}
	//----------------------------------------
	//�J�e�S���p�ϐ�
	static category s_categoryForInitialize;//�������������s�̂��߂̃C���X�^���X
	//----------------------------------------
	//�J�e�S���R���e�i��
	void printCategoryAll()
	{
		for (auto& obj : category::container())//C++11�X�^�C��
		//for (auto ite = category::container::begin(); ite != category::container::end(); ++ite)//�����̃X�^�C��
		//for (auto ite = category::container::cbegin(); ite != category::container::cend(); ++ite)//�����̃X�^�C��
		{
			//const category& obj = ite;//�C�e���[�^��ϊ��i�C�e���[�^�̂܂܂ł��A���[���Z�q�Œ��ڒl����\�j
			printf("category=%d, name=\"%s\", isAssigned=%d, isReserved=%d, forLog=%d, forNotice=%d, forMask=%d\n", obj.value(), obj.name(), obj.isAssigned(), obj.isReserved(), obj.forLog(), obj.forNotice(), obj.forMask());
		}
	}

	//----------------------------------------
	//���b�Z�[�W�Œ�o�b�t�@
	class messageBuffer
	{
	public:
		//�萔
		static const std::size_t BUFFER_SIZE = 2048;//1������̃o�b�t�@�T�C�Y
		static const std::size_t BUFFER_NUM = 16;//�o�b�t�@�̌�
	public:
		//�^
		typedef CPoolAllocatorWithBuff<BUFFER_SIZE, BUFFER_NUM> pool_t;//�v�[���o�b�t�@�^
	public:
		//���b�Z�[�W�p�Œ�o�b�t�@�擾
		//����������܂Łi���̃X���b�h���������܂Łj���g���C����
		void* assignBuffer()
		{
			void* p = nullptr;
			while (1)
			{
				p = m_pool.alloc(BUFFER_SIZE);
				if (p)
					break;
				std::this_thread::sleep_for(std::chrono::milliseconds(0));
			}
			return p;
		}
		//���b�Z�[�W�o�b�t�@�ԋp
		void releaseBuffer(void* p)
		{
			m_pool.free(p);
		}
	public:
		//�R���X�g���N�^
		messageBuffer()
		{}
		//�f�X�g���N�^
		~messageBuffer()
		{}
	private:
		static pool_t m_pool;
	};
	//���b�Z�[�W�Œ�o�b�t�@�p�ÓI�ϐ��C���X�^���X��
	messageBuffer::pool_t messageBuffer::m_pool;

	//----------------------------------------
	//���b�Z�[�W�\������
	enum msgAttrEnum : unsigned char//����
	{
		withSeqNo = 0x01,//�V�[�P���X�ԍ��\��
		withLevel = 0x02,//���x�����\��
		withCategory = 0x04,//�J�e�S�����\��
		withoutColor = 0x08,//�J���[�Ȃ�
	};
	//----------------------------------------
	//���b�Z�[�W����
	enum msgCtrlEnum :unsigned char
	{
		simplePrint = 0x00,//�V���v��
		withFuncName = 0x01,//�֐��������ɕ\��
		withFileName = 0x02,//�t�@�C���������ɕ\��
	};
	//----------------------------------------
	//���b�Z�[�W�N���X
	class message
	{
	public:
		//�^
		typedef char buff_t;//���b�Z�[�W�o�b�t�@�p
		typedef unsigned char attr_t;//�����^
		typedef unsigned char control_t;//���b�Z�[�W����^
	public:
		//�萔
		static const attr_t DEFAULT_ATTR = withLevel | withCategory;//�f�t�H���g�\������
		static const level::value_t DEFAULT_LOG_LEVEL = asNormal;//�f�t�H���g���O���x��
		static const level::value_t DEFAULT_NOTOICE_LEVEL = asCritical;//�f�t�H���g��ʒʒm���x��
	public:
		//�A�N�Z�b�T
		level::value_t getLevel() const { return m_level; }//���x���擾
		category::value_t getCategory() const { return m_category; }//�J�e�S���擾
		const char* getName() const { return m_name; }//�������擾
		const char* getSrcFileName() const { return getFileName(m_srcFileName); }//�\�[�X�t�@�C�����擾
		const char* getFuncName() const { return m_funcName; }//�֐����擾
		bool hasPushed() const { return m_hasPushed; }//�R�[���|�C���g�X�^�b�N�Ƀv�b�V���ς�
		bool attrHasChanged() const { return m_attrHasChanged; }//�ꎞ�\�������ύX�ς�
		bool logLevelHasChanged() const { return m_logLevelHasChanged; }//�ꎞ���O���x���ύX�ς�
		bool noticeLevelHasChanged() const { return m_noticeLevelHasChanged; }//�ꎞ��ʒʒm���x���ύX�ς�
	public:
		//���\�b�h
		//�������i������j
		static void initializeOnce();
		//�K�؂ȃJ�e�S���ɒ���
		//��forCallPoint, forCriticalCallPoint�Ɋ�Â��ϊ�
		static category::value_t adjustProperCategory(const category::value_t category_)
		{
			if (category_ == forCallPoint)//���O�̃R�[���|�C���g�̃J�e�S��
			{
				const message* call_point = getLastCallPoint();
				if (call_point)
					return call_point->getCategory();
				return forAny;//�R�[���|�C���g���Ȃ���� forAny ����
			}
			else if (category_ == forCriticalCallPoint)//���߂̃N���e�B�J���R�[���|�C���g�̃J�e�S��
			{
				const message* call_point = getLastCriticalCallPoint();
				if (call_point)
					return call_point->getCategory();
				return forAny;//�R�[���|�C���g���Ȃ���� forAny ����
			}
			return category_;
		}
		//���݂̕\���������擾
		static attr_t getAttrG(){ return m_attrG; }
		//�y�ꎞ�\�������Łz
		attr_t getAttr() const { return m_attr; }
		//�y�R�[���|�C���g�Łz
		static attr_t getAttrG_CP()
		{
			message* call_point = getLastCallPointWithAttrHasChanged();
			if (!call_point)
				return getAttrG();//�R�[���|�C���g����������ʏ�̕\������
			return call_point->getAttr();
		}
		//�y�ꎞ�\�������̃R�[���|�C���g�Łz
		level::value_t getAttr_CP()
		{
			return m_attrHasChanged ? getAttr() : getAttrG_CP();
		}
		//���݂̕\��������ύX
		//static void setAttrG(const attr_t attr){ m_attrG = attr; }//�֎~
		static attr_t addAttrG(const attr_t attr){ m_attrG |= attr; return m_attrG; }
		static attr_t delAttrG(const attr_t attr){ m_attrG &= ~attr; return m_attrG; }
		//�y�ꎞ�\�������Łz
		//void setAttr(const attr_t attr){ copyAttr(); m_attr = attr; }//�֎~
		attr_t addAttr(const attr_t attr){ copyAttr(); m_attr |= attr; return m_attr; }
		attr_t delAttr(const attr_t attr){ copyAttr(); m_attr &= ~attr; return m_attr; }
		//���݂̕\�����������Z�b�g
		//���f�t�H���g�ɖ߂�
		static void resetAttrG(){ m_attrG = DEFAULT_ATTR; }
		//�y�ꎞ�\�������Łz
		void resetAttr(){ copyAttr(); m_attr = DEFAULT_ATTR; }
		//���݂̕\���������ꎞ�\�������ɃR�s�[
		void copyAttr()
		{
			if (m_attrHasChanged)
				return;
			message* call_point = getLastCallPointWithAttrHasChanged();
			m_attrHasChanged = true;
			if (m_hasPushed)
				++m_attrHasChangedG;
			if (call_point)
				m_attr = call_point->m_attr;//�ꎞ�\������
			else
				m_attr = m_attrG;//�ꎞ�\������
		}
		//�ꎞ�\�������̃R�s�[��Ԃ�����
		//���{���̕\�������ɖ߂�
		void releaseAttr()
		{
			if (!m_attrHasChanged)
				return;
			m_attrHasChanged = false;
			if (m_hasPushed)
				--m_attrHasChangedG;
		}
		//���݂̃��O���x�����擾
		static level::value_t getLogLevelG(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			return m_logLevelG[category_];
		}
		//�y�R�[���|�C���g�Łz
		static level::value_t getLogLevelG_CP(const category::value_t category_)
		{
			message* call_point = getLastCallPointWithLogLevelHasChanged();
			if (!call_point)
				return getLogLevelG(category_);//�R�[���|�C���g����������ʏ�̃��O���x��
			return call_point->getLogLevel(category_);
		}
		//�y�ꎞ���O���x���̗L������z
		//���{���̃��x�����Ⴂ�ꎞ���O���x���͈����Ȃ�
		bool isValidTempLogLevel(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			return m_logLevelHasChanged && level::calcValueAsOutput(m_logLevelG[category_]) <= level::calcValueAsOutput(m_logLevel[category_]);
		}
		//�y�ꎞ���O���x���Łz
		level::value_t getLogLevel(const category::value_t category_)
		{
			return isValidTempLogLevel(category_) ? m_logLevel[category_] : m_logLevelG[category_];
		}
		//�y�ꎞ���O���x���̃R�[���|�C���g�Łz
		level::value_t getLogLevel_CP(const category::value_t category_)
		{
			return isValidTempLogLevel(category_) ? m_logLevel[category_] : getLogLevelG_CP(category_);
		}
		//���݂̃��O���x����ύX
		//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
		//���ύX�O�̃��O���x����Ԃ��iforEvery�w�莞��forAny�̃��O���x����Ԃ��j
		static level::value_t setLogLevelG(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			if (category_ == forEvery)
			{
				const level::value_t prev = m_logLevelG[forAny];
				for (level::value_t& value : m_logLevelG)
					value = level_;
				return prev;
			}
			assert(o_category.forLog() == true);
			const level::value_t prev = m_logLevelG[category_];
			m_logLevelG[category_] = level_;
			return prev;
		}
		//�y�ꎞ���O���x���Łz
		level::value_t setLogLevel(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			copyLogLevel();//�X�V�O�Ɍ��݂̃��O���x�����R�s�[
			if (category_ == forEvery)
			{
				const level::value_t prev = m_logLevel[forAny];
				for (int category_tmp = category::NORMAL_MIN; category_tmp <= category::NORMAL_MAX; ++category_tmp)
				{
					m_logLevel[category_tmp] =
						level::calcValueAsOutput(m_logLevelG[category_tmp]) > level::calcValueAsOutput(level_) ?
							m_logLevelG[category_tmp] ://�{���̃��x�����Ⴍ���邱�Ƃ͂ł��Ȃ�
							level_;
				}
				return prev;
			}
			assert(o_category.forLog() == true);
			const level::value_t prev = m_logLevel[category_];
			m_logLevel[category_] =
				level::calcValueAsOutput(m_logLevelG[category_]) > level::calcValueAsOutput(level_) ?
					m_logLevelG[category_] ://�{���̃��x�����Ⴍ���邱�Ƃ͂ł��Ȃ�
					level_;
			return prev;
		}
		//���݂̃��O���x�������Z�b�g
		//���f�t�H���g�ɖ߂�
		static void resetLogLevelG(const category::value_t category_)
		{
			setLogLevelG(DEFAULT_LOG_LEVEL, category_);
		}
		//�y�ꎞ���O���x���Łz
		void resetLogLevel(const category::value_t category_)
		{
			setLogLevel(DEFAULT_LOG_LEVEL, category_);
		}
		//���݂̃��O���x����S�ă��Z�b�g
		//���f�t�H���g�ɖ߂�
		static void resetLogLevelAllG()
		{
			//resetLogLevelG(forEvery);//�����������ł��Ăяo�����̂ŁA���ʏ������g�킸�P���ɍX�V
			for (level::value_t& value : m_logLevelG)
				value = DEFAULT_LOG_LEVEL;
		}
		//�y�ꎞ���O���x���Łz
		void resetLogLevelAll()
		{
			resetLogLevel(forEvery);
		}
		//���O���x�����ꎞ���O���x���ɃR�s�[
		void copyLogLevel()
		{
			if (m_logLevelHasChanged)
				return;
			message* call_point = getLastCallPointWithLogLevelHasChanged();
			m_logLevelHasChanged = true;
			if (m_hasPushed)
				++m_logLevelHasChangedG;
			if (call_point)
				memcpy(m_logLevel, call_point->m_logLevel, sizeof(m_logLevel));//�ꎞ���O���x��
			else
				memcpy(m_logLevel, m_logLevelG, sizeof(m_logLevel));//�ꎞ���O���x��
		}
		//�ꎞ���O���x���̃R�s�[��Ԃ�����
		//���{���̃��O���x���ɖ߂�
		void releaseLogLevel()
		{
			if (!m_logLevelHasChanged)
				return;
			m_logLevelHasChanged = false;
			if (m_hasPushed)
				--m_logLevelHasChangedG;
		}
		//���݂̉�ʒʒm���x�����擾
		static level::value_t getNoticeLevelG(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			return m_noticeLevelG[category_];
		}
		//�y�R�[���|�C���g�Łz
		static level::value_t getNoticeLevelG_CP(const category::value_t category_)
		{
			message* call_point = getLastCallPointWithNoticeLevelHasChanged();
			if (!call_point)
				return getNoticeLevelG(category_);//�R�[���|�C���g����������ʏ�̉�ʒʒm���x��
			return call_point->getNoticeLevel(category_);
		}
		//�y�ꎞ��ʒʒm���x���̗L������z
		//���{���̃��x�����Ⴂ�ꎞ��ʒʒm���x���͈����Ȃ�
		bool isValidTempNoticeLevel(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			return m_noticeLevelHasChanged && level::calcValueAsOutput(m_noticeLevelG[category_]) <= level::calcValueAsOutput(m_noticeLevel[category_]);
		}
		//�y�ꎞ��ʒʒm���x���Łz
		level::value_t getNoticeLevel(const category::value_t category_)
		{
			return isValidTempNoticeLevel(category_) ? m_noticeLevel[category_] : m_noticeLevelG[category_];
		}
		//�y�ꎞ��ʒʒm���x���̃R�[���|�C���g�Łz
		level::value_t getNoticeLevel_CP(const category::value_t category_)
		{
			return isValidTempNoticeLevel(category_) ? m_noticeLevel[category_] : getNoticeLevelG_CP(category_);
		}
		//���݂̉�ʒʒm���x����ύX
		//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
		//���ύX�O�̉�ʒʒm���x����Ԃ��iforEvery�w�莞��forAny�̉�ʒʒm���x����Ԃ��j
		static level::value_t setNoticeLevelG(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			if (category_ == forEvery)
			{
				const level::value_t prev = m_noticeLevelG[forAny];
				for (level::value_t& value : m_noticeLevelG)
					value = level_;
				return prev;
			}
			assert(o_category.forNotice() == true);
			const level::value_t prev = m_noticeLevelG[category_];
			m_noticeLevelG[category_] = level_;
			return prev;
		}
		//�y�ꎞ��ʒʒm���x���Łz
		level::value_t setNoticeLevel(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			copyNoticeLevel();//�X�V�O�Ɍ��݂̉�ʒʒm���x�����R�s�[
			if (category_ == forEvery)
			{
				const level::value_t prev = m_noticeLevel[forAny];
				for (int category_tmp = category::NORMAL_MIN; category_tmp <= category::NORMAL_MAX; ++category_tmp)
				{
					m_noticeLevel[category_tmp] =
						level::calcValueAsOutput(m_noticeLevelG[category_tmp]) > level::calcValueAsOutput(level_) ?
						m_noticeLevelG[category_tmp] ://�{���̃��x�����Ⴍ���邱�Ƃ͂ł��Ȃ�
						level_;
				}
				return prev;
			}
			assert(o_category.forNotice() == true);
			const level::value_t prev = m_noticeLevel[category_];
			m_noticeLevel[category_] =
				level::calcValueAsOutput(m_noticeLevelG[category_]) > level::calcValueAsOutput(level_) ?
				m_noticeLevelG[category_] ://�{���̃��x�����Ⴍ���邱�Ƃ͂ł��Ȃ�
				level_;
			return prev;
		}
		//���݂̉�ʒʒm���x�������Z�b�g
		//���f�t�H���g�ɖ߂�
		static void resetNoticeLevelG(const category::value_t category_)
		{
			setNoticeLevelG(DEFAULT_NOTOICE_LEVEL, category_);
		}
		//�y�ꎞ��ʒʒm���x���Łz
		void resetNoticeLevel(const category::value_t category_)
		{
			setNoticeLevel(DEFAULT_NOTOICE_LEVEL, category_);
		}
		//���݂̉�ʒʒm���x����S�ă��Z�b�g
		//���f�t�H���g�ɖ߂�
		static void resetNoticeLevelAllG()
		{
			//resetNoticeLevelG(forEvery);//�����������ł��Ăяo�����̂ŁA���ʏ������g�킸�P���ɍX�V
			for (level::value_t& value : m_noticeLevelG)
				value = DEFAULT_NOTOICE_LEVEL;
		}
		//�y�ꎞ��ʒʒm���x���Łz
		void resetNoticeLevelAll()
		{
			resetNoticeLevel(forEvery);
		}
		//��ʒʒm���x�����ꎞ��ʒʒm���x���ɃR�s�[
		void copyNoticeLevel()
		{
			if (m_noticeLevelHasChanged)
				return;
			message* call_point = getLastCallPointWithLogLevelHasChanged();
			m_noticeLevelHasChanged = true;
			if (m_hasPushed)
				++m_noticeLevelHasChangedG;
			if (call_point)
				memcpy(m_noticeLevel, call_point->m_noticeLevel, sizeof(m_noticeLevel));//�ꎞ���O���x��
			else
				memcpy(m_noticeLevel, m_noticeLevelG, sizeof(m_noticeLevel));//�ꎞ���O���x��
		}
		//�ꎞ��ʒʒm���x���̃R�s�[��Ԃ�����
		//���{���̉�ʒʒm���x���ɖ߂�
		void releaseNoticeLevel()
		{
			if (!m_noticeLevelHasChanged)
				return;
			m_noticeLevelHasChanged = false;
			if (m_hasPushed)
				--m_noticeLevelHasChangedG;
		}
	protected:
		//���b�Z�[�W�o�b�t�@�m��
		static void beginBuffer()
		{
			if (m_messageBuff)
				freeBuffer();
			messageBuffer allocator;//���b�Z�[�W�Œ�o�b�t�@
			m_messageBuff = reinterpret_cast<buff_t*>(allocator.assignBuffer());
			m_messageBuffSize = messageBuffer::BUFFER_SIZE;
			m_messageBuffUsed = 0;
			if (!m_messageBuff)
				m_messageBuffSize = 0;
		}
		//���b�Z�[�W�o�b�t�@���
		static void freeBuffer()
		{
			if (!m_messageBuff)
				return;
			messageBuffer allocator;//���b�Z�[�W�Œ�o�b�t�@
			allocator.releaseBuffer(m_messageBuff);
			m_messageBuff = nullptr;//���b�Z�[�W�o�b�t�@
			m_messageBuffSize = 0;//���b�Z�[�W�o�b�t�@�T�C�Y
			m_messageBuffUsed = 0;//���b�Z�[�W�o�b�t�@�g�p��
		}
		//���b�Z�[�W�o�b�t�@�t���b�V��
		static void flushBuffer(const level& o_level, const bool flush_log, const bool flush_notice, const bool log_without_color = false)
		{
			if (!m_messageBuff)
				return;
			//�y�������z�{���̓��b�Z�[�W���L���[�C���O���鏈��
			if (flush_log)
			{
				if (log_without_color)
				{
					fprintf(stdout, m_messageBuff);
				}
				else
				{
					color col(o_level.changeColor());
					fprintf(stdout, m_messageBuff);
				}
			}
			if (flush_notice)
			{
				color col(o_level.changeColorForNotice());
				fprintf(stderr, m_messageBuff);
			}
			freeBuffer();//�o�b�t�@���
		}
		//�o�b�t�@�����O
		static int vbuffer(const char* fmt, va_list args)
		{
			std::size_t remain = m_messageBuffSize - m_messageBuffUsed;
			if (!m_messageBuff || remain == 0)
				return 0;
		#ifdef USE_STRCPY_S
			const int ret = vsprintf_s(m_messageBuff + m_messageBuffUsed, remain, fmt, args);
		#else//USE_STRCPY_S
			const int ret = vsprintf(m_messageBuff + m_messageBuffUsed, fmt, args);
		#endif//USE_STRCPY_S
			m_messageBuffUsed += ret;
			return ret;
		}
		static int buffer(const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vbuffer(fmt, args);
			va_end(args);
			return ret;
		}
		//�o�͔���
		static void isAllowPrint(bool& is_allow_log, bool& is_allow_notice, const level::value_t log_level, const level::value_t notice_level, const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forLog() == true || o_level.forNotice() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			const level& o_log_level = level::get(log_level);
			const level& o_notice_level = level::get(notice_level);
			is_allow_log = (o_level >= o_log_level && o_level.forLog() && o_category.forLog());
			is_allow_notice = (o_level >= o_notice_level && o_level.forNotice() && o_category.forNotice());
		}
		//���b�Z�[�W�o�́F���x���������w��
		//��va_list�������ɂƂ�o�[�W����
		static int vprintCommon(const attr_t attr, const level::value_t log_level, const level::value_t notice_level, const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			bool is_allow_log;
			bool is_allow_notice;
			isAllowPrint(is_allow_log, is_allow_notice, log_level, notice_level, level_, category_);
			if (!is_allow_log && !is_allow_notice)
				return 0;
			const level& o_level = level::get(level_);
			const category& o_category = category::get(category_);
			beginBuffer();
			const bool without_color = (attr & withoutColor) ? true : false;
			const attr_t attr_tmp = attr & (withLevel | withCategory);
			if (is_allow_log && attr_tmp != 0)
			{
				if (attr_tmp == withLevel)
					buffer("[%s]", o_level.name());
				else if (attr_tmp == withCategory)
					buffer("[%s]", o_category.name());
				else//if (attr_tmp == (withLevel | withCategory))
					buffer("[%s,%s]", o_level.name(), o_category.name());
				flushBuffer(o_level, true, false, without_color);
				beginBuffer();
				buffer(" ");
			}
			int ret = vbuffer(fmt, args);
			flushBuffer(o_level, is_allow_log, is_allow_notice, true);
			return ret;
		}
		//�R�[���|�C���g�X�^�b�N�����X�g�\��
		static void printCPStackCommon(const attr_t attr, const level::value_t log_level, const level::value_t level_, const category::value_t category_, const char* name, const control_t control)
		{
			bool is_allow_log;
			bool is_allow_notice;
			isAllowPrint(is_allow_log, is_allow_notice, log_level, asSilentAbsolutely, level_, category_);
			if (!is_allow_log)
				return;
			const level& o_level = level::get(level_);
			const category& o_category = category::get(category_);
			const bool without_color = (attr & withoutColor) ? true : false;
			const attr_t attr_tmp = attr & (withLevel | withCategory);
			beginBuffer();
			buffer("============================================================\n");
			if (attr_tmp != 0)
			{
				if (attr_tmp == withLevel)
					buffer("[%s]", o_level.name());
				else if (attr_tmp == withCategory)
					buffer("[%s]", o_category.name());
				else//if (attr_tmp == (withLevel | withCategory))
					buffer("[%s,%s]", o_level.name(), o_category.name());
			}
			if (!without_color)
			{
				flushBuffer(o_level, true, false);
				beginBuffer();
			}
			buffer(" Call point stack at \"%s\"\n", name);
			buffer("----------------------------------------\n");
			const message* call_point = m_callPointStackHead;
			while (call_point)
			{
				buffer("  \"%s\" ", call_point->getName());
				if (attr_tmp != 0)
				{
					const level& o_level_tmp = level::get(call_point->getLevel());
					const category& o_category_tmp = category::get(call_point->getCategory());
					if (!without_color)
					{
						flushBuffer(o_level, true, false, true);
						beginBuffer();
					}
					if (attr_tmp == withLevel)
						buffer("[%s]", o_level_tmp.name());
					else if (attr_tmp == withCategory)
						buffer("[%s]", o_category_tmp.name());
					else//if (attr_tmp == (withLevel | withCategory))
						buffer("[%s,%s]", o_level_tmp.name(), o_category_tmp.name());
					if (!without_color)
					{
						flushBuffer(o_level_tmp, true, false, false);
						beginBuffer();
					}
				}
				const control_t control_tmp = control & (withFuncName | withFileName);
				if (control_tmp != 0)
				{
					buffer(" ... ");
					if (control_tmp & withFuncName)
						buffer("%s", call_point->getFuncName());
					if (control_tmp == (withFuncName | withFileName))
						buffer(" : ");
					if (control_tmp & withFileName)
						buffer(" %s", call_point->getSrcFileName());
				}
				buffer("\n");
				call_point = call_point->m_callPointStackNext;
			}
			if (!without_color)
			{
				flushBuffer(o_level, true, false, true);
				beginBuffer();
			}
			buffer("============================================================\n");
			flushBuffer(o_level, true, false, without_color);
		}
	public:
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h�F���x���������w��
		//��vprint***/vlog***/vnotice***
		//��va_list�������ɂƂ�o�[�W����
		static int vprintG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttrG_CP();
			const level::value_t log_level = getLogLevelG_CP(category_adj);
			const level::value_t notice_level = getNoticeLevelG_CP(category_adj);
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vprint(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttr_CP();
			const level::value_t log_level = getLogLevel_CP(category_adj);
			const level::value_t notice_level = getNoticeLevel_CP(category_adj);
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vprint(const level::value_t level_, const char* fmt, va_list args)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			return vprint(level_, m_category, fmt, args);
		}
		int vprint(const char* fmt, va_list args)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			return vprint(m_level, m_category, fmt, args);
		}
		static int vlogG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttrG_CP();
			const level::value_t log_level = getLogLevelG_CP(category_adj);
			const level::value_t notice_level = asSilentAbsolutely;
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vlog(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//�y�ꎞ���O���x���Łz
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttr_CP();
			const level::value_t log_level = getLogLevel_CP(category_adj);
			const level::value_t notice_level = asSilentAbsolutely;
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vlog(const level::value_t level_, const char* fmt, va_list args)//�y�ꎞ���O���x���Łz
		{
			return vlog (level_, m_category, fmt, args);
		}
		int vlog(const char* fmt, va_list args)//�y�ꎞ���O���x���Łz
		{
			return vlog(m_level, m_category, fmt, args);
		}
		static int vnoticeG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttrG_CP();
			const level::value_t log_level = asSilentAbsolutely;
			const level::value_t notice_level = getNoticeLevelG_CP(category_adj);
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vnotice(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//�y�ꎞ��ʒʒm���x���Łz
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttr_CP();
			const level::value_t log_level = asSilentAbsolutely;
			const level::value_t notice_level = getNoticeLevel_CP(category_adj);
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vnotice(const level::value_t level_, const char* fmt, va_list args)//�y�ꎞ��ʒʒm���x���Łz
		{
			return vnotice(level_, m_category, fmt, args);
		}
		int vnotice(const char* fmt, va_list args)//�y�ꎞ��ʒʒm���x���Łz
		{
			return vnotice(m_level, m_category, fmt, args);
		}
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h�F���x���������w��
		//��print***/log***/notice***
		//���ϒ������o�[�W����
		static int printG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprintG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const level::value_t level_, const char* fmt, ...)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const char* fmt, ...)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(fmt, args);
			va_end(args);
			return ret;
		}
		static int logG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlogG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//�y�ꎞ���O���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const level::value_t level_, const char* fmt, ...)//�y�ꎞ���O���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const char* fmt, ...)//�y�ꎞ���O���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(fmt, args);
			va_end(args);
			return ret;
		}
		static int noticeG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnoticeG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//�y�ꎞ��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const level::value_t level_, const char* fmt, ...)//�y�ꎞ��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const char* fmt, ...)//�y�ꎞ��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(fmt, args);
			va_end(args);
			return ret;
		}
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h��`�}�N��
		//��vprint***/vlog***/vnotice***
		//��va_list�������ɂƂ�o�[�W����
	#define declare_vprintMethods(level_) \
		static int vprintAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vprintG(as##level_, category_, fmt, args); \
		} \
		int vprintAs##level_(const category::value_t category_, const char* fmt, va_list args)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			return vprint(as##level_, category_, fmt, args); \
		} \
		int vprintAs##level_(const char* fmt, va_list args)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			return vprint(as##level_, fmt, args); \
		} \
		static int vlogAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vlogG(as##level_, category_, fmt, args); \
		} \
		int vlogAs##level_(const category::value_t category_, const char* fmt, va_list args)/*�y�ꎞ���O���x���Łz*/ \
		{ \
			return vlog(as##level_, category_, fmt, args); \
		} \
		int vlogAs##level_(const char* fmt, va_list args)/*�y�ꎞ���O���x���Łz*/ \
		{ \
			return vlog(as##level_, fmt, args); \
		} \
		static int vnoticeAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vnoticeG(as##level_, category_, fmt, args); \
		} \
		int vnoticeAs##level_(const category::value_t category_, const char* fmt, va_list args)/*�y�ꎞ��ʒʒm���x���Łz*/ \
		{ \
			return vnotice(as##level_, category_, fmt, args); \
		} \
		int vnoticeAs##level_(const char* fmt, va_list args)/*�y�ꎞ��ʒʒm���x���Łz*/ \
		{ \
			return vnotice(as##level_, fmt, args); \
		}
			//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h��`�}�N��
		//��print***/log***/notice***
		//���ϒ������o�[�W����
	#define declare_printMethods(level_) \
		static int printAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int printAs##level_(const category::value_t category_, const char* fmt, ...)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int printAs##level_(const char* fmt, ...)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		} \
		static int logAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int logAs##level_(const category::value_t category_, const char* fmt, ...)/*�y�ꎞ���O���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int logAs##level_(const char* fmt, ...)/*�y�ꎞ���O���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		} \
		static int noticeAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int noticeAs##level_(const category::value_t category_, const char* fmt, ...)/*�y�ꎞ��ʒʒm���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int noticeAs##level_(const char* fmt, ...)/*�y�ꎞ��ʒʒm���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		}
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h��`
		//��vprint***/vlog***/vnotice***
		//��va_list�������ɂƂ�o�[�W����
		declare_vprintMethods(Normal);//�ʏ탁�b�Z�[�W
		declare_vprintMethods(Verbose);//�璷���b�Z�[�W
		declare_vprintMethods(Detail);//�ڍ׃��b�Z�[�W
		declare_vprintMethods(Important);//�d�v���b�Z�[�W
		declare_vprintMethods(Warning);//�x�����b�Z�[�W
		declare_vprintMethods(Critical);//�d��i���j���b�Z�[�W
		declare_vprintMethods(Absolute);//��΁i�K�{�j���b�Z�[�W
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h��`
		//��print***/log***/notice***
		//���ϒ������o�[�W����
		declare_printMethods(Normal);//�ʏ탁�b�Z�[�W
		declare_printMethods(Verbose);//�璷���b�Z�[�W
		declare_printMethods(Detail);//�ڍ׃��b�Z�[�W
		declare_printMethods(Important);//�d�v���b�Z�[�W
		declare_printMethods(Warning);//�x�����b�Z�[�W
		declare_printMethods(Critical);//�d��i���j���b�Z�[�W
		declare_printMethods(Absolute);//��΁i�K�{�j���b�Z�[�W
	protected:
		//�R�[���|�C���g�X�^�b�N�Ɏ��g���v�b�V��
		void pushCallPoint()
		{
			if (m_hasPushed)
				return;
			m_hasPushed = true;
			assert(m_callPointStackHead != this);
			m_callPointStackNext = m_callPointStackHead;
			m_callPointStackHead = this;
		}
		//�R�[���|�C���g�X�^�b�N����i���g���j�|�b�v
		void popCallPoint()
		{
			if (!m_hasPushed)
				return;
			m_hasPushed = false;
			assert(m_callPointStackHead == this);
			m_callPointStackHead = m_callPointStackNext;
			m_callPointStackNext = nullptr;
		}
	public:
		//���O�̃R�[���|�C���g���擾
		static message* getLastCallPoint()
		{
			return m_callPointStackHead;
		}
		//���߂̃N���e�B�J���R�[���|�C���g���擾
		static message* getLastCriticalCallPoint()
		{
			message* node = m_callPointStackHead;
			while (node)
			{
				if (node->getLevel() == asCritical)
					break;
				node = node->m_callPointStackNext;
			}
			return node;
		}
		//���߂ŕ\���������X�V�����R�[���|�C���g���擾
		static message* getLastCallPointWithAttrHasChanged()
		{
			if (m_attrHasChangedG == 0)
				return nullptr;
			message* node = m_callPointStackHead;
			while (node)
			{
				if (node->attrHasChanged())
					break;
				node = node->m_callPointStackNext;
			}
			return node;
		}
		//���߂Ń��O���x�����X�V�����R�[���|�C���g���擾
		static message* getLastCallPointWithLogLevelHasChanged()
		{
			if (m_logLevelHasChangedG == 0)
				return nullptr;
			message* node = m_callPointStackHead;
			while (node)
			{
				if (node->logLevelHasChanged())
					break;
				node = node->m_callPointStackNext;
			}
			return node;
		}
		//���߂ŉ�ʒʒm���x�����X�V�����R�[���|�C���g���擾
		static message* getLastCallPointWithNoticeLevelHasChanged()
		{
			if (m_noticeLevelHasChangedG == 0)
				return nullptr;
			message* node = m_callPointStackHead;
			while (node)
			{
				if (node->noticeLevelHasChanged())
					break;
				node = node->m_callPointStackNext;
			}
			return node;
		}
		//�R�[���|�C���g�X�^�b�N�����X�g�\��
		static void printCPStackG(const level::value_t level_, category::value_t category_, const char* name, const control_t control = simplePrint)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttrG_CP();
			const level::value_t log_level = getLogLevelG_CP(category_adj);
			printCPStackCommon(attr_adj, log_level, level_, category_adj, name, control);
		}
		void printCPStack(const level::value_t level_, category::value_t category_, const char* name, const control_t control = simplePrint)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttr_CP();
			const level::value_t log_level = getLogLevel_CP(category_adj);
			printCPStackCommon(attr_adj, log_level, level_, category_adj, name, control);
		}
	#define declare_printCPMethods(level_) \
		static void printCPStackAs##level_##G(const category::value_t category_, const char* name, const control_t control = simplePrint) \
		{ \
			printCPStackG(as##level_, category_, name, control); \
		} \
		void printCPStackAs##level_(const category::value_t category_, const char* name, const control_t control = simplePrint)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			printCPStack(as##level_, category_, name, control); \
		} \
		void printCPStackAs##level_(const char* name, const control_t control = simplePrint)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			printCPStack(as##level_, m_category, name, control); \
		}
		declare_printCPMethods(Normal);//�ʏ탁�b�Z�[�W
		declare_printCPMethods(Verbose);//�璷���b�Z�[�W
		declare_printCPMethods(Detail);//�ڍ׃��b�Z�[�W
		declare_printCPMethods(Important);//�d�v���b�Z�[�W
		declare_printCPMethods(Warning);//�x�����b�Z�[�W
		declare_printCPMethods(Critical);//�d��i���j���b�Z�[�W
		declare_printCPMethods(Absolute);//��΁i�K�{�j���b�Z�[�W
	public:
		//�f�t�H���g�R���X�g���N�^
		message():
			m_level(asNormal),//���x��
			m_category(forAny),//�J�e�S��
			m_name(nullptr),//���O
			m_srcFileName(nullptr),//�\�[�X�t�@�C����
			m_funcName(nullptr),//�֐���
			m_attr(0),//�ꎞ�\������
			m_hasPushed(false),//�R�[���|�C���g�X�^�b�N�Ƀv�b�V���ς�
			m_attrHasChanged(false),//�ꎞ�\�������ύX�ς�
			m_logLevelHasChanged(false),//�ꎞ���O���x���ύX�ς�
			m_noticeLevelHasChanged(false),//�ꎞ��ʒʒm���x���ύX�ς�
			m_callPointStackNext(nullptr)//���̃R�[���|�C���g�X�^�b�N
		{
			initializeOnce();
		}
		//�R���X�g���N�^
		message(const level::value_t level_, const category::value_t category_, const char* name, const char* src_file_name = nullptr, const char* func_name = nullptr) :
			m_level(level_),//���x��
			m_category(category_),//�J�e�S��
			m_name(name),//���O
			m_srcFileName(src_file_name),//�\�[�X�t�@�C����
			m_funcName(func_name),//�֐���
			m_attr(0),//�ꎞ�\������
			m_hasPushed(false),//�R�[���|�C���g�X�^�b�N�Ƀv�b�V���ς�
			m_attrHasChanged(false),//�ꎞ�\�������ύX�ς�
			m_logLevelHasChanged(false),//�ꎞ���O���x���ύX�ς�
			m_noticeLevelHasChanged(false),//�ꎞ��ʒʒm���x���ύX�ς�
			m_callPointStackNext(nullptr)//���̃R�[���|�C���g�X�^�b�N
		{
			assert(category_ >= category::NORMAL_MIN && category_ <= category::NORMAL_MAX);
		}
		//�f�X�g���N�^
		~message()
		{
			releaseAttr();//�ꎞ�\�����������
			releaseLogLevel();//�ꎞ���O���x�������
			releaseNoticeLevel();//�ꎞ��ʒʒm���x�������
			popCallPoint();//�R�[���X�^�b�N����|�b�v
		}
	protected:
		//�t�B�[���h
		const level::value_t m_level;//���x��
		const category::value_t m_category;//�J�e�S��
		const char* m_name;//������
		const char* m_srcFileName;//�\�[�X�t�@�C����
		const char* m_funcName;//�֐���
		attr_t m_attr;//�\������
		bool m_hasPushed;//�R�[���|�C���g�X�^�b�N�Ƀv�b�V���ς�
		bool m_attrHasChanged;//�ꎞ�\�������ύX�ς�
		bool m_logLevelHasChanged;//�ꎞ���O���x���ύX�ς�
		bool m_noticeLevelHasChanged;//�ꎞ��ʒʒm���x���ύX�ς�
		message* m_callPointStackNext;//���̃R�[���|�C���g�X�^�b�N
		level::value_t m_logLevel[category::NORMAL_NUM];//�ꎞ���O���x��
		level::value_t m_noticeLevel[category::NORMAL_NUM];//�ꎞ��ʒʒm���x��
	private:
		static bool m_isInitialized;//�������ς݃t���O
		static attr_t m_attrG;//�\������
		static level::value_t m_logLevelG[category::NORMAL_NUM];//���݂̃��O���x��
		static level::value_t m_noticeLevelG[category::NORMAL_NUM];//���݂̉�ʒʒm���x��
		static thread_local int m_attrHasChangedG;//�ꎞ�\�������ύX�X�^�b�N��
		static thread_local int m_logLevelHasChangedG;//�ꎞ���O���x���ύX�X�^�b�N��
		static thread_local int m_noticeLevelHasChangedG;//�ꎞ��ʒʒm���x���ύX�X�^�b�N��
		static thread_local message* m_callPointStackHead;//�R�[���|�C���g�X�^�b�N�̐擪
		static thread_local buff_t* m_messageBuff;//���b�Z�[�W�o�b�t�@
		static thread_local std::size_t m_messageBuffSize;//���b�Z�[�W�o�b�t�@�T�C�Y
		static thread_local std::size_t m_messageBuffUsed;//���b�Z�[�W�o�b�t�@�g�p��
	};
	//----------------------------------------
	//���b�Z�[�W�̐ÓI�ϐ����C���X�^���X��
	bool message::m_isInitialized = false;//�������ς݃t���O
	message::attr_t message::m_attrG = 0;//�\������
	level::value_t message::m_logLevelG[category::NORMAL_NUM];//���݂̃��O���x��
	level::value_t message::m_noticeLevelG[category::NORMAL_NUM];//���݂̉�ʒʒm���x��
	thread_local int message::m_attrHasChangedG = 0;//�ꎞ�\�������ύX�X�^�b�N��
	thread_local int message::m_logLevelHasChangedG = 0;//�ꎞ���O���x���ύX�X�^�b�N��
	thread_local int message::m_noticeLevelHasChangedG = 0;//�ꎞ��ʒʒm���x���ύX�X�^�b�N��
	thread_local message* message::m_callPointStackHead = nullptr;//�R�[���|�C���g�X�^�b�N�̐擪
	thread_local message::buff_t* message::m_messageBuff = nullptr;//���b�Z�[�W�o�b�t�@
	thread_local std::size_t message::m_messageBuffSize = 0;//���b�Z�[�W�o�b�t�@�T�C�Y
	thread_local std::size_t message::m_messageBuffUsed = 0;//���b�Z�[�W�o�b�t�@�g�p��
	//----------------------------------------
	//���b�Z�[�W�������i������j
	void message::initializeOnce()
	{
		//�������ς݃`�F�b�N
		if (m_isInitialized)
			return;
		//�ÓI�ϐ���������
		m_isInitialized = true;
		resetAttrG();
		resetLogLevelAllG();
		resetNoticeLevelAllG();
	}
	//----------------------------------------
	//���b�Z�[�W�p�ϐ�
	static message s_messageForInitialize;//�������������s�̂��߂̃C���X�^���X
	//----------------------------------------
	//�R�[���|�C���g�p�萔
	enum controlEnum : unsigned char//����ݒ�
	{
		recProfile = 0x00,//�v���t�@�C���L�^
		noProfile = 0x01,//�v���t�@�C���s�v
	};
	//----------------------------------------
	//�R�[���|�C���g�N���X
	class callPoint : public message
	{
	public:
		//�^
		typedef uintptr_t key_t;//�L�[�^
		typedef std::chrono::high_resolution_clock::time_point clock_t;//�N���b�N�^
		typedef double duration_t;//�������Ԍ^
		typedef unsigned char control_t;//����ݒ�^
	public:
		//�A�N�Z�b�T
		key_t getKey() const{ return m_key; }//�L�[
		clock_t getBegintime() const{ return m_beginTime; }//�����J�n����
	public:
		//���\�b�h
		//�o�ߎ��Ԏ擾
		duration_t getElapsedTime() const
		{
			const clock_t end_time = std::chrono::high_resolution_clock::now();
			return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - m_beginTime).count()) / 1000000.;
		}
	public:
		//�R���X�g���N�^
		callPoint(const level::value_t level_, const category::value_t category_, const char* name, const controlEnum control, const key_t key, const char* src_file_name, const char* func_name) :
			message(level_, category_, name, src_file_name, func_name),
			m_key(key),
			m_control(control),
			m_beginTime(std::chrono::high_resolution_clock::now())
		{
			pushCallPoint();//�R�[���|�C���g���v�b�V��
		}
		//�f�X�g���N�^
		~callPoint()
		{
			if (!(m_control & noProfile))
			{
				//�X���b�h���擾
				CThreadID thread_id;
				
				//�p�t�H�[�}���X�L�^
				CProfiler profiler;
				profiler.addProfile(m_key, m_name, &thread_id, getFileName(m_srcFileName), m_funcName, getElapsedTime());
			}
			//popCallPoint();//�R�[���|�C���g���|�b�v�@���|�b�v�͐e�N���X���s���̂ŕs�v
		}
	private:
		//�t�B�[���h
		const key_t m_key;//�L�[
		const control_t m_control;//����ݒ�
		const clock_t m_beginTime;//�����J�n����
	};
	template<level::value_t L>
	class callPointAsLevel : public callPoint
	{
	public:
		//�萔
		static const level::value_t LEVEL = L;//���x��
	public:
		//�R���X�g���N�^
		callPointAsLevel(const category::value_t category_, const char* name, const controlEnum control, const key_t key, const char* src_file_name, const char* func_name) :
			callPoint(LEVEL, category_, name, control, key, src_file_name, func_name)
		{}
		//�f�X�g���N�^
		~callPointAsLevel()
		{}
	};
#define declare_callPointClass(level_) using callPointAs##level_ = callPointAsLevel<as##level_>
	declare_callPointClass(Normal);//�ʏ탁�b�Z�[�W
	declare_callPointClass(Verbose);//�璷���b�Z�[�W
	declare_callPointClass(Detail);//�ڍ׃��b�Z�[�W
	declare_callPointClass(Important);//�d�v���b�Z�[�W
	declare_callPointClass(Warning);//�x�����b�Z�[�W
	declare_callPointClass(Critical);//�d��i���j���b�Z�[�W
	declare_callPointClass(Absolute);//��΁i�K�{�j���b�Z�[�W
#define __CPARGS() reinterpret_cast<callPoint::key_t>(GET_CONCATENATED_SOURCE_FILE_NAME()), GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME()
	//----------------------------------------
	//�֐�
	message::attr_t getAttr(){ return message::getAttrG(); }
	//void setAttr(const message::attr_t attr){ message::setAttrG(attr); }
	message::attr_t addAttr(const message::attr_t attr){ return message::addAttrG(attr); }
	message::attr_t delAttr(const message::attr_t attr){ return message::delAttrG(attr); }
	void resetAttr(){ message::resetAttrG(); }
	//���݂̃��O���x�����擾
	level::value_t getLogLevel(const category::value_t category_)
	{
		return message::getLogLevelG(category_);
	}
	//���݂̃��O���x����ύX
	//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
	level::value_t setLogLevel(const level::value_t level_, const category::value_t category_)
	{
		return message::setLogLevelG(level_, category_);
	}
	//���݂̃��O���x�������Z�b�g
	void resetLogLevel(const category::value_t category_)
	{
		message::resetLogLevelG(category_);
	}
	//���݂̃��O���x����S�ă��Z�b�g
	void resetLogLevelAll()
	{
		message::resetLogLevelAllG();
	}
	//���݂̉�ʒʒm���x�����擾
	level::value_t getNoticeLevel(const category::value_t category_)
	{
		return message::getNoticeLevelG(category_);
	}
	//���݂̉�ʒʒm���x����ύX
	//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
	level::value_t setNoticeLevel(const level::value_t level_, const category::value_t category_)
	{
		return message::setNoticeLevelG(level_, category_);
	}
	//���݂̉�ʒʒm���x�������Z�b�g
	void resetNoticeLevel(const category::value_t category_)
	{
		message::resetNoticeLevelG(category_);
	}
	//���݂̉�ʒʒm���x����S�ă��Z�b�g
	void resetNoticeLevelAll()
	{
		message::resetNoticeLevelAllG();
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐��F���x���������w��
	//��vprint***/vlog***/vnotice***
	//��va_list�������ɂƂ�o�[�W����
	static int vprint(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vprintG(level_, category_, fmt, args);
	}
	static int vlog(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vlogG(level_, category_, fmt, args);
	}
	static int vnotice(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vnoticeG(level_, category_, fmt, args);
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐��F���x���������w��
	//��print***/log***/notice***
	//���ϒ������o�[�W����
	static int print(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vprintG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	static int log(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vlogG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	static int notice(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vnoticeG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐���`�}�N��
	//��vprint***/vlog***/vnotice***
	//��va_list�������ɂƂ�o�[�W����
#define declare_vprintFuncs(level_) \
	static int vprintAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vprintAs##level_##G(category_, fmt, args); \
	} \
	static int vlogAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vlogAs##level_##G(category_, fmt, args); \
	} \
	static int vnoticeAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vnoticeAs##level_##G(category_, fmt, args); \
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐���`�}�N��
	//��print***/log***/notice***
	//���ϒ������o�[�W����
#define declare_printFuncs(level_) \
	static int printAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vprintAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	} \
	static int logAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vlogAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	} \
	static int noticeAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vnoticeAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐���`
	//��vprint***/vlog***/vnotice***
	//��va_list�������ɂƂ�o�[�W����
	declare_vprintFuncs(Normal);//�ʏ탁�b�Z�[�W
	declare_vprintFuncs(Verbose);//�璷���b�Z�[�W
	declare_vprintFuncs(Detail);//�ڍ׃��b�Z�[�W
	declare_vprintFuncs(Important);//�d�v���b�Z�[�W
	declare_vprintFuncs(Warning);//�x�����b�Z�[�W
	declare_vprintFuncs(Critical);//�d��i���j���b�Z�[�W
	declare_vprintFuncs(Absolute);//��΁i�K�{�j���b�Z�[�W
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐���`
	//��print***/log***/notice***
	//���ϒ������o�[�W����
	declare_printFuncs(Normal);//�ʏ탁�b�Z�[�W
	declare_printFuncs(Verbose);//�璷���b�Z�[�W
	declare_printFuncs(Detail);//�ڍ׃��b�Z�[�W
	declare_printFuncs(Important);//�d�v���b�Z�[�W
	declare_printFuncs(Warning);//�x�����b�Z�[�W
	declare_printFuncs(Critical);//�d��i���j���b�Z�[�W
	declare_printFuncs(Absolute);//��΁i�K�{�j���b�Z�[�W
	void printCPStack(const level::value_t level_, category::value_t category_, const char* name, const message::control_t control = simplePrint)
	{
		message::printCPStackG(level_, category_, name, control);
	}
#define declare_printCPFunc(level_) \
	static void printCPStackAs##level_(const category::value_t category_, const char* name, const message::control_t control = simplePrint) \
	{ \
		message::printCPStackAs##level_##G(category_, name, control); \
	}
	declare_printCPFunc(Normal);//�ʏ탁�b�Z�[�W
	declare_printCPFunc(Verbose);//�璷���b�Z�[�W
	declare_printCPFunc(Detail);//�ڍ׃��b�Z�[�W
	declare_printCPFunc(Important);//�d�v���b�Z�[�W
	declare_printCPFunc(Warning);//�x�����b�Z�[�W
	declare_printCPFunc(Critical);//�d��i���j���b�Z�[�W
	declare_printCPFunc(Absolute);//��΁i�K�{�j���b�Z�[�W
}//namespce dbg

//----------------------------------------
//�f�o�b�O���b�Z�[�W�̃��[�U�[�g��
namespace dbg
{
	//���[�U�[�g��
	namespace ext
	{
		//----------------------------------------
		//�J�e�S���萔
		enum categoryEnum : category::value_t
		{
			forThread = define_revervedCategory(0),//�X���b�h
			forTaro = define_revervedCategory(1),//���Y��p
		};
		//----------------------------------------
		//�J�e�S����`
		//���w�b�_�[�Ō��J����K�v�Ȃ�
		declare_reservedCategory(forThread, true, false);//�X���b�h
		declare_reservedCategory(forTaro, true, true);//���Y��p
		//----------------------------------------
		//�J�e�S���R���e�i�g��������
		struct categoryContainerExt
		{
			categoryContainerExt()
			{
				category::container::initializeOnce();
				category_forThread();//�X���b�h
				category_forTaro();//���Y��p
			}
		};
		//----------------------------------------
		//�ϐ�
		static categoryContainerExt s_categoryForInitialize;//�������������s�̂��߂̃C���X�^���X
	}//namespace ext
}//namespace dbg



//----------------------------------------
//�e�X�g

//�l�[���X�[�y�[�X�\�L�ȗ��p
using namespace dbg;
using namespace dbg::ext;

//--------------------
//�e�X�g�i���ʊ֐��j
void printCommon(const char* name)
{
	printf("---------- printCommon(%s) ----------\n", name);
	printAsNormal(forAny, "�ʏ탁�b�Z�[�W(%s)\n", name);
	printAsVerbose(forAny, "�璷���b�Z�[�W\n");
	printAsDetail(forAny, "�ڍ׃��b�Z�[�W\n");
	printAsImportant(forAny, "�d�v���b�Z�[�W\n");
	printAsWarning(forAny, "�x�����b�Z�[�W\n");
	printAsCritical(forAny, "�d�僁�b�Z�[�W\n");
	printAsAbsolute(forAny, "��΃��b�Z�[�W\n");
	printAsNormal(for3D, "�y3D�z�ʏ탁�b�Z�[�W\n");
	printAsNormal(for2D, "�y2D�z�ʏ탁�b�Z�[�W\n");
	printAsNormal(forLogic, "�yLogic�z�ʏ탁�b�Z�[�W\n");
	printAsCritical(forCallPoint, "�yCP�̃J�e�S���z�d�僁�b�Z�[�W\n");
	printAsCritical(forCriticalCallPoint, "�y�N���e�B�J��CP�̃J�e�S���z�d�僁�b�Z�[�W\n");
	print(asNormal, forAny, "�y���x���������w��z�ʏ탁�b�Z�[�W\n");
	logAsCritical(forAny, "�y���O�o�͐�p�֐��z�d�僁�b�Z�[�W\n");
	noticeAsCritical(forAny, "�y��ʒʒm��p�֐��z�d�僁�b�Z�[�W\n");
	printCPStackAsNormal(forAny, "CP(�R�[���|�C���g)�X�^�b�N�\��");
}
//�����_�����ԃE�F�C�g����
static std::mt19937 s_rndEngine;
void initRnadom()//������
{
	//����������
	std::random_device rd;
	s_rndEngine.seed(rd());
}
void randomWait()//�E�F�C�g
{
	std::uniform_int_distribution<int> time(10, 100);
	const int sleep_time = time(s_rndEngine);
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
}
//--------------------
//�e�X�g�i�[���Q�[�����[�v�j
void gameLoop()
{
	for (int frame = 0; frame < 10; ++frame)
	{
		//�t���[���̏����J�n
		//���f�X�g���N�^�ŏ������邽�߁A�����u���b�N�ň͂�
		{
			callPointAsCritical cp(forAny, "�Q�[�����[�v", recProfile, __CPARGS());
			extern void subProc1();
			extern void subProc2();
			extern void subProc3();
			extern void subProc4();
			extern void subProc5();
			extern void subProc6();
			extern void subProc7(const char* thread_name);
			std::thread th1 = std::thread(subProc7, "�X���b�hA");
			subProc1();//�����P
			subProc2();//�����Q
			subProc3();//�����R
			std::thread th2 = std::thread(subProc7, "�X���b�hB");
			subProc4();//�����S
			subProc5();//�����T
			subProc6();//�����U
			std::thread th3 = std::thread(subProc7, "�X���b�hC");
			printCommon(cp.getName());//���ʏ���
			th1.join();
			th2.join();
			th3.join();
		}

		//�t���[���̏������Ԃ��W�v
		{
			CProfiler profiler;
			profiler.sumOnFrame();
		}
	}
}
//�����P
void subProc1()
{
	callPointAsNormal cp(for3D, "�����P�F�\�������ύX", recProfile, __CPARGS());
	cp.delAttr(withLevel);//���x���\���Ȃ�
	//cp.delAttr(withCategory);//�J�e�S���\���Ȃ�
	randomWait();//�E�F�C�g
	printCommon(cp.getName());//���ʏ���
}
//�����Q
void subProc2()
{
	callPointAsNormal cp(for2D, "�����Q�F�Î�", recProfile, __CPARGS());
	cp.setLogLevel(asSilent, forEvery);//�ȍ~�̃��O�\���Ȃ��i��ʒʒm�͂���j
	randomWait();//�E�F�C�g
	printCommon(cp.getName());//���ʏ���
}
//�����R
void subProc3()
{
	callPointAsNormal cp(forLogic, "�����R�F�J���[��\��", recProfile, __CPARGS());
	cp.addAttr(withoutColor);//�J���[�\���Ȃ��i���O�ɂ̂݉e���j
	randomWait();//�E�F�C�g
	printCommon(cp.getName());//���ʏ���
}
//�����S
void subProc4()
{
	callPointAsNormal cp(forGameData, "�����S�F��ΐÎ�", recProfile, __CPARGS());
	cp.setLogLevel(asSilentAbsolutely, forAny);//�ȍ~��forAny�̃��O�\�������S��~
	cp.setNoticeLevel(asSilentAbsolutely, forEvery);//�ȍ~�̑S�Ẳ�ʒʒm�\�������S��~
	randomWait();//�E�F�C�g
	printCommon(cp.getName());//���ʏ���
}
//�����T
void subProc5()
{
	callPointAsNormal cp(forSound, "�����T�F�Ȃɂ����Ȃ�", recProfile, __CPARGS());
	randomWait();//�E�F�C�g
	printCommon(cp.getName());//���ʏ���
}
//�����U
void subProc6()
{
	//�R�[���|�C���g���N���e�B�J��
	callPointAsCritical cp(forTaro, "�����U�F�N���e�B�J��CP", recProfile, __CPARGS());
	randomWait();//�E�F�C�g
	subProc5();
}
//�����V
void subProc7(const char* thread_name)
{
	callPointAsCritical cp(forThread, "�����V�F�X���b�h", recProfile, __CPARGS());
	CThreadID thread_id(thread_name);
	//�X���b�h�p�i�E�F�C�g�̂݁j
	randomWait();//�E�F�C�g
}
//--------------------
//�e�X�g�i�v���t�@�C����\���j
void printProfile()
{
	printf("--- PROFILE ---\n");
	CProfiler profiler;
	printf("size()=%d, Buffer:Total=%d,Used=%d,Remain=%d\n", profiler.size(), profiler.getBuffTotal(), profiler.getBuffUsed(), profiler.getBuffRemain());
	CStackAllocatorWithBuff<2048> work;//���[�N�̈�m��
	CTempPolyStackAllocator alloc(work);//new ���Z�q�Ń��[�N�̈���g���悤�ɐݒ�i�����u���b�N�𔲂����玩�������j
	//�\�[�g�̂��߂�vector�Ɉڂ��ւ�
	typedef std::vector<const CProfiler::PROFILE*> vec_t;
	vec_t vec;
	for (auto& o : profiler)
	{
		const CProfiler::PROFILE& profile = o.second;
		vec.push_back(&profile);
	}
	//�\�[�g
	//���g�[�^���������Ԃ��傫����
	std::sort(vec.begin(), vec.end(),
		[](const CProfiler::PROFILE* lhs, const CProfiler::PROFILE* rhs)->bool
	{
		return lhs->m_total.sum > rhs->m_total.sum;
	}
	);
	//�\��
	for (auto& ite : vec)
	{
		const CProfiler::PROFILE& profile = *ite;
		//printf("name=\"%s\", funcname=\"%s\", srcFileName=\"%s\", TOTAL:(count=%d, sum=%.6llf, max=%.6f, min=%.6f, ave=%.6f), FRAME:(count=%d, sum=%.6llf, max=%.6f, min=%.6f, ave=%.6f), frameCount=%d\n",
		//	profile.m_name.c_str(), profile.m_funcName.c_str(), profile.m_srcFileName.c_str(), 
		//	profile.m_total.count, profile.m_total.sum, profile.m_total.min, profile.m_total.max, profile.m_total.average(), 
		//	profile.m_frame.count, profile.m_frame.sum, profile.m_frame.min, profile.m_frame.max, profile.m_frame.average(), 
		//	profile.m_frameCount);
		printf("%8.6fsec (%d cnt): \"%s\" %s\n", profile.m_total.sum, profile.m_total.count, profile.m_name.c_str(), profile.m_funcName.c_str());
	}
	printf("work:total=%d,used=%d,remain=%d\n", work.getTotal(), work.getUsed(), work.getRemain());
}

//--------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	//�X���b�h�ɖ��O��t����
	CThreadID("���C���X���b�h");

	//���x�����
	printf("---------- ���x����� ----------\n");
	printLevelAll();
	
	//�J�e�S�����
	printf("---------- �J�e�S����� ----------\n");
	printCategoryAll();

	//������ԂŃv�����g
	printCommon("�������");

	//�[���Q�[�����[�v
	gameLoop();

	//�v���t�@�C����\��
	printProfile();

	return EXIT_SUCCESS;
}

// End of file
