//--------------------------------------------------------------------------------
//ソートアルゴリズムテスト用設定とコンパイラスイッチ

//#define USE_GCC//GCCを使用

//#define TEST_DATA_WATCH_CONSTRUCTOR//コンストラクタ／デストラクタ／代入演算子の動作を確認する場合、このマクロを有効化する

//static const int TEST_DATA_COUNT = 500000;//テストデータ件数（最大）
static const int TEST_DATA_COUNT = 100000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 50000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 20000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 10000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 5000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 1000;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 100;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 32;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 10;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 5;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 3;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 2;//テストデータ件数（最大）
//static const int TEST_DATA_COUNT = 1;//テストデータ件数（最大）

//#define TEST_DATA_SAME_KEY_NUM 1//テストデータに登録する同一キーデータの数（各キーのデータを指定数ずつ登録） ※安定ソートの挙動確認用
#define TEST_DATA_SAME_KEY_NUM 3//テストデータに登録する同一キーデータの数（各キーのデータを指定数ずつ登録） ※安定ソートの挙動確認用

//#define TEST_DATA_SIZE 512//テストデータ一件のサイズ
//#define TEST_DATA_SIZE 256//テストデータ一件のサイズ
#define TEST_DATA_SIZE 64//テストデータ一件のサイズ
//#define TEST_DATA_SIZE 4//テストデータ一件のサイズ

#define TEST_DATA_ALIGN 16//テストデータ一件のアラインメント
//#define TEST_DATA_ALIGN 4//テストデータ一件のアラインメント

//アラインメント属性
#ifdef USE_GCC
//#define alignas(n) __attribute__((aligned(n)))//for GCC
//#define alignof(T) __alignof__(T)//for GCC
#else//USE_GCC
#define alignas(n) __declspec(align(n))//for Visual C++
#define alignof(T) __alignof(T)//for Visual C++
#endif//USE_GCC

//アラインメント指定付きメモリ確保関数
#ifdef USE_GCC
#include <stdlib.h>//posix_memalign()用
#include <memory.h>//free()用
inline void* _aligned_malloc(size_t size, size_t alignment)
{
	void *p;
	int ret = posix_memalign(&p, alignment, size);
	return (ret == 0) ? p : 0;
}
#define _aligned_free(p) free(p)
#else//USE_GCC
#include <memory.h>//_aligned_malloc(), _aligned_free()用
//void* _aligned_malloc(size_t size, size_t alignment);
//void _aligned_free(void* p);
#endif//USE_GCC

//----------------------------------------
//テスト用構造体
#ifdef TEST_DATA_WATCH_CONSTRUCTOR
#include <stdio.h>
#include <memory.h>//memcpy用
#endif//TEST_DATA_WATCH_CONSTRUCTOR
struct alignas(TEST_DATA_ALIGN) data_t
{
	int m_key;//キー
	int m_seqNo;//シーケンス番号
	char m_data[TEST_DATA_SIZE];//データ（大き目のサイズにする）

#ifdef TEST_DATA_WATCH_CONSTRUCTOR
	data_t& operator=(const data_t&& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::move_assignment_operator\n");
		return *this;
	}
	data_t& operator=(const data_t& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::copy_assignment_operator\n");
		return *this;
	}
	data_t(const data_t&& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::move_constructor\n");
	}
	data_t(const data_t& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::copy_constructor\n");
	}
	data_t()
	{
		printf("data_t::constructor\n");
	}
	~data_t()
	{
		printf("data_t::destructor\n");
	}
#endif//TEST_DATA_WATCH_CONSTRUCTOR
};

// End of file
