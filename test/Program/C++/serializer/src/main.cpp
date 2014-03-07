#define TLS_IS_WINDOWS//�yMS�ŗL�d�l�zTLS�̐錾��Windows�X�^�C���ɂ��鎞�͂��̃}�N����L���ɂ���
#define USE_STRCPY_S//�yMS�ŗL�d�l�zstrcpy_s���g�p���鎞�ɂ��̃}�N����L���ɂ���
#define USE_ALIGNED_MALLOC//�yMS�ŗL�d�l�z_aligned_malloc���g�p���鎞�͂��̃}�N����L���ɂ���
#define USE_FRIEND_WITH_NEW_OPERATOR//�yMS�ŗL�d�l�H�zoperator new()���N���X���Ńt�����h�����鎞�͂��̃}�N����L���ɂ���
#define USE_WINDOWS_DEBUG_BREAK//�yMS�ŗL�d�l�zWindow��DebugBreak���g�p

//#define ENABLE_CONSTEXPR//�yC++11�p�zconstexpr��L���ɂ��鎞�͂��̃}�N����L���ɂ���
//#define ENABLE_USER_DEFINED_LITERALS//�yC++11�p�z���[�U�[��`���e������L���ɂ��鎞�͂��̃}�N����L���ɂ���

#include <stdio.h>
#include <stdlib.h>

#include <memory.h>//memcpy�p
#include <assert.h>//assert�p
#include <cstddef>//std::size_t�p
#include <stdint.h>//uintptr_t�p
#include <limits.h>//UCHAR_MAX�p
#include <typeinfo.h>//type_id�p
#include <map>//STL map�p
#include <iterator>//std::iterator�p
#include <vector>//STL vector�p
#include <algorithm>//STL sort�p
#include <atomic>//C++11�A�g�~�b�N����
#include <thread>//C++11�X���b�h
#include <chrono>//C++11����
#include <stdarg.h>//va_list�p

#ifdef USE_ALIGNED_MALLOC
#include <malloc.h>//malloc,_aligned_malloc�p
#else//USE_ALIGNED_MALLOC
#include <stdlib.h>//memalign�p
#endif//USE_ALIGNED_MALLOC

//--------------------------------------------------------------------------------
//��{�}�N��

//�u���[�N�|�C���g
#ifdef USE_WINDOWS_DEBUG_BREAK
#include <windows.h>//�u���[�N�|�C���g�p
#define BREAK_POINT() DebugBreak()
#else//USE_WINDOWS_DEBUG_BREAK
#define BREAK_POINT()
#endif//USE_WINDOWS_DEBUG_BREAK

//�f�o�b�O�v�����g
#define DEBUG_PRINT(msg, ...) printf(msg, ##__VA_ARGS__)
#define DEBUG_FPRINT(fp, msg, ...) fprintf(fp, msg, ##__VA_ARGS__)
#define DEBUG_FLUSH() fflush(stdout)
#define DEBUG_FFLUSH(fp) fflush(fp)
//#define DEBUG_PRINT(msg, ...)
//#define DEBUG_FPRINT(fp, msg, ...)
//#define DEBUG_FLUSH()
//#define DEBUG_FFLUSH(fp) fflush(fp)

//�����񉻃}�N��
#define TO_STRING(s) #s
#define TO_STRING_EX(s) TO_STRING(s)

//�ÓI�A�T�[�V����
#define STATIC_ASSERT(expr, msg) \
	static_assert(expr, msg)

//�A�T�[�V����
#define ASSERT(expr, msg, ...) \
if (!(expr)) \
	{ \
	DEBUG_FPRINT(stderr, "Assertion failed! : " #expr "\n" \
	"  " __FILE__ "(" TO_STRING_EX(__LINE__) ")\n" \
	"  "  msg "\n", ##__VA_ARGS__); \
	BREAK_POINT(); \
	}
//#define ASSERT(expr, msg, ...)//�폜�p
//#include <assert.h>//assert�p
//#define ASSERT(expr, msg, ...) assert(expr)//VC++�W����

//�X���b�h���[�J���X�g���[�W�C���q
//��C++11�d�l�U��
#ifdef TLS_IS_WINDOWS
#define thread_local __declspec(thread)//Windows�d�l
#else//TLS_IS_WINDOWS
#define thread_local __thread//POSIX�d�l
#endif//TLS_IS_WINDOWS

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
	T& operator*(){ return *m_singleton; }
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

#if 0
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
#endif

#if 0
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
#endif

//--------------------------------------------------------------------------------
//�v�[���A���P�[�^�N���X

//----------------------------------------
//�N���X�錾
class CPoolAllocator;

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
		m_lock.lock();

		m_used.store(0);//�g�p����
		m_next = 0;//���g�p�擪�C���f�b�N�X
		m_recycle = INVALID_INDEX;//���T�C�N���C���f�b�N�X

		//���b�N���
		m_lock.unlock();
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
		m_lock.lock();

		//�g�p���u���b�N�����ă`�F�b�N
		if (m_used.load() >= m_poolBlocksNum)
		{
			m_lock.unlock();//���b�N���
			return INVALID_INDEX;//�󂫂Ȃ�
		}

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
		m_lock.unlock();

		//�ŏ��Ɏg�p���u���b�N���𔻒肵�Ă���̂ŁA���̎��_�ŃC���f�b�N�X�������Ȃ���΃v���O�����ɖ�肪����͂�
		ASSERT(index != INVALID_INDEX, "Probably, mistaken logic in this program.");

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
		m_lock.lock();

		//���T�C�N��
		*reinterpret_cast<unsigned int*>(getBlock(index)) = m_recycle;//���T�C�N���C���f�b�N�X�������݁i�󂫃m�[�h�̐擪�ɋ����ɏ������ށj
		m_recycle = index;//���T�C�N���C���f�b�N�X�g�݊���

		//�g�p�����J�E���g�_�E��
		m_used.fetch_sub(1);

		//���b�N���
		m_lock.unlock();
	}
public:
	//�������m��
	void* alloc(const std::size_t size)
	{
		//�y�A�T�[�V�����z�v���T�C�Y���u���b�N�T�C�Y�𒴂���ꍇ�͑����m�ێ��s
		ASSERT(size <= m_blockSize, "CPoolAllocator::alloc(%d) cannot allocate. Size must has been under %d.", size, m_blockSize);
		if (size > m_blockSize)
		{
			return nullptr;
		}
		//�󂫃u���b�N���m�ۂ��ĕԂ�
		const index_t index = assign();
		//�y�A�T�[�V�����z�S�u���b�N�g�p���ɂ��A�m�ێ��s
		ASSERT(index >= 0, "CPoolAllocator::alloc(%d) cannot allocate. Buffer is full. (num of blocks is %d)", size, m_poolBlocksNum);
		//�m�ۂ�����������Ԃ�
		return index == INVALID_INDEX ? nullptr : getBlock(index);
	}
	//���������
	void free(void * p)
	{
		//nullptr���͑���������s
		ASSERT(p != nullptr, "CPoolAllocator::free() cannot free. Pointer is null.");
		if (!p)
			return;
		//�|�C���^����C���f�b�N�X���Z�o
		const intptr_t diff = reinterpret_cast<intptr_t>(p)-reinterpret_cast<intptr_t>(m_pool);//�|�C���^�̍���
		const index_t index = diff / m_blockSize;//�u���b�N�T�C�Y�Ŋ����ăC���f�b�N�X�Z�o
		//�y�A�T�[�V�����z�������o�b�t�@�͈̔͊O�Ȃ珈�����s�irelease�֐����Ŏ��s����̂ł��̂܂܎��s�j
		ASSERT(index >= 0 && index < m_poolBlocksNum, "CPoolAllocator::free() cannot free. Pointer is different.");
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
		ASSERT((m_blockSize & 0x3) == 0, "CPoolAllocator::CPoolAllocator() block size is invalid.");

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
	CSpinLock m_lock;//���b�N
};

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

#if 1
//--------------------
//�z�unew
void* operator new(const std::size_t size, CPoolAllocator& allocator) throw()
{
	return allocator.alloc(size);
}
//�z�udelete
void operator delete(void* p, CPoolAllocator& allocator) throw()
{
	allocator.free(p);
}

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
#endif

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
#ifdef USE_ALIGNED_MALLOC
		return _aligned_malloc(size, align);//MS�d�l�F�A���C�������g�w���malloc
#else//USE_ALIGNED_MALLOC
		return memalign(align, size);//GCC�p�F�A���C�������g�w���malloc
