//--------------------------------------------------------------------------------
//コンパイラ＆プラットフォーム判定
//--------------------------------------------------------------------------------

//----------------------------------------
//コンパイラ判定
#ifdef _MSC_VER 
	#include <cstddef>//VC++では、これを最初にインクルードしておかないと、コンパイルに影響がでることがある。
                      //※先に #define constexpr や #define thread_local を行ったあとで、
	                  //　#include<cstddef>(std::size_tなど用)を行うと、以後の処理で不可解なコンパイルエラーが発生する。
	#define IS_VC//コンパイラ：Visual C++
	#define COMPILER_NAME "VC++"
	#define COMPILER_VER _MSC_VER//コンパイラバージョン（メジャーバージョン）
	#define COMPILER_MINOR 0//コンパイラバージョン（マイナーバージョン）
	//_MSC_VERの値
	//   600 ... C Compiler 6.0
	//   700 ... C/C++ Compiler 7.0
	//   800 ... Visual C++ 1.0
	//   900 ... Visual C++ 2.0
	//  1000 ... Visual C++ 4.0
	//  1010 ... Visual C++ 4.1
	//  1020 ... Visual C++ 4.2
	//  1100 ... Visual C++ 5.0 (Visual Studio 97)
	//  1200 ... Visual C++ 6.0 (Visual Studio 6.0)
	//  1300 ... Visual C++ 7.0 (Visual Studio.NET 2002)
	//  1310 ... Visual C++ 7.1 (Visual Studio.NET 2003)
	//  1400 ... Visual C++ 8.0 (Visual Studio 2005)
	//  1500 ... Visual C++ 9.0 (Visual Studio 2008)
	//  1600 ... Visual C++ 10.0 (Visual Studio 2010)
	//  1700 ... Visual C++ 11.0 (Visual Studio 2012)
	//  1800 ... Visual C++ 12.0 (Visual Studio 2013)
#endif//_MSC_VER
#ifdef __GNUC__
	#include <features.h>//__GNUC_PREREQマクロを使えるようにする
	#define IS_GCC//コンパイラ：GCC
	#define COMPILER_NAME "GCC"
	#define COMPILER_VER __GNUC__//コンパイラバージョン（メジャーバージョン）
	#define COMPILER_MINOR __GNUC_MINOR__//コンパイラバージョン（マイナーバージョン）
#endif//__GNUC__
#ifdef __cplusplus
	#define IS_CPP//言語：C++
	#define COMPILER_LANGUAGE "C++"
	#if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
		//#define HAS_CPPTR1//言語：C++TR1対応（暫定）
		#define HAS_CPP11//言語：C++11対応
		#define CPP_VER 2011
	#endif
	#if __cplusplus >= 199711L
		#define HAS_CPP98//言語：C++98対応
		#define HAS_CPP03//言語：C++03対応（暫定）
		#ifndef CPP_VER
			//#define CPP_VER 1998
			#define CPP_VER 2003
		#endif//CPP_VER
	#endif
#else//__cplusplus
	#define IS_C//言語：C
	#define COMPILER_LANGUAGE "C"
	#define CPP_VER 0
#endif//__cplusplus

//----------------------------------------
//プラットフォーム判定
#ifdef _WIN32
	#define IS_WIN//プラットフォーム：Windows
	#define PLATFORM_NAME "Win"//プラットフォーム名
	#ifdef WINVER
		#define PLATFORM_VER WINVER//プラットフォームバージョン ※別途_WIN32_WINNT/WINVERを設定する必要あり
		//_WIN32_WINNT / WINVER に指定可能な値
		//  0x500 ... Windows2000
		//  0x501 ... Windows XP / Windows 2003 Server
		//  0x502 ... Windows XP SP2 / Windows 2003 Server SP1
		//  0x600 ... Windows Vista / Windows 2008 Server
		//  0x700 ... Windows 7
	#else//WINVER	
		#define PLATFORM_VER 0//プラットフォームバージョン
	#endif//WINVER
	#define PLATFORM_MINOR 0//プラットフォームマイナーバージョン
	#ifdef _WIN64
		#define IS_64BIT//プラットフォーム：64bit
		#define PLATFORM_ARCHITECTURE_BITS 64//プラットフォームアーキテクチャ（ビット長）
	#else//_WIN64
		#define IS_32BIT//プラットフォーム：32bit
		#define PLATFORM_ARCHITECTURE_BITS 32//プラットフォームアーキテクチャ（ビット長）
	#endif//_WIN64
