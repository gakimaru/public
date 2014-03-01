#define TLS_IS_WINDOWS//【MS固有仕様】TLSの宣言をWindowsスタイルにする時はこのマクロを有効にする
#define USE_FUNCSIG//【MS固有仕様】関数名に__FUNCSIG__を使用する時にこのマクロを有効にする
#define USE_STRCPY_S//【MS固有仕様】strcpy_sを使用する時にこのマクロを有効にする
#define USE_WINDOWS_CONSOLE_COLOR//【MS固有仕様】Windowsスタイルのコンソールカラーを使用
#define USE_WINDOWS_DEBUG_BREAK//【MS固有仕様】WindowのDebugBreakを使用
#define USE_ALIGNED_MALLOC//【MS固有仕様】_aligned_mallocを使用する時はこのマクロを有効にする
#define USE_FRIEND_WITH_NEW_OPERATOR//【MS固有仕様？】operator new()をクラス内でフレンド化する時はこのマクロを有効にする

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>//valist用
#include <assert.h>//assert用
#include <memory.h>//memcpy用
#include <stdint.h>//uintptr_t用
#include <limits.h>//UCHAR_MAX用
#include <bitset>//std::bitset用
#include <iterator>//std::iterator用
#include <algorithm>//std::move用
#include <atomic>//C++11アトミック操作
#include <vector>//vector
#include <unordered_map>//C++11ハッシュテーブル
#include <chrono>//C++11時間
#include <thread>//C++11スレッド
#include <random>//C++11乱数

#ifdef USE_ALIGNED_MALLOC
#include <malloc.h>//malloc,_aligned_malloc用
#else//USE_ALIGNED_MALLOC
#include <stdlib.h>//memalign用
#endif//USE_ALIGNED_MALLOC

//--------------------------------------------------------------------------------
//基本マクロ

//ブレークポイント
#ifdef USE_WINDOWS_DEBUG_BREAK
#include <windows.h>//ブレークポイント用
#define BREAK_POINT() DebugBreak()
#else//USE_WINDOWS_DEBUG_BREAK
#define BREAK_POINT()
#endif//USE_WINDOWS_DEBUG_BREAK

//デバッグプリント
#define DEBUG_PRINT(msg, ...) printf(msg, ##__VA_ARGS__)
#define DEBUG_FPRINT(fp, msg, ...) fprintf(fp, msg, ##__VA_ARGS__)
#define DEBUG_FLUSH() fflush(stdout)
#define DEBUG_FFLUSH(fp) fflush(fp)
//#define DEBUG_PRINT(msg, ...)
//#define DEBUG_FPRINT(fp, msg, ...)
//#define DEBUG_FLUSH()
//#define DEBUG_FFLUSH(fp) fflush(fp)

//文字列化マクロ
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)

//静的アサーション
#define STATIC_ASSERT(expr, msg) \
	static_assert(expr, msg)

//アサーション
#define ASSERT(expr, msg, ...) \
	if (!(expr)) \
	{ \
		DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
		"  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
		"  "  msg "\n", ##__VA_ARGS__); \
		BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//削除用
//#include <assert.h>//assert用
//#define ASSERT(expr, msg, ...) assert(expr)//VC++標準版

//スレッドローカルストレージ修飾子
//※C++11仕様偽装
#ifdef TLS_IS_WINDOWS
#define thread_local __declspec(thread)//Windows仕様
#else//TLS_IS_WINDOWS
#define thread_local __thread//POSIX仕様
#endif//TLS_IS_WINDOWS

//関数名取得マクロ
#ifdef USE_FUNCSIG
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif//USE_FUNCSIG

//ソースファイル名＆関数名取得マクロ
#define GET_CONCATENATED_SOURCE_FILE_NAME() __FILE__ "(" TO_STRING_EX(__LINE__) ")[" __TIMESTAMP__ "]"//ファイル名合成＆取得マクロ
#define GET_FUNC_NAME() __PRETTY_FUNCTION__//関数名取得マクロ

//Windowsスタイルカラー用
#ifdef USE_WINDOWS_CONSOLE_COLOR
#include <windows.h>
#include <conio.h> 
#endif//USE_WINDOWS_CONSOLE_COLOR

//--------------------
//共通関数
#include <string.h>
//ファイル名取得関数（ディレクトリ部を除いた文字列を返す）
const char* getFileName(const char* str)
{
	if (!str)
		return nullptr;
	std::size_t len = strlen(str);
	const char* p = str + len;
	for (; len > 0; --len, --p)
	{
		const char c = *(p - 1);
		if (c == '\\' || c == '/')
			return p;
	}
	return str;
}

//----------------------------------------
//スレッドIDクラス
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

#if 0
//--------------------------------------------------------------------------------
//リード・ライトロッククラス
//※容量節約のために、POSIXスレッドライブラリ版のように、現在のスレッドのロック状態を保持しない
//※必ずロッククラス CRWLock::LockR, CRWLock::LockR_AsNecessary, CRWLock::LockW を使用し、
//　そこに現在のロック状態を保持する

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
#endif

//--------------------------------------------------------------------------------
//スタックアロケータ

//--------------------
//スタックアロケータインターフェースクラス
class IStackAllocator
{
public:
	//定数
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//デフォルトのアラインメント
	//スタック順
	enum E_ORDERED
	{
		DEFAULT = 0,//デフォルト
		NORMAL = 1,//正順
		REVERSE = -1,//逆順
	};
public:
	//型
	typedef unsigned char byte;//バッファ用
	typedef uintptr_t marker_t;//スタックマーカー型
public:
	//アクセッサ
	virtual std::size_t getTotal() const = 0;//全体のメモリ量を取得
	virtual std::size_t getUsed() const = 0;//使用中のメモリ量を取得
	virtual std::size_t getRemain() const = 0;//残りのメモリ量を取得
	virtual const byte* getNowPtr() const = 0;//現在のバッファ位置を取得
	virtual marker_t getMarker() const = 0;//現在のマーカーを取得
public:
	//メソッド
	//メモリ確保
	virtual void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) = 0;
	//メモリを以前のマーカーに戻す
	//※マーカー指定版
	virtual void back(const marker_t marker) = 0;
	//メモリを以前のマーカーに戻す
	//※ポインタ指定版
	virtual void back(const void* p) = 0;
	//メモリ破棄（正順）
	virtual void clear() = 0;
	//メモリ破棄（全て）
	virtual void clearAll() = 0;
public:
	//デストラクタ
	virtual ~IStackAllocator(){}
};
//定数のエイリアス
static const IStackAllocator::E_ORDERED DSA_DEFAULT = IStackAllocator::DEFAULT;//デフォルト
static const IStackAllocator::E_ORDERED DSA_NORMAL = IStackAllocator::NORMAL;//正順
static const IStackAllocator::E_ORDERED DSA_REVERSE = IStackAllocator::REVERSE;//逆順

