//--------------------------------------------------------------------------------
//�R���p�C���X�C�b�`

#define USE_POOL_ALLOCATOR//�X�^�b�N�^�L���[�̎����ŁA�v�[���A���P�[�^���g�p����ꍇ�͂��̃}�N����L��������
//#define USE_LF_POOL_ALLOCATOR//���b�N�t���[�X�^�b�N�^�L���[�̎����ŁA���b�N�t���[�v�[���A���P�[�^���g�p����ꍇ�͂��̃}�N����L��������

//#define USE_GCC//GCC�g�p���́A���̃}�N����L��������

//--------------------------------------------------------------------------------
//�e�X�g�p�R���p�C���X�C�b�`�^�萔

//#define ENABLE_EASY_TEST//�ȈՃe�X�g�����s����ꍇ�́A���̃}�N����L��������
#define ENABLE_THREAD_TEST//�X�e�b�h�e�X�g�����s����ꍇ�́A���̃}�N����L��������

//�X���b�h�e�X�g�p�萔
//#define ENABLE_TEST_PRINT//�X���b�h�e�X�g�̌o�߃��b�Z�[�W��\������ꍇ�́A���̃}�N����L��������
//#define TEST_1_TIME//1�񂾂��̃e�X�g�����s����ꍇ�́A���̃}�N����L��������
#ifdef TEST_1_TIME
static const int TEST_COUNT = 1;//�e�X�g��
static const int TEST_PRINT_COUNT = 0;//�e�X�g���̃��b�Z�[�W�\����
static const int TEST_PUSH_THREADS = 1;//�e�X�g�p�̃v�b�V���^�G���L���[�X���b�h��
static const int TEST_POP_THREADS = 1;//�e�X�g�p�̃|�b�v�^�f�L���[�X���b�h��
static const int TEST_ALLOC_THREADS = 1;//�e�X�g�p�̃A���P�[�g�X���b�h��
static const int TEST_POOL_SIZE = 20;//�e�X�g�p�v�[���A���P�[�^�̃v�[���T�C�Y
#else//TEST_1_TIME
#ifdef USE_GCC
static const int TEST_COUNT = 10000;//�e�X�g��
static const int TEST_PRINT_COUNT = 5;//�e�X�g���̃��b�Z�[�W�\����
static const int TEST_PUSH_THREADS = 10;//�e�X�g�p�̃v�b�V���^�G���L���[�X���b�h��
static const int TEST_POP_THREADS = 5;//�e�X�g�p�̃|�b�v�^�f�L���[�X���b�h��
static const int TEST_ALLOC_THREADS = 20;//�e�X�g�p�̃A���P�[�g�X���b�h��
static const int TEST_POOL_SIZE = 20;//�e�X�g�p�v�[���A���P�[�^�̃v�[���T�C�Y
#else//USE_GCC
static const int TEST_COUNT = 1000000;//�e�X�g��
static const int TEST_PRINT_COUNT = 5;//�e�X�g���̃��b�Z�[�W�\����
static const int TEST_PUSH_THREADS = 10;//�e�X�g�p�̃v�b�V���^�G���L���[�X���b�h��
static const int TEST_POP_THREADS = 5;//�e�X�g�p�̃|�b�v�^�f�L���[�X���b�h��
static const int TEST_ALLOC_THREADS = 100;//�e�X�g�p�̃A���P�[�g�X���b�h��
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
#include <bitset>//std::bitset

//--------------------------------------------------------------------------------
//�ʏ�X�^�b�N�^�L���[�p�C���N���[�h
#include <mutex>//C++11 std::mutex
//#include <stack>//std::stack
//#include <queue>//std::queue

//--------------------------------------------------------------------------------
//���b�N�t���[�X�^�b�N�^�L���[�p�C���N���[�h
#include <atomic>//C++11 std::atomic

//--------------------------------------------------------------------------------
//�ėp����

//�z��̗v�f����Ԃ�
template<typename T, std::size_t N>
inline std::size_t extentof(T(&val)[N]){return N; }

//--------------------------------------------------------------------------------
//�ʏ�v�[���A���P�[�^�N���X
#include <new>//new(void*)�p
template<class T, std::size_t POOL>
class alignas(16) pool_allocator
{
	static_assert(sizeof(T) >= 4, "sizeof(T) is too small.");

public:
	//�^
	typedef T value_type;//�l�^

public:
	//�萔
	static const std::size_t POOL_SIZE = POOL;//�v�[���T�C�Y
	static const std::size_t VALUE_SIZE = sizeof(value_type);//�l�̃T�C�Y
	static const std::size_t INVALID_INDEX = 0xffffffff;//�����ȃC���f�b�N�X
	static const std::size_t DIRTY_INDEX = 0xfefefefe;//�ė��p�A���C���f�b�N�X�폜�p

public:
	//���\�b�h

	//�������m��
	void* alloc()
	{
		std::lock_guard<std::mutex> lock(m_mutex);//�~���[�e�b�N�X�Ń��b�N
		//�V�K�v�[�����m��
		if (m_emptyHead < POOL_SIZE)//�󂫃o�b�t�@�̐擪�C���f�b�N�X���v�[���T�C�Y�����Ȃ炻�̂܂ܕԂ�
		{
			const std::size_t empty_index = m_emptyHead++;//�󂫃o�b�t�@�̃C���Ńb�N�X���擾���C���N�������g
			void* empty = m_buff[empty_index];//�󂫃o�b�t�@�擾
			*reinterpret_cast<std::size_t*>(empty) = DIRTY_INDEX;//�ė��p�A���C���f�b�N�X�폜
			m_using[empty_index] = true;//�C���f�b�N�X���g�p���ɂ���
			++m_usingCount;//�g�p���̐��𑝂₷
			return empty;//�������m�ې���
		}
		//�폜�ς݃C���f�b�N�X�������Ȃ烁�����m�ێ��s�i�󂫃v�[���������j
		if (m_deletedHead == INVALID_INDEX)
		{
			//static const bool NOT_ENOUGH_POOL_MEMORY = false;
			//assert(NOT_ENOUGH_POOL_MEMORY);
			return nullptr;//�������m�ێ��s
		}
		//�ė��p�v�[�����m��
		{
			const std::size_t recycle_index = m_deletedHead;//�擪�̍폜�ς݃C���f�b�N�X���ė��p�C���f�b�N�X�Ƃ��Ď擾
			void* recycle = m_buff[recycle_index];//�ė��p�o�b�t�@�擾
			m_deletedHead = *reinterpret_cast<std::size_t*>(recycle);//�擪�̍폜�ς݃C���f�b�N�X�����̃C���f�b�N�X�ɕύX
			*reinterpret_cast<std::size_t*>(recycle) = DIRTY_INDEX;//�ė��p�A���C���f�b�N�X�폜
			m_using[recycle_index] = true;//�C���f�b�N�X���g�p���ɂ���
			++m_usingCount;//�g�p���̐��𑝂₷
			return recycle;//�������m�ې���
		}
	}

private:
	//���������
	bool free(void* p, const std::size_t index)
	{
		*reinterpret_cast<std::size_t*>(m_buff[index]) = m_deletedHead;//���̍폜�ς݃C���f�b�N�X��ۑ�
		m_deletedHead = index;//�擪�̍폜�ς݃C���f�b�N�X��ύX
		m_using[index] = false;//�C���f�b�N�X�𖢎g�p��Ԃɂ���
		--m_usingCount;//�g�p���̐������炷
		return true;
	}
	
