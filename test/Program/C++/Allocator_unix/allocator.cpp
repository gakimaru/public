#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>//uintptr_t用
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
//　  void* operator new(size_t, void* where);
//　  void* operator new[](size_t, void* where);
//　  void operator delete(void*, void*);
//　  void operator delete[](void*, void*);
//　  void* operator new(size_t size, const nothrow_t&);//例外をスローしない
//　  void* operator new[](size_t size, const nothrow_t&);//例外をスローしない
//　  void operator delete(void*, const nothrow_t&);//例外をスローしない
//　  void operator delete[](void*, const nothrow_t&);//例外をスローしない

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
	//operator delete(p, p);//配置deleteの呼び出しは不要
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
void* operator new(const std::size_t size, char* where)
{
	printf("placement new(size=%d, where=0x%p)\n", size, where);
	return where;//渡されたバッファをそのまま返す
}
//配列new
//※デストラクタを持った型の場合、バッファの先頭に要素数を格納するために、少し大きなサイズが渡される
//　この時、戻り値のポインタは、関数を抜けた時、要素数情報の分がシフトしたポインタに変換される
//　型のアラインメントによっては大きくシフトする可能性もある
//　デストラクタを持たない型もしくはプリミティブ型ではこの情報は扱われない（なのでややこしい）
void* operator new[](const std::size_t size, char* where)
{
	printf("placement new[](size=%d, where=0x%p)\n", size, where);
	return where;//渡されたバッファをそのまま返す
}
//単体delete
//※配置newと対になる配置deleteは必須
//　（コンストラクタで例外が発生すると自動的に呼び出されるため）
void operator delete(void* p, char* where)
{
	printf("placement delete(p=0x%p, where=0x%p)\n", p, where);
	//なにもしない
}
//配列delete
//※デストラクタを持った型のポインタであっても、受け渡されたポインタがそのまま扱われるので注意
//　（メモリ確保時の正確なポインタが分からない）
//※クラス内delete関数を使用することでこの問題を解消できる
void operator delete[](void* p, char* where)
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
		CTest1("(default)")//他のコンストラクタ呼び出し：C++11で追加された構文
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
		//delete_ptr(obj_p);
		//delete_ptr(parent_p);
		delete_ptr(parent_ex_p);
	}
}

//--------------------------------------------------------------------------------
//クラス内new

//--------------------
//CTest2クラスインスタンス用バッファ
static char s_buffForTestClass2[32];

