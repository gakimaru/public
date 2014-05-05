//--------------------------------------------------------------------------------
//�R���p�C�����v���b�g�t�H�[������
//--------------------------------------------------------------------------------

//----------------------------------------
//�R���p�C������
#ifdef _MSC_VER 
	#include <cstddef>//VC++�ł́A������ŏ��ɃC���N���[�h���Ă����Ȃ��ƁA�R���p�C���ɉe�����ł邱�Ƃ�����B
                      //����� #define constexpr �� #define thread_local ���s�������ƂŁA
	                  //�@#include<cstddef>(std::size_t�ȂǗp)���s���ƁA�Ȍ�̏����ŕs���ȃR���p�C���G���[����������B
	#define IS_VC//�R���p�C���FVisual C++
	#define COMPILER_NAME "VC++"
	#define COMPILER_VER _MSC_VER//�R���p�C���o�[�W�����i���W���[�o�[�W�����j
	#define COMPILER_MINOR 0//�R���p�C���o�[�W�����i�}�C�i�[�o�[�W�����j
	//_MSC_VER�̒l
	//   600 ... C Compiler 6.0
	//   700 ... C/C++ Compiler 7.0
	//   800 ... Visual C++ 1.0
	//   900 ... Visual C++ 2.0
	//  1000 ... Visual C++ 4.0
	//  1010 ... Visual C++ 4.1
	//  1020 ... Visual C++ 4.2
	//  1100 ... Visual C++ 5.0 (Visual Studio 97)
	//  1200 ... Visual C++ 6.0 (Visual Studio 6.0)
	//  1300 ... Visual C++ 7.0 (Visual Studio.NET 2002)
	//  1310 ... Visual C++ 7.1 (Visual Studio.NET 2003)
	//  1400 ... Visual C++ 8.0 (Visual Studio 2005)
	//  1500 ... Visual C++ 9.0 (Visual Studio 2008)
	//  1600 ... Visual C++ 10.0 (Visual Studio 2010)
	//  1700 ... Visual C++ 11.0 (Visual Studio 2012)
	//  1800 ... Visual C++ 12.0 (Visual Studio 2013)
#endif//_MSC_VER
#ifdef __GNUC__
	#include <features.h>//__GNUC_PREREQ�}�N�����g����悤�ɂ���
	#define IS_GCC//�R���p�C���FGCC
	#define COMPILER_NAME "GCC"
	#define COMPILER_VER __GNUC__//�R���p�C���o�[�W�����i���W���[�o�[�W�����j
	#define COMPILER_MINOR __GNUC_MINOR__//�R���p�C���o�[�W�����i�}�C�i�[�o�[�W�����j
#endif//__GNUC__
#ifdef __cplusplus
	#define IS_CPP//����FC++
	#define COMPILER_LANGUAGE "C++"
	#if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
		//#define HAS_CPPTR1//����FC++TR1�Ή��i�b��j
		#define HAS_CPP11//����FC++11�Ή�
		#define CPP_VER 2011
	#endif
	#if __cplusplus >= 199711L
		#define HAS_CPP98//����FC++98�Ή�
		#define HAS_CPP03//����FC++03�Ή��i�b��j
		#ifndef CPP_VER
			//#define CPP_VER 1998
			#define CPP_VER 2003
		#endif//CPP_VER
	#endif
#else//__cplusplus
	#define IS_C//����FC
	#define COMPILER_LANGUAGE "C"
	#define CPP_VER 0
#endif//__cplusplus

