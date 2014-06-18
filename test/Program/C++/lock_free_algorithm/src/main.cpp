//--------------------------------------------------------------------------------
//�R���p�C���X�C�b�`

//#define USE_GCC//GCC�g�p���́A���̃}�N����L��������

#define USE_POOL_ALLOCATOR//�X�^�b�N�^�L���[�̎����ŁA�v�[���A���P�[�^���g�p����ꍇ�́A���̃}�N����L��������
#define USE_LF_POOL_ALLOCATOR//���b�N�t���[�X�^�b�N�^�L���[�̎����ŁA���b�N�t���[�v�[���A���P�[�^���g�p����ꍇ�́A���̃}�N����L��������
//#define USE_SAFE_ALLOC_LF_POOL_ALLOCATOR//���b�N�t���[�v�[���A���P�[�^�̎����ŁA�����C���f�b�N�X�̃A���P�[�g��r�����䂷��ꍇ�́A���̃}�N����L��������
//#define USE_SAFE_CAS_LF_POOL_ALLOCATOR//���b�N�t���[�v�[���A���P�[�^�̎����ŁACAS���삪�Ӑ}�ʂ�ɓ��삵�Ȃ����̈��S�΍���g�p����ꍇ�́A���̃}�N����L��������
//#define USE_SAFE_CAS_LF_STACK//���b�N�t���[�X�^�b�N�̎����ŁACAS���삪�Ӑ}�ʂ�ɓ��삵�Ȃ����̈��S�΍���g�p����ꍇ�́A���̃}�N����L��������
//#define USE_SAFE_CAS_LF_QUEUE//���b�N�t���[�L���[�̎����ŁACAS���삪�Ӑ}�ʂ�ɓ��삵�Ȃ����̈��S�΍���g�p����ꍇ�́A���̃}�N����L��������
//��CAS����̈��S�΍�́ACAS����Ɍ�肪����A�Ӑ}�ʂ�ɓ��삵�Ȃ��������̋�����r�p�ɗp�ӂ������́BCAS������X�s�����b�N�ŕی삷�邽�߁A���b�N�t���[�ł͂Ȃ��Ȃ��Ă��܂��B

#define NORMAL_LOCK_IS_MUTEX//�ʏ�ł̃��b�N������~���[�e�b�N�X���g�p���čs���ꍇ�A���̃}�N����L�������� �����������̓X�s�����b�N���g�p����

//--------------------------------------------------------------------------------
//�e�X�g�p�R���p�C���X�C�b�`�^�萔

#define ENABLE_EASY_TEST//�ȈՃe�X�g�����s����ꍇ�́A���̃}�N����L��������
#define ENABLE_THREAD_TEST//�X�e�b�h�e�X�g�����s����ꍇ�́A���̃}�N����L��������

#define ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR//�ʏ�v�[���A���P�[�^�̃e�X�g��L���ɂ���ꍇ�́A���̃}�N����L��������
#define ENABLE_TEST_FOR_LF_POOL_ALLOCATOR//���b�N�t���[�v�[���A���P�[�^�̃e�X�g��L���ɂ���ꍇ�́A���̃}�N����L��������
#define ENABLE_TEST_FOR_NORMAL_STACK//�ʏ�X�^�b�N�̃e�X�g��L���ɂ���ꍇ�́A���̃}�N����L��������
#define ENABLE_TEST_FOR_LF_STACK//���b�N�t���[�X�^�b�N�̃e�X�g��L���ɂ���ꍇ�́A���̃}�N����L��������
#define ENABLE_TEST_FOR_NORMAL_QUEUE//�ʏ�L���[�̃e�X�g��L���ɂ���ꍇ�́A���̃}�N����L��������
#define ENABLE_TEST_FOR_LF_QUEUE//���b�N�t���[�L���[�̃e�X�g��L���ɂ���ꍇ�́A���̃}�N����L��������

//#define ENABLE_TEST_PRINT//�X���b�h�e�X�g�̌o�߃��b�Z�[�W��\������ꍇ�́A���̃}�N����L��������
//#define ENABLE_TEST_PRINT_DEBUG_INFO//�X���b�h�e�X�g�̍Ō�Ƀf�o�b�O����\������ꍇ�́A���̃}�N����L��������
//#define TEST_1_TIME//1�񂾂��̃e�X�g�����s����ꍇ�́A���̃}�N����L��������
#ifdef TEST_1_TIME
static const int TEST_COUNT = 1;//�e�X�g��
static const int TEST_PRINT_COUNT = 0;//�e�X�g���̃��b�Z�[�W�\����
static const int TEST_PUSH_THREADS = 1;//�e�X�g�p�̃v�b�V���^�G���L���[�X���b�h��
static const int TEST_POP_THREADS = 1;//�e�X�g�p�̃|�b�v�^�f�L���[�X���b�h��
static const int TEST_ALLOC_THREADS = 1;//�e�X�g�p�̃A���P�[�g�X���b�h��
static const int TEST_POOL_SIZE = 10;//�e�X�g�p�v�[���A���P�[�^�̃v�[���T�C�Y
#else//TEST_1_TIME
#ifdef USE_GCC
static const int TEST_COUNT = 100000;//�e�X�g��
static const int TEST_PRINT_COUNT = 5;//�e�X�g���̃��b�Z�[�W�\����
static const int TEST_PUSH_THREADS = 3;//�e�X�g�p�̃v�b�V���^�G���L���[�X���b�h��
static const int TEST_POP_THREADS = 2;//�e�X�g�p�̃|�b�v�^�f�L���[�X���b�h��
static const int TEST_ALLOC_THREADS = 5;//�e�X�g�p�̃A���P�[�g�X���b�h��
static const int TEST_POOL_SIZE = 20;//�e�X�g�p�v�[���A���P�[�^�̃v�[���T�C�Y
#else//USE_GCC
static const int TEST_COUNT = 500000;//�e�X�g��
static const int TEST_PRINT_COUNT = 5;//�e�X�g���̃��b�Z�[�W�\����
static const int TEST_PUSH_THREADS = 3;//�e�X�g�p�̃v�b�V���^�G���L���[�X���b�h��
static const int TEST_POP_THREADS = 2;//�e�X�g�p�̃|�b�v�^�f�L���[�X���b�h��
static const int TEST_ALLOC_THREADS = 5;//�e�X�g�p�̃A���P�[�g�X���b�h��
static const int TEST_POOL_SIZE = 20;//�e�X�g�p�v�[���A���P�[�^�̃v�[���T�C�Y
#endif//USE_GCC
#endif//TEST_1_TIME
#ifdef ENABLE_TEST_PRINT
static const int TEST_PRINT_STEP = TEST_COUNT >= TEST_PRINT_COUNT * 10 ? TEST_COUNT / TEST_PRINT_COUNT : 10;//�e�X�g���̃��b�Z�[�W�\���̊Ԋu
#else//ENABLE_TEST_PRINT
static const int TEST_PRINT_STEP = 0;
#endif//ENABLE_TEST_PRINT

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>//assert()�p
#include <cstddef>//std::size_t�p

//�A���C�������g�w��
#ifdef USE_GCC
#define alignas(n) __attribute__((aligned(n)))//GCC�p
#else//USE_GCC
#define alignas(n) __declspec(align(n))//VC++�p
#endif//USE_GCC

//�A���C�������g�w��t���������m�ۊ֐�
//��VC++�d�l�ɍ��킹�ċ��ʉ�
#ifdef USE_GCC
#include <cstddef>//std::size_t�p
#include <stdlib.h>//posix_memalign()�p
#include <memory.h>//free()�p
inline void* _aligned_malloc(const std::size_t size, const std::size_t alignment)
{
	void *p;
	int ret = posix_memalign(&p, alignment, size);
	return (ret == 0) ? p : 0;
}
inline void _aligned_free(void* p)
{
	free(p);
}
#else//USE_GCC
#include <memory.h>//_aligned_malloc(), _aligned_free()�p
//void* _aligned_malloc(size_t size, size_t alignment);
//void _aligned_free(void* p);
#endif//USE_GCC

//--------------------------------------------------------------------------------
//�v�[���A���P�[�^�p�C���N���[�h
#include <new>//new(void*), delete(void*, void*)
#include <bitset>//std::bitset
#include <thread>//C++11 std::this_thread

//--------------------------------------------------------------------------------
//�ʏ�X�^�b�N�^�L���[�p�C���N���[�h
#include <mutex>//C++11 std::mutex
#include <utility>//C++11 std::move

//--------------------------------------------------------------------------------
//���b�N�t���[�X�^�b�N�^�L���[�p�C���N���[�h
#include <atomic>//C++11 std::atomic
#include <utility>//C++11 std::move

//--------------------------------------------------------------------------------
//�ėp����

//�z��̗v�f����Ԃ�
template<typename T, std::size_t N>
inline std::size_t extentof(T(&val)[N]){return N; }

//--------------------------------------------------------------------------------
//�^�O�t���|�C���^�^
//��32�r�b�g�A�h���X�O��
//��POD�^��ۏ؂��邽�߂ɃR���X�g���N�^��R�s�[�I�y���[�^��p�ӂ��Ȃ�
//��POD�^�ɂ��āFhttp://ja.wikipedia.org/wiki/C++11#Plain_Old_Data_.E5.9E.8B.E3.81.AE.E5.AE.9A.E7.BE.A9.E3.81.AE.E4.BF.AE.E6.AD.A3
template<typename T>
struct tag_ptr
{
	//�^
	typedef unsigned long long value_type;//�^�O�t���|�C���^�^
	typedef T* pointer_type;//�|�C���^�^
	typedef unsigned int tag_type;//�^�O�^
	//�L���X�g�I�y���[�^
	inline operator value_type() const { return m_value; }
	inline operator const pointer_type() const { return ptr(); }
	inline operator pointer_type(){ return ptr(); }
	//�I�y���[�^
	inline bool operator==(const tag_ptr& lhs) const { return m_value == lhs.m_value; }
	inline bool operator!=(const tag_ptr& lhs) const { return m_value != lhs.m_value; }
	//�A�N�Z�b�T
	inline value_type value() const { return m_value; }
	inline const pointer_type ptr() const { return reinterpret_cast<const pointer_type>(m_value & 0xffffffffllu); }
	inline pointer_type ptr(){ return reinterpret_cast<pointer_type>(m_value & 0xffffffffllu); }
	inline tag_type tag() const { return static_cast<tag_type>(m_value >> 32); }
	inline bool isNull() const { return m_value == 0; }
	inline bool isNotNull() const { return m_value != 0; }
	inline void setTagPtr(const pointer_type ptr, const tag_type tag)
	{
		m_value = reinterpret_cast<value_type>(ptr) | (static_cast<value_type>(tag) << 32);
	}
	//�t�B�[���h
	value_type m_value;//�^�O�i���32�r�b�g�j�{�|�C���^�i����32�r�b�g�j
};