//--------------------
//スタックアロケータクラス
//※非スレッドセーフ（処理速度優先）
//※インターフェースを実装するが、高速化のために virtualメソッドに頼らず操作可能
class CStackAllocator : public IStackAllocator
{
public:
	//アクセッサ
	std::size_t getTotal() const override { return m_buffSize; }//全体のメモリ量を取得
	std::size_t getUsed() const override { return m_used; }//使用中のメモリ量を取得
	std::size_t getRemain() const override { return m_buffSize - m_used; }//残りのメモリ量を取得
	const byte* getBuff() const { return m_buffPtr; }//バッファ取得を取得
	const byte* getNowPtrN() const { return m_buffPtr + m_used; }//現在のバッファ位置（正順）を取得
	const byte* getNowPtr() const override { return getNowPtrN(); }//現在のバッファ位置を取得
	marker_t getMarkerN() const { return m_used; }//現在のマーカー（正順）を取得
	marker_t getMarker() const override { return getMarkerN(); }//現在のマーカーを取得
public:
	//メソッド
	//メモリ確保（正順）
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_used;//現在のポインタ位置算出
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//アラインメント計算
		const marker_t next_used = m_used + align_diff + size;//次のマーカー算出
		if (next_used > m_buffSize)//メモリオーバーチェック（符号なしなので、範囲チェックは大判定のみでOK）
		{
			printf("stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_buffSize - m_used);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//メモリ確保アドレス算出
		m_used = next_used;//マーカー更新
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocN(size, align);
	}
	//メモリを以前のマーカーに戻す（正順）
	//※マーカー指定版
	void backN(const marker_t marker)
	{
		if (marker >= m_used)//符号なしなので、範囲チェックは大判定のみでOK
			return;
		m_used = marker;
	}
	//メモリを以前のマーカーに戻す
	//※マーカー指定版
	void back(const marker_t marker) override
	{
		return backN(marker);
	}
	//メモリを以前のマーカーに戻す（正順）
	//※ポインタ指定版
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		back(marker);
	}
	//メモリを以前のマーカーに戻す
	//※ポインタ指定版
	void back(const void* p) override
	{
		backN(p);
	}
	//メモリ破棄（正順）
	void clearN()
	{
		m_used = 0;//マーカーをリセット
	}
	//メモリ破棄（正順）
	void clear() override
	{
		clearN();
	}
	//メモリ破棄（全て）
	void clearAll() override
	{
		clearN();
	}
public:
	//コンストラクタ
	CStackAllocator(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//バッファ先頭アドレス
		m_buffSize(buff_size),//バッファサイズ
		m_used(0)//マーカー
	{}
	//デストラクタ
	~CStackAllocator() override
	{}
private:
	//フィールド
	byte* m_buffPtr;//バッファ先頭アドレス
	const std::size_t m_buffSize;//バッファサイズ
	marker_t m_used;//マーカー（正順）
};

//--------------------
//バッファ付きスタックアロケータテンプレートクラス
//※静的バッファを使用したければ、固定バッファシングルトン化する
template<std::size_t SIZE>
class CStackAllocatorWithBuff : public CStackAllocator
{
public:
	//定数
	static const std::size_t BUFF_SIZE = SIZE;//バッファサイズ
public:
	//コンストラクタ
	CStackAllocatorWithBuff() :
		CStackAllocator(m_buff, BUFF_SIZE)
	{}
	//デストラクタ
	~CStackAllocatorWithBuff() override
	{}
private:
	//フィールド
	byte m_buff[BUFF_SIZE];//バッファ
};

#if 0
//--------------------
//双方向スタックアロケータクラス
//※非スレッドセーフ（処理速度優先）
//※インターフェースを実装するが、高速化のために virtualメソッドに頼らず操作可能
class CDualStackAllocator : public IStackAllocator
{
public:
	//アクセッサ
	std::size_t getTotal() const override { return m_buffSize; }//全体のメモリ量を取得
	std::size_t getUsed() const override { return m_usedN + m_buffSize - m_usedR; }//使用中のメモリ量を取得
	std::size_t getRemain() const override { return m_usedR - m_usedN; }//残りのメモリ量を取得
	E_ORDERED getDefaultOrdered() const { return m_defaultOrdered; }//デフォルトのスタック順を取得
	void setDefaultOrdered(const E_ORDERED ordered)//デフォルトのスタック順を更新
	{
		m_defaultOrdered = ordered == REVERSE ? REVERSE : NORMAL;
	}
	const byte* getBuff() const { return m_buffPtr; }//バッファ取得を取得
	const byte* getNowPtrN() const { return m_buffPtr + m_usedN; }//現在のバッファ位置（正順）を取得
	const byte* getNowPtrR() const { return m_buffPtr + m_usedR; }//現在のバッファ位置（逆順）を取得
	const byte* getNowPtrD() const { return getNowPtr(m_defaultOrdered); }//現在のバッファ位置を取得
	const byte* getNowPtr(const E_ORDERED ordered) const { return ordered == DEFAULT ? getNowPtrD() : ordered == REVERSE ? getNowPtrR() : getNowPtrN(); }//現在のバッファ位置を取得
	const byte* getNowPtr() const override { return getNowPtrD(); }//現在のバッファ位置を取得
	marker_t getMarkerN() const { return m_usedN; }//現在のマーカー（正順）を取得
	marker_t getMarkerR() const { return m_usedR; }//現在のマーカー（逆順）を取得
	marker_t getMarkerD() const { return getMarker(m_defaultOrdered); }//現在のマーカーを取得
	marker_t getMarker(const E_ORDERED ordered) const { return ordered == DEFAULT ? getMarkerD() : ordered == REVERSE ? getMarkerR() : getMarkerN(); }//現在のマーカーを取得
	marker_t getMarker() const override { return getMarkerD(); }//現在のマーカーを取得
public:
	//メソッド
	//メモリ確保（正順）
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedN;//現在のポインタ位置算出
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//アラインメント計算
		const marker_t next_used = m_usedN + align_diff + size;//次のマーカー算出
		if (next_used > m_usedR)//メモリオーバーチェック（符号なしなので、範囲チェックは大判定のみでOK）
		{
			printf("normal-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR - m_usedN);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//メモリ確保アドレス算出
		m_usedN = next_used;//マーカー更新
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//メモリ確保（逆順）
	void* allocR(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedR;//現在のポインタ位置算出
		const uintptr_t alloc_ptr_tmp = now_ptr - size;//メモリ確保アドレス算出（暫定）
		const uintptr_t align_diff = align > 0 ? alloc_ptr_tmp % align == 0 ? 0 : alloc_ptr_tmp % align : 0;//アラインメント計算
		const marker_t next_used = m_usedR - size - align_diff;//次のマーカー算出
		if (next_used < m_usedN || next_used > m_buffSize)//メモリオーバーチェック（オーバーフローして値が大きくなる可能性もチェック）
		{
			printf("reversed-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR - m_usedN);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr - size - align_diff;//メモリ確保アドレス算出
		m_usedR = next_used;//マーカー更新
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//メモリ確保
	void* allocD(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return alloc(m_defaultOrdered, size, align);
	}
	//メモリ確保
	void* alloc(const E_ORDERED ordered, const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return ordered == DEFAULT ? allocD(size, align) : ordered == REVERSE ? allocR(size, align) : allocN(size, align);
	}
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocD(size, align);
	}
	//メモリを以前のマーカーに戻す（正順）
	//※マーカー指定版
	void backN(const marker_t marker_n)
	{
		if (marker_n > m_usedR)//符号なしなので、範囲チェックは大判定のみでOK
			return;
		m_usedN = marker_n;
	}
	//メモリを以前のマーカーに戻す（正順）
	//※ポインタ指定版
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//メモリを以前のマーカーに戻す（逆順）
	//※マーカー指定版
	void backR(const marker_t marker_r)
	{
		if (marker_r < m_usedN || marker_r > m_buffSize)//メモリオーバーチェック
			return;
		m_usedR = marker_r;
	}
	//メモリを以前のマーカーに戻す（逆順）
	//※ポインタ指定版
	void backR(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backR(marker);
	}
	//メモリを以前のマーカーに戻す
	//※マーカー指定版
	void backD(const marker_t marker)
	{
		back(m_defaultOrdered, marker);
	}
	//メモリを以前のマーカーに戻す
	//※ポインタ指定版
	void backD(const void* p)
	{
		back(m_defaultOrdered, p);
	}
	//メモリを以前のマーカーに戻す
	//※マーカー指定版
	void back(const E_ORDERED ordered, const marker_t marker)
	{
		ordered == DEFAULT ? backD(marker) : ordered == REVERSE ? backR(marker) : backN(marker);
	}
	//メモリを以前のマーカーに戻す
	//※ポインタ指定版
	void back(const E_ORDERED ordered, const void* p)
	{
		ordered == DEFAULT ? backD(p) : ordered == REVERSE ? backR(p) : backN(p);
	}
	//メモリを以前のマーカーに戻す
	//※マーカー指定版
	void back(const marker_t marker) override
	{
		backD(marker);
	}
	//メモリを以前のマーカーに戻す
	//※ポインタ指定版
	void back(const void* p) override
	{
		backD(p);
	}
	//メモリ破棄（正順）
	void clearN()
	{
		m_usedN = 0;
	}
	//メモリ破棄（逆順）
	void clearR()
	{
		m_usedR = m_buffSize;
	}
	//メモリ破棄
	void clearD()
	{
		clear(m_defaultOrdered);
	}
	//メモリ破棄（両方）
	void clearNR()
	{
		clearN();
		clearR();
	}
	//メモリ破棄
	void clear(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? clearD() : ordered == REVERSE ? clearR() : clearN();
	}
	//メモリ破棄
	void clear() override
	{
		clearD();
	}
	//メモリ破棄（全て）
	void clearAll() override
	{
		clearNR();
	}
public:
	//コンストラクタ
	CDualStackAllocator(void* buff_p, const std::size_t buff_size, const E_ORDERED default_ordered = NORMAL) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//バッファ先頭アドレス
		m_buffSize(buff_size),//バッファサイズ
		m_usedN(0),//マーカー（正順）
		m_usedR(buff_size)//マーカー（逆順）
	{
		setDefaultOrdered(default_ordered);//デフォルトのスタック順を補正
	}
	//デストラクタ
	~CDualStackAllocator() override
	{}
private:
	//フィールド
	byte* m_buffPtr;//バッファ先頭アドレス
	const std::size_t m_buffSize;//バッファサイズ
	marker_t m_usedN;//マーカー（正順）
	marker_t m_usedR;//マーカー（逆順）
	E_ORDERED m_defaultOrdered;//デフォルトのスタック順
};

//--------------------
//バッファ付き双方向スタックアロケータテンプレートクラス
//※静的バッファを使用したければ、固定バッファシングルトン化する
template<std::size_t SIZE>
class CDualStackAllocatorWithBuff : public CDualStackAllocator
{
public:
	//定数
	static const std::size_t BUFF_SIZE = SIZE;//バッファサイズ
public:
	//コンストラクタ
	CDualStackAllocatorWithBuff(const E_ORDERED default_ordered = NORMAL) :
		CDualStackAllocator(m_buff, BUFF_SIZE, default_ordered)
	{}
	//デストラクタ
	~CDualStackAllocatorWithBuff() override
	{}
private:
	//フィールド
	byte m_buff[BUFF_SIZE];//バッファ
};
#endif

#if 0
//--------------------
//スマートスタックアロケータクラス
//※非スレッドセーフ（処理速度優先）
//※インターフェースを実装するが、高速化のために virtualメソッドに頼らず操作可能
class CSmartStackAllocator : public IStackAllocator
{
public:
	//型
	typedef int counter_t;//カウンタ型
public:
	//アクセッサ
	std::size_t getTotal() const override { return m_buffSize; }//全体のメモリ量を取得
	std::size_t getUsed() const override { return m_usedN.load() + m_buffSize - m_usedR.load(); }//使用中のメモリ量を取得
	std::size_t getRemain() const override { return m_usedR.load() - m_usedN.load(); }//残りのメモリ量を取得
	E_ORDERED getDefaultOrdered() const { return m_defaultOrdered.load(); }//デフォルトのスタック順を取得
	void setDefaultOrdered(const E_ORDERED ordered)//デフォルトのスタック順を更新
	{
		//m_lock.lock();//ロック取得（不要⇒代わりにアトミック型を使用）
		m_defaultOrdered.store(ordered == REVERSE ? REVERSE : NORMAL);
		//m_lock.unlock();//ロック解放（不要）
	}
	const byte* getBuff() const { return m_buffPtr; }//バッファ取得を取得
	const byte* getNowPtrN() const { return m_buffPtr + m_usedN.load(); }//現在のバッファ位置（正順）を取得
	const byte* getNowPtrR() const { return m_buffPtr + m_usedR.load(); }//現在のバッファ位置（逆順）を取得
	const byte* getNowPtrD() const { return getNowPtr(m_defaultOrdered.load()); }//現在のバッファ位置を取得
	const byte* getNowPtr(const E_ORDERED ordered) const { return ordered == DEFAULT ? getNowPtrD() : ordered == REVERSE ? getNowPtrR() : getNowPtrN(); }//現在のバッファ位置を取得
	const byte* getNowPtr() const override { return getNowPtrD(); }//現在のバッファ位置を取得
	marker_t getMarkerN() const { return m_usedN.load(); }//現在のマーカー（正順）を取得
	marker_t getMarkerR() const { return m_usedR.load(); }//現在のマーカー（逆順）を取得
	marker_t getMarkerD() const { return getMarker(m_defaultOrdered.load()); }//現在のマーカーを取得
	marker_t getMarker(const E_ORDERED ordered) const { return ordered == DEFAULT ? getMarkerD() : ordered == REVERSE ? getMarkerR() : getMarkerN(); }//現在のマーカーを取得
	marker_t getMarker() const override { return getMarkerD(); }//現在のマーカーを取得
	marker_t getBeginN() const { return m_beginN.load(); }//開始マーカー（正順）を取得
	marker_t getBeginR() const { return m_beginR.load(); }//開始マーカー（逆順）を取得
	marker_t getBeginD() const { return getBegin(m_defaultOrdered.load()); }//開始マーカーを取得
	marker_t getBegin(const E_ORDERED ordered) const { return ordered == DEFAULT ? getBeginD() : ordered == REVERSE ? getBeginR() : getBeginN(); }//開始マーカーを取得
	marker_t getBegin() const { return getBeginD(); }//開始マーカーを取得
	marker_t getCounterN() const { return m_counterN.load(); }//メモリ確保カウンタ（正順）を取得
	marker_t getCounterR() const { return m_counterR.load(); }//メモリ確保カウンタ（逆順）を取得
	marker_t getCounterD() const { return getCounter(m_defaultOrdered.load()); }//メモリ確保カウンタを取得
	marker_t getCounter(const E_ORDERED ordered) const { return ordered == DEFAULT ? getCounterD() : ordered == REVERSE ? getCounterR() : getCounterN(); }//メモリ確保カウンタを取得
	marker_t getCounter() const { return getCounterD(); }//メモリ確保カウンタを取得
public:
	//メソッド
	//メモリ確保（正順）
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		//高速化のために、一度ロックの範囲外で単純空き領域判定
		if (m_usedN.load() + size > m_usedR.load())
			return nullptr;
		m_lock.lock();//ロック取得
		m_counterN.fetch_add(1);
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedN.load();//現在のポインタ位置算出
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//アラインメント計算
		const marker_t next_used = m_usedN.load() + align_diff + size;//次のマーカー算出
		if (next_used > m_usedR.load())//メモリオーバーチェック（符号なしなので、範囲チェックは大判定のみでOK）
		{
			printf("normal-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR.load() - m_usedN.load());
			m_lock.unlock();//ロック解放
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//メモリ確保アドレス算出
		m_usedN.store(next_used);//マーカー更新
		m_lock.unlock();//ロック解放
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//メモリ確保（逆順）
	void* allocR(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		//高速化のために、一度ロックの範囲外で単純空き領域判定
		if (m_usedN.load() > m_usedR.load() - size)
			return nullptr;
		m_lock.lock();//ロック取得
		m_counterR.fetch_add(1);
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedR.load();//現在のポインタ位置算出
		const uintptr_t alloc_ptr_tmp = now_ptr - size;//メモリ確保アドレス算出（暫定）
		const uintptr_t align_diff = align > 0 ? alloc_ptr_tmp % align == 0 ? 0 : alloc_ptr_tmp % align : 0;//アラインメント計算
		const marker_t next_used = m_usedR.load() - size - align_diff;//次のマーカー算出
		if (next_used < m_usedN.load() || next_used > m_buffSize)//メモリオーバーチェック（オーバーフローして値が大きくなる可能性もチェック）
		{
			printf("reversed-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR.load() - m_usedN.load());
			m_lock.unlock();//ロック解放
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr - size - align_diff;//メモリ確保アドレス算出
		m_usedR.store(next_used);//マーカー更新
		m_lock.unlock();//ロック解放
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//メモリ確保
	void* allocD(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return alloc(m_defaultOrdered.load(), size, align);
	}
	//メモリ確保
	void* alloc(const E_ORDERED ordered, const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return ordered == DEFAULT ? allocD(size, align) : ordered == REVERSE ? allocR(size, align) : allocN(size, align);
	}
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocD(size, align);
	}
private:
	//メモリ破棄（正順）
	void freeN(void* p)
	{
		//ポインタの範囲チェック
		//※高速化のために、一度ロックの範囲外でチェック
		//　（常にfreeN関数とfreeDが一組で呼び出されるため）
		if (m_counterN.load() <= 0)
			return;
		const marker_t now_n = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		if (now_n < m_beginN.load() || now_n > m_usedN.load())
			return;
		//ポインタが正順スタックとして適正のため、処理開始
		m_lock.lock();//ロック取得
		if (m_counterN.load() <= 0 || now_n < m_beginN.load() || now_n > m_usedN.load())//範囲の再チェック
		{
			m_lock.unlock();//ロック解放
			return;
		}
		m_counterN.fetch_sub(1);
		if (m_counterN.load() == 0)
			m_usedN.store(m_beginN.load());
		m_lock.unlock();//ロック解放
	}
	//メモリ破棄（逆順）
	void freeR(void* p)
	{
		//ポインタの範囲チェック
		//※高速化のために、一度ロックの範囲外でチェック
		//　（常にfreeN関数とfreeDが一組で呼び出されるため）
		if (m_counterR.load() <= 0)
			return;
		const marker_t now_r = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		if (now_r >= m_beginR.load() || now_r < m_usedR.load())
			return;
		//ポインタが逆順スタックとして適正のため、処理開始
		m_lock.lock();//ロック取得
		if (m_counterR.load() <= 0 || now_r >= m_beginR.load() || now_r < m_usedR.load())//範囲の再チェック
		{
			m_lock.unlock();//ロック解放
			return;
		}
		m_counterR.fetch_sub(1);
		if (m_counterR.load() == 0)
			m_usedR.store(m_beginR.load());
		m_lock.unlock();//ロック解放
	}
public:
	//メモリ破棄
	void free(void* p)
	{
		//ポインタをチェックして処理するので正順と逆順の両方の処理をまとめて実行する
		freeN(p);//正順
		freeR(p);//逆順
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始（正順）
	//※メモリ確保カウンタをリセット
	void beginN()
	{
		m_lock.lock();//ロック取得
		m_beginN.store(m_usedN.load());
		m_counterN.store(0);
		m_lock.unlock();//ロック解放
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始（逆順）
	//※メモリ確保カウンタをリセット
	void beginR()
	{
		m_lock.lock();//ロック取得
		m_beginR.store(m_usedR.load());
		m_counterR.store(0);
		m_lock.unlock();//ロック解放
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始 
	//※メモリ確保カウンタをリセット
	void beginD()
	{
		begin(m_defaultOrdered.load());
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始 
	//※メモリ確保カウンタをリセット
	void begin(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? beginD() : ordered == REVERSE ? beginR() : beginN();
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始 
	//※メモリ確保カウンタをリセット
	void begin()
	{
		beginD();
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す（正順）
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※マーカー指定版
	void backN(const marker_t marker_n)
	{
		m_lock.lock();//ロック取得
		if (marker_n > m_usedR.load())//符号なしなので、範囲チェックは大判定のみでOK
		{
			m_lock.unlock();//ロック解放
			return;
		}
		m_usedN.store(marker_n);
		m_beginN.store(marker_n);
		m_counterN.store(0);
		m_lock.unlock();//ロック解放
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す（正順）
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※ポインタ指定版
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す（逆順）
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※マーカー指定版
	void backR(const marker_t marker_r)
	{
		m_lock.lock();//ロック取得
		if (marker_r < m_usedN.load() || marker_r > m_buffSize)//メモリオーバーチェック
		{
			return;
			m_lock.unlock();//ロック解放
		}
		m_usedR.store(marker_r);
		m_beginR.store(marker_r);
		m_counterR.store(0);
		m_lock.unlock();//ロック解放
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す（逆順）
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※ポインタ指定版
	void backR(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backR(marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※マーカー指定版
	void backD(const marker_t marker)
	{
		back(m_defaultOrdered.load(), marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※ポインタ指定版
	void backD(const void* p)
	{
		back(m_defaultOrdered.load(), p);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※マーカー指定版
	void back(const E_ORDERED ordered, const marker_t marker)
	{
		ordered == DEFAULT ? backD(marker) : ordered == REVERSE ? backR(marker) : backN(marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※ポインタ指定版
	void back(const E_ORDERED ordered, const void* p)
	{
		ordered == DEFAULT ? backD(p) : ordered == REVERSE ? backR(p) : backN(p);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※マーカー指定版
	void back(const marker_t marker) override
	{
		backD(marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンタもリセットする
	//※ポインタ指定版
	void back(const void* p) override
	{
		backD(p);
	}
	//メモリ破棄（正順）
	//※開始マーカーとメモリ確保カウンタもリセットする
	void clearN()
	{
		m_lock.lock();//ロック取得
		m_usedN.store(0);
		m_beginN.store(0);
		m_counterN.store(0);
		m_lock.unlock();//ロック解放
	}
	//メモリ破棄（逆順）
	//※開始マーカーとメモリ確保カウンタもリセットする
	void clearR()
	{
		m_lock.lock();//ロック取得
		m_usedR.store(m_buffSize);
		m_beginR.store(0);
		m_counterR.store(0);
		m_lock.unlock();//ロック解放
	}
	//メモリ破棄
	//※開始マーカーとメモリ確保カウンタもリセットする
	void clearD()
	{
		clear(m_defaultOrdered.load());
	}
	//メモリ破棄（両方）
	//※開始マーカーとメモリ確保カウンタもリセットする
	void clearNR()
	{
		clearN();
		clearR();
	}
	//メモリ破棄
	//※開始マーカーとメモリ確保カウンタもリセットする
	void clear(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? clearD() : ordered == REVERSE ? clearR() : clearN();
	}
	//メモリ破棄
	//※開始マーカーとメモリ確保カウンタもリセットする
	void clear() override
	{
		clearD();
	}
	//メモリ破棄（全て）
	//※開始マーカーとメモリ確保カウンタもリセットする
	void clearAll() override
	{
		clearNR();
	}
public:
	//コンストラクタ
	CSmartStackAllocator(void* buff_p, const std::size_t buff_size, const E_ORDERED default_ordered = NORMAL) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//バッファ先頭アドレス
		m_buffSize(buff_size)//バッファサイズ
	{
		m_usedN.store(0);//マーカー（正順）
		m_usedR.store(buff_size);//マーカー（逆順）
		m_beginN.store(0);//開始マーカー（正順）※カウントを開始した位置（自動開放でこの位置に戻す）
		m_beginR.store(buff_size);//開始マーカー（逆順）※カウントを開始した位置（自動開放でこの位置に戻す）
		m_counterN.store(0);//メモリ確保カウンタ（正順）
		m_counterR.store(0);//メモリ確保カウンタ（逆順）
		setDefaultOrdered(default_ordered);//デフォルトのスタック順
	}
	//デストラクタ
	~CSmartStackAllocator() override
	{}
private:
	//フィールド
	byte* m_buffPtr;//バッファ先頭アドレス
	const std::size_t m_buffSize;//バッファサイズ
	std::atomic<marker_t> m_usedN;//マーカー（正順）
	std::atomic<marker_t> m_usedR;//マーカー（逆順）
	std::atomic<marker_t> m_beginN;//開始マーカー（正順）※カウントを開始した位置（自動開放でこの位置に戻す）
	std::atomic<marker_t> m_beginR;//開始マーカー（逆順）※カウントを開始した位置（自動開放でこの位置に戻す）
	std::atomic<counter_t> m_counterN;//メモリ確保カウンタ（正順）
	std::atomic<counter_t> m_counterR;//メモリ確保カウンタ（逆順）
	std::atomic<E_ORDERED> m_defaultOrdered;//デフォルトのスタック順
	CSpinLock m_lock;//ロック
};

//--------------------
//バッファ付きスマートスタックアロケータテンプレートクラス
//※静的バッファを使用したければ、固定バッファシングルトン化する
template<std::size_t SIZE>
class CSmartStackAllocatorWithBuff : public CSmartStackAllocator
{
public:
	//定数
	static const std::size_t BUFF_SIZE = SIZE;//バッファサイズ
public:
	//コンストラクタ
	CSmartStackAllocatorWithBuff(const E_ORDERED default_ordered = NORMAL) :
		CSmartStackAllocator(m_buff, BUFF_SIZE, default_ordered)
	{}
	//デストラクタ
	~CSmartStackAllocatorWithBuff() override
	{}
private:
	//フィールド
	byte m_buff[BUFF_SIZE];//バッファ
};
#endif

//--------------------------------------------------------------------------------
//プールアロケータクラス

//----------------------------------------
//クラス宣言
class CPoolAllocator;

//----------------------------------------
//プールアロケータクラス
//※スレッドセーフ対応
class CPoolAllocator
{
public:
	//型宣言
	typedef unsigned char byte;//バッファ用
	typedef int index_t;//インデックス用
public:
	//定数
	static const index_t INVALID_INDEX = INT_MAX;//ブロックインデックスの無効値
public:
	//アクセッサ
	const byte* getBuff() const { return m_pool; }//バッファ取得
	std::size_t getBlockSize() const { return m_blockSize; }//ブロックサイズ
	index_t getBlocksNum() const { return m_poolBlocksNum; }//プールブロック数
	index_t getUsed() const { return m_used.load(); }//使用中数取得
	index_t getRemain() const { return m_poolBlocksNum - m_used.load(); }//残数取得
	const byte* getBlockConst(const index_t index) const { return m_pool + index * m_blockSize; }//ブロック取得
private:
	byte* getBlock(const index_t index){ return m_pool + index * m_blockSize; }//ブロック取得
private:
	//メソッド
	//メモリ確保状態リセット
	void reset()
	{
		//ロック取得
		m_lock.lock();

		m_used.store(0);//使用中数
		m_next = 0;//未使用先頭インデックス
		m_recycle = INVALID_INDEX;//リサイクルインデックス

		//ロック解放
		m_lock.unlock();
	}
	//メモリブロック確保
	//※使用中フラグの空きを検索してフラグを更新し、
	//　確保したインデックスを返す
	int assign()
	{
		//使用中ブロック数チェックは、高速化のために、一度ロックの範囲外で行う
		if (m_used.load() >= m_poolBlocksNum)
			return INVALID_INDEX;//空きなし

		//ロック取得
		m_lock.lock();

		//使用中ブロック数を再チェック
		if (m_used.load() >= m_poolBlocksNum)
		{
			m_lock.unlock();//ロック解放
			return INVALID_INDEX;//空きなし
		}

		//インデックス確保
		index_t index = INVALID_INDEX;
		if (m_next < m_poolBlocksNum)
		{
			//未使用インデックスがある場合
			index = m_next++;//未使用先頭インデックスカウントアップ
			m_used.fetch_add(1);//使用中数カウントアップ
		}
		else
		{
			if (m_recycle != INVALID_INDEX)
			{
				//リサイクル可能なインデックスがある場合
				index = m_recycle;//リサイクルインデックス
				m_recycle = *reinterpret_cast<unsigned int*>(getBlock(index));//リサイクルインデックス更新（空きノードの先頭に書き込まれている）
				m_used.fetch_add(1);//使用中数カウントアップ
			}
		}

		//ロック解放
		m_lock.unlock();

		//最初に使用中ブロック数を判定しているので、この時点でインデックスが得られなければプログラムに問題があるはず
		ASSERT(index != INVALID_INDEX, "Probably, mistaken logic in this program.");

		//終了
		return index;
	}
	//メモリブロック解放
	//※指定のインデックスの使用中フラグをリセット
	void release(const index_t index)
	{
		//インデックスの範囲チェック（ロックの範囲外で行う）
		if (index < 0 || index >= m_poolBlocksNum)
			return;

		//ロック取得
		m_lock.lock();

		//リサイクル
		*reinterpret_cast<unsigned int*>(getBlock(index)) = m_recycle;//リサイクルインデックス書き込み（空きノードの先頭に強引に書き込む）
		m_recycle = index;//リサイクルインデックス組み換え

		//使用中数カウントダウン
		m_used.fetch_sub(1);

		//ロック解放
		m_lock.unlock();
	}
public:
	//メモリ確保
	void* alloc(const std::size_t size)
	{
		//【アサーション】要求サイズがブロックサイズを超える場合は即時確保失敗
		ASSERT(size <= m_blockSize, "CPoolAllocator::alloc(%d) cannot allocate. Size must has been under %d.", size, m_blockSize);
		if (size > m_blockSize)
		{
			return nullptr;
		}
		//空きブロックを確保して返す
		const index_t index = assign();
		//【アサーション】全ブロック使用中につき、確保失敗
		ASSERT(index >= 0, "CPoolAllocator::alloc(%d) cannot allocate. Buffer is full. (num of blocks is %d)", size, m_poolBlocksNum);
		//確保したメモリを返す
		return index == INVALID_INDEX ? nullptr : getBlock(index);
	}
	//メモリ解放
	void free(void * p)
	{
		//nullptr時は即時解放失敗
		ASSERT(p != nullptr, "CPoolAllocator::free() cannot free. Pointer is null.");
		if (!p)
			return;
		//ポインタからインデックスを算出
		const intptr_t diff = reinterpret_cast<intptr_t>(p)-reinterpret_cast<intptr_t>(m_pool);//ポインタの差分
		const index_t index = diff / m_blockSize;//ブロックサイズで割ってインデックス算出
		//【アサーション】メモリバッファの範囲外なら処理失敗（release関数内で失敗するのでそのまま実行）
		ASSERT(index >= 0 && index < m_poolBlocksNum, "CPoolAllocator::free() cannot free. Pointer is different.");
		//【アサーション】ポインタが各ブロックの先頭を指しているかチェック
		//　　　　　　　　⇒多重継承とキャストしているとずれることがるのでこの問題は無視して解放してしまう
		//ASSERT(diff % m_blockSize == 0, "CPoolAllocator::free() cannot free. Pointer is illegal.");
		//算出したインデックスでメモリ解放
		release(index);
	}
	//コンストラクタ呼び出し機能付きメモリ確保
	//※C++11の可変長テンプレートパラメータを活用
	template<class T, typename... Tx>
	T* create(Tx... nx)
	{
		return new(*this) T(nx...);
	}
	//デストラクタ呼び出し機能付きメモリ解放
	//※解放後、ポインタに nullptr をセットする
	template<class T>
	void destroy(T*& p)
	{
		if (!p)
			return;
		p->~T();//明示的なデストラクタ呼び出し（デストラクタ未定義のクラスでも問題なし）
		operator delete(p, *this);//配置delete呼び出し
		p = nullptr;//ポインタにはnullptrをセット
	}
public:
	//コンストラクタ
	CPoolAllocator(void* pool_buff, const std::size_t block_size, const index_t pool_blocks_num) :
		m_pool(reinterpret_cast<byte*>(pool_buff)),//プールバッファ
		m_blockSize(block_size),//ブロックサイズ　※4倍数であること
		m_poolBlocksNum(pool_blocks_num)//プールブロック数
	{
		//【アサーション】パラメータチェック
		ASSERT((m_blockSize & 0x3) == 0, "CPoolAllocator::CPoolAllocator() block size is invalid.");

		//使用中フラグリセット
		reset();
	}
	//デストラクタ
	~CPoolAllocator()
	{}
private:
	//フィールド
	byte* m_pool;//プールバッファ
	const std::size_t m_blockSize;//ブロックサイズ
	const index_t m_poolBlocksNum;//プールブロック数
	std::atomic<index_t> m_used;//使用中数
	index_t m_next;//未使用先頭インデックス
	index_t m_recycle;//リサイクルインデックス
	CSpinLock m_lock;//ロック
};

//----------------------------------------
//バッファ付きプールアロケータクラス：ブロックサイズとブロック数指定
template<std::size_t S, int N>
class CPoolAllocatorWithBuff : public CPoolAllocator
{
public:
	//定数
	static const std::size_t BLOCK_SIZE = (S + 3) & ~3;//ブロックサイズ
	static const index_t POOL_BLOCKS_NUM = N;//プールブロック数
public:
	//コンストラクタ
	CPoolAllocatorWithBuff() :
		CPoolAllocator(&m_poolBuff, BLOCK_SIZE, POOL_BLOCKS_NUM)
	{}
	//デストラクタ
	~CPoolAllocatorWithBuff()
	{}
private:
	//フィールド
	byte m_poolBuff[POOL_BLOCKS_NUM][BLOCK_SIZE];//プールバッファ
};

#if 0
//----------------------------------------
//バッファ付きプールアロケータクラス：データ型とブロック数指定
template<typename T, int N>
class CPoolAllocatorWithType : public CPoolAllocatorWithBuff<sizeof(T), N>
{
public:
	//型
	typedef T data_t;//データ型
public:
	//定数
	static const std::size_t TYPE_SIZE = sizeof(data_t);//型のサイズ
public:
	//コンストラクタ呼び出し機能付きメモリ確保
	//※C++11の可変長テンプレートパラメータを活用
	template<typename... Tx>
	data_t* createData(Tx... nx)
	{
		return CPoolAllocator::create<data_t>(nx...);
	}
	//デストラクタ呼び出し機能付きメモリ解放
	//※解放後、ポインタに nullptr をセットする
	void destroyData(data_t*& p)
	{
		CPoolAllocator::destroy(p);
	}
public:
	//コンストラクタ
	CPoolAllocatorWithType() :
		CPoolAllocatorWithBuff<TYPE_SIZE, N>()
	{}
	//デストラクタ
	~CPoolAllocatorWithType()
	{}
};
#endif

//--------------------------------------------------------------------------------
//共通アロケータインターフェース

//--------------------
//メモリ確保情報
//※デバッグ情報（参照のみ）
struct ALLOC_INFO;

//--------------------
//共通アロケータインターフェースクラス
class IAllocator
{
public:
	//定数
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//デフォルトのアラインメント
public:
	//メソッド
	virtual const char* getName() const = 0;//アロケータ名取得
	virtual std::size_t getTotal() const = 0;//全体メモリ量　※参考情報（正しい値とは限らない）
	virtual std::size_t getUsed() const = 0;//使用中メモリ量　※参考情報（正しい値とは限らない）
	virtual std::size_t getRemain() const = 0;//残りメモリ量　※参考情報（正しい値とは限らない）
	//メモリ確保
	virtual void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) = 0;
	//メモリ解放
	virtual void free(void* p) = 0;
public:
	//デストラクタ
	virtual ~IAllocator(){}
};

//--------------------
//標準アロケータアダプタークラス
//※内部でmalloc, freeを使用
class CStdAllocAdp : public IAllocator
{
public:
	//型
	typedef CStdAllocAdp ALLOCATOR_TYPE;//アロケータ型（便宜上自身を定義）
	typedef unsigned char byte;//バッファ用
public:
	//アクセッサ
	const char* getName() const override { return "CStdAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override { return 0; }//全体メモリ量取得　※集計不可
	std::size_t getUsed() const override { return 0; }//使用中メモリ量取得　※集計不可
	std::size_t getRemain() const override { return 0; }//残りメモリ量取得　※集計不可
public:
	//オペレータ
	//※main関数より前に何かしらのメモリ確保処理が実行された場合、
	//　CPolyAllocatorが明示的にこのクラスを初期化する必要があるため、
	//　new / delete 演算子とインスタンス用の静的バッファを実装する
	static void* operator new(const std::size_t) throw(){ return m_buff; }//new演算子
	static void operator delete(void*) throw() {}//delete演算子
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		//return malloc(size);//通常malloc()
	#ifdef USE_ALIGNED_MALLOC
		return _aligned_malloc(size, align);//MS仕様：アラインメント指定版malloc
	#else//USE_ALIGNED_MALLOC
		return memalign(align, size);//GCC用：アラインメント指定版malloc
	#endif//USE_ALIGNED_MALLOC
	}
	//メモリ解放
	void free(void* p) override
	{
		if (!p)
			return;
	#ifdef USE_ALIGNED_MALLOC
		_aligned_free(p);//MS仕様：アラインメント指定版free
	#else//USE_ALIGNED_MALLOC
		::free(p);//通常free() ※memalignで確保したメモリもfreeで解放
	#endif//USE_ALIGNED_MALLOC
	}
public:
	//デフォルトコンストラクタ
	CStdAllocAdp()
	{}
	//デストラクタ
	~CStdAllocAdp() override
	{}
private:
	//フィールド
	static byte m_buff[];
};
//標準アロケータアダプタークラスの静的変数インスタンス化
CStdAllocAdp::byte CStdAllocAdp::m_buff[sizeof(CStdAllocAdp)];

#if 0
//--------------------
//単一バッファアロケータアダプタークラス
//※単なるバッファに1回だけアロケートするためのクラス
//※所定のバッファにインスタンスを生成したい場合に用いる
class CMonoAllocAdp : public IAllocator
{
public:
	//型
	//typedef CMonoAllocAdp ALLOCATOR_TYPE;//アロケータ型（アロケータなし）
	typedef unsigned char* byte;//バッファ用
public:
	//アクセッサ
	const char* getName() const override { return "CMonoAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override { return m_buffSize; }//全体メモリ量取得
	std::size_t getUsed() const override { return m_isAllocated ? m_buffSize : 0; }//使用中メモリ量取得
	std::size_t getRemain() const override { return m_isAllocated ? 0 : m_buffSize; }//残りメモリ量取得
	const byte* getBuff() const { return m_buffPtr; }//バッファ取得
	std::size_t getBuffSize() const { return m_buffSize; }//バッファサイズ取得
	bool isAllocated() const { return m_isAllocated; }//メモリ確保済み
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		if (m_isAllocated)
			return nullptr;
		m_isAllocated = true;//メモリ確保済み
		return m_buffPtr;
	}
	//メモリ解放
	void free(void* p) override
	{
		if (!p)
			return;
		if (!m_isAllocated)
			return;
		m_isAllocated = false;//メモリ確保済み解除
	}
public:
	//デフォルトコンストラクタ
	CMonoAllocAdp() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CMonoAllocAdp(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//バッファアドレス
		m_buffSize(buff_size),//バッファサイズ
		m_isAllocated(false)//メモリ確保済み
	{}
	//デストラクタ
	~CMonoAllocAdp() override
	{}
private:
	//フィールド
	byte* m_buffPtr;//バッファアドレス
	const std::size_t m_buffSize;//バッファサイズ
	bool m_isAllocated;//メモリ確保済み
};

//--------------------
//バッファ付き単一バッファアロケータアダプターテンプレートクラス
template<std::size_t SIZE>
class CMonoAllocAdpWithBuff : public CMonoAllocAdp
{
public:
	//定数
	static const std::size_t BUFF_SIZE = SIZE;//バッファサイズ
public:
	//コンストラクタ
	CMonoAllocAdpWithBuff() :
		CMonoAllocAdp(m_buff, BUFF_SIZE)
	{}
	//デストラクタ
	~CMonoAllocAdpWithBuff() override
	{}
private:
	//フィールド
	byte m_buff[BUFF_SIZE];//バッファ
};
#endif

//--------------------
//スタックアロケータインターフェースアダプタークラス
//※スタックアロケータ／双方向スタックアロケータ両用のアダプター
class CIStackAllocAdp : public IAllocator
{
public:
	//型
	typedef IStackAllocator ALLOCATOR_TYPE;//アロケータ型
public:
	//定数
	//自動巻き戻し
	enum E_AUTO_REWIND
	{
		NOREWIND = 0,//巻き戻しなし
		AUTO_REWIND = 1,//指定のスタック順に巻き戻し
		BOTH_AUTO_REWIND = 2,//両方向に巻き戻し（双方向スタックアロケータのみ）
	};
public:
	//アクセッサ
	const char* getName() const override { return "CIStackAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override { return m_allocator.getTotal(); }//全体メモリ量取得
	std::size_t getUsed() const override { return m_allocator.getUsed(); }//使用中メモリ量取得
	std::size_t getRemain() const override { return m_allocator.getRemain(); }//残りメモリ量取得
	IStackAllocator& getAllocator(){ return m_allocator; }//アロケータ取得
	const IStackAllocator& getAllocator() const { return m_allocator; }//アロケータ取得
	E_AUTO_REWIND getAutoRewind() const { m_autoRewind; }//自動巻き戻し指定取得
	void setAutoRewind(const E_AUTO_REWIND auto_rewind){ m_autoRewind = auto_rewind; }//自動巻き戻し指定更新
	IStackAllocator::marker_t getRewindMarker() const { return m_rewindMarker; }//巻き戻しマーカー取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		return m_allocator.alloc(size, align);//virtualメンバーを使う
	}
	//メモリ解放
	void free(void* p) override
	{
		//なにもしない
	}
public:
	//デフォルトコンストラクタ
	CIStackAllocAdp() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CIStackAllocAdp(IStackAllocator& allocator, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		m_allocator(allocator),//スタックアロケータ
		m_autoRewind(auto_rewind)//自動巻き戻し指定
	{
		//自動巻き戻し位置記憶
		m_rewindMarker = m_allocator.getMarker();
	}
	//デストラクタ
	~CIStackAllocAdp() override
	{
		//自動巻き戻し
		if (m_autoRewind == AUTO_REWIND)
		{
			m_allocator.back(m_rewindMarker);
		}
	}
protected:
	//フィールド
	IStackAllocator& m_allocator;//スタックアロケータ
	E_AUTO_REWIND m_autoRewind;//自動巻き戻し指定
	IStackAllocator::marker_t m_rewindMarker;//巻き戻しマーカー
};

//--------------------
//スタックアロケータアダプタークラス
//※スタックアロケータ用のアダプター
class CStackAllocAdp : public CIStackAllocAdp
{
public:
	//型
	typedef CStackAllocator ALLOCATOR_TYPE;//アロケータ型
public:
	//アクセッサ
	const char* getName() const override { return "CStackAllocAdp"; }//アロケータ名取得
	CStackAllocator& getAllocator(){ return *static_cast<CStackAllocator*>(&m_allocator); }//アロケータ取得
	const CStackAllocator& getAllocator() const { return *static_cast<CStackAllocator*>(&m_allocator); }//アロケータ取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CStackAllocator& allocator = getAllocator();
		return allocator.allocN(size, align);//非virtualメンバーを使う
	}
	//メモリ解放
	void free(void* p) override
	{
		//なにもしない
	}
public:
	//デフォルトコンストラクタ
	CStackAllocAdp() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CStackAllocAdp(CStackAllocator& allocator, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		CIStackAllocAdp(allocator, auto_rewind)//スタックアロケータ
	{}
	//デストラクタ
	~CStackAllocAdp() override
	{}
};

#if 0
//--------------------
//双方向スタックアロケータアダプタークラス
class CDualStackAllocAdp : public CIStackAllocAdp
{
public:
	//型
	typedef CDualStackAllocator ALLOCATOR_TYPE;//アロケータ型
public:
	//アクセッサ
	const char* getName() const override { return "CDualStackAllocAdp"; }//アロケータ名取得
	CDualStackAllocator& getAllocator(){ return *static_cast<CDualStackAllocator*>(&m_allocator); }//アロケータ取得
	const CDualStackAllocator& getAllocator() const { return *static_cast<CDualStackAllocator*>(&m_allocator); }//アロケータ取得
	IStackAllocator::E_ORDERED getOrdered() const { return m_ordered; }//スタック順取得
	void setOrdered(const IStackAllocator::E_ORDERED ordered){ m_ordered = ordered; }//スタック順更新
	IStackAllocator::marker_t getRewindMarkerN() const { return m_rewindMarker; }//巻き戻しマーカー（正順）取得
	IStackAllocator::marker_t getRewindMarkerR() const { return m_rewindMarkerR; }//巻き戻しマーカー（逆順）取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CDualStackAllocator& allocator = getAllocator();
		return allocator.alloc(m_ordered, size, align);//非virtualメンバーを使う
	}
	//メモリ解放
	void free(void* p) override
	{
		//なにもしない
	}
public:
	//デフォルトコンストラクタ
	CDualStackAllocAdp() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CDualStackAllocAdp(CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		CIStackAllocAdp(allocator, auto_rewind),//双方向スタックアロケータ
		m_ordered(ordered)//スタック順
	{
		//自動巻き戻し位置記憶
		m_rewindMarker = allocator.getMarkerN();//正順
		m_rewindMarkerR = allocator.getMarkerR();//逆順
	}
	//デストラクタ
	~CDualStackAllocAdp() override
	{
		//自動巻き戻し
		if (m_autoRewind == BOTH_AUTO_REWIND)
		{
			//両方向の巻き戻し
			CDualStackAllocator& allocator = getAllocator();
			allocator.backN(m_rewindMarker);//正順
			allocator.backR(m_rewindMarkerR);//逆順
		}
		else if (m_autoRewind == AUTO_REWIND)
		{
			//単方向の巻き戻し
			CDualStackAllocator& allocator = getAllocator();
			if (m_ordered == IStackAllocator::NORMAL)//正順スタックのみ
				allocator.backN(m_rewindMarker);
			else if (m_ordered == IStackAllocator::REVERSE)//逆順スタックのみ
				allocator.backR(m_rewindMarkerR);
			else//if (m_ordered == IStackAllocator::DEFAULT)//アロケータのデフォルトスタック順に従う
			{
				//	allocator.backD(m_rewindMarker);//このメソッドは使わない
				if (allocator.getDefaultOrdered() == IStackAllocator::REVERSE)//逆順スタックのみ
					allocator.backR(m_rewindMarkerR);
				else//if (allocator.getDefaultOrdered() == IStackAllocator::NORMAL)//正順スタックのみ
					allocator.backN(m_rewindMarker);
			}
		}
		m_autoRewind = NOREWIND;//親クラスのデストラクタ処理で問題が起こらないように設定を無効化する
	}
private:
	//フィールド
	IStackAllocator::E_ORDERED m_ordered;//スタック順
	//IStackAllocator::marker_t m_rewindMarker;//巻き戻しマーカー（正順）※親クラスの変数を使用
	IStackAllocator::marker_t m_rewindMarkerR;//巻き戻しマーカー（逆順）
};
#endif

#if 0
//--------------------
//スマートスタックアロケータアダプタークラス
class CSmartStackAllocAdp : public CIStackAllocAdp
{
public:
	//型
	typedef CSmartStackAllocator ALLOCATOR_TYPE;//アロケータ型
public:
	//アクセッサ
	const char* getName() const override{ return "CSmartStackAllocAdp"; }//アロケータ名取得
	CSmartStackAllocator& getAllocator(){ return *static_cast<CSmartStackAllocator*>(&m_allocator); }//アロケータ取得
	const CSmartStackAllocator& getAllocator() const { return *static_cast<CSmartStackAllocator*>(&m_allocator); }//アロケータ取得
	IStackAllocator::E_ORDERED getOrdered() const { return m_ordered; }//スタック順取得
	void setOrdered(const IStackAllocator::E_ORDERED ordered){ m_ordered = ordered; }//スタック順更新
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CSmartStackAllocator& allocator = getAllocator();
		return allocator.alloc(m_ordered, size, align);//非virtualメンバーを使う
	}
	//メモリ解放
	void free(void* p) override
	{
		CSmartStackAllocator& allocator = getAllocator();
		return allocator.free(p);
	}
public:
	//デフォルトコンストラクタ
	CSmartStackAllocAdp() = delete;//コンストラクタ引数必須
	//コンストラクタ
	//※自動巻き戻しには対応しない
	CSmartStackAllocAdp(CSmartStackAllocator& stack, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) :
		CIStackAllocAdp(stack, NOREWIND),//スマートスタックアロケータ
		m_ordered(ordered)//スタック順
	{}
	//デストラクタ
	~CSmartStackAllocAdp() override
	{}
private:
	//フィールド
	IStackAllocator::E_ORDERED m_ordered;//スタック順
};
#endif

//--------------------
//プールアロケータアダプタークラス
class CPoolAllocAdp : public IAllocator
{
public:
	//型
	typedef CPoolAllocator ALLOCATOR_TYPE;//アロケータ型
public:
	//アクセッサ
	const char* getName() const override { return "CPoolAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override { return m_allocator.getBlocksNum() * m_allocator.getBlockSize(); }//全体メモリ量取得
	std::size_t getUsed() const override { return m_allocator.getUsed() * m_allocator.getBlockSize(); }//使用中メモリ量取得
	std::size_t getRemain() const override { return m_allocator.getRemain() * m_allocator.getBlockSize(); }//残りメモリ量取得
	CPoolAllocator& getAllocator() const { return m_allocator; }//アロケータ取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		return m_allocator.alloc(size);
	}
	//メモリ解放
	void free(void* p) override
	{
		return m_allocator.free(p);
	}
public:
	//デフォルトコンストラクタ
	CPoolAllocAdp() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CPoolAllocAdp(CPoolAllocator& allocator) :
		m_allocator(allocator)//プールアロケータ
	{}
	//デストラクタ
	~CPoolAllocAdp() override
	{}
private:
	//フィールド
	CPoolAllocator& m_allocator;//プールアロケータ
};

//--------------------------------------------------------------------------------
//グローバルnew/delete + 共通アロケータインターフェース

//--------------------
//クラス宣言
class CTempPolyAllocatorBase;//一時多態アロケータ基底クラス

//--------------------
//多態アロケータ
class CPolyAllocator
{
#ifdef USE_FRIEND_WITH_NEW_OPERATOR
	//標準 new / deleete 演算子をフレンド化
	//※この CPolyAllocator クラスを直接インスタンス化するのは new / delete 演算子のみ
	friend void* operator new(const std::size_t size) throw();
	friend void* operator new[](const std::size_t size) throw();
	friend void operator delete(void* p) throw();
	friend void operator delete[](void* p) throw();
#endif//USE_FRIEND_WITH_NEW_OPERATOR
	friend class CTempPolyAllocatorBase;//一時多態アロケータ基底クラス
public:
	//オペレータ
	IAllocator* operator->(){ return m_allocator; }//アロー演算子（プロキシー）
public:
	//アクセッサ
	//アロケータ取得
	static IAllocator* getAllocator()
	{
		return m_allocator;
	}
	//アロケータ変更
	//※戻りとして変更前のアロケータを返す
	//※なるべく直接使用禁止⇒CTempPoly***Allocatorクラスを使い、コンストラクタで自動的に元に戻す
	static IAllocator* setAllocator(IAllocator& new_allocator)
	{
		IAllocator* prev_allocator = m_allocator;//変更前のアロケータ取得
		m_allocator = &new_allocator;//アロケータ変更
		return prev_allocator;//変更前のアロケータを返す
	}
	//メモリ確保情報取得
	static const ALLOC_INFO* getAllocInfo()
	{
		return m_allocInfo;
	}
	//メモリ確保情報取得と同時に情報を破棄
	static const ALLOC_INFO* getAllocInfoWithReset()
	{
		const ALLOC_INFO* info = m_allocInfo;
		m_allocInfo = nullptr;
		return info;
	}
	//メモリ確保情報をセット
	static void setAllocInfo(const ALLOC_INFO* info)
	{
		m_allocInfo = info;
	}
#ifdef USE_FRIEND_WITH_NEW_OPERATOR
private://直接インスタンス生成不可（フレンド専用）
#else//USE_FRIEND_WITH_NEW_OPERATOR
public:
#endif//USE_FRIEND_WITH_NEW_OPERATOR
	//デフォルトコンストラクタ
	CPolyAllocator()
	{
		if (!m_allocator)//まだ何のアロケータも保持していない場合標準アロケータを自動的に保持する
			m_allocator = new CStdAllocAdp();//標準アロケータを明示的に初期化（クラス内newを使用）
	}
public:
	//デストラクタ
	~CPolyAllocator()
	{}
protected:
	//フィールド
	static thread_local IAllocator* m_allocator;//現在のアロケータ
	static thread_local const ALLOC_INFO* m_allocInfo;//現在のメモリ確保情報
	//TLSを利用し、アロケータの変更が他のスレッドに影響しないようにする
};
//--------------------
//多態アロケータの静的変数インスタンス化
thread_local IAllocator* CPolyAllocator::m_allocator = nullptr;//現在のアロケータ
thread_local const ALLOC_INFO* CPolyAllocator::m_allocInfo = nullptr;//現在のメモリ確保情報

//--------------------
//メモリ確保情報
//※デバッグ情報（参照のみ）
struct ALLOC_INFO
{
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//デフォルトのアラインメントサイズ
	const char* m_fileName;//ファイル名
	const char* m_funcName;//関数名
	const char* m_callPointName;//コールポイント名
	float m_time;//ゲーム時間
	const char* m_typeName;//型名
	std::size_t m_align;//アラインメントサイズ
	ALLOC_INFO(const char* file_name, const char* func_name, const char* call_point_name, const float time, const char* type_name, const std::size_t align = DEFAULT_ALIGN) :
		m_fileName(file_name),
		m_funcName(func_name),
		m_callPointName(call_point_name),
		m_time(time),
		m_typeName(type_name),
		m_align(align)
	{}
};

//--------------------
//グローバル多態アロケータ
//※標準new / delete 演算子の置き換え
//new
void* operator new(const std::size_t size) throw()
{
	CPolyAllocator allocator;
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//メモリ確保情報取得
	if (info)
		align = info->m_align;
	void* p = allocator->alloc(size, align);
	return p;
}
//配列版
void* operator new[](const std::size_t size) throw()
{
	CPolyAllocator allocator;
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//メモリ確保情報取得
	if (info)
		align = info->m_align;
	void* p = allocator->alloc(size, align);
	return p;
}
//delete
void operator delete(void* p) throw()
{
	CPolyAllocator allocator;
	allocator->free(p);
}
//配列版
void operator delete[](void* p) throw()
{
	CPolyAllocator allocator;
	allocator->free(p);
}

#if 0
//--------------------
//デバッグ情報収集用関数参照
const char* getCurrentCallPointNameDummy();//コールポイント名取得
float getGameTimeDummy();//ゲーム時間取得

//--------------------
//メモリ確保情報付きNEW処理
template<class T, typename... Tx>
T* newWithInfo(const char* file_name, const char* func_name, const std::size_t align, Tx ...nx)
{
	const char* call_point_name = getCurrentCallPointNameDummy();//コールポイント名取得
	const float game_time = getGameTimeDummy();//ゲーム時間取得
	const ALLOC_INFO info(file_name, func_name, call_point_name, game_time, typeid(T).name(), align);//メモリ確保情報生成
	CPolyAllocator::setAllocInfo(&info);//メモリ確保情報受け渡し ※ローカル変数のポインタを受け渡すことになるが、後続の処理でのみ参照することと、TLSで保護されるため問題なし
	return new T(nx...);//メモリ確保
}
//配列版
//※【問題点】配列newにアラインメントが指定された場合、正しいポインタが計算しきれないため、アラインメント指定に対応しない
template<class T, std::size_t array_size>
T* newArrayWithInfo(const char* file_name, const char* func_name)
{
	const char* call_point_name = getCurrentCallPointNameDummy();//コールポイント名取得
	const float game_time = getGameTimeDummy();//ゲーム時間取得
	const ALLOC_INFO info(file_name, func_name, call_point_name, game_time, typeid(T[array_size]).name());//メモリ確保情報生成
	CPolyAllocator::setAllocInfo(&info);//メモリ確保情報受け渡し ※ローカル変数のポインタを受け渡すことになるが、後続の処理でのみ参照することと、TLSで保護されるため問題なし
	return new T[array_size];//メモリ確保
}

//--------------------
//NEWマクロ
//※メモリ確保情報付き
#define NEW(T, ...) newWithInfo<T>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME(), ALLOC_INFO::DEFAULT_ALIGN, ##__VA_ARGS__)//NEW
#define NEWALIGN(T, align, ...) newWithInfo<T>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME(), align, ##__VA_ARGS__)//アラインメント指定付きNEW
#define NEWARR(T, array_size) newArrayWithInfo<T, array_size>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME())//配列NEW
//#define NEWALIGNARR(T, align, array_size)//アライメント指定付き配列NEWは正確に計算できないので対応しない
//--------------------
//DELETEマクロ
#ifdef DELETE
#undef DELETE
#endif//DELETE
#define DELETE delete//DELETE
#define DELETEARR delete[]//配列DELETE
#endif

//--------------------
//一時多態アロケータ
//※多態アロケータの「現在のアロケータ」を一時的に変更するためのクラス
//※処理ブロックを抜ける時に、デストラクタで自動的に元の状態に戻す

//--------------------
//一時多態アロケータ基底クラス
//※継承専用クラス
class CTempPolyAllocatorBase : public CPolyAllocator
{
protected://直接インスタンス生成不可（継承専用）
	//デフォルトコンストラクタ
	CTempPolyAllocatorBase() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CTempPolyAllocatorBase(IAllocator& allocator) :
		CPolyAllocator()
	{
		m_prevAllocator = setAllocator(allocator);//アロケータを変更して、変更前のアロケータを記憶
	}
public:
	//デストラクタ
	~CTempPolyAllocatorBase()
	{
		if (m_prevAllocator)
		{
			m_allocator = m_prevAllocator;//変更前のアロケータに戻す
			m_prevAllocator = nullptr;
		}
	}
private:
	//フィールド
	IAllocator* m_prevAllocator;//変更前のアロケータ
};
//--------------------
//一時多態アロケータテンプレートクラス：アダプター保持タイプ
template<class ADAPTER>
class CTempPolyAllocatorWithAdp : public CTempPolyAllocatorBase
{
public:
	//型
	typedef ADAPTER ADAPTER_TYPE;//アダプター型
	typedef typename ADAPTER::ALLOCATOR_TYPE ALLOCATOR_TYPE;//アロケータ型
public:
	//デフォルトコンストラクタ
	CTempPolyAllocatorWithAdp() :
		m_adapter(),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//コンストラクタ
	CTempPolyAllocatorWithAdp(ALLOCATOR_TYPE& allocator) :
		m_adapter(allocator),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//デストラクタ
	~CTempPolyAllocatorWithAdp()
	{}
protected:
	//フィールド
	ADAPTER_TYPE m_adapter;//アロケータアダプター
};
//--------------------
//一時多態アロケータテンプレートクラス：アダプター直接利用タイプ
//※アダプターを保持せず外部から受け渡したものをそのまま利用する
template<class ADAPTER>
class CTempPolyAllocatorDirect : public CTempPolyAllocatorBase
{
public:
	//型
	typedef ADAPTER ADAPTER_TYPE;//アダプター型
public:
	//デフォルトコンストラクタ
	CTempPolyAllocatorDirect() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CTempPolyAllocatorDirect(ADAPTER_TYPE& adapter) :
		CTempPolyAllocatorBase(adapter)
	{}
	//デストラクタ
	~CTempPolyAllocatorDirect()
	{}
};
//--------------------
//一時多態アロケータテンプレートクラス：スタックアロケータアダプター保持タイプ
template<class ADAPTER>
class CTempPolyAllocatorWithStackAdp : public CTempPolyAllocatorBase
{
public:
	//型
	typedef ADAPTER ADAPTER_TYPE;//アダプター型
	typedef typename ADAPTER::ALLOCATOR_TYPE ALLOCATOR_TYPE;//アロケータ型
public:
	//デフォルトコンストラクタ
	CTempPolyAllocatorWithStackAdp() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind) :
		m_adapter(allocator, auto_rewind),
		CTempPolyAllocatorBase(m_adapter)
	{}
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const IStackAllocator::E_ORDERED ordered, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind) :
		m_adapter(allocator, ordered, auto_rewind),
		CTempPolyAllocatorBase(m_adapter)
	{}
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const IStackAllocator::E_ORDERED ordered) :
		m_adapter(allocator, ordered),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//デストラクタ
	~CTempPolyAllocatorWithStackAdp()
	{}
protected:
	//フィールド
	ADAPTER_TYPE m_adapter;//アロケータアダプター
};
//--------------------
//一時多態アロケータクラス：標準アロケータ用
using CTempPolyStdAllocator = CTempPolyAllocatorWithAdp<CStdAllocAdp>;//C++11形式
#if 0
//--------------------
//一時多態アロケータクラス：単一バッファアロケータ用
using CTempPolyMonoAllocator = CTempPolyAllocatorDirect<CMonoAllocAdp>;//C++11形式
#endif
//--------------------
//一時多態アロケータクラス：スタックアロケータインターフェース用
class CTempPolyIStackAllocator : public CTempPolyAllocatorWithStackAdp<CIStackAllocAdp>
{
public:
	//デフォルトコンストラクタ
	CTempPolyIStackAllocator() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CTempPolyIStackAllocator(IStackAllocator& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CIStackAllocAdp>(allocator, auto_rewind)
	{}
	//デストラクタ
	~CTempPolyIStackAllocator()
	{}
};
//--------------------
//一時多態アロケータクラス：スタックアロケータ用
class CTempPolyStackAllocator : public CTempPolyAllocatorWithStackAdp<CStackAllocAdp>
{
public:
	//デフォルトコンストラクタ
	CTempPolyStackAllocator() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CTempPolyStackAllocator(CStackAllocator& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CStackAllocAdp>(allocator, auto_rewind)
	{}
	//デストラクタ
	~CTempPolyStackAllocator()
	{}
};
#if 0
//--------------------
//一時多態アロケータクラス：双方向スタックアロケータ用
class CTempPolyDualStackAllocator : public CTempPolyAllocatorWithStackAdp<CDualStackAllocAdp>
{
public:
	//デフォルトコンストラクタ
	CTempPolyDualStackAllocator() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CTempPolyDualStackAllocator(CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CDualStackAllocAdp>(allocator, ordered, auto_rewind)
	{}
	//デストラクタ
	~CTempPolyDualStackAllocator()
	{}
};
#endif
#if 0
//--------------------
//一時多態アロケータクラス：スマートスタックアロケータ用
class CTempPolySmartStackAllocator : public CTempPolyAllocatorWithStackAdp<CSmartStackAllocAdp>
{
public:
	//デフォルトコンストラクタ
	CTempPolySmartStackAllocator() = delete;//コンストラクタ引数必須
	//コンストラクタ
	CTempPolySmartStackAllocator(CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) :
		CTempPolyAllocatorWithStackAdp<CSmartStackAllocAdp>(allocator, ordered)
	{}
	//デストラクタ
	~CTempPolySmartStackAllocator()
	{}
};
#endif
//--------------------
//一時多態アロケータクラス：プールアロケータ用
using CTempPolyPoolAllocator = CTempPolyAllocatorWithAdp<CPoolAllocAdp>;//C++11形式

//--------------------------------------------------------------------------------
//簡易プロファイラ
namespace dbg
{
	//----------------------------------------
	//プロファイラクラス
	class CProfiler
	{
	public:
		//定数
		static const std::size_t BUFF_SIZE = 64 * 1024;//記録用のバッファ
	public:
		//型
		typedef CStackAllocatorWithBuff<BUFF_SIZE> buffer_t;//バッファ型
		typedef uintptr_t key_t;//キー型
		//プロファイル
		struct PROFILE
		{
			key_t m_key;//キー
			std::string m_name;//処理名
			THREAD_ID m_threadId;//スレッドID
			std::string m_threadName;//スレッド名
			std::string m_srcFileName;//ソースファイル名
			std::string m_funcName;//関数名
			struct TIME
			{
				double sum;//処理時間の合計
				float max;//最大の処理時間
				float min;//最小の処理時間
				int count;//計測回数
				float average() const { return count == 0 ? 0 : static_cast<float>(sum / static_cast<double>(count)); }
				//計測時間集計
				void add(const double time)
				{
					++count;
					sum += time;
					const float time_f = static_cast<float>(time);
					if (max == 0.f || max < time_f)
						max = time_f;
					if (min == 0.f || min > time_f)
						min = time_f;
				}
				//計測時間集計
				void add(const TIME& time)
				{
					count += time.count;
					sum += time.sum;
					if (max == 0.f || max < time.max)
						max = time.max;
					if (min == 0.f || min > time.min)
						min = time.min;
				}
				//計測時間リセット
				void reset()
				{
					sum = 0.;
					max = 0.f;
					min = 0.f;
					count = 0;
				}
				//コピー演算子
				TIME& operator=(TIME& rhs)
				{
					memcpy(this, &rhs, sizeof(*this));
					return *this;
				}
			};
			TIME m_total;//処理全体の集計
			TIME m_frame;//フレーム内の集計
			bool m_inCountOnFrame;//フレームの集計があったか？
			int m_frameCount;//計測フレーム数
			float m_time;//（前回計測時の）処理時間
			//計測時間を加算
			void add(const double time)
			{
				m_time = static_cast<float>(time);
				m_frame.add(time);
				m_inCountOnFrame = true;
			}
			//フレーム集計
			void sumOnFrame()
			{
				if (m_inCountOnFrame)
				{
					m_inCountOnFrame = false;
					m_total.add(m_frame);
					m_frame.reset();
					++m_frameCount;
				}
			}
			//ムーブコンストラクタ
			//※要素追加の際の無駄なオブジェクト生成と破棄を防ぐ
			//　（std::string向けの対処：std::move()を使って受け渡し）
			PROFILE(PROFILE&& src) :
				m_key(src.m_key),
				m_name(std::move(src.m_name)),
				m_threadId(src.m_threadId),
				m_threadName(std::move(src.m_threadName)),
				m_srcFileName(std::move(src.m_srcFileName)),
				m_funcName(std::move(src.m_funcName)),
				m_inCountOnFrame(src.m_inCountOnFrame),
				m_frameCount(src.m_frameCount),
				m_time(src.m_time)
			{
				m_total = src.m_total;
				m_frame = src.m_frame;
			}
			//コンストラクタ
			PROFILE(const key_t key, const char* name, const THREAD_ID thread_id, const char* thread_name, const char* src_file_name, const char* func_name) :
				m_key(key),
				m_name(name),
				m_threadId(thread_id),
				m_threadName(thread_name),
				m_srcFileName(src_file_name),
				m_funcName(func_name),
				m_inCountOnFrame(false),
				m_frameCount(0),
				m_time(0.f)
			{
				m_total.reset();
				m_frame.reset();
			}
		};
		typedef std::unordered_map<key_t, PROFILE> table_t;//ハッシュテーブル型
		typedef table_t::iterator iterator;//イテレータ型
		typedef table_t::const_iterator const_iterator;//イテレータ型
	public:
		//アクセッサ
		std::size_t getBuffTotal()const{ return m_buff.getTotal(); }
		std::size_t getBuffUsed()const{ return m_buff.getUsed(); }
		std::size_t getBuffRemain()const{ return m_buff.getRemain(); }
	public:
		//メソッド
		//プロファイル追加／集計
		void addProfile(const key_t key, const char* name, const CThreadID* thread_id, const char* src_file_name, const char* func_name, const double time)
		{
			m_lock.lock();
			THREAD_ID thread_id_ = INITIAL_THREAD_ID;
			const char* thread_name = "(unknown)";
			if (thread_id)
			{
				thread_id_ = thread_id->getID();
				thread_name = thread_id->getName();
			}
			CTempPolyStackAllocator allocator(m_buff);
			PROFILE* profile = nullptr;
			{
				table_t::iterator ite = m_table->find(key);
				if (ite != m_table->end())
					profile = &ite->second;
				else
				{
					m_table->emplace(key, std::move(PROFILE(key, name, thread_id_, thread_name, src_file_name, func_name)));
					ite = m_table->find(key);
					if (ite != m_table->end())
						profile = &ite->second;
				}
			}
			if (profile)
			{
				profile->add(time);
			}
			m_lock.unlock();
		}
		//フレーム集計
		void sumOnFrame()
		{
			m_lock.lock();
			for (auto& ite : *m_table)
			{
				PROFILE* profile = &ite.second;
				profile->sumOnFrame();
			}
			m_lock.unlock();
		}
		//イテレータ取得
		std::size_t size() const { return m_table->size(); }
		//table_t::iterator begin() { return m_table->begin(); }
		//table_t::iterator end() { return m_table->end(); }
		table_t::const_iterator begin() const { return m_table->begin(); }
		table_t::const_iterator end() const { return m_table->end(); }
		table_t::const_iterator cbegin() const { return m_table->cbegin(); }
		table_t::const_iterator cend() const { return m_table->cend(); }
		//テーブル生成
		void createTable()
		{
			m_lock.lock();
			if (!m_table)
			{
				CTempPolyStackAllocator allocator(m_buff);
				m_table = new table_t();
				m_table->reserve(1024);
			}
			m_lock.unlock();
		}
		//テーブル破棄
		void destroyTable()
		{
			m_lock.lock();
			if (m_table)
			{
				CTempPolyStackAllocator allocator(m_buff);
				delete m_table;
				m_table = nullptr;
				m_buff.clearN();
			}
			m_lock.unlock();
		}
		//テーブルをリセット
		void resetTable()
		{
			destroyTable();
			createTable();
		}
	public:
		//コンストラクタ
		CProfiler()
		{
			createTable();
		}
		//デストラクタ
		~CProfiler()
		{
		}
	private:
		//フィールド
		static table_t* m_table;//ハッシュテーブル
		static buffer_t m_buff;//記録用バッファ
		static CSpinLock m_lock;//ロック
	};
	//----------------------------------------
	//プロファイラの静的変数をインスタンス化
	CProfiler::table_t* CProfiler::m_table;//ハッシュテーブル
	CProfiler::buffer_t CProfiler::m_buff;//記録用バッファ
	CSpinLock CProfiler::m_lock;//ロック
}//dbg

//--------------------------------------------------------------------------------
//デバッグメッセージ
namespace dbg
{
	//----------------------------------------
	//コンソールカラークラス
	class color
	{
	public:
		//型
		//ハンドル型
	#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
		typedef HANDLE handle_t;
	#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
		typedef FILE* handle_t;
	#endif//USE_WINDOWS_CONSOLE_COLOR
	public:
		//定数
		//カラー値
		enum color_t : unsigned char
		{
			reset = 0x10,//リセット
			through = 0x20,//スルー（現状維持：何もしない）

		#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
			R = 0x04,//Red:赤
			G = 0x02,//Green:緑
			B = 0x01,//Blue:青
			I = 0x08,//Intensity:鮮やか
			BG_SHIFT = 4,//背景色指定時のビットシフト数
		#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
			R = 0x01,//Red:赤
			G = 0x02,//Green:緑
			B = 0x04,//Blue:青
			I = 0x08,//high Intensity:鮮やか
		#endif//USE_WINDOWS_CONSOLE_COLOR

			RGB = 0x07,//RGBマスク
			RGBI = 0x0f,//RGB+Iマスク

			//標準カラー
			black = 0,//黒
			blue = B,//青
			red = R,//赤
			magenta = R | B,//紫
			green = G,//緑
			cyan = G | B,//水
			yellow = G | R,//黄
			white = G | R | B,//白

			//鮮やかなカラー
			iBlack = I | black,//黒
			iBlue = I | blue,//青
			iRed = I | red,//赤
			iMagenta = I | magenta,//紫
			iGreen = I | green,//緑
			iCyan = I | cyan,//水
			iYellow = I | yellow ,//黄
			iWhite = I | white,//白
		};
		//対象
		enum target_t : unsigned char
		{
			stdOut = 0,//対象：標準出力
			stdErr = 1,//対象：標準エラー
		};
		static const int targetNum = 2;
	public:
		//アクセッサ
		target_t getTarget() const { return m_target; }//対象
		color_t getForeColor() const { return m_foreColor; }//カラー：前面
		color_t getBackColor() const { return m_backColor; }//カラー：背面
		color_t getPrevForeColor() const { return m_prevForeColor; }//前のカラー:前面
		color_t getPrevBackColor() const { return m_prevBackColor; }//前のカラー:背面
		bool isAutoRestore() const { return m_isAutoRestore; }//自動カラー復元実行指定
	public:
		//キャストオペレータ
		operator int() const { return static_cast<int>(m_target); }//対象
		operator target_t() const { return m_target; }//対象
	public:
		//メソッド
		//カラー変更
		//※実際にコンソールに反映させる
		void changeColor()
		{
			if (m_foreColor == through)
				return;
			changeColor(m_target, m_foreColor, m_backColor);
		}
		void changeColor(const target_t target, const color_t fore_color, const color_t back_color = black)
		{
			//対象ハンドル取得
			const handle_t target_h = m_handle[target];

			//カラー変更
			if (fore_color == reset)
			{
			#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
				SetConsoleTextAttribute(target_h, m_ConsoleScreenBufferInfo[target].wAttributes);
			#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
				fprintf(target_h, "\x1b[39m\x1b[49m");//"\x1b[0m"
			#endif//USE_WINDOWS_CONSOLE_COLOR
			}
			else
			{
			#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
				SetConsoleTextAttribute(target_h, ((back_color & RGBI) << BG_SHIFT) | (fore_color & RGBI));
			#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
				fprintf(target_h, "\x1b[%dm\x1b[%dm", (fore_color & I ? 90 : 30) + (fore_color & RGB), (back_color & I ? 100 : 40) + (back_color & RGB));
			#endif//USE_WINDOWS_CONSOLE_COLOR
			}
		}
	public:
		//カラー初期化（一回限り）
		static void initializeOnce();
	public:
		//デフォルトコンストラクタ
		color() :
			m_target(stdOut),//対象
			m_foreColor(reset),//カラー：前面
			m_backColor(reset),//カラー：背面
			m_prevForeColor(reset),//前のカラー：前面を記憶
			m_prevBackColor(reset),//前のカラー：背面を記憶
			m_isAutoRestore(false)//自動カラー復元実行指定
		{
			initializeOnce();
		}
		//ムーブコンストラクタ
		color(color&& src) :
			m_target(src.m_target),//対象
			m_foreColor(src.m_foreColor),//カラー：前面
			m_backColor(src.m_backColor),//カラー：背面
			m_prevForeColor(src.m_prevForeColor),//前のカラー：前面を記憶
			m_prevBackColor(src.m_prevBackColor),//前のカラー：背面を記憶
			m_isAutoRestore(src.m_isAutoRestore)//自動カラー復元実行指定
		{
			//ムーブコンストラクタにつき、移動元の内容を改変し、デストラクタが機能しないようにする
			*const_cast<bool*>(&src.m_isAutoRestore) = false;//自動カラー復元実行指定を無効化
		}
		//コンストラクタ
		color(const target_t target, const color_t fore_color, const color_t back_color = black, const bool is_auto_restore = true) :
			m_target(target),//対象
			m_foreColor(fore_color),//カラー：前面
			m_backColor(back_color),//カラー：背面
			m_prevForeColor(m_nowForeColor[m_target]),//前のカラー：前面を記憶
			m_prevBackColor(m_nowBackColor[m_target]),//前のカラー：背面を記憶
			m_isAutoRestore(is_auto_restore)//自動カラー復元実行指定
		{
			if (m_foreColor == through || !m_isAutoRestore)
				return;
			m_nowForeColor[m_target] = m_foreColor;//現在のカラー：前面（記憶用）を更新
			m_nowBackColor[m_target] = m_backColor;//現在のカラー：背面（記憶用）を更新
			changeColor();
		}
		//デストラクタ
		~color()
		{
			if (m_foreColor == through || !m_isAutoRestore)
				return;
			m_nowForeColor[m_target] = m_prevForeColor;//現在のカラー：前面を前のカラーに戻す
			m_nowBackColor[m_target] = m_prevBackColor;//現在のカラー：背面を前のカラーに戻す
			changeColor(m_target, m_prevForeColor, m_prevBackColor);
		}
	private:
		//フィールド
		const target_t m_target;//対象
		const color_t m_foreColor;//カラー：前面
		const color_t m_backColor;//カラー：背面
		const color_t m_prevForeColor;//前のカラー：前面
		const color_t m_prevBackColor;//前のカラー：背面
		const bool m_isAutoRestore;//自動カラー復元実行指定
		static bool m_isInitialized;//初期化済み
		static color_t m_nowForeColor[color::targetNum];//現在のカラー：前面（記憶用）
		static color_t m_nowBackColor[color::targetNum];//現在のカラー：背面（記憶用）
	#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
		static handle_t m_handle[color::targetNum];//ハンドル
		static CONSOLE_SCREEN_BUFFER_INFO m_ConsoleScreenBufferInfo[color::targetNum];//コンソールスクリーンバッファ（リセット用）
	#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用	
		static const handle_t m_handle[color::targetNum];//ハンドル
	#endif//USE_WINDOWS_CONSOLE_COLOR
	};
	//----------------------------------------
	//カラーの静的変数をインスタンス化
	bool color::m_isInitialized = false;
	color::color_t color::m_nowForeColor[color::targetNum] =//現在のカラー：前面（記憶用）
	{
		color::reset,//標準出力用
		color::reset,//標準エラー用
	};
	color::color_t color::m_nowBackColor[color::targetNum] =//現在のカラー：背面（記憶用）
	{
		color::reset,//標準出力用
		color::reset,//標準エラー用
	};
#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
	color::handle_t color::m_handle[color::targetNum];
	CONSOLE_SCREEN_BUFFER_INFO color::m_ConsoleScreenBufferInfo[color::targetNum];//Windows用のリセット用カラー情報
#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
	const color::handle_t color::m_handle[] =
	{
		stdout,//標準出力ハンドル
		stderr,//標準エラーハンドル
	};
#endif//USE_WINDOWS_CONSOLE_COLOR
	//----------------------------------------
	//コンソールカラー初期化（一回限り）
	void color::initializeOnce()
	{
		//初期化済みチェック
		if (m_isInitialized)
			return;
		//静的変数を初期化
		m_isInitialized = true;
#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
		//ハンドル
		m_handle[stdOut] = GetStdHandle(STD_OUTPUT_HANDLE);//標準出力ハンドル
		m_handle[stdErr] = GetStdHandle(STD_ERROR_HANDLE);//標準エラーハンドル
		//カラー変更開始
		GetConsoleScreenBufferInfo(m_handle[stdOut], &m_ConsoleScreenBufferInfo[stdOut]);
		GetConsoleScreenBufferInfo(m_handle[stdErr], &m_ConsoleScreenBufferInfo[stdErr]);
#endif//USE_WINDOWS_CONSOLE_COLOR
	}
	//----------------------------------------
	//コンソールカラー用変数
	static color s_colorForInitialize;//初期化処理実行のためのインスタンス

	//----------------------------------------
	//レベルクラス
	class level
	{
	public:
		//型
		typedef unsigned char value_t;//値（レベル）
		typedef unsigned char byte;//バッファ用
	private:
		//定数（計算用）
		#define calcAsOutput(value) ((value) >> 1)//値を出力レベルに変換
		#define calcAsValue(value) ((value) << 1)//出力レベルを値に変換
	public:
		//定数
		static const value_t NORMAL_NUM = 11;//通常レベル数
		static const value_t SPECIAL_NUM = 2;//特殊レベル数
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;//レベル総数
		static const value_t MIN = 0;//レベル最小値
		static const value_t MAX = NUM - 1;//レベル最大値
		static const value_t NORMAL_MIN = MIN;//通常レベル最小値
		static const value_t NORMAL_MAX = NORMAL_MIN + NORMAL_NUM - 1;//通常レベル最大値
		static const value_t SPECIAL_MIN = NORMAL_MAX + 1;//特殊レベル最小値
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//特殊レベル最大値
		static const value_t BEGIN = MIN;//レベル開始値（イテレータ用）
		static const value_t END = NUM;//レベル終端値（イテレータ用）
		static const value_t POOL_NUM = NUM + 1;//レベル記録数
		static const value_t OUTPUT_LEVEL_MIN = calcAsOutput(NORMAL_MIN);//出力レベル最小値
		static const value_t OUTPUT_LEVEL_MAX = calcAsOutput(NORMAL_MAX);//出力レベル最大値
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");//定数チェック
	public:
		//型
		//--------------------
		//イテレータ
		class iterator : public std::iterator<std::bidirectional_iterator_tag, level>//双方向イテレータとして実装
		{
		public:
			//オペレータ
			const level* operator->() const { return &container::get(m_value); }
			const level& operator*() const { return container::get(m_value); }
			bool operator==(const iterator rhs) const { return m_value == rhs.m_value; }
			bool operator!=(const iterator rhs) const { return m_value != rhs.m_value; }
			const level& operator++() const { return m_value >= container::endValue() ? container::getEnd() : container::get(++m_value); }
			const level& operator++(int) const { return m_value >= container::endValue() ? container::getEnd() : container::get(m_value++); }
			const level& operator--() const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getEnd(); } return container::get(--m_value); }
			const level& operator--(int) const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getBegin(); } return container::get(m_value--); }
		public:
			//キャストオペレータ
			operator const level&() const { return container::get(m_value); }//値（レベル）
		public:
			//コンストラクタ
			iterator(const value_t value) :
				m_value(value)
			{}
			iterator(const value_t value, int) :
				m_value(container::endValue())
			{}
			iterator(const level& obj) :
				m_value(obj.value())
			{}
			iterator(const level& obj, int) :
				m_value(container::endValue())
			{}
			iterator() :
				m_value(container::endValue())
			{}
			//デストラクタ
			~iterator()
			{}
		private:
			//フィールド
			value_t mutable m_value;//値（レベル）
		};
		//--------------------
		//constイテレータ
		typedef const iterator const_iterator;
		//--------------------
		//コンテナ（イテレータ用）
		class container
		{
			friend class level;
		public:
			//メソッド
			static const value_t beginValue(){ return BEGIN; }//開始値取得
			static const value_t endValue(){ return END; }//終端値取得
			static const level& get(const value_t value){ return m_poolPtr[value]; }//要素を取得
			static const level& getBegin(){ return m_poolPtr[beginValue()]; }//開始要素を取得
			static const level& getEnd(){ return m_poolPtr[endValue()]; }//終端要素を取得
		private:
			static void set(const value_t value, const level& obj)//要素を更新
			{
				if (!container::m_isAlreadyPool[value])
				{
					container::m_poolPtr[value] = obj;
					container::m_isAlreadyPool[value] = true;
				}
			}
		public:
			static const iterator begin(){ return iterator(beginValue()); }//開始イテレータを取得
			static const iterator end()	{ return iterator(endValue()); }//終端イテレータを取得
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//開始constイテレータを取得
			static const_iterator cend(){ return const_iterator(endValue()); }//終端constイテレータを取得
			//※reverse_iterator非対応
			//メソッド
			//初期化（一回限り）
			static void initializeOnce();
		private:
			//フィールド
			static bool m_isInitialized;//初期化済み
			static level* m_poolPtr;//要素のプール（ポインタ）
			static byte m_pool[];//要素のプール（バッファ）※バッファとポインタを分けているのは、コンストラクタの実行を防止するため
			static std::bitset<POOL_NUM> m_isAlreadyPool;//要素の初期化済みフラグ
		};
	public:
		//オペレータ
		//※出力レベルで比較する
		bool operator ==(const level& rhs) const { return valueAsOutput() == rhs.valueAsOutput(); }
		bool operator !=(const level& rhs) const { return valueAsOutput() != rhs.valueAsOutput(); }
		bool operator >(const level& rhs) const { return valueAsOutput() > rhs.valueAsOutput(); }
		bool operator >=(const level& rhs) const { return valueAsOutput() >= rhs.valueAsOutput(); }
		bool operator <(const level& rhs) const { return valueAsOutput() < rhs.valueAsOutput(); }
		bool operator <=(const level& rhs) const { return valueAsOutput() <= rhs.valueAsOutput(); }
	private:
		//コピーオペレータ
		level& operator=(const level& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//キャストオペレータ
		operator int() const { return static_cast<int>(m_value); }//値（レベル）
		operator value_t() const { return m_value; }//値（レベル）
		operator const char*() const { return m_name; }//名前
	public:
		//アクセッサ
		value_t value() const { return m_value; }//値（レベル）取得
		const char* name() const { return m_name; }//名前取得
		static value_t calcValueAsOutput(const value_t value){ return calcAsOutput(value); }//出力レベル計算
		value_t valueAsOutput() const { return calcAsOutput(m_value); }//出力レベル取得
		bool forLog() const { return m_forLog; }//ログレベルとして使用可能か？
		bool forNotice() const { return m_forNotice; }//画面通知レベルとして使用可能か？
		bool forMask() const { return m_forMask; }//出力レベルマスクとして使用可能か？
		color getColor() const { return std::move(changeColor(true)); }//カラー取得
		color getColorForNotice() const { return std::move(changeColorForNotice(true)); }//カラー取得（画面通知用）
	public:
		//メソッド
		//カラー変更
		//※戻り値受け取り必須
		//　戻り値を受け取らないとすぐにデストラクタが実行されて元のカラーに戻るので実際に反映されない
		color changeColor(const bool is_only_get = false) const
		{
			return std::move(color(color::stdOut, m_foreColor, m_backColor, !is_only_get));
		}
		//カラー変更（画面通知用）
		//※戻り値受け取り必須
		//　戻り値を受け取らないとすぐにデストラクタが実行されて元のカラーに戻るので実際に反映されない
		color changeColorForNotice(const bool is_only_get = false) const
		{
			return std::move(color(color::stdErr, m_foreColorForNotice, m_backColorForNotice, !is_only_get));
		}
		//コンテナ要素を取得（ショートカット用）
		static const level& get(const value_t value){ return container::get(value); }
		//前のレベルを取得
		const level& prev() const
		{
			if (valueAsOutput() <= OUTPUT_LEVEL_MIN || valueAsOutput() > OUTPUT_LEVEL_MAX || !(m_forLog || m_forNotice))
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcAsValue(calcAsOutput(m_value) - 1)];
		}
		//次のレベルを取得
		const level& next() const
		{
			if (valueAsOutput() < OUTPUT_LEVEL_MIN || valueAsOutput() >= OUTPUT_LEVEL_MAX || !(m_forLog || m_forNotice))
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcAsValue(calcAsOutput(m_value) + 1)];
		}
	public:
		//デフォルトコンストラクタ
		level() :
			m_name(nullptr),
			m_value(UCHAR_MAX),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false),
			m_foreColor(color::through),
			m_backColor(color::through),
			m_foreColorForNotice(color::through),
			m_backColorForNotice(color::through)
		{
			container::initializeOnce();//コンテナ初期化（一回限り）
		}
		//コピーコンストラクタ
		level(const level& src) :
			m_name(src.m_name),
			m_value(src.m_value),
			m_forLog(src.m_forLog),
			m_forNotice(src.m_forNotice),
			m_forMask(src.m_forMask),
			m_foreColor(src.m_foreColor),
			m_backColor(src.m_backColor),
			m_foreColorForNotice(src.m_foreColorForNotice),
			m_backColorForNotice(src.m_backColorForNotice)
		{
		}
		//コンストラクタ
		level(const value_t value, const char* name, const bool for_log, const bool for_notice, const bool for_mask, const color::color_t fore_color, const color::color_t back_color, const color::color_t fore_color_for_notice, const color::color_t back_color_for_notice) :
			m_name(name),
			m_value(value),
			m_forLog(for_log),
			m_forNotice(for_notice),
			m_forMask(for_mask),
			m_foreColor(fore_color),
			m_backColor(back_color),
			m_foreColorForNotice(fore_color_for_notice),
			m_backColorForNotice(back_color_for_notice)
		{
			assert(value >= BEGIN && value <= END);
			container::set(m_value, *this);//コンテナに登録
		}
		level(const value_t value) :
			m_name(nullptr),
			m_value(value),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false),
			m_foreColor(color::through),
			m_backColor(color::through),
			m_foreColorForNotice(color::through),
			m_backColorForNotice(color::through)
		{
			assert(value >= BEGIN && value <= END);
			*this = container::get(m_value);//コンテナから取得して自身にコピー
		}
		//デストラクタ
		~level()
		{}
	private:
		const char* m_name;//名前
		const value_t m_value;//値（レベル）
		const bool m_forLog;//ログ出力レベルとして使用可能か？
		const bool m_forNotice;//画面通知レベルとして使用可能か？
		const bool m_forMask;//出力レベルマスクとして使用可能か？
		const color::color_t m_foreColor;//カラー：前面
		const color::color_t m_backColor;//カラー：背面
		const color::color_t m_foreColorForNotice;//カラー：前面（画面通知用）
		const color::color_t m_backColorForNotice;//カラー：背面（画面通知用）
	private:
		//マクロ消去
#ifndef ENABLE_CONSTEXPR
#undef calcAsOutput
#undef calcAsValue
#endif//ENABLE_CONSTEXPR
	};
	//----------------------------------------
	//レベル定義用テンプレートクラス：通常レベル用
	template<unsigned char V, bool for_log, bool for_notice, color::color_t fore_color, color::color_t back_color, color::color_t fore_color_for_notice, color::color_t back_color_for_notice>
	class level_normal : public level
	{
	public:
		//定数
		static const value_t VALUE = V;//値（レベル）
		static_assert(VALUE >= NORMAL_MIN && VALUE <= NORMAL_MAX, "out of range of level");//値の範囲チェック
		static const bool FOR_LOG = for_log;//ログレベルとして使用可能か？
		static const bool FOR_NOTICE = for_notice;//画面通知レベルとして使用可能か？
		static const bool FOR_MASK = true;//出力レベルマスクとして使用可能か？
		static const color::color_t FORE_COLOR = fore_color;//カラー：前面
		static const color::color_t BACK_COLOR = back_color;//カラー：背面
		static const color::color_t FORE_COLOR_FOR_NOTICE = fore_color_for_notice;//カラー：前面（画面通知用）
		static const color::color_t BACK_COLOR_FOR_NOTICE = back_color_for_notice;//カラー：背面（画面通知用）
	public:
		//コンストラクタ
		level_normal(const char* name) :
			level(VALUE, name, FOR_LOG, FOR_NOTICE, FOR_MASK, FORE_COLOR, BACK_COLOR, FORE_COLOR_FOR_NOTICE, BACK_COLOR_FOR_NOTICE)
		{}
	};
	//----------------------------------------
	//レベル定義用テンプレートクラス：特殊レベル用
	template<unsigned char V>
	class level_special : public level
	{
	public:
		//定数
		static const value_t VALUE = V;//値（レベル）
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of level");//値の範囲チェック
		static const bool FOR_LOG = false;//ログレベルとして使用可能か？
		static const bool FOR_NOTICE = false;//画面通知レベルとして使用可能か？
		static const bool FOR_MASK = true;//出力レベルマスクとして使用可能か？
	public:
		//コンストラクタ
		level_special(const char* name) :
			level(VALUE, name, FOR_LOG, FOR_NOTICE, FOR_MASK, color::through, color::through, color::through, color::through)
		{}
	};
	//----------------------------------------
	//レベル定義クラス：終端用
	class level_end : public level
	{
	public:
		//定数
		static const value_t VALUE = END;//値（レベル）
		static const bool FOR_LOG = false;//ログレベルとして使用可能か？
		static const bool FOR_NOTICE = false;//画面通知レベルとして使用可能か？
		static const bool FOR_MASK = false;//出力レベルマスクとして使用可能か？
	public:
		//コンストラクタ
		level_end() :
			level(VALUE, "(END)", FOR_LOG, FOR_NOTICE, FOR_MASK, color::through, color::through, color::through, color::through)
		{}
	};
	//----------------------------------------
	//レベル定数
#define define_normalLevel(print_level, sub) (level::NORMAL_MIN + print_level * 2 + sub)
#define define_specialLevel(value) (level::SPECIAL_MIN + value)
	enum levelEnum : level::value_t
	{
		asNormal = define_normalLevel(1, 0),//通常メッセージ
		asVerbose = define_normalLevel(0, 0),//冗長メッセージ
		asDetail = define_normalLevel(0, 1),//詳細メッセージ
		asImportant = define_normalLevel(2, 0),//重要メッセージ
		asWarning = define_normalLevel(3, 0),//警告メッセージ
		asCritical = define_normalLevel(4, 0),//重大メッセージ
		asAbsolute = define_normalLevel(5, 0),//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
		//以下、ログレベル／画面通知レベル変更用
		asSilent = define_specialLevel(0),//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
		asSilentAbsolutely = define_specialLevel(1),//絶対静寂（全てのメッセージを出力しない）
	};
	//----------------------------------------
	//レベル定義
#define declare_normalLevel(value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice) struct level_##value : public level_normal<value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice>{ level_##value () :level_normal<value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice>(#value){} }
#define declare_specialLevel(value) struct level_##value : public level_special<value>{ level_##value () :level_special<value>(#value){} }
	//※以下、ヘッダーで公開する必要なし
	declare_normalLevel(asNormal, true, true, color::reset, color::reset, color::black, color::iWhite);//通常メッセージ
	declare_normalLevel(asVerbose, true, false, color::iBlack, color::black, color::iBlack, color::iWhite);//冗長メッセージ
	declare_normalLevel(asDetail, true, false, color::iBlack, color::black, color::iBlack, color::iWhite);//詳細メッセージ
	declare_normalLevel(asImportant, true, true, color::iBlue, color::black, color::iBlue, color::iWhite);//重要メッセージ
	declare_normalLevel(asWarning, true, true, color::iMagenta, color::black, color::black, color::iMagenta);//警告メッセージ
	declare_normalLevel(asCritical, true, true, color::iRed, color::black, color::iYellow, color::iRed);//重大メッセージ
	declare_normalLevel(asAbsolute, true, false, color::through, color::through, color::through, color::through);//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
	//以下、ログレベル／画面通知レベル変更用
	declare_specialLevel(asSilent);//静寂（絶対メッセ―ジ以外出力しない）
	declare_specialLevel(asSilentAbsolutely);//絶対静寂（全てのメッセージを出力しない）

	//----------------------------------------
	//レベルコンテナの静的変数をインスタンス化
	bool level::container::m_isInitialized = false;
	level* level::container::m_poolPtr = nullptr;
	level::byte level::container::m_pool[(POOL_NUM)* sizeof(level)];
	std::bitset<level::POOL_NUM> level::container::m_isAlreadyPool;
	//----------------------------------------
	//レベルコンテナ初期化（一回限り）
	void level::container::initializeOnce()
	{
		//初期化済みチェック
		if (m_isInitialized)
			return;
		//静的変数を初期化
		m_isInitialized = true;
		m_isAlreadyPool.reset();
		memset(m_pool, 0, sizeof(m_pool));
		m_poolPtr = reinterpret_cast<level*>(m_pool);
		//要素を初期化
		for (level::value_t value = 0; value < level::NUM; ++value)
		{
			level(value, "(undefined)", false, false, false, color::through, color::through, color::through, color::through);
			m_isAlreadyPool[value] = false;
		}
		//割り当て済みレベルを設定（コンストラクタで要素を登録）
		level_asNormal();//通常メッセージ
		level_asVerbose();//冗長メッセージ
		level_asDetail();//詳細メッセージ
		level_asImportant();//重要メッセージ
		level_asWarning();//警告メッセージ
		level_asCritical();//重大メッセージ
		level_asAbsolute();//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
		level_asSilent();//静寂（絶対メッセ―ジ以外出力しない）
		level_asSilentAbsolutely();//絶対静寂（全てのメッセージを出力しない）
		level_end();//終端
	}
	//----------------------------------------
	//レベル用変数
	static level s_levelForInitialize;//初期化処理実行のためのインスタンス
	//----------------------------------------
	//レベルコンテナ列挙
	void printLevelAll()
	{
		for (auto& obj : level::container())//C++11スタイル
		//for (auto ite = level::container::begin(); ite != level::container::end(); ++ite)//旧来のスタイル
		//for (auto ite = level::container::cbegin(); ite != level::container::cend(); ++ite)//旧来のスタイル
		{
			//const level& obj = ite;//イテレータを変換（イテレータのままでもアロー演算子で直接値操作可能）
			color col(obj.changeColor());
			fprintf(stdout, "level=%d, name=\"%s\", valueAsOutput=%d, forLog=%d, forNotice=%d, forMask=%d\n", obj.value(), obj.name(), obj.valueAsOutput(), obj.forLog(), obj.forNotice(), obj.forMask());
			auto& prev = obj.prev();
			auto& next = obj.next();
			fprintf(stdout, "           prev=%s(%d)\n", prev.name(), prev.value());
			fprintf(stdout, "           next=%s(%d)\n", next.name(), next.value());
		}
	}

	//----------------------------------------
	//カテゴリクラス
	class category
	{
	public:
		//型
		typedef unsigned char value_t;//値（カテゴリ）
		typedef unsigned char byte;//バッファ用
	public:
		//定数
		static const value_t NORMAL_NUM = 64;//通常カテゴリ数
		static const value_t ASSIGNED_NUM = 8;//割り当て済みカテゴリ数
		static const value_t RESERVED_NUM = NORMAL_NUM - ASSIGNED_NUM;//予約カテゴリ数
		static const value_t SPECIAL_NUM = 3;//特殊カテゴリ数
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;//カテゴリ総数
		static const value_t MIN = 0;//カテゴリ最小値
		static const value_t MAX = NUM - 1;//カテゴリ最大値
		static const value_t NORMAL_MIN = MIN;//通常カテゴリ最小値
		static const value_t NORMAL_MAX = NORMAL_MIN + NORMAL_NUM - 1;//通常カテゴリ最大値
		static const value_t ASSIGNED_MIN = NORMAL_MIN;//割り当て済みカテゴリ最小値
		static const value_t ASSIGNED_MAX = ASSIGNED_MIN + ASSIGNED_NUM - 1;//割り当て済みカテゴリ最大値
		static const value_t RESERVED_MIN = ASSIGNED_MAX + 1;//予約カテゴリ最小値
		static const value_t RESERVED_MAX = RESERVED_MIN + RESERVED_NUM - 1;//予約カテゴリ最大値
		static const value_t SPECIAL_MIN = NORMAL_MAX + 1;//特殊カテゴリ最小値
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//特殊カテゴリ最大値
		static const value_t BEGIN = MIN;//カテゴリ開始値（イテレータ用）
		static const value_t END = NUM;//カテゴリ終端値（イテレータ用）
		static const value_t POOL_NUM = NUM + 1;//カテゴリ記録数
		static_assert(NORMAL_MAX == RESERVED_MAX, "invalid category numbers.");//定数チェック
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");//定数チェック
	public:
		//型
		//--------------------
		//イテレータ
		class iterator : public std::iterator<std::bidirectional_iterator_tag, category>//双方向イテレータとして実装
		{
		public:
			//オペレータ
			const category* operator->() const { return &container::get(m_value); }
			const category& operator*() const { return container::get(m_value); }
			bool operator==(const iterator rhs) const { return m_value == rhs.m_value; }
			bool operator!=(const iterator rhs) const { return m_value != rhs.m_value; }
			const category& operator++() const { return m_value >= container::endValue() ? container::getEnd() : container::get(++m_value); }
			const category& operator++(int) const { return m_value >= container::endValue() ? container::getEnd() : container::get(m_value++); }
			const category& operator--() const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getEnd(); } return container::get(--m_value); }
			const category& operator--(int) const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getBegin(); } return container::get(m_value--); }
		public:
			//キャストオペレータ
			operator const category&() const { return container::get(m_value); }//値（カテゴリ）
		public:
			//コンストラクタ
			iterator(const value_t value) :
				m_value(value)
			{}
			iterator(const value_t value, int) :
				m_value(container::endValue())
			{}
			iterator(const category& obj) :
				m_value(obj.value())
			{}
			iterator(const category& obj, int) :
				m_value(container::endValue())
			{}
			iterator() :
				m_value(container::endValue())
			{}
			//デストラクタ
			~iterator()
			{}
		private:
			//フィールド
			value_t mutable m_value;//値（カテゴリ）
		};
		//--------------------
		//constイテレータ
		typedef const iterator const_iterator;
		//--------------------
		//コンテナ（イテレータ用）
		class container
		{
			friend class category;
		public:
			//メソッド
			static const value_t beginValue(){ return BEGIN; }//開始値取得
			static const value_t endValue(){ return END; }//終端値取得
			static const category& get(const value_t value){ return m_poolPtr[value]; }//要素を取得
			static const category& getBegin(){ return m_poolPtr[beginValue()]; }//開始要素を取得
			static const category& getEnd(){ return m_poolPtr[endValue()]; }//終端要素を取得
		private:
			static void set(const value_t value, const category& obj)//要素を更新
			{
				if (!container::m_isAlreadyPool[value])
				{
					container::m_poolPtr[value] = obj;
					container::m_isAlreadyPool[value] = true;
				}
			}
		public:
			static const iterator begin(){ return iterator(beginValue()); }//開始イテレータを取得
			static const iterator end()	{ return iterator(endValue()); }//終端イテレータを取得
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//開始constイテレータを取得
			static const_iterator cend(){ return const_iterator(endValue()); }//終端constイテレータを取得
			//※reverse_iterator非対応
			//メソッド
			//初期化（一回限り）
			static void initializeOnce();
		private:
			//フィールド
			static bool m_isInitialized;//初期化済み
			static category* m_poolPtr;//要素のプール（ポインタ）
			static byte m_pool[];//要素のプール（バッファ）※バッファとポインタを分けているのは、コンストラクタの実行を防止するため
			static std::bitset<POOL_NUM> m_isAlreadyPool;//要素の初期化済みフラグ
		};
	public:
		//オペレータ
		bool operator ==(const category& rhs) const { return m_value == rhs.m_value; }
		bool operator !=(const category& rhs) const { return m_value != rhs.m_value; }
	private:
		//コピーオペレータ
		category& operator=(const category& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//キャストオペレータ
		operator int() const { return static_cast<int>(m_value); }//値（カテゴリ）
		operator value_t() const { return m_value; }//値（カテゴリ）
		operator const char*() const { return m_name; }//名前
	public:
		//アクセッサ
		value_t value() const { return m_value; }//値（カテゴリ）取得
		const char* name() const { return m_name; }//名前取得
		bool isAssigned() const { return m_isAssigned; }//割り当て済みカテゴリか？
		bool isReserved() const { return !m_isAssigned; }//予約カテゴリか？
		bool forLog() const { return m_forLog; }//ログ出力可能か？
		bool forNotice() const { return m_forNotice; }//画面通知可能か？
		bool forMask() const { return m_forMask; }//出力レベルマスク可能か？
	public:
		//メソッド
		//コンテナ要素を取得（ショートカット用）
		static const category& get(const value_t value){ return container::get(value); }
	public:
		//デフォルトコンストラクタ
		category() :
			m_name(nullptr),
			m_value(UCHAR_MAX),
			m_isAssigned(false),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false)
		{
			container::initializeOnce();//コンテナ初期化（一回限り）
		}
		//コピーコンストラクタ
		category(const category& src) :
			m_name(src.m_name),
			m_value(src.m_value),
			m_isAssigned(src.m_isAssigned),
			m_forLog(src.m_forLog),
			m_forNotice(src.m_forNotice),
			m_forMask(src.m_forMask)
		{
		}
		//コンストラクタ
		category(const value_t value, const char* name, const bool is_assigned, const bool for_log, const bool for_notice, const bool for_mask) :
			m_name(name),
			m_value(value),
			m_isAssigned(is_assigned),
			m_forLog(for_log),
			m_forNotice(for_notice),
			m_forMask(for_mask)
		{
			assert(value >= BEGIN && value <= END);
			container::set(m_value, *this);//コンテナに登録
		}
		category(const value_t value) :
			m_name(nullptr),
			m_value(value),
			m_isAssigned(false),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false)
		{
			assert(value >= BEGIN && value <= END);
			*this = container::get(m_value);//コンテナから取得して自身にコピー
		}
		//デストラクタ
		~category()
		{}
	private:
		const char* m_name;//名前
		const value_t m_value;//値（カテゴリ）
		const bool m_isAssigned;//割り当て済みカテゴリか？
		const bool m_forLog;//ログ出力可能か？
		const bool m_forNotice;//画面通知可能か？
		const bool m_forMask;//出力レベルマスク可能か？
	};
	//----------------------------------------
	//カテゴリ定義用テンプレートクラス：割り当て済みカテゴリ用
	template<unsigned char V, bool for_log, bool for_notice>
	class category_assigned : public category
	{
	public:
		//定数
		static const value_t VALUE = V;//値（カテゴリ）
		static_assert(VALUE >= ASSIGNED_MIN && VALUE <= ASSIGNED_MAX, "out of range of category");//値の範囲チェック
		static const bool IS_ASSIGNED = true;//割り当て済みカテゴリか？
		static const bool FOR_LOG = for_log;//ログ出力可能か？
		static const bool FOR_NOTICE = for_notice;//画面通知可能か？
		static const bool FOR_MASK = true;//出力レベルマスク可能か？
	public:
		//コンストラクタ
		category_assigned(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//カテゴリ定義用テンプレートクラス：予約カテゴリ用
	template<unsigned char V, bool for_log, bool for_notice>
	class category_reserved: public category
	{
	public:
		//定数
		static const value_t VALUE = V;//値（カテゴリ）
		static_assert(VALUE >= RESERVED_MIN && VALUE <= RESERVED_MAX, "out of range of category");//値の範囲チェック
		static const bool IS_ASSIGNED = false;//割り当て済みカテゴリか？
		static const bool FOR_LOG = for_log;//ログ出力可能か？
		static const bool FOR_NOTICE = for_notice;//画面通知可能か？
		static const bool FOR_MASK = true;//出力レベルマスク可能か？
	public:
		//コンストラクタ
		category_reserved(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//カテゴリ定義用テンプレートクラス：特殊カテゴリ用
	template<unsigned char V, bool for_log, bool for_notice, bool for_mask>
	class category_special : public category
	{
	public:
		//定数
		static const value_t VALUE = V;//値（カテゴリ）
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of category");//値の範囲チェック
		static const bool IS_ASSIGNED = true;//割り当て済みカテゴリか？
		static const bool FOR_LOG = for_log;//ログ出力可能か？
		static const bool FOR_NOTICE = for_notice;//画面通知可能か？
		static const bool FOR_MASK = for_mask;//出力レベルマスク可能か？
	public:
		//コンストラクタ
		category_special(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//カテゴリ定義クラス：終端用
	class category_end : public category
	{
	public:
		//定数
		static const value_t VALUE = END;//値（カテゴリ）
		static const bool IS_ASSIGNED = true;//割り当て済みカテゴリか？
		static const bool FOR_LOG = false;//ログ出力可能か？
		static const bool FOR_NOTICE = false;//画面通知可能か？
		static const bool FOR_MASK = false;//出力レベルマスク可能か？
	public:
		//コンストラクタ
		category_end() :
			category(VALUE, "(END)", IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//カテゴリ定数
#define define_assignedCategory(value) (category::ASSIGNED_MIN + value)
#define define_revervedCategory(value) (category::RESERVED_MIN + value)
#define define_specialCategory(value) (category::SPECIAL_MIN + value)
	enum categoryEnum : category::value_t
	{
		forAny = define_assignedCategory(0),//なんでも（カテゴリなし）
		forLogic = define_assignedCategory(1),//プログラム関係
		forResource = define_assignedCategory(2),//リソース関係
		for3D = define_assignedCategory(3),//3Dグラフィックス関係
		for2D = define_assignedCategory(4),//2Dグラフィックス関係
		forSound = define_assignedCategory(5),//サウンド関係
		forScript = define_assignedCategory(6),//スクリプト関係
		forGameData = define_assignedCategory(7),//ゲームデータ関係
		//ログレベル／画面通知レベル変更用
		forEvery = define_specialCategory(0),//全部まとめて変更
		//特殊なカテゴリ（プリント時専用）
		forCallPoint = define_specialCategory(1),//直近のコールポイントのカテゴリに合わせる（なければforAny扱い）
		forCriticalCallPoint = define_specialCategory(2),//直近の重大コールポイントのカテゴリに合わせる（なければforAny扱い）
	};
	//----------------------------------------
	//カテゴリ定義
#define declare_assignedCategory(value, for_log, for_notice) struct category_##value : public category_assigned<value, for_log, for_notice>{ category_##value () :category_assigned<value, for_log, for_notice>(#value){} }
#define declare_reservedCategory(value, for_log, for_notice) struct category_##value : public category_reserved<value, for_log, for_notice>{ category_##value () :category_reserved<value, for_log, for_notice>(#value){} }
#define declare_specialCategory(value, for_log, for_notice, for_mask) struct category_##value : public category_special<value, for_log, for_notice, for_mask>{ category_##value () :category_special<value, for_log, for_notice, for_mask>(#value){} }
	//※以下、ヘッダーで公開する必要なし
	declare_assignedCategory(forAny, true, true);//なんでも（カテゴリなし）
	declare_assignedCategory(forLogic, true, true);//プログラム関係
	declare_assignedCategory(forResource, true, true);//リソース関係
	declare_assignedCategory(for3D, true, true);//3Dグラフィックス関係
	declare_assignedCategory(for2D, true, true);//2Dグラフィックス関係
	declare_assignedCategory(forSound, true, true);//サウンド関係
	declare_assignedCategory(forScript, true, true);//スクリプト関係
	declare_assignedCategory(forGameData, true, true);//ゲームデータ関係
	//ログレベル／画面通知レベル変更用
	declare_specialCategory(forEvery, false, false, true);//全部まとめて変更
	//特殊なカテゴリ（プリント時専用）
	declare_specialCategory(forCallPoint, true, true, false);//直近のコールポイントのカテゴリに合わせる（なければforAny扱い）
	declare_specialCategory(forCriticalCallPoint, true, true, false);//直近の重大コールポイントのカテゴリに合わせる（なければforAny扱い）

	//----------------------------------------
	//カテゴリコンテナの静的変数をインスタンス化
	bool category::container::m_isInitialized = false;
	category* category::container::m_poolPtr = nullptr;
	category::byte category::container::m_pool[(POOL_NUM)* sizeof(category)];
	std::bitset<category::POOL_NUM> category::container::m_isAlreadyPool;
	//----------------------------------------
	//カテゴリコンテナ初期化（一回限り）
	void category::container::initializeOnce()
	{
		//初期化済みチェック
		if (m_isInitialized)
			return;
		//静的変数を初期化
		m_isInitialized = true;
		m_isAlreadyPool.reset();
		memset(m_pool, 0, sizeof(m_pool));
		m_poolPtr = reinterpret_cast<category*>(m_pool);
		//要素を初期化
		for (category::value_t value = 0; value < category::NUM; ++value)
		{
			category(value, "(undefined)", false, false, false, false);
			m_isAlreadyPool[value] = false;
		}
		//割り当て済みカテゴリを設定（コンストラクタで要素を登録）
		category_forAny();//なんでも（カテゴリなし）
		category_forLogic();//プログラム関係
		category_forResource();//リソース関係
		category_for3D();//3Dグラフィックス関係
		category_for2D();//2Dグラフィックス関係
		category_forSound();//サウンド関係
		category_forScript();//スクリプト関係
		category_forGameData();//ゲームデータ関係
		//ログレベル／画面通知レベル変更用
		category_forEvery();//全部まとめて変更
		//特殊なカテゴリ（プリント時専用）
		category_forCallPoint();//直近のコールポイントのカテゴリに合わせる（なければforAny扱い）
		category_forCriticalCallPoint();//直近の重大コールポイントのカテゴリに合わせる（なければforAny扱い）
		category_end();//終端
	}
	//----------------------------------------
	//カテゴリ用変数
	static category s_categoryForInitialize;//初期化処理実行のためのインスタンス
	//----------------------------------------
	//カテゴリコンテナ列挙
	void printCategoryAll()
	{
		for (auto& obj : category::container())//C++11スタイル
		//for (auto ite = category::container::begin(); ite != category::container::end(); ++ite)//旧来のスタイル
		//for (auto ite = category::container::cbegin(); ite != category::container::cend(); ++ite)//旧来のスタイル
		{
			//const category& obj = ite;//イテレータを変換（イテレータのままでもアロー演算子で直接値操作可能）
			printf("category=%d, name=\"%s\", isAssigned=%d, isReserved=%d, forLog=%d, forNotice=%d, forMask=%d\n", obj.value(), obj.name(), obj.isAssigned(), obj.isReserved(), obj.forLog(), obj.forNotice(), obj.forMask());
		}
	}

	//----------------------------------------
	//メッセージ固定バッファ
	class messageBuffer
	{
	public:
		//定数
		static const std::size_t BUFFER_SIZE = 2048;//1個あたりのバッファサイズ
		static const std::size_t BUFFER_NUM = 16;//バッファの個数
	public:
		//型
		typedef CPoolAllocatorWithBuff<BUFFER_SIZE, BUFFER_NUM> pool_t;//プールバッファ型
	public:
		//メッセージ用固定バッファ取得
		//※成功するまで（他のスレッドが解放するまで）リトライする
		void* assignBuffer()
		{
			void* p = nullptr;
			while (1)
			{
				p = m_pool.alloc(BUFFER_SIZE);
				if (p)
					break;
				std::this_thread::sleep_for(std::chrono::milliseconds(0));
			}
			return p;
		}
		//メッセージバッファ返却
		void releaseBuffer(void* p)
		{
			m_pool.free(p);
		}
	public:
		//コンストラクタ
		messageBuffer()
		{}
		//デストラクタ
		~messageBuffer()
		{}
	private:
		static pool_t m_pool;
	};
	//メッセージ固定バッファ用静的変数インスタンス化
	messageBuffer::pool_t messageBuffer::m_pool;

	//----------------------------------------
	//メッセージ表示属性
	enum msgAttrEnum : unsigned char//属性
	{
		withSeqNo = 0x01,//シーケンス番号表示
		withLevel = 0x02,//レベル名表示
		withCategory = 0x04,//カテゴリ名表示
		withoutColor = 0x08,//カラーなし
	};
	//----------------------------------------
	//メッセージ操作
	enum msgCtrlEnum :unsigned char
	{
		simplePrint = 0x00,//シンプル
		withFuncName = 0x01,//関数名を共に表示
		withFileName = 0x02,//ファイル名を共に表示
	};
	//----------------------------------------
	//メッセージクラス
	class message
	{
	public:
		//型
		typedef char buff_t;//メッセージバッファ用
		typedef unsigned char attr_t;//属性型
		typedef unsigned char control_t;//メッセージ操作型
	public:
		//定数
		static const attr_t DEFAULT_ATTR = withLevel | withCategory;//デフォルト表示属性
		static const level::value_t DEFAULT_LOG_LEVEL = asNormal;//デフォルトログレベル
		static const level::value_t DEFAULT_NOTOICE_LEVEL = asCritical;//デフォルト画面通知レベル
	public:
		//アクセッサ
		level::value_t getLevel() const { return m_level; }//レベル取得
		category::value_t getCategory() const { return m_category; }//カテゴリ取得
		const char* getName() const { return m_name; }//処理名取得
		const char* getSrcFileName() const { return getFileName(m_srcFileName); }//ソースファイル名取得
		const char* getFuncName() const { return m_funcName; }//関数名取得
		bool hasPushed() const { return m_hasPushed; }//コールポイントスタックにプッシュ済み
		bool attrHasChanged() const { return m_attrHasChanged; }//一時表示属性変更済み
		bool logLevelHasChanged() const { return m_logLevelHasChanged; }//一時ログレベル変更済み
		bool noticeLevelHasChanged() const { return m_noticeLevelHasChanged; }//一時画面通知レベル変更済み
	public:
		//メソッド
		//初期化（一回限り）
		static void initializeOnce();
		//適切なカテゴリに調整
		//※forCallPoint, forCriticalCallPointに基づく変換
		static category::value_t adjustProperCategory(const category::value_t category_)
		{
			if (category_ == forCallPoint)//直前のコールポイントのカテゴリ
			{
				const message* call_point = getLastCallPoint();
				if (call_point)
					return call_point->getCategory();
				return forAny;//コールポイントがなければ forAny 扱い
			}
			else if (category_ == forCriticalCallPoint)//直近のクリティカルコールポイントのカテゴリ
			{
				const message* call_point = getLastCriticalCallPoint();
				if (call_point)
					return call_point->getCategory();
				return forAny;//コールポイントがなければ forAny 扱い
			}
			return category_;
		}
		//現在の表示属性を取得
		static attr_t getAttrG(){ return m_attrG; }
		//【一時表示属性版】
		attr_t getAttr() const { return m_attr; }
		//【コールポイント版】
		static attr_t getAttrG_CP()
		{
			message* call_point = getLastCallPointWithAttrHasChanged();
			if (!call_point)
				return getAttrG();//コールポイント無かったら通常の表示属性
			return call_point->getAttr();
		}
		//【一時表示属性のコールポイント版】
		level::value_t getAttr_CP()
		{
			return m_attrHasChanged ? getAttr() : getAttrG_CP();
		}
		//現在の表示属性を変更
		//static void setAttrG(const attr_t attr){ m_attrG = attr; }//禁止
		static attr_t addAttrG(const attr_t attr){ m_attrG |= attr; return m_attrG; }
		static attr_t delAttrG(const attr_t attr){ m_attrG &= ~attr; return m_attrG; }
		//【一時表示属性版】
		//void setAttr(const attr_t attr){ copyAttr(); m_attr = attr; }//禁止
		attr_t addAttr(const attr_t attr){ copyAttr(); m_attr |= attr; return m_attr; }
		attr_t delAttr(const attr_t attr){ copyAttr(); m_attr &= ~attr; return m_attr; }
		//現在の表示属性をリセット
		//※デフォルトに戻す
		static void resetAttrG(){ m_attrG = DEFAULT_ATTR; }
		//【一時表示属性版】
		void resetAttr(){ copyAttr(); m_attr = DEFAULT_ATTR; }
		//現在の表示属性を一時表示属性にコピー
		void copyAttr()
		{
			if (m_attrHasChanged)
				return;
			message* call_point = getLastCallPointWithAttrHasChanged();
			m_attrHasChanged = true;
			if (m_hasPushed)
				++m_attrHasChangedG;
			if (call_point)
				m_attr = call_point->m_attr;//一時表示属性
			else
				m_attr = m_attrG;//一時表示属性
		}
		//一時表示属性のコピー状態を解除
		//※本来の表示属性に戻す
		void releaseAttr()
		{
			if (!m_attrHasChanged)
				return;
			m_attrHasChanged = false;
			if (m_hasPushed)
				--m_attrHasChangedG;
		}
		//現在のログレベルを取得
		static level::value_t getLogLevelG(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			return m_logLevelG[category_];
		}
		//【コールポイント版】
		static level::value_t getLogLevelG_CP(const category::value_t category_)
		{
			message* call_point = getLastCallPointWithLogLevelHasChanged();
			if (!call_point)
				return getLogLevelG(category_);//コールポイント無かったら通常のログレベル
			return call_point->getLogLevel(category_);
		}
		//【一時ログレベルの有効判定】
		//※本来のレベルより低い一時ログレベルは扱えない
		bool isValidTempLogLevel(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			return m_logLevelHasChanged && level::calcValueAsOutput(m_logLevelG[category_]) <= level::calcValueAsOutput(m_logLevel[category_]);
		}
		//【一時ログレベル版】
		level::value_t getLogLevel(const category::value_t category_)
		{
			return isValidTempLogLevel(category_) ? m_logLevel[category_] : m_logLevelG[category_];
		}
		//【一時ログレベルのコールポイント版】
		level::value_t getLogLevel_CP(const category::value_t category_)
		{
			return isValidTempLogLevel(category_) ? m_logLevel[category_] : getLogLevelG_CP(category_);
		}
		//現在のログレベルを変更
		//※指定の値以上のレベルのメッセージのみをログ出力する
		//※変更前のログレベルを返す（forEvery指定時はforAnyのログレベルを返す）
		static level::value_t setLogLevelG(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			if (category_ == forEvery)
			{
				const level::value_t prev = m_logLevelG[forAny];
				for (level::value_t& value : m_logLevelG)
					value = level_;
				return prev;
			}
			assert(o_category.forLog() == true);
			const level::value_t prev = m_logLevelG[category_];
			m_logLevelG[category_] = level_;
			return prev;
		}
		//【一時ログレベル版】
		level::value_t setLogLevel(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			copyLogLevel();//更新前に現在のログレベルをコピー
			if (category_ == forEvery)
			{
				const level::value_t prev = m_logLevel[forAny];
				for (int category_tmp = category::NORMAL_MIN; category_tmp <= category::NORMAL_MAX; ++category_tmp)
				{
					m_logLevel[category_tmp] =
						level::calcValueAsOutput(m_logLevelG[category_tmp]) > level::calcValueAsOutput(level_) ?
							m_logLevelG[category_tmp] ://本来のレベルより低くすることはできない
							level_;
				}
				return prev;
			}
			assert(o_category.forLog() == true);
			const level::value_t prev = m_logLevel[category_];
			m_logLevel[category_] =
				level::calcValueAsOutput(m_logLevelG[category_]) > level::calcValueAsOutput(level_) ?
					m_logLevelG[category_] ://本来のレベルより低くすることはできない
					level_;
			return prev;
		}
		//現在のログレベルをリセット
		//※デフォルトに戻す
		static void resetLogLevelG(const category::value_t category_)
		{
			setLogLevelG(DEFAULT_LOG_LEVEL, category_);
		}
		//【一時ログレベル版】
		void resetLogLevel(const category::value_t category_)
		{
			setLogLevel(DEFAULT_LOG_LEVEL, category_);
		}
		//現在のログレベルを全てリセット
		//※デフォルトに戻す
		static void resetLogLevelAllG()
		{
			//resetLogLevelG(forEvery);//初期化処理でも呼び出されるので、共通処理を使わず単純に更新
			for (level::value_t& value : m_logLevelG)
				value = DEFAULT_LOG_LEVEL;
		}
		//【一時ログレベル版】
		void resetLogLevelAll()
		{
			resetLogLevel(forEvery);
		}
		//ログレベルを一時ログレベルにコピー
		void copyLogLevel()
		{
			if (m_logLevelHasChanged)
				return;
			message* call_point = getLastCallPointWithLogLevelHasChanged();
			m_logLevelHasChanged = true;
			if (m_hasPushed)
				++m_logLevelHasChangedG;
			if (call_point)
				memcpy(m_logLevel, call_point->m_logLevel, sizeof(m_logLevel));//一時ログレベル
			else
				memcpy(m_logLevel, m_logLevelG, sizeof(m_logLevel));//一時ログレベル
		}
		//一時ログレベルのコピー状態を解除
		//※本来のログレベルに戻す
		void releaseLogLevel()
		{
			if (!m_logLevelHasChanged)
				return;
			m_logLevelHasChanged = false;
			if (m_hasPushed)
				--m_logLevelHasChangedG;
		}
		//現在の画面通知レベルを取得
		static level::value_t getNoticeLevelG(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			return m_noticeLevelG[category_];
		}
		//【コールポイント版】
		static level::value_t getNoticeLevelG_CP(const category::value_t category_)
		{
			message* call_point = getLastCallPointWithNoticeLevelHasChanged();
			if (!call_point)
				return getNoticeLevelG(category_);//コールポイント無かったら通常の画面通知レベル
			return call_point->getNoticeLevel(category_);
		}
		//【一時画面通知レベルの有効判定】
		//※本来のレベルより低い一時画面通知レベルは扱えない
		bool isValidTempNoticeLevel(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			return m_noticeLevelHasChanged && level::calcValueAsOutput(m_noticeLevelG[category_]) <= level::calcValueAsOutput(m_noticeLevel[category_]);
		}
		//【一時画面通知レベル版】
		level::value_t getNoticeLevel(const category::value_t category_)
		{
			return isValidTempNoticeLevel(category_) ? m_noticeLevel[category_] : m_noticeLevelG[category_];
		}
		//【一時画面通知レベルのコールポイント版】
		level::value_t getNoticeLevel_CP(const category::value_t category_)
		{
			return isValidTempNoticeLevel(category_) ? m_noticeLevel[category_] : getNoticeLevelG_CP(category_);
		}
		//現在の画面通知レベルを変更
		//※指定の値以上のレベルのメッセージのみをログ出力する
		//※変更前の画面通知レベルを返す（forEvery指定時はforAnyの画面通知レベルを返す）
		static level::value_t setNoticeLevelG(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			if (category_ == forEvery)
			{
				const level::value_t prev = m_noticeLevelG[forAny];
				for (level::value_t& value : m_noticeLevelG)
					value = level_;
				return prev;
			}
			assert(o_category.forNotice() == true);
			const level::value_t prev = m_noticeLevelG[category_];
			m_noticeLevelG[category_] = level_;
			return prev;
		}
		//【一時画面通知レベル版】
		level::value_t setNoticeLevel(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			copyNoticeLevel();//更新前に現在の画面通知レベルをコピー
			if (category_ == forEvery)
			{
				const level::value_t prev = m_noticeLevel[forAny];
				for (int category_tmp = category::NORMAL_MIN; category_tmp <= category::NORMAL_MAX; ++category_tmp)
				{
					m_noticeLevel[category_tmp] =
						level::calcValueAsOutput(m_noticeLevelG[category_tmp]) > level::calcValueAsOutput(level_) ?
						m_noticeLevelG[category_tmp] ://本来のレベルより低くすることはできない
						level_;
				}
				return prev;
			}
			assert(o_category.forNotice() == true);
			const level::value_t prev = m_noticeLevel[category_];
			m_noticeLevel[category_] =
				level::calcValueAsOutput(m_noticeLevelG[category_]) > level::calcValueAsOutput(level_) ?
				m_noticeLevelG[category_] ://本来のレベルより低くすることはできない
				level_;
			return prev;
		}
		//現在の画面通知レベルをリセット
		//※デフォルトに戻す
		static void resetNoticeLevelG(const category::value_t category_)
		{
			setNoticeLevelG(DEFAULT_NOTOICE_LEVEL, category_);
		}
		//【一時画面通知レベル版】
		void resetNoticeLevel(const category::value_t category_)
		{
			setNoticeLevel(DEFAULT_NOTOICE_LEVEL, category_);
		}
		//現在の画面通知レベルを全てリセット
		//※デフォルトに戻す
		static void resetNoticeLevelAllG()
		{
			//resetNoticeLevelG(forEvery);//初期化処理でも呼び出されるので、共通処理を使わず単純に更新
			for (level::value_t& value : m_noticeLevelG)
				value = DEFAULT_NOTOICE_LEVEL;
		}
		//【一時画面通知レベル版】
		void resetNoticeLevelAll()
		{
			resetNoticeLevel(forEvery);
		}
		//画面通知レベルを一時画面通知レベルにコピー
		void copyNoticeLevel()
		{
			if (m_noticeLevelHasChanged)
				return;
			message* call_point = getLastCallPointWithLogLevelHasChanged();
			m_noticeLevelHasChanged = true;
			if (m_hasPushed)
				++m_noticeLevelHasChangedG;
			if (call_point)
				memcpy(m_noticeLevel, call_point->m_noticeLevel, sizeof(m_noticeLevel));//一時ログレベル
			else
				memcpy(m_noticeLevel, m_noticeLevelG, sizeof(m_noticeLevel));//一時ログレベル
		}
		//一時画面通知レベルのコピー状態を解除
		//※本来の画面通知レベルに戻す
		void releaseNoticeLevel()
		{
			if (!m_noticeLevelHasChanged)
				return;
			m_noticeLevelHasChanged = false;
			if (m_hasPushed)
				--m_noticeLevelHasChangedG;
		}
	protected:
		//メッセージバッファ確保
		static void beginBuffer()
		{
			if (m_messageBuff)
				freeBuffer();
			messageBuffer allocator;//メッセージ固定バッファ
			m_messageBuff = reinterpret_cast<buff_t*>(allocator.assignBuffer());
			m_messageBuffSize = messageBuffer::BUFFER_SIZE;
			m_messageBuffUsed = 0;
			if (!m_messageBuff)
				m_messageBuffSize = 0;
		}
		//メッセージバッファ解放
		static void freeBuffer()
		{
			if (!m_messageBuff)
				return;
			messageBuffer allocator;//メッセージ固定バッファ
			allocator.releaseBuffer(m_messageBuff);
			m_messageBuff = nullptr;//メッセージバッファ
			m_messageBuffSize = 0;//メッセージバッファサイズ
			m_messageBuffUsed = 0;//メッセージバッファ使用量
		}
		//メッセージバッファフラッシュ
		static void flushBuffer(const level& o_level, const bool flush_log, const bool flush_notice, const bool log_without_color = false)
		{
			if (!m_messageBuff)
				return;
			//【仮処理】本来はメッセージをキューイングする処理
			if (flush_log)
			{
				if (log_without_color)
				{
					fprintf(stdout, m_messageBuff);
				}
				else
				{
					color col(o_level.changeColor());
					fprintf(stdout, m_messageBuff);
				}
			}
			if (flush_notice)
			{
				color col(o_level.changeColorForNotice());
				fprintf(stderr, m_messageBuff);
			}
			freeBuffer();//バッファ解放
		}
		//バッファリング
		static int vbuffer(const char* fmt, va_list args)
		{
			std::size_t remain = m_messageBuffSize - m_messageBuffUsed;
			if (!m_messageBuff || remain == 0)
				return 0;
		#ifdef USE_STRCPY_S
			const int ret = vsprintf_s(m_messageBuff + m_messageBuffUsed, remain, fmt, args);
		#else//USE_STRCPY_S
			const int ret = vsprintf(m_messageBuff + m_messageBuffUsed, fmt, args);
		#endif//USE_STRCPY_S
			m_messageBuffUsed += ret;
			return ret;
		}
		static int buffer(const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vbuffer(fmt, args);
			va_end(args);
			return ret;
		}
		//出力判定
		static void isAllowPrint(bool& is_allow_log, bool& is_allow_notice, const level::value_t log_level, const level::value_t notice_level, const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forLog() == true || o_level.forNotice() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			const level& o_log_level = level::get(log_level);
			const level& o_notice_level = level::get(notice_level);
			is_allow_log = (o_level >= o_log_level && o_level.forLog() && o_category.forLog());
			is_allow_notice = (o_level >= o_notice_level && o_level.forNotice() && o_category.forNotice());
		}
		//メッセージ出力：レベルを引数指定
		//※va_listを引数にとるバージョン
		static int vprintCommon(const attr_t attr, const level::value_t log_level, const level::value_t notice_level, const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			bool is_allow_log;
			bool is_allow_notice;
			isAllowPrint(is_allow_log, is_allow_notice, log_level, notice_level, level_, category_);
			if (!is_allow_log && !is_allow_notice)
				return 0;
			const level& o_level = level::get(level_);
			const category& o_category = category::get(category_);
			beginBuffer();
			const bool without_color = (attr & withoutColor) ? true : false;
			const attr_t attr_tmp = attr & (withLevel | withCategory);
			if (is_allow_log && attr_tmp != 0)
			{
				if (attr_tmp == withLevel)
					buffer("[%s]", o_level.name());
				else if (attr_tmp == withCategory)
					buffer("[%s]", o_category.name());
				else//if (attr_tmp == (withLevel | withCategory))
					buffer("[%s,%s]", o_level.name(), o_category.name());
				flushBuffer(o_level, true, false, without_color);
				beginBuffer();
				buffer(" ");
			}
			int ret = vbuffer(fmt, args);
			flushBuffer(o_level, is_allow_log, is_allow_notice, true);
			return ret;
		}
		//コールポイントスタックをリスト表示
		static void printCPStackCommon(const attr_t attr, const level::value_t log_level, const level::value_t level_, const category::value_t category_, const char* name, const control_t control)
		{
			bool is_allow_log;
			bool is_allow_notice;
			isAllowPrint(is_allow_log, is_allow_notice, log_level, asSilentAbsolutely, level_, category_);
			if (!is_allow_log)
				return;
			const level& o_level = level::get(level_);
			const category& o_category = category::get(category_);
			const bool without_color = (attr & withoutColor) ? true : false;
			const attr_t attr_tmp = attr & (withLevel | withCategory);
			beginBuffer();
			buffer("============================================================\n");
			if (attr_tmp != 0)
			{
				if (attr_tmp == withLevel)
					buffer("[%s]", o_level.name());
				else if (attr_tmp == withCategory)
					buffer("[%s]", o_category.name());
				else//if (attr_tmp == (withLevel | withCategory))
					buffer("[%s,%s]", o_level.name(), o_category.name());
			}
			if (!without_color)
			{
				flushBuffer(o_level, true, false);
				beginBuffer();
			}
			buffer(" Call point stack at \"%s\"\n", name);
			buffer("----------------------------------------\n");
			const message* call_point = m_callPointStackHead;
			while (call_point)
			{
				buffer("  \"%s\" ", call_point->getName());
				if (attr_tmp != 0)
				{
					const level& o_level_tmp = level::get(call_point->getLevel());
					const category& o_category_tmp = category::get(call_point->getCategory());
					if (!without_color)
					{
						flushBuffer(o_level, true, false, true);
						beginBuffer();
					}
					if (attr_tmp == withLevel)
						buffer("[%s]", o_level_tmp.name());
					else if (attr_tmp == withCategory)
						buffer("[%s]", o_category_tmp.name());
					else//if (attr_tmp == (withLevel | withCategory))
						buffer("[%s,%s]", o_level_tmp.name(), o_category_tmp.name());
					if (!without_color)
					{
						flushBuffer(o_level_tmp, true, false, false);
						beginBuffer();
					}
				}
				const control_t control_tmp = control & (withFuncName | withFileName);
				if (control_tmp != 0)
				{
					buffer(" ... ");
					if (control_tmp & withFuncName)
						buffer("%s", call_point->getFuncName());
					if (control_tmp == (withFuncName | withFileName))
						buffer(" : ");
					if (control_tmp & withFileName)
						buffer(" %s", call_point->getSrcFileName());
				}
				buffer("\n");
				call_point = call_point->m_callPointStackNext;
			}
			if (!without_color)
			{
				flushBuffer(o_level, true, false, true);
				beginBuffer();
			}
			buffer("============================================================\n");
			flushBuffer(o_level, true, false, without_color);
		}
	public:
		//メッセージ出力／ログ出力／画面通知メソッド：レベルを引数指定
		//※vprint***/vlog***/vnotice***
		//※va_listを引数にとるバージョン
		static int vprintG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttrG_CP();
			const level::value_t log_level = getLogLevelG_CP(category_adj);
			const level::value_t notice_level = getNoticeLevelG_CP(category_adj);
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vprint(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//【一時ログ／画面通知レベル版】
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttr_CP();
			const level::value_t log_level = getLogLevel_CP(category_adj);
			const level::value_t notice_level = getNoticeLevel_CP(category_adj);
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vprint(const level::value_t level_, const char* fmt, va_list args)//【一時ログ／画面通知レベル版】
		{
			return vprint(level_, m_category, fmt, args);
		}
		int vprint(const char* fmt, va_list args)//【一時ログ／画面通知レベル版】
		{
			return vprint(m_level, m_category, fmt, args);
		}
		static int vlogG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttrG_CP();
			const level::value_t log_level = getLogLevelG_CP(category_adj);
			const level::value_t notice_level = asSilentAbsolutely;
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vlog(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//【一時ログレベル版】
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttr_CP();
			const level::value_t log_level = getLogLevel_CP(category_adj);
			const level::value_t notice_level = asSilentAbsolutely;
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vlog(const level::value_t level_, const char* fmt, va_list args)//【一時ログレベル版】
		{
			return vlog (level_, m_category, fmt, args);
		}
		int vlog(const char* fmt, va_list args)//【一時ログレベル版】
		{
			return vlog(m_level, m_category, fmt, args);
		}
		static int vnoticeG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttrG_CP();
			const level::value_t log_level = asSilentAbsolutely;
			const level::value_t notice_level = getNoticeLevelG_CP(category_adj);
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vnotice(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//【一時画面通知レベル版】
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttr_CP();
			const level::value_t log_level = asSilentAbsolutely;
			const level::value_t notice_level = getNoticeLevel_CP(category_adj);
			return vprintCommon(attr_adj, log_level, notice_level, level_, category_adj, fmt, args);
		}
		int vnotice(const level::value_t level_, const char* fmt, va_list args)//【一時画面通知レベル版】
		{
			return vnotice(level_, m_category, fmt, args);
		}
		int vnotice(const char* fmt, va_list args)//【一時画面通知レベル版】
		{
			return vnotice(m_level, m_category, fmt, args);
		}
		//メッセージ出力／ログ出力／画面通知メソッド：レベルを引数指定
		//※print***/log***/notice***
		//※可変長引数バージョン
		static int printG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprintG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//【一時ログ／画面通知レベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const level::value_t level_, const char* fmt, ...)//【一時ログ／画面通知レベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const char* fmt, ...)//【一時ログ／画面通知レベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(fmt, args);
			va_end(args);
			return ret;
		}
		static int logG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlogG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//【一時ログレベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const level::value_t level_, const char* fmt, ...)//【一時ログレベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const char* fmt, ...)//【一時ログレベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(fmt, args);
			va_end(args);
			return ret;
		}
		static int noticeG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnoticeG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//【一時画面通知レベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const level::value_t level_, const char* fmt, ...)//【一時画面通知レベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const char* fmt, ...)//【一時画面通知レベル版】
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(fmt, args);
			va_end(args);
			return ret;
		}
		//メッセージ出力／ログ出力／画面通知メソッド定義マクロ
		//※vprint***/vlog***/vnotice***
		//※va_listを引数にとるバージョン
	#define declare_vprintMethods(level_) \
		static int vprintAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vprintG(as##level_, category_, fmt, args); \
		} \
		int vprintAs##level_(const category::value_t category_, const char* fmt, va_list args)/*【一時ログ／画面通知レベル版】*/ \
		{ \
			return vprint(as##level_, category_, fmt, args); \
		} \
		int vprintAs##level_(const char* fmt, va_list args)/*【一時ログ／画面通知レベル版】*/ \
		{ \
			return vprint(as##level_, fmt, args); \
		} \
		static int vlogAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vlogG(as##level_, category_, fmt, args); \
		} \
		int vlogAs##level_(const category::value_t category_, const char* fmt, va_list args)/*【一時ログレベル版】*/ \
		{ \
			return vlog(as##level_, category_, fmt, args); \
		} \
		int vlogAs##level_(const char* fmt, va_list args)/*【一時ログレベル版】*/ \
		{ \
			return vlog(as##level_, fmt, args); \
		} \
		static int vnoticeAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vnoticeG(as##level_, category_, fmt, args); \
		} \
		int vnoticeAs##level_(const category::value_t category_, const char* fmt, va_list args)/*【一時画面通知レベル版】*/ \
		{ \
			return vnotice(as##level_, category_, fmt, args); \
		} \
		int vnoticeAs##level_(const char* fmt, va_list args)/*【一時画面通知レベル版】*/ \
		{ \
			return vnotice(as##level_, fmt, args); \
		}
			//メッセージ出力／ログ出力／画面通知メソッド定義マクロ
		//※print***/log***/notice***
		//※可変長引数バージョン
	#define declare_printMethods(level_) \
		static int printAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int printAs##level_(const category::value_t category_, const char* fmt, ...)/*【一時ログ／画面通知レベル版】*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int printAs##level_(const char* fmt, ...)/*【一時ログ／画面通知レベル版】*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		} \
		static int logAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int logAs##level_(const category::value_t category_, const char* fmt, ...)/*【一時ログレベル版】*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int logAs##level_(const char* fmt, ...)/*【一時ログレベル版】*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		} \
		static int noticeAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int noticeAs##level_(const category::value_t category_, const char* fmt, ...)/*【一時画面通知レベル版】*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int noticeAs##level_(const char* fmt, ...)/*【一時画面通知レベル版】*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		}
		//メッセージ出力／ログ出力／画面通知メソッド定義
		//※vprint***/vlog***/vnotice***
		//※va_listを引数にとるバージョン
		declare_vprintMethods(Normal);//通常メッセージ
		declare_vprintMethods(Verbose);//冗長メッセージ
		declare_vprintMethods(Detail);//詳細メッセージ
		declare_vprintMethods(Important);//重要メッセージ
		declare_vprintMethods(Warning);//警告メッセージ
		declare_vprintMethods(Critical);//重大（問題）メッセージ
		declare_vprintMethods(Absolute);//絶対（必須）メッセージ
		//メッセージ出力／ログ出力／画面通知メソッド定義
		//※print***/log***/notice***
		//※可変長引数バージョン
		declare_printMethods(Normal);//通常メッセージ
		declare_printMethods(Verbose);//冗長メッセージ
		declare_printMethods(Detail);//詳細メッセージ
		declare_printMethods(Important);//重要メッセージ
		declare_printMethods(Warning);//警告メッセージ
		declare_printMethods(Critical);//重大（問題）メッセージ
		declare_printMethods(Absolute);//絶対（必須）メッセージ
	protected:
		//コールポイントスタックに自身をプッシュ
		void pushCallPoint()
		{
			if (m_hasPushed)
				return;
			m_hasPushed = true;
			assert(m_callPointStackHead != this);
			m_callPointStackNext = m_callPointStackHead;
			m_callPointStackHead = this;
		}
		//コールポイントスタックから（自身を）ポップ
		void popCallPoint()
		{
			if (!m_hasPushed)
				return;
			m_hasPushed = false;
			assert(m_callPointStackHead == this);
			m_callPointStackHead = m_callPointStackNext;
			m_callPointStackNext = nullptr;
		}
	public:
		//直前のコールポイントを取得
		static message* getLastCallPoint()
		{
			return m_callPointStackHead;
		}
		//直近のクリティカルコールポイントを取得
		static message* getLastCriticalCallPoint()
		{
			message* node = m_callPointStackHead;
			while (node)
			{
				if (node->getLevel() == asCritical)
					break;
				node = node->m_callPointStackNext;
			}
			return node;
		}
		//直近で表示属性を更新したコールポイントを取得
		static message* getLastCallPointWithAttrHasChanged()
		{
			if (m_attrHasChangedG == 0)
				return nullptr;
			message* node = m_callPointStackHead;
			while (node)
			{
				if (node->attrHasChanged())
					break;
				node = node->m_callPointStackNext;
			}
			return node;
		}
		//直近でログレベルを更新したコールポイントを取得
		static message* getLastCallPointWithLogLevelHasChanged()
		{
			if (m_logLevelHasChangedG == 0)
				return nullptr;
			message* node = m_callPointStackHead;
			while (node)
			{
				if (node->logLevelHasChanged())
					break;
				node = node->m_callPointStackNext;
			}
			return node;
		}
		//直近で画面通知レベルを更新したコールポイントを取得
		static message* getLastCallPointWithNoticeLevelHasChanged()
		{
			if (m_noticeLevelHasChangedG == 0)
				return nullptr;
			message* node = m_callPointStackHead;
			while (node)
			{
				if (node->noticeLevelHasChanged())
					break;
				node = node->m_callPointStackNext;
			}
			return node;
		}
		//コールポイントスタックをリスト表示
		static void printCPStackG(const level::value_t level_, category::value_t category_, const char* name, const control_t control = simplePrint)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttrG_CP();
			const level::value_t log_level = getLogLevelG_CP(category_adj);
			printCPStackCommon(attr_adj, log_level, level_, category_adj, name, control);
		}
		void printCPStack(const level::value_t level_, category::value_t category_, const char* name, const control_t control = simplePrint)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const attr_t attr_adj = getAttr_CP();
			const level::value_t log_level = getLogLevel_CP(category_adj);
			printCPStackCommon(attr_adj, log_level, level_, category_adj, name, control);
		}
	#define declare_printCPMethods(level_) \
		static void printCPStackAs##level_##G(const category::value_t category_, const char* name, const control_t control = simplePrint) \
		{ \
			printCPStackG(as##level_, category_, name, control); \
		} \
		void printCPStackAs##level_(const category::value_t category_, const char* name, const control_t control = simplePrint)/*【一時ログ／画面通知レベル版】*/ \
		{ \
			printCPStack(as##level_, category_, name, control); \
		} \
		void printCPStackAs##level_(const char* name, const control_t control = simplePrint)/*【一時ログ／画面通知レベル版】*/ \
		{ \
			printCPStack(as##level_, m_category, name, control); \
		}
		declare_printCPMethods(Normal);//通常メッセージ
		declare_printCPMethods(Verbose);//冗長メッセージ
		declare_printCPMethods(Detail);//詳細メッセージ
		declare_printCPMethods(Important);//重要メッセージ
		declare_printCPMethods(Warning);//警告メッセージ
		declare_printCPMethods(Critical);//重大（問題）メッセージ
		declare_printCPMethods(Absolute);//絶対（必須）メッセージ
	public:
		//デフォルトコンストラクタ
		message():
			m_level(asNormal),//レベル
			m_category(forAny),//カテゴリ
			m_name(nullptr),//名前
			m_srcFileName(nullptr),//ソースファイル名
			m_funcName(nullptr),//関数名
			m_attr(0),//一時表示属性
			m_hasPushed(false),//コールポイントスタックにプッシュ済み
			m_attrHasChanged(false),//一時表示属性変更済み
			m_logLevelHasChanged(false),//一時ログレベル変更済み
			m_noticeLevelHasChanged(false),//一時画面通知レベル変更済み
			m_callPointStackNext(nullptr)//次のコールポイントスタック
		{
			initializeOnce();
		}
		//コンストラクタ
		message(const level::value_t level_, const category::value_t category_, const char* name, const char* src_file_name = nullptr, const char* func_name = nullptr) :
			m_level(level_),//レベル
			m_category(category_),//カテゴリ
			m_name(name),//名前
			m_srcFileName(src_file_name),//ソースファイル名
			m_funcName(func_name),//関数名
			m_attr(0),//一時表示属性
			m_hasPushed(false),//コールポイントスタックにプッシュ済み
			m_attrHasChanged(false),//一時表示属性変更済み
			m_logLevelHasChanged(false),//一時ログレベル変更済み
			m_noticeLevelHasChanged(false),//一時画面通知レベル変更済み
			m_callPointStackNext(nullptr)//次のコールポイントスタック
		{
			assert(category_ >= category::NORMAL_MIN && category_ <= category::NORMAL_MAX);
		}
		//デストラクタ
		~message()
		{
			releaseAttr();//一時表示属性を解放
			releaseLogLevel();//一時ログレベルを解放
			releaseNoticeLevel();//一時画面通知レベルを解放
			popCallPoint();//コールスタックからポップ
		}
	protected:
		//フィールド
		const level::value_t m_level;//レベル
		const category::value_t m_category;//カテゴリ
		const char* m_name;//処理名
		const char* m_srcFileName;//ソースファイル名
		const char* m_funcName;//関数名
		attr_t m_attr;//表示属性
		bool m_hasPushed;//コールポイントスタックにプッシュ済み
		bool m_attrHasChanged;//一時表示属性変更済み
		bool m_logLevelHasChanged;//一時ログレベル変更済み
		bool m_noticeLevelHasChanged;//一時画面通知レベル変更済み
		message* m_callPointStackNext;//次のコールポイントスタック
		level::value_t m_logLevel[category::NORMAL_NUM];//一時ログレベル
		level::value_t m_noticeLevel[category::NORMAL_NUM];//一時画面通知レベル
	private:
		static bool m_isInitialized;//初期化済みフラグ
		static attr_t m_attrG;//表示属性
		static level::value_t m_logLevelG[category::NORMAL_NUM];//現在のログレベル
		static level::value_t m_noticeLevelG[category::NORMAL_NUM];//現在の画面通知レベル
		static thread_local int m_attrHasChangedG;//一時表示属性変更スタック数
		static thread_local int m_logLevelHasChangedG;//一時ログレベル変更スタック数
		static thread_local int m_noticeLevelHasChangedG;//一時画面通知レベル変更スタック数
		static thread_local message* m_callPointStackHead;//コールポイントスタックの先頭
		static thread_local buff_t* m_messageBuff;//メッセージバッファ
		static thread_local std::size_t m_messageBuffSize;//メッセージバッファサイズ
		static thread_local std::size_t m_messageBuffUsed;//メッセージバッファ使用量
	};
	//----------------------------------------
	//メッセージの静的変数をインスタンス化
	bool message::m_isInitialized = false;//初期化済みフラグ
	message::attr_t message::m_attrG = 0;//表示属性
	level::value_t message::m_logLevelG[category::NORMAL_NUM];//現在のログレベル
	level::value_t message::m_noticeLevelG[category::NORMAL_NUM];//現在の画面通知レベル
	thread_local int message::m_attrHasChangedG = 0;//一時表示属性変更スタック数
	thread_local int message::m_logLevelHasChangedG = 0;//一時ログレベル変更スタック数
	thread_local int message::m_noticeLevelHasChangedG = 0;//一時画面通知レベル変更スタック数
	thread_local message* message::m_callPointStackHead = nullptr;//コールポイントスタックの先頭
	thread_local message::buff_t* message::m_messageBuff = nullptr;//メッセージバッファ
	thread_local std::size_t message::m_messageBuffSize = 0;//メッセージバッファサイズ
	thread_local std::size_t message::m_messageBuffUsed = 0;//メッセージバッファ使用量
	//----------------------------------------
	//メッセージ初期化（一回限り）
	void message::initializeOnce()
	{
		//初期化済みチェック
		if (m_isInitialized)
			return;
		//静的変数を初期化
		m_isInitialized = true;
		resetAttrG();
		resetLogLevelAllG();
		resetNoticeLevelAllG();
	}
	//----------------------------------------
	//メッセージ用変数
	static message s_messageForInitialize;//初期化処理実行のためのインスタンス
	//----------------------------------------
	//コールポイント用定数
	enum controlEnum : unsigned char//操作設定
	{
		recProfile = 0x00,//プロファイル記録
		noProfile = 0x01,//プロファイル不要
	};
	//----------------------------------------
	//コールポイントクラス
	class callPoint : public message
	{
	public:
		//型
		typedef uintptr_t key_t;//キー型
		typedef std::chrono::high_resolution_clock::time_point clock_t;//クロック型
		typedef double duration_t;//処理時間型
		typedef unsigned char control_t;//操作設定型
	public:
		//アクセッサ
		key_t getKey() const{ return m_key; }//キー
		clock_t getBegintime() const{ return m_beginTime; }//処理開始時間
	public:
		//メソッド
		//経過時間取得
		duration_t getElapsedTime() const
		{
			const clock_t end_time = std::chrono::high_resolution_clock::now();
			return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - m_beginTime).count()) / 1000000.;
		}
	public:
		//コンストラクタ
		callPoint(const level::value_t level_, const category::value_t category_, const char* name, const controlEnum control, const key_t key, const char* src_file_name, const char* func_name) :
			message(level_, category_, name, src_file_name, func_name),
			m_key(key),
			m_control(control),
			m_beginTime(std::chrono::high_resolution_clock::now())
		{
			pushCallPoint();//コールポイントをプッシュ
		}
		//デストラクタ
		~callPoint()
		{
			if (!(m_control & noProfile))
			{
				//スレッド名取得
				CThreadID thread_id;
				
				//パフォーマンス記録
				CProfiler profiler;
				profiler.addProfile(m_key, m_name, &thread_id, getFileName(m_srcFileName), m_funcName, getElapsedTime());
			}
			//popCallPoint();//コールポイントをポップ　※ポップは親クラスが行うので不要
		}
	private:
		//フィールド
		const key_t m_key;//キー
		const control_t m_control;//操作設定
		const clock_t m_beginTime;//処理開始時間
	};
	template<level::value_t L>
	class callPointAsLevel : public callPoint
	{
	public:
		//定数
		static const level::value_t LEVEL = L;//レベル
	public:
		//コンストラクタ
		callPointAsLevel(const category::value_t category_, const char* name, const controlEnum control, const key_t key, const char* src_file_name, const char* func_name) :
			callPoint(LEVEL, category_, name, control, key, src_file_name, func_name)
		{}
		//デストラクタ
		~callPointAsLevel()
		{}
	};
#define declare_callPointClass(level_) using callPointAs##level_ = callPointAsLevel<as##level_>
	declare_callPointClass(Normal);//通常メッセージ
	declare_callPointClass(Verbose);//冗長メッセージ
	declare_callPointClass(Detail);//詳細メッセージ
	declare_callPointClass(Important);//重要メッセージ
	declare_callPointClass(Warning);//警告メッセージ
	declare_callPointClass(Critical);//重大（問題）メッセージ
	declare_callPointClass(Absolute);//絶対（必須）メッセージ
#define __CPARGS() reinterpret_cast<callPoint::key_t>(GET_CONCATENATED_SOURCE_FILE_NAME()), GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME()
	//----------------------------------------
	//関数
	message::attr_t getAttr(){ return message::getAttrG(); }
	//void setAttr(const message::attr_t attr){ message::setAttrG(attr); }
	message::attr_t addAttr(const message::attr_t attr){ return message::addAttrG(attr); }
	message::attr_t delAttr(const message::attr_t attr){ return message::delAttrG(attr); }
	void resetAttr(){ message::resetAttrG(); }
	//現在のログレベルを取得
	level::value_t getLogLevel(const category::value_t category_)
	{
		return message::getLogLevelG(category_);
	}
	//現在のログレベルを変更
	//※指定の値以上のレベルのメッセージのみをログ出力する
	level::value_t setLogLevel(const level::value_t level_, const category::value_t category_)
	{
		return message::setLogLevelG(level_, category_);
	}
	//現在のログレベルをリセット
	void resetLogLevel(const category::value_t category_)
	{
		message::resetLogLevelG(category_);
	}
	//現在のログレベルを全てリセット
	void resetLogLevelAll()
	{
		message::resetLogLevelAllG();
	}
	//現在の画面通知レベルを取得
	level::value_t getNoticeLevel(const category::value_t category_)
	{
		return message::getNoticeLevelG(category_);
	}
	//現在の画面通知レベルを変更
	//※指定の値以上のレベルのメッセージのみをログ出力する
	level::value_t setNoticeLevel(const level::value_t level_, const category::value_t category_)
	{
		return message::setNoticeLevelG(level_, category_);
	}
	//現在の画面通知レベルをリセット
	void resetNoticeLevel(const category::value_t category_)
	{
		message::resetNoticeLevelG(category_);
	}
	//現在の画面通知レベルを全てリセット
	void resetNoticeLevelAll()
	{
		message::resetNoticeLevelAllG();
	}
	//メッセージ出力／ログ出力／画面通知関数：レベルを引数指定
	//※vprint***/vlog***/vnotice***
	//※va_listを引数にとるバージョン
	static int vprint(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vprintG(level_, category_, fmt, args);
	}
	static int vlog(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vlogG(level_, category_, fmt, args);
	}
	static int vnotice(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vnoticeG(level_, category_, fmt, args);
	}
	//メッセージ出力／ログ出力／画面通知関数：レベルを引数指定
	//※print***/log***/notice***
	//※可変長引数バージョン
	static int print(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vprintG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	static int log(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vlogG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	static int notice(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vnoticeG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	//メッセージ出力／ログ出力／画面通知関数定義マクロ
	//※vprint***/vlog***/vnotice***
	//※va_listを引数にとるバージョン
#define declare_vprintFuncs(level_) \
	static int vprintAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vprintAs##level_##G(category_, fmt, args); \
	} \
	static int vlogAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vlogAs##level_##G(category_, fmt, args); \
	} \
	static int vnoticeAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vnoticeAs##level_##G(category_, fmt, args); \
	}
	//メッセージ出力／ログ出力／画面通知関数定義マクロ
	//※print***/log***/notice***
	//※可変長引数バージョン
#define declare_printFuncs(level_) \
	static int printAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vprintAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	} \
	static int logAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vlogAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	} \
	static int noticeAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vnoticeAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	}
	//メッセージ出力／ログ出力／画面通知関数定義
	//※vprint***/vlog***/vnotice***
	//※va_listを引数にとるバージョン
	declare_vprintFuncs(Normal);//通常メッセージ
	declare_vprintFuncs(Verbose);//冗長メッセージ
	declare_vprintFuncs(Detail);//詳細メッセージ
	declare_vprintFuncs(Important);//重要メッセージ
	declare_vprintFuncs(Warning);//警告メッセージ
	declare_vprintFuncs(Critical);//重大（問題）メッセージ
	declare_vprintFuncs(Absolute);//絶対（必須）メッセージ
	//メッセージ出力／ログ出力／画面通知関数定義
	//※print***/log***/notice***
	//※可変長引数バージョン
	declare_printFuncs(Normal);//通常メッセージ
	declare_printFuncs(Verbose);//冗長メッセージ
	declare_printFuncs(Detail);//詳細メッセージ
	declare_printFuncs(Important);//重要メッセージ
	declare_printFuncs(Warning);//警告メッセージ
	declare_printFuncs(Critical);//重大（問題）メッセージ
	declare_printFuncs(Absolute);//絶対（必須）メッセージ
	void printCPStack(const level::value_t level_, category::value_t category_, const char* name, const message::control_t control = simplePrint)
	{
		message::printCPStackG(level_, category_, name, control);
	}
#define declare_printCPFunc(level_) \
	static void printCPStackAs##level_(const category::value_t category_, const char* name, const message::control_t control = simplePrint) \
	{ \
		message::printCPStackAs##level_##G(category_, name, control); \
	}
	declare_printCPFunc(Normal);//通常メッセージ
	declare_printCPFunc(Verbose);//冗長メッセージ
	declare_printCPFunc(Detail);//詳細メッセージ
	declare_printCPFunc(Important);//重要メッセージ
	declare_printCPFunc(Warning);//警告メッセージ
	declare_printCPFunc(Critical);//重大（問題）メッセージ
	declare_printCPFunc(Absolute);//絶対（必須）メッセージ
}//namespce dbg

//----------------------------------------
//デバッグメッセージのユーザー拡張
namespace dbg
{
	//ユーザー拡張
	namespace ext
	{
		//----------------------------------------
		//カテゴリ定数
		enum categoryEnum : category::value_t
		{
			forThread = define_revervedCategory(0),//スレッド
			forTaro = define_revervedCategory(1),//太郎専用
		};
		//----------------------------------------
		//カテゴリ定義
		//※ヘッダーで公開する必要なし
		declare_reservedCategory(forThread, true, false);//スレッド
		declare_reservedCategory(forTaro, true, true);//太郎専用
		//----------------------------------------
		//カテゴリコンテナ拡張初期化
		struct categoryContainerExt
		{
			categoryContainerExt()
			{
				category::container::initializeOnce();
				category_forThread();//スレッド
				category_forTaro();//太郎専用
			}
		};
		//----------------------------------------
		//変数
		static categoryContainerExt s_categoryForInitialize;//初期化処理実行のためのインスタンス
	}//namespace ext
}//namespace dbg



//----------------------------------------
//テスト

//ネームスーペース表記省略用
using namespace dbg;
using namespace dbg::ext;

//--------------------
//テスト（共通関数）
void printCommon(const char* name)
{
	printf("---------- printCommon(%s) ----------\n", name);
	printAsNormal(forAny, "通常メッセージ(%s)\n", name);
	printAsVerbose(forAny, "冗長メッセージ\n");
	printAsDetail(forAny, "詳細メッセージ\n");
	printAsImportant(forAny, "重要メッセージ\n");
	printAsWarning(forAny, "警告メッセージ\n");
	printAsCritical(forAny, "重大メッセージ\n");
	printAsAbsolute(forAny, "絶対メッセージ\n");
	printAsNormal(for3D, "【3D】通常メッセージ\n");
	printAsNormal(for2D, "【2D】通常メッセージ\n");
	printAsNormal(forLogic, "【Logic】通常メッセージ\n");
	printAsCritical(forCallPoint, "【CPのカテゴリ】重大メッセージ\n");
	printAsCritical(forCriticalCallPoint, "【クリティカルCPのカテゴリ】重大メッセージ\n");
	print(asNormal, forAny, "【レベルを引数指定】通常メッセージ\n");
	logAsCritical(forAny, "【ログ出力専用関数】重大メッセージ\n");
	noticeAsCritical(forAny, "【画面通知専用関数】重大メッセージ\n");
	printCPStackAsNormal(forAny, "CP(コールポイント)スタック表示");
}
//ランダム時間ウェイトする
static std::mt19937 s_rndEngine;
void initRnadom()//初期化
{
	//乱数初期化
	std::random_device rd;
	s_rndEngine.seed(rd());
}
void randomWait()//ウェイト
{
	std::uniform_int_distribution<int> time(10, 100);
	const int sleep_time = time(s_rndEngine);
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
}
//--------------------
//テスト（擬似ゲームループ）
void gameLoop()
{
	for (int frame = 0; frame < 10; ++frame)
	{
		//フレームの処理開始
		//※デストラクタで処理するため、処理ブロックで囲む
		{
			callPointAsCritical cp(forAny, "ゲームループ", recProfile, __CPARGS());
			extern void subProc1();
			extern void subProc2();
			extern void subProc3();
			extern void subProc4();
			extern void subProc5();
			extern void subProc6();
			extern void subProc7(const char* thread_name);
			std::thread th1 = std::thread(subProc7, "スレッドA");
			subProc1();//処理１
			subProc2();//処理２
			subProc3();//処理３
			std::thread th2 = std::thread(subProc7, "スレッドB");
			subProc4();//処理４
			subProc5();//処理５
			subProc6();//処理６
			std::thread th3 = std::thread(subProc7, "スレッドC");
			printCommon(cp.getName());//共通処理
			th1.join();
			th2.join();
			th3.join();
		}

		//フレームの処理時間を集計
		{
			CProfiler profiler;
			profiler.sumOnFrame();
		}
	}
}
//処理１
void subProc1()
{
	callPointAsNormal cp(for3D, "処理１：表示属性変更", recProfile, __CPARGS());
	cp.delAttr(withLevel);//レベル表示なし
	//cp.delAttr(withCategory);//カテゴリ表示なし
	randomWait();//ウェイト
	printCommon(cp.getName());//共通処理
}
//処理２
void subProc2()
{
	callPointAsNormal cp(for2D, "処理２：静寂", recProfile, __CPARGS());
	cp.setLogLevel(asSilent, forEvery);//以降のログ表示なし（画面通知はあり）
	randomWait();//ウェイト
	printCommon(cp.getName());//共通処理
}
//処理３
void subProc3()
{
	callPointAsNormal cp(forLogic, "処理３：カラー非表示", recProfile, __CPARGS());
	cp.addAttr(withoutColor);//カラー表示なし（ログにのみ影響）
	randomWait();//ウェイト
	printCommon(cp.getName());//共通処理
}
//処理４
void subProc4()
{
	callPointAsNormal cp(forGameData, "処理４：絶対静寂", recProfile, __CPARGS());
	cp.setLogLevel(asSilentAbsolutely, forAny);//以降のforAnyのログ表示を完全停止
	cp.setNoticeLevel(asSilentAbsolutely, forEvery);//以降の全ての画面通知表示を完全停止
	randomWait();//ウェイト
	printCommon(cp.getName());//共通処理
}
//処理５
void subProc5()
{
	callPointAsNormal cp(forSound, "処理５：なにもしない", recProfile, __CPARGS());
	randomWait();//ウェイト
	printCommon(cp.getName());//共通処理
}
//処理６
void subProc6()
{
	//コールポイントがクリティカル
	callPointAsCritical cp(forTaro, "処理６：クリティカルCP", recProfile, __CPARGS());
	randomWait();//ウェイト
	subProc5();
}
//処理７
void subProc7(const char* thread_name)
{
	callPointAsCritical cp(forThread, "処理７：スレッド", recProfile, __CPARGS());
	CThreadID thread_id(thread_name);
	//スレッド用（ウェイトのみ）
	randomWait();//ウェイト
}
//--------------------
//テスト（プロファイルを表示）
void printProfile()
{
	printf("--- PROFILE ---\n");
	CProfiler profiler;
	printf("size()=%d, Buffer:Total=%d,Used=%d,Remain=%d\n", profiler.size(), profiler.getBuffTotal(), profiler.getBuffUsed(), profiler.getBuffRemain());
	CStackAllocatorWithBuff<2048> work;//ワーク領域確保
	CTempPolyStackAllocator alloc(work);//new 演算子でワーク領域を使うように設定（処理ブロックを抜けたら自動解除）
	//ソートのためにvectorに移し替え
	typedef std::vector<const CProfiler::PROFILE*> vec_t;
	vec_t vec;
	for (auto& o : profiler)
	{
		const CProfiler::PROFILE& profile = o.second;
		vec.push_back(&profile);
	}
	//ソート
	//※トータル処理時間が大きい順
	std::sort(vec.begin(), vec.end(),
		[](const CProfiler::PROFILE* lhs, const CProfiler::PROFILE* rhs)->bool
	{
		return lhs->m_total.sum > rhs->m_total.sum;
	}
	);
	//表示
	for (auto& ite : vec)
	{
		const CProfiler::PROFILE& profile = *ite;
		//printf("name=\"%s\", funcname=\"%s\", srcFileName=\"%s\", TOTAL:(count=%d, sum=%.6llf, max=%.6f, min=%.6f, ave=%.6f), FRAME:(count=%d, sum=%.6llf, max=%.6f, min=%.6f, ave=%.6f), frameCount=%d\n",
		//	profile.m_name.c_str(), profile.m_funcName.c_str(), profile.m_srcFileName.c_str(), 
		//	profile.m_total.count, profile.m_total.sum, profile.m_total.min, profile.m_total.max, profile.m_total.average(), 
		//	profile.m_frame.count, profile.m_frame.sum, profile.m_frame.min, profile.m_frame.max, profile.m_frame.average(), 
		//	profile.m_frameCount);
		printf("%8.6fsec (%d cnt): \"%s\" %s\n", profile.m_total.sum, profile.m_total.count, profile.m_name.c_str(), profile.m_funcName.c_str());
	}
	printf("work:total=%d,used=%d,remain=%d\n", work.getTotal(), work.getUsed(), work.getRemain());
}

//--------------------
//テスト
int main(const int argc, const char* argv[])
{
	//スレッドに名前を付ける
	CThreadID("メインスレッド");

	//レベルを列挙
	printf("---------- レベルを列挙 ----------\n");
	printLevelAll();
	
	//カテゴリを列挙
	printf("---------- カテゴリを列挙 ----------\n");
	printCategoryAll();

	//初期状態でプリント
	printCommon("初期状態");

	//擬似ゲームループ
	gameLoop();

	//プロファイルを表示
	printProfile();

	return EXIT_SUCCESS;
}

// End of file
