//--------------------------------------------------------------------------------
//双方向連結リストテスト用設定とコンパイラスイッチ
static const int TEST_DATA_NUM = 10;//大量登録テストデータの登録数
//static const int TEST_DATA_NUM = 20000;//大量登録テストデータの登録数

static const int TEST_DATA_FIND_NUM = 1000;//大量テストの線形探索回数
static const int TEST_DATA_FIND_STEP = TEST_DATA_NUM > TEST_DATA_FIND_NUM ? TEST_DATA_NUM / TEST_DATA_FIND_NUM : 1;//大量テストの線形実行ステップ

#define ENABLE_SORT_TEST//大量データテストでソートを実行する場合、このマクロを有効化する

#define PRINT_TEST_DATA_DETAIL//テストデータの詳細タを表示する場合は、このマクロを有効化する
//#define TEST_DATA_WATCH_CONSTRUCTOR//コンストラクタ／デストラクタ／代入演算子の動作を確認する場合、このマクロを有効化する

//--------------------------------------------------------------------------------
//双方向連結リストのコンパイラスイッチ
//#define ENABLE_BINARY_SEARCH//二分探索を有効にする
//#define ENABLE_STABLE_SORT//安定ソートを有効にする
//#define USE_SHELL_SORT//通常ソートにシェルソートを使用する（無効化時は挿入ソートを使用）

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

#if 0
//----------------------------------------
//比較ソート処理オーバーロード関数用マクロ
//※イテレータ対応版
//※標準プレディケート関数使用版
#define iteratorSortFuncSetByDefaultPredicate(func_name) \
	template<class ITERATOR> \
	inline std::size_t func_name(ITERATOR begin, ITERATOR end) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		return func_name(begin, end, less<value_type>()); \
	}
#define iteratorSortFuncSet(func_name) \
	iteratorSortFuncSetByDefaultPredicate(func_name)
#endif

//----------------------------------------
//探索処理オーバーロード関数用マクロ
//※イテレータ対応版
//※探索値指定版：プレディケート関数と値で比較
#define iteratorSearchFuncSetPredicateAndValue(func_name) \
	template<class ITERATOR, typename V, class PREDICATE> \
	inline ITERATOR func_name##Value(ITERATOR begin, ITERATOR end, const V& value, PREDICATE predicate) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		auto _equal = [&value, &predicate](value_type& val1) -> bool { return predicate(val1, value); }; \
		return std::move(func_name(begin, end, _equal)); \
	}
//※探索値指定版：標準のプレディケート関数と値で比較
#define iteratorSearchFuncSetByDefaultPredicateAndValue(func_name) \
	template<class ITERATOR, typename V> \
	inline ITERATOR func_name##Value(ITERATOR begin, ITERATOR end, const V& value) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		auto _equal = [&value](value_type& val1) -> bool { return equal_to<value_type>()(val1, value); }; \
		return std::move(func_name(begin, end, _equal)); \
	}
#define iteratorSearchFuncSetByPredicate(func_name) \
	iteratorSearchFuncSetPredicateAndValue(func_name) \
	iteratorSearchFuncSetByDefaultPredicateAndValue(func_name)
//※探索値指定版：比較関数と値で比較
#define iteratorSearchFuncSetByComparisonAndValue(func_name) \
	template<class ITERATOR, typename V, class COMPARISON> \
	inline ITERATOR func_name##Value(ITERATOR begin, ITERATOR end, const V& value, COMPARISON comparison) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		auto _comparison = [&value, &comparison](value_type& val1) -> int { return comparison(val1, value); }; \
		return func_name(begin, end, _comparison); \
	}
//※探索値指定版：標準比較関数と値で比較
#define iteratorSearchFuncSetByDefaultComparisonAndValue(func_name) \
	template<class ITERATOR, typename V> \
	inline ITERATOR func_name##Value(ITERATOR begin, ITERATOR end, const V& value) \
	{ \
		typedef typename ITERATOR::value_type value_type; \
		auto _comparison = [&value](value_type& val1) -> int { return compare_to<value_type>()(val1, value); }; \
		return func_name(begin, end, _comparison); \
	}
#define iteratorSearchFuncSetByComparison(func_name) \
	iteratorSearchFuncSetByComparisonAndValue(func_name) \
	iteratorSearchFuncSetByDefaultComparisonAndValue(func_name)

#if 0
//----------------------------------------
//整列状態確認 ※イテレータ対応版
template<class ITERATOR, class PREDICATE>
inline std::size_t iteratorCalcUnordered(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	std::size_t unordered = 0;
	ITERATOR prev = begin;
	ITERATOR now = begin;
	++now;
	for (; now != end; ++now, ++prev)
	{
		if (predicate(*now, *prev))
			++unordered;
	}
	return unordered;
}
iteratorSortFuncSet(iteratorCalcUnordered);
#endif

//----------------------------------------
//イテレータの差（要素数）を返す
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::input_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::output_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::forward_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::bidirectional_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
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
	for (; begin != end; ++begin)
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
	while (begin != end)
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
//探索アルゴリズム
//========================================

//----------------------------------------
//アルゴリズム：線形探索 ※イテレータ対応版
//----------------------------------------
//・最良計算時間：O(1)
//・平均計算時間：O(n/2)
//・最悪計算時間：O(n)
//・探索失敗時：  O(n)
//----------------------------------------
template<class  ITERATOR, class PREDICATE>
ITERATOR iteratorLinearSearch(ITERATOR begin, ITERATOR end, PREDICATE predicate)
{
	if (begin == end)
		return end;
	ITERATOR now = begin;
	for (; now != end; ++now)//順次探索
	{
		if (predicate(*now))//探索キーと一致したら終了
			return now;
	}
	return end;//探索失敗
}
iteratorSearchFuncSetByPredicate(iteratorLinearSearch);

//----------------------------------------
//アルゴリズム：二分探索 ※イテレータ対応版
//----------------------------------------
//・最良計算時間：O(1)
//・平均計算時間：O(log n)
//・最悪計算時間：O(log n)
//・探索失敗時：  O(log n)
//----------------------------------------
template<class  ITERATOR, class COMPARISON>
ITERATOR iteratorBinarySearch(ITERATOR begin, ITERATOR end, COMPARISON comparison)
{
	if (begin == end)
		return end;
	const int size = iteratorDifference(begin, end);
	int range = size;
	ITERATOR found = end;
	while (true)
	{
		const int range_half = range / 2;//探索範囲の半分の範囲
		ITERATOR mid = begin + range_half;//探索範囲の中心要素
		const int comp = comparison(*mid);//中心要素を探索キーと比較
		if (comp == 0)//中心要素が探索キーと一致
			found = mid;//発見した場所を記憶 ※見つかった位置の先頭を発見するため、探索を続行する
		if (range_half == 0)//探索範囲が残っていなければ探索終了
			break;
		if (comp <= 0)//探索キーが中心要素より小さいか同じだった場合、次に中心より前の範囲に絞って探索する
			range = range_half;
		else//if (comp > 0)//探索キーが中心要素より大きかった場合、次に中心より後の範囲に絞って探索する
		{
			begin = mid + 1;
			range -= (range_half + 1);
		}
	}
	if (found != end && found != begin)//見つかった地点が先頭でなければ、一つ前を調べる
	{
		ITERATOR found_prev = found;
		--found_prev;
		if (comparison(*found_prev) == 0)//一つ前が一致するならそれを返す
			found = found_prev;
	}
	return found;
}
iteratorSearchFuncSetByComparison(iteratorBinarySearch);

