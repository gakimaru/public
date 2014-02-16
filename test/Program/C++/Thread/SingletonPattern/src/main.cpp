#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//C++11���C�u����
#include <thread>//�X���b�h
#include <mutex>//�~���[�e�b�N�X
#include <atomic>//�A�g�~�b�N�^

//--------------------------------------------------------------------------------
//��{�}�N��

//�u���[�N�|�C���g
#include <windows.h>//�u���[�N�|�C���g�p
#define BREAK_POINT() DebugBreak()

//�f�o�b�O�v�����g
#define DEBUG_PRINT(msg, ...) printf(msg, __VA_ARGS__);
#define DEBUG_FPRINT(fp, msg, ...) fprintf(fp, msg, __VA_ARGS__);
#define DEBUG_FLUSH() fflush(stdout)
#define DEBUG_FFLUSH(fp) fflush(fp)
//#define DEBUG_PRINT(msg, ...)
//#define DEBUG_FPRINT(fp, msg, ...)
//#define DEBUG_FLUSH()
//#define DEBUG_FFLUSH(fp) fflush(fp)

//�����񉻃}�N��
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)
#define COLLECT_STRING(s) s

//�A�T�[�V����
#define ASSERT(expr, msg, ...) \
	if(!(expr)) \
	{ \
		DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
		                "  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
						"  "  msg "\n", __VA_ARGS__); \
		BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//�폜�p
//#include <assert.h>//assert�p
//#define ASSERT(expr, msg, ...) assert(expr)//VC++�W����

//�ÓI�A�T�[�V����
//��C++11�d�l
//�����{��g�p�s��
#define STATIC_ASSERT(expr, msg) static_assert(expr, msg)
//#define STATIC_ASSERT(expr, msg)//�폜�p

//�X���b�h���[�J���X�g���[�W�C���q
//��C++11�d�l�U���iVC++2013�ł͖��Ή��ɂ��j
//�����g��Windows�d�l
#define thread_local __declspec(thread)

//----------------------------------------
//�X���b�hID�N���X
//��TLS�����p���č�����

//�X���b�hID�^
//typedef std::thread::id THREAD_ID;//C++11/ �����̌^�ł͈��킸�A�n�b�V���l���g�p����
typedef std::size_t THREAD_ID;//C++11
static const THREAD_ID INVALID_THREAD_ID = 0xffffffff;//�����ȃX���b�hID

//���݂̃X���b�hID�擾�֐�
//inline THREAD_ID  GetThisThreadID(){ return std::this_thread::get_id(); } //C++11
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id().hash(); } //C++11

