#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//C++11ライブラリ
#include <thread>//スレッド
#include <mutex>//ミューテックス
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
	if(!(expr)) \
	{ \
		DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
		                "  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
						"  "  msg "\n", __VA_ARGS__); \
		BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//削除用
//#include <assert.h>//assert用
//#define ASSERT(expr, msg, ...) assert(expr)//VC++標準版

//静的アサーション
//※C++11仕様
//※日本語使用不可
#define STATIC_ASSERT(expr, msg) static_assert(expr, msg)
//#define STATIC_ASSERT(expr, msg)//削除用

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
	void destroy(T*& p)
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
//シングルトンクラス
//※現状は可読性重視だが、実際にはテンプレートのインスタンス化による
//　プログラムサイズの肥大を考慮し、非テンプレートの共通処理を
//　切り出す必要がある

//----------------------------------------
//クラス宣言
//※friend宣言のための事前宣言

//共通シングルトンテンプレート　※継承専用
template<class T, class U>
class CSingletonCommon;

//通常シングルトンテンプレートクラス
template<class T>
class CSingleton;

//管理シングルトンテンプレートクラス
template<class T>
class CManagedSingleton;

//【シングルトン用ヘルパー】シングルトンプロキシーテンプレートクラス　※継承専用
template<class T>
class CSingletonProxy;

//【シングルトン用ヘルパー】シングルトンイニシャライザーテンプレートクラス
template<class T>
class CSingletonInitializer;

//【シングルトン用ヘルパー】シングルトンアクセステンプレートクラス
template<class T>
class CSingletonUsing;

//----------------------------------------
//シングルトン処理用定数定義
class CSingletonConst
{
public:
	//定数定義

	//シングルトン属性
	enum E_ATTR
	{
		ATTR_AUTO_CREATE,             //自動生成（破棄しない）
		ATTR_AUTO_CREATE_AND_DELETE,  //自動生成と自動破棄
		ATTR_MANUAL_CREATE_AND_DELETE,//手動生成と手動破棄
	};
	//スレッドセーフ宣言
	enum E_IS_THREAD_SAFE
	{
		IS_THREAD_SAFE = true,//スレッドセーフ宣言
		IS_NOT_THREAD_SAFE = false,//非スレッドセーフ宣言
	};
	//管理シングルトン宣言
	enum E_IS_MANAGED_SINGLETON
	{
		IS_NORMAL_SINGLETON = false,//通常シングルトン宣言
		IS_MANAGED_SINGLETON = true,//管理シングルトン宣言
	};
	//シングルトン生成済み状態
	enum E_IS_CREATED
	{
		IS_NOT_CREATED = false,//未生成
		IS_CREATED = true,//生成済み
	};
	//強制処理指定
	enum E_IS_FORCED
	{
		IS_FORCED = true,//強制
		IS_NORMAL = false,//通常
	};
	//ファイナライズ処理指定
	enum E_IS_FINALIZE
	{
		IS_FINALIZE = true,//ファイナライズ
		IS_RELEASE = false,//参照カウンタリリース
	};
	//シングルトンイニシャライザー指定
	enum E_IS_INITIALIZER
	{
		IS_INITIALIZER = true,//シングルトンイニシャライザー
		IS_USING = false,//シングルトンアクセス
	};
public:
	//データ型
	
