#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdint.h>//uintptr_t,intptr_t用
#include <limits.h>//INT_MAX用

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
//※C++11仕様偽装
//#define TLS_IS_POSIX//TLSの宣言をPOSIX仕様にする時はこのマクロを有効にする
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX仕様
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows仕様
#endif//TLS_IS_POSIX

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

//--------------------------------------------------------------------------------
//プールアロケータクラス

//----------------------------------------
//クラス宣言
class CPoolAllocator;

//----------------------------------------
//プールアロケータクラス専用配置new/delete処理
//※クラス内で使用するためのものなので、直接使用は禁止
//※クラス内でdeleteすることで、デストラクタの呼び出しにも対応
//配置new
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw();
//配置delete
void operator delete(void* p, CPoolAllocator& allocator) throw();

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
//プールアロケータクラス専用配置new/delete処理
//配置new
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw() { return allocator.alloc(size); }
//配置delete
void operator delete(void* p, CPoolAllocator& allocator) throw() { allocator.free(p); }

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
//CRC算出

//--------------------
//型
typedef unsigned int crc32_t;//CRC32型

//--------------------
//【通常関数版】文字列からCRC算出
crc32_t calcCRC32(const char* str)
{
	//ダミー処理
	return reinterpret_cast<crc32_t>(str);
}

//--------------------------------------------------------------------------------
//名前付きデータ参照クラス

#include <atomic>//アトミック型
#include <unordered_map>//【暫定】C++11のハッシュテーブルライブラリ
                        //※できれば、ヒープを使用しない独自の実装に変えた方が安定する

