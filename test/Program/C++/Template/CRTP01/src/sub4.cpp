#include <stdio.h>

//親クラス（テンプレート）
template<class D>
class CBase
{
public:
	void foo() const
	{
		printf("CBase<D>::foo()\n");
		static_cast<const D&>(*this).bar();	//子クラスのメンバーを呼び出し
	}
};

//子クラス
class CDerived : public CBase<CDerived>	//親クラスのテンプレートパラメータに自分（子クラス）を渡している
{
	friend class CBase<CDerived>;
private:
	void bar() const
	{
		printf("CDerived::bar()\n");
	}
};

//CRTPのテスト
void testCRTP()
{
	printf("\n- testCRTP() -\n\n");

	CDerived obj;
	obj.foo();
}

//--------------------------------------------------------------------------------

//シーンオブジェクト用インターフェースクラス
class ISceneObject
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
//	virtual const char* getName() = 0;//削除
};

//シーンオブジェクト用テンプレートクラス
template<class O, class U, class D>
class CSceneObject : public ISceneObject
{
public:
	void update() override
	{
		U policy;
		policy.update_core<O, CSceneObject<O, U, D> >(this);
	}
	void draw() override
	{
		D policy;
		policy.draw_core<O, CSceneObject<O, U, D> >(this);
	}

};

//update処理用ポリシークラス：パターンＡ
class CUpdatePolicyA
{
public:
	template<class O, class T>
	void update_core(T* obj)
	{
		printf("%s->CUpdatePolicyA::update_core()\n", static_cast<O*>(obj)->getName());
	}
};

//update処理用ポリシークラス：パターンＢ
class CUpdatePolicyB
{
public:
	template<class O, class T>
	void update_core(T* obj)
	{
		printf("%s->CUpdatePolicyB::update_core()\n", static_cast<O*>(obj)->getName());
	}
};

//draw処理用ポリシークラス：パターンＡ
class CDrawPolicyA
{
public:
	template<class O, class T>
	void draw_core(T* obj)
	{
		printf("%s->CDrawPolicyA::draw_core()\n", static_cast<O*>(obj)->getName());
	}
};

//draw処理用ポリシークラス：パターンＢ
class CDrawPolicyB
{
public:
	template<class O, class T>
	void draw_core(T* obj)
	{
		printf("%s->CDrawPolicyB::draw_core()\n", static_cast<O*>(obj)->getName());
	}
};

//主人公
class CHero : public CSceneObject<CHero, CUpdatePolicyA, CDrawPolicyA>
{
	friend class CUpdatePolicyA;
	friend class CDrawPolicyA;
private:
	const char* getName() { return "CHero"; }//非opverride
};

//敵
class CEnemy : public CSceneObject<CEnemy, CUpdatePolicyB, CDrawPolicyA>
{
	friend class CUpdatePolicyB;
	friend class CDrawPolicyA;
private:
	const char* getName() { return "CEnemy"; }//非opverride
};

//ミサイル
class CMissile : public CSceneObject<CMissile, CUpdatePolicyB, CDrawPolicyB>
{
	friend class CUpdatePolicyB;
	friend class CDrawPolicyB;
private:
	const char* getName() { return "CMissile"; }//非opverride
};

//for_each
template<class T, size_t N, class F>
inline void for_each(T* (&obj)[N], F& functor)
{
	T** p = obj;
	for (int i = 0; i < N; ++i, ++p)
	{
		functor(*p);
	}
}

//ポリシー＆CRTPテスト
void testPolicyAndCRTP()
{
	printf("\n- testPolicyAndCRTP() -\n\n");

	//シーンオブジェクトのリスト生成
	ISceneObject* scene_objs[] = {
		new CHero,
		new CEnemy,
		new CMissile
	};
	//update実行用関数オブジェクト
	struct update_functor{ inline void operator()(ISceneObject* obj){ obj->update(); } };
	//draw実行用関数オブジェクト
	struct draw_functor{ inline void operator()(ISceneObject* obj){ obj->draw(); } };
	//delete用関数オブジェクト
	struct delete_functor{ inline void operator()(ISceneObject* obj){ delete obj; } };
	//全シーンオブジェクトのupdate実行
	printf("[update]\n");
	for_each(scene_objs, update_functor());
	//全シーンオブジェクトのdraw実行
	printf("[draw]\n");
	for_each(scene_objs, draw_functor());
	//全シーンオブジェクトのdelete
	for_each(scene_objs, delete_functor());
}

// End of file
