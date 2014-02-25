//コンパイルスイッチ
#define USE_NEW_PTR_FOR_TEST0//test0で、new_ptr関数を使用する時はこのマクロを有効にする
#define USE_DELETE_PTR_FOR_TEST0//test0で、delete_ptr関数を使用する時はこのマクロを有効にする
#define USE_DESTRUCTOR_FOR_TEST1//test1で、デストラクタを使用するときはこのマクロを有効にする（アロケートサイズが増えることを確認できる）
//#define USE_GLOBAL_NEW_DELETE_FOR_TEST2//test2で、クラス内new/deleteをグローバルnew/deleteに変更する時はこのマクロを有効にする
#define USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2//test2で、クラス内deleteをsize引数付きのものにする時はこのマクロを有効にする
#define USE_DESTRUCTOR_FOR_TEST2//test2で、デストラクタを使用する時はこのマクロを有効にする（アロケートサイズが増えることを確認できる）
//#define USE_NAMESPACE_NEW_DELETE_FOR_TEST2//test2で、ネームスペースに定義したnew/deleteのテストを行う時はこのマクロを有効にする
#define USE_CRC_CALC_TABLE//test8で、CRC計算の際に、事前計算済みのCRC計算テーブルを使用するならこのマクロを有効にする

//GCC関連：GCC使用時はこれらのマクロを有効化する
#define USE_MEMALIGN//【GCC用】test6以降で、memalignを使用する時はこのマクロを有効にする
#define IS_NOT_FRIEND_NEW_OPERATOR_FOR_TEST7//【GCC用】test7以降で、オペレータnew/deleteをフレンド宣言しない時はこのマクロを有効にする
#define TLS_IS_POSIX//【GCC用】TLSの宣言をPOSIXスタイルにする時はこのマクロを有効にする

//C++11関連：サンプルプログラムには、これら以外にもC++11の要素が膨れている
//これらのマクロは、Visual C++環境やC++0x環境でコンパイルするために使用する
#define ENABLE_NULLPTR//【C++11用】nullptrを有効にする時はこのマクロを有効にする
#define ENABLE_OVERRIDE//【C++11用】overrideを有効にする時はこのマクロを有効にする
#define ENABLE_CONSTEXPR//【C++11用】constexprを有効にする時はこのマクロを有効にする
#define ENABLE_USER_DEFINED_LITERALS//【C++11用】ユーザー定義リテラルを有効にする時はこのマクロを有効にする

//MS固有仕様関連
//#define USE_STRCPY_S//【MS固有仕様】strcpy_sを使用する時にこのマクロを有効にする

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>//uintptr_t,intptr_t用
#include <limits.h>//INT_MAX用
#include <new>//規定の配置new/配置delete用

//スレッドローカルストレージ修飾子
//※C++11仕様偽装（VC++2013では未対応につき）
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
	static void* operator new(const std::size_t) throw() { return m_singletonBuff; }//new演算子
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
public:
	//型
	typedef unsigned char byte;//バッファ用
	typedef std::size_t marker_t;//スタックマーカー型
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

