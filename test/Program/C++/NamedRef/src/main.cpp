#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//C++11���C�u����
#include <thread>//�X���b�h
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
if (!(expr)) \
	{ \
	DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
	"  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
	"  "  msg "\n", __VA_ARGS__); \
	BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//�폜�p
//#include <assert.h>//assert�p
//#define ASSERT(expr, msg, ...) assert(expr)//VC++�W����

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
	void remove(T*& p)
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
		m_lock(),
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
//���O�t���f�[�^�Q�ƃN���X

#include <atomic>//�A�g�~�b�N�^

//�y�b��zC++11�̃n�b�V���e�[�u�����C�u����
//���ł���΁A�q�[�v���g�p���Ȃ��Ǝ��̎����ɕς����������肷��
#include <unordered_map>

//----------------------------------------
//���O�t���f�[�^�Q�ƃN���X
//���e���v���[�g�p�����[�^�ŋL�^�\�ȎQ�Ƃ̍ő吔���w��
template<std::size_t MAX>
class CNamedRefT
{
public:
	//�萔
	static const int MAX_NODES = MAX;//�L�^�\�ȎQ�Ƃ̍ő吔���w��
public:
	//�^
	typedef unsigned long long KeyPrim;//�L�[�^�i�n�b�V���e�[�u���p�̃v���~�e�B�u�^�j
	//�L�[�^
	struct Key
	{
		union
		{
			KeyPrim m_prim;//�v���~�e�B�u�^�L�[
			struct
			{
				unsigned int m_main;//��L�[
				unsigned int m_sub;//���L�[
			};
		};
		//�L���X�g�I�y���[�^
		operator KeyPrim() const { return m_prim; }
		//��r�I�y���[�^
		bool operator==(const Key& key) const { return m_prim == key.m_prim; }
		bool operator!=(const Key& key) const { return m_prim != key.m_prim; }
		bool operator>(const Key& key) const { return m_prim > key.m_prim; }
		bool operator<(const Key& key) const { return m_prim < key.m_prim; }
		bool operator>=(const Key& key) const { return m_prim >= key.m_prim; }
		bool operator<=(const Key& key) const { return m_prim <= key.m_prim; }
		//����I�y���[�^
		Key& operator=(const Key& key) const { return m_prim = key.m_prim; }
		//���\�b�h
		//CRC�l�Z�o�֐�
		unsigned int CRC32(const char* name)
		{
			//�_�~�[����
			return reinterpret_cast<unsigned long>(name);
		}
		//�R���X�g���N�^
		//��explicit�錾���Ȃ� �� Key�^�������Ɏ��֐��ɕ������n���Ă�OK
		Key(const Key& key) :
			m_prim(key.m_prim)
		{}
		Key(const KeyPrim key_prim) :
			m_prim(key_prim)
		{}
		Key(const unsigned int main_key, const unsigned int sub_key) :
			m_main(main_key),
			m_sub(sub_key)
		{}
		Key(const unsigned int key) :
			m_main(key),
			m_sub(0)
		{}
		Key(const char* name, const unsigned int sub_key):
			m_main(CRC32(name)),
			m_sub(sub_key)
		{}
		Key(const char* name) :
			m_main(CRC32(name)),
			m_sub(0)
		{}
		Key(const unsigned int main_key, const char* sub_key) :
			m_main(main_key),
			m_sub(CRC32(sub_key))
		{}
		//�f�X�g���N�^
		~Key()
		{}
	};
private:
	//--------------------
	//�ϐ��Q�ƌ^�F���ʕ�
	struct RefNodeCore
	{
		//���\�b�h
		virtual void* getRefByFunctor() const = 0;//�֐��I�u�W�F�N�g���g�p���ĕϐ��̎Q�Ƃ��擾
		virtual void getValByFunctor(void* val) const = 0;//�֐��I�u�W�F�N�g���g�p���ĕϐ��̒l���擾
		virtual void setValByFunctor(const void* val) = 0;//�֐��I�u�W�F�N�g���g�p���ĕϐ��̒l���X�V
		//�ϐ��̎Q�Ƃ��擾
		template<typename T>
		void* getRefCore() const
		{
			if (m_removed.load() == true)//�y�ی������z�폜�ς݃`�F�b�N
				return nullptr;
			ASSERT(typeid(T) == m_type, "This type is not match.");
			if (typeid(T) != m_type)
				return nullptr;
			if (m_ref.load() == nullptr)//�Q��ڈȍ~�̃A�N�Z�X�������ɂ��邽�߂ɁA�Q�Ƃ��L������
				m_ref.store(getRefByFunctor());
			return m_ref.load();
		}
		//�ϐ��̎Q�Ƃ��擾
		template<typename T>
		T* getRef(){ return static_cast<T*>(getRefCore<T>()); }
		//�ϐ��̎Q�Ƃ��擾
		template<typename T>
		const T* getRef() const { return static_cast<T*>(getRefCore<T>()); }
		//�ϐ��̒l���擾
		template<typename T>
		T getVal() const
		{
			if (m_removed.load() == true)//�y�ی������z�폜�ς݃`�F�b�N
				return static_cast<T>(0);
			if (m_hasAccessor)
			{
				//�A�N�Z�b�T������ꍇ
				ASSERT(typeid(T) == m_type, "This type is not match.");
				if (typeid(T) != m_type)
					return static_cast<T>(0);
				T val = static_cast<T>(0);
				getValByFunctor(reinterpret_cast<void*>(&val));
				return val;
			}
			//�A�N�Z�b�T���Ȃ��ꍇ
			void* p = getRefCore<T>();
			return p == nullptr ? static_cast<T>(0) : *static_cast<T*>(p);
		}
		//�ϐ��̒l���X�V
		template<typename T>
		void setVal(const T val)
		{
			if (m_removed.load() == true)//�y�ی������z�폜�ς݃`�F�b�N
				return;
			if (m_hasAccessor)
			{
				//�A�N�Z�b�T������ꍇ
				ASSERT(typeid(T) == m_type, "This type is not match.");
				if (typeid(T) != m_type)
					return;
				setValByFunctor(reinterpret_cast<const void*>(&val));
			}
			//�A�N�Z�b�T���Ȃ��ꍇ
			void* p = getRefCore<T>();
			if (p){ *static_cast<T*>(p) = val; }
		}
		//�L�����Ă���Q�Ƃ����Z�b�g
		//���������Ĕz�u��Q�Ɛ�̍폜����������Ăяo���K�v����
		//�����b�N�t���[����
		void resetRef(){ m_ref.store(nullptr); }
		//���[�h���b�N�擾
		void rLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const { CRWLockHelper(m_lock).rLock(spin_count); }
		//���C�g���b�N�擾
		void wLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const { CRWLockHelper(m_lock).wLock(spin_count); }
		//���[�h���b�N���
		void rUnlock() const { CRWLockHelper(m_lock).rUnlock(); }
		//���C�g���b�N���
		void wUnlock() const { CRWLockHelper(m_lock).wUnlock(); }
		//�R���X�g���N�^
		RefNodeCore(const Key& key, const type_info& type, const bool has_accessor) :
			m_key(key),
			m_type(type),
			m_hasAccessor(has_accessor),
			m_ref(nullptr),
			m_lock()
		{
			m_removed.store(false);
		}
		//�f�X�g���N�^
		virtual ~RefNodeCore()
		{
			m_removed.store(true);//�y�ی������z�폜�ς݂ɂ���
			m_ref.store(nullptr);//�y�O�̂��߁z�ϐ��̎Q�Ƃ��N���A
		}
		//�t�B�[���h
		const Key m_key;//�L�[
		const type_info& m_type;//�^���@���s���A�N�Z�X���o�p
		const bool m_hasAccessor;//�A�N�Z�b�T�^�C�v���H
		std::atomic<bool> m_removed;//�y�ی��p�z�폜�ς݃t���O
		mutable std::atomic<void*> m_ref;//�ϐ��̎Q��
		mutable CRWLock m_lock;//���[�h�E���C�g���b�N�I�u�W�F�N�g
	};
	//--------------------
	//�ϐ��Q�ƌ^�F�������F���ڎQ�ƃ^�C�v
	//�����ڎQ�ƃ^�C�v�́A��x�֐��I�u�W�F�N�g�ŕϐ��̎Q�Ƃ��擾�����炻���ێ����A
	//�@�֐��I�u�W�F�N�g�̍Ď��s���s��Ȃ����߁A�Q��ڈȍ~�̃A�N�Z�X�������B
	//�������I�Ɂu�Q�Ƃ����Z�b�g�v����ƁA����܂��֐��I�u�W�F�N�g�����s����B
	template <typename F>
	struct DirectRefNode : public RefNodeCore
	{
		//�^
		typedef typename F::TYPE TYPE;//�f�[�^�^
		typedef typename F NAMED_REF_FUNCTOR;//�ϐ��̎Q�Ǝ擾�p�֐��I�u�W�F�N�g�^
		//�y�I�[�o�[���C�h�z�֐��I�u�W�F�N�g���g�p���ĕϐ��̎Q�Ƃ��擾
		void* getRefByFunctor() const override
		{
			NAMED_REF_FUNCTOR functor;
			return functor(m_key);
		}
		//�y�I�[�o�[���C�h�z�y�����z�֐��I�u�W�F�N�g���g�p���ĕϐ��̒l���擾
		void getValByFunctor(void* val) const override {}
		//�y�I�[�o�[���C�h�z�y�����z�֐��I�u�W�F�N�g���g�p���ĕϐ��̒l���X�V
		void setValByFunctor(const void* val) override {}
		//�R���X�g���N�^
		DirectRefNode(const Key& key) :
			RefNodeCore(key, typeid(TYPE), false)
		{}
		//�f�X�g���N�^
		~DirectRefNode() override
		{}
	};
	//--------------------
	//�ϐ��Q�ƌ^�F�������F�A�N�Z�b�T�^�C�v
	//�����ڎQ�ƃ^�C�v�̕����A�Q�Ƃ��L���ł��镪�����B
	//���A�N�Z�b�T�^�C�v�́A����K���A�N�Z�b�T��ʂ��B
	template<typename F>
	struct AccessorNode : public RefNodeCore
	{
		//�^
		typedef typename F::TYPE TYPE;//�f�[�^�^
		typedef typename F::getter GETTER_FUNCTOIR;//�ϐ��̒l�擾�p�֐��I�u�W�F�N�g�^
		typedef typename F::setter SETTER_FUNCTOIR;//�ϐ��̒l�X�V�p�֐��I�u�W�F�N�g�^
		//�y�I�[�o�[���C�h�z�y�����z�֐��I�u�W�F�N�g���g�p���ĕϐ��̎Q�Ƃ��擾
		void* getRefByFunctor() const override{ return nullptr; }
		//�y�I�[�o�[���C�h�z�֐��I�u�W�F�N�g���g�p���ĕϐ��̒l���擾
		void getValByFunctor(void* val) const override
		{
			GETTER_FUNCTOIR functor;
			*static_cast<TYPE*>(val) = functor(m_key);
		}
		//�y�I�[�o�[���C�h�z�֐��I�u�W�F�N�g���g�p���ĕϐ��̒l���X�V
		void setValByFunctor(const void* val) override
		{
			SETTER_FUNCTOIR functor;
			functor(m_key, *static_cast<const TYPE*>(val));
		}
		//�R���X�g���N�^
		AccessorNode(const Key& key) :
			RefNodeCore(key, typeid(TYPE), true)
		{}
		//�f�X�g���N�^
		~AccessorNode() override
		{}
	};
public:
	//--------------------
	//�֐��I�u�W�F�N�g�p��{�^
	//���K���p�����Ďg�p����
	template<typename T>
	struct BaseRefF
	{
		typedef typename T TYPE;//�f�[�^�^��`
	};
private:
	//--------------------
	//�������T�C�Y�v�Z�p�̃_�~�[�֐��I�u�W�F�N�g
	struct getRefFunctorDummy : BaseRefF<int>{ TYPE* operator()(const Key& key) const { return nullptr; } };//�y�_�~�[�z�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�F���ڎQ�ƃ^�C�v
	struct accessorFunctorDummy : BaseRefF<int>{//�y�_�~�[�z�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�F�A�N�Z�b�T�^�C�v
		struct getter { TYPE operator()(const Key& key) const { return 0; } };
		struct setter { void operator()(const Key& key, const TYPE val) const {} };
	};
	using DirectRefNodeDummy = DirectRefNode<getRefFunctorDummy>;//�y�_�~�[�z�ϐ��Q�ƌ^�F���ڎQ�ƃ^�C�v
	using AccessorNodeDummy = AccessorNode<accessorFunctorDummy>;//�y�_�~�[�z�ϐ��Q�ƌ^�F�A�N�Z�b�T�^�C�v
public:
	//�萔
	#define MAX_SIZE(x, y) ((x) > (y) ? (x) : (y))
	static const std::size_t REF_NODE_SIZE_MAX = MAX_SIZE(sizeof(DirectRefNodeDummy), sizeof(AccessorNodeDummy));//�ϐ��Q�ƌ^�̍ő�T�C�Y
	#undef MAX_SIZE
private:
	//�^
	//--------------------
	//�n�b�V���e�[�u���^
	//�y�b��zC++11�W�����C�u�����̃n�b�V���e�[�u���^���g�p
	//���ł���΁A�q�[�v���g�p���Ȃ��Ǝ��̎����ɕς����������肷��
	using NamedRefTable = std::unordered_map<KeyPrim, RefNodeCore*>;
public:
	//�N���X���N���X��`
	//���\���̎Q�Ɨp
	
