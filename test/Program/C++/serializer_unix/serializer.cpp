//#define TLS_IS_WINDOWS//【MS固有仕様】TLSの宣言をWindowsスタイルにする時はこのマクロを有効にする
//#define USE_STRCPY_S//【MS固有仕様】strcpy_sを使用する時にこのマクロを有効にする
//#define USE_ALIGNED_MALLOC//【MS固有仕様】_aligned_mallocを使用する時はこのマクロを有効にする
//#define USE_FRIEND_WITH_NEW_OPERATOR//【MS固有仕様？】operator new()をクラス内でフレンド化する時はこのマクロを有効にする
//#define USE_WINDOWS_DEBUG_BREAK//【MS固有仕様】WindowのDebugBreakを使用

#define ENABLE_CONSTEXPR//【C++11用】constexprを有効にする時はこのマクロを有効にする
#define ENABLE_USER_DEFINED_LITERALS//【C++11用】ユーザー定義リテラルを有効にする時はこのマクロを有効にする

#include <stdio.h>
#include <stdlib.h>

#include <memory.h>//memcpy用
#include <assert.h>//assert用
#include <cstddef>//std::size_t用
#include <stdint.h>//uintptr_t用
#include <limits.h>//UCHAR_MAX用
#include <typeinfo.h>//type_id用
#include <map>//STL map用
#include <iterator>//std::iterator用
#include <vector>//STL vector用
#include <algorithm>//STL sort用
#include <atomic>//C++11アトミック操作
#include <thread>//C++11スレッド
#include <chrono>//C++11時間
#include <stdarg.h>//va_list用

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

//C++11互換用マクロ
#ifndef ENABLE_NULLPTR
#define nullptr NULL
#endif//ENABLE_NULLPTR
#ifndef ENABLE_OVERRIDE
#define overide
#endif//ENABLE_OVERRIDE
#ifdef ENABLE_CONSTEXPR
#define CONSTEXPR constexpr
#else//ENABLE_CONSTEXPR
#define CONSTEXPR const
#endif//ENABLE_CONSTEXPR

//--------------------
//CRC算出

#include <cstddef>//std::size_t用
#include <assert.h>//assert用

//--------------------
//型
typedef unsigned int crc32_t;//CRC32型

//--------------------
//CRC算出関数
namespace crc_inner_calc//直接使用しない処理を隠ぺいするためのネームスペース
{
#ifndef USE_CRC_CALC_TABLE
	//--------------------
	//CRC生成多項式計算（再帰処理）
	CONSTEXPR crc32_t calcPoly(crc32_t poly, const int n)
	{
		return n == 0 ? poly : calcPoly(poly & 1 ? 0xedb88320u ^ (poly >> 1) : (poly >> 1), n - 1);
	}
#else//USE_CRC_CALC_TABLE
	//--------------------
	//CRC生成多項式計算計算済みテーブル
	CONSTEXPR crc32_t s_calcTable[] =
	{
		0x00000000u, 0x77073096u, 0xee0e612cu, 0x990951bau, 0x076dc419u, 0x706af48fu, 0xe963a535u, 0x9e6495a3u,
		0x0edb8832u, 0x79dcb8a4u, 0xe0d5e91eu, 0x97d2d988u, 0x09b64c2bu, 0x7eb17cbdu, 0xe7b82d07u, 0x90bf1d91u,
		0x1db71064u, 0x6ab020f2u, 0xf3b97148u, 0x84be41deu, 0x1adad47du, 0x6ddde4ebu, 0xf4d4b551u, 0x83d385c7u,
		0x136c9856u, 0x646ba8c0u, 0xfd62f97au, 0x8a65c9ecu, 0x14015c4fu, 0x63066cd9u, 0xfa0f3d63u, 0x8d080df5u,
		0x3b6e20c8u, 0x4c69105eu, 0xd56041e4u, 0xa2677172u, 0x3c03e4d1u, 0x4b04d447u, 0xd20d85fdu, 0xa50ab56bu,
		0x35b5a8fau, 0x42b2986cu, 0xdbbbc9d6u, 0xacbcf940u, 0x32d86ce3u, 0x45df5c75u, 0xdcd60dcfu, 0xabd13d59u,
		0x26d930acu, 0x51de003au, 0xc8d75180u, 0xbfd06116u, 0x21b4f4b5u, 0x56b3c423u, 0xcfba9599u, 0xb8bda50fu,
		0x2802b89eu, 0x5f058808u, 0xc60cd9b2u, 0xb10be924u, 0x2f6f7c87u, 0x58684c11u, 0xc1611dabu, 0xb6662d3du,
		0x76dc4190u, 0x01db7106u, 0x98d220bcu, 0xefd5102au, 0x71b18589u, 0x06b6b51fu, 0x9fbfe4a5u, 0xe8b8d433u,
		0x7807c9a2u, 0x0f00f934u, 0x9609a88eu, 0xe10e9818u, 0x7f6a0dbbu, 0x086d3d2du, 0x91646c97u, 0xe6635c01u,
		0x6b6b51f4u, 0x1c6c6162u, 0x856530d8u, 0xf262004eu, 0x6c0695edu, 0x1b01a57bu, 0x8208f4c1u, 0xf50fc457u,
		0x65b0d9c6u, 0x12b7e950u, 0x8bbeb8eau, 0xfcb9887cu, 0x62dd1ddfu, 0x15da2d49u, 0x8cd37cf3u, 0xfbd44c65u,
		0x4db26158u, 0x3ab551ceu, 0xa3bc0074u, 0xd4bb30e2u, 0x4adfa541u, 0x3dd895d7u, 0xa4d1c46du, 0xd3d6f4fbu,
		0x4369e96au, 0x346ed9fcu, 0xad678846u, 0xda60b8d0u, 0x44042d73u, 0x33031de5u, 0xaa0a4c5fu, 0xdd0d7cc9u,
		0x5005713cu, 0x270241aau, 0xbe0b1010u, 0xc90c2086u, 0x5768b525u, 0x206f85b3u, 0xb966d409u, 0xce61e49fu,
		0x5edef90eu, 0x29d9c998u, 0xb0d09822u, 0xc7d7a8b4u, 0x59b33d17u, 0x2eb40d81u, 0xb7bd5c3bu, 0xc0ba6cadu,
		0xedb88320u, 0x9abfb3b6u, 0x03b6e20cu, 0x74b1d29au, 0xead54739u, 0x9dd277afu, 0x04db2615u, 0x73dc1683u,
		0xe3630b12u, 0x94643b84u, 0x0d6d6a3eu, 0x7a6a5aa8u, 0xe40ecf0bu, 0x9309ff9du, 0x0a00ae27u, 0x7d079eb1u,
		0xf00f9344u, 0x8708a3d2u, 0x1e01f268u, 0x6906c2feu, 0xf762575du, 0x806567cbu, 0x196c3671u, 0x6e6b06e7u,
		0xfed41b76u, 0x89d32be0u, 0x10da7a5au, 0x67dd4accu, 0xf9b9df6fu, 0x8ebeeff9u, 0x17b7be43u, 0x60b08ed5u,
		0xd6d6a3e8u, 0xa1d1937eu, 0x38d8c2c4u, 0x4fdff252u, 0xd1bb67f1u, 0xa6bc5767u, 0x3fb506ddu, 0x48b2364bu,
		0xd80d2bdau, 0xaf0a1b4cu, 0x36034af6u, 0x41047a60u, 0xdf60efc3u, 0xa867df55u, 0x316e8eefu, 0x4669be79u,
		0xcb61b38cu, 0xbc66831au, 0x256fd2a0u, 0x5268e236u, 0xcc0c7795u, 0xbb0b4703u, 0x220216b9u, 0x5505262fu,
		0xc5ba3bbeu, 0xb2bd0b28u, 0x2bb45a92u, 0x5cb36a04u, 0xc2d7ffa7u, 0xb5d0cf31u, 0x2cd99e8bu, 0x5bdeae1du,
		0x9b64c2b0u, 0xec63f226u, 0x756aa39cu, 0x026d930au, 0x9c0906a9u, 0xeb0e363fu, 0x72076785u, 0x05005713u,
		0x95bf4a82u, 0xe2b87a14u, 0x7bb12baeu, 0x0cb61b38u, 0x92d28e9bu, 0xe5d5be0du, 0x7cdcefb7u, 0x0bdbdf21u,
		0x86d3d2d4u, 0xf1d4e242u, 0x68ddb3f8u, 0x1fda836eu, 0x81be16cdu, 0xf6b9265bu, 0x6fb077e1u, 0x18b74777u,
		0x88085ae6u, 0xff0f6a70u, 0x66063bcau, 0x11010b5cu, 0x8f659effu, 0xf862ae69u, 0x616bffd3u, 0x166ccf45u,
		0xa00ae278u, 0xd70dd2eeu, 0x4e048354u, 0x3903b3c2u, 0xa7672661u, 0xd06016f7u, 0x4969474du, 0x3e6e77dbu,
		0xaed16a4au, 0xd9d65adcu, 0x40df0b66u, 0x37d83bf0u, 0xa9bcae53u, 0xdebb9ec5u, 0x47b2cf7fu, 0x30b5ffe9u,
		0xbdbdf21cu, 0xcabac28au, 0x53b39330u, 0x24b4a3a6u, 0xbad03605u, 0xcdd70693u, 0x54de5729u, 0x23d967bfu,
		0xb3667a2eu, 0xc4614ab8u, 0x5d681b02u, 0x2a6f2b94u, 0xb40bbe37u, 0xc30c8ea1u, 0x5a05df1bu, 0x2d02ef8du
	};
#endif//USE_CRC_CALC_TABLE
	//--------------------
	//文字列からCRC算出用（再帰処理）
	CONSTEXPR crc32_t calcStr(const crc32_t crc, const char* str)
	{
#ifndef USE_CRC_CALC_TABLE
		return *str == '\0' ? crc : calcStr(calcPoly(static_cast<crc32_t>((crc ^ *str) & 0xffu), 8) ^ (crc >> 8), str + 1);//CRC生成多項式計算計算を合成
#else//USE_CRC_CALC_TABLE
		return *str == '\0' ? crc : calcStr(s_calcTable[(crc ^ *str) & 0xffu] ^ (crc >> 8), str + 1);//CRC生成多項式計算計算済みテーブルの値を合成
#endif//USE_CRC_CALC_TABLE
	}
	//--------------------
	//データ長を指定してCRC算出用（再帰処理）
	CONSTEXPR crc32_t calcData(const crc32_t crc, const char* data, const std::size_t len)
	{
#ifndef USE_CRC_CALC_TABLE
		return len == 0 ? crc : calcData(calcPoly(static_cast<crc32_t>((crc ^ *data) & 0xffu), 8) ^ (crc >> 8), data + 1, len - 1);//CRC生成多項式計算計算を合成
#else//USE_CRC_CALC_TABLE
		return len == 0 ? crc : calcData(s_calcTable[(crc ^ *data) & 0xffu] ^ (crc >> 8), data + 1, len - 1);//CRC生成多項式計算計算済みテーブルの値を合成
#endif//USE_CRC_CALC_TABLE
	}
}
//--------------------
//【constexpr版】文字列からCRC算出
CONSTEXPR crc32_t calcConstCRC32(const char* str)
{
	return ~crc_inner_calc::calcStr(~0u, str);
}
//--------------------
//【constexpr版】データ長を指定してCRC算出
CONSTEXPR crc32_t calcConstCRC32(const char* data, const std::size_t len)
{
	return ~crc_inner_calc::calcData(~0u, data, len);
}
#ifdef ENABLE_USER_DEFINED_LITERALS
//--------------------
//【ユーザー定義リテラル版】データ長を指定してCRC算出
CONSTEXPR crc32_t operator "" _crc32(const char* str, std::size_t len)
{
	return calcConstCRC32(str, len);
}
#endif//ENABLE_USER_DEFINED_LITERALS
//--------------------
//【通常関数版】文字列からCRC算出
crc32_t calcCRC32(const char* str)
{
	crc32_t crc = ~0u;
	const char* p = str;
	while (*p)
	{
#ifndef USE_CRC_CALC_TABLE
		crc = crc_inner_calc::calcPoly(static_cast<crc32_t>((crc ^ *p) & 0xffu), 8) ^ (crc >> 8);//CRC生成多項式計算計算を合成
#else//USE_CRC_CALC_TABLE
		crc = crc_inner_calc::s_calcTable[(crc ^ *p) & 0xffu] ^ (crc >> 8);//CRC生成多項式計算計算済みテーブルの値を合成
#endif//USE_CRC_CALC_TABLE
		++p;
	}
	return ~crc;
}
//--------------------
//【通常関数版】データ長を指定してCRC算出
crc32_t calcCRC32(const char* data, const std::size_t len)
{
	crc32_t crc = ~0u;
	const char* p = data;
	for (std::size_t pos = 0; pos < len; ++pos, ++p)
	{
	#ifndef USE_CRC_CALC_TABLE
		crc = crc_inner_calc::calcPoly(static_cast<crc32_t>((crc ^ *p) & 0xffu), 8) ^ (crc >> 8);//CRC生成多項式計算計算を合成
	#else//USE_CRC_CALC_TABLE
		crc = crc_inner_calc::s_calcTable[(crc ^ *p) & 0xffu] ^ (crc >> 8);//CRC生成多項式計算計算済みテーブルの値を合成
	#endif//USE_CRC_CALC_TABLE
	}
	return ~crc;
}

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
//--------------------
//汎用固定バッファシングルトンテンプレートクラス
template<class T>
class CSingleton
{
	//配置newテンプレートをフレンド化
	template<class U>
	friend void* operator new(const std::size_t size, CSingleton<U>& singleton) throw();
public:
	//オペレータ（シングルトン本体のプロキシー）
	T* operator->(){ return m_singleton; }
	T& operator*(){ return *m_singleton; }
public:
	//メソッド
	//シングルトンインスタンスの明示的な破棄
	void destroy();
public:
	//コンストラクタ
	CSingleton();
private:
	//フィールド
	static T* m_singleton;//シングルトン本体参照
	static unsigned char m_singletonBuff[];//シングルトン本体用バッファ
};

//--------------------
//テンプレート配置new
template<class T>
void* operator new(const std::size_t size, CSingleton<T>& singleton) throw()
{
	return singleton.m_singletonBuff;//汎用シングルトンテンプレートクラス内のバッファを返す
}
//テンプレート配置delete
template<class T>
void operator delete(void* p, CSingleton<T>& singleton) throw()
{
	//なにもしない
}

//--------------------
//汎用固定バッファシングルトンテンプレートクラス：実装部
//明示的な削除
template<class T>
void CSingleton<T>::destroy()
{
	if (!m_singleton)
		return;
	m_singleton->~T();//デストラクタ呼び出し
	operator delete(m_singleton, *this);//配置delete呼び出し（なくてもよい）
	m_singleton = nullptr;
}
//コンストラクタ
template<class T>
CSingleton<T>::CSingleton()
{
	//まだ初期化していなければ初期化
	if (!m_singleton)
		m_singleton = new(*this)T();
}
//--------------------
//シングルトン静的変数のインスタンス化
template<class T>
T* CSingleton<T>::m_singleton = nullptr;//シングルトン参照
template<class T>
unsigned char CSingleton<T>::m_singletonBuff[sizeof(T)];//シングルトン用バッファ

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