#endif//_WIN32
#ifdef __linux__
	#define IS_LINUX//プラットフォーム：Linux
	#define PLATFORM_VER 0//プラットフォームバージョン
	#define PLATFORM_MINOR 0//プラットフォームマイナーバージョン
	#define PLATFORM_NAME "Linux"
	#ifdef __x86_64__
		#define IS_64BIT//プラットフォーム：64bit
		#define PLATFORM_ARCHITECTURE_BITS 64//プラットフォームアーキテクチャ（ビット長）
	#else//__x86_64__
		#define IS_32BIT//プラットフォーム：32bit
		#define PLATFORM_ARCHITECTURE_BITS 32//プラットフォームアーキテクチャ（ビット長）
	#endif//__x86_64__
#endif//__linux__
#ifdef __CYGWIN__
	#define IS_CYGWIN//プラットフォーム：Cygwin
	#define PLATFORM_VER 0//プラットフォームバージョン
	#define PLATFORM_MINOR 0//プラットフォームマイナーバージョン
	#define PLATFORM_NAME "Cygin"
#endif//__CYGWIN__

//CPU
#if defined(__x86_64__) || defined(_M_X64)
	#define IS_X86//プラットフォームアーキテクチャ：x86系
	#define IS_X64//プラットフォームアーキテクチャ：x64系
	#define PLATFORM_ARCHITECTURE "x64"//プラットフォームアーキテクチャ名
	#define IS_64BIT//プラットフォーム：64bit
	#define PLATFORM_ARCHITECTURE_BITS 64//プラットフォームアーキテクチャ（ビット長）
	#ifndef __LITTLE_ENDIAN__	
		#define __LITTLE_ENDIAN__//リトルエンディアン
	#endif//__LITTLE_ENDIAN__	
#elif defined(__i386__) || defined(_M_IX86)
	#define IS_X86//プラットフォームアーキテクチャ：x86系
	#define PLATFORM_ARCHITECTURE "x86"//プラットフォームアーキテクチャ名
	#define IS_32BIT//プラットフォーム：32bit
	#define PLATFORM_ARCHITECTURE_BITS 32//プラットフォームアーキテクチャ（ビット長）
	#ifndef __LITTLE_ENDIAN__	
		#define __LITTLE_ENDIAN__//リトルエンディアン
	#endif//__LITTLE_ENDIAN__	
#endif//__x86_64__/__i386__

//エンディアン判定
#ifdef __BIG_ENDIAN__
	#define IS_BIG_ENDIAN//プラットフォーム：ビッグエンディアン
	#define ENDIAN "big"//エンディアン名
#endif//__BIG_ENDIAN__ 
#ifdef __LITTLE_ENDIAN__
	#define IS_LITTLE_ENDIAN//プラットフォーム：リトルエンディアン
	#define ENDIAN "little"//エンディアン名
#endif//__LITTLE_ENDIAN__ 

//----------------------------------------
//関数名取得マクロ対応

//文字列化マクロ
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)

//関数名取得マクロ
//【注意】GCCの関数名 __FUNCTION__, __PRETTY_FUNCTION__ は関数なので、
//　　　　コンパイル時の文字列結合ができない
#ifdef IS_VC
	#define __PRETTY_FUNCTION__ __FUNCSIG__
	#define __func__ __FUNCTION__
#endif//IS_VC
#ifdef IS_GCC
	#define __FUNCSIG__ __PRETTY_FUNCTION__
	#define __FUNCDNAME__ ""
#endif//IS_GCC

//関数名取得マクロ
#define GET_FUNC_NAME() __PRETTY_FUNCTION__

//ソースファイル名＋行番号取得マクロ
#define GET_FILE_LINE() __FILE__ "(" TO_STRING_EX(__LINE__) ")"
#define GET_FILE_LINE_TIME() __FILE__ "(" TO_STRING_EX(__LINE__) ")[" __TIMESTAMP__ "]"

