//--------------------------------------------------------------------------------
//二分ヒープテスト用設定とコンパイラスイッチ
static const int TEST_DATA_PRIOR_MIN = 1;//テストデータの最小プライオリティ
static const int TEST_DATA_PRIOR_MAX = 5;//テストデータの最大プライオリティ
static const int TEST_DATA_MAX = 128;//テストデータの最大登録可能数
static const int TEST_DATA_REG_NUM = 60;//テストデータの登録数

#define PRINT_TEST_DATA_DETAIL//テストデーの詳細タを表示する場合は、このマクロを有効化する
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
//・コンテナには対応するが、イテレータには対応しない。
//　ただし、配列のポインタをそのまま返すだけの begin(), end() 関数は実装する。
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

#include <cstddef>//std::size_t用

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
		typedef typename ope_type::lock_type lock_type;
	//----------------------------------------
	//二分ヒープコンテナ
	//※固定配列と使用中の要素数を持つ
	//※std::priority_queueとはあまり互換性がなく、イテレータにも対応しない
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//定数
		static const std::size_t TABLE_SIZE = _TABLE_SIZE;//配列要素数
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
		inline std::size_t max_size() const { return TABLE_SIZE; }//最大要素数を取得
		inline std::size_t capacity() const { return TABLE_SIZE; }//最大要素数を取得
		inline std::size_t size() const { return m_used; }//使用中の要素数を取得
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
		inline const node_type* begin() const { return m_used == 0 ? nullptr : _ref_top(); }//開始ノード
		inline const node_type* end() const { return m_used == 0 ? nullptr : _ref_new(); }//終了ノード
		inline node_type* ref_node(const int index){ return  const_cast<node_type*>(const_cast<const container*>(this)->ref_node()); }//ノード参照
		inline node_type* ref_top(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_top()); }//先頭ノード参照
		inline node_type* ref_bottom(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_bottom()); }//終端ノード参照
		inline node_type* ref_new(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_new()); }//新規ノード参照
		inline node_type* begin(){ return const_cast<node_type*>(const_cast<const container*>(this)->begin()); }//開始ノード
		inline node_type* end(){ return const_cast<node_type*>(const_cast<const container*>(this)->end()); }//終了ノード
	private:
		inline int _adj_index(const int index) const { return index >= 0 && index < TABLE_SIZE ? index : -1; }//インデックスを範囲内に補正
		inline int _ref_index(const node_type* node) const{ return node - _ref_top(); }//ノードをインデックスに変換 ※範囲チェックなし
		inline int _calc_parent(const int index) const { return (index - 1) >> 1; }//親インデックス計算 ※範囲チェックなし
		inline int _calc_child_l(const int index) const { return (index << 1) + 1; }//左側の子インデックス計算 ※範囲チェックなし
		inline int _calc_child_r(const int index) const { return _calc_child_l(index) + 1; }//右側の子インデックス計算 ※範囲チェックなし
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
		inline bool less(const node_type& lhs, const node_type& rhs) const { return ope_type::less(lhs, rhs); }//キー比較
	private:
		//プッシュ（本体）
		node_type* _pushCopying(const node_type& src)
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
	public:
		//プッシュ
		//※オブジェクト渡し
		//※オブジェクトのコピーが発生する点に注意（少し遅くなる）
		//※ムーブオペレータを使用してコピーする点に注意
		//※処理中、ロックを取得する
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
			*top_obj = *obj;
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
			int index = ref_index(obj);
			if (index < 0)
				return nullptr;
			while (index != 0)
			{
				index = _calc_parent(index);
				node_type* parent = _ref_node(index);
				if (less(*parent, *obj))
				{
					swapValues(*parent, *obj);
					obj = parent;
				}
				else
					break;
			}
			return obj;
		}
		//ノードを下方に移動
		//※ロックを取得しないで処理するので注意！
		//　（局所的なロックで済む処理ではないため）
		//　必ず呼び出し元でロックを取得すること！
		node_type* downHeap(node_type* obj)
		{
			int index = ref_index(obj);
			if (index < 0)
				return nullptr;
			while (true)
			{
				index = _calc_child_l(index);
				if (index >= m_used)
					break;
				node_type* child = _ref_node(index);
				node_type* child_r = index + 1 < m_used ? child + 1 : nullptr;
				bool is_swap = false;
				if (child_r && !less(*child_r, *child) && !less(*child_r, *obj))
				{
					is_swap = true;
					child = child_r;
					++index;
				}
				else if (!less(*child, *obj))
				{
					is_swap = true;
				}
				if (is_swap)
					swapValues(*child, *obj);
				else
					break;
				obj = child;
			}
			return obj;
		}
	private:
		//クリア（本体）
		void _clear()
		{
			node_type* obj_end = end();
			for (node_type* obj = begin(); obj < obj_end; ++obj)
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
		//※キー比較処理を渡す
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
		int m_used;//使用数
		status_t m_status;//ステータス
		mutable lock_type m_lock;//ロックオブジェクト
	};
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
	//		inline static priority_type getPrior(const node_type& node){ return node.m_priority; }
	//		//優先度を更新
	//		inline static void setPrior(node_type& node, const priority_type priority){ node.m_priority = priority; }
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
			return _lessSeqNo(ope_type::comparePriority(ope_type::getPrior(lhs), ope_type::getPrior(rhs)), ope_type::getSeqNo(lhs), ope_type::getSeqNo(rhs));
		}

		//STLのstd::priority_queueと共用するための関数オブジェクト
		inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return ope_type::less(lhs, rhs); }

		//デストラクタ呼び出し
		static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef ope_type pqueue_ope_type; \
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
	//プライオリティキューコンテナ
	//※内部に二分ヒープを持つ
	//※std::priority_queueとはあまり互換性がなく、イテレータにも対応しない
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
		struct heap_ope_t : public binary_heap::base_ope_t<heap_ope_t, node_type>//二分ヒープ操作型
		{
			//キーを比較
			//※lhsの方が小さいければ true を返す
			inline static bool less(const node_type& lhs, const node_type& rhs)
			{
				return pqueue_ope_type::less(lhs, rhs);
			}

			//ロック型
			//※ロック型はデフォルトのままとし、二分ヒープ側ではロック制御を行わない
			//typedef dummy_lock lock_type;//ロックオブジェクト型
		};
		typedef binary_heap::container<heap_ope_t, _TABLE_SIZE> heap_type;//二分ヒープ型
		typedef typename heap_type::status_t status_t;//ステータス型
	public:
		//アクセッサ
		inline const heap_type& getHeap() const { return m_heap; }//二分ヒープ取得
		inline heap_type& getHeap(){ return m_heap; }//二分ヒープ取得
	public:
		//キャストオペレータ
		inline operator const heap_type() const{ return m_heap; }//二分ヒープを返す
		inline operator heap_type(){ return m_heap; }//二分ヒープを返す
		inline operator lock_type&(){ return m_lock; }//共有ロックオブジェクト
		inline operator lock_type&() const { return m_lock; }//共有ロックオブジェクト ※mutable
	public:
		//メソッド
		inline std::size_t max_size() const { return m_heap.max_aize(); }//最大要素数を取得
		inline std::size_t capacity() const { return m_heap.capacity(); }//最大要素数を取得
		inline std::size_t size() const { return m_heap.size(); }//使用中の要素数を取得
		inline bool empty() const { return m_heap.empty(); }//空か？
	public:
		inline const node_type* begin() const { return m_heap.begin(); }//開始ノード
		inline const node_type* end() const { return m_heap.end(); }//終了ノード
		inline node_type* begin(){ return m_heap.begin(); }//開始ノード
		inline node_type* end(){ return m_heap.end(); }//終了ノード
	private:
		//シーケンス番号発行
		inline seq_type getNextSeqNo(){ return m_seqNo++; }
		//可能ならシーケンス番号をリセット
		inline void checkAndResetSeqNo()
		{
			if (m_heap.empty())
				m_seqNo = 0;
		}
	private:
		//エンキュー（本体）
		node_type* _enqueueCopying(const node_type& obj)
		{
			if (m_heap.status() == status_t::PUSH_BEGINNING || m_heap.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type obj_tmp(std::move(obj));
			ope_type::setSeqNo(obj_tmp, getNextSeqNo());//シーケンス番号をセット
			return m_heap.pushCopying(obj_tmp);//二分ヒープにプッシュ
		}
	public:
		//エンキュー
		//※オブジェクト渡し
		//※オブジェクトには、あらかじめ優先度を設定しておく必要がある
		//※オブジェクトのコピーが２回発生する点に注意（少し遅くなる）
		//　（シーケンス番号をセットするために1回テンポラリにコピーし、プッシュ時にさらにコピーする。）
		//※ムーブコンストラクタとムーブオペレータを使用してコピーする点に注意
		//※処理中、ロックを取得する
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
			//if (m_heap.status() == status_t::PUSH_BEGINNING || m_heap.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_heap.pushBegin(args...);//二分ヒープにプッシュ開始
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//優先度を設定
			ope_type::setSeqNo(*obj, getNextSeqNo());//シーケンス番号をセット
			obj = m_heap.pushEnd();//二分ヒープにプッシュ終了
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
			//if (m_heap.status() == status_t::PUSH_BEGINNING || m_heap.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_heap.pushBegin(args...);//二分ヒープにプッシュ開始
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//優先度を設定
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
			return m_heap.pushEnd();//二分ヒープにプッシュ終了
		}
	public:
		//エンキュー終了
		//※enqueueBeginで取得したロックを解放する
		inline node_type* enqueueEnd()
		{
			const bool unlock = (m_heap.status() == status_t::PUSH_BEGINNING);//プッシュ開始中ならアンロックする
			node_type* new_obj = _enqueueEnd();//エンキュー終了
			if (unlock)
				m_lock.unlock();//ロック解放
			return new_obj;
		}
	private:
		//エンキュー取り消し（本体）
		inline bool _enqueueCancel()
		{
			//if (m_heap.status() != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
			//	return;
			return m_heap.pushCancel();//プッシュ取り消し
		}
	public:
		//エンキュー取り消し
		//※enqueueBeginで取得したロックを解放する
		inline bool enqueueCancel()
		{
			const bool unlock = (m_heap.status() == status_t::PUSH_BEGINNING);//プッシュ開始中ならアンロックする
			const bool result = m_heap.pushCancel();//プッシュ取り消し
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	private:
		//デキュー（本体）
		bool _dequeueCopying(node_type& dst)
		{
			//if (m_heap.status() == status_t::PUSH_BEGINNING || m_heap.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			const bool result = m_heap.popCopying(dst);//二分ヒープからポップ
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
			//if (m_heap.status() == status_t::PUSH_BEGINNING || m_heap.status() == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_heap.popBegin();//二分ヒープからポップ開始
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
			//if (m_heap.status() != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
			//	return false;
			const bool result = m_heap.popEnd();//二分ヒープからポップ終了
			checkAndResetSeqNo();//キューが空になったらシーケンス番号をリセットする
			return result;
		}
	public:
		//デキュー終了
		//※オブジェクトのデストラクタが呼び出される
		//※dequeueBeginで取得したロックを解放する
		inline bool dequeueEnd()
		{
			const bool unlock = (m_heap.status() == status_t::POP_BEGINNING);//ポップ開始中ならアンロックする
			const bool result = _dequeueEnd();//デキュー終了
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	private:
		//デキュー取り消し（本体）
		bool _dequeueCancel()
		{
			//if (m_heap.status() != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
			//	return false;
			return m_heap.popCancel();//ポップ取り消し
		}
	public:
		//デキュー取り消し
		//※dequeueBeginで取得したロックを解放する
		inline bool dequeueCancel()
		{
			const bool unlock = (m_heap.status() == status_t::POP_BEGINNING);//ポップ開始中ならアンロックする
			const bool result = _dequeueCancel();//デキュー取り消し
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
		//先頭（根）キューを参照
		//※デキューしない
		inline const node_type* top() const
		{
			return m_heap.ref_top();//二分ヒープの先頭（根）ノードを取得
		}
	private:
		//先頭（根）キューのプライオリティ変更（本体）
		node_type* _changePriorityOnTop(const priority_type priority)
		{
			node_type* obj = m_heap.ref_top();
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//優先度を更新
			ope_type::setSeqNo(*obj, getNextSeqNo());//シーケンス番号を更新
			return m_heap.downHeap(obj);//ダウンヒープ
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
	private:
		//クリア（本体）
		inline void _clear()
		{
			m_heap.clear();
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
		//※キー比較処理を渡す
		container() :
			m_heap(),
			m_seqNo(0),
			m_lock()
		{}
		//デストラクタ
		~container()
		{
			enqueueCancel();//エンキュー取り消し
			dequeueCancel();//デキュー取り消し
		}
	private:
		//フィールド
		heap_type m_heap;//二分ヒープ
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
		typedef CON container_type;//コンテナ型
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
			node_type* node = m_container.enqueueBegin(priority, args...);//エンキュー開始
			if (node)
				m_status = status_t::PUSH_BEGINNING;//ステータス変更
			return node;
		}
		//エンキュー終了
		node_type* enqueueEnd()
		{
			if (m_status != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			node_type* node = m_container.enqueueEnd();//エンキュー終了
			m_status = status_t::PUSH_ENDED;//ステータス変更
			return node;
		}
		//エンキュー取り消し
		bool enqueueCancel()
		{
			if (m_status != status_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			m_container.enqueueCancel();//エンキュー取り消し
			m_status = status_t::PUSH_CANCELLED;//ステータス変更
			return true;
		}
		//デキュー開始
		node_type* dequeueBegin()
		{
			if (m_status == status_t::PUSH_BEGINNING || m_status == status_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_container.dequeueBegin();//デキュー開始
			if (node)
				m_status = status_t::POP_BEGINNING;//ステータス変更
			return node;
		}
		//デキュー終了
		bool dequeueEnd()
		{
			if (m_status != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			const bool result = m_container.dequeueEnd();//デキュー終了
			m_status = status_t::POP_ENDED;//ステータス変更
			return result;
		}
		//デキュー取り消し
		bool dequeueCancel()
		{
			if (m_status != status_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			m_container.dequeueCancel();//デキュー取り消し
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
			enqueueEnd();//エンキュー終了
			dequeueEnd();//デキュー終了
		}
	private:
		//フィールド
		container_type& m_container;//コンテナ
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
	int m_seqNo;//シーケンス番号
	int m_val;//データ

	//コンストラクタ
	data_t(const PRIORITY priority, const int val) :
		m_priority(priority),
		m_seqNo(0),
		m_val(val)
	{
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
struct pqueue_ope_t : public priority_queue::base_ope_t<pqueue_ope_t, data_t, PRIORITY, int>
{
	//優先度を取得
	inline static priority_type getPrior(const node_type& node){ return node.m_priority; }
	//優先度を更新
	inline static void setPrior(node_type& node, const priority_type priority){ node.m_priority = priority; }
	
	//シーケンス番号を取得
	inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//シーケンス番号を更新
	inline static void setSeqNo(node_type& node, const seq_type seq_no){ node.m_seqNo = seq_no; }

	//ロック型
	//※デフォルト（dummy_lock）のままとする
	//typedef spin_lock lock_type;//ロックオブジェクト型
};

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
//木を表示
template<class HEAP>
void showTree(const HEAP& heap)
{
	printf("--- Show tree (count=%d) ---\n", heap.size());
	//static const int depth_limit = 5;//最大でも5段階目までを表示（0段階目から数えるので最大で6段階表示される→最大：1+2+4+8+16+32=63個）
	static const int depth_limit = 4;//最大でも4段階目までを表示（0段階目から数えるので最大で5段階表示される→最大：1+2+4+8+16=31個）
	const int _depth_max = heap.depth_max();
	printf("depth_max=%d (limit for showing=%d)\n", _depth_max, depth_limit);
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
						printf(" ");
					if (heap.ref_child_l(node) && c < print_indent)
					{
						printf(".");
						++c;
					}
					for (; c < print_indent; ++c)
						printf(heap.ref_child_l(node) ? "-" : " ");
				}
				printf("%s%1d:%2d%s", heap.ref_child_l(node) ? "{" : "[", node->m_priority, node->m_val, heap.ref_child_r(node) ? "}" : "]");
				{
					int c = 0;
					for (; c < print_indent / 2; ++c)
						printf(heap.ref_child_r(node) ? "-" : " ");
					if (heap.ref_child_r(node) && c < print_indent)
					{
						printf(".");
						++c;
					}
					for (; c < print_indent; ++c)
						printf(" ");
				}
			}
			else
			{
				for (int c = 0; c < print_width; ++c)
					printf(" ");
			}
		}
		printf("\n");
	}
};

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//プライオリティキューコンテナ生成
	typedef priority_queue::container<pqueue_ope_t, TEST_DATA_MAX> pqueue_type;
	pqueue_type con;

	//--------------------
	//プライオリティキューのテスト
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)]\n");
	printf("\n");

	//エンキュー
	auto enqueue = [&con]()
	{
		printf("--- Enqueue ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj = con.enqueue(NORMAL, 0);
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
				data_t* obj = con.enqueueCopying(new_obj);
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//【推奨】【エンキュー方法②】コンストラクタパラメータを渡して登録する方法
			//※オブジェクトのコピーは発生しない。
			//※コンストラクタが呼び出される。
			#elif USE_ENQUEUE_TYPE == 2
			{
				data_t* obj = con.enqueue(priority, val);//優先度とコンストラクタパラメータを渡して登録
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
				priority_queue::operation_guard<pqueue_type> ope(con);//エンキュー／デキュー操作用クラス
				data_t* obj = ope.enqueueBegin(priority);//この時点で優先度とシーケンス番号がセットされ、ロックが取得される
				                                         //※返り値は、処理ブロック内でしか（enqueueEnd/enqueueCancel呼び出しまでしか）有効ではないポインタなので注意
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
		printf_detail("\n");
	};
	enqueue();

#if 0
	//範囲に基づくforループテスト
	auto printNodesTest1 = [&con]()
	{
		printf("--- Test for C++11 for(:) ---\n");
		for (const data_t& o : con)
			printf("[%1d:%2d] ", o.m_priority, o.m_val);
		printf("\n");
	};
	printNodesTest1();
#endif

#if 0
	//std::for_eachテスト
	auto printNodesTest2 = [&con]()
	{
		printf("--- Test for std::for_each() ---\n");
		std::for_each(con.begin(), con.end(), [](data_t& o)
			{
				printf("[%1d:%2d] ", o.m_priority, o.m_val);
			}
		);
		printf("\n");
	};
	printNodesTest2();
#endif

	//木を表示
	showTree(con.getHeap());

	//デキュー
	auto dequeue = [&con](const int pop_limit)
	{
		printf("--- Dequeue ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			#define USE_DEQUEUE_TYPE 2
			//【デキュー方法①】情報取得用のオブジェクトを受け渡す
			//※オブジェクトのコピーが発生する。
			//※デストラクタが呼び出される。（コピー後に実行）
			#if USE_DEQUEUE_TYPE == 1
			{
				data_t node;
				const bool result = con.dequeueCopying(node);
				if (!result)
					break;
				printf("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//【推奨】【デキュー方法②】キュー（オブジェクト）の参照を受け取る方法
			//※オブジェクトのコピーは発生しない。
			//※明示的に終了処理を呼び出し、ロックを解放しなければならない点に注意。
			//　（エンキュー／デキュー操作用クラスを使用することで、処理ブロックを抜ける時に自動敵にロックが解放される）
			//※最後にデストラクタが呼び出される。
			#elif USE_DEQUEUE_TYPE == 2
			{
				priority_queue::operation_guard<pqueue_type> ope(con);//エンキュー／デキュー操作用クラス
				data_t* obj = ope.dequeueBegin();//この時点でロックが取得される
				                                 //※返り値は、処理ブロック内でしか（dequeueEnd/dequeueCancel呼び出しまでしか）有効ではないポインタなので注意
				if (!obj)
					break;
				printf("[%1d:%2d] ", obj->m_priority, obj->m_val);
				//処理ブロックを抜ける時に自動的にデキューが終了し、ロックが解放される。
				//※受け取ったポインタを処理ブロックの外で参照すると、誤った情報を参照することになるので注意。
				//※明示的にデキュー終了／取り消しを実行することも可能。
				//ope.dequeueEnd();
				//ope.dequeueCancel();
			}
			#endif//USE_DEQUEUE_TYPE
		}
		printf("\n");
	};
	dequeue(3);
	showTree(con.getHeap());//木を表示

	//先頭（根）ノードの優先度を変更
	auto changePriorityOnTop = [&con](const PRIORITY new_priority)
	{
		printf("--- Change Priority ---\n");
		const data_t* node = con.top();//先頭ノードを取得（ポップされない）
		printf("[%1d:%2d(seq=%d)]", node->m_priority, node->m_val, node->m_seqNo);
		node = con.changePriorityOnTop(new_priority);//優先度を変更（変更後、キューが再配置される）
		printf(" -> [%1d:%2d(seq=%d)]\n", node->m_priority, node->m_val, node->m_seqNo);
	};
	changePriorityOnTop(HIGHEST);
	changePriorityOnTop(LOWER);
	changePriorityOnTop(HIGHER);
	showTree(con.getHeap());//木を表示
	
	//デキュー
	dequeue(TEST_DATA_REG_NUM / 2);
	showTree(con.getHeap());//木を表示

	//デキュー
	dequeue(TEST_DATA_REG_NUM);
	showTree(con.getHeap());//木を表示

	//--------------------
	//【挙動比較用】二分ヒープのテスト
	//※プライオリティキューと異なり、ポップ時に、プッシュ時（エンキュー時）の順序性が保証されていないことが確認できる
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for binary_heap::container(Binary Heap)]\n");
	printf("\n");

	//ヒープコンテナ生成
	typedef binary_heap::container<heap_ope_t, TEST_DATA_MAX> heap_type;
	heap_type heap;

	//二分ヒープでノードをプッシュ
	auto pushNodesBinHeap = [&heap]()
	{
		printf("--- Push nodes(Binary Heap) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj =heap.push(NORMAL, 0);
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
				data_t* obj = heap.pushCopying(new_obj);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//【推奨】【プッシュ方法②】
			#elif USE_PUSH_TYPE == 2
			{
				data_t* obj = heap.push(priority, val);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//【プッシュ方法③】
			#elif USE_PUSH_TYPE == 3
			{
				binary_heap::operation_guard<heap_type> ope(heap);
				data_t* obj = ope.pushBegin(priority, val);//※返り値は、処理ブロック内でしか（pushEnd/pushCancel呼び出しまでしか）有効ではないポインタなので注意
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
				//obj = ope.popEnd();//明示的なポップ終了を行うと、正しいオブジェクトの参照を取得できる
			}
			#endif//USE_PUSH_TYPE
		}
		printf_detail("\n");
	};
	pushNodesBinHeap();

	//木を表示
	showTree(heap);
	
	//二分ヒープでノードをポップ
	auto popNodesBinHeap  = [&heap](const int pop_limit)
	{
		printf("--- Pop nodes(Binary Heap) ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			//※上記プライオリティキューで説明した、２種類のポップ方法が使える
			#define USE_POP_TYPE 2
			//【ポップ方法①】
			#if USE_POP_TYPE == 1
			{
				data_t node;
				const bool result = heap.popCopying(node);
				if (!result)
					break;
				printf("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//【推奨】【ポップ方法②】
			#elif USE_POP_TYPE == 2
			{
				binary_heap::operation_guard<heap_type> ope(heap);
				data_t* obj = ope.popBegin();//※返り値は、処理ブロック内でしか（popEnd/popCancel呼び出しまでしか）有効ではないポインタなので注意
				if (!obj)
					break;
				printf("[%1d:%2d] ", obj->m_priority, obj->m_val);
			}
			#endif//USE_POP_TYPE
		}
		printf("\n");
	};
	popNodesBinHeap(TEST_DATA_REG_NUM / 2);
	showTree(heap);//木を表示

	//ノードをポップ
	popNodesBinHeap(TEST_DATA_REG_NUM);
	showTree(heap);//木を表示

	//--------------------
	//【挙動比較用】STLのstd::priority_queueテスト
	//※プライオリティキューと異なり、ポップ時に、プッシュ時（エンキュー時）の順序性が保証されていないことが確認できる
	//※STLと二分ヒープの挙動（ポップ順序）が全く同じことを確認できる
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for std::priority_queue(STL)]\n");
	printf("\n");
	
	std::priority_queue<data_t, std::vector<data_t>, heap_ope_t> stl;
	//std::priority_queue<data_t, std::vector<data_t>, pqueue_ope_t> stl;

	//STLでノードをプッシュ
	auto pushNodesSTL = [&stl]()
	{
		printf("--- Push nodes(STL) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t obj(NORMAL, 0);
			stl.push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			data_t obj(priority, val);
			stl.push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
		printf_detail("\n");
	};
	pushNodesSTL();

	//STLでノードをポップ
	auto popNodesSTL = [&stl](const int pop_limit)
	{
		printf("--- Pop nodes(STL) ---\n");
		for (int i = 0; i < pop_limit && !stl.empty(); ++i)
		{
			data_t node = stl.top();
			printf("[%1d:%2d] ", node.m_priority, node.m_val);
			stl.pop();
		}
		printf("\n");
	};
	popNodesSTL(TEST_DATA_REG_NUM / 2);
	popNodesSTL(TEST_DATA_REG_NUM);

	//--------------------
	//【挙動比較用】プライオリティキューの再テスト
	//※上記の二分ヒープ／STLのテストと同一の流れのテストを実施
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)] *Second time\n");
	printf("\n");

	enqueue();//エンキュー
	showTree(con.getHeap());//木を表示
	dequeue(TEST_DATA_REG_NUM / 2);//デキュー
	showTree(con.getHeap());//木を表示
	dequeue(TEST_DATA_REG_NUM);//デキュー
	showTree(con.getHeap());//木を表示

	//--------------------
	//プライオリティキューのクリアのテスト
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)] *Clear\n");
	printf("\n");

	enqueue();//エンキュー
	showTree(con.getHeap());//木を表示
	printf("--- Clear ---\n");
	con.clear();//クリア
	printf("OK\n");
	showTree(con.getHeap());//木を表示

	//--------------------
	//ポインタ変数をキューイングする場合のテスト
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for priority_queue::container(Priority Queue)] *Pointer\n");
		
		//操作型
		struct p_ope_t : public priority_queue::base_ope_t<p_ope_t, data_t*, PRIORITY, int>
		{
			inline static priority_type getPrior(const node_type& node){ return node->m_priority; }
			inline static void setPrior(node_type& node, const priority_type priority){ node->m_priority = priority; }
			inline static seq_type getSeqNo(const node_type& node){ return node->m_seqNo; }
			inline static void setSeqNo(node_type& node, const seq_type seq_no){ node->m_seqNo = seq_no; }

			//ロック型
			//※デフォルト（dummy_lock）のままとする
			//typedef spin_lock lock_type;//ロックオブジェクト型
		};
		
		//プライオリティキュー
		priority_queue::container<p_ope_t, TEST_DATA_MAX> p_con;
		
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
			printf("pop: [%1d:%2d](seq=%d)\n", obj_p->m_priority, obj_p->m_val, obj_p->m_seqNo);
		};
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
	}

	return EXIT_SUCCESS;
}

// End of file