	//--------------------
	//�ϐ��ǂݍ��ݎQ�Ɨp�N���X�F�\���̎Q�Ɨp
	template<typename T>
	class RefR
	{
	public:
		//�I�y���[�^
		const T* operator->() const { return m_ref; }//�A���[���Z�q�i�{���̃f�[�^�^�̃v���L�V�[�j
		T operator*() const { return *m_ref; }//�|�C���^�^
	public:
		//���\�b�h
		bool isExist() const { return m_isExist; }//�Q�Ɛ悪���݂��邩�H
	public:
		//�R���X�g���N�^
		RefR(CNamedRefT<MAX>& map, const Key key, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_propRef(map.find(key, &m_isExist)),
			m_ref(nullptr)
		{
			//�ϐ��̎Q�Ƃ��擾
			if (m_propRef)
			{
				m_ref = m_propRef->getRef<T>();
				if (m_ref)
				{
					//�ϐ��̎Q�Ƃɐ��������烊�[�h���b�N�擾
					m_propRef->rLock(spin_count);
				}
			}
		}
		//�f�X�g���N�^
		~RefR()
		{
			if (m_propRef && m_ref)
			{
				//���[�h���b�N���
				m_propRef->rUnlock();
			}
		}
	private:
		//�t�B�[���h
		const RefNodeCore* m_propRef;//�ϐ��Q�ƌ^
		const T* m_ref;//�ϐ��Q��
		bool m_isExist;//�Q�Ɛ悪���݂��邩�H
	};
	//--------------------
	//�ϐ��������ݎQ�Ɨp�N���X�F�\���̎Q�Ɨp
	template<typename T>
	class RefW
	{
	public:
		//�I�y���[�^
		T* operator->(){ return m_ref; }//�A���[���Z�q�i�{���̃f�[�^�^�̃v���L�V�[�j
		const T* operator->() const { return m_ref; }//�A���[���Z�q�i�{���̃f�[�^�^�̃v���L�V�[�j
		T operator*() const { return *m_ref; }//�|�C���^�^
	public:
		//���\�b�h
		bool isExist() const { return m_isExist; }//�Q�Ɛ悪���݂��邩�H
	public:
		//�R���X�g���N�^
		RefW(CNamedRefT<MAX>& map, const Key key, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_propRef(map.find(key, &m_isExist)),
			m_ref(nullptr)
		{
			//�ϐ��̎Q�Ƃ��擾
			if (m_propRef)
			{
				m_ref = m_propRef->getRef<T>();
				if (m_ref)
				{
					//�ϐ��̎Q�Ƃɐ��������烉�C�g���b�N�擾
					m_propRef->wLock(spin_count);
				}
			}
		}
		//�f�X�g���N�^
		~RefW()
		{
			if (m_propRef && m_ref)
			{
				//���C�g���b�N���
				m_propRef->wUnlock();
			}
		}
	private:
		//�t�B�[���h
		RefNodeCore* m_propRef;//�ϐ��Q�ƌ^
		T* m_ref;//�ϐ��Q��
		bool m_isExist;//�Q�Ɛ悪���݂��邩�H
	};
	//�N���X���N���X��`�F�����܂�
	//--------------------
public:
	//���\�b�h
	//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�o�^�F���ڎQ�ƃ^�C�v
	template<typename F>
	bool regist(const Key key, F functor)
	{
		//�n�b�V���e�[�u���o�^�ς݃`�F�b�N
		if (m_namedRefList.find(key) != m_namedRefList.end())
			return false;
		//�m�[�h�̃������m��
		DirectRefNode<F>* ref = m_allocator.create< DirectRefNode<F> >(key);
		if (!ref)
			return false;
		//�n�b�V���e�[�u���ɒǉ��o�^
		m_namedRefList.insert(std::make_pair(key, ref));
		return true;
	}
	//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�o�^�F�A�N�Z�b�T�^�C�v
	template<typename F>
	bool registAcc(const Key key, F functor_set)
	{
		//�n�b�V���e�[�u���o�^�ς݃`�F�b�N
		if (m_namedRefList.find(key) != m_namedRefList.end())
			return false;
		//�m�[�h�̃������m��
		AccessorNode<F>* ref = m_allocator.create< AccessorNode<F> >(key);
		if (!ref)
			return false;
		//�n�b�V���e�[�u���ɒǉ��o�^
		m_namedRefList.insert(std::make_pair(key, ref));
		return true;
	}
	//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�o�^����
	//���X���b�h�Z�[�t�ł͂Ȃ��̂Ń^�C�~���O�Ɍ��d����
	//���O�̂��߃��b�N���擾���Ă͂�����̂́A������̃A�N�Z�X���u���b�N���Ă���󋵂��ƁA
	//�@�폜��ɏ���������̂Ō��ǖ����N����
	bool unregist(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		//�ϐ��Q�Ə��擾
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		//�o�^�����ƍ폜
		ref->wLock(spin_count);//���C�g���b�N�擾
		m_namedRefList.erase(key);//�n�b�V���e�[�u������o�^����
		ref->wUnlock();//���C�g���b�N���
		m_allocator.remove(ref);//���������
		return true;
	}
	//�S�Ă̕ϐ��Q�Ɨp�֐��I�u�W�F�N�g�o�^����
	//���X���b�h�Z�[�t�ł͂Ȃ��̂Ń^�C�~���O�Ɍ��d����
	//���O�̂��߃��b�N���擾���Ă͂�����̂́A������̃A�N�Z�X���u���b�N���Ă���󋵂��ƁA
	//�@�폜��ɏ���������̂Ō��ǖ����N����
	void unregistAll(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		//�S�m�[�h����
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;//�n�b�V���e�[�u���̏����Q��
			if (ref)
			{
				ref->wLock(spin_count);//���C�g���b�N�擾
				node.second = nullptr;//�n�b�V���e�[�u���������j��
				ref->wUnlock();//���C�g���b�N���
				m_allocator.remove(ref);//���������
			}
		}
		m_namedRefList.clear();//�n�b�V���e�[�u���̑S�m�[�h���N���A
	}
	//�ϐ��̎Q�Ƃ��N���A
	//�����b�N�t���[����
	void resetRef(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		//�ϐ��Q�Ə��擾
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return;
		//�ϐ��̎Q�Ƃ��N���A
		ref->resetRef();
	}
	//�ϐ��̎Q�Ƃ�S�ăN���A
	//�����b�N�t���[����
	void resetRefAll(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;
			if (ref)
			{
				//�ϐ��̎Q�Ƃ��N���A
				ref->resetRef();
			}
		}
	}
private:
	//�ϐ��Q�Ə��擾�F���ʕ�
	inline const RefNodeCore* findCore(const Key key, bool* is_exist) const
	{
		//�n�b�V���e�[�u������
		NamedRefTable::const_iterator node = m_namedRefList.find(key);
		if (node == m_namedRefList.end())
		{
			//������Ȃ������ꍇ
			if (is_exist)
				*is_exist = false;
			return nullptr;
		}
		const RefNodeCore* ref = node->second;
		if (!ref)
		{
			//������Ȃ������ꍇ
			if (is_exist)
				*is_exist = false;
			return nullptr;
		}
		//���������ꍇ
		if (is_exist)
			*is_exist = true;
		return ref;
	}
	//�ϐ��Q�Ə��擾�Fconst�p
	inline const RefNodeCore* find(const Key key, bool* is_exist) const
	{
		const RefNodeCore* ref = findCore(key, is_exist);
		return ref;
	}
	//�ϐ��Q�Ə��擾�F��const�p
	inline RefNodeCore* find(const Key key, bool* is_exist)
	{
		const RefNodeCore* ref = findCore(key, is_exist);
		return const_cast<RefNodeCore*>(ref);
	}
public:
	//----------
	//�l���擾�F�^�w��p
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����[�h���b�N�̃X�s���J�E���g�w���
	template<typename T>
	T get(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		const RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return static_cast<T>(0);
		ref->rLock(spin_count);
		T val = ref->getVal<T>();
		ref->rUnlock();
		return val;
	}
	//bool�^�p
	bool getBool(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return get<bool>(key, is_exist, spin_count);
	}
	//int�^�p
	int getInt(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return get<int>(key, is_exist, spin_count);
	}
	//float�^�p
	float getFloat(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return get<float>(key, is_exist, spin_count);
	}
	//const char*�^�p
	const char* getStr(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return get<const char*>(key, is_exist, spin_count);
	}
	//----------
	//�l���X�V�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool set(const Key key, const T val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T now_val = ref->getVal<T>();
		if (prev_val)
			*prev_val = now_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//bool�^�p
	bool setBool(const Key key, const bool val, bool* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return set<bool>(key, val, prev_val, is_exist, spin_count);
	}
	//int�^�p
	bool setInt(const Key key, const int val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return set<int>(key, val, prev_val, is_exist, spin_count);
	}
	//float�^�p
	bool setFloat(const Key key, const float val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return set<float>(key, val, prev_val, is_exist, spin_count);
	}
	//const char*�^�p
	bool setStr(const Key key, const char* str, const char** prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return set<const char*>(key, str, prev_val, is_exist, spin_count);
	}
	//----------
	//�l���C���N�������g�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool inc(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val += static_cast<T>(1);
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool incInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return inc<int>(key, prev_val, is_exist, spin_count);
	}
	//----------
	//�l���f�N�������g�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool dec(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val -= static_cast<T>(1);
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool decInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return dec<int>(key, prev_val, is_exist, spin_count);
	}
	//----------
	//�l�����Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool add(const Key key, const T add_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val += add_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool addInt(const Key key, const int add_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return add<int>(key, add_val, prev_val, is_exist, spin_count);
	}
	//float�^�p
	bool addFloat(const Key key, const float add_val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return add<float>(key, add_val, prev_val, is_exist, spin_count);
	}
	//----------
	//�l�����Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool sub(const Key key, const T sub_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val -= sub_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool subInt(const Key key, const int sub_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return sub<int>(key, sub_val, prev_val, is_exist, spin_count);
	}
	//float�^�p
	bool subFloat(const Key key, const float sub_val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return sub<float>(key, sub_val, prev_val, is_exist, spin_count);
	}
	//----------
	//�l����Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool mul(const Key key, const T mul_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val *= mul_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool mulInt(const Key key, const int mul_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return mul<int>(key, mul_val, prev_val, is_exist, spin_count);
	}
	//float�^�p
	bool mulFloat(const Key key, const float mul_val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return mul<float>(key, mul_val, prev_val, is_exist, spin_count);
	}
	//----------
	//�l�����Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool div(const Key key, const T div_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val /= div_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool divInt(const Key key, const int div_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return div<int>(key, div_val, prev_val, is_exist, spin_count);
	}
	//float�^�p
	bool divFloat(const Key key, const float div_val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return div<float>(key, div_val, prev_val, is_exist, spin_count);
	}
	//----------
	//�l����]�Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool mod(const Key key, const T mod_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val %= mod_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool modInt(const Key key, const int mod_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return mod<int>(key, mod_val, prev_val, is_exist, spin_count);
	}
	//----------
	//�l�𔽓]�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool reverse(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		ref->setVal<T>(~val);
		ref->wUnlock();
		return true;
	}
	//bool�^�p
	bool reverse(const Key key, bool* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		bool val = ref->getVal<bool>();
		if (prev_val)
			*prev_val = val;
		ref->setVal<bool>(val ? false : true );
		ref->wUnlock();
		return true;
	}
	//bool�^�p
	bool reverseBool(const Key key, bool* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return reverse(key, prev_val, is_exist, spin_count);
	}
	//int�^�p
	bool reverseInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return reverse<int>(key, prev_val, is_exist, spin_count);
	}
	//----------
	//�l��_���ρF�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool and(const Key key, const T and_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val &= and_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool andInt(const Key key, const int and_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return and<int>(key, and_val, prev_val, is_exist, spin_count);
	}
	//----------
	//�l��_���a�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool or(const Key key, const T or_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val |= or_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool orInt(const Key key, const int or_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return or<int>(key, or_val, prev_val, is_exist, spin_count);
	}
	//----------
	//�l��r���I�_���a�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	//�����C�g���b�N�̃X�s���J�E���g�w���
	template<typename T>
	bool xor(const Key key, const T xor_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val ^= xor_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool xorInt(const Key key, const int xor_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return xor<int>(key, xor_val, prev_val, is_exist, spin_count);
	}
	//----------
	//�Q�Ɛ悪���݂��邩�H
	bool isExist(const Key key) const
	{
		bool is_exist;
		find(key, &is_exist);
		return is_exist;
	}

public:
	//�R���X�g���N�^
	CNamedRefT()
	{
		//�n�b�V���e�[�u���̗v�f�����ő吔�ŗ\��
		m_namedRefList.reserve(MAX_NODES);
	}
	//�f�X�g���N�^
	~CNamedRefT()
	{
		//�n�b�V���e�[�u������S�m�[�h�폜
		unregistAll();
	}
private:
	//�t�B�[���h
	CBlockAllocator<MAX_NODES, REF_NODE_SIZE_MAX> m_allocator;//�Œ胁�����u���b�N�A���P�[�^�i�ő吔�ȏ�̊m�ۂ͕s�j
	NamedRefTable m_namedRefList;//�y�b��zC++11�W�����C�u�����̃n�b�V���e�[�u��
};

