//----- ���C������ -----
//�ymain.cpp�z

//�C���N���[�h
#include <stdlib.h>
#include "test/test_crc32.h"
#include "test/test_size.h"

//���C���֐�
int main(const int argc, const char* argv[])
{
	//CRC32�e�X�g
	Test_StaticCRC32();
	Test_DynamicCRC32();
	
	//�T�C�Y�擾�����e�X�g
	Test_Size();

	//constexpr/���[�U�[��`���e�����̃e�X�g
	extern void test_constexpr();
	test_constexpr();

	//�I��
	return EXIT_SUCCESS;
}

// End of file
