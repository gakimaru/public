//--------------------------------------------------------------------------------
//�\�[�g�A���S���Y���e�X�g�p�ݒ�ƃR���p�C���X�C�b�`

//#define USE_GCC//GCC���g�p

//#define TEST_DATA_WATCH_CONSTRUCTOR//�R���X�g���N�^�^�f�X�g���N�^�^������Z�q�̓�����m�F����ꍇ�A���̃}�N����L��������

//static const int TEST_DATA_COUNT = 500000;//�e�X�g�f�[�^�����i�ő�j
static const int TEST_DATA_COUNT = 100000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 50000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 20000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 10000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 5000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 1000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 100;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 32;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 10;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 5;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 3;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 2;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 1;//�e�X�g�f�[�^�����i�ő�j

//#define TEST_DATA_SAME_KEY_NUM 1//�e�X�g�f�[�^�ɓo�^���铯��L�[�f�[�^�̐��i�e�L�[�̃f�[�^���w�萔���o�^�j ������\�[�g�̋����m�F�p
#define TEST_DATA_SAME_KEY_NUM 3//�e�X�g�f�[�^�ɓo�^���铯��L�[�f�[�^�̐��i�e�L�[�̃f�[�^���w�萔���o�^�j ������\�[�g�̋����m�F�p

//#define TEST_DATA_SIZE 512//�e�X�g�f�[�^�ꌏ�̃T�C�Y
//#define TEST_DATA_SIZE 256//�e�X�g�f�[�^�ꌏ�̃T�C�Y
#define TEST_DATA_SIZE 64//�e�X�g�f�[�^�ꌏ�̃T�C�Y
//#define TEST_DATA_SIZE 4//�e�X�g�f�[�^�ꌏ�̃T�C�Y

#define TEST_DATA_ALIGN 16//�e�X�g�f�[�^�ꌏ�̃A���C�������g
//#define TEST_DATA_ALIGN 4//�e�X�g�f�[�^�ꌏ�̃A���C�������g

//�A���C�������g����
#ifdef USE_GCC
//#define alignas(n) __attribute__((aligned(n)))//for GCC
//#define alignof(T) __alignof__(T)//for GCC
#else//USE_GCC
#define alignas(n) __declspec(align(n))//for Visual C++
#define alignof(T) __alignof(T)//for Visual C++
#endif//USE_GCC

//�A���C�������g�w��t���������m�ۊ֐�
#ifdef USE_GCC
#include <stdlib.h>//posix_memalign()�p
#include <memory.h>//free()�p
inline void* _aligned_malloc(size_t size, size_t alignment)
{
	void *p;
	int ret = posix_memalign(&p, alignment, size);
	return (ret == 0) ? p : 0;
}
#define _aligned_free(p) free(p)
#else//USE_GCC
#include <memory.h>//_aligned_malloc(), _aligned_free()�p
//void* _aligned_malloc(size_t size, size_t alignment);
//void _aligned_free(void* p);
#endif//USE_GCC

//----------------------------------------
//�e�X�g�p�\����
#ifdef TEST_DATA_WATCH_CONSTRUCTOR
#include <stdio.h>
#include <memory.h>//memcpy�p
#endif//TEST_DATA_WATCH_CONSTRUCTOR
struct alignas(TEST_DATA_ALIGN) data_t
{
	int m_key;//�L�[
	int m_seqNo;//�V�[�P���X�ԍ�
	char m_data[TEST_DATA_SIZE];//�f�[�^�i�傫�ڂ̃T�C�Y�ɂ���j

#ifdef TEST_DATA_WATCH_CONSTRUCTOR
	data_t& operator=(const data_t&& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::move_assignment_operator\n");
		return *this;
	}
	data_t& operator=(const data_t& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::copy_assignment_operator\n");
		return *this;
	}
	data_t(const data_t&& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::move_constructor\n");
	}
	data_t(const data_t& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::copy_constructor\n");
	}
	data_t()
	{
		printf("data_t::constructor\n");
	}
	~data_t()
	{
		printf("data_t::destructor\n");
	}
#endif//TEST_DATA_WATCH_CONSTRUCTOR
};

// End of file
