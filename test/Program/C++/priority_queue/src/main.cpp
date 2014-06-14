//--------------------------------------------------------------------------------
//二分ヒープテスト用設定とコンパイラスイッチ
static const int TEST_DATA_PRIOR_MIN = 1;//テストデータの最小プライオリティ
static const int TEST_DATA_PRIOR_MAX = 5;//テストデータの最大プライオリティ
static const int TEST_DATA_MAX = 128;//テストデータの最大登録可能数
static const int TEST_DATA_REG_NUM = 20;//テストデータの登録数
//static const int TEST_DATA_MAX = 1000000;//テストデータの最大登録可能数
//static const int TEST_DATA_REG_NUM = 1000000;//テストデータの登録数

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
//共通処理
//--------------------------------------------------------------------------------

#include <type_traits>//C++11 std::is_class, std::conditional用
#include <utility>//C++11 std::move用

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
	#if 1//ムーブオペレータを使用して入れ替え（#include <utility> の std::swap() と同じ）
		T tmp = std::move(std::move(val2));
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
template<class T>
inline void swapValues(T& val1, T& val2)
{
	std::conditional<std::is_arithmetic<T>::value,
		_swapArithmetic<T>,
		_swapObjects<T>
	>::type::exec(val1, val2);
}

//--------------------------------------------------------------------------------
//二分ヒープ
//--------------------------------------------------------------------------------
//データ構造とアルゴリズム
//【特徴】
//・二分木である。
//	  - ノードの子（左右両方）には、自身よりキーが小さいノードを連結。
//	  - 兄弟ノード間のキーの大小は不定。
//・平衡木である。
//	  - 木のバランスは常に保たれる。
//・以上の特徴により、最もキーが大きいノードの探索時間が、常にO(1)に保たれる。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【本プログラムにおける実装要件】
//・固定配列で実装し、一切メモリ確保・削除をしない。
//・ノード連結のポインタを使用しない。
//　一般的な二分ヒープと同じく、配列の順序に基づいて連結する。
//・この二分ヒープをプライオリティキューに利用した場合、
//　デキュー（pop）時に、エンキュー（push）の順序性は保証されない。
//　※この挙動はSTLと同じ。
//・ただし、（二分ヒープを内包する）プライオリティキューでは、キーの比較に
//　プライオリティとシーケンス番号を併用することで、順序性を保証する。
//・STL（std::priority_queue）との違いは下記の通り
//    - 固定長配列である。（STLは内部にstd::vectorを使用しており、自動拡張する）
//    - 赤黒木コンテナ（rb_tree）の実装と合わせた構造にしており、
//　　  操作用テンプレート構造体を用いる。
//　　  ※STLで使用する比較用の関数オブジェクトクラス(less)は用いない。
//　　- C++11の「範囲に基づくforループ」と、STLの「std::for_each()」が使用可能。
//　　  単純に配列の内容を列挙する。
//    - 効率化のために、オブジェクトのコピーを伴う操作を、
//      明示的なメソッド（pushCoping/ popCoping）にしている。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【具体的な活用の想定】
//・任意の構造のプライオリティキューに適用。
//--------------------------------------------------------------------------------

#include <cstddef>//std::size_t, std::ptrdiff_t用
//#include <cstdint>//std::intptr_t用
#include <iterator>//std::iterator用
#include <new>//配置new,配置delete用

namespace binary_heap
{
	//--------------------
	//二分ヒープ操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename NODE_TYPE>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public binary_heap::base_ope_t<派生構造体, ノード型>
	//	struct ope_t : public binary_heap::base_ope_t<ope_t, data_t>
	//	{
	//		//キーを比較
	//		//※lhsの方が小さいければ true を返す
	//		inline static bool less(const node_type& lhs, const node_type& rhs)
	//		{
	//			return lhs.m_key < rhs.m_key;
	//		}
	//		
	//		//ロック型 ※必要に応じて定義
	//		//※ロックでコンテナ操作をスレッドセーフにしたい場合は、
	//		//　有効なロック型（spin_lockなど）を lock_type 型として定義する。
	//		typedef spin_lock lock_type;//ロックオブジェクト型
	//	};
	template<class OPE_TYPE, typename NODE_TYPE>
	struct base_ope_t
	{
		//型
		typedef OPE_TYPE ope_type;//ノード操作型
		typedef NODE_TYPE node_type;//ノード型

		//ロック型
		typedef dummy_lock lock_type;//ロックオブジェクト型
		//※デフォルトはダミーのため、一切ロック制御しない。
		//※ロックでコンテナ操作をスレッドセーフにしたい場合は、
		//　base_ope_tの派生クラスにて、有効なロック型（spin_lock など）を
		//　lock_type 型として再定義する。
		//【補足】コンテナには、あらかじめロック制御のための仕組みがソースコードレベルで
		//　　　　仕込んであるが、有効な型を与えない限りは、実行時のオーバーヘッドは一切ない。

		//キーを比較
		//※lhsの方が小さいければ true を返す
		//※派生クラスでの実装が必要
		//inline static bool less(const node_type& lhs, const node_type& rhs)

		//STLのstd::priority_queueと共用するための関数オブジェクト
		inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return ope_type::less(lhs, rhs); }