	//�|�C���^���C���f�b�N�X�ɕϊ�
	std::size_t ptrToIndex(void* p)
	{
		const std::size_t index = (reinterpret_cast<char*>(p) - reinterpret_cast<char*>(m_buff)) / VALUE_SIZE;
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
		std::lock_guard<std::mutex> lock(m_mutex);//�~���[�e�b�N�X�Ń��b�N
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
		static_assert(sizeof(ObjType) <= VALUE_SIZE, "sizeof(ObjType) is too big.");
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)ObjType(args...);
	}
	
	//����������ƃf�X�g���N�^�Ăяo��
	template<typename ObjType>
	bool deleteObj(ObjType* p)
	{
		std::lock_guard<std::mutex> lock(m_mutex);//�~���[�e�b�N�X�Ń��b�N
		const std::size_t index = ptrToIndex(p);//�|�C���^���C���f�b�N�X�ɕϊ�
		if (index == INVALID_INDEX)
			return false;
		p->~ObjType();//�f�X�g���N�^�Ăяo��
		return free(p, index);
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(value_type& value)> print_node)
	{
		printf("----- Debug Info for pool_allocator -----\n");
		printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d, usingCount=%d\n", POOL_SIZE, VALUE_SIZE, m_emptyHead, m_usingCount);
		printf("Using:\n");
		for (int index = 0; index < POOL_SIZE; ++index)
		{
			if (m_using[index])
			{
				printf("[%d] ", index);
				print_node(*reinterpret_cast<value_type*>(m_buff[index]));
				printf("\n");
			}
		}
		printf("Deleted(for Recycle):\n");
		std::size_t deleted_index = m_deletedHead;
		while (deleted_index != INVALID_INDEX)
		{
			printf(" [%d]", deleted_index);
			deleted_index = *reinterpret_cast<std::size_t*>(m_buff[deleted_index]);
		}
		printf("\n");
		printf("----------\n");
	}

public:
	//�R���X�g���N�^
	pool_allocator() :
		m_emptyHead(0),
		m_deletedHead(INVALID_INDEX)
	{}
	//�f�X�g���N�^
	~pool_allocator()
	{}

private:
	//�t�B�[���h
	char m_buff[POOL_SIZE][VALUE_SIZE];//�v�[���o�b�t�@ ���擪�ɔz�u���ăN���X�̃A���C�����g�ƈ�v������
	std::size_t m_emptyHead;//�󂫃o�b�t�@�̐擪�C���f�b�N�X
	std::size_t m_deletedHead;//�擪�̍폜�ς݃C���f�b�N�X�i�ė��p�p�j
	std::bitset<POOL_SIZE> m_using;//�g�p���C���f�b�N�X
	std::size_t m_usingCount;//�g�p���̐��i�f�o�b�O�p�j���K�{�̏��ł͂Ȃ�
	std::mutex m_mutex;//�~���[�e�b�N�X
};

//--------------------------------------------------------------------------------
//���b�N�t���[�v�[���A���P�[�^�N���X
//��ABA���΍􂠂�i�v�[���v�f���Ƃ̏��������J�E���g���A�d��������}����j
#include <new>//new(void*)�p
template<class T, std::size_t POOL>
class alignas(16) lf_pool_allocator
{
	static_assert(sizeof(T) >= 4, "sizeof(T) is too small.");

public:
	//�^
	typedef T value_type;//�l�^

public:
	//�萔
	static const std::size_t POOL_SIZE = POOL;//�v�[���T�C�Y
	static const std::size_t VALUE_SIZE = sizeof(value_type);//�l�̃T�C�Y
	static const std::size_t INVALID_INDEX = 0xffffffff;//�����ȃC���f�b�N�X
	static const std::size_t DIRTY_INDEX = 0xfefefefe;//�ė��p�A���C���f�b�N�X�폜�p

public:
	//���\�b�h
	