//----------------------------------------
//名前付きデータ参照クラス
//※テンプレートパラメータで記録可能な参照の最大数を指定
template<std::size_t MAX, int SPIN = CSpinLock::DEFAULT_SPIN_COUNT>
class CNamedRefT
{
public:
	//定数
	static const int MAX_NODES = MAX;//記録可能な参照の最大数を指定
	static const int SPIN_COUNT = SPIN;//スピンロックのピンカウント数
public:
	//型
	typedef unsigned long long u64;//64ビット型
	typedef unsigned long u32;//32ビット型
	typedef u64 KeyPrim;//キー型（ハッシュテーブル用のプリミティブ型）
	//キー型
	struct Key
	{
		union
		{
			KeyPrim m_prim;//プリミティブ型キー
			struct
			{
				u32 m_main;//主キー
				u32 m_sub;//副キー
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
			m_main(calcCRC32(name)),
			m_sub(sub_key)
		{}
		Key(const char* name) :
			m_main(calcCRC32(name)),
			m_sub(0)
		{}
		Key(const unsigned int main_key, const char* sub_key) :
			m_main(main_key),
			m_sub(calcCRC32(sub_key))
		{}
		Key(const char* name, const char* sub_key) :
			m_main(calcCRC32(name)),
			m_sub(calcCRC32(sub_key))
		{}
		//デストラクタ
		~Key()
		{}
	};
private:
	//--------------------
	//データ参照型：共通部
	struct RefNodeCore
	{
		//メソッド
		virtual void* getRefByFunctor() const = 0;//関数オブジェクトを使用して変数の参照を取得
		virtual void getValByFunctor(void* val) const = 0;//関数オブジェクトを使用して変数の値を取得
		virtual void setValByFunctor(const void* val) = 0;//関数オブジェクトを使用して変数の値を更新
		//データの参照を取得
		template<typename T>
		void* getRefCore() const
		{
			if (m_removed.load() == true)//【保険処理】削除済みチェック
				return nullptr;
			ASSERT(typeid(T) == m_type, "This type is not match.(this=%s, request=%s)", m_type.name(), typeid(T).name());
			if (typeid(T) != m_type)
				return nullptr;
			if (m_ref.load() == nullptr)//２回目以降のアクセスを高速にするために、参照を記憶する
				m_ref.store(getRefByFunctor());
			return m_ref.load();
		}
		//データの参照を取得
		template<typename T>
		T* getRef(){ return static_cast<T*>(getRefCore<T>()); }
		//データの参照を取得
		template<typename T>
		const T* getRef() const { return static_cast<T*>(getRefCore<T>()); }
		//データの値を取得
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
		//データの値を更新
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
		void resetRef(){ m_ref.store(nullptr); }
		//リードロック取得
		void rLock() const { CRWLockHelper(m_lock).rLock(SPIN_COUNT); }
		//ライトロック取得
		void wLock() const { CRWLockHelper(m_lock).wLock(SPIN_COUNT); }
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
	//データ参照型：実装部：直接参照タイプ
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
	//データ参照型：実装部：アクセッサタイプ
	//※直接参照タイプの方が、参照を記憶できる分早い。
	//※アクセッサタイプは、毎回必ずアクセッサを通す。
	template<typename F>
	struct AccessorNode : public RefNodeCore
	{
		//型
		typedef typename F::TYPE TYPE;//データ型
		typedef typename F::getter GETTER_FUNCTOIR;//データの値取得用関数オブジェクト型
		typedef typename F::setter SETTER_FUNCTOIR;//データの値更新用関数オブジェクト型
		//【オーバーライド】【無効】関数オブジェクトを使用して変数の参照を取得
		void* getRefByFunctor() const override{ return nullptr; }
		//【オーバーライド】関数オブジェクトを使用してデータの値を取得
		void getValByFunctor(void* val) const override
		{
			GETTER_FUNCTOIR functor;
			*static_cast<TYPE*>(val) = functor(m_key);
		}
		//【オーバーライド】関数オブジェクトを使用してデータの値を更新
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
	struct getRefFunctorDummy : BaseRefF<int>{ TYPE* operator()(const Key& key) const { return nullptr; } };//【ダミー】データ参照用関数オブジェクト：直接参照タイプ
	struct accessorFunctorDummy : BaseRefF<int>{//【ダミー】データ参照用関数オブジェクト：アクセッサタイプ
		struct getter { TYPE operator()(const Key& key) const { return 0; } };
		struct setter { void operator()(const Key& key, const TYPE val) const {} };
	};
	using DirectRefNodeDummy = DirectRefNode<getRefFunctorDummy>;//【ダミー】データ参照型：直接参照タイプ
	using AccessorNodeDummy = AccessorNode<accessorFunctorDummy>;//【ダミー】データ参照型：アクセッサタイプ
public:
	//定数
	#define MAX_SIZE(x, y) ((x) > (y) ? (x) : (y))
	static const std::size_t REF_NODE_SIZE_MAX = MAX_SIZE(sizeof(DirectRefNodeDummy), sizeof(AccessorNodeDummy));//データ参照型の最大サイズ
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
		RefR(CNamedRefT<MAX>& map, const Key key) :
			m_namedRef(map.find(key, &m_isExist)),
			m_ref(nullptr)
		{
			//変数の参照を取得
			if (m_namedRef)
			{
				m_ref = m_namedRef->getRef<T>();
				if (m_ref)
				{
					//変数の参照に成功したらリードロック取得
					m_namedRef->rLock();
				}
			}
		}
		//デストラクタ
		~RefR()
		{
			if (m_namedRef && m_ref)
			{
				//リードロック解放
				m_namedRef->rUnlock();
			}
		}
	private:
		//フィールド
		const RefNodeCore* m_namedRef;//変数参照型
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
		RefW(CNamedRefT<MAX>& map, const Key key) :
			m_namedRef(map.find(key, &m_isExist)),
			m_ref(nullptr)
		{
			//変数の参照を取得
			if (m_namedRef)
			{
				m_ref = m_namedRef->getRef<T>();
				if (m_ref)
				{
					//変数の参照に成功したらライトロック取得
					m_namedRef->wLock();
				}
			}
		}
		//デストラクタ
		~RefW()
		{
			if (m_namedRef && m_ref)
			{
				//ライトロック解放
				m_namedRef->wUnlock();
			}
		}
	private:
		//フィールド
		RefNodeCore* m_namedRef;//変数参照型
		T* m_ref;//変数参照
		bool m_isExist;//参照先が存在するか？
	};
private:
	//--------------------
	//全体ブロック：読み込みロック
	class WholeBLockR
	{
	public:
		//コンストラクタ
		WholeBLockR(CRWLock& lock, const bool locked, const THREAD_ID locked_thread_id) :
			m_lock(lock)
		{
			//ロック中状態
			//※全体ブロック中、かつ、全体ブロックを行ったスレッドと同じスレッドならロックしない
			m_locked = !(locked == true && CThreadID() == locked_thread_id);
			if (m_locked)
				CRWLockHelper(m_lock).rLock(SPIN_COUNT);
		}
		//デストラクタ
		~WholeBLockR()
		{
			if (m_locked)
				CRWLockHelper(m_lock).rUnlock();
		}
	private:
		CRWLock& m_lock;//リード・ライトロック
		bool m_locked;//ロック中
	};
	//--------------------
	//全体ブロック：書き込みロック
	class WholeBLockW
	{
	public:
		//コンストラクタ
		WholeBLockW(CRWLock& lock, const bool locked, const THREAD_ID locked_thread_id) :
			m_lock(lock)
		{
			//ロック中状態
			//※全体ブロック中、かつ、全体ブロックを行ったスレッドと同じスレッドならロックしない
			m_locked = !(locked == true && CThreadID() == locked_thread_id);
			if (m_locked)
				CRWLockHelper(m_lock).wLock(SPIN_COUNT);
		}
		//デストラクタ
		~WholeBLockW()
		{
			if (m_locked)
				CRWLockHelper(m_lock).wUnlock();
		}
	private:
		CRWLock& m_lock;//リード・ライトロック
		bool m_locked;//ロック中
	};
	//クラス内クラス定義：ここまで
	//--------------------
public:
	//メソッド
	//変数参照用関数オブジェクト登録：直接参照タイプ
	template<typename F>
	bool regist(const Key key, F functor, bool* is_exist = nullptr)
	{
		//全体ライトロック取得（解放は自動）
		WholeBLockW lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//ハッシュテーブル登録済みチェック
		NamedRefTable::const_iterator node = m_namedRefList.find(key);
		if (node != m_namedRefList.end())
		{
			if (is_exist)
				*is_exist = true;
			return false;
		}
		if (is_exist)
			*is_exist = false;
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
	bool registAcc(const Key key, F functor_set, bool* is_exist = nullptr)
	{
		//全体ライトロック取得（解放は自動）
		WholeBLockW lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//ハッシュテーブル登録済みチェック
		NamedRefTable::const_iterator node = m_namedRefList.find(key);
		if (node != m_namedRefList.end())
		{
			if (is_exist)
				*is_exist = true;
			return false;
		}
		if (is_exist)
			*is_exist = false;
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
	bool unregist(const Key key, bool* is_exist = nullptr)
	{
		//全体ライトロック取得（解放は自動）
		WholeBLockW lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//変数参照情報取得
		//ハッシュテーブル登録済みチェック
		NamedRefTable::iterator node = m_namedRefList.find(key);
		if (node == m_namedRefList.end())
		{
			if (is_exist)
				*is_exist = false;
			return false;
		}
		if (is_exist)
			*is_exist = true;
		//登録解除と削除
		RefNodeCore* ref = node->second;//ハッシュテーブルの情報を参照
		if (ref)
		{
			//ref->wLock();//【不要】ライトロック取得
			node->second = nullptr;//ハッシュテーブルから情報を破棄
			//ref->wUnlock();//【不要】ライトロック解放
			m_allocator.destroy(ref);//メモリ解放
		}
		m_namedRefList.erase(key);//ハッシュテーブルから登録解除
		return true;
	}
	//全ての変数参照用関数オブジェクト登録解除
	//※スレッドセーフではないのでタイミングに厳重注意
	//※念のためロックを取得してはいるものの、他からのアクセスをブロックしている状況だと、
	//　削除後に処理が走るので結局問題を起こす
	void unregistAll()
	{
		//全体ライトロック取得（解放は自動）
		WholeBLockW lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//全ノード処理
		for (auto node : m_namedRefList)
		{
			RefNodeCore* ref = node.second;//ハッシュテーブルの情報を参照
			if (ref)
			{
				//ref->wLock();//【不要】ライトロック取得
				node.second = nullptr;//ハッシュテーブルから情報を破棄
				//ref->wUnlock();//【不要】ライトロック解放
				m_allocator.destroy(ref);//メモリ解放
			}
		}
		m_namedRefList.clear();//ハッシュテーブルの全ノードをクリア
	}
	//変数の参照をクリア
	void resetRef(const Key key, bool* is_exist = nullptr)
	{
		//変数参照情報取得
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return;
		//変数の参照をクリア
		ref->resetRef();
	}
	//変数の参照を全てクリア
	void resetRefAll()
	{
		//全体リードロック取得（解放は自動）
		WholeBLockR lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
		//全変数の参照をクリア
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
	//全体アクセスブロック開始
	bool beginBlock()
	{
		//ブロック中状態判定
		if (m_wholeLocked.load() == true)
			return false;
		//全体ライトロック取得
		CRWLockHelper(m_wholeLock).wLock(SPIN_COUNT);
		m_wholeLocked.store(true);//全体ブロック中状態開始
		m_wholeLockThreadID.store(CThreadID().getID());//現在のスレッドID記録
		return true;
	}
	//全体アクセスブロック終了
	//※内部で全変数参照のクリアを実行
	//※ブロックを行ったスレッドしか解除できない
	bool endBlock()
	{
		//ブロック中状態＆スレッド判定
		if (m_wholeLocked.load() == false || CThreadID() != m_wholeLockThreadID.load())
			return false;
		//全参照をクリア
		resetRefAll();
		//全体ライトロック解法
		CRWLockHelper(m_wholeLock).wUnlock();
		m_wholeLocked.store(false);//全体ブロック中状態解除
		m_wholeLockThreadID.store(INVALID_THREAD_ID);//現在のスレッドID記録クリア
		return true;
	}
private:
	//変数参照情報取得：共通部
	inline const RefNodeCore* findCore(const Key key, bool* is_exist) const
	{
		//全体リードロック取得（解放は自動）
		WholeBLockR lock(m_wholeLock, m_wholeLocked.load(), m_wholeLockThreadID.load());
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
	template<typename T>
	T get(const Key key, bool* is_exist = nullptr) const
	{
		const RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return static_cast<T>(0);
		ref->rLock();
		T val = ref->getVal<T>();
		ref->rUnlock();
		return val;
	}
	//bool型用
	bool getBool(const Key key, bool* is_exist = nullptr) const
	{
		return get<bool>(key, is_exist);
	}
	//int型用
	int getInt(const Key key, bool* is_exist = nullptr) const
	{
		return get<int>(key, is_exist);
	}
	//float型用
	float getFloat(const Key key, bool* is_exist = nullptr) const
	{
		return get<float>(key, is_exist);
	}
	//const char*型用
	const char* getStr(const Key key, bool* is_exist = nullptr) const
	{
		return get<const char*>(key, is_exist);
	}
	//----------
	//値を更新：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool set(const Key key, const T val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T now_val = ref->getVal<T>();
		if (prev_val)
			*prev_val = now_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//bool型用
	bool setBool(const Key key, const bool val, bool* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return set<bool>(key, val, prev_val, is_exist);
	}
	//int型用
	bool setInt(const Key key, const int val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return set<int>(key, val, prev_val, is_exist);
	}
	//float型用
	bool setFloat(const Key key, const float val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return set<float>(key, val, prev_val, is_exist);
	}
	//const char*型用
	bool setStr(const Key key, const char* str, const char** prev_val = nullptr, bool* is_exist = nullptr)
	{
		return set<const char*>(key, str, prev_val, is_exist);
	}
	//----------
	//CAS（Compare And Swap）：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool cas(const Key key, const T compare_val, const T swap_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T now_val = ref->getVal<T>();
		if (prev_val)
			*prev_val = now_val;
		if (ref->getVal<T>() == compare_val)
			ref->setVal<T>(swap_val);
		ref->wUnlock();
		return true;
	}
	//bool型用
	bool casBool(const Key key, const bool compare_val, const bool swap_val, bool* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return cas<bool>(key, compare_val, swap_val, prev_val, is_exist);
	}
	//int型用
	bool casInt(const Key key, const int compare_val, const int swap_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return cas<int>(key, compare_val, swap_val, prev_val, is_exist);
	}
	//float型用
	bool casFloat(const Key key, const float compare_val, const float swap_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return cas<float>(key, compare_val, swap_val, prev_val, is_exist);
	}
	//----------
	//値をインクリメント：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool inc(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val += static_cast<T>(1);
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool incInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return inc<int>(key, prev_val, is_exist);
	}
	//----------
	//値をデクリメント：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool dec(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val -= static_cast<T>(1);
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool decInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return dec<int>(key, prev_val, is_exist);
	}
	//----------
	//値を加算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool add(const Key key, const T add_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val += add_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool addInt(const Key key, const int add_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return add<int>(key, add_val, prev_val, is_exist);
	}
	//float型用
	bool addFloat(const Key key, const float add_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return add<float>(key, add_val, prev_val, is_exist);
	}
	//----------
	//値を減算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool sub(const Key key, const T sub_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val -= sub_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool subInt(const Key key, const int sub_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return sub<int>(key, sub_val, prev_val, is_exist);
	}
	//float型用
	bool subFloat(const Key key, const float sub_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return sub<float>(key, sub_val, prev_val, is_exist);
	}
	//----------
	//値を乗算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool mul(const Key key, const T mul_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val *= mul_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool mulInt(const Key key, const int mul_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return mul<int>(key, mul_val, prev_val, is_exist);
	}
	//float型用
	bool mulFloat(const Key key, const float mul_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return mul<float>(key, mul_val, prev_val, is_exist);
	}
	//----------
	//値を除算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool div(const Key key, const T div_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val /= div_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool divInt(const Key key, const int div_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return div<int>(key, div_val, prev_val, is_exist);
	}
	//float型用
	bool divFloat(const Key key, const float div_val, float* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return div<float>(key, div_val, prev_val, is_exist);
	}
	//----------
	//値を剰余算：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool mod(const Key key, const T mod_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val %= mod_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool modInt(const Key key, const int mod_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return mod<int>(key, mod_val, prev_val, is_exist);
	}
	//----------
	//値を反転：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool reverse(const Key key, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		ref->setVal<T>(~val);
		ref->wUnlock();
		return true;
	}
	//bool型用
	bool reverse(const Key key, bool* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		bool val = ref->getVal<bool>();
		if (prev_val)
			*prev_val = val;
		ref->setVal<bool>(val ? false : true );
		ref->wUnlock();
		return true;
	}
	//bool型用
	bool reverseBool(const Key key, bool* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return reverse(key, prev_val, is_exist);
	}
	//int型用
	bool reverseInt(const Key key, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return reverse<int>(key, prev_val, is_exist);
	}
	//----------
	//値を論理積：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool and(const Key key, const T and_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val &= and_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool andInt(const Key key, const int and_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return and<int>(key, and_val, prev_val, is_exist);
	}
	//----------
	//値を論理和：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool or(const Key key, const T or_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val |= or_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool orInt(const Key key, const int or_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return or<int>(key, or_val, prev_val, is_exist);
	}
	//----------
	//値を排他的論理和：型指定用
	//※prev_val で変更前の値を確認可能
	//※is_exist で参照先の変数の存在を確認可能
	template<typename T>
	bool xor(const Key key, const T xor_val, T* prev_val = nullptr, bool* is_exist = nullptr)
	{
		RefNodeCore* ref = find(key, is_exist);
		if (!ref)
			return false;
		ref->wLock();
		T val = ref->getVal<T>();
		if (prev_val)
			*prev_val = val;
		val ^= xor_val;
		ref->setVal<T>(val);
		ref->wUnlock();
		return true;
	}
	//int型用
	bool xorInt(const Key key, const int xor_val, int* prev_val = nullptr, bool* is_exist = nullptr)
	{
		return xor<int>(key, xor_val, prev_val, is_exist);
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
		//全体ブロック状態解除
		m_wholeLocked.store(false);
		m_wholeLockThreadID.store(INVALID_THREAD_ID);
	}
	//デストラクタ
	~CNamedRefT()
	{
		//ハッシュテーブルから全ノード削除
		unregistAll();
	}
