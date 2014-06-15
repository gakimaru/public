//--------------------------------------------------------------------------------
//動的配列テスト用設定とコンパイラスイッチ
static const int TEST_DATA_NUM = 10;//大量登録テストデータの登録数
//static const int TEST_DATA_NUM = 10000000;//大量登録テストデータの登録数

#define PRINT_TEST_DATA_DETAIL//テストデータの詳細タを表示する場合は、このマクロを有効化する
//#define TEST_DATA_WATCH_CONSTRUCTOR//コンストラクタ／デストラクタ／代入演算子の動作を確認する場合、このマクロを有効化する

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------
//自作ロッククラス
//--------------------------------------------------------------------------------

#include <atomic>//C++11 std::atomic用
#include <thread>//C++11 std::this_thread::sleep_for用
#include <chrono>//C++11 std::chrono::milliseconds用

//--------------------------------------------------------------------------------
//スピンロック
//--------------------------------------------------------------------------------

//----------------------------------------
//スピンロッククラス
//※サイズは4バイト(std::atomic_flag一つ分のサイズ)
class spin_lock
{
public:
	//定数
	static const int DEFAULT_SPIN_COUNT = 1000;//スピンロックカウントのデフォルト値
public:
	//ロック取得
	void lock(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (true)
		{
			if (!m_lock.test_and_set())
				return;
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//ロック取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	inline bool try_lock()
	{
		return m_lock.test_and_set() == false;
	}
	//ロック解放
	inline void unlock()
	{
		m_lock.clear();
	}
public:
	//コンストラクタ
	inline spin_lock()
	{
		m_lock.clear();
	}
	//デストラクタ
	inline ~spin_lock()
	{}
private:
	//フィールド
	std::atomic_flag m_lock;//ロック用フラグ
};

//----------------------------------------
//スピンロッククラス（軽量版）
//※サイズは1バイト
//※spin_lockの方が速い
class lw_spin_lock
{
public:
	//ロック取得
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (true)
		{
			bool prev = false;
			if (!m_lock.compare_exchange_weak(prev, true))
				return;
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//ロック取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	inline bool try_lock()
	{
		bool prev = false;
		return m_lock.compare_exchange_weak(prev, true) == false;
	}
	//ロック解放
	inline void unlock()
	{
		m_lock.store(false);
	}
public:
	//コンストラクタ
	inline lw_spin_lock()
	{
		m_lock.store(false);//ロック用フラグ
	}
	//デストラクタ
	inline ~lw_spin_lock()
	{}
private:
	//フィールド
	std::atomic_bool m_lock;//ロック用フラグ
};

//----------------------------------------
//共有（リード・ライト）スピンロッククラス
//※サイズは4バイト
//※排他ロック（ライトロック）を優先する
//※読み込み操作（共有ロック）が込み合っている途中で割り込んで
//　書き込み操作（排他ロック）を行いたい時に用いる
//※排他ロックが常に最優先されるわけではない。
//　共有ロックがロックを開放する前に排他ロックがロックを
//　取得することを許可する仕組みで実装する。その場合、
//　共有ロックが全て解放されるのを待ってから処理を続行する。
//　そのため、別の排他ロックが待ち状態になっても、
//　共有ロックより先にロックを取得することは保証しない。
class shared_spin_lock
{
public:
	//定数
	static const int DEFAULT_COUNTER = 0x01000000;//ロックが取得されていない時のデフォルトのカウンタ

public:
	//共有ロック（リードロック）取得
	void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(1);//カウンタを更新
			if (lock_counter > 0)
				return;//ロック取得成功
			m_lockCounter.fetch_add(1);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//共有ロック（リードロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	bool try_lock_shared()
	{
		const int lock_counter = m_lockCounter.fetch_sub(1);//カウンタを更新
		if (lock_counter >= 0)
			return true;//ロック取得成功
		m_lockCounter.fetch_add(1);//カウンタを戻す
		return false;//ロック取得失敗
	}
	//排他ロック（ライトロック）取得
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(DEFAULT_COUNTER);//カウンタを更新
			if (lock_counter == DEFAULT_COUNTER)
				return;//ロック取得成功
			if (lock_counter > 0)	//他が排他ロックを取得していないので、現在の共有ロックが全て解放されるのを待つ
			{						//※カウンタを更新したままなので、後続の共有ロック／排他ロックは取得できない。
				while (m_lockCounter.load() != 0)//カウンタが0になるのを待つ
				{
					if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
					{
						std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
						spin_count_now = spin_count;
					}
				}
				return;//ロック取得成功
			}
			m_lockCounter.fetch_add(DEFAULT_COUNTER);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//排他ロック（ライトロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	bool try_lock()
	{
		const int lock_counter = m_lockCounter.fetch_sub(DEFAULT_COUNTER);//カウンタを更新
		if (lock_counter == DEFAULT_COUNTER)
			return true;//ロック取得成功
		m_lockCounter.fetch_add(DEFAULT_COUNTER);//カウンタを戻す
		return false;//ロック取得失敗
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		m_lockCounter.fetch_add(1);//カウンタを戻す
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		m_lockCounter.fetch_add(DEFAULT_COUNTER);//カウンタを戻す
	}
public:
	//コンストラクタ
	inline shared_spin_lock() :
		m_lockCounter(DEFAULT_COUNTER)
	{}
	//デストラクタ
	inline ~shared_spin_lock()
	{}
private:
	//フィールド
	std::atomic<int> m_lockCounter;//ロックカウンタ
};

//----------------------------------------
//共有（リード・ライト）スピンロッククラス（軽量版）
//※サイズは4バイト
//※排他ロック（ライトロック）を優先しない
//※読み込み操作（共有ロック）が込み合っていると、
//　書き込み操作（排他ロック）が待たされるので注意。
class lw_shared_spin_lock
{
public:
	//共有ロック（リードロック）取得
	void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(1);//カウンタを更新
			if (lock_counter > 0)
				return;//ロック取得成功
			m_lockCounter.fetch_add(1);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//共有ロック（リードロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	bool try_lock_shared()
	{
		const int lock_counter = m_lockCounter.fetch_sub(1);//カウンタを更新
		if (lock_counter >= 0)
			return true;//ロック取得成功
		m_lockCounter.fetch_add(1);//カウンタを戻す
		return false;//ロック取得失敗
	}
	//排他ロック（ライトロック）取得
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(shared_spin_lock::DEFAULT_COUNTER);//カウンタを更新
			if (lock_counter == shared_spin_lock::DEFAULT_COUNTER)
				return;//ロック取得成功
			m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//排他ロック（ライトロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	bool try_lock()
	{
		const int lock_counter = m_lockCounter.fetch_sub(shared_spin_lock::DEFAULT_COUNTER);//カウンタを更新
		if (lock_counter == shared_spin_lock::DEFAULT_COUNTER)
			return true;//ロック取得成功
		m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//カウンタを戻す
		return false;//ロック取得失敗
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		m_lockCounter.fetch_add(1);//カウンタを戻す
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//カウンタを戻す
	}
public:
	//コンストラクタ
	inline lw_shared_spin_lock() :
		m_lockCounter(shared_spin_lock::DEFAULT_COUNTER)
	{}
	//デストラクタ
	inline ~lw_shared_spin_lock()
	{}
private:
	//フィールド
	std::atomic<int> m_lockCounter;//ロックカウンタ
};

//----------------------------------------
//非共有（排他）スピンロッククラス
//※サイズは4バイト
//※共有ロッククラスと同一のインターフェースで、
//　共有ロックを行わないクラス
//※共有ロックのヘルパークラスやロックガードを使用する処理に対して、
//　完全な排他制御を行いたい時に使用する。
class unshared_spin_lock
{
public:
	//共有ロック（リードロック）取得
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//共有ロック（リードロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	inline bool try_lock_shared()
	{
		return m_lock.try_lock();
	}
	//排他ロック（ライトロック）取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//排他ロック（ライトロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	inline bool try_lock()
	{
		return m_lock.try_lock();
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		m_lock.unlock();
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//コンストラクタ
	unshared_spin_lock() :
		m_lock()
	{}
	//デストラクタ
	~unshared_spin_lock()
	{}
private:
	//フィールド
	spin_lock m_lock;//ロックオブジェクト
};

//--------------------------------------------------------------------------------
//ダミーロック
//--------------------------------------------------------------------------------

//----------------------------------------
//ダミーロッククラス
//※spin_lockやstd::mutexと同様のロックインターフェースを持つが、実際には何もしないクラス
class dummy_lock
{
public:
	//ロック取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//何もしない
	}
	//ロック取得を試行
	inline bool try_lock()
	{
		//何もしない
		return true;
	}
	//ロック解放
	inline void unlock()
	{
		//何もしない
	}
public:
	//コンストラクタ
	inline dummy_lock()
	{}
	//デストラクタ
	~dummy_lock()
	{}
};

//----------------------------------------
//ダミー共有（リード・ライト）ロッククラス
//※shared_spin_lockやstd::shared_lockと同様のロックインターフェースを持つが、実際には何もしないクラス
class dummy_shared_lock
{
public:
	//共有ロック（リードロック）取得
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//何もしない
	}
	//共有ロック（リードロック）取得を試行
	inline bool try_lock_shared()
	{
		//何もしない
		return true;
	}
	//排他ロック（ライトロック）取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//何もしない
	}
	//排他ロック（ライトロック）取得を試行
	inline bool try_lock()
	{
		//何もしない
		return true;
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		//何もしない
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		//何もしない
	}
public:
	//コンストラクタ
	inline dummy_shared_lock()
	{}
	//デストラクタ
	~dummy_shared_lock()
	{}
};

//--------------------------------------------------------------------------------
//ロックヘルパー
//--------------------------------------------------------------------------------

//----------------------------------------
//ロックヘルパークラス
//※実装を隠ぺいしてロックを操作するためのヘルパークラス
template<class T>
class lock_helper
{
public:
	typedef T lock_type;//ロックオブジェクト型
public:
	//メソッド

	//ロック取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//ロック取得を試行
	inline bool try_lock()
	{
		return m_lock.try_lock();
	}
	//ロック解放
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//コンストラクタ
	inline lock_helper(lock_type& lock) :
		m_lock(lock)
	{}
	//デストラクタ
	inline ~lock_helper()
	{}
private:
	//フィールド
	lock_type& m_lock;//ロックオブジェクトの参照
};

//----------------------------------------
//共有（リード・ライト）ロックヘルパークラス
//※実装を隠ぺいして共有（リード・ライト）ロックを操作するためのヘルパークラス
template<class T>
class shared_lock_helper
{
public:
	typedef T lock_type;//ロックオブジェクト型
public:
	//メソッド

	//共有ロック（リードロック）取得
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock_shared(spin_count);
	}
	//共有ロック（リードロック）取得を試行
	inline bool try_lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		return m_lock.try_lock_shared(spin_count);
	}
	//排他ロック（ライトロック）取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//排他ロック（ライトロック）取得を試行
	inline bool try_lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		return m_lock.try_lock(spin_count);
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		m_lock.unlock_shared();
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//コンストラクタ
	inline shared_lock_helper(lock_type& lock) :
		m_lock(lock)
	{}
	//デストラクタ
	inline ~shared_lock_helper()
	{}
private:
	//フィールド
	lock_type& m_lock;//ロックオブジェクトの参照
};

//--------------------------------------------------------------------------------
//ロックガード（スコープロック）
//--------------------------------------------------------------------------------

//----------------------------------------
//ロックガードクラス（スコープロック）
//※スコープロックで通常ロックもしくは排他ロック（ライトロック）のロック取得と解放を行う
template<class T>
class lock_guard
{
public:
	typedef T lock_type;//ロックオブジェクト型
public:
	//コンストラクタ
	inline lock_guard(lock_type& lock, const int spin_count = spin_lock::DEFAULT_SPIN_COUNT) :
		m_lock(lock)
	{
		m_lock.lock(spin_count);
	}
	//デストラクタ
	inline ~lock_guard()
	{
		m_lock.unlock();
	}
private:
	//フィールド
	lock_type& m_lock;//ロックオブジェクトの参照
};

//----------------------------------------
//共有（リード・ライト）ロックガードクラス（スコープロック）
//※スコープロックで共有ロック（リードロック）のロック取得と解放を行う
template<class T>
class shared_lock_guard
{
public:
	typedef T lock_type;//ロックオブジェクト型
public:
	//コンストラクタ
	inline shared_lock_guard(lock_type& lock, const int spin_count = spin_lock::DEFAULT_SPIN_COUNT) :
		m_lock(lock)
	{
		m_lock.lock_shared(spin_count);
	}
	//デストラクタ
	inline ~shared_lock_guard()
	{
		m_lock.unlock_shared();
	}
private:
	//フィールド
	lock_type& m_lock;//ロックオブジェクトの参照
};

//--------------------------------------------------------------------------------
//ソートアルゴリズム
//--------------------------------------------------------------------------------

#include <algorithm>//C++11 std::move用
#include <memory.h>//memcpy用

//========================================
//ソート／探索補助処理
//========================================

//----------------------------------------
//ソート用標準プレディケート関数オブジェクト：less
//※対象オブジェクトが operator<に対応している必要あり
template<typename T>
struct less{
	inline bool operator()(const T& val1, const T& val2) const
	{
		return val1 < val2;
	}
};
//----------------------------------------
//線形探索用標準プレディケート関数オブジェクト：eqal_to
//※対象オブジェクトが operator==に対応している必要あり
template<typename T>
struct equal_to{
	template<typename V>
	inline bool operator()(const T& val1, const V& val2) const
	{
		return val1 == val2;
	}
};
//----------------------------------------
//二分探索用標準比較関数オブジェクト：compare_to
//※対象オブジェクトが operator==, operator<に対応している必要あり
template<typename T>
struct compare_to{
	template<typename V>
	inline int operator()(const T& val1, const V& val2) const
	{
		if (val1 == val2)
			return 0;
		else if (val1 < val2)
			return 1;
		else//if (val1 > val2)
			return -1;
	}
};

