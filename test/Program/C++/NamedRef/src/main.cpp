#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//C++11ライブラリ
#include <thread>//スレッド
#include <atomic>//アトミック型

//--------------------------------------------------------------------------------
//基本マクロ

//ブレークポイント
#include <windows.h>//ブレークポイント用
#define BREAK_POINT() DebugBreak()

//デバッグプリント
#define DEBUG_PRINT(msg, ...) printf(msg, __VA_ARGS__);
#define DEBUG_FPRINT(fp, msg, ...) fprintf(fp, msg, __VA_ARGS__);
#define DEBUG_FLUSH() fflush(stdout)
#define DEBUG_FFLUSH(fp) fflush(fp)
//#define DEBUG_PRINT(msg, ...)
//#define DEBUG_FPRINT(fp, msg, ...)
//#define DEBUG_FLUSH()
//#define DEBUG_FFLUSH(fp) fflush(fp)

//文字列化マクロ
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)
#define COLLECT_STRING(s) s

//アサーション
#define ASSERT(expr, msg, ...) \
if (!(expr)) \
	{ \
	DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
	"  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
	"  "  msg "\n", __VA_ARGS__); \
	BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//削除用
//#include <assert.h>//assert用
//#define ASSERT(expr, msg, ...) assert(expr)//VC++標準版

//スレッドローカルストレージ修飾子
//※C++11仕様偽装（VC++2013では未対応につき）
//※中身はWindows仕様
#define thread_local __declspec(thread)

//----------------------------------------
//スレッドIDクラス
//※TLSを活用して高速化

//スレッドID型
//typedef std::thread::id THREAD_ID;//C++11/ ※この型では扱わず、ハッシュ値を使用する
typedef std::size_t THREAD_ID;//C++11
static const THREAD_ID INVALID_THREAD_ID = 0xffffffff;//無効なスレッドID

//現在のスレッドID取得関数
//inline THREAD_ID  GetThisThreadID(){ return std::this_thread::get_id(); } //C++11
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id().hash(); } //C++11