#endif//USE_ALIGNED_MALLOC
	}
	//���������
	void free(void* p) override
	{
		if (!p)
			return;
#ifdef USE_ALIGNED_MALLOC
		_aligned_free(p);//MS�d�l�F�A���C�������g�w���free
#else//USE_ALIGNED_MALLOC
		::free(p);//�ʏ�free() ��memalign�Ŋm�ۂ�����������free�ŉ��
#endif//USE_ALIGNED_MALLOC
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

#if 0
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
#endif

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
//�X�^�b�N�A���P�[�^�A�_�v�^�[�N���X
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

#if 0
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
#endif

#if 0
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
#endif

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

//--------------------------------------------------------------------------------
//�O���[�o��new/delete + ���ʃA���P�[�^�C���^�[�t�F�[�X

//--------------------
//�N���X�錾
class CTempPolyAllocatorBase;//�ꎞ���ԃA���P�[�^���N���X

//--------------------
//���ԃA���P�[�^
class CPolyAllocator
{
#ifdef USE_FRIEND_WITH_NEW_OPERATOR
	//�W�� new / deleete ���Z�q���t�����h��
	//������ CPolyAllocator �N���X�𒼐ڃC���X�^���X������̂� new / delete ���Z�q�̂�
	friend void* operator new(const std::size_t size) throw();
	friend void* operator new[](const std::size_t size) throw();
	friend void operator delete(void* p) throw();
	friend void operator delete[](void* p) throw();
#endif//USE_FRIEND_WITH_NEW_OPERATOR
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
#ifdef USE_FRIEND_WITH_NEW_OPERATOR
private://���ڃC���X�^���X�����s�i�t�����h��p�j
#else//USE_FRIEND_WITH_NEW_OPERATOR
public:
#endif//USE_FRIEND_WITH_NEW_OPERATOR
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
//�O���[�o�����ԃA���P�[�^
//���W��new / delete ���Z�q�̒u������
//new
void* operator new(const std::size_t size) throw()
{
	CPolyAllocator allocator;
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//�������m�ۏ��擾
	if (info)
		align = info->m_align;
	return allocator->alloc(size, align);
}
//�z���
void* operator new[](const std::size_t size) throw()
{
	CPolyAllocator allocator;
	std::size_t align = ALLOC_INFO::DEFAULT_ALIGN;
	const ALLOC_INFO* info = CPolyAllocator::getAllocInfoWithReset();//�������m�ۏ��擾
	if (info)
		align = info->m_align;
	return allocator->alloc(size, align);
}
//delete
void operator delete(void* p) throw()
{
	CPolyAllocator allocator;
	allocator->free(p);
}
//�z���
void operator delete[](void* p) throw()
{
	CPolyAllocator allocator;
	allocator->free(p);
}

#if 0
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
//NEW�}�N��
//���������m�ۏ��t��
#define NEW(T, ...) newWithInfo<T>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME(), ALLOC_INFO::DEFAULT_ALIGN, ##__VA_ARGS__)//NEW
#define NEWALIGN(T, align, ...) newWithInfo<T>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME(), align, ##__VA_ARGS__)//�A���C�������g�w��t��NEW
#define NEWARR(T, array_size) newArrayWithInfo<T, array_size>(GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME())//�z��NEW
//#define NEWALIGNARR(T, align, array_size)//�A���C�����g�w��t���z��NEW�͐��m�Ɍv�Z�ł��Ȃ��̂őΉ����Ȃ�
//--------------------
//DELETE�}�N��
#ifdef DELETE
#undef DELETE
#endif//DELETE
#define DELETE delete//DELETE
#define DELETEARR delete[]//�z��DELETE
#endif

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
#if 0
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�P��o�b�t�@�A���P�[�^�p
using CTempPolyMonoAllocator = CTempPolyAllocatorDirect<CMonoAllocAdp>;//C++11�`��
#endif
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
#if 0
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
#endif
#if 0
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
#endif
//--------------------
//�ꎞ���ԃA���P�[�^�N���X�F�v�[���A���P�[�^�p
using CTempPolyPoolAllocator = CTempPolyAllocatorWithAdp<CPoolAllocAdp>;//C++11�`��

//--------------------------------------------------------------------------------
//�V���A���C�Y
namespace serial
{
#define IS_LITTLE_ENDIAN//���g���G���f�B�A��
//#define IS_BIG_ENDIAN//�r�b�O�G���f�B�A��

	//--------------------
	//�o�[�W�����N���X
	template<unsigned short MAJOR, unsigned short MINOR>
	class CVersionDefBase;
	class CVersion
	{
	public:
		//�萔
		static const unsigned int VER_FIGURE = 1000000;//�����o�[�W�����v�Z�p���グ��
		enum compareEnum : char
		{
			EQ = 0,//==:EQual�F����
			LT = -1,//<:Less Than�F������
			GT = 1,//>:Greater Than�F�傫��
			MINOR_LT = -2,//�}�C�i�[�o�[�W�����̂ݏ������i���W���[�o�[�W�����͈�v�j
			MINOR_GT = 2,//�}�C�i�[�o�[�W�����̂ݑ傫���i���W���[�o�[�W�����͈�v�j
		};
	public:
		//�A�N�Z�b�T
		unsigned int getMajor() const { return m_majorVer; };//���W���[�o�[�W����
		unsigned int getMinor() const { return m_minorVer; };//�}�C�i�[�o�[�W����
		unsigned int getVer()const { return m_ver; };//�����o�[�W����
		const unsigned int* getVerPtr()const { return &m_ver; };//�����o�[�W�����̃|�C���^
		std::size_t getVerSize()const { return sizeof(m_ver); };//�����o�[�W�����̃T�C�Y
	public:
		//�I�y���[�^
		bool operator==(const CVersion& rhs) const { return m_ver == rhs.m_ver; }
		bool operator!=(const CVersion& rhs) const { return m_ver != rhs.m_ver; }
		bool operator<(const CVersion& rhs) const { return m_ver < rhs.m_ver; }
		bool operator<=(const CVersion& rhs) const { return m_ver <= rhs.m_ver; }
		bool operator>(const CVersion& rhs) const { return m_ver > rhs.m_ver; }
		bool operator>=(const CVersion& rhs) const { return m_ver >= rhs.m_ver; }
	public:
		//�L���X�g�I�y���[�^
		operator unsigned int() const { return m_ver; }
	public:
		//���\�b�h
		//��r
		compareEnum compare(CVersion& rhs)
		{
			return	m_majorVer < rhs.m_majorVer ?
						LT :
						m_majorVer > rhs.m_majorVer ?
							GT :
							m_minorVer < rhs.m_minorVer ?
								MINOR_LT :
								m_minorVer > rhs.m_minorVer ?
									MINOR_GT :
									EQ;
		}
		//�o�[�W��������W���[�o�[�W�����ƃ}�C�i�[�o�[�W�������Z�o
		void calcFromVer()
		{
			*const_cast<unsigned short*>(&m_majorVer) = m_ver / VER_FIGURE;
			*const_cast<unsigned short*>(&m_minorVer) = m_ver % VER_FIGURE;
		}
	public:
		//�f�t�H���g�R���X�g���N�^
		CVersion() :
			m_majorVer(0),
			m_minorVer(0),
			m_ver(0)
		{}
		//�R���X�g���N�^
		CVersion(const unsigned short major, const unsigned short minor) :
			m_majorVer(major),
			m_minorVer(minor),
			m_ver(major * VER_FIGURE + minor)
		{}
		template<unsigned short MAJOR, unsigned short MINOR>
		CVersion(CVersionDefBase<MAJOR, MINOR>&) :
			CVersion(MAJOR, MINOR)
		{}
	private:
		//�t�B�[���h
		const unsigned int m_ver;//�o�[�W����
		const unsigned short m_majorVer;//���W���[�o�[�W����
		const unsigned short m_minorVer;//�}�C�i�[�o�[�W����
	};
	//--------------------
	//�o�[�W�����e���v���[�g���N���X
	template<unsigned short MAJOR, unsigned short MINOR>
	class CVersionDefBase
	{
	public:
		//�萔
		static const unsigned short MAJOR_VER = MAJOR;//���W���[�o�[�W����
		static const unsigned short MINOR_VER = MINOR;//�}�C�i�[�o�[�W����
		static const unsigned int VER = MAJOR_VER * CVersion::VER_FIGURE + MINOR_VER;//�����o�[�W����
	public:
		//�A�N�Z�b�T
		unsigned int getMajor() const { return MAJOR_VER; };//���W���[�o�[�W����
		unsigned int getMinor() const { return MINOR_VER; };//�}�C�i�[�o�[�W����
		unsigned int getVer() const { return VER; };//�����o�[�W����
	};
	//--------------------
	//�o�[�W�����e���v���[�g�N���X
	template<class T>
	class CVersionDef : public CVersionDefBase<0, 0>{};//�K��ł�0

	//--------------------
	//�f�[�^�N���X�p�̃o�[�W������`�}�N��
	#define SERIALIZE_VERSION_DEF(T, MAJOR, MINOR) \
		namespace serial \
		{ \
			template<> \
			struct CVersionDef<T> : public CVersionDefBase<MAJOR, MINOR>{}; \
		}

	//--------------------
	//�ėp�f�[�^�^�w��p�\����
	struct str_t{};//������^
	struct bin_t{};//�o�C�i���^
	//--------------------
	//�^������N���X
	typedef std::size_t(*toMemFuncP)(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size);//�������փR�s�[�֐��^
	typedef std::size_t(*fromMemFuncP)(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size);//����������R�s�[�֐��^
	typedef std::size_t(*toStrFuncP)(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size);//������֕ϊ��֐��^
	typedef std::size_t(*fromStrFuncP)(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max);//�����񂩂�ϊ��֐��^
	class CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			if (mem_size < value_size)
			{
				//�������ݐ�̃T�C�Y�̕����������ꍇ
				//���������ݐ�̃T�C�Y�������R�s�[����
				memcpy(mem, value_p, mem_size);
			}
			else if (mem_size > value_size)
			{
				//�������ݐ�̃T�C�Y�̕����傫���ꍇ
				//��������[���N���A
				memcpy(mem, value_p, value_size);
				memset(reinterpret_cast<char*>(mem)+value_size, 0, mem_size - value_size);
			}
			else//if (mem_size == value_size)
			{
				//�T�C�Y����v����ꍇ
				//�����̂܂܃R�s�[���邾��
				memcpy(mem, value_p, mem_size);
			}
			return mem_size;
		}
		//���G���f�B�A��������
		static std::size_t toMemAndAdjust(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			if (mem_size < value_size)
			{
				//�������ݐ�̃T�C�Y�̕����������ꍇ
			#ifdef IS_BIG_ENDIAN
				//���������ݐ�̃T�C�Y������������R�s�[����
				memcpy(mem, reinterpret_cast<const char*>(value_p)+(value_size - mem_size), mem_size);
			#else//IS_BIG_ENDIAN
				//���������ݐ�̃T�C�Y�������O�����R�s�[����
				memcpy(mem, value_p, mem_size);
			#endif//IS_BIG_ENDIAN
			}
			else if (mem_size > value_size)
			{
				//�������ݐ�̃T�C�Y�̕����傫���ꍇ
			#ifdef IS_BIG_ENDIAN
				//����l�߂őO�����[���N���A
				memcpy(reinterpret_cast<char*>(mem)+value_size, value_p, value_size);
				memset(mem, 0, mem_size - value_size);
			#else//IS_BIG_ENDIAN
				//���O�l�߂Ō�����[���N���A
				memcpy(mem, value_p, value_size);
				memset(reinterpret_cast<char*>(mem)+value_size, 0, mem_size - value_size);
			#endif//IS_BIG_ENDIAN
			}
			else//if (mem_size == value_size)
			{
				//�T�C�Y����v����ꍇ
				//�����̂܂܃R�s�[���邾��
				memcpy(mem, value_p, mem_size);
			}
			return mem_size;
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return toMem(value_p, value_size, mem, mem_size);
		}
		//���G���f�B�A��������
		static std::size_t fromMemAndAdjust(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return toMemAndAdjust(value_p, value_size, mem, mem_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			std::size_t used = 0;
			std::size_t remain = str_max;
			char* write_p = str;
			const unsigned char* read_p = reinterpret_cast<const unsigned char*>(value_p);
			for (unsigned int i = 0; i < value_size && remain > 5 + 1; ++i)
			{
				const unsigned char c = *(read_p++);
				const unsigned char hi = c >> 4;
				const unsigned char lo = c & 0xf;
				if (i != 0)
				{
					*(write_p++) = ',';
					++used;
					--remain;
				}
				*(write_p++) = '0';
				*(write_p++) = 'x';
				*(write_p++) = hi >= 10 ? 'a' + hi : '0' + hi;
				*(write_p++) = lo >= 10 ? 'a' + lo : '0' + lo;
				used += 4;
				remain -= 4;
			}
			if (remain > 1)
				*(write_p) = '\0';
			return used;
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�f�t�H���g�R���X�g���N�^
		CTypeCtrlBase() :
			m_toMemFuncP(toMem),
			m_fromMemFuncP(fromMem),
			m_toStrFuncP(toStr),
			m_fromStrFuncP(fromStr)
		{}
		//�R�s�[�R���X�g���N�^
		CTypeCtrlBase(const CTypeCtrlBase& src) :
			m_toMemFuncP(src.m_toMemFuncP),
			m_fromMemFuncP(src.m_fromMemFuncP),
			m_toStrFuncP(src.m_toStrFuncP),
			m_fromStrFuncP(src.m_fromStrFuncP)
		{}
		//�R���X�g���N�^
		CTypeCtrlBase(toMemFuncP to_mem_func_p, fromMemFuncP from_mem_func_p, toStrFuncP to_func_p, fromStrFuncP from_func_p) :
			m_toMemFuncP(to_mem_func_p),
			m_fromMemFuncP(from_mem_func_p),
			m_toStrFuncP(to_func_p),
			m_fromStrFuncP(from_func_p)
		{}
		//�f�X�g���N�^
		~CTypeCtrlBase()
		{}
	public:
		//�t�B�[���h
		toMemFuncP m_toMemFuncP;//�������փR�s�[�֐�
		fromMemFuncP m_fromMemFuncP;//����������R�s�[�֐�
		toStrFuncP m_toStrFuncP;//������֕ϊ��֐�
		fromStrFuncP m_fromStrFuncP;//�����񂩂�ϊ��֐�
	};
	//--------------------
	//�^���쉻�N���X
	template<typename T>
	class CTypeCtrl : public CTypeCtrlBase
	{
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase()
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<int> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const int value = *reinterpret_cast<const int*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%d", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%d", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t data_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<unsigned int> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned int value = *reinterpret_cast<const unsigned int*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%08x", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%08x", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<long> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const long value = *reinterpret_cast<const long*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%ld", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%ld", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t data_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<unsigned long> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned long value = *reinterpret_cast<const unsigned long*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%08lx", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%08lx", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<long long> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const long long value = *reinterpret_cast<const long long*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%lld", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%lld", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t data_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<unsigned long long> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned long long value = *reinterpret_cast<const unsigned long long*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%016llx", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%016llx", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<short> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const short value = *reinterpret_cast<const short*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%d", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%d", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<unsigned short> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned short value = *reinterpret_cast<const unsigned short*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%04x", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%04x", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<char> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const char value = *reinterpret_cast<const char*>(value_p);
			#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%d", value);
			#else//USE_STRCPY_S
			return sprintf(str, "%d", value);
			#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<unsigned char> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const unsigned char value = *reinterpret_cast<const unsigned char*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "0x%02x", value);
		#else//USE_STRCPY_S
			return sprintf(str, "0x%02x", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<float> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			//return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
			return CTypeCtrlBase::toMem(mem, mem_size, value_p, value_size);//�G���f�B�A�������Ȃ��ŃR�s�[
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			if (mem_size == sizeof(double))
			{
				//double�^�Ɨ\��
				double value_from;
				CTypeCtrlBase::fromMem(mem, mem_size, &value_from, sizeof(value_from));
				const float value_to = static_cast<float>(value_from);
				CTypeCtrlBase::toMem(value_p, value_size, &value_to, sizeof(value_to));
			}
			else if (mem_size == sizeof(float))
			{
				//return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
				return CTypeCtrlBase::fromMem(mem, mem_size, value_p, value_size);//�G���f�B�A�������Ȃ��ŃR�s�[
			}
			else
			{
				//�����^�Ɨ\��
				long long value_from;
				CTypeCtrlBase::fromMem(mem, mem_size, &value_from, sizeof(value_from));
				const float value_to = static_cast<float>(value_from);
				CTypeCtrlBase::toMem(value_p, value_size, &value_to, sizeof(value_to));
			}
			return mem_size;
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const float value = *reinterpret_cast<const float*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%f", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%f", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<double> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			//return CTypeCtrlBase::toMemAndAdjust(mem, mem_size, value_p, value_size);
			return CTypeCtrlBase::toMem(mem, mem_size, value_p, value_size);//�G���f�B�A�������Ȃ��ŃR�s�[
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			if (mem_size == sizeof(float))
			{
				//float�^�Ɨ\��
				float value_from;
				CTypeCtrlBase::fromMem(mem, mem_size, &value_from, sizeof(value_from));
				const double value_to = static_cast<float>(value_from);
				CTypeCtrlBase::toMem(value_p, value_size, &value_to, sizeof(value_to));
			}
			else if (mem_size == sizeof(double))
			{
				//return CTypeCtrlBase::fromMemAndAdjust(mem, mem_size, value_p, value_size);
				return CTypeCtrlBase::fromMem(mem, mem_size, value_p, value_size);//�G���f�B�A�������Ȃ��ŃR�s�[
			}
			else
			{
				//�����^�Ɨ\��
				long long value_from;
				CTypeCtrlBase::fromMem(mem, mem_size, &value_from, sizeof(value_from));
				const double value_to = static_cast<double>(value_from);
				CTypeCtrlBase::toMem(value_p, value_size, &value_to, sizeof(value_to));
			}
			return mem_size;
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			const double value = *reinterpret_cast<const double*>(value_p);
		#ifdef USE_STRCPY_S
			return sprintf_s(str, str_max, "%llf", value);
		#else//USE_STRCPY_S
			return sprintf(str, "%llf", value);
		#endif//USE_STRCPY_S
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<bin_t> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMem(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMem(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toStr(str, str_max, value_p, value_size);
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};
	//--------------------
	//�^����N���X
	template<>
	class CTypeCtrl<str_t> : public CTypeCtrlBase
	{
	public:
		//���\�b�h
		//�������փR�s�[
		static std::size_t toMem(void* mem, const std::size_t mem_size, const void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::toMem(mem, mem_size, value_p, value_size);
		}
		//����������R�s�[
		static std::size_t fromMem(const void* mem, const std::size_t mem_size, void* value_p, const std::size_t value_size)
		{
			return CTypeCtrlBase::fromMem(mem, mem_size, value_p, value_size);
		}
		//������֕ϊ�
		static std::size_t toStr(char* str, const std::size_t str_max, const void* value_p, const std::size_t value_size)
		{
			std::size_t used = 0;
			std::size_t remain = str_max;
			char* write_p = str;
			if (remain > 1 + 1)
			{
				*(write_p++) = '\"';
				++used;
				--remain;
			}
			const unsigned char* read_p = reinterpret_cast<const unsigned char*>(value_p);
			for (unsigned int i = 0; i < value_size && remain > 1 + 1; ++i)
			{
				const unsigned char c = *(read_p++);
				if (c == '\0')
					break;
				*(write_p++) = c;
				++used;
				++remain;
			}
			if (remain > 1 + 1)
			{
				*(write_p++) = '\"';
				++used;
				--remain;
			}
			if (remain > 1)
				*(write_p) = '\0';
			return used;
		}
		//�����񂩂�ϊ�
		static std::size_t fromStr(const char* str, const std::size_t str_size, void* value_p, const std::size_t value_size_max)
		{
			//������
			return 0;
		}
	public:
		//�R���X�g���N�^
		CTypeCtrl() :
			CTypeCtrlBase(toMem, fromMem, toStr, fromStr)
		{}
		//�f�X�g���N�^
		~CTypeCtrl()
		{}
	};

	//--------------------
	//�N���X�錾
	class CItemBase;
	//--------------------
	//�V���A���C�Y�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���V���A���C�Y�ƃf�V���A���C�Y���p���ʏ���
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct serialize {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, const T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//�Z�[�u�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct save	{
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//���[�h�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct load	{
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, const T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//���[�h�O�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//��obj�̃��[�h���J�n����O�Ɏ��s�����
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct beforeLoad {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//���[�h�㏈���p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//��obj�̃��[�h����ʂ�I��������Ǝ��s�����
	//��noticeUnrecognizedItem, noticeUnloadedItem �̌�Ɏ��s�����
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct afterLoad {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//�Z�[�u�f�[�^�ɂ͂��������A�ۑ���̎w�肪�Ȃ��A���[�h�ł��Ȃ��������ڂ̒ʒm
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//�����������玞�_�Œm�����̂ŁAobj���s���S�ȏ�Ԃł���_�ɒ���
	//���Ϗ��f�[�^���� delegate_item �Ƀf�[�^���ڂ��Z�b�g���ĕԂ��ƃ��g���C���Ă����ɓǂݍ���
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct noticeUnrecognizedItem {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unrecognized_item)
		{}
	};
	//--------------------
	//�ۑ���̎w�肪���邪�A�Z�[�u�f�[�^�ɂȂ����[�h�ł��Ȃ��������ڂ̒ʒm
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//��obj�̃��[�h����ʂ�I��������ƁA�܂Ƃ߂Ēʒm����
	//��noticeUnrecognizedItem �̌�AafterLoad ����Ɏ��s�����
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct noticeUnloadedItem {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unloaded_item)
		{}
	};
	//--------------------
	//�f�[�^���W�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//�������̒��Ŏg����̂� operator<<() �̂�
	//�@operator&() �͋֎~
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct collector {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//�f�[�^���z�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//�������̒��Ŏg����̂� operator>>() �̂�
	//�@operator&() �͋֎~
	//�����W�����œo�^���ꂽ�I�u�W�F�N�g���Z�[�u�f�[�^���猩���邲�Ƃ�
	//�@���x���Ăяo�����
	//�����������I�u�W�F�N�g�̏��i�f�[�^���ڏ�� = target_item�j���n�����
	//����{�I�u�W�F�N�g�iobj�j�́A�z�񂾂����ꍇ�A���̐擪�̗v�f���n�����
	//���Z�[�u�f�[�^��̔z��v�f���ƁA���[�h�ł����z��v�f���i��������̔z��v�f���j���n�����
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct distributor {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{}
	};
	//--------------------
	//�f�[�^���z�O�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	template<class Arc, class T>
	struct beforeDistribute {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//�f�[�^���z�㏈���p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	template<class Arc, class T>
	struct afterDistribute {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//�V���A���C�Y���ɒv���I�G���[�����������p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���V���A���C�Y��p����
	//���G���[�����������^�C�~���O�ł͂Ȃ��A�Ō�ɌĂяo�����
	//�����ꉻ�ɂ�胆�[�U�[����������
	template<class Arc, class T>
	struct fatalSerializeErrorOccurred {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//�f�V���A���C�Y���ɒv���I�G���[�����������p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//���G���[�����������^�C�~���O�ł͂Ȃ��A�Ō�ɌĂяo�����
	//�����ꉻ�ɂ�胆�[�U�[����������
	template<class Arc, class T>
	struct fatalDeserializeErrorOccurred {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, const T& obj, const CVersion& ver, const CVersion& now_ver)
		{}
	};
	//--------------------
	//�֐��I�u�W�F�N�g��`�ς݃`�F�b�N�֐�
	//��SFINAE�ɂ��AIS_UNDEFINED ����`����Ă���^�̃I�[�o�[���[�h�֐����I�΂ꂽ�疢��`�Ƃ݂Ȃ�
	template<class F>
	bool isDefinedFunctor(const typename F::IS_UNDEFINED)
	{
		return false;//����`
	}
	template<class F>
	bool isDefinedFunctor(...)
	{
		return true;//��`�ς�
	}
	//--------------------
	//�A�[�J�C�u�_�~�[�N���X
	class CArchiveDummy{};
	//--------------------
	//�I�u�W�F�N�g�^���H
	//�������ꂩ�̊֐��I�u�W�F�N�g���o�^����Ă���΃I�u�W�F�N�g�^�Ƃ݂Ȃ�
	//���I�u�W�F�N�g�^�̓V���A���C�Y�̍ۂɃf�[�^�u���b�N�Ƃ��Ĉ���
	template<class T>
	bool hasAnyFunctor()
	{
		//�����Ń`�F�b�N�F���W�����ƕ��z�����͕K�������Z�b�g�Œ�`����K�v����
		assert((isDefinedFunctor<collector<CArchiveDummy, T> >(0)) == (isDefinedFunctor<distributor<CArchiveDummy, T> >(0)));
		//�֐��I�u�W�F�N�g�̂ǂꂩ��ł���`����Ă��邩�`�F�b�N
		return isDefinedFunctor<serialize<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<save<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<load<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<beforeLoad<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<afterLoad<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<noticeUnrecognizedItem<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<noticeUnloadedItem<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<collector<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<distributor<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<beforeDistribute<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<afterDistribute<CArchiveDummy, T> >(0);
		//isDefinedFunctor<fatalSerializeErrorOccurred<CArchiveDummy, T> >(0);//����͐����Ȃ�
		//isDefinedFunctor<fatalDeserializeErrorOccurred<CArchiveDummy, T> >(0);////����͐����Ȃ�
	}
	//--------------------
	//�f�[�^�N���X�̃t�����h�錾�p�}�N��
	#define FRIEND_SERIALIZE(T) \
		template<class Arc, class T> \
		friend struct serial::serialize; \
		template<class Arc, class T> \
		friend struct serial::save; \
		template<class Arc, class T> \
		friend struct serial::load; \
		template<class Arc, class T> \
		friend struct serial::beforeLoad; \
		template<class Arc, class T> \
		friend struct serial::afterLoad; \
		template<class Arc, class T> \
		friend struct serial::noticeUnrecognizedItem; \
		template<class Arc, class T> \
		friend struct serial::noticeUnloadedItem; \
		template<class Arc, class T> \
		friend struct serial::collector; \
		template<class Arc, class T> \
		friend struct serial::distributor; \
		template<class Arc, class T> \
		friend struct serial::beforeDistribute; \
		template<class Arc, class T> \
		friend struct serial::afterDistribute; \
		template<class Arc, class T> \
		friend struct serial::fatalSerializeErrorOccurred; \
		template<class Arc, class T> \
		friend struct fatalDeserializeErrorOccurred;

	//--------------------
	//�|�C���^�^�`�F�b�N�p�N���X
	//���e���v���[�g�̕������ꉻ�𗘗p
	template<class T>
	struct isPtr
	{
		static const bool IS_PTR = false;//�|�C���^�^���H = ��|�C���^�^
		typedef T TYPE;//�ʏ�^�i��|�C���^�^�j�ϊ��p�̌^
		typedef T* PTR_TYPE;//�|�C���^�^�ϊ��p�̌^
		static const T* TO_PTR(const T& var){ return reinterpret_cast<const T*>(&var); }//�|�C���^�ɕϊ�
	};
	template<class T>
	struct isPtr<T*>
	{
		static const bool IS_PTR = true;//�|�C���^�^���H = �|�C���^�^
		typedef T TYPE;//�ʏ�^�i��|�C���^�^�j�ϊ��p�̌^
		typedef T* PTR_TYPE;//�|�C���^�^�ϊ��p�̌^
		static const T* TO_PTR(const T* var){ return var; }//�|�C���^�ɕϊ�
	};
	//--------------------
	//�f�[�^���ڑ���
	enum itemAttrEnum : unsigned char
	{
		IS_OBJECT = 0x01,//�I�u�W�F�N�g�^
		IS_ARRAY = 0x02,//�z��^
		IS_PTR = 0x04,//�|�C���^�^
		IS_NULL = 0x08,//�k��
		IS_VLEN = 0x10,//�ϒ����H
		HAS_VERSION = 0x20,//�o�[�W������񂠂�
	};
	class CItemAttr
	{
	public:
		//�^
		typedef unsigned char value_t;//�����^
	public:
		//�A�N�Z�b�T
		bool isObj() const { return (m_value & IS_OBJECT) ? true : false; }//�I�u�W�F�N�g�^���H
		bool isArr() const { return (m_value & IS_ARRAY) ? true : false; }//�z��^���H
		bool isPtr() const { return (m_value & IS_PTR) ? true : false; }//�|�C���^�^���H
		bool isNul() const { return (m_value & IS_NULL) ? true : false; }//�k���|�C���^���H�i�|�C���^�^�̎�����������j
		bool isVLen() const { return (m_value & IS_VLEN) ? true : false; }//�ϒ����H�i��ɕ�����|�C���^�̎��Ɉ�����j
		bool hasVersion() const { return (m_value & HAS_VERSION) ? true : false; }//�o�[�W������񂪂��邩�H
		void setHasVersion() const { *const_cast<value_t*>(&m_value) = m_value | HAS_VERSION; }//�o�[�W������񂠂�ɂ���
		void resetHasVersion() const { *const_cast<value_t*>(&m_value) = m_value & ~HAS_VERSION; }//�o�[�W�������Ȃ��ɂ���
	public:
		//�I�y���[�^
		bool operator==(const CItemAttr& rhs) const { return m_value == rhs.m_value; }
		bool operator!=(const CItemAttr& rhs) const { return m_value != rhs.m_value; }
		//�R�s�[�I�y���[�^
		CItemAttr& operator=(const CItemAttr& src)
		{
			*const_cast<value_t*>(&m_value) = src.m_value;
			return *this;
		}
	public:
		//���\�b�h
		//�N���A
		void clear()
		{
			*const_cast<value_t*>(&m_value) = 0;
		}
	public:
		//�R���X�g���N�^
		CItemAttr(const value_t info) :
			m_value(info)
		{}
		CItemAttr(const bool is_object, const bool is_array, const bool is_ptr, const bool is_null, const bool is_vlen) :
			m_value(
				(is_object ? IS_OBJECT : 0) |
				(is_array ? IS_ARRAY : 0) |
				(is_ptr ? IS_PTR : 0) |
				(is_ptr && is_null ? IS_NULL : 0) |
				(is_vlen ? IS_VLEN : 0)
				)
		{}
		//�f�X�g���N�^
		~CItemAttr()
		{}
	public://���ڃA�N�Z�X����
		//�t�B�[���h
		const value_t m_value;//����
	};
	//--------------------
	//�f�[�^���ڏ����N���X
	class CItemBase
	{
	public:
		//�A�N�Z�b�T
		bool isObj() const { return m_attr.isObj(); }//�I�u�W�F�N�g�^���H
		bool isArr() const { return m_attr.isArr(); }//�z��^���H
		bool isPtr() const { return m_attr.isPtr(); }//�|�C���^�^���H
		bool isNul() const { return m_attr.isNul(); }//�k�����H
		bool isVLen() const { return m_attr.isVLen(); }//�ϒ����H
		//�y�Q�l�p�z�i�Z�[�u�f�[�^��́j�z��v�f�����擾
		//���A�[�J�C�u�`���ɂ���Ă͐������Ȃ��\��������
		std::size_t getElemNum() const
		{
			return m_arrNum == 0 ?
						1 :
						m_arrNum;
		}
		//���݂̔z��v�f�����擾
		std::size_t getNowElemNum() const
		{
			return	m_hasNowInfo ?
						m_nowArrNum == 0 ?
							1 :
							m_nowArrNum :
						0;
		}
		//�y�Q�l�p�z�ŏ��̔z��v�f�����擾
		//���A�[�J�C�u�`���ɂ���Ă͐������Ȃ��\��������
		std::size_t getMinimumElemNum() const
		{
			return	m_hasNowInfo ?
						m_arrNum < m_nowArrNum ?
							m_arrNum == 0 ?
								1 :
								m_arrNum :
							m_nowArrNum == 0 ?
								1 :
								m_nowArrNum :
						m_arrNum == 0 ?
							 1 :
							 m_arrNum;
		}
		bool nowIsObj() const { return m_hasNowInfo && m_nowAttr.isObj(); }//���݂̃f�[�^�̓I�u�W�F�N�g�^���H
		bool nowIsArr() const { return m_hasNowInfo && m_nowAttr.isArr(); }//���݂̃f�[�^�͔z��^���H
		bool nowIsPtr() const { return m_hasNowInfo && m_nowAttr.isPtr(); }//���݂̃f�[�^�̓|�C���^�^���H
		bool nowIsNul() const { return m_hasNowInfo && m_nowAttr.isNul(); }//���݂̃f�[�^�̓k�����H
		bool nowIsVLen() const { return m_hasNowInfo && m_nowAttr.isVLen(); }//���݂̃f�[�^�͉ϒ����H
		bool nowAndSaveDataIsSameAttr() const { return m_hasNowInfo && m_nowAttr == m_attr; }//���݂̃f�[�^�ƃZ�[�u�f�[�^�̑�������v���邩�H
		bool nowAndSaveDataIsDifferentAttr() const { return m_hasNowInfo && m_nowAttr != m_attr; }//���݂̃f�[�^�ƃZ�[�u�f�[�^�̑�������v���Ȃ����H
		bool nowAndSaveDataIsObj() const { return m_hasNowInfo && m_nowAttr.isObj() && m_attr.isObj(); }//���݂̃f�[�^���Z�[�u�f�[�^���I�u�W�F�N�g�^���H
		bool nowAndSaveDataIsArr() const { return m_hasNowInfo && m_nowAttr.isArr() && m_attr.isArr(); }//���݂̃f�[�^���Z�[�u�f�[�^���z��^���H
		bool nowAndSaveDataIsPtr() const { return m_hasNowInfo && m_nowAttr.isPtr() && m_attr.isPtr(); }//���݂̃f�[�^���Z�[�u�f�[�^���|�C���^�^���H
		bool nowAndSaveDataIsNul() const { return m_hasNowInfo && m_nowAttr.isNul() && m_attr.isNul(); }//���݂̃f�[�^���Z�[�u�f�[�^���̓k�����H
		bool nowIsObjButSaveDataIsNot() const { return m_hasNowInfo && m_nowAttr.isObj() && !m_attr.isObj(); }//���݂̃f�[�^�̓I�u�W�F�N�g�^�����Z�[�u�f�[�^�͂����ł͂Ȃ����H
		bool nowIsArrButSaveDataIsNot() const { return m_hasNowInfo && m_nowAttr.isArr() && !m_attr.isArr(); }//���݂̃f�[�^�͔z��^�����Z�[�u�f�[�^�͂����ł͂Ȃ����H
		bool nowIsPtrButSaveDataIsNot() const { return m_hasNowInfo && m_nowAttr.isPtr() && !m_attr.isPtr(); }//���݂̃f�[�^�̓|�C���^�^�����Z�[�u�f�[�^�͂����ł͂Ȃ����H
		bool nowIsNulButSaveDataIsNot() const { return m_hasNowInfo && m_nowAttr.isNul() && !m_attr.isNul(); }//���݂̃f�[�^�̓k�������Z�[�u�f�[�^�͂����ł͂Ȃ����H
		bool nowIsNotObjButSaveDataIs() const { return m_hasNowInfo && !m_nowAttr.isObj() && m_attr.isObj(); }//���݂̃f�[�^�̓I�u�W�F�N�g�^�ł͂Ȃ����Z�[�u�f�[�^�͂������H
		bool nowIsNotArrButSaveDataIs() const { return m_hasNowInfo && !m_nowAttr.isArr() && m_attr.isArr(); }//���݂̃f�[�^�͔z��^�ł͂Ȃ����Z�[�u�f�[�^�͂������H
		bool nowIsNotPtrButSaveDataIs() const { return m_hasNowInfo && !m_nowAttr.isPtr() && m_attr.isPtr(); }//���݂̃f�[�^�̓|�C���^�^�ł͂Ȃ����Z�[�u�f�[�^�͂������H
		bool nowIsNotNulButSaveDataIs() const { return m_hasNowInfo && !m_nowAttr.isNul() && m_attr.isNul(); }//���݂̃f�[�^�̓k���ł͂Ȃ����Z�[�u�f�[�^�͂������H
		bool nowSizeIsSame() const { return !isObj() && !isVLen() && m_hasNowInfo && m_nowItemSize == m_itemSize; }//���݂̃T�C�Y�̕��ƃZ�[�u�f�[�^�̃T�C�Y���������H
		bool nowSizeIsSamall() const { return !isObj() && !isVLen() && m_hasNowInfo && m_nowItemSize < m_itemSize; }//���݂̃T�C�Y�̕����Z�[�u�f�[�^�̃T�C�Y��菬�������H
		bool nowSizeIsLarge() const { return !isObj() && !isVLen() && m_hasNowInfo && m_nowItemSize > m_itemSize; }//���݂̃T�C�Y�̕����Z�[�u�f�[�^�̃T�C�Y���傫�����H
		bool nowArrIsSame() const { return m_hasNowInfo && m_nowArrNum == m_arrNum; }//���݂̔z��T�C�Y�ƃZ�[�u�f�[�^�̔z��T�C�Y���������H
		bool nowArrIsSmall() const { return m_hasNowInfo && m_nowArrNum < m_arrNum; }//���݂̔z��T�C�Y�̕����Z�[�u�f�[�^�̔z��T�C�Y��菬�������H
		bool nowArrIsLarge() const { return m_hasNowInfo && m_nowArrNum > m_arrNum; }//���݂̔z��T�C�Y�̕����Z�[�u�f�[�^�̔z��T�C�Y���傫�����H
		bool hasNowInfo() const { return m_hasNowInfo; }//���݂̏��R�s�[�ςݎ擾
		bool isOnlyOnSaveData() const{ return m_isOnlyOnSaveData; }//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���H
		void setIsOnlyOnSaveData() const { m_isOnlyOnSaveData = true; m_isOnlyOnMem = false; }//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^�����X�V
		void setIsOnlyOnSaveData(const bool enabled) const { if (enabled) setIsOnlyOnSaveData(); }//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^�����X�V
		void resetIsOnlyOnSaveData() const { m_isOnlyOnSaveData = false; }//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^�������Z�b�g
		bool isOnlyOnMem() const { return m_isOnlyOnMem; }//�Z�[�u�f�[�^��ɂȂ��f�[�^���H
		void setIsOnlyOnMem() const { m_isOnlyOnMem = true; m_isOnlyOnSaveData = false; }//�Z�[�u�f�[�^��ɂȂ��f�[�^�����X�V
		void setIsOnlyOnMem(const bool enabled) const { if (enabled) setIsOnlyOnMem(); }//�Z�[�u�f�[�^��ɂȂ��f�[�^�����X�V
		void resetIsOnlyOnMem() const { m_isOnlyOnMem = false; }//�Z�[�u�f�[�^��ɂȂ��f�[�^�������Z�b�g
		bool isAlready() const { return m_isAlready; }//�����ς݂��H
		void setIsAlready() const { m_isAlready = true; }//�����ς݂ɂ���
		void resetIsAlready() const { m_isAlready = false; }//�����ς݂���������
	public:
		//�I�y���[�^
		bool operator==(const CItemBase& rhs) const { return m_nameCrc == rhs.m_nameCrc; }//�f�[�^���ږ�CRC�ň�v����
		bool operator!=(const CItemBase& rhs) const { return m_nameCrc != rhs.m_nameCrc; }//�f�[�^���ږ�CRC�ŕs��v����
		bool operator==(const crc32_t name_crc) const { return m_nameCrc == name_crc; }//�f�[�^���ږ�CRC�ň�v����
		bool operator!=(const crc32_t name_crc) const { return m_nameCrc != name_crc; }//�f�[�^���ږ�CRC�ŕs��v����
		bool operator==(const char* name) const { return m_nameCrc == calcCRC32(name); }//�f�[�^���ږ�CRC�ň�v����
		bool operator!=(const char* name) const { return m_nameCrc != calcCRC32(name); }//�f�[�^���ږ�CRC�ŕs��v����
	public:
		//�L���X�g�I�y���[�^
		operator crc32_t() const { return m_nameCrc; }
		operator const char*() const { return m_name; }
		operator const std::type_info& () const { return *m_itemType; }
	public:
		//���\�b�h
		template<typename T>//�l�擾
		T& get(){ return *static_cast<T*>(const_cast<void*>(m_itemP)); }
		template<typename T>//�l�擾�i�z��v�f�j
		T& get(const int index){ return static_cast<T*>(const_cast<void*>(m_itemP))[index]; }
		template<typename T>//const�Œl�擾
		const T& get() const { return *static_cast<const T*>(m_itemP); }
		template<typename T>//const�Œl�擾�i�z��v�f�j
		const T& get(const int index) const { return static_cast<const T*>(m_itemP)[index]; }
		template<typename T>//const�Œl�擾
		const T& getConst() const { return *static_cast<const T*>(m_itemP); }
		template<typename T>//const�Œl�擾�i�z��v�f�j
		const T& getConst(const int index) const { return static_cast<const T*>(m_itemP)[index]; }
		//�ǂݍ��ݏ����N���A
		void clearForLoad()
		{
			//m_name = nullptr;//�f�[�^���ږ�
			*const_cast<crc32_t*>(&m_nameCrc) = 0;//�f�[�^���ږ�CRC
			//m_itemP;//�f�[�^�̎Q�ƃ|�C���^
			//m_itemType;//�f�[�^�̌^���
			*const_cast<std::size_t*>(&m_itemSize) = 0;//�f�[�^�T�C�Y
			*const_cast<std::size_t*>(&m_arrNum) = 0;//�f�[�^�̔z��T�C�Y
			const_cast<CItemAttr*>(&m_attr)->clear();//����
			m_nowItemSize = 0;//���݂̃f�[�^�T�C�Y
			m_nowArrNum = 0;//���݂̃f�[�^�̔z��T�C�Y
			m_nowAttr.clear();//���݂̑���
			m_hasNowInfo = false;//���݂̏��R�s�[�ς�
			m_isOnlyOnSaveData = false;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^
			m_isOnlyOnMem = false;//�Z�[�u�f�[�^��ɂȂ��f�[�^
			m_isAlready = false;//�����ς�
		}
		//���݂̏����R�s�[
		void copyFromOnMem(const CItemBase& src)
		{
			//assert(m_nameCrc == src.m_nameCrc);//�S�Ă��R�s�[����
			m_name = src.m_name;//�f�[�^���ږ�
			*const_cast<crc32_t*>(&m_nameCrc) = src.m_nameCrc;//�f�[�^���ږ�CRC
			m_itemP = src.m_itemP;//�f�[�^�̎Q�ƃ|�C���^
			m_itemType = src.m_itemType;//�f�[�^�̌^���
			m_nowItemSize = src.m_itemSize;//���݂̃f�[�^�T�C�Y
			m_nowArrNum = src.m_arrNum;//���݂̃f�[�^�̔z��T�C�Y
			m_nowAttr = src.m_attr;//���݂̑���
			m_nowTypeCtrl = src.m_typeCtrl;//�^����
			m_hasNowInfo = true;//���݂̏��R�s�[�ς�
			m_isOnlyOnSaveData = false;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^
			m_isOnlyOnMem = false;//�Z�[�u�f�[�^��ɂȂ��f�[�^
			src.resetIsOnlyOnMem();//�R�s�[���́u�Z�[�u�f�[�^��ɂȂ��f�[�^�v�����Z�b�g
		}
		//�����I�ɑS�����R�s�[
		void copyForce(const CItemBase& src)
		{
			memcpy(this, &src, sizeof(*this));
		}
	public:
		//�R�s�[�R���X�g���N�^
		CItemBase(const CItemBase& src) :
			m_name(src.m_name),
			m_nameCrc(src.m_nameCrc),
			m_itemP(src.m_itemP),
			m_itemType(src.m_itemType),
			m_itemSize(src.m_itemSize),
			m_arrNum(src.m_arrNum),
			m_attr(src.m_attr),
			m_typeCtrl(src.m_typeCtrl),
			m_nowItemSize(src.m_nowItemSize),
			m_nowArrNum(src.m_nowArrNum),
			m_nowAttr(src.m_nowAttr),
			m_nowTypeCtrl(src.m_nowTypeCtrl),
			m_hasNowInfo(src.m_hasNowInfo),
			m_isOnlyOnSaveData(src.m_isOnlyOnSaveData),
			m_isOnlyOnMem(src.m_isOnlyOnMem),
			m_isAlready(src.m_isAlready)
		{}
		//�f�t�H���g�R���X�g���N�^
		CItemBase() :
			m_name(nullptr),
			m_nameCrc(0),
			m_itemP(nullptr),
			m_itemType(&typeid(void)),
			m_itemSize(0),
			m_arrNum(0),
			m_attr(false, false, false, false, false),
			m_typeCtrl(CTypeCtrlBase()),
			m_nowItemSize(0),
			m_nowArrNum(0),
			m_nowAttr(false, false, false, false, false),
			m_nowTypeCtrl(CTypeCtrlBase()),
			m_hasNowInfo(false),
			m_isOnlyOnSaveData(false),
			m_isOnlyOnMem(false),
			m_isAlready(false)
		{}
		//�R���X�g���N�^
		CItemBase(const char* name, const void* item_p, const std::type_info& item_type, const std::size_t item_size, const std::size_t arr_num, const bool is_object, const bool is_ptr, const bool is_vlen, CTypeCtrlBase type_ctrl) :
			m_name(name),
			m_nameCrc(calcCRC32(name)),
			m_itemP(item_p),
			m_itemType(&item_type),
			m_itemSize(item_size),
			m_arrNum(arr_num),
			m_attr(is_object, arr_num > 0, is_ptr, item_p == nullptr, is_vlen),
			m_typeCtrl(type_ctrl),
			m_nowItemSize(0),
			m_nowArrNum(0),
			m_nowAttr(false, false, false, false, false),
			m_nowTypeCtrl(CTypeCtrlBase()),
			m_hasNowInfo(false),
			m_isOnlyOnSaveData(false),
			m_isOnlyOnMem(false),
			m_isAlready(false)
		{}
		//�R���X�g���N�^
		CItemBase(const CItemBase& src, const void* item_p, const std::type_info& item_type, const std::size_t item_size, const std::size_t arr_num, const bool is_object, const bool is_ptr, const bool is_vlen, CTypeCtrlBase type_ctrl) :
			m_name(src.m_name),
			m_nameCrc(src.m_nameCrc),
			m_itemP(item_p),
			m_itemType(&item_type),
			m_itemSize(item_size),
			m_arrNum(arr_num),
			m_attr(is_object, arr_num > 0, is_ptr, item_p == nullptr, is_vlen),
			m_typeCtrl(type_ctrl),
			m_nowItemSize(0),
			m_nowArrNum(0),
			m_nowAttr(false, false, false, false, false),
			m_nowTypeCtrl(CTypeCtrlBase()),
			m_hasNowInfo(false),
			m_isOnlyOnSaveData(false),
			m_isOnlyOnMem(false),
			m_isAlready(false)
		{}
		//�f�X�g���N�^
		~CItemBase()
		{}
	public://�t�B�[���h�����J���Ē��ڑ���
		//�t�B�[���h
		const char* m_name;//�f�[�^���ږ�
		const crc32_t m_nameCrc;//�f�[�^���ږ�CRC
		const void* m_itemP;//�f�[�^�̎Q�ƃ|�C���^
		const std::type_info* m_itemType;//�f�[�^�̌^���
		const std::size_t m_itemSize;//�f�[�^�T�C�Y
		const std::size_t m_arrNum;//�f�[�^�̔z��T�C�Y
		const CItemAttr m_attr;//����
		CTypeCtrlBase m_typeCtrl;//�^����
		std::size_t m_nowItemSize;//�f�[�^�T�C�Y�@�����݂̃T�C�Y�i�f�V���A���C�Y�����p�j
		std::size_t m_nowArrNum;//�f�[�^�̔z��T�C�Y�@�����݂̃T�C�Y�i�f�V���A���C�Y�����p�j
		CItemAttr m_nowAttr;//�����@�����݂̏�ԁi�f�V���A���C�Y�����p�j
		CTypeCtrlBase m_nowTypeCtrl;//�^����@�����݂̏�ԁi�f�V���A���C�Y�����p�j
		bool m_hasNowInfo;//���݂̏��R�s�[�ς�
		mutable bool m_isOnlyOnSaveData;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^
		mutable bool m_isOnlyOnMem;//�Z�[�u�f�[�^��ɂȂ��f�[�^
		mutable bool m_isAlready;//�����ς�
	};
	//--------------------
	//�f�[�^���ڏ��e���v���[�g�N���X
	template<typename T>
	class CItem : public CItemBase
	{
	public:
		//�R���X�g���N�^
		CItem(const char* name, const T* item_p, const std::size_t arr_num, const bool is_ptr, const bool is_vlen) :
			CItemBase(name, item_p, typeid(T), sizeof(T), arr_num, hasAnyFunctor<T>(), is_ptr, is_vlen, CTypeCtrl<T>())
		{}
		CItem(const char* name, const std::size_t size, const T* item_p, const bool is_ptr, const bool is_vlen) :
			CItemBase(name, item_p, typeid(T), size, 0, hasAnyFunctor<T>(), is_ptr, is_vlen, CTypeCtrl<T>())
		{}
		CItem(const char* name, const std::size_t size) :
			CItemBase(name, nullptr, typeid(T), size, 0, hasAnyFunctor<T>(), false, false, CTypeCtrl<T>())
		{}
		CItem(const char* name) :
			CItemBase(name, nullptr, typeid(T), 0, 0, hasAnyFunctor<T>(), false, false, CTypeCtrl<T>())
		{}
		CItem(const CItemBase& src) :
			CItemBase(src)
		{}
		//�f�X�g���N�^
		~CItem()
		{}
	};
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐�
	template<class T>
	CItem<typename isPtr<T>::TYPE> pair(const char* name, const T& item)
	{
		CItem<typename isPtr<T>::TYPE> item_obj(name, isPtr<T>::TO_PTR(item), 0, isPtr<T>::IS_PTR, false);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i�z�񎩓�����p�j
	template<class T, std::size_t N>
	CItem<T> pair(const char* name, const T(&item)[N])
	{
		CItem<T> item_obj(name, item, N, false, false);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i�|�C���^��z�񈵂��ɂ������ꍇ�Ɏg�p�j
	template<class T>
	CItem<typename isPtr<T>::TYPE> pairArray(const char* name, const T& item, const std::size_t N)
	{
		CItem<typename isPtr<T>::TYPE> item_obj(name, isPtr<T>::TO_PTR(item), N, isPtr<T>::IS_PTR, false);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i�o�C�i���p�j
	//��operator&()��p
	//��operator<<() / operator>>() �ɂ͎g�p�֎~
#if 1//�o�C�i���^�����ɂ���ꍇ
	template<class T>
	CItem<bin_t> pairBin(const char* name, const T& item)
	{
		const std::size_t item_size = sizeof(T);
		const bin_t* item_p = reinterpret_cast<const bin_t*>(&item);
		CItem<bin_t> item_obj(name, item_size, item_p, false, false);
		return item_obj;
	}
#else//char�̔z�񈵂��ɂ���ꍇ
	template<class T>
	CItem<char> pairBin(const char* name, const T& item)
	{
		const std::size_t arra_num = sizeof(T);
		const char* item_p = reinterpret_cast<const char*>(&item);
		CItem<char> item_obj(name, item_p, arra_num, false, false);
		return item_obj;
	}
#endif
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i������p�j
	//��operator&()��p
	//��operator<<() / operator>>() �ɂ͎g�p�֎~
	template<std::size_t N>
	CItem<str_t> pairStr(const char* name, const char (&item)[N])
	{
		const std::size_t item_size = sizeof(char)* N;
		const str_t* item_p = reinterpret_cast<const str_t*>(&item);
		CItem<str_t> item_obj(name, item_size, item_p, false, true);
		return item_obj;
	}
	//���|�C���^�p
	CItem<str_t> pairStr(const char* name, char* item, const std::size_t max_size)
	{
		const std::size_t item_size = max_size;//�A�[�J�C�u�ǂݍ��ݗp�̃T�C�Y�i�A�[�J�C�u�������ݎ��͎��ۂ̕�����+1�ɍX�V����^�k���Ȃ�0�j
		const str_t* item_p = reinterpret_cast<const str_t*>(item);
		CItem<str_t> item_obj(name, item_size, item_p, true, true);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i����p�j
	template<class T>
	CItem<T> pair(const char* name, const std::size_t size)
	{
		CItem<T> item_obj(name, size);
		return item_obj;
	}
	template<class T>
	CItem<T> pair(const char* name)
	{
		CItem<T> item_obj(name, 0);
		return item_obj;
	}
	
	//--------------------
	//�������ʃN���X
	class CResult
	{
	public:
		//�A�N�Z�b�T
		bool hasFatalError() const { return m_hasFatalError; }//�v���I�ȃG���[����
		void setHasFatalError(){ m_hasFatalError = true; }//�v���I�ȃG���[����
		void setHasFatalError(const bool enabled){ if (enabled) setHasFatalError(); }//�v���I�ȃG���[����
		int getNumSmallerSizeItem() const { return m_numSmallerSizeItem; }//�T�C�Y���k�����ꂽ�f�[�^���ڂ̐����擾
		int getNumLargerSizeItem() const { return m_numLargerSizeItem; }//�T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐����擾
		int getNumSmallerArrItem() const { return m_numSmallerArrItem; }//�z��T�C�Y���k�����ꂽ�f�[�^���ڂ̐����擾
		int getNumLargerArrItem() const { return m_numLargerArrItem; }//�z��T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐����擾
		int getNumIsOnlyOnSaveData() const { return m_numIsOnlyOnSaveData; }//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���ڂ̐����擾
		int getNumIsOnlyOnMem() const { return m_numIsOnlyOnMem; }//�Z�[�u�f�[�^��ɂȂ��f�[�^���ڂ̐����擾
		int getNumIsObjOnSaveDataOnly() const { return m_numIsObjOnSaveDataOnly; }//���݃I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����擾
		int getNumIsObjOnMemOnly() const { return m_numIsObjOnMemOnly; }//���݃I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����擾
		int getNumIsArrOnSaveDataOnly() const { return m_numIsArrOnSaveDataOnly; }//���ݔz��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����擾
		int getNumIsArrOnMemOnly() const { return m_numIsArrOnMemOnly; }//���ݔz��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����擾
		int getNumIsPtrOnSaveDataOnly() const { return m_numIsPtrOnSaveDataOnly; }//���݃|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����擾
		int getNumIsPtrOnMemOnly() const { return m_numIsPtrOnMemOnly; }//���݃|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����擾
		int getNumIsNulOnSaveDataOnly() const { return m_numIsNulOnSaveDataOnly; }//���݃k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����擾
		int getNumIsNulOnMemOnly() const { return m_numIsNulOnMemOnly; }//���݃k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����擾
		void addNumSmallerSizeItem(){ ++m_numSmallerSizeItem; }//�T�C�Y���k�����ꂽ�f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumLargerSizeItem(){ ++m_numLargerSizeItem; }//�T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumSmallerArrItem(){ ++m_numSmallerArrItem; }//�z��T�C�Y���k�����ꂽ�f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumLargerArrItem(){ ++m_numLargerArrItem; }//�z��T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsOnlyOnSaveData(){ ++m_numIsOnlyOnSaveData; }//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsOnlyOnMem(){ ++m_numIsOnlyOnMem; }//�Z�[�u�f�[�^��ɂȂ��f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsObjOnSaveDataOnly(){ ++m_numIsObjOnSaveDataOnly; }//���݃I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsObjOnMemOnly(){ ++m_numIsObjOnMemOnly; }//���݃I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsArrOnSaveDataOnly(){ ++m_numIsArrOnSaveDataOnly; }///���ݔz��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsArrOnMemOnly(){ ++m_numIsArrOnMemOnly; }//���ݔz��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsPtrOnSaveDataOnly(){ ++m_numIsPtrOnSaveDataOnly; }//���݃|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsPtrOnMemOnly(){ ++m_numIsPtrOnMemOnly; }//���݃|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsNulOnSaveDataOnly(){ ++m_numIsNulOnSaveDataOnly; }//���݃k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsNulOnMemOnly(){ ++m_numIsNulOnMemOnly; }//���݃k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumSmallerSizeItem(const bool enabled){ if (enabled) addNumSmallerSizeItem(); }//�T�C�Y���k�����ꂽ�f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumLargerSizeItem(const bool enabled){ if (enabled) addNumLargerSizeItem(); }//�T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumSmallerArrItem(const bool enabled){ if (enabled) addNumSmallerArrItem(); }//�z��T�C�Y���k�����ꂽ�f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumLargerArrItem(const bool enabled){ if (enabled) addNumLargerArrItem(); }//�z��T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsOnlyOnSaveData(const bool enabled){ if (enabled) addNumIsOnlyOnSaveData(); }//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsOnlyOnMem(const bool enabled){ if (enabled) addNumIsOnlyOnMem(); }//�Z�[�u�f�[�^��ɂȂ��f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsObjOnSaveDataOnly(const bool enabled){ if (enabled) addNumIsObjOnSaveDataOnly(); }//���݃I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsObjOnMemOnly(const bool enabled){ if (enabled) addNumIsObjOnMemOnly(); }//���݃I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsArrOnSaveDataOnly(const bool enabled){ if (enabled) addNumIsArrOnSaveDataOnly(); }//���ݔz��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsArrOnMemOnly(const bool enabled){ if (enabled) addNumIsArrOnMemOnly(); }//���ݔz��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsPtrOnSaveDataOnly(const bool enabled){ if (enabled) addNumIsPtrOnSaveDataOnly(); }//���݃|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsPtrOnMemOnly(const bool enabled){ if (enabled) addNumIsPtrOnMemOnly(); }//���݃|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsNulOnSaveDataOnly(const bool enabled){ if (enabled) addNumIsNulOnSaveDataOnly(); }//���݃k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����J�E���g�A�b�v
		void addNumIsNulOnMemOnly(const bool enabled){ if (enabled) addNumIsNulOnMemOnly(); }//���݃k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����J�E���g�A�b�v
		std::size_t getCopiedSize() const { return m_copiedSize; }//�R�s�[�ς݃T�C�Y�擾
		std::size_t getSaveDataSize() const { return m_hasFatalError ? 0 : m_saveDataSize; }//�Z�[�u�f�[�^�T�C�Y�擾
		void setSaveDataSize(const std::size_t save_data_size){ m_saveDataSize = save_data_size; }//�Z�[�u�f�[�^�T�C�Y���Z�b�g
	public:
		//���\�b�h
		//�R�s�[�ς݃T�C�Y�ǉ�
		std::size_t addCopiedSize(const std::size_t size)
		{
			m_copiedSize += size;
			return m_copiedSize;
		}
		//�������ʂɉ��Z
		void addResult(const CResult& src)
		{
			setHasFatalError(src.m_hasFatalError);//�v���I�ȃG���[����
			m_numSmallerSizeItem += src.m_numSmallerSizeItem;//�T�C�Y���k�����ꂽ�f�[�^���ڂ̐�
			m_numLargerSizeItem += src.m_numLargerSizeItem;//�T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐�
			m_numSmallerArrItem += src.m_numSmallerArrItem;//�z��T�C�Y���k�����ꂽ�f�[�^���ڂ̐�
			m_numLargerArrItem += src.m_numLargerArrItem;//�z��T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐�
			m_numIsOnlyOnSaveData += src.m_numIsOnlyOnSaveData;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���ڂ̐�
			m_numIsOnlyOnMem += src.m_numIsOnlyOnMem;//�Z�[�u�f�[�^��ɂȂ��f�[�^���ڂ̐�
			m_numIsObjOnSaveDataOnly += src.m_numIsObjOnSaveDataOnly;//���݃I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
			m_numIsObjOnMemOnly += src.m_numIsObjOnMemOnly;//���݃I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
			m_numIsArrOnSaveDataOnly += src.m_numIsArrOnSaveDataOnly;//���ݔz��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
			m_numIsArrOnMemOnly += src.m_numIsArrOnMemOnly;//���ݔz��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
			m_numIsPtrOnSaveDataOnly += src.m_numIsPtrOnSaveDataOnly;//���݃|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
			m_numIsPtrOnMemOnly += src.m_numIsPtrOnMemOnly;//���݃|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
			m_numIsNulOnSaveDataOnly += src.m_numIsNulOnSaveDataOnly;//���݃k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
			m_numIsNulOnMemOnly += src.m_numIsNulOnMemOnly;//���݃k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
			m_copiedSize += src.m_copiedSize;//�R�s�[�ς݃T�C�Y
		}
		//�������ʂ��v��
		void addResult(const CItemBase& src)
		{
			addNumSmallerSizeItem(src.nowSizeIsSamall());//�T�C�Y���k�����ꂽ�f�[�^���ڂ̐�
			addNumLargerSizeItem(src.nowSizeIsLarge());//�T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐�
			addNumSmallerArrItem(src.nowArrIsSmall());//�z��T�C�Y���k�����ꂽ�f�[�^���ڂ̐�
			addNumLargerArrItem(src.nowArrIsLarge());//�z��T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐�
			addNumIsOnlyOnSaveData(src.isOnlyOnSaveData());//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���ڂ̐�
			addNumIsOnlyOnMem(src.isOnlyOnMem());//�Z�[�u�f�[�^��ɂȂ��f�[�^���ڂ̐�
			addNumIsObjOnSaveDataOnly(src.nowIsNotObjButSaveDataIs());//���݃I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
			addNumIsObjOnMemOnly(src.nowIsObjButSaveDataIsNot());//���݃I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
			addNumIsArrOnSaveDataOnly(src.nowIsNotArrButSaveDataIs());//���ݔz��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
			addNumIsArrOnMemOnly(src.nowIsArrButSaveDataIsNot());//���ݔz��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
			addNumIsPtrOnSaveDataOnly(src.nowIsNotPtrButSaveDataIs());//���݃|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
			addNumIsPtrOnMemOnly(src.nowIsPtrButSaveDataIsNot());//���݃|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
			addNumIsNulOnSaveDataOnly(src.nowIsNotNulButSaveDataIs());//���݃k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
			addNumIsNulOnMemOnly(src.nowIsNulButSaveDataIsNot());//���݃k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		}
	public:
		//�R���X�g���N�^
		CResult() :
			m_hasFatalError(false),
			m_numSmallerSizeItem(0),
			m_numLargerSizeItem(0),
			m_numSmallerArrItem(0),
			m_numLargerArrItem(0),
			m_numIsOnlyOnSaveData(0),
			m_numIsOnlyOnMem(0),
			m_numIsObjOnSaveDataOnly(0),
			m_numIsObjOnMemOnly(0),
			m_numIsArrOnSaveDataOnly(0),
			m_numIsArrOnMemOnly(0),
			m_numIsPtrOnSaveDataOnly(0),
			m_numIsPtrOnMemOnly(0),
			m_numIsNulOnSaveDataOnly(0),
			m_numIsNulOnMemOnly(0),
			m_copiedSize(0),
			m_saveDataSize(0)
		{}
		//�f�X�g���N�^
		~CResult()
		{}
	private:
		//�t�B�[���h
		bool m_hasFatalError;//�v���I�ȃG���[����
		short m_numSmallerSizeItem;//�T�C�Y���k�����ꂽ�f�[�^���ڂ̐�
		short m_numLargerSizeItem;//�T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐�
		short m_numSmallerArrItem;//�z��T�C�Y���k�����ꂽ�f�[�^���ڂ̐�
		short m_numLargerArrItem;//�z��T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐�
		short m_numIsOnlyOnSaveData;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���ڂ̐�
		short m_numIsOnlyOnMem;//�Z�[�u�f�[�^��ɂȂ��f�[�^���ڂ̐�
		short m_numIsObjOnSaveDataOnly;//���݃I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
		short m_numIsObjOnMemOnly;//���݃I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		short m_numIsArrOnSaveDataOnly;//���ݔz��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
		short m_numIsArrOnMemOnly;//���ݔz��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		short m_numIsPtrOnSaveDataOnly;//���݃|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
		short m_numIsPtrOnMemOnly;//���݃|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		short m_numIsNulOnSaveDataOnly;//���݃k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
		short m_numIsNulOnMemOnly;//���݃k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		std::size_t m_copiedSize;//�R�s�[�ς݃T�C�Y
		std::size_t m_saveDataSize;//�Z�[�u�f�[�^�T�C�Y
	};

	//--------------------
	//�A�[�J�C�u�ǂݏ������N���X
	typedef unsigned char byte;//�o�b�t�@�p
	class CIOArchiveBase
	{
		friend class CIOArchiveHelper;
		friend class COArchiveHelper;
		friend class CIArchiveHelper;
	public:
		//�^
		typedef std::map<crc32_t, const CItemBase> itemList_t;//�f�[�^���ڃ��X�g�^
	public:
		//�A�N�Z�b�T
		CResult& getResult(){ return m_result; }//�������ʂ��擾
		const CResult& getResult() const { return m_result; }//�������ʂ��擾
		bool hasFatalError() const { return m_result.hasFatalError(); }//�v���I�ȃG���[���肩�H
		std::size_t getSaveDataSize() const { return m_result.getSaveDataSize(); }//�Z�[�u�f�[�^�T�C�Y�擾
	protected:
		const byte* getBuffPtr() const { return m_buff; }//�Z�[�u�f�[�^�o�b�t�@�̐擪�|�C���^���擾
		const std::size_t getBuffSize() const { return m_buffSize; }//�Z�[�u�f�[�^�o�b�t�@�̃T�C�Y���擾
		const std::size_t getBuffUsed() const { return m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̎g�p�ʂ��擾
		const std::size_t getBuffPos() const { return m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̌��݈ʒu���擾
		const std::size_t getBuffRemain() const { return m_buffSize - m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̎c�ʂ��擾
		byte* getBuffNowPtr(){ return m_buff + m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̌��݈ʒu�̃|�C���^���擾
		bool buffIsFull() const { return m_buffPos >= m_buffSize; }//�o�b�t�@�̌��݈ʒu�����[�ɓ��B�������H
		std::size_t getItemListNum() const { return m_itemList->size(); }//�f�[�^���ڃ��X�g
	protected:
		//���\�b�h
		//�������ʂ�����
		void addResult(const CResult& src)
		{
			m_result.addResult(src);
		}
		//���X�g�Ƀf�[�^���ڒǉ�
		void addItem(const CItemBase& item)
		{
			//���[�N�̈��ݒ�i�O���[�o�����ԃA���P�[�^�j
			//���֐��𔲂���Ǝ����I�Ɍ��ɖ߂�
			CTempPolyStackAllocator alloc(m_workBuff);

			//�f�[�^���ڂ�ǉ�
			assert(m_itemList->find(item.m_nameCrc) == m_itemList->end());
			m_itemList->emplace(item.m_nameCrc, item);
		}
		//���X�g����f�[�^���ڂ�����
		const CItemBase* findItem(const crc32_t name_crc) const
		{
			auto ite = m_itemList->find(name_crc);
			if (ite == m_itemList->end())//�����������H
				return nullptr;//������Ȃ�����
			return &ite->second;
		}
	private:
		//�f�[�^���X�g�쐬
		void createItemList()
		{
			//���[�N�̈��ݒ�i�O���[�o�����ԃA���P�[�^�j
			//���֐��𔲂���Ǝ����I�Ɍ��ɖ߂�
			CTempPolyStackAllocator alloc(m_workBuff);

			//�f�[�^���ڃ��X�g�𐶐�
			m_itemList = new itemList_t;
		}
		//�f�[�^���X�g�j��
		void destroyItemList()
		{
			//���[�N�̈��ݒ�i�O���[�o�����ԃA���P�[�^�j
			//���֐��𔲂���Ǝ����I�Ɍ��ɖ߂�
			CTempPolyStackAllocator alloc(m_workBuff);

			//�f�[�^���ڃ��X�g��j��
			if (m_itemList)
			{
				delete m_itemList;
				m_itemList = nullptr;
			}

			//���[�N�o�b�t�@�p�X�^�b�N�A���P�[�^�N���A
			m_workBuff.clearN();
		}
	protected:
		//�R���X�g���N�^
		CIOArchiveBase(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_nestLevel(0),
			m_buff(reinterpret_cast<byte*>(buff)),
			m_buffSize(buff_size),
			m_buffPos(0),
			m_workBuff(work_buff, work_buff_size),
			m_itemList(nullptr)
		{
			//�f�[�^���X�g�쐬
			createItemList();
		}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		CIOArchiveBase(CIOArchiveBase& parent) :
			m_nestLevel(parent.m_nestLevel + 1),
			m_buff(parent.getBuffNowPtr()),
			m_buffSize(parent.getBuffRemain()),
			m_buffPos(0),
			m_workBuff(const_cast<IStackAllocator::byte*>(parent.m_workBuff.getNowPtrN()), parent.m_workBuff.getRemain()),
			m_itemList(nullptr)
		{
			//�f�[�^���X�g�쐬
			createItemList();
		}
		//�f�X�g���N�^
		~CIOArchiveBase()
		{
			//�f�[�^���X�g�j��
			destroyItemList();
		}
	protected:
		//�t�B�[���h
		CResult m_result;//��������
		int m_nestLevel;//�f�[�^�̃l�X�g���x��
		byte* m_buff;//�Z�[�u�f�[�^�o�b�t�@
		const std::size_t m_buffSize;//�Z�[�u�f�[�^�o�b�t�@�̃T�C�Y
		std::size_t m_buffPos;//�Z�[�u�f�[�^�o�b�t�@�̏����ʒu
		CStackAllocator m_workBuff;//���[�N�o�b�t�@�p�X�^�b�N�A���P�[�^
		itemList_t* m_itemList;//�f�[�^���ڃ��X�g
	};
	//--------------------
	//�A�[�J�C�u�������݃N���X
	template<class STYLE>
	class COArchive : public CIOArchiveBase
	{
	public:
		//�萔
		static const bool is_read = false;//�ǂݍ��݃N���X���H
		static const bool is_write = true;//�������݃N���X���H
	public:
		//�^
		typedef STYLE arcStyle_t;//�A�[�J�C�u�`���^
	private:
		//�萔
		//�X�e�[�g
		enum stateEnum : int
		{
			st_SERIALIZE,//�V���A���C�Y��
			st_SERIALIZE_PHASE_BLOCK,//�V���A���C�Y�F�u���b�N�����t�F�[�Y
			st_SERIALIZE_PHASE_ARRAY,//�V���A���C�Y�F�z��u���b�N�����t�F�[�Y
			st_SERIALIZE_PHASE_ELEMENT,//�V���A���C�Y�F�v�f�����t�F�[�Y
			st_SERIALIZE_PHASE_SAVE_DATA,//�V���A���C�Y�F�f�[�^�̃Z�[�u�t�F�[�Y
			st_SERIALIZE_PHASE_COLLECT,//�V���A���C�Y�F���W�t�F�[�Y
			st_SERIALIZE_PHASE_COLLECT_END,//�V���A���C�Y�F���W�t�F�[�Y�I��
			st_SERIALIZE_END,//�V���A���C�Y�I��
		};
	private:
		//�A�N�Z�b�T
		stateEnum getState() const { return m_state; }//�X�e�[�g���擾
		stateEnum setState(const stateEnum state){ stateEnum prev = m_state; m_state = state; return prev; }//�X�e�[�g��ύX�@���ύX�O�̃X�e�[�g��Ԃ�
	public:
		//�I�y���[�^
		//�u&�v�I�y���[�^
		//���f�[�^���ڎw�聕�f�[�^�������ݗp����
		template<class T>
		COArchive& operator&(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return *this;

			//���ݏ������̃A�[�J�C�u�I�u�W�F�N�g
			COArchive& arc = *this;

			//printf("[operator&] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//st_SERIALIZE_PHASE_SAVE_DATA ���ȊO�ɂ��̏����ɗ���̂̓v���O�����ɊԈႢ������
			//�����W������ operator&() ���g���Ă��鎞�Ȃ�
			assert(arc.getState() == st_SERIALIZE_PHASE_SAVE_DATA);

			//������^��p����
			if (typeid(T) == typeid(serial::str_t))
			{
				if (item_obj.m_itemP)
				{
					//�����񒷂��i�[������
					*const_cast<std::size_t*>(&item_obj.m_itemSize) = strlen(reinterpret_cast<const char*>(item_obj.m_itemP)) + 1;
				}
				else
				{
					//�k������0��
					*const_cast<std::size_t*>(&item_obj.m_itemSize) = 0;
				}
			}

			//�f�[�^���ڂ��L�^
			//���d���`�F�b�N�̂���
			addItem(item_obj);
			
			//�f�[�^��������
			if (item_obj.isObj())
			{
				//�I�u�W�F�N�g�Ȃ� operator<<() �ŏ�������
				arc << item_obj;
			}
			else
			{
				//�f�[�^���A�[�J�C�u�ɋL�^
				arc.m_style.writeDataItem(arc, item_obj, item_obj);

				//�f�[�^�������ݍς�
				item_obj.setIsAlready();
			}
			
			return *this;
		}
		//�u<<�v�I�y���[�^
		//���f�[�^��������
		template<class T>
		COArchive& operator<<(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return *this;

			//���ݏ������̃A�[�J�C�u�I�u�W�F�N�g
			COArchive& arc = *this;

			//printf("[operator<<] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//st_SERIALIZE, st_SERIALIZE_PHASE_SAVE_DATA, st_SERIALIZE_PHASE_COLLECT ���ȊO��
			//���̏����ɗ���̂̓v���O�����ɊԈႢ������
			assert(arc.getState() == st_SERIALIZE ||
				arc.getState() == st_SERIALIZE_PHASE_SAVE_DATA ||
				arc.getState() == st_SERIALIZE_PHASE_COLLECT);

			//�I�u�W�F�N�g�łȂ���΃_��
			//����������̃V���A���C�Y�p�֐��I�u�W�F�N�g�����������^���H
			assert(item_obj.isObj() == true);

			//�l�X�g���x����0�Ȃ�V�O�l�`���[����������
			if (m_nestLevel == 0)
				arc.m_style.writeSignature(arc);//�V�O�l�`���[��������
	
			//�o�[�W�����擾
			CVersionDef<T> ver_def;
			CVersion ver(ver_def);

			//�u���b�N�J�n��񏑂�����
			arc.m_style.writeBlockHeader(arc, item_obj, ver);
			
			//�u���b�N�J�n
			std::size_t block_size = 0;//�u���b�N�̃T�C�Y
			
			{
				//�u���b�N�����p�̎q�A�[�J�C�u�I�u�W�F�N�g�𐶐�
				COArchive& parent_arc = arc;
				COArchive arc(parent_arc, st_SERIALIZE_PHASE_BLOCK);

				//�k���łȂ���Ώ�������
				if (!item_obj.isNul() && !arc.hasFatalError())
				{
					//�z��v�f���擾
					const std::size_t array_elem_num = item_obj.m_arrNum;
					
					//�z��u���b�N�J�n��񏑂�����
					arc.m_style.writeArrayHeader(arc, item_obj, array_elem_num);

					//�z��u���b�N�J�n
					std::size_t array_block_size = 0;//�z��u���b�N�̃T�C�Y

					{
						//�z��u���b�N�����p�̑��A�[�J�C�u�I�u�W�F�N�g�𐶐�
						COArchive& parent_arc = arc;
						COArchive arc(parent_arc, st_SERIALIZE_PHASE_ARRAY);

						//�f�[�^�������ݐ�̐擪�|�C���^�i�z��̐擪�j���L��
						//���z�񃋁[�v�������� item_obj.m_itemP ������������̂ŁA���ɖ߂���悤�ɂ��Ă���
						const void* item_p_top = item_obj.m_itemP;

						//�v�f���[�v
						const std::size_t loop_elem_num = item_obj.getElemNum();//�z��̗v�f���������́i�z�񂶂�Ȃ���΁j1��Ԃ�
						for (std::size_t index = 0; index < loop_elem_num && !arc.hasFatalError(); ++index)
						{
							//�v�f�J�n��񏑂�����
							arc.m_style.writeElemHeader(arc, item_obj, index);

							//�v�f�J�n
							short items_num = 0;//�f�[�^���ڐ�
							std::size_t elem_size = 0;//���̗v�f�̃f�[�^�T�C�Y
							{
								//�v�f�����p�̂Б��A�[�J�C�u�I�u�W�F�N�g�𐶐�
								COArchive& parent_arc = arc;
								COArchive arc(parent_arc, st_SERIALIZE_PHASE_ELEMENT);
								
								//�f�[�^�̃Z�[�u�t�F�[�Y�ɕύX
								arc.setState(st_SERIALIZE_PHASE_SAVE_DATA);

								//�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j�Ăяo��
								{
									serialize<COArchive, T> functor;
									functor(arc, item_obj.template getConst<T>(), ver, ver);
								}

								//�Z�[�u�����i�V���A���C�Y��p�����j�Ăяo��
								{
									save<COArchive, T> functor;
									functor(arc, item_obj.template getConst<T>(), ver);
								}

								//�v�f�I����񏑂�����
								//���Ⴆ�΁A�o�C�i���X�^�C���ł́A�v�f�̃w�b�_���Ƀf�[�^���ڐ��ƃf�[�^�T�C�Y���������݁A
								//�@�v�f�̍Ō�܂ŃV�[�N����
								arc.m_style.writeElemFooter(parent_arc, arc, item_obj, index, items_num, elem_size);

								//�v�f�I��
								//arc.m_style.finishWriteElem(parent_arc, arc, items_num, elem_size);

								//�f�[�^�������ݐ�̃|�C���^��z��̎��̗v�f�ɍX�V
								if (item_obj.m_itemP)
								{
									*const_cast<void**>(&item_obj.m_itemP) = reinterpret_cast<T*>(const_cast<void*>(item_obj.m_itemP)) + 1;
								}
							}
						}

						//�z��̐擪�|�C���^�i���̃|�C���^�j�ɖ߂�
						*const_cast<const void**>(&item_obj.m_itemP) = item_p_top;

						//�z��u���b�N�I����񏑂�����
						//���Ⴆ�΁A�o�C�i���X�^�C���ł́A�z��u���b�N�̃w�b�_���ɔz��v�f���ƃf�[�^�T�C�Y���������݁A
						//�@�v�f�̍Ō�܂ŃV�[�N����
						arc.m_style.writeArrayFooter(parent_arc, arc, item_obj, array_block_size);

						//�z��u���b�N�I��
						//arc.m_style.finishWriteArray(parent_arc, arc, array_block_size);
					}
				}

				//�f�[�^���W�����i�V���A���C�Y��p�����j�Ăяo��
				arc.setState(st_SERIALIZE_PHASE_COLLECT);
				{
					collector<COArchive, T> functor;
					functor(arc, item_obj.template getConst<T>(), ver);
				}
				arc.setState(st_SERIALIZE_PHASE_COLLECT_END);

				//�u���b�N�I����񏑂�����
				//���Ⴆ�΁A�o�C�i���X�^�C���ł́A�u���b�N�̃w�b�_���Ƀf�[�^�T�C�Y���������݁A
				//�@�u���b�N�̍Ō�܂ŃV�[�N����
				arc.m_style.writeBlockFooter(parent_arc, arc, item_obj, block_size);

				//�u���b�N�I��
				//arc.m_style.finishWriteBlock(parent_arc, arc, block_size);
			}

			//�l�X�g���x����0�Ȃ�^�[�~�l�[�^����������
			if (m_nestLevel == 0)
				arc.m_style.writeTerminator(arc);//�^�[�~�l�[�^��������
	
			//�f�[�^�������ݍς݂ɂ���
			item_obj.setIsAlready();

			//�������ʂɃZ�[�u�f�[�^�T�C�Y���Z�b�g����
			m_result.setSaveDataSize(getBuffUsed());

			//�ŏI�I�ɒv���I�ȃG���[������ΌĂяo��
			if (m_nestLevel == 0 && arc.hasFatalError())
			{
				fatalSerializeErrorOccurred<COArchive, T> functor;
				functor(arc, item_obj.template get<T>(), ver);
			}

			return *this;
		}
	public:
		//�R���X�g���N�^
		COArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(buff, buff_size, work_buff, work_buff_size),
			m_parent(nullptr),
			m_style(),
			m_state(st_SERIALIZE)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		COArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(buff, BUFF_SIZE, work_buff, WORK_SIZE),
			m_parent(nullptr),
			m_style(),
			m_state(st_SERIALIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		COArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(buff, buff_size, work_buff, WORK_SIZE),
			m_parent(nullptr),
			m_style(),
			m_state(st_SERIALIZE)
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		COArchive(COArchive& parent, const stateEnum state) :
			CIOArchiveBase(parent),
			m_parent(&parent),
			m_style(parent.m_style),
			m_state(state)
		{}
		//�f�X�g���N�^
		~COArchive()
		{}
	private:
		//�t�B�[���h
		COArchive* m_parent;//�e�A�[�J�C�u�I�u�W�F�N�g
		arcStyle_t m_style;//�A�[�J�C�u�X�^�C���I�u�W�F�N�g
		stateEnum m_state;//�X�e�[�g
	};
	//--------------------
	//�A�[�J�C�u�ǂݍ��݃N���X
	template<class STYLE>
	class CIArchive : public CIOArchiveBase
	{
	public:
		//�萔
		static const bool is_read = true;//�ǂݍ��݃N���X���H
		static const bool is_write = false;//�������݃N���X���H
	public:
		//�^
		typedef STYLE arcStyle_t;//�A�[�J�C�u�`���^
	private:
		//�萔
		//�X�e�[�g
		enum stateEnum : int
		{
			st_DESERIALIZE,//�f�V���A���C�Y��
			st_DESERIALIZE_PHASE_BLOCK,//�V���A���C�Y�F�u���b�N�����t�F�[�Y
			st_DESERIALIZE_PHASE_ARRAY,//�V���A���C�Y�F�z��u���b�N�����t�F�[�Y
			st_DESERIALIZE_PHASE_ELEMENT,//�V���A���C�Y�F�v�f�����t�F�[�Y
			st_DESERIALIZE_PHASE_BEFORE_LOAD,//�f�V���A���C�Y�F���[�h�O�����t�F�[�Y
			st_DESERIALIZE_PHASE_MAKE_LIST,//�f�V���A���C�Y�F�Ώۃf�[�^���ڃ��X�g�쐬�t�F�[�Y
			st_DESERIALIZE_PHASE_LOAD_DATA,//�f�V���A���C�Y�F�f�[�^�̃��[�h�t�F�[�Y
			st_DESERIALIZE_PHASE_LOAD_OBJECT,//�f�V���A���C�Y�F�I�u�W�F�N�g�̃��[�h�t�F�[�Y
			st_DESERIALIZE_PHASE_LOAD_OBJECT_END,//�f�V���A���C�Y�F�I�u�W�F�N�g�̃��[�h�t�F�[�Y�I��
			st_DESERIALIZE_PHASE_NOTICE_UNRECOGNIZED,//�f�V���A���C�Y�F�F���ł��Ȃ������f�[�^���ڂ̒ʒm�t�F�[�Y
			st_DESERIALIZE_PHASE_NOTICE_UNLOADED,//�f�V���A���C�Y�F���[�h�ł��Ȃ������f�[�^���ڂ̒ʒm�t�F�[�Y
			st_DESERIALIZE_PHASE_AFTEER_LOAD,//�f�V���A���C�Y�F���[�h�㏈���t�F�[�Y
			st_DESERIALIZE_PHASE_BEFORE_DISTRIBUTE,//�f�V���A���C�Y�F���z�O�t�F�[�Y
			st_DESERIALIZE_PHASE_DISTRIBUTE,//�f�V���A���C�Y�F���z�t�F�[�Y
			st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT,//�f�V���A���C�Y�F�I�u�W�F�N�g�̕��z�t�F�[�Y
			st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END,//�f�V���A���C�Y�F�I�u�W�F�N�g�̕��z�t�F�[�Y�I��
			st_DESERIALIZE_PHASE_AFTER_DISTRIBUTE,//�f�V���A���C�Y�F���z��t�F�[�Y
			st_DESERIALIZE_END,//�f�V���A���C�Y�I��
		};
	private:
		//�A�N�Z�b�T
		stateEnum getState() const { return m_state; }//�X�e�[�g���擾
		stateEnum setState(const stateEnum state){ stateEnum prev = m_state; m_state = state; return prev; }//�X�e�[�g��ύX�@���ύX�O�̃X�e�[�g��Ԃ�
		CItemBase* getTargetObjItem(){ return m_targetObjItem; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ��Z�b�g
		const CItemBase* getTargetObjItem() const { return m_targetObjItem; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ��Z�b�g
		void setTargetObjItem(CItemBase& item){ m_targetObjItem = &item; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ��Z�b�g
		void resetTargetObjItem(){ m_targetObjItem = nullptr; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ����Z�b�g
		CItemBase* getTargetObjItemDelegate(){ return m_targetObjItemDelegate; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ̈Ϗ��f�[�^���ڂ��Z�b�g
		const CItemBase* getTargetObjItemDelegate() const { return m_targetObjItemDelegate; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ̈Ϗ��f�[�^���ڂ��Z�b�g
		void setTargetObjItemDelegate(CItemBase* item){ m_targetObjItemDelegate = item; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ̈Ϗ��f�[�^���ڂ��Z�b�g
		void resetTargetObjItemDelegate(){ m_targetObjItemDelegate = nullptr; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ̈Ϗ��f�[�^���ڂ����Z�b�g
	public:
		//�I�y���[�^
		//�u&�v�I�y���[�^
		//���f�[�^���ڎw��p����
		template<class T>
		CIArchive& operator&(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return *this;

			//���ݏ������̃A�[�J�C�u�I�u�W�F�N�g
			CIArchive& arc = *this;

			//printf("[operator&] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//st_DESERIALIZE_PHASE_MAKE_LIST, st_DESERIALIZE_PHASE_LOAD_OBJECT,
			//st_DESERIALIZE_PHASE_LOAD_OBJECT_END ���ȊO�ɂ��̏����ɗ���̂̓v���O�����ɊԈႢ������
			//�����[�h�O�����⃍�[�h�㏈���A�ʒm�����A���z������ operator&() ���g���Ă��鎞�Ȃ�
			assert(arc.getState() == st_DESERIALIZE_PHASE_MAKE_LIST ||
				arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT ||
				arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT_END ||
				arc.getState() == st_DESERIALIZE_PHASE_NOTICE_UNRECOGNIZED);

			//�I�u�W�F�N�g�������[�h�I�����͂Ȃɂ����Ȃ�
			if (arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
			{
				return *this;
			}
			//�I�u�W�F�N�g�������[�h���͑Ώۃf�[�^���ڂ̂ݏ�������
			else if (arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT)
			{
				if (*m_targetObjItem == item_obj)
				{
					arc >> item_obj;//�I�u�W�F�N�g�ǂݍ���
					arc.setState(st_DESERIALIZE_PHASE_LOAD_OBJECT_END);//�I�u�W�F�N�g�������[�h�I��
				}
				return *this;
			}
			//�F���ł��Ȃ������I�u�W�F�N�g�̒ʒm���[�h���͈Ϗ��f�[�^���ڂ��Z�b�g���ďI������
			else if (arc.getState() == st_DESERIALIZE_PHASE_NOTICE_UNRECOGNIZED)
			{
				if (m_targetObjItemDelegate)
				{
					m_targetObjItemDelegate->copyForce(item_obj);
				}
				return *this;
			}

			//��U�́u�Z�[�u�f�[�^�ɑ��݂��Ȃ��f�[�^���ځv�Ƃ��������ɂ��Ă���
			//�����[�h�I��������̂܂܂Ȃ烍�[�h�ł��Ȃ������f�[�^���ڂƂ��ď�������
			item_obj.setIsOnlyOnMem();
			
			//�f�[�^���ڂ��L�^
			//���S�Ă̋L�^���I�������A�f�[�^��ǂݍ��݂Ȃ���f�[�^���ڂɏ�������ł���
			addItem(item_obj);
			
			return *this;
		}
		
		//�u>>�v�I�y���[�^
		//���f�[�^�ǂݍ���
		template<class T>
		CIArchive& operator>>(CItem<T> item_obj_now)
		{
			if (m_result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return *this;

			//���ݏ������̃A�[�J�C�u�I�u�W�F�N�g
			CIArchive& arc = *this;

			//printf("[operator>>] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj_now.m_name, item_obj_now.m_nameCrc, item_obj_now.m_itemType->name(), item_obj_now.m_itemP, item_obj_now.m_itemSize, item_obj_now.m_arrNum, item_obj_now.isObj(), item_obj_now.isArr(), item_obj_now.isPtr(), item_obj_now.isNul(), item_obj_now.isOnlyOnMem(), item_obj_now.isOnlyOnSaveData());

			//st_DESERIALIZE, st_DESERIALIZE_PHASE_MAKE_LIST, st_DESERIALIZE_PHASE_LOAD_DATA,
			//st_DESERIALIZE_PHASE_LOAD_OBJECT,st_DESERIALIZE_PHASE_LOAD_OBJECT_END ���ȊO��
			//���̏����ɗ���̂̓v���O�����ɊԈႢ������
			//�����[�h�O�����⃍�[�h�㏈���A�ʒm�����A���z������ operator&() ���g���Ă��鎞�Ȃ�
			assert(arc.getState() == st_DESERIALIZE ||
				arc.getState() == st_DESERIALIZE_PHASE_MAKE_LIST ||
				arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT ||
				arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT_END ||
				arc.getState() == st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT ||
				arc.getState() == st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END);

			//�f�[�^���ڃ��g���C�����˃u���b�N�ǂݍ��݂̂��߂̈Ϗ��f�[�^���ڂ�����
			CItemBase* delebate_item = nullptr;

			//�Ώۃf�[�^���ڃ��X�g�쐬�t�F�[�Y���Ȃ� operator&() �ɏ�������
			if (arc.getState() == st_DESERIALIZE_PHASE_MAKE_LIST)
			{
				return *this & item_obj_now;
			}
			//�I�u�W�F�N�g�������[�h���͈Ϗ��f�[�^���ڂ��擾����
			else if (arc.getState() == st_DESERIALIZE_PHASE_LOAD_OBJECT)
			{
				//�Ϗ��f�[�^���ڂ��擾
				delebate_item = m_targetObjItemDelegate;
			}
			//���z�I�u�W�F�N�g�������[�h�I�����͂Ȃɂ����Ȃ�
			else if (arc.getState() == st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END)
			{
				return *this;
			}
			//���z�I�u�W�F�N�g���[�h���͑Ώۃf�[�^���ڂ̂ݏ�������
			else if (arc.getState() == st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT)
			{
				if (*m_targetObjItem == item_obj_now)
				{
					//�I�u�W�F�N�g�������[�h�I����Ԃɂ��ď������s
					arc.setState(st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END);
				}
			}

			//�p�����[�^�`�F�b�N
			//assert(!item_obj_now.isOnlyOnSaveData());
			//���Z�[�u�f�[�^�ɂ������݂��Ȃ��f�[�^�͏����s��
			//���z�M�������ԈႦ�Ĉȓ�����A���̂悤�ȏ�Ԃɂ͂Ȃ�Ȃ��͂�

			//�l�X�g���x����0�Ȃ�p�[�X
			if (m_nestLevel == 0)
				arc.m_style.parse(arc);//�p�[�X
			
			//�l�X�g���x����0�Ȃ�V�O�l�`���[��ǂݍ���
			if (m_nestLevel == 0)
				arc.m_style.readSignature(arc);//�V�O�l�`���[�ǂݍ���
			
			//�o�[�W�����擾
			CVersionDef<T> now_ver_def;
			CVersion now_ver(now_ver_def);//���݂̃o�[�W����
			CVersion ver;//�ǂݍ��ݗp�̃o�[�W����
			//�u���b�N�J�n���ǂݍ���
			std::size_t block_size = 0;
			CItem<T> item_obj(item_obj_now);
			arc.m_style.readBlockHeader(arc, item_obj_now, delebate_item, now_ver, item_obj, ver, block_size);
			//printf("  readDataItem:name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d\n", item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul());

			//�u���b�N�J�n
			{
				//�u���b�N�����p�̎q�A�[�J�C�u�I�u�W�F�N�g�𐶐�
				CIArchive& parent_arc = arc;
				CIArchive arc(parent_arc, st_DESERIALIZE_PHASE_BLOCK);
				
				//�W�v����
				const std::size_t elem_num = item_obj.getElemNum();//�v�f���i�z��v�f�ł͂Ȃ��A��z��Ȃ�1�j
				std::size_t elem_num_loaded = 0;//���ۂɓǂݍ��񂾗v�f���i�z��v�f�ł͂Ȃ��A��z��Ȃ�1�j
				
				if (!item_obj.isNul() && !arc.hasFatalError())//�y�Z�[�u�f�[�^��́z�v�f���k���łȂ���Ώ�������
				{

					//�z��u���b�N�J�n���ǂݍ���
					std::size_t array_elem_num = 0;//�z��v�f��
					std::size_t array_block_size = 0;//�z��u���b�N�T�C�Y
					arc.m_style.readArrayHeader(arc, item_obj, array_elem_num, array_block_size);

					//�z��u���b�N�J�n
					{
						//�z��u���b�N�����p�̑��A�[�J�C�u�I�u�W�F�N�g�𐶐�
						CIArchive& parent_arc = arc;
						CIArchive arc(parent_arc, st_DESERIALIZE_PHASE_ARRAY);

						//�f�[�^�ǂݍ��ݐ�̐擪�|�C���^�i�z��̐擪�j���L��
						//���z�񃋁[�v�������� item_obj.m_itemP ������������̂ŁA���ɖ߂���悤�ɂ��Ă���
						const void* item_p_top = item_obj.m_itemP;

						//�z�񃋁[�v
						//�����[�v�I����������� index < elem_num �͊܂߂Ȃ�
						//�@�i�A�[�J�C�u�X�^�C���ɂ���Ă͎��O�ɐ��m�Ȕz��v�f���������Ȃ��\�������邽�߁j
						for (std::size_t index = 0; !arc.hasFatalError(); ++index)//�y�Z�[�u�f�[�^��́z�z��v�f�����f�[�^�ǂݍ���
						{
							if (!item_obj.isArr())
							{
								//��z��v�f�̏I������
								if (index == 1)
									break;
							}
							else
							{
								//�z��u���b�N�I������
								bool is_array_block_end = true;
								arc.m_style.tryAndReadArrayFooter(arc, item_obj, is_array_block_end);
								if (is_array_block_end)
									break;//�z��u���b�N�̏I�������o�����烋�[�v���甲����
							}

							//�f�o�b�O�p�̕ϐ��L���X�g
							const T* debug_p = reinterpret_cast<const T*>(item_obj.m_itemP);

							//�L���Ȕz��v�f���H�i�L���łȂ���Ώ��������ǂݍ��ނ����j
							const bool is_valid_element = (!item_obj.nowIsNul() && index < item_obj.getNowElemNum());
							if (is_valid_element)
								++elem_num_loaded;

							//�v�f�J�n���ǂݍ���
							std::size_t elem_size = 0;
							short items_num = 0;
							arc.m_style.readElemHeader(arc, item_obj, index, items_num, elem_size);

							//�v�f�J�n
							{
								//�V�����A�[�J�C�u�I�u�W�F�N�g�𐶐�
								CIArchive& parent_arc = arc;
								CIArchive arc(parent_arc, st_DESERIALIZE_PHASE_ELEMENT);

								//���[�h�O�����t�F�[�Y�ɕύX
								arc.setState(st_DESERIALIZE_PHASE_BEFORE_LOAD);

								//���[�h�O�����i�f�V���A���C�Y��p�����j�Ăяo��
								if (is_valid_element)
								{
									beforeLoad<CIArchive, T> functor;
									functor(arc, item_obj.template get<T>(), ver, now_ver);
								}

								//�Ώۃf�[�^���ڃ��X�g�쐬�t�F�[�Y�ɕύX
								arc.setState(st_DESERIALIZE_PHASE_MAKE_LIST);

								//�f�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j�Ăяo��
								//���f�[�^���ڃ��X�g���L�^���邾��
								if (is_valid_element)
								{
									serialize<CIArchive, T> functor;
									functor(arc, item_obj.template getConst<T>(), ver, now_ver);
								}

								//���[�h�����i�f�V���A���C�Y��p�����j�Ăяo��
								//���f�[�^���ڃ��X�g���L�^���邾��
								if (is_valid_element)
								{
									load<CIArchive, T> functor;
									functor(arc, item_obj.template get<T>(), ver, now_ver);
								}

								//�f�[�^�̃��[�h�t�F�[�Y�ɕύX
								arc.setState(st_DESERIALIZE_PHASE_LOAD_DATA);

								//���ۂ̃��[�h����
								//�����[�v�I����������� item_idx < items_num �͊܂߂Ȃ�
								//�@�i�A�[�J�C�u�X�^�C���ɂ���Ă͎��O�ɐ��m�ȍ��ڐ��������Ȃ��\�������邽�߁j
								for (short item_idx = 0; !arc.hasFatalError(); ++item_idx)
								{
									//�v�f�I�����ǂݍ���
									bool is_elem_end = true;
									arc.m_style.tryAndReadElemFooter(arc, item_obj, index, is_elem_end);
									if (is_elem_end)
										break;//�v�f�̏I�������o�����烋�[�v���甲����

									bool is_init = true;//���񏈗�
									bool is_required_retry = false;//���g���C�����v��
									bool is_already_retry = false;//���g���C�����ς�
									CItemBase delegate_child_item_for_retry;//���g���C�p�̈Ϗ����ځi���́j
									CItemBase* delegate_child_item_now = nullptr;//���g���C�p�̈Ϗ�����
									while (is_init || (is_required_retry && !is_already_retry))//���g���C�͈�񂾂��L��
									{
										is_init = false;//���񏈗��I��
										if (is_required_retry)//���g���C��
											is_already_retry = true;//���g���C�ς݂ɂ���i���g���C�͈�񂾂��j

										//�v�f�̓ǂݍ���
										CItemBase child_item;
										arc.m_style.readDataItem(arc, item_obj, delegate_child_item_now, child_item, is_valid_element, is_required_retry);

										//���[�h�������ۑ���̎w�肪�Ȃ��������ڂ̏���
										//�����Ƀ��g���C���Ă���ꍇ�͎��s���Ȃ�
										if (child_item.isOnlyOnSaveData() && !is_already_retry)
										{
											//�ʒm�t�F�[�Y�ɕύX
											arc.setState(st_DESERIALIZE_PHASE_NOTICE_UNRECOGNIZED);

											//�ʒm
											if (is_valid_element)
											{
												//�Ϗ��f�[�^���ڂ̎󂯎��p�ɃC���X�^���X���Z�b�g
												arc.setTargetObjItemDelegate(&delegate_child_item_for_retry);

												//�ʒm�����Ăяo��
												noticeUnrecognizedItem<CIArchive, T> functor;
												functor(arc, item_obj.template get<T>(), ver, now_ver, child_item);

												//�Ϗ��f�[�^���ڂ̎󂯎��I��
												arc.resetTargetObjItemDelegate();

												//�Ϗ��f�[�^���ڂ̎󂯎���Ԃ𔻒�
												if (delegate_child_item_for_retry.m_nameCrc != 0 && delegate_child_item_for_retry.m_itemP)
												{
													//�Ϗ��f�[�^���ڂ��ݒ肳�ꂽ�̂Ń��g���C
													delegate_child_item_now = &delegate_child_item_for_retry;
													is_required_retry = true;
												}
											}

											//�f�[�^�̃��[�h�t�F�[�Y�ɖ߂�
											arc.setState(st_DESERIALIZE_PHASE_LOAD_DATA);

											//���g���C
											//���I�u�W�F�N�g�̏����ɓ���O�Ƀ��g���C�����s
											if (is_required_retry)
												continue;
										}

										//�I�u�W�F�N�g�̏ꍇ�̏���
										if (child_item.isObj())
										{
											//�I�u�W�F�N�g�̃��[�h�t�F�[�Y�ɕύX
											arc.setState(st_DESERIALIZE_PHASE_LOAD_OBJECT);

											//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ��Z�b�g
											arc.setTargetObjItem(child_item);
											arc.setTargetObjItemDelegate(delegate_child_item_now);

											//�ʒm�����Ăяo��
											//���Ϗ��f�[�^���ڂ��Z�b�g����Ă��鎞�̂�
											//if (arc.getState() != st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
											if (delegate_child_item_now)
											{
												noticeUnrecognizedItem<CIArchive, T> functor;
												functor(arc, item_obj.template get<T>(), ver, now_ver, child_item);
											}

											//�f�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j�Ăяo��
											//���ΏۃI�u�W�F�N�g�A�C�e������������
											if (arc.getState() != st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
											{
												serialize<CIArchive, T> functor;
												functor(arc, item_obj.template getConst<T>(), ver, now_ver);
											}

											//���[�h�����i�f�V���A���C�Y��p�����j�Ăяo��
											//���ΏۃI�u�W�F�N�g�A�C�e������������
											if (arc.getState() != st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
											{
												load<CIArchive, T> functor;
												functor(arc, item_obj.template get<T>(), ver, now_ver);
											}

											//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ����Z�b�g
											arc.resetTargetObjItem();
											arc.resetTargetObjItemDelegate();
											delegate_child_item_now = nullptr;

											//�������̂܂܂�������u���b�N���X�L�b�v����
											if (arc.getState() != st_DESERIALIZE_PHASE_LOAD_OBJECT_END)
											{
												//�I�u�W�F�N�g�̃u���b�N���X�L�b�v
												arc.m_style.skipReadBlock(arc);

												//�����ς݂ɂ���
												child_item.setIsAlready();
											}

											//�f�[�^�̃��[�h�t�F�[�Y�ɖ߂�
											arc.setState(st_DESERIALIZE_PHASE_LOAD_DATA);
										}
									}
									//���g���C�p�̈Ϗ����ڃ��Z�b�g
									delegate_child_item_now = nullptr;
								}

								//��������Ȃ������f�[�^���ڂ̏���
								for (auto& pair : *arc.m_itemList)
								{
									const CItemBase& child_item = pair.second;
									//�ۑ���̎w�肪���邪�A�Z�[�u�f�[�^�ɂȂ����[�h�ł��Ȃ���������
									if (child_item.isOnlyOnMem())
									{
										//�ʒm�t�F�[�Y�ɕύX
										arc.setState(st_DESERIALIZE_PHASE_NOTICE_UNLOADED);

										//�������ʌv��
										arc.getResult().addResult(child_item);

										//�ʒm�����Ăяo��
										if (is_valid_element)
										{
											noticeUnloadedItem<CIArchive, T> functor;
											functor(arc, item_obj.template get<T>(), ver, now_ver, child_item);
										}
									}
								}

								//���[�h�㏈���t�F�[�Y�ɕύX
								arc.setState(st_DESERIALIZE_PHASE_AFTEER_LOAD);

								//���[�h�㏈���i�f�V���A���C�Y��p�����j�Ăяo��
								if (is_valid_element)
								{
									afterLoad<CIArchive, T> functor;
									functor(arc, item_obj.template get<T>(), ver, now_ver);
								}

								//�v�f�I��
								arc.m_style.finishReadElem(parent_arc, arc);
							}

							//�f�[�^�ǂݍ��ݐ�̃|�C���^��z��̎��̗v�f�ɍX�V
							if (item_obj.m_itemP)
							{
								*const_cast<void**>(&item_obj.m_itemP) = reinterpret_cast<T*>(const_cast<void*>(item_obj.m_itemP)) + 1;
							}
						}

						//�z��̐擪�|�C���^�i���̃|�C���^�j�ɖ߂�
						item_obj.m_itemP = item_p_top;

						//�z��u���b�N�I��
						arc.m_style.finishReadArray(parent_arc, arc);
					}
				}
					
				//���z�O�t�F�[�Y�ɕύX
				arc.setState(st_DESERIALIZE_PHASE_BEFORE_DISTRIBUTE);

				//���z�O�����i�f�V���A���C�Y��p�����j�Ăяo��
				{
					beforeDistribute<CIArchive, T> functor;
					functor(arc, item_obj.template get<T>(), elem_num, elem_num_loaded, ver, now_ver);
				}

				//���z�t�F�[�Y�ɕύX
				arc.setState(st_DESERIALIZE_PHASE_DISTRIBUTE);

				//���z�����i�f�V���A���C�Y��p�����j�Ăяo��
				while (!arc.hasFatalError())
				{
					//�u���b�N�I������
					bool is_block_end = true;
					arc.m_style.tryAndReadBlockFooter(arc, item_obj, is_block_end);
					if (is_block_end)
						break;//�u���b�N�̏I�������o�����烋�[�v���甲����

					//�I�u�W�F�N�g�u���b�N�J�n
					{
						//�I�u�W�F�N�g�u���b�N�����p�̎q�A�[�J�C�u�I�u�W�F�N�g�𐶐�
						CIArchive& parent_arc = arc;
						CIArchive arc(parent_arc, st_DESERIALIZE_PHASE_DISTRIBUTE);

						//�u���b�N�J�n�������ǂ݂��A���z�����ɉ�
						CItemBase require_item;
						std::size_t require_block_size = 0;
						bool is_found_next_block = false;
						arc.m_style.requireNextBlockHeader(arc, require_item, require_block_size, is_found_next_block);
						if (!is_found_next_block)
							break;//�u���b�N��������Ȃ������ꍇ�����[�v���甲����i���肦�Ȃ��H�j

						//�I�u�W�F�N�g���z�����t�F�[�Y�ɕύX
						arc.setState(st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT);

						//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ��Z�b�g
						arc.setTargetObjItem(require_item);

						//���z�����i�f�V���A���C�Y��p�����j�Ăяo��
						{
							distributor<CIArchive, T> functor;
							functor(arc, item_obj.template get<T>(), elem_num, elem_num_loaded, ver, now_ver, require_item);
						}

						//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ����Z�b�g
						arc.resetTargetObjItem();

						//�������̂܂܂�������u���b�N���X�L�b�v����
						if (arc.getState() != st_DESERIALIZE_PHASE_DISTRIBUTE_OBJECT_END)
						{
							//�I�u�W�F�N�g�̃u���b�N���X�L�b�v
							arc.m_style.skipReadBlock(arc);

							//�����ς݂ɂ���
							require_item.setIsAlready();
						}

						//�I�u�W�F�N�g�u���b�N�I��
						arc.m_style.finishReadBlock(parent_arc, arc);
					}
				}

				//���z��t�F�[�Y�ɕύX
				arc.setState(st_DESERIALIZE_PHASE_AFTER_DISTRIBUTE);

				//���z�㏈���i�f�V���A���C�Y��p�����j�Ăяo��
				{
					afterDistribute<CIArchive, T> functor;
					functor(arc, item_obj.template get<T>(), elem_num, elem_num_loaded, ver, now_ver);
				}

				//�u���b�N�I��
				arc.m_style.finishReadBlock(parent_arc, arc);
			}
			
			//�l�X�g���x����0�Ȃ�^�[�~�l�[�^��ǂݍ���
			if (m_nestLevel == 0)
				arc.m_style.readTerminator(arc);//�^�[�~�l�[�^�ǂݍ���
	
			//�������ʂɃZ�[�u�f�[�^�T�C�Y���Z�b�g����
			m_result.setSaveDataSize(getBuffUsed());

			//�ŏI�I�ɒv���I�ȃG���[������ΌĂяo��
			if (m_nestLevel == 0 && arc.hasFatalError())
			{
				fatalDeserializeErrorOccurred<CIArchive, T> functor;
				functor(arc, item_obj.template get<T>(), ver, now_ver);
			}
			
			return *this;
		}
	public:
		//�R���X�g���N�^
		CIArchive(const void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(const_cast<void*>(buff), buff_size, work_buff, work_buff_size),
			m_style(),
			m_state(st_DESERIALIZE),
			m_parent(nullptr),
			m_targetObjItem(nullptr),
			m_targetObjItemDelegate(nullptr)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(const BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(const_cast<BUFF_T*>(&buff[0]), BUFF_SIZE, work_buff, WORK_SIZE),
			m_style(),
			m_state(st_DESERIALIZE),
			m_parent(nullptr),
			m_targetObjItem(nullptr),
			m_targetObjItemDelegate(nullptr)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(const void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(const_cast<void*>(buff), buff_size, work_buff, WORK_SIZE),
			m_parent(nullptr),
			m_style(),
			m_state(st_DESERIALIZE),
			m_targetObjItem(nullptr),
			m_targetObjItemDelegate(nullptr)
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		CIArchive(CIArchive& parent, const stateEnum state) :
			CIOArchiveBase(parent),
			m_parent(&parent),
			m_style(parent.m_style),
			m_state(state),
			m_targetObjItem(nullptr),
			m_targetObjItemDelegate(nullptr)
		{}
		//�f�X�g���N�^
		~CIArchive()
		{}
	private:
		//�t�B�[���h
		CIArchive* m_parent;//�e�A�[�J�C�u�I�u�W�F�N�g
		arcStyle_t m_style;//�A�[�J�C�u�X�^�C���I�u�W�F�N�g
		stateEnum m_state;//�X�e�[�g
		CItemBase* m_targetObjItem;//�I�u�W�F�N�g�����̑Ώۃf�[�^����
		CItemBase* m_targetObjItemDelegate;//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ̈Ϗ��f�[�^����
	};
	//--------------------
	//�A�[�J�C�u�ǂݏ�����{����w���p�[�N���X
	class CIOArchiveHelper
	{
	public:
		CResult& getResult(){ return m_arc.getResult(); }//�������ʂ��擾
		const CResult& getResult() const { return m_arc.getResult(); }//�������ʂ��擾
		bool hasFatalError() const { return m_arc.hasFatalError(); }//�v���I�ȃG���[���肩�H
		const byte* getBuffPtr() const { return m_arc.getBuffPtr(); }//�Z�[�u�f�[�^�o�b�t�@�̐擪�|�C���^���擾
		const std::size_t getBuffSize() const { return m_arc.getBuffSize(); }//�Z�[�u�f�[�^�o�b�t�@�̃T�C�Y���擾
		const std::size_t getBuffUsed() const { return m_arc.getBuffUsed(); }//�Z�[�u�f�[�^�o�b�t�@�̎g�p�ʂ��擾
		const std::size_t getBuffPos() const { return m_arc.getBuffPos(); }//�Z�[�u�f�[�^�o�b�t�@�̌��݈ʒu���擾
		const std::size_t getBuffRemain() const { return m_arc.getBuffRemain(); }//�Z�[�u�f�[�^�o�b�t�@�̎c�ʂ��擾
		byte* getBuffNowPtr(){ return m_arc.getBuffNowPtr(); }//�Z�[�u�f�[�^�o�b�t�@�̌��݈ʒu�̃|�C���^���擾
		bool buffIsFull() const { return m_arc.buffIsFull(); }//�o�b�t�@�̌��݈ʒu�����[�ɓ��B�������H
		std::size_t getItemListNum() const { return m_arc.getItemListNum(); }//�f�[�^���ڃ��X�g
	public:
		//���\�b�h
		//�������ʂ�����
		void addResult(const CResult& src){ m_arc.addResult(src); }
		//���X�g����f�[�^���ڂ�����
		const CItemBase* findItem(const crc32_t name_crc) const	{ return m_arc.findItem(name_crc); }
		//�o�b�t�@�̃J�����g�|�C���^���ړ�
		//���͈͊O�ւ̈ړ����v�����ꂽ��[�܂ňړ����� false ��Ԃ�
		bool seek(const int seek_, int& real_seek)
		{
			const int used = static_cast<int>(m_arc.m_buffPos);
			const int remain = static_cast<int>(m_arc.getBuffRemain());
			real_seek = seek_ < 0 ?
				used >(-seek_) ?
			seek_ :
				  -used :
				  remain > seek_ ?
			  seek_ :
					remain;
			m_arc.m_buffPos = static_cast<std::size_t>(used + real_seek);
			return real_seek == seek_;
		}
		//���������ʃI�u�W�F�N�g�g�p��
		bool seek(CResult& result, const int seek_)
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			int real_seek = 0;
			//�J�����g�|�C���^�ړ�
			const bool result_now = seek(seek_, real_seek);
			//�������ʋL�^
			if (!result_now)
				result.setHasFatalError();
			return result_now;
		}
	protected:
		//�R���X�g���N�^
		CIOArchiveHelper(CIOArchiveBase& arc) :
			m_arc(arc)
		{}
		//�f�X�g���N�^
		~CIOArchiveHelper()
		{}
	protected:
		//�t�B�[���h
		CIOArchiveBase& m_arc;//�A�[�J�C�u�I�u�W�F�N�g�i�Z�[�u�f�[�^�C���[�W�o�b�t�@�j
	};
	//--------------------
	//�A�[�J�C�u�������݊�{����w���p�[�N���X
	class COArchiveHelper : public CIOArchiveHelper
	{
		template<class STYLE>
		friend class COArchive;
	public:
		//���\�b�h
		//�o�b�t�@�ւ̃f�[�^��������
		//���v���T�C�Y���S�ď������߂Ȃ������� false ��Ԃ�
		bool write(const void* data, const std::size_t size, std::size_t& written_size)
		{
			const std::size_t remain = m_arc.getBuffRemain();
			written_size = remain > size ? size : remain;
			if (data)//�f�[�^���k���Ȃ�T�C�Y��0�Ŗ��߂�
				memcpy(m_arc.m_buff + m_arc.m_buffPos, data, written_size);
			else//�f�[�^�R�s�[
				memset(m_arc.m_buff + m_arc.m_buffPos, 0, written_size);
			m_arc.m_buffPos += written_size;
			return written_size == size;
		}
		//���������ʃI�u�W�F�N�g�g�p��
		bool write(CResult& result, const void* data, const std::size_t size, std::size_t* written_size = nullptr)
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//�f�[�^��������
			std::size_t written_size_tmp = 0;
			const bool result_now = write(data, size, written_size_tmp);
			//�������ʋL�^
			result.addCopiedSize(written_size_tmp);
			if (!result_now)
				result.setHasFatalError();
			if (written_size)
				*written_size += written_size_tmp;
			return result_now;
		}
		//�o�b�t�@�ւ̕����񏑂�����
		std::size_t print(CResult& result, const char* fmt, ...)
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			const std::size_t remain = m_arc.getBuffRemain();
			va_list args;
			va_start(args, fmt);
		#ifdef USE_STRCPY_S
			const std::size_t ret = vsprintf_s(reinterpret_cast<char*>(m_arc.m_buff + m_arc.m_buffPos), remain, fmt, args);
		#else//USE_STRCPY_S
			const std::size_t ret = vsprintf(reinterpret_cast<char*>(m_arc.m_buff + m_arc.m_buffPos), fmt, args);
		#endif//USE_STRCPY_S
			va_end(args);
			m_arc.m_buffPos += ret;
			return ret;
		}
		//�o�b�t�@�ւ̕����񏑂�����
		std::size_t printWithFunc(CResult& result, toStrFuncP to_str_func, const void* data_p, const std::size_t data_size)
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			const std::size_t remain = m_arc.getBuffRemain();
			const std::size_t ret = to_str_func(reinterpret_cast<char*>(m_arc.m_buff + m_arc.m_buffPos), remain, data_p, data_size);
			m_arc.m_buffPos += ret;
			return ret;
		}
		//�o�b�t�@�ւ̃C���f���g��������
		void printIndent(CResult& result, const int add)
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return;
			const int remain = static_cast<int>(m_arc.getBuffRemain());
			int space_len = (static_cast<int>(m_arc.m_nestLevel) + add) * 2 + 1;
			space_len = space_len > 0 ? space_len : 0;
			space_len = space_len < remain ? space_len : remain;
			if (space_len >= 1)
			{
				memset(m_arc.m_buff + m_arc.m_buffPos, ' ', space_len);
				m_arc.m_buffPos += space_len;
				*(m_arc.m_buff + m_arc.m_buffPos) = '\0';
			}
		}
	public:
		//�R���X�g���N�^
		COArchiveHelper(CIOArchiveBase& arc) :
			CIOArchiveHelper(arc)
		{}
		//�f�X�g���N�^
		~COArchiveHelper()
		{}
	};
	//--------------------
	//�A�[�J�C�u�ǂݍ��݊�{����w���p�[�N���X
	class CIArchiveHelper : public CIOArchiveHelper
	{
		template<class STYLE>
		friend class CIArchive;
	public:
		//���\�b�h
		//�o�b�t�@����̃f�[�^�ǂݍ���
		//���v���T�C�Y���S�ď������߂Ȃ������� false ��Ԃ�
		bool read(void* data, const std::size_t size, std::size_t& read_size)
		{
			const std::size_t remain = m_arc.getBuffRemain();
			read_size = remain > size ? size : remain;
			if (data)//data���k���Ȃ�R�s�[���Ȃ����|�C���^�͐i�߂�
				memcpy(data, m_arc.m_buff + m_arc.m_buffPos, read_size);
			m_arc.m_buffPos += read_size;
			return read_size == size;
		}
		//���������ʃI�u�W�F�N�g�g�p��
		bool read(CResult& result, void* data, const std::size_t size, std::size_t* read_size = nullptr)
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//�f�[�^�ǂݍ���
			std::size_t read_size_tmp = 0;
			const bool result_now = read(data, size, read_size_tmp);
			//�������ʋL�^
			if (!result_now)
				result.setHasFatalError();
			if (read_size)
				*read_size += read_size_tmp;
			return result_now;
		}
		//�o�b�t�@����̃f�[�^�ǂݍ���
		//���v���T�C�Y���S�ď������߂Ȃ������� false ��Ԃ�
		bool readWithFunc(fromMemFuncP from_mem_func, void* data, const std::size_t dst_size, const std::size_t src_size, std::size_t& read_size)
		{
			const std::size_t remain = m_arc.getBuffRemain();
			read_size = remain > src_size ? src_size : remain;
			if (data)//data���k���Ȃ�R�s�[���Ȃ����|�C���^�͐i�߂�
			{
				from_mem_func(m_arc.m_buff + m_arc.m_buffPos, read_size, data, dst_size);
			}
			m_arc.m_buffPos += read_size;
			return read_size == src_size;
		}
		//���������ʃI�u�W�F�N�g�g�p��
		bool readWithFunc(CResult& result, fromMemFuncP from_mem_func, void* data, const std::size_t dst_size, const std::size_t src_size, std::size_t* read_size = nullptr)
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//�f�[�^�ǂݍ���
			std::size_t read_size_tmp = 0;
			const bool result_now = readWithFunc(from_mem_func, data, dst_size, src_size, read_size_tmp);
			//�������ʋL�^
			if (!result_now)
				result.setHasFatalError();
			if (read_size)
				*read_size += read_size_tmp;
			return result_now;
		}
	public:
		//�R���X�g���N�^
		CIArchiveHelper(CIOArchiveBase& arc) :
			CIOArchiveHelper(arc)
		{}
		//�f�X�g���N�^
		~CIArchiveHelper()
		{}
	};
	//--------------------
	//�A�[�J�C�u�`�����N���X
	class CArchiveStyleBase
	{
	public:
		//�R���X�g���N�^
		CArchiveStyleBase()
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		CArchiveStyleBase(CArchiveStyleBase& parent)
		{}
		//�f�X�g���N�^
		~CArchiveStyleBase()
		{}
	};
	//--------------------
	//�A�[�J�C�u�`���v���g�^�C�v�i�A�[�J�C�u�������ݗp�j
	//���K�v�ȃ��\�b�h���`���Ă��邾���̃T���v���i�N���X�ǉ��̂��߂̎Q�l�p�j
	//�����ۂɂ͎g�p���Ȃ�
	class COArchiveStyleProto : public CArchiveStyleBase
	{
	public:
		//���\�b�h
		//�V�O�l�`����������
		bool writeSignature(COArchiveHelper arc){ return true; }
		//�u���b�N�w�b�_�[��������
		bool writeBlockHeader(COArchiveHelper arc, const CItemBase& item, const CVersion& ver){ return true; }
		//�z��u���b�N�w�b�_�[��������
		bool writeArrayHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t array_elem_num){ return true; }
		//�v�f�w�b�_�[��������
		bool writeElemHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t index){ return true; }
		//�f�[�^���ڏ�������
		bool writeDataItem(COArchiveHelper arc, const CItemBase& item, const CItemBase& child_item){ return true; }
		//�v�f�t�b�^�[��������
		bool writeElemFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size){ return true; }
		//�z��u���b�N�t�b�^�[��������
		bool writeArrayFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& array_block_size){ return true; }
		//�u���b�N�t�b�^�[��������
		bool writeBlockFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& block_size){ return true; }
		//�^�[�~�l�[�^��������
		bool writeTerminator(COArchiveHelper arc){ return true; }
	public:
		//�R���X�g���N�^
		COArchiveStyleProto() :
			CArchiveStyleBase()
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		COArchiveStyleProto(COArchiveStyleProto& parent) :
			CArchiveStyleBase(parent)
		{}
		//�f�X�g���N�^
		~COArchiveStyleProto()
		{}
	};
	//--------------------
	//�A�[�J�C�u�`���v���g�^�C�v�i�A�[�J�C�u�ǂݍ��ݗp�j
	//���K�v�ȃ��\�b�h���`���Ă��邾���̃T���v���i�N���X�ǉ��̂��߂̎Q�l�p�j
	//�����ۂɂ͎g�p���Ȃ�
	class CIArchiveStyleProto : public CArchiveStyleBase
	{
	public:
		//���\�b�h
		//�p�[�X
		bool parse(CIArchiveHelper arc){ return true; }
		//�V�O�l�`���ǂݍ���
		bool readSignature(CIArchiveHelper arc){ return true; }
		//�u���b�N�w�b�_�[�ǂݍ���
		//���ǂݍ��񂾃I�u�W�F�N�g�̌^���ƃo�[�W������Ԃ�
		bool readBlockHeader(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_item, const CVersion& ver, CItemBase& input_item, CVersion& input_ver, std::size_t& block_size){ return true; }
		//�z��u���b�N�w�b�_�[�ǂݍ���
		bool readArrayHeader(CIArchiveHelper arc, const CItemBase& item, std::size_t& array_elem_num, std::size_t& array_block_size){ return true; }
		//�v�f�w�b�_�[�ǂݍ���
		bool readElemHeader(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size){ return true; }
		//�f�[�^���ړǂݍ���
		bool readDataItem(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_child_item_now, CItemBase& child_item, const bool item_is_valid, const bool is_required_retry){ return true; }
		//�v�f�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�v�f�t�b�^�[�łȂ���΃f�[�^���ڂ̓ǂݍ��݂��p������
		bool tryAndReadElemFooter(CIArchiveHelper child_arc, const CItemBase& item, const std::size_t index, bool& is_elem_end){ return true; }
		//�v�f�ǂݍ��ݏI��
		bool finishReadElem(CIArchiveHelper parent_arc, CIArchiveHelper child_arc){ return true; }
		//�z��u���b�N�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�z��u���b�N�t�b�^�[�łȂ���΃f�[�^���ڂ̓ǂݍ��݂��p������
		bool tryAndReadArrayFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_array_block_end){ return true; }
		//�z��u���b�N�ǂݍ��ݏI��
		bool finishReadArray(CIArchiveHelper parent_arc, CIArchiveHelper child_arc){ return true; }
		//�u���b�N�̓ǂݍ��݂��X�L�b�v
		bool skipReadBlock(CIArchiveHelper arc){ return true; }
		//�u���b�N�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�u���b�N�t�b�^�[�łȂ���΃f�[�^���ځi�I�u�W�F�N�g�j�̓ǂݍ��݂��p������
		bool tryAndReadBlockFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_block_end){ return true; }
		//�u���b�N�ǂݍ��ݏI��
		bool finishReadBlock(CIArchiveHelper parent_arc, CIArchiveHelper child_arc){ return true; }
		//���̃u���b�N�w�b�_�[�₢���킹�i��s�ǂݍ��݁j
		//��������i�߂��A���̏���ǂݎ��̂�
		//���i�Ⴆ�΁A�o�C�i���X�^�C���Ȃ�A�ǂݍ��݃o�b�t�@�̃|�C���^��i�߂Ȃ��j
		bool requireNextBlockHeader(CIArchiveHelper arc, CItemBase& require_item, std::size_t& child_block_size, bool& is_found_next_block){ return true; }
		//�^�[�~�l�[�^�ǂݍ���
		bool readTerminator(CIArchiveHelper arc){ return true; }
	public:
		//�R���X�g���N�^
		CIArchiveStyleProto() :
			CArchiveStyleBase()
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		CIArchiveStyleProto(CIArchiveStyleProto& parent) :
			CArchiveStyleBase(parent)
		{}
		//�f�X�g���N�^
		~CIArchiveStyleProto()
		{}
	};
	//--------------------
	//�o�C�i���`���A�[�J�C�u�N���X�i���ʁj
	class CArchiveStyleBinaryBase : public CArchiveStyleBase
	{
	public:
		//�萔
		static const std::size_t SIGNATURE_SIZE = 16;//�V�O�l�`���T�C�Y
		static const std::size_t TERMINATOR_SIZE = 16;//�^�[�~�l�[�^�T�C�Y
		static const std::size_t BEGIN_MARK_SIZE = 2;//�e��n�[�}�[�N�T�C�Y
		static const std::size_t END_MARK_SIZE = 2;//�e��I�[�}�[�N�T�C�Y
		static const unsigned char SIGNATURE[SIGNATURE_SIZE];//�V�O�l�`��
		static const unsigned char TERMINATOR[TERMINATOR_SIZE];//�^�[�~�l�[�^
		static const unsigned char BLOCK_BEGIN[BEGIN_MARK_SIZE];//�u���b�N�n�[
		static const unsigned char BLOCK_END[END_MARK_SIZE];//�u���b�N�I�[
		static const unsigned char ARRAY_BEGIN[BEGIN_MARK_SIZE];//�z��n�[
		static const unsigned char ARRAY_END[END_MARK_SIZE];//�z��I�[
		static const unsigned char ELEM_BEGIN[BEGIN_MARK_SIZE];//�v�f�n�[
		static const unsigned char ELEM_END[END_MARK_SIZE];//�v�f�I�[
		static const unsigned char ITEM_BEGIN[BEGIN_MARK_SIZE];//�f�[�^���ڎn�[
		static const unsigned char ITEM_END[END_MARK_SIZE];//�f�[�^���ڏI�[
	public:
		//�R���X�g���N�^
		CArchiveStyleBinaryBase():
			CArchiveStyleBase()
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		CArchiveStyleBinaryBase(CArchiveStyleBinaryBase& parent) :
			CArchiveStyleBase(parent)
		{}
		//�f�X�g���N�^
		~CArchiveStyleBinaryBase() 
		{}
	};
	//--------------------
	//�o�C�i���`���A�[�J�C�u�N���X�i���ʁj�F�ÓI�ϐ��C���X�^���X��
	const unsigned char CArchiveStyleBinaryBase::SIGNATURE[CArchiveStyleBinaryBase::SIGNATURE_SIZE] = { 0x00, 0xff, 's', 'e', 'r', 'i', 'a', 'l', ':', ':', 'C', 'B', 'i', 'n', 0xff, 0x00 };//�V�O�l�`��
	const unsigned char CArchiveStyleBinaryBase::TERMINATOR[CArchiveStyleBinaryBase::TERMINATOR_SIZE] = { 0xff, 0x00, 's', 'e', 'r', 'i', 'a', 'l', ':', ':', 'C', 'B', 'i', 'n', 0x00, 0xff };//�^�[�~�l�[�^
	const unsigned char CArchiveStyleBinaryBase::BLOCK_BEGIN[CArchiveStyleBinaryBase::BEGIN_MARK_SIZE] = { 0xfb, 0xff };//�u���b�N�n�[
	const unsigned char CArchiveStyleBinaryBase::BLOCK_END[CArchiveStyleBinaryBase::END_MARK_SIZE] = { 0xff, 0xfb };//�u���b�N�I�[
	const unsigned char CArchiveStyleBinaryBase::ARRAY_BEGIN[CArchiveStyleBinaryBase::BEGIN_MARK_SIZE] = { 0xfa, 0xff };//�z��n�[
	const unsigned char CArchiveStyleBinaryBase::ARRAY_END[CArchiveStyleBinaryBase::END_MARK_SIZE] = { 0xff, 0xfa };//�z��I�[
	const unsigned char CArchiveStyleBinaryBase::ELEM_BEGIN[CArchiveStyleBinaryBase::BEGIN_MARK_SIZE] = { 0xfe, 0xff };//�v�f�n�[
	const unsigned char CArchiveStyleBinaryBase::ELEM_END[CArchiveStyleBinaryBase::END_MARK_SIZE] = { 0xff, 0xfe };//�v�f�I�[
	const unsigned char CArchiveStyleBinaryBase::ITEM_BEGIN[CArchiveStyleBinaryBase::BEGIN_MARK_SIZE] = { 0xf1, 0xff };//�f�[�^���ڎn�[
	const unsigned char CArchiveStyleBinaryBase::ITEM_END[CArchiveStyleBinaryBase::END_MARK_SIZE] = { 0xff, 0xf1 };//�f�[�^���ڏI�[
	//--------------------
	//�o�C�i���`���A�[�J�C�u�N���X�i�A�[�J�C�u�������ݗp�j
	class COArchiveStyleBinary : public CArchiveStyleBinaryBase
	{
	public:
		//���\�b�h
		//�V�O�l�`����������
		bool writeSignature(COArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, SIGNATURE, SIGNATURE_SIZE);//�V�O�l�`����������
			return !result.hasFatalError();
		}
		//�u���b�N�w�b�_�[��������
		bool writeBlockHeader(COArchiveHelper arc, const CItemBase& item, const CVersion& ver)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, BLOCK_BEGIN, BEGIN_MARK_SIZE);//�u���b�N�n�[��������
			arc.write(result, &item.m_nameCrc, sizeof(item.m_nameCrc));//���OCRC��������
			item.m_attr.setHasVersion();//�o�[�W������񂠂�ɂ���
			arc.write(result, &item.m_attr.m_value, sizeof(item.m_attr.m_value));//������������
			arc.write(result, ver.getVerPtr(), ver.getVerSize());//�o�[�W������������
			const std::size_t block_size = 0;
			arc.write(result, &block_size, sizeof(block_size));//�u���b�N�T�C�Y���������݁@���u���b�N�I�����ɏ���������
			return !result.hasFatalError();
		}
		//�z��u���b�N�w�b�_�[��������
		bool writeArrayHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t array_elem_num)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			if (item.isArr())
			{
				arc.write(result, ARRAY_BEGIN, BEGIN_MARK_SIZE);//�z��u���b�N�n�[��������
				const std::size_t array_block_size = 0;
				arc.write(result, &array_elem_num, sizeof(array_elem_num));//�z��v�f������������
				arc.write(result, &array_block_size, sizeof(array_block_size));//�z�u���b�N��T�C�Y���������݁@���z��I�����ɏ���������
			}
			return !result.hasFatalError();
		}
		//�v�f�w�b�_�[��������
		bool writeElemHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t index)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, ELEM_BEGIN, BEGIN_MARK_SIZE);//�v�f�n�[��������
			const short items_num = 0;
			const std::size_t elem_size = 0;
			arc.write(result, &items_num, sizeof(items_num));//�f�[�^���ڐ����������݁@���v�f�I�����ɏ���������
			arc.write(result, &elem_size, sizeof(elem_size));//�v�f�T�C�Y���������݁@���v�f�I�����ɏ���������
			return !result.hasFatalError();
		}
		//�f�[�^���ڏ�������
		bool writeDataItem(COArchiveHelper arc, const CItemBase& item, const CItemBase& child_item)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, ITEM_BEGIN, BEGIN_MARK_SIZE);//�f�[�^���ڎn�[��������
			arc.write(result, &child_item.m_nameCrc, sizeof(child_item.m_nameCrc));//���OCRC��������
			child_item.m_attr.resetHasVersion();//�o�[�W�������Ȃ��ɂ���
			arc.write(result, &child_item.m_attr.m_value, sizeof(child_item.m_attr.m_value));//������������
			arc.write(result, &child_item.m_itemSize, sizeof(child_item.m_itemSize));//�f�[�^�T�C�Y��������
			if (!child_item.isNul())//�k�����͂����܂ł̏��ŏI���
			{
				if (child_item.isArr())//�z�񂩁H
					arc.write(result, &child_item.m_arrNum, sizeof(child_item.m_arrNum));//��v�f����������
				unsigned char* p = reinterpret_cast<unsigned char*>(const_cast<void*>(child_item.m_itemP));
				const std::size_t elem_num = child_item.getElemNum();
				for (std::size_t index = 0; index < elem_num && !result.hasFatalError(); ++index)//�z��v�f�����f�[�^��������
				{
					arc.write(result, p, child_item.m_itemSize);//�f�[�^��������
					p += child_item.m_itemSize;
				}
			}
			arc.write(result, ITEM_END, END_MARK_SIZE);//�f�[�^���ڏI�[��������
			return !result.hasFatalError();
		}
		//�v�f�t�b�^�[��������
		bool writeElemFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
			{
				parent_arc.addResult(result);//�e�ɏ������ʂ��v��
				return false;
			}
			items_num = child_arc.getItemListNum();//�f�[�^���ڐ��擾
			elem_size = child_arc.getBuffUsed();//�f�[�^�T�C�Y�擾
			parent_arc.seek(result, -static_cast<int>(sizeof(elem_size)));//�v�f�T�C�Y���̕��A�o�b�t�@�̃J�����g�|�C���^��߂�
			parent_arc.seek(result, -static_cast<int>(sizeof(items_num)));//�f�[�^���ڐ����̕��A�o�b�t�@�̃J�����g�|�C���^��߂�
			parent_arc.write(result, &items_num, sizeof(items_num));//�v�f�T�C�Y���X�V�i�������݁j
			parent_arc.write(result, &elem_size, sizeof(elem_size));//�v�f�T�C�Y���X�V�i�������݁j
			parent_arc.seek(result, static_cast<int>(elem_size));//�v�f�T�C�Y���i�v�f�̏I���܂Łj�A�o�b�t�@�̃J�����g�|�C���^��i�߂�
			parent_arc.write(result, ELEM_END, END_MARK_SIZE);//�v�f�I�[��������
			parent_arc.addResult(result);//�e�ɏ������ʂ��v��
			return !result.hasFatalError();
		}
		//�z��u���b�N�t�b�^�[��������
		bool writeArrayFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& array_block_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
			{
				parent_arc.addResult(result);//�e�ɏ������ʂ��v��
				return false;
			}
			array_block_size = child_arc.getBuffUsed();//�f�[�^�T�C�Y�擾
			if (item.isArr())
			{
				parent_arc.seek(result, -static_cast<int>(sizeof(array_block_size)));//�z��u���b�N�T�C�Y���̕��A�o�b�t�@�̃J�����g�|�C���^��߂�
				parent_arc.write(result, &array_block_size, sizeof(array_block_size));//�z��u���b�N�T�C�Y���X�V�i�������݁j
			}
			parent_arc.seek(result, static_cast<int>(array_block_size));//�z��u���b�N�T�C�Y���i�v�f�̏I���܂Łj�A�o�b�t�@�̃J�����g�|�C���^��i�߂�
			if (item.isArr())
			{
				parent_arc.write(result, ARRAY_END, END_MARK_SIZE);//�z��u���b�N�I�[��������
			}
			parent_arc.addResult(result);//�e�ɏ������ʂ��v��
			return !result.hasFatalError();
		}
		//�u���b�N�t�b�^�[��������
		bool writeBlockFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& block_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
			{
				parent_arc.addResult(result);//�e�ɏ������ʂ��v��
				return false;
			}
			block_size = child_arc.getBuffUsed();//�f�[�^�T�C�Y�擾
			int real_seek = 0;
			parent_arc.seek(result, -static_cast<int>(sizeof(block_size)));//�u���b�N�T�C�Y���̕��A�o�b�t�@�̃J�����g�|�C���^��߂�
			parent_arc.write(result, &block_size, sizeof(block_size));//�u���b�N�T�C�Y���X�V�i�������݁j
			parent_arc.seek(result, static_cast<int>(block_size));//�u���b�N�T�C�Y���i�u���b�N�̏I���܂Łj�A�o�b�t�@�̃J�����g�|�C���^��i�߂�
			parent_arc.write(result, BLOCK_END, END_MARK_SIZE);//�u���b�N�I�[��������
			parent_arc.addResult(result);//�e�ɏ������ʂ��v��
			return !result.hasFatalError();
		}
		//�^�[�~�l�[�^��������
		bool writeTerminator(COArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, TERMINATOR, TERMINATOR_SIZE);//�^�[�~�l�[�^��������
			return !result.hasFatalError();
		}
	public:
		//�R���X�g���N�^
		COArchiveStyleBinary() :
			CArchiveStyleBinaryBase()
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		COArchiveStyleBinary(COArchiveStyleBinary& parent) :
			CArchiveStyleBinaryBase(parent)
		{}
		//�f�X�g���N�^
		~COArchiveStyleBinary()
		{}
	};
	//--------------------
	//�o�C�i���`���A�[�J�C�u�N���X�i�A�[�J�C�u�ǂݍ��ݗp�j
	class CIArchiveStyleBinary : public CArchiveStyleBinaryBase
	{
	public:
		//���\�b�h
		//�p�[�X
		bool parse(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//�������Ȃ�
			return !result.hasFatalError();
		}
		//�V�O�l�`���ǂݍ���
		bool readSignature(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char signature[SIGNATURE_SIZE];//�V�O�l�`���ǂݍ��݃o�b�t�@
			arc.read(result, signature, SIGNATURE_SIZE);//�V�O�l�`���ǂݍ���
			if (memcmp(signature, SIGNATURE, SIGNATURE_SIZE) != 0)//�V�O�l�`���`�F�b�N
				result.setHasFatalError();
			return !result.hasFatalError();
		}
		//�u���b�N�w�b�_�[�ǂݍ���
		//���ǂݍ��񂾃I�u�W�F�N�g�̌^���ƃo�[�W������Ԃ�
		bool readBlockHeader(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_item, const CVersion& ve, CItemBase& input_item, CVersion& input_ver, std::size_t& block_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char begin_mark[BEGIN_MARK_SIZE];//�u���b�N�n�[�ǂݍ��݃o�b�t�@
			arc.read(result, begin_mark, BEGIN_MARK_SIZE);//�u���b�N�n�[�ǂݍ���
			if (memcmp(begin_mark, BLOCK_BEGIN, BEGIN_MARK_SIZE) != 0)//�u���b�N�n�[�`�F�b�N
			{
				result.setHasFatalError();
				return false;
			}
			input_item.clearForLoad();//�ǂݍ��ݏ�����U�N���A
			arc.read(result, const_cast<crc32_t*>(&input_item.m_nameCrc), sizeof(input_item.m_nameCrc));//���OCRC�ǂݍ���
			arc.read(result, const_cast<CItemAttr::value_t*>(&input_item.m_attr.m_value), sizeof(input_item.m_attr.m_value));//�����ǂݍ���
			if (input_item.m_attr.hasVersion())//�o�[�W������񂪂��邩�H
			{
				arc.read(result, const_cast<unsigned int*>(input_ver.getVerPtr()), input_ver.getVerSize());//�o�[�W�����ǂݍ���
				input_ver.calcFromVer();
			}
			arc.read(result, const_cast<std::size_t*>(&input_item.m_itemSize), sizeof(input_item.m_itemSize));//�u���b�N�T�C�Y�ǂݍ���
			block_size = input_item.m_itemSize;//�u���b�N�T�C�Y
			//�Ϗ��A�C�e���̎w�肪����΁A���O���`�F�b�N�����ɓ��̓f�[�^�ɏ����R�s�[����
			if (delegate_item)
			{
				input_item.copyFromOnMem(*delegate_item);//�Z�[�u�f�[�^�̏��Ɍ��݂̏����R�s�[�i�����j
				input_item.setIsOnlyOnSaveData();//�Z�[�u�f�[�^��݂̂̃f�[�^�����ɂ���i�W�v�̂��߁j
			}
			else
			{
				//���OCRC���`�F�b�N���ď��𓝍�
				//������Ă�����v���I�G���[�i�Z�[�u�f�[�^���K�����Ă��Ȃ��j
				if (input_item == item)
				{
					//���҂ɑ��݂���
					input_item.copyFromOnMem(item);//�Z�[�u�f�[�^�̏��Ɍ��݂̏����R�s�[�i�����j
				}
				else
				{
					//��v���Ȃ�
					input_item.setIsOnlyOnSaveData();//�Z�[�u�f�[�^�ɂ������݂��Ȃ��f�[�^����
					result.setHasFatalError();//�v���I�G���[�ݒ�
				}
			}
			//�k���̎��͂��̎��_�ŏ����ς݂ɂ���
			//���k������Ȃ����͔z��ǂݍ��݂��ς񂾂珈���ς݂ɂ���
			if (input_item.m_attr.isNul())
			{
				item.setIsAlready();//�����ς݂ɂ���
				result.addResult(input_item);//���ʂ��v��
			}
			return !result.hasFatalError();
		}
		//�z��u���b�N�w�b�_�[�ǂݍ���
		bool readArrayHeader(CIArchiveHelper arc, const CItemBase& item, std::size_t& array_elem_num, std::size_t& array_block_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			if (item.isArr())//�z��^�̎������ǂݍ���
			{
				char begin_mark[BEGIN_MARK_SIZE];//�z��u���b�N�n�[�ǂݍ��݃o�b�t�@
				arc.read(result, begin_mark, BEGIN_MARK_SIZE);//�z��u���b�N�n�[�ǂݍ���
				if (memcmp(begin_mark, ARRAY_BEGIN, BEGIN_MARK_SIZE) != 0)//�z��u���b�N�n�[�`�F�b�N
				{
					result.setHasFatalError();
					return false;
				}
				arc.read(result, const_cast<std::size_t*>(&item.m_arrNum), sizeof(item.m_arrNum));//�z��v�f���ǂݍ���
				arc.read(result, const_cast<std::size_t*>(&array_block_size), sizeof(array_block_size));//�z��u���b�N�T�C�Y�ǂݍ���
				array_elem_num = item.m_arrNum;//�z��v�f��
			}
			else
			{
				*const_cast<std::size_t*>(&item.m_arrNum) = 0;//�z��v�f��
				array_elem_num = 0;//�z��v�f��
				array_block_size = 0;//�z��u���b�N�T�C�Y
			}
			item.setIsAlready();//�����ς݂ɂ���
			result.addResult(item);//���ʂ��v��
			return !result.hasFatalError();
		}
		//�v�f�w�b�_�[�ǂݍ���
		bool readElemHeader(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size)
		{
			CResult& result = arc.getResult();
			items_num = 0;
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char begin_mark[BEGIN_MARK_SIZE];//�z��n�[�ǂݍ��݃o�b�t�@
			arc.read(result, begin_mark, BEGIN_MARK_SIZE);//�z��n�[�ǂݍ���
			if (memcmp(begin_mark, ELEM_BEGIN, BEGIN_MARK_SIZE) != 0)//�v�f�n�[�`�F�b�N
			{
				result.setHasFatalError();
				return false;
			}
			arc.read(result, &items_num, sizeof(items_num));//�f�[�^���ڐ��ǂݍ���
			arc.read(result, &elem_size, sizeof(elem_size));//�v�f�T�C�Y�ǂݍ���
			return !result.hasFatalError();
		}
		//�f�[�^���ړǂݍ���
		bool readDataItem(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_child_item_now, CItemBase& child_item, const bool item_is_valid, const bool is_required_retry)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			if (is_required_retry)//���g���C�v��
			{
				//�L�����Ă���ʒu�ɖ߂�
				arc.seek(result, -static_cast<int>(m_readSizeForPrevDataItem));//�y���g���C�p�z�O��̃f�[�^�ǂݍ��݃T�C�Y
			}
			m_readSizeForPrevDataItem = 0;//�y���g���C�p�z�O��̃f�[�^�ǂݍ��݃T�C�Y�����Z�b�g
			std::size_t read_size = 0;//���̏������Ōv�シ��ǂݍ��݃T�C�Y
			char begin_mark[BEGIN_MARK_SIZE];//�f�[�^���ځ^�u���b�N�n�[�ǂݍ��݃o�b�t�@
			arc.read(result, begin_mark, BEGIN_MARK_SIZE, &read_size);//�f�[�^���ځ^�u���b�N�n�[�ǂݍ���
			bool is_block_begin = false;
			if (memcmp(begin_mark, BLOCK_BEGIN, BEGIN_MARK_SIZE) == 0)//�u���b�N�n�[�`�F�b�N
				is_block_begin = true;
			else
			{
				if (memcmp(begin_mark, ITEM_BEGIN, BEGIN_MARK_SIZE) != 0)//�f�[�^���ڎn�[�`�F�b�N
				{
					result.setHasFatalError();
					return false;
				}
			}
			arc.read(result, const_cast<crc32_t*>(&child_item.m_nameCrc), sizeof(child_item.m_nameCrc), &read_size);//���OCRC�ǂݍ���
			arc.read(result, const_cast<CItemAttr::value_t*>(&child_item.m_attr.m_value), sizeof(child_item.m_attr.m_value), &read_size);//�����ǂݍ���
			const CItemBase* child_item_now = nullptr;
			if (delegate_child_item_now)//�Ϗ��f�[�^���ڂ�����΂����D��I�Ɏg�p
			{
				child_item_now = delegate_child_item_now;//�Ϗ��f�[�^����
				//child_item�̖��O��CRC������������
				child_item.m_name = delegate_child_item_now->m_name;//���O
				*const_cast<crc32_t*>(&child_item.m_nameCrc) = delegate_child_item_now->m_nameCrc;//���O��CRC
			}
			else
				child_item_now = arc.findItem(child_item.m_nameCrc);//�Ή�����f�[�^���ڏ�������
			if (child_item_now)//�Ή�����f�[�^���ڂ������������H
				child_item.copyFromOnMem(*child_item_now);//���݂̏����Z�[�u�f�[�^�̏��ɃR�s�[�i�����j
			else
				child_item.setIsOnlyOnSaveData();//�Ή�����f�[�^���Ȃ��F�Z�[�u�f�[�^�ɂ����f�[�^�����݂��Ȃ�
			//�Ώۃf�[�^���ڂ̓I�u�W�F�N�g�^���H
			if (child_item.isObj())
			{
				//�Ώۂ��I�u�W�F�N�g�i�u���b�N�j�Ȃ�A�I�u�W�F�N�g�Ƃ��ď�������蒼�����߂ɁA���̎��_�ŏ����I��
				arc.seek(result, -static_cast<int>(read_size));//��蒼���̂��߂ɁA�o�b�t�@�̃J�����g�|�C���^��擪�ɖ߂�
				//�u���b�N�n�[�����o���Ă��Ȃ�������f�[�^�s�����ŃG���[�I��
				if (!is_block_begin)
				{
					result.setHasFatalError();
					return false;
				}
				return !result.hasFatalError();
			}
			//�ʏ�f�[�^�̓ǂݍ��ݏ���
			assert(!child_item.m_attr.hasVersion());//�I�u�W�F�N�g�ł��Ȃ��̂Ƀo�[�W������񂪂����NG
			arc.read(result, const_cast<std::size_t*>(&child_item.m_itemSize), sizeof(child_item.m_itemSize), &read_size);//�f�[�^�T�C�Y�ǂݍ���
			if (!child_item.isNul())//�y�Z�[�u�f�[�^��́z�f�[�^���k���łȂ���Ώ�������
			{
				if (child_item.isArr())//�z�񂩁H
					arc.read(result, const_cast<std::size_t*>(&child_item.m_arrNum), sizeof(child_item.m_arrNum), &read_size);//�z��v�f���ǂݍ���
				unsigned char* p = reinterpret_cast<unsigned char*>(const_cast<void*>(child_item.m_itemP));
				const std::size_t elem_num = child_item.getElemNum();
				for (std::size_t index = 0; index < elem_num && !result.hasFatalError(); ++index)//�y�Z�[�u�f�[�^��́z�z��v�f�����f�[�^��������
				{
					const bool element_is_valid =//�L���ȃf�[�^���H
						item_is_valid && //�e�̃f�[�^���L�����H
						!child_item.isOnlyOnSaveData() && //�Z�[�u�f�[�^�ɂ����Ȃ��f�[�^�ł͂Ȃ����H
						!child_item.nowIsNul() && //���݂́i�R�s�[��́j�f�[�^���k���ł͂Ȃ����H
						index < child_item.getNowElemNum();//���݂́i�R�s�[��́j�z��͈͓̔����H
					void* p_tmp = element_is_valid ? p : nullptr;//�L���ȃf�[�^�łȂ����nullptr��n���A��ǂݍ��݂���
					arc.readWithFunc(result, child_item.m_nowTypeCtrl.m_fromMemFuncP, p_tmp, child_item.m_nowItemSize, child_item.m_itemSize, &read_size);//�f�[�^�ǂݍ���
					if (p)
						p += child_item.m_nowItemSize;//���̗v�f
				}
			}
			char end_mark[END_MARK_SIZE];//�f�[�^���ڏI�[�ǂݍ��݃o�b�t�@
			arc.read(result, end_mark, END_MARK_SIZE, &read_size);//�f�[�^���ڏI�[�ǂݍ���
			if (memcmp(end_mark, ITEM_END, END_MARK_SIZE) != 0)//�f�[�^���ڎn�[�`�F�b�N
			{
				result.setHasFatalError();
				return false;
			}
			child_item.setIsAlready();//�����ς݂ɂ���
			result.addResult(child_item);//���ʂ��v��
			m_readSizeForPrevDataItem = read_size;//�y���g���C�p�z�O��̃f�[�^�ǂݍ��݃T�C�Y���L��
			return true;
		}
		//�v�f�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�v�f�t�b�^�[�łȂ���΃f�[�^���ڂ̓ǂݍ��݂��p������
		bool tryAndReadElemFooter(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, bool& is_elem_end)
		{
			is_elem_end = true;//�v�f�I������
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			std::size_t read_size = 0;
			char end_mark[END_MARK_SIZE];
			arc.read(result, end_mark, END_MARK_SIZE, &read_size);//�v�f�I�[�ǂݍ���
			if (memcmp(end_mark, ELEM_END, END_MARK_SIZE) != 0)//�v�f�I�[�`�F�b�N
			{
				is_elem_end = false;//�v�f�I���ł͂Ȃ�
				arc.seek(result, -static_cast<int>(read_size));//�v�f�̏I�[�ł͂Ȃ��������߁A�o�b�t�@�̃J�����g�|�C���^��߂�
			}
			return !result.hasFatalError();
		}
		//�v�f�ǂݍ��ݏI��
		bool finishReadElem(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			parent_arc.addResult(child_arc.getResult());//�e�ɏ������ʂ��v��
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			parent_arc.seek(result, child_arc.getBuffUsed());
			return !result.hasFatalError();
		}
		//�z��u���b�N�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�z��u���b�N�t�b�^�[�łȂ���΃f�[�^���ڂ̓ǂݍ��݂��p������
		bool tryAndReadArrayFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_array_block_end)
		{
			is_array_block_end = true;//�z��u���b�N�I������
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			if (item.isArr())
			{
				std::size_t read_size = 0;
				char end_mark[END_MARK_SIZE];
				arc.read(result, end_mark, END_MARK_SIZE, &read_size);//�z��u���b�N�I�[�ǂݍ���
				if (memcmp(end_mark, ARRAY_END, END_MARK_SIZE) != 0)//�v�f�I�[�`�F�b�N
				{
					is_array_block_end = false;//�z��u���b�N�I���ł͂Ȃ�
					arc.seek(result, -static_cast<int>(read_size));//�v�f�̏I�[�ł͂Ȃ��������߁A�o�b�t�@�̃J�����g�|�C���^��߂�
				}
			}
			return !result.hasFatalError();
		}
		//�z��u���b�N�ǂݍ��ݏI��
		bool finishReadArray(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			parent_arc.addResult(child_arc.getResult());//�e�ɏ������ʂ��v��
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			parent_arc.seek(result, child_arc.getBuffUsed());
			return !result.hasFatalError();
		}
		//�u���b�N�̓ǂݍ��݂��X�L�b�v
		bool skipReadBlock(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char begin_mark[BEGIN_MARK_SIZE];//�u���b�N�n�[�ǂݍ��݃o�b�t�@
			arc.read(result, begin_mark, BEGIN_MARK_SIZE);//�u���b�N�n�[�ǂݍ���
			if (memcmp(begin_mark, BLOCK_BEGIN, BEGIN_MARK_SIZE) != 0)//�u���b�N�n�[�`�F�b�N
			{
				result.setHasFatalError();
				return false;
			}
			crc32_t name_crc = 0;
			CItemAttr attr(false, false, false, false, false);
			arc.read(result, &name_crc, sizeof(name_crc));//���OCRC�ǂݍ���
			arc.read(result, const_cast<CItemAttr::value_t*>(&attr.m_value), sizeof(attr.m_value));//������������
			if (attr.hasVersion())//�o�[�W������񂪂��邩�H
			{
				CVersion input_ver_dummy;
				arc.read(result, const_cast<unsigned int*>(input_ver_dummy.getVerPtr()), input_ver_dummy.getVerSize());//�o�[�W�����ǂݍ���
			}
			if (!attr.isNul())//�k�����͂����܂ł̏��ŏI���
			{
				std::size_t item_size;
				arc.read(result, &item_size, sizeof(item_size));//�u���b�N�T�C�Y�ǂݍ���
				arc.seek(result, static_cast<int>(item_size));//�u���b�N�T�C�Y���A�o�b�t�@�̃J�����g�|�C���^��i�߂�
			}
			//�u���b�N�t�b�^�[�ǂݍ���
			char end_mark[END_MARK_SIZE];
			arc.read(result, end_mark, END_MARK_SIZE);//�u���b�N�I�[�ǂݍ���
			if (memcmp(end_mark, BLOCK_END, END_MARK_SIZE) != 0)//�u���b�N�I�[�`�F�b�N
			{
				result.setHasFatalError();
				return false;
			}
			return !result.hasFatalError();
		}
		//�u���b�N�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�u���b�N�t�b�^�[�łȂ���΃f�[�^���ځi�I�u�W�F�N�g�j�̓ǂݍ��݂��p������
		bool tryAndReadBlockFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_block_end)
		{
			is_block_end = true;//�u���b�N�I������
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			std::size_t read_size = 0;
			char end_mark[END_MARK_SIZE];
			arc.read(result, end_mark, END_MARK_SIZE, &read_size);//�u���b�N�I�[�ǂݍ���
			if (memcmp(end_mark, BLOCK_END, END_MARK_SIZE) != 0)//�u���b�N�I�[�`�F�b�N
			{
				is_block_end = false;//�u���b�N�I���ł͂Ȃ�
				arc.seek(result, -static_cast<int>(read_size));//�u���b�N�̏I�[�ł͂Ȃ��������߁A�o�b�t�@�̃J�����g�|�C���^��߂�
			}
			return !result.hasFatalError();
		}
		//�u���b�N�ǂݍ��ݏI��
		bool finishReadBlock(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			parent_arc.addResult(child_arc.getResult());//�e�ɏ������ʂ��v��
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			parent_arc.seek(result, child_arc.getBuffUsed());
			return !result.hasFatalError();
		}
		//���ǂݍ��݃e�X�g�̌��ʁA�u���b�N�t�b�^�[�łȂ���΃f�[�^���ځi�I�u�W�F�N�g�j�̓ǂݍ��݂��p������
		//���̃u���b�N�w�b�_�[�₢���킹�i��s�ǂݍ��݁j
		//��������i�߂��A���̏���ǂݎ��̂�
		//���i�Ⴆ�΁A�o�C�i���X�^�C���Ȃ�A�ǂݍ��݃o�b�t�@�̃|�C���^��i�߂Ȃ��j
		bool requireNextBlockHeader(CIArchiveHelper arc, CItemBase& require_item, std::size_t& require_block_size, bool& is_found_next_block)
		{
			is_found_next_block = false;//�u���b�N��񂪌������ĂȂ����Ƃɂ���
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			std::size_t read_size = 0;//�ǂݍ��݃T�C�Y
			require_item.clearForLoad();//�ǂݍ��ݏ�����U�N���A
			char begin_mark[BEGIN_MARK_SIZE];//�u���b�N�n�[�ǂݍ��݃o�b�t�@
			arc.read(result, begin_mark, BEGIN_MARK_SIZE, &read_size);//�u���b�N�n�[�ǂݍ���
			if (memcmp(begin_mark, BLOCK_BEGIN, BEGIN_MARK_SIZE) != 0)//�u���b�N�n�[�`�F�b�N
			{
				arc.seek(result, -static_cast<int>(read_size));//���ǂ݂������A�o�b�t�@�̃J�����g�|�C���^��߂�
				return !result.hasFatalError();
			}
			is_found_next_block = true;//��������
			arc.read(result, const_cast<crc32_t*>(&require_item.m_nameCrc), sizeof(require_item.m_nameCrc), &read_size);//���OCRC��������
			arc.read(result, const_cast<CItemAttr::value_t*>(&require_item.m_attr.m_value), sizeof(require_item.m_attr.m_value), &read_size);//������������
			if (require_item.m_attr.hasVersion())//�o�[�W������񂪂��邩�H
			{
				CVersion input_ver_dummy;
				arc.read(result, const_cast<unsigned int*>(input_ver_dummy.getVerPtr()), input_ver_dummy.getVerSize(), &read_size);//�o�[�W�����ǂݍ���
			}
			require_block_size = read_size;//�u���b�N�T�C�Y��U�v��
			if (!require_item.isNul())//�k�����͂����܂ł̏��ŏI���
			{
				arc.read(result, const_cast<std::size_t*>(&require_item.m_itemSize), sizeof(require_item.m_itemSize), &read_size);//�u���b�N�T�C�Y�ǂݍ���
				require_block_size += require_item.m_itemSize;//�u���b�N�T�C�Y�v��
				if (require_item.isArr())//�z�񎞂͔z��v�f�����ǂݍ���
				{
					char begin_mark[BEGIN_MARK_SIZE];//�z��u���b�N�n�[�ǂݍ��݃o�b�t�@
					arc.read(result, begin_mark, BEGIN_MARK_SIZE);//�z��u���b�N�n�[�ǂݍ���
					if (memcmp(begin_mark, ARRAY_BEGIN, BEGIN_MARK_SIZE) == 0)//�z��u���b�N�n�[�`�F�b�N
					{
						//std::size_t array_block_size = 0;
						arc.read(result, const_cast<std::size_t*>(&require_item.m_arrNum), sizeof(require_item.m_arrNum));//�z��v�f���ǂݍ���
						//arc.read(result, const_cast<std::size_t*>(&array_block_size), sizeof(array_block_size));//�z��u���b�N�T�C�Y�ǂݍ���
					}
				}
			}
			arc.seek(result, -static_cast<int>(read_size));//���ǂ݂������A�o�b�t�@�̃J�����g�|�C���^��߂�
			return !result.hasFatalError();
		}
		//�^�[�~�l�[�^�ǂݍ���
		bool readTerminator(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char terminator[TERMINATOR_SIZE];
			arc.read(result, terminator, TERMINATOR_SIZE);//�^�[�~�l�[�^�ǂݍ���
			if (memcmp(terminator, TERMINATOR, TERMINATOR_SIZE) != 0)//�^�[�~�l�[�^�`�F�b�N
				result.setHasFatalError();
			return true;
		}
	public:
		//�R���X�g���N�^
		CIArchiveStyleBinary() :
			CArchiveStyleBinaryBase(),
			m_readSizeForPrevDataItem(0)
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		CIArchiveStyleBinary(CIArchiveStyleBinary& parent) :
			CArchiveStyleBinaryBase(parent),
			m_readSizeForPrevDataItem(0)
		{}
		//�f�X�g���N�^
		~CIArchiveStyleBinary()
		{}
	private:
		//�t�B�[���h
		std::size_t m_readSizeForPrevDataItem;//�y���g���C�p�z�O��̃f�[�^�ǂݍ��݃T�C�Y
	};
	//--------------------
	//�e�L�X�g�`���A�[�J�C�u�N���X�i���ʁj
	class CArchiveStyleTextBase : public CArchiveStyleBase
	{
	public:
		//�R���X�g���N�^
		CArchiveStyleTextBase() :
			CArchiveStyleBase()
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		CArchiveStyleTextBase(CArchiveStyleTextBase& parent) :
			CArchiveStyleBase(parent)
		{}
		//�f�X�g���N�^
		~CArchiveStyleTextBase()
		{}
	};
	//--------------------
	//�e�L�X�g�`���A�[�J�C�u�N���X�i�A�[�J�C�u�������ݗp�j
	class COArchiveStyleText : public CArchiveStyleTextBase
	{
	public:
		//�萔
		enum PROCESS
		{
			PROCESS_UNKNOWN = 0,
			PROCESS_TOP,
			PROCESS_BLOCK,
			PROCESS_ARRAY_BLOCK,
			PROCESS_ELEM,
			PROCESS_ITEM,
		};
	public:
		//���\�b�h
		//�V�O�l�`����������
		bool writeSignature(COArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			m_process = PROCESS_TOP;
			arc.print(result, "\"serializer\": {");
			m_blockIndex = 0;
			return !result.hasFatalError();
		}
		//�u���b�N�w�b�_�[��������
		bool writeBlockHeader(COArchiveHelper arc, const CItemBase& item, const CVersion& ver)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			if (m_blockIndex != 0 || m_process == PROCESS_ARRAY_BLOCK)
				arc.print(result, ",");
			arc.print(result, "\n");
			m_process = PROCESS_BLOCK;
			arc.printIndent(result, 0);
			arc.print(result, "\"%s\": {", item.m_name);
			arc.print(result, "\"crc\": 0x%08x, ", item.m_nameCrc);
			arc.print(result, "\"itemType\": \"%s\", ", item.m_itemType->name());
			arc.print(result, "\"itemSize\": %d, ", item.m_itemSize);
			arc.print(result, "\"isObj\": %d, ", item.isObj());
			arc.print(result, "\"isArr\": %d, ", item.isArr());
			arc.print(result, "\"isPtr\": %d, ", item.isPtr());
			arc.print(result, "\"isNul\": %d, ", item.isNul());
			arc.print(result, "\"isVLen\": %d, ", item.isVLen());
			arc.print(result, "\"hasVersion\": %d, ", item.m_attr.hasVersion());
			arc.print(result, "\"ver\": \"%d.%d\"", ver.getMajor(), ver.getMinor());
			m_arrayBlockIndex = 0;
			return !result.hasFatalError();
		}
		//�z��u���b�N�w�b�_�[��������
		bool writeArrayHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t array_elem_num)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			if (item.isArr())
			{
				arc.print(result, ",");
				arc.print(result, "\n");
				m_process = PROCESS_ARRAY_BLOCK;
				arc.printIndent(result, 0);
				arc.print(result, "\"arrayNum\": %d, \"array\": [", array_elem_num);
				m_elemIndex = 0;
			}
			else
			{
				m_process = PROCESS_ARRAY_BLOCK;
				m_elemIndex = -1;
			}
			return !result.hasFatalError();
		}
		//�v�f�w�b�_�[��������
		bool writeElemHeader(COArchiveHelper arc, const CItemBase& item, const std::size_t index)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			if (!item.isArr() || (item.isArr() && m_elemIndex != 0))
				arc.print(result, ",");
			arc.print(result, "\n");
			m_process = PROCESS_ELEM;
			arc.printIndent(result, 0);
			arc.print(result, "\"elem\": {");
			m_itemIndex = 0;
			return !result.hasFatalError();
		}
		//�f�[�^���ڏ�������
		bool writeDataItem(COArchiveHelper arc, const CItemBase& item, const CItemBase& child_item)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			if (m_itemIndex != 0)
				arc.print(result, ",");
			arc.print(result, "\n");
			m_process = PROCESS_ITEM;
			arc.printIndent(result, 0);
			arc.print(result, "\"%s\": {", child_item.m_name);
			arc.print(result, "\"crc\": 0x%08x, ", child_item.m_nameCrc);
			arc.print(result, "\"itemType\": \"%s\", ", child_item.m_itemType->name());
			arc.print(result, "\"itemSize\": %d, ", child_item.m_itemSize);
			arc.print(result, "\"isObj\": %d, ", child_item.isObj());
			arc.print(result, "\"isArr\": %d, ", child_item.isArr());
			arc.print(result, "\"isPtr\": %d, ", child_item.isPtr());
			arc.print(result, "\"isNul\": %d, ", child_item.isNul());
			arc.print(result, "\"isVLen\": %d, ", child_item.isVLen());
			arc.print(result, "\"hasVersion\": %d, ", child_item.m_attr.hasVersion());
			if (child_item.isArr())
				arc.print(result, "\"arrNum\": %d, ", child_item.m_arrNum);
			arc.print(result, "\"data\": ");
			{
				if (child_item.isNul())
					arc.print(result, "null");
				else
				{
					unsigned char* p = reinterpret_cast<unsigned char*>(const_cast<void*>(child_item.m_itemP));
					const std::size_t elem_num = child_item.getElemNum();
					if (child_item.isArr())
						arc.print(result, "[");
					for (std::size_t index = 0; index < elem_num && !result.hasFatalError(); ++index)//�z��v�f�����f�[�^��������
					{
						if (index != 0)
							arc.print(result, ",");
						arc.printWithFunc(result, child_item.m_typeCtrl.m_toStrFuncP, p, child_item.m_itemSize);
						p += child_item.m_itemSize;
					}
					if (child_item.isArr())
						arc.print(result, "]");
				}
			}
			arc.print(result, "}");
			++m_itemIndex;
			m_process = m_parentProcess;
			return !result.hasFatalError();
		}
		//�v�f�t�b�^�[��������
		bool writeElemFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
			{
				parent_arc.addResult(result);//�e�ɏ������ʂ��v��
				return false;
			}
			child_arc.print(result, "}");
			parent_arc.seek(result, child_arc.getBuffUsed());
			parent_arc.addResult(result);//�e�ɏ������ʂ��v��
			if (m_parent)
				++m_parent->m_elemIndex;
			m_process = m_parentProcess;
			return !result.hasFatalError();
		}
		//�z��u���b�N�t�b�^�[��������
		bool writeArrayFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& array_block_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
			{
				parent_arc.addResult(result);//�e�ɏ������ʂ��v��
				return false;
			}
			if (item.isArr())
			{
				child_arc.print(result, "]");
			}
			parent_arc.seek(result, child_arc.getBuffUsed());
			parent_arc.addResult(result);//�e�ɏ������ʂ��v��
			if (m_parent)
				++m_parent->m_arrayBlockIndex;
			m_process = m_parentProcess;
			return !result.hasFatalError();
		}
		//�u���b�N�t�b�^�[��������
		bool writeBlockFooter(COArchiveHelper parent_arc, COArchiveHelper child_arc, const CItemBase& item, std::size_t& block_size)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
			{
				parent_arc.addResult(result);//�e�ɏ������ʂ��v��
				return false;
			}
			child_arc.print(result, "}");
			parent_arc.seek(result, child_arc.getBuffUsed());
			parent_arc.addResult(result);//�e�ɏ������ʂ��v��
			if (m_parent)
				++m_parent->m_blockIndex;
			m_process = m_parentProcess;
			return !result.hasFatalError();
		}
		//�^�[�~�l�[�^��������
		bool writeTerminator(COArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.print(result, "\n");
			arc.print(result, "}\n");
			return !result.hasFatalError();
		}
	public:
		//�R���X�g���N�^
		COArchiveStyleText() :
			CArchiveStyleTextBase(),
			m_parent(nullptr),
			m_nestLevel(0),
			m_process(PROCESS_UNKNOWN),
			m_blockIndex(0),
			m_arrayBlockIndex(0),
			m_elemIndex(0),
			m_itemIndex(0),
			m_parentProcess(PROCESS_UNKNOWN),
			m_parentBlockIndex(0),
			m_parentArrayBlockIndex(0),
			m_parentElemIndex(0),
			m_parentItemIndex(0)
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		COArchiveStyleText(COArchiveStyleText& src) :
			CArchiveStyleTextBase(src),
			m_parent(&src),
			m_nestLevel(src.m_nestLevel + 1),
			m_process(src.m_process),
			m_blockIndex(0),
			m_arrayBlockIndex(0),
			m_elemIndex(0),
			m_itemIndex(0),
			m_parentProcess(src.m_process),
			m_parentBlockIndex(src.m_blockIndex),
			m_parentArrayBlockIndex(src.m_arrayBlockIndex),
			m_parentElemIndex(src.m_elemIndex),
			m_parentItemIndex(src.m_itemIndex)
		{}
		//�f�X�g���N�^
		~COArchiveStyleText()
		{}
	private:
		//�t�B�[���h
		COArchiveStyleText* m_parent;//�e�A�[�J�C�u�`���I�u�W�F�N�g
		int m_nestLevel;//�f�[�^�̃l�X�g���x��
		PROCESS m_process;//�������
		int m_blockIndex;//�u���b�N�C���f�b�N�X
		int m_arrayBlockIndex;//�z��u���b�N�C���f�b�N�X
		int m_elemIndex;//�v�f�C���f�b�N�X
		int m_itemIndex;//�f�[�^���ڃC���f�b�N�X
		PROCESS m_parentProcess;//�e�̏������
		int m_parentBlockIndex;//�e�̃u���b�N�C���f�b�N�X
		int m_parentArrayBlockIndex;//�e�̔z��u���b�N�C���f�b�N�X
		int m_parentElemIndex;//�e�̗v�f�C���f�b�N�X
		int m_parentItemIndex;//�e�̃f�[�^���ڃC���f�b�N�X
	};
	//--------------------
	//�e�L�X�g�`���A�[�J�C�u�N���X�i�A�[�J�C�u�ǂݍ��ݗp�j
	class CIArchiveStyleText : public CArchiveStyleTextBase
	{
	public:
		//���\�b�h
		//�p�[�X
		bool parse(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�V�O�l�`���ǂݍ���
		bool readSignature(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�u���b�N�w�b�_�[�ǂݍ���
		//���ǂݍ��񂾃I�u�W�F�N�g�̌^���ƃo�[�W������Ԃ�
		bool readBlockHeader(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_item, const CVersion& ver, CItemBase& input_item, CVersion& input_ver, std::size_t& block_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�z��u���b�N�w�b�_�[�ǂݍ���
		bool readArrayHeader(CIArchiveHelper arc, const CItemBase& item, std::size_t& array_elem_num, std::size_t& array_block_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�v�f�w�b�_�[�ǂݍ���
		bool readElemHeader(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, short& items_num, std::size_t& elem_size)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�f�[�^���ړǂݍ���
		bool readDataItem(CIArchiveHelper arc, const CItemBase& item, const CItemBase* delegate_child_item_now, const bool item_is_valid, const bool is_required_retry)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�v�f�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�v�f�t�b�^�[�łȂ���΃f�[�^���ڂ̓ǂݍ��݂��p������
		bool tryAndReadElemFooter(CIArchiveHelper arc, const CItemBase& item, const std::size_t index, bool& is_elem_end)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�v�f�ǂݍ��ݏI��
		bool finishReadElem(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�z��u���b�N�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�z��u���b�N�t�b�^�[�łȂ���΃f�[�^���ڂ̓ǂݍ��݂��p������
		bool tryAndReadArrayFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_array_block_end)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�z��u���b�N�ǂݍ��ݏI��
		bool finishReadArray(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�u���b�N�̓ǂݍ��݂��X�L�b�v
		bool skipReadBlock(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�u���b�N�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʁA�u���b�N�t�b�^�[�łȂ���΃f�[�^���ځi�I�u�W�F�N�g�j�̓ǂݍ��݂��p������
		bool tryAndReadBlockFooter(CIArchiveHelper arc, const CItemBase& item, bool& is_block_end)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�u���b�N�ǂݍ��ݏI��
		bool finishReadBlock(CIArchiveHelper parent_arc, CIArchiveHelper child_arc)
		{
			CResult& result = child_arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//���ǂݍ��݃e�X�g�̌��ʁA�u���b�N�t�b�^�[�łȂ���΃f�[�^���ځi�I�u�W�F�N�g�j�̓ǂݍ��݂��p������
		//���̃u���b�N�w�b�_�[�₢���킹�i��s�ǂݍ��݁j
		//��������i�߂��A���̏���ǂݎ��̂�
		//���i�Ⴆ�΁A�o�C�i���X�^�C���Ȃ�A�ǂݍ��݃o�b�t�@�̃|�C���^��i�߂Ȃ��j
		bool requireNextBlockHeader(CIArchiveHelper arc, CItemBase& require_item, std::size_t& require_block_size, bool& is_found_next_block)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
		//�^�[�~�l�[�^�ǂݍ���
		bool readTerminator(CIArchiveHelper arc)
		{
			CResult& result = arc.getResult();
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//������
			return !result.hasFatalError();
		}
	public:
		//�R���X�g���N�^
		CIArchiveStyleText() :
			CArchiveStyleTextBase()
		{}
		//�e���󂯎��R���X�g���N�^
		//�������K�w���[���Ȃ邲�ƂɃR�s�[���s����
		CIArchiveStyleText(CIArchiveStyleText& parent) :
			CArchiveStyleTextBase(parent)
		{}
		//�f�X�g���N�^
		~CIArchiveStyleText()
		{}
	};
	//--------------------
	//�o�C�i���`���A�[�J�C�u�������݃N���X
	using COBinaryArchive = COArchive<COArchiveStyleBinary>;
	//--------------------
	//�o�C�i���`���A�[�J�C�u�ǂݍ��݃N���X
	using CIBinaryArchive = CIArchive<CIArchiveStyleBinary>;
	//--------------------
	//�e�L�X�g�`���A�[�J�C�u�������݃N���X
	using COTextArchive = COArchive<COArchiveStyleText>;
	//--------------------
	//�e�L�X�g�`���A�[�J�C�u�ǂݍ��݃N���X
	using CITextArchive = CIArchive<CIArchiveStyleText>;
}

//--------------------------------------------------------------------------------
//�V���A���C�Y�e�X�g�P

#include <bitset>//std::bitset

//--------------------
//�e�X�g�p�N���X
class CTest1
{
	//�V���A���C�Y�p�̃t�����h�ݒ�
	FRIEND_SERIALIZE(CTest1);
public:
	//�^
	struct STRUCT
	{
		//FRIEND_SERIALIZE(STRUCT);
		int m_a;
		char m_b;
		float m_c;
		//�R���X�g���N�^
		STRUCT():
			m_a(0),
			m_b(0),
			m_c(0.f)
		{}
	};
public:
	//�A�N�Z�b�T
	int getData1() const { return m_data1; }//�f�[�^1�擾
	void setData1(const int value){ m_data1 = value; }//�f�[�^1�X�V
	float getData2() const { return m_data2; }//�f�[�^2�擾
	void setData2(const float value){ m_data2 = value; }//�f�[�^2�X�V
	char getData3(const int index) const { return m_data3[index]; }//�f�[�^3�擾
	void setData3(const int index, const int value){ m_data3[index] = value; }//�f�[�^3�X�V
	STRUCT& getData4a(){ return m_data4a; }//�f�[�^4a�擾
	const STRUCT& getData4a() const { return m_data4a; }//�f�[�^4a�擾
	STRUCT& getData4b(){ return m_data4b; }//�f�[�^4b�擾
	const STRUCT& getData4b() const { return m_data4b; }//�f�[�^4b�擾
	bool getData5a(const int index) const { return m_data5a[index]; }//�f�[�^5a�擾
	void setData5a(const int index, const bool value){ m_data5a[index] = value; }//�f�[�^5a�X�V
	bool getData5b(const int index) const { return m_data5b[index]; }//�f�[�^5b�擾
	void setData5b(const int index, const bool value){ m_data5b[index] = value; }//�f�[�^5b�X�V
	STRUCT& getData6(const int index){ return m_data6[index]; }//�f�[�^6�擾
	const STRUCT& getData6(const int index) const { return m_data6[index]; }//�f�[�^6�擾
	STRUCT* getData7a(){ return m_data7a; }//�f�[�^7a�擾
	const STRUCT* getData7a() const { return m_data7a; }//�f�[�^7a�擾
	STRUCT* getData7b(){ return m_data7b; }//�f�[�^7b�擾
	const STRUCT* getData7b() const { return m_data7b; }//�f�[�^7b�擾
	int* getData8a(){ return m_data8a; }//�f�[�^8a�擾
	const int* getData8a() const { return m_data8a; }//�f�[�^8a�擾
	int* getData8b(){ return m_data8b; }//�f�[�^8b�擾
	const int* getData8b() const { return m_data8b; }//�f�[�^8b�擾
public:
	//�R���X�g���N�^
	CTest1() :
		m_data1(0),
		m_data2(0.f),
		m_data4a(),
		m_data4b(),
		m_data7a(nullptr),
		m_data7b(nullptr),
		m_data8a(nullptr),
		m_data8b(nullptr)
	{
		m_data3[0] = 0;
		m_data3[1] = 0;
		m_data3[2] = 0;
		m_data5a.reset();
		m_data5b.reset();
		m_data7a = new STRUCT();
		//m_data7b = new STRUCT();
		m_data8a = new int;
		//m_data8b = new int;
	}
	//�f�X�g���N�^
	~CTest1()
	{
		if (m_data7a)
			delete m_data7a;
		if (m_data7b)
			delete m_data7b;
		if (m_data8a)
			delete m_data8a;
		if (m_data8b)
			delete m_data8b;
	}
private:
	//�t�B�[���h
	//int m_data0;
	int m_data1;//�f�[�^1
	float m_data2;//�f�[�^2
	char m_data3[3];//�f�[�^3
	STRUCT m_data4a;//�f�[�^4a
	STRUCT m_data4b;//�f�[�^4b
	std::bitset<8192> m_data5a;//�f�[�^5a
	std::bitset<8192> m_data5b;//�f�[�^5b
	STRUCT m_data6[2];//�f�[�^6
	STRUCT* m_data7a;//�f�[�^7a
	STRUCT* m_data7b;//�f�[�^7b
	int* m_data8a;//�f�[�^8a
	int* m_data8b;//�f�[�^8b
};
//--------------------
//�Z�[�u�f�[�^�쐬�p�N���X
//����̃N���X
//���M���U�[���ƃf�B�X�g���r���[�^�̂ݒ�`����
class CSaveDataSerializer
{};
//--------------------
//�e�X�g�p�N���X�̃o�[�W������ݒ�
SERIALIZE_VERSION_DEF(CTest1, 1, 2);
SERIALIZE_VERSION_DEF(CTest1::STRUCT, 3, 4);
SERIALIZE_VERSION_DEF(CSaveDataSerializer, 5, 6);

//�Z�[�u�f�[�^�C���X�^���X
static CTest1* s_saveData = nullptr;

//�Z�[�u�f�[�^������
void initSaveData()
{
	//�Z�[�u�f�[�^�擾
	CTest1& data = *s_saveData;
	//�f�[�^��������
	data.setData1(1);
	data.setData2(2.34f);
	data.setData3(0, 5);
	data.setData3(1, 6);
	data.setData3(2, 7);
	data.getData4a().m_a = 8;
	data.getData4a().m_b = 9;
	data.getData4a().m_c = 10.f;
	data.getData4b().m_a = 11;
	data.getData4b().m_b = 12;
	data.getData4b().m_c = 13.f;
	data.setData5a(0, true);
	data.setData5a(1, true);
	data.setData5a(8191, true);
	data.setData5b(2, true);
	data.setData5b(8190, true);
	data.getData6(0).m_a = 14;
	data.getData6(0).m_b = 15;
	data.getData6(0).m_c = 16.f;
	data.getData6(1).m_a = 17;
	data.getData6(1).m_b = 18;
	data.getData6(1).m_c = 19.f;
	if (data.getData7a())
	{
		data.getData7a()->m_a = 20;
		data.getData7a()->m_b = 21;
		data.getData7a()->m_c = 22.f;
	}
	if (data.getData7b())
	{
		data.getData7b()->m_a = 23;
		data.getData7b()->m_b = 24;
		data.getData7b()->m_c = 25.f;
	}
	if (data.getData8a())
		*data.getData8a() = 26;
	if (data.getData8b())
		*data.getData8b() = 27;
}

//�Z�[�u�f�[�^���e�\��
void printSaveData()
{
	//�Z�[�u�f�[�^�擾
	CTest1& data = *s_saveData;
	//�f�[�^�\��
	printf("data1=%d\n", data.getData1());
	printf("data2=%.2f\n", data.getData2());
	printf("data3={%d, %d, %d}\n", data.getData3(0), data.getData3(1), data.getData3(2));
	printf("data4a:a=%d,b=%d,c=%.1f\n", data.getData4a().m_a, data.getData4a().m_b, data.getData4a().m_c);
	printf("data4b:a=%d,b=%d,c=%.1f\n", data.getData4b().m_a, data.getData4b().m_b, data.getData4b().m_c);
	printf("data5a:[0]=%d,[1]=%d,[2]=%d,[8190]=%d,[8191]=%d\n", data.getData5a(0), data.getData5a(1), data.getData5a(2), data.getData5a(8190), data.getData5a(8191));
	printf("data5b:[0]=%d,[1]=%d,[2]=%d,[8190]=%d,[8191]=%d\n", data.getData5b(0), data.getData5b(1), data.getData5b(2), data.getData5b(8190), data.getData5b(8191));
	printf("data6:[0]={a=%d,b=%d,c=%.1f},[1]={a=%d,b=%d,c=%.1f}\n", data.getData6(0).m_a, data.getData6(0).m_b, data.getData6(0).m_c, data.getData6(1).m_a, data.getData6(1).m_b, data.getData6(1).m_c);
	if (data.getData7a())
		printf("data7a(0x%p):a=%d,b=%d,c=%.1f\n", data.getData7a(), data.getData7a()->m_a, data.getData7a()->m_b, data.getData7a()->m_c);
	else
		printf("data7a(0x%p)\n", data.getData7a());
	if (data.getData7b())
		printf("data7b(0x%p):a=%d,b=%d,c=%.1f\n", data.getData7b(), data.getData7b()->m_a, data.getData7b()->m_b, data.getData7b()->m_c);
	else
		printf("data7b(0x%p)\n", data.getData7b());

	if (data.getData8a())
		printf("data8a(0x%p)=%d\n", data.getData8a(), *data.getData8a());
	else
		printf("data8a(0x%p)\n", data.getData8a());
	if (data.getData8b())
		printf("data8b(0x%p)=%d\n", data.getData8b(), *data.getData8b());
	else
		printf("data8b(0x%p)\n", data.getData8b());
}


//--------------------
//�e�X�g�p�N���X�̃V���A���C�Y������`
namespace serial
{
#if 1
	//--------------------
	//���[�h�O�����p�֐��I�u�W�F�N�g
	//���f�V���A���C�Y��p����
	template<class Arc>
	struct beforeLoad<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("beforeLoad<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			if (!obj.m_data7a)
				obj.m_data7a = new CTest1::STRUCT();
		}
	};
#endif
#if 1
	//--------------------
	//�V���A���C�Y�����p�֐��I�u�W�F�N�g
	//���V���A���C�Y�ƃf�V���A���C�Y���p���ʏ���
	template<class Arc>
	struct serialize<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("arc.is_read=%d, arc.is_write=%d\n", arc.is_read, arc.is_write);
			printf("serialize<CTest1>(ver=%d,%d) sizeof(CTest1)=%d\n", ver.getMajor(), ver.getMinor(), sizeof(CTest1));
			//arc & pair("data0", obj.m_data0);
			arc & pair("data1", obj.m_data1)
			    & pair("data2", obj.m_data2)
			    & pair("data3", obj.m_data3);
			arc & pairBin("data4a", obj.m_data4a);
			arc & pair("data4b", obj.m_data4b);
			arc & pairBin("data5a", obj.m_data5a);
			arc & pair("data5b", obj.m_data5b);
			arc & pair("data6", obj.m_data6);
			arc & pair("data7a", obj.m_data7a);
			arc & pair("data7b", obj.m_data7b);
			arc & pair("data8a", obj.m_data8a);
			arc & pair("data8b", obj.m_data8b);
		}
	};
#endif
#if 1
	template<class Arc>
	struct serialize<Arc, CTest1::STRUCT> {
		void operator()(Arc& arc, const CTest1::STRUCT& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("serialize<CTest1::STRUCT>(ver=%d,%d) sizeof(CTest1::STRUCT)=%d\n", ver.getMajor(), ver.getMinor(), sizeof(CTest1::STRUCT));
			arc & pair("data1", obj.m_a);
			arc & pair("data2", obj.m_b);
			arc & pair("data3", obj.m_c);
		}
	};
#endif
#if 0
	//�W���N���X���C�u�����ɑΉ�����֐�����`�ł���
	//std::bitset��1�r�b�g���ʍ��ڂŏ����o���T���v��
	//���c��ȃ��[�N�o�b�t�@��v����̂Œ���
	template<class Arc, std::size_t N>
	struct serialize<Arc, std::bitset<N> > {
		void operator()(Arc& arc, const std::bitset<N>& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("serialize<std::bitset<N>>(ver=%d,%d) sizeof(std::bitset<N>)=%d\n", ver.getMajor(), ver.getMinor(), sizeof(std::bitset<N>));
			for (int i = 0; i < N; ++i)
			{
				char name[16];
			#ifdef USE_STRCPY_S
				sprintf_s(name,sizeof(name),  "no%d", i);
			#else//USE_STRCPY_S
				sprintf(name, "no%d", i);
			#endif//USE_STRCPY_S
				bool bit = obj[i];
				arc & pair(name, bit);
			}
		}
	};
#endif
#if 1
	//--------------------
	//�Z�[�u�����p�֐��I�u�W�F�N�g�N���X
	//���V���A���C�Y��p����
	template<class Arc>
	struct save<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver)
		{
			printf("save<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//���[�h�����p�֐��I�u�W�F�N�g�N���X
	//���f�V���A���C�Y��p����
	template<class Arc>
	struct load<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("load<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//���[�h�㏈���p�֐��I�u�W�F�N�g�N���X
	//���f�V���A���C�Y��p����
	template<class Arc>
	struct afterLoad<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("afterLoad<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//�f�[�^���W�����p�֐��I�u�W�F�N�g�N���X
	//���V���A���C�Y��p����
	template<class Arc>
	struct collector<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver)
		{
			printf("collector<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//�f�[�^���z�����p�֐��I�u�W�F�N�g�N���X
	//���f�V���A���C�Y��p����
	template<class Arc>
	struct distributor<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{
			printf("distributor<CTest1>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//�f�[�^���W�����p�֐��I�u�W�F�N�g�N���X
	//���V���A���C�Y��p����
	template<class Arc>
	struct collector<Arc, CSaveDataSerializer> {
		void operator()(Arc& arc, const CSaveDataSerializer& obj, const CVersion& ver)
		{
			printf("collector<CSaveDataSerializer>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			//�Ώۃf�[�^�擾
			CTest1& data = *s_saveData;
			//�V���A���C�Y
			arc << pair("CTest1", data);
		}
	};
#endif
#if 1
	//--------------------
	//�f�[�^���z�����p�֐��I�u�W�F�N�g�N���X
	//���f�V���A���C�Y��p����
	template<class Arc>
	struct distributor<Arc, CSaveDataSerializer> {
		void operator()(Arc& arc, CSaveDataSerializer& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{
			printf("distributor<CSaveDataSerializer>(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			//�Ώۃf�[�^�擾
			CTest1& data = *s_saveData;
			//�f�V���A���C�Y
			arc >> pair("CTest1", data);
		}
	};
#endif
}//namespace serial

//--------------------
//�V���A���C�Y�e�X�g�P�F�o�C�i���A�[�J�C�u
void serializeTest1bin(const char* file_path)
{
	printf("--------------------\n");
	printf("�V���A���C�Y�F�o�C�i���A�[�J�C�u\n");
	//�o�b�t�@�̗p��
	//char* save_buff = new char[1 * 1024 * 1024];//�Z�[�u�f�[�^�o�b�t�@
	//char* work_buff = new char[8 * 1024 * 1024];//���[�N�o�b�t�@
	char save_buff[16 * 1024];//�Z�[�u�f�[�^�o�b�t�@
	char work_buff[16 * 1024];//���[�N�o�b�t�@
	//�Z�[�u�f�[�^������
	initSaveData();
	//�Z�[�u�f�[�^�\��
	printSaveData();
	//�V���A���C�Y
	serial::COBinaryArchive arc(save_buff, work_buff);
	arc << serial::pair<CSaveDataSerializer>("SaveData");//�V���A���C�Y
	printf("�������ʁF%s\n", arc.hasFatalError() ? "�v���I�ȃG���[����" : "�G���[�Ȃ�");
	//�t�@�C���ɏ����o��
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(save_buff, 1, arc.getSaveDataSize(), fp);
	fclose(fp);
	fp = NULL;
}
//--------------------
//�V���A���C�Y�e�X�g�P�F�e�L�X�g�A�[�J�C�u
void serializeTest1txt(const char* file_path)
{
	printf("--------------------\n");
	printf("�V���A���C�Y�F�e�L�X�g�A�[�J�C�u\n");
	//�o�b�t�@�̗p��
	//char* save_buff = new char[1 * 1024 * 1024];//�Z�[�u�f�[�^�o�b�t�@
	//char* work_buff = new char[8 * 1024 * 1024];//���[�N�o�b�t�@
	char save_buff[32 * 1024];//�Z�[�u�f�[�^�o�b�t�@
	char work_buff[16 * 1024];//���[�N�o�b�t�@
	//�Z�[�u�f�[�^������
	initSaveData();
	//�Z�[�u�f�[�^�\��
	printSaveData();
	//�V���A���C�Y
	serial::COTextArchive arc(save_buff, work_buff);
	arc << serial::pair<CSaveDataSerializer>("SaveData");//�V���A���C�Y
	printf("�������ʁF%s\n", arc.hasFatalError() ? "�v���I�ȃG���[����" : "�G���[�Ȃ�");
	//�t�@�C���ɏ����o��
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(save_buff, 1, arc.getSaveDataSize(), fp);
	fclose(fp);
	fp = NULL;
}
//--------------------
//�f�V���A���C�Y�e�X�g�P�F�o�C�i���A�[�J�C�u
void deserializeTest1bin(const char* file_path)
{
	printf("--------------------\n");
	printf("�f�V���A���C�Y�F�o�C�i���A�[�J�C�u\n");
	//�o�b�t�@�̗p��
	//char* save_buff = new char[1 * 1024 * 1024];//�Z�[�u�f�[�^�o�b�t�@
	//char* work_buff = new char[8 * 1024 * 1024];//���[�N�o�b�t�@
	char save_buff[16 * 1024];//�Z�[�u�f�[�^�o�b�t�@
	char work_buff[16 * 1024];//���[�N�o�b�t�@
	//�t�@�C������ǂݍ���
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "rb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "rb");
#endif//USE_STRCPY_S
	//�t�@�C���T�C�Y�����߂�
	fseek(fp, 0, SEEK_END);
	const std::size_t file_size = ftell(fp);
	//�t�@�C����ǂݍ���
	fseek(fp, 0, SEEK_SET);
	fread(save_buff, 1, file_size, fp);
	fclose(fp);
	fp = NULL;
	//�f�V���A���C�Y
	serial::CIBinaryArchive arc(save_buff, file_size, work_buff);
	arc >> serial::pair<CSaveDataSerializer>("SaveData", file_size);
	printf("�������ʁF%s\n", arc.hasFatalError() ? "�v���I�ȃG���[����" : "�G���[�Ȃ�");
	serial::CResult& result = arc.getResult();
	printf("  getNumSmallerSizeItem()=%d\n", result.getNumSmallerSizeItem());//�T�C�Y���k�����ꂽ�f�[�^���ڂ̐����擾
	printf("  getNumLargerSizeItem()=%d\n", result.getNumLargerSizeItem());//�T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐����擾
	printf("  getNumSmallerArrItem()=%d\n", result.getNumSmallerArrItem());//�z��T�C�Y���k�����ꂽ�f�[�^���ڂ̐����擾
	printf("  getNumLargerArrItem()=%d\n", result.getNumLargerArrItem());//�z��T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐����擾
	printf("  getNumIsOnlyOnSaveData()=%d\n", result.getNumIsOnlyOnSaveData());//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���ڂ̐����擾
	printf("  getNumIsOnlyOnMem()=%d\n", result.getNumIsOnlyOnMem());//�Z�[�u�f�[�^��ɂȂ��f�[�^���ڂ̐����擾
	printf("  getNumIsObjOnSaveDataOnly()=%d\n", result.getNumIsObjOnSaveDataOnly());//���݃I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����擾
	printf("  getNumIsObjOnMemOnly()=%d\n", result.getNumIsObjOnMemOnly());//���݃I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����擾
	printf("  getNumIsArrOnSaveDataOnly()=%d\n", result.getNumIsArrOnSaveDataOnly());//���ݔz��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����擾
	printf("  getNumIsArrOnMemOnly()=%d\n", result.getNumIsArrOnMemOnly());//���ݔz��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����擾
	printf("  getNumIsPtrOnSaveDataOnly()=%d\n", result.getNumIsPtrOnSaveDataOnly());//���݃|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����擾
	printf("  getNumIsPtrOnMemOnly()=%d\n", result.getNumIsPtrOnMemOnly());//���݃|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����擾
	printf("  getNumIsNulOnSaveDataOnly()=%d\n", result.getNumIsNulOnSaveDataOnly());//���݃k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐����擾
	printf("  getNumIsNulOnMemOnly()=%d\n", result.getNumIsNulOnMemOnly());//���݃k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐����擾
	//�Z�[�u�f�[�^�\��
	printSaveData();
}
//--------------------
//�V���A���C�Y���f�V���A���C�Y�e�X�g�P�F�o�C�i���A�[�J�C�u
void test1()
{
	static const char* file_path_bin = "test1.bin";
	static const char* file_path_txt = "test1.txt";
	//�V���A���C�Y
	s_saveData = new CTest1();
	serializeTest1bin(file_path_bin);
	serializeTest1txt(file_path_txt);
	delete s_saveData;
	s_saveData = nullptr;

	char* dummy = new char[10 * 1024];
	
	//�f�V���A���C�Y
	s_saveData = new CTest1();
	deserializeTest1bin(file_path_bin);
	delete s_saveData;
	s_saveData = nullptr;
	
	delete dummy;
}

//--------------------------------------------------------------------------------
//�V���A���C�Y�e�X�g�Q

//--------------------
//��{�^
//�Z��������^
template <std::size_t S>
class CStr
{
public:
	//�萔
	static const std::size_t BUFF_SIZE = S;//�o�b�t�@�T�C�Y
	static const std::size_t MAX_SIZE = S - 1;//�ő啶����
public:
	//�A�N�Z�b�T
	const char* c_str() const { return m_str; }//��������擾�@��std::string�݊�
	std::size_t length() const { return m_len; }//�����񒷂��擾�@��std::string�݊�
	std::size_t size() const { return m_len; }//�����񒷂��擾�@��std::string�݊�
	std::size_t max_size() const { return MAX_SIZE; }//������̍ő咷���擾�@��std::string�݊�
	const char* getStr() const { return m_str; }//��������擾
	void setStr(const char* str)//��������Z�b�g
	{
		if (!str)
		{
			m_str[0] = '\0';
			m_len = 0;
			return;
		}
	#ifdef USE_STRCPY_S
		strncpy_s(m_str, sizeof(m_str), str, MAX_SIZE);
	#else//USE_STRCPY_S
		strncpy(m_str, str, MAX_SIZE);
	#endif//USE_STRCPY_S
		m_str[MAX_SIZE] = '\0';
		m_len = strlen(m_str);
	}
public:
	//�L���X�g�I�y���[�^
	operator const char*() const { return m_str; }
public:
	//�f�t�H���g�R���X�g���N�^
	CStr():
		m_len(0)
	{
		m_str[0] = '\0';
	}
	//�R�s�[�R���X�g���N�^
	template <std::size_t SS>
	CStr(const CStr<S>& src) :
		m_len(src.m_len < MAX_SIZE ? src.m_len : MAX_SIZE)
	{
		memcpy(m_str, src.m_str, m_len);
		m_str[m_len] = '\0';
	}
	//�R���X�g���N�^
	CStr(const char* str)
	{
		setStr(str);
	}
protected:
	//�t�B�[���h
	unsigned char m_len;//������
	char m_str[BUFF_SIZE];//������
	//�V���A���C�Y�p�̃t�����h�ݒ�
	FRIEND_SERIALIZE(str);
};
//CRC�t��������^
template <std::size_t S>
class CStrWithCRC : public CStr<S>
{
public:
	//�^
	typedef CStr<S> CParent;
public:
	//�A�N�Z�b�T
	crc32_t getCRC() const { return m_crc; }//CRC���擾
	void setStr(const char* str)//��������Z�b�g
	{
		CParent::setStr(str);
		m_crc = calcCRC32(CParent::m_str);
	}
public:
	//�L���X�g�I�y���[�^
	operator crc32_t() const { return m_crc; }
public:
	//�f�t�H���g�R���X�g���N�^
	CStrWithCRC() :
		CParent(nullptr),
		m_crc(0)
	{}
	//�R�s�[�R���X�g���N�^
	template <std::size_t SS>
	CStrWithCRC(const CStrWithCRC<SS>& src) :
		CStr<SS>(src),
		m_crc(src.m_crc)
	{}
	//�R���X�g���N�^
	CStrWithCRC(const char* str) :
		CParent()
	{
		setStr(str);
	}
private:
	//�t�B�[���h
	crc32_t m_crc;//CRC
	//�V���A���C�Y�p�̃t�����h�ݒ�
	FRIEND_SERIALIZE(strWithCRC);
};

//--------------------
//ID�^�����O�^
using ID_t = CStrWithCRC<8>;
using name_t = CStr<32>;

//--------------------
//��{�f�[�^�\����
struct BASIC_DATA
{
	short m_atk;//�U����
	short m_def;//�����
	//�f�t�H���g�R���X�g���N�^
	BASIC_DATA()
	{}
	//�R�s�[�R���X�g���N�^
	BASIC_DATA(const BASIC_DATA& src) :
		m_atk(src.m_atk),
		m_def(src.m_def)
	{}
	//�R���X�g���N�^
	BASIC_DATA(const int atk, const int def) :
		m_atk(atk),
		m_def(def)
	{}
};
//�\���̃o�[�W����
SERIALIZE_VERSION_DEF(BASIC_DATA, 1, 0);

//--------------------
//�A�C�e���\����
struct ITEM_DATA
{
	crc32_t getKey() const { return m_id.getCRC(); }//�L�[���擾
	ID_t m_id;//ID
	name_t m_name;//���O
	char* m_title;//�̍��@���ϒ�������i�|�C���^�j�̃e�X�g�p
	char m_titleBuff[16];//�̍��p�o�b�t�@
	BASIC_DATA m_basic;//��{�f�[�^
	short m_recover;//�񕜗�
	short m_num;//�f�[�^��
	//�f�t�H���g�R���X�g���N�^
	ITEM_DATA()
	{
		m_title = m_titleBuff;
		m_titleBuff[0] = '\0';
	}
	//�R���X�g���N�^�i�e�X�g�p�ɋ����j
	ITEM_DATA(const char* id, const char* name, const int atk, const int def, const int recover, const int num) :
		m_id(id),
		m_name(name),
		m_basic(atk, def),
		m_recover(recover),
		m_num(num)
	{
		m_title = m_titleBuff;
		m_title[0] = '\0';
	}
	//�R�s�[�R���X�g���N�^
	ITEM_DATA(const ITEM_DATA& src):
		m_id(src.m_id),
		m_name(src.m_name),
		m_basic(src.m_basic),
		m_recover(src.m_recover),
		m_num(src.m_num)
	{
		if (src.m_title)
		{
			m_title = m_titleBuff;
		#ifdef USE_STRCPY_S
			strcpy_s(m_title, sizeof(m_titleBuff), src.m_title);
		#else//USE_STRCPY_S
			strcpy(m_title, src.m_title);
		#endif//USE_STRCPY_S
		}
		else
			m_title = nullptr;
	}
};
//�\���̃o�[�W����
SERIALIZE_VERSION_DEF(ITEM_DATA, 1, 0);

//--------------------
//�A�r���e�B�f�[�^�\����
struct ABILITY_DATA
{
	crc32_t getKey() const { return m_id.getCRC(); }//�L�[���擾
	ID_t m_id;//ID
	name_t m_name;//���O
	BASIC_DATA m_basic;//��{�f�[�^
	//�f�t�H���g�R���X�g���N�^
	ABILITY_DATA()
	{}
	//�R���X�g���N�^�i�e�X�g�p�ɋ����j
	ABILITY_DATA(const char* id, const char* name, const int atk, const int def) :
		m_id(id),
		m_name(name),
		m_basic(atk, def)
	{}
};
//�\���̃o�[�W����
SERIALIZE_VERSION_DEF(ABILITY_DATA, 1, 0);

//--------------------
//�L�����f�[�^�\����
struct ABILITY_DATA;
struct CHARA_ABILITY_DATA;
struct CHARA_DATA
{
	crc32_t getKey() const { return m_id.getCRC(); }//�L�[���擾
	ID_t m_id;//ID
	name_t m_name;//���O
	char m_level;//���x��
	BASIC_DATA m_basic;//��{�f�[�^
	const ITEM_DATA* m_weapon;//����
	const ITEM_DATA* m_shield;//��
	int m_param1[2];//�_�~�[�p�����[�^1
	int m_param2[2];//�_�~�[�p�����[�^2
	//���\�b�h
	void setWeapon(const crc32_t weapon_id);//������Z�b�g
	void setWeapon(const char* weapon_id){ setWeapon(calcCRC32(weapon_id)); }//������Z�b�g
	void setShield(const crc32_t shield_id);//�����Z�b�g
	void setShield(const char* shield_id){ setShield(calcCRC32(shield_id)); }//�����Z�b�g
	void attachItems();//�A�C�e�����Q�Ƃ�����
	void addAbility(const crc32_t ability_id);//�A�r���e�B��ǉ�
	void addAbility(const char* ability_id){ addAbility(calcCRC32(ability_id)); }//�A�r���e�B��ǉ�
	ABILITY_DATA* getAbility(const int index);//�A�r���e�B���擾
	//�f�t�H���g�R���X�g���N�^
	CHARA_DATA()
	{}
	//�R���X�g���N�^�i�e�X�g�p�ɋ����j
	CHARA_DATA(const char* id, const char* name, const int level, const int atk, const int def, const char* weapon_id, const char* shield_id, const int param1a, const int param1b, const int param2a, const int param2b) :
		m_id(id),
		m_name(name),
		m_level(level),
		m_basic(atk, def),
		m_weapon(nullptr),
		m_shield(nullptr),
		m_abilities(nullptr)
	{
		setWeapon(weapon_id);
		setShield(shield_id);
		m_param1[0] = param1a;
		m_param1[1] = param1b;
		m_param2[0] = param2a;
		m_param2[1] = param2b;
	}
private:
	crc32_t m_weaponId;//����ID
	crc32_t m_shieldId;//��ID
	CHARA_ABILITY_DATA* m_abilities;//�A�r���e�B
	//�V���A���C�Y�p�̃t�����h�ݒ�
	FRIEND_SERIALIZE(CHARA_DATA);
};
//�\���̃o�[�W����
SERIALIZE_VERSION_DEF(CHARA_DATA, 1, 0);

//--------------------
//�L�����ۗL�A�r���e�B�f�[�^�\����
struct CHARA_ABILITY_DATA
{
	CHARA_ABILITY_DATA* m_next;//�A�����X�g
	ABILITY_DATA* m_ability;//�A�r���e�B
};
//���Z�[�u�p�\����
struct CHARA_ABILITY_DATA_FOR_SAVE
{
	//crc32_t m_charaId;//�L����ID
	crc32_t m_abilityId;//�A�r���e�BID
};
//--------------------
//�L�����ۗL�A�r���e�B�f�[�^�o�b�t�@
class CCharaAbilityBuff
{
public:
	//���\�b�h
	CHARA_ABILITY_DATA* assign(){ return m_itemPool.createData(); }
	void release(CHARA_ABILITY_DATA* data){ m_itemPool.destroyData(data); }
public:
	//�R���X�g���N�^
	CCharaAbilityBuff()
	{}
private:
	//�t�B�[���h
	CPoolAllocatorWithType<CHARA_ABILITY_DATA, 100> m_itemPool;//�f�[�^�p�̃o�b�t�@
};

//--------------------
//�R���N�V�����N���X
template<class T, std::size_t D, std::size_t B1, std::size_t B2>
class CCollection
{
private:
	//�^
	typedef std::map<crc32_t, T*> search_t;//�����e�[�u���^
	typedef std::vector<T*> table_t;//����e�[�u���^
	typedef typename table_t::iterator iterator;//�C�e���[�^�^
	typedef typename table_t::const_iterator const_iterator;//�C�e���[�^�^
public:
	//�萔
	static const std::size_t DATA_NUM_MAX = D;//�ő�f�[�^��
	static const std::size_t SEARCH_BUFF_SIZE = B1;//�����e�[�u���̃o�b�t�@�T�C�Y
	static const std::size_t TABLE_BUFF_SIZE = B2;//����e�[�u���o�b�t�@�T�C�Y
public:
	//�A�N�Z�b�T
	iterator begin(){ return m_table->begin(); }//�J�n�C�e���[�^
	iterator end(){ return m_table->end(); }//�I���C�e���[�^
	const_iterator begin() const { return m_table->begin(); }//�J�n�C�e���[�^
	const_iterator end() const { return m_table->end(); }//�I���C�e���[�^
	const_iterator cbegin() const { return m_table->cbegin(); }//�J�n�C�e���[�^
	const_iterator cend() const { return m_table->cend(); }//�I���C�e���[�^
public:
	//����
	T* find(const crc32_t key)
	{
		auto ite = m_search->find(key);
		if (ite == m_search->end())
			return nullptr;//������Ȃ�����
		return ite->second;
	}
	T* find(const char* id)
	{
		return find(calcCRC32(id));
	}
	//�o�^
	T* regist(const T& item)
	{
		//�v�[���A���P�[�^���犄�蓖��
		T* reg_item = m_itemPool.createData(item);
		if (!reg_item)
			return nullptr;//�K��̌������蓖�čς݂Ȃ玸�s
		{
			//�����e�[�u���o�b�t�@�𑽑ԃA���P�[�^�ɃZ�b�g
			CTempPolyStackAllocator allocator(m_searchBuff);

			//�����e�[�u���ɓo�^
			m_search->emplace(reg_item->getKey(), reg_item);
		}
		{
			//����e�[�u���o�b�t�@�𑽑ԃA���P�[�^�ɃZ�b�g
			CTempPolyStackAllocator allocator(m_tableBuff);
			
			//����e�[�u���ɂ��ǉ�
			m_table->push_back(reg_item);
		}
		return reg_item;
	}
	//�j��
	void unregist(const crc32_t key)
	{
		T* item = find(key);
		if (!item)
			return;
		{
			//�����e�[�u���o�b�t�@�𑽑ԃA���P�[�^�ɃZ�b�g
			CTempPolyStackAllocator allocator(m_searchBuff);

			//�����e�[�u������A�C�e����j��
			m_search->erase(key);
		}
		//�v�[���A���P�[�^������
		//m_itemPool.destroy(item);
	}
private:
	//����e�[�u���𐶐�
	void createTable()
	{
		if (!m_table)
		{
			//����e�[�u���o�b�t�@�𑽑ԃA���P�[�^�ɃZ�b�g
			CTempPolyStackAllocator allocator(m_tableBuff);
			
			m_table = new table_t();
		}
	}
	//����e�[�u���j��
	void destroyTable()
	{
		if (m_table)
		{
			//����e�[�u���o�b�t�@�𑽑ԃA���P�[�^�ɃZ�b�g
			CTempPolyStackAllocator allocator(m_tableBuff);

			delete m_table;
			m_table = nullptr;
		}
		//�o�b�t�@���N���A
		m_tableBuff.clearN();
	}
public:
	//�\�[�g
	//������e�[�u���č쐬
	void sort(const bool is_descendant = false)
	{
		//����e�[�u���̔j���Ɛ���
		destroyTable();//�j��
		createTable();//����
		{
			//����e�[�u���o�b�t�@�𑽑ԃA���P�[�^�ɃZ�b�g
			CTempPolyStackAllocator allocator(m_tableBuff);

			//�����e�[�u�����琮��e�[�u���ɑS�v�f�R�s�[
			for (auto& pair : *m_search)
			{
				m_table->push_back(pair.second);
			}

			//���O���\�[�g
			std::sort(m_table->begin(), m_table->end(),
				[&is_descendant](T* lhs, T* rhs)->bool
				{
					const int cmp = strcmp(lhs->m_name, rhs->m_name);
					return is_descendant ? cmp > 0 : cmp < 0;
				}
			);
		}
	}
public:
	//�R���X�g���N�^
	CCollection()
	{
		{
			//�����e�[�u���o�b�t�@�𑽑ԃA���P�[�^�ɃZ�b�g
			//���Ȍ�A�����u���b�N�𔲂���܂ŁAnew ���Z�q�ɂ��
			//�@�������m�ۂ� m_searchBuff ����s����
			CTempPolyStackAllocator allocator(m_searchBuff);

			//�����e�[�u������
			m_search = new search_t;
		}
		//����e�[�u������
		createTable();
	}
	//�f�X�g���N�^
	~CCollection()
	{
		{
			//�����e�[�u���o�b�t�@�𑽑ԃA���P�[�^�ɃZ�b�g
			CTempPolyStackAllocator allocator(m_searchBuff);

			//�����e�[�u���j��
			//���Ƃ��ɕK�v�ł͂Ȃ����O�̂���
			delete m_search;
		}
		//����e�[�u���j��
		destroyTable();
	}
private:
	//�t�B�[���h
	CPoolAllocatorWithType<T, DATA_NUM_MAX> m_itemPool;//�f�[�^�p�̃o�b�t�@
	CStackAllocatorWithBuff<SEARCH_BUFF_SIZE> m_searchBuff;//�����e�[�u���o�b�t�@
	search_t* m_search;//�����e�[�u��
	CStackAllocatorWithBuff<TABLE_BUFF_SIZE> m_tableBuff;//����e�[�u���o�b�t�@
	table_t* m_table;//����e�[�u��
};
//--------------------
//�C���x���g���N���X
typedef CCollection<ITEM_DATA, 100, 8 * 1024, 8 * 1024> CInventoryBase;
class CInventory : public CInventoryBase
{
public:
	//�R���X�g���N�^
	CInventory() :
		CInventoryBase()
	{}
	//�f�X�g���N�^
	~CInventory()
	{}
};
//�\���̃o�[�W����
SERIALIZE_VERSION_DEF(CInventory, 1, 0);
//--------------------
//�A�r���e�B���N���X
using CAbilityList = CCollection<ABILITY_DATA, 40, 8 * 1024, 8 * 1024>;
//�\���̃o�[�W����
SERIALIZE_VERSION_DEF(CAbilityList, 1, 0);
//--------------------
//�L�������X�g�N���X
using CCharaList = CCollection<CHARA_DATA, 10, 8 * 1024, 8 * 1024>;
//�\���̃o�[�W����
SERIALIZE_VERSION_DEF(CCharaList, 1, 0);

//--------------------
//�i�s���t���O�f�[�^
class CPhaseAndFlags
{
public:
	//�^
	typedef std::bitset<64> flag_t;
public:
	//�A�N�Z�b�T
	int getPhase() const { return m_phase; }//�t�F�[�Y�擾
	void setPhase(const int phase){ m_phase = phase; }//�t�F�[�Y�X�V
	bool getFlag(const int index) const { return m_flags[index]; }//�t���O�擾
	void setFlag(const int index, const bool flag){ m_flags[index] = flag; }//�t���O�X�V
	const flag_t& getFlags() const { return m_flags; }
public:
	//�R���X�g���N�^
	CPhaseAndFlags() :
		m_phase(0)
	{
		m_flags.reset();
	}
private:
	//�t�B�[���h
	short m_phase;//�i�s�t�F�[�Y
	flag_t m_flags;//�t���O
	//�V���A���C�Y�p�̃t�����h�ݒ�
	FRIEND_SERIALIZE(CPhaseAndFlags);
};
//�\���̃o�[�W����
SERIALIZE_VERSION_DEF(CPhaseAndFlags, 1, 0);

//--------------------
//�L�����f�[�^�F���\�b�h����
//������Z�b�g
void CHARA_DATA::setWeapon(const crc32_t weapon_id)
{
	CSingleton<CInventory> inventory;
	ITEM_DATA* item = inventory->find(weapon_id);
	if (!item)
	{
		//�ΏۃA�C�e�����Ȃ��̂Ŏ����Ă��Ȃ����Ƃɂ���
		m_weaponId = 0;
		m_weapon = nullptr;
		return;
	}
	m_weaponId = weapon_id;
	m_weapon = item;
}
//�����Z�b�g
void CHARA_DATA::setShield(const crc32_t shield_id)
{
	CSingleton<CInventory> inventory;
	ITEM_DATA* item = inventory->find(shield_id);
	if (!item)
	{
		//�ΏۃA�C�e�����Ȃ��̂Ŏ����Ă��Ȃ����Ƃɂ���
		m_shieldId = 0;
		m_shield = nullptr;
		return;
	}
	m_shieldId = shield_id;
	m_shield = item;
}
//�A�C�e�����Q�Ƃ�����
void CHARA_DATA::attachItems()
{
	setWeapon(m_weaponId);//����
	setShield(m_shieldId);//��
}
//�A�r���e�B��ǉ�
void CHARA_DATA::addAbility(const crc32_t ability_id)
{
	CSingleton<CAbilityList> chara_ability_list;
	ABILITY_DATA* ability = chara_ability_list->find(ability_id);
	if (!ability)
		return;
	CSingleton<CCharaAbilityBuff> chara_ability_buff;
	CHARA_ABILITY_DATA* new_chara_ability = chara_ability_buff->assign();
	if (!new_chara_ability)
		return;
	new_chara_ability->m_next = nullptr;
	new_chara_ability->m_ability = ability;
	CHARA_ABILITY_DATA* chara_ability = m_abilities;
	while (chara_ability && chara_ability->m_next)
		chara_ability = chara_ability->m_next;
	if (chara_ability)
		chara_ability->m_next = new_chara_ability;
	else
		m_abilities = new_chara_ability;
}
//�A�r���e�B���擾
ABILITY_DATA* CHARA_DATA::getAbility(const int index)
{
	CHARA_ABILITY_DATA* chara_ability = m_abilities;
	for (int i = 0; i < index && chara_ability; ++i)
		chara_ability = chara_ability->m_next;
	return chara_ability == nullptr ? nullptr : chara_ability->m_ability;
}

//--------------------------------------------------------------------------------
//�e�X�g�f�[�^�p�f�[�^�m�F����

//--------------------
//�S�f�[�^���Z�b�g
void resetAll()
{
	printf("------------------------------------------------------------\n");
	printf("�y�S�f�[�^���Z�b�g�z\n");

	//�C���x���g���f�[�^�j��
	{
		CSingleton<CInventory> inventory;
		inventory.destroy();
	}
	//�A�r���e�B�f�[�^�j��
	{
		CSingleton<CAbilityList> ability_list;
		ability_list.destroy();
	}
	//�L�����f�[�^�j��
	{
		CSingleton<CCharaList> chara_list;
		chara_list.destroy();
	}
	//�L�����A�r���e�B�f�[�^�j��
	{
		CSingleton<CAbilityList> chara_ability_list;
		chara_ability_list.destroy();
	}
	//�t�F�[�Y���t���O�f�[�^�j��
	{
		CSingleton<CPhaseAndFlags> phase_and_flags;
		phase_and_flags.destroy();
	}
}

//--------------------
//�e�X�g�f�[�^�쐬
void makeTestData(const int pattern)
{
	printf("------------------------------------------------------------\n");
	printf("�y�e�X�g�f�[�^�쐬�z(pattern=%d)\n", pattern);

	//�C���x���g���f�[�^�o�^
	{
		CSingleton<CInventory> inventory;
		for (int i = 0; i < 5 + pattern * 10; i += (1 + pattern))
		{
			char id[8];
			char name[32];
		#ifdef USE_STRCPY_S
			sprintf_s(id, sizeof(id), "w%05d", (i + 1) * 10);
			sprintf_s(name, sizeof(name), "����%03d", i + 1);
		#else//USE_STRCPY_S
			sprintf(id, "w%05d", i);
			sprintf(name, "����%03d", i);
		#endif//USE_STRCPY_S
			ITEM_DATA item(id, name, 10 + i, i / 2, 0, 1);
			if (item.m_title && i > 0)
			{
			#ifdef USE_STRCPY_S
				sprintf_s(item.m_title, sizeof(item.m_titleBuff), "���\:+%d", i);
			#else//USE_STRCPY_S
				sprintf(item.m_title, "���\:+%d", i);
			#endif//USE_STRCPY_S
			}
			else
				item.m_title = nullptr;
			inventory->regist(item);
		}
		for (int i = 0; i < 5 + pattern * 10; i += (1 + pattern))
		{
			char id[8];
			char name[32];
		#ifdef USE_STRCPY_S
			sprintf_s(id, sizeof(id), "s%05d", (i + 1) * 10);
			sprintf_s(name, sizeof(name), "��%03d", i + 1);
		#else//USE_STRCPY_S
			sprintf(id, "s%05d", i);
			sprintf(name, "��%03d", i);
		#endif//USE_STRCPY_S
			ITEM_DATA item(id, name, 0, 5 + i, 0, 1);
			if (item.m_title && i > 0)
			{
			#ifdef USE_STRCPY_S
				sprintf_s(item.m_title, sizeof(item.m_titleBuff), "�O���[�h:%c", 'A' + i);
			#else//USE_STRCPY_S
				sprintf(item.m_title, "�O���[�h:%c", 'A' + i);
			#endif//USE_STRCPY_S
			}
			else
				item.m_title = nullptr;
			inventory->regist(item);
		}
		for (int i = pattern; i < 3 + pattern * 3; ++i)
		{
			char id[8];
			char name[32];
		#ifdef USE_STRCPY_S
			sprintf_s(id, sizeof(id), "r%05d", (i + 1) * 10);
			sprintf_s(name, sizeof(name), "�񕜖�%03d", i + 1);
		#else//USE_STRCPY_S
			sprintf(id, "r%05d", i);
			sprintf(name, "�񕜖�%03d", i);
		#endif//USE_STRCPY_S
			ITEM_DATA item(id, name, 0, 0, 5 + i * 2, 10);
			item.m_title = nullptr;
			inventory->regist(item);
		}
		inventory->sort();
	}
	//�A�r���e�B�f�[�^�o�^
	{
		CSingleton<CAbilityList> ability_list;
		for (int i = pattern; i < 10 + pattern * 10; ++i)
		{
			char id[8];
			char name[32];
		#ifdef USE_STRCPY_S
			sprintf_s(id, sizeof(id), "a%05d", (i + 1) * 10);
			sprintf_s(name, sizeof(name), "���Z%03d", i + 1);
		#else//USE_STRCPY_S
			sprintf(id, "a%05d", i);
			sprintf(name, "���Z%03d", i);
		#endif//USE_STRCPY_S
			ABILITY_DATA ability(id, name, 5 + i * 3, 4 + i * 2);
			ability_list->regist(ability);
		}
		ability_list->sort();
	}
	//�L�����f�[�^�o�^
	{
		CSingleton<CCharaList> chara_list;
		if (pattern & 1)
		{
			CHARA_DATA chara1("c00010", "���낤", 11, 15, 20, "w00030", "s00030", 111, 222, 333, 444);
			CHARA_DATA chara2("c00020", "���낤", 21, 25, 40, "w00050", "s00010", 999, 888, 777, 666);
			CHARA_DATA chara3("c00030", "���Ԃ낤", 31, 55, 3, "w00070", "s00050", 123, 456, 987, 654);
			CHARA_DATA chara4("c00040", "���낤", 41, 55, 3, "w00090", "s00090", 123, 456, 987, 654);
			chara1.addAbility("a00030");
			chara1.addAbility("a00010");
			chara3.addAbility("a00050");
			chara4.addAbility("a00020");
			chara_list->regist(chara1);
			chara_list->regist(chara2);
			chara_list->regist(chara3);
			chara_list->regist(chara4);
			chara_list->sort(true);
		}
		else
		{
			CHARA_DATA chara1("c00010", "���낤", 10, 15, 20, "w00020", "s00020", 111, 222, 333, 444);
			CHARA_DATA chara2("c00020", "���낤", 20, 25, 40, "w00050", "s00010", 999, 888, 777, 666);
			CHARA_DATA chara3("c00030", "���Ԃ낤", 30, 55, 3, "w00010", "s00030", 123, 456, 987, 654);
			chara1.addAbility("a00030");
			chara1.addAbility("a00020");
			chara1.addAbility("a00010");
			chara3.addAbility("a00050");
			chara_list->regist(chara1);
			chara_list->regist(chara2);
			chara_list->regist(chara3);
			chara_list->sort();
		}
	}
	//�i�s�f�[�^�X�V
	{
		CSingleton<CPhaseAndFlags> phase_and_flags;
		if (pattern & 1)
		{
			phase_and_flags->setPhase(3 + pattern);
			phase_and_flags->setFlag(1, true);
			phase_and_flags->setFlag(2 + pattern, true);
			phase_and_flags->setFlag(62, true);
		}
		else
		{
			phase_and_flags->setPhase(7 + pattern);
			phase_and_flags->setFlag(0, true);
			phase_and_flags->setFlag(2, true);
			phase_and_flags->setFlag(4, true);
			phase_and_flags->setFlag(5, true);
			phase_and_flags->setFlag(63 - pattern, true);
		}
	}
}

//--------------------
//���݂̃f�[�^��\��
void printDataAll()
{
	printf("------------------------------------------------------------\n");
	printf("�y���݂̃f�[�^��\���z\n");

	//�C���x���g���f�[�^�\��
	printf("--- �C���x���g�� ---\n");
	{
		CSingleton<CInventory> inventory;
		for (auto& ite : *inventory)
		{
			printf("ID=\"%s\"(0x%08x), name=\"%s\", atk=%d, def=%d, recover=%d, num=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_basic.m_atk, ite->m_basic.m_def, ite->m_recover, ite->m_num);
			if (ite->m_title)
				printf("                              title=\"%s\"\n", ite->m_title);
		}
	}
	//�A�r���e�B�f�[�^�\��
	printf("--- �A�r���e�B ---\n");
	{
		CSingleton<CAbilityList> ability_list;
		for (auto& ite : *ability_list)
		{
			printf("ID=\"%s\"(0x%08x), name=\"%s\", atk=%d, def=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_basic.m_atk, ite->m_basic.m_def);
		}
	}
	//�L�����f�[�^�\��
	printf("--- �L���� ---\n");
	{
		CSingleton<CCharaList> chara_list;
		for (auto& ite : *chara_list)
		{
			printf("ID=\"%s\"(0x%08x), name=\"%s\", level=%d, atk=%d, def=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_level, ite->m_basic.m_atk, ite->m_basic.m_def);
			printf("                              param1={%d, %d}, param2={%d, %d}\n",
				ite->m_param1[0], ite->m_param1[1], ite->m_param2[0], ite->m_param2[1]);
			if (ite->m_weapon)
				printf("                              weapon=%s\n", ite->m_weapon->m_name.c_str());
			if (ite->m_shield)
				printf("                              shield=%s\n", ite->m_shield->m_name.c_str());
			for (int i = 0;; ++i)
			{
				const ABILITY_DATA* ability = ite->getAbility(i);
				if (!ability)
					break;
				printf("                              [%s]\n", ability->m_name.c_str());
			}
		}
	}
	//�i�s�f�[�^�\��
	printf("--- �i�s�f�[�^ ---\n");
	{
		CSingleton<CPhaseAndFlags> phase_flags;
		printf("pahse=%d\n", phase_flags->getPhase());
		printf("flags=\n");
		for (unsigned int i = 0; i < phase_flags->getFlags().size(); ++i)
		{
			if (i > 0 && i % 16 == 0)
				printf("\n");
			printf(" %d", phase_flags->getFlag(i));
		}
		printf("\n");
	}
}

//--------------------------------------------------------------------------------
//�e�X�g�f�[�^�p�V���A���C�Y

//--------------------
//�Z�[�u�f�[�^�p��{�N���X
class CSaveData{};

//--------------------
//�Z�[�u�f�[�^�o�[�W�����Ǘ��N���X
class CSaveDataVersion
{
public:
	//�萔
	static const int MAJOR_VER = 1;//���W���[�o�[�W����
	static const int MINOR_VER = 0;//�}�C�i�[�o�[�W����
public:
	//�A�N�Z�b�T
	int getMajorVer() const { return MAJOR_VER; }//���W���[�o�[�W�����擾
	int getMinorVer() const { return MINOR_VER; }//�}�C�i�[�o�[�W�����擾
	int getLoadedMajorVer() const { return m_loadedMajorVer; }//�Z�[�u�f�[�^���烍�[�h�������W���[�o�[�W�����擾
	int getLoadedMinorVer() const { return m_loadedMinorVer; }//�Z�[�u�f�[�^���烍�[�h�����}�C�i�[�o�[�W�����擾
	bool hasSaved() const { return m_hasSaved; }//�Z�[�u�������H
	bool hasLoaded() const { return m_hasLoaded; }//���[�h�������H
private:
	void setHasSaved(){ m_hasSaved = true; }//�Z�[�u�������Ƃɂ���
	void setHasLoaded(){ m_hasLoaded = true; }//���[�h�������Ƃɂ���
	void resetHasSaved(){ m_hasSaved = false; }//�Z�[�u�������Ƃ������Ԃ�����
	void resetHasLoaded(){ m_hasLoaded = false; }//���[�h�������Ƃ������Ԃ�����
public:
	//���\�b�h
	//���[�h�����o�[�W���������݂̃o�[�W�����ɍX�V
	void updateLoadedVer()
	{
		m_loadedMajorVer = MAJOR_VER;//�Z�[�u�f�[�^���烍�[�h�������W���[�o�[�W�����擾
		m_loadedMinorVer = MINOR_VER;//�Z�[�u�f�[�^���烍�[�h�����}�C�i�[�o�[�W�����擾
	}
public:
	//�R���X�g���N�^
	CSaveDataVersion() :
		m_loadedMajorVer(0),
		m_loadedMinorVer(0),
		m_hasSaved(false),
		m_hasLoaded(false)
	{}
	//�f�X�g���N�^
	~CSaveDataVersion()
	{}
private:
	//�t�B�[���h
	int m_loadedMajorVer;//�Z�[�u�f�[�^���烍�[�h�������W���[�o�[�W�����擾
	int m_loadedMinorVer;//�Z�[�u�f�[�^���烍�[�h�����}�C�i�[�o�[�W�����擾
	bool m_hasSaved;//�Z�[�u�������H
	bool m_hasLoaded;//���[�h�������H
	//�V���A���C�Y�p�̃t�����h�ݒ�
	FRIEND_SERIALIZE(CSaveDataVersion);
};
//--------------------
//�Z�[�u�f�[�^�p�o�[�W������\��
void printSaveDataVer()
{
	printf("------------------------------------------------------------\n");
	printf("�y�Z�[�u�f�[�^�o�[�W�����z\n");
	
	CSingleton<CSaveDataVersion> save_data_version;
	printf("���݂̃o�[�W����:                 %d.%d\n", save_data_version->getMajorVer(), save_data_version->getMinorVer());
	printf("���[�h�ς�or�Z�[�u�ς݃o�[�W����: %d.%d\n", save_data_version->getLoadedMajorVer(), save_data_version->getLoadedMinorVer());
	printf("�E�Z�[�u�������H = %s\n", save_data_version->hasSaved() ? "yes" : "no");
	printf("�E���[�h�������H = %s\n", save_data_version->hasLoaded() ? "yes" : "no");
}

//--------------------
//�e�X�g�p�N���X�̃V���A���C�Y������`
namespace serial
{
	//--------------------
	//�V���A���C�Y�����Fstd::bitset<>
	template<class Arc, std::size_t N>
	struct serialize<Arc, std::bitset<N> > {
		void operator()(Arc& arc, const std::bitset<N>& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pairBin("bitset", obj);
		}
	};
	//--------------------
	//�V���A���C�Y�����FCStr<>
	template<class Arc, std::size_t S>
	struct serialize<Arc, CStr<S> > {
		void operator()(Arc& arc, const CStr<S>& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("len", obj.m_len);
			arc & pairStr("str", obj.m_str);
		}
	};
	//--------------------
	//�V���A���C�Y�����FCStrWithCRC<>
	template<class Arc, std::size_t S>
	struct serialize<Arc, CStrWithCRC<S> > {
		void operator()(Arc& arc, const CStrWithCRC<S>& obj, const CVersion& ver, const CVersion& now_ver)
		{
			serialize<Arc, typename CStrWithCRC<S>::CParent> parent;
			parent(arc, obj, ver, now_ver);//�e�N���X�̃V���A���C�Y���Ăяo��
			arc & pair("crc", obj.m_crc);
		}
	};
	//--------------------
	//�V���A���C�Y�����FBASIC_DATA
	template<class Arc>
	struct serialize<Arc, BASIC_DATA> {
		void operator()(Arc& arc, const BASIC_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("atk", obj.m_atk);
			arc & pair("def", obj.m_def);
		}
	};
	//--------------------
	//�V���A���C�Y�����FITEM_DATA
	template<class Arc>
	struct serialize<Arc, ITEM_DATA> {
		void operator()(Arc& arc, const ITEM_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("id", obj.m_id);
			arc & pair("name", obj.m_name);
			arc & pairStr("title", obj.m_title, sizeof(obj.m_titleBuff));//�ϒ�������i�|�C���^�j�̃e�X�g
			//arc & pairArray("title", obj.m_title, sizeof(obj.m_titleBuff));//�z��Ƃ��Ĉ������Ƃ���
			arc & pair("basic", obj.m_basic);
			arc & pair("recover", obj.m_recover);
			arc & pair("num", obj.m_num);
		}
	};
	//--------------------
	//���[�h�㏈���FITEM_DATA
	template<class Arc>
	struct afterLoad<Arc, ITEM_DATA> {
		void operator()(Arc& arc, ITEM_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			if (obj.m_title[0] == '\0')//��������Ȃ������^�C�g����nullptr�ɂ���
				obj.m_title = nullptr;
		}
	};
	//--------------------
	//�V���A���C�Y�����FABILITY_DATA
	template<class Arc>
	struct serialize<Arc, ABILITY_DATA> {
		void operator()(Arc& arc, const ABILITY_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("id", obj.m_id);
			arc & pair("name", obj.m_name);
			arc & pair("basic", obj.m_basic);
		}
	};
	//--------------------
	//�V���A���C�Y�����FCHARA_DATA
	template<class Arc>
	struct serialize<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("id", obj.m_id);
			arc & pair("name", obj.m_name);
			arc & pair("level", obj.m_level);
			//arc & pair("basic", obj.m_basic);//�Z�[�u�f�[�^�ɂ����Ȃ��I�u�W�F�N�g�̃V�~�����[�V����
			arc & pair("weapon", obj.m_weaponId);
			arc & pair("shield", obj.m_shieldId);
			//arc & pair("param1", obj.m_param1);//�Z�[�u�f�[�^�ɂ����Ȃ��f�[�^�̃V�~�����[�V����
			//arc & pair("param2", obj.m_param1);//�Z�[�u�f�[�^���Ȃ��f�[�^�̃V�~�����[�V����
		}
	};
	//--------------------
	//�V���A���C�Y��p�����FCHARA_DATA
	template<class Arc>
	struct save<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver)
		{
			arc & pair("param1", obj.m_param1);//�Z�[�u�f�[�^�ɂ����Ȃ��f�[�^�̃V�~�����[�V����
			arc & pair("basic", obj.m_basic);//�Z�[�u�f�[�^�ɂ����Ȃ��I�u�W�F�N�g�̃V�~�����[�V����
		}
	};
	//--------------------
	//�f�V���A���C�Y��p�����FCHARA_DATA
	template<class Arc>
	struct load<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver, CVersion& now_ver)
		{
			arc & pair("param2", obj.m_param2);//�Z�[�u�f�[�^���Ȃ��f�[�^�̃V�~�����[�V����
		}
	};
	//--------------------
	//�Z�[�u�f�[�^�ɂ͂��������A�ۑ���̎w�肪�Ȃ��A���[�h�ł��Ȃ��������ڂ̒ʒm
	template<class Arc>
	struct noticeUnrecognizedItem<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unrecognized_item)
		{
			if (unrecognized_item == "param1")
			{
				arc & pair("param1", obj.m_param1);//�Z�[�u�f�[�^�ɂ����Ȃ��f�[�^�̃V�~�����[�V����
			}
			else if (unrecognized_item == "basic")
			{
				arc & pair("basic", obj.m_basic);//�Z�[�u�f�[�^�ɂ����Ȃ��f�[�^�̃V�~�����[�V����
			}
		}
	};
	//--------------------
	//�ۑ���̎w�肪���邪�A�Z�[�u�f�[�^�ɂȂ����[�h�ł��Ȃ��������ڂ̒ʒm
	template<class Arc>
	struct noticeUnloadedItem<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unloaded_item)
		{
			if (unloaded_item == "param2")
			{
				obj.m_param2[0] = 98765;
				obj.m_param2[1] = 43210;
			}
		}
	};
	//--------------------
	//���[�h�㏈���FCHARA_DATA
	template<class Arc>
	struct afterLoad<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, const CVersion& ver, const CVersion& now_ver)
		{
			CSingleton<CInventory> inventory;
			obj.m_weapon = inventory->find(obj.m_weaponId);//����̃|�C���^�𕜌�
			obj.m_shield = inventory->find(obj.m_shieldId);//���̃|�C���^�𕜌�
			obj.m_abilities = nullptr;//�A�r���e�B�͈�Unullptr�ɂ��Ă���
		}
	};
	//--------------------
	//���W�����FCHARA_DATA
	template<class Arc>
	struct collector<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver)
		{
			CHARA_ABILITY_DATA* chara_ability = obj.m_abilities;
			while (chara_ability)
			{
				//�A�r���e�B���擾
				ABILITY_DATA* ability_data = chara_ability->m_ability;
				//�Z�[�u�p�A�r���e�B���쐬
				//���ꎞ�I�Ƀ��[�J���ϐ��ɋL�^���������Z�[�u����
				CHARA_ABILITY_DATA_FOR_SAVE chara_ability_data_for_save;
				//chara_ability_data_for_save.m_charaId = obj.m_id.getKey();//�A�r���e�BID
				chara_ability_data_for_save.m_abilityId = ability_data->getKey();//�A�r���e�BID
				//�V���A���C�Y
				arc << pair("charaAbility", chara_ability_data_for_save);
				//���̃A�r���e�B
				chara_ability = chara_ability->m_next;
			}
		}
	};
	//--------------------
	//���z�����FCHARA_DATA
	template<class Arc>
	struct distributor<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{
			if (target_item == "charaAbility")
			{
				//�Z�[�u�p�A�r���e�B��񕜌�
				//���ꎞ�I�Ƀ��[�J���ϐ��ɓW�J���Ď��ۂ̃f�[�^�ɔ��f������
				CHARA_ABILITY_DATA_FOR_SAVE chara_ability_data_for_save;
				//�f�V���A���C�Y
				arc >> pair("charaAbility", chara_ability_data_for_save);
				//�A�r���e�B�ǉ�
				obj.addAbility(chara_ability_data_for_save.m_abilityId);
			}
		}
	};
	//--------------------
	//�V���A���C�Y�����FCHARA_ABILITY_DATA_FOR_SAVE
	template<class Arc>
	struct serialize<Arc, CHARA_ABILITY_DATA_FOR_SAVE> {
		void operator()(Arc& arc, const CHARA_ABILITY_DATA_FOR_SAVE& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("id", obj.m_abilityId);
		}
	};
	//--------------------
	//�V���A���C�Y�����FCPhaseAndFlags
	template<class Arc>
	struct serialize<Arc, CPhaseAndFlags> {
		void operator()(Arc& arc, const CPhaseAndFlags& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("phase", obj.m_phase);
			arc & pair("flags", obj.m_flags);
		}
	};
	//--------------------
	//�V���A���C�Y�����FCSaveDataVersion
	template<class Arc>
	struct serialize<Arc, CSaveDataVersion> {
		void operator()(Arc& arc, const CSaveDataVersion& obj, const CVersion& ver, const CVersion& now_ver)
		{
			arc & pair("major", obj.m_loadedMajorVer);
			arc & pair("minor", obj.m_loadedMinorVer);
		}
	};
	//--------------------
	//���W�����FCSaveData
	template<class Arc>
	struct collector<Arc, CSaveData> {
		void operator()(Arc& arc, const CSaveData& obj, const CVersion& ver)
		{
			//�Z�[�u�f�[�^�o�[�W�����̃o�[�W������ۑ��p�ɍX�V
			CSingleton<CSaveDataVersion> save_data_version;
			save_data_version->updateLoadedVer();
			arc << pair("version", *save_data_version);//�V���A���C�Y
			save_data_version->setHasSaved();

			//�C���x���g���̃f�[�^�����W
			CSingleton<CInventory> inventory;
			for (auto item_data : *inventory)
			{
				//�A�C�e���f�[�^������V���A���C�Y
				arc << pair("item", *item_data);
			}
			//�A�r���e�B�̃f�[�^�����W
			CSingleton<CAbilityList> ability_list;
			for (auto ability_data : *ability_list)
			{
				//�A�r���e�B�f�[�^������V���A���C�Y
				arc << pair("ability", *ability_data);
			}
			//�L�����̃f�[�^�����W
			CSingleton<CCharaList> chara_list;
			for (auto chara_data : *chara_list)
			{
				//�L�����f�[�^������V���A���C�Y
				arc << pair("chara", *chara_data);
			}
			//�i�s���t���O�f�[�^���V���A���C�Y
			CSingleton<CPhaseAndFlags> phase_and_flags;
			arc << pair("phase_and_flags", *phase_and_flags);
		}
	};
	//--------------------
	//�v���I�ȃG���[���������������FCSaveData
	template<class Arc>
	struct fatalSerializeErrorOccurred<Arc, CSaveData> {
		void operator()(Arc& arc, const CSaveData& obj, const CVersion& ver)
		{
			printf("�V���A���C�Y�Œv���I�ȃG���[�����I\n");
		}
	};
	//--------------------
	//�������[�h�Ή������FCSaveData
	crc32_t s_loadTarget;//���[�h�Ώ�
	void setLoadTarget(const crc32_t loada_target)//���[�h�Ώۂ��Z�b�g
	{
		s_loadTarget = loada_target;
	}
	void setLoadTarget(const char* name)//���[�h�Ώۂ��Z�b�g
	{
		setLoadTarget(calcCRC32(name));
	}
	void resetLoadTarget()//���[�h�Ώۂ����Z�b�g
	{
		s_loadTarget = 0;
	}
	bool isLoadTarget(const crc32_t name_crc)//���[�h�Ώۂ��H
	{
		return s_loadTarget == 0 || s_loadTarget == name_crc;
	}
	bool isLoadTarget(const char* name)//���[�h�Ώۂ��H
	{
		return isLoadTarget(calcCRC32(name));
	}
	bool isLoadTarget(const CItemBase& item)//���[�h�Ώۂ��H
	{
		return isLoadTarget(item.m_nameCrc);
	}
	bool isPartLoad()//�������[�h���H
	{
		return s_loadTarget != 0;
	}
	bool isPartLoad(const crc32_t name_crc)//�������[�h���H
	{
		return isPartLoad() && isLoadTarget(name_crc);
	}
	bool isPartLoad(const char* name)//�������[�h���H
	{
		return isPartLoad() && isLoadTarget(name);
	}
	//--------------------
	//���z�O�����FCSaveData
	template<class Arc>
	struct beforeDistribute<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver)
		{
			if (isLoadTarget("item"))
			{
				//�C���x���g���f�[�^�N���A
				CSingleton<CInventory> inventory;
				inventory.destroy();
			}
			if (isLoadTarget("ability"))
			{
				//�A�r���e�B�f�[�^�N���A
				CSingleton<CAbilityList> ability_list;
				ability_list.destroy();
			}
			if (isLoadTarget("chara"))
			{
				//�L�����f�[�^�N���A
				CSingleton<CCharaList> chara_list;
				chara_list.destroy();
			}
			if (isLoadTarget("ability") || isLoadTarget("chara"))
			{
				//�L�����ۗL�A�r���e�B�f�[�^�N���A
				CSingleton<CCharaAbilityBuff> chara_ability_list;
				chara_ability_list.destroy();
			}
			if (isLoadTarget("phase_and_flags"))
			{
				//�t�F�[�Y���i�s�f�[�^�N���A
				CSingleton<CPhaseAndFlags> phase_and_flags;
				phase_and_flags.destroy();
			}
		}
	};
	//--------------------
	//���z�����FCSaveData
	template<class Arc>
	struct distributor<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
		{
			if (target_item == "version")
			{
				//�Z�[�u�f�[�^�o�[�W����
				CSingleton<CSaveDataVersion> save_data_version;
				arc >> pair("version", *save_data_version);//�f�V���A���C�Y
				save_data_version->setHasLoaded();
			}
			else if (target_item == "item" && isLoadTarget(target_item))
			{
				//�C���x���g���f�[�^����
				CSingleton<CInventory> inventory;
				ITEM_DATA item_data;
				arc >> pair("item", item_data);//�f�V���A���C�Y
				inventory->regist(item_data);
			}
			else if (target_item == "ability" && isLoadTarget(target_item))
			{
				//�A�r���e�B�f�[�^����
				CSingleton<CAbilityList> ability_list;
				ABILITY_DATA ability_data;
				arc >> pair("ability", ability_data);
				ability_list->regist(ability_data);
			}
			else if (target_item == "chara" && isLoadTarget(target_item))
			{
				//�L�����f�[�^����
				CSingleton<CCharaList> chara_list;
				CHARA_DATA chara_data;
				arc >> pair("chara", chara_data);
				chara_list->regist(chara_data);
			}
			else if (target_item == "phase_and_flags" && isLoadTarget(target_item))
			{
				//�t�F�[�Y���i�s�f�[�^����
				CSingleton<CPhaseAndFlags> phase_and_flags;
				arc >> pair("phase_and_flags", *phase_and_flags);
			}
		}
	};
	//--------------------
	//���z�㏈���FCSaveData
	template<class Arc>
	struct afterDistribute<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, const CVersion& ver, const CVersion& now_ver)
		{
			//�C���x���g���f�[�^�����������ăL�����f�[�^�����̂܂܂Ȃ畐��Ə����Q�Ƃ�����
			if (isPartLoad("item") && !isPartLoad("chara"))
			{
				CSingleton<CCharaList> chara_list;
				for (auto& chara_data : *chara_list)
				{
					chara_data->attachItems();//�A�C�e�����Q�Ƃ�����
				}
			}
		}
	};
	//--------------------
	//�v���I�ȃG���[���������������FCSaveData
	template<class Arc>
	struct fatalDeserializeErrorOccurred<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const CVersion& ver, const CVersion& now_ver)
		{
			printf("�f�V���A���C�Y�Œv���I�ȃG���[�����I\n");
#if 1
			//�C���x���g���f�[�^�N���A
			CSingleton<CInventory> inventory;
			inventory.destroy();
			//�A�r���e�B�f�[�^�N���A
			CSingleton<CAbilityList> ability_list;
			ability_list.destroy();
			//�L�����f�[�^�N���A
			CSingleton<CCharaList> chara_list;
			chara_list.destroy();
			//�L�����ۗL�A�r���e�B�f�[�^�N���A
			CSingleton<CCharaAbilityBuff> chara_ability_list;
			chara_ability_list.destroy();
			//�t�F�[�Y���i�s�f�[�^�N���A
			CSingleton<CPhaseAndFlags> phase_and_flags;
			phase_and_flags.destroy();
#endif
		}
	};
}

