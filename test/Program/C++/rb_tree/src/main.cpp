//--------------------------------------------------------------------------------
//【謝辞】
//このプログラムのアルゴリズムは、下記の個人サイトにて発表されております、
//サイト主様が開発されたアルゴリズムを参考にいたしました。
//    URL： http ://www.moon.sannet.ne.jp/okahisa/rb-tree/rb-tree.html
//    記事：「Red - Black Tree by Java -- これで分かった赤黒木」
//          トップページURL : http ://www.moon.sannet.ne.jp/okahisa/
//                           「OKおじさんのホームページ」
//とても分かり易く優れたアルゴリズムであり、問題なくプログラムを作成でき
//ましたことを感謝いたします。
//なお、ソースコードは引用しておりません。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//赤黒木テスト用設定とコンパイラスイッチ
static const int TEST_DATA_KEY_MIN = 1;//テストデータの最小キー
static const int TEST_DATA_KEY_MAX = 10;//テストデータの最大キー
static const int TEST_DATA_REG_NUM = 20;//テストデータの登録数
static const int TEST_DATA_STACK_DEPTH_MAX = 32;//テストデータの赤黒木操作用スタックの最大の深さ（デフォルトは32で、平衡木なら10万件は扱える）
//#define REGIST_TEST_DATA_SEQUENTIALLY//データをシーケンシャルに登録する場合は、このマクロを有効化する（無効化時はランダム）
#define PRINT_TEST_DATA_TREE//テストデータの木を表示する場合は、このマクロを有効化する（表示しなくても検索は実行する）
#define PRINT_TEST_DATA_SEARCH//テストデーたの検索結果を表示する場合は、このマクロを有効化する（表示しなくても検索は実行する）
#define PRINT_TEST_DATA_COLOR_COUNT//テストデータの赤黒カウント数計測を表示する場合は、このマクロを有効化する
#define PRINT_TEST_DATA_DETAIL//テストデータの詳細を表示する場合は、このマクロを有効化する
//#define ENABLE_CALC_COUNT_PERFORMANCE//データ件数カウントの処理時間を計測する場合は、このマクロを有効化する

//テストデータを固定順に登録する場合は、このマクロを有効化する（無効時はランダム、ただし、REGIST_TEST_DATA_SEQUENTIALLYが優先）
//#define TEST_DATA_REGISTRATION_LIST { 54, 59, 71, 84, 60, 85, 54, 84, 42, 62, 64, 38, 43, 29, 89, 5, 96, 27, 38, 47, 79, 81, 52, 47, 56, 39, 92, 83, 7, 33, 8, 64, 2, 36, 83, 95, 77, 14, 87, 87, 97, 47, 79, 80, 46, 52, 78, 67, 11, 72, 63, 58, 14, 53, 94, 75, 52, 10, 41, 47, 26, 18, 77, 73, 45, 21, 56, 13, 1, 32, 61, 14, 61, 22, 61, 38, 94, 90, 68, 44, 35, 61, 43, 90, 69, 9, 6, 96, 66, 65, 67, 17, 21, 35, 12, 75, 31, 60, 36, 32}

//テストデータを固定順に削除する場合は、このマクロを有効化する（無効時はランダム）
//#define TEST_DATA_REMOVING_LIST { 41, 72, 12, 14, 9, 39, 18, 38, 66, 53, 84, 31, 68, 52, 44, 87 }

//--------------------------------------------------------------------------------
//赤黒木アルゴリズム用コンパイラスイッチ
//#define DISABLE_COLOR_FOR_ADD//ノード追加時の色操作と回転処理を無効化する場合は、このマクロを有効化する
//#define DISABLE_COLOR_FOR_REMOVE//ノード削除時の色操作と回転処理を無効化する場合は、このマクロを有効化する
//#define DEBUG_PRINT_FOR_ADD//ノード追加時のデバッグ情報表示を有効化する場合は、このマクロを有効化する
//#define DEBUG_PRINT_FOR_REMOVE//ノード削除時のデバッグ情報表示を有効化する場合は、このマクロを有効化する

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
//赤黒木（red-black tree）
//--------------------------------------------------------------------------------
//データ構造とアルゴリズム
//【特徴】
//・二分探索木である。
//	  - ノードの左側の子には、キーの値が小さいノードを連結。
//	  - ノードの右側の子には、キーの値が大きいか等しいノードを連結。
//・平衡木である。
//	  - 常に左右の木のバランスを保つ。
//・以上の特徴により、探索・追加・削除の時間が、常にO(log n)に保たれる。
//【条件】
//・条件①：各ノードは「赤」か「黒」の「色」を持つ。
//・条件②：「根」（root）は必ず「黒」。
//・条件③：「赤」の子は必ず「黒」。
//	          - 対偶により、「赤」の親は必ず「黒」。
//	          - 「黒」の子は「赤」でも「黒」でも良い。
//・条件④：「根」から「葉」までの経路上にある「黒」の数は、
//　　　　　あらゆる経路で一定。
//            - 「葉」とは、末端のnullptrであるものとする。
//            - 「葉」（nullptr）の色は「黒」であるものとする。
//              つまり、「赤」の子がnullptrであっても良い。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【本プログラムにおける実装要件】
//・メモリ節約のために、親ノードへのリンクを持たないデータ構造とする。
//・代わりに、検索等の関数実行時に外部からスタックを渡す事で親を辿ることが可能。
//・テンプレートにより、アルゴリズムを汎用化。
//・キー重複（同キーのノードが複数ある状態）を許容するアルゴリズムとする。
//・リンクの方法に柔軟性を持たせ、かつ、virtualを必須としないように、
//　データ構造は自由とする。
//　（リンクの変数をポインタにしようがインデックスにしようが自由）
//・代わりに、データ操作専用のクラスをユーザー定義することで、
//　処理に汎用性を持たせる。
//・一切メモリ操作は行わず、ノードのオブジェクトを受け取って操作する
//　アルゴリズムのみを提供する。
//・std::mapを模したコンテナとイテレータを利用可能とする。
//・コンテナは、根ノードのみを保持し、一切メモリ操作しないものとする。
//・イテレータは、上述のスタック操作を隠ぺいする。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【具体的な活用の想定】※以下、メモリ管理処理に適用することを想定した要件。
//・メモリマネージャの管理情報の連結に使用することを想定。
//・空きメモリサイズ順の連結を行うため、キー重複を許容する必要がある。
//・また、連結リストが肥大化することを避けるため、親ノードへのリンク情報は
//　持たない。
//・必要量以上の空きメモリのノードを検索したのち、アラインメントを加味した
//　上で利用可能なノードかを確認し、一つずつ大きなノードを辿って最適な
//　ノードを探し出す。
//・ノード間のリンク情報は、64bitポインタ変数による肥大化が起こらないように、
//　メモリ空間の先頭からオフセットされた32bitの相対ポインタを扱う。
//・一つのメモリ管理情報を、2種類の木に振り分けて使用する。
//　削除済みメモリノードの二分探索木はサイズをキーにし、
//　使用中メモリノードの二分探索木はポインタをキーにする。
//・このような利用を可能とするために、データ構造とアルゴリズムを完全に
//　切り離した構成にする。
//--------------------------------------------------------------------------------

#include <memory.h>//memcpy用
#include <assert.h>//assert用
#include <cstddef>//srd::size_t用
#include <iterator>//std::iterator用
#include <utility>//std::move用

namespace rb_tree
{
	//--------------------
	//赤黒木ノード操作用基底テンプレートクラス
	//※下記のような派生クラス（CRTP）を定義して使用する
	//  //struct クラス名 : public rb_tree::base_ope_t<クラス名, ノード型, キー型, スタックの最大の深さ = 32>
	//	struct ope_t : public rb_tree::base_ope_t<ope_t, data_t, int>
	//	{
	//		//子ノードを取得
	//		inline static const node_type* getChildL(const node_type& node){ return ???; }//大（右）側
	//		inline static const node_type* getChildS(const node_type& node){ return ???; }//小（左）側
	//		//子ノードを変更
	//		inline static void setChildL(node_type& node, const node_type* child){ ??? = child; }//大（右）側
	//		inline static void setChildS(node_type& node, const node_type* child){ ??? = child; }//小（左）側
	//		
	//		//ノードの色を取得
	//		inline static color_t getColor(const node_type& node){ return ??? ? BLACK : RED; }
	//		//ノードの色を変更
	//		inline static void setColor(node_type& node, const color_t color){ ??? = color == BLACK; }
	//		
	//		//キーを取得
	//		inline static key_type getKey(const node_type& node){ return ???; }
	//		
	//		//キーを比較 ※必要に応じて定義
	//		inline static int compareKey(const key_type lhs, const key_type rhs){ return ???; }
	//		
	//		//ロック型 ※必要に応じて定義
	//		//※共有ロック（リード・ライトロック）でコンテナ操作をスレッドセーフにしたい場合は、
	//		//　有効な共有ロック型（shared_spin_lockなど）を lock_type 型として定義する。
	//		typedef shared_spin_lock lock_type;//ロックオブジェクト型
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, typename KEY_TYPE, int _STACK_DEPTH_MAX = 32>
	struct base_ope_t
	{
		//定数
		static const int STACK_DEPTH_MAX = _STACK_DEPTH_MAX;//スタックの最大の深さ
		enum color_t//色
		{
			RED = 0,//赤
			BLACK = 1,//黒
		};

		//型
		typedef OPE_TYPE ope_type;//ノード操作型
		typedef NODE_TYPE node_type;//ノード型
		typedef KEY_TYPE key_type;//キー型

		//ロック型
		typedef dummy_shared_lock lock_type;//ロックオブジェクト型
		//※デフォルトはダミーのため、一切ロック制御しない。
		//※共有ロック（リード・ライトロック）でコンテナ操作をスレッドセーフにしたい場合は、
		//　base_ope_tの派生クラスにて、有効な共有ロック型（shared_spin_lock など）を
		//　lock_type 型として再定義する。
		//【補足①】コンテナには、あらかじめロック制御のための仕組みがソースコードレベルで
		//　　　　　仕込んであるが、有効な型を与えない限りは、実行時のオーバーヘッドは一切ない。
		//【補足②】スレッドセーフ化した場合、書き込み時の排他ロックは行われるようになるが、
		//　　　　　読み込み時の共有ロックは行っていない。読み込み時のロックは局所的なロックで
		//　　　　　済まないため、ユーザーが任意に対応しなければならない。
		//　　　　　（例）
		//　　　　　    {
		//　　　　　        shared_lock_guard lock(container);//コンテナオブジェクトを渡して共有ロック
		//　　　　　                                          //※コンテナオブジェクトはロック
		//　　　　　                                          //　オブジェクト（lock_type）として振る舞える
		//　　　　　        //...
		//　　　　　        //一連のイテレータ操作など
		//　　　　　        //...
		//　　　　　    }//スコープを抜ける時に自動的にロック解放

		//子ノードを取得 ※const外し(remove_const)
		inline static node_type* getChildL_rc(node_type& node){ return const_cast<node_type*>(ope_type::getChildL(const_cast<const node_type&>(node))); }//大（右）側
		inline static node_type* getChildS_rc(node_type& node){ return const_cast<node_type*>(ope_type::getChildS(const_cast<const node_type&>(node))); }//小（左）側
		//子ノードを取得
		inline static const node_type* getChild(const node_type& node, const bool child_is_large)
		{
			return child_is_large ?
				ope_type::getChildL(node) ://大（右）側
				ope_type::getChildS(node); //小（左）側
		}
		inline static node_type* getChild_rc(node_type& node, const bool child_is_large){ return const_cast<node_type*>(getChild(const_cast<const node_type&>(node), child_is_large)); }
		//子ノードを変更
		inline static void setChild(node_type& node, const bool child_is_large, const node_type* child)
		{
			if (child_is_large)
				ope_type::setChildL(node, child);//大（右）側
			else
				ope_type::setChildS(node, child);//小（左）側
		}

		//キーを比較
		//※デフォルト
		//Return value:
		//  0     ... lhs == rhs
		//  1以上 ... lhs > rhs
		// -1以下 ... lhs < rhs
		inline static int compareKey(const key_type lhs, const key_type rhs)
		{
			return static_cast<int>(lhs) - static_cast<int>(rhs);
		}

		//ノードとキーを比較
		inline static int compare(const node_type& lhs, const node_type& rhs)
		{
			return ope_type::compareKey(ope_type::getKey(lhs), ope_type::getKey(rhs));
		}
		inline static int compare(const node_type& lhs, const key_type rhs)
		{
			return ope_type::compareKey(ope_type::getKey(lhs), rhs);
		}
		inline static int compare(const key_type lhs, const node_type& rhs)
		{
			return ope_type::compareKey(lhs, ope_type::getKey(rhs));
		}
		inline static int compare(const key_type lhs, const key_type rhs)
		{
			return ope_type::compareKey(lhs, rhs);
		}
		inline static bool eq(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) == 0; }
		inline static bool eq(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) == 0; }
		inline static bool eq(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) == 0; }
		inline static bool ne(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) != 0; }
		inline static bool ne(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) != 0; }
		inline static bool ne(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) != 0; }
		inline static bool gt(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) > 0; }
		inline static bool gt(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) > 0; }
		inline static bool gt(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) > 0; }
		inline static bool ge(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool ge(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool ge(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool lt(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) < 0; }
		inline static bool lt(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) < 0; }
		inline static bool lt(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) < 0; }
		inline static bool le(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) <= 0; }
		inline static bool le(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) <= 0; }
		inline static bool le(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) <= 0; }

		//色判定
		inline static bool isBlack(const node_type& node){ return ope_type::getColor(node) == BLACK; }
		inline static bool isRed(const node_type& node){ return ope_type::getColor(node) == RED; }
		//色更新
		inline static void setBlack(node_type& node){ ope_type::setColor(node, BLACK); }
		inline static void setRed(node_type& node){ ope_type::setColor(node, RED); }
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef typename ope_type::key_type key_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef stack_t<ope_type> stack_type; \
		typedef typename stack_type::info_t stack_info_type; \
		typedef typename ope_type::lock_type lock_type;
	//----------------------------------------
	//デバッグ用補助関数
#ifdef DEBUG_PRINT_FOR_ADD
	template<typename... Tx>
	inline int printf_dbg_add(const char* fmt, Tx... args)
	{
		return printf(fmt, args...);
	}
#else//DEBUG_PRINT_FOR_ADD
	inline int printf_dbg_add(const char* fmt, ...){ return 0; }
#endif//DEBUG_PRINT_FOR_ADD
#ifdef DEBUG_PRINT_FOR_REMOVE
	template<typename... Tx>
	inline int printf_dbg_remove(const char* fmt, Tx... args)
	{
		return printf(fmt, args...);
	}
#else//DEBUG_PRINT_FOR_REMOVE
	inline int printf_dbg_remove(const char* fmt, ...){ return 0; }