//スレッドIDクラス
class CThreadID
{
public:
	//アクセッサ
	const THREAD_ID getID() const { return m_threadId; }//スレッドIDを取得
	const char* getName() const { return m_threadName; }//スレッド名を取得
public:
	//アクセッサ（static）
	static THREAD_ID getThisID(){ return m_thisThreadID; }//現在のスレッドのスレッドIDを取得
	static const char* getThisName(){ return m_thisThreadName; }//現在のスレッドのスレッド名を取得
public:
	//メソッド
	bool isThisThread() const { return m_threadId == getThisID(); }//現在のスレッドと同じスレッドか判定
private:
	//メソッド(static)
	static void setThisThread()//現在のスレッドのスレッドIDをセット
	{
		if (m_thisThreadID == INVALID_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
	}
	static void resetThisThread(const char* name)//現在のスレッドのスレッドIDをリセット
	{
		m_thisThreadID = GetThisThreadID();
		m_thisThreadName = name;
	}
public:
	//オペレータ（許可）
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID一致判定
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID不一致判定
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID一致判定
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID不一致判定
	CThreadID& operator=(const CThreadID& o) //コピー演算子
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
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
	//デフォルトコンストラクタ
	//※既にTLSに記録済みのスレッドID（と名前）を取得
	CThreadID()
	{
		setThisThread();
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
private:
	//フィールド
	THREAD_ID m_threadId;//スレッドID（オブジェクトに保存する値）
	const char* m_threadName;//スレッド名（オブジェクトに保存する値）
	static thread_local THREAD_ID m_thisThreadID;//現在のスレッドのスレッドID(TLS)
	static thread_local const char* m_thisThreadName;//現在のスレッド名(TLS)
};
//static変数のインスタンス化
thread_local THREAD_ID CThreadID::m_thisThreadID = INVALID_THREAD_ID;//スレッドID(TLS)
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

//--------------------------------------------------------------------------------
//固定メモリブロックアロケータクラス
//※現状は可読性重視だが、実際にはテンプレートのインスタンス化による
//　プログラムサイズの肥大を考慮し、非テンプレートの共通処理を
//　切り出す必要がある

//----------------------------------------
//クラス宣言
template<std::size_t N, std::size_t S>
class CBlockAllocator;

//----------------------------------------
//固定メモリブロックアロケータクラス専用配置new/delete処理
//※クラス内で使用するためのものなので、直接使用は禁止
//※クラス内でdeleteすることで、デストラクタの呼び出しにも対応

//配置new
template<std::size_t N, std::size_t S>
void* operator new(const std::size_t size, CBlockAllocator<N, S>& allocator){ return allocator.alloc(size); }

//配置delete
template<std::size_t N, std::size_t S>
void operator delete(void* p, CBlockAllocator<N, S>& allocator){ allocator.free(p); }

//----------------------------------------
//固定メモリブロックアロケータクラス
//※スレッドセーフ対応
template<std::size_t N, std::size_t S>
class CBlockAllocator
{
public:
	//型宣言
	typedef unsigned char byte;//バッファ用
	typedef unsigned int b32;//フラグ用
public:
	//定数
	static const std::size_t BLOCKS_NUM = N;//ブロック数
	static const std::size_t BLOCK_SIZE = S;//メモリブロックサイズ
	static const std::size_t FLAG_SIZE = ((N + 31) >> 5);//フラグサイズ（１サイズで32ビットのフラグ）
	static const std::size_t FLAG_SURPLUS_BITS = N % 32;//余剰フラグ数（32の倍数からはみ出したフラグの数）
private:
	//メソッド
	//メモリ確保状態リセット
	void reset()
	{
		//ロック取得
		m_lock.lock();

		//ゼロクリア
		memset(m_used, 0, sizeof(m_used));

		//ブロック数の範囲外のフラグは最初から立てておく
		if (FLAG_SURPLUS_BITS > 0)
		{
			b32 parmanent = 0xffffffff >> FLAG_SURPLUS_BITS;
			parmanent <<= FLAG_SURPLUS_BITS;
			m_used[FLAG_SIZE - 1] = parmanent;
		}

		//ロック解放
		m_lock.unlock();
	}
	//メモリブロック確保
	//※使用中フラグの空きを検索してフラグを更新し、
	//　確保したインデックスを返す
	int assign()
	{
		//ロック取得
		m_lock.lock();

		//確保済みインデックス準備
		int index = -1;//初期状態は失敗状態

		//空きフラグ検索
		b32* used_p = m_used;
		int bit_no = 0;
		for (int arr_idx = 0; arr_idx < FLAG_SIZE; ++arr_idx, ++used_p)
		{
			//32bitごとの空き判定
			b32 bits_now = *used_p;
			if (bits_now != 0xffffffff)
			{
				//32bitのフラグのどこかに空きがあるので、
				//最初に空いているフラグ（ビット）を検索
				b32 bits = bits_now;
				if ((bits & 0xffff) == 0xffff){ bit_no += 16; bits >>= 16; }//下位16ビット判定（空きがなければ16ビットシフト）
				if ((bits & 0xff) == 0xff){ bit_no += 8;  bits >>= 8; }//下位8ビット判定（空きがなければ8ビットシフト）
				if ((bits & 0xf) == 0xf){ bit_no += 4;  bits >>= 4; }//下位4ビット判定（空きがなければ4ビットシフト）
				if ((bits & 0x3) == 0x3){ bit_no += 2;  bits >>= 2; }//下位2ビット判定（空きがなければ2ビットシフト）
				if ((bits & 0x1) == 0x1){ ++bit_no; }//下位1ビット判定（空きがなければ上位1ビットで確定）
				bits_now |= (1 << bit_no);//論理和用のビット情報に変換
				*used_p = bits_now;//論理和
				index = arr_idx * 32 + bit_no;//メモリブロックのインデックス算出

				//確保成功
				break;
			}
		}

		//ロック解放
		m_lock.unlock();

		//終了
		return index;
	}
	//メモリブロック解放
	//※指定のインデックスの使用中フラグをリセット
	void release(const int index)
	{
		//インデックスの範囲チェック
		if (index < 0 || index >= BLOCKS_NUM)
			return;

		//ロック取得
		m_lock.lock();

		//フラグ解放
		const int arr_idx = index >> 5;//使用中フラグの配列番号
		const int bit_no = index & 31;//ビット番号
		m_used[arr_idx] &= ~(1 << bit_no);//論理積

		//ロック解放
		m_lock.unlock();
	}
public:
	//メモリ確保
	void* alloc(const std::size_t size)
	{
		//【アサーション】要求サイズがブロックサイズを超える場合は即時確保失敗
		ASSERT(size <= BLOCK_SIZE, "CBlockAllocator::alloc(%d) cannot allocate. Size must has been under %d.", size, BLOCK_SIZE);
		if (size > BLOCK_SIZE)
		{
			return nullptr;
		}
		//空きブロックを確保して返す
		const int index = assign();
		//【アサーション】全ブロック使用中につき、確保失敗
		ASSERT(index >= 0, "CBlockAllocator::alloc(%d) cannot allocate. Buffer is full. (num of blocks is %d)", size, BLOCKS_NUM);
		//確保したメモリを返す
		return index < 0 ? nullptr : &m_buff[index];
	}
	//メモリ解放
	void free(void * p)
	{
		//nullptr時は即時解放失敗
		ASSERT(p != nullptr, "CBlockAllocator::free() cannot free. Pointer is null.");
		if (!p)
			return;
		//ポインタからインデックスを算出
		const byte* top_p = reinterpret_cast<byte*>(m_buff);//バッファの先頭ポインタ
		const byte* target_p = reinterpret_cast<byte*>(p);//指定ポインタ
		const int diff = (target_p - top_p);//ポインタの引き算で差のバイト数算出
		const int index = (target_p - top_p) / BLOCK_SIZE;//ブロックサイズで割ってインデックス算出
		//【アサーション】メモリバッファの範囲外なら処理失敗（release関数内で失敗するのでそのまま実行）
		ASSERT(index >= 0 && index < BLOCKS_NUM, "CBlockAllocator::free() cannot free. Pointer is different.");
		//【アサーション】ポインタが各ブロックの先頭を指しているかチェック
		//　　　　　　　　⇒多重継承とキャストしているとずれることがるのでこの問題は無視して解放してしまう
		//ASSERT(diff % BLOCK_SIZE == 0, "CBlockAllocator::free() cannot free. Pointer is illegal.");
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
	void remove(T*& p)
	{
		p->~T();//明示的なデストラクタ呼び出し（デストラクタ未定義のクラスでも問題なし）
		operator delete(p, *this);//配置delete呼び出し
		p = nullptr;//ポインタにはnullptrをセット
	}
public:
	//コンストラクタ
	CBlockAllocator()
	{
		//使用中フラグリセット
		reset();
	}
	//デストラクタ
	~CBlockAllocator()
	{}
private:
	//フィールド
	byte m_buff[BLOCKS_NUM][BLOCK_SIZE];//ブロックバッファ
	b32 m_used[FLAG_SIZE];//使用中フラグ
	CSpinLock m_lock;//ロック
};

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
		m_lock(),
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
//名前付きデータ参照クラス

#include <atomic>//アトミック型

//【暫定】C++11のハッシュテーブルライブラリ
//※できれば、ヒープを使用しない独自の実装に変えた方が安定する
#include <unordered_map>

//----------------------------------------
//名前付きデータ参照クラス
//※テンプレートパラメータで記録可能な参照の最大数を指定
template<std::size_t MAX>
class CNamedRefT
{
public:
	//定数
	static const int MAX_NODES = MAX;//記録可能な参照の最大数を指定
public:
	//型
	typedef unsigned long long KeyPrim;//キー型（ハッシュテーブル用のプリミティブ型）
	//キー型
	struct Key
	{
		union
		{
			KeyPrim m_prim;//プリミティブ型キー
			struct
			{
				unsigned int m_main;//主キー
				unsigned int m_sub;//副キー
			};
		};
		//キャストオペレータ
		operator KeyPrim() const { return m_prim; }
		//比較オペレータ
		bool operator==(const Key& key) const { return m_prim == key.m_prim; }
		bool operator!=(const Key& key) const { return m_prim != key.m_prim; }
		bool operator>(const Key& key) const { return m_prim > key.m_prim; }
		bool operator<(const Key& key) const { return m_prim < key.m_prim; }
		bool operator>=(const Key& key) const { return m_prim >= key.m_prim; }
		bool operator<=(const Key& key) const { return m_prim <= key.m_prim; }
		//代入オペレータ
		Key& operator=(const Key& key) const { return m_prim = key.m_prim; }
		//メソッド
		//CRC値算出関数
		unsigned int CRC32(const char* name)
		{
			//ダミー処理
			return reinterpret_cast<unsigned long>(name);
		}
		//コンストラクタ
		//※explicit宣言しない ⇒ Key型を引数に取る関数に文字列を渡してもOK
		Key(const Key& key) :
			m_prim(key.m_prim)
		{}
		Key(const KeyPrim key_prim) :
			m_prim(key_prim)
		{}
		Key(const unsigned int main_key, const unsigned int sub_key) :
			m_main(main_key),
			m_sub(sub_key)
		{}
		Key(const unsigned int key) :
			m_main(key),
			m_sub(0)
		{}
		Key(const char* name, const unsigned int sub_key):
			m_main(CRC32(name)),
			m_sub(sub_key)
		{}
		Key(const char* name) :
			m_main(CRC32(name)),
			m_sub(0)
		{}
		Key(const unsigned int main_key, const char* sub_key) :
			m_main(main_key),
			m_sub(CRC32(sub_key))
		{}
		//デストラクタ
		~Key()
		{}
	};
private:
	//--------------------
	//変数参照型：共通部
	struct RefNodeCore
	{
		//メソッド
		virtual void* getRefByFunctor() const = 0;//関数オブジェクトを使用して変数の参照を取得
		virtual void getValByFunctor(void* val) const = 0;//関数オブジェクトを使用して変数の値を取得
		virtual void setValByFunctor(const void* val) = 0;//関数オブジェクトを使用して変数の値を更新
		//変数の参照を取得
		template<typename T>
		void* getRefCore() const
		{
			if (m_removed.load() == true)//【保険処理】削除済みチェック
				return nullptr;
			ASSERT(typeid(T) == m_type, "This type is not match.");
			if (typeid(T) != m_type)
				return nullptr;
			if (m_ref.load() == nullptr)//２回目以降のアクセスを高速にするために、参照を記憶する
				m_ref.store(getRefByFunctor());
			return m_ref.load();
		}
		//変数の参照を取得
		template<typename T>
		T* getRef(){ return static_cast<T*>(getRefCore<T>()); }
		//変数の参照を取得
		template<typename T>
		const T* getRef() const { return static_cast<T*>(getRefCore<T>()); }
		//変数の値を取得
		template<typename T>
		T getVal() const
		{
			if (m_removed.load() == true)//【保険処理】削除済みチェック
				return static_cast<T>(0);
			if (m_hasAccessor)
			{
				//アクセッサがある場合
				ASSERT(typeid(T) == m_type, "This type is not match.");
				if (typeid(T) != m_type)
					return static_cast<T>(0);
				T val = static_cast<T>(0);
				getValByFunctor(reinterpret_cast<void*>(&val));
				return val;
			}
			//アクセッサがない場合
			void* p = getRefCore<T>();
			return p == nullptr ? static_cast<T>(0) : *static_cast<T*>(p);
		}
		//変数の値を更新
		template<typename T>
		void setVal(const T val)
		{
			if (m_removed.load() == true)//【保険処理】削除済みチェック
				return;
			if (m_hasAccessor)
			{
				//アクセッサがある場合
				ASSERT(typeid(T) == m_type, "This type is not match.");
				if (typeid(T) != m_type)
					return;
				setValByFunctor(reinterpret_cast<const void*>(&val));
			}
			//アクセッサがない場合
			void* p = getRefCore<T>();
			if (p){ *static_cast<T*>(p) = val; }
		}
		//記憶している参照をリセット
		//※メモリ再配置や参照先の削除があったら呼び出す必要あり
		//※ロックフリー処理
		void resetRef(){ m_ref.store(nullptr); }
		//リードロック取得
		void rLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const { CRWLockHelper(m_lock).rLock(spin_count); }
		//ライトロック取得
		void wLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const { CRWLockHelper(m_lock).wLock(spin_count); }
		//リードロック解放
		void rUnlock() const { CRWLockHelper(m_lock).rUnlock(); }
		//ライトロック解放
		void wUnlock() const { CRWLockHelper(m_lock).wUnlock(); }
		//コンストラクタ
		RefNodeCore(const Key& key, const type_info& type, const bool has_accessor) :
			m_key(key),
			m_type(type),
			m_hasAccessor(has_accessor),
			m_ref(nullptr),
			m_lock()
		{
			m_removed.store(false);
		}
		//デストラクタ
		virtual ~RefNodeCore()
		{
			m_removed.store(true);//【保険処理】削除済みにする
			m_ref.store(nullptr);//【念のため】変数の参照をクリア
		}
		//フィールド
		const Key m_key;//キー
		const type_info& m_type;//型情報　※不正アクセス検出用
		const bool m_hasAccessor;//アクセッサタイプか？
		std::atomic<bool> m_removed;//【保険用】削除済みフラグ
		mutable std::atomic<void*> m_ref;//変数の参照
		mutable CRWLock m_lock;//リード・ライトロックオブジェクト
	};
	//--------------------
	//変数参照型：実装部：直接参照タイプ
	//※直接参照タイプは、一度関数オブジェクトで変数の参照を取得したらそれを保持し、
	//　関数オブジェクトの再実行を行わないため、２回目以降のアクセスが早い。
	//※明示的に「参照をリセット」すると、次回また関数オブジェクトを実行する。
	template <typename F>
	struct DirectRefNode : public RefNodeCore
	{
		//型
		typedef typename F::TYPE TYPE;//データ型
		typedef typename F NAMED_REF_FUNCTOR;//変数の参照取得用関数オブジェクト型
		//【オーバーライド】関数オブジェクトを使用して変数の参照を取得
		void* getRefByFunctor() const override
		{
			NAMED_REF_FUNCTOR functor;
			return functor(m_key);
		}
		//【オーバーライド】【無効】関数オブジェクトを使用して変数の値を取得
		void getValByFunctor(void* val) const override {}
		//【オーバーライド】【無効】関数オブジェクトを使用して変数の値を更新
		void setValByFunctor(const void* val) override {}
		//コンストラクタ
		DirectRefNode(const Key& key) :
			RefNodeCore(key, typeid(TYPE), false)
		{}
		//デストラクタ
		~DirectRefNode() override
		{}
	};
	//--------------------
	//変数参照型：実装部：アクセッサタイプ
	//※直接参照タイプの方が、参照を記憶できる分早い。
	//※アクセッサタイプは、毎回必ずアクセッサを通す。
	template<typename F>
	struct AccessorNode : public RefNodeCore
	{
		//型
		typedef typename F::TYPE TYPE;//データ型
		typedef typename F::getter GETTER_FUNCTOIR;//変数の値取得用関数オブジェクト型
		typedef typename F::setter SETTER_FUNCTOIR;//変数の値更新用関数オブジェクト型
		//【オーバーライド】【無効】関数オブジェクトを使用して変数の参照を取得
		void* getRefByFunctor() const override{ return nullptr; }
		//【オーバーライド】関数オブジェクトを使用して変数の値を取得
		void getValByFunctor(void* val) const override
		{
			GETTER_FUNCTOIR functor;
			*static_cast<TYPE*>(val) = functor(m_key);
		}
		//【オーバーライド】関数オブジェクトを使用して変数の値を更新
		void setValByFunctor(const void* val) override
		{
			SETTER_FUNCTOIR functor;
			functor(m_key, *static_cast<const TYPE*>(val));
		}
		//コンストラクタ
		AccessorNode(const Key& key) :
			RefNodeCore(key, typeid(TYPE), true)
		{}
		//デストラクタ
		~AccessorNode() override
		{}
	};
public:
	//--------------------
	//関数オブジェクト用基本型
	//※必ず継承して使用する
	template<typename T>
	struct BaseRefF
	{
		typedef typename T TYPE;//データ型定義
	};
private:
	//--------------------
	//メモリサイズ計算用のダミー関数オブジェクト
	struct getRefFunctorDummy : BaseRefF<int>{ TYPE* operator()(const Key& key) const { return nullptr; } };//【ダミー】変数参照用関数オブジェクト：直接参照タイプ
	struct accessorFunctorDummy : BaseRefF<int>{//【ダミー】変数参照用関数オブジェクト：アクセッサタイプ
		struct getter { TYPE operator()(const Key& key) const { return 0; } };
		struct setter { void operator()(const Key& key, const TYPE val) const {} };
	};
	using DirectRefNodeDummy = DirectRefNode<getRefFunctorDummy>;//【ダミー】変数参照型：直接参照タイプ
	using AccessorNodeDummy = AccessorNode<accessorFunctorDummy>;//【ダミー】変数参照型：アクセッサタイプ
public:
	//定数
	#define MAX_SIZE(x, y) ((x) > (y) ? (x) : (y))
	static const std::size_t REF_NODE_SIZE_MAX = MAX_SIZE(sizeof(DirectRefNodeDummy), sizeof(AccessorNodeDummy));//変数参照型の最大サイズ
	#undef MAX_SIZE
private:
	//型
	//--------------------
	//ハッシュテーブル型
	//【暫定】C++11標準ライブラリのハッシュテーブル型を使用
	//※できれば、ヒープを使用しない独自の実装に変えた方が安定する
	using NamedRefTable = std::unordered_map<KeyPrim, RefNodeCore*>;
public:
	//クラス内クラス定義
	//※構造体参照用
	
	//--------------------
	//変数読み込み参照用クラス：構造体参照用
	template<typename T>
	class RefR
	{
	public:
		//オペレータ
		const T* operator->() const { return m_ref; }//アロー演算子（本来のデータ型のプロキシー）
		T operator*() const { return *m_ref; }//ポインタ型
	public:
		//メソッド
		bool isExist() const { return m_isExist; }//参照先が存在するか？
	public:
		//コンストラクタ
		RefR(CNamedRefT<MAX>& map, const Key key, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_propRef(map.find(key, &m_isExist)),
			m_ref(nullptr)
		{
			//変数の参照を取得
			if (m_propRef)
			{
				m_ref = m_propRef->getRef<T>();
				if (m_ref)
				{
					//変数の参照に成功したらリードロック取得
					m_propRef->rLock(spin_count);
				}
			}
		}
		//デストラクタ
		~RefR()
		{
			if (m_propRef && m_ref)
			{
				//リードロック解放
				m_propRef->rUnlock();
			}
		}
	private:
		//フィールド
		const RefNodeCore* m_propRef;//変数参照型
		const T* m_ref;//変数参照
		bool m_isExist;//参照先が存在するか？
	};
	//--------------------
	//変数書き込み参照用クラス：構造体参照用
	template<typename T>
	class RefW
	{
	public:
		//オペレータ
		T* operator->(){ return m_ref; }//アロー演算子（本来のデータ型のプロキシー）
		const T* operator->() const { return m_ref; }//アロー演算子（本来のデータ型のプロキシー）
		T operator*() const { return *m_ref; }//ポインタ型
	public:
		//メソッド
		bool isExist() const { return m_isExist; }//参照先が存在するか？
	public:
		//コンストラクタ
		RefW(CNamedRefT<MAX>& map, const Key key, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_propRef(map.find(key, &m_isExist)),
			m_ref(nullptr)
		{
			//変数の参照を取得
			if (m_propRef)
			{
				m_ref = m_propRef->getRef<T>();
				if (m_ref)
				{
					//変数の参照に成功したらライトロック取得
					m_propRef->wLock(spin_count);
				}
			}
		}
		//デストラクタ
		~RefW()
		{
			if (m_propRef && m_ref)
			{
				//ライトロック解放
				m_propRef->wUnlock();
			}
		}
	private:
		//フィールド
		RefNodeCore* m_propRef;//変数参照型
		T* m_ref;//変数参照
		bool m_isExist;//参照先が存在するか？
	};
	//クラス内クラス定義：ここまで
	//--------------------
public:
	//メソッド
	//変数参照用関数オブジェクト登録：直接参照タイプ
	template<typename F>
	bool regist(const Key key, F functor)
	{
		//ハッシュテーブル登録済みチェック
		if (m_namedRefList.find(key) != m_namedRefList.end())
			return false;
		//ノードのメモリ確保
		DirectRefNode<F>* ref = m_allocator.create< DirectRefNode<F> >(key);
		if (!ref)
			return false;
		//ハッシュテーブルに追加登録
		m_namedRefList.insert(std::make_pair(key, ref));
		return true;
	}
	//変数参照用関数オブジェクト登録：アクセッサタイプ
	template<typename F>
	bool registAcc(const Key key, F functor_set)
	{
		//ハッシュテーブル登録済みチェック
		if (m_namedRefList.find(key) != m_namedRefList.end())
			return false;
		//ノードのメモリ確保
		AccessorNode<F>* ref = m_allocator.create< AccessorNode<F> >(key);
		if (!ref)
			return false;
		//ハッシュテーブルに追加登録
		m_namedRefList.insert(std::make_pair(key, ref));
		return true;
	}
	//変数参照用関数オブジェクト登録解除
	//※スレッドセーフではないのでタイミングに厳重注意
	//※念のためロックを取得してはいるものの、他からのアクセスをブロックしている状況だと、
	//　削除後に処理が走るので結局問題を起こす
	bool unregist(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		//変数参照情報取得
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		//登録解除と削除
		ref->wLock(spin_count);//ライトロック取得
		m_namedRefList.erase(key);//ハッシュテーブルから登録解除
		ref->wUnlock();//ライトロック解放
		m_allocator.remove(ref);//メモリ解放
		return true;
	}
	//全ての変数参照用関数オブジェクト登録解除
	//※スレッドセーフではないのでタイミングに厳重注意
	//※念のためロックを取得してはいるものの、他からのアクセスをブロックしている状況だと、
	//　削除後に処理が走るので結局問題を起こす
	void unregistAll(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		//全ノード処理
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;//ハッシュテーブルの情報を参照
			if (ref)
			{
				ref->wLock(spin_count);//ライトロック取得
				node.second = nullptr;//ハッシュテーブルから情報を破棄
				ref->wUnlock();//ライトロック解放
				m_allocator.remove(ref);//メモリ解放
			}
		}
		m_namedRefList.clear();//ハッシュテーブルの全ノードをクリア
	}
	//変数の参照をクリア
	//※ロックフリー処理
	void resetRef(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		//変数参照情報取得
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return;
		//変数の参照をクリア
		ref->resetRef();
	}
	//変数の参照を全てクリア
	//※ロックフリー処理
	void resetRefAll(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;
			if (ref)
			{
				//変数の参照をクリア
				ref->resetRef();
			}
		}
	}
private:
	//変数参照情報取得：共通部
	inline const RefNodeCore* findCore(const Key key, bool* is_exist) const
	{
		//ハッシュテーブル検索
		NamedRefTable::const_iterator node = m_namedRefList.find(key);
		if (node == m_namedRefList.end())
		{
			//見つからなかった場合
			if (is_exist)
				*is_exist = false;
			return nullptr;
		}
		const RefNodeCore* ref = node->second;
		if (!ref)
		{
			//見つからなかった場合
			if (is_exist)
				*is_exist = false;
			return nullptr;
		}
		//見つかった場合
		if (is_exist)
			*is_exist = true;
		return ref;
	}
	//変数参照情報取得：const用
	inline const RefNodeCore* find(const Key key, bool* is_exist) const
	{
		const RefNodeCore* ref = findCore(key, is_exist);
		return ref;
	}
	//変数参照情報取得：非const用
	inline RefNodeCore* find(const Key key, bool* is_exist)
	{
		const RefNodeCore* ref = findCore(key, is_exist);
		return const_cast<RefNodeCore*>(ref);
	}
public:
	//----------
	//値を取得：型指定用
	//※is_exist で参照先の変数の存在を確認可能
	//※リードロックのスピンカウント指定可
	template<typename T>
	T get(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		const RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return static_cast<T>(0);
		ref->rLock(spin_count);
		T val = ref->getVal<T>();
		ref->rUnlock();
		return val;
	}
	//bool型用
	bool getBool(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return get<bool>(key, is_exist, spin_count);
	}
	//int型用
	int getInt(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return get<int>(key, is_exist, spin_count);
	}
	//float型用
	float getFloat(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return get<float>(key, is_exist, spin_count);
	}
	//const char*型用
	const char* getStr(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return get<const char*>(key, is_exist, spin_count);
	}
	//----------
	//値を更新：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool set(const Key key, const T val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T now_val = ref->getVal<T>();
		if (prev_val)
			*prev_val = now_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//bool型用
	bool setBool(const Key key, const bool val, bool* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return set<bool>(key, val, prev_val, is_exist, spin_count);
	}
	//int型用
	bool setInt(const Key key, const int val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return set<int>(key, val, prev_val, is_exist, spin_count);
	}
	//float型用
	bool setFloat(const Key key, const float val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return set<float>(key, val, prev_val, is_exist, spin_count);
	}
	//const char*型用
	bool setStr(const Key key, const char* str, const char** prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return set<const char*>(key, str, prev_val, is_exist, spin_count);
	}
	//----------
	//値をインクリメント：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool inc(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val += static_cast<T>(1);
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool incInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return inc<int>(key, prev_val, is_exist, spin_count);
	}
	//----------
	//値をデクリメント：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool dec(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val -= static_cast<T>(1);
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool decInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return dec<int>(key, prev_val, is_exist, spin_count);
	}
	//----------
	//値を加算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool add(const Key key, const T add_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val += add_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool addInt(const Key key, const int add_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return add<int>(key, add_val, prev_val, is_exist, spin_count);
	}
	//float型用
	bool addFloat(const Key key, const float add_val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return add<float>(key, add_val, prev_val, is_exist, spin_count);
	}
	//----------
	//値を減算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool sub(const Key key, const T sub_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val -= sub_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool subInt(const Key key, const int sub_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return sub<int>(key, sub_val, prev_val, is_exist, spin_count);
	}
	//float型用
	bool subFloat(const Key key, const float sub_val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return sub<float>(key, sub_val, prev_val, is_exist, spin_count);
	}
	//----------
	//値を乗算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool mul(const Key key, const T mul_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val *= mul_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool mulInt(const Key key, const int mul_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return mul<int>(key, mul_val, prev_val, is_exist, spin_count);
	}
	//float型用
	bool mulFloat(const Key key, const float mul_val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return mul<float>(key, mul_val, prev_val, is_exist, spin_count);
	}
	//----------
	//値を除算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool div(const Key key, const T div_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val /= div_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool divInt(const Key key, const int div_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return div<int>(key, div_val, prev_val, is_exist, spin_count);
	}
	//float型用
	bool divFloat(const Key key, const float div_val, float* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return div<float>(key, div_val, prev_val, is_exist, spin_count);
	}
	//----------
	//値を剰余算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool mod(const Key key, const T mod_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val %= mod_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool modInt(const Key key, const int mod_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return mod<int>(key, mod_val, prev_val, is_exist, spin_count);
	}
	//----------
	//値を反転：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool reverse(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		ref->setVal<T>(~val);
		ref->wUnlock();
		return true;
	}
	//bool型用
	bool reverse(const Key key, bool* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		bool val = ref->getVal<bool>();
		if (prev_val)
			*prev_val = val;
		ref->setVal<bool>(val ? false : true );
		ref->wUnlock();
		return true;
	}
	//bool型用
	bool reverseBool(const Key key, bool* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return reverse(key, prev_val, is_exist, spin_count);
	}
	//int型用
	bool reverseInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return reverse<int>(key, prev_val, is_exist, spin_count);
	}
	//----------
	//値を論理積：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool and(const Key key, const T and_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val &= and_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool andInt(const Key key, const int and_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return and<int>(key, and_val, prev_val, is_exist, spin_count);
	}
	//----------
	//値を論理和：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool or(const Key key, const T or_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val |= or_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool orInt(const Key key, const int or_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return or<int>(key, or_val, prev_val, is_exist, spin_count);
	}
	//----------
	//値を排他的論理和：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	//※ライトロックのスピンカウント指定可
	template<typename T>
	bool xor(const Key key, const T xor_val, T* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val ^= xor_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool xorInt(const Key key, const int xor_val, int* prev_val = nullptr, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return xor<int>(key, xor_val, prev_val, is_exist, spin_count);
	}
	//----------
	//参照先が存在するか？
	bool isExist(const Key key) const
	{
		bool is_exist;
		find(key, &is_exist);
		return is_exist;
	}

public:
	//コンストラクタ
	CNamedRefT()
	{
		//ハッシュテーブルの要素数を最大数で予約
		m_namedRefList.reserve(MAX_NODES);
	}
	//デストラクタ
	~CNamedRefT()
	{
		//ハッシュテーブルから全ノード削除
		unregistAll();
	}
private:
	//フィールド
	CBlockAllocator<MAX_NODES, REF_NODE_SIZE_MAX> m_allocator;//固定メモリブロックアロケータ（最大数以上の確保は不可）
	NamedRefTable m_namedRefList;//【暫定】C++11標準ライブラリのハッシュテーブル
};

