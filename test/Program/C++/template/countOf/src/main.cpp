#include <iostream>
#include <iomanip>
#include <stdlib.h>

//マクロを使用
namespace for_define
{
#ifdef offsetof
#undef offsetof
#endif
#define extentof_1d(var) (sizeof(var) / sizeof(var[0]))
#define extentof_2d(var) (sizeof(var) / sizeof(var[0][0]))
#define extentof_3d(var) (sizeof(var) / sizeof(var[0][0][0]))
#define extentof_4d(var) (sizeof(var) / sizeof(var[0][0][0][0]))
#define extent1of(var) (sizeof(var) / sizeof(var[0]))
#define extent2of(var) (sizeof(var[0]) / sizeof(var[0][0]))
#define extent3of(var) (sizeof(var[0][0]) / sizeof(var[0][0][0]))
#define extent4of(var) (sizeof(var[0][0][0]) / sizeof(var[0][0][0][0]))
#define offsetof(T, member) reinterpret_cast<std::size_t>(&reinterpret_cast<T*>(0)->member)
	void test_func()
	{
		std::cout << std::endl;
		std::cout << "----- for_define::test_func() -----" << std::endl;
		
		//以下、for_template::test_func() とほぼ同じ
		{
			int var0 = 0;
			int var1[1] = { 0 };
			int var2[2][3] = { 0 };
			int var3[4][5][6] = { 0 };
			int var4[7][8][9][10] = { 0 };
			printf("var0\n");
			printf("var1[%d](Total=%d)\n", extent1of(var1), extentof_1d(var1));
			printf("var2[%d][%d](Total=%d)\n", extent1of(var2), extent2of(var2), extentof_2d(var2));
			printf("var3[%d][%d][%d](Total=%d)\n", extent1of(var3), extent2of(var3), extent3of(var3), extentof_3d(var3));
			printf("var4[%d][%d][%d][%d](Total=%d)\n", extent1of(var4), extent2of(var4), extent3of(var4), extent4of(var4),  extentof_4d(var4));
		}

		//以下、for_template::test_func() とほぼ同じ
		{
			int var0 = 0;
			int var1[1] = { 0 };
			int var2[2][3] = { 0 };
			int var3[4][5][6] = { 0 };
			int var4[7][8][9][10] = { 0 };
			std::cout << "sizeof(var0)=" << std::setw(5) << std::right << sizeof(var0) << ", extent1of(var0)=" << std::setw(4) << std::right << "?" << ", extent2of(var0)=" << std::setw(4) << std::right << "?" << ", extent3of(var0)=" << std::setw(4) << std::right << "?" << ", extent4of(var0)=" << std::setw(4) << std::right << "?" << ", extentof_?d(var0)=" << std::setw(4) << std::right << "?" << std::endl;
			std::cout << "sizeof(var1)=" << std::setw(5) << std::right << sizeof(var1) << ", extent1of(var1)=" << std::setw(4) << std::right << extent1of(var1) << ", extent2of(var1)=" << std::setw(4) << std::right << "?"             << ", extent3of(var1)=" << std::setw(4) << std::right << "?" << ", extent4of(var1)=" << std::setw(4) << std::right << "?" << ", extentof_1d(var1)=" << std::setw(4) << std::right << extentof_1d(var1) << std::endl;
			std::cout << "sizeof(var2)=" << std::setw(5) << std::right << sizeof(var2) << ", extent1of(var2)=" << std::setw(4) << std::right << extent1of(var2) << ", extent2of(var2)=" << std::setw(4) << std::right << extent2of(var2) << ", extent3of(var2)=" << std::setw(4) << std::right << "?" << ", extent4of(var2)=" << std::setw(4) << std::right <<"?" << ", extentof_2d(var2)=" << std::setw(4) << std::right << extentof_2d(var2) << std::endl;
			std::cout << "sizeof(var3)=" << std::setw(5) << std::right << sizeof(var3) << ", extent1of(var3)=" << std::setw(4) << std::right << extent1of(var3) << ", extent2of(var3)=" << std::setw(4) << std::right << extent2of(var3) << ", extent3of(var3)=" << std::setw(4) << std::right << extent3of(var3) << ", extent4of(var3)=" << std::setw(4) << std::right << "?" << ", extentof_3d(var3)=" << std::setw(4) << std::right << extentof_3d(var3) << std::endl;
			std::cout << "sizeof(var4)=" << std::setw(5) << std::right << sizeof(var4) << ", extent1of(var4)=" << std::setw(4) << std::right << extent1of(var4) << ", extent2of(var4)=" << std::setw(4) << std::right << extent2of(var4) << ", extent3of(var4)=" << std::setw(4) << std::right << extent3of(var4) << ", extent4of(var4)=" << std::setw(4) << std::right << extent4of(var4) << ", extentof_4d(var4)=" << std::setw(4) << std::right << extentof_4d(var4) << std::endl;
		}

		//以下、for_template::test_func() とほぼ同じ
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
		std::cout << "sizeof(DATA1)=" << std::setw(4) << std::right << sizeof(DATA1) << ", offsetof(DATA1, member_a)=" << std::setw(4) << std::right << offsetof(DATA1, member_a) << ", offsetof(DATA1, member_b)=" << std::setw(4) << std::right << offsetof(DATA1, member_b) << ", offsetof(DATA1, member_c)=" << std::setw(4) << std::right << offsetof(DATA1, member_c) << ", offsetof(DATA1, member_d)=" << std::setw(4) << std::right << offsetof(DATA1, member_d) << std::endl;
		std::cout << "sizeof(DATA2)=" << std::setw(4) << std::right << sizeof(DATA2) << ", offsetof(DATA2, member_a)=" << std::setw(4) << std::right << offsetof(DATA2, member_a) << ", offsetof(DATA2, member_b)=" << std::setw(4) << std::right << offsetof(DATA2, member_b) << ", offsetof(DATA2, member_c)=" << std::setw(4) << std::right << offsetof(DATA2, member_c) << ", offsetof(DATA2, member_d)=" << std::setw(4) << std::right << offsetof(DATA2, member_d) << std::endl;
	}
#undef extent1of
#undef extent2of
#undef extent3of
#undef extent4of
#undef extentof_1d
#undef extentof_2d
#undef extentof_3d
#undef extentof_4d
#undef offsetof
}

