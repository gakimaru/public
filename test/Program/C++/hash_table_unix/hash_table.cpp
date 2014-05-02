//--------------------------------------------------------------------------------
//ハッシュテーブルテスト用設定とコンパイラスイッチ
static const int TEST_DATA_TABLE_SIZE = 500000;//テストデータテーブルサイズ
//static const int TEST_DATA_TABLE_SIZE = 10;//テストデータテーブルサイズ

//#define PRINT_TEST_DATA_DETAIL//テストデーの詳細タを表示する場合は、このマクロを有効化する
//#define TEST_DATA_WATCH_CONSTRUCTOR//コンストラクタ／デストラクタ／代入演算子の動作を確認する場合、このマクロを有効化する

#define USE_GCC//GCC版でコンパイルするときは、このマクロを有効化する

#include <cstddef>//sｔd::size_t用

//【C++11仕様】thread_local：スレッドローカルストレージ（TLS）修飾子
#ifdef USE_GCC
#define thread_local __thread//GCC用
#else//USE_GCC
#define thread_local __declspec(thread)//VC++用
#endif//USE_GCC

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------
//素数計算
//--------------------------------------------------------------------------------

#include <cstddef>//srd::size_t用
#include <type_traits>//C++11 std::conditional, std:integral_constant用

//----------------------------------------
//【ランタイム版】
//----------------------------------------

