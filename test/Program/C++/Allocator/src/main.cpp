#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>//uintptr_t,intptr_t用
#include <limits.h>//INT_MAX用
#include <new>//規定の配置new/配置delete用

//C++11ライブラリ
//#include <thread>//スレッド
//#include <atomic>//アトミック型

//#define nullptr NULL
//#define override

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

#define USE_NEW_PTR_FOR_TEST0//new関数を使用しないときはコメントアウトする
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

#define USE_DELETE_PTR_FOR_TEST0//delete関数を使用しないときはコメントアウトする
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
	if (!p)
		return;
	printf("delete_ptr(p=0x%p)\n", p);
	p->~T();//デストラクタ呼び出し
	operator delete(p, reinterpret_cast<char*>(p));//配置delete呼び出し
	p = nullptr;//安全のためにポインタを初期化
}
//挙動の確認のために配列版のdelete関数も用意
//（残念ながら）配列の要素数を受け渡す
template<class T>
void delete_ptr(T*& p, const std::size_t array_num)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, array_num=%d)\n", p, array_num);
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//デストラクタ呼び出し
	operator delete[](p, reinterpret_cast<char*>(p));//配置delete呼び出し
	p = nullptr;//安全のためにポインタを初期化
}

//--------------------
//テスト用クラス
//#define DELETE_DESTRUCTOR_FOR_CTEST1//デストラクタを使用するときはコメントアウト
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
#ifndef DELETE_DESTRUCTOR_FOR_CTEST1
	//デストラクタ
	~CTest1()
	{
		printf("CTest1::Destructor : name=\"%s\"\n", m_name);
	}
#endif//DELETE_DESTRUCTOR_FOR_CTEST1
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
//#define USE_GLOBAL_NEW_DELETE_TEST2//test2をグローバルnew/deleteで実行する場合はこのマクロを有効化
#ifdef USE_GLOBAL_NEW_DELETE_TEST2
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
#endif//USE_GLOBAL_NEW_DELETE_TEST2