//----------------------------------------
//�v���b�g�t�H�[������
#ifdef _WIN32
	#define IS_WIN//�v���b�g�t�H�[���FWindows
	#define PLATFORM_NAME "Win"//�v���b�g�t�H�[����
	#ifdef WINVER
		#define PLATFORM_VER WINVER//�v���b�g�t�H�[���o�[�W���� ���ʓr_WIN32_WINNT/WINVER��ݒ肷��K�v����
		//_WIN32_WINNT / WINVER �Ɏw��\�Ȓl
		//  0x500 ... Windows2000
		//  0x501 ... Windows XP / Windows 2003 Server
		//  0x502 ... Windows XP SP2 / Windows 2003 Server SP1
		//  0x600 ... Windows Vista / Windows 2008 Server
		//  0x700 ... Windows 7
	#else//WINVER	
		#define PLATFORM_VER 0//�v���b�g�t�H�[���o�[�W����
	#endif//WINVER
	#define PLATFORM_MINOR 0//�v���b�g�t�H�[���}�C�i�[�o�[�W����
	#ifdef _WIN64
		#define IS_64BIT//�v���b�g�t�H�[���F64bit
		#define PLATFORM_ARCHITECTURE_BITS 64//�v���b�g�t�H�[���A�[�L�e�N�`���i�r�b�g���j
	#else//_WIN64
		#define IS_32BIT//�v���b�g�t�H�[���F32bit
		#define PLATFORM_ARCHITECTURE_BITS 32//�v���b�g�t�H�[���A�[�L�e�N�`���i�r�b�g���j
	#endif//_WIN64
#endif//_WIN32
#ifdef __linux__
	#define IS_LINUX//�v���b�g�t�H�[���FLinux
	#define PLATFORM_VER 0//�v���b�g�t�H�[���o�[�W����
	#define PLATFORM_MINOR 0//�v���b�g�t�H�[���}�C�i�[�o�[�W����
	#define PLATFORM_NAME "Linux"
	#ifdef __x86_64__
		#define IS_64BIT//�v���b�g�t�H�[���F64bit
		#define PLATFORM_ARCHITECTURE_BITS 64//�v���b�g�t�H�[���A�[�L�e�N�`���i�r�b�g���j
	#else//__x86_64__
		#define IS_32BIT//�v���b�g�t�H�[���F32bit
		#define PLATFORM_ARCHITECTURE_BITS 32//�v���b�g�t�H�[���A�[�L�e�N�`���i�r�b�g���j
	#endif//__x86_64__
#endif//__linux__
#ifdef __CYGWIN__
	#define IS_CYGWIN//�v���b�g�t�H�[���FCygwin
	#define PLATFORM_VER 0//�v���b�g�t�H�[���o�[�W����
	#define PLATFORM_MINOR 0//�v���b�g�t�H�[���}�C�i�[�o�[�W����
	#define PLATFORM_NAME "Cygin"
#endif//__CYGWIN__

//CPU
#if defined(__x86_64__) || defined(_M_X64)
	#define IS_X86//�v���b�g�t�H�[���A�[�L�e�N�`���Fx86�n
	#define IS_X64//�v���b�g�t�H�[���A�[�L�e�N�`���Fx64�n
	#define PLATFORM_ARCHITECTURE "x64"//�v���b�g�t�H�[���A�[�L�e�N�`����
	#define IS_64BIT//�v���b�g�t�H�[���F64bit
	#define PLATFORM_ARCHITECTURE_BITS 64//�v���b�g�t�H�[���A�[�L�e�N�`���i�r�b�g���j
	#ifndef __LITTLE_ENDIAN__	
		#define __LITTLE_ENDIAN__//���g���G���f�B�A��
	#endif//__LITTLE_ENDIAN__	
#elif defined(__i386__) || defined(_M_IX86)
	#define IS_X86//�v���b�g�t�H�[���A�[�L�e�N�`���Fx86�n
	#define PLATFORM_ARCHITECTURE "x86"//�v���b�g�t�H�[���A�[�L�e�N�`����
	#define IS_32BIT//�v���b�g�t�H�[���F32bit
	#define PLATFORM_ARCHITECTURE_BITS 32//�v���b�g�t�H�[���A�[�L�e�N�`���i�r�b�g���j
	#ifndef __LITTLE_ENDIAN__	
		#define __LITTLE_ENDIAN__//���g���G���f�B�A��
	#endif//__LITTLE_ENDIAN__	
