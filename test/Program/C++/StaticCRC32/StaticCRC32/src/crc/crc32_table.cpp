//----- CRC32多項式計算テーブル処理 -----
//【crc32_table.cpp】

//インクルード
#include "crc/crc32.h"
#include "crc/crc32_table.h"

//CRC32多項式計算テーブルメンバー実体
#ifdef CRC32_TABLE_CHECK_ENABLED
bool CCRC32Table::m_Already = false; //多項式計算テーブル生成済みフラグ ※後に削除
#endif//CRC32_TABLE_CHECK_ENABLED

CRC32_TABLE_CONST CRC32T CCRC32Table::m_Table[CCRC32Table::TABLE_SIZE] //多項式計算テーブル ※後に const 付加＆固定テーブル追加
#ifdef CRC32_TABLE_MAKE_ENABLED
;
#else//CRC32_TABLE_MAKE_ENABLED
  = CRC32_TABLE_VALUES;
#endif//CRC32_TABLE_MAKE_ENABLED

#ifdef CRC32_TABLE_FUNC_ENABLED
//CRC32多項式計算テーブル実体 ※削除
static CCRC32Table* CRC32Table = nullptr;

//CRC32多項式計算テーブル取得 ※削除
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
