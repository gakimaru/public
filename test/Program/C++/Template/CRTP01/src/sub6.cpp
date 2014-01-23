#include <stdio.h>
#include <iostream>
#include <vector>

//SFINAEテスト（様々なfor_each）

//独自コンテナ
template<typename T, int N>
class MY_ARRAY
{
public:
	typedef MY_ARRAY<T, N> MY_TYPE;
	typedef T DATA_TYPE;
	static const int NUM = N;
public:
	T* begin(){ return &m_array[0]; }
	T* end(){ return &m_array[N]; }
	T& operator[](int i){ return m_array[i]; }
private:
	T m_array[N];
};

//固定配列版for_each
template<class T, size_t N, class F>
inline void for_each(T (&obj)[N], F& functor)
{
	bool is_first = true;
	T* p = obj;
	for (int i = 0; i < N; ++i, ++p)
	{
		functor(*p, is_first);
	}
}

//ポインター型の固定配列版for_each　※部分特殊化
template<class T, std::size_t N, class F>
inline void for_each(T*(&obj)[N], F& functor)
{
	bool is_first = true;
	T** p = obj;
	for (int i = 0; i < N; ++i, ++p)
	{
		functor(**p, is_first);
	}
}

//動的配列版for_each①：配列要素数を渡す
template<class T, class F>
inline void for_each(T* p, int n, F& functor)
{
	bool is_first = true;
	for (int i = 0; i < n; ++i, ++p)
	{
		functor(*p, is_first);
	}
}

//動的配列版for_each②：配列の終端+1を渡す
template<class T, class F>
inline void for_each(T* p, T* end, F& functor)
{
	bool is_first = true;
	while (p != end)
	{
		functor(*p, is_first);
		++p;
	}
}

//STLコンテナ版for_each
template<class T, class F>
inline void for_each(T& con, F& functor)
{
	bool is_first = true;
	typename T::iterator ite = con.begin();
	typename T::iterator end = con.end();
	while (ite != end)
	{
		functor(*ite, is_first);
		++ite;
	}
}

//独自コンテナ版for_each
template<class T, class F>
inline void for_each(typename T::MY_TYPE& con, F& functor)//独自コンテナには ::MY_TYPE メンバーが定義されている
{
	bool is_first = true;
	typename T::DATA_TYPE* p = con.begin();
	typename T::DATA_TYPE* end = con.end();
	while (p != end)
	{
		functor(*p, is_first);
		++p;
	}
}

//関数オブジェクト　※templateなので関数の外で定義
template<typename T>
struct functor {
	inline void operator()(T& o, bool& is_first)
	{
		std::cout << (is_first ? "" : ", ") << o;
		is_first = false;
	}
};

//SFINAEテスト
void testSFINAE()
{
	printf("\n- testSFINAE() -\n\n");

	//int の配列
	int data[] = { 1, 22, 333, 44444, 55555 };

	//int* の配列
	int* data_p[] = { &data[4], &data[3], &data[2], &data[1], &data[0] };

	//STLのvector
	std::vector<char> vec;
	vec.push_back('T');
	vec.push_back('E');
	vec.push_back('S');
	vec.push_back('T');

	//自作コンテナ
	MY_ARRAY<float, 6> my_con;
	my_con[0] = 1.2f;
	my_con[1] = 2.3f;
	my_con[2] = 3.4f;
	my_con[3] = 5.6f;
	my_con[4] = 7.8f;
	my_con[5] = 9.1f;

	//固定配列版for_each
	std::cout << "data[(all)]=";
	for_each(data, functor<int>());
	std::cout << std::endl;

	//ポインター型の固定配列版for_each
	std::cout << "data_p[(all)]=";
	for_each(data_p, functor<int>());
	std::cout << std::endl;

	//動的配列版for_each①：配列要素数を渡す
	std::cout << "data[3]=";
	for_each(data, 3, functor<int>());
	std::cout << std::endl;

	//動的配列版for_each②：配列の終端+1を渡す
	std::cout << "data[2～3]=";
	for_each(data + 2, data + 3 + 1, functor<int>());
	std::cout << std::endl;

	//STLコンテナ版for_each
	std::cout << "vec=";
	for_each(vec, functor<char>());
	std::cout << std::endl;

	//独自コンテナ版for_each
	std::cout << "my_con=";
	for_each<MY_ARRAY<float, 6> >(my_con, functor<float>());//STLコンテナ版と区別するために明示的に型を指定
	std::cout << std::endl;
}

// End of file