//----------------------------------------
//名前付きデータ参照クラスシングルトン
//※テンプレートパラメータで記録可能な参照の最大数を指定
//※インスタンス識別IDを指定することで、複数のシングルトンを作成可能
template <std::size_t MAX, int ID = 0>
class CNamedRefSingletonT
{
public:
	//型
	typedef CNamedRefT<MAX> NamedRef;//名前付きデータ参照クラス
public:
	//定数
	static const int INSTANCE_ID = ID;//インスタンス識別ID
public:
	//オペレータ
	operator NamedRef&() { return m_namedRef; }//キャストオペレータ
	const NamedRef* operator->() const { return &m_prosMap; }//アロー演算子
	NamedRef* operator->(){ return &m_namedRef; }//アロー演算子
private:
	//フィールド
	static NamedRef m_namedRef;//【static】名前付きデータ参照クラス本体
};

//----------------------------------------
//データ型のエイリアス
static const std::size_t NAMED_REF_MAX = 256;//名前付きデータ参照テーブルの最大数
using CNamedRefSingleton = CNamedRefSingletonT<NAMED_REF_MAX>;//名前付きデータ参照クラスシングルトン
using CNamedRef = CNamedRefSingleton::NamedRef;//名前付きデータ参照クラス
using RefK = CNamedRef::Key;//名前付きデータ参照キー
template <typename T>
using CRefR = CNamedRef::RefR<T>;//名前付きデータ参照：構造体参照クラス（読み込み用）
template <typename T>
using CRefW = CNamedRef::RefW<T>;//名前付きデータ参照：構造体参照クラス（書き込み用）
template <typename T>
using RefF = CNamedRef::BaseRefF<T>;//データ参照用関数オブジェクトの基本型

