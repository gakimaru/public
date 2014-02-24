#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>//uintptr_t,intptr_t�p
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
//�@  void* operator new(size_t, void* where) throw();
//�@  void* operator new[](size_t, void* where) throw();
//�@  void operator delete(void*, void*) throw();
//�@  void operator delete[](void*, void*) throw();
//�@  void* operator new(size_t size, const nothrow_t&) throw();//��O���X���[���Ȃ�
//�@  void* operator new[](size_t size, const nothrow_t&) throw();//��O���X���[���Ȃ�
//�@  void operator delete(void*, const nothrow_t&) throw();//��O���X���[���Ȃ�
//�@  void operator delete[](void*, const nothrow_t&) throw();//��O���X���[���Ȃ�

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
	//operator delete(p, p);//�z�udelete�̌Ăяo���́A���ɕK�v�ł͂Ȃ�
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
void* operator new(const std::size_t size, char* where) throw()
{
	printf("placement new(size=%d, where=0x%p)\n", size, where);
	return where;//�n���ꂽ�o�b�t�@�����̂܂ܕԂ�
}
//�z��new
//���f�X�g���N�^���������^�̏ꍇ�A�o�b�t�@�̐擪�ɗv�f�����i�[���邽�߂ɁA�����傫�ȃT�C�Y���n�����
//�@���̎��A�߂�l�̃|�C���^�́A�֐��𔲂������A�v�f�����̕����V�t�g�����|�C���^�ɕϊ������
//�@�^�̃A���C�������g�ɂ���Ă͑傫���V�t�g����\��������
//�@�f�X�g���N�^�������Ȃ��^�������̓v���~�e�B�u�^�ł͂��̏��͈����Ȃ��i�Ȃ̂ł�₱�����j
void* operator new[](const std::size_t size, char* where) throw()
{
	printf("placement new[](size=%d, where=0x%p)\n", size, where);
	return where;//�n���ꂽ�o�b�t�@�����̂܂ܕԂ�
}
//�P��delete
//���z�unew�Ƒ΂ɂȂ�z�udelete�͕K�{
//�@�i�R���X�g���N�^�ŗ�O����������Ǝ����I�ɌĂяo����邽�߁j
void operator delete(void* p, char* where) throw()
{
	printf("placement delete(p=0x%p, where=0x%p)\n", p, where);
	//�Ȃɂ����Ȃ�
}
//�z��delete
//���f�X�g���N�^���������^�̃|�C���^�ł����Ă��A�󂯓n���ꂽ�|�C���^�����̂܂܈�����̂Œ���
//�@�i�������m�ێ��̐��m�ȃ|�C���^��������Ȃ��j
//���N���X��delete�֐����g�p���邱�Ƃł��̖��������ł���
void operator delete[](void* p, char* where) throw()
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
		CTest1("(default)")//���̃R���X�g���N�^�Ăяo���iC++11�Œǉ����ꂽ�\���j
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
		//delete_ptr(obj_p);//�q�Ƃ��č폜
		//delete_ptr(parent_p);//�e1�Ƃ��č폜
		delete_ptr(parent_ex_p);//�e2�Ƃ��č폜
	}
}

//--------------------------------------------------------------------------------
//�N���X��new

//--------------------
//�C���X�^���X�p�o�b�t�@
static char s_buffForTestClass2[64];

//--------------------
//�O���[�o��new/delete�e�X�g
//#define USE_GLOBAL_NEW_DELETE_TEST2//test2���O���[�o��new/delete�Ŏ��s����ꍇ�͂��̃}�N����L����
#ifdef USE_GLOBAL_NEW_DELETE_TEST2
//�P��new
void* operator new(const std::size_t size) throw()
{
	printf("new(size=%d)\n", size);
	return s_buffForTestClass2;//�C���X�^���X�p�o�b�t�@��Ԃ�
}
//�z��new
void* operator new[](const std::size_t size) throw()
{
	printf("new[](size=%d)\n", size);
	return s_buffForTestClass2;//�C���X�^���X�p�o�b�t�@��Ԃ�
}
//�P��delete
void operator delete(void* p) throw()
{
	printf("delete(p=0x%p)\n", p);
	//�Ȃɂ����Ȃ�
}
//�z��delete
void operator delete[](void* p) throw()
{
	printf("delete[](p=0x%p)\n", p);
	//�Ȃɂ����Ȃ�
}
#endif//USE_GLOBAL_NEW_DELETE_TEST2

