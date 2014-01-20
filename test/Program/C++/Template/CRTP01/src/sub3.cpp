#include <stdio.h>

//シーンオブジェクト用インターフェースクラス
class ISceneObject
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual const char* getName() = 0;
};

//シーンオブジェクト用テンプレートクラス
template<class U, class D>
class CSceneObject : public ISceneObject
{
public:
	void update() override
	{
		U policy;
		policy.update_core(this);
	}
	void draw() override
	{
		D policy;
		policy.draw_core(this);
	}

};

//update処理用ポリシークラス：パターンＡ
class CUpdatePolicyA
{
public:
	void update_core(ISceneObject* obj)
	{
		printf("%s->CUpdatePolicyA::update_core()\n", obj->getName());
	}
};

//update処理用ポリシークラス：パターンＢ
class CUpdatePolicyB
{
public:
	void update_core(ISceneObject* obj)
	{
		printf("%s->CUpdatePolicyB::update_core()\n", obj->getName());
	}
};

//draw処理用ポリシークラス：パターンＡ
class CDrawPolicyA
{
public:
	void draw_core(ISceneObject* obj)
	{
		printf("%s->CDrawPolicyA::draw_core()\n", obj->getName());
	}
};

//draw処理用ポリシークラス：パターンＢ
class CDrawPolicyB
{
public:
	void draw_core(ISceneObject* obj)
	{
		printf("%s->CDrawPolicyB::draw_core()\n", obj->getName());
	}
};

//主人公
class CHero : public CSceneObject<CUpdatePolicyA, CDrawPolicyA>
{
public:
	const char* getName() override { return "CHero"; }
};

//敵
class CEnemy : public CSceneObject<CUpdatePolicyB, CDrawPolicyA>
{
public:
	const char* getName() override { return "CEnemy"; }
};

//ミサイル
class CMissile : public CSceneObject<CUpdatePolicyB, CDrawPolicyB>
{
public:
	const char* getName() override { return "CMissile"; }
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

//ポリシーテスト
void testPolicy()
{
	printf("\n- testPolicy() -\n\n");

	//シーンオブジェクトのリスト生成
	ISceneObject* scene_objs[] = {
		new CHero,
		new CEnemy,
		new CMissile
	};
	//update実行用関数オブジェクト
	struct update_functor{ void operator()(ISceneObject* obj){ obj->update(); } };
	//draw実行用関数オブジェクト
	struct draw_functor{ void operator()(ISceneObject* obj){ obj->draw(); } };
	//delete用関数オブジェクト
	struct delete_functor{ void operator()(ISceneObject* obj){ delete obj; } };
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
