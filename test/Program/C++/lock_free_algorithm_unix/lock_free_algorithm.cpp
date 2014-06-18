//--------------------------------------------------------------------------------
//コンパイラスイッチ

#define USE_GCC//GCC使用時は、このマクロを有効化する

#define USE_POOL_ALLOCATOR//スタック／キューの実装で、プールアロケータを使用する場合は、このマクロを有効化する
#define USE_LF_POOL_ALLOCATOR//ロックフリースタック／キューの実装で、ロックフリープールアロケータを使用する場合は、このマクロを有効化する
//#define USE_SAFE_ALLOC_LF_POOL_ALLOCATOR//ロックフリープールアロケータの実装で、同じインデックスのアロケートを排他制御する場合は、このマクロを有効化する
//#define USE_SAFE_CAS_LF_POOL_ALLOCATOR//ロックフリープールアロケータの実装で、CAS操作が意図通りに動作しない時の安全対策を使用する場合は、このマクロを有効化する
//#define USE_SAFE_CAS_LF_STACK//ロックフリースタックの実装で、CAS操作が意図通りに動作しない時の安全対策を使用する場合は、このマクロを有効化する
//#define USE_SAFE_CAS_LF_QUEUE//ロックフリーキューの実装で、CAS操作が意図通りに動作しない時の安全対策を使用する場合は、このマクロを有効化する
//※CAS操作の安全対策は、CAS操作に誤りがあり、意図通りに動作しなかった時の挙動比較用に用意したもの。CAS操作をスピンロックで保護するため、ロックフリーではなくなってしまう。

#define NORMAL_LOCK_IS_MUTEX//通常版のロック制御をミューテックスを使用して行う場合、このマクロを有効化する ※無効化時はスピンロックを使用する

//--------------------------------------------------------------------------------
//テスト用コンパイラスイッチ／定数

#define ENABLE_EASY_TEST//簡易テストを実行する場合は、このマクロを有効化する
#define ENABLE_THREAD_TEST//ステッドテストを実行する場合は、このマクロを有効化する

#define ENABLE_TEST_FOR_NORMAL_POOL_ALLOCATOR//通常プールアロケータのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_LF_POOL_ALLOCATOR//ロックフリープールアロケータのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_NORMAL_STACK//通常スタックのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_LF_STACK//ロックフリースタックのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_NORMAL_QUEUE//通常キューのテストを有効にする場合は、このマクロを有効化する
#define ENABLE_TEST_FOR_LF_QUEUE//ロックフリーキューのテストを有効にする場合は、このマクロを有効化する

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
static const int TEST_COUNT = 100000;//テスト回数
static const int TEST_PRINT_COUNT = 5;//テスト中のメッセージ表示回数
static const int TEST_PUSH_THREADS = 3;//テスト用のプッシュ／エンキュースレッド数
static const int TEST_POP_THREADS = 2;//テスト用のポップ／デキュースレッド数
static const int TEST_ALLOC_THREADS = 5;//テスト用のアロケートスレッド数
static const int TEST_POOL_SIZE = 20;//テスト用プールアロケータのプールサイズ
#else//USE_GCC
static const int TEST_COUNT = 500000;//テスト回数
static const int TEST_PRINT_COUNT = 5;//テスト中のメッセージ表示回数
static const int TEST_PUSH_THREADS = 3;//テスト用のプッシュ／エンキュースレッド数
static const int TEST_POP_THREADS = 2;//テスト用のポップ／デキュースレッド数
static const int TEST_ALLOC_THREADS = 5;//テスト用のアロケートスレッド数
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
#include <new>//new(void*), delete(void*, void*)
#include <bitset>//std::bitset
#include <thread>//C++11 std::this_thread

//--------------------------------------------------------------------------------
//通常スタック／キュー用インクルード
#include <mutex>//C++11 std::mutex
#include <utility>//C++11 std::move

//--------------------------------------------------------------------------------
//ロックフリースタック／キュー用インクルード
#include <atomic>//C++11 std::atomic
#include <utility>//C++11 std::move

//--------------------------------------------------------------------------------
//汎用処理

//配列の要素数を返す
template<typename T, std::size_t N>
inline std::size_t extentof(T(&val)[N]){return N; }

//--------------------------------------------------------------------------------
//タグ付きポインタ型
//※32ビットアドレス前提
//※POD型を保証するためにコンストラクタやコピーオペレータを用意しない
//※POD型について：http://ja.wikipedia.org/wiki/C++11#Plain_Old_Data_.E5.9E.8B.E3.81.AE.E5.AE.9A.E7.BE.A9.E3.81.AE.E4.BF.AE.E6.AD.A3
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
//スピンロック
class spin_lock
{
public:
	//ロック取得
	void lock()
	{
		while (m_lock.test_and_set());
	}
	//ロック解除
	void unlock()
	{
		m_lock.clear();
	}
private:
	//フィールド
	std::atomic_flag m_lock;//ロック用フラグ
};