//----------------------------------------
//C++11仕様対応
//参考：https://sites.google.com/site/cpprefjp/implementation-status
//参考(VC++)：http://msdn.microsoft.com/ja-jp/library/hh567368.aspx
//            ※VC++2010以降、C++11仕様を部分実装
//参考(GCC)：http://gcc.gnu.org/projects/cxx0x.html
//           ※GCC 4.3 C++0x Status
//           　GCC 4.4 C++0x Status
//           　GCC 4.5 C++0x Status
//           　GCC 4.6 C++0x Status
//           　GCC 4.7 C++11 Status
//           　GCC 4.8 C++11 Status

//【C++11仕様】nullptr
#ifdef IS_VC
	#if _MSC_VER >= 1600//VC++10.0(2010)以降
		#define HAS_NULLPTR
	#else//_MSC_VER
		//static const void* nullptr = 0;
		#define nullptr 0
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 6)
		#define HAS_NULLPTR
	#else//HAS_CPP11
		//static const void* nullptr = 0;
		#define nullptr 0
	#endif//HAS_CPP11
#endif//IS_GCC

//【C++11仕様】override指定子
#ifdef IS_VC
	#if _MSC_VER >= 1400//VC++8.0(2005)以降
		#define HAS_OVERRIDE
	#else//_MSC_VER
		#define override//ダミー
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 7)
		#define HAS_OVERRIDE
	#else//HAS_CPP11
		#define override//ダミー
	#endif//HAS_CPP11
#endif//IS_GCC

//【C++11仕様】final指定子
#ifdef IS_VC
	#if _MSC_VER >= 1700//VC++11.0(2012)以降
		#define HAS_FINAL
	#else//_MSC_VER
		#define final//ダミー
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 7)
		#define HAS_FINAL
	#else//HAS_CPP11
		#define final//ダミー
	#endif//HAS_CPP11
#endif//IS_GCC

//【C++11仕様】constexpr修飾子
#ifdef IS_VC
	#if _MSC_VER > 1800//VC++12.0(2013)以後（暫定）
		#define HAS_CONSTEXPR
	#else//_MSC_VER
		#define constexpr const
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 6)
		#define HAS_CONSTEXPR
	#else//HAS_CPP11
		#define constexpr const
	#endif//HAS_CPP11
#endif//IS_GCC

//【C++11仕様】ユーザー定義リテラル
#ifdef IS_VC
	#if _MSC_VER > 1800//VC++12.0(2013)以後（暫定）
		#define HAS_USER_DEFINED_LITERAL
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 7)
		#define HAS_USER_DEFINED_LITERAL
	#endif//HAS_CPP11
#endif//IS_GCC

//【C++11仕様】static_assert
#ifdef IS_VC
	#if _MSC_VER >= 1600//VC++10.0(2010)以後
		#define HAS_STATIC_ASSERT
	#else//_MSC_VER
		#define STATIC_ASSERT(expr, msg) typedef char __STATIC_ASSERT_TYPE[(expr) ? 1 : -1]
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 3)
		#define HAS_STATIC_ASSERT
	#else//HAS_CPP11
		#define STATIC_ASSERT(expr, msg) typedef char __STATIC_ASSERT_TYPE[(expr) ? 1 : -1]
	#endif//HAS_CPP11
#endif//IS_GCC

//【C++11仕様】thread_local：スレッドローカルストレージ（TLS）修飾子
#ifdef IS_VC
	#if _MSC_VER > 1800//VC++12.0(2013)以後（暫定）
		#define HAS_THREAD_LOCAL
	#else//_MSC_VER
		#define thread_local __declspec(thread)
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 8)
		#define HAS_THREAD_LOCAL
	#else//HAS_CPP11
		#define thread_local __thread
	#endif//HAS_CPP11
#endif//IS_GCC

//【C++11仕様】alignas：アラインメント修飾子
//【注意】修飾子の指定位置がコンパイラによって異なる
//        ＜変数宣言＞
//        ・C++11 ... alignas(32) float pos[4];
//        ・VC++  ... __declspec(align(16)) float pos[4];
//        ・GCC   ... float pos[4] __attribute((aligned(16));
//        ＜型宣言＞
//        ・C++11 ... struct alignas(32) AVECT{ float pos[4]; };
//        ・VC++  ... __declspec(align(32)) struct vector{ float pos[4]; };
//                    struct __declspec(align(32)) vector{ float pos[4]; };
//        ・GCC   ... struct vector{ float pos[4]; } __attribute((aligned(32));
//                    struct __attribute((aligned(32)) vector{ float pos[4]; };
#ifdef IS_WIN
	#if _MSC_VER > 1800//VC++12.0(2013)以後（暫定）
		#define HAS_ALIGNAS
	#else//_MSC_VER
		#define alignas(n) __declspec(align(n))
	#endif//_MSC_VER