#if 1
//--------------------
//配置new
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw()
{
	return allocator.alloc(size);
}
//配置delete
void operator delete(void* p, CPoolAllocator& allocator) throw()
{
	allocator.free(p);
}

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
	return allocator->alloc(size, align);
}
//配列版
void* operator new[](const std::size_t size) throw()
{
	CPolyAllocator allocator;
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//メモリ確保情報取得
	if (info)
		align = info->m_align;
	return allocator->alloc(size, align);
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
//シリアライズ
namespace serial
{
#define IS_LITTLE_ENDIAN//リトルエンディアン
//#define IS_BIG_ENDIAN//ビッグエンディアン

	//--------------------
	//バージョンクラス
	template<unsigned short MAJOR, unsigned short MINOR>
	class CVersionDefBase;
	class CVersion
	{
	public:
		//定数
		static const unsigned int VER_FIGURE = 1000000;//合成バージョン計算用桁上げ数
		enum compareEnum : char
		{
			EQ = 0,//==:EQual：同じ
			LT = -1,//<:Less Than：小さい
			GT = 1,//>:Greater Than：大きい
			MINOR_LT = -2,//マイナーバージョンのみ小さい（メジャーバージョンは一致）
			MINOR_GT = 2,//マイナーバージョンのみ大きい（メジャーバージョンは一致）
		};
	public:
		//アクセッサ
		unsigned int getMajor() const { return m_majorVer; };//メジャーバージョン
		unsigned int getMinor() const { return m_minorVer; };//マイナーバージョン
		unsigned int getVer()const { return m_ver; };//合成バージョン
		const unsigned int* getVerPtr()const { return &m_ver; };//合成バージョンのポインタ
		std::size_t getVerSize()const { return sizeof(m_ver); };//合成バージョンのサイズ
	public:
		//オペレータ
		bool operator==(const CVersion& rhs) const { return m_ver == rhs.m_ver; }
		bool operator!=(const CVersion& rhs) const { return m_ver != rhs.m_ver; }
		bool operator<(const CVersion& rhs) const { return m_ver < rhs.m_ver; }
		bool operator<=(const CVersion& rhs) const { return m_ver <= rhs.m_ver; }
		bool operator>(const CVersion& rhs) const { return m_ver > rhs.m_ver; }
		bool operator>=(const CVersion& rhs) const { return m_ver >= rhs.m_ver; }
	public:
		//キャストオペレータ
		operator unsigned int() const { return m_ver; }
	public:
		//メソッド
		//比較
		compareEnum compare(CVersion& rhs)
		{
			return	m_majorVer < rhs.m_majorVer ?
						LT :
						m_majorVer > rhs.m_majorVer ?
							GT :
							m_minorVer < rhs.m_minorVer ?
								MINOR_LT :
								m_minorVer > rhs.m_minorVer ?
									MINOR_GT :
									EQ;
		}
		//バージョンからジャーバージョンとマイナーバージョンを算出
		void calcFromVer()
		{
			*const_cast<unsigned short*>(&m_majorVer) = m_ver / VER_FIGURE;
			*const_cast<unsigned short*>(&m_minorVer) = m_ver % VER_FIGURE;
		}
	public:
		//デフォルトコンストラクタ
		CVersion() :
			m_majorVer(0),
			m_minorVer(0),
			m_ver(0)
		{}
		//コンストラクタ
		CVersion(const unsigned short major, const unsigned short minor) :
			m_majorVer(major),
			m_minorVer(minor),
			m_ver(major * VER_FIGURE + minor)
		{}
		template<unsigned short MAJOR, unsigned short MINOR>
		CVersion(CVersionDefBase<MAJOR, MINOR>&) :
			CVersion(MAJOR, MINOR)
		{}
	private:
		//フィールド
		const unsigned int m_ver;//バージョン
		const unsigned short m_majorVer;//メジャーバージョン
		const unsigned short m_minorVer;//マイナーバージョン
	};
	//--------------------
	//バージョンテンプレート基底クラス
	template<unsigned short MAJOR, unsigned short MINOR>
	class CVersionDefBase
	{
	public:
		//定数
		static const unsigned short MAJOR_VER = MAJOR;//メジャーバージョン
		static const unsigned short MINOR_VER = MINOR;//マイナーバージョン
		static const unsigned int VER = MAJOR_VER * CVersion::VER_FIGURE + MINOR_VER;//合成バージョン
	public:
		//アクセッサ
		unsigned int getMajor() const { return MAJOR_VER; };//メジャーバージョン
		unsigned int getMinor() const { return MINOR_VER; };//マイナーバージョン
		unsigned int getVer() const { return VER; };//合成バージョン
	};
	//--------------------
	//バージョンテンプレートクラス
	template<class T>
	class CVersionDef : public CVersionDefBase<0, 0>{};//規定では0

	//--------------------
	//データクラス用のバージョン定義マクロ
	#define SERIALIZE_VERSION_DEF(T, MAJOR, MINOR) \
		namespace serial \
		{ \
			template<> \
			struct CVersionDef<T> : public CVersionDefBase<MAJOR, MINOR>{}; \
		}

	//--------------------
	//汎用データ型指定用構造体
	struct str_t{};//文字列型
	struct bin_t{};//バイナリ型
	//--------------------
	//型操作基底クラス
	typedef std::size_t(*toMemFuncP)(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size);//メモリへコピー関数型
	typedef std::size_t(*fromMemFuncP)(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size);//メモリからコピー関数型
	typedef std::size_t(*toStrFuncP)(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size);//文字列へ変換関数型
	typedef std::size_t(*fromStrFuncP)(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max);//文字列から変換関数型
	class CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			if (mem_size < value_size)
			{
				//書き込み先のサイズの方が小さい場合
				//※書き込み先のサイズ分だけコピーする
				memcpy(mem, value_p, mem_size);
			}
			else if (mem_size > value_size)
			{
				//書き込み先のサイズの方が大きい場合
				//※後方をゼロクリア
				memcpy(mem, value_p, value_size);
				memset(reinterpret_cast<char*>(mem)+value_size, 0, mem_size - value_size);
			}
			else//if (mem_size == value_size)
			{
				//サイズが一致する場合
				//※そのままコピーするだけ
				memcpy(mem, value_p, mem_size);
			}
			return mem_size;
		}
		//※エンディアン調整版
		static std::size_t toMemAndAdjust(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			if (mem_size < value_size)
			{
				//書き込み先のサイズの方が小さい場合
			#ifdef IS_BIG_ENDIAN
				//※書き込み先のサイズ分だけ後方をコピーする
				memcpy(mem, reinterpret_cast<const char*>(value_p)+(value_size - mem_size), mem_size);
			#else//IS_BIG_ENDIAN
				//※書き込み先のサイズ分だけ前方をコピーする
				memcpy(mem, value_p, mem_size);
			#endif//IS_BIG_ENDIAN
			}
			else if (mem_size > value_size)
			{
				//書き込み先のサイズの方が大きい場合
			#ifdef IS_BIG_ENDIAN
				//※後詰めで前方をゼロクリア
				memcpy(reinterpret_cast<char*>(mem)+value_size, value_p, value_size);
				memset(mem, 0, mem_size - value_size);
			#else//IS_BIG_ENDIAN
				//※前詰めで後方をゼロクリア
				memcpy(mem, value_p, value_size);
				memset(reinterpret_cast<char*>(mem)+value_size, 0, mem_size - value_size);
			#endif//IS_BIG_ENDIAN
			}
			else//if (mem_size == value_size)
			{
				//サイズが一致する場合
				//※そのままコピーするだけ
				memcpy(mem, value_p, mem_size);
			}
			return mem_size;
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return toMem(value_p, value_size, mem, mem_size);
		}
		//※エンディアン調整版
		static std::size_t fromMemAndAdjust(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return toMemAndAdjust(value_p, value_size, mem, mem_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			std::size_t used = 0;
			std::size_t remain = str_max;
			char* write_p = str;
			if (remain > 3)
			{
				*(write_p++) = '[';
				++used;
				--remain;
			}
			const unsigned char* read_p = reinterpret_cast<const unsigned char*>(value_p);
			for (unsigned int i = 0; i < value_size && remain > 5 + 2; ++i)
			{
				const unsigned char c = *(read_p++);
				const unsigned char hi = c >> 4;
				const unsigned char lo = c & 0xf;
				if (i != 0)
				{
					*(write_p++) = ',';
					++used;
					--remain;
				}
				*(write_p++) = '0';
				*(write_p++) = 'x';
				*(write_p++) = hi >= 10 ? 'a' + hi : '0' + hi;
				*(write_p++) = lo >= 10 ? 'a' + lo : '0' + lo;
				used += 4;
				remain -= 4;
			}
			if (remain > 2)
			{
				*(write_p++) = ']';
				++used;
				--remain;
			}
			if (remain > 1)
				*(write_p) = '\0';
			return used;
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//デフォルトコンストラクタ
		CTypeCtrlBase() :
			m_toMemFuncP(toMem),
			m_fromMemFuncP(fromMem),
			m_toStrFuncP(toStr),
			m_fromStrFuncP(fromStr)
		{}
		//コピーコンストラクタ
		CTypeCtrlBase(const CTypeCtrlBase& src) :
			m_toMemFuncP(src.m_toMemFuncP),
			m_fromMemFuncP(src.m_fromMemFuncP),
			m_toStrFuncP(src.m_toStrFuncP),
			m_fromStrFuncP(src.m_fromStrFuncP)
		{}
		//コンストラクタ
		CTypeCtrlBase(toMemFuncP to_mem_func_p, fromMemFuncP from_mem_func_p, toStrFuncP to_func_p, fromStrFuncP from_func_p) :
			m_toMemFuncP(to_mem_func_p),
			m_fromMemFuncP(from_mem_func_p),
			m_toStrFuncP(to_func_p),
			m_fromStrFuncP(from_func_p)
		{}
		//デストラクタ
		~CTypeCtrlBase()
		{}
	public:
		//フィールド
		toMemFuncP m_toMemFuncP;//メモリへコピー関数
		fromMemFuncP m_fromMemFuncP;//メモリからコピー関数
		toStrFuncP m_toStrFuncP;//文字列へ変換関数
		fromStrFuncP m_fromStrFuncP;//文字列から変換関数
	};
	//--------------------
	//型操作化クラス
	template<typename T>
	class CTypeCtrl : public CTypeCtrlBase
	{
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase()
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<int> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const int value = *reinterpret_cast<const int*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%d", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%d", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t data_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<unsigned int> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned int value = *reinterpret_cast<const unsigned int*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%08x", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%08x", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<long> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const long value = *reinterpret_cast<const long*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%ld", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%ld", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t data_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<unsigned long> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned long value = *reinterpret_cast<const unsigned long*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%08lx", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%08lx", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<long long> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const long long value = *reinterpret_cast<const long long*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%lld", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%lld", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t data_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<unsigned long long> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned long long value = *reinterpret_cast<const unsigned long long*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%016llx", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%016llx", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<short> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const short value = *reinterpret_cast<const short*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%d", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%d", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<unsigned short> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned short value = *reinterpret_cast<const unsigned short*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%04x", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%04x", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<char> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const char value = *reinterpret_cast<const char*>(value_p);
			#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%d", value);
			#else//USE_STRCPY_S
			return sprintf(str, "%d", value);
			#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<unsigned char> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned char value = *reinterpret_cast<const unsigned char*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%02x", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%02x", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<float> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			//return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
			return CTypeCtrlBase::toMem(mem, mem_size, value_p, value_size);//エンディアン調整なしでコピー
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			if (mem_size == sizeof(double))
			{
				//double型と予測
				double value_from;
				CTypeCtrlBase::fromMem(mem, mem_size, &value_from, sizeof(value_from));
				const float value_to = static_cast<float>(value_from);
				CTypeCtrlBase::toMem(value_p, value_size, &value_to, sizeof(value_to));
			}
			else if (mem_size == sizeof(float))
			{
				//return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
				return CTypeCtrlBase::fromMem(mem, mem_size, value_p, value_size);//エンディアン調整なしでコピー
			}
			else
			{
				//整数型と予測
				long long value_from;
				CTypeCtrlBase::fromMem(mem, mem_size, &value_from, sizeof(value_from));
				const float value_to = static_cast<float>(value_from);
				CTypeCtrlBase::toMem(value_p, value_size, &value_to, sizeof(value_to));
			}
			return mem_size;
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const float value = *reinterpret_cast<const float*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%f", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%f", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<double> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			//return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
			return CTypeCtrlBase::toMem(mem, mem_size, value_p, value_size);//エンディアン調整なしでコピー
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			if (mem_size == sizeof(float))
			{
				//float型と予測
				float value_from;
				CTypeCtrlBase::fromMem(mem, mem_size, &value_from, sizeof(value_from));
				const double value_to = static_cast<float>(value_from);
				CTypeCtrlBase::toMem(value_p, value_size, &value_to, sizeof(value_to));
			}
			else if (mem_size == sizeof(double))
			{
				//return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
				return CTypeCtrlBase::fromMem(mem, mem_size, value_p, value_size);//エンディアン調整なしでコピー
			}
			else
			{
				//整数型と予測
				long long value_from;
				CTypeCtrlBase::fromMem(mem, mem_size, &value_from, sizeof(value_from));
				const double value_to = static_cast<double>(value_from);
				CTypeCtrlBase::toMem(value_p, value_size, &value_to, sizeof(value_to));
			}
			return mem_size;
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const double value = *reinterpret_cast<const double*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%llf", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%llf", value);
		#endif//USE_STRCPY_S
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<bin_t> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMem(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMem(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toStr(str, str_max, value_p, value_size);
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};
	//--------------------
	//型操作クラス
	template<>
	class CTypeCtrl<str_t> : public CTypeCtrlBase
	{
	public:
		//メソッド
		//メモリへコピー
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMem(mem, mem_size, value_p, value_size);
		}
		//メモリからコピー
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMem(mem, mem_size, value_p, value_size);
		}
		//文字列へ変換
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			std::size_t used = 0;
			std::size_t remain = str_max;
			char* write_p = str;
			if (remain > 1 + 1)
			{
				*(write_p++) = '\"';
				++used;
				--remain;
			}
			const unsigned char* read_p = reinterpret_cast<const unsigned char*>(value_p);
			for (unsigned int i = 0; i < value_size && remain > 1 + 1; ++i)
			{
				const unsigned char c = *(read_p++);
				if (c == '\0')
					break;
				*(write_p++) = c;
				++used;
				++remain;
			}
			if (remain > 1 + 1)
			{
				*(write_p++) = '\"';
				++used;
				--remain;
			}
			if (remain > 1)
				*(write_p) = '\0';
			return used;
		}
		//文字列から変換
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//未実装
			return 0;
		}
	public:
		//コンストラクタ
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//デストラクタ
		~CTypeCtrl()
		{}
	};

	//--------------------
	//クラス宣言
	class CItemBase;
	//--------------------
	//シリアライズ処理用関数オブジェクトテンプレートクラス
	//※シリアライズとデシリアライズ兼用共通処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct serialize {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, const T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//セーブ処理用関数オブジェクトテンプレートクラス
	//※シリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct save	{
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//ロード処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct load	{
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, const T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//ロード前処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※objのロードを開始する前に実行される
	//※標準では何もしない
	template<class Arc, class T>
	struct beforeLoad {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//ロード後処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※objのロードが一通り終わったあと実行される
	//※noticeUnrecognizedItem, noticeUnloadedItem の後に実行される
	//※標準では何もしない
	template<class Arc, class T>
	struct afterLoad {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//セーブデータにはあったが、保存先の指定がなく、ロードできなかった項目の通知
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※見つかったら時点で知されるので、objが不完全な状態である点に注意
	//※委譲データ項目 delegate_item にデータ項目をセットして返すとリトライしてそこに読み込む
	//※標準では何もしない
	template<class Arc, class T>
	struct noticeUnrecognizedItem {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, T& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unrecognized_item)
		{}
	};
	//--------------------
	//保存先の指定があるが、セーブデータになくロードできなかった項目の通知
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※objのロードが一通り終わったあと、まとめて通知する
	//※noticeUnrecognizedItem の後、afterLoad より先に実行される
	//※標準では何もしない
	template<class Arc, class T>
	struct noticeUnloadedItem {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, T& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unloaded_item)
		{}
	};
	//--------------------
	//データ収集処理用関数オブジェクトテンプレートクラス
	//※シリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※処理の中で使えるのは operator<<() のみ
	//　operator&() は禁止
	//※標準では何もしない
	template<class Arc, class T>
	struct collector {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//データ分配処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※処理の中で使えるのは operator>>() のみ
	//　operator&() は禁止
	//※収集処理で登録されたオブジェクトがセーブデータから見つかるごとに
	//　何度も呼び出される
	//※見つかったオブジェクトの情報（データ項目情報 = target_item）が渡される
	//※基本オブジェクト（obj）は、配列だった場合、その先頭の要素が渡される
	//※セーブデータ上の配列要素数と、ロードできた配列要素数（メモリ上の配列要素数）が渡される
	//※標準では何もしない
	template<class Arc, class T>
	struct distributor {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, T& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{}
	};
	//--------------------
	//データ分配前処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	template<class Arc, class T>
	struct beforeDistribute {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, T& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//データ分配後処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	template<class Arc, class T>
	struct afterDistribute {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, T& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//シリアライズ時に致命的エラー発生時処理用関数オブジェクトテンプレートクラス
	//※シリアライズ専用処理
	//※エラーが発生したタイミングではなく、最後に呼び出される
	//※特殊化によりユーザー処理を実装
	template<class Arc, class T>
	struct fatalSerializeErrorOccurred {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//デシリアライズ時に致命的エラー発生時処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※エラーが発生したタイミングではなく、最後に呼び出される
	//※特殊化によりユーザー処理を実装
	template<class Arc, class T>
	struct fatalDeserializeErrorOccurred {
		typedef int IS_UNDEFINED;//SFINAE用:関数オブジェクトの未定義チェック用の型定義
		void operator()(Arc& arc, const T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//ユーザー定義処理クラス定義済みチェック関数
	//※SFINAEにより、IS_UNDEFINED が定義されている型のオーバーロード関数が選ばれたら未定義とみなす
	template<class F>
	bool isDefinedFunctor(const typename F::IS_UNDEFINED)
	{
		return false;//未定義
	}
	template<class F>
	bool isDefinedFunctor(...)
	{
		return true;//定義済み
	}
	//--------------------
	//アーカイブダミークラス
	class CArchiveDummy{};
	//--------------------
	//オブジェクト型か？
	//※いずれかの関数オブジェクトが登録されていればオブジェクト型とみなす
	//※オブジェクト型はシリアライズの際にデータブロックとして扱う
	template<class T>
	bool hasAnyFunctor()
	{
		//ここでチェック：収集処理と分配処理は必ずワンセットで定義する必要あり
		assert((isDefinedFunctor<collector<CArchiveDummy, T> >(0)) == (isDefinedFunctor<distributor<CArchiveDummy, T> >(0)));
		//関数オブジェクトのどれか一つでも定義されているかチェック
		return isDefinedFunctor<serialize<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<save<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<load<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<beforeLoad<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<afterLoad<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<noticeUnrecognizedItem<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<noticeUnloadedItem<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<collector<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<distributor<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<beforeDistribute<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<afterDistribute<CArchiveDummy, T> >(0);
		//isDefinedFunctor<fatalSerializeErrorOccurred<CArchiveDummy, T> >(0);//これは数えない
		//isDefinedFunctor<fatalDeserializeErrorOccurred<CArchiveDummy, T> >(0);////これは数えない
	}
	//--------------------
	//データクラスのフレンド宣言用マクロ
	#define FRIEND_SERIALIZE(T) \
		template<class Arc, class T> \
		friend struct serial::serialize; \
		template<class Arc, class T> \
		friend struct serial::save; \
		template<class Arc, class T> \
		friend struct serial::load; \
		template<class Arc, class T> \
		friend struct serial::beforeLoad; \
		template<class Arc, class T> \
		friend struct serial::afterLoad; \
		template<class Arc, class T> \
		friend struct serial::noticeUnrecognizedItem; \
		template<class Arc, class T> \
		friend struct serial::noticeUnloadedItem; \
		template<class Arc, class T> \
		friend struct serial::collector; \
		template<class Arc, class T> \
		friend struct serial::distributor; \
		template<class Arc, class T> \
		friend struct serial::beforeDistribute; \
		template<class Arc, class T> \
		friend struct serial::afterDistribute; \
		template<class Arc, class T> \
		friend struct serial::fatalSerializeErrorOccurred; \
		template<class Arc, class T> \
		friend struct fatalDeserializeErrorOccurred;

	//--------------------
	//ポインタ型チェック用クラス
	//※テンプレートの部分特殊化を利用
	template<class T>
	struct isPtr
	{
		static const bool IS_PTR = false;//ポインタ型か？ = 非ポインタ型
		typedef T TYPE;//通常型（非ポインタ型）変換用の型
		typedef T* PTR_TYPE;//ポインタ型変換用の型
		static const T* TO_PTR(const T& var){ return reinterpret_cast<const T*>(&var); }//ポインタに変換
	};
	template<class T>
	struct isPtr<T*>
	{
		static const bool IS_PTR = true;//ポインタ型か？ = ポインタ型
		typedef T TYPE;//通常型（非ポインタ型）変換用の型
		typedef T* PTR_TYPE;//ポインタ型変換用の型
		static const T* TO_PTR(const T* var){ return var; }//ポインタに変換
	};
	//--------------------
	//データ項目属性
	enum itemAttrEnum : unsigned char
	{
		IS_OBJECT = 0x01,//オブジェクト型
		IS_ARRAY = 0x02,//配列型
		IS_PTR = 0x04,//ポインタ型
		IS_NULL = 0x08,//ヌル
		IS_VLEN = 0x10,//可変長か？
		HAS_VERSION = 0x20,//バージョン情報あり
	};
	class CItemAttr
	{
	public:
		//型
		typedef unsigned char value_t;//属性型
	public:
		//アクセッサ
		bool isObj() const { return (m_value & IS_OBJECT) ? true : false; }//オブジェクト型か？
		bool isArr() const { return (m_value & IS_ARRAY) ? true : false; }//配列型か？
		bool isPtr() const { return (m_value & IS_PTR) ? true : false; }//ポインタ型か？
		bool isNul() const { return (m_value & IS_NULL) ? true : false; }//ヌルポインタか？（ポインタ型の時だけ扱われる）
		bool isVLen() const { return (m_value & IS_VLEN) ? true : false; }//可変長か？（主に文字列ポインタの時に扱われる）
		bool hasVersion() const { return (m_value & HAS_VERSION) ? true : false; }//バージョン情報があるか？
		void setHasVersion() const { *const_cast<value_t*>(&m_value) = m_value | HAS_VERSION; }//バージョン情報ありにする
		void resetHasVersion() const { *const_cast<value_t*>(&m_value) = m_value & ~HAS_VERSION; }//バージョン情報なしにする
	public:
		//オペレータ
		bool operator==(const CItemAttr& rhs) const { return m_value == rhs.m_value; }
		bool operator!=(const CItemAttr& rhs) const { return m_value != rhs.m_value; }
		//コピーオペレータ
		CItemAttr& operator=(const CItemAttr& src)
		{
			*const_cast<value_t*>(&m_value) = src.m_value;
			return *this;
		}
	public:
		//メソッド
		//クリア
		void clear()
		{
			*const_cast<value_t*>(&m_value) = 0;
		}
	public:
		//コンストラクタ
		CItemAttr(const value_t info) :
			m_value(info)
		{}
		CItemAttr(const bool is_object, const bool is_array, const bool is_ptr, const bool is_null, const bool is_vlen) :
			m_value(
				(is_object ? IS_OBJECT : 0) |
				(is_array ? IS_ARRAY : 0) |
				(is_ptr ? IS_PTR : 0) |
				(is_ptr && is_null ? IS_NULL : 0) |
				(is_vlen ? IS_VLEN : 0)
				)
		{}
		//デストラクタ
		~CItemAttr()
		{}
	public://直接アクセス許可
		//フィールド
		const value_t m_value;//属性
	};
	//--------------------
	//データ項目情報基底クラス
	class CItemBase
	{
	public:
		//アクセッサ
		bool isObj() const { return m_attr.isObj(); }//オブジェクト型か？
		bool isArr() const { return m_attr.isArr(); }//配列型か？
		bool isPtr() const { return m_attr.isPtr(); }//ポインタ型か？
		bool isNul() const { return m_attr.isNul(); }//ヌルか？
		bool isVLen() const { return m_attr.isVLen(); }//可変長か？
		//【参考用】（セーブデータ上の）配列要素数を取得
		//※アーカイブ形式によっては正しくない可能性がある
		std::size_t getElemNum() const
		{
			return m_arrNum == 0 ?
						1 :
						m_arrNum;
		}
		//現在の配列要素数を取得
		std::size_t getNowElemNum() const
		{
			return	m_hasNowInfo ?
						m_nowArrNum == 0 ?
							1 :
							m_nowArrNum :
						0;
		}
		//【参考用】最小の配列要素数を取得
		//※アーカイブ形式によっては正しくない可能性がある
		std::size_t getMinimumElemNum() const
		{
			return	m_hasNowInfo ?
						m_arrNum < m_nowArrNum ?
							m_arrNum == 0 ?
								1 :
								m_arrNum :
							m_nowArrNum == 0 ?
								1 :
								m_nowArrNum :
						m_arrNum == 0 ?
							 1 :
							 m_arrNum;
		}
		bool nowIsObj() const { return m_hasNowInfo && m_nowAttr.isObj(); }//現在のデータはオブジェクト型か？
		bool nowIsArr() const { return m_hasNowInfo && m_nowAttr.isArr(); }//現在のデータは配列型か？
		bool nowIsPtr() const { return m_hasNowInfo && m_nowAttr.isPtr(); }//現在のデータはポインタ型か？
		bool nowIsNul() const { return m_hasNowInfo && m_nowAttr.isNul(); }//現在のデータはヌルか？
		bool nowIsVLen() const { return m_hasNowInfo && m_nowAttr.isVLen(); }//現在のデータは可変長か？
		bool nowAndSaveDataIsSameAttr() const { return m_hasNowInfo && m_nowAttr == m_attr; }//現在のデータとセーブデータの属性が一致するか？
		bool nowAndSaveDataIsDifferentAttr() const { return m_hasNowInfo && m_nowAttr != m_attr; }//現在のデータとセーブデータの属性が一致しないか？
		bool nowAndSaveDataIsObj() const { return m_hasNowInfo && m_nowAttr.isObj() && m_attr.isObj(); }//現在のデータもセーブデータもオブジェクト型か？
		bool nowAndSaveDataIsArr() const { return m_hasNowInfo && m_nowAttr.isArr() && m_attr.isArr(); }//現在のデータもセーブデータも配列型か？
		bool nowAndSaveDataIsPtr() const { return m_hasNowInfo && m_nowAttr.isPtr() && m_attr.isPtr(); }//現在のデータもセーブデータもポインタ型か？
		bool nowAndSaveDataIsNul() const { return m_hasNowInfo && m_nowAttr.isNul() && m_attr.isNul(); }//現在のデータもセーブデータもはヌルか？
		bool nowIsObjButSaveDataIsNot() const { return m_hasNowInfo && m_nowAttr.isObj() && !m_attr.isObj(); }//現在のデータはオブジェクト型だがセーブデータはそうではないか？
		bool nowIsArrButSaveDataIsNot() const { return m_hasNowInfo && m_nowAttr.isArr() && !m_attr.isArr(); }//現在のデータは配列型だがセーブデータはそうではないか？
		bool nowIsPtrButSaveDataIsNot() const { return m_hasNowInfo && m_nowAttr.isPtr() && !m_attr.isPtr(); }//現在のデータはポインタ型だがセーブデータはそうではないか？
		bool nowIsNulButSaveDataIsNot() const { return m_hasNowInfo && m_nowAttr.isNul() && !m_attr.isNul(); }//現在のデータはヌルだがセーブデータはそうではないか？
		bool nowIsNotObjButSaveDataIs() const { return m_hasNowInfo && !m_nowAttr.isObj() && m_attr.isObj(); }//現在のデータはオブジェクト型ではないがセーブデータはそうか？
		bool nowIsNotArrButSaveDataIs() const { return m_hasNowInfo && !m_nowAttr.isArr() && m_attr.isArr(); }//現在のデータは配列型ではないがセーブデータはそうか？
		bool nowIsNotPtrButSaveDataIs() const { return m_hasNowInfo && !m_nowAttr.isPtr() && m_attr.isPtr(); }//現在のデータはポインタ型ではないがセーブデータはそうか？
		bool nowIsNotNulButSaveDataIs() const { return m_hasNowInfo && !m_nowAttr.isNul() && m_attr.isNul(); }//現在のデータはヌルではないがセーブデータはそうか？
		bool nowSizeIsSame() const { return !isObj() && !isVLen() && m_hasNowInfo && m_nowItemSize == m_itemSize; }//現在のサイズの方とセーブデータのサイズが同じか？
		bool nowSizeIsSamall() const { return !isObj() && !isVLen() && m_hasNowInfo && m_nowItemSize < m_itemSize; }//現在のサイズの方がセーブデータのサイズより小さいか？
		bool nowSizeIsLarge() const { return !isObj() && !isVLen() && m_hasNowInfo && m_nowItemSize > m_itemSize; }//現在のサイズの方がセーブデータのサイズより大きいか？
		bool nowArrIsSame() const { return m_hasNowInfo && m_nowArrNum == m_arrNum; }//現在の配列サイズとセーブデータの配列サイズが同じか？
		bool nowArrIsSmall() const { return m_hasNowInfo && m_nowArrNum < m_arrNum; }//現在の配列サイズの方がセーブデータの配列サイズより小さいか？
		bool nowArrIsLarge() const { return m_hasNowInfo && m_nowArrNum > m_arrNum; }//現在の配列サイズの方がセーブデータの配列サイズより大きいか？
		bool hasNowInfo() const { return m_hasNowInfo; }//現在の情報コピー済み取得
		bool isOnlyOnSaveData() const{ return m_isOnlyOnSaveData; }//セーブデータ上にのみ存在するデータか？
		void setIsOnlyOnSaveData() const { m_isOnlyOnSaveData = true; m_isOnlyOnMem = false; }//セーブデータ上にのみ存在するデータかを更新
		void setIsOnlyOnSaveData(const bool enabled) const { if (enabled) setIsOnlyOnSaveData(); }//セーブデータ上にのみ存在するデータかを更新
		void resetIsOnlyOnSaveData() const { m_isOnlyOnSaveData = false; }//セーブデータ上にのみ存在するデータかをリセット
		bool isOnlyOnMem() const { return m_isOnlyOnMem; }//セーブデータ上にないデータか？
		void setIsOnlyOnMem() const { m_isOnlyOnMem = true; m_isOnlyOnSaveData = false; }//セーブデータ上にないデータかを更新
		void setIsOnlyOnMem(const bool enabled) const { if (enabled) setIsOnlyOnMem(); }//セーブデータ上にないデータかを更新
		void resetIsOnlyOnMem() const { m_isOnlyOnMem = false; }//セーブデータ上にないデータかをリセット
		bool isAlready() const { return m_isAlready; }//処理済みか？
		void setIsAlready() const { m_isAlready = true; }//処理済みにする
		void resetIsAlready() const { m_isAlready = false; }//処理済みを解除する
	public:
		//オペレータ
		bool operator==(const CItemBase& rhs) const { return m_nameCrc == rhs.m_nameCrc; }//データ項目名CRCで一致判定
		bool operator!=(const CItemBase& rhs) const { return m_nameCrc != rhs.m_nameCrc; }//データ項目名CRCで不一致判定
		bool operator==(const crc32_t name_crc) const { return m_nameCrc == name_crc; }//データ項目名CRCで一致判定
		bool operator!=(const crc32_t name_crc) const { return m_nameCrc != name_crc; }//データ項目名CRCで不一致判定
		bool operator==(const char* name) const { return m_nameCrc == calcCRC32(name); }//データ項目名CRCで一致判定
		bool operator!=(const char* name) const { return m_nameCrc != calcCRC32(name); }//データ項目名CRCで不一致判定
	public:
		//キャストオペレータ
		operator crc32_t() const { return m_nameCrc; }
		operator const char*() const { return m_name; }
		operator const std::type_info& () const { return *m_itemType; }
	public:
		//メソッド
		template<typename T>//値取得
		T& get(){ return *static_cast<T*>(const_cast<void*>(m_itemP)); }
		template<typename T>//値取得（配列要素）
		T& get(const int index){ return static_cast<T*>(const_cast<void*>(m_itemP))[index]; }
		template<typename T>//constで値取得
		const T& get() const { return *static_cast<const T*>(m_itemP); }
		template<typename T>//constで値取得（配列要素）
		const T& get(const int index) const { return static_cast<const T*>(m_itemP)[index]; }
		template<typename T>//constで値取得
		const T& getConst() const { return *static_cast<const T*>(m_itemP); }
		template<typename T>//constで値取得（配列要素）
		const T& getConst(const int index) const { return static_cast<const T*>(m_itemP)[index]; }
		//読み込み情報をクリア
		void clearForLoad()
		{
			//m_name = nullptr;//データ項目名
			*const_cast<crc32_t*>(&m_nameCrc) = 0;//データ項目名CRC
			//m_itemP;//データの参照ポインタ
			//m_itemType;//データの型情報
			*const_cast<std::size_t*>(&m_itemSize) = 0;//データサイズ
			*const_cast<std::size_t*>(&m_arrNum) = 0;//データの配列サイズ
			const_cast<CItemAttr*>(&m_attr)->clear();//属性
			m_nowItemSize = 0;//現在のデータサイズ
			m_nowArrNum = 0;//現在のデータの配列サイズ
			m_nowAttr.clear();//現在の属性
			m_hasNowInfo = false;//現在の情報コピー済み
			m_isOnlyOnSaveData = false;//セーブデータ上にのみ存在するデータ
			m_isOnlyOnMem = false;//セーブデータ上にないデータ
			m_isAlready = false;//処理済み
		}
		//現在の情報をコピー
		void copyFromOnMem(const CItemBase& src)
		{
			//assert(m_nameCrc == src.m_nameCrc);//全てをコピーする
			m_name = src.m_name;//データ項目名
			*const_cast<crc32_t*>(&m_nameCrc) = src.m_nameCrc;//データ項目名CRC
			m_itemP = src.m_itemP;//データの参照ポインタ
			m_itemType = src.m_itemType;//データの型情報
			m_nowItemSize = src.m_itemSize;//現在のデータサイズ
			m_nowArrNum = src.m_arrNum;//現在のデータの配列サイズ
			m_nowAttr = src.m_attr;//現在の属性
			m_nowTypeCtrl = src.m_typeCtrl;//型操作
			m_hasNowInfo = true;//現在の情報コピー済み
			m_isOnlyOnSaveData = false;//セーブデータ上にのみ存在するデータ
			m_isOnlyOnMem = false;//セーブデータ上にないデータ
			src.resetIsOnlyOnMem();//コピー元の「セーブデータ上にないデータ」をリセット
		}
		//強制的に全情報をコピー
		void copyForce(const CItemBase& src)
		{
			memcpy(this, &src, sizeof(*this));
		}
	public:
		//コピーコンストラクタ
		CItemBase(const CItemBase& src) :
			m_name(src.m_name),
			m_nameCrc(src.m_nameCrc),
			m_itemP(src.m_itemP),
			m_itemType(src.m_itemType),
			m_itemSize(src.m_itemSize),
			m_arrNum(src.m_arrNum),
			m_attr(src.m_attr),
			m_typeCtrl(src.m_typeCtrl),
			m_nowItemSize(src.m_nowItemSize),
			m_nowArrNum(src.m_nowArrNum),
			m_nowAttr(src.m_nowAttr),
			m_nowTypeCtrl(src.m_nowTypeCtrl),
			m_hasNowInfo(src.m_hasNowInfo),
			m_isOnlyOnSaveData(src.m_isOnlyOnSaveData),
			m_isOnlyOnMem(src.m_isOnlyOnMem),
			m_isAlready(src.m_isAlready)
		{}
		//デフォルトコンストラクタ
		CItemBase() :
			m_name(nullptr),
			m_nameCrc(0),
			m_itemP(nullptr),
			m_itemType(&typeid(void)),
			m_itemSize(0),
			m_arrNum(0),
			m_attr(false, false, false, false, false),
			m_typeCtrl(CTypeCtrlBase()),
			m_nowItemSize(0),
			m_nowArrNum(0),
			m_nowAttr(false, false, false, false, false),
			m_nowTypeCtrl(CTypeCtrlBase()),
			m_hasNowInfo(false),
			m_isOnlyOnSaveData(false),
			m_isOnlyOnMem(false),
			m_isAlready(false)
		{}
		//コンストラクタ
		CItemBase(const char* name, const void* item_p, const std::type_info& item_type, const std::size_t item_size, const std::size_t arr_num, const bool is_object, const bool is_ptr, const bool is_vlen, CTypeCtrlBase type_ctrl) :
			m_name(name),
			m_nameCrc(calcCRC32(name)),
			m_itemP(item_p),
			m_itemType(&item_type),
			m_itemSize(item_size),
			m_arrNum(arr_num),
			m_attr(is_object, arr_num > 0, is_ptr, item_p == nullptr, is_vlen),
			m_typeCtrl(type_ctrl),
			m_nowItemSize(0),
			m_nowArrNum(0),
			m_nowAttr(false, false, false, false, false),
			m_nowTypeCtrl(CTypeCtrlBase()),
			m_hasNowInfo(false),
			m_isOnlyOnSaveData(false),
			m_isOnlyOnMem(false),
			m_isAlready(false)
		{}
		//コンストラクタ
		CItemBase(const CItemBase& src, const void* item_p, const std::type_info& item_type, const std::size_t item_size, const std::size_t arr_num, const bool is_object, const bool is_ptr, const bool is_vlen, CTypeCtrlBase type_ctrl) :
			m_name(src.m_name),
			m_nameCrc(src.m_nameCrc),
			m_itemP(item_p),
			m_itemType(&item_type),
			m_itemSize(item_size),
			m_arrNum(arr_num),
			m_attr(is_object, arr_num > 0, is_ptr, item_p == nullptr, is_vlen),
			m_typeCtrl(type_ctrl),
			m_nowItemSize(0),
			m_nowArrNum(0),
			m_nowAttr(false, false, false, false, false),
			m_nowTypeCtrl(CTypeCtrlBase()),
			m_hasNowInfo(false),
			m_isOnlyOnSaveData(false),
			m_isOnlyOnMem(false),
			m_isAlready(false)
		{}
		//デストラクタ
		~CItemBase()
		{}
	public://フィールドを公開して直接操作
		//フィールド
		const char* m_name;//データ項目名
		const crc32_t m_nameCrc;//データ項目名CRC
		const void* m_itemP;//データの参照ポインタ
		const std::type_info* m_itemType;//データの型情報
		const std::size_t m_itemSize;//データサイズ
		const std::size_t m_arrNum;//データの配列サイズ
		const CItemAttr m_attr;//属性
		CTypeCtrlBase m_typeCtrl;//型操作
		std::size_t m_nowItemSize;//データサイズ　※現在のサイズ（デシリアライズ処理用）
		std::size_t m_nowArrNum;//データの配列サイズ　※現在のサイズ（デシリアライズ処理用）
		CItemAttr m_nowAttr;//属性　※現在の状態（デシリアライズ処理用）
		CTypeCtrlBase m_nowTypeCtrl;//型操作　※現在の状態（デシリアライズ処理用）
		bool m_hasNowInfo;//現在の情報コピー済み
		mutable bool m_isOnlyOnSaveData;//セーブデータ上にのみ存在するデータ
		mutable bool m_isOnlyOnMem;//セーブデータ上にないデータ
		mutable bool m_isAlready;//処理済み
	};
	//--------------------
	//データ項目情報テンプレートクラス
	template<typename T>
	class CItem : public CItemBase
	{
	public:
		//コンストラクタ
		CItem(const char* name, const T* item_p, const std::size_t arr_num, const bool is_ptr, const bool is_vlen) :
			CItemBase(name, item_p, typeid(T), sizeof(T), arr_num, hasAnyFunctor<T>(), is_ptr, is_vlen, CTypeCtrl<T>())
		{}
		CItem(const char* name, const std::size_t size, const T* item_p, const bool is_ptr, const bool is_vlen) :
			CItemBase(name, item_p, typeid(T), size, 0, hasAnyFunctor<T>(), is_ptr, is_vlen, CTypeCtrl<T>())
		{}
		CItem(const char* name, const std::size_t size) :
			CItemBase(name, nullptr, typeid(T), size, 0, hasAnyFunctor<T>(), false, false, CTypeCtrl<T>())
		{}
		CItem(const char* name) :
			CItemBase(name, nullptr, typeid(T), 0, 0, hasAnyFunctor<T>(), false, false, CTypeCtrl<T>())
		{}
		CItem(const CItemBase& src) :
			CItemBase(src)
		{}
		//デストラクタ
		~CItem()
		{}
	};
	//--------------------
	//データ項目情報作成テンプレート関数
	template<class T>
	CItem<typename isPtr<T>::TYPE> pair(const char* name, const T& item)
	{
		CItem<typename isPtr<T>::TYPE> item_obj(name, isPtr<T>::TO_PTR(item), 0, isPtr<T>::IS_PTR, false);
		return item_obj;
	}
	//--------------------
	//データ項目情報作成テンプレート関数（配列自動判定用）
	template<class T, std::size_t N>
	CItem<T> pair(const char* name, const T(&item)[N])
	{
		CItem<T> item_obj(name, item, N, false, false);
		return item_obj;
	}
	//--------------------
	//データ項目情報作成テンプレート関数（ポインタを配列扱いにしたい場合に使用）
	template<class T>
	CItem<typename isPtr<T>::TYPE> pairArray(const char* name, const T& item, const std::size_t N)
	{
		CItem<typename isPtr<T>::TYPE> item_obj(name, isPtr<T>::TO_PTR(item), N, isPtr<T>::IS_PTR, false);
		return item_obj;
	}
	//--------------------
	//データ項目情報作成テンプレート関数（バイナリ用）
	//※operator&()専用
	//※operator<<() / operator>>() には使用禁止
#if 1//バイナリ型扱いにする場合
	template<class T>
	CItem<bin_t> pairBin(const char* name, const T& item)
	{
		const std::size_t item_size = sizeof(T);
		const bin_t* item_p = reinterpret_cast<const bin_t*>(&item);
		CItem<bin_t> item_obj(name, item_size, item_p, false, false);
		return item_obj;
	}
#else//charの配列扱いにする場合
	template<class T>
	CItem<char> pairBin(const char* name, const T& item)
	{
		const std::size_t arra_num = sizeof(T);
		const char* item_p = reinterpret_cast<const char*>(&item);
		CItem<char> item_obj(name, item_p, arra_num, false, false);
		return item_obj;
	}
#endif
	//--------------------
	//データ項目情報作成テンプレート関数（文字列用）
	//※operator&()専用
	//※operator<<() / operator>>() には使用禁止
	template<std::size_t N>
	CItem<str_t> pairStr(const char* name, const char (&item)[N])
	{
		const std::size_t item_size = sizeof(char)* N;
		const str_t* item_p = reinterpret_cast<const str_t*>(&item);
		CItem<str_t> item_obj(name, item_size, item_p, false, true);
		return item_obj;
	}
	//※ポインタ用
	CItem<str_t> pairStr(const char* name, char* item, const std::size_t max_size)
	{
		const std::size_t item_size = max_size;//アーカイブ読み込み用のサイズ（アーカイブ書き込み時は実際の文字列長+1に更新する／ヌルなら0）
		const str_t* item_p = reinterpret_cast<const str_t*>(item);
		CItem<str_t> item_obj(name, item_size, item_p, true, true);
		return item_obj;
	}
	//--------------------
	//データ項目情報作成テンプレート関数（初回用）
	template<class T>
	CItem<T> pair(const char* name, const std::size_t size)
	{
		CItem<T> item_obj(name, size);
		return item_obj;
	}
	template<class T>
	CItem<T> pair(const char* name)
	{
		CItem<T> item_obj(name, 0);
		return item_obj;
	}
	
	//--------------------
	//処理結果クラス
	class CResult
	{
	public:
		//アクセッサ
		bool hasFatalError() const { return m_hasFatalError; }//致命的なエラーあり
		void setHasFatalError(){ m_hasFatalError = true; }//致命的なエラーあり
		void setHasFatalError(const bool enabled){ if (enabled) setHasFatalError(); }//致命的なエラーあり
		int getNumSmallerSizeItem() const { return m_numSmallerSizeItem; }//サイズが縮小されたデータ項目の数を取得
		int getNumLargerSizeItem() const { return m_numLargerSizeItem; }//サイズが拡大されたデータ項目の数を取得
		int getNumSmallerArrItem() const { return m_numSmallerArrItem; }//配列サイズが縮小されたデータ項目の数を取得
		int getNumLargerArrItem() const { return m_numLargerArrItem; }//配列サイズが拡大されたデータ項目の数を取得
		int getNumIsOnlyOnSaveData() const { return m_numIsOnlyOnSaveData; }//セーブデータ上にのみ存在するデータ項目の数を取得
		int getNumIsOnlyOnMem() const { return m_numIsOnlyOnMem; }//セーブデータ上にないデータ項目の数を取得
		int getNumIsObjOnSaveDataOnly() const { return m_numIsObjOnSaveDataOnly; }//現在オブジェクト型ではないが、セーブデータ上ではそうだったデータ項目の数を取得
		int getNumIsObjOnMemOnly() const { return m_numIsObjOnMemOnly; }//現在オブジェクト型だが、セーブデータ上ではそうではなかったデータ項目の数を取得
		int getNumIsArrOnSaveDataOnly() const { return m_numIsArrOnSaveDataOnly; }//現在配列型ではないが、セーブデータ上ではそうだったデータ項目の数を取得
		int getNumIsArrOnMemOnly() const { return m_numIsArrOnMemOnly; }//現在配列型だが、セーブデータ上ではそうではなかったデータ項目の数を取得
		int getNumIsPtrOnSaveDataOnly() const { return m_numIsPtrOnSaveDataOnly; }//現在ポインタ型ではないが、セーブデータ上ではそうだったデータ項目の数を取得
		int getNumIsPtrOnMemOnly() const { return m_numIsPtrOnMemOnly; }//現在ポインタ型だが、セーブデータ上ではそうではなかったデータ項目の数を取得
		int getNumIsNulOnSaveDataOnly() const { return m_numIsNulOnSaveDataOnly; }//現在ヌルではないが、セーブデータ上ではそうだったデータ項目の数を取得
		int getNumIsNulOnMemOnly() const { return m_numIsNulOnMemOnly; }//現在ヌルだが、セーブデータ上ではそうではなかったデータ項目の数を取得
		void addNumSmallerSizeItem(){ ++m_numSmallerSizeItem; }//サイズが縮小されたデータ項目の数をカウントアップ
		void addNumLargerSizeItem(){ ++m_numLargerSizeItem; }//サイズが拡大されたデータ項目の数をカウントアップ
		void addNumSmallerArrItem(){ ++m_numSmallerArrItem; }//配列サイズが縮小されたデータ項目の数をカウントアップ
		void addNumLargerArrItem(){ ++m_numLargerArrItem; }//配列サイズが拡大されたデータ項目の数をカウントアップ
		void addNumIsOnlyOnSaveData(){ ++m_numIsOnlyOnSaveData; }//セーブデータ上にのみ存在するデータ項目の数をカウントアップ
		void addNumIsOnlyOnMem(){ ++m_numIsOnlyOnMem; }//セーブデータ上にないデータ項目の数をカウントアップ
		void addNumIsObjOnSaveDataOnly(){ ++m_numIsObjOnSaveDataOnly; }//現在オブジェクト型ではないが、セーブデータ上ではそうだったデータ項目の数をカウントアップ
		void addNumIsObjOnMemOnly(){ ++m_numIsObjOnMemOnly; }//現在オブジェクト型だが、セーブデータ上ではそうではなかったデータ項目の数をカウントアップ
		void addNumIsArrOnSaveDataOnly(){ ++m_numIsArrOnSaveDataOnly; }///現在配列型ではないが、セーブデータ上ではそうだったデータ項目の数をカウントアップ
		void addNumIsArrOnMemOnly(){ ++m_numIsArrOnMemOnly; }//現在配列型だが、セーブデータ上ではそうではなかったデータ項目の数をカウントアップ
		void addNumIsPtrOnSaveDataOnly(){ ++m_numIsPtrOnSaveDataOnly; }//現在ポインタ型ではないが、セーブデータ上ではそうだったデータ項目の数をカウントアップ
		void addNumIsPtrOnMemOnly(){ ++m_numIsPtrOnMemOnly; }//現在ポインタ型だが、セーブデータ上ではそうではなかったデータ項目の数をカウントアップ
		void addNumIsNulOnSaveDataOnly(){ ++m_numIsNulOnSaveDataOnly; }//現在ヌルではないが、セーブデータ上ではそうだったデータ項目の数をカウントアップ
		void addNumIsNulOnMemOnly(){ ++m_numIsNulOnMemOnly; }//現在ヌルだが、セーブデータ上ではそうではなかったデータ項目の数をカウントアップ
		void addNumSmallerSizeItem(const bool enabled){ if (enabled) addNumSmallerSizeItem(); }//サイズが縮小されたデータ項目の数をカウントアップ
		void addNumLargerSizeItem(const bool enabled){ if (enabled) addNumLargerSizeItem(); }//サイズが拡大されたデータ項目の数をカウントアップ
		void addNumSmallerArrItem(const bool enabled){ if (enabled) addNumSmallerArrItem(); }//配列サイズが縮小されたデータ項目の数をカウントアップ
		void addNumLargerArrItem(const bool enabled){ if (enabled) addNumLargerArrItem(); }//配列サイズが拡大されたデータ項目の数をカウントアップ
		void addNumIsOnlyOnSaveData(const bool enabled){ if (enabled) addNumIsOnlyOnSaveData(); }//セーブデータ上にのみ存在するデータ項目の数をカウントアップ
		void addNumIsOnlyOnMem(const bool enabled){ if (enabled) addNumIsOnlyOnMem(); }//セーブデータ上にないデータ項目の数をカウントアップ
		void addNumIsObjOnSaveDataOnly(const bool enabled){ if (enabled) addNumIsObjOnSaveDataOnly(); }//現在オブジェクト型ではないが、セーブデータ上ではそうだったデータ項目の数をカウントアップ
		void addNumIsObjOnMemOnly(const bool enabled){ if (enabled) addNumIsObjOnMemOnly(); }//現在オブジェクト型だが、セーブデータ上ではそうではなかったデータ項目の数をカウントアップ
		void addNumIsArrOnSaveDataOnly(const bool enabled){ if (enabled) addNumIsArrOnSaveDataOnly(); }//現在配列型ではないが、セーブデータ上ではそうだったデータ項目の数をカウントアップ
		void addNumIsArrOnMemOnly(const bool enabled){ if (enabled) addNumIsArrOnMemOnly(); }//現在配列型だが、セーブデータ上ではそうではなかったデータ項目の数をカウントアップ
		void addNumIsPtrOnSaveDataOnly(const bool enabled){ if (enabled) addNumIsPtrOnSaveDataOnly(); }//現在ポインタ型ではないが、セーブデータ上ではそうだったデータ項目の数をカウントアップ
		void addNumIsPtrOnMemOnly(const bool enabled){ if (enabled) addNumIsPtrOnMemOnly(); }//現在ポインタ型だが、セーブデータ上ではそうではなかったデータ項目の数をカウントアップ
		void addNumIsNulOnSaveDataOnly(const bool enabled){ if (enabled) addNumIsNulOnSaveDataOnly(); }//現在ヌルではないが、セーブデータ上ではそうだったデータ項目の数をカウントアップ
		void addNumIsNulOnMemOnly(const bool enabled){ if (enabled) addNumIsNulOnMemOnly(); }//現在ヌルだが、セーブデータ上ではそうではなかったデータ項目の数をカウントアップ
		std::size_t getCopiedSize() const { return m_copiedSize; }//コピー済みサイズ取得
		std::size_t getSaveDataSize() const { return m_hasFatalError ? 0 : m_saveDataSize; }//セーブデータサイズ取得
		void setSaveDataSize(const std::size_t save_data_size){ m_saveDataSize = save_data_size; }//セーブデータサイズをセット
	public:
		//メソッド
		//コピー済みサイズ追加
		std::size_t addCopiedSize(const std::size_t size)
		{
			m_copiedSize += size;
			return m_copiedSize;
		}
		//処理結果に加算
		void addResult(const CResult& src)
		{
			setHasFatalError(src.m_hasFatalError);//致命的なエラーあり
			m_numSmallerSizeItem += src.m_numSmallerSizeItem;//サイズが縮小されたデータ項目の数
			m_numLargerSizeItem += src.m_numLargerSizeItem;//サイズが拡大されたデータ項目の数
			m_numSmallerArrItem += src.m_numSmallerArrItem;//配列サイズが縮小されたデータ項目の数
			m_numLargerArrItem += src.m_numLargerArrItem;//配列サイズが拡大されたデータ項目の数
			m_numIsOnlyOnSaveData += src.m_numIsOnlyOnSaveData;//セーブデータ上にのみ存在するデータ項目の数
			m_numIsOnlyOnMem += src.m_numIsOnlyOnMem;//セーブデータ上にないデータ項目の数
			m_numIsObjOnSaveDataOnly += src.m_numIsObjOnSaveDataOnly;//現在オブジェクト型ではないが、セーブデータ上ではそうだったデータ項目の数
			m_numIsObjOnMemOnly += src.m_numIsObjOnMemOnly;//現在オブジェクト型だが、セーブデータ上ではそうではなかったデータ項目の数
			m_numIsArrOnSaveDataOnly += src.m_numIsArrOnSaveDataOnly;//現在配列型ではないが、セーブデータ上ではそうだったデータ項目の数
			m_numIsArrOnMemOnly += src.m_numIsArrOnMemOnly;//現在配列型だが、セーブデータ上ではそうではなかったデータ項目の数
			m_numIsPtrOnSaveDataOnly += src.m_numIsPtrOnSaveDataOnly;//現在ポインタ型ではないが、セーブデータ上ではそうだったデータ項目の数
			m_numIsPtrOnMemOnly += src.m_numIsPtrOnMemOnly;//現在ポインタ型だが、セーブデータ上ではそうではなかったデータ項目の数
			m_numIsNulOnSaveDataOnly += src.m_numIsNulOnSaveDataOnly;//現在ヌルではないが、セーブデータ上ではそうだったデータ項目の数
			m_numIsNulOnMemOnly += src.m_numIsNulOnMemOnly;//現在ヌルだが、セーブデータ上ではそうではなかったデータ項目の数
			m_copiedSize += src.m_copiedSize;//コピー済みサイズ
		}
		//処理結果を計上
		void addResult(const CItemBase& src)
		{
			addNumSmallerSizeItem(src.nowSizeIsSamall());//サイズが縮小されたデータ項目の数
			addNumLargerSizeItem(src.nowSizeIsLarge());//サイズが拡大されたデータ項目の数
			addNumSmallerArrItem(src.nowArrIsSmall());//配列サイズが縮小されたデータ項目の数
			addNumLargerArrItem(src.nowArrIsLarge());//配列サイズが拡大されたデータ項目の数
			addNumIsOnlyOnSaveData(src.isOnlyOnSaveData());//セーブデータ上にのみ存在するデータ項目の数
			addNumIsOnlyOnMem(src.isOnlyOnMem());//セーブデータ上にないデータ項目の数
			addNumIsObjOnSaveDataOnly(src.nowIsNotObjButSaveDataIs());//現在オブジェクト型ではないが、セーブデータ上ではそうだったデータ項目の数
			addNumIsObjOnMemOnly(src.nowIsObjButSaveDataIsNot());//現在オブジェクト型だが、セーブデータ上ではそうではなかったデータ項目の数
			addNumIsArrOnSaveDataOnly(src.nowIsNotArrButSaveDataIs());//現在配列型ではないが、セーブデータ上ではそうだったデータ項目の数
			addNumIsArrOnMemOnly(src.nowIsArrButSaveDataIsNot());//現在配列型だが、セーブデータ上ではそうではなかったデータ項目の数
			addNumIsPtrOnSaveDataOnly(src.nowIsNotPtrButSaveDataIs());//現在ポインタ型ではないが、セーブデータ上ではそうだったデータ項目の数
			addNumIsPtrOnMemOnly(src.nowIsPtrButSaveDataIsNot());//現在ポインタ型だが、セーブデータ上ではそうではなかったデータ項目の数
			addNumIsNulOnSaveDataOnly(src.nowIsNotNulButSaveDataIs());//現在ヌルではないが、セーブデータ上ではそうだったデータ項目の数
			addNumIsNulOnMemOnly(src.nowIsNulButSaveDataIsNot());//現在ヌルだが、セーブデータ上ではそうではなかったデータ項目の数
		}
	public:
		//コンストラクタ
		CResult() :
			m_hasFatalError(false),
			m_numSmallerSizeItem(0),
			m_numLargerSizeItem(0),
			m_numSmallerArrItem(0),
			m_numLargerArrItem(0),
			m_numIsOnlyOnSaveData(0),
			m_numIsOnlyOnMem(0),
			m_numIsObjOnSaveDataOnly(0),
			m_numIsObjOnMemOnly(0),
			m_numIsArrOnSaveDataOnly(0),
			m_numIsArrOnMemOnly(0),
			m_numIsPtrOnSaveDataOnly(0),
			m_numIsPtrOnMemOnly(0),
			m_numIsNulOnSaveDataOnly(0),
			m_numIsNulOnMemOnly(0),
			m_copiedSize(0),
			m_saveDataSize(0)
		{}
		//デストラクタ
		~CResult()
		{}
	private:
		//フィールド
		bool m_hasFatalError;//致命的なエラーあり
		short m_numSmallerSizeItem;//サイズが縮小されたデータ項目の数
		short m_numLargerSizeItem;//サイズが拡大されたデータ項目の数
		short m_numSmallerArrItem;//配列サイズが縮小されたデータ項目の数
		short m_numLargerArrItem;//配列サイズが拡大されたデータ項目の数
		short m_numIsOnlyOnSaveData;//セーブデータ上にのみ存在するデータ項目の数
		short m_numIsOnlyOnMem;//セーブデータ上にないデータ項目の数
		short m_numIsObjOnSaveDataOnly;//現在オブジェクト型ではないが、セーブデータ上ではそうだったデータ項目の数
		short m_numIsObjOnMemOnly;//現在オブジェクト型だが、セーブデータ上ではそうではなかったデータ項目の数
		short m_numIsArrOnSaveDataOnly;//現在配列型ではないが、セーブデータ上ではそうだったデータ項目の数
		short m_numIsArrOnMemOnly;//現在配列型だが、セーブデータ上ではそうではなかったデータ項目の数
		short m_numIsPtrOnSaveDataOnly;//現在ポインタ型ではないが、セーブデータ上ではそうだったデータ項目の数
		short m_numIsPtrOnMemOnly;//現在ポインタ型だが、セーブデータ上ではそうではなかったデータ項目の数
		short m_numIsNulOnSaveDataOnly;//現在ヌルではないが、セーブデータ上ではそうだったデータ項目の数
		short m_numIsNulOnMemOnly;//現在ヌルだが、セーブデータ上ではそうではなかったデータ項目の数
		std::size_t m_copiedSize;//コピー済みサイズ
		std::size_t m_saveDataSize;//セーブデータサイズ
	};

	//--------------------
	//アーカイブ読み書き基底クラス
	typedef unsigned char byte;//バッファ用
	class CIOArchiveBase
	{
		friend class CIOArchiveHelper;
		friend class COArchiveHelper;
		friend class CIArchiveHelper;
	public:
		//型
		typedef std::map<crc32_t, const CItemBase> itemList_t;//データ項目リスト型
	public:
		//アクセッサ
		CResult& getResult(){ return m_result; }//処理結果を取得
		const CResult& getResult() const { return m_result; }//処理結果を取得
		bool hasFatalError() const { return m_result.hasFatalError(); }//致命的なエラーありか？
		std::size_t getSaveDataSize() const { return m_result.getSaveDataSize(); }//セーブデータサイズ取得
	protected:
		const byte* getBuffPtr() const { return m_buff; }//セーブデータバッファの先頭ポインタを取得
		const std::size_t getBuffSize() const { return m_buffSize; }//セーブデータバッファのサイズを取得
		const std::size_t getBuffUsed() const { return m_buffPos; }//セーブデータバッファの使用量を取得
		const std::size_t getBuffPos() const { return m_buffPos; }//セーブデータバッファの現在位置を取得
		const std::size_t getBuffRemain() const { return m_buffSize - m_buffPos; }//セーブデータバッファの残量を取得
		byte* getBuffNowPtr(){ return m_buff + m_buffPos; }//セーブデータバッファの現在位置のポインタを取得
		bool buffIsFull() const { return m_buffPos >= m_buffSize; }//バッファの現在位置が末端に到達したか？
		std::size_t getItemListNum() const { return m_itemList->size(); }//データ項目リスト
	protected:
		//メソッド
		//処理結果を合成
		void addResult(const CResult& src)
		{
			m_result.addResult(src);
		}
		//リストにデータ項目追加
		void addItem(const CItemBase& item)
		{
			//ワーク領域を設定（グローバル多態アロケータ）
			//※関数を抜けると自動的に元に戻る
			CTempPolyStackAllocator alloc(m_workBuff);

			//データ項目を追加
			assert(m_itemList->find(item.m_nameCrc) == m_itemList->end());
			m_itemList->emplace(item.m_nameCrc, item);
		}
		//リストからデータ項目を検索
		const CItemBase* findItem(const crc32_t name_crc) const
		{
			auto ite = m_itemList->find(name_crc);
			if (ite == m_itemList->end())//見つかったか？
				return nullptr;//見つからなかった
			return &ite->second;
		}
	private:
		//データリスト作成
		void createItemList()
		{
			//ワーク領域を設定（グローバル多態アロケータ）
			//※関数を抜けると自動的に元に戻る
			CTempPolyStackAllocator alloc(m_workBuff);

			//データ項目リストを生成
			m_itemList = new itemList_t;
		}
		//データリスト破棄
		void destroyItemList()
		{
			//ワーク領域を設定（グローバル多態アロケータ）
			//※関数を抜けると自動的に元に戻る
			CTempPolyStackAllocator alloc(m_workBuff);

			//データ項目リストを破棄
			if (m_itemList)
			{
				delete m_itemList;
				m_itemList = nullptr;
			}

			//ワークバッファ用スタックアロケータクリア
			m_workBuff.clearN();
		}
	protected:
		//コンストラクタ
		CIOArchiveBase(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_nestLevel(0),
			m_buff(reinterpret_cast<byte*>(buff)),
			m_buffSize(buff_size),
			m_buffPos(0),
			m_workBuff(work_buff, work_buff_size),
			m_itemList(nullptr)
		{
			//データリスト作成
			createItemList();
		}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		CIOArchiveBase(CIOArchiveBase& parent) :
			m_nestLevel(parent.m_nestLevel + 1),
			m_buff(parent.getBuffNowPtr()),
			m_buffSize(parent.getBuffRemain()),
			m_buffPos(0),
			m_workBuff(const_cast<IStackAllocator::byte*>(parent.m_workBuff.getNowPtrN()), parent.m_workBuff.getRemain()),
			m_itemList(nullptr)
		{
			//データリスト作成
			createItemList();
		}
		//デストラクタ
		~CIOArchiveBase()
		{
			//データリスト破棄
			destroyItemList();
		}
	protected:
		//フィールド
		CResult m_result;//処理結果
		int m_nestLevel;//データのネストレベル
		byte* m_buff;//セーブデータバッファ
		const std::size_t m_buffSize;//セーブデータバッファのサイズ
		std::size_t m_buffPos;//セーブデータバッファの処理位置
		CStackAllocator m_workBuff;//ワークバッファ用スタックアロケータ
		itemList_t* m_itemList;//データ項目リスト
	};
	//--------------------
	//アーカイブ書き込みクラス
	template<class STYLE>
	class COArchive : public CIOArchiveBase
	{
	public:
		//定数
		static const bool is_read = false;//読み込みクラスか？
		static const bool is_write = true;//書き込みクラスか？
	public:
		//型
		typedef STYLE arcStyle_t;//アーカイブ形式型
	private:
		//定数
		//ステート
		enum stateEnum : int
		{
			st_SERIALIZE,//シリアライズ中
			st_SERIALIZE_PHASE_BLOCK,//シリアライズ：ブロック処理フェーズ
			st_SERIALIZE_PHASE_ARRAY,//シリアライズ：配列ブロック処理フェーズ
			st_SERIALIZE_PHASE_ELEMENT,//シリアライズ：要素処理フェーズ
			st_SERIALIZE_PHASE_SAVE_DATA,//シリアライズ：データのセーブフェーズ
			st_SERIALIZE_PHASE_COLLECT,//シリアライズ：収集フェーズ
			st_SERIALIZE_PHASE_COLLECT_END,//シリアライズ：収集フェーズ終了
			st_SERIALIZE_END,//シリアライズ終了
		};
	private:
		//アクセッサ
		stateEnum getState() const { return m_state; }//ステートを取得
		stateEnum setState(const stateEnum state){ stateEnum prev = m_state; m_state = state; return prev; }//ステートを変更　※変更前のステートを返す
	public:
		//オペレータ
		//「&」オペレータ
		//※データ項目指定＆データ書き込み用処理
		template<class T>
		COArchive& operator&(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return *this;

			//現在処理中のアーカイブオブジェクト
			COArchive& arc = *this;

			//printf("[operator&] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//st_SERIALIZE_PHASE_SAVE_DATA 時以外にこの処理に来るのはプログラムに間違いがある
			//※収集処理で operator&() を使っている時など
			assert(arc.getState() == st_SERIALIZE_PHASE_SAVE_DATA);

			//文字列型専用処理
			if (typeid(T) == typeid(serial::str_t))
			{
				if (item_obj.m_itemP)
				{
					//文字列長を格納し直す
					*const_cast<std::size_t*>(&item_obj.m_itemSize) = strlen(reinterpret_cast<const char*>(item_obj.m_itemP)) + 1;
				}
				else
				{
					//ヌル時は0に
					*const_cast<std::size_t*>(&item_obj.m_itemSize) = 0;
				}
			}

			//データ項目を記録
			//※重複チェックのため
			addItem(item_obj);
			
			//データ書き込み
			if (item_obj.isObj())
			{
				//オブジェクトなら operator<<() で書き込み
				arc << item_obj;
			}
			else
			{
				//データをアーカイブに記録
				arc.m_style.writeDataItem(arc, item_obj, item_obj);

				//データ書き込み済み
				item_obj.setIsAlready();
			}
			
			return *this;
		}
		//「<<」オペレータ
		//※データ書き込み
		template<class T>
		COArchive& operator<<(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return *this;

			//現在処理中のアーカイブオブジェクト
			COArchive& arc = *this;

			//printf("[operator<<] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//st_SERIALIZE, st_SERIALIZE_PHASE_SAVE_DATA, st_SERIALIZE_PHASE_COLLECT 時以外に
			//この処理に来るのはプログラムに間違いがある
			assert(arc.getState() == st_SERIALIZE ||
				arc.getState() == st_SERIALIZE_PHASE_SAVE_DATA ||
				arc.getState() == st_SERIALIZE_PHASE_COLLECT);

			//オブジェクトでなければダメ
			//※何かしらのシリアライズ用関数オブジェクトを実装した型か？
			assert(item_obj.isObj() == true);

			//ネストレベルが0ならシグネチャーを書き込み
			if (m_nestLevel == 0)
				arc.m_style.writeSignature(arc);//シグネチャー書き込み
	
			//バージョン取得
			CVersionDef<T> ver_def;
			CVersion ver(ver_def);

			//ブロック開始情報書き込み
			arc.m_style.writeBlockHeader(arc, item_obj, ver);
			
			//ブロック開始
			std::size_t block_size = 0;//ブロックのサイズ
			
			{
				//ブロック処理用の子アーカイブオブジェクトを生成
				COArchive& parent_arc = arc;
				COArchive arc(parent_arc, st_SERIALIZE_PHASE_BLOCK);

				//ヌルでなければ処理する
				if (!item_obj.isNul() && !arc.hasFatalError())
				{
					//配列要素数取得
					const std::size_t array_elem_num = item_obj.m_arrNum;
					
					//配列ブロック開始情報書き込み
					arc.m_style.writeArrayHeader(arc, item_obj, array_elem_num);

					//配列ブロック開始
					std::size_t array_block_size = 0;//配列ブロックのサイズ

					{
						//配列ブロック処理用の孫アーカイブオブジェクトを生成
						COArchive& parent_arc = arc;
						COArchive arc(parent_arc, st_SERIALIZE_PHASE_ARRAY);

						//データ書き込み先の先頭ポインタ（配列の先頭）を記憶
						//※配列ループ処理中に item_obj.m_itemP を書き換えるので、元に戻せるようにしておく
						const void* item_p_top = item_obj.m_itemP;

						//要素ループ
						const std::size_t loop_elem_num = item_obj.getElemNum();//配列の要素数もしくは（配列じゃなければ）1を返す
						for (std::size_t index = 0; index < loop_elem_num && !arc.hasFatalError(); ++index)
						{
							//要素開始情報書き込み
							arc.m_style.writeElemHeader(arc, item_obj, index);

							//要素開始
							short items_num = 0;//データ項目数
							std::size_t elem_size = 0;//この要素のデータサイズ
							{
								//要素処理用のひ孫アーカイブオブジェクトを生成
								COArchive& parent_arc = arc;
								COArchive arc(parent_arc, st_SERIALIZE_PHASE_ELEMENT);
								
								//データのセーブフェーズに変更
								arc.setState(st_SERIALIZE_PHASE_SAVE_DATA);

								//シリアライズ処理（シリアライズ＆デシリアライズ兼用処理）呼び出し
								{
									serialize<COArchive, T> functor;
									functor(arc, item_obj.template getConst<T>(), ver, ver);
								}

								//セーブ処理（シリアライズ専用処理）呼び出し
								{
									save<COArchive, T> functor;
									functor(arc, item_obj.template getConst<T>(), ver);
								}

								//要素終了情報書き込み
								//※例えば、バイナリスタイルでは、要素のヘッダ部にデータ項目数とデータサイズを書き込み、
								//　要素の最後までシークする
								arc.m_style.writeElemFooter(parent_arc, arc, item_obj, index, items_num, elem_size);

								//要素終了
								//arc.m_style.finishWriteElem(parent_arc, arc, items_num, elem_size);

								//データ書き込み先のポインタを配列の次の要素に更新
								if (item_obj.m_itemP)
								{
									*const_cast<void**>(&item_obj.m_itemP) = reinterpret_cast<T*>(const_cast<void*>(item_obj.m_itemP)) + 1;
								}
							}
						}

						//配列の先頭ポインタ（元のポインタ）に戻す
						*const_cast<const void**>(&item_obj.m_itemP) = item_p_top;

						//配列ブロック終了情報書き込み
						//※例えば、バイナリスタイルでは、配列ブロックのヘッダ部に配列要素数とデータサイズを書き込み、
						//　要素の最後までシークする
						arc.m_style.writeArrayFooter(parent_arc, arc, item_obj, array_block_size);

						//配列ブロック終了
						//arc.m_style.finishWriteArray(parent_arc, arc, array_block_size);
					}
				}

				//データ収集処理（シリアライズ専用処理）呼び出し
				arc.setState(st_SERIALIZE_PHASE_COLLECT);
				{
					collector<COArchive, T> functor;
					functor(arc, item_obj.template getConst<T>(), ver);
				}
				arc.setState(st_SERIALIZE_PHASE_COLLECT_END);

				//ブロック終了情報書き込み
				//※例えば、バイナリスタイルでは、ブロックのヘッダ部にデータサイズを書き込み、
				//　ブロックの最後までシークする
				arc.m_style.writeBlockFooter(parent_arc, arc, item_obj, block_size);

				//ブロック終了
				//arc.m_style.finishWriteBlock(parent_arc, arc, block_size);
			}

			//ネストレベルが0ならターミネータを書き込み
			if (m_nestLevel == 0)
				arc.m_style.writeTerminator(arc);//ターミネータ書き込み
	
			//データ書き込み済みにする
			item_obj.setIsAlready();

			//処理結果にセーブデータサイズをセットする
			m_result.setSaveDataSize(getBuffUsed());

			//最終的に致命的なエラーがあれば呼び出し
			if (m_nestLevel == 0 && arc.hasFatalError())
			{
				fatalSerializeErrorOccurred<COArchive, T> functor;
				functor(arc, item_obj.template get<T>(), ver);
			}

			return *this;
		}
	public:
		//コンストラクタ
		COArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(buff, buff_size, work_buff, work_buff_size),
			m_parent(nullptr),
			m_style(),
			m_state(st_SERIALIZE)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		COArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(buff, BUFF_SIZE, work_buff, WORK_SIZE),
			m_parent(nullptr),
			m_style(),
			m_state(st_SERIALIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		COArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(buff, buff_size, work_buff, WORK_SIZE),
			m_parent(nullptr),
			m_style(),
			m_state(st_SERIALIZE)
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		COArchive(COArchive& parent, const stateEnum state) :
			CIOArchiveBase(parent),
			m_parent(&parent),
			m_style(parent.m_style),
			m_state(state)
		{}
		//デストラクタ
		~COArchive()
		{}
	private:
		//フィールド
		COArchive* m_parent;//親アーカイブオブジェクト
		arcStyle_t m_style;//アーカイブスタイルオブジェクト
		stateEnum m_state;//ステート
	};
	//--------------------
	//アーカイブ読み込みクラス
	template<class STYLE>
	class CIArchive : public CIOArchiveBase
	{
	public:
		//定数
		static const bool is_read = true;//読み込みクラスか？
		static const bool is_write = false;//書き込みクラスか？
	public:
		//型
		typedef STYLE arcStyle_t;//アーカイブ形式型
	private:
		//定数
		//ステート
		enum stateEnum : int
		{
			st_DESERIALIZE,//デシリアライズ中
			st_DESERIALIZE_PHASE_BLOCK,//シリアライズ：ブロック処理フェーズ
			st_DESERIALIZE_PHASE_ARRAY,//シリアライズ：配列ブロック処理フェーズ
			st_DESERIALIZE_PHASE_ELEMENT,//シリアライズ：要素処理フェーズ
			st_DESERIALIZE_PHASE_BEFORE_LOAD,//デシリアライズ：ロード前処理フェーズ
			st_DESERIALIZE_PHASE_MAKE_LIST,//デシリアライズ：対象データ項目リスト作成フェーズ
			st_DESERIALIZE_PHASE_LOAD_DATA,//デシリアライズ：データのロードフェーズ
			st_DESERIALIZE_PHASE_LOAD_OBJECT,//デシリアライズ：オブジェクトのロードフェーズ
			st_DESERIALIZE_PHASE_LOAD_OBJECT_END,//デシリアライズ：オブジェクトのロードフェーズ終了
			st_DESERIALIZE_PHASE_NOTICE_UNRECOGNIZED,//デシリアライズ：認識できなかったデータ項目の通知フェーズ
			st_DESERIALIZE_PHASE_NOTICE_UNLOADED,//デシリアライズ：ロードできなかったデータ項目の通知フェーズ
			st_DESERIALIZE_PHASE_AFTEER_LOAD,//デシリアライズ：ロード後処理フェーズ
			st_DESERIALIZE_PHASE_BEFORE_DISTRIBUTE,//デシリアライズ：分配前フェーズ
			st_DESERIALIZE_PHASE_DISTRIBUTE,//デシリアライズ：分配フェーズ
			st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT,//デシリアライズ：オブジェクトの分配フェーズ
			st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END,//デシリアライズ：オブジェクトの分配フェーズ終了
			st_DESERIALIZE_PHASE_AFTER_DISTRIBUTE,//デシリアライズ：分配後フェーズ
			st_DESERIALIZE_END,//デシリアライズ終了
		};
	private:
		//アクセッサ
		stateEnum getState() const { return m_state; }//ステートを取得
		stateEnum setState(const stateEnum state){ stateEnum prev = m_state; m_state = state; return prev; }//ステートを変更　※変更前のステートを返す
		CItemBase* getTargetObjItem(){ return m_targetObjItem; }//オブジェクト処理の対象データ項目をセット
		const CItemBase* getTargetObjItem() const { return m_targetObjItem; }//オブジェクト処理の対象データ項目をセット
		void setTargetObjItem(CItemBase& item){ m_targetObjItem = &item; }//オブジェクト処理の対象データ項目をセット
		void resetTargetObjItem(){ m_targetObjItem = nullptr; }//オブジェクト処理の対象データ項目をリセット
		CItemBase* getTargetObjItemDelegate(){ return m_targetObjItemDelegate; }//オブジェクト処理の対象データ項目の委譲データ項目をセット
		const CItemBase* getTargetObjItemDelegate() const { return m_targetObjItemDelegate; }//オブジェクト処理の対象データ項目の委譲データ項目をセット
		void setTargetObjItemDelegate(CItemBase* item){ m_targetObjItemDelegate = item; }//オブジェクト処理の対象データ項目の委譲データ項目をセット
		void resetTargetObjItemDelegate(){ m_targetObjItemDelegate = nullptr; }//オブジェクト処理の対象データ項目の委譲データ項目をリセット
	public:
		//オペレータ
		//「&」オペレータ
		//※データ項目指定用処理
		template<class T>
		CIArchive& operator&(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return *this;

			//現在処理中のアーカイブオブジェクト
			CIArchive& arc = *this;

			//printf("[operator&] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//st_DESERIALIZE_PHASE_MAKE_LIST, st_DESERIALIZE_PHASE_LOAD_OBJECT,
			//st_DESERIALIZE_PHASE_LOAD_OBJECT_END 時以外にこの処理に来るのはプログラムに間違いがある
			//※ロード前処理やロード後処理、通知処理、分配処理で operator&() を使っている時など
			assert(arc.getState() == st_DESERIALIZE_PHASE_MAKE_LIST ||
				arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT ||
				arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT_END ||
				arc.getState() == st_DESERIALIZE_PHASE_NOTICE_UNRECOGNIZED);

			//オブジェクト処理モード終了時はなにもしない
			if (arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
			{
				return *this;
			}
			//オブジェクト処理モード時は対象データ項目のみ処理する
			else if (arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT)
			{
				if (*m_targetObjItem == item_obj)
				{
					arc >> item_obj;//オブジェクト読み込み
					arc.setState(st_DESERIALIZE_PHASE_LOAD_OBJECT_END);//オブジェクト処理モード終了
				}
				return *this;
			}
			//認識できなかったオブジェクトの通知モード時は委譲データ項目をセットして終了する
			else if (arc.getState() == st_DESERIALIZE_PHASE_NOTICE_UNRECOGNIZED)
			{
				if (m_targetObjItemDelegate)
				{
					m_targetObjItemDelegate->copyForce(item_obj);
				}
				return *this;
			}

			//一旦は「セーブデータに存在しないデータ項目」という扱いにしておく
			//※ロード終了後もそのままならロードできなかったデータ項目として処理する
			item_obj.setIsOnlyOnMem();
			
			//データ項目を記録
			//※全ての記録が終わった後、データを読み込みながらデータ項目に書き込んでいく
			addItem(item_obj);
			
			return *this;
		}
		
		//「>>」オペレータ
		//※データ読み込み
		template<class T>
		CIArchive& operator>>(CItem<T> item_obj_now)
		{
			if (m_result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return *this;

			//現在処理中のアーカイブオブジェクト
			CIArchive& arc = *this;

			//printf("[operator>>] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj_now.m_name, item_obj_now.m_nameCrc, item_obj_now.m_itemType->name(), item_obj_now.m_itemP, item_obj_now.m_itemSize, item_obj_now.m_arrNum, item_obj_now.isObj(), item_obj_now.isArr(), item_obj_now.isPtr(), item_obj_now.isNul(), item_obj_now.isOnlyOnMem(), item_obj_now.isOnlyOnSaveData());

			//st_DESERIALIZE, st_DESERIALIZE_PHASE_MAKE_LIST, st_DESERIALIZE_PHASE_LOAD_DATA,
			//st_DESERIALIZE_PHASE_LOAD_OBJECT,st_DESERIALIZE_PHASE_LOAD_OBJECT_END 時以外に
			//この処理に来るのはプログラムに間違いがある
			//※ロード処理（ロード前後処理含む）、通知処理で operator>>() を使っている時など
			assert(arc.getState() == st_DESERIALIZE ||
				arc.getState() == st_DESERIALIZE_PHASE_MAKE_LIST ||
				arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT ||
				arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT_END ||
				arc.getState() == st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT ||
				arc.getState() == st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END);

			//データ項目リトライ処理⇒ブロック読み込みのための委譲データ項目を準備
			CItemBase* delebate_item = nullptr;

			//対象データ項目リスト作成フェーズ中なら operator&() に処理を回す
			if (arc.getState() == st_DESERIALIZE_PHASE_MAKE_LIST)
			{
				return *this & item_obj_now;
			}
			//オブジェクト処理モード時は委譲データ項目を取得する
			else if (arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT)
			{
				//委譲データ項目を取得
				delebate_item = m_targetObjItemDelegate;
			}
			//分配オブジェクト処理モード終了時はなにもしない
			else if (arc.getState() == st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END)
			{
				return *this;
			}
			//分配オブジェクトモード時は対象データ項目のみ処理する
			else if (arc.getState() == st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT)
			{
				if (*m_targetObjItem == item_obj_now)
				{
					//オブジェクト処理モード終了状態にして処理続行
					arc.setState(st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END);
				}
			}

			//パラメータチェック
			//assert(!item_obj_now.isOnlyOnSaveData());
			//※セーブデータにしか存在しないデータは処理不可
			//※配信処理を間違えて以内限り、そのような状態にはならないはず

			//ネストレベルが0ならパース
			if (m_nestLevel == 0)
				arc.m_style.parse(arc);//パース
			
			//ネストレベルが0ならシグネチャーを読み込み
			if (m_nestLevel == 0)
				arc.m_style.readSignature(arc);//シグネチャー読み込み
			
			//バージョン取得
			CVersionDef<T> now_ver_def;
			CVersion now_ver(now_ver_def);//現在のバージョン
			CVersion ver;//読み込み用のバージョン
			//ブロック開始情報読み込み
			std::size_t block_size = 0;
			CItem<T> item_obj(item_obj_now);
			arc.m_style.readBlockHeader(arc, item_obj_now, delebate_item, now_ver, item_obj, ver, block_size);
			//printf("  readDataItem:name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d\n", item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul());

			//ブロック開始
			{
				//ブロック処理用の子アーカイブオブジェクトを生成
				CIArchive& parent_arc = arc;
				CIArchive arc(parent_arc, st_DESERIALIZE_PHASE_BLOCK);
				
				//集計準備
				const std::size_t elem_num = item_obj.getElemNum();//要素数（配列要素ではなく、非配列なら1）
				std::size_t elem_num_loaded = 0;//実際に読み込んだ要素数（配列要素ではなく、非配列なら1）
				
				if (!item_obj.isNul() && !arc.hasFatalError())//【セーブデータ上の】要素がヌルでなければ処理する
				{

					//配列ブロック開始情報読み込み
					std::size_t array_elem_num = 0;//配列要素数
					std::size_t array_block_size = 0;//配列ブロックサイズ
					arc.m_style.readArrayHeader(arc, item_obj, array_elem_num, array_block_size);

					//配列ブロック開始
					{
						//配列ブロック処理用の孫アーカイブオブジェクトを生成
						CIArchive& parent_arc = arc;
						CIArchive arc(parent_arc, st_DESERIALIZE_PHASE_ARRAY);

						//データ読み込み先の先頭ポインタ（配列の先頭）を記憶
						//※配列ループ処理中に item_obj.m_itemP を書き換えるので、元に戻せるようにしておく
						const void* item_p_top = item_obj.m_itemP;

						//配列ループ
						//※ループ終了条件判定に index < elem_num は含めない
						//　（アーカイブスタイルによっては事前に正確な配列要素数が得られない可能性があるため）
						for (std::size_t index = 0; !arc.hasFatalError(); ++index)//【セーブデータ上の】配列要素数分データ読み込み
						{
							if (!item_obj.isArr())
							{
								//非配列要素の終了判定
								if (index == 1)
									break;
							}
							else
							{
								//配列ブロック終了判定
								bool is_array_block_end = true;
								arc.m_style.tryAndReadArrayFooter(arc, item_obj, is_array_block_end);
								if (is_array_block_end)
									break;//配列ブロックの終了を検出したらループから抜ける
							}

							//デバッグ用の変数キャスト
							const T* debug_p = reinterpret_cast<const T*>(item_obj.m_itemP);

							//有効な配列要素か？（有効でなければ処理せず読み込むだけ）
							const bool is_valid_element = (!item_obj.nowIsNul() && index < item_obj.getNowElemNum());
							if (is_valid_element)
								++elem_num_loaded;

							//要素開始情報読み込み
							std::size_t elem_size = 0;
							short items_num = 0;
							arc.m_style.readElemHeader(arc, item_obj, index, items_num, elem_size);

							//要素開始
							{
								//新しいアーカイブオブジェクトを生成
								CIArchive& parent_arc = arc;
								CIArchive arc(parent_arc, st_DESERIALIZE_PHASE_ELEMENT);

								//ロード前処理フェーズに変更
								arc.setState(st_DESERIALIZE_PHASE_BEFORE_LOAD);

								//ロード前処理（デシリアライズ専用処理）呼び出し
								if (is_valid_element)
								{
									beforeLoad<CIArchive, T> functor;
									functor(arc, item_obj.template get<T>(), ver, now_ver);
								}

								//対象データ項目リスト作成フェーズに変更
								arc.setState(st_DESERIALIZE_PHASE_MAKE_LIST);

								//デシリアライズ処理（シリアライズ＆デシリアライズ兼用処理）呼び出し
								//※データ項目リストを記録するだけ
								if (is_valid_element)
								{
									serialize<CIArchive, T> functor;
									functor(arc, item_obj.template getConst<T>(), ver, now_ver);
								}

								//ロード処理（デシリアライズ専用処理）呼び出し
								//※データ項目リストを記録するだけ
								if (is_valid_element)
								{
									load<CIArchive, T> functor;
									functor(arc, item_obj.template get<T>(), ver, now_ver);
								}

								//データのロードフェーズに変更
								arc.setState(st_DESERIALIZE_PHASE_LOAD_DATA);

								//実際のロード処理
								//※ループ終了条件判定に item_idx < items_num は含めない
								//　（アーカイブスタイルによっては事前に正確な項目数が得られない可能性があるため）
								for (short item_idx = 0; !arc.hasFatalError(); ++item_idx)
								{
									//要素終了情報読み込み
									bool is_elem_end = true;
									arc.m_style.tryAndReadElemFooter(arc, item_obj, index, is_elem_end);
									if (is_elem_end)
										break;//要素の終了を検出したらループから抜ける

									bool is_init = true;//初回処理
									bool is_required_retry = false;//リトライ処理要求
									bool is_already_retry = false;//リトライ処理済み
									CItemBase delegate_child_item_for_retry;//リトライ用の委譲項目（実体）
									CItemBase* delegate_child_item_now = nullptr;//リトライ用の委譲項目
									while (is_init || (is_required_retry && !is_already_retry))//リトライは一回だけ有効
									{
										is_init = false;//初回処理終了
										if (is_required_retry)//リトライ時
											is_already_retry = true;//リトライ済みにする（リトライは一回だけ）

										//要素の読み込み
										CItemBase child_item;
										arc.m_style.readDataItem(arc, item_obj, delegate_child_item_now, child_item, is_valid_element, is_required_retry);

										//ロードしたが保存先の指定がなかった項目の処理
										//※既にリトライしている場合は実行しない
										if (child_item.isOnlyOnSaveData() && !is_already_retry)
										{
											//通知フェーズに変更
											arc.setState(st_DESERIALIZE_PHASE_NOTICE_UNRECOGNIZED);

											//通知
											if (is_valid_element)
											{
												//委譲データ項目の受け取り用にインスタンスをセット
												arc.setTargetObjItemDelegate(&delegate_child_item_for_retry);

												//通知処理呼び出し
												noticeUnrecognizedItem<CIArchive, T> functor;
												functor(arc, item_obj.template get<T>(), ver, now_ver, child_item);

												//委譲データ項目の受け取り終了
												arc.resetTargetObjItemDelegate();

												//委譲データ項目の受け取り状態を判定
												if (delegate_child_item_for_retry.m_nameCrc != 0 && delegate_child_item_for_retry.m_itemP)
												{
													//委譲データ項目が設定されたのでリトライ
													delegate_child_item_now = &delegate_child_item_for_retry;
													is_required_retry = true;
												}
											}

											//データのロードフェーズに戻す
											arc.setState(st_DESERIALIZE_PHASE_LOAD_DATA);

											//リトライ
											//※オブジェクトの処理に入る前にリトライを実行
											if (is_required_retry)
												continue;
										}

										//オブジェクトの場合の処理
										if (child_item.isObj())
										{
											//オブジェクトのロードフェーズに変更
											arc.setState(st_DESERIALIZE_PHASE_LOAD_OBJECT);

											//オブジェクト処理対象データ項目をセット
											arc.setTargetObjItem(child_item);
											arc.setTargetObjItemDelegate(delegate_child_item_now);

											//通知処理呼び出し
											//※委譲データ項目がセットされている時のみ
											//if (arc.getState() != st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
											if (delegate_child_item_now)
											{
												noticeUnrecognizedItem<CIArchive, T> functor;
												functor(arc, item_obj.template get<T>(), ver, now_ver, child_item);
											}

											//デシリアライズ処理（シリアライズ＆デシリアライズ兼用処理）呼び出し
											//※対象オブジェクトアイテムを処理する
											if (arc.getState() != st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
											{
												serialize<CIArchive, T> functor;
												functor(arc, item_obj.template getConst<T>(), ver, now_ver);
											}

											//ロード処理（デシリアライズ専用処理）呼び出し
											//※対象オブジェクトアイテムを処理する
											if (arc.getState() != st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
											{
												load<CIArchive, T> functor;
												functor(arc, item_obj.template get<T>(), ver, now_ver);
											}

											//オブジェクト処理対象データ項目をリセット
											arc.resetTargetObjItem();
											arc.resetTargetObjItemDelegate();
											delegate_child_item_now = nullptr;

											//未処理のままだったらブロックをスキップする
											if (arc.getState() != st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
											{
												//オブジェクトのブロックをスキップ
												arc.m_style.skipReadBlock(arc);

												//処理済みにする
												child_item.setIsAlready();
											}

											//データのロードフェーズに戻す
											arc.setState(st_DESERIALIZE_PHASE_LOAD_DATA);
										}
									}
									//リトライ用の委譲項目リセット
									delegate_child_item_now = nullptr;
								}

								//処理されなかったデータ項目の処理
								for (auto& pair : *arc.m_itemList)
								{
									const CItemBase& child_item = pair.second;
									//保存先の指定があるが、セーブデータになくロードできなかった項目
									if (child_item.isOnlyOnMem())
									{
										//通知フェーズに変更
										arc.setState(st_DESERIALIZE_PHASE_NOTICE_UNLOADED);

										//処理結果計上
										arc.getResult().addResult(child_item);

										//通知処理呼び出し
										if (is_valid_element)
										{
											noticeUnloadedItem<CIArchive, T> functor;
											functor(arc, item_obj.template get<T>(), ver, now_ver, child_item);
										}
									}
								}

								//ロード後処理フェーズに変更
								arc.setState(st_DESERIALIZE_PHASE_AFTEER_LOAD);

								//ロード後処理（デシリアライズ専用処理）呼び出し
								if (is_valid_element)
								{
									afterLoad<CIArchive, T> functor;
									functor(arc, item_obj.template get<T>(), ver, now_ver);
								}

								//要素終了
								arc.m_style.finishReadElem(parent_arc, arc);
							}

							//データ読み込み先のポインタを配列の次の要素に更新
							if (item_obj.m_itemP)
							{
								*const_cast<void**>(&item_obj.m_itemP) = reinterpret_cast<T*>(const_cast<void*>(item_obj.m_itemP)) + 1;
							}
						}

						//配列の先頭ポインタ（元のポインタ）に戻す
						item_obj.m_itemP = item_p_top;

						//配列ブロック終了
						arc.m_style.finishReadArray(parent_arc, arc);
					}
				}
					
				//分配前フェーズに変更
				arc.setState(st_DESERIALIZE_PHASE_BEFORE_DISTRIBUTE);

				//分配前処理（デシリアライズ専用処理）呼び出し
				{
					beforeDistribute<CIArchive, T> functor;
					functor(arc, item_obj.template get<T>(), elem_num, elem_num_loaded, ver, now_ver);
				}

				//分配フェーズに変更
				arc.setState(st_DESERIALIZE_PHASE_DISTRIBUTE);

				//分配処理（デシリアライズ専用処理）呼び出し
				while (!arc.hasFatalError())
				{
					//ブロック終了判定
					bool is_block_end = true;
					arc.m_style.tryAndReadBlockFooter(arc, item_obj, is_block_end);
					if (is_block_end)
						break;//ブロックの終了を検出したらループから抜ける

					//オブジェクトブロック開始
					{
						//オブジェクトブロック処理用の子アーカイブオブジェクトを生成
						CIArchive& parent_arc = arc;
						CIArchive arc(parent_arc, st_DESERIALIZE_PHASE_DISTRIBUTE);

						//ブロック開始情報を仮読みし、分配処理に回す
						CItemBase require_item;
						std::size_t require_block_size = 0;
						bool is_found_next_block = false;
						arc.m_style.requireNextBlockHeader(arc, require_item, require_block_size, is_found_next_block);
						if (!is_found_next_block)
							break;//ブロックが見つからなかった場合もループから抜ける（ありえない？）

						//オブジェクト分配処理フェーズに変更
						arc.setState(st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT);

						//オブジェクト処理対象データ項目をセット
						arc.setTargetObjItem(require_item);

						//分配処理（デシリアライズ専用処理）呼び出し
						{
							distributor<CIArchive, T> functor;
							functor(arc, item_obj.template get<T>(), elem_num, elem_num_loaded, ver, now_ver, require_item);
						}

						//オブジェクト処理対象データ項目をリセット
						arc.resetTargetObjItem();

						//未処理のままだったらブロックをスキップする
						if (arc.getState() != st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END)
						{
							//オブジェクトのブロックをスキップ
							arc.m_style.skipReadBlock(arc);

							//処理済みにする
							require_item.setIsAlready();
						}

						//オブジェクトブロック終了
						arc.m_style.finishReadBlock(parent_arc, arc);
					}
				}

				//分配後フェーズに変更
				arc.setState(st_DESERIALIZE_PHASE_AFTER_DISTRIBUTE);

				//分配後処理（デシリアライズ専用処理）呼び出し
				{
					afterDistribute<CIArchive, T> functor;
					functor(arc, item_obj.template get<T>(), elem_num, elem_num_loaded, ver, now_ver);
				}

				//ブロック終了
				arc.m_style.finishReadBlock(parent_arc, arc);
			}
			
			//ネストレベルが0ならターミネータを読み込み
			if (m_nestLevel == 0)
				arc.m_style.readTerminator(arc);//ターミネータ読み込み
	
			//処理結果にセーブデータサイズをセットする
			m_result.setSaveDataSize(getBuffUsed());

			//最終的に致命的なエラーがあれば呼び出し
			if (m_nestLevel == 0 && arc.hasFatalError())
			{
				fatalDeserializeErrorOccurred<CIArchive, T> functor;
				functor(arc, item_obj.template get<T>(), ver, now_ver);
			}
			
			return *this;
		}
	public:
		//コンストラクタ
		CIArchive(const void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(const_cast<void*>(buff), buff_size, work_buff, work_buff_size),
			m_style(),
			m_state(st_DESERIALIZE),
			m_parent(nullptr),
			m_targetObjItem(nullptr),
			m_targetObjItemDelegate(nullptr)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(const BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(const_cast<BUFF_T*>(&buff[0]), BUFF_SIZE, work_buff, WORK_SIZE),
			m_style(),
			m_state(st_DESERIALIZE),
			m_parent(nullptr),
			m_targetObjItem(nullptr),
			m_targetObjItemDelegate(nullptr)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(const void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(const_cast<void*>(buff), buff_size, work_buff, WORK_SIZE),
			m_parent(nullptr),
			m_style(),
			m_state(st_DESERIALIZE),
			m_targetObjItem(nullptr),
			m_targetObjItemDelegate(nullptr)
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		CIArchive(CIArchive& parent, const stateEnum state) :
			CIOArchiveBase(parent),
			m_parent(&parent),
			m_style(parent.m_style),
			m_state(state),
			m_targetObjItem(nullptr),
			m_targetObjItemDelegate(nullptr)
		{}
		//デストラクタ
		~CIArchive()
		{}
	private:
		//フィールド
		CIArchive* m_parent;//親アーカイブオブジェクト
		arcStyle_t m_style;//アーカイブスタイルオブジェクト
		stateEnum m_state;//ステート
		CItemBase* m_targetObjItem;//オブジェクト処理の対象データ項目
		CItemBase* m_targetObjItemDelegate;//オブジェクト処理の対象データ項目の委譲データ項目
	};
	//--------------------
	//アーカイブ読み書き基本操作ヘルパークラス
	class CIOArchiveHelper
	{
	public:
		CResult& getResult(){ return m_arc.getResult(); }//処理結果を取得
		const CResult& getResult() const { return m_arc.getResult(); }//処理結果を取得
		bool hasFatalError() const { return m_arc.hasFatalError(); }//致命的なエラーありか？
		const byte* getBuffPtr() const { return m_arc.getBuffPtr(); }//セーブデータバッファの先頭ポインタを取得
		const std::size_t getBuffSize() const { return m_arc.getBuffSize(); }//セーブデータバッファのサイズを取得
		const std::size_t getBuffUsed() const { return m_arc.getBuffUsed(); }//セーブデータバッファの使用量を取得
		const std::size_t getBuffPos() const { return m_arc.getBuffPos(); }//セーブデータバッファの現在位置を取得
		const std::size_t getBuffRemain() const { return m_arc.getBuffRemain(); }//セーブデータバッファの残量を取得
		byte* getBuffNowPtr(){ return m_arc.getBuffNowPtr(); }//セーブデータバッファの現在位置のポインタを取得
		bool buffIsFull() const { return m_arc.buffIsFull(); }//バッファの現在位置が末端に到達したか？
		std::size_t getItemListNum() const { return m_arc.getItemListNum(); }//データ項目リスト
	public:
		//メソッド
		//処理結果を合成
		void addResult(const CResult& src){ m_arc.addResult(src); }
		//リストからデータ項目を検索
		const CItemBase* findItem(const crc32_t name_crc) const	{ return m_arc.findItem(name_crc); }
		//バッファのカレントポインタを移動
		//※範囲外への移動が要求されたら端まで移動して false を返す
		bool seek(const int seek_, int& real_seek)
		{
			const int used = static_cast<int>(m_arc.m_buffPos);
			const int remain = static_cast<int>(m_arc.getBuffRemain());
			real_seek = seek_ < 0 ?
				used >(-seek_) ?
			seek_ :
				  -used :
				  remain > seek_ ?
			  seek_ :
					remain;
			m_arc.m_buffPos = static_cast<std::size_t>(used + real_seek);
			return real_seek == seek_;
		}
		//※処理結果オブジェクト使用版
		bool seek(CResult& result, const int seek_)
		{
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			int real_seek = 0;
			//カレントポインタ移動
			const bool result_now = seek(seek_, real_seek);
			//処理結果記録
			if (!result_now)
				result.setHasFatalError();
			return result_now;
		}
	protected:
		//コンストラクタ
		CIOArchiveHelper(CIOArchiveBase& arc) :
			m_arc(arc)
		{}
		//デストラクタ
		~CIOArchiveHelper()
		{}
	protected:
		//フィールド
		CIOArchiveBase& m_arc;//アーカイブオブジェクト（セーブデータイメージバッファ）
	};
	//--------------------
	//アーカイブ書き込み基本操作ヘルパークラス
	class COArchiveHelper : public CIOArchiveHelper
	{
		template<class STYLE>
		friend class COArchive;
	public:
		//メソッド
		//バッファへのデータ書き込み
		//※要求サイズが全て書き込めなかったら false を返す
		bool write(const void* data, const std::size_t size, std::size_t& written_size)
		{
			const std::size_t remain = m_arc.getBuffRemain();
			written_size = remain > size ? size : remain;
			if (data)//データがヌルならサイズ分0で埋める
				memcpy(m_arc.m_buff + m_arc.m_buffPos, data, written_size);
			else//データコピー
				memset(m_arc.m_buff + m_arc.m_buffPos, 0, written_size);
			m_arc.m_buffPos += written_size;
			return written_size == size;
		}
		//※処理結果オブジェクト使用版
		bool write(CResult& result, const void* data, const std::size_t size, std::size_t* written_size = nullptr)
		{
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//データ書き込み
			std::size_t written_size_tmp = 0;
			const bool result_now = write(data, size, written_size_tmp);
			//処理結果記録
			result.addCopiedSize(written_size_tmp);
			if (!result_now)
				result.setHasFatalError();
			if (written_size)
				*written_size += written_size_tmp;
			return result_now;
		}
		//バッファへの文字列書き込み
		std::size_t print(CResult& result, const char* fmt, ...)
		{
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			const std::size_t remain = m_arc.getBuffRemain();
			va_list args;
			va_start(args, fmt);
		#ifdef USE_STRCPY_S
			const std::size_t ret = vsprintf_s(reinterpret_cast<char*>(m_arc.m_buff + m_arc.m_buffPos), remain, fmt, args);
		#else//USE_STRCPY_S
			const std::size_t ret = vsprintf(reinterpret_cast<char*>(m_arc.m_buff + m_arc.m_buffPos), fmt, args);
		#endif//USE_STRCPY_S
			va_end(args);
			m_arc.m_buffPos += ret;
			return ret;
		}
		//バッファへの文字列書き込み
		std::size_t printWithFunc(CResult& result, toStrFuncP to_str_func, const void* data_p, const std::size_t data_size)
		{
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			const std::size_t remain = m_arc.getBuffRemain();
			const std::size_t ret = to_str_func(reinterpret_cast<char*>(m_arc.m_buff + m_arc.m_buffPos), remain, data_p, data_size);
			m_arc.m_buffPos += ret;
			return ret;
		}
		//バッファへのインデント書き込み
		void printIndent(CResult& result, const int add)
		{
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return;
			const int remain = static_cast<int>(m_arc.getBuffRemain());
			int space_len = (static_cast<int>(m_arc.m_nestLevel) + add) * 2 + 1;
			space_len = space_len > 0 ? space_len : 0;
			space_len = space_len < remain ? space_len : remain;
			if (space_len >= 1)
			{
				memset(m_arc.m_buff + m_arc.m_buffPos, ' ', space_len);
				m_arc.m_buffPos += space_len;
				*(m_arc.m_buff + m_arc.m_buffPos) = '\0';
			}
		}
	public:
		//コンストラクタ
		COArchiveHelper(CIOArchiveBase& arc) :
			CIOArchiveHelper(arc)
		{}
		//デストラクタ
		~COArchiveHelper()
		{}
	};
	//--------------------
	//アーカイブ読み込み基本操作ヘルパークラス
	class CIArchiveHelper : public CIOArchiveHelper
	{
		template<class STYLE>
		friend class CIArchive;
	public:
		//メソッド
		//バッファからのデータ読み込み
		//※要求サイズが全て書き込めなかったら false を返す
		bool read(void* data, const std::size_t size, std::size_t& read_size)
		{
			const std::size_t remain = m_arc.getBuffRemain();
			read_size = remain > size ? size : remain;
			if (data)//dataがヌルならコピーしないがポインタは進める
				memcpy(data, m_arc.m_buff + m_arc.m_buffPos, read_size);
			m_arc.m_buffPos += read_size;
			return read_size == size;
		}
		//※処理結果オブジェクト使用版
		bool read(CResult& result, void* data, const std::size_t size, std::size_t* read_size = nullptr)
		{
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//データ読み込み
			std::size_t read_size_tmp = 0;
			const bool result_now = read(data, size, read_size_tmp);
			//処理結果記録
			if (!result_now)
				result.setHasFatalError();
			if (read_size)
				*read_size += read_size_tmp;
			return result_now;
		}
		//バッファからのデータ読み込み
		//※要求サイズが全て書き込めなかったら false を返す
		bool readWithFunc(fromMemFuncP from_mem_func, void* data, const std::size_t dst_size, const std::size_t src_size, std::size_t& read_size)
		{
			const std::size_t remain = m_arc.getBuffRemain();
			read_size = remain > src_size ? src_size : remain;
			if (data)//dataがヌルならコピーしないがポインタは進める
			{
				from_mem_func(m_arc.m_buff + m_arc.m_buffPos, read_size, data, dst_size);
			}
			m_arc.m_buffPos += read_size;
			return read_size == src_size;
		}
		//※処理結果オブジェクト使用版
		bool readWithFunc(CResult& result, fromMemFuncP from_mem_func, void* data, const std::size_t dst_size, const std::size_t src_size, std::size_t* read_size = nullptr)
		{
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//データ読み込み
			std::size_t read_size_tmp = 0;
			const bool result_now = readWithFunc(from_mem_func, data, dst_size, src_size, read_size_tmp);
			//処理結果記録
			if (!result_now)
				result.setHasFatalError();
			if (read_size)
				*read_size += read_size_tmp;
			return result_now;
		}
	public:
		//コンストラクタ
		CIArchiveHelper(CIOArchiveBase& arc) :
			CIOArchiveHelper(arc)
		{}
		//デストラクタ
		~CIArchiveHelper()
		{}
	};
	//--------------------
	//アーカイブ形式基底クラス
	class CArchiveStyleBase
	{
	public:
		//コンストラクタ
		CArchiveStyleBase()
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		CArchiveStyleBase(CArchiveStyleBase& parent)
		{}
		//デストラクタ
		~CArchiveStyleBase()
		{}
	};
	//--------------------
	//アーカイブ形式プロトタイプ（アーカイブ書き込み用）
	//※必要なメソッドを定義しているだけのサンプル（クラス追加のための参考用）
	//※実際には使用しない
	class COArchiveStyleProto : public CArchiveStyleBase
	{
	public:
		//メソッド
		//シグネチャ書き込み
		bool writeSignature(COArchiveHelper arc){ return true; }
		//ブロックヘッダー書き込み
		bool writeBlockHeader(COArchiveHelper arc, const CItemBase& item, const CVersion& ver){ return true; }
		//配列ブロックヘッダー書き込み
		bool writeArrayHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t array_elem_num){ return true; }
		//要素ヘッダー書き込み
		bool writeElemHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t index){ return true; }
		//データ項目書き込み
		bool writeDataItem(COArchiveHelper arc, const CItemBase& item, const CItemBase& child_item){ return true; }
		//要素フッター書き込み
		bool writeElemFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size){ return true; }
		//配列ブロックフッター書き込み
		bool writeArrayFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& array_block_size){ return true; }
		//ブロックフッター書き込み
		bool writeBlockFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& block_size){ return true; }
		//ターミネータ書き込み
		bool writeTerminator(COArchiveHelper arc){ return true; }
	public:
		//コンストラクタ
		COArchiveStyleProto() :
			CArchiveStyleBase()
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		COArchiveStyleProto(COArchiveStyleProto& parent) :
			CArchiveStyleBase(parent)
		{}
		//デストラクタ
		~COArchiveStyleProto()
		{}
	};
	//--------------------
	//アーカイブ形式プロトタイプ（アーカイブ読み込み用）
	//※必要なメソッドを定義しているだけのサンプル（クラス追加のための参考用）
	//※実際には使用しない
	class CIArchiveStyleProto : public CArchiveStyleBase
	{
	public:
		//メソッド
		//パース
		bool parse(CIArchiveHelper arc){ return true; }
		//シグネチャ読み込み
		bool readSignature(CIArchiveHelper arc){ return true; }
		//ブロックヘッダー読み込み
		//※読み込んだオブジェクトの型情報とバージョンを返す
		bool readBlockHeader(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_item, const CVersion& ver, CItemBase& input_item, CVersion& input_ver, std::size_t& block_size){ return true; }
		//配列ブロックヘッダー読み込み
		bool readArrayHeader(CIArchiveHelper arc, const CItemBase& item, std::size_t& array_elem_num, std::size_t& array_block_size){ return true; }
		//要素ヘッダー読み込み
		bool readElemHeader(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size){ return true; }
		//データ項目読み込み
		bool readDataItem(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_child_item_now, CItemBase& child_item, const bool item_is_valid, const bool is_required_retry){ return true; }
		//要素フッター読み込み
		//※読み込みテストの結果、要素フッターでなければデータ項目の読み込みを継続する
		bool tryAndReadElemFooter(CIArchiveHelper child_arc, const CItemBase& item, const std::size_t index, bool& is_elem_end){ return true; }
		//要素読み込み終了
		bool finishReadElem(CIArchiveHelper parent_arc, CIArchiveHelper child_arc){ return true; }
		//配列ブロックフッター読み込み
		//※読み込みテストの結果、配列ブロックフッターでなければデータ項目の読み込みを継続する
		bool tryAndReadArrayFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_array_block_end){ return true; }
		//配列ブロック読み込み終了
		bool finishReadArray(CIArchiveHelper parent_arc, CIArchiveHelper child_arc){ return true; }
		//ブロックの読み込みをスキップ
		bool skipReadBlock(CIArchiveHelper arc){ return true; }
		//ブロックフッター読み込み
		//※読み込みテストの結果、ブロックフッターでなければデータ項目（オブジェクト）の読み込みを継続する
		bool tryAndReadBlockFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_block_end){ return true; }
		//ブロック読み込み終了
		bool finishReadBlock(CIArchiveHelper parent_arc, CIArchiveHelper child_arc){ return true; }
		//次のブロックヘッダー問い合わせ（先行読み込み）
		//※処理を進めず、次の情報を読み取るのみ
		//※（例えば、バイナリスタイルなら、読み込みバッファのポインタを進めない）
		bool requireNextBlockHeader(CIArchiveHelper arc, CItemBase& require_item, std::size_t& child_block_size, bool& is_found_next_block){ return true; }
		//ターミネータ読み込み
		bool readTerminator(CIArchiveHelper arc){ return true; }
	public:
		//コンストラクタ
		CIArchiveStyleProto() :
			CArchiveStyleBase()
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		CIArchiveStyleProto(CIArchiveStyleProto& parent) :
			CArchiveStyleBase(parent)
		{}
		//デストラクタ
		~CIArchiveStyleProto()
		{}
	};
	//--------------------
	//バイナリ形式アーカイブクラス（共通）
	class CArchiveStyleBinaryBase : public CArchiveStyleBase
	{
	public:
		//定数
		static const std::size_t SIGNATURE_SIZE = 16;//シグネチャサイズ
		static const std::size_t TERMINATOR_SIZE = 16;//ターミネータサイズ
		static const std::size_t BEGIN_MARK_SIZE = 2;//各種始端マークサイズ
		static const std::size_t END_MARK_SIZE = 2;//各種終端マークサイズ
		static const unsigned char SIGNATURE[SIGNATURE_SIZE];//シグネチャ
		static const unsigned char TERMINATOR[TERMINATOR_SIZE];//ターミネータ
		static const unsigned char BLOCK_BEGIN[BEGIN_MARK_SIZE];//ブロック始端
		static const unsigned char BLOCK_END[END_MARK_SIZE];//ブロック終端
		static const unsigned char ARRAY_BEGIN[BEGIN_MARK_SIZE];//配列始端
		static const unsigned char ARRAY_END[END_MARK_SIZE];//配列終端
		static const unsigned char ELEM_BEGIN[BEGIN_MARK_SIZE];//要素始端
		static const unsigned char ELEM_END[END_MARK_SIZE];//要素終端
		static const unsigned char ITEM_BEGIN[BEGIN_MARK_SIZE];//データ項目始端
		static const unsigned char ITEM_END[END_MARK_SIZE];//データ項目終端
	public:
		//コンストラクタ
		CArchiveStyleBinaryBase():
			CArchiveStyleBase()
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		CArchiveStyleBinaryBase(CArchiveStyleBinaryBase& parent) :
			CArchiveStyleBase(parent)
		{}
		//デストラクタ
		~CArchiveStyleBinaryBase() 
		{}
	};
	//--------------------
	//バイナリ形式アーカイブクラス（共通）：静的変数インスタンス化
	const unsigned char CArchiveStyleBinaryBase::SIGNATURE[CArchiveStyleBinaryBase::SIGNATURE_SIZE] = { 0x00, 0xff, 's', 'e', 'r', 'i', 'a', 'l', ':', ':', 'C', 'B', 'i', 'n', 0xff, 0x00 };//シグネチャ
	const unsigned char CArchiveStyleBinaryBase::TERMINATOR[CArchiveStyleBinaryBase::TERMINATOR_SIZE] = { 0xff, 0x00, 's', 'e', 'r', 'i', 'a', 'l', ':', ':', 'C', 'B', 'i', 'n', 0x00, 0xff };//ターミネータ
	const unsigned char CArchiveStyleBinaryBase::BLOCK_BEGIN[CArchiveStyleBinaryBase::BEGIN_MARK_SIZE] = { 0xfb, 0xff };//ブロック始端
	const unsigned char CArchiveStyleBinaryBase::BLOCK_END[CArchiveStyleBinaryBase::END_MARK_SIZE] = { 0xff, 0xfb };//ブロック終端
	const unsigned char CArchiveStyleBinaryBase::ARRAY_BEGIN[CArchiveStyleBinaryBase::BEGIN_MARK_SIZE] = { 0xfa, 0xff };//配列始端
	const unsigned char CArchiveStyleBinaryBase::ARRAY_END[CArchiveStyleBinaryBase::END_MARK_SIZE] = { 0xff, 0xfa };//配列終端
	const unsigned char CArchiveStyleBinaryBase::ELEM_BEGIN[CArchiveStyleBinaryBase::BEGIN_MARK_SIZE] = { 0xfe, 0xff };//要素始端
	const unsigned char CArchiveStyleBinaryBase::ELEM_END[CArchiveStyleBinaryBase::END_MARK_SIZE] = { 0xff, 0xfe };//要素終端
	const unsigned char CArchiveStyleBinaryBase::ITEM_BEGIN[CArchiveStyleBinaryBase::BEGIN_MARK_SIZE] = { 0xf1, 0xff };//データ項目始端
	const unsigned char CArchiveStyleBinaryBase::ITEM_END[CArchiveStyleBinaryBase::END_MARK_SIZE] = { 0xff, 0xf1 };//データ項目終端
	//--------------------
	//バイナリ形式アーカイブクラス（アーカイブ書き込み用）
	class COArchiveStyleBinary : public CArchiveStyleBinaryBase
	{
	public:
		//メソッド
		//シグネチャ書き込み
		bool writeSignature(COArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			arc.write(result, SIGNATURE, SIGNATURE_SIZE);//シグネチャ書き込み
			return !result.hasFatalError();
		}
		//ブロックヘッダー書き込み
		bool writeBlockHeader(COArchiveHelper arc, const CItemBase& item, const CVersion& ver)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			arc.write(result, BLOCK_BEGIN, BEGIN_MARK_SIZE);//ブロック始端書き込み
			arc.write(result, &item.m_nameCrc, sizeof(item.m_nameCrc));//名前CRC書き込み
			item.m_attr.setHasVersion();//バージョン情報ありにする
			arc.write(result, &item.m_attr.m_value, sizeof(item.m_attr.m_value));//属性書き込み
			arc.write(result, ver.getVerPtr(), ver.getVerSize());//バージョン書き込み
			const std::size_t block_size = 0;
			arc.write(result, &block_size, sizeof(block_size));//ブロックサイズ仮書き込み　※ブロック終了時に書き換える
			return !result.hasFatalError();
		}
		//配列ブロックヘッダー書き込み
		bool writeArrayHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t array_elem_num)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			if (item.isArr())
			{
				arc.write(result, ARRAY_BEGIN, BEGIN_MARK_SIZE);//配列ブロック始端書き込み
				const std::size_t array_block_size = 0;
				arc.write(result, &array_elem_num, sizeof(array_elem_num));//配列要素数仮書き込み
				arc.write(result, &array_block_size, sizeof(array_block_size));//配ブロック列サイズ仮書き込み　※配列終了時に書き換える
			}
			return !result.hasFatalError();
		}
		//要素ヘッダー書き込み
		bool writeElemHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t index)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			arc.write(result, ELEM_BEGIN, BEGIN_MARK_SIZE);//要素始端書き込み
			const short items_num = 0;
			const std::size_t elem_size = 0;
			arc.write(result, &items_num, sizeof(items_num));//データ項目数仮書き込み　※要素終了時に書き換える
			arc.write(result, &elem_size, sizeof(elem_size));//要素サイズ仮書き込み　※要素終了時に書き換える
			return !result.hasFatalError();
		}
		//データ項目書き込み
		bool writeDataItem(COArchiveHelper arc, const CItemBase& item, const CItemBase& child_item)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			arc.write(result, ITEM_BEGIN, BEGIN_MARK_SIZE);//データ項目始端書き込み
			arc.write(result, &child_item.m_nameCrc, sizeof(child_item.m_nameCrc));//名前CRC書き込み
			child_item.m_attr.resetHasVersion();//バージョン情報なしにする
			arc.write(result, &child_item.m_attr.m_value, sizeof(child_item.m_attr.m_value));//属性書き込み
			arc.write(result, &child_item.m_itemSize, sizeof(child_item.m_itemSize));//データサイズ書き込み
			if (!child_item.isNul())//ヌル時はここまでの情報で終わり
			{
				if (child_item.isArr())//配列か？
					arc.write(result, &child_item.m_arrNum, sizeof(child_item.m_arrNum));//列要素数書き込み
				unsigned char* p = reinterpret_cast<unsigned char*>(const_cast<void*>(child_item.m_itemP));
				const std::size_t elem_num = child_item.getElemNum();
				for (std::size_t index = 0; index < elem_num && !result.hasFatalError(); ++index)//配列要素数分データ書き込み
				{
					arc.write(result, p, child_item.m_itemSize);//データ書き込み
					p += child_item.m_itemSize;
				}
			}
			arc.write(result, ITEM_END, END_MARK_SIZE);//データ項目終端書き込み
			return !result.hasFatalError();
		}
		//要素フッター書き込み
		bool writeElemFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
			{
				parent_arc.addResult(result);//親に処理結果を計上
				return false;
			}
			items_num = child_arc.getItemListNum();//データ項目数取得
			elem_size = child_arc.getBuffUsed();//データサイズ取得
			parent_arc.seek(result, -static_cast<int>(sizeof(elem_size)));//要素サイズ情報の分、バッファのカレントポインタを戻す
			parent_arc.seek(result, -static_cast<int>(sizeof(items_num)));//データ項目数情報の分、バッファのカレントポインタを戻す
			parent_arc.write(result, &items_num, sizeof(items_num));//要素サイズを更新（書き込み）
			parent_arc.write(result, &elem_size, sizeof(elem_size));//要素サイズを更新（書き込み）
			parent_arc.seek(result, static_cast<int>(elem_size));//要素サイズ分（要素の終わりまで）、バッファのカレントポインタを進める
			parent_arc.write(result, ELEM_END, END_MARK_SIZE);//要素終端書き込み
			parent_arc.addResult(result);//親に処理結果を計上
			return !result.hasFatalError();
		}
		//配列ブロックフッター書き込み
		bool writeArrayFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& array_block_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
			{
				parent_arc.addResult(result);//親に処理結果を計上
				return false;
			}
			array_block_size = child_arc.getBuffUsed();//データサイズ取得
			if (item.isArr())
			{
				parent_arc.seek(result, -static_cast<int>(sizeof(array_block_size)));//配列ブロックサイズ情報の分、バッファのカレントポインタを戻す
				parent_arc.write(result, &array_block_size, sizeof(array_block_size));//配列ブロックサイズを更新（書き込み）
			}
			parent_arc.seek(result, static_cast<int>(array_block_size));//配列ブロックサイズ分（要素の終わりまで）、バッファのカレントポインタを進める
			if (item.isArr())
			{
				parent_arc.write(result, ARRAY_END, END_MARK_SIZE);//配列ブロック終端書き込み
			}
			parent_arc.addResult(result);//親に処理結果を計上
			return !result.hasFatalError();
		}
		//ブロックフッター書き込み
		bool writeBlockFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& block_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
			{
				parent_arc.addResult(result);//親に処理結果を計上
				return false;
			}
			block_size = child_arc.getBuffUsed();//データサイズ取得
			int real_seek = 0;
			parent_arc.seek(result, -static_cast<int>(sizeof(block_size)));//ブロックサイズ情報の分、バッファのカレントポインタを戻す
			parent_arc.write(result, &block_size, sizeof(block_size));//ブロックサイズを更新（書き込み）
			parent_arc.seek(result, static_cast<int>(block_size));//ブロックサイズ分（ブロックの終わりまで）、バッファのカレントポインタを進める
			parent_arc.write(result, BLOCK_END, END_MARK_SIZE);//ブロック終端書き込み
			parent_arc.addResult(result);//親に処理結果を計上
			return !result.hasFatalError();
		}
		//ターミネータ書き込み
		bool writeTerminator(COArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			arc.write(result, TERMINATOR, TERMINATOR_SIZE);//ターミネータ書き込み
			return !result.hasFatalError();
		}
	public:
		//コンストラクタ
		COArchiveStyleBinary() :
			CArchiveStyleBinaryBase()
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		COArchiveStyleBinary(COArchiveStyleBinary& parent) :
			CArchiveStyleBinaryBase(parent)
		{}
		//デストラクタ
		~COArchiveStyleBinary()
		{}
	};
	//--------------------
	//バイナリ形式アーカイブクラス（アーカイブ読み込み用）
	class CIArchiveStyleBinary : public CArchiveStyleBinaryBase
	{
	public:
		//メソッド
		//パース
		bool parse(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//何もしない
			return !result.hasFatalError();
		}
		//シグネチャ読み込み
		bool readSignature(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			char signature[SIGNATURE_SIZE];//シグネチャ読み込みバッファ
			arc.read(result, signature, SIGNATURE_SIZE);//シグネチャ読み込み
			if (memcmp(signature, SIGNATURE, SIGNATURE_SIZE) != 0)//シグネチャチェック
				result.setHasFatalError();
			return !result.hasFatalError();
		}
		//ブロックヘッダー読み込み
		//※読み込んだオブジェクトの型情報とバージョンを返す
		bool readBlockHeader(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_item, const CVersion& ve, CItemBase& input_item, CVersion& input_ver, std::size_t& block_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			char begin_mark[BEGIN_MARK_SIZE];//ブロック始端読み込みバッファ
			arc.read(result, begin_mark, BEGIN_MARK_SIZE);//ブロック始端読み込み
			if (memcmp(begin_mark, BLOCK_BEGIN, BEGIN_MARK_SIZE) != 0)//ブロック始端チェック
			{
				result.setHasFatalError();
				return false;
			}
			input_item.clearForLoad();//読み込み情報を一旦クリア
			arc.read(result, const_cast<crc32_t*>(&input_item.m_nameCrc), sizeof(input_item.m_nameCrc));//名前CRC読み込み
			arc.read(result, const_cast<CItemAttr::value_t*>(&input_item.m_attr.m_value), sizeof(input_item.m_attr.m_value));//属性読み込み
			if (input_item.m_attr.hasVersion())//バージョン情報があるか？
			{
				arc.read(result, const_cast<unsigned int*>(input_ver.getVerPtr()), input_ver.getVerSize());//バージョン読み込み
				input_ver.calcFromVer();
			}
			arc.read(result, const_cast<std::size_t*>(&input_item.m_itemSize), sizeof(input_item.m_itemSize));//ブロックサイズ読み込み
			block_size = input_item.m_itemSize;//ブロックサイズ
			//委譲アイテムの指定があれば、名前をチェックせずに入力データに情報をコピーする
			if (delegate_item)
			{
				input_item.copyFromOnMem(*delegate_item);//セーブデータの情報に現在の情報をコピー（統合）
				input_item.setIsOnlyOnSaveData();//セーブデータ上のみのデータ扱いにする（集計のため）
			}
			else
			{
				//名前CRCをチェックして情報を統合
				//※違っていたら致命的エラー（セーブデータが適合していない）
				if (input_item == item)
				{
					//両者に存在する
					input_item.copyFromOnMem(item);//セーブデータの情報に現在の情報をコピー（統合）
				}
				else
				{
					//一致しない
					input_item.setIsOnlyOnSaveData();//セーブデータにしか存在しないデータ項目
					result.setHasFatalError();//致命的エラー設定
				}
			}
			//ヌルの時はこの時点で処理済みにする
			//※ヌルじゃない時は配列読み込みが済んだら処理済みにする
			if (input_item.m_attr.isNul())
			{
				item.setIsAlready();//処理済みにする
				result.addResult(input_item);//結果を計上
			}
			return !result.hasFatalError();
		}
		//配列ブロックヘッダー読み込み
		bool readArrayHeader(CIArchiveHelper arc, const CItemBase& item, std::size_t& array_elem_num, std::size_t& array_block_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			if (item.isArr())//配列型の時だけ読み込む
			{
				char begin_mark[BEGIN_MARK_SIZE];//配列ブロック始端読み込みバッファ
				arc.read(result, begin_mark, BEGIN_MARK_SIZE);//配列ブロック始端読み込み
				if (memcmp(begin_mark, ARRAY_BEGIN, BEGIN_MARK_SIZE) != 0)//配列ブロック始端チェック
				{
					result.setHasFatalError();
					return false;
				}
				arc.read(result, const_cast<std::size_t*>(&item.m_arrNum), sizeof(item.m_arrNum));//配列要素数読み込み
				arc.read(result, const_cast<std::size_t*>(&array_block_size), sizeof(array_block_size));//配列ブロックサイズ読み込み
				array_elem_num = item.m_arrNum;//配列要素数
			}
			else
			{
				*const_cast<std::size_t*>(&item.m_arrNum) = 0;//配列要素数
				array_elem_num = 0;//配列要素数
				array_block_size = 0;//配列ブロックサイズ
			}
			item.setIsAlready();//処理済みにする
			result.addResult(item);//結果を計上
			return !result.hasFatalError();
		}
		//要素ヘッダー読み込み
		bool readElemHeader(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size)
		{
			CResult& result = arc.getResult();
			items_num = 0;
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			char begin_mark[BEGIN_MARK_SIZE];//配列始端読み込みバッファ
			arc.read(result, begin_mark, BEGIN_MARK_SIZE);//配列始端読み込み
			if (memcmp(begin_mark, ELEM_BEGIN, BEGIN_MARK_SIZE) != 0)//要素始端チェック
			{
				result.setHasFatalError();
				return false;
			}
			arc.read(result, &items_num, sizeof(items_num));//データ項目数読み込み
			arc.read(result, &elem_size, sizeof(elem_size));//要素サイズ読み込み
			return !result.hasFatalError();
		}
		//データ項目読み込み
		bool readDataItem(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_child_item_now, CItemBase& child_item, const bool item_is_valid, const bool is_required_retry)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			if (is_required_retry)//リトライ要求
			{
				//記憶している位置に戻す
				arc.seek(result, -static_cast<int>(m_readSizeForPrevDataItem));//【リトライ用】前回のデータ読み込みサイズ
			}
			m_readSizeForPrevDataItem = 0;//【リトライ用】前回のデータ読み込みサイズをリセット
			std::size_t read_size = 0;//この処理中で計上する読み込みサイズ
			char begin_mark[BEGIN_MARK_SIZE];//データ項目／ブロック始端読み込みバッファ
			arc.read(result, begin_mark, BEGIN_MARK_SIZE, &read_size);//データ項目／ブロック始端読み込み
			bool is_block_begin = false;
			if (memcmp(begin_mark, BLOCK_BEGIN, BEGIN_MARK_SIZE) == 0)//ブロック始端チェック
				is_block_begin = true;
			else
			{
				if (memcmp(begin_mark, ITEM_BEGIN, BEGIN_MARK_SIZE) != 0)//データ項目始端チェック
				{
					result.setHasFatalError();
					return false;
				}
			}
			arc.read(result, const_cast<crc32_t*>(&child_item.m_nameCrc), sizeof(child_item.m_nameCrc), &read_size);//名前CRC読み込み
			arc.read(result, const_cast<CItemAttr::value_t*>(&child_item.m_attr.m_value), sizeof(child_item.m_attr.m_value), &read_size);//属性読み込み
			const CItemBase* child_item_now = nullptr;
			if (delegate_child_item_now)//委譲データ項目があればそれを優先的に使用
			{
				child_item_now = delegate_child_item_now;//委譲データ項目
				//child_itemの名前とCRCを書き換える
				child_item.m_name = delegate_child_item_now->m_name;//名前
				*const_cast<crc32_t*>(&child_item.m_nameCrc) = delegate_child_item_now->m_nameCrc;//名前のCRC
			}
			else
				child_item_now = arc.findItem(child_item.m_nameCrc);//対応するデータ項目情報を検索
			if (child_item_now)//対応するデータ項目が見つかったか？
				child_item.copyFromOnMem(*child_item_now);//現在の情報をセーブデータの情報にコピー（統合）
			else
				child_item.setIsOnlyOnSaveData();//対応するデータがない：セーブデータにしかデータが存在しない
			//対象データ項目はオブジェクト型か？
			if (child_item.isObj())
			{
				//対象がオブジェクト（ブロック）なら、オブジェクトとして処理をやり直すために、この時点で処理終了
				arc.seek(result, -static_cast<int>(read_size));//やり直しのために、バッファのカレントポインタを先頭に戻す
				//ブロック始端を検出していなかったらデータ不整合でエラー終了
				if (!is_block_begin)
				{
					result.setHasFatalError();
					return false;
				}
				return !result.hasFatalError();
			}
			//通常データの読み込み処理
			assert(!child_item.m_attr.hasVersion());//オブジェクトでもないのにバージョン情報があればNG
			arc.read(result, const_cast<std::size_t*>(&child_item.m_itemSize), sizeof(child_item.m_itemSize), &read_size);//データサイズ読み込み
			if (!child_item.isNul())//【セーブデータ上の】データがヌルでなければ処理する
			{
				if (child_item.isArr())//配列か？
					arc.read(result, const_cast<std::size_t*>(&child_item.m_arrNum), sizeof(child_item.m_arrNum), &read_size);//配列要素数読み込み
				unsigned char* p = reinterpret_cast<unsigned char*>(const_cast<void*>(child_item.m_itemP));
				const std::size_t elem_num = child_item.getElemNum();
				for (std::size_t index = 0; index < elem_num && !result.hasFatalError(); ++index)//【セーブデータ上の】配列要素数分データ書き込み
				{
					const bool element_is_valid =//有効なデータか？
						item_is_valid && //親のデータが有効か？
						!child_item.isOnlyOnSaveData() && //セーブデータにしかないデータではないか？
						!child_item.nowIsNul() && //現在の（コピー先の）データがヌルではないか？
						index < child_item.getNowElemNum();//現在の（コピー先の）配列の範囲内か？
					void* p_tmp = element_is_valid ? p : nullptr;//有効なデータでなければnullptrを渡し、空読み込みする
					arc.readWithFunc(result, child_item.m_nowTypeCtrl.m_fromMemFuncP, p_tmp, child_item.m_nowItemSize, child_item.m_itemSize, &read_size);//データ読み込み
					if (p)
						p += child_item.m_nowItemSize;//次の要素
				}
			}
			char end_mark[END_MARK_SIZE];//データ項目終端読み込みバッファ
			arc.read(result, end_mark, END_MARK_SIZE, &read_size);//データ項目終端読み込み
			if (memcmp(end_mark, ITEM_END, END_MARK_SIZE) != 0)//データ項目始端チェック
			{
				result.setHasFatalError();
				return false;
			}
			child_item.setIsAlready();//処理済みにする
			result.addResult(child_item);//結果を計上
			m_readSizeForPrevDataItem = read_size;//【リトライ用】前回のデータ読み込みサイズを記憶
			return true;
		}
		//要素フッター読み込み
		//※読み込みテストの結果、要素フッターでなければデータ項目の読み込みを継続する
		bool tryAndReadElemFooter(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, bool& is_elem_end)
		{
			is_elem_end = true;//要素終了扱い
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			std::size_t read_size = 0;
			char end_mark[END_MARK_SIZE];
			arc.read(result, end_mark, END_MARK_SIZE, &read_size);//要素終端読み込み
			if (memcmp(end_mark, ELEM_END, END_MARK_SIZE) != 0)//要素終端チェック
			{
				is_elem_end = false;//要素終了ではない
				arc.seek(result, -static_cast<int>(read_size));//要素の終端ではなかったため、バッファのカレントポインタを戻す
			}
			return !result.hasFatalError();
		}
		//要素読み込み終了
		bool finishReadElem(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			parent_arc.addResult(child_arc.getResult());//親に処理結果を計上
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			parent_arc.seek(result, child_arc.getBuffUsed());
			return !result.hasFatalError();
		}
		//配列ブロックフッター読み込み
		//※読み込みテストの結果、配列ブロックフッターでなければデータ項目の読み込みを継続する
		bool tryAndReadArrayFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_array_block_end)
		{
			is_array_block_end = true;//配列ブロック終了扱い
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			if (item.isArr())
			{
				std::size_t read_size = 0;
				char end_mark[END_MARK_SIZE];
				arc.read(result, end_mark, END_MARK_SIZE, &read_size);//配列ブロック終端読み込み
				if (memcmp(end_mark, ARRAY_END, END_MARK_SIZE) != 0)//要素終端チェック
				{
					is_array_block_end = false;//配列ブロック終了ではない
					arc.seek(result, -static_cast<int>(read_size));//要素の終端ではなかったため、バッファのカレントポインタを戻す
				}
			}
			return !result.hasFatalError();
		}
		//配列ブロック読み込み終了
		bool finishReadArray(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			parent_arc.addResult(child_arc.getResult());//親に処理結果を計上
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			parent_arc.seek(result, child_arc.getBuffUsed());
			return !result.hasFatalError();
		}
		//ブロックの読み込みをスキップ
		bool skipReadBlock(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			char begin_mark[BEGIN_MARK_SIZE];//ブロック始端読み込みバッファ
			arc.read(result, begin_mark, BEGIN_MARK_SIZE);//ブロック始端読み込み
			if (memcmp(begin_mark, BLOCK_BEGIN, BEGIN_MARK_SIZE) != 0)//ブロック始端チェック
			{
				result.setHasFatalError();
				return false;
			}
			crc32_t name_crc = 0;
			CItemAttr attr(false, false, false, false, false);
			arc.read(result, &name_crc, sizeof(name_crc));//名前CRC読み込み
			arc.read(result, const_cast<CItemAttr::value_t*>(&attr.m_value), sizeof(attr.m_value));//属性書き込み
			if (attr.hasVersion())//バージョン情報があるか？
			{
				CVersion input_ver_dummy;
				arc.read(result, const_cast<unsigned int*>(input_ver_dummy.getVerPtr()), input_ver_dummy.getVerSize());//バージョン読み込み
			}
			if (!attr.isNul())//ヌル時はここまでの情報で終わり
			{
				std::size_t item_size;
				arc.read(result, &item_size, sizeof(item_size));//ブロックサイズ読み込み
				arc.seek(result, static_cast<int>(item_size));//ブロックサイズ分、バッファのカレントポインタを進める
			}
			//ブロックフッター読み込み
			char end_mark[END_MARK_SIZE];
			arc.read(result, end_mark, END_MARK_SIZE);//ブロック終端読み込み
			if (memcmp(end_mark, BLOCK_END, END_MARK_SIZE) != 0)//ブロック終端チェック
			{
				result.setHasFatalError();
				return false;
			}
			return !result.hasFatalError();
		}
		//ブロックフッター読み込み
		//※読み込みテストの結果、ブロックフッターでなければデータ項目（オブジェクト）の読み込みを継続する
		bool tryAndReadBlockFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_block_end)
		{
			is_block_end = true;//ブロック終了扱い
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			std::size_t read_size = 0;
			char end_mark[END_MARK_SIZE];
			arc.read(result, end_mark, END_MARK_SIZE, &read_size);//ブロック終端読み込み
			if (memcmp(end_mark, BLOCK_END, END_MARK_SIZE) != 0)//ブロック終端チェック
			{
				is_block_end = false;//ブロック終了ではない
				arc.seek(result, -static_cast<int>(read_size));//ブロックの終端ではなかったため、バッファのカレントポインタを戻す
			}
			return !result.hasFatalError();
		}
		//ブロック読み込み終了
		bool finishReadBlock(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			parent_arc.addResult(child_arc.getResult());//親に処理結果を計上
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			parent_arc.seek(result, child_arc.getBuffUsed());
			return !result.hasFatalError();
		}
		//※読み込みテストの結果、ブロックフッターでなければデータ項目（オブジェクト）の読み込みを継続する
		//次のブロックヘッダー問い合わせ（先行読み込み）
		//※処理を進めず、次の情報を読み取るのみ
		//※（例えば、バイナリスタイルなら、読み込みバッファのポインタを進めない）
		bool requireNextBlockHeader(CIArchiveHelper arc, CItemBase& require_item, std::size_t& require_block_size, bool& is_found_next_block)
		{
			is_found_next_block = false;//ブロック情報が見つかってないことにする
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			std::size_t read_size = 0;//読み込みサイズ
			require_item.clearForLoad();//読み込み情報を一旦クリア
			char begin_mark[BEGIN_MARK_SIZE];//ブロック始端読み込みバッファ
			arc.read(result, begin_mark, BEGIN_MARK_SIZE, &read_size);//ブロック始端読み込み
			if (memcmp(begin_mark, BLOCK_BEGIN, BEGIN_MARK_SIZE) != 0)//ブロック始端チェック
			{
				arc.seek(result, -static_cast<int>(read_size));//仮読みした分、バッファのカレントポインタを戻す
				return !result.hasFatalError();
			}
			is_found_next_block = true;//見つかった
			arc.read(result, const_cast<crc32_t*>(&require_item.m_nameCrc), sizeof(require_item.m_nameCrc), &read_size);//名前CRC書き込み
			arc.read(result, const_cast<CItemAttr::value_t*>(&require_item.m_attr.m_value), sizeof(require_item.m_attr.m_value), &read_size);//属性書き込み
			if (require_item.m_attr.hasVersion())//バージョン情報があるか？
			{
				CVersion input_ver_dummy;
				arc.read(result, const_cast<unsigned int*>(input_ver_dummy.getVerPtr()), input_ver_dummy.getVerSize(), &read_size);//バージョン読み込み
			}
			require_block_size = read_size;//ブロックサイズ一旦計上
			if (!require_item.isNul())//ヌル時はここまでの情報で終わり
			{
				arc.read(result, const_cast<std::size_t*>(&require_item.m_itemSize), sizeof(require_item.m_itemSize), &read_size);//ブロックサイズ読み込み
				require_block_size += require_item.m_itemSize;//ブロックサイズ計上
				if (require_item.isArr())//配列時は配列要素数も読み込み
				{
					char begin_mark[BEGIN_MARK_SIZE];//配列ブロック始端読み込みバッファ
					arc.read(result, begin_mark, BEGIN_MARK_SIZE);//配列ブロック始端読み込み
					if (memcmp(begin_mark, ARRAY_BEGIN, BEGIN_MARK_SIZE) == 0)//配列ブロック始端チェック
					{
						//std::size_t array_block_size = 0;
						arc.read(result, const_cast<std::size_t*>(&require_item.m_arrNum), sizeof(require_item.m_arrNum));//配列要素数読み込み
						//arc.read(result, const_cast<std::size_t*>(&array_block_size), sizeof(array_block_size));//配列ブロックサイズ読み込み
					}
				}
			}
			arc.seek(result, -static_cast<int>(read_size));//仮読みした分、バッファのカレントポインタを戻す
			return !result.hasFatalError();
		}
		//ターミネータ読み込み
		bool readTerminator(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			char terminator[TERMINATOR_SIZE];
			arc.read(result, terminator, TERMINATOR_SIZE);//ターミネータ読み込み
			if (memcmp(terminator, TERMINATOR, TERMINATOR_SIZE) != 0)//ターミネータチェック
				result.setHasFatalError();
			return true;
		}
	public:
		//コンストラクタ
		CIArchiveStyleBinary() :
			CArchiveStyleBinaryBase(),
			m_readSizeForPrevDataItem(0)
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		CIArchiveStyleBinary(CIArchiveStyleBinary& parent) :
			CArchiveStyleBinaryBase(parent),
			m_readSizeForPrevDataItem(0)
		{}
		//デストラクタ
		~CIArchiveStyleBinary()
		{}
	private:
		//フィールド
		std::size_t m_readSizeForPrevDataItem;//【リトライ用】前回のデータ読み込みサイズ
	};
	//--------------------
	//テキスト形式アーカイブクラス（共通）
	class CArchiveStyleTextBase : public CArchiveStyleBase
	{
	public:
		//コンストラクタ
		CArchiveStyleTextBase() :
			CArchiveStyleBase()
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		CArchiveStyleTextBase(CArchiveStyleTextBase& parent) :
			CArchiveStyleBase(parent)
		{}
		//デストラクタ
		~CArchiveStyleTextBase()
		{}
	};
	//--------------------
	//テキスト形式アーカイブクラス（アーカイブ書き込み用）
	class COArchiveStyleText : public CArchiveStyleTextBase
	{
	public:
		//定数
		enum PROCESS
		{
			PROCESS_UNKNOWN = 0,
			PROCESS_TOP,
			PROCESS_BLOCK,
			PROCESS_ARRAY_BLOCK,
			PROCESS_ELEM,
			PROCESS_ITEM,
		};
	public:
		//メソッド
		//シグネチャ書き込み
		bool writeSignature(COArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			m_process = PROCESS_TOP;
			arc.print(result, "{\"serializer\": {");
			m_blockIndex = 0;
			return !result.hasFatalError();
		}
		//ブロックヘッダー書き込み
		bool writeBlockHeader(COArchiveHelper arc, const CItemBase& item, const CVersion& ver)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			if (m_blockIndex != 0 || m_process == PROCESS_ARRAY_BLOCK || (m_process == PROCESS_ELEM && m_itemIndex != 0))
				arc.print(result, ",");
			if (m_process == PROCESS_ELEM)
				++m_itemIndex;
			arc.print(result, "\n");
			m_process = PROCESS_BLOCK;
			arc.printIndent(result, 0);
			arc.print(result, "\"%s\": {", item.m_name);
			arc.print(result, "\"crc\": 0x%08x, ", item.m_nameCrc);
			arc.print(result, "\"itemType\": \"%s\", ", item.m_itemType->name());
			arc.print(result, "\"itemSize\": %d, ", item.m_itemSize);
			arc.print(result, "\"isObj\": %d, ", item.isObj());
			arc.print(result, "\"isArr\": %d, ", item.isArr());
			arc.print(result, "\"isPtr\": %d, ", item.isPtr());
			arc.print(result, "\"isNul\": %d, ", item.isNul());
			arc.print(result, "\"isVLen\": %d, ", item.isVLen());
			arc.print(result, "\"hasVersion\": %d, ", item.m_attr.hasVersion());
			arc.print(result, "\"ver\": \"%d.%d\"", ver.getMajor(), ver.getMinor());
			m_arrayBlockIndex = 0;
			return !result.hasFatalError();
		}
		//配列ブロックヘッダー書き込み
		bool writeArrayHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t array_elem_num)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			if (item.isArr())
			{
				arc.print(result, ",");
				arc.print(result, "\n");
				m_process = PROCESS_ARRAY_BLOCK;
				arc.printIndent(result, 0);
				arc.print(result, "\"arrayNum\": %d, \"array\": [", array_elem_num);
				m_elemIndex = 0;
			}
			else
			{
				m_process = PROCESS_ARRAY_BLOCK;
				m_elemIndex = -1;
			}
			return !result.hasFatalError();
		}
		//要素ヘッダー書き込み
		bool writeElemHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t index)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			if (!item.isArr() || (item.isArr() && m_elemIndex != 0))
				arc.print(result, ",");
			arc.print(result, "\n");
			m_process = PROCESS_ELEM;
			arc.printIndent(result, 0);
			if (item.isArr())
			{
				arc.print(result, "{");
			}
			else
			{
				arc.print(result, "\"elem\": {");
			}
			m_itemIndex = 0;
			return !result.hasFatalError();
		}
		//データ項目書き込み
		bool writeDataItem(COArchiveHelper arc, const CItemBase& item, const CItemBase& child_item)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			if (m_itemIndex != 0)
				arc.print(result, ",");
			arc.print(result, "\n");
			m_process = PROCESS_ITEM;
			arc.printIndent(result, 0);
			arc.print(result, "\"%s\": {", child_item.m_name);
			arc.print(result, "\"crc\": 0x%08x, ", child_item.m_nameCrc);
			arc.print(result, "\"itemType\": \"%s\", ", child_item.m_itemType->name());
			arc.print(result, "\"itemSize\": %d, ", child_item.m_itemSize);
			arc.print(result, "\"isObj\": %d, ", child_item.isObj());
			arc.print(result, "\"isArr\": %d, ", child_item.isArr());
			arc.print(result, "\"isPtr\": %d, ", child_item.isPtr());
			arc.print(result, "\"isNul\": %d, ", child_item.isNul());
			arc.print(result, "\"isVLen\": %d, ", child_item.isVLen());
			arc.print(result, "\"hasVersion\": %d, ", child_item.m_attr.hasVersion());
			if (child_item.isArr())
				arc.print(result, "\"arrNum\": %d, ", child_item.m_arrNum);
			arc.print(result, "\"data\": ");
			{
				if (child_item.isNul())
					arc.print(result, "null");
				else
				{
					unsigned char* p = reinterpret_cast<unsigned char*>(const_cast<void*>(child_item.m_itemP));
					const std::size_t elem_num = child_item.getElemNum();
					if (child_item.isArr())
						arc.print(result, "[");
					for (std::size_t index = 0; index < elem_num && !result.hasFatalError(); ++index)//配列要素数分データ書き込み
					{
						if (index != 0)
							arc.print(result, ",");
						arc.printWithFunc(result, child_item.m_typeCtrl.m_toStrFuncP, p, child_item.m_itemSize);
						p += child_item.m_itemSize;
					}
					if (child_item.isArr())
						arc.print(result, "]");
				}
			}
			arc.print(result, "}");
			++m_itemIndex;
			m_process = m_parentProcess;
			return !result.hasFatalError();
		}
		//要素フッター書き込み
		bool writeElemFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
			{
				parent_arc.addResult(result);//親に処理結果を計上
				return false;
			}
			child_arc.print(result, "}");
			parent_arc.seek(result, child_arc.getBuffUsed());
			parent_arc.addResult(result);//親に処理結果を計上
			if (m_parent)
				++m_parent->m_elemIndex;
			m_process = m_parentProcess;
			return !result.hasFatalError();
		}
		//配列ブロックフッター書き込み
		bool writeArrayFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& array_block_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
			{
				parent_arc.addResult(result);//親に処理結果を計上
				return false;
			}
			if (item.isArr())
			{
				child_arc.print(result, "]");
			}
			parent_arc.seek(result, child_arc.getBuffUsed());
			parent_arc.addResult(result);//親に処理結果を計上
			if (m_parent)
				++m_parent->m_arrayBlockIndex;
			m_process = m_parentProcess;
			return !result.hasFatalError();
		}
		//ブロックフッター書き込み
		bool writeBlockFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& block_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
			{
				parent_arc.addResult(result);//親に処理結果を計上
				return false;
			}
			child_arc.print(result, "}");
			parent_arc.seek(result, child_arc.getBuffUsed());
			parent_arc.addResult(result);//親に処理結果を計上
			if (m_parent)
				++m_parent->m_blockIndex;
			m_process = m_parentProcess;
			return !result.hasFatalError();
		}
		//ターミネータ書き込み
		bool writeTerminator(COArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			arc.print(result, "\n");
			arc.print(result, "}, \"terminator\": \"ok\"}\n");
			return !result.hasFatalError();
		}
	public:
		//コンストラクタ
		COArchiveStyleText() :
			CArchiveStyleTextBase(),
			m_parent(nullptr),
			m_nestLevel(0),
			m_process(PROCESS_UNKNOWN),
			m_blockIndex(0),
			m_arrayBlockIndex(0),
			m_elemIndex(0),
			m_itemIndex(0),
			m_parentProcess(PROCESS_UNKNOWN),
			m_parentBlockIndex(0),
			m_parentArrayBlockIndex(0),
			m_parentElemIndex(0),
			m_parentItemIndex(0)
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		COArchiveStyleText(COArchiveStyleText& src) :
			CArchiveStyleTextBase(src),
			m_parent(&src),
			m_nestLevel(src.m_nestLevel + 1),
			m_process(src.m_process),
			m_blockIndex(0),
			m_arrayBlockIndex(0),
			m_elemIndex(0),
			m_itemIndex(0),
			m_parentProcess(src.m_process),
			m_parentBlockIndex(src.m_blockIndex),
			m_parentArrayBlockIndex(src.m_arrayBlockIndex),
			m_parentElemIndex(src.m_elemIndex),
			m_parentItemIndex(src.m_itemIndex)
		{}
		//デストラクタ
		~COArchiveStyleText()
		{}
	private:
		//フィールド
		COArchiveStyleText* m_parent;//親アーカイブ形式オブジェクト
		int m_nestLevel;//データのネストレベル
		PROCESS m_process;//処理状態
		int m_blockIndex;//ブロックインデックス
		int m_arrayBlockIndex;//配列ブロックインデックス
		int m_elemIndex;//要素インデックス
		int m_itemIndex;//データ項目インデックス
		PROCESS m_parentProcess;//親の処理状態
		int m_parentBlockIndex;//親のブロックインデックス
		int m_parentArrayBlockIndex;//親の配列ブロックインデックス
		int m_parentElemIndex;//親の要素インデックス
		int m_parentItemIndex;//親のデータ項目インデックス
	};
	//--------------------
	//テキスト形式アーカイブクラス（アーカイブ読み込み用）
	class CIArchiveStyleText : public CArchiveStyleTextBase
	{
	public:
		//メソッド
		//パース
		bool parse(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//シグネチャ読み込み
		bool readSignature(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//ブロックヘッダー読み込み
		//※読み込んだオブジェクトの型情報とバージョンを返す
		bool readBlockHeader(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_item, const CVersion& ver, CItemBase& input_item, CVersion& input_ver, std::size_t& block_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//配列ブロックヘッダー読み込み
		bool readArrayHeader(CIArchiveHelper arc, const CItemBase& item, std::size_t& array_elem_num, std::size_t& array_block_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//要素ヘッダー読み込み
		bool readElemHeader(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//データ項目読み込み
		bool readDataItem(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_child_item_now, const bool item_is_valid, const bool is_required_retry)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//要素フッター読み込み
		//※読み込みテストの結果、要素フッターでなければデータ項目の読み込みを継続する
		bool tryAndReadElemFooter(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, bool& is_elem_end)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//要素読み込み終了
		bool finishReadElem(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//配列ブロックフッター読み込み
		//※読み込みテストの結果、配列ブロックフッターでなければデータ項目の読み込みを継続する
		bool tryAndReadArrayFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_array_block_end)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//配列ブロック読み込み終了
		bool finishReadArray(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//ブロックの読み込みをスキップ
		bool skipReadBlock(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//ブロックフッター読み込み
		//※読み込みテストの結果、ブロックフッターでなければデータ項目（オブジェクト）の読み込みを継続する
		bool tryAndReadBlockFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_block_end)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//ブロック読み込み終了
		bool finishReadBlock(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//※読み込みテストの結果、ブロックフッターでなければデータ項目（オブジェクト）の読み込みを継続する
		//次のブロックヘッダー問い合わせ（先行読み込み）
		//※処理を進めず、次の情報を読み取るのみ
		//※（例えば、バイナリスタイルなら、読み込みバッファのポインタを進めない）
		bool requireNextBlockHeader(CIArchiveHelper arc, CItemBase& require_item, std::size_t& require_block_size, bool& is_found_next_block)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
		//ターミネータ読み込み
		bool readTerminator(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//致命的なエラーが出ている時は即時終了する
				return false;
			//未実装
			return !result.hasFatalError();
		}
	public:
		//コンストラクタ
		CIArchiveStyleText() :
			CArchiveStyleTextBase()
		{}
		//親を受け取るコンストラクタ
		//※処理階層が深くなるごとにコピーが行われる
		CIArchiveStyleText(CIArchiveStyleText& parent) :
			CArchiveStyleTextBase(parent)
		{}
		//デストラクタ
		~CIArchiveStyleText()
		{}
	};
	//--------------------
	//バイナリ形式アーカイブ書き込みクラス
	using COBinaryArchive = COArchive<COArchiveStyleBinary>;
	//--------------------
	//バイナリ形式アーカイブ読み込みクラス
	using CIBinaryArchive = CIArchive<CIArchiveStyleBinary>;
	//--------------------
	//テキスト形式アーカイブ書き込みクラス
	using COTextArchive = COArchive<COArchiveStyleText>;
	//--------------------
	//テキスト形式アーカイブ読み込みクラス
	using CITextArchive = CIArchive<CIArchiveStyleText>;
}

//--------------------------------------------------------------------------------
//シリアライズテスト１

#include <bitset>//std::bitset

//--------------------
//テスト用クラス
class CTest1
{
	//シリアライズ用のフレンド設定
	FRIEND_SERIALIZE(CTest1);
public:
	//型
	struct STRUCT
	{
		//FRIEND_SERIALIZE(STRUCT);
		int m_a;
		char m_b;
		float m_c;
		//コンストラクタ
		STRUCT():
			m_a(0),
			m_b(0),
			m_c(0.f)
		{}
	};
public:
	//アクセッサ
	int getData1() const { return m_data1; }//データ1取得
	void setData1(const int value){ m_data1 = value; }//データ1更新
	float getData2() const { return m_data2; }//データ2取得
	void setData2(const float value){ m_data2 = value; }//データ2更新
	char getData3(const int index) const { return m_data3[index]; }//データ3取得
	void setData3(const int index, const int value){ m_data3[index] = value; }//データ3更新
	STRUCT& getData4a(){ return m_data4a; }//データ4a取得
	const STRUCT& getData4a() const { return m_data4a; }//データ4a取得
	STRUCT& getData4b(){ return m_data4b; }//データ4b取得
	const STRUCT& getData4b() const { return m_data4b; }//データ4b取得
	bool getData5a(const int index) const { return m_data5a[index]; }//データ5a取得
	void setData5a(const int index, const bool value){ m_data5a[index] = value; }//データ5a更新
	bool getData5b(const int index) const { return m_data5b[index]; }//データ5b取得
	void setData5b(const int index, const bool value){ m_data5b[index] = value; }//データ5b更新
	STRUCT& getData6(const int index){ return m_data6[index]; }//データ6取得
	const STRUCT& getData6(const int index) const { return m_data6[index]; }//データ6取得
	STRUCT* getData7a(){ return m_data7a; }//データ7a取得
	const STRUCT* getData7a() const { return m_data7a; }//データ7a取得
	STRUCT* getData7b(){ return m_data7b; }//データ7b取得
	const STRUCT* getData7b() const { return m_data7b; }//データ7b取得
	int* getData8a(){ return m_data8a; }//データ8a取得
	const int* getData8a() const { return m_data8a; }//データ8a取得
	int* getData8b(){ return m_data8b; }//データ8b取得
	const int* getData8b() const { return m_data8b; }//データ8b取得
public:
	//コンストラクタ
	CTest1() :
		m_data1(0),
		m_data2(0.f),
		m_data4a(),
		m_data4b(),
		m_data7a(nullptr),
		m_data7b(nullptr),
		m_data8a(nullptr),
		m_data8b(nullptr)
	{
		m_data3[0] = 0;
		m_data3[1] = 0;
		m_data3[2] = 0;
		m_data5a.reset();
		m_data5b.reset();
		m_data7a = new STRUCT();
		//m_data7b = new STRUCT();
		m_data8a = new int;
		//m_data8b = new int;
	}
	//デストラクタ
	~CTest1()
	{
		if (m_data7a)
			delete m_data7a;
		if (m_data7b)
			delete m_data7b;
		if (m_data8a)
			delete m_data8a;
		if (m_data8b)
			delete m_data8b;
	}
private:
	//フィールド
	//int m_data0;
	int m_data1;//データ1
	float m_data2;//データ2
	char m_data3[3];//データ3
	STRUCT m_data4a;//データ4a
	STRUCT m_data4b;//データ4b
	std::bitset<8192> m_data5a;//データ5a
	std::bitset<8192> m_data5b;//データ5b
	STRUCT m_data6[2];//データ6
	STRUCT* m_data7a;//データ7a
	STRUCT* m_data7b;//データ7b
	int* m_data8a;//データ8a
	int* m_data8b;//データ8b
};
//--------------------
//セーブデータ作成用クラス
//※空のクラス
//※ギャザーラとディストリビュータのみ定義する
class CSaveDataSerializer
{};
//--------------------
//テスト用クラスのバージョンを設定
SERIALIZE_VERSION_DEF(CTest1, 1, 2);
SERIALIZE_VERSION_DEF(CTest1::STRUCT, 3, 4);
SERIALIZE_VERSION_DEF(CSaveDataSerializer, 5, 6);

//セーブデータインスタンス
static CTest1* s_saveData = nullptr;

//セーブデータ初期化
void initSaveData()
{
	//セーブデータ取得
	CTest1& data = *s_saveData;
	//データを初期化
	data.setData1(1);
	data.setData2(2.34f);
	data.setData3(0, 5);
	data.setData3(1, 6);
	data.setData3(2, 7);
	data.getData4a().m_a = 8;
	data.getData4a().m_b = 9;
	data.getData4a().m_c = 10.f;
	data.getData4b().m_a = 11;
	data.getData4b().m_b = 12;
	data.getData4b().m_c = 13.f;
	data.setData5a(0, true);
	data.setData5a(1, true);
	data.setData5a(8191, true);
	data.setData5b(2, true);
	data.setData5b(8190, true);
	data.getData6(0).m_a = 14;
	data.getData6(0).m_b = 15;
	data.getData6(0).m_c = 16.f;
	data.getData6(1).m_a = 17;
	data.getData6(1).m_b = 18;
	data.getData6(1).m_c = 19.f;
	if (data.getData7a())
	{
		data.getData7a()->m_a = 20;
		data.getData7a()->m_b = 21;
		data.getData7a()->m_c = 22.f;
	}
	if (data.getData7b())
	{
		data.getData7b()->m_a = 23;
		data.getData7b()->m_b = 24;
		data.getData7b()->m_c = 25.f;
	}
	if (data.getData8a())
		*data.getData8a() = 26;
	if (data.getData8b())
		*data.getData8b() = 27;
}

//セーブデータ内容表示
void printSaveData()
{
	//セーブデータ取得
	CTest1& data = *s_saveData;
	//データ表示
	printf("data1=%d\n", data.getData1());
	printf("data2=%.2f\n", data.getData2());
	printf("data3={%d, %d, %d}\n", data.getData3(0), data.getData3(1), data.getData3(2));
	printf("data4a:a=%d,b=%d,c=%.1f\n", data.getData4a().m_a, data.getData4a().m_b, data.getData4a().m_c);
	printf("data4b:a=%d,b=%d,c=%.1f\n", data.getData4b().m_a, data.getData4b().m_b, data.getData4b().m_c);
	printf("data5a:[0]=%d,[1]=%d,[2]=%d,[8190]=%d,[8191]=%d\n", data.getData5a(0), data.getData5a(1), data.getData5a(2), data.getData5a(8190), data.getData5a(8191));
	printf("data5b:[0]=%d,[1]=%d,[2]=%d,[8190]=%d,[8191]=%d\n", data.getData5b(0), data.getData5b(1), data.getData5b(2), data.getData5b(8190), data.getData5b(8191));
	printf("data6:[0]={a=%d,b=%d,c=%.1f},[1]={a=%d,b=%d,c=%.1f}\n", data.getData6(0).m_a, data.getData6(0).m_b, data.getData6(0).m_c, data.getData6(1).m_a, data.getData6(1).m_b, data.getData6(1).m_c);
	if (data.getData7a())
		printf("data7a(0x%p):a=%d,b=%d,c=%.1f\n", data.getData7a(), data.getData7a()->m_a, data.getData7a()->m_b, data.getData7a()->m_c);
	else
		printf("data7a(0x%p)\n", data.getData7a());
	if (data.getData7b())
		printf("data7b(0x%p):a=%d,b=%d,c=%.1f\n", data.getData7b(), data.getData7b()->m_a, data.getData7b()->m_b, data.getData7b()->m_c);
	else
		printf("data7b(0x%p)\n", data.getData7b());

	if (data.getData8a())
		printf("data8a(0x%p)=%d\n", data.getData8a(), *data.getData8a());
	else
		printf("data8a(0x%p)\n", data.getData8a());
	if (data.getData8b())
		printf("data8b(0x%p)=%d\n", data.getData8b(), *data.getData8b());
	else
		printf("data8b(0x%p)\n", data.getData8b());
}


//--------------------
//テスト用クラスのシリアライズ処理定義
namespace serial
{
#if 1
	//--------------------
	//ロード前処理用関数オブジェクト
	//※デシリアライズ専用処理
	template<class Arc>
	struct beforeLoad<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("beforeLoad<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			if (!obj.m_data7a)
				obj.m_data7a = new CTest1::STRUCT();
		}
	};
#endif
#if 1
	//--------------------
	//シリアライズ処理用関数オブジェクト
	//※シリアライズとデシリアライズ兼用共通処理
	template<class Arc>
	struct serialize<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("arc.is_read=%d, arc.is_write=%d\n", arc.is_read, arc.is_write);
			printf("serialize<CTest1>(ver=%d,%d) sizeof(CTest1)=%d\n", ver.getMajor(), ver.getMinor(), sizeof(CTest1));
			//arc & pair("data0", obj.m_data0);
			arc & pair("data1", obj.m_data1)
			    & pair("data2", obj.m_data2)
			    & pair("data3", obj.m_data3);
			arc & pairBin("data4a", obj.m_data4a);
			arc & pair("data4b", obj.m_data4b);
			arc & pairBin("data5a", obj.m_data5a);
			arc & pair("data5b", obj.m_data5b);
			arc & pair("data6", obj.m_data6);
			arc & pair("data7a", obj.m_data7a);
			arc & pair("data7b", obj.m_data7b);
			arc & pair("data8a", obj.m_data8a);
			arc & pair("data8b", obj.m_data8b);
		}
	};
#endif
#if 1
	template<class Arc>
	struct serialize<Arc, CTest1::STRUCT> {
		void operator()(Arc& arc, const CTest1::STRUCT& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("serialize<CTest1::STRUCT>(ver=%d,%d) sizeof(CTest1::STRUCT)=%d\n", ver.getMajor(), ver.getMinor(), sizeof(CTest1::STRUCT));
			arc & pair("data1", obj.m_a);
			arc & pair("data2", obj.m_b);
			arc & pair("data3", obj.m_c);
		}
	};
#endif
#if 0
	//標準クラスライブラリに対応する関数も定義できる
	//std::bitsetを1ビットずつ別項目で書き出すサンプル
	//※膨大なワークバッファを要するので注意
	template<class Arc, std::size_t N>
	struct serialize<Arc, std::bitset<N> > {
		void operator()(Arc& arc, const std::bitset<N>& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("serialize<std::bitset<N>>(ver=%d,%d) sizeof(std::bitset<N>)=%d\n", ver.getMajor(), ver.getMinor(), sizeof(std::bitset<N>));
			for (int i = 0; i < N; ++i)
			{
				char name[16];
			#ifdef USE_STRCPY_S
				sprintf_s(name,sizeof(name),  "no%d", i);
			#else//USE_STRCPY_S
				sprintf(name, "no%d", i);
			#endif//USE_STRCPY_S
				bool bit = obj[i];
				arc & pair(name, bit);
			}
		}
	};
#endif
#if 1
	//--------------------
	//セーブ処理用関数オブジェクトクラス
	//※シリアライズ専用処理
	template<class Arc>
	struct save<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver)
		{
			printf("save<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//ロード処理用関数オブジェクトクラス
	//※デシリアライズ専用処理
	template<class Arc>
	struct load<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("load<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//ロード後処理用関数オブジェクトクラス
	//※デシリアライズ専用処理
	template<class Arc>
	struct afterLoad<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("afterLoad<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//データ収集処理用関数オブジェクトクラス
	//※シリアライズ専用処理
	template<class Arc>
	struct collector<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver)
		{
			printf("collector<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//データ分配処理用関数オブジェクトクラス
	//※デシリアライズ専用処理
	template<class Arc>
	struct distributor<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{
			printf("distributor<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//データ収集処理用関数オブジェクトクラス
	//※シリアライズ専用処理
	template<class Arc>
	struct collector<Arc, CSaveDataSerializer> {
		void operator()(Arc& arc, const CSaveDataSerializer& obj, const CVersion& ver)
		{
			printf("collector<CSaveDataSerializer>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			//対象データ取得
			CTest1& data = *s_saveData;
			//シリアライズ
			arc << pair("CTest1", data);
		}
	};
#endif
#if 1
	//--------------------
	//データ分配処理用関数オブジェクトクラス
	//※デシリアライズ専用処理
	template<class Arc>
	struct distributor<Arc, CSaveDataSerializer> {
		void operator()(Arc& arc, CSaveDataSerializer& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{
			printf("distributor<CSaveDataSerializer>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			//対象データ取得
			CTest1& data = *s_saveData;
			//デシリアライズ
			arc >> pair("CTest1", data);
		}
	};
#endif
}//namespace serial

//--------------------
//シリアライズテスト１：バイナリアーカイブ
void serializeTest1bin(const char* file_path)
{
	printf("--------------------\n");
	printf("シリアライズ：バイナリアーカイブ\n");
	//バッファの用意
	//char* save_buff = new char[1 * 1024 * 1024];//セーブデータバッファ
	//char* work_buff = new char[8 * 1024 * 1024];//ワークバッファ
	char save_buff[16 * 1024];//セーブデータバッファ
	char work_buff[16 * 1024];//ワークバッファ
	//セーブデータ初期化
	initSaveData();
	//セーブデータ表示
	printSaveData();
	//シリアライズ
	serial::COBinaryArchive arc(save_buff, work_buff);
	arc << serial::pair<CSaveDataSerializer>("SaveData");//シリアライズ
	printf("処理結果：%s\n", arc.hasFatalError() ? "致命的なエラーあり" : "エラーなし");
	//ファイルに書き出し
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(save_buff, 1, arc.getSaveDataSize(), fp);
	fclose(fp);
	fp = NULL;
}
//--------------------
//シリアライズテスト１：テキストアーカイブ
void serializeTest1txt(const char* file_path)
{
	printf("--------------------\n");
	printf("シリアライズ：テキストアーカイブ\n");
	//バッファの用意
	//char* save_buff = new char[1 * 1024 * 1024];//セーブデータバッファ
	//char* work_buff = new char[8 * 1024 * 1024];//ワークバッファ
	char save_buff[32 * 1024];//セーブデータバッファ
	char work_buff[16 * 1024];//ワークバッファ
	//セーブデータ初期化
	initSaveData();
	//セーブデータ表示
	printSaveData();
	//シリアライズ
	serial::COTextArchive arc(save_buff, work_buff);
	arc << serial::pair<CSaveDataSerializer>("SaveData");//シリアライズ
	printf("処理結果：%s\n", arc.hasFatalError() ? "致命的なエラーあり" : "エラーなし");
	//ファイルに書き出し
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(save_buff, 1, arc.getSaveDataSize(), fp);
	fclose(fp);
	fp = NULL;
}
//--------------------
//デシリアライズテスト１：バイナリアーカイブ
void deserializeTest1bin(const char* file_path)
{
	printf("--------------------\n");
	printf("デシリアライズ：バイナリアーカイブ\n");
	//バッファの用意
	//char* save_buff = new char[1 * 1024 * 1024];//セーブデータバッファ
	//char* work_buff = new char[8 * 1024 * 1024];//ワークバッファ
	char save_buff[16 * 1024];//セーブデータバッファ
	char work_buff[16 * 1024];//ワークバッファ
	//ファイルから読み込み
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "rb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "rb");
#endif//USE_STRCPY_S
	//ファイルサイズを求める
	fseek(fp, 0, SEEK_END);
	const std::size_t file_size = ftell(fp);
	//ファイルを読み込み
	fseek(fp, 0, SEEK_SET);
	fread(save_buff, 1, file_size, fp);
	fclose(fp);
	fp = NULL;
	//デシリアライズ
	serial::CIBinaryArchive arc(save_buff, file_size, work_buff);
	arc >> serial::pair<CSaveDataSerializer>("SaveData", file_size);
	printf("処理結果：%s\n", arc.hasFatalError() ? "致命的なエラーあり" : "エラーなし");
	serial::CResult& result = arc.getResult();
	printf("  getNumSmallerSizeItem()=%d\n", result.getNumSmallerSizeItem());//サイズが縮小されたデータ項目の数を取得
	printf("  getNumLargerSizeItem()=%d\n", result.getNumLargerSizeItem());//サイズが拡大されたデータ項目の数を取得
	printf("  getNumSmallerArrItem()=%d\n", result.getNumSmallerArrItem());//配列サイズが縮小されたデータ項目の数を取得
	printf("  getNumLargerArrItem()=%d\n", result.getNumLargerArrItem());//配列サイズが拡大されたデータ項目の数を取得
	printf("  getNumIsOnlyOnSaveData()=%d\n", result.getNumIsOnlyOnSaveData());//セーブデータ上にのみ存在するデータ項目の数を取得
	printf("  getNumIsOnlyOnMem()=%d\n", result.getNumIsOnlyOnMem());//セーブデータ上にないデータ項目の数を取得
	printf("  getNumIsObjOnSaveDataOnly()=%d\n", result.getNumIsObjOnSaveDataOnly());//現在オブジェクト型ではないが、セーブデータ上ではそうだったデータ項目の数を取得
	printf("  getNumIsObjOnMemOnly()=%d\n", result.getNumIsObjOnMemOnly());//現在オブジェクト型だが、セーブデータ上ではそうではなかったデータ項目の数を取得
	printf("  getNumIsArrOnSaveDataOnly()=%d\n", result.getNumIsArrOnSaveDataOnly());//現在配列型ではないが、セーブデータ上ではそうだったデータ項目の数を取得
	printf("  getNumIsArrOnMemOnly()=%d\n", result.getNumIsArrOnMemOnly());//現在配列型だが、セーブデータ上ではそうではなかったデータ項目の数を取得
	printf("  getNumIsPtrOnSaveDataOnly()=%d\n", result.getNumIsPtrOnSaveDataOnly());//現在ポインタ型ではないが、セーブデータ上ではそうだったデータ項目の数を取得
	printf("  getNumIsPtrOnMemOnly()=%d\n", result.getNumIsPtrOnMemOnly());//現在ポインタ型だが、セーブデータ上ではそうではなかったデータ項目の数を取得
	printf("  getNumIsNulOnSaveDataOnly()=%d\n", result.getNumIsNulOnSaveDataOnly());//現在ヌルではないが、セーブデータ上ではそうだったデータ項目の数を取得
	printf("  getNumIsNulOnMemOnly()=%d\n", result.getNumIsNulOnMemOnly());//現在ヌルだが、セーブデータ上ではそうではなかったデータ項目の数を取得
	//セーブデータ表示
	printSaveData();
}
//--------------------
//シリアライズ＆デシリアライズテスト１：バイナリアーカイブ
void test1()
{
	static const char* file_path_bin = "test1.bin";
	static const char* file_path_txt = "test1.txt";
	//シリアライズ
	s_saveData = new CTest1();
	serializeTest1bin(file_path_bin);
	serializeTest1txt(file_path_txt);
	delete s_saveData;
	s_saveData = nullptr;

	char* dummy = new char[10 * 1024];
	
	//デシリアライズ
	s_saveData = new CTest1();
	deserializeTest1bin(file_path_bin);
	delete s_saveData;
	s_saveData = nullptr;
	
	delete dummy;
}

//--------------------------------------------------------------------------------
//シリアライズテスト２

//--------------------
//基本型
//短い文字列型
template <std::size_t S>
class CStr
{
public:
	//定数
	static const std::size_t BUFF_SIZE = S;//バッファサイズ
	static const std::size_t MAX_SIZE = S - 1;//最大文字列長
public:
	//アクセッサ
	const char* c_str() const { return m_str; }//文字列を取得　※std::string互換
	std::size_t length() const { return m_len; }//文字列長を取得　※std::string互換
	std::size_t size() const { return m_len; }//文字列長を取得　※std::string互換
	std::size_t max_size() const { return MAX_SIZE; }//文字列の最大長を取得　※std::string互換
	const char* getStr() const { return m_str; }//文字列を取得
	void setStr(const char* str)//文字列をセット
	{
		if (!str)
		{
			m_str[0] = '\0';
			m_len = 0;
			return;
		}
	#ifdef USE_STRCPY_S
		strncpy_s(m_str, sizeof(m_str), str, MAX_SIZE);
	#else//USE_STRCPY_S
		strncpy(m_str, str, MAX_SIZE);
	#endif//USE_STRCPY_S
		m_str[MAX_SIZE] = '\0';
		m_len = strlen(m_str);
	}
public:
	//キャストオペレータ
	operator const char*() const { return m_str; }
public:
	//デフォルトコンストラクタ
	CStr():
		m_len(0)
	{
		m_str[0] = '\0';
	}
	//コピーコンストラクタ
	template <std::size_t SS>
	CStr(const CStr<S>& src) :
		m_len(src.m_len < MAX_SIZE ? src.m_len : MAX_SIZE)
	{
		memcpy(m_str, src.m_str, m_len);
		m_str[m_len] = '\0';
	}
	//コンストラクタ
	CStr(const char* str)
	{
		setStr(str);
	}
protected:
	//フィールド
	unsigned char m_len;//文字列長
	char m_str[BUFF_SIZE];//文字列
	//シリアライズ用のフレンド設定
	FRIEND_SERIALIZE(str);
};
//CRC付き文字列型
template <std::size_t S>
class CStrWithCRC : public CStr<S>
{
public:
	//型
	typedef CStr<S> CParent;
public:
	//アクセッサ
	crc32_t getCRC() const { return m_crc; }//CRCを取得
	void setStr(const char* str)//文字列をセット
	{
		CParent::setStr(str);
		m_crc = calcCRC32(CParent::m_str);
	}
public:
	//キャストオペレータ
	operator crc32_t() const { return m_crc; }
public:
	//デフォルトコンストラクタ
	CStrWithCRC() :
		CParent(nullptr),
		m_crc(0)
	{}
	//コピーコンストラクタ
	template <std::size_t SS>
	CStrWithCRC(const CStrWithCRC<SS>& src) :
		CStr<SS>(src),
		m_crc(src.m_crc)
	{}
	//コンストラクタ
	CStrWithCRC(const char* str) :
		CParent()
	{
		setStr(str);
	}
private:
	//フィールド
	crc32_t m_crc;//CRC
	//シリアライズ用のフレンド設定
	FRIEND_SERIALIZE(strWithCRC);
};

//--------------------
//ID型＆名前型
using ID_t = CStrWithCRC<8>;
using name_t = CStr<32>;

//--------------------
//基本データ構造体
struct BASIC_DATA
{
	short m_atk;//攻撃力
	short m_def;//守備力
	//デフォルトコンストラクタ
	BASIC_DATA()
	{}
	//コピーコンストラクタ
	BASIC_DATA(const BASIC_DATA& src) :
		m_atk(src.m_atk),
		m_def(src.m_def)
	{}
	//コンストラクタ
	BASIC_DATA(const int atk, const int def) :
		m_atk(atk),
		m_def(def)
	{}
};
//構造体バージョン
SERIALIZE_VERSION_DEF(BASIC_DATA, 1, 0);

//--------------------
//アイテム構造体
struct ITEM_DATA
{
	crc32_t getKey() const { return m_id.getCRC(); }//キーを取得
	ID_t m_id;//ID
	name_t m_name;//名前
	char* m_title;//称号　※可変長文字列（ポインタ）のテスト用
	char m_titleBuff[16];//称号用バッファ
	BASIC_DATA m_basic;//基本データ
	short m_recover;//回復力
	short m_num;//データ個数
	//デフォルトコンストラクタ
	ITEM_DATA()
	{
		m_title = m_titleBuff;
		m_titleBuff[0] = '\0';
	}
	//コンストラクタ（テスト用に強引）
	ITEM_DATA(const char* id, const char* name, const int atk, const int def, const int recover, const int num) :
		m_id(id),
		m_name(name),
		m_basic(atk, def),
		m_recover(recover),
		m_num(num)
	{
		m_title = m_titleBuff;
		m_title[0] = '\0';
	}
	//コピーコンストラクタ
	ITEM_DATA(const ITEM_DATA& src):
		m_id(src.m_id),
		m_name(src.m_name),
		m_basic(src.m_basic),
		m_recover(src.m_recover),
		m_num(src.m_num)
	{
		if (src.m_title)
		{
			m_title = m_titleBuff;
		#ifdef USE_STRCPY_S
			strcpy_s(m_title, sizeof(m_titleBuff), src.m_title);
		#else//USE_STRCPY_S
			strcpy(m_title, src.m_title);
		#endif//USE_STRCPY_S
		}
		else
			m_title = nullptr;
	}
};
//構造体バージョン
SERIALIZE_VERSION_DEF(ITEM_DATA, 1, 0);

//--------------------
//アビリティデータ構造体
struct ABILITY_DATA
{
	crc32_t getKey() const { return m_id.getCRC(); }//キーを取得
	ID_t m_id;//ID
	name_t m_name;//名前
	BASIC_DATA m_basic;//基本データ
	//デフォルトコンストラクタ
	ABILITY_DATA()
	{}
	//コンストラクタ（テスト用に強引）
	ABILITY_DATA(const char* id, const char* name, const int atk, const int def) :
		m_id(id),
		m_name(name),
		m_basic(atk, def)
	{}
};
//構造体バージョン
SERIALIZE_VERSION_DEF(ABILITY_DATA, 1, 0);

//--------------------
//キャラデータ構造体
struct ABILITY_DATA;
struct CHARA_ABILITY_DATA;
struct CHARA_DATA
{
	crc32_t getKey() const { return m_id.getCRC(); }//キーを取得
	ID_t m_id;//ID
	name_t m_name;//名前
	char m_level;//レベル
	BASIC_DATA m_basic;//基本データ
	const ITEM_DATA* m_weapon;//武器
	const ITEM_DATA* m_shield;//盾
	int m_param1[2];//ダミーパラメータ1
	int m_param2[2];//ダミーパラメータ2
	//メソッド
	void setWeapon(const crc32_t weapon_id);//武器をセット
	void setWeapon(const char* weapon_id){ setWeapon(calcCRC32(weapon_id)); }//武器をセット
	void setShield(const crc32_t shield_id);//盾をセット
	void setShield(const char* shield_id){ setShield(calcCRC32(shield_id)); }//盾をセット
	void attachItems();//アイテムを参照し直す
	void addAbility(const crc32_t ability_id);//アビリティを追加
	void addAbility(const char* ability_id){ addAbility(calcCRC32(ability_id)); }//アビリティを追加
	ABILITY_DATA* getAbility(const int index);//アビリティを取得
	//デフォルトコンストラクタ
	CHARA_DATA()
	{}
	//コンストラクタ（テスト用に強引）
	CHARA_DATA(const char* id, const char* name, const int level, const int atk, const int def, const char* weapon_id, const char* shield_id, const int param1a, const int param1b, const int param2a, const int param2b) :
		m_id(id),
		m_name(name),
		m_level(level),
		m_basic(atk, def),
		m_weapon(nullptr),
		m_shield(nullptr),
		m_abilities(nullptr)
	{
		setWeapon(weapon_id);
		setShield(shield_id);
		m_param1[0] = param1a;
		m_param1[1] = param1b;
		m_param2[0] = param2a;
		m_param2[1] = param2b;
	}
private:
	crc32_t m_weaponId;//武器ID
	crc32_t m_shieldId;//盾ID
	CHARA_ABILITY_DATA* m_abilities;//アビリティ
	//シリアライズ用のフレンド設定
	FRIEND_SERIALIZE(CHARA_DATA);
};
//構造体バージョン
SERIALIZE_VERSION_DEF(CHARA_DATA, 1, 0);

//--------------------
//キャラ保有アビリティデータ構造体
struct CHARA_ABILITY_DATA
{
	CHARA_ABILITY_DATA* m_next;//連結リスト
	ABILITY_DATA* m_ability;//アビリティ
};
//※セーブ用構造体
struct CHARA_ABILITY_DATA_FOR_SAVE
{
	//crc32_t m_charaId;//キャラID
	crc32_t m_abilityId;//アビリティID
};
//--------------------
//キャラ保有アビリティデータバッファ
class CCharaAbilityBuff
{
public:
	//メソッド
	CHARA_ABILITY_DATA* assign(){ return m_itemPool.createData(); }
	void release(CHARA_ABILITY_DATA* data){ m_itemPool.destroyData(data); }
public:
	//コンストラクタ
	CCharaAbilityBuff()
	{}
private:
	//フィールド
	CPoolAllocatorWithType<CHARA_ABILITY_DATA, 100> m_itemPool;//データ用のバッファ
};

//--------------------
//コレクションクラス
template<class T, std::size_t D, std::size_t B1, std::size_t B2>
class CCollection
{
private:
	//型
	typedef std::map<crc32_t, T*> search_t;//検索テーブル型
	typedef std::vector<T*> table_t;//整列テーブル型
	typedef typename table_t::iterator iterator;//イテレータ型
	typedef typename table_t::const_iterator const_iterator;//イテレータ型
public:
	//定数
	static const std::size_t DATA_NUM_MAX = D;//最大データ数
	static const std::size_t SEARCH_BUFF_SIZE = B1;//検索テーブルのバッファサイズ
	static const std::size_t TABLE_BUFF_SIZE = B2;//整列テーブルバッファサイズ
public:
	//アクセッサ
	iterator begin(){ return m_table->begin(); }//開始イテレータ
	iterator end(){ return m_table->end(); }//終了イテレータ
	const_iterator begin() const { return m_table->begin(); }//開始イテレータ
	const_iterator end() const { return m_table->end(); }//終了イテレータ
	const_iterator cbegin() const { return m_table->cbegin(); }//開始イテレータ
	const_iterator cend() const { return m_table->cend(); }//終了イテレータ
public:
	//検索
	T* find(const crc32_t key)
	{
		auto ite = m_search->find(key);
		if (ite == m_search->end())
			return nullptr;//見つからなかった
		return ite->second;
	}
	T* find(const char* id)
	{
		return find(calcCRC32(id));
	}
	//登録
	T* regist(const T& item)
	{
		//プールアロケータから割り当て
		T* reg_item = m_itemPool.createData(item);
		if (!reg_item)
			return nullptr;//規定の個数が割り当て済みなら失敗
		{
			//検索テーブルバッファを多態アロケータにセット
			CTempPolyStackAllocator allocator(m_searchBuff);

			//検索テーブルに登録
			m_search->emplace(reg_item->getKey(), reg_item);
		}
		{
			//整列テーブルバッファを多態アロケータにセット
			CTempPolyStackAllocator allocator(m_tableBuff);
			
			//整列テーブルにも追加
			m_table->push_back(reg_item);
		}
		return reg_item;
	}
	//破棄
	void unregist(const crc32_t key)
	{
		T* item = find(key);
		if (!item)
			return;
		{
			//検索テーブルバッファを多態アロケータにセット
			CTempPolyStackAllocator allocator(m_searchBuff);

			//検索テーブルからアイテムを破棄
			m_search->erase(key);
		}
		//プールアロケータから解放
		//m_itemPool.destroy(item);
	}
private:
	//整列テーブルを生成
	void createTable()
	{
		if (!m_table)
		{
			//整列テーブルバッファを多態アロケータにセット
			CTempPolyStackAllocator allocator(m_tableBuff);
			
			m_table = new table_t();
		}
	}
	//整列テーブル破棄
	void destroyTable()
	{
		if (m_table)
		{
			//整列テーブルバッファを多態アロケータにセット
			CTempPolyStackAllocator allocator(m_tableBuff);

			delete m_table;
			m_table = nullptr;
		}
		//バッファをクリア
		m_tableBuff.clearN();
	}
public:
	//ソート
	//※整列テーブル再作成
	void sort(const bool is_descendant = false)
	{
		//整列テーブルの破棄と生成
		destroyTable();//破棄
		createTable();//生成
		{
			//整列テーブルバッファを多態アロケータにセット
			CTempPolyStackAllocator allocator(m_tableBuff);

			//検索テーブルから整列テーブルに全要素コピー
			for (auto& pair : *m_search)
			{
				m_table->push_back(pair.second);
			}

			//名前順ソート
			std::sort(m_table->begin(), m_table->end(),
				[&is_descendant](T* lhs, T* rhs)->bool
				{
					const int cmp = strcmp(lhs->m_name, rhs->m_name);
					return is_descendant ? cmp > 0 : cmp < 0;
				}
			);
		}
	}
public:
	//コンストラクタ
	CCollection()
	{
		{
			//検索テーブルバッファを多態アロケータにセット
			//※以後、処理ブロックを抜けるまで、new 演算子による
			//　メモリ確保が m_searchBuff から行われる
			CTempPolyStackAllocator allocator(m_searchBuff);

			//検索テーブル生成
			m_search = new search_t;
		}
		//整列テーブル生成
		createTable();
	}
	//デストラクタ
	~CCollection()
	{
		{
			//検索テーブルバッファを多態アロケータにセット
			CTempPolyStackAllocator allocator(m_searchBuff);

			//検索テーブル破棄
			//※とくに必要ではないが念のため
			delete m_search;
		}
		//整列テーブル破棄
		destroyTable();
	}
private:
	//フィールド
	CPoolAllocatorWithType<T, DATA_NUM_MAX> m_itemPool;//データ用のバッファ
	CStackAllocatorWithBuff<SEARCH_BUFF_SIZE> m_searchBuff;//検索テーブルバッファ
	search_t* m_search;//検索テーブル
	CStackAllocatorWithBuff<TABLE_BUFF_SIZE> m_tableBuff;//整列テーブルバッファ
	table_t* m_table;//整列テーブル
};
//--------------------
//インベントリクラス
typedef CCollection<ITEM_DATA, 100, 8 * 1024, 8 * 1024> CInventoryBase;
class CInventory : public CInventoryBase
{
public:
	//コンストラクタ
	CInventory() :
		CInventoryBase()
	{}
	//デストラクタ
	~CInventory()
	{}
};
//構造体バージョン
SERIALIZE_VERSION_DEF(CInventory, 1, 0);
//--------------------
//アビリティリクラス
using CAbilityList = CCollection<ABILITY_DATA, 40, 8 * 1024, 8 * 1024>;
//構造体バージョン
SERIALIZE_VERSION_DEF(CAbilityList, 1, 0);
//--------------------
//キャラリストクラス
using CCharaList = CCollection<CHARA_DATA, 10, 8 * 1024, 8 * 1024>;
//構造体バージョン
SERIALIZE_VERSION_DEF(CCharaList, 1, 0);

//--------------------
//進行＆フラグデータ
class CPhaseAndFlags
{
public:
	//型
	typedef std::bitset<64> flag_t;
public:
	//アクセッサ
	int getPhase() const { return m_phase; }//フェーズ取得
	void setPhase(const int phase){ m_phase = phase; }//フェーズ更新
	bool getFlag(const int index) const { return m_flags[index]; }//フラグ取得
	void setFlag(const int index, const bool flag){ m_flags[index] = flag; }//フラグ更新
	const flag_t& getFlags() const { return m_flags; }
public:
	//コンストラクタ
	CPhaseAndFlags() :
		m_phase(0)
	{
		m_flags.reset();
	}
private:
	//フィールド
	short m_phase;//進行フェーズ
	flag_t m_flags;//フラグ
	//シリアライズ用のフレンド設定
	FRIEND_SERIALIZE(CPhaseAndFlags);
};
//構造体バージョン
SERIALIZE_VERSION_DEF(CPhaseAndFlags, 1, 0);

//--------------------
//キャラデータ：メソッド実装
//武器をセット
void CHARA_DATA::setWeapon(const crc32_t weapon_id)
{
	CSingleton<CInventory> inventory;
	ITEM_DATA* item = inventory->find(weapon_id);
	if (!item)
	{
		//対象アイテムがないので持っていないことにする
		m_weaponId = 0;
		m_weapon = nullptr;
		return;
	}
	m_weaponId = weapon_id;
	m_weapon = item;
}
//盾をセット
void CHARA_DATA::setShield(const crc32_t shield_id)
{
	CSingleton<CInventory> inventory;
	ITEM_DATA* item = inventory->find(shield_id);
	if (!item)
	{
		//対象アイテムがないので持っていないことにする
		m_shieldId = 0;
		m_shield = nullptr;
		return;
	}
	m_shieldId = shield_id;
	m_shield = item;
}
//アイテムを参照し直す
void CHARA_DATA::attachItems()
{
	setWeapon(m_weaponId);//武器
	setShield(m_shieldId);//盾
}
//アビリティを追加
void CHARA_DATA::addAbility(const crc32_t ability_id)
{
	CSingleton<CAbilityList> chara_ability_list;
	ABILITY_DATA* ability = chara_ability_list->find(ability_id);
	if (!ability)
		return;
	CSingleton<CCharaAbilityBuff> chara_ability_buff;
	CHARA_ABILITY_DATA* new_chara_ability = chara_ability_buff->assign();
	if (!new_chara_ability)
		return;
	new_chara_ability->m_next = nullptr;
	new_chara_ability->m_ability = ability;
	CHARA_ABILITY_DATA* chara_ability = m_abilities;
	while (chara_ability && chara_ability->m_next)
		chara_ability = chara_ability->m_next;
	if (chara_ability)
		chara_ability->m_next = new_chara_ability;
	else
		m_abilities = new_chara_ability;
}
//アビリティを取得
ABILITY_DATA* CHARA_DATA::getAbility(const int index)
{
	CHARA_ABILITY_DATA* chara_ability = m_abilities;
	for (int i = 0; i < index && chara_ability; ++i)
		chara_ability = chara_ability->m_next;
	return chara_ability == nullptr ? nullptr : chara_ability->m_ability;
}

//--------------------------------------------------------------------------------
//テストデータ用データ確認処理

//--------------------
//全データリセット
void resetAll()
{
	printf("------------------------------------------------------------\n");
	printf("【全データリセット】\n");

	//インベントリデータ破棄
	{
		CSingleton<CInventory> inventory;
		inventory.destroy();
	}
	//アビリティデータ破棄
	{
		CSingleton<CAbilityList> ability_list;
		ability_list.destroy();
	}
	//キャラデータ破棄
	{
		CSingleton<CCharaList> chara_list;
		chara_list.destroy();
	}
	//キャラアビリティデータ破棄
	{
		CSingleton<CAbilityList> chara_ability_list;
		chara_ability_list.destroy();
	}
	//フェーズ＆フラグデータ破棄
	{
		CSingleton<CPhaseAndFlags> phase_and_flags;
		phase_and_flags.destroy();
	}
}

//--------------------
//テストデータ作成
void makeTestData(const int pattern)
{
	printf("------------------------------------------------------------\n");
	printf("【テストデータ作成】(pattern=%d)\n", pattern);

	//インベントリデータ登録
	{
		CSingleton<CInventory> inventory;
		for (int i = 0; i < 5 + pattern * 10; i += (1 + pattern))
		{
			char id[8];
			char name[32];
		#ifdef USE_STRCPY_S
			sprintf_s(id, sizeof(id), "w%05d", (i + 1) * 10);
			sprintf_s(name, sizeof(name), "武器%03d", i + 1);
		#else//USE_STRCPY_S
			sprintf(id, "w%05d", i);
			sprintf(name, "武器%03d", i);
		#endif//USE_STRCPY_S
			ITEM_DATA item(id, name, 10 + i, i / 2, 0, 1);
			if (item.m_title && i > 0)
			{
			#ifdef USE_STRCPY_S
				sprintf_s(item.m_title, sizeof(item.m_titleBuff), "性能:+%d", i);
			#else//USE_STRCPY_S
				sprintf(item.m_title, "性能:+%d", i);
			#endif//USE_STRCPY_S
			}
			else
				item.m_title = nullptr;
			inventory->regist(item);
		}
		for (int i = 0; i < 5 + pattern * 10; i += (1 + pattern))
		{
			char id[8];
			char name[32];
		#ifdef USE_STRCPY_S
			sprintf_s(id, sizeof(id), "s%05d", (i + 1) * 10);
			sprintf_s(name, sizeof(name), "盾%03d", i + 1);
		#else//USE_STRCPY_S
			sprintf(id, "s%05d", i);
			sprintf(name, "盾%03d", i);
		#endif//USE_STRCPY_S
			ITEM_DATA item(id, name, 0, 5 + i, 0, 1);
			if (item.m_title && i > 0)
			{
			#ifdef USE_STRCPY_S
				sprintf_s(item.m_title, sizeof(item.m_titleBuff), "グレード:%c", 'A' + i);
			#else//USE_STRCPY_S
				sprintf(item.m_title, "グレード:%c", 'A' + i);
			#endif//USE_STRCPY_S
			}
			else
				item.m_title = nullptr;
			inventory->regist(item);
		}
		for (int i = pattern; i < 3 + pattern * 3; ++i)
		{
			char id[8];
			char name[32];
		#ifdef USE_STRCPY_S
			sprintf_s(id, sizeof(id), "r%05d", (i + 1) * 10);
			sprintf_s(name, sizeof(name), "回復薬%03d", i + 1);
		#else//USE_STRCPY_S
			sprintf(id, "r%05d", i);
			sprintf(name, "回復薬%03d", i);
		#endif//USE_STRCPY_S
			ITEM_DATA item(id, name, 0, 0, 5 + i * 2, 10);
			item.m_title = nullptr;
			inventory->regist(item);
		}
		inventory->sort();
	}
	//アビリティデータ登録
	{
		CSingleton<CAbilityList> ability_list;
		for (int i = pattern; i < 10 + pattern * 10; ++i)
		{
			char id[8];
			char name[32];
		#ifdef USE_STRCPY_S
			sprintf_s(id, sizeof(id), "a%05d", (i + 1) * 10);
			sprintf_s(name, sizeof(name), "特技%03d", i + 1);
		#else//USE_STRCPY_S
			sprintf(id, "a%05d", i);
			sprintf(name, "特技%03d", i);
		#endif//USE_STRCPY_S
			ABILITY_DATA ability(id, name, 5 + i * 3, 4 + i * 2);
			ability_list->regist(ability);
		}
		ability_list->sort();
	}
	//キャラデータ登録
	{
		CSingleton<CCharaList> chara_list;
		if (pattern & 1)
		{
			CHARA_DATA chara1("c00010", "たろう", 11, 15, 20, "w00030", "s00030", 111, 222, 333, 444);
			CHARA_DATA chara2("c00020", "じろう", 21, 25, 40, "w00050", "s00010", 999, 888, 777, 666);
			CHARA_DATA chara3("c00030", "さぶろう", 31, 55, 3, "w00070", "s00050", 123, 456, 987, 654);
			CHARA_DATA chara4("c00040", "しろう", 41, 55, 3, "w00090", "s00090", 123, 456, 987, 654);
			chara1.addAbility("a00030");
			chara1.addAbility("a00010");
			chara3.addAbility("a00050");
			chara4.addAbility("a00020");
			chara_list->regist(chara1);
			chara_list->regist(chara2);
			chara_list->regist(chara3);
			chara_list->regist(chara4);
			chara_list->sort(true);
		}
		else
		{
			CHARA_DATA chara1("c00010", "たろう", 10, 15, 20, "w00020", "s00020", 111, 222, 333, 444);
			CHARA_DATA chara2("c00020", "じろう", 20, 25, 40, "w00050", "s00010", 999, 888, 777, 666);
			CHARA_DATA chara3("c00030", "さぶろう", 30, 55, 3, "w00010", "s00030", 123, 456, 987, 654);
			chara1.addAbility("a00030");
			chara1.addAbility("a00020");
			chara1.addAbility("a00010");
			chara3.addAbility("a00050");
			chara_list->regist(chara1);
			chara_list->regist(chara2);
			chara_list->regist(chara3);
			chara_list->sort();
		}
	}
	//進行データ更新
	{
		CSingleton<CPhaseAndFlags> phase_and_flags;
		if (pattern & 1)
		{
			phase_and_flags->setPhase(3 + pattern);
			phase_and_flags->setFlag(1, true);
			phase_and_flags->setFlag(2 + pattern, true);
			phase_and_flags->setFlag(62, true);
		}
		else
		{
			phase_and_flags->setPhase(7 + pattern);
			phase_and_flags->setFlag(0, true);
			phase_and_flags->setFlag(2, true);
			phase_and_flags->setFlag(4, true);
			phase_and_flags->setFlag(5, true);
			phase_and_flags->setFlag(63 - pattern, true);
		}
	}
}

//--------------------
//現在のデータを表示
void printDataAll()
{
	printf("------------------------------------------------------------\n");
	printf("【現在のデータを表示】\n");

	//インベントリデータ表示
	printf("--- インベントリ ---\n");
	{
		CSingleton<CInventory> inventory;
		for (auto& ite : *inventory)
		{
			printf("ID=\"%s\"(0x%08x), name=\"%s\", atk=%d, def=%d, recover=%d, num=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_basic.m_atk, ite->m_basic.m_def, ite->m_recover, ite->m_num);
			if (ite->m_title)
				printf("                              title=\"%s\"\n", ite->m_title);
		}
	}
	//アビリティデータ表示
	printf("--- アビリティ ---\n");
	{
		CSingleton<CAbilityList> ability_list;
		for (auto& ite : *ability_list)
		{
			printf("ID=\"%s\"(0x%08x), name=\"%s\", atk=%d, def=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_basic.m_atk, ite->m_basic.m_def);
		}
	}
	//キャラデータ表示
	printf("--- キャラ ---\n");
	{
		CSingleton<CCharaList> chara_list;
		for (auto& ite : *chara_list)
		{
			printf("ID=\"%s\"(0x%08x), name=\"%s\", level=%d, atk=%d, def=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_level, ite->m_basic.m_atk, ite->m_basic.m_def);
			printf("                              param1={%d, %d}, param2={%d, %d}\n",
				ite->m_param1[0], ite->m_param1[1], ite->m_param2[0], ite->m_param2[1]);
			if (ite->m_weapon)
				printf("                              weapon=%s\n", ite->m_weapon->m_name.c_str());
			if (ite->m_shield)
				printf("                              shield=%s\n", ite->m_shield->m_name.c_str());
			for (int i = 0;; ++i)
			{
				const ABILITY_DATA* ability = ite->getAbility(i);
				if (!ability)
					break;
				printf("                              [%s]\n", ability->m_name.c_str());
			}
		}
	}
	//進行データ表示
	printf("--- 進行データ ---\n");
	{
		CSingleton<CPhaseAndFlags> phase_flags;
		printf("pahse=%d\n", phase_flags->getPhase());
		printf("flags=\n");
		for (unsigned int i = 0; i < phase_flags->getFlags().size(); ++i)
		{
			if (i > 0 && i % 16 == 0)
				printf("\n");
			printf(" %d", phase_flags->getFlag(i));
		}
		printf("\n");
	}
}

//--------------------------------------------------------------------------------
//テストデータ用シリアライズ

//--------------------
//セーブデータ用基本クラス
class CSaveData{};

//--------------------
//セーブデータバージョン管理クラス
class CSaveDataVersion
{
public:
	//定数
	static const int MAJOR_VER = 1;//メジャーバージョン
	static const int MINOR_VER = 0;//マイナーバージョン
public:
	//アクセッサ
	int getMajorVer() const { return MAJOR_VER; }//メジャーバージョン取得
	int getMinorVer() const { return MINOR_VER; }//マイナーバージョン取得
	int getLoadedMajorVer() const { return m_loadedMajorVer; }//セーブデータからロードしたメジャーバージョン取得
	int getLoadedMinorVer() const { return m_loadedMinorVer; }//セーブデータからロードしたマイナーバージョン取得
	bool hasSaved() const { return m_hasSaved; }//セーブしたか？
	bool hasLoaded() const { return m_hasLoaded; }//ロードしたか？
private:
	void setHasSaved(){ m_hasSaved = true; }//セーブしたことにする
	void setHasLoaded(){ m_hasLoaded = true; }//ロードしたことにする
	void resetHasSaved(){ m_hasSaved = false; }//セーブしたことがある状態を解除
	void resetHasLoaded(){ m_hasLoaded = false; }//ロードしたことがある状態を解除
public:
	//メソッド
	//ロードしたバージョンを現在のバージョンに更新
	void updateLoadedVer()
	{
		m_loadedMajorVer = MAJOR_VER;//セーブデータからロードしたメジャーバージョン取得
		m_loadedMinorVer = MINOR_VER;//セーブデータからロードしたマイナーバージョン取得
	}
public:
	//コンストラクタ
	CSaveDataVersion() :
		m_loadedMajorVer(0),
		m_loadedMinorVer(0),
		m_hasSaved(false),
		m_hasLoaded(false)
	{}
	//デストラクタ
	~CSaveDataVersion()
	{}
private:
	//フィールド
	int m_loadedMajorVer;//セーブデータからロードしたメジャーバージョン取得
	int m_loadedMinorVer;//セーブデータからロードしたマイナーバージョン取得
	bool m_hasSaved;//セーブしたか？
	bool m_hasLoaded;//ロードしたか？
	//シリアライズ用のフレンド設定
	FRIEND_SERIALIZE(CSaveDataVersion);
};
//--------------------
//セーブデータ用バージョンを表示
void printSaveDataVer()
{
	printf("------------------------------------------------------------\n");
	printf("【セーブデータバージョン】\n");
	
	CSingleton<CSaveDataVersion> save_data_version;
	printf("現在のバージョン:                 %d.%d\n", save_data_version->getMajorVer(), save_data_version->getMinorVer());
	printf("ロード済みorセーブ済みバージョン: %d.%d\n", save_data_version->getLoadedMajorVer(), save_data_version->getLoadedMinorVer());
	printf("・セーブしたか？ = %s\n", save_data_version->hasSaved() ? "yes" : "no");
	printf("・ロードしたか？ = %s\n", save_data_version->hasLoaded() ? "yes" : "no");
}

//--------------------
//テスト用クラスのシリアライズ処理定義
namespace serial
{
	//--------------------
	//シリアライズ処理：std::bitset<>
	template<class Arc, std::size_t N>
	struct serialize<Arc, std::bitset<N> > {
		void operator()(Arc& arc, const std::bitset<N>& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pairBin("bitset", obj);
		}
	};
	//--------------------
	//シリアライズ処理：CStr<>
	template<class Arc, std::size_t S>
	struct serialize<Arc, CStr<S> > {
		void operator()(Arc& arc, const CStr<S>& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("len", obj.m_len);
			arc & pairStr("str", obj.m_str);
		}
	};
	//--------------------
	//シリアライズ処理：CStrWithCRC<>
	template<class Arc, std::size_t S>
	struct serialize<Arc, CStrWithCRC<S> > {
		void operator()(Arc& arc, const CStrWithCRC<S>& obj, const CVersion& ver, const CVersion& now_ver)
		{
			serialize<Arc, typename CStrWithCRC<S>::CParent> parent;
			parent(arc, obj, ver, now_ver);//親クラスのシリアライズを呼び出し
			arc & pair("crc", obj.m_crc);
		}
	};
	//--------------------
	//シリアライズ処理：BASIC_DATA
	template<class Arc>
	struct serialize<Arc, BASIC_DATA> {
		void operator()(Arc& arc, const BASIC_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("atk", obj.m_atk);
			arc & pair("def", obj.m_def);
		}
	};
	//--------------------
	//シリアライズ処理：ITEM_DATA
	template<class Arc>
	struct serialize<Arc, ITEM_DATA> {
		void operator()(Arc& arc, const ITEM_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("id", obj.m_id);
			arc & pair("name", obj.m_name);
			arc & pairStr("title", obj.m_title, sizeof(obj.m_titleBuff));//可変長文字列（ポインタ）のテスト
			//arc & pairArray("title", obj.m_title, sizeof(obj.m_titleBuff));//配列として扱うことも可
			arc & pair("basic", obj.m_basic);
			arc & pair("recover", obj.m_recover);
			arc & pair("num", obj.m_num);
		}
	};
	//--------------------
	//ロード後処理：ITEM_DATA
	template<class Arc>
	struct afterLoad<Arc, ITEM_DATA> {
		void operator()(Arc& arc, ITEM_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			if (obj.m_title[0] == '\0')//復元されなかったタイトルはnullptrにする
				obj.m_title = nullptr;
		}
	};
	//--------------------
	//シリアライズ処理：ABILITY_DATA
	template<class Arc>
	struct serialize<Arc, ABILITY_DATA> {
		void operator()(Arc& arc, const ABILITY_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("id", obj.m_id);
			arc & pair("name", obj.m_name);
			arc & pair("basic", obj.m_basic);
		}
	};
	//--------------------
	//シリアライズ処理：CHARA_DATA
	template<class Arc>
	struct serialize<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("id", obj.m_id);
			arc & pair("name", obj.m_name);
			arc & pair("level", obj.m_level);
			//arc & pair("basic", obj.m_basic);//セーブデータにしかないオブジェクトのシミュレーション
			arc & pair("weapon", obj.m_weaponId);
			arc & pair("shield", obj.m_shieldId);
			//arc & pair("param1", obj.m_param1);//セーブデータにしかないデータのシミュレーション
			//arc & pair("param2", obj.m_param1);//セーブデータがないデータのシミュレーション
		}
	};
	//--------------------
	//シリアライズ専用処理：CHARA_DATA
	template<class Arc>
	struct save<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver)
		{
			arc & pair("param1", obj.m_param1);//セーブデータにしかないデータのシミュレーション
			arc & pair("basic", obj.m_basic);//セーブデータにしかないオブジェクトのシミュレーション
		}
	};
	//--------------------
	//デシリアライズ専用処理：CHARA_DATA
	template<class Arc>
	struct load<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver, CVersion& now_ver)
		{
			arc & pair("param2", obj.m_param2);//セーブデータがないデータのシミュレーション
		}
	};
	//--------------------
	//セーブデータにはあったが、保存先の指定がなく、ロードできなかった項目の通知
	template<class Arc>
	struct noticeUnrecognizedItem<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unrecognized_item)
		{
			if (unrecognized_item == "param1")
			{
				arc & pair("param1", obj.m_param1);//セーブデータにしかないデータのシミュレーション
			}
			else if (unrecognized_item == "basic")
			{
				arc & pair("basic", obj.m_basic);//セーブデータにしかないデータのシミュレーション
			}
		}
	};
	//--------------------
	//保存先の指定があるが、セーブデータになくロードできなかった項目の通知
	template<class Arc>
	struct noticeUnloadedItem<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unloaded_item)
		{
			if (unloaded_item == "param2")
			{
				obj.m_param2[0] = 98765;
				obj.m_param2[1] = 43210;
			}
		}
	};
	//--------------------
	//ロード後処理：CHARA_DATA
	template<class Arc>
	struct afterLoad<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			CSingleton<CInventory> inventory;
			obj.m_weapon = inventory->find(obj.m_weaponId);//武器のポインタを復元
			obj.m_shield = inventory->find(obj.m_shieldId);//盾のポインタを復元
			obj.m_abilities = nullptr;//アビリティは一旦nullptrにしておく
		}
	};
	//--------------------
	//収集処理：CHARA_DATA
	template<class Arc>
	struct collector<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver)
		{
			CHARA_ABILITY_DATA* chara_ability = obj.m_abilities;
			while (chara_ability)
			{
				//アビリティ情報取得
				ABILITY_DATA* ability_data = chara_ability->m_ability;
				//セーブ用アビリティ情報作成
				//※一時的にローカル変数に記録した情報をセーブする
				CHARA_ABILITY_DATA_FOR_SAVE chara_ability_data_for_save;
				//chara_ability_data_for_save.m_charaId = obj.m_id.getKey();//アビリティID
				chara_ability_data_for_save.m_abilityId = ability_data->getKey();//アビリティID
				//シリアライズ
				arc << pair("charaAbility", chara_ability_data_for_save);
				//次のアビリティ
				chara_ability = chara_ability->m_next;
			}
		}
	};
	//--------------------
	//分配処理：CHARA_DATA
	template<class Arc>
	struct distributor<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{
			if (target_item == "charaAbility")
			{
				//セーブ用アビリティ情報復元
				//※一時的にローカル変数に展開して実際のデータに反映させる
				CHARA_ABILITY_DATA_FOR_SAVE chara_ability_data_for_save;
				//デシリアライズ
				arc >> pair("charaAbility", chara_ability_data_for_save);
				//アビリティ追加
				obj.addAbility(chara_ability_data_for_save.m_abilityId);
			}
		}
	};
	//--------------------
	//シリアライズ処理：CHARA_ABILITY_DATA_FOR_SAVE
	template<class Arc>
	struct serialize<Arc, CHARA_ABILITY_DATA_FOR_SAVE> {
		void operator()(Arc& arc, const CHARA_ABILITY_DATA_FOR_SAVE& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("id", obj.m_abilityId);
		}
	};
	//--------------------
	//シリアライズ処理：CPhaseAndFlags
	template<class Arc>
	struct serialize<Arc, CPhaseAndFlags> {
		void operator()(Arc& arc, const CPhaseAndFlags& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("phase", obj.m_phase);
			arc & pair("flags", obj.m_flags);
		}
	};
	//--------------------
	//シリアライズ処理：CSaveDataVersion
	template<class Arc>
	struct serialize<Arc, CSaveDataVersion> {
		void operator()(Arc& arc, const CSaveDataVersion& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("major", obj.m_loadedMajorVer);
			arc & pair("minor", obj.m_loadedMinorVer);
		}
	};
	//--------------------
	//収集処理：CSaveData
	template<class Arc>
	struct collector<Arc, CSaveData> {
		void operator()(Arc& arc, const CSaveData& obj, const CVersion& ver)
		{
			//セーブデータバージョンのバージョンを保存用に更新
			CSingleton<CSaveDataVersion> save_data_version;
			save_data_version->updateLoadedVer();
			arc << pair("version", *save_data_version);//シリアライズ
			save_data_version->setHasSaved();

			//インベントリのデータを収集
			CSingleton<CInventory> inventory;
			for (auto item_data : *inventory)
			{
				//アイテムデータを一つずつシリアライズ
				arc << pair("item", *item_data);
			}
			//アビリティのデータを収集
			CSingleton<CAbilityList> ability_list;
			for (auto ability_data : *ability_list)
			{
				//アビリティデータを一つずつシリアライズ
				arc << pair("ability", *ability_data);
			}
			//キャラのデータを収集
			CSingleton<CCharaList> chara_list;
			for (auto chara_data : *chara_list)
			{
				//キャラデータを一つずつシリアライズ
				arc << pair("chara", *chara_data);
			}
			//進行＆フラグデータをシリアライズ
			CSingleton<CPhaseAndFlags> phase_and_flags;
			arc << pair("phase_and_flags", *phase_and_flags);
		}
	};
	//--------------------
	//致命的なエラー発生時処理処理：CSaveData
	template<class Arc>
	struct fatalSerializeErrorOccurred<Arc, CSaveData> {
		void operator()(Arc& arc, const CSaveData& obj, const CVersion& ver)
		{
			printf("シリアライズで致命的なエラー発生！\n");
		}
	};
	//--------------------
	//部分ロード対応処理：CSaveData
	crc32_t s_loadTarget;//ロード対象
	void setLoadTarget(const crc32_t loada_target)//ロード対象をセット
	{
		s_loadTarget = loada_target;
	}
	void setLoadTarget(const char* name)//ロード対象をセット
	{
		setLoadTarget(calcCRC32(name));
	}
	void resetLoadTarget()//ロード対象をリセット
	{
		s_loadTarget = 0;
	}
	bool isLoadTarget(const crc32_t name_crc)//ロード対象か？
	{
		return s_loadTarget == 0 || s_loadTarget == name_crc;
	}
	bool isLoadTarget(const char* name)//ロード対象か？
	{
		return isLoadTarget(calcCRC32(name));
	}
	bool isLoadTarget(const CItemBase& item)//ロード対象か？
	{
		return isLoadTarget(item.m_nameCrc);
	}
	bool isPartLoad()//部分ロードか？
	{
		return s_loadTarget != 0;
	}
	bool isPartLoad(const crc32_t name_crc)//部分ロードか？
	{
		return isPartLoad() && isLoadTarget(name_crc);
	}
	bool isPartLoad(const char* name)//部分ロードか？
	{
		return isPartLoad() && isLoadTarget(name);
	}
	//--------------------
	//分配前処理：CSaveData
	template<class Arc>
	struct beforeDistribute<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver)
		{
			if (isLoadTarget("item"))
			{
				//インベントリデータクリア
				CSingleton<CInventory> inventory;
				inventory.destroy();
			}
			if (isLoadTarget("ability"))
			{
				//アビリティデータクリア
				CSingleton<CAbilityList> ability_list;
				ability_list.destroy();
			}
			if (isLoadTarget("chara"))
			{
				//キャラデータクリア
				CSingleton<CCharaList> chara_list;
				chara_list.destroy();
			}
			if (isLoadTarget("ability") || isLoadTarget("chara"))
			{
				//キャラ保有アビリティデータクリア
				CSingleton<CCharaAbilityBuff> chara_ability_list;
				chara_ability_list.destroy();
			}
			if (isLoadTarget("phase_and_flags"))
			{
				//フェーズ＆進行データクリア
				CSingleton<CPhaseAndFlags> phase_and_flags;
				phase_and_flags.destroy();
			}
		}
	};
	//--------------------
	//分配処理：CSaveData
	template<class Arc>
	struct distributor<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{
			if (target_item == "version")
			{
				//セーブデータバージョン
				CSingleton<CSaveDataVersion> save_data_version;
				arc >> pair("version", *save_data_version);//デシリアライズ
				save_data_version->setHasLoaded();
			}
			else if (target_item == "item" && isLoadTarget(target_item))
			{
				//インベントリデータ復元
				CSingleton<CInventory> inventory;
				ITEM_DATA item_data;
				arc >> pair("item", item_data);//デシリアライズ
				inventory->regist(item_data);
			}
			else if (target_item == "ability" && isLoadTarget(target_item))
			{
				//アビリティデータ復元
				CSingleton<CAbilityList> ability_list;
				ABILITY_DATA ability_data;
				arc >> pair("ability", ability_data);
				ability_list->regist(ability_data);
			}
			else if (target_item == "chara" && isLoadTarget(target_item))
			{
				//キャラデータ復元
				CSingleton<CCharaList> chara_list;
				CHARA_DATA chara_data;
				arc >> pair("chara", chara_data);
				chara_list->regist(chara_data);
			}
			else if (target_item == "phase_and_flags" && isLoadTarget(target_item))
			{
				//フェーズ＆進行データ復縁
				CSingleton<CPhaseAndFlags> phase_and_flags;
				arc >> pair("phase_and_flags", *phase_and_flags);
			}
		}
	};
	//--------------------
	//分配後処理：CSaveData
	template<class Arc>
	struct afterDistribute<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver)
		{
			//インベントリデータだけ復元してキャラデータがそのままなら武器と盾を参照し直す
			if (isPartLoad("item") && !isPartLoad("chara"))
			{
				CSingleton<CCharaList> chara_list;
				for (auto& chara_data : *chara_list)
				{
					chara_data->attachItems();//アイテムを参照し直す
				}
			}
		}
	};
	//--------------------
	//致命的なエラー発生時処理処理：CSaveData
	template<class Arc>
	struct fatalDeserializeErrorOccurred<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("デシリアライズで致命的なエラー発生！\n");