//--------------------
//変数参照用関数オブジェクト作成マクロ：直接参照タイプ
#define NAMED_REF_FUNCTOR(name, code, type) \
	struct name : RefF<type> \
	{ \
	TYPE* operator()(const RefK& key) const \
		{ \
			code; \
		} \
	};
//変数参照用関数オブジェクト作成マクロ：直接参照タイプ：簡易版
#define NAMED_REF_FUNCTOR_DIRECT(name, var, type) \
	NAMED_REF_FUNCTOR(name, return &var, type)
//--------------------
//変数参照用関数オブジェクト作成マクロ：アクセッサタイプ
#define NAMED_ACCESSOR_FUNCTOR(name, getter_code, setter_code, type) \
	struct name : RefF<type> \
	{ \
		struct getter \
		{ \
			TYPE operator()(const RefK& key) const \
			{ \
				getter_code; \
			} \
		}; \
		struct setter \
		{ \
			void operator()(const RefK& key, const TYPE val) const \
			{ \
				setter_code; \
			} \
		}; \
	};
//変数参照用関数オブジェクト作成マクロ：アクセッサタイプ：簡易版
#define NAMED_ACCESSOR_FUNCTOR_SIMPLE(name, obj, getter_method, setter_method, type) \
	NAMED_ACCESSOR_FUNCTOR(name, return obj getter_method(), obj setter_method(val), type })