private:
	//フィールド
	CPoolAllocatorWithBuff<REF_NODE_SIZE_MAX, MAX_NODES> m_allocator;//プールアロケータ（最大数以上の確保は不可）
	NamedRefTable m_namedRefList;//【暫定】C++11標準ライブラリのハッシュテーブル
	mutable CRWLock m_wholeLock;//全体ブロック用リード・ライトロック
	mutable std::atomic<bool> m_wholeLocked;//全体ブロック中
	mutable std::atomic<THREAD_ID> m_wholeLockThreadID;//全体ブロックスレッドID
};

//----------------------------------------
//名前付きデータ参照クラスシングルトン
//※テンプレートパラメータで記録可能な参照の最大数を指定
//※インスタンス識別IDを指定することで、複数のシングルトンを作成可能
template <std::size_t MAX, int ID = 0, int SPIN = CSpinLock::DEFAULT_SPIN_COUNT>
class CNamedRefSingletonT
{
public:
	//型
	typedef CNamedRefT<MAX, SPIN> NamedRef;//名前付きデータ参照クラス
public:
	//定数
	static const int INSTANCE_ID = ID;//インスタンス識別ID
public:
	//オペレータ
	operator NamedRef&() { return m_namedRef; }//キャストオペレータ
	const NamedRef* operator->() const { return &m_prosMap; }//アロー演算子（名前付きデータ参照クラスのプロキシー）
	NamedRef* operator->(){ return &m_namedRef; }//アロー演算子（名前付きデータ参照クラスのプロキシー）
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
//データ参照用関数オブジェクト作成マクロ：直接参照タイプ
#define NAMED_REF_FUNCTOR(name, code, type) \
	struct name : RefF<type> \
	{ \
	TYPE* operator()(const RefK& key) const \
		{ \
			code; \
		} \
	};
//データ参照用関数オブジェクト作成マクロ：直接参照タイプ：簡易版
#define NAMED_REF_FUNCTOR_DIRECT(name, var, type) \
	NAMED_REF_FUNCTOR(name, return &var, type)

//--------------------
//データ参照用関数オブジェクト作成マクロ：アクセッサタイプ
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
//データ参照用関数オブジェクト作成マクロ：アクセッサタイプ：簡易版
#define NAMED_ACCESSOR_FUNCTOR_SIMPLE(name, obj, getter_method, setter_method, type) \
	NAMED_ACCESSOR_FUNCTOR(name, return obj getter_method(), obj setter_method(val), type })