//--------------------
//�e�X�g�p�N���X
//#define USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2//size�t����delete�֐����g�p����Ƃ��̓R�����g�A�E�g
//#define DELETE_DESTRUCTOR_FOR_CTEST2//�f�X�g���N�^���g�p����Ƃ��̓R�����g�A�E�g
class CTest2
{
public:
	//�I�y���[�^
#ifndef USE_GLOBAL_NEW_DELETE_TEST2
	//�N���X��new/delete
	//new
	//�����N���X�̃C���X�^���X��p��new/delete
	//�����ʂ�new/delete���Z�q�ŃC���X�^���X�𐶐��^�j������ƌĂяo�����
	//���z�unew/�z�udelete���g�p�i�z�udelete�̍ۂ� CTest2::operator delete(p, xxx) �̂悤�ɃN���X���𖾎�����K�v����j
	//���ÓIoperator�ł���K�v�����邪�Astatic��t���Ȃ��Ă��ÖٓI��static�����ɂȂ�
	//�P��new
	static void* operator new(const std::size_t size) throw()
	{
		printf("CTest2::new(size=%d)\n", size);
		return s_buffForTestClass2;//�C���X�^���X�p�o�b�t�@��Ԃ�
	}
	//�z��new
	static void* operator new[](const std::size_t size) throw()
	{
		printf("CTest2::new[](size=%d)\n", size);
		return s_buffForTestClass2;//�C���X�^���X�p�o�b�t�@��Ԃ�
	}
#ifdef USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
	//delete
	//���N���X��delete�ɂ�2��ނ̃X�^�C��������
	//������͕W���I�ȃX�^�C��
	//�P��delete
	static void operator delete(void* p) throw()
	{
		printf("CTest2::delete(p=0x%p)\n", p);
		//�Ȃɂ����Ȃ�
	}
	//�z��delete
	static void operator delete[](void* p) throw()
	{
		printf("CTest2::delete[](p=0x%p)\n", p);
		//�Ȃɂ����Ȃ�
	}
#else//USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
	//delete
	//���N���X��delete�ł́A��2������ size_t �����`���W���X�^�C���̈�i��z�udelete�j
	//��2��ނƂ���`������Aoperator delete(void*) �̕����D��
	//�P��delete
	static void operator delete(void* p, const std::size_t size) throw()
	{
		printf("CTest2::delete(p=0x%p, size=%d)\n", p, size);
		//�Ȃɂ����Ȃ�
	}
	//�z��delete
	static void operator delete[](void* p, const std::size_t size) throw()
	{
		printf("CTest2::delete[](p=0x%p, size=%d)\n", p, size);
		//�Ȃɂ����Ȃ�
	}
#endif//USE_NORMAL_OPERATOR_DELETE_FOR_CTEST2
#endif//USE_GLOBAL_NEW_DELETE_TEST2
public:
	//�f�t�H���g�R���X�g���N�^
	CTest2() :
		CTest2("(default)")//���̃R���X�g���N�^�Ăяo���iC++11�Œǉ����ꂽ�d�l�j
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
	//�����d�p���̃e�X�g�̂��߂� virtual ��
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
#ifndef USE_GLOBAL_NEW_DELETE_TEST2
	//�N���X��new
	static void* operator new(const std::size_t size) throw()
	{
		printf("CTest2ex::new(size=%d)\n", size);
		return s_buffForTestClass2;//�C���X�^���X�p�o�b�t�@��Ԃ�
	}
	//�N���X��delete
	static void operator delete(void* p) throw()
	{
		printf("CTest2ex::delete(p=0x%p)\n", p);
		//�Ȃɂ����Ȃ�
	}
#endif//USE_GLOBAL_NEW_DELETE_TEST2
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
#ifndef USE_GLOBAL_NEW_DELETE_TEST2
	//�N���X��new
	static void* operator new(const std::size_t size) throw()
	{
		printf("CDerivedTest2::new(size=%d)\n", size);
		return s_buffForTestClass2;//�C���X�^���X�p�o�b�t�@��Ԃ�
	}
	//�N���X��delete
	static void operator delete(void* p) throw()
	{
		printf("CDerivedTest2::delete(p=0x%p)\n", p);
		//�Ȃɂ����Ȃ�
	}
#endif//USE_GLOBAL_NEW_DELETE_TEST2
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
//�l�[���X�y�[�X
//#define USE_NAMESPACE_FOR_TEST2//�l�[���X�y�[�X�ɒ�`����new/delete�̃e�X�g���s���ꍇ�́A���̍s��L���ɂ���
#ifdef USE_NAMESPACE_FOR_TEST2
namespace test2_ns
{
	//�l�[���X�y�[�X���o�b�t�@
	char s_buff[32];

