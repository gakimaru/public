#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <varargs.h>

#include <algorithm>

//�e���v���[�g�֐����R���p�C�����Ƀ��e�����l�ɓW�J����鎖���e�X�g�i�œK�����x���Ɉˑ��j
//�����s���ɁA[�f�o�b�O]��[�E�C���h�E]��[�t�A�Z���u��]�ŁA�A�Z���u���̃R�[�h���m�F����B
template<typename T> T max(T n1, T n2){                   return n1 > n2 ? n1 : n2; }
template<typename T> T max(T n1, T n2, T n3){             return n1 > n2 ? n1 : max(n2, n3); }
template<typename T> T max(T n1, T n2, T n3, T n4){       return n1 > n2 ? n1 : max(n2, n3, n4); }
template<typename T> T max(T n1, T n2, T n3, T n4, T n5){ return n1 > n2 ? n1 : max(n2, n3, n4, n5); }

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

//�ϒ��e���v���[�g�����ł�max()
//�l����� max()
template<typename T1, typename T2>
T1 vmax(T1 n1, T2 n2){ return n1 > n2 ? n1 : n2; }
//�l���O�ȏ�� max() : �ċA�����i���F�e���v���[�g�̓��ꉻ�ł͂Ȃ��A�֐��̃I�[�o�[���[�h�ōċN���I�������Ă���j
template<typename T1, typename T2, typename T3, typename... Tx>
T1 vmax(T1 n1, T2 n2, T3 n3, Tx... nx){ return vmax(vmax(n1, n2), n3, nx...); } //nx����ɂȂ�����l����̕����Ă΂��

//�ϒ��e���v���[�g�����e�X�g
template<class First>
void func()
{
	std::cout << typeid(First).name() << std::endl;
}
template<class First, class Second, class... Rest>
void func()
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

//���������}�N���Ŏ��������ꍇ
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

