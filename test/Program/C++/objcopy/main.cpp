#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char binary_test_txt_start[];//test.txt �̐擪�̈ʒu
extern char binary_test_txt_end[];//test.txt �̏I�[+1�̈ʒu
extern char binary_test_txt_size[];//test.txt �̃T�C�Y
//_binary_ + (�t�@�C����) + _ + (�g���q) + _start / _end / _size �Ƃ����V���{���� objcopy �ō����
//Cygwin�̏ꍇ�͒��ӁI
//GCC�ŃR���p�C�����Ă��AVisual C++ �Ɠ������A�R���p�C������
//�����I�ɃV���{�����̐擪�ɃA���_�[�X�R�A��t������B
//���̂��߁AC/C++�̃R�[�h��ł͐擪�̃A���_�[�X�R�A��t���Ȃ��B

int main(const int argc, const char* argv[])
{
	const char *txt_top = binary_test_txt_start;//test.txt �̐擪�̈ʒu���擾
	const char *txt_end = binary_test_txt_end;//test.txt �̏I�[+1�̈ʒu���擾
	const size_t txt_size = reinterpret_cast<size_t>(binary_test_txt_size);//test.txt �̃T�C�Y���擾
	
	//test.txt �̓��e���R�s�[
	char* txt = new char[txt_size + 1];
	strncpy(txt, txt_top, txt_size);
	txt[txt_size] = '\0';
	
	//text.txt �̓��e��\��
	printf("test.txt = \"%s\"\n", txt);
	
	//�o�b�t�@��j��
	delete txt;
	
	return EXIT_SUCCESS;
}

// End of file