	//�������m��
	void* alloc()
	{
		//�V�K�v�[�����m��
		{
			const std::size_t empty_index = m_emptyHead.fetch_add(1);//�󂫃o�b�t�@�̐擪�C���f�b�N�X���擾���ăC���N�������g
			if (empty_index < POOL_SIZE)//�󂫃o�b�t�@�̐擪�C���f�b�N�X���v�[���T�C�Y�����Ȃ炻�̂܂ܕԂ�
			{
				m_using[empty_index].fetch_add(1);//�C���f�b�N�X���g�p����Ԃɂ���
				*reinterpret_cast<std::size_t*>(m_buff[empty_index]) = DIRTY_INDEX;//�ė��p�A���C���f�b�N�X�폜
				m_usingCount.fetch_add(1);//�g�p���̐��𑝂₷
				m_allocCount[empty_index].fetch_add(1);//�A���P�[�g�񐔂��J�E���g�A�b�v�i�f�o�b�O�p�j
				return m_buff[empty_index];//�������m�ې���
			}
		}
		//�ė��p�v�[�����m��
		{
			m_emptyHead.store(POOL_SIZE);//�󂫃o�b�t�@�̐擪�C���f�b�N�X���v�[���T�C�Y�ɂ���i�C���N�������g�ŃI�[�o�[���Ă��܂��Ă���̂Łj
			std::size_t recycle_index = m_deletedHead.load();//�擪�̍폜�ς݃C���f�b�N�X���ė��p�C���f�b�N�X�Ƃ��Ď擾
			int retry_count = 0;//���g���C��
			while (true)
			{
				++retry_count;
				if (retry_count == 1000)//��萔�̃��g���C���ƂɃ[���X���[�v
				{
					std::this_thread::sleep_for(std::chrono::nanoseconds(0));//�[���X���[�v�i�R���e�L�X�g�X�C�b�`�j
					recycle_index = m_deletedHead.load();//�ė��p�C���f�b�N�X���Ď擾
					retry_count = 0;
				}
				if (recycle_index == INVALID_INDEX)//�폜�ς݃C���f�b�N�X�������Ȃ烁�����m�ێ��s�i�󂫃v�[���������j
				{
					//static const bool NOT_ENOUGH_POOL_MEMORY = false;
					//assert(NOT_ENOUGH_POOL_MEMORY);
					return nullptr;//�������m�ێ��s
				}
				const std::size_t index_using = m_using[recycle_index].fetch_add(1);//�C���f�b�N�X���g�p����Ԃɂ���
				if (index_using != 0)//���̃X���b�h���C���f�b�N�X���������Ȃ烊�g���C
				{
					m_using[recycle_index].fetch_sub(1);//�C���f�b�N�X�̎g�p����Ԃ�߂�
					recycle_index = m_deletedHead.load();//�ė��p�C���f�b�N�X���Ď擾
					continue;//���g���C
				}
				void* recycle = m_buff[recycle_index];//�擪�̍폜�ς݃C���f�b�N�X�̃v�[�����ė��p
				const std::size_t next_index_and_tag = *reinterpret_cast<std::size_t*>(recycle);//�擪�̍폜�ς݃C���f�b�N�X�̎��̃C���f�b�N�X���擾
				std::size_t curr_recycle_index = recycle_index;//CAS���쎸�s�ɔ����čė��p�C���f�b�N�X���L��

				//CAS����
				if (m_deletedHead.compare_exchange_weak(recycle_index, next_index_and_tag))
				{
					*reinterpret_cast<std::size_t*>(m_buff[recycle_index]) = DIRTY_INDEX;//�ė��p�A���C���f�b�N�X�폜
					m_usingCount.fetch_add(1);//�g�p���̐��𑝂₷
					m_allocCount[recycle_index].fetch_add(1);//�A���P�[�g�񐔂��J�E���g�A�b�v�i�f�o�b�O�p�j
					return recycle;//�������m�ې���
				}
				//�y���̏����𕪉����������z
				//    if(m_deletedHead == recycle_index)//�擪�̍폜�ς݃C���f�b�N�X�𑼂̃X���b�h�����������Ă��Ȃ����H
				//    {
				//        m_deletedHead = next;//�擪�̍폜�ς݃C���f�b�N�X�����̃C���f�b�N�X�ɕύX
				//        //�������m�ې���
				//    }
				//    else
				//        recycle_index_and_tag = m_deletedHead;//�擪�̍폜�ς݃C���f�b�N�X���Ď擾
				
				m_using[curr_recycle_index].fetch_sub(1);//�C���f�b�N�X�̎g�p����Ԃ�߂��ă��g���C
			}
			return nullptr;//�_�~�[
		}
	}

private:
	//���������
	bool free(void* p, const std::size_t index)
	{
		std::size_t deleted_index_head = m_deletedHead.load();//�폜�ς݃C���f�b�N�X���擾
		while (true)
		{
			*reinterpret_cast<std::size_t*>(m_buff[index]) = deleted_index_head;//���̍폜�ς݃C���f�b�N�X��ۑ�
			
			//CAS����
			if (m_deletedHead.compare_exchange_weak(deleted_index_head, index))
			{
				m_using[index].fetch_sub(1);//�C���f�b�N�X�𖢎g�p��Ԃɂ���
				m_usingCount.fetch_sub(1);//�g�p���̐������炷
				m_freeCount[index].fetch_add(1);//�t���[�񐔂��J�E���g�A�b�v�i�f�o�b�O�p�j
				return true;//�������������
			}
			//�y���̏����𕪉����������z
			//    if(m_deletedHead == deleted_head_index_and_tag)//�擪�̍폜�ς݃C���f�b�N�X�𑼂̃X���b�h�����������Ă��Ȃ����H
			//    {
			//        m_deletedHead = index_and_tag;//�擪�̍폜�ς݃C���f�b�N�X�����̃C���f�b�N�X�ɕύX
			//        //�������������
			//    }
			//    else
			//        deleted_head_index_and_tag = m_deletedHead;//�폜�ς݃C���f�b�N�X���Ď擾
		}
		return false;//�_�~�[
	}
	
	//�|�C���^���C���f�b�N�X�ɕϊ�
	std::size_t ptrToIndex(void* p)
	{
		const std::size_t index = (reinterpret_cast<char*>(p) - reinterpret_cast<char*>(m_buff)) / VALUE_SIZE;
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
		static_assert(sizeof(ObjType) <= VALUE_SIZE, "sizeof(ObjType) is too big.");
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)ObjType(args...);
	}
	
	//����������ƃf�X�g���N�^�Ăяo��
	template<typename ObjType>
	bool deleteObj(ObjType* p)
	{
		const std::size_t index = ptrToIndex(p);//�|�C���^���C���f�b�N�X�ɕϊ�
		if (index == INVALID_INDEX)
			return false;
		p->~ObjType();//�f�X�g���N�^�Ăяo��
		return free(p, index);
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_pool_allocator -----\n");
		printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d, usingCount=%d\n", POOL_SIZE, VALUE_SIZE, m_emptyHead, m_usingCount);
		printf("Using:\n");
		for (int index = 0; index < POOL_SIZE; ++index)
		{
			if (m_using[index].load() != 0)
			{
				printf("[%d]", index);
				if (m_using[index].load() != 1)
					printf("(using=%d)", m_using[index].load());
				printf("(leak=%d)", static_cast<int>(m_allocCount[index].load() - m_freeCount[index].load()));
				print_node(*reinterpret_cast<value_type*>(m_buff[index]));
				printf("\n");
			}
			else
			{
				if (m_allocCount[index].load() != m_freeCount[index].load())
					printf("[%d](leak=%d)\n", index, static_cast<int>(m_allocCount[index].load() - m_freeCount[index].load()));
			}
		}
		printf("Deleted(for Recycle):\n");
		std::size_t deleted_index = m_deletedHead;
		while (deleted_index != INVALID_INDEX)
		{
			printf(" [%d]", deleted_index);
			deleted_index = *reinterpret_cast<std::size_t*>(m_buff[deleted_index]);
		}
		printf("\n");
		printf("----------\n");
	}