//--------------------
//テスト用クラス
//#define USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2//size付きのdelete関数を使用するときはコメントアウト
//#define DELETE_DESTRUCTOR_FOR_CTEST2//デストラクタを使用するときはコメントアウト
class CTest2
{
public:
	//オペレータ
	//クラス内new/delete
	//※自クラスのインスタンス専用のnew/delete
	//※第2引数がないので、配置new/配置deleteという扱いではないが、同じように使用できる
	//※クラス内new/deleteも配置new/配置deleteは使用可
	//※staticはあってもなくてもよい（必ずstatic扱いになる）
	static void* operator new(const std::size_t size)
	{
		printf("placement CTest2::new(size=%d)\n", size);
		return s_buffForTestClass2;//固定バッファを返す
	}
	static void* operator new[](const std::size_t size)
	{
		printf("placement CTest2::new[](size=%d)\n", size);
		return s_buffForTestClass2;//固定バッファを返す
	}
#ifdef USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
	//※クラス内deleteは規定のdeleteが2種類ある
	//※これは標準的なスタイル
	static void operator delete(void* p)
	{
		printf("placement CTest2::delete(p=0x%p)\n", p);
		//なにもしない
	}
	static void operator delete[](void* p)
	{
		printf("placement CTest2::delete[](p=0x%p)\n", p);
		//なにもしない
	}
#else//USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
	//※クラス内deleteでは、第2引数に size_t を取る形も標準スタイルの一つ（非配置delete）
	//※2種類とも定義したら、operator delete(void*) の方が優先
	static void operator delete(void* p, const std::size_t size)
	{
		printf("placement CTest2::delete(p=0x%p, size=%d)\n", p, size);
		//なにもしない
	}
	static void operator delete[](void* p, const std::size_t size)
	{
		printf("placement CTest2::delete[](p=0x%p, size=%d)\n", p, size);
		//なにもしない
	}
#endif//USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
public:
	//デフォルトコンストラクタ
	CTest2() :
		CTest2("(default)")//他のコンストラクタ呼び出し：C++11で追加された構文
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
	//クラス内new
	static void* operator new(const std::size_t size)
	{
		printf("placement CTest2ex::new(size=%d)\n", size);
		return s_buffForTestClass2;//固定バッファを返す
	}
	//クラス内delete
	static void operator delete(void* p)
	{
		printf("placement CTest2ex::delete(p=0x%p)\n", p);
		//なにもしない
	}
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
	//クラス内new
	static void* operator new(const std::size_t size)
	{
		printf("placement CDerivedTest2::new(size=%d)\n", size);
		return s_buffForTestClass2;//固定バッファを返す
	}
	//クラス内delete
	static void operator delete(void* p)
	{
		printf("placement CDerivedTest2::delete(p=0x%p)\n", p);
		//なにもしない
	}
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
//テスト
void test2()
{
	printf("---------- test2:クラス内new/delete ----------\n");
	{
		printf("----------クラス\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CTest2* obj_p = new CTest2("テスト2");
		printf("obj_p=0x%p\n", obj_p);
		delete obj_p;//普通の（operator を付けない）deleteとして呼び出せる
	}
	{
		printf("----------クラスの配列\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CTest2* obj_p = new CTest2[3];
		printf("obj_p=0x%p\n", obj_p);
		printf("*reinterpret_cast<int*>(s_buffForTestClass2)=%d\n", *reinterpret_cast<int*>(s_buffForTestClass2));//デストラクタを持った型の配列は、バッファの先頭に要素数が格納されている
		delete[] obj_p;//普通の（operator を付けない）delete[]として呼び出せる
	}
	{
		printf("----------多重継承クラス\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CDerivedTest2* obj_p = new CDerivedTest2("テスト2多重継承");
		CTest2* parent_p = obj_p;//親1にキャスト
		CTest2ex* parent_ex_p = obj_p;//親2にキャスト
		printf("obj_p=0x%p, parent_p=0x%p, parent_ex_p=0x%p\n", obj_p, parent_p, parent_ex_p);
		//delete obj_p;
		//delete parent_p;
		delete parent_ex_p;
	}
}

//--------------------------------------------------------------------------------
//固定バッファシングルトンのテスト

//--------------------
//固定バッファシングルトンテンプレートクラス
template<class T>
class CSingleton
{
	friend void* operator new(const std::size_t size, CSingleton<T>& singleton);
public:
	//オペレータ（シングルトン本体のプロキシー）
	T* operator->(){ return m_ptr; }
public:
	//メソッド
	//明示的な削除
	void destroy();
public:
	//コンストラクタ
	CSingleton();
private:
	//フィールド
	static T* m_ptr;//シングルトン本体参照
	static char m_buff[];//シングルトン本体用バッファ
};

//--------------------
//テンプレート配置new
template<class T>
void* operator new(const std::size_t size, CSingleton<T>& singleton)
{
	printf("placement new<T>(size=%d, singleton.m_buff=0x%p)\n", size, singleton.m_buff);
	return singleton.buff;
}
//テンプレート配置delete
template<class T>
void operator delete(void* p, CSingleton<T>& singleton)
{
	printf("placement delete<T>(p=0x%p, singleton.m_buff=0x%p)\n", p, singleton.m_buff);
}

//--------------------
//固定バッファシングルトンテンプレートクラス：処理部
//明示的な削除
template<class T>
void CSingleton<T>::destroy()
{
	if (!m_ptr)
		return;
	m_ptr->~T();//デストラクタ呼び出し
	operator delete(m_ptr, m_buff);
	m_ptr = nullptr;
}
//コンストラクタ
template<class T>
CSingleton<T>::CSingleton()
{
	//まだ初期化していなければ初期化
	if (!m_ptr)
		m_ptr = new(m_buff)T();
}
//静的変数
template<class T>
T* CSingleton<T>::m_ptr = nullptr;//シングルトン参照
template<class T>
char CSingleton<T>::m_buff[sizeof(T)];//シングルトン用バッファ

//--------------------
//テスト用クラス
class CTest3
{
public:
	//アクセッサ
	int getData() const { return m_data; }
	void setData(const int data){ m_data = data; }
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
void printData()
{
	CSingleton<CTest3> obj;
	printf("obj->getData()=%d\n", obj->getData());
}
void setData()
{
	CSingleton<CTest3> obj;
	obj->setData(123);
}
void deleteIntentionally()
{
	CSingleton<CTest3> obj;
	obj.destroy();
}
void test3()
{
	printf("---------- test3 ----------\n");
	printData();
	setData();
	printData();
	deleteIntentionally();
	printData();
}

//--------------------------------------------------------------------------------
//スタックアロケータ

//--------------------
//スタックアロケータ
class CStackAllocator
{
public:
	//型
	typedef std::size_t MARKER;
public:
	//アクセッサ
	MARKER getMarker() const { return m_used; }//現在のスタックマーカーを取得
public:
	//メソッド
	//メモリ確保
	void* alloc(const std::size_t size, const std::size_t align = sizeof(int))
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_used;
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;
		const std::size_t next_used = m_used + align_diff + size;
		if (next_used > m_buffSize)
			return nullptr;
		const uintptr_t new_ptr = now_ptr + m_used + align_diff;
		m_used = next_used;
		return reinterpret_cast<void*>(new_ptr);
	}
	//メモリを以前のマーカーに戻す
	void back(const MARKER marker)
	{
		if (marker >= m_used)
			return;
		m_used = marker;
	}
	//メモリを以前のマーカーに戻す
	void back(const void* p)
	{
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
		back(marker);
	}
	//メモリ破棄
	void clear()
	{
		m_used = 0;
	}
public:
	//コンストラクタ
	CStackAllocator(char* buff_p, const std::size_t buff_size) :
		m_buffPtr(buff_p),
		m_buffSize(buff_size),
		m_used(0)
	{}
	//デストラクタ
	~CStackAllocator()
	{}
private:
	//フィールド
	char* m_buffPtr;//バッファ
	const std::size_t m_buffSize;//バッファサイズ
	MARKER m_used;//使用済みサイズ
};

//--------------------
//配置new
void* operator new(const std::size_t size, CStackAllocator& allocator, const std::size_t align = sizeof(int))
{
	printf("placement new(size=%d, allocator.marker=%d)\n", size, allocator.getMarker());
	return allocator.alloc(size, align);
}
void* operator new[](const std::size_t size, CStackAllocator& allocator, const std::size_t align = sizeof(int))
{
	printf("placement new[](size=%d, allocator.marker=%d)\n", size, allocator.getMarker());
	return allocator.alloc(size, align);
}
//配置delete
void operator delete(void* p, CStackAllocator& allocator)
{
	printf("placement delete(p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	//なにもしない
	//allocator.back(p) も実行しない
}
void operator delete[](void* p, CStackAllocator& allocator)
{
	printf("placement delete[](p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	//なにもしない
	//allocator.back(p) も実行しない
}
//デストラクタ呼び出し付きdelete
template<class T>
void delete_ptr(T*& p, CStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	p->~T();
	p = nullptr;
	//なにもしない
	//allocator.back(p) も実行しない
}

//--------------------
//バッファ付きスタックアロケータ
template<std::size_t SIZE>
class CBufferedStackAllocator : public CStackAllocator
{
public:
	//定数
	static const std::size_t STACK_SIZE = SIZE;//スタックサイズ
public:
	//コンストラクタ
	CBufferedStackAllocator() :
		CStackAllocator(m_buff, STACK_SIZE)
	{}
	//デストラクタ
	~CBufferedStackAllocator()
	{}
private:
	//フィールド
	char m_buff[STACK_SIZE];//スタック領域サイズ
};

//--------------------
//テスト
void test4()
{
	printf("---------- test4 ----------\n");
	CBufferedStackAllocator<32> stack;
	int* i1 = new(stack) int;
	CStackAllocator::MARKER marker = stack.getMarker();
	char* f1 = new(stack) char[15];
	delete_ptr(f1, stack);
	delete_ptr(i1, stack);
	stack.back(marker);
	int* i2 = new(stack) int;
	float* f2 = new(stack) float;
	delete_ptr(f2, stack);
	delete_ptr(i2, stack);
}

//--------------------------------------------------------------------------------
//双方向スタックアロケータ

//--------------------
//双方向スタックアロケータ
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
	typedef std::size_t MARKER;
public:
	//アクセッサ
	MARKER getMarkerN() const { return m_usedN; }//現在のスタックマーカー（正順）を取得
	MARKER getMarkerR() const { return m_usedR; }//現在のスタックマーカー（逆順）を取得
public:
	//メソッド
	//メモリ確保（正順）
	void* allocN(const std::size_t size, const std::size_t align = sizeof(int))
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_usedN;
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;
		const std::size_t next_used = m_usedN + align_diff + size;
		if (next_used > m_usedR)
			return nullptr;
		const uintptr_t new_ptr = now_ptr + m_usedN + align_diff;
		m_usedN = next_used;
		return reinterpret_cast<void*>(new_ptr);
	}
	//メモリ確保（逆順）
	void* allocR(const std::size_t size, const std::size_t align = sizeof(int))
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_usedR;
		const std::size_t next_ptr = now_ptr - size;
		const uintptr_t align_diff = align > 0 ? next_ptr % align == 0 ? 0 : next_ptr % align : 0;
		const std::size_t next_used = m_usedR - size - align_diff;
		if (next_used < m_usedN)
			return nullptr;
		const uintptr_t new_ptr = now_ptr + next_used;
		m_usedR = next_used;
		return reinterpret_cast<void*>(new_ptr);
	}
	//メモリを以前のマーカーに戻す（正順）
	void backN(const MARKER marker_n)
	{
		if (marker_n >= m_usedN)
			return;
		m_usedN = marker_n;
	}
	//メモリを以前のマーカーに戻す（逆順）
	void backR(const MARKER marker_r)
	{
		if (marker_r <= m_usedR || marker_r > m_buffSize)
			return;
		m_usedR = marker_r;
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
	CDualStackAllocator(char* buff_p, const std::size_t buff_size) :
		m_buffPtr(buff_p),
		m_buffSize(buff_size),
		m_usedN(0),
		m_usedR(buff_size)
	{}
	//デストラクタ
	~CDualStackAllocator()
	{}
private:
	//フィールド
	char* m_buffPtr;//バッファ
	const std::size_t m_buffSize;//バッファサイズ
	MARKER m_usedN;//使用済みサイズ（正順）
	MARKER m_usedR;//使用済みサイズ（逆順）
};

//--------------------
//配置new
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::NORMAL, const std::size_t align = sizeof(int))
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR());
	return ordered == CDualStackAllocator::NORMAL ? allocator.allocN(size, align) : allocator.allocR(size, align);
}
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::NORMAL, const std::size_t align = sizeof(int))
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR());
	return ordered == CDualStackAllocator::NORMAL ? allocator.allocN(size, align) : allocator.allocR(size, align);
}
//配置delete
void operator delete(void* p, CDualStackAllocator& allocator)
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//なにもしない
	//allocator.back(p) も実行しない
}
void operator delete[](void* p, CDualStackAllocator& allocator)
{
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//なにもしない
	//allocator.back(p) も実行しない
}
//デストラクタ呼び出し付きdelete
template<class T>
void delete_ptr(T*& p, CDualStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	p->~T();
	p = nullptr;
	//なにもしない
	//allocator.back(p) も実行しない
}

