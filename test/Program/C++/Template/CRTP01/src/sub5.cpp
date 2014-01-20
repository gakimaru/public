#include <stdio.h>

//自作vtableのテスト

//----------
//基底クラス
class CBase
{
	//----------仮想関数テーブル準備（基底クラスだけに必要）----------
protected:
	//仮想関数テーブル構造体定義
	struct VTABLE
	{
		//static関数ポインターのテーブル ※thisポインターを受け取るため、必ず第一引数は void* 型
		void(*v_methodA)(void*);
		int(*v_methodB)(void*);
		int(*v_methodC)(void*, int, char);
	};
public:
	//仮想関数呼び出しテーブル構造体定義
	struct CALL_TABLE
	{
		//【仮想関数対象】通常メソッドと同じ名前と引数のメソッドを定義し、仮想関数テーブルのメソッドを this ポインター付きで呼び出す
		void methodA(){ m_vtable->v_methodA(m_this); }
		int methodB(){ return m_vtable->v_methodB(m_this); }
		int methodC(int par1, char par2){ return m_vtable->v_methodC(m_this, par1, par2); }
		//コンストラクタ
		CALL_TABLE(void* this_, VTABLE* vtable) :
			m_this(this_),
			m_vtable(vtable)
		{}
	private:
		//フィールド
		void* m_this;    //this ポインター
		VTABLE* m_vtable;//仮想関数テーブル
	};
public:
	//アクセッサ
	CALL_TABLE& getCallTable() { return m_callTable; } //仮想関数呼び出しテーブル取得
protected:
	//フィールド
	CALL_TABLE m_callTable;//仮想関数呼び出しテーブル
protected:
	//コンストラクタ
	CBase(VTABLE* vtable) :                           //子クラス用に、パラメータを受け取るコンストラクタも用意
		m_callTable(static_cast<void*>(this), vtable) //必ず仮想関数呼び出しテーブルを初期化する
	{}

	//----------仮想関数用処理----------
public:
	//【仮想関数対象】通常メソッド
	void methodA(){ printf("CBase::methoA()\n"); }
	int methodB(){ printf("CBase::methoB()\n"); return 0; }
	int methodC(int par1, char par2){ printf("CBase::methoC(%d, %d)\n", par1, par2); return 0; }
public:
	//【仮想関数対象】通常メソッドを呼び出すstaticメソッド　※ this ポインター＋通常メソッドの引数を受け取り、this ポインターの通常メソッドを呼び出す
	static void s_methodA(void* this_){ static_cast<CBase*>(this_)->methodA(); }
	static int s_methodB(void* this_){ return static_cast<CBase*>(this_)->methodB(); }
	static int s_methodC(void* this_, int par1, char par2){ return static_cast<CBase*>(this_)->methodC(par1, par2); }
private:
	//staticフィールド
	static VTABLE s_vtalble;//仮想関数テーブル

	//----------通常処理----------
public:
	//.....
	
public:
	//コンストラクタ
	CBase() :
		CBase(&s_vtalble) //必ず仮想関数呼び出しテーブルを初期化する（初期化のためのコンストラクタを呼び出す）
	{}
};

//----------仮想関数用処理----------
//static仮想関数テーブルを初期化
CBase::VTABLE CBase::s_vtalble = {
	&CBase::s_methodA,
	&CBase::s_methodB,
	&CBase::s_methodC
};

//----------
//子クラスA
class CClassA : public CBase
{
	//----------仮想関数用処理----------
public:
	//【仮想関数対象】通常メソッド
	void methodA(){ printf("CClassA::methoA()\n"); }
	int methodB(){ printf("CClassA::methoB()\n"); return 0; }
	int methodC(int par1, char par2){ printf("CClassA::methoC(%d, %d)\n", par1, par2); return 0; }
public:
	//【仮想関数対象】通常メソッドを呼び出すstaticメソッド　※ this ポインター＋通常メソッドの引数を受け取り、this ポインターの通常メソッドを呼び出す
	static void s_methodA(void* this_){ static_cast<CClassA*>(this_)->methodA(); }
	static int s_methodB(void* this_){ return static_cast<CClassA*>(this_)->methodB(); }
	static int s_methodC(void* this_, int par1, char par2){ return static_cast<CClassA*>(this_)->methodC(par1, par2); }
private:
	//staticフィールド
	static VTABLE s_vtalble;//仮想関数テーブル

	//----------通常処理----------
public:
	//.....

public:
	//コンストラクタ
	CClassA() :
		CBase(&s_vtalble) //親クラスのコンストラクタを呼び出し、必ず仮想関数呼び出しテーブルを初期化する
	{}
};

//----------仮想関数用処理----------
//static仮想関数テーブルを初期化
CBase::VTABLE CClassA::s_vtalble = {
	&CClassA::s_methodA,
	&CClassA::s_methodB,
	&CClassA::s_methodC
};

//----------
//子クラスB
class CClassB : public CBase
{
	//----------仮想関数用処理----------
public:
	//【仮想関数対象】通常メソッド
	void methodA(){ printf("CClassB::methoA()\n"); }
	int methodB(){ printf("CClassB::methoB()\n"); return 0; }
	//methodCはオーバーライドしない
public:
	//【仮想関数対象】通常メソッドを呼び出すstaticメソッド　※ this ポインター＋通常メソッドの引数を受け取り、this ポインターの通常メソッドを呼び出す
	static void s_methodA(void* this_){ static_cast<CClassB*>(this_)->methodA(); }
	static int s_methodB(void* this_){ return static_cast<CClassB*>(this_)->methodB(); }
	//methodCはオーバーライドしない
private:
	//staticフィールド
	static VTABLE s_vtalble;//仮想関数テーブル

	//----------通常処理----------
public:
	//.....

public:
	//コンストラクタ
	CClassB() :
		CBase(&s_vtalble) //親クラスのコンストラクタを呼び出し、必ず仮想関数呼び出しテーブルを初期化する
	{}
};

//----------仮想関数用処理----------
//static仮想関数テーブルを初期化
CBase::VTABLE CClassB::s_vtalble = {
	&CClassB::s_methodA,
	&CClassB::s_methodB,
	&CBase::s_methodC   //オーバーライドしない場合は、親のメソッドを指定
};

//for_each
template<class T, size_t N, class F>
void for_each(T* (&obj)[N], F& functor)
{
	T** p = obj;
	for (int i = 0; i < N; ++i, ++p)
	{
		functor(*p);
	}
}

//自作vtableテスト
void testVTable()
{
	printf("\n- testVTable() -\n\n");

	//オブジェクトのリスト生成
	CBase* objs[] = {
		new CBase,
		new CClassA,
		new CClassB
	};
	//関数オブジェクト
	struct functor{
		void operator()(CBase* obj){
			CBase::CALL_TABLE& ctbl = obj->getCallTable(); //仮想関数呼び出しテーブルを取得してから、仮想関数を呼び出す
			ctbl.methodA();
			ctbl.methodB();
			ctbl.methodC(12, 34);
		}
	};
	//全オブジェクトの処理実行
	for_each(objs, functor());
}

// End of file