//----------------------------------------
//名前付きデータ参照クラスシングルトンインスタンス化
CNamedRef CNamedRefSingleton::m_namedRef;

//--------------------------------------------------------------------------------
//名前付きデータ参照クラステスト

//----------------------------------------
//テスト用構造体：ダミーシーンオブジェクト
struct CSceneObjDummy
{
	//public フィールド
	const int id;//ID
	const char* name;//名前
	int data1;//データ1
	float data2;//データ2
	//アクセッサ
	int getData3() const { return data3; }//データ3：取得アクセッサ
	void setData3(const int val) { data3 = val; }//データ3：更新アクセッサ
	//コンストラクタ
	CSceneObjDummy(const int id_, const char* name_, const int data1_, const float data2_, const int data3_):
		id(id_),
		name(name_),
		data1(data1_),
		data2(data2_),
		data3(data3_)
	{}
private:
	//フィールド
	int data3;//データ3
};

//----------------------------------------
//テスト用データ定義
namespace TEST
{
	static bool s_debugCpuMeter = false;//【デバッグ用】CPU使用率表示状態
	static int s_debugData1 = 1;//【デバッグ用】データ1
	static float s_debugData2 = 2.f;//【デバッグ用】データ2
	static const char* s_debugData3 = "DATA3";//【デバッグ用】データ3
	static short s_debugData4 = 4;//【デバッグ用】データ4
	static int s_debugData5 = 5;//【デバッグ用】データ5
	//ダミーシーンオブジェクト
	static CSceneObjDummy s_sceneObjDummy[] =
	{
		{ 10, "太郎", 11, 111.1f, 1111 },
		{ 20, "次郎", 22, 222.2f, 2222 },
		{ 30, "三郎", 33, 333.3f, 3333 }
	};
	//ダミーシーンオブジェクト検索関数
	static CSceneObjDummy* searchSceneObj(const int id)
	{
		for (auto& o : s_sceneObjDummy)
		{
			if (o.id == id)
				return &o;
		}
		return nullptr;
	}
}