//--------------------------------------------------------------------------------
//�X�s�����b�N
class spin_lock
{
public:
	//���b�N�擾
	void lock()
	{
		while (m_lock.test_and_set());
	}
	//���b�N����
	void unlock()
	{
		m_lock.clear();
	}
private:
	//�t�B�[���h
	std::atomic_flag m_lock;//���b�N�p�t���O
};

//--------------------------------------------------------------------------------
//�ʏ�N���X�p�̃��b�N�I�u�W�F�N�g
//���~���[�e�b�N�X�܂��̓X�s�����b�N
class normal_lock
{
public:
	//���b�N�擾
	void lock()
	{
	#ifdef NORMAL_LOCK_IS_MUTEX
		m_lock.lock();//�~���[�e�b�N�X
	#else//NORMAL_LOCK_IS_MUTEX
		while (m_lock.test_and_set());//�X�s�����b�N
	#endif//NORMAL_LOCK_IS_MUTEX
	}
	//���b�N����
	void unlock()
	{
	#ifdef NORMAL_LOCK_IS_MUTEX
		m_lock.unlock();//�~���[�e�b�N�X
	#else//NORMAL_LOCK_IS_MUTEX
		m_lock.clear();//�X�s�����b�N
	#endif//NORMAL_LOCK_IS_MUTEX
	}
private:
	//�t�B�[���h
#ifdef NORMAL_LOCK_IS_MUTEX
	std::mutex m_lock;//�~���[�e�b�N�X
#else//NORMAL_LOCK_IS_MUTEX
	std::atomic_flag m_lock;//�X�s�����b�N�p�t���O
#endif//NORMAL_LOCK_IS_MUTEX
};

//--------------------------------------------------------------------------------
//�ʏ�v�[���A���P�[�^�N���X
template<class T, std::size_t POOL>
class pool_allocator
{
	static_assert(sizeof(T) >= 4, "sizeof(T) is too small.");

public:
	//�^
	typedef T value_type;//�l�^

	//�ė��p�v�[���^
	struct recycable_t
	{
		std::size_t m_next_index;//�ė��p�v�[���A���C���f�b�N�X
	};

public:
	//�萔
	static const std::size_t POOL_SIZE = POOL;//�v�[���T�C�Y
	static const std::size_t VALUE_SIZE = sizeof(value_type);//�l�̃T�C�Y
	static const std::size_t INVALID_INDEX = 0xffffffff;//�����ȃC���f�b�N�X
	static const std::size_t DIRTY_INDEX = 0xfefefefe;//�ė��p�v�[���A���C���f�b�N�X�폜�p

public:
	//���\�b�h

	//�������m��
	void* alloc()
	{
		std::lock_guard<normal_lock> lock(m_lock);//���b�N�i�X�R�[�v���b�N�j
		//�󂫃v�[�����m��
		if (m_vacantHead < POOL_SIZE)//�󂫃v�[���̐擪�C���f�b�N�X���v�[���T�C�Y�����Ȃ�󂫃v�[���𗘗p����
		{
			const std::size_t vacant_index = m_vacantHead++;//�󂫃v�[���̐擪�C���Ńb�N�X���擾���C���N�������g
			m_using[vacant_index] = true;//�C���f�b�N�X���g�p���ɂ���
		//	++m_usingCount;//�g�p���̐��𑝂₷�i�f�o�b�O�p�j
			return  m_pool[vacant_index];//�������m�ې���
		}
		//�ė��p�v�[���̐擪�C���f�b�N�X�������Ȃ烁�����m�ێ��s�i�ė��p�v�[���������j
		if (m_recyclableHead == INVALID_INDEX)
			return nullptr;//�������m�ێ��s
		//�ė��p�v�[�����m��
		{
			const std::size_t recyclable_index = m_recyclableHead;//�ė��p�v�[���̐擪�C���f�b�N�X���擾
			recycable_t* recyclable_pool = reinterpret_cast<recycable_t*>(m_pool[recyclable_index]);//�ė��p�v�[���̐擪�����蓖��
			m_recyclableHead = recyclable_pool->m_next_index;//�ė��p�v�[���̐擪�C���f�b�N�X�����̍ė��p�v�[���ɕύX
			recyclable_pool->m_next_index = DIRTY_INDEX;//�ė��p�v�[���̘A���C���f�b�N�X���폜
			m_using[recyclable_index] = true;//�C���f�b�N�X���g�p���ɂ���
		//	++m_usingCount;//�g�p���̐��𑝂₷�i�f�o�b�O�p�j
			return recyclable_pool;//�������m�ې���
		}
	}

private:
	//����������i���ʏ����j
	//�����b�N�擾�͌Ăяo�����ōs��
	bool free(void* p, const std::size_t index)
	{
		recycable_t* deleted_pool = reinterpret_cast<recycable_t*>(m_pool[index]);//������ꂽ���������Q��
		deleted_pool->m_next_index = m_recyclableHead;//���̍ė��p�v�[���̃C���f�b�N�X��ۑ�
		m_recyclableHead = index;//�ė��p�v�[���̐擪�C���f�b�N�X��ύX
		m_using[index] = false;//�C���f�b�N�X�𖢎g�p��Ԃɂ���
	//	--m_usingCount;//�g�p���̐������炷�i�f�o�b�O�p�j
		return true;
	}
	
	//�|�C���^���C���f�b�N�X�ɕϊ�
	std::size_t ptrToIndex(void* p)
	{
		const std::size_t index = (reinterpret_cast<char*>(p) - reinterpret_cast<char*>(m_pool)) / VALUE_SIZE;
		if (index >= POOL_SIZE)//�͈͊O�̃C���f�b�N�X�Ȃ�I��
		{
			static const bool IS_INVALID_POINTER_OF_POOL = false;
			assert(IS_INVALID_POINTER_OF_POOL);
			return INVALID_INDEX;
		}
		if (!m_using[index])//�C���f�b�N�X�����ɖ��g�p��ԂȂ�I��
		{
			static const bool IS_ALREADY_DELETE_POINTER = false;
			assert(IS_ALREADY_DELETE_POINTER);
			return INVALID_INDEX;
		}
		return index;
	}

public:
	//���������
	bool free(void* p)
	{
		std::lock_guard<normal_lock> lock(m_lock);//���b�N�i�X�R�[�v���b�N�j
		const std::size_t index = ptrToIndex(p);//�|�C���^���C���f�b�N�X�ɕϊ�
		if (index == INVALID_INDEX)
			return false;
		return free(p, index);
	}
	
	//�������m�ۂƃR���X�g���N�^�Ăяo��
	template<typename...Tx>
	value_type* newObj(Tx... args)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(args...);
	}
	template<typename ObjType, typename...Tx>
	ObjType* newObj(Tx... args)
	{
		static_assert(sizeof(ObjType) <= VALUE_SIZE, "sizeof(ObjType) is too large.");
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)ObjType(args...);
	}
	value_type* newCopyObj(value_type& org)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(org);
	}
	value_type* newMoveObj(value_type&& org)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(std::move(org));
	}

	//����������ƃf�X�g���N�^�Ăяo��
	template<typename ObjType>
	bool deleteObj(ObjType* p)
	{
		std::lock_guard<normal_lock> lock(m_lock);//���b�N�i�X�R�[�v���b�N�j
		const std::size_t index = ptrToIndex(p);//�|�C���^���C���f�b�N�X�ɕϊ�
		if (index == INVALID_INDEX)
			return false;
		p->~ObjType();//�f�X�g���N�^�Ăяo��
		//operator delete(p, p);
		return free(p, index);
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for pool_allocator -----\n");
	//	printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d, usingCount=%d\n", POOL_SIZE, VALUE_SIZE, m_vacantHead, m_usingCount);
		printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d\n", POOL_SIZE, VALUE_SIZE, m_vacantHead);
		printf("Using:\n");
		for (int index = 0; index < POOL_SIZE; ++index)
		{
			if (m_using[index])
			{
				printf("[%d] ", index);
				print_node(*reinterpret_cast<const value_type*>(m_pool[index]));
				printf("\n");
			}
		}
		printf("Recycable pool:\n");
		std::size_t recycable_index = m_recyclableHead;
		while (recycable_index != INVALID_INDEX)
		{
			printf(" [%d]", recycable_index);
			recycable_t* recycable_pool = reinterpret_cast<recycable_t*>(m_pool[recycable_index]);
			recycable_index = recycable_pool->m_next_index;
		}
		printf("\n");
		printf("----------\n");
	}

public:
	//�R���X�g���N�^
	pool_allocator() :
		m_vacantHead(0),
		m_recyclableHead(INVALID_INDEX)
	{}
	//�f�X�g���N�^
	~pool_allocator()
	{}

private:
	//�t�B�[���h
	char m_pool[POOL_SIZE][VALUE_SIZE];//�v�[���o�b�t�@ ���擪�ɔz�u���ăN���X�̃A���C�����g�ƈ�v������
	std::size_t m_vacantHead;//�󂫃v�[���̐擪�C���f�b�N�X
	std::size_t m_recyclableHead;//�ė��p�v�[���̐擪�C���f�b�N�X
	std::bitset<POOL_SIZE> m_using;//�g�p���C���f�b�N�X�i��d�������p�j
//	std::size_t m_usingCount;//�g�p���̐��i�f�o�b�O�p�j���K�{�̏��ł͂Ȃ�
	normal_lock m_lock;//���b�N�I�u�W�F�N�g�i�~���[�e�b�N�Xor�X�s�����b�N�j
};

//--------------------------------------------------------------------------------
//���b�N�t���[�v�[���A���P�[�^�N���X
//��ABA���΍􂠂�i�v�[���̍ė��p�C���f�b�N�X��8�r�b�g�̃^�O��t���ĊǗ��j
//���v�[���\�ȗv�f���̍ő��2^(32-8)-2 = 16,777,214�i2^(32-8)-1���ƁA�l��INVALID_INDEX�ɂȂ�\��������̂�NG�j
template<class T, std::size_t POOL>
class lf_pool_allocator
{
	static_assert(sizeof(T) >= 4, "sizeof(T) is too small.");
	static_assert(POOL < 0x00ffffff, "POOL is too large.");

public:
	//�^
	typedef T value_type;//�l�^

	//�ė��p�v�[���^
	struct recycable_t
	{
		std::atomic<std::size_t> m_next_index;//�ė��p�v�[���A���C���f�b�N�X
	};

public:
	//�萔
	static const std::size_t POOL_SIZE = POOL;//�v�[���T�C�Y
	static const std::size_t VALUE_SIZE = sizeof(value_type);//�l�̃T�C�Y
	static const std::size_t INVALID_INDEX = 0xffffffff;//�����ȃC���f�b�N�X
	static const std::size_t DIRTY_INDEX = 0xfefefefe;//�ė��p�v�[���A���C���f�b�N�X�폜�p

public:
	//���\�b�h
	
