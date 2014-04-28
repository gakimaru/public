//--------------------------------------------------------------------------------
//ソートアルゴリズムテスト用設定とコンパイラスイッチ
//static const int TEST_DATA_COUNT = 500000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 100000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 50000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 10000;//テストデータ件数（最大）
static const int TEST_DATA_COUNT = 5000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 1000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 100;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 10;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 2;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 1;//テストデータ件数（最大）

//#define TEST_DATA_SIZE 512//テストデータ一件のサイズ
//#define TEST_DATA_SIZE 256//テストデータ一件のサイズ
#define TEST_DATA_SIZE 64//テストデータ一件のサイズ
//#define TEST_DATA_SIZE 4//テストデータ一件のサイズ

#define TEST_DATA_ALIGN 16//テストデータ一件のアラインメント
//#define TEST_DATA_ALIGN 4//テストデータ一件のアラインメント

#define USE_GCC//GCCを使用

//アラインメント属性
#ifdef USE_GCC
#define ATTR_ALIGN(n) __attribute__((aligned(n)))//for GCC
#else//USE_GCC
#define ATTR_ALIGN(n) __declspec(align(n))//for Visual C++
#endif//USE_GCC

//メモリ確保関数
#ifdef USE_GCC
#define _memalign(alignment, size) memalign(alignment, size)
#define _free(p) free(p)
#else//USE_GCC
#define _memalign(alignment, size) _aligned_malloc(size, alignment)
#define _free(p) _aligned_free(p)
#endif//USE_GCC

//----------------------------------------
//テスト用構造体
struct ATTR_ALIGN(TEST_DATA_ALIGN) data_t
{
	int m_key;//キー
	char m_data[TEST_DATA_SIZE];//データ（大き目のサイズにする）
};

// End of file