//--------------------------------------------------------------------------------
//通常クラス用のロックオブジェクト
//※ミューテックスまたはスピンロック
class normal_lock
{
public:
	//ロック取得
	void lock()
	{
	#ifdef NORMAL_LOCK_IS_MUTEX
		m_lock.lock();//ミューテックス
	#else//NORMAL_LOCK_IS_MUTEX
		while (m_lock.test_and_set());//スピンロック
	#endif//NORMAL_LOCK_IS_MUTEX
	}
	//ロック解除
	void unlock()
	{
	#ifdef NORMAL_LOCK_IS_MUTEX
		m_lock.unlock();//ミューテックス
	#else//NORMAL_LOCK_IS_MUTEX
		m_lock.clear();//スピンロック
	#endif//NORMAL_LOCK_IS_MUTEX
	}
private:
	//フィールド
#ifdef NORMAL_LOCK_IS_MUTEX
	std::mutex m_lock;//ミューテックス
#else//NORMAL_LOCK_IS_MUTEX
	std::atomic_flag m_lock;//スピンロック用フラグ
#endif//NORMAL_LOCK_IS_MUTEX
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

	//再利用プール型
	struct recycable_t
	{
		std::size_t m_next_index;//再利用プール連結インデックス
	};

public:
	//定数
	static const std::size_t POOL_SIZE = POOL;//プールサイズ
	static const std::size_t VALUE_SIZE = sizeof(value_type);//値のサイズ
	static const std::size_t INVALID_INDEX = 0xffffffff;//無効なインデックス
	static const std::size_t DIRTY_INDEX = 0xfefefefe;//再利用プール連結インデックス削除用

public:
	//メソッド

	//メモリ確保
	void* alloc()
	{
		std::lock_guard<normal_lock> lock(m_lock);//ロック（スコープロック）
		//空きプールを確保
		if (m_vacantHead < POOL_SIZE)//空きプールの先頭インデックスがプールサイズ未満なら空きプールを利用する
		{
			const std::size_t vacant_index = m_vacantHead++;//空きプールの先頭インでックスを取得＆インクリメント
			m_using[vacant_index] = true;//インデックスを使用中にする
		//	++m_usingCount;//使用中の数を増やす（デバッグ用）
			return  m_pool[vacant_index];//メモリ確保成功
		}
		//再利用プールの先頭インデックスが無効ならメモリ確保失敗（再利用プールが無い）
		if (m_recyclableHead == INVALID_INDEX)
			return nullptr;//メモリ確保失敗
		//再利用プールを確保
		{
			const std::size_t recyclable_index = m_recyclableHead;//再利用プールの先頭インデックスを取得
			recycable_t* recyclable_pool = reinterpret_cast<recycable_t*>(m_pool[recyclable_index]);//再利用プールの先頭を割り当て
			m_recyclableHead = recyclable_pool->m_next_index;//再利用プールの先頭インデックスを次の再利用プールに変更
			recyclable_pool->m_next_index = DIRTY_INDEX;//再利用プールの連結インデックスを削除
			m_using[recyclable_index] = true;//インデックスを使用中にする
		//	++m_usingCount;//使用中の数を増やす（デバッグ用）
			return recyclable_pool;//メモリ確保成功
		}
	}

private:
	//メモリ解放（共通処理）
	//※ロック取得は呼び出し元で行う
	bool free(void* p, const std::size_t index)
	{
		recycable_t* deleted_pool = reinterpret_cast<recycable_t*>(m_pool[index]);//解放されたメモリを参照
		deleted_pool->m_next_index = m_recyclableHead;//次の再利用プールのインデックスを保存
		m_recyclableHead = index;//再利用プールの先頭インデックスを変更
		m_using[index] = false;//インデックスを未使用状態にする
	//	--m_usingCount;//使用中の数を減らす（デバッグ用）
		return true;
	}
	
	//ポインタをインデックスに変換
	std::size_t ptrToIndex(void* p)
	{
		const std::size_t index = (reinterpret_cast<char*>(p) - reinterpret_cast<char*>(m_pool)) / VALUE_SIZE;
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
		std::lock_guard<normal_lock> lock(m_lock);//ロック（スコープロック）
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
		static_assert(sizeof(ObjType) <= VALUE_SIZE, "sizeof(ObjType) is too large.");
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)ObjType(args...);
	}
	value_type* newCopyObj(value_type& org)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(org);
	}
	value_type* newMoveObj(value_type&& org)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(std::move(org));
	}

	//メモリ解放とデストラクタ呼び出し
	template<typename ObjType>
	bool deleteObj(ObjType* p)
	{
		std::lock_guard<normal_lock> lock(m_lock);//ロック（スコープロック）
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
	//	printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d, usingCount=%d\n", POOL_SIZE, VALUE_SIZE, m_vacantHead, m_usingCount);
		printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d\n", POOL_SIZE, VALUE_SIZE, m_vacantHead);
		printf("Using:\n");
		for (int index = 0; index < POOL_SIZE; ++index)
		{
			if (m_using[index])
			{
				printf("[%d] ", index);
				print_node(*reinterpret_cast<const value_type*>(m_pool[index]));
				printf("\n");
			}
		}
		printf("Recycable pool:\n");
		std::size_t recycable_index = m_recyclableHead;
		while (recycable_index != INVALID_INDEX)
		{
			printf(" [%d]", recycable_index);
			recycable_t* recycable_pool = reinterpret_cast<recycable_t*>(m_pool[recycable_index]);
			recycable_index = recycable_pool->m_next_index;
		}
		printf("\n");
		printf("----------\n");
	}