#endif//DEBUG_PRINT_FOR_REMOVE
	//--------------------
	//赤黒木処理用スタッククラス
	//※赤黒木のノード情報を扱う
	template<class OPE_TYPE>
	class stack_t
	{
	public:
		//基本型
		typedef OPE_TYPE ope_type;
		typedef typename OPE_TYPE::node_type node_type;
	public:
		//定数
		static const int DEPTH_MAX = ope_type::STACK_DEPTH_MAX;//最大の深さ（スタック処理用）
	public:
		//型
		//ノード情報型
		struct info_t
		{
			const node_type* m_nodeRef;//ノード参照
			bool m_isLarge;//大（右）側に連結か？
		};
	public:
		//スタックにノード情報を記録
		info_t* push(const node_type* node, const bool is_large)
		{
			assert(m_depth < DEPTH_MAX);
			info_t* stack_node = &m_array[m_depth++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
			return stack_node;
		}
		//スタックからノード情報を取得
		info_t* pop()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[--m_depth];
		}
		//スタックの先頭のノード情報を参照
		//※要素が減らない
		info_t* top()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[m_depth - 1];
		}
		//スタックの現在の深さを取得
		int getDepth() const { return m_depth; }
		//スタックの現在の深さを更新
		void setDepth(const int depth)
		{
			if (depth < 0)
				m_depth = 0;
			else if (depth < m_depth)
				m_depth = depth;
		}
		//スタックの現在の深さをリセット
		void reset()
		{
			m_depth = 0;
		}
		//スタックの現在の幅を算出
		//※「幅」＝スタックの現在の深さまでの大小連結の合計値を算出
		//※小側を-1、大側を+1として計算
		long long calcBreadth()
		{
			long long breadth = 0;
			for (int depth = 0; depth < m_depth; ++depth)
			{
				breadth *= 2ll;
				breadth += (m_array[depth].m_isLarge ? 1ll : 0ll);
			}
			return breadth;
		}
		//ムーブオペレータ
		inline stack_t& operator=(const stack_t&& rhs)
		{
			m_depth = rhs.m_depth;
			if (m_depth > 0)
				memcpy(m_array, rhs.m_array, sizeof(info_t)* m_depth);
			return *this;
		}
		//コピーオペレータ
		inline stack_t& operator=(const stack_t& rhs)
		{
			//return operator=(std::move(rhs));
			m_depth = rhs.m_depth;
			if (m_depth > 0)
				memcpy(m_array, rhs.m_array, sizeof(info_t)* m_depth);
			return *this;
		}
		//ムーブコンストラクタ
		inline stack_t(const stack_t&& obj) :
			m_depth(obj.m_depth)
		{
			if (m_depth > 0)
				memcpy(m_array, obj.m_array, sizeof(info_t)* m_depth);
		}
		//コピーコンストラクタ
		inline stack_t(const stack_t& obj) :
			m_depth(obj.m_depth)
		{
			if (m_depth > 0)
				memcpy(m_array, obj.m_array, sizeof(info_t)* m_depth);
		}
		//コンストラクタ
		inline stack_t() :
			m_depth(0)
		{}
	private:
		//フィールド
		info_t m_array[DEPTH_MAX];//ノード情報の配列（スタック）
		int m_depth;//スタックのカレントの深さ
	};
	//--------------------
	//赤黒木操作関数：最小ノード探索
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getSmallestNode(const typename OPE_TYPE::node_type* root, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* curr_node = root;//現在の探索ノード
		while (true)
		{
			const node_type* child_node = ope_type::getChildS(*curr_node);//小（左）側の子ノードを取得
			if (!child_node)//子が無ければ終了
				return  curr_node;
			stack.push(curr_node, false);//親ノードをスタックに記録
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：最大ノード探索
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getLargestNode(const typename OPE_TYPE::node_type* root, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* curr_node = root;//現在の探索ノード
		while (true)
		{
			const node_type* child_node = ope_type::getChildL(*curr_node);//大（右）側の子ノードを取得
			if (!child_node)//子が無ければ終了
				return  curr_node;
			stack.push(curr_node, true);//親ノードをスタックに記録
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：次ノード探索（カレントノードの次に大きいノードを探索）
	//※get**Node()やsearchNode()でカレントノードを取得した際のスタックを渡す必要あり
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getNextNode(const typename OPE_TYPE::node_type* curr_node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!curr_node)
			return nullptr;
		const node_type* child_node_l = ope_type::getChildL(*curr_node);//大（右）側の子ノードを取得
		if (child_node_l)//子がある場合
		{
			stack.push(curr_node, true);//親ノードをスタックに記録
			return getSmallestNode<ope_type>(child_node_l, stack);//子から一番小さい子孫ノードを取得
		}
		else//if(!child_node_l)//子がない場合
		{
			const stack_info_type* stack_node = nullptr;
			while (stack_node = stack.pop())//親ノードを取得
			{
				if (stack_node->m_isLarge == false)//小（左）側の子の親なら終了
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：前ノード探索（カレントノードの次に小さいノードを探索）
	//※get**Node()やsearchNode()でカレントノードを取得した際のスタックを渡す必要あり
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getPrevNode(const typename OPE_TYPE::node_type* curr_node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!curr_node)
			return nullptr;
		const node_type* child_node_s = ope_type::getChildS(*curr_node);//小（左）側の子ノードを取得
		if (child_node_s)//子がある場合
		{
			stack.push(curr_node, false);//親ノードをスタックに記録
			return getLargestNode<ope_type>(child_node_s, stack);//子から一番大きい子孫ノードを取得
		}
		else//if(!child_node_s)//子がない場合
		{
			const stack_info_type* stack_node = nullptr;
			while (stack_node = stack.pop())//親ノードを取得
			{
				if (stack_node->m_isLarge == true)//大（右）側の子の親なら終了
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：ノード探索（指定のキーと一致するノード、もしくは、指定のキーに最も近いノードを検索）
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	//※一致ノードが複数ある場合、最小位置にあるノードを返す
	//※指定のキーの内輪で最も近いノードと同キーのノードが複数ある場合、その最後のノードを返す
	//※指定のキーより大きく最も近いノードと同キーのノードが複数ある場合、その最初のノードを返す
	enum match_type_t
	{
		FOR_MATCH = 0,//一致ノードを検索
		FOR_NEAREST_SMALLER,//一致ノード、もしくは、内輪で最も近いノードを検索
		FOR_NEAREST_LARGER,//一致ノード、もしくは、それより大きく最も近いノードを検索
	};
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* searchNode(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::key_type key, stack_t<OPE_TYPE>& stack, const match_type_t search_type = FOR_MATCH)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* match_node = nullptr;//一致ノード
		int match_stack_depth = -1;//一致ノード検出時のスタック位置
		const node_type* nearest_node = nullptr;//最近ノード
		int nearest_stack_depth = -1;//最近ノード検出時のスタック位置
		const node_type* curr_node = root;//現在の探索ノード
		while (true)
		{
			const int cmp = ope_type::compare(*curr_node, key);//指定のキーと大小比較
			if (cmp == 0)//指定のキーと一致
			{
				//※キー重複を許容するアルゴリズムのため、
				//　一致ノードを記録した上で検索を続行する
				match_node = curr_node;//一致ノードを記録
				match_stack_depth = stack.getDepth();//一致ノード検出時のスタック位置を記録
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = ope_type::getChildS(*curr_node);//小（左）側の子の方に検索を続行
				if (!curr_node)//子が無ければ探索終了
					break;
			}
			else if (cmp < 0)//指定のキーより小さい
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && ope_type::le(*nearest_node, *curr_node)))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_depth = stack.getDepth();//最近ノード検出時のスタック位置を記録
				}
				const node_type* child_node = ope_type::getChildL(*curr_node);//大（右）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, true);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
			else//if (cmp > 0)//指定のキーより大きい
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && ope_type::ge(*nearest_node, *curr_node)))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_depth = stack.getDepth();//最近ノード検出時のスタック位置を記録
				}
				const node_type* child_node = ope_type::getChildS(*curr_node);//小（左）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
		}
		if (match_node)//一致ノード検出時
		{
			stack.setDepth(match_stack_depth);//一致ノード検出時のスタック位置に戻す
			return match_node;//一致ノードを返す
		}
		else//if (!match_node)
		{
			if (nearest_node)//最近ノード検出時
			{
				stack.setDepth(nearest_stack_depth);//最近ノード検出時のスタック位置に戻す
				return nearest_node;//最近ノードを返す
			}
		}
		return nullptr;//検索失敗
	}
	//既存ノード探索 ※キーを指定する代わりに、既存のノードを渡して探索する
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* searchNode(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::node_type* node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const key_type key = ope_type::getKey(*node);//キーを取得
		node_type* target_node = const_cast<node_type*>(searchNode<ope_type>(root, key, stack));//キーが一致するノードを検索
		if (!target_node)//キーが一致するノードがなければ終了
			return nullptr;
		while (target_node != node && ope_type::eq(*target_node, key))//指定ノード（と同じアドレス）を検索
			target_node = const_cast<node_type*>(getNextNode<ope_type>(target_node, stack));
		if (target_node != node)
			return nullptr;
		return target_node;
	}
	//--------------------
	//赤黒木操作関数：木の最大深度を計測
	//※内部でスタックを作成
	//※-1でリストなし
	template<class OPE_TYPE>
	int getDepthMax(const typename OPE_TYPE::node_type* root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return -1;
		int depth_max = 0;//最大の深さ
		stack_type stack;//スタックを作成
		const node_type* node = getSmallestNode<ope_type>(root, stack);//最小ノード取得
		while (node)
		{
			const int depth = stack.getDepth();//深さを取得
			depth_max = depth_max >= depth ? depth_max : depth;//最大の深さを更新
			node = getNextNode<ope_type>(node, stack);//次のノード取得
		}
		return depth_max;
	}
	//--------------------
	//赤黒木操作関数：木のノード数を計測
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type* node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
	#if 0
		//再帰処理版
		return !node ? 0 : 1 + countNodes<ope_type>(ope_type::getChildL(*node)) +
		                       countNodes<ope_type>(ope_type::getChildS(*node));
	#else
		//ループ処理版
		//※再帰処理版よりもループ処理版の方が高速
		//　▼実際に処理時間を測定して確認
		//　　以下、ノード数100の計測を10000000回行った結果
		//　　・再帰処理版：　3.443212500 sec
		//　　・ループ処理版：1.663094300 sec
		int count = 0;
		const node_type* stack[stack_type::DEPTH_MAX];
		int stack_pos = 0;
		while (node)
		{
			while (node)
			{
				++count;
				stack[stack_pos++] = node;
				node = ope_type::getChildS(*node);
			}
			while (!node && stack_pos != 0)
				node = ope_type::getChildL(*stack[--stack_pos]);
		}
		return count;
	#endif
	}
	//--------------------
	//赤黒木操作関数：指定のキーのノード数を計測
	//※関数内でスタックを使用
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::key_type key)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return 0;
		stack_type stack;
		const node_type* node = searchNode<ope_type>(root, key, stack, FOR_MATCH);
		if (!node)
			return 0;
		int count = 0;//ノード数
		while (node && ope_type::eq(*node, key))
		{
			++count;
			node = getNextNode<ope_type>(node, stack);
		}
		return count;
	}
	//--------------------
	//赤黒木操作関数：ノード追加時の赤黒バランス調整
	template<class OPE_TYPE>
	void _balanceForAdd(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* curr_node, bool child_is_large, typename OPE_TYPE::node_type* child_node);
	//--------------------
	//赤黒木操作関数：ノードを追加
	//※関数内でスタックを使用
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* addNode(typename OPE_TYPE::node_type* new_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!new_node)
			return nullptr;
		ope_type::setChildL(*new_node, nullptr);//新規ノードはリンクをクリア：大（右）側
		ope_type::setChildS(*new_node, nullptr);//新規ノードはリンクをクリア：小（左）側
		if (!root)//根ノードが未登録の場合
		{
			root = new_node;//根ノードに登録
		#ifndef DISABLE_COLOR_FOR_ADD
			ope_type::setBlack(*root);//根ノードは黒
		#endif//DISABLE_COLOR_FOR_ADD
			return new_node;//この時点で処理終了
		}
	#ifndef DISABLE_COLOR_FOR_ADD
		ope_type::setRed(*new_node);//新規ノードは暫定で赤
	#endif//DISABLE_COLOR_FOR_ADD
		key_type new_key = ope_type::getKey(*new_node);//新規ノードのキーを取得
		stack_type stack;//スタックを用意
		node_type* curr_node = root;//現在の探索ノード
		bool new_key_is_large = false;
		while (true)
		{
			new_key_is_large = ope_type::ge(new_key, *curr_node);//指定のキーと一致もしくは指定のキーの方が大きければtrue
			node_type* child_node = ope_type::getChild_rc(*curr_node, new_key_is_large);//子ノードを取得
			if (!child_node)//子ノードが無ければそこに新規ノードを追加して終了
			{
				ope_type::setChild(*curr_node, new_key_is_large, new_node);//子ノードとして新規ノードを追加
				break;
			}
			stack.push(curr_node, new_key_is_large);//親ノードをスタックに記録
			curr_node = child_node;
		}
	#ifndef DISABLE_COLOR_FOR_ADD
		//赤黒バランス調整
		_balanceForAdd<ope_type>(root, stack, curr_node, new_key_is_large, new_node);
	#endif//DISABLE_COLOR_FOR_ADD
		return new_node;
	}
	//--------------------
	//赤黒木操作関数：ノード削除時の赤黒バランス調整
	template<class OPE_TYPE>
	void _balanceForRemove(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* removing_node, typename OPE_TYPE::node_type* replacing_node);
	//--------------------
	//赤黒木操作関数：ノードを削除
	//※関数内でスタックを二つ使用
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* removeNode(const typename OPE_TYPE::node_type* target_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!target_node || !root)
			return nullptr;
		stack_type stack;//スタックを用意
		node_type* removing_node = const_cast<node_type*>(searchNode<ope_type>(root, target_node, stack));//削除ノードを検索してスタックを作る
		if (!removing_node)//検索に失敗したら終了
			return nullptr;
		//削除開始
		node_type* parent_node = nullptr;//削除ノードの親ノード
		bool curr_is_large = false;//削除ノードの親ノードからの連結方向
		{
			stack_info_type* parent_info = stack.top();//親ノード参照情報を取得
			if (parent_info)
			{
				parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//親ノードを取得
				curr_is_large = parent_info->m_isLarge;//親ノードからの連結方向
			}
		}
		node_type* child_node_l = ope_type::getChildL_rc(*removing_node);//大（右）側の子ノードを取得
		node_type* child_node_s = ope_type::getChildS_rc(*removing_node);//小（左）側の子ノードを取得
		node_type* descendant_node = nullptr;//削除ノードの最大子孫ノード（削除ノードの次に小さいノード）
		node_type* replacing_node = nullptr;//削除ノードと置き換えるノード
		//削除ノードと置き換えるノードの選出処理
		//-------------------------------------------------------------------------
		//【木の説明の凡例】
		//・「(S)」は、小（左）側のノードを示す。
		//・「(L)」は、大（右）側のノードを示す。
		//・「(SL)」は、小（左）側の子の大（右）側のノードを示す。
		//　（「(LS)」[(SS)」「(SSL)」などのパターンも同様）
		//・「(null)」は、ノードがないことを示す。
		//-------------------------------------------------------------------------
		if (child_node_s && !child_node_l)
		{
			//削除ノードの小（左）側にのみ子ノードがある場合、それを置き換えノードとする
			//-------------------------------------------------------------------------
			//            .-------[removing_node]------.                               
			//   .--[replacing_node]--.             (null)                             
			// [(SS)]              [(SL)]                                              
			//-------------------------------------------------------------------------
			//                          ↓【置き換え】                                 
			//                 .--[replacing_node]--.                                  
			//               [(SS)]              [(SL)]                                
			//-------------------------------------------------------------------------
			replacing_node = child_node_s;//削除ノードと置き換えるノードをセット
		}
		else if (!child_node_s && child_node_l)
		{
			//削除ノードの大（右）側にのみ子ノードがある場合、それを置き換えノードとする
			//-------------------------------------------------------------------------
			//            .-------[removing_node]------.                               
			//          (null)              .--[replacing_node]--.                     
			//                            [(LS)]              [(LL)]                   
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                          ↓【置き換え】                                 
			//                 .--[replacing_node]--.                                  
			//               [(LS)]              [(LL)]                                
			//-------------------------------------------------------------------------
			replacing_node = child_node_l;//削除ノードと置き換えるノードをセット
		}
		else if (child_node_s && child_node_l)
		{
			//削除ノードの小（左）側と大（右）側の両方の子ノードがある場合、前ノード（最大子孫ノード）を置き換えノードとする
			//-------------------------------------------------------------------------
			//【ケース①】                                                             
			//            .---------------[removing_node]---------------.              
			//          [(S)]----.                                    [(L)]            
			//                   .(最大子孫)                                           
			//           .--[replacing_node]--.                                        
			//         [(SLS)]             (null)                                      
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                                 ↓【置き換え】                          
			//            .---------------[replacing_node]--------------.              
			//          [(S)]----.                                    [(L)]            
			//                   .(最大子孫)                                           
			//                [(SLS)]                                                  
			//-------------------------------------------------------------------------
			//【ケース②】                                                             
			//            .---------------[removing_node]---------------.              
			//    .--[replacing_node]--.                              [(L)]            
			//  [(SLS)]             (null)                                             
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                                 ↓【置き換え】                          
			//            .---------------[replacing_node]--------------.              
			//         [(SLS)]                                        [(L)]            
			//-------------------------------------------------------------------------
			stack_info_type* remove_info = stack.push(removing_node, false);//スタックに削除ノードを追加
			descendant_node = const_cast<node_type*>(getLargestNode<ope_type>(child_node_s, stack));//最大子孫ノードを取得
			replacing_node = descendant_node;//削除ノードと置き換えるノードをセット
			if (replacing_node != child_node_s)
			{
				//【ケース①：前ノード（最大子孫ノード）が削除ノードの小（左）側の子の最大子孫】
				stack_info_type* descendant_parent_info = stack.top();//最大子孫ノードの親ノードを取得
				node_type* descendant_parent_node = const_cast<node_type*>(descendant_parent_info->m_nodeRef);//最大子孫ノードの親ノードを取得
				ope_type::setChildL(*descendant_parent_node, ope_type::getChildS(*replacing_node));//最大子孫ノードの親ノードの大（右）側の子ノードを変更
				ope_type::setChildS(*replacing_node, child_node_s);//置き換えノードの小（左）側の子ノードを変更
			}
			else//if (descendant_node == child_node_s)
			{
				//【ケース②：前ノード（最大子孫ノード）が削除ノードの小（左）側の子】
				//なにもしない
			}
			ope_type::setChildL(*replacing_node, child_node_l);//置き換えノードの大（右）側の子ノードを変更
			remove_info->m_nodeRef = replacing_node;//スタック上の削除ノード参照を置き換えノード参照に書き換え
		}
		//else//if (!child_node_s && !child_node_l)
		//{
		//	//削除ノードの小（左）側と大（右）側の両方の子ノードがない場合、置き換えノードはnullptr
		//	replacing_node = nullptr;//削除ノードと置き換えるノードをセット
		//}
		//削除ノードの置き換え処理
		ope_type::setChildL(*removing_node, nullptr);
		ope_type::setChildS(*removing_node, nullptr);
		if (!parent_node)//親ノードがない場合 → 根ノードが削除された場合である
		{
			root = replacing_node;//根ノードを置き換え
			if (!root)//根ノードがなくなったら、この時点で処理終了
				return removing_node;
		}
		else//if(parent_node)//親ノードがある場合
		{
			ope_type::setChild(*parent_node, curr_is_large, replacing_node);//親ノードの子ノードを置き換え
		}
	#ifndef DISABLE_COLOR_FOR_REMOVE
		//赤黒バランス調整
		_balanceForRemove<ope_type>(root, stack, removing_node, replacing_node);
	#endif//DISABLE_COLOR_FOR_REMOVE
		return removing_node;
	}
	//--------------------
	//赤黒木操作関数：【汎用処理】ノード左回転処理
	//-------------------------------------------------------------------------
	//              .--------------[curr_node]--------------.                  
	//       [child_node_s]                     .----[child_node_l]            
	//                                    [child_node_ls]                      
	//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	//                               ↓【左回転】                              
	//              .-------------[child_node_l]                               
	//      .-----[curr_node]----.                                             
	// [child_node_s]  [child_node_ls]                                         
	//-------------------------------------------------------------------------
	template<class OPE_TYPE>
	inline typename OPE_TYPE::node_type* _rotateL(typename OPE_TYPE::node_type* curr_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		node_type* child_node_l = ope_type::getChildL_rc(*curr_node);
		node_type* child_node_ls = ope_type::getChildS_rc(*child_node_l);
		ope_type::setChildS(*child_node_l, curr_node);
		ope_type::setChildL(*curr_node, child_node_ls);
		return child_node_l;
	};
	//--------------------
	//赤黒木操作関数：【汎用処理】ノード右回転処理
	//-------------------------------------------------------------------------
	//        .--------------[curr_node]--------------.                        
	// [child_node_s]----.                       [child_node_l]                
	//          [child_node_sl]                                                
	//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	//                            ↓【右回転】                                 
	//                      [child_node_s]------------.                        
	//                                      .----[curr_node]----.              
	//                                 [child_node_sl]  [child_node_l]         
	//-------------------------------------------------------------------------
	template<class OPE_TYPE>
	inline typename OPE_TYPE::node_type* _rotateR(typename OPE_TYPE::node_type* curr_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		node_type* child_node_s = ope_type::getChildS_rc(*curr_node);
		node_type* child_node_sl = ope_type::getChildL_rc(*child_node_s);
		ope_type::setChildL(*child_node_s, curr_node);
		ope_type::setChildS(*curr_node, child_node_sl);
		return child_node_s;
	};
	//--------------------
	//赤黒木操作関数：ノード追加時の赤黒バランス調整
	template<class OPE_TYPE>
	void _balanceForAdd(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* curr_node, bool child_is_large, typename OPE_TYPE::node_type* child_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		bool is_rotated = false;//回転処理済みフラグ
		bool is_balanced = false;//平衡状態検出フラグ
		while (true)
		{
			stack_info_type* parent_info = stack.pop();//スタックから親ノード情報取得
			if (!parent_info)
				break;
			node_type* parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//親ノード取得
			bool curr_is_large = parent_info->m_isLarge;//親ノードからの大小連結情報取得
			if (is_rotated)//前回回転処理済みなら親ノードの子ノードを連結し直す
			{
				ope_type::setChild(*parent_node, curr_is_large, curr_node);
				is_rotated = false;//回転処理済み状態リセット
			}
			//回転処理
			//-------------------------------------------------------------------------
			//【木の説明の凡例】
			//・「:B」は、黒を示す。
			//・「:R」は、赤を示す。
			//・「:+B」は、黒に変更することを示す。
			//・「:+R」は、赤に変更することを示す。
			//・「(S)」は、小（左）側のノードを示す。
			//・「(L)」は、大（右）側のノードを示す。
			//・「(SL)」は、小（左）側の子の大（右）側のノードを示す。
			//　（「(LS)」[(SS)」「(SSL)」などのパターンも同様）
			//・「(null)」は、ノードがないことを示す。
			//-------------------------------------------------------------------------
			if (!is_balanced && ope_type::isBlack(*curr_node))//現在ノードが黒なら平衡状態検出（以後の条件違反チェックは不要）
				is_balanced = true;
			if (!is_balanced && ope_type::isRed(*child_node))//赤ノードが二つ連結していたら条件違反のため、回転処理
			{
				//【共通処理】親ノードを左回転処理
				//-------------------------------------------------------------------------
				//             .-------[parent_node:B]--------.                            
				//           [(S)]                    .--[curr_node:R]--.                  
				//                                  [(LS)]       [child_node:R]            
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ↓【左回転】                                   
				//          .-----------[curr_node:R]---------.                            
				//   .--[parent_node:B]--.               [child_node:R]                    
				// [(S)]              [(LS)]                                               
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ↓【変数と色を調整】                           
				//                                                  黒に                   
				//            .--------[parent_node:R]--------.      ↓                    
				//   .------[(S):B]------.                [curr_node:+B]                   
				// [(SS)]             [(SL)]                                               
				//-------------------------------------------------------------------------
				auto rotateParentL = [&]() -> const node_type*
				{
					parent_node = _rotateL<ope_type>(parent_node);//左回転処理
					curr_is_large = true;
					curr_node = child_node;
					ope_type::setBlack(*curr_node);//ノードを黒にする
					//child_is_large = true;
					//child_node = nullptr;
					return parent_node;
				};
				//【共通処理】親ノードを右回転処理
				//-------------------------------------------------------------------------
				//               .-----[parent_node:B]-----.                               
				//       .--[curr_node:R]--.             [(L)]                             
				// [child_node:R]       [(SL)]                                             
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                            ↓【右回転】                                 
				//               .-------[curr_node:R]-------.                             
				//          [child_node:R]         .--[parent_node:B]--.                   
				//                               [(SL)]              [(L)]                 
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                            ↓【変数と色を調整】                         
				//               .-------[parent_node:R]-----.                             
				//           [curr_node:+B]        .------[(L):B]------.                   
				//                      ↑       [(LS)]             [(LL)]                 
				//                     黒に                                                
				//-------------------------------------------------------------------------
				auto rotateParentR = [&]() -> const node_type*
				{
					parent_node = _rotateR<ope_type>(parent_node);//右回転処理
					curr_is_large = false;
					curr_node = child_node;
					ope_type::setBlack(*curr_node);//ノードを黒にする
					//child_is_large = false;
					//child_node = nullptr;
					return parent_node;
				};
				//【共通処理】現在のノードを左回転処理
				//-------------------------------------------------------------------------
				//           .-------[curr_node:R]-------.                                 
				//         [(S)]                .--[child_node:R]                          
				//                            [(LS)]                                       
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ↓【左回転】                                   
				//           .-------[child_node:R]                                        
				//   .--[curr_node:R]--.                                                   
				// [(S)]            [(LS)]                                                 
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ↓【変数を調整】※色の調整はしない             
				//           .--------[curr_node:R]                                        
				//   .--[child_node:R]--.                                                  
				// [(SS)]            [(SL)]                                                
				//-------------------------------------------------------------------------
				auto rotateCurrL = [&]() -> const node_type*
				{
					node_type* curr_node_tmp = curr_node;
					curr_node = _rotateL<ope_type>(curr_node);//左回転処理
					child_is_large = false;
					child_node = curr_node_tmp;
					return curr_node;
				};
				//【共通処理】現在のノードを右回転処理
				//-------------------------------------------------------------------------
				//       .--------[curr_node:R]--------.                                   
				// [child_node:R]--.                 [(L)]                                 
				//              [(SS)]                                                     
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                     ↓【右回転】                                        
				//               [child_node:R]-------.                                    
				//                           .--[curr_node:R]--.                           
				//                         [(SS)]            [(L)]                         
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                     ↓【変数を調整】※色の調整はしない                  
				//                [curr_node:R]-------.                                    
				//                          .--[child_node:R]--.                           
				//                        [(LS)]            [(LL)]                         
				//-------------------------------------------------------------------------
				auto rotateCurrR = [&]() -> const node_type*
				{
					node_type* curr_node_tmp = curr_node;
					curr_node = _rotateR<ope_type>(curr_node);//右回転処理
					child_is_large = true;
					child_node = curr_node_tmp;
					return curr_node;
				};
				//各状態に合わせた回転処理
				if (!curr_is_large && !child_is_large)
				{
					//【回転ケース[S-S]：［小（左）側の子：赤］→［小（左）側の子：赤］】
					//-------------------------------------------------------------------------
					//               .-----[parent_node:B]-----.                               
					//       .--[curr_node:R]--.             [(L)]                             
					// [child_node:R]       [(SL)]                                             
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                            ↓【親ノードを右回転】                       
					//               .-------[curr_node:R]-------.                             
					//          [child_node:R]         .--[parent_node:B]--.                   
					//                               [(SL)]              [(L)]                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                            ↓【変数と色を調整】                         
					//               .-------[parent_node:R]-----.                             
					//           [curr_node:+B]         .------[(L):B]------.                  
					//                      ↑        [(LS)]             [(LL)]                
					//                     黒に                                                
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-SS-[%d:B]→[%d:R]→[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					rotateParentR();//親ノードを右回転処理
				}
				else if (!curr_is_large &&  child_is_large)
				{
					//【回転ケース[S-L]：［小（左）側の子：赤］→［大（右）側の子：赤］】
					//-------------------------------------------------------------------------
					//                       .-----------------[parent_node:B]-------.         
					//               .--[curr_node:R]--.                           [(L)]       
					//             [(SS)]        .--[child_node:R]--.                          
					//                        [(SLS)]          [(SLL)]                         
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ↓【現在ノードを左回転】  
					//                        .----------------[parent_node:B]-------.         
					//           .------[child_node:R]------.                      [(L)]       
					//   .--[curr_node:R]--.            [(SLL)]                                
					// [(SS)]          [(SLS)]                                                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ↓【親ノードを右回転】    
					//                        .-----------------[child_node:R]-------.         
					//                .--[curr_node:R]--.               .--[parent_node:B]--.  
					//              [(SS)]           [(SLS)]          [(SLL)]             [(L)]
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ↓【変数と色を調整】      
					//                        .-----------------[parent_node:R]-----.          
					//                .--[curr_node:+B]--.                  .-----[(L):B]---.  
					//               [(SS)])        ↑ [(SL)]             [(LS)]         [(LL)]
					//                             黒に                                        
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-SL-[%d:B]→[%d:R]→[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					ope_type::setChildS(*parent_node, rotateCurrL());//現在のノードを左回転処理
					rotateParentR();//親ノードを右回転処理
				}
				else if (curr_is_large && !child_is_large)
				{
					//【回転ケ－ス[L-S]：［大（右）側の子：赤］→［小（左）側の子：赤］】
					//---------------------------------------------------------------------------------
					//             .-------[parent_node:B]----------------.                            
					//           [(S)]                       .-------[curr_node:R]-------.             
					//                               .--[child_node:R]--.              [(LL)]          
					//                             [(LSS)]          [(LSL)]                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【現在ノードを右回転】                               
					//             .-------[parent_node:B]-----------------.                           
					//           [(S)]                       .-------[child_node:R]-------.            
					//                                     [(LSS)]                .--[curr_node:R]--.  
					//                                                          [(LSL)]          [(LL)]
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【親ノードを左回転】                                 
					//           .----------[child_node:R]---------.                                   
					//   .--[parent_node:B]--.             .--[curr_node:R]--.                         
					// [(S)]             [(LSS)]         [(LSL)]          [(LL)]                       
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【変数と色を調整】                                   
					//            .--------[parent_node:R]--------.       ↓黒に                       
					//   .------[(S):B]------.              .--[curr_node:+B]--.                       
					// [(SS)]             [(SL)]          [(LSL)]           [(LL)]                     
					//---------------------------------------------------------------------------------
					printf_dbg_add("<ADD-LS-[%d:B]→[%d:R]→[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					ope_type::setChildL(*parent_node, rotateCurrR());//現在のノードを右回転処理
					rotateParentL();//親ノードを左回転処理
				}
				else//if (!curr_is_large && !child_is_large)
				{
					//【回転ケース[L-L]：［大（右）側の子：赤］→［大（右）側の子：赤］】
					//-------------------------------------------------------------------------
					//             .-------[parent_node:B]--------.                            
					//           [(S)]                    .--[curr_node:R]--.                  
					//                                  [(LS)]       [child_node:R]            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【親ノードを左回転】                         
					//          .-----------[curr_node:R]---------.                            
					//   .--[parent_node:B]--.               [child_node:R]                    
					// [(S)]              [(LS)]                                               
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【変数と色を調整】                           
					//            .--------[parent_node:R]--------.      ↓ 黒に               
					//   .------[(S):B]------.                [curr_node:+B]                   
					// [(SS)]             [(SL)]                                               
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-LL-[%d:B]→[%d:R]→[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					rotateParentL();//親ノードを左回転処理
				}
				is_rotated = true;//回転済み
			}
			//親ノードに処理を移す
			child_is_large = curr_is_large;
			child_node = curr_node;
			curr_node = parent_node;
		}
		if (curr_node)
		{
			root = curr_node;//根ノードを更新
			ope_type::setBlack(*root);//根ノードは黒
		}
	}
	//--------------------
	//赤黒木操作関数：ノード削除時の赤黒バランス調整
	template<class OPE_TYPE>
	void _balanceForRemove(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* removing_node, typename OPE_TYPE::node_type* replacing_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		bool is_necessary_rotate = false;//回転処理必要？
		bool remove_node_is_black = ope_type::isBlack(*removing_node);
		bool replace_node_is_black = replacing_node ? ope_type::isBlack(*replacing_node) : false;
		//回転処理必要判定
		//-------------------------------------------------------------------------
		//【木の説明の凡例】
		//・「:B」は、黒を示す。
		//・「:R」は、赤を示す。
		//・「:R/n」は、赤、もしくは、ノードがないことを示す。
		//・「:+B」は、黒に変更することを示す。
		//・「:+R」は、赤に変更することを示す。
		//・「(S)」は、小（左）側のノードを示す。
		//・「(L)」は、大（右）側のノードを示す。
		//・「(SS)」は、小（左）側の子の小（左）側のノードを示す。
		//・「(SL)」は、小（左）側の子の大（右）側のノードを示す。
		//　（「(LS)」[(SS)」「(SSL)」などのパターンも同様）
		//・「(null)」は、ノードがないことを示す。
		//-------------------------------------------------------------------------
		if (!remove_node_is_black)//削除ノードが赤の場合
		{
			if (!replacing_node)//置き換えノードがない場合
			{
				//【判定ケース[R-on-null]：削除ノードが赤、置き換えノードがない】：回転処理不要
				//-------------------------------------------------------------------------
				//    .--[removing_node:R]--.                                              
				// (null)                 (null)                                           
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//             ↓【削除】                                                  
				//           (null)                                                        
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//※黒が減らないので、木に影響がない。                                     
				//-------------------------------------------------------------------------
				//【最終状態の特徴】                                                       
				//・赤黒の位置関係（条件③）も                                             
				//　黒のバランス（条件④）も崩れない。                                     
				//-------------------------------------------------------------------------
				printf_dbg_remove("<DEL-Rn-[%d:R]←(null)=END", ope_type::getKey(*removing_node));
				//is_necessary_rotate = false;//回転処理不要
			}
			else//if(replacing_node)//置き換えノードがある場合
			{
				if (!replace_node_is_black)//置き換えノードが黒の場合
				{
					//【判定ケース[R-on-R]：削除ノードが赤、置き換えノードが赤】：回転処理不要
					//-------------------------------------------------------------------------
					//     .---------------------[removing_node:R]-----.                       
					//  [(S:B)]---------.                           [(L:B)]                    
					//                  .(最大子孫)                                            
					//         .--[replacing_node:R]--.                                        
					//      [(SLS)]                 (null)                                     
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//     .---------------------[replacing_node:R]----.                       
					//  [(S:B)]---------.                           [(L:B)]                    
					//                  .(最大子孫)                                            
					//               [(SLS)]                                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※黒が減らないので、木に影響がない。                                     
					//-------------------------------------------------------------------------
					//【他のケース】                                                           
					//※置き換えノードが削除ノードの子であるケースはない。                     
					//　（赤の子が赤であってはいけないルールのため）                           
					//-------------------------------------------------------------------------
					//【最終状態の特徴】                                                       
					//・赤黒の位置関係（条件③）も                                             
					//　黒のバランス（条件④）も崩れない。                                     
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-RR-[%d:R]←[%d:R]=END>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					//is_necessary_rotate = false;//回転処理不要
				}
				else//if (replace_node_is_black)//置き換えノードが黒の場合
				{
					//【判定ケース[R-on-B]：削除ノードが赤、置き換えノードが黒】：回転処理必要
					//-------------------------------------------------------------------------
					//【ケース①】                                                             
					//     .---------------------[removing_node:R]-----.                       
					//  [(S:B)]---------.                           [(L:B)]                    
					//                  .(最大子孫)                                            
					//         .--[replacing_node:B]--.                                        
					//      [(SLS)]                 (null)                                     
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//     .---------------------[replacing_node:B]----.                       
					//  [(S:B)]---------.                           [(L:B)]                    
					//                  .(最大子孫)                                            
					//               [(SLS)]                                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【色を調整】                         
					//     .---------------------[replacing_node:+R]----.                      
					//  [(S:B)]---------.                        ↑  [(L:B)]                   
					//                  .(最大子孫)             赤に                           
					//               [(SLS)]                                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(SLS)」とその兄弟で黒のバランスが崩れるので、                        
					//　「(SLS)」から調整（回転処理）が必要。                                  
					//-------------------------------------------------------------------------
					//【ケース②】                                                             
					//                    .------[removing_node:R]-----.                       
					//     .----[replacing_node:B]----.             [(L:B)]                    
					// [(SS:R/n)]                   (null)                                     
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//       .-------------------[replacing_node:B]----.                       
					//   [(SS:R/n)]----.                            [(L:B)]                    
					//               (null)                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【色を調整】                         
					//       .-------------------[replacing_node:+R]---.                       
					//   [(SS:R/n)]----.                            [(L:B)]                    
					//               (null)                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(SS:R/n)」と「(L:B)」で黒のバランスが崩れるので、                    
					//　「(SS:R/n)」から調整（回転処理）が必要。                               
					//-------------------------------------------------------------------------
					//【参考ケース①】※この状態は既に条件④に違反しているため、ありえない     
					//              .-----[removing_node:R]-----.                              
					//   .--[replacing_node:B]--.             (null)                           
					// [(SS)]                [(SL)]                                            
					//-------------------------------------------------------------------------
					//【参考ケース②】※この状態は既に条件④に違反しているため、ありえない     
					//      .-----[removing_node:R]-----.                                      
					//    (null)           .--[replacing_node:B]--.                            
					//                   [(LS)]                [(LL)]                          
					//-------------------------------------------------------------------------
					//【最終状態の特徴】                                                       
					//・置き換え元の位置で、黒のバランス（条件④）が崩れる。                   
					//・置き換え元の位置で、赤→赤の連結（条件③違反）が起こる可能性がある。   
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-RB-[%d:R]←[%d:B]=ROT>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					is_necessary_rotate = true;//回転処理必要
					ope_type::setRed(*replacing_node);//置き換えノードを赤にする
					//remove_node_is_black = true;//削除ノードは黒
					//                            //※置き換え元のノードが削除されたものとして処理する
				}
			}
		}
		else//if (remove_node_is_black)//削除ノードが黒の場合
		{
			if (!replacing_node)//置き換えノードがない場合
			{
				//【判定ケース[B-on-null]：削除ノードが黒、置き換えノードがない】：回転処理必要
				//-------------------------------------------------------------------------
				//    .--[removing_node:B]--.                                              
				// (null)                 (null)                                           
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//             ↓【削除】                                                  
				//           (null)                                                        
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//※黒が一つ減るので、                                                     
				//　親に遡って木の調整（回転処理）が必要。                                 
				//-------------------------------------------------------------------------
				//【最終状態の特徴】                                                       
				//・置き換え元の位置で、黒のバランス（条件④）が崩れる。                   
				//・置き換え元の位置で、赤→赤の連結（条件③違反）が起こる可能性がある。   
				//-------------------------------------------------------------------------
				printf_dbg_remove("<DEL-Bn-[%d:B]←(null)=ROT>", ope_type::getKey(*removing_node));
				is_necessary_rotate = true;//回転処理必要
			}
			else//if(replacing_node)//置き換えノードがある場合
			{
				if (!replace_node_is_black)//置き換えノードが赤の場合
				{
					//【判定ケース[B-on-R]：削除ノードが黒、置き換えノードが赤】：回転処理不要
					//-------------------------------------------------------------------------
					//【ケース①】                                                             
					//     .---------------------[removing_node:B]-----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//        .--[replacing_node:R]--.                                         
					//     [(SLS)]                (null)                                       
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//     .---------------------[replacing_node:R]----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【色を調整】                         
					//     .---------------------[replacing_node:+B]----.                      
					//   [(S)]---------.                       ↑     [(L)]                    
					//                 .(最大子孫)            黒に                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※結果的に黒が減らないので、木に影響がない。                             
					//-------------------------------------------------------------------------
					//【ケース②】                                                             
					//               .-----[removing_node:B]-----.                             
					//    .--[replacing_node:R]--.            [(L:R/n)]                        
					// [(null)]               [(null)]                                         
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【置き換え】                                 
					//               .-----[replacing_node:R]-----.                            
					//            [(null)]                     [(L:R/n)]                       
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【色を調整】                                 
					//               .-----[replacing_node:+B]----.                            
					//            [(null)]                 ↑  [(L:R/n)]                       
					//                                    黒に                                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※結果的に黒が減らないので、木に影響がない。                             
					//-------------------------------------------------------------------------
					//【ケース③】                                                             
					//      .-----[removing_node:B]-----.                                      
					//    (null)           .--[replacing_node:R]--.                            
					//                  [(null)]               [(null)]                        
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ↓【置き換え】                                       
					//      .-----[replacing_node:R]-----.                                     
					//   [(null)]                     [(null)]                                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ↓【色を調整】                                       
					//      .-----[replacing_node:+B]----.                                     
					//   [(null)]                ↑   [(null)]                                 
					//                         黒に                                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※結果的に黒が減らないので、木に影響がない。                             
					//-------------------------------------------------------------------------
					//【最終状態の特徴】                                                       
					//・赤黒の位置関係（条件③）も                                             
					//　黒のバランス（条件④）も崩れない。                                     
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-BR-[%d:B]←[%d:R]=END>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					//is_necessary_rotate = false;//回転処理不要
					ope_type::setBlack(*replacing_node);//置き換えノードを黒にする
					//remove_node_is_black = false;//削除ノードは赤
					//                             //※置き換え元のノードが削除されたものとして処理する
				}
				else//if (replace_node_is_black)//置き換えノードが黒の場合
				{
					//【範囲ケース[B-on-B]：削除ノードが黒、置き換えノードが黒】：回転処理必要
					//-------------------------------------------------------------------------
					//【ケース①】                                                             
					//     .---------------------[removing_node:B]-----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//        .--[replacing_node:B]--.                                         
					//     [(SLS)]              (null)                                         
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//     .---------------------[replacing_node:B]----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(SLS)」とその兄弟で黒のバランスが崩れるので、                        
					//　「(SLS)」から調整（回転処理）が必要。                                  
					//-------------------------------------------------------------------------
					//【ケース②】                                                             
					//                    .------[removing_node:B]-----.                       
					//     .----[replacing_node:B]----.              [(L)]                     
					// [(SS:R/n)]                   (null)                                     
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//       .-------------------[replacing_node:B]----.                       
					//   [(SS:R/n)]----.                             [(L)]                     
					//               (null)                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(SS:R/n)」と「(L)」で黒のバランスが崩れるので、                      
					//　「(SS:R/n)」から調整（回転処理）が必要。                               
					//-------------------------------------------------------------------------
					//【参考ケース①】※この状態は既に条件④に違反しているため、ありえない     
					//              .-----[removing_node:B]-----.                              
					//   .--[replacing_node:B]--.             (null)                           
					// [(SS)]                [(SL)]                                            
					//-------------------------------------------------------------------------
					//【参考ケース②】※この状態は既に条件④に違反しているため、ありえない     
					//      .-----[removing_node:B]-----.                                      
					//    (null)           .--[replacing_node:B]--.                            
					//                   [(LS)]              [(LL)]                            
					//-------------------------------------------------------------------------
					//【最終状態の特徴】                                                       
					//・赤黒の位置関係（条件③）は保たれるが、                                 
					//　黒のバランス（条件④）が崩れる。                                       
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-BB-[%d:B]←[%d:B]=ROT>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					is_necessary_rotate = true;//回転処理必要
				}
			}
		}
		//回転処理
		//※黒ノードが削除された時のみ回転を行う
		//-------------------------------------------------------------------------
		//【木の説明の凡例】
		//・「:B」は、黒を示す。
		//・「:R」は、赤を示す。
		//・「:?」は、黒もしくは赤を示す。
		//・「:?/n」は、黒もしくは赤、もしくは、ノードがないことを示す。
		//・「:B/n」は、黒、もしくは、ノードがないことを示す。
		//・「:-B」は、そのノード、もしくは、その子孫で、黒ノードの削除があったことを示す。
		//・「:+B」は、黒に変更することを示す。
		//・「:+R」は、赤に変更することを示す。
		//・「:+?」は、元の位置と同じ色に変更することを示す。
		//・「(S)」は、小（左）側のノードを示す。
		//・「(L)」は、大（右）側のノードを示す。
		//・「(SL)」は、小（左）側の子の大（右）側のノードを示す。
		//　（「(LS)」[(SS)」「(SSL)」などのパターンも同様）
		//・「(null)」は、ノードがないことを示す。
		//-------------------------------------------------------------------------
		if (is_necessary_rotate)
		{
			node_type* parent_node = nullptr;//親ノード
			node_type* parent_node_prev = nullptr;//前回のループ処理での親ノード
			bool curr_is_large = false;//親ノードからの連結方向
			while (true)
			{
				stack_info_type* parent_info = stack.pop();//親ノード情報を取得
				if (!parent_info)
					break;
				parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//親ノードを取得
				curr_is_large = parent_info->m_isLarge;//親ノードからの連結方向を取得
				if (parent_node_prev)//前回のループ処理での親ノードを親子連結
				{
					ope_type::setChild(*parent_node, curr_is_large, parent_node_prev);
					parent_node_prev = nullptr;//前回のループ処理での親ノードをクリア
				}
				if (is_necessary_rotate)//回転処理が必要
				{
					node_type* curr_node =//現在のノード取得 ※この側で黒ノードが一つ減少している
						parent_node ?
							ope_type::getChild_rc(*parent_node, curr_is_large) :
							nullptr;
					node_type* sibling_node =//兄弟ノード取得
						parent_node ?
							ope_type::getChild_rc(*parent_node, !curr_is_large) :
							nullptr;
					node_type* sibling_node_s =//兄弟ノードの小（左）側の子ノード取得
						sibling_node ?
							ope_type::getChildS_rc(*sibling_node) :
							nullptr;
					node_type* sibling_node_l =//兄弟ノードの大（右）側の子ノード取得
						sibling_node ?
							ope_type::getChildL_rc(*sibling_node) :
							nullptr;
					if (sibling_node)//兄弟ノードが存在する場合
					{
						if (!curr_is_large)//【ケース：［小（左）側：黒］が削除】
						{
							if (ope_type::isBlack(*sibling_node))//【ケース：削除側の兄弟が［大（右）側：黒］】
							{
								if (sibling_node_s && ope_type::isRed(*sibling_node_s))//【ケース：兄弟の子が［小（左）側の子：赤］】
								{
									//【回転ケース[S-1]：［削除：小（左）側：黒］→［兄弟：大（右）側：黒］→［小（左）側の子：赤］】
									//-------------------------------------------------------------------------------------------------
									//              .----------[parent_node:?]-------------------.                                     
									//        [curr_node:-B]                      .------[sibling_node:B]------.                       
									//                                   .--[sibling_node_s:R]--.      [sibling_node_l:?/n]            
									//                                [(LSS)]                [(LSL)]                                   
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【兄弟ノードを右回転】                                          
									//              .----------[parent_node:?]-------------------.                                     
									//        [curr_node:-B]                      .------[sibling_node_s:R]------.                     
									//                                         [(LSS)]                .--[sibling_node:B]--.           
									//                                                             [(LSL)]         [sibling_node_l:?/n]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【親ノードを左回転】                                            
									//              .----------[sibling_node_s:R]----------------.                                     
									//     .--[parent_node:?]--.                   .------[sibling_node:B]------.                      
									// [curr_node:-B]       [(LSS)]             [(LSL)]                 [sibling_node_l:?/n]           
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【色を調整】                                                    
									//                                         ↓元のparent_nodeと同じ色に                             
									//              .----------[sibling_node_s:+?]----------------.                                    
									//     .--[parent_node:+B]--.                   .------[sibling_node:B]------.                     
									// [curr_node:?]       ↑[(LSS)]             [(LSL)]                 [sibling_node_l:?/n]          
									//           ↑       黒に                                                                         
									//          上の「+B」により、この「-B」が解消                                                     
									//-------------------------------------------------------------------------------------------------
									//【最終状態の特徴】                                                                               
									//・赤黒の位置関係（条件③）は保たれる。                                                           
									//・部分木の小（左）側に黒が一つ増えることで、                                                     
									//　木全体のバランス（条件④）が回復し、木の調整は完了する。                                       
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//【初期状態の考察】                                                                               
									//・「curr_node」以下の黒の数は、                                                                  
									//　「sibling_node」以下の黒の数より一つ少ない。                                                   
									//・「(LSS)」以下と「(LSL)」以下と「sibling_node_l」以下の黒の数は、それぞれ                       
									//　「sibling_node」以下の黒の数より一つ少ない。                                                   
									//・「curr_node」以下と「(LSS)」以下と「(LSL)」以下と「sibling_node_l」以下の                      
									//　黒の数は、すべて同じ。                                                                         
									//・「curr_node」と「parent_node」が共に赤（条件③違反）の可能性がある。                           
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//【最終状態の考察】                                                                               
									//・部分木の大（右）側の黒の数は変化しない。                                                       
									//・部分木の小（左）側の黒の数は一つ増える。                                                       
									//・木全体の黒の数は変化しない。                                                                   
									//・初期状態で「curr_node」と「parent_node」が共に赤（条件③違反）だった場合、問題が解消される。   
									//-------------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-S1-[%d:?]→[%d:B]→[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_s));
									ope_type::setChildL(*parent_node, _rotateR<ope_type>(sibling_node));//兄弟ノードを右回転処理
									_rotateL<ope_type>(parent_node);//親ノードを左回転処理
									ope_type::setColor(*sibling_node_s, ope_type::getColor(*parent_node));//親ノードを元のparent_nodeと同じ色に
									ope_type::setBlack(*parent_node);//削除側ノードを黒に
									parent_node_prev = sibling_node_s;//親ノードを記録（次のループ処理の親の子に連結する）
									is_necessary_rotate = false;//調整完了
								}
								else if (sibling_node_l && ope_type::isRed(*sibling_node_l))//【ケース：兄弟の子が［大（右）側の子：赤］】
								{
									//【回転ケース[S-2]：［削除：小（左）側：黒］→［兄弟：大（右）側：黒］→［大（右）側の子：赤］】
									//-----------------------------------------------------------------------------------------
									//              .----------[parent_node:?]-------------------.                             
									//        [curr_node:-B]                      .------[sibling_node:B]------.               
									//                                      [sibling_node_s:B/n]    .--[sibling_node_l:R]--.   
									//                                                           [(LLS)]                [(LLL)]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【親ノードを左回転】                                    
									//              .-----------[sibling_node:B]----------------.                              
									//     .--[parent_node:?]--.                  .------[sibling_node_l:R]------.             
									// [curr_node:-B] [sibling_node_s:B/n]     [(LLS)]                        [(LLL)]          
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【色を調整】                                            
									//                                        ↓元のparent_nodeと同じ色に                      
									//              .-----------[sibling_node:+?]----------------.                             
									//     .--[parent_node:+B]--.                 .------[sibling_node_l:+B]-----.             
									// [curr_node:?]  [sibling_node_s:B/n]     [(LLS)]                   ↑   [(LLL)]          
									//           ↑       ↑黒に                                        黒に                   
									//          上の「+B」により、この「-B」が解消                                             
									//-----------------------------------------------------------------------------------------
									//【最終状態の特徴】                                                                       
									//・赤黒の位置関係（条件③）は保たれる。                                                   
									//・部分木の小（左）側に黒が一つ増えることで、                                             
									//　木全体のバランス（条件④）が回復し、木の調整は完了する。                               
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//【初期状態の考察】                                                                       
									//・「curr_node」以下の黒の数は、                                                          
									//　「sibling_node」以下の黒の数より一つ少ない。                                           
									//・「(LLS)」以下と「(LLL)」以下と「sibling_node_s」以下の黒の数は、それぞれ               
									//　「sibling_node」以下の黒の数より一つ少ない。                                           
									//・「curr_node」以下と「(LLS)」以下と「(LLL)」以下と「sibling_node_s」以下の              
									//　黒の数は、すべて同じ。                                                                 
									//・「curr_node」と「parent_node」が共に赤（条件③違反）の可能性がある。                           
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//【最終状態の考察】                                                                       
									//・部分木の大（右）側の黒の数は変化しない。                                               
									//・部分木の小（左）側の黒の数は一つ増える。                                               
									//・木全体の黒の数は変化しない。                                                           
									//・初期状態で「curr_node」と「parent_node」が共に赤（条件③違反）だった場合、問題が解消される。
									//-----------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-S2-[%d:?]→[%d:B]→[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_l));
									_rotateL<ope_type>(parent_node);//親ノードを左回転処理
									ope_type::setColor(*sibling_node, ope_type::getColor(*parent_node));//親ノードを元のparent_nodeと同じ色に
									ope_type::setBlack(*parent_node);//削除側ノードを黒に
									ope_type::setBlack(*sibling_node_l);//兄弟ノードを黒に
									parent_node_prev = sibling_node;//親ノードを記録（次のループ処理の親の子に連結する）
									is_necessary_rotate = false;//調整完了
								}
								else//【ケース：兄弟の子が大小（左右）両方とも黒もしくはヌル】
								{
									if (ope_type::isRed(*parent_node))//【ケース：削除ノードの親が赤】
									{
										//【回転ケース[S-3a]：［削除：小（左）側：黒］→［親：赤］→［兄弟：大（右）側：黒］→［大小（左右）両側の子：赤以外］】
										//------------------------------------------------------------------------------
										//       .----------[parent_node:R]-------------------.                         
										// [curr_node:-B]                      .------[sibling_node:B]------.           
										//                               [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ------
										//                        ↓【色を調整】                                        
										//       .----------[parent_node:+B]-------------------.   ↓赤に               
										// [curr_node:?]             黒に↑   .------[sibling_node:+R]------.           
										//           ↑                  [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//           上の「+B」により、この「-B」が解消                                 
										//------------------------------------------------------------------------------
										//【最終状態の特徴】                                                            
										//・赤黒の位置関係（条件③）は保たれる。                                        
										//・部分木の大（右）側の黒が一つ減ることで、                                    
										//　部分木のバランスが回復し、                                                  
										//　更に、部分木の根に黒が一つ増えることで、                                    
										//　木全体のバランス（条件④）が回復し、木の調整は完了する。                    
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
										//【初期状態の考察】                                                            
										//・「curr_node」以下の黒の数は、                                               
										//　「sibling_node」以下の黒の数より一つ少ない。                                
										//・「sibling_node_s」以下と「sibling_node_l」以下の黒の数は、                  
										//　それぞれ「sibling_node」以下の黒の数より一つ少ない。                        
										//・「curr_node」以下と「sibling_node_s」以下と「sibling_node_l」以下の         
										//　黒の数は、すべて同じ。                                                      
										//・「curr_node」と「parent_node」が共に赤（条件③違反）の可能性がある。                           
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
										//【最終状態の考察】                                                            
										//・部分木の大（右）側の黒の数は±０。                                          
										//・部分木の小（左）側の黒の数は一つ増える。                                    
										//・木全体の黒の数は変化しない。                                                
										//・初期状態で「curr_node」と「parent_node」が共に赤（条件③違反）だった場合、問題が解消される。
										//------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-S3a-[%d:R]→[%d:B]→[*:B/n]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setBlack(*parent_node);//親ノードを黒に
										ope_type::setRed(*sibling_node);//兄弟ノードを赤に
										parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
										is_necessary_rotate = false;//調整完了
									}
									else//if (ope_type::isBlack(*parent_node))//【ケース：削除ノードの親が黒】
									{
										//【回転ケース[S-3b]：［削除：小（左）側：黒］→［親：黒］→［兄弟：大（右）側：黒］→［大小（左右）両側の子：赤以外］】
										//-------------------------------------------------------------------------------------
										//              .----------[parent_node:B]-------------------.                         
										//        [curr_node:-B]                      .------[sibling_node:B]------.           
										//                                      [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                               ↓【色を調整】                                        
										//              .----------[parent_node:B]--------------------.   ↓赤に               
										//        [curr_node:?]                      .------[sibling_node:+R]------.           
										//                  ↑                  [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//                  右の「+R」により、この「-B」が解消（右側も黒が減ったので）         
										//-------------------------------------------------------------------------------------
										//【最終状態の特徴】                                                                   
										//・赤黒の位置関係（条件③）は保たれる。                                               
										//・部分木の大（右）側の黒が一つ減ることで、                                           
										//　部分木のバランスが回復するが、                                                     
										//　部分木全体では黒が一つ減った状態のため、                                           
										//　親に遡って木の調整が必要。                                                         
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//【初期状態の考察】                                                                   
										//・「curr_node」以下の黒の数は、                                                      
										//　「sibling_node」以下の黒の数より一つ少ない。                                       
										//・「sibling_node_s」以下と「sibling_node_l」以下の黒の数は、                         
										//　それぞれ「sibling_node」以下の黒の数より一つ少ない。                               
										//・「curr_node」以下と「sibling_node_s」以下と「sibling_node_l」以下の                
										//　黒の数は、すべて同じ。                                                             
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//【最終状態の考察】                                                                   
										//・部分木の大（右）側の黒の数は一つ減る。                                             
										//・部分木の小（左）側の黒の数は変わらない。                                           
										//・部分木のバランスは取れるが、                                                       
										//　部分木全体で黒の数が一つ少ない。                                                   
										//-------------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-S3b-[%d:B]→[%d:B]→[*:B/n]=NEXT>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setRed(*sibling_node);//兄弟ノードを赤に
										parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
										//is_necessary_rotate = true;//調整続行
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//【ケース：削除側の兄弟が［大（右）側：赤］】
							{
								//※兄弟が赤であるため、「条件③」により、必然的に親は黒になる
								//【回転ケース[S-4]：［削除：小（左）側：黒］→［親：黒］→［兄弟：大（右）側：赤］】
								//--------------------------------------------------------------------------------------
								//                 .--------------[parent_node:B]---------------.                       
								//        [curr_node:-B]                         .------[sibling_node:R]------.         
								//                                         [sibling_node_s:B]       [sibling_node_l:B]  
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                      ↓【親ノードを左回転】                          
								//                 .--------------[sibling_node:R]--------------.                       
								//      .----[parent_node:B]----.                      [sibling_node_l:B]               
								// [curr_node:-B]   [sibling_node_s:B]                                                  
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                      ↓【色を調整】                                  
								//                 .--------------[sibling_node:+B]-------------.                       
								//      .----[parent_node:+R]----.              ↑黒に [sibling_node_l:B]               
								// [curr_node:-B]   [sibling_node_s:B]                                                  
								//            ↑          ↑赤に（curr_nodeが赤だと、「条件③」が崩れる）               
								//            この「-B」は解消されない                                                  
								//--------------------------------------------------------------------------------------
								//【最終状態の特徴】                                                                    
								//・赤黒の位置関係（条件③）が崩れる可能性があるが、                                    
								//　この後の処理で必ずcurr_nodeの親が黒になるので問題ない。                             
								//・部分木のバランスは回復しない。                                                      
								//・この状態のparent_nodeとcurr_node部分木に対して、                                    
								//　再帰的に【ケース[①～③]】を実行すると、部分木の                                    
								//　バランスが保たれる。                                                                
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//【初期状態の考察】                                                                    
								//・「curr_node」以下の黒の数は、                                                       
								//　「sibling_node_s」／「sibling_node_l」以下の黒の数より一つ少ない。                  
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//【最終状態の考察】                                                                    
								//・部分木の大（右）側の黒の数は変化しない。                                            
								//・部分木の小（左）側はバランスが崩れるため、                                          
								//　さらにその部分木でバランスを調整する。                                              
								//--------------------------------------------------------------------------------------
								printf_dbg_remove("<ROT-S4-[%d:B]→[%d:R]→[*:B/n]=RETRY>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
								_rotateL<ope_type>(parent_node);//親ノードを左回転処理
								ope_type::setRed(*parent_node);//削除側ノードを赤に
								ope_type::setBlack(*sibling_node);//親ノードを黒に
								stack_info_type* ancestor_info = stack.top();//スタックから現在の親情報を取得
								const bool parent_is_large = ancestor_info ? ancestor_info->m_isLarge : false;//親の親からの連結方向
								if (ancestor_info)
								{
									node_type* ancestor_node = const_cast<node_type*>(ancestor_info->m_nodeRef);
									ope_type::setChild(*ancestor_node, parent_is_large, sibling_node);//親の親に新しい親を連結
								}
								stack.push(sibling_node, false);//もう一度同じ部分木を回転操作するために、兄弟ノードをスタックにプッシュ
								stack.push(parent_node, false);//もう一度同じ部分木を回転操作するために、親ノードをスタックにプッシュ
								parent_node_prev = curr_node;//親ノードを記録（次のループ処理の親の子に連結する）
								//is_necessary_rotate = true;//再帰的に調整続行
							}
						}
						else//if (curr_is_large)//【ケース：［大（右）側：黒］が削除】
						{
							if (ope_type::isBlack(*sibling_node))//【ケース：削除側の兄弟が［小（左）側：黒］】
							{
								if (sibling_node_l && ope_type::isRed(*sibling_node_l))//【ケース：兄弟の子が［大（右）側の子：赤］】
								{
									//【回転ケース[L-1]：［削除：大（右）側：黒］→［兄弟：小（左）側：黒］→［大（右）側の子：赤］】
									//--------------------------------------------------------------------------------------------
									//                               .-------------------[parent_node:?]----------.               
									//                 .------[sibling_node:B]------.                      [curr_node:-B]         
									//       [sibling_node_s:?/n]      .--[sibling_node_l:R]--.                                   
									//                              [(SLS)]                [(SLL)]                                
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ↓【兄弟ノードを左回転】           
									//                               .-------------------[parent_node:?]----------.               
									//                 .------[sibling_node_l:R]------.                    [curr_node:-B]         
									//           .--[sibling_node:B]--.            [(SLL)]                                        
									// [sibling_node_s:?/n]        [(SLS)]                                                        
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ↓【親ノードを右回転】             
									//                               .-----------------[sibling_node_l:R]---------.               
									//                 .------[sibling_node:B]------.                .--[parent_node:?]--.        
									//           [sibling_node_s:?/n]            [(SLS)]          [(SLL)]          [curr_node:-B] 
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ↓【色を調整】                     
									//                                                                 ↓元のparent_nodeと同じ色に
									//                               .-----------------[sibling_node_l:+?]--------.  ↓黒に       
									//                 .------[sibling_node:B]------.                .--[parent_node:+B]--.       
									//           [sibling_node_s:?/n]            [(SLS)]          [(SLL)]          [curr_node:?]  
									//                                                     上の「+B」により、この「-B」が解消↑   
									//--------------------------------------------------------------------------------------------
									//※調整完了。                                                                                
									//※説明は省略。【ケース[S-1]】と同じ                                                         
									//--------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-L1-[%d:?]→[%d:B]→[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_l));
									ope_type::setChildS(*parent_node, _rotateL<ope_type>(sibling_node));//兄弟ノードを左回転処理
									_rotateR<ope_type>(parent_node);//親ノードを右回転処理
									ope_type::setColor(*sibling_node_l, ope_type::getColor(*parent_node));//親ノードを元のparent_nodeと同じ色に
									ope_type::setBlack(*parent_node);//削除側ノードを黒に
									parent_node_prev = sibling_node_l;//親ノードを記録（次のループ処理の親の子に連結する）
									is_necessary_rotate = false;//調整完了
								}
								else if (sibling_node_s && ope_type::isRed(*sibling_node_s))//【ケース：兄弟の子が［小（左）側の子：赤］】
								{
									//【回転ケース[L-2]：［削除：大（右）側：黒］→［兄弟：小（左）側：黒］→［小（左）側の子：赤］】
									//---------------------------------------------------------------------------------------------
									//                               .-------------------[parent_node:?]----------.                
									//                 .------[sibling_node:B]------.                      [curr_node:-B]          
									//    .--[sibling_node_s:R]--.      [sibling_node_l:B/n]                                       
									// [(SLS)]                [(SLL)]                                                              
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                                                        ↓【親ノードを右回転】               
									//                               .------------------[sibling_node:R]----------.                
									//                 .------[sibling_node_s:R]------.                .--[parent_node:?]--.       
									//              [(SLS)]                        [(SLL)]    [sibling_node_l:B/n]   [curr_node:-B]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -                    
									//                                                        ↓【色を調整】                       
									//                                                                ↓元のparent_nodeと同じ色に  
									//                               .------------------[sibling_node:+?]---------.   ↓黒に       
									//                 .------[sibling_node_s:+B]-----.               .--[parent_node:+B]--.       
									//              [(SLS)]                   ↑   [(SLL)]    [sibling_node_l:B/n]   [curr_node:?] 
									//                                       黒に            上の「+B」により、この「-B」が解消↑  
									//---------------------------------------------------------------------------------------------
									//※調整完了。                                                                                 
									//※説明は省略。【ケース[S-2]】と同じ                                                          
									//---------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-L2-[%d:?]→[%d:B]→[%d:R]=OK>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_s));
									_rotateR<ope_type>(parent_node);//親ノードを右回転処理
									ope_type::setColor(*sibling_node, ope_type::getColor(*parent_node));//親ノードを元のparent_nodeと同じ色に
									ope_type::setBlack(*parent_node);//削除側ノードを黒に
									ope_type::setBlack(*sibling_node_s);//兄弟ノードを黒に
									parent_node_prev = sibling_node;//親ノードを記録（次のループ処理の親の子に連結する）
									is_necessary_rotate = false;//調整完了
								}
								else//【ケース：兄弟の子が大小（左右）両方とも黒もしくはヌル】
								{
									if (ope_type::isRed(*parent_node))//【ケース：削除ノードの親が赤】
									{
										//【回転ケース[L-3a]：［削除：大（右）側：黒］→［親：赤］→［兄弟：小（左）側：黒］→［大小（左右）両側の子：赤以外］】
										//---------------------------------------------------------------------------------
										//                       .-------------------[parent_node:R]----------.            
										//         .------[sibling_node:B]------.                      [curr_node:-B]      
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]                                   
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                                                 ↓【色を調整】                  
										//                       .-------------------[parent_node:+B]---------.            
										//         .------[sibling_node:+B]-----.                 ↑   [curr_node:?]       
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]         黒に			 ↑        
										//                              ↑赤に                         上の「 + B」により、
										//                                                             この「 - B」が解消  
										//---------------------------------------------------------------------------------
										//※調整完了。                                                                     
										//※説明は省略。【ケース[S-3a]】と同じ                                             
										//---------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-L3a-[%d:R]→[%d:B]→[*:B/n]=OK>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setBlack(*parent_node);//親ノードを黒に
										ope_type::setRed(*sibling_node);//兄弟ノードを赤に
										parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
										is_necessary_rotate = false;//調整完了
									}
									else//if (ope_type::isBlack(*parent_node))//【ケース：削除ノードの親が黒】
									{
										//【回転ケース[L-3b]：［削除：大（右）側：黒］→［親：黒］→［兄弟：小（左）側：黒］→［大小（左右）両側の子：赤以外］】
										//---------------------------------------------------------------------------
										//                       .-------------------[parent_node:B]----------.      
										//         .------[sibling_node:B]------.                      [curr_node:-B]
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]                             
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                                                 ↓【色を調整】            
										//                       .-------------------[parent_node:B]---------.       
										//         .------[sibling_node:+R]-----.                      [curr_node:?] 
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]       左の「+R」により、↑  
										//                              ↑赤に                 この「-B」が解消      
										//                                                   （左側も黒が減ったので）
										//---------------------------------------------------------------------------
										//※調整続行。                                                               
										//※説明は省略。【ケース[S-3b]】と同じ                                       
										//---------------------------------------------------------------------------
										printf_dbg_remove("<ROT-L3b-[%d:B]→[%d:B]→[*:B/n]=NEXT>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setRed(*sibling_node);//兄弟ノードを赤に
										parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
										//is_necessary_rotate = true;//調整続行
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//【ケース：削除側の兄弟が［小（左）側：赤］】
							{
								//※兄弟が赤であるため、「条件③」により、必然的に親は黒になる
								//【回転ケース[L-4]：［削除：大（右）側：黒］→［親：黒］→［兄弟：小（左）側：赤］】
								//--------------------------------------------------------------------------------------------------------
								//                         .-------------------[parent_node:B]----------.                                 
								//           .------[sibling_node:R]------.                      [curr_node:-B]                           
								// [sibling_node_s:B]          [sibling_node_l:B]                                                         
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                                   ↓【親ノードを右回転】                               
								//                         .------------------[sibling_node:R]----------.                                 
								//                 [sibling_node_s:B]                         .--[parent_node:B]--.                       
								//                                                    [sibling_node_l:B]     [curr_node:-B]               
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                                   ↓【色を調整】                                       
								//                         .-----------------[sibling_node:+B]----------.     ↓赤に（curr_nodeが赤だと、 
								//                 [sibling_node_s:B]                  黒に↑ .--[parent_node:+R]--.  「条件③」が崩れる）
								//                                                    [sibling_node_l:B]     [curr_node:-B]               
								//                                                                                      ↑                
								//                                                                 この「-B」は解消されない               
								//--------------------------------------------------------------------------------------------------------
								//※再帰的に調整続行。                                                                                    
								//※説明は省略。【ケース[S-4]】と同じ                                                                     
								//--------------------------------------------------------------------------------------------------------
								printf_dbg_remove("<ROT-L4-[%d:B]→[%d:R]→[*:B/n]=RETRY>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
								_rotateR<ope_type>(parent_node);//親ノードを右回転処理
								ope_type::setRed(*parent_node);//削除側ノードを赤に
								ope_type::setBlack(*sibling_node);//親ノードを黒に
								stack_info_type* ancestor_info = stack.top();//スタックから現在の親情報を取得
								const bool parent_is_large = ancestor_info ? ancestor_info->m_isLarge : false;//親の親からの連結方向
								if (ancestor_info)
								{
									node_type* ancestor_node = const_cast<node_type*>(ancestor_info->m_nodeRef);
									ope_type::setChild(*ancestor_node, parent_is_large, sibling_node);//親の親に新しい親を連結
								}
								stack.push(sibling_node, true);//もう一度同じ部分木を回転操作するために、兄弟ノードをスタックにプッシュ
								stack.push(parent_node, true);//もう一度同じ部分木を回転操作するために、親ノードをスタックにプッシュ
								parent_node_prev = curr_node;//親ノードを記録（次のループ処理の親の子に連結する）
								//is_necessary_rotate = true;//再帰的に調整続行
							}
						}
					}
					else//if (!sibling_node)//兄弟ノードが存在しない場合
					{
						//黒ノード（削除対象ノード）の兄弟ノードが存在しないことは本来ありえない
						//※「条件④」により、根から葉までのあらゆる経路で黒の数は一定のため、
						//　黒ノードを削除した場合、必ず兄弟ノードもしくはその子孫に黒がいる。
						printf_dbg_remove("【赤黒木にバグあり！】黒ノード（削除）の兄弟ノードが存在しない\n");
						assert(sibling_node != nullptr);
						parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
					}
				}
				else//if (!is_necessary_rotate)//回転処理が不要
				{
					parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
				}
			}
			if (parent_node_prev)
			{
				root = parent_node_prev;
				ope_type::setBlack(*root);
			}
		}
	}

	//----------------------------------------
	//赤黒木コンテナ
	//※根ノードを持つのみ
	//※std::mapを模した構造
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
			inline operator key_type() const { return ope_type::getKey(*getNode()); }
		public:
			//オペレータ
			inline const_reference operator*() const { return *getNode(); }
			inline reference operator*(){ return *getNode(); }
			inline const_pointer operator->() const { return getNode(); }
			inline pointer operator->(){ return getNode(); }
		#if 1//std::bidirectional_iterator_tag には本来必要ではない
			inline const_iterator operator[](const int index) const
			{
				iterator ite(m_root, false);
				ite += index;
				return std::move(ite);
			}
			inline iterator operator[](const int index)
			{
				iterator ite(m_root, false);
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
				       ope_type::eq(*m_node, *rhs);
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? false :
				       m_isEnd || rhs.m_isEnd ? true :
				       ope_type::ne(*m_node, *rhs);
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && !rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       ope_type::gt(*m_node, *rhs);
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd && !rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       ope_type::ge(*m_node, *rhs);
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       !m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       ope_type::lt(*m_node, *rhs);
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       !m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       ope_type::le(*m_node, *rhs);
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
		public:
			//ムーブオペレータ
			inline iterator& operator=(const_iterator&& rhs)
			{
				m_stack = std::move(rhs.m_stack);
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			iterator& operator=(const_reverse_iterator&& rhs);
			//コピーオペレータ
			inline iterator& operator=(const_iterator& rhs)
			{
				m_stack = rhs.m_stack;
				m_root = rhs.m_root;
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
			inline const node_type* getRoot() const { return m_root; }//根ノード
			inline node_type* getRoot(){ return m_root; }//根ノード
			inline const node_type* getNode() const { return m_node; }//現在のノード
			inline node_type* getNode(){ return m_node; }//現在のノード
		private:
			//メソッド
			inline void updateNext() const
			{
				node_type* prev = m_node;
				m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
				m_isEnd = (prev && !m_node);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					m_stack.reset();
					m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
					m_isEnd = false;
					return;
				}
				m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
				m_isEnd = false;
			}
			void updateForward(const int step) const
			{
				int _step = step;
				node_type* prev = m_node;
				while (_step > 0 && m_node)
				{
					m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
					--_step;
				}
				m_isEnd = (prev && !m_node && _step == 0);
			}
			void updateBackward(const int step) const
			{
				int _step = step;
				if (_step > 0 && m_isEnd)
				{
					m_stack.reset();
					m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
					--_step;
				}
				while (_step > 0 && m_node)
				{
					m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
					--_step;
				}
				m_isEnd = false;
			}
		public:
			//ムーブコンストラクタ
			inline iterator(const_iterator&& obj) :
				m_stack(std::move(obj.m_stack)),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			iterator(const_reverse_iterator&& obj);
			//コピーコンストラクタ
			inline iterator(const_iterator& obj) :
				m_stack(obj.m_stack),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			iterator(const_reverse_iterator& obj);
			//コンストラクタ
			inline iterator(const node_type* root, const bool is_end) :
				m_stack(),
				m_root(root),
				m_node(nullptr),
				m_isEnd(is_end)
			{
				if (!is_end)
					m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
			}
			inline iterator(stack_type&& stack, const node_type* root, node_type* node, const bool is_end) :
				m_stack(std::move(stack)),
				m_root(root),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline iterator(stack_type& stack, const node_type* root, node_type* node, const bool is_end) :
				m_stack(stack),
				m_root(root),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline iterator() :
				m_stack(),
				m_root(nullptr),
				m_node(nullptr),
				m_isEnd(false)
			{}
			//デストラクタ
			inline ~iterator()
			{}
		protected:
			//フィールド
			mutable stack_type m_stack;//スタック
			const node_type* m_root;//根ノード
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
			inline operator key_type() const { return ope_type::getKey(*getNode()); }
		public:
			//オペレータ
			inline const_reference operator*() const { return *getNode(); }
			inline reference operator*(){ return *getNode(); }
			inline const_pointer operator->() const { return getNode(); }
			inline pointer operator->(){ return getNode(); }
		#if 1//std::bidirectional_iterator_tag には本来必要ではない
			inline const_reverse_iterator operator[](const int index) const
			{
				reverse_iterator ite(m_root, false);
				ite += index;
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(m_root, false);
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
				       ope_type::eq(*rhs, *m_node);
			}
			inline bool operator!=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? false :
				       rhs.m_isEnd || m_isEnd ? true :
					   ope_type::ne(*rhs, *m_node);
			}
			inline bool operator>(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && !m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       ope_type::gt(*rhs, *m_node);
			}
			inline bool operator>=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd && !m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       ope_type::ge(*rhs, *m_node);
			}
			inline bool operator<(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       !rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       ope_type::lt(*rhs, *m_node);
			}
			inline bool operator<=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       !rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       ope_type::le(*rhs, *m_node);
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
		public:
			//ムーブオペレータ
			inline reverse_iterator& operator=(const_reverse_iterator&& rhs)
			{
				m_stack = std::move(rhs.m_stack);
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator&& rhs)
			{
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = false;
				if (m_node)
				{
					m_stack = std::move(rhs.m_stack);
					++(*this);
				}
				else
				{
					m_stack.reset();
					if (rhs.m_isEnd)
						m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
				}
				return *this;
			}
			//コピーオペレータ
			inline reverse_iterator& operator=(const_reverse_iterator& rhs)
			{
				m_stack = rhs.m_stack;
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator& rhs)
			{
				m_root = rhs.m_root;
				m_node = rhs.m_node;
				m_isEnd = false;
				if (m_node)
				{
					m_stack = rhs.m_stack;
					++(*this);
				}
				else
				{
					m_stack.reset();
					if (rhs.m_isEnd)
						m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
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
			inline const node_type* getRoot() const { return m_root; }//根ノード
			inline node_type* getRoot(){ return m_root; }//根ノード
			inline const node_type* getNode() const { return m_node; }//現在のノード
			inline node_type* getNode(){ return m_node; }//現在のノード
		public:
			//メソッド
			inline void updateNext() const
			{
				node_type* prev = m_node;
				m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
				m_isEnd = (prev && !m_node);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					m_stack.reset();
					m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
					m_isEnd = false;
					return;
				}
				m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
				m_isEnd = false;
			}
			void updateForward(const int step) const
			{
				int _step = step;
				node_type* prev = m_node;
				while (_step > 0 && m_node)
				{
					m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
					--_step;
				}
				m_isEnd = (prev && !m_node && _step == 0);
			}
			void updateBackward(const int step) const
			{
				int _step = step;
				if (_step > 0 && m_isEnd)
				{
					m_stack.reset();
					m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
					--_step;
				}
				while (_step > 0 && m_node)
				{
					m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
					--_step;
				}
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
				m_stack(std::move(obj.m_stack)),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator&& obj) :
				m_stack(),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(false)
			{
				if (m_node)
				{
					m_stack = std::move(obj.m_stack);
					++(*this);
				}
				else
				{
					m_stack.reset();
					if (obj.m_isEnd)
						m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
				}
			}
			//コピーコンストラクタ
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_stack(obj.m_stack),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_stack(),
				m_root(obj.m_root),
				m_node(obj.m_node),
				m_isEnd(obj.m_isEnd)
			{
				if (m_node)
				{
					m_stack = obj.m_stack;
					++(*this);
				}
				else
				{
					m_stack.reset();
					if (obj.m_isEnd)
						m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
				}
			}
			//コンストラクタ
			inline reverse_iterator(const node_type* root, const bool is_end) :
				m_stack(),
				m_root(root),
				m_node(nullptr),
				m_isEnd(is_end)
			{
				if (!is_end)
					m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, m_stack));
			}
			inline reverse_iterator(stack_type&& stack, const node_type* root, node_type* node, const bool is_end) :
				m_stack(std::move(stack)),
				m_root(root),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline reverse_iterator(stack_type& stack, const node_type* root, node_type* node, const bool is_end) :
				m_stack(stack),
				m_root(root),
				m_node(node),
				m_isEnd(is_end)
			{}
			inline reverse_iterator() :
				m_stack(),
				m_root(nullptr),
				m_node(nullptr),
				m_isEnd(false)
			{}
			//デストラクタ
			inline ~reverse_iterator()
			{}
		protected:
			//フィールド
			mutable stack_type m_stack;//スタック
			const node_type* m_root;//根ノード
			mutable node_type* m_node;//現在のノード
			mutable bool m_isEnd;//終端か？
		};
	public:
		//アクセッサ
		inline const node_type* root() const { return m_root; }//根ノードを取得
		inline node_type* root(){ return m_root; }//根ノードを取得
		inline node_type*& root_ref(){ return m_root; }//根ノードの参照を取得
	public:
		//キャストオペレータ
		inline operator lock_type&(){ return m_lock; }//ロックオブジェクト
		inline operator lock_type&() const { return m_lock; }//ロックオブジェクト ※mutable
	public:
		//メソッド：イテレータ系
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
		inline const_iterator cbegin() const
		{
			iterator ite(m_root, false);
			return std::move(ite);
		}
		inline const_iterator cend() const
		{
			iterator ite(m_root, true);
			return std::move(ite);
		}
		inline const_iterator begin() const
		{
			iterator ite(m_root, false);
			return std::move(ite);
		}
		inline const_iterator end() const
		{
			iterator ite(m_root, true);
			return std::move(ite);
		}
		inline iterator begin()
		{
			iterator ite(m_root, false);
			return std::move(ite);
		}
		inline iterator end()
		{
			iterator ite(m_root, true);
			return std::move(ite);
		}
		//メソッド：リバースイテレータ系
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
		inline const_reverse_iterator crbegin() const
		{
			reverse_iterator ite(m_root, false);
			return std::move(ite);
		}
		inline const_reverse_iterator crend() const
		{
			reverse_iterator ite(m_root, true);
			return std::move(ite);
		}
		inline const_reverse_iterator rbegin() const
		{
			reverse_iterator ite(m_root, false);
			return std::move(ite);
		}
		inline const_reverse_iterator rend() const
		{
			reverse_iterator ite(m_root, true);
			return std::move(ite);
		}
		inline reverse_iterator rbegin()
		{
			reverse_iterator ite(m_root, false);
			return std::move(ite);
		}
		inline reverse_iterator rend()
		{
			reverse_iterator ite(m_root, true);
			return std::move(ite);
		}
		//メソッド：容量系
		//inline std::size_t max_size() const { return (不定); }
		//inline std::size_t capacity() const { return (不定); }
		inline std::size_t size() const { return countNodes<ope_type>(m_root); }//ノード数を取得
		inline bool empty() const { return m_root == nullptr; }//木が空か？
		inline int depth_max() const { return getDepthMax<ope_type>(m_root); }//木の深さを取得
		//メソッド：要素アクセス系
		//※std::mapと異なり、ノードのポインタを返す
		const node_type* at(const key_type key) const
		{
			stack_type stack;
			return searchNode<ope_type>(m_root, key, stack, FOR_MATCH);
		}
		inline node_type* at(const key_type key){ return const_cast<node_type*>(const_cast<const container*>(this)->at(key)); }
		inline const node_type* operator[](const key_type key) const { return at(key); }
		inline node_type* operator[](const key_type key){ return at(key); }
		//メソッド：追加／削除系
		//※std::mapと異なり、ノードを直接指定し、結果をbool型で受け取る
		//※要素のメモリ確保／削除を行わない点に注意
		//※処理中、排他ロック（ライトロック）を取得する
		inline node_type* insert(const node_type& node)
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			return addNode<ope_type>(const_cast<node_type*>(&node), m_root);
		}
		inline node_type* erase(const node_type& node)
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			return removeNode<ope_type>(&node, m_root);
		}
		inline node_type* erase(const key_type key)
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			return removeNode<ope_type>(at(key), m_root);
		}
		node_type* clear()
		{ 
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			node_type* root = m_root;
			m_root = nullptr;
			return root;
		}
		//メソッド：検索系
		//※lower_bound(), upper_bound()には非対応
		//※代わりに、find_nearestに対応
		inline const_iterator& _find(const_iterator& ite, const key_type key, const match_type_t type = FOR_MATCH) const
		{
			ite.m_node = const_cast<node_type*>(searchNode<ope_type>(m_root, key, ite.m_stack, type));
			return ite;
		}
		inline const_iterator find(const key_type key, const match_type_t type = FOR_MATCH) const
		{
			const_iterator ite;
			return std::move(_find(ite, key, type));
		}
		inline iterator find(const key_type key, const match_type_t type = FOR_MATCH)
		{
			iterator ite;
			return std::move(_find(ite, key, type));
		}
		inline std::size_t count(const key_type key) const { return countNodes<ope_type>(m_root, key); }
		const_iterator& _equal_range(const_iterator& ite, const key_type key) const
		{
			ite.m_node = const_cast<node_type*>(searchNode<ope_type>(m_root, key, ite.m_stack, FOR_MATCH));
			while (ite.m_node && ope_type::getKey(*ite) == key)
				++ite;
			return ite;
		}
		inline const_iterator equal_range(const key_type key) const
		{
			const_iterator ite;
			return std::move(_equal_range(ite, key));
		}
		inline iterator equal_range(const key_type key)
		{
			iterator ite;
			return std::move(_equal_range(ite, key));
		}
	public:
		//ムーブコンストラクタ
		container(const container&& con) :
			m_root(con.m_root)
		{}
		//コピーコンストラクタ
		container(const container& con) :
			m_root(con.m_root)
		{}
		//コンストラクタ
		container() :
			m_root(nullptr)
		{}
		//デストラクタ
		~container()
		{}
	private:
		//フィールド
		node_type* m_root;//根ノード
		mutable lock_type m_lock;//ロックオブジェクト
	};
	//イテレータのムーブオペレータ
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator&& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator&& rhs)//VC++もOK
	{
		m_root = rhs.m_root;
		m_node = rhs.m_node;
		m_isEnd = false;
		if (m_node)
		{
			m_stack = std::move(rhs.m_stack);
			++(*this);
		}
		else
		{
			m_stack.reset();
			if (rhs.m_isEnd)
				m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
		}
		return *this;
	}
	//イテレータのコピーオペレータ
	template<class OPE_TYPE>
	//typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(typename container<OPE_TYPE>::const_reverse_iterator& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE>::iterator& container<OPE_TYPE>::iterator::operator=(const typename container<OPE_TYPE>::reverse_iterator& rhs)//VC++もOK
	{
		m_root = rhs.m_root;
		m_node = rhs.m_node;
		m_isEnd = false;
		if (m_node)
		{
			m_stack = rhs.m_stack;
			++(*this);
		}
		else
		{
			m_stack.reset();
			if (rhs.m_isEnd)
				m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
		}
		return *this;
	}
	//イテレータのムーブコンストラクタ
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator&& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator&& obj) ://VC++もOK
		m_stack(),
		m_root(obj.m_root),
		m_node(obj.m_node),
		m_isEnd(false)
	{
		if (m_node)
		{
			m_stack = std::move(obj.m_stack);
			++(*this);
		}
		else
		{
			m_stack.reset();
			if (obj.m_isEnd)
				m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
		}
	}
	//イテレータのコピーコンストラクタ
	template<class OPE_TYPE>
	//container<OPE_TYPE>::iterator::iterator(typename container<OPE_TYPE>::const_reverse_iterator& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE>::iterator::iterator(const typename container<OPE_TYPE>::reverse_iterator& obj) ://VC++もOK
		m_stack(),
		m_root(obj.m_root),
		m_node(obj.m_node),
		m_isEnd(false)
	{
		if (m_node)
		{
			m_stack = obj.m_stack;
			++(*this);
		}
		else
		{
			m_stack.reset();
			if (obj.m_isEnd)
				m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, m_stack));
		}
	}
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace rb_tree