//--------------------
//テスト用クラス
//#define USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2//size付きのdelete関数を使用するときはコメントアウト
//#define DELETE_DESTRUCTOR_FOR_CTEST2//デストラクタを使用するときはコメントアウト
class CTest2
{
public:
	//オペレータ
#ifndef USE_GLOBAL_NEW_DELETE_TEST2
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
#ifdef USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
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
#else//USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
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
#endif//USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
#endif//USE_GLOBAL_NEW_DELETE_TEST2
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
#ifndef DELETE_DESTRUCTOR_FOR_CTEST2
	//デストラクタ
	//※多重継承のテストのために virtual 化
	virtual ~CTest2()
	{
		printf("CTest2::Destructor : name=\"%s\"\n", m_name);
	}
#endif//DELETE_DESTRUCTOR_FOR_CTEST2
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
#ifndef USE_GLOBAL_NEW_DELETE_TEST2
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
#endif//USE_GLOBAL_NEW_DELETE_TEST2
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
#ifndef USE_GLOBAL_NEW_DELETE_TEST2
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
#endif//USE_GLOBAL_NEW_DELETE_TEST2
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
//#define USE_NAMESPACE_FOR_TEST2//ネームスペースに定義したnew/deleteのテストを行う場合は、この行を有効にする
#ifdef USE_NAMESPACE_FOR_TEST2
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
#endif//USE_NAMESPACE_FOR_TEST2

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
#ifdef USE_NAMESPACE_FOR_TEST2
	{
		printf("----------ネームスペースのnew/delete\n");
		CTest2* obj_p = (CTest2*)test2_ns::operator new(sizeof(CTest2));//ネームスペースに定義したnew
		::new(obj_p)CTest2("テスト2");//配置newで明示的なコンストラクタ呼び出し
		obj_p->~CTest2();//明示的なデストラクタ呼び出し
		test2_ns::operator delete(obj_p);//ネームスペースに定義したdelete
	}
#endif//USE_NAMESPACE_FOR_TEST2
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
	void* operator new(const std::size_t) throw() { return m_singletonBuff; }//new演算子
	void operator delete(void*) throw() {}//delete演算子
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
//スタックアロケータクラス
//※非スレッドセーフ（処理速度優先）
class CStackAllocator
{
public:
	//型
	typedef unsigned char byte;//バッファ用
	typedef std::size_t marker_t;//スタックマーカー型
public:
	//アクセッサ
	const byte* getBuff() const { return m_buffPtr; }//バッファ取得
	const byte* getNowPtr() const { return m_buffPtr + m_used; }//現在のバッファ位置
	marker_t getMarker() const { return m_used; }//現在のマーカーを取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = sizeof(int))
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
	//メモリを以前のマーカーに戻す
	//※マーカー指定版
	void back(const marker_t marker)
	{
		if (marker >= m_used)//符号なしなので、範囲チェックは大判定のみでOK
			return;
		m_used = marker;
	}
	//メモリを以前のマーカーに戻す
	//※ポインタ指定版
	void back(const void* p)
	{
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
		back(marker);
	}
	//メモリ破棄
	void clear()
	{
		m_used = 0;//マーカーをリセット
	}
public:
	//コンストラクタ
	CStackAllocator(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//バッファ先頭アドレス
		m_buffSize(buff_size),//バッファサイズ
		m_used(0)//マーカー
	{}
	//デストラクタ
	~CStackAllocator()
	{}
private:
	//フィールド
	byte* m_buffPtr;//バッファ先頭アドレス
	const std::size_t m_buffSize;//バッファサイズ
	marker_t m_used;//マーカー
};

//--------------------
//配置new/配置delete
//※メモリ使用状況を確認するためにマーカーを表示
//配置new
void* operator new(const std::size_t size, CStackAllocator& allocator, const std::size_t align = sizeof(int)) throw()
{
	printf("placement new(size=%d, allocator.marker=%d, align=%d)\n", size, allocator.getMarker(), align);
	return allocator.alloc(size, align);
}
//配列版
void* operator new[](const std::size_t size, CStackAllocator& allocator, const std::size_t align = sizeof(int)) throw()
{
	printf("placement new[](size=%d, allocator.marker=%d, align=%d)\n", size, allocator.getMarker(), align);
	return allocator.alloc(size, align);
}
//配置delete
void operator delete(void* p, CStackAllocator& allocator, const std::size_t) throw()
{
	printf("placement delete(p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	//allocator.back(p) は実行しない
}
//配列版
void operator delete[](void* p, CStackAllocator& allocator, const std::size_t) throw()
{
	printf("placement delete[](p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	//allocator.back(p) は実行しない
}
//デストラクタ呼び出し付きdelete
template<class T>
void delete_ptr(T*& p, CStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	p->~T();//デストラクタ呼び出し
	//operator delete(p, allocator, 0) は実行しない
	//allocator.back(p) は実行しない
	p = nullptr;//安全のためにポインタを初期化
}
//配列版
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, array_num=%d, allocator.marker=%d)\n", p, array_num, allocator.getMarker());
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//デストラクタ呼び出し
	//operator delete(p, allocator, 0) は実行しない
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
	~CStackAllocatorWithBuff()
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

//--------------------------------------------------------------------------------
//双方向スタックアロケータ

//--------------------
//双方向スタックアロケータクラス
//※非スレッドセーフ（処理速度優先）
class CDualStackAllocator
{
public:
	//定数
	enum E_ORDERED
	{
		NORMAL,//正順
		REVERSE//逆順
	};
public:
	//型
	typedef unsigned char byte;//バッファ用
	typedef std::size_t marker_t;//マーカー型
public:
	//アクセッサ
	const byte* getBuff() const { return m_buffPtr; }//バッファ取得
	const byte* getNowPtrN() const { return m_buffPtr + m_usedN; }//現在のバッファ位置（正順）
	const byte* getNowPtrR() const { return m_buffPtr + m_usedR; }//現在のバッファ位置（逆順）
	marker_t getMarkerN() const { return m_usedN; }//現在のマーカー（正順）を取得
	marker_t getMarkerR() const { return m_usedR; }//現在のマーカー（逆順）を取得
public:
	//メソッド
	//メモリ確保（正順）
	void* allocN(const std::size_t size, const std::size_t align = sizeof(int))
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
	void* allocR(const std::size_t size, const std::size_t align = sizeof(int))
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
	//メモリ破棄
	void clear()
	{
		clearN();
		clearR();
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
public:
	//コンストラクタ
	CDualStackAllocator(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//バッファ先頭アドレス
		m_buffSize(buff_size),//バッファサイズ
		m_usedN(0),//マーカー（正順）
		m_usedR(buff_size)//マーカー（逆順）
	{}
	//デストラクタ
	~CDualStackAllocator()
	{}
private:
	//フィールド
	byte* m_buffPtr;//バッファ先頭アドレス
	const std::size_t m_buffSize;//バッファサイズ
	marker_t m_usedN;//マーカー（正順）
	marker_t m_usedR;//マーカー（逆順）
};
static const CDualStackAllocator::E_ORDERED DSA_NORMAL = CDualStackAllocator::NORMAL;//正順
static const CDualStackAllocator::E_ORDERED DSA_REVERSE = CDualStackAllocator::REVERSE;//逆順

//--------------------
//配置new/配置delete
//※メモリ使用状況を確認するためにマーカーを表示
//配置new
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::NORMAL, const std::size_t align = sizeof(int)) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, ordered=%d, align=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), ordered, align);
	return ordered == CDualStackAllocator::NORMAL ? allocator.allocN(size, align) : allocator.allocR(size, align);
}
//配列版
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::NORMAL, const std::size_t align = sizeof(int)) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, ordered=%d, align=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), ordered, align);
	return ordered == CDualStackAllocator::NORMAL ? allocator.allocN(size, align) : allocator.allocR(size, align);
}
//配置delete
void operator delete(void* p, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED, const std::size_t) throw()
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.backN(p) / allocator.backR(p) は実行しない
}
//配列版
void operator delete[](void* p, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED, const std::size_t) throw()
{
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.backN(p) / allocator.backR(p) は実行しない
}
//デストラクタ呼び出し付きdelete
template<class T>
void delete_ptr(T*& p, CDualStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	p->~T();//デストラクタ呼び出し
	//operator delete(p, allocator, DSA_NORMAL, 0) は実行しない
	//allocator.backN(p) / allocator.backR(p) は実行しない
	p = nullptr;//安全のためにポインタを初期化
}
//配列版
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CDualStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, array_num=%d, allocator.marker=%d,%d)\n", p, array_num, allocator.getMarkerN(), allocator.getMarkerR());
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//デストラクタ呼び出し
	//operator delete(p, allocator, DSA_NORMAL, 0) は実行しない
	//allocator.backN(p) / allocator.backR(p) は実行しない
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
	CDualStackAllocatorWithBuff() :
		CDualStackAllocator(m_buff, BUFF_SIZE)
	{}
	//デストラクタ
	~CDualStackAllocatorWithBuff()
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