public:
	//コンストラクタ
	pool_allocator() :
		m_vacantHead(0),
		m_recyclableHead(INVALID_INDEX)
	{}
	//デストラクタ
	~pool_allocator()
	{}

private:
	//フィールド
	char m_pool[POOL_SIZE][VALUE_SIZE];//プールバッファ ※先頭に配置してクラスのアライメントと一致させる
	std::size_t m_vacantHead;//空きプールの先頭インデックス
	std::size_t m_recyclableHead;//再利用プールの先頭インデックス
	std::bitset<POOL_SIZE> m_using;//使用中インデックス（二重解放判定用）
//	std::size_t m_usingCount;//使用中の数（デバッグ用）※必須の情報ではない
	normal_lock m_lock;//ロックオブジェクト（ミューテックスorスピンロック）
};

//--------------------------------------------------------------------------------
//ロックフリープールアロケータクラス
//※ABA問題対策あり（プールの再利用インデックスに8ビットのタグを付けて管理）
//※プール可能な要素数の最大は2^(32-8)-2 = 16,777,214個（2^(32-8)-1だと、値がINVALID_INDEXになる可能性があるのでNG）
template<class T, std::size_t POOL>
class lf_pool_allocator
{
	static_assert(sizeof(T) >= 4, "sizeof(T) is too small.");
	static_assert(POOL < 0x00ffffff, "POOL is too large.");

public:
	//型
	typedef T value_type;//値型

	//再利用プール型
	struct recycable_t
	{
		std::atomic<std::size_t> m_next_index;//再利用プール連結インデックス
	};

public:
	//定数
	static const std::size_t POOL_SIZE = POOL;//プールサイズ
	static const std::size_t VALUE_SIZE = sizeof(value_type);//値のサイズ
	static const std::size_t INVALID_INDEX = 0xffffffff;//無効なインデックス
	static const std::size_t DIRTY_INDEX = 0xfefefefe;//再利用プール連結インデックス削除用

public:
	//メソッド
	
