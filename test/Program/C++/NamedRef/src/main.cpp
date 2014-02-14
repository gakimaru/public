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

//【暫定】C++11のハッシュテーブルライブラリ
#include <unordered_map>

template<std::size_t MAX>
class CNamedRefT
{
public:
	static const int MAX_MAP = MAX;
public:
	typedef unsigned long long KeyPrim;
	struct Key
	{
		union
		{
			KeyPrim m_prim;
			struct
			{
				unsigned int m_main;
				unsigned int m_sub;
			};
		};
		operator KeyPrim() const { return m_prim; }
		unsigned int CRC32(const char* name)
		{
			return reinterpret_cast<unsigned long>(name);//ダミー
		}
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
	};
private:
	struct RefNodeCore
	{
		virtual void* getRefFromFunctor() const = 0;
		template<typename T>
		void* getRefCore() const
		{
			ASSERT(typeid(T) == m_type, "This type is not match.");
			if (typeid(T) != m_type)
				return nullptr;
			if (!m_ref)
				m_ref = getRefFromFunctor();
			return m_ref;
		}
		template<typename T>
		T* getRef(){ return static_cast<T*>(getRefCore<T>()); }
		template<typename T>
		const T* getRef() const { return static_cast<T*>(getRefCore<T>()); }
		template<typename T>
		T getVal() const { void* p = getRefCore<T>(); return p == nullptr ? static_cast<T>(0) : *static_cast<T*>(p); }
		template<typename T>
		void setVal(const T value){ void* p = getRefCore<T>(); if (p){ *static_cast<T*>(p) = value; } }
		void resetRef(){ m_ref = nullptr; }
		void rLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const { CRWLockHelper(m_lock).rLock(spin_count); }
		void wLock(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const { CRWLockHelper(m_lock).wLock(spin_count); }
		void rUnlock() const { CRWLockHelper(m_lock).rUnlock(); }
		void wUnlock() const { CRWLockHelper(m_lock).wUnlock(); }
		RefNodeCore(const Key& key, const type_info& type) :
			m_key(key),
			m_type(type),
			m_ref(nullptr),
			m_lock()
		{}
		virtual ~RefNodeCore()
		{}
		const Key m_key;
		const type_info& m_type;
		mutable void* m_ref;
		mutable CRWLock m_lock;
	};
	template <typename F>
	struct RefNode : public RefNodeCore
	{
		F m_getRefFunctor;
		void* getRefFromFunctor() const override
		{
			return m_getRefFunctor(m_key);
		}
		RefNode(const Key& key) :
			RefNodeCore(key, typeid(F::TYPE))
		{}
		~RefNode() override
		{
		}
	};
	struct getRefFunctorDummy{ typedef int TYPE; TYPE* operator()(const Key& key) const { return nullptr; } };
	using NamedRefTable = std::unordered_map<KeyPrim, RefNodeCore*>;
	using RefNodeDummy = RefNode<getRefFunctorDummy>;
public:
	template<typename T>
	class RefR
	{
	public:
		const T* operator->() const { return m_ref; }
		T operator*() const { return *m_ref; }
		bool isExist() const { return m_isExist; }
	public:
		RefR(CNamedRefT<MAX>& map, const Key key, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_propRef(map.get(key, &m_isExist)),
			m_ref(nullptr)
		{
			if (m_propRef)
			{
				m_ref = m_propRef->getRef<T>();
				if (m_ref)
					m_propRef->rLock(spin_count);
			}
		}
		~RefR()
		{
			if (m_propRef && m_ref)
				m_propRef->rUnlock();
		}
	private:
		const RefNodeCore* m_propRef;
		const T* m_ref;
		bool m_isExist;
	};
	template<typename T>
	class RefW
	{
	public:
		T* operator->(){ return m_ref; }
		const T* operator->() const { return m_ref; }
		T operator*() const { return *m_ref; }
		bool isExist() const { return m_isExist; }
	public:
		RefW(CNamedRefT<MAX>& map, const Key key, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) :
			m_propRef(map.get(key, &m_isExist)),
			m_ref(nullptr)
		{
			if (m_propRef)
			{
				m_ref = m_propRef->getRef<T>();
				if (m_ref)
					m_propRef->wLock(spin_count);
			}
		}
		~RefW()
		{
			if (m_propRef && m_ref)
				m_propRef->wUnlock();
		}
	private:
		RefNodeCore* m_propRef;
		T* m_ref;
		bool m_isExist;
	};
public:
	template<typename F>
	bool regist(const Key key, F functor)
	{
		RefNode<F>* ref = m_allocator.create< RefNode<F> >(key);
		if (!ref)
			return false;
		m_namedRefList.insert(std::make_pair(key, ref));
		return true;
	}
	bool unregist(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = get(key, is_exist);
		if (!ref)
			return false;
		{
			ref->wLock(spin_count);
			m_namedRefList.erase(name);
			ref->wUnlock();
		}
		m_allocator.remove(ref);
		return true;
	}
	void unregistAll(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;
			{
				ref->wLock(spin_count);
				node.second = nullptr;
				ref->wUnlock();
			}
			m_allocator.remove(ref);
		}
		m_namedRefList.clear();
	}
	void resetRef(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = get(key, is_exist);
		if (!ref)
			return;
		{
			ref->wLock(spin_count);
			ref->resetRef();
			ref->wUnlock();
		}
	}
	void resetRefAll(const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;
			{
				ref->wLock(spin_count);
				ref->resetRef();
				ref->wUnlock();
			}
		}
	}
private:
	inline const RefNodeCore* getCore(const Key key, bool* is_exist) const
	{
		NamedRefTable::const_iterator node = m_namedRefList.find(key);
		if (node == m_namedRefList.end())
		{
			if (is_exist)
				*is_exist = true;
			return nullptr;
		}
		if (is_exist)
			*is_exist = false;
		return node->second;
	}
	inline const RefNodeCore* get(const Key key, bool* is_exist) const
	{
		const RefNodeCore* ref = getCore(key, is_exist);
		return ref;
	}
	inline RefNodeCore* get(const Key key, bool* is_exist)
	{
		const RefNodeCore* ref = getCore(key, is_exist);
		return const_cast<RefNodeCore*>(ref);
	}
public:
	template<typename T>
	T getVal(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		const RefNodeCore* ref = get(key, is_exist);
		if (!ref)
			return static_cast<T>(0);
		ref->rLock(spin_count);
		T val = ref->getVal<T>();
		ref->rUnlock();
		return val;
	}
	bool getBool(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return getVal<bool>(key, is_exist, spin_count);
	}
	int getInt(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return getVal<int>(key, is_exist, spin_count);
	}
	float getFloat(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return getVal<float>(key, is_exist, spin_count);
	}
	const char* getStr(const Key key, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT) const
	{
		return getVal<const char*>(key, is_exist, spin_count);
	}
	template<typename T>
	bool setVal(const Key key, const T value, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		RefNodeCore* ref = get(key, is_exist);
		if (!ref)
			return false;
		ref->wLock(spin_count);
		ref->setVal<T>(value);
		ref->wUnlock();
		return true;
	}
	bool setBool(const Key key, const bool value, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return setVal<bool>(key, value, is_exist, spin_count);
	}
	bool setInt(const Key key, const int value, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return setVal<int>(key, value, is_exist, spin_count);
	}
	bool setFloat(const Key key, const float value, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return setVal<float>(key, value, is_exist, spin_count);
	}
	bool setStr(const Key key, const char* str, bool* is_exist = nullptr, const int spin_count = CSpinLock::DEFAULT_SPIN_COUNT)
	{
		return setVal<const char*>(key, str, is_exist, spin_count);
	}
	bool isExist(const Key key) const
	{
		bool is_exist;
		const RefNodeCore* ref = get(key, &is_exist);
		return is_exist;
	}

public:
	CNamedRefT()
	{
		m_namedRefList.reserve(MAX_MAP);
	}
	~CNamedRefT()
	{
		unregistAll();
	}
private:
	CBlockAllocator<MAX_MAP, sizeof(RefNodeDummy)> m_allocator;
	NamedRefTable m_namedRefList;
};
template <std::size_t MAX, int ID = 0>
class CNamedRefSingletonT
{
public:
	static const int INSTANCE_ID = ID;
	typedef CNamedRefT<MAX> NamedRef;
public:
	operator NamedRef&() { return m_namedRef; }
	const NamedRef* operator->() const { return &m_prosMap; }
	NamedRef* operator->(){ return &m_namedRef; }
private:
	static NamedRef m_namedRef;
};

