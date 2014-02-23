#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>//uintptr_t�p
#include <limits.h>//INT_MAX�p
#include <new>//�K��̔z�unew/�z�udelete�p

//C++11���C�u����
//#include <thread>//�X���b�h
//#include <atomic>//�A�g�~�b�N�^

//#define nullptr NULL
//#define override

//--------------------------------------------------------------------------------
//�Œ�o�b�t�@�p�z�unew�ŃR���X�g�N�^�Ăяo��

//�K��̔z�unew/�z�udelete
//��#include <new> �Œ�`����Ă���K��̔z�unew/�z�udelete
//�@  void* operator new(size_t, void* where);
//�@  void* operator new[](size_t, void* where);
//�@  void operator delete(void*, void*);
//�@  void operator delete[](void*, void*);
//�@  void* operator new(size_t size, const nothrow_t&);//��O���X���[���Ȃ�
//�@  void* operator new[](size_t size, const nothrow_t&);//��O���X���[���Ȃ�
//�@  void operator delete(void*, const nothrow_t&);//��O���X���[���Ȃ�
//�@  void operator delete[](void*, const nothrow_t&);//��O���X���[���Ȃ�

#define USE_NEW_PTR_FOR_TEST0//new�֐����g�p���Ȃ��Ƃ��̓R�����g�A�E�g����
#ifdef USE_NEW_PTR_FOR_TEST0
//--------------------
//�z�unew�pnew�֐�
//���ϒ��e���v���[�g�������g�p���āA�R���X�g���N�^�̈������擾
template<class T, typename... Tx>
T* new_ptr(char* buff, Tx... nx)
{
	if (!buff)
		return nullptr;
	return new(buff)T(nx...);//�z�unew�Ăяo���i�R���X�g���N�^�͉ϒ��䐔�n���j
}
//���z��ł�new�֐��͂Ȃ�
//���N���X��delete�Ƒ΂̃N���X��new��p�����ق����悢
#endif//USE_DELETE_PTR_FOR_TEST0