//テンプレートを使用
#include <type_traits>//C++11 std::extent用
namespace for_template
{
	//非配列用
	template<typename T> inline std::size_t rankof(const T& data){ return 0; }
	template<typename T> inline std::size_t sizeofelemof(const T& data){ return sizeof(T); }
	template<typename T> inline std::size_t extentof(const T& data){ return 0; }
	template<typename T> inline std::size_t extent1of(const T& data){ return 0; }
	template<typename T> inline std::size_t extent2of(const T& data){ return 0; }
	template<typename T> inline std::size_t extent3of(const T& data){ return 0; }
	template<typename T> inline std::size_t extent4of(const T& data){ return 0; }

	//一次配列用
	template<typename T, std::size_t N1> inline std::size_t rankof(const T(&data)[N1]){ return 1; }
	template<typename T, std::size_t N1> inline std::size_t sizeofelemof(const T(&data)[N1]){ return sizeof(T); }
	template<typename T, std::size_t N1> inline std::size_t extentof(const T(&data)[N1]){ return N1; }
	template<typename T, std::size_t N1> inline std::size_t extent1of(const T(&data)[N1]){ return N1; }
	//template<typename T, std::size_t N1> inline std::size_t extent2of(const T(&data)[N1]){ return 0; }//※不要
	//template<typename T, std::size_t N1> inline std::size_t extent3of(const T(&data)[N1]){ return 0; }//※不要
	//template<typename T, std::size_t N1> inline std::size_t extent4of(const T(&data)[N1]){ return 0; }//※不要

	//二次配列用
	template<typename T, std::size_t N1, std::size_t N2> inline std::size_t rankof(const T(&data)[N1][N2]){ return 2; }
	template<typename T, std::size_t N1, std::size_t N2> inline std::size_t sizeofelemof(const T(&data)[N1][N2]){ return sizeof(T); }
	template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extentof(const T(&data)[N1][N2]){ return N1 * N2; }
	//template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent1of(const T(&data)[N1][N2]){ return N1; }//※不要
	template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent2of(const T(&data)[N1][N2]){ return N2; }
	//template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent3of(const T(&data)[N1][N2]){ return 0; }//※不要
	//template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent4of(const T(&data)[N1][N2]){ return 0; }//※不要