#endif//IS_WIN
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 8)
		#define HAS_ALIGNAS
	#else//HAS_CPP11
		#define alignas(n) __attribute__((aligned(n)))
	#endif//HAS_CPP11
#endif//IS_GCC

//【C++11仕様】alignof：アラインメント取得関数
#ifdef IS_WIN
	#if _MSC_VER > 1800//VC++12.0(2013)以後（暫定）
		#define HAS_ALIGNOF
	#else//_MSC_VER
		#define alignof(T) __alignof(T)
	#endif//_MSC_VER
#endif//IS_WIN
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 5)
		#define HAS_ALIGNOF
	#else//HAS_CPP11
		#define alignof(T) __alignof__(T)
	#endif//HAS_CPP11
#endif//IS_GCC

//アラインメント指定付きメモリ確保関数
//※VC++仕様に合わせて共通化
#ifdef IS_GCC
#include <stdlib.h>//posix_memalign()用
#include <memory.h>//free()用
inline void* _aligned_malloc(size_t size, size_t alignment)
{
	void *p;
	int ret = posix_memalign(&p, alignment, size);
	return (ret == 0) ? p : 0;
}
#define _aligned_free(p) free(p)
#endif//IS_GCC
#ifdef IS_VC
#include <memory.h>//_aligned_malloc(), _aligned_free()用
//void* _aligned_malloc(size_t size, size_t alignment);
//void _aligned_free(void* p);
#endif//IS_VC

//--------------------------------------------------------------------------------
//コンパイラ＆プラットフォーム判定に基づく処理テスト
//--------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//std::size_t用

//【C++11仕様】nullptrテスト
void* nullptr_var = nullptr;

//【C++11仕様】overrideテスト
struct base
{
	virtual void func()
	{
		printf("This is virtual func.\n");
	}
};
struct derived : public base
{
	void func() override
	{
		printf("This is override func.\n");
	}
};
derived override_func_var;

//【C++11仕様】constexprテスト
constexpr int constexpr_calc(int a, int b){ return a + b; }
constexpr int constexpr_var = constexpr_calc(1, 2) + 3;

//【C++11仕様】ユーザー定義リテラルテスト
#ifdef HAS_USER_DEFINED_LITERAL
constexpr int operator "" _len(const char* str, const std::size_t len)
{
	return len;
}
const std::size_t user_defined_literal_var = "1234567890"_len;
#endif//HAS_USER_DEFINED_LITERAL

//【C++11仕様】TLS変数宣言テスト
thread_local int m_var_tls = 123;

//【C++11仕様】アライメント指定テスト
struct alignas(16) data_t
{
	int var[8];
};

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//コンパイラー確認テスト
	printf("Compiler: name=\"%s\", Ver=[%d(0x%08x).%d(0x%08x)]\n", COMPILER_NAME, COMPILER_VER, COMPILER_VER, COMPILER_MINOR, COMPILER_MINOR);
#ifdef IS_VC
	printf("    This compiler is \"Visual C++\"\n");
#endif//IS_VC
#ifdef IS_GCC
	printf("    This compiler is \"GCC\"\n");
#endif//IS_GCC

	//C++言語確認テスト
	printf("\n");
	printf("Compiler-language: %s (C++ Ver.=%d)\n", COMPILER_LANGUAGE, CPP_VER);
#ifdef IS_CPP
	printf("    C++ is available.\n");
#endif//IS_CPP
#ifdef HAS_CPP98
	printf("        C++ is implemented C++98.\n");
#endif//HAS_CPP98
#ifdef HAS_CPP03
	printf("        C++ is implemented C++03.\n");
#endif//HAS_CPP03
#ifdef HAS_CPP11
	printf("        C++ is implemented C++11.\n");
