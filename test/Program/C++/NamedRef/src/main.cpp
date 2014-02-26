#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdint.h>//uintptr_t,intptr_t�p
#include <limits.h>//INT_MAX�p

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
//��C++11�d�l�U��
//#define TLS_IS_POSIX//TLS�̐錾��POSIX�d�l�ɂ��鎞�͂��̃}�N����L���ɂ���
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX�d�l
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows�d�l
#endif//TLS_IS_POSIX

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

//--------------------------------------------------------------------------------
//�v�[���A���P�[�^�N���X

//----------------------------------------
//�N���X�錾
class CPoolAllocator;

//----------------------------------------
//�v�[���A���P�[�^�N���X��p�z�unew/delete����
//���N���X���Ŏg�p���邽�߂̂��̂Ȃ̂ŁA���ڎg�p�͋֎~
//���N���X����delete���邱�ƂŁA�f�X�g���N�^�̌Ăяo���ɂ��Ή�
//�z�unew
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw();
//�z�udelete
void operator delete(void* p, CPoolAllocator& allocator) throw();

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
//�v�[���A���P�[�^�N���X��p�z�unew/delete����
//�z�unew
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw() { return allocator.alloc(size); }
//�z�udelete
void operator delete(void* p, CPoolAllocator& allocator) throw() { allocator.free(p); }

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
//CRC�Z�o

//--------------------
//�^
typedef unsigned int crc32_t;//CRC32�^

//--------------------
//�y�ʏ�֐��Łz�����񂩂�CRC�Z�o
crc32_t calcCRC32(const char* str)
{
	//�_�~�[����
	return reinterpret_cast<crc32_t>(str);
}

//--------------------------------------------------------------------------------
//���O�t���f�[�^�Q�ƃN���X

#include <atomic>//�A�g�~�b�N�^
#include <unordered_map>//�y�b��zC++11�̃n�b�V���e�[�u�����C�u����
                        //���ł���΁A�q�[�v���g�p���Ȃ��Ǝ��̎����ɕς����������肷��

//----------------------------------------
//���O�t���f�[�^�Q�ƃN���X
//���e���v���[�g�p�����[�^�ŋL�^�\�ȎQ�Ƃ̍ő吔���w��
template<std::size_t MAX, int SPIN = CSpinLock::DEFAULT_SPIN_COUNT>
class CNamedRefT
{
public:
	//�萔
	static const int MAX_NODES = MAX;//�L�^�\�ȎQ�Ƃ̍ő吔���w��
	static const int SPIN_COUNT = SPIN;//�X�s�����b�N�̃s���J�E���g��
public:
	//�^
	typedef unsigned long long u64;//64�r�b�g�^
	typedef unsigned long u32;//32�r�b�g�^
	typedef u64 KeyPrim;//�L�[�^�i�n�b�V���e�[�u���p�̃v���~�e�B�u�^�j
	//�L�[�^
	struct Key
	{
		union
		{
			KeyPrim m_prim;//�v���~�e�B�u�^�L�[
			struct
			{
				u32 m_main;//��L�[
				u32 m_sub;//���L�[
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
			m_main(calcCRC32(name)),
			m_sub(sub_key)
		{}
		Key(const char* name) :
			m_main(calcCRC32(name)),
			m_sub(0)
		{}
		Key(const unsigned int main_key, const char* sub_key) :
			m_main(main_key),
			m_sub(calcCRC32(sub_key))
		{}
		Key(const char* name, const char* sub_key) :
			m_main(calcCRC32(name)),
			m_sub(calcCRC32(sub_key))
		{}
		//�f�X�g���N�^
		~Key()
		{}
	};
private:
	//--------------------
	//�f�[�^�Q�ƌ^�F���ʕ�
	struct RefNodeCore
	{
		//���\�b�h
		virtual void* getRefByFunctor() const = 0;//�֐��I�u�W�F�N�g���g�p���ĕϐ��̎Q�Ƃ��擾
		virtual void getValByFunctor(void* val) const = 0;//�֐��I�u�W�F�N�g���g�p���ĕϐ��̒l���擾
		virtual void setValByFunctor(const void* val) = 0;//�֐��I�u�W�F�N�g���g�p���ĕϐ��̒l���X�V
		//�f�[�^�̎Q�Ƃ��擾
		template<typename T>
		void* getRefCore() const
		{
			if (m_removed.load() == true)//�y�ی������z�폜�ς݃`�F�b�N
				return nullptr;
			ASSERT(typeid(T) == m_type, "This type is not match.(this=%s, request=%s)", m_type.name(), typeid(T).name());
			if (typeid(T) != m_type)
				return nullptr;
			if (m_ref.load() == nullptr)//�Q��ڈȍ~�̃A�N�Z�X�������ɂ��邽�߂ɁA�Q�Ƃ��L������
				m_ref.store(getRefByFunctor());
			return m_ref.load();
		}
		//�f�[�^�̎Q�Ƃ��擾
		template<typename T>
		T* getRef(){ return static_cast<T*>(getRefCore<T>()); }
		//�f�[�^�̎Q�Ƃ��擾
		template<typename T>
		const T* getRef() const { return static_cast<T*>(getRefCore<T>()); }
		//�f�[�^�̒l���擾
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
		//�f�[�^�̒l���X�V
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
		void resetRef(){ m_ref.store(nullptr); }
		//���[�h���b�N�擾
		void rLock() const { CRWLockHelper(m_lock).rLock(SPIN_COUNT); }
		//���C�g���b�N�擾
		void wLock() const { CRWLockHelper(m_lock).wLock(SPIN_COUNT); }
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
	//�f�[�^�Q�ƌ^�F�������F���ڎQ�ƃ^�C�v
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
	//�f�[�^�Q�ƌ^�F�������F�A�N�Z�b�T�^�C�v
	//�����ڎQ�ƃ^�C�v�̕����A�Q�Ƃ��L���ł��镪�����B
	//���A�N�Z�b�T�^�C�v�́A����K���A�N�Z�b�T��ʂ��B
	template<typename F>
	struct AccessorNode : public RefNodeCore
	{
		//�^
		typedef typename F::TYPE TYPE;//�f�[�^�^
		typedef typename F::getter GETTER_FUNCTOIR;//�f�[�^�̒l�擾�p�֐��I�u�W�F�N�g�^
		typedef typename F::setter SETTER_FUNCTOIR;//�f�[�^�̒l�X�V�p�֐��I�u�W�F�N�g�^
		//�y�I�[�o�[���C�h�z�y�����z�֐��I�u�W�F�N�g���g�p���ĕϐ��̎Q�Ƃ��擾
		void* getRefByFunctor() const override{ return nullptr; }
		//�y�I�[�o�[���C�h�z�֐��I�u�W�F�N�g���g�p���ăf�[�^�̒l���擾
		void getValByFunctor(void* val) const override
		{
			GETTER_FUNCTOIR functor;
			*static_cast<TYPE*>(val) = functor(m_key);
		}
		//�y�I�[�o�[���C�h�z�֐��I�u�W�F�N�g���g�p���ăf�[�^�̒l���X�V
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
	struct getRefFunctorDummy : BaseRefF<int>{ TYPE* operator()(const Key& key) const { return nullptr; } };//�y�_�~�[�z�f�[�^�Q�Ɨp�֐��I�u�W�F�N�g�F���ڎQ�ƃ^�C�v
	struct accessorFunctorDummy : BaseRefF<int>{//�y�_�~�[�z�f�[�^�Q�Ɨp�֐��I�u�W�F�N�g�F�A�N�Z�b�T�^�C�v
		struct getter { TYPE operator()(const Key& key) const { return 0; } };
		struct setter { void operator()(const Key& key, const TYPE val) const {} };
	};
	using DirectRefNodeDummy = DirectRefNode<getRefFunctorDummy>;//�y�_�~�[�z�f�[�^�Q�ƌ^�F���ڎQ�ƃ^�C�v
	using AccessorNodeDummy = AccessorNode<accessorFunctorDummy>;//�y�_�~�[�z�f�[�^�Q�ƌ^�F�A�N�Z�b�T�^�C�v
public:
	//�萔
	#define MAX_SIZE(x, y) ((x) > (y) ? (x) : (y))
	static const std::size_t REF_NODE_SIZE_MAX = MAX_SIZE(sizeof(DirectRefNodeDummy), sizeof(AccessorNodeDummy));//�f�[�^�Q�ƌ^�̍ő�T�C�Y
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
		RefR(CNamedRefT<MAX>& map, const Key key) :
			m_namedRef(map.find(key, &m_isExist)),
			m_ref(nullptr)
		{
			//�ϐ��̎Q�Ƃ��擾
			if (m_namedRef)
			{
				m_ref = m_namedRef->getRef<T>();
				if (m_ref)
				{
					//�ϐ��̎Q�Ƃɐ��������烊�[�h���b�N�擾
					m_namedRef->rLock();
				}
			}
		}
		//�f�X�g���N�^
		~RefR()
		{
			if (m_namedRef && m_ref)
			{
				//���[�h���b�N���
				m_namedRef->rUnlock();
			}
		}
	private:
		//�t�B�[���h
		const RefNodeCore* m_namedRef;//�ϐ��Q�ƌ^
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
		RefW(CNamedRefT<MAX>& map, const Key key) :
			m_namedRef(map.find(key, &m_isExist)),
			m_ref(nullptr)
		{
			//�ϐ��̎Q�Ƃ��擾
			if (m_namedRef)
			{
				m_ref = m_namedRef->getRef<T>();
				if (m_ref)
				{
					//�ϐ��̎Q�Ƃɐ��������烉�C�g���b�N�擾
					m_namedRef->wLock();
				}
			}
		}
		//�f�X�g���N�^
		~RefW()
		{
			if (m_namedRef && m_ref)
			{
				//���C�g���b�N���
				m_namedRef->wUnlock();
			}
		}
	private:
		//�t�B�[���h
		RefNodeCore* m_namedRef;//�ϐ��Q�ƌ^
		T* m_ref;//�ϐ��Q��
		bool m_isExist;//�Q�Ɛ悪���݂��邩�H
	};
private:
	//--------------------
	//�S�̃u���b�N�F�ǂݍ��݃��b�N
	class WholeBLockR
	{
	public:
		//�R���X�g���N�^
		WholeBLockR(CRWLock& lock, const bool locked, const THREAD_ID locked_thread_id) :
			m_lock(lock)
		{
			//���b�N�����
			//���S�̃u���b�N���A���A�S�̃u���b�N���s�����X���b�h�Ɠ����X���b�h�Ȃ烍�b�N���Ȃ�
			m_locked = !(locked == true && CThreadID() == locked_thread_id);
			if (m_locked)
				CRWLockHelper(m_lock).rLock(SPIN_COUNT);
		}
		//�f�X�g���N�^
		~WholeBLockR()
		{
			if (m_locked)
				CRWLockHelper(m_lock).rUnlock();
		}
	private:
		CRWLock& m_lock;//���[�h�E���C�g���b�N
		bool m_locked;//���b�N��
	};
	//--------------------
	//�S�̃u���b�N�F�������݃��b�N
	class WholeBLockW
	{
	public:
		//�R���X�g���N�^
		WholeBLockW(CRWLock& lock, const bool locked, const THREAD_ID locked_thread_id) :
			m_lock(lock)
		{
			//���b�N�����
			//���S�̃u���b�N���A���A�S�̃u���b�N���s�����X���b�h�Ɠ����X���b�h�Ȃ烍�b�N���Ȃ�
			m_locked = !(locked == true && CThreadID() == locked_thread_id);
			if (m_locked)
				CRWLockHelper(m_lock).wLock(SPIN_COUNT);
		}
		//�f�X�g���N�^
		~WholeBLockW()
		{
			if (m_locked)
				CRWLockHelper(m_lock).wUnlock();
		}
	private:
		CRWLock& m_lock;//���[�h�E���C�g���b�N
		bool m_locked;//���b�N��
	};
	//�N���X���N���X��`�F�����܂�
	//--------------------
public:
	//���\�b�h
	//�ϐ��Q�Ɨp�֐��I�u�W�F�N�g�o�^�F���ڎQ�ƃ^�C�v
	template<typename F>
	bool regist(const Key key, F functor, bool* is_exist = nullptr)
	{
		//�S�̃��C�g���b�N�擾�i����͎����j
		WholeBLockW lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//�n�b�V���e�[�u���o�^�ς݃`�F�b�N
		NamedRefTable::const_iterator node = m_namedRefList.find(key);
		if (node != m_namedRefList.end())
		{
			if (is_exist)
				*is_exist = true;
			return false;
		}
		if (is_exist)
			*is_exist = false;
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
	bool registAcc(const Key key, F functor_set, bool* is_exist = nullptr)
	{
		//�S�̃��C�g���b�N�擾�i����͎����j
		WholeBLockW lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//�n�b�V���e�[�u���o�^�ς݃`�F�b�N
		NamedRefTable::const_iterator node = m_namedRefList.find(key);
		if (node != m_namedRefList.end())
		{
			if (is_exist)
				*is_exist = true;
			return false;
		}
		if (is_exist)
			*is_exist = false;
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
	bool unregist(const Key key, bool* is_exist = nullptr)
	{
		//�S�̃��C�g���b�N�擾�i����͎����j
		WholeBLockW lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//�ϐ��Q�Ə��擾
		//�n�b�V���e�[�u���o�^�ς݃`�F�b�N
		NamedRefTable::iterator node = m_namedRefList.find(key);
		if (node == m_namedRefList.end())
		{
			if (is_exist)
				*is_exist = false;
			return false;
		}
		if (is_exist)
			*is_exist = true;
		//�o�^�����ƍ폜
		RefNodeCore* ref = node->second;//�n�b�V���e�[�u���̏����Q��
		if (ref)
		{
			//ref->wLock();//�y�s�v�z���C�g���b�N�擾
			node->second = nullptr;//�n�b�V���e�[�u���������j��
			//ref->wUnlock();//�y�s�v�z���C�g���b�N���
			m_allocator.destroy(ref);//���������
		}
		m_namedRefList.erase(key);//�n�b�V���e�[�u������o�^����
		return true;
	}
	//�S�Ă̕ϐ��Q�Ɨp�֐��I�u�W�F�N�g�o�^����
	//���X���b�h�Z�[�t�ł͂Ȃ��̂Ń^�C�~���O�Ɍ��d����
	//���O�̂��߃��b�N���擾���Ă͂�����̂́A������̃A�N�Z�X���u���b�N���Ă���󋵂��ƁA
	//�@�폜��ɏ���������̂Ō��ǖ����N����
	void unregistAll()
	{
		//�S�̃��C�g���b�N�擾�i����͎����j
		WholeBLockW lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//�S�m�[�h����
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;//�n�b�V���e�[�u���̏����Q��
			if (ref)
			{
				//ref->wLock();//�y�s�v�z���C�g���b�N�擾
				node.second = nullptr;//�n�b�V���e�[�u���������j��
				//ref->wUnlock();//�y�s�v�z���C�g���b�N���
				m_allocator.destroy(ref);//���������
			}
		}
		m_namedRefList.clear();//�n�b�V���e�[�u���̑S�m�[�h���N���A
	}
	//�ϐ��̎Q�Ƃ��N���A
	void resetRef(const Key key, bool* is_exist = nullptr)
	{
		//�ϐ��Q�Ə��擾
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return;
		//�ϐ��̎Q�Ƃ��N���A
		ref->resetRef();
	}
	//�ϐ��̎Q�Ƃ�S�ăN���A
	void resetRefAll()
	{
		//�S�̃��[�h���b�N�擾�i����͎����j
		WholeBLockR lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//�S�ϐ��̎Q�Ƃ��N���A
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
	//�S�̃A�N�Z�X�u���b�N�J�n
	bool beginBlock()
	{
		//�u���b�N����Ԕ���
		if (m_wholeLocked.load() == true)
			return false;
		//�S�̃��C�g���b�N�擾
		CRWLockHelper(m_wholeLock).wLock(SPIN_COUNT);
		m_wholeLocked.store(true);//�S�̃u���b�N����ԊJ�n
		m_wholeLockThreadID.store(CThreadID().getID());//���݂̃X���b�hID�L�^
		return true;
	}
	//�S�̃A�N�Z�X�u���b�N�I��
	//�������őS�ϐ��Q�Ƃ̃N���A�����s
	//���u���b�N���s�����X���b�h���������ł��Ȃ�
	bool endBlock()
	{
		//�u���b�N����ԁ��X���b�h����
		if (m_wholeLocked.load() == false || CThreadID() != m_wholeLockThreadID.load())
			return false;
		//�S�Q�Ƃ��N���A
		resetRefAll();
		//�S�̃��C�g���b�N��@
		CRWLockHelper(m_wholeLock).wUnlock();
		m_wholeLocked.store(false);//�S�̃u���b�N����ԉ���
		m_wholeLockThreadID.store(INVALID_THREAD_ID);//���݂̃X���b�hID�L�^�N���A
		return true;
	}
private:
	//�ϐ��Q�Ə��擾�F���ʕ�
	inline const RefNodeCore* findCore(const Key key, bool* is_exist) const
	{
		//�S�̃��[�h���b�N�擾�i����͎����j
		WholeBLockR lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
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
	template<typename T>
	T get(const Key key, bool* is_exist = nullptr) const
	{
		const RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return static_cast<T>(0);
		ref->rLock();
		T val = ref->getVal<T>();
		ref->rUnlock();
		return val;
	}
	//bool�^�p
	bool getBool(const Key key, bool* is_exist = nullptr) const
	{
		return get<bool>(key, is_exist);
	}
	//int�^�p
	int getInt(const Key key, bool* is_exist = nullptr) const
	{
		return get<int>(key, is_exist);
	}
	//float�^�p
	float getFloat(const Key key, bool* is_exist = nullptr) const
	{
		return get<float>(key, is_exist);
	}
	//const char*�^�p
	const char* getStr(const Key key, bool* is_exist = nullptr) const
	{
		return get<const char*>(key, is_exist);
	}
	//----------
	//�l���X�V�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool set(const Key key, const T val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T now_val = ref->getVal<T>();
		if (prev_val)
			*prev_val = now_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//bool�^�p
	bool setBool(const Key key, const bool val, bool* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return set<bool>(key, val, prev_val, is_exist);
	}
	//int�^�p
	bool setInt(const Key key, const int val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return set<int>(key, val, prev_val, is_exist);
	}
	//float�^�p
	bool setFloat(const Key key, const float val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return set<float>(key, val, prev_val, is_exist);
	}
	//const char*�^�p
	bool setStr(const Key key, const char* str, const char** prev_val = nullptr, bool* is_exist = nullptr)
	{
		return set<const char*>(key, str, prev_val, is_exist);
	}
	//----------
	//CAS�iCompare And Swap�j�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool cas(const Key key, const T compare_val, const T swap_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T now_val = ref->getVal<T>();
		if (prev_val)
			*prev_val = now_val;
		if (ref->getVal<T>() == compare_val)
			ref->setVal<T>(swap_val);
		ref->wUnlock();
		return true;
	}
	//bool�^�p
	bool casBool(const Key key, const bool compare_val, const bool swap_val, bool* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return cas<bool>(key, compare_val, swap_val, prev_val, is_exist);
	}
	//int�^�p
	bool casInt(const Key key, const int compare_val, const int swap_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return cas<int>(key, compare_val, swap_val, prev_val, is_exist);
	}
	//float�^�p
	bool casFloat(const Key key, const float compare_val, const float swap_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return cas<float>(key, compare_val, swap_val, prev_val, is_exist);
	}
	//----------
	//�l���C���N�������g�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool inc(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val += static_cast<T>(1);
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool incInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return inc<int>(key, prev_val, is_exist);
	}
	//----------
	//�l���f�N�������g�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool dec(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val -= static_cast<T>(1);
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool decInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return dec<int>(key, prev_val, is_exist);
	}
	//----------
	//�l�����Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool add(const Key key, const T add_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val += add_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool addInt(const Key key, const int add_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return add<int>(key, add_val, prev_val, is_exist);
	}
	//float�^�p
	bool addFloat(const Key key, const float add_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return add<float>(key, add_val, prev_val, is_exist);
	}
	//----------
	//�l�����Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool sub(const Key key, const T sub_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val -= sub_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool subInt(const Key key, const int sub_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return sub<int>(key, sub_val, prev_val, is_exist);
	}
	//float�^�p
	bool subFloat(const Key key, const float sub_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return sub<float>(key, sub_val, prev_val, is_exist);
	}
	//----------
	//�l����Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool mul(const Key key, const T mul_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val *= mul_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool mulInt(const Key key, const int mul_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return mul<int>(key, mul_val, prev_val, is_exist);
	}
	//float�^�p
	bool mulFloat(const Key key, const float mul_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return mul<float>(key, mul_val, prev_val, is_exist);
	}
	//----------
	//�l�����Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool div(const Key key, const T div_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val /= div_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool divInt(const Key key, const int div_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return div<int>(key, div_val, prev_val, is_exist);
	}
	//float�^�p
	bool divFloat(const Key key, const float div_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return div<float>(key, div_val, prev_val, is_exist);
	}
	//----------
	//�l����]�Z�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool mod(const Key key, const T mod_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val %= mod_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool modInt(const Key key, const int mod_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return mod<int>(key, mod_val, prev_val, is_exist);
	}
	//----------
	//�l�𔽓]�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool reverse(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		ref->setVal<T>(~val);
		ref->wUnlock();
		return true;
	}
	//bool�^�p
	bool reverse(const Key key, bool* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		bool val = ref->getVal<bool>();
		if (prev_val)
			*prev_val = val;
		ref->setVal<bool>(val ? false : true );
		ref->wUnlock();
		return true;
	}
	//bool�^�p
	bool reverseBool(const Key key, bool* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return reverse(key, prev_val, is_exist);
	}
	//int�^�p
	bool reverseInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return reverse<int>(key, prev_val, is_exist);
	}
	//----------
	//�l��_���ρF�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool and(const Key key, const T and_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val &= and_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool andInt(const Key key, const int and_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return and<int>(key, and_val, prev_val, is_exist);
	}
	//----------
	//�l��_���a�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool or(const Key key, const T or_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val |= or_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool orInt(const Key key, const int or_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return or<int>(key, or_val, prev_val, is_exist);
	}
	//----------
	//�l��r���I�_���a�F�^�w��p
	//��prev_val �ŕύX�O�̒l���m�F�\
	//��is_exist �ŎQ�Ɛ�̕ϐ��̑��݂��m�F�\
	template<typename T>
	bool xor(const Key key, const T xor_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val ^= xor_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int�^�p
	bool xorInt(const Key key, const int xor_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return xor<int>(key, xor_val, prev_val, is_exist);
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
		//�S�̃u���b�N��ԉ���
		m_wholeLocked.store(false);
		m_wholeLockThreadID.store(INVALID_THREAD_ID);
	}
	//�f�X�g���N�^
	~CNamedRefT()
	{
		//�n�b�V���e�[�u������S�m�[�h�폜
		unregistAll();
	}
private:
	//�t�B�[���h
	CPoolAllocatorWithBuff<REF_NODE_SIZE_MAX, MAX_NODES> m_allocator;//�v�[���A���P�[�^�i�ő吔�ȏ�̊m�ۂ͕s�j
	NamedRefTable m_namedRefList;//�y�b��zC++11�W�����C�u�����̃n�b�V���e�[�u��
	mutable CRWLock m_wholeLock;//�S�̃u���b�N�p���[�h�E���C�g���b�N
	mutable std::atomic<bool> m_wholeLocked;//�S�̃u���b�N��
	mutable std::atomic<THREAD_ID> m_wholeLockThreadID;//�S�̃u���b�N�X���b�hID
};

