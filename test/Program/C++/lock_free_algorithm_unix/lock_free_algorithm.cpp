//--------------------------------------------------------------------------------
//コンパイラスイッチ

#define USE_GCC//GCC使用時は、このマクロを有効化する

#define USE_POOL_ALLOCATOR//スタック／キューの実装で、プールアロケータを使用する場合は、このマクロを有効化する
#define USE_LF_POOL_ALLOCATOR//ロックフリースタック／キューの実装で、ロックフリープールアロケータを使用する場合は、このマクロを有効化する
//#define USE_SAFE_CAS_LF_POOL_ALLOCATOR//ロックフリープールアロケータの実装で、CAS操作が意図通りに動作しない時の安全対策を使用する場合は、このマクロを有効化する
//#define USE_SAFE_CAS_LF_STACK//ロックフリースタックの実装で、CAS操作が意図通りに動作しない時の安全対策を使用する場合は、このマクロを有効化する
//#define USE_SAFE_CAS_LF_QUEUE//ロックフリーキューの実装で、CAS操作が意図通りに動作しない時の安全対策を使用する場合は、このマクロを有効化する
//※CAS操作の安全対策は、ごく稀にCAS操作が意図通りに動作しないことがあったために用意。CAS操作をスピンロックで保護する。ロックフリーとは言えなくなってしまう。

//--------------------------------------------------------------------------------
//テスト用コンパイラスイッチ／定数

//#define ENABLE_EASY_TEST//簡易テストを実行する場合は、このマクロを有効化する
#define ENABLE_THREAD_TEST//ステッドテストを実行する場合は、このマクロを有効化する

#define ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR//通常プールアロケータのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_LF_POOL_ALLOCATOR//ロックフリープールアロケータのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_NORMAL_STACK//通常スタックのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_LF_STACK//ロックフリースタックのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_NORMAL_QUEUE//通常キューのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_LF_QUEUE//ロックフリーキューのテストを有効にする場合は、このマクロを有効化する

//スレッドテスト用定数
//#define ENABLE_TEST_PRINT//スレッドテストの経過メッセージを表示する場合は、このマクロを有効化する
//#define ENABLE_TEST_PRINT_DEBUG_INFO//スレッドテストの最後にデバッグ情報を表示する場合は、このマクロを有効化する
//#define TEST_1_TIME//1回だけのテストを実行する場合は、このマクロを有効化する
#ifdef TEST_1_TIME
static const int TEST_COUNT = 1;//テスト回数
static const int TEST_PRINT_COUNT = 0;//テスト中のメッセージ表示回数
static const int TEST_PUSH_THREADS = 1;//テスト用のプッシュ／エンキュースレッド数
static const int TEST_POP_THREADS = 1;//テスト用のポップ／デキュースレッド数
static const int TEST_ALLOC_THREADS = 1;//テスト用のアロケートスレッド数
static const int TEST_POOL_SIZE = 10;//テスト用プールアロケータのプールサイズ
#else//TEST_1_TIME
#ifdef USE_GCC
static const int TEST_COUNT = 20000;//テスト回数
static const int TEST_PRINT_COUNT = 5;//テスト中のメッセージ表示回数
static const int TEST_PUSH_THREADS = 10;//テスト用のプッシュ／エンキュースレッド数
static const int TEST_POP_THREADS = 5;//テスト用のポップ／デキュースレッド数
static const int TEST_ALLOC_THREADS = 15;//テスト用のアロケートスレッド数
static const int TEST_POOL_SIZE = 20;//テスト用プールアロケータのプールサイズ
#else//USE_GCC
static const int TEST_COUNT = 200000;//テスト回数
static const int TEST_PRINT_COUNT = 5;//テスト中のメッセージ表示回数
static const int TEST_PUSH_THREADS = 10;//テスト用のプッシュ／エンキュースレッド数
static const int TEST_POP_THREADS = 5;//テスト用のポップ／デキュースレッド数
static const int TEST_ALLOC_THREADS = 15;//テスト用のアロケートスレッド数
static const int TEST_POOL_SIZE = 20;//テスト用プールアロケータのプールサイズ
#endif//USE_GCC
#endif//TEST_1_TIME
#ifdef ENABLE_TEST_PRINT
static const int TEST_PRINT_STEP = TEST_COUNT >= TEST_PRINT_COUNT * 10 ? TEST_COUNT / TEST_PRINT_COUNT : 10;//テスト中のメッセージ表示の間隔
#else//ENABLE_TEST_PRINT
static const int TEST_PRINT_STEP = 0;
#endif//ENABLE_TEST_PRINT

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>//assert()用

#include <cstddef>//std::size_t用

//アラインメント指定
#ifdef USE_GCC
#define alignas(n) __attribute__((aligned(n)))//GCC用
#else//USE_GCC
#define alignas(n) __declspec(align(n))//VC++用
#endif//USE_GCC

//アラインメント指定付きメモリ確保関数
//※VC++仕様に合わせて共通化
#ifdef USE_GCC
#include <cstddef>//std::size_t用
#include <stdlib.h>//posix_memalign()用
#include <memory.h>//free()用
inline void* _aligned_malloc(const std::size_t size, const std::size_t alignment)
{
	void *p;
	int ret = posix_memalign(&p, alignment, size);
	return (ret == 0) ? p : 0;
}
inline void _aligned_free(void* p)
{
	free(p);
}
#else//USE_GCC
#include <memory.h>//_aligned_malloc(), _aligned_free()用
//void* _aligned_malloc(size_t size, size_t alignment);
//void _aligned_free(void* p);
#endif//USE_GCC

//--------------------------------------------------------------------------------
//プールアロケータ用インクルード
#include <bitset>//std::bitset
#include <new>//new(void*), delete(void*, void*)

//--------------------------------------------------------------------------------
//通常スタック／キュー用インクルード
#include <utility>//C++11 std::move
#include <mutex>//C++11 std::mutex
#include <thread>//C++11 std::this_thread
#include <cstdint>//uintptr_t

//--------------------------------------------------------------------------------
//ロックフリースタック／キュー用インクルード
#include <atomic>//C++11 std::atomic

//--------------------------------------------------------------------------------
//汎用処理

//配列の要素数を返す
template<typename T, std::size_t N>
inline std::size_t extentof(T(&val)[N]){return N; }

//--------------------------------------------------------------------------------
//タグ付きポインタ型
//※32ビットアドレス前提
//※POD型を保証するためにコンストラクタを用意しない
template<typename T>
struct tag_ptr
{
	//型
	typedef unsigned long long value_type;//タグ付きポインタ型
	typedef T* pointer_type;//ポインタ型
	typedef unsigned int tag_type;//タグ型
	//キャストオペレータ
	inline operator value_type() const { return m_value; }
	inline operator const pointer_type() const { return ptr(); }
	inline operator pointer_type(){ return ptr(); }
	//オペレータ
	inline bool operator==(const tag_ptr& lhs) const { return m_value == lhs.m_value; }
	inline bool operator!=(const tag_ptr& lhs) const { return m_value != lhs.m_value; }
	//アクセッサ
	inline value_type value() const { return m_value; }
	inline const pointer_type ptr() const { return reinterpret_cast<const pointer_type>(m_value & 0xffffffffllu); }
	inline pointer_type ptr(){ return reinterpret_cast<pointer_type>(m_value & 0xffffffffllu); }
	inline tag_type tag() const { return static_cast<tag_type>(m_value >> 32); }
	inline bool isNull() const { return m_value == 0; }
	inline bool isNotNull() const { return m_value != 0; }
	inline void setTagPtr(const pointer_type ptr, const tag_type tag)
	{
		m_value = reinterpret_cast<value_type>(ptr) | (static_cast<value_type>(tag) << 32);
	}
	//フィールド
	value_type m_value;//タグ（上位32ビット）＋ポインタ（下位32ビット）
};

//--------------------------------------------------------------------------------
//通常プールアロケータクラス
template<class T, std::size_t POOL>
class pool_allocator
{
	static_assert(sizeof(T) >= 4, "sizeof(T) is too small.");

public:
	//型
	typedef T value_type;//値型

public:
	//定数
	static const std::size_t POOL_SIZE = POOL;//プールサイズ
	static const std::size_t VALUE_SIZE = sizeof(value_type);//値のサイズ
	static const std::size_t INVALID_INDEX = 0xffffffff;//無効なインデックス
	static const std::size_t DIRTY_INDEX = 0xfefefefe;//再利用連結インデックス削除用

public:
	//メソッド