//--------------------------------------------------------------------------------
//赤黒木テスト
//--------------------------------------------------------------------------------

#include <algorithm>//for_each用
#include <random>//C++11 std::random用
#include <chrono>//C++11 時間計測用
#include <type_traits>//C++11 時間計測用

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
	//コンストラクタ
	data_t(const int key) :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_key(key)
	{}
	data_t() :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_key(0)
	{}

	//フィールド
	const data_t* m_nodeS;//小（左）側の子ノード
	const data_t* m_nodeL;//大（右）側の子ノード
	bool m_isBlack;//ノードの色
	int m_key;//キー
};
//----------------------------------------
//テストデータ向けノード操作用クラス（CRTP）
struct ope_t : public rb_tree::base_ope_t<ope_t, data_t, int, TEST_DATA_STACK_DEPTH_MAX>
{
	//子ノードを取得
	inline static const node_type* getChildL(const node_type& node){ return node.m_nodeL; }//大（右）側
	inline static const node_type* getChildS(const node_type& node){ return node.m_nodeS; }//小（左）側
	//子ノードを変更
	inline static void setChildL(node_type& node, const node_type* child){ node.m_nodeL = child; }//大（右）側
	inline static void setChildS(node_type& node, const node_type* child){ node.m_nodeS = child; }//小（左）側