//----------------------------------------
//【ランタイム版】素数判定
bool isPrime(const std::size_t n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if ((n & 0x1) == 0x0)//偶数判定
		return false;
	for (std::size_t div = 3; div <= n / div; div += 2)
	{
		if (n % div == 0)
			return false;
	}
	return true;
}
//----------------------------------------
//【ランタイム版】前の素数を生成
std::size_t makePrimePrev(const std::size_t n)
{
	if (n <= 2)
		return 0;
	else if (n == 3)
		return 2;
	for (std::size_t nn = n - ((n & 0x1) == 0x0 ? 1 : 2);; nn -= 2)//※偶数は判定しない
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//----------------------------------------
//【ランタイム版】次の素数を生成
std::size_t makePrimeNext(const std::size_t n)
{
	if (n < 2)
		return 2;
	for (std::size_t nn = n + ((n & 0x1) == 0x0 ? 1 : 2);; nn += 2)//※偶数は判定しない
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//----------------------------------------
//【ランタイム版】指定の値と同じか、前の素数を生成
std::size_t makePrimeEqPrev(const std::size_t n)
{
	return isPrime(n) ? n : makePrimePrev(n);
}
//----------------------------------------
//【ランタイム版】指定の値と同じか、次の素数を生成
std::size_t makePrimeEqNext(const std::size_t n)
{
	return isPrime(n) ? n : makePrimeNext(n);
}

//----------------------------------------
//【メタプログラミング版】
//----------------------------------------
//【注意】
// メタプログラミング版では、コンパイラに応じてテンプレートの再帰レベルの限界がある。
// このため、実質 100001 ぐらいまでの素数しか扱えない点に注意。
// 他のテンプレート内で使うと、もっと制約を受ける点にも注意。
// また、コンパイル時間に影響がある点にも注意。
//----------------------------------------

//----------------------------------------
//【メタプログラミング版】素数判定
//※偶数の判定を避けるために階層化する
template <std::size_t N, std::size_t DIV>//再帰クラス
struct _isPrimeMeta{
	typedef
		typename std::conditional<
			(DIV > N / DIV),
			std::integral_constant<bool, true>,
			typename std::conditional<
				(N % DIV == 0),
				std::integral_constant<bool, false>,
				_isPrimeMeta<N, DIV + 2>
			>::type
		>::type
		type;
	static const bool value = type::value;
};
template <std::size_t N>//素数判定クラス
struct isPrimeMeta{
	typedef
		typename std::conditional<
			(N & 0x1) == 0x0,
			std::integral_constant<bool, false>,
			typename _isPrimeMeta<N, 3>::type
		>::type
		type;
	static const bool value = type::value;
};
template <>
struct isPrimeMeta<0>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<1>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<2>{
	static const bool value = true;
};

//----------------------------------------
//【メタプログラミング版】前の素数を生成
//※偶数の判定を避けるために階層化する
template<std::size_t N>//再帰クラス
struct _makePrimePrevMeta{
	typedef
		typename std::conditional<
			isPrimeMeta<N>::value,
			std::integral_constant<std::size_t, N>,
			_makePrimePrevMeta<N - 2>
		>::type
		type;
	static const std::size_t value = type::value;
};
template<std::size_t N>//前の素数生成クラス
struct makePrimePrevMeta{
	typedef
		typename std::conditional<
			(N & 0x1) == 0x0,
			_makePrimePrevMeta<N - 1>,
			_makePrimePrevMeta<N - 2>
		>::type
		type;
	static const std::size_t value = type::value;
};
template<>
struct makePrimePrevMeta<0>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<1>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<2>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<3>{
	static const std::size_t value = 2;
};

//----------------------------------------
//【メタプログラミング版】次の素数を生成
//※偶数の判定を避けるために階層化する
template<std::size_t N>//再帰クラス
struct _makePrimeNextMeta{
	typedef
		typename std::conditional<
			isPrimeMeta<N>::value,
			std::integral_constant<std::size_t, N>,
			_makePrimeNextMeta<N + 2>
		>::type
		type;
	static const std::size_t value = type::value;
};
template<std::size_t N>//次の素数生成クラス
struct makePrimeNextMeta{
	typedef
		typename std::conditional<
			(N & 0x1) == 0x0,
			_makePrimeNextMeta<N + 1>,
			_makePrimeNextMeta<N + 2>
		>::type
		type;
	static const std::size_t value = type::value;
};
template<>
struct makePrimeNextMeta<0>{
	static const std::size_t value = 2;
};
template<>
struct makePrimeNextMeta<1>{
	static const std::size_t value = 2;
};

//----------------------------------------
//【メタプログラミング版】指定の値と同じか、前の素数を生成
template<std::size_t N>
struct makePrimeEqPrevMeta{
	typedef
		typename std::conditional<
			isPrimeMeta<N>::value,
			std::integral_constant<std::size_t, N>,
			makePrimePrevMeta<N>
		>::type
		type;
	static const std::size_t value = type::value;
};

//----------------------------------------
//【メタプログラミング版】指定の値と同じか、次の素数を生成
template<std::size_t N>
struct makePrimeEqNextMeta{
	typedef
		typename std::conditional<
			isPrimeMeta<N>::value,
			std::integral_constant<std::size_t, N>,
			makePrimeNextMeta<N>
		>::type
		type;
	static const std::size_t value = type::value;
};

//--------------------------------------------------------------------------------
//自作リード・ライトロッククラス
//--------------------------------------------------------------------------------

#include <thread>
#include <atomic>

//--------------------------------------------------------------------------------
//スレッドIDクラス
//--------------------------------------------------------------------------------
//※IDをハッシュ化した場合、TLSを活用して高速化
//--------------------------------------------------------------------------------

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

//スレッドIDクラス
class CThreadID
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
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID一致判定
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID不一致判定
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID一致判定
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID不一致判定
	CThreadID& operator=(const CThreadID& o)//コピー演算子
	{
		m_threadId = o.m_threadId;
		m_threadName = o.m_threadName;
		return *this;
	}
private:
	//オペレータ（禁止）
	CThreadID& operator=(const THREAD_ID& id) { return *this; }//コピー演算子（禁止）
public:
	//コピーコンストラクタ（許可）
	explicit CThreadID(const CThreadID& o) :
		m_threadId(o.m_threadId),
		m_threadName(o.m_threadName)
	{
	}
private:
	//コピーコンストラクタ（禁止）
	explicit CThreadID(const THREAD_ID& id){}
public:
	//コンストラクタ
	//※スレッド名を指定し、内部で現在のスレッドIDを取得して保持
	//※TLSにも記録
	CThreadID(const char* name)
	{
		resetThisThread(name);
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
	//デフォルトコンストラクタ
	//※既にTLSに記録済みのスレッドID（と名前）を取得
	CThreadID()
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
thread_local THREAD_ID CThreadID::m_thisThreadID = INITIAL_THREAD_ID;//スレッドID(TLS)
#endif//THREAD_ID_IS_HASH
thread_local const char* CThreadID::m_thisThreadName = nullptr;//スレッド名(TLS)

//--------------------------------------------------------------------------------
//軽量スピンロック
//--------------------------------------------------------------------------------

//----------------------------------------
//軽量スピンロック
//※手軽に使えるスピンロック
//※一定回数のスリープごとにスリープ（コンテキストスイッチ）を行う
//※容量は4バイト(std::atomic_flag一つ分のサイズ)
//※プログラミング上の安全性は低いので気がるに使うべきではない
//　　⇒ロック取得状態を確認せずにアンロックする
#define SPIN_LOCK_USE_ATOMIC_FLAG//std::atomic_flag版（高速）
//#define SPIN_LOCK_USE_ATOMIC_BOOL//std::atomic_bool版（軽量）
class CSpinLock
{
public:
	//定数
	static const int DEFAULT_SPIN_COUNT = 1000;//スピンロックカウントのデフォルト値
public:
	//ロック取得
	void lock(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = 0;
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		while (m_lock.test_and_set())//std::atomic_flag版（高速）
		{
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		bool prev = false;
		while (m_lock.compare_exchange_weak(prev, true))//std::atomic_bool版（軽量）
		{
			prev = false;
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
			if (spin_count == 0 || ++spin_count_now % spin_count == 0)
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//スリープ（コンテキストスイッチ）
		}
	}
	//ロック解放
	void unlock()
	{
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.clear();//std::atomic_flag版（高速）
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.store(false);//std::atomic_bool版（軽量）
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
	}
public:
	//コンストラクタ
	CSpinLock()
	{
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.clear();//ロック用フラグ（高速）
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.store(false);//ロック用フラグ（軽量）
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
	}
	//デストラクタ
	~CSpinLock()
	{
	}
private:
	//フィールド
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
	std::atomic_flag m_lock;//ロック用フラグ（高速）
#else//SPIN_LOCK_USE_ATOMIC_FLAG
	std::atomic_bool m_lock;//ロック用フラグ（軽量）
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
};

//--------------------------------------------------------------------------------
//リード・ライトロッククラス
//--------------------------------------------------------------------------------
//※容量節約のために、POSIXスレッドライブラリ版のように、現在のスレッドのロック状態を保持しない
//※必ずロッククラス CRWLock::LockR, CRWLock::LockR_AsNecessary, CRWLock::LockW を使用し、
//　そこに現在のロック状態を保持する
//--------------------------------------------------------------------------------

//----------------------------------------
//クラス宣言
class CRWLockHelper;

//----------------------------------------
//リード・ライトロッククラス
class CRWLock
{
	friend class CRWLockHelper;//手動でロック／アンロックを操作するためのヘルパークラス
public:
	//定数
	enum E_WLOCK_PRIORITY//ライトロック優先度
	{
		WLOCK_PRIORITIZED,//ライトロック優先
		NOT_WLOCK_PRIORITIZED,//ライトロック優先しない
		ALL_WLOCK//全てライトロックにする（リードロックも内部的にライトロックになる）
	};
public:
	//----------------------------------------
	//【クラス内クラス】クラス宣言
	class RLock;
	class RLockAsNecessary;
	class WLock;
	//----------------------------------------
	//【クラス内クラス】ロッククラス　※継承専用
	class Lock
	{
		friend class CRWLock;
	public:
		//アクセッサ
		bool isWriteLock() const { return m_isWriteLock; }//ライトロックモードか？
		bool isUnlocked() const { return m_isUnlocked; }//現在アンロック状態か？（ロック状態なのが普通）
	public:
		//メソッド

		//明示的なリードロック
		//※リードロック時が「必要に応じてリードロック」なら同じ動作になる
		//※明示的なロック解放後用メソッド
		//※通常はコンストラクタでロックするので使用しない
		void rlock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
		{
			if (!m_isUnlocked)
				return;
			m_lock.rlock(spin_count, m_ignoreThreadId);
			m_isWriteLock = false;
			m_isUnlocked = false;
		}
		//明示的なライトロック
		//※明示的なロック解放後用メソッド
		//※通常はコンストラクタでロックするので使用しない
		void wlock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
		{
			if (!m_isUnlocked)
				return;
			m_lock.wlock(spin_count);
			m_isWriteLock = true;
			m_isUnlocked = false;
		}
		//明示的なアンロック
		//※通常はデストラクタでアンロックするので使用しない
		void unlock()
		{
			if (m_isUnlocked)
				return;
			if (m_isWriteLock)
				m_lock.wunlock();
			else
				m_lock.runlock();
			m_isUnlocked = true;
		}
	private:
		//オペレータ
		Lock& operator=(const Lock& o){ return *this; }//コピー演算子（禁止）
	private:
		//コンストラクタ
		explicit Lock(const Lock& o) :m_lock(o.m_lock){}//コピーコンストラクタ（禁止）
	public:
		//ムーブコンストラクタ
		inline Lock(Lock&& lock) :
			m_lock(lock.m_lock),
			m_ignoreThreadId(lock.m_ignoreThreadId),
			m_isWriteLock(lock.m_isWriteLock),
			m_isUnlocked(lock.m_isUnlocked)
		{
			//移動元のロックオブジェクトはアンロック扱いにして、
			//デストラクタでアンロックしてしまうことを防ぐ
			lock.m_isUnlocked = true;
		}
	protected:
		//コンストラクタ　※各種ロッククラスからのみ使用

		//リードロック用コンストラクタ
		inline Lock(const RLock*, CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(INVALID_THREAD_ID),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//リードロック
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		//必要に応じてリードロック用コンストラクタ
		inline Lock(const RLockAsNecessary*, CRWLock& lock, const CThreadID& ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(ignore_thread_id.getID()),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//必要に応じてリードロック
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		inline Lock(const RLockAsNecessary*, CRWLock& lock, const THREAD_ID ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(ignore_thread_id),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//必要に応じてリードロック
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		//ライトロック用コンストラクタ
		inline Lock(const WLock*, CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(INVALID_THREAD_ID),
			m_isWriteLock(true),
			m_isUnlocked(false)
		{
			//ライトロック
			m_lock.wlock(spin_count);
		}
	public:
		//デストラクタ
		//※アンロック
		~Lock()
		{
			unlock();
		}
	private:
		//フィールド
		CRWLock& m_lock;//リード・ライトオブジェクトの参照
		THREAD_ID m_ignoreThreadId;//リードロックを無視するスレッドID
		bool m_isWriteLock;//ライトロックモードか？
		bool m_isUnlocked;//アンロック状態か？
	};
public:
	//----------------------------------------
	//【クラス内クラス】リードロッククラス
	class RLock : public Lock
	{
	private:
		//オペレータ
		RLock& operator=(const RLock& o){ return *this; }//コピー演算子（禁止）
	private:
		//コンストラクタ
		explicit RLock(const Lock& o) :Lock(o){}//コピーコンストラクタ（禁止）
	public:
		//ムーブコンストラクタ
		inline RLock(RLock&& lock) :
			Lock(std::move(lock))
		{
		}
	public:
		//コンストラクタ
		inline RLock(CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, spin_count)
		{}
		//デストラクタ
		inline ~RLock()
		{}
	};
	//----------------------------------------
	//【クラス内クラス】必要に応じてリードロッククラス
	class RLockAsNecessary : public Lock
	{
	private:
		//オペレータ
		RLockAsNecessary& operator=(const RLockAsNecessary& o){ return *this; }//コピー演算子（禁止）
	private:
		//コンストラクタ
		explicit RLockAsNecessary(const RLockAsNecessary& o) :Lock(o){}//コピーコンストラクタ（禁止）
	public:
		//ムーブコンストラクタ
		inline RLockAsNecessary(RLockAsNecessary&& lock) :
			Lock(std::move(lock))
		{}
	public:
		//コンストラクタ
		inline RLockAsNecessary(CRWLock& lock, const CThreadID& ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, ignore_thread_id, spin_count)
		{}
		inline RLockAsNecessary(CRWLock& lock, const THREAD_ID ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, ignore_thread_id, spin_count)
		{}
		inline RLockAsNecessary(CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, CThreadID::getThisID(), spin_count)
		{}
		//デストラクタ
		inline ~RLockAsNecessary()
		{}
	};
	//----------------------------------------
	//【クラス内クラス】ライトロッククラス
	class WLock : public Lock
	{
	private:
		//オペレータ
		WLock& operator=(const WLock& lock){ return *this; }//コピー演算子（禁止）
	private:
		//コンストラクタ
		explicit WLock(const WLock& lock) :Lock(lock){}//コピーコンストラクタ（禁止）
	public:
		//ムーブコンストラクタ
		inline WLock(WLock&& lock) :
			Lock(std::move(lock))
		{}
	public:
		//コンストラクタ
		inline WLock(CRWLock& lock, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			Lock(this, lock, spin_count)
		{}
		//デストラクタ
		inline ~WLock()
		{}
	};
	//----------------------------------------
	//【クラス内クラス】（以上で終了）

public:
	//【ロックオブジェクトを返すロックメソッド】
	//※右辺値参照を使用することにより、「コピーコンストラクタ」と
	//　区別して「ムーブコンストラクタ」を記述できる
	//※これを利用して、関数の内部で作成したオブジェクトの内容を
	//　呼び出し元のオブジェクトに移動する。
	//　ムーブコンストラクタでは、移動元オブジェクトを
	//　アンロック済み扱いにしているるので、関数終了時に
	//　ローカルオブジェクトのデストラクタが呼び出されても、
	//　アンロックしてしまうことがない。

	//【ロックオブジェクトを返すロックメソッド】リードロック
	RLock rLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RLock lock(*this, spin_count);
		return std::move(lock);
	}
	//【ロックオブジェクトを返すロックメソッド】必要に応じてリードロック
	RLockAsNecessary rLockAsNecessary(const CThreadID& ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, ignore_thread_id, spin_count);
		return std::move(lock);
	}
	RLockAsNecessary rLockAsNecessary(const THREAD_ID ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, ignore_thread_id, spin_count);
		return std::move(lock);
	}
	RLockAsNecessary rLockAsNecessary(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, spin_count);
		return std::move(lock);
	}
	//【ロックオブジェクトを返すロックメソッド】ライトロック
	WLock wLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		WLock lock(*this, spin_count);
		return std::move(lock);
	}

private:
	//メソッド　※ロッククラスからのみ使用

	//リードロック取得
	//※必要に応じてリードロックの機能を備える
	void rlock(const int spin_count, const THREAD_ID ignore_thread_id)
	{
		//全てライトロックにするモード用処理
		if (m_wlockPrioritized == ALL_WLOCK)
		{
			wlock(spin_count);
			return;
		}

		//リードロックスキップチェック
		//※リード・ライトロックオブジェクトインスタンス生成時、および、リードロック時に、
		//　共にスレッドIDが指定されていた場合、かつ、それが同じIDであった場合、
		//　リードロックをスキップする
		if (ignore_thread_id != INVALID_THREAD_ID && m_ignoreThreadId == ignore_thread_id)//&& m_writeLock.load() == false)
			//↑ライトロック状態はチェックしない
			//※プログラムを信頼して高速化を徹底する
			//※仮にこの判定を行っても、m_lock で保護しない限りは不確実なブロック
		{
			m_readLock.fetch_add(1);
			return;
		}

		//リードロック予約カウントアップ
		//※制御上は必要ないが、問題追跡時の参考用
		m_readLockReserved.fetch_add(1);

		//リードロック待機ループ
		while (1)
		{
			//内部変数更新ロック取得
			m_lock.lock(spin_count);

			//内部変数更新ロックを取得できたので、ライトロックの状態をチェック
			if (m_writeLock.load() == false &&//ライトロック状態ではない
				(m_wlockPrioritized != WLOCK_PRIORITIZED ||//ライトロック優先モードではない
				m_wlockPrioritized == WLOCK_PRIORITIZED && m_writeLockReserved.load() == 0))//ライトロック優先モードなら、ライトロック予約がないこともチェック
			{
				//リードロックOK
				m_readLock.fetch_add(1);//リードロックカウントアップ
				m_lock.unlock();//内部変数更新ロック解放
				break;
			}

			//内部変数更新ロック解放
			//※リードロックが取得できるまで再び待機
			m_lock.unlock();//内部変数更新ロック解放
		}

		//リードロック予約カウントダウン
		//※制御上は必要ないが、問題追跡時の参考用
		m_readLockReserved.fetch_sub(1);
	}
	//ライトロック取得
	void wlock(const int spin_count)
	{
		//ライトロック予約カウントアップ
		m_writeLockReserved.fetch_add(1);

		//ライトロック待機ループ
		while (1)
		{
			//内部変数更新ロック取得
			m_lock.lock(spin_count);

			//内部変数更新ロックを取得できたので、リードロックとライトロックの状態をチェック
			if (m_readLock.load() == 0 && m_writeLock.load() == false)
			{
				//ライトロックOK
				m_writeLock.store(true);//ライトロックON
				m_lock.unlock();//内部変数更新ロック解放
				break;
			}

			//内部変数更新ロック解放
			//※ライトロックが取得できるまで再び待機
			m_lock.unlock();//内部変数更新ロック解放
		}

		//ライトロック予約カウントダウン
		m_writeLockReserved.fetch_sub(1);
	}
	//リードロック解放
	void runlock()
	{
		//全てライトロックにするモード用処理
		if (m_wlockPrioritized == ALL_WLOCK)
		{
			wunlock();
			return;
		}

		//リードロックカウントダウン
		m_readLock.fetch_sub(1);
	}
	//ライトロック解放
	void wunlock()
	{
		//ライトロックOFF
		m_writeLock.store(false);
	}
public:
	//アクセッサ
	THREAD_ID getIgnoreThreadID() const { return m_ignoreThreadId; }//「必要に応じてリードロック」用のスレッドID
	void setIgnoreThreadID(const THREAD_ID thread_id) { m_ignoreThreadId = thread_id; }//「必要に応じてリードロック」用のスレッドIDを更新
	int getReadLockReserved() const { return m_readLockReserved.load(); }//リードロック予約カウンタ ※制御上は必要ないが、問題追跡時の参考用
	int getReadLock() const { return m_readLock.load(); }//リードロックカウンタ
	int getWriteLockReserved() const { return m_writeLockReserved.load(); }//ライトロック予約カウンタ
	bool getWriteLock() const { return m_writeLock.load(); }//ライトロックフラグ
	E_WLOCK_PRIORITY getWlockPrioritized() const { return m_wlockPrioritized; }//ライトロック優先度
public:
	//コンストラクタ
	CRWLock(const THREAD_ID ignore_thread_id, const E_WLOCK_PRIORITY wlock_prioritized) :
		m_ignoreThreadId(ignore_thread_id),
		m_readLockReserved(0),
		m_readLock(0),
		m_writeLockReserved(0),
		m_writeLock(false),
		m_wlockPrioritized(wlock_prioritized)
	{}
	CRWLock(const CThreadID& ignore_thread_id, const E_WLOCK_PRIORITY wlock_prioritized) :
		CRWLock(ignore_thread_id.getID(), wlock_prioritized)
	{}
	CRWLock(const CThreadID& ignore_thread_id) :
		CRWLock(ignore_thread_id.getID(), WLOCK_PRIORITIZED)
	{}
	CRWLock(const THREAD_ID ignore_thread_id) :
		CRWLock(ignore_thread_id, WLOCK_PRIORITIZED)
	{}
	CRWLock(const E_WLOCK_PRIORITY wlock_prioritized) :
		CRWLock(CThreadID::getThisID(), wlock_prioritized)
	{}
	CRWLock() :
		CRWLock(CThreadID::getThisID(), WLOCK_PRIORITIZED)
	{}
	//デストラクタ
	~CRWLock()
	{}
private:
	//フィールド
	THREAD_ID m_ignoreThreadId;//「必要に応じてリードロック」用のスレッドID
	std::atomic<int> m_readLockReserved;//リードロック予約カウンタ ※制御上は必要ないが、問題追跡時の参考用
	std::atomic<int> m_readLock;//リードロックカウンタ
	std::atomic<int> m_writeLockReserved;//ライトロック予約カウンタ
	std::atomic<bool> m_writeLock;//ライトロックフラグ
	CSpinLock m_lock;//内部変数更新用ロックフラグ
	E_WLOCK_PRIORITY m_wlockPrioritized;//ライトロック優先度
};

//「リードロッククラス」「必要に応じてリードロッククラス」「ライトロッククラス」の別名を設定
typedef CRWLock::RLock CRWLockR;
typedef CRWLock::RLockAsNecessary CRWLockR_AsNecessary;
typedef CRWLock::WLock CRWLockW;

//【C++11スタイル】「リードロッククラス」「必要に応じてリードロッククラス」「ライトロッククラス」の別名を設定
//using CRWLockR = CRWLock::RLock;
//using CRWLockR_AsNecessary = CRWLock::RLockAsNecessary;
//using CRWLockW = CRWLock::WLock;

//----------------------------------------
//リード・ライトロックヘルパークラス
//※ロッククラスを用いずに、直接リード・ライトロックを操作するためのクラス
//※濫用禁止
class CRWLockHelper
{
public:
	//メソッド

	//リードロック取得
	void rLock(const int spin_count)
	{
		m_lock.rlock(spin_count, INVALID_THREAD_ID);
	}
	//必要に応じてリードロック取得
	void rLockAsNecessary(const CThreadID& ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		m_lock.rlock(spin_count, ignore_thread_id.getID());
	}
	void rLockAsNecessary(const THREAD_ID ignore_thread_id, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		m_lock.rlock(spin_count, ignore_thread_id);
	}
	void rLockAsNecessary(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		m_lock.rlock(spin_count, CThreadID::getThisID());
	}
	//ライトロック取得
	void wLock(const int spin_count)
	{
		m_lock.wlock(spin_count);
	}
	//リードロック解放
	void rUnlock()
	{
		m_lock.runlock();
	}
	//ライトロック解放
	void wUnlock()
	{
		m_lock.wunlock();
	}
public:
	//コンストラクタ
	CRWLockHelper(CRWLock& lock) :
		m_lock(lock)
	{}
	//デストラクタ
	~CRWLockHelper()
	{}
private:
	//フィールド
	CRWLock& m_lock;//リード・ライトオブジェクトの参照
};

//--------------------------------------------------------------------------------
//ハッシュテーブル
//--------------------------------------------------------------------------------
//データ構造とアルゴリズム
//【特徴】
//・ダブルハッシュアルゴリズムを採用。
//　  - ハッシュ① ... 最初のインデックス。キーに応じて生成。
//　  - ハッシュ② ... 衝突の際のインデックスの歩幅。キーに応じて生成。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【本プログラムにおける実装要件】
//・固定配列で実装し、一切メモリ確保・削除をしない。
//・キー重複を許容しないアルゴリズムとする。
//・文字列（std::string/char*）のキーをサポートしない。
//・代わりに、文字列キーは自動的にcrc32変換を行う。（文字列は保持しない）
//・処理効率化のために、データの削除時は実際に削除せず、
//　削除済みフラグを用いるものとする。
//　※検索処理は、削除済みのデータを検出しても打ち切らないことで効率化する。
//　※このため、頻繁に登録／削除を繰り返すと、未登録データ検索時の
//　　速度が劣化する可能性がある。
//・STL（std::unodered_map）との違いは下記の通り
//    - 固定長配列である。（STLは自動拡張する）
//    - キーと値のペアで扱わない。
//　　- insert/erase時のイテレータに対応しない。
//    - 赤黒木コンテナ（rb_tree）の実装と合わせた構造にしており、
//　　  操作用テンプレート構造体を用いる。
//--------------------------------------------------------------------------------

#include <bitset>//std::bitset用
#include <cstddef>//srd::size_t用
#include <iterator>//std::iterator用
#include <utility>//std::move用
#include <string>//std::string用

#ifdef USE_GCC
#include "../StaticCRC32_unix/constexpr.h"
#else//USE_GCC
#include "../../StaticCRC32/StaticCRC32/src/constexpr/constexpr.h"
#endif//USE_GCC

namespace hash_table
{
	//--------------------
	//ハッシュテーブルデータ操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public hash_table::base_ope_t<派生構造体, キー型, 値型, キーの最小値= 0u, キーの最大値 = 0xffffffffu, 不正なキー = 0xffffffffu>
	//	struct ope_t : public hash_table::ope_t<ope_t, crc32_t, data_t, 500>
	//	{
	//		//キーを取得
	//		inline static key_type getKey(const value_type& value){ return ???; }
	//	};
	template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	struct base_ope_t
	{
		//定数
		static const KEY_TYPE KEY_MIN = _KEY_MIN;//キーの最小値
		static const KEY_TYPE KEY_MAX = _KEY_MAX;//キーの最大値
		static const KEY_TYPE INVALID_KEY = _INVALID_KEY;//不正なキー

		//型
		typedef OPE_TYPE ope_type;//データ操作型
		typedef VALUE_TYPE value_type;//値型
		typedef KEY_TYPE key_type;//キー型

		//デストラクタ呼び出し
		static void callDestructor(value_type* obj){ obj->~VALUE_TYPE(); }
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::value_type value_type; \
		typedef typename ope_type::key_type key_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type;
	
	//----------------------------------------
	//ハッシュテーブルコンテナ用定数
	enum replace_attr_t : unsigned char//データ置換属性
	{
		NEVER_REPLACE,//キーが重複するデータは登録できない（置換しない）
		REPLACE,//キーが重複するデータは置換して登録する
	};
	enum auto_lock_attr_t : unsigned char//自動ロック属性
	{
		NEVER_LOCK,//ロックしない
		AUTO_WRITE_LOCK,//自動ライトロック
	};
	//----------------------------------------
	//ハッシュテーブルコンテナ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _AUTO_REHASH_RATIO = 25, int _FINDING_CYCLE_LIMIT = 0, std::size_t _INDEX_STEP_BASE = 5>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//定数
		static const size_type ORIGINAL_TABLE_SIZE = _TABLE_SIZE;//テーブルサイズ（元々指定されたサイズ）
		static const size_type TABLE_SIZE = makePrimeEqNextMeta<ORIGINAL_TABLE_SIZE>::value;//テーブルサイズ（指定サイズと同じか、それより大きい素数）
		static const size_type TABLE_SIZE_EXTENDED = TABLE_SIZE - ORIGINAL_TABLE_SIZE;//指定サイズから拡張したサイズ
		static const size_type  AUTO_REHASH_RATIO = _AUTO_REHASH_RATIO;//自動リハッシュ実行の基準割合 ※削除済み件数が全体サイズの一定割合以上になったら自動リハッシュ ※0で自動リハッシュなし
		static const size_type  AUTO_REHASH_SIZE = AUTO_REHASH_RATIO == 0 ? 0 : TABLE_SIZE * AUTO_REHASH_RATIO / 100;//自動リハッシュ実行の基準サイズ ※割合とテーブルサイズから計算
		static const int FINDING_CYCLE_LIMIT = _FINDING_CYCLE_LIMIT;//検索時の巡回回数の制限 ※0で無制限
		static const key_type KEY_MIN = ope_type::KEY_MIN;//キーの最小値
		static const key_type KEY_MAX = ope_type::KEY_MAX;//キーの最大値
		static const index_type INDEX_STEP_BASE = _INDEX_STEP_BASE;//検索巡回時のインデックスのス歩幅の基準値 ※必ず素数でなければならない
		static const index_type INVALID_INDEX = 0xffffffffu;//無効なインデックス
	public:
		//メタ関数
		//キー範囲定数計算（２バリエーション）
		template <bool COND, typename size_type, typename key_type, key_type KEY_MIN, key_type KEY_MAX>
		struct calcKeyRangeImpl{
			static const key_type value = KEY_MAX - KEY_MIN + 1;
		};
		template <typename size_type, typename key_type, key_type KEY_MIN, key_type KEY_MAX>
		struct calcKeyRangeImpl<true, size_type, key_type, KEY_MIN, KEY_MAX>{
			static const key_type value = 0;
		};
		//インデックス計算関数（２バリエーション）
		template <bool COND, typename size_type, typename index_type, typename key_type, size_type TABLE_SIZE, key_type KEY_MIN, key_type KEY_RANGE>
		struct calcIndexImpl{
			inline static index_type calc(const key_type key){ return (key - KEY_MIN) % TABLE_SIZE; }//キーからインデックスを計算 ※キーの範囲がテーブルサイズより大きい場合
		};
		template <typename size_type, typename index_type, typename key_type, size_type TABLE_SIZE, key_type KEY_MIN, key_type KEY_RANGE>
		struct calcIndexImpl<true, size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE>{
			inline static index_type calc(const key_type key){ return (key - KEY_MIN) * (TABLE_SIZE / KEY_RANGE) % TABLE_SIZE; }//キーからインデックスを計算 ※キーの範囲がテーブルサイズ以下の場合
		};
	public:
		//定数
		static const key_type KEY_RANGE = calcKeyRangeImpl<((KEY_MIN == 0u && KEY_MAX == 0xffffffffu) || KEY_MIN >= KEY_MAX), size_type, key_type, KEY_MIN, KEY_MAX>::value;//キーの範囲
		//静的アサーション
		static_assert(TABLE_SIZE > INDEX_STEP_BASE, "hash_table::container: TABLE_SIZE is required larger than INDEX_STEP_BASE.");
		static_assert(isPrimeMeta<INDEX_STEP_BASE>::value == true, "hash_table::container: INDEX_STEP_BASE is required prime.");
	public:
		//--------------------
		//イテレータ用の型
		struct set
		{
			//フィールド
			index_type m_index;//（実際の）インデックス
			index_type m_primaryIndex;//本来のインデックス
			key_type m_key;//現在のキー
			value_type* m_value;//現在の値
			bool m_isDeleted;//削除済み

			//オペレータ
			inline const value_type& operator*() const { return m_value; }
			inline value_type& operator*(){ return m_value; }
			inline const value_type* operator->() const { return m_value; }
			inline value_type* operator->(){ return m_value; }

			//メソッド
			inline bool isPrimaryIndex() const { return m_index == m_primaryIndex; }//実際のインデックスは、本来のインデックスと一致するか？
			void update(const index_type index, const index_type primary_index, const key_type key, const value_type* value, const bool is_deleted)
			{
				m_index = index;
				m_primaryIndex = primary_index;
				m_key = key;
				m_value = const_cast<value_type*>(value);
				m_isDeleted = is_deleted;
			}

			//コストラクタ
			set(const index_type index, const index_type primary_index, const key_type key, const value_type* value, const bool is_deleted) :
				m_index(index),
				m_primaryIndex(primary_index),
				m_key(key),
				m_value(const_cast<value_type*>(value)),
				m_isDeleted(is_deleted)
			{}
		};
	public:
		//--------------------
		//イテレータ
		class iterator;
		typedef const iterator const_iterator;
		class iterator : public std::iterator<std::forward_iterator_tag, value_type>
		{
			friend class container;
		public:
			//キャストオペレータ
			inline operator const set() const { return *m_set; }
			inline operator set&(){ return *m_set; }
			inline operator const value_type() const { return *m_set.m_value; }
			inline operator value_type&(){ return *m_set.m_value; }
			inline operator const value_type*() const { return m_set.m_value; }
			inline operator value_type*(){ return m_set.m_value; }
			inline operator key_type() const { return m_set.m_key; }
		public:
			//オペレータ
			inline const set& operator*() const { return m_set; }
			inline set& operator*(){ return m_set; }
			inline const value_type* operator->() const { return m_set.value; }
			inline value_type* operator->(){ return m_set.value; }
			//比較オペレータ
			inline bool operator==(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX && rhs.m_set.m_index == INVALID_INDEX ? true :
				       m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index == rhs.m_set.index;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX && rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? true :
				       m_set.m_index != rhs.m_set.m_index;
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index > rhs.m_set.m_index;
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index >= rhs.m_set.m_index;
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index < rhs.m_set.m_index;
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return m_set.m_index == INVALID_INDEX || rhs.m_set.m_index == INVALID_INDEX ? false :
				       m_set.m_index <= rhs.m_set.m_index;
			}
			//演算オペレータ
			inline const_iterator& operator++() const
			{
				updateSet(m_con.getNextIndex(m_set.m_index));
				return *this;
			}
			inline const_iterator& operator--() const
			{
				updateSet(m_con.getPrevIndex(m_set.m_index));
				return *this;
			}
			inline iterator& operator++()
			{
				updateSet(m_con.getNextIndex(m_set.m_index));
				return *this;
			}
			inline iterator& operator--()
			{
				updateSet(m_con.getPrevIndex(m_set.m_index));
				return *this;
			}
			const_iterator operator++(int) const
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			const_iterator& operator+=(const int val) const
			{
				for (int i = 0; i < val; ++i)
					++(*this);
				return *this;
			}
			const_iterator& operator-=(const int val) const
			{
				for (int i = 0; i < val; ++i)
					--(*this);
				return *this;
			}
			iterator& operator+=(const int val)
			{
				for (int i = 0; i < val; ++i)
					++(*this);
				return *this;
			}
			iterator& operator-=(const int val)
			{
				for (int i = 0; i < val; ++i)
					--(*this);
				return *this;
			}
			const_iterator operator+(const int val) const
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			const_iterator operator-(const int val) const
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
			iterator operator+(const int val)
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			iterator operator-(const int val)
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
		public:
			//ムーブオペレータ
			iterator& operator=(const_iterator&& rhs)
			{
				m_set = rhs.m_set;
				return *this;
			}
			//コピーオペレータ
			inline iterator& operator=(const_iterator& rhs)
			{
				return operator=(std::move(rhs));
			}
		public:
			//アクセッサ
			inline index_type getIndex() const { return m_set.m_index; }//（実際の）インデックス
			inline index_type getPrimaryIndex() const { return m_set.m_primaryIndex; }//本来のインデックス
			inline key_type getKey() const { return m_set.m_key; }//現在のキー
			inline const value_type* getValue() const { return m_set.m_value; }//現在の値
			inline value_type* getValue(){ return m_set.m_value; }//現在の値
			inline bool isDeleted() const { return m_set.m_isDeleted; }//削除済み
			inline bool isPrimaryIndex() const { return m_set.isPrimaryIndex(); }//本来のインデックスか？
		private:
			//メソッド
			void updateSet(const index_type index) const
			{
				if (index == INVALID_INDEX)
					m_set.update(INVALID_INDEX, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
				else
					m_set.update(index, m_con.calcIndex(m_con.m_keyTable[index]), m_con.m_keyTable[index], reinterpret_cast<const value_type*>(m_con.m_table[index]), m_con.m_deleted[index]);
			}
		public:
			//ムーブコンストラクタ
			iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_set(obj.m_set)
			{}
			//コピーコンストラクタ
			inline iterator(const_iterator& obj) :
				iterator(std::move(obj))
			{}
			//コンストラクタ
			iterator(const container& con) :
				m_con(con),
				m_set(0, nullptr, false)
			{}
			iterator(const container& con, const index_type index, const key_type key, const value_type* value, const bool is_deleted) :
				m_con(con),
				m_set(index, con.calcIndex(key), key, value, is_deleted)
			{}
			//デストラクタ
			inline ~iterator()
			{}
		protected:
			//フィールド
			const container& m_con;//コンテナ
			mutable set m_set;//現在のキー/値/削除済みフラグ
		};
	public:
		//アクセッサ
		inline replace_attr_t getReplaceAttr() const { return m_replaceAttr; }//置換属性を取得
		inline auto_lock_attr_t getAutoLockAttr() const { return m_autoLockAttr; }//自動ロック属性を取得
		inline size_type getOriginalTableSize() const { return ORIGINAL_TABLE_SIZE; }//指定されたテーブルサイズを取得
		inline size_type getTableSize() const { return TABLE_SIZE; }//（実際の）テーブルサイズを取得
		inline size_type getTableSizeExtended() const { return TABLE_SIZE_EXTENDED; }//指定のテーブルサイズからの増分を取得
		inline size_type getAutoRehashRatio() const { return AUTO_REHASH_RATIO; }//自動リハッシュ実行の基準割合
		inline size_type getAutoRehashSize() const { return AUTO_REHASH_SIZE; }//自動リハッシュ実行の基準サイズ
		inline int getFindingCycleLimit() const { return FINDING_CYCLE_LIMIT; }//検索時の巡回回数の制限を取得
		inline key_type getKeyMin() const { return KEY_MIN; }//キーの最小値を取得
		inline key_type getKeyMax() const { return KEY_MAX; }//キーの最大値を取得
		inline key_type getKeyRange() const { return KEY_RANGE; }//キーの範囲を取得
		inline index_type getIndexStepBase() const { return INDEX_STEP_BASE; }//検索巡回時のインデックスの歩幅の基準値（実際のステップ数は、この値を係数にキーから算出する）
		inline int getUsingCount() const { return m_usingCount; }//使用中データ数を取得
		inline int getDeletedCount() const { return m_deletedCount; }//削除済みデータ数を取得
		inline int getMaxFindingCycle() const { return m_maxFindingCycle; }//検索時の最大巡回回数を取得
		int getNotOptimizedCount() const//最適化されていないデータ件数を取得 ※検索の際に2回以上の巡回が必要なデータ = 本来のインデックスと実際のインデックスが異なるデータ
		{
			int count = 0;
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || m_deleted[index])
					continue;
				if (index != calcIndex(m_keyTable[index]))
					++count;
			}
			return count;
		}
	public:
		std::size_t max_size() const { return TABLE_SIZE; }//最大要素数を取得
		std::size_t capacity() const { return TABLE_SIZE; }//最大要素数を取得
		std::size_t size() const { return m_usingCount - m_deletedCount; }//使用中の要素数を取得
		bool empty() const { return size() == 0; }//空か？
	public:
		//検索系アクセッサ：キーで検索して値を返す
		//※マルチスレッドで処理する際は、一連の処理ブロック全体の前後で
		//　リードロックの取得を行うようにすること。
		value_type* at(const key_type key){ return findValue(key); }
		value_type* at(const char* key){ return findValue(key); }
		value_type* at(const std::string& key){ return findValue(key); }
		value_type* at(const value_type& value){ return findValue(value); }
		const value_type* at(const key_type key) const { return findValue(key); }
		const value_type* at(const char* key) const { return findValue(key); }
		const value_type* at(const std::string& key) const { return findValue(key); }
		const value_type* at(const value_type& value) const { return findValue(value); }
		value_type* operator[](const key_type key){ return findValue(key); }
		value_type* operator[](const char* key){ return findValue(key); }
		value_type* operator[](const std::string& key){ return findValue(key); }
		value_type* operator[](const value_type& value){ return findValue(value); }
		const value_type* operator[](const key_type key) const { return findValue(key); }
		const value_type* operator[](const char* key) const { return findValue(key); }
		const value_type* operator[](const std::string& key) const { return findValue(key); }
		const value_type* operator[](const value_type& value) const { return findValue(value); }
	public:
		//キャストオペレータ
		operator CRWLock&(){ return m_lock; }//リード・ライトロック
	public:
		//メソッド
		inline index_type calcIndexStep(const key_type key) const { return INDEX_STEP_BASE - key % INDEX_STEP_BASE; }//キーからインデックスの歩幅（第二ハッシュ）を計算
		inline index_type calcIndex(const key_type key) const { return calcIndexImpl<(TABLE_SIZE >= KEY_RANGE && KEY_RANGE > 0), size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE >::calc(key); }//キーからインデックス（第一ハッシュ）を計算
		inline index_type calcNextIndex(const key_type key, const index_type index) const { return (index + calcIndexStep(key)) % TABLE_SIZE; }//次のインデックスを計算（指定のインデックスに歩幅を加算）
	public:
		//インデックスを取得
		//※マルチスレッドで処理する際は、一連の処理ブロック全体の前後で
		//　リードロックの取得を行うようにすること。
		index_type getFirstIndex() const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (m_using[index])
					return index;
			}
			return INVALID_INDEX;
		}
		index_type getLastIndex() const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (index_type index = TABLE_SIZE; index > 0; --index)
			{
				if (m_using[index - 1])
					return index - 1;
			}
			return INVALID_INDEX;
		}
		index_type getNextIndex(const index_type index) const
		{
			index_type next_index = index == INVALID_INDEX ? 0 : index + 1;
			if (index < 0 || index >= TABLE_SIZE - 1 || m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (; next_index < TABLE_SIZE; ++next_index)
			{
				if (m_using[next_index])
					return next_index;
			}
			return INVALID_INDEX;
		}
		index_type getPrevIndex(const index_type index) const
		{
			index_type now_index = index == INVALID_INDEX ? TABLE_SIZE : index;
			if (index <= 0 || index >= TABLE_SIZE || m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (; now_index > 0; --now_index)
			{
				if (m_using[now_index - 1])
					return now_index - 1;
			}
			return INVALID_INDEX;
		}
		//イテレータを取得
		//※マルチスレッドで処理する際は、一連の処理ブロック全体の前後で
		//　リードロックの取得を行うようにすること。
		inline const_iterator begin() const
		{
			const index_type index = getFirstIndex();//先頭インデックスを取得
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, index, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator end() const
		{
			return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
		}
		inline iterator begin(){ return const_cast<const container*>(this)->begin(); }
		inline iterator end(){ return const_cast<const container*>(this)->end(); }
		inline const_iterator cbegin() const { return this->begin(); }
		inline const_iterator cend() const { return this->end(); }
	private:
		//キーで検索してインデックスを取得（本体）
		index_type _findIndex(const key_type key) const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			const index_type index_first = calcIndex(key);//キーからインデックス（ハッシュ）を計算
			index_type index = index_first;
			do
			{
				if (!m_using[index])//未使用インデックスなら検索失敗
					break;
				if (!m_deleted[index] && m_keyTable[index] == key)//キーが一致するインデックスなら検索成功
					return index;
				index = calcNextIndex(key, index);//次のインデックスへ
			} while (index != index_first);//最初のインデックスに戻ったら終了（検索失敗）
			return INVALID_INDEX;
		}
		//キーで検索してインデックスを取得
		//※マルチスレッドで処理する際は、一連の処理ブロック全体の前後で
		//　リードロックの取得を行うようにすること。
		inline index_type findIndex(const key_type key) const{ return _findIndex(key); }
		inline index_type findIndex(const char* key) const{ return _findIndex(calcCRC32(key)); }
		inline index_type findIndex(const std::string& key) const{ return _findIndex(key.c_str()); }
		inline index_type findIndex(const value_type& value) const{ return _findIndex(ope_type::getKey(value)); }
	private:
		//キーで検索して値を取得（本体）
		inline const value_type* _findValue(const key_type key) const
		{
			const index_type index = findIndex(key);//検索してインデックスを取得
			if (index == INVALID_INDEX)
				return nullptr;
			return reinterpret_cast<const value_type*>(&m_table[index]);
		}
	public:
		//キーで検索して値を取得
		//※マルチスレッドで処理する際は、一連の処理ブロック全体の前後で
		//　リードロックの取得を行うようにすること。
		inline const value_type* findValue(const key_type key) const { return _findValue(key); }
		inline const value_type* findValue(const char* key) const { return _findValue(calcCRC32(key)); }
		inline const value_type* findValue(const std::string& key) const { return _findValue(key.c_str()); }
		inline const value_type* findValue(const value_type& value) const { return _findValue(ope_type::getKey(value)); }
		inline value_type* findValue(const key_type key){ return const_cast<value_type*>(_findValue(key)); }
		inline value_type* findValue(const char* key){ return const_cast<value_type*>(_findValue(calcCRC32(key))); }
		inline value_type* findValue(const std::string& key){ return const_cast<value_type*>(_findValue(key.c_str())); }
		inline value_type* findValue(const value_type& value){ return const_cast<value_type*>(_findValue(ope_type::getKey(value))); }
		//キーで検索してイテレータを取得
		//※マルチスレッドで処理する際は、一連の処理ブロック全体の前後で
		//　リードロックの取得を行うようにすること。
		const_iterator find(const key_type key) const
		{
			const index_type index = findIndex(key);
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, index, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator find(const char* key) const { return find(calcCRC32(key)); }
		inline const_iterator find(const std::string& key) const { return find(key.c_str()); }
		inline const_iterator find(const value_type& value) const { return find(ope_type::getKey(value)); }
		inline iterator find(const key_type key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const char* key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const std::string& key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const value_type value){ return const_cast<const container*>(this)->find(value); }
	private:
		//キー割り当て（本体）
		//※割り当てた配列要素（データテーブル）のポインタを返す
		value_type* _assign(const key_type key)
		{
			if (m_usingCount == TABLE_SIZE && m_deletedCount == 0)
				return nullptr;
			index_type index = _findIndex(key);
			if (m_replaceAttr == NEVER_REPLACE && index != INVALID_INDEX)//同じキーが既に割り当て済みなら割り当て失敗
				return nullptr;
			int find_cycle = 0;
			if (index != INVALID_INDEX)
			{
				//置換
				_eraseByIndex(index);//デストラクタの呼び出しあり
			}
			else
			{
				//新規登録
				const index_type index_first = calcIndex(key);//キーからインデックス（ハッシュ）を計算
				index = index_first;
				do
				{
					++find_cycle;
					if (!m_using[index] || m_deleted[index])//未使用／削除済みインデックスなら割り当て成功
						break;
					if (FINDING_CYCLE_LIMIT > 0 && find_cycle == FINDING_CYCLE_LIMIT)//巡回回数が制限に達したら割り当て失敗
						return nullptr;
					index = calcNextIndex(key, index);//次のインデックスへ
				} while (index != index_first);//最初のインデックスに戻ったら終了（割り当て失敗）
			}
			m_keyTable[index] = key;//キーテーブルにキー登録
			if (!m_using[index])//未使用インデックスの割り当てなら使用中数を調整
			{
				m_using[index] = true;//使用中フラグをセット
				++m_usingCount;//使用中数をカウントアップ
			}
			if (m_deleted[index])//削除済みインデックスの再割り当てなら削除数を調整
			{
				m_deleted[index] = false;//削除済みフラグをリセット
				--m_deletedCount;//削除済み数をカウントダウン
			}
			m_maxFindingCycle = m_maxFindingCycle >= find_cycle ? m_maxFindingCycle : find_cycle;//最大巡回回数を更新
			return reinterpret_cast<value_type*>(&m_table[index]);
		}
	public:
		//キー割り当て
		//※割り当てた配列要素（データテーブル）のポインタを返す
		//※処理中、ライトロックを取得する（自動ライトロック属性設定時）
		inline value_type* assign(const key_type key)
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//ライトロック
				return _assign(key);
			}
			return _assign(key);
		}
		inline value_type* assign(const char* key){ return assign(calcCRC32(key)); }
		inline value_type* assign(const std::string& key){ return assign(key.c_str()); }
		inline value_type* assign(const value_type& value){ return assign(ope_type::getKey(value)); }
	private:
		//キー割り当てして値を挿入（コピー）（本体）
		//※オブジェクトのコピーが発生する点に注意
		value_type* _insert(const key_type key, const value_type& value)
		{
			value_type* assigned_value = _assign(key);
			if (!assigned_value)
				return nullptr;
			*assigned_value = value;
			return assigned_value;
		}
	public:
		//キー割り当てして値を挿入（コピー）
		//※オブジェクトのコピーが発生する点に注意
		//※処理中、ライトロックを取得する（自動ライトロック属性設定時）
		inline value_type* insert(const key_type key, const value_type& value)
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//ライトロック
				return _insert(key, value);
			}
			return _insert(key, value);
		}
		inline value_type* insert(const char* key, const value_type& value){ return insert(calcCRC32(key), value); }
		inline value_type* insert(const std::string& key, const value_type& value){ return insert(key.c_str(), value); }
		//値を挿入（コピー）し、キーは自動割り当て
		//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
		//※オブジェクトのコピーが発生する点に注意
		inline value_type* insertAuto(const value_type& value){ return insert(ope_type::getKey(value), value); }
	private:
		//キー割り当てして値を初期化（本体）
		//※コンストラクタが呼び出される
		template<typename... Tx>
		value_type* _emplace(const key_type key, Tx... args)//const Tx&... args とも書ける
		{
			value_type* assigned_value = _assign(key);
			if (!assigned_value)
				return nullptr;
			assigned_value = new(assigned_value) value_type(args...);//コンストラクタ呼び出し
			return assigned_value;
		}
	public:
		//キー割り当てして値を初期化
		//※コンストラクタが呼び出される
		//※処理中、ライトロックを取得する（自動ライトロック属性設定時）
		template<typename... Tx>
		inline value_type* emplace(const key_type key, Tx... args)//const Tx&... args とも書ける
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//ライトロック
				return _emplace(key, args...);
			}
			return _emplace(key, args...);
		}
		template<typename... Tx>
		inline value_type* emplace(const char* key, Tx... args){ return emplace(calcCRC32(key), args...); }
		template<typename... Tx>
		inline value_type* emplace(const std::string& key, Tx... args){ return emplace(key.c_str(), args...); }
		//値を初期化して自動的にキー割り当て
		//※オブジェクトのコピーが発生する点に注意
		//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
		//※処理中、ライトロックを取得する
		template<typename... Tx>
		inline value_type* emplaceAuto(Tx... args)
		{
			value_type value(args...);
			return insertAuto(value);
		}
	private:
		//インデックスを指定して削除
		void _eraseByIndex(const index_type index)
		{
			value_type* data_p = reinterpret_cast<value_type*>(&m_table[index]);
			ope_type::callDestructor(data_p);//デストラクタ呼び出し
			operator delete(data_p, data_p);//（作法として）deleteオペレータ呼び出し
			m_deleted[index] = true;//削除済みインデックスを更新
			++m_deletedCount;//削除済み数をカウントアップ
		}
		//キーを削除（本体）
		bool _erase(const key_type key)
		{
			const index_type index = findIndex(key);//検索してインデックスを取得
			if (index == INVALID_INDEX)//検索失敗なら削除失敗
				return false;
			_eraseByIndex(index);
			if (m_usingCount == m_deletedCount || m_deletedCount == AUTO_REHASH_SIZE)//自動リハッシュ
				_rehash();
			return true;
		}
	public:
		//キーを削除
		//※処理中、ライトロックを取得する（自動ライトロック属性設定時）
		inline bool erase(const key_type key)
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//ライトロック
				return _erase(key);
			}
			return _erase(key);
		}
		inline bool erase(const char* key){ return erase(calcCRC32(key)); }
		inline bool erase(const std::string& key){ return erase(key.c_str()); }
		//キーを削除
		//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
		inline bool eraseAuto(const value_type& value){ return erase(ope_type::getKey(value)); }
	private:
		//リハッシュ（本体）
		bool _rehash()
		{
			if (m_usingCount == 0 || m_deletedCount == 0)
				return false;
			if (m_usingCount == m_deletedCount)
			{
				_clear();
				return true;
			}
			m_maxFindingCycle = 1;//最大巡回回数を1にリセット
			//値の移動
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || m_deleted[index])//未使用インデックスまたは削除済みインデックスは処理をスキップ
					continue;
				const key_type key = m_keyTable[index];//キーを取得
				if (calcIndex(key) == index)//キーが本来のインデックスと異なる場合、移動を試みる
					continue;
				value_type* value = reinterpret_cast<value_type*>(m_table[index]);//現在の値を記憶
				m_deleted[index] = true;//一旦削除済みにする
				++m_deletedCount;       //（同上）
				value_type* value_new = _assign(key);//改めてキーを割り当て
				if (value_new != value)//インデックスが違っていたなら値を移動
				{
				#if 1
					*value_new = std::move(*value);//ムーブ演算子で移動
				#else
					memcpy(value_new, value, sizeof(value_type));//memcpyで移動
				#endif
				}
			}
			//削除済みインデックスのクリア
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || !m_deleted[index])//未使用インデックスまたは未削除インデックスは処理をスキップ
					continue;
				m_deleted[index] = false;//削除済みを解消する
				--m_deletedCount;       //（同上）
				m_using[index] = false;//使用中を解消する
				--m_usingCount;        //（同上）
			}
			return true;
		}
	public:
		//リハッシュ
		//※処理中、ライトロックを取得する（自動ライトロック属性設定時）
		inline bool rehash()
		{
			if (m_autoLockAttr == AUTO_WRITE_LOCK)
			{
				CRWLock::WLock lock(m_lock);//ライトロック
				return _rehash();
			}
			return _rehash();
		}
	private:
		//クリア（本体）
		void _clear()
		{
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (m_using[index] && !m_deleted[index])//使用中データはデストラクタ呼び出し
					_eraseByIndex(index);
			}
			m_using.reset();
			m_deleted.reset();
			m_usingCount = 0;
			m_deletedCount = 0;
			m_maxFindingCycle = 0;
		}
	public:
		//クリア
		//※処理中、ライトロックを取得する
		inline void clear()
		{
			CRWLock::WLock lock(m_lock);//ライトロック
			_clear();
		}
	public:
		//コンストラクタ
		container(const replace_attr_t replace_attr = NEVER_REPLACE, const auto_lock_attr_t auto_lock_attr = NEVER_LOCK, const CRWLock::E_WLOCK_PRIORITY wlock_prioritized = CRWLock::WLOCK_PRIORITIZED) :
			m_using(),
			m_deleted(),
			m_usingCount(0),
			m_deletedCount(0),
			m_maxFindingCycle(0),
			m_replaceAttr(replace_attr),
			m_autoLockAttr(auto_lock_attr),
			m_lock(wlock_prioritized)
		{}
		//デストラクタ
		~container()
		{}
	private:
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//データテーブル
		key_type m_keyTable[TABLE_SIZE];//キーテーブル
		std::bitset<TABLE_SIZE> m_using;//キー設定済みフラグ ※登録を削除してもfalseにならない（リハッシュ時には調整される）
		std::bitset<TABLE_SIZE> m_deleted;//削除済みフラグ
		int m_usingCount;//使用中データ数 ※登録を削除しても減らない（リハッシュ時には調整される）
		int m_deletedCount;//削除済みデータ数
		int m_maxFindingCycle;//検索時の最大巡回回数 ※登録を削除しても減らない（リハッシュ時には調整される）
		replace_attr_t m_replaceAttr;//データ置換属性
		auto_lock_attr_t m_autoLockAttr;//自動ロック属性
		CRWLock m_lock;//リード・ライトロック
	};
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace hash_table