//----------------------------------------
//���O�t���f�[�^�Q�ƃN���X�V���O���g��
//���e���v���[�g�p�����[�^�ŋL�^�\�ȎQ�Ƃ̍ő吔���w��
//���C���X�^���X����ID���w�肷�邱�ƂŁA�����̃V���O���g�����쐬�\
template <std::size_t MAX, int ID = 0, int SPIN = CSpinLock::DEFAULT_SPIN_COUNT>
class CNamedRefSingletonT
{
public:
	//�^
	typedef CNamedRefT<MAX, SPIN> NamedRef;//���O�t���f�[�^�Q�ƃN���X
public:
	//�萔
	static const int INSTANCE_ID = ID;//�C���X�^���X����ID
public:
	//�I�y���[�^
	operator NamedRef&() { return m_namedRef; }//�L���X�g�I�y���[�^
	const NamedRef* operator->() const { return &m_prosMap; }//�A���[���Z�q�i���O�t���f�[�^�Q�ƃN���X�̃v���L�V�[�j
	NamedRef* operator->(){ return &m_namedRef; }//�A���[���Z�q�i���O�t���f�[�^�Q�ƃN���X�̃v���L�V�[�j
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
//�f�[�^�Q�Ɨp�֐��I�u�W�F�N�g�쐬�}�N���F���ڎQ�ƃ^�C�v
#define NAMED_REF_FUNCTOR(name, code, type) \
	struct name : RefF<type> \
	{ \
	TYPE* operator()(const RefK& key) const \
		{ \
			code; \
		} \
	};
//�f�[�^�Q�Ɨp�֐��I�u�W�F�N�g�쐬�}�N���F���ڎQ�ƃ^�C�v�F�ȈՔ�
#define NAMED_REF_FUNCTOR_DIRECT(name, var, type) \
	NAMED_REF_FUNCTOR(name, return &var, type)

//--------------------
//�f�[�^�Q�Ɨp�֐��I�u�W�F�N�g�쐬�}�N���F�A�N�Z�b�T�^�C�v
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
//�f�[�^�Q�Ɨp�֐��I�u�W�F�N�g�쐬�}�N���F�A�N�Z�b�T�^�C�v�F�ȈՔ�
#define NAMED_ACCESSOR_FUNCTOR_SIMPLE(name, obj, getter_method, setter_method, type) \
	NAMED_ACCESSOR_FUNCTOR(name, return obj getter_method(), obj setter_method(val), type })