using CNamedRefSingleton = CNamedRefSingletonT<100>;
using CNamedRef = CNamedRefSingleton::NamedRef;
using RefKey = CNamedRef::Key;
template <typename T>
using CRefR = CNamedRef::RefR<T>;
template <typename T>
using CRefW = CNamedRef::RefW<T>;

//インスタンス化
CNamedRef CNamedRefSingleton::m_namedRef;

struct CSceneObjDummy
{
	int id;
	const char* name;
	int data1;
	float data2;
};
static bool s_debugCpuMeter = false;
static int s_debugParam1 = 1;
static float s_debugParam2 = 2.f;
static const char* s_debugParam3 = "TEST";
static CSceneObjDummy s_sceneObjDummy[] =
{
	{ 1, "太郎", 10, 11.1f },
	{ 2, "次郎", 20, 22.2f },
	{ 3, "三郎", 30, 33.3f }
};
static CSceneObjDummy* searchSceneObj(const int id)
{
	for (auto& o : s_sceneObjDummy)
	{
		if (o.id == id)
			return &o;
	}
	return nullptr;
}

const char* boolToStr(const bool value){ return value ? "true" : "false"; }

void testRegistNamedRef()
{
	//struct refDebugCpuMeter{ typedef (型名) TYPE; TYPE* operator()(const RefKey& key) const { return (データの参照); } };
	struct refDebugCpuMeter{ typedef bool TYPE; TYPE* operator()(const RefKey& key) const { return &s_debugCpuMeter; } };
	struct refDebugParam1{ typedef int TYPE; TYPE* operator()(const RefKey& key) const { return &s_debugParam1; } };
	struct refDebugParam2{ typedef float TYPE; TYPE* operator()(const RefKey& key) const { return &s_debugParam2; } };
	struct refDebugParam3{ typedef const char*TYPE; TYPE* operator()(const RefKey& key) const { return &s_debugParam3; } };
	struct refSceneObjDummy{ typedef CSceneObjDummy TYPE; TYPE *operator()(const RefKey& key) const { return searchSceneObj(key.m_sub); } };
	
	CNamedRefSingleton named_ref;
	named_ref->regist(RefKey("DebugCpuMeter"), refDebugCpuMeter());
	named_ref->regist(RefKey("DebugParam1"), refDebugParam1());
	named_ref->regist(RefKey("DebugParam2"), refDebugParam2());
	named_ref->regist(RefKey("DebugParam3"), refDebugParam3());
	named_ref->regist(RefKey("SceneObj", 1), refSceneObjDummy());
	named_ref->regist(RefKey("SceneObj", 2), refSceneObjDummy());
	named_ref->regist(RefKey("SceneObj", 3), refSceneObjDummy());
}