	//�������m��
	void* alloc()
	{
		//�󂫃v�[�����m��
		if (m_vacantHead.load() < POOL_SIZE)//�󂫃v�[���̐擪�C���f�b�N�X���v�[���T�C�Y�����Ȃ�󂫃v�[���𗘗p
		{
			const std::size_t vacant_index = m_vacantHead.fetch_add(1);//�󂫃v�[���̐擪�C���f�b�N�X���擾���ăC���N�������g
			if (vacant_index < POOL_SIZE)//�v�[���T�C�Y�����Ȃ�m�ې���
			{
				m_using[vacant_index].fetch_add(1);//�C���f�b�N�X���g�p����Ԃɂ���
			//	m_usingCount.fetch_add(1);//�g�p���̐��𑝂₷�i�f�o�b�O�p�j
			//	m_allocCount[vacant_index].fetch_add(1);//�A���P�[�g�񐔂��J�E���g�A�b�v�i�f�o�b�O�p�j
				return m_pool[vacant_index];//�������m�ې���
			}
			if (vacant_index > POOL_SIZE)//�C���N�������g�ŃI�[�o�[�����C���f�b�N�X�����ɖ߂�
				m_vacantHead.store(POOL_SIZE);
		}
		//�ė��p�v�[�����m��
		{
			std::size_t recycable_index_and_tag = m_recyclableHead.load();//�ė��p�v�[���̐擪�C���f�b�N�X���擾
		#ifdef USE_SAFE_ALLOC_LF_POOL_ALLOCATOR//�y���S�΍�z�������C���f�b�N�X�̃A���P�[�g��r������
			static const int retry_max = 32;
			int retry_count = retry_max;//���g���C��
		#endif//USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
			while (true)
			{
				if (recycable_index_and_tag == INVALID_INDEX)//�ė��p�v�[���̐擪�C���f�b�N�X�������Ȃ烁�����m�ێ��s�i�ė��p�v�[���������j
					return nullptr;//�������m�ێ��s
				const std::size_t recyclable_index = recycable_index_and_tag & 0x00ffffff;//�^�O�폜
				if (recyclable_index >= POOL_SIZE)//�ė��p�v�[���̐擪�C���f�b�N�X�͈͊O�Ȃ烊�g���C
				{
					recycable_index_and_tag = m_recyclableHead.load();//�ė��p�v�[���̐擪�C���f�b�N�X���Ď擾
					continue;//���g���C
				}
			#ifdef USE_SAFE_ALLOC_LF_POOL_ALLOCATOR//�y���S�΍�z�������C���f�b�N�X�̃A���P�[�g��r������
				const std::size_t index_using = m_using[recyclable_index].fetch_add(1);//�C���f�b�N�X���g�p����Ԃɂ���
				if (index_using != 0)//���̃X���b�h���C���f�b�N�X���������Ȃ烊�g���C
				{
					m_using[recyclable_index].fetch_sub(1);//�C���f�b�N�X�̎g�p����Ԃ�߂�
					--retry_count;
					if (retry_count == 0)//��萔�̃��g���C���ƂɃR���e�L�X�g�X�C�b�`
					{
						retry_count = retry_max;//���g���C�񐔂�������Ԃɖ߂�
						std::this_thread::sleep_for(std::chrono::nanoseconds(0));//�R���e�L�X�g�X�C�b�`�i�[���X���[�v�j
					}
					recycable_index_and_tag = m_recyclableHead.load();//�ė��p�v�[���̃C���f�b�N�X���Ď擾
					continue;//���g���C
				}
			#endif//USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
				recycable_t* recyclable_pool = reinterpret_cast<recycable_t*>(m_pool[recyclable_index]);//�ė��p�v�[���̐擪�����蓖��
				const std::size_t next_index_and_tag = recyclable_pool->m_next_index.load();//���̍ė��p�v�[���̃C���f�b�N�X���擾

				//CAS����@
			#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR//�y���S�΍�z���X�s�����b�N��CAS�����ی�
				m_lock.lock();//���b�N�擾
				const bool result = m_recyclableHead.compare_exchange_weak(recycable_index_and_tag, next_index_and_tag);//CAS����
				m_lock.unlock();//���b�N����
				if (result)
			#else//USE_SAFE_CAS_LF_POOL_ALLOCATOR
				if (m_recyclableHead.compare_exchange_weak(recycable_index_and_tag, next_index_and_tag))//CAS����
			#endif//USE_SAFE_CAS_LF_POOL_ALLOCATOR
				//�yCAS����̓��e�z
				//    if(m_recyclableHead == recyclable_index)//�ė��p�v�[���̐擪�C���f�b�N�X�𑼂̃X���b�h�����������Ă��Ȃ����H
				//        m_recyclableHead = next;//�ė��p�v�[���̐擪�C���f�b�N�X�����̍ė��p�C���f�b�N�X�ɕύX�i�������m�ې����j
				//    else
				//        recycable_index_and_tag = m_recyclableHead;//�ė��p�v�[���̐擪�C���f�b�N�X���Ď擾
				{
					recyclable_pool->m_next_index.store(DIRTY_INDEX);//�ė��p�v�[���̘A���C���f�b�N�X���폜
				#ifndef USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
					m_using[recyclable_index].fetch_sub(1);//�C���f�b�N�X���g�p����Ԃɂ���
				#endif//USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
				//	m_usingCount.fetch_add(1);//�g�p���̐��𑝂₷�i�f�o�b�O�p�j
				//	m_allocCount[recyclable_index].fetch_add(1);//�A���P�[�g�񐔂��J�E���g�A�b�v�i�f�o�b�O�p�j
					return recyclable_pool;//�������m�ې���
				}
				
		#ifdef USE_SAFE_ALLOC_LF_POOL_ALLOCATOR//�y���S�΍�z�������C���f�b�N�X�̃A���P�[�g��r������
				m_using[recyclable_index].fetch_sub(1);//�C���f�b�N�X�̎g�p����Ԃ�߂��ă��g���C
		#endif//USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
			}
			return nullptr;//�_�~�[
		}
	}

private:
	//����������i���ʏ����j
	bool free(void* p, const std::size_t index)
	{
		const std::size_t tag = static_cast<std::size_t>(m_tag.fetch_add(1));//�^�O�擾
		const std::size_t index_and_tag = index | (tag << 24);//�^�O�t���C���f�b�N�X�쐬
		std::size_t recycable_index_and_tag = m_recyclableHead.load();//�ė��p�v�[���̐擪�C���f�b�N�X���擾
		while (true)
		{
			recycable_t* deleted_pool = reinterpret_cast<recycable_t*>(m_pool[index]);//������ꂽ���������Q��
			deleted_pool->m_next_index.store(recycable_index_and_tag);//���̍ė��p�v�[���̃C���f�b�N�X��ۑ�
			
			//CAS����A
		#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR//�y���S�΍�z���X�s�����b�N��CAS�����ی�
			m_lock.lock();//���b�N�擾
			const bool result = m_recyclableHead.compare_exchange_weak(recycable_index_and_tag, index_and_tag);//CAS����
			m_lock.unlock();//���b�N����
			if (result)
		#else//USE_SAFE_CAS_LF_POOL_ALLOCATOR
			if (m_recyclableHead.compare_exchange_weak(recycable_index_and_tag, index_and_tag))//CAS����
		#endif//USE_SAFE_CAS_LF_POOL_ALLOCATOR
			//�yCAS����̓��e�z
			//    if(m_recyclableHead == recycable_index_and_tag)//�ė��p�v�[���̐擪�C���f�b�N�X�𑼂̃X���b�h�����������Ă��Ȃ����H
			//        m_recyclableHead = index_and_tag;//�ė��p�v�[���̐擪�C���f�b�N�X�����̃C���f�b�N�X�ɕύX�i��������������j
			//    else
			//        recycable_index_and_tag = m_recyclableHead;//�ė��p�v�[���̐擪�C���f�b�N�X���Ď擾
			{
				m_using[index].fetch_sub(1);//�C���f�b�N�X�𖢎g�p��Ԃɂ���
			//	m_usingCount.fetch_sub(1);//�g�p���̐������炷�i�f�o�b�O�p�j
			//	m_freeCount[index].fetch_add(1);//�t���[�񐔂��J�E���g�A�b�v�i�f�o�b�O�p�j
				return true;//�������������
			}
		}
		return false;//�_�~�[
	}
	
	//�|�C���^���C���f�b�N�X�ɕϊ�
	std::size_t ptrToIndex(void* p)
	{
		const std::size_t index = (reinterpret_cast<char*>(p) - reinterpret_cast<char*>(m_pool)) / VALUE_SIZE;
		if (index >= POOL_SIZE)//�͈͊O�̃C���f�b�N�X�Ȃ�I��
		{
			static const bool IS_INVALID_POINTER_OF_POOL = false;
			assert(IS_INVALID_POINTER_OF_POOL);
			return INVALID_INDEX;
		}
		if (m_using[index].load() == 0)//�C���f�b�N�X�����ɖ��g�p��ԂȂ�I��
		{
			static const bool IS_ALREADY_DELETE_POINTER = false;
			assert(IS_ALREADY_DELETE_POINTER);
			return INVALID_INDEX;
		}
		return index;
	}

public:
	//���������
	bool free(void* p)
	{
		const std::size_t index = ptrToIndex(p);//�|�C���^���C���f�b�N�X�ɕϊ�
		if (index == INVALID_INDEX)
			return false;
		return free(p, index);
	}

	//�������m�ۂƃR���X�g���N�^�Ăяo��
	template<typename...Tx>
	value_type* newObj(Tx... args)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(args...);
	}
	template<typename ObjType, typename...Tx>
	ObjType* newObj(Tx... args)
	{
		static_assert(sizeof(ObjType) <= VALUE_SIZE, "sizeof(ObjType) is too large.");
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)ObjType(args...);
	}
	value_type* newCopyObj(value_type& org)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(org);
	}
	value_type* newMoveObj(value_type&& org)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(std::move(org));
	}

	//����������ƃf�X�g���N�^�Ăяo��
	template<typename ObjType>
	bool deleteObj(ObjType* p)
	{
		const std::size_t index = ptrToIndex(p);//�|�C���^���C���f�b�N�X�ɕϊ�
		if (index == INVALID_INDEX)
			return false;
		p->~ObjType();//�f�X�g���N�^�Ăяo��
		//operator delete(p, p);
		return free(p, index);
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_pool_allocator -----\n");
	//	printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d, usingCount=%d\n", POOL_SIZE, VALUE_SIZE, m_vacantHead.load(), m_usingCount.load());
		printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d\n", POOL_SIZE, VALUE_SIZE, m_vacantHead.load());
		printf("Using:\n");
		for (int index = 0; index < POOL_SIZE; ++index)
		{
			if (m_using[index].load() != 0)
			{
				printf("[%d]", index);
				if (m_using[index].load() != 1)
					printf("(using=%d)", m_using[index].load());
			//	printf("(leak=%d)", static_cast<int>(m_allocCount[index].load() - m_freeCount[index].load()));
				print_node(*reinterpret_cast<const value_type*>(m_pool[index]));
				printf("\n");
			}
		//	else
		//	{
		//		if (m_allocCount[index].load() != m_freeCount[index].load())
		//			printf("[%d](leak=%d)\n", index, static_cast<int>(m_allocCount[index].load() - m_freeCount[index].load()));
		//	}
		}
		printf("Recycable pool:\n");
		std::size_t recycable_index_and_tag = m_recyclableHead;
		while (recycable_index_and_tag != INVALID_INDEX)
		{
			const std::size_t recycable_index = recycable_index_and_tag & 0x00ffffff;
			const std::size_t tag = recycable_index_and_tag >> 24;
			printf(" [%d(tag=%d)]", recycable_index, tag);
			recycable_t* recycable_pool = reinterpret_cast<recycable_t*>(m_pool[recycable_index]);
			recycable_index_and_tag = recycable_pool->m_next_index.load();
		}
		printf("\n");
		printf("----------\n");
	}

