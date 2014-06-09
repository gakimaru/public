#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <atomic>

#include <chrono> //時間計測用
#include <random> //乱数生成用

//--------------------------------------------------------------------------------
//基本マクロ

//スレッドローカルストレージ修飾子
//※C++11仕様偽装
//#define TLS_IS_POSIX//TLSの宣言をPOSIX仕様にする時はこのマクロを有効にする
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX仕様
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows仕様
#endif//TLS_IS_POSIX

//----------------------------------------
//スレッド識別クラス
//※IDをハッシュ化した場合、TLSを活用して高速化

//スレッドID型
#define THREAD_ID_IS_HASH//スレッドIDをハッシュ型で扱う場合はこのマクロを有効化する（ハッシュの方が高速）
#ifdef THREAD_ID_IS_HASH
typedef std::size_t THREAD_ID;//(ハッシュ)
static const THREAD_ID INVALID_THREAD_ID = std::hash<std::thread::id>()(std::thread::id());//無効なスレッドID(ハッシュ)
static const THREAD_ID INITIAL_THREAD_ID = static_cast<THREAD_ID>(~0);//初期スレッドID(ハッシュ)
#else//THREAD_ID_IS_HASH
typedef std::thread::id THREAD_ID;
static const THREAD_ID INVALID_THREAD_ID = std::thread::id();//無効なスレッドID
#endif//THREAD_ID_IS_HASH

//現在のスレッドID取得関数
#ifdef THREAD_ID_IS_HASH
inline THREAD_ID GetThisThreadID(){ return std::hash<std::thread::id>()(std::this_thread::get_id()); }//(ハッシュ)
#else//THREAD_ID_IS_HASH
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id(); }
#endif//THREAD_ID_IS_HASH

