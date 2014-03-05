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
	//--------------------
	//�N���X�錾
	class CItemBase;
	
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
		bool operator<(const CVersion& rhs) const { return m_ver <= rhs.m_ver; }
		bool operator<=(const CVersion& rhs) const { return m_ver < rhs.m_ver; }
		bool operator>(const CVersion& rhs) const { return m_ver >= rhs.m_ver; }
		bool operator>=(const CVersion& rhs) const { return m_ver > rhs.m_ver; }
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
	//�Z�[�u�f�[�^�ɂ͂��������A�ۑ���̎w�肪�Ȃ��A���[�h�ł��Ȃ��������ڂ̒ʒm
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//�����������玞�_�Œm�����̂ŁAobj���s���S�ȏ�Ԃł���_�ɒ���
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct noticeUnconsciousItem {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unconcious_item)
		{}
	};
	//--------------------
	//�ۑ���̎w�肪���邪�A�Z�[�u�f�[�^�ɂȂ����[�h�ł��Ȃ��������ڂ̒ʒm
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//��obj�̃��[�h����ʂ�I��������ƁA�܂Ƃ߂Ēʒm����
	//��noticeUnconsciousItem �̌�AafterLoad ����Ɏ��s�����
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct noticeUnloadedItem {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unloaded_item)
		{}
	};
	//--------------------
	//���[�h�㏈���p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//��obj�̃��[�h����ʂ�I��������Ǝ��s�����
	//��noticeUnconsciousItem, noticeUnconsciousItem �̌�Ɏ��s�����
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct afterLoad {
		typedef int IS_UNDEFINED;//SFINAE�p:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`
		void operator()(Arc& arc, T& obj, const CVersion& ver, const CVersion& now_ver)
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
		void operator()(Arc& arc, T& obj, const std::size_t array_num_on_save_data, const std::size_t array_num_loaded, CVersion& ver, const CVersion& now_ver, const CItemBase& target_item)
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
		return isDefinedFunctor<beforeLoad<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<serialize<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<save<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<load<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<noticeUnconsciousItem<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<noticeUnloadedItem<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<afterLoad<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<collector<CArchiveDummy, T> >(0) ||
			isDefinedFunctor<distributor<CArchiveDummy, T> >(0);
	}

	//--------------------
	//�ۑ����
	enum recInfoEnum : unsigned char
	{
		IS_OBJECT = 0x01,//�I�u�W�F�N�g�^
		IS_ARRAY = 0x02,//�z��^
		IS_PTR = 0x04,//�|�C���^�^
		IS_NULL = 0x08,//�k��
		HAS_VERSION = 0x10,//�o�[�W������񂠂�
	};
	class CRecInfo
	{
	public:
		//�^
		typedef unsigned char value_t;//�ۑ���Ԍ^
	public:
		//�A�N�Z�b�T
		bool isObj() const { return (m_value & IS_OBJECT) ? true : false; }//�I�u�W�F�N�g�^���H
		bool isArr() const { return (m_value & IS_ARRAY) ? true : false; }//�z��^���H
		bool isPtr() const { return (m_value & IS_PTR) ? true : false; }//�|�C���^�^���H
		bool isNul() const { return (m_value & IS_NULL) ? true : false; }//�k���|�C���^���H�i�|�C���^�^�̎�����������j
		bool hasVersion() const { return (m_value & HAS_VERSION) ? true : false; }//�o�[�W������񂪂��邩�H
		void setHasVersion() const { *const_cast<value_t*>(&m_value) = m_value | HAS_VERSION; }//�o�[�W������񂠂�ɂ���
		void resetHasVersion() const { *const_cast<value_t*>(&m_value) = m_value & ~HAS_VERSION; }//�o�[�W�������Ȃ��ɂ���
	public:
		//�I�y���[�^
		bool operator==(const CRecInfo& rhs) const { return m_value == rhs.m_value; }
		bool operator!=(const CRecInfo& rhs) const { return m_value != rhs.m_value; }
		//�R�s�[�I�y���[�^
		CRecInfo& operator=(const CRecInfo& src)
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
		CRecInfo(const value_t info) :
			m_value(info)
		{}
		CRecInfo(const bool is_object, const bool is_array, const bool is_ptr, const bool is_null) :
			m_value(
				(is_object ? IS_OBJECT : 0) |
				(is_array ? IS_ARRAY : 0) |
				(is_ptr ? IS_PTR : 0) |
				(is_ptr && is_null ? IS_NULL : 0)
				)
		{}
		//�f�X�g���N�^
		~CRecInfo()
		{}
	public://���ڃA�N�Z�X����
		//�t�B�[���h
		const value_t m_value;//�ۑ����
	};
	//--------------------
	//�f�[�^���ڊ��N���X
	class CItemBase
	{
	public:
		//�A�N�Z�b�T
		bool isObj() const { return m_info.isObj(); }//�I�u�W�F�N�g�^���H
		bool isArr() const { return m_info.isArr(); }//�z��^���H
		bool isPtr() const { return m_info.isPtr(); }//�|�C���^�^���H
		bool isNul() const { return m_info.isNul(); }//�k�����H
		std::size_t getElemNum() const //�v�f�����擾
		{
			return m_arrNum == 0 ?
						1 :
						m_arrNum;
		}
		std::size_t getMinimumElemNum() const //�ŏ��v�f�����擾
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
		bool nowIsObj() const { return m_hasNowInfo && m_nowInfo.isObj(); }//���݂̃f�[�^�̓I�u�W�F�N�g�^���H
		bool nowIsArr() const { return m_hasNowInfo && m_nowInfo.isArr(); }//���݂̃f�[�^�͔z��^���H
		bool nowIsPtr() const { return m_hasNowInfo && m_nowInfo.isPtr(); }//���݂̃f�[�^�̓|�C���^�^���H
		bool nowIsNul() const { return m_hasNowInfo && m_nowInfo.isNul(); }//���݂̃f�[�^�̓k�����H
		bool nowAndSaveDataIsSameRecInfo() const { return m_hasNowInfo && m_nowInfo == m_info; }//���݂̃f�[�^�ƃZ�[�u�f�[�^�̕ۑ���񂪈�v���邩�H
		bool nowAndSaveDataIsdifferentRecInfo() const { return m_hasNowInfo && m_nowInfo != m_info; }//���݂̃f�[�^�ƃZ�[�u�f�[�^�̕ۑ���񂪈�v���Ȃ����H
		bool nowAndSaveDataIsObj() const { return m_hasNowInfo && m_nowInfo.isObj() && m_info.isObj(); }//���݂̃f�[�^���Z�[�u�f�[�^���I�u�W�F�N�g�^���H
		bool nowAndSaveDataIsArr() const { return m_hasNowInfo && m_nowInfo.isArr() && m_info.isArr(); }//���݂̃f�[�^���Z�[�u�f�[�^���z��^���H
		bool nowAndSaveDataIsPtr() const { return m_hasNowInfo && m_nowInfo.isPtr() && m_info.isPtr(); }//���݂̃f�[�^���Z�[�u�f�[�^���|�C���^�^���H
		bool nowAndSaveDataIsNul() const { return m_hasNowInfo && m_nowInfo.isNul() && m_info.isNul(); }//���݂̃f�[�^���Z�[�u�f�[�^���̓k�����H
		bool nowIsObjButSaveDataIsNot() const { return m_hasNowInfo && m_nowInfo.isObj() && !m_info.isObj(); }//���݂̃f�[�^�̓I�u�W�F�N�g�^�����Z�[�u�f�[�^�͂����ł͂Ȃ����H
		bool nowIsArrButSaveDataIsNot() const { return m_hasNowInfo && m_nowInfo.isArr() && !m_info.isArr(); }//���݂̃f�[�^�͔z��^�����Z�[�u�f�[�^�͂����ł͂Ȃ����H
		bool nowIsPtrButSaveDataIsNot() const { return m_hasNowInfo && m_nowInfo.isPtr() && !m_info.isPtr(); }//���݂̃f�[�^�̓|�C���^�^�����Z�[�u�f�[�^�͂����ł͂Ȃ����H
		bool nowIsNulButSaveDataIsNot() const { return m_hasNowInfo && m_nowInfo.isNul() && !m_info.isNul(); }//���݂̃f�[�^�̓k�������Z�[�u�f�[�^�͂����ł͂Ȃ����H
		bool nowIsNotObjButSaveDataIs() const { return m_hasNowInfo && !m_nowInfo.isObj() && m_info.isObj(); }//���݂̃f�[�^�̓I�u�W�F�N�g�^�ł͂Ȃ����Z�[�u�f�[�^�͂������H
		bool nowIsNotArrButSaveDataIs() const { return m_hasNowInfo && !m_nowInfo.isArr() && m_info.isArr(); }//���݂̃f�[�^�͔z��^�ł͂Ȃ����Z�[�u�f�[�^�͂������H
		bool nowIsNotPtrButSaveDataIs() const { return m_hasNowInfo && !m_nowInfo.isPtr() && m_info.isPtr(); }//���݂̃f�[�^�̓|�C���^�^�ł͂Ȃ����Z�[�u�f�[�^�͂������H
		bool nowIsNotNulButSaveDataIs() const { return m_hasNowInfo && !m_nowInfo.isNul() && m_info.isNul(); }//���݂̃f�[�^�̓k���ł͂Ȃ����Z�[�u�f�[�^�͂������H
		bool nowSizeIsSame() const { return !isObj() && m_hasNowInfo && m_nowItemSize == m_itemSize; }//���݂̃T�C�Y�̕��ƃZ�[�u�f�[�^�̃T�C�Y���������H
		bool nowSizeIsSamall() const { return !isObj() && m_hasNowInfo && m_nowItemSize < m_itemSize; }//���݂̃T�C�Y�̕����Z�[�u�f�[�^�̃T�C�Y��菬�������H
		bool nowSizeIsLarge() const { return !isObj() && m_hasNowInfo && m_nowItemSize > m_itemSize; }//���݂̃T�C�Y�̕����Z�[�u�f�[�^�̃T�C�Y���傫�����H
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
		//���͏����N���A
		void clearForInput()
		{
			//m_name = nullptr;//�f�[�^���ږ�
			*const_cast<crc32_t*>(&m_nameCrc) = 0;//�f�[�^���ږ�CRC
			//m_itemP;//�f�[�^�̎Q�ƃ|�C���^
			//m_itemType;//�f�[�^�̌^���
			*const_cast<std::size_t*>(&m_itemSize) = 0;//�f�[�^�T�C�Y
			*const_cast<std::size_t*>(&m_arrNum) = 0;//�f�[�^�̔z��T�C�Y
			const_cast<CRecInfo*>(&m_info)->clear();//�ۑ����
			m_nowItemSize = 0;//���݂̃f�[�^�T�C�Y
			m_nowArrNum = 0;//���݂̃f�[�^�̔z��T�C�Y
			m_nowInfo.clear();//���݂̕ۑ����
			m_hasNowInfo = false;//���݂̏��R�s�[�ς�
			m_isOnlyOnSaveData = false;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^
			m_isOnlyOnMem = false;//�Z�[�u�f�[�^��ɂȂ��f�[�^
			m_isAlready = false;//�����ς�
		}
		//���݂̏����R�s�[
		void copyFromOnMem(const CItemBase& src)
		{
			assert(m_nameCrc == src.m_nameCrc);
			m_name = src.m_name;//�f�[�^���ږ�
			//*const_cast<crc32_t*>(&m_nameCrc) = src.m_nameCrc;//�f�[�^���ږ�CRC
			m_itemP = src.m_itemP;//�f�[�^�̎Q�ƃ|�C���^
			m_itemType = src.m_itemType;//�f�[�^�̌^���
			m_nowItemSize = src.m_itemSize;//���݂̃f�[�^�T�C�Y
			m_nowArrNum = src.m_arrNum;//���݂̃f�[�^�̔z��T�C�Y
			m_nowInfo = src.m_info;//���݂̕ۑ����
			m_hasNowInfo = true;//���݂̏��R�s�[�ς�
			m_isOnlyOnSaveData = false;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^
			m_isOnlyOnMem = false;//�Z�[�u�f�[�^��ɂȂ��f�[�^
			src.resetIsOnlyOnMem();//�R�s�[���́u�Z�[�u�f�[�^��ɂȂ��f�[�^�v�����Z�b�g
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
			m_info(src.m_info),
			m_nowItemSize(src.m_nowItemSize),
			m_nowArrNum(src.m_nowArrNum),
			m_nowInfo(src.m_nowInfo),
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
			m_info(false, false, false, false),
			m_nowItemSize(0),
			m_nowArrNum(0),
			m_nowInfo(false, false, false, false),
			m_hasNowInfo(false),
			m_isOnlyOnSaveData(false),
			m_isOnlyOnMem(false),
			m_isAlready(false)
		{}
		//�R���X�g���N�^
		CItemBase(const char* name, const void* item_p, const std::type_info& item_type, const std::size_t item_size, const std::size_t arr_num, const bool is_object, const bool is_ptr) :
			m_name(name),
			m_nameCrc(calcCRC32(name)),
			m_itemP(item_p),
			m_itemType(&item_type),
			m_itemSize(item_size),
			m_arrNum(arr_num),
			m_info(is_object, arr_num > 0, is_ptr, item_p == nullptr),
			m_nowItemSize(0),
			m_nowArrNum(0),
			m_nowInfo(false, false, false, false),
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
		const CRecInfo m_info;//�ۑ����
		std::size_t m_nowItemSize;//�f�[�^�T�C�Y�@�����݂̃T�C�Y�i�f�V���A���C�Y�����p�j
		std::size_t m_nowArrNum;//�f�[�^�̔z��T�C�Y�@�����݂̃T�C�Y�i�f�V���A���C�Y�����p�j
		CRecInfo m_nowInfo;//�ۑ���ԁ@�����݂̏�ԁi�f�V���A���C�Y�����p�j
		bool m_hasNowInfo;//���݂̏��R�s�[�ς�
		mutable bool m_isOnlyOnSaveData;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^
		mutable bool m_isOnlyOnMem;//�Z�[�u�f�[�^��ɂȂ��f�[�^
		mutable bool m_isAlready;//�����ς�
	};
	//--------------------
	//�f�[�^���ڃe���v���[�g�N���X
	template<typename T>
	class CItem : public CItemBase
	{
	public:
		//�R���X�g���N�^
		CItem(const char* name, const T* item_p, const std::size_t arr_num, const bool is_ptr) :
			CItemBase(name, item_p, typeid(T), sizeof(T), arr_num, hasAnyFunctor<T>(), is_ptr)
		{}
		CItem(const char* name, const std::size_t size) :
			CItemBase(name, nullptr, typeid(T), size, 0, hasAnyFunctor<T>(), false)
		{}
		CItem(const char* name) :
			CItemBase(name, nullptr, typeid(T), 0, 0, hasAnyFunctor<T>(), false)
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
		CItem<typename isPtr<T>::TYPE> item_obj(name, isPtr<T>::TO_PTR(item), 0, isPtr<T>::IS_PTR);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i�z�񎩓�����p�j
	template<class T, std::size_t N>
	CItem<T> pair(const char* name, const T(&item)[N])
	{
		CItem<T> item_obj(name, item, N, false);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i�|�C���^��z�񈵂��ɂ������ꍇ�Ɏg�p�j
	template<class T>
	CItem<typename isPtr<T>::TYPE> pairArr(const char* name, const T& item, const std::size_t N)
	{
		CItem<typename isPtr<T>::TYPE> item_obj(name, isPtr<T>::TO_PTR(item), N, isPtr<T>::IS_PTR);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i�o�C�i���p�j
	//��operator&()��p
	//��operator<<() / operator>>() �ɂ͎g�p�֎~
	template<class T>
	CItem<char> pairBin(const char* name, const T& item)
	{
		const std::size_t arra_num = sizeof(T);
		const char* item_p = reinterpret_cast<const char*>(&item);
		CItem<char> item_obj(name, item_p, arra_num, false);
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
	class CIOResult
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
		std::size_t getCopiedSize() const { return m_copiedSize; }//�R�s�[�ς݃T�C�Y
	public:
		//���\�b�h
		//�R�s�[�ς݃T�C�Y�ǉ�
		std::size_t addCopiedSize(const std::size_t size)
		{
			m_copiedSize += size;
			return m_copiedSize;
		}
		//�������ʂɉ��Z
		void addResult(const CIOResult& src)
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
		CIOResult() :
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
			m_copiedSize(0)
		{}
		//�f�X�g���N�^
		~CIOResult()
		{}
	private:
		//�t�B�[���h
		bool m_hasFatalError;//�v���I�ȃG���[����
		int m_numSmallerSizeItem;//�T�C�Y���k�����ꂽ�f�[�^���ڂ̐�
		int m_numLargerSizeItem;//�T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐�
		int m_numSmallerArrItem;//�z��T�C�Y���k�����ꂽ�f�[�^���ڂ̐�
		int m_numLargerArrItem;//�z��T�C�Y���g�傳�ꂽ�f�[�^���ڂ̐�
		int m_numIsOnlyOnSaveData;//�Z�[�u�f�[�^��ɂ̂ݑ��݂���f�[�^���ڂ̐�
		int m_numIsOnlyOnMem;//�Z�[�u�f�[�^��ɂȂ��f�[�^���ڂ̐�
		int m_numIsObjOnSaveDataOnly;//���݃I�u�W�F�N�g�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
		int m_numIsObjOnMemOnly;//���݃I�u�W�F�N�g�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		int m_numIsArrOnSaveDataOnly;//���ݔz��^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
		int m_numIsArrOnMemOnly;//���ݔz��^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		int m_numIsPtrOnSaveDataOnly;//���݃|�C���^�^�ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
		int m_numIsPtrOnMemOnly;//���݃|�C���^�^�����A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		int m_numIsNulOnSaveDataOnly;//���݃k���ł͂Ȃ����A�Z�[�u�f�[�^��ł͂����������f�[�^���ڂ̐�
		int m_numIsNulOnMemOnly;//���݃k�������A�Z�[�u�f�[�^��ł͂����ł͂Ȃ������f�[�^���ڂ̐�
		std::size_t m_copiedSize;//�R�s�[�ς݃T�C�Y
	};

	//--------------------
	//�A�[�J�C�u�`�����N���X
	class CArchiveStyleBase;
	//--------------------
	//���o�̓A�[�J�C�u���N���X
	class CIOArchiveBase
	{
	public:
		//�^
		typedef unsigned char byte;//�o�b�t�@�p
		typedef std::map<crc32_t, const CItemBase> itemList_t;//�f�[�^���ڃ��X�g�^
	public:
		//�A�N�Z�b�T
		CIOResult& getResult(){ return m_result; }//���o�͏������ʂ��擾
		const CIOResult& getResult() const { return m_result; }//���o�͏������ʂ��擾
		bool hasFatalError() const { return m_result.hasFatalError(); }//�v���I�ȃG���[���肩�H
		const byte* getBuffPtr() const { return m_buff; }//�Z�[�u�f�[�^�o�b�t�@�̐擪�|�C���^���擾
		const std::size_t getBuffSize() const { return m_buffSize; }//�Z�[�u�f�[�^�o�b�t�@�̃T�C�Y���擾
		const std::size_t getBuffUsed() const { return m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̎g�p�ʂ��擾
		const std::size_t getBuffPos() const { return m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̌��݈ʒu���擾
		const std::size_t getBuffRemain() const { return m_buffSize - m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̎c�ʂ��擾
		byte* getBuffNowPtr(){ return m_buff + m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̌��݈ʒu�̃|�C���^���擾
		bool buffIsFull() const { return m_buffPos >= m_buffSize; }//�o�b�t�@�̌��݈ʒu�����[�ɓ��B�������H
	public:
		//���\�b�h
		//�������ʂ�����
		void addResult(const CIOResult& src)
		{
			m_result.addResult(src);
		}
		//�o�b�t�@�ւ̃f�[�^��������
		//���v���T�C�Y���S�ď������߂Ȃ������� false ��Ԃ�
		bool write(const void* data, const std::size_t size, std::size_t& written_size)
		{
			const std::size_t remain = getBuffRemain();
			written_size = remain > size ? size : remain;
			if (data)//�f�[�^���k���Ȃ�T�C�Y��0�Ŗ��߂�
				memcpy(m_buff + m_buffPos, data, written_size);
			else//�f�[�^�R�s�[
				memset(m_buff + m_buffPos, 0, written_size);
			m_buffPos += written_size;
			return written_size == size;
		}
		//���������ʃI�u�W�F�N�g�g�p��
		bool write(CIOResult& result, const void* data, const std::size_t size, std::size_t* written_size = nullptr)
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
		//�o�b�t�@����̃f�[�^�ǂݍ���
		//���v���T�C�Y���S�ď������߂Ȃ������� false ��Ԃ�
		bool read(void* data, const std::size_t size, std::size_t& read_size)
		{
			const std::size_t remain = getBuffRemain();
			read_size = remain > size ? size : remain;
			if (data)//data���k���Ȃ�R�s�[���Ȃ����|�C���^�͐i�߂�
				memcpy(data, m_buff + m_buffPos, read_size);
			m_buffPos += read_size;
			return read_size == size;
		}
		//���������ʃI�u�W�F�N�g�g�p��
		bool read(CIOResult& result, void* data, const std::size_t size, std::size_t* read_size = nullptr)
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
		//�T�C�Y�̈قȂ�f�[�^�ǂݍ���
		//�o�b�t�@����ǂݍ��ރf�[�^�̒����ƁA�����ۑ������i�ϐ��j�̃f�[�^�����Ⴄ�ꍇ�ɗp����
		//���v���T�C�Y���S�ď������߂Ȃ������� false ��Ԃ�
		//���y����z���g�����f�B�A����p����
		bool readResizing(void* data, const std::size_t dst_size, const std::size_t src_size, std::size_t& read_size)
		{
			const std::size_t remain = getBuffRemain();
			read_size = remain > src_size ? src_size : remain;
			if (data)//data���k���Ȃ�R�s�[���Ȃ����|�C���^�͐i�߂�
			{
				if (dst_size < read_size)
				{
					//�������ݐ�̃T�C�Y�̕����������ꍇ
					//���������ݐ�̃T�C�Y�������R�s�[����
					//���r�b�O�G���f�B�A���Ή����K�v�ȏꍇ�A���l�߂ɂ���K�v������̂Œ���
					memcpy(data, m_buff + m_buffPos, dst_size);
				}
				else if (dst_size > read_size)
				{
					//�������ݐ�̃T�C�Y�̕����傫���ꍇ
					//����U�[���N���A���ēǂݍ��݃T�C�Y�����R�s�[
					//���r�b�O�G���f�B�A���Ή����K�v�ȏꍇ�A���l�߂ɂ���K�v������̂Œ���
					memset(data, 0, sizeof(dst_size));
					memcpy(data, m_buff + m_buffPos, read_size);
				}
				else//if (dst_size == read_size)
				{
					//�T�C�Y����v����ꍇ
					//�����̂܂܃R�s�[���邾��
					memcpy(data, m_buff + m_buffPos, read_size);
				}
			}
			m_buffPos += read_size;
			return read_size == src_size;
		}
		//���������ʃI�u�W�F�N�g�g�p��
		bool readResizing(CIOResult& result, void* data, const std::size_t dst_size, const std::size_t src_size, std::size_t* read_size = nullptr)
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			//�f�[�^�ǂݍ���
			std::size_t read_size_tmp = 0;
			const bool result_now = readResizing(data, dst_size, src_size, read_size_tmp);
			//�������ʋL�^
			if (!result_now)
				result.setHasFatalError();
			if (read_size)
				*read_size += read_size_tmp;
			return result_now;
		}
		//�o�b�t�@�̃J�����g�|�C���^���ړ�
		//���͈͊O�ւ̈ړ����v�����ꂽ��[�܂ňړ����� false ��Ԃ�
		bool seek(const int seek_, int& real_seek)
		{
			const int used = static_cast<int>(m_buffPos);
			const int remain = static_cast<int>(getBuffRemain());
			real_seek = seek_ < 0 ?
				used > (-seek_) ?
					seek_ :
					-used :
				remain > seek_ ?
					seek_ :
					remain;
			m_buffPos = static_cast<std::size_t>(used + real_seek);
			return real_seek == seek_;
		}
		//���������ʃI�u�W�F�N�g�g�p��
		bool seek(CIOResult& result, const int seek_)
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
	public:
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
	public:
		//�R���X�g���N�^
		CIOArchiveBase(CArchiveStyleBase& style, void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(style),
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
		//�R���X�g���N�^
		CIOArchiveBase(CIOArchiveBase& src) :
			m_style(src.m_style),
			m_nestLevel(src.m_nestLevel + 1),
			m_buff(src.getBuffNowPtr()),
			m_buffSize(src.getBuffRemain()),
			m_buffPos(0),
			m_workBuff(const_cast<IStackAllocator::byte*>(src.m_workBuff.getNowPtrN()), src.m_workBuff.getRemain()),
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
		CArchiveStyleBase& m_style;//�A�[�J�C�u�`��
		CIOResult m_result;//���o�͏�������
		int m_nestLevel;//�f�[�^�̃l�X�g���x��
		byte* m_buff;//�Z�[�u�f�[�^�o�b�t�@
		const std::size_t m_buffSize;//�Z�[�u�f�[�^�o�b�t�@�̃T�C�Y
		std::size_t m_buffPos;//�Z�[�u�f�[�^�o�b�t�@�̏����ʒu
		CStackAllocator m_workBuff;//���[�N�o�b�t�@�p�X�^�b�N�A���P�[�^
		itemList_t* m_itemList;//�f�[�^���ڃ��X�g
	};
	//--------------------
	//�A�[�J�C�u�`�����N���X
	class CArchiveStyleBase
	{
	public:
		//���\�b�h
		//�V�O�l�`����������
		virtual bool writeSignature(CIOResult& result, CIOArchiveBase& arc) = 0;
		//�V�O�l�`���ǂݍ���
		virtual bool readSignature(CIOResult& result, CIOArchiveBase& arc) = 0;
		//�u���b�N�w�b�_�[��������
		virtual bool writeBlockHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const CVersion& ver) = 0;
		//�u���b�N�w�b�_�[�ǂݍ���
		//���ǂݍ��񂾃I�u�W�F�N�g�̌^���ƃo�[�W������Ԃ�
		virtual bool readBlockHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const CVersion& ver, CItemBase& input_item, CVersion& input_ver) = 0;
		//�u���b�N�w�b�_�[�ǂݍ��݃e�X�g
		virtual bool tryReadBlockHeader(CIOResult& result, CIOArchiveBase& arc, CItemBase& input_item, std::size_t& child_block_size) = 0;
		//�z��v�f�w�b�_�[��������
		virtual bool writeArrElemHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index) = 0;
		//�z��v�f�w�b�_�[�ǂݍ���
		virtual bool readArrElemHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index, short& items_num) = 0;
		//�f�[�^���ڏ�������
		virtual bool writeDataItem(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;
		//�f�[�^���ړǂݍ���
		virtual bool readDataItem(CIOResult& result, CIOArchiveBase& arc, CItemBase& item, const bool is_valid_item) = 0;
		//�z��v�f�t�b�^�[��������
		virtual bool writeArrElemFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index, const short items_num, const std::size_t elem_size) = 0;
		//�z��v�f�t�b�^�[�ǂݍ���
		virtual bool readArrElemFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index) = 0;
		//�u���b�N�̓ǂݍ��݂��X�L�b�v
		virtual bool readSkipBlock(CIOResult& result, CIOArchiveBase& arc) = 0;
		//�u���b�N�t�b�^�[��������
		virtual bool writeBlockFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) = 0;
		//�u���b�N�t�b�^�[�ǂݍ���
		//���ǂݍ��݃e�X�g�̌��ʃt�b�^�[�łȂ���Ύ��̃f�[�^���ڂ�ǂݍ���
		virtual bool readBlockFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, bool& is_block_end) = 0;
		//�^�[�~�l�[�^��������
		virtual bool writeTerminator(CIOResult& result, CIOArchiveBase& arc) = 0;
		//�^�[�~�l�[�^�ǂݍ���
		virtual bool readTerminator(CIOResult& result, CIOArchiveBase& arc) = 0;
	public:
		//�R���X�g���N�^
		CArchiveStyleBase()
		{}
		//�f�X�g���N�^
		~CArchiveStyleBase()
		{}
	};
	//--------------------
	//�o�̓A�[�J�C�u�N���X
	class COArchive : public CIOArchiveBase
	{
	public:
		//�I�y���[�^
		//�u&�v�I�y���[�^
		//���f�[�^���ڎw�聕�f�[�^�o�͗p����
		template<class T>
		COArchive& operator&(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return *this;

			//printf("[operator&] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//�v���I�ȃG���[���������瑦�I��
			if (m_result.hasFatalError())
				return *this;
			
			//�f�[�^���ڂ��L�^
			//���d���`�F�b�N�̂���
			addItem(item_obj);
			
			//�o��
			if (item_obj.isObj())
			{
				//�I�u�W�F�N�g�Ȃ� operator<<() �ŏo��
				*this << item_obj;
			}
			else
			{
				//�f�[�^���A�[�J�C�u�ɋL�^
				m_style.writeDataItem(m_result, *this, item_obj);

				//�f�[�^�o�͍ς�
				item_obj.setIsAlready();
			}
			
			return *this;
		}
		//�u<<�v�I�y���[�^
		//���f�[�^�o��
		template<class T>
		COArchive& operator<<(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return *this;
			
			//printf("[operator<<] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//�I�u�W�F�N�g�łȂ���΃_��
			//����������̃V���A���C�Y�p�֐��I�u�W�F�N�g�����������^���H
			assert(item_obj.isObj() == true);

			//�l�X�g���x����0�Ȃ�V�O�l�`���[����������
			if (m_nestLevel == 0)
				m_style.writeSignature(m_result, *this);
			
			//�o�[�W�����擾
			CVersionDef<T> ver_def;
			CVersion ver(ver_def);

			//�u���b�N�J�n��񏑂�����
			m_style.writeBlockHeader(m_result, *this, item_obj, ver);
			
			//�k���łȂ���Ώ�������
			if (!item_obj.isNul() && !m_result.hasFatalError())
			{
				//�u���b�N�J�n
				std::size_t block_size = 0;//�u���b�N�̃f�[�^�T�C�Y

				{
					//�u���b�N�����p�̎q�A�[�J�C�u�I�u�W�F�N�g�𐶐�
					COArchive arc_block(*this);

					//�z�񃋁[�v
					const std::size_t elem_num = item_obj.getElemNum();
					for (std::size_t index = 0; index < elem_num && !arc_block.hasFatalError(); ++index)
					{
						//�z��v�f�J�n��񏑂�����
						m_style.writeArrElemHeader(arc_block.getResult(), arc_block, item_obj, index);

						//�z��v�f�J�n
						std::size_t items_num = 0;//�f�[�^���ڐ�
						std::size_t elem_size = 0;//���̔z��v�f�̃f�[�^�T�C�Y
						{
							//�z��v�f�����p�̑��A�[�J�C�u�I�u�W�F�N�g�𐶐�
							COArchive arc_elem(arc_block);

							//�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j�Ăяo��
							{
								serialize<COArchive, T> functor;
								functor(arc_elem, item_obj.template getConst<T>(), ver, ver);
							}

							//�Z�[�u�����i�V���A���C�Y��p�����j�Ăяo��
							{
								save<COArchive, T> functor;
								functor(arc_elem, item_obj.template getConst<T>(), ver);
							}

							//�z��v�f�I��
							items_num = arc_elem.m_itemList->size();//�f�[�^���ڐ��擾
							elem_size = arc_elem.m_buffPos;//�f�[�^�T�C�Y�擾
							arc_block.addResult(arc_elem.getResult());//�������ʂ��v��
						}

						//�z��v�f�I����񏑂�����
						//���Ⴆ�΁A�o�C�i���X�^�C���ł́A�z��v�f�̃w�b�_���Ƀf�[�^���ڐ��ƃf�[�^�T�C�Y���������݁A
						//�@�z��v�f�̍Ō�܂ŃV�[�N����
						m_style.writeArrElemFooter(arc_block.getResult(), arc_block, item_obj, index, items_num, elem_size);
					}

					//�f�[�^���W�����i�V���A���C�Y��p�����j�Ăяo��
					{
						collector<COArchive, T> functor;
						functor(arc_block, item_obj.template getConst<T>(), ver);
					}

					//�u���b�N�I��
					block_size = arc_block.m_buffPos;//�u���b�N�T�C�Y�擾
					m_result.addResult(arc_block.getResult());//�������ʂ��v��
				}

				//�u���b�N�I����񏑂�����
				//���Ⴆ�΁A�o�C�i���X�^�C���ł́A�u���b�N�̃w�b�_���Ƀf�[�^�T�C�Y���������݁A
				//�@�u���b�N�̍Ō�܂ŃV�[�N����
				m_style.writeBlockFooter(m_result, *this, item_obj, block_size);
			}

			//�l�X�g���x����0�Ȃ�^�[�~�l�[�^����������
			if (m_nestLevel == 0)
				m_style.writeTerminator(m_result, *this);
			
			//�f�[�^�o�͍ς�
			item_obj.setIsAlready();

			return *this;
		}
	public:
		//�R���X�g���N�^
		COArchive(CArchiveStyleBase& style, void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		COArchive(CArchiveStyleBase& style, BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		COArchive(CArchiveStyleBase& style, void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		COArchive(COArchive& src) :
			CIOArchiveBase(src)
		{}
		//�f�X�g���N�^
		~COArchive()
		{}
	};
	//--------------------
	//���̓A�[�J�C�u�N���X
	class CIArchive : public CIOArchiveBase
	{
	public:
		//�A�N�Z�b�T
		bool isMakeListMode() const { return m_isMakeListMode; }//�������X�g���L�^���邾���̃��[�h���H
		void setIsMakeListMode(){ m_isMakeListMode = true; }//�������X�g���L�^���邾���̃��[�h���Z�b�g
		void resetIsMakeListMode(){ m_isMakeListMode = false; }//�������X�g���L�^���邾���̃��[�h������
		CItemBase* getTargetObjItem(){ return m_targetObjItem; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ��Z�b�g
		const CItemBase* getTargetObjItem() const { return m_targetObjItem; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ��Z�b�g
		void setTargetObjItem(CItemBase& item){ m_targetObjItem = &item; m_isUsedTargetObjItem = false; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ��Z�b�g
		void resetTargetObjItem(){ m_targetObjItem = nullptr; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ����Z�b�g
		bool isUsedTargetObjItem() const { return m_isUsedTargetObjItem; }//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ��g�p�������H
	public:
		//�I�y���[�^
		//�u&�v�I�y���[�^
		//���f�[�^���ڎw��p����
		template<class T>
		CIArchive& operator&(const CItem<T> item_obj)
		{
			if (m_result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return *this;

			//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ��Z�b�g����Ă���ꍇ�͓��ʏ���
			if (m_targetObjItem)
			{
				if (*m_targetObjItem == item_obj)
				{
					*this >> item_obj;//�I�u�W�F�N�g�ǂݍ���
					m_isUsedTargetObjItem = true;//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ��g�p����
				}
				return *this;
			}

			//printf("[operator&] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul(), item_obj.isOnlyOnMem(), item_obj.isOnlyOnSaveData());

			//��U�Z�[�u�f�[�^�ɑ��݂��Ȃ��f�[�^���ڂƂ��������ɂ��Ă���
			item_obj.setIsOnlyOnMem();
			
			//�f�[�^���ڂ��L�^
			//���S�Ă̋L�^���I�������A�f�[�^��ǂݍ��݂Ȃ���f�[�^���ڂɏ�������ł���
			addItem(item_obj);
			
			return *this;
		}
		
		//�u>>�v�I�y���[�^
		//���f�[�^����
		template<class T>
		CIArchive& operator>>(CItem<T> item_obj_now)
		{
			if (m_result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return *this;
			
			//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ��Z�b�g����Ă���ꍇ�͓��ʏ���
			if (m_targetObjItem)
			{
				if (*m_targetObjItem != item_obj_now)//�Ώۃf�[�^���ڈȊO�͏������Ȃ�
					return *this;
			}

			//�������X�g���L�^���邾���̃��[�h�Ȃ�u���v�I�y���[�^�ɏ������񂵂ďI��
			if (m_isMakeListMode)
			{
				return operator&(item_obj_now);
			}

			//printf("[operator>>] name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d, isOnlyOnMem=%d, isOnlyOnSaveData=%d\n",
			//	item_obj_now.m_name, item_obj_now.m_nameCrc, item_obj_now.m_itemType->name(), item_obj_now.m_itemP, item_obj_now.m_itemSize, item_obj_now.m_arrNum, item_obj_now.isObj(), item_obj_now.isArr(), item_obj_now.isPtr(), item_obj_now.isNul(), item_obj_now.isOnlyOnMem(), item_obj_now.isOnlyOnSaveData());
			
			//�p�����[�^�`�F�b�N
			//assert(!item_obj_now.isOnlyOnSaveData());
			//���Z�[�u�f�[�^�ɂ������݂��Ȃ��f�[�^�͏����s��
			//���z�M�������ԈႦ�Ĉȓ�����A���̂悤�ȏ�Ԃɂ͂Ȃ�Ȃ��͂�

			//�l�X�g���x����0�Ȃ�V�O�l�`���[��ǂݍ���
			if (m_nestLevel == 0)
			{
				m_style.readSignature(m_result, *this);
			}
			
			//�o�[�W�����擾
			CVersionDef<T> now_ver_def;
			CVersion now_ver(now_ver_def);//���݂̃o�[�W����
			CVersion ver;//�ǂݍ��ݗp�̃o�[�W����
			//�u���b�N�J�n���ǂݍ���
			CItem<T> item_obj(item_obj_now);
			m_style.readBlockHeader(m_result, *this, item_obj_now, now_ver, item_obj, ver);
			//printf("  readDataItem:name=\"%s\"(0x%08x), typeName=%s, item=0x%p, size=%d, arrNum=%d, isObj=%d, isArr=%d, isPtr=%d, isNul=%d\n", item_obj.m_name, item_obj.m_nameCrc, item_obj.m_itemType->name(), item_obj.m_itemP, item_obj.m_itemSize, item_obj.m_arrNum, item_obj.isObj(), item_obj.isArr(), item_obj.isPtr(), item_obj.isNul());

			if (!item_obj.isNul() && !m_result.hasFatalError())//�y�Z�[�u�f�[�^��́z�v�f���k���łȂ���Ώ�������
			{
				//�u���b�N�J�n
				{
					//�V�����A�[�J�C�u�I�u�W�F�N�g�𐶐�
					CIArchive arc_block(*this);
					
					//�z��̐擪�|�C���^�i���̃|�C���^�j���L��
					const void* item_p_top = item_obj.m_itemP;

					//�z�񃋁[�v
					const std::size_t elem_num = item_obj.getElemNum();
					std::size_t elem_num_loaded = 0;
					for (std::size_t index = 0; index < elem_num && !arc_block.buffIsFull() && !arc_block.hasFatalError(); ++index)//�y�Z�[�u�f�[�^��́z�z��v�f�����f�[�^�o��
					{
						const T* debug_p = reinterpret_cast<const T*>(item_obj.m_itemP);
						const bool is_valid_element = (!item_obj.nowIsNul() && index < item_obj.getMinimumElemNum());//�L���Ȕz��v�f���H�i�L���łȂ���Ώ��������ǂݍ��ނ����j
						if (is_valid_element)
							++elem_num_loaded;

						//�z��v�f�J�n���ǂݍ���
						short items_num = 0;
						m_style.readArrElemHeader(arc_block.getResult(), arc_block, item_obj, index, items_num);

						//�z��v�f�J�n
						{
							//�V�����A�[�J�C�u�I�u�W�F�N�g�𐶐�
							CIArchive arc_elem(arc_block);

							//���[�h�O�����i�f�V���A���C�Y��p�����j�Ăяo��
							if (is_valid_element)
							{
								beforeLoad<CIArchive, T> functor;
								functor(arc_elem, item_obj.template get<T>(), ver, now_ver);
							}

							//�������X�g���L�^���邾���̃��[�h�ɃZ�b�g
							arc_elem.setIsMakeListMode();

							//�f�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j�Ăяo��
							//���f�[�^���ڃ��X�g���L�^���邾��
							if (is_valid_element)
							{
								serialize<CIArchive, T> functor;
								functor(arc_elem, item_obj.template getConst<T>(), ver, now_ver);
							}

							//���[�h�����i�f�V���A���C�Y��p�����j�Ăяo��
							//���f�[�^���ڃ��X�g���L�^���邾��
							if (is_valid_element)
							{
								load<CIArchive, T> functor;
								functor(arc_elem, item_obj.template get<T>(), ver, now_ver);
							}
							
							//�������X�g���L�^���邾���̃��[�h������
							arc_elem.resetIsMakeListMode();

							//���ۂ̃��[�h����
							for (short item_idx = 0; item_idx < items_num && !arc_elem.buffIsFull(); ++item_idx)
							{
								CItemBase child_item;
								m_style.readDataItem(arc_elem.getResult(), arc_elem, child_item, is_valid_element);
								
								//�I�u�W�F�N�g�̏ꍇ�̏���
								if (child_item.isObj())
								{
									//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ��Z�b�g
									arc_elem.setTargetObjItem(child_item);

									//�f�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j�Ăяo��
									//���ΏۃI�u�W�F�N�g�A�C�e������������
									//if (!arc_elem.isUsedTargetObjItem())
									{
										serialize<CIArchive, T> functor;
										functor(arc_elem, item_obj.template getConst<T>(), ver, now_ver);
									}

									//���[�h�����i�f�V���A���C�Y��p�����j�Ăяo��
									//���ΏۃI�u�W�F�N�g�A�C�e������������
									if (!arc_elem.isUsedTargetObjItem())
									{
										load<CIArchive, T> functor;
										functor(arc_elem, item_obj.template get<T>(), ver, now_ver);
									}
									
									//�I�u�W�F�N�g�����Ώۃf�[�^���ڂ����Z�b�g
									arc_elem.resetTargetObjItem();

									//�������̂܂܂�������u���b�N���X�L�b�v����
									if (!arc_elem.isUsedTargetObjItem())
									{
										//�I�u�W�F�N�g�̃u���b�N���X�L�b�v
										m_style.readSkipBlock(arc_elem.getResult(), arc_elem);
										
										//�����ς݂ɂ���
										child_item.setIsAlready();
									}
								}
								
								//���[�h�������ۑ���̎w�肪�Ȃ���������
								if (child_item.isOnlyOnSaveData())
								{
									//�ʒm
									noticeUnconsciousItem<CIArchive, T> functor;
									functor(arc_elem, item_obj.template get<T>(), ver, now_ver, child_item);
								}
							}

							//��������Ȃ������f�[�^���ڂ̏���
							for (auto& pair : *arc_elem.m_itemList)
							{
								const CItemBase& child_item = pair.second;
								//�ۑ���̎w�肪���邪�A�Z�[�u�f�[�^�ɂȂ����[�h�ł��Ȃ���������
								if (child_item.isOnlyOnMem())
								{
									//�������ʌv��
									arc_elem.getResult().addResult(child_item);
									
									//�ʒm
									noticeUnloadedItem<CIArchive, T> functor;
									functor(arc_elem, item_obj.template get<T>(), ver, now_ver, child_item);
								}
							}

							//���[�h�㏈���i�f�V���A���C�Y��p�����j�Ăяo��
							if (is_valid_element)
							{
								afterLoad<CIArchive, T> functor;
								functor(arc_elem, item_obj.template get<T>(), ver, now_ver);
							}

							//�z��v�f�I��
							arc_block.addResult(arc_elem.getResult());

							//�v�f��ǂݍ��񂾕��A�o�b�t�@�̃J�����g�|�C���^��i�߂�
							arc_block.seek(arc_block.getResult(), arc_elem.getBuffPos());
						}

						//�z��v�f�I�����ǂݍ���
						m_style.readArrElemFooter(arc_block.getResult(), arc_block, item_obj, index);

						//�z��̎��̗v�f��
						if (item_obj.m_itemP)
						{
							*const_cast<void**>(&item_obj.m_itemP) = reinterpret_cast<T*>(const_cast<void*>(item_obj.m_itemP)) + 1;
						}
					}
					
					//�z��̐擪�|�C���^�i���̃|�C���^�j�ɖ߂�
					item_obj.m_itemP = item_p_top;

					//�f�[�^���z�����i�f�V���A���C�Y��p�����j�Ăяo��
					//���[�h����
					while (!arc_block.buffIsFull() && !arc_block.getResult().hasFatalError())
					{
						//�u���b�N�I������
						bool is_block_end;
						m_style.readBlockFooter(arc_block.getResult(), arc_block, item_obj, is_block_end);
						if (is_block_end)
							break;//�u���b�N�̏I�������o�����烋�[�v���甲����
						
						const std::size_t prev_pos = arc_block.m_buffPos;//�������s�O�̈ʒu���L��
						CItemBase child_item;
						std::size_t child_block_size = 0;
						m_style.tryReadBlockHeader(m_result, arc_block, child_item, child_block_size);//�u���b�N�J�n�������ǂ݂��A���z�����ɉ�
						//���z�����i�f�V���A���C�Y��p�����j�Ăяo��
						{
							distributor<CIArchive, T> functor;
							functor(arc_block, item_obj.template get<T>(), elem_num, elem_num_loaded, ver, now_ver, child_item);
						}
						//���z�������s���ʃ`�F�b�N
						if (arc_block.m_buffPos == prev_pos)//�ǂݍ��݂��i��ł��邩�H
						{
							//�ǂݍ��݂��i��ł��Ȃ�������u���b�N�T�C�Y���A�o�b�t�@�̃J�����g�|�C���^��i�߂Ė����v�シ��
							arc_block.seek(arc_block.getResult(), child_block_size);
							arc_block.getResult().addResult(child_item);//�����v��i�Z�[�u�f�[�^�ɂ����Ȃ����W�J�悪�Ȃ��f�[�^�������j
						}
					}

					//�u���b�N�I��
					m_result.addResult(arc_block.getResult());
					
					//�v�f��ǂݍ��񂾕��A�o�b�t�@�̃J�����g�|�C���^��i�߂�
					seek(m_result, arc_block.getBuffPos());
				}
			}
			
			//�l�X�g���x����0�Ȃ�^�[�~�l�[�^��ǂݍ���
			if (m_nestLevel == 0)
			{
				m_style.readTerminator(m_result, *this);
			}
			
			return *this;
		}
	public:
		//�R���X�g���N�^
		CIArchive(CArchiveStyleBase& style, const void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(style, const_cast<void*>(buff), buff_size, work_buff, work_buff_size),
			m_isMakeListMode(false),
			m_targetObjItem(nullptr),
			m_isUsedTargetObjItem(false)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(CArchiveStyleBase& style, const BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, const_cast<BUFF_T*>(&buff[0]), BUFF_SIZE, work_buff, WORK_SIZE),
			m_isMakeListMode(false),
			m_targetObjItem(nullptr),
			m_isUsedTargetObjItem(false)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(CArchiveStyleBase& style, const void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, const_cast<void*>(buff), buff_size, work_buff, WORK_SIZE),
			m_isMakeListMode(false),
			m_targetObjItem(nullptr),
			m_isUsedTargetObjItem(false)
		{}
		CIArchive(CIArchive& src) :
			CIOArchiveBase(src),
			m_isMakeListMode(false),
			m_targetObjItem(nullptr),
			m_isUsedTargetObjItem(false)
		{}
		//�f�X�g���N�^
		~CIArchive()
		{}
	private:
		//�t�B�[���h
		bool m_isMakeListMode;//�������X�g���L�^���邾���̃��[�h���H
		CItemBase* m_targetObjItem;//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ����Z�b�g
		bool m_isUsedTargetObjItem;//�I�u�W�F�N�g�����̑Ώۃf�[�^���ڂ��g�p�������H

	};
	//--------------------
	//�o�C�i���`���A�[�J�C�u�N���X
	class CBinaryArchive : public CArchiveStyleBase
	{
	public:
		//�萔
		static const std::size_t SIGNATURE_SIZE = 16;//�V�O�l�`���T�C�Y
		static const unsigned char SIGNATURE[SIGNATURE_SIZE];//�V�O�l�`��
		static const std::size_t TERMINATOR_SIZE = 16;//�^�[�~�l�[�^�T�C�Y
		static const unsigned char TERMINATOR[TERMINATOR_SIZE];//�^�[�~�l�[�^
		static const std::size_t BLOCK_TERM_SIZE = 2;//�u���b�N�I�[�T�C�Y
		static const unsigned char BLOCK_TERM[BLOCK_TERM_SIZE];//�u���b�N�I�[
		static const std::size_t ELEM_TERM_SIZE = 2;//�v�f�I�[�T�C�Y
		static const unsigned char ELEM_TERM[ELEM_TERM_SIZE];//�v�f�I�[
	public:
		//���\�b�h
		//�V�O�l�`���o��
		bool writeSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, SIGNATURE, SIGNATURE_SIZE);//�V�O�l�`���o��
			return !result.hasFatalError();
		}
		//�V�O�l�`�����́i�������f�[�^���`�F�b�N�j
		bool readSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char signature[SIGNATURE_SIZE];
			arc.read(result, signature, SIGNATURE_SIZE);//�V�O�l�`������
			if (memcmp(signature, SIGNATURE, SIGNATURE_SIZE) != 0)//�V�O�l�`���`�F�b�N
				result.setHasFatalError();
			return !result.hasFatalError();
		}
		//�u���b�N�J�n���o��
		bool writeBlockHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const CVersion& ver) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, &item.m_nameCrc, sizeof(item.m_nameCrc));//���OCRC�o��
			item.m_info.setHasVersion();//�o�[�W������񂠂�ɂ���
			arc.write(result, &item.m_info.m_value, sizeof(item.m_info.m_value));//�ۑ���ԏo��
			arc.write(result, ver.getVerPtr(), ver.getVerSize());//�o�[�W�����o��
			if (!item.isNul())//�k�����͂����܂ł̏��ŏI���
			{
				if (item.isArr())//�z�񎞂͔z��v�f�����o��
					arc.write(result, &item.m_arrNum, sizeof(item.m_arrNum));//�z��v�f���o��
				arc.write(result, &item.m_itemSize, sizeof(item.m_itemSize));//�u���b�N�T�C�Y���o�́@���u���b�N�I�����ɏ���������
			}
			return !result.hasFatalError();
		}
		//�u���b�N�J�n������
		bool readBlockHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const CVersion& ver, CItemBase& input_item, CVersion& input_ver) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			input_item.clearForInput();//���͏�����U�N���A
			arc.read(result, const_cast<crc32_t*>(&input_item.m_nameCrc), sizeof(input_item.m_nameCrc));//���OCRC�o��
			arc.read(result, const_cast<CRecInfo::value_t*>(&input_item.m_info.m_value), sizeof(input_item.m_info.m_value));//�ۑ���ԏo��
			if (input_item.m_info.hasVersion())//�o�[�W������񂪂��邩�H
			{
				arc.read(result, const_cast<unsigned int*>(input_ver.getVerPtr()), input_ver.getVerSize());//�o�[�W��������
				input_ver.calcFromVer();
			}
			if (!input_item.isNul())//�k�����͂����܂ł̏��ŏI���
			{
				if (input_item.isArr())//�z�񎞂͔z��v�f��������
					arc.read(result, const_cast<std::size_t*>(&input_item.m_arrNum), sizeof(input_item.m_arrNum));//�z��v�f������
				arc.read(result, const_cast<std::size_t*>(&input_item.m_itemSize), sizeof(input_item.m_itemSize));//�u���b�N�T�C�Y����
			}
			//���OCRC���`�F�b�N���ď��𓝍�
			//������Ă�����v���I�G���[�i�Z�[�u�f�[�^���K�����Ă��Ȃ��j
			if (item == input_item)
			{
				input_item.copyFromOnMem(item);//�Z�[�u�f�[�^�̏��Ɍ��݂̏����R�s�[�i�����j
			}
			else
			{
				item.setIsOnlyOnMem();//�Z�[�u�f�[�^�ɑ��݂��Ȃ��f�[�^����
				input_item.setIsOnlyOnSaveData();//�Z�[�u�f�[�^�ɂ������݂��Ȃ��f�[�^����
				result.setHasFatalError();//�v���I�G���[�ݒ�
				result.addResult(item);//�G���[���v��
			}
			input_item.setIsAlready();//�����ς݂ɂ���
			result.addResult(input_item);//���ʂ��v��
			return !result.hasFatalError();
		}
		//�u���b�N�J�n��񉼓ǂݍ���
		bool tryReadBlockHeader(CIOResult& result, CIOArchiveBase& arc, CItemBase& input_item, std::size_t& child_block_size) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			std::size_t read_size = 0;//�ǂݍ��݃T�C�Y
			input_item.clearForInput();//���͏�����U�N���A
			arc.read(result, const_cast<crc32_t*>(&input_item.m_nameCrc), sizeof(input_item.m_nameCrc), &read_size);//���OCRC�o��
			arc.read(result, const_cast<CRecInfo::value_t*>(&input_item.m_info.m_value), sizeof(input_item.m_info.m_value), &read_size);//�ۑ���ԏo��
			if (input_item.m_info.hasVersion())//�o�[�W������񂪂��邩�H
			{
				CVersion input_ver_dummy;
				arc.read(result, const_cast<unsigned int*>(input_ver_dummy.getVerPtr()), input_ver_dummy.getVerSize(), &read_size);//�o�[�W��������
			}
			if (!input_item.isNul())//�k�����͂����܂ł̏��ŏI���
			{
				if (input_item.isArr())//�z�񎞂͔z��v�f��������
					arc.read(result, const_cast<std::size_t*>(&input_item.m_arrNum), sizeof(input_item.m_arrNum), &read_size);//�z��v�f������
				arc.read(result, const_cast<std::size_t*>(&input_item.m_itemSize), sizeof(input_item.m_itemSize), &read_size);//�u���b�N�T�C�Y����
			}
			child_block_size = read_size + input_item.m_itemSize;
			arc.seek(result, -static_cast<int>(read_size));//���ǂ݂������A�o�b�t�@�̃J�����g�|�C���^��߂�
			return !result.hasFatalError();
		}
		//�u���b�N�̔z��v�f�J�n���o��
		bool writeArrElemHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			short items_num = 0;
			arc.write(result, &items_num, sizeof(items_num));//�f�[�^���ڐ����o�́@���z��v�f�I�����ɏ���������
			arc.write(result, &item.m_itemSize, sizeof(item.m_itemSize));//�z��v�f�T�C�Y���o�́@���z��v�f�I�����ɏ���������
			return !result.hasFatalError();
		}
		//�u���b�N�̔z��v�f�J�n������
		bool readArrElemHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index, short& items_num) override
		{
			items_num = 0;
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			std::size_t elem_size = 0;
			arc.read(result, &items_num, sizeof(items_num));//�f�[�^���ڐ�����
			arc.read(result, &elem_size, sizeof(elem_size));//�z��v�f�T�C�Y����
			return !result.hasFatalError();
		}
		//�f�[�^���ڏo��
		bool writeDataItem(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, &item.m_nameCrc, sizeof(item.m_nameCrc));//���OCRC�o��
			item.m_info.resetHasVersion();//�o�[�W�������Ȃ��ɂ���
			arc.write(result, &item.m_info.m_value, sizeof(item.m_info.m_value));//�ۑ���ԏo��
			if (!item.isNul())//�k�����͂����܂ł̏��ŏI���
			{
				arc.write(result, &item.m_itemSize, sizeof(item.m_itemSize));//�f�[�^�T�C�Y�o��
				if (item.isArr())//�z�񂩁H
					arc.write(result, &item.m_arrNum, sizeof(item.m_arrNum));//�z��v�f���o��
				unsigned char* p = reinterpret_cast<unsigned char*>(const_cast<void*>(item.m_itemP));
				const std::size_t elem_num = item.getElemNum();
				for (std::size_t index = 0; index < elem_num && !result.hasFatalError(); ++index)//�z��v�f�����f�[�^�o��
				{
					arc.write(result, p, item.m_itemSize);//�f�[�^�o��
					p += item.m_itemSize;
				}
			}
			return !result.hasFatalError();
		}
		//�f�[�^���ړ���
		bool readDataItem(CIOResult& result, CIOArchiveBase& arc, CItemBase& item, const bool is_valid_item) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			std::size_t item_size = 0;
			arc.read(result, const_cast<crc32_t*>(&item.m_nameCrc), sizeof(item.m_nameCrc), &item_size);//���OCRC����
			arc.read(result, const_cast<CRecInfo::value_t*>(&item.m_info.m_value), sizeof(item.m_info.m_value), &item_size);//�ۑ���ԓ���
			const CItemBase* org_item = arc.findItem(item.m_nameCrc);//�Ή�����f�[�^���ڏ�������
			if (org_item)//�Ή�����f�[�^���ڂ������������H
				item.copyFromOnMem(*org_item);//���݂̏����Z�[�u�f�[�^�̏��ɃR�s�[�i�����j
			else
				item.setIsOnlyOnSaveData();//�Ή�����f�[�^���Ȃ��F�Z�[�u�f�[�^�ɂ����f�[�^�����݂��Ȃ�
			if (item.isObj())
			{
				//�Ώۂ��I�u�W�F�N�g�i�u���b�N�j�Ȃ�A���̎��_�ŏ������I�����A�o�b�t�@�̃J�����g�|�C���^�𕔘^�̐擪�ɖ߂�
				arc.seek(result, -static_cast<int>(item_size));
				item_size = 0;
				return !result.hasFatalError();
			}
			assert(!item.m_info.hasVersion());//�o�[�W�������Ȃ����H
			//�Ή�����f�[�^���ڂ�����
			if (!item.isNul())//�y�Z�[�u�f�[�^��́z�f�[�^���k���łȂ���Ώ�������
			{
				arc.read(result, const_cast<std::size_t*>(&item.m_itemSize), sizeof(item.m_itemSize), &item_size);//�f�[�^�T�C�Y����
				if (item.isArr())//�z�񂩁H
					arc.read(result, const_cast<std::size_t*>(&item.m_arrNum), sizeof(item.m_arrNum), &item_size);//�z��v�f������
				unsigned char* p = reinterpret_cast<unsigned char*>(const_cast<void*>(item.m_itemP));
				const std::size_t elem_num = item.getElemNum();
				for (std::size_t index = 0; index < elem_num && !result.hasFatalError(); ++index)//�y�Z�[�u�f�[�^��́z�z��v�f�����f�[�^�o��
				{
					const bool is_valid_elment =//�L���ȃf�[�^���H
						is_valid_item && //�e�̃f�[�^���L�����H
						!item.isOnlyOnSaveData() && //�Z�[�u�f�[�^�ɂ����Ȃ��f�[�^�ł͂Ȃ����H
						!item.nowIsNul() && //���݂́i�R�s�[��́j�f�[�^���k���ł͂Ȃ����H
						index < item.getMinimumElemNum();//���݂́i�R�s�[��́j�z��͈͓̔����H
					void* p_tmp = is_valid_elment ? p : nullptr;//�L���ȃf�[�^�łȂ����nullptr��n���A��ǂݍ��݂���
					arc.readResizing(result, p_tmp, item.m_nowItemSize, item.m_itemSize, &item_size);//�f�[�^����
					if (p)
						p += item.m_nowItemSize;
				}
			}
			item.setIsAlready();//�����ς݂ɂ���
			result.addResult(item);//���ʂ��v��
			return true;
		}
		//�u���b�N�̔z��v�f�I�����o��
		bool writeArrElemFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index, const short items_num, const std::size_t elem_size) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.seek(result, -static_cast<int>(sizeof(elem_size)));//�z��v�f�T�C�Y���̕��A�o�b�t�@�̃J�����g�|�C���^��߂�
			arc.seek(result, -static_cast<int>(sizeof(items_num)));//�f�[�^���ڐ����̕��A�o�b�t�@�̃J�����g�|�C���^��߂�
			arc.write(result, &items_num, sizeof(items_num));//�z��v�f�T�C�Y���X�V�i�o�́j
			arc.write(result, &elem_size, sizeof(elem_size));//�z��v�f�T�C�Y���X�V�i�o�́j
			arc.seek(result, static_cast<int>(elem_size));//�z��v�f�T�C�Y���i�v�f�̏I���܂Łj�A�o�b�t�@�̃J�����g�|�C���^��i�߂�
			arc.write(result, ELEM_TERM, ELEM_TERM_SIZE);//�v�f�I�[�o��
			return !result.hasFatalError();
		}
		//�u���b�N�̔z��v�f�I��������
		bool readArrElemFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char elem_term[ELEM_TERM_SIZE];
			arc.read(result, elem_term, ELEM_TERM_SIZE);//�v�f�I�[����
			if (memcmp(elem_term, ELEM_TERM, ELEM_TERM_SIZE) != 0)//�v�f�I�[�`�F�b�N
				result.setHasFatalError();
			return !result.hasFatalError();
		}
		//�I�u�W�F�N�g�̃u���b�N���X�L�b�v
		bool readSkipBlock(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			crc32_t name_crc = 0;
			CRecInfo rec_info(false, false, false, false);
			arc.read(result, &name_crc, sizeof(name_crc));//���OCRC�o��
			arc.read(result, const_cast<CRecInfo::value_t*>(&rec_info.m_value), sizeof(rec_info.m_value));//�ۑ���ԏo��
			if (rec_info.hasVersion())//�o�[�W������񂪂��邩�H
			{
				CVersion input_ver_dummy;
				arc.read(result, const_cast<unsigned int*>(input_ver_dummy.getVerPtr()), input_ver_dummy.getVerSize());//�o�[�W��������
			}
			if (!rec_info.isNul())//�k�����͂����܂ł̏��ŏI���
			{
				if (rec_info.isArr())//�z�񎞂͔z��v�f��������
				{
					std::size_t arr_num;
					arc.read(result, &arr_num, sizeof(arr_num));//�z��v�f������
				}
				std::size_t item_size;
				arc.read(result, &item_size, sizeof(item_size));//�u���b�N�T�C�Y����
				arc.seek(result, static_cast<int>(item_size));//�u���b�N�T�C�Y���A�o�b�t�@�̃J�����g�|�C���^��i�߂�
			}
			return !result.hasFatalError();
		}
		//�u���b�N�I�����o��
		bool writeBlockFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			int real_seek = 0;
			arc.seek(result, -static_cast<int>(sizeof(block_size)));//�u���b�N�T�C�Y���̕��A�o�b�t�@�̃J�����g�|�C���^��߂�
			arc.write(result, &block_size, sizeof(block_size));//�u���b�N�T�C�Y���X�V�i�o�́j
			arc.seek(result, static_cast<int>(block_size));//�u���b�N�T�C�Y���i�u���b�N�̏I���܂Łj�A�o�b�t�@�̃J�����g�|�C���^��i�߂�
			arc.write(result, BLOCK_TERM, BLOCK_TERM_SIZE);//�u���b�N�I�[�o��
			return !result.hasFatalError();
		}
		//�u���b�N�I��������
		//���u���b�N�I�����ǂ������𔻒肵�ĕԂ�
		bool readBlockFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, bool& is_block_end) override
		{
			is_block_end = true;//�u���b�N�I������
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char block_term[BLOCK_TERM_SIZE];
			std::size_t read_size = 0;
			arc.read(result, block_term, BLOCK_TERM_SIZE, &read_size);//�u���b�N�I�[����
			if (memcmp(block_term, BLOCK_TERM, BLOCK_TERM_SIZE) != 0)//�u���b�N�I�[�`�F�b�N
			{
				is_block_end = false;//�u���b�N�I���ł͂Ȃ�
				arc.seek(result, -static_cast<int>(read_size));//�u���b�N�̏I�[�ł͂Ȃ��������߁A�o�b�t�@�̃J�����g�|�C���^��߂�
			}
			return !result.hasFatalError();
		}
		//�^�[�~�l�[�^�o��
		bool writeTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			arc.write(result, TERMINATOR, TERMINATOR_SIZE);//�^�[�~�l�[�^�o��
			return !result.hasFatalError();
		}
		//�^�[�~�l�[�^���́i�������f�[�^���`�F�b�N�j
		bool readTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			char terminator[TERMINATOR_SIZE];
			arc.read(result, terminator, TERMINATOR_SIZE);//�^�[�~�l�[�^����
			if (memcmp(terminator, TERMINATOR, TERMINATOR_SIZE) != 0)//�^�[�~�l�[�^�`�F�b�N
				result.setHasFatalError();
			return true;
		}
	public:
		//�R���X�g���N�^
		CBinaryArchive():
			CArchiveStyleBase()
		{}
		//�f�X�g���N�^
		~CBinaryArchive()
		{}
	};
	//�ÓI�ϐ��C���X�^���X��
	const unsigned char CBinaryArchive::SIGNATURE[CBinaryArchive::SIGNATURE_SIZE] = { 0x00, 0xff, 's', 'e', 'r', 'i', 'a', 'l', ':', ':', 'C', 'B', 'i', 'n', 0xff, 0x00 };//�V�O�l�`��
	const unsigned char CBinaryArchive::TERMINATOR[CBinaryArchive::TERMINATOR_SIZE] = { 0xff, 0x00, 's', 'e', 'r', 'i', 'a', 'l', ':', ':', 'C', 'B', 'i', 'n', 0x00, 0xff };//�^�[�~�l�[�^
	const unsigned char CBinaryArchive::BLOCK_TERM[CBinaryArchive::BLOCK_TERM_SIZE] = { 0xfb, 0xff };//�u���b�N�I�[
	const unsigned char CBinaryArchive::ELEM_TERM[CBinaryArchive::ELEM_TERM_SIZE] = { 0xfe, 0xff };//�v�f�I�[
	//--------------------
	//�e�L�X�g�`���A�[�J�C�u�N���X
	class CTextArchive : public CArchiveStyleBase
	{
	public:
		//�萔
		static const char* SIGNATURE;//�V�O�l�`��
		static const char* TERMINATOR;//�^�[�~�l�[�^
	public:
		//���\�b�h
		//�V�O�l�`���o��
		bool writeSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�V�O�l�`�����́i�������f�[�^���`�F�b�N�j
		bool readSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�J�n���o��
		bool writeBlockHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const CVersion& ver) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�J�n������
		bool readBlockHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const CVersion& ver, CItemBase& input_item, CVersion& input_ver) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�̔z��v�f�J�n���o��
		bool writeArrElemHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�̔z��v�f�J�n������
		bool readArrElemHeader(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index, short& items_num) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�J�n��񉼓ǂݍ���
		bool tryReadBlockHeader(CIOResult& result, CIOArchiveBase& arc, CItemBase& input_item, std::size_t& child_block_size) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�f�[�^���ڏo��
		bool writeDataItem(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�f�[�^���ړ���
		bool readDataItem(CIOResult& result, CIOArchiveBase& arc, CItemBase& item, const bool is_valid_item) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�̔z��v�f�I�����o��
		bool writeArrElemFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index, const short items_num, const std::size_t elem_size) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�̔z��v�f�I��������
		bool readArrElemFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t index) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�I�u�W�F�N�g�̃u���b�N���X�L�b�v
		bool readSkipBlock(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�I�����o��
		bool writeBlockFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�u���b�N�I��������
		bool readBlockFooter(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, bool& is_block_end) override
		{
			is_block_end = true;
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�^�[�~�l�[�^�o��
		bool writeTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
		//�^�[�~�l�[�^���́i�������f�[�^���`�F�b�N�j
		bool readTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			if (result.hasFatalError())//�v���I�ȃG���[���o�Ă��鎞�͑����I������
				return false;
			return !result.hasFatalError();
		}
	public:
		//�R���X�g���N�^
		CTextArchive():
			CArchiveStyleBase()
		{}
		//�f�X�g���N�^
		~CTextArchive()
		{}
	};
	//�ÓI�ϐ��C���X�^���X��
	const char* CTextArchive::SIGNATURE = "\"serial::CTextArchive\": {";//�V�O�l�`��
	const char* CTextArchive::TERMINATOR = "}";//�^�[�~�l�[�^
	//--------------------
	//�o�C�i���o�̓A�[�J�C�u�N���X
	class COBinaryArchive : public COArchive
	{
	public:
		//�R���X�g���N�^
		COBinaryArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(),
			COArchive(m_style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		COBinaryArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			COArchive(m_style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		COBinaryArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			COArchive(m_style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		//�f�X�g���N�^
		~COBinaryArchive()
		{}
	private:
		//�t�B�[���h
		CBinaryArchive m_style;
	};
	//--------------------
	//�o�C�i�����̓A�[�J�C�u�N���X
	class CIBinaryArchive : public CIArchive
	{
	public:
		//�R���X�g���N�^
		CIBinaryArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(),
			CIArchive(m_style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CIBinaryArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			CIArchive(m_style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CIBinaryArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			CIArchive(m_style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		//�f�X�g���N�^
		~CIBinaryArchive()
		{}
	private:
		//�t�B�[���h
		CBinaryArchive m_style;
	};
	//--------------------
	//�e�L�X�g�o�̓A�[�J�C�u�N���X
	class COTextArchive : public COArchive
	{
	public:
		//�R���X�g���N�^
		COTextArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(),
			COArchive(m_style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		COTextArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			COArchive(m_style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		COTextArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			COArchive(m_style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		//�f�X�g���N�^
		~COTextArchive()
		{}
	private:
		//�t�B�[���h
		CTextArchive m_style;
	};
	//--------------------
	//�e�L�X�g���̓A�[�J�C�u�N���X
	class CITextArchive : public CIArchive
	{
	public:
		//�R���X�g���N�^
		CITextArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_style(),
			CIArchive(m_style, buff, buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CITextArchive(BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			CIArchive(m_style, buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CITextArchive(void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			m_style(),
			CIArchive(m_style, buff, buff_size, work_buff, WORK_SIZE)
		{}
		//�f�X�g���N�^
		~CITextArchive()
		{}
	private:
		//�t�B�[���h
		CTextArchive m_style;
	};
}
//--------------------
//�f�[�^�N���X�p�̃o�[�W������`�}�N��
#define SERIALIZE_VERSION_DEF(T, MAJOR, MINOR) \
	namespace serial \
	{ \
		template<> \
		struct CVersionDef<T> : public CVersionDefBase<MAJOR, MINOR>{}; \
	}
//--------------------
//�f�[�^�N���X�̃t�����h�錾�p�}�N��
#define FRIEND_SERIALIZE(T) \
	template<class Arc, class T> \
	friend struct serial::beforeLoad; \
	template<class Arc, class T> \
	friend struct serial::serialize; \
	template<class Arc, class T> \
	friend struct serial::save; \
	template<class Arc, class T> \
	friend struct serial::load; \
	template<class Arc, class T> \
	friend struct serial::noticeUnconsciousItem; \
	template<class Arc, class T> \
	friend struct serial::noticeUnloadedItem; \
	template<class Arc, class T> \
	friend struct serial::afterLoad; \
	template<class Arc, class T> \
	friend struct serial::collector; \
	template<class Arc, class T> \
	friend struct serial::distributor;

//--------------------------------------------------------------------------------
//�V���A���C�Y�e�X�g

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
	STRUCT* getData7b(){ return m_data7b; }//�f�[�^7�擾
	const STRUCT* getData7b() const { return m_data7b; }//�f�[�^7�擾
public:
	//�R���X�g���N�^
	CTest1() :
		m_data1(0),
		m_data2(0.f),
		m_data4a(),
		m_data4b(),
		m_data7a(),
		m_data7b(nullptr)
	{
		m_data3[0] = 0;
		m_data3[1] = 0;
		m_data3[2] = 0;
		m_data5a.reset();
		m_data5b.reset();
		//m_data7a = new STRUCT();
		//m_data7b = new STRUCT();
	}
	//�f�X�g���N�^
	~CTest1()
	{
		if (m_data7a)
			delete m_data7a;
		if (m_data7b)
			delete m_data7b;
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
			printf("serialize<CTest1>(ver=%d,%d) sizeof(CTest1)=%d\n", ver.getMajor(), ver.getMinor(), sizeof(CTest1));
			//arc & pair("data0", obj.m_data0);
			arc & pair("data1", obj.m_data1);
			arc & pair("data2", obj.m_data2);
			arc & pair("data3", obj.m_data3);
			arc & pairBin("data4a", obj.m_data4a);
			arc & pair("data4b", obj.m_data4b);
			arc & pairBin("data5a", obj.m_data5a);
			arc & pair("data5b", obj.m_data5b);
			arc & pair("data6", obj.m_data6);
			arc & pair("data7a", obj.m_data7a);
			arc & pair("data7b", obj.m_data7b);
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
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver, const CVersion& now_ver)
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
void serializeTest1(const char* file_path)
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
	serial::COBinaryArchive arc(save_buff, work_buff);//�o�̓A�[�J�C�u�쐬�F�e�L�X�g�A�[�J�C�u
	arc << serial::pair<CSaveDataSerializer>("SaveData");//�V���A���C�Y
	printf("�������ʁF%s\n", arc.hasFatalError() ? "�v���I�ȃG���[����" : "�G���[�Ȃ�");
	//�t�@�C���ɏ����o��
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(save_buff, 1, arc.getBuffPos(), fp);
	fclose(fp);
	fp = NULL;
}
//--------------------
//�f�V���A���C�Y�e�X�g�P�F�o�C�i���A�[�J�C�u
void deserializeTest1(const char* file_path)
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
	serial::CIOResult& result = arc.getResult();
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
	static const char* file_path = "test1.bin";
	//�V���A���C�Y
	s_saveData = new CTest1();
	serializeTest1(file_path);
	delete s_saveData;
	s_saveData = nullptr;

	char* dummy = new char[10 * 1024];
	
	//�f�V���A���C�Y
	s_saveData = new CTest1();
	deserializeTest1(file_path);
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
	BASIC_DATA m_basic;//��{�f�[�^
	short m_recover;//�񕜗�
	short m_num;//�f�[�^��
	//�f�t�H���g�R���X�g���N�^
	ITEM_DATA()
	{}
	//�R���X�g���N�^�i�e�X�g�p�ɋ����j
	ITEM_DATA(const char* id, const char* name, const int atk, const int def, const int recover, const int num) :
		m_id(id),
		m_name(name),
		m_basic(atk, def),
		m_recover(recover),
		m_num(num)
	{}
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
	void setWeapon(const crc32_t weapon_id);//������Z�b�g
	void setWeapon(const char* weapon_id){ setWeapon(calcCRC32(weapon_id)); }//������Z�b�g
	void setShield(const crc32_t shield_id);//�����Z�b�g
	void setShield(const char* shield_id){ setShield(calcCRC32(shield_id)); }//�����Z�b�g
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
		return;
	m_weaponId = weapon_id;
	m_weapon = item;
}
//�����Z�b�g
void CHARA_DATA::setShield(const crc32_t shield_id)
{
	CSingleton<CInventory> inventory;
	ITEM_DATA* item = inventory->find(shield_id);
	if (!item)
		return;
	m_shieldId = shield_id;
	m_shield = item;
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
void makeTestData()
{
	printf("------------------------------------------------------------\n");
	printf("�y�e�X�g�f�[�^�쐬�z\n");

	//�C���x���g���f�[�^�o�^
	{
		CSingleton<CInventory> inventory;
		for (int i = 0; i < 5; ++i)
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
			inventory->regist(item);
		}
		for (int i = 0; i < 5; ++i)
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
			inventory->regist(item);
		}
		for (int i = 0; i < 3; ++i)
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
			inventory->regist(item);
		}
		inventory->sort();
	}
	//�A�r���e�B�f�[�^�o�^
	{
		CSingleton<CAbilityList> ability_list;
		for (int i = 0; i < 20; ++i)
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
		CHARA_DATA chara1("c00010", "���Y", 10, 15, 20, "w00020", "s00020", 111, 222, 333, 444);
		CHARA_DATA chara2("c00020", "���Y", 20, 25, 40, "w00050", "s00010", 999, 888, 777, 666);
		CHARA_DATA chara3("c00030", "�O�Y", 30, 55, 3, "w00010", "s00030", 123,456, 987, 654);
		chara1.addAbility("a00030");
		chara1.addAbility("a00020");
		chara1.addAbility("a00010");
		chara3.addAbility("a00050");
		chara_list->regist(chara1);
		chara_list->regist(chara2);
		chara_list->regist(chara3);
		chara_list->sort();
	}
	//�i�s�f�[�^�X�V
	{
		CSingleton<CPhaseAndFlags> phase_and_flags;
		phase_and_flags->setPhase(7);
		phase_and_flags->setFlag(0, true);
		phase_and_flags->setFlag(2, true);
		phase_and_flags->setFlag(4, true);
		phase_and_flags->setFlag(5, true);
		phase_and_flags->setFlag(63, true);
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
			printf("ID=\"%s\"(0x%08x), nmae=\"%s\", atk=%d, def=%d, recover=%d, num=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_basic.m_atk, ite->m_basic.m_def, ite->m_recover, ite->m_num);
		}
	}
	//�A�r���e�B�f�[�^�\��
	printf("--- �A�r���e�B ---\n");
	{
		CSingleton<CAbilityList> ability_list;
		for (auto& ite : *ability_list)
		{
			printf("ID=\"%s\"(0x%08x), nmae=\"%s\", atk=%d, def=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_basic.m_atk, ite->m_basic.m_def);
		}
	}
	//�L�����f�[�^�\��
	printf("--- �L���� ---\n");
	{
		CSingleton<CCharaList> chara_list;
		for (auto& ite : *chara_list)
		{
			printf("ID=\"%s\"(0x%08x), nmae=\"%s\", level=%d, atk=%d, def=%d\n",
				ite->m_id.c_str(), ite->m_id.getCRC(), ite->m_name.c_str(), ite->m_level, ite->m_basic.m_atk, ite->m_basic.m_def);
			printf("    param1={%d, %d}, param2={%d, %d}\n",
				ite->m_param1[0], ite->m_param1[1], ite->m_param2[0], ite->m_param2[1]);
			if (ite->m_weapon)
				printf("  weapon=%s\n", ite->m_weapon->m_name.c_str());
			if (ite->m_shield)
				printf("  shield=%s\n", ite->m_shield->m_name.c_str());
			for (int i = 0;; ++i)
			{
				const ABILITY_DATA* ability = ite->getAbility(i);
				if (!ability)
					break;
				printf("    [%s]\n", ability->m_name.c_str());
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
//�Z�[�u�f�[�^�p�_�~�[�N���X
class CSaveData{};
SERIALIZE_VERSION_DEF(CSaveData, 1, 0);//�o�[�W����

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
			arc & pair("str", obj.m_str);
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
			arc & pair("basic", obj.m_basic);
			arc & pair("recover", obj.m_recover);
			arc & pair("num", obj.m_num);
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
			arc & pair("basic", obj.m_basic);
			arc & pair("weapon", obj.m_weaponId);
			arc & pair("shield", obj.m_shieldId);
		}
	};
	//--------------------
	//�V���A���C�Y��p�����FCHARA_DATA
	template<class Arc>
	struct save<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver)
		{
			arc & pair("param1", obj.m_param1);//�Z�[�u�f�[�^�ɂ����Ȃ��f�[�^�̃V�~�����[�V�����p
		}
	};
	//--------------------
	//�f�V���A���C�Y��p�����FCHARA_DATA
	template<class Arc>
	struct load<Arc, CHARA_DATA> {
		void operator()(Arc& arc, const CHARA_DATA& obj, const CVersion& ver, CVersion& now_ver)
		{
			arc & pair("param2", obj.m_param2);//�Z�[�u�f�[�^���Ȃ��f�[�^�̃V�~�����[�V�����p
		}
	};
	//--------------------
	//�Z�[�u�f�[�^�ɂ͂��������A�ۑ���̎w�肪�Ȃ��A���[�h�ł��Ȃ��������ڂ̒ʒm
	template<class Arc>
	struct noticeUnconsciousItem<Arc, CHARA_DATA> {
		void operator()(Arc& arc, CHARA_DATA& obj, CVersion& ver, const CVersion& now_ver, const CItemBase& unloaded_item)
		{
			if (unloaded_item == "param1")
			{
				obj.m_param1[0] = 12345;
				obj.m_param1[1] = 67890;
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
	//���W�����FCSaveData
	template<class Arc>
	struct collector<Arc, CSaveData> {
		void operator()(Arc& arc, const CSaveData& obj, const CVersion& ver)
		{
			//�C���x���g���̃f�[�^�����W
			CSingleton<CInventory> inventory;
			for (auto item_data : *inventory)
			{
				arc << pair("item", *item_data);
			}
			//�A�r���e�B�̃f�[�^�����W
			CSingleton<CAbilityList> ability_list;
			for (auto ability_data : *ability_list)
			{
				arc << pair("ability", *ability_data);
			}
			//�L�����̃f�[�^�����W
			CSingleton<CCharaList> chara_list;
			for (auto chara_data : *chara_list)
			{
				arc << pair("chara", *chara_data);
			}
			//�i�s���t���O�f�[�^���V���A���C�Y
			CSingleton<CPhaseAndFlags> phase_and_flags;
			arc << pair("phase_and_flags", *phase_and_flags);
		}
	};
	//--------------------
	//���[�h�O�����FCSaveData
	template<class Arc>
	struct beforeLoad<Arc, CSaveData> {
		void operator()(Arc& arc, CSaveData& obj, const CVersion& ver, const CVersion& now_ver)
		{
			if (true)
			{
				//�C���x���g���f�[�^�N���A
				CSingleton<CInventory> inventory;
				inventory.destroy();
			}
			if (true)
			{
				//�A�r���e�B�f�[�^�N���A
				CSingleton<CAbilityList> ability_list;
				ability_list.destroy();
			}
			if (true)
			{
				//�L�����f�[�^�N���A
				CSingleton<CCharaList> chara_list;
				chara_list.destroy();
			}
			if (true)
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
			if (target_item == "item")
			{
				//�C���x���g���f�[�^����
				CSingleton<CInventory> inventory;
				ITEM_DATA item_data;
				arc >> pair("item", item_data);//�f�V���A���C�Y
				inventory->regist(item_data);
			}
			else if (target_item == "ability")
			{
				//�A�r���e�B�f�[�^����
				CSingleton<CAbilityList> ability_list;
				ABILITY_DATA ability_data;
				arc >> pair("ability", ability_data);
				ability_list->regist(ability_data);
			}
			else if (target_item == "chara")
			{
				//�L�����f�[�^����
				CSingleton<CCharaList> chara_list;
				CHARA_DATA chara_data;
				arc >> pair("chara", chara_data);
				chara_list->regist(chara_data);
			}
			else if (target_item == "phase_and_flags")
			{
				//�t�F�[�Y���i�s�f�[�^����
				CSingleton<CPhaseAndFlags> phase_and_flags;
				arc >> pair("phase_and_flags", *phase_and_flags);
			}
		}
	};
}

//--------------------
//�V���A���C�Y
std::size_t serialize(void* save_data_buff, const std::size_t save_data_buff_size)
{
	printf("------------------------------------------------------------\n");
	printf("�y�V���A���C�Y�z\n");
	
	//���[�N�o�b�t�@����
	const std::size_t WORK_BUFF_SIZE = 1 * 1024 * 1024;
	void* work_buff = new char[WORK_BUFF_SIZE];

	//�V���A���C�Y�p�A�[�J�C�u�I�u�W�F�N�g����
	serial::COBinaryArchive arc(save_data_buff, save_data_buff_size, work_buff, WORK_BUFF_SIZE);

	//�V���A���C�Y
	arc << serial::pair<CSaveData>("SaveData");

	//�V���A���C�Y�̌��ʂ�\��
	serial::CIOResult result = arc.getResult();
	printf("�V���A���C�Y���ʁF\n");
	printf("  �v���I�ȃG���[ ... %s\n", result.hasFatalError() ? "����" : "�Ȃ�");

	//�Z�[�u�f�[�^�̃T�C�Y��Ԃ�
	return arc.getBuffUsed();
}

//--------------------
//�f�V���A���C�Y
void deserialize(void* save_data, const std::size_t save_data_size)
{
	printf("------------------------------------------------------------\n");
	printf("�y�f�V���A���C�Y�z\n");
	
	//���[�N�o�b�t�@����
	const std::size_t WORK_BUFF_SIZE = 1 * 1024 * 1024;
	void* work_buff = new char[WORK_BUFF_SIZE];

	//�V���A���C�Y�p�A�[�J�C�u�I�u�W�F�N�g����
	serial::CIBinaryArchive arc(save_data, save_data_size, work_buff, WORK_BUFF_SIZE);

	//�f�V���A���C�Y
	arc >> serial::pair<CSaveData>("SaveData");

	//�f�V���A���C�Y�̌��ʂ�\��
	serial::CIOResult result = arc.getResult();
	printf("�f�V���A���C�Y���ʁF\n");
	printf("  �v���I�ȃG���[ ... %s\n", result.hasFatalError() ? "����" : "�Ȃ�");
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
void serializeAndSave(const char* file_path)
{
	//�Z�[�u�f�[�^�p�o�b�t�@����
	const std::size_t SAVE_DATA_BUFF_SIZE = 1 * 1024 * 1024;
	void* save_data_buff = new char[SAVE_DATA_BUFF_SIZE];

	//�V���A���C�Y
	const std::size_t save_data_size = serialize(save_data_buff, SAVE_DATA_BUFF_SIZE);

	//�Z�[�u
	save(file_path, save_data_buff, save_data_size);
}

//--------------------
//���[�h���f�V���A���C�Y
void loadAndDeserialize(const char* file_path)
{
	//�Z�[�u�f�[�^�p�o�b�t�@����
	const std::size_t SAVE_DATA_BUFF_SIZE = 1 * 1024 * 1024;
	void* save_data_buff = new char[SAVE_DATA_BUFF_SIZE];

	//���[�h
	const std::size_t save_data_size = load(file_path, save_data_buff, SAVE_DATA_BUFF_SIZE);

	//�f�V���A���C�Y
	deserialize(save_data_buff, save_data_size);
}

//--------------------------------------------------------------------------------
//�e�X�g���s

//--------------------
//�V���A���C�Y
void test2serialize()
{
	//�e�X�g�f�[�^�쐬
	makeTestData();
	//���݂̃f�[�^��\��
	printDataAll();
	const char* save_file_name = "save_data.bin";
	//�V���A���C�Y���Z�[�u
	serializeAndSave(save_file_name);
	//�S�f�[�^���Z�b�g
	resetAll();
	//���݂̃f�[�^��\��
	printDataAll();
	//���[�h���f�V���A���C�Y
	loadAndDeserialize(save_file_name);
	//���݂̃f�[�^��\��
	printDataAll();
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
	//test1();
	test2();
	return EXIT_SUCCESS;
}

// End of file