//�y���p�z����̃N���X�̒��ōő�̃T�C�Y��\�ߒ��ׂĂ���
//���Ⴆ�΁A�e���v���[�g���\�b�h�Ő������镡����̃I�u�W�F�N�g�ׂ̈ɁA�ŗL�̃o�b�t�@��p�ӂ��Ă����ꍇ�ȂǁB�o�b�t�@�T�C�Y�������v�Z����ׂɎg�p�B
//�������ȃ��e�����l���������萔�Ƃ̈Ⴂ���`�F�b�N���Ă���
//�����_�iVisual C++ 2013�j�F�e���v���[�g�֐��ɂ��R���p�C�����̃��e�����l�����͐������邪�A�K���f�[�^�̈�Ɍ��ʂ��i�[����A�R�[�h��ł̃��e�����l�W�J�͂���Ȃ��B���ꂪ�K�v�Ȃ�#define���g�����AC++11��constexpr�̎�����҂K�v������B
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
const std::size_t MAX_CLASS_SIZE2 = max(sizeof(CA), sizeof(CB), sizeof(CC));//�O���[�o���萔
const std::size_t MAX_CLASS_SIZE2x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//�O���[�o���萔
const std::size_t LITERAL2 = 2;
static const std::size_t MAX_CLASS_SIZE3 = max(sizeof(CA), sizeof(CB), sizeof(CC));//static�O���[�o���萔
static const std::size_t MAX_CLASS_SIZE3x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//static�O���[�o���萔
static const std::size_t LITERAL3 = 3;
namespace NS
{
	const std::size_t MAX_CLASS_SIZE4 = max(sizeof(CA), sizeof(CB), sizeof(CC));//�l�[���X�y�[�X�萔
	const std::size_t MAX_CLASS_SIZE4x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//�l�[���X�y�[�X�萔
	const std::size_t LITERAL4 = 4;
	static const std::size_t MAX_CLASS_SIZE5 = max(sizeof(CA), sizeof(CB), sizeof(CC));//static�l�[���X�y�[�X�萔
	static const std::size_t MAX_CLASS_SIZE5x = max3(sizeof(CA), sizeof(CB), sizeof(CC));//static�l�[���X�y�[�X�萔
	static const std::size_t LITERAL5 = 5;

};
void test_func3()
{
	const std::size_t MAX_CLASS_SIZE6 = max(sizeof(CA), sizeof(CB), sizeof(CC));//���[�J���萔
	const std::size_t MAX_CLASS_SIZE6x = max(sizeof(CA), sizeof(CB), sizeof(CC));//���[�J���萔
	const std::size_t LITERAL6 = 6;
	static const std::size_t MAX_CLASS_SIZE7 = max(sizeof(CA), sizeof(CB), sizeof(CC));//static���[�J���萔
	static const std::size_t MAX_CLASS_SIZE7x = max(sizeof(CA), sizeof(CB), sizeof(CC));//static���[�J���萔
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

//�萔
static const int sc1 = max(1, 2, 3, 4, 5);  //OK
static const int sc2 = max5(1, 2, 3, 4, 5); //OK
const int c1 = max(1, 2, 3, 4, 5);          //OK
const int c2 = max5(1, 2, 3, 4, 5);         //OK

//�N���X���̒萔�^�����l
class CClass
{
public:
//	static const int sc1 = max(1, 2, 3, 4, 5);  //NG:�R���p�C���G���[
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

//��
enum
{
//	e1 = max(1, 2, 3, 4, 5),  //NG:�R���p�C���G���[
	e2 = max5(1, 2, 3, 4, 5), //OK
};

//�ׂ���
template<int N, int E>
struct Pow{
	static const int value = N * Pow<N, E - 1>::value;
};
//�ׂ���F�ċA�I�_�̂��߂̓��ꉻ
template<int N>
struct Pow<N, 0>{
	static const int value = 1;
};

//���W�^
template<typename T>
struct POINT
{
	T x;
	T y;
	//�ʏ�R���X�g���N�^
	POINT(T x_, T y_) :
		x(x_),
		y(y_)
	{}
	//�R�s�[�e���v���[�g�R���X�g���N�^
	template<typename U>
	POINT(POINT<U>& o) :
		x(static_cast<T>(o.x)),
		y(static_cast<T>(o.y))
	{}
	//�R�s�[�e���v���[�g�I�y���[�^
	template<typename U>
	POINT<T>& operator=(POINT<U>& o)
	{
		x = static_cast<T>(o.x);
		y = static_cast<T>(o.y);
		return *this;
	}
};

//�����œK�������p�N���X�F�œK���O
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
//�����œK�������p�N���X�F�œK���@
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
//�����œK�������p�N���X�F�œK���A
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
//�����œK�������p�N���X�F�œK���B
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
	static int sum;
	struct print{
		void all(const char* name, int data[], int n)
		{
			sum = 0;
			printf("%s=", name);
		//	for_each_array(data, n, *this);
			std::for_each(data, data + n, *this);
			printf(" (sum=%d, avg=%.1f)\n", sum, static_cast<float>(sum) / static_cast<float>(n));
		}
		//int sum;
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
//	for_each_array(data1, n1, round());
//	for_each_array(data2, n2, round());
	std::for_each(data1, data1 + n1, round());
	std::for_each(data2, data2 + n2, round());
	printf("<AFTER>\n");
	o.all("data1", data1, n1);
	o.all("data2", data2, n2);
}

template<typename T, std::size_t N>
std::size_t lengthOfAray(T (&var)[N]){ return N; }

void test_func4()
{
	//�����œK�������p����
	{
		int data1[] = {1, 2, 3, 39, 200, 53, 8, 74, 12};
		int data2[] = {13, 6, 76, 43, 23, 125, 1 };
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

	//�ׂ���e�X�g
	const int n1 = Pow<2, 0>::value;
	const int n2 = Pow<2, 1>::value;
	const int n3 = Pow<2, 2>::value;
	const int n4 = Pow<2, 3>::value;
	const int n5 = Pow<10, 4>::value;
	printf("{%d, %d, %d, %d, %d}\n", n1, n2, n3, n4, n5);
	
	//�R���X�g���N�^�e���v���[�g�e�X�g
	POINT<int> p1(1, 2);
	POINT<float> p2(p1);
	POINT<long> p3(0, 0);
	p3 = p2;
	printf("p1=(%d, %d)\n", p1.x, p1.y);
	printf("p2=(%.1f, %.1f)\n", p2.x, p2.y);
	printf("p3=(%ld, %ld)\n", p3.x, p3.y);

	//�N���X�萔�e�X�g
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

//���C��
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