//--------------------------------------------------------------------------------
//ハッシュテーブル＆素数計算テスト
//--------------------------------------------------------------------------------

#include <chrono>//C++11 時間計測用
#include <unordered_map>//C++11 std::unordered_map
#include <map>//C++11 std::map
#include <string.h>//strcpy用

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
//文字列操作関数
#ifdef USE_GCC
inline char* strcpy_s(char* dst, const std::size_t size, const char* src)
{
	return strcpy(dst, src);
}
inline char* strncpy_s(char* dst, const std::size_t size, const char* src, const std::size_t max)
{
	return strncpy(dst, src, max);
}
template<typename... Tx>
inline int sprintf_s(char* dst, const std::size_t size, const char* fmt, Tx... args)
{
	return sprintf(dst, fmt, args...);
}
#endif//USE_GCC

//----------------------------------------
//素数計算テスト

//【ランタイム版】素数表示
void printPrime(const std::size_t min, const std::size_t max)
{
	if (max > min)
		printPrime(min, max - 1);
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", max, isPrime(max) ? "PRIME.    " : "not prime.", makePrimePrev(max), makePrimeEqPrev(max), makePrimeNext(max), makePrimeEqNext(max));
}

//【メタプログラミング版】素数表示
template<std::size_t N>
void _printPrimeCommon()
{
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", N, isPrimeMeta<N>::value ? "PRIME.    " : "not prime.", makePrimePrevMeta<N>::value, makePrimeEqPrevMeta<N>::value, makePrimeNextMeta<N>::value, makePrimeEqNextMeta<N>::value);
}
template<std::size_t MIN, std::size_t MAX>
struct printPrimeMeta{
	void operator()()
	{
		printPrimeMeta<MIN, MAX - 1>()();
		_printPrimeCommon<MAX>();
	}
};
template<std::size_t MIN>
struct printPrimeMeta<MIN, MIN>{
	void operator()()
	{
		_printPrimeCommon<MIN>();
	}
};