//----------------------------------------
//補助関数
const char* boolToStr(const bool val){ return val ? "true" : "false"; }//bool値を文字列化

//----------------------------------------
//テスト関数①：名前付きデータ参照を登録
void testRegistNamedRef()
{
	//変数参照用関数オブジェクトを定義：直接参照タイプ
	//・条件①：構造体内に「typedef データ型 TYPE;」を定義するか、「RefF<データ型>」を継承する。
	//・条件②：「TYPE* operator()(const RefK& key) const { return 変数のポインタ; }」を定義する。
	//・条件③：メンバー変数があってはいけない
	//struct refDebugCpuMeter : RefF<bool>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugCpuMeter; } };//【デバッグ用】CPU使用率表示状態参照用
	//struct refDebugParam1 : RefF<int>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugData1; } };//【デバッグ用】データ1参照用
	//struct refDebugParam2 : RefF<float>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugData2; } };//【デバッグ用】データ2参照用
	//struct refDebugParam3 : RefF<const char*>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugData3; } };//【デバッグ用】データ3参照用
	//struct refDebugParam4 : RefF<short>{ TYPE* operator()(const RefK& key) const { return &TEST::s_debugData4; } };//【デバッグ用】データ4参照用
	//struct refSceneObjDummy : RefF<CSceneObjDummy>{ TYPE *operator()(const RefK& key) const { return TEST::searchSceneObj(key.m_sub); } };//ダミーシーンオブジェクト参照用
	//※上記の構造体と同じことを「NAMED_REF_FUNCTOR」マクロで代用できる
	NAMED_REF_FUNCTOR_DIRECT(refDebugCpuMeter, TEST::s_debugCpuMeter, bool);//【デバッグ用】CPU使用率表示状態参照用
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam1, TEST::s_debugData1, int);//【デバッグ用】データ1参照用
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam2, TEST::s_debugData2, float);//【デバッグ用】データ2参照用
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam3, TEST::s_debugData3, const char*);//【デバッグ用】データ3参照用
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam4, TEST::s_debugData4, short);//【デバッグ用】データ4参照用
	NAMED_REF_FUNCTOR(refSceneObjDummy, return TEST::searchSceneObj(key.m_sub), CSceneObjDummy);//ダミーシーンオブジェクト参照用

	//変数参照用関数オブジェクトを定義：アクセッサタイプ
	//・条件①：構造体内に「typedef データ型 TYPE;」を定義するか、「RefF<データ型>」を継承する。
	//・条件②：「struct getter」を定義し、そのメンバーとして「TYPE operator()(const RefK& key) const { return 変数の値; }」を定義する。
	//・条件③：「struct setter」を定義し、そのメンバーとして「void operator()(const RefK& key, const TYPE val){ 変数 = val; }」を定義する。
	//・条件④：メンバー変数があってはいけない
	//struct refDebugParam5 : RefF<int>{//【デバッグ用】データ5アクセス用
	//	struct getter{ TYPE operator()(const RefK& key) const { return TEST::s_debugData5; } };
	//	struct setter{ void operator()(const RefK& key, const TYPE val) { TEST::s_debugData5 = val; } };
	//};
	//※上記の構造体と同じことを「NAMED_ACCESSOR_FUNCTOR」マクロで代用できる
	NAMED_ACCESSOR_FUNCTOR(refDebugParam5, return TEST::s_debugData5, TEST::s_debugData5 = val, int);//【デバッグ用】データ5アクセス用
	//※共通関数を作成したりなど、複雑な処理が必要ならマクロは使えない
	struct refSceneObjData3 : RefF<int>{//ダミーシーンオブジェクトのData3アクセス用
		typedef CSceneObjDummy OBJ;
		static OBJ* search(const RefK& key){ return TEST::searchSceneObj(key.m_sub); }
		struct getter{ TYPE operator()(const RefK& key) const { const OBJ* obj = search(key);  return obj ? obj->getData3() : 0; } };
		struct setter{ void operator()(const RefK& key, const TYPE val) { OBJ* obj = search(key); obj->setData3(val); } };
	};

	//名前付きデータ参照クラスシングルトン
	CNamedRefSingleton named_ref;

	//変数参照を登録：直接参照タイプ
	named_ref->regist(RefK("DebugCpuMeter"), refDebugCpuMeter()); //【デバッグ用】CPU使用率表示状態
	named_ref->regist(RefK("DebugParam1"), refDebugParam1());//【デバッグ用】データ1
	named_ref->regist(RefK("DebugParam2"), refDebugParam2());//【デバッグ用】データ2
	named_ref->regist(RefK("DebugParam3"), refDebugParam3());//【デバッグ用】データ3
	named_ref->regist(RefK("DebugParam4"), refDebugParam4());//【デバッグ用】データ4
	named_ref->regist(RefK("SceneObj", 10), refSceneObjDummy());//ダミーシーンオブジェクト：ID=10
	named_ref->regist(RefK("SceneObj", 20), refSceneObjDummy());//ダミーシーンオブジェクト：ID=20
	named_ref->regist(RefK("SceneObj", 30), refSceneObjDummy());//ダミーシーンオブジェクト：ID=30
	//変数参照を登録：アクセッサタイプ
	named_ref->registAcc(RefK("DebugParam5"), refDebugParam5());//【デバッグ用】データ5
	named_ref->registAcc(RefK("SceneObj::Data3", 10), refSceneObjData3());//ダミーシーンオブジェクト：Data3：ID=10
	named_ref->registAcc(RefK("SceneObj::Data3", 20), refSceneObjData3());//ダミーシーンオブジェクト：Data3：ID=20
	named_ref->registAcc(RefK("SceneObj::Data3", 30), refSceneObjData3());//ダミーシーンオブジェクト：Data3：ID=30
}