//--------------------
//スタックアロケータクラス
//※非スレッドセーフ（処理速度優先）
//※インターフェースを実装するが、高速化のために virtualメソッドに頼らず操作可能
class CStackAllocator : public IStackAllocator
{
public:
	//型
	typedef unsigned char byte;//バッファ用
	typedef std::size_t marker_t;//スタックマーカー型
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
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_used;//現在のポインタ位置算出
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//アラインメント計算
		const std::size_t next_used = m_used + align_diff + size;//次のマーカー算出
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
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
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
	//定数
	enum E_ORDERED
	{
		DEFAULT = 0,//デフォルト
		NORMAL = 1,//正順
		REVERSE = -1,//逆順
	};
public:
	//アクセッサ
	std::size_t getTotal() const override { return m_buffSize; }//全体のメモリ量を取得
	std::size_t getUsed() const override { return m_usedN + m_buffSize - m_usedR; }//使用中のメモリ量を取得
	std::size_t getRemain() const override { return m_usedR - m_usedN; }//残りのメモリ量を取得
	E_ORDERED getDefaultOrdered() const { return m_defaultOrdered; }//デフォルトのスタック順を取得
	void setDefaultOrdered(const E_ORDERED ordered){ m_defaultOrdered = ordered; }//デフォルトのスタック順を更新
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
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_usedN;//現在のポインタ位置算出
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//アラインメント計算
		const std::size_t next_used = m_usedN + align_diff + size;//次のマーカー算出
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
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_usedR;//現在のポインタ位置算出
		const uintptr_t alloc_ptr_tmp = now_ptr - size;//メモリ確保アドレス算出（暫定）
		const uintptr_t align_diff = align > 0 ? alloc_ptr_tmp % align == 0 ? 0 : alloc_ptr_tmp % align : 0;//アラインメント計算
		const std::size_t next_used = m_usedR - size - align_diff;//次のマーカー算出
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
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//メモリを以前のマーカーに戻す（逆順）
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
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
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
		m_usedR(buff_size),//マーカー（逆順）
		m_defaultOrdered(default_ordered)//デフォルトのスタック順
	{
		if (m_defaultOrdered != REVERSE)
			m_defaultOrdered = NORMAL;//デフォルトのスタック順を補正
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
//定数のエイリアス
static const CDualStackAllocator::E_ORDERED DSA_DEFAULT = CDualStackAllocator::DEFAULT;//デフォルト
static const CDualStackAllocator::E_ORDERED DSA_NORMAL = CDualStackAllocator::NORMAL;//正順
static const CDualStackAllocator::E_ORDERED DSA_REVERSE = CDualStackAllocator::REVERSE;//逆順

//--------------------
//配置new/配置delete
//※メモリ使用状況を確認するためにマーカーを表示
//配置new
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const std::size_t align, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//配列版
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const std::size_t align, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//配置delete
void operator delete(void* p, CDualStackAllocator& allocator, const std::size_t align, const CDualStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) は実行しない
}
void operator delete(void* p, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) は実行しない
}
//配列版
void operator delete[](void* p, CDualStackAllocator& allocator, const std::size_t align, const CDualStackAllocator::E_ORDERED ordered) throw()
{
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) は実行しない
}
void operator delete[](void* p, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered) throw()
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

#include <atomic>//アトミック型

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
		//使用中ブロック数判定はロックの範囲外で行う
		if (m_used.load() >= m_poolBlocksNum)
			return INVALID_INDEX;//空きなし
		
		//ロック取得
		//m_lock.lock();

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
		//インデックスの範囲チェック
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
		const byte* top_p = reinterpret_cast<byte*>(m_pool);//バッファの先頭ポインタ
		const byte* target_p = reinterpret_cast<byte*>(p);//指定ポインタ
		const intptr_t diff = (target_p - top_p);//ポインタの引き算で差のバイト数算出
		const intptr_t index = diff / m_blockSize;//ブロックサイズで割ってインデックス算出
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
//共通アロケータインターフェースクラス
class IAllocator
{
public:
	//定数
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//デフォルトのアラインメント
public:
	//メソッド
	virtual const char* getName() const = 0;//アロケータ名取得
	virtual std::size_t getTotal() const = 0;//全体メモリ量　※参考情報（正しくない可能性がある）
	virtual std::size_t getUsed() const = 0;//使用中メモリ量　※参考情報（正しくない可能性がある）
	virtual std::size_t getRemain() const = 0;//残りメモリ量　※参考情報（正しくない可能性がある）
	//メモリ確保
	virtual void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) = 0;
	//メモリ解放
	virtual void free(void* p) = 0;
public:
	//デストラクタ
	virtual ~IAllocator(){}
};