//----------------------------------------
//比較ソート処理オーバーロード関数用マクロ
//※プレディケート関数指定版
#define sortFuncSetByUserPredicate(func_name) \
	template<class T, std::size_t N, class PREDICATE> \
	inline std::size_t func_name(T(&array)[N], PREDICATE predicate) \
	{ \
		return func_name(array, N, predicate); \
	} \
	template<class T, class PREDICATE> \
	inline std::size_t func_name(T* begin, T* end, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(begin, size, predicate); \
	} \
	template<class ITERATOR, class PREDICATE> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(&begin[0], size, predicate); \
	} \
	template<class CONTAINER, class PREDICATE> \
	inline std::size_t func_name(CONTAINER& con, PREDICATE predicate) \
	{ \
		std::size_t size = con.size(); \
		return size == 0 ? 0 : func_name(&(con.at(0)), size, predicate); \
	}
//※標準プレディケート関数使用版
#define sortFuncSetByDefaultPredicate(func_name) \
	template<class T> \
	inline std::size_t func_name(T* array, const std::size_t size) \
	{ \
		return func_name(array, size, less<T>()); \
	} \
	template<class T, std::size_t N> \
	inline std::size_t func_name(T(&array)[N]) \
	{ \
		return func_name(array, less<T>()); \
	} \
	template<class T> \
	inline std::size_t func_name(T* begin, T* end) \
	{ \
		return func_name(begin, end, less<T>()); \
	} \
	template<class ITERATOR> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end) \
	{ \
		return func_name(begin, end, less<typename ITERATOR::value_type>()); \
	} \
	template<class CONTAINER> \
	inline std::size_t func_name(CONTAINER& con) \
	{ \
		return func_name(con, less<typename CONTAINER::value_type>()); \
	}
#define sortFuncSet(func_name) \
	sortFuncSetByUserPredicate(func_name) \
	sortFuncSetByDefaultPredicate(func_name)

//----------------------------------------
//非比較ソート処理オーバーロード関数用マクロ
//※キー取得用関数オブジェクト指定版
#define distributedSortFuncSetByUserFunctor(func_name) \
	template<class T, std::size_t N, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(T(&array)[N], GET_KEY_FUNCTOR get_key_functor) \
	{ \
		return func_name(array, N, get_key_functor); \
	} \
	template<class T, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(T* begin, T* end, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(begin, size, get_key_functor); \
	} \
	template<class ITERATOR, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(&begin[0], size, get_key_functor); \
	} \
	template<class CONTAINER, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(CONTAINER& con, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		std::size_t size = con.size(); \
		return size == 0 ? 0 : func_name(&(con.at(0)), size, get_key_functor); \
	}
#define distributedSortFuncSet(func_name) \
	distributedSortFuncSetByUserFunctor(func_name)

//----------------------------------------
//探索処理オーバーロード関数用マクロ
#define searchFuncSetByUserFunc(func_name) \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T* array, const std::size_t size, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(const_cast<T*>(array), size, predicate_or_comparison); \
	} \
	template<class T, std::size_t N, class PREDICATE_OR_COMPARISON> \
	inline T* func_name(T(&array)[N], PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(array, N, predicate_or_comparison); \
	} \
	template<class T, std::size_t N, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T(&array)[N], PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(const_cast<T*>(array), N, predicate_or_comparison); \
	} \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline T* func_name(T* begin, T* end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(begin, size, predicate_or_comparison); \
	} \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T* begin, const T* end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, predicate_or_comparison); \
	} \
	template<class ITERATOR, class PREDICATE_OR_COMPARISON> \
	inline typename ITERATOR::value_type* func_name(ITERATOR& begin, ITERATOR& end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(&begin[0], size, predicate_or_comparison); \
	} \
	template<class ITERATOR, class PREDICATE_OR_COMPARISON> \
	inline const typename ITERATOR::value_type* func_name(const ITERATOR& begin, const ITERATOR& end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, predicate_or_comparison); \
	} \
	template<class CONTAINER, class PREDICATE_OR_COMPARISON> \
	inline typename CONTAINER::value_type* func_name(CONTAINER& con, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = con.size(); \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, predicate_or_comparison); \
	} \
	template<class CONTAINER, class PREDICATE_OR_COMPARISON> \
	inline const typename CONTAINER::value_type* func_name(const CONTAINER& con, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = con.size(); \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, predicate_or_comparison); \
	}
//※探索値指定版：プレディケート関数と値で比較
#define searchFuncSetPredicateAndValue(func_name) \
	template<class T, typename V, class PREDICATE> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(array, size, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _equal); \
	} \
	template<class T, std::size_t N, typename V, class PREDICATE> \
	inline T* func_name##Value(T(&array)[N], const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(array, N, _equal); \
	} \
	template<class T, std::size_t N, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T(&array)[N], const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline T* func_name##Value(T* begin, T* end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _equal); \
	} \
	template<class ITERATOR, typename V, class PREDICATE> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const typename ITERATOR::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _equal); \
	} \
	template<class ITERATOR, typename V, class PREDICATE> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const typename ITERATOR::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _equal); \
	} \
	template<class CONTAINER, typename V, class PREDICATE> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value, &predicate](const typename CONTAINER::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _equal); \
	} \
	template<class CONTAINER, typename V, class PREDICATE> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value, &predicate](const typename CONTAINER::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _equal); \
	}
//※探索値指定版：標準のプレディケート関数と値で比較
#define searchFuncSetByDefaultPredicateAndValue(func_name) \
	template<class T, typename V> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value) \
	{ \
		auto _equal = [&value](T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(array, size, _equal); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _equal); \
	} \
	template<class T, std::size_t N, typename V> \
	inline T* func_name##Value(T(&array)[N], const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(array, N, _equal); \
	} \
	template<class T, std::size_t N, typename V> \
	inline const T* func_name##Value(const T(&array)[N], const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _equal); \
	} \
	template<class T, typename V> \
	inline T* func_name##Value(T* begin, T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _equal); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _equal); \
	} \
	template<class ITERATOR, typename V> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const typename ITERATOR::value_type& val1) -> bool { return equal_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _equal); \
	} \
	template<class ITERATOR, typename V> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const typename ITERATOR::value_type& val1) -> bool { return equal_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _equal); \
	} \
	template<class CONTAINER, typename V> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value](const typename CONTAINER::value_type& val1) -> bool { return equal_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _equal); \
	} \
	template<class CONTAINER, typename V> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value](const typename CONTAINER::value_type& val1) -> bool { return equal_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _equal); \
	}
#define searchFuncSetByPredicate(func_name) \
	searchFuncSetByUserFunc(func_name) \
	searchFuncSetPredicateAndValue(func_name) \
	searchFuncSetByDefaultPredicateAndValue(func_name)
//※探索値指定版：比較関数と値で比較
#define searchFuncSetByComparisonAndValue(func_name) \
	template<class T, typename V, class COMPARISON> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](T& val1) -> int { return comparison(val1, value); }; \
		return func_name(array, size, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _comparison); \
	} \
	template<class T, std::size_t N, typename V, class COMPARISON> \
	inline T* func_name##Value(T(&array)[N], const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(array, N, _comparison); \
	} \
	template<class T, std::size_t N, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T(&array)[N], const V &value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline T* func_name##Value(T* begin, T* end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _comparison); \
	} \
	template<class ITERATOR, typename V, class COMPARISON> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const typename ITERATOR::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _comparison); \
	} \
	template<class ITERATOR, typename V, class COMPARISON> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const typename ITERATOR::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _comparison); \
	} \
	template<class CONTAINER, typename V, class COMPARISON> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value, &comparison](const typename CONTAINER::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _comparison); \
	} \
	template<class CONTAINER, typename V, class COMPARISON> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value, &comparison](const typename CONTAINER::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _comparison); \
	}
//※探索値指定版：標準比較関数と値で比較
#define searchFuncSetByDefaultComparisonAndValue(func_name) \
	template<class T, typename V> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value) \
	{ \
		auto _comparison = [&value](T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(array, size, _comparison); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _comparison); \
	} \
	template<class T, std::size_t N, typename V> \
	inline T* func_name##Value(T(&array)[N], const V& value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(array, N, _comparison); \
	} \
	template<class T, std::size_t N, typename V> \
	inline const T* func_name##Value(const T(&array)[N], const V &value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _comparison); \
	} \
	template<class T, typename V> \
	inline T* func_name##Value(T* begin, T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _comparison); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _comparison); \
	} \
	template<class ITERATOR, typename V> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const typename ITERATOR::value_type& val1) -> int { return compare_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _comparison); \
	} \
	template<class ITERATOR, typename V> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const typename ITERATOR::value_type& val1) -> int { return compare_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _comparison); \
	} \
	template<class CONTAINER, typename V> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value](const typename CONTAINER::value_type& val1) -> int { return compare_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _comparison); \
	} \
	template<class CONTAINER, typename V> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value](const typename CONTAINER::value_type& val1) -> int { return compare_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _comparison); \
	}
#define searchFuncSetByComparison(func_name) \
	searchFuncSetByUserFunc(func_name) \
	searchFuncSetByComparisonAndValue(func_name) \
	searchFuncSetByDefaultComparisonAndValue(func_name)

//----------------------------------------
//整列状態確認
template<class T, class PREDICATE>
inline std::size_t calcUnordered(const T* array, const std::size_t size, PREDICATE predicate)
{
	std::size_t unordered = 0;
	const T* prev = array;
	const T* now = prev + 1;
	for (std::size_t i = 1; i < size; ++i, ++now, ++prev)
	{
		if (predicate(*now, *prev))
			++unordered;
	}
	return unordered;
}
sortFuncSet(calcUnordered);

//----------------------------------------
//データの入れ替え
template<class T>
struct _swapArithmetic{
	inline static void exec(T& val1, T& val2)
	{
		T tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapArithmetic<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		T* tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapObjects{
	inline static void exec(T& val1, T& val2)
	{
	#if 1//ムーブコンストラクタとムーブオペレータを使用して入れ替え（#include <utility> の std::swap() と同じ）
		T tmp = std::move(val2);
		val2 = std::move(val1);
		val1 = std::move(tmp);
	#else//コンストラクタ／オペレータの呼び出しを避けて単純なメモリコピー
		char tmp[sizeof(T)];
		memcpy(tmp, &val2, sizeof(T));
		memcpy(&val2, &val1, sizeof(T));
		memcpy(&val1, tmp, sizeof(T));
	#endif
	}
};
template<class T>
struct _swapObjects<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		_swapArithmetic<T*>::exec(val1, val2);
	}
};
//データ入れ替え関数（直接使用する関数）
template<class T>
inline void swapValues(T& val1, T& val2)
{
	std::conditional<std::is_arithmetic<T>::value,
		_swapArithmetic<T>,
		_swapObjects<T>
	>::type::exec(val1, val2);
}

//----------------------------------------
//データのローテーション
template<class T>
struct _rotateArithmetic{
	inline static void exec(T* val1, T* val2, int step)
	{
		T tmp;
		tmp = *val2;
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			*val2 = *val2_prev;
			val2 = val2_prev;
		}
		*val1 = tmp;
	}
};
template<class T>
struct _rotateArithmetic<T*>{
	inline static void exec(T** val1, T** val2, int step)
	{
		T* tmp;
		tmp = *val2;
		while (val1 != val2)
		{
			T** val2_prev = val2 - step;
			*val2 = *val2_prev;
			val2 = val2_prev;
		}
		*val1 = tmp;
	}
};
template<class T>
struct _rotateObjects{
	inline static void exec(T* val1, T* val2, int step)
	{
	#if 1//ムーブコンストラクタとムーブオペレータを使用して入れ替え
		T tmp = std::move(*val2);
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			*val2 = std::move(*val2_prev);
			val2 = val2_prev;
		}
		*val1 = std::move(tmp);
	#else//コンストラクタ／オペレータの呼び出しを避けて単純なメモリコピー
		char tmp[sizeof(T)];
		memcpy(tmp, val2, sizeof(T));
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			memcpy(val2, val2_prev, sizeof(T));
			val2 = val2_prev;
		}
		memcpy(val1, tmp, sizeof(T));
	#endif
	}
};
template<class T>
struct _rotateObjects<T*>{
	inline static void exec(T** val1, T** val2, int step)
	{
		_rotateArithmetic<T*>::exec(val1, val2, step);
	}
};
//データローテーション関数（直接使用する関数）
template<class T>
inline void rotateValues(T* val1, T* val2, int step)
{
	std::conditional<std::is_arithmetic<T>::value,
		_rotateArithmetic<T>,
		_rotateObjects<T>
	>::type::exec(val1, val2, step);
}

//----------------------------------------
//イテレータの差（要素数）を返す
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::input_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin < end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::output_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin < end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::forward_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin < end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::bidirectional_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin < end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::random_access_iterator_tag)
{
	return end - begin;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end)
{
	typename ITERATOR::iterator_category category;
	return iteratorDifference(begin, end, category);
}