	//メモリ確保
	void* alloc()
	{
		//空きプールを確保
		if (m_vacantHead.load() < POOL_SIZE)//空きプールの先頭インデックスがプールサイズ未満なら空きプールを利用
		{
			const std::size_t vacant_index = m_vacantHead.fetch_add(1);//空きプールの先頭インデックスを取得してインクリメント
			if (vacant_index < POOL_SIZE)//プールサイズ未満なら確保成功
			{
				m_using[vacant_index].fetch_add(1);//インデックスを使用中状態にする
			//	m_usingCount.fetch_add(1);//使用中の数を増やす（デバッグ用）
			//	m_allocCount[vacant_index].fetch_add(1);//アロケート回数をカウントアップ（デバッグ用）
				return m_pool[vacant_index];//メモリ確保成功
			}
			if (vacant_index > POOL_SIZE)//インクリメントでオーバーしたインデックスを元に戻す
				m_vacantHead.store(POOL_SIZE);
		}
		//再利用プールを確保
		{
			std::size_t recycable_index_and_tag = m_recyclableHead.load();//再利用プールの先頭インデックスを取得
		#ifdef USE_SAFE_ALLOC_LF_POOL_ALLOCATOR//【安全対策】※同じインデックスのアロケートを排他制御
			static const int retry_max = 32;
			int retry_count = retry_max;//リトライ回数
		#endif//USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
			while (true)
			{
				if (recycable_index_and_tag == INVALID_INDEX)//再利用プールの先頭インデックスが無効ならメモリ確保失敗（再利用プールが無い）
					return nullptr;//メモリ確保失敗
				const std::size_t recyclable_index = recycable_index_and_tag & 0x00ffffff;//タグ削除
				if (recyclable_index >= POOL_SIZE)//再利用プールの先頭インデックス範囲外ならリトライ
				{
					recycable_index_and_tag = m_recyclableHead.load();//再利用プールの先頭インデックスを再取得
					continue;//リトライ
				}
			#ifdef USE_SAFE_ALLOC_LF_POOL_ALLOCATOR//【安全対策】※同じインデックスのアロケートを排他制御
				const std::size_t index_using = m_using[recyclable_index].fetch_add(1);//インデックスを使用中状態にする
				if (index_using != 0)//他のスレッドがインデックスを処理中ならリトライ
				{
					m_using[recyclable_index].fetch_sub(1);//インデックスの使用中状態を戻す
					--retry_count;
					if (retry_count == 0)//一定数のリトライごとにコンテキストスイッチ
					{
						retry_count = retry_max;//リトライ回数を初期状態に戻す
						std::this_thread::sleep_for(std::chrono::nanoseconds(0));//コンテキストスイッチ（ゼロスリープ）
					}
					recycable_index_and_tag = m_recyclableHead.load();//再利用プールのインデックスを再取得
					continue;//リトライ
				}
			#endif//USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
				recycable_t* recyclable_pool = reinterpret_cast<recycable_t*>(m_pool[recyclable_index]);//再利用プールの先頭を割り当て
				const std::size_t next_index_and_tag = recyclable_pool->m_next_index.load();//次の再利用プールのインデックスを取得

				//CAS操作①
			#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR//【安全対策】※スピンロックでCAS操作を保護
				m_lock.lock();//ロック取得
				const bool result = m_recyclableHead.compare_exchange_weak(recycable_index_and_tag, next_index_and_tag);//CAS操作
				m_lock.unlock();//ロック解除
				if (result)
			#else//USE_SAFE_CAS_LF_POOL_ALLOCATOR
				if (m_recyclableHead.compare_exchange_weak(recycable_index_and_tag, next_index_and_tag))//CAS操作
			#endif//USE_SAFE_CAS_LF_POOL_ALLOCATOR
				//【CAS操作の内容】
				//    if(m_recyclableHead == recyclable_index)//再利用プールの先頭インデックスを他のスレッドが書き換えていないか？
				//        m_recyclableHead = next;//再利用プールの先頭インデックスを次の再利用インデックスに変更（メモリ確保成功）
				//    else
				//        recycable_index_and_tag = m_recyclableHead;//再利用プールの先頭インデックスを再取得
				{
					recyclable_pool->m_next_index.store(DIRTY_INDEX);//再利用プールの連結インデックスを削除
				#ifndef USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
					m_using[recyclable_index].fetch_sub(1);//インデックスを使用中状態にする
				#endif//USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
				//	m_usingCount.fetch_add(1);//使用中の数を増やす（デバッグ用）
				//	m_allocCount[recyclable_index].fetch_add(1);//アロケート回数をカウントアップ（デバッグ用）
					return recyclable_pool;//メモリ確保成功
				}
				
		#ifdef USE_SAFE_ALLOC_LF_POOL_ALLOCATOR//【安全対策】※同じインデックスのアロケートを排他制御
				m_using[recyclable_index].fetch_sub(1);//インデックスの使用中状態を戻してリトライ
		#endif//USE_SAFE_ALLOC_LF_POOL_ALLOCATOR
			}
			return nullptr;//ダミー
		}
	}

private:
	//メモリ解放（共通処理）
	bool free(void* p, const std::size_t index)
	{
		const std::size_t tag = static_cast<std::size_t>(m_tag.fetch_add(1));//タグ取得
		const std::size_t index_and_tag = index | (tag << 24);//タグ付きインデックス作成
		std::size_t recycable_index_and_tag = m_recyclableHead.load();//再利用プールの先頭インデックスを取得
		while (true)
		{
			recycable_t* deleted_pool = reinterpret_cast<recycable_t*>(m_pool[index]);//解放されたメモリを参照
			deleted_pool->m_next_index.store(recycable_index_and_tag);//次の再利用プールのインデックスを保存
			
			//CAS操作②
		#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR//【安全対策】※スピンロックでCAS操作を保護
			m_lock.lock();//ロック取得
			const bool result = m_recyclableHead.compare_exchange_weak(recycable_index_and_tag, index_and_tag);//CAS操作
			m_lock.unlock();//ロック解除
			if (result)
		#else//USE_SAFE_CAS_LF_POOL_ALLOCATOR
			if (m_recyclableHead.compare_exchange_weak(recycable_index_and_tag, index_and_tag))//CAS操作
		#endif//USE_SAFE_CAS_LF_POOL_ALLOCATOR
			//【CAS操作の内容】
			//    if(m_recyclableHead == recycable_index_and_tag)//再利用プールの先頭インデックスを他のスレッドが書き換えていないか？
			//        m_recyclableHead = index_and_tag;//再利用プールの先頭インデックスを次のインデックスに変更（メモリ解放成功）
			//    else
			//        recycable_index_and_tag = m_recyclableHead;//再利用プールの先頭インデックスを再取得
			{
				m_using[index].fetch_sub(1);//インデックスを未使用状態にする
			//	m_usingCount.fetch_sub(1);//使用中の数を減らす（デバッグ用）
			//	m_freeCount[index].fetch_add(1);//フリー回数をカウントアップ（デバッグ用）
				return true;//メモリ解放成功
			}
		}
		return false;//ダミー
	}
	