#endif//__x86_64__/__i386__

//�G���f�B�A������
#ifdef __BIG_ENDIAN__
	#define IS_BIG_ENDIAN//�v���b�g�t�H�[���F�r�b�O�G���f�B�A��
	#define ENDIAN "big"//�G���f�B�A����
#endif//__BIG_ENDIAN__ 
#ifdef __LITTLE_ENDIAN__
	#define IS_LITTLE_ENDIAN//�v���b�g�t�H�[���F���g���G���f�B�A��
	#define ENDIAN "little"//�G���f�B�A����
#endif//__LITTLE_ENDIAN__ 

//----------------------------------------
//�֐����擾�}�N���Ή�

//�����񉻃}�N��
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)

//�֐����擾�}�N��
//�y���ӁzGCC�̊֐��� __FUNCTION__, __PRETTY_FUNCTION__ �͊֐��Ȃ̂ŁA
//�@�@�@�@�R���p�C�����̕����񌋍����ł��Ȃ�
#ifdef IS_VC
	#define __PRETTY_FUNCTION__ __FUNCSIG__
	#define __func__ __FUNCTION__
#endif//IS_VC
#ifdef IS_GCC
	#define __FUNCSIG__ __PRETTY_FUNCTION__
	#define __FUNCDNAME__ ""
#endif//IS_GCC

//�֐����擾�}�N��
#define GET_FUNC_NAME() __PRETTY_FUNCTION__

//�\�[�X�t�@�C�����{�s�ԍ��擾�}�N��
#define GET_FILE_LINE() __FILE__ "(" TO_STRING_EX(__LINE__) ")"
#define GET_FILE_LINE_TIME() __FILE__ "(" TO_STRING_EX(__LINE__) ")[" __TIMESTAMP__ "]"

//----------------------------------------
//C++11�d�l�Ή�
//�Q�l�Fhttps://sites.google.com/site/cpprefjp/implementation-status
//�Q�l(VC++)�Fhttp://msdn.microsoft.com/ja-jp/library/hh567368.aspx
//            ��VC++2010�ȍ~�AC++11�d�l�𕔕�����
//�Q�l(GCC)�Fhttp://gcc.gnu.org/projects/cxx0x.html
//           ��GCC 4.3 C++0x Status
//           �@GCC 4.4 C++0x Status
//           �@GCC 4.5 C++0x Status
//           �@GCC 4.6 C++0x Status
//           �@GCC 4.7 C++11 Status
//           �@GCC 4.8 C++11 Status

//�yC++11�d�l�znullptr
#ifdef IS_VC
	#if _MSC_VER >= 1600//VC++10.0(2010)�ȍ~
		#define HAS_NULLPTR
	#else//_MSC_VER
		//static const void* nullptr = 0;
		#define nullptr 0
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 6)
		#define HAS_NULLPTR
	#else//HAS_CPP11
		//static const void* nullptr = 0;
		#define nullptr 0
	#endif//HAS_CPP11
#endif//IS_GCC

//�yC++11�d�l�zoverride�w��q
#ifdef IS_VC
	#if _MSC_VER >= 1400//VC++8.0(2005)�ȍ~
		#define HAS_OVERRIDE
	#else//_MSC_VER
		#define override//�_�~�[
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 7)
		#define HAS_OVERRIDE
	#else//HAS_CPP11
		#define override//�_�~�[
	#endif//HAS_CPP11
#endif//IS_GCC

//�yC++11�d�l�zfinal�w��q
#ifdef IS_VC
	#if _MSC_VER >= 1700//VC++11.0(2012)�ȍ~
		#define HAS_FINAL
	#else//_MSC_VER
		#define final//�_�~�[
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 7)
		#define HAS_FINAL
	#else//HAS_CPP11
		#define final//�_�~�[
	#endif//HAS_CPP11
#endif//IS_GCC