//----------------------------------------
//テスト関数②：名前付きデータ参照を使ってデータを表示
void testPrintNamedRef()
{
	CNamedRefSingleton named_ref;
	printf("DebugCpuMeter=%s\n", boolToStr(named_ref->getBool(RefK("DebugCpuMeter"))));
	printf("DebugParam1=%d\n", named_ref->getInt(RefK("DebugParam1")));
	printf("DebugParam2=%.3f\n", named_ref->getFloat(RefK("DebugParam2")));
	printf("DebugParam3=\"%s\"\n", named_ref->getStr(RefK("DebugParam3")));
	printf("DebugParam4=%d\n", named_ref->get<short>(RefK("DebugParam4")));
	printf("DebugParam5=%d\n", named_ref->getInt(RefK("DebugParam5")));
	for (int id : {10, 20, 30})
	{
		CRefR<CSceneObjDummy> obj(named_ref, RefK("SceneObj", id));
		if (obj.isExist())
			printf("SceneObj[id=%d]: {name\"%s\", data1=%d, data2=%.3f, data3=%d}\n",
				obj->id, obj->name, obj->data1, obj->data2, named_ref->getInt(RefK("SceneObj::Data3", id)));
	}
}

//----------------------------------------
//テスト関数③：名前付きデータ参照を使ってデータを更新
void testUpdateNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->setBool(RefK("DebugCpuMeter"), true);
	named_ref->setInt(RefK("DebugParam1"), 123);
	named_ref->setFloat(RefK("DebugParam2"), 456.789f);
	named_ref->setStr(RefK("DebugParam3"), "New String");
	named_ref->set<short>(RefK("DebugParam4"), 12345);
	named_ref->setInt(RefK("DebugParam5"), 67890);
	{
		int id = 20;
		CRefW<CSceneObjDummy> obj(named_ref, RefK("SceneObj", id));
		if (obj.isExist())
		{
			obj->data1 = 321;
			obj->data2 = 987.654f;
		}
		named_ref->setInt(RefK("SceneObj::Data3", id), 987654);
	}
}

