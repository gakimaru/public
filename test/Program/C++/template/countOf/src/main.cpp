#include <iostream>
#include <iomanip>
#include <stdlib.h>

//マクロを使用
namespace for_define
{
#ifdef countof
#undef countof
#endif
#ifdef offsetof
#undef offsetof
#endif
#define countof1(var) (sizeof(var) / sizeof(var[0]))
#define countof2(var) (sizeof(var[0]) / sizeof(var[0][0]))
#define countof3(var) (sizeof(var[0][0]) / sizeof(var[0][0][0]))
#define countof(var) countof1(var)
#define offsetof(T, member) reinterpret_cast<std::size_t>(&reinterpret_cast<T*>(0)->member)
	void test_func()
	{
		std::cout << std::endl;
		std::cout << "----- for_define::test_func() -----" << std::endl;
		
		//以下、for_template::test_func() と同じ

		int var1 = 0;
		int var2[2] = { 0 };
		int var3[2][3] = { 0 };
		int var4[2][3][4] = { 0 };
		std::cout << "sizeof(va11)=" << std::setw(3) << std::right << sizeof(var1) << std::endl;
		std::cout << "sizeof(va12)=" << std::setw(3) << std::right << sizeof(var2) << ", countof1(var2)=" << std::setw(3) << std::right << countof1(var2) << std::endl;
		std::cout << "sizeof(va13)=" << std::setw(3) << std::right << sizeof(var3) << ", countof1(var3)=" << std::setw(3) << std::right << countof1(var3) << ", countof2(var3)=" << std::setw(3) << std::right << countof2(var3) << std::endl;
		std::cout << "sizeof(va14)=" << std::setw(3) << std::right << sizeof(var4) << ", countof1(var4)=" << std::setw(3) << std::right << countof1(var4) << ", countof2(var4)=" << std::setw(3) << std::right << countof2(var4) << ", countof3(var4)=" << std::setw(3) << std::right << countof3(var4) << std::endl;

		struct DATA1
		{
			short member_a;
			int member_b;
			char member_c[9];
			void* member_d;
			DATA1(){}
		};
		struct DATA2
		{
			short member_a;
			int member_b;
			char member_c[9];
			void* member_d;
			virtual void func(){}
			DATA2(){}
		};
		std::cout << "sizeof(DATA1)=" << std::setw(3) << std::right << sizeof(DATA1) << ", offsetof(DATA1, member_a)=" << std::setw(3) << std::right << offsetof(DATA1, member_a) << ", offsetof(DATA1, member_b)=" << std::setw(3) << std::right << offsetof(DATA1, member_b) << ", offsetof(DATA1, member_c)=" << std::setw(3) << std::right << offsetof(DATA1, member_c) << ", offsetof(DATA1, member_d)=" << std::setw(3) << std::right << offsetof(DATA1, member_d) << std::endl;
		std::cout << "sizeof(DATA2)=" << std::setw(3) << std::right << sizeof(DATA2) << ", offsetof(DATA2, member_a)=" << std::setw(3) << std::right << offsetof(DATA2, member_a) << ", offsetof(DATA2, member_b)=" << std::setw(3) << std::right << offsetof(DATA2, member_b) << ", offsetof(DATA2, member_c)=" << std::setw(3) << std::right << offsetof(DATA2, member_c) << ", offsetof(DATA2, member_d)=" << std::setw(3) << std::right << offsetof(DATA2, member_d) << std::endl;
	}
#undef countof1
#undef countof2
#undef countof3
#undef countof
#undef offsetof
}