//----------------------------------------
//名前付きデータ参照クラスシングルトンインスタンス化
CNamedRef CNamedRefSingleton::m_namedRef;

//--------------------------------------------------------------------------------
//名前付きデータ参照クラステスト

//----------------------------------------
//テスト用構造体：キャラ情報
struct CCharaInfo
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
	CCharaInfo(const int id_, const char* name_, const int data1_, const float data2_, const int data3_):
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
	//キャラ情報
	static CCharaInfo s_charaInfoList[] =
	{
		{ 10, "太郎", 11, 111.1f, 1111 },
		{ 20, "次郎", 22, 222.2f, 2222 },
		{ 30, "三郎", 33, 333.3f, 3333 }
	};
	//キャラ情報検索関数
	static CCharaInfo* searchCharaInfo(const int id)
	{
		for (auto& o : s_charaInfoList)
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
	//struct refCharaInfo : RefF<CCharaInfo>{ TYPE *operator()(const RefK& key) const { return TEST::searchCharaInfo(key.m_sub); } };//キャラ情報参照用
	//※上記の構造体と同じことを「NAMED_REF_FUNCTOR」マクロで代用できる
	NAMED_REF_FUNCTOR_DIRECT(refDebugCpuMeter, TEST::s_debugCpuMeter, bool);//【デバッグ用】CPU使用率表示状態参照用
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam1, TEST::s_debugData1, int);//【デバッグ用】データ1参照用
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam2, TEST::s_debugData2, float);//【デバッグ用】データ2参照用
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam3, TEST::s_debugData3, const char*);//【デバッグ用】データ3参照用
	NAMED_REF_FUNCTOR_DIRECT(refDebugParam4, TEST::s_debugData4, short);//【デバッグ用】データ4参照用
	NAMED_REF_FUNCTOR(refCharaInfo, return TEST::searchCharaInfo(key.m_sub), CCharaInfo);//キャラ情報参照用

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
	struct refCharaInfoData3 : RefF<int>{//キャラ情報のData3アクセス用
		typedef CCharaInfo OBJ;
		static OBJ* search(const RefK& key){ return TEST::searchCharaInfo(key.m_sub); }
		struct getter{ TYPE operator()(const RefK& key) const { const OBJ* obj = search(key);  return obj ? obj->getData3() : 0; } };
		struct setter{ void operator()(const RefK& key, const TYPE val) { OBJ* obj = search(key); obj->setData3(val); } };
	};

	//名前付きデータ参照クラスシングルトン
	CNamedRefSingleton named_ref;

	//変数参照を登録：直接参照タイプ
	named_ref->regist(RefK("DebugCpuMeter"), refDebugCpuMeter());//【デバッグ用】CPU使用率表示状態
	named_ref->regist(RefK("DebugParam1"), refDebugParam1());//【デバッグ用】データ1
	named_ref->regist(RefK("DebugParam2"), refDebugParam2());//【デバッグ用】データ2
	named_ref->regist(RefK("DebugParam3"), refDebugParam3());//【デバッグ用】データ3
	named_ref->regist(RefK("DebugParam4"), refDebugParam4());//【デバッグ用】データ4
	named_ref->regist(RefK("CharaInfo", 10), refCharaInfo());//キャラ情報：ID=10
	named_ref->regist(RefK("CharaInfo", 20), refCharaInfo());//キャラ情報：ID=20
	named_ref->regist(RefK("CharaInfo", 30), refCharaInfo());//キャラ情報：ID=30
	//変数参照を登録：アクセッサタイプ
	named_ref->registAcc(RefK("DebugParam5"), refDebugParam5());//【デバッグ用】データ5
	named_ref->registAcc(RefK("CharaInfo::Data3", 10), refCharaInfoData3());//キャラ情報：Data3：ID=10
	named_ref->registAcc(RefK("CharaInfo::Data3", 20), refCharaInfoData3());//キャラ情報：Data3：ID=20
	named_ref->registAcc(RefK("CharaInfo::Data3", 30), refCharaInfoData3());//キャラ情報：Data3：ID=30
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
		CRefR<CCharaInfo> obj(named_ref, RefK("CharaInfo", id));//処理ブロックを抜けるまでロックを取得（自動開放）
		if (obj.isExist())
			printf("CharaInfo[id=%d]: {name=\"%s\", data1=%d, data2=%.3f, data3=%d}\n",
				obj->id, obj->name, obj->data1, obj->data2, named_ref->getInt(RefK("CharaInfo::Data3", id)));
	}
}