public:
	//�R���X�g���N�^
	lf_pool_allocator()
	{
		m_vacantHead.store(0);
		m_recyclableHead.store(INVALID_INDEX);
	//	m_usingCount.store(0);
		for (int i = 0; i < POOL_SIZE; ++i)
		{
			m_using[i].store(0);
		//	m_allocCount[i].store(0);
		//	m_freeCount[i].store(0);
		}
	}
	//�f�X�g���N�^
	~lf_pool_allocator()
	{}

private:
	//�t�B�[���h
	char m_pool[POOL_SIZE][VALUE_SIZE];//�v�[���o�b�t�@ ���擪�ɔz�u���ăN���X�̃A���C�����g�ƈ�v������
	std::atomic<std::size_t> m_vacantHead;//�󂫃v�[���̐擪�C���f�b�N�X
	std::atomic<std::size_t> m_recyclableHead;//�ė��p�v�[���̐擪�C���f�b�N�X
	std::atomic<unsigned char> m_tag;//ABA���΍��p�̃^�O
	std::atomic<char> m_using[POOL_SIZE];//�g�p���C���f�b�N�X�i��d������聕�ی��̔r������p�j  ��std::bitset�g�p�s��
//	std::atomic<std::size_t> m_usingCount;//�g�p���̐��i�f�o�b�O�p�j���K�{�̏��ł͂Ȃ�
//	std::atomic<std::size_t> m_allocCount[POOL_SIZE];//�A���P�[�g�񐔁i�f�o�b�O�p�j���K�{�̏��ł͂Ȃ�
//	std::atomic<std::size_t> m_freeCount[POOL_SIZE];//�t���[�񐔁i�f�o�b�O�p�j���K�{�̏��ł͂Ȃ�
#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR
	spin_lock m_lock;//CAS����ی�p�̃X�s�����b�N
#endif//USE_SAFE_CAS_LF_POOL_ALLOCATOR
};

//--------------------------------------------------------------------------------
//�ʏ�X�^�b�N�N���X
#ifdef USE_POOL_ALLOCATOR
template<class T, std::size_t POOL_SIZE>
#else//USE_POOL_ALLOCATOR
template<class T>
#endif//USE_POOL_ALLOCATOR
class stack
{
public:
	//�^
	typedef T value_type;//�l�^

	//�X�^�b�N�^
	struct stack_t
	{
		stack_t* m_next;//���̃m�[�h
		value_type m_value;//�l
		//�R���X�g���N�^ ���l�̎󂯓n���̓��[�u�R���X�g���N�^���g�p
		stack_t(value_type&& value) :
			m_value(std::move(value))
		{}
	};

public:
	//���\�b�h

	//�v�b�V��
	bool push(value_type&& value)
	{
	#ifdef USE_POOL_ALLOCATOR
		void* p = m_allocator.alloc();//�V�K�m�[�h�̃��������m��
	#else//USE_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(stack_t), 16);//�V�K�m�[�h�̃��������m��
	#endif//USE_POOL_ALLOCATOR
		if (!p)//�������m�ێ��s
			return false;//�v�b�V�����s
		stack_t* new_node = new(p)stack_t(std::move(value));//�V�K�m�[�h�̃R���X�g���N�^�Ăяo��
		std::lock_guard<normal_lock> lock(m_lock);//���b�N�i�X�R�[�v���b�N�j
		new_node->m_next = m_head;//�V�K�m�[�h�̎��m�[�h�Ɍ��݂̐擪�m�[�h���Z�b�g
		m_head = new_node;//�擪�m�[�h��V�K�m�[�h�ɂ���
		return true;//�v�b�V������
	}
	bool push(value_type& value)
	{
		return push(std::move(value));//��Ƀ��[�u������K�p
	}

	//�|�b�v
	bool pop(value_type& value)
	{
		std::lock_guard<normal_lock> lock(m_lock);//���b�N�i�X�R�[�v���b�N�j
		stack_t* head = m_head;//�擪�m�[�h���擾
		if (head)//�擪�m�[�h�����݂��Ă����ꍇ
		{
			m_head = head->m_next;//�擪�m�[�h�����m�[�h�ɕύX
			value = std::move(head->m_value);//�l���擾
		#ifdef USE_POOL_ALLOCATOR
			m_allocator.deleteObj(head);//�擪�m�[�h���폜
		#else//USE_POOL_ALLOCATOR
			delete head;//�擪�m�[�h���폜
		#endif//USE_POOL_ALLOCATOR
			return true;//�|�b�v����
		}
		return false;//�|�b�v���s
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for stack -----\n");
		printf("Stack:\n");
		int no = 0;
		stack_t* node = m_head;
		while (node)
		{
			printf("[%d](%p) ", no++, node);
			print_node(node->m_value);
			printf("\n");
			node = node->m_next;
		}
		printf("----------\n");
	#ifdef USE_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](const stack_t& info)
		{
			print_node(info.m_value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_POOL_ALLOCATOR
	}

private:
	//������
	void initialize()
	{
		m_head = nullptr;//�擪�m�[�h�̏����l��nullptr
	}
	//�I��
	void finalize()
	{
		//��ɂȂ�܂Ń|�b�v
		value_type value;
		while (pop(value));
	}

public:
	//�R���X�g���N�^
	stack()
	{
		initialize();
	}
	//�f�X�g���N�^
	~stack()
	{
		finalize();
	}
private:
	//�t�B�[���h
#ifdef USE_POOL_ALLOCATOR
	pool_allocator<stack_t, POOL_SIZE> m_allocator;//�v�[���A���P�[�^
#endif//USE_POOL_ALLOCATOR
	stack_t* m_head;//�X�^�b�N�̐擪
	normal_lock m_lock;//���b�N�I�u�W�F�N�g�i�~���[�e�b�N�Xor�X�s�����b�N�j
};

//--------------------------------------------------------------------------------
//���b�N�t���[�X�^�b�N�N���X
//��ABA���΍􂠂�i�^�O�t���|�C���^�^�g�p�j
#ifdef USE_LF_POOL_ALLOCATOR
template<class T, std::size_t POOL_SIZE>
#else//USE_LF_POOL_ALLOCATOR
template<class T>
#endif//USE_LF_POOL_ALLOCATOR
class lf_stack
{
public:
	//�^
	typedef T value_type;//�l�^

	//�X�^�b�N�^�p�^�O�t���|�C���^�^
	struct stack_t;
	typedef tag_ptr<stack_t> stack_ptr_t;
	
	//�X�^�b�N�^
	struct stack_t
	{
		std::atomic<stack_ptr_t> m_next;//���̃m�[�h
		value_type m_value;//�l
		//�R���X�g���N�^ ���l�̎󂯓n���̓��[�u�R���X�g���N�^���g�p
		stack_t(value_type&& value) :
			m_value(std::move(value))
		{}
	};

public:
	//���\�b�h

	//�v�b�V��
	bool push(value_type&& value)
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		void* p = m_allocator.alloc();//�V�K�m�[�h�̃��������m��
	#else//USE_LF_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(stack_t), 16);//�V�K�m�[�h�̃��������m��
	#endif//USE_LF_POOL_ALLOCATOR
		if (!p)//�������m�ێ��s
			return nullptr;//�v�b�V�����s
		stack_t* new_node = new(p)stack_t(std::move(value));//�V�K�m�[�h�̃R���X�g���N�^�Ăяo��
		new_node->m_next.store(m_head.load());//�V�K�m�[�h�̎��m�[�h�Ɍ��݂̐擪�m�[�h���Z�b�g
		stack_ptr_t new_node_tag_ptr;
		new_node_tag_ptr.setTagPtr(new_node, m_tag.fetch_add(1));//�^�O�t���|�C���^����
		while (true)
		{
			stack_ptr_t next_tag_ptr = new_node->m_next.load();//�V�K�m�[�h�̎��m�[�h���擾

			//CAS����@
		#ifdef USE_SAFE_CAS_LF_STACK//�y���S�΍�z���X�s�����b�N��CAS�����ی�
			m_lock.lock();//���b�N�擾
			const bool result = m_head.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr);//CAS����
			m_lock.unlock();//���b�N����
			if (result)
		#else//USE_SAFE_CAS_LF_STACK
			if (m_head.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr))//CAS����
		#endif//USE_SAFE_CAS_LF_STACK
			//�yCAS����̓��e�z
			//    if(m_head == next_tag_ptr)//�擪�m�[�h���V�K�m�[�h�̎��m�[�h���H
			//        m_head = new_node_tag_ptr;//�擪�m�[�h��V�K�m�[�h���^�O�ɒu�������Ċ����i�v�b�V�������j
			//    else
			//        next_tag_ptr = m_head;//�V�K�m�[�h�̎��m�[�h�����݂̐擪�m�[�h�ɂ���
			{
				return true;//�v�b�V������
			}
				
			new_node->m_next.store(next_tag_ptr);//�擪�m�[�h���Ď擾
		}
		return false;//�_�~�[
	}
	bool push(value_type& value)
	{
		return push(std::move(value));//��Ƀ��[�u������K�p
	}

	//�|�b�v
	bool pop(value_type& value)
	{
		stack_ptr_t head_tag_ptr = m_head.load();//�擪�m�[�h���擾
		while (head_tag_ptr.isNotNull())
		{
			stack_t* head = head_tag_ptr;//�^�O�t���|�C���^����|�C���^���擾
			stack_ptr_t next_tag_ptr = head->m_next;//���̃m�[�h���擾

			//CAS����A
		#ifdef USE_SAFE_CAS_LF_STACK//�y���S�΍�z���X�s�����b�N��CAS�����ی�
			m_lock.lock();//���b�N�擾
			const bool result = m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr);//CAS����
			m_lock.unlock();//���b�N����
			if (result)
		#else//USE_SAFE_CAS_LF_STACK
			if (m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr))//CAS����
		#endif//USE_SAFE_CAS_LF_STACK
			//�yCAS����̓��e�z
			//    if(m_head == head_tag_ptr)//�擪�m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
			//        m_head = next_tag_ptr;//�擪�m�[�h��擪�m�[�h�̎��m�[�h�ɒu�������Ċ����i�|�b�v�����j
			//    else
			//        head_tag_ptr = m_head;//�擪�m�[�h���Ď擾
			{
				value = std::move(head->m_value);//�l���擾
			#ifdef USE_LF_POOL_ALLOCATOR
				m_allocator.deleteObj(head);//�擪�m�[�h���폜
			#else//USE_LF_POOL_ALLOCATOR
				head->~stack_t();
				//operator delete(head, head);
				_aligned_free(head);//�擪�m�[�h���폜
			#endif//USE_LF_POOL_ALLOCATOR
				return true;//�|�b�v����
			}
		}
		return false;//�|�b�v���s
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_stack -----\n");
		printf("Stack:\n");
		int no = 0;
		stack_ptr_t node_tag_ptr = m_head.load();
		while (node_tag_ptr.isNotNull())
		{
			const stack_t* node = node_tag_ptr;
			printf("[%d(tag=%d)](%p) ", no++, node, node_tag_ptr.tag(), node);
			print_node(node->m_value);
			printf("\n");
			node_tag_ptr = node->m_next;
		}
		printf("----------\n");
	#ifdef USE_LF_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](const stack_t& info)
		{
			print_node(info.m_value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_LF_POOL_ALLOCATOR
	}

private:
	//������
	void initialize()
	{
		stack_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//�^�O�t���k���|�C���^
		m_head.store(null_tag_ptr);//�擪�m�[�h�̏����l��null
		m_tag.store(0);//�^�O��������
		//if (m_head.is_lock_free())
		//	printf("m_head is lock free!\n");
	}
	//�I��
	void finalize()
	{
		//��ɂȂ�܂Ń|�b�v
		value_type value;
		while (pop(value));
	}

public:
	//�R���X�g���N�^
	lf_stack()
	{
		initialize();
	}
	//�f�X�g���N�^
	~lf_stack()
	{
		finalize();
	}
private:
	//�t�B�[���h
#ifdef USE_LF_POOL_ALLOCATOR
	lf_pool_allocator<stack_t, POOL_SIZE> m_allocator;//�v�[���A���P�[�^
#endif//USE_LF_POOL_ALLOCATOR
	std::atomic<stack_ptr_t> m_head;//�X�^�b�N�̐擪�@���^�O�t���|�C���^
	std::atomic<std::size_t> m_tag;//ABA���΍��p�̃^�O
#ifdef USE_SAFE_CAS_LF_STACK
	spin_lock m_lock;//CAS����ی�p�̃X�s�����b�N
#endif//USE_SAFE_CAS_LF_STACK
};

