#include "sub2.h"

//�y�^�C�v�R�z�œK���O�F���ʊ֐�
//���I�u�U�[�o�[�i�R�[���o�b�N�j���֐��|�C���^�^�Ŏ󂯎��
void commonProc_testOpt03_Type3_Before(int* values, std::size_t n, const int find, void(*observer)(int&))
{
	//�z�񂩂�l���������A��������I�u�U�[�o�[���Ăяo��
	for (int i = 0; i < n; ++i)
	{
		int& value = values[i];
		if (value == find)
			observer(value);
	}
}

// End of file