#if 1
			//インベントリデータクリア
			CSingleton<CInventory> inventory;
			inventory.destroy();
			//アビリティデータクリア
			CSingleton<CAbilityList> ability_list;
			ability_list.destroy();
			//キャラデータクリア
			CSingleton<CCharaList> chara_list;
			chara_list.destroy();
			//キャラ保有アビリティデータクリア
			CSingleton<CCharaAbilityBuff> chara_ability_list;
			chara_ability_list.destroy();
			//フェーズ＆進行データクリア
			CSingleton<CPhaseAndFlags> phase_and_flags;
			phase_and_flags.destroy();
#endif
		}
	};
}

//--------------------
//シリアライズ
template<class Arc>
std::size_t serialize(void* save_data_buff, const std::size_t save_data_buff_size)
{
	printf("------------------------------------------------------------\n");
	printf("【シリアライズ】\n");
	
	//ワークバッファ準備
	const std::size_t WORK_BUFF_SIZE = 1 * 1024 * 1024;
	void* work_buff = new char[WORK_BUFF_SIZE];

	//シリアライズ用アーカイブオブジェクト生成
	Arc arc(save_data_buff, save_data_buff_size, work_buff, WORK_BUFF_SIZE);

	//シリアライズ
	arc << serial::pair<CSaveData>("SaveData");

	//シリアライズの結果を表示
	serial::CResult result = arc.getResult();
	printf("シリアライズ結果：\n");
	printf("  致命的なエラー ... %s\n", result.hasFatalError() ? "発生！" : "なし");

	//セーブデータのサイズを返す
	return result.getSaveDataSize();
}