//----------------------------------------
//���O�t���f�[�^�Q�ƃN���X�V���O���g���C���X�^���X��
CNamedRef CNamedRefSingleton::m_namedRef;

//--------------------------------------------------------------------------------
//���O�t���f�[�^�Q�ƃN���X�e�X�g

//----------------------------------------
//�e�X�g�p�\���́F�L�������
struct CCharaInfo
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
	CCharaInfo(const int id_, const char* name_, const int data1_, const float data2_, const int data3_):
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
	//�L�������
	static CCharaInfo s_charaInfoList[] =
	{
		{ 10, "���Y", 11, 111.1f, 1111 },
		{ 20, "���Y", 22, 222.2f, 2222 },
		{ 30, "�O�Y", 33, 333.3f, 3333 }
	};
	//�L������񌟍��֐�
	static CCharaInfo* searchCharaInfo(const int id)
	{
		for (auto& o : s_charaInfoList)
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
	//struct refCharaInfo : RefF<CCharaInfo>{ TYPE *operator()(const RefK& key) const { return TEST::searchCharaInfo(key.m_sub); } };//�L�������Q�Ɨp
	//����L�̍\���̂Ɠ������Ƃ��uNAMED_REF_FUNCTOR�v�}�N���ő�p�ł���
	NAMED_REF_FUNCTOR_DIRECT(refDebugCpuMeter, TEST::s_debugCpuMeter, bool);//�y�f�o�b�O�p�zCPU�g�p���\����ԎQ�Ɨp
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam1, TEST::s_debugData1, int);//�y�f�o�b�O�p�z�f�[�^1�Q�Ɨp
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam2, TEST::s_debugData2, float);//�y�f�o�b�O�p�z�f�[�^2�Q�Ɨp
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam3, TEST::s_debugData3, const char*);//�y�f�o�b�O�p�z�f�[�^3�Q�Ɨp
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam4, TEST::s_debugData4, short);//�y�f�o�b�O�p�z�f�[�^4�Q�Ɨp
	NAMED_REF_FUNCTOR(refCharaInfo, return TEST::searchCharaInfo(key.m_sub), CCharaInfo);//�L�������Q�Ɨp

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
	struct refCharaInfoData3 : RefF<int>{//�L��������Data3�A�N�Z�X�p
		typedef CCharaInfo OBJ;
		static OBJ* search(const RefK& key){ return TEST::searchCharaInfo(key.m_sub); }
		struct getter{ TYPE operator()(const RefK& key) const { const OBJ* obj = search(key);  return obj ? obj->getData3() : 0; } };
		struct setter{ void operator()(const RefK& key, const TYPE val) { OBJ* obj = search(key); obj->setData3(val); } };
	};

	//���O�t���f�[�^�Q�ƃN���X�V���O���g��
	CNamedRefSingleton named_ref;

	//�ϐ��Q�Ƃ�o�^�F���ڎQ�ƃ^�C�v
	named_ref->regist(RefK("DebugCpuMeter"), refDebugCpuMeter());//�y�f�o�b�O�p�zCPU�g�p���\�����
	named_ref->regist(RefK("DebugParam1"), refDebugParam1());//�y�f�o�b�O�p�z�f�[�^1
	named_ref->regist(RefK("DebugParam2"), refDebugParam2());//�y�f�o�b�O�p�z�f�[�^2
	named_ref->regist(RefK("DebugParam3"), refDebugParam3());//�y�f�o�b�O�p�z�f�[�^3
	named_ref->regist(RefK("DebugParam4"), refDebugParam4());//�y�f�o�b�O�p�z�f�[�^4
	named_ref->regist(RefK("CharaInfo", 10), refCharaInfo());//�L�������FID=10
	named_ref->regist(RefK("CharaInfo", 20), refCharaInfo());//�L�������FID=20
	named_ref->regist(RefK("CharaInfo", 30), refCharaInfo());//�L�������FID=30
	//�ϐ��Q�Ƃ�o�^�F�A�N�Z�b�T�^�C�v
	named_ref->registAcc(RefK("DebugParam5"), refDebugParam5());//�y�f�o�b�O�p�z�f�[�^5
	named_ref->registAcc(RefK("CharaInfo::Data3", 10), refCharaInfoData3());//�L�������FData3�FID=10
	named_ref->registAcc(RefK("CharaInfo::Data3", 20), refCharaInfoData3());//�L�������FData3�FID=20
	named_ref->registAcc(RefK("CharaInfo::Data3", 30), refCharaInfoData3());//�L�������FData3�FID=30
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
		CRefR<CCharaInfo> obj(named_ref, RefK("CharaInfo", id));//�����u���b�N�𔲂���܂Ń��b�N���擾�i�����J���j
		if (obj.isExist())
			printf("CharaInfo[id=%d]: {name=\"%s\", data1=%d, data2=%.3f, data3=%d}\n",
				obj->id, obj->name, obj->data1, obj->data2, named_ref->getInt(RefK("CharaInfo::Data3", id)));
	}
}