//--------------------------------------------------------------------------------
//双方向連結リスト（doubly-linked list）
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【本プログラムにおける実装要件】
//・テンプレートにより、アルゴリズムを汎用化。
//・リンクの方法に柔軟性を持たせ、かつ、virtualを必須としないように、
//　データ構造は自由とする。
//　（リンクの変数をポインタにしようがインデックスにしようが自由）
//・代わりに、データ操作専用のクラスをユーザー定義することで、
//　処理に汎用性を持たせる。
//・一切メモリ操作は行わず、ノードのオブジェクトを受け取って操作する
//　アルゴリズムのみを提供する。
//・std::listを模したコンテナとイテレータを利用可能とする。
//　ただし、メモリ管理を行わないため、複製を作るようなメソッドには対応しない。
//・コンテナは、先頭ノードと末尾ノードのみを保持し、一切メモリ操作しないものとする。
//--------------------------------------------------------------------------------

#include <cstddef>//srd::size_t用
#include <iterator>//std::iterator用
#include <algorithm>//C++11 std::move用

namespace linked_list
{
	//--------------------
	//双方向連結リストノード操作用基底テンプレートクラス
	//※下記のような派生クラス（CRTP）を定義して使用する
	//  //struct クラス名 : public linked_list::base_ope_t<クラス名, ノード型>
	//	struct ope_t : public linked_list::base_ope_t<ope_t, data_t>
	//	{
	//		//前ノードを取得
	//		inline static const node_type* getPrev(const node_type& node){ return ???; }
	//		//前ノードを変更
	//		inline static void setPrev(node_type& node, const node_type* prev){ ??? = prev; }
	//
	//		//次ノードを取得
	//		inline static const node_type* getNext(const node_type& node){ return ???; }
	//		//次ノードを変更
	//		inline static void setNext(node_type& node, const node_type* next){ ??? = next; }
	//		
	//		//ソート用プレディケート関数オブジェクト
	//		//※必要に応じて実装する
	//		struct sort_predicate{
	//			inline bool operator()(const node_type& lhs, const node_type& rhs) const { return lhs.??? < rhs.???; }
	//		};
	//
	//		//探索用プレディケート関数オブジェクト
	//		//※必要に応じて実装する
	//		struct find_predicate{
	//			inline bool operator()(const node_type& lhs, const ???& rhs) const { return lhs.??? == rhs; }
	//		};
	//		
	//		//ロック型 ※必要に応じて定義
	//		//※共有ロック（リード・ライトロック）でコンテナ操作をスレッドセーフにしたい場合は、
	//		//　有効な共有ロック型（shared_spin_lockなど）を lock_type 型として定義する。
	//		typedef shared_spin_lock lock_type;//ロックオブジェクト型
	//	};
	template<class OPE_TYPE, typename NODE_TYPE>
	struct base_ope_t
	{
		//型
		typedef OPE_TYPE ope_type;//ノード操作型
		typedef NODE_TYPE node_type;//ノード型

		//ロック型
		typedef dummy_shared_lock lock_type;//ロックオブジェクト型
		//※デフォルトはダミーのため、一切ロック制御しない。
		//※共有ロック（リード・ライトロック）でコンテナ操作をスレッドセーフにしたい場合は、
		//　base_ope_tの派生クラスにて、有効な共有ロック型（shared_spin_lock など）を
		//　lock_type 型として再定義する。

		//前ノードを取得 ※const外し(remove_const)
		inline static node_type* getPrev_rc(node_type& node){ return const_cast<node_type*>(ope_type::getPrev(const_cast<const node_type&>(node))); }
		//次ノードを取得 ※const外し(remove_const)
		inline static node_type* getNext_rc(node_type& node){ return const_cast<node_type*>(ope_type::getNext(const_cast<const node_type&>(node))); }

		//ソート用プレディケート関数オブジェクト
		//※trueでlhsの方が小さい（並び順が正しい）
		struct sort_predicate{
			inline bool operator()(const node_type& lhs, const node_type& rhs) const { return less<node_type>()(lhs, rhs); }
		};

		//線形探索用プレディケート関数オブジェクト
		//※trueで一致（探索成功）
		struct find_predicate{
			template<typename V>
			inline bool operator()(const node_type& lhs, const V& rhs) const { return equal_to<node_type>()(lhs, rhs); }
		};