	//ポインタをインデックスに変換
	std::size_t ptrToIndex(void* p)
	{
		const std::size_t index = (reinterpret_cast<char*>(p) - reinterpret_cast<char*>(m_pool)) / VALUE_SIZE;
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
		static_assert(sizeof(ObjType) <= VALUE_SIZE, "sizeof(ObjType) is too large.");
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)ObjType(args...);
	}
	value_type* newCopyObj(value_type& org)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(org);
	}
	value_type* newMoveObj(value_type&& org)
	{
		void* p = alloc();
		if (!p)
			return nullptr;
		return new(p)value_type(std::move(org));
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
	//	printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d, usingCount=%d\n", POOL_SIZE, VALUE_SIZE, m_vacantHead.load(), m_usingCount.load());
		printf("POOL_SIZE=%d, VALUE_SIZE=%d, emptyHead=%d\n", POOL_SIZE, VALUE_SIZE, m_vacantHead.load());
		printf("Using:\n");
		for (int index = 0; index < POOL_SIZE; ++index)
		{
			if (m_using[index].load() != 0)
			{
				printf("[%d]", index);
				if (m_using[index].load() != 1)
					printf("(using=%d)", m_using[index].load());
			//	printf("(leak=%d)", static_cast<int>(m_allocCount[index].load() - m_freeCount[index].load()));
				print_node(*reinterpret_cast<const value_type*>(m_pool[index]));
				printf("\n");
			}
		//	else
		//	{
		//		if (m_allocCount[index].load() != m_freeCount[index].load())
		//			printf("[%d](leak=%d)\n", index, static_cast<int>(m_allocCount[index].load() - m_freeCount[index].load()));
		//	}
		}
		printf("Recycable pool:\n");
		std::size_t recycable_index_and_tag = m_recyclableHead;
		while (recycable_index_and_tag != INVALID_INDEX)
		{
			const std::size_t recycable_index = recycable_index_and_tag & 0x00ffffff;
			const std::size_t tag = recycable_index_and_tag >> 24;
			printf(" [%d(tag=%d)]", recycable_index, tag);
			recycable_t* recycable_pool = reinterpret_cast<recycable_t*>(m_pool[recycable_index]);
			recycable_index_and_tag = recycable_pool->m_next_index.load();
		}
		printf("\n");
		printf("----------\n");
	}

public:
	//コンストラクタ
	lf_pool_allocator()
	{
		m_vacantHead.store(0);
		m_recyclableHead.store(INVALID_INDEX);
	//	m_usingCount.store(0);
		for (int i = 0; i < POOL_SIZE; ++i)
		{
			m_using[i].store(0);
		//	m_allocCount[i].store(0);
		//	m_freeCount[i].store(0);
		}
	}
	//デストラクタ
	~lf_pool_allocator()
	{}

private:
	//フィールド
	char m_pool[POOL_SIZE][VALUE_SIZE];//プールバッファ ※先頭に配置してクラスのアライメントと一致させる
	std::atomic<std::size_t> m_vacantHead;//空きプールの先頭インデックス
	std::atomic<std::size_t> m_recyclableHead;//再利用プールの先頭インデックス
	std::atomic<unsigned char> m_tag;//ABA問題対策用のタグ
	std::atomic<char> m_using[POOL_SIZE];//使用中インデックス（二重解放判定＆保険の排他制御用）  ※std::bitset使用不可
//	std::atomic<std::size_t> m_usingCount;//使用中の数（デバッグ用）※必須の情報ではない
//	std::atomic<std::size_t> m_allocCount[POOL_SIZE];//アロケート回数（デバッグ用）※必須の情報ではない
//	std::atomic<std::size_t> m_freeCount[POOL_SIZE];//フリー回数（デバッグ用）※必須の情報ではない
#ifdef USE_SAFE_CAS_LF_POOL_ALLOCATOR
	spin_lock m_lock;//CAS操作保護用のスピンロック
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
		stack_t* m_next;//次のノード
		value_type m_value;//値
		//コンストラクタ ※値の受け渡しはムーブコンストラクタを使用
		stack_t(value_type&& value) :
			m_value(std::move(value))
		{}
	};

