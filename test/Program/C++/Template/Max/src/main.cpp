#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <varargs.h>

#include <vector>
#include <algorithm>

//テンプレート関数がコンパイル時にリテラル値に展開される事をテスト（最適化レベルに依存）
//※実行時に、[デバッグ]→[ウインドウ]→[逆アセンブル]で、アセンブラのコードを確認する。
template<typename T> inline T max(T n1, T n2){ return n1 > n2 ? n1 : n2; }
template<typename T> inline T max(T n1, T n2, T n3){ return n1 > n2 ? n1 : max(n2, n3); }
template<typename T> inline T max(T n1, T n2, T n3, T n4){ return n1 > n2 ? n1 : max(n2, n3, n4); }
template<typename T> inline T max(T n1, T n2, T n3, T n4, T n5){ return n1 > n2 ? n1 : max(n2, n3, n4, n5); }

void test_func1()
{
	const int v1 = max(1, 2);
	const int v2 = max(3, 4, 5);
	const int v3 = max(6, 7, 8, 9);
	const int v4 = max(10, 11, 12, 13, 14);
	printf("{%d, %d, %d, %d}\n", v1, v2, v3, v4);

	std::cout << "max(1, 2)          = " << max(1, 2) << std::endl;
	std::cout << "max(1, 2, 3)       = " << max(1, 2, 3) << std::endl;
	std::cout << "max(1, 2, 3, 4)    = " << max(1, 2, 3, 4) << std::endl;
	std::cout << "max(1, 2, 3, 4, 5) = " << max(1, 2, 3, 4, 5) << std::endl;
}

//可変長テンプレート引数版のmax()
//値が二つの max()
template<typename T1, typename T2>
inline T1 vmax(T1 n1, T2 n2){ return n1 > n2 ? n1 : n2; }
//値が三つ以上の max() : 再帰処理（注：テンプレートの特殊化ではなく、関数のオーバーロードで再起を終結させている）
template<typename T1, typename T2, typename T3, typename... Tx>
inline T1 vmax(T1 n1, T2 n2, T3 n3, Tx... nx){ return vmax(vmax(n1, n2), n3, nx...); } //nxが空になったら値が二つの方が呼ばれる

//可変長テンプレート引数テスト
template<class First>
inline void func()
{
	std::cout << typeid(First).name() << std::endl;
}
template<class First, class Second, class... Rest>
inline void func()
{
	func<First>();
	func<Second, Rest...>();
}