public:
	//�R���X�g���N�^
	lf_pool_allocator()
	{
		m_emptyHead.store(0);
		m_deletedHead.store(INVALID_INDEX);
	}
	//�f�X�g���N�^
	~lf_pool_allocator()
	{}

private:
	//�t�B�[���h
	char m_buff[POOL_SIZE][VALUE_SIZE];//�v�[���o�b�t�@ ���擪�ɔz�u���ăN���X�̃A���C�����g�ƈ�v������
	std::atomic<std::size_t> m_emptyHead;//�󂫃o�b�t�@�̐擪�C���f�b�N�X
	std::atomic<std::size_t> m_deletedHead;//�擪�̍폜�ς݃C���f�b�N�X�i�ė��p�p�j
	std::atomic<char> m_using[POOL_SIZE];//�g�p���C���f�b�N�X  ��std::bitset�͎g�p���Ȃ�
	std::atomic<std::size_t> m_usingCount;//�g�p���̐��i�f�o�b�O�p�j���K�{�̏��ł͂Ȃ�
	std::atomic<std::size_t> m_allocCount[POOL_SIZE];//�A���P�[�g�񐔁i�f�o�b�O�p�j���K�{�̏��ł͂Ȃ�
	std::atomic<std::size_t> m_freeCount[POOL_SIZE];//�t���[�񐔁i�f�o�b�O�p�j���K�{�̏��ł͂Ȃ�
};

//--------------------------------------------------------------------------------
//�ʏ�X�^�b�N�N���X
//�����b�N�t���[�X�^�b�N�Ƃ̍����m�F���邽�߂ɁAstd::stack�͎g�p���Ȃ��istd::stack�̓������ė��p�̌����������̂ŒP���Ȕ�r�ɂȂ�Ȃ��j
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
		stack_t* next;
		value_type value;
	};