public:
	//メソッド

	//プッシュ
	bool push(value_type&& value)
	{
	#ifdef USE_POOL_ALLOCATOR
		void* p = m_allocator.alloc();//新規ノードのメモリを確保
	#else//USE_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(stack_t), 16);//新規ノードのメモリを確保
	#endif//USE_POOL_ALLOCATOR
		if (!p)//メモリ確保失敗
			return false;//プッシュ失敗
		stack_t* new_node = new(p)stack_t(std::move(value));//新規ノードのコンストラクタ呼び出し
		std::lock_guard<normal_lock> lock(m_lock);//ロック（スコープロック）
		new_node->m_next = m_head;//新規ノードの次ノードに現在の先頭ノードをセット
		m_head = new_node;//先頭ノードを新規ノードにする
		return true;//プッシュ成功
	}
	bool push(value_type& value)
	{
		return push(std::move(value));//常にムーブ処理を適用
	}

	//ポップ
	bool pop(value_type& value)
	{
		std::lock_guard<normal_lock> lock(m_lock);//ロック（スコープロック）
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
	normal_lock m_lock;//ロックオブジェクト（ミューテックスorスピンロック）
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
		std::atomic<stack_ptr_t> m_next;//次のノード
		value_type m_value;//値
		//コンストラクタ ※値の受け渡しはムーブコンストラクタを使用
		stack_t(value_type&& value) :
			m_value(std::move(value))
		{}
	};

public:
	//メソッド

	//プッシュ
	bool push(value_type&& value)
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		void* p = m_allocator.alloc();//新規ノードのメモリを確保
	#else//USE_LF_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(stack_t), 16);//新規ノードのメモリを確保
	#endif//USE_LF_POOL_ALLOCATOR
		if (!p)//メモリ確保失敗
			return nullptr;//プッシュ失敗
		stack_t* new_node = new(p)stack_t(std::move(value));//新規ノードのコンストラクタ呼び出し
		new_node->m_next.store(m_head.load());//新規ノードの次ノードに現在の先頭ノードをセット
		stack_ptr_t new_node_tag_ptr;
		new_node_tag_ptr.setTagPtr(new_node, m_tag.fetch_add(1));//タグ付きポインタ生成
		while (true)
		{
			stack_ptr_t next_tag_ptr = new_node->m_next.load();//新規ノードの次ノードを取得

			//CAS操作①
		#ifdef USE_SAFE_CAS_LF_STACK//【安全対策】※スピンロックでCAS操作を保護
			m_lock.lock();//ロック取得
			const bool result = m_head.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr);//CAS操作
			m_lock.unlock();//ロック解除
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
		return false;//ダミー
	}
	bool push(value_type& value)
	{
		return push(std::move(value));//常にムーブ処理を適用
	}

	//ポップ
	bool pop(value_type& value)
	{
		stack_ptr_t head_tag_ptr = m_head.load();//先頭ノードを取得
		while (head_tag_ptr.isNotNull())
		{
			stack_t* head = head_tag_ptr;//タグ付きポインタからポインタを取得
			stack_ptr_t next_tag_ptr = head->m_next;//次のノードを取得

			//CAS操作②
		#ifdef USE_SAFE_CAS_LF_STACK//【安全対策】※スピンロックでCAS操作を保護
			m_lock.lock();//ロック取得
			const bool result = m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr);//CAS操作
			m_lock.unlock();//ロック解除
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
	spin_lock m_lock;//CAS操作保護用のスピンロック
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
		queue_t* m_next;//次のノード
		value_type m_value;//値
		//コンストラクタ ※値の受け渡しはムーブコンストラクタを使用
		queue_t(value_type&& value) :
			m_value(std::move(value))
		{}
		//デフォルトコンストラクタ（ダミー生成用）
		queue_t()
		{}
	};

public:
	//メソッド

	//エンキュー
	bool enqueue(value_type&& value)
	{
	#ifdef USE_POOL_ALLOCATOR
		void* p = m_allocator.alloc();//新規ノードのメモリを確保
	#else//USE_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(queue_t), 16);//新規ノードのメモリを確保
	#endif//USE_POOL_ALLOCATOR
		if (!p)//メモリ確保失敗
			return false;//エンキュー失敗
		queue_t* new_node = new(p)queue_t(std::move(value));//新規ノードのコンストラクタ呼び出し
		new_node->m_next = nullptr;//新規ノードの次ノードを初期化
		std::lock_guard<normal_lock> lock(m_lock);//ロック（スコープロック）
		m_tail->m_next = new_node;//末尾ノードの次ノードを新規ノードにする
		m_tail = new_node;//末尾ノードを新規ノードにする
		return true;//エンキュー成功
	}
	bool enqueue(value_type& value)
	{
		return enqueue(std::move(value));//常にムーブ処理を適用
	}

	//デキュー
	bool dequeue(value_type& value)
	{
		std::lock_guard<normal_lock> lock(m_lock);//ロック（スコープロック）
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
	normal_lock m_lock;//ロックオブジェクト（ミューテックスorスピンロック）
};