#define USE_DELETE_PTR_FOR_TEST0//delete�֐����g�p���Ȃ��Ƃ��̓R�����g�A�E�g����
#ifdef USE_DELETE_PTR_FOR_TEST0
//--------------------
//�z�udelete�pdelete�֐�
template<class T>
void delete_ptr(T*& p, char* buff)
{
	if (!p)
		return;
	p->~T();//�f�X�g���N�^�Ăяo���i�f�X�g���N�^����`����Ă��Ȃ��^��v���~�e�B�u�^�ł����Ȃ��j
	//operator delete(p, p);//�z�udelete�̌Ăяo���͕s�v
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//���z��ł�delete�֐��͂Ȃ�
//���^�Ƀf�X�g���N�^����`����Ă��邩�ǂ������C�ɂ����g�����悤�Ȕėp���������Ȃ�����
//���N���X��delete��p���邱�Ƃł��̖��������ł���
#endif//USE_DELETE_PTR_FOR_TEST0

//--------------------
//�e�X�g�p�N���X
class CTest0
{
public:
	//�R���X�g���N�^
	CTest0(const char* name) :
		m_name(name)
	{
		printf("CTest0::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	~CTest0()
	{
		printf("CTest0::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	const char* m_name;//���O
};

//--------------------
//�e�X�g
void test0()
{
	printf("---------- test0:�Œ�o�b�t�@�z�unew/�z�udelete ----------\n");
	char buff[32];//�C���X�^���X�p�̃o�b�t�@
	printf("buff=0x%p\n", buff);
#ifdef USE_NEW_PTR_FOR_TEST0
	CTest0* obj_p = new_ptr<CTest0>(buff, "�e�X�g0");
#else//USE_NEW_PTR_FOR_TEST0
	CTest0* obj_p = new(buff)CTest0("�e�X�g0");
#endif//USE_NEW_PTR_FOR_TEST0
	printf("obj_p=0x%p\n", obj_p);
#ifdef USE_DELETE_PTR_FOR_TEST0
	delete_ptr(obj_p, buff);//��pdelete�֐��ō폜�i�����Ńf�X�g���N�^���Ăяo���j
	printf("obj_p=0x%p\n", obj_p);//�폜��̃|�C���^���m�F
#else//USE_DELETE_PTR_FOR_TEST0
	obj_p->~CTest0();//�����I�ȃf�X�g���N�^�Ăяo��
	operator delete(obj_p, buff);//operator delete �Ŕz�udelete���Ăяo���i�f�X�g���N�^���Ăяo����Ȃ��_�ɒ��Ӂj
#endif//USE_DELETE_PTR_FOR_TEST0
}

//--------------------------------------------------------------------------------
//�����m�F�̂��߂̔z�unew / �z�udelete

//--------------------
//�z�unew/�z�udelete
//�����ꂼ���2������ char* �����A����̊֐����I�[�o�[���[�h����
//�P��new
void* operator new(const std::size_t size, char* where)
{
	printf("placement new(size=%d, where=0x%p)\n", size, where);
	return where;//�n���ꂽ�o�b�t�@�����̂܂ܕԂ�
}
//�z��new
//���f�X�g���N�^���������^�̏ꍇ�A�o�b�t�@�̐擪�ɗv�f�����i�[���邽�߂ɁA�����傫�ȃT�C�Y���n�����
//�@���̎��A�߂�l�̃|�C���^�́A�֐��𔲂������A�v�f�����̕����V�t�g�����|�C���^�ɕϊ������
//�@�^�̃A���C�������g�ɂ���Ă͑傫���V�t�g����\��������
//�@�f�X�g���N�^�������Ȃ��^�������̓v���~�e�B�u�^�ł͂��̏��͈����Ȃ��i�Ȃ̂ł�₱�����j
void* operator new[](const std::size_t size, char* where)
{
	printf("placement new[](size=%d, where=0x%p)\n", size, where);
	return where;//�n���ꂽ�o�b�t�@�����̂܂ܕԂ�
}
//�P��delete
//���z�unew�Ƒ΂ɂȂ�z�udelete�͕K�{
//�@�i�R���X�g���N�^�ŗ�O����������Ǝ����I�ɌĂяo����邽�߁j
void operator delete(void* p, char* where)
{
	printf("placement delete(p=0x%p, where=0x%p)\n", p, where);
	//�Ȃɂ����Ȃ�
}
//�z��delete
//���f�X�g���N�^���������^�̃|�C���^�ł����Ă��A�󂯓n���ꂽ�|�C���^�����̂܂܈�����̂Œ���
//�@�i�������m�ێ��̐��m�ȃ|�C���^��������Ȃ��j
//���N���X��delete�֐����g�p���邱�Ƃł��̖��������ł���
void operator delete[](void* p, char* where)
{
	printf("placement delete[](p=0x%p, where=0x%p)\n", p, where);
	//�Ȃɂ����Ȃ�
}

//--------------------
//�Œ�o�b�t�@�pdelete�֐�
//���f�X�g���N�^���Ăяo���e���v���[�g�֐�
template<class T>
void delete_ptr(T*& p)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p)\n", p);
	p->~T();//�f�X�g���N�^�Ăяo��
	operator delete(p, reinterpret_cast<char*>(p));//�z�udelete�Ăяo��
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//�����̊m�F�̂��߂ɔz��ł�delete�֐����p��
//�i�c�O�Ȃ���j�z��̗v�f�����󂯓n��
template<class T>
void delete_ptr(T*& p, const std::size_t array_num)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, array_num=%d)\n", p, array_num);
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//�f�X�g���N�^�Ăяo��
	operator delete[](p, reinterpret_cast<char*>(p));//�z�udelete�Ăяo��
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}

//--------------------
//�e�X�g�p�N���X
//#define DELETE_DESTRUCTOR_FOR_CTEST1//�f�X�g���N�^���g�p����Ƃ��̓R�����g�A�E�g
//__declspec(align(8))//8�o�C�g�A���C�������g�Ńe�X�g����ꍇ�͂��̍s��L���ɂ���
class CTest1
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTest1() :
		CTest1("(default)")//���̃R���X�g���N�^�Ăяo���FC++11�Œǉ����ꂽ�\��
		//m_name("(default)")//C++11���g���Ȃ��ꍇ�͕��ʂɏ�����
	{
		printf("CTest1::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CTest1(const char* name) :
		m_name(name)
	{
		printf("CTest1::Constructor : name=\"%s\"\n", m_name);
	}
#ifndef DELETE_DESTRUCTOR_FOR_CTEST1
	//�f�X�g���N�^
	~CTest1()
	{
		printf("CTest1::Destructor : name=\"%s\"\n", m_name);
	}
#endif//DELETE_DESTRUCTOR_FOR_CTEST1
protected:
	//�t�B�[���h
	const char* m_name;//���O
	int m_dummy;//�_�~�[
};
//--------------------
//�e�X�g�p�N���X�i���d�p���e�X�g�p�j
class CTest1ex
{
public:
	//�R���X�g���N�^
	CTest1ex()
	{
		printf("CTest1ex::Constructor\n");
	}
	//�f�X�g���N�^
	~CTest1ex()
	{
		printf("CTest1ex::Destructor\n");
	}
protected:
	//�t�B�[���h
	int m_dummy;//�_�~�[
};
//--------------------
//�e�X�g�p�N���X�i���d�p���j
class CDerivedTest1 : public CTest1, public CTest1ex
{
public:
	//�f�t�H���g�R���X�g���N�^
	CDerivedTest1() :
		CTest1(),
		CTest1ex()
	{
		printf("CDerivedTest1::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CDerivedTest1(const char* name) :
		CTest1(name),
		CTest1ex()
	{
		printf("CDerivedTest1::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	~CDerivedTest1()
	{
		printf("CDerivedTest1::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	int m_dummy;//�_�~�[
};

//--------------------
//�e�X�g
void test1()
{
	printf("---------- test1:�Œ�o�b�t�@�z�unew/�z�udelete�i�����m�F�j----------\n");
	//�Œ�o�b�t�@�ŃN���X�̃C���X�^���X�𐶐�
	{
		printf("----------�N���X\n");
		char buff[32];//�C���X�^���X�p�̃o�b�t�@
		printf("buff=0x%p\n", buff);
		CTest1* obj_p = new(buff)CTest1("�e�X�g1");
		printf("obj_p=0x%p\n", obj_p);
		delete_ptr(obj_p);
	}
	//�Œ�o�b�t�@�ŃN���X�z��̃C���X�^���X�𐶐�
	{
		printf("----------�N���X�̔z��\n");
		char buff[64];//�C���X�^���X�p�̃o�b�t�@
		printf("buff=0x%p\n", buff);
		const int array_num = 3;
		CTest1* obj_p = new(buff)CTest1[array_num]();
		printf("obj_p=0x%p\n", obj_p);
		printf("*reinterpret_cast<int*>(buff)=%d\n", *reinterpret_cast<int*>(buff));//�f�X�g���N�^���������^�̔z��́A�o�b�t�@�̐擪�ɗv�f�����i�[����Ă���
		delete_ptr(obj_p, array_num);
	}
	//�Œ�o�b�t�@�Ńv���~�e�B�u�^�̃C���X�^���X�𐶐�
	{
		printf("----------�v���~�e�B�u�^\n");
		char buff[32];//�C���X�^���X�p�̃o�b�t�@
		printf("buff=0x%p\n", buff);
		char* data_p = new(buff)char;
		printf("data_p=0x%p\n", data_p);
		*data_p = 123;
		printf("*data_p(0x%p)=%d\n", data_p, *data_p);
		delete_ptr(data_p);//�f�X�g���N�^�̂Ȃ��^�Ŏ��s���Ă����Ȃ�
	}
	//�Œ�o�b�t�@�Ńv���~�e�B�u�^�̔z��̃C���X�^���X�𐶐�
	{
		printf("----------�v���~�e�B�u�^�̔z��\n");
		char buff[32];//�C���X�^���X�p�̃o�b�t�@
		printf("buff=0x%p\n", buff);
		const int array_num = 3;
		char* data_p = new(buff)char[array_num];
		printf("data_p=0x%p\n", data_p);
		printf("*reinterpret_cast<int*>(buff)=%d\n", *reinterpret_cast<int*>(buff));//�f�X�g���N�^�������Ȃ��^�̔z��́A�o�b�t�@�ɗv�f�����i�[���Ă��Ȃ�
		data_p[0] = 123;
		printf("*data_p(0x%p)[0]=%d\n", data_p, data_p[0]);
		delete_ptr(data_p, array_num);//�f�X�g���N�^�̂Ȃ��^�Ŏ��s���Ă����Ȃ�
	}
	//�Œ�o�b�t�@�ő��d�p�������N���X�̃C���X�^���X�𐶐�
	{
		printf("----------���d�p���N���X\n");
		char buff[32];//�C���X�^���X�p�̃o�b�t�@
		printf("buff=0x%p\n", buff);
		CDerivedTest1* obj_p = new(buff)CDerivedTest1("�e�X�g1���d�p��");
		CTest1* parent_p = obj_p;//�e1�ɃL���X�g
		CTest1ex* parent_ex_p = obj_p;//�e2�ɃL���X�g
		printf("obj_p=0x%p, parent_p=0x%p, parent_ex_p=0x%p\n", obj_p, parent_p, parent_ex_p);
		//delete_ptr(obj_p);
		//delete_ptr(parent_p);
		delete_ptr(parent_ex_p);
	}
}

//--------------------------------------------------------------------------------
//�N���X��new

//--------------------
//CTest2�N���X�C���X�^���X�p�o�b�t�@
static char s_buffForTestClass2[32];

//--------------------
//�e�X�g�p�N���X
//#define USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2//size�t����delete�֐����g�p����Ƃ��̓R�����g�A�E�g
//#define DELETE_DESTRUCTOR_FOR_CTEST2//�f�X�g���N�^���g�p����Ƃ��̓R�����g�A�E�g
class CTest2
{
public:
	//�I�y���[�^
	//�N���X��new/delete
	//�����N���X�̃C���X�^���X��p��new/delete
	//����2�������Ȃ��̂ŁA�z�unew/�z�udelete�Ƃ��������ł͂Ȃ����A�����悤�Ɏg�p�ł���
	//���N���X��new/delete���z�unew/�z�udelete�͎g�p��
	//��static�͂����Ă��Ȃ��Ă��悢�i�K��static�����ɂȂ�j
	static void* operator new(const std::size_t size)
	{
		printf("placement CTest2::new(size=%d)\n", size);
		return s_buffForTestClass2;//�Œ�o�b�t�@��Ԃ�
	}
	static void* operator new[](const std::size_t size)
	{
		printf("placement CTest2::new[](size=%d)\n", size);
		return s_buffForTestClass2;//�Œ�o�b�t�@��Ԃ�
	}
#ifdef USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
	//���N���X��delete�͋K���delete��2��ނ���
	//������͕W���I�ȃX�^�C��
	static void operator delete(void* p)
	{
		printf("placement CTest2::delete(p=0x%p)\n", p);
		//�Ȃɂ����Ȃ�
	}
	static void operator delete[](void* p)
	{
		printf("placement CTest2::delete[](p=0x%p)\n", p);
		//�Ȃɂ����Ȃ�
	}
#else//USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
	//���N���X��delete�ł́A��2������ size_t �����`���W���X�^�C���̈�i��z�udelete�j
	//��2��ނƂ���`������Aoperator delete(void*) �̕����D��
	static void operator delete(void* p, const std::size_t size)
	{
		printf("placement CTest2::delete(p=0x%p, size=%d)\n", p, size);
		//�Ȃɂ����Ȃ�
	}
	static void operator delete[](void* p, const std::size_t size)
	{
		printf("placement CTest2::delete[](p=0x%p, size=%d)\n", p, size);
		//�Ȃɂ����Ȃ�
	}
#endif//USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
public:
	//�f�t�H���g�R���X�g���N�^
	CTest2() :
		CTest2("(default)")//���̃R���X�g���N�^�Ăяo���FC++11�Œǉ����ꂽ�\��
		//m_name("(default)")//C++11���g���Ȃ��ꍇ�͕��ʂɏ�����
	{
		printf("CTest2::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CTest2(const char* name) :
		m_name(name)
	{
		printf("CTest2::Constructor : name=\"%s\"\n", m_name);
	}
#ifndef DELETE_DESTRUCTOR_FOR_CTEST2
	//�f�X�g���N�^
	virtual ~CTest2()
	{
		printf("CTest2::Destructor : name=\"%s\"\n", m_name);
	}
#endif//DELETE_DESTRUCTOR_FOR_CTEST2
protected:
	//�t�B�[���h
	const char* m_name;//���O
	int m_dummy;//�_�~�[
};
//--------------------
//�e�X�g�p�N���X�i���d�p���e�X�g�p�j
class CTest2ex
{
public:
	//�I�y���[�^
	//�N���X��new
	static void* operator new(const std::size_t size)
	{
		printf("placement CTest2ex::new(size=%d)\n", size);
		return s_buffForTestClass2;//�Œ�o�b�t�@��Ԃ�
	}
	//�N���X��delete
	static void operator delete(void* p)
	{
		printf("placement CTest2ex::delete(p=0x%p)\n", p);
		//�Ȃɂ����Ȃ�
	}
public:
	//�R���X�g���N�^
	CTest2ex()
	{
		printf("CTest2ex::Constructor\n");
	}
	//�f�X�g���N�^
	virtual ~CTest2ex()
	{
		printf("CTest2ex::Destructor\n");
	}
protected:
	//�t�B�[���h
	int m_dummy;//�_�~�[
};
//--------------------
//�e�X�g�p�N���X�i���d�p���j
class CDerivedTest2 : public CTest2, public CTest2ex
{
public:
	//�I�y���[�^
	//�N���X��new
	static void* operator new(const std::size_t size)
	{
		printf("placement CDerivedTest2::new(size=%d)\n", size);
		return s_buffForTestClass2;//�Œ�o�b�t�@��Ԃ�
	}
	//�N���X��delete
	static void operator delete(void* p)
	{
		printf("placement CDerivedTest2::delete(p=0x%p)\n", p);
		//�Ȃɂ����Ȃ�
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CDerivedTest2() :
		CTest2(),
		CTest2ex()
	{
		printf("CDerivedTest2::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CDerivedTest2(const char* name) :
		CTest2(name),
		CTest2ex()
	{
		printf("CDerivedTest2::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	~CDerivedTest2() override
	{
		printf("CDerivedTest2::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	int m_dummy;//�_�~�[
};

//--------------------
//�e�X�g
void test2()
{
	printf("---------- test2:�N���X��new/delete ----------\n");
	{
		printf("----------�N���X\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CTest2* obj_p = new CTest2("�e�X�g2");
		printf("obj_p=0x%p\n", obj_p);
		delete obj_p;//���ʂ́ioperator ��t���Ȃ��jdelete�Ƃ��ČĂяo����
	}
	{
		printf("----------�N���X�̔z��\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CTest2* obj_p = new CTest2[3];
		printf("obj_p=0x%p\n", obj_p);
		printf("*reinterpret_cast<int*>(s_buffForTestClass2)=%d\n", *reinterpret_cast<int*>(s_buffForTestClass2));//�f�X�g���N�^���������^�̔z��́A�o�b�t�@�̐擪�ɗv�f�����i�[����Ă���
		delete[] obj_p;//���ʂ́ioperator ��t���Ȃ��jdelete[]�Ƃ��ČĂяo����
	}
	{
		printf("----------���d�p���N���X\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CDerivedTest2* obj_p = new CDerivedTest2("�e�X�g2���d�p��");
		CTest2* parent_p = obj_p;//�e1�ɃL���X�g
		CTest2ex* parent_ex_p = obj_p;//�e2�ɃL���X�g
		printf("obj_p=0x%p, parent_p=0x%p, parent_ex_p=0x%p\n", obj_p, parent_p, parent_ex_p);
		//delete obj_p;
		//delete parent_p;
		delete parent_ex_p;
	}
}

//--------------------------------------------------------------------------------
//�Œ�o�b�t�@�V���O���g���̃e�X�g

//--------------------
//�Œ�o�b�t�@�V���O���g���e���v���[�g�N���X
template<class T>
class CSingleton
{
	friend void* operator new(const std::size_t size, CSingleton<T>& singleton);
public:
	//�I�y���[�^�i�V���O���g���{�̂̃v���L�V�[�j
	T* operator->(){ return m_ptr; }
public:
	//���\�b�h
	//�����I�ȍ폜
	void destroy();
public:
	//�R���X�g���N�^
	CSingleton();
private:
	//�t�B�[���h
	static T* m_ptr;//�V���O���g���{�̎Q��
	static char m_buff[];//�V���O���g���{�̗p�o�b�t�@
};

//--------------------
//�e���v���[�g�z�unew
template<class T>
void* operator new(const std::size_t size, CSingleton<T>& singleton)
{
	printf("placement new<T>(size=%d, singleton.m_buff=0x%p)\n", size, singleton.m_buff);
	return singleton.buff;
}
//�e���v���[�g�z�udelete
template<class T>
void operator delete(void* p, CSingleton<T>& singleton)
{
	printf("placement delete<T>(p=0x%p, singleton.m_buff=0x%p)\n", p, singleton.m_buff);
}

//--------------------
//�Œ�o�b�t�@�V���O���g���e���v���[�g�N���X�F������
//�����I�ȍ폜
template<class T>
void CSingleton<T>::destroy()
{
	if (!m_ptr)
		return;
	m_ptr->~T();//�f�X�g���N�^�Ăяo��
	operator delete(m_ptr, m_buff);
	m_ptr = nullptr;
}
//�R���X�g���N�^
template<class T>
CSingleton<T>::CSingleton()
{
	//�܂����������Ă��Ȃ���Ώ�����
	if (!m_ptr)
		m_ptr = new(m_buff)T();
}
//�ÓI�ϐ�
template<class T>
T* CSingleton<T>::m_ptr = nullptr;//�V���O���g���Q��
template<class T>
char CSingleton<T>::m_buff[sizeof(T)];//�V���O���g���p�o�b�t�@

//--------------------
//�e�X�g�p�N���X
class CTest3
{
public:
	//�A�N�Z�b�T
	int getData() const { return m_data; }
	void setData(const int data){ m_data = data; }
public:
	//�R���X�g���N�^
	CTest3() :
		m_data(0)
	{
		printf("CTest3::Constructor : m_data=%d\n", m_data);
	}
	//�f�X�g���N�^
	~CTest3()
	{
		printf("CTest3::Destructor : m_data=%d\n", m_data);
	}
private:
	//�t�B�[���h
	int m_data;//�f�[�^
};

//--------------------
//�e�X�g
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
//�X�^�b�N�A���P�[�^

//--------------------
//�X�^�b�N�A���P�[�^
class CStackAllocator
{
public:
	//�^
	typedef std::size_t MARKER;
public:
	//�A�N�Z�b�T
	MARKER getMarker() const { return m_used; }//���݂̃X�^�b�N�}�[�J�[���擾
public:
	//���\�b�h
	//�������m��
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
	//���������ȑO�̃}�[�J�[�ɖ߂�
	void back(const MARKER marker)
	{
		if (marker >= m_used)
			return;
		m_used = marker;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	void back(const void* p)
	{
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
		back(marker);
	}
	//�������j��
	void clear()
	{
		m_used = 0;
	}
public:
	//�R���X�g���N�^
	CStackAllocator(char* buff_p, const std::size_t buff_size) :
		m_buffPtr(buff_p),
		m_buffSize(buff_size),
		m_used(0)
	{}
	//�f�X�g���N�^
	~CStackAllocator()
	{}
private:
	//�t�B�[���h
	char* m_buffPtr;//�o�b�t�@
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	MARKER m_used;//�g�p�ς݃T�C�Y
};

//--------------------
//�z�unew
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
//�z�udelete
void operator delete(void* p, CStackAllocator& allocator)
{
	printf("placement delete(p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	//�Ȃɂ����Ȃ�
	//allocator.back(p) �����s���Ȃ�
}
void operator delete[](void* p, CStackAllocator& allocator)
{
	printf("placement delete[](p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	//�Ȃɂ����Ȃ�
	//allocator.back(p) �����s���Ȃ�
}
//�f�X�g���N�^�Ăяo���t��delete
template<class T>
void delete_ptr(T*& p, CStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	p->~T();
	p = nullptr;
	//�Ȃɂ����Ȃ�
	//allocator.back(p) �����s���Ȃ�
}

//--------------------
//�o�b�t�@�t���X�^�b�N�A���P�[�^
template<std::size_t SIZE>
class CBufferedStackAllocator : public CStackAllocator
{
public:
	//�萔
	static const std::size_t STACK_SIZE = SIZE;//�X�^�b�N�T�C�Y
public:
	//�R���X�g���N�^
	CBufferedStackAllocator() :
		CStackAllocator(m_buff, STACK_SIZE)
	{}
	//�f�X�g���N�^
	~CBufferedStackAllocator()
	{}
private:
	//�t�B�[���h
	char m_buff[STACK_SIZE];//�X�^�b�N�̈�T�C�Y
};

//--------------------
//�e�X�g
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
//�o�����X�^�b�N�A���P�[�^

//--------------------
//�o�����X�^�b�N�A���P�[�^
class CDualStackAllocator
{
public:
	//�萔
	enum E_ORDERED
	{
		NORMAL,//����
		REVERSE//�t��
	};
public:
	//�^
	typedef std::size_t MARKER;
public:
	//�A�N�Z�b�T
	MARKER getMarkerN() const { return m_usedN; }//���݂̃X�^�b�N�}�[�J�[�i�����j���擾
	MARKER getMarkerR() const { return m_usedR; }//���݂̃X�^�b�N�}�[�J�[�i�t���j���擾
public:
	//���\�b�h
	//�������m�ہi�����j
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
	//�������m�ہi�t���j
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
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	void backN(const MARKER marker_n)
	{
		if (marker_n >= m_usedN)
			return;
		m_usedN = marker_n;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	void backR(const MARKER marker_r)
	{
		if (marker_r <= m_usedR || marker_r > m_buffSize)
			return;
		m_usedR = marker_r;
	}
	//�������j��
	void clear()
	{
		clearN();
		clearR();
	}
	//�������j���i�����j
	void clearN()
	{
		m_usedN = 0;
	}
	//�������j���i�t���j
	void clearR()
	{
		m_usedR = m_buffSize;
	}
public:
	//�R���X�g���N�^
	CDualStackAllocator(char* buff_p, const std::size_t buff_size) :
		m_buffPtr(buff_p),
		m_buffSize(buff_size),
		m_usedN(0),
		m_usedR(buff_size)
	{}
	//�f�X�g���N�^
	~CDualStackAllocator()
	{}
private:
	//�t�B�[���h
	char* m_buffPtr;//�o�b�t�@
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	MARKER m_usedN;//�g�p�ς݃T�C�Y�i�����j
	MARKER m_usedR;//�g�p�ς݃T�C�Y�i�t���j
};

//--------------------
//�z�unew
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
//�z�udelete
void operator delete(void* p, CDualStackAllocator& allocator)
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//�Ȃɂ����Ȃ�
	//allocator.back(p) �����s���Ȃ�
}
void operator delete[](void* p, CDualStackAllocator& allocator)
{
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//�Ȃɂ����Ȃ�
	//allocator.back(p) �����s���Ȃ�
}
//�f�X�g���N�^�Ăяo���t��delete
template<class T>
void delete_ptr(T*& p, CDualStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	p->~T();
	p = nullptr;
	//�Ȃɂ����Ȃ�
	//allocator.back(p) �����s���Ȃ�
}

//--------------------
//�o�b�t�@�t���o�����X�^�b�N�A���P�[�^
template<std::size_t SIZE>
class CBufferedDualStackAllocator : public CDualStackAllocator
{
public:
	//�萔
	static const std::size_t STACK_SIZE = SIZE;//�X�^�b�N�T�C�Y
public:
	//�R���X�g���N�^
	CBufferedDualStackAllocator() :
		CDualStackAllocator(m_buff, STACK_SIZE)
	{}
	//�f�X�g���N�^
	~CBufferedDualStackAllocator()
	{}
private:
	//�t�B�[���h
	char m_buff[STACK_SIZE];//�X�^�b�N�̈�T�C�Y
};

//--------------------
//�e�X�g
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
//��{�}�N��

//�u���[�N�|�C���g
#include <windows.h>//�u���[�N�|�C���g�p
#define BREAK_POINT() DebugBreak()

//�f�o�b�O�v�����g
#define DEBUG_PRINT(msg, ...) printf(msg, __VA_ARGS__);
#define DEBUG_FPRINT(fp, msg, ...) fprintf(fp, msg, __VA_ARGS__);
#define DEBUG_FLUSH() fflush(stdout)
#define DEBUG_FFLUSH(fp) fflush(fp)
//#define DEBUG_PRINT(msg, ...)
//#define DEBUG_FPRINT(fp, msg, ...)
//#define DEBUG_FLUSH()
//#define DEBUG_FFLUSH(fp) fflush(fp)

//�����񉻃}�N��
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)
#define COLLECT_STRING(s) s

//�A�T�[�V����
#define ASSERT(expr, msg, ...) \
if (!(expr)) \
	{ \
	DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
	"  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
	"  "  msg "\n", __VA_ARGS__); \
	BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//�폜�p
//#include <assert.h>//assert�p
//#define ASSERT(expr, msg, ...) assert(expr)//VC++�W����

//�X���b�h���[�J���X�g���[�W�C���q
//��C++11�d�l�U���iVC++2013�ł͖��Ή��ɂ��j
//�����g��Windows�d�l
#define thread_local __declspec(thread)

//----------------------------------------
//�X���b�hID�N���X
//��TLS�����p���č�����

//�X���b�hID�^
//typedef std::thread::id THREAD_ID;//C++11/ �����̌^�ł͈��킸�A�n�b�V���l���g�p����
typedef std::size_t THREAD_ID;//C++11
static const THREAD_ID INVALID_THREAD_ID = 0xffffffff;//�����ȃX���b�hID

//���݂̃X���b�hID�擾�֐�
//inline THREAD_ID  GetThisThreadID(){ return std::this_thread::get_id(); } //C++11
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id().hash(); } //C++11

//�X���b�hID�N���X
class CThreadID
{
public:
	//�A�N�Z�b�T
	const THREAD_ID getID() const { return m_threadId; }//�X���b�hID���擾
	const char* getName() const { return m_threadName; }//�X���b�h�����擾
public:
	//�A�N�Z�b�T�istatic�j
	static THREAD_ID getThisID(){ return m_thisThreadID; }//���݂̃X���b�h�̃X���b�hID���擾
	static const char* getThisName(){ return m_thisThreadName; }//���݂̃X���b�h�̃X���b�h�����擾
public:
	//���\�b�h
	bool isThisThread() const { return m_threadId == getThisID(); }//���݂̃X���b�h�Ɠ����X���b�h������
private:
	//���\�b�h(static)
	static void setThisThread()//���݂̃X���b�h�̃X���b�hID���Z�b�g
	{
		if (m_thisThreadID == INVALID_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
	}
	static void resetThisThread(const char* name)//���݂̃X���b�h�̃X���b�hID�����Z�b�g
	{
		m_thisThreadID = GetThisThreadID();
		m_thisThreadName = name;
	}
public:
	//�I�y���[�^�i���j
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID��v����
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID�s��v����
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID��v����
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID�s��v����
	CThreadID& operator=(const CThreadID& o) //�R�s�[���Z�q
	{
		m_threadId = o.m_threadId;
		m_threadName = o.m_threadName;
		return *this;
	}
private:
	//�I�y���[�^�i�֎~�j
	CThreadID& operator=(const THREAD_ID& id) { return *this; }//�R�s�[���Z�q�i�֎~�j
public:
	//�R�s�[�R���X�g���N�^�i���j
	explicit CThreadID(const CThreadID& o) :
		m_threadId(o.m_threadId),
		m_threadName(o.m_threadName)
	{
	}
private:
	//�R�s�[�R���X�g���N�^�i�֎~�j
	explicit CThreadID(const THREAD_ID& id){}
public:
	//�R���X�g���N�^
	//���X���b�h�����w�肵�A�����Ō��݂̃X���b�hID���擾���ĕێ�
	//��TLS�ɂ��L�^
	CThreadID(const char* name)
	{
		resetThisThread(name);
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
	//�f�t�H���g�R���X�g���N�^
	//������TLS�ɋL�^�ς݂̃X���b�hID�i�Ɩ��O�j���擾
	CThreadID()
	{
		setThisThread();
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
private:
	//�t�B�[���h
	THREAD_ID m_threadId;//�X���b�hID�i�I�u�W�F�N�g�ɕۑ�����l�j
	const char* m_threadName;//�X���b�h���i�I�u�W�F�N�g�ɕۑ�����l�j
	static thread_local THREAD_ID m_thisThreadID;//���݂̃X���b�h�̃X���b�hID(TLS)
	static thread_local const char* m_thisThreadName;//���݂̃X���b�h��(TLS)
};
//static�ϐ��̃C���X�^���X��
thread_local THREAD_ID CThreadID::m_thisThreadID = INVALID_THREAD_ID;//�X���b�hID(TLS)
thread_local const char* CThreadID::m_thisThreadName = nullptr;//�X���b�h��(TLS)

//--------------------------------------------------------------------------------
//�y�ʃX�s�����b�N

//----------------------------------------
//�y�ʃX�s�����b�N
//����y�Ɏg����X�s�����b�N
//�����񐔂̃X���[�v���ƂɃX���[�v�i�R���e�L�X�g�X�C�b�`�j���s��
//���e�ʂ�4�o�C�g(std::atomic_flag����̃T�C�Y)
//���v���O���~���O��̈��S���͒Ⴂ�̂ŋC����Ɏg���ׂ��ł͂Ȃ�
//�@�@�˃��b�N�擾��Ԃ��m�F�����ɃA�����b�N����
#define SPIN_LOCK_USE_ATOMIC_FLAG//std::atomic_flag�Łi�����j
//#define SPIN_LOCK_USE_ATOMIC_BOOL//std::atomic_bool�Łi�y�ʁj
class CSpinLock
{
public:
	//�萔
	static const int DEFAULT_SPIN_COUNT = 1000;//�X�s�����b�N�J�E���g�̃f�t�H���g�l
public:
	//���b�N�擾
	void lock(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = 0;
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		while (m_lock.test_and_set())//std::atomic_flag�Łi�����j
		{
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		bool prev = false;
		while (m_lock.compare_exchange_weak(prev, true))//std::atomic_bool�Łi�y�ʁj
		{
			prev = false;
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
			if (spin_count == 0 || ++spin_count_now % spin_count == 0)
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//�X���[�v�i�R���e�L�X�g�X�C�b�`�j
		}
	}
	//���b�N���
	void unlock()
	{
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.clear();//std::atomic_flag�Łi�����j
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.store(false);//std::atomic_bool�Łi�y�ʁj
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
	}
public:
	//�R���X�g���N�^
	CSpinLock()
	{
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.clear();//���b�N�p�t���O�i�����j
#else//SPIN_LOCK_USE_ATOMIC_FLAG
		m_lock.store(false);//���b�N�p�t���O�i�y�ʁj
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
	}
	//�f�X�g���N�^
	~CSpinLock()
	{
	}
private:
	//�t�B�[���h
#ifdef SPIN_LOCK_USE_ATOMIC_FLAG
	std::atomic_flag m_lock;//���b�N�p�t���O�i�����j
#else//SPIN_LOCK_USE_ATOMIC_FLAG
	std::atomic_bool m_lock;//���b�N�p�t���O�i�y�ʁj
#endif//SPIN_LOCK_USE_ATOMIC_FLAG
};
#endif

//--------------------------------------------------------------------------------
//�v�[���A���P�[�^

//--------------------
//�N���X�錾
class CPoolAllocator;

//--------------------
//�z�unew
void* operator new(const std::size_t size, CPoolAllocator& allocator);
//�z�udelete
void operator delete(void* p, CPoolAllocator& allocator);

//----------------------------------------
//�v�[���A���P�[�^�N���X
//���X���b�h�Z�[�t�Ή�
class CPoolAllocator
{
public:
	//�^�錾
	typedef unsigned char byte;//�o�b�t�@�p
	typedef int index_t;//�C���f�b�N�X�p
public:
	//�萔
	const std::size_t m_blockSize;//�u���b�N�T�C�Y
	const index_t m_poolBlocksNum;//�v�[���u���b�N��
	static const index_t INVALID_INDEX = INT_MAX;//�u���b�N�C���f�b�N�X�̖����l
public:
	//�A�N�Z�b�T
	std::size_t getUsed() const { return m_used; }//�g�p�����擾
	void* getBlock(const index_t index){ return m_pool + index * m_blockSize; }//�u���b�N�擾
private:
	//���\�b�h
	//�������m�ۏ�ԃ��Z�b�g
	void reset()
	{
		//���b�N�擾
		//m_lock.lock();

		m_used = 0;//�g�p����
		m_next = 0;//���g�p�擪�C���f�b�N�X
		m_recycle = INVALID_INDEX;//���T�C�N���C���f�b�N�X

		//���b�N���
		//m_lock.unlock();
	}
	//�������u���b�N�m��
	//���g�p���t���O�̋󂫂��������ăt���O���X�V���A
	//�@�m�ۂ����C���f�b�N�X��Ԃ�
	int assign()
	{
		//���b�N�擾
		//m_lock.lock();

		//�C���f�b�N�X�m��
		index_t index = -1;
		if (m_next < m_poolBlocksNum)
		{
			//���g�p�C���f�b�N�X������ꍇ
			index = m_next++;//���g�p�擪�C���f�b�N�X�J�E���g�A�b�v
			++m_used;//�g�p�����J�E���g�A�b�v
		}
		else
		{
			if (m_recycle != INVALID_INDEX)
			{
				//���T�C�N���\�ȃC���f�b�N�X������ꍇ
				index = m_recycle;//���T�C�N���C���f�b�N�X
				m_recycle = *reinterpret_cast<unsigned int*>(getBlock(index));//���T�C�N���C���f�b�N�X�X�V�i�󂫃m�[�h�̐擪�ɏ������܂�Ă���j
				++m_used;//�g�p�����J�E���g�A�b�v
			}
		}

		//���b�N���
		//m_lock.unlock();

		//�I��
		return index;
	}
	//�������u���b�N���
	//���w��̃C���f�b�N�X�̎g�p���t���O�����Z�b�g
	void release(const index_t index)
	{
		//�C���f�b�N�X�͈̔̓`�F�b�N
		if (index < 0 || index >= m_poolBlocksNum)
			return;

		//���b�N�擾
		//m_lock.lock();

		//���T�C�N��
		*reinterpret_cast<unsigned int*>(getBlock(index)) = m_recycle;//���T�C�N���C���f�b�N�X�������݁i�󂫃m�[�h�̐擪�ɋ����ɏ������ށj
		m_recycle = index;//���T�C�N���C���f�b�N�X�g�݊���

		//�g�p�����J�E���g�_�E��
		--m_used;

		//���b�N���
		//m_lock.unlock();
	}
public:
	//�������m��
	void* alloc(const std::size_t size)
	{
		//�y�A�T�[�V�����z�v���T�C�Y���u���b�N�T�C�Y�𒴂���ꍇ�͑����m�ێ��s
		//ASSERT(size <= m_blockSize, "CPoolAllocator::alloc(%d) cannot allocate. Size must has been under %d.", size, m_blockSize);
		if (size > m_blockSize)
		{
			return nullptr;
		}
		//�󂫃u���b�N���m�ۂ��ĕԂ�
		const index_t index = assign();
		//�y�A�T�[�V�����z�S�u���b�N�g�p���ɂ��A�m�ێ��s
		//ASSERT(index >= 0, "CPoolAllocator::alloc(%d) cannot allocate. Buffer is full. (num of blocks is %d)", size, m_poolBlocksNum);
		//�m�ۂ�����������Ԃ�
		return index < 0 ? nullptr : getBlock(index);
	}
	//���������
	void free(void * p)
	{
		//nullptr���͑���������s
		//ASSERT(p != nullptr, "CPoolAllocator::free() cannot free. Pointer is null.");
		if (!p)
			return;
		//�|�C���^����C���f�b�N�X���Z�o
		const byte* top_p = reinterpret_cast<byte*>(m_pool);//�o�b�t�@�̐擪�|�C���^
		const byte* target_p = reinterpret_cast<byte*>(p);//�w��|�C���^
		const int diff = (target_p - top_p);//�|�C���^�̈����Z�ō��̃o�C�g���Z�o
		const int index = (target_p - top_p) / m_blockSize;//�u���b�N�T�C�Y�Ŋ����ăC���f�b�N�X�Z�o
		//�y�A�T�[�V�����z�������o�b�t�@�͈̔͊O�Ȃ珈�����s�irelease�֐����Ŏ��s����̂ł��̂܂܎��s�j
		//ASSERT(index >= 0 && index < m_poolBlocksNum, "CPoolAllocator::free() cannot free. Pointer is different.");
		//�y�A�T�[�V�����z�|�C���^���e�u���b�N�̐擪���w���Ă��邩�`�F�b�N
		//�@�@�@�@�@�@�@�@�ˑ��d�p���ƃL���X�g���Ă���Ƃ���邱�Ƃ���̂ł��̖��͖������ĉ�����Ă��܂�
		//ASSERT(diff % m_blockSize == 0, "CPoolAllocator::free() cannot free. Pointer is illegal.");
		//�Z�o�����C���f�b�N�X�Ń��������
		release(index);
	}
	//�R���X�g���N�^�Ăяo���@�\�t���������m��
	//��C++11�̉ϒ��e���v���[�g�p�����[�^�����p
	template<class T, typename... Tx>
	T* create(Tx... nx)
	{
		return new(*this) T(nx...);
	}
	//�f�X�g���N�^�Ăяo���@�\�t�����������
	//�������A�|�C���^�� nullptr ���Z�b�g����
	template<class T>
	void destroy(T*& p)
	{
		if (!p)
			return;
		p->~T();//�����I�ȃf�X�g���N�^�Ăяo���i�f�X�g���N�^����`�̃N���X�ł����Ȃ��j
		operator delete(p, *this);//�z�udelete�Ăяo��
		p = nullptr;//�|�C���^�ɂ�nullptr���Z�b�g
	}
public:
	//�R���X�g���N�^
	CPoolAllocator(void* pool_buff, const std::size_t block_size, const index_t pool_blocks_num) :
		m_pool(reinterpret_cast<byte*>(pool_buff)),//�v�[���o�b�t�@
		m_blockSize(block_size),//�u���b�N�T�C�Y�@��4�{���ł��邱��
		m_poolBlocksNum(pool_blocks_num)//�v�[���u���b�N��
	{
		//�y�A�T�[�V�����z�p�����[�^�`�F�b�N
		//ASSERT((m_blockSize & 0x3) == 0, "CPoolAllocator::CPoolAllocator() block size is invalid.");

		//�g�p���t���O���Z�b�g
		reset();
	}
	//�f�X�g���N�^
	~CPoolAllocator()
	{}
private:
	//�t�B�[���h
	byte* m_pool;//�v�[���o�b�t�@
	index_t m_used;//�g�p����
	index_t m_next;//���g�p�擪�C���f�b�N�X
	index_t m_recycle;//���T�C�N���C���f�b�N�X
	//CSpinLock m_lock;//���b�N
};

//--------------------
//�z�unew
void* operator new(const std::size_t size, CPoolAllocator& allocator)
{
	printf("placement new(size=%d, pool_allocator.used=%d,%d)\n", size, allocator.getUsed());
	return allocator.alloc(size);
}
//�z�udelete
void operator delete(void* p, CPoolAllocator& allocator)
{
	printf("placement delete(p=0x%p, pool_allocator.used=%d,%d)\n", p, allocator.getUsed());
	allocator.free(p);
}

//----------------------------------------
//�v�[���A���P�[�^�N���X�i�o�b�t�@����Łj
template<int N, std::size_t S>
class CPoolAllocatorWithBuff : public CPoolAllocator
{
public:
	//�萔
	static const std::size_t BLOCK_SIZE = (S + 3) & ~3;//�u���b�N�T�C�Y
	static const index_t POOL_BLOCKS_NUM = N;//�v�[���u���b�N��
public:
	//�R���X�g���N�^
	CPoolAllocatorWithBuff() :
		CPoolAllocator(&m_poolBuff, BLOCK_SIZE, POOL_BLOCKS_NUM)
	{}
	//�f�X�g���N�^
	~CPoolAllocatorWithBuff()
	{}
private:
	//�t�B�[���h
	byte m_poolBuff[POOL_BLOCKS_NUM][BLOCK_SIZE];//�v�[���o�b�t�@
};

//�e�X�g
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
//�e�X�g���C��
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


//�e�X�g
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