//�X���b�hID�N���X
class CThreadID
{
public:
	//�A�N�Z�b�T
	const THREAD_ID getID() const { return m_threadId; }//�X���b�hID���擾
	const char* getName() const { return m_threadName; }//�X���b�h�����擾
public:
	//�A�N�Z�b�T�istatic�j
	static THREAD_ID getThisID(){ return m_thisThreadID; }//���݂̃X���b�h�̃X���b�hID���擾
	static const char* getThisName(){ return m_thisThreadName; }//���݂̃X���b�h�̃X���b�h�����擾
public:
	//���\�b�h
	bool isThisThread() const { return m_threadId == getThisID(); }//���݂̃X���b�h�Ɠ����X���b�h������
private:
	//���\�b�h(static)
	static void setThisThread()//���݂̃X���b�h�̃X���b�hID���Z�b�g
	{
		if (m_thisThreadID == INVALID_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
	}
	static void resetThisThread(const char* name)//���݂̃X���b�h�̃X���b�hID�����Z�b�g
	{
		m_thisThreadID = GetThisThreadID();
		m_thisThreadName = name;
	}
public:
	//�I�y���[�^�i���j
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID��v����
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID�s��v����
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID��v����
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID�s��v����
	CThreadID& operator=(const CThreadID& o) //�R�s�[���Z�q
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
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
	//�f�t�H���g�R���X�g���N�^
	//������TLS�ɋL�^�ς݂̃X���b�hID�i�Ɩ��O�j���擾
	CThreadID()
	{
		setThisThread();
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
private:
	//�t�B�[���h
	THREAD_ID m_threadId;//�X���b�hID�i�I�u�W�F�N�g�ɕۑ�����l�j
	const char* m_threadName;//�X���b�h���i�I�u�W�F�N�g�ɕۑ�����l�j
	static thread_local THREAD_ID m_thisThreadID;//���݂̃X���b�h�̃X���b�hID(TLS)
	static thread_local const char* m_thisThreadName;//���݂̃X���b�h��(TLS)
};
//static�ϐ��̃C���X�^���X��
thread_local THREAD_ID CThreadID::m_thisThreadID = INVALID_THREAD_ID;//�X���b�hID(TLS)
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

//--------------------------------------------------------------------------------
//�Œ胁�����u���b�N�A���P�[�^�N���X
//������͉ǐ��d�������A���ۂɂ̓e���v���[�g�̃C���X�^���X���ɂ��
//�@�v���O�����T�C�Y�̔����l�����A��e���v���[�g�̋��ʏ�����
//�@�؂�o���K�v������

//----------------------------------------
//�N���X�錾
template<std::size_t N, std::size_t S>
class CBlockAllocator;

//----------------------------------------
//�Œ胁�����u���b�N�A���P�[�^�N���X��p�z�unew/delete����
//���N���X���Ŏg�p���邽�߂̂��̂Ȃ̂ŁA���ڎg�p�͋֎~
//���N���X����delete���邱�ƂŁA�f�X�g���N�^�̌Ăяo���ɂ��Ή�

//�z�unew
template<std::size_t N, std::size_t S>
void* operator new(const std::size_t size, CBlockAllocator<N, S>& allocator){ return allocator.alloc(size); }

//�z�udelete
template<std::size_t N, std::size_t S>
void operator delete(void* p, CBlockAllocator<N, S>& allocator){ allocator.free(p); }

//----------------------------------------
//�Œ胁�����u���b�N�A���P�[�^�N���X
//���X���b�h�Z�[�t�Ή�
template<std::size_t N, std::size_t S>
class CBlockAllocator
{
public:
	//�^�錾
	typedef unsigned char byte;//�o�b�t�@�p
	typedef unsigned int b32;//�t���O�p
public:
	//�萔
	static const std::size_t BLOCKS_NUM = N;//�u���b�N��
	static const std::size_t BLOCK_SIZE = S;//�������u���b�N�T�C�Y
	static const std::size_t FLAG_SIZE = ((N + 31) >> 5);//�t���O�T�C�Y�i�P�T�C�Y��32�r�b�g�̃t���O�j
	static const std::size_t FLAG_SURPLUS_BITS = N % 32;//�]��t���O���i32�̔{������͂ݏo�����t���O�̐��j
private:
	//���\�b�h
	//�������m�ۏ�ԃ��Z�b�g
	void reset()
	{
		//���b�N�擾
		m_lock.lock();

		//�[���N���A
		memset(m_used, 0, sizeof(m_used));

		//�u���b�N���͈̔͊O�̃t���O�͍ŏ����痧�ĂĂ���
		if (FLAG_SURPLUS_BITS > 0)
		{
			b32 parmanent = 0xffffffff >> FLAG_SURPLUS_BITS;
			parmanent <<= FLAG_SURPLUS_BITS;
			m_used[FLAG_SIZE - 1] = parmanent;
		}

		//���b�N���
		m_lock.unlock();
	}
	//�������u���b�N�m��
	//���g�p���t���O�̋󂫂��������ăt���O���X�V���A
	//�@�m�ۂ����C���f�b�N�X��Ԃ�
	int assign()
	{
		//���b�N�擾
		m_lock.lock();

		//�m�ۍς݃C���f�b�N�X����
		int index = -1;//������Ԃ͎��s���

		//�󂫃t���O����
		b32* used_p = m_used;
		int bit_no = 0;
		for (int arr_idx = 0; arr_idx < FLAG_SIZE; ++arr_idx, ++used_p)
		{
			//32bit���Ƃ̋󂫔���
			b32 bits_now = *used_p;
			if (bits_now != 0xffffffff)
			{
				//32bit�̃t���O�̂ǂ����ɋ󂫂�����̂ŁA
				//�ŏ��ɋ󂢂Ă���t���O�i�r�b�g�j������
				b32 bits = bits_now;
				if ((bits & 0xffff) == 0xffff){ bit_no += 16; bits >>= 16; }//����16�r�b�g����i�󂫂��Ȃ����16�r�b�g�V�t�g�j
				if ((bits & 0xff) == 0xff){ bit_no += 8;  bits >>= 8; }//����8�r�b�g����i�󂫂��Ȃ����8�r�b�g�V�t�g�j
				if ((bits & 0xf) == 0xf){ bit_no += 4;  bits >>= 4; }//����4�r�b�g����i�󂫂��Ȃ����4�r�b�g�V�t�g�j
				if ((bits & 0x3) == 0x3){ bit_no += 2;  bits >>= 2; }//����2�r�b�g����i�󂫂��Ȃ����2�r�b�g�V�t�g�j
				if ((bits & 0x1) == 0x1){ ++bit_no; }//����1�r�b�g����i�󂫂��Ȃ���Ώ��1�r�b�g�Ŋm��j
				bits_now |= (1 << bit_no);//�_���a�p�̃r�b�g���ɕϊ�
				*used_p = bits_now;//�_���a
				index = arr_idx * 32 + bit_no;//�������u���b�N�̃C���f�b�N�X�Z�o

				//�m�ې���
				break;
			}
		}

		//���b�N���
		m_lock.unlock();

		//�I��
		return index;
	}
	//�������u���b�N���
	//���w��̃C���f�b�N�X�̎g�p���t���O�����Z�b�g
	void release(const int index)
	{
		//�C���f�b�N�X�͈̔̓`�F�b�N
		if (index < 0 || index >= BLOCKS_NUM)
			return;

		//���b�N�擾
		m_lock.lock();

		//�t���O���
		const int arr_idx = index >> 5;//�g�p���t���O�̔z��ԍ�
		const int bit_no = index & 31;//�r�b�g�ԍ�
		m_used[arr_idx] &= ~(1 << bit_no);//�_����

		//���b�N���
		m_lock.unlock();
	}
public:
	//�������m��
	void* alloc(const std::size_t size)
	{
		//�y�A�T�[�V�����z�v���T�C�Y���u���b�N�T�C�Y�𒴂���ꍇ�͑����m�ێ��s
		ASSERT(size <= BLOCK_SIZE, "CBlockAllocator::alloc(%d) cannot allocate. Size must has been under %d.", size, BLOCK_SIZE);
		if (size > BLOCK_SIZE)
		{
			return nullptr;
		}
		//�󂫃u���b�N���m�ۂ��ĕԂ�
		const int index = assign();
		//�y�A�T�[�V�����z�S�u���b�N�g�p���ɂ��A�m�ێ��s
		ASSERT(index >= 0, "CBlockAllocator::alloc(%d) cannot allocate. Buffer is full. (num of blocks is %d)", size, BLOCKS_NUM);
		//�m�ۂ�����������Ԃ�
		return index < 0 ? nullptr : &m_buff[index];
	}
	//���������
	void free(void * p)
	{
		//nullptr���͑���������s
		ASSERT(p != nullptr, "CBlockAllocator::free() cannot free. Pointer is null.");
		if (!p)
			return;
		//�|�C���^����C���f�b�N�X���Z�o
		const byte* top_p = reinterpret_cast<byte*>(m_buff);//�o�b�t�@�̐擪�|�C���^
		const byte* target_p = reinterpret_cast<byte*>(p);//�w��|�C���^
		const int diff = (target_p - top_p);//�|�C���^�̈����Z�ō��̃o�C�g���Z�o
		const int index = (target_p - top_p) / BLOCK_SIZE;//�u���b�N�T�C�Y�Ŋ����ăC���f�b�N�X�Z�o
		//�y�A�T�[�V�����z�������o�b�t�@�͈̔͊O�Ȃ珈�����s�irelease�֐����Ŏ��s����̂ł��̂܂܎��s�j
		ASSERT(index >= 0 && index < BLOCKS_NUM, "CBlockAllocator::free() cannot free. Pointer is different.");
		//�y�A�T�[�V�����z�|�C���^���e�u���b�N�̐擪���w���Ă��邩�`�F�b�N
		//�@�@�@�@�@�@�@�@�ˑ��d�p���ƃL���X�g���Ă���Ƃ���邱�Ƃ���̂ł��̖��͖������ĉ�����Ă��܂�
		//ASSERT(diff % BLOCK_SIZE == 0, "CBlockAllocator::free() cannot free. Pointer is illegal.");
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
		p->~T();//�����I�ȃf�X�g���N�^�Ăяo���i�f�X�g���N�^����`�̃N���X�ł����Ȃ��j
		operator delete(p, *this);//�z�udelete�Ăяo��
		p = nullptr;//�|�C���^�ɂ�nullptr���Z�b�g
	}
public:
	//�R���X�g���N�^
	CBlockAllocator()
	{
		//�g�p���t���O���Z�b�g
		reset();
	}
	//�f�X�g���N�^
	~CBlockAllocator()
	{}
private:
	//�t�B�[���h
	byte m_buff[BLOCKS_NUM][BLOCK_SIZE];//�u���b�N�o�b�t�@
	b32 m_used[FLAG_SIZE];//�g�p���t���O
	CSpinLock m_lock;//���b�N
};

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

//--------------------------------------------------------------------------------
//�V���O���g���N���X
//������͉ǐ��d�������A���ۂɂ̓e���v���[�g�̃C���X�^���X���ɂ��
//�@�v���O�����T�C�Y�̔����l�����A��e���v���[�g�̋��ʏ�����
//�@�؂�o���K�v������

//----------------------------------------
//�N���X�錾
//��friend�錾�̂��߂̎��O�錾

//���ʃV���O���g���e���v���[�g�@���p����p
template<class T, class U>
class CSingletonCommon;

//�ʏ�V���O���g���e���v���[�g�N���X
template<class T>
class CSingleton;

//�Ǘ��V���O���g���e���v���[�g�N���X
template<class T>
class CManagedSingleton;

//�y�V���O���g���p�w���p�[�z�V���O���g���v���L�V�[�e���v���[�g�N���X�@���p����p
template<class T>
class CSingletonProxy;

//�y�V���O���g���p�w���p�[�z�V���O���g���C�j�V�����C�U�[�e���v���[�g�N���X
template<class T>
class CSingletonInitializer;

//�y�V���O���g���p�w���p�[�z�V���O���g���A�N�Z�X�e���v���[�g�N���X
template<class T>
class CSingletonUsing;

//----------------------------------------
//�V���O���g�������p�萔��`
class CSingletonConst
{
public:
	//�萔��`

	//�V���O���g������
	enum E_ATTR
	{
		ATTR_AUTO_CREATE,             //���������i�j�����Ȃ��j
		ATTR_AUTO_CREATE_AND_DELETE,  //���������Ǝ����j��
		ATTR_MANUAL_CREATE_AND_DELETE,//�蓮�����Ǝ蓮�j��
	};
	//�X���b�h�Z�[�t�錾
	enum E_IS_THREAD_SAFE
	{
		IS_THREAD_SAFE = true,//�X���b�h�Z�[�t�錾
		IS_NOT_THREAD_SAFE = false,//��X���b�h�Z�[�t�錾
	};
	//�Ǘ��V���O���g���錾
	enum E_IS_MANAGED_SINGLETON
	{
		IS_NORMAL_SINGLETON = false,//�ʏ�V���O���g���錾
		IS_MANAGED_SINGLETON = true,//�Ǘ��V���O���g���錾
	};
	//�V���O���g�������ςݏ��
	enum E_IS_CREATED
	{
		IS_NOT_CREATED = false,//������
		IS_CREATED = true,//�����ς�
	};
	//���������w��
	enum E_IS_FORCED
	{
		IS_FORCED = true,//����
		IS_NORMAL = false,//�ʏ�
	};
	//�t�@�C�i���C�Y�����w��
	enum E_IS_FINALIZE
	{
		IS_FINALIZE = true,//�t�@�C�i���C�Y
		IS_RELEASE = false,//�Q�ƃJ�E���^�����[�X
	};
	//�V���O���g���C�j�V�����C�U�[�w��
	enum E_IS_INITIALIZER
	{
		IS_INITIALIZER = true,//�V���O���g���C�j�V�����C�U�[
		IS_USING = false,//�V���O���g���A�N�Z�X
	};
public:
	//�f�[�^�^
	
	//�y�e���v���[�g�N���X�̋�����錾���A�ÓI�A�T�[�V�����istatic_assert�j���s�����߂̍\���́z
	//�R���p�C������ݒ�p�\���́F�ʏ�V���O���g���錾
	struct AUTO_SINGLETON_TYPE
	{
		static const E_IS_MANAGED_SINGLETON THIS_IS_MANAGED_SINGLETON = IS_NORMAL_SINGLETON;
	};
	//�R���p�C������ݒ�p�\���́F�Ǘ��V���O���g���錾
	struct MANAGED_SINGLETON_TYPE
	{
		static const E_IS_MANAGED_SINGLETON THIS_IS_MANAGED_SINGLETON = IS_MANAGED_SINGLETON;
	};
public:
	//���\�b�h
	//�y�萔�����񉻁z�V���O���g������
	static const char* Attr_ToStr(const E_ATTR attr)
	{
		#define CASE_TO_STR(x) case ATTR_##x: return #x; break;
		switch (attr)
		{
		CASE_TO_STR(AUTO_CREATE);
		CASE_TO_STR(AUTO_CREATE_AND_DELETE);
		CASE_TO_STR(MANUAL_CREATE_AND_DELETE);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//�y�萔�����񉻁z�X���b�h�Z�[�t�錾
	static const char* IsThreadSafe_ToStr(const E_IS_THREAD_SAFE is_thread_safe)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_thread_safe)
		{
		CASE_TO_STR(IS_THREAD_SAFE);
		CASE_TO_STR(IS_NOT_THREAD_SAFE);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//�y�萔�����񉻁z�Ǘ��V���O���g���錾
	static const char* IsManagedSingleton_ToStr(const E_IS_MANAGED_SINGLETON is_managed_singleton)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_managed_singleton)
		{
		CASE_TO_STR(IS_MANAGED_SINGLETON);
		CASE_TO_STR(IS_NORMAL_SINGLETON);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//�y�萔�����񉻁z�V���O���g�������ςݏ��
	static const char* IsCreated_ToStr(const E_IS_CREATED is_created)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_created)
		{
		CASE_TO_STR(IS_CREATED);
		CASE_TO_STR(IS_NOT_CREATED);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//�y�萔�����񉻁z���������w��
	static const char* IsForced_ToStr(const E_IS_FORCED is_forced)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_forced)
		{
		CASE_TO_STR(IS_FORCED);
		CASE_TO_STR(IS_NORMAL);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//�y�萔�����񉻁z�t�@�C�i���C�Y�w��
	static const char* IsFinalize_ToStr(const E_IS_FINALIZE is_finalize)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_finalize)
		{
		CASE_TO_STR(IS_FINALIZE);
		CASE_TO_STR(IS_RELEASE);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//�y�萔�����񉻁z�C�j�V�����C�U�[�w��
	static const char* IsInitializer_ToStr(const E_IS_INITIALIZER is_initializer)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_initializer)
		{
		CASE_TO_STR(IS_INITIALIZER);
		CASE_TO_STR(IS_USING);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//�y�萔�����񉻁z�_���l
	static const char* Bool_ToStr(const bool flag)
	{
		return flag ? "TRUE" : "FALSE";
	}
};

//----------------------------------------
//���ʃV���O���g���e���v���[�g�N���X�@���p����p
template<class T, class U>
class CSingletonCommon
{
	//�t�����h�N���X
	friend class CSingleton<T>;
	friend class CManagedSingleton<T>;
	friend class CSingletonProxy<T>;
	friend class CSingletonInitializer<T>;
	friend class CSingletonUsing<T>;
public:
	//�V���O���g���ݒ���e���v���[�g�����̃N���X�Ɋ�Â��ĐÓI�Ɋm��
	//���N���X T �ɂ́A�萔 CLASS_NAME, SINGLETON_ATTR, IS_THREAD_SAFE ����`����Ă���K�v������B
	//���N���X U �ɂ́A�萔 THIS_IS_MANAGED_SINGLETON ����`����Ă���K�v������B
	//static const char* T::CLASS_NAME;//�N���X�� ��char*�^�̂��߁A�N���X�̐ÓI�Ȓl�Ƃ��Ĕ��f�ł��Ȃ�
	static const CSingletonConst::E_ATTR THIS_SINGLETON_ATTR = T::SINGLETON_ATTR;//�V���O���g������
	static const CSingletonConst::E_IS_THREAD_SAFE THIS_IS_THREAD_SAFE = T::THIS_IS_THREAD_SAFE;//�X���b�h�Z�[�t�錾
	static const CSingletonConst::E_IS_MANAGED_SINGLETON THIS_IS_MANAGED_SINGLETON = U::THIS_IS_MANAGED_SINGLETON;//�Ǘ��V���O���g���錾
	
	//�y�ÓI�A�T�[�V�����z�ʏ�V���O���g���ł́A�u�蓮���������FATTR_MANUAL_CREATE_AND_DELETE�v���g�p����ƃA�T�[�V�����ᔽ
	STATIC_ASSERT(THIS_IS_MANAGED_SINGLETON == CSingletonConst::IS_NORMAL_SINGLETON && THIS_SINGLETON_ATTR != CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE ||
		          THIS_IS_MANAGED_SINGLETON != CSingletonConst::IS_NORMAL_SINGLETON,
		"CSingleton<T> is not supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");

	//�y�ÓI�ÓI�A�T�[�V�����z�Ǘ��V���O���g���ł́A�u�蓮���������FATTR_MANUAL_CREATE_AND_DELETE�v�ȊO���g�p����ƃA�T�[�V�����ᔽ
	STATIC_ASSERT(THIS_IS_MANAGED_SINGLETON == CSingletonConst::IS_MANAGED_SINGLETON && THIS_SINGLETON_ATTR == CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE ||
		          THIS_IS_MANAGED_SINGLETON != CSingletonConst::IS_MANAGED_SINGLETON,
		"CManagedSingleton<T> is only supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");
	
private:
	//�C���X�^���X�����E�j���p�z�unew/delete
	//��new �͓����Ŏ��� static �o�b�t�@�̃|�C���^��Ԃ�����
	//��delete �͉������Ȃ�
	//���R���X�g���N�^�A�f�X�g���N�^�����s���āA�I�u�W�F�N�g�̏������E�I�����������s���邱�Ƃ��ړI
	void* operator new(const size_t size){ return m_buff; }
	void operator delete(void*){}
public:
	//�A�N�Z�b�T
	const char* getClassName() const { return T::CLASS_NAME; }//�N���X���擾
	CSingletonConst::E_ATTR getAttr() const { return THIS_SINGLETON_ATTR; }//�V���O���g�������擾
	const char* getAttr_Named() const { return CSingletonConst::Attr_ToStr(getAttr()); }//�V���O���g���������擾�i�f�o�b�O�p�j
	CSingletonConst::E_IS_THREAD_SAFE isThreadSafe() const { return THIS_IS_THREAD_SAFE; }//�X���b�h�Z�[�t�錾�擾
	const char* isThreadSafe_Named() const { return CSingletonConst::IsThreadSafe_ToStr(isThreadSafe()); }//�X���b�h�Z�[�t�錾���擾�i�f�o�b�O�p�j
	CSingletonConst::E_IS_MANAGED_SINGLETON isManagedSingleton() const { return THIS_IS_MANAGED_SINGLETON; }//�Ǘ��V���O���g���錾�擾
	const char* isManagedSingleton_Named() const { return CSingletonConst::IsManagedSingleton_ToStr(isManagedSingleton()); }//�Ǘ��V���O���g���錾���擾�i�f�o�b�O�p�j
	CSingletonConst::E_IS_CREATED isCreated() const { return m_this.load() != nullptr ? CSingletonConst::IS_CREATED : CSingletonConst::IS_NOT_CREATED; }//�N���X(T)�C���X�^���X�����ςݏ�Ԏ擾
	const char* isCreated_Named() const { return CSingletonConst::IsCreated_ToStr(isCreated()); }//�N���X(T)�C���X�^���X�����ςݏ�Ԗ��擾�i�f�o�b�O�p�j
private:
	T* getThis() { return m_this.load(); }//�N���X(T)�C���X�^���X�̎Q�Ƃ��擾�i�֎~�j
	const T* getThis() const { return m_this.load(); }//�N���X(T)�C���X�^���X��const�Q�Ƃ��擾�i�֎~�j
public:
	int getRefCount() const { return m_refCount.load(); }//�Q�ƃJ�E���^�擾
	int getRefCountMax() const { return m_refCountMax.load(); }//�Q�ƃJ�E���^�̍ő哞�B�l���擾
	int getRefCountOnThread() const { return m_refCountOnThread; }//���݂̃X���b�h���̎Q�ƃJ�E���^�����擾
	int getThreadCount() const { return m_threadCount.load(); }//�Q�ƃX���b�h���擾
	int getThreadCountMax() const { return m_threadCountMax.load(); }//�Q�ƃX���b�h���̍ő哞�B�l���擾
	THREAD_ID getCreatedThreadID() const { return m_createdThreadId; }//�N���X(T)�C���X�^���X�𐶐������X���b�h�̃X���b�hID���擾
	const char* getCreatedThreadName() const { return m_createdThreadName; }//�N���X(T)�C���X�^���X�𐶐������X���b�h�̃X���b�h�����擾
public:
	//�I�y���[�^
	T* operator->(){ return m_this.load(); }//�A���[���Z�q�F�V���O���g���N���X���N���X(T)�̃C���X�^���X���U���i�㗝�j����
	const T* operator->() const { return m_this.load(); }//const �A���[���Z�q�F�i����j
private:
	//�I�y���[�^�i�֎~�j
	T& operator*(){ return *m_this.load(); }//�|�C���^���Z�q�i�֎~�j
	const T& operator*() const { return *m_this.load(); }//const�|�C���^���Z�q�i�֎~�j
	operator T*(){ return m_this.load(); }//�N���X T* �L���X�g���Z�q�i�֎~�j
	operator const T*() const { return m_this.load(); }//�N���Xconst T* �L���X�g���Z�q�i�֎~�j
	operator T&(){ return *m_this.load(); }//�N���X T& �L���X�g���Z�q�i�֎~�j
	operator const T&() const { return *m_this.load(); }//�N���X const T& �L���X�g���Z�q�i�֎~�j
	CSingletonCommon<T, U>& operator=(const CSingletonCommon<T, U>&){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonCommon<T, U>& operator=(const CSingletonCommon<T, U>*){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonCommon<T, U>& operator=(const T&){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonCommon<T, U>& operator=(const T*){ return *this; }//�R�s�[���Z�q�i�֎~�j
private:
	//�R�s�[�R���X�g���N�^�i�֎~�j
	explicit CSingletonCommon(CSingletonCommon<T, U>&){}
	explicit CSingletonCommon(CSingletonCommon<T, U>*){}
	explicit CSingletonCommon(T&){}
	explicit CSingletonCommon(T*){}
private:
	//�Q�ƃJ�E���^�̃J�E���g�A�b�v
	//���ŏ��̃J�E���g�A�b�v���ɃC���X�^���X�𐶐�
	//���Ȃ�ׂ����b�N�t���[�ɂ��邽�߂ɃJ�E���^�̔���͉��Z��̒l�݂̂�p���Ă���
	//�@...���A���ǃC���X�^���X�̐������m���ɑ҂�����K�v������̂ŁA���ǑS�̂����b�N����B
	//���u�������������FATTR_AUTO_CREATE�v�̎��́ACallOnce�ɂ�菉�����̏Փ˂�ی�
	//�@... ���A�����̗\��ɔ����ăX���b�h�Z�[�t����苭�������̂ŁACallOnce�͔p�~�B
	//�@�Q�l�p�� CallOnce ���g�p����ꍇ�̏������R�����g�Ƃ��Ďc���B
	//��C++11�d�l�̉ϒ��e���v���[�g���g�p���A�N���X T ���C���X�^���X������ۂɁA
	//�@�C�ӂ̃p�����[�^��^���邱�Ƃ��\�ɂ��Ă���B
	//�@C++11��Ή��̃R���p�C���ł́A�N���X T �Ƀf�t�H���g�R���X�g���N�^����
	//�@�g���Ȃ����̂Ƃ���B
	template<typename... Tx>
	bool addRef(Tx... nx)
	{
		//�C���X�^���X�����p�����_��
		//���ϒ��e���v���[�g�������g�p�����֐��̉��������A�����_���̊O���Q�ƂɎw�肵�Ă���
		auto creator = [&nx...](bool& is_created)
		{
			if (m_this.load() == nullptr)
			{
				//�N���X�� �z�u new �𗘗p���Astatic �̈�����蓖��
				//���ϒ��e���v���[�g�������g�p�����֐��̉��������󂯓n��
				m_this.store(new T(nx...));

				//�����������L�^
				{
					CThreadID thread_id;//���݂̃X���b�h���
					m_createdThreadId = thread_id.getID();//�X���b�hID�L�^
					m_createdThreadName = thread_id.getName();//�X���b�h���L�^
					is_created = true;//����OK
				}
			}
		};
		//�Q�ƃJ�E���^�J�E���g�A�b�v�i���ʏ����j
		return addRefCore(creator);
	}
	//�Q�ƃJ�E���^�̃J�E���g�A�b�v
	//���C���X�^���X�𐶐����Ȃ�
	bool addRefWitoutCreate()
	{
		//�C���X�^���X�����p�����_���i�_�~�[�j
		auto creator_dummy = [](bool& is_created)
		{
		};
		//�Q�ƃJ�E���^�J�E���g�A�b�v�i���ʏ����j
		return addRefCore(creator_dummy);
	}
	//�Q�ƃJ�E���^�̃J�E���g�A�b�v�i���ʏ������j
	//�����ۂ̃C���X�^���X�����������̓����_���Ŏ󂯎��
	//�������_�����󂯎�邽�߂Ƀe���v���[�g�֐������Ă���
	template<typename L>
	bool addRefCore(L& creator)
	{
		//�J�E���g�A�b�v�ςݔ���
		if (m_isCounted)
			return false;
		m_isCounted = true;
		
		//���b�N�擾
		m_instanceLock.lock();

		//�Q�ƃJ�E���^���J�E���g�A�b�v
		bool is_allow_create = false;//�C���X�^���X�������t���O
		{
			const int ref_count_prev = m_refCount.fetch_add(1);//�J�E���g�A�b�v
			const int ref_count_now = ref_count_prev + 1;
			if (ref_count_prev == 0)
				is_allow_create = true;//���߂ẴJ�E���g�A�b�v���ɃC���X�^���X����

			//�ő哞�B�l���L�^
			if (m_refCountMax.load() < ref_count_now)
				m_refCountMax.store(ref_count_now);
		}

		//�X���b�h���Q�Ɛ����J�E���g�A�b�v
		{
			const int ref_count_on_thread_prev = m_refCountOnThread++;
			if (ref_count_on_thread_prev == 0)
			{
				//���߂ẴJ�E���g�A�b�v���ɎQ�ƃX���b�h�����J�E���g�A�b�v
				const int thread_count_prev = m_threadCount.fetch_add(1);
				const int thread_count_now = thread_count_prev + 1;

				//�ő哞�B�l���L�^
				if (m_threadCountMax.load() < thread_count_now)
					m_threadCountMax.store(thread_count_now);
			}
		}

		//�C���X�^���X����
		bool is_created = false;//�����ς݃t���O
		if (is_allow_create)
		{
		//��CallOnce�p�~
		//	//�u�������������FATTR_AUTO_CREATE�v�̎��� CallOnce �Ő���
		//	if (THIS_SINGLETON_ATTR == CSingletonConst::ATTR_AUTO_CREATE)
		//	{
		//		std::call_once(m_once, creator, is_created);
		//	}
		//	//�u�������������FATTR_AUTO_CREATE�v�ȊO�̎��͕��ʂɐ���
		//	else
		//	{
		//		creator(is_created);
		//	}
			//��ɕ��ʂɃC���X�^���X����
			creator(is_created);
		}

		//���b�N���
		m_instanceLock.unlock();

		//�C���X�^���X�������s�������ǂ�����Ԃ�
		return is_created;
	}
	//�Q�ƃJ�E���^�̃J�E���g�_�E��
	//���Ō�̃J�E���g�_�E�����ɃC���X�^���X��j��
	//���Ȃ�ׂ����b�N�t���[�ɂ��邽�߂ɃJ�E���^�̔���͉��Z��̒l�݂̂�p���Ă���
	//�@...���A���ǃC���X�^���X�̐������m���ɑ҂�����K�v������̂ŁA���ǑS�̂����b�N����B
	bool release()
	{
		//�J�E���g�A�b�v�ςݔ���
		if (!m_isCounted)
			return false;
		m_isCounted = false;

		//���b�N�擾
		m_instanceLock.lock();

		//�Q�ƃJ�E���^���J�E���g�_�E��
		bool is_allow_delete = false;//�C���X�^���X�j�����t���O
		{
			const int ref_count_prev = m_refCount.fetch_sub(1);//�J�E���g�_�E��
			const int ref_count_now = ref_count_prev - 1;
			if (ref_count_now == 0)
				is_allow_delete = true;//�Ō�̃J�E���g�_�E�����ɃC���X�^���X�j��
		}
		
		//�X���b�h���Q�Ɛ����J�E���g�_�E��
		{
			const int ref_count_on_thread_now = --m_refCountOnThread;
			if (ref_count_on_thread_now == 0)
			{
				//�J�E���g 0 ���ɎQ�ƃX���b�h�����J�E���g�_�E��
				if (m_threadCount.load() > 0)
				{
					m_threadCount.fetch_sub(1);
				}
			}
		}

		//�C���X�^���X�j��
		bool is_deleted = false;//�j���ς݃t���O
		if (is_allow_delete)
		{
			//�u���������E�j�������FATTR_AUTO_CREATE_AND_DELETE�v�̎����������j��
			if (THIS_SINGLETON_ATTR == CSingletonConst::ATTR_AUTO_CREATE_AND_DELETE)
			{
				//�C���X�^���X�j���i���ʏ������p�j
				is_deleted = deleteThisCore();
			}
		}

		//���b�N���
		m_instanceLock.unlock();

		//�C���X�^���X�j�����s�������ǂ�����Ԃ�
		return is_deleted;
	}
	//�蓮�j��
	//���Q�ƃJ�E���^�͍X�V���Ȃ�
	bool deleteThis()
	{
		//�J�E���g�A�b�v�ςݏ�ԉ��
		m_isCounted = false;
		
		//���b�N�擾
		m_instanceLock.lock();

		//�C���X�^���X�j���i���ʏ������p�j
		const bool is_deleted = deleteThisCore();

		//���b�N���
		m_instanceLock.unlock();

		//�C���X�^���X�j�����s�������ǂ�����Ԃ�
		return is_deleted;
	}
	//�j���i���ʕ��j
	bool deleteThisCore()
	{
		//�C���X�^���X�j��
		bool is_deleted = false;//�j���ς݃t���O
		if (m_this.load() != nullptr)
		{
			//�C���X�^���X��j��
			delete m_this.load();
			m_this.store(nullptr);

			//�������������Z�b�g
			m_createdThreadId = INVALID_THREAD_ID;//�X���b�hID
			m_createdThreadName = nullptr;//�X���b�h��
			is_deleted = true;//�j��OK
		}

		//�C���X�^���X�j�����s�������ǂ�����Ԃ�
		return is_deleted;
	}
private:
	//�ʏ�V���O���g���p�R���X�g���N�^
	//���R���X�g���N�^�Ŏ����I�ɎQ�ƃJ�E���^���J�E���g�A�b�v���A�C���X�^���X�𐶐�����B
	//��C++11�d�l�̉ϒ��e���v���[�g���g�p���A�N���X T ���C���X�^���X������ۂɁA
	//�@�R���X�g���N�^�ɔC�ӂ̃p�����[�^��^���邱�Ƃ��\�ɂ��Ă���B
	//�@C++11��Ή��̃R���p�C���ł́A�N���X T �Ƀf�t�H���g�R���X�g���N�^����
	//�@�g���Ȃ����̂Ƃ���B
	template<typename... Tx>
	CSingletonCommon(CSingleton<T>*, Tx... nx) :
		m_isCounted(false)
	{
		//�y�A�T�[�V�����z�ʏ�V���O���g���ł́A�u�蓮���������FATTR_MANUAL_CREATE_AND_DELETE�v���g�p����ƃA�T�[�V�����ᔽ�i�������s�j
		ASSERT(THIS_SINGLETON_ATTR != CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE,
			"CSingleton<T> is not supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");

		//�y�A�T�[�V�����z�C���X�^���X�����ς݂̏ꍇ�A�X���b�h�Z�[�t����Ȃ��N���X�ɑ΂��āA�������ƈقȂ�X���b�h����A�N�Z�X����ƃA�T�[�V�����ᔽ�i�������s�j
		CThreadID this_thread;
		ASSERT(m_createdThreadId == INVALID_THREAD_ID ||
		       THIS_IS_THREAD_SAFE == CSingletonConst::IS_THREAD_SAFE ||
		       THIS_IS_THREAD_SAFE == CSingletonConst::IS_NOT_THREAD_SAFE && m_createdThreadId == this_thread.getID(),
			   "CSingleton<T> is not thread safe. Create thread and this thread are different.");

		//�Q�ƃJ�E���^���J�E���g�A�b�v
		//�����߂ẴJ�E���g�A�b�v�Ȃ�C���X�^���X�𐶐�����
		addRef(nx...);
	}
	//�Ǘ��V���O���g���p�R���X�g���N�^
	//���R���X�g���N�^�ŎQ�ƃJ�E���^���X�V�����A�C���X�^���X�𐶐����Ȃ��B
	CSingletonCommon(CManagedSingleton<T>*) :
		m_isCounted(false)
	{
		//�y�A�T�[�V�����z�Ǘ��V���O���g���ł́A�u�蓮���������FATTR_MANUAL_CREATE_AND_DELETE�v�ȊO���g�p����ƃA�T�[�V�����ᔽ�i�������s�j
		ASSERT(THIS_SINGLETON_ATTR == CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE,
			"CManagedSingleton<T> is only supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");
		
		//�y�A�T�[�V�����z�C���X�^���X�����ς݂̏ꍇ�A�X���b�h�Z�[�t����Ȃ��N���X�ɑ΂��āA�������ƈقȂ�X���b�h����A�N�Z�X����ƃA�T�[�V�����ᔽ�i�������s�j
		CThreadID this_thread;
		ASSERT(m_createdThreadId == INVALID_THREAD_ID ||
		       THIS_IS_THREAD_SAFE == CSingletonConst::IS_THREAD_SAFE ||
		       THIS_IS_THREAD_SAFE == CSingletonConst::IS_NOT_THREAD_SAFE && m_createdThreadId == this_thread.getID(),
			"CManagedSingleton<T> is not thread safe. Create thread and this thread are different.");
	}
	//�f�X�g���N�^
	//���f�X�g���N�^�Ŏ����I�ɎQ�ƃJ�E���^���J�E���g�_�E������B
	//���u�������������FATTR_AUTO_CREATE_AND_DELTE�v�̎��́A�Q�ƃJ�E���^�� 0 �Ŏ����j������B
	~CSingletonCommon()
	{
		//�Q�ƃJ�E���^���J�E���g�_�E��
		//���Ō�̃J�E���g�_�E���Ȃ�C���X�^���X��j������
		release();
	}
private:
	//�t�B�[���h
	bool m_isCounted;//�J�E���g�A�b�v�ς�
	//static std::once_flag m_once;//CallOnce�t���O ��CallOnce�p�~
	static CSpinLock m_instanceLock;//�����E�j���������b�N�t���O
	static std::atomic<T*> m_this;//�N���X T �̃C���X�^���X�i�|�C���^�j
	static char m_buff[sizeof(T)];//�N���X T �̃C���X�^���X�p�� static �̈�
	static std::atomic<int> m_refCount;//�Q�ƃJ�E���^
	static std::atomic<int> m_refCountMax;//�Q�ƃJ�E���^�̍ő哞�B�l
	static thread_local int m_refCountOnThread;//�yTLS�z���݂̃X���b�h���̎Q�ƃJ�E���^
	static std::atomic<int> m_threadCount;//�Q�ƃX���b�h��
	static std::atomic<int> m_threadCountMax;//�Q�ƃX���b�h���̍ő哞�B�l
	static THREAD_ID m_createdThreadId;//�C���X�^���X�������̃X���b�h�̃X���b�hID
	static const char* m_createdThreadName;//�C���X�^���X�������̃X���b�h�̃X���b�h��
};

//----------------------------------------
//friend �N���X�w��⏕�}�N��
//�����̃}�N���𒼐ڎg�p�����ASINGLETON_FRIEND �� MANAGED_SINGLETON_FRIEND ���g�p����
#define SINGLETON_COMMON_FRIEND(T, U) \
	friend class CSingletonCommon<T, U>;

//----------------------------------------
//�V���O���g���ݒ�⏕�}�N��
//�����̃}�N���𒼐ڎg�p�����ASINGLETON_ATTR �� MANAGED_SINGLETON_ATTR ���g�p����
#define SINGLETON_COMMON_ATTR(attr, is_thread_safe) \
	static const char* CLASS_NAME; \
	static const CSingletonConst::E_ATTR SINGLETON_ATTR = attr; \
	static const CSingletonConst::E_IS_THREAD_SAFE THIS_IS_THREAD_SAFE = is_thread_safe;

//----------------------------------------
//�V���O���g���N���X�� static �C���X�^���X�����p�}�N��
//�����̃}�N���𒼐ڎg�p�����AMAKE_SINGLETON_INSTANCE �� MAKE_MANAGED_SINGLETON_INSTANCE_ALL ���g�p����
#define MAKE_SINGLETON_COMMON_INSTANCE(T, U) \
	/*std::once_flag CSingletonCommon<T, U>::m_once;*//*CallOnce�t���O ��CallOnce�p�~*/ \
	CSpinLock CSingletonCommon<T, U>::m_instanceLock;/*�����E�j���������b�N�t���O*/ \
	std::atomic<T*> CSingletonCommon<T, U>::m_this(nullptr);/*�N���X T �̃C���X�^���X�i�|�C���^�j*/ \
	char CSingletonCommon<T, U>::m_buff[sizeof(T)];/*�N���X T �̃C���X�^���X�p�� static �̈�*/ \
	std::atomic<int> CSingletonCommon<T, U>::m_refCount(0);/*�Q�ƃJ�E���^*/ \
	std::atomic<int> CSingletonCommon<T, U>::m_refCountMax(0);/*�Q�ƃJ�E���^�̍ő哞�B�l*/ \
	thread_local int CSingletonCommon<T, U>::m_refCountOnThread = 0;/*�yTLS�z���݂̃X���b�h���̎Q�ƃJ�E���^*/ \
	std::atomic<int> CSingletonCommon<T, U>::m_threadCount(0);/*�Q�ƃX���b�h��*/ \
	std::atomic<int> CSingletonCommon<T, U>::m_threadCountMax(0);/*�Q�ƃX���b�h���̍ő哞�B�l*/ \
	THREAD_ID CSingletonCommon<T, U>::m_createdThreadId = INVALID_THREAD_ID;/*�C���X�^���X�������̃X���b�h�̃X���b�hID*/ \
	const char* CSingletonCommon<T, U>::m_createdThreadName = nullptr;/*�C���X�^���X�������̃X���b�h�̃X���b�h��*/ \
	const char* T::CLASS_NAME = #T;/*�N���X��*/

//----------------------------------------
//�ʏ�V���O���g���e���v���[�g�N���X
template<class T>
class CSingleton : public CSingletonCommon<T, CSingletonConst::AUTO_SINGLETON_TYPE>
{
public:
	//���\�b�h
	
	//�f�o�b�O���\��
	void printDebugInfo(FILE* fp = stdout)
	{
		CThreadID thread_id;
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		m_instanceLock.lock();//���b�N�擾
		DEBUG_FPRINT(fp, "Debug Info: [%s] on \"%s\"(0x%08x)\n", getClassName(), thread_id.getName(), thread_id.getID());
		DEBUG_FPRINT(fp, "  ClassAttribute       = %s\n", getAttr_Named());
		DEBUG_FPRINT(fp, "  ClassIsThreadSafe    = %s\n", isThreadSafe_Named());
		DEBUG_FPRINT(fp, "  ClassIsManaged       = %s\n", isManagedSingleton_Named());
		DEBUG_FPRINT(fp, "  ClassIsCreated       = %s\n", isCreated_Named());
		DEBUG_FPRINT(fp, "  RefCount             = %d (max=%d)\n", getRefCount(), getRefCountMax());
		DEBUG_FPRINT(fp, "  RefCountOnThisThread = %d\n", getRefCountOnThread());
		DEBUG_FPRINT(fp, "  ThreadCount          = %d (max=%d)\n", getThreadCount(), getThreadCountMax());
		DEBUG_FPRINT(fp, "  CreatedThread        = \"%s\"(0x%08x)\n", getCreatedThreadName(), getCreatedThreadID());
		m_instanceLock.unlock();//���b�N���
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		DEBUG_FFLUSH(fp);
	}
public:
	//�R���X�g���N�^
	//���R���X�g���N�^�Ŏ����I�ɎQ�ƃJ�E���^���J�E���g�A�b�v���A�C���X�^���X�𐶐�����B
	//��C++11�d�l�̉ϒ��e���v���[�g���g�p���A�N���X T ���C���X�^���X������ۂɁA
	//�@�R���X�g���N�^�ɔC�ӂ̃p�����[�^��^���邱�Ƃ��\�ɂ��Ă���B
	//�@C++11��Ή��̃R���p�C���ł́A�N���X T �Ƀf�t�H���g�R���X�g���N�^����
	//�@�g���Ȃ����̂Ƃ���B
	template<typename... Tx>
	CSingleton(Tx... nx) :
		CSingletonCommon<T, CSingletonConst::AUTO_SINGLETON_TYPE>::CSingletonCommon(this, nx...)
	{
	}
	//�f�X�g���N�^
	//���f�X�g���N�^�Ŏ����I�ɎQ�ƃJ�E���^���J�E���g�_�E������B
	//���u�������������FATTR_AUTO_CREATE_AND_DELTE�v�̎��́A�Q�ƃJ�E���^�� 0 �Ŏ����j������B
	~CSingleton()
	{
	}
};

//----------------------------------------
//�ʏ�V���O���g���N���X�p friend �N���X�w��⏕�}�N��
//���V���O���g���ΏۃN���X���ɋL�q����
//���V���O���g���ΏۃN���X���g�̃N���X����n��
#define SINGLETON_FRIEND(T) \
	SINGLETON_COMMON_FRIEND(T, CSingletonConst::AUTO_SINGLETON_TYPE);

//----------------------------------------
//�ʏ�V���O���g���N���X�p�V���O���g���ݒ�⏕�}�N��
//���V���O���g���ΏۃN���X���ɋL�q����iprivate�X�R�[�v�ł��悢�j
//���V���O���g�������ƃX���b�h�Z�[�t�錾��n��
#define SINGLETON_ATTR(attr, is_thread_safe) \
	SINGLETON_COMMON_ATTR(attr, is_thread_safe);

//�ʏ�V���O���g���N���X�p�V���O���g�������F���������̂݁{�X���b�h�Z�[�t�錾
#define SINGLETON_ATTR_AUTO_CREATE_WITH_THREAD_SAFE() \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_AUTO_CREATE, CSingletonConst::IS_THREAD_SAFE);

//�ʏ�V���O���g���N���X�p�V���O���g�������F���������̂݁{��X���b�h�Z�[�t�錾
#define SINGLETON_ATTR_AUTO_CREATE_WITHOUT_THREAD_SAFE() \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_AUTO_CREATE, CSingletonConst::IS_NOT_THREAD_SAFE);

//�ʏ�V���O���g���N���X�p�V���O���g�������F���������^�����폜�{�X���b�h�Z�[�t�錾
#define SINGLETON_ATTR_AUTO_CREATE_AND_DELETE_WITH_THREAD_SAFE() \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_AUTO_CREATE_AND_DELETE, CSingletonConst::IS_THREAD_SAFE);

//�ʏ�V���O���g���N���X�p�V���O���g�������F���������^�����폜�{��X���b�h�Z�[�t�錾
#define SINGLETON_ATTR_AUTO_CREATE_AND_DELETE_WITHOUT_THREAD_SAFE() \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_AUTO_CREATE_AND_DELETE, CSingletonConst::IS_NOT_THREAD_SAFE);

//----------------------------------------
//�ʏ�V���O���g���N���X�p static �C���X�^���X�����p�}�N��
//��.cpp �t�@�C�����ɋL�q����
//���V���O���g���ΏۃN���X�̃N���X����n��
#define MAKE_SINGLETON_INSTANCE(T) \
	MAKE_SINGLETON_COMMON_INSTANCE(T, CSingletonConst::AUTO_SINGLETON_TYPE)

//----------------------------------------
//�Ǘ��V���O���g���e���v���[�g�N���X
template<class T>
class CManagedSingleton : public CSingletonCommon<T, CSingletonConst::MANAGED_SINGLETON_TYPE>
{
	//�t�����h�N���X
	friend class CSingletonProxy<T>;
	friend class CSingletonInitializer<T>;
	friend class CSingletonUsing<T>;
public:
	//�V���O���g���ݒ���e���v���[�g�����̃N���X�Ɋ�Â��ĐÓI�Ɋm��
	//���N���X T �ɂ́A�萔 SINGLETON_USING_LIST_MAX ����`����Ă���K�v������
	static const std::size_t THIS_SINGLETON_USING_LIST_MAX = T::SINGLETON_USING_LIST_MAX;//�g�p���������X�g��
	
	//�y�ÓI�A�T�[�V�����zT::SINGLETON_USING_LIST_MAX �� 1 �ȏ�̎w�肪�K�v
	STATIC_ASSERT(THIS_SINGLETON_USING_LIST_MAX > 0, "class THIS_SINGLETON_USING_LIST_MAX is under 0.");
public:
	//�A�N�Z�b�T
	const char* getInitializerName() const { return m_initializerName.load(); }//�C���X�^���X�𐶐������C�j�V�����C�U�[���擾
	int getInitializerExists() const { return m_initializerExists.load(); }//�C�j�V�����C�U�[���擾
	CRWLock& getRWLock() { return m_lock; }//���[�h�E���C�g���b�N�擾
	const char* getDebugTrapName() const { return m_debugTrapName.load(); }//�f�o�b�O�p�g���b�v�Ώۏ������擾
	void setDebugTrapName(const char* name){ m_debugTrapName.store(const_cast<char*>(name)); }//�f�o�b�O�p�g���b�v�Ώۏ������X�V
	void resetDebugTrapName(){ m_debugTrapName.store(nullptr); }//�f�o�b�O�p�g���b�v�Ώۏ��������Z�b�g
	const char* getDebugTrapThreadName() const { return m_debugTrapThreadName.load(); }//�f�o�b�O�p�g���b�v�ΏۃX���b�h���擾
	void setDebugTrapThreadName(const char* name){ m_debugTrapThreadName.store(const_cast<char*>(name)); }//�f�o�b�O�p�g���b�v�ΏۃX���b�h���X�V
	void resetDebugTrapThreadName(){ m_debugTrapThreadName.store(nullptr); }//�f�o�b�O�p�g���b�v�ΏۃX���b�h�����Z�b�g
private:
	void setInitializerName(const char* name){ m_initializerName.store(const_cast<char*>(name)); }//�C���X�^���X�𐶐������C�j�V�����C�U�[���X�V
	void resetInitializerName(){ m_initializerName.store(nullptr); }//�C���X�^���X�𐶐������C�j�V�����C�U�[�����Z�b�g
	int addInitializerExists(){ return m_initializerExists.fetch_add(1); }//�C�j�V�����C�U�[�����J�E���g�A�b�v
	int subInitializerExists(){ return m_initializerExists.fetch_sub(1); }//�C�j�V�����C�U�[�����J�E���g�_�E��
public:
	//�I�y���[�^
	operator CRWLock& (){ return m_lock; }//���[�h�E���C�g���b�N�L���X�g�I�y���[�^
private:
	//���\�b�h

	//�g�p���������X�g�ɏ�������ǉ�
	//���������A�X���b�hID�A�X���b�h����n��
	void addUsingList(const char* name, const THREAD_ID thread_id, const char* thread_name, const CSingletonConst::E_IS_INITIALIZER is_initializer)
	{
		//�g���b�v�Ώۏ��������X���b�h���`�F�b�N
		//��������̈�v�̓|�C���^�Ŕ���i�����񃊃e�����������Ȃ�|�C���^����v����˃R���p�C���I�v�V�����ˑ��j
		const char* trap_name = m_debugTrapName.load();
		const char* trap_thread_name = m_debugTrapThreadName.load();
		if ((trap_name || trap_thread_name) &&
			(!trap_name || (name && name == trap_name)) &&
			(!trap_thread_name || (thread_name && thread_name == trap_thread_name)))
		{
			//���b�Z�[�W
			DEBUG_PRINT("Singleton catch the trap!! (\"%s\", Thread=\"%s\")\n", trap_name, trap_thread_name);
			
			//�u���[�N�|�C���g
			BREAK_POINT();
		}
		//�g�p�����쐬
		//��THIS_SINGLETON_USING_LIST_MAX �Ŏw�肳�ꂽ���܂œ����ɋL�^�\
		m_thisUsingInfo = m_usingListBuff.create<USING_INFO>(m_usingList.load(), name, thread_id, thread_name, is_initializer);
		if (m_thisUsingInfo)
		{
			//�y�Q�l�z���b�N�t���[�ȃX�^�b�N�v�b�V���i�擪�m�[�h�ǉ��j�A���S���Y��
			//m_thisUsingInfo->m_next = m_usingList.load();
			//while (!m_usingList.compare_exchange_weak(m_thisUsingInfo->m_next, m_thisUsingInfo)){}
			//���j�������������b�N�t���[�ɂł��Ȃ��̂ŁA���̃A���S���Y�����g�p���Ȃ�

			//�g�p����񃊃X�g�ǉ�
			m_usingListLock.lock();//���b�N�擾
			m_thisUsingInfo->m_next = m_usingList.load();
			m_usingList.store(m_thisUsingInfo);//�擪�m�[�h�ɑ}���i�A�����X�g�j
			m_usingListLock.unlock();//���b�N���
		}
	}
	//�g�p���������X�g���珈�����폜
	//��m_thisUsingInfo �����X�g���猟�����č폜
	void deleteUsingList()
	{
		if (m_thisUsingInfo)
		{
			//�y�Q�l�z���b�N�t���[�ȃX�^�b�N�|�b�v�i�擪�m�[�h���o���j�A���S���Y��
			//USING_INFO* old_head = m_usingList.load();
			//while (old_head && !m_usingList.compare_exchange_weak(old_head, old_head->next));
			//�����̗v���ɂ͓K�����Ȃ��̂ŁA���b�N���g�p����

			//�g�p����񃊃X�g�폜
			m_usingListLock.lock();//���b�N�擾
			USING_INFO* now = m_usingList.load();
			if (now && now == m_thisUsingInfo)
			{
				//�擪�m�[�h�̏ꍇ
				m_usingList.store(m_thisUsingInfo->m_next);
			}
			else
			{
				//�擪�ȍ~�̃m�[�h�̏ꍇ
				while (now && now->m_next != m_thisUsingInfo){ now = now->m_next; }
				if (now)
					now->m_next = m_thisUsingInfo->m_next;
			}
			m_usingListBuff.destroy(m_thisUsingInfo);//�폜
			m_usingListLock.unlock();//���b�N���
		}
	}
public:
	//�g�p���������X�g�\��
	void printUsingList(const char* name, FILE* fp = stdout)
	{
		CThreadID thread_id;
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		DEBUG_FPRINT(fp, "Using List: [%s] by \"%s\" on \"%s\"(0x%08x)\n", getClassName(), name, thread_id.getName(), thread_id.getID());
		m_usingListLock.lock();//���b�N�擾
		USING_INFO* info = m_usingList;
		while (info)
		{
			DEBUG_FPRINT(fp, " \"%s\" %s\ton \"%s\"(0x%08x)\n",
				info->m_name, 
				CSingletonConst::IsInitializer_ToStr(info->m_isInitializer ? CSingletonConst::IS_INITIALIZER : CSingletonConst::IS_USING),
				info->m_threadName,
				info->m_threadId
			);
			info = info->m_next;
		}
		DEBUG_FPRINT(fp, "(num=%d, max=%d)\n", m_usingListNum, m_usingListNumMax);
		m_usingListLock.unlock();//���b�N���
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		DEBUG_FFLUSH(fp);
	}
	//�f�o�b�O���\��
	void printDebugInfo(const char* name, FILE* fp = stdout)
	{
		CThreadID thread_id;
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		m_instanceLock.lock();//���b�N�擾
		DEBUG_FPRINT(fp, "Debug Info: [%s] by \"%s\" on \"%s\"(0x%08x)\n", getClassName(), name, thread_id.getName(), thread_id.getID());
		DEBUG_FPRINT(fp, "  ClassAttribute       = %s\n", getAttr_Named());
		DEBUG_FPRINT(fp, "  ClassIsThreadSafe    = %s\n", isThreadSafe_Named());
		DEBUG_FPRINT(fp, "  ClassIsManaged       = %s\n", isManagedSingleton_Named());
		DEBUG_FPRINT(fp, "  ClassIsCreated       = %s\n", isCreated_Named());
		DEBUG_FPRINT(fp, "  RefCount             = %d (max=%d)\n", getRefCount(), getRefCountMax());
		DEBUG_FPRINT(fp, "  RefCountOnThisThread = %d\n", getRefCountOnThread());
		DEBUG_FPRINT(fp, "  ThreadCount          = %d (max=%d)\n", getThreadCount(), getThreadCountMax());
		DEBUG_FPRINT(fp, "  CreatedThread        = \"%s\"(0x%08x)\n", getCreatedThreadName(), getCreatedThreadID());
		DEBUG_FPRINT(fp, "  InitializerName      = \"%s\"\n", getInitializerName());
		DEBUG_FPRINT(fp, "  InitializerExists    = %d\n", getInitializerExists());
		DEBUG_FPRINT(fp, "  DebugTrap            = \"%s\" on \"%s\"\n", getDebugTrapName(), getDebugTrapThreadName());
		m_instanceLock.unlock();//���b�N���
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		DEBUG_FFLUSH(fp);
	}
private:
	//�R���X�g���N�^
	//���R���X�g���N�^�ŎQ�ƃJ�E���^���X�V�����A�C���X�^���X�𐶐����Ȃ��B
	CManagedSingleton() :
		CSingletonCommon<T, CSingletonConst::MANAGED_SINGLETON_TYPE>::CSingletonCommon(this)
	{
	}
	//�f�X�g���N�^
	//���f�X�g���N�^�Ŏ����I�ɎQ�ƃJ�E���^���J�E���g�_�E������B
	~CManagedSingleton()
	{
	}
private:
	//�\���́F�g�p���������^
	struct USING_INFO
	{
		USING_INFO* m_next;//���̃m�[�h
		const char* m_name;//������
		const THREAD_ID m_threadId;//�����X���b�h�̃X���b�hID
		const char* m_threadName;//�����X���b�h�̃X���b�h��
		bool m_isInitializer;//�C�j�V�����C�U�[�t���O
		//�R���X�g���N�^
		USING_INFO(USING_INFO* next, const char* name, const THREAD_ID thread_id, const char* thread_name, const CSingletonConst::E_IS_INITIALIZER is_initializer) :
			m_next(next),
			m_name(name),
			m_threadId(thread_id),
			m_threadName(thread_name),
			m_isInitializer(is_initializer == CSingletonConst::IS_INITIALIZER)
		{
		}
		//�f�X�g���N�^
		~USING_INFO()
		{
		}
	};
private:
	//�t�B�[���h
	USING_INFO* m_thisUsingInfo;//���g�̎g�p���������
	static std::atomic<char*> m_initializerName;//�C���X�^���X�𐶐������C�j�V�����C�U�[��
	static std::atomic<int> m_initializerExists;//�C�j�V�����C�U�[���i���ʂ� 0 �� 1�j
	static CRWLock m_lock;//���[�h�E���C�g���b�N
	static std::atomic<char*> m_debugTrapName;//�f�o�b�O�p�g���b�v�Ώۏ�����
	static std::atomic<char*> m_debugTrapThreadName;//�f�o�b�O�p�g���b�v�ΏۃX���b�h��
	static std::atomic<int> m_usingListNum;//�g�p���������X�g�̎g�p��
	static std::atomic<int> m_usingListNumMax;//�g�p���������X�g�̎g�p���̍ő哞�B�l
	static std::atomic<USING_INFO*> m_usingList;//�g�p���������X�g
	static CSpinLock m_usingListLock;//�g�p���������X�g�̃��b�N�p�t���O
	static CBlockAllocator<THIS_SINGLETON_USING_LIST_MAX, sizeof(USING_INFO)> m_usingListBuff;//�g�p���������X�g�̗̈�
};

//----------------------------------------
//�Ǘ��V���O���g���N���X�p friend �N���X�w��⏕�}�N��
//���V���O���g���ΏۃN���X���ɋL�q����
//���V���O���g���ΏۃN���X���g�̃N���X����n��
#define MANAGED_SINGLETON_FRIEND(T) \
	SINGLETON_COMMON_FRIEND(T, CSingletonConst::MANAGED_SINGLETON_TYPE);

//----------------------------------------
//�Ǘ��V���O���g���N���X�p�V���O���g���ݒ�⏕�}�N��
//���V���O���g���ΏۃN���X���ɋL�q����iprivate�X�R�[�v�ł��悢�j
//���V���O���g�������ƃX���b�h�Z�[�t�錾��n��
#define MANAGED_SINGLETON_ATTR(is_thread_safe, using_list_num) \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE, is_thread_safe); \
	static const std::size_t SINGLETON_USING_LIST_MAX = using_list_num;

//�Ǘ��V���O���g���N���X�p�V���O���g�������F�蓮�����{�X���b�h�Z�[�t�錾
#define MANAGED_SINGLETON_ATTR_WITH_THREAD_SAFE(using_list_num) \
	MANAGED_SINGLETON_ATTR(CSingletonConst::IS_THREAD_SAFE, using_list_num);

//�Ǘ��V���O���g���N���X�p�V���O���g�������F�蓮�����{��X���b�h�Z�[�t�錾
#define MANAGED_SINGLETON_ATTR_WITHOUT_THREAD_SAFE(using_list_num) \
	MANAGED_SINGLETON_ATTR(CSingletonConst::IS_NOT_THREAD_SAFE, using_list_num);

//----------------------------------------
//�Ǘ��V���O���g���N���X�p static �C���X�^���X�����p�}�N��
//�����̃}�N���𒼐ڎg�p�����AMAKE_MANAGED_SINGLETON_INSTANCE_ALL ���g�p����
#define MAKE_MANAGED_SINGLETON_INSTANCE(T) \
	std::atomic<char*> CManagedSingleton<T>::m_initializerName(nullptr);/*�C���X�^���X�𐶐������C�j�V�����C�U�[��*/ \
	std::atomic<int> CManagedSingleton<T>::m_initializerExists(0);/*�C�j�V�����C�U�[��*/ \
	CRWLock CManagedSingleton<T>::m_lock;/*���[�h�E���C�g���b�N*/ \
	std::atomic<char*> CManagedSingleton<T>::m_debugTrapName(nullptr);/*�f�o�b�O�p�g���b�v�Ώۏ�����*/ \
	std::atomic<char*> CManagedSingleton<T>::m_debugTrapThreadName(nullptr);/*�f�o�b�O�p�g���b�v�ΏۃX���b�h��*/ \
	std::atomic<int> CManagedSingleton<T>::m_usingListNum(0);/*�g�p���������X�g�̎g�p��*/ \
	std::atomic<int> CManagedSingleton<T>::m_usingListNumMax(0);/*�g�p���������X�g�̎g�p���̍ő哞�B�l*/ \
	std::atomic< CManagedSingleton<T>::USING_INFO* > CManagedSingleton<T>::m_usingList(nullptr);/*�g�p���������X�g*/ \
	CSpinLock CManagedSingleton<T>::m_usingListLock;/*�g�p���������X�g�̃��b�N�p�t���O*/ \
	CBlockAllocator<CManagedSingleton<T>::THIS_SINGLETON_USING_LIST_MAX, sizeof(CManagedSingleton<T>::USING_INFO)> CManagedSingleton<T>::m_usingListBuff;/*�g�p���������X�g�̗̈�*/

//----------------------------------------
//�y�V���O���g���p�w���p�[�z�V���O���g���v���L�V�[�e���v���[�g�N���X�@���p����p
template<class T>
class CSingletonProxy
{
public:
	//�N���X�̑����A���샂�[�h���e���v���[�g�����Ɋ�Â��ĐÓI�Ɍ���
	//���N���X T �ɂ́A�萔 CLASS_NAME, SINGLETON_ATTR, IS_THREAD_SAFE ����`����Ă���K�v������B
	//���N���X U �ɂ́A�萔 THIS_IS_MANAGED_SINGLETON ����`����Ă���K�v������B
	static const CSingletonConst::E_ATTR THIS_SINGLETON_ATTR = T::SINGLETON_ATTR;//�V���O���g������
	static const CSingletonConst::E_IS_THREAD_SAFE THIS_IS_THREAD_SAFE = T::THIS_IS_THREAD_SAFE;//�X���b�h�Z�[�t�錾
public:
	//�A�N�Z�b�T
	const char* getName() const { return m_name; }//�������擾
	const CThreadID& getThreadID() const { return m_threadId; }//���݂̃X���b�hID�擾
	const char* getClassName() const { return m_singleton.getClassName(); }//���݂̃X���b�h���擾�@���Ϗ�
	CSingletonConst::E_ATTR getAttr() const { return m_singleton.getAttr(); }//�V���O���g�������擾�@���Ϗ�
	const char* getAttr_Named() const { return m_singleton.getAttr_Named(); }//�V���O���g���������擾�i�f�o�b�O�p�j�@���Ϗ�
	CSingletonConst::E_IS_THREAD_SAFE isThreadSafe() const { return m_singleton.isThreadSafe(); }//�X���b�h�Z�[�t�錾�擾�@���Ϗ�
	const char* isThreadSafe_Named() const { return m_singleton.isThreadSafe_Named(); }//�X���b�h�Z�[�t�錾���擾�i�f�o�b�O�p�j�@���Ϗ�
	CSingletonConst::E_IS_MANAGED_SINGLETON isManagedSingleton() const { return m_singleton.isManagedSingleton(); }//�Ǘ��V���O���g���錾�擾�@���Ϗ�
	const char* isManagedSingleton_Named() const { return m_singleton.isManagedSingleton_Named(); }//�Ǘ��V���O���g���錾���擾�i�f�o�b�O�p�j�@���Ϗ�
	CSingletonConst::E_IS_CREATED isCreated() const { return m_singleton.isCreated(); }//�N���X(T)�C���X�^���X�����ςݏ�Ԏ擾�@���Ϗ�
	const char* isCreated_Named() const { return m_singleton.isCreated_Named(); }//�N���X(T)�C���X�^���X�����ςݏ�Ԗ��擾�i�f�o�b�O�p�j�@���Ϗ�
private:
	CManagedSingleton<T>& getSinlgeton() { return m_singleton; }//�V���O���g���擾
	const CManagedSingleton<T>& getSinlgeton() const { return m_singleton; }//const�V���O���g���擾
	T* getThis() { return m_singleton.getThis(); }//�N���X(T)�C���X�^���X�̎Q�Ƃ��擾�i�֎~�j�@���Ϗ�
	const T* getThis() const { return m_singleton.getThis(); }//�N���X(T)�C���X�^���X��const�Q�Ƃ��擾�i�֎~�j�@���Ϗ�
public:
	int getRefCount() const { return m_singleton.getRefCount(); }//�Q�ƃJ�E���^�擾�@���Ϗ�
	int getRefCountMax() const { return m_singleton.getRefCountMax(); }//�Q�ƃJ�E���^�̍ő哞�B�l���擾�@���Ϗ�
	int getRefCountOnThread() const { return m_singleton.getRefCountOnThread(); }//���݂̃X���b�h���̎Q�ƃJ�E���^�����擾�@���Ϗ�
	int getThreadCount() const { return m_singleton.getThreadCount(); }//�Q�ƃX���b�h���擾�@���Ϗ�
	int getThreadCountMax() const { return m_singleton.getThreadCountMax(); }//�Q�ƃX���b�h���̍ő哞�B�l���擾�@���Ϗ�
	THREAD_ID getCreatedThreadID() const { return m_singleton.getCreatedThreadID(); }//�N���X(T)�C���X�^���X�𐶐������X���b�h�̃X���b�hID���擾�@���Ϗ�
	const char* getCreatedThreadName() const { return m_singleton.getCreatedThreadName(); }//�N���X(T)�C���X�^���X�𐶐������X���b�h�̃X���b�h�����擾�@���Ϗ�
	const char* getInitializerName() const { return m_singleton.getInitializerName(); }//�C���X�^���X�𐶐������C�j�V�����C�U�[���擾�@���Ϗ�
	int getInitializerExists() const { return m_singleton.getInitializerExists(); }//�C�j�V�����C�U�[���擾�@���Ϗ�
	CRWLock& getRWLock() { return m_singleton.getRWLock(); }//���[�h�E���C�g���b�N�擾�@���Ϗ�
	const char* getDebugTrapName() const { return m_singleton.getDebugTrapName(); }//�f�o�b�O�p�g���b�v�Ώۏ������擾�@���Ϗ�
	void setDebugTrapName(const char* name){ m_singleton.setDebugTrapName(name); }//�f�o�b�O�p�g���b�v�Ώۏ������X�V�@���Ϗ�
	void resetDebugTrapName(){ m_singleton.resetDebugTrapName(); }//�f�o�b�O�p�g���b�v�Ώۏ��������Z�b�g�@���Ϗ�
	const char* getDebugTrapThreadName() const { return m_singleton.getDebugTrapThreadName(); }//�f�o�b�O�p�g���b�v�ΏۃX���b�h���擾�@���Ϗ�
	void setDebugTrapThreadName(const char* name){ m_singleton.setDebugTrapThreadName(name); }//�f�o�b�O�p�g���b�v�ΏۃX���b�h���X�V�@���Ϗ�
	void resetDebugTrapThreadName(){ m_singleton.resetDebugTrapThreadName(); }//�f�o�b�O�p�g���b�v�ΏۃX���b�h�����Z�b�g�@���Ϗ�
public:
	//���\�b�h
	void printUsingList(FILE* fp = stdout){ m_singleton.printUsingList(m_name, fp); }//�g�p���������X�g�\���@���Ϗ�
	void printDebugInfo(FILE* fp = stdout){ m_singleton.printDebugInfo(m_name, fp); }//�f�o�b�O���\���@���Ϗ�
public:
	//�I�y���[�^
	T* operator->(){ return m_singleton; }//�A���[���Z�q�F�V���O���g���N���X���N���X(T)�̃C���X�^���X���U���i�㗝�j����@���Ϗ�
	const T* operator->() const { return m_singleton; }//const �A���[���Z�q�F�i����j�@���Ϗ�
	operator CRWLock& (){ return m_singleton; }//���[�h�E���C�g���b�N�L���X�g�I�y���[�^�@���Ϗ�
protected:
	//�I�y���[�^�i�֎~�j
	T& operator*(){ return *m_singleton; }//�|�C���^���Z�q�i�֎~�j�@���Ϗ�
	const T& operator*() const { return *m_singleton; }//const�|�C���^���Z�q�i�֎~�j�@���Ϗ�
	operator T*(){ return m_singleton; }//�N���X T* �L���X�g���Z�q�i�֎~�j�@���Ϗ�
	operator const T*() const { return m_singleton; }//�N���Xconst T* �L���X�g���Z�q�i�֎~�j�@���Ϗ�
	operator T&(){ return *m_singleton; }//�N���X T& �L���X�g���Z�q�i�֎~�j�@���Ϗ�
	operator const T&() const { return *m_singleton; }//�N���X const T& �L���X�g���Z�q�i�֎~�j�@���Ϗ�
	CSingletonProxy<T>& operator=(const CSingletonProxy<T>&){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonProxy<T>& operator=(const CSingletonProxy<T>*){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonProxy<T>& operator=(const T&){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonProxy<T>& operator=(const T*){ return *this; }//�R�s�[���Z�q�i�֎~�j
private:
	//�R�s�[�R���X�g���N�^�i�֎~�j
	explicit CSingletonProxy(CSingletonInitializer<T>&){}
	explicit CSingletonProxy(CSingletonInitializer<T>*){}
	explicit CSingletonProxy(T&){}
	explicit CSingletonProxy(T*){}
private:
	//�f�t�H���g�R���X�g���N�^�i�֎~�j
	CSingletonProxy(){}
protected:
	//�R���X�g���N�^
	CSingletonProxy(const char* name) :
		m_singleton(),
		m_name(name),
		m_threadId(),
		m_isAddRef(false)
	{}
	//�f�X�g���N�^
	~CSingletonProxy()
	{}
protected:
	//�t�B�[���h
	CManagedSingleton<T> m_singleton;//�Ǘ��V���O���g��
	const char* m_name;//������
	CThreadID m_threadId;//�X���b�hID
	bool m_isAddRef;//�Q�ƃJ�E���^�J�E���g�A�b�v�ς�
};

//----------------------------------------
//�V���O���g���v���L�V�[�N���X�p static �C���X�^���X�����p�}�N��
//�����̃}�N���𒼐ڎg�p�����AMAKE_MANAGED_SINGLETON_INSTANCE_ALL ���g�p����
#define MAKE_SINGLETON_PROXY_INSTANCE(T) \
	//

//----------------------------------------
//�y�V���O���g���p�w���p�[�z�V���O���g���C�j�V�����C�U�[�e���v���[�g�N���X
template<class T>
class CSingletonInitializer : public CSingletonProxy<T>
{
	//�y�ÓI�A�T�[�V�����zCSingletonInitializer<T>�́A�u�蓮���������FATTR_MANUAL_CREATE_AND_DELETE�v�ȊO���p�s��
	STATIC_ASSERT(THIS_SINGLETON_ATTR == CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE,
		"CSingletonInitializer<T> is only supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");
public:
	//�A�N�Z�b�T
	bool isExist() const { return CManagedSingleton<T>::isExistInitializer(); }//�C�j�V�����C�U�[�����݂��邩�H
private:
	void setInitializerName(const char* name) { return m_singleton.setInitializerName(name); }//�C�j�V�����C�U�[�����X�V�@���Ϗ�
	void resetInitializerName() { return m_singleton.resetInitializerName(); }//�C�j�V�����C�U�[�������Z�b�g�@���Ϗ�
private:
	//�I�y���[�^�i�֎~�j
	CSingletonInitializer<T>& operator=(const CSingletonInitializer<T>&){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonInitializer<T>& operator=(const CSingletonInitializer<T>*){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonInitializer<T>& operator=(const T&){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonInitializer<T>& operator=(const T*){ return *this; }//�R�s�[���Z�q�i�֎~�j
private:
	//�R�s�[�R���X�g���N�^�i�֎~�j
	explicit CSingletonInitializer(CSingletonInitializer<T>&){}
	explicit CSingletonInitializer(CSingletonInitializer<T>*){}
	explicit CSingletonInitializer(T&){}
	explicit CSingletonInitializer(T*){}
public:
	//���\�b�h

	//�������i�蓮�C���X�^���X�����j
	//��C++11�d�l�̉ϒ��e���v���[�g���g�p���A�N���X T ���C���X�^���X������ۂɁA
	//�@�C�ӂ̃p�����[�^��^���邱�Ƃ��\�ɂ��Ă���B
	//�@C++11��Ή��̃R���p�C���ł́A�N���X T �Ƀf�t�H���g�R���X�g���N�^����
	//�@�g���Ȃ����̂Ƃ���B
	template<typename... Tx>
	bool initialize(Tx... nx)
	{
		//�y�A�T�[�V�����z���ɃC���X�^���X�������ς݂Ȃ�A�T�[�V�����ᔽ�i�������s�j
		ASSERT(!isCreated(),
			"CSingletonInitializer<T> cannot create. Singleton instance is already exist.");
		
		//�����i�Q�ƃJ�E���^�J�E���g�A�b�v�j
		bool is_created = false;//�����������H
		if (!m_isAddRef)//�܂��Q�ƃJ�E���^�J���J�E���g�A�b�v���Ă��Ȃ����ɏ������s
		{
			m_isAddRef = true;//�Q�ƃJ�E���^�J�E���g�A�b�v���ON
			is_created = m_singleton.addRef(nx...);//�����i�Q�ƃJ�E���^�J�E���g�A�b�v�j
			//�������ꂽ���H
			if (is_created)
			{
				//�֘A�����Z�b�g
				setInitializerName(m_name);//�C���X�^���X�𐶐������C�j�V�����C�U�[��
				CRWLock& lock(getRWLock());
				lock.setIgnoreThreadID(getThreadID().getID());//���[�h�E���C�g���b�N�̑ΏۃX���b�hID���X�V
			}
		}
		//�C���X�^���X���������ꂽ���ǂ�����Ԃ�
		return is_created;
	}
	//�j���i�蓮�j���j
	bool finalize(CSingletonConst::E_IS_FORCED is_forced = CSingletonConst::IS_NORMAL){ return releaseCore(CSingletonConst::IS_FINALIZE, is_forced); }
	//�i�����I�ȁj�Q�ƃJ�E���^�����[�X�@���j�����Ȃ�
	bool release(){ return releaseCore(CSingletonConst::IS_RELEASE, CSingletonConst::IS_NORMAL); }
private:
	//�Q�ƃJ�E���^�����[�X�i���ʏ����j
	bool releaseCore(CSingletonConst::E_IS_FINALIZE is_finalize, CSingletonConst::E_IS_FORCED is_forced)
	{
		//�����[�X�ς݂Ȃ瑦�I��
		//���t�@�C�i���C�Y���̓����[�X�ς݂ł����s����
		if (!m_isAddRef && is_finalize != CSingletonConst::IS_FINALIZE)
			return false;

		//�y�A�T�[�V�����z���ɔj���ς݂Ȃ�A�T�[�V�����ᔽ�i�������s�j
		//���������s���̓A�T�[�V�����ᔽ�Ƃ��Ȃ�
		ASSERT(isCreated() == CSingletonConst::IS_CREATED ||
			   is_forced == CSingletonConst::IS_FORCED,
			"CSingletonInitializer<T> cannot delete. Singleton instance is already deleted.");

		//�y�A�T�[�V�����z�t�@�C�i���C�Y���ɂ܂����Q�Ƃ��c���Ă���Ȃ�A�T�[�V�����ᔽ�i�������s�j
		//�������������̓A�T�[�V�����ᔽ�Ƃ��Ȃ�
		const int LAST_COUNT = getRefCount() - (m_isAddRef ? 1 : 0);
		ASSERT(is_finalize == CSingletonConst::IS_FINALIZE && LAST_COUNT == 0 ||
			   is_finalize != CSingletonConst::IS_FINALIZE ||
			   is_forced == CSingletonConst::IS_FORCED,
			"CSingletonInitializer<T> will finalize, yet still using singleton.");

		//�Q�ƃJ�E���^�����[�X
		bool is_deleted = false;//�폜�ς݃t���O
		if (m_isAddRef || is_finalize == CSingletonConst::IS_FINALIZE)//�Q�ƃJ�E���^���J�E���g�A�b�v���Ă������A�����蓮�j���w�莞�ɏ������s
		{
			m_isAddRef = false;//�Q�ƃJ�E���^�J�E���g�A�b�v���OFF
			if (is_finalize == CSingletonConst::IS_FINALIZE)//�t�@�C�i���C�Y�i�蓮�j���j���H
				is_deleted = m_singleton.deleteThis();//�蓮�j��
			else
				is_deleted = m_singleton.release(); //�����[�X
			//�j�����ꂽ���H
			if (is_deleted)
			{
				//�֘A����j��
				resetInitializerName();//�C���X�^���X�𐶐������C�j�V�����C�U�[��
				resetDebugTrapName();//�f�o�b�O�p�g���b�v�Ώۏ�����
				resetDebugTrapThreadName();//�f�o�b�O�p�g���b�v�ΏۃX���b�h��
			}
		}
		//�C���X�^���X���j�����ꂽ���ǂ�����Ԃ�
		return is_deleted;
	}
public:
	//�R���X�g���N�^
	CSingletonInitializer(const char* name, const CSingletonConst::E_IS_FORCED is_forced = CSingletonConst::IS_NORMAL) :
		CSingletonProxy(name),
		m_isFirst(false)
	{
		//�C�j�V�����C�U�[���J�E���g�A�b�v
		const int exists_prev = m_singleton.addInitializerExists();

		//�g�p���������X�g�ǉ�
		m_singleton.addUsingList(m_name, m_threadId.getID(), m_threadId.getName(), CSingletonConst::IS_INITIALIZER);

		//�ŏ��̃C�j�V�����C�U�[������
		if (exists_prev == 0)
		{
			m_isFirst = true;//�ŏ��̃C�j�V�����C�U�[�C���X�^���X
		}

		//�y�A�T�[�V�����z���ɂ��C�j�V�����C�U�[������Ȃ�A�T�[�V�����ᔽ�i�������s�j
		//�������j���w�莞�̓A�T�[�V�����ᔽ�Ƃ��Ȃ�
		ASSERT(m_isFirst == true || is_forced == CSingletonConst::IS_FORCED,
			"CSingletonInitializer<T>: already exist!");
	}
	//�f�X�g���N�^
	~CSingletonInitializer()
	{
		//�C�j�V�����C�U�[���J�E���g�_�E��
		m_singleton.subInitializerExists();

		//�g�p���������X�g����j��
		m_singleton.deleteUsingList();

		//�Q�ƃJ�E���^�������[�X
		release();
	}
private:
	//�t�B�[���h
	bool m_isFirst;//�ŏ��̃C�j�V�����C�U�[�C���X�^���X���H
};

//----------------------------------------
//�V���O���g���C�j�V�����C�U�[�N���X�p static �C���X�^���X�����p�}�N��
//�����̃}�N���𒼐ڎg�p�����AMAKE_MANAGED_SINGLETON_INSTANCE_ALL ���g�p����
#define MAKE_SINGLETON_INITIALIZER_INSTANCE(T) \
	//

//----------------------------------------
//�y�V���O���g���p�w���p�[�z�V���O���g���A�N�Z�X�e���v���[�g�N���X
template<class T>
class CSingletonUsing : public CSingletonProxy<T>
{
	//�y�ÓI�A�T�[�V�����zCSingletonInitializer<T>�́A�u�蓮���������FATTR_MANUAL_CREATE_AND_DELETE�v�ȊO���p�s��
	STATIC_ASSERT(THIS_SINGLETON_ATTR == CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE,
		"CSingletonUsing<T> is only supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");
private:
	//�I�y���[�^�i�֎~�j
	CSingletonUsing<T>& operator=(const CSingletonUsing<T>&){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonUsing<T>& operator=(const CSingletonUsing<T>*){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonUsing<T>& operator=(const T&){ return *this; }//�R�s�[���Z�q�i�֎~�j
	CSingletonUsing<T>& operator=(const T*){ return *this; }//�R�s�[���Z�q�i�֎~�j
private:
	//�R�s�[�R���X�g���N�^�֎~
	explicit CSingletonUsing(CSingletonUsing<T>&){}
	explicit CSingletonUsing(CSingletonUsing<T>*){}
	explicit CSingletonUsing(T&){}
	explicit CSingletonUsing(T*){}
public:
	//�R���X�g���N�^
	CSingletonUsing(const char* name) :
		CSingletonProxy(name)
	{
	//���s�v
	//	//�y�A�T�[�V�����z�C�j�V�����C�U�[�����݂��Ă��Ȃ����̓A�T�[�V�����ᔽ
	//	ASSERT(m_singleton.getInitializerExists() > 0,
	//		"CSingletonUsing<T> cannot use. SingletonInitialize<T> not exist.");
	//	if (getInitializerExists() == 0)
	//	{
	//		return;
	//	}
		
		//�y�A�T�[�V�����z�C���X�^���X�����݂��Ă��Ȃ����̓A�T�[�V�����ᔽ
		ASSERT(m_singleton.isCreated() == CSingletonConst::IS_CREATED,
			"CSingletonUsing<T> cannot use. Singleton instance not exist.");
		if (isCreated() != CSingletonConst::IS_CREATED)
		{
			return;
		}
		
		//�Q�ƃJ�E���^�J�E���g�A�b�v���ON
		m_isAddRef = true;
		
		//�Q�ƃJ�E���^���J�E���g�A�b�v
		m_singleton.addRefWitoutCreate();
		
		//�g�p���������X�g�ǉ�
		m_singleton.addUsingList(m_name, m_threadId.getID(), m_threadId.getName(), CSingletonConst::IS_USING);
	}
	//�f�X�g���N�^
	~CSingletonUsing()
	{
		if (m_isAddRef)
		{
			//�Q�ƃJ�E���^�J�E���g�A�b�v���OFF
			m_isAddRef = false;
			
			//�Q�ƃJ�E���^���J�E���g�_�E��
			m_singleton.release();

			//�g�p���������X�g�j��
			m_singleton.deleteUsingList();
		}
	}
};

//----------------------------------------
//�V���O���g���A�N�Z�X�N���X�p static �C���X�^���X�����p�}�N��
//�����̃}�N���𒼐ڎg�p�����AMAKE_MANAGED_SINGLETON_INSTANCE_ALL ���g�p����
#define MAKE_SINGLETON_USING_INSTANCE(T) \
	//

//----------------------------------------
//�V���O���g���A�N�Z�X�w���p�[�N���X�p static �C���X�^���X�����p�}�N��
//��.cpp �t�@�C�����ɋL�q����
//���V���O���g���ΏۃN���X�̃N���X����n��
#define MAKE_MANAGED_SINGLETON_INSTANCE_ALL(T) \
	MAKE_SINGLETON_COMMON_INSTANCE(T, CSingletonConst::MANAGED_SINGLETON_TYPE); \
	MAKE_MANAGED_SINGLETON_INSTANCE(T); \
	MAKE_SINGLETON_INITIALIZER_INSTANCE(T); \
	MAKE_SINGLETON_USING_INSTANCE(T);

#if 1
//--------------------------------------------------------------------------------
//�e�X�g�����@

//----------------------------------------
//C++11���C�u����
#include <random>//����
#include <chrono>//����

//----------------------------------------
//���ʏ����N���X�@�F�ʏ�V���O���g���p
class CData1
{
	//�R���X�g���N�^�^�f�X�g���N�^�� private �ɂ��邽�߂� friend �錾
	SINGLETON_FRIEND(CData1);
public:
	//�萔
	//�V���O���g�������F���������̂݁{�X���b�h�Z�[�t�錾
	SINGLETON_ATTR_AUTO_CREATE_WITH_THREAD_SAFE();
	//�V���O���g�������F���������̂݁{��X���b�h�Z�[�t�錾
	//SINGLETON_ATTR_AUTO_CREATE_WITHOUT_THREAD_SAFE();
	//�V���O���g�������F���������^�����폜�{�X���b�h�Z�[�t�錾
	//SINGLETON_ATTR_AUTO_CREATE_AND_DELETE_WITH_THREAD_SAFE();
	//�V���O���g�������F���������^�����폜�{��X���b�h�Z�[�t�錾
	//SINGLETON_ATTR_AUTO_CREATE_AND_DELETE_WITHOUT_THREAD_SAFE();
public:
	//�A�N�Z�b�T
	int getData() const { m_data.load(); }
public:
	//���\�b�h
	//�J�E���g�A�b�v
	void addData()
	{
		int data_prev = m_data.fetch_add(1);
		printf("addCount() %d -> %d\n", data_prev, data_prev + 1);
		fflush(stdout);
	}
	//�J�E���g�_�E��
	void subData()
	{
		int data_prev = m_data.fetch_sub(1);
		printf("subCount() %d -> %d\n", data_prev, data_prev - 1);
		fflush(stdout);
	}
	//�v�����g
	void print(const char* name, const char* thread)
	{
		printf("print() Data=%2d [%s][%s] (FIRST:%s)\n", m_data, name, thread, m_firstThreadName);
		fflush(stdout);
	}
private:
	//�R���X�g���N�^
	//���V���O���g���ȊO�ł��̃N���X���g���Ȃ��悤�� private �ɂ���
	CData1(const char* thread_name):
		m_data(0),
		m_firstThreadName(thread_name)
	{
		printf("[CONSTRUCTOR] (FIRST:%s)\n", m_firstThreadName);
		fflush(stdout);
	}
	//�f�X�g���N�^
	~CData1()
	{
		printf("[DESTRUCTOR] (FIRST:%s)\n", m_firstThreadName);
		fflush(stdout);
	}
private:
	std::atomic<int> m_data;//�f�[�^
	const char* m_firstThreadName;//�ŏ��ɃA�N�Z�X�����X���b�h��
};
//�N���X����static�����o�[�̃C���X�^���X���`����K�v����
MAKE_SINGLETON_INSTANCE(CData1);//�ʏ�V���O���g���pstatic�C���X�^���X�����p�}�N��

//----------------------------------------
//�X���b�h�֐��@-A
void threadFunc1A(const char* thread_name)
{
	//�X���b�hID�ƃX���b�h�����Z�b�g
	CThreadID thread_id(thread_name);

	//�V���O���g��
	//��CData1 �̃R���X�g���N�^�������w��
	CSingleton<CData1> data(thread_id.getName());

	//����
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> sleep_time(60, 100);

	//�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(engine)));

	//�J�E���g�A�b�v
	//���A���[���Z�q��CData1�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->addData();

	//�v�����g
	//���A���[���Z�q��CData1�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->print("threadFunc1A", thread_id.getName());
}

//----------------------------------------
//�X���b�h�֐��@-B
void threadFunc1B(const char* thread_name)
{
	//�X���b�hID�ƃX���b�h�����Z�b�g
	CThreadID thread_id(thread_name);

	//�V���O���g��
	//��CData1 �̃R���X�g���N�^�������w��
	CSingleton<CData1> data(thread_id.getName());

	//�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	//����
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> sleep_time(60, 100);

	//�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(engine)));

	//�J�E���g�_�E��
	//���A���[���Z�q��CData1�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->subData();

	//�v�����g
	//���A���[���Z�q��CData1�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->print("threadFunc1B", thread_id.getName());
}

//----------------------------------------
//�e�X�g�@�F�ʏ�V���O���g���e�X�g
void test1()
{
	printf("----------------------------------------------------------------------\n");
	printf("�y�ʏ�V���O���g���e�X�g�z\n");

	//�y�R���p�C���G���[�z���ڃC���X�^���X����
	{
		//���ʂɃC���X�^���X����
		//CData1 data("illegal-data");//��NG:�R���p�C���G���[
		//CData1* data = new CData1("illegal-data");//��NG:�R���p�C���G���[
		//���V���O���g���ΏۃN���X�̓R���X�g���N�^�� private �錾����Ă���̂�
		//�@���ڃC���X�^���X�𐶐��ł��Ȃ�
	}

	//�X���b�h����
	std::thread th1 = std::thread(threadFunc1A, "THREAD-A");
	std::thread th2 = std::thread(threadFunc1B, "THREAD-B");
	std::thread th3 = std::thread(threadFunc1A, "THREAD-C");
	std::thread th4 = std::thread(threadFunc1B, "THREAD-D");
	std::thread th5 = std::thread(threadFunc1A, "THREAD-E");
	std::thread th6 = std::thread(threadFunc1B, "THREAD-F");

	//�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	//�r����Ԃ̃V���O���g���̏���\��
	{
		//�X���b�hID
		CThreadID thread_id;

		//�V���O���g��
		//��CData1 �̃R���X�g���N�^�������w��
		CSingleton<CData1> data(thread_id.getName());

		//�v�����g
		//���A���[���Z�q��CData1�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
		data->print("main", thread_id.getName());

		//�f�o�b�O���\��
		data.printDebugInfo();
	}

	//�X���b�h�I���҂�
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();

	//�I����Ԃ̃V���O���g���̏���\��
	{
		//�X���b�hID
		CThreadID thread_id;

		//�V���O���g��
		//��CData1 �̃R���X�g���N�^�������w��
		CSingleton<CData1> data(thread_id.getName());

		//�v�����g
		//���A���[���Z�q��CData1�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
		data->print("main", thread_id.getName());

		//�f�o�b�O���\��
		data.printDebugInfo();
	}
	
	printf("----------------------------------------------------------------------\n");
}

//--------------------------------------------------------------------------------
//�e�X�g�����A

//----------------------------------------
//C++11���C�u����
#include <random>//����
#include <chrono>//����

//----------------------------------------
//���ʏ����N���X�A�F�Ǘ��V���O���g���p
class CData2
{
	//�R���X�g���N�^�^�f�X�g���N�^�� private �ɂ��邽�߂� friend �錾
	MANAGED_SINGLETON_FRIEND(CData2);
public:
	//�萔
	//�V���O���g�������F�蓮�����{�X���b�h�Z�[�t�錾�{�g�p�����MAX=10��
	MANAGED_SINGLETON_ATTR_WITH_THREAD_SAFE(10);
	//�V���O���g�������F�蓮�����{��X���b�h�Z�[�t�錾�{�g�p�����MAX=10��
	//MANAGED_SINGLETON_ATTR_WITHOUT_THREAD_SAFE(10);
public:
	//�A�N�Z�b�T
	int getData() const { m_data.load(); }
public:
	//���\�b�h
	//�J�E���g�A�b�v
	void addData()
	{
		int data_prev = m_data.fetch_add(1);
		printf("addCount() %d -> %d\n", data_prev, data_prev + 1);
		fflush(stdout);
	}
	//�J�E���g�_�E��
	void subData()
	{
		int data_prev = m_data.fetch_sub(1);
		printf("subCount() %d -> %d\n", data_prev, data_prev - 1);
		fflush(stdout);
	}
	//�v�����g
	void print(const char* name, const char* thread)
	{
		printf("print() Data=%2d [%s][%s] (FIRST:%s)\n", m_data, name, thread, m_firstThreadName);
		fflush(stdout);
	}
private:
	//�R���X�g���N�^
	//���V���O���g���ȊO�ł��̃N���X���g���Ȃ��悤�� private �ɂ���
	CData2(const char* thread_name) :
		m_data(0),
		m_firstThreadName(thread_name)
	{
		printf("[CONSTRUCTOR] (FIRST:%s)\n", m_firstThreadName);
		fflush(stdout);
	}
	//�f�X�g���N�^
	~CData2()
	{
		printf("[DESTRUCTOR] (FIRST:%s)\n", m_firstThreadName);
		fflush(stdout);
	}
private:
	std::atomic<int> m_data;//�f�[�^
	const char* m_firstThreadName;//�ŏ��ɃA�N�Z�X�����X���b�h��
};
//�N���X����static�����o�[�̃C���X�^���X���`����K�v����
MAKE_MANAGED_SINGLETON_INSTANCE_ALL(CData2);//�Ǘ��V���O���g���pstatic�C���X�^���X�����p�}�N��

//----------------------------------------
//�X���b�h�֐��A-A
void threadFunc2A(const char* thread_name)
{
	//�X���b�hID�ƃX���b�h�����Z�b�g
	CThreadID thread_id(thread_name);

	//�V���O���g���A�N�Z�X
	//�����������w��
	CSingletonUsing<CData2> data("threadFunc2A");

	//����
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> sleep_time(60, 100);

	//�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(engine)));

	//�v�����g
	//���A���[���Z�q��CData2�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->print("threadFunc2A:BEFORE", thread_id.getName());

	//���[�h���b�N
	//���֐��I�����Ɏ����I�Ƀ��b�N���
	CRWLockR lock(data);
	//���Ǘ��V���O���g���̓��[�h�E���C�g���b�N����ێ����Ă���B
	//�@�܂��A�L���X�g�I�y���[�^�[�ɂ��A���̂܂܃��[�h�E���C�g���b�N�I�u�W�F�N�g�Ƃ��ĐU�镑�����Ƃ��ł���

	//�J�E���g�A�b�v
	//���A���[���Z�q��CData2�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->addData();

	//�v�����g
	//���A���[���Z�q��CData2�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->print("threadFunc2A:AFTER ", thread_id.getName());
}

//----------------------------------------
//�X���b�h�֐��A-B
void threadFunc2B(const char* thread_name)
{
	//�X���b�hID�ƃX���b�h�����Z�b�g
	CThreadID thread_id(thread_name);

	//�V���O���g���A�N�Z�X
	//�����������w��
	CSingletonUsing<CData2> data("threadFunc2B");

	//�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	//����
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> sleep_time(60, 100);

	//�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(engine)));

	//�v�����g
	//���A���[���Z�q��CData2�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->print("threadFunc2B:BEFORE", thread_id.getName());

	//���C�g���b�N
	//���֐��I�����Ɏ����I�Ƀ��b�N���
	CRWLockW lock(data);
	//���Ǘ��V���O���g���̓��[�h�E���C�g���b�N����ێ����Ă���B
	//�@�܂��A�L���X�g�I�y���[�^�[�ɂ��A���̂܂܃��[�h�E���C�g���b�N�I�u�W�F�N�g�Ƃ��ĐU�镑�����Ƃ��ł���

	//�J�E���g�_�E��
	//���A���[���Z�q��CData2�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->subData();

	//�v�����g
	//���A���[���Z�q��CData2�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
	data->print("threadFunc2B:AFTER ", thread_id.getName());
}

//----------------------------------------
//�e�X�g�A�������֐�
void initializeTest2()
{
	//�X���b�hID
	CThreadID thread_id;
	
	//�V���O���g���C�j�V�����C�U�[
	//�����������w��
	CSingletonInitializer<CData2> data_init("initializeTest2");
	
	//�C���X�^���X����
	//��CData2 �̃R���X�g���N�^�������w��
	data_init.initialize(thread_id.getName());
	
	//�f�o�b�O���\��
	data_init.printDebugInfo();
	data_init.printUsingList();
}

//----------------------------------------
//�e�X�g�A�I���֐�
void finalizeTest2()
{
	//�V���O���g���C�j�V�����C�U�[
	//�����������w��
	CSingletonInitializer<CData2> data_init("finalizeTest2");
	
	//�C���X�^���X�j��
	data_init.finalize();
	
	//�f�o�b�O���\��
	data_init.printDebugInfo();
	data_init.printUsingList();
}

//----------------------------------------
//�e�X�g�A�F�Ǘ��V���O���g���e�X�g
void test2()
{
	printf("----------------------------------------------------------------------\n");
	printf("�y�Ǘ��V���O���g���e�X�g�z\n");

	//�y�R���p�C���G���[�z���ڃC���X�^���X����
	{
		//���ʂɃC���X�^���X����
		//CData2 data("illegal-data");//��NG:�R���p�C���G���[
		//CData2* data = new CData2("illegal-data");//��NG:�R���p�C���G���[
		//���V���O���g���ΏۃN���X�̓R���X�g���N�^�� private �錾����Ă���̂�
		//�@���ڃC���X�^���X�𐶐��ł��Ȃ�
	}

	//�y�ÓI�A�T�[�V�����ᔽ�z�ʏ�V���O���g���Ƃ��� CData2 ���C���X�^���X��
	{
		//�ʏ�V���O���g��
		//��CData2 �̃R���X�g���N�^�������w��
		//CSingleton<CData2> data("illegal-initialize");//��NG:�ÓI�A�T�[�V�����ᔽ
		//��CData2�͊Ǘ��V���O���g���Ƃ��Đ錾����Ă��邽�߁A
		//�@�ʏ�V���O���g���Ƃ��Ďg�p���悤�Ƃ���ƃR���p�C�����ʂ�Ȃ�
		//�@�������A���S�ł͂�����̂́A�G���[�̏ꏊ�����Ȃ�킩��ɂ����̂ŁA
		//�@�ÓI�A�T�[�V��������߂Ď��s���A�T�[�V�����ɂ����ق����ǂ���������Ȃ�
	}

	//�y�A�T�[�V�����ᔽ�z�������O�ɃV���O���g���ɃA�N�Z�X
	{
		//�V���O���g���A�N�Z�X
		//�����������w��
		CSingletonUsing<CData2> data("illegal-access");
	}
	
	//�V���O���g��������
	initializeTest2();

	//�f�o�b�O�g���b�v
	//���w��̏������ƃX���b�h������v����V���O���g���A�N�Z�X���������ꍇ�A
	//�@�u���[�N�|�C���g����������
	//���ǂ��炩�Е��̎w�����
	{
		CSingletonUsing<CData2> data("test");
		data.setDebugTrapName("threadFunc2B");//�������Ńg���b�v
		data.setDebugTrapThreadName("THREAD-F");//�X���b�h���Ńg���b�v
	}

	//�X���b�h����
	std::thread th1 = std::thread(threadFunc2A, "THREAD-A");
	std::thread th2 = std::thread(threadFunc2B, "THREAD-B");
	std::thread th3 = std::thread(threadFunc2A, "THREAD-C");
	std::thread th4 = std::thread(threadFunc2B, "THREAD-D");
	std::thread th5 = std::thread(threadFunc2A, "THREAD-E");
	std::thread th6 = std::thread(threadFunc2B, "THREAD-F");

	//�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	//�r����Ԃ̃V���O���g���̏���\��
	{
		//�X���b�hID
		CThreadID thread_id;

		//�V���O���g���A�N�Z�X
		//�����������w��
		CSingletonUsing<CData2> data("main-1");

		//�v�����g
		//���A���[���Z�q��CData2�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
		data->print("main", thread_id.getName());

		//�f�o�b�O���\��
		data.printDebugInfo();
		data.printUsingList();
	}

	//�X���b�h�I���҂�
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();

	//�I����Ԃ̃V���O���g���̏���\��
	{
		//�X���b�hID
		CThreadID thread_id;

		//�V���O���g���A�N�Z�X
		//�����������w��
		CSingletonUsing<CData2> data("main-2");

		//�v�����g
		//���A���[���Z�q��CData2�̃����o�[�֐��ɕ��ʂɃA�N�Z�X
		data->print("main", thread_id.getName());

		//�f�o�b�O���\��
		data.printDebugInfo();
		data.printUsingList();
	}

	//�V���O���g���I��
	finalizeTest2();
	
	printf("----------------------------------------------------------------------\n");
}

//----------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//���C���X���b�hID�ƃX���b�h�����Z�b�g
	CThreadID main_thread_id("MainThread");
	
	//�e�X�g�@�F�ʏ�V���O���g��
	test1();

	//�e�X�g�A�F�Ǘ��V���O���g��
	test2();
	
	return EXIT_SUCCESS;
}

#endif
#if 0
//--------------------------------------------------------------------------------
//���e�X�g����

//���ʏ����N���X �����ɉ������p������K�v���A�ǂ����Ɏ��̂�錾����K�v���Ȃ�
class CTest
{
	//�R���X�g���N�^�^�f�X�g���N�^�� private �ɂ��邽�߂� friend �錾
	SINGLETON_FRIEND(CTest);
public:
	//�V���O���g�������F���������̂�
	SINGLETON_ATTR(CSingletonConst::ATTR_AUTO_CREATE, CSingletonConst::IS_THREAD_SAFE);
public:
	//����
	void printTest()
	{
		printf("test\n");
	}
private:
	//�R���X�g���N�^
	CTest()
	{
		printf("CTest::CTest()\n");
	}
	//�f�X�g���N�^
	~CTest()
	{
		printf("CTest::~CTest()\n");
	}
};
//�N���X����static�����o�[�̃C���X�^���X���`����K�v����
MAKE_SINGLETON_INSTANCE(CTest);//�V���O���g���pstatic�C���X�^���X�����p�}�N��

//----------------------------------------

//�����P
void func1()
{
	//�V���O���g���A�N�Z�X
	//������̃A�N�Z�X���ɃC���X�^���X����������A
	//�@�Ȍ�͂��̃C���X�^���X���g�p�����
	CSingleton<CTest> test;

	//����
	//���A���[���Z�q�ŕ��ʂ�CTest�N���X�̃����o�[�ɃA�N�Z�X����
	test->printTest();
}

//�����Q
void func2()
{
	//�V���O���g���A�N�Z�X
	CSingleton<CTest> test;

	func1();

	//����
	test->printTest();
}

//--------------------------------------------------------------------------------

//���C���X���b�h
CThreadID s_mainThread("MainThread");

//----------------------------------------

//�����\�[�X�}�l�[�W���N���X
class CResManager
{
	//�V���O���g���N���X�Ή�
	MANAGED_SINGLETON_FRIEND(CResManager);
public:
	MANAGED_SINGLETON_ATTR(CSingletonConst::IS_THREAD_SAFE, 20);

private:
	//�R���X�g���N�^�̓v���C�x�[�g������
	CResManager() :
		m_val(0)
	{
		printf("constructor!\n");
	}
	//�f�X�g���N�^
	~CResManager()
	{
		printf("desstructor!\n");
	}
public:
	int getVal() const { return m_val; }
	void setVal(const int val) { m_val = val; }
private:
	int m_val;
};
//�C���X�^���X���i.cpp�t�@�C���ɔz�u�j
MAKE_MANAGED_SINGLETON_INSTANCE_ALL(CResManager);

//----------------------------------------

//�T�u����A
void subA()
{
	printf("- subA:start -\n");
	CSingletonUsing<CResManager> res("subA");
	res->setVal(123);
	CRWLockR lock(res.getRWLock());
	res.resetDebugTrapName();
	res.resetDebugTrapThreadName();
	res.setDebugTrapName("subB");
	res.setDebugTrapThreadName("subB");
	printf("- subA:end -\n");
}

//�T�u����B
void subB(const char* name)
{
	printf("- subB(%s):start -\n", name);
	std::cout << "s_mainThread.isThisThread()=" << std::boolalpha << s_mainThread.isThisThread() << std::endl;
	CSingletonUsing<CResManager> res("subB");
	printf("getVal()=%d\n", res->getVal());
	extern void subC();
	subC();
	printf("getVal()=%d\n", res->getVal());
	res.printUsingList();
	printf("- subB(%s):end -\n", name);
}
void subB2(const char* name, const bool is_new_thread = false)
{
	if (is_new_thread)
		CThreadID this_thread("subB2");
	printf("- subB2(%s):start -\n", name);
	std::this_thread::sleep_for(std::chrono::microseconds(1));
	CSingletonUsing<CResManager> res("subB2");
	subB(name);
	printf("- subB2(%s):end -\n", name);
}

//�T�u����C
void subC()
{
	printf("- subC:start -\n");
	CSingletonUsing<CResManager> res("subC");
	res->setVal(456);
	CSingletonInitializer<CResManager> res2("subC");
	CSingletonUsing<CResManager> res3("subC2");
	//	CSingleton<CResManager> res4;
	res.printUsingList();
	printf("- subC:end -\n");
}

//----------------------------------------

//�e�X�g
int main(const int argc, const char* argv[])
{
	func1();
	func2();
	//	CSingletonInitializer<CResManager> x("initializer");
	//	x.createSingleton();
	{
		CSingletonUsing<CResManager> ng_res("main_prior");
		ng_res.printDebugInfo();
		//CSingletonInitializer<CResManager> res_init("initializer");
		CSingletonInitializer<CResManager> res_init("initializer", CSingletonConst::IS_FORCED);
		res_init.createSingleton();
		CSingletonUsing<CResManager> res("main");
		subA();
		std::thread t = std::thread(subB2, "thread", true);
		subB("main");
		res.printUsingList();
		res.printDebugInfo();
		t.join();
		{
			printf("getRefCount()=%d\n", res.getRefCount());
			printf("getRefCountMax()=%d\n", res.getRefCountMax());
			printf("getRefCountOnThread()=%d\n", res.getRefCountOnThread());
			printf("getThreadCount()=%d\n", res.getThreadCount());
			printf("getThreadCountMax()=%d\n", res.getThreadCountMax());
			printf("getCreatedThreadID()=%d\n", res.getCreatedThreadID());
			printf("getCreatedThreadName()=\"%s\"\n", res.getCreatedThreadName());
			printf("getDebugTrapName()=\"%s\"\n", res.getDebugTrapName());
			printf("getDebugTrapThreadName()=\"%s\"\n", res.getDebugTrapThreadName());
			printf("getAttr()=%d\n", res.getAttr());
			printf("isThreadSafe()=%d\n", res.isThreadSafe());
			printf("isManagedSingleton()=%d\n", res.isManagedSingleton());
			printf("isCreated()=%d\n", res.isCreated());
			printf("getClassName()=\"%s\"\n", res.getClassName());
			printf("getInitializeNname()=\"%s\"\n", res.getInitializerName());
		}
		{
			printf("getRefCount()=%d\n", res_init.getRefCount());
			printf("getRefCountMax()=%d\n", res_init.getRefCountMax());
			printf("getRefCountOnThread()=%d\n", res_init.getRefCountOnThread());
			printf("getThreadCount()=%d\n", res_init.getThreadCount());
			printf("getThreadCountMax()=%d\n", res_init.getThreadCountMax());
			printf("getCreatedThreadID()=%d\n", res_init.getCreatedThreadID());
			printf("getCreatedThreadName()=\"%s\"\n", res_init.getCreatedThreadName());
			printf("getDebugTrapName()=\"%s\"\n", res_init.getDebugTrapName());
			printf("getDebugTrapThreadName()=\"%s\"\n", res_init.getDebugTrapThreadName());
			printf("getAttr()=%d\n", res_init.getAttr());
			printf("isThreadSafe()=%d\n", res_init.isThreadSafe());
			printf("isManagedSingleton()=%d\n", res_init.isManagedSingleton());
			printf("isCreated()=%d\n", res_init.isCreated());
			printf("getClassName()=\"%s\"\n", res_init.getClassName());
			printf("getInitializeNname()=\"%s\"\n", res_init.getInitializerName());
		}
		res_init.releaseSingleton();
		res_init.deleteSingleton(CSingletonConst::IS_FORCED);
		res_init.printUsingList();
		res_init.printDebugInfo();
	}
	//	x.printUsingList();
	//	x.printDebugInfo();
	//	x.releaseSingleton();
	//	x.deleteSingleton();
	CSingletonInitializer<CResManager> x("initializer2");
	x.printUsingList();
	x.printDebugInfo();

	bool a = CThreadID() == CThreadID();

	return EXIT_SUCCESS;
}

#endif

// End of file