#endif//HAS_CPP11

	//プラットフォーム確認テスト
	printf("\n");
	printf("Plataform: \"%s\"(%s %dbits, %s-endian), Ver=[%d(0x%08x).%d(0x%08x)]\n", PLATFORM_NAME, PLATFORM_ARCHITECTURE, PLATFORM_ARCHITECTURE_BITS, ENDIAN, PLATFORM_VER, PLATFORM_VER, PLATFORM_MINOR, PLATFORM_MINOR);
#ifdef IS_WIN
	printf("    Target plarform is \"Windows\"\n");
#endif//IS_WIN
#ifdef IS_LINUX
	printf("    Target plarform is \"Linux\"\n");
#endif//IS_LINUX
#ifdef IS_CYGWIN
	printf("    Target plarform is \"Cygwin\"\n");
#endif//IS_CYGWIN

	//定義済みマクロ表示テスト
	struct test
	{
		static void func()
		{
			printf("\n");
			printf("__FILE__=\"%s\"\n", __FILE__);
			printf("__LINE__=%d\n", __LINE__);
			printf("__FUNCTION__=\"%s\"\n", __FUNCTION__);
			printf("__PRETTY_FUNCTION__=\"%s\"\n", __PRETTY_FUNCTION__);
			printf("__FUNCSIG__=\"%s\"\n", __FUNCSIG__);
			printf("__func__=\"%s\"\n", __func__);
			printf("__FUNCDNAME__=\"%s\"\n", __FUNCDNAME__);
			printf("__DATE__=\"%s\"\n", __DATE__);
			printf("__TIME__=\"%s\"\n", __TIME__);
			printf("__TIMESTAMP__=\"%s\"\n", __TIMESTAMP__);
			printf("\n");
			printf("GET_FUNC_NAME()=\"%s\"\n", GET_FUNC_NAME());
			printf("GET_FILE_LINE()=\"%s\"\n", GET_FILE_LINE());
			printf("GET_FILE_LINE_TIME()=\"%s\"\n", GET_FILE_LINE_TIME());
		}
	};
	test::func();

	//【C++11仕様】nullptrテスト
	printf("\n");
	printf("nullptr_var=%p\n", nullptr_var);
#ifdef HAS_NULLPTR
	printf("    'nullptr' is featured.\n");
#endif//HAS_NULLPTR

	//【C++11仕様】overrideテスト
	printf("\n");
	override_func_var.func();
#ifdef HAS_OVERRIDE
	printf("    'override' is featured.\n");
#endif//HAS_OVERRIDE

	//【C++11仕様】constexprテスト
	printf("\n");
	printf("constexpr_var=%d\n", constexpr_var);
	printf("constexpr_calc(1, 2)=%d\n", constexpr_calc(1, 2));
#ifdef HAS_CONSTEXPR
	printf("    'constexpr' is featured.\n");
#endif//HAS_CONSTEXPR

	//【C++11仕様】ユーザー定義リテラルテスト
#ifdef HAS_USER_DEFINED_LITERAL
	printf("\n");
	printf("user_defined_literal_var=%d\n", user_defined_literal_var);
#endif//HAS_USER_DEFINED_LITERAL
#ifdef HAS_USER_DEFINED_LITERAL
	printf("    'operator \"\"'(user defined literal) is featured.\n");
#endif//HAS_USER_DEFINED_LITERAL

	//【C++11仕様】TLSテスト
	printf("\n");
	printf("TLS Variable=%d\n", m_var_tls);
#ifdef HAS_THREAD_LOCAL
	printf("    'thread_local' is featured.\n");
#endif//HAS_THREAD_LOCAL

	//【C++11仕様】アラインメント指定／取得／指定付メモリ確保と解放テスト
	printf("\n");
	printf("sizeof(data_t)=%d\n", sizeof(data_t));
	printf("alignof(data_t)=%d\n", alignof(data_t));//アラインメント取得テスト
	data_t* p = reinterpret_cast<data_t*>(_aligned_malloc(sizeof(data_t), alignof(data_t)));
	printf("_aligned_malloc(sizeof(data_t), alignof(data_t))=%p\n", p);
	_aligned_free(p);
	printf("_aligned_free(p)\n");
#ifdef HAS_ALIGNAS
	printf("    'alignas' is featured.\n");
#endif//HAS_ALIGNAS
#ifdef HAS_ALIGNOF
	printf("    'alignof' is featured.\n");
#endif//HAS_ALIGNOF

	return EXIT_SUCCESS;
}

// End of file