//--------------------
//デシリアライズ
template<class Arc>
void deserialize(void* save_data, const std::size_t save_data_size)
{
	printf("------------------------------------------------------------\n");
	printf("【デシリアライズ】\n");
	
	//ワークバッファ準備
	const std::size_t WORK_BUFF_SIZE = 1 * 1024 * 1024;
	void* work_buff = new char[WORK_BUFF_SIZE];

	//シリアライズ用アーカイブオブジェクト生成
	Arc arc(save_data, save_data_size, work_buff, WORK_BUFF_SIZE);

	//デシリアライズ
	arc >> serial::pair<CSaveData>("SaveData");

	//デシリアライズの結果を表示
	serial::CResult result = arc.getResult();
	printf("デシリアライズ結果：\n");
	printf("  致命的なエラー ... %s\n", result.hasFatalError() ? "発生！" : "なし");
	printf("  以下、セーブデータの状態に対する現在のプログラムが変わっていた箇所の集計\n");
	printf("  ・サイズが縮小された項目の数           = %d\n", result.getNumSmallerSizeItem());
	printf("  ・サイズが拡大された項目の数           = %d\n", result.getNumLargerSizeItem());
	printf("  ・配列サイズが縮小された項目の数       = %d\n", result.getNumSmallerArrItem());
	printf("  ・配列サイズが拡大された項目の数       = %d\n", result.getNumLargerArrItem());
	printf("  ・セーブデータ上にのみ存在した項目の数 = %d\n", result.getNumIsOnlyOnSaveData());
	printf("  ・セーブデータ上になかった項目の数     = %d\n", result.getNumIsOnlyOnMem());
	printf("  ・現在はオブジェクト型ではないが、セーブデータ上ではそうだった項目の数 = %d\n", result.getNumIsObjOnSaveDataOnly());
	printf("  ・現在はオブジェクト型だが、セーブデータ上ではそうではなかった項目の数 = %d\n", result.getNumIsObjOnMemOnly());
	printf("  ・現在は配列型ではないが、セーブデータ上ではそうだった項目の数         = %d\n", result.getNumIsArrOnSaveDataOnly());
	printf("  ・現在は配列型だが、セーブデータ上ではそうではなかった項目の数         = %d\n", result.getNumIsArrOnMemOnly());
	printf("  ・現在はポインタ型ではないが、セーブデータ上ではそうだった項目の数     = %d\n", result.getNumIsPtrOnSaveDataOnly());
	printf("  ・現在はポインタ型だが、セーブデータ上ではそうではなかった項目の数     = %d\n", result.getNumIsPtrOnMemOnly());
	printf("  ・現在はヌルではないが、セーブデータ上ではそうだった項目の数           = %d\n", result.getNumIsNulOnSaveDataOnly());
	printf("  ・現在はヌルだが、セーブデータ上ではそうではなかった項目の数           = %d\n", result.getNumIsNulOnMemOnly());
}

