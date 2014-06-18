#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

//定義済みマクロ表示
int printDefinedMacro(const int argc, const char* argv[])
{
	printf("\n- printDefinedMacro -\n\n");
	printf("\n【ANSI C準拠の定義済みマクロ】\n");
	printf("__FILE__      = \"%s\"\n", __FILE__);
	printf("__LINE__      = %d\n", __LINE__);
	printf("__DATE__      = \"%s\"\n", __DATE__);
	printf("__TIME__      = \"%s\"\n", __TIME__);
	printf("__TIMESTAMP__ = \"%s\"\n", __TIMESTAMP__);
	printf("\n【Microsoft 固有の定義済みマクロ】\n");
	printf("__COUNTER__        = %d\n", __COUNTER__);	//←カウントアップを確認するために３回使用
	printf("__COUNTER__        = %d\n", __COUNTER__);	//←
	printf("__COUNTER__        = %d\n", __COUNTER__);	//←
	printf("__FUNCDNAME__      = \"%s\"\n", __FUNCDNAME__);
	printf("__FUNCSIG__        = \"%s\"\n", __FUNCSIG__);
	printf("__FUNCTION__       = \"%s\"\n", __FUNCTION__);
	printf("_INTEGRAL_MAX_BITS = %d\n", _INTEGRAL_MAX_BITS);
	printf("_M_IX86_FP         = %d\n", _M_IX86_FP);
	printf("_MSC_FULL_VER      = %d\n", _MSC_FULL_VER);
	printf("_MSC_VER           = %d\n", _MSC_VER);
	return 0;
}
//関数オーバーロード用のダミー関数（__FUNCDNAME__テスト用）
void printDefinedMacro()
{}

//文字列化マクロ
#define TO_STRING(x) #x

//マクロ展開付き文字列化マクロ
#define TO_STRING_EX(x) TO_STRING(x)

//Visual C++ 固有の定義済みマクロ「__FUNCSIG__」を標準化するために、
//「__FUNC__」として再定義（他のビルド環境でも __FUNC__ を用いればソースコードを共通利用できるようにする）
#define __FUNC__ __FUNCSIG__

//ファイル名取得関数
const char* getFileName(const char* path)
{
	const char* p = path + strlen(path) - 1;
	while (p > path)
	{
		if (*p == '\\' || *p == '/')
			return p + 1;
		--p;
	}
	return path;
}

//定義済みマクロを活用したアサーション
#define MY_ASSERT(expr, msg) \
if (!(expr)) \
{ \
	fprintf(stderr, "------------------------------------------------------------\n"); \
	fprintf(stderr, "Assertion failed!\n"); \
	fprintf(stderr, "%s(%d): %s\n", getFileName(__FILE__), __LINE__, __FUNC__); \
	fprintf(stderr, "%s\n", #expr);	/* ←exprを # で文字列化 */ \
	fprintf(stderr, "%s\n", msg); \
	fprintf(stderr, "------------------------------------------------------------\n"); \
	assert(expr);	/* ←処理比較とabortのために、標準で用意されているassert()を実行 */ \
}

//アサーションテスト
int testAssert(const int argc, const char* argv[])
{
	printf("\n- testAssert -\n\n");
	struct STRUCT
	{
		char memberA;
		short memberB;
		int memberC;
		char memberD;
	};
	MY_ASSERT(sizeof(STRUCT) == 8, "STRUCT構造体のサイズが8バイトではありません！");
	return 0;
}

//ファイル名取得関数
const char* getFileName2(const char* path, const size_t path_len)
{
	const char* p = path + path_len - 1;
	while (p > path)
	{
		if (*p == '\\' || *p == '/')
			return p + 1;
		--p;
	}
	return path;
}

//処理行情報作成マクロ
//#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" #__LINE__ "):" __FUNC__, strlen(__FILE__))//コンパイルエラー
//#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" TO_STRING(__LINE__) "):" __FUNC__ TO_STRING( [テスト!]) TO_STRING(123), strlen(__FILE__))
#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" TO_STRING_EX(__LINE__) "):" __FUNC__ TO_STRING( [テスト!]) TO_STRING(123), strlen(__FILE__))

//文字列連結テスト
int testConcatenateStr(const int argc, const char* argv[])
{
	printf("\n- testConcatenateStr -\n\n");
	const char* func_line_info = MAKE_FUNC_LINE_INFO();
	printf("MAKE_FUNC_LINE_INFO() = \"%s\"\n", func_line_info);
	return 0;
}

//幾つかの関数
//void functionForTokenConcatenateTestAAA01(){ printf("TEST: AAA-01\n"); }
//void functionForTokenConcatenateTestAAA02(){ printf("TEST: AAA-02\n"); }
//void functionForTokenConcatenateTestBBB01(){ printf("TEST: BBB-01\n"); }
//void functionForTokenConcatenateTestBBB02(){ printf("TEST: BBB-02\n"); }

//トークン連結演算子を使った関数定義マクロ
#define MAKE_TEST(ID, NO) \
	void functionForTokenConcatenateTest ## ID ## NO() \
{ \
	printf("TEST: " #ID "-" #NO "\n"); \
}

//幾つかの関数
MAKE_TEST(AAA, 01)
MAKE_TEST(AAA, 02)
MAKE_TEST(BBB, 01)
MAKE_TEST(BBB, 02)

//トークン連結演算子を使った関数呼び出しマクロ
#define TEST(ID, NO) functionForTokenConcatenateTest ## ID ## NO ()

//トークン連結テスト
int testConcatenateToken(const int argc, const char* argv[])
{
	printf("\n- testConcatenateToken -\n\n");
	TEST(AAA, 01);
	TEST(AAA, 02);
	TEST(BBB, 01);
	TEST(BBB, 02);
	return 0;
}

//最大値判定マクロ
#define MAX(a, b) (a > b ? a : b)

#define ONCE once
#pragma ONCE

int testDengerMacro(const int argc, const char* argv[])
{
	printf("\n- testDengerMacro -\n\n");
	int x = MAX(1, 2);     //結果：x=2
	int y = MAX(4, 3);     //結果：y=3
	int z = MAX(++x, ++y); //結果：z=5（期待値）⇒ z=6（実際）
	printf("x=%d, y=%d, z=%d\n", x, y, z);
	return 0;
}

//テスト
int main(const int argc, const char* argv[])
{
	printDefinedMacro(argc, argv);

	testConcatenateStr(argc, argv);

	testConcatenateToken(argc, argv);

	testDengerMacro(argc, argv);

	testAssert(argc, argv);

	return EXIT_SUCCESS;
}

// End of file