		//デストラクタ呼び出し
		inline static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type; \
		typedef typename ope_type::lock_type lock_type;
	//--------------------
	//二分ヒープ操作関数：親のインデックス計算
	inline static std::size_t calcParent(const std::size_t index){ return (index - 1) >> 1; }
	//--------------------
	//二分ヒープ操作関数：子のインデックス計算
	inline static std::size_t calcChildL(const std::size_t index){ return (index << 1) + 1; }
	inline static std::size_t calcChildR(const std::size_t index){ return calcChildL(index) + 1; }
	//--------------------
	//二分ヒープ操作関数：アップヒープ
	//※ノードを上方に移動
	template<class OPE_TYPE, class PREDICATE>
	static typename OPE_TYPE::node_type* upHeap(typename OPE_TYPE::node_type* top, const std::size_t size, typename OPE_TYPE::node_type* now, PREDICATE less)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		std::ptrdiff_t index = now - top;
		std::ptrdiff_t _size = static_cast<std::ptrdiff_t>(size);
		if (index < 0 || index >= _size)
			return nullptr;
		while (index != 0)
		{
			index = calcParent(index);
			node_type* parent = top + index;
			if (!less(*parent, *now))
				break;
			swapValues(*parent, *now);
			now = parent;
		}
		return now;
	}
	//--------------------
	//二分ヒープ操作関数：ダウンヒープ
	//※ノードを下方に移動
	template<class OPE_TYPE, class PREDICATE>
	static typename OPE_TYPE::node_type* downHeap(typename OPE_TYPE::node_type* top, const std::size_t size, typename OPE_TYPE::node_type* now, PREDICATE less)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		std::ptrdiff_t index = now - top;
		std::ptrdiff_t _size = static_cast<std::ptrdiff_t>(size);
		if (index < 0 || index >= _size)
			return nullptr;
		while (true)
		{
			index = calcChildL(index);
			if (index >= _size)
				break;
			node_type* child = top + index;
			node_type* child_r = child + 1;
			bool is_swap = false;
			if (index + 1 < _size && !less(*child_r, *child) && !less(*child_r, *now))
			{
				is_swap = true;
				child = child_r;
				++index;
			}
			else if (!less(*child, *now))
			{
				is_swap = true;
			}
			if (!is_swap)
				break;
			swapValues(*child, *now);
			now = child;
		}
		return now;
	}
	
	//----------------------------------------
	//二分ヒープコンテナ
	//※固定配列と使用中の要素数を持つ
	//※std::vectorとstd::priority_queueを一つにしたようなコンテナ。
	//　なお、emplace()メソッドには非対応。
	//※データのコピーを避けて処理効率を向上させるために、
	//　pushBegin()～pushEnd()、popBegin()～popEnd()
	//　というメソッドを用意している。内部のバッファを直接参照するので高速。
	//　なお、begin～end の間はロックが行われる点に注意。
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//定数
		static const size_type TABLE_SIZE = _TABLE_SIZE;//配列要素数
		static const index_type INVALID_INDEX = 0xffffffffu;//無効なインデックス
		enum status_t//ステータス
		{
			IDLE = 0,//アイドル
			PUSH_BEGINNING,//プッシュ開始中
			PUSH_ENDED,//プッシュ終了した
			PUSH_CANCELLED,//プッシュ取り消した
			POP_BEGINNING,//ポップ開始中
			POP_ENDED,//ポップ終了した
			POP_CANCELLED,//ポップ取り消した
		};
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
				return ite;
			}
			inline const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			inline iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			inline iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			inline const_iterator& operator+=(const int val) const
			{
				addIndexAndUpdate(val);
				return *this;
			}
			inline const_iterator& operator-=(const int val) const
			{
				addIndexAndUpdate(-val);
				return *this;
			}
			inline iterator& operator+=(const int val)
			{
				addIndexAndUpdate(val);
				return *this;
			}
			inline iterator& operator-=(const int val)
			{
				addIndexAndUpdate(-val);
				return *this;
			}
			inline const_iterator operator+(const int val) const
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			inline const_iterator operator-(const int val) const
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
			inline iterator operator+(const int val)
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			inline iterator operator-(const int val)
			{
				iterator ite(*this);
				ite -= val;
				return ite;
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
			inline bool isExist() const { return m_index != INVALID_INDEX && m_index < m_con->m_used; }
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
				//if (index == INVALID_INDEX || index < 0 || index > static_cast<index_type>(m_con->m_used))
				if (index > static_cast<index_type>(m_con->m_used))
				{
					m_index = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_index = index;
					m_value = const_cast<value_type*>(m_con->_ref_node(m_index));
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
					update(m_con->m_used);//末尾データ
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
				ite.update(m_con->m_used - index);
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(*m_con, false);
				ite.update(m_con->m_used - index);
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
				return ite;
			}
			inline const_reverse_iterator operator--(int) const
			{
				reverse_iterator ite(*this);
				--(*this);
				return ite;
			}
			inline reverse_iterator operator++(int)
			{
				reverse_iterator ite(*this);
				++(*this);
				return ite;
			}
			inline reverse_iterator operator--(int)
			{
				reverse_iterator ite(*this);
				--(*this);
				return ite;
			}
			inline const_reverse_iterator& operator+=(const int val) const
			{
				addIndexAndUpdate(val);
				return *this;
			}
			inline const_reverse_iterator& operator-=(const int val) const
			{
				addIndexAndUpdate(-val);
				return *this;
			}
			inline reverse_iterator& operator+=(const int val)
			{
				addIndexAndUpdate(val);
				return *this;
			}
			inline reverse_iterator& operator-=(const int val)
			{
				addIndexAndUpdate(-val);
				return *this;
			}
			inline const_reverse_iterator operator+(const int val) const
			{
				reverse_iterator ite(*this);
				ite += val;
				return ite;
			}
			inline const_reverse_iterator operator-(const int val) const
			{
				reverse_iterator ite(*this);
				ite -= val;
				return ite;
			}
			inline reverse_iterator operator+(const int val)
			{
				reverse_iterator ite(*this);
				ite += val;
				return ite;
			}
			inline reverse_iterator operator-(const int val)
			{
				reverse_iterator ite(*this);
				ite -= val;
				return ite;
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
				m_value = rhs.m_value;
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
				m_value = rhs.m_value;
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
			inline const value_type* getValue() const { return m_value - 1; }//現在の値
			inline value_type* getValue(){ return m_value - 1; }//現在の値
		private:
			//メソッド
			void update(const index_type index) const
			{
				//if (index == INVALID_INDEX || index < 0 || index > static_cast<index_type>(m_con->m_used))
				if (index > static_cast<index_type>(m_con->m_used))
				{
					m_index = INVALID_INDEX;
					m_value = nullptr;
				}
				else
				{
					m_index = index;
					m_value = const_cast<value_type*>(m_con->_ref_node(m_index));
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
				m_value(obj.m_value)
			{}
			//コピーコンストラクタ
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_index(obj.m_index),
				m_value(obj.m_value)
			{}
			//コンストラクタ
			inline reverse_iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_index(INVALID_INDEX),
				m_value(nullptr)
			{
				if (!is_end)
					update(m_con->m_used);//末尾データ
				else
					update(0);//先頭データ
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
		inline const node_type* at(const int index) const { return ref_node(index); }
		inline node_type* at(const int index){ return ref_node(index); }
		inline const node_type* operator[](const int index) const { return ref_node(index); }
		inline node_type* operator[](const int index){ return ref_node(index); }
		inline status_t status() const { return m_status; }
	public:
		//キャストオペレータ
		inline operator lock_type&(){ return m_lock; }//共有ロックオブジェクト
		inline operator lock_type&() const { return m_lock; }//共有ロックオブジェクト ※mutable
	public:
		//メソッド
		inline size_type max_size() const { return TABLE_SIZE; }//最大要素数を取得
		inline size_type capacity() const { return TABLE_SIZE; }//最大要素数を取得
		inline size_type size() const { return m_used; }//使用中の要素数を取得
		inline bool empty() const { return m_used == 0; }//空か？
	public:
		int depth_max() const//最大の深さを取得
		{
			if (m_used == 0)
				return -1;
			int depth = 0;
			int used = m_used >> 1;
			while (used != 0)
			{
				++depth;
				used >>= 1;
			}
			return depth;
		}
	private:
		inline const node_type* _ref_node(const int index) const { return reinterpret_cast<const node_type*>(&m_table[index]); }//ノード参照
		inline const node_type* _ref_top() const { return _ref_node(0); }//先頭ノード参照
		inline const node_type* _ref_bottom() const { return _ref_node(m_used - 1); }//終端ノード参照
		inline const node_type* _ref_new() const { return _ref_node(m_used); }//新規ノード参照
		inline node_type* _ref_node(const int index){ return reinterpret_cast<node_type*>(&m_table[index]); }//ノード参照
		inline node_type* _ref_top(){ return _ref_node(0); }//先頭ノード参照
		inline node_type* _ref_bottom(){ return _ref_node(m_used - 1); }//終端ノード参照
		inline node_type* _ref_new(){ return _ref_node(m_used); }//新規ノード参照
	public:
		inline const node_type* ref_node(const int index) const { return index >= 0 && index < static_cast<int>(m_used) ? _ref_node(index) : nullptr; }//ノード参照
		inline const node_type* ref_top() const { return m_used == 0 ? nullptr : _ref_top(); }//先頭ノード参照
		inline const node_type* ref_bottom() const { return m_used == 0 ? nullptr : _ref_bottom(); }//終端ノード参照
		inline const node_type* ref_new() const { return m_used == TABLE_SIZE ? nullptr : _ref_new(); }//新規ノード参照
		inline node_type* ref_node(const int index){ return  const_cast<node_type*>(const_cast<const container*>(this)->ref_node()); }//ノード参照
		inline node_type* ref_top(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_top()); }//先頭ノード参照
		inline node_type* ref_bottom(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_bottom()); }//終端ノード参照
		inline node_type* ref_new(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_new()); }//新規ノード参照
	private:
		inline int _adj_index(const int index) const { return index >= 0 && index < TABLE_SIZE ? index : -1; }//インデックスを範囲内に補正
		inline int _ref_index(const node_type* node) const{ return node - _ref_top(); }//ノードをインデックスに変換 ※範囲チェックなし
		inline int _calc_parent(const int index) const { return binary_heap::calcParent(index); }//親インデックス計算 ※範囲チェックなし
		inline int _calc_child_l(const int index) const { return binary_heap::calcChildL(index); }//左側の子インデックス計算 ※範囲チェックなし
		inline int _calc_child_r(const int index) const { return binary_heap::calcChildR(index); }//右側の子インデックス計算 ※範囲チェックなし
	public:
		inline int ref_index(const node_type* node) const{ return _adj_index(_ref_index(node)); }//ノードをインデックスに変換
		inline int calc_parent(const int index) const { return _adj_index(_calc_parent(index)); }//親インデックス計算
		inline int calc_child_l(const int index) const { return _adj_index(_calc_child_l(index)); }//左側の子インデックス計算
		inline int calc_child_r(const int index) const { return _adj_index(_calc_child_r(index)); }//右側の子インデックス計算
		inline int calc_child(const int index, const bool is_right) const { return is_right ? calc_child_r(index) : calc_child_l(index); }//子インデックス計算
		inline const node_type* ref_parent(const node_type* node) const { return ref_node(_calc_parent(_ref_index(node))); }//親ノード参照
		inline const node_type* ref_child_l(const node_type* node) const { return ref_node(_calc_child_l(_ref_index(node))); }//左側の子ノード参照
		inline const node_type* ref_child_r(const node_type* node) const { return ref_node(_calc_child_r(_ref_index(node))); }//左側の子ノード参照
		inline const node_type* ref_child(const node_type* node, const bool is_right) const { return is_right ? ref_child_r(node) : ref_child_l(node); }//子ノード参照
		inline node_type* ref_parent(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_parent(index)); }//親ノード参照
		inline node_type* ref_child_l(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child_l(index)); }//左側の子ノード参照
		inline node_type* ref_child_r(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child_r(index)); }//左側の子ノード参照
		inline node_type* ref_child(const int index, const bool is_right){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child(index, is_right)); }//子ノード参照
	public:
		inline const node_type* top() const { return ref_top(); }//先頭ノード参照
		inline node_type* top(){ return ref_top(); }//先頭ノード参照
		inline bool less(const node_type& lhs, const node_type& rhs) const { return ope_type::less(lhs, rhs); }//キー比較
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
	private:
		//プッシュ（本体）：ムーブ
		node_type* _pushCopying(const node_type&& src)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			*obj = std::move(src);
			m_status = PUSH_BEGINNING;
			return pushEnd();
		}
		//プッシュ（本体）：コピー
		node_type* _pushCopying(const node_type& src)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			*obj = src;
			m_status = PUSH_BEGINNING;
			return pushEnd();
		}
	public:
		//プッシュ
		//※オブジェクト渡し
		//※オブジェクトのコピーが発生する点に注意（少し遅くなる）
		//※ムーブオペレータを使用してコピーする点に注意
		//※処理中、ロックを取得する
		inline node_type* pushCopying(const node_type&& src)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _pushCopying(std::move(src));
		}
		inline node_type* pushCopying(const node_type& src)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _pushCopying(src);
		}
	private:
		//プッシュ（本体）
		template<typename... Tx>
		node_type* _push(Tx... args)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = pushBegin(args...);
			if (!obj)
				return nullptr;
			return pushEnd();
		}
	public:
		//プッシュ
		//※パラメータ渡し
		//※オブジェクトのコンストラクタが呼び出される
		//※処理中、ロックを取得する
		template<typename... Tx>
		inline node_type* push(Tx... args)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _push(args...);
		}
	private:
		//プッシュ開始（本体）
		template<typename... Tx>
		node_type* _pushBegin(Tx... args)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			obj = new(obj)node_type(args...);//コンストラクタ呼び出し
			if (obj)
				m_status = PUSH_BEGINNING;
			return obj;
		}
	public:
		//プッシュ開始
		//※空きノードを取得し、コンストラクタが呼び出される
		//※処理が成功すると、ロックを取得した状態になる（pushEndで解放する）
		template<typename... Tx>
		inline node_type* pushBegin(Tx... args)
		{
			m_lock.lock();//ロックを取得（そのまま関数を抜ける）
			node_type* obj = _pushBegin(args...);//プッシュ開始
			if (!obj)
				m_lock.unlock();//プッシュ失敗時はロック解放
			return obj;
		}
	private:
		//プッシュ終了（本体）
		node_type* _pushEnd()
		{
			if (m_status != PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			++m_used;
			m_status = PUSH_ENDED;
			//末端の葉ノードとして登録された新規ノードを上方に移動
			return upHeap(obj);
		}
	public:
		//プッシュ終了
		//※追加した新規ノードを上に移動
		//※pushBeginで取得したロックを解放する
		inline node_type* pushEnd()
		{
			const bool unlock = (m_status == PUSH_BEGINNING);//プッシュ開始中ならアンロックする
			node_type* new_obj = _pushEnd();//プッシュ終了
			if (unlock)
				m_lock.unlock();//ロック解放
			return new_obj;
		}
	private:
		//プッシュ取り消し（本体）
		bool _pushCancel()
		{
			if (m_status != PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return false;
			m_status = PUSH_CANCELLED;
			return true;
		}
	public:
		//プッシュ取り消し
		//※pushBeginで取得したロックを解放する
		inline bool pushCancel()
		{
			const bool unlock = (m_status == PUSH_BEGINNING);//プッシュ開始中ならアンロックする
			const bool result = _pushCancel();//プッシュ取り消し
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	private:
		//ポップ（本体）
		bool _popCopying(node_type& dst)
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return false;
			const node_type* obj = popBegin();
			if (!obj)
				return false;
			dst = *obj;
			return popEnd();
		}
	public:
		//ポップ
		//※オブジェクトのコピーを受け取る領域を渡す
		//※オブジェクトのデストラクタが呼び出される ※コピー後に実行
		//※処理中、ロックを取得する
		inline bool popCopying(node_type& dst)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _popCopying(dst);
		}
	private:
		//ポップ開始（本体）
		node_type* _popBegin()
		{
			if (m_status == PUSH_BEGINNING || m_status == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = ref_top();
			if (obj)
				m_status = POP_BEGINNING;
			return obj;
		}
	public:
		//ポップ開始
		//※根ノード取得
		//※処理が成功すると、ロックを取得した状態になる（popEndで解放する）
		node_type* popBegin()
		{
			m_lock.lock();//ロックを取得（そのまま関数を抜ける）
			node_type* obj = _popBegin();//ポップ開始
			if (!obj)
				m_lock.unlock();//プッシュ失敗時はロック解放
			return obj;
		}
	private:
		//ポップ終了（本体）
		bool _popEnd()
		{
			if (m_status != POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			node_type* obj = ref_bottom();
			if (!obj)
				return false;
			ope_type::callDestructor(obj);//デストラクタ呼び出し
			operator delete(obj, obj);//（作法として）deleteオペレータ呼び出し
			m_status = POP_ENDED;
			//根ノードがポップされたので、末端の葉ノードを根ノードに上書きした上で、それを下方に移動
			node_type* top_obj = _ref_top();
			*top_obj = std::move(*obj);
			--m_used;
			downHeap(top_obj);
			return true;
		}
	public:
		//ポップ終了
		//※オブジェクトのデストラクタが呼び出される
		//※削除した根ノードの隙間を埋めるために、以降のノードを上に移動
		//※popBeginで取得したロックを解放する
		inline bool popEnd()
		{
			const bool unlock = (m_status == POP_BEGINNING);//ポップ開始中ならアンロックする
			const bool result = _popEnd();//ポップ終了
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	private:
		//ポップ取り消し（本体）
		bool _popCancel()
		{
			if (m_status != POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			m_status = POP_CANCELLED;
			return true;
		}
	public:
		//ポップ取り消し
		//※popBeginで取得したロックを解放する
		inline bool popCancel()
		{
			const bool unlock = (m_status == POP_BEGINNING);//ポップ開始中ならアンロックする
			const bool result = _popCancel();//ポップ取り消し
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	public:
		//ノードを上方に移動
		//※ロックを取得しないで処理するので注意！
		//　（局所的なロックで済む処理ではないため）
		//　必ず呼び出し元でロックを取得すること！
		node_type* upHeap(node_type* obj)
		{
			return binary_heap::upHeap<ope_type>(_ref_top(), m_used, obj, ope_type::less);
		}
		//ノードを下方に移動
		//※ロックを取得しないで処理するので注意！
		//　（局所的なロックで済む処理ではないため）
		//　必ず呼び出し元でロックを取得すること！
		node_type* downHeap(node_type* obj)
		{
			return binary_heap::downHeap<ope_type>(_ref_top(), m_used, obj, ope_type::less);
		}
	private:
		//クリア（本体）
		void _clear()
		{
			if (m_used == 0)
				return;
			node_type* obj_end = _ref_top() + m_used;
			for (node_type* obj = _ref_top(); obj < obj_end; ++obj)
			{
				ope_type::callDestructor(obj);//デストラクタ呼び出し
				operator delete(obj, obj);//（作法として）deleteオペレータ呼び出し
			}
			m_used = 0;
		}
	public:
		//クリア
		//※処理中、ロックを取得する
		inline void clear()
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			_clear();
		}
	public:
		//コンストラクタ
		container() :
			m_used(0),
			m_status(IDLE)
		{}
		//デストラクタ
		~container()
		{
			pushCancel();//プッシュ取り消し
			popCancel();//ポップ取り消し
		}
	private:
		//フィールド
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//データテーブル
		size_type m_used;//使用数
		status_t m_status;//ステータス
		mutable lock_type m_lock;//ロックオブジェクト
	};
	//イテレータのムーブオペレータ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	//typename container<OPE_TYPE, _TABLE_SIZE>::iterator& container<OPE_TYPE, _TABLE_SIZE>::iterator::operator=(typename container<OPE_TYPE, _TABLE_SIZE>::const_reverse_iterator&& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE, _TABLE_SIZE>::iterator& container<OPE_TYPE, _TABLE_SIZE>::iterator::operator=(const typename container<OPE_TYPE, _TABLE_SIZE>::reverse_iterator&& rhs)//VC++もOK
	{
		m_con = rhs.m_con;
		m_index = rhs.m_index;
		m_value = rhs.m_value;
		return *this;
	}
	//イテレータのコピーオペレータ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	//typename container<OPE_TYPE, _TABLE_SIZE>::iterator& container<OPE_TYPE, _TABLE_SIZE>::iterator::operator=(typename container<OPE_TYPE, _TABLE_SIZE>::const_reverse_iterator& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE, _TABLE_SIZE>::iterator& container<OPE_TYPE, _TABLE_SIZE>::iterator::operator=(const typename container<OPE_TYPE, _TABLE_SIZE>::reverse_iterator& rhs)//VC++もOK
	{
		m_con = rhs.m_con;
		m_index = rhs.m_index;
		m_value = rhs.m_value;
		return *this;
	}
	//イテレータのムーブコンストラクタ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	//container<OPE_TYPE, _TABLE_SIZE>::iterator::iterator(typename container<OPE_TYPE, _TABLE_SIZE>::const_reverse_iterator&& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE, _TABLE_SIZE>::iterator::iterator(const typename container<OPE_TYPE, _TABLE_SIZE>::reverse_iterator&& obj) ://VC++もOK
		m_con(obj.m_con),
		m_index(obj.m_index),
		m_value(obj.m_value)
	{}
	//イテレータのコピーコンストラクタ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	//container<OPE_TYPE, _TABLE_SIZE>::iterator::iterator(typename container<OPE_TYPE, _TABLE_SIZE>::const_reverse_iterator& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE, _TABLE_SIZE>::iterator::iterator(const typename container<OPE_TYPE, _TABLE_SIZE>::reverse_iterator& obj) ://VC++もOK
		m_con(obj.m_con),
		m_index(obj.m_index),
		m_value(obj.m_value)
	{}
	//--------------------
	//安全なプッシュ／ポップ操作クラス
	//※操作状態を記憶し、デストラクタで必ず完了させる
	template<class CON>
	class operation_guard
	{
	public:
		//型
		typedef CON container_type;//コンテナ型
		typedef typename CON::node_type node_type;//ノード型
		typedef typename CON::status_t status_t;//ステータス型
	public:
		//アクセッサ
		status_t status() const { return m_status; }//ステータスを取得
	public:
		//プッシュ開始
		template<typename... Tx>
		node_type* pushBegin(Tx... args)
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_container.pushBegin(args...);//プッシュ開始
			if (node)
				m_status = status_t::PUSH_BEGINNING;//ステータス変更
			return node;
		}
		//プッシュ終了
		node_type* pushEnd()
		{
			if (m_status != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			node_type* node = m_container.pushEnd();//プッシュ終了
			m_status = status_t::PUSH_ENDED;//ステータス変更
			return node;
		}
		//プッシュ取り消し
		bool pushCancel()
		{
			if (m_status != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return false;
			m_container.pushCancel();//プッシュ取り消し
			m_status = status_t::PUSH_CANCELLED;//ステータス変更
			return true;
		}
		//ポップ開始
		node_type* popBegin()
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_container.popBegin();//ポップ開始
			if (node)
				m_status = status_t::POP_BEGINNING;//ステータス変更
			return node;
		}
		//ポップ終了
		bool popEnd()
		{
			if (m_status != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			const bool result = m_container.popEnd();//ポップ終了
			m_status = status_t::POP_ENDED;//ステータス変更
			return result;
		}
		//ポップ取り消し
		bool popCancel()
		{
			if (m_status != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			m_container.popCancel();//ポップ取り消し
			m_status = status_t::POP_CANCELLED;//ステータス変更
			return true;
		}
	public:
		//コンストラクタ
		operation_guard(container_type& container) :
			m_container(container),
			m_status(status_t::IDLE)
		{}
		//デストラクタ
		~operation_guard()
		{
			pushEnd();//プッシュ終了
			popEnd();//ポップ終了
		}
	private:
		//フィールド
		container_type& m_container;//コンテナ
		status_t m_status;//ステータス
	};
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace binary_heap

//--------------------------------------------------------------------------------
//プライオリティキュー
//※プライオリティとともに、シーケンス番号を扱うことで、キューイングの順序性を保証する。
//--------------------------------------------------------------------------------

#include <utility>//C++11 std::move用

namespace priority_queue
{
	//--------------------
	//プライオリティキュー操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename NODE_TYPE, int _NODES_MAX>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public priority_queue::base_ope_t<派生構造体, ノード型, 優先度型, シーケンス番号型>
	//	struct ope_t : public priority_queue::base_ope_t<ope_t, data_t, int, unsigned int>
	//	{
	//		//優先度を取得
	//		inline static priority_type getPriority(const node_type& node){ return node.m_priority; }
	//		//優先度を更新
	//		inline static void setPriority(node_type& node, const priority_type priority){ node.m_priority = priority; }
	//		
	//		//シーケンス番号を取得
	//		inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//		//シーケンス番号を更新
	//		inline static void setSeqNo(node_type& node, const seq_type seq_no) const { node.m_seqNo = seq_no; }
	//		
	//		//優先度を比較 ※必要に応じて定義
	//		inline static int compareProior(const priority_type lhs, const priority_type rhs){ return ???; }
	//		
	//		//ロック型 ※必要に応じて定義
	//		//※ロックでコンテナ操作をスレッドセーフにしたい場合は、
	//		//　有効なロック型（spin_lockなど）を lock_type 型として定義する。
	//		typedef spin_lock lock_type;//ロックオブジェクト型
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, typename PRIOR_TYPE = int, typename SEQ_TYPE = unsigned int>
	struct base_ope_t
	{
		//型
		typedef OPE_TYPE ope_type;//ノード操作型
		typedef NODE_TYPE node_type;//ノード型
		typedef PRIOR_TYPE priority_type;//優先度型
		typedef SEQ_TYPE seq_type;//シーケンス番号型
		
		//ロック型
		typedef dummy_lock lock_type;//ロックオブジェクト型
		//※デフォルトはダミーのため、一切ロック制御しない。
		//※ロックでコンテナ操作をスレッドセーフにしたい場合は、
		//　base_ope_tの派生クラスにて、有効なロック型（spin_lock など）を
		//　lock_type 型として再定義する。
		//【補足】コンテナには、あらかじめロック制御のための仕組みがソースコードレベルで
		//　　　　仕込んであるが、有効な型を与えない限りは、実行時のオーバーヘッドは一切ない。

		//シーケンス番号を比較
		inline static bool lessSeqNo(const seq_type lhs, const seq_type rhs)
		{
			return lhs > rhs;
		}

		//優先度を比較
		//※デフォルト
		//Return value:
		//  0     ... lhs == rhs
		//  1以上 ... lhs > rhs
		// -1以下 ... lhs < rhs
		inline static int comparePriority(const priority_type lhs, const priority_type rhs)
		{
			return static_cast<int>(lhs)-static_cast<int>(rhs);
		}

		//キーを比較
		//※lhsの方が小さいければ true を返す
		inline static bool _lessSeqNo(const int compare_priority, const seq_type lhs, const seq_type rhs)
		{
			return compare_priority < 0 ? true : compare_priority > 0 ? false : ope_type::lessSeqNo(lhs, rhs);
		}
		inline static bool less(const node_type& lhs, const node_type& rhs)
		{
			return _lessSeqNo(ope_type::comparePriority(ope_type::getPriority(lhs), ope_type::getPriority(rhs)), ope_type::getSeqNo(lhs), ope_type::getSeqNo(rhs));
		}

		//STLのstd::priority_queueと共用するための関数オブジェクト
		inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return ope_type::less(lhs, rhs); }

		//デストラクタ呼び出し
		static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }

		//コンテナ操作型
		struct container_ope_type
		{
			typedef OPE_TYPE adapter_ope_type;//コンテナアダプタのノード操作型
			typedef container_ope_type ope_type;//ノード操作型
			typedef NODE_TYPE node_type;//ノード型
			
			//キーを比較
			//※lhsの方が小さいければ true を返す
			inline static bool less(const node_type& lhs, const node_type& rhs)
			{
				return adapter_ope_type::less(lhs, rhs);
			}

			//STLのstd::priority_queueと共用するための関数オブジェクト
			inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return adapter_ope_type::less(lhs, rhs); }

			//デストラクタ呼び出し
			static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
			
			//ロック型
			typedef dummy_lock lock_type;//ロックオブジェクト型
			//※コンテナ側でのロックは使用しない
		};
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef typename ope_type::priority_type priority_type; \
		typedef typename ope_type::seq_type seq_type; \
		typedef typename ope_type::lock_type lock_type;
	//----------------------------------------
	//プライオリティキューコンテナアダプタ
	//※コンテナのデフォルトは二分ヒープ（binary_heap::container）。
	//　同じインターフェースを持ったクラスなら、置き換えて使用可能。
	//※std::priority_queueとはあまり互換性がなく、イテレータにも対応しない
	//※イテレータが必要なら、container_adapter::container_type にキャストして
	//　コンテナを取り出せば操作可能。
	//※データのコピーを避けて処理効率を向上させるために、
	//　enqueueBegin()～enqueueEnd()、dequeueBegin()～dequeueEnd()
	//　というメソッドを用意している。内部のバッファを直接参照するので高速。
	//　なお、begin～end の間はロックが行われる点に注意。
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, class CONTAINER_TYPE = binary_heap::container<typename OPE_TYPE::container_ope_type, _TABLE_SIZE> >
	class container_adapter
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
		typedef CONTAINER_TYPE container_type;//コンテナ型
		typedef typename container_type::status_t status_t;//ステータス型
	public:
		//アクセッサ
		inline const container_type& getContainer() const { return m_container; }//コンテナ取得
		inline container_type& getContainer(){ return m_container; }//コンテナ取得
	public:
		//キャストオペレータ
		inline operator const container_type&() const{ return m_container; }//コンテナを返す
		inline operator container_type&(){ return m_container; }//コンテナを返す
		inline operator lock_type&(){ return m_lock; }//共有ロックオブジェクト
		inline operator lock_type&() const { return m_lock; }//共有ロックオブジェクト ※mutable
	public:
		//メソッド
		inline size_type max_size() const { return m_container.max_aize(); }//最大要素数を取得
		inline size_type capacity() const { return m_container.capacity(); }//最大要素数を取得
		inline size_type size() const { return m_container.size(); }//使用中の要素数を取得
		inline bool empty() const { return m_container.empty(); }//空か？
	private:
		//シーケンス番号発行
		inline seq_type getNextSeqNo(){ return m_seqNo++; }
		//可能ならシーケンス番号をリセット
		inline void checkAndResetSeqNo()
		{
			if (m_container.empty())
				m_seqNo = 0;
		}
	private:
		//エンキュー（本体）：ムーブ
		node_type* _enqueueCopying(const node_type&& obj)
		{
			if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type obj_tmp(std::move(obj));//一時オブジェクトにムーブ
			ope_type::setSeqNo(obj_tmp, getNextSeqNo());//シーケンス番号をセット
			return m_container.pushCopying(std::move(obj_tmp));//コンテナにプッシュ（ムーブ）
		}
		//エンキュー（本体）：コピー
		node_type* _enqueueCopying(const node_type& obj)
		{
			if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type obj_tmp(obj);//一時オブジェクトにコピー
			ope_type::setSeqNo(obj_tmp, getNextSeqNo());//シーケンス番号をセット
			return m_container.pushCopying(std::move(obj_tmp));//コンテナにプッシュ（ムーブ）
		}
	public:
		//エンキュー
		//※オブジェクト渡し
		//※オブジェクトには、あらかじめ優先度を設定しておく必要がある
		//※オブジェクトのコピーが２回発生する点に注意（少し遅くなる）
		//　（シーケンス番号をセットするために1回テンポラリにコピーし、プッシュ時にさらにコピーする。）
		//※ムーブコンストラクタとムーブオペレータを使用してコピーする点に注意
		//※処理中、ロックを取得する
		inline node_type* enqueueCopying(const node_type&& obj)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _enqueueCopying(std::move(obj));
		}
		inline node_type* enqueueCopying(const node_type& obj)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _enqueueCopying(obj);
		}
	private:
		//エンキュー（本体）
		template<typename... Tx>
		node_type* _enqueue(const priority_type priority, Tx... args)
		{
			//if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_container.pushBegin(args...);//コンテナにプッシュ開始
			if (!obj)
				return nullptr;
			ope_type::setPriority(*obj, priority);//優先度を設定
			ope_type::setSeqNo(*obj, getNextSeqNo());//シーケンス番号をセット
			obj = m_container.pushEnd();//コンテナにプッシュ終了
			return obj;
		}
	public:
		//エンキュー
		//※パラメータ渡し
		//※オブジェクトのコンストラクタが呼び出される
		//※オブジェクトには、シーケンス番号が書き込まれる
		//※処理中、ロックを取得する
		template<typename... Tx>
		inline node_type* enqueue(const priority_type priority, Tx... args)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _enqueue(priority, args...);
		}
	private:
		//エンキュー開始（本体）
		template<typename... Tx>
		node_type* _enqueueBegin(const priority_type priority, Tx... args)
		{
			//if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_container.pushBegin(args...);//コンテナにプッシュ開始
			if (!obj)
				return nullptr;
			ope_type::setPriority(*obj, priority);//優先度を設定
			ope_type::setSeqNo(*obj, getNextSeqNo());//シーケンス番号を設定
			return obj;
		}
	public:
		//エンキュー開始
		//※空きキュー取得
		//※エンキュー完了時に enqueueEnd を呼び出す必要あり
		//※この時点で、優先度とシーケンス番号が書き込まれる
		//※処理が成功すると、ロックを取得した状態になる（enqueueEndで解放する）
		template<typename... Tx>
		inline node_type* enqueueBegin(const priority_type priority, Tx... args)
		{
			m_lock.lock();//ロックを取得（そのまま関数を抜ける）
			node_type* obj = _enqueueBegin(args...);//エンキュー開始
			if (!obj)
				m_lock.unlock();//プッシュ失敗時はロック解放
			return obj;
		}
	private:
		//エンキュー終了（本体）
		inline node_type* _enqueueEnd()
		{
			//if (m_container.status() != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
			//	return;
			return m_container.pushEnd();//コンテナにプッシュ終了
		}
	public:
		//エンキュー終了
		//※enqueueBeginで取得したロックを解放する
		inline node_type* enqueueEnd()
		{
			const bool unlock = (m_container.status() == status_t::PUSH_BEGINNING);//プッシュ開始中ならアンロックする
			node_type* new_obj = _enqueueEnd();//エンキュー終了
			if (unlock)
				m_lock.unlock();//ロック解放
			return new_obj;
		}
	private:
		//エンキュー取り消し（本体）
		inline bool _enqueueCancel()
		{
			//if (m_container.status() != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
			//	return;
			return m_container.pushCancel();//プッシュ取り消し
		}
	public:
		//エンキュー取り消し
		//※enqueueBeginで取得したロックを解放する
		inline bool enqueueCancel()
		{
			const bool unlock = (m_container.status() == status_t::PUSH_BEGINNING);//プッシュ開始中ならアンロックする
			const bool result = m_container.pushCancel();//プッシュ取り消し
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	private:
		//デキュー（本体）
		bool _dequeueCopying(node_type& dst)
		{
			//if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			const bool result = m_container.popCopying(dst);//コンテナからポップ
			if (!result)
				return false;
			checkAndResetSeqNo();//キューが空になったらシーケンス番号をリセットする
			return true;
		}
	public:
		//デキュー
		//※オブジェクトのコピーを受け取る領域を渡す
		//※オブジェクトのデストラクタが呼び出される ※コピー後に実行
		//※処理中、ロックを取得する
		inline bool dequeueCopying(node_type& dst)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _dequeueCopying(dst);
		}
	private:
		//デキュー開始（本体）
		//※デキュー完了時に dequeueEnd を呼び出す必要あり
		node_type* _dequeueBegin()
		{
			//if (m_container.status() == status_t::PUSH_BEGINNING || m_container.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_container.popBegin();//コンテナからポップ開始
			if (!obj)
				return nullptr;
			return obj;
		}
	public:
		//デキュー開始
		//※デキュー完了時に dequeueEnd を呼び出す必要あり
		//※処理が成功すると、ロックを取得した状態になる（dequeueEndで解放する）
		inline node_type* dequeueBegin()
		{
			m_lock.lock();//ロックを取得（そのまま関数を抜ける）
			node_type* obj = _dequeueBegin();//デキュー開始
			if (!obj)
				m_lock.unlock();//プッシュ失敗時はロック解放
			return obj;
		}
	private:
		//デキュー終了（本体）
		bool _dequeueEnd()
		{
			//if (m_container.status() != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
			//	return false;
			const bool result = m_container.popEnd();//コンテナからポップ終了
			checkAndResetSeqNo();//キューが空になったらシーケンス番号をリセットする
			return result;
		}
	public:
		//デキュー終了
		//※オブジェクトのデストラクタが呼び出される
		//※dequeueBeginで取得したロックを解放する
		inline bool dequeueEnd()
		{
			const bool unlock = (m_container.status() == status_t::POP_BEGINNING);//ポップ開始中ならアンロックする
			const bool result = _dequeueEnd();//デキュー終了
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	private:
		//デキュー取り消し（本体）
		bool _dequeueCancel()
		{
			//if (m_container.status() != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
			//	return false;
			return m_container.popCancel();//ポップ取り消し
		}
	public:
		//デキュー取り消し
		//※dequeueBeginで取得したロックを解放する
		inline bool dequeueCancel()
		{
			const bool unlock = (m_container.status() == status_t::POP_BEGINNING);//ポップ開始中ならアンロックする
			const bool result = _dequeueCancel();//デキュー取り消し
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
		//先頭（根）キューを参照
		//※デキューしない
		inline const node_type* top() const
		{
			return m_container.top();//コンテナの先頭（根）ノードを取得
		}
	private:
		//先頭（根）キューのプライオリティ変更（本体）
		node_type* _changePriorityOnTop(const priority_type priority)
		{
			node_type* obj = m_container.top();
			if (!obj)
				return nullptr;
			ope_type::setPriority(*obj, priority);//優先度を更新
			ope_type::setSeqNo(*obj, getNextSeqNo());//シーケンス番号を更新
			return m_container.downHeap(obj);//ダウンヒープ
		}
	public:
		//先頭（根）キューのプライオリティ変更
		//※プライオリティを変更した時点でキューの位置が入れ替わる
		//※シーケンス番号を再更新する
		//※同じプライオリティに変更した場合、同じプライオリティのキューの一番最後に回される
		//※処理中、ロックを取得する
		inline node_type* changePriorityOnTop(const priority_type priority)
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			return _changePriorityOnTop(priority);
		}
		//※ロックなし版（top()参照～プライオリティ変更までを任意にロックするならこちらを使用する）
		inline node_type* changePriorityOnTopWithoutLock(const priority_type priority)
		{
			return _changePriorityOnTop(priority);
		}
	private:
		//クリア（本体）
		inline void _clear()
		{
			m_container.clear();
		}
	public:
		//クリア
		//※処理中、ロックを取得する
		inline void clear()
		{
			lock_guard<lock_type> lock(m_lock);//ロック取得（関数を抜ける時に自動開放）
			_clear();
		}
	public:
		//コンストラクタ
		container_adapter() :
			m_container(),
			m_seqNo(0),
			m_lock()
		{}
		//デストラクタ
		~container_adapter()
		{
			enqueueCancel();//エンキュー取り消し
			dequeueCancel();//デキュー取り消し
		}
	private:
		//フィールド
		container_type m_container;//コンテナ
		int m_dummy;
		seq_type m_seqNo;//シーケンス番号 ※mutable修飾子
		mutable lock_type m_lock;//ロックオブジェクト
	};
	//--------------------
	//安全なエンキュー／デキュー操作クラス
	//※操作状態を記憶し、デストラクタで必ず完了させる
	template<class CON>
	class operation_guard
	{
	public:
		//型
		typedef CON container_adapter_type;//コンテナアダプター型
		typedef typename CON::node_type node_type;//ノード型
		typedef typename CON::status_t status_t;//ステータス型
	public:
		//アクセッサ
		status_t status() const { return m_status; }//ステータスを取得
	public:
		//エンキュー開始
		template<typename... Tx>
		node_type* enqueueBegin(const typename CON::priority_type priority, Tx... args)
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_containerAdapter.enqueueBegin(priority, args...);//エンキュー開始
			if (node)
				m_status = status_t::PUSH_BEGINNING;//ステータス変更
			return node;
		}
		//エンキュー終了
		node_type* enqueueEnd()
		{
			if (m_status != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			node_type* node = m_containerAdapter.enqueueEnd();//エンキュー終了
			m_status = status_t::PUSH_ENDED;//ステータス変更
			return node;
		}
		//エンキュー取り消し
		bool enqueueCancel()
		{
			if (m_status != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			m_containerAdapter.enqueueCancel();//エンキュー取り消し
			m_status = status_t::PUSH_CANCELLED;//ステータス変更
			return true;
		}
		//デキュー開始
		node_type* dequeueBegin()
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_containerAdapter.dequeueBegin();//デキュー開始
			if (node)
				m_status = status_t::POP_BEGINNING;//ステータス変更
			return node;
		}
		//デキュー終了
		bool dequeueEnd()
		{
			if (m_status != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			const bool result = m_containerAdapter.dequeueEnd();//デキュー終了
			m_status = status_t::POP_ENDED;//ステータス変更
			return result;
		}
		//デキュー取り消し
		bool dequeueCancel()
		{
			if (m_status != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			m_containerAdapter.dequeueCancel();//デキュー取り消し
			m_status = status_t::POP_CANCELLED;//ステータス変更
			return true;
		}
	public:
		//コンストラクタ
		operation_guard(container_adapter_type& container_adapter) :
			m_containerAdapter(container_adapter),
			m_status(status_t::IDLE)
		{}
		//デストラクタ
		~operation_guard()
		{
			enqueueEnd();//エンキュー終了
			dequeueEnd();//デキュー終了
		}
	private:
		//フィールド
		container_adapter_type& m_containerAdapter;//コンテナアダプタ
		status_t m_status;//ステータス
	};
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace priority_queue

//--------------------------------------------------------------------------------
//プライオリティキューテスト
//--------------------------------------------------------------------------------

#include <memory.h>//memcpy用
#include <random>//C++11 std::random用
#include <algorithm>//std::for_each用
#include <queue>//std::priority_queue用※比較テスト用

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
enum PRIORITY : short
{
	HIGHEST = 5,
	HIGHER = 4,
	NORMAL = 3,
	LOWER = 2,
	LOWEST = 1,
};
struct data_t
{
	PRIORITY m_priority;//優先度
	unsigned int m_seqNo;//シーケンス番号
	int m_val;//データ
	int m_data[2];

	//コンストラクタ
	data_t(const PRIORITY priority, const int val) :
		m_priority(priority),
		m_seqNo(0),
		m_val(val)
	{
		m_data[0] = 99;
		m_data[1] = 99;
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d, %d)\n", priority, val);
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	data_t(const int val) :
		m_priority(NORMAL),
		m_seqNo(0),
		m_val(val)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d)\n", val);
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
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
	//デフォルトコンストラクタ
	data_t() :
		m_priority(NORMAL),
		m_seqNo(0),
		m_val(0)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor\n");
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	//デストラクタ
	~data_t()
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::destructor\n");
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
};
//----------------------------------------
//テストデータ操作クラス
struct heap_ope_t : public binary_heap::base_ope_t<heap_ope_t, data_t>
{
	//キーを比較
	//※lhsの方が小さいければ true を返す
	//※派生クラスでの実装が必要
	inline static bool less(const node_type& lhs, const node_type& rhs)
	{
		return lhs.m_priority < rhs.m_priority;//優先度のみを比較
	}
	
	//ロック型
	//※デフォルト（dummy_lock）のままとする
	//typedef spin_lock lock_type;//ロックオブジェクト型
};
//----------------------------------------
//テストデータ操作クラス
struct ope_t : public priority_queue::base_ope_t<ope_t, data_t, PRIORITY, int>
{
	//優先度を取得
	inline static priority_type getPriority(const node_type& node){ return node.m_priority; }
	//優先度を更新
	inline static void setPriority(node_type& node, const priority_type priority){ node.m_priority = priority; }
	
	//シーケンス番号を取得
	inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//シーケンス番号を更新
	inline static void setSeqNo(node_type& node, const seq_type seq_no){ node.m_seqNo = seq_no; }

	//ロック型
	//※デフォルト（dummy_lock）のままとする
	//typedef spin_lock lock_type;//ロックオブジェクト型
};

//----------------------------------------
//木を表示
template<class HEAP>
void showTree(const HEAP& heap)
{
	printf_detail("\n");
	printf_detail("--- Show tree (count=%d) ---\n", heap.size());
	//static const int depth_limit = 5;//最大でも5段階目までを表示（0段階目から数えるので最大で6段階表示される→最大：1+2+4+8+16+32=63個）
	static const int depth_limit = 4;//最大でも4段階目までを表示（0段階目から数えるので最大で5段階表示される→最大：1+2+4+8+16=31個）
	const int _depth_max = heap.depth_max();
	printf_detail("depth_max=%d (limit for showing=%d)\n", _depth_max, depth_limit);
	const int depth_max = _depth_max <= depth_limit ? _depth_max : depth_limit;
	const int width_max = static_cast<int>(std::pow(2, depth_max));
	for (int depth = 0; depth <= depth_max; ++depth)
	{
		const int width = static_cast<int>(std::pow(2, depth));
		static const int label_len = 6;
		const int print_width = (width_max * label_len) / width;
		const int print_indent = (print_width - label_len) / 2;
		for (int breath = 0; breath < width; ++breath)
		{
			const data_t* node = heap.ref_top();
			int breath_tmp = breath;
			for (int depth_tmp = depth - 1; node; --depth_tmp)
			{
				if (depth_tmp < 0)
					break;
				node = heap.ref_child(node, (breath_tmp & (0x1 << depth_tmp)) != 0x0);
			}
			if (node)
			{
				{
					int c = 0;
					for (; c < print_indent / 2; ++c)
						printf_detail(" ");
					if (heap.ref_child_l(node) && c < print_indent)
					{
						printf_detail(".");
						++c;
					}
					for (; c < print_indent; ++c)
						printf_detail(heap.ref_child_l(node) ? "-" : " ");
				}
				printf_detail("%s%1d:%2d%s", heap.ref_child_l(node) ? "{" : "[", node->m_priority, node->m_val, heap.ref_child_r(node) ? "}" : "]");
				{
					int c = 0;
					for (; c < print_indent / 2; ++c)
						printf_detail(heap.ref_child_r(node) ? "-" : " ");
					if (heap.ref_child_r(node) && c < print_indent)
					{
						printf_detail(".");
						++c;
					}
					for (; c < print_indent; ++c)
						printf_detail(" ");
				}
			}
			else
			{
				for (int c = 0; c < print_width; ++c)
					printf_detail(" ");
			}
		}
		printf_detail("\n");
	}
};

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//プライオリティキューコンテナ生成
	typedef priority_queue::container_adapter<ope_t, TEST_DATA_MAX> pqueue_t;
	pqueue_t* con = new pqueue_t();

	//処理時間計測開始
	const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point prev_time = begin_time;

	//--------------------
	//プライオリティキューのテスト
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container_adapter(Priority Queue)]\n");

	//エンキュー
	auto enqueue = [&con]()
	{
		printf("\n");
		printf("--- Enqueue ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj = con->enqueue(NORMAL, 0);
			printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			#define USE_ENQUEUE_TYPE 2
			//【エンキュー方法①】オブジェクトを受け渡す方法
			//※オブジェクトのコピーが発生するので少し遅い。
			#if USE_ENQUEUE_TYPE == 1
			{
				data_t new_obj(priority, val);
				data_t* obj = con->enqueueCopying(new_obj);
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//【推奨】【エンキュー方法②】コンストラクタパラメータを渡して登録する方法
			//※オブジェクトのコピーは発生しない。
			//※コンストラクタが呼び出される。
			#elif USE_ENQUEUE_TYPE == 2
			{
				data_t* obj = con->enqueue(priority, val);//優先度とコンストラクタパラメータを渡して登録
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//【エンキュー方法③】新規キュー（オブジェクト）の参照を受け取って値をセットする方法
			//※オブジェクトのコピーは発生しない。
			//※最初にコンストラクタが呼び出される。
			//※明示的に終了処理を呼び出し、ロックを解放しなければならない点に注意。
			//　（エンキュー／デキュー操作用クラスを使用することで、処理ブロックを抜ける時に自動敵にロックが解放される）
			//※エンキュー終了時にはポインタが変わる点にも注意。
			#elif USE_ENQUEUE_TYPE == 3
			{
				priority_queue::operation_guard<pqueue_t> ope(*con);//エンキュー／デキュー操作用クラス
				data_t* obj = ope.enqueueBegin(priority);//この時点で優先度とシーケンス番号がセットされ、ロックが取得される
				                                         //※戻り値は、処理ブロック内でしか（enqueueEnd/enqueueCancel呼び出しまでしか）有効ではないポインタなので注意
				obj->m_val = val;
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
				//処理ブロックを抜ける時に自動的にデキューが終了し、ロックが解放される。
				//※受け取ったポインタを処理ブロックの外で参照すると、誤った情報を参照することになるので注意。
				//※明示的にエンキュー終了／取り消しを実行することも可能。
				//obj = ope.enqueueEnd();//明示的なエンキュー終了を行うと、正しいオブジェクトの参照を取得できる
				//ope.enqueueCancel();
			}
			#endif//USE_ENQUEUE_TYPE
		}
	};
	enqueue();

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
	prev_time = printElapsedTime(prev_time, true);

#if 0
	//範囲に基づくforループテスト
	auto printNodesTest1 = [&con]()
	{
		printf("\n");
		printf("--- Test for C++11 for(:) ---\n");
		typedef pqueue_t::container_type container_t;
		container_t& heap = *con;
		for (const data_t& o : heap)
			printf("[%1d:%2d] ", o.m_priority, o.m_val);
		printf("\n");
	};
	printNodesTest1();
#endif

#if 0
	//std::for_eachテスト
	auto printNodesTest2 = [&con]()
	{
		printf("\n");
		printf("--- Test for std::for_each() ---\n");
		typedef pqueue_t::container_type container_t;
		container_t& heap = *con;
		printf("iterator:         ");
		std::for_each(heap.begin(), heap.end(), [](data_t& o)
			{
				printf("[%1d:%2d] ", o.m_priority, o.m_val);
			}
		);
		printf("\n");
		printf("reverse_iterator: ");
		std::for_each(heap.rbegin(), heap.rend(), [](data_t& o)
			{
				printf("[%1d:%2d] ", o.m_priority, o.m_val);
			}
		);
		printf("\n");
	};
	printNodesTest2();
#endif

#if 0//イテレータとロック取得のテスト
	{
		printf("\n");
		typedef pqueue_t::container_type container_t;
		container_t& heap = *con;
		lock_guard<container_t::lock_type> lock(heap);
		container_t::iterator ite = heap.begin();
		container_t::reverse_iterator rite = heap.rbegin();
		container_t::iterator ite_end = heap.end();
		container_t::reverse_iterator rite_end = heap.rend();
		container_t::iterator ite2 = heap.rbegin();
		container_t::reverse_iterator rite2 = heap.begin();
		container_t::iterator ite2_end = heap.rend();
		container_t::reverse_iterator rite2_end = heap.end();
		printf("constructor\n");
		if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
		if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
		if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
		if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
		if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
		if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
		if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
		if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
		printf("copy operator\n");
		ite = heap.begin();
		rite = heap.rbegin();
		ite_end = heap.end();
		rite_end = heap.rend();
		ite2 = heap.rbegin();
		rite2 = heap.begin();
		ite2_end = heap.rend();
		rite2_end = heap.end();
		if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
		if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
		if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
		if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
		if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
		if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
		if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
		if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
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
			if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
			if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
			if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
			if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
			if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
			if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
			if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
			if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
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
		if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
		if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
		if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
		if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
		if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
		if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
		if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
		if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
		printf("-= 3\n");
		ite -= 3;
		rite -= 3;
		ite_end -= 3;
		rite_end -= 3;
		ite2 -= 3;
		rite2 -= 3;
		ite2_end -= 3;
		rite2_end -= 3;
		if (ite.isExist()) printf("ite:[%d] priority=%d, seqNo=%d, value=%d\n", ite.getIndex(), ite->m_priority, ite->m_seqNo, ite->m_val);
		if (rite.isExist()) printf("rite:[%d] priority=%d, seqNo=%d, value=%d\n", rite.getIndex(), rite->m_priority, rite->m_seqNo, rite->m_val);
		if (ite_end.isExist()) printf("ite_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite_end.getIndex(), ite_end->m_priority, ite_end->m_seqNo, ite_end->m_val);
		if (rite_end.isExist()) printf("rite_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite_end.getIndex(), rite_end->m_priority, rite_end->m_seqNo, rite_end->m_val);
		if (ite2.isExist()) printf("ite2:[%d] priority=%d, seqNo=%d, value=%d\n", ite2.getIndex(), ite2->m_priority, ite2->m_seqNo, ite2->m_val);
		if (rite2.isExist()) printf("rite2:[%d] priority=%d, seqNo=%d, value=%d\n", rite2.getIndex(), rite2->m_priority, rite2->m_seqNo, rite2->m_val);
		if (ite2_end.isExist()) printf("ite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", ite2_end.getIndex(), ite2_end->m_priority, ite2_end->m_seqNo, ite2_end->m_val);
		if (rite2_end.isExist()) printf("rite2_end:[%d] priority=%d, seqNo=%d, value=%d\n", rite2_end.getIndex(), rite2_end->m_priority, rite2_end->m_seqNo, rite2_end->m_val);
	}
#endif

	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	//デキュー
	auto dequeue = [&con](const int pop_limit)
	{
		printf("\n");
		printf("--- Dequeue ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			#define USE_DEQUEUE_TYPE 1
			//【推奨】【デキュー方法①】情報取得用のオブジェクトを受け渡す
			//※オブジェクトのコピーが発生する。
			//※デストラクタが呼び出される。（コピー後に実行）
			#if USE_DEQUEUE_TYPE == 1
			{
				data_t node;
				const bool result = con->dequeueCopying(node);
				if (!result)
					break;
				printf_detail("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//【デキュー方法②】キュー（オブジェクト）の参照を受け取る方法
			//※オブジェクトのコピーは発生しない。
			//※明示的に終了処理を呼び出し、ロックを解放しなければならない点に注意。
			//　（エンキュー／デキュー操作用クラスを使用することで、処理ブロックを抜ける時に自動敵にロックが解放される）
			//※最後にデストラクタが呼び出される。
			#elif USE_DEQUEUE_TYPE == 2
			{
				priority_queue::operation_guard<pqueue_t> ope(*con);//エンキュー／デキュー操作用クラス
				data_t* obj = ope.dequeueBegin();//この時点でロックが取得される
				                                 //※戻り値は、処理ブロック内でしか（dequeueEnd/dequeueCancel呼び出しまでしか）有効ではないポインタなので注意
				if (!obj)
					break;
				printf_detail("[%1d:%2d] ", obj->m_priority, obj->m_val);
				//処理ブロックを抜ける時に自動的にデキューが終了し、ロックが解放される。
				//※受け取ったポインタを処理ブロックの外で参照すると、誤った情報を参照することになるので注意。
				//※明示的にデキュー終了／取り消しを実行することも可能。
				//ope.dequeueEnd();
				//ope.dequeueCancel();
			}
			#endif//USE_DEQUEUE_TYPE
		}
		printf_detail("\n");
	};
	dequeue(3);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示

	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	//先頭（根）ノードの優先度を変更
	auto changePriorityOnTop = [&con](const PRIORITY new_priority)
	{
		printf("\n");
		printf("--- Change Priority ---\n");
		const data_t* node = con->top();//先頭ノードを取得（ポップされない）
		printf("[%1d:%2d(seq=%d)]", node->m_priority, node->m_val, node->m_seqNo);
		node = con->changePriorityOnTop(new_priority);//優先度を変更（変更後、キューが再配置される）
		printf(" -> [%1d:%2d(seq=%d)]\n", node->m_priority, node->m_val, node->m_seqNo);
	};
	changePriorityOnTop(HIGHEST);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	changePriorityOnTop(LOWER);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	changePriorityOnTop(HIGHER);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示
	
	//デキュー
	dequeue(TEST_DATA_REG_NUM / 2);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	//デキュー
	dequeue(TEST_DATA_REG_NUM);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	//--------------------
	//【挙動比較用】二分ヒープのテスト
	//※プライオリティキューと異なり、ポップ時に、プッシュ時（エンキュー時）の順序性が保証されていないことが確認できる
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for binary_heap::container(Binary Heap)]\n");

	//ヒープコンテナ生成
	typedef binary_heap::container<heap_ope_t, TEST_DATA_MAX> heap_t;
	heap_t* heap = new heap_t();

	//二分ヒープでノードをプッシュ
	auto pushNodesBinHeap = [&heap]()
	{
		printf("\n");
		printf("--- Push nodes(Binary Heap) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj =heap->push(NORMAL, 0);
			printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			//※上記プライオリティキューで説明した、３種類のプッシュ方法が使える
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			#define USE_PUSH_TYPE 2
			//【プッシュ方法①】
			#if USE_PUSH_TYPE == 1
			{
				data_t new_obj(priority, val);
				data_t* obj = heap->pushCopying(new_obj);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//【推奨】【プッシュ方法②】
			#elif USE_PUSH_TYPE == 2
			{
				data_t* obj = heap->push(priority, val);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//【プッシュ方法③】
			#elif USE_PUSH_TYPE == 3
			{
				binary_heap::operation_guard<container_type> ope(*heap);
				data_t* obj = ope.pushBegin(priority, val);//※戻り値は、処理ブロック内でしか（pushEnd/pushCancel呼び出しまでしか）有効ではないポインタなので注意
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
				//obj = ope.popEnd();//明示的なポップ終了を行うと、正しいオブジェクトの参照を取得できる
			}
			#endif//USE_PUSH_TYPE
		}
	};
	pushNodesBinHeap();
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示

	//木を表示
	showTree(*heap);
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示
	
	//二分ヒープでノードをポップ
	auto popNodesBinHeap  = [&heap](const int pop_limit)
	{
		printf("\n");
		printf("--- Pop nodes(Binary Heap) ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			//※上記プライオリティキューで説明した、２種類のポップ方法が使える
			#define USE_POP_TYPE 1
			//【推奨】【ポップ方法①】
			#if USE_POP_TYPE == 1
			{
				data_t node;
				const bool result = heap->popCopying(node);
				if (!result)
					break;
				printf_detail("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//【ポップ方法②】
			#elif USE_POP_TYPE == 2
			{
				binary_heap::operation_guard<heap_t> ope(*heap);
				data_t* obj = ope.popBegin();//※戻り値は、処理ブロック内でしか（popEnd/popCancel呼び出しまでしか）有効ではないポインタなので注意
				if (!obj)
					break;
				printf_detail("[%1d:%2d] ", obj->m_priority, obj->m_val);
			}
			#endif//USE_POP_TYPE
		}
		printf_detail("\n");
	};
	popNodesBinHeap(TEST_DATA_REG_NUM / 2);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示

	//木を表示
	showTree(*heap);
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	//ノードをポップ
	popNodesBinHeap(TEST_DATA_REG_NUM);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示

	//木を表示
	showTree(*heap);
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	//インスタンスを破棄
	delete heap;
	heap = nullptr;

	//--------------------
	//【挙動比較用】STLのstd::priority_queueテスト
	//※プライオリティキューと異なり、ポップ時に、プッシュ時（エンキュー時）の順序性が保証されていないことが確認できる
	//※STLと二分ヒープの挙動（ポップ順序）が全く同じことを確認できる
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for std::priority_queue(STL)]\n");
	
	//優先度付きキューコンテナ生成
	typedef std::priority_queue<data_t, std::vector<data_t>, heap_ope_t> stl_container_type;
	//typedef std::priority_queue<data_t, std::vector<data_t>, ope_t> stl_container_type;
	stl_container_type* stl_heap = new stl_container_type();

	//STLでノードをプッシュ
	auto pushNodesSTL = [&stl_heap]()
	{
		printf("\n");
		printf("--- Push nodes(STL) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t obj(NORMAL, 0);
			stl_heap->push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			data_t obj(priority, val);
			stl_heap->push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
	};
	pushNodesSTL();
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示

	//STLでノードをポップ
	auto popNodesSTL = [&stl_heap](const int pop_limit)
	{
		printf("\n");
		printf("--- Pop nodes(STL) ---\n");
		for (int i = 0; i < pop_limit && !stl_heap->empty(); ++i)
		{
			data_t node = stl_heap->top();
			printf_detail("[%1d:%2d] ", node.m_priority, node.m_val);
			stl_heap->pop();
		}
		printf_detail("\n");
	};
	popNodesSTL(TEST_DATA_REG_NUM / 2);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	popNodesSTL(TEST_DATA_REG_NUM);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示

	//インスタンスを破棄
	delete stl_heap;
	stl_heap = nullptr;

	//--------------------
	//【挙動比較用】プライオリティキューの再テスト
	//※上記の二分ヒープ／STLのテストと同一の流れのテストを実施
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container_adapter(Priority Queue)] *Second time\n");

	//エンキュー
	enqueue();
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示
	
	//デキュー
	dequeue(TEST_DATA_REG_NUM / 2);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示
	
	//デキュー
	dequeue(TEST_DATA_REG_NUM);
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示
	
	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	//--------------------
	//プライオリティキューのクリアのテスト
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container_adapter(Priority Queue)] *Clear\n");
		
	//エンキュー
	enqueue();
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示

	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	printf("\n");
	printf("--- Clear ---\n");
	
	//クリア
	con->clear();
	printf("OK\n");
	prev_time = printElapsedTime(prev_time, true);//経過時間を表示

	//木を表示
	showTree(con->getContainer());
	prev_time = printElapsedTime(prev_time, false);//経過時間を表示

	//インスタンスを破棄
	delete con;
	con = nullptr;

	//--------------------
	//ポインタ変数をキューイングする場合のテスト
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for priority_queue::container_adapter(Priority Queue)] *Pointer\n");
		printf("\n");

		//操作型
		struct p_ope_t : public priority_queue::base_ope_t<p_ope_t, data_t*, PRIORITY, int>
		{
			inline static priority_type getPriority(const node_type& node){ return node->m_priority; }
			inline static void setPriority(node_type& node, const priority_type priority){ node->m_priority = priority; }
			inline static seq_type getSeqNo(const node_type& node){ return node->m_seqNo; }
			inline static void setSeqNo(node_type& node, const seq_type seq_no){ node->m_seqNo = seq_no; }

			//ロック型
			//※デフォルト（dummy_lock）のままとする
			//typedef spin_lock lock_type;//ロックオブジェクト型
		};
		
		//プライオリティキュー
		priority_queue::container_adapter<p_ope_t, 100> p_con;
		
		//エンキュー
		data_t obj1(NORMAL, 1);
		data_t obj2(HIGHER, 2);
		data_t obj3(LOWER, 3);
		data_t obj4(HIGHEST, 4);
		data_t obj5(LOWEST, 5);
		p_con.enqueueCopying(&obj1);
		p_con.enqueueCopying(&obj2);
		p_con.enqueueCopying(&obj3);
		p_con.enqueueCopying(&obj4);
		p_con.enqueueCopying(&obj5);

		//デキュー
		auto dequeuObj = [&p_con]()
		{
			data_t* obj_p = nullptr;
			p_con.dequeueCopying(obj_p);
			printf_detail("pop: [%1d:%2d](seq=%d)\n", obj_p->m_priority, obj_p->m_val, obj_p->m_seqNo);
		};
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
	}

	//終了
	printf("\n");
	printf("--- end ---\n");
	printElapsedTime(begin_time, true);//経過時間を表示

	return EXIT_SUCCESS;
}

// End of file