//----------------------------------------
//ハッシュテーブル用テストデータ
struct data_t
{
	crc32_t m_key;//キー ※名前のハッシュ値
	int m_value;//値
	char m_name[20];//名前

	//コンストラクタ
	data_t(const char* name, const int value) :
		m_key(calcCRC32(name)),
		m_value(value)
	{
		strncpy_s(m_name, sizeof(m_name), name, sizeof(m_name) - 1);
		m_name[sizeof(m_name)-1] = '\0';
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(\"%s\", value)\n", name, value);
		//printf("    m_key=%d, m_name=[%s], m_value=%d\n", m_key, m_name, m_value);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
#ifdef TEST_DATA_WATCH_CONSTRUCTOR
	//ムーブオペレータ
	data_t& operator=(const data_t&& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::move_assignment_operator\n");
		return *this;
	}
	//コピーオペレータ
	data_t& operator=(const data_t& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::copy_assignment_operator\n");
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
	//デフォルトコンストラクタ
	data_t():
		m_key(0),
		m_value(0)
	{
		m_name[0] = '\0';
		printf("data_t::constructor\n");
	}
	//デストラクタ
	~data_t()
	{
		printf("data_t::destructor\n");
		//printf("  m_key=%d, m_name=[%s]\n", m_key, m_name);
	}
#endif//TEST_DATA_WATCH_CONSTRUCTOR
};

//----------------------------------------
//テストデータ操作クラス
#include <functional>//C++11 std::function用
struct ope_t : public hash_table::base_ope_t<ope_t, crc32_t, data_t>
{
	//キーを取得
	inline static key_type getKey(const value_type& value){ return value.m_key; }
};

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//時間計測
	auto begin_time = std::chrono::system_clock::now();
	auto prev_time = begin_time;

	//処理時間計測
	auto calcElapsedTime = [](const std::chrono::system_clock::time_point& now_time, const std::chrono::system_clock::time_point& prev_time) -> double
	{
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - prev_time);
		const auto elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		return elapsed_time;
	};
	auto getElapsedTime = [&calcElapsedTime](const std::chrono::system_clock::time_point& prev_time) -> double
	{
		return calcElapsedTime(std::chrono::system_clock::now(), prev_time);
	};