public:
	//���\�b�h

	//�v�b�V��
	bool push(value_type value)
	{
	#ifdef USE_POOL_ALLOCATOR
		stack_t* new_node = m_allocator.newObj();//�V�K�m�[�h�𐶐�
	#else//USE_POOL_ALLOCATOR
		stack_t* new_node = new stack_t();//�V�K�m�[�h�𐶐�
	#endif//USE_POOL_ALLOCATOR
		if (!new_node)//�������m�ێ��s
			return false;//�v�b�V�����s
		new_node->value = value;//�V�K�m�[�h�ɒl���Z�b�g
		std::lock_guard<std::mutex> lock(m_mutex);//�~���[�e�b�N�X�Ń��b�N
		new_node->next = m_head;//�V�K�m�[�h�̎��m�[�h�Ɍ��݂̐擪�m�[�h���Z�b�g
		m_head = new_node;//�擪�m�[�h��V�K�m�[�h�ɂ���
		return true;//�v�b�V������
	}

	//�|�b�v
	bool pop(value_type& value)
	{
		std::lock_guard<std::mutex> lock(m_mutex);//�~���[�e�b�N�X�Ń��b�N
		stack_t* head = m_head;//�擪�m�[�h���擾
		if (head)//�擪�m�[�h�����݂��Ă����ꍇ
		{
			m_head = head->next;//�擪�m�[�h�����m�[�h�ɕύX
			value = head->value;//�l���擾
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
	void printDebugInfo(std::function<void(value_type& value)> print_node)
	{
		printf("----- Debug Info for stack -----\n");
		printf("Stack:\n");
		int no = 0;
		stack_t* node = m_head;
		while (node)
		{
			printf("[%d](%p) ", no++, node);
			print_node(node->value);
			printf("\n");
			node = node->next;
		}
		printf("----------\n");
	#ifdef USE_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](stack_t& info)
		{
			print_node(info.value);
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
	stack_t* m_head;//�X�^�b�N�̐擪
	std::mutex m_mutex;//�~���[�e�b�N�X
#ifdef USE_POOL_ALLOCATOR
	pool_allocator<stack_t, POOL_SIZE> m_allocator;//�v�[���A���P�[�^
#endif//USE_POOL_ALLOCATOR
};

//--------------------------------------------------------------------------------
//���b�N�t���[�X�^�b�N�N���X
//��ABA���΍􂠂�i4�r�b�g�̃^�O���g�p����ABA���̔�������1/16�ɂ���j
#include <cstdint>//uintptr_t�p
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

	//�X�^�b�N�^
	//���|�C���^�̉���4�r�b�g�Ƀ^�O��t����ABA���ɑ΂��邽�߂ɁA16�o�C�g�A���C�������g�ɂ���
	struct alignas(16) stack_t
	{
		stack_t* next;
		value_type value;
		stack_t(){ value.m_value = 123; }
	};

public:
	//���\�b�h

	//�v�b�V��
	bool push(value_type value)
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		stack_t* new_node = m_allocator.newObj();//�V�K�m�[�h�𐶐�
	#else//USE_LF_POOL_ALLOCATOR
		stack_t* new_node = new(_aligned_malloc(sizeof(stack_t), 16)) stack_t();//�V�K�m�[�h�𐶐�
	#endif//USE_LF_POOL_ALLOCATOR
		if (!new_node)//�������m�ێ��s
			return nullptr;//�v�b�V�����s
		if (reinterpret_cast<uintptr_t>(new_node)& 0xf)//16�o�C�g�A���C�������g�m�F
		{
			static const bool IS_NOT_16_ALIGNMENT = false;
			assert(IS_NOT_16_ALIGNMENT);
		#ifdef USE_LF_POOL_ALLOCATOR
			m_allocator.deleteObj(new_node);//�V�K�m�[�h���폜
		#else//USE_LF_POOL_ALLOCATOR
			_aligned_free(new_node);//�V�K�m�[�h���폜
		#endif//USE_LF_POOL_ALLOCATOR
			return false;
		}
		new_node->next = nullptr;//�V�K�m�[�h�̎��m�[�h��������
		new_node->value = value;//�V�K�m�[�h�ɒl���Z�b�g
		const uintptr_t tag = m_tag.fetch_add(1) & 0xf;//�^�O���Z�o
		stack_t* new_node_and_tag = reinterpret_cast<stack_t*>(reinterpret_cast<uintptr_t>(new_node) | tag);//�^�O��ǉ�
		while (true)
		{
			if (new_node->next != nullptr && reinterpret_cast<uintptr_t>(new_node->next) < 0x100)
			{
				printf("!!! new_node->next(0x%08x) is broken !!!\n", reinterpret_cast<uintptr_t>(new_node->next));
			}
			if (m_head.compare_exchange_weak(new_node->next, new_node_and_tag))
				return true;//�v�b�V������
			//�y���̏����𕪉����������z
			//    if(m_head == new_node->next)//�擪�m�[�h���V�K�m�[�h�̎��m�[�h���H
			//    {
			//        m_head = new_node_and_tag;//�擪�m�[�h��V�K�m�[�h���^�O�ɒu�������Ċ���
			//        //�v�b�V������
			//    }
			//    else
			//        new_node->next = m_head;//�V�K�m�[�h�̎��m�[�h�����݂̐擪�m�[�h�ɂ���
			//        �����̃^�C�~���O�ő��̃X���b�h���擪�m�[�h�����������Ă���\�������邽�߁A
			//          ���̃��[�v�Ő�������Ƃ͌���Ȃ�
		}
		return false;//�_�~�[
	}

	//�|�b�v
	bool pop(value_type& value)
	{
		stack_t* head_and_tag = m_head.load();//�擪�m�[�h���擾
		stack_t* head = nullptr;
		while (head_and_tag)
		{
			head = reinterpret_cast<stack_t*>(reinterpret_cast<uintptr_t>(head_and_tag) & ~0xf);//�^�O���폜
			if (m_head.compare_exchange_weak(head_and_tag, head->next))
			{
				value = head->value;//�l���擾
			#ifdef USE_LF_POOL_ALLOCATOR
				m_allocator.deleteObj(head);//�擪�m�[�h���폜
			#else//USE_LF_POOL_ALLOCATOR
				head->~stack_t();
				_aligned_free(head);//�擪�m�[�h���폜
			#endif//USE_LF_POOL_ALLOCATOR
				return true;//�|�b�v����
			}
			//�y���̏����𕪉����������z
			//    if(m_head == head_and_tag)//�擪�m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
			//    {
			//        m_head = head->next;//�擪�m�[�h��擪�m�[�h�̎��m�[�h�ɒu�������Ċ���
			//        //�|�b�v����
			//    }
			//    else
			//        head_and_tag = m_head;//�擪�m�[�h���Ď擾
		}
		return false;//�|�b�v���s
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_stack -----\n");
		printf("Stack:\n");
		int no = 0;
		stack_t* node_and_tag = m_head.load();
		while (node_and_tag)
		{
			stack_t* node = reinterpret_cast<stack_t*>(reinterpret_cast<uintptr_t>(node_and_tag)& ~0xf);
			const int tag = reinterpret_cast<uintptr_t>(node_and_tag)& 0xf;
			printf("[%d](%p:%d) ", no++, node, tag);
			print_node(node->value);
			printf("\n");
			node_and_tag = node->next;
		}
		printf("----------\n");
	#ifdef USE_LF_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](stack_t& info)
		{
			print_node(info.value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_LF_POOL_ALLOCATOR
	}

private:
	//������
	void initialize()
	{
		m_head.store(nullptr);//�擪�m�[�h�̏����l��nullptr
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
	pool_allocator<stack_t, POOL_SIZE> m_allocator;//�v�[���A���P�[�^
#endif//USE_LF_POOL_ALLOCATOR
	std::atomic<stack_t*> m_head;//�X�^�b�N�̐擪
	std::atomic<std::size_t> m_tag;//ABA���΍��p�̃^�O
	std::atomic<unsigned long long> m_test;
};

//--------------------------------------------------------------------------------
//�ʏ�L���[�N���X
//�����b�N�t���[�L���[�Ƃ̍����m�F���邽�߂ɁAstd::queue�͎g�p���Ȃ��istd::queue�̓������ė��p�̌����������̂ŒP���Ȕ�r�ɂȂ�Ȃ��j
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
		queue_t* next;
		value_type value;
	};

public:
	//���\�b�h

	//�G���L���[
	bool enqueue(value_type value)
	{
	#ifdef USE_POOL_ALLOCATOR
		queue_t* new_node = m_allocator.newObj();//�V�K�m�[�h�𐶐�
	#else//USE_POOL_ALLOCATOR
		queue_t* new_node = new queue_t();//�V�K�m�[�h�𐶐�
	#endif//USE_POOL_ALLOCATOR
		if (!new_node)//�������m�ێ��s
			return false;//�G���L���[���s
		new_node->next = nullptr;//�V�K�m�[�h�̎��m�[�h��������
		new_node->value = value;//�V�K�m�[�h�ɒl���Z�b�g
		std::lock_guard<std::mutex> lock(m_mutex);//�~���[�e�b�N�X�Ń��b�N
		m_tail->next = new_node;//�����m�[�h�̎��m�[�h��V�K�m�[�h�ɂ���
		m_tail = new_node;//�����m�[�h��V�K�m�[�h�ɂ���
		return true;//�G���L���[����
	}

	//�f�L���[
	bool dequeue(value_type& value)
	{
		std::lock_guard<std::mutex> lock(m_mutex);//�~���[�e�b�N�X�Ń��b�N
		if (m_head != m_tail)
		{
			queue_t* top = m_head->next;//���m�[�h�i�L���ȃL���[�̐擪�j���擾
		#ifdef USE_POOL_ALLOCATOR
			m_allocator.deleteObj(m_head);//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
		#else//USE_POOL_ALLOCATOR
			delete m_head;//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
		#endif//USE_POOL_ALLOCATOR
			m_head = top;//�擪�m�[�h�����m�[�h�ɕύX�i�����莟�m�[�h���_�~�[�m�[�h�����ɂȂ�j
			value = top->value;//�l���擾
			return true;//�f�L���[����
		}
		return false;//�f�L���[���s
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(value_type& value)> print_node)
	{
		printf("----- Debug Info for queue -----\n");
		printf("Queue:\n");
		int no = 0;
		queue_t* node = m_head;
		while (node)
		{
			printf("[%d](%p) ", no++, node);
			print_node(node->value);
			printf("\n");
			node = node->next;
		}
		printf("[tail](%p)", m_tail);
		print_node(m_tail->value);
		printf("\n");
		printf("----------\n");
	#ifdef USE_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](queue_t& info)
		{
			print_node(info.value);
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
		dummy_node->next = nullptr;//�_�~�[�m�[�h�̎��m�[�h��������
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
	queue_t* m_head;//�L���[�̐擪
	queue_t* m_tail;//�L���[�̖���
	std::mutex m_mutex;//�~���[�e�b�N�X
#ifdef USE_POOL_ALLOCATOR
	pool_allocator<queue_t, POOL_SIZE> m_allocator;//�v�[���A���P�[�^
#endif//USE_POOL_ALLOCATOR
};

//--------------------------------------------------------------------------------
//���b�N�t���[�L���[�N���X
//���b�N�t���[�L���[�̘_��:http://www.cs.rochester.edu/u/scott/papers/1996_PODC_queues.pdf
//�����L�̎����͂��̘_���Ɋ�Â��Ă���B�������AABA���΍�Ȃ��B
//#define ENABLE_DEBUG_RECORD_FOR_LF_QUEUE//�f�o�b�O�p����L�^���쐬����ꍇ�A���̃}�N����L��������
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

	//�L���[�^
	struct alignas(16) queue_t
	{
		std::atomic<queue_t*> next;
		value_type value;
	};

public:
	//���\�b�h
	
	//�G���L���[
	bool enqueue(value_type value)
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		queue_t* new_node = m_allocator.newObj();//�V�K�m�[�h�𐶐�
	#else//USE_LF_POOL_ALLOCATOR
		queue_t* new_node = new(_aligned_malloc(sizeof(queue_t), 16)) queue_t();//�V�K�m�[�h�𐶐�
	#endif//USE_LF_POOL_ALLOCATOR
		if (!new_node)//�������m�ێ��s
			return nullptr;//�G���L���[���s
		if (reinterpret_cast<uintptr_t>(new_node)& 0xf)//16�o�C�g�A���C�������g�m�F
		{
			static const bool IS_NOT_16_ALIGNMENT = false;
			assert(IS_NOT_16_ALIGNMENT);
			return false;
		}
		new_node->next = nullptr;//�V�K�m�[�h�̎��m�[�h��������
		new_node->value = value;//�V�K�m�[�h�ɒl���Z�b�g
		queue_t* tail = nullptr;
		while (true)
		{
			tail = m_tail.load();//�����m�[�h���擾
			queue_t* next = tail->next.load();//�����m�[�h�̎��m�[�h���擾
			if (tail == m_tail.load())//���̃^�C�~���O�ő��̃X���b�h�����������������Ă��Ȃ����H
			{
				if (!next)//�����m�[�h�̎��m�[�h�����[�inullptr�j���H
				{
					if (tail->next.compare_exchange_weak(next, new_node))
						break;
					//�y���̏����𕪉����������z
					//    if(tail->next == next)//�����m�[�h�̎��m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
					//    {
					//        tail->next = new_node;//�����m�[�h�̎��m�[�h�ɐV�K�m�[�h���Z�b�g
					//        break;//���[�v�𔲂���
					//    }
				}
				else//if(mext)//�����m�[�h�̎��m�[�h�����[�ł͂Ȃ��i���̃X���b�h�̏��������荞��ł����ꍇ�j
				{
					m_tail.compare_exchange_weak(tail, next);
					//�y���̏����𕪉����������z
					//    if(m_tail == tail)//�����m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
					//        m_tail = next;//�����m�[�h�����m�[�h�ɕύX
				}
			}
		}
		m_tail.compare_exchange_strong(tail, new_node);
		//�y���̏����𕪉����������z
		//    if(m_tail == tail)//�����m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
		//        m_tail = new_node;//�����m�[�h��V�K�m�[�h�ɕύX
		return true;//�G���L���[����
	}

	//�f�L���[
	bool dequeue(value_type& value)
	{
		queue_t* head = nullptr;
		queue_t* tail = nullptr;
		queue_t* top = nullptr;
		while (true)
		{
			head = m_head.load();//�擪�m�[�h���擾
			tail = m_tail.load();//�����m�[�h���擾
			queue_t* next = head->next.load();//�擪�m�[�h�̎��m�[�h�i�L���ȃL���[�̐擪�j���擾
			if (head == m_head.load())//���̃^�C�~���O�ő��̃X���b�h���擪�����������Ă��Ȃ����H
			{
				if (head == tail)//�擪�m�[�h�Ɩ����m�[�h���������H�i�L���[�C���O����Ă��Ȃ���Ԃ��H�j
				{
					if (!next)//�{���ɃL���[���Ȃ����H�itail�擾��next�擾�̊ԂɁA���̃X���b�h���L���[�C���O���Ă���\��������j
						return false;//�f�L���[���s
					m_tail.compare_exchange_strong(tail, next);
					//�y���̏����𕪉����������z
					//    if(m_tail == tail)//�����m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
					//        m_tail = next;//�����m�[�h�����m�[�h�ɕύX
				}
				else
				{
					top = next;//���m�[�h�i�L���ȃL���[�̐擪�j���擾
					if (m_head.compare_exchange_weak(head, next))
						break;
					//�y���̏����𕪉����������z
					//    if(m_head == head)//�擪�m�[�h�̎��m�[�h�𑼂̃X���b�h�����������Ă��Ȃ����H
					//    {
					//        m_head = next;//�擪�m�[�h�����m�[�h�ɕύX�i�����莟�m�[�h���_�~�[�m�[�h�����ɂȂ�j
					//        break;//���[�v�𔲂���
					//    }
				}
			}
		}
		value = top->value;//�l���擾
	#ifdef USE_LF_POOL_ALLOCATOR
		m_allocator.deleteObj(head);//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
	#else//USE_LF_POOL_ALLOCATOR
		head->~queue_t();
		_aligned_free(head);//�擪�m�[�h�i�_�~�[�m�[�h�j���폜
	#endif//USE_LF_POOL_ALLOCATOR
		return true;//�f�L���[����
	}

	//�f�o�b�O���\��
	void printDebugInfo(std::function<void(value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_queue -----\n");
		printf("Queue:\n");
		int no = 0;
		queue_t* node = m_head;
		while (node)
		{
			printf("[%d](%p) ", no++, node);
			print_node(node->value);
			printf("\n");
			node = node->next;
		}
		printf("[tail](%p)", m_tail.load());
		print_node(m_tail.load()->value);
		printf("\n");
		printf("----------\n");
	#ifdef USE_LF_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](queue_t& info)
		{
			print_node(info.value);
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
		dummy_node->next = nullptr;//�_�~�[�m�[�h�̎��m�[�h��������
		m_head.store(dummy_node);//�擪�m�[�h�Ƀ_�~�[�m�[�h���Z�b�g
		m_tail.store(dummy_node);//�����m�[�h�Ƀ_�~�[�m�[�h���Z�b�g
	}
	//�I��
	void finalize()
	{
		//��ɂȂ�܂Ńf�L���[
		value_type value;
		while (dequeue(value));
		//�_�~�[�m�[�h���폜
		queue_t* head = m_head.load();
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
	std::atomic<queue_t*> m_head;//�L���[�̐擪
	std::atomic<queue_t*> m_tail;//�L���[�̖���
#ifdef ENABLE_DEBUG_RECORD_FOR_LF_QUEUE
	//�f�o�b�O�p����L�^
	struct q_ope_t
	{
		bool is_enqeue;
		queue_t* head;
		queue_t* head_next;
		queue_t* tail;
	};
	static ope_t m_qOpeRec[10000];
	static std::atomic<std::size_t> m_qOpeIndex;
#endif//ENABLE_DEBUG_RECORD_FOR_LF_QUEUE
};
#ifdef ENABLE_DEBUG_RECORD_FOR_LF_QUEUE
//�f�o�b�O�p����L�^
template<class T, std::size_t POOL_SIZE>
typename lf_queue<T, POOL_SIZE>::q_ope_t lf_queue<T, POOL_SIZE>::m_qOpeRec[];
template<class T, std::size_t POOL_SIZE>
std::atomic<std::size_t> lf_queue<T, POOL_SIZE>::m_qOpeIndex;
#endif//ENABLE_DEBUG_RECORD_FOR_LF_QUEUE

//--------------------------------------------------------------------------------
//�e�X�g�p�f�[�^
struct data_t
{
	int m_temp;
	int m_value;
};

//--------------------------------------------------------------------------------
//�ʏ�X�^�b�N�e�X�g

#ifdef USE_POOL_ALLOCATOR
static stack<data_t, TEST_POOL_SIZE> s_stack;//�ʏ�X�^�b�N
#else//USE_POOL_ALLOCATOR
static stack<data_t> s_stack;//�ʏ�X�^�b�N
#endif//USE_POOL_ALLOCATOR

//���b�N�t���[�X�^�b�N�Ƀv�b�V��
bool pushNormal(data_t data)
{
	return s_stack.push(data);//�X�^�b�N�Ƀv�b�V��
}

//���b�N�t���[�X�^�b�N����|�b�v
bool popNormal(data_t& data)
{
	return s_stack.pop(data);//�X�^�b�N����|�b�v
}

//--------------------------------------------------------------------------------
//�ʏ�L���[�e�X�g

#ifdef USE_POOL_ALLOCATOR
static queue<data_t, TEST_POOL_SIZE> s_queue;//�ʏ�L���[
#else//USE_POOL_ALLOCATOR
static queue<data_t> s_queue;//�ʏ�L���[
#endif//USE_POOL_ALLOCATOR

//�ʏ�L���[�ɃG���L���[
bool enqueueNormal(data_t value)
{
	return s_queue.enqueue(value);
}
//�ʏ�L���[����f�L���[
bool dequeueNormal(data_t& value)
{
	return s_queue.dequeue(value);
}

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
//���b�N�t���[�X�^�b�N�e�X�g

#ifdef USE_LF_POOL_ALLOCATOR
static lf_stack<data_t, TEST_POOL_SIZE> s_lfStack;//���b�N�t���[�X�^�b�N
#else//USE_LF_POOL_ALLOCATOR
static lf_stack<data_t> s_lfStack;//���b�N�t���[�X�^�b�N
#endif//USE_LF_POOL_ALLOCATOR

//���b�N�t���[�X�^�b�N�Ƀv�b�V��
bool pushLockFree(data_t data)
{
	return s_lfStack.push(data);//�X�^�b�N�Ƀv�b�V��
}

//���b�N�t���[�X�^�b�N����|�b�v
bool popLockFree(data_t& data)
{
	return s_lfStack.pop(data);//�X�^�b�N����|�b�v
}

//--------------------------------------------------------------------------------
//���b�N�t���[�L���[�e�X�g

#ifdef USE_LF_POOL_ALLOCATOR
static lf_queue<data_t, TEST_POOL_SIZE> s_lfQueue;//���b�N�t���[�L���[
#else//USE_LF_POOL_ALLOCATOR
static lf_queue<data_t> s_lfQueue;//���b�N�t���[�L���[
#endif//USE_LF_POOL_ALLOCATOR

//���b�N�t���[�L���[�ɃG���L���[
bool enqueueLockFree(data_t value)
{
	return s_lfQueue.enqueue(value);
}
//���b�N�t���[�L���[����f�L���[
bool dequeueLockFree(data_t& value)
{
	return	s_lfQueue.dequeue(value);
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
//�e�X�g

#ifdef ENABLE_EASY_TEST
//�ȈՃe�X�g
void easyTest()
{
	printf("----------------------------------------\n");
	printf("[Test for Lock-free stack/queue]\n");
	
	//�ʏ�X�^�b�N
	{
		printf("Normal stack\n");
		for (int i = 1; i <= 3; ++i)
			pushNormal({ i });
		bool result;
		data_t value;
		while (true)
		{
			result = popNormal(value);
			if (!result)
				break;
			printf("pop: value=%d\n", value.m_value);
		}
	}
	//���b�N�t���[�X�^�b�N
	{
		printf("Lock-free stack\n");
		for (int i = 1; i <= 3; ++i)
			pushLockFree({ i });
		bool result;
		data_t value;
		while (true)
		{
			result = popLockFree(value);
			if (!result)
				break;
			printf("pop: value=%d\n", value.m_value);
		}
	}
	//�ʏ�L���[
	{
		printf("Normal queue\n");
		for (int i = 1; i <= 3; ++i)
			enqueueNormal({ i });
		bool result;
		data_t value;
		while (true)
		{
			result = dequeueNormal(value);
			if (!result)
				break;
			printf("deque: value=%d\n", value.m_value);
		}
	}
	//���b�N�t���[�L���[
	{
		printf("Lock-free queue\n");
		for (int i = 1; i <= 3; ++i)
			enqueueLockFree({ i });
		bool result;
		data_t value;
		while (true)
		{
			result = dequeueLockFree(value);
			if (!result)
				break;
			printf("deque: value=%d\n", value.m_value);
		}
	}
	//�ʏ�v�[���A���P�[�^
	{
		printf("Normal pool allocator\n");
		pool_allocator<data_t, 3> allocator;
		data_t* data[4] = { 0 };
		int value = 0;
		for (int repeat = 0; repeat < 3; ++repeat)
		{
			for (int i = 0; i < static_cast<int>(extentof(data)); ++i)
			{
				data[i] = allocator.newObj();
				if (data[i])
				{
					data[i]->m_value = ++value;
					//printf("create: value=%d\n", data[i]->m_value);
				}
			}
			for (int i = 0; i < static_cast<int>(extentof(data)); ++i)
			{
				if (data[i])
				{
					int delete_value = data[i]->m_value;
					if (allocator.deleteObj(data[i]))
						printf("delete: value=%d\n", delete_value);
				}
			}
		}
	}
	//���b�N�t���[�v�[���A���P�[�^
	{
		printf("Lock-free pool allocator\n");
		lf_pool_allocator<data_t, 3> allocator;
		data_t* data[4] = { 0 };
		int value = 0;
		for (int repeat = 0; repeat < 3; ++repeat)
		{
			for (int i = 0; i < static_cast<int>(extentof(data)); ++i)
			{
				data[i] = allocator.newObj();
				if (data[i])
				{
					data[i]->m_value = ++value;
					//printf("create: value=%d\n", data[i]->m_value);
				}
			}
			for (int i = 0; i < static_cast<int>(extentof(data)); ++i)
			{
				if (data[i])
				{
					int delete_value = data[i]->m_value;
					if (allocator.deleteObj(data[i]))
						printf("delete: value=%d\n", delete_value);
				}
			}
		}
	}
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
	printf("----------------------------------------\n");
	printf("[Test for Lock-free stack/queue with threads]\n");
	
	//�X�^�b�N�^�L���[�̃e�X�g�i���ʏ����j
	auto test_stack_queue = [](const char* caption, const char* push_name, const char* pop_name, std::function<bool(data_t)> push, std::function<bool(data_t&)> pop)
	{
		printf("--------------------\n");
		printf("[%s:START]\n", caption);
		
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
		auto threadPush = [&push_name, &push, &cond, &mutex, &isReady, &wait_count, &start_count, &end_count, &push_count](const int thread_no)
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
				++loop_count;
				if (loop_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(0));
				const int count = push_count.fetch_add(1);
				if (count > TEST_COUNT)
					break;
				const bool result = push({ 0, count });
				if (!result)
				{
					push_count.fetch_sub(1);
					continue;
				}
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
		printf("[%s:END] elapsed_time=%.9llf\n", caption, elapsed_time);
	};

	//�v�[���A���P�[�^�̃e�X�g�i���ʏ����j
	auto test_pool_allocator = [](const char* caption, std::function<data_t*()> alloc, std::function<bool(data_t*)> free)
	{
		printf("--------------------\n");
		printf("[%s:START]\n", caption);

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
				++loop_count;
				if (loop_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(0));
				const int count = alloc_count.fetch_add(1);
				if (count > TEST_COUNT)
					break;
				data_t* obj = alloc();
				if (!obj)
					continue;
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
		printf("[%s:END] elapsed_time=%.9llf\n", caption, elapsed_time);
	};
	
	//�f�o�b�O���\���p����
	auto debug_print_info = [](data_t& data)
	{
		printf("temp=%d, value=%d", data.m_temp, data.m_value);
	};
	
#if 0
	//�ʏ�X�^�b�N�̃e�X�g
	{
		auto push = [](data_t data) -> bool
		{
			return pushNormal(data);
		};
		auto pop = [](data_t& data) -> bool
		{
			return popNormal(data);
		};
		test_stack_queue("Normal Stack", "PUSH", "POP ", push, pop);
		
		s_stack.printDebugInfo(debug_print_info);
	}
#endif
#if 0
	//�ʏ�L���[�̃e�X�g
	{
		auto push = [](data_t data) -> bool
		{
			return enqueueNormal(data);
		};
		auto pop = [](data_t& data) -> bool
		{
			return dequeueNormal(data);
		};
		test_stack_queue("Normal Queue", "ENQUEUE", "DEQUEUE", push, pop);

		s_queue.printDebugInfo(debug_print_info);
	}
#endif
#if 1
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

		s_poolAllocator.printDebugInfo(debug_print_info);
	}
#endif

#if 0
	//���b�N�t���[�X�^�b�N�̃e�X�g
	{
		auto push = [](data_t data) -> bool
		{
			return pushLockFree(data);
		};
		auto pop = [](data_t& data) -> bool
		{
			return popLockFree(data);
		};
		test_stack_queue("Lock-Free Stack", "PUSH", "POP ", push, pop);

		s_lfStack.printDebugInfo(debug_print_info);
	}
#endif
#if 0
	//���b�N�t���[�L���[�̃e�X�g
	{
		auto push = [](data_t data) -> bool
		{
			return enqueueLockFree(data);
		};
		auto pop = [](data_t& data) -> bool
		{
			return dequeueLockFree(data);
		};
		test_stack_queue("Lock-Free Queue", "ENQUEUE", "DEQUEUE", push, pop);

		//s_lfQueue.printDebugInfo(debug_print_info);
	}
#endif
#if 1
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

		s_lfPoolAllocator.printDebugInfo(debug_print_info);
	}
#endif
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