	//【テンプレートクラスの挙動を宣言し、静的アサーション（static_assert）を行うための構造体】
	//コンパイル動作設定用構造体：通常シングルトン宣言
	struct AUTO_SINGLETON_TYPE
	{
		static const E_IS_MANAGED_SINGLETON THIS_IS_MANAGED_SINGLETON = IS_NORMAL_SINGLETON;
	};
	//コンパイル動作設定用構造体：管理シングルトン宣言
	struct MANAGED_SINGLETON_TYPE
	{
		static const E_IS_MANAGED_SINGLETON THIS_IS_MANAGED_SINGLETON = IS_MANAGED_SINGLETON;
	};
public:
	//メソッド
	//【定数文字列化】シングルトン属性
	static const char* Attr_ToStr(const E_ATTR attr)
	{
		#define CASE_TO_STR(x) case ATTR_##x: return #x; break;
		switch (attr)
		{
		CASE_TO_STR(AUTO_CREATE);
		CASE_TO_STR(AUTO_CREATE_AND_DELETE);
		CASE_TO_STR(MANUAL_CREATE_AND_DELETE);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//【定数文字列化】スレッドセーフ宣言
	static const char* IsThreadSafe_ToStr(const E_IS_THREAD_SAFE is_thread_safe)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_thread_safe)
		{
		CASE_TO_STR(IS_THREAD_SAFE);
		CASE_TO_STR(IS_NOT_THREAD_SAFE);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//【定数文字列化】管理シングルトン宣言
	static const char* IsManagedSingleton_ToStr(const E_IS_MANAGED_SINGLETON is_managed_singleton)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_managed_singleton)
		{
		CASE_TO_STR(IS_MANAGED_SINGLETON);
		CASE_TO_STR(IS_NORMAL_SINGLETON);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//【定数文字列化】シングルトン生成済み状態
	static const char* IsCreated_ToStr(const E_IS_CREATED is_created)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_created)
		{
		CASE_TO_STR(IS_CREATED);
		CASE_TO_STR(IS_NOT_CREATED);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//【定数文字列化】強制処理指定
	static const char* IsForced_ToStr(const E_IS_FORCED is_forced)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_forced)
		{
		CASE_TO_STR(IS_FORCED);
		CASE_TO_STR(IS_NORMAL);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//【定数文字列化】ファイナライズ指定
	static const char* IsFinalize_ToStr(const E_IS_FINALIZE is_finalize)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_finalize)
		{
		CASE_TO_STR(IS_FINALIZE);
		CASE_TO_STR(IS_RELEASE);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//【定数文字列化】イニシャライザー指定
	static const char* IsInitializer_ToStr(const E_IS_INITIALIZER is_initializer)
	{
		#define CASE_TO_STR(x) case x: return #x; break;
		switch (is_initializer)
		{
		CASE_TO_STR(IS_INITIALIZER);
		CASE_TO_STR(IS_USING);
		}
		#undef CASE_TO_STR
		return "(unknown)";
	}
	//【定数文字列化】論理値
	static const char* Bool_ToStr(const bool flag)
	{
		return flag ? "TRUE" : "FALSE";
	}
};

//----------------------------------------
//共通シングルトンテンプレートクラス　※継承専用
template<class T, class U>
class CSingletonCommon
{
	//フレンドクラス
	friend class CSingleton<T>;
	friend class CManagedSingleton<T>;
	friend class CSingletonProxy<T>;
	friend class CSingletonInitializer<T>;
	friend class CSingletonUsing<T>;
public:
	//シングルトン設定をテンプレート引数のクラスに基づいて静的に確定
	//※クラス T には、定数 CLASS_NAME, SINGLETON_ATTR, IS_THREAD_SAFE が定義されている必要がある。
	//※クラス U には、定数 THIS_IS_MANAGED_SINGLETON が定義されている必要がある。
	//static const char* T::CLASS_NAME;//クラス名 ※char*型のため、クラスの静的な値として反映できない
	static const CSingletonConst::E_ATTR THIS_SINGLETON_ATTR = T::SINGLETON_ATTR;//シングルトン属性
	static const CSingletonConst::E_IS_THREAD_SAFE THIS_IS_THREAD_SAFE = T::THIS_IS_THREAD_SAFE;//スレッドセーフ宣言
	static const CSingletonConst::E_IS_MANAGED_SINGLETON THIS_IS_MANAGED_SINGLETON = U::THIS_IS_MANAGED_SINGLETON;//管理シングルトン宣言
	
	//【静的アサーション】通常シングルトンでは、「手動生成属性：ATTR_MANUAL_CREATE_AND_DELETE」を使用するとアサーション違反
	STATIC_ASSERT(THIS_IS_MANAGED_SINGLETON == CSingletonConst::IS_NORMAL_SINGLETON && THIS_SINGLETON_ATTR != CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE ||
		          THIS_IS_MANAGED_SINGLETON != CSingletonConst::IS_NORMAL_SINGLETON,
		"CSingleton<T> is not supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");

	//【静的静的アサーション】管理シングルトンでは、「手動生成属性：ATTR_MANUAL_CREATE_AND_DELETE」以外を使用するとアサーション違反
	STATIC_ASSERT(THIS_IS_MANAGED_SINGLETON == CSingletonConst::IS_MANAGED_SINGLETON && THIS_SINGLETON_ATTR == CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE ||
		          THIS_IS_MANAGED_SINGLETON != CSingletonConst::IS_MANAGED_SINGLETON,
		"CManagedSingleton<T> is only supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");
	
private:
	//インスタンス生成・破棄用配置new/delete
	//※new は内部で持つ static バッファのポインタを返すだけ
	//※delete は何もしない
	//※コンストラクタ、デストラクタを実行して、オブジェクトの初期化・終了処理を実行することが目的
	void* operator new(const size_t size){ return m_buff; }
	void operator delete(void*){}
public:
	//アクセッサ
	const char* getClassName() const { return T::CLASS_NAME; }//クラス名取得
	CSingletonConst::E_ATTR getAttr() const { return THIS_SINGLETON_ATTR; }//シングルトン属性取得
	const char* getAttr_Named() const { return CSingletonConst::Attr_ToStr(getAttr()); }//シングルトン属性名取得（デバッグ用）
	CSingletonConst::E_IS_THREAD_SAFE isThreadSafe() const { return THIS_IS_THREAD_SAFE; }//スレッドセーフ宣言取得
	const char* isThreadSafe_Named() const { return CSingletonConst::IsThreadSafe_ToStr(isThreadSafe()); }//スレッドセーフ宣言名取得（デバッグ用）
	CSingletonConst::E_IS_MANAGED_SINGLETON isManagedSingleton() const { return THIS_IS_MANAGED_SINGLETON; }//管理シングルトン宣言取得
	const char* isManagedSingleton_Named() const { return CSingletonConst::IsManagedSingleton_ToStr(isManagedSingleton()); }//管理シングルトン宣言名取得（デバッグ用）
	CSingletonConst::E_IS_CREATED isCreated() const { return m_this.load() != nullptr ? CSingletonConst::IS_CREATED : CSingletonConst::IS_NOT_CREATED; }//クラス(T)インスタンス生成済み状態取得
	const char* isCreated_Named() const { return CSingletonConst::IsCreated_ToStr(isCreated()); }//クラス(T)インスタンス生成済み状態名取得（デバッグ用）
private:
	T* getThis() { return m_this.load(); }//クラス(T)インスタンスの参照を取得（禁止）
	const T* getThis() const { return m_this.load(); }//クラス(T)インスタンスのconst参照を取得（禁止）
public:
	int getRefCount() const { return m_refCount.load(); }//参照カウンタ取得
	int getRefCountMax() const { return m_refCountMax.load(); }//参照カウンタの最大到達値を取得
	int getRefCountOnThread() const { return m_refCountOnThread; }//現在のスレッド内の参照カウンタ数を取得
	int getThreadCount() const { return m_threadCount.load(); }//参照スレッド数取得
	int getThreadCountMax() const { return m_threadCountMax.load(); }//参照スレッド数の最大到達値を取得
	THREAD_ID getCreatedThreadID() const { return m_createdThreadId; }//クラス(T)インスタンスを生成したスレッドのスレッドIDを取得
	const char* getCreatedThreadName() const { return m_createdThreadName; }//クラス(T)インスタンスを生成したスレッドのスレッド名を取得
public:
	//オペレータ
	T* operator->(){ return m_this.load(); }//アロー演算子：シングルトンクラスがクラス(T)のインスタンスを偽装（代理）する
	const T* operator->() const { return m_this.load(); }//const アロー演算子：（同上）
private:
	//オペレータ（禁止）
	T& operator*(){ return *m_this.load(); }//ポインタ演算子（禁止）
	const T& operator*() const { return *m_this.load(); }//constポインタ演算子（禁止）
	operator T*(){ return m_this.load(); }//クラス T* キャスト演算子（禁止）
	operator const T*() const { return m_this.load(); }//クラスconst T* キャスト演算子（禁止）
	operator T&(){ return *m_this.load(); }//クラス T& キャスト演算子（禁止）
	operator const T&() const { return *m_this.load(); }//クラス const T& キャスト演算子（禁止）
	CSingletonCommon<T, U>& operator=(const CSingletonCommon<T, U>&){ return *this; }//コピー演算子（禁止）
	CSingletonCommon<T, U>& operator=(const CSingletonCommon<T, U>*){ return *this; }//コピー演算子（禁止）
	CSingletonCommon<T, U>& operator=(const T&){ return *this; }//コピー演算子（禁止）
	CSingletonCommon<T, U>& operator=(const T*){ return *this; }//コピー演算子（禁止）
private:
	//コピーコンストラクタ（禁止）
	explicit CSingletonCommon(CSingletonCommon<T, U>&){}
	explicit CSingletonCommon(CSingletonCommon<T, U>*){}
	explicit CSingletonCommon(T&){}
	explicit CSingletonCommon(T*){}
private:
	//参照カウンタのカウントアップ
	//※最初のカウントアップ時にインスタンスを生成
	//※なるべくロックフリーにするためにカウンタの判定は演算後の値のみを用いている
	//　...が、結局インスタンスの生成を確実に待たせる必要があるので、結局全体をロックする。
	//※「自動生成属性：ATTR_AUTO_CREATE」の時は、CallOnceにより初期化の衝突を保護
	//　... が、当初の予定に反してスレッドセーフをより強化したので、CallOnceは廃止。
	//　参考用に CallOnce を使用する場合の処理をコメントとして残す。
	//※C++11仕様の可変長テンプレートを使用し、クラス T をインスタンス化する際に、
	//　任意のパラメータを与えることを可能にしている。
	//　C++11非対応のコンパイラでは、クラス T にデフォルトコンストラクタしか
	//　使えないものとする。
	template<typename... Tx>
	bool addRef(Tx... nx)
	{
		//インスタンス生成用ラムダ式
		//※可変長テンプレート引数を使用した関数の仮引数を、ラムダ式の外部参照に指定している
		auto creator = [&nx...](bool& is_created)
		{
			if (m_this.load() == nullptr)
			{
				//クラス内 配置 new を利用し、static 領域を割り当て
				//※可変長テンプレート引数を使用した関数の仮引数を受け渡し
				m_this.store(new T(nx...));

				//生成時情報を記録
				{
					CThreadID thread_id;//現在のスレッド情報
					m_createdThreadId = thread_id.getID();//スレッドID記録
					m_createdThreadName = thread_id.getName();//スレッド名記録
					is_created = true;//生成OK
				}
			}
		};
		//参照カウンタカウントアップ（共通処理）
		return addRefCore(creator);
	}
	//参照カウンタのカウントアップ
	//※インスタンスを生成しない
	bool addRefWitoutCreate()
	{
		//インスタンス生成用ラムダ式（ダミー）
		auto creator_dummy = [](bool& is_created)
		{
		};
		//参照カウンタカウントアップ（共通処理）
		return addRefCore(creator_dummy);
	}
	//参照カウンタのカウントアップ（共通処理部）
	//※実際のインスタンス生成処理部はラムダ式で受け取る
	//※ラムダ式を受け取るためにテンプレート関数化している
	template<typename L>
	bool addRefCore(L& creator)
	{
		//カウントアップ済み判定
		if (m_isCounted)
			return false;
		m_isCounted = true;
		
		//ロック取得
		m_instanceLock.lock();

		//参照カウンタをカウントアップ
		bool is_allow_create = false;//インスタンス生成許可フラグ
		{
			const int ref_count_prev = m_refCount.fetch_add(1);//カウントアップ
			const int ref_count_now = ref_count_prev + 1;
			if (ref_count_prev == 0)
				is_allow_create = true;//初めてのカウントアップ時にインスタンス生成

			//最大到達値を記録
			if (m_refCountMax.load() < ref_count_now)
				m_refCountMax.store(ref_count_now);
		}

		//スレッド内参照数をカウントアップ
		{
			const int ref_count_on_thread_prev = m_refCountOnThread++;
			if (ref_count_on_thread_prev == 0)
			{
				//初めてのカウントアップ時に参照スレッド数をカウントアップ
				const int thread_count_prev = m_threadCount.fetch_add(1);
				const int thread_count_now = thread_count_prev + 1;

				//最大到達値を記録
				if (m_threadCountMax.load() < thread_count_now)
					m_threadCountMax.store(thread_count_now);
			}
		}

		//インスタンス生成
		bool is_created = false;//生成済みフラグ
		if (is_allow_create)
		{
		//※CallOnce廃止
		//	//「自動生成属性：ATTR_AUTO_CREATE」の時は CallOnce で生成
		//	if (THIS_SINGLETON_ATTR == CSingletonConst::ATTR_AUTO_CREATE)
		//	{
		//		std::call_once(m_once, creator, is_created);
		//	}
		//	//「自動生成属性：ATTR_AUTO_CREATE」以外の時は普通に生成
		//	else
		//	{
		//		creator(is_created);
		//	}
			//常に普通にインスタンス生成
			creator(is_created);
		}

		//ロック解放
		m_instanceLock.unlock();

		//インスタンス生成を行ったかどうかを返す
		return is_created;
	}
	//参照カウンタのカウントダウン
	//※最後のカウントダウン時にインスタンスを破棄
	//※なるべくロックフリーにするためにカウンタの判定は演算後の値のみを用いている
	//　...が、結局インスタンスの生成を確実に待たせる必要があるので、結局全体をロックする。
	bool release()
	{
		//カウントアップ済み判定
		if (!m_isCounted)
			return false;
		m_isCounted = false;

		//ロック取得
		m_instanceLock.lock();

		//参照カウンタをカウントダウン
		bool is_allow_delete = false;//インスタンス破棄許可フラグ
		{
			const int ref_count_prev = m_refCount.fetch_sub(1);//カウントダウン
			const int ref_count_now = ref_count_prev - 1;
			if (ref_count_now == 0)
				is_allow_delete = true;//最後のカウントダウン時にインスタンス破棄
		}
		
		//スレッド内参照数をカウントダウン
		{
			const int ref_count_on_thread_now = --m_refCountOnThread;
			if (ref_count_on_thread_now == 0)
			{
				//カウント 0 時に参照スレッド数をカウントダウン
				if (m_threadCount.load() > 0)
				{
					m_threadCount.fetch_sub(1);
				}
			}
		}

		//インスタンス破棄
		bool is_deleted = false;//破棄済みフラグ
		if (is_allow_delete)
		{
			//「自動生成・破棄属性：ATTR_AUTO_CREATE_AND_DELETE」の時だけ自動破棄
			if (THIS_SINGLETON_ATTR == CSingletonConst::ATTR_AUTO_CREATE_AND_DELETE)
			{
				//インスタンス破棄（共通処理利用）
				is_deleted = deleteThisCore();
			}
		}

		//ロック解放
		m_instanceLock.unlock();

		//インスタンス破棄を行ったかどうかを返す
		return is_deleted;
	}
	//手動破棄
	//※参照カウンタは更新しない
	bool deleteThis()
	{
		//カウントアップ済み状態解放
		m_isCounted = false;
		
		//ロック取得
		m_instanceLock.lock();

		//インスタンス破棄（共通処理利用）
		const bool is_deleted = deleteThisCore();

		//ロック解放
		m_instanceLock.unlock();

		//インスタンス破棄を行ったかどうかを返す
		return is_deleted;
	}
	//破棄（共通部）
	bool deleteThisCore()
	{
		//インスタンス破棄
		bool is_deleted = false;//破棄済みフラグ
		if (m_this.load() != nullptr)
		{
			//インスタンスを破棄
			delete m_this.load();
			m_this.store(nullptr);

			//生成時情報をリセット
			m_createdThreadId = INVALID_THREAD_ID;//スレッドID
			m_createdThreadName = nullptr;//スレッド名
			is_deleted = true;//破棄OK
		}

		//インスタンス破棄を行ったかどうかを返す
		return is_deleted;
	}
private:
	//通常シングルトン用コンストラクタ
	//※コンストラクタで自動的に参照カウンタをカウントアップし、インスタンスを生成する。
	//※C++11仕様の可変長テンプレートを使用し、クラス T をインスタンス化する際に、
	//　コンストラクタに任意のパラメータを与えることを可能にしている。
	//　C++11非対応のコンパイラでは、クラス T にデフォルトコンストラクタしか
	//　使えないものとする。
	template<typename... Tx>
	CSingletonCommon(CSingleton<T>*, Tx... nx) :
		m_isCounted(false)
	{
		//【アサーション】通常シングルトンでは、「手動生成属性：ATTR_MANUAL_CREATE_AND_DELETE」を使用するとアサーション違反（処理続行可）
		ASSERT(THIS_SINGLETON_ATTR != CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE,
			"CSingleton<T> is not supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");

		//【アサーション】インスタンス生成済みの場合、スレッドセーフじゃないクラスに対して、生成時と異なるスレッドからアクセスするとアサーション違反（処理続行可）
		CThreadID this_thread;
		ASSERT(m_createdThreadId == INVALID_THREAD_ID ||
		       THIS_IS_THREAD_SAFE == CSingletonConst::IS_THREAD_SAFE ||
		       THIS_IS_THREAD_SAFE == CSingletonConst::IS_NOT_THREAD_SAFE && m_createdThreadId == this_thread.getID(),
			   "CSingleton<T> is not thread safe. Create thread and this thread are different.");

		//参照カウンタをカウントアップ
		//※初めてのカウントアップならインスタンスを生成する
		addRef(nx...);
	}
	//管理シングルトン用コンストラクタ
	//※コンストラクタで参照カウンタを更新せず、インスタンスを生成しない。
	CSingletonCommon(CManagedSingleton<T>*) :
		m_isCounted(false)
	{
		//【アサーション】管理シングルトンでは、「手動生成属性：ATTR_MANUAL_CREATE_AND_DELETE」以外を使用するとアサーション違反（処理続行可）
		ASSERT(THIS_SINGLETON_ATTR == CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE,
			"CManagedSingleton<T> is only supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");
		
		//【アサーション】インスタンス生成済みの場合、スレッドセーフじゃないクラスに対して、生成時と異なるスレッドからアクセスするとアサーション違反（処理続行可）
		CThreadID this_thread;
		ASSERT(m_createdThreadId == INVALID_THREAD_ID ||
		       THIS_IS_THREAD_SAFE == CSingletonConst::IS_THREAD_SAFE ||
		       THIS_IS_THREAD_SAFE == CSingletonConst::IS_NOT_THREAD_SAFE && m_createdThreadId == this_thread.getID(),
			"CManagedSingleton<T> is not thread safe. Create thread and this thread are different.");
	}
	//デストラクタ
	//※デストラクタで自動的に参照カウンタをカウントダウンする。
	//※「自動生成属性：ATTR_AUTO_CREATE_AND_DELTE」の時は、参照カウンタが 0 で自動破棄する。
	~CSingletonCommon()
	{
		//参照カウンタをカウントダウン
		//※最後のカウントダウンならインスタンスを破棄する
		release();
	}
private:
	//フィールド
	bool m_isCounted;//カウントアップ済み
	//static std::once_flag m_once;//CallOnceフラグ ※CallOnce廃止
	static CSpinLock m_instanceLock;//生成・破棄処理ロックフラグ
	static std::atomic<T*> m_this;//クラス T のインスタンス（ポインタ）
	static char m_buff[sizeof(T)];//クラス T のインスタンス用の static 領域
	static std::atomic<int> m_refCount;//参照カウンタ
	static std::atomic<int> m_refCountMax;//参照カウンタの最大到達値
	static thread_local int m_refCountOnThread;//【TLS】現在のスレッド内の参照カウンタ
	static std::atomic<int> m_threadCount;//参照スレッド数
	static std::atomic<int> m_threadCountMax;//参照スレッド数の最大到達値
	static THREAD_ID m_createdThreadId;//インスタンス生成時のスレッドのスレッドID
	static const char* m_createdThreadName;//インスタンス生成時のスレッドのスレッド名
};

//----------------------------------------
//friend クラス指定補助マクロ
//※このマクロを直接使用せず、SINGLETON_FRIEND か MANAGED_SINGLETON_FRIEND を使用する
#define SINGLETON_COMMON_FRIEND(T, U) \
	friend class CSingletonCommon<T, U>;

//----------------------------------------
//シングルトン設定補助マクロ
//※このマクロを直接使用せず、SINGLETON_ATTR か MANAGED_SINGLETON_ATTR を使用する
#define SINGLETON_COMMON_ATTR(attr, is_thread_safe) \
	static const char* CLASS_NAME; \
	static const CSingletonConst::E_ATTR SINGLETON_ATTR = attr; \
	static const CSingletonConst::E_IS_THREAD_SAFE THIS_IS_THREAD_SAFE = is_thread_safe;

//----------------------------------------
//シングルトンクラスの static インスタンス生成用マクロ
//※このマクロを直接使用せず、MAKE_SINGLETON_INSTANCE か MAKE_MANAGED_SINGLETON_INSTANCE_ALL を使用する
#define MAKE_SINGLETON_COMMON_INSTANCE(T, U) \
	/*std::once_flag CSingletonCommon<T, U>::m_once;*//*CallOnceフラグ ※CallOnce廃止*/ \
	CSpinLock CSingletonCommon<T, U>::m_instanceLock;/*生成・破棄処理ロックフラグ*/ \
	std::atomic<T*> CSingletonCommon<T, U>::m_this(nullptr);/*クラス T のインスタンス（ポインタ）*/ \
	char CSingletonCommon<T, U>::m_buff[sizeof(T)];/*クラス T のインスタンス用の static 領域*/ \
	std::atomic<int> CSingletonCommon<T, U>::m_refCount(0);/*参照カウンタ*/ \
	std::atomic<int> CSingletonCommon<T, U>::m_refCountMax(0);/*参照カウンタの最大到達値*/ \
	thread_local int CSingletonCommon<T, U>::m_refCountOnThread = 0;/*【TLS】現在のスレッド内の参照カウンタ*/ \
	std::atomic<int> CSingletonCommon<T, U>::m_threadCount(0);/*参照スレッド数*/ \
	std::atomic<int> CSingletonCommon<T, U>::m_threadCountMax(0);/*参照スレッド数の最大到達値*/ \
	THREAD_ID CSingletonCommon<T, U>::m_createdThreadId = INVALID_THREAD_ID;/*インスタンス生成時のスレッドのスレッドID*/ \
	const char* CSingletonCommon<T, U>::m_createdThreadName = nullptr;/*インスタンス生成時のスレッドのスレッド名*/ \
	const char* T::CLASS_NAME = #T;/*クラス名*/

//----------------------------------------
//通常シングルトンテンプレートクラス
template<class T>
class CSingleton : public CSingletonCommon<T, CSingletonConst::AUTO_SINGLETON_TYPE>
{
public:
	//メソッド
	
	//デバッグ情報表示
	void printDebugInfo(FILE* fp = stdout)
	{
		CThreadID thread_id;
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		m_instanceLock.lock();//ロック取得
		DEBUG_FPRINT(fp, "Debug Info: [%s] on \"%s\"(0x%08x)\n", getClassName(), thread_id.getName(), thread_id.getID());
		DEBUG_FPRINT(fp, "  ClassAttribute       = %s\n", getAttr_Named());
		DEBUG_FPRINT(fp, "  ClassIsThreadSafe    = %s\n", isThreadSafe_Named());
		DEBUG_FPRINT(fp, "  ClassIsManaged       = %s\n", isManagedSingleton_Named());
		DEBUG_FPRINT(fp, "  ClassIsCreated       = %s\n", isCreated_Named());
		DEBUG_FPRINT(fp, "  RefCount             = %d (max=%d)\n", getRefCount(), getRefCountMax());
		DEBUG_FPRINT(fp, "  RefCountOnThisThread = %d\n", getRefCountOnThread());
		DEBUG_FPRINT(fp, "  ThreadCount          = %d (max=%d)\n", getThreadCount(), getThreadCountMax());
		DEBUG_FPRINT(fp, "  CreatedThread        = \"%s\"(0x%08x)\n", getCreatedThreadName(), getCreatedThreadID());
		m_instanceLock.unlock();//ロック解放
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		DEBUG_FFLUSH(fp);
	}
public:
	//コンストラクタ
	//※コンストラクタで自動的に参照カウンタをカウントアップし、インスタンスを生成する。
	//※C++11仕様の可変長テンプレートを使用し、クラス T をインスタンス化する際に、
	//　コンストラクタに任意のパラメータを与えることを可能にしている。
	//　C++11非対応のコンパイラでは、クラス T にデフォルトコンストラクタしか
	//　使えないものとする。
	template<typename... Tx>
	CSingleton(Tx... nx) :
		CSingletonCommon<T, CSingletonConst::AUTO_SINGLETON_TYPE>::CSingletonCommon(this, nx...)
	{
	}
	//デストラクタ
	//※デストラクタで自動的に参照カウンタをカウントダウンする。
	//※「自動生成属性：ATTR_AUTO_CREATE_AND_DELTE」の時は、参照カウンタが 0 で自動破棄する。
	~CSingleton()
	{
	}
};

//----------------------------------------
//通常シングルトンクラス用 friend クラス指定補助マクロ
//※シングルトン対象クラス内に記述する
//※シングルトン対象クラス自身のクラス名を渡す
#define SINGLETON_FRIEND(T) \
	SINGLETON_COMMON_FRIEND(T, CSingletonConst::AUTO_SINGLETON_TYPE);

//----------------------------------------
//通常シングルトンクラス用シングルトン設定補助マクロ
//※シングルトン対象クラス内に記述する（privateスコープでもよい）
//※シングルトン属性とスレッドセーフ宣言を渡す
#define SINGLETON_ATTR(attr, is_thread_safe) \
	SINGLETON_COMMON_ATTR(attr, is_thread_safe);

//通常シングルトンクラス用シングルトン属性：自動生成のみ＋スレッドセーフ宣言
#define SINGLETON_ATTR_AUTO_CREATE_WITH_THREAD_SAFE() \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_AUTO_CREATE, CSingletonConst::IS_THREAD_SAFE);

//通常シングルトンクラス用シングルトン属性：自動生成のみ＋非スレッドセーフ宣言
#define SINGLETON_ATTR_AUTO_CREATE_WITHOUT_THREAD_SAFE() \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_AUTO_CREATE, CSingletonConst::IS_NOT_THREAD_SAFE);

//通常シングルトンクラス用シングルトン属性：自動生成／自動削除＋スレッドセーフ宣言
#define SINGLETON_ATTR_AUTO_CREATE_AND_DELETE_WITH_THREAD_SAFE() \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_AUTO_CREATE_AND_DELETE, CSingletonConst::IS_THREAD_SAFE);

//通常シングルトンクラス用シングルトン属性：自動生成／自動削除＋非スレッドセーフ宣言
#define SINGLETON_ATTR_AUTO_CREATE_AND_DELETE_WITHOUT_THREAD_SAFE() \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_AUTO_CREATE_AND_DELETE, CSingletonConst::IS_NOT_THREAD_SAFE);

//----------------------------------------
//通常シングルトンクラス用 static インスタンス生成用マクロ
//※.cpp ファイル中に記述する
//※シングルトン対象クラスのクラス名を渡す
#define MAKE_SINGLETON_INSTANCE(T) \
	MAKE_SINGLETON_COMMON_INSTANCE(T, CSingletonConst::AUTO_SINGLETON_TYPE)

//----------------------------------------
//管理シングルトンテンプレートクラス
template<class T>
class CManagedSingleton : public CSingletonCommon<T, CSingletonConst::MANAGED_SINGLETON_TYPE>
{
	//フレンドクラス
	friend class CSingletonProxy<T>;
	friend class CSingletonInitializer<T>;
	friend class CSingletonUsing<T>;
public:
	//シングルトン設定をテンプレート引数のクラスに基づいて静的に確定
	//※クラス T には、定数 SINGLETON_USING_LIST_MAX が定義されている必要がある
	static const std::size_t THIS_SINGLETON_USING_LIST_MAX = T::SINGLETON_USING_LIST_MAX;//使用中処理リスト数
	
	//【静的アサーション】T::SINGLETON_USING_LIST_MAX は 1 以上の指定が必要
	STATIC_ASSERT(THIS_SINGLETON_USING_LIST_MAX > 0, "class THIS_SINGLETON_USING_LIST_MAX is under 0.");
public:
	//アクセッサ
	const char* getInitializerName() const { return m_initializerName.load(); }//インスタンスを生成したイニシャライザー名取得
	int getInitializerExists() const { return m_initializerExists.load(); }//イニシャライザー数取得
	CRWLock& getRWLock() { return m_lock; }//リード・ライトロック取得
	const char* getDebugTrapName() const { return m_debugTrapName.load(); }//デバッグ用トラップ対象処理名取得
	void setDebugTrapName(const char* name){ m_debugTrapName.store(const_cast<char*>(name)); }//デバッグ用トラップ対象処理名更新
	void resetDebugTrapName(){ m_debugTrapName.store(nullptr); }//デバッグ用トラップ対象処理名リセット
	const char* getDebugTrapThreadName() const { return m_debugTrapThreadName.load(); }//デバッグ用トラップ対象スレッド名取得
	void setDebugTrapThreadName(const char* name){ m_debugTrapThreadName.store(const_cast<char*>(name)); }//デバッグ用トラップ対象スレッド名更新
	void resetDebugTrapThreadName(){ m_debugTrapThreadName.store(nullptr); }//デバッグ用トラップ対象スレッド名リセット
private:
	void setInitializerName(const char* name){ m_initializerName.store(const_cast<char*>(name)); }//インスタンスを生成したイニシャライザー名更新
	void resetInitializerName(){ m_initializerName.store(nullptr); }//インスタンスを生成したイニシャライザー名リセット
	int addInitializerExists(){ return m_initializerExists.fetch_add(1); }//イニシャライザー数をカウントアップ
	int subInitializerExists(){ return m_initializerExists.fetch_sub(1); }//イニシャライザー数をカウントダウン
public:
	//オペレータ
	operator CRWLock& (){ return m_lock; }//リード・ライトロックキャストオペレータ
private:
	//メソッド

	//使用中処理リストに処理情報を追加
	//※処理名、スレッドID、スレッド名を渡す
	void addUsingList(const char* name, const THREAD_ID thread_id, const char* thread_name, const CSingletonConst::E_IS_INITIALIZER is_initializer)
	{
		//トラップ対象処理名＆スレッド名チェック
		//※文字列の一致はポインタで判定（文字列リテラルが同じならポインタが一致する⇒コンパイルオプション依存）
		const char* trap_name = m_debugTrapName.load();
		const char* trap_thread_name = m_debugTrapThreadName.load();
		if ((trap_name || trap_thread_name) &&
			(!trap_name || (name && name == trap_name)) &&
			(!trap_thread_name || (thread_name && thread_name == trap_thread_name)))
		{
			//メッセージ
			DEBUG_PRINT("Singleton catch the trap!! (\"%s\", Thread=\"%s\")\n", trap_name, trap_thread_name);
			
			//ブレークポイント
			BREAK_POINT();
		}
		//使用中情報作成
		//※THIS_SINGLETON_USING_LIST_MAX で指定された数まで同時に記録可能
		m_thisUsingInfo = m_usingListBuff.create<USING_INFO>(m_usingList.load(), name, thread_id, thread_name, is_initializer);
		if (m_thisUsingInfo)
		{
			//【参考】ロックフリーなスタックプッシュ（先頭ノード追加）アルゴリズム
			//m_thisUsingInfo->m_next = m_usingList.load();
			//while (!m_usingList.compare_exchange_weak(m_thisUsingInfo->m_next, m_thisUsingInfo)){}
			//※破棄処理側をロックフリーにできないので、このアルゴリズムを使用しない

			//使用中情報リスト追加
			m_usingListLock.lock();//ロック取得
			m_thisUsingInfo->m_next = m_usingList.load();
			m_usingList.store(m_thisUsingInfo);//先頭ノードに挿入（連結リスト）
			m_usingListLock.unlock();//ロック解放
		}
	}
	//使用中処理リストから処理情報削除
	//※m_thisUsingInfo をリストから検索して削除
	void deleteUsingList()
	{
		if (m_thisUsingInfo)
		{
			//【参考】ロックフリーなスタックポップ（先頭ノード取り出し）アルゴリズム
			//USING_INFO* old_head = m_usingList.load();
			//while (old_head && !m_usingList.compare_exchange_weak(old_head, old_head->next));
			//※この要件には適合しないので、ロックを使用する

			//使用中情報リスト削除
			m_usingListLock.lock();//ロック取得
			USING_INFO* now = m_usingList.load();
			if (now && now == m_thisUsingInfo)
			{
				//先頭ノードの場合
				m_usingList.store(m_thisUsingInfo->m_next);
			}
			else
			{
				//先頭以降のノードの場合
				while (now && now->m_next != m_thisUsingInfo){ now = now->m_next; }
				if (now)
					now->m_next = m_thisUsingInfo->m_next;
			}
			m_usingListBuff.destroy(m_thisUsingInfo);//削除
			m_usingListLock.unlock();//ロック解放
		}
	}
public:
	//使用中処理リスト表示
	void printUsingList(const char* name, FILE* fp = stdout)
	{
		CThreadID thread_id;
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		DEBUG_FPRINT(fp, "Using List: [%s] by \"%s\" on \"%s\"(0x%08x)\n", getClassName(), name, thread_id.getName(), thread_id.getID());
		m_usingListLock.lock();//ロック取得
		USING_INFO* info = m_usingList;
		while (info)
		{
			DEBUG_FPRINT(fp, " \"%s\" %s\ton \"%s\"(0x%08x)\n",
				info->m_name, 
				CSingletonConst::IsInitializer_ToStr(info->m_isInitializer ? CSingletonConst::IS_INITIALIZER : CSingletonConst::IS_USING),
				info->m_threadName,
				info->m_threadId
			);
			info = info->m_next;
		}
		DEBUG_FPRINT(fp, "(num=%d, max=%d)\n", m_usingListNum, m_usingListNumMax);
		m_usingListLock.unlock();//ロック解放
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		DEBUG_FFLUSH(fp);
	}
	//デバッグ情報表示
	void printDebugInfo(const char* name, FILE* fp = stdout)
	{
		CThreadID thread_id;
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		m_instanceLock.lock();//ロック取得
		DEBUG_FPRINT(fp, "Debug Info: [%s] by \"%s\" on \"%s\"(0x%08x)\n", getClassName(), name, thread_id.getName(), thread_id.getID());
		DEBUG_FPRINT(fp, "  ClassAttribute       = %s\n", getAttr_Named());
		DEBUG_FPRINT(fp, "  ClassIsThreadSafe    = %s\n", isThreadSafe_Named());
		DEBUG_FPRINT(fp, "  ClassIsManaged       = %s\n", isManagedSingleton_Named());
		DEBUG_FPRINT(fp, "  ClassIsCreated       = %s\n", isCreated_Named());
		DEBUG_FPRINT(fp, "  RefCount             = %d (max=%d)\n", getRefCount(), getRefCountMax());
		DEBUG_FPRINT(fp, "  RefCountOnThisThread = %d\n", getRefCountOnThread());
		DEBUG_FPRINT(fp, "  ThreadCount          = %d (max=%d)\n", getThreadCount(), getThreadCountMax());
		DEBUG_FPRINT(fp, "  CreatedThread        = \"%s\"(0x%08x)\n", getCreatedThreadName(), getCreatedThreadID());
		DEBUG_FPRINT(fp, "  InitializerName      = \"%s\"\n", getInitializerName());
		DEBUG_FPRINT(fp, "  InitializerExists    = %d\n", getInitializerExists());
		DEBUG_FPRINT(fp, "  DebugTrap            = \"%s\" on \"%s\"\n", getDebugTrapName(), getDebugTrapThreadName());
		m_instanceLock.unlock();//ロック解放
		DEBUG_FPRINT(fp, "----------------------------------------\n");
		DEBUG_FFLUSH(fp);
	}
private:
	//コンストラクタ
	//※コンストラクタで参照カウンタを更新せず、インスタンスを生成しない。
	CManagedSingleton() :
		CSingletonCommon<T, CSingletonConst::MANAGED_SINGLETON_TYPE>::CSingletonCommon(this)
	{
	}
	//デストラクタ
	//※デストラクタで自動的に参照カウンタをカウントダウンする。
	~CManagedSingleton()
	{
	}
private:
	//構造体：使用中処理情報型
	struct USING_INFO
	{
		USING_INFO* m_next;//次のノード
		const char* m_name;//処理名
		const THREAD_ID m_threadId;//処理スレッドのスレッドID
		const char* m_threadName;//処理スレッドのスレッド名
		bool m_isInitializer;//イニシャライザーフラグ
		//コンストラクタ
		USING_INFO(USING_INFO* next, const char* name, const THREAD_ID thread_id, const char* thread_name, const CSingletonConst::E_IS_INITIALIZER is_initializer) :
			m_next(next),
			m_name(name),
			m_threadId(thread_id),
			m_threadName(thread_name),
			m_isInitializer(is_initializer == CSingletonConst::IS_INITIALIZER)
		{
		}
		//デストラクタ
		~USING_INFO()
		{
		}
	};
private:
	//フィールド
	USING_INFO* m_thisUsingInfo;//自身の使用中処理情報
	static std::atomic<char*> m_initializerName;//インスタンスを生成したイニシャライザー名
	static std::atomic<int> m_initializerExists;//イニシャライザー数（普通は 0 か 1）
	static CRWLock m_lock;//リード・ライトロック
	static std::atomic<char*> m_debugTrapName;//デバッグ用トラップ対象処理名
	static std::atomic<char*> m_debugTrapThreadName;//デバッグ用トラップ対象スレッド名
	static std::atomic<int> m_usingListNum;//使用中処理リストの使用数
	static std::atomic<int> m_usingListNumMax;//使用中処理リストの使用数の最大到達値
	static std::atomic<USING_INFO*> m_usingList;//使用中処理リスト
	static CSpinLock m_usingListLock;//使用中処理リストのロック用フラグ
	static CBlockAllocator<THIS_SINGLETON_USING_LIST_MAX, sizeof(USING_INFO)> m_usingListBuff;//使用中処理リストの領域
};

//----------------------------------------
//管理シングルトンクラス用 friend クラス指定補助マクロ
//※シングルトン対象クラス内に記述する
//※シングルトン対象クラス自身のクラス名を渡す
#define MANAGED_SINGLETON_FRIEND(T) \
	SINGLETON_COMMON_FRIEND(T, CSingletonConst::MANAGED_SINGLETON_TYPE);

//----------------------------------------
//管理シングルトンクラス用シングルトン設定補助マクロ
//※シングルトン対象クラス内に記述する（privateスコープでもよい）
//※シングルトン属性とスレッドセーフ宣言を渡す
#define MANAGED_SINGLETON_ATTR(is_thread_safe, using_list_num) \
	SINGLETON_COMMON_ATTR(CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE, is_thread_safe); \
	static const std::size_t SINGLETON_USING_LIST_MAX = using_list_num;

//管理シングルトンクラス用シングルトン属性：手動生成＋スレッドセーフ宣言
#define MANAGED_SINGLETON_ATTR_WITH_THREAD_SAFE(using_list_num) \
	MANAGED_SINGLETON_ATTR(CSingletonConst::IS_THREAD_SAFE, using_list_num);

//管理シングルトンクラス用シングルトン属性：手動生成＋非スレッドセーフ宣言
#define MANAGED_SINGLETON_ATTR_WITHOUT_THREAD_SAFE(using_list_num) \
	MANAGED_SINGLETON_ATTR(CSingletonConst::IS_NOT_THREAD_SAFE, using_list_num);

//----------------------------------------
//管理シングルトンクラス用 static インスタンス生成用マクロ
//※このマクロを直接使用せず、MAKE_MANAGED_SINGLETON_INSTANCE_ALL を使用する
#define MAKE_MANAGED_SINGLETON_INSTANCE(T) \
	std::atomic<char*> CManagedSingleton<T>::m_initializerName(nullptr);/*インスタンスを生成したイニシャライザー名*/ \
	std::atomic<int> CManagedSingleton<T>::m_initializerExists(0);/*イニシャライザー数*/ \
	CRWLock CManagedSingleton<T>::m_lock;/*リード・ライトロック*/ \
	std::atomic<char*> CManagedSingleton<T>::m_debugTrapName(nullptr);/*デバッグ用トラップ対象処理名*/ \
	std::atomic<char*> CManagedSingleton<T>::m_debugTrapThreadName(nullptr);/*デバッグ用トラップ対象スレッド名*/ \
	std::atomic<int> CManagedSingleton<T>::m_usingListNum(0);/*使用中処理リストの使用数*/ \
	std::atomic<int> CManagedSingleton<T>::m_usingListNumMax(0);/*使用中処理リストの使用数の最大到達値*/ \
	std::atomic< CManagedSingleton<T>::USING_INFO* > CManagedSingleton<T>::m_usingList(nullptr);/*使用中処理リスト*/ \
	CSpinLock CManagedSingleton<T>::m_usingListLock;/*使用中処理リストのロック用フラグ*/ \
	CBlockAllocator<CManagedSingleton<T>::THIS_SINGLETON_USING_LIST_MAX, sizeof(CManagedSingleton<T>::USING_INFO)> CManagedSingleton<T>::m_usingListBuff;/*使用中処理リストの領域*/

//----------------------------------------
//【シングルトン用ヘルパー】シングルトンプロキシーテンプレートクラス　※継承専用
template<class T>
class CSingletonProxy
{
public:
	//クラスの属性、動作モードをテンプレート引数に基づいて静的に決定
	//※クラス T には、定数 CLASS_NAME, SINGLETON_ATTR, IS_THREAD_SAFE が定義されている必要がある。
	//※クラス U には、定数 THIS_IS_MANAGED_SINGLETON が定義されている必要がある。
	static const CSingletonConst::E_ATTR THIS_SINGLETON_ATTR = T::SINGLETON_ATTR;//シングルトン属性
	static const CSingletonConst::E_IS_THREAD_SAFE THIS_IS_THREAD_SAFE = T::THIS_IS_THREAD_SAFE;//スレッドセーフ宣言
public:
	//アクセッサ
	const char* getName() const { return m_name; }//処理名取得
	const CThreadID& getThreadID() const { return m_threadId; }//現在のスレッドID取得
	const char* getClassName() const { return m_singleton.getClassName(); }//現在のスレッド名取得　※委譲
	CSingletonConst::E_ATTR getAttr() const { return m_singleton.getAttr(); }//シングルトン属性取得　※委譲
	const char* getAttr_Named() const { return m_singleton.getAttr_Named(); }//シングルトン属性名取得（デバッグ用）　※委譲
	CSingletonConst::E_IS_THREAD_SAFE isThreadSafe() const { return m_singleton.isThreadSafe(); }//スレッドセーフ宣言取得　※委譲
	const char* isThreadSafe_Named() const { return m_singleton.isThreadSafe_Named(); }//スレッドセーフ宣言名取得（デバッグ用）　※委譲
	CSingletonConst::E_IS_MANAGED_SINGLETON isManagedSingleton() const { return m_singleton.isManagedSingleton(); }//管理シングルトン宣言取得　※委譲
	const char* isManagedSingleton_Named() const { return m_singleton.isManagedSingleton_Named(); }//管理シングルトン宣言名取得（デバッグ用）　※委譲
	CSingletonConst::E_IS_CREATED isCreated() const { return m_singleton.isCreated(); }//クラス(T)インスタンス生成済み状態取得　※委譲
	const char* isCreated_Named() const { return m_singleton.isCreated_Named(); }//クラス(T)インスタンス生成済み状態名取得（デバッグ用）　※委譲
private:
	CManagedSingleton<T>& getSinlgeton() { return m_singleton; }//シングルトン取得
	const CManagedSingleton<T>& getSinlgeton() const { return m_singleton; }//constシングルトン取得
	T* getThis() { return m_singleton.getThis(); }//クラス(T)インスタンスの参照を取得（禁止）　※委譲
	const T* getThis() const { return m_singleton.getThis(); }//クラス(T)インスタンスのconst参照を取得（禁止）　※委譲
public:
	int getRefCount() const { return m_singleton.getRefCount(); }//参照カウンタ取得　※委譲
	int getRefCountMax() const { return m_singleton.getRefCountMax(); }//参照カウンタの最大到達値を取得　※委譲
	int getRefCountOnThread() const { return m_singleton.getRefCountOnThread(); }//現在のスレッド内の参照カウンタ数を取得　※委譲
	int getThreadCount() const { return m_singleton.getThreadCount(); }//参照スレッド数取得　※委譲
	int getThreadCountMax() const { return m_singleton.getThreadCountMax(); }//参照スレッド数の最大到達値を取得　※委譲
	THREAD_ID getCreatedThreadID() const { return m_singleton.getCreatedThreadID(); }//クラス(T)インスタンスを生成したスレッドのスレッドIDを取得　※委譲
	const char* getCreatedThreadName() const { return m_singleton.getCreatedThreadName(); }//クラス(T)インスタンスを生成したスレッドのスレッド名を取得　※委譲
	const char* getInitializerName() const { return m_singleton.getInitializerName(); }//インスタンスを生成したイニシャライザー名取得　※委譲
	int getInitializerExists() const { return m_singleton.getInitializerExists(); }//イニシャライザー数取得　※委譲
	CRWLock& getRWLock() { return m_singleton.getRWLock(); }//リード・ライトロック取得　※委譲
	const char* getDebugTrapName() const { return m_singleton.getDebugTrapName(); }//デバッグ用トラップ対象処理名取得　※委譲
	void setDebugTrapName(const char* name){ m_singleton.setDebugTrapName(name); }//デバッグ用トラップ対象処理名更新　※委譲
	void resetDebugTrapName(){ m_singleton.resetDebugTrapName(); }//デバッグ用トラップ対象処理名リセット　※委譲
	const char* getDebugTrapThreadName() const { return m_singleton.getDebugTrapThreadName(); }//デバッグ用トラップ対象スレッド名取得　※委譲
	void setDebugTrapThreadName(const char* name){ m_singleton.setDebugTrapThreadName(name); }//デバッグ用トラップ対象スレッド名更新　※委譲
	void resetDebugTrapThreadName(){ m_singleton.resetDebugTrapThreadName(); }//デバッグ用トラップ対象スレッド名リセット　※委譲
public:
	//メソッド
	void printUsingList(FILE* fp = stdout){ m_singleton.printUsingList(m_name, fp); }//使用中処理リスト表示　※委譲
	void printDebugInfo(FILE* fp = stdout){ m_singleton.printDebugInfo(m_name, fp); }//デバッグ情報表示　※委譲
public:
	//オペレータ
	T* operator->(){ return m_singleton; }//アロー演算子：シングルトンクラスがクラス(T)のインスタンスを偽装（代理）する　※委譲
	const T* operator->() const { return m_singleton; }//const アロー演算子：（同上）　※委譲
	operator CRWLock& (){ return m_singleton; }//リード・ライトロックキャストオペレータ　※委譲
protected:
	//オペレータ（禁止）
	T& operator*(){ return *m_singleton; }//ポインタ演算子（禁止）　※委譲
	const T& operator*() const { return *m_singleton; }//constポインタ演算子（禁止）　※委譲
	operator T*(){ return m_singleton; }//クラス T* キャスト演算子（禁止）　※委譲
	operator const T*() const { return m_singleton; }//クラスconst T* キャスト演算子（禁止）　※委譲
	operator T&(){ return *m_singleton; }//クラス T& キャスト演算子（禁止）　※委譲
	operator const T&() const { return *m_singleton; }//クラス const T& キャスト演算子（禁止）　※委譲
	CSingletonProxy<T>& operator=(const CSingletonProxy<T>&){ return *this; }//コピー演算子（禁止）
	CSingletonProxy<T>& operator=(const CSingletonProxy<T>*){ return *this; }//コピー演算子（禁止）
	CSingletonProxy<T>& operator=(const T&){ return *this; }//コピー演算子（禁止）
	CSingletonProxy<T>& operator=(const T*){ return *this; }//コピー演算子（禁止）
private:
	//コピーコンストラクタ（禁止）
	explicit CSingletonProxy(CSingletonInitializer<T>&){}
	explicit CSingletonProxy(CSingletonInitializer<T>*){}
	explicit CSingletonProxy(T&){}
	explicit CSingletonProxy(T*){}
private:
	//デフォルトコンストラクタ（禁止）
	CSingletonProxy(){}
protected:
	//コンストラクタ
	CSingletonProxy(const char* name) :
		m_singleton(),
		m_name(name),
		m_threadId(),
		m_isAddRef(false)
	{}
	//デストラクタ
	~CSingletonProxy()
	{}
protected:
	//フィールド
	CManagedSingleton<T> m_singleton;//管理シングルトン
	const char* m_name;//処理名
	CThreadID m_threadId;//スレッドID
	bool m_isAddRef;//参照カウンタカウントアップ済み
};

//----------------------------------------
//シングルトンプロキシークラス用 static インスタンス生成用マクロ
//※このマクロを直接使用せず、MAKE_MANAGED_SINGLETON_INSTANCE_ALL を使用する
#define MAKE_SINGLETON_PROXY_INSTANCE(T) \
	//

//----------------------------------------
//【シングルトン用ヘルパー】シングルトンイニシャライザーテンプレートクラス
template<class T>
class CSingletonInitializer : public CSingletonProxy<T>
{
	//【静的アサーション】CSingletonInitializer<T>は、「手動生成属性：ATTR_MANUAL_CREATE_AND_DELETE」以外利用不可
	STATIC_ASSERT(THIS_SINGLETON_ATTR == CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE,
		"CSingletonInitializer<T> is only supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");
public:
	//アクセッサ
	bool isExist() const { return CManagedSingleton<T>::isExistInitializer(); }//イニシャライザーが存在するか？
private:
	void setInitializerName(const char* name) { return m_singleton.setInitializerName(name); }//イニシャライザー名を更新　※委譲
	void resetInitializerName() { return m_singleton.resetInitializerName(); }//イニシャライザー名をリセット　※委譲
private:
	//オペレータ（禁止）
	CSingletonInitializer<T>& operator=(const CSingletonInitializer<T>&){ return *this; }//コピー演算子（禁止）
	CSingletonInitializer<T>& operator=(const CSingletonInitializer<T>*){ return *this; }//コピー演算子（禁止）
	CSingletonInitializer<T>& operator=(const T&){ return *this; }//コピー演算子（禁止）
	CSingletonInitializer<T>& operator=(const T*){ return *this; }//コピー演算子（禁止）
private:
	//コピーコンストラクタ（禁止）
	explicit CSingletonInitializer(CSingletonInitializer<T>&){}
	explicit CSingletonInitializer(CSingletonInitializer<T>*){}
	explicit CSingletonInitializer(T&){}
	explicit CSingletonInitializer(T*){}
public:
	//メソッド

	//初期化（手動インスタンス生成）
	//※C++11仕様の可変長テンプレートを使用し、クラス T をインスタンス化する際に、
	//　任意のパラメータを与えることを可能にしている。
	//　C++11非対応のコンパイラでは、クラス T にデフォルトコンストラクタしか
	//　使えないものとする。
	template<typename... Tx>
	bool initialize(Tx... nx)
	{
		//【アサーション】既にインスタンスが生成済みならアサーション違反（処理続行可）
		ASSERT(!isCreated(),
			"CSingletonInitializer<T> cannot create. Singleton instance is already exist.");
		
		//生成（参照カウンタカウントアップ）
		bool is_created = false;//生成したか？
		if (!m_isAddRef)//まだ参照カウンタカをカウントアップしていない時に処理実行
		{
			m_isAddRef = true;//参照カウンタカウントアップ状態ON
			is_created = m_singleton.addRef(nx...);//生成（参照カウンタカウントアップ）
			//生成されたか？
			if (is_created)
			{
				//関連情報をセット
				setInitializerName(m_name);//インスタンスを生成したイニシャライザー名
				CRWLock& lock(getRWLock());
				lock.setIgnoreThreadID(getThreadID().getID());//リード・ライトロックの対象スレッドIDを更新
			}
		}
		//インスタンスが生成されたかどうかを返す
		return is_created;
	}
	//破棄（手動破棄）
	bool finalize(CSingletonConst::E_IS_FORCED is_forced = CSingletonConst::IS_NORMAL){ return releaseCore(CSingletonConst::IS_FINALIZE, is_forced); }
	//（明示的な）参照カウンタリリース　※破棄しない
	bool release(){ return releaseCore(CSingletonConst::IS_RELEASE, CSingletonConst::IS_NORMAL); }
private:
	//参照カウンタリリース（共通処理）
	bool releaseCore(CSingletonConst::E_IS_FINALIZE is_finalize, CSingletonConst::E_IS_FORCED is_forced)
	{
		//リリース済みなら即終了
		//※ファイナライズ時はリリース済みでも実行する
		if (!m_isAddRef && is_finalize != CSingletonConst::IS_FINALIZE)
			return false;

		//【アサーション】既に破棄済みならアサーション違反（処理続行可）
		//※強制実行時はアサーション違反としない
		ASSERT(isCreated() == CSingletonConst::IS_CREATED ||
			   is_forced == CSingletonConst::IS_FORCED,
			"CSingletonInitializer<T> cannot delete. Singleton instance is already deleted.");

		//【アサーション】ファイナライズ時にまだが参照が残っているならアサーション違反（処理続行可）
		//※強制時刻時はアサーション違反としない
		const int LAST_COUNT = getRefCount() - (m_isAddRef ? 1 : 0);
		ASSERT(is_finalize == CSingletonConst::IS_FINALIZE && LAST_COUNT == 0 ||
			   is_finalize != CSingletonConst::IS_FINALIZE ||
			   is_forced == CSingletonConst::IS_FORCED,
			"CSingletonInitializer<T> will finalize, yet still using singleton.");

		//参照カウンタリリース
		bool is_deleted = false;//削除済みフラグ
		if (m_isAddRef || is_finalize == CSingletonConst::IS_FINALIZE)//参照カウンタをカウントアップしていたか、強制手動破棄指定時に処理実行
		{
			m_isAddRef = false;//参照カウンタカウントアップ状態OFF
			if (is_finalize == CSingletonConst::IS_FINALIZE)//ファイナライズ（手動破棄）か？
				is_deleted = m_singleton.deleteThis();//手動破棄
			else
				is_deleted = m_singleton.release(); //リリース
			//破棄されたか？
			if (is_deleted)
			{
				//関連情報を破棄
				resetInitializerName();//インスタンスを生成したイニシャライザー名
				resetDebugTrapName();//デバッグ用トラップ対象処理名
				resetDebugTrapThreadName();//デバッグ用トラップ対象スレッド名
			}
		}
		//インスタンスが破棄されたかどうかを返す
		return is_deleted;
	}
public:
	//コンストラクタ
	CSingletonInitializer(const char* name, const CSingletonConst::E_IS_FORCED is_forced = CSingletonConst::IS_NORMAL) :
		CSingletonProxy(name),
		m_isFirst(false)
	{
		//イニシャライザー数カウントアップ
		const int exists_prev = m_singleton.addInitializerExists();

		//使用中処理リスト追加
		m_singleton.addUsingList(m_name, m_threadId.getID(), m_threadId.getName(), CSingletonConst::IS_INITIALIZER);

		//最初のイニシャライザーか判定
		if (exists_prev == 0)
		{
			m_isFirst = true;//最初のイニシャライザーインスタンス
		}

		//【アサーション】他にもイニシャライザーがいるならアサーション違反（処理続行可）
		//※強制破棄指定時はアサーション違反としない
		ASSERT(m_isFirst == true || is_forced == CSingletonConst::IS_FORCED,
			"CSingletonInitializer<T>: already exist!");
	}
	//デストラクタ
	~CSingletonInitializer()
	{
		//イニシャライザー数カウントダウン
		m_singleton.subInitializerExists();

		//使用中処理リストから破棄
		m_singleton.deleteUsingList();

		//参照カウンタをリリース
		release();
	}
private:
	//フィールド
	bool m_isFirst;//最初のイニシャライザーインスタンスか？
};

//----------------------------------------
//シングルトンイニシャライザークラス用 static インスタンス生成用マクロ
//※このマクロを直接使用せず、MAKE_MANAGED_SINGLETON_INSTANCE_ALL を使用する
#define MAKE_SINGLETON_INITIALIZER_INSTANCE(T) \
	//

//----------------------------------------
//【シングルトン用ヘルパー】シングルトンアクセステンプレートクラス
template<class T>
class CSingletonUsing : public CSingletonProxy<T>
{
	//【静的アサーション】CSingletonInitializer<T>は、「手動生成属性：ATTR_MANUAL_CREATE_AND_DELETE」以外利用不可
	STATIC_ASSERT(THIS_SINGLETON_ATTR == CSingletonConst::ATTR_MANUAL_CREATE_AND_DELETE,
		"CSingletonUsing<T> is only supported ATTR_MANUAL_CREATE_AND_DELETE in THIS_SINGLETON_ATTR.");
private:
	//オペレータ（禁止）
	CSingletonUsing<T>& operator=(const CSingletonUsing<T>&){ return *this; }//コピー演算子（禁止）
	CSingletonUsing<T>& operator=(const CSingletonUsing<T>*){ return *this; }//コピー演算子（禁止）
	CSingletonUsing<T>& operator=(const T&){ return *this; }//コピー演算子（禁止）
	CSingletonUsing<T>& operator=(const T*){ return *this; }//コピー演算子（禁止）
private:
	//コピーコンストラクタ禁止
	explicit CSingletonUsing(CSingletonUsing<T>&){}
	explicit CSingletonUsing(CSingletonUsing<T>*){}
	explicit CSingletonUsing(T&){}
	explicit CSingletonUsing(T*){}
public:
	//コンストラクタ
	CSingletonUsing(const char* name) :
		CSingletonProxy(name)
	{
	//※不要
	//	//【アサーション】イニシャライザーが存在していない時はアサーション違反
	//	ASSERT(m_singleton.getInitializerExists() > 0,
	//		"CSingletonUsing<T> cannot use. SingletonInitialize<T> not exist.");
	//	if (getInitializerExists() == 0)
	//	{
	//		return;
	//	}
		
		//【アサーション】インスタンスが存在していない時はアサーション違反
		ASSERT(m_singleton.isCreated() == CSingletonConst::IS_CREATED,
			"CSingletonUsing<T> cannot use. Singleton instance not exist.");
		if (isCreated() != CSingletonConst::IS_CREATED)
		{
			return;
		}
		
		//参照カウンタカウントアップ状態ON
		m_isAddRef = true;
		
		//参照カウンタをカウントアップ
		m_singleton.addRefWitoutCreate();
		
		//使用中処理リスト追加
		m_singleton.addUsingList(m_name, m_threadId.getID(), m_threadId.getName(), CSingletonConst::IS_USING);
	}
	//デストラクタ
	~CSingletonUsing()
	{
		if (m_isAddRef)
		{
			//参照カウンタカウントアップ状態OFF
			m_isAddRef = false;
			
			//参照カウンタをカウントダウン
			m_singleton.release();

			//使用中処理リスト破棄
			m_singleton.deleteUsingList();
		}
	}
};

//----------------------------------------
//シングルトンアクセスクラス用 static インスタンス生成用マクロ
//※このマクロを直接使用せず、MAKE_MANAGED_SINGLETON_INSTANCE_ALL を使用する
#define MAKE_SINGLETON_USING_INSTANCE(T) \
	//

//----------------------------------------
//シングルトンアクセスヘルパークラス用 static インスタンス生成用マクロ
//※.cpp ファイル中に記述する
//※シングルトン対象クラスのクラス名を渡す
#define MAKE_MANAGED_SINGLETON_INSTANCE_ALL(T) \
	MAKE_SINGLETON_COMMON_INSTANCE(T, CSingletonConst::MANAGED_SINGLETON_TYPE); \
	MAKE_MANAGED_SINGLETON_INSTANCE(T); \
	MAKE_SINGLETON_INITIALIZER_INSTANCE(T); \
	MAKE_SINGLETON_USING_INSTANCE(T);

#if 1
//--------------------------------------------------------------------------------
//テスト処理①

//----------------------------------------
//C++11ライブラリ
#include <random>//乱数
#include <chrono>//時間

//----------------------------------------
//共通処理クラス①：通常シングルトン用
class CData1
{
	//コンストラクタ／デストラクタを private にするための friend 宣言
	SINGLETON_FRIEND(CData1);
public:
	//定数
	//シングルトン属性：自動生成のみ＋スレッドセーフ宣言
	SINGLETON_ATTR_AUTO_CREATE_WITH_THREAD_SAFE();
	//シングルトン属性：自動生成のみ＋非スレッドセーフ宣言
	//SINGLETON_ATTR_AUTO_CREATE_WITHOUT_THREAD_SAFE();
	//シングルトン属性：自動生成／自動削除＋スレッドセーフ宣言
	//SINGLETON_ATTR_AUTO_CREATE_AND_DELETE_WITH_THREAD_SAFE();
	//シングルトン属性：自動生成／自動削除＋非スレッドセーフ宣言
	//SINGLETON_ATTR_AUTO_CREATE_AND_DELETE_WITHOUT_THREAD_SAFE();
public:
	//アクセッサ
	int getData() const { m_data.load(); }
public:
	//メソッド
	//カウントアップ
	void addData()
	{
		int data_prev = m_data.fetch_add(1);
		printf("addCount() %d -> %d\n", data_prev, data_prev + 1);
		fflush(stdout);
	}
	//カウントダウン
	void subData()
	{
		int data_prev = m_data.fetch_sub(1);
		printf("subCount() %d -> %d\n", data_prev, data_prev - 1);
		fflush(stdout);
	}
	//プリント
	void print(const char* name, const char* thread)
	{
		printf("print() Data=%2d [%s][%s] (FIRST:%s)\n", m_data, name, thread, m_firstThreadName);
		fflush(stdout);
	}
private:
	//コンストラクタ
	//※シングルトン以外でこのクラスを使えないように private にする
	CData1(const char* thread_name):
		m_data(0),
		m_firstThreadName(thread_name)
	{
		printf("[CONSTRUCTOR] (FIRST:%s)\n", m_firstThreadName);
		fflush(stdout);
	}
	//デストラクタ
	~CData1()
	{
		printf("[DESTRUCTOR] (FIRST:%s)\n", m_firstThreadName);
		fflush(stdout);
	}
private:
	std::atomic<int> m_data;//データ
	const char* m_firstThreadName;//最初にアクセスしたスレッド名
};
//クラス内のstaticメンバーのインスタンスを定義する必要あり
MAKE_SINGLETON_INSTANCE(CData1);//通常シングルトン用staticインスタンス生成用マクロ

//----------------------------------------
//スレッド関数①-A
void threadFunc1A(const char* thread_name)
{
	//スレッドIDとスレッド名をセット
	CThreadID thread_id(thread_name);

	//シングルトン
	//※CData1 のコンストラクタ引数を指定
	CSingleton<CData1> data(thread_id.getName());

	//乱数
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> sleep_time(60, 100);

	//スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(engine)));

	//カウントアップ
	//※アロー演算子でCData1のメンバー関数に普通にアクセス
	data->addData();

	//プリント
	//※アロー演算子でCData1のメンバー関数に普通にアクセス
	data->print("threadFunc1A", thread_id.getName());
}

//----------------------------------------
//スレッド関数①-B
void threadFunc1B(const char* thread_name)
{
	//スレッドIDとスレッド名をセット
	CThreadID thread_id(thread_name);

	//シングルトン
	//※CData1 のコンストラクタ引数を指定
	CSingleton<CData1> data(thread_id.getName());

	//スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	//乱数
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> sleep_time(60, 100);

	//スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(engine)));

	//カウントダウン
	//※アロー演算子でCData1のメンバー関数に普通にアクセス
	data->subData();

	//プリント
	//※アロー演算子でCData1のメンバー関数に普通にアクセス
	data->print("threadFunc1B", thread_id.getName());
}

//----------------------------------------
//テスト①：通常シングルトンテスト
void test1()
{
	printf("----------------------------------------------------------------------\n");
	printf("【通常シングルトンテスト】\n");

	//【コンパイルエラー】直接インスタンス生成
	{
		//普通にインスタンス生成
		//CData1 data("illegal-data");//←NG:コンパイルエラー
		//CData1* data = new CData1("illegal-data");//←NG:コンパイルエラー
		//※シングルトン対象クラスはコンストラクタが private 宣言されているので
		//　直接インスタンスを生成できない
	}

	//スレッド生成
	std::thread th1 = std::thread(threadFunc1A, "THREAD-A");
	std::thread th2 = std::thread(threadFunc1B, "THREAD-B");
	std::thread th3 = std::thread(threadFunc1A, "THREAD-C");
	std::thread th4 = std::thread(threadFunc1B, "THREAD-D");
	std::thread th5 = std::thread(threadFunc1A, "THREAD-E");
	std::thread th6 = std::thread(threadFunc1B, "THREAD-F");

	//スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	//途中状態のシングルトンの情報を表示
	{
		//スレッドID
		CThreadID thread_id;

		//シングルトン
		//※CData1 のコンストラクタ引数を指定
		CSingleton<CData1> data(thread_id.getName());

		//プリント
		//※アロー演算子でCData1のメンバー関数に普通にアクセス
		data->print("main", thread_id.getName());

		//デバッグ情報表示
		data.printDebugInfo();
	}

	//スレッド終了待ち
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();

	//終了状態のシングルトンの情報を表示
	{
		//スレッドID
		CThreadID thread_id;

		//シングルトン
		//※CData1 のコンストラクタ引数を指定
		CSingleton<CData1> data(thread_id.getName());

		//プリント
		//※アロー演算子でCData1のメンバー関数に普通にアクセス
		data->print("main", thread_id.getName());

		//デバッグ情報表示
		data.printDebugInfo();
	}
	
	printf("----------------------------------------------------------------------\n");
}

//--------------------------------------------------------------------------------
//テスト処理②

//----------------------------------------
//C++11ライブラリ
#include <random>//乱数
#include <chrono>//時間

//----------------------------------------
//共通処理クラス②：管理シングルトン用
class CData2
{
	//コンストラクタ／デストラクタを private にするための friend 宣言
	MANAGED_SINGLETON_FRIEND(CData2);
public:
	//定数
	//シングルトン属性：手動生成＋スレッドセーフ宣言＋使用中情報数MAX=10件
	MANAGED_SINGLETON_ATTR_WITH_THREAD_SAFE(10);
	//シングルトン属性：手動生成＋非スレッドセーフ宣言＋使用中情報数MAX=10件
	//MANAGED_SINGLETON_ATTR_WITHOUT_THREAD_SAFE(10);
public:
	//アクセッサ
	int getData() const { m_data.load(); }
public:
	//メソッド
	//カウントアップ
	void addData()
	{
		int data_prev = m_data.fetch_add(1);
		printf("addCount() %d -> %d\n", data_prev, data_prev + 1);
		fflush(stdout);
	}
	//カウントダウン
	void subData()
	{
		int data_prev = m_data.fetch_sub(1);
		printf("subCount() %d -> %d\n", data_prev, data_prev - 1);
		fflush(stdout);
	}
	//プリント
	void print(const char* name, const char* thread)
	{
		printf("print() Data=%2d [%s][%s] (FIRST:%s)\n", m_data, name, thread, m_firstThreadName);
		fflush(stdout);
	}
private:
	//コンストラクタ
	//※シングルトン以外でこのクラスを使えないように private にする
	CData2(const char* thread_name) :
		m_data(0),
		m_firstThreadName(thread_name)
	{
		printf("[CONSTRUCTOR] (FIRST:%s)\n", m_firstThreadName);
		fflush(stdout);
	}
	//デストラクタ
	~CData2()
	{
		printf("[DESTRUCTOR] (FIRST:%s)\n", m_firstThreadName);
		fflush(stdout);
	}
private:
	std::atomic<int> m_data;//データ
	const char* m_firstThreadName;//最初にアクセスしたスレッド名
};
//クラス内のstaticメンバーのインスタンスを定義する必要あり
MAKE_MANAGED_SINGLETON_INSTANCE_ALL(CData2);//管理シングルトン用staticインスタンス生成用マクロ

//----------------------------------------
//スレッド関数②-A
void threadFunc2A(const char* thread_name)
{
	//スレッドIDとスレッド名をセット
	CThreadID thread_id(thread_name);

	//シングルトンアクセス
	//※処理名を指定
	CSingletonUsing<CData2> data("threadFunc2A");

	//乱数
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> sleep_time(60, 100);

	//スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(engine)));

	//プリント
	//※アロー演算子でCData2のメンバー関数に普通にアクセス
	data->print("threadFunc2A:BEFORE", thread_id.getName());

	//リードロック
	//※関数終了時に自動的にロック解放
	CRWLockR lock(data);
	//※管理シングルトンはリード・ライトロックを一つ保持している。
	//　また、キャストオペレーターにより、そのままリード・ライトロックオブジェクトとして振る舞うことができる

	//カウントアップ
	//※アロー演算子でCData2のメンバー関数に普通にアクセス
	data->addData();

	//プリント
	//※アロー演算子でCData2のメンバー関数に普通にアクセス
	data->print("threadFunc2A:AFTER ", thread_id.getName());
}

//----------------------------------------
//スレッド関数②-B
void threadFunc2B(const char* thread_name)
{
	//スレッドIDとスレッド名をセット
	CThreadID thread_id(thread_name);

	//シングルトンアクセス
	//※処理名を指定
	CSingletonUsing<CData2> data("threadFunc2B");

	//スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	//乱数
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> sleep_time(60, 100);

	//スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(engine)));

	//プリント
	//※アロー演算子でCData2のメンバー関数に普通にアクセス
	data->print("threadFunc2B:BEFORE", thread_id.getName());

	//ライトロック
	//※関数終了時に自動的にロック解放
	CRWLockW lock(data);
	//※管理シングルトンはリード・ライトロックを一つ保持している。
	//　また、キャストオペレーターにより、そのままリード・ライトロックオブジェクトとして振る舞うことができる

	//カウントダウン
	//※アロー演算子でCData2のメンバー関数に普通にアクセス
	data->subData();

	//プリント
	//※アロー演算子でCData2のメンバー関数に普通にアクセス
	data->print("threadFunc2B:AFTER ", thread_id.getName());
}

//----------------------------------------
//テスト②初期化関数
void initializeTest2()
{
	//スレッドID
	CThreadID thread_id;
	
	//シングルトンイニシャライザー
	//※処理名を指定
	CSingletonInitializer<CData2> data_init("initializeTest2");
	
	//インスタンス生成
	//※CData2 のコンストラクタ引数を指定
	data_init.initialize(thread_id.getName());
	
	//デバッグ情報表示
	data_init.printDebugInfo();
	data_init.printUsingList();
}

//----------------------------------------
//テスト②終了関数
void finalizeTest2()
{
	//シングルトンイニシャライザー
	//※処理名を指定
	CSingletonInitializer<CData2> data_init("finalizeTest2");
	
	//インスタンス破棄
	data_init.finalize();
	
	//デバッグ情報表示
	data_init.printDebugInfo();
	data_init.printUsingList();
}

//----------------------------------------
//テスト②：管理シングルトンテスト
void test2()
{
	printf("----------------------------------------------------------------------\n");
	printf("【管理シングルトンテスト】\n");

	//【コンパイルエラー】直接インスタンス生成
	{
		//普通にインスタンス生成
		//CData2 data("illegal-data");//←NG:コンパイルエラー
		//CData2* data = new CData2("illegal-data");//←NG:コンパイルエラー
		//※シングルトン対象クラスはコンストラクタが private 宣言されているので
		//　直接インスタンスを生成できない
	}

	//【静的アサーション違反】通常シングルトンとして CData2 をインスタンス化
	{
		//通常シングルトン
		//※CData2 のコンストラクタ引数を指定
		//CSingleton<CData2> data("illegal-initialize");//←NG:静的アサーション違反
		//※CData2は管理シングルトンとして宣言されているため、
		//　通常シングルトンとして使用しようとするとコンパイルが通らない
		//　しかし、安全ではあるものの、エラーの場所がかなりわかりにくいので、
		//　静的アサーションをやめて実行時アサーションにしたほうが良いかもしれない
	}

	//【アサーション違反】初期化前にシングルトンにアクセス
	{
		//シングルトンアクセス
		//※処理名を指定
		CSingletonUsing<CData2> data("illegal-access");
	}
	
	//シングルトン初期化
	initializeTest2();

	//デバッグトラップ
	//※指定の処理名とスレッド名が一致するシングルトンアクセスがあった場合、
	//　ブレークポイントが発生する
	//※どちらか片方の指定も可
	{
		CSingletonUsing<CData2> data("test");
		data.setDebugTrapName("threadFunc2B");//処理名でトラップ
		data.setDebugTrapThreadName("THREAD-F");//スレッド名でトラップ
	}

	//スレッド生成
	std::thread th1 = std::thread(threadFunc2A, "THREAD-A");
	std::thread th2 = std::thread(threadFunc2B, "THREAD-B");
	std::thread th3 = std::thread(threadFunc2A, "THREAD-C");
	std::thread th4 = std::thread(threadFunc2B, "THREAD-D");
	std::thread th5 = std::thread(threadFunc2A, "THREAD-E");
	std::thread th6 = std::thread(threadFunc2B, "THREAD-F");

	//スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	//途中状態のシングルトンの情報を表示
	{
		//スレッドID
		CThreadID thread_id;

		//シングルトンアクセス
		//※処理名を指定
		CSingletonUsing<CData2> data("main-1");

		//プリント
		//※アロー演算子でCData2のメンバー関数に普通にアクセス
		data->print("main", thread_id.getName());

		//デバッグ情報表示
		data.printDebugInfo();
		data.printUsingList();
	}

	//スレッド終了待ち
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();

	//終了状態のシングルトンの情報を表示
	{
		//スレッドID
		CThreadID thread_id;

		//シングルトンアクセス
		//※処理名を指定
		CSingletonUsing<CData2> data("main-2");

		//プリント
		//※アロー演算子でCData2のメンバー関数に普通にアクセス
		data->print("main", thread_id.getName());

		//デバッグ情報表示
		data.printDebugInfo();
		data.printUsingList();
	}

	//シングルトン終了
	finalizeTest2();
	
	printf("----------------------------------------------------------------------\n");
}

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//メインスレッドIDとスレッド名をセット
	CThreadID main_thread_id("MainThread");
	
	//テスト①：通常シングルトン
	test1();

	//テスト②：管理シングルトン
	test2();
	
	return EXIT_SUCCESS;
}

#endif
#if 0
//--------------------------------------------------------------------------------
//旧テスト処理

//共通処理クラス ※特に何かを継承する必要も、どこかに実体を宣言する必要もない
class CTest
{
	//コンストラクタ／デストラクタを private にするための friend 宣言
	SINGLETON_FRIEND(CTest);
public:
	//シングルトン属性：自動生成のみ
	SINGLETON_ATTR(CSingletonConst::ATTR_AUTO_CREATE, CSingletonConst::IS_THREAD_SAFE);
public:
	//処理
	void printTest()
	{
		printf("test\n");
	}
private:
	//コンストラクタ
	CTest()
	{
		printf("CTest::CTest()\n");
	}
	//デストラクタ
	~CTest()
	{
		printf("CTest::~CTest()\n");
	}
};
//クラス内のstaticメンバーのインスタンスを定義する必要あり
MAKE_SINGLETON_INSTANCE(CTest);//シングルトン用staticインスタンス生成用マクロ

//----------------------------------------

//処理１
void func1()
{
	//シングルトンアクセス
	//※初回のアクセス時にインスタンスが生成され、
	//　以後はそのインスタンスが使用される
	CSingleton<CTest> test;

	//処理
	//※アロー演算子で普通にCTestクラスのメンバーにアクセスする
	test->printTest();
}

//処理２
void func2()
{
	//シングルトンアクセス
	CSingleton<CTest> test;

	func1();

	//処理
	test->printTest();
}

//--------------------------------------------------------------------------------

//メインスレッド
CThreadID s_mainThread("MainThread");

//----------------------------------------

//仮リソースマネージャクラス
class CResManager
{
	//シングルトンクラス対応
	MANAGED_SINGLETON_FRIEND(CResManager);
public:
	MANAGED_SINGLETON_ATTR(CSingletonConst::IS_THREAD_SAFE, 20);

private:
	//コンストラクタはプライベート化する
	CResManager() :
		m_val(0)
	{
		printf("constructor!\n");
	}
	//デストラクタ
	~CResManager()
	{
		printf("desstructor!\n");
	}
public:
	int getVal() const { return m_val; }
	void setVal(const int val) { m_val = val; }
private:
	int m_val;
};
//インスタンス化（.cppファイルに配置）
MAKE_MANAGED_SINGLETON_INSTANCE_ALL(CResManager);

//----------------------------------------

//サブ処理A
void subA()
{
	printf("- subA:start -\n");
	CSingletonUsing<CResManager> res("subA");
	res->setVal(123);
	CRWLockR lock(res.getRWLock());
	res.resetDebugTrapName();
	res.resetDebugTrapThreadName();
	res.setDebugTrapName("subB");
	res.setDebugTrapThreadName("subB");
	printf("- subA:end -\n");
}

//サブ処理B
void subB(const char* name)
{
	printf("- subB(%s):start -\n", name);
	std::cout << "s_mainThread.isThisThread()=" << std::boolalpha << s_mainThread.isThisThread() << std::endl;
	CSingletonUsing<CResManager> res("subB");
	printf("getVal()=%d\n", res->getVal());
	extern void subC();
	subC();
	printf("getVal()=%d\n", res->getVal());
	res.printUsingList();
	printf("- subB(%s):end -\n", name);
}
void subB2(const char* name, const bool is_new_thread = false)
{
	if (is_new_thread)
		CThreadID this_thread("subB2");
	printf("- subB2(%s):start -\n", name);
	std::this_thread::sleep_for(std::chrono::microseconds(1));
	CSingletonUsing<CResManager> res("subB2");
	subB(name);
	printf("- subB2(%s):end -\n", name);
}

//サブ処理C
void subC()
{
	printf("- subC:start -\n");
	CSingletonUsing<CResManager> res("subC");
	res->setVal(456);
	CSingletonInitializer<CResManager> res2("subC");
	CSingletonUsing<CResManager> res3("subC2");
	//	CSingleton<CResManager> res4;
	res.printUsingList();
	printf("- subC:end -\n");
}

//----------------------------------------

//テスト
int main(const int argc, const char* argv[])
{
	func1();
	func2();
	//	CSingletonInitializer<CResManager> x("initializer");
	//	x.createSingleton();
	{
		CSingletonUsing<CResManager> ng_res("main_prior");
		ng_res.printDebugInfo();
		//CSingletonInitializer<CResManager> res_init("initializer");
		CSingletonInitializer<CResManager> res_init("initializer", CSingletonConst::IS_FORCED);
		res_init.createSingleton();
		CSingletonUsing<CResManager> res("main");
		subA();
		std::thread t = std::thread(subB2, "thread", true);
		subB("main");
		res.printUsingList();
		res.printDebugInfo();
		t.join();
		{
			printf("getRefCount()=%d\n", res.getRefCount());
			printf("getRefCountMax()=%d\n", res.getRefCountMax());
			printf("getRefCountOnThread()=%d\n", res.getRefCountOnThread());
			printf("getThreadCount()=%d\n", res.getThreadCount());
			printf("getThreadCountMax()=%d\n", res.getThreadCountMax());
			printf("getCreatedThreadID()=%d\n", res.getCreatedThreadID());
			printf("getCreatedThreadName()=\"%s\"\n", res.getCreatedThreadName());
			printf("getDebugTrapName()=\"%s\"\n", res.getDebugTrapName());
			printf("getDebugTrapThreadName()=\"%s\"\n", res.getDebugTrapThreadName());
			printf("getAttr()=%d\n", res.getAttr());
			printf("isThreadSafe()=%d\n", res.isThreadSafe());
			printf("isManagedSingleton()=%d\n", res.isManagedSingleton());
			printf("isCreated()=%d\n", res.isCreated());
			printf("getClassName()=\"%s\"\n", res.getClassName());
			printf("getInitializeNname()=\"%s\"\n", res.getInitializerName());
		}
		{
			printf("getRefCount()=%d\n", res_init.getRefCount());
			printf("getRefCountMax()=%d\n", res_init.getRefCountMax());
			printf("getRefCountOnThread()=%d\n", res_init.getRefCountOnThread());
			printf("getThreadCount()=%d\n", res_init.getThreadCount());
			printf("getThreadCountMax()=%d\n", res_init.getThreadCountMax());
			printf("getCreatedThreadID()=%d\n", res_init.getCreatedThreadID());
			printf("getCreatedThreadName()=\"%s\"\n", res_init.getCreatedThreadName());
			printf("getDebugTrapName()=\"%s\"\n", res_init.getDebugTrapName());
			printf("getDebugTrapThreadName()=\"%s\"\n", res_init.getDebugTrapThreadName());
			printf("getAttr()=%d\n", res_init.getAttr());
			printf("isThreadSafe()=%d\n", res_init.isThreadSafe());
			printf("isManagedSingleton()=%d\n", res_init.isManagedSingleton());
			printf("isCreated()=%d\n", res_init.isCreated());
			printf("getClassName()=\"%s\"\n", res_init.getClassName());
			printf("getInitializeNname()=\"%s\"\n", res_init.getInitializerName());
		}
		res_init.releaseSingleton();
		res_init.deleteSingleton(CSingletonConst::IS_FORCED);
		res_init.printUsingList();
		res_init.printDebugInfo();
	}
	//	x.printUsingList();
	//	x.printDebugInfo();
	//	x.releaseSingleton();
	//	x.deleteSingleton();
	CSingletonInitializer<CResManager> x("initializer2");
	x.printUsingList();
	x.printDebugInfo();

	bool a = CThreadID() == CThreadID();

	return EXIT_SUCCESS;
}

#endif

// End of file