//--------------------
//標準アロケータアダプタークラス
//※内部でmalloc, freeを使用
#include <malloc.h>
#include <stdlib.h>
class CStdAllocAdp : public IAllocator
{
public:
	//型
	typedef unsigned char byte;//バッファ用
public:
	//アクセッサ
	const char* getName() const override{ return "CStdAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override{ return 0; }//全体メモリ量取得　※集計不可
	std::size_t getUsed() const override{ return 0; }//使用中メモリ量取得　※集計不可
	std::size_t getRemain() const override { return 0; }//残りメモリ量取得　※集計不可
public:
	//オペレータ
	//※main関数より前に何かしらのメモリ確保処理が実行された場合、
	//　CPolyAllocatorが明示的にこのクラスを初期化する必要があるため、
	//　new / delete 演算子とインスタンス用の静的バッファを実装する
	static void* operator new(const std::size_t) throw() { return m_buff; }//new演算子
	static void operator delete(void*) throw() {}//delete演算子
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		//return malloc(size);//通常malloc()
#ifdef USE_MEMALIGN
		return memalign(align, size);//アラインメント指定版malloc
#else//USE_MEMALIGN
		return _aligned_malloc(size, align);//MS仕様：アラインメント指定版malloc
#endif//USE_MEMALIGN
	}
	//メモリ解放
	void free(void* p) override
	{
		if(!p)
			return;
#ifdef USE_MEMALIGN
		::free(p);//通常free()
#else//USE_MEMALIGN
		_aligned_free(p);//MS仕様：アラインメント指定版free
#endif//USE_MEMALIGN
	}
public:
	//コンストラクタ
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
class CMonoAllocAdp : public IAllocator
{
public:
	//型
	typedef unsigned char* byte;
public:
	//アクセッサ
	const char* getName() const override{ return "CMonoAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override{ return m_buffSize; }//全体メモリ量取得
	std::size_t getUsed() const override{ return m_isAllocated ? m_buffSize : 0; }//使用中メモリ量取得
	std::size_t getRemain() const override { return m_isAllocated ? 0 : m_buffSize; }//残りメモリ量取得
	const byte* getBuff() const { return m_buffPtr; }//バッファ取得
	std::size_t getBuffSize() const { return m_buffSize; }//バッファサイズ取得
	bool isAllocated() const { return m_isAllocated; }//メモリ確保済み
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
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
	CMonoAllocAdp() = delete;
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
	//型
	typedef unsigned char byte;//バッファ用
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
//スタックアロケータアダプター
class CStackAllocAdp : public IAllocator
{
public:
	//アクセッサ
	const char* getName() const override{ return "CStackAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override{ return m_allocator.getTotal(); }//全体メモリ量取得
	std::size_t getUsed() const override{ return m_allocator.getUsed(); }//使用中メモリ量取得
	std::size_t getRemain() const override { return m_allocator.getRemain(); }//残りメモリ量取得
	CStackAllocator& getAllocator() const { return m_allocator; }//アロケータ取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return m_allocator.allocN(size, align);//非virtualメンバーを使う
	}
	//メモリ解放
	void free(void* p) override
	{
		//なにもしない
	}
public:
	//デフォルトコンストラクタ
	CStackAllocAdp() = delete;
	//コンストラクタ
	CStackAllocAdp(CStackAllocator& stack) :
		m_allocator(stack)//スタックアロケータ
	{}
	//デストラクタ
	~CStackAllocAdp() override
	{}
private:
	//フィールド
	CStackAllocator& m_allocator;//スタックアロケータ
};

//--------------------
//双方向スタックアロケータアダプタークラス
class CDualStackAllocAdp : public IAllocator
{
public:
	//アクセッサ
	const char* getName() const override{ return "CDualStackAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override{ return m_allocator.getTotal(); }//全体メモリ量取得
	std::size_t getUsed() const override{ return m_allocator.getUsed(); }//使用中メモリ量取得
	std::size_t getRemain() const override { return m_allocator.getRemain(); }//残りメモリ量取得
	CDualStackAllocator& getAllocator() const { return m_allocator; }//アロケータ取得
	CDualStackAllocator::E_ORDERED getOrdered() const { m_ordered; }//スタック順取得
	void setOrdered(const CDualStackAllocator::E_ORDERED ordered){ m_ordered = ordered; }//スタック順更新
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return m_allocator.alloc(m_ordered, size, align);//非virtualメンバーを使う
	}
	//メモリ解放
	void free(void* p) override
	{
		//なにもしない
	}
public:
	//デフォルトコンストラクタ
	CDualStackAllocAdp() = delete;
	//コンストラクタ
	CDualStackAllocAdp(CDualStackAllocator& stack, CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::DEFAULT) :
		m_allocator(stack),//双方向スタックアロケータ
		m_ordered(ordered)//スタック順
	{}
	//デストラクタ
	~CDualStackAllocAdp() override
	{}
private:
	//フィールド
	CDualStackAllocator& m_allocator;//双方向スタックアロケータ
	CDualStackAllocator::E_ORDERED m_ordered;//スタック順
};

//--------------------
//スタックアロケータインターフェースアダプタークラス
class CIStackAllocAdp : public IAllocator
{
public:
	//アクセッサ
	const char* getName() const override{ return "CIStackAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override{ return m_allocator.getTotal(); }//全体メモリ量取得
	std::size_t getUsed() const override{ return m_allocator.getUsed(); }//使用中メモリ量取得
	std::size_t getRemain() const override { return m_allocator.getRemain(); }//残りメモリ量取得
	IStackAllocator& getAllocator() const { return m_allocator; }//アロケータ取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
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
	CIStackAllocAdp() = delete;
	//コンストラクタ
	CIStackAllocAdp(IStackAllocator& stack) :
		m_allocator(stack)//スタックアロケータ
	{}
	//デストラクタ
	~CIStackAllocAdp() override
	{}
private:
	//フィールド
	IStackAllocator& m_allocator;//スタックアロケータ
};

//--------------------
//プールアロケータアダプタークラス
class CPoolAllocAdp : public IAllocator
{
public:
	//アクセッサ
	const char* getName() const override{ return "CPoolAllocAdp"; }//アロケータ名取得
	std::size_t getTotal() const override{ return m_allocator.getBlocksNum() * m_allocator.getBlockSize(); }//全体メモリ量取得
	std::size_t getUsed() const override{ return m_allocator.getUsed() * m_allocator.getBlockSize(); }//使用中メモリ量取得
	std::size_t getRemain() const override { return m_allocator.getRemain() * m_allocator.getBlockSize(); }//残りメモリ量取得
	CPoolAllocator& getAllocator() const { return m_allocator; }//アロケータ取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
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
	CPoolAllocAdp() = delete;
	//コンストラクタ
	CPoolAllocAdp(CPoolAllocator& stack) :
		m_allocator(stack)//双方向スタックアロケータ
	{}
	//デストラクタ
	~CPoolAllocAdp() override
	{}
private:
	//フィールド
	CPoolAllocator& m_allocator;//双方向スタックアロケータ
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
	~CTest6()
	{
		printf("CTest6::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};

//--------------------
//テスト（共通関数）
void test6_sub1(const char* name, IAllocator& allocator)
{
	CTest6* obj_p = new(allocator)CTest6(name);
	printf("obj_p=0x%p\n", obj_p);
	delete_ptr(obj_p, allocator);
}
void test6_sub2(IAllocator& allocator)
{
	CTest6* obj_p = new(allocator)CTest6[3];
	printf("obj_p=0x%p\n", obj_p);
	delete_ptr(obj_p, 3, allocator);
}
//--------------------
//テスト
void test6()
{
	printf("---------- test6:共通アロケータインターフェース ----------\n");
	{
		printf("----------CStdAllocAdp\n");
		CStdAllocAdp allocator_adp;
		test6_sub1("テスト6-1", allocator_adp);
		//test6_sub2(allocator_adp);
	}
	{
		printf("----------CMonoAllocAdp\n");
		CMonoAllocAdpWithBuff<64> allocator_adp;
		test6_sub1("テスト6-2", allocator_adp);
		test6_sub2(allocator_adp);
	}
	{
		printf("----------CStackAllocAdp\n");
		CStackAllocatorWithBuff<64> allocator;
		CStackAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-3", allocator_adp);
		test6_sub2(allocator_adp);
	}
	{
		printf("----------CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<64> allocator;
		CDualStackAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-4", allocator_adp);
		test6_sub2(allocator_adp);
	}
	{
		printf("----------CIStackAllocAdp on CStackAllocAdp\n");
		CStackAllocatorWithBuff<64> allocator;
		CIStackAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-5", allocator_adp);
		test6_sub2(allocator_adp);
	}
	{
		printf("----------CIStackAllocAdp on CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<64> allocator;
		CIStackAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-6", allocator_adp);
		test6_sub2(allocator_adp);
	}
	{
		printf("----------CPoolAllocAdp\n");
		CPoolAllocatorWithBuff<8, 5> allocator;
		CPoolAllocAdp allocator_adp(allocator);
		test6_sub1("テスト6-7", allocator_adp);
		test6_sub2(allocator_adp);
	}
}

//--------------------------------------------------------------------------------
//グローバルnew/delete + 共通アロケータインターフェース

//--------------------
//プロトタイプ宣言
class CTempPolyAllocatorBase;

//--------------------
//グローバル多態性アロケータ
class CPolyAllocator
{
#ifndef IS_NOT_FRIEND_NEW_OPERATOR_FOR_TEST7
	//標準 new / deleete 演算子をフレンド化
	//※この CPolyAllocator クラスを直接インスタンス化するのは new / delete 演算子のみ
	friend void* operator new(const std::size_t size) throw();
	friend void* operator new[](const std::size_t size) throw();
	friend void operator delete(void* p) throw();
	friend void operator delete[](void* p) throw();
#endif//IS_NOT_FRIEND_NEW_OPERATOR_FOR_TEST7
	friend class CTempPolyAllocatorBase;
public:
	//オペレータ
	IAllocator* operator->(){ return m_allocator; }//アロー演算子（プロキシー）
	const IAllocator* operator->() const { return m_allocator; }//アロー演算子（プロキシー）
public:
	//アクセッサ
	//アロケータ取得
	static IAllocator* getAllocator()
	{
		return m_allocator;
	}
	//アロケータ変更
	//※戻りとして変更前のアロケータを返す
	//※なるべく直接使用禁止⇒CTempPolyAllocatorクラスを使い、コンストラクタで自動的に元に戻す
	static IAllocator* setAllocator(IAllocator& new_allocator)
	{
		IAllocator* prev_allocator = m_allocator;//変更前のアロケータ取得
		m_allocator = &new_allocator;//アロケータ変更
		return prev_allocator;//変更前のアロケータを返す
	}
#ifdef IS_NOT_FRIEND_NEW_OPERATOR_FOR_TEST7
public:
#else//IS_NOT_FRIEND_NEW_OPERATOR_FOR_TEST7
private://フレンド以外はインスタンス生成不可
#endif//IS_NOT_FRIEND_NEW_OPERATOR_FOR_TEST7
	//デフォルトコンストラクタ
	CPolyAllocator()
	{
		if (!m_allocator)
			m_allocator = new CStdAllocAdp();//標準アロケータを明示的に初期化
	}
public:
	//デストラクタ
	~CPolyAllocator()
	{}
protected:
	//フィールド
	static thread_local IAllocator* m_allocator;//現在のアロケータ
	//TLSを利用し、アロケータの変更が他のスレッドに影響しないようにする
};
//グローバル多態性アロケータの静的変数インスタンス化
thread_local IAllocator* CPolyAllocator::m_allocator = nullptr;

//クラス宣言
template<class I>
class CTempPolyAllocator;

//--------------------
//一時グローバル多態性アロケータ
//※グローバル多態性アロケータの「現在のアロケータ」を一時的に変更するためのクラス
//※処理ブロックを抜ける時に、デストラクタで自動的に元の状態に戻す

//一時グローバル多態性アロケータ基底クラス
//※継承専用クラス
class CTempPolyAllocatorBase : public CPolyAllocator
{
protected:
	//デフォルトコンストラクタ
	CTempPolyAllocatorBase() = delete;
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
//一時グローバル多態性アロケータテンプレートクラス
template<class I>
class CTempPolyAllocator : public CTempPolyAllocatorBase
{
public:
	//デフォルトコンストラクタ
	CTempPolyAllocator() = delete;
	//コンストラクタ
	CTempPolyAllocator(I& adapter) :
		CTempPolyAllocator(adapter)
	{}
public:
	//デストラクタ
	~CTempPolyAllocator()
	{}
};
//一時グローバル多態性アロケータテンプレートクラス：標準アロケータ用に特殊化
template<>
class CTempPolyAllocator<CStdAllocAdp> : public CTempPolyAllocatorBase
{
public:
	//デフォルトコンストラクタ
	CTempPolyAllocator():
		m_adapter(),//標準アロケータアダプタ初期化
		CTempPolyAllocatorBase(m_adapter)
	{}
public:
	//デストラクタ
	~CTempPolyAllocator()
	{}
private:
	//フィールド
	CStdAllocAdp m_adapter;//標準アロケータアダプタ
};
//一時グローバル多態性アロケータクラス：標準アロケータ用
using CTempPolyStdAllocator = CTempPolyAllocator<CStdAllocAdp>;
//一時グローバル多態性アロケータテンプレートクラス：単一バッファアロケータ用に特殊化
template<>
class CTempPolyAllocator<CMonoAllocAdp> : public CTempPolyAllocatorBase
{
public:
	//デフォルトコンストラクタ
	CTempPolyAllocator() = delete;
	//コンストラクタ
	CTempPolyAllocator(CMonoAllocAdp& adapter) :
		CTempPolyAllocatorBase(adapter)
	{}
public:
	//デストラクタ
	~CTempPolyAllocator()
	{}
};
//一時グローバル多態性アロケータクラス：単一バッファアロケータ用
using CTempPolyMonoAllocator = CTempPolyAllocator<CMonoAllocAdp>;
//一時グローバル多態性アロケータテンプレートクラス：スタックアロケータ用に特殊化
template<>
class CTempPolyAllocator<CStackAllocator> : public CTempPolyAllocatorBase
{
public:
	//デフォルトコンストラクタ
	CTempPolyAllocator() = delete;
	//コンストラクタ
	CTempPolyAllocator(CStackAllocator& allocator) :
		m_adapter(allocator),//スタックアロケータアダプタ初期化
		CTempPolyAllocatorBase(m_adapter)
	{}
public:
	//デストラクタ
	~CTempPolyAllocator()
	{}
private:
	//フィールド
	CStackAllocAdp m_adapter;//スタックアロケータアダプタ
};
//一時グローバル多態性アロケータクラス：スタックアロケータ用
using CTempPolyStackAllocator = CTempPolyAllocator<CStackAllocator>;
//一時グローバル多態性アロケータテンプレートクラス：双方向スタックアロケータ用に特殊化
template<>
class CTempPolyAllocator<CDualStackAllocator> : public CTempPolyAllocatorBase
{
public:
	//デフォルトコンストラクタ
	CTempPolyAllocator() = delete;
	//コンストラクタ
	CTempPolyAllocator(CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::DEFAULT) :
		m_adapter(allocator, ordered),//双方向スタックアロケータアダプタ初期化
		CTempPolyAllocatorBase(m_adapter)
	{}
public:
	//デストラクタ
	~CTempPolyAllocator()
	{}
private:
	//フィールド
	CDualStackAllocAdp m_adapter;//双方向スタックアロケータアダプタ
};
//一時グローバル多態性アロケータクラス：双方向スタックアロケータ用
using CTempPolyDualStackAllocator = CTempPolyAllocator<CDualStackAllocator>;
//一時グローバル多態性アロケータテンプレートクラス：スタックアロケータインターフェース用に特殊化
template<>
class CTempPolyAllocator<IStackAllocator> : public CTempPolyAllocatorBase
{
public:
	//デフォルトコンストラクタ
	CTempPolyAllocator() = delete;
	//コンストラクタ
	CTempPolyAllocator(IStackAllocator& allocator) :
		m_adapter(allocator),//スタックアロケータインターフェースアダプタ初期化
		CTempPolyAllocatorBase(m_adapter)
	{}
public:
	//デストラクタ
	~CTempPolyAllocator()
	{}
private:
	//フィールド
	CIStackAllocAdp m_adapter;//スタックアロケータインターフェースアダプタ
};
//一時グローバル多態性アロケータクラス：スタックアロケータインターフェース用
using CTempPolyIStackAllocator = CTempPolyAllocator<IStackAllocator>;
//一時グローバル多態性アロケータテンプレートクラス：プールアロケータ用に特殊化
template<>
class CTempPolyAllocator<CPoolAllocator> : public CTempPolyAllocatorBase
{
public:
	//デフォルトコンストラクタ
	CTempPolyAllocator() = delete;
	//コンストラクタ
	CTempPolyAllocator(CPoolAllocator& allocator) :
		m_adapter(allocator),//プールアロケータアダプタ初期化
		CTempPolyAllocatorBase(m_adapter)
	{}
public:
	//デストラクタ
	~CTempPolyAllocator()
	{}
private:
	//フィールド
	CPoolAllocAdp m_adapter;//プールアロケータアダプタ
};
//一時グローバル多態性アロケータクラス：プールアロケータ用
using CTempPolyPoolAllocator = CTempPolyAllocator<CPoolAllocator>;

#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
//--------------------
//配置new
void* operator new(const std::size_t size) throw()
{
	CPolyAllocator allocator;
	printf("new(size=%d, poly_allocator=\"%s\":%d/%d/%d)\n", size, allocator->getName(),  allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	void* p =allocator->alloc(size);
	printf("  p=0x%p\n", p);
	return p;
}
//配列版
void* operator new[](const std::size_t size) throw()
{
	CPolyAllocator allocator;
	printf("new[](size=%d, poly_allocator=\"%s\":%d/%d/%d)\n", size, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	void* p = allocator->alloc(size);
	printf("  p=0x%p\n", p);
	return p;
}
//配置delete
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
	~CTest7()
	{
		printf("CTest7::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	const char* m_name;//名前
	int m_dummy;//ダミー
};

//--------------------
//テスト（共通関数）
void test7_sub1(const char* name)
{
	CTest7* obj_p = new CTest7(name);
	printf("obj_p=0x%p\n", obj_p);
	delete obj_p;
}
void test7_sub2()
{
	CTest7* obj_p = new CTest7[3];
	printf("obj_p=0x%p\n", obj_p);
	delete[] obj_p;
}
//--------------------
//テスト
void test7()
{
	printf("---------- test7:グローバルnew/delete + 共通アロケータインターフェース ----------\n");
	{
		printf("----------CStdAllocAdp\n");
		CTempPolyStdAllocator poly_allocator;
		test7_sub1("テスト7-1");
		test7_sub2();
	}
	{
		printf("----------CMonoAllocAdp\n");
		CMonoAllocAdpWithBuff<64> allocator_adp;
		CTempPolyMonoAllocator allocator(allocator_adp);
		test7_sub1("テスト7-2");
		test7_sub2();
	}
	{
		printf("----------CStackAllocAdp\n");
		CStackAllocatorWithBuff<64> allocator;
		CTempPolyStackAllocator poly_allocator(allocator);
		test7_sub1("テスト7-3");
		test7_sub2();
	}
	{
		printf("----------CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<64> allocator;
		CTempPolyDualStackAllocator poly_allocator(allocator);
		test7_sub1("テスト7-4");
		test7_sub2();
	}
	{
		printf("----------CIStackAllocAdp on CStackAllocAdp\n");
		CStackAllocatorWithBuff<64> allocator;
		CTempPolyIStackAllocator poly_allocator(allocator);
		test7_sub1("テスト7-5");
		test7_sub2();
	}
	{
		printf("----------CIStackAllocAdp on CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<64> allocator;
		CTempPolyIStackAllocator poly_allocator(allocator);
		test7_sub1("テスト7-6");
		test7_sub2();
	}
	{
		printf("----------CPoolAllocAdp\n");
		CPoolAllocatorWithBuff<8, 5> allocator;
		CTempPolyPoolAllocator poly_allocator(allocator);
		test7_sub1("テスト7-7");
		test7_sub2();
	}
}

//--------------------------------------------------------------------------------
//標準ライブラリを便利に活用

//--------------------
//CRC算出関数
typedef unsigned int crc32_t;//CRC32型
namespace crc_inner_calc//直接使用しない処理を隠ぺいするためのネームスペース
{
#ifndef USE_CRC_CALC_TABLE
	//CRC生成多項式計算
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
//データ長を指定してからCRC算出
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

void sub()
{
	{
		const crc32_t crc1 = calcCRC32("1234567890");//コンパイル時に計算
#ifdef ENABLE_CONSTEXPR
		static_assert(crc1 == 0x261daee5, "invalid crc1");//OK：コンパイル時に評価
#endif//ENABLE_CONSTEXPR
		printf("constexpr によるコンパイル時のCRC計算結果=0x%08x\n", crc1);
	}
	{
		const crc32_t crc2 = calcCRC32("1234567890");//ランタイム時に計算//constが付いていないため
		assert(crc2 == 0x261daee5);//OK：コンパイル時に評価
		printf("constexpr によるランタイム時のCRC計算結果=0x%08x\n", crc2);
	}
#ifdef ENABLE_USER_DEFINED_LITERALS
	{
		const crc32_t crc3 = "1234567890"_crc32;//コンパイル時に計算
		static_assert(crc3 == 0x261daee5, "invalid crc2");//OK：コンパイル時に評価
		printf("ユーザー定義リテラルによるコンパイル時のCRC計算結果=0x%08x\n", crc3);
	}
#endif//ENABLE_USER_DEFINED_LITERALS
}

#include <unordered_map>//ハッシュテーブル用


//--------------------
//標準ライブラリを利用した固定バッファハッシュテーブルクラス


//--------------------
//テスト
#include <string.h>
#include <string>
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
		printf("----------CStackAllocAdp\n");
		CStackAllocatorWithBuff<8192> allocator;
		CTempPolyStackAllocator poly_allocator(allocator);
		{
			std::unordered_map<uintptr_t, int> hash_table;
			hash_table.reserve(100);
			printf("already reserved\n");
			hash_table.insert(std::make_pair(reinterpret_cast<uintptr_t>("太郎"), 123));
			hash_table.insert(std::make_pair(reinterpret_cast<uintptr_t>("次郎"), 456));
			hash_table.insert(std::make_pair(reinterpret_cast<uintptr_t>("三郎"), 789));
			printf("already inserted\n");
			printf("individual data print\n");
			printf("\"%s\"=%d\n", "太郎", hash_table.find(reinterpret_cast<uintptr_t>("太郎"))->second);
			printf("\"%s\"=%d\n", "次郎", hash_table.find(reinterpret_cast<uintptr_t>("次郎"))->second);
			printf("\"%s\"=%d\n", "三郎", hash_table.find(reinterpret_cast<uintptr_t>("三郎"))->second);
			printf("each data print\n");
			for (auto& o : hash_table)
			{
				printf("\"%s\"=%d\n", reinterpret_cast<char*>(o.first), o.second);
			}
			for (auto o = hash_table.cbegin(); o != hash_table.cend(); ++o)
			{
				printf("\"%s\"=%d\n", reinterpret_cast<char*>(o->first), o->second);
			}
		}
	}
sub();
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
	printf("---------- main:end ----------\n");
	return EXIT_SUCCESS;
}

// End of file