//----------------------------------------
//���O�t���f�[�^�Q�ƃN���X�V���O���g��
//���e���v���[�g�p�����[�^�ŋL�^�\�ȎQ�Ƃ̍ő吔���w��
//���C���X�^���X����ID���w�肷�邱�ƂŁA�����̃V���O���g�����쐬�\
template <std::size_t MAX, int ID = 0>
class CNamedRefSingletonT
{
public:
	//�^
	typedef CNamedRefT<MAX> NamedRef;//���O�t���f�[�^�Q�ƃN���X
public:
	//�萔
	static const int INSTANCE_ID = ID;//�C���X�^���X����ID
public:
	//�I�y���[�^
	operator NamedRef&() { return m_namedRef; }//�L���X�g�I�y���[�^
	const NamedRef* operator->() const { return &m_prosMap; }//�A���[���Z�q
	NamedRef* operator->(){ return &m_namedRef; }//�A���[���Z�q
private:
	//�t�B�[���h
	static NamedRef m_namedRef;//�ystatic�z���O�t���f�[�^�Q�ƃN���X�{��
};

//----------------------------------------
//�f�[�^�^�̃G�C���A�X
static const std::size_t NAMED_REF_MAX = 256;//���O�t���f�[�^�Q�ƃe�[�u���̍ő吔
using CNamedRefSingleton = CNamedRefSingletonT<NAMED_REF_MAX>;//���O�t���f�[�^�Q�ƃN���X�V���O���g��
using CNamedRef = CNamedRefSingleton::NamedRef;//���O�t���f�[�^�Q�ƃN���X
using RefK = CNamedRef::Key;//���O�t���f�[�^�Q�ƃL�[
template <typename T>
using CRefR = CNamedRef::RefR<T>;//���O�t���f�[�^�Q�ƁF�\���̎Q�ƃN���X�i�ǂݍ��ݗp�j
template <typename T>
using CRefW = CNamedRef::RefW<T>;//���O�t���f�[�^�Q�ƁF�\���̎Q�ƃN���X�i�������ݗp�j
template <typename T>
using RefF = CNamedRef::BaseRefF<T>;//�f�[�^�Q�Ɨp�֐��I�u�W�F�N�g�̊�{�^

