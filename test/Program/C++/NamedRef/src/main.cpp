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

//�y�b��zC++11�̃n�b�V���e�[�u�����C�u����
#include <unordered_map>

template<std::size_t MAX>
class CNamedRefT
{
public:
	static const int MAX_MAP = MAX;
public:
	typedef unsigned long long KeyPrim;
	struct Key
	{
		union
		{
			KeyPrim m_prim;
			struct
			{
				unsigned int m_main;
				unsigned int m_sub;
			};
		};
		operator KeyPrim() const { return m_prim; }
		unsigned int CRC32(const char* name)
		{
			return reinterpret_cast<unsigned long>(name);//�_�~�[
		}
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
	};
private:
	struct RefNodeCore
	{
		virtual void* getRefFromFunctor() const = 0;
		template<typename T>
		void* getRefCore() const
		{
			ASSERT(typeid(T) == m_type, "This type is not match.");
			if (typeid(T) != m_type)
				return nullptr;
			if (!m_ref)
				m_ref = getRefFromFunctor();
			return m_ref;
		}
		template<typename T>
		T* getRef(){ return static_cast<T*>(getRefCore<T>()); }
		template<typename T>
		const T* getRef() const { return static_cast<T*>(getRefCore<T>()); }
		template<typename T>
		T getVal() const { void* p = getRefCore<T>(); return p == nullptr ? static_cast<T>(0) : *static_cast<T*>(p); }
		template<typename T>
		void setVal(const T value){ void* p = getRefCore<T>(); if (p){ *static_cast<T*>(p) = value; } }
		void resetRef(){ m_ref = nullptr; }
		void rLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const { CRWLockHelper(m_lock).rLock(spin_count); }
		void wLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const { CRWLockHelper(m_lock).wLock(spin_count); }
		void rUnlock() const { CRWLockHelper(m_lock).rUnlock(); }
		void wUnlock() const { CRWLockHelper(m_lock).wUnlock(); }
		RefNodeCore(const Key& key, const type_info& type) :
			m_key(key),
			m_type(type),
			m_ref(nullptr),
			m_lock()
		{}
		virtual ~RefNodeCore()
		{}
		const Key m_key;
		const type_info& m_type;
		mutable void* m_ref;
		mutable CRWLock m_lock;
	};
	template <typename F>
	struct RefNode : public RefNodeCore
	{
		F m_getRefFunctor;
		void* getRefFromFunctor() const override
		{
			return m_getRefFunctor(m_key);
		}
		RefNode(const Key& key) :
			RefNodeCore(key, typeid(F::TYPE))
		{}
		~RefNode() override
		{
		}
	};
	struct getRefFunctorDummy{ typedef int TYPE; TYPE* operator()(const Key& key) const { return nullptr; } };
	using NamedRefTable = std::unordered_map<KeyPrim, RefNodeCore*>;
	using RefNodeDummy = RefNode<getRefFunctorDummy>;
public:
	template<typename T>
	class RefR
	{
	public:
		const T* operator->() const { return m_ref; }
		T operator*() const { return *m_ref; }
		bool isExist() const { return m_isExist; }
	public:
		RefR(CNamedRefT<MAX>& map, const Key key, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_propRef(map.get(key, &m_isExist)),
			m_ref(nullptr)
		{
			if (m_propRef)
			{
				m_ref = m_propRef->getRef<T>();
				if (m_ref)
					m_propRef->rLock(spin_count);
			}
		}
		~RefR()
		{
			if (m_propRef && m_ref)
				m_propRef->rUnlock();
		}
	private:
		const RefNodeCore* m_propRef;
		const T* m_ref;
		bool m_isExist;
	};
	template<typename T>
	class RefW
	{
	public:
		T* operator->(){ return m_ref; }
		const T* operator->() const { return m_ref; }
		T operator*() const { return *m_ref; }
		bool isExist() const { return m_isExist; }
	public:
		RefW(CNamedRefT<MAX>& map, const Key key, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_propRef(map.get(key, &m_isExist)),
			m_ref(nullptr)
		{
			if (m_propRef)
			{
				m_ref = m_propRef->getRef<T>();
				if (m_ref)
					m_propRef->wLock(spin_count);
			}
		}
		~RefW()
		{
			if (m_propRef && m_ref)
				m_propRef->wUnlock();
		}
	private:
		RefNodeCore* m_propRef;
		T* m_ref;
		bool m_isExist;
	};
public:
	template<typename F>
	bool regist(const Key key, F functor)
	{
		RefNode<F>* ref = m_allocator.create< RefNode<F> >(key);
		if (!ref)
			return false;
		m_namedRefList.insert(std::make_pair(key, ref));
		return true;
	}
	bool unregist(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = get(key, is_exist);
		if (!ref)
			return false;
		{
			ref->wLock(spin_count);
			m_namedRefList.erase(name);
			ref->wUnlock();
		}
		m_allocator.remove(ref);
		return true;
	}
	void unregistAll(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;
			{
				ref->wLock(spin_count);
				node.second = nullptr;
				ref->wUnlock();
			}
			m_allocator.remove(ref);
		}
		m_namedRefList.clear();
	}
	void resetRef(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = get(key, is_exist);
		if (!ref)
			return;
		{
			ref->wLock(spin_count);
			ref->resetRef();
			ref->wUnlock();
		}
	}
	void resetRefAll(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;
			{
				ref->wLock(spin_count);
				ref->resetRef();
				ref->wUnlock();
			}
		}
	}
private:
	inline const RefNodeCore* getCore(const Key key, bool* is_exist) const
	{
		NamedRefTable::const_iterator node = m_namedRefList.find(key);
		if (node == m_namedRefList.end())
		{
			if (is_exist)
				*is_exist = true;
			return nullptr;
		}
		if (is_exist)
			*is_exist = false;
		return node->second;
	}
	inline const RefNodeCore* get(const Key key, bool* is_exist) const
	{
		const RefNodeCore* ref = getCore(key, is_exist);
		return ref;
	}
	inline RefNodeCore* get(const Key key, bool* is_exist)
	{
		const RefNodeCore* ref = getCore(key, is_exist);
		return const_cast<RefNodeCore*>(ref);
	}
public:
	template<typename T>
	T getVal(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		const RefNodeCore* ref = get(key, is_exist);
		if (!ref)
			return static_cast<T>(0);
		ref->rLock(spin_count);
		T val = ref->getVal<T>();
		ref->rUnlock();
		return val;
	}
	bool getBool(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return getVal<bool>(key, is_exist, spin_count);
	}
	int getInt(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return getVal<int>(key, is_exist, spin_count);
	}
	float getFloat(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return getVal<float>(key, is_exist, spin_count);
	}
	const char* getStr(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return getVal<const char*>(key, is_exist, spin_count);
	}
	template<typename T>
	bool setVal(const Key key, const T value, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = get(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		ref->setVal<T>(value);
		ref->wUnlock();
		return true;
	}
	bool setBool(const Key key, const bool value, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return setVal<bool>(key, value, is_exist, spin_count);
	}
	bool setInt(const Key key, const int value, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return setVal<int>(key, value, is_exist, spin_count);
	}
	bool setFloat(const Key key, const float value, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return setVal<float>(key, value, is_exist, spin_count);
	}
	bool setStr(const Key key, const char* str, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return setVal<const char*>(key, str, is_exist, spin_count);
	}
	bool isExist(const Key key) const
	{
		bool is_exist;
		const RefNodeCore* ref = get(key, &is_exist);
		return is_exist;
	}

public:
	CNamedRefT()
	{
		m_namedRefList.reserve(MAX_MAP);
	}
	~CNamedRefT()
	{
		unregistAll();
	}
private:
	CBlockAllocator<MAX_MAP, sizeof(RefNodeDummy)> m_allocator;
	NamedRefTable m_namedRefList;
};
template <std::size_t MAX, int ID = 0>
class CNamedRefSingletonT
{
public:
	static const int INSTANCE_ID = ID;
	typedef CNamedRefT<MAX> NamedRef;
public:
	operator NamedRef&() { return m_namedRef; }
	const NamedRef* operator->() const { return &m_prosMap; }
	NamedRef* operator->(){ return &m_namedRef; }
private:
	static NamedRef m_namedRef;
};

using CNamedRefSingleton = CNamedRefSingletonT<100>;
using CNamedRef = CNamedRefSingleton::NamedRef;
using RefKey = CNamedRef::Key;
template <typename T>
using CRefR = CNamedRef::RefR<T>;
template <typename T>
using CRefW = CNamedRef::RefW<T>;

//�C���X�^���X��
CNamedRef CNamedRefSingleton::m_namedRef;

struct CSceneObjDummy
{
	int id;
	const char* name;
	int data1;
	float data2;
};
static bool s_debugCpuMeter = false;
static int s_debugParam1 = 1;
static float s_debugParam2 = 2.f;
static const char* s_debugParam3 = "TEST";
static CSceneObjDummy s_sceneObjDummy[] =
{
	{ 1, "���Y", 10, 11.1f },
	{ 2, "���Y", 20, 22.2f },
	{ 3, "�O�Y", 30, 33.3f }
};
static CSceneObjDummy* searchSceneObj(const int id)
{
	for (auto& o : s_sceneObjDummy)
	{
		if (o.id == id)
			return &o;
	}
	return nullptr;
}

const char* boolToStr(const bool value){ return value ? "true" : "false"; }

void testRegistNamedRef()
{
	//struct refDebugCpuMeter{ typedef (�^��) TYPE; TYPE* operator()(const RefKey& key) const { return (�f�[�^�̎Q��); } };
	struct refDebugCpuMeter{ typedef bool TYPE; TYPE* operator()(const RefKey& key) const { return &s_debugCpuMeter; } };
	struct refDebugParam1{ typedef int TYPE; TYPE* operator()(const RefKey& key) const { return &s_debugParam1; } };
	struct refDebugParam2{ typedef float TYPE; TYPE* operator()(const RefKey& key) const { return &s_debugParam2; } };
	struct refDebugParam3{ typedef const char*TYPE; TYPE* operator()(const RefKey& key) const { return &s_debugParam3; } };
	struct refSceneObjDummy{ typedef CSceneObjDummy TYPE; TYPE *operator()(const RefKey& key) const { return searchSceneObj(key.m_sub); } };
	
	CNamedRefSingleton named_ref;
	named_ref->regist(RefKey("DebugCpuMeter"), refDebugCpuMeter());
	named_ref->regist(RefKey("DebugParam1"), refDebugParam1());
	named_ref->regist(RefKey("DebugParam2"), refDebugParam2());
	named_ref->regist(RefKey("DebugParam3"), refDebugParam3());
	named_ref->regist(RefKey("SceneObj", 1), refSceneObjDummy());
	named_ref->regist(RefKey("SceneObj", 2), refSceneObjDummy());
	named_ref->regist(RefKey("SceneObj", 3), refSceneObjDummy());
}

void testPrintNamedRef()
{
	CNamedRefSingleton named_ref;
	printf("DebugCpuMeter=%s\n", boolToStr(named_ref->getBool(RefKey("DebugCpuMeter"))));
	printf("DebugParam1=%d\n", named_ref->getInt(RefKey("DebugParam1")));
	printf("DebugParam2=%.3f\n", named_ref->getFloat(RefKey("DebugParam2")));
	printf("DebugParam3=\"%s\"\n", named_ref->getStr(RefKey("DebugParam3")));
	for (int id : {1, 2, 3} )
	{
		CRefR<CSceneObjDummy> obj(named_ref, RefKey("SceneObj", id));
		printf("SceneObj[id=%d]: {name\"%s\", data1=%d, data2=%.3f}\n", obj->id, obj->name, obj->data1, obj->data2);
	}
}

void testUpdateNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->setBool(RefKey("DebugCpuMeter"), true);
	named_ref->setInt(RefKey("DebugParam1"), 123);
	named_ref->setFloat(RefKey("DebugParam2"), 456.789f);
	named_ref->setStr(RefKey("DebugParam3"), "New String");
	{
		CRefW<CSceneObjDummy> obj(named_ref, RefKey("SceneObj", 2));
		obj->data1 = 321;
		obj->data2 = 987.654f;
	}
}

void testResetRefAll()
{
	CNamedRefSingleton named_ref;
	named_ref->resetRefAll();
}

int main(const int argc, const char* argv[])
{
	testRegistNamedRef();
	testPrintNamedRef();
	testUpdateNamedRef();
	testResetRefAll();
	testPrintNamedRef();
	return EXIT_SUCCESS;
}

// End of file
