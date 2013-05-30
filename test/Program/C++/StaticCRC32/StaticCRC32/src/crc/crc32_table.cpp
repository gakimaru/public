//----- CRC32�������v�Z�e�[�u������ -----
//�ycrc32_table.cpp�z

//�C���N���[�h
#include "crc/crc32.h"
#include "crc/crc32_table.h"

//CRC32�������v�Z�e�[�u�������o�[����
#ifdef CRC32_TABLE_CHECK_ENABLED
bool CCRC32Table::m_Already = false; //�������v�Z�e�[�u�������ς݃t���O ����ɍ폜
#endif//CRC32_TABLE_CHECK_ENABLED

CRC32_TABLE_CONST CRC32T CCRC32Table::m_Table[CCRC32Table::TABLE_SIZE] //�������v�Z�e�[�u�� ����� const �t�����Œ�e�[�u���ǉ�
#ifdef CRC32_TABLE_MAKE_ENABLED
;
#else//CRC32_TABLE_MAKE_ENABLED
  = CRC32_TABLE_VALUES;
#endif//CRC32_TABLE_MAKE_ENABLED

#ifdef CRC32_TABLE_FUNC_ENABLED
//CRC32�������v�Z�e�[�u������ ���폜
static CCRC32Table* CRC32Table = nullptr;

//CRC32�������v�Z�e�[�u���擾 ���폜
CRC32T GetCRC32Table(const size_t index)
{
	if(!CRC32Table)
	{
		CRC32Table = new CCRC32Table();
	}
	if(!CRC32Table)
	{
		return 0;
	}
	return CRC32Table->GetTable(index);
}
#endif//CRC32_TABLE_FUNC_ENABLED

// End of file

//----- End of file -----