	//�l�[���X�y�[�X�ɒ�`���� new
	void* operator new(const std::size_t size) throw()
	{
		printf("test2_ns::new size=%d\n", size);
		return s_buff;
	}
	//�l�[���X�y�[�X�ɒ�`���� delete
	void operator delete(void* p) throw()
	{
		printf("test2_ns::delete p=0x%p\n", p);
	}
}
#endif//USE_NAMESPACE_FOR_TEST2

//--------------------
//�e�X�g
void test2()
{
	printf("---------- test2:�N���X��new/delete ----------\n");
	{
		printf("----------�N���X\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CTest2* obj_p = new CTest2("�e�X�g2");//���ʂ�new���Z�q�Ƃ��Ďg����
		printf("obj_p=0x%p\n", obj_p);
		delete obj_p;//���ʂ�delete���Z�q�Ƃ��Ďg����
	}
	{
		printf("----------�N���X�̔z��\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CTest2* obj_p = new CTest2[3];//���ʂ�new[]���Z�q�Ƃ��Ďg����
		printf("obj_p=0x%p\n", obj_p);
		printf("*reinterpret_cast<int*>(s_buffForTestClass2)=%d\n", *reinterpret_cast<int*>(s_buffForTestClass2));//�f�X�g���N�^���������^�̔z��́A�o�b�t�@�̐擪�ɗv�f�����i�[����Ă���
		delete[] obj_p;//���ʂ�delete[]���Z�q�Ƃ��Ďg����
	}
	{
		printf("----------���d�p���N���X\n");
		printf("s_buffForTestClass2=0x%p\n", s_buffForTestClass2);
		CDerivedTest2* obj_p = new CDerivedTest2("�e�X�g2���d�p��");
		CTest2* parent_p = obj_p;//�e1�ɃL���X�g
		CTest2ex* parent_ex_p = obj_p;//�e2�ɃL���X�g
		printf("obj_p=0x%p, parent_p=0x%p, parent_ex_p=0x%p\n", obj_p, parent_p, parent_ex_p);
		//delete obj_p;//�q�Ƃ��č폜
		//delete parent_p;//�e1�Ƃ��č폜
		delete parent_ex_p;//�e2�Ƃ��č폜
	}
#ifdef USE_NAMESPACE_FOR_TEST2
	{
		printf("----------�l�[���X�y�[�X��new/delete\n");
		CTest2* obj_p = (CTest2*)test2_ns::operator new(sizeof(CTest2));//�l�[���X�y�[�X�ɒ�`����new
		::new(obj_p)CTest2("�e�X�g2");//�z�unew�Ŗ����I�ȃR���X�g���N�^�Ăяo��
		obj_p->~CTest2();//�����I�ȃf�X�g���N�^�Ăяo��
		test2_ns::operator delete(obj_p);//�l�[���X�y�[�X�ɒ�`����delete
	}
#endif//USE_NAMESPACE_FOR_TEST2
}

//--------------------------------------------------------------------------------
//�Œ�o�b�t�@�V���O���g���̃e�X�g

//--------------------
//��p�V���O���g���F�P���^�C�v
class CTest3Singleton1
{
public:
	//�ÓI�A�N�Z�b�T
	static CTest3Singleton1* getSigleton(){ return &m_singleton; }//�V���O���g�����擾
public:
	//�A�N�Z�b�T
	int getData() const { return m_data; }//�f�[�^���擾
	void setData(const int data){ m_data = data; }//�f�[�^���X�V
public:
	//�R���X�g���N�^
	CTest3Singleton1() :
		m_data(0)
	{
		printf("CTest3Singleton1::Constructor : m_data=%d\n", m_data);
	}
	//�f�X�g���N�^
	~CTest3Singleton1()
	{
		printf("CTest3Singleton1::Destructor : m_data=%d\n", m_data);
	}
private:
	//�t�B�[���h
	int m_data;//�f�[�^
	static CTest3Singleton1 m_singleton;//�V���O���g���C���X�^���X
};
//--------------------
//�V���O���g���ÓI�ϐ��̃C���X�^���X��
CTest3Singleton1 CTest3Singleton1::m_singleton;

//--------------------
//�e�X�g
//�V���O���g���̃f�[�^�\��
void printData_typeA1()
{
	CTest3Singleton1* singleton_p = CTest3Singleton1::getSigleton();
	printf("singleton_p->getData()=%d\n", singleton_p->getData());
}
//�V���O���g���̃f�[�^�X�V
void updateData_typeA1()
{
	CTest3Singleton1* singleton_p = CTest3Singleton1::getSigleton();
	singleton_p->setData(123);
}

//--------------------
//��p�V���O���g���F�C���X�^���X����^�C�v
class CTest3Singleton2
{
public:
	//�ÓI�A�N�Z�b�T
	static CTest3Singleton2* getSigleton()//�V���O���g�����擾
	{
		create();//�C���X�^���X���Ȃ���ΐ���
		return m_singleton;
	}
public:
	//�A�N�Z�b�T
	int getData() const { return m_data; }//�f�[�^���擾
	void setData(const int data){ m_data = data; }//�f�[�^���X�V
private:
	//�I�y���[�^�iprivate�j
	void* operator new(const std::size_t) throw() { return m_singletonBuff; }//new���Z�q
	void operator delete(void*) throw() {}//delete���Z�q
private:
	//�ÓI���\�b�h�iprivate�j
	//�V���O���g���C���X�^���X�̐���
	static void create()
	{
		if (m_singleton)
			return;
		m_singleton = new CTest3Singleton2();
	}
public:
	//�ÓI���\�b�h
	//�V���O���g���C���X�^���X�̖����I�Ȕj��
	static void destroy()
	{
		if (!m_singleton)
			return;
		delete m_singleton;
		m_singleton = nullptr;
	}
public:
	//�R���X�g���N�^
	CTest3Singleton2() :
		m_data(0)
	{
		printf("CTest3Singleton2::Constructor : m_data=%d\n", m_data);
	}
	//�f�X�g���N�^
	~CTest3Singleton2()
	{
		printf("CTest3Singleton2::Destructor : m_data=%d\n", m_data);
	}
private:
	//�t�B�[���h
	int m_data;//�f�[�^
	static CTest3Singleton2* m_singleton;//�V���O���g���C���X�^���X�Q��
	static unsigned char m_singletonBuff[];//�V���O���g���C���X�^���X�p�o�b�t�@
};
//--------------------
//�V���O���g���ÓI�ϐ��̃C���X�^���X��
CTest3Singleton2* CTest3Singleton2::m_singleton = nullptr;
unsigned char CTest3Singleton2::m_singletonBuff[sizeof(CTest3Singleton2)];//�V���O���g���C���X�^���X�p�o�b�t�@

//--------------------
//�e�X�g
//�V���O���g���̃f�[�^�\��
void printData_typeA2()
{
	CTest3Singleton2* singleton_p = CTest3Singleton2::getSigleton();
	printf("singleton_p->getData()=%d\n", singleton_p->getData());
}
//�V���O���g���̃f�[�^�X�V
void updateData_typeA2()
{
	CTest3Singleton2* singleton_p = CTest3Singleton2::getSigleton();
	singleton_p->setData(123);
}
//�V���O���g���̃C���X�^���X�𖾎��I�ɔj��
void deleteIntentionally_typeA2()
{
	CTest3Singleton2::destroy();
}

//--------------------
//�ėp�Œ�o�b�t�@�V���O���g���e���v���[�g�N���X
template<class T>
class CSingleton
{
	//�z�unew�e���v���[�g���t�����h��
	template<class U>
	friend void* operator new(const std::size_t size, CSingleton<U>& singleton) throw();
public:
	//�I�y���[�^�i�V���O���g���{�̂̃v���L�V�[�j
	T* operator->(){ return m_singleton; }
public:
	//���\�b�h
	//�V���O���g���C���X�^���X�̖����I�Ȕj��
	void destroy();
public:
	//�R���X�g���N�^
	CSingleton();
private:
	//�t�B�[���h
	static T* m_singleton;//�V���O���g���{�̎Q��
	static unsigned char m_singletonBuff[];//�V���O���g���{�̗p�o�b�t�@
};

//--------------------
//�e���v���[�g�z�unew
template<class T>
void* operator new(const std::size_t size, CSingleton<T>& singleton) throw()
{
	return singleton.m_singletonBuff;//�ėp�V���O���g���e���v���[�g�N���X���̃o�b�t�@��Ԃ�
}
//�e���v���[�g�z�udelete
template<class T>
void operator delete(void* p, CSingleton<T>& singleton) throw()
{
	//�Ȃɂ����Ȃ�
}

//--------------------
//�ėp�Œ�o�b�t�@�V���O���g���e���v���[�g�N���X�F������
//�����I�ȍ폜
template<class T>
void CSingleton<T>::destroy()
{
	if (!m_singleton)
		return;
	m_singleton->~T();//�f�X�g���N�^�Ăяo��
	operator delete(m_singleton, *this);//�z�udelete�Ăяo���i�Ȃ��Ă��悢�j
	m_singleton = nullptr;
}
//�R���X�g���N�^
template<class T>
CSingleton<T>::CSingleton()
{
	//�܂����������Ă��Ȃ���Ώ�����
	if (!m_singleton)
		m_singleton = new(*this)T();
}
//--------------------
//�V���O���g���ÓI�ϐ��̃C���X�^���X��
template<class T>
T* CSingleton<T>::m_singleton = nullptr;//�V���O���g���Q��
template<class T>
unsigned char CSingleton<T>::m_singletonBuff[sizeof(T)];//�V���O���g���p�o�b�t�@

//--------------------
//�e�X�g�p�N���X
class CTest3
{
public:
	//�A�N�Z�b�T
	int getData() const { return m_data; }//�f�[�^�擾
	void setData(const int data){ m_data = data; }//�f�[�^�X�V
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
//�V���O���g���̃f�[�^�\��
void printData_typeB()
{
	CSingleton<CTest3> singleton;
	printf("singleton->getData()=%d\n", singleton->getData());
}
//�V���O���g���̃f�[�^�X�V
void updateData_typeB()
{
	CSingleton<CTest3> singleton;
	singleton->setData(123);
}
//�V���O���g���̃C���X�^���X�𖾎��I�ɔj��
void deleteIntentionally_typeB()
{
	CSingleton<CTest3> singleton;
	singleton.destroy();
}

//--------------------
//�e�X�g
void test3()
{
	printf("---------- test3:�V���O���g�� ----------\n");
	{
		printf("----------��p�V���O���g���F�P���^�C�v\n");
		printData_typeA1();//�f�[�^�\��
		updateData_typeA1();//�f�[�^�X�V
		printData_typeA1();//�f�[�^�\��
	}
	{
		printf("----------��p�V���O���g���F�C���X�^���X����^�C�v\n");
		printData_typeA2();//�f�[�^�\��
		updateData_typeA2();//�f�[�^�X�V
		printData_typeA2();//�f�[�^�\��
		deleteIntentionally_typeA2();//�����I�ȃC���X�^���X�j��
		printData_typeA2();//�f�[�^�\��
	}
	{
		printf("----------�ėp�V���O���g��\n");
		printData_typeB();//�f�[�^�\��
		updateData_typeB();//�f�[�^�X�V
		printData_typeB();//�f�[�^�\��
		deleteIntentionally_typeB();//�����I�ȃC���X�^���X�j��
		printData_typeB();//�f�[�^�\��
	}
}

//--------------------------------------------------------------------------------
//�X�^�b�N�A���P�[�^

//--------------------
//�X�^�b�N�A���P�[�^�N���X
//����X���b�h�Z�[�t�i�������x�D��j
class CStackAllocator
{
public:
	//�^
	typedef unsigned char byte;//�o�b�t�@�p
	typedef std::size_t marker_t;//�X�^�b�N�}�[�J�[�^
public:
	//�A�N�Z�b�T
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾
	const byte* getNowPtr() const { return m_buffPtr + m_used; }//���݂̃o�b�t�@�ʒu
	marker_t getMarker() const { return m_used; }//���݂̃}�[�J�[���擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = sizeof(int))
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_used;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//�A���C�������g�v�Z
		const std::size_t next_used = m_used + align_diff + size;//���̃}�[�J�[�Z�o
		if (next_used > m_buffSize)//�������I�[�o�[�`�F�b�N�i�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK�j
		{
			printf("stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_buffSize - m_used);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//�������m�ۃA�h���X�Z�o
		m_used = next_used;//�}�[�J�[�X�V
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void back(const marker_t marker)
	{
		if (marker >= m_used)//�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK
			return;
		m_used = marker;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void back(const void* p)
	{
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
		back(marker);
	}
	//�������j��
	void clear()
	{
		m_used = 0;//�}�[�J�[�����Z�b�g
	}
public:
	//�R���X�g���N�^
	CStackAllocator(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�擪�A�h���X
		m_buffSize(buff_size),//�o�b�t�@�T�C�Y
		m_used(0)//�}�[�J�[
	{}
	//�f�X�g���N�^
	~CStackAllocator()
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�擪�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	marker_t m_used;//�}�[�J�[
};

//--------------------
//�z�unew/�z�udelete
//���������g�p�󋵂��m�F���邽�߂Ƀ}�[�J�[��\��
//�z�unew
void* operator new(const std::size_t size, CStackAllocator& allocator, const std::size_t align = sizeof(int)) throw()
{
	printf("placement new(size=%d, allocator.marker=%d, align=%d)\n", size, allocator.getMarker(), align);
	return allocator.alloc(size, align);
}
//�z���
void* operator new[](const std::size_t size, CStackAllocator& allocator, const std::size_t align = sizeof(int)) throw()
{
	printf("placement new[](size=%d, allocator.marker=%d, align=%d)\n", size, allocator.getMarker(), align);
	return allocator.alloc(size, align);
}
//�z�udelete
void operator delete(void* p, CStackAllocator& allocator, const std::size_t) throw()
{
	printf("placement delete(p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	//allocator.back(p) �͎��s���Ȃ�
}
//�z���
void operator delete[](void* p, CStackAllocator& allocator, const std::size_t) throw()
{
	printf("placement delete[](p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	//allocator.back(p) �͎��s���Ȃ�
}
//�f�X�g���N�^�Ăяo���t��delete
template<class T>
void delete_ptr(T*& p, CStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, allocator.marker=%d)\n", p, allocator.getMarker());
	p->~T();//�f�X�g���N�^�Ăяo��
	//operator delete(p, allocator, 0) �͎��s���Ȃ�
	//allocator.back(p) �͎��s���Ȃ�
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//�z���
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, array_num=%d, allocator.marker=%d)\n", p, array_num, allocator.getMarker());
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//�f�X�g���N�^�Ăяo��
	//operator delete(p, allocator, 0) �͎��s���Ȃ�
	//allocator.back(p) �͎��s���Ȃ�
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}

//--------------------
//�o�b�t�@�t���X�^�b�N�A���P�[�^�e���v���[�g�N���X
//���ÓI�o�b�t�@���g�p��������΁A�Œ�o�b�t�@�V���O���g��������
template<std::size_t SIZE>
class CStackAllocatorWithBuff : public CStackAllocator
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = SIZE;//�o�b�t�@�T�C�Y
public:
	//�R���X�g���N�^
	CStackAllocatorWithBuff() :
		CStackAllocator(m_buff, BUFF_SIZE)
	{}
	//�f�X�g���N�^
	~CStackAllocatorWithBuff()
	{}
private:
	//�t�B�[���h
	byte m_buff[BUFF_SIZE];//�o�b�t�@
};

//--------------------
//�e�X�g�p�N���X
//__declspec(align(8))//8�o�C�g�A���C�������g�Ńe�X�g����ꍇ�͂��̍s��L���ɂ���
class CTest4a
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTest4a() :
		CTest4a("(default)")//���̃R���X�g���N�^�Ăяo���iC++11�Œǉ����ꂽ�d�l�j
		//m_name("(default)")//C++11���g���Ȃ��ꍇ�͕��ʂɏ�����
	{
		printf("CTest4a::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CTest4a(const char* name) :
		m_name(name)
	{
		printf("CTest4a::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	~CTest4a()
	{
		printf("CTest4a::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	const char* m_name;//���O
	int m_dummy;//�_�~�[
};

//--------------------
//�e�X�g
void test4a()
{
	printf("---------- test4a:�X�^�b�N�A���P�[�^ ----------\n");
	CStackAllocatorWithBuff<64> stack;//�X�^�b�N�A���P�[�^�����i64�o�C�g�̃o�b�t�@���m�ہj
	printf("buff=0x%p\n", stack.getBuff());
	{
		printf("-----\n");
		int* i1 = new(stack) int[2];
		printf("i1=0x%p\n", i1);
		char* c1 = new(stack, 1) char[13];
		printf("c1=0x%p\n", c1);
		CStackAllocator::marker_t marker = stack.getMarker();//�}�[�J�[�擾
		printf("marker=%d\n", marker);
		float* f1 = new(stack) float[4];
		printf("f1=0x%p\n", f1);
		CTest4a* obj1_p = new(stack)CTest4a("�e�X�g4a");
		printf("obj1_p=0x%p\n", obj1_p);
		delete_ptr(f1, 4, stack);
		delete_ptr(c1, 15, stack);
		delete_ptr(i1, 2, stack);
		delete_ptr(obj1_p, stack);
		stack.back(marker);//�}�[�J�[��߂�
	}
	{
		printf("-----\n");
		CStackAllocator::marker_t marker = stack.getMarker();//�}�[�J�[�擾
		printf("marker=%d\n", marker);
		CTest4a* obj2_p = new(stack)CTest4a[3];
		printf("obj2_p=0x%p\n", obj2_p);
		int* i2 = new(stack) int;
		printf("i2=0x%p\n", i2);
		float* f2 = new(stack) float;
		printf("f2=0x%p\n", f2);
		char* c2 = new(stack, 1) char;
		printf("c2=0x%p\n", c2);
		int* over = new(stack) int[10];//�yNG�z�T�C�Y�I�[�o�[
		printf("over=0x%p\n", over);
		delete_ptr(f2, stack);
		delete_ptr(c2, stack);
		delete_ptr(i2, stack);
		delete_ptr(obj2_p, 3, stack);
	}
}

//--------------------------------------------------------------------------------
//�o�����X�^�b�N�A���P�[�^

//--------------------
//�o�����X�^�b�N�A���P�[�^�N���X
//����X���b�h�Z�[�t�i�������x�D��j
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
	typedef unsigned char byte;//�o�b�t�@�p
	typedef std::size_t marker_t;//�}�[�J�[�^
public:
	//�A�N�Z�b�T
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾
	const byte* getNowPtrN() const { return m_buffPtr + m_usedN; }//���݂̃o�b�t�@�ʒu�i�����j
	const byte* getNowPtrR() const { return m_buffPtr + m_usedR; }//���݂̃o�b�t�@�ʒu�i�t���j
	marker_t getMarkerN() const { return m_usedN; }//���݂̃}�[�J�[�i�����j���擾
	marker_t getMarkerR() const { return m_usedR; }//���݂̃}�[�J�[�i�t���j���擾
public:
	//���\�b�h
	//�������m�ہi�����j
	void* allocN(const std::size_t size, const std::size_t align = sizeof(int))
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_usedN;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//�A���C�������g�v�Z
		const std::size_t next_used = m_usedN + align_diff + size;//���̃}�[�J�[�Z�o
		if (next_used > m_usedR)//�������I�[�o�[�`�F�b�N�i�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK�j
		{
			printf("normal-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR - m_usedN);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//�������m�ۃA�h���X�Z�o
		m_usedN = next_used;//�}�[�J�[�X�V
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m�ہi�t���j
	void* allocR(const std::size_t size, const std::size_t align = sizeof(int))
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr) + m_usedR;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t alloc_ptr_tmp = now_ptr - size;//�������m�ۃA�h���X�Z�o�i�b��j
		const uintptr_t align_diff = align > 0 ? alloc_ptr_tmp % align == 0 ? 0 : alloc_ptr_tmp % align : 0;//�A���C�������g�v�Z
		const std::size_t next_used = m_usedR - size - align_diff;//���̃}�[�J�[�Z�o
		if (next_used < m_usedN || next_used > m_buffSize)//�������I�[�o�[�`�F�b�N�i�I�[�o�[�t���[���Ēl���傫���Ȃ�\�����`�F�b�N�j
		{
			printf("reversed-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR - m_usedN);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr - size - align_diff;//�������m�ۃA�h���X�Z�o
		m_usedR = next_used;//�}�[�J�[�X�V
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���}�[�J�[�w���
	void backN(const marker_t marker_n)
	{
		if (marker_n > m_usedR)//�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK
			return;
		m_usedN = marker_n;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���|�C���^�w���
	void backN(const void* p)
	{
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	void backR(const marker_t marker_r)
	{
		if (marker_r < m_usedN || marker_r > m_buffSize)//�������I�[�o�[�`�F�b�N
			return;
		m_usedR = marker_r;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	//���|�C���^�w���
	void backR(const void* p)
	{
		const std::size_t marker = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_buffPtr);
		backR(marker);
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
	CDualStackAllocator(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�擪�A�h���X
		m_buffSize(buff_size),//�o�b�t�@�T�C�Y
		m_usedN(0),//�}�[�J�[�i�����j
		m_usedR(buff_size)//�}�[�J�[�i�t���j
	{}
	//�f�X�g���N�^
	~CDualStackAllocator()
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�擪�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	marker_t m_usedN;//�}�[�J�[�i�����j
	marker_t m_usedR;//�}�[�J�[�i�t���j
};
static const CDualStackAllocator::E_ORDERED DSA_NORMAL = CDualStackAllocator::NORMAL;//����
static const CDualStackAllocator::E_ORDERED DSA_REVERSE = CDualStackAllocator::REVERSE;//�t��

//--------------------
//�z�unew/�z�udelete
//���������g�p�󋵂��m�F���邽�߂Ƀ}�[�J�[��\��
//�z�unew
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::NORMAL, const std::size_t align = sizeof(int)) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, ordered=%d, align=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), ordered, align);
	return ordered == CDualStackAllocator::NORMAL ? allocator.allocN(size, align) : allocator.allocR(size, align);
}
//�z���
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED ordered = CDualStackAllocator::NORMAL, const std::size_t align = sizeof(int)) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, ordered=%d, align=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), ordered, align);
	return ordered == CDualStackAllocator::NORMAL ? allocator.allocN(size, align) : allocator.allocR(size, align);
}
//�z�udelete
void operator delete(void* p, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED, const std::size_t) throw()
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.backN(p) / allocator.backR(p) �͎��s���Ȃ�
}
//�z���
void operator delete[](void* p, CDualStackAllocator& allocator, const CDualStackAllocator::E_ORDERED, const std::size_t) throw()
{
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.backN(p) / allocator.backR(p) �͎��s���Ȃ�
}
//�f�X�g���N�^�Ăяo���t��delete
template<class T>
void delete_ptr(T*& p, CDualStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	p->~T();//�f�X�g���N�^�Ăяo��
	//operator delete(p, allocator, DSA_NORMAL, 0) �͎��s���Ȃ�
	//allocator.backN(p) / allocator.backR(p) �͎��s���Ȃ�
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//�z���
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CDualStackAllocator& allocator)
{
	if (!p)
		return;
	printf("delete_ptr(p=0x%p, array_num=%d, allocator.marker=%d,%d)\n", p, array_num, allocator.getMarkerN(), allocator.getMarkerR());
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//�f�X�g���N�^�Ăяo��
	//operator delete(p, allocator, DSA_NORMAL, 0) �͎��s���Ȃ�
	//allocator.backN(p) / allocator.backR(p) �͎��s���Ȃ�
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}

//--------------------
//�o�b�t�@�t���o�����X�^�b�N�A���P�[�^�e���v���[�g�N���X
//���ÓI�o�b�t�@���g�p��������΁A�Œ�o�b�t�@�V���O���g��������
template<std::size_t SIZE>
class CDualStackAllocatorWithBuff : public CDualStackAllocator
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = SIZE;//�o�b�t�@�T�C�Y
public:
	//�R���X�g���N�^
	CDualStackAllocatorWithBuff() :
		CDualStackAllocator(m_buff, BUFF_SIZE)
	{}
	//�f�X�g���N�^
	~CDualStackAllocatorWithBuff()
	{}
private:
	//�t�B�[���h
	byte m_buff[BUFF_SIZE];//�o�b�t�@
};

//--------------------
//�e�X�g�p�N���X
//__declspec(align(8))//8�o�C�g�A���C�������g�Ńe�X�g����ꍇ�͂��̍s��L���ɂ���
class CTest4b
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTest4b() :
		CTest4b("(default)")//���̃R���X�g���N�^�Ăяo���iC++11�Œǉ����ꂽ�d�l�j
		//m_name("(default)")//C++11���g���Ȃ��ꍇ�͕��ʂɏ�����
	{
		printf("CTest4b::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CTest4b(const char* name) :
		m_name(name)
	{
		printf("CTest4b::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	~CTest4b()
	{
		printf("CTest4b::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	const char* m_name;//���O
	int m_dummy;//�_�~�[
};

//--------------------
//�e�X�g
void test4b()
{
	printf("---------- test4b:�o�����X�^�b�N�A���P�[�^ ----------\n");
	CDualStackAllocatorWithBuff<64> stack;//�o�����X�^�b�N�A���P�[�^�����i64�o�C�g�̃o�b�t�@���m�ہj
	printf("buff=0x%p\n", stack.getBuff());
	{
		printf("-----\n");
		int* i1 = new(stack, DSA_NORMAL) int[2];
		printf("i1=0x%p\n", i1);
		char* c1 = new(stack, DSA_REVERSE, 1) char[13];
		printf("c1=0x%p\n", c1);
		CStackAllocator::marker_t marker_n = stack.getMarkerN();//�}�[�J�[�擾
		CStackAllocator::marker_t marker_r = stack.getMarkerR();//�}�[�J�[�擾
		printf("marker=%d,%d\n", marker_n, marker_r);
		float* f1 = new(stack, DSA_NORMAL) float[4];
		printf("f1=0x%p\n", f1);
		CTest4b* obj1_p = new(stack, DSA_REVERSE)CTest4b("�e�X�g4b");
		printf("obj1_p=0x%p\n", obj1_p);
		delete_ptr(f1, 4, stack);
		delete_ptr(c1, 15, stack);
		delete_ptr(i1, 2, stack);
		delete_ptr(obj1_p, stack);
		stack.backN(marker_n);//�}�[�J�[��߂�
		stack.backR(marker_r);//�}�[�J�[��߂�
	}
	{
		printf("-----\n");
		CStackAllocator::marker_t marker_n = stack.getMarkerN();//�}�[�J�[�擾
		CStackAllocator::marker_t marker_r = stack.getMarkerR();//�}�[�J�[�擾
		printf("marker=%d,%d\n", marker_n, marker_r);
		CTest4b* obj2_p = new(stack, DSA_NORMAL)CTest4b[3];
		printf("obj2_p=0x%p\n", obj2_p);
		int* i2 = new(stack, DSA_REVERSE) int;
		printf("i2=0x%p\n", i2);
		float* f2 = new(stack, DSA_NORMAL) float;
		printf("f2=0x%p\n", f2);
		char* c2 = new(stack, DSA_REVERSE, 1) char;
		printf("c2=0x%p\n", c2);
		int* over1 = new(stack, DSA_NORMAL) int[10];//�yNG�z�T�C�Y�I�[�o�[
		printf("over1=0x%p\n", over1);
		int* over2 = new(stack, DSA_REVERSE) int[10];//�yNG�z�T�C�Y�I�[�o�[
		printf("over2=0x%p\n", over2);
		delete_ptr(f2, stack);
		delete_ptr(c2, stack);
		delete_ptr(i2, stack);
		delete_ptr(obj2_p, 3, stack);
	}
}

//--------------------------------------------------------------------------------
//�v�[���A���P�[�^

//--------------------
//�N���X�錾
class CPoolAllocator;

//--------------------
//�z�unew
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw();
//�z�udelete
void operator delete(void* p, CPoolAllocator& allocator) throw();

//----------------------------------------
//�v�[���A���P�[�^�N���X
//����X���b�h�Z�[�t
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
	const byte* getBuff() const { return m_pool; }//�o�b�t�@�擾
	index_t getUsed() const { return m_used; }//�g�p�����擾
	index_t getRemain() const { return m_poolBlocksNum - m_used; }//�c���擾
	const byte* getBlockConst(const index_t index) const { return m_pool + index * m_blockSize; }//�u���b�N�擾
private:
	byte* getBlock(const index_t index){ return m_pool + index * m_blockSize; }//�u���b�N�擾
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
		const intptr_t diff = (target_p - top_p);//�|�C���^�̈����Z�ō��̃o�C�g���Z�o
		const intptr_t index = diff / m_blockSize;//�u���b�N�T�C�Y�Ŋ����ăC���f�b�N�X�Z�o
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
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw()
{
	printf("placement new(size=%d, pool_allocator.used=%d/%d)\n", size, allocator.getUsed(), allocator.getRemain());
	return allocator.alloc(size);
}
//�z�udelete
void operator delete(void* p, CPoolAllocator& allocator) throw()
{
	printf("placement delete(p=0x%p, pool_allocator.used=%d/%d)\n", p, allocator.getUsed(), allocator.getRemain());
	allocator.free(p);
}

//----------------------------------------
//�o�b�t�@�t���v�[���A���P�[�^�N���X�F�u���b�N�T�C�Y�ƃu���b�N���w��
template<std::size_t S, int N>
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

//----------------------------------------
//�o�b�t�@�t���v�[���A���P�[�^�N���X�F�f�[�^�^�ƃu���b�N���w��
template<typename T, int N>
class CPoolAllocatorWithType : public CPoolAllocatorWithBuff<sizeof(T), N>
{
public:
	//�^
	typedef T data_t;//�f�[�^�^
public:
	//�萔
	static const std::size_t TYPE_SIZE = sizeof(data_t);//�^�̃T�C�Y
public:
	//�R���X�g���N�^�Ăяo���@�\�t���������m��
	//��C++11�̉ϒ��e���v���[�g�p�����[�^�����p
	template<typename... Tx>
	data_t* createData(Tx... nx)
	{
		return CPoolAllocator::create<data_t>(nx...);
	}
	//�f�X�g���N�^�Ăяo���@�\�t�����������
	//�������A�|�C���^�� nullptr ���Z�b�g����
	void destroyData(data_t*& p)
	{
		CPoolAllocator::destroy(p);
	}
public:
	//�R���X�g���N�^
	CPoolAllocatorWithType() :
		CPoolAllocatorWithBuff<TYPE_SIZE, N>()
	{}
	//�f�X�g���N�^
	~CPoolAllocatorWithType()
	{}
};

//--------------------
//�e�X�g�p�N���X
//__declspec(align(8))//8�o�C�g�A���C�������g�Ńe�X�g����ꍇ�͂��̍s��L���ɂ���
class CTest5
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTest5() :
		CTest5("(default)")//���̃R���X�g���N�^�Ăяo���iC++11�Œǉ����ꂽ�d�l�j
		//m_name("(default)")//C++11���g���Ȃ��ꍇ�͕��ʂɏ�����
	{
		printf("CTest5::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CTest5(const char* name) :
		m_name(name)
	{
		printf("CTest5::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	~CTest5()
	{
		printf("CTest5::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	const char* m_name;//���O
	int m_dummy;//�_�~�[
};
//�傫���N���X
class CTest5L
{
	char m_dummy[9];
};

//--------------------
//�e�X�g
void test5()
{
	printf("---------- test5:�v�[���A���P�[�^ ----------\n");
	CPoolAllocatorWithType<CTest5, 5> pool;//�v�[���A���P�[�^�����isizeof(CTest5) * 5�̃o�b�t�@���m�ہj
	printf("buff=0x%p\n", pool.getBuff());
	{
		printf("-----\n");
		//createData() ���\�b�h�ŃC���X�^���X�𐶐�
		//���C�ӂ̃R���X�g���N�^�������󂯓n����
		CTest5* obj1_p = pool.createData("�e�X�g5-1");//createData()�́A�v�[���A���P�[�^�ɒ�`�����f�[�^�^�ŃC���X�^���X�𐶐�����
		printf("obj1_p=0x%p\n", obj1_p);
		CTest5* obj2_p = pool.createData("�e�X�g5-2");
		printf("obj2_p=0x%p\n", obj2_p);
		CTest5* obj3_p = pool.createData("�e�X�g5-3");
		printf("obj3_p=0x%p\n", obj3_p);
		CTest5* obj4_p = pool.createData("�e�X�g5-4");
		printf("obj4_p=0x%p\n", obj4_p);
		CTest5* obj5_p = pool.createData("�e�X�g5-5");
		printf("obj5_p=0x%p\n", obj5_p);
		CTest5* obj6_p = pool.createData("�e�X�g5-6");//�yNG�z���I�[�o�[
		printf("obj6_p=0x%p\n", obj6_p);
		//destroy() ���\�b�h�ŃC���X�^���X��j��
		//���f�X�g���N�^�Ăяo���ɑΉ�
		pool.destroyData(obj1_p);
		pool.destroyData(obj2_p);
		pool.destroyData(obj3_p);
		pool.destroyData(obj4_p);
		pool.destroyData(obj5_p);
		pool.destroyData(obj6_p);
	}
	{
		printf("-----\n");
		//sizeof(CTest5)�ȉ��̃T�C�Y�̌^�Ȃ牽�ł�������
		CTest5L* obj_l_p = pool.create<CTest5L>();//�yNG�z��`���̃N���X���T�C�Y���傫���N���X
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
		long long* ll_p = pool.create<long long>();//�yNG�z���I�[�o�[
		printf("ll_p=0x%p\n", ll_p);
		//destroy() ���\�b�h�̓f�X�g���N�^���Ȃ��^�ł����Ȃ�
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
//�e�X�g���C��
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