//----------------------------------------
//テスト関数③：名前付きデータ参照を使ってデータを更新
void testUpdateNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->set(RefK("DebugCpuMeter"), true);
	named_ref->set(RefK("DebugParam1"), 123);
	named_ref->set(RefK("DebugParam2"), 456.789f);
	named_ref->set(RefK("DebugParam3"), "New String");
	named_ref->set<short>(RefK("DebugParam4"), 12345);
	named_ref->set(RefK("DebugParam5"), 67890);
	{
		int id = 20;
		CRefW<CCharaInfo> obj(named_ref, RefK("CharaInfo", id));//処理ブロックを抜けるまでロックを取得（自動開放）
		if (obj.isExist())
		{
			obj->data1 = 321;
			obj->data2 = 987.654f;
		}
		named_ref->setInt(RefK("CharaInfo::Data3", id), 987654);
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
		named_ref->xorInt(RefK("CharaInfo::Data3", id), 0xffff);
	}
}

//----------------------------------------
//テスト関数⑤：名前付きデータ参照を使ってデータを演算２（演算１の前の状態に戻す逆計算）
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
		named_ref->xorInt(RefK("CharaInfo::Data3", id), 0xffff);
	}
}

//----------------------------------------
//テスト関数⑥：名前付きデータ参照を使ってデータを演算３（論理演算）
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
//テスト関数⑧：全体ブロック開始
void testBeginBlock()
{
	CNamedRefSingleton named_ref;
	named_ref->beginBlock();
}

