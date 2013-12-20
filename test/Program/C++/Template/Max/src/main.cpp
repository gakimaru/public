#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//�e���v���[�g�֐����R���p�C�����Ƀ��e�����l�ɓW�J����鎖���e�X�g�i�œK�����x���Ɉˑ��j
//�����s���ɁA[�f�o�b�O]��[�E�C���h�E]��[�t�A�Z���u��]�ŁA�A�Z���u���̃R�[�h���m�F����B
template<typename T> T max(T n1, T n2){ return n1 >= n2 ? n1 : n2; }
template<typename T> T max(T n1, T n2, T n3){ return n1 >= n2 ? n1 : n2 >= n3 ? n2 : n3; }
template<typename T> T max(T n1, T n2, T n3, T n4){ return n1 >= n2 ? n1 : n2 >= n3 ? n2 : n3 >= n4 ? n3 : n4; }
void test_func1()
{
	std::cout << "max(1, 2)       = " << max(1, 2) << std::endl;
	std::cout << "max(1, 2, 3)    = " << max(1, 2, 3) << std::endl;
	std::cout << "max(1, 2, 3, 4) = " << max(1, 2, 3, 4) << std::endl;
}

//���������}�N���Ŏ��������ꍇ
#define max2(n1, n2) (n1 >= n2 ? n1 : n2)
#define max3(n1, n2, n3) (n1 >= n2 ? n1 : n2 >= n3 ? n2 : n3)
#define max4(n1, n2, n3, n4) (n1 >= n2 ? n1 : n2 >= n3 ? n2 : n3 >= n4 ? n3 : n4)
void test_func2()

{
	std::cout << "max2(1, 2)       = " << max2(1, 2) << std::endl;
	std::cout << "max3(1, 2, 3)    = " << max3(1, 2, 3) << std::endl;
	std::cout << "max4(1, 2, 3, 4) = " << max4(1, 2, 3, 4) << std::endl;
}