//--------------------
//セーブ
void save(const char* file_path, const void* file_image, const std::size_t file_image_size)
{
	printf("------------------------------------------------------------\n");
	printf("【セーブ】\n");
	printf("file=\"%s\", size=%d\n", file_path, file_image_size);
	if (file_image_size == 0)
	{
		printf("Save data not found!\n");
		return;
	}

	FILE* fp;
#ifdef USE_STRCPY_S
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(file_image, 1, file_image_size, fp);
	fclose(fp);
}

//--------------------
//ファイルサイズ取得
std::size_t getFileSize(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
	const std::size_t file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return file_size;
}

//--------------------
//ロード
std::size_t load(const char* file_path, void* file_image_buff, const std::size_t file_image_buff_size_max)
{
	printf("------------------------------------------------------------\n");
	printf("【ロード】\n");

	FILE* fp;
#ifdef USE_STRCPY_S
	fopen_s(&fp, file_path, "rb");
#else//USE_STRCPY_S
	fp = fopen(file_path, "rb");
#endif//USE_STRCPY_S
	std::size_t file_image_size = getFileSize(fp);
	printf("file=\"%s\", size=%d\n", file_path, file_image_size);
	if (file_image_size <= file_image_buff_size_max)
		fread(file_image_buff, 1, file_image_size, fp);
	else
		file_image_size = 0;
	fclose(fp);
	return file_image_size;
}