//----------------------------------------
//テスト関数⑨：全体ブロック終了
void testEndBlock()
{
	CNamedRefSingleton named_ref;
	named_ref->endBlock();
}

//----------------------------------------
//テスト関数⑩：一部の名前付きデータ参照を登録解除
void testUnregistNamedRef()
{
	CNamedRefSingleton named_ref;
	named_ref->unregist(RefK("DebugParam1"));
	named_ref->unregist(RefK("DebugParam3"));
	named_ref->unregist(RefK("DebugParam5"));
	named_ref->unregist(RefK("CharaInfo", 20));
	named_ref->unregist(RefK("CharaInfo::Data3", 20));
}

//----------------------------------------
//テスト関数⑪：全ての名前付きデータ参照を登録解除
void testUnregistRefAll()
{
	CNamedRefSingleton named_ref;
	named_ref->unregistAll();
}

//----------------------------------------
//マルチスレッドテスト①：大量同時更新テスト
void readyTestThread1()//準備
{
	CNamedRefSingleton named_ref;
	named_ref->setInt(RefK("DebugParam1"), 0);//テストのために0クリア
}
void testThread1(const int n)//処理
{
	CNamedRefSingleton named_ref;
	for (int i = 0; i < 10000; ++ i)
		named_ref->addInt(RefK("DebugParam1"), n);//10000回nずつ加算
}