//--------------------------------------------------------------------------------
//ロックフリーキュークラス
//※論文に基づいていて実装: http://www.cs.rochester.edu/u/scott/papers/1996_PODC_queues.pdf
//　一部論文通りの実装と異なる
//    ⇒ 変更点①：enqueu:E9:  if CAS(&tail.ptr->next, next, <node, ...>)
//                                     ↓
//                             if CAS(&Q->Tail.ptr->next, next, <node, ...>)
//       変更点②：enqueu:E7:  if tail == Q->Tail
//                        E15: endif
//                               ↓
//                              削除
//       変更点③：dequeu:D5:  if head == Q->Head
//                        D17: endif
//                               ↓
//                              削除
//       変更点④：ポインタへのタグ付けは新規ノード生成時のみ適用
//                 ※32bitタグ＋32bitポインタによる64bitのタグ付きポインタとすることで、
//                   タグが巡回して競合する危険性がほとんどない状態に
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
		std::atomic<queue_ptr_t> m_next;//次のノード
		value_type m_value;//値
		//コンストラクタ ※値の受け渡しはムーブコンストラクタを使用
		queue_t(value_type&& value) :
			m_value(std::move(value))
		{}
		//デフォルトコンストラクタ（ダミー生成用）
		queue_t()
		{}
	};