//--------------------
//シリアライズ＆セーブ
template<class Arc>
void serializeAndSave(const char* file_path)
{
	//セーブデータ用バッファ準備
	const std::size_t SAVE_DATA_BUFF_SIZE = 1 * 1024 * 1024;
	void* save_data_buff = new char[SAVE_DATA_BUFF_SIZE];

	//シリアライズ
	const std::size_t save_data_size = serialize<Arc>(save_data_buff, SAVE_DATA_BUFF_SIZE);

	//セーブ
	save(file_path, save_data_buff, save_data_size);
}

//--------------------
//ロード＆デシリアライズ
template<class Arc>
void loadAndDeserialize(const char* file_path)
{
	//セーブデータ用バッファ準備
	const std::size_t SAVE_DATA_BUFF_SIZE = 1 * 1024 * 1024;
	void* save_data_buff = new char[SAVE_DATA_BUFF_SIZE];

	//ロード
	const std::size_t save_data_size = load(file_path, save_data_buff, SAVE_DATA_BUFF_SIZE);

	//デシリアライズ
	deserialize<Arc>(save_data_buff, save_data_size);
}

//--------------------------------------------------------------------------------
//テスト実行

//--------------------
//シリアライズ
void test2serialize()
{
	//全データリセット
	resetAll();
	//テストデータ作成(pattern=1)
	makeTestData(0);
	//現在のデータを表示
	printDataAll();
	//セーブデータ用バージョンを表示
	printSaveDataVer();
	//ファイルパス＆アーカイブオブジェクト
	const char* save_file_name_bin = "save_data.bin";
	const char* save_file_name_txt = "save_data.txt";
	//シリアライズ＆セーブ
	serializeAndSave<serial::COBinaryArchive>(save_file_name_bin);//バイナリ形式を使用
	serializeAndSave<serial::COTextArchive>(save_file_name_txt);//テキスト形式を使用
	//セーブデータ用バージョンを表示
	printSaveDataVer();
	//全データリセット
	resetAll();
	//現在のデータを表示
	printDataAll();
	//ロード＆デシリアライズ
	loadAndDeserialize<serial::CIBinaryArchive>(save_file_name_bin);
	//セーブデータ用バージョンを表示
	printSaveDataVer();
	//現在のデータを表示
	printDataAll();
	//全データリセット
	resetAll();
	//テストデータ作成(pattern=1)
	makeTestData(1);
	//現在のデータを表示
	printDataAll();
	//部分ロード指定
	//serial::setLoadTarget("phase_and_flags");
	serial::setLoadTarget("chara");
	//ロード＆デシリアライズ
	loadAndDeserialize<serial::CIBinaryArchive>(save_file_name_bin);
	//現在のデータを表示
	printDataAll();
	//部分ロード指定解除
	serial::resetLoadTarget();
}

//--------------------
//テスト
void test2()
{
	//シリアライズ
	test2serialize();
}

//--------------------------------------------------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	test1();
	test2();
	return EXIT_SUCCESS;
}

// End of file