//----------------------------------------
//テスト関数④：名前付きデータ参照を使ってデータを演算１
void testCalcNamedRef1()
{
	CNamedRefSingleton named_ref;
	named_ref->reverseBool(RefK("DebugCpuMeter"));
	named_ref->incInt(RefK("DebugParam1"));
	named_ref->addFloat(RefK("DebugParam2"), 100.f);
	named_ref->mul<short>(RefK("DebugParam4"), 2);
	named_ref->reverseInt(RefK("DebugParam5"));
	{
		int id = 20;
		named_ref->xorInt(RefK("SceneObj::Data3", id), 0xffff);
	}
}

//----------------------------------------
//テスト関数⑤：名前付きデータ参照を使ってデータを演算２
void testCalcNamedRef2()
{
	CNamedRefSingleton named_ref;
	named_ref->reverseBool(RefK("DebugCpuMeter"));
	named_ref->decInt(RefK("DebugParam1"));
	named_ref->subFloat(RefK("DebugParam2"), 100.f);
	named_ref->div<short>(RefK("DebugParam4"), 2);
	named_ref->reverseInt(RefK("DebugParam5"));
	{
		int id = 20;
		named_ref->xorInt(RefK("SceneObj::Data3", id), 0xffff);
	}
}

//----------------------------------------
//テスト関数⑥：名前付きデータ参照を使ってデータを演算３
void testCalcNamedRef3()
{
	CNamedRefSingleton named_ref;
	named_ref->setInt(RefK("DebugParam1"), 0x33);
	named_ref->setInt(RefK("DebugParam5"), 0xf0);
	named_ref->andInt(RefK("DebugParam1"), 0x7);
	named_ref->orInt(RefK("DebugParam5"), 0xf);
}

//----------------------------------------
//テスト関数⑦：名前付きデータ参照が内部で保持する参照をリセット
//※見た目に何の影響はないが、次回なんらかの処理時に参照を再取得する。
//※データが消えたり登録が削除されたりするわけではない。
//※2回目以降のアクセスを高速化するために内部で保持している参照（ポインタ）をクリアするだけ。
//※メモリ再配置や、データの削除が行われた場合に実行する必要がある。
//※サンプルでは全体リセットだが、個別のリセットも可能。
//※アクセッサタイプには何の影響もない。
void testResetRefAll()
{
	CNamedRefSingleton named_ref;
	named_ref->resetRefAll();
}

//----------------------------------------
//テスト関数⑧：一部の名前付きデータ参照を登録解除
void testUnregistNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->unregist(RefK("DebugParam1"));
	named_ref->unregist(RefK("DebugParam3"));
	named_ref->unregist(RefK("DebugParam5"));
	named_ref->unregist(RefK("SceneObj", 20));
	named_ref->unregist(RefK("SceneObj::Data3", 20));
}

//----------------------------------------
//テスト関数⑨：全ての名前付きデータ参照を登録解除
void testUnregistRefAll()
{
	CNamedRefSingleton named_ref;
	named_ref->unregistAll();
}

//----------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	printf("sizeof(CNamedRef)=%d\n", sizeof(CNamedRef));
	printf("sizeof(CNamedRefSingleton)=%d\n", sizeof(CNamedRefSingleton));
	
	//テスト①：名前付きデータ参照を登録
	printf("----- regist -----\n");
	testRegistNamedRef();
	//テスト②：名前付きデータ参照を使ってデータを表示
	testPrintNamedRef();
	
	//テスト③：名前付きデータ参照を使ってデータを更新
	printf("----- set value -----\n");
	testUpdateNamedRef();
	testPrintNamedRef();
	
	//テスト④：名前付きデータ参照を使ってデータを演算１
	printf("----- reset-ref all -----\n");
	testResetRefAll();
	testPrintNamedRef();
	
	//テスト⑤：名前付きデータ参照を使ってデータを演算２
	printf("----- calc value (1) -----\n");
	testCalcNamedRef1();
	testPrintNamedRef();
	
	//テスト⑥：名前付きデータ参照を使ってデータを演算３
	printf("----- calc value (2) -----\n");
	testCalcNamedRef2();
	testPrintNamedRef();
	
	//テスト関数⑦：名前付きデータ参照が内部で保持する参照をリセット
	printf("----- calc value (3) -----\n");
	testCalcNamedRef3();
	testPrintNamedRef();
	
	//テスト関数⑧：一部の名前付きデータ参照を登録解除
	printf("----- unregist -----\n");
	testUnregistNamedRef();
	testPrintNamedRef();
	
	//テスト関数⑨：全ての名前付きデータ参照を登録解除
	printf("----- unregist all -----\n");
	testUnregistRefAll();
	testPrintNamedRef();
	
	return EXIT_SUCCESS;
}

// End of file
