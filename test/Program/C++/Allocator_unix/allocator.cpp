//コンパイルスイッチ
#define USE_NEW_PTR_FOR_TEST0//test0で、new_ptr関数を使用する時はこのマクロを有効にする
#define USE_DELETE_PTR_FOR_TEST0//test0で、delete_ptr関数を使用する時はこのマクロを有効にする
#define USE_DESTRUCTOR_FOR_TEST1//test1で、デストラクタを使用するときはこのマクロを有効にする（アロケートサイズが増えることを確認できる）
//#define USE_GLOBAL_NEW_DELETE_FOR_TEST2//test2で、クラス内new/deleteをグローバルnew/deleteに変更する時はこのマクロを有効にする
#define USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2//test2で、クラス内deleteをsize引数付きのものにする時はこのマクロを有効にする
#define USE_DESTRUCTOR_FOR_TEST2//test2で、デストラクタを使用する時はこのマクロを有効にする（アロケートサイズが増えることを確認できる）
//#define USE_NAMESPACE_NEW_DELETE_FOR_TEST2//test2で、ネームスペースに定義したnew/deleteのテストを行う時はこのマクロを有効にする
#define USE_NEW_MACRO//test7で、NEWマクロを使用する時はこのマクロを有効にする
#define USE_ALLOC_INFO//test7で、new時にメモリ確保事情報を使用する時はこのマクロを有効にする
#define USE_CRC_CALC_TABLE//test8で、CRC計算の際に、事前計算済みのCRC計算テーブルを使用する時はこのマクロを有効にする

//GCC関連：GCC使用時はこれらのマクロを有効化する
#define USE_MEMALIGN//【GCC用】test6以降で、memalignを使用する時はこのマクロを有効にする
#define IS_NOT_FRIEND_WITH_NEW_OPERATOR//【GCC用】test7以降で、オペレータnew/deleteをフレンド宣言しない時はこのマクロを有効にする
#define TLS_IS_POSIX//【GCC用】TLSの宣言をPOSIXスタイルにする時はこのマクロを有効にする

//MS固有仕様関連：Visual C++使用時はこのマクロを有効化する
//#define USE_STRCPY_S//【MS固有仕様】strcpy_sを使用する時にこのマクロを有効にする
//#define USE_FUNCSIG//【MS固有仕様】関数名に__FUNCSIG__を使用する時にこのマクロを有効にする

//C++11関連：サンプルプログラムには、これら以外にもC++11の要素が膨れている
//これらのマクロは、Visual C++環境やC++0x環境でコンパイルするために使用する
#define ENABLE_NULLPTR//【C++11用】nullptrを有効にする時はこのマクロを有効にする
#define ENABLE_OVERRIDE//【C++11用】overrideを有効にする時はこのマクロを有効にする
#define ENABLE_CONSTEXPR//【C++11用】constexprを有効にする時はこのマクロを有効にする
#define ENABLE_USER_DEFINED_LITERALS//【C++11用】ユーザー定義リテラルを有効にする時はこのマクロを有効にする

#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//std::size_t用
#include <stdint.h>//uintptr_t,intptr_t用
#include <limits.h>//INT_MAX用
#include <assert.h>//assert用
#include <new>//規定の配置new/配置delete用
#include <typeinfo>//typeid用

//スレッドローカルストレージ修飾子
//※C++11仕様偽装
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX仕様
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows仕様
#endif//TLS_IS_POSIX

//C++11互換用マクロ
#ifndef ENABLE_NULLPTR
#define nullptr NULL
#endif//ENABLE_NULLPTR
#ifndef ENABLE_OVERRIDE
#define overide
#endif//ENABLE_OVERRIDE
#ifndef ENABLE_CONSTEXPR
#define constexpr
#endif//ENABLE_CONSTEXPR

//関数名取得マクロ
#ifdef USE_FUNCSIG
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif//USE_FUNCSIG

//--------------------------------------------------------------------------------
//固定バッファ用配置newでコンストクタ呼び出し

//規定の配置new/配置delete
//※#include <new> で定義されている規定の配置new/配置delete
//　  void* operator new(size_t, void* where) throw();
//　  void* operator new[](size_t, void* where) throw();
//　  void operator delete(void*, void*) throw();
//　  void operator delete[](void*, void*) throw();
//　  void* operator new(size_t size, const nothrow_t&) throw();//例外をスローしない
//　  void* operator new[](size_t size, const nothrow_t&) throw();//例外をスローしない
//　  void operator delete(void*, const nothrow_t&) throw();//例外をスローしない
//　  void operator delete[](void*, const nothrow_t&) throw();//例外をスローしない

#ifdef USE_NEW_PTR_FOR_TEST0
//--------------------
//配置new用new関数
//※可変長テンプレート引数を使用して、コンストラクタの引数を取得
template<class T, typename... Tx>
T* new_ptr(char* buff, Tx... nx)
{
	if (!buff)
		return nullptr;
	return new(buff)T(nx...);//配置new呼び出し（コンストラクタは可変長比数渡し）
}
//※配列版のnew関数はなし
//※クラス内deleteと対のクラス内newを用いたほうがよい
#endif//USE_DELETE_PTR_FOR_TEST0

#ifdef USE_DELETE_PTR_FOR_TEST0
//--------------------
//配置delete用delete関数
template<class T>
void delete_ptr(T*& p, char* buff)
{
	if (!p)
		return;
	p->~T();//デストラクタ呼び出し（デストラクタが定義されていない型やプリミティブ型でも問題なし）
	//operator delete(p, p);//配置deleteの呼び出しは、特に必要ではない
	p = nullptr;//安全のためにポインタを初期化
}
//※配列版のdelete関数はなし
//※型にデストラクタが定義されているかどうかを気にせず使えるるような汎用処理が作れないため
//※クラス内deleteを用いることでこの問題を解消できる
#endif//USE_DELETE_PTR_FOR_TEST0