	//三次配列用
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t rankof(const T(&data)[N1][N2][N3]){ return 3; }
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t sizeofelemof(const T(&data)[N1][N2][N3]){ return sizeof(T); }
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extentof(const T(&data)[N1][N2][N3]){ return N1 * N2 * N3; }
	//template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent1of(const T(&data)[N1][N2][N3]){ return N1; }//※不要
	//template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent2of(const T(&data)[N1][N2][N3]){ return N2; }//※不要
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent3of(const T(&data)[N1][N2][N3]){ return N3; }
	//template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent4of(const T(&data)[N1][N2][N3]){ return 0; }//※不要

	//四次配列用
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t rankof(const T(&data)[N1][N2][N3][N4]){ return 4; }
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t sizeofelemof(const T(&data)[N1][N2][N3][N4]){ return sizeof(T); }
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extentof(const T(&data)[N1][N2][N3][N4]){ return N1 * N2 * N3 * N4; }
	//template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent1of(const T(&data)[N1][N2][N3][N4]){ return N1; }//※不要
	//template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent2of(const T(&data)[N1][N2][N3][N4]){ return N2; }//※不要
	//template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent3of(const T(&data)[N1][N2][N3][N4]){ return N3; }//※不要
	template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent4of(const T(&data)[N1][N2][N3][N4]){ return N4; }
	