	//処理時間表示
	auto printElapsedTimeDirect = [&calcElapsedTime](const double elapsed_time, const bool is_preint) -> std::chrono::system_clock::time_point
	{
		if (is_preint)
			printf("*elapsed time=%.9llf sec.\n", elapsed_time);
		return std::chrono::system_clock::now();
	};
	auto printElapsedTime = [&calcElapsedTime, &printElapsedTimeDirect](const std::chrono::system_clock::time_point& prev_time, const bool is_print) -> std::chrono::system_clock::time_point
	{
		const auto now_time = std::chrono::system_clock::now();
		const auto elapsed_time = calcElapsedTime(now_time, prev_time);
		return printElapsedTimeDirect(elapsed_time, is_print);
	};

#if 0
	//--------------------
	//素数コンパイル時計算の再帰レベル限界チェック
	static const std::size_t x = 9999;
	printf("x=%d\n", x);
	printf("  isPrime=%s\n", isPrimeMeta<x>::value ? "true" : "False");
	printf("  prev=%d\n", makePrimePrevMeta<x>::value);
	printf("  next=%d\n", makePrimeNextMeta<x>::value);
	printf("  equalPrev=%d\n", makePrimeEqPrevMeta<x>::value);
	printf("  equalNext=%d\n", makePrimeEqNextMeta<x>::value);
#endif

#if 0
	//--------------------
	//素数計算のテスト
	static const std::size_t MIN = 1020;
	static const std::size_t MAX = 1030;
	