//�y���p�z����̃N���X�̒��ōő�̃T�C�Y��\�ߒ��ׂĂ���
//���Ⴆ�΁A�e���v���[�g���\�b�h�Ő������镡����̃I�u�W�F�N�g�ׂ̈ɁA�ŗL�̃o�b�t�@��p�ӂ��Ă����ꍇ�ȂǁB�o�b�t�@�T�C�Y�������v�Z����ׂɎg�p�B
//�������ȃ��e�����l���������萔�Ƃ̈Ⴂ���`�F�b�N���Ă���
//�����_�iVisual C++ 2013�j�F�e���v���[�g�֐��ɂ��R���p�C�����̃��e�����l�����͐������邪�A�K���f�[�^�̈�Ɍ��ʂ��i�[����A�R�[�h��ł̃��e�����l�W�J�͂���Ȃ��B���ꂪ�K�v�Ȃ�#define���g�����AC++11��constexpr�̎�����҂K�v������B
class CBase
{
public:
	int x;
};
class CA : public CBase
{
public:
	int y;
};
class CB : public CBase
{
public:
	int z[10];
};
class CC : public CBase
{
public:
	int a;
	int b;
	int c;
};
#define MAX_CLASS_SIZE1 max(sizeof(CA), sizeof(CB), sizeof(CC))//#define
#define MAX_CLASS_SIZE1x max3(sizeof(CA), sizeof(CB), sizeof(CC))//#define
#define LITERAL1 1//#define
const std::size_t MAX_CLASS_SIZE2 = max(sizeof(CA), sizeof(CB), sizeof(CC));//�O���[�o���萔
const std::size_t MAX_CLASS_SIZE2x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//�O���[�o���萔
const std::size_t LITERAL2 = 2;
static const std::size_t MAX_CLASS_SIZE3 = max(sizeof(CA), sizeof(CB), sizeof(CC));//static�O���[�o���萔
static const std::size_t MAX_CLASS_SIZE3x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//static�O���[�o���萔
static const std::size_t LITERAL3 = 3;
namespace NS
{
	const std::size_t MAX_CLASS_SIZE4 = max(sizeof(CA), sizeof(CB), sizeof(CC));//�l�[���X�y�[�X�萔
	const std::size_t MAX_CLASS_SIZE4x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//�l�[���X�y�[�X�萔
	const std::size_t LITERAL4 = 4;
	static const std::size_t MAX_CLASS_SIZE5 = max(sizeof(CA), sizeof(CB), sizeof(CC));//static�l�[���X�y�[�X�萔
	static const std::size_t MAX_CLASS_SIZE5x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//static�l�[���X�y�[�X�萔
	static const std::size_t LITERAL5 = 5;

};
void test_func3()
{
	const std::size_t MAX_CLASS_SIZE6 = max(sizeof(CA), sizeof(CB), sizeof(CC));//���[�J���萔
	const std::size_t MAX_CLASS_SIZE6x = max(sizeof(CA), sizeof(CB), sizeof(CC));//���[�J���萔
	const std::size_t LITERAL6 = 6;
	static const std::size_t MAX_CLASS_SIZE7 = max(sizeof(CA), sizeof(CB), sizeof(CC));//static���[�J���萔
	static const std::size_t MAX_CLASS_SIZE7x = max(sizeof(CA), sizeof(CB), sizeof(CC));//static���[�J���萔
	static const std::size_t LITERAL7 = 7;

	std::cout << "max(sizeof(CA), sizeof(CB), sizeof(CC))" << std::endl;
	std::cout << "  MAX_CLASS_SIZE1 = " << MAX_CLASS_SIZE1 << std::endl;
	std::cout << "  MAX_CLASS_SIZE2 = " << MAX_CLASS_SIZE2 << std::endl;
	std::cout << "  MAX_CLASS_SIZE3 = " << MAX_CLASS_SIZE3 << std::endl;
	std::cout << "  MAX_CLASS_SIZE4 = " << NS::MAX_CLASS_SIZE4 << std::endl;
	std::cout << "  MAX_CLASS_SIZE5 = " << NS::MAX_CLASS_SIZE5 << std::endl;
	std::cout << "  MAX_CLASS_SIZE6 = " << MAX_CLASS_SIZE6 << std::endl;
	std::cout << "  MAX_CLASS_SIZE7 = " << MAX_CLASS_SIZE7 << std::endl;
	std::cout << "max3(sizeof(CA), sizeof(CB), sizeof(CC))" << std::endl;
	std::cout << "  MAX_CLASS_SIZE1x = " << MAX_CLASS_SIZE1x << std::endl;
	std::cout << "  MAX_CLASS_SIZE2x = " << MAX_CLASS_SIZE2x << std::endl;
	std::cout << "  MAX_CLASS_SIZE3x = " << MAX_CLASS_SIZE3x << std::endl;
	std::cout << "  MAX_CLASS_SIZE4x = " << NS::MAX_CLASS_SIZE4x << std::endl;
	std::cout << "  MAX_CLASS_SIZE5x = " << NS::MAX_CLASS_SIZE5x << std::endl;
	std::cout << "  MAX_CLASS_SIZE6x = " << MAX_CLASS_SIZE6x << std::endl;
	std::cout << "  MAX_CLASS_SIZE7x = " << MAX_CLASS_SIZE7x << std::endl;
	std::cout << "LITERAL" << std::endl;
	std::cout << "  LITERAL1 = " << LITERAL1 << std::endl;
	std::cout << "  LITERAL2 = " << LITERAL2 << std::endl;
	std::cout << "  LITERAL3 = " << LITERAL3 << std::endl;
	std::cout << "  LITERAL4 = " << NS::LITERAL4 << std::endl;
	std::cout << "  LITERAL5 = " << NS::LITERAL5 << std::endl;
	std::cout << "  LITERAL6 = " << LITERAL6 << std::endl;
	std::cout << "  LITERAL7 = " << LITERAL7 << std::endl;
}

//���C��
int main(const int argc, const char* argv[])
{
	test_func1();
	test_func2();
	test_func3();
	return EXIT_SUCCESS;
}

// End of file