	template<typename T1, typename T2>
	inline int offsetOf(T1& p1, T2& p2)
	{
		return (const volatile char*)(&p2) - (const volatile char*)(&p1);
	}
	template<typename T1, typename T2>
	inline int offsetOf(T1* p1, T2* p2)
	{
		return (const volatile char*)(p2)-(const volatile char*)(p1);
	}
	template<typename T1, typename T2>
	inline int offsetOf(T1& p1, T2* p2)
	{
		return (const volatile char*)(p2)-(const volatile char*)(&p1);
	}
	template<typename T1, typename T2>
	inline int offsetOf(T1* p1, T2& p2)
	{
		return (const volatile char*)(&p2) - (const volatile char*)(p1);
	}
	//追加：ポインターでも実体でも値（クラス／構造体）のサイズを返す sizeof()
	template<typename T>
	inline std::size_t sizeOf(T val)
	{
		return sizeof(T);
	}
	template<typename T>
	inline std::size_t sizeOf(T* val)
	{
		return sizeof(T);
	}
#define offsetof(T, member) offsetOf((T*)(0), &(((T*)(0))->member))
	void test_func()
	{
		std::cout << std::endl;
		std::cout << "----- for_template::test_func() -----" << std::endl;

		{
			typedef int arr0_t;
			typedef int arr1_t[1];
			typedef int arr2_t[2][3];
			typedef int arr3_t[4][5][6];
			typedef int arr4_t[7][8][9][10];
			printf("arr0_t(Rank=%d)\n", std::rank<arr0_t>::value);
			printf("arr1_t[%d](Rank=%d)\n", std::extent<arr1_t, 0>::value, std::rank<arr1_t>::value);
			printf("arr2_t[%d][%d](Rank=%d)\n", std::extent<arr2_t, 0>::value, std::extent<arr2_t, 1>::value, std::rank<arr2_t>::value);
			printf("arr3_t[%d][%d][%d](Rank=%d)\n", std::extent<arr3_t, 0>::value, std::extent<arr3_t, 1>::value, std::extent<arr3_t, 2>::value, std::rank<arr3_t>::value);
			printf("arr4_t[%d][%d][%d][%d](Rank=%d)\n", std::extent<arr4_t, 0>::value, std::extent<arr4_t, 1>::value, std::extent<arr4_t, 2>::value, std::extent<arr4_t, 3>::value, std::rank<arr4_t>::value);
			printf("*arr0_t[%d][%d][%d][%d](Rank=%d)\n", std::extent<arr0_t, 0>::value, std::extent<arr0_t, 1>::value, std::extent<arr0_t, 2>::value, std::extent<arr0_t, 3>::value, std::rank<arr0_t>::value);
			printf("*arr1_t[%d][%d][%d][%d](Rank=%d)\n", std::extent<arr1_t, 0>::value, std::extent<arr1_t, 1>::value, std::extent<arr1_t, 2>::value, std::extent<arr1_t, 3>::value, std::rank<arr1_t>::value);
			printf("*arr2_t[%d][%d][%d][%d](Rank=%d)\n", std::extent<arr2_t, 0>::value, std::extent<arr2_t, 1>::value, std::extent<arr2_t, 2>::value, std::extent<arr2_t, 3>::value, std::rank<arr2_t>::value);
			printf("*arr3_t[%d][%d][%d][%d](Rank=%d)\n", std::extent<arr3_t, 0>::value, std::extent<arr3_t, 1>::value, std::extent<arr3_t, 2>::value, std::extent<arr3_t, 3>::value, std::rank<arr3_t>::value);
			printf("*arr4_t[%d][%d][%d][%d](Rank=%d)\n", std::extent<arr4_t, 0>::value, std::extent<arr4_t, 1>::value, std::extent<arr4_t, 2>::value, std::extent<arr4_t, 3>::value, std::rank<arr4_t>::value);

			std::cout << "sizeof(arr0_t)=" << std::setw(5) << std::right << sizeof(arr0_t) << ", std::extent<arr0_t, 0>::value=" << std::setw(4) << std::right << std::extent<arr0_t, 0>::value << ", std::extent<arr0_t, 1>::value=" << std::setw(4) << std::right << std::extent<arr0_t, 1>::value << ", std::extent<arr0_t, 2>::value=" << std::setw(4) << std::right << std::extent<arr0_t, 2>::value << ", std::extent<arr0_t, 3>::value=" << std::setw(4) << std::right << std::extent<arr0_t, 3>::value << ", std::rank<arr0_t>::value=" << std::setw(4) << std::right << std::rank<arr0_t>::value << std::endl;
			std::cout << "sizeof(arr1_t)=" << std::setw(5) << std::right << sizeof(arr1_t) << ", std::extent<arr1_t, 0>::value=" << std::setw(4) << std::right << std::extent<arr1_t, 0>::value << ", std::extent<arr1_t, 1>::value=" << std::setw(4) << std::right << std::extent<arr1_t, 1>::value << ", std::extent<arr1_t, 2>::value=" << std::setw(4) << std::right << std::extent<arr1_t, 2>::value << ", std::extent<arr1_t, 3>::value=" << std::setw(4) << std::right << std::extent<arr1_t, 3>::value << ", std::rank<arr1_t>::value=" << std::setw(4) << std::right << std::rank<arr1_t>::value << std::endl;
			std::cout << "sizeof(arr2_t)=" << std::setw(5) << std::right << sizeof(arr2_t) << ", std::extent<arr2_t, 0>::value=" << std::setw(4) << std::right << std::extent<arr2_t, 0>::value << ", std::extent<arr2_t, 1>::value=" << std::setw(4) << std::right << std::extent<arr2_t, 1>::value << ", std::extent<arr2_t, 2>::value=" << std::setw(4) << std::right << std::extent<arr2_t, 2>::value << ", std::extent<arr2_t, 3>::value=" << std::setw(4) << std::right << std::extent<arr2_t, 3>::value << ", std::rank<arr2_t>::value=" << std::setw(4) << std::right << std::rank<arr2_t>::value << std::endl;
			std::cout << "sizeof(arr3_t)=" << std::setw(5) << std::right << sizeof(arr3_t) << ", std::extent<arr3_t, 0>::value=" << std::setw(4) << std::right << std::extent<arr3_t, 0>::value << ", std::extent<arr3_t, 1>::value=" << std::setw(4) << std::right << std::extent<arr3_t, 1>::value << ", std::extent<arr3_t, 2>::value=" << std::setw(4) << std::right << std::extent<arr3_t, 2>::value << ", std::extent<arr3_t, 3>::value=" << std::setw(4) << std::right << std::extent<arr3_t, 3>::value << ", std::rank<arr3_t>::value=" << std::setw(4) << std::right << std::rank<arr3_t>::value << std::endl;
			std::cout << "sizeof(arr4_t)=" << std::setw(5) << std::right << sizeof(arr4_t) << ", std::extent<arr4_t, 0>::value=" << std::setw(4) << std::right << std::extent<arr4_t, 0>::value << ", std::extent<arr4_t, 1>::value=" << std::setw(4) << std::right << std::extent<arr4_t, 1>::value << ", std::extent<arr4_t, 2>::value=" << std::setw(4) << std::right << std::extent<arr4_t, 2>::value << ", std::extent<arr4_t, 3>::value=" << std::setw(4) << std::right << std::extent<arr4_t, 3>::value << ", std::rank<arr4_t>::value=" << std::setw(4) << std::right << std::rank<arr4_t>::value << std::endl;
		}
		
		//以下、for_define::test_func() とほぼ同じ
		{
			int var0 = 0;
			int var1[1] = { 0 };
			int var2[2][3] = { 0 };
			int var3[4][5][6] = { 0 };
			int var4[7][8][9][10] = { 0 };
			printf("var0(Rank=%d, Total=%d, ElemtSize=%d)\n", rankof(var0), extentof(var0), sizeofelemof(var0));
			printf("var1[%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var1), rankof(var1), extentof(var1), sizeofelemof(var1));
			printf("var2[%d][%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var2), extent2of(var2), rankof(var2), extentof(var2), sizeofelemof(var2));
			printf("var3[%d][%d][%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var3), extent2of(var3), extent3of(var3), rankof(var3), extentof(var3), sizeofelemof(var3));
			printf("var4[%d][%d][%d][%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var4), extent2of(var4), extent3of(var4), extent4of(var4), rankof(var4), extentof(var4), sizeofelemof(var4));
			printf("*var0[%d][%d][%d][%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var0), extent2of(var0), extent3of(var0), extent4of(var0), rankof(var0), extentof(var0), sizeofelemof(var0));
			printf("*var1[%d][%d][%d][%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var1), extent2of(var1), extent3of(var1), extent4of(var1), rankof(var1), extentof(var1), sizeofelemof(var1));
			printf("*var2[%d][%d][%d][%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var2), extent2of(var2), extent3of(var2), extent4of(var2), rankof(var2), extentof(var2), sizeofelemof(var2));
			printf("*var3[%d][%d][%d][%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var3), extent2of(var3), extent3of(var3), extent4of(var3), rankof(var3), extentof(var3), sizeofelemof(var3));
			printf("*var4[%d][%d][%d][%d](Rank=%d, Total=%d, ElemtSize=%d)\n", extent1of(var4), extent2of(var4), extent3of(var4), extent4of(var4), rankof(var4), extentof(var4), sizeofelemof(var4));
		}

		//以下、for_define::test_func() とほぼ同じ
		{
			int var0 = 0;
			int var1[1] = { 0 };
			int var2[2][3] = { 0 };
			int var3[4][5][6] = { 0 };
			int var4[7][8][9][10] = { 0 };
			std::cout << "sizeof(var0)=" << std::setw(5) << std::right << sizeof(var0) << ", sizeofelemof(var0)=" << std::setw(4) << std::right << sizeofelemof(var0) << ", extent1of(var0)=" << std::setw(4) << std::right << extent1of(var0) << ", extent2of(var0)=" << std::setw(4) << std::right << extent2of(var0) << ", extent3of(var0)=" << std::setw(4) << std::right << extent3of(var0) << ", extent4of(var0)=" << std::setw(4) << std::right << extent4of(var0) << ", extentof(var0)=" << std::setw(4) << std::right << extentof(var0) << ", rankof(var0)=" << std::setw(4) << std::right << rankof(var0) << std::endl;
			std::cout << "sizeof(var1)=" << std::setw(5) << std::right << sizeof(var1) << ", sizeofelemof(var1)=" << std::setw(4) << std::right << sizeofelemof(var1) << ", extent1of(var1)=" << std::setw(4) << std::right << extent1of(var1) << ", extent2of(var1)=" << std::setw(4) << std::right << extent2of(var1) << ", extent3of(var1)=" << std::setw(4) << std::right << extent3of(var1) << ", extent4of(var1)=" << std::setw(4) << std::right << extent4of(var1) << ", extentof(var1)=" << std::setw(4) << std::right << extentof(var1) << ", rankof(var1)=" << std::setw(4) << std::right << rankof(var1) << std::endl;
			std::cout << "sizeof(var2)=" << std::setw(5) << std::right << sizeof(var2) << ", sizeofelemof(var2)=" << std::setw(4) << std::right << sizeofelemof(var2) << ", extent1of(var2)=" << std::setw(4) << std::right << extent1of(var2) << ", extent2of(var2)=" << std::setw(4) << std::right << extent2of(var2) << ", extent3of(var2)=" << std::setw(4) << std::right << extent3of(var2) << ", extent4of(var2)=" << std::setw(4) << std::right << extent4of(var2) << ", extentof(var2)=" << std::setw(4) << std::right << extentof(var2) << ", rankof(var2)=" << std::setw(4) << std::right << rankof(var2) << std::endl;
			std::cout << "sizeof(var3)=" << std::setw(5) << std::right << sizeof(var3) << ", sizeofelemof(var3)=" << std::setw(4) << std::right << sizeofelemof(var3) << ", extent1of(var3)=" << std::setw(4) << std::right << extent1of(var3) << ", extent2of(var3)=" << std::setw(4) << std::right << extent2of(var3) << ", extent3of(var3)=" << std::setw(4) << std::right << extent3of(var3) << ", extent4of(var3)=" << std::setw(4) << std::right << extent4of(var3) << ", extentof(var3)=" << std::setw(4) << std::right << extentof(var3) << ", rankof(var3)=" << std::setw(4) << std::right << rankof(var3) << std::endl;
			std::cout << "sizeof(var4)=" << std::setw(5) << std::right << sizeof(var4) << ", sizeofelemof(var4)=" << std::setw(4) << std::right << sizeofelemof(var4) << ", extent1of(var4)=" << std::setw(4) << std::right << extent1of(var4) << ", extent2of(var4)=" << std::setw(4) << std::right << extent2of(var4) << ", extent3of(var4)=" << std::setw(4) << std::right << extent3of(var4) << ", extent4of(var4)=" << std::setw(4) << std::right << extent4of(var4) << ", extentof(var4)=" << std::setw(4) << std::right << extentof(var4) << ", rankof(var4)=" << std::setw(4) << std::right << rankof(var4) << std::endl;
		}

		//以下、for_define::test_func() と同じ
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
		std::cout << "sizeof(DATA1)=" << std::setw(4) << std::right << sizeof(DATA1) << ", offsetof(DATA1, member_a)=" << std::setw(4) << std::right << offsetof(DATA1, member_a) << ", offsetof(DATA1, member_b)=" << std::setw(4) << std::right << offsetof(DATA1, member_b) << ", offsetof(DATA1, member_c)=" << std::setw(4) << std::right << offsetof(DATA1, member_c) << ", offsetof(DATA1, member_d)=" << std::setw(4) << std::right << offsetof(DATA1, member_d) << std::endl;
		std::cout << "sizeof(DATA2)=" << std::setw(4) << std::right << sizeof(DATA2) << ", offsetof(DATA2, member_a)=" << std::setw(4) << std::right << offsetof(DATA2, member_a) << ", offsetof(DATA2, member_b)=" << std::setw(4) << std::right << offsetof(DATA2, member_b) << ", offsetof(DATA2, member_c)=" << std::setw(4) << std::right << offsetof(DATA2, member_c) << ", offsetof(DATA2, member_d)=" << std::setw(4) << std::right << offsetof(DATA2, member_d) << std::endl;

		//追加
		DATA1 obj1;
		DATA2* obj2 = new DATA2;
		std::cout << "sizeOf(obj1)=" << std::setw(4) << std::right << sizeOf(obj1) << ", offsetOf(obj1, obj1.member_a)=" << std::setw(4) << std::right << offsetOf(obj1, obj1.member_a) << ", offsetOf(obj1, obj1.member_b)=" << std::setw(4) << std::right << offsetOf(obj1, obj1.member_b) << ", offsetOf(obj1, obj1.member_c)=" << std::setw(4) << std::right << offsetOf(obj1, obj1.member_c) << ", offsetOf(obj1, obj1.member_d)=" << std::setw(4) << std::right << offsetOf(obj1, obj1.member_d) << std::endl;          //offsetOf()ではポインター変数の扱いに注意！（ポインター変数の member_d をそのまま渡しているとおかしな結果になる）
		std::cout << "sizeOf(obj2)=" << std::setw(4) << std::right << sizeOf(obj2) << ", offsetOf(obj2, obj2->member_a)=" << std::setw(4) << std::right << offsetOf(obj2, obj2->member_a) << ", offsetOf(obj2, obj2->member_b)=" << std::setw(4) << std::right << offsetOf(obj2, obj2->member_b) << ", offsetOf(obj2, obj2->member_c)=" << std::setw(4) << std::right << offsetOf(obj2, obj2->member_c) << ", offsetOf(obj2, obj2->member_d)=" << std::setw(4) << std::right << offsetOf(obj2, &obj2->member_d) << std::endl; //                                          （member_d のポインターを渡す事で問題を解消）
	}
#undef offsetof
}

int main(const int argc, const char* argv[])
{
	for_define::test_func();
	for_template::test_func();
	return EXIT_SUCCESS;
}

// End of file