//----------------------------------------
//for-each
template<class ITERATOR, class FUNCTOR>
void forEach(ITERATOR begin, ITERATOR end, FUNCTOR functor)
{
	for (; begin < end; ++begin)
	{
		functor(*begin);
	}
}
template<class CONTAINER, class FUNCTOR>
void forEach(CONTAINER container, FUNCTOR functor)
{
	typename CONTAINER::iterator begin = container.begin();
	typename CONTAINER::iterator end = container.end();
	forEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void forEach(T(&array)[N], FUNCTOR functor)
{
	T* begin = array;
	T* end = array + N;
	forEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void forEach(const T(&array)[N], FUNCTOR functor)
{
	const T* begin = array;
	const T* end = array + N;
	forEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void forEach(T* array, const std::size_t size, FUNCTOR functor)
{
	T* begin = array;
	T* end = array + size;
	forEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void forEach(const T* array, const std::size_t size, FUNCTOR functor)
{
	const T* begin = array;
	const T* end = array + size;
	forEach(begin, end, functor);
}
//----------------------------------------
//reverse for-each
template<class ITERATOR, class FUNCTOR>
void reverseForEach(ITERATOR begin, ITERATOR end, FUNCTOR functor)
{
	while (begin > end)
	{
		--begin;
		functor(*begin);
	}
}
template<class CONTAINER, class FUNCTOR>
void reverseForEach(CONTAINER container, FUNCTOR functor)
{
	typename CONTAINER::reverse_iterator rbegin = container.rbegin();
	typename CONTAINER::reverse_iterator rend = container.rend();
	forEach(rbegin, rend, functor);//リバースイテレータ＋forEachで処理
}
template<typename T, std::size_t N, class FUNCTOR>
void reverseForEach(T(&array)[N], FUNCTOR functor)
{
	T* begin = array + N;
	T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void reverseForEach(const T(&array)[N], FUNCTOR functor)
{
	const T* begin = array + N;
	const T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void reverseForEach(T* array, const std::size_t size, FUNCTOR functor)
{
	T* begin = array + size;
	T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void reverseForEach(const T* array, const std::size_t size, FUNCTOR functor)
{
	const T* begin = array + size;
	const T* end = array;
	reverseForEach(begin, end, functor);
}

//========================================
//ソートアルゴリズム分類：挿入ソート
//========================================

//----------------------------------------
//アルゴリズム：挿入ソート
//----------------------------------------
//・最良計算時間：O(n)
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
template<class T, class PREDICATE>
std::size_t insertionSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	const T* end = array + size;
	T* now = array;
	T* next = now + 1;
	while (next < end)
	{
		if (predicate(*next, *now))
		{
			T* min = now;
			T* prev = now - 1;
			while (prev >= array)
			{
				if (predicate(*next, *prev))
					min = prev;
				else
					break;
				--prev;
			}
			rotateValues(min, next, 1);
			++swapped_count;
		}
		++now;
		++next;
	}
	return swapped_count;
}
sortFuncSet(insertionSort);

//----------------------------------------
//アルゴリズム：シェルソート
//----------------------------------------
//・最良計算時間：O(n)
//・平均計算時間：O(n log^2 n) or O(n^3/2)
//・最悪計算時間：O(n log^2 n)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class PREDICATE>
std::size_t shellSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	const T* end = array + size;
	const std::size_t h_max = size / 3;
	std::size_t h = 1;
	while (h <= h_max)
		h = 3 * h + 1;
	while (h > 0)
	{
		T* now = array;
		T* next = now + h;
		while (next < end)
		{
			if (predicate(*next, *now))
			{
				T* min = now;
				T* prev = now - h;
				while (prev >= array)
				{
					if (predicate(*next, *prev))
						min = prev;
					else
						break;
					prev -= h;
				}
				rotateValues(min, next, h);
				++swapped_count;
			}
			++now;
			++next;
		}
		h = (h - 1) / 3;
	}
	return swapped_count;
}
sortFuncSet(shellSort);

//========================================
//ソートアルゴリズム分類：混成ソート
//========================================

//----------------------------------------
//アルゴリズム：イントロソート
//----------------------------------------
//・最良計算時間：O(n log n)
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(n log n) ※ループ処理版は O(32*2)
//・安定性：　　　×
//----------------------------------------
template<class T, class PREDICATE>
std::size_t _introSort(T* array, const std::size_t size, PREDICATE predicate)
{
	int depth_max = 0;//ヒープソートに切り替える再帰（スタック）の深さ
	for (std::size_t size_tmp = size; size_tmp > 1; size_tmp >>= 1, ++depth_max);
	//--------------------
	//クイックソート：スタック処理版
	//※再帰処理版は省略
	static const std::size_t SIZE_THRESHOLD = 16;//32;//挿入ソートに切り替える件数
	std::size_t swapped_count = 0;
	struct stack_t
	{
		T* array;
		std::size_t size;
		int depth;
	};
	static const int STACK_DEPTH_MAX = 32 * 2;
	stack_t stack[STACK_DEPTH_MAX];
	//最初の配列をスタックにプッシュ
	stack_t* stack_p = &stack[0];
	stack_p->array = array;
	stack_p->size = size;
	stack_p->depth = depth_max;
	int stack_curr = 1;//スタック位置
	while (stack_curr > 0)
	{
		//配列をスタックから取得
		stack_p = &stack[--stack_curr];
		T* _array = stack_p->array;
		const size_t _size = stack_p->size;
		const int _depth = stack_p->depth;
		//配列の範囲情報
		const T* term = _array + _size;
		T* begin = _array;
		T* end = _array + _size - 1;
		//軸を決定
		const T* mid = _array + (_size >> 1);
		const T* pivot =
			predicate(*begin, *mid) ?
				predicate(*mid, *end) ?
					mid :
					predicate(*end, *begin) ?
						begin :
						end :
				predicate(*end, *mid) ?
					mid :
					predicate(*begin, *end) ?
						begin :
						end;
		//軸未満の配列と軸以上の配列に二分
		while (true)
		{
			while (predicate(*begin, *pivot))
				++begin;
			while (predicate(*pivot, *end))
				--end;
			if (begin >= end)
				break;
			swapValues(*begin, *end);
			pivot = pivot == begin ? end : pivot == end ? begin : pivot;//軸の位置調整（軸の位置も入れ替わるため）
			++swapped_count;
			++begin;
			--end;
		}
		//recursive = 0 : 軸未満の配列をプッシュ
		//            1 : 軸以上の配列をプッシュ
		for (int recursive = 0; recursive < 2; ++recursive)
		{
			T* new_array = recursive == 0 ? _array : end + 1;
			const std::size_t new_size = recursive == 0 ? begin - _array : term - end - 1;
			const int new_depth = _depth - 1;
			if (new_size >= 1)
			{
				if (new_size < SIZE_THRESHOLD)
				{
					//swapped_count += insertionSort(new_array, new_size, predicate);//【本来の処理】挿入ソートに切り替え
					//swapped_count += combSort(new_array, new_size, predicate);//【改良】コムソートに切り替え
					swapped_count += shellSort(new_array, new_size, predicate);//【改良】シェルソートに切り替え
				}
				else if (new_depth == 0)
				{
					//swapped_count += heapSort(new_array, new_size, predicate);//【本来の処理】ヒープソートに切り替え
					//swapped_count += combSort(new_array, new_size, predicate);//【改良】コムソートに切り替え
					swapped_count += shellSort(new_array, new_size, predicate);//【改良】シェルソートに切り替え
				}
				else
				{
					//再帰
					stack_p = &stack[stack_curr++];
					stack_p->array = new_array;
					stack_p->size = new_size;
					stack_p->depth = new_depth;
				}
			}
		}
	}
	return swapped_count;
}
template<class T, class PREDICATE>
inline std::size_t introSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	if (calcUnordered(array, size, predicate) == 0)
		return 0;
	return _introSort(array, size, predicate);
}
sortFuncSet(introSort);

//========================================
//探索アルゴリズム
//========================================

//----------------------------------------
//アルゴリズム：線形探索
//----------------------------------------
//・最良計算時間：O(1)
//・平均計算時間：O(n/2)
//・最悪計算時間：O(n)
//・探索失敗時：  O(n)
//----------------------------------------
template<class T, class PREDICATE>
T* linearSearch(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size == 0)
		return nullptr;
	T* now = array;
	for (std::size_t i = 0; i < size; ++i, ++now)//順次探索
	{
		if (predicate(*now))//探索キーと一致したら終了
			return now;
	}
	return nullptr;//探索失敗
}
searchFuncSetByPredicate(linearSearch);

//----------------------------------------
//アルゴリズム：二分探索
//----------------------------------------
//・最良計算時間：O(1)
//・平均計算時間：O(log n)
//・最悪計算時間：O(log n)
//・探索失敗時：  O(log n)
//----------------------------------------
template<class T, class COMPARISON>
T* binarySearch(T* array, const std::size_t size, COMPARISON comparison)
{
	if (!array || size == 0)
		return nullptr;
	std::size_t range = size;
	T* begin = array;
	while (true)
	{
		const std::size_t range_half = range / 2;//探索範囲の半分の範囲
		T* mid = begin + range_half;//探索範囲の中心要素
		const int comp = comparison(*mid);//中心要素を探索キーと比較
		if (comp == 0)//中心要素が探索キーと一致
		{
			//遡ってキーの開始点を探す
			while (mid > array)
			{
				T* prev = mid - 1;
				if (comparison(*prev) != 0)
					break;
				mid = prev;
			}
			return mid;//探索終了
		}
		if (range_half == 0)//探索範囲が残っていなければ探索失敗
			return nullptr;
		if (comp < 0)//探索キーが中心要素より小さかった場合、次に中心より前の範囲に絞って探索する
			range = range_half;
		else//if (comp > 0)//探索キーが中心要素より大きかった場合、次に中心より後の範囲に絞って探索する
		{
			begin = mid + 1;
			range -= (range_half + 1);
		}
	}
	return nullptr;
}
searchFuncSetByComparison(binarySearch);

//--------------------------------------------------------------------------------
//動的配列
//--------------------------------------------------------------------------------
//データ構造とアルゴリズム
//【特徴】
//・単純な一次配列である。
//・配列の要素数を超えない範囲で、有効要素数を動的に変化させて管理する。
//・有効要素の増減に伴い、コンストラクタ／デストラクタの呼び出しを行う。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【本プログラムにおける実装要件】
//・アルゴリズムとデータ本体を分離したコンテナとする。
//・コンテナ自体は要素の実体を持たずメモリ確保も行わない。
//・コンストラクタで受けとった配列の参照を扱う。
//・STL（std::vector）との違いは下記の通り
//    - 固定長配列である。
//    - 赤黒木コンテナ（rb_tree）の実装と合わせた構造にしており、
//　　  操作用テンプレート構造体を用いる。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【具体的な活用の想定】
//・コンテナクラスと無関係の配列を、一時的にコンテナクラス化して操作する。
//--------------------------------------------------------------------------------

#include <cstddef>//std::size_t, std::ptrdiff_t用
//#include <cstdint>//std::intptr_t用
#include <iterator>//std::iterator用
#include <new>//配置new,配置delete用
#include <algorithm>//C++11 std::move用

namespace dynamic_array
{
	//--------------------
	//動的配列操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename VALUE_TYPE>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public dynamic_array::base_ope_t<派生構造体, 要素型>
	//	struct ope_t : public dynamic_array::base_ope_t<ope_t, data_t>
	//	{
	//		//ソート用プレディケート関数オブジェクト
	//		//※必要に応じて実装する
	//		struct sort_predicate{
	//			inline bool operator()(const value_type& lhs, const value_type& rhs) const { return lhs.??? < rhs.???; }
	//		};
	//
	//		//探索用プレディケート関数オブジェクト
	//		//※必要に応じて実装する
	//		struct find_predicate{
	//			inline bool operator()(const value_type& lhs, const ???& rhs) const { return lhs.??? == rhs; }
	//		};
	//		
	//		//探索用比較関数オブジェクト
	//		//※必要に応じて実装する
	//		struct search_comparison{
	//			inline int operator()(const value_type& lhs, const ???& rhs) const { return rhs - lhs.???; }
	//		};
	//		
	//		//ロック型 ※必要に応じて定義
	//		//※ロックでコンテナ操作をスレッドセーフにしたい場合は、
	//		//　有効なロック型（spin_lockなど）を lock_type 型として定義する。
	//		typedef shared_spin_lock lock_type;//ロックオブジェクト型
	//
	//		//デストラクタ呼び出し ※必要に応じて実装
	//		//※デストラクタ呼び出しを抑制したい場合などに定義する。
	//		inline static void callDestructor(value_type* obj)
	//		{
	//			//なにもしない
	//		}
	//	};
	template<class OPE_TYPE, typename VALUE_TYPE>
	struct base_ope_t
	{
		//型
		typedef OPE_TYPE ope_type;//要素操作型
		typedef VALUE_TYPE value_type;//要素型

		//ロック型
		typedef dummy_shared_lock lock_type;//ロックオブジェクト型
		//※デフォルトはダミーのため、一切ロック制御しない。
		//※ロックでコンテナ操作をスレッドセーフにしたい場合は、
		//　base_ope_tの派生クラスにて、有効なロック型（shared_spin_lock など）を
		//　lock_type 型として再定義する。

		//デストラクタ呼び出し
		inline static void callDestructor(value_type* obj){ obj->~VALUE_TYPE(); }
		//※デストラクタの呼び出しを禁止したい場合、
		//　base_ope_tの派生クラスにて、なにもしない
		//　callDestructor メソッドを再定義する。

		//ソート用プレディケート関数オブジェクト
		//※trueでlhsの方が小さい（並び順が正しい）
		struct sort_predicate{
			inline bool operator()(const value_type& lhs, const value_type& rhs) const { return less<value_type>()(lhs, rhs); }
		};

		//探索用プレディケート関数オブジェクト
		//※trueで一致（探索成功）
		struct find_predicate{
			template<typename V>
			inline bool operator()(const value_type& lhs, const V& rhs) const { return equal_to<value_type>()(lhs, rhs); }
		};

		//探索用比較関数オブジェクト
		//※0で一致（探索成功）、1以上でlhsの方が大きい、-1以下でrhsの方が大きい
		struct search_comparison{
			template<typename V>
			inline int operator()(const value_type& lhs, const V& rhs) const { return compare_to<value_type>()(lhs, rhs); }
		};
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::value_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type; \
		typedef typename ope_type::lock_type lock_type;
	//----------------------------------------
	//コンテナ破棄時の要素の自動クリア属性
	enum auto_clear_attr_t
	{
		NEVER_CLEAR,//自動クリアしない（デフォルト）
		AUTO_CLEAR,//自動クリアし、残っている要素のデストラクタを呼び出す
	};
	//----------------------------------------
	//動的配列コンテナ
	template<class OPE_TYPE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//定数
		static const index_type INVALID_INDEX = 0xffffffffu;//無効なインデックス
	public:
		//--------------------
		//イテレータ宣言
		class iterator;
		class reverse_iterator;
		typedef const iterator const_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		//--------------------
		//イテレータ
		class iterator : public std::iterator<std::random_access_iterator_tag, value_type>
		{
			friend class container;
			friend class reverse_iterator;
		public:
			//キャストオペレータ
			inline operator bool() const { return isExist(); }
			inline operator const value_type&() const { return *getValue(); }
			inline operator value_type&(){ return *getValue(); }
			inline operator const value_type*() const { return getValue(); }
			inline operator value_type*(){ return getValue(); }
		public:
			//オペレータ
			inline const value_type& operator*() const { return *getValue(); }
			inline value_type& operator*(){ return *getValue(); }
			inline const_pointer operator->() const { return getValue(); }
			inline pointer operator->(){ return getValue(); }
			inline const_iterator operator[](const int index) const
			{
				iterator ite(*m_con, false);
				ite.update(index);
				return std::move(ite);
			}
			inline iterator operator[](const int index)
			{
				iterator ite(*m_con, false);
				ite.update(index);
				return std::move(ite);
			}
			//比較オペレータ
			inline bool operator==(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index == rhs.index;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index != rhs.m_index;
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index > rhs.m_index;
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index >= rhs.m_index;
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index < rhs.m_index;
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_index <= rhs.m_index;
			}
			//演算オペレータ
			inline const_iterator& operator++() const
			{
				addIndexAndUpdate(1);
				return *this;
			}
			inline const_iterator& operator--() const
			{
				addIndexAndUpdate(-1);
				return *this;
			}
			inline iterator& operator++()
			{
				addIndexAndUpdate(1);
				return *this;
			}
			inline iterator& operator--()
			{
				addIndexAndUpdate(-1);
				return *this;
			}
			inline const_iterator operator++(int) const
			{
				iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline const_iterator& operator+=(const typename iterator::difference_type rhs) const
			{
				addIndexAndUpdate(rhs);
				return *this;
			}
			inline const_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline const_iterator& operator-=(const typename iterator::difference_type rhs) const
			{
				addIndexAndUpdate(-rhs);
				return *this;
			}
			inline const_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator+=(const typename iterator::difference_type rhs)
			{
				addIndexAndUpdate(rhs);
				return *this;
			}
			inline iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator-=(const typename iterator::difference_type rhs)
			{
				addIndexAndUpdate(-rhs);
				return *this;
			}
			inline iterator& operator-=(const std::size_t rhs)
			{
				return operator-=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline const_iterator operator+(const typename iterator::difference_type rhs) const
			{
				iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline const_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline const_iterator operator-(const typename iterator::difference_type rhs) const
			{
				iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline const_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator+(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator-(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline typename iterator::difference_type operator-(const iterator rhs)
			{
				if (m_index == INVALID_INDEX || rhs.m_index == INVALID_INDEX || m_index < rhs.m_index)
					return 0;
				return m_index - rhs.m_index;
			}
		public:
			//ムーブオペレータ
			inline iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				m_value = rhs.m_value;
				return *this;
			}
			iterator& operator=(const_reverse_iterator&& rhs);
			//コピーオペレータ
			inline iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				m_value = rhs.m_value;
				return *this;
			}
			iterator& operator=(const_reverse_iterator& rhs);
		public:
			//アクセッサ
			inline bool isExist() const { return m_index != INVALID_INDEX && m_index < m_con->m_size; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_index != INVALID_INDEX; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_index == m_con->m_size; }//終端か？
			inline index_type getIndex() const { return m_index; }//インデックス
			inline const value_type* getValue() const { return m_value; }//現在の値
			inline value_type* getValue(){ return m_value; }//現在の値
		private:
			//メソッド
			void update(const index_type index) const
			{
				//if (index == INVALID_INDEX || index < 0 || index > static_cast<index_type>(m_con->m_size))
				if (index > static_cast<index_type>(m_con->m_size))
				{
					m_index = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_index = index;
					m_value = const_cast<value_type*>(m_con->_ref_element(m_index));
				}
			}
			inline void addIndexAndUpdate(const int add) const
			{
				update(m_index + add);
			}
		public:
			//ムーブコンストラクタ
			iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			iterator(const_reverse_iterator&& obj);
			//コピーコンストラクタ
			inline iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			iterator(const_reverse_iterator& obj);
			//コンストラクタ
			inline iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				if (!is_end)
					update(0);//先頭データ
				else
					update(m_con->m_size);//末尾データ
			}
			inline iterator(const container& con, const index_type index) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				update(index);
			}
			inline iterator() :
				m_con(nullptr),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{}
			//デストラクタ
			inline ~iterator()
			{}
		protected:
			//フィールド
			const container* m_con;//コンテナ
			mutable index_type m_index;//現在のインデックス
			mutable value_type* m_value;//現在の値
		};
		//--------------------
		//リバースイテレータ
		//class reverse_iterator : public std::reverse_iterator<iterator>
		class reverse_iterator : public std::iterator<std::random_access_iterator_tag, value_type>
		{
			friend class container;
			friend class iterator;
		public:
			//キャストオペレータ
			inline operator bool() const { return isExist(); }
			inline operator const value_type&() const { return *getValue(); }
			inline operator value_type&(){ return *getValue(); }
			inline operator const value_type*() const { return getValue(); }
			inline operator value_type*(){ return getValue(); }
		public:
			//オペレータ
			inline const value_type& operator*() const { return *getValue(); }
			inline value_type& operator*(){ return *getValue(); }
			inline const_pointer operator->() const { return getValue(); }
			inline pointer operator->(){ return getValue(); }
			inline const_reverse_iterator operator[](const int index) const
			{
				reverse_iterator ite(*m_con, false);
				ite.update(m_con->m_size - index);
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(*m_con, false);
				ite.update(m_con->m_size - index);
				return std::move(ite);
			}
		public:
			//比較オペレータ
			inline bool operator==(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index == m_index;
			}
			inline bool operator!=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index != m_index;
			}
			inline bool operator>(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index > m_index;
			}
			inline bool operator>=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index >= m_index;
			}
			inline bool operator<(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index < m_index;
			}
			inline bool operator<=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_index <= m_index;
			}
			//演算オペレータ
			inline const_reverse_iterator& operator++() const
			{
				addIndexAndUpdate(1);
				return *this;
			}
			inline const_reverse_iterator& operator--() const
			{
				addIndexAndUpdate(-1);
				return *this;
			}
			inline reverse_iterator& operator++()
			{
				addIndexAndUpdate(1);
				return *this;
			}
			inline reverse_iterator& operator--()
			{
				addIndexAndUpdate(-1);
				return *this;
			}
			inline const_reverse_iterator operator++(int) const
			{
				reverse_iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline const_reverse_iterator operator--(int) const
			{
				reverse_iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline reverse_iterator operator++(int)
			{
				reverse_iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline reverse_iterator operator--(int)
			{
				reverse_iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline const_reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs) const
			{
				addIndexAndUpdate(rhs);
				return *this;
			}
			inline const_reverse_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline const_reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs) const
			{
				addIndexAndUpdate(-rhs);
				return *this;
			}
			inline const_reverse_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs)
			{
				addIndexAndUpdate(rhs);
				return *this;
			}
			inline reverse_iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs)
			{
				addIndexAndUpdate(-rhs);
				return *this;
			}
			inline reverse_iterator& operator-=(const std::size_t rhs)
			{
				return operator-=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline const_reverse_iterator operator+(const typename reverse_iterator::difference_type rhs) const
			{
				reverse_iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline const_reverse_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline const_reverse_iterator operator-(const typename reverse_iterator::difference_type rhs) const
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline const_reverse_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator+(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline reverse_iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator-(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline reverse_iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline typename reverse_iterator::difference_type operator-(const reverse_iterator rhs)
			{
				if (m_index == INVALID_INDEX || rhs.m_index == INVALID_INDEX || rhs.m_index < m_index)
					return 0;
				return rhs.m_index - m_index;
			}
		public:
			//ムーブオペレータ
			inline reverse_iterator& operator=(const_reverse_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				m_value = rhs.m_value;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				update(m_index);
				return *this;
			}
			//コピーオペレータ
			inline reverse_iterator& operator=(const_reverse_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				m_value = rhs.m_value;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_index = rhs.m_index;
				update(m_index);
				return *this;
			}
		public:
			//アクセッサ
			inline bool isExist() const { return m_index != INVALID_INDEX && m_index > 0; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_index != INVALID_INDEX; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_index == 0; }//終端か？
			inline index_type getIndex() const { return m_index - 1; }//インデックス
			inline const value_type* getValue() const { return m_value; }//現在の値
			inline value_type* getValue(){ return m_value; }//現在の値
		private:
			//メソッド
			void update(const index_type index) const
			{
				//if (index == INVALID_INDEX || index < 0 || index > static_cast<index_type>(m_con->m_size))
				if (index > static_cast<index_type>(m_con->m_size))
				{
					m_index = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_index = index;
					m_value = const_cast<value_type*>(m_con->_ref_element(m_index)) - 1;
				}
			}
			inline void addIndexAndUpdate(const int add) const
			{
				update(m_index - add);
			}
		public:
			//ベースを取得
			inline const_iterator base() const
			{
				iterator ite(*this);
				return std::move(ite);
			}
			inline iterator base()
			{
				iterator ite(*this);
				return std::move(ite);
			}
		public:
			//ムーブコンストラクタ
			inline reverse_iterator(const_reverse_iterator&& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			inline reverse_iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(nullptr)
			{
				update(obj.m_index);
			}
			//コピーコンストラクタ
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(nullptr)
			{
				update(m_index);
			}
			//コンストラクタ
			inline reverse_iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				if (!is_end)
					update(m_con->m_size);//末尾データ
				else
					update(0);//先頭データ
			}
			inline reverse_iterator(const container& con, const index_type index) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				update(index);
			}
			inline reverse_iterator() :
				m_con(nullptr),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{}
			//デストラクタ
			inline ~reverse_iterator()
			{}
		protected:
			//フィールド
			const container* m_con;//コンテナ
			mutable index_type m_index;//現在のインデックス
			mutable value_type* m_value;//現在の値
		};
	public:
		//アクセッサ
		inline const value_type* at(const int index) const { return ref_element(index); }
		inline value_type* at(const int index){ return ref_element(index); }
		inline const value_type* operator[](const int index) const { return ref_element(index); }
		inline value_type* operator[](const int index){ return ref_element(index); }
		auto_clear_attr_t getAutoClearAttr() const { return m_autoClearAttr; }//コンテナ破棄時に残っている要素の自動クリア属性を取得
		void setAutoClearAttr(const auto_clear_attr_t attr){ m_autoClearAttr = attr; }//コンテナ破棄時に残っている要素の自動クリア属性を変更
	public:
		//キャストオペレータ
		inline operator lock_type&(){ return m_lock; }//共有ロックオブジェクト
		inline operator lock_type&() const { return m_lock; }//共有ロックオブジェクト ※mutable
	public:
		//メソッド
		inline size_type max_size_real() const { return m_maxSizeReal; }//最大要素数（実際の最大要素数）を取得
		inline size_type max_size() const { return m_maxSize; }//最大要素数を取得
		inline size_type capacity() const { return m_maxSize; }//最大要素数を取得
		inline size_type size() const { return m_size; }//使用中の要素数を取得
		inline size_type remain() const { return m_maxSize - m_size; }//残りの要素数を取得
		inline bool empty() const { return m_size == 0; }//空か？
		inline bool full() const { return m_size == m_maxSize; }//満杯か？
	private:
		//※範囲チェックなし
		inline const value_type* _ref_element(const index_type index) const { return &m_array[index]; }//要素参照
		inline const value_type* _ref_front() const { return _ref_element(0); }//先頭要素参照
		inline const value_type* _ref_back() const { return _ref_element(m_size - 1); }//末尾要素参照
		inline const value_type* _ref_new() const { return _ref_element(m_size); }//新規要素参照
		inline value_type* _ref_element(const index_type index){ return &m_array[index]; }//要素参照
		inline value_type* _ref_front(){ return _ref_element(0); }//先頭要素参照
		inline value_type* _ref_back(){ return _ref_element(m_size - 1); }//末尾要素参照
		inline value_type* _ref_new(){ return _ref_element(m_size); }//新規要素参照
	public:
		//※範囲チェックあり
		//inline const value_type* ref_element(const index_type index) const { return index >= 0 && index < m_size ? _ref_element(index) : nullptr; }//要素参照
		inline const value_type* ref_element(const index_type index) const { return index < m_size ? _ref_element(index) : nullptr; }//要素参照
		inline const value_type* ref_front() const { return m_size == 0 ? nullptr : _ref_front(); }//先頭要素参照
		inline const value_type* ref_back() const { return m_size == 0 ? nullptr : _ref_back(); }//末尾要素参照
		inline const value_type* ref_new() const { return m_size == m_maxSize ? nullptr : _ref_new(); }//新規要素参照
		inline value_type* ref_element(const index_type index){ return  const_cast<value_type*>(const_cast<const container*>(this)->ref_element(index)); }//要素参照
		inline value_type* ref_front(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_front()); }//先頭要素参照
		inline value_type* ref_back(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_back()); }//末尾要素参照
		inline value_type* ref_new(){ return const_cast<value_type*>(const_cast<const container*>(this)->ref_new()); }//新規要素参照
	private:
		//inline index_type _adj_index(const index_type index) const { return index >= 0 && index < m_maxSize ? index : INVALID_INDEX; }//インデックスを範囲内に補正
		inline index_type _adj_index(const index_type index) const { return index < m_maxSize ? index : INVALID_INDEX; }//インデックスを範囲内に補正
		inline index_type _ref_index(const value_type* node) const{ return node - _ref_front(); }//要素をインデックスに変換 ※範囲チェックなし
	public:
		inline index_type ref_index(const value_type* node) const{ return _adj_index(_ref_index(node)); }//要素をインデックスに変換
	public:
		inline const value_type* front() const { return ref_front(); }//先頭要素参照
		inline value_type* front(){ return ref_front(); }//先頭要素参照
		inline const value_type* back() const { return ref_back(); }//末尾要素参照
		inline value_type* back(){ return ref_back(); }//末尾要素参照
		//イテレータを取得
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で共有ロック（リードロック）の取得と解放を行う必要がある
		inline const_iterator cbegin() const
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_iterator cend() const
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
		inline const_iterator begin() const
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_iterator end() const
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
		inline iterator begin()
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline iterator end()
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
		//リバースイテレータを取得
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で共有ロック（リードロック）の取得と解放を行う必要がある
		inline const_reverse_iterator crbegin() const
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_reverse_iterator crend() const
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
		inline const_reverse_iterator rbegin() const
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_reverse_iterator rend() const
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
		inline reverse_iterator rbegin()
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline reverse_iterator rend()
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
	public:
		//配列の再割り当て
		//※コンテナ生成時のコンストラクタで配列を指定できなかった時に使用する。
		//※初期状態で使用中の要素数を指定する（-1で全要素を使用中にする）
		//※要素の初期化は行わない（必要なら size に 0 を指定して、後で resize() を呼び出す）
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		template<size_type N>
		inline void assign_array(value_type(&array)[N], const int size = 0)
		{
			assign_array(array, N, size);
		}
		//※ポインタと配列要素数指定版
		void assign_array(value_type* array, const size_type max_size, const int size = 0)
		{
			if (m_array && m_autoClearAttr == AUTO_CLEAR)
				clear();//クリア
			m_array = array;
			m_maxSizeReal = max_size;
			m_maxSize = max_size;
			m_size = size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size);
		}
		//※voidポインタとバッファサイズ数指定版
		void assign_array(void* buff_ptr, const size_type buff_size, const int size = 0)
		{
			assign_array(static_cast<value_type*>(buff_ptr), buff_size / sizeof(value_type), size);
		}
		//最大要素数の変更（新しい最大要素数を返す）
		//※名前に反して拡大・縮小が可能
		//※使用中の要素数以下にはできない
		//※実際の最大要素数以上にはできない
		//※実際の配列の範囲を超えないことは保証しない
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		inline size_type reserve(const size_type max_size)
		{
			if (max_size < m_size)
				m_maxSize = m_size;
			else if (max_size > m_maxSizeReal)
				m_maxSize = m_maxSizeReal;
			else
				m_maxSize = max_size;
			return m_maxSize;
		}
		//最大要素数の変更（新しい最大要素数を返す）
		//※名前に反して拡大・縮小が可能
		//※使用中の要素数以下にもできる（削除された要素はデストラクタを呼び出す）
		//※実際の配列の範囲を超えないことは保証しない
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		size_type shrink(const size_type max_size)
		{
			if (max_size < m_size)
			{
				value_type* value = _ref_element(max_size);
				for (index_type index = max_size; index < m_size; ++index, ++value)
				{
					ope_type::callDestructor(value);//デストラクタ呼び出し
					operator delete(value, value);//（作法として）deleteオペレータ呼び出し
				}
				m_size = max_size;
				m_maxSize = m_size;
			}
			else if (max_size > m_maxSizeReal)
				m_maxSize = m_maxSizeReal;
			else
				m_maxSize = max_size;
			return m_maxSize;
		}
		//最大要素数の変更（新しい最大要素数を返す）
		//※現在使用中のサイズに合わせる
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		size_type shrink_to_fit()
		{
			m_maxSize = m_size;
			return m_maxSize;
		}
		//使用中のサイズを変更（新しいサイズを返す）
		//※新しい要素にはnew_valueをセットし、削除された要素はデストラクタを呼び出す
		//※最大要素数を超えるサイズにはできない
		//※指定数が -1 なら最大要素数に変更
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		size_type resize(const int size, const value_type& new_value)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			if (_size > m_size)
			{
				value_type* value = _ref_element(m_size);
				for (index_type index = m_size; index < _size; ++index, ++value)
					*value = new_value;//新しい値を初期化
			}
			else if (_size < m_size)
			{
				value_type* value = _ref_element(_size);
				for (index_type index = _size; index < m_size; ++index, ++value)
				{
					ope_type::callDestructor(value);//デストラクタ呼び出し
					operator delete(value, value);//（作法として）deleteオペレータ呼び出し
				}
			}
			m_size = _size;
			return m_size;
		}
		//※コンストラクタ呼び出し版
		template<typename... Tx>
		size_type resize(const int size, Tx... args)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			if (_size > m_size)
			{
				value_type* value = _ref_element(m_size);
				for (index_type index = m_size; index < _size; ++index, ++value)
					new(value)value_type(args...);//コンストラクタ呼び出し
			}
			else if (_size < m_size)
			{
				value_type* value = _ref_element(size);
				for (index_type index = size; index < m_size; ++index, ++value)
				{
					ope_type::callDestructor(value);//デストラクタ呼び出し
					operator delete(value, value);//（作法として）deleteオペレータ呼び出し
				}
			}
			m_size = _size;
			return m_size;
		}
		//使用中のサイズを変更（新しいサイズを返す）
		//※新しい値の代入も削除された要素のデストラクタ呼び出しも行わず、
		//　使用中のサイズだけを変更する
		//※最大要素数を超えるサイズにはできない
		//※指定数が -1 なら最大要素数に変更
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		size_type resize_silent(const int size)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			m_size = _size;
			return m_size;
		}
		//先頭から指定数の要素にデータを割り当てる
		//※new_valueで要素を上書きする
		//※既存の要素を上書きする際は、コピーオペレータを使用（デストラクタは呼び出さない）
		//※指定数が -1 なら最大素数を対象にする
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		size_type assign(const int size, const value_type& new_value)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			//{
			//	const size_type used_size = _size < m_size ? _size : m_size;
			//	value_type* value = _ref_front();
			//	for (index_type index = 0; index < used_size; ++index, ++value)
			//	{
			//		ope_type::callDestructor(value);//デストラクタ呼び出し
			//		operator delete(value, value);//（作法として）deleteオペレータ呼び出し
			//	}
			//}
			{
				value_type* value = _ref_front();
				for (index_type index = 0; index < _size; ++index, ++value)
					*value = new_value;//データを上書き
			}
			if(m_size < _size)
				m_size = _size;
			return m_size;
		}
		//※コンストラクタ呼び出し版
		//※既存の要素を上書きする際は、先にデストラクタを呼び出す
		template<typename... Tx>
		size_type assign(const int size, Tx... args)
		{
			const size_type _size = size < 0 ? m_maxSize : static_cast<size_type>(size) < m_maxSize ? static_cast<size_type>(size) : m_maxSize;
			{
				const size_type used_size = _size < m_size ? _size : m_size;
				value_type* value = _ref_front();
				for (index_type index = 0; index < used_size; ++index, ++value)
				{
					ope_type::callDestructor(value);//デストラクタ呼び出し
					operator delete(value, value);//（作法として）deleteオペレータ呼び出し
				}
			}
			{
				value_type* value = _ref_front();
				for (index_type index = 0; index < _size; ++index, ++value)
					new(value)value_type(args...);//コンストラクタ呼び出し
			}
			if (m_size < _size)
				m_size = _size;
			return m_size;
		}
		//末尾に要素を追加
		//※オブジェクト渡し
		//※オブジェクトのコピーが発生する点に注意（少し遅くなる）
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		inline value_type* push_back(const value_type&& src)//ムーブ版
		{
			value_type* obj = ref_new();//サイズチェック含む
			if (!obj)
				return nullptr;
			*obj = std::move(src);
			++m_size;
			return obj;
		}
		inline value_type* push_back(const value_type& src)//コピー版
		{
			value_type* obj = ref_new();//サイズチェック含む
			if (!obj)
				return nullptr;
			*obj = src;
			++m_size;
			return obj;
		}
		//末尾に要素を追加
		//※パラメータ渡し
		//※オブジェクトのコンストラクタが呼び出される
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		template<typename... Tx>
		value_type* push_back(Tx... args)
		{
			value_type* obj = ref_new();//サイズチェック含む
			if (!obj)
				return nullptr;
			new(obj)value_type(args...);//コンストラクタ呼び出し
			++m_size;
			return obj;
		}
		//末尾の要素を削除
		//※オブジェクトのデストラクタが呼び出される
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		bool pop_back()
		{
			if (m_size == 0)
				return false;
			value_type* value = const_cast<value_type*>(ref_back());
			ope_type::callDestructor(value);//デストラクタ呼び出し
			operator delete(value, value);//（作法として）deleteオペレータ呼び出し
			--m_size;
			return true;
		}
		//※オブジェクトの値を受け取る
		bool pop_back(value_type& value)
		{
			if (m_size == 0)
				return false;
			value_type* obj = const_cast<value_type*>(ref_back());
			value = std::move(*obj);//ムーブ
			ope_type::callDestructor(obj);//デストラクタ呼び出し
			operator delete(obj, obj);//（作法として）deleteオペレータ呼び出し
			--m_size;
			return true;
		}
	public:
		//クリア
		//※デストラクタを呼び出す
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		inline void clear()
		{
			if (m_size == 0)
				return;
			value_type* value = _ref_front();
			for (size_type i = 0; i < m_size; ++i, ++value)
			{
				ope_type::callDestructor(value);//デストラクタ呼び出し
				operator delete(value, value);//（作法として）deleteオペレータ呼び出し
			}
			m_size = 0;
		}
	private:
		//要素の移動（昇順）
		void move_asc(const index_type dst_pos, const index_type src_pos, const size_type num)
		{
			value_type* dst = _ref_element(dst_pos);
			value_type* src = _ref_element(src_pos);
			value_type* end = _ref_new();
			for (size_type i = 0; i < num; ++i)
			{
				if (dst >= end)
					new(dst)value_type(std::move(*src));//ムーブコンストラクタ
				else
					*dst = std::move(*src);//ムーブオペレータ
				++dst;
				++src;
			}
		}
		//要素の移動（降順）
		void move_desc(const index_type dst_pos, const index_type src_pos, const size_type num)
		{
			value_type* dst = _ref_element(dst_pos + num - 1);
			value_type* src = _ref_element(src_pos + num - 1);
			value_type* end = _ref_new();
			for (size_type i = 0; i < num; ++i)
			{
				if (dst >= end)
					new(dst)value_type(std::move(*src));//ムーブコンストラクタ
				else
					*dst = std::move(*src);//ムーブオペレータ
				--dst;
				--src;
			}
		}
	public:
		//要素の挿入
		//※numの挿入によって最大要素数を超える場合は、可能なサイズに縮小して返す
		//※挿入した位置（先頭）のイテレータを返す
		//※指定数が -1 なら可能な限りの数を挿入
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		iterator insert(iterator pos, const int num, value_type& value)
		{
			if (pos.isNotEnabled() || num == 0 || m_size == m_maxSize)
			{
				iterator ite(*this, INVALID_INDEX);
				return std::move(ite);
			}
			index_type index = pos.getIndex();
			const size_type remain = m_maxSize - m_size;
			const size_type _num = num < 0 || static_cast<size_type>(num) > remain ? remain : static_cast<size_type>(num);
			//移動
			move_desc(index + _num, index, _num);
			//要素数変更
			m_size += _num;
			//挿入
			value_type* new_value = _ref_element(index);
			for (size_type i = 0; i < _num; ++i, ++new_value)
				*new_value = value;
			//終了
			iterator now(*this, index);
			return std::move(now);
		}
		//※コンストラクタ呼び出し版
		template<typename... Tx>
		iterator insert(iterator pos, const int num, Tx... args)
		{
			if (pos.isNotEnabled() || num == 0 || m_size == m_maxSize)
			{
				iterator ite(*this, INVALID_INDEX);
				return std::move(ite);
			}
			index_type index = pos.getIndex();
			const size_type remain = m_maxSize - m_size;
			const size_type _num = num < 0 || static_cast<size_type>(num) > remain ? remain : static_cast<size_type>(num);
			const size_type move_num = m_size - index;
			//移動
			move_desc(index + _num, index, move_num);
			//要素数変更
			m_size += _num;
			//挿入
			value_type* new_value = _ref_element(index);
			for (size_type i = 0; i < _num; ++i, ++new_value)
				new(new_value)value_type(args...);
			//終了
			iterator now(*this, index);
			return std::move(now);
		}
	private:
		//要素の削除
		void _erase(const index_type index, const size_type num)
		{
			const size_type remain = m_maxSize - m_size;
			const size_type _num = num < 0 || num > remain ? remain : num;
			const size_type move_num = m_size - index;
			//削除
			value_type* delete_value = _ref_element(index);
			for (size_type i = 0; i < _num; ++i, ++delete_value)
			{
				ope_type::callDestructor(delete_value);//デストラクタ呼び出し
				operator delete(delete_value, delete_value);//（作法として）deleteオペレータ呼び出し
			}
			//移動
			move_asc(index, index + _num, move_num);
			//要素数変更
			m_size -= _num;
		}
	public:
		//要素の削除
		//※デストラクタを呼び出す
		//※削除された直後の要素のイテレータを返す
		//※指定数が -1 なら以降の全要素を削除
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		iterator erase(iterator pos, const int num = 1)
		{
			if (pos.isNotExist() || num == 0 || m_size == 0)
			{
				iterator ite(*this, INVALID_INDEX);
				return std::move(ite);
			}
			const index_type index = pos.getIndex();
			//削除
			_erase(index, num);
			//終了
			iterator now(*this, index);
			return std::move(now);
		}
		//※範囲指定版
		iterator erase(iterator start, iterator end)
		{
			if (start.isNotExist() || end.isNotExist() || start >= end || m_size == 0)
			{
				iterator ite(*this, INVALID_INDEX);
				return std::move(ite);
			}
			index_type index = start.getIndex();
			index_type end_index = end.getIndex();
			const size_type num = end_index - index;
			//削除
			_erase(index, num);
			//終了
			iterator now(*this, index);
			return std::move(now);
		}
	public:
		//ソート
		//※イントロソートを使用
		//※ope_type::sort_predicate() を使用して探索（標準では、データ型の operator<() に従って探索）
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		void sort()
		{
			introSort(_ref_front(), m_size, typename ope_type::sort_predicate());
		}
		//※プレディケート関数指定版
		template<class PREDICATE>
		void sort(PREDICATE predicate)
		{
			introSort(_ref_front(), m_size, predicate);
		}
		//安定ソート
		//※挿入ソートを使用
		//※ope_type::sort_predicate() を使用して探索（標準では、データ型の operator<() に従って探索）
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		void stable_sort()
		{
			insertionSort(_ref_front(), m_size, typename ope_type::sort_predicate());
		}
		//※プレディケート関数指定版
		template<class PREDICATE>
		void stable_sort(PREDICATE predicate)
		{
			insertionSort(_ref_front(), m_size, predicate);
		}
	public:
		//線形探索
		//※探索値指定版
		//※ope_type::find_predicate() を使用して探索（標準では、データ型の operator==() に従って探索）
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で共有ロック（リードロック）の取得と解放を行う必要がある
		template<typename V>
		iterator find_value(const V& value)
		{
			value_type* found = linearSearchValue(_ref_front(), m_size, value, typename ope_type::find_predicate());
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//※比較関数＋値指定版
		template<typename V, class PREDICATE>
		iterator find_value(const V& value, PREDICATE predicate)
		{
			value_type* found = linearSearchValue(_ref_front(), m_size, value, predicate);
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//※比較関数指定版
		//※値の指定は関数に含んでおく（クロ―ジャを用いるなどする）
		template<class PREDICATE>
		iterator find(PREDICATE predicate)
		{
			value_type* found = linearSearch(_ref_front(), m_size, predicate);
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//二分探索
		//※探索値指定版
		//※ope_type::search_comparison() を使用して探索（標準では、データ型の operator==() と operator<() に従って探索）
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で共有ロック（リードロック）の取得と解放を行う必要がある
		template<typename V>
		iterator binary_search_value(const V& value)
		{
			value_type* found = binarySearchValue(_ref_front(), m_size, value, typename ope_type::search_comparison());
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//※比較関数＋値指定版
		template<typename V, class COMPARISON>
		iterator binary_search_value(const V& value, COMPARISON comparison)
		{
			value_type* found = binarySearchValue(_ref_front(), m_size, value, comparison);
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
		//※比較関数指定版
		//※値の指定は関数に含んでおく（クロ―ジャを用いるなどする）
		template<class COMPARISON>
		iterator binary_search(COMPARISON comparison)
		{
			value_type* found = binarySearch(_ref_front(), m_size, comparison);
			const index_type index = found ? _ref_index(found) : INVALID_INDEX;
			iterator ite(*this, index);
			return std::move(ite);
		}
	public:
		//コンストラクタ
		//※初期状態で使用中の要素数を指定する（-1で全要素を使用中にする）
		//※要素の初期化は行わない（必要なら size に 0 を指定して、後で resize() を呼び出す）
		template<size_type N>
		container(value_type(&array)[N], const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(array),
			m_maxSizeReal(N),
			m_maxSize(N),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_autoClearAttr(auto_clear_attr)
		{}
		//※ポインタと配列要素数指定版
		container(value_type* array, const size_type max_size, const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(array),
			m_maxSizeReal(max_size),
			m_maxSize(max_size),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_autoClearAttr(auto_clear_attr)
		{}
		//※voidポインタとバッファサイズ数指定版
		container(void* buff_ptr, const size_type buff_size, const int size = 0, const auto_clear_attr_t auto_clear_attr = NEVER_CLEAR) :
			m_array(static_cast<value_type*>(buff_ptr)),
			m_maxSizeReal(buff_size / sizeof(value_type)),
			m_maxSize(m_maxSizeReal),
			m_size(size < 0 || static_cast<size_type>(size) >= m_maxSize ? m_maxSize : static_cast<size_type>(size)),
			m_autoClearAttr(auto_clear_attr)
		{}
		//デフォルトコンストラクタ
		container() :
			m_array(nullptr),
			m_maxSizeReal(0),
			m_maxSize(0),
			m_size(0),
			m_autoClearAttr(NEVER_CLEAR)
		{}
		//デストラクタ
		~container()
		{
			//自動クリア属性が有効なら、自動クリアする
			if (m_array && m_autoClearAttr == AUTO_CLEAR)
				clear();
		}
	private:
		//フィールド
		value_type* m_array;//配列の先頭
		size_type m_maxSizeReal;//実際（初期）の最大要素数
		size_type m_maxSize;//最大要素数（後から変更可能なサイズ）
		size_type m_size;//使用中の要素数
		auto_clear_attr_t m_autoClearAttr;//コンテナ破棄時に残っている要素の自動クリア属性
		mutable lock_type m_lock;//ロックオブジェクト
	};
	//イテレータのムーブオペレータ
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator&& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator&& rhs)//VC++もOK
	{
		m_con = rhs.m_con;
		m_index = rhs.m_index;
		update(m_index);
		return *this;
	}
	//イテレータのコピーオペレータ
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator& rhs)//VC++もOK
	{
		m_con = rhs.m_con;
		m_index = rhs.m_index;
		update(m_index);
		return *this;
	}
	//イテレータのムーブコンストラクタ
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator&& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator&& obj) ://VC++もOK
		m_con(obj.m_con),
		m_index(obj.m_index),
		m_value(nullptr)
	{
		update(m_index);
	}
	//イテレータのコピーコンストラクタ
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator& obj) ://VC++もOK
		m_con(obj.m_con),
		m_index(obj.m_index),
		m_value(nullptr)
	{
		update(m_index);
	}
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace dynamic_array

//--------------------------------------------------------------------------------
//動的配列テスト
//--------------------------------------------------------------------------------

#include <algorithm>//std::for_each用
#include <vector>//std::vector用（比較用）

//----------------------------------------
//テスト用補助関数
#ifdef PRINT_TEST_DATA_DETAIL
template<typename... Tx>
inline int printf_detail(const char* fmt, Tx... args)
{
	return printf(fmt, args...);
}
#else//PRINT_TEST_DATA_DETAIL
inline int printf_detail(const char* fmt, ...){ return 0; }
#endif//PRINT_TEST_DATA_DETAIL

//----------------------------------------
//テストデータ
struct data_t
{
	int m_key;//キー
	int m_val;//データ

	//コンストラクタ
	data_t(const int key, const int val) :
		m_key(key),
		m_val(val)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d, %d)\n", key, val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	//デフォルトコンストラクタ
	data_t() :
		m_key(0),
		m_val(0)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor()\n");
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	//デストラクタ
	~data_t()
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::destructor(): key=%d, val=%d\n", m_key, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
#ifdef TEST_DATA_WATCH_CONSTRUCTOR
	//ムーブオペレータ
	data_t& operator=(const data_t&& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::move_operator\n");
		return *this;
	}
	//コピーオペレータ
	data_t& operator=(const data_t& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::copy_operator\n");
		return *this;
	}
	//ムーブコンストラクタ
	data_t(const data_t&& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::move_constructor\n");
	}
	//コピーコンストラクタ
	data_t(const data_t& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::copy_constructor\n");
	}
#endif//TEST_DATA_WATCH_CONSTRUCTOR
	//デフォルトのソート用の比較演算子（必須ではない）
	inline bool operator<(const data_t& rhs) const
	{
		return m_key < rhs.m_key;
	}
	//デフォルトの線形／二分探索用の比較演算子（必須ではない）
	inline bool operator==(const int key) const
	{
		return m_key == key;
	}
	inline bool operator<(const int key) const
	{
		return m_key < key;
	}
};
//※std::binary_searchを使用する場合は、このオペレータも必要
static bool operator<(const int key, const data_t& rhs)
{
	return key < rhs.m_key;
}
//----------------------------------------
//テストデータ操作クラス①：デフォルトのまま使う
struct ope_t : public dynamic_array::base_ope_t<ope_t, data_t>{};
//----------------------------------------
//テストデータ操作クラス②：ソート／探索方法をデフォルトから変える
struct another_ope_t : public dynamic_array::base_ope_t<ope_t, data_t>
{
	//ソート用プレディケート関数オブジェクト
	//※m_valメンバーを基準にソート
	struct sort_predicate{
		inline bool operator()(const value_type& lhs, const value_type& rhs) const
		{
			return lhs.m_val < rhs.m_val;
		}
	};

	//線形探索用プレディケート関数オブジェクト
	//※m_valメンバーを探索
	struct find_predicate{
		inline bool operator()(const value_type& lhs, const int rhs) const
		{
			return lhs.m_val == rhs;
		}
	};

	//二分探索用比較関数オブジェクト
	//※m_valメンバーを比較
	struct search_comparison{
		inline int operator()(const value_type& lhs, const int rhs) const
		{
			return rhs - lhs.m_val;
		}
	};
	
	//デストラクタ呼び出しを禁止したい場合、
	//この空のメソッドを定義する。
	inline static void callDestructor(value_type* obj)
	{
		//何もしない
	}
};
//----------------------------------------
//テストデータ操作クラス③：ロックを有効化する
struct mt_ope_t : public dynamic_array::base_ope_t<mt_ope_t, data_t>
{
	//ロック型
	typedef shared_spin_lock lock_type;//ロックオブジェクトを指定
};

//----------------------------------------
//スレッドテスト用関数の参照
template <class C>
extern void testThread(const char* container_type);

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//--------------------
	//テスト①：プリミティブ型の配列を扱う場合
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(Primitive type)]\n");
		
		int arr[20];//配列

		//int型用のデータ操作クラス定義
		struct ope_t : public dynamic_array::base_ope_t<ope_t, int>{};

		//コンテナ生成
		//※既存の配列を渡して動的配列コンテナとして扱う
		dynamic_array::container<ope_t> con(arr);//配列要素数を自動取得

		//データを表示
		auto printAll = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array=");
			if (con.empty())
				printf("(empty)");
			for (auto val : con)
				printf(" %d", val);
			printf("\n");
		};

		//データを逆順に表示
		auto printReverse = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array(reverse)=");
			if (con.empty())
				printf("(empty)");
			std::for_each(con.rbegin(), con.rend(),
				[](int val)
				{
					printf(" %d", val);
				}
			);
			printf("\n");
		};

		//値を追加
		printf("\n");
		printf("[push_back]\n");
		con.push_back(5);
		con.push_back(8);
		con.push_back(3);
		con.push_back(1);
		con.push_back(7);
		con.push_back(4);
		con.push_back(13);
		con.push_back(10);
		con.push_back(5);

		//データを表示
		printAll();

		//データを逆順に表示
		printReverse();

		//リサイズ（拡大）
		printf("\n");
		printf("[resize(expand)]\n");
		con.resize(12, 1000);//12件に拡張
		printAll();//全件表示

		//ソ―ト
		printf("\n");
		printf("[sort]\n");
		con.sort();//高速ソート
		//con.stable_sort();//安定ソート
		//std::sort(con.begin(), con.end());//高速ソート(STL版)
		//std::stable_sort(con.begin(), con.end());//安定ソート(STL版)
		printAll();//全件表示

		//逆順にソート ※カスタムプレディケート関数を使用
		printf("\n");
		printf("[custom sort]\n");
		auto reverse_pred = [](const int lhs, const int rhs) -> bool {return lhs > rhs; };
		con.sort(reverse_pred);//高速ソート
		//con.stable_sort(reverse_pred);//安定ソート
		//std::sort(con.begin(), con.end(), reverse_pred);//高速ソート(STL版)
		//std::stable_sort(con.begin(), con.end(), reverse_pred);//安定ソート(STL版)
		printAll();//全件表示

		//ポップ(1)
		printf("\n");
		printf("[pop_back(1)]\n");
		{
			const int* val = con.back();//末尾の値を取得
			printf("back=%d\n", *val);
			con.pop_back();//末尾を削除
			printAll();//全件表示
		}

		//ポップ(2)
		printf("\n");
		printf("[pop_back(2)]\n");
		{
			int pop_val;
			con.pop_back(pop_val);//値のコピーを受け取って末尾を削除
			printf("pop_back=[%d]\n", pop_val);
			printAll();//全件表示
		}

		//線形探索
		printf("\n");
		printf("[find]\n");
		printAll();//全件表示
		auto find = [&con](const int val)
		{
			printf("find_value(%d)=", val);
			auto ite = con.find_value(val);//線形探索
			//auto ite = std::find(con.begin(), con.end(), val);//線形探索(STL版)
			if (ite.isExist())
			{
				printf("%d", *ite);
				++ite;
				if (ite.isExist())
					printf(" next=%d", *ite);
			}
			else
				printf("(not found)");
			printf("\n");
		};
		find(5);
		find(6);
		find(7);

		//二分探索（ソート前）
		printf("\n");
		printf("[binary search(before sort)]\n");
		printAll();//全件表示
		auto binary_search = [&con](const int val)
		{
			printf("binary_search_value(%d)=", val);
			auto ite = con.binary_search_value(val);//二分探索
			if (ite.isExist())
			{
			//if(std::binary_search(con.begin(), con.end(), val))//二分探索(STL版)
			//{
			//	auto ite = std::lower_bound(con.begin(), con.end(), val);
				printf("%d", *ite);
				--ite;
				if (ite.isExist())
					printf(" prev=%d", *ite);
			}
			else
				printf("(not found)");
			printf("\n");
		};
		binary_search(5);
		binary_search(6);
		binary_search(7);

		//二分探索（ソート後）
		printf("\n");
		printf("[binary search(after sort)]\n");
		con.sort();//ソート済み状態にする
		printAll();//全件表示
		binary_search(5);
		binary_search(6);
		binary_search(7);

		//削除１：イテレータと数で指定
		printf("\n");
		printf("[erase(1)]\n");
		{
			auto ite = con.end();
			ite -= 4;
			con.erase(ite, 2);//後ろから4つ目の位置から2件削除
			printAll();//全件表示
		}

		//削除２：イテレータの範囲で指定
		printf("\n");
		printf("[erase(2)]\n");
		{
			auto start = con.end();
			start -= 4;
			auto end = start;
			end += 2;
			con.erase(start, end);//後ろから4つ目の位置から2件削除
			printAll();//全件表示
		}

		//挿入
		printf("\n");
		printf("[insert]\n");
		{
			auto ite = con.begin();
			++ite;
			con.insert(ite, 5, 999);//先頭から2つ目の位置に5件挿入
			printAll();//全件表示
		}

		//リサイズ（縮小）
		printf("\n");
		printf("[resize(shrink)]\n");
		con.resize(5);//要素数=5に縮小
		printAll();//全件表示

		//最大サイズを縮小
		printf("\n");
		printf("[shrink_to_fit]\n");
		con.shrink_to_fit();
		printAll();//全件表示

		//データ割り当て
		printf("\n");
		printf("[assign]\n");
		con.assign(-1, 0);//※-1で最大要素数全件に割り当て
		printAll();//全件表示

		//クリア
		printf("\n");
		printf("[clear]\n");
		con.clear();
		printAll();//全件表示
		//printReverse();//全件逆順表示
	}

	//--------------------
	//テスト②：ユーザー定義型を扱う場合
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(User defined type)]\n");

		//配列データ
		data_t array[20];
		//※この宣言だと、デフォルトコンストラクタとデストラクタが呼び出される点に注意

		//動的配列コンテナ生成
		typedef dynamic_array::container<ope_t> container_t;
		container_t con(array);//※配列要素数を自動取得
		//container_t con(&array[0], 10);//※要素数を明示的に受け渡す方法
		//char buff[1024];
		//container_t con(buff, sizeof(buff), dynamic_array::AUTO_CLEAR);//バッファとバッファサイズを受け渡す方法＋コンテナ破棄時に自動クリア属性追加
		//                                                               //（コンテナのデストラクタで、残っている要素のデストラクタを呼び出す。デフォルトは自動クリアなし）
		//container_t con;//初期状態で配列の割り当てをせずにコンテナを生成する場合

		//後から配列を割り当てる場合は assign_array() を使用する
		//container_t con;//デフォルトコンストラクタ ※コンテナ生成時に配列を割り当てない
		//con.assign_array(array);//※配列要素数を自動取得
		//con.assign_array(&array[0], 10);//※要素数を明示的に受け渡す方法
		//char buff[1024];
		//con.assign_array(buff, sizeof(buff), dynamic_array::AUTO_CLEAR);//バッファとバッファサイズを受け渡す方法＋コンテナ破棄時に自動クリア属性追加
		//                                                                //（コンテナのデストラクタで、残っている要素のデストラクタを呼び出す。デフォルトは自動クリアなし）

		//データを表示
		auto printAll = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array=");
			if (con.empty())
			{
				printf("(empty)\n");
				return;
			}
			for (auto& data : con)
			{
				printf(" [%d:%d]", data.m_key, data.m_val);
			}
			printf("\n");
		};

		//データを逆順に表示
		auto printReverse = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array(reverse)=");
			if (con.empty())
			{
				printf("(empty)\n");
				return;
			}
			std::for_each(con.rbegin(), con.rend(),
				[](data_t& data)
				{
					printf(" [%d:%d]", data.m_key, data.m_val);
				}
			);
			printf("\n");
		};

		//データ登録１：push_back()メソッド＋コンストラクタパラメータ（コンストラクタ呼び出しを行う）
		printf("\n");
		printf("[push_back(1)]\n");
		con.push_back(5, 101);
		con.push_back(8, 102);
		con.push_back(3, 103);

		//データを表示
		printAll();

		//データを逆順に表示
		printReverse();

		//データ登録２：push_back()メソッド＋オブジェクト（オブジェクトのコピーを行う）
		printf("\n");
		printf("[push_back(2)]\n");
		{ data_t obj(1, 104); con.push_back(obj); }//コピーで追加
		{ data_t obj(7, 105); con.push_back(obj); }//コピーで追加
		{ data_t obj(4, 106); con.push_back(obj); }//コピーで追加
		con.push_back(data_t(13, 107));//ムーブ（右辺値）で追加
		con.push_back(data_t(10, 108));//ムーブ（右辺値）で追加
		con.push_back(data_t(5, 109));//ムーブ（右辺値）で追加
		printAll();//全件表示

		//リサイズ１：resize()メソッド＋コンストラクタパラメータ（コンストラクタ呼び出しを行う）
		printf("\n");
		printf("[resize(1)]\n");
		con.resize(12, 1000, 1000);//12件に拡張
		printAll();

		//リサイズ２：resize()メソッド＋オブジェクト（オブジェクトのコピーを行う）
		printf("\n");
		printf("[resize(2)]\n");
		{
			data_t prototype(1001, 1001);//コピー用のオブジェクト
			con.resize(15, prototype);//15件に拡張
		}
		printAll();

		//ソ―ト
		printf("\n");
		printf("[sort]\n");
		con.sort();//高速ソート
		//con.stable_sort();//安定ソート
		//std::sort(con.begin(), con.end());//高速ソート(STL版)
		//std::stable_sort(con.begin(), con.end());//安定ソート(STL版)
		printAll();//全件表示

		//逆順にソート ※カスタムプレディケート関数を使用
		printf("\n");
		printf("[custom sort]\n");
		auto reverse_pred = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key > rhs.m_key; };
		con.sort(reverse_pred);//高速ソート
		//con.stable_sort(reverse_pred);//安定ソート
		//std::sort(con.begin(), con.end(), reverse_pred);//高速ソート(STL版)
		//std::stable_sort(con.begin(), con.end(), reverse_pred);//安定ソート(STL版)
		printAll();//全件表示

	#if 0
		{
			printf("\n");
			printf("constructor\n");
			container_t::iterator ite = con.begin();
			container_t::reverse_iterator rite = con.rbegin();
			container_t::iterator ite_end = con.end();
			container_t::reverse_iterator rite_end = con.rend();
			container_t::iterator ite2 = con.rbegin();
			container_t::reverse_iterator rite2 = con.begin();
			container_t::iterator ite2_end = con.rend();
			container_t::reverse_iterator rite2_end = con.end();
			if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
			printf("copy operator\n");
			ite = con.begin();
			rite = con.rbegin();
			ite_end = con.end();
			rite_end = con.rend();
			ite2 = con.rbegin();
			rite2 = con.begin();
			ite2_end = con.rend();
			rite2_end = con.end();
			if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
			for (int i = 0; i <= 3; ++i)
			{
				printf("[%d]\n", i);
				ite = ite[i];
				rite = rite[i];
				ite_end = ite_end[i];
				rite_end = rite_end[i];
				ite2 = ite2[i];
				rite2 = rite2[i];
				ite2_end = ite2_end[i];
				rite2_end = rite2_end[i];
				if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
				if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
				if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
				if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
				if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
				if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
				if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
				if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
			}
			printf("+= 3\n");
			ite += 3;
			rite += 3;
			ite_end += 3;
			rite_end += 3;
			ite2 += 3;
			rite2 += 3;
			ite2_end += 3;
			rite2_end += 3;
			if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
			printf("-= 3\n");
			ite -= 3;
			rite -= 3;
			ite_end -= 3;
			rite_end -= 3;
			ite2 -= 3;
			rite2 -= 3;
			ite2_end -= 3;
			rite2_end -= 3;
			if (ite.isExist()) printf("ite:[%d] key=%d, value=%d\n", ite.getIndex(), ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] key=%d, value=%d\n", rite.getIndex(), rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] key=%d, value=%d\n", ite_end.getIndex(), ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] key=%d, value=%d\n", rite_end.getIndex(), rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] key=%d, value=%d\n", ite2.getIndex(), ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] key=%d, value=%d\n", rite2.getIndex(), rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] key=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] key=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_key, rite2_end->m_val);
		}
	#endif

		//末尾をポップ(1)
		printf("\n");
		printf("[pop_back(1)]\n");
		{
			const data_t* val = con.back();//末尾の値を取得
			printf("back=[%d:%d]\n", val->m_key, val->m_val);
			con.pop_back();//末尾を削除
			printAll();//全件表示
		}

		//末尾をポップ(2)
		printf("\n");
		printf("[pop_back(2)]\n");
		{
			data_t pop_val;
			con.pop_back(pop_val);//値のコピーを受け取って末尾を削除
			printf("pop_back=[%d:%d]\n", pop_val.m_key, pop_val.m_val);
			printAll();//全件表示
		}

		//線形探索
		printf("\n");
		printf("[find]\n");
		printAll();//全件表示
		auto find = [&con](const int key)
		{
			printf("find_value(key=%d)=", key);
			auto ite = con.find_value(key);//線形探索
			//auto ite = std::find(con.begin(), con.end(), key);//線形探索(STL版)
			if (ite.isExist())
			{
				printf(" [%d:%d]", ite->m_key, ite->m_val);
				++ite;
				if (ite.isExist())
					printf(" next=[%d:%d]", ite->m_key, ite->m_val);
			}
			else
				printf("(not found)");
			printf("\n");
		};
		find(5);
		find(6);
		find(7);

		//二分探索（ソート前）
		printf("\n");
		printf("[binary search(before sort)]\n");
		printAll();//全件表示
		auto binary_search = [&con](const int key)
		{
			printf("binary_search_value(key=%d)=", key);
			auto ite = con.binary_search_value(key);//二分探索
			if (ite.isExist())
			{
			//if (std::binary_search(con.begin(), con.end(), key))//二分探索(STL版)
			//{
			//	auto ite = std::lower_bound(con.begin(), con.end(), key);
				printf(" [%d:%d]", ite->m_key, ite->m_val);
				--ite;
				if (ite.isExist())
					printf(" prev=[%d:%d]", ite->m_key, ite->m_val);
			}
			else
				printf("(not found)");
			printf("\n");
		};
		binary_search(5);
		binary_search(6);
		binary_search(7);

		//二分探索（ソート後）
		printf("\n");
		printf("[binary search(after sort)]\n");
		con.sort();//ソート済み状態にする
		printAll();//全件表示
		binary_search(5);
		binary_search(6);
		binary_search(7);

		//削除１：イテレータと削除数で指定
		printf("\n");
		printf("[erase(1)]\n");
		{
			auto ite = con.end();
			ite -= 4;
			con.erase(ite, 2);//後ろから4つ目の位置から2件削除
			printAll();//全件表示
		}

		//削除２：イテレータの範囲で指定
		printf("\n");
		printf("[erase(2)]\n");
		{
			auto start = con.end();
			start -= 4;
			auto end = start;
			end += 2;
			con.erase(start, end);//後ろから4つ目の位置から2件削除
			printAll();//全件表示
		}

		//挿入１：insert()メソッド＋コンストラクタパラメータ（コンストラクタ呼び出しを行う）
		printf("\n");
		printf("[insert(1)]\n");
		{
			auto ite = con.begin();
			++ite;
			con.insert(ite, 5, 99, 999);//先頭から2つ目の位置に5件挿入
			printAll();//全件表示
		}

		//挿入２：insert()メソッド＋オブジェクト（オブジェクトのコピーを行う）
		printf("\n");
		printf("[insert(2)]\n");
		{
			auto ite = con.begin();
			ite += 10;
			data_t prototype(88, 888);//コピー用のオブジェクト
			con.insert(ite, 2, prototype);//先頭から11個目の位置に2件挿入
			printAll();//全件表示
		}

		//リサイズ（縮小）
		printf("\n");
		printf("[resize(shrink)]\n");
		con.resize(5);//要素数=5に縮小
		printAll();//全件表示

		//最大サイズを縮小
		printf("\n");
		printf("[shrink_to_fit]\n");
		con.shrink_to_fit();
		printAll();//全件表示

		//データ割り当て１：assign()メソッド＋コンストラクタパラメータ（コンストラクタ呼び出しを行う）
		printf("\n");
		printf("[assign(1)]\n");
		{
			con.assign(2, 0, 0);//先頭から2件に割り当て
			printAll();//全件表示
		}

		//データ割り当て２：assign()メソッド＋オブジェクト（オブジェクトのコピーを行う）
		printf("\n");
		printf("[assign(2)]\n");
		{
			data_t prototype(-1, 0);//コピー用のオブジェクト
			con.assign(-1, prototype);//※-1で最大要素数全件に割り当て
			printAll();//全件表示
		}

		//クリア
		printf("\n");
		printf("[clear]\n");
		con.clear();
		printAll();//全件表示
		//printReverse();//全件逆順表示
	}

	//--------------------
	//テスト③：ソート、探索の設定を変える
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(User defined type with custom operator type)]\n");

		//配列データ
		data_t array[20];

		//動的配列コンテナ生成
		typedef dynamic_array::container<another_ope_t> container_t;
		container_t con(array);

		//コンテナのインスタンス生成時に配列を渡せない場合は、sertArray() を使用する
		//container_t con;
		//con.assign_array(array);

		//データ登録１：push_back()メソッド＋コンストラクタパラメータ（コンストラクタ呼び出しを行う）
		printf("\n");
		printf("[push_back]\n");
		con.push_back(1, 105);
		con.push_back(1, 108);
		con.push_back(2, 103);
		con.push_back(2, 101);
		con.push_back(3, 107);
		con.push_back(3, 104);
		con.push_back(4, 113);
		con.push_back(4, 111);
		con.push_back(5, 105);
		con.push_back(5, 106);

		//データを表示
		auto printAll = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array=");
			if (con.empty())
			{
				printf("(empty)\n");
				return;
			}
			for (auto& data : con)
			{
				printf(" [%d:%d]", data.m_key, data.m_val);
			}
			printf("\n");
		};
		printAll();

		//ソ―ト
		printf("\n");
		printf("[sort]\n");
		con.sort();//高速ソート
		//con.stable_sort();//安定ソート
		printAll();//全件表示

		//線形探索
		printf("\n");
		printf("[find]\n");
		auto find = [&con](const int value)
		{
			printf("find_value(value=%d)=", value);
			auto ite = con.find_value(value);//線形探索
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		find(101);
		find(110);
		find(103);

		//二分探索
		printf("\n");
		printf("[binary search]\n");
		auto binary_search = [&con](const int value)
		{
			printf("binary_search_value(value=%d)=", value);
			auto ite = con.binary_search_value(value);//二分探索
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		binary_search(101);
		binary_search(110);
		binary_search(103);

		//カスタムソート
		{
			printf("\n");
			printf("[sort with custom predicate]\n");
			auto predicate = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key < rhs.m_key ? true : lhs.m_key == rhs.m_key ? lhs.m_val > rhs.m_val : false; };
			con.sort(predicate);//高速ソート
			//con.stable_sort(reverse_pred);//安定ソート
			printAll();//全件表示
		}

		//カスタム線形探索(1)
		printf("\n");
		printf("[find with custom predicate(1)]\n");
		auto custom_find1 = [&con](const int key, const int value)
		{
			printf("find(key=%d, value=%d)=", key, value);
			auto predicate = [&key, &value](const data_t& lhs) -> bool { return lhs.m_key == key && lhs.m_val == value; };
			auto ite = con.find(predicate);//線形探索
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_find1(2, 101);
		custom_find1(2, 102);
		custom_find1(2, 103);

		//カスタム二分探索(1)
		printf("\n");
		printf("[binary search with custom comparison(1)]\n");
		auto custom_binary_search1 = [&con](const int key, const int value)
		{
			printf("binary_search_value(key=%d, value=%d)=", key, value);
			auto comparison = [&key, &value](const data_t& lhs) -> int { return key == lhs.m_key ? lhs.m_val - value : key > lhs.m_key ? 1 : -1; };
			auto ite = con.binary_search(comparison);//二分探索
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_binary_search1(2, 101);
		custom_binary_search1(2, 102);
		custom_binary_search1(2, 103);

		//カスタム線形探索(2)
		printf("\n");
		printf("[find with custom predicate(2)]\n");
		auto custom_find2 = [&con](const int key)
		{
			printf("find(key=%d)=", key);
			auto predicate = [](const data_t& lhs, const int key) -> bool { return lhs.m_key == key; };
			auto ite = con.find_value(key, predicate);//線形探索
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_find2(2);
		custom_find2(7);
		custom_find2(3);

		//カスタム二分探索(2)
		printf("\n");
		printf("[binary search with custom comparison(2)]\n");
		auto custom_binary_search2 = [&con](const int key)
		{
			printf("binary_search_value(key=%d)=", key);
			auto comparison = [](const data_t& lhs, const int key) -> int { return key - lhs.m_key; };
			auto ite = con.binary_search_value(key, comparison);//二分探索
			if (ite.isExist())
				printf(" [%d:%d]", ite->m_key, ite->m_val);
			else
				printf("(not found)");
			printf("\n");
		};
		custom_binary_search2(2);
		custom_binary_search2(7);
		custom_binary_search2(3);
	}

	//--------------------
	//テスト④：データ設定済みの既存の配列を扱う
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(User defined type for existing data)]\n");

		//データ設定済みの既存の配列
		data_t array[] = 
		{
			{ 6, 111 },
			{ 2, 103 },
			{ 2, 104 },
			{ 4, 107 },
			{ 3, 105 },
			{ 3, 106 },
			{ 1, 102 },
			{ 5, 109 },
			{ 1, 101 },
			{ 4, 108 },
			{ 5, 110 },
			{ 6, 112 },
		};

		//設定済みのデータを残したまま、動的配列コンテナのデータとして活用
		dynamic_array::container<ope_t> con(array, -1);//第二引数で使用中のデータサイズを指定（-1で全域）
		
		//コンテナのインスタンス生成時に配列を渡せない場合は、sertArray() を使用する
		//dynamic_array::container<ope_t> con;
		//con.assign_array(array, -1);//第二引数で使用中のデータサイズを指定（-1で全域）

		//データを表示
		auto printAll = [&con]()
		{
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			printf("array=");
			if (con.empty())
			{
				printf("(empty)\n");
				return;
			}
			for (auto& data : con)
			{
				printf(" [%d:%d]", data.m_key, data.m_val);
			}
			printf("\n");
		};
		printf("\n");
		printf("[sort(before)]\n");
		printAll();

		//ソ―ト
		printf("\n");
		printf("[sort(after)]\n");
		//con.sort();//高速ソート
		con.stable_sort();//安定ソート
		printAll();//全件表示
	}

	//--------------------
	//テスト⑤：ロック制御を行う
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for dynamic_array::container(User defined type for multi-thread)]\n");

		testThread<dynamic_array::container<ope_t> >("normal container");//ロックなし版のスレッド
		testThread<dynamic_array::container<mt_ope_t> >("multi-thread container");//ロックあり版のスレッド
	}

	//--------------------
	//テスト⑥：大量登録テスト
	{
		//経過時間を表示
		auto printElapsedTime = [](const std::chrono::system_clock::time_point& prev_time, const bool is_show) -> std::chrono::system_clock::time_point
		{
			//最終経過時間表示
			const auto now_time = std::chrono::system_clock::now();
			const auto duration = now_time - prev_time;
			const double elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()) / 1000000000.;
			if (is_show)
				printf("*elapsed_time=%.9llf sec\n", elapsed_time);
			return now_time;
		};
		
		{
			printf("--------------------------------------------------------------------------------\n");
			printf("[Test for performance dynamic_array]\n");
			
			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//データを初期化
			printf("\n");
			printf("[create container & assign() * %d]\n", TEST_DATA_NUM);
			const std::size_t buff_size = sizeof(data_t)* TEST_DATA_NUM;
			char* buff = new char[buff_size];
			typedef dynamic_array::container<ope_t> container_t;
			container_t* con = new container_t(buff, buff_size, 0, dynamic_array::AUTO_CLEAR);//コンテナ生成（バッファを割り当て）
			con->assign(-1, 0, 0);//全件初期化
			prev_time = printElapsedTime(prev_time, true);

			//データをクリア
			printf("\n");
			printf("[clear() * %d]\n", TEST_DATA_NUM);
			con->clear();
			prev_time = printElapsedTime(prev_time, true);

			//データを登録
			printf("\n");
			printf("[push_back() * %d]\n", TEST_DATA_NUM);
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					con->push_back(i, 10000000 + i);
					++num;
				}
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//イテレータ(1)
			printf("\n");
			printf("[iterator(1)]\n");
			{
				printf_detail("size=%d, max_size=%d(%d)\n", con->size(), con->max_size(), con->max_size_real());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				for (const data_t& value : *con)
				{
					printf_detail(" [%d:%d]", value.m_key, value.m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//逆順ソート
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			con->sort(reverse_sort);
			prev_time = printElapsedTime(prev_time, true);

			//イテレータ(2)
			printf("\n");
			printf("[iterator(2)]\n");
			{
				printf_detail("size=%d, max_size=%d(%d)\n", con->size(), con->max_size(), con->max_size_real());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				forEach(*con, [&num](const data_t& value)
					{
						printf_detail(" [%d:%d]", value.m_key, value.m_val);
						++num;
					}
				);
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//正順ソート
			printf("\n");
			printf("[sort]\n");
			con->sort();
			prev_time = printElapsedTime(prev_time, true);

			//リバースイテレータ
			printf("\n");
			printf("[reverse_iterator]\n");
			{
				printf_detail("size=%d, max_size=%d(%d)\n", con->size(), con->max_size(), con->max_size_real());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				reverseForEach(*con, [&num](const data_t& value)
					{
						printf_detail(" [%d:%d]", value.m_key, value.m_val);
						++num;
					}
				);
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//線形探索
			printf("\n");
			printf("[find_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += (TEST_DATA_NUM / 100 + 1))
				{
					container_t::iterator ite = std::move(con->find_value(i));
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//二分探索
			printf("\n");
			printf("[binary_search_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					container_t::iterator ite = std::move(con->binary_search_value(i));
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//データを破棄
			printf("\n");
			printf("[delete container]\n");
			delete con;//コンテナを破棄
			con = nullptr;
			delete buff;
			buff = nullptr;
			prev_time = printElapsedTime(prev_time, true);

			//総時間
			printf("\n");
			printf("[finish]\n");
			printElapsedTime(begin_time, true);
		}

		{
			printf("--------------------------------------------------------------------------------\n");
			printf("[Test for performance std::vector]\n");

			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//データを初期化
			printf("\n");
			printf("[create container & assign() * %d]\n", TEST_DATA_NUM);
			typedef std::vector<data_t> container_t;
			container_t* con = new container_t();//std::vectorコンテナを生成
			con->reserve(TEST_DATA_NUM);
			{
				data_t prototype(0, 0);
				con->assign(TEST_DATA_NUM, prototype);
			}
			prev_time = printElapsedTime(prev_time, true);

			//データをクリア
			printf("\n");
			printf("[clear() * %d]\n", TEST_DATA_NUM);
			con->clear();
			prev_time = printElapsedTime(prev_time, true);

			//データを登録
			printf("\n");
			printf("[push_back() * %d]\n", TEST_DATA_NUM);
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					data_t value(i, 10000000 + i);
					con->push_back(std::move(value));
					++num;
				}
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//イテレータ(1)
			printf("\n");
			printf("[iterator(1)]\n");
			{
				printf_detail("size=%d, max_size=%d\n", con->size(), con->max_size());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				for (const data_t& value : *con)
				{
					printf_detail(" [%d:%d]", value.m_key, value.m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//逆順ソート
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			std::sort(con->begin(), con->end(), reverse_sort);
			prev_time = printElapsedTime(prev_time, true);

			//イテレータ(2)
			printf("\n");
			printf("[iterator(2)]\n");
			{
				printf_detail("size=%d, max_size=%d\n", con->size(), con->max_size());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				std::for_each(con->begin(), con->end(), [&num](const data_t& value)
					{
						printf_detail(" [%d:%d]", value.m_key, value.m_val);
						++num;
					}
				);
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//正順ソート
			printf("\n");
			printf("[sort]\n");
			std::sort(con->begin(), con->end());
			prev_time = printElapsedTime(prev_time, true);

			//リバースイテレータ
			printf("\n");
			printf("[reverse_iterator]\n");
			{
				printf_detail("size=%d, max_size=%d\n", con->size(), con->max_size());
				printf_detail("array=");
				if (con->empty())
					printf_detail("(empty)");
				int num = 0;
				std::for_each(con->rbegin(), con->rend(), [&num](const data_t& value)
					{
						printf_detail(" [%d:%d]", value.m_key, value.m_val);
						++num;
					}
				);
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//線形探索
			printf("\n");
			printf("[find_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += (TEST_DATA_NUM / 100 + 1))
				{
					container_t::iterator ite = std::find(con->begin(), con->end(), i);
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//二分探索
			printf("\n");
			printf("[binary_search_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					container_t::iterator ite = std::lower_bound(con->begin(), con->end(), i);
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//データを破棄
			printf("\n");
			printf("[delete container]\n");
			delete con;//std::vectorコンテナを破棄
			con = nullptr;
			prev_time = printElapsedTime(prev_time, true);

			//総時間
			printf("\n");
			printf("[finish]\n");
			printElapsedTime(begin_time, true);
		}
	}

	printf("\n");
	printf("- end -\n");
	
	return EXIT_SUCCESS;
}

//--------------------
//テスト⑤：ロック制御を行う

#include <thread>//C++11 std::thread用
#include <mutex>//C++11 std::mutex用
#include <condition_variable>//C++11 std::condition_variable用
#include <atomic>//C++11 std::atomic用
#include <chrono>//C++11 std::chrono用

template <class C>
void testThread(const char* container_type)
{
	typedef C container_t;//テンプレートパラメータで、ロックありコンテナか、ロックなしコンテナの型を受け取る
	typedef typename container_t::lock_type lock_type;//ロック制御型

	printf("\n");
	printf("[%s]\n", container_type);
	
	//配列データ
	data_t array[100];

	//動的配列コンテナ生成
	container_t con(array);

	//条件変数
	std::condition_variable cond;
	std::mutex mutex;
	std::atomic<bool> is_ready;
	std::atomic<int> start_count;
	is_ready.store(false);
	auto isReady = [&is_ready]() -> bool
	{
		return is_ready.load();
	};
	start_count.store(0);

	//スレッド
	auto test_thread = [&con, &mutex, &cond, &start_count, &isReady](const int key, const int value)
	{
		{
			std::unique_lock<std::mutex> lock(mutex);
			cond.wait(lock, isReady);
		}
		start_count.fetch_add(1);
		std::this_thread::sleep_for(std::chrono::microseconds(1));
		//スタート
		{
			lock_guard<lock_type> lock(con);//ライト・ロック取得 ※コンテナを渡してスコープロック
			con.push_back(key, value);
		}
		{
			lock_guard<lock_type> lock(con);//ライト・ロック取得 ※コンテナを渡してスコープロック
			auto ite = con.find_value(key);
			std::this_thread::sleep_for(std::chrono::microseconds(1));
			con.erase(ite, 1);
		}
		{
			lock_guard<lock_type> lock(con);//ライト・ロック取得 ※コンテナを渡してスコープロック
			con.push_back(key, value + 10);
		}
	};

	static const int THREAD_NUM = 10;//同時実行スレッド数
	{
		std::thread* th[THREAD_NUM];

		//スレッド生成
		is_ready.store(false);
		start_count.store(0);
		{
			std::lock_guard<std::mutex> lock(mutex);
			for (int i = 0; i < THREAD_NUM; ++i)
				th[i] = new std::thread(test_thread, i, i);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

		//スレッド開始
		//※条件変数を使用して、全スレッドのタイミングを揃えて一斉に処理開始
		is_ready.store(true);
		while (true)
		{
			cond.notify_all();
			//std::this_thread::sleep_for(std::chrono::milliseconds(1));
			if (start_count.load() == THREAD_NUM)
				break;
		}

		//配列を表示
		auto print_data = [&con](const char* caption)
		{
			shared_lock_guard<lock_type> lock(con);//リード・ロック取得 ※コンテナを渡してスコープロック
			printf("(%s)\n", caption);
			printf("size=%d, max_size=%d(%d)\n", con.size(), con.max_size(), con.max_size_real());
			std::this_thread::sleep_for(std::chrono::microseconds(1));
			printf("array=");
			if (con.empty())
			{
				printf("(empty)");
			}
			else
			{
				for (auto& data : con)
				{
					printf(" [%d:%d]", data.m_key, data.m_val);
				}
			}
			printf("\n");
		};
		print_data("before");

		//スレッド終了待ち
		for (int i = 0; i < THREAD_NUM; ++i)
		{
			th[i]->join();
			delete th[i];
			th[i] = nullptr;
		}

		//配列を表示
		print_data("after");
	}
}

// End of file