//スレッド識別クラス
class thread_identifier
{
public:
	//アクセッサ
	const THREAD_ID getID() const { return m_threadId; }//スレッドIDを取得
	const char* getName() const { return m_threadName; }//スレッド名を取得
public:
	//アクセッサ（static）
#ifdef THREAD_ID_IS_HASH
	static THREAD_ID getThisID(){ return m_thisThreadID; }//現在のスレッドのスレッドIDを取得(ハッシュ)
#else//THREAD_ID_IS_HASH
	static THREAD_ID getThisID(){ return GetThisThreadID(); }//現在のスレッドのスレッドIDを取得
#endif//THREAD_ID_IS_HASH
	static const char* getThisName(){ return m_thisThreadName; }//現在のスレッドのスレッド名を取得
public:
	//メソッド
	bool isThisThread() const { return m_threadId == getThisID(); }//現在のスレッドと同じスレッドか判定
private:
	//メソッド(static)
	static void setThisThread()//現在のスレッドのスレッドIDをセット
	{
	#ifdef THREAD_ID_IS_HASH
		if (m_thisThreadID == INITIAL_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
	#endif//THREAD_ID_IS_HASH
	}
	static void resetThisThread(const char* name)//現在のスレッドのスレッドIDをリセット
	{
	#ifdef THREAD_ID_IS_HASH
		m_thisThreadID = GetThisThreadID();
	#endif//THREAD_ID_IS_HASH
		m_thisThreadName = name;
	}
public:
	//オペレータ（許可）
	bool operator==(const thread_identifier& o) const { return m_threadId == o.getID(); }//ID一致判定
	bool operator!=(const thread_identifier& o) const { return m_threadId != o.getID(); }//ID不一致判定
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID一致判定
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID不一致判定
	thread_identifier& operator=(const thread_identifier& o)//コピー演算子
	{
		m_threadId = o.m_threadId;
		m_threadName = o.m_threadName;
		return *this;
	}
private:
	//オペレータ（禁止）
	thread_identifier& operator=(const THREAD_ID& id) { return *this; }//コピー演算子（禁止）
public:
	//コピーコンストラクタ（許可）
	explicit thread_identifier(const thread_identifier& o) :
		m_threadId(o.m_threadId),
		m_threadName(o.m_threadName)
	{
	}
private:
	//コピーコンストラクタ（禁止）
	explicit thread_identifier(const THREAD_ID& id){}
public:
	//コンストラクタ
	//※スレッド名を指定し、内部で現在のスレッドIDを取得して保持
	//※TLSにも記録
	thread_identifier(const char* name)
	{
		resetThisThread(name);
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
	//デフォルトコンストラクタ
	//※既にTLSに記録済みのスレッドID（と名前）を取得
	thread_identifier()
	{
		setThisThread();
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
private:
	//フィールド
	THREAD_ID m_threadId;//スレッドID（オブジェクトに保存する値）
	const char* m_threadName;//スレッド名（オブジェクトに保存する値）
#ifdef THREAD_ID_IS_HASH
	static thread_local THREAD_ID m_thisThreadID;//現在のスレッドのスレッドID(TLS)
#endif//THREAD_ID_IS_HASH
	static thread_local const char* m_thisThreadName;//現在のスレッド名(TLS)
};
//static変数のインスタンス化
#ifdef THREAD_ID_IS_HASH
thread_local THREAD_ID thread_identifier::m_thisThreadID = INITIAL_THREAD_ID;//スレッドID(TLS)
#endif//THREAD_ID_IS_HASH
thread_local const char* thread_identifier::m_thisThreadName = nullptr;//スレッド名(TLS)

//--------------------------------------------------------------------------------
//自作ロッククラス
//--------------------------------------------------------------------------------

#include <thread>
#include <atomic>

//--------------------------------------------------------------------------------
//スピンロック
//--------------------------------------------------------------------------------

//----------------------------------------
//スピンロック
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
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//スリープ（コンテキストスイッチ）
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
//スピンロック（軽量版）
//※サイズは1バイト
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
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//スリープ（コンテキストスイッチ）
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
//共有スピンロッククラス（リード・ライトロッククラス）
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
	static const int DEFAULT_COUNTER = 0x01000000;//ロックが取得されていない時のデフォルトのカウンター

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
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//スリープ（コンテキストスイッチ）
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
						std::this_thread::sleep_for(std::chrono::milliseconds(0));//スリープ（コンテキストスイッチ）
						spin_count_now = spin_count;
					}
				}
				return;//ロック取得成功
			}
			m_lockCounter.fetch_add(DEFAULT_COUNTER);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//スリープ（コンテキストスイッチ）
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
	std::atomic<int> m_lockCounter;//ロックカウンター
};

//----------------------------------------
//共有スピンロッククラス（リード・ライトロッククラス）（軽量版）
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
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//スリープ（コンテキストスイッチ）
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
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//スリープ（コンテキストスイッチ）
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
	std::atomic<int> m_lockCounter;//ロックカウンター
};

//----------------------------------------
//非共有スピンロッククラス（リード・ライトロッククラス）
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
//ダミー共有ロッククラス
//※shared_spin_lockやstd::shared_spin_lockと同様のロックインターフェースを持つが、実際には何もしないクラス
class dummy_shared_lock
{
public:
	//リード・ロック取得
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//何もしない
	}
	//リード・ロック取得を試行
	inline bool try_lock_shared()
	{
		//何もしない
	}
	//ライト・ロック取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//何もしない
	}
	//ライト・ロック取得を試行
	inline bool try_lock()
	{
		//何もしない
	}
	//リード・ロック解放
	inline void unlock_shared()
	{
		//何もしない
	}
	//ライト・ロック解放
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
//共有ロックヘルパークラス
//※実装を隠ぺいして共有ロックを操作するためのヘルパークラス
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
//共有ロックガードクラス（スコープロック）
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

//メインスレッド情報
static thread_identifier s_mainThread("MainThread");