//--------------------
//�V���A���C�Y
template<class Arc>
std::size_t serialize(void* save_data_buff, const std::size_t save_data_buff_size)
{
	printf("------------------------------------------------------------\n");
	printf("�y�V���A���C�Y�z\n");
	
	//���[�N�o�b�t�@����
	const std::size_t WORK_BUFF_SIZE = 1 * 1024 * 1024;
	void* work_buff = new char[WORK_BUFF_SIZE];

	//�V���A���C�Y�p�A�[�J�C�u�I�u�W�F�N�g����
	Arc arc(save_data_buff, save_data_buff_size, work_buff, WORK_BUFF_SIZE);

	//�V���A���C�Y
	arc << serial::pair<CSaveData>("SaveData");

	//�V���A���C�Y�̌��ʂ�\��
	serial::CResult result = arc.getResult();
	printf("�V���A���C�Y���ʁF\n");
	printf("  �v���I�ȃG���[ ... %s\n", result.hasFatalError() ? "�����I" : "�Ȃ�");

	//�Z�[�u�f�[�^�̃T�C�Y��Ԃ�
	return result.getSaveDataSize();
}

//--------------------
//�f�V���A���C�Y
template<class Arc>
void deserialize(void* save_data, const std::size_t save_data_size)
{
	printf("------------------------------------------------------------\n");
	printf("�y�f�V���A���C�Y�z\n");
	
	//���[�N�o�b�t�@����
	const std::size_t WORK_BUFF_SIZE = 1 * 1024 * 1024;
	void* work_buff = new char[WORK_BUFF_SIZE];

	//�V���A���C�Y�p�A�[�J�C�u�I�u�W�F�N�g����
	Arc arc(save_data, save_data_size, work_buff, WORK_BUFF_SIZE);

	//�f�V���A���C�Y
	arc >> serial::pair<CSaveData>("SaveData");

	//�f�V���A���C�Y�̌��ʂ�\��
	serial::CResult result = arc.getResult();
	printf("�f�V���A���C�Y���ʁF\n");
	printf("  �v���I�ȃG���[ ... %s\n", result.hasFatalError() ? "�����I" : "�Ȃ�");
	printf("  �ȉ��A�Z�[�u�f�[�^�̏�Ԃɑ΂��錻�݂̃v���O�������ς���Ă����ӏ��̏W�v\n");
	printf("  �E�T�C�Y���k�����ꂽ���ڂ̐�           = %d\n", result.getNumSmallerSizeItem());
	printf("  �E�T�C�Y���g�傳�ꂽ���ڂ̐�           = %d\n", result.getNumLargerSizeItem());
	printf("  �E�z��T�C�Y���k�����ꂽ���ڂ̐�       = %d\n", result.getNumSmallerArrItem());
	printf("  �E�z��T�C�Y���g�傳�ꂽ���ڂ̐�       = %d\n", result.getNumLargerArrItem());
	printf("  �E�Z�[�u�f�[�^��ɂ̂ݑ��݂������ڂ̐� = %d\n", result.getNumIsOnlyOnSaveData());
	printf("  �E�Z�[�u�f�[�^��ɂȂ��������ڂ̐�     = %d\n", result.getNumIsOnlyOnMem());
	printf("  �E���݂̓I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂������������ڂ̐� = %d\n", result.getNumIsObjOnSaveDataOnly());
	printf("  �E���݂̓I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ��������ڂ̐� = %d\n", result.getNumIsObjOnMemOnly());
	printf("  �E���݂͔z��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂������������ڂ̐�         = %d\n", result.getNumIsArrOnSaveDataOnly());
	printf("  �E���݂͔z��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ��������ڂ̐�         = %d\n", result.getNumIsArrOnMemOnly());
	printf("  �E���݂̓|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂������������ڂ̐�     = %d\n", result.getNumIsPtrOnSaveDataOnly());
	printf("  �E���݂̓|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ��������ڂ̐�     = %d\n", result.getNumIsPtrOnMemOnly());
	printf("  �E���݂̓k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂������������ڂ̐�           = %d\n", result.getNumIsNulOnSaveDataOnly());
	printf("  �E���݂̓k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ��������ڂ̐�           = %d\n", result.getNumIsNulOnMemOnly());
}