//----------------------------------------
//�e�X�g�֐��B�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^���X�V
void testUpdateNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->set(RefK("DebugCpuMeter"), true);
	named_ref->set(RefK("DebugParam1"), 123);
	named_ref->set(RefK("DebugParam2"), 456.789f);
	named_ref->set(RefK("DebugParam3"), "New String");
	named_ref->set<short>(RefK("DebugParam4"), 12345);
	named_ref->set(RefK("DebugParam5"), 67890);
	{
		int id = 20;
		CRefW<CCharaInfo> obj(named_ref, RefK("CharaInfo", id));//�����u���b�N�𔲂���܂Ń��b�N���擾�i�����J���j
		if (obj.isExist())
		{
			obj->data1 = 321;
			obj->data2 = 987.654f;
		}
		named_ref->setInt(RefK("CharaInfo::Data3", id), 987654);
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
		named_ref->xorInt(RefK("CharaInfo::Data3", id), 0xffff);
	}
}

//----------------------------------------
//�e�X�g�֐��D�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�Q�i���Z�P�̑O�̏�Ԃɖ߂��t�v�Z�j
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
		named_ref->xorInt(RefK("CharaInfo::Data3", id), 0xffff);
	}
}

//----------------------------------------
//�e�X�g�֐��E�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�R�i�_�����Z�j
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
//�e�X�g�֐��G�F�S�̃u���b�N�J�n
void testBeginBlock()
{
	CNamedRefSingleton named_ref;
	named_ref->beginBlock();
}