//--------------------
//バッファ付き双方向スタックアロケータ
template<std::size_t SIZE>
class CBufferedDualStackAllocator : public CDualStackAllocator
{
public:
	//定数
	static const std::size_t STACK_SIZE = SIZE;//スタックサイズ
public:
	//コンストラクタ
	CBufferedDualStackAllocator() :
		CDualStackAllocator(m_buff, STACK_SIZE)
	{}
	//デストラクタ
	~CBufferedDualStackAllocator()
	{}
private:
	//フィールド
	char m_buff[STACK_SIZE];//スタック領域サイズ
};

//--------------------
//テスト
void test5()
{
	printf("---------- test5 ----------\n");
	CBufferedDualStackAllocator<50> stack;
	int* i1 = new(stack, CDualStackAllocator::NORMAL) int;
	CDualStackAllocator::MARKER markerN = stack.getMarkerN();
	CDualStackAllocator::MARKER markerR = stack.getMarkerR();
	char* f1 = new(stack, CDualStackAllocator::REVERSE) char[15];
	delete_ptr(f1, stack);
	delete_ptr(i1, stack);
	stack.backN(markerN);
	stack.backR(markerR);
	int* i2 = new(stack, CDualStackAllocator::NORMAL) int;
	float* f2 = new(stack, CDualStackAllocator::REVERSE) float;
	delete_ptr(f2, stack);
	delete_ptr(i2, stack);
}