void testPrintNamedRef()
{
	CNamedRefSingleton named_ref;
	printf("DebugCpuMeter=%s\n", boolToStr(named_ref->getBool(RefKey("DebugCpuMeter"))));
	printf("DebugParam1=%d\n", named_ref->getInt(RefKey("DebugParam1")));
	printf("DebugParam2=%.3f\n", named_ref->getFloat(RefKey("DebugParam2")));
	printf("DebugParam3=\"%s\"\n", named_ref->getStr(RefKey("DebugParam3")));
	for (int id : {1, 2, 3} )
	{
		CRefR<CSceneObjDummy> obj(named_ref, RefKey("SceneObj", id));
		printf("SceneObj[id=%d]: {name\"%s\", data1=%d, data2=%.3f}\n", obj->id, obj->name, obj->data1, obj->data2);
	}
}

void testUpdateNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->setBool(RefKey("DebugCpuMeter"), true);
	named_ref->setInt(RefKey("DebugParam1"), 123);
	named_ref->setFloat(RefKey("DebugParam2"), 456.789f);
	named_ref->setStr(RefKey("DebugParam3"), "New String");
	{
		CRefW<CSceneObjDummy> obj(named_ref, RefKey("SceneObj", 2));
		obj->data1 = 321;
		obj->data2 = 987.654f;
	}
}

void testResetRefAll()
{
	CNamedRefSingleton named_ref;
	named_ref->resetRefAll();
}

int main(const int argc, const char* argv[])
{
	testRegistNamedRef();
	testPrintNamedRef();
	testUpdateNamedRef();
	testResetRefAll();
	testPrintNamedRef();
	return EXIT_SUCCESS;
}

// End of file