	//メモリ確保
	void* alloc()
	{
		std::lock_guard<std::mutex> lock(m_mutex);//ミューテックスでロック
		//新規プールを確保
		if (m_emptyHead < POOL_SIZE)//空きバッファの先頭インデックスがプールサイズ未満ならそのまま返す
		{
			const std::size_t empty_index = m_emptyHead++;//空きバッファのインでックスを取得＆インクリメント
			void* empty = m_buff[empty_index];//空きバッファ取得
			*reinterpret_cast<std::size_t*>(empty) = DIRTY_INDEX;//再利用連結インデックス削除
			m_using[empty_index] = true;//インデックスを使用中にする
			++m_usingCount;//使用中の数を増やす
			return empty;//メモリ確保成功
		}
		//削除済みインデックスが無効ならメモリ確保失敗（空きプールが無い）
		if (m_deletedHead == INVALID_INDEX)
		{
			//static const bool NOT_ENOUGH_POOL_MEMORY = false;
			//assert(NOT_ENOUGH_POOL_MEMORY);
			return nullptr;//メモリ確保失敗
		}
		//再利用プールを確保
		{
			const std::size_t recycle_index = m_deletedHead;//先頭の削除済みインデックスを再利用インデックスとして取得
			void* recycle = m_buff[recycle_index];//再利用バッファ取得
			m_deletedHead = *reinterpret_cast<std::size_t*>(recycle);//先頭の削除済みインデックスを次のインデックスに変更
			*reinterpret_cast<std::size_t*>(recycle) = DIRTY_INDEX;//再利用連結インデックス削除
			m_using[recycle_index] = true;//インデックスを使用中にする
			++m_usingCount;//使用中の数を増やす
			return recycle;//メモリ確保成功
		}
	}

private:
	//メモリ解放
	bool free(void* p, const std::size_t index)
	{
		*reinterpret_cast<std::size_t*>(m_buff[index]) = m_deletedHead;//次の削除済みインデックスを保存
		m_deletedHead = index;//先頭の削除済みインデックスを変更
		m_using[index] = false;//インデックスを未使用状態にする
		--m_usingCount;//使用中の数を減らす
		return true;
	}
	
	//ポインタをインデックスに変換
	std::size_t ptrToIndex(void* p)
	{
		const std::size_t index = (reinterpret_cast<char*>(p) - reinterpret_cast<char*>(m_buff)) / VALUE_SIZE;
		if (index >= POOL_SIZE)//範囲外のインデックスなら終了
		{
			static const bool IS_INVALID_POINTER_OF_POOL = false;
			assert(IS_INVALID_POINTER_OF_POOL);
			return INVALID_INDEX;
		}
		if (!m_using[index])//インデックスが既に未使用状態なら終了
		{
			static const bool IS_ALREADY_DELETE_POINTER = false;
			assert(IS_ALREADY_DELETE_POINTER);
			return INVALID_INDEX;
		}
		return index;
	}

public:
	//メモリ解放
	bool free(void* p)
	{
		std::lock_guard<std::mutex> lock(m_mutex);//ミューテックスでロック
		const std::size_t index = ptrToIndex(p);//ポインタをインデックスに変換
		if (index == INVALID_INDEX)
			return false;
		return free(p, index);
	}
	
	//メモリ確保とコンストラクタ呼び出し
	template<typename...Tx>
	value_type* newObj(Tx... args)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(args...);
	}
	template<typename ObjType, typename...Tx>
	ObjType* newObj(Tx... args)
	{
		static_assert(sizeof(ObjType) <= VALUE_SIZE, "sizeof(ObjType) is too big.");
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)ObjType(args...);
	}
	
	//メモリ解放とデストラクタ呼び出し
	template<typename ObjType>
	bool deleteObj(ObjType* p)
	{
		std::lock_guard<std::mutex> lock(m_mutex);//ミューテックスでロック
		const std::size_t index = ptrToIndex(p);//ポインタをインデックスに変換
		if (index == INVALID_INDEX)
			return false;
		p->~ObjType();//デストラクタ呼び出し
		//operator delete(p, p);
		return free(p, index);
	}

	//デバッグ情報表示
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for pool_allocator -----\n");
		printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d, usingCount=%d\n", POOL_SIZE, VALUE_SIZE, m_emptyHead, m_usingCount);
		printf("Using:\n");
		for (int index = 0; index < POOL_SIZE; ++index)
		{
			if (m_using[index])
			{
				printf("[%d] ", index);
				print_node(*reinterpret_cast<const value_type*>(m_buff[index]));
				printf("\n");
			}
		}
		printf("Deleted(for Recycle):\n");
		std::size_t deleted_index = m_deletedHead;
		while (deleted_index != INVALID_INDEX)
		{
			printf(" [%d]", deleted_index);
			deleted_index = *reinterpret_cast<std::size_t*>(m_buff[deleted_index]);
		}
		printf("\n");
		printf("----------\n");
	}

public:
	//コンストラクタ
	pool_allocator() :
		m_emptyHead(0),
		m_deletedHead(INVALID_INDEX)
	{}
	//デストラクタ
	~pool_allocator()
	{}

private:
	//フィールド
	char m_buff[POOL_SIZE][VALUE_SIZE];//プールバッファ ※先頭に配置してクラスのアライメントと一致させる
	std::size_t m_emptyHead;//空きバッファの先頭インデックス
	std::size_t m_deletedHead;//先頭の削除済みインデックス（再利用用）
	std::bitset<POOL_SIZE> m_using;//使用中インデックス
	std::size_t m_usingCount;//使用中の数（デバッグ用）※必須の情報ではない
	std::mutex m_mutex;//ミューテックス
};

//--------------------------------------------------------------------------------
//ロックフリープールアロケータクラス
//※ABA問題対策あり（プール要素ごとの処理数をカウントし、重複処理を抑える）
template<class T, std::size_t POOL>
class lf_pool_allocator
{
	static_assert(sizeof(T) >= 4, "sizeof(T) is too small.");

public:
	//型
	typedef T value_type;//値型

public:
	//定数
	static const std::size_t POOL_SIZE = POOL;//プールサイズ
	static const std::size_t VALUE_SIZE = sizeof(value_type);//値のサイズ
	static const std::size_t INVALID_INDEX = 0xffffffff;//無効なインデックス
	static const std::size_t DIRTY_INDEX = 0xfefefefe;//再利用連結インデックス削除用

public:
	//メソッド
	
