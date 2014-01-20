#include <stdio.h>

//����vtable�̃e�X�g

//----------
//���N���X
class CBase
{
	//----------���z�֐��e�[�u�������i���N���X�����ɕK�v�j----------
protected:
	//���z�֐��e�[�u���\���̒�`
	struct VTABLE
	{
		//static�֐��|�C���^�[�̃e�[�u�� ��this�|�C���^�[���󂯎�邽�߁A�K���������� void* �^
		void(*v_methodA)(void*);
		int(*v_methodB)(void*);
		int(*v_methodC)(void*, int, char);
	};
public:
	//���z�֐��Ăяo���e�[�u���\���̒�`
	struct CALL_TABLE
	{
		//�y���z�֐��Ώہz�ʏ탁�\�b�h�Ɠ������O�ƈ����̃��\�b�h���`���A���z�֐��e�[�u���̃��\�b�h�� this �|�C���^�[�t���ŌĂяo��
		void methodA(){ m_vtable->v_methodA(m_this); }
		int methodB(){ return m_vtable->v_methodB(m_this); }
		int methodC(int par1, char par2){ return m_vtable->v_methodC(m_this, par1, par2); }
		//�R���X�g���N�^
		CALL_TABLE(void* this_, VTABLE* vtable) :
			m_this(this_),
			m_vtable(vtable)
		{}
	private:
		//�t�B�[���h
		void* m_this;    //this �|�C���^�[
		VTABLE* m_vtable;//���z�֐��e�[�u��
	};
public:
	//�A�N�Z�b�T
	CALL_TABLE& getCallTable() { return m_callTable; } //���z�֐��Ăяo���e�[�u���擾
protected:
	//�t�B�[���h
	CALL_TABLE m_callTable;//���z�֐��Ăяo���e�[�u��
protected:
	//�R���X�g���N�^
	CBase(VTABLE* vtable) :                           //�q�N���X�p�ɁA�p�����[�^���󂯎��R���X�g���N�^���p��
		m_callTable(static_cast<void*>(this), vtable) //�K�����z�֐��Ăяo���e�[�u��������������
	{}

	//----------���z�֐��p����----------
public:
	//�y���z�֐��Ώہz�ʏ탁�\�b�h
	void methodA(){ printf("CBase::methoA()\n"); }
	int methodB(){ printf("CBase::methoB()\n"); return 0; }
	int methodC(int par1, char par2){ printf("CBase::methoC(%d, %d)\n", par1, par2); return 0; }
public:
	//�y���z�֐��Ώہz�ʏ탁�\�b�h���Ăяo��static���\�b�h�@�� this �|�C���^�[�{�ʏ탁�\�b�h�̈������󂯎��Athis �|�C���^�[�̒ʏ탁�\�b�h���Ăяo��
	static void s_methodA(void* this_){ static_cast<CBase*>(this_)->methodA(); }
	static int s_methodB(void* this_){ return static_cast<CBase*>(this_)->methodB(); }
	static int s_methodC(void* this_, int par1, char par2){ return static_cast<CBase*>(this_)->methodC(par1, par2); }
private:
	//static�t�B�[���h
	static VTABLE s_vtalble;//���z�֐��e�[�u��

	//----------�ʏ폈��----------
public:
	//.....
	
public:
	//�R���X�g���N�^
	CBase() :
		CBase(&s_vtalble) //�K�����z�֐��Ăяo���e�[�u��������������i�������̂��߂̃R���X�g���N�^���Ăяo���j
	{}
};

//----------���z�֐��p����----------
//static���z�֐��e�[�u����������
CBase::VTABLE CBase::s_vtalble = {
	&CBase::s_methodA,
	&CBase::s_methodB,
	&CBase::s_methodC
};

