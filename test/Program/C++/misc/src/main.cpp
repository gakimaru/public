#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

//��`�ς݃}�N���\��
int printDefinedMacro(const int argc, const char* argv[])
{
	printf("\n- printDefinedMacro -\n\n");
	printf("\n�yANSI C�����̒�`�ς݃}�N���z\n");
	printf("__FILE__      = \"%s\"\n", __FILE__);
	printf("__LINE__      = %d\n", __LINE__);
	printf("__DATE__      = \"%s\"\n", __DATE__);
	printf("__TIME__      = \"%s\"\n", __TIME__);
	printf("__TIMESTAMP__ = \"%s\"\n", __TIMESTAMP__);
	printf("\n�yMicrosoft �ŗL�̒�`�ς݃}�N���z\n");
	printf("__COUNTER__        = %d\n", __COUNTER__);	//���J�E���g�A�b�v���m�F���邽�߂ɂR��g�p
	printf("__COUNTER__        = %d\n", __COUNTER__);	//��
	printf("__COUNTER__        = %d\n", __COUNTER__);	//��
	printf("__FUNCDNAME__      = \"%s\"\n", __FUNCDNAME__);
	printf("__FUNCSIG__        = \"%s\"\n", __FUNCSIG__);
	printf("__FUNCTION__       = \"%s\"\n", __FUNCTION__);
	printf("_INTEGRAL_MAX_BITS = %d\n", _INTEGRAL_MAX_BITS);
	printf("_M_IX86_FP         = %d\n", _M_IX86_FP);
	printf("_MSC_FULL_VER      = %d\n", _MSC_FULL_VER);
	printf("_MSC_VER           = %d\n", _MSC_VER);
	return 0;
}
//�֐��I�[�o�[���[�h�p�̃_�~�[�֐��i__FUNCDNAME__�e�X�g�p�j
void printDefinedMacro()
{}

//�����񉻃}�N��
#define TO_STRING(x) #x

//�}�N���W�J�t�������񉻃}�N��
#define TO_STRING_EX(x) TO_STRING(x)

//Visual C++ �ŗL�̒�`�ς݃}�N���u__FUNCSIG__�v��W�������邽�߂ɁA
//�u__FUNC__�v�Ƃ��čĒ�`�i���̃r���h���ł� __FUNC__ ��p����΃\�[�X�R�[�h�����ʗ��p�ł���悤�ɂ���j
#define __FUNC__ __FUNCSIG__

//�t�@�C�����擾�֐�
const char* getFileName(const char* path)
{
	const char* p = path + strlen(path) - 1;
	while (p > path)
	{
		if (*p == '\\' || *p == '/')
			return p + 1;
		--p;
	}
	return path;
}

//��`�ς݃}�N�������p�����A�T�[�V����
#define MY_ASSERT(expr, msg) \
if (!(expr)) \
{ \
	fprintf(stderr, "------------------------------------------------------------\n"); \
	fprintf(stderr, "Assertion failed!\n"); \
	fprintf(stderr, "%s(%d): %s\n", getFileName(__FILE__), __LINE__, __FUNC__); \
	fprintf(stderr, "%s\n", #expr);	/* ��expr�� # �ŕ����� */ \
	fprintf(stderr, "%s\n", msg); \
	fprintf(stderr, "------------------------------------------------------------\n"); \
	assert(expr);	/* ��������r��abort�̂��߂ɁA�W���ŗp�ӂ���Ă���assert()�����s */ \
}

//�A�T�[�V�����e�X�g
int testAssert(const int argc, const char* argv[])
{
	printf("\n- testAssert -\n\n");
	struct STRUCT
	{
		char memberA;
		short memberB;
		int memberC;
		char memberD;
	};
	MY_ASSERT(sizeof(STRUCT) == 8, "STRUCT�\���̂̃T�C�Y��8�o�C�g�ł͂���܂���I");
	return 0;
}

//�t�@�C�����擾�֐�
const char* getFileName2(const char* path, const size_t path_len)
{
	const char* p = path + path_len - 1;
	while (p > path)
	{
		if (*p == '\\' || *p == '/')
			return p + 1;
		--p;
	}
	return path;
}

//�����s���쐬�}�N��
//#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" #__LINE__ "):" __FUNC__, strlen(__FILE__))//�R���p�C���G���[
//#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" TO_STRING(__LINE__) "):" __FUNC__ TO_STRING( [�e�X�g!]) TO_STRING(123), strlen(__FILE__))
#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" TO_STRING_EX(__LINE__) "):" __FUNC__ TO_STRING( [�e�X�g!]) TO_STRING(123), strlen(__FILE__))

//������A���e�X�g
int testConcatenateStr(const int argc, const char* argv[])
{
	printf("\n- testConcatenateStr -\n\n");
	const char* func_line_info = MAKE_FUNC_LINE_INFO();
	printf("MAKE_FUNC_LINE_INFO() = \"%s\"\n", func_line_info);
	return 0;
}

//����̊֐�
//void functionForTokenConcatenateTestAAA01(){ printf("TEST: AAA-01\n"); }
//void functionForTokenConcatenateTestAAA02(){ printf("TEST: AAA-02\n"); }
//void functionForTokenConcatenateTestBBB01(){ printf("TEST: BBB-01\n"); }
//void functionForTokenConcatenateTestBBB02(){ printf("TEST: BBB-02\n"); }

//�g�[�N���A�����Z�q���g�����֐���`�}�N��
#define MAKE_TEST(ID, NO) \
	void functionForTokenConcatenateTest ## ID ## NO() \
{ \
	printf("TEST: " #ID "-" #NO "\n"); \
}

//����̊֐�
MAKE_TEST(AAA, 01)
MAKE_TEST(AAA, 02)
MAKE_TEST(BBB, 01)
MAKE_TEST(BBB, 02)

//�g�[�N���A�����Z�q���g�����֐��Ăяo���}�N��
#define TEST(ID, NO) functionForTokenConcatenateTest ## ID ## NO ()

//�g�[�N���A���e�X�g
int testConcatenateToken(const int argc, const char* argv[])
{
	printf("\n- testConcatenateToken -\n\n");
	TEST(AAA, 01);
	TEST(AAA, 02);
	TEST(BBB, 01);
	TEST(BBB, 02);
	return 0;
}

//�ő�l����}�N��
#define MAX(a, b) (a > b ? a : b)

#define ONCE once
#pragma ONCE

int testDengerMacro(const int argc, const char* argv[])
{
	printf("\n- testDengerMacro -\n\n");
	int x = MAX(1, 2);     //���ʁFx=2
	int y = MAX(4, 3);     //���ʁFy=3
	int z = MAX(++x, ++y); //���ʁFz=5�i���Ғl�j�� z=6�i���ہj
	printf("x=%d, y=%d, z=%d\n", x, y, z);
	return 0;
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	printDefinedMacro(argc, argv);

	testConcatenateStr(argc, argv);

	testConcatenateToken(argc, argv);

	testDengerMacro(argc, argv);

	testAssert(argc, argv);

	return EXIT_SUCCESS;
}

// End of file