//--------------------
//�Z�[�u
void save(const char* file_path, const void* file_image, const std::size_t file_image_size)
{
	printf("------------------------------------------------------------\n");
	printf("�y�Z�[�u�z\n");
	printf("file=\"%s\", size=%d\n", file_path, file_image_size);
	if (file_image_size == 0)
	{
		printf("Save data not found!\n");
		return;
	}

	FILE* fp;
#ifdef USE_STRCPY_S
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(file_image, 1, file_image_size, fp);
	fclose(fp);
}

//--------------------
//�t�@�C���T�C�Y�擾
std::size_t getFileSize(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
	const std::size_t file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return file_size;
}

//--------------------
//���[�h
std::size_t load(const char* file_path, void* file_image_buff, const std::size_t file_image_buff_size_max)
{
	printf("------------------------------------------------------------\n");
	printf("�y���[�h�z\n");

	FILE* fp;
#ifdef USE_STRCPY_S
	fopen_s(&fp, file_path, "rb");
#else//USE_STRCPY_S
	fp = fopen(file_path, "rb");
#endif//USE_STRCPY_S
	std::size_t file_image_size = getFileSize(fp);
	printf("file=\"%s\", size=%d\n", file_path, file_image_size);
	if (file_image_size <= file_image_buff_size_max)
		fread(file_image_buff, 1, file_image_size, fp);
	else
		file_image_size = 0;
	fclose(fp);
	return file_image_size;
}