//--------------------
//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�쐬�}�N���F���ڎQ�ƃ^�C�v
#define NAMED_REF_FUNCTOR(name, code, type) \
	struct name : RefF<type> \
	{ \
	TYPE* operator()(const RefK& key) const \
		{ \
			code; \
		} \
	};
//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�쐬�}�N���F���ڎQ�ƃ^�C�v�F�ȈՔ�
#define NAMED_REF_FUNCTOR_DIRECT(name, var, type) \
	NAMED_REF_FUNCTOR(name, return &var, type)
//--------------------
//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�쐬�}�N���F�A�N�Z�b�T�^�C�v
#define NAMED_ACCESSOR_FUNCTOR(name, getter_code, setter_code, type) \
	struct name : RefF<type> \
	{ \
		struct getter \
		{ \
			TYPE operator()(const RefK& key) const \
			{ \
				getter_code; \
			} \
		}; \
		struct setter \
		{ \
			void operator()(const RefK& key, const TYPE val) const \
			{ \
				setter_code; \
			} \
		}; \
	};
//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�쐬�}�N���F�A�N�Z�b�T�^�C�v�F�ȈՔ�
#define NAMED_ACCESSOR_FUNCTOR_SIMPLE(name, obj, getter_method, setter_method, type) \
	NAMED_ACCESSOR_FUNCTOR(name, return obj getter_method(), obj setter_method(val), type })

