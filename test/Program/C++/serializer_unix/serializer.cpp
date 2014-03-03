//#define TLS_IS_WINDOWS//【MS固有仕様】TLSの宣言をWindowsスタイルにする時はこのマクロを有効にする
//#define USE_STRCPY_S//【MS固有仕様】strcpy_sを使用する時にこのマクロを有効にする
//#define USE_ALIGNED_MALLOC//【MS固有仕様】_aligned_mallocを使用する時はこのマクロを有効にする
//#define USE_FRIEND_WITH_NEW_OPERATOR//【MS固有仕様？】operator new()をクラス内でフレンド化する時はこのマクロを有効にする
//#define USE_WINDOWS_DEBUG_BREAK//【MS固有仕様】WindowのDebugBreakを使用

#define ENABLE_CONSTEXPR//【C++11用】constexprを有効にする時はこのマクロを有効にする
#define ENABLE_USER_DEFINED_LITERALS//【C++11用】ユーザー定義リテラルを有効にする時はこのマクロを有効にする

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>//assert用
#include <cstddef>//std::size_t用
#include <stdint.h>//uintptr_t用
#include <limits.h>//UCHAR_MAX用
#include <typeinfo.h>//type_id用
#include <map>//STL map用
#include <vector>//STL vector用
#include <atomic>//C++11アトミック操作
#include <thread>//C++11スレッド
#include <chrono>//C++11時間

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
	//--------------------
	//バージョンクラス
	template<unsigned short MAJOR, unsigned short MINOR>
	class CVersionDefBase;
	class CVersion
	{
	public:
		//定数
		static const unsigned int VER_FIGURE = 1000000;//合成バージョン計算用桁上げ数
	public:
		//アクセッサ
		unsigned int getMajor() const { return m_majorVer; };//メジャーバージョン
		unsigned int getMinor() const { return m_minorVer; };//マイナーバージョン
		unsigned int getVer()const { return m_majorVer * VER_FIGURE + m_minorVer; };//合成バージョン
	public:
		//デフォルトコンストラクタ
		CVersion() :
			m_majorVer(0),
			m_minorVer(0)
		{}
		//コンストラクタ
		CVersion(const unsigned short major, const unsigned short minor) :
			m_majorVer(major),
			m_minorVer(minor)
		{}
		template<unsigned short MAJOR, unsigned short MINOR>
		CVersion(CVersionDefBase<MAJOR, MINOR>&) :
			CVersion(MAJOR, MINOR)
		{}
	private:
		//フィールド
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
	//データ項目基底クラス
	class CItemBase
	{
	public:
		//キャストオペレータ
		operator crc32_t() const { return m_nameCrc; }
		operator const char*() const { return m_name; }
		operator const std::type_info& () const { return m_itemType; }
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
	public:
		//コンストラクタ
		CItemBase(const char* name, const void* item_p, const std::type_info& item_type, const std::size_t item_size, const std::size_t arr_num = 0) :
			m_nameCrc(calcCRC32(name)),
			m_name(name),
			m_itemP(item_p),
			m_itemType(item_type),
			m_itemSize(item_size),
			m_arrNum(arr_num)
		{}
		//デストラクタ
		~CItemBase()
		{}
	public://フィールドを公開して直接操作
		//フィールド
		const crc32_t m_nameCrc;//データ項目名CRC
		const char* m_name;//データ項目名
		const void* m_itemP;//データの参照ポインタ
		const std::type_info& m_itemType;//データの型情報
		const std::size_t m_itemSize;//データサイズ
		const std::size_t m_arrNum;//データの配列サイズ
	};
	//--------------------
	//データ項目テンプレートクラス
	template<typename T>
	class CItem : public CItemBase
	{
	public:
		//コンストラクタ
		CItem(const char* name, const T& item, const std::size_t arr_num) :
			CItemBase(name, &item, typeid(T), sizeof(T), arr_num)
		{}
		CItem(const char* name, const std::size_t size) :
			CItemBase(name, nullptr, typeid(T), size, 0)
		{}
		//デストラクタ
		~CItem()
		{}
	};
	//--------------------
	//データ項目情報作成テンプレート関数
	template<class T>
	CItem<T> pair(const char* name, const T& item)
	{
		CItem<T> item_obj(name, item, 0);
		return item_obj;
	}
	//--------------------
	//データ項目情報作成テンプレート関数（配列用）
	template<class T, std::size_t N>
	CItem<T> pair(const char* name, const T(&item)[N])
	{
		CItem<T> item_obj(name, item[0], N);
		return item_obj;
	}
	//--------------------
	//データ項目情報作成テンプレート関数（バイナリ用）
	template<class T>
	CItem<char> pairBin(const char* name, const T& item)
	{
		const std::size_t size = sizeof(T);
		const char* item_p = reinterpret_cast<const char*>(&item);
		CItem<char> item_obj(name, *item_p, size);
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
	//アイテム入出力結果クラス
	class CIOResult
	{
	public:
		//型
		struct Output{};//出力時指定用構造体
		struct Input{};//入力時指定用構造体
	public:
		//コンストラクタ
		CIOResult() :
			m_isInput(false),
			m_hasFatalError(false),
			m_hasSrc(false),
			m_hasDst(false),
			m_srcSize(0),
			m_dstSize(0),
			m_copiedSize(0)
		{}
		//出力時用コンストラクタ
		CIOResult(const Output&, const CItemBase& item) :
			m_isInput(false),
			m_hasFatalError(false),
			m_hasSrc(true),
			m_hasDst(false),
			m_srcSize(item.m_itemSize),
			m_dstSize(0),
			m_copiedSize(0)
		{}
		//入力時用コンストラクタ
		CIOResult(const Input&, const CItemBase& item) :
			m_isInput(true),
			m_hasFatalError(false),
			m_hasSrc(false),
			m_hasDst(true),
			m_srcSize(0),
			m_dstSize(item.m_itemSize),
			m_copiedSize(0)
		{}
		//デストラクタ
		~CIOResult()
		{}
	public://フィールドを公開して直接操作
		//フィールド
		bool m_isInput;//入力処理か？
		bool m_hasFatalError;//致命的なエラーあり
		bool m_hasSrc;//コピー元あり
		bool m_hasDst;//コピー先あり
		std::size_t m_srcSize;//コピー元サイズ
		std::size_t m_dstSize;//コピー先サイズ
		std::size_t m_copiedSize;//コピー済みサイズ
	};
	
	//--------------------
	//ロード前処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct beforeLoad {
		typedef beforeLoad<Arc, T> IS_UNDEFINED;//SFINAE:関数オブジェクトの未定義チェック用の型定義（自身と同じ型を定義）
		void operator()(Arc& arc, T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//シリアライズ処理用関数オブジェクトテンプレートクラス
	//※シリアライズとデシリアライズ兼用共通処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct serialize {
		typedef serialize<Arc, T> IS_UNDEFINED;//SFINAE:関数オブジェクトの未定義チェック用の型定義（自身と同じ型を定義）
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//セーブ処理用関数オブジェクトテンプレートクラス
	//※シリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct save	{
		typedef save<Arc, T> IS_UNDEFINED;//SFINAE:関数オブジェクトの未定義チェック用の型定義（自身と同じ型を定義）
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
		typedef load<Arc, T> IS_UNDEFINED;//SFINAE:関数オブジェクトの未定義チェック用の型定義（自身と同じ型を定義）
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//ロード後処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct afterLoad {
		typedef afterLoad<Arc, T> IS_UNDEFINED;//SFINAE:関数オブジェクトの未定義チェック用の型定義（自身と同じ型を定義）
		void operator()(Arc& arc, T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//データ収集処理用関数オブジェクトテンプレートクラス
	//※シリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct gatherer	{
		typedef gatherer<Arc, T> IS_UNDEFINED;//SFINAE:関数オブジェクトの未定義チェック用の型定義（自身と同じ型を定義）
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//データ分配処理用関数オブジェクトテンプレートクラス
	//※デシリアライズ専用処理
	//※特殊化によりユーザー処理を実装
	//※標準では何もしない
	template<class Arc, class T>
	struct distributor {
		typedef distributor<Arc, T> IS_UNDEFINED;//SFINAE:関数オブジェクトの未定義チェック用の型定義（自身と同じ型を定義）
		void operator()(Arc& arc, T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//関数オブジェクト定義済みチェック関数
	//※SFINAEにより、IS_UNDEFINED が定義されている型のオーバーロード関数が選ばれたら未定義とみなす
	template<class F>
	bool isDefinedFunctor(const typename  F::IS_UNDEFINED& o)
	{
		return false;//未定義
	}
	template<class F>
	bool isDefinedFunctor(const F& o)
	{
		return true;//定義済み
	}
	
	//--------------------
	//アーカイブ形式基底クラス
	class CArchiveStyleBase;
	//--------------------
	//入出力アーカイブ基底クラス
	class CIOArchiveBase
	{
	public:
		//型
		typedef unsigned char byte;//バッファ用
		typedef std::vector<CItemBase> itemList_t;//データ項目リスト型
		typedef std::map<crc32_t, const CItemBase*> itemSearch_t;//データ検索リスト型
	public:
		//アクセッサ
		const byte* getBuffPtr() const { return m_buff; }//セーブデータバッファ
		const std::size_t getBuffSize() const { return m_buffSize; }//セーブデータバッファのサイズ
		const std::size_t getBuffPos() const { return m_buffPos; }//セーブデータバッファの処理位置
	public:
		//メソッド
		//リストにデータ項目追加
		void addItem(const CItemBase& item)
		{
			//ワーク領域を設定（グローバル多態アロケータ）
			//※関数を抜けると自動的に元に戻る
			CTempPolyStackAllocator alloc(m_workBuff);

			//データ項目を追加
			assert(m_itemSearch->find(item) == m_itemSearch->end());
			m_itemList->push_back(item);
			const CItemBase& rec = m_itemList->at(m_itemList->size() - 1);
			m_itemSearch->emplace(item.m_nameCrc, &rec);
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

			//データ検索リストを生成
			m_itemSearch = new itemSearch_t;
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
			//データ検索リストを破棄
			if (m_itemSearch)
			{
				delete m_itemSearch;
				m_itemSearch = nullptr;
			}

			//ワークバッファ用スタックアロケータクリア
			m_workBuff.clearN();
		}
	public:
		//コンストラクタ
		CIOArchiveBase(CArchiveStyleBase& style, void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(style),
			m_nestLevel(0),
			m_buff(reinterpret_cast<byte*>(buff)),
			m_buffSize(buff_size),
			m_buffPos(0),
			m_workBuff(work_buff, work_buff_size),
			m_itemList(nullptr),
			m_itemSearch(nullptr)
		{
			//データリスト作成
			createItemList();
		}
		//コンストラクタ
		CIOArchiveBase(CIOArchiveBase& src, const std::size_t buff_size) :
			m_style(src.m_style),
			m_nestLevel(src.m_nestLevel + 1),
			m_buff(src.m_buff + src.m_buffPos),
			m_buffSize(buff_size),
			m_buffPos(0),
			m_workBuff(const_cast<IStackAllocator::byte*>(src.m_workBuff.getNowPtrN()), src.m_workBuff.getRemain()),
			m_itemList(nullptr),
			m_itemSearch(nullptr)
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
		CArchiveStyleBase& m_style;//アーカイブ形式
		int m_nestLevel;//データのネストレベル
		byte* m_buff;//セーブデータバッファ
		const std::size_t m_buffSize;//セーブデータバッファのサイズ
		std::size_t m_buffPos;//セーブデータバッファの処理位置
		CStackAllocator m_workBuff;//ワークバッファ用スタックアロケータ
		itemList_t* m_itemList;//データ項目リスト
		itemSearch_t* m_itemSearch;//データ検索リスト
	};
	//--------------------
	//アーカイブ形式基底クラス
	class CArchiveStyleBase
	{
	public:
		//メソッド
		virtual bool outputSignature(CIOResult& result, CIOArchiveBase& arc) = 0;//シグネチャ出力
		virtual bool inputSignature(CIOResult& result, CIOArchiveBase& arc) = 0;//シグネチャ入力（正しいデータかチェック）
		virtual bool outputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;//ブロック開始情報出力
		virtual bool inputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;//ブロック開始情報入力
		virtual bool outputVersion(CIOResult& result, CIOArchiveBase& arc, const CVersion& ver) = 0;//バージョン出力
		virtual bool inputVersion(CIOResult& result, CIOArchiveBase& arc, CVersion& ver) = 0;//バージョン入力
		virtual bool output(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;//出力
		virtual bool input(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;//入力
		virtual bool outputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) = 0;//ブロック終了情報出力
		virtual bool inputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) = 0;//ブロック終了情報入力
		virtual bool outputTerminator(CIOResult& result, CIOArchiveBase& arc) = 0;//ターミネータ出力
		virtual bool inputTerminator(CIOResult& result, CIOArchiveBase& arc) = 0;//ターミネータ入力（正しいデータかチェック）
	public:
		//コンストラクタ
		CArchiveStyleBase()
		{}
		//デストラクタ
		~CArchiveStyleBase()
		{}
	};
	//--------------------
	//入出力アーカイブダミークラス（なにもしない）
	class CIOArchiveDummy
	{
	public:
		//オペレータ
		//「&」オペレータ
		//※データ項目指定＆データ出力用処理
		template<class T>
		CIOArchiveDummy& operator&(const CItem<T> item_obj)
		{
			return *this;
		}
		//「<<」オペレータ
		//※データ出力
		template<class T>
		CIOArchiveDummy& operator<<(const CItem<T> item_obj)
		{
			return *this;
		}
		//「>>」オペレータ
		//※データ入力
		template<class T>
		CIOArchiveDummy& operator>>(CItem<T> item_obj)
		{
			return *this;
		}
	};
	//--------------------
	//出力アーカイブクラス
	class COArchive : public CIOArchiveBase
	{
	public:
		//オペレータ
		//「&」オペレータ
		//※データ項目指定＆データ出力用処理
		template<class T>
		COArchive& operator&(const CItem<T> item_obj)
		{
			//printf("[operator&] name=%s, typeName=%s, item=0x%p [%d]\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP, item_obj.m_arrNum);
			
			//データ項目を記録
			addItem(item_obj);
			
			//専用シリアライズ処理があるかチェック
			bool is_obj = false;

			//シリアライズ処理（シリアライズ＆デシリアライズ兼用処理）存在確認
			if (!is_obj)
			{
				serialize<CIOArchiveDummy, T> functor;
				is_obj = isDefinedFunctor(functor);
			}
			
			//セーブ処理（シリアライズ専用処理）存在確認
			if (!is_obj)
			{
				save<CIOArchiveDummy, T> functor;
				is_obj = isDefinedFunctor(functor);
			}
			
			//出力
			if (is_obj)
			{
				//オブジェクトなので operator<<() で出力
				*this << item_obj;
			}
			else
			{
				//データをアーカイブに記録
				CIOResult result(CIOResult::Output(), item_obj);
				m_style.output(result, *this, item_obj);
			}
			
			return *this;
		}
		//「<<」オペレータ
		//※データ出力
		template<class T>
		COArchive& operator<<(const CItem<T> item_obj)
		{
			//printf("[operator<<] name=%s, typeName=%s, item=0x%p\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP);
			
			//ネストレベルが0ならシグネチャーを書き込み
			if (m_nestLevel == 0)
			{
				CIOResult result;
				m_style.outputSignature(result, *this);
			}
			
			//ブロック開始情報書き込み
			{
				CIOResult result;
				m_style.outputBeginBlock(result, *this, item_obj);
			}
			
			//ブロック開始
			std::size_t block_size = 0;
			{
				//新しいアーカイブオブジェクトを生成
				COArchive new_arc(*this, m_buffSize - m_buffPos);
				
				//バージョン取得
				CVersionDef<T> ver_def;
				CVersion ver(ver_def);
				
				//バージョン書き込み
				{
					CIOResult result;
					m_style.outputVersion(result, new_arc, ver);
				}
				
				//シリアライズ処理（シリアライズ＆デシリアライズ兼用処理）呼び出し
				{
					serialize<COArchive, T> functor;
					functor(new_arc, item_obj.template getConst<T>(), ver);
				}
				
				//セーブ処理（シリアライズ専用処理）呼び出し
				{
					save<COArchive, T> functor;
					functor(new_arc, item_obj.template getConst<T>(), ver);
				}
				
				//データ収集処理（シリアライズ専用処理）呼び出し
				{
					gatherer<COArchive, T> functor;
					functor(new_arc, item_obj.template getConst<T>(), ver);
				}
				
				//ブロック終了
				block_size = new_arc.m_buffPos;
			}
			
			//ブロック終了情報書き込み
			{
				CIOResult result;
				m_style.outputEndBlock(result, *this, item_obj, block_size);
			}
			
			//ネストレベルが0ならターミネータを書き込み
			if (m_nestLevel == 0)
			{
				CIOResult result;
				m_style.outputTerminator(result, *this);
			}
			
			return *this;
		}
	public:
		//コンストラクタ
		COArchive(CArchiveStyleBase& style, void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		COArchive(CArchiveStyleBase& style, BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		COArchive(CArchiveStyleBase& style, void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		COArchive(COArchive& src, const std::size_t size) :
			CIOArchiveBase(src, size)
		{}
		//デストラクタ
		~COArchive()
		{}
	};
	//--------------------
	//入力アーカイブクラス
	class CIArchive : public CIOArchiveBase
	{
	public:
		//オペレータ
		//「&」オペレータ
		//※データ項目指定用処理
		template<class T>
		CIArchive& operator&(const CItem<T> item_obj)
		{
			//printf("[operator&] name=%s, typeName=%s, item=0x%p [%d]\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP, item_obj.m_arrNum);
			//データ項目を記録
			addItem(item_obj);
			return *this;
		}
		
		//「>>」オペレータ
		//※データ入力
		template<class T>
		CIArchive& operator>>(CItem<T> item_obj)
		{
			//printf("[operator>>] name=%s, typeName=%s, item=0x%p\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP);
			
			//ネストレベルが0ならシグネチャーを読み込み
			if (m_nestLevel == 0)
			{
				CIOResult result;
				m_style.inputSignature(result, *this);
			}
			
			//ブロック開始情報読み込み
			{
				CIOResult result;
				m_style.inputBeginBlock(result, *this, item_obj);
			}
			
			//ブロック開始
			std::size_t block_size = 0;
			{
				//新しいアーカイブオブジェクトを生成
				CIArchive new_arc(*this, m_buffSize - m_buffPos);
				
				//バージョン読み込み
				CVersion ver;
				{
					CIOResult result;
					m_style.inputVersion(result, new_arc, ver);
				}
				
				//ロード前処理（デシリアライズ専用処理）呼び出し
				{
					beforeLoad<CIArchive, T> functor;
					functor(new_arc, item_obj.template get<T>(), ver);
				}
				
				//デシリアライズ処理（シリアライズ＆デシリアライズ兼用処理）呼び出し
				{
					serialize<CIArchive, T> functor;
					functor(new_arc, item_obj.template getConst<T>(), ver);
				}
				
				//ロード処理（デシリアライズ専用処理）呼び出し
				{
					load<CIArchive, T> functor;
					functor(new_arc, item_obj.template get<T>(), ver);
				}
				
				//実際のロード処理
				for (auto item : *m_itemList)
				{
					CIOResult result(CIOResult::Input(), item);
					m_style.input(result, new_arc, item);
				}
				
				//ロード後処理（デシリアライズ専用処理）呼び出し
				{
					afterLoad<CIArchive, T> functor;
					functor(new_arc, item_obj.template get<T>(), ver);
				}
				
				//データ分配処理（デシリアライズ専用処理）呼び出し
				{
					distributor<CIArchive, T> functor;
					functor(new_arc, item_obj.template get<T>(), ver);
				}
				
				//ブロック終了
				block_size = new_arc.m_buffPos;
			}
			
			//ブロック終了情報読み込み
			{
				CIOResult result;
				m_style.inputEndBlock(result, *this, item_obj, block_size);
			}
			
			//ネストレベルが0ならターミネータを読み込み
			if (m_nestLevel == 0)
			{
				CIOResult result;
				m_style.inputTerminator(result, *this);
			}
			
			return *this;
		}
	public:
		//コンストラクタ
		CIArchive(CArchiveStyleBase& style, const void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(style, const_cast<void*>(buff), buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(CArchiveStyleBase& style, const BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, const_cast<BUFF_T*>(&buff[0]), BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(CArchiveStyleBase& style, const void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, const_cast<void*>(buff), buff_size, work_buff, WORK_SIZE)
		{}
		CIArchive(CIArchive& src, const std::size_t size) :
			CIOArchiveBase(src, size)
		{}
		//デストラクタ
		~CIArchive()
		{}
	};
	//--------------------
	//バイナリ形式アーカイブクラス
	class CBinaryArchive : public CArchiveStyleBase
	{
	public:
		//定数
		static const char SIGNATURE[];//シグネチャ
	public:
		//メソッド
		//シグネチャ出力
		bool outputSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//シグネチャ入力（正しいデータかチェック）
		bool inputSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//ブロック開始情報出力
		bool outputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//ブロック開始情報入力
		bool inputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//バージョン出力
		bool outputVersion(CIOResult& result, CIOArchiveBase& arc, const CVersion& ver) override
		{
			return true;
		}
		//バージョン入力
		bool inputVersion(CIOResult& result, CIOArchiveBase& arc, CVersion& ver) override
		{
			return true;
		}
		//出力
		bool output(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//入力
		bool input(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//ブロック終了情報出力
		bool outputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			return true;
		}
		//ブロック終了情報入力
		bool inputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			return true;
		}
		//ターミネータ出力
		bool outputTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//ターミネータ入力（正しいデータかチェック）
		bool inputTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
	public:
		//コンストラクタ
		CBinaryArchive():
			CArchiveStyleBase()
		{}
		//デストラクタ
		~CBinaryArchive()
		{}
	};
	//静的変数インスタンス化
	const char CBinaryArchive::SIGNATURE[] = "";//シグネチャ
	//--------------------
	//テキスト形式アーカイブクラス
	class CTextArchive : public CArchiveStyleBase
	{
	public:
		//メソッド
		//シグネチャ出力
		bool outputSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//シグネチャ入力（正しいデータかチェック）
		bool inputSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//ブロック開始情報出力
		bool outputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//ブロック開始情報入力
		bool inputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//バージョン出力
		bool outputVersion(CIOResult& result, CIOArchiveBase& arc, const CVersion& ver) override
		{
			return true;
		}
		//バージョン入力
		bool inputVersion(CIOResult& result, CIOArchiveBase& arc, CVersion& ver) override
		{
			return true;
		}
		//出力
		bool output(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//入力
		bool input(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//ブロック終了情報出力
		bool outputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			return true;
		}
		//ブロック終了情報入力
		bool inputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			return true;
		}
		//ターミネータ出力
		bool outputTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//ターミネータ入力（正しいデータかチェック）
		bool inputTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
	public:
		//コンストラクタ
		CTextArchive():
			CArchiveStyleBase()
		{}
		//デストラクタ
		~CTextArchive()
		{}
	};
	//--------------------
	//バイナリ出力アーカイブクラス
	class COBinaryArchive : public COArchive
	{
	public:
		//コンストラクタ
		COBinaryArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(),
			COArchive(m_style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		COBinaryArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			COArchive(m_style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		COBinaryArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			COArchive(m_style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		//デストラクタ
		~COBinaryArchive()
		{}
	private:
		//フィールド
		CBinaryArchive m_style;
	};
	//--------------------
	//バイナリ入力アーカイブクラス
	class CIBinaryArchive : public CIArchive
	{
	public:
		//コンストラクタ
		CIBinaryArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(),
			CIArchive(m_style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CIBinaryArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			CIArchive(m_style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CIBinaryArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			CIArchive(m_style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		//デストラクタ
		~CIBinaryArchive()
		{}
	private:
		//フィールド
		CBinaryArchive m_style;
	};
	//--------------------
	//テキスト出力アーカイブクラス
	class COTextArchive : public COArchive
	{
	public:
		//コンストラクタ
		COTextArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(),
			COArchive(m_style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		COTextArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			COArchive(m_style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		COTextArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			COArchive(m_style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		//デストラクタ
		~COTextArchive()
		{}
	private:
		//フィールド
		CTextArchive m_style;
	};
	//--------------------
	//テキスト入力アーカイブクラス
	class CITextArchive : public CIArchive
	{
	public:
		//コンストラクタ
		CITextArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(),
			CIArchive(m_style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CITextArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			CIArchive(m_style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CITextArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			CIArchive(m_style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		//デストラクタ
		~CITextArchive()
		{}
	private:
		//フィールド
		CTextArchive m_style;
	};
}
//--------------------
//データクラス用のバージョン定義マクロ
#define SERIALIZE_VERSION_DEF(T, MAJOR, MINOR) \
	namespace serial \
	{ \
		template<> \
		struct CVersionDef<T> : public CVersionDefBase<MAJOR, MINOR>{}; \
	}
//--------------------
//データクラスのフレンド宣言用マクロ
#define FRIEND_SERIALIZE(T) \
	template<class Arc, class T> \
	friend struct serial::beforeLoad; \
	template<class Arc, class T> \
	friend struct serial::serialize; \
	template<class Arc, class T> \
	friend struct serial::save; \
	template<class Arc, class T> \
	friend struct serial::load; \
	template<class Arc, class T> \
	friend struct serial::afterLoad; \
	template<class Arc, class T> \
	friend struct serial::gatherer; \
	template<class Arc, class T> \
	friend struct serial::distributor;

//--------------------------------------------------------------------------------
//シリアライズテスト

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
	STRUCT& getData4(){ return m_data4; }//データ4取得
	const STRUCT& getData4() const { return m_data4; }//データ4取得
	bool getData5(const int index) const { return m_data5[index]; }//データ5取得
	void setData5(const int index, const bool value){ m_data5[index] = value; }//データ5更新
public:
	//コンストラクタ
	CTest1() :
		m_data1(0),
		m_data2(0.f),
		m_data4(),
		m_data5()
	{
		m_data3[0] = 0;
		m_data3[1] = 0;
		m_data5.reset();
	}
private:
	//フィールド
	int m_data1;//データ1
	float m_data2;//データ2
	char m_data3[3];//データ3
	STRUCT m_data4;//データ4
	std::bitset<8192> m_data5;//フラグ用
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
static CTest1 s_saveData;

//セーブデータ初期化
void initSaveData()
{
	//セーブデータ取得
	CTest1& data = s_saveData;
	//データを初期化
	data.setData1(1);
	data.setData2(2.34f);
	data.setData3(0, 5);
	data.setData3(1, 6);
	data.setData3(2, 7);
	data.getData4().m_a = 8;
	data.getData4().m_b = 9;
	data.getData4().m_c = 10;
	data.setData5(0, true);
	data.setData5(1, true);
	data.setData5(8191, true);
}

//セーブデータ内容表示
void printSaveData()
{
	//セーブデータ取得
	CTest1& data = s_saveData;
	//データ表示
	printf("data1=%d\n", data.getData1());
	printf("data2=%.2f\n", data.getData2());
	printf("data3={%d, %d, %d}\n", data.getData3(0), data.getData3(1), data.getData3(2));
	printf("data4:a=%d,b=%d,c=%d\n", data.getData4().m_a, data.getData4().m_b, data.getData4().m_c);
	printf("data5:[0]=%d,[1]=%d,[2]=%d,[8190]=%d,[8191]=%d\n", data.getData5(0), data.getData5(1), data.getData5(2), data.getData5(8190), data.getData5(8191));
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
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver)
		{
			printf("beforeLoad(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//シリアライズ処理用関数オブジェクト
	//※シリアライズとデシリアライズ兼用共通処理
	template<class Arc>
	struct serialize<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver)
		{
			printf("serialize(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			arc & pair("data1", obj.m_data1);
			arc & pair("data2", obj.m_data2);
			arc & pair("data3", obj.m_data3);
			arc & pair("data4", obj.m_data4);
			arc & pairBin("data5", obj.m_data5);
		}
	};
	template<class Arc>
	struct serialize<Arc, CTest1::STRUCT> {
		void operator()(Arc& arc, const CTest1::STRUCT& obj, const CVersion& ver)
		{
			printf("serialize::STRUCT(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			arc & pair("data1", obj.m_a);
			arc & pair("data2", obj.m_b);
			arc & pair("data3", obj.m_c);
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
			printf("save(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//ロード処理用関数オブジェクトクラス
	//※デシリアライズ専用処理
	template<class Arc>
	struct load<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver)
		{
			printf("load(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//ロード後処理用関数オブジェクトクラス
	//※デシリアライズ専用処理
	template<class Arc>
	struct afterLoad<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver)
		{
			printf("afterLoad(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//データ収集処理用関数オブジェクトクラス
	//※シリアライズ専用処理
	template<class Arc>
	struct gatherer<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver)
		{
			printf("gatherer(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//データ分配処理用関数オブジェクトクラス
	//※デシリアライズ専用処理
	template<class Arc>
	struct distributor<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver)
		{
			printf("distributor(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//データ収集処理用関数オブジェクトクラス
	//※シリアライズ専用処理
	template<class Arc>
	struct gatherer<Arc, CSaveDataSerializer> {
		void operator()(Arc& arc, const CSaveDataSerializer& obj, const CVersion& ver)
		{
			printf("CSaveDataSerializer::gatherer(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			//対象データ取得
			CTest1& data = s_saveData;
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
		void operator()(Arc& arc, CSaveDataSerializer& obj, const CVersion& ver)
		{
			printf("CSaveDataSerializer::distributor(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			//対象データ取得
			CTest1& data = s_saveData;
			//デシリアライズ
			arc >> pair("CTest1", data);
		}
	};
#endif
}//namespace serial

//--------------------
//シリアライズテスト１：バイナリアーカイブ
void serializeTest1(const char* file_path)
{
	printf("--------------------\n");
	printf("シリアライズ：バイナリアーカイブ\n");
	//セーブデータ初期化
	initSaveData();
	//セーブデータ表示
	printSaveData();
	//バッファ準備
	char buff[16 * 1024];//セーブデータ用バッファ
	char work[16 * 1024];//ワーク用バッファ
	//シリアライズ
	serial::COBinaryArchive oa(buff, work);//出力アーカイブ作成：テキストアーカイブ
	oa << serial::pair<CSaveDataSerializer>("SaveData");//シリアライズ
	//ファイルに書き出し
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(buff, 1, oa.getBuffPos(), fp);
	fclose(fp);
	fp = NULL;
}
//--------------------
//デシリアライズテスト１：バイナリアーカイブ
void deserializeTest1(const char* file_path)
{
	printf("--------------------\n");
	printf("デシリアライズ：バイナリアーカイブ\n");
	//バッファ準備
	char buff[16 * 1024];//セーブデータ用バッファ
	char work[16 * 1024];//ワーク用バッファ
	//ファイルから読み込み
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "rb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "rb");
#endif//USE_STRCPY_S
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	fread(buff, 1, file_size, fp);
	fclose(fp);
	fp = NULL;
	//デシリアライズ
	serial::CIBinaryArchive ia(buff, file_size, work);
	ia >> serial::pair<CSaveDataSerializer>("CTest1", file_size);
	//セーブデータ表示
	printSaveData();
}
//--------------------
//シリアライズ＆デシリアライズテスト１：バイナリアーカイブ
void test1()
{
	static const char* file_path = "test1.bin";
	//シリアライズ
	serializeTest1(file_path);
	//デシリアライズ
	deserializeTest1(file_path);
}

//--------------------
//テスト
int main(const int argc, const char* argv[])
{
	test1();

	return EXIT_SUCCESS;
}

// End of file
