#include "constexpr_test.h"

#ifdef ENABLE_PERFORMANCE_TEST
//���R���p�C���̍œK���̉e�����󂯂��ɔ�r���Ղ��悤�ɁA
//�@�_�~�[�������󂯎��A�e�X�g��p�֐��Ƃ��č\��
crc32_t test_performance(const char* str, const int dummy)
{
	return calcCRC32(str);//�ʏ�֐��Ń����^�C�����Ɍv�Z
}
#endif//ENABLE_PERFORMANCE_TEST

// End of file