#if 0
//--------------------------------------------------------------------------------
//基本マクロ

//ブレークポイント
#include <windows.h>//ブレークポイント用
#define BREAK_POINT() DebugBreak()

//デバッグプリント
#define DEBUG_PRINT(msg, ...) printf(msg, __VA_ARGS__);
#define DEBUG_FPRINT(fp, msg, ...) fprintf(fp, msg, __VA_ARGS__);
#define DEBUG_FLUSH() fflush(stdout)
#define DEBUG_FFLUSH(fp) fflush(fp)
//#define DEBUG_PRINT(msg, ...)
//#define DEBUG_FPRINT(fp, msg, ...)
//#define DEBUG_FLUSH()
//#define DEBUG_FFLUSH(fp) fflush(fp)

//文字列化マクロ
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)
#define COLLECT_STRING(s) s

//アサーション
#define ASSERT(expr, msg, ...) \
if (!(expr)) \
	{ \
	DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
	"  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
	"  "  msg "\n", __VA_ARGS__); \
	BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//削除用
//#include <assert.h>//assert用
//#define ASSERT(expr, msg, ...) assert(expr)//VC++標準版

//スレッドローカルストレージ修飾子
//※C++11仕様偽装（VC++2013では未対応につき）
//※中身はWindows仕様
#define thread_local __declspec(thread)