//--------------------------------------------------------------------------------
//�ʏ�L���[�N���X
#ifdef USE_POOL_ALLOCATOR
template<class T, std::size_t POOL_SIZE>
#else//USE_POOL_ALLOCATOR
template<class T>
#endif//USE_POOL_ALLOCATOR
class queue
{
public:
	//�^
	typedef T value_type;//�l�^

	//�L���[�^
	struct queue_t
	{
		queue_t* m_next;//���̃m�[�h
		value_type m_value;//�l
		//�R���X�g���N�^ ���l�̎󂯓n���̓��[�u�R���X�g���N�^���g�p
		queue_t(value_type&& value) :
			m_value(std::move(value))
		{}
		//�f�t�H���g�R���X�g���N�^�i�_�~�[�����p�j
		queue_t()
		{}
	};

public:
	//���\�b�h

	//�G���L���[
	bool enqueue(value_type&& value)
	{
	#ifdef USE_POOL_ALLOCATOR
		void* p = m_allocator.alloc();//�V�K�m�[�h�̃��������m��
	#else//USE_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(queue_t), 16);//�V�K�m�[�h�̃��������m��
	#endif//USE_POOL_ALLOCATOR
		if (!p)//�������m�ێ��s
			return false;//�G���L���[���s
		queue_t* new_node = new(p)queue_t(std::move(value));//�V�K�m�[�h�̃R���X�g���N�^�Ăяo��
		new_node->m_next = nullptr;//�V�K�m�[�h�̎��m�[�h��������
		std::lock_guard<normal_lock> lock(m_lock);//���b�N�i�X�R�[�v���b�N�j
		m_tail->m_next = new_node;//�����m�[�h�̎��m�[�h��V�K�m�[�h�ɂ���
		m_tail = new_node;//�����m�[�h��V�K�m�[�h�ɂ���
		return true;//�G���L���[����
	}
	bool enqueue(value_type& value)
	{
		return enqueue(std::move(value));//��Ƀ��[�u������K�p
	}