//----------------------------------------
//マルチスレッドテスト②:ブロック中のアクセステスト
void testThread2()
{
	CNamedRefSingleton named_ref;
	printf("----- THREAD:BEGIN -----\n");
	int param1 = named_ref->getInt(RefK("DebugParam1"));//データ取得
	printf("----- THREAD:SLEEP(param1=%d) -----\n", param1);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));//スリープ（この間にメイン側でデータ参照の登録が解除される）
	param1 = named_ref->getInt(RefK("DebugParam1"));//データ取得
	printf("----- THREAD:END(param1=%d) -----\n", param1);
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
	
	//テスト①：もう一度登録しても登録済みのキーは登録に失敗するだけ
	testRegistNamedRef();

	//テスト③：名前付きデータ参照を使ってデータを更新
	printf("----- set value -----\n");
	testUpdateNamedRef();
	testPrintNamedRef();
	
	//テスト④：名前付きデータ参照を使ってデータを演算１
	printf("----- calc value (1) -----\n");
	testCalcNamedRef1();
	testPrintNamedRef();
	
	//テスト⑤：名前付きデータ参照を使ってデータを演算２
	printf("----- calc value (2) -----\n");
	testCalcNamedRef2();
	testPrintNamedRef();
	
	//テスト⑥：名前付きデータ参照を使ってデータを演算３
	printf("----- calc value (3) -----\n");
	testCalcNamedRef3();
	testPrintNamedRef();
	
	//テスト関数⑦：名前付きデータ参照が内部で保持する参照をリセット
	printf("----- reset-ref all -----\n");
	testResetRefAll();
	testPrintNamedRef();

	//スレッドテスト①
	printf("----- thread test -----\n");
	std::thread th1ready = std::thread(readyTestThread1);//準備（param1を0クリア）
	th1ready.join();
	std::thread th1[10];
	int n = 1;
	for (auto& th1tmp : th1)
	{
		th1tmp = std::thread(testThread1, n++);
	}
	for (auto& th1tmp : th1)
	{
		th1tmp.join();
	}
	testPrintNamedRef();

	//テスト関数⑧：全体ブロック開始
	printf("----- begin block -----\n");
	testBeginBlock();
	testPrintNamedRef();

	//スレッドテスト②
	std::thread th2 = std::thread(testThread2);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));//スリープ（この間スレッド側の処理がブロックされる）

	//テスト③（再）：名前付きデータ参照を使ってデータを更新
	printf("----- set value : 2nd time -----\n");
	testUpdateNamedRef();
	testPrintNamedRef();
	
	//テスト関数⑨：全体ブロック終了
	printf("----- end block -----\n");
	testEndBlock();
	testPrintNamedRef();

	//テスト関数⑩：一部の名前付きデータ参照を登録解除
	printf("----- unregist -----\n");
	testUnregistNamedRef();
	testPrintNamedRef();
	
	//テスト関数⑪：全ての名前付きデータ参照を登録解除
	printf("----- unregist all -----\n");
	testUnregistRefAll();
	testPrintNamedRef();

	//スレッド終了待ち
	th2.join();

	return EXIT_SUCCESS;
}

// End of file