	//メモリ確保
	void* alloc()
	{
		//新規プールを確保
		{
			const std::size_t empty_index = m_emptyHead.fetch_add(1);//空きバッファの先頭インデックスを取得してインクリメント
			if (empty_index < POOL_SIZE)//空きバッファの先頭インデックスがプールサイズ未満ならそのまま返す
			{
				m_using[empty_index].fetch_add(1);//インデックスを使用中状態にする
				*reinterpret_cast<std::size_t*>(m_buff[empty_index]) = DIRTY_INDEX;//再利用連結インデックス削除
				m_usingCount.fetch_add(1);//使用中の数を増やす
				m_allocCount[empty_index].fetch_add(1);//アロケート回数をカウントアップ（デバッグ用）
				return m_buff[empty_index];//メモリ確保成功
			}
		}
		//再利用プールを確保
		{
			m_emptyHead.store(POOL_SIZE);//空きバッファの先頭インデックスをプールサイズにする（インクリメントでオーバーしてしまっているので）
			std::size_t recycle_index = m_deletedHead.load();//先頭の削除済みインデックスを再利用インデックスとして取得
			int retry_count = 0;//リトライ回数
			while (true)
			{
				++retry_count;
				if (retry_count == 1000)//一定数のリトライごとにゼロスリープ
				{
					std::this_thread::sleep_for(std::chrono::nanoseconds(0));//ゼロスリープ（コンテキストスイッチ）
					recycle_index = m_deletedHead.load();//再利用インデックスを再取得
					retry_count = 0;
				}
				if (recycle_index == INVALID_INDEX)//削除済みインデックスが無効ならメモリ確保失敗（空きプールが無い）
				{
					//static const bool NOT_ENOUGH_POOL_MEMORY = false;
					//assert(NOT_ENOUGH_POOL_MEMORY);
					return nullptr;//メモリ確保失敗
				}
				const std::size_t index_using = m_using[recycle_index].fetch_add(1);//インデックスを使用中状態にする
				if (index_using != 0)//他のスレッドがインデックスを処理中ならリトライ
				{
					m_using[recycle_index].fetch_sub(1);//インデックスの使用中状態を戻す
					recycle_index = m_deletedHead.load();//再利用インデックスを再取得
					continue;//リトライ
				}
				void* recycle = m_buff[recycle_index];//先頭の削除済みインデックスのプールを再利用
				const std::size_t next_index_and_tag = *reinterpret_cast<std::size_t*>(recycle);//先頭の削除済みインデックスの次のインデックスを取得
				std::size_t curr_recycle_index = recycle_index;//CAS操作失敗に備えて再利用インデックスを記憶

				//CAS操作
			#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR//【安全対策】※スピンロックでCAS操作を保護
				while (m_lock.test_and_set());//ロック取得
				const bool result = m_deletedHead.compare_exchange_weak(recycle_index, next_index_and_tag);//CAS操作
				m_lock.clear();//ロック解除
				if (result)
			#else//USE_SAFE_CAS_LF_POOL_ALLOCATOR
				if (m_deletedHead.compare_exchange_weak(recycle_index, next_index_and_tag))//CAS操作
			#endif//USE_SAFE_CAS_LF_POOL_ALLOCATOR
				//【CAS操作の内容】
				//    if(m_deletedHead == recycle_index)//先頭の削除済みインデックスを他のスレッドが書き換えていないか？
				//        m_deletedHead = next;//先頭の削除済みインデックスを次のインデックスに変更（メモリ確保成功）
				//    else
				//        recycle_index_and_tag = m_deletedHead;//先頭の削除済みインデックスを再取得
				{
					*reinterpret_cast<std::size_t*>(m_buff[recycle_index]) = DIRTY_INDEX;//再利用連結インデックス削除
					m_usingCount.fetch_add(1);//使用中の数を増やす
					m_allocCount[recycle_index].fetch_add(1);//アロケート回数をカウントアップ（デバッグ用）
					return recycle;//メモリ確保成功
				}
				
				m_using[curr_recycle_index].fetch_sub(1);//インデックスの使用中状態を戻してリトライ
			}
			return nullptr;//ダミー
		}
	}

private:
	//メモリ解放
	bool free(void* p, const std::size_t index)
	{
		std::size_t deleted_index_head = m_deletedHead.load();//削除済みインデックスを取得
		while (true)
		{
			*reinterpret_cast<std::size_t*>(m_buff[index]) = deleted_index_head;//次の削除済みインデックスを保存
			
			//CAS操作
		#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR//【安全対策】※スピンロックでCAS操作を保護
			while (m_lock.test_and_set());//ロック取得
			const bool result = m_deletedHead.compare_exchange_weak(deleted_index_head, index);//CAS操作
			m_lock.clear();//ロック解除
			if (result)
		#else//USE_SAFE_CAS_LF_POOL_ALLOCATOR
			if (m_deletedHead.compare_exchange_weak(deleted_index_head, index))//CAS操作
		#endif//USE_SAFE_CAS_LF_POOL_ALLOCATOR
			//【CAS操作の内容】
			//    if(m_deletedHead == deleted_head_index_and_tag)//先頭の削除済みインデックスを他のスレッドが書き換えていないか？
			//        m_deletedHead = index_and_tag;//先頭の削除済みインデックスを次のインデックスに変更（メモリ解放成功）
			//    else
			//        deleted_head_index_and_tag = m_deletedHead;//削除済みインデックスを再取得
			{
				m_using[index].fetch_sub(1);//インデックスを未使用状態にする
				m_usingCount.fetch_sub(1);//使用中の数を減らす
				m_freeCount[index].fetch_add(1);//フリー回数をカウントアップ（デバッグ用）
				return true;//メモリ解放成功
			}
		}
		return false;//ダミー
	}
	
	//ポインタをインデックスに変換
	std::size_t ptrToIndex(void* p)
	{
		const std::size_t index = (reinterpret_cast<char*>(p) - reinterpret_cast<char*>(m_buff)) / VALUE_SIZE;
		if (index >= POOL_SIZE)//範囲外のインデックスなら終了
		{
			static const bool IS_INVALID_POINTER_OF_POOL = false;
			assert(IS_INVALID_POINTER_OF_POOL);
			return INVALID_INDEX;
		}
		if (m_using[index].load() == 0)//インデックスが既に未使用状態なら終了
		{
			static const bool IS_ALREADY_DELETE_POINTER = false;
			assert(IS_ALREADY_DELETE_POINTER);
			return INVALID_INDEX;
		}
		return index;
	}

public:
	//メモリ解放
	bool free(void* p)
	{
		const std::size_t index = ptrToIndex(p);//ポインタをインデックスに変換
		if (index == INVALID_INDEX)
			return false;
		return free(p, index);
	}

	//メモリ確保とコンストラクタ呼び出し
	template<typename...Tx>
	value_type* newObj(Tx... args)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(args...);
	}
	template<typename ObjType, typename...Tx>
	ObjType* newObj(Tx... args)
	{
		static_assert(sizeof(ObjType) <= VALUE_SIZE, "sizeof(ObjType) is too big.");
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)ObjType(args...);
	}
	
	//メモリ解放とデストラクタ呼び出し
	template<typename ObjType>
	bool deleteObj(ObjType* p)
	{
		const std::size_t index = ptrToIndex(p);//ポインタをインデックスに変換
		if (index == INVALID_INDEX)
			return false;
		p->~ObjType();//デストラクタ呼び出し
		//operator delete(p, p);
		return free(p, index);
	}

	//デバッグ情報表示
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_pool_allocator -----\n");
		printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d, usingCount=%d\n", POOL_SIZE, VALUE_SIZE, m_emptyHead.load(), m_usingCount.load());
		printf("Using:\n");
		for (int index = 0; index < POOL_SIZE; ++index)
		{
			if (m_using[index].load() != 0)
			{
				printf("[%d]", index);
				if (m_using[index].load() != 1)
					printf("(using=%d)", m_using[index].load());
				printf("(leak=%d)", static_cast<int>(m_allocCount[index].load() - m_freeCount[index].load()));
				print_node(*reinterpret_cast<const value_type*>(m_buff[index]));
				printf("\n");
			}
			else
			{
				if (m_allocCount[index].load() != m_freeCount[index].load())
					printf("[%d](leak=%d)\n", index, static_cast<int>(m_allocCount[index].load() - m_freeCount[index].load()));
			}
		}
		printf("Deleted(for Recycle):\n");
		std::size_t deleted_index = m_deletedHead;
		while (deleted_index != INVALID_INDEX)
		{
			printf(" [%d]", deleted_index);
			deleted_index = *reinterpret_cast<std::size_t*>(m_buff[deleted_index]);
		}
		printf("\n");
		printf("----------\n");
	}

public:
	//コンストラクタ
	lf_pool_allocator()
	{
		m_emptyHead.store(0);
		m_deletedHead.store(INVALID_INDEX);
		m_usingCount.store(0);
		for (int i = 0; i < POOL_SIZE; ++i)
		{
			m_using[i].store(0);
			m_allocCount[i].store(0);
			m_freeCount[i].store(0);
		}
	}
	//デストラクタ
	~lf_pool_allocator()
	{}

private:
	//フィールド
	char m_buff[POOL_SIZE][VALUE_SIZE];//プールバッファ ※先頭に配置してクラスのアライメントと一致させる
	std::atomic<std::size_t> m_emptyHead;//空きバッファの先頭インデックス
	std::atomic<std::size_t> m_deletedHead;//先頭の削除済みインデックス（再利用用）
	std::atomic<char> m_using[POOL_SIZE];//使用中インデックス  ※std::bitset使用不可
	std::atomic<std::size_t> m_usingCount;//使用中の数（デバッグ用）※必須の情報ではない
	std::atomic<std::size_t> m_allocCount[POOL_SIZE];//アロケート回数（デバッグ用）※必須の情報ではない
	std::atomic<std::size_t> m_freeCount[POOL_SIZE];//フリー回数（デバッグ用）※必須の情報ではない
#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR
	std::atomic_flag m_lock;//CAS操作保護用のスピンロック
#endif//USE_SAFE_CAS_LF_POOL_ALLOCATOR
};

//--------------------------------------------------------------------------------
//通常スタッククラス
#ifdef USE_POOL_ALLOCATOR
template<class T, std::size_t POOL_SIZE>
#else//USE_POOL_ALLOCATOR
template<class T>
#endif//USE_POOL_ALLOCATOR
class stack
{
public:
	//型
	typedef T value_type;//値型

	//スタック型
	struct stack_t
	{
		stack_t* m_next;
		value_type m_value;
	};

public:
	//メソッド

	//プッシュ
	bool push(value_type&& value)
	{
	#ifdef USE_POOL_ALLOCATOR
		stack_t* new_node = m_allocator.newObj();//新規ノードを生成
	#else//USE_POOL_ALLOCATOR
		stack_t* new_node = new stack_t();//新規ノードを生成
	#endif//USE_POOL_ALLOCATOR
		if (!new_node)//メモリ確保失敗
			return false;//プッシュ失敗
		new_node->m_value = std::move(value);//新規ノードに値をセット
		std::lock_guard<std::mutex> lock(m_mutex);//ミューテックスでロック
		new_node->m_next = m_head;//新規ノードの次ノードに現在の先頭ノードをセット
		m_head = new_node;//先頭ノードを新規ノードにする
		return true;//プッシュ成功
	}