//----------------------------------------
//�e�X�g�֐��H�F�S�̃u���b�N�I��
void testEndBlock()
{
	CNamedRefSingleton named_ref;
	named_ref->endBlock();
}

//----------------------------------------
//�e�X�g�֐��I�F�ꕔ�̖��O�t���f�[�^�Q�Ƃ�o�^����
void testUnregistNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->unregist(RefK("DebugParam1"));
	named_ref->unregist(RefK("DebugParam3"));
	named_ref->unregist(RefK("DebugParam5"));
	named_ref->unregist(RefK("CharaInfo", 20));
	named_ref->unregist(RefK("CharaInfo::Data3", 20));
}

//----------------------------------------
//�e�X�g�֐��J�F�S�Ă̖��O�t���f�[�^�Q�Ƃ�o�^����
void testUnregistRefAll()
{
	CNamedRefSingleton named_ref;
	named_ref->unregistAll();
}

//----------------------------------------
//�}���`�X���b�h�e�X�g�@�F��ʓ����X�V�e�X�g
void readyTestThread1()//����
{
	CNamedRefSingleton named_ref;
	named_ref->setInt(RefK("DebugParam1"), 0);//�e�X�g�̂��߂�0�N���A
}
void testThread1(const int n)//����
{
	CNamedRefSingleton named_ref;
	for (int i = 0; i < 10000; ++ i)
		named_ref->addInt(RefK("DebugParam1"), n);//10000��n�����Z
}