//----------------------------------------
//���O�t���f�[�^�Q�ƃN���X�V���O���g���C���X�^���X��
CNamedRef CNamedRefSingleton::m_namedRef;

//--------------------------------------------------------------------------------
//���O�t���f�[�^�Q�ƃN���X�e�X�g

//----------------------------------------
//�e�X�g�p�\���́F�_�~�[�V�[���I�u�W�F�N�g
struct CSceneObjDummy
{
	//public �t�B�[���h
	const int id;//ID
	const char* name;//���O
	int data1;//�f�[�^1
	float data2;//�f�[�^2
	//�A�N�Z�b�T
	int getData3() const { return data3; }//�f�[�^3�F�擾�A�N�Z�b�T
	void setData3(const int val) { data3 = val; }//�f�[�^3�F�X�V�A�N�Z�b�T
	//�R���X�g���N�^
	CSceneObjDummy(const int id_, const char* name_, const int data1_, const float data2_, const int data3_):
		id(id_),
		name(name_),
		data1(data1_),
		data2(data2_),
		data3(data3_)
	{}
private:
	//�t�B�[���h
	int data3;//�f�[�^3
};

//----------------------------------------
//�e�X�g�p�f�[�^��`
namespace TEST
{
	static bool s_debugCpuMeter = false;//�y�f�o�b�O�p�zCPU�g�p���\�����
	static int s_debugData1 = 1;//�y�f�o�b�O�p�z�f�[�^1
	static float s_debugData2 = 2.f;//�y�f�o�b�O�p�z�f�[�^2
	static const char* s_debugData3 = "DATA3";//�y�f�o�b�O�p�z�f�[�^3
	static short s_debugData4 = 4;//�y�f�o�b�O�p�z�f�[�^4
	static int s_debugData5 = 5;//�y�f�o�b�O�p�z�f�[�^5
	//�_�~�[�V�[���I�u�W�F�N�g
	static CSceneObjDummy s_sceneObjDummy[] =
	{
		{ 10, "���Y", 11, 111.1f, 1111 },
		{ 20, "���Y", 22, 222.2f, 2222 },
		{ 30, "�O�Y", 33, 333.3f, 3333 }
	};
	//�_�~�[�V�[���I�u�W�F�N�g�����֐�
	static CSceneObjDummy* searchSceneObj(const int id)
	{
		for (auto& o : s_sceneObjDummy)
		{
			if (o.id == id)
				return &o;
		}
		return nullptr;
	}
}

