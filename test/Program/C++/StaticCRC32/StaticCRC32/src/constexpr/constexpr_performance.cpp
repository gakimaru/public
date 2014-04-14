#include "constexpr_test.h"

#ifdef ENABLE_PERFORMANCE_TEST
//※コンパイラの最適化の影響を受けずに比較し易いように、
//　ダミー引数を受け取り、テスト専用関数として構成
crc32_t test_performance(const char* str, const int dummy)
{
	return calcCRC32(str);//通常関数でランタイム時に計算
}
#endif//ENABLE_PERFORMANCE_TEST

// End of file