	printf("----- Check and Make Prime for Runtime -----\n");
	printPrime(MIN, MAX);
	
	printf("----- Check and Make Prime for Meta-Programming -----\n");
	printPrimeMeta<MIN, MAX>()();
#endif

#if 0
	//--------------------
	//ハッシュテーブルのインデックス計算ロジックテスト
	//※全てのインデックスが、正確にテーブルサイズ（素数）回の再計算を行う事で、元のインデックスに戻ることを確認。
	{
		int ng_count = 0;
		const ope_t::key_type key_min = 0;// con.getKeyMin();
		const ope_t::key_type key_max = 100000;// con.getKeyMax();
		const ope_t::key_type key_step = 1;
		for (ope_t::key_type key = key_min; key <= key_max; key += key_step)
		{
			if (key % (1024 * 1024) == 0)
				printf("pass ... Key:%d\n", key);
			std::size_t count = 0;
			std::size_t first_index = con.calcIndex(key);
			std::size_t index = first_index;
			do
			{
				index = con.calcNextIndex(key, index);
				++count;
			} while (index != first_index && count < con.getTableSize());
			if (count != con.getTableSize())
			{
				printf("%u is OUT! (count=%d)\n", key, count);
				++ng_count;
			}
		}
		printf("Chek Hash Table: NG=%d/%d\n", ng_count, con.getTableSize());
		for (std::size_t key = 10; key <= 30; key += 1)
		{
			printf("Key:%u -> Index;%u\n", key, con.calcIndex(key));
		}
	}
#endif

#if 0
	//--------------------
	//ハッシュテーブルテスト（旧）
	{
		hash_table::container<ope_t, 20> con(hash_table::AUTO_WRITE_LOCK);
		
		data_t* result;
		printf("- emplace -\n");
		result = con.emplace(110, "123", 123);
		data_t* obj = con[110];
		obj->m_value = 1234567;
		result = con.emplace(220, "456", 456);
		result = con.emplace(330, "789", 789);
		result = con.emplace(110, "123", 123);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".size()=%d\n", con.size());
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- erase -\n");
		con.erase(220);
		con.erase(330);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- emplace -\n");
		result = con.emplace(220, "456!", 4567);
		result = con.emplace("123", "123!!", 12345);
		result = con.emplaceAuto("456!!", 45679);
		result = con.emplace("789", "789!!", 78901);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- erase -\n");
		con.erase(220);
		con.erase(110);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- rehash -\n");
		con.rehash();
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
	}