//�yC++11�d�l�zconstexpr�C���q
#ifdef IS_VC
	#if _MSC_VER > 1800//VC++12.0(2013)�Ȍ�i�b��j
		#define HAS_CONSTEXPR
	#else//_MSC_VER
		#define constexpr const
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 6)
		#define HAS_CONSTEXPR
	#else//HAS_CPP11
		#define constexpr const
	#endif//HAS_CPP11
#endif//IS_GCC

//�yC++11�d�l�z���[�U�[��`���e����
#ifdef IS_VC
	#if _MSC_VER > 1800//VC++12.0(2013)�Ȍ�i�b��j
		#define HAS_USER_DEFINED_LITERAL
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 7)
		#define HAS_USER_DEFINED_LITERAL
	#endif//HAS_CPP11
#endif//IS_GCC

//�yC++11�d�l�zstatic_assert
#ifdef IS_VC
	#if _MSC_VER >= 1600//VC++10.0(2010)�Ȍ�
		#define HAS_STATIC_ASSERT
	#else//_MSC_VER
		#define STATIC_ASSERT(expr, msg) typedef char __STATIC_ASSERT_TYPE[(expr) ? 1 : -1]
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 3)
		#define HAS_STATIC_ASSERT
	#else//HAS_CPP11
		#define STATIC_ASSERT(expr, msg) typedef char __STATIC_ASSERT_TYPE[(expr) ? 1 : -1]
	#endif//HAS_CPP11
#endif//IS_GCC

//�yC++11�d�l�zthread_local�F�X���b�h���[�J���X�g���[�W�iTLS�j�C���q
#ifdef IS_VC
	#if _MSC_VER > 1800//VC++12.0(2013)�Ȍ�i�b��j
		#define HAS_THREAD_LOCAL
	#else//_MSC_VER
		#define thread_local __declspec(thread)
	#endif//_MSC_VER
#endif//IS_VC
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 8)
		#define HAS_THREAD_LOCAL
	#else//HAS_CPP11
		#define thread_local __thread
	#endif//HAS_CPP11
#endif//IS_GCC

//�yC++11�d�l�zalignas�F�A���C�������g�C���q
//�y���Ӂz�C���q�̎w��ʒu���R���p�C���ɂ���ĈقȂ�
//        ���ϐ��錾��
//        �EC++11 ... alignas(32) float pos[4];
//        �EVC++  ... __declspec(align(16)) float pos[4];
//        �EGCC   ... float pos[4] __attribute((aligned(16));
//        ���^�錾��
//        �EC++11 ... struct alignas(32) AVECT{ float pos[4]; };
//        �EVC++  ... __declspec(align(32)) struct vector{ float pos[4]; };
//                    struct __declspec(align(32)) vector{ float pos[4]; };
//        �EGCC   ... struct vector{ float pos[4]; } __attribute((aligned(32));
//                    struct __attribute((aligned(32)) vector{ float pos[4]; };
#ifdef IS_WIN
	#if _MSC_VER > 1800//VC++12.0(2013)�Ȍ�i�b��j
		#define HAS_ALIGNAS
	#else//_MSC_VER
		#define alignas(n) __declspec(align(n))
	#endif//_MSC_VER
#endif//IS_WIN
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 8)
		#define HAS_ALIGNAS
	#else//HAS_CPP11
		#define alignas(n) __attribute__((aligned(n)))
	#endif//HAS_CPP11
#endif//IS_GCC

//�yC++11�d�l�zalignof�F�A���C�������g�擾�֐�
#ifdef IS_WIN
	#if _MSC_VER > 1800//VC++12.0(2013)�Ȍ�i�b��j
		#define HAS_ALIGNOF
	#else//_MSC_VER
		#define alignof(T) __alignof(T)
	#endif//_MSC_VER
#endif//IS_WIN
#ifdef IS_GCC
	#if defined(HAS_CPP11) && __GNUC_PREREQ(4, 5)
		#define HAS_ALIGNOF
	#else//HAS_CPP11
		#define alignof(T) __alignof__(T)
	#endif//HAS_CPP11