	#ifdef ENABLE_BINARY_SEARCH
		//二分探索用比較関数オブジェクト
		//※0で一致（探索成功）、1以上でlhsの方が大きい、-1以下でrhsの方が大きい
		struct search_comparison{
			template<typename V>
			inline int operator()(const node_type& lhs, const V& rhs) const { return compare_to<node_type>()(lhs, rhs); }
		};
	#endif//ENABLE_BINARY_SEARCH
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef node_type& reference; \
		typedef const node_type& const_reference; \
		typedef node_type* pointer; \
		typedef const node_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type; \
		typedef typename ope_type::lock_type lock_type;
	//--------------------
	//双方向連結リスト操作関数：指定ノードの次ノードを取得
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getNextNode(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		node = ope_type::getNext(*node);
		return node;
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの後方のノードを取得
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getForwardNode(const typename OPE_TYPE::node_type& target, std::size_t& step)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		while (step > 0 && node)
		{
			node = ope_type::getNext(*node);
			--step;
		}
		return node;
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの前ノードを取得
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getPrevNode(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		node = ope_type::getPrev(*node);
		return node;
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの前方のノードを取得
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getBackwardNode(const typename OPE_TYPE::node_type& target, std::size_t& step)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		while (step > 0 && node)
		{
			node = ope_type::getPrev(*node);
			--step;
		}
		return node;
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの先頭ノードを取得
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getFirstNode(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		while (true)
		{
			const typename ope_type::node_type* prev = ope_type::getPrev(*node);
			if (!prev)
				return node;
			node = prev;
		}
		return nullptr;//ダミー
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの末尾ノードを取得
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getLastNode(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const typename ope_type::node_type* node = &target;
		while (true)
		{
			const typename ope_type::node_type* next = ope_type::getNext(*node);
			if (!next)
				return node;
			node = next;
		}
		return nullptr;//ダミー
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの数を数える
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type& target)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		std::size_t num = 1;
		const typename ope_type::node_type* node = &target;
		while (true)
		{
			const typename ope_type::node_type* next = ope_type::getNext(*node);
			if (!next)
				return num;
			++num;
			node = next;
		}
		return 0;//ダミー
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの次に連結
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* insertNodeAfter(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type& target, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		typename ope_type::node_type* next = const_cast<typename ope_type::node_type*>(ope_type::getNext(target));
		if (!next)
			last = &node;
		else
			ope_type::setPrev(*next, &node);
		ope_type::setPrev(node, &target);
		ope_type::setNext(target, &node);
		ope_type::setNext(node, next);
		return &node;
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの前に連結
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* insertNodeBefore(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type& target, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		typename ope_type::node_type* prev = const_cast<typename ope_type::node_type*>(ope_type::getPrev(target));
		if (!prev)
			first = &node;
		else
			ope_type::setNext(*prev, &node);
		ope_type::setNext(node, &target);
		ope_type::setPrev(target, &node);
		ope_type::setPrev(node, prev);
		return &node;
	}
	//--------------------
	//双方向連結リスト操作関数：先頭に連結
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* insertNodeBeginning(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!first)
		{
			first = &node;
			last = &node;
			ope_type::setPrev(node, nullptr);
			ope_type::setNext(node, nullptr);
			return &node;
		}
		ope_type::setNext(node, first);
		ope_type::setPrev(*first, &node);
		ope_type::setPrev(node, nullptr);
		first = &node;
		return &node;
	}
	//--------------------
	//双方向連結リスト操作関数：末尾に連結
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* insertNodeEnd(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!last)
		{
			first = &node;
			last = &node;
			ope_type::setPrev(node, nullptr);
			ope_type::setNext(node, nullptr);
			return &node;
		}
		ope_type::setPrev(node, last);
		ope_type::setNext(*last, &node);
		ope_type::setNext(node, nullptr);
		last = &node;
		return &node;
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードを連結から外す
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* removeNode(typename OPE_TYPE::node_type& node, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		typename ope_type::node_type* prev = const_cast<typename ope_type::node_type*>(ope_type::getPrev(node));
		typename ope_type::node_type* next = const_cast<typename ope_type::node_type*>(ope_type::getNext(node));
		if (prev)
			ope_type::setNext(*prev, next);
		else
			first = next;
		if (next)
			ope_type::setPrev(*next, prev);
		else
			last = prev;
		ope_type::setPrev(node, nullptr);
		ope_type::setNext(node, nullptr);
		return &node;
	}
	//--------------------
	//双方向連結リスト操作関数：指定ノードの範囲を連結から外す
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* removeNodes(typename OPE_TYPE::node_type& start, typename OPE_TYPE::node_type& end, typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		typename ope_type::node_type* prev = const_cast<typename ope_type::node_type*>(ope_type::getPrev(start));
		typename ope_type::node_type* next = &end;
		typename ope_type::node_type* _end = next ? const_cast<typename ope_type::node_type*>(ope_type::getPrev(end)) : last;
		if (prev)
			ope_type::setNext(*prev, next);
		else
			first = next;
		if (next)
			ope_type::setPrev(*next, prev);
		else
			last = prev;
		ope_type::setPrev(start, nullptr);
		ope_type::setNext(*_end, nullptr);
		return &start;
	}

	//========================================
	//ソートアルゴリズム
	//========================================

	//----------------------------------------
	//比較ソート処理オーバーロード関数用マクロ
	//※連結リスト対応版
	//※標準プレディケート関数使用版
	#define liskedListSortFuncSetByDefaultPredicate(func_name) \
		template<class OPE_TYPE> \
		inline std::size_t func_name(typename OPE_TYPE::node_type* first) \
		{ \
			typedef typename OPE_TYPE::node_type node_type; \
			return func_name<OPE_TYPE>(first, less<node_type>()); \
		}
	#define linkedListSortFuncSet(func_name) \
		liskedListSortFuncSetByDefaultPredicate(func_name)

	//----------------------------------------
	//整列状態確認 ※連結リスト対応版
	template<class OPE_TYPE, class PREDICATE>
	inline std::size_t linkedListCalcUnordered(const typename OPE_TYPE::node_type* start, PREDICATE predicate)
	{
		typedef typename OPE_TYPE::node_type node_type;
		std::size_t unordered = 0;
		const node_type* prev = start;
		const node_type* now = OPE_TYPE::getNext(*prev);
		while(now)
		{
			if (predicate(*now, *prev))
				++unordered;
			now = OPE_TYPE::getNext(*now);
		}
		return unordered;
	}
	linkedListSortFuncSet(linkedListCalcUnordered);

	//========================================
	//ソートアルゴリズム分類：挿入ソート
	//========================================

	//----------------------------------------
	//アルゴリズム：挿入ソート ※双方向連結リスト対応版
	//----------------------------------------
	//・最良計算時間：O(n)
	//・平均計算時間：O(n^2)
	//・最悪計算時間：O(n^2)
	//・メモリ使用量：O(1)
	//・安定性：　　　○
	//----------------------------------------
	template<class OPE_TYPE, class PREDICATE>
	std::size_t linkedListInsertionSort(typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last, PREDICATE predicate)
	{
		typedef typename OPE_TYPE::node_type node_type;
		if (!first || !OPE_TYPE::getNext(*first))
			return 0;
		std::size_t swapped_count = 0;
		node_type* now = first;
		node_type* next = const_cast<node_type*>(OPE_TYPE::getNext(*now));
		while (next)
		{
			if (predicate(*next, *now))
			{
				node_type* min = now;
				node_type* prev = const_cast<node_type*>(OPE_TYPE::getPrev(*now));
				while (prev)
				{
					if (predicate(*next, *prev))
						min = prev;
					else
						break;
					prev = const_cast<node_type*>(OPE_TYPE::getPrev(*prev));
				}
				removeNode<OPE_TYPE>(*next, first, last);
				insertNodeBefore<OPE_TYPE>(*next, *min, first, last);
				++swapped_count;
				next = const_cast<node_type*>(OPE_TYPE::getNext(*now));
			}
			else
			{
				now = next;
				next = const_cast<node_type*>(OPE_TYPE::getNext(*next));
			}
		}
		return swapped_count;
	}
	linkedListSortFuncSet(linkedListInsertionSort);

	//----------------------------------------
	//アルゴリズム：シェルソート ※双方向連結リスト対応版
	//----------------------------------------
	//・最良計算時間：O(n)
	//・平均計算時間：O(n log^2 n) or O(n^3/2)
	//・最悪計算時間：O(n log^2 n)
	//・メモリ使用量：O(1)
	//・安定性：　　　×
	//----------------------------------------
	template<class OPE_TYPE, class PREDICATE>
	std::size_t linkedListShellSort(typename OPE_TYPE::node_type*& first, typename OPE_TYPE::node_type*& last, PREDICATE predicate)
	{
		typedef typename OPE_TYPE::node_type node_type;
		if (!first || !OPE_TYPE::getNext(*first))
			return 0;
		std::size_t swapped_count = 0;
		std::size_t size = 0;
		{
			const node_type* node = first;
			while (node)
			{
				++size;
				node = OPE_TYPE::getNext(*node);
			}
		}
		const int h_max = size / 3;
		int h = 1;
		while (h <= h_max)
			h = 3 * h + 1;
		while (h > 0)
		{
			node_type* now = first;
			node_type* next = now;
			for (int i = 0; i < h && next; ++i)
				next = const_cast<node_type*>(OPE_TYPE::getNext(*next));
			while (next)
			{
				if (predicate(*next, *now))
				{
					node_type* min = now;
					node_type* prev = now;
					for (int i = 0; i < h && prev; ++i)
						prev = const_cast<node_type*>(OPE_TYPE::getPrev(*prev));
					while (prev)
					{
						if (predicate(*next, *prev))
							min = prev;
						else
							break;
						for (int i = 0; i < h && prev; ++i)
							prev = const_cast<node_type*>(OPE_TYPE::getPrev(*prev));
					}
					removeNode<OPE_TYPE>(*next, first, last);
					insertNodeBefore<OPE_TYPE>(*next, *min, first, last);
					++swapped_count;
					next = now;
					for (int i = 0; i < h && next; ++i)
						next = const_cast<node_type*>(OPE_TYPE::getNext(*next));
				}
				else
				{
					now = const_cast<node_type*>(OPE_TYPE::getNext(*now));
					next = const_cast<node_type*>(OPE_TYPE::getNext(*next));
				}
			}
			h = (h - 1) / 3;
		}
		return swapped_count;
	}
	linkedListSortFuncSet(linkedListShellSort);

	//----------------------------------------
	//双方向連結リストコンテナ
	//※先頭ノードと末尾ノードを持つのみ
	//※std::listを模した構造
	template<class OPE_TYPE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//--------------------
		//イテレータ宣言
		class iterator;
		class reverse_iterator;
		typedef const iterator const_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		//--------------------
		//イテレータ
		class iterator : public std::iterator<std::bidirectional_iterator_tag, node_type>
		{
			friend class container;
			friend class reverse_iterator;
		public:
			//キャストオペレータ
			inline operator bool() const { return isExist(); }
			inline operator const node_type() const { return *getNode(); }
			inline operator node_type&(){ return *getNode(); }
		public:
			//オペレータ
			inline const_reference operator*() const { return *getNode(); }
			inline reference operator*(){ return *getNode(); }
			inline const_pointer operator->() const { return getNode(); }
			inline pointer operator->(){ return getNode(); }
		#if 1//std::bidirectional_iterator_tag には本来必要ではない
			inline const_iterator operator[](const int index) const
			{
				iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
			inline iterator operator[](const int index)
			{
				iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
		#endif
			//比較オペレータ
			inline bool operator==(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       m_node == rhs.m_node;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? false :
				       m_isEnd || rhs.m_isEnd ? true :
					   m_node != rhs.m_node;
			}
			//演算オペレータ
			inline const_iterator& operator++() const
			{
				updateNext();
				return *this;
			}
			inline const_iterator& operator--() const
			{
				updatePrev();
				return *this;
			}
			inline iterator& operator++()
			{
				updateNext();
				return *this;
			}
			inline iterator& operator--()
			{
				updatePrev();
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
				return  std::move(ite);
			}
			inline iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return  std::move(ite);
			}
			inline iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return  std::move(ite);
			}
		#if 1//std::bidirectional_iterator_tag には本来必要ではない
			inline const_iterator& operator+=(const typename iterator::difference_type rhs) const
			{
				updateForward(rhs);
				return *this;
			}
			inline const_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline const_iterator& operator-=(const typename iterator::difference_type rhs) const
			{
				updateBackward(rhs);
				return *this;
			}
			inline const_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator+=(const typename iterator::difference_type rhs)
			{
				updateForward(rhs);
				return *this;
			}
			inline iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator-=(const typename iterator::difference_type rhs)
			{
				updateBackward(rhs);
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
				return  std::move(ite);
			}
			inline const_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline const_iterator operator-(const typename iterator::difference_type rhs) const
			{
				iterator ite(*this);
				ite -= rhs;
				return  std::move(ite);
			}
			inline const_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator+(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite += rhs;
				return  std::move(ite);
			}
			inline iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator-(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite -= rhs;
				return  std::move(ite);
			}
			inline iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			//inline typename iterator::difference_type operator-(const iterator rhs)
			//{
			//	return ???;
			//}
		#endif
		public:
			//ムーブオペレータ
			inline iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			iterator& operator=(const_reverse_iterator&& rhs);
			//コピーオペレータ
			inline iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			iterator& operator=(const_reverse_iterator& rhs);
		public:
			//アクセッサ
			inline bool isExist() const { return m_node != nullptr; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_node != nullptr || m_isEnd; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_isEnd; }//終端か？
			inline const node_type* getNode() const { return m_node; }//現在のノード
			inline node_type* getNode(){ return m_node; }//現在のノード
		private:
			//メソッド
			inline void updateNext() const
			{
				node_type* prev = m_node;
				if (m_node)
					m_node = const_cast<node_type*>(getNextNode<ope_type>(*m_node));
				m_isEnd = (prev && !m_node);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					m_node = const_cast<node_type*>(m_con->m_last);
					m_isEnd = false;
					return;
				}
				if (m_node)
					m_node = const_cast<node_type*>(getPrevNode<ope_type>(*m_node));
				m_isEnd = false;
			}
			void updateForward(const std::size_t step) const
			{
				std::size_t _step = step;
				node_type* prev = m_node;
				if (m_node)
					m_node = const_cast<node_type*>(getForwardNode<ope_type>(*m_node, _step));
				m_isEnd = (prev && !m_node && _step == 0);
			}
			void updateBackward(const std::size_t step) const
			{
				std::size_t _step = step;
				if (_step > 0 && m_isEnd)
				{
					m_node = const_cast<node_type*>(m_con->m_last);
					--_step;
				}
				if (m_node)
					m_node = const_cast<node_type*>(getBackwardNode<ope_type>(*m_node, _step));
				m_isEnd = false;
			}
		public:
			//ムーブコンストラクタ
			inline iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			iterator(const_reverse_iterator&& obj);
			//コピーコンストラクタ
			inline iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			iterator(const_reverse_iterator& obj);
			//コンストラクタ
			inline iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_node(nullptr),
				m_isEnd(is_end)
			{
				if (!is_end)
				{
					m_node = const_cast<node_type*>(con.m_first);
					if (!m_node)
						m_isEnd = true;
				}
			}
			inline iterator(const container& con, node_type* node, const bool is_end) :
				m_con(&con),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline iterator() :
				m_con(nullptr),
				m_node(nullptr),
				m_isEnd(false)
			{}
			//デストラクタ
			inline ~iterator()
			{}
		protected:
			//フィールド
			const container* m_con;//コンテナ
			mutable node_type* m_node;//現在のノード
			mutable bool m_isEnd;//終端か？
		};
		//--------------------
		//リバースイテレータ
		//class reverse_iterator : public std::reverse_iterator<iterator>
		class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, node_type>
		{
			friend class container;
			friend class iterator;
		public:
			//キャストオペレータ
			inline operator bool() const { return isExist(); }
			inline operator const node_type() const { return *getNode(); }
			inline operator node_type&(){ return *getNode(); }
		public:
			//オペレータ
			inline const_reference operator*() const { return *getNode(); }
			inline reference operator*(){ return *getNode(); }
			inline const_pointer operator->() const { return getNode(); }
			inline pointer operator->(){ return getNode(); }
		#if 1//std::bidirectional_iterator_tag には本来必要ではない
			inline const_reverse_iterator operator[](const int index) const
			{
				reverse_iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
		#endif
		public:
			//比較オペレータ
			inline bool operator==(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
					   m_node == rhs.m_node;
			}
			inline bool operator!=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? false :
				       rhs.m_isEnd || m_isEnd ? true :
					   m_node != rhs.m_node;
			}
			//演算オペレータ
			inline const_reverse_iterator& operator++() const
			{
				updateNext();
				return *this;
			}
			inline const_reverse_iterator& operator--() const
			{
				updatePrev();
				return *this;
			}
			inline reverse_iterator& operator++()
			{
				updateNext();
				return *this;
			}
			inline reverse_iterator& operator--()
			{
				updatePrev();
				return *this;
			}
			inline const_reverse_iterator operator++(int) const
			{
				reverse_iterator ite(*this);
				++(*this);
				return  std::move(ite);
			}
			inline const_reverse_iterator operator--(int) const
			{
				reverse_iterator ite(*this);
				--(*this);
				return  std::move(ite);
			}
			inline reverse_iterator operator++(int)
			{
				reverse_iterator ite(*this);
				++(*this);
				return  std::move(ite);
			}
			inline reverse_iterator operator--(int)
			{
				reverse_iterator ite(*this);
				--(*this);
				return  std::move(ite);
			}
		#if 1//std::bidirectional_iterator_tag には本来必要ではない
			inline const_reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs) const
			{
				updateForward(rhs);
				return *this;
			}
			inline const_reverse_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline const_reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs) const
			{
				updateBackward(rhs);
				return *this;
			}
			inline const_reverse_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs)
			{
				updateForward(rhs);
				return *this;
			}
			inline reverse_iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs)
			{
				updateBackward(rhs);
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
				return  std::move(ite);
			}
			inline const_reverse_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline const_reverse_iterator operator-(const typename reverse_iterator::difference_type rhs) const
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return  std::move(ite);
			}
			inline const_reverse_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator+(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite += rhs;
				return  std::move(ite);
			}
			inline reverse_iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator-(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return  std::move(ite);
			}
			inline reverse_iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			//inline typename reverse_iterator::difference_type operator-(const reverse_iterator rhs)
			//{
			//	return ???;
			//}
		#endif
		public:
			//ムーブオペレータ
			inline reverse_iterator& operator=(const_reverse_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = false;
				if (m_node)
				{
					++(*this);
				}
				else
				{
					if (rhs.m_isEnd)
						m_node = const_cast<node_type*>(m_con->m_last);
				}
				return *this;
			}
			//コピーオペレータ
			inline reverse_iterator& operator=(const_reverse_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_node = rhs.m_node;
				m_isEnd = false;
				if (m_node)
				{
					++(*this);
				}
				else
				{
					if (rhs.m_isEnd)
						m_node = const_cast<node_type*>(m_con->m_last);
				}
				return *this;
			}
		public:
			//アクセッサ
			inline bool isExist() const { return m_node != nullptr; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_node != nullptr || m_isEnd; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_isEnd; }//終端か？
			inline const node_type* getNode() const { return m_node; }//現在のノード
			inline node_type* getNode(){ return m_node; }//現在のノード
		public:
			//メソッド
			inline void updateNext() const
			{
				node_type* prev = m_node;
				if (m_node)
					m_node = const_cast<node_type*>(getPrevNode<ope_type>(*m_node));
				m_isEnd = (prev && !m_node);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					m_node = const_cast<node_type*>(m_con->m_first);
					m_isEnd = false;
					return;
				}
				if (m_node)
					m_node = const_cast<node_type*>(getNextNode<ope_type>(*m_node));
				m_isEnd = false;
			}
			void updateForward(const std::size_t step) const
			{
				std::size_t _step = step;
				node_type* prev = m_node;
				if (m_node)
					m_node = const_cast<node_type*>(getBackwardNode<ope_type>(*m_node, _step));
				m_isEnd = (prev && !m_node && _step == 0);
			}
			void updateBackward(const std::size_t step) const
			{
				std::size_t _step = step;
				if (_step > 0 && m_isEnd)
				{
					m_node = const_cast<node_type*>(m_con->m_first);
					--_step;
				}
				if (m_node)
					m_node = const_cast<node_type*>(getForwardNode<ope_type>(*m_node, _step));
				m_isEnd = false;
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
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(false)
			{
				if (m_node)
				{
					++(*this);
				}
				else
				{
					if (obj.m_isEnd)
						m_node = const_cast<node_type*>(m_con->m_last);
				}
			}
			//コピーコンストラクタ
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{
				if (m_node)
				{
					++(*this);
				}
				else
				{
					if (obj.m_isEnd)
						m_node = const_cast<node_type*>(m_con->m_last);
				}
			}
			//コンストラクタ
			inline reverse_iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_node(nullptr),
				m_isEnd(is_end)
			{
				if (!is_end)
				{
					m_node = const_cast<node_type*>(m_con->m_last);
					if (!m_node)
						m_isEnd = true;
				}
			}
			inline reverse_iterator(const container& con, node_type* node, const bool is_end) :
				m_con(con),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline reverse_iterator() :
				m_con(nullptr),
				m_node(nullptr),
				m_isEnd(false)
			{}
			//デストラクタ
			inline ~reverse_iterator()
			{}
		protected:
			//フィールド
			const container* m_con;//コンテナ
			mutable node_type* m_node;//現在のノード
			mutable bool m_isEnd;//終端か？
		};
	public:
		//アクセッサ
		//※std::listと異なり、ノードのポインタを返す
		const node_type* at(const index_type index) const
		{
			return getForwardNode<ope_type>(m_first, index);
		}
		inline node_type* at(const index_type index){ return const_cast<node_type*>(const_cast<const container*>(this)->at(index)); }
		inline const node_type* operator[](const index_type index) const { return at(index); }
		inline node_type* operator[](const index_type index){ return at(index); }
	public:
		//キャストオペレータ
		inline operator lock_type&(){ return m_lock; }//ロックオブジェクト
		inline operator lock_type&() const { return m_lock; }//ロックオブジェクト ※mutable
	public:
		//メソッド
		//inline std::size_t max_size() const { return (不定); }
		//inline std::size_t capacity() const { return (不定); }
		inline std::size_t size() const { return m_first ? countNodes<ope_type>(*m_first) : 0; }//ノード数を取得
		inline bool empty() const { return m_first == nullptr; }//空か？
		inline node_type* front(){ return m_first; }//先頭ノードを参照
		inline const node_type* front() const { return m_first; }//先頭ノードを参照
		inline node_type*& first_ref(){ return m_first; }//先頭ノードの参照を取得
		inline node_type* back(){ return m_last; }//末尾ノードを参照
		inline const node_type* back() const { return m_last; }//末尾ノードを参照
		inline node_type*& last_ref(){ return m_last; }//末尾ノードの参照を取得
		//イテレータを取得
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
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
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
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
		
		//追加／削除系メソッド
		//※std::listと異なり、追加／削除対象のノードを直接指定し、結果をポインタで受け取る（成功したら、追加／削除したポインタを返す）
		//※要素のメモリ確保／解放を行わない点に注意
		//※assign(), remove_if(), emplace(), emplace_front(), emplase_back()には非対応
		//※insert_before()を追加
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		
		//先頭にノードを挿入（連結に追加）
		inline node_type* push_front(const node_type& node)
		{
			return insertNodeBeginning<ope_type>(*const_cast<node_type*>(&node), m_first, m_last);
		}
		//末尾にノードを挿入（連結に追加）
		inline node_type* push_back(const node_type& node)
		{
			return insertNodeEnd<ope_type>(*const_cast<node_type*>(&node), m_first, m_last);
		}
		//先頭ノードを削除（連結解除）
		inline node_type* pop_front()
		{
			if (!m_first)
				return nullptr;
			return removeNode<ope_type>(*m_first, m_first, m_last);
		}
		//末尾ノードを削除（連結解除）
		inline node_type* pop_back()
		{
			if (!m_first)
				return nullptr;
			return removeNode<ope_type>(*m_last, m_first, m_last);
		}
		//指定の位置の後ろにノードを挿入（連結に追加）
		//※位置はイテレータで指定
		inline node_type* insert(iterator pos, const node_type& node)
		{
			if (pos.isNotExist())
				return nullptr;
			return insertNodeAfter<ope_type>(*const_cast<node_type*>(&node), *pos, m_first, m_last);
		}
		//指定の位置の前にノードを挿入（連結に追加）
		//※位置はイテレータで指定
		inline node_type* insert_before(iterator pos, const node_type& node)
		{
			if (pos.isNotExist())
				return nullptr;
			return insertNodeBefore<ope_type>(*const_cast<node_type*>(&node), *pos, m_first, m_last);
		}
		//指定ノードを削除（連結解除）
		inline node_type* remove(node_type& node)
		{
			if (!m_first)
				return nullptr;
			return removeNode<ope_type>(node, m_first, m_last);
		}
		//指定位置のノードを削除（連結解除）
		//※位置はイテレータで指定
		inline node_type* erase(iterator pos)
		{
			if (!m_first || pos.isNotExist())
				return nullptr;
			return removeNode<ope_type>(*pos, m_first, m_last);
		}
		//指定範囲のノードを削除（連結解除）
		//※範囲はイテレータで指定
		inline node_type* erase(iterator start, iterator end)
		{
			if (!m_first || start.isNotExist() || end.isNotEnabled())
				return nullptr;
			return removeNodes<ope_type>(*start, *end, m_first, m_last);
		}
		//全ノードをクリア
		//※先頭ノードを返す
		inline node_type* clear()
		{ 
			node_type* first = m_first;
			m_first = nullptr;
			m_last = nullptr;
			return first;
		}
	public:
		//ソート
		//※挿入ソートを使用（シェルソートではあまり速度が上がらないため）
		//※ope_type::sort_predicate() を使用して探索（標準では、データ型の operator<() に従って探索）
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		void sort()
		{
		#ifdef USE_SHELL_SORT
			linkedListShellSort<OPE_TYPE>(m_first, m_last, typename ope_type::sort_predicate());
		#else//USE_SHELL_SORT
			linkedListInsertionSort<OPE_TYPE>(m_first, m_last, typename ope_type::sort_predicate());
		#endif//USE_SHELL_SORT
		}
		//※プレディケート関数指定版
		template<class PREDICATE>
		void sort(PREDICATE predicate)
		{
		#ifdef USE_SHELL_SORT
			linkedListShellSort<OPE_TYPE>(m_first, m_last, predicate);
		#else//USE_SHELL_SORT
			linkedListInsertionSort<OPE_TYPE>(m_first, m_last, predicate);
		#endif//USE_SHELL_SORT
		}
	#ifdef ENABLE_STABLE_SORT
		//安定ソート
		//※挿入ソートを使用
		//※ope_type::sort_predicate() を使用して探索（標準では、データ型の operator<() に従って探索）
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で排他ロック（ライトロック）の取得と解放を行う必要がある
		void stable_sort()
		{
			linkedListInsertionSort<OPE_TYPE>(m_first, m_last, typename ope_type::sort_predicate());
		}
		//※プレディケート関数指定版
		template<class PREDICATE>
		void stable_sort(PREDICATE predicate)
		{
			linkedListInsertionSort<OPE_TYPE>(m_first, m_last, predicate);
		}
	#endif//ENABLE_STABLE_SORT
		//ソート済み状態チェック
		//※ope_type::sort_predicate() を使用して探索（標準では、データ型の operator<() に従って探索）
		//※自動的なロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で共有ロック（リードロック）の取得と解放を行う必要がある
		bool is_ordered() const
		{
			return linkedListCalcUnordered<OPE_TYPE>(m_first, typename ope_type::sort_predicate()) == 0;
		}
		//※プレディケート関数指定版
		template<class PREDICATE>
		bool is_ordered(PREDICATE predicate) const
		{
			return linkedListCalcUnordered<OPE_TYPE>(m_first, predicate) == 0;
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
			iterator found = iteratorLinearSearchValue(begin(), end(), value, typename ope_type::find_predicate());
			return std::move(found);
		}
		//※比較関数＋値指定版
		template<typename V, class PREDICATE>
		iterator find_value(const V& value, PREDICATE predicate)
		{
			iterator found = iteratorLinearSearchValue(begin(), end(), value, predicate);
			return std::move(found);
		}
		//※比較関数指定版
		//※値の指定は関数に含んでおく（クロ―ジャを用いるなどする）
		template<class PREDICATE>
		iterator find(PREDICATE predicate)
		{
			iterator found = iteratorLinearSearch(begin(), end(), predicate);
			return std::move(found);
		}
	#ifdef ENABLE_BINARY_SEARCH
		//二分探索
		//※探索値指定版
		//※ope_type::search_comparison() を使用して探索（標準では、データ型の operator==() と operator<() に従って探索）
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロックの前後で共有ロック（リードロック）の取得と解放を行う必要がある
		template<typename V>
		iterator binary_search_value(const V& value)
		{
			iterator found = iteratorBinarySearchValue(begin(), end(), value, typename ope_type::search_comparison());
			return std::move(found);
		}
		//※比較関数＋値指定版
		template<typename V, class COMPARISON>
		iterator binary_search_value(const V& value, COMPARISON comparison)
		{
			iterator found = iteratorBinarySearchValue(begin(), end(), value, comparison);
			return std::move(found);
		}
		//※比較関数指定版
		//※値の指定は関数に含んでおく（クロ―ジャを用いるなどする）
		template<class COMPARISON>
		iterator binary_search(COMPARISON comparison)
		{
			iterator found = iteratorBinarySearch(begin(), end(), comparison);
			return std::move(found);
		}
	#endif//ENABLE_BINARY_SEARCH

		//リスト操作系メソッド
		//※merge(), splice(), reverse(), unique()には非対応

	public:
		//ムーブコンストラクタ
		container(const container&& con) :
			m_first(con.m_first),
			m_last(con.m_last)
		{}
		//コピーコンストラクタ
		container(const container& con) :
			m_first(con.m_first),
			m_last(con.m_last)
		{}
		//コンストラクタ
		container() :
			m_first(nullptr),
			m_last(nullptr)
		{}
		//デストラクタ
		~container()
		{}
	private:
		//フィールド
		node_type* m_first;//先頭ノード
		node_type* m_last;//末尾ノード
		mutable lock_type m_lock;//ロックオブジェクト
	};
	//イテレータのムーブオペレータ
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator&& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator&& rhs)//VC++もOK
	{
		m_con = rhs.m_con;
		m_node = rhs.m_node;
		m_isEnd = false;
		if (m_node)
		{
			++(*this);
		}
		else
		{
			if (rhs.m_isEnd)
				m_node = const_cast<node_type*>(m_con->m_first);
		}
		return *this;
	}
	//イテレータのコピーオペレータ
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator& rhs)//VC++もOK
	{
		m_con = rhs.m_con;
		m_node = rhs.m_node;
		m_isEnd = false;
		if (m_node)
		{
			++(*this);
		}
		else
		{
			if (rhs.m_isEnd)
				m_node = const_cast<node_type*>(m_con->m_first);
		}
		return *this;
	}
	//イテレータのムーブコンストラクタ
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator&& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator&& obj) ://VC++もOK
		m_con(obj.m_con),
		m_node(obj.m_node),
		m_isEnd(false)
	{
		if (m_node)
		{
			++(*this);
		}
		else
		{
			if (obj.m_isEnd)
				m_node = const_cast<node_type*>(m_con->m_first);
		}
	}
	//イテレータのコピーコンストラクタ
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator& obj) ://VC++もOK
		m_con(obj.m_con),
		m_node(obj.m_node),
		m_isEnd(false)
	{
		if (m_node)
		{
			++(*this);
		}
		else
		{
			if (obj.m_isEnd)
				m_node = const_cast<node_type*>(m_con->m_first);
		}
	}
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace linked_list