	//�f�L���[
	bool dequeue(value_type& value)
	{
		std::lock_guard<normal_lock> lock(m_lock);//���b�N�i�X�R�[�v���b�N�j
		if (m_head != m_tail)
		{
			queue_t* top = m_head->m_next;//���m�[�h�i�L���ȃL���[�̐擪�j���擾
		#ifdef USE_POOL_ALLOCATOR
			m_allocator.deleteObj(m_head);//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
		#else//USE_POOL_ALLOCATOR
			delete m_head;//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
		#endif//USE_POOL_ALLOCATOR
			m_head = top;//�擪�m�[�h�����m�[�h�ɕύX�i�����莟�m�[�h���_�~�[�m�[�h�����ɂȂ�j
			value = std::move(top->m_value);//�l���擾
			return true;//�f�L���[����
		}
		return false;//�f�L���[���s
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for queue -----\n");
		printf("Queue:\n");
		int no = 0;
		const queue_t* node = m_head;
		while (node)
		{
			printf("[%d](%p) ", no++, node);
			print_node(node->m_value);
			printf("\n");
			node = node->m_next;
		}
		printf("[tail](%p)", m_tail);
		print_node(m_tail->m_value);
		printf("\n");
		printf("----------\n");
	#ifdef USE_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](const queue_t& info)
		{
			print_node(info.m_value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_POOL_ALLOCATOR
	}

private:
	//������
	void initialize()
	{
	#ifdef USE_POOL_ALLOCATOR
		queue_t* dummy_node = m_allocator.newObj();//�_�~�[�m�[�h�𐶐�
	#else//USE_POOL_ALLOCATOR
		queue_t* dummy_node = new queue_t;//�_�~�[�m�[�h�𐶐�
	#endif//USE_POOL_ALLOCATOR
		dummy_node->m_next = nullptr;//�_�~�[�m�[�h�̎��m�[�h��������
		m_head = dummy_node;//�擪�m�[�h�Ƀ_�~�[�m�[�h���Z�b�g
		m_tail = dummy_node;//�����m�[�h�Ƀ_�~�[�m�[�h���Z�b�g
	}
	//�I��
	void finalize()
	{
		//��ɂȂ�܂Ńf�L���[
		value_type value;
		while (dequeue(value));
		//�_�~�[�m�[�h���폜
	#ifdef USE_POOL_ALLOCATOR
		m_allocator.deleteObj(m_head);
	#else//USE_POOL_ALLOCATOR
		delete m_head;
	#endif//USE_POOL_ALLOCATOR
	}

public:
	//�R���X�g���N�^
	queue()
	{
		initialize();
	}
	//�f�X�g���N�^
	~queue()
	{
		finalize();
	}
private:
	//�t�B�[���h
#ifdef USE_POOL_ALLOCATOR
	pool_allocator<queue_t, POOL_SIZE> m_allocator;//�v�[���A���P�[�^
#endif//USE_POOL_ALLOCATOR
	queue_t* m_head;//�L���[�̐擪
	queue_t* m_tail;//�L���[�̖���
	normal_lock m_lock;//���b�N�I�u�W�F�N�g�i�~���[�e�b�N�Xor�X�s�����b�N�j
};

//--------------------------------------------------------------------------------
//���b�N�t���[�L���[�N���X
//���_���Ɋ�Â��Ă��Ď���: http://www.cs.rochester.edu/u/scott/papers/1996_PODC_queues.pdf
//�@�ꕔ�_���ʂ�̎����ƈقȂ�
//    �� �ύX�_�@�Fenqueu:E9:  if CAS(&tail.ptr->next, next, <node, ...>)
//                                     ��
//                             if CAS(&Q->Tail.ptr->next, next, <node, ...>)
//       �ύX�_�A�Fenqueu:E7:  if tail == Q->Tail
//                        E15: endif
//                               ��
//                              �폜
//       �ύX�_�B�Fdequeu:D5:  if head == Q->Head
//                        D17: endif
//                               ��
//                              �폜
//       �ύX�_�C�F�|�C���^�ւ̃^�O�t���͐V�K�m�[�h�������̂ݓK�p
//                 ��32bit�^�O�{32bit�|�C���^�ɂ��64bit�̃^�O�t���|�C���^�Ƃ��邱�ƂŁA
//                   �^�O�����񂵂ċ�������댯�����قƂ�ǂȂ���Ԃ�
//��ABA���΍􂠂�i�^�O�t���|�C���^�^�g�p�j
#ifdef USE_LF_POOL_ALLOCATOR
template<class T, std::size_t POOL_SIZE>
#else//USE_LF_POOL_ALLOCATOR
template<class T>
#endif//USE_LF_POOL_ALLOCATOR
class lf_queue
{
public:
	//�^
	typedef T value_type;//�l�^

	//�L���[�^�p�^�O�t���|�C���^�^
	struct queue_t;
	typedef tag_ptr<queue_t> queue_ptr_t;

	//�L���[�^
	struct queue_t
	{
		std::atomic<queue_ptr_t> m_next;//���̃m�[�h
		value_type m_value;//�l
		//�R���X�g���N�^ ���l�̎󂯓n���̓��[�u�R���X�g���N�^���g�p
		queue_t(value_type&& value) :
			m_value(std::move(value))
		{}
		//�f�t�H���g�R���X�g���N�^�i�_�~�[�����p�j
		queue_t()
		{}
	};

public:
	//���\�b�h
	
	//�G���L���[
	bool enqueue(value_type&& value)
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		void* p = m_allocator.alloc();//�V�K�m�[�h�̃��������m��
	#else//USE_LF_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(queue_t), 16);//�V�K�m�[�h�̃��������m��
	#endif//USE_LF_POOL_ALLOCATOR
		if (!p)//�������m�ێ��s
			return false;//�G���L���[���s
		queue_t* new_node = new(p)queue_t(std::move(value));//�V�K�m�[�h�̃R���X�g���N�^�Ăяo��
		queue_ptr_t new_node_tag_ptr;
		new_node_tag_ptr.setTagPtr(new_node, m_tag.fetch_add(1));//�^�O�t���|�C���^����
		queue_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//�^�O�t���k���|�C���^
		new_node->m_next.store(null_tag_ptr);//�V�K�m�[�h�̎��m�[�h��������
		queue_ptr_t tail_tag_ptr = null_tag_ptr;
		while (true)
		{
			tail_tag_ptr = m_tail.load();//�����m�[�h���擾
			queue_t* tail = tail_tag_ptr;
			queue_ptr_t next_tag_ptr = tail->m_next.load();//�����m�[�h�̎��m�[�h���擾
			//if (tail_tag_ptr == m_tail.load())//���̃^�C�~���O�ő��̃X���b�h�����������������Ă��Ȃ����H�@���폜�iE7,E15�j
			{
				if (next_tag_ptr.isNull())//�����m�[�h�̎��m�[�h�����[�inullptr�j���H
				{
					//CAS����@
				#ifdef USE_SAFE_CAS_LF_QUEUE//�y���S�΍�z���X�s�����b�N��CAS�����ی�@���ύX�iE9�j
					m_lock.lock();//���b�N�擾
					const bool result = m_tail.load().ptr()->m_next.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr);//CAS����
					m_lock.unlock();//���b�N����
					if (result)
				#else//USE_SAFE_CAS_LF_QUEUE
					if (m_tail.load().ptr()->m_next.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr))//CAS����
				#endif//USE_SAFE_CAS_LF_QUEUE
					//�yCAS����̓��e�z
					//    if(tail_tag_ptr->m_next == next_tag_ptr)//�����m�[�h�̎��m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
					//        tail_tag_ptr->m_next = new_node_tag_ptr;//�����m�[�h�̎��m�[�h�ɐV�K�m�[�h���Z�b�g�i�G���L���[�����j
					{
						//CAS����A
					#ifdef USE_SAFE_CAS_LF_QUEUE//�y���S�΍�z���X�s�����b�N��CAS�����ی�
						m_lock.lock();//���b�N�擾
						m_tail.compare_exchange_strong(tail_tag_ptr, new_node_tag_ptr);//CAS����
						m_lock.unlock();//���b�N����
					#else//USE_SAFE_CAS_LF_QUEUE
						m_tail.compare_exchange_strong(tail_tag_ptr, new_node_tag_ptr);//CAS����
					#endif//USE_SAFE_CAS_LF_QUEUE
						//�yCAS����̓��e�z
						//    if(m_tail == tail_tag_ptr)//�����m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
						//        tail_tag_ptr = new_node_tag_ptr;//�����m�[�h��V�K�m�[�h�ɕύX

						return true;//�G���L���[����
					}
				}
				else//if(next_tag_ptr.isNotNull())//�����m�[�h�̎��m�[�h�����[�ł͂Ȃ��i���̃X���b�h�̏��������荞��ł����ꍇ�j
				{
					//CAS����B�F���܍��킹���� ��CAS����A�����s����\�������邽�߁A���̏������K�v
				#ifdef USE_SAFE_CAS_LF_QUEUE//�y���S�΍�z���X�s�����b�N��CAS�����ی�
					m_lock.lock();//���b�N�擾
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS����
					m_lock.unlock();//���b�N����
				#else//USE_SAFE_CAS_LF_QUEUE
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS����
				#endif//USE_SAFE_CAS_LF_QUEUE
					//�yCAS����̓��e�z
					//    if(m_tail == tail_tag_ptr)//�����m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
					//        m_tail = next_tag_ptr;//�����m�[�h�����m�[�h�ɕύX
				}
			}
		}
		return false;//�_�~�[
	}
	bool enqueue(value_type& value)
	{
		return enqueue(std::move(value));//��Ƀ��[�u������K�p
	}

	//�f�L���[
	bool dequeue(value_type& value)
	{
		queue_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//�^�O�t���k���|�C���^
		queue_ptr_t head_tag_ptr = null_tag_ptr;
		queue_ptr_t tail_tag_ptr = null_tag_ptr;
		queue_ptr_t top_tag_ptr = null_tag_ptr;
		while (true)
		{
			head_tag_ptr = m_head.load();//�擪�m�[�h���擾
			tail_tag_ptr = m_tail.load();//�����m�[�h���擾
			queue_t* head = head_tag_ptr;
			queue_ptr_t next_tag_ptr = head->m_next.load();//�擪�m�[�h�̎��m�[�h�i�L���ȃL���[�̐擪�j���擾
			//if (head_tag_ptr == m_head.load())//���̃^�C�~���O�ő��̃X���b�h���擪�����������Ă��Ȃ����H�@���폜�iD5,D17�j
			{
				if (head_tag_ptr == tail_tag_ptr)//�擪�m�[�h�Ɩ����m�[�h���������H�i����L���[�C���O����Ă��Ȃ���Ԃ��H�j
				{
					if (next_tag_ptr.isNull())//�{���ɃL���[���Ȃ����H�itail�擾��next�擾�̊ԂɁA���̃X���b�h���L���[�C���O���Ă���\��������j
						return false;//�f�L���[���s
					
					//CAS����C�F���܍��킹���� ���G���L���[��CAS����A�����s����\�������邽�߁A���̏������K�v
				#ifdef USE_SAFE_CAS_LF_QUEUE//�y���S�΍�z���X�s�����b�N��CAS�����ی�
					m_lock.lock();//���b�N�擾
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS����
					m_lock.unlock();//���b�N����
				#else//USE_SAFE_CAS_LF_QUEUE
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS����
				#endif//USE_SAFE_CAS_LF_QUEUE
					//�yCAS����̓��e�z
					//    if(m_tail == tail_tag_ptr)//�����m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
					//        m_tail = next_tag_ptr;//�����m�[�h�����m�[�h�ɕύX
				}
				else
				{
					//CAS����D
				#ifdef USE_SAFE_CAS_LF_QUEUE//�y���S�΍�z���X�s�����b�N��CAS�����ی�
					m_lock.lock();//���b�N�擾
					const bool result = m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr);//CAS����
					m_lock.unlock();//���b�N����
					if (result)
				#else//USE_SAFE_CAS_LF_QUEUE
					if (m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr))//CAS����
				#endif//USE_SAFE_CAS_LF_QUEUE
					//�yCAS����̓��e�z
					//    if(m_head == head_tag_ptr)//�擪�m�[�h�̎��m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
					//        m_head = next_tag_ptr;//�擪�m�[�h�����m�[�h�ɕύX�i�����莟�m�[�h���_�~�[�m�[�h�����ɂȂ�j�i�f�L���[�����j
					{
						queue_t* top = next_tag_ptr;//�V�����擪�m�[�h����l�����o��
						value = std::move(top->m_value);//�l���擾
					#ifdef USE_LF_POOL_ALLOCATOR
						m_allocator.deleteObj(head);//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
					#else//USE_LF_POOL_ALLOCATOR
						head->~queue_t();
						//operator delete(head, head);
						_aligned_free(head);//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
					#endif//USE_LF_POOL_ALLOCATOR
						return true;//�f�L���[����
					}
				}
			}
		}
		return false;//�_�~�[
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_queue -----\n");
		printf("Queue:\n");
		int no = 0;
		queue_ptr_t node_tag_ptr = m_head;
		while (node_tag_ptr.isNotNull())
		{
			queue_t* node = node_tag_ptr;
			printf("[%d(tag=%d)](%p) ", no++, node_tag_ptr.tag(), node);
			print_node(node->m_value);
			printf("\n");
			node_tag_ptr = node->m_next.load();
		}
		queue_ptr_t tail_tag_ptr = m_tail.load();
		queue_t* tail = tail_tag_ptr;
		printf("[tail(tag=%d)](%p)", tail_tag_ptr.tag(), tail);
		print_node(tail->m_value);
		printf("\n");
		printf("----------\n");
	#ifdef USE_LF_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](const queue_t& info)
		{
			print_node(info.m_value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_LF_POOL_ALLOCATOR
	}

private:
	//������
	void initialize()
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		queue_t* dummy_node = m_allocator.newObj();//�_�~�[�m�[�h�𐶐�
	#else//USE_LF_POOL_ALLOCATOR
		queue_t* dummy_node = new(_aligned_malloc(sizeof(queue_t), 16)) queue_t();//�_�~�[�m�[�h�𐶐�
	#endif//USE_LF_POOL_ALLOCATOR
		queue_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//�^�O�t���k���|�C���^
		dummy_node->m_next.store(null_tag_ptr);//�_�~�[�m�[�h�̎��m�[�h��������
		queue_ptr_t dummy_node_tag_ptr;
		dummy_node_tag_ptr.setTagPtr(dummy_node, 0);
		m_head.store(dummy_node_tag_ptr);//�擪�m�[�h�Ƀ_�~�[�m�[�h���Z�b�g
		m_tail.store(dummy_node_tag_ptr);//�����m�[�h�Ƀ_�~�[�m�[�h���Z�b�g
		m_tag.store(0);//�^�O��������
		//if (dummy_node->m_next.is_lock_free())
		//	printf("dummy_node->m_next is lock free!\n");
		//if (m_head.is_lock_free())
		//	printf("m_head is lock free!\n");
		//if (m_tail.is_lock_free())
		//	printf("m_tail is lock free!\n");
	}
	//�I��
	void finalize()
	{
		//��ɂȂ�܂Ńf�L���[
		value_type value;
		while (dequeue(value));
		//�_�~�[�m�[�h���폜
		queue_ptr_t head_tag_ptr = m_head.load();
		queue_t* head = head_tag_ptr;
	#ifdef USE_LF_POOL_ALLOCATOR
		m_allocator.deleteObj(head);
	#else//USE_LF_POOL_ALLOCATOR
		head->~queue_t();
		_aligned_free(head);//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
	#endif//USE_LF_POOL_ALLOCATOR
	}

public:
	//�R���X�g���N�^
	lf_queue()
	{
		initialize();
	}
	//�f�X�g���N�^
	~lf_queue()
	{
		finalize();
	}
private:
	//�t�B�[���h
#ifdef USE_LF_POOL_ALLOCATOR
	lf_pool_allocator<queue_t, POOL_SIZE> m_allocator;//�v�[���A���P�[�^
#endif//USE_LF_POOL_ALLOCATOR
	std::atomic<queue_ptr_t> m_head;//�L���[�̐擪
	std::atomic<queue_ptr_t> m_tail;//�L���[�̖���
	std::atomic<std::size_t> m_tag;//ABA���΍��p�̃^�O
#ifdef USE_SAFE_CAS_LF_QUEUE
	spin_lock m_lock;//CAS����ی�p�̃X�s�����b�N
#endif//USE_SAFE_CAS_LF_QUEUE
};

//--------------------------------------------------------------------------------
//�e�X�g�p�f�[�^
struct data_t
{
	int m_temp;
	int m_value;
};

//--------------------------------------------------------------------------------
//�ʏ�v�[���A���P�[�^�e�X�g