public:
	//メソッド
	
	//エンキュー
	bool enqueue(value_type&& value)
	{
	#ifdef USE_LF_POOL_ALLOCATOR
		void* p = m_allocator.alloc();//新規ノードのメモリを確保
	#else//USE_LF_POOL_ALLOCATOR
		void* p = _aligned_malloc(sizeof(queue_t), 16);//新規ノードのメモリを確保
	#endif//USE_LF_POOL_ALLOCATOR
		if (!p)//メモリ確保失敗
			return false;//エンキュー失敗
		queue_t* new_node = new(p)queue_t(std::move(value));//新規ノードのコンストラクタ呼び出し
		queue_ptr_t new_node_tag_ptr;
		new_node_tag_ptr.setTagPtr(new_node, m_tag.fetch_add(1));//タグ付きポインタ生成
		queue_ptr_t null_tag_ptr;
		null_tag_ptr.setTagPtr(nullptr, 0);//タグ付きヌルポインタ
		new_node->m_next.store(null_tag_ptr);//新規ノードの次ノードを初期化
		queue_ptr_t tail_tag_ptr = null_tag_ptr;
		while (true)
		{
			tail_tag_ptr = m_tail.load();//末尾ノードを取得
			queue_t* tail = tail_tag_ptr;
			queue_ptr_t next_tag_ptr = tail->m_next.load();//末尾ノードの次ノードを取得
			//if (tail_tag_ptr == m_tail.load())//このタイミングで他のスレッドが末尾を書き換えていないか？　←削除（E7,E15）
			{
				if (next_tag_ptr.isNull())//末尾ノードの次ノードが末端（nullptr）か？
				{
					//CAS操作①
				#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護　←変更（E9）
					m_lock.lock();//ロック取得
					const bool result = m_tail.load().ptr()->m_next.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr);//CAS操作
					m_lock.unlock();//ロック解除
					if (result)
				#else//USE_SAFE_CAS_LF_QUEUE
					if (m_tail.load().ptr()->m_next.compare_exchange_weak(next_tag_ptr, new_node_tag_ptr))//CAS操作
				#endif//USE_SAFE_CAS_LF_QUEUE
					//【CAS操作の内容】
					//    if(tail_tag_ptr->m_next == next_tag_ptr)//末尾ノードの次ノードを他のスレッドが書き換えていないか？
					//        tail_tag_ptr->m_next = new_node_tag_ptr;//末尾ノードの次ノードに新規ノードをセット（エンキュー成功）
					{
						//CAS操作②
					#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
						m_lock.lock();//ロック取得
						m_tail.compare_exchange_strong(tail_tag_ptr, new_node_tag_ptr);//CAS操作
						m_lock.unlock();//ロック解除
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
					//CAS操作③：つじつま合わせ処理 ※CAS操作②が失敗する可能性があるため、この処理が必要
				#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
					m_lock.lock();//ロック取得
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS操作
					m_lock.unlock();//ロック解除
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
	bool enqueue(value_type& value)
	{
		return enqueue(std::move(value));//常にムーブ処理を適用
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
			//if (head_tag_ptr == m_head.load())//このタイミングで他のスレッドが先頭を書き換えていないか？　←削除（D5,D17）
			{
				if (head_tag_ptr == tail_tag_ptr)//先頭ノードと末尾ノードが同じか？（一つもキューイングされていない状態か？）
				{
					if (next_tag_ptr.isNull())//本当にキューがないか？（tail取得とnext取得の間に、他のスレッドがキューイングしている可能性がある）
						return false;//デキュー失敗
					
					//CAS操作④：つじつま合わせ処理 ※エンキューのCAS操作②が失敗する可能性があるため、この処理が必要
				#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
					m_lock.lock();//ロック取得
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS操作
					m_lock.unlock();//ロック解除
				#else//USE_SAFE_CAS_LF_QUEUE
					m_tail.compare_exchange_weak(tail_tag_ptr, next_tag_ptr);//CAS操作
				#endif//USE_SAFE_CAS_LF_QUEUE
					//【CAS操作の内容】
					//    if(m_tail == tail_tag_ptr)//末尾ノードを他のスレッドが書き換えていないか？
					//        m_tail = next_tag_ptr;//末尾ノードを次ノードに変更
				}
				else
				{
					//CAS操作⑤
				#ifdef USE_SAFE_CAS_LF_QUEUE//【安全対策】※スピンロックでCAS操作を保護
					m_lock.lock();//ロック取得
					const bool result = m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr);//CAS操作
					m_lock.unlock();//ロック解除
					if (result)
				#else//USE_SAFE_CAS_LF_QUEUE
					if (m_head.compare_exchange_weak(head_tag_ptr, next_tag_ptr))//CAS操作
				#endif//USE_SAFE_CAS_LF_QUEUE
					//【CAS操作の内容】
					//    if(m_head == head_tag_ptr)//先頭ノードの次ノードを他のスレッドが書き換えていないか？
					//        m_head = next_tag_ptr;//先頭ノードを次ノードに変更（これより次ノードがダミーノード扱いになる）（デキュー成功）
					{
						queue_t* top = next_tag_ptr;//新しい先頭ノードから値を取り出す
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
	spin_lock m_lock;//CAS操作保護用のスピンロック
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
bool pushNormal(data_t& data)
{
	return s_stack.push(data);//スタックにプッシュ
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
bool pushLockFree(data_t& data)
{
	return s_lfStack.push(data);//スタックにプッシュ
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
bool enqueueNormal(data_t& value)
{
	return s_queue.enqueue(value);
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
bool enqueueLockFree(data_t& value)
{
	return s_lfQueue.enqueue(value);
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
	
	//プールアロケータのテスト（共通処理）
	auto test_pool_allocator = [](const char* caption, std::function<data_t*()> alloc, std::function<bool(data_t*)> free)
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[%s:START]\n", caption);
		printf("*Test count                     = %d\n", TEST_COUNT);
		printf("*Allocate and free test threads = %d\n", 1);
		printf("*Memory pool size               = %d\n", TEST_POOL_SIZE);
		const auto begin_time = std::chrono::system_clock::now();
		pool_allocator<data_t, TEST_POOL_SIZE> allocator;
		data_t* data[TEST_POOL_SIZE + 1] = { 0 };
		int count = 0;
		while(true)
		{
			int num = 0;
			while (true)
			{
				data_t*& data_p = data[num++];
				data_p = alloc();
				if (!data_p)
					break;
				data_p->m_temp = 0;
				data_p->m_value = count++;
				if (count > TEST_COUNT)
					break;
			}
			for (int i = 0; i < num; ++i)
			{
				data_t* data_p = data[i];
				if (data_p)
					free(data_p);
			}
			if (count > TEST_COUNT)
				break;
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("[%s:END] elapsed_time=%.9llf sec\n", caption, elapsed_time);
		printf("--------------------------------------------------------------------------------\n");
	};

	//スタック／キューのテスト（共通処理）
	auto test_stack_queue = [](const char* caption, std::function<bool(data_t&&)> push, std::function<bool(data_t&)> pop)
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[%s:START]\n", caption);
		printf("*Test count                = %d\n", TEST_COUNT);
		printf("*Push/Enqueue test threads = %d\n", 1);
		printf("*Pop/Dequeue  test threads = %d\n", 1);
		printf("*Memory pool size          = %d\n", TEST_POOL_SIZE);
		const auto begin_time = std::chrono::system_clock::now();
		int count = 0;
		while (true)
		{
			int num = 0;
			while (true)
			{
				const bool result = push({ count++ });
				if (!result)
				{
					--count;
					break;
				}
				if (count > TEST_COUNT)
					break;
			}
			while (true)
			{
				data_t data;
				const bool result = pop(data);
				if (!result)
					break;
			}
			if (count > TEST_COUNT)
				break;
		}
		const auto end_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("[%s:END] elapsed_time=%.9llf sec\n", caption, elapsed_time);
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
		test_stack_queue("Normal Stack", push, pop);

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
		test_stack_queue("Lock-Free Stack", push, pop);

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
		test_stack_queue("Normal Queue", push, pop);

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
		test_stack_queue("Lock-Free Queue", push, pop);

#ifdef ENABLE_TEST_PRINT_DEBUG_INFO
		s_lfQueue.printDebugInfo(debug_print_info);
#endif//ENABLE_TEST_PRINT_DEBUG_INFO
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
		printf("[%s:END] elapsed_time=%.9llf sec\n", caption, elapsed_time);
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
		printf("[%s:END] elapsed_time=%.9llf sec\n", caption, elapsed_time);
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