//----------------------------------------
//�⏕�֐�
const char* boolToStr(const bool val){ return val ? "true" : "false"; }//bool�l�𕶎���

//----------------------------------------
//�e�X�g�֐��@�F���O�t���f�[�^�Q�Ƃ�o�^
void testRegistNamedRef()
{
	//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g���`�F���ڎQ�ƃ^�C�v
	//�E�����@�F�\���̓��Ɂutypedef �f�[�^�^ TYPE;�v���`���邩�A�uRefF<�f�[�^�^>�v���p������B
	//�E�����A�F�uTYPE* operator()(const RefK& key) const { return �ϐ��̃|�C���^; }�v���`����B
	//�E�����B�F�����o�[�ϐ��������Ă͂����Ȃ�
	//struct refDebugCpuMeter : RefF<bool>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugCpuMeter; } };//�y�f�o�b�O�p�zCPU�g�p���\����ԎQ�Ɨp
	//struct refDebugParam1 : RefF<int>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugData1; } };//�y�f�o�b�O�p�z�f�[�^1�Q�Ɨp
	//struct refDebugParam2 : RefF<float>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugData2; } };//�y�f�o�b�O�p�z�f�[�^2�Q�Ɨp
	//struct refDebugParam3 : RefF<const char*>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugData3; } };//�y�f�o�b�O�p�z�f�[�^3�Q�Ɨp
	//struct refDebugParam4 : RefF<short>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugData4; } };//�y�f�o�b�O�p�z�f�[�^4�Q�Ɨp
	//struct refSceneObjDummy : RefF<CSceneObjDummy>{ TYPE *operator()(const RefK& key) const { return TEST::searchSceneObj(key.m_sub); } };//�_�~�[�V�[���I�u�W�F�N�g�Q�Ɨp
	//����L�̍\���̂Ɠ������Ƃ��uNAMED_REF_FUNCTOR�v�}�N���ő�p�ł���
	NAMED_REF_FUNCTOR_DIRECT(refDebugCpuMeter, TEST::s_debugCpuMeter, bool);//�y�f�o�b�O�p�zCPU�g�p���\����ԎQ�Ɨp
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam1, TEST::s_debugData1, int);//�y�f�o�b�O�p�z�f�[�^1�Q�Ɨp
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam2, TEST::s_debugData2, float);//�y�f�o�b�O�p�z�f�[�^2�Q�Ɨp
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam3, TEST::s_debugData3, const char*);//�y�f�o�b�O�p�z�f�[�^3�Q�Ɨp
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam4, TEST::s_debugData4, short);//�y�f�o�b�O�p�z�f�[�^4�Q�Ɨp
	NAMED_REF_FUNCTOR(refSceneObjDummy, return TEST::searchSceneObj(key.m_sub), CSceneObjDummy);//�_�~�[�V�[���I�u�W�F�N�g�Q�Ɨp

	//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g���`�F�A�N�Z�b�T�^�C�v
	//�E�����@�F�\���̓��Ɂutypedef �f�[�^�^ TYPE;�v���`���邩�A�uRefF<�f�[�^�^>�v���p������B
	//�E�����A�F�ustruct getter�v���`���A���̃����o�[�Ƃ��āuTYPE operator()(const RefK& key) const { return �ϐ��̒l; }�v���`����B
	//�E�����B�F�ustruct setter�v���`���A���̃����o�[�Ƃ��āuvoid operator()(const RefK& key, const TYPE val){ �ϐ� = val; }�v���`����B
	//�E�����C�F�����o�[�ϐ��������Ă͂����Ȃ�
	//struct refDebugParam5 : RefF<int>{//�y�f�o�b�O�p�z�f�[�^5�A�N�Z�X�p
	//	struct getter{ TYPE operator()(const RefK& key) const { return TEST::s_debugData5; } };
	//	struct setter{ void operator()(const RefK& key, const TYPE val) { TEST::s_debugData5 = val; } };
	//};
	//����L�̍\���̂Ɠ������Ƃ��uNAMED_ACCESSOR_FUNCTOR�v�}�N���ő�p�ł���
	NAMED_ACCESSOR_FUNCTOR(refDebugParam5, return TEST::s_debugData5, TEST::s_debugData5 = val, int);//�y�f�o�b�O�p�z�f�[�^5�A�N�Z�X�p
	//�����ʊ֐����쐬������ȂǁA���G�ȏ������K�v�Ȃ�}�N���͎g���Ȃ�
	struct refSceneObjData3 : RefF<int>{//�_�~�[�V�[���I�u�W�F�N�g��Data3�A�N�Z�X�p
		typedef CSceneObjDummy OBJ;
		static OBJ* search(const RefK& key){ return TEST::searchSceneObj(key.m_sub); }
		struct getter{ TYPE operator()(const RefK& key) const { const OBJ* obj = search(key);  return obj ? obj->getData3() : 0; } };
		struct setter{ void operator()(const RefK& key, const TYPE val) { OBJ* obj = search(key); obj->setData3(val); } };
	};

	//���O�t���f�[�^�Q�ƃN���X�V���O���g��
	CNamedRefSingleton named_ref;

	//�ϐ��Q�Ƃ�o�^�F���ڎQ�ƃ^�C�v
	named_ref->regist(RefK("DebugCpuMeter"), refDebugCpuMeter()); //�y�f�o�b�O�p�zCPU�g�p���\�����
	named_ref->regist(RefK("DebugParam1"), refDebugParam1());//�y�f�o�b�O�p�z�f�[�^1
	named_ref->regist(RefK("DebugParam2"), refDebugParam2());//�y�f�o�b�O�p�z�f�[�^2
	named_ref->regist(RefK("DebugParam3"), refDebugParam3());//�y�f�o�b�O�p�z�f�[�^3
	named_ref->regist(RefK("DebugParam4"), refDebugParam4());//�y�f�o�b�O�p�z�f�[�^4
	named_ref->regist(RefK("SceneObj", 10), refSceneObjDummy());//�_�~�[�V�[���I�u�W�F�N�g�FID=10
	named_ref->regist(RefK("SceneObj", 20), refSceneObjDummy());//�_�~�[�V�[���I�u�W�F�N�g�FID=20
	named_ref->regist(RefK("SceneObj", 30), refSceneObjDummy());//�_�~�[�V�[���I�u�W�F�N�g�FID=30
	//�ϐ��Q�Ƃ�o�^�F�A�N�Z�b�T�^�C�v
	named_ref->registAcc(RefK("DebugParam5"), refDebugParam5());//�y�f�o�b�O�p�z�f�[�^5
	named_ref->registAcc(RefK("SceneObj::Data3", 10), refSceneObjData3());//�_�~�[�V�[���I�u�W�F�N�g�FData3�FID=10
	named_ref->registAcc(RefK("SceneObj::Data3", 20), refSceneObjData3());//�_�~�[�V�[���I�u�W�F�N�g�FData3�FID=20
	named_ref->registAcc(RefK("SceneObj::Data3", 30), refSceneObjData3());//�_�~�[�V�[���I�u�W�F�N�g�FData3�FID=30
}