static pool_allocator<data_t, TEST_POOL_SIZE> s_poolAllocator;//�ʏ�v�[���A���P�[�^

//�ʏ�v�[���A���P�[�^����A���P�[�g
data_t* allocNormal()
{
	return s_poolAllocator.newObj();
}
//�ʏ�v�[���A���P�[�^����t���[
bool freeNormal(data_t* value)
{
	return s_poolAllocator.deleteObj(value);
}

//--------------------------------------------------------------------------------
//���b�N�t���[�v�[���A���P�[�^�e�X�g

static lf_pool_allocator<data_t, TEST_POOL_SIZE> s_lfPoolAllocator;//���b�N�t���[�v�[���A���P�[�^

//���b�N�t���[�v�[���A���P�[�^����A���P�[�g
data_t* allocLockFree()
{
	return s_lfPoolAllocator.newObj();
}
//���b�N�t���[�v�[���A���P�[�^����t���[
bool freeLockFree(data_t* value)
{
	return s_lfPoolAllocator.deleteObj(value);
}

//--------------------------------------------------------------------------------
//�ʏ�X�^�b�N�e�X�g

#ifdef USE_POOL_ALLOCATOR
static stack<data_t, TEST_POOL_SIZE> s_stack;//�ʏ�X�^�b�N
#else//USE_POOL_ALLOCATOR
static stack<data_t> s_stack;//�ʏ�X�^�b�N
#endif//USE_POOL_ALLOCATOR

//�ʏ�X�^�b�N�Ƀv�b�V��
bool pushNormal(data_t&& data)
{
	return s_stack.push(std::move(data));//�X�^�b�N�Ƀv�b�V��
}
bool pushNormal(data_t& data)
{
	return s_stack.push(data);//�X�^�b�N�Ƀv�b�V��
}

//�ʏ�X�^�b�N����|�b�v
bool popNormal(data_t& data)
{
	return s_stack.pop(data);//�X�^�b�N����|�b�v
}

//--------------------------------------------------------------------------------
//���b�N�t���[�X�^�b�N�e�X�g

#ifdef USE_LF_POOL_ALLOCATOR
static lf_stack<data_t, TEST_POOL_SIZE> s_lfStack;//���b�N�t���[�X�^�b�N
#else//USE_LF_POOL_ALLOCATOR
static lf_stack<data_t> s_lfStack;//���b�N�t���[�X�^�b�N
#endif//USE_LF_POOL_ALLOCATOR

//���b�N�t���[�X�^�b�N�Ƀv�b�V��
bool pushLockFree(data_t&& data)
{
	return s_lfStack.push(std::move(data));//�X�^�b�N�Ƀv�b�V��
}
bool pushLockFree(data_t& data)
{
	return s_lfStack.push(data);//�X�^�b�N�Ƀv�b�V��
}

//���b�N�t���[�X�^�b�N����|�b�v
bool popLockFree(data_t& data)
{
	return s_lfStack.pop(data);//�X�^�b�N����|�b�v
}

//--------------------------------------------------------------------------------
//�ʏ�L���[�e�X�g

#ifdef USE_POOL_ALLOCATOR
static queue<data_t, TEST_POOL_SIZE> s_queue;//�ʏ�L���[
#else//USE_POOL_ALLOCATOR
static queue<data_t> s_queue;//�ʏ�L���[
#endif//USE_POOL_ALLOCATOR

//�ʏ�L���[�ɃG���L���[
bool enqueueNormal(data_t&& value)
{
	return s_queue.enqueue(std::move(value));
}
bool enqueueNormal(data_t& value)
{
	return s_queue.enqueue(value);
}

//�ʏ�L���[����f�L���[
bool dequeueNormal(data_t& value)
{
	return s_queue.dequeue(value);
}

//--------------------------------------------------------------------------------
//���b�N�t���[�L���[�e�X�g

#ifdef USE_LF_POOL_ALLOCATOR
static lf_queue<data_t, TEST_POOL_SIZE> s_lfQueue;//���b�N�t���[�L���[
#else//USE_LF_POOL_ALLOCATOR
static lf_queue<data_t> s_lfQueue;//���b�N�t���[�L���[
#endif//USE_LF_POOL_ALLOCATOR

//���b�N�t���[�L���[�ɃG���L���[
bool enqueueLockFree(data_t&& value)
{
	return s_lfQueue.enqueue(std::move(value));
}
bool enqueueLockFree(data_t& value)
{
	return s_lfQueue.enqueue(value);
}

//���b�N�t���[�L���[����f�L���[
bool dequeueLockFree(data_t& value)
{
	return	s_lfQueue.dequeue(value);
}

//--------------------------------------------------------------------------------
//�e�X�g

