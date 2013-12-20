#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//テンプレート関数がコンパイル時にリテラル値に展開される事をテスト（最適化レベルに依存）
//※実行時に、[デバッグ]→[ウインドウ]→[逆アセンブル]で、アセンブラのコードを確認する。
template<typename T> T max(T n1, T n2){ return n1 >= n2 ? n1 : n2; }
template<typename T> T max(T n1, T n2, T n3){ return n1 >= n2 ? n1 : n2 >= n3 ? n2 : n3; }
template<typename T> T max(T n1, T n2, T n3, T n4){ return n1 >= n2 ? n1 : n2 >= n3 ? n2 : n3 >= n4 ? n3 : n4; }
void test_func1()
{
	std::cout << "max(1, 2)       = " << max(1, 2) << std::endl;
	std::cout << "max(1, 2, 3)    = " << max(1, 2, 3) << std::endl;
	std::cout << "max(1, 2, 3, 4) = " << max(1, 2, 3, 4) << std::endl;
}

//同じ事をマクロで実装した場合
#define max2(n1, n2) (n1 >= n2 ? n1 : n2)
#define max3(n1, n2, n3) (n1 >= n2 ? n1 : n2 >= n3 ? n2 : n3)
#define max4(n1, n2, n3, n4) (n1 >= n2 ? n1 : n2 >= n3 ? n2 : n3 >= n4 ? n3 : n4)
void test_func2()

{
	std::cout << "max2(1, 2)       = " << max2(1, 2) << std::endl;
	std::cout << "max3(1, 2, 3)    = " << max3(1, 2, 3) << std::endl;
	std::cout << "max4(1, 2, 3, 4) = " << max4(1, 2, 3, 4) << std::endl;
}

//【応用】幾つかのクラスの中で最大のサイズを予め調べておく
//※例えば、テンプレートメソッドで生成する複数種のオブジェクトの為に、固有のバッファを用意しておく場合など。バッファサイズを自動計算する為に使用。
//※純粋なリテラル値を扱った定数との違いもチェックしておく
//※結論（Visual C++ 2013）：テンプレート関数によるコンパイル時のリテラル値生成は成功するが、必ずデータ領域に結果が格納され、コード上でのリテラル値展開はされない。それが必要なら#defineを使うか、C++11のconstexprの実装を待つ必要がある。
class CBase
{
public:
	int x;
};
class CA : public CBase
{
public:
	int y;
};
class CB : public CBase
{
public:
	int z[10];
};
class CC : public CBase
{
public:
	int a;
	int b;
	int c;
};
#define MAX_CLASS_SIZE1 max(sizeof(CA), sizeof(CB), sizeof(CC))//#define
#define MAX_CLASS_SIZE1x max3(sizeof(CA), sizeof(CB), sizeof(CC))//#define
#define LITERAL1 1//#define
const std::size_t MAX_CLASS_SIZE2 = max(sizeof(CA), sizeof(CB), sizeof(CC));//グローバル定数
const std::size_t MAX_CLASS_SIZE2x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//グローバル定数
const std::size_t LITERAL2 = 2;
static const std::size_t MAX_CLASS_SIZE3 = max(sizeof(CA), sizeof(CB), sizeof(CC));//staticグローバル定数
static const std::size_t MAX_CLASS_SIZE3x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//staticグローバル定数
static const std::size_t LITERAL3 = 3;
namespace NS
{
	const std::size_t MAX_CLASS_SIZE4 = max(sizeof(CA), sizeof(CB), sizeof(CC));//ネームスペース定数
	const std::size_t MAX_CLASS_SIZE4x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//ネームスペース定数
	const std::size_t LITERAL4 = 4;
	static const std::size_t MAX_CLASS_SIZE5 = max(sizeof(CA), sizeof(CB), sizeof(CC));//staticネームスペース定数
	static const std::size_t MAX_CLASS_SIZE5x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//staticネームスペース定数
	static const std::size_t LITERAL5 = 5;

};
void test_func3()
{
	const std::size_t MAX_CLASS_SIZE6 = max(sizeof(CA), sizeof(CB), sizeof(CC));//ローカル定数
	const std::size_t MAX_CLASS_SIZE6x = max(sizeof(CA), sizeof(CB), sizeof(CC));//ローカル定数
	const std::size_t LITERAL6 = 6;
	static const std::size_t MAX_CLASS_SIZE7 = max(sizeof(CA), sizeof(CB), sizeof(CC));//staticローカル定数
	static const std::size_t MAX_CLASS_SIZE7x = max(sizeof(CA), sizeof(CB), sizeof(CC));//staticローカル定数
	static const std::size_t LITERAL7 = 7;

	std::cout << "max(sizeof(CA), sizeof(CB), sizeof(CC))" << std::endl;
	std::cout << "  MAX_CLASS_SIZE1 = " << MAX_CLASS_SIZE1 << std::endl;
	std::cout << "  MAX_CLASS_SIZE2 = " << MAX_CLASS_SIZE2 << std::endl;
	std::cout << "  MAX_CLASS_SIZE3 = " << MAX_CLASS_SIZE3 << std::endl;
	std::cout << "  MAX_CLASS_SIZE4 = " << NS::MAX_CLASS_SIZE4 << std::endl;
	std::cout << "  MAX_CLASS_SIZE5 = " << NS::MAX_CLASS_SIZE5 << std::endl;
	std::cout << "  MAX_CLASS_SIZE6 = " << MAX_CLASS_SIZE6 << std::endl;
	std::cout << "  MAX_CLASS_SIZE7 = " << MAX_CLASS_SIZE7 << std::endl;
	std::cout << "max3(sizeof(CA), sizeof(CB), sizeof(CC))" << std::endl;
	std::cout << "  MAX_CLASS_SIZE1x = " << MAX_CLASS_SIZE1x << std::endl;
	std::cout << "  MAX_CLASS_SIZE2x = " << MAX_CLASS_SIZE2x << std::endl;
	std::cout << "  MAX_CLASS_SIZE3x = " << MAX_CLASS_SIZE3x << std::endl;
	std::cout << "  MAX_CLASS_SIZE4x = " << NS::MAX_CLASS_SIZE4x << std::endl;
	std::cout << "  MAX_CLASS_SIZE5x = " << NS::MAX_CLASS_SIZE5x << std::endl;
	std::cout << "  MAX_CLASS_SIZE6x = " << MAX_CLASS_SIZE6x << std::endl;
	std::cout << "  MAX_CLASS_SIZE7x = " << MAX_CLASS_SIZE7x << std::endl;
	std::cout << "LITERAL" << std::endl;
	std::cout << "  LITERAL1 = " << LITERAL1 << std::endl;
	std::cout << "  LITERAL2 = " << LITERAL2 << std::endl;
	std::cout << "  LITERAL3 = " << LITERAL3 << std::endl;
	std::cout << "  LITERAL4 = " << NS::LITERAL4 << std::endl;
	std::cout << "  LITERAL5 = " << NS::LITERAL5 << std::endl;
	std::cout << "  LITERAL6 = " << LITERAL6 << std::endl;
	std::cout << "  LITERAL7 = " << LITERAL7 << std::endl;
}

//メイン
int main(const int argc, const char* argv[])
{
	test_func1();
	test_func2();
	test_func3();
	return EXIT_SUCCESS;
}

// End of file