//--------------------
//�V���A���C�Y���Z�[�u
template<class Arc>
void serializeAndSave(const char* file_path)
{
	//�Z�[�u�f�[�^�p�o�b�t�@����
	const std::size_t SAVE_DATA_BUFF_SIZE = 1 * 1024 * 1024;
	void* save_data_buff = new char[SAVE_DATA_BUFF_SIZE];

	//�V���A���C�Y
	const std::size_t save_data_size = serialize<Arc>(save_data_buff, SAVE_DATA_BUFF_SIZE);

	//�Z�[�u
	save(file_path, save_data_buff, save_data_size);
}

//--------------------
//���[�h���f�V���A���C�Y
template<class Arc>
void loadAndDeserialize(const char* file_path)
{
	//�Z�[�u�f�[�^�p�o�b�t�@����
	const std::size_t SAVE_DATA_BUFF_SIZE = 1 * 1024 * 1024;
	void* save_data_buff = new char[SAVE_DATA_BUFF_SIZE];

	//���[�h
	const std::size_t save_data_size = load(file_path, save_data_buff, SAVE_DATA_BUFF_SIZE);

	//�f�V���A���C�Y
	deserialize<Arc>(save_data_buff, save_data_size);
}

//--------------------------------------------------------------------------------
//�e�X�g���s