//----------------------------------------
//�}���`�X���b�h�e�X�g�A:�u���b�N���̃A�N�Z�X�e�X�g
void testThread2()
{
	CNamedRefSingleton named_ref;
	printf("----- THREAD:BEGIN -----\n");
	int param1 = named_ref->getInt(RefK("DebugParam1"));//�f�[�^�擾
	printf("----- THREAD:SLEEP(param1=%d) -----\n", param1);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));//�X���[�v�i���̊ԂɃ��C�����Ńf�[�^�Q�Ƃ̓o�^�����������j
	param1 = named_ref->getInt(RefK("DebugParam1"));//�f�[�^�擾
	printf("----- THREAD:END(param1=%d) -----\n", param1);
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
	
	//�e�X�g�@�F������x�o�^���Ă��o�^�ς݂̃L�[�͓o�^�Ɏ��s���邾��
	testRegistNamedRef();

	//�e�X�g�B�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^���X�V
	printf("----- set value -----\n");
	testUpdateNamedRef();
	testPrintNamedRef();
	
	//�e�X�g�C�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�P
	printf("----- calc value (1) -----\n");
	testCalcNamedRef1();
	testPrintNamedRef();
	
	//�e�X�g�D�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�Q
	printf("----- calc value (2) -----\n");
	testCalcNamedRef2();
	testPrintNamedRef();
	
	//�e�X�g�E�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^�����Z�R
	printf("----- calc value (3) -----\n");
	testCalcNamedRef3();
	testPrintNamedRef();
	
	//�e�X�g�֐��F�F���O�t���f�[�^�Q�Ƃ������ŕێ�����Q�Ƃ����Z�b�g
	printf("----- reset-ref all -----\n");
	testResetRefAll();
	testPrintNamedRef();

	//�X���b�h�e�X�g�@
	printf("----- thread test -----\n");
	std::thread th1ready = std::thread(readyTestThread1);//�����iparam1��0�N���A�j
	th1ready.join();
	std::thread th1[10];
	int n = 1;
	for (auto& th1tmp : th1)
	{
		th1tmp = std::thread(testThread1, n++);
	}
	for (auto& th1tmp : th1)
	{
		th1tmp.join();
	}
	testPrintNamedRef();

	//�e�X�g�֐��G�F�S�̃u���b�N�J�n
	printf("----- begin block -----\n");
	testBeginBlock();
	testPrintNamedRef();

	//�X���b�h�e�X�g�A
	std::thread th2 = std::thread(testThread2);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));//�X���[�v�i���̊ԃX���b�h���̏������u���b�N�����j

	//�e�X�g�B�i�āj�F���O�t���f�[�^�Q�Ƃ��g���ăf�[�^���X�V
	printf("----- set value : 2nd time -----\n");
	testUpdateNamedRef();
	testPrintNamedRef();
	
	//�e�X�g�֐��H�F�S�̃u���b�N�I��
	printf("----- end block -----\n");
	testEndBlock();
	testPrintNamedRef();

	//�e�X�g�֐��I�F�ꕔ�̖��O�t���f�[�^�Q�Ƃ�o�^����
	printf("----- unregist -----\n");
	testUnregistNamedRef();
	testPrintNamedRef();
	
	//�e�X�g�֐��J�F�S�Ă̖��O�t���f�[�^�Q�Ƃ�o�^����
	printf("----- unregist all -----\n");
	testUnregistRefAll();
	testPrintNamedRef();

	//�X���b�h�I���҂�
	th2.join();

	return EXIT_SUCCESS;
}

// End of file