//--------------------------------------------------------------------------------
//双方向連結リストテスト
//--------------------------------------------------------------------------------

#include <algorithm>//std::for_each用
#include <chrono>//C++11 時間計測用
#include <list>//std::list用（比較用）
#include <assert.h>//assert用

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
#ifdef PRINT_TEST_DATA_SEARCH
template<typename... Tx>
inline int printf_dbg_search(const char* fmt, Tx... args)
{
	return printf(fmt, args...);
}
#else//PRINT_TEST_DATA_SEARCH
inline int printf_dbg_search(const char* fmt, ...){ return 0; }
#endif//PRINT_TEST_DATA_SEARCH

//----------------------------------------
//テストデータ
struct data_t
{
	mutable const data_t* m_prev;//前ノード
	mutable const data_t* m_next;//次ノード
	
	int m_key;//キー
	int m_val;//値
	
	//コンストラクタ
	data_t(const int key, const int val) :
		m_next(nullptr),
		m_prev(nullptr),
		m_key(key),
		m_val(val)
	{}
	data_t() :
		m_next(nullptr),
		m_prev(nullptr),
		m_key(0),
		m_val(0)
	{}

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
#ifdef ENABLE_BINARY_SEARCH
	inline bool operator<(const int key) const
	{
		return m_key < key;
	}
#endif//ENABLE_BINARY_SEARCH
};
#ifdef ENABLE_BINARY_SEARCH
//※std::binary_searchを使用する場合は、このオペレータも必要
static bool operator<(const int key, const data_t& rhs)
{
	return key < rhs.m_key;
}
#endif//ENABLE_BINARY_SEARCH

