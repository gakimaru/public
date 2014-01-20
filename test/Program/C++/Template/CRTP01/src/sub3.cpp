#include <stdio.h>

//�V�[���I�u�W�F�N�g�p�C���^�[�t�F�[�X�N���X
class ISceneObject
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual const char* getName() = 0;
};

//�V�[���I�u�W�F�N�g�p�e���v���[�g�N���X
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

//update�����p�|���V�[�N���X�F�p�^�[���`
class CUpdatePolicyA
{
public:
	void update_core(ISceneObject* obj)
	{
		printf("%s->CUpdatePolicyA::update_core()\n", obj->getName());
	}
};

//update�����p�|���V�[�N���X�F�p�^�[���a
class CUpdatePolicyB
{
public:
	void update_core(ISceneObject* obj)
	{
		printf("%s->CUpdatePolicyB::update_core()\n", obj->getName());
	}
};

//draw�����p�|���V�[�N���X�F�p�^�[���`
class CDrawPolicyA
{
public:
	void draw_core(ISceneObject* obj)
	{
		printf("%s->CDrawPolicyA::draw_core()\n", obj->getName());
	}
};

//draw�����p�|���V�[�N���X�F�p�^�[���a
class CDrawPolicyB
{
public:
	void draw_core(ISceneObject* obj)
	{
		printf("%s->CDrawPolicyB::draw_core()\n", obj->getName());
	}
};

//��l��
class CHero : public CSceneObject<CUpdatePolicyA, CDrawPolicyA>
{
public:
	const char* getName() override { return "CHero"; }
};

//�G
class CEnemy : public CSceneObject<CUpdatePolicyB, CDrawPolicyA>
{
public:
	const char* getName() override { return "CEnemy"; }
};

//�~�T�C��
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

//�|���V�[�e�X�g
void testPolicy()
{
	printf("\n- testPolicy() -\n\n");

	//�V�[���I�u�W�F�N�g�̃��X�g����
	ISceneObject* scene_objs[] = {
		new CHero,
		new CEnemy,
		new CMissile
	};
	//update���s�p�֐��I�u�W�F�N�g
	struct update_functor{ void operator()(ISceneObject* obj){ obj->update(); } };
	//draw���s�p�֐��I�u�W�F�N�g
	struct draw_functor{ void operator()(ISceneObject* obj){ obj->draw(); } };
	//delete�p�֐��I�u�W�F�N�g
	struct delete_functor{ void operator()(ISceneObject* obj){ delete obj; } };
	//�S�V�[���I�u�W�F�N�g��update���s
	printf("[update]\n");
	for_each(scene_objs, update_functor());
	//�S�V�[���I�u�W�F�N�g��draw���s
	printf("[draw]\n");
	for_each(scene_objs, draw_functor());
	//�S�V�[���I�u�W�F�N�g��delete
	for_each(scene_objs, delete_functor());
}

// End of file