//----------------------------------------
//�e�X�g�֐��A�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^��\��
void testPrintNamedRef()
{
	CNamedRefSingleton named_ref;
	printf("DebugCpuMeter=%s\n", boolToStr(named_ref->getBool(RefK("DebugCpuMeter"))));
	printf("DebugParam1=%d\n", named_ref->getInt(RefK("DebugParam1")));
	printf("DebugParam2=%.3f\n", named_ref->getFloat(RefK("DebugParam2")));
	printf("DebugParam3=\"%s\"\n", named_ref->getStr(RefK("DebugParam3")));
	printf("DebugParam4=%d\n", named_ref->get<short>(RefK("DebugParam4")));
	printf("DebugParam5=%d\n", named_ref->getInt(RefK("DebugParam5")));
	for (int id : {10, 20, 30})
	{
		CRefR<CSceneObjDummy> obj(named_ref, RefK("SceneObj", id));
		if (obj.isExist())
			printf("SceneObj[id=%d]: {name\"%s\", data1=%d, data2=%.3f, data3=%d}\n",
				obj->id, obj->name, obj->data1, obj->data2, named_ref->getInt(RefK("SceneObj::Data3", id)));
	}
}

//----------------------------------------
//�e�X�g�֐��B�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^���X�V
void testUpdateNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->setBool(RefK("DebugCpuMeter"), true);
	named_ref->setInt(RefK("DebugParam1"), 123);
	named_ref->setFloat(RefK("DebugParam2"), 456.789f);
	named_ref->setStr(RefK("DebugParam3"), "New String");
	named_ref->set<short>(RefK("DebugParam4"), 12345);
	named_ref->setInt(RefK("DebugParam5"), 67890);
	{
		int id = 20;
		CRefW<CSceneObjDummy> obj(named_ref, RefK("SceneObj", id));
		if (obj.isExist())
		{
			obj->data1 = 321;
			obj->data2 = 987.654f;
		}
		named_ref->setInt(RefK("SceneObj::Data3", id), 987654);
	}
}