	//ポップ
	bool pop(value_type& value)
	{
		std::lock_guard<std::mutex> lock(m_mutex);//ミューテックスでロック
		stack_t* head = m_head;//先頭ノードを取得
		if (head)//先頭ノードが存在していた場合
		{
			m_head = head->m_next;//先頭ノードを次ノードに変更
			value = std::move(head->m_value);//値を取得
		#ifdef USE_POOL_ALLOCATOR
			m_allocator.deleteObj(head);//先頭ノードを削除
		#else//USE_POOL_ALLOCATOR
			delete head;//先頭ノードを削除
		#endif//USE_POOL_ALLOCATOR
			return true;//ポップ成功
		}
		return false;//ポップ失敗
	}

	//デバッグ情報表示
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for stack -----\n");
		printf("Stack:\n");
		int no = 0;
		stack_t* node = m_head;
		while (node)
		{
			printf("[%d](%p) ", no++, node);
			print_node(node->m_value);
			printf("\n");
			node = node->m_next;
		}
		printf("----------\n");
	#ifdef USE_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](const stack_t& info)
		{
			print_node(info.m_value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_POOL_ALLOCATOR
	}

private:
	//初期化
	void initialize()
	{
		m_head = nullptr;//先頭ノードの初期値はnullptr
	}
	//終了
	void finalize()
	{
		//空になるまでポップ
		value_type value;
		while (pop(value));
	}

public:
	//コンストラクタ
	stack()
	{
		initialize();
	}
	//デストラクタ
	~stack()
	{
		finalize();
	}
private:
	//フィールド
#ifdef USE_POOL_ALLOCATOR
	pool_allocator<stack_t, POOL_SIZE> m_allocator;//プールアロケータ
#endif//USE_POOL_ALLOCATOR
	stack_t* m_head;//スタックの先頭
	std::mutex m_mutex;//ミューテックス
};

//--------------------------------------------------------------------------------
//ロックフリースタッククラス
//※ABA問題対策あり（タグ付きポインタ型使用）
#ifdef USE_LF_POOL_ALLOCATOR
template<class T, std::size_t POOL_SIZE>
#else//USE_LF_POOL_ALLOCATOR
template<class T>
#endif//USE_LF_POOL_ALLOCATOR
class lf_stack
{
public:
	//型
	typedef T value_type;//値型

	//スタック型用タグ付きポインタ型
	struct stack_t;
	typedef tag_ptr<stack_t> stack_ptr_t;
	
	//スタック型
	struct stack_t
	{
		std::atomic<stack_ptr_t> m_next;
		value_type m_value;
	};

public:
	//メソッド

	//プッシュ
	bool push(value_type&& value)
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		stack_t* new_node = m_allocator.newObj();//新規ノードを生成
		if (!new_node)//メモリ確保失敗
			return nullptr;//プッシュ失敗
	#else//USE_LF_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(stack_t), 16);
		if (!p)//メモリ確保失敗
			return false;//プッシュ失敗
		stack_t* new_node = new(p) stack_t();//新規ノードを生成
	#endif//USE_LF_POOL_ALLOCATOR
		new_node->m_next.store(m_head.load());//新規ノードの次ノードに現在の先頭ノードをセット
		new_node->m_value = std::move(value);//新規ノードに値をセット
		stack_ptr_t new_node_tag_ptr;
		new_node_tag_ptr.setTagPtr(new_node, m_tag.fetch_add(1));//タグ付きポインタ生成
		while (true)
		{
			stack_ptr_t next_tag_ptr = new_node->m_next.load();
			if (next_tag_ptr == m_head.load())//このタイミングで他のスレッドが末尾を書き換えていないか？
			{
				//CAS操作
			#ifdef USE_SAFE_CAS_LF_STACK//【安全対策】※スピンロックでCAS操作を保護
				while (m_lock.test_and_set());//ロック取得
				const bool result = m_head.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr);//CAS操作
				m_lock.clear();//ロック解除
				if (result)
			#else//USE_SAFE_CAS_LF_STACK
				if (m_head.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr))//CAS操作
			#endif//USE_SAFE_CAS_LF_STACK
				//【CAS操作の内容】
				//    if(m_head == next_tag_ptr)//先頭ノードが新規ノードの次ノードか？
				//        m_head = new_node_tag_ptr;//先頭ノードを新規ノード＆タグに置き換えて完了（プッシュ成功）
				//    else
				//        next_tag_ptr = m_head;//新規ノードの次ノードを現在の先頭ノードにする
				{
					return true;//プッシュ成功
				}
				
				new_node->m_next.store(next_tag_ptr);//先頭ノードを再取得
			}
			else
				new_node->m_next.store(m_head.load());//先頭ノードを再取得
		}
		return false;//ダミー
	}

	//ポップ
	bool pop(value_type& value)
	{
		stack_ptr_t head_tag_ptr = m_head.load();//先頭ノードを取得
		while (head_tag_ptr.isNotNull())
		{
			stack_t* head = head_tag_ptr;//タグ付きポインタからポインタを取得
			stack_ptr_t next_tag_ptr = head->m_next;//次のノードを取得

			if (head_tag_ptr == m_head.load())//このタイミングで他のスレッドが末尾を書き換えていないか？
			{
				//CAS操作
			#ifdef USE_SAFE_CAS_LF_STACK//【安全対策】※スピンロックでCAS操作を保護
				while (m_lock.test_and_set());//ロック取得
				const bool result = m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr);//CAS操作
				m_lock.clear();//ロック解除
				if (result)
			#else//USE_SAFE_CAS_LF_STACK
				if (m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr))//CAS操作
			#endif//USE_SAFE_CAS_LF_STACK
				//【CAS操作の内容】
				//    if(m_head == head_tag_ptr)//先頭ノードを他のスレッドが書き換えていないか？
				//        m_head = next_tag_ptr;//先頭ノードを先頭ノードの次ノードに置き換えて完了（ポップ成功）
				//    else
				//        head_tag_ptr = m_head;//先頭ノードを再取得
				{
					value = std::move(head->m_value);//値を取得
				#ifdef USE_LF_POOL_ALLOCATOR
					m_allocator.deleteObj(head);//先頭ノードを削除
				#else//USE_LF_POOL_ALLOCATOR
					head->~stack_t();
					//operator delete(head, head);
					_aligned_free(head);//先頭ノードを削除
				#endif//USE_LF_POOL_ALLOCATOR
					return true;//ポップ成功
				}
			}
			else
				head_tag_ptr = m_head.load();//先頭ノードを再取得
		}
		return false;//ポップ失敗
	}

	//デバッグ情報表示
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_stack -----\n");
		printf("Stack:\n");
		int no = 0;
		stack_ptr_t node_tag_ptr = m_head.load();
		while (node_tag_ptr.isNotNull())
		{
			const stack_t* node = node_tag_ptr;
			printf("[%d(tag=%d)](%p) ", no++, node, node_tag_ptr.tag(), node);
			print_node(node->m_value);
			printf("\n");
			node_tag_ptr = node->m_next;
		}
		printf("----------\n");
	#ifdef USE_LF_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](const stack_t& info)
		{
			print_node(info.m_value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_LF_POOL_ALLOCATOR
	}

private:
	//初期化
	void initialize()
	{
		stack_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//タグ付きヌルポインタ
		m_head.store(null_tag_ptr);//先頭ノードの初期値はnull
		m_tag.store(0);//タグを初期化
		//if (m_head.is_lock_free())
		//	printf("m_head is lock free!\n");
	}
	//終了
	void finalize()
	{
		//空になるまでポップ
		value_type value;
		while (pop(value));
	}

public:
	//コンストラクタ
	lf_stack()
	{
		initialize();
	}
	//デストラクタ
	~lf_stack()
	{
		finalize();
	}
private:
	//フィールド
#ifdef USE_LF_POOL_ALLOCATOR
	lf_pool_allocator<stack_t, POOL_SIZE> m_allocator;//プールアロケータ
#endif//USE_LF_POOL_ALLOCATOR
	std::atomic<stack_ptr_t> m_head;//スタックの先頭　※タグ付きポインタ
	std::atomic<std::size_t> m_tag;//ABA問題対策用のタグ
#ifdef USE_SAFE_CAS_LF_STACK
	std::atomic_flag m_lock;//CAS操作保護用のスピンロック
#endif//USE_SAFE_CAS_LF_STACK
};

//--------------------------------------------------------------------------------
//通常キュークラス
#ifdef USE_POOL_ALLOCATOR
template<class T, std::size_t POOL_SIZE>
#else//USE_POOL_ALLOCATOR
template<class T>
#endif//USE_POOL_ALLOCATOR
class queue
{
public:
	//型
	typedef T value_type;//値型