#endif//IS_GCC

//�A���C�������g�w��t���������m�ۊ֐�
//��VC++�d�l�ɍ��킹�ċ��ʉ�
#ifdef IS_GCC
#include <stdlib.h>//posix_memalign()�p
#include <memory.h>//free()�p
inline void* _aligned_malloc(size_t size, size_t alignment)
{
	void *p;
	int ret = posix_memalign(&p, alignment, size);
	return (ret == 0) ? p : 0;
}
#define _aligned_free(p) free(p)
#endif//IS_GCC
#ifdef IS_VC
#include <memory.h>//_aligned_malloc(), _aligned_free()�p
//void* _aligned_malloc(size_t size, size_t alignment);
//void _aligned_free(void* p);
#endif//IS_VC

//--------------------------------------------------------------------------------
//�R���p�C�����v���b�g�t�H�[������Ɋ�Â������e�X�g
//--------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//std::size_t�p

//�yC++11�d�l�znullptr�e�X�g
void* nullptr_var = nullptr;

//�yC++11�d�l�zoverride�e�X�g
struct base
{
	virtual void func()
	{
		printf("This is virtual func.\n");
	}
};
struct derived : public base
{
	void func() override
	{
		printf("This is override func.\n");
	}
};
derived override_func_var;

//�yC++11�d�l�zconstexpr�e�X�g
constexpr int constexpr_calc(int a, int b){ return a + b; }
constexpr int constexpr_var = constexpr_calc(1, 2) + 3;

//�yC++11�d�l�z���[�U�[��`���e�����e�X�g
#ifdef HAS_USER_DEFINED_LITERAL
constexpr int operator "" _len(const char* str, const std::size_t len)
{
	return len;
}
const std::size_t user_defined_literal_var = "1234567890"_len;
#endif//HAS_USER_DEFINED_LITERAL

//�yC++11�d�l�zTLS�ϐ��錾�e�X�g
thread_local int m_var_tls = 123;

//�yC++11�d�l�z�A���C�����g�w��e�X�g
struct alignas(16) data_t
{
	int var[8];
};

//----------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//�R���p�C���[�m�F�e�X�g
	printf("Compiler: name=\"%s\", Ver=[%d(0x%08x).%d(0x%08x)]\n", COMPILER_NAME, COMPILER_VER, COMPILER_VER, COMPILER_MINOR, COMPILER_MINOR);
#ifdef IS_VC
	printf("    This compiler is \"Visual C++\"\n");
#endif//IS_VC
#ifdef IS_GCC
	printf("    This compiler is \"GCC\"\n");
#endif//IS_GCC

	//C++����m�F�e�X�g
	printf("\n");
	printf("Compiler-language: %s (C++ Ver.=%d)\n", COMPILER_LANGUAGE, CPP_VER);
#ifdef IS_CPP
	printf("    C++ is available.\n");
#endif//IS_CPP
#ifdef HAS_CPP98
	printf("        C++ is implemented C++98.\n");
#endif//HAS_CPP98
#ifdef HAS_CPP03
	printf("        C++ is implemented C++03.\n");
#endif//HAS_CPP03
#ifdef HAS_CPP11
	printf("        C++ is implemented C++11.\n");
#endif//HAS_CPP11

	//�v���b�g�t�H�[���m�F�e�X�g
	printf("\n");
	printf("Plataform: \"%s\"(%s %dbits, %s-endian), Ver=[%d(0x%08x).%d(0x%08x)]\n", PLATFORM_NAME, PLATFORM_ARCHITECTURE, PLATFORM_ARCHITECTURE_BITS, ENDIAN, PLATFORM_VER, PLATFORM_VER, PLATFORM_MINOR, PLATFORM_MINOR);
#ifdef IS_WIN
	printf("    Target plarform is \"Windows\"\n");
#endif//IS_WIN
#ifdef IS_LINUX
	printf("    Target plarform is \"Linux\"\n");
