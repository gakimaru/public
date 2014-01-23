#include <stdio.h>

//�e�N���X�i�e���v���[�g�j
template<class D>
class CBase
{
public:
	void foo() const
	{
		printf("CBase<D>::foo()\n");
		static_cast<const D&>(*this).bar();	//�q�N���X�̃����o�[���Ăяo��
	}
};

//�q�N���X
class CDerived : public CBase<CDerived>	//�e�N���X�̃e���v���[�g�p�����[�^�Ɏ����i�q�N���X�j��n���Ă���
{
	friend class CBase<CDerived>;
private:
	void bar() const
	{
		printf("CDerived::bar()\n");
	}
};

//CRTP�̃e�X�g
void testCRTP()
{
	printf("\n- testCRTP() -\n\n");

	CDerived obj;
	obj.foo();
}

//--------------------------------------------------------------------------------

//�V�[���I�u�W�F�N�g�p�C���^�[�t�F�[�X�N���X
class ISceneObject
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
//	virtual const char* getName() = 0;//�폜
};

//�V�[���I�u�W�F�N�g�p�e���v���[�g�N���X
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

//update�����p�|���V�[�N���X�F�p�^�[���`
class CUpdatePolicyA
{
public:
	template<class O, class T>
	void update_core(T* obj)
	{
		printf("%s->CUpdatePolicyA::update_core()\n", static_cast<O*>(obj)->getName());
	}
};

//update�����p�|���V�[�N���X�F�p�^�[���a
class CUpdatePolicyB
{
public:
	template<class O, class T>
	void update_core(T* obj)
	{
		printf("%s->CUpdatePolicyB::update_core()\n", static_cast<O*>(obj)->getName());
	}
};

//draw�����p�|���V�[�N���X�F�p�^�[���`
class CDrawPolicyA
{
public:
	template<class O, class T>
	void draw_core(T* obj)
	{
		printf("%s->CDrawPolicyA::draw_core()\n", static_cast<O*>(obj)->getName());
	}
};

//draw�����p�|���V�[�N���X�F�p�^�[���a
class CDrawPolicyB
{
public:
	template<class O, class T>
	void draw_core(T* obj)
	{
		printf("%s->CDrawPolicyB::draw_core()\n", static_cast<O*>(obj)->getName());
	}
};

//��l��
class CHero : public CSceneObject<CHero, CUpdatePolicyA, CDrawPolicyA>
{
	friend class CUpdatePolicyA;
	friend class CDrawPolicyA;
private:
	const char* getName() { return "CHero"; }//��opverride
};

//�G
class CEnemy : public CSceneObject<CEnemy, CUpdatePolicyB, CDrawPolicyA>
{
	friend class CUpdatePolicyB;
	friend class CDrawPolicyA;
private:
	const char* getName() { return "CEnemy"; }//��opverride
};

//�~�T�C��
class CMissile : public CSceneObject<CMissile, CUpdatePolicyB, CDrawPolicyB>
{
	friend class CUpdatePolicyB;
	friend class CDrawPolicyB;
private:
	const char* getName() { return "CMissile"; }//��opverride
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

//�|���V�[��CRTP�e�X�g
void testPolicyAndCRTP()
{
	printf("\n- testPolicyAndCRTP() -\n\n");

	//�V�[���I�u�W�F�N�g�̃��X�g����
	ISceneObject* scene_objs[] = {
		new CHero,
		new CEnemy,
		new CMissile
	};
	//update���s�p�֐��I�u�W�F�N�g
	struct update_functor{ inline void operator()(ISceneObject* obj){ obj->update(); } };
	//draw���s�p�֐��I�u�W�F�N�g
	struct draw_functor{ inline void operator()(ISceneObject* obj){ obj->draw(); } };
	//delete�p�֐��I�u�W�F�N�g
	struct delete_functor{ inline void operator()(ISceneObject* obj){ delete obj; } };
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