#ifdef ENABLE_EASY_TEST
//�ȈՃe�X�g
void easyTest()
{
	printf("================================================================================\n");
	printf("[Test for Lock-free pool-allocator/stack/queue]\n");
	
	//�v�[���A���P�[�^�̃e�X�g�i���ʏ����j
	auto test_pool_allocator = [](const char* caption, std::function<data_t*()> alloc, std::function<bool(data_t*)> free)
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[%s:START]\n", caption);
		printf("*Test count                     = %d\n", TEST_COUNT);
		printf("*Allocate and free test threads = %d\n", 1);
		printf("*Memory pool size               = %d\n", TEST_POOL_SIZE);
		const auto begin_time = std::chrono::system_clock::now();
		pool_allocator<data_t, TEST_POOL_SIZE> allocator;
		data_t* data[TEST_POOL_SIZE + 1] = { 0 };
		int count = 0;
		while(true)
		{
			int num = 0;
			while (true)
			{
				data_t*& data_p = data[num++];
				data_p = alloc();
				if (!data_p)
					break;
				data_p->m_temp = 0;
				data_p->m_value = count++;
				if (count > TEST_COUNT)
					break;
			}
			for (int i = 0; i < num; ++i)
			{
				data_t* data_p = data[i];
				if (data_p)
					free(data_p);
			}
			if (count > TEST_COUNT)
				break;
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("[%s:END] elapsed_time=%.9llf sec\n", caption, elapsed_time);
		printf("--------------------------------------------------------------------------------\n");
	};

	//�X�^�b�N�^�L���[�̃e�X�g�i���ʏ����j
	auto test_stack_queue = [](const char* caption, std::function<bool(data_t&&)> push, std::function<bool(data_t&)> pop)
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[%s:START]\n", caption);
		printf("*Test count                = %d\n", TEST_COUNT);
		printf("*Push/Enqueue test threads = %d\n", 1);
		printf("*Pop/Dequeue  test threads = %d\n", 1);
		printf("*Memory pool size          = %d\n", TEST_POOL_SIZE);
		const auto begin_time = std::chrono::system_clock::now();
		int count = 0;
		while (true)
		{
			int num = 0;
			while (true)
			{
				const bool result = push({ count++ });
				if (!result)
				{
					--count;
					break;
				}
				if (count > TEST_COUNT)
					break;
			}
			while (true)
			{
				data_t data;
				const bool result = pop(data);
				if (!result)
					break;
			}
			if (count > TEST_COUNT)
				break;
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("[%s:END] elapsed_time=%.9llf sec\n", caption, elapsed_time);
		printf("--------------------------------------------------------------------------------\n");
	};

	//�f�o�b�O���\���p����
	auto debug_print_info = [](const data_t& data)
	{
		printf("temp=%d, value=%d", data.m_temp, data.m_value);
	};

#ifdef ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR
	//�ʏ�v�[���A���P�[�^�̃e�X�g
	{
		auto alloc = []() -> data_t*
		{
			return allocNormal();
		};
		auto free = [](data_t* data) -> bool
		{
			return freeNormal(data);
		};
		test_pool_allocator("Normal Pool-allocator", alloc, free);

#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_poolAllocator.printDebugInfo(debug_print_info);
#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR

#ifdef ENABLE_TEST_FOR_LF_POOL_ALLOCATOR
	//���b�N�t���[�v�[���A���P�[�^�̃e�X�g
	{
		auto alloc = []() -> data_t*
		{
			return allocLockFree();
		};
		auto free = [](data_t* data) -> bool
		{
			return freeLockFree(data);
		};
		test_pool_allocator("Lock-Free Pool-allocator", alloc, free);

#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfPoolAllocator.printDebugInfo(debug_print_info);
#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_POOL_ALLOCATOR

#ifdef ENABLE_TEST_FOR_NORMAL_STACK
	//�ʏ�X�^�b�N�̃e�X�g
	{
		auto push = [](data_t&& data) -> bool
		{
			return pushNormal(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return popNormal(data);
		};
		test_stack_queue("Normal Stack", push, pop);

#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_stack.printDebugInfo(debug_print_info);
#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_STACK

#ifdef ENABLE_TEST_FOR_LF_STACK
	//���b�N�t���[�X�^�b�N�̃e�X�g
	{
		auto push = [](data_t&& data) -> bool
		{
			return pushLockFree(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return popLockFree(data);
		};
		test_stack_queue("Lock-Free Stack", push, pop);

#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfStack.printDebugInfo(debug_print_info);
#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_STACK

#ifdef ENABLE_TEST_FOR_NORMAL_QUEUE
	//�ʏ�L���[�̃e�X�g
	{
		auto push = [](data_t&& data) -> bool
		{
			return enqueueNormal(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return dequeueNormal(data);
		};
		test_stack_queue("Normal Queue", push, pop);

#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_queue.printDebugInfo(debug_print_info);
#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_QUEUE

#ifdef ENABLE_TEST_FOR_LF_QUEUE
	//���b�N�t���[�L���[�̃e�X�g
	{
		auto push = [](data_t&& data) -> bool
		{
			return enqueueLockFree(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return dequeueLockFree(data);
		};
		test_stack_queue("Lock-Free Queue", push, pop);

#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfQueue.printDebugInfo(debug_print_info);
#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_QUEUE
}
#endif//ENABLE_EASY_TEST

#ifdef ENABLE_THREAD_TEST
//�X���b�h���g�����e�X�g
#include <thread>//C++11 std::thread
#include <condition_variable>//C++11 std::condition_variable
#include <chrono>//C++11 std::chrono
#include <functional>//C++11 std::function
void thread_test()
{
	printf("================================================================================\n");
	printf("[Test for Lock-free pool-allocator/stack/queue with threads]\n");

	//�v�[���A���P�[�^�̃e�X�g�i���ʏ����j
	auto test_pool_allocator = [](const char* caption, std::function<data_t*()> alloc, std::function<bool(data_t*)> free)
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[%s:START]\n", caption);
		printf("*Test count                     = %d\n", TEST_COUNT);
		printf("*Allocate and free test threads = %d\n", TEST_ALLOC_THREADS);
		printf("*Memory pool size               = %d\n", TEST_POOL_SIZE);

		std::condition_variable cond;
		std::mutex mutex;
		std::atomic<bool> is_ready;
		is_ready.store(false);
		auto isReady = [&is_ready]() -> bool
		{
			return is_ready.load();
		};
		std::atomic<int> wait_count;
		std::atomic<int> start_count;
		std::atomic<int> end_count;
		std::atomic<int> alloc_count;
		wait_count.store(0);
		start_count.store(0);
		end_count.store(0);
		alloc_count.store(0);
		auto threadAlloc = [&alloc, &free, &cond, &mutex, &isReady, &wait_count, &start_count, &end_count, &alloc_count](const int thread_no)
		{
			wait_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[Alloc:%2d]:Waiting...\n", thread_no);
		#endif//ENABLE_TEST_PRINT
			{
				std::unique_lock<std::mutex> lock(mutex);
				cond.wait(lock, isReady);
			}

			start_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[Alloc:%2d]:Start\n", thread_no);
		#endif//ENABLE_TEST_PRINT

			int loop_count = 0;
			int my_alloc_count = 0;
			while (true)
			{
				if (alloc_count.load() > TEST_COUNT)
					break;
				++loop_count;
				if (loop_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(0));
				data_t* obj = alloc();
				if (!obj)
					continue;
				const int count = alloc_count.fetch_add(1);
				std::this_thread::sleep_for(std::chrono::microseconds(0));
				free(obj);
				++my_alloc_count;
				if (my_alloc_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(1));
			#ifdef ENABLE_TEST_PRINT
				if (count % TEST_PRINT_STEP == 0)
					printf("[Alloc:%2d] alloc=%d\n", thread_no, count);
			#endif//ENABLE_TEST_PRINT
				//std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::microseconds(0));
			}

			end_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[Alloc:%2d]:End\n", thread_no);
		#endif//ENABLE_TEST_PRINT
		};
		std::thread* th[TEST_ALLOC_THREADS];
		int thread_count = 0;
		{
			std::lock_guard<std::mutex> lock(mutex);
			for (int i = 0; i < static_cast<int>(extentof(th)); ++i)
			{
				th[i] = new std::thread(threadAlloc, i);
				++thread_count;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		const auto begin_time = std::chrono::system_clock::now();
		{
			is_ready = true;
			while (true)
			{
				cond.notify_all();//������ƑS�X���b�h�ɒʒm�ł��Ȃ��ꍇ������̂Ń��g���C����
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				if (start_count.load() == thread_count)
					break;
			}
		}
		{
			for (int i = 0; i < static_cast<int>(extentof(th)); ++i)
			{
				th[i]->join();
				delete th[i];
				th[i] = nullptr;
			}
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("[%s:END] elapsed_time=%.9llf sec\n", caption, elapsed_time);
		printf("--------------------------------------------------------------------------------\n");
	};

	//�X�^�b�N�^�L���[�̃e�X�g�i���ʏ����j
	auto test_stack_queue = [](const char* caption, const char* push_name, const char* pop_name, std::function<bool(data_t&&)> push, std::function<bool(data_t&)> pop)
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[%s:START]\n", caption);
		printf("*Test count                = %d\n", TEST_COUNT);
		printf("*Push/Enqueue test threads = %d\n", TEST_PUSH_THREADS);
		printf("*Pop/Dequeue  test threads = %d\n", TEST_POP_THREADS);
		printf("*Memory pool size          = %d\n", TEST_POOL_SIZE);

		std::condition_variable cond;
		std::mutex mutex;
		std::atomic<bool> is_ready;
		is_ready.store(false);
		auto isReady = [&is_ready]() -> bool
		{
			return is_ready.load();
		};
		std::atomic<int> wait_count;
		std::atomic<int> start_count;
		std::atomic<int> end_count;
		std::atomic<int> push_count;
		std::atomic<int> pop_count;
		std::atomic<int> seq_no;
		wait_count.store(0);
		start_count.store(0);
		end_count.store(0);
		push_count.store(0);
		pop_count.store(0);
		seq_no.store(0);
		auto threadPush = [&push_name, &push, &cond, &mutex, &isReady, &wait_count, &start_count, &end_count, &push_count, &seq_no](const int thread_no)
		{
			wait_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:Waiting...\n", push_name, thread_no);
		#endif//ENABLE_TEST_PRINT
			{
				std::unique_lock<std::mutex> lock(mutex);
				cond.wait(lock, isReady);
			}
			
			start_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:Start\n", push_name, thread_no);
		#endif//ENABLE_TEST_PRINT

			int loop_count = 0;
			int my_push_count = 0;
			while (true)
			{
				if (push_count.load() > TEST_COUNT)
					break;
				++loop_count;
				if (loop_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(0));
				const int no = seq_no.fetch_add(1);
				if (no > TEST_COUNT)
				{
					seq_no.fetch_sub(1);
					continue;
				}
				const bool result = push({ 0, no });
				if (!result)
				{
					seq_no.fetch_sub(1);
					continue;
				}
				const int count = push_count.fetch_add(1);
				++my_push_count;
				if (my_push_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(1));
			#ifdef ENABLE_TEST_PRINT
				if (count % TEST_PRINT_STEP == 0)
					printf("[%s:%2d] count=%d\n", push_name, thread_no, count);
			#endif//ENABLE_TEST_PRINT
				//std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::microseconds(0));
			}
			
			end_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:End\n", push_name, thread_no);
		#endif//ENABLE_TEST_PRINT
		};
		auto threadPop = [&pop_name, &pop, &cond, &mutex, &isReady, &wait_count, &start_count, &end_count, &pop_count](const int thread_no)
		{
			wait_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:Waiting...\n", pop_name, thread_no);
		#endif//ENABLE_TEST_PRINT
			{
				std::unique_lock<std::mutex> lock(mutex);
				cond.wait(lock, isReady);
			}

			start_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:Start\n", pop_name, thread_no);
		#endif//ENABLE_TEST_PRINT

			while (pop_count.load() <= TEST_COUNT)
			{
				data_t data;
				if (pop(data))
				{
					const int count = pop_count.fetch_add(1);
				#ifdef ENABLE_TEST_PRINT
					if (TEST_PRINT_STEP > 0 && count % TEST_PRINT_STEP == 0)
						printf("[%s:%2d] count=%d\n", pop_name, thread_no, count);
				#endif//ENABLE_TEST_PRINT
				}
				//std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::microseconds(0));
			}

			end_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:End\n", pop_name, thread_no);
		#endif//ENABLE_TEST_PRINT
		};
		std::thread* th1[TEST_PUSH_THREADS];
		std::thread* th2[TEST_POP_THREADS];
		int thread_count = 0;
		{
			std::lock_guard<std::mutex> lock(mutex);
			for (int i = 0; i < static_cast<int>(extentof(th1)); ++i)
			{
				th1[i] = new std::thread(threadPush, i);
				++thread_count;
			}
			for (int i = 0; i < static_cast<int>(extentof(th2)); ++i)
			{
				th2[i] = new std::thread(threadPop, i);
				++thread_count;
			}
			std::this_thread::sleep_for(std::chrono::microseconds(1));
		}
		const auto begin_time = std::chrono::system_clock::now();
		{
			is_ready = true;
			while (true)
			{
				cond.notify_all();//������ƑS�X���b�h�ɒʒm�ł��Ȃ��ꍇ������̂Ń��g���C����
				std::this_thread::sleep_for(std::chrono::microseconds(1));
				if (start_count.load() == thread_count)
					break;
			}
		}
		{
			for (int i = 0; i < static_cast<int>(extentof(th1)); ++i)
			{
				th1[i]->join();
				delete th1[i];
				th1[i] = nullptr;
			}
			for (int i = 0; i < static_cast<int>(extentof(th2)); ++i)
			{
				th2[i]->join();
				delete th2[i];
				th2[i] = nullptr;
			}
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("[%s:END] elapsed_time=%.9llf sec\n", caption, elapsed_time);
		printf("--------------------------------------------------------------------------------\n");
	};
	
	//�f�o�b�O���\���p����
	auto debug_print_info = [](const data_t& data)
	{
		printf("temp=%d, value=%d", data.m_temp, data.m_value);
	};
	
#ifdef ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR
	//�ʏ�v�[���A���P�[�^�̃e�X�g
	{
		auto alloc = []() -> data_t*
		{
			return allocNormal();
		};
		auto free = [](data_t* data) -> bool
		{
			return freeNormal(data);
		};
		test_pool_allocator("Normal Pool-allocator", alloc, free);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_poolAllocator.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR

#ifdef ENABLE_TEST_FOR_LF_POOL_ALLOCATOR
	//���b�N�t���[�v�[���A���P�[�^�̃e�X�g
	{
		auto alloc = []() -> data_t*
		{
			return allocLockFree();
		};
		auto free = [](data_t* data) -> bool
		{
			return freeLockFree(data);
		};
		test_pool_allocator("Lock-Free Pool-allocator", alloc, free);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfPoolAllocator.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_POOL_ALLOCATOR

#ifdef ENABLE_TEST_FOR_NORMAL_STACK
	//�ʏ�X�^�b�N�̃e�X�g
	{
		auto push = [](data_t&& data) -> bool
		{
			return pushNormal(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return popNormal(data);
		};
		test_stack_queue("Normal Stack", "PUSH", "POP ", push, pop);
		
	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_stack.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_STACK

#ifdef ENABLE_TEST_FOR_LF_STACK
	//���b�N�t���[�X�^�b�N�̃e�X�g
	{
		auto push = [](data_t&& data) -> bool
		{
			return pushLockFree(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return popLockFree(data);
		};
		test_stack_queue("Lock-Free Stack", "PUSH", "POP ", push, pop);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfStack.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_STACK

#ifdef ENABLE_TEST_FOR_NORMAL_QUEUE
	//�ʏ�L���[�̃e�X�g
	{
		auto push = [](data_t&& data) -> bool
		{
			return enqueueNormal(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return dequeueNormal(data);
		};
		test_stack_queue("Normal Queue", "ENQUEUE", "DEQUEUE", push, pop);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_queue.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_QUEUE

#ifdef ENABLE_TEST_FOR_LF_QUEUE
	//���b�N�t���[�L���[�̃e�X�g
	{
		auto push = [](data_t&& data) -> bool
		{
			return enqueueLockFree(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return dequeueLockFree(data);
		};
		test_stack_queue("Lock-Free Queue", "ENQUEUE", "DEQUEUE", push, pop);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfQueue.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_QUEUE
}
#endif//ENABLE_THREAD_TEST

//�e�X�g
int main(const int argc, const char* argv[])
{
#ifdef ENABLE_EASY_TEST
	//�ȈՃe�X�g
	easyTest();
#endif//ENABLE_EASY_TEST

#ifdef ENABLE_THREAD_TEST
	//�X���b�h���g�����e�X�g
	thread_test();
#endif//ENABLE_THREAD_TEST

	return EXIT_SUCCESS;
}

// End of file