//--------------------
//テスト
void test4b()
{
	printf("---------- test4b:双方向スタックアロケータ ----------\n");
	CDualStackAllocatorWithBuff<64> stack;//双方向スタックアロケータ生成（64バイトのバッファを確保）
	printf("buff=0x%p\n", stack.getBuff());
	{
		printf("-----\n");
		int* i1 = new(stack, DSA_NORMAL) int[2];
		printf("i1=0x%p\n", i1);
		char* c1 = new(stack, DSA_REVERSE, 1) char[13];
		printf("c1=0x%p\n", c1);
		CStackAllocator::marker_t marker_n = stack.getMarkerN();//マーカー取得
		CStackAllocator::marker_t marker_r = stack.getMarkerR();//マーカー取得
		printf("marker=%d,%d\n", marker_n, marker_r);
		float* f1 = new(stack, DSA_NORMAL) float[4];
		printf("f1=0x%p\n", f1);
		CTest4b* obj1_p = new(stack, DSA_REVERSE)CTest4b("テスト4b");
		printf("obj1_p=0x%p\n", obj1_p);
		delete_ptr(f1, 4, stack);
		delete_ptr(c1, 15, stack);
		delete_ptr(i1, 2, stack);
		delete_ptr(obj1_p, stack);
		stack.backN(marker_n);//マーカーを戻す
		stack.backR(marker_r);//マーカーを戻す
	}
	{
		printf("-----\n");
		CStackAllocator::marker_t marker_n = stack.getMarkerN();//マーカー取得
		CStackAllocator::marker_t marker_r = stack.getMarkerR();//マーカー取得
		printf("marker=%d,%d\n", marker_n, marker_r);
		CTest4b* obj2_p = new(stack, DSA_NORMAL)CTest4b[3];
		printf("obj2_p=0x%p\n", obj2_p);
		int* i2 = new(stack, DSA_REVERSE) int;
		printf("i2=0x%p\n", i2);
		float* f2 = new(stack, DSA_NORMAL) float;
		printf("f2=0x%p\n", f2);
		char* c2 = new(stack, DSA_REVERSE, 1) char;
		printf("c2=0x%p\n", c2);
		int* over1 = new(stack, DSA_NORMAL) int[10];//【NG】サイズオーバー
		printf("over1=0x%p\n", over1);
		int* over2 = new(stack, DSA_REVERSE) int[10];//【NG】サイズオーバー
		printf("over2=0x%p\n", over2);
		delete_ptr(f2, stack);
		delete_ptr(c2, stack);
		delete_ptr(i2, stack);
		delete_ptr(obj2_p, 3, stack);
	}
}