//----------
//�q�N���XA
class CClassA : public CBase
{
	//----------���z�֐��p����----------
public:
	//�y���z�֐��Ώہz�ʏ탁�\�b�h
	void methodA(){ printf("CClassA::methoA()\n"); }
	int methodB(){ printf("CClassA::methoB()\n"); return 0; }
	int methodC(int par1, char par2){ printf("CClassA::methoC(%d, %d)\n", par1, par2); return 0; }
public:
	//�y���z�֐��Ώہz�ʏ탁�\�b�h���Ăяo��static���\�b�h�@�� this �|�C���^�[�{�ʏ탁�\�b�h�̈������󂯎��Athis �|�C���^�[�̒ʏ탁�\�b�h���Ăяo��
	static void s_methodA(void* this_){ static_cast<CClassA*>(this_)->methodA(); }
	static int s_methodB(void* this_){ return static_cast<CClassA*>(this_)->methodB(); }
	static int s_methodC(void* this_, int par1, char par2){ return static_cast<CClassA*>(this_)->methodC(par1, par2); }
private:
	//static�t�B�[���h
	static VTABLE s_vtalble;//���z�֐��e�[�u��

	//----------�ʏ폈��----------
public:
	//.....

public:
	//�R���X�g���N�^
	CClassA() :
		CBase(&s_vtalble) //�e�N���X�̃R���X�g���N�^���Ăяo���A�K�����z�֐��Ăяo���e�[�u��������������
	{}
};

//----------���z�֐��p����----------
//static���z�֐��e�[�u����������
CBase::VTABLE CClassA::s_vtalble = {
	&CClassA::s_methodA,
	&CClassA::s_methodB,
	&CClassA::s_methodC
};

//----------
//�q�N���XB
class CClassB : public CBase
{
	//----------���z�֐��p����----------
public:
	//�y���z�֐��Ώہz�ʏ탁�\�b�h
	void methodA(){ printf("CClassB::methoA()\n"); }
	int methodB(){ printf("CClassB::methoB()\n"); return 0; }
	//methodC�̓I�[�o�[���C�h���Ȃ�
public:
	//�y���z�֐��Ώہz�ʏ탁�\�b�h���Ăяo��static���\�b�h�@�� this �|�C���^�[�{�ʏ탁�\�b�h�̈������󂯎��Athis �|�C���^�[�̒ʏ탁�\�b�h���Ăяo��
	static void s_methodA(void* this_){ static_cast<CClassB*>(this_)->methodA(); }
	static int s_methodB(void* this_){ return static_cast<CClassB*>(this_)->methodB(); }
	//methodC�̓I�[�o�[���C�h���Ȃ�
private:
	//static�t�B�[���h
	static VTABLE s_vtalble;//���z�֐��e�[�u��

	//----------�ʏ폈��----------
public:
	//.....

public:
	//�R���X�g���N�^
	CClassB() :
		CBase(&s_vtalble) //�e�N���X�̃R���X�g���N�^���Ăяo���A�K�����z�֐��Ăяo���e�[�u��������������
	{}
};

//----------���z�֐��p����----------
//static���z�֐��e�[�u����������
CBase::VTABLE CClassB::s_vtalble = {
	&CClassB::s_methodA,
	&CClassB::s_methodB,
	&CBase::s_methodC   //�I�[�o�[���C�h���Ȃ��ꍇ�́A�e�̃��\�b�h���w��
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

//����vtable�e�X�g
void testVTable()
{
	printf("\n- testVTable() -\n\n");

	//�I�u�W�F�N�g�̃��X�g����
	CBase* objs[] = {
		new CBase,
		new CClassA,
		new CClassB
	};
	//�֐��I�u�W�F�N�g
	struct functor{
		void operator()(CBase* obj){
			CBase::CALL_TABLE& ctbl = obj->getCallTable(); //���z�֐��Ăяo���e�[�u�����擾���Ă���A���z�֐����Ăяo��
			ctbl.methodA();
			ctbl.methodB();
			ctbl.methodC(12, 34);
		}
	};
	//�S�I�u�W�F�N�g�̏������s
	for_each(objs, functor());
}

// End of file