	//キュー型
	struct queue_t
	{
		queue_t* m_next;
		value_type m_value;
	};

public:
	//メソッド

	//エンキュー
	bool enqueue(value_type&& value)
	{
	#ifdef USE_POOL_ALLOCATOR
		queue_t* new_node = m_allocator.newObj();//新規ノードを生成
	#else//USE_POOL_ALLOCATOR
		queue_t* new_node = new queue_t();//新規ノードを生成
	#endif//USE_POOL_ALLOCATOR
		if (!new_node)//メモリ確保失敗
			return false;//エンキュー失敗
		new_node->m_next = nullptr;//新規ノードの次ノードを初期化
		new_node->m_value = std::move(value);//新規ノードに値をセット
		std::lock_guard<std::mutex> lock(m_mutex);//ミューテックスでロック
		m_tail->m_next = new_node;//末尾ノードの次ノードを新規ノードにする
		m_tail = new_node;//末尾ノードを新規ノードにする
		return true;//エンキュー成功
	}

	//デキュー
	bool dequeue(value_type& value)
	{
		std::lock_guard<std::mutex> lock(m_mutex);//ミューテックスでロック
		if (m_head != m_tail)
		{
			queue_t* top = m_head->m_next;//次ノード（有効なキューの先頭）を取得
		#ifdef USE_POOL_ALLOCATOR
			m_allocator.deleteObj(m_head);//先頭ノード（ダミーノード）を削除
		#else//USE_POOL_ALLOCATOR
			delete m_head;//先頭ノード（ダミーノード）を削除
		#endif//USE_POOL_ALLOCATOR
			m_head = top;//先頭ノードを次ノードに変更（これより次ノードがダミーノード扱いになる）
			value = std::move(top->m_value);//値を取得
			return true;//デキュー成功
		}
		return false;//デキュー失敗
	}

	//デバッグ情報表示
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for queue -----\n");
		printf("Queue:\n");
		int no = 0;
		const queue_t* node = m_head;
		while (node)
		{
			printf("[%d](%p) ", no++, node);
			print_node(node->m_value);
			printf("\n");
			node = node->m_next;
		}
		printf("[tail](%p)", m_tail);
		print_node(m_tail->m_value);
		printf("\n");
		printf("----------\n");
	#ifdef USE_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](const queue_t& info)
		{
			print_node(info.m_value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_POOL_ALLOCATOR
	}

private:
	//初期化
	void initialize()
	{
	#ifdef USE_POOL_ALLOCATOR
		queue_t* dummy_node = m_allocator.newObj();//ダミーノードを生成
	#else//USE_POOL_ALLOCATOR
		queue_t* dummy_node = new queue_t;//ダミーノードを生成
	#endif//USE_POOL_ALLOCATOR
		dummy_node->m_next = nullptr;//ダミーノードの次ノードを初期化
		m_head = dummy_node;//先頭ノードにダミーノードをセット
		m_tail = dummy_node;//末尾ノードにダミーノードをセット
	}
	//終了
	void finalize()
	{
		//空になるまでデキュー
		value_type value;
		while (dequeue(value));
		//ダミーノードを削除
	#ifdef USE_POOL_ALLOCATOR
		m_allocator.deleteObj(m_head);
	#else//USE_POOL_ALLOCATOR
		delete m_head;
	#endif//USE_POOL_ALLOCATOR
	}

public:
	//コンストラクタ
	queue()
	{
		initialize();
	}
	//デストラクタ
	~queue()
	{
		finalize();
	}
private:
	//フィールド
#ifdef USE_POOL_ALLOCATOR
	pool_allocator<queue_t, POOL_SIZE> m_allocator;//プールアロケータ
#endif//USE_POOL_ALLOCATOR
	queue_t* m_head;//キューの先頭
	queue_t* m_tail;//キューの末尾
	std::mutex m_mutex;//ミューテックス
};

//--------------------------------------------------------------------------------
//ロックフリーキュークラス
//※論文に基づいていて実装: http://www.cs.rochester.edu/u/scott/papers/1996_PODC_queues.pdf
//※ABA問題対策あり（タグ付きポインタ型使用）
#ifdef USE_LF_POOL_ALLOCATOR
template<class T, std::size_t POOL_SIZE>
#else//USE_LF_POOL_ALLOCATOR
template<class T>
#endif//USE_LF_POOL_ALLOCATOR
class lf_queue
{
public:
	//型
	typedef T value_type;//値型

	//キュー型用タグ付きポインタ型
	struct queue_t;
	typedef tag_ptr<queue_t> queue_ptr_t;

	//キュー型
	struct queue_t
	{
		std::atomic<queue_ptr_t> m_next;
		value_type m_value;
	};

public:
	//メソッド
	