//--------------------------------------------------------------------------------
//プールアロケータ

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
	const std::size_t m_blockSize;//ブロックサイズ
	const index_t m_poolBlocksNum;//プールブロック数
	static const index_t INVALID_INDEX = INT_MAX;//ブロックインデックスの無効値
public:
	//アクセッサ
	const byte* getBuff() const { return m_pool; }//バッファ取得
	index_t getUsed() const { return m_used; }//使用中数取得
	index_t getRemain() const { return m_poolBlocksNum - m_used; }//残数取得
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

		m_used = 0;//使用中数
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
		//ロック取得
		//m_lock.lock();

		//インデックス確保
		index_t index = -1;
		if (m_next < m_poolBlocksNum)
		{
			//未使用インデックスがある場合
			index = m_next++;//未使用先頭インデックスカウントアップ
			++m_used;//使用中数カウントアップ
		}
		else
		{
			if (m_recycle != INVALID_INDEX)
			{
				//リサイクル可能なインデックスがある場合
				index = m_recycle;//リサイクルインデックス
				m_recycle = *reinterpret_cast<unsigned int*>(getBlock(index));//リサイクルインデックス更新（空きノードの先頭に書き込まれている）
				++m_used;//使用中数カウントアップ
			}
		}

		//ロック解放
		//m_lock.unlock();

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
		--m_used;

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
		return index < 0 ? nullptr : getBlock(index);
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
	index_t m_used;//使用中数
	index_t m_next;//未使用先頭インデックス
	index_t m_recycle;//リサイクルインデックス
	//CSpinLock m_lock;//ロック
};

//--------------------
//配置new
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw()
{
	printf("placement new(size=%d, pool_allocator.used=%d/%d)\n", size, allocator.getUsed(), allocator.getRemain());
	return allocator.alloc(size);
}
//配置delete
void operator delete(void* p, CPoolAllocator& allocator) throw()
{
	printf("placement delete(p=0x%p, pool_allocator.used=%d/%d)\n", p, allocator.getUsed(), allocator.getRemain());
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
//テストメイン
int main(const int argc, const char* argv[])
{
	test0();
	test1();
	test2();
	test3();
	test4a();
	test4b();
	test5();
	return EXIT_SUCCESS;
}





#if 0

#include <malloc.h>

class IAllocator
{
public:
	virtual void* alloc(const std::size_t size, const std::size_t align = 0) = 0;
	virtual void free(void* p) = 0;
public:
	IAllocator()
	{}
	virtual ~IAllocator()
	{}
};
class CGlobalAllocator : public IAllocator
{
public:
	void* alloc(const std::size_t size, const std::size_t align) override
	{
		return std::malloc(size);
	}
	void free(void* p) override
	{
		std::free(p);
	}
public:
	void* operator new(const std::size_t){ return &m_buff; }
	void operator delete(void*){}
public:
	CGlobalAllocator()
	{}
	~CGlobalAllocator() override
	{}
private:
	static char m_buff[];
};
char CGlobalAllocator::m_buff[sizeof(CGlobalAllocator)];
class CAllocator
{
public:
	IAllocator* operator->(){ return m_allocator; }
	const IAllocator* operator->() const { return m_allocator; }
	IAllocator* setAllocator(IAllocator* new_allocator)
	{
		assert(new_allocator != nullptr);
		IAllocator*prev_allocator = m_allocator;
		m_allocator = new_allocator;
		return prev_allocator;
	}
	CAllocator()
	{
		if (!m_allocator)
			m_allocator = new CGlobalAllocator();
	}
	~CAllocator()
	{
	}
public:
	static IAllocator* m_allocator;
};
IAllocator* CAllocator::m_allocator = nullptr;
void* operator new(const std::size_t size){ printf("new!\n"); CAllocator allocator; return allocator->alloc(size); }
void operator delete(void* p){ printf("delete!\n"); CAllocator allocator; allocator->free(p); }
void* operator new[](const std::size_t size){ printf("new[]!\n");  CAllocator allocator; return allocator->alloc(size); }
void operator delete[](void* p){ printf("delete[]!\n"); CAllocator allocator; allocator->free(p); }
class A
{
public:
	A(){ printf("A()\n"); }
	~A(){ printf("~A()\n"); }
};


//テスト
int main(const int argc, const char* argv)
{
	test1::test();
	test2::test();
	test3::test();

	printf("-begin-\n");
	A* a = new A();
	A* b = new A[2];
	delete a;
	delete[] b;
	printf("-end-\n");
	
	return EXIT_SUCCESS;
}
#endif

// End of file