#endif
	
	//--------------------
	//ハッシュテーブルテスト
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("Hash Table Test\n");
	printf("--------------------------------------------------------------------------------\n");
	typedef hash_table::container<ope_t, TEST_DATA_TABLE_SIZE, 0, 0> container_type;//自動リハッシュなし, 検索巡回回数制限なし
	container_type* con = new container_type(hash_table::NEVER_REPLACE, hash_table::NEVER_LOCK);//置換なし、自動ロックなし

	//ハッシュテーブルの基本情報表示
	auto printTableParameter = [&con]()
	{
		printf("\n");
		printf("--- Table Parameter ---\n");
		printf(".max_size()=%u\n", con->max_size());
		printf(".capacity()=%u\n", con->capacity());
		printf(".getOriginalTableSize()=%u\n", con->getOriginalTableSize());
		printf(".getTableSize()=%u\n", con->getTableSize());
		printf(".getTableSizeExtended()=%u\n", con->getTableSizeExtended());
		printf(".getAutoRehashRatio()=%u\n", con->getAutoRehashRatio());
		printf(".getAutoRehashSize()=%u\n", con->getAutoRehashSize());
		printf(".getFindingCycleLimit()=%u\n", con->getFindingCycleLimit());
		printf(".getKeyMin()=%u\n", con->getKeyMin());
		printf(".getKeyMax()=%u\n", con->getKeyMax());
		printf(".getKeyRange()=%u\n", con->getKeyRange());
		printf(".getReplaceAttr()=%u\n", con->getReplaceAttr());
		printf(".getAutoLockAttr()=%u\n", con->getAutoLockAttr());
	};
	printTableParameter();

	//テーブル状態表示
	auto printTableStatus = [&con]()
	{
		printf("\n");
		printf("--- Table Status ---\n");
		printf(".size()=%u\n", con->size());
		printf(".empty()=%u\n", con->empty());
		printf(".getUsingCount()=%u\n", con->getUsingCount());
		printf(".getDeletedCount()=%u\n", con->getDeletedCount());
		printf(".getMaxFindingCycle()=%u\n", con->getMaxFindingCycle());
		printf(".getNotOptimizedCount()=%u\n", con->getNotOptimizedCount());
	};
	printTableStatus();

	//ハッシュテーブルへのデータ登録
	auto insertData = [&con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- Insert Data ---\n");
		int insert_success = 0;
		int insert_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t* obj = nullptr;
			#define USE_INSERT_TYPE 1
			//【推奨】【登録方法①】emplace()メソッドにキーとコンストラクタパラメータを渡して登録する方法
			//※オブジェクトのコピーは発生しない
			#if USE_INSERT_TYPE == 1
			{
				obj = con->emplace(calcCRC32(name), name, i);//キーとコンストラクタパラメータを渡して登録
			}
			//【登録方法②】emplaceAuto()メソッドにコンストラクタパラメータを渡して登録する方法
			//※オブジェクトのコピーが発生するので少し遅い
			#elif USE_INSERT_TYPE == 2
			{
				obj = con->emplaceAuto(name, i);//コンストラクタパラメータを渡して登録
			}
			//【登録方法③】insert()メソッドにキーとオブジェクトを渡して登録する方法
			//※オブジェクトのコピーが発生するので少し遅い
			//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
			#elif USE_INSERT_TYPE == 3
			{
				data_t new_obj(name, i);
				obj = con->insert(calcCRC32(name), new_obj);
			}
			//【登録方法④】insertAuto()メソッドにオブジェクトを渡して登録する方法
			//※オブジェクトのコピーが発生するので少し遅い
			//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
			#elif USE_INSERT_TYPE == 4
			{
				data_t new_obj(name, i);
				obj = con->insertAuto(new_obj);
			}
			//【登録方法⑤】assign()メソッドでデータのポインタを取得し、そこに値を書き込む
			//※コンストラクタのないオブジェクトを扱う場合に有効
			#elif USE_INSERT_TYPE == 5
			{
				const crc32_t key = calcCRC32(name);
				obj = con->assign(key);
				if(obj)
				{
					obj->m_key = key;
					strncpy_s(obj->m_name, sizeof(obj->m_name), name, sizeof(obj->m_name) - 1);
					obj->m_name[sizeof(obj->m_name) - 1] = '\0';
					obj->m_value = i;
				}
			}
			#endif//USE_INSERT_TYPE
			if (obj)
			{
				++insert_success;
				printf_detail("OK\n");
			}
			else
			{
				++insert_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", insert_success, insert_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	insertData(0, TEST_DATA_TABLE_SIZE / 2, 1);

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	auto printTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf_detail("\n");
		printf_detail("--- Print Table ---\n");
		//for (container_type::set& set : +con)
		for (auto& set : *con)
		{
			printf_detail("%c[%6d](%6d) key=%08x, name=\"%s\", value=%d%s\n", set.isPrimaryIndex() ? ' ' : '*', set.m_index, set.m_primaryIndex, set.m_key, set->m_name, set->m_value, set.m_isDeleted ? " (DELETED)" : "");
		}
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	printTable();

	//ハッシュテーブルアクセス
	auto findTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Find Data ---\n");
		int find_success = 0;
		int find_failure = 0;
		for (int i = 0; i < TEST_DATA_TABLE_SIZE; ++i)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t* obj;
			crc32_t key;
			int index;
			int primary_index;
			bool is_primary_index;
			bool is_deleted;
			#define USE_FIND_TYPE 1
			//【推奨】【検索方法①】[]オペレータにキーを渡して検索する方法
			//※値を返す
			#if USE_FIND_TYPE == 1
			{
				obj = (*con)[name];
				if(obj)
				{
					key = obj->m_key;
					index = i;
					primary_index = con->calcIndex(key);
					is_primary_index = (index == primary_index);
					is_deleted = false;
				}
			}
			//【検索方法②】at()メソッドにキーを渡して検索する方法
			//※値を返す（[]オペレータと同じ）
			#elif USE_FIND_TYPE == 2
			{
				obj = con->at(name);
				if(obj)
				{
					key = obj->m_key;
					index = i;
					primary_index = con->calcIndex(key);
					is_primary_index = (index == primary_index);
					is_deleted = false;
				}
			}
			//【検索方法③】find()メソッドにキーを渡して検索する方法
			//※イテレータを返す
			#elif USE_FIND_TYPE == 3
			{
				container_type::iterator ite = con->find(name);
				obj = ite;
				if (obj)
				{
					key = ite.getKey();
					index = ite.getIndex();
					primary_index = ite.getPrimaryIndex();
					is_primary_index = ite.isPrimaryIndex();
					is_deleted = ite.isDeleted();
				}
			}
			#endif//USE_FIND_TYPE
			if (obj)
			{
				printf_detail("OK  %c[%6d](%6d) key=%08x, name=\"%s\", value=%d%s\n", is_primary_index ? ' ' : '*', index, primary_index, key, obj->m_name, obj->m_value, is_deleted ? " (DELETED)" : "");
				++find_success;
			}
			else
			{
				printf_detail("NG\n");
				++find_failure;
			}
		}
		printf("success=%d, failure=%d\n", find_success, find_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	findTable();

	//ハッシュテーブルからのデータ削除
	auto eraseData = [&con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- Erase Data ---\n");
		int erase_success = 0;
		int erase_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			bool result = false;
			#define USE_ERASE_TYPE 1
			//【推奨】【削除方法①】erase()メソッドにキーを渡して削除する方法
			#if USE_ERASE_TYPE == 1
			{
				result = con->erase(calcCRC32(name));//キーを渡して削除
			}
			//【削除方法②】eraseAuto()メソッドにオブジェクトを渡して削除する方法
			//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
			#elif USE_INSERT_TYPE == 2
			{
				data_t obj(name, i);
				result = con->eraseAuto(obj);//オブジェクトを渡して削除
			}
			#endif//USE_ERASETYPE
			if (result)
			{
				++erase_success;
				printf_detail("OK\n");
			}
			else
			{
				++erase_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", erase_success, erase_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	eraseData(0, TEST_DATA_TABLE_SIZE, 2);
	
	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//ハッシュテーブルへのデータ登録
	insertData(1, TEST_DATA_TABLE_SIZE, 2);

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//リハッシュ
	auto rehashTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Rehash Table ---\n");
		con->rehash();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	rehashTable();

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//クリア
	auto clearTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Clear Table ---\n");
		con->clear();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	clearTable();

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//ハッシュテーブルへのデータ登録
	insertData(0, TEST_DATA_TABLE_SIZE, 1);

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//ハッシュテーブルからのデータ削除
	eraseData(0, TEST_DATA_TABLE_SIZE, 1);

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();
	
	//--------------------
	//ハッシュテーブル削除
	delete con;
	con = nullptr;

	printf("\n");
	printf("End\n");
	printf("============================================================\n");
	begin_time = printElapsedTime(begin_time, true);//処理時間表示

	//--------------------
	//【比較用】【STL版】ハッシュテーブルテスト
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[STL] Hash Table Test\n");
	printf("--------------------------------------------------------------------------------\n");
	typedef std::unordered_map<crc32_t, data_t> stl_container_type;
	stl_container_type* stl_con = new stl_container_type();
	stl_con->reserve(TEST_DATA_TABLE_SIZE);

	//ハッシュテーブルの基本情報表示
	auto printSTLTableParameter = [&stl_con]()
	{
		printf("\n");
		printf("--- [STL] Table Parameter ---\n");
		printf(".max_size()=%u\n", stl_con->max_size());
	};
	printSTLTableParameter();

	//テーブル状態表示
	auto printSTLTableStatus = [&stl_con]()
	{
		printf("\n");
		printf("--- [STL] Table Status ---\n");
		printf(".size()=%u\n", stl_con->size());
		printf(".empty()=%u\n", stl_con->empty());
	};
	printSTLTableStatus();

	//ハッシュテーブルへのデータ登録
	auto insertSTLData = [&stl_con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- [STL] Insert Data ---\n");
		int insert_success = 0;
		int insert_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t obj(name, i);
			auto ite = stl_con->emplace(calcCRC32(name), obj);//キーとコンストラクタパラメータを渡して登録
			if (ite.second)
			{
				++insert_success;
				printf_detail("OK\n");
			}
			else
			{
				++insert_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", insert_success, insert_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	insertSTLData(0, TEST_DATA_TABLE_SIZE / 2, 1);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	auto printSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf_detail("\n");
		printf_detail("--- [STL] Print Table ---\n");
		//for (container_type::set& set : +con)
		for (auto& pair : *stl_con)
		{
			printf_detail("key=%08x, name=\"%s\", value=%d\n", pair.first, pair.second.m_name, pair.second.m_value);
		}
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	printSTLTable();

	//ハッシュテーブルアクセス
	auto findSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Find Data ---\n");
		int find_success = 0;
		int find_failure = 0;
		for (int i = 0; i < TEST_DATA_TABLE_SIZE; ++i)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			crc32_t key = calcCRC32(name);
			auto ite = stl_con->find(key);
			if (ite != stl_con->end())
			{
				printf_detail("OK  key=%08x, name=\"%s\", value=%d\n", ite->first, ite->second.m_name, ite->second.m_value);
				++find_success;
			}
			else
			{
				printf_detail("NG\n");
				++find_failure;
			}
		}
		printf("success=%d, failure=%d\n", find_success, find_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	findSTLTable();

	//ハッシュテーブルからのデータ削除
	auto eraseSTLData = [&stl_con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- [STL] Erase Data ---\n");
		int erase_success = 0;
		int erase_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			crc32_t key = calcCRC32(name);
			bool result = stl_con->erase(key) == 1;
			if (result)
			{
				++erase_success;
				printf_detail("OK\n");
			}
			else
			{
				++erase_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", erase_success, erase_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	eraseSTLData(0, TEST_DATA_TABLE_SIZE, 2);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//ハッシュテーブルへのデータ登録
	insertSTLData(1, TEST_DATA_TABLE_SIZE, 2);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//リハッシュ
	auto rehashSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Rehash Table ---\n");
		stl_con->rehash(TEST_DATA_TABLE_SIZE);
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	rehashSTLTable();

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//クリア
	auto clearSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Clear Table ---\n");
		stl_con->clear();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	clearSTLTable();

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//ハッシュテーブルへのデータ登録
	insertSTLData(0, TEST_DATA_TABLE_SIZE, 1);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//ハッシュテーブルからのデータ削除
	eraseSTLData(0, TEST_DATA_TABLE_SIZE, 1);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//--------------------
	//ハッシュテーブル削除
	delete stl_con;
	stl_con = nullptr;
	
	printf("\n");
	printf("End\n");
	printf("============================================================\n");
	printElapsedTime(begin_time, true);//処理時間表示

	//--------------------
	//ポインタ型のハッシュテーブルテスト
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Hash Table Test for Pointer\n");
		printf("--------------------------------------------------------------------------------\n");

		//操作型
		struct p_ope_t : public hash_table::base_ope_t<p_ope_t, int, data_t*>
		{
			//キーを取得
			inline static key_type getKey(const value_type& value){ return value->m_key; }
		};

		//ハッシュテーブル
		hash_table::container<p_ope_t, 100> p_con;

		//登録
		data_t obj1("0010", 123);
		data_t obj2("0020", 456);
		data_t obj3("0030", 789);
		p_con.insert(10, &obj1);
		p_con.insert(20, &obj2);
		p_con.insert(30, &obj3);

		//検索して表示
		auto printObj = [&p_con](const int key)
		{
			printf("[%2d] ... ", key);
			data_t** p = p_con[key];
			if (p && *p)
				printf("OK  name=\"%s\", val=%d\n", (*p)->m_name, (*p)->m_value);
			else
				printf("NG\n");
		};
		printObj(10);
		printObj(20);
		printObj(30);
		printObj(40);
	}

	//--------------------
	//関数型のハッシュテーブルテスト
	//※スクリプトなどから関数名（文字列）で関数を実行するような用途を想定
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Hash Table Test for Function\n");
		printf("--------------------------------------------------------------------------------\n");
		
		//操作型
		struct func_ope_t : public hash_table::base_ope_t<func_ope_t, crc32_t, std::function<int(int, int)>>
		{
		};
		
		//ハッシュテーブル
		hash_table::container<func_ope_t, 100> func_con;
		
		//関数型ハッシュテーブルテスト用関数：通常関数
		extern int func_add(int a, int b);

		//関数型ハッシュテーブルテスト用関数：関数オブジェクト
		struct func_sub{
			int operator()(int a, int b)
			{
				return a - b;
			};
		};

		//関数型ハッシュテーブルテスト用関数：ラムダ関数
		auto func_mul = [](int a, int b) -> int
		{
			return a * b;
		};
		auto func_div = [](int a, int b) -> int
		{
			return a / b;
		};
		//※ std::function<>はクラスメンバー関数も扱えるが省略

		//登録
		func_con.emplace("+", func_add);
		func_con.emplace("-", func_sub());
		func_con.emplace("*", func_mul);
		func_con.emplace("/", func_div);

		//検索して実行
		printf("50 + 4 = %d\n", (*func_con["+"])(50, 4));
		printf("50 - 4 = %d\n", (*func_con["-"])(50, 4));
		printf("50 * 4 = %d\n", (*func_con["*"])(50, 4));
		printf("50 / 4 = %d\n", (*func_con["/"])(50, 4));
	}

	return EXIT_SUCCESS;
}

//関数型ハッシュテーブルテスト用関数：通常関数
int func_add(int a, int b)
{
	return a + b;
};

// End of file
