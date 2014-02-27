//�e�X�g�����p�R���p�C���X�C�b�`
#define USE_NEW_PTR_FOR_TEST0//test0�ŁAnew_ptr�֐����g�p���鎞�͂��̃}�N����L���ɂ���
#define USE_DELETE_PTR_FOR_TEST0//test0�ŁAdelete_ptr�֐����g�p���鎞�͂��̃}�N����L���ɂ���
#define USE_DESTRUCTOR_FOR_TEST1//test1�ŁA�f�X�g���N�^���g�p����Ƃ��͂��̃}�N����L���ɂ���i�A���P�[�g�T�C�Y�������邱�Ƃ��m�F�ł���j
//#define USE_GLOBAL_NEW_DELETE_FOR_TEST2//test2�ŁA�N���X��new/delete���O���[�o��new/delete�ɕύX���鎞�͂��̃}�N����L���ɂ���
#define USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2//test2�ŁA�N���X��delete��size�����t���̂��̂ɂ��鎞�͂��̃}�N����L���ɂ���
#define USE_DESTRUCTOR_FOR_TEST2//test2�ŁA�f�X�g���N�^���g�p���鎞�͂��̃}�N����L���ɂ���i�A���P�[�g�T�C�Y�������邱�Ƃ��m�F�ł���j
//#define USE_NAMESPACE_NEW_DELETE_FOR_TEST2//test2�ŁA�l�[���X�y�[�X�ɒ�`����new/delete�̃e�X�g���s�����͂��̃}�N����L���ɂ���
#define USE_NEW_MACRO//test7�ŁANEW�}�N�����g�p���鎞�͂��̃}�N����L���ɂ���
#define USE_ALLOC_INFO//test7�ŁAnew���Ƀ������m�ۏ����g�p���鎞�͂��̃}�N����L���ɂ���

//CRC�Z�o�����p�R���p�C���X�C�b�`
//#define USE_CRC_CALC_TABLE//CRC�v�Z�̍ۂɁA���O�v�Z�ς݂�CRC�v�Z�e�[�u�����g�p����Ȃ炱�̃}�N����L���ɂ���

//GCC�֘A�FGCC�g�p���͂����̃}�N����L��������
//#define USE_MEMALIGN//�yGCC�p�ztest6�ȍ~�ŁAmemalign���g�p���鎞�͂��̃}�N����L���ɂ���
//#define IS_NOT_FRIEND_WITH_NEW_OPERATOR//�yGCC�p�ztest7�ȍ~�ŁA�I�y���[�^new/delete���t�����h�錾���Ȃ����͂��̃}�N����L���ɂ���
//#define TLS_IS_POSIX//�yGCC�p�zTLS�̐錾��POSIX�X�^�C���ɂ��鎞�͂��̃}�N����L���ɂ���

//MS�ŗL�d�l�֘A�FVisual C++�g�p���͂��̃}�N����L��������
#define USE_STRCPY_S//�yMS�ŗL�d�l�zstrcpy_s���g�p���鎞�ɂ��̃}�N����L���ɂ���
#define USE_FUNCSIG//�yMS�ŗL�d�l�z�֐�����__FUNCSIG__���g�p���鎞�ɂ��̃}�N����L���ɂ���

//C++11�֘A�F�ꕔ�̋�����ݒ�
//�����̃}�N���́AVisual C++����C++0x���ŃR���p�C�����邽�߂Ɏg�p����
#define ENABLE_NULLPTR//�yC++11�p�znullptr��L���ɂ��鎞�͂��̃}�N����L���ɂ���
#define ENABLE_OVERRIDE//�yC++11�p�zoverride��L���ɂ��鎞�͂��̃}�N����L���ɂ���
//#define ENABLE_CONSTEXPR//�yC++11�p�zconstexpr��L���ɂ��鎞�͂��̃}�N����L���ɂ���
//#define ENABLE_USER_DEFINED_LITERALS//�yC++11�p�z���[�U�[��`���e������L���ɂ��鎞�͂��̃}�N����L���ɂ���

#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//std::size_t�p
#include <stdint.h>//uintptr_t,intptr_t�p
#include <limits.h>//INT_MAX�p
#include <assert.h>//assert�p
#include <new>//�K��̔z�unew/�z�udelete�p
#include <typeinfo>//typeid�p

//�X���b�h���[�J���X�g���[�W�C���q
//��C++11�d�l�U��
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX�d�l
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows�d�l
#endif//TLS_IS_POSIX

//C++11�݊��p�}�N��
#ifndef ENABLE_NULLPTR
#define nullptr NULL
#endif//ENABLE_NULLPTR
#ifndef ENABLE_OVERRIDE
#define overide
#endif//ENABLE_OVERRIDE
#ifdef ENABLE_CONSTEXPR
#define CONSTEXPR constexpr
#else//ENABLE_CONSTEXPR
#define CONSTEXPR const
#endif//ENABLE_CONSTEXPR

//�֐����擾�}�N��
#ifdef USE_FUNCSIG
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif//USE_FUNCSIG

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
	printf("delete_ptr(p=0x%p)\n", p);
	if (!p)
		return;
	p->~T();//�f�X�g���N�^�Ăяo��
	operator delete(p, reinterpret_cast<char*>(p));//�z�udelete�Ăяo��
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//�����̊m�F�̂��߂ɔz��ł�delete�֐����p��
//�i�c�O�Ȃ���j�z��̗v�f�����󂯓n��
template<class T>
void delete_ptr(T*& p, const std::size_t array_num)
{
	printf("delete_ptr(p=0x%p, array_num=%d)\n", p, array_num);
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//�f�X�g���N�^�Ăяo��
	operator delete[](p, reinterpret_cast<char*>(p));//�z�udelete�Ăяo��
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}

//--------------------
//�e�X�g�p�N���X
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
#ifdef USE_DESTRUCTOR_FOR_TEST1
	//�f�X�g���N�^
	~CTest1()
	{
		printf("CTest1::Destructor : name=\"%s\"\n", m_name);
	}
#endif//USE_DESTRUCTOR_FOR_TEST1
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
#ifdef USE_GLOBAL_NEW_DELETE_FOR_TEST2
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
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2

//--------------------
//�e�X�g�p�N���X
class CTest2
{
public:
	//�I�y���[�^
#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
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
#ifndef USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2
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
#else//USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2
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
#endif//USE_EXTENDED_OPERATOR_DELETE_FOR_TEST2
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2
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
#ifdef USE_DESTRUCTOR_FOR_TEST2
	//�f�X�g���N�^
	//�����d�p���̃e�X�g�̂��߂� virtual ��
	virtual ~CTest2()
	{
		printf("CTest2::Destructor : name=\"%s\"\n", m_name);
	}
#endif//USE_DESTRUCTOR_FOR_TEST2
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
#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
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
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2
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
#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
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
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2
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
#ifdef USE_NAMESPACE_NEW_DELETE_FOR_TEST2
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
#endif//USE_NAMESPACE_NEW_DELETE_FOR_TEST2

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
#ifdef USE_NAMESPACE_NEW_DELETE_FOR_TEST2
	{
		printf("----------�l�[���X�y�[�X��new/delete\n");
		CTest2* obj_p = (CTest2*)test2_ns::operator new(sizeof(CTest2));//�l�[���X�y�[�X�ɒ�`����new
		::new(obj_p)CTest2("�e�X�g2");//�z�unew�Ŗ����I�ȃR���X�g���N�^�Ăяo��
		obj_p->~CTest2();//�����I�ȃf�X�g���N�^�Ăяo��
		test2_ns::operator delete(obj_p);//�l�[���X�y�[�X�ɒ�`����delete
	}
#endif//USE_NAMESPACE_NEW_DELETE_FOR_TEST2
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
	static void* operator new(const std::size_t) throw(){ return m_singletonBuff; }//new���Z�q
	static void operator delete(void*) throw() {}//delete���Z�q
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
//�X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�N���X
class IStackAllocator
{
public:
	//�萔
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//�f�t�H���g�̃A���C�������g
	//�X�^�b�N��
	enum E_ORDERED
	{
		DEFAULT = 0,//�f�t�H���g
		NORMAL = 1,//����
		REVERSE = -1,//�t��
	};
public:
	//�^
	typedef unsigned char byte;//�o�b�t�@�p
	typedef uintptr_t marker_t;//�X�^�b�N�}�[�J�[�^
public:
	//�A�N�Z�b�T
	virtual std::size_t getTotal() const = 0;//�S�̂̃������ʂ��擾
	virtual std::size_t getUsed() const = 0;//�g�p���̃������ʂ��擾
	virtual std::size_t getRemain() const = 0;//�c��̃������ʂ��擾
	virtual const byte* getNowPtr() const = 0;//���݂̃o�b�t�@�ʒu���擾
	virtual marker_t getMarker() const = 0;//���݂̃}�[�J�[���擾
public:
	//���\�b�h
	//�������m��
	virtual void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) = 0;
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	virtual void back(const marker_t marker) = 0;
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	virtual void back(const void* p) = 0;
	//�������j���i�����j
	virtual void clear() = 0;
	//�������j���i�S�āj
	virtual void clearAll() = 0;
public:
	//�f�X�g���N�^
	virtual ~IStackAllocator(){}
};
//�萔�̃G�C���A�X
static const IStackAllocator::E_ORDERED DSA_DEFAULT = IStackAllocator::DEFAULT;//�f�t�H���g
static const IStackAllocator::E_ORDERED DSA_NORMAL = IStackAllocator::NORMAL;//����
static const IStackAllocator::E_ORDERED DSA_REVERSE = IStackAllocator::REVERSE;//�t��

//--------------------
//�X�^�b�N�A���P�[�^�N���X
//����X���b�h�Z�[�t�i�������x�D��j
//���C���^�[�t�F�[�X���������邪�A�������̂��߂� virtual���\�b�h�ɗ��炸����\
class CStackAllocator : public IStackAllocator
{
public:
	//�A�N�Z�b�T
	std::size_t getTotal() const override { return m_buffSize; }//�S�̂̃������ʂ��擾
	std::size_t getUsed() const override { return m_used; }//�g�p���̃������ʂ��擾
	std::size_t getRemain() const override { return m_buffSize - m_used; }//�c��̃������ʂ��擾
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾���擾
	const byte* getNowPtrN() const { return m_buffPtr + m_used; }//���݂̃o�b�t�@�ʒu�i�����j���擾
	const byte* getNowPtr() const override { return getNowPtrN(); }//���݂̃o�b�t�@�ʒu���擾
	marker_t getMarkerN() const { return m_used; }//���݂̃}�[�J�[�i�����j���擾
	marker_t getMarker() const override { return getMarkerN(); }//���݂̃}�[�J�[���擾
public:
	//���\�b�h
	//�������m�ہi�����j
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_used;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_used + align_diff + size;//���̃}�[�J�[�Z�o
		if (next_used > m_buffSize)//�������I�[�o�[�`�F�b�N�i�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK�j
		{
			printf("stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_buffSize - m_used);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//�������m�ۃA�h���X�Z�o
		m_used = next_used;//�}�[�J�[�X�V
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocN(size, align);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���}�[�J�[�w���
	void backN(const marker_t marker)
	{
		if (marker >= m_used)//�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK
			return;
		m_used = marker;
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void back(const marker_t marker) override
	{
		return backN(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���|�C���^�w���
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		back(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void back(const void* p) override
	{
		backN(p);
	}
	//�������j���i�����j
	void clearN()
	{
		m_used = 0;//�}�[�J�[�����Z�b�g
	}
	//�������j���i�����j
	void clear() override
	{
		clearN();
	}
	//�������j���i�S�āj
	void clearAll() override
	{
		clearN();
	}
public:
	//�R���X�g���N�^
	CStackAllocator(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�擪�A�h���X
		m_buffSize(buff_size),//�o�b�t�@�T�C�Y
		m_used(0)//�}�[�J�[
	{}
	//�f�X�g���N�^
	~CStackAllocator() override
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�擪�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	marker_t m_used;//�}�[�J�[�i�����j
};

//--------------------
//�z�unew/�z�udelete
//���������g�p�󋵂��m�F���邽�߂Ƀ}�[�J�[��\��
//�z�unew
void* operator new(const std::size_t size, CStackAllocator& allocator, const std::size_t align = IStackAllocator::DEFAULT_ALIGN) throw()
{
	printf("placement new(size=%d, stack_allocator.marker=%d, align=%d)\n", size, allocator.getMarker(), align);
	return allocator.alloc(size, align);
}
//�z���
void* operator new[](const std::size_t size, CStackAllocator& allocator, const std::size_t align = IStackAllocator::DEFAULT_ALIGN) throw()
{
	printf("placement new[](size=%d, stack_allocator.marker=%d, align=%d)\n", size, allocator.getMarker(), align);
	return allocator.alloc(size, align);
}
//�z�udelete
void operator delete(void* p, CStackAllocator& allocator, const std::size_t) throw()
{
	printf("placement delete(p=0x%p, stack_allocator.marker=%d)\n", p, allocator.getMarker());
	//allocator.back(p) �͎��s���Ȃ�
}
//�z���
void operator delete[](void* p, CStackAllocator& allocator, const std::size_t) throw()
{
	printf("placement delete[](p=0x%p, stack_allocator.marker=%d)\n", p, allocator.getMarker());
	//allocator.back(p) �͎��s���Ȃ�
}
//�f�X�g���N�^�Ăяo���t��delete
template<class T>
void delete_ptr(T*& p, CStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, stack_allocator.marker=%d)\n", p, allocator.getMarker());
	if (!p)
		return;
	p->~T();//�f�X�g���N�^�Ăяo��
	//operator delete(p, allocator, 0) �͎��s���Ȃ�
	//allocator.back(p) �͎��s���Ȃ�
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//�z���
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, array_num=%d, stack_allocator.marker=%d)\n", p, array_num, allocator.getMarker());
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//�f�X�g���N�^�Ăяo��
	//operator delete[](p, allocator, 0) �͎��s���Ȃ�
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
	~CStackAllocatorWithBuff() override
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

//--------------------------------------------------------------------------------
//�o�����X�^�b�N�A���P�[�^

//--------------------
//�o�����X�^�b�N�A���P�[�^�N���X
//����X���b�h�Z�[�t�i�������x�D��j
//���C���^�[�t�F�[�X���������邪�A�������̂��߂� virtual���\�b�h�ɗ��炸����\
class CDualStackAllocator : public IStackAllocator
{
public:
	//�A�N�Z�b�T
	std::size_t getTotal() const override { return m_buffSize; }//�S�̂̃������ʂ��擾
	std::size_t getUsed() const override { return m_usedN + m_buffSize - m_usedR; }//�g�p���̃������ʂ��擾
	std::size_t getRemain() const override { return m_usedR - m_usedN; }//�c��̃������ʂ��擾
	E_ORDERED getDefaultOrdered() const { return m_defaultOrdered; }//�f�t�H���g�̃X�^�b�N�����擾
	void setDefaultOrdered(const E_ORDERED ordered)//�f�t�H���g�̃X�^�b�N�����X�V
	{
		m_defaultOrdered = ordered == REVERSE ? REVERSE : NORMAL;
	}
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾���擾
	const byte* getNowPtrN() const { return m_buffPtr + m_usedN; }//���݂̃o�b�t�@�ʒu�i�����j���擾
	const byte* getNowPtrR() const { return m_buffPtr + m_usedR; }//���݂̃o�b�t�@�ʒu�i�t���j���擾
	const byte* getNowPtrD() const { return getNowPtr(m_defaultOrdered); }//���݂̃o�b�t�@�ʒu���擾
	const byte* getNowPtr(const E_ORDERED ordered) const { return ordered == DEFAULT ? getNowPtrD() : ordered == REVERSE ? getNowPtrR() : getNowPtrN(); }//���݂̃o�b�t�@�ʒu���擾
	const byte* getNowPtr() const override { return getNowPtrD(); }//���݂̃o�b�t�@�ʒu���擾
	marker_t getMarkerN() const { return m_usedN; }//���݂̃}�[�J�[�i�����j���擾
	marker_t getMarkerR() const { return m_usedR; }//���݂̃}�[�J�[�i�t���j���擾
	marker_t getMarkerD() const { return getMarker(m_defaultOrdered); }//���݂̃}�[�J�[���擾
	marker_t getMarker(const E_ORDERED ordered) const { return ordered == DEFAULT ? getMarkerD() : ordered == REVERSE ? getMarkerR() : getMarkerN(); }//���݂̃}�[�J�[���擾
	marker_t getMarker() const override { return getMarkerD(); }//���݂̃}�[�J�[���擾
public:
	//���\�b�h
	//�������m�ہi�����j
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedN;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_usedN + align_diff + size;//���̃}�[�J�[�Z�o
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
	void* allocR(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedR;//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t alloc_ptr_tmp = now_ptr - size;//�������m�ۃA�h���X�Z�o�i�b��j
		const uintptr_t align_diff = align > 0 ? alloc_ptr_tmp % align == 0 ? 0 : alloc_ptr_tmp % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_usedR - size - align_diff;//���̃}�[�J�[�Z�o
		if (next_used < m_usedN || next_used > m_buffSize)//�������I�[�o�[�`�F�b�N�i�I�[�o�[�t���[���Ēl���傫���Ȃ�\�����`�F�b�N�j
		{
			printf("reversed-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR - m_usedN);
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr - size - align_diff;//�������m�ۃA�h���X�Z�o
		m_usedR = next_used;//�}�[�J�[�X�V
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m��
	void* allocD(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return alloc(m_defaultOrdered, size, align);
	}
	//�������m��
	void* alloc(const E_ORDERED ordered, const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return ordered == DEFAULT ? allocD(size, align) : ordered == REVERSE ? allocR(size, align) : allocN(size, align);
	}
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocD(size, align);
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
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	//���}�[�J�[�w���
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
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backR(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void backD(const marker_t marker)
	{
		back(m_defaultOrdered, marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void backD(const void* p)
	{
		back(m_defaultOrdered, p);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void back(const E_ORDERED ordered, const marker_t marker)
	{
		ordered == DEFAULT ? backD(marker) : ordered == REVERSE ? backR(marker) : backN(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void back(const E_ORDERED ordered, const void* p)
	{
		ordered == DEFAULT ? backD(p) : ordered == REVERSE ? backR(p) : backN(p);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���}�[�J�[�w���
	void back(const marker_t marker) override
	{
		backD(marker);
	}
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���|�C���^�w���
	void back(const void* p) override
	{
		backD(p);
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
	//�������j��
	void clearD()
	{
		clear(m_defaultOrdered);
	}
	//�������j���i�����j
	void clearNR()
	{
		clearN();
		clearR();
	}
	//�������j��
	void clear(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? clearD() : ordered == REVERSE ? clearR() : clearN();
	}
	//�������j��
	void clear() override
	{
		clearD();
	}
	//�������j���i�S�āj
	void clearAll() override
	{
		clearNR();
	}
public:
	//�R���X�g���N�^
	CDualStackAllocator(void* buff_p, const std::size_t buff_size, const E_ORDERED default_ordered = NORMAL) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�擪�A�h���X
		m_buffSize(buff_size),//�o�b�t�@�T�C�Y
		m_usedN(0),//�}�[�J�[�i�����j
		m_usedR(buff_size)//�}�[�J�[�i�t���j
	{
		setDefaultOrdered(default_ordered);//�f�t�H���g�̃X�^�b�N����␳
	}
	//�f�X�g���N�^
	~CDualStackAllocator() override
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�擪�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	marker_t m_usedN;//�}�[�J�[�i�����j
	marker_t m_usedR;//�}�[�J�[�i�t���j
	E_ORDERED m_defaultOrdered;//�f�t�H���g�̃X�^�b�N��
};

//--------------------
//�z�unew/�z�udelete
//���������g�p�󋵂��m�F���邽�߂Ƀ}�[�J�[��\��
//�z�unew
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new(const std::size_t size, CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//�z���
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new[](const std::size_t size, CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, dual_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//�z�udelete
void operator delete(void* p, CDualStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) �͎��s���Ȃ�
}
void operator delete(void* p, CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) �͎��s���Ȃ�
}
//�z���
void operator delete[](void* p, CDualStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered) throw()
{
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) �͎��s���Ȃ�
}
void operator delete[](void* p, CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement delete[](p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	//allocator.back(ordered, p) �͎��s���Ȃ�
}
//�f�X�g���N�^�Ăяo���t��delete
template<class T>
void delete_ptr(T*& p, CDualStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, dual_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	if (!p)
		return;
	p->~T();//�f�X�g���N�^�Ăяo��
	//operator delete(p, allocator, 0) �͎��s���Ȃ�
	//allocator.back(p) �͎��s���Ȃ�
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//�z���
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CDualStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, array_num=%d, dual_allocator.marker=%d,%d)\n", p, array_num, allocator.getMarkerN(), allocator.getMarkerR());
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//�f�X�g���N�^�Ăяo��
	//operator delete[](p, allocator, 0) �͎��s���Ȃ�
	//allocator.back(p) �͎��s���Ȃ�
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
	CDualStackAllocatorWithBuff(const E_ORDERED default_ordered = NORMAL) :
		CDualStackAllocator(m_buff, BUFF_SIZE, default_ordered)
	{}
	//�f�X�g���N�^
	~CDualStackAllocatorWithBuff() override
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

//--------------------------------------------------------------------------------

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
		printf("back(%d)\n", marker);
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

//--------------------
//�e�X�g
void test4b()
{
	printf("---------- test4b:�o�����X�^�b�N�A���P�[�^ ----------\n");
	CDualStackAllocatorWithBuff<64> stack(DSA_NORMAL);//�o�����X�^�b�N�A���P�[�^�����i64�o�C�g�̃o�b�t�@���m�ہj
	printf("buff=0x%p\n", stack.getBuff());
	{
		printf("-----\n");
		printf("getDefaultOrdered()=%d\n", stack.getDefaultOrdered());
		int* i1 = new(stack) int[2];
		printf("i1=0x%p\n", i1);
		char* c1 = new(stack, 1, DSA_REVERSE) char[13];
		printf("c1=0x%p\n", c1);
		CStackAllocator::marker_t marker = stack.getMarker();//�}�[�J�[�擾
		CStackAllocator::marker_t marker_n = stack.getMarkerN();//�}�[�J�[�擾
		CStackAllocator::marker_t marker_r = stack.getMarkerR();//�}�[�J�[�擾
		printf("marker: default=%d, normal=%d, reverse=%d\n", marker, marker_n, marker_r);
		float* f1 = new(stack) float[4];
		printf("f1=0x%p\n", f1);
		CTest4b* obj1_p = new(stack, DSA_REVERSE)CTest4b("�e�X�g4b");
		printf("obj1_p=0x%p\n", obj1_p);
		delete_ptr(f1, 4, stack);
		delete_ptr(c1, 15, stack);
		delete_ptr(i1, 2, stack);
		delete_ptr(obj1_p, stack);
		stack.backN(marker_n);//�}�[�J�[��߂�
		printf("backN(%d)\n", marker_n);
		stack.backR(marker_r);//�}�[�J�[��߂�
		printf("backR(%d)\n", marker_r);
	}
	{
		printf("-----\n");
		stack.setDefaultOrdered(DSA_REVERSE);//�f�t�H���g�L���^�b�N����ύX
		printf("getDefaultOrdered()=%d\n", stack.getDefaultOrdered());
		CStackAllocator::marker_t marker = stack.getMarker();//�}�[�J�[�擾
		CStackAllocator::marker_t marker_n = stack.getMarkerN();//�}�[�J�[�擾
		CStackAllocator::marker_t marker_r = stack.getMarkerR();//�}�[�J�[�擾
		printf("marker: default=%d, normal=%d, reverse=%d\n", marker, marker_n, marker_r);
		CTest4b* obj2_p = new(stack, DSA_NORMAL)CTest4b[3];
		printf("obj2_p=0x%p\n", obj2_p);
		int* i2 = new(stack) int;
		printf("i2=0x%p\n", i2);
		float* f2 = new(stack, DSA_NORMAL) float;
		printf("f2=0x%p\n", f2);
		char* c2 = new(stack, 1) char;
		printf("c2=0x%p\n", c2);
		int* over1 = new(stack, DSA_NORMAL) int[10];//�yNG�z�T�C�Y�I�[�o�[
		printf("over1=0x%p\n", over1);
		int* over2 = new(stack) int[10];//�yNG�z�T�C�Y�I�[�o�[
		printf("over2=0x%p\n", over2);
		delete_ptr(f2, stack);
		delete_ptr(c2, stack);
		delete_ptr(i2, stack);
		delete_ptr(obj2_p, 3, stack);
	}
}

//--------------------------------------------------------------------------------
//�v�[���A���P�[�^

#include <atomic>//C++11�A�g�~�b�N�^

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
	static const index_t INVALID_INDEX = INT_MAX;//�u���b�N�C���f�b�N�X�̖����l
public:
	//�A�N�Z�b�T
	const byte* getBuff() const { return m_pool; }//�o�b�t�@�擾
	std::size_t getBlockSize() const { return m_blockSize; }//�u���b�N�T�C�Y
	index_t getBlocksNum() const { return m_poolBlocksNum; }//�v�[���u���b�N��
	index_t getUsed() const { return m_used.load(); }//�g�p�����擾
	index_t getRemain() const { return m_poolBlocksNum - m_used.load(); }//�c���擾
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

		m_used.store(0);//�g�p����
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
		//�g�p���u���b�N���`�F�b�N�́A�������̂��߂ɁA��x���b�N�͈̔͊O�ōs��
		if (m_used.load() >= m_poolBlocksNum)
			return INVALID_INDEX;//�󂫂Ȃ�

		//���b�N�擾
		//m_lock.lock();

		//�g�p���u���b�N�����ă`�F�b�N
		//if (m_used.load() >= m_poolBlocksNum)
		//{
		//	m_lock.unlock();//���b�N���
		//	return INVALID_INDEX;//�󂫂Ȃ�
		//}

		//�C���f�b�N�X�m��
		index_t index = INVALID_INDEX;
		if (m_next < m_poolBlocksNum)
		{
			//���g�p�C���f�b�N�X������ꍇ
			index = m_next++;//���g�p�擪�C���f�b�N�X�J�E���g�A�b�v
			m_used.fetch_add(1);//�g�p�����J�E���g�A�b�v
		}
		else
		{
			if (m_recycle != INVALID_INDEX)
			{
				//���T�C�N���\�ȃC���f�b�N�X������ꍇ
				index = m_recycle;//���T�C�N���C���f�b�N�X
				m_recycle = *reinterpret_cast<unsigned int*>(getBlock(index));//���T�C�N���C���f�b�N�X�X�V�i�󂫃m�[�h�̐擪�ɏ������܂�Ă���j
				m_used.fetch_add(1);//�g�p�����J�E���g�A�b�v
			}
		}

		//���b�N���
		//m_lock.unlock();

		//�ŏ��Ɏg�p���u���b�N���𔻒肵�Ă���̂ŁA���̎��_�ŃC���f�b�N�X�������Ȃ���΃v���O�����ɖ�肪����͂�
		//ASSERT(index != INVALID_INDEX, "Probably, mistaken logic in this program.");

		//�I��
		return index;
	}
	//�������u���b�N���
	//���w��̃C���f�b�N�X�̎g�p���t���O�����Z�b�g
	void release(const index_t index)
	{
		//�C���f�b�N�X�͈̔̓`�F�b�N�i���b�N�͈̔͊O�ōs���j
		if (index < 0 || index >= m_poolBlocksNum)
			return;

		//���b�N�擾
		//m_lock.lock();

		//���T�C�N��
		*reinterpret_cast<unsigned int*>(getBlock(index)) = m_recycle;//���T�C�N���C���f�b�N�X�������݁i�󂫃m�[�h�̐擪�ɋ����ɏ������ށj
		m_recycle = index;//���T�C�N���C���f�b�N�X�g�݊���

		//�g�p�����J�E���g�_�E��
		m_used.fetch_sub(1);

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
		return index == INVALID_INDEX ? nullptr : getBlock(index);
	}
	//���������
	void free(void * p)
	{
		//nullptr���͑���������s
		//ASSERT(p != nullptr, "CPoolAllocator::free() cannot free. Pointer is null.");
		if (!p)
			return;
		//�|�C���^����C���f�b�N�X���Z�o
		const intptr_t diff = reinterpret_cast<intptr_t>(p)-reinterpret_cast<intptr_t>(m_pool);//�|�C���^�̍���
		const index_t index = diff / m_blockSize;//�u���b�N�T�C�Y�Ŋ����ăC���f�b�N�X�Z�o
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
	const std::size_t m_blockSize;//�u���b�N�T�C�Y
	const index_t m_poolBlocksNum;//�v�[���u���b�N��
	std::atomic<index_t> m_used;//�g�p����
	index_t m_next;//���g�p�擪�C���f�b�N�X
	index_t m_recycle;//���T�C�N���C���f�b�N�X
	//CSpinLock m_lock;//���b�N
};

//--------------------
//�z�unew
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw()
{
	printf("placement new(size=%d, pool_allocator.used=%d/%d/%d)\n", size, allocator.getBlocksNum(), allocator.getUsed(), allocator.getRemain());
	return allocator.alloc(size);
}
//�z�udelete
void operator delete(void* p, CPoolAllocator& allocator) throw()
{
	printf("placement delete(p=0x%p, pool_allocator.used=%d/%d/%d)\n", p, allocator.getBlocksNum(), allocator.getUsed(), allocator.getRemain());
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
//���ʃA���P�[�^�C���^�[�t�F�[�X

//--------------------
//�������m�ۏ��
//���f�o�b�O���i�Q�Ƃ̂݁j
struct ALLOC_INFO;

//--------------------
//���ʃA���P�[�^�C���^�[�t�F�[�X�N���X
class IAllocator
{
public:
	//�萔
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//�f�t�H���g�̃A���C�������g
public:
	//���\�b�h
	virtual const char* getName() const = 0;//�A���P�[�^���擾
	virtual std::size_t getTotal() const = 0;//�S�̃������ʁ@���Q�l���i�������l�Ƃ͌���Ȃ��j
	virtual std::size_t getUsed() const = 0;//�g�p���������ʁ@���Q�l���i�������l�Ƃ͌���Ȃ��j
	virtual std::size_t getRemain() const = 0;//�c�胁�����ʁ@���Q�l���i�������l�Ƃ͌���Ȃ��j
	//�������m��
	virtual void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) = 0;
	//���������
	virtual void free(void* p) = 0;
public:
	//�f�X�g���N�^
	virtual ~IAllocator(){}
};

//--------------------
//�W���A���P�[�^�A�_�v�^�[�N���X
//��������malloc, free���g�p
#include <malloc.h>//malloc,_aligned_malloc�p
#include <stdlib.h>//memalign�p
class CStdAllocAdp : public IAllocator
{
public:
	//�^
	typedef CStdAllocAdp ALLOCATOR_TYPE;//�A���P�[�^�^�i�֋X�㎩�g���`�j
	typedef unsigned char byte;//�o�b�t�@�p
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CStdAllocAdp"; }//�A���P�[�^���擾
	std::size_t getTotal() const override { return 0; }//�S�̃������ʎ擾�@���W�v�s��
	std::size_t getUsed() const override { return 0; }//�g�p���������ʎ擾�@���W�v�s��
	std::size_t getRemain() const override { return 0; }//�c�胁�����ʎ擾�@���W�v�s��
public:
	//�I�y���[�^
	//��main�֐����O�ɉ�������̃������m�ۏ��������s���ꂽ�ꍇ�A
	//�@CPolyAllocator�������I�ɂ��̃N���X������������K�v�����邽�߁A
	//�@new / delete ���Z�q�ƃC���X�^���X�p�̐ÓI�o�b�t�@����������
	static void* operator new(const std::size_t) throw(){ return m_buff; }//new���Z�q
	static void operator delete(void*) throw() {}//delete���Z�q
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		//return malloc(size);//�ʏ�malloc()
	#ifdef USE_MEMALIGN
		return memalign(align, size);//GCC�p�F�A���C�������g�w���malloc
	#else//USE_MEMALIGN
		return _aligned_malloc(size, align);//MS�d�l�F�A���C�������g�w���malloc
	#endif//USE_MEMALIGN
	}
	//���������
	void free(void* p) override
	{
		if (!p)
			return;
	#ifdef USE_MEMALIGN
		::free(p);//�ʏ�free() ��memalign�Ŋm�ۂ�����������free�ŉ��
	#else//USE_MEMALIGN
		_aligned_free(p);//MS�d�l�F�A���C�������g�w���free
	#endif//USE_MEMALIGN
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CStdAllocAdp()
	{}
	//�f�X�g���N�^
	~CStdAllocAdp() override
	{}
private:
	//�t�B�[���h
	static byte m_buff[];
};
//�W���A���P�[�^�A�_�v�^�[�N���X�̐ÓI�ϐ��C���X�^���X��
CStdAllocAdp::byte CStdAllocAdp::m_buff[sizeof(CStdAllocAdp)];

//--------------------
//�P��o�b�t�@�A���P�[�^�A�_�v�^�[�N���X
//���P�Ȃ�o�b�t�@��1�񂾂��A���P�[�g���邽�߂̃N���X
//������̃o�b�t�@�ɃC���X�^���X�𐶐��������ꍇ�ɗp����
class CMonoAllocAdp : public IAllocator
{
public:
	//�^
	//typedef CMonoAllocAdp ALLOCATOR_TYPE;//�A���P�[�^�^�i�A���P�[�^�Ȃ��j
	typedef unsigned char* byte;//�o�b�t�@�p
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CMonoAllocAdp"; }//�A���P�[�^���擾
	std::size_t getTotal() const override { return m_buffSize; }//�S�̃������ʎ擾
	std::size_t getUsed() const override { return m_isAllocated ? m_buffSize : 0; }//�g�p���������ʎ擾
	std::size_t getRemain() const override { return m_isAllocated ? 0 : m_buffSize; }//�c�胁�����ʎ擾
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾
	std::size_t getBuffSize() const { return m_buffSize; }//�o�b�t�@�T�C�Y�擾
	bool isAllocated() const { return m_isAllocated; }//�������m�ۍς�
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		if (m_isAllocated)
			return nullptr;
		m_isAllocated = true;//�������m�ۍς�
		return m_buffPtr;
	}
	//���������
	void free(void* p) override
	{
		if (!p)
			return;
		if (!m_isAllocated)
			return;
		m_isAllocated = false;//�������m�ۍς݉���
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CMonoAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CMonoAllocAdp(void* buff_p, const std::size_t buff_size) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�A�h���X
		m_buffSize(buff_size),//�o�b�t�@�T�C�Y
		m_isAllocated(false)//�������m�ۍς�
	{}
	//�f�X�g���N�^
	~CMonoAllocAdp() override
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	bool m_isAllocated;//�������m�ۍς�
};

//--------------------
//�o�b�t�@�t���P��o�b�t�@�A���P�[�^�A�_�v�^�[�e���v���[�g�N���X
template<std::size_t SIZE>
class CMonoAllocAdpWithBuff : public CMonoAllocAdp
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = SIZE;//�o�b�t�@�T�C�Y
public:
	//�R���X�g���N�^
	CMonoAllocAdpWithBuff() :
		CMonoAllocAdp(m_buff, BUFF_SIZE)
	{}
	//�f�X�g���N�^
	~CMonoAllocAdpWithBuff() override
	{}
private:
	//�t�B�[���h
	byte m_buff[BUFF_SIZE];//�o�b�t�@
};

//--------------------
//�X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�A�_�v�^�[�N���X
//���X�^�b�N�A���P�[�^�^�o�����X�^�b�N�A���P�[�^���p�̃A�_�v�^�[
class CIStackAllocAdp : public IAllocator
{
public:
	//�^
	typedef IStackAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�萔
	//���������߂�
	enum E_AUTO_REWIND
	{
		NOREWIND = 0,//�����߂��Ȃ�
		AUTO_REWIND = 1,//�w��̃X�^�b�N���Ɋ����߂�
		BOTH_AUTO_REWIND = 2,//�������Ɋ����߂��i�o�����X�^�b�N�A���P�[�^�̂݁j
	};
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CIStackAllocAdp"; }//�A���P�[�^���擾
	std::size_t getTotal() const override { return m_allocator.getTotal(); }//�S�̃������ʎ擾
	std::size_t getUsed() const override { return m_allocator.getUsed(); }//�g�p���������ʎ擾
	std::size_t getRemain() const override { return m_allocator.getRemain(); }//�c�胁�����ʎ擾
	IStackAllocator& getAllocator(){ return m_allocator; }//�A���P�[�^�擾
	const IStackAllocator& getAllocator() const { return m_allocator; }//�A���P�[�^�擾
	E_AUTO_REWIND getAutoRewind() const { m_autoRewind; }//���������߂��w��擾
	void setAutoRewind(const E_AUTO_REWIND auto_rewind){ m_autoRewind = auto_rewind; }//���������߂��w��X�V
	IStackAllocator::marker_t getRewindMarker() const { return m_rewindMarker; }//�����߂��}�[�J�[�擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		return m_allocator.alloc(size, align);//virtual�����o�[���g��
	}
	//���������
	void free(void* p) override
	{
		//�Ȃɂ����Ȃ�
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CIStackAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CIStackAllocAdp(IStackAllocator& allocator, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		m_allocator(allocator),//�X�^�b�N�A���P�[�^
		m_autoRewind(auto_rewind)//���������߂��w��
	{
		//���������߂��ʒu�L��
		m_rewindMarker = m_allocator.getMarker();
	}
	//�f�X�g���N�^
	~CIStackAllocAdp() override
	{
		//���������߂�
		if (m_autoRewind == AUTO_REWIND)
		{
			m_allocator.back(m_rewindMarker);
		}
	}
protected:
	//�t�B�[���h
	IStackAllocator& m_allocator;//�X�^�b�N�A���P�[�^
	E_AUTO_REWIND m_autoRewind;//���������߂��w��
	IStackAllocator::marker_t m_rewindMarker;//�����߂��}�[�J�[
};

//--------------------
//�X�^�b�N�A���P�[�^�A�_�v�^�[
//���X�^�b�N�A���P�[�^�p�̃A�_�v�^�[
class CStackAllocAdp : public CIStackAllocAdp
{
public:
	//�^
	typedef CStackAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CStackAllocAdp"; }//�A���P�[�^���擾
	CStackAllocator& getAllocator(){ return *static_cast<CStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	const CStackAllocator& getAllocator() const { return *static_cast<CStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CStackAllocator& allocator = getAllocator();
		return allocator.allocN(size, align);//��virtual�����o�[���g��
	}
	//���������
	void free(void* p) override
	{
		//�Ȃɂ����Ȃ�
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CStackAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CStackAllocAdp(CStackAllocator& allocator, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		CIStackAllocAdp(allocator, auto_rewind)//�X�^�b�N�A���P�[�^
	{}
	//�f�X�g���N�^
	~CStackAllocAdp() override
	{}
};

//--------------------
//�o�����X�^�b�N�A���P�[�^�A�_�v�^�[�N���X
class CDualStackAllocAdp : public CIStackAllocAdp
{
public:
	//�^
	typedef CDualStackAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CDualStackAllocAdp"; }//�A���P�[�^���擾
	CDualStackAllocator& getAllocator(){ return *static_cast<CDualStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	const CDualStackAllocator& getAllocator() const { return *static_cast<CDualStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	IStackAllocator::E_ORDERED getOrdered() const { return m_ordered; }//�X�^�b�N���擾
	void setOrdered(const IStackAllocator::E_ORDERED ordered){ m_ordered = ordered; }//�X�^�b�N���X�V
	IStackAllocator::marker_t getRewindMarkerN() const { return m_rewindMarker; }//�����߂��}�[�J�[�i�����j�擾
	IStackAllocator::marker_t getRewindMarkerR() const { return m_rewindMarkerR; }//�����߂��}�[�J�[�i�t���j�擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CDualStackAllocator& allocator = getAllocator();
		return allocator.alloc(m_ordered, size, align);//��virtual�����o�[���g��
	}
	//���������
	void free(void* p) override
	{
		//�Ȃɂ����Ȃ�
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CDualStackAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CDualStackAllocAdp(CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT, const E_AUTO_REWIND auto_rewind = NOREWIND) :
		CIStackAllocAdp(allocator, auto_rewind),//�o�����X�^�b�N�A���P�[�^
		m_ordered(ordered)//�X�^�b�N��
	{
		//���������߂��ʒu�L��
		m_rewindMarker = allocator.getMarkerN();//����
		m_rewindMarkerR = allocator.getMarkerR();//�t��
	}
	//�f�X�g���N�^
	~CDualStackAllocAdp() override
	{
		//���������߂�
		if (m_autoRewind == BOTH_AUTO_REWIND)
		{
			//�������̊����߂�
			CDualStackAllocator& allocator = getAllocator();
			allocator.backN(m_rewindMarker);//����
			allocator.backR(m_rewindMarkerR);//�t��
		}
		else if (m_autoRewind == AUTO_REWIND)
		{
			//�P�����̊����߂�
			CDualStackAllocator& allocator = getAllocator();
			if (m_ordered == IStackAllocator::NORMAL)//�����X�^�b�N�̂�
				allocator.backN(m_rewindMarker);
			else if (m_ordered == IStackAllocator::REVERSE)//�t���X�^�b�N�̂�
				allocator.backR(m_rewindMarkerR);
			else//if (m_ordered == IStackAllocator::DEFAULT)//�A���P�[�^�̃f�t�H���g�X�^�b�N���ɏ]��
			{
			//	allocator.backD(m_rewindMarker);//���̃��\�b�h�͎g��Ȃ�
				if (allocator.getDefaultOrdered() == IStackAllocator::REVERSE)//�t���X�^�b�N�̂�
					allocator.backR(m_rewindMarkerR);
				else//if (allocator.getDefaultOrdered() == IStackAllocator::NORMAL)//�����X�^�b�N�̂�
					allocator.backN(m_rewindMarker);
			}
		}
		m_autoRewind = NOREWIND;//�e�N���X�̃f�X�g���N�^�����Ŗ�肪�N����Ȃ��悤�ɐݒ�𖳌�������
	}
private:
	//�t�B�[���h
	IStackAllocator::E_ORDERED m_ordered;//�X�^�b�N��
	//IStackAllocator::marker_t m_rewindMarker;//�����߂��}�[�J�[�i�����j���e�N���X�̕ϐ����g�p
	IStackAllocator::marker_t m_rewindMarkerR;//�����߂��}�[�J�[�i�t���j
};

//--------------------
//�v�[���A���P�[�^�A�_�v�^�[�N���X
class CPoolAllocAdp : public IAllocator
{
public:
	//�^
	typedef CPoolAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�A�N�Z�b�T
	const char* getName() const override { return "CPoolAllocAdp"; }//�A���P�[�^���擾
	std::size_t getTotal() const override { return m_allocator.getBlocksNum() * m_allocator.getBlockSize(); }//�S�̃������ʎ擾
	std::size_t getUsed() const override { return m_allocator.getUsed() * m_allocator.getBlockSize(); }//�g�p���������ʎ擾
	std::size_t getRemain() const override { return m_allocator.getRemain() * m_allocator.getBlockSize(); }//�c�胁�����ʎ擾
	CPoolAllocator& getAllocator() const { return m_allocator; }//�A���P�[�^�擾
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		return m_allocator.alloc(size);
	}
	//���������
	void free(void* p) override
	{
		return m_allocator.free(p);
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CPoolAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CPoolAllocAdp(CPoolAllocator& allocator) :
		m_allocator(allocator)//�v�[���A���P�[�^
	{}
	//�f�X�g���N�^
	~CPoolAllocAdp() override
	{}
private:
	//�t�B�[���h
	CPoolAllocator& m_allocator;//�v�[���A���P�[�^
};

//--------------------
//�z�unew
void* operator new(const std::size_t size, IAllocator& allocator) throw()
{
	printf("placement new(size=%d, i_allocator=\"%s\":%d/%d/%d)\n", size, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	void* p = allocator.alloc(size);
	printf("  p=0x%p\n", p);
	return p;
}
//�z���
void* operator new[](const std::size_t size, IAllocator& allocator) throw()
{
	printf("placement new[](size=%d, i_allocator=\"%s\":%d/%d/%d)\n", size, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	void* p = allocator.alloc(size);
	printf("  p=0x%p\n", p);
	return p;
}
//�z�udelete
void operator delete(void* p, IAllocator& allocator) throw()
{
	printf("placement delete(p=0x%p, i_allocator=\"%s\":%d/%d/%d)\n", p, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	allocator.free(p);
}
//�z���
void operator delete[](void* p, IAllocator& allocator) throw()
{
	printf("placement delete[](p=0x%p, i_allocator=\"%s\":%d/%d/%d)\n", p, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	allocator.free(p);
}
//�f�X�g���N�^�Ăяo���t��delete
template<class T>
void delete_ptr(T*& p, IAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, i_allocator=\"%s\":%d/%d/%d)\n", p, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	if (!p)
		return;
	p->~T();//�f�X�g���N�^�Ăяo��
	operator delete(p, allocator);
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//�z���
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, IAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, array_num=%d, i_allocator=\"%s\":%d/%d/%d)\n", p, array_num, allocator.getName(), allocator.getTotal(), allocator.getUsed(), allocator.getRemain());
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//�f�X�g���N�^�Ăяo��
	operator delete[](p, allocator);
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}

//--------------------
//�e�X�g�p�N���X
//__declspec(align(8))//8�o�C�g�A���C�������g�Ńe�X�g����ꍇ�͂��̍s��L���ɂ���
class CTest6
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTest6() :
		CTest6("(default)")//���̃R���X�g���N�^�Ăяo���iC++11�Œǉ����ꂽ�d�l�j
		//m_name("(default)")//C++11���g���Ȃ��ꍇ�͕��ʂɏ�����
	{
		printf("CTest6::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CTest6(const char* name) :
		m_name(name)
	{
		printf("CTest6::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	virtual ~CTest6()
	{
		printf("CTest6::Destructor : name=\"%s\"\n", m_name);
	}
protected:
	//�t�B�[���h
	const char* m_name;//���O
	int m_dummy;//�_�~�[
};
//--------------------
//�e�X�g�p�N���X�i���d�p���e�X�g�p�j
class CTest6ex
{
public:
	//�R���X�g���N�^
	CTest6ex()
	{
		printf("CTest6ex::Constructor\n");
	}
	//�f�X�g���N�^
	virtual ~CTest6ex()
	{
		printf("CTest6ex::Destructor\n");
	}
protected:
	//�t�B�[���h
	int m_dummy;//�_�~�[
};
//--------------------
//�e�X�g�p�N���X�i���d�p���j
class CDerivedTest6 : public CTest6, public CTest6ex
{
public:
	//�f�t�H���g�R���X�g���N�^
	CDerivedTest6() :
		CTest6(),
		CTest6ex()
	{
		printf("CDerivedTest6::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CDerivedTest6(const char* name) :
		CTest6(name),
		CTest6ex()
	{
		printf("CDerivedTest6::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	~CDerivedTest6() override
	{
		printf("CDerivedTest6::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	int m_dummy;//�_�~�[
};

//--------------------
//�e�X�g�i���ʊ֐��j
//�����ۂ̃A���P�[�^��؂�ւ��ċ��ʏ��������s����e�X�g
//�N���X�P�̂̃e�X�g
void test6_sub1(const char* name, IAllocator& allocator)
{
	CTest6* obj_p = new(allocator)CTest6(name);
	printf("obj_p=0x%p\n", obj_p);
	delete_ptr(obj_p, allocator);
}
//�N���X�̔z��̃e�X�g
void test6_sub2(IAllocator& allocator)
{
	CTest6* obj_p = new(allocator)CTest6[3];
	printf("obj_p=0x%p\n", obj_p);
	delete_ptr(obj_p, 3, allocator);
}
//���d�p���N���X�̃e�X�g
void test6_sub3(const char* name, IAllocator& allocator)
{
	CTest6ex* obj_p = new(allocator)CDerivedTest6(name);//�A�b�v�L���X�g
	printf("obj_p=0x%p\n", obj_p);
	delete_ptr(obj_p, allocator);
}
//--------------------
//�e�X�g
void test6()
{
	printf("---------- test6:���ʃA���P�[�^�C���^�[�t�F�[�X ----------\n");
	//�W���A���P�[�^�imalloc / free�j�g�p
	{
		printf("----------CStdAllocAdp\n");
		CStdAllocAdp allocator_adp;
		test6_sub1("�e�X�g6-1a", allocator_adp);
		//test6_sub2(allocator_adp);//�N���X�̔z��ł��ꂽ�|�C���^�����̂܂�free����̂Ńn���O����
		//test6_sub3("�e�X�g6-1b", allocator_adp);//���d�p���ł��ꂽ�|�C���^�����̂܂�free����̂Ńn���O����
	}
	//�P��o�b�t�@�A���P�[�^�g�p
	{
		printf("----------CMonoAllocAdp\n");
		CMonoAllocAdpWithBuff<128> allocator_adp;
		test6_sub1("�e�X�g6-2a", allocator_adp);
		test6_sub2(allocator_adp);
		test6_sub3("�e�X�g6-2b", allocator_adp);
	}
	//�X�^�b�N�A���P�[�^�g�p
	{
		printf("----------CStackAllocAdp\n");
		CStackAllocatorWithBuff<128> allocator;
		CStackAllocAdp allocator_adp(allocator);
		test6_sub1("�e�X�g6-3a", allocator_adp);
		{
			//���������߂��̃e�X�g
			CStackAllocAdp allocator_adp_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test6_sub2(allocator_adp_tmp);
		}
		test6_sub3("�e�X�g6-3b", allocator_adp);
	}
	//�o�����X�^�b�N�A���P�[�^�g�p
	{
		printf("----------CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<128> allocator;
		CDualStackAllocAdp allocator_adp(allocator, DSA_REVERSE);
		test6_sub1("�e�X�g6-4a", allocator_adp);
		{
			//���������߂��̃e�X�g
			CDualStackAllocAdp allocator_adp_tmp(allocator, DSA_REVERSE, CIStackAllocAdp::AUTO_REWIND);
			test6_sub2(allocator_adp_tmp);
		}
		test6_sub3("�e�X�g6-4b", allocator_adp);
	}
	//�X�^�b�N�A���P�[�^���X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�Ƃ��Ďg�p
	{
		printf("----------CIStackAllocAdp on CStackAllocAdp\n");
		CStackAllocatorWithBuff<128> allocator;
		CIStackAllocAdp allocator_adp(allocator);
		test6_sub1("�e�X�g6-5a", allocator_adp);
		{
			//���������߂��̃e�X�g
			CIStackAllocAdp allocator_adp_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test6_sub2(allocator_adp_tmp);
		}
		test6_sub3("�e�X�g6-5b", allocator_adp);
	}
	//�o�����X�^�b�N�A���P�[�^���X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�Ƃ��Ďg�p
	{
		printf("----------CIStackAllocAdp on CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<128> allocator;
		CIStackAllocAdp allocator_adp(allocator);
		test6_sub1("�e�X�g6-6a", allocator_adp);
		{
			//���������߂��̃e�X�g
			CIStackAllocAdp allocator_adp_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test6_sub2(allocator_adp_tmp);
		}
		test6_sub3("�e�X�g6-6b", allocator_adp);
	}
	//�v�[���A���P�[�^�g�p
	{
		printf("----------CPoolAllocAdp\n");
		CPoolAllocatorWithBuff<24, 5> allocator;
		CPoolAllocAdp allocator_adp(allocator);
		test6_sub1("�e�X�g6-7a", allocator_adp);
		test6_sub2(allocator_adp);
		test6_sub3("�e�X�g6-7b", allocator_adp);
	}
}

//--------------------------------------------------------------------------------
//�O���[�o��new/delete + ���ʃA���P�[�^�C���^�[�t�F�[�X

//--------------------
//�N���X�錾
class CTempPolyAllocatorBase;//�ꎞ���ԃA���P�[�^���N���X

//--------------------
//���ԃA���P�[�^
class CPolyAllocator
{
#ifndef IS_NOT_FRIEND_WITH_NEW_OPERATOR
	//�W�� new / deleete ���Z�q���t�����h��
	//������ CPolyAllocator �N���X�𒼐ڃC���X�^���X������̂� new / delete ���Z�q�̂�
	friend void* operator new(const std::size_t size) throw();
	friend void* operator new[](const std::size_t size) throw();
	friend void operator delete(void* p) throw();
	friend void operator delete[](void* p) throw();
#endif//IS_NOT_FRIEND_WITH_NEW_OPERATOR
	friend class CTempPolyAllocatorBase;//�ꎞ���ԃA���P�[�^���N���X
public:
	//�I�y���[�^
	IAllocator* operator->(){ return m_allocator; }//�A���[���Z�q�i�v���L�V�[�j
public:
	//�A�N�Z�b�T
	//�A���P�[�^�擾
	static IAllocator* getAllocator()
	{
		return m_allocator;
	}
	//�A���P�[�^�ύX
	//���߂�Ƃ��ĕύX�O�̃A���P�[�^��Ԃ�
	//���Ȃ�ׂ����ڎg�p�֎~��CTempPoly***Allocator�N���X���g���A�R���X�g���N�^�Ŏ����I�Ɍ��ɖ߂�
	static IAllocator* setAllocator(IAllocator& new_allocator)
	{
		IAllocator* prev_allocator = m_allocator;//�ύX�O�̃A���P�[�^�擾
		m_allocator = &new_allocator;//�A���P�[�^�ύX
		return prev_allocator;//�ύX�O�̃A���P�[�^��Ԃ�
	}
	//�������m�ۏ��擾
	static const ALLOC_INFO* getAllocInfo()
	{
		return m_allocInfo;
	}
	//�������m�ۏ��擾�Ɠ����ɏ���j��
	static const ALLOC_INFO* getAllocInfoWithReset()
	{
		const ALLOC_INFO* info = m_allocInfo;
		m_allocInfo = nullptr;
		return info;
	}
	//�������m�ۏ����Z�b�g
	static void setAllocInfo(const ALLOC_INFO* info)
	{
		m_allocInfo = info;
	}
#ifdef IS_NOT_FRIEND_WITH_NEW_OPERATOR
public:
#else//IS_NOT_FRIEND_WITH_NEW_OPERATOR
private://���ڃC���X�^���X�����s�i�t�����h��p�j
#endif//IS_NOT_FRIEND_WITH_NEW_OPERATOR
	//�f�t�H���g�R���X�g���N�^
	CPolyAllocator()
	{
		if (!m_allocator)//�܂����̃A���P�[�^���ێ����Ă��Ȃ��ꍇ�W���A���P�[�^�������I�ɕێ�����
			m_allocator = new CStdAllocAdp();//�W���A���P�[�^�𖾎��I�ɏ������i�N���X��new���g�p�j
	}
public:
	//�f�X�g���N�^
	~CPolyAllocator()
	{}
protected:
	//�t�B�[���h
	static thread_local IAllocator* m_allocator;//���݂̃A���P�[�^
	static thread_local const ALLOC_INFO* m_allocInfo;//���݂̃������m�ۏ��
	//TLS�𗘗p���A�A���P�[�^�̕ύX�����̃X���b�h�ɉe�����Ȃ��悤�ɂ���
};
//--------------------
//���ԃA���P�[�^�̐ÓI�ϐ��C���X�^���X��
thread_local IAllocator* CPolyAllocator::m_allocator = nullptr;//���݂̃A���P�[�^
thread_local const ALLOC_INFO* CPolyAllocator::m_allocInfo = nullptr;//���݂̃������m�ۏ��

//--------------------
//�������m�ۏ��
//���f�o�b�O���i�Q�Ƃ̂݁j
struct ALLOC_INFO
{
	static const std::size_t DEFAULT_ALIGN = sizeof(int);//�f�t�H���g�̃A���C�������g�T�C�Y
	const char* m_fileName;//�t�@�C����
	const char* m_funcName;//�֐���
	const char* m_callPointName;//�R�[���|�C���g��
	float m_time;//�Q�[������
	const char* m_typeName;//�^��
	std::size_t m_align;//�A���C�������g�T�C�Y
	ALLOC_INFO(const char* file_name, const char* func_name, const char* call_point_name, const float time, const char* type_name, const std::size_t align = DEFAULT_ALIGN) :
		m_fileName(file_name),
		m_funcName(func_name),
		m_callPointName(call_point_name),
		m_time(time),
		m_typeName(type_name),
		m_align(align)
	{}
};

//--------------------
//�f�o�b�O�����W�p�֐�
const char* getCurrentCallPointNameDummy(){ return "(unknown call-point)"; }//�R�[���|�C���g���擾
float getGameTimeDummy(){ return 0.f; }//�Q�[�����Ԏ擾

//--------------------
//���ʊ֐�
#include <string.h>
#ifdef ENABLE_CONSTEXPR
//�yconstexpr�Łz�t�@�C�����擾�֐��i�f�B���N�g�������������������Ԃ��j
//���ċA�������i���ڎg�p���Ȃ��j
CONSTEXPR const char* getConstFileNameRecursive(const char* str, const std::size_t len)
{
	return len == 0 ?
	str :
		*(str + len - 1) == '\\' || *(str + len - 1) == '/' ?
			str + len :
			getConstFileNameRecursive(str, len - 1);
}
//�yconstexpr�Łz�t�@�C�����擾�֐��i�f�B���N�g�������������������Ԃ��j
CONSTEXPR const char* getConstFileName(const char* str)
{
	return getConstFileNameRecursive(str, strlen(str));
}
#else//ENABLE_CONSTEXPR
//�y�ʏ�Łz�t�@�C�����擾�֐��i�f�B���N�g�������������������Ԃ��j
const char* getFileName(const char* str)
{
	std::size_t len = strlen(str);
	const char* p = str + len;
	for (; len > 0; --len, --p)
	{
		const char c = *(p - 1);
		if (c == '\\' || c == '/')
			return p;
	}
	return str;
}
#endif//ENABLE_CONSTEXPR

#ifndef USE_GLOBAL_NEW_DELETE_FOR_TEST2
//--------------------
//���ʊ֐��Q��
const char* getFileName(const char* str);//�֐��Q�ƁF�t�@�C�����擾�֐��i�f�B���N�g�������������������Ԃ��j
//--------------------
//�O���[�o�����ԃA���P�[�^
//���W��new / delete ���Z�q�̒u������
//new
void* operator new(const std::size_t size) throw()
{
	CPolyAllocator allocator;
	printf("new(size=%d, poly_allocator=\"%s\":%d/%d/%d)\n", size, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//�������m�ۏ��擾
	if (info)
	{
		align = info->m_align;
	#ifdef ENABLE_CONSTEXPR
		printf("  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\n", info->m_fileName, info->m_funcName, info->m_callPointName, info->m_time, info->m_typeName, info->m_align);
	#else//ENABLE_CONSTEXPR
		printf("  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\n", getFileName(info->m_fileName), info->m_funcName, info->m_callPointName, info->m_time, info->m_typeName, info->m_align);
	#endif//ENABLE_CONSTEXPR
	}
	void* p = allocator->alloc(size, align);
	printf("  p=0x%p\n", p);
	return p;
}
//�z���
void* operator new[](const std::size_t size) throw()
{
	CPolyAllocator allocator;
	printf("new[](size=%d, poly_allocator=\"%s\":%d/%d/%d)\n", size, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//�������m�ۏ��擾
	if (info)
	{
		align = info->m_align;
	#ifdef ENABLE_CONSTEXPR
		printf("  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\n", info->m_fileName, info->m_funcName, info->m_callPointName, info->m_time, info->m_typeName, info->m_align);
	#else//ENABLE_CONSTEXPR
		printf("  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\n", getFileName(info->m_fileName), info->m_funcName, info->m_callPointName, info->m_time, info->m_typeName, info->m_align);
	#endif//ENABLE_CONSTEXPR
	}
	void* p = allocator->alloc(size, align);
	printf("  p=0x%p\n", p);
	return p;
}
//delete
void operator delete(void* p) throw()
{
	CPolyAllocator allocator;
	printf("delete(p=0x%p, poly_allocator=\"%s\":%d/%d/%d)\n", p, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	allocator->free(p);
}
//�z���
void operator delete[](void* p) throw()
{
	CPolyAllocator allocator;
	printf("delete[](p=0x%p, poly_allocator=\"%s\":%d/%d/%d)\n", p, allocator->getName(), allocator->getTotal(), allocator->getUsed(), allocator->getRemain());
	allocator->free(p);
}
#endif//USE_GLOBAL_NEW_DELETE_FOR_TEST2

//--------------------
//�f�o�b�O�����W�p�֐��Q��
const char* getCurrentCallPointNameDummy();//�R�[���|�C���g���擾
float getGameTimeDummy();//�Q�[�����Ԏ擾

//--------------------
//�������m�ۏ��t��NEW����
template<class T, typename... Tx>
T* newWithInfo(const char* file_name, const char* func_name, const std::size_t align, Tx ...nx)
{
	const char* call_point_name = getCurrentCallPointNameDummy();//�R�[���|�C���g���擾
	const float game_time = getGameTimeDummy();//�Q�[�����Ԏ擾
	const ALLOC_INFO info(file_name, func_name, call_point_name, game_time, typeid(T).name(), align);//�������m�ۏ�񐶐�
	CPolyAllocator::setAllocInfo(&info);//�������m�ۏ��󂯓n�� �����[�J���ϐ��̃|�C���^���󂯓n�����ƂɂȂ邪�A�㑱�̏����ł̂ݎQ�Ƃ��邱�ƂƁATLS�ŕی삳��邽�ߖ��Ȃ�
	return new T(nx...);//�������m��
}
//�z���
//���y���_�z�z��new�ɃA���C�������g���w�肳�ꂽ�ꍇ�A�������|�C���^���v�Z������Ȃ����߁A�A���C�������g�w��ɑΉ����Ȃ�
template<class T, std::size_t array_size>
T* newArrayWithInfo(const char* file_name, const char* func_name)
{
	const char* call_point_name = getCurrentCallPointNameDummy();//�R�[���|�C���g���擾
	const float game_time = getGameTimeDummy();//�Q�[�����Ԏ擾
	const ALLOC_INFO info(file_name, func_name, call_point_name, game_time, typeid(T[array_size]).name());//�������m�ۏ�񐶐�
	CPolyAllocator::setAllocInfo(&info);//�������m�ۏ��󂯓n�� �����[�J���ϐ��̃|�C���^���󂯓n�����ƂɂȂ邪�A�㑱�̏����ł̂ݎQ�Ƃ��邱�ƂƁATLS�ŕی삳��邽�ߖ��Ȃ�
	return new T[array_size];//�������m��
}

//--------------------
//NEW�}�N���⏕�}�N��
#define TO_STRING(s) #s//__LINE__�𕶎��񉻂��邽�߂̓�d�}�N��
#define TO_STRING_EX(s) TO_STRING(s)//__LINE__�𕶎��񉻂��邽�߂̃}�N��
#ifdef ENABLE_CONSTEXPR
#define GET_CONCATENATED_FILE_NAME() getConstFileName(__FILE__ "(" TO_STRING_EX(__LINE__) ") [" __TIMESTAMP__ "]")//�t�@�C�����������擾�}�N��
#else//ENABLE_CONSTEXPR
#define GET_CONCATENATED_FILE_NAME() __FILE__ "(" TO_STRING_EX(__LINE__) ")  [" __TIMESTAMP__ "]"//�t�@�C�����������擾�}�N��
#endif//ENABLE_CONSTEXPR
#define GET_FUNC_NAME() __PRETTY_FUNCTION__//�֐����擾�}�N��
//#define GET_FUNC_NAME() __FUNCTION__

#ifdef USE_ALLOC_INFO
//--------------------
//NEW�}�N��
//���������m�ۏ��t��
#define NEW(T, ...) newWithInfo<T>(GET_CONCATENATED_FILE_NAME(), GET_FUNC_NAME(), ALLOC_INFO::DEFAULT_ALIGN, __VA_ARGS__)//NEW
#define NEWALIGN(T, align, ...) newWithInfo<T>(GET_CONCATENATED_FILE_NAME(), GET_FUNC_NAME(), align, __VA_ARGS__)//�A���C�������g�w��t��NEW
#define NEWARR(T, array_size) newArrayWithInfo<T, array_size>(GET_CONCATENATED_FILE_NAME(), GET_FUNC_NAME())//�z��NEW
//#define NEWALIGNARR(T, align, array_size)//�A���C�����g�w��t���z��NEW�͐��m�Ɍv�Z�ł��Ȃ��̂őΉ����Ȃ�
#else//USE_ALLOC_INFO
//--------------------
//NEW�}�N��
//���������m�ۏ��Ȃ�
#define NEW(T, ...) new T(__VA_ARGS__)//NEW
#define NEWALIGN(T, align, ...) new T(__VA_ARGS__)//�A���C�������g�w��t��NEW�i�݊��p�j�����ۂɂ̓A���C�������g�͋@�\���Ȃ�
#define NEWARR(T, array_size) new T[array_size]//�z��NEW
//#define NEWALIGNARR(T, align, array_size)//�A���C�����g�w��t���z��NEW�͐��m�Ɍv�Z�ł��Ȃ��̂őΉ����Ȃ�
#endif//USE_ALLOC_INFO
//--------------------
//DELETE�}�N��
#define DELETE delete//DELETE
#define DELETEARR delete[]//�z��DELETE

//--------------------
//�ꎞ���ԃA���P�[�^
//�����ԃA���P�[�^�́u���݂̃A���P�[�^�v���ꎞ�I�ɕύX���邽�߂̃N���X
//�������u���b�N�𔲂��鎞�ɁA�f�X�g���N�^�Ŏ����I�Ɍ��̏�Ԃɖ߂�

//--------------------
//�ꎞ���ԃA���P�[�^���N���X
//���p����p�N���X
class CTempPolyAllocatorBase : public CPolyAllocator
{
protected://���ڃC���X�^���X�����s�i�p����p�j
	//�f�t�H���g�R���X�g���N�^
	CTempPolyAllocatorBase() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyAllocatorBase(IAllocator& allocator) :
		CPolyAllocator()
	{
		m_prevAllocator = setAllocator(allocator);//�A���P�[�^��ύX���āA�ύX�O�̃A���P�[�^���L��
	}
public:
	//�f�X�g���N�^
	~CTempPolyAllocatorBase()
	{
		if (m_prevAllocator)
		{
			m_allocator = m_prevAllocator;//�ύX�O�̃A���P�[�^�ɖ߂�
			m_prevAllocator = nullptr;
		}
	}
private:
	//�t�B�[���h
	IAllocator* m_prevAllocator;//�ύX�O�̃A���P�[�^
};
//--------------------
//�ꎞ���ԃA���P�[�^�e���v���[�g�N���X�F�A�_�v�^�[�ێ��^�C�v
template<class ADAPTER>
class CTempPolyAllocatorWithAdp : public CTempPolyAllocatorBase
{
public:
	//�^
	typedef ADAPTER ADAPTER_TYPE;//�A�_�v�^�[�^
	typedef typename ADAPTER::ALLOCATOR_TYPE ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyAllocatorWithAdp() :
		m_adapter(),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//�R���X�g���N�^
	CTempPolyAllocatorWithAdp(ALLOCATOR_TYPE& allocator) :
		m_adapter(allocator),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//�f�X�g���N�^
	~CTempPolyAllocatorWithAdp()
	{}
protected:
	//�t�B�[���h
	ADAPTER_TYPE m_adapter;//�A���P�[�^�A�_�v�^�[
};
//--------------------
//�ꎞ���ԃA���P�[�^�e���v���[�g�N���X�F�A�_�v�^�[���ڗ��p�^�C�v
//���A�_�v�^�[��ێ������O������󂯓n�������̂����̂܂ܗ��p����
template<class ADAPTER>
class CTempPolyAllocatorDirect : public CTempPolyAllocatorBase
{
public:
	//�^
	typedef ADAPTER ADAPTER_TYPE;//�A�_�v�^�[�^
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyAllocatorDirect() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyAllocatorDirect(ADAPTER_TYPE& adapter) :
		CTempPolyAllocatorBase(adapter)
	{}
	//�f�X�g���N�^
	~CTempPolyAllocatorDirect()
	{}
};
//--------------------
//�ꎞ���ԃA���P�[�^�e���v���[�g�N���X�F�X�^�b�N�A���P�[�^�A�_�v�^�[�ێ��^�C�v
template<class ADAPTER>
class CTempPolyAllocatorWithStackAdp : public CTempPolyAllocatorBase
{
public:
	//�^
	typedef ADAPTER ADAPTER_TYPE;//�A�_�v�^�[�^
	typedef typename ADAPTER::ALLOCATOR_TYPE ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyAllocatorWithStackAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind) :
		m_adapter(allocator, auto_rewind),
		CTempPolyAllocatorBase(m_adapter)
	{}
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const IStackAllocator::E_ORDERED ordered, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind) :
		m_adapter(allocator, ordered, auto_rewind),
		CTempPolyAllocatorBase(m_adapter)
	{}
	CTempPolyAllocatorWithStackAdp(ALLOCATOR_TYPE& allocator, const IStackAllocator::E_ORDERED ordered) :
		m_adapter(allocator, ordered),
		CTempPolyAllocatorBase(m_adapter)
	{}
	//�f�X�g���N�^
	~CTempPolyAllocatorWithStackAdp()
	{}
protected:
	//�t�B�[���h
	ADAPTER_TYPE m_adapter;//�A���P�[�^�A�_�v�^�[
};
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�W���A���P�[�^�p
using CTempPolyStdAllocator = CTempPolyAllocatorWithAdp<CStdAllocAdp>;//C++11�`��
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�P��o�b�t�@�A���P�[�^�p
using CTempPolyMonoAllocator = CTempPolyAllocatorDirect<CMonoAllocAdp>;//C++11�`��
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�p
class CTempPolyIStackAllocator : public CTempPolyAllocatorWithStackAdp<CIStackAllocAdp>
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyIStackAllocator() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyIStackAllocator(IStackAllocator& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CIStackAllocAdp>(allocator, auto_rewind)
	{}
	//�f�X�g���N�^
	~CTempPolyIStackAllocator()
	{}
};
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�X�^�b�N�A���P�[�^�p
class CTempPolyStackAllocator : public CTempPolyAllocatorWithStackAdp<CStackAllocAdp>
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyStackAllocator() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyStackAllocator(CStackAllocator& allocator, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CStackAllocAdp>(allocator, auto_rewind)
	{}
	//�f�X�g���N�^
	~CTempPolyStackAllocator()
	{}
};
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�o�����X�^�b�N�A���P�[�^�p
class CTempPolyDualStackAllocator : public CTempPolyAllocatorWithStackAdp<CDualStackAllocAdp>
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolyDualStackAllocator() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolyDualStackAllocator(CDualStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT, const CIStackAllocAdp::E_AUTO_REWIND auto_rewind = CIStackAllocAdp::NOREWIND) :
		CTempPolyAllocatorWithStackAdp<CDualStackAllocAdp>(allocator, ordered, auto_rewind)
	{}
	//�f�X�g���N�^
	~CTempPolyDualStackAllocator()
	{}
};
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�v�[���A���P�[�^�p
using CTempPolyPoolAllocator = CTempPolyAllocatorWithAdp<CPoolAllocAdp>;//C++11�`��

//--------------------
//�e�X�g�p�N���X
//__declspec(align(8))//8�o�C�g�A���C�������g�Ńe�X�g����ꍇ�͂��̍s��L���ɂ���
class CTest7
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTest7() :
		CTest7("(default)")//���̃R���X�g���N�^�Ăяo���iC++11�Œǉ����ꂽ�d�l�j
		//m_name("(default)")//C++11���g���Ȃ��ꍇ�͕��ʂɏ�����
	{
		printf("CTest7::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CTest7(const char* name) :
		m_name(name)
	{
		printf("CTest7::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	virtual ~CTest7()
	{
		printf("CTest7::Destructor : name=\"%s\"\n", m_name);
	}
protected:
	//�t�B�[���h
	const char* m_name;//���O
	int m_dummy;//�_�~�[
};
//--------------------
//�e�X�g�p�N���X�i���d�p���e�X�g�p�j
class CTest7ex
{
public:
	//�R���X�g���N�^
	CTest7ex()
	{
		printf("CTest7ex::Constructor\n");
	}
	//�f�X�g���N�^
	virtual ~CTest7ex()
	{
		printf("CTest7ex::Destructor\n");
	}
protected:
	//�t�B�[���h
	int m_dummy;//�_�~�[
};
//--------------------
//�e�X�g�p�N���X�i���d�p���j
class CDerivedTest7 : public CTest7, public CTest7ex
{
public:
	//�f�t�H���g�R���X�g���N�^
	CDerivedTest7() :
		CTest7(),
		CTest7ex()
	{
		printf("CDerivedTest7::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CDerivedTest7(const char* name) :
		CTest7(name),
		CTest7ex()
	{
		printf("CDerivedTest7::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	~CDerivedTest7() override
	{
		printf("CDerivedTest7::Destructor : name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	int m_dummy;//�_�~�[
};

//--------------------
//�e�X�g�i���ʊ֐��j
//����̋��ʃA���P�[�^�C���^�[�t�F�[�X�̃e�X�g�ƈقȂ�A�A�_�v�^�[���󂯎�炸�A���̂܂� new / delete����
//���Ăяo�����ŁAnew / delete �̎�����؂�ւ��Ă���
//�N���X�P�̂̃e�X�g
void test7_sub1(const char* name)
{
#ifdef USE_NEW_MACRO
	CTest7* obj_p = NEW(CTest7, name);
	printf("obj_p=0x%p\n", obj_p);
	DELETE obj_p;
#else//USE_NEW_MACRO
	CTest7* obj_p = new CTest7(name);//�z�unew�ł͂Ȃ��A���ʂ�new���Z�q
	printf("obj_p=0x%p\n", obj_p);
	delete obj_p;//�z�udelete�ł͂Ȃ��A���ʂ�delete���Z�q
#endif//USE_NEW_MACRO
}
//�N���X�̔z��̃e�X�g
void test7_sub2()
{
#ifdef USE_NEW_MACRO
	CTest7* obj_p = NEWARR(CTest7, 3);
	printf("obj_p=0x%p\n", obj_p);
	DELETEARR obj_p;
#else//USE_NEW_MACRO
	CTest7* obj_p = new CTest7[3];//�z�unew�ł͂Ȃ��A���ʂ�new[]���Z�q
	printf("obj_p=0x%p\n", obj_p);
	delete[] obj_p;//�z�udelete�ł͂Ȃ��A���ʂ�delete[]���Z�q
#endif//USE_NEW_MACRO
}
//���d�p���N���X�̃e�X�g
void test7_sub3(const char* name)
{
#ifdef USE_NEW_MACRO
	CTest7ex* obj_p = NEWALIGN(CDerivedTest7, 16, name);//�A�b�v�L���X�g
	printf("obj_p=0x%p\n", obj_p);
	DELETE obj_p;
#else//USE_NEW_MACRO
	CTest7ex* obj_p = new CDerivedTest7(name);//�z�unew�ł͂Ȃ��A���ʂ�new���Z�q
	printf("obj_p=0x%p\n", obj_p);
	delete obj_p;//�z�udelete�ł͂Ȃ��A���ʂ�delete���Z�q
#endif//USE_NEW_MACRO
}
//--------------------
//�e�X�g
void test7()
{
	printf("---------- test7:�O���[�o��new/delete + ���ʃA���P�[�^�C���^�[�t�F�[�X ----------\n");
	//�W���A���P�[�^�imalloc / free�j�g�p
	{
		printf("----------CStdAllocAdp\n");
		CTempPolyStdAllocator poly_allocator;
		test7_sub1("�e�X�g7-1a");
		test7_sub2();//�N���X�̔z��ł��ꂽ�|�C���^�́Adelet[]���Z�q�ɂ���Đ�������������邽�߁A��肪�N����Ȃ�
		test7_sub3("�e�X�g7-1b");//���d�p���ł��ꂽ�|�C���^�́Adelet���Z�q�ɂ���Đ�������������邽�߁A��肪�N����Ȃ�
	}
	//�P��o�b�t�@�A���P�[�^�g�p
	{
		printf("----------CMonoAllocAdp\n");
		CMonoAllocAdpWithBuff<128> allocator_adp;
		CTempPolyMonoAllocator poly_allocator(allocator_adp);
		test7_sub1("�e�X�g7-2a");
		test7_sub2();
		test7_sub3("�e�X�g7-2b");
	}
	//�X�^�b�N�A���P�[�^�g�p
	{
		printf("----------CStackAllocAdp\n");
		CStackAllocatorWithBuff<128> allocator;
		CTempPolyStackAllocator poly_allocator(allocator);
		test7_sub1("�e�X�g7-3a");
		{
			//���������߂��̃e�X�g
			CTempPolyStackAllocator poly_allocator_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test7_sub2();
		}
		test7_sub3("�e�X�g7-3b");
	}
	//�o�����X�^�b�N�A���P�[�^�g�p
	{
		printf("----------CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<128> allocator;
		CTempPolyDualStackAllocator poly_allocator(allocator, DSA_REVERSE);
		test7_sub1("�e�X�g7-4a");
		{
			//���������߂��̃e�X�g
			CTempPolyDualStackAllocator poly_allocator_tmp(allocator, DSA_REVERSE, CIStackAllocAdp::AUTO_REWIND);
			test7_sub2();
		}
		test7_sub3("�e�X�g7-4b");
	}
	//�X�^�b�N�A���P�[�^���X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�Ƃ��Ďg�p
	{
		printf("----------CIStackAllocAdp on CStackAllocAdp\n");
		CStackAllocatorWithBuff<128> allocator;
		CTempPolyIStackAllocator poly_allocator(allocator);
		test7_sub1("�e�X�g7-5a");
		{
			//���������߂��̃e�X�g
			CTempPolyIStackAllocator poly_allocator_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test7_sub2();
		}
		test7_sub3("�e�X�g7-5b");
	}
	//�o�����X�^�b�N�A���P�[�^���X�^�b�N�A���P�[�^�C���^�[�t�F�[�X�Ƃ��Ďg�p
	{
		printf("----------CIStackAllocAdp on CDualStackAllocAdp\n");
		CDualStackAllocatorWithBuff<128> allocator;
		CTempPolyIStackAllocator poly_allocator(allocator);
		test7_sub1("�e�X�g7-6a");
		{
			//���������߂��̃e�X�g
			CTempPolyIStackAllocator poly_allocator_tmp(allocator, CIStackAllocAdp::AUTO_REWIND);
			test7_sub2();
		}
		test7_sub3("�e�X�g7-6b");
	}
	//�v�[���A���P�[�^�g�p
	{
		printf("----------CPoolAllocAdp\n");
		CPoolAllocatorWithBuff<24, 5> allocator;
		CTempPolyPoolAllocator poly_allocator(allocator);
		test7_sub1("�e�X�g7-7a");
		test7_sub2();
		test7_sub3("�e�X�g7-7b");
	}
}

//--------------------------------------------------------------------------------
//�W�����C�u������֗��Ɋ��p

//--------------------
//CRC�Z�o

#include <cstddef>//std::size_t�p
#include <assert.h>//assert�p

//--------------------
//�^
typedef unsigned int crc32_t;//CRC32�^

//--------------------
//CRC�Z�o�֐�
namespace crc_inner_calc//���ڎg�p���Ȃ��������B�؂����邽�߂̃l�[���X�y�[�X
{
#ifndef USE_CRC_CALC_TABLE
	//--------------------
	//CRC�����������v�Z�i�ċA�����j
	CONSTEXPR crc32_t calcPoly(crc32_t poly, const int n)
	{
		return n == 0 ? poly : calcPoly(poly & 1 ? 0xedb88320u ^ (poly >> 1) : (poly >> 1), n - 1);
	}
#else//USE_CRC_CALC_TABLE
	//--------------------
	//CRC�����������v�Z�v�Z�ς݃e�[�u��
	CONSTEXPR crc32_t s_calcTable[] =
	{
		0x00000000u, 0x77073096u, 0xee0e612cu, 0x990951bau, 0x076dc419u, 0x706af48fu, 0xe963a535u, 0x9e6495a3u,
		0x0edb8832u, 0x79dcb8a4u, 0xe0d5e91eu, 0x97d2d988u, 0x09b64c2bu, 0x7eb17cbdu, 0xe7b82d07u, 0x90bf1d91u,
		0x1db71064u, 0x6ab020f2u, 0xf3b97148u, 0x84be41deu, 0x1adad47du, 0x6ddde4ebu, 0xf4d4b551u, 0x83d385c7u,
		0x136c9856u, 0x646ba8c0u, 0xfd62f97au, 0x8a65c9ecu, 0x14015c4fu, 0x63066cd9u, 0xfa0f3d63u, 0x8d080df5u,
		0x3b6e20c8u, 0x4c69105eu, 0xd56041e4u, 0xa2677172u, 0x3c03e4d1u, 0x4b04d447u, 0xd20d85fdu, 0xa50ab56bu,
		0x35b5a8fau, 0x42b2986cu, 0xdbbbc9d6u, 0xacbcf940u, 0x32d86ce3u, 0x45df5c75u, 0xdcd60dcfu, 0xabd13d59u,
		0x26d930acu, 0x51de003au, 0xc8d75180u, 0xbfd06116u, 0x21b4f4b5u, 0x56b3c423u, 0xcfba9599u, 0xb8bda50fu,
		0x2802b89eu, 0x5f058808u, 0xc60cd9b2u, 0xb10be924u, 0x2f6f7c87u, 0x58684c11u, 0xc1611dabu, 0xb6662d3du,
		0x76dc4190u, 0x01db7106u, 0x98d220bcu, 0xefd5102au, 0x71b18589u, 0x06b6b51fu, 0x9fbfe4a5u, 0xe8b8d433u,
		0x7807c9a2u, 0x0f00f934u, 0x9609a88eu, 0xe10e9818u, 0x7f6a0dbbu, 0x086d3d2du, 0x91646c97u, 0xe6635c01u,
		0x6b6b51f4u, 0x1c6c6162u, 0x856530d8u, 0xf262004eu, 0x6c0695edu, 0x1b01a57bu, 0x8208f4c1u, 0xf50fc457u,
		0x65b0d9c6u, 0x12b7e950u, 0x8bbeb8eau, 0xfcb9887cu, 0x62dd1ddfu, 0x15da2d49u, 0x8cd37cf3u, 0xfbd44c65u,
		0x4db26158u, 0x3ab551ceu, 0xa3bc0074u, 0xd4bb30e2u, 0x4adfa541u, 0x3dd895d7u, 0xa4d1c46du, 0xd3d6f4fbu,
		0x4369e96au, 0x346ed9fcu, 0xad678846u, 0xda60b8d0u, 0x44042d73u, 0x33031de5u, 0xaa0a4c5fu, 0xdd0d7cc9u,
		0x5005713cu, 0x270241aau, 0xbe0b1010u, 0xc90c2086u, 0x5768b525u, 0x206f85b3u, 0xb966d409u, 0xce61e49fu,
		0x5edef90eu, 0x29d9c998u, 0xb0d09822u, 0xc7d7a8b4u, 0x59b33d17u, 0x2eb40d81u, 0xb7bd5c3bu, 0xc0ba6cadu,
		0xedb88320u, 0x9abfb3b6u, 0x03b6e20cu, 0x74b1d29au, 0xead54739u, 0x9dd277afu, 0x04db2615u, 0x73dc1683u,
		0xe3630b12u, 0x94643b84u, 0x0d6d6a3eu, 0x7a6a5aa8u, 0xe40ecf0bu, 0x9309ff9du, 0x0a00ae27u, 0x7d079eb1u,
		0xf00f9344u, 0x8708a3d2u, 0x1e01f268u, 0x6906c2feu, 0xf762575du, 0x806567cbu, 0x196c3671u, 0x6e6b06e7u,
		0xfed41b76u, 0x89d32be0u, 0x10da7a5au, 0x67dd4accu, 0xf9b9df6fu, 0x8ebeeff9u, 0x17b7be43u, 0x60b08ed5u,
		0xd6d6a3e8u, 0xa1d1937eu, 0x38d8c2c4u, 0x4fdff252u, 0xd1bb67f1u, 0xa6bc5767u, 0x3fb506ddu, 0x48b2364bu,
		0xd80d2bdau, 0xaf0a1b4cu, 0x36034af6u, 0x41047a60u, 0xdf60efc3u, 0xa867df55u, 0x316e8eefu, 0x4669be79u,
		0xcb61b38cu, 0xbc66831au, 0x256fd2a0u, 0x5268e236u, 0xcc0c7795u, 0xbb0b4703u, 0x220216b9u, 0x5505262fu,
		0xc5ba3bbeu, 0xb2bd0b28u, 0x2bb45a92u, 0x5cb36a04u, 0xc2d7ffa7u, 0xb5d0cf31u, 0x2cd99e8bu, 0x5bdeae1du,
		0x9b64c2b0u, 0xec63f226u, 0x756aa39cu, 0x026d930au, 0x9c0906a9u, 0xeb0e363fu, 0x72076785u, 0x05005713u,
		0x95bf4a82u, 0xe2b87a14u, 0x7bb12baeu, 0x0cb61b38u, 0x92d28e9bu, 0xe5d5be0du, 0x7cdcefb7u, 0x0bdbdf21u,
		0x86d3d2d4u, 0xf1d4e242u, 0x68ddb3f8u, 0x1fda836eu, 0x81be16cdu, 0xf6b9265bu, 0x6fb077e1u, 0x18b74777u,
		0x88085ae6u, 0xff0f6a70u, 0x66063bcau, 0x11010b5cu, 0x8f659effu, 0xf862ae69u, 0x616bffd3u, 0x166ccf45u,
		0xa00ae278u, 0xd70dd2eeu, 0x4e048354u, 0x3903b3c2u, 0xa7672661u, 0xd06016f7u, 0x4969474du, 0x3e6e77dbu,
		0xaed16a4au, 0xd9d65adcu, 0x40df0b66u, 0x37d83bf0u, 0xa9bcae53u, 0xdebb9ec5u, 0x47b2cf7fu, 0x30b5ffe9u,
		0xbdbdf21cu, 0xcabac28au, 0x53b39330u, 0x24b4a3a6u, 0xbad03605u, 0xcdd70693u, 0x54de5729u, 0x23d967bfu,
		0xb3667a2eu, 0xc4614ab8u, 0x5d681b02u, 0x2a6f2b94u, 0xb40bbe37u, 0xc30c8ea1u, 0x5a05df1bu, 0x2d02ef8du
	};
#endif//USE_CRC_CALC_TABLE
	//--------------------
	//�����񂩂�CRC�Z�o�p�i�ċA�����j
	CONSTEXPR crc32_t calcStr(const crc32_t crc, const char* str)
	{
	#ifndef USE_CRC_CALC_TABLE
		return *str == '\0' ? crc : calcStr(calcPoly(static_cast<crc32_t>((crc ^ *str) & 0xffu), 8) ^ (crc >> 8), str + 1);//CRC�����������v�Z�v�Z������
	#else//USE_CRC_CALC_TABLE
		return *str == '\0' ? crc : calcStr(s_calcTable[(crc ^ *str) & 0xffu] ^ (crc >> 8), str + 1);//CRC�����������v�Z�v�Z�ς݃e�[�u���̒l������
	#endif//USE_CRC_CALC_TABLE
	}
	//--------------------
	//�f�[�^�����w�肵��CRC�Z�o�p�i�ċA�����j
	CONSTEXPR crc32_t calcData(const crc32_t crc, const char* data, const std::size_t len)
	{
	#ifndef USE_CRC_CALC_TABLE
		return len == 0 ? crc : calcData(calcPoly(static_cast<crc32_t>((crc ^ *data) & 0xffu), 8) ^ (crc >> 8), data + 1, len - 1);//CRC�����������v�Z�v�Z������
	#else//USE_CRC_CALC_TABLE
		return len == 0 ? crc : calcData(s_calcTable[(crc ^ *data) & 0xffu] ^ (crc >> 8), data + 1, len - 1);//CRC�����������v�Z�v�Z�ς݃e�[�u���̒l������
	#endif//USE_CRC_CALC_TABLE
	}
}
//--------------------
//�yconstexpr�Łz�����񂩂�CRC�Z�o
CONSTEXPR crc32_t calcConstCRC32(const char* str)
{
	return ~crc_inner_calc::calcStr(~0u, str);
}
//--------------------
//�yconstexpr�Łz�f�[�^�����w�肵��CRC�Z�o
CONSTEXPR crc32_t calcConstCRC32(const char* data, const std::size_t len)
{
	return ~crc_inner_calc::calcData(~0u, data, len);
}
#ifdef ENABLE_USER_DEFINED_LITERALS
//--------------------
//�y���[�U�[��`���e�����Łz�f�[�^�����w�肵��CRC�Z�o
CONSTEXPR crc32_t operator "" _crc32(const char* str, std::size_t len)
{
	return calcConstCRC32(str, len);
}
#endif//ENABLE_USER_DEFINED_LITERALS
//--------------------
//�y�ʏ�֐��Łz�����񂩂�CRC�Z�o
crc32_t calcCRC32(const char* str)
{
	crc32_t crc = ~0u;
	const char* p = str;
	while (*p)
	{
	#ifndef USE_CRC_CALC_TABLE
		crc = crc_inner_calc::calcPoly(static_cast<crc32_t>((crc ^ *p) & 0xffu), 8) ^ (crc >> 8);//CRC�����������v�Z�v�Z������
	#else//USE_CRC_CALC_TABLE
		crc = crc_inner_calc::s_calcTable[(crc ^ *p) & 0xffu] ^ (crc >> 8);//CRC�����������v�Z�v�Z�ς݃e�[�u���̒l������
	#endif//USE_CRC_CALC_TABLE
		++p;
	}
	return ~crc;
}
//--------------------
//�y�ʏ�֐��Łz�f�[�^�����w�肵��CRC�Z�o
crc32_t calcCRC32(const char* data, const std::size_t len)
{
	crc32_t crc = ~0u;
	const char* p = data;
	for (std::size_t pos = 0; pos < len; ++pos, ++p)
	{
	#ifndef USE_CRC_CALC_TABLE
		crc = crc_inner_calc::calcPoly(static_cast<crc32_t>((crc ^ *p) & 0xffu), 8) ^ (crc >> 8);//CRC�����������v�Z�v�Z������
	#else//USE_CRC_CALC_TABLE
		crc = crc_inner_calc::s_calcTable[(crc ^ *p) & 0xffu] ^ (crc >> 8);//CRC�����������v�Z�v�Z�ς݃e�[�u���̒l������
	#endif//USE_CRC_CALC_TABLE
	}
	return ~crc;
}

//--------------------
//�W�����C�u�����𗘗p�����Œ�o�b�t�@�n�b�V���e�[�u���N���X
#include <string.h>//strcpy�p
#include <unordered_map>//C++11�n�b�V���e�[�u��
class CTest8
{
public:
	//�^
	//�f�[�^�^
	struct DATA
	{
		char m_name[20];//���O
		int m_age;//�N��
		//�R���X�g���N�^
		DATA(const char* name, const int age)
		{
		#ifdef USE_STRCPY_S
			strcpy_s(m_name, sizeof(m_name), name);
		#else//USE_STRCPY_S
			strcpy(m_name, name);
		#endif//USE_STRCPY_S
			m_age = age;
		}
	};
public:
	//���\�b�h
	//�f�[�^�ǉ�
	void addData(const DATA& data)
	{
		printf("CTest8::addData()\n");
		CTempPolyStackAllocator poly_allocator(m_stack);//���ԃA���P�[�^���N���X���X�^�b�N�ɕύX
		m_table->emplace(calcCRC32(data.m_name), data);//�R���e�i���ɗv�f���\�z
		//m_table->insert(std::make_pair(calcCRC32(data.m_name), data));//insert���g�p����ꍇ
	}
	//�f�[�^�Q��
	const DATA* find(const crc32_t name_crc) const
	{
		printf("CTest8::find()\n");
		const auto& obj = m_table->find(name_crc);//�L�[�iCRC�j�Ńe�[�u������
		if (obj == m_table->cend())//������Ȃ��������H
			return nullptr;
		return &obj->second;//�f�[�^����Ԃ�
	}
	const DATA* find(const char* name) const
	{
		return find(calcCRC32(name));
	}
public:
	//�R���X�g���N�^
	CTest8()
	{
		printf("CTest8::Consructor()\n");
		CTempPolyStackAllocator poly_allocator(m_stack);//���ԃA���P�[�^���N���X���X�^�b�N�ɕύX
		printf("new unordered_map\n");
		m_table = new std::unordered_map<crc32_t, DATA>();//�n�b�V���e�[�u������
		printf("unordered_map::reserve\n");
		m_table->reserve(10);//���炩���߃e�[�u������\��i�����ł��������������悭���邽�߁j
		printf("--\n");
	}
	//�f�X�g���N�^
	~CTest8()
	{
		printf("CTest8::Destructor()\n");
		CTempPolyStackAllocator poly_allocator(m_stack);//���ԃA���P�[�^���N���X���X�^�b�N�ɕύX
		printf("delete unordered_map\n");
		delete m_table;//�n�b�V���e�[�u����j��
		printf("--\n");
	}
private:
	//�t�B�[���h
	std::unordered_map<crc32_t, DATA>* m_table;//�n�b�V���e�[�u��
	CStackAllocatorWithBuff<1024> m_stack;//�N���X���X�^�b�N
};

//--------------------
//�풓�f�[�^�i�z��j
CStackAllocatorWithBuff<1024> s_parmaDataBuff;//�풓�f�[�^�p�o�b�t�@
static char* s_message1 = nullptr;//�풓���b�Z�[�W1
static char* s_message2 = nullptr;//�풓���b�Z�[�W2

//--------------------
//���[�N�o�b�t�@
CStackAllocatorWithBuff<4096> s_tempStack;//�ꎞ�X�^�b�N�A���P�[�^

//--------------------
//�e�X�g
#include <string.h>//strcpy�p
#include <string>//std::string�p
void test8a()
{
	printf("---------- test8a:�W�����C�u������֗��ɗ��p ----------\n");
	//�ꎞ�X�^�b�N�A���P�[�^�g�p
	{
		printf("----------�ꎞ�X�^�b�N�A���P�[�^�ŕ����񑀍�\n");
		CTempPolyStackAllocator poly_allocator(s_tempStack, CIStackAllocAdp::AUTO_REWIND);
		{
			std::string str1 = "�������";
			std::string str2 = "�������";
			std::string str3 = "��������悤�ȏ����ł́A";
			std::string str4 = "std::string��";
			std::string str5 = "����ς�֗�!";
			std::string str = str1 + str2 + str3 + str4 + str5;
			str += "\n" "�������A�f����strcat()���g������������";
			str += "\n" "std::string �́Afind(), replace(), substr() �Ȃǂ��g���������ɕ֗�";
			str += "\n" "�܂��A�u�������̂��߂Ɉꎞ�o�b�t�@�ŃT�C�Y�����ς����ăR�s�[�v�̂悤�ȏ����ɂ�\n���ʓI";
			str = "�y�ꎞ�X�^�b�N�A���P�[�^�Łz\n" + str;
			printf("strpcy()\n");
			const std::size_t size = str.length() + 1;
			s_message1 = static_cast<char*>(s_parmaDataBuff.allocN(size, 1));
		#ifdef USE_STRCPY_S
			strcpy_s(s_message1, size, str.c_str());
		#else//USE_STRCPY_S
			strcpy(s_message1, str.c_str());
		#endif//USE_STRCPY_S
		}
	}
	//�W���A���P�[�^�imalloc / free�j�g�p
	{
		printf("----------�W���A���P�[�^�ŕ����񑀍�\n");
		{
			std::string str1 = "�������";
			std::string str2 = "�������";
			std::string str3 = "��������悤�ȏ����ł́A";
			std::string str4 = "std::string��";
			std::string str5 = "����ς�֗�!";
			std::string str = str1 + str2 + str3 + str4 + str5;
			str += "\n" "�������A�f����strcat()���g������������";
			str += "\n" "std::string �́Afind(), replace(), substr() �Ȃǂ��g���������ɕ֗�";
			str += "\n" "�܂��A�u�������̂��߂Ɉꎞ�o�b�t�@�ŃT�C�Y�����ς����ăR�s�[�v�̂悤�ȏ����ɂ�\n���ʓI";
			str = "�y�W���A���P�[�^�Łz\n" + str;
			printf("strpcy()\n");
			const std::size_t size = str.length() + 1;
			s_message2 = static_cast<char*>(s_parmaDataBuff.allocN(size, 1));
		#ifdef USE_STRCPY_S
			strcpy_s(s_message2, size, str.c_str());
		#else//USE_STRCPY_S
			strcpy(s_message2, str.c_str());
		#endif//USE_STRCPY_S
		}
	}
	{
		printf("----------�����񑀍�̌��ʕ\��\n");
		printf("s_message1=\"%s\"\n", s_message1);
		printf("-----\n");
		printf("s_message2=\"%s\"\n", s_message2);
		printf("-----\n");
		printf("s_parmaDataBuff=%d/%d/%d\n", s_parmaDataBuff.getTotal(), s_parmaDataBuff.getUsed(), s_parmaDataBuff.getRemain());
		printf("s_tempStack=%d/%d/%d\n", s_tempStack.getTotal(), s_tempStack.getUsed(), s_tempStack.getRemain());
	}
}

//--------------------
//�e�X�g
void test8b()
{
	printf("---------- test8b:�W�����C�u������֗��ɗ��p ----------\n");
	//�W�����C�u�����̃N���X�������N���X�̃e�X�g
	{
		printf("----------�W�����C�u�����̃N���X�������N���X�𑀍�\n");
		CTempPolyStackAllocator poly_allocator(s_tempStack, CIStackAllocAdp::AUTO_REWIND);//�ꎞ�X�^�b�N�A���P�[�^
		{
			//�e�[�u���o�^�p�̃f�[�^������
			CTest8::DATA data1("���Y", 40);
			CTest8::DATA data2("���Y", 30);
			CTest8::DATA data3("�O�Y", 20);
			
			//�N���X�̃C���X�^���X�𐶐��i�ꎞ�X�^�b�N�A���P�[�^�ɍ쐬�j
			printf("new CTest8\n");
			CTest8* table = new CTest8();
			
			//�e�[�u���Ƀf�[�^��o�^
			table->addData(data1);
			table->addData(data2);
			table->addData(data3);

			//�e�[�u������f�[�^���Q��
			const CTest8::DATA* ref1 = table->find("���Y");
			const CTest8::DATA* ref2 = table->find("���Y");
			const CTest8::DATA* ref3 = table->find("�O�Y");
			const CTest8::DATA* ref4 = table->find("�l�N");
			if (ref1) printf("ref1: name=\"%s\", age=%d\n", ref1->m_name, ref1->m_age);
			if (ref2) printf("ref2: name=\"%s\", age=%d\n", ref2->m_name, ref2->m_age);
			if (ref3) printf("ref3: name=\"%s\", age=%d\n", ref3->m_name, ref3->m_age);
			if (ref4) printf("ref4: name=\"%s\", age=%d\n", ref4->m_name, ref4->m_age);

			//�C���X�^���X�j��
			printf("delete CTest8\n");
			delete table;
		}
	}
}

//--------------------------------------------------------------------------------
//�}���`�X���b�h�ŕ֗��ȃX�^�b�N�A���P�[�^

#include <thread>//C++11�X���b�h
#include <atomic>//C++11�A�g�~�b�N�^

//----------------------------------------
//�X���b�hID�N���X
//��ID���n�b�V���������ꍇ�ATLS�����p���č�����

//�X���b�hID�^
#define THREAD_ID_IS_HASH//�X���b�hID���n�b�V���^�ň����ꍇ�͂��̃}�N����L��������i�n�b�V���̕��������j
#ifdef THREAD_ID_IS_HASH
typedef std::size_t THREAD_ID;//(�n�b�V��)
static const THREAD_ID INVALID_THREAD_ID = std::hash<std::thread::id>()(std::thread::id());//�����ȃX���b�hID(�n�b�V��)
static const THREAD_ID INITIAL_THREAD_ID = static_cast<THREAD_ID>(~0);//�����X���b�hID(�n�b�V��)
#else//THREAD_ID_IS_HASH
typedef std::thread::id THREAD_ID;
static const THREAD_ID INVALID_THREAD_ID = std::thread::id();//�����ȃX���b�hID
#endif//THREAD_ID_IS_HASH

//���݂̃X���b�hID�擾�֐�
#ifdef THREAD_ID_IS_HASH
inline THREAD_ID GetThisThreadID(){ return std::hash<std::thread::id>()(std::this_thread::get_id()); }//(�n�b�V��)
#else//THREAD_ID_IS_HASH
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id(); }
#endif//THREAD_ID_IS_HASH

//�X���b�hID�N���X
class CThreadID
{
public:
	//�A�N�Z�b�T
	const THREAD_ID getID() const { return m_threadId; }//�X���b�hID���擾
	const char* getName() const { return m_threadName; }//�X���b�h�����擾
public:
	//�A�N�Z�b�T�istatic�j
#ifdef THREAD_ID_IS_HASH
	static THREAD_ID getThisID(){ return m_thisThreadID; }//���݂̃X���b�h�̃X���b�hID���擾(�n�b�V��)
#else//THREAD_ID_IS_HASH
	static THREAD_ID getThisID(){ return GetThisThreadID(); }//���݂̃X���b�h�̃X���b�hID���擾
#endif//THREAD_ID_IS_HASH
	static const char* getThisName(){ return m_thisThreadName; }//���݂̃X���b�h�̃X���b�h�����擾
public:
	//���\�b�h
	bool isThisThread() const { return m_threadId == getThisID(); }//���݂̃X���b�h�Ɠ����X���b�h������
private:
	//���\�b�h(static)
	static void setThisThread()//���݂̃X���b�h�̃X���b�hID���Z�b�g
	{
	#ifdef THREAD_ID_IS_HASH
		if (m_thisThreadID == INITIAL_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
	#endif//THREAD_ID_IS_HASH
	}
	static void resetThisThread(const char* name)//���݂̃X���b�h�̃X���b�hID�����Z�b�g
	{
	#ifdef THREAD_ID_IS_HASH
		m_thisThreadID = GetThisThreadID();
	#endif//THREAD_ID_IS_HASH
		m_thisThreadName = name;
	}
public:
	//�I�y���[�^�i���j
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID��v����
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID�s��v����
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID��v����
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID�s��v����
	CThreadID& operator=(const CThreadID& o)//�R�s�[���Z�q
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
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
	//�f�t�H���g�R���X�g���N�^
	//������TLS�ɋL�^�ς݂̃X���b�hID�i�Ɩ��O�j���擾
	CThreadID()
	{
		setThisThread();
		m_threadId = getThisID();
		m_threadName = getThisName();
	}
private:
	//�t�B�[���h
	THREAD_ID m_threadId;//�X���b�hID�i�I�u�W�F�N�g�ɕۑ�����l�j
	const char* m_threadName;//�X���b�h���i�I�u�W�F�N�g�ɕۑ�����l�j
#ifdef THREAD_ID_IS_HASH
	static thread_local THREAD_ID m_thisThreadID;//���݂̃X���b�h�̃X���b�hID(TLS)
#endif//THREAD_ID_IS_HASH
	static thread_local const char* m_thisThreadName;//���݂̃X���b�h��(TLS)
};
//static�ϐ��̃C���X�^���X��
#ifdef THREAD_ID_IS_HASH
thread_local THREAD_ID CThreadID::m_thisThreadID = INITIAL_THREAD_ID;//�X���b�hID(TLS)
#endif//THREAD_ID_IS_HASH
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

//--------------------
//�X�}�[�g�X�^�b�N�A���P�[�^�N���X
//����X���b�h�Z�[�t�i�������x�D��j
//���C���^�[�t�F�[�X���������邪�A�������̂��߂� virtual���\�b�h�ɗ��炸����\
class CSmartStackAllocator : public IStackAllocator
{
public:
	//�^
	typedef int counter_t;//�J�E���^�^
public:
	//�A�N�Z�b�T
	std::size_t getTotal() const override { return m_buffSize; }//�S�̂̃������ʂ��擾
	std::size_t getUsed() const override { return m_usedN.load() + m_buffSize - m_usedR.load(); }//�g�p���̃������ʂ��擾
	std::size_t getRemain() const override { return m_usedR.load() - m_usedN.load(); }//�c��̃������ʂ��擾
	E_ORDERED getDefaultOrdered() const { return m_defaultOrdered.load(); }//�f�t�H���g�̃X�^�b�N�����擾
	void setDefaultOrdered(const E_ORDERED ordered)//�f�t�H���g�̃X�^�b�N�����X�V
	{
		//m_lock.lock();//���b�N�擾�i�s�v�ˑ���ɃA�g�~�b�N�^���g�p�j
		m_defaultOrdered.store(ordered == REVERSE ? REVERSE : NORMAL);
		//m_lock.unlock();//���b�N����i�s�v�j
	}
	const byte* getBuff() const { return m_buffPtr; }//�o�b�t�@�擾���擾
	const byte* getNowPtrN() const { return m_buffPtr + m_usedN.load(); }//���݂̃o�b�t�@�ʒu�i�����j���擾
	const byte* getNowPtrR() const { return m_buffPtr + m_usedR.load(); }//���݂̃o�b�t�@�ʒu�i�t���j���擾
	const byte* getNowPtrD() const { return getNowPtr(m_defaultOrdered.load()); }//���݂̃o�b�t�@�ʒu���擾
	const byte* getNowPtr(const E_ORDERED ordered) const { return ordered == DEFAULT ? getNowPtrD() : ordered == REVERSE ? getNowPtrR() : getNowPtrN(); }//���݂̃o�b�t�@�ʒu���擾
	const byte* getNowPtr() const override { return getNowPtrD(); }//���݂̃o�b�t�@�ʒu���擾
	marker_t getMarkerN() const { return m_usedN.load(); }//���݂̃}�[�J�[�i�����j���擾
	marker_t getMarkerR() const { return m_usedR.load(); }//���݂̃}�[�J�[�i�t���j���擾
	marker_t getMarkerD() const { return getMarker(m_defaultOrdered.load()); }//���݂̃}�[�J�[���擾
	marker_t getMarker(const E_ORDERED ordered) const { return ordered == DEFAULT ? getMarkerD() : ordered == REVERSE ? getMarkerR() : getMarkerN(); }//���݂̃}�[�J�[���擾
	marker_t getMarker() const override { return getMarkerD(); }//���݂̃}�[�J�[���擾
	marker_t getBeginN() const { return m_beginN.load(); }//�J�n�}�[�J�[�i�����j���擾
	marker_t getBeginR() const { return m_beginR.load(); }//�J�n�}�[�J�[�i�t���j���擾
	marker_t getBeginD() const { return getBegin(m_defaultOrdered.load()); }//�J�n�}�[�J�[���擾
	marker_t getBegin(const E_ORDERED ordered) const { return ordered == DEFAULT ? getBeginD() : ordered == REVERSE ? getBeginR() : getBeginN(); }//�J�n�}�[�J�[���擾
	marker_t getBegin() const { return getBeginD(); }//�J�n�}�[�J�[���擾
	marker_t getCounterN() const { return m_counterN.load(); }//�������m�ۃJ�E���^�i�����j���擾
	marker_t getCounterR() const { return m_counterR.load(); }//�������m�ۃJ�E���^�i�t���j���擾
	marker_t getCounterD() const { return getCounter(m_defaultOrdered.load()); }//�������m�ۃJ�E���^���擾
	marker_t getCounter(const E_ORDERED ordered) const { return ordered == DEFAULT ? getCounterD() : ordered == REVERSE ? getCounterR() : getCounterN(); }//�������m�ۃJ�E���^���擾
	marker_t getCounter() const { return getCounterD(); }//�������m�ۃJ�E���^���擾
public:
	//���\�b�h
	//�������m�ہi�����j
	void* allocN(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		//�������̂��߂ɁA��x���b�N�͈̔͊O�ŒP���󂫗̈攻��
		if (m_usedN.load() + size > m_usedR.load())
			return nullptr;
		m_lock.lock();//���b�N�擾
		m_counterN.fetch_add(1);
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedN.load();//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t align_diff = align > 0 ? now_ptr % align == 0 ? 0 : align - now_ptr % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_usedN.load() + align_diff + size;//���̃}�[�J�[�Z�o
		if (next_used > m_usedR.load())//�������I�[�o�[�`�F�b�N�i�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK�j
		{
			printf("normal-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR.load() - m_usedN.load());
			m_lock.unlock();//���b�N���
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr + align_diff;//�������m�ۃA�h���X�Z�o
		m_usedN.store(next_used);//�}�[�J�[�X�V
		m_lock.unlock();//���b�N���
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m�ہi�t���j
	void* allocR(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		//�������̂��߂ɁA��x���b�N�͈̔͊O�ŒP���󂫗̈攻��
		if (m_usedN.load() > m_usedR.load() - size)
			return nullptr;
		m_lock.lock();//���b�N�擾
		m_counterR.fetch_add(1);
		const uintptr_t now_ptr = reinterpret_cast<uintptr_t>(m_buffPtr)+m_usedR.load();//���݂̃|�C���^�ʒu�Z�o
		const uintptr_t alloc_ptr_tmp = now_ptr - size;//�������m�ۃA�h���X�Z�o�i�b��j
		const uintptr_t align_diff = align > 0 ? alloc_ptr_tmp % align == 0 ? 0 : alloc_ptr_tmp % align : 0;//�A���C�������g�v�Z
		const marker_t next_used = m_usedR.load() - size - align_diff;//���̃}�[�J�[�Z�o
		if (next_used < m_usedN.load() || next_used > m_buffSize)//�������I�[�o�[�`�F�b�N�i�I�[�o�[�t���[���Ēl���傫���Ȃ�\�����`�F�b�N�j
		{
			printf("reversed-stack overflow!(size=%d+align=%d, remain=%d)\n", size, align_diff, m_usedR.load() - m_usedN.load());
			m_lock.unlock();//���b�N���
			return nullptr;
		}
		const uintptr_t alloc_ptr = now_ptr - size - align_diff;//�������m�ۃA�h���X�Z�o
		m_usedR.store(next_used);//�}�[�J�[�X�V
		m_lock.unlock();//���b�N���
		return reinterpret_cast<void*>(alloc_ptr);
	}
	//�������m��
	void* allocD(const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return alloc(m_defaultOrdered.load(), size, align);
	}
	//�������m��
	void* alloc(const E_ORDERED ordered, const std::size_t size, const std::size_t align = DEFAULT_ALIGN)
	{
		return ordered == DEFAULT ? allocD(size, align) : ordered == REVERSE ? allocR(size, align) : allocN(size, align);
	}
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN) override
	{
		return allocD(size, align);
	}
private:
	//�������j���i�����j
	void freeN(void* p)
	{
		//�|�C���^�͈̔̓`�F�b�N
		//���������̂��߂ɁA��x���b�N�͈̔͊O�Ń`�F�b�N
		//�@�i���freeN�֐���freeD����g�ŌĂяo����邽�߁j
		if (m_counterN.load() <= 0)
			return;
		const marker_t now_n = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		if (now_n < m_beginN.load() || now_n > m_usedN.load())
			return;
		//�|�C���^�������X�^�b�N�Ƃ��ēK���̂��߁A�����J�n
		m_lock.lock();//���b�N�擾
		if (m_counterN.load() <= 0 || now_n < m_beginN.load() || now_n > m_usedN.load())//�͈͂̍ă`�F�b�N
		{
			m_lock.unlock();//���b�N���
			return;
		}
		m_counterN.fetch_sub(1);
		if (m_counterN.load() == 0)
			m_usedN.store(m_beginN.load());
		m_lock.unlock();//���b�N���
	}
	//�������j���i�t���j
	void freeR(void* p)
	{
		//�|�C���^�͈̔̓`�F�b�N
		//���������̂��߂ɁA��x���b�N�͈̔͊O�Ń`�F�b�N
		//�@�i���freeN�֐���freeD����g�ŌĂяo����邽�߁j
		if (m_counterR.load() <= 0)
			return;
		const marker_t now_r = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		if (now_r >= m_beginR.load() || now_r < m_usedR.load())
			return;
		//�|�C���^���t���X�^�b�N�Ƃ��ēK���̂��߁A�����J�n
		m_lock.lock();//���b�N�擾
		if (m_counterR.load() <= 0 || now_r >= m_beginR.load() || now_r < m_usedR.load())//�͈͂̍ă`�F�b�N
		{
			m_lock.unlock();//���b�N���
			return;
		}
		m_counterR.fetch_sub(1);
		if (m_counterR.load() == 0)
			m_usedR.store(m_beginR.load());
		m_lock.unlock();//���b�N���
	}
public:
	//�������j��
	void free(void* p)
	{
		//�|�C���^���`�F�b�N���ď�������̂Ő����Ƌt���̗����̏������܂Ƃ߂Ď��s����
		freeN(p);//����
		freeR(p);//�t��
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n�i�����j
	//���������m�ۃJ�E���^�����Z�b�g
	void beginN()
	{
		m_lock.lock();//���b�N�擾
		m_beginN.store(m_usedN.load());
		m_counterN.store(0);
		m_lock.unlock();//���b�N���
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n�i�t���j
	//���������m�ۃJ�E���^�����Z�b�g
	void beginR()
	{
		m_lock.lock();//���b�N�擾
		m_beginR.store(m_usedR.load());
		m_counterR.store(0);
		m_lock.unlock();//���b�N���
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n 
	//���������m�ۃJ�E���^�����Z�b�g
	void beginD()
	{
		begin(m_defaultOrdered.load());
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n 
	//���������m�ۃJ�E���^�����Z�b�g
	void begin(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? beginD() : ordered == REVERSE ? beginR() : beginN();
	}
	//�}�[�J�[�ʒu���L�����ă������m�ۂ̃J�E���g���J�n 
	//���������m�ۃJ�E���^�����Z�b�g
	void begin()
	{
		beginD();
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void backN(const marker_t marker_n)
	{
		m_lock.lock();//���b�N�擾
		if (marker_n > m_usedR.load())//�����Ȃ��Ȃ̂ŁA�͈̓`�F�b�N�͑唻��݂̂�OK
		{
			m_lock.unlock();//���b�N���
			return;
		}
		m_usedN.store(marker_n);
		m_beginN.store(marker_n);
		m_counterN.store(0);
		m_lock.unlock();//���b�N���
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂��i�����j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void backN(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backN(marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void backR(const marker_t marker_r)
	{
		m_lock.lock();//���b�N�擾
		if (marker_r < m_usedN.load() || marker_r > m_buffSize)//�������I�[�o�[�`�F�b�N
		{
			return;
			m_lock.unlock();//���b�N���
		}
		m_usedR.store(marker_r);
		m_beginR.store(marker_r);
		m_counterR.store(0);
		m_lock.unlock();//���b�N���
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂��i�t���j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void backR(const void* p)
	{
		const marker_t marker = reinterpret_cast<uintptr_t>(p)-reinterpret_cast<uintptr_t>(m_buffPtr);
		backR(marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void backD(const marker_t marker)
	{
		back(m_defaultOrdered.load(), marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void backD(const void* p)
	{
		back(m_defaultOrdered.load(), p);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void back(const E_ORDERED ordered, const marker_t marker)
	{
		ordered == DEFAULT ? backD(marker) : ordered == REVERSE ? backR(marker) : backN(marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void back(const E_ORDERED ordered, const void* p)
	{
		ordered == DEFAULT ? backD(p) : ordered == REVERSE ? backR(p) : backN(p);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���}�[�J�[�w���
	void back(const marker_t marker) override
	{
		backD(marker);
	}
	//�y���̃N���X�ł͔񐄏����\�b�h�z
	//���������ȑO�̃}�[�J�[�ɖ߂�
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	//���|�C���^�w���
	void back(const void* p) override
	{
		backD(p);
	}
	//�������j���i�����j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearN()
	{
		m_lock.lock();//���b�N�擾
		m_usedN.store(0);
		m_beginN.store(0);
		m_counterN.store(0);
		m_lock.unlock();//���b�N���
	}
	//�������j���i�t���j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearR()
	{
		m_lock.lock();//���b�N�擾
		m_usedR.store(m_buffSize);
		m_beginR.store(0);
		m_counterR.store(0);
		m_lock.unlock();//���b�N���
	}
	//�������j��
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearD()
	{
		clear(m_defaultOrdered.load());
	}
	//�������j���i�����j
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearNR()
	{
		clearN();
		clearR();
	}
	//�������j��
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clear(const E_ORDERED ordered)
	{
		ordered == DEFAULT ? clearD() : ordered == REVERSE ? clearR() : clearN();
	}
	//�������j��
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clear() override
	{
		clearD();
	}
	//�������j���i�S�āj
	//���J�n�}�[�J�[�ƃ������m�ۃJ�E���^�����Z�b�g����
	void clearAll() override
	{
		clearNR();
	}
public:
	//�R���X�g���N�^
	CSmartStackAllocator(void* buff_p, const std::size_t buff_size, const E_ORDERED default_ordered = NORMAL) :
		m_buffPtr(reinterpret_cast<byte*>(buff_p)),//�o�b�t�@�擪�A�h���X
		m_buffSize(buff_size)//�o�b�t�@�T�C�Y
	{
		m_usedN.store(0);//�}�[�J�[�i�����j
		m_usedR.store(buff_size);//�}�[�J�[�i�t���j
		m_beginN.store(0);//�J�n�}�[�J�[�i�����j���J�E���g���J�n�����ʒu�i�����J���ł��̈ʒu�ɖ߂��j
		m_beginR.store(buff_size);//�J�n�}�[�J�[�i�t���j���J�E���g���J�n�����ʒu�i�����J���ł��̈ʒu�ɖ߂��j
		m_counterN.store(0);//�������m�ۃJ�E���^�i�����j
		m_counterR.store(0);//�������m�ۃJ�E���^�i�t���j
		setDefaultOrdered(default_ordered);//�f�t�H���g�̃X�^�b�N��
	}
	//�f�X�g���N�^
	~CSmartStackAllocator() override
	{}
private:
	//�t�B�[���h
	byte* m_buffPtr;//�o�b�t�@�擪�A�h���X
	const std::size_t m_buffSize;//�o�b�t�@�T�C�Y
	std::atomic<marker_t> m_usedN;//�}�[�J�[�i�����j
	std::atomic<marker_t> m_usedR;//�}�[�J�[�i�t���j
	std::atomic<marker_t> m_beginN;//�J�n�}�[�J�[�i�����j���J�E���g���J�n�����ʒu�i�����J���ł��̈ʒu�ɖ߂��j
	std::atomic<marker_t> m_beginR;//�J�n�}�[�J�[�i�t���j���J�E���g���J�n�����ʒu�i�����J���ł��̈ʒu�ɖ߂��j
	std::atomic<counter_t> m_counterN;//�������m�ۃJ�E���^�i�����j
	std::atomic<counter_t> m_counterR;//�������m�ۃJ�E���^�i�t���j
	std::atomic<E_ORDERED> m_defaultOrdered;//�f�t�H���g�̃X�^�b�N��
	CSpinLock m_lock;//���b�N
};

#if 0//�g��Ȃ�
//--------------------
//�z�unew/�z�udelete
//���������g�p�󋵂��m�F���邽�߂Ƀ}�[�J�[��\��
//�z�unew
void* operator new(const std::size_t size, CSmartStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, smart_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new(const std::size_t size, CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, smart_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//�z���
void* operator new[](const std::size_t size, CSmartStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	printf("placement new(size=%d, smart_allocator.marker=%d,%d, align=%d, ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
void* operator new[](const std::size_t size, CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement new(size=%d, smart_allocator.marker=%d,%d, (align=%d), ordered=%d)\n", size, allocator.getMarkerN(), allocator.getMarkerR(), align, ordered);
	return allocator.alloc(ordered, size, align);
}
//�z�udelete
void operator delete(void* p, CSmartStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, smart_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	allocator.free(p);
}
void operator delete(void* p, CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED) throw()
{
	printf("placement delete(p=0x%p, smart_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	allocator.free(p);
}
//�z���
void operator delete[](void* p, CSmartStackAllocator& allocator, const std::size_t align, const IStackAllocator::E_ORDERED ordered) throw()
{
	printf("placement delete[](p=0x%p, smart_allocator.marker=%d,%d, align)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	allocator.free(p);
}
void operator delete[](void* p, CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered) throw()
{
	const std::size_t align = IStackAllocator::DEFAULT_ALIGN;
	printf("placement delete[](p=0x%p, smart_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	allocator.free(p);
}
//�f�X�g���N�^�Ăяo���t��delete
template<class T>
void delete_ptr(T*& p, CSmartStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, smart_allocator.marker=%d,%d)\n", p, allocator.getMarkerN(), allocator.getMarkerR());
	if (!p)
		return;
	p->~T();//�f�X�g���N�^�Ăяo��
	operator delete(p, allocator, IStackAllocator::DEFAULT);
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
//�z���
template<class T>
void delete_ptr(T*& p, const std::size_t array_num, CSmartStackAllocator& allocator)
{
	printf("delete_ptr(p=0x%p, array_num=%d, smart_allocator.marker=%d,%d)\n", p, array_num, allocator.getMarkerN(), allocator.getMarkerR());
	if (!p)
		return;
	for (std::size_t i = 0; i < array_num; ++i)
		p->~T();//�f�X�g���N�^�Ăяo��
	operator delete[](p, allocator, IStackAllocator::DEFAULT);
	p = nullptr;//���S�̂��߂Ƀ|�C���^��������
}
#endif

//--------------------
//�o�b�t�@�t���X�}�[�g�X�^�b�N�A���P�[�^�e���v���[�g�N���X
//���ÓI�o�b�t�@���g�p��������΁A�Œ�o�b�t�@�V���O���g��������
template<std::size_t SIZE>
class CSmartStackAllocatorWithBuff : public CSmartStackAllocator
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = SIZE;//�o�b�t�@�T�C�Y
public:
	//�R���X�g���N�^
	CSmartStackAllocatorWithBuff(const E_ORDERED default_ordered = NORMAL) :
		CSmartStackAllocator(m_buff, BUFF_SIZE, default_ordered)
	{}
	//�f�X�g���N�^
	~CSmartStackAllocatorWithBuff() override
	{}
private:
	//�t�B�[���h
	byte m_buff[BUFF_SIZE];//�o�b�t�@
};

//--------------------
//�X�}�[�g�X�^�b�N�A���P�[�^�A�_�v�^�[�N���X
class CSmartStackAllocAdp : public CIStackAllocAdp
{
public:
	//�^
	typedef CSmartStackAllocator ALLOCATOR_TYPE;//�A���P�[�^�^
public:
	//�A�N�Z�b�T
	const char* getName() const override{ return "CSmartStackAllocAdp"; }//�A���P�[�^���擾
	CSmartStackAllocator& getAllocator(){ return *static_cast<CSmartStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	const CSmartStackAllocator& getAllocator() const { return *static_cast<CSmartStackAllocator*>(&m_allocator); }//�A���P�[�^�擾
	IStackAllocator::E_ORDERED getOrdered() const { return m_ordered; }//�X�^�b�N���擾
	void setOrdered(const IStackAllocator::E_ORDERED ordered){ m_ordered = ordered; }//�X�^�b�N���X�V
public:
	//���\�b�h
	//�������m��
	void* alloc(const std::size_t size, const std::size_t align = DEFAULT_ALIGN, const ALLOC_INFO* info = nullptr) override
	{
		CSmartStackAllocator& allocator = getAllocator();
		return allocator.alloc(m_ordered, size, align);//��virtual�����o�[���g��
	}
	//���������
	void free(void* p) override
	{
		CSmartStackAllocator& allocator = getAllocator();
		return allocator.free(p);
	}
public:
	//�f�t�H���g�R���X�g���N�^
	CSmartStackAllocAdp() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	//�����������߂��ɂ͑Ή����Ȃ�
	CSmartStackAllocAdp(CSmartStackAllocator& stack, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) :
		CIStackAllocAdp(stack, NOREWIND),//�X�}�[�g�X�^�b�N�A���P�[�^
		m_ordered(ordered)//�X�^�b�N��
	{}
	//�f�X�g���N�^
	~CSmartStackAllocAdp() override
	{}
private:
	//�t�B�[���h
	IStackAllocator::E_ORDERED m_ordered;//�X�^�b�N��
};

//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�X�}�[�g�X�^�b�N�A���P�[�^�p
class CTempPolySmartStackAllocator : public CTempPolyAllocatorWithStackAdp<CSmartStackAllocAdp>
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTempPolySmartStackAllocator() = delete;//�R���X�g���N�^�����K�{
	//�R���X�g���N�^
	CTempPolySmartStackAllocator(CSmartStackAllocator& allocator, const IStackAllocator::E_ORDERED ordered = IStackAllocator::DEFAULT) :
		CTempPolyAllocatorWithStackAdp<CSmartStackAllocAdp>(allocator, ordered)
	{}
	//�f�X�g���N�^
	~CTempPolySmartStackAllocator()
	{}
};

//--------------------
//�e�X�g�p�N���X
//__declspec(align(8))//8�o�C�g�A���C�������g�Ńe�X�g����ꍇ�͂��̍s��L���ɂ���
class CTest9
{
public:
	//�f�t�H���g�R���X�g���N�^
	CTest9() :
		CTest9("(default)")//���̃R���X�g���N�^�Ăяo���iC++11�Œǉ����ꂽ�d�l�j
		//m_name("(default)")//C++11���g���Ȃ��ꍇ�͕��ʂɏ�����
	{
		printf("CTest9::DefaultConstructor : name=\"%s\"\n", m_name);
	}
	//�R���X�g���N�^
	CTest9(const char* name) :
		m_name(name)
	{
		printf("CTest9::Constructor : name=\"%s\"\n", m_name);
	}
	//�f�X�g���N�^
	virtual ~CTest9()
	{
		printf("CTest9::Destructor : name=\"%s\"\n", m_name);
	}
protected:
	//�t�B�[���h
	const char* m_name;//���O
	int m_dummy;//�_�~�[
};

//--------------------
//�X���b�h�e�X�g
#include <thread>//C++11�X���b�h
#include <chrono>//C++11����
//�X�}�[�g�X�^�b�N�A���P�[�^
static CSmartStackAllocatorWithBuff<1024> s_stackForThread;
void test9thread_n(const char* name)
{
	CTempPolySmartStackAllocator poly_allocator(s_stackForThread, DSA_NORMAL);//���ԃA���P�[�^���X�}�[�g�X�^�b�N�i�����j�ɐݒ�
	CTest9* obj_p = new CTest9(name);
	std::this_thread::sleep_for(std::chrono::seconds(1));//1�b�X���[�v
	delete obj_p;
}
void test9thread_r(const char* name)
{
	CTempPolySmartStackAllocator poly_allocator(s_stackForThread, DSA_REVERSE);//���ԃA���P�[�^���X�}�[�g�X�^�b�N�i�t���j�ɐݒ�
	CTest9* obj_p = new CTest9(name);
	std::this_thread::sleep_for(std::chrono::seconds(1));//1�b�X���[�v
	delete obj_p;
}
//--------------------
//�e�X�g
void test9()
{
	printf("---------- test9:�}���`�X���b�h�ɕ֗��ȃX�}�[�g�X�^�b�N�A���P�[�^ ----------\n");
	{
		printf("----------��{����`�F�b�N\n");
		CSmartStackAllocatorWithBuff<128> allocator;
		CTempPolySmartStackAllocator poly_allocator(allocator);
		CTest9* obj1_p = new CTest9("�e�X�g9-1");
		printf("obj1_p=0x%p\n", obj1_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		printf("beginN()\n");
		allocator.beginN();
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_REVERSE);
		CTest9* obj2_p = new CTest9("�e�X�g9-2");
		printf("obj2_p=0x%p\n", obj2_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		printf("beginR()\n");
		allocator.beginR();
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_NORMAL);
		CTest9* obj3_p = new CTest9("�e�X�g9-3");
		printf("obj3_p=0x%p\n", obj3_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_REVERSE);
		CTest9* obj4_p = new CTest9("�e�X�g9-4");
		printf("obj4_p=0x%p\n", obj4_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj1_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj2_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj3_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj4_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_NORMAL);
		CTest9* obj5_p = new CTest9("�e�X�g9-5");
		printf("obj5_p=0x%p\n", obj5_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		allocator.setDefaultOrdered(DSA_REVERSE);
		CTest9* obj6_p = new CTest9("�e�X�g9-6");
		printf("obj6_p=0x%p\n", obj6_p);
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj5_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		delete obj6_p;
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		printf("clearN()\n");
		allocator.clearN();
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
		printf("clearR()\n");
		allocator.clearR();
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", allocator.getMarkerN(), allocator.getMarkerR(), allocator.getBeginN(), allocator.getBeginR(), allocator.getCounterN(), allocator.getCounterR());
	}
	{
		printf("----------�X���b�h�e�X�g\n");
		//�y�z��z�X���b�h�J�n�O�ɁA�����o�b�t�@�𑼂̗p�r�ɏ����g��
		//�@�@�@�@�i����͏풓����f�[�^�Ŕj�����Ȃ����̂Ƃ���j
		int* parmanent_data1 = nullptr;
		char* parmanent_data2 = nullptr;
		float* parmanent_data3 = nullptr;
		{
			CTempPolySmartStackAllocator poly_allocator(s_stackForThread, DSA_NORMAL);//���ԃA���P�[�^���X�}�[�g�X�^�b�N�i�����j�ɐݒ�
			parmanent_data1 = new int[2];
			parmanent_data2 = new char[3];
			parmanent_data3 = new float[4];
		}
		unsigned int* parmanent_data4 = nullptr;
		unsigned char* parmanent_data5 = nullptr;
		double* parmanent_data6 = nullptr;
		{
			CTempPolySmartStackAllocator poly_allocator(s_stackForThread, DSA_REVERSE);//���ԃA���P�[�^���X�}�[�g�X�^�b�N�i�t���j�ɐݒ�
			parmanent_data4 = new unsigned int[5];
			parmanent_data5 = new unsigned char[6];
			parmanent_data6 = new double[7];
		}
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());

		//�J�E���g�J�n�i�������Z�b�g�ʒu���X�V�j
		//�����܂ł̏���ی삵�A�ȍ~�g�p���郁�����́A�S�ĉ�����ꂽ���_��
		//�}�[�J�[�������I�ɖ߂�
		printf("beginN()\n");
		s_stackForThread.beginN();//�����������m�ۂ̃J�E���g���J�n
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
		printf("beginR()\n");
		s_stackForThread.beginR();//�t���������m�ۂ̃J�E���g���J�n
		printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());

		//�X���b�h�J�n�@
		{
			std::thread th1 = std::thread(test9thread_n, "�X���b�h�e�X�g9-1(N)");
			std::thread th2 = std::thread(test9thread_n, "�X���b�h�e�X�g9-2(N)");
			std::thread th3 = std::thread(test9thread_r, "�X���b�h�e�X�g9-3(R)");
			std::thread th4 = std::thread(test9thread_r, "�X���b�h�e�X�g9-4(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(500));//500msec�X���[�v
			printf("sleep(500msec)\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			//�X���b�h�I���҂�
			th1.join();
			th2.join();
			th3.join();
			th4.join();
			printf("joined\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
		}

		//�X���b�h�J�n�A
		{
			std::thread th5 = std::thread(test9thread_n, "�X���b�h�e�X�g9-5(N)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msec�X���[�v
			printf("sleep(200msec)\n");
			std::thread th6 = std::thread(test9thread_n, "�X���b�h�e�X�g9-6(N)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msec�X���[�v
			printf("sleep(200msec)\n");
			std::thread th7 = std::thread(test9thread_r, "�X���b�h�e�X�g9-7(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msec�X���[�v
			printf("sleep(200msec)\n");
			std::thread th8 = std::thread(test9thread_r, "�X���b�h�e�X�g9-8(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msec�X���[�v
			printf("sleep(200msec)\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			{
				//���ԃA���P�[�^��TLS�ŃA���P�[�^���X���b�h���Ƃɕ����Ďg���Ă���̂ŁA
				//���̃X���b�h�����쒆�ɈقȂ�A���P�[�^���g���Ă����Ȃ�
				CSmartStackAllocatorWithBuff<128> allocator;
				CTempPolySmartStackAllocator poly_allocator(allocator);
				CTest9* obj_p = new CTest9("�X���b�h�e�X�g(���荞��)");
				delete obj_p;
				printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			}
			{
				//�J�E���g�J�n�O�Ɋm�ۂ�����������r���Ŕj�����Ă��J�E���^�ɂ͉e�����Ȃ�
				//���J�E���g�J�n�ʒu�ȑO�̈ʒu�ɂ��郁�����́A�J�E���^�ɉe�����Ȃ�
				CTempPolySmartStackAllocator poly_allocator(s_stackForThread);
				delete[] parmanent_data1;
				delete[] parmanent_data2;
				delete[] parmanent_data3;
				delete[] parmanent_data4;
				delete[] parmanent_data5;
				delete[] parmanent_data6;
				printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			}
			std::thread th9 = std::thread(test9thread_n, "�X���b�h�e�X�g9-9(N)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msec�X���[�v
			printf("sleep(200msec)\n");
			std::thread th10 = std::thread(test9thread_n, "�X���b�h�e�X�g9-10(N)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msec�X���[�v
			printf("sleep(200msec)\n");
			std::thread th11 = std::thread(test9thread_r, "�X���b�h�e�X�g9-11(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msec�X���[�v
			printf("sleep(200msec)\n");
			std::thread th12 = std::thread(test9thread_r, "�X���b�h�e�X�g9-12(R)");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//200msec�X���[�v
			printf("sleep(200msec)\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
			//�X���b�h�I���҂�
			th5.join();
			th6.join();
			th7.join();
			th8.join();
			th9.join();
			th10.join();
			th11.join();
			th12.join();
			printf("joined\n");
			printf("marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\n", s_stackForThread.getMarkerN(), s_stackForThread.getMarkerR(), s_stackForThread.getBeginN(), s_stackForThread.getBeginR(), s_stackForThread.getCounterN(), s_stackForThread.getCounterR());
		}
	}
}

//--------------------------------------------------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	printf("---------- main:start ----------\n");
	test0();
	test1();
	test2();
	test3();
	test4a();
	test4b();
	test5();
	test6();
	test7();
	test8a();
	test8b();
	test9();
	printf("---------- main:end ----------\n");
	return EXIT_SUCCESS;
}

// End of file