//テンプレートを使用
namespace for_template
{
	template<typename T, std::size_t N1>
	std::size_t countOf1(const T (&var)[N1])
	{
		return N1;
	}
	template<typename T, std::size_t N1, std::size_t N2>
	std::size_t countOf2(const T (&var)[N1][N2])
	{
		return N2;
	}
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3>
	std::size_t countOf3(const T (&var)[N1][N2][N3])
	{
		return N3;
	}
	template<typename T1, typename T2>
	int offsetOf(T1& p1, T2& p2)
	{
		return (const volatile char*)(&p2) - (const volatile char*)(&p1);
	}
	template<typename T1, typename T2>
	int offsetOf(T1* p1, T2* p2)
	{
		return (const volatile char*)(p2)-(const volatile char*)(p1);
	}
	template<typename T1, typename T2>
	int offsetOf(T1& p1, T2* p2)
	{
		return (const volatile char*)(p2)-(const volatile char*)(&p1);
	}
	template<typename T1, typename T2>
	int offsetOf(T1* p1, T2& p2)
	{
		return (const volatile char*)(&p2) - (const volatile char*)(p1);
	}
	template<typename T>
	std::size_t sizeOf(T val)
	{
		return sizeof(T);
	}
	//追加：ポインターでも実体でも値（クラス／構造体）のサイズを返す sizeof()
	template<typename T>
	std::size_t sizeOf(T* val)
	{
		return sizeof(T);
	}
#define countof1(var) countOf1(var)
#define countof2(var) countOf2(var)
#define countof3(var) countOf3(var)
#define countof(var) countOf1(var)
#define offsetof(T, member) offsetOf((T*)(0), &(((T*)(0))->member))
	void test_func()
	{
		std::cout << std::endl;
		std::cout << "----- for_template::test_func() -----" << std::endl;
		
		//以下、for_define::test_func() と同じ

		int var1 = 0;
		int var2[2] = { 0 };
		int var3[2][3] = { 0 };
		int var4[2][3][4] = { 0 };
		std::cout << "sizeof(va11)=" << std::setw(3) << std::right << sizeof(var1) << std::endl;
		std::cout << "sizeof(va12)=" << std::setw(3) << std::right << sizeof(var2) << ", countof1(var2)=" << std::setw(3) << std::right << countof1(var2) << std::endl;
		std::cout << "sizeof(va13)=" << std::setw(3) << std::right << sizeof(var3) << ", countof1(var3)=" << std::setw(3) << std::right << countof1(var3) << ", countof2(var3)=" << std::setw(3) << std::right << countof2(var3) << std::endl;
		std::cout << "sizeof(va14)=" << std::setw(3) << std::right << sizeof(var4) << ", countof1(var4)=" << std::setw(3) << std::right << countof1(var4) << ", countof2(var4)=" << std::setw(3) << std::right << countof2(var4) << ", countof3(var4)=" << std::setw(3) << std::right << countof3(var4) << std::endl;

		struct DATA1
		{
			short member_a;
			int member_b;
			char member_c[9];
			void* member_d;
			DATA1(){}
		};
		struct DATA2
		{
			short member_a;
			int member_b;
			char member_c[9];
			void* member_d;
			virtual void func(){}
			DATA2(){}
		};
		std::cout << "sizeof(DATA1)=" << std::setw(3) << std::right << sizeof(DATA1) << ", offsetof(DATA1, member_a)=" << std::setw(3) << std::right << offsetof(DATA1, member_a) << ", offsetof(DATA1, member_b)=" << std::setw(3) << std::right << offsetof(DATA1, member_b) << ", offsetof(DATA1, member_c)=" << std::setw(3) << std::right << offsetof(DATA1, member_c) << ", offsetof(DATA1, member_d)=" << std::setw(3) << std::right << offsetof(DATA1, member_d) << std::endl;
		std::cout << "sizeof(DATA2)=" << std::setw(3) << std::right << sizeof(DATA2) << ", offsetof(DATA2, member_a)=" << std::setw(3) << std::right << offsetof(DATA2, member_a) << ", offsetof(DATA2, member_b)=" << std::setw(3) << std::right << offsetof(DATA2, member_b) << ", offsetof(DATA2, member_c)=" << std::setw(3) << std::right << offsetof(DATA2, member_c) << ", offsetof(DATA2, member_d)=" << std::setw(3) << std::right << offsetof(DATA2, member_d) << std::endl;

		//追加
		DATA1 obj1;
		DATA2* obj2 = new DATA2;
		std::cout << "sizeOf(obj1)=" << std::setw(3) << std::right << sizeOf(obj1) << ", offsetOf(obj1, obj1.member_a)=" << std::setw(3) << std::right << offsetOf(obj1, obj1.member_a) << ", offsetOf(obj1, obj1.member_b)=" << std::setw(3) << std::right << offsetOf(obj1, obj1.member_b) << ", offsetOf(obj1, obj1.member_c)=" << std::setw(3) << std::right << offsetOf(obj1, obj1.member_c) << ", offsetOf(obj1, obj1.member_d)=" << std::setw(3) << std::right << offsetOf(obj1, obj1.member_d) << std::endl;          //offsetOf()ではポインター変数の扱いに注意！（ポインター変数の member_d をそのまま渡しているとおかしな結果になる）
		std::cout << "sizeOf(obj2)=" << std::setw(3) << std::right << sizeOf(obj2) << ", offsetOf(obj2, obj2->member_a)=" << std::setw(3) << std::right << offsetOf(obj2, obj2->member_a) << ", offsetOf(obj2, obj2->member_b)=" << std::setw(3) << std::right << offsetOf(obj2, obj2->member_b) << ", offsetOf(obj2, obj2->member_c)=" << std::setw(3) << std::right << offsetOf(obj2, obj2->member_c) << ", offsetOf(obj2, obj2->member_d)=" << std::setw(3) << std::right << offsetOf(obj2, &obj2->member_d) << std::endl; //                                          （member_d のポインターを渡す事で問題を解消）
	}
#undef countof1
#undef countof2
#undef countof3
#undef countof
#undef offsetof
}

int main(const int argc, const char* argv[])
{
	for_define::test_func();
	for_template::test_func();
	return EXIT_FAILURE;
}

// End of file