//--------------------
//�V���A���C�Y
void test2serialize()
{
	//�S�f�[�^���Z�b�g
	resetAll();
	//�e�X�g�f�[�^�쐬(pattern=1)
	makeTestData(0);
	//���݂̃f�[�^��\��
	printDataAll();
	//�Z�[�u�f�[�^�p�o�[�W������\��
	printSaveDataVer();
	//�t�@�C���p�X���A�[�J�C�u�I�u�W�F�N�g
	const char* save_file_name_bin = "save_data.bin";
	const char* save_file_name_txt = "save_data.txt";
	//�V���A���C�Y���Z�[�u
	serializeAndSave<serial::COBinaryArchive>(save_file_name_bin);//�o�C�i���`�����g�p
	serializeAndSave<serial::COTextArchive>(save_file_name_txt);//�e�L�X�g�`�����g�p
	//�Z�[�u�f�[�^�p�o�[�W������\��
	printSaveDataVer();
	//�S�f�[�^���Z�b�g
	resetAll();
	//���݂̃f�[�^��\��
	printDataAll();
	//���[�h���f�V���A���C�Y
	loadAndDeserialize<serial::CIBinaryArchive>(save_file_name_bin);
	//�Z�[�u�f�[�^�p�o�[�W������\��
	printSaveDataVer();
	//���݂̃f�[�^��\��
	printDataAll();
	//�S�f�[�^���Z�b�g
	resetAll();
	//�e�X�g�f�[�^�쐬(pattern=1)
	makeTestData(1);
	//���݂̃f�[�^��\��
	printDataAll();
	//�������[�h�w��
	//serial::setLoadTarget("phase_and_flags");
	serial::setLoadTarget("chara");
	//���[�h���f�V���A���C�Y
	loadAndDeserialize<serial::CIBinaryArchive>(save_file_name_bin);
	//���݂̃f�[�^��\��
	printDataAll();
	//�������[�h�w�����
	serial::resetLoadTarget();
}

//--------------------
//�e�X�g
void test2()
{
	//�V���A���C�Y
	test2serialize();
}

//--------------------------------------------------------------------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	test1();
	test2();
	return EXIT_SUCCESS;
}

// End of file