//リード・ライトロックオブジェクト
typedef shared_spin_lock lock_type;
//typedef lw_shared_spin_lock lock_type;
//typedef unshared_spin_lock lock_type;
//typedef dummy_shared_lock lock_type;
static lock_type s_lock;

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__declspec(thread) int s_tlsData = 0;
//thread_local int s_tlsData = 0;//Visual C++ 2013 では thread_local キーワードが使えない

//書き込みスレッド
void threadFuncW(const char* name)
{
	//開始
	printf("- begin:(W)%s -\n", name);
	fflush(stdout);

	//乱数
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time1(0, 10);
	std::uniform_int_distribution<int> sleep_time2(100, 200);

	//若干ランダムでスリープ（0～499 msec）
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time1(rnd)));

	//処理
	for (int i = 0; i < 3; ++i)
	{
		{
			//ライトロック取得
			lock_guard<lock_type> lock(s_lock);

			//データ表示（前）
			printf("(W)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
			fflush(stdout);

			//データ取得
			int common_data = s_commonData;
			int tls_data = s_tlsData;

			//データ更新
			++common_data;
			++tls_data;

			//若干ランダムでスリープ（0～499 msec）
			std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time2(rnd)));

			//データ書き戻し
			s_commonData = common_data;
			s_tlsData = tls_data;

			//データ表示（後）
			printf("(W)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
			fflush(stdout);
		}//ライトロック解放

		//若干ランダムでスリープ（0～499 msec）
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time1(rnd)));
	}

	//終了
	printf("- end:(W)%s -\n", name);
	fflush(stdout);
}

//読み込みスレッド
void threadFuncR(const char* name)
{
	//開始
	printf("- begin:(R)%s -\n", name);
	fflush(stdout);

	//乱数
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time1(10, 20);
	std::uniform_int_distribution<int> sleep_time2(50, 150);

	//若干ランダムでスリープ（0～499 msec）
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time1(rnd)));

	//処理
	for (int i = 0; i < 3; ++i)
	{
		{
			//リードロック取得
			shared_lock_guard<lock_type> lock(s_lock);

			//データ表示（前）
			printf("(R)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
			fflush(stdout);

			//若干ランダムでスリープ（0～499 msec）
			std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time2(rnd)));

			//データ表示（後）
			printf("(R)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
			fflush(stdout);
		}//リードロック解放

		//若干ランダムでスリープ（0～499 msec）
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time1(rnd)));
	}

	//終了
	printf("- end:(R)%s -\n", name);
	fflush(stdout);
}

//テスト
int main(const int argc, const char* argv[])
{
	printf("sizeof(shared_spin_lock)=%d\n", sizeof(shared_spin_lock));

	//スレッド作成
	std::thread thread_obj1 = std::thread(threadFuncR, "太郎");
	std::thread thread_obj2 = std::thread(threadFuncR, "次郎");
	std::thread thread_obj3 = std::thread(threadFuncR, "三郎");
	std::this_thread::sleep_for(std::chrono::microseconds(1));
	std::thread thread_obj4 = std::thread(threadFuncW, "松子");
	std::thread thread_obj5 = std::thread(threadFuncW, "竹子");
	std::thread thread_obj6 = std::thread(threadFuncW, "梅子");

	//スレッド終了待ち
	{
		auto begin = std::chrono::high_resolution_clock::now();
		thread_obj1.join();
		thread_obj2.join();
		thread_obj3.join();
		thread_obj4.join();
		thread_obj5.join();
		thread_obj6.join();
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Time = %.6f sec\n", duration);
	}
	
	//共有ロックの取得と解放を大量に実行して時間を計測
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			shared_lock_helper<lock_type> lock(s_lock);
			lock.lock_shared();
			lock.unlock_shared();
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Read-WriteLock:wlock * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//共有ロックの取得と解放を大量に実行して時間を計測
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			shared_lock_helper<lock_type> lock(s_lock);
			lock.lock();
			lock.unlock();
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Read-WriteLock:rlock * %d = %.6f sec\n", TEST_TIMES, duration);
	}
	
	return EXIT_SUCCESS;
}

// End of file