//----------------------------------------
//スレッドIDクラス
//※TLSを活用して高速化

//スレッドID型
//typedef std::thread::id THREAD_ID;//C++11/ ※この型では扱わず、ハッシュ値を使用する
typedef std::size_t THREAD_ID;//C++11
static const THREAD_ID INVALID_THREAD_ID = 0xffffffff;//無効なスレッドID

//現在のスレッドID取得関数
//inline THREAD_ID  GetThisThreadID(){ return std::this_thread::get_id(); } //C++11
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id().hash(); } //C++11

//スレッドIDクラス
class CThreadID
{
public:
	//アクセッサ
	const THREAD_ID getID() const { return m_threadId; }//スレッドIDを取得
	const char* getName() const { return m_threadName; }//スレッド名を取得
public:
	//アクセッサ（static）
	static THREAD_ID getThisID(){ return m_thisThreadID; }//現在のスレッドのスレッドIDを取得
	static const char* getThisName(){ return m_thisThreadName; }//現在のスレッドのスレッド名を取得
public:
	//メソッド
	bool isThisThread() const { return m_threadId == getThisID(); }//現在のスレッドと同じスレッドか判定
private:
	//メソッド(static)
	static void setThisThread()//現在のスレッドのスレッドIDをセット
	{
		if (m_thisThreadID == INVALID_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
	}
	static void resetThisThread(const char* name)//現在のスレッドのスレッドIDをリセット
	{
		m_thisThreadID = GetThisThreadID();
		m_thisThreadName = name;
	}
public:
	//オペレータ（許可）
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID一致判定
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID不一致判定
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID一致判定
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID不一致判定
	CThreadID& operator=(const CThreadID& o) //コピー演算子
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
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
	//デフォルトコンストラクタ
	//※既にTLSに記録済みのスレッドID（と名前）を取得
	CThreadID()
	{
		setThisThread();
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
private:
	//フィールド
	THREAD_ID m_threadId;//スレッドID（オブジェクトに保存する値）
	const char* m_threadName;//スレッド名（オブジェクトに保存する値）
	static thread_local THREAD_ID m_thisThreadID;//現在のスレッドのスレッドID(TLS)
	static thread_local const char* m_thisThreadName;//現在のスレッド名(TLS)
};
//static変数のインスタンス化
thread_local THREAD_ID CThreadID::m_thisThreadID = INVALID_THREAD_ID;//スレッドID(TLS)
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
#endif

//--------------------------------------------------------------------------------
//プールアロケータ

//--------------------
//クラス宣言
class CPoolAllocator;

//--------------------
//配置new
void* operator new(const std::size_t size, CPoolAllocator& allocator);
//配置delete
void operator delete(void* p, CPoolAllocator& allocator);

//----------------------------------------
//プールアロケータクラス
//※スレッドセーフ対応
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
	std::size_t getUsed() const { return m_used; }//使用中数取得
	void* getBlock(const index_t index){ return m_pool + index * m_blockSize; }//ブロック取得
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
		const int diff = (target_p - top_p);//ポインタの引き算で差のバイト数算出
		const int index = (target_p - top_p) / m_blockSize;//ブロックサイズで割ってインデックス算出
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
void* operator new(const std::size_t size, CPoolAllocator& allocator)
{
	printf("placement new(size=%d, pool_allocator.used=%d,%d)\n", size, allocator.getUsed());
	return allocator.alloc(size);
}
//配置delete
void operator delete(void* p, CPoolAllocator& allocator)
{
	printf("placement delete(p=0x%p, pool_allocator.used=%d,%d)\n", p, allocator.getUsed());
	allocator.free(p);
}

//----------------------------------------
//プールアロケータクラス（バッファ内包版）
template<int N, std::size_t S>
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

//テスト
void test6()
{
	printf("---------- test4 ----------\n");
	CPoolAllocatorWithBuff<10, 32> pool;
	int* i1 = pool.create<int>();
	pool.destroy(i1);
	int* i2 = pool.create<int>();
	float* f2 = pool.create<float>();
	pool.destroy(f2);
	pool.destroy(i2);
}

//--------------------------------------------------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
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