//----------------------------------------
//�e�X�g�֐��C�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�P
void testCalcNamedRef1()
{
	CNamedRefSingleton named_ref;
	named_ref->reverseBool(RefK("DebugCpuMeter"));
	named_ref->incInt(RefK("DebugParam1"));
	named_ref->addFloat(RefK("DebugParam2"), 100.f);
	named_ref->mul<short>(RefK("DebugParam4"), 2);
	named_ref->reverseInt(RefK("DebugParam5"));
	{
		int id = 20;
		named_ref->xorInt(RefK("SceneObj::Data3", id), 0xffff);
	}
}

//----------------------------------------
//�e�X�g�֐��D�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�Q
void testCalcNamedRef2()
{
	CNamedRefSingleton named_ref;
	named_ref->reverseBool(RefK("DebugCpuMeter"));
	named_ref->decInt(RefK("DebugParam1"));
	named_ref->subFloat(RefK("DebugParam2"), 100.f);
	named_ref->div<short>(RefK("DebugParam4"), 2);
	named_ref->reverseInt(RefK("DebugParam5"));
	{
		int id = 20;
		named_ref->xorInt(RefK("SceneObj::Data3", id), 0xffff);
	}
}

//----------------------------------------
//�e�X�g�֐��E�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�R
void testCalcNamedRef3()
{
	CNamedRefSingleton named_ref;
	named_ref->setInt(RefK("DebugParam1"), 0x33);
	named_ref->setInt(RefK("DebugParam5"), 0xf0);
	named_ref->andInt(RefK("DebugParam1"), 0x7);
	named_ref->orInt(RefK("DebugParam5"), 0xf);
}

//----------------------------------------
//�e�X�g�֐��F�F���O�t���f�[�^�Q�Ƃ������ŕێ�����Q�Ƃ����Z�b�g
//�������ڂɉ��̉e���͂Ȃ����A����Ȃ�炩�̏������ɎQ�Ƃ��Ď擾����B
//���f�[�^����������o�^���폜���ꂽ�肷��킯�ł͂Ȃ��B
//��2��ڈȍ~�̃A�N�Z�X�����������邽�߂ɓ����ŕێ����Ă���Q�Ɓi�|�C���^�j���N���A���邾���B
//���������Ĕz�u��A�f�[�^�̍폜���s��ꂽ�ꍇ�Ɏ��s����K�v������B
//���T���v���ł͑S�̃��Z�b�g�����A�ʂ̃��Z�b�g���\�B
//���A�N�Z�b�T�^�C�v�ɂ͉��̉e�����Ȃ��B
void testResetRefAll()
{
	CNamedRefSingleton named_ref;
	named_ref->resetRefAll();
}

//----------------------------------------
//�e�X�g�֐��G�F�ꕔ�̖��O�t���f�[�^�Q�Ƃ�o�^����
void testUnregistNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->unregist(RefK("DebugParam1"));
	named_ref->unregist(RefK("DebugParam3"));
	named_ref->unregist(RefK("DebugParam5"));
	named_ref->unregist(RefK("SceneObj", 20));
	named_ref->unregist(RefK("SceneObj::Data3", 20));
}

//----------------------------------------
//�e�X�g�֐��H�F�S�Ă̖��O�t���f�[�^�Q�Ƃ�o�^����
void testUnregistRefAll()
{
	CNamedRefSingleton named_ref;
	named_ref->unregistAll();
}

//----------------------------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	printf("sizeof(CNamedRef)=%d\n", sizeof(CNamedRef));
	printf("sizeof(CNamedRefSingleton)=%d\n", sizeof(CNamedRefSingleton));
	
	//�e�X�g�@�F���O�t���f�[�^�Q�Ƃ�o�^
	printf("----- regist -----\n");
	testRegistNamedRef();
	//�e�X�g�A�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^��\��
	testPrintNamedRef();
	
	//�e�X�g�B�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^���X�V
	printf("----- set value -----\n");
	testUpdateNamedRef();
	testPrintNamedRef();
	
	//�e�X�g�C�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�P
	printf("----- reset-ref all -----\n");
	testResetRefAll();
	testPrintNamedRef();
	
	//�e�X�g�D�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�Q
	printf("----- calc value (1) -----\n");
	testCalcNamedRef1();
	testPrintNamedRef();
	
	//�e�X�g�E�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�R
	printf("----- calc value (2) -----\n");
	testCalcNamedRef2();
	testPrintNamedRef();
	
	//�e�X�g�֐��F�F���O�t���f�[�^�Q�Ƃ������ŕێ�����Q�Ƃ����Z�b�g
	printf("----- calc value (3) -----\n");
	testCalcNamedRef3();
	testPrintNamedRef();
	
	//�e�X�g�֐��G�F�ꕔ�̖��O�t���f�[�^�Q�Ƃ�o�^����
	printf("----- unregist -----\n");
	testUnregistNamedRef();
	testPrintNamedRef();
	
	//�e�X�g�֐��H�F�S�Ă̖��O�t���f�[�^�Q�Ƃ�o�^����
	printf("----- unregist all -----\n");
	testUnregistRefAll();
	testPrintNamedRef();
	
	return EXIT_SUCCESS;
}

// End of file