	//エンキュー
	bool enqueue(value_type&& value)
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		queue_t* new_node = m_allocator.newObj();//新規ノードを生成
		if (!new_node)//メモリ確保失敗
			return nullptr;//エンキュー失敗
	#else//USE_LF_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(queue_t), 16);
		if (!p)//メモリ確保失敗
			return false;//エンキュー失敗
		queue_t* new_node = new(p) queue_t();//新規ノードを生成
	#endif//USE_LF_POOL_ALLOCATOR
		queue_ptr_t new_node_tag_ptr;
		new_node_tag_ptr.setTagPtr(new_node, m_tag.fetch_add(1));//タグ付きポインタ生成
		queue_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//タグ付きヌルポインタ
		new_node->m_next.store(null_tag_ptr);//新規ノードの次ノードを初期化
		new_node->m_value = std::move(value);//新規ノードに値をセット
		queue_ptr_t tail_tag_ptr = null_tag_ptr;
		while (true)
		{
			tail_tag_ptr = m_tail.load();//末尾ノードを取得
			queue_t* tail = tail_tag_ptr;
			queue_ptr_t next_tag_ptr = tail->m_next.load();//末尾ノードの次ノードを取得
			if (tail_tag_ptr == m_tail.load())//このタイミングで他のスレッドが末尾を書き換えていないか？
			{
				if (next_tag_ptr.isNull())//末尾ノードの次ノードが末端（nullptr）か？
				{
					//CAS操作
				#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
					while (m_lock.test_and_set());//ロック取得
					const bool result = tail->m_next.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr);//CAS操作
						m_lock.clear();//ロック解除
					if (result)
				#else//USE_SAFE_CAS_LF_QUEUE
					if (tail->m_next.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr))//CAS操作
				#endif//USE_SAFE_CAS_LF_QUEUE
					//【CAS操作の内容】
					//    if(tail_tag_ptr->m_next == next_tag_ptr)//末尾ノードの次ノードを他のスレッドが書き換えていないか？
					//        tail_tag_ptr->m_next = new_node_tag_ptr;//末尾ノードの次ノードに新規ノードをセット（エンキュー成功）
					{
						//CAS操作
					#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
						while (m_lock.test_and_set());//ロック取得
						m_tail.compare_exchange_strong(tail_tag_ptr, new_node_tag_ptr);//CAS操作
						m_lock.clear();//ロック解除
					#else//USE_SAFE_CAS_LF_QUEUE
						m_tail.compare_exchange_strong(tail_tag_ptr, new_node_tag_ptr);//CAS操作
					#endif//USE_SAFE_CAS_LF_QUEUE
						//【CAS操作の内容】
						//    if(m_tail == tail_tag_ptr)//末尾ノードを他のスレッドが書き換えていないか？
						//        tail_tag_ptr = new_node_tag_ptr;//末尾ノードを新規ノードに変更

						return true;//エンキュー成功
					}
				}
				else//if(next_tag_ptr.isNotNull())//末尾ノードの次ノードが末端ではない（他のスレッドの処理が割り込んでいた場合）
				{
					//CAS操作
				#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
					while (m_lock.test_and_set());//ロック取得
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS操作
					m_lock.clear();//ロック解除
				#else//USE_SAFE_CAS_LF_QUEUE
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS操作
				#endif//USE_SAFE_CAS_LF_QUEUE
					//【CAS操作の内容】
					//    if(m_tail == tail_tag_ptr)//末尾ノードを他のスレッドが書き換えていないか？
					//        m_tail = next_tag_ptr;//末尾ノードを次ノードに変更
				}
			}
		}
		return false;//ダミー
	}

	//デキュー
	bool dequeue(value_type& value)
	{
		queue_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//タグ付きヌルポインタ
		queue_ptr_t head_tag_ptr = null_tag_ptr;
		queue_ptr_t tail_tag_ptr = null_tag_ptr;
		queue_ptr_t top_tag_ptr = null_tag_ptr;
		while (true)
		{
			head_tag_ptr = m_head.load();//先頭ノードを取得
			tail_tag_ptr = m_tail.load();//末尾ノードを取得
			queue_t* head = head_tag_ptr;
			queue_ptr_t next_tag_ptr = head->m_next.load();//先頭ノードの次ノード（有効なキューの先頭）を取得
			if (head_tag_ptr == m_head.load())//このタイミングで他のスレッドが先頭を書き換えていないか？
			{
				if (head_tag_ptr == tail_tag_ptr)//先頭ノードと末尾ノードが同じか？（キューイングされていない状態か？）
				{
					if (next_tag_ptr.isNull())//本当にキューがないか？（tail取得とnext取得の間に、他のスレッドがキューイングしている可能性がある）
						return false;//デキュー失敗
					
					//CAS操作
				#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
					while (m_lock.test_and_set());//ロック取得
					m_tail.compare_exchange_strong(tail_tag_ptr, next_tag_ptr);//CAS操作
					m_lock.clear();//ロック解除
				#else//USE_SAFE_CAS_LF_QUEUE
					m_tail.compare_exchange_strong(tail_tag_ptr, next_tag_ptr);//CAS操作
				#endif//USE_SAFE_CAS_LF_QUEUE
					//【CAS操作の内容】
					//    if(m_tail == tail_tag_ptr)//末尾ノードを他のスレッドが書き換えていないか？
					//        m_tail = next_tag_ptr;//末尾ノードを次ノードに変更
				}
				else
				{
					top_tag_ptr = next_tag_ptr;//次ノード（有効なキューの先頭）を取得
					
					//CAS操作
				#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
					while (m_lock.test_and_set());//ロック取得
					const bool result = m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr);//CAS操作
					m_lock.clear();//ロック解除
					if (result)
				#else//USE_SAFE_CAS_LF_QUEUE
					if (m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr))//CAS操作
				#endif//USE_SAFE_CAS_LF_QUEUE
					//【CAS操作の内容】
					//    if(m_head == head_tag_ptr)//先頭ノードの次ノードを他のスレッドが書き換えていないか？
					//        m_head = next_tag_ptr;//先頭ノードを次ノードに変更（これより次ノードがダミーノード扱いになる）（デキュー成功）
					{
						queue_t* top = top_tag_ptr;
						value = std::move(top->m_value);//値を取得
					#ifdef USE_LF_POOL_ALLOCATOR
						m_allocator.deleteObj(head);//先頭ノード（ダミーノード）を削除
					#else//USE_LF_POOL_ALLOCATOR
						head->~queue_t();
						//operator delete(head, head);
						_aligned_free(head);//先頭ノード（ダミーノード）を削除
					#endif//USE_LF_POOL_ALLOCATOR
						return true;//デキュー成功
					}
				}
			}
		}
		return false;//ダミー
	}

	//デバッグ情報表示
	void printDebugInfo(std::function<void(const value_type& value)> print_node)
	{
		printf("----- Debug Info for lf_queue -----\n");
		printf("Queue:\n");
		int no = 0;
		queue_ptr_t node_tag_ptr = m_head;
		while (node_tag_ptr.isNotNull())
		{
			queue_t* node = node_tag_ptr;
			printf("[%d(tag=%d)](%p) ", no++, node_tag_ptr.tag(), node);
			print_node(node->m_value);
			printf("\n");
			node_tag_ptr = node->m_next.load();
		}
		queue_ptr_t tail_tag_ptr = m_tail.load();
		queue_t* tail = tail_tag_ptr;
		printf("[tail(tag=%d)](%p)", tail_tag_ptr.tag(), tail);
		print_node(tail->m_value);
		printf("\n");
		printf("----------\n");
	#ifdef USE_LF_POOL_ALLOCATOR
		auto print_allocator_node = [&print_node](const queue_t& info)
		{
			print_node(info.m_value);
		};
		m_allocator.printDebugInfo(print_allocator_node);
	#endif//USE_LF_POOL_ALLOCATOR
	}

private:
	//初期化
	void initialize()
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		queue_t* dummy_node = m_allocator.newObj();//ダミーノードを生成
	#else//USE_LF_POOL_ALLOCATOR
		queue_t* dummy_node = new(_aligned_malloc(sizeof(queue_t), 16)) queue_t();//ダミーノードを生成
	#endif//USE_LF_POOL_ALLOCATOR
		queue_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//タグ付きヌルポインタ
		dummy_node->m_next.store(null_tag_ptr);//ダミーノードの次ノードを初期化
		queue_ptr_t dummy_node_tag_ptr;
		dummy_node_tag_ptr.setTagPtr(dummy_node, 0);
		m_head.store(dummy_node_tag_ptr);//先頭ノードにダミーノードをセット
		m_tail.store(dummy_node_tag_ptr);//末尾ノードにダミーノードをセット
		m_tag.store(0);//タグを初期化
		//if (dummy_node->m_next.is_lock_free())
		//	printf("dummy_node->m_next is lock free!\n");
		//if (m_head.is_lock_free())
		//	printf("m_head is lock free!\n");
		//if (m_tail.is_lock_free())
		//	printf("m_tail is lock free!\n");
	}
	//終了
	void finalize()
	{
		//空になるまでデキュー
		value_type value;
		while (dequeue(value));
		//ダミーノードを削除
		queue_ptr_t head_tag_ptr = m_head.load();
		queue_t* head = head_tag_ptr;
	#ifdef USE_LF_POOL_ALLOCATOR
		m_allocator.deleteObj(head);
	#else//USE_LF_POOL_ALLOCATOR
		head->~queue_t();
		_aligned_free(head);//先頭ノード（ダミーノード）を削除
	#endif//USE_LF_POOL_ALLOCATOR
	}

public:
	//コンストラクタ
	lf_queue()
	{
		initialize();
	}
	//デストラクタ
	~lf_queue()
	{
		finalize();
	}
private:
	//フィールド
#ifdef USE_LF_POOL_ALLOCATOR
	lf_pool_allocator<queue_t, POOL_SIZE> m_allocator;//プールアロケータ
#endif//USE_LF_POOL_ALLOCATOR
	std::atomic<queue_ptr_t> m_head;//キューの先頭
	std::atomic<queue_ptr_t> m_tail;//キューの末尾
	std::atomic<std::size_t> m_tag;//ABA問題対策用のタグ
#ifdef USE_SAFE_CAS_LF_QUEUE
	std::atomic_flag m_lock;//CAS操作保護用のスピンロック
#endif//USE_SAFE_CAS_LF_QUEUE
};

//--------------------------------------------------------------------------------
//テスト用データ
struct data_t
{
	int m_temp;
	int m_value;
};

//--------------------------------------------------------------------------------
//通常プールアロケータテスト

static pool_allocator<data_t, TEST_POOL_SIZE> s_poolAllocator;//通常プールアロケータ

//通常プールアロケータからアロケート
data_t* allocNormal()
{
	return s_poolAllocator.newObj();
}
//通常プールアロケータからフリー
bool freeNormal(data_t* value)
{
	return s_poolAllocator.deleteObj(value);
}

//--------------------------------------------------------------------------------
//ロックフリープールアロケータテスト

static lf_pool_allocator<data_t, TEST_POOL_SIZE> s_lfPoolAllocator;//ロックフリープールアロケータ

//ロックフリープールアロケータからアロケート
data_t* allocLockFree()
{
	return s_lfPoolAllocator.newObj();
}
//ロックフリープールアロケータからフリー
bool freeLockFree(data_t* value)
{
	return s_lfPoolAllocator.deleteObj(value);
}

//--------------------------------------------------------------------------------
//通常スタックテスト

#ifdef USE_POOL_ALLOCATOR
static stack<data_t, TEST_POOL_SIZE> s_stack;//通常スタック
#else//USE_POOL_ALLOCATOR
static stack<data_t> s_stack;//通常スタック
#endif//USE_POOL_ALLOCATOR

//通常スタックにプッシュ
bool pushNormal(data_t&& data)
{
	return s_stack.push(std::move(data));//スタックにプッシュ
}

//通常スタックからポップ
bool popNormal(data_t& data)
{
	return s_stack.pop(data);//スタックからポップ
}

//--------------------------------------------------------------------------------
//ロックフリースタックテスト

#ifdef USE_LF_POOL_ALLOCATOR
static lf_stack<data_t, TEST_POOL_SIZE> s_lfStack;//ロックフリースタック
#else//USE_LF_POOL_ALLOCATOR
static lf_stack<data_t> s_lfStack;//ロックフリースタック
#endif//USE_LF_POOL_ALLOCATOR

//ロックフリースタックにプッシュ
bool pushLockFree(data_t&& data)
{
	return s_lfStack.push(std::move(data));//スタックにプッシュ
}