#endif//IS_LINUX
#ifdef IS_CYGWIN
	printf("    Target plarform is \"Cygwin\"\n");
#endif//IS_CYGWIN

	//��`�ς݃}�N���\���e�X�g
	struct test
	{
		static void func()
		{
			printf("\n");
			printf("__FILE__=\"%s\"\n", __FILE__);
			printf("__LINE__=%d\n", __LINE__);
			printf("__FUNCTION__=\"%s\"\n", __FUNCTION__);
			printf("__PRETTY_FUNCTION__=\"%s\"\n", __PRETTY_FUNCTION__);
			printf("__FUNCSIG__=\"%s\"\n", __FUNCSIG__);
			printf("__func__=\"%s\"\n", __func__);
			printf("__FUNCDNAME__=\"%s\"\n", __FUNCDNAME__);
			printf("__DATE__=\"%s\"\n", __DATE__);
			printf("__TIME__=\"%s\"\n", __TIME__);
			printf("__TIMESTAMP__=\"%s\"\n", __TIMESTAMP__);
			printf("\n");
			printf("GET_FUNC_NAME()=\"%s\"\n", GET_FUNC_NAME());
			printf("GET_FILE_LINE()=\"%s\"\n", GET_FILE_LINE());
			printf("GET_FILE_LINE_TIME()=\"%s\"\n", GET_FILE_LINE_TIME());
		}
	};
	test::func();

	//�yC++11�d�l�znullptr�e�X�g
	printf("\n");
	printf("nullptr_var=%p\n", nullptr_var);
#ifdef HAS_NULLPTR
	printf("    'nullptr' is featured.\n");
#endif//HAS_NULLPTR

	//�yC++11�d�l�zoverride�e�X�g
	printf("\n");
	override_func_var.func();
#ifdef HAS_OVERRIDE
	printf("    'override' is featured.\n");
#endif//HAS_OVERRIDE

	//�yC++11�d�l�zconstexpr�e�X�g
	printf("\n");
	printf("constexpr_var=%d\n", constexpr_var);
	printf("constexpr_calc(1, 2)=%d\n", constexpr_calc(1, 2));
#ifdef HAS_CONSTEXPR
	printf("    'constexpr' is featured.\n");
#endif//HAS_CONSTEXPR

	//�yC++11�d�l�z���[�U�[��`���e�����e�X�g
#ifdef HAS_USER_DEFINED_LITERAL
	printf("\n");
	printf("user_defined_literal_var=%d\n", user_defined_literal_var);
#endif//HAS_USER_DEFINED_LITERAL
#ifdef HAS_USER_DEFINED_LITERAL
	printf("    'operator \"\"'(user defined literal) is featured.\n");
#endif//HAS_USER_DEFINED_LITERAL

	//�yC++11�d�l�zTLS�e�X�g
	printf("\n");
	printf("TLS Variable=%d\n", m_var_tls);
#ifdef HAS_THREAD_LOCAL
	printf("    'thread_local' is featured.\n");
#endif//HAS_THREAD_LOCAL

	//�yC++11�d�l�z�A���C�������g�w��^�擾�^�w��t�������m�ۂƉ���e�X�g
	printf("\n");
	printf("sizeof(data_t)=%d\n", sizeof(data_t));
	printf("alignof(data_t)=%d\n", alignof(data_t));//�A���C�������g�擾�e�X�g
	data_t* p = reinterpret_cast<data_t*>(_aligned_malloc(sizeof(data_t), alignof(data_t)));
	printf("_aligned_malloc(sizeof(data_t), alignof(data_t))=%p\n", p);
	_aligned_free(p);
	printf("_aligned_free(p)\n");
#ifdef HAS_ALIGNAS
	printf("    'alignas' is featured.\n");
#endif//HAS_ALIGNAS
#ifdef HAS_ALIGNOF
	printf("    'alignof' is featured.\n");
#endif//HAS_ALIGNOF

	return EXIT_SUCCESS;
}

// End of file
