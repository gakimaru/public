//--------------------------------------------------------------------------------
//�\�[�g�A���S���Y���e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
//static const int TEST_DATA_COUNT = 500000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 100000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 50000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 10000;//�e�X�g�f�[�^�����i�ő�j
static const int TEST_DATA_COUNT = 5000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 1000;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 100;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 10;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 2;//�e�X�g�f�[�^�����i�ő�j
//static const int TEST_DATA_COUNT = 1;//�e�X�g�f�[�^�����i�ő�j

//#define TEST_DATA_SIZE 512//�e�X�g�f�[�^�ꌏ�̃T�C�Y
//#define TEST_DATA_SIZE 256//�e�X�g�f�[�^�ꌏ�̃T�C�Y
#define TEST_DATA_SIZE 64//�e�X�g�f�[�^�ꌏ�̃T�C�Y
//#define TEST_DATA_SIZE 4//�e�X�g�f�[�^�ꌏ�̃T�C�Y

#define TEST_DATA_ALIGN 16//�e�X�g�f�[�^�ꌏ�̃A���C�������g
//#define TEST_DATA_ALIGN 4//�e�X�g�f�[�^�ꌏ�̃A���C�������g

#define USE_GCC//GCC���g�p

//�A���C�������g����
#ifdef USE_GCC
#define ATTR_ALIGN(n) __attribute__((aligned(n)))//for GCC
#else//USE_GCC
#define ATTR_ALIGN(n) __declspec(align(n))//for Visual C++
#endif//USE_GCC

//�������m�ۊ֐�
#ifdef USE_GCC
#define _memalign(alignment, size) memalign(alignment, size)
#define _free(p) free(p)
#else//USE_GCC
#define _memalign(alignment, size) _aligned_malloc(size, alignment)
#define _free(p) _aligned_free(p)
#endif//USE_GCC

//----------------------------------------
//�e�X�g�p�\����
struct ATTR_ALIGN(TEST_DATA_ALIGN) data_t
{
	int m_key;//�L�[
	char m_data[TEST_DATA_SIZE];//�f�[�^�i�傫�ڂ̃T�C�Y�ɂ���j
};

// End of file