//----------------------------------------
//テストデータ向けノード操作用クラス（CRTP）
struct ope_t : public linked_list::base_ope_t<ope_t, data_t>
{
	//前ノードを取得
	inline static const node_type* getPrev(const node_type& node){ return node.m_prev; }
	//前ノードを変更
	inline static void setPrev(node_type& node, const node_type* prev){ node.m_prev = prev; }
	
	//次ノードを取得
	inline static const node_type* getNext(const node_type& node){ return node.m_next; }
	//次ノードを変更
	inline static void setNext(node_type& node, const node_type* next){ node.m_next = next; }

	//ロック型
	//※デフォルト（dummy_shared_lock）のままとする
	//typedef shared_spin_lock lock_type;//ロックオブジェクト型
};

//----------------------------------------
//テストデータ操作クラス②：ソート／探索方法をデフォルトから変える
struct another_ope_t : public ope_t
{
	//ソート用プレディケート関数オブジェクト
	//※m_valメンバーを基準にソート
	struct sort_predicate{
		inline bool operator()(const node_type& lhs, const node_type& rhs) const
		{
			return lhs.m_val < rhs.m_val;
		}
	};

	//線形探索用プレディケート関数オブジェクト
	//※m_valメンバーを探索
	struct find_predicate{
		inline bool operator()(const node_type& lhs, const int rhs) const
		{
			return lhs.m_val == rhs;
		}
	};

#ifdef ENABLE_BINARY_SEARCH
	//二分探索用比較関数オブジェクト
	//※m_valメンバーを比較
	struct search_comparison{
		inline int operator()(const node_type& lhs, const int rhs) const
		{
			return rhs - lhs.m_val;
		}
	};
#endif//ENABLE_BINARY_SEARCH
};

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//--------------------
	//テスト①：基本ロジックテスト
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for linked_list::container(User defined type)]\n");

		//双方向連結リストコンテナ生成
		typedef linked_list::container<ope_t> container_t;
		container_t con;

		//データを表示
		auto printAll = [&con]()
		{
			printf("size=%d\n", con.size());
			printf("list=");
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
			printf("size=%d\n", con.size());
			printf("list(reverse)=");
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

		//末尾に連続プッシュ(1)
		auto continuous_push_back = [&con](const int num)
		{
			printf("\n");
			printf("[push_back * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				const int key = i;
				const int val = 100 + i;
				printf("push_back(%d:%d) ... ", key, val);
				data_t* data = new data_t(key, val);
				if (con.push_back(*data))
					printf("OK\n");
				else
				{
					delete data;
					printf("NG!\n");
				}
			}
		};
		continuous_push_back(10);
		printAll();//全件表示
		//printReverse();//全件逆順表示

		//先頭から連続ポップ(1)
		auto continuous_pop_front = [&con](const int num)
		{
			printf("\n");
			printf("[pop_front * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				printf("pop_front() ... ");
				data_t* data = con.pop_front();
				if (data)
				{
					printf("OK [%d:%d]\n", data->m_key, data->m_val);
					delete data;
				}
				else
					printf("NG!\n");
			}
		};
		continuous_pop_front(5);
		printAll();//全件表示
		//printReverse();//全件逆順表示

		//末尾に連続プッシュ(2)
		continuous_push_back(20);
		printAll();//全件表示
		//printReverse();//全件逆順表示

		//先頭から連続ポップ(2)
		continuous_pop_front(25);
		printAll();//全件表示
		//printReverse();//全件逆順表示

		//先頭に連続プッシュ(1)
		auto continuous_push_front = [&con](const int num)
		{
			printf("\n");
			printf("[push_front * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				const int key = 1000 + i;
				const int val = 100 + i;
				printf("push_front(%d:%d) ... ", key, val);
				data_t* data = new data_t(key, val);
				if (con.push_front(*data))
					printf("OK\n");
				else
				{
					delete data;
					printf("NG!\n");
				}
			}
		};
		continuous_push_front(10);
		printAll();//全件表示
		//printReverse();//全件逆順表示

		//末尾から連続ポップ(1)
		auto continuous_pop_back = [&con](const int num)
		{
			printf("\n");
			printf("[pop_back * %d]\n", num);
			for (int i = 0; i < num; ++i)
			{
				printf("pop_back() ... ");
				data_t* data = con.pop_back();
				if (data)
				{
					printf("OK [%d:%d]\n", data->m_key, data->m_val);
					delete data;
				}
				else
					printf("NG!\n");
			}
		};
		continuous_pop_back(5);
		printAll();//全件表示
		//printReverse();//全件逆順表示

		//先頭に連続プッシュ(2)
		continuous_push_front(20);
		printAll();//全件表示
		//printReverse();//全件逆順表示

		//末尾から連続ポップ(2)
		continuous_pop_back(25);
		printAll();//全件表示
		//printReverse();//全件逆順表示

		//データ登録：push_back()メソッド
		printf("\n");
		printf("[push_back(1)]\n");
		auto push_back = [&con](const int key, const int val)
		{
			data_t* data = new data_t(key, val);
			con.push_back(*data);
		};
		push_back(5, 101);
		push_back(8, 102);
		push_back(3, 103);
		push_back(1, 104);
		push_back(7, 105);
		push_back(4, 106);
		push_back(13, 107);
		push_back(10, 108);
		push_back(5, 109);
		
		//データを表示
		printAll();

		//データを逆順に表示
		printReverse();

		//ソ―ト
		printf("\n");
		printf("[sort]\n");
		con.sort();//通常ソート
		//con.stable_sort();//安定ソート
		printAll();//全件表示

		//逆順にソート ※カスタムプレディケート関数を使用
		printf("\n");
		printf("[custom sort]\n");
		auto reverse_pred = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key > rhs.m_key; };
		con.sort(reverse_pred);//通常ソート
		//con.stable_sort(reverse_pred);//安定ソート
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
			if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
			printf("copy operator\n");
			ite = con.begin();
			rite = con.rbegin();
			ite_end = con.end();
			rite_end = con.rend();
			ite2 = con.rbegin();
			rite2 = con.begin();
			ite2_end = con.rend();
			rite2_end = con.end();
			if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
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
				if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
				if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
				if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
				if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
				if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
				if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
				if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
				if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
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
			if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
			printf("-= 3\n");
			ite -= 3;
			rite -= 3;
			ite_end -= 3;
			rite_end -= 3;
			ite2 -= 3;
			rite2 -= 3;
			ite2_end -= 3;
			rite2_end -= 3;
			if (ite.isExist()) printf("ite: key=%d, value=%d\n", ite->m_key, ite->m_val);
			if (rite.isExist()) printf("rite: key=%d, value=%d\n", rite->m_key, rite->m_val);
			if (ite_end.isExist()) printf("ite_end: key=%d, value=%d\n", ite_end->m_key, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end: key=%d, value=%d\n", rite_end->m_key, rite_end->m_val);
			if (ite2.isExist()) printf("ite2: key=%d, value=%d\n", ite2->m_key, ite2->m_val);
			if (rite2.isExist()) printf("rite2: key=%d, value=%d\n", rite2->m_key, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end: key=%d, value=%d\n", ite2_end->m_key, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end: key=%d, value=%d\n", rite2_end->m_key, rite2_end->m_val);
		}
	#endif

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

	#ifdef ENABLE_BINARY_SEARCH
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
	#endif//ENABLE_BINARY_SEARCH

	#if 0
		con.sort(reverse_pred);//通常ソート
		printAll();//全件表示
		con.sort();//通常ソート
		printAll();//全件表示
		con.stable_sort(reverse_pred);//安定ソート
		printAll();//全件表示
		con.stable_sort();//安定ソート
		printAll();//全件表示
		find(1);
		find(2);
		find(3);
		binary_search(1);
		binary_search(2);
		binary_search(3);
	#endif

		//削除１：削除ノードで指定
		printf("\n");
		printf("[remove]\n");
		{
			auto ite = con.begin();
			ite += 2;
			data_t* del = con.remove(*ite);//前から3つ目のノードを削除
			if (del)
				delete del;
			printAll();//全件表示
		}

		//削除２：イテレータで指定
		printf("\n");
		printf("[erase(1)]\n");
		{
			auto ite = con.end();
			ite -= 4;
			data_t* del = con.erase(ite);//後ろから4つ目の位置のノードを削除
			if (del)
				delete del;
			printAll();//全件表示
		}

		//削除３：イテレータの範囲で指定
		printf("\n");
		printf("[erase(2)]\n");
		{
			auto start = con.end();
			start -= 4;
			auto end = start;
			end += 2;
			const data_t* del = con.erase(start, end);//後ろから4つ目の位置から2つのノードを削除
			while (del)
			{
				const data_t* next = del->m_next;
				delete del;
				del = next;
			}
			printAll();//全件表示
		}

		//削除４：イテレータの範囲で指定（末尾まで削除）
		printf("\n");
		printf("[erase(3)]\n");
		{
			auto start = con.end();
			start -= 2;
			auto end = con.end();
			const data_t* del = con.erase(start, end);//後ろから2つ目の位置から末尾までのノードを削除
			while (del)
			{
				const data_t* next = del->m_next;
				delete del;
				del = next;
			}
			printAll();//全件表示
		}

		//挿入１：insert()メソッド
		printf("\n");
		printf("[insert]\n");
		{
			auto ite = con.begin();
			++ite;
			data_t* data = new data_t(99, 999);
			con.insert(ite, *data);//先頭から2つ目の位置に挿入
			printAll();//全件表示
		}

		//挿入２：insert_before()メソッド
		printf("\n");
		printf("[insert_before]\n");
		{
			auto ite = con.begin();
			ite += 3;
			data_t* data = new data_t(88, 888);
			con.insert_before(ite, *data);//先頭から4つ目の位置の前に挿入
			printAll();//全件表示
		}

		//クリア
		printf("\n");
		printf("[clear]\n");
		{
			const data_t* del = con.clear();
			while (del)
			{
				const data_t* next = del->m_next;
				delete del;
				del = next;
			}
			printAll();//全件表示
			//printReverse();//全件逆順表示
		}
	}

	//--------------------
	//テスト②：ソート、探索の設定を変える
	{
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for linked_list::container(User defined type with custom operator type)]\n");

		//双方向連結リストコンテナ生成
		typedef linked_list::container<another_ope_t> container_t;
		container_t con;

		//データ登録１：push_back()メソッド
		printf("\n");
		printf("[push_back]\n");
		auto push_back = [&con](const int key, const int val)
		{
			data_t* data = new data_t(key, val);
			con.push_back(*data);
		};
		push_back(1, 105);
		push_back(1, 108);
		push_back(2, 103);
		push_back(2, 101);
		push_back(3, 107);
		push_back(3, 104);
		push_back(4, 113);
		push_back(4, 111);
		push_back(5, 105);
		push_back(5, 106);

		//データを表示
		auto printAll = [&con]()
		{
			printf("size=%d\n", con.size());
			printf("list=");
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
		con.sort();//通常ソート
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

	#ifdef ENABLE_BINARY_SEARCH
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
	#endif//ENABLE_BINARY_SEARCH

		//カスタムソート
		{
			printf("\n");
			printf("[sort with custom predicate]\n");
			auto predicate = [](const data_t& lhs, const data_t& rhs) -> bool {return lhs.m_key < rhs.m_key ? true : lhs.m_key == rhs.m_key ? lhs.m_val > rhs.m_val : false; };
			con.sort(predicate);//通常ソート
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

	#ifdef ENABLE_BINARY_SEARCH
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
	#endif//ENABLE_BINARY_SEARCH

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

	#ifdef ENABLE_BINARY_SEARCH
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
	#endif//ENABLE_BINARY_SEARCH
	}

	//--------------------
	//テスト③：大量登録テスト
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
			printf("[Test for performance linked_list]\n");

			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//データを初期化
			printf("\n");
			printf("[create container]\n");
			typedef linked_list::container<ope_t> container_t;
			container_t* con = new container_t;//コンテナ生成
			prev_time = printElapsedTime(prev_time, true);

			//データを登録
			printf("\n");
			printf("[push_back() * %d]\n", TEST_DATA_NUM);
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; ++i)
				{
					data_t* data = new data_t(i, 10000000 + i);
					con->push_back(*data);
					++num;
				}
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

			//イテレータ(1)
			printf("\n");
			printf("[iterator(1)]\n");
			{
				printf_detail("size=%d\n", con->size());
				printf_detail("list=");
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

		#ifdef ENABLE_SORT_TEST
			//逆順ソート
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			con->sort(reverse_sort);
			assert(con->is_ordered(reverse_sort));
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_SORT_TEST

			//イテレータ(2)
			printf("\n");
			printf("[iterator(2)]\n");
			{
				printf_detail("size=%d\n", con->size());
				printf_detail("list=");
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

		#ifdef ENABLE_SORT_TEST
			//正順ソート
			printf("\n");
			printf("[sort]\n");
			con->sort();
			assert(con->is_ordered());
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_SORT_TEST

			//リバースイテレータ
			printf("\n");
			printf("[reverse_iterator]\n");
			{
				printf_detail("size=%d\n", con->size());
				printf_detail("list=");
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

		#ifdef ENABLE_SORT_TEST
		#ifdef ENABLE_STABLE_SORT
			//逆順安定ソート
			printf("\n");
			printf("[reverse stable sort]\n");
			con->stable_sort(reverse_sort);
			assert(con->is_ordered(reverse_sort));
			prev_time = printElapsedTime(prev_time, true);

			//正順安定ソート
			printf("\n");
			printf("[stable sort]\n");
			con->stable_sort();
			assert(con->is_ordered());
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_STABLE_SORT
		#endif//ENABLE_SORT_TEST

			//線形探索
			printf("\n");
			printf("[find_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += TEST_DATA_FIND_STEP)
				{
					container_t::iterator ite = std::move(con->find_value(i));
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_BINARY_SEARCH
			//二分探索
			printf("\n");
			printf("[binary_search_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += TEST_DATA_FIND_STEP)
				{
					container_t::iterator ite = std::move(con->binary_search_value(i));
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_BINARY_SEARCH

			//データを破棄
			printf("\n");
			printf("[delete container]\n");
			{
				const data_t* data = con->clear();
				while (data)
				{
					const data_t* next = data->m_next;
					delete data;
					data = next;
				}
			}
			delete con;//コンテナを破棄
			con = nullptr;
			prev_time = printElapsedTime(prev_time, true);

			//総時間
			printf("\n");
			printf("[finish]\n");
			printElapsedTime(begin_time, true);
		}

		{
			printf("--------------------------------------------------------------------------------\n");
			printf("[Test for performance std::list]\n");

			const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point prev_time = begin_time;

			//データを初期化
			printf("\n");
			printf("[create container]\n");
			typedef std::list<data_t> container_t;
			container_t* con = new container_t();//std::listコンテナを生成
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

		#ifdef ENABLE_SORT_TEST
			//逆順ソート
			printf("\n");
			printf("[reverse sort]\n");
			auto reverse_sort = [](const data_t& lhs, const data_t& rhs){return lhs.m_key > rhs.m_key; };
			con->sort(reverse_sort);
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_SORT_TEST

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

		#ifdef ENABLE_SORT_TEST
			//正順ソート
			printf("\n");
			printf("[sort]\n");
			con->sort();
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_SORT_TEST

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

		#ifdef ENABLE_SORT_TEST
		#ifdef ENABLE_STABLE_SORT
			//逆順ソート　※安定ソートの代わり
			printf("\n");
			printf("[reverse (stable) sort]\n");
			con->sort(reverse_sort);
			prev_time = printElapsedTime(prev_time, true);

			//正順ソート　※安定ソートの代わり
			printf("\n");
			printf("[(stable) sort]\n");
			con->sort();
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_STABLE_SORT
		#endif//ENABLE_SORT_TEST

			//線形探索
			printf("\n");
			printf("[find_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += TEST_DATA_FIND_STEP)
				{
					container_t::iterator ite = std::find(con->begin(), con->end(), i);
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);

		#ifdef ENABLE_BINARY_SEARCH
			//二分探索
			printf("\n");
			printf("[binary_search_value]\n");
			{
				int num = 0;
				for (int i = 0; i < TEST_DATA_NUM; i += TEST_DATA_FIND_STEP)
				{
					container_t::iterator ite = std::lower_bound(con->begin(), con->end(), i);
					printf_detail(" [%d:%d]", ite->m_key, ite->m_val);
					++num;
				}
				printf_detail("\n");
				printf("num=%d\n", num);
			}
			prev_time = printElapsedTime(prev_time, true);
		#endif//ENABLE_BINARY_SEARCH

			//データを破棄
			printf("\n");
			printf("[delete container]\n");
			delete con;//std::listコンテナを破棄
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

// End of file