	//ノードの色を取得
	inline static color_t getColor(const node_type& node){ return node.m_isBlack ? BLACK : RED; }
	//ノードの色を変更
	inline static void setColor(node_type& node, const color_t color){ node.m_isBlack = color == BLACK; }
	
	//キーを取得
	inline static key_type getKey(const node_type& node){ return node.m_key; }

	//キーを比較
	//※デフォルトのままとする
	//inline static int compareKey(const key_type lhs, const key_type rhs);

	//ロック型
	//※デフォルト（dummy_shared_lock）のままとする
	//typedef shared_spin_lock lock_type;//ロックオブジェクト型
};

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//型
	typedef rb_tree::container<ope_t> container_t;
	typedef container_t::iterator iterator;
	typedef container_t::const_iterator const_iterator;
	typedef container_t::reverse_iterator reverse_iterator;
	typedef container_t::const_reverse_iterator const_reverse_iterator;
	
	//赤黒木コンテナ
	container_t con;

	//処理時間計測開始
	const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point prev_time = begin_time;

	//データを登録
	auto regList = [&con]()
	{
		printf("--- Make table ---\n");
		auto insert = [&con](const int key)
		{
			data_t* new_node = new data_t(key);
			printf_detail("[%2d] ", new_node->m_key);
			con.insert(*new_node);
			rb_tree::printf_dbg_add("\n");
		};
	#ifdef REGIST_TEST_DATA_SEQUENTIALLY
		//シーケンシャルにデータ登録
		for (int i = 0; i < TEST_DATA_REG_NUM; ++i)
		{
			const int key = TEST_DATA_KEY_MIN + i % (TEST_DATA_KEY_MAX - TEST_DATA_KEY_MIN + 1);
			insert(key);
		}
	#else//REGIST_TEST_DATA_SEQUENTIALLY
	#ifndef TEST_DATA_REGISTRATION_LIST
		//ランダムにデータ登録
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_KEY_MIN, TEST_DATA_KEY_MAX);
		for (int i = 0; i < TEST_DATA_REG_NUM; ++i)
			insert(rand_dist(rand_engine));
	#else//TEST_DATA_REGISTRATION_LIST
		//固定順にデータ登録
		const int key_list[] = TEST_DATA_REGISTRATION_LIST;
		for (int key : key_list)
			insert(key);
	#endif//TEST_DATA_REGISTRATION_LIST
	#endif//REGIST_TEST_DATA_SEQUENTIALLY
		printf_detail("\n");
		printf("%d registered.\n", TEST_DATA_REG_NUM);
	};
	regList();

	//経過時間を表示
	auto printElapsedTime = [](const std::chrono::system_clock::time_point& prev_time) -> std::chrono::system_clock::time_point
	{
		//最終経過時間表示
		const auto now_time = std::chrono::system_clock::now();
		const auto duration = now_time - prev_time;
		const double elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()) / 1000000000.;
		printf("*elapsed_time=%.9llf sec\n", elapsed_time);
		return now_time;
	};
	prev_time = printElapsedTime(prev_time);

	//木を表示
	auto showTree = [&con]()
	{
		printf("--- Show tree (count=%d) ---\n", con.size());
		//static const int depth_limit = 5;//最大でも5段階目までを表示（0段階目から数えるので最大で6段階表示される→最大：1+2+4+8+16+32=63個）
		static const int depth_limit = 4;//最大でも4段階目までを表示（0段階目から数えるので最大で5段階表示される→最大：1+2+4+8+16=31個）
		const int _depth_max = con.depth_max();
		printf("depth_max=%d (limit for showing=%d)\n", _depth_max, depth_limit);
	#ifdef PRINT_TEST_DATA_TREE
		const int depth_max = _depth_max <= depth_limit ? _depth_max : depth_limit;
		const int width_max = depth_max < 0 ? 0 : 1 << depth_max;//static_cast<int>(std::pow(2, depth_max));
		for (int depth = 0; depth <= depth_max; ++depth)
		{
			const int width = 1 << depth;//static_cast<int>(std::pow(2, depth));
			static const int label_len = 6;
			const int print_width = (width_max * label_len) / width;
			const int print_indent = (print_width - label_len) / 2;
			for (int breath = 0; breath < width; ++breath)
			{
				const data_t* node = con.root();
				int breath_tmp = breath;
				for (int depth_tmp = depth - 1; node; --depth_tmp)
				{
					if (depth_tmp < 0)
						break;
					node = ope_t::getChild(*node, (breath_tmp & (0x1 << depth_tmp)) != 0x0);
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (ope_t::getChildS(*node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(ope_t::getChildS(*node) ? "-" : " ");
					}
					printf("%s%2d:%c%s", ope_t::getChildS(*node) ? "{" : "[", node->m_key, ope_t::isBlack(*node) ? 'B' : 'R', ope_t::getChildL(*node) ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(ope_t::getChildL(*node) ? "-" : " ");
						if (ope_t::getChildL(*node) && c < print_indent)
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
	#endif//PRINT_TEST_DATA_TREE
	};
	showTree();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

#ifdef ENABLE_CALC_COUNT_PERFORMANCE
	//ノード数カウントの時間計測
	auto calcNodesCount = [&con]()
	{
		static const int loop_max = 10000000;
		printf("--- Calc count (%d times) ---\n", loop_max);
		long long count = 0;
		for (int i = 0; i < loop_max; ++i)
			count += con.size();
		printf("count=%lld\n", count);
	};
	calcNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示
#endif//ENABLE_CALC_COUNT_PERFORMANCE

	//各枝までのノード数を表示
	//※条件③と条件④違反確認
	auto showNodesCount = [&con]()
	{
		printf("--- Show nodes count (count=%d) ---\n", con.size());
		const int depth_max = con.depth_max();
		const unsigned long long width_max = depth_max < 0 ? 0llu : 1llu << depth_max;//static_cast<long long>(std::pow(2, static_cast<long long>(depth_max)));
		printf("depth_max=%d, width_max=%llu\n", depth_max, width_max);
		if(depth_max > 63)
		{
			printf("'depth_max' is over 63. aborting therefor.\n");
			return;
		}
	#ifdef PRINT_TEST_DATA_COLOR_COUNT
		const data_t* prev_node = nullptr;
		int blacks_min = -1;
		int blacks_max = -1;
		int reds_min = -1;
		int reds_max = -1;
		int total_min = -1;
		int total_max = -1;
		int total_illegal_connects = 0;
		for (unsigned long long breath = 0; breath < width_max; ++breath)
		{
			int blacks = 0;
			int reds = 0;
			int illegal_connects = 0;
			const data_t* last_node = nullptr;
			const data_t* parent_node = nullptr;
			const data_t* node = con.root();
			long long breath_tmp = breath;
			for (long long depth_tmp = depth_max - 1; node; --depth_tmp)
			{
				last_node = node;
				if (ope_t::isBlack(*node))
					++blacks;
				else//if (ope_t::isRed(*node))
				{
					++reds;
					if (parent_node && ope_t::isRed(*parent_node))
					{
						++illegal_connects;
					}
				}
				if (depth_tmp < 0)
					break;
				parent_node = node;
				node = ope_t::getChild(*node, (breath_tmp & (0x1ll << depth_tmp)) != 0x0ll);
			}
			int total = blacks + reds;
			blacks_min = blacks_min > blacks || blacks_min == -1 ? blacks : blacks_min;
			blacks_max = blacks_max < blacks || blacks_max == -1 ? blacks : blacks_max;
			reds_min = reds_min > reds || reds_min == -1 ? reds : reds_min;
			reds_max = reds_max < reds || reds_max == -1 ? reds : reds_max;
			total_min = total_min > total || total_min == -1 ? total : total_min;
			total_max = total_max < total || total_max == -1 ? total : total_max;
			total_illegal_connects += illegal_connects;
			if (prev_node != last_node)
			{
			#ifdef PRINT_TEST_DATA_DETAIL
				printf("%5lld:[%2d] blacks=%d, reds=%d, total=%d (illegal=%d)\n", breath, last_node->m_key, blacks, reds, total, illegal_connects);
			#endif//PRINT_TEST_DATA_DETAIL
			}
			prev_node = last_node;
		}
		blacks_min = blacks_min >= 0 ? blacks_min : 0;
		blacks_max = blacks_max >= 0 ? blacks_max : 0;
		reds_min = reds_min >= 0 ? reds_min : 0;
		reds_max = reds_max >= 0 ? reds_max : 0;
		total_min = total_min >= 0 ? total_min : 0;
		total_max = total_max >= 0 ? total_max : 0;
		printf("max: blacks=%d, reds=%d, total=%d\n", blacks_max, reds_max, total_max);
		printf("min: blacks=%d, reds=%d, total=%d\n", blacks_min, reds_min, total_min);
		printf("diff:blacks=%d, reds=%d, total=%d (illegal=%d)\n", blacks_max - blacks_min, reds_max - reds_min, total_max - total_min, total_illegal_connects);
	#endif//PRINT_TEST_DATA_COLOR_COUNT
	};
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番小さいノードから昇順に全ノードをリストアップ
	auto showListAsc = [&con]()
	{
		printf("--- Show nodes ascending (count=%d) ---\n", con.size());
		bool is_found = false;
		for (const data_t& obj : con)//※イテレータ（.begin() , .end()）が暗黙的に使用される
		{
			if (!is_found)
				is_found = true;
			printf_detail("[%2d] ", obj.m_key);
		}
		//※イテレータの変数宣言と値の更新を分けた方が若干効率的
		//const_reverse_iterator ite;con._begin(ite);
		//const_reverse_iterator end;con._end(end);
		//for (; ite != end; ++ite)
		//{
		//	const data_t& obj = *ite;
		//	...
		//}
		if (is_found)
			printf_detail("\n");
		else
			printf("(nothing)\n");
	};
	showListAsc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番大きいノードから降順に全ノードをリストアップ
	auto showListDesc = [&con]()
	{
		printf("--- Show nodes descending (count=%d) ---\n", con.size());
		bool is_found = false;
		std::for_each(con.rbegin(), con.rend(),//リバースイテレータ
			[&is_found](const data_t& obj)
			{
				if (!is_found)
					is_found = true;
				printf_detail("[%2d] ", obj.m_key);
			}
		);
		//※イテレータの変数宣言と値の更新を分けた方が効率的
		//const_reverse_iterator ite;con._rbegin(ite);
		//const_reverse_iterator end;con._rend(end);
		//for (; ite != end; ++ite)
		//{
		//	const data_t& obj = *ite;
		//	...
		//}
		if (is_found)
			printf_detail("\n");
		else
			printf("(nothing)\n");
	};
	showListDesc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

#if 0//イテレータとロック取得のテスト
	{
		shared_lock_guard<container_t::lock_type> lock(con);
		container_t::iterator ite = con.begin();
		container_t::reverse_iterator rite = con.rbegin();
		container_t::iterator ite_end = con.end();
		container_t::reverse_iterator rite_end = con.rend();
		container_t::iterator ite2 = con.rbegin();
		container_t::reverse_iterator rite2 = con.begin();
		container_t::iterator ite2_end = con.rend();
		container_t::reverse_iterator rite2_end = con.end();
		printf("constructor\n");
		if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
		if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
		if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
		if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
		if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
		if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
		if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
		if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
		printf("copy operator\n");
		ite = con.begin();
		rite = con.rbegin();
		ite_end = con.end();
		rite_end = con.rend();
		ite2 = con.rbegin();
		rite2 = con.begin();
		ite2_end = con.rend();
		rite2_end = con.end();
		if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
		if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
		if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
		if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
		if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
		if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
		if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
		if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
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
			if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
			if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
			if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
			if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
			if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
			if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
			if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
			if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
		}
		printf("+= 7\n");
		ite += 7;
		rite += 7;
		ite_end += 7;
		rite_end += 7;
		ite2 += 7;
		rite2 += 7;
		ite2_end += 7;
		rite2_end += 7;
		if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
		if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
		if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
		if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
		if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
		if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
		if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
		if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
		printf("-= 7\n");
		ite -= 7;
		rite -= 7;
		ite_end -= 7;
		rite_end -= 7;
		ite2 -= 7;
		rite2 -= 7;
		ite2_end -= 7;
		rite2_end -= 7;
		if (ite.isExist()) printf("ite:key=%d\n", ite->m_key);
		if (rite.isExist()) printf("rite:key=%d\n", rite->m_key);
		if (ite_end.isExist()) printf("ite_end:key=%d\n", ite_end->m_key);
		if (rite_end.isExist()) printf("rite_end:key=%d\n", rite_end->m_key);
		if (ite2.isExist()) printf("ite2:key=%d\n", ite2->m_key);
		if (rite2.isExist()) printf("rite2:key=%d\n", rite2->m_key);
		if (ite2_end.isExist()) printf("ite2_end:key=%d\n", ite2_end->m_key);
		if (rite2_end.isExist()) printf("rite2_end:key=%d\n", rite2_end->m_key);
	}
#endif

	//指定のキーのノードを検索し、同じキーのノードをリストアップ
	auto searchData = [&con]()
	{
		printf("--- Search node ---\n");
		for (int search_key = TEST_DATA_KEY_MIN; search_key <= TEST_DATA_KEY_MAX; ++search_key)
		{
			static const int print_count_limit = 10;
			int print_count = 0;
			bool is_found = false;
			std::for_each(con.find(search_key), con.equal_range(search_key),
				[&con, &is_found, &search_key, &print_count](const data_t& obj)
				{
					if (!is_found)
					{
						printf_dbg_search("%2d(%d):", search_key, con.count(search_key));
						is_found = true;
					}
					if (print_count < print_count_limit)
						printf_dbg_search("[%2d] ", obj.m_key);
					else if (print_count == print_count_limit)
						printf_dbg_search("...");
					++print_count;
				}
			);
			//※イテレータの変数宣言と検索を分けた方が効率的
			//const_iterator ite;con._find(ite, search_key);
			//const_iterator end;con._equal_range(end, search_key);
			//for (; ite != end; ++ite)
			//{
			//	const data_t& obj = *ite;
			//	...
			//}
			if (is_found)
				printf_dbg_search("\n");
		}
	};
	searchData();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//指定のキーのノードを検索
	//※一致ノードは表示を省略
	//※最近ノードから数ノードを表示
	auto searchNearestData = [&con](const rb_tree::match_type_t search_type)
	{
		printf("--- Search nearest node for %s ---\n", search_type == rb_tree::FOR_NEAREST_SMALLER ? "smaller" : search_type == rb_tree::FOR_NEAREST_LARGER ? "larger" : "same");
		for (int search_key = TEST_DATA_KEY_MIN; search_key <= TEST_DATA_KEY_MAX; ++search_key)
		{
			bool is_found = false;
			const_iterator ite(con.find(search_key, search_type));
			const_iterator end(con.end());
			for (int i = 0; ite != end && ite->m_key != search_key && i < 4; ++i, ++ite)
			{
				const data_t& obj = *ite;
				if (!is_found)
				{
					printf_dbg_search("%2d:", search_key);
					is_found = true;
				}
				printf_dbg_search("[%2d] ", obj.m_key);
			}
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key, search_type);
			//const_iterator end;con._end(end);
			//...
			if (is_found)
				printf_dbg_search("\n");
		}
	};
	//指定のキーと同じか内輪で一番近いノードを検索
	searchNearestData(rb_tree::FOR_NEAREST_SMALLER);
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//指定のキーと同じかそれより大きい最近ノードを検索
	searchNearestData(rb_tree::FOR_NEAREST_LARGER);
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//ノードを削除
	//※特定のキーを削除
	auto removeNodes = [&con]()
	{
		printf("--- Remove nodes ---\n");
		auto erase = [&con](const int remove_key) -> bool
		{
			data_t* removed_node = con.erase(remove_key);
			if (removed_node)
			{
				delete removed_node;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
				return true;
			}
			return false;
		};
		int removed_count = 0;
	#ifndef TEST_DATA_REMOVING_LIST
		//ランダムにデータ削除
		std::mt19937 rand_engine;
		rand_engine.seed(1);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_KEY_MIN, TEST_DATA_KEY_MAX);
		const int removed_count_max = TEST_DATA_REG_NUM / 4;
		while (removed_count < removed_count_max)
		{
			const bool result = erase(rand_dist(rand_engine));
			if (result)
				++removed_count;
		}
	#else//TEST_DATA_REMOVING_LIST
		//固定順にデータ削除
		const int key_list[] = TEST_DATA_REMOVING_LIST;
		for (int key : key_list)
		{
			const bool result = erase(key);
			if (result)
				++removed_count;
		}
	#endif//TEST_DATA_REMOVING_LIST
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeNodes();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//木を表示
	showTree();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//各枝までのノード数を表示
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//ノードを削除
	//※すべての値のキーを一つずつ削除
	auto removeEachKeyNodes = [&con]()
	{
		printf("--- Remove each-key nodes ---\n");
		int removed_count = 0;
		for (int remove_key = TEST_DATA_KEY_MIN; remove_key <= TEST_DATA_KEY_MAX; ++remove_key)
		{
			const_iterator ite(con.find(remove_key));
			data_t* removed_node = con.erase(*ite);
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (removed_node)
			{
				delete removed_node;
				++removed_count;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
			}
		}
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeEachKeyNodes();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//木を表示
	showTree();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//各枝までのノード数を表示
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//ノードを全削除
	//※すべての値のキーに対して、削除が失敗するまで削除を実行
	auto removeAllNodes = [&con]()
	{
		printf("--- Remove all nodes ---\n");
		int removed_count = 0;
		for (int remove_key = TEST_DATA_KEY_MIN; remove_key <= TEST_DATA_KEY_MAX;)
		{
			const_iterator ite(con.find(remove_key));
			data_t* removed_node = con.erase(*ite);
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (removed_node)
			{
				delete removed_node;
				++removed_count;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
			}
			else
				++remove_key;
		}
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeAllNodes();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//木を表示
	showTree();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//各枝までのノード数を表示
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//終了
	printf("--- end ---\n");
	printElapsedTime(begin_time);//経過時間を表示

	return EXIT_SUCCESS;
}

// End of file