void test_func1v()
{
	const int v1 = vmax(1, 2);
	const int v2 = vmax(3, 4, 5);
	const int v3 = vmax(6, 7, 8, 9);
	const int v4 = vmax(10, 11, 12, 13, 14);
	const int v5 = vmax(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
	const int v6 = vmax(6, 5, 4, 3, 2, 1);
	const int v7 = vmax(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	printf("{%d, %d, %d, %d, %d, %d, %d}\n", v1, v2, v3, v4, v5, v6, v7);

	func<int>();
	func<int, short>();
	func<int, short, char>();
}

//同じ事をマクロで実装した場合
#define max2(n1, n2)             (n1 > n2 ? n1 : n2)
#define max3(n1, n2, n3)         (n1 > n2 ? n1 : max2(n2, n3))
#define max4(n1, n2, n3, n4)     (n1 > n2 ? n1 : max3(n2, n3, n4))
#define max5(n1, n2, n3, n4, n5) (n1 > n2 ? n1 : max4(n2, n3, n4, 5))
void test_func2()
{
	const int v1 = max2(1, 2);
	const int v2 = max3(3, 4, 5);
	const int v3 = max4(6, 7, 8, 9);
	const int v4 = max5(10, 11, 12, 13, 14);
	printf("{%d, %d, %d, %d}\n", v1, v2, v3, v4);

	std::cout << "max2(1, 2)          = " << max2(1, 2) << std::endl;
	std::cout << "max3(1, 2, 3)       = " << max3(1, 2, 3) << std::endl;
	std::cout << "max4(1, 2, 3, 4)    = " << max4(1, 2, 3, 4) << std::endl;
	std::cout << "max4(1, 2, 3, 4, 5) = " << max5(1, 2, 3, 4, 5) << std::endl;
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

//定数
static const int sc1 = max(1, 2, 3, 4, 5);  //OK
static const int sc2 = max5(1, 2, 3, 4, 5); //OK
const int c1 = max(1, 2, 3, 4, 5);          //OK
const int c2 = max5(1, 2, 3, 4, 5);         //OK

//クラス内の定数／初期値
class CClass
{
public:
	//	static const int sc1 = max(1, 2, 3, 4, 5);  //NG:コンパイルエラー
	static const int sc2 = max5(1, 2, 3, 4, 5); //OK
	const int c1 = max(1, 2, 3, 4, 5);          //OK
	const int c2 = max5(1, 2, 3, 4, 5);         //OK
	CClass() :
		v1(max(1, 2, 3, 4, 5)),                 //OK
		v2(max5(1, 2, 3, 4, 5))                 //OK
	{}
	int v1;
	int v2;
};

//列挙
enum
{
	//	e1 = max(1, 2, 3, 4, 5),  //NG:コンパイルエラー
	e2 = max5(1, 2, 3, 4, 5), //OK
};

//べき乗（テンプレートクラス版）※指数に負の数を指定するとコンパイルエラー
//#include <type_traits>//C++11 std::conditional, std:integral_constant用
template<typename T, T N, int E>
struct static_pow{
	static const T value = N * static_pow<T, N, E - 1>::value;
};
//べき乗：再帰終点のための特殊化
template<typename T, int N>
struct static_pow<T, N, 0>{
	static const T value = 1;
};


//べき乗（テンプレート関数版）※指数に負の数を指定するとコンパイルエラー
template<typename T, int E>
T power(const T n){ return n * power<T, E - 1>(n); }
//べき乗：再帰終点のための特殊化
//template<typename T>
//T power<T, 0>(const T n){ return static_cast<T>(1); }
//※テンプレート関数では部分特殊化を使おうとするとコンパイルエラーとなる
//　そのため、下記のように各型で展開した特殊化関数を用意する必要がある。
template<>
char power<char, 0>(const char n){ return 1; }
template<>
unsigned char power<unsigned char, 0>(const unsigned char n){ return 1; }
template<>
short power<short, 0>(const short n){ return 1; }
template<>
unsigned short power<unsigned short, 0>(const unsigned short n){ return 1; }
template<>
int power<int, 0>(const int n){ return 1; }
template<>
unsigned int power<unsigned int, 0>(const unsigned int n){ return 1; }
template<>
long power<long, 0>(const long n){ return 1; }
template<>
unsigned long power<unsigned long, 0>(const unsigned long n){ return 1; }
template<>
long long power<long long, 0>(const long long n){ return 1; }
template<>
unsigned long long power<unsigned long long, 0>(const unsigned long long n){ return 1; }
template<>
float power<float, 0>(const float n){ return 1.f; }
template<>
double power<double, 0>(const double n){ return 1.; }
//負の数の指数用のべき乗（テンプレート関数版）※指数に正の数を指定するとコンパイルエラー
template<typename T, int E>
T minus_power(const T n){ return static_cast<T>(1) / power<T, -E>(n); }

//座標型
template<typename T>
struct POINT
{
	T x;
	T y;
	//通常コンストラクタ
	POINT(T x_, T y_) :
		x(x_),
		y(y_)
	{}
	//コピーテンプレートコンストラクタ
	template<typename U>
	POINT(POINT<U>& o) :
		x(static_cast<T>(o.x)),
		y(static_cast<T>(o.y))
	{}
	//コピーテンプレートオペレータ
	template<typename U>
	POINT<T>& operator=(POINT<U>& o)
	{
		x = static_cast<T>(o.x);
		y = static_cast<T>(o.y);
		return *this;
	}
};

//処理最適化説明用クラス：最適化前
void func_old(int data1[], int n1, int data2[], int n2)
{
	printf("<BEFORE>\n");
	printf("data1=");
	int sum1 = 0;
	for (int i = 0; i < n1; ++i)
	{
		sum1 += data1[i];
		printf(" %d", data1[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum1, static_cast<float>(sum1) / static_cast<float>(n1));
	printf("data2=");
	int sum2 = 0;
	for (int i = 0; i < n2; ++i)
	{
		sum2 += data2[i];
		printf(" %d", data2[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum2, static_cast<float>(sum2) / static_cast<float>(n2));
	for (int i = 0; i < n1; ++i)
	{
		if (data1[i] < 10)
			data1[i] = 10;
		else if (data1[i] > 100)
			data1[i] = 100;
	}
	for (int i = 0; i < n2; ++i)
	{
		if (data2[i] < 10)
			data2[i] = 10;
		else if (data2[i] > 100)
			data2[i] = 100;
	}
	printf("<AFTER>\n");
	printf("data1=");
	sum1 = 0;
	for (int i = 0; i < n1; ++i)
	{
		sum1 += data1[i];
		printf(" %d", data1[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum1, static_cast<float>(sum1) / static_cast<float>(n1));
	printf("data2=");
	sum2 = 0;
	for (int i = 0; i < n2; ++i)
	{
		sum2 += data2[i];
		printf(" %d", data2[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum2, static_cast<float>(sum2) / static_cast<float>(n2));
}
//処理最適化説明用クラス：最適化①
int func_new1_round(int data)
{
	if (data < 10)
		data = 10;
	else if (data > 100)
		data = 100;
	return data;
}
void func_new1(int data1[], int n1, int data2[], int n2)
{
	printf("<BEFORE>\n");
	printf("data1=");
	int sum1 = 0;
	for (int i = 0; i < n1; ++i)
	{
		sum1 += data1[i];
		printf(" %d", data1[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum1, static_cast<float>(sum1) / static_cast<float>(n1));
	printf("data2=");
	int sum2 = 0;
	for (int i = 0; i < n2; ++i)
	{
		sum2 += data2[i];
		printf(" %d", data2[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum2, static_cast<float>(sum2) / static_cast<float>(n2));
	for (int i = 0; i < n1; ++i)
	{
		data1[i] = func_new1_round(data1[i]);
	}
	for (int i = 0; i < n2; ++i)
	{
		data2[i] = func_new1_round(data2[i]);
	}
	printf("<AFTER>\n");
	printf("data1=");
	sum1 = 0;
	for (int i = 0; i < n1; ++i)
	{
		sum1 += data1[i];
		printf(" %d", data1[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum1, static_cast<float>(sum1) / static_cast<float>(n1));
	printf("data2=");
	sum2 = 0;
	for (int i = 0; i < n2; ++i)
	{
		sum2 += data2[i];
		printf(" %d", data2[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum2, static_cast<float>(sum2) / static_cast<float>(n2));
}
//処理最適化説明用クラス：最適化②
void func_new2(int data1[], int n1, int data2[], int n2)
{
	struct round{
		static int calc(int data)
		{
			if (data < 10)
				data = 10;
			else if (data > 100)
				data = 100;
			return data;
		}
	};
	printf("<BEFORE>\n");
	printf("data1=");
	int sum1 = 0;
	for (int i = 0; i < n1; ++i)
	{
		sum1 += data1[i];
		printf(" %d", data1[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum1, static_cast<float>(sum1) / static_cast<float>(n1));
	printf("data2=");
	int sum2 = 0;
	for (int i = 0; i < n2; ++i)
	{
		sum2 += data2[i];
		printf(" %d", data2[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum2, static_cast<float>(sum2) / static_cast<float>(n2));
	for (int i = 0; i < n1; ++i)
	{
		data1[i] = round::calc(data1[i]);
	}
	for (int i = 0; i < n2; ++i)
	{
		data2[i] = round::calc(data2[i]);
	}
	printf("<AFTER>\n");
	printf("data1=");
	sum1 = 0;
	for (int i = 0; i < n1; ++i)
	{
		sum1 += data1[i];
		printf(" %d", data1[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum1, static_cast<float>(sum1) / static_cast<float>(n1));
	printf("data2=");
	sum2 = 0;
	for (int i = 0; i < n2; ++i)
	{
		sum2 += data2[i];
		printf(" %d", data2[i]);
	}
	printf(" (sum=%d, avg=%.1f)\n", sum2, static_cast<float>(sum2) / static_cast<float>(n2));
}
//処理最適化説明用クラス：最適化③
template<typename T, class F>
void for_each_array(T* data, int n, F& functor)
{
	for (int i = 0; i < n; ++i, ++data)
	{
		functor(*data);
	}
}
void func_new3(int data1[], int n1, int data2[], int n2)
{
	struct print{
		void all(const char* name, int data[], int n)
		{
			sum = 0;
			printf("%s=", name);
			for_each_array(data, n, *this);
			printf(" (sum=%d, avg=%.1f)\n", sum, static_cast<float>(sum) / static_cast<float>(n));
		}
		int sum;
		void operator()(int data)
		{
			sum += data;
			printf(" %d", data);
		}
	};
	struct round{
		void operator()(int& data)
		{
			if (data < 10)
				data = 10;
			else if (data > 100)
				data = 100;
		}
	};
	print o;
	printf("<BEFORE>\n");
	o.all("data1", data1, n1);
	o.all("data2", data2, n2);
	for_each_array(data1, n1, round());
	for_each_array(data2, n2, round());
	printf("<AFTER>\n");
	o.all("data1", data1, n1);
	o.all("data2", data2, n2);
}
//処理最適化説明用クラス：最適化④
void func_new4(int data1[], int n1, int data2[], int n2)
{
	static int sum;
	struct print{
		void all(const char* name, int data[], int n)
		{
			sum = 0;
			printf("%s=", name);
			std::for_each(data, data + n, *this);
			printf(" (sum=%d, avg=%.1f)\n", sum, static_cast<float>(sum) / static_cast<float>(n));
		}
		void operator()(int data)
		{
			sum += data;
			printf(" %d", data);
		}
	};
	struct round{
		void operator()(int& data)
		{
			if (data < 10)
				data = 10;
			else if (data > 100)
				data = 100;
		}
	};
	print o;
	printf("<BEFORE>\n");
	o.all("data1", data1, n1);
	o.all("data2", data2, n2);
	std::for_each(data1, data1 + n1, round());//STL板
	std::for_each(data2, data2 + n2, round());
	printf("<AFTER>\n");
	o.all("data1", data1, n1);
	o.all("data2", data2, n2);
}
//処理最適化説明用クラス：最適化⑤
void func_new5(int data1[], int n1, int data2[], int n2)
{
	auto lambda_print = [](int& sum, const char* name, int data[], int n) -> void
	{
		sum = 0;
		printf("%s=", name);
		std::for_each(data, data + n, [&sum](int data)
		{
			sum += data;
			printf(" %d", data);
		}
		);
		printf(" (sum=%d, avg=%.1f)\n", sum, static_cast<float>(sum) / static_cast<float>(n));
	};
	auto lambda_round = [](int& data)
	{
		if (data < 10)
			data = 10;
		else if (data > 100)
			data = 100;
	};
	int sum1 = 0;
	int sum2 = 0;
	printf("<BEFORE>\n");
	lambda_print(sum1, "data1", data1, n1);
	lambda_print(sum2, "data2", data2, n2);
	std::for_each(data1, data1 + n1, lambda_round);
	std::for_each(data2, data2 + n2, lambda_round);
	printf("<AFTER>\n");
	lambda_print(sum1, "data1", data1, n1);
	lambda_print(sum2, "data2", data2, n2);
}

template<typename T, std::size_t N>
std::size_t lengthOfAray(T(&var)[N]){ return N; }

void test_func4()
{
	//処理最適化説明用処理
	{
		int data1[] = { 1, 2, 3, 39, 200, 53, 8, 74, 12 };
		int data2[] = { 13, 6, 76, 43, 23, 125, 1 };
		func_old(data1, lengthOfAray(data1), data2, lengthOfAray(data2));
	}
	{
		int data1[] = { 1, 2, 3, 39, 200, 53, 8, 74, 12 };
		int data2[] = { 13, 6, 76, 43, 23, 125, 1 };
		func_new1(data1, lengthOfAray(data1), data2, lengthOfAray(data2));
	}
	{
		int data1[] = { 1, 2, 3, 39, 200, 53, 8, 74, 12 };
		int data2[] = { 13, 6, 76, 43, 23, 125, 1 };
		func_new2(data1, lengthOfAray(data1), data2, lengthOfAray(data2));
	}
	{
		int data1[] = { 1, 2, 3, 39, 200, 53, 8, 74, 12 };
		int data2[] = { 13, 6, 76, 43, 23, 125, 1 };
		func_new3(data1, lengthOfAray(data1), data2, lengthOfAray(data2));
	}
	{
		int data1[] = { 1, 2, 3, 39, 200, 53, 8, 74, 12 };
		int data2[] = { 13, 6, 76, 43, 23, 125, 1 };
		func_new4(data1, lengthOfAray(data1), data2, lengthOfAray(data2));
	}
	{
		int data1[] = { 1, 2, 3, 39, 200, 53, 8, 74, 12 };
		int data2[] = { 13, 6, 76, 43, 23, 125, 1 };
		func_new5(data1, lengthOfAray(data1), data2, lengthOfAray(data2));
	}
	{
		//範囲に基づく for ループ：固定長配列
		int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		printf("data=");
		for (int elem : data)
		{
			printf(" %d", elem);
		}
		printf("\n");
	}
	{
		//範囲に基づく for ループ：STLコンテナ
		std::vector<const char*> data;
		data.push_back("太郎");
		data.push_back("次郎");
		data.push_back("三郎");
		printf("data=");
		for (auto elem: data)
		{
			printf(" %s", elem);
		}
		printf("\n");
	}
	{
		//範囲に基づく for ループ：自作コンテナ
		struct DATA
		{
			char* begin(){ return m_data + 0; }
			char* end(){ return m_data + sizeof(m_data) / sizeof(m_data[0]); }
			char m_data[10];
		};
		DATA data = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } };
		for (auto& elem : data) //begin(), end() がイテレータを返すものならなんにでも使える
			//値を書き戻したければ要素型に & を付けて参照型にする
		{
			elem += 100;
		}
		printf("data=");
		for (auto elem : data)
		{
			printf(" %d", elem);
		}
		printf("\n");
	}

	//べき乗テスト
	{
		const int n0 = static_pow<int, 2, 0>::value;
		const int n1 = static_pow<int, 2, 1>::value;
		const int n2 = static_pow<int, 2, 2>::value;
		const int n3 = static_pow<int, 2, 3>::value;
		const int n4 = static_pow<int, 2, 4>::value;
		printf("static_pow<2, e> = {%d, %d, %d, %d, %d}\n", n0, n1, n2, n3, n4);
	}
	{
		const int ni0 = power<int, 0>(2);
		const int ni1 = power<int, 1>(2);
		const int ni2 = power<int, 2>(2);
		const int ni3 = power<int, 3>(2);
		const int ni4 = power<int, 4>(2);
		const float nf0 = power<float, 0>(2.f);
		const float nf1 = power<float, 1>(2.f);
		const float nf2 = power<float, 2>(2.f);
		const float nf3 = power<float, 3>(2.f);
		const float nf4 = power<float, 4>(2.f);
		const float nfm0 = minus_power<float, 0>(2.f);
		const float nfm1 = minus_power<float, -1>(2.f);
		const float nfm2 = minus_power<float, -2>(2.f);
		const float nfm3 = minus_power<float, -3>(2.f);
		const float nfm4 = minus_power<float, -4>(2.f);
		printf("power<int, e>(2) = {%d, %d, %d, %d, %d}\n", ni0, ni1, ni2, ni3, ni4);
		printf("power<float, e>(2.f) = {%.1f, %.1f, %.1f, %.1f, %.1f}\n", nf0, nf1, nf2, nf3, nf4);
		printf("minus_power<float, -e>(2.f) = {%.4f, %.4f, %.4f, %.4f, %.4f}\n", nfm0, nfm1, nfm2, nfm3, nfm4);
	}

	//コンストラクタテンプレートテスト
	POINT<int> p1(1, 2);
	POINT<float> p2(p1);
	POINT<long> p3(0, 0);
	p3 = p2;
	printf("p1=(%d, %d)\n", p1.x, p1.y);
	printf("p2=(%.1f, %.1f)\n", p2.x, p2.y);
	printf("p3=(%ld, %ld)\n", p3.x, p3.y);

	//クラス定数テスト
	CClass o;
	//	printf("%d\n", CClass::sc1);
	printf("%d\n", CClass::sc2);
	printf("%d\n", o.c1);
	printf("%d\n", o.c2);
	printf("%d\n", o.v1);
	printf("%d\n", o.v2);
	printf("%d\n", sc1);
	printf("%d\n", sc2);
	printf("%d\n", c1);
	printf("%d\n", c2);
}

//メイン
int main(const int argc, const char* argv[])
{
	test_func1();
	test_func1v();
	test_func2();
	test_func3();
	test_func4();
	return EXIT_SUCCESS;
}

// End of file