//ロックフリースタックからポップ
bool popLockFree(data_t& data)
{
	return s_lfStack.pop(data);//スタックからポップ
}

//--------------------------------------------------------------------------------
//通常キューテスト

#ifdef USE_POOL_ALLOCATOR
static queue<data_t, TEST_POOL_SIZE> s_queue;//通常キュー
#else//USE_POOL_ALLOCATOR
static queue<data_t> s_queue;//通常キュー
#endif//USE_POOL_ALLOCATOR

//通常キューにエンキュー
bool enqueueNormal(data_t&& value)
{
	return s_queue.enqueue(std::move(value));
}
//通常キューからデキュー
bool dequeueNormal(data_t& value)
{
	return s_queue.dequeue(value);
}

//--------------------------------------------------------------------------------
//ロックフリーキューテスト

#ifdef USE_LF_POOL_ALLOCATOR
static lf_queue<data_t, TEST_POOL_SIZE> s_lfQueue;//ロックフリーキュー
#else//USE_LF_POOL_ALLOCATOR
static lf_queue<data_t> s_lfQueue;//ロックフリーキュー
#endif//USE_LF_POOL_ALLOCATOR

//ロックフリーキューにエンキュー
bool enqueueLockFree(data_t&& value)
{
	return s_lfQueue.enqueue(std::move(value));
}
//ロックフリーキューからデキュー
bool dequeueLockFree(data_t& value)
{
	return	s_lfQueue.dequeue(value);
}

//--------------------------------------------------------------------------------
//テスト

#ifdef ENABLE_EASY_TEST
//簡易テスト
void easyTest()
{
	printf("================================================================================\n");
	printf("[Test for Lock-free pool-allocator/stack/queue]\n");
	
#ifdef ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR
	//通常プールアロケータ
	{
		printf("Normal pool allocator\n");
		pool_allocator<data_t, 3> allocator;
		data_t* data[4] = { 0 };
		int value = 0;
		for (int repeat = 0; repeat < 3; ++repeat)
		{
			for (int i = 0; i < static_cast<int>(extentof(data)); ++i)
			{
				data[i] = allocator.newObj();
				if (data[i])
				{
					data[i]->m_value = ++value;
					//printf("create: value=%d\n", data[i]->m_value);
				}
			}
			for (int i = 0; i < static_cast<int>(extentof(data)); ++i)
			{
				if (data[i])
				{
					int delete_value = data[i]->m_value;
					if (allocator.deleteObj(data[i]))
						printf("delete: value=%d\n", delete_value);
				}
			}
		}
	}
#endif//ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR

#ifdef ENABLE_TEST_FOR_LF_POOL_ALLOCATOR
	//ロックフリープールアロケータ
	{
		printf("Lock-free pool allocator\n");
		lf_pool_allocator<data_t, 3> allocator;
		data_t* data[4] = { 0 };
		int value = 0;
		for (int repeat = 0; repeat < 3; ++repeat)
		{
			for (int i = 0; i < static_cast<int>(extentof(data)); ++i)
			{
				data[i] = allocator.newObj();
				if (data[i])
				{
					data[i]->m_value = ++value;
					//printf("create: value=%d\n", data[i]->m_value);
				}
			}
			for (int i = 0; i < static_cast<int>(extentof(data)); ++i)
			{
				if (data[i])
				{
					int delete_value = data[i]->m_value;
					if (allocator.deleteObj(data[i]))
						printf("delete: value=%d\n", delete_value);
				}
			}
		}
	}
#endif//ENABLE_TEST_FOR_LF_POOL_ALLOCATOR
	
#ifdef ENABLE_TEST_FOR_NORMAL_STACK
	//通常スタック
	{
		printf("Normal stack\n");
		for (int i = 1; i <= 3; ++i)
			pushNormal({ i });
		bool result;
		data_t value;
		while (true)
		{
			result = popNormal(value);
			if (!result)
				break;
			printf("pop: value=%d\n", value.m_value);
		}
	}
#endif//ENABLE_TEST_FOR_NORMAL_STACK
	
#ifdef ENABLE_TEST_FOR_LF_STACK
	//ロックフリースタック
	{
		printf("Lock-free stack\n");
		for (int i = 1; i <= 3; ++i)
			pushLockFree({ i });
		bool result;
		data_t value;
		while (true)
		{
			result = popLockFree(value);
			if (!result)
				break;
			printf("pop: value=%d\n", value.m_value);
		}
	}
#endif//ENABLE_TEST_FOR_LF_STACK
	
#ifdef ENABLE_TEST_FOR_NORMAL_QUEUE
	//通常キュー
	{
		printf("Normal queue\n");
		for (int i = 1; i <= 3; ++i)
			enqueueNormal({ i });
		bool result;
		data_t value;
		while (true)
		{
			result = dequeueNormal(value);
			if (!result)
				break;
			printf("deque: value=%d\n", value.m_value);
		}
	}
#endif//ENABLE_TEST_FOR_NORMAL_QUEUE
	
#ifdef ENABLE_TEST_FOR_LF_QUEUE
	//ロックフリーキュー
	{
		printf("Lock-free queue\n");
		for (int i = 1; i <= 3; ++i)
			enqueueLockFree({ i });
		bool result;
		data_t value;
		while (true)
		{
			result = dequeueLockFree(value);
			if (!result)
				break;
			printf("deque: value=%d\n", value.m_value);
		}
	}
#endif//ENABLE_TEST_FOR_LF_QUEUE
}
#endif//ENABLE_EASY_TEST

