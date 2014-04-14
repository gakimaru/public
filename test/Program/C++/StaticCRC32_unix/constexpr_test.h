//C++11用の constexpr / ユーザー定義リテラルを使ったコンパイル時CRC計算およびSSE4.2を使用したCRC計算テスト

//--------------------
#include "constexpr.h"

//--------------------
//コンパイラスイッチ用マクロ
#define ENABLE_MAIN//メイン関数を有効にする時はこのマクロを有効にする

//#define USE_MAKE_STATIC_TABLE//CRC多項式テーブル作成を使用する時はこのマクロを有効にする
#define ENABLE_CONSTEXPR_TEST//constexprテストを有効にする時はこのマクロを有効にする
#define ENABLE_USER_DEFINED_LITERALS_TEST//ユーザー定義リテラルテストを有効にする時はこのマクロを有効にする
#define ENABLE_RUNTIME_TEST//ランタイム時CRC計算テストを有効にする時はこのマクロを有効にする
//#define ENABLE_MORE_TEST//追加テストを有効にする時はこのマクロを有効にする
//#define ENABLE_PERFORMANCE_TEST//パフォーマンステストを有効にする時はこのマクロを有効にする

#define USE_STATIC_ASSERT//static_assertを使用する時はこのマクロを有効にする

#define CONST_TO_CONST//CONSTマクロをconstにする時はこのマクロを有効にする
//#define NOCONST_TO_CONST//NOCONSTマクロをconstにする時はこのマクロを有効にする

//※「ランタイム時CRC計算テスト」と「追加テスト」、「パフォーマンステスト」を無効化すると、
//　constexprとユーザー定義リテラルのにより、文字列リテラル "1234567890" が
//　コンパイル時に消滅して、CRCのリテラル値で扱われることが、アセンブラコードから確認できる。
//　なお、const型で計算結果を受けないと、コンパイル時に計算されず、ランタイム時の処理になってしまうので注意。

//--------------------
//コンパイラスイッチ調整
#ifndef ENABLE_MAKE_STATIC_TABLE
#ifdef USE_MAKE_STATIC_TABLE
#undef USE_MAKE_STATIC_TABLE//※CRC多項式テーブルを作成が無効なら、呼び出せない
#endif//USE_MAKE_STATIC_TABLE
#endif//ENABLE_MAKE_STATIC_TABLE

#ifndef ENABLE_USER_DEFINED_LITERALS
#ifdef ENABLE_USER_DEFINED_LITERALS_TEST
#undef ENABLE_USER_DEFINED_LITERALS_TEST//※ユーザー定義リテラルが無効なら、テストできない
#endif//ENABLE_USER_DEFINED_LITERALS_TEST
#endif//ENABLE_USER_DEFINED_LITERALS

#ifndef ENABLE_RUNTIME_FUNC
#ifdef ENABLE_RUNTIME_TEST
#undef ENABLE_RUNTIME_TEST//※ランタイム関数が無効なら、テストできない
#endif//ENABLE_RUNTIME_TEST
#ifdef ENABLE_PERFORMANCE_TEST
#undef ENABLE_PERFORMANCE_TEST//※ランタイム関数が無効なら、パフォーマンステストできない
#endif//ENABLE_PERFORMANCE_TEST
#endif//ENABLE_RUNTIME_FUNC

//--------------------
//CONSTマクロ
#ifdef CONST_TO_CONST
#define CONST const//※CONSTをconstとして扱う
#else//CONST_TO_CONST
#define CONST//※CONSTを非constとして扱う
#endif//CONST_TO_CONST
//NOCONSTマクロ
#ifdef NOCONST_TO_CONST
#define NOCONST const
#else//NOCONST_TO_CONST
#define NOCONST
#endif//NOCONST_TO_CONST

// End of file