//--------------------
//テスト用クラス
class CTest0
{
public:
	//コンストラクタ
	CTest0(const char* name) :
		m_name(name)
	{
		printf("CTest0::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	~CTest0()
	{
		printf("CTest0::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	const char* m_name;//名前
};

//--------------------
//テスト
void test0()
{
	printf("---------- test0:固定バッファ配置new/配置delete ----------\n");
	char buff[32];//インスタンス用のバッファ
	printf("buff=0x%p\n", buff);
#ifdef USE_NEW_PTR_FOR_TEST0
	CTest0* obj_p = new_ptr<CTest0>(buff, "テスト0");
#else//USE_NEW_PTR_FOR_TEST0
	CTest0* obj_p = new(buff)CTest0("テスト0");
#endif//USE_NEW_PTR_FOR_TEST0
	printf("obj_p=0x%p\n", obj_p);
#ifdef USE_DELETE_PTR_FOR_TEST0
	delete_ptr(obj_p, buff);//専用delete関数で削除（内部でデストラクタを呼び出す）
	printf("obj_p=0x%p\n", obj_p);//削除後のポインタを確認
#else//USE_DELETE_PTR_FOR_TEST0
	obj_p->~CTest0();//明示的なデストラクタ呼び出し
	operator delete(obj_p, buff);//operator delete で配置deleteを呼び出す（デストラクタが呼び出されない点に注意）
#endif//USE_DELETE_PTR_FOR_TEST0
}

//--------------------------------------------------------------------------------
//挙動確認のための配置new / 配置delete

//--------------------
//配置new/配置delete
//※それぞれ第2引数に char* を取り、既定の関数をオーバーロードする
//単体new
void* operator new(const std::size_t size, char* where) throw()
{
	printf("placement new(size=%d, where=0x%p)\n", size, where);
	return where;//渡されたバッファをそのまま返す
}
//配列new
//※デストラクタを持った型の場合、バッファの先頭に要素数を格納するために、少し大きなサイズが渡される
//　この時、戻り値のポインタは、関数を抜けた時、要素数情報の分がシフトしたポインタに変換される
//　型のアラインメントによっては大きくシフトする可能性もある
//　デストラクタを持たない型もしくはプリミティブ型ではこの情報は扱われない（なのでややこしい）
void* operator new[](const std::size_t size, char* where) throw()
{
	printf("placement new[](size=%d, where=0x%p)\n", size, where);
	return where;//渡されたバッファをそのまま返す
}
//単体delete
//※配置newと対になる配置deleteは必須
//　（コンストラクタで例外が発生すると自動的に呼び出されるため）
void operator delete(void* p, char* where) throw()
{
	printf("placement delete(p=0x%p, where=0x%p)\n", p, where);
	//なにもしない
}
//配列delete
//※デストラクタを持った型のポインタであっても、受け渡されたポインタがそのまま扱われるので注意
//　（メモリ確保時の正確なポインタが分からない）
//※クラス内delete関数を使用することでこの問題を解消できる
void operator delete[](void* p, char* where) throw()
{
	printf("placement delete[](p=0x%p, where=0x%p)\n", p, where);
	//なにもしない
}

//--------------------
//固定バッファ用delete関数
//※デストラクタを呼び出すテンプレート関数
template<class T>
void delete_ptr(T*& p)
{
	printf("delete_ptr(p=0x%p)\n", p);
	if (!p)
		return;
	p->~T();//デストラクタ呼び出し
	operator delete(p, reinterpret_cast<char*>(p));//配置delete呼び出し
	p = nullptr;//安全のためにポインタを初期化
}
//挙動の確認のために配列版のdelete関数も用意
//（残念ながら）配列の要素数を受け渡す
template<class T>
void delete_ptr(T*& p, const std::size_t array_num)
{
	printf("delete_ptr(p=0x%p, array_num=%d)\n", p, array_num);
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//デストラクタ呼び出し
	operator delete[](p, reinterpret_cast<char*>(p));//配置delete呼び出し
	p = nullptr;//安全のためにポインタを初期化
}

//--------------------
//テスト用クラス
//__declspec(align(8))//8バイトアラインメントでテストする場合はこの行を有効にする
class CTest1
{
public:
	//デフォルトコンストラクタ
	CTest1() :
		CTest1("(default)")//他のコンストラクタ呼び出し（C++11で追加された構文）
		//m_name("(default)")//C++11が使えない場合は普通に初期化
	{
		printf("CTest1::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CTest1(const char* name) :
		m_name(name)
	{
		printf("CTest1::Constructor : name=\"%s\"\n", m_name);
	}
#ifdef USE_DESTRUCTOR_FOR_TEST1
	//デストラクタ
	~CTest1()
	{
		printf("CTest1::Destructor : name=\"%s\"\n", m_name);
	}
#endif//USE_DESTRUCTOR_FOR_TEST1
protected:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};
//--------------------
//テスト用クラス（多重継承テスト用）
class CTest1ex
{
public:
	//コンストラクタ
	CTest1ex()
	{
		printf("CTest1ex::Constructor\n");
	}
	//デストラクタ
	~CTest1ex()
	{
		printf("CTest1ex::Destructor\n");
	}
protected:
	//フィールド
	int m_dummy;//ダミー
};
//--------------------
//テスト用クラス（多重継承）
class CDerivedTest1 : public CTest1, public CTest1ex
{
public:
	//デフォルトコンストラクタ
	CDerivedTest1() :
		CTest1(),
		CTest1ex()
	{
		printf("CDerivedTest1::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CDerivedTest1(const char* name) :
		CTest1(name),
		CTest1ex()
	{
		printf("CDerivedTest1::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	~CDerivedTest1()
	{
		printf("CDerivedTest1::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	int m_dummy;//ダミー
};

//--------------------
//テスト
void test1()
{
	printf("---------- test1:固定バッファ配置new/配置delete（挙動確認）----------\n");
	//固定バッファでクラスのインスタンスを生成
	{
		printf("----------クラス\n");
		char buff[32];//インスタンス用のバッファ
		printf("buff=0x%p\n", buff);
		CTest1* obj_p = new(buff)CTest1("テスト1");
		printf("obj_p=0x%p\n", obj_p);
		delete_ptr(obj_p);
	}
	//固定バッファでクラス配列のインスタンスを生成
	{
		printf("----------クラスの配列\n");
		char buff[64];//インスタンス用のバッファ
		printf("buff=0x%p\n", buff);
		const int array_num = 3;
		CTest1* obj_p = new(buff)CTest1[array_num]();
		printf("obj_p=0x%p\n", obj_p);
		printf("*reinterpret_cast<int*>(buff)=%d\n", *reinterpret_cast<int*>(buff));//デストラクタを持った型の配列は、バッファの先頭に要素数が格納されている
		delete_ptr(obj_p, array_num);
	}
	//固定バッファでプリミティブ型のインスタンスを生成
	{
		printf("----------プリミティブ型\n");
		char buff[32];//インスタンス用のバッファ
		printf("buff=0x%p\n", buff);
		char* data_p = new(buff)char;
		printf("data_p=0x%p\n", data_p);
		*data_p = 123;
		printf("*data_p(0x%p)=%d\n", data_p, *data_p);
		delete_ptr(data_p);//デストラクタのない型で実行しても問題なし
	}
	//固定バッファでプリミティブ型の配列のインスタンスを生成
	{
		printf("----------プリミティブ型の配列\n");
		char buff[32];//インスタンス用のバッファ
		printf("buff=0x%p\n", buff);
		const int array_num = 3;
		char* data_p = new(buff)char[array_num];
		printf("data_p=0x%p\n", data_p);
		printf("*reinterpret_cast<int*>(buff)=%d\n", *reinterpret_cast<int*>(buff));//デストラクタを持たない型の配列は、バッファに要素数を格納していない
		data_p[0] = 123;
		printf("*data_p(0x%p)[0]=%d\n", data_p, data_p[0]);
		delete_ptr(data_p, array_num);//デストラクタのない型で実行しても問題なし
	}
	//固定バッファで多重継承したクラスのインスタンスを生成
	{
		printf("----------多重継承クラス\n");
		char buff[32];//インスタンス用のバッファ
		printf("buff=0x%p\n", buff);
		CDerivedTest1* obj_p = new(buff)CDerivedTest1("テスト1多重継承");
		CTest1* parent_p = obj_p;//親1にキャスト
		CTest1ex* parent_ex_p = obj_p;//親2にキャスト
		printf("obj_p=0x%p, parent_p=0x%p, parent_ex_p=0x%p\n", obj_p, parent_p, parent_ex_p);
		//delete_ptr(obj_p);//子として削除
		//delete_ptr(parent_p);//親1として削除
		delete_ptr(parent_ex_p);//親2として削除
	}
}

//--------------------------------------------------------------------------------
//クラス内new

//--------------------
//インスタンス用バッファ
static char s_buffForTestClass2[64];

//--------------------
//グローバルnew/deleteテスト
#ifdef USE_GLOBAL_NEW_DELETE_FOR_TEST2
//単体new
void* operator new(const std::size_t size) throw()
{
	printf("new(size=%d)\n", size);
	return s_buffForTestClass2;//インスタンス用バッファを返す
}
//配列new
void* operator new[](const std::size_t size) throw()
{
	printf("new[](size=%d)\n", size);
	return s_buffForTestClass2;//インスタンス用バッファを返す
}
//単体delete
void operator delete(void* p) throw()
{
	printf("delete(p=0x%p)\n", p);
	//なにもしない
}
//配列delete
void operator delete[](void* p) throw()
{
	printf("delete[](p=0x%p)\n", p);
	//なにもしない
}
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2

//--------------------
//テスト用クラス
class CTest2
{
public:
	//オペレータ
#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
	//クラス内new/delete
	//new
	//※自クラスのインスタンス専用のnew/delete
	//※普通のnew/delete演算子でインスタンスを生成／破棄すると呼び出される
	//※配置new/配置deleteも使用可（配置deleteの際は CTest2::operator delete(p, xxx) のようにクラス名を明示する必要あり）
	//※静的operatorである必要があるが、staticを付けなくても暗黙的にstatic扱いになる
	//単体new
	static void* operator new(const std::size_t size) throw()
	{
		printf("CTest2::new(size=%d)\n", size);
		return s_buffForTestClass2;//インスタンス用バッファを返す
	}
	//配列new
	static void* operator new[](const std::size_t size) throw()
	{
		printf("CTest2::new[](size=%d)\n", size);
		return s_buffForTestClass2;//インスタンス用バッファを返す
	}
#ifndef USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2
	//delete
	//※クラス内deleteには2種類のスタイルがある
	//※これは標準的なスタイル
	//単体delete
	static void operator delete(void* p) throw()
	{
		printf("CTest2::delete(p=0x%p)\n", p);
		//なにもしない
	}
	//配列delete
	static void operator delete[](void* p) throw()
	{
		printf("CTest2::delete[](p=0x%p)\n", p);
		//なにもしない
	}
#else//USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2
	//delete
	//※クラス内deleteでは、第2引数に size_t を取る形も標準スタイルの一つ（非配置delete）
	//※2種類とも定義したら、operator delete(void*) の方が優先
	//単体delete
	static void operator delete(void* p, const std::size_t size) throw()
	{
		printf("CTest2::delete(p=0x%p, size=%d)\n", p, size);
		//なにもしない
	}
	//配列delete
	static void operator delete[](void* p, const std::size_t size) throw()
	{
		printf("CTest2::delete[](p=0x%p, size=%d)\n", p, size);
		//なにもしない
	}
#endif//USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2
public:
	//デフォルトコンストラクタ
	CTest2() :
		CTest2("(default)")//他のコンストラクタ呼び出し（C++11で追加された仕様）
		//m_name("(default)")//C++11が使えない場合は普通に初期化
	{
		printf("CTest2::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CTest2(const char* name) :
		m_name(name)
	{
		printf("CTest2::Constructor : name=\"%s\"\n", m_name);
	}
#ifdef USE_DESTRUCTOR_FOR_TEST2
	//デストラクタ
	//※多重継承のテストのために virtual 化
	virtual ~CTest2()
	{
		printf("CTest2::Destructor : name=\"%s\"\n", m_name);
	}
#endif//USE_DESTRUCTOR_FOR_TEST2
protected:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};
//--------------------
//テスト用クラス（多重継承テスト用）
class CTest2ex
{
public:
	//オペレータ
#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
	//クラス内new
	static void* operator new(const std::size_t size) throw()
	{
		printf("CTest2ex::new(size=%d)\n", size);
		return s_buffForTestClass2;//インスタンス用バッファを返す
	}
	//クラス内delete
	static void operator delete(void* p) throw()
	{
		printf("CTest2ex::delete(p=0x%p)\n", p);
		//なにもしない
	}
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2
public:
	//コンストラクタ
	CTest2ex()
	{
		printf("CTest2ex::Constructor\n");
	}
	//デストラクタ
	virtual ~CTest2ex()
	{
		printf("CTest2ex::Destructor\n");
	}
protected:
	//フィールド
	int m_dummy;//ダミー
};
//--------------------
//テスト用クラス（多重継承）
class CDerivedTest2 : public CTest2, public CTest2ex
{
public:
	//オペレータ
#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
	//クラス内new
	static void* operator new(const std::size_t size) throw()
	{
		printf("CDerivedTest2::new(size=%d)\n", size);
		return s_buffForTestClass2;//インスタンス用バッファを返す
	}
	//クラス内delete
	static void operator delete(void* p) throw()
	{
		printf("CDerivedTest2::delete(p=0x%p)\n", p);
		//なにもしない
	}
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2
public:
	//デフォルトコンストラクタ
	CDerivedTest2() :
		CTest2(),
		CTest2ex()
	{
		printf("CDerivedTest2::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CDerivedTest2(const char* name) :
		CTest2(name),
		CTest2ex()
	{
		printf("CDerivedTest2::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	~CDerivedTest2() override
	{
		printf("CDerivedTest2::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	int m_dummy;//ダミー
};
//--------------------
//ネームスペース
#ifdef USE_NAMESPACE_NEW_DELETE_FOR_TEST2
namespace test2_ns
{
	//ネームスペース内バッファ
	char s_buff[32];

	//ネームスペースに定義した new
	void* operator new(const std::size_t size) throw()
	{
		printf("test2_ns::new size=%d\n", size);
		return s_buff;
	}
	//ネームスペースに定義した delete
	void operator delete(void* p) throw()
	{
		printf("test2_ns::delete p=0x%p\n", p);
	}
}
#endif//USE_NAMESPACE_NEW_DELETE_FOR_TEST2

//--------------------
//テスト
void test2()
{
	printf("---------- test2:クラス内new/delete ----------\n");
	{
		printf("----------クラス\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CTest2* obj_p = new CTest2("テスト2");//普通のnew演算子として使える
		printf("obj_p=0x%p\n", obj_p);
		delete obj_p;//普通のdelete演算子として使える
	}
	{
		printf("----------クラスの配列\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CTest2* obj_p = new CTest2[3];//普通のnew[]演算子として使える
		printf("obj_p=0x%p\n", obj_p);
		printf("*reinterpret_cast<int*>(s_buffForTestClass2)=%d\n", *reinterpret_cast<int*>(s_buffForTestClass2));//デストラクタを持った型の配列は、バッファの先頭に要素数が格納されている
		delete[] obj_p;//普通のdelete[]演算子として使える
	}
	{
		printf("----------多重継承クラス\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CDerivedTest2* obj_p = new CDerivedTest2("テスト2多重継承");
		CTest2* parent_p = obj_p;//親1にキャスト
		CTest2ex* parent_ex_p = obj_p;//親2にキャスト
		printf("obj_p=0x%p, parent_p=0x%p, parent_ex_p=0x%p\n", obj_p, parent_p, parent_ex_p);
		//delete obj_p;//子として削除
		//delete parent_p;//親1として削除
		delete parent_ex_p;//親2として削除
	}
#ifdef USE_NAMESPACE_NEW_DELETE_FOR_TEST2
	{
		printf("----------ネームスペースのnew/delete\n");
		CTest2* obj_p = (CTest2*)test2_ns::operator new(sizeof(CTest2));//ネームスペースに定義したnew
		::new(obj_p)CTest2("テスト2");//配置newで明示的なコンストラクタ呼び出し
		obj_p->~CTest2();//明示的なデストラクタ呼び出し
		test2_ns::operator delete(obj_p);//ネームスペースに定義したdelete
	}
#endif//USE_NAMESPACE_NEW_DELETE_FOR_TEST2
}

//--------------------------------------------------------------------------------
//固定バッファシングルトンのテスト

//--------------------
//専用シングルトン：単純タイプ
class CTest3Singleton1
{
public:
	//静的アクセッサ
	static CTest3Singleton1* getSigleton(){ return &m_singleton; }//シングルトンを取得
public:
	//アクセッサ
	int getData() const { return m_data; }//データを取得
	void setData(const int data){ m_data = data; }//データを更新
public:
	//コンストラクタ
	CTest3Singleton1() :
		m_data(0)
	{
		printf("CTest3Singleton1::Constructor : m_data=%d\n", m_data);
	}
	//デストラクタ
	~CTest3Singleton1()
	{
		printf("CTest3Singleton1::Destructor : m_data=%d\n", m_data);
	}
private:
	//フィールド
	int m_data;//データ
	static CTest3Singleton1 m_singleton;//シングルトンインスタンス
};
//--------------------
//シングルトン静的変数のインスタンス化
CTest3Singleton1 CTest3Singleton1::m_singleton;

//--------------------
//テスト
//シングルトンのデータ表示
void printData_typeA1()
{
	CTest3Singleton1* singleton_p = CTest3Singleton1::getSigleton();
	printf("singleton_p->getData()=%d\n", singleton_p->getData());
}
//シングルトンのデータ更新
void updateData_typeA1()
{
	CTest3Singleton1* singleton_p = CTest3Singleton1::getSigleton();
	singleton_p->setData(123);
}

//--------------------
//専用シングルトン：インスタンス操作タイプ
class CTest3Singleton2
{
public:
	//静的アクセッサ
	static CTest3Singleton2* getSigleton()//シングルトンを取得
	{
		create();//インスタンスがなければ生成
		return m_singleton;
	}
public:
	//アクセッサ
	int getData() const { return m_data; }//データを取得
	void setData(const int data){ m_data = data; }//データを更新
private:
	//オペレータ（private）
	static void* operator new(const std::size_t) throw(){ return m_singletonBuff; }//new演算子
	static void operator delete(void*) throw() {}//delete演算子
private:
	//静的メソッド（private）
	//シングルトンインスタンスの生成
	static void create()
	{
		if (m_singleton)
			return;
		m_singleton = new CTest3Singleton2();
	}
public:
	//静的メソッド
	//シングルトンインスタンスの明示的な破棄
	static void destroy()
	{
		if (!m_singleton)
			return;
		delete m_singleton;
		m_singleton = nullptr;
	}
public:
	//コンストラクタ
	CTest3Singleton2() :
		m_data(0)
	{
		printf("CTest3Singleton2::Constructor : m_data=%d\n", m_data);
	}
	//デストラクタ
	~CTest3Singleton2()
	{
		printf("CTest3Singleton2::Destructor : m_data=%d\n", m_data);
	}
private:
	//フィールド
	int m_data;//データ
	static CTest3Singleton2* m_singleton;//シングルトンインスタンス参照
	static unsigned char m_singletonBuff[];//シングルトンインスタンス用バッファ
};
//--------------------
//シングルトン静的変数のインスタンス化
CTest3Singleton2* CTest3Singleton2::m_singleton = nullptr;
unsigned char CTest3Singleton2::m_singletonBuff[sizeof(CTest3Singleton2)];//シングルトンインスタンス用バッファ

//--------------------
//テスト
//シングルトンのデータ表示
void printData_typeA2()
{
	CTest3Singleton2* singleton_p = CTest3Singleton2::getSigleton();
	printf("singleton_p->getData()=%d\n", singleton_p->getData());
}
//シングルトンのデータ更新
void updateData_typeA2()
{
	CTest3Singleton2* singleton_p = CTest3Singleton2::getSigleton();
	singleton_p->setData(123);
}
//シングルトンのインスタンスを明示的に破棄
void deleteIntentionally_typeA2()
{
	CTest3Singleton2::destroy();
}

//--------------------
//汎用固定バッファシングルトンテンプレートクラス
template<class T>
class CSingleton
{
	//配置newテンプレートをフレンド化
	template<class U>
	friend void* operator new(const std::size_t size, CSingleton<U>& singleton) throw();
public:
	//オペレータ（シングルトン本体のプロキシー）
	T* operator->(){ return m_singleton; }
public:
	//メソッド
	//シングルトンインスタンスの明示的な破棄
	void destroy();
public:
	//コンストラクタ
	CSingleton();
private:
	//フィールド
	static T* m_singleton;//シングルトン本体参照
	static unsigned char m_singletonBuff[];//シングルトン本体用バッファ
};

//--------------------
//テンプレート配置new
template<class T>
void* operator new(const std::size_t size, CSingleton<T>& singleton) throw()
{
	return singleton.m_singletonBuff;//汎用シングルトンテンプレートクラス内のバッファを返す
}
//テンプレート配置delete
template<class T>
void operator delete(void* p, CSingleton<T>& singleton) throw()
{
	//なにもしない
}

//--------------------
//汎用固定バッファシングルトンテンプレートクラス：実装部
//明示的な削除
template<class T>
void CSingleton<T>::destroy()
{
	if (!m_singleton)
		return;
	m_singleton->~T();//デストラクタ呼び出し
	operator delete(m_singleton, *this);//配置delete呼び出し（なくてもよい）
	m_singleton = nullptr;
}
//コンストラクタ
template<class T>
CSingleton<T>::CSingleton()
{
	//まだ初期化していなければ初期化
	if (!m_singleton)
		m_singleton = new(*this)T();
}
//--------------------
//シングルトン静的変数のインスタンス化
template<class T>
T* CSingleton<T>::m_singleton = nullptr;//シングルトン参照
template<class T>
unsigned char CSingleton<T>::m_singletonBuff[sizeof(T)];//シングルトン用バッファ

//--------------------
//テスト用クラス
class CTest3
{
public:
	//アクセッサ
	int getData() const { return m_data; }//データ取得
	void setData(const int data){ m_data = data; }//データ更新
public:
	//コンストラクタ
	CTest3() :
		m_data(0)
	{
		printf("CTest3::Constructor : m_data=%d\n", m_data);
	}
	//デストラクタ
	~CTest3()
	{
		printf("CTest3::Destructor : m_data=%d\n", m_data);
	}
private:
	//フィールド
	int m_data;//データ
};

//--------------------
//テスト
//シングルトンのデータ表示
void printData_typeB()
{
	CSingleton<CTest3> singleton;
	printf("singleton->getData()=%d\n", singleton->getData());
}
//シングルトンのデータ更新
void updateData_typeB()
{
	CSingleton<CTest3> singleton;
	singleton->setData(123);
}
//シングルトンのインスタンスを明示的に破棄
void deleteIntentionally_typeB()
{
	CSingleton<CTest3> singleton;
	singleton.destroy();
}

//--------------------
//テスト
void test3()
{
	printf("---------- test3:シングルトン ----------\n");
	{
		printf("----------専用シングルトン：単純タイプ\n");
		printData_typeA1();//データ表示
		updateData_typeA1();//データ更新
		printData_typeA1();//データ表示
	}
	{
		printf("----------専用シングルトン：インスタンス操作タイプ\n");
		printData_typeA2();//データ表示
		updateData_typeA2();//データ更新
		printData_typeA2();//データ表示
		deleteIntentionally_typeA2();//明示的なインスタンス破棄
		printData_typeA2();//データ表示
	}
	{
		printf("----------汎用シングルトン\n");
		printData_typeB();//データ表示
		updateData_typeB();//データ更新
		printData_typeB();//データ表示
		deleteIntentionally_typeB();//明示的なインスタンス破棄
		printData_typeB();//データ表示
	}
}

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
//配置new/配置delete
//※メモリ使用状況を確認するためにマーカーを表示
//配置new
void* operator new(const std::size_t size, CStackAllocator& allocator, const std::size_t align = IStackAllocator::DEFAULT_ALIGN) throw()
{
	printf("placement new(size=%d, stack_allocator.marker=%d, align=%d)\n", size, allocator.getMarker(), align);
	return allocator.alloc(size, align);
}
//配列版
void* operator new[](const std::size_t size, CStackAllocator& allocator, const std::size_t align = IStackAllocator::DEFAULT_ALIGN) throw()
{
	printf("placement new[](size=%d, stack_allocator.marker=%d, align=%d)\n", size, allocator.getMarker(), align);
	return allocator.alloc(size, align);
}
//配置delete
void operator delete(void* p, CStackAllocator& allocator, const std::size_t) throw()
{
	printf("placement delete(p=0x%p, stack_allocator.marker=%d)\n", p, allocator.getMarker());
	//allocator.back(p) は実行しない
}
//配列版
void operator delete[](void* p, CStackAllocator& allocator, const std::size_t) throw()
{
	printf("placement delete[](p=0x%p, stack_allocator.marker=%d)\n", p, allocator.getMarker());
	//allocator.back(p) は実行しない
}
//デストラクタ呼び出し付きdelete
template<class T>
void delete_ptr(T*& p, CStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, stack_allocator.marker=%d)\n", p, allocator.getMarker());
	if (!p)
		return;
	p->~T();//デストラクタ呼び出し
	//operator delete(p, allocator, 0) は実行しない
	//allocator.back(p) は実行しない
	p = nullptr;//安全のためにポインタを初期化
}
//配列版
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, array_num=%d, stack_allocator.marker=%d)\n", p, array_num, allocator.getMarker());
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//デストラクタ呼び出し
	//operator delete[](p, allocator, 0) は実行しない
	//allocator.back(p) は実行しない
	p = nullptr;//安全のためにポインタを初期化
}

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

//--------------------
//テスト用クラス
//__declspec(align(8))//8バイトアラインメントでテストする場合はこの行を有効にする
class CTest4a
{
public:
	//デフォルトコンストラクタ
	CTest4a() :
		CTest4a("(default)")//他のコンストラクタ呼び出し（C++11で追加された仕様）
		//m_name("(default)")//C++11が使えない場合は普通に初期化
	{
		printf("CTest4a::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CTest4a(const char* name) :
		m_name(name)
	{
		printf("CTest4a::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	~CTest4a()
	{
		printf("CTest4a::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};

//--------------------------------------------------------------------------------
//双方向スタックアロケータ

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
//配置new/配置delete
//※メモリ使用状況を確認するためにマーカーを表示
//配置new
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//配列版
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//配置delete
void operator delete(void* p, CDualStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) は実行しない
}
void operator delete(void* p, CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) は実行しない
}
//配列版
void operator delete[](void* p, CDualStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered) throw()
{
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) は実行しない
}
void operator delete[](void* p, CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) は実行しない
}
//デストラクタ呼び出し付きdelete
template<class T>
void delete_ptr(T*& p, CDualStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	if (!p)
		return;
	p->~T();//デストラクタ呼び出し
	//operator delete(p, allocator, 0) は実行しない
	//allocator.back(p) は実行しない
	p = nullptr;//安全のためにポインタを初期化
}
//配列版
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CDualStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, array_num=%d, dual_allocator.marker=%d,%d)\n", p, array_num, allocator.getMarkerN(), allocator.getMarkerR());
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//デストラクタ呼び出し
	//operator delete[](p, allocator, 0) は実行しない
	//allocator.back(p) は実行しない
	p = nullptr;//安全のためにポインタを初期化
}

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

//--------------------
//テスト用クラス
//__declspec(align(8))//8バイトアラインメントでテストする場合はこの行を有効にする
class CTest4b
{
public:
	//デフォルトコンストラクタ
	CTest4b() :
		CTest4b("(default)")//他のコンストラクタ呼び出し（C++11で追加された仕様）
		//m_name("(default)")//C++11が使えない場合は普通に初期化
	{
		printf("CTest4b::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CTest4b(const char* name) :
		m_name(name)
	{
		printf("CTest4b::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	~CTest4b()
	{
		printf("CTest4b::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};

//--------------------------------------------------------------------------------

//--------------------
//テスト
void test4a()
{
	printf("---------- test4a:スタックアロケータ ----------\n");
	CStackAllocatorWithBuff<64> stack;//スタックアロケータ生成（64バイトのバッファを確保）
	printf("buff=0x%p\n", stack.getBuff());
	{
		printf("-----\n");
		int* i1 = new(stack) int[2];
		printf("i1=0x%p\n", i1);
		char* c1 = new(stack, 1) char[13];
		printf("c1=0x%p\n", c1);
		CStackAllocator::marker_t marker = stack.getMarker();//マーカー取得
		printf("marker=%d\n", marker);
		float* f1 = new(stack) float[4];
		printf("f1=0x%p\n", f1);
		CTest4a* obj1_p = new(stack)CTest4a("テスト4a");
		printf("obj1_p=0x%p\n", obj1_p);
		delete_ptr(f1, 4, stack);
		delete_ptr(c1, 15, stack);
		delete_ptr(i1, 2, stack);
		delete_ptr(obj1_p, stack);
		stack.back(marker);//マーカーを戻す
		printf("back(%d)\n", marker);
	}
	{
		printf("-----\n");
		CStackAllocator::marker_t marker = stack.getMarker();//マーカー取得
		printf("marker=%d\n", marker);
		CTest4a* obj2_p = new(stack)CTest4a[3];
		printf("obj2_p=0x%p\n", obj2_p);
		int* i2 = new(stack) int;
		printf("i2=0x%p\n", i2);
		float* f2 = new(stack) float;
		printf("f2=0x%p\n", f2);
		char* c2 = new(stack, 1) char;
		printf("c2=0x%p\n", c2);
		int* over = new(stack) int[10];//【NG】サイズオーバー
		printf("over=0x%p\n", over);
		delete_ptr(f2, stack);
		delete_ptr(c2, stack);
		delete_ptr(i2, stack);
		delete_ptr(obj2_p, 3, stack);
	}
}

//--------------------
//テスト
void test4b()
{
	printf("---------- test4b:双方向スタックアロケータ ----------\n");
	CDualStackAllocatorWithBuff<64> stack(DSA_NORMAL);//双方向スタックアロケータ生成（64バイトのバッファを確保）
	printf("buff=0x%p\n", stack.getBuff());
	{
		printf("-----\n");
		printf("getDefaultOrdered()=%d\n", stack.getDefaultOrdered());
		int* i1 = new(stack) int[2];
		printf("i1=0x%p\n", i1);
		char* c1 = new(stack, 1, DSA_REVERSE) char[13];
		printf("c1=0x%p\n", c1);
		CStackAllocator::marker_t marker = stack.getMarker();//マーカー取得
		CStackAllocator::marker_t marker_n = stack.getMarkerN();//マーカー取得
		CStackAllocator::marker_t marker_r = stack.getMarkerR();//マーカー取得
		printf("marker: default=%d, normal=%d, reverse=%d\n", marker, marker_n, marker_r);
		float* f1 = new(stack) float[4];
		printf("f1=0x%p\n", f1);
		CTest4b* obj1_p = new(stack, DSA_REVERSE)CTest4b("テスト4b");
		printf("obj1_p=0x%p\n", obj1_p);
		delete_ptr(f1, 4, stack);
		delete_ptr(c1, 15, stack);
		delete_ptr(i1, 2, stack);
		delete_ptr(obj1_p, stack);
		stack.backN(marker_n);//マーカーを戻す
		printf("backN(%d)\n", marker_n);
		stack.backR(marker_r);//マーカーを戻す
		printf("backR(%d)\n", marker_r);
	}
	{
		printf("-----\n");
		stack.setDefaultOrdered(DSA_REVERSE);//デフォルト伸すタック順を変更
		printf("getDefaultOrdered()=%d\n", stack.getDefaultOrdered());
		CStackAllocator::marker_t marker = stack.getMarker();//マーカー取得
		CStackAllocator::marker_t marker_n = stack.getMarkerN();//マーカー取得
		CStackAllocator::marker_t marker_r = stack.getMarkerR();//マーカー取得
		printf("marker: default=%d, normal=%d, reverse=%d\n", marker, marker_n, marker_r);
		CTest4b* obj2_p = new(stack, DSA_NORMAL)CTest4b[3];
		printf("obj2_p=0x%p\n", obj2_p);
		int* i2 = new(stack) int;
		printf("i2=0x%p\n", i2);
		float* f2 = new(stack, DSA_NORMAL) float;
		printf("f2=0x%p\n", f2);
		char* c2 = new(stack, 1) char;
		printf("c2=0x%p\n", c2);
		int* over1 = new(stack, DSA_NORMAL) int[10];//【NG】サイズオーバー
		printf("over1=0x%p\n", over1);
		int* over2 = new(stack) int[10];//【NG】サイズオーバー
		printf("over2=0x%p\n", over2);
		delete_ptr(f2, stack);
		delete_ptr(c2, stack);
		delete_ptr(i2, stack);
		delete_ptr(obj2_p, 3, stack);
	}
}

//--------------------------------------------------------------------------------
//プールアロケータ

#include <atomic>//C++11アトミック型

//--------------------
//クラス宣言
class CPoolAllocator;

//--------------------
//配置new
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw();
//配置delete
void operator delete(void* p, CPoolAllocator& allocator) throw();

//----------------------------------------
//プールアロケータクラス
//※非スレッドセーフ
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
		//m_lock.lock();

		m_used.store(0);//使用中数
		m_next = 0;//未使用先頭インデックス
		m_recycle = INVALID_INDEX;//リサイクルインデックス

		//ロック解放
		//m_lock.unlock();
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
		//m_lock.lock();

		//使用中ブロック数を再チェック
		//if (m_used.load() >= m_poolBlocksNum)
		//{
		//	m_lock.unlock();//ロック解放
		//	return INVALID_INDEX;//空きなし
		//}

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
		//m_lock.unlock();

		//最初に使用中ブロック数を判定しているので、この時点でインデックスが得られなければプログラムに問題があるはず
		//ASSERT(index != INVALID_INDEX, "Probably, mistaken logic in this program.");

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
		//m_lock.lock();

		//リサイクル
		*reinterpret_cast<unsigned int*>(getBlock(index)) = m_recycle;//リサイクルインデックス書き込み（空きノードの先頭に強引に書き込む）
		m_recycle = index;//リサイクルインデックス組み換え

		//使用中数カウントダウン
		m_used.fetch_sub(1);

		//ロック解放
		//m_lock.unlock();
	}
public:
	//メモリ確保
	void* alloc(const std::size_t size)
	{
		//【アサーション】要求サイズがブロックサイズを超える場合は即時確保失敗
		//ASSERT(size <= m_blockSize, "CPoolAllocator::alloc(%d) cannot allocate. Size must has been under %d.", size, m_blockSize);
		if (size > m_blockSize)
		{
			return nullptr;
		}
		//空きブロックを確保して返す
		const index_t index = assign();
		//【アサーション】全ブロック使用中につき、確保失敗
		//ASSERT(index >= 0, "CPoolAllocator::alloc(%d) cannot allocate. Buffer is full. (num of blocks is %d)", size, m_poolBlocksNum);
		//確保したメモリを返す
		return index == INVALID_INDEX ? nullptr : getBlock(index);
	}
	//メモリ解放
	void free(void * p)
	{
		//nullptr時は即時解放失敗
		//ASSERT(p != nullptr, "CPoolAllocator::free() cannot free. Pointer is null.");
		if (!p)
			return;
		//ポインタからインデックスを算出
		const intptr_t diff = reinterpret_cast<intptr_t>(p)-reinterpret_cast<intptr_t>(m_pool);//ポインタの差分
		const index_t index = diff / m_blockSize;//ブロックサイズで割ってインデックス算出
		//【アサーション】メモリバッファの範囲外なら処理失敗（release関数内で失敗するのでそのまま実行）
		//ASSERT(index >= 0 && index < m_poolBlocksNum, "CPoolAllocator::free() cannot free. Pointer is different.");
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
		//ASSERT((m_blockSize & 0x3) == 0, "CPoolAllocator::CPoolAllocator() block size is invalid.");

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
	//CSpinLock m_lock;//ロック
};

//--------------------
//配置new
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw()
{
	printf("placement new(size=%d, pool_allocator.used=%d/%d/%d)\n", size, allocator.getBlocksNum(), allocator.getUsed(), allocator.getRemain());
	return allocator.alloc(size);
}
//配置delete
void operator delete(void* p, CPoolAllocator& allocator) throw()
{
	printf("placement delete(p=0x%p, pool_allocator.used=%d/%d/%d)\n", p, allocator.getBlocksNum(), allocator.getUsed(), allocator.getRemain());
	allocator.free(p);
}

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

//--------------------
//テスト用クラス
//__declspec(align(8))//8バイトアラインメントでテストする場合はこの行を有効にする
class CTest5
{
public:
	//デフォルトコンストラクタ
	CTest5() :
		CTest5("(default)")//他のコンストラクタ呼び出し（C++11で追加された仕様）
		//m_name("(default)")//C++11が使えない場合は普通に初期化
	{
		printf("CTest5::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CTest5(const char* name) :
		m_name(name)
	{
		printf("CTest5::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	~CTest5()
	{
		printf("CTest5::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};
//大きいクラス
class CTest5L
{
	char m_dummy[9];
};

//--------------------
//テスト
void test5()
{
	printf("---------- test5:プールアロケータ ----------\n");
	CPoolAllocatorWithType<CTest5, 5> pool;//プールアロケータ生成（sizeof(CTest5) * 5のバッファを確保）
	printf("buff=0x%p\n", pool.getBuff());
	{
		printf("-----\n");
		//createData() メソッドでインスタンスを生成
		//※任意のコンストラクタ引数も受け渡し可
		CTest5* obj1_p = pool.createData("テスト5-1");//createData()は、プールアロケータに定義したデータ型でインスタンスを生成する
		printf("obj1_p=0x%p\n", obj1_p);
		CTest5* obj2_p = pool.createData("テスト5-2");
		printf("obj2_p=0x%p\n", obj2_p);
		CTest5* obj3_p = pool.createData("テスト5-3");
		printf("obj3_p=0x%p\n", obj3_p);
		CTest5* obj4_p = pool.createData("テスト5-4");
		printf("obj4_p=0x%p\n", obj4_p);
		CTest5* obj5_p = pool.createData("テスト5-5");
		printf("obj5_p=0x%p\n", obj5_p);
		CTest5* obj6_p = pool.createData("テスト5-6");//【NG】個数オーバー
		printf("obj6_p=0x%p\n", obj6_p);
		//destroy() メソッドでインスタンスを破棄
		//※デストラクタ呼び出しに対応
		pool.destroyData(obj1_p);
		pool.destroyData(obj2_p);
		pool.destroyData(obj3_p);
		pool.destroyData(obj4_p);
		pool.destroyData(obj5_p);
		pool.destroyData(obj6_p);
	}
	{
		printf("-----\n");
		//sizeof(CTest5)以下のサイズの型なら何でも扱える
		CTest5L* obj_l_p = pool.create<CTest5L>();//【NG】定義時のクラスよりサイズが大きいクラス
		printf("obj_l_p=0x%p\n", obj_l_p);
		char* c_p = pool.create<char>();
		printf("c_p=0x%p\n", c_p);
		short* s_p = pool.create<short>();
		printf("s_p=0x%p\n", s_p);
		int* i_p = pool.create<int>();
		printf("i_p=0x%p\n", i_p);
		float* f_p = pool.create<float>();
		printf("f_p=0x%p\n", f_p);
		double* d_p = pool.create<double>();
		printf("d_p=0x%p\n", d_p);
		long long* ll_p = pool.create<long long>();//【NG】個数オーバー
		printf("ll_p=0x%p\n", ll_p);
		//destroy() メソッドはデストラクタがない型でも問題なし
		pool.destroy(obj_l_p);
		pool.destroy(c_p);
		pool.destroy(s_p);
		pool.destroy(i_p);
		pool.destroy(f_p);
		pool.destroy(d_p);
		pool.destroy(ll_p);
	}
}

//--------------------------------------------------------------------------------
//共通アロケータインターフェース

//--------------------
//メモリ確保時情報
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
#include <malloc.h>//malloc,_aligned_malloc用
#include <stdlib.h>//memalign用
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
	#ifdef USE_MEMALIGN
		return memalign(align, size);//GCC用：アラインメント指定版malloc
	#else//USE_MEMALIGN
		return _aligned_malloc(size, align);//MS仕様：アラインメント指定版malloc
	#endif//USE_MEMALIGN
	}
	//メモリ解放
	void free(void* p) override
	{
		if (!p)
			return;
	#ifdef USE_MEMALIGN
		::free(p);//通常free() ※memalignで確保したメモリもfreeで解放
	#else//USE_MEMALIGN
		_aligned_free(p);//MS仕様：アラインメント指定版free
	#endif//USE_MEMALIGN
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
//スタックアロケータアダプター
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
	IStackAllocator::E_ORDERED getOrdered() const { m_ordered; }//スタック順取得
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

//--------------------
//配置new
void* operator new(const std::size_t size, IAllocator& allocator) throw()
{
	printf("placement new(size=%d, i_allocator=\"%s\":%d/%d/%d)\n", size, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	void* p = allocator.alloc(size);
	printf("  p=0x%p\n", p);
	return p;
}
//配列版
void* operator new[](const std::size_t size, IAllocator& allocator) throw()
{
	printf("placement new[](size=%d, i_allocator=\"%s\":%d/%d/%d)\n", size, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	void* p = allocator.alloc(size);
	printf("  p=0x%p\n", p);
	return p;
}
//配置delete
void operator delete(void* p, IAllocator& allocator) throw()
{
	printf("placement delete(p=0x%p, i_allocator=\"%s\":%d/%d/%d)\n", p, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	allocator.free(p);
}
//配列版
void operator delete[](void* p, IAllocator& allocator) throw()
{
	printf("placement delete[](p=0x%p, i_allocator=\"%s\":%d/%d/%d)\n", p, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	allocator.free(p);
}
//デストラクタ呼び出し付きdelete
template<class T>
void delete_ptr(T*& p, IAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, i_allocator=\"%s\":%d/%d/%d)\n", p, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	if (!p)
		return;
	p->~T();//デストラクタ呼び出し
	operator delete(p, allocator);
	p = nullptr;//安全のためにポインタを初期化
}
//配列版
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, IAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, array_num=%d, i_allocator=\"%s\":%d/%d/%d)\n", p, array_num, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//デストラクタ呼び出し
	operator delete[](p, allocator);
	p = nullptr;//安全のためにポインタを初期化
}

//--------------------
//テスト用クラス
//__declspec(align(8))//8バイトアラインメントでテストする場合はこの行を有効にする
class CTest6
{
public:
	//デフォルトコンストラクタ
	CTest6() :
		CTest6("(default)")//他のコンストラクタ呼び出し（C++11で追加された仕様）
		//m_name("(default)")//C++11が使えない場合は普通に初期化
	{
		printf("CTest6::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CTest6(const char* name) :
		m_name(name)
	{
		printf("CTest6::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	virtual ~CTest6()
	{
		printf("CTest6::Destructor : name=\"%s\"\n", m_name);
	}
protected:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};
//--------------------
//テスト用クラス（多重継承テスト用）
class CTest6ex
{
public:
	//コンストラクタ
	CTest6ex()
	{
		printf("CTest6ex::Constructor\n");
	}
	//デストラクタ
	virtual ~CTest6ex()
	{
		printf("CTest6ex::Destructor\n");
	}
protected:
	//フィールド
	int m_dummy;//ダミー
};
//--------------------
//テスト用クラス（多重継承）
class CDerivedTest6 : public CTest6, public CTest6ex
{
public:
	//デフォルトコンストラクタ
	CDerivedTest6() :
		CTest6(),
		CTest6ex()
	{
		printf("CDerivedTest6::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CDerivedTest6(const char* name) :
		CTest6(name),
		CTest6ex()
	{
		printf("CDerivedTest6::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	~CDerivedTest6() override
	{
		printf("CDerivedTest6::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	int m_dummy;//ダミー
};

//--------------------
//テスト（共通関数）
//※実際のアロケータを切り替えて共通処理を実行するテスト
//クラス単体のテスト
void test6_sub1(const char* name, IAllocator& allocator)
{
	CTest6* obj_p = new(allocator)CTest6(name);
	printf("obj_p=0x%p\n", obj_p);
	delete_ptr(obj_p, allocator);
}
//クラスの配列のテスト
void test6_sub2(IAllocator& allocator)
{
	CTest6* obj_p = new(allocator)CTest6[3];
	printf("obj_p=0x%p\n", obj_p);
	delete_ptr(obj_p, 3, allocator);
}
//多重継承クラスのテスト
void test6_sub3(const char* name, IAllocator& allocator)
{
	CTest6ex* obj_p = new(allocator)CDerivedTest6(name);//アップキャスト
	printf("obj_p=0x%p\n", obj_p);
	delete_ptr(obj_p, allocator);
}
//--------------------
//テスト
void test6()
{
	printf("---------- test6:共通アロケータインターフェース ----------\n");
	//標準アロケータ（malloc / free）使用
	{
		printf("----------CStdAllocAdp\n");
		CStdAllocAdp allocator_adp;
		test6_sub1("テスト6-1a", allocator_adp);
		//test6_sub2(allocator_adp);//クラスの配列でずれたポインタをそのままfreeするのでハングする
		//test6_sub3("テスト6-1b", allocator_adp);//多重継承でずれたポインタをそのままfreeするのでハングする
	}
	//単一バッファアロケータ使用
	{
		printf("----------CMonoAllocAdp\n");
		CMonoAllocAdpWithBuff<128> allocator_adp;
		test6_sub1("テスト6-2a", allocator_adp);
		test6_sub2(allocator_adp);
		test6_sub3("テスト6-2b", allocator_adp);
	}
	//スタックアロケータ使用
	{
		printf("----------CStackAllocAdp\n");
		CStackAllocatorWithBuff<128> allocator;
		CStackAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-3a", allocator_adp);
		{
			//自動巻き戻しのテスト
			CStackAllocAdp allocator_adp_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test6_sub2(allocator_adp_tmp);
		}
		test6_sub3("テスト6-3b", allocator_adp);
	}
	//双方向スタックアロケータ使用
	{
		printf("----------CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<128> allocator;
		CDualStackAllocAdp allocator_adp(allocator, DSA_REVERSE);
		test6_sub1("テスト6-4a", allocator_adp);
		{
			//自動巻き戻しのテスト
			CDualStackAllocAdp allocator_adp_tmp(allocator, DSA_REVERSE, CIStackAllocAdp::AUTO_REWIND);
			test6_sub2(allocator_adp_tmp);
		}
		test6_sub3("テスト6-4b", allocator_adp);
	}
	//スタックアロケータをスタックアロケータインターフェースとして使用
	{
		printf("----------CIStackAllocAdp on CStackAllocAdp\n");
		CStackAllocatorWithBuff<128> allocator;
		CIStackAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-5a", allocator_adp);
		{
			//自動巻き戻しのテスト
			CIStackAllocAdp allocator_adp_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test6_sub2(allocator_adp_tmp);
		}
		test6_sub3("テスト6-5b", allocator_adp);
	}
	//双方向スタックアロケータをスタックアロケータインターフェースとして使用
	{
		printf("----------CIStackAllocAdp on CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<128> allocator;
		CIStackAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-6a", allocator_adp);
		{
			//自動巻き戻しのテスト
			CIStackAllocAdp allocator_adp_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test6_sub2(allocator_adp_tmp);
		}
		test6_sub3("テスト6-6b", allocator_adp);
	}
	//プールアロケータ使用
	{
		printf("----------CPoolAllocAdp\n");
		CPoolAllocatorWithBuff<24, 5> allocator;
		CPoolAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-7a", allocator_adp);
		test6_sub2(allocator_adp);
		test6_sub3("テスト6-7b", allocator_adp);
	}
}

//--------------------------------------------------------------------------------
//グローバルnew/delete + 共通アロケータインターフェース

//--------------------
//クラス宣言
class CTempPolyAllocatorBase;//一時多態アロケータ基底クラス

//--------------------
//多態アロケータ
class CPolyAllocator
{
#ifndef IS_NOT_FRIEND_WITH_NEW_OPERATOR
	//標準 new / deleete 演算子をフレンド化
	//※この CPolyAllocator クラスを直接インスタンス化するのは new / delete 演算子のみ
	friend void* operator new(const std::size_t size) throw();
	friend void* operator new[](const std::size_t size) throw();
	friend void operator delete(void* p) throw();
	friend void operator delete[](void* p) throw();
#endif//IS_NOT_FRIEND_WITH_NEW_OPERATOR
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
#ifdef IS_NOT_FRIEND_WITH_NEW_OPERATOR
public:
#else//IS_NOT_FRIEND_WITH_NEW_OPERATOR
private://直接インスタンス生成不可（フレンド専用）
#endif//IS_NOT_FRIEND_WITH_NEW_OPERATOR
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
//メモリ確保時情報
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

#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
extern const char* getFileName(const char* str);//関数参照：ファイル名取得関数（ディレクトリ部を除いた文字列を返す）
//--------------------
//グローバル多態アロケータ
//※標準new / delete 演算子の置き換え
//new
void* operator new(const std::size_t size) throw()
{
	CPolyAllocator allocator;
	printf("new(size=%d, poly_allocator=\"%s\":%d/%d/%d)\n", size, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();
	if (info)
	{
		align = info->m_align;
	#ifdef ENABLE_CONSTEXPR
		printf("  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\n", info->m_fileName, info->m_funcName, info->m_callPointName, info->m_time, info->m_typeName, info->m_align);
	#else//ENABLE_CONSTEXPR
		printf("  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\n", getFileName(info->m_fileName), info->m_funcName, info->m_callPointName, info->m_time, info->m_typeName, info->m_align);
	#endif//ENABLE_CONSTEXPR
	}
	void* p = allocator->alloc(size, align);
	printf("  p=0x%p\n", p);
	return p;
}
//配列版
void* operator new[](const std::size_t size) throw()
{
	CPolyAllocator allocator;
	printf("new[](size=%d, poly_allocator=\"%s\":%d/%d/%d)\n", size, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();
	if (info)
	{
		align = info->m_align;
	#ifdef ENABLE_CONSTEXPR
		printf("  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\n", info->m_fileName, info->m_funcName, info->m_callPointName, info->m_time, info->m_typeName, info->m_align);
	#else//ENABLE_CONSTEXPR
		printf("  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\n", getFileName(info->m_fileName), info->m_funcName, info->m_callPointName, info->m_time, info->m_typeName, info->m_align);
	#endif//ENABLE_CONSTEXPR
	}
	void* p = allocator->alloc(size, align);
	printf("  p=0x%p\n", p);
	return p;
}
//delete
void operator delete(void* p) throw()
{
	CPolyAllocator allocator;
	printf("delete(p=0x%p, poly_allocator=\"%s\":%d/%d/%d)\n", p, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	allocator->free(p);
}
//配列版
void operator delete[](void* p) throw()
{
	CPolyAllocator allocator;
	printf("delete[](p=0x%p, poly_allocator=\"%s\":%d/%d/%d)\n", p, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	allocator->free(p);
}
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2

//--------------------
//メモリ確保時情報の作成
//--------------------
//ダミー関数
const char* getCurrentCallPointNameDummy(){ return "(unknown call-point)"; }//コールポイント名取得
float getGameTimeDummy(){ return 0.f; }//ゲーム時間取得
//--------------------
//関数名作成マクロ
#include <string.h>
//【constexpr版】ファイル名取得関数（ディレクトリ部を除いた文字列を返す）
#ifdef ENABLE_CONSTEXPR
constexpr const char* getConstFileNameRecursive(const char* str, const std::size_t len)
{
	return len == 0 ?
	str :
		*(str + len - 1) == '\\' || *(str + len - 1) == '/' ?
			str + len :
			getConstFileNameRecursive(str, len - 1);
}
constexpr const char* getConstFileName(const char* str)
{
	return getConstFileNameRecursive(str, strlen(str));
}
#else//ENABLE_CONSTEXPR
//【通常版】ファイル名取得関数（ディレクトリ部を除いた文字列を返す）
const char* getFileName(const char* str)
{
	std::size_t len = strlen(str);
	const char* p = str + len;
	for (; len > 0; --len, --p)
	{
		const char c = *(p - 1);
		if (c == '\\' || c == '/')
			return p;
	}
	return str;
}
#endif//ENABLE_CONSTEXPR

//--------------------
//メモリ確保情報付きNEW処理
template<class T, typename... Tx>
T* newWithInfo(const char* file_name, const char* func_name, const std::size_t align, Tx ...nx)
{
	const char* call_point_name = getCurrentCallPointNameDummy();
	const float game_time = getGameTimeDummy();
	const ALLOC_INFO info(file_name, func_name, call_point_name, game_time, typeid(T).name(), align);
	CPolyAllocator::setAllocInfo(&info);
	return new T(nx...);
}
//配列版
template<class T, std::size_t array_size>
T* newArrayWithInfo(const char* file_name, const char* func_name, const std::size_t align)
{
	const char* call_point_name = getCurrentCallPointNameDummy();
	const float game_time = getGameTimeDummy();
	const ALLOC_INFO info(file_name, func_name, call_point_name, game_time, typeid(T[array_size]).name(), align);
	CPolyAllocator::setAllocInfo(&info);
	return new T[array_size];
}
//--------------------
//newマクロ補助マクロ
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)
#ifdef ENABLE_CONSTEXPR
#define GET_CONCATENATED_FILE_NAME() getConstFileName(__FILE__ "(" TO_STRING_EX(__LINE__) ") [" __TIMESTAMP__ "]")
#else//ENABLE_CONSTEXPR
#define GET_CONCATENATED_FILE_NAME() __FILE__ "(" TO_STRING_EX(__LINE__) ")  [" __TIMESTAMP__ "]"
#endif//ENABLE_CONSTEXPR
#define GET_FUNC_NAME() __PRETTY_FUNCTION__
//#define GET_FUNC_NAME() __FUNCTION__
//--------------------
//newマクロ
#ifdef USE_ALLOC_INFO
//※メモリ確保時情報付き
#define NEW(T, ...) newWithInfo<T>(GET_CONCATENATED_FILE_NAME(), GET_FUNC_NAME(), ALLOC_INFO::DEFAULT_ALIGN, __VA_ARGS__)
#define NEWALIGN(T, align, ...) newWithInfo<T>(GET_CONCATENATED_FILE_NAME(), GET_FUNC_NAME(), align, __VA_ARGS__)
#define NEWARR(T, array_size) newArrayWithInfo<T, array_size>(GET_CONCATENATED_FILE_NAME(), GET_FUNC_NAME(), ALLOC_INFO::DEFAULT_ALIGN)
#define NEWALIGNARR(T, align, array_size) newArrayWithInfo<T, array_size>(GET_CONCATENATED_FILE_NAME(), GET_FUNC_NAME(), align)
#define DELETE delete
#define DELETEARR delete[]
#else//USE_ALLOC_INFO
//※メモリ確保時情報なし
#define NEW(T, ...) new T(__VA_ARGS__)
#define NEWARR(T, array_size) new T[array_size]
#define DELETE delete
#define DELETEARR delete[]
#endif//USE_ALLOC_INFO

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
//--------------------
//一時多態アロケータクラス：単一バッファアロケータ用
using CTempPolyMonoAllocator = CTempPolyAllocatorDirect<CMonoAllocAdp>;//C++11形式
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
//--------------------
//一時多態アロケータクラス：プールアロケータ用
using CTempPolyPoolAllocator = CTempPolyAllocatorWithAdp<CPoolAllocAdp>;//C++11形式

//--------------------
//テスト用クラス
//__declspec(align(8))//8バイトアラインメントでテストする場合はこの行を有効にする
class CTest7
{
public:
	//デフォルトコンストラクタ
	CTest7() :
		CTest7("(default)")//他のコンストラクタ呼び出し（C++11で追加された仕様）
		//m_name("(default)")//C++11が使えない場合は普通に初期化
	{
		printf("CTest7::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CTest7(const char* name) :
		m_name(name)
	{
		printf("CTest7::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	virtual ~CTest7()
	{
		printf("CTest7::Destructor : name=\"%s\"\n", m_name);
	}
protected:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};
//--------------------
//テスト用クラス（多重継承テスト用）
class CTest7ex
{
public:
	//コンストラクタ
	CTest7ex()
	{
		printf("CTest7ex::Constructor\n");
	}
	//デストラクタ
	virtual ~CTest7ex()
	{
		printf("CTest7ex::Destructor\n");
	}
protected:
	//フィールド
	int m_dummy;//ダミー
};
//--------------------
//テスト用クラス（多重継承）
class CDerivedTest7 : public CTest7, public CTest7ex
{
public:
	//デフォルトコンストラクタ
	CDerivedTest7() :
		CTest7(),
		CTest7ex()
	{
		printf("CDerivedTest7::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CDerivedTest7(const char* name) :
		CTest7(name),
		CTest7ex()
	{
		printf("CDerivedTest7::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	~CDerivedTest7() override
	{
		printf("CDerivedTest7::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	int m_dummy;//ダミー
};

//--------------------
//テスト（共通関数）
//※先の共通アロケータインターフェースのテストと異なり、アダプターを受け取らず、そのまま new / deleteする
//※呼び出し元で、new / delete の実装を切り替えている
//クラス単体のテスト
void test7_sub1(const char* name)
{
#ifdef USE_NEW_MACRO
	CTest7* obj_p = NEW(CTest7, name);
	printf("obj_p=0x%p\n", obj_p);
	DELETE obj_p;
#else//USE_NEW_MACRO
	CTest7* obj_p = new CTest7(name);//配置newではなく、普通のnew演算子
	printf("obj_p=0x%p\n", obj_p);
	delete obj_p;//配置deleteではなく、普通のdelete演算子
#endif//USE_NEW_MACRO
}
//クラスの配列のテスト
void test7_sub2()
{
#ifdef USE_NEW_MACRO
	CTest7* obj_p = NEWARR(CTest7, 3);
	printf("obj_p=0x%p\n", obj_p);
	DELETEARR obj_p;
#else//USE_NEW_MACRO
	CTest7* obj_p = new CTest7[3];//配置newではなく、普通のnew[]演算子
	printf("obj_p=0x%p\n", obj_p);
	delete[] obj_p;//配置deleteではなく、普通のdelete[]演算子
#endif//USE_NEW_MACRO
}
//多重継承クラスのテスト
void test7_sub3(const char* name)
{
#ifdef USE_NEW_MACRO
	CTest7ex* obj_p = NEW(CDerivedTest7, name);//アップキャスト
	printf("obj_p=0x%p\n", obj_p);
	DELETE obj_p;
#else//USE_NEW_MACRO
	CTest7ex* obj_p = new CDerivedTest7(name);//配置newではなく、普通のnew演算子
	printf("obj_p=0x%p\n", obj_p);
	delete obj_p;//配置deleteではなく、普通のdelete演算子
#endif//USE_NEW_MACRO
}
//--------------------
//テスト
void test7()
{
	printf("---------- test7:グローバルnew/delete + 共通アロケータインターフェース ----------\n");
	//標準アロケータ（malloc / free）使用
	{
		printf("----------CStdAllocAdp\n");
		CTempPolyStdAllocator poly_allocator;
		test7_sub1("テスト7-1a");
		test7_sub2();//クラスの配列でずれたポインタは、delet[]演算子によって正しく処理されるため、問題が起こらない
		test7_sub3("テスト7-1b");//多重継承でずれたポインタは、delet演算子によって正しく処理されるため、問題が起こらない
	}
	//単一バッファアロケータ使用
	{
		printf("----------CMonoAllocAdp\n");
		CMonoAllocAdpWithBuff<128> allocator_adp;
		CTempPolyMonoAllocator poly_allocator(allocator_adp);
		test7_sub1("テスト7-2a");
		test7_sub2();
		test7_sub3("テスト7-2b");
	}
	//スタックアロケータ使用
	{
		printf("----------CStackAllocAdp\n");
		CStackAllocatorWithBuff<128> allocator;
		CTempPolyStackAllocator poly_allocator(allocator);
		test7_sub1("テスト7-3a");
		{
			//自動巻き戻しのテスト
			CTempPolyStackAllocator poly_allocator_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test7_sub2();
		}
		test7_sub3("テスト7-3b");
	}
	//双方向スタックアロケータ使用
	{
		printf("----------CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<128> allocator;
		CTempPolyDualStackAllocator poly_allocator(allocator, DSA_REVERSE);
		test7_sub1("テスト7-4a");
		{
			//自動巻き戻しのテスト
			CTempPolyDualStackAllocator poly_allocator_tmp(allocator, DSA_REVERSE, CIStackAllocAdp::AUTO_REWIND);
			test7_sub2();
		}
		test7_sub3("テスト7-4b");
	}
	//スタックアロケータをスタックアロケータインターフェースとして使用
	{
		printf("----------CIStackAllocAdp on CStackAllocAdp\n");
		CStackAllocatorWithBuff<128> allocator;
		CTempPolyIStackAllocator poly_allocator(allocator);
		test7_sub1("テスト7-5a");
		{
			//自動巻き戻しのテスト
			CTempPolyIStackAllocator poly_allocator_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test7_sub2();
		}
		test7_sub3("テスト7-5b");
	}
	//双方向スタックアロケータをスタックアロケータインターフェースとして使用
	{
		printf("----------CIStackAllocAdp on CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<128> allocator;
		CTempPolyIStackAllocator poly_allocator(allocator);
		test7_sub1("テスト7-6a");
		{
			//自動巻き戻しのテスト
			CTempPolyIStackAllocator poly_allocator_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test7_sub2();
		}
		test7_sub3("テスト7-6b");
	}
	//プールアロケータ使用
	{
		printf("----------CPoolAllocAdp\n");
		CPoolAllocatorWithBuff<24, 5> allocator;
		CTempPolyPoolAllocator poly_allocator(allocator);
		test7_sub1("テスト7-7a");
		test7_sub2();
		test7_sub3("テスト7-7b");
	}
}

//--------------------------------------------------------------------------------
//標準ライブラリを便利に活用

#include <string.h>//strcpy用
#include <string>//std::string用

//--------------------
//CRC算出関数
typedef unsigned int crc32_t;//CRC32型
namespace crc_inner_calc//直接使用しない処理を隠ぺいするためのネームスペース
{
#ifndef USE_CRC_CALC_TABLE
	//CRC生成多項式計算（再帰処理）
	constexpr crc32_t calcPoly(crc32_t poly, const int n)
	{
		return n == 0 ? poly : calcPoly(poly & 1 ? 0xedb88320u ^ (poly >> 1) : (poly >> 1), n - 1);
	}
#else//USE_CRC_CALC_TABLE
	//CRC生成多項式計算計算済みテーブル
	static constexpr crc32_t s_calcTable[] =
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
	//文字列からCRC算出用（再帰処理）
	constexpr crc32_t calcStr(const crc32_t crc, const char* str)
	{
	#ifndef USE_CRC_CALC_TABLE
		return *str == '\0' ? crc : calcStr(calcPoly(static_cast<crc32_t>((crc ^ *str) & 0xffu), 8) ^ (crc >> 8), str + 1);//CRC生成多項式計算計算を合成
	#else//USE_CRC_CALC_TABLE
		return *str == '\0' ? crc : calcStr(s_calcTable[(crc ^ *str) & 0xffu] ^ (crc >> 8), str + 1);//CRC生成多項式計算計算済みテーブルの値を合成
	#endif//USE_CRC_CALC_TABLE
	}
	//データ長を指定してからCRC算出用（再帰処理）
	constexpr crc32_t calcData(const crc32_t crc, const char* data, const int len)
	{
	#ifndef USE_CRC_CALC_TABLE
		return len == 0 ? crc : calcData(calcPoly(static_cast<crc32_t>((crc ^ *data) & 0xffu), 8) ^ (crc >> 8), data + 1, len - 1);//CRC生成多項式計算計算を合成
	#else//USE_CRC_CALC_TABLE
		return len == 0 ? crc : calcData(s_calcTable[(crc ^ *data) & 0xffu] ^ (crc >> 8), data + 1, len - 1);//CRC生成多項式計算計算済みテーブルの値を合成
	#endif//USE_CRC_CALC_TABLE
	}
}
//文字列からCRC算出用
constexpr crc32_t calcCRC32(const char* str)
{
	return ~crc_inner_calc::calcStr(~0u, str);
}
//データ長を指定してCRC算出
constexpr crc32_t calcCRC32(const char* str, const int len)
{
	return ~crc_inner_calc::calcData(~0u, str, len);
}
#ifdef ENABLE_USER_DEFINED_LITERALS
//ユーザー定義リテラル
constexpr crc32_t operator "" _crc32(const char* str, std::size_t len)
{
	return calcCRC32(str, len);
}
#endif//ENABLE_USER_DEFINED_LITERALS

//--------------------
//標準ライブラリを利用した固定バッファハッシュテーブルクラス
#include <unordered_map>//C++11ハッシュテーブル
class CTest8
{
public:
	//型
	//データ型
	struct DATA
	{
		char m_name[20];//名前
		int m_age;//年齢
		DATA(const char* name, const int age)
		{
		#ifdef USE_STRCPY_S
			strcpy_s(m_name, sizeof(m_name), name);
		#else//USE_STRCPY_S
			strcpy(m_name, name);
		#endif//USE_STRCPY_S
			m_age = age;
		}
	};
public:
	//メソッド
	//データ追加
	void addData(const DATA& data)
	{
		printf("CTest8::addData()\n");
		CTempPolyStackAllocator poly_allocator(m_stack);
		m_table->insert(std::make_pair(calcCRC32(data.m_name), data));
	}
	//データ参照
	const DATA* find(const crc32_t name_crc) const
	{
		printf("CTest8::find()\n");
		//CTempPolyStackAllocator poly_allocator(m_stack);//不要
		const auto& obj = m_table->find(name_crc);
		if (obj == m_table->cend())
			return nullptr;
		return &obj->second;
	}
	const DATA* find(const char* name) const
	{
		return find(calcCRC32(name));
	}
public:
	//コンストラクタ
	CTest8()
	{
		printf("CTest8::Consructor()\n");
		CTempPolyStackAllocator poly_allocator(m_stack);
		printf("new unordered_map\n");
		m_table = new std::unordered_map<crc32_t, DATA>();
		printf("unordered_map::reserve\n");
		m_table->reserve(10);
		printf("--\n");
	}
	//デストラクタ
	~CTest8()
	{
		printf("CTest8::Destructor()\n");
		CTempPolyStackAllocator poly_allocator(m_stack);
		printf("delete unordered_map\n");
		delete m_table;
		printf("--\n");
	}
private:
	//フィールド
	std::unordered_map<crc32_t, DATA>* m_table;//データテーブル
	CStackAllocatorWithBuff<1024> m_stack;//スタックアロケータ
};

//--------------------
//テスト
void test8()
{
	printf("---------- test8:標準ライブラリを便利に利用 ----------\n");
	{
		printf("----------CStackAllocAdp\n");
		char str_buff[128];
		CStackAllocatorWithBuff<1024> allocator;
		CTempPolyStackAllocator poly_allocator(allocator);
		{
			std::string str1 = "文字列と";
			std::string str2 = "文字列を";
			std::string str3 = "結合するような処理では、";
			std::string str4 = "std::stringが";
			std::string str5 = "やっぱり便利!!";
			std::string str = str1 + str2 + str3 + str4 + str5;
		#ifdef USE_STRCPY_S
			strcpy_s(str_buff, sizeof(str_buff), str.c_str());
		#else//USE_STRCPY_S
			strcpy(str_buff, str.c_str());
		#endif//USE_STRCPY_S
		}
		printf("str_buff=\"%s\"\n", str_buff);
	}
	{
		printf("----------CStdAllocAdp\n");
		char str_buff[128];
		{
			std::string str1 = "文字列と";
			std::string str2 = "文字列を";
			std::string str3 = "結合するような処理では、";
			std::string str4 = "std::stringが";
			std::string str5 = "やっぱり便利!!";
			std::string str = str1 + str2 + str3 + str4 + str5;
		#ifdef USE_STRCPY_S
			strcpy_s(str_buff, sizeof(str_buff), str.c_str());
		#else//USE_STRCPY_S
			strcpy(str_buff, str.c_str());
		#endif//USE_STRCPY_S
		}
		printf("str_buff=\"%s\"\n", str_buff);
	}
	{
		CStackAllocatorWithBuff<8192> allocator;
		CTempPolyStackAllocator poly_allocator(allocator);
		{
			printf("----------CTest8\n");
			CTest8::DATA data1("太郎", 40);
			CTest8::DATA data2("次郎", 30);
			CTest8::DATA data3("三郎", 20);
			printf("new CTest8\n");
			CTest8* table = new CTest8();
			table->addData(data1);
			table->addData(data2);
			table->addData(data3);
			const CTest8::DATA* ref1 = table->find("太郎");
			const CTest8::DATA* ref2 = table->find("次郎");
			const CTest8::DATA* ref3 = table->find("三郎");
			if (ref1) printf("ref1: name=\"%s\", age=%d\n", ref1->m_name, ref1->m_age);
			if (ref2) printf("ref2: name=\"%s\", age=%d\n", ref2->m_name, ref2->m_age);
			if (ref3) printf("ref3: name=\"%s\", age=%d\n", ref3->m_name, ref3->m_age);
			printf("delete CTest8\n");
			delete table;
			printf("----------CTest8:End\n");
		}
	}
}

//--------------------------------------------------------------------------------
//マルチスレッドで便利なスタックアロケータ

#include <thread>//C++11スレッド
#include <atomic>//C++11アトミック型

//----------------------------------------
//スレッドIDクラス
//※IDをハッシュ化した場合、TLSを活用して高速化

//スレッドID型
#define THREAD_ID_IS_HASH//スレッドIDをハッシュ型で扱う場合はこのマクロを有効化する（ハッシュの方が高速）
#ifdef THREAD_ID_IS_HASH
typedef std::size_t THREAD_ID;//(ハッシュ)
static const THREAD_ID INVALID_THREAD_ID = std::hash<std::thread::id>()(std::thread::id());//無効なスレッドID(ハッシュ)
static const THREAD_ID INITIAL_THREAD_ID = static_cast<THREAD_ID>(~0);//初期スレッドID(ハッシュ)
#else//THREAD_ID_IS_HASH
typedef std::thread::id THREAD_ID;
static const THREAD_ID INVALID_THREAD_ID = std::thread::id();//無効なスレッドID
#endif//THREAD_ID_IS_HASH

//現在のスレッドID取得関数
#ifdef THREAD_ID_IS_HASH
inline THREAD_ID GetThisThreadID(){ return std::hash<std::thread::id>()(std::this_thread::get_id()); }//(ハッシュ)
#else//THREAD_ID_IS_HASH
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id(); }
#endif//THREAD_ID_IS_HASH

//スレッドIDクラス
class CThreadID
{
public:
	//アクセッサ
	const THREAD_ID getID() const { return m_threadId; }//スレッドIDを取得
	const char* getName() const { return m_threadName; }//スレッド名を取得
public:
	//アクセッサ（static）
#ifdef THREAD_ID_IS_HASH
	static THREAD_ID getThisID(){ return m_thisThreadID; }//現在のスレッドのスレッドIDを取得(ハッシュ)
#else//THREAD_ID_IS_HASH
	static THREAD_ID getThisID(){ return GetThisThreadID(); }//現在のスレッドのスレッドIDを取得
#endif//THREAD_ID_IS_HASH
	static const char* getThisName(){ return m_thisThreadName; }//現在のスレッドのスレッド名を取得
public:
	//メソッド
	bool isThisThread() const { return m_threadId == getThisID(); }//現在のスレッドと同じスレッドか判定
private:
	//メソッド(static)
	static void setThisThread()//現在のスレッドのスレッドIDをセット
	{
	#ifdef THREAD_ID_IS_HASH
		if (m_thisThreadID == INITIAL_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
	#endif//THREAD_ID_IS_HASH
	}
	static void resetThisThread(const char* name)//現在のスレッドのスレッドIDをリセット
	{
	#ifdef THREAD_ID_IS_HASH
		m_thisThreadID = GetThisThreadID();
	#endif//THREAD_ID_IS_HASH
		m_thisThreadName = name;
	}
public:
	//オペレータ（許可）
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID一致判定
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID不一致判定
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID一致判定
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID不一致判定
	CThreadID& operator=(const CThreadID& o)//コピー演算子
	{
		m_threadId = o.m_threadId;
		m_threadName = o.m_threadName;
		return *this;
	}
private:
	//オペレータ（禁止）
	CThreadID& operator=(const THREAD_ID& id) { return *this; }//コピー演算子（禁止）
public:
	//コピーコンストラクタ（許可）
	explicit CThreadID(const CThreadID& o) :
		m_threadId(o.m_threadId),
		m_threadName(o.m_threadName)
	{
	}
private:
	//コピーコンストラクタ（禁止）
	explicit CThreadID(const THREAD_ID& id){}
public:
	//コンストラクタ
	//※スレッド名を指定し、内部で現在のスレッドIDを取得して保持
	//※TLSにも記録
	CThreadID(const char* name)
	{
		resetThisThread(name);
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
	//デフォルトコンストラクタ
	//※既にTLSに記録済みのスレッドID（と名前）を取得
	CThreadID()
	{
		setThisThread();
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
private:
	//フィールド
	THREAD_ID m_threadId;//スレッドID（オブジェクトに保存する値）
	const char* m_threadName;//スレッド名（オブジェクトに保存する値）
#ifdef THREAD_ID_IS_HASH
	static thread_local THREAD_ID m_thisThreadID;//現在のスレッドのスレッドID(TLS)
#endif//THREAD_ID_IS_HASH
	static thread_local const char* m_thisThreadName;//現在のスレッド名(TLS)
};
//static変数のインスタンス化
#ifdef THREAD_ID_IS_HASH
thread_local THREAD_ID CThreadID::m_thisThreadID = INITIAL_THREAD_ID;//スレッドID(TLS)
#endif//THREAD_ID_IS_HASH
thread_local const char* CThreadID::m_thisThreadName = nullptr;//スレッド名(TLS)

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

//--------------------
//スマートスタックアロケータクラス
//※非スレッドセーフ（処理速度優先）
//※インターフェースを実装するが、高速化のために virtualメソッドに頼らず操作可能
class CSmartStackAllocator : public IStackAllocator
{
public:
	//型
	typedef int counter_t;//カウンター型
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
	marker_t getCounterN() const { return m_counterN.load(); }//メモリ確保カウンター（正順）を取得
	marker_t getCounterR() const { return m_counterR.load(); }//メモリ確保カウンター（逆順）を取得
	marker_t getCounterD() const { return getCounter(m_defaultOrdered.load()); }//メモリ確保カウンターを取得
	marker_t getCounter(const E_ORDERED ordered) const { return ordered == DEFAULT ? getCounterD() : ordered == REVERSE ? getCounterR() : getCounterN(); }//メモリ確保カウンターを取得
	marker_t getCounter() const { return getCounterD(); }//メモリ確保カウンターを取得
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
		if (now_r > m_beginR.load() || now_r < m_usedR.load())
			return;
		//ポインタが逆順スタックとして適正のため、処理開始
		m_lock.lock();//ロック取得
		if (m_counterR.load() <= 0 || now_r > m_beginR.load() || now_r < m_usedR.load())//範囲の再チェック
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
		freeN(p);
		freeR(p);
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始（正順）
	//※メモリ確保カウンターをリセット
	void beginN()
	{
		m_lock.lock();//ロック取得
		m_beginN.store(m_usedN.load());
		m_counterN.store(0);
		m_lock.unlock();//ロック解放
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始（逆順）
	//※メモリ確保カウンターをリセット
	void beginR()
	{
		m_lock.lock();//ロック取得
		m_beginR.store(m_usedR.load());
		m_counterR.store(0);
		m_lock.unlock();//ロック解放
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始 
	//※メモリ確保カウンターをリセット
	void beginD()
	{
		begin(m_defaultOrdered.load());
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始 
	//※メモリ確保カウンターをリセット
	void begin(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? beginD() : ordered == REVERSE ? beginR() : beginN();
	}
	//マーカー位置を記憶してメモリ確保のカウントを開始 
	//※メモリ確保カウンターをリセット
	void begin()
	{
		beginD();
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す（正順）
	//※開始マーカーとメモリ確保カウンターもリセットする
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
	//※開始マーカーとメモリ確保カウンターもリセットする
	//※ポインタ指定版
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す（逆順）
	//※開始マーカーとメモリ確保カウンターもリセットする
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
	//※開始マーカーとメモリ確保カウンターもリセットする
	//※ポインタ指定版
	void backR(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backR(marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンターもリセットする
	//※マーカー指定版
	void backD(const marker_t marker)
	{
		back(m_defaultOrdered.load(), marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンターもリセットする
	//※ポインタ指定版
	void backD(const void* p)
	{
		back(m_defaultOrdered.load(), p);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンターもリセットする
	//※マーカー指定版
	void back(const E_ORDERED ordered, const marker_t marker)
	{
		ordered == DEFAULT ? backD(marker) : ordered == REVERSE ? backR(marker) : backN(marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンターもリセットする
	//※ポインタ指定版
	void back(const E_ORDERED ordered, const void* p)
	{
		ordered == DEFAULT ? backD(p) : ordered == REVERSE ? backR(p) : backN(p);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンターもリセットする
	//※マーカー指定版
	void back(const marker_t marker) override
	{
		backD(marker);
	}
	//【このクラスでは非推奨メソッド】
	//メモリを以前のマーカーに戻す
	//※開始マーカーとメモリ確保カウンターもリセットする
	//※ポインタ指定版
	void back(const void* p) override
	{
		backD(p);
	}
	//メモリ破棄（正順）
	//※開始マーカーとメモリ確保カウンターもリセットする
	void clearN()
	{
		m_lock.lock();//ロック取得
		m_usedN.store(0);
		m_beginN.store(0);
		m_counterN.store(0);
		m_lock.unlock();//ロック解放
	}
	//メモリ破棄（逆順）
	//※開始マーカーとメモリ確保カウンターもリセットする
	void clearR()
	{
		m_lock.lock();//ロック取得
		m_usedR.store(m_buffSize);
		m_beginR.store(0);
		m_counterR.store(0);
		m_lock.unlock();//ロック解放
	}
	//メモリ破棄
	//※開始マーカーとメモリ確保カウンターもリセットする
	void clearD()
	{
		clear(m_defaultOrdered.load());
	}
	//メモリ破棄（両方）
	//※開始マーカーとメモリ確保カウンターもリセットする
	void clearNR()
	{
		clearN();
		clearR();
	}
	//メモリ破棄
	//※開始マーカーとメモリ確保カウンターもリセットする
	void clear(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? clearD() : ordered == REVERSE ? clearR() : clearN();
	}
	//メモリ破棄
	//※開始マーカーとメモリ確保カウンターもリセットする
	void clear() override
	{
		clearD();
	}
	//メモリ破棄（全て）
	//※開始マーカーとメモリ確保カウンターもリセットする
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
		m_counterN.store(0);//メモリ確保カウンター（正順）
		m_counterR.store(0);//メモリ確保カウンター（逆順）
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
	std::atomic<counter_t> m_counterN;//メモリ確保カウンター（正順）
	std::atomic<counter_t> m_counterR;//メモリ確保カウンター（逆順）
	std::atomic<E_ORDERED> m_defaultOrdered;//デフォルトのスタック順
	CSpinLock m_lock;//ロック
};

#if 0//使わない
//--------------------
//配置new/配置delete
//※メモリ使用状況を確認するためにマーカーを表示
//配置new
void* operator new(const std::size_t size, CSmartStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, smart_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new(const std::size_t size, CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, smart_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//配列版
void* operator new[](const std::size_t size, CSmartStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, smart_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new[](const std::size_t size, CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, smart_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//配置delete
void operator delete(void* p, CSmartStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, smart_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	allocator.free(p);
}
void operator delete(void* p, CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, smart_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	allocator.free(p);
}
//配列版
void operator delete[](void* p, CSmartStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered) throw()
{
	printf("placement delete[](p=0x%p, smart_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	allocator.free(p);
}
void operator delete[](void* p, CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement delete[](p=0x%p, smart_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	allocator.free(p);
}
//デストラクタ呼び出し付きdelete
template<class T>
void delete_ptr(T*& p, CSmartStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, smart_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	if (!p)
		return;
	p->~T();//デストラクタ呼び出し
	operator delete(p, allocator, IStackAllocator::DEFAULT);
	p = nullptr;//安全のためにポインタを初期化
}
//配列版
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CSmartStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, array_num=%d, smart_allocator.marker=%d,%d)\n", p, array_num, allocator.getMarkerN(), allocator.getMarkerR());
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//デストラクタ呼び出し
	operator delete[](p, allocator, IStackAllocator::DEFAULT);
	p = nullptr;//安全のためにポインタを初期化
}
#endif

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
	IStackAllocator::E_ORDERED getOrdered() const { m_ordered; }//スタック順取得
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
	CSmartStackAllocAdp() = delete;
	//コンストラクタ
	//※自動巻き戻しには対応しない
	CSmartStackAllocAdp(CSmartStackAllocator& stack, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) :
		CIStackAllocAdp(stack, NOREWIND),//双方向スタックアロケータ
		m_ordered(ordered)//スタック順
	{}
	//デストラクタ
	~CSmartStackAllocAdp() override
	{}
private:
	//フィールド
	IStackAllocator::E_ORDERED m_ordered;//スタック順
};

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

//--------------------
//テスト用クラス
//__declspec(align(8))//8バイトアラインメントでテストする場合はこの行を有効にする
class CTest9
{
public:
	//デフォルトコンストラクタ
	CTest9() :
		CTest9("(default)")//他のコンストラクタ呼び出し（C++11で追加された仕様）
		//m_name("(default)")//C++11が使えない場合は普通に初期化
	{
		printf("CTest9::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//コンストラクタ
	CTest9(const char* name) :
		m_name(name)
	{
		printf("CTest9::Constructor : name=\"%s\"\n", m_name);
	}
	//デストラクタ
	virtual ~CTest9()
	{
		printf("CTest9::Destructor : name=\"%s\"\n", m_name);
	}
protected:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};

//--------------------
//スレッドテスト
#include <thread>//C++11スレッド
#include <chrono>//C++11時間
//スマートスタックアロケータ
static CSmartStackAllocatorWithBuff<1024> s_stackForThread;
void test9thread_n(const char* name)
{
	CTempPolySmartStackAllocator poly_allocator(s_stackForThread, DSA_NORMAL);//多態アロケータをスマートスタック（正順）に設定
	CTest9* obj_p = new CTest9(name);
	std::this_thread::sleep_for(std::chrono::seconds(1));//1秒スリープ
	delete obj_p;
}
void test9thread_r(const char* name)
{
	CTempPolySmartStackAllocator poly_allocator(s_stackForThread, DSA_REVERSE);//多態アロケータをスマートスタック（逆順）に設定
	CTest9* obj_p = new CTest9(name);
	std::this_thread::sleep_for(std::chrono::seconds(1));//1秒スリープ
	delete obj_p;
}
//--------------------
//テスト
void test9()
{
	printf("---------- test9:マルチスレッドに便利なスマートスタックアロケータ ----------\n");
	{
		printf("----------基本動作チェック\n");
		CSmartStackAllocatorWithBuff<128> allocator;
		CTempPolySmartStackAllocator poly_allocator(allocator);
		CTest9* obj1_p = new CTest9("テスト9-1");
		printf("obj1_p=0x%p\n", obj1_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		printf("beginN()\n");
		allocator.beginN();
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_REVERSE);
		CTest9* obj2_p = new CTest9("テスト9-2");
		printf("obj2_p=0x%p\n", obj2_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		printf("beginR()\n");
		allocator.beginR();
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_NORMAL);
		CTest9* obj3_p = new CTest9("テスト9-3");
		printf("obj3_p=0x%p\n", obj3_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_REVERSE);
		CTest9* obj4_p = new CTest9("テスト9-4");
		printf("obj4_p=0x%p\n", obj4_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj1_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj2_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj3_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj4_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_NORMAL);
		CTest9* obj5_p = new CTest9("テスト9-5");
		printf("obj5_p=0x%p\n", obj5_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_REVERSE);
		CTest9* obj6_p = new CTest9("テスト9-6");
		printf("obj6_p=0x%p\n", obj6_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj5_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj6_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		printf("clearN()\n");
		allocator.clearN();
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		printf("clearR()\n");
		allocator.clearR();
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
	}
	{
		printf("----------スレッド使用チェック\n");
		//【想定】スレッド開始前に、同じバッファを他の用途に少し使う
		//　　　　（これは常駐するデータで破棄しないものとする）
		int* parmanent_data1 = nullptr;
		char* parmanent_data2 = nullptr;
		float* parmanent_data3 = nullptr;
		{
			CTempPolySmartStackAllocator poly_allocator(s_stackForThread, DSA_NORMAL);//多態アロケータをスマートスタック（正順）に設定
			parmanent_data1 = new int[2];
			parmanent_data2 = new char[3];
			parmanent_data3 = new float[4];
		}
		unsigned int* parmanent_data4 = nullptr;
		unsigned char* parmanent_data5 = nullptr;
		double* parmanent_data6 = nullptr;
		{
			CTempPolySmartStackAllocator poly_allocator(s_stackForThread, DSA_REVERSE);//多態アロケータをスマートスタック（逆順）に設定
			parmanent_data4 = new unsigned int[5];
			parmanent_data5 = new unsigned char[6];
			parmanent_data6 = new double[7];
		}
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());

		//カウント開始（自動リセット位置を更新）
		//ここまでの情報を保護し、以降使用するメモリは、全て解放された時点で
		//マーカーを自動的に戻す
		printf("beginN()\n");
		s_stackForThread.beginN();//正順メモリ確保のカウントを開始
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
		printf("beginR()\n");
		s_stackForThread.beginR();//逆順メモリ確保のカウントを開始
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());

		//スレッド開始①
		{
			std::thread th1 = std::thread(test9thread_n, "スレッドテスト9-1(N)");
			std::thread th2 = std::thread(test9thread_n, "スレッドテスト9-2(N)");
			std::thread th3 = std::thread(test9thread_r, "スレッドテスト9-3(R)");
			std::thread th4 = std::thread(test9thread_r, "スレッドテスト9-4(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(500));//500msecスリープ
			printf("sleep(500msec)\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			th1.join();
			th2.join();
			th3.join();
			th4.join();
			printf("join\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
		}

		//スレッド開始②
		{
			std::thread th5 = std::thread(test9thread_n, "スレッドテスト9-5(N)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msecスリープ
			printf("sleep(200msec)\n");
			std::thread th6 = std::thread(test9thread_n, "スレッドテスト9-6(N)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msecスリープ
			printf("sleep(200msec)\n");
			std::thread th7 = std::thread(test9thread_r, "スレッドテスト9-7(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msecスリープ
			printf("sleep(200msec)\n");
			std::thread th8 = std::thread(test9thread_r, "スレッドテスト9-8(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msecスリープ
			printf("sleep(200msec)\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			{
				//途中で多態アロケータはTLSでアロケータをスレッドごとに分けて使っているので、
				//他のスレッドが動作中に異なるアロケータを使っても問題なし
				CSmartStackAllocatorWithBuff<128> allocator;
				CTempPolySmartStackAllocator poly_allocator(allocator);
				CTest9* obj_p = new CTest9("スレッドテスト(割り込み)");
				delete obj_p;
				printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			}
			std::thread th9 = std::thread(test9thread_n, "スレッドテスト9-9(N)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msecスリープ
			printf("sleep(200msec)\n");
			std::thread th10 = std::thread(test9thread_n, "スレッドテスト9-10(N)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msecスリープ
			printf("sleep(200msec)\n");
			std::thread th11 = std::thread(test9thread_r, "スレッドテスト9-11(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msecスリープ
			printf("sleep(200msec)\n");
			std::thread th12 = std::thread(test9thread_r, "スレッドテスト9-12(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msecスリープ
			printf("sleep(200msec)\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			th5.join();
			th6.join();
			th7.join();
			th8.join();
			th9.join();
			th10.join();
			th11.join();
			th12.join();
			printf("join\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
		}

		{
			//カウント開始前に確保したメモリを破棄しても何の影響もない
			CTempPolySmartStackAllocator poly_allocator(s_stackForThread);
			delete parmanent_data1;
			delete parmanent_data2;
			delete parmanent_data3;
			delete parmanent_data4;
			delete parmanent_data5;
			delete parmanent_data6;
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
		}
	}
}

//--------------------------------------------------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	printf("---------- main:start ----------\n");
	test0();
	test1();
	test2();
	test3();
	test4a();
	test4b();
	test5();
	test6();
	test7();
	test8();
	test9();
	printf("---------- main:end ----------\n");
	return EXIT_SUCCESS;
}

// End of file