#ifdef ENABLE_THREAD_TEST
//スレッドを使ったテスト
#include <thread>//C++11 std::thread
#include <condition_variable>//C++11 std::condition_variable
#include <chrono>//C++11 std::chrono
#include <functional>//C++11 std::function
void thread_test()
{
	printf("================================================================================\n");
	printf("[Test for Lock-free pool-allocator/stack/queue with threads]\n");

	//プールアロケータのテスト（共通処理）
	auto test_pool_allocator = [](const char* caption, std::function<data_t*()> alloc, std::function<bool(data_t*)> free)
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[%s:START]\n", caption);
		printf("*Test count                     = %d\n", TEST_COUNT);
		printf("*Allocate and free test threads = %d\n", TEST_ALLOC_THREADS);
		printf("*Memory pool size               = %d\n", TEST_POOL_SIZE);

		std::condition_variable cond;
		std::mutex mutex;
		std::atomic<bool> is_ready;
		is_ready.store(false);
		auto isReady = [&is_ready]() -> bool
		{
			return is_ready.load();
		};
		std::atomic<int> wait_count;
		std::atomic<int> start_count;
		std::atomic<int> end_count;
		std::atomic<int> alloc_count;
		wait_count.store(0);
		start_count.store(0);
		end_count.store(0);
		alloc_count.store(0);
		auto threadAlloc = [&alloc, &free, &cond, &mutex, &isReady, &wait_count, &start_count, &end_count, &alloc_count](const int thread_no)
		{
			wait_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[Alloc:%2d]:Waiting...\n", thread_no);
		#endif//ENABLE_TEST_PRINT
			{
				std::unique_lock<std::mutex> lock(mutex);
				cond.wait(lock, isReady);
			}

			start_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[Alloc:%2d]:Start\n", thread_no);
		#endif//ENABLE_TEST_PRINT

			int loop_count = 0;
			int my_alloc_count = 0;
			while (true)
			{
				if (alloc_count.load() > TEST_COUNT)
					break;
				++loop_count;
				if (loop_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(0));
				data_t* obj = alloc();
				if (!obj)
					continue;
				const int count = alloc_count.fetch_add(1);
				std::this_thread::sleep_for(std::chrono::microseconds(0));
				free(obj);
				++my_alloc_count;
				if (my_alloc_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(1));
			#ifdef ENABLE_TEST_PRINT
				if (count % TEST_PRINT_STEP == 0)
					printf("[Alloc:%2d] alloc=%d\n", thread_no, count);
			#endif//ENABLE_TEST_PRINT
				//std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::microseconds(0));
			}

			end_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[Alloc:%2d]:End\n", thread_no);
		#endif//ENABLE_TEST_PRINT
		};
		std::thread* th[TEST_ALLOC_THREADS];
		int thread_count = 0;
		{
			std::lock_guard<std::mutex> lock(mutex);
			for (int i = 0; i < static_cast<int>(extentof(th)); ++i)
			{
				th[i] = new std::thread(threadAlloc, i);
				++thread_count;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		const auto begin_time = std::chrono::system_clock::now();
		{
			is_ready = true;
			while (true)
			{
				cond.notify_all();//きちんと全スレッドに通知できない場合があるのでリトライする
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				if (start_count.load() == thread_count)
					break;
			}
		}
		{
			for (int i = 0; i < static_cast<int>(extentof(th)); ++i)
			{
				th[i]->join();
				delete th[i];
				th[i] = nullptr;
			}
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("[%s:END] elapsed_time=%.9llf\n", caption, elapsed_time);
		printf("--------------------------------------------------------------------------------\n");
	};

	//スタック／キューのテスト（共通処理）
	auto test_stack_queue = [](const char* caption, const char* push_name, const char* pop_name, std::function<bool(data_t&&)> push, std::function<bool(data_t&)> pop)
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[%s:START]\n", caption);
		printf("*Test count                = %d\n", TEST_COUNT);
		printf("*Push/Enqueue test threads = %d\n", TEST_PUSH_THREADS);
		printf("*Pop/Dequeue  test threads = %d\n", TEST_POP_THREADS);
		printf("*Memory pool size          = %d\n", TEST_POOL_SIZE);

		std::condition_variable cond;
		std::mutex mutex;
		std::atomic<bool> is_ready;
		is_ready.store(false);
		auto isReady = [&is_ready]() -> bool
		{
			return is_ready.load();
		};
		std::atomic<int> wait_count;
		std::atomic<int> start_count;
		std::atomic<int> end_count;
		std::atomic<int> push_count;
		std::atomic<int> pop_count;
		std::atomic<int> seq_no;
		wait_count.store(0);
		start_count.store(0);
		end_count.store(0);
		push_count.store(0);
		pop_count.store(0);
		seq_no.store(0);
		auto threadPush = [&push_name, &push, &cond, &mutex, &isReady, &wait_count, &start_count, &end_count, &push_count, &seq_no](const int thread_no)
		{
			wait_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:Waiting...\n", push_name, thread_no);
		#endif//ENABLE_TEST_PRINT
			{
				std::unique_lock<std::mutex> lock(mutex);
				cond.wait(lock, isReady);
			}
			
			start_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:Start\n", push_name, thread_no);
		#endif//ENABLE_TEST_PRINT

			int loop_count = 0;
			int my_push_count = 0;
			while (true)
			{
				if (push_count.load() > TEST_COUNT)
					break;
				++loop_count;
				if (loop_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(0));
				const int no = seq_no.fetch_add(1);
				if (no > TEST_COUNT)
				{
					seq_no.fetch_sub(1);
					continue;
				}
				const bool result = push({ 0, no });
				if (!result)
				{
					seq_no.fetch_sub(1);
					continue;
				}
				const int count = push_count.fetch_add(1);
				++my_push_count;
				if (my_push_count % 1000 == 0)
					std::this_thread::sleep_for(std::chrono::microseconds(1));
			#ifdef ENABLE_TEST_PRINT
				if (count % TEST_PRINT_STEP == 0)
					printf("[%s:%2d] count=%d\n", push_name, thread_no, count);
			#endif//ENABLE_TEST_PRINT
				//std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::microseconds(0));
			}
			
			end_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:End\n", push_name, thread_no);
		#endif//ENABLE_TEST_PRINT
		};
		auto threadPop = [&pop_name, &pop, &cond, &mutex, &isReady, &wait_count, &start_count, &end_count, &pop_count](const int thread_no)
		{
			wait_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:Waiting...\n", pop_name, thread_no);
		#endif//ENABLE_TEST_PRINT
			{
				std::unique_lock<std::mutex> lock(mutex);
				cond.wait(lock, isReady);
			}

			start_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:Start\n", pop_name, thread_no);
		#endif//ENABLE_TEST_PRINT

			while (pop_count.load() <= TEST_COUNT)
			{
				data_t data;
				if (pop(data))
				{
					const int count = pop_count.fetch_add(1);
				#ifdef ENABLE_TEST_PRINT
					if (TEST_PRINT_STEP > 0 && count % TEST_PRINT_STEP == 0)
						printf("[%s:%2d] count=%d\n", pop_name, thread_no, count);
				#endif//ENABLE_TEST_PRINT
				}
				//std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::microseconds(0));
			}

			end_count.fetch_add(1);
		#ifdef ENABLE_TEST_PRINT
			printf("[%s:%2d]:End\n", pop_name, thread_no);
		#endif//ENABLE_TEST_PRINT
		};
		std::thread* th1[TEST_PUSH_THREADS];
		std::thread* th2[TEST_POP_THREADS];
		int thread_count = 0;
		{
			std::lock_guard<std::mutex> lock(mutex);
			for (int i = 0; i < static_cast<int>(extentof(th1)); ++i)
			{
				th1[i] = new std::thread(threadPush, i);
				++thread_count;
			}
			for (int i = 0; i < static_cast<int>(extentof(th2)); ++i)
			{
				th2[i] = new std::thread(threadPop, i);
				++thread_count;
			}
			std::this_thread::sleep_for(std::chrono::microseconds(1));
		}
		const auto begin_time = std::chrono::system_clock::now();
		{
			is_ready = true;
			while (true)
			{
				cond.notify_all();//きちんと全スレッドに通知できない場合があるのでリトライする
				std::this_thread::sleep_for(std::chrono::microseconds(1));
				if (start_count.load() == thread_count)
					break;
			}
		}
		{
			for (int i = 0; i < static_cast<int>(extentof(th1)); ++i)
			{
				th1[i]->join();
				delete th1[i];
				th1[i] = nullptr;
			}
			for (int i = 0; i < static_cast<int>(extentof(th2)); ++i)
			{
				th2[i]->join();
				delete th2[i];
				th2[i] = nullptr;
			}
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("[%s:END] elapsed_time=%.9llf\n", caption, elapsed_time);
		printf("--------------------------------------------------------------------------------\n");
	};
	
	//デバッグ情報表示用処理
	auto debug_print_info = [](const data_t& data)
	{
		printf("temp=%d, value=%d", data.m_temp, data.m_value);
	};
	
#ifdef ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR
	//通常プールアロケータのテスト
	{
		auto alloc = []() -> data_t*
		{
			return allocNormal();
		};
		auto free = [](data_t* data) -> bool
		{
			return freeNormal(data);
		};
		test_pool_allocator("Normal Pool-allocator", alloc, free);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_poolAllocator.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR

#ifdef ENABLE_TEST_FOR_LF_POOL_ALLOCATOR
	//ロックフリープールアロケータのテスト
	{
		auto alloc = []() -> data_t*
		{
			return allocLockFree();
		};
		auto free = [](data_t* data) -> bool
		{
			return freeLockFree(data);
		};
		test_pool_allocator("Lock-Free Pool-allocator", alloc, free);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfPoolAllocator.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_POOL_ALLOCATOR

#ifdef ENABLE_TEST_FOR_NORMAL_STACK
	//通常スタックのテスト
	{
		auto push = [](data_t&& data) -> bool
		{
			return pushNormal(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return popNormal(data);
		};
		test_stack_queue("Normal Stack", "PUSH", "POP ", push, pop);
		
	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_stack.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_STACK

#ifdef ENABLE_TEST_FOR_LF_STACK
	//ロックフリースタックのテスト
	{
		auto push = [](data_t&& data) -> bool
		{
			return pushLockFree(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return popLockFree(data);
		};
		test_stack_queue("Lock-Free Stack", "PUSH", "POP ", push, pop);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfStack.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_STACK

#ifdef ENABLE_TEST_FOR_NORMAL_QUEUE
	//通常キューのテスト
	{
		auto push = [](data_t&& data) -> bool
		{
			return enqueueNormal(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return dequeueNormal(data);
		};
		test_stack_queue("Normal Queue", "ENQUEUE", "DEQUEUE", push, pop);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_queue.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_NORMAL_QUEUE

#ifdef ENABLE_TEST_FOR_LF_QUEUE
	//ロックフリーキューのテスト
	{
		auto push = [](data_t&& data) -> bool
		{
			return enqueueLockFree(std::move(data));
		};
		auto pop = [](data_t& data) -> bool
		{
			return dequeueLockFree(data);
		};
		test_stack_queue("Lock-Free Queue", "ENQUEUE", "DEQUEUE", push, pop);

	#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfQueue.printDebugInfo(debug_print_info);
	#endif//ENABLE_TEST_PRINT_DEBUG_INFO
	}
#endif//ENABLE_TEST_FOR_LF_QUEUE
}
#endif//ENABLE_THREAD_TEST

//テスト
int main(const int argc, const char* argv[])
{
#ifdef ENABLE_EASY_TEST
	//簡易テスト
	easyTest();
#endif//ENABLE_EASY_TEST

#ifdef ENABLE_THREAD_TEST
	//スレッドを使ったテスト
	thread_test();
#endif//ENABLE_THREAD_TEST

	return EXIT_SUCCESS;
}

// End of file
