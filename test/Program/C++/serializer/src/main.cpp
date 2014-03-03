#define TLS_IS_WINDOWS//�yMS�ŗL�d�l�zTLS�̐錾��Windows�X�^�C���ɂ��鎞�͂��̃}�N����L���ɂ���
#define USE_STRCPY_S//�yMS�ŗL�d�l�zstrcpy_s���g�p���鎞�ɂ��̃}�N����L���ɂ���
#define USE_ALIGNED_MALLOC//�yMS�ŗL�d�l�z_aligned_malloc���g�p���鎞�͂��̃}�N����L���ɂ���
#define USE_FRIEND_WITH_NEW_OPERATOR//�yMS�ŗL�d�l�H�zoperator new()���N���X���Ńt�����h�����鎞�͂��̃}�N����L���ɂ���
#define USE_WINDOWS_DEBUG_BREAK//�yMS�ŗL�d�l�zWindow��DebugBreak���g�p

//#define ENABLE_CONSTEXPR//�yC++11�p�zconstexpr��L���ɂ��鎞�͂��̃}�N����L���ɂ���
//#define ENABLE_USER_DEFINED_LITERALS//�yC++11�p�z���[�U�[��`���e������L���ɂ��鎞�͂��̃}�N����L���ɂ���

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>//assert�p
#include <cstddef>//std::size_t�p
#include <stdint.h>//uintptr_t�p
#include <limits.h>//UCHAR_MAX�p
#include <typeinfo.h>//type_id�p
#include <map>//STL map�p
#include <vector>//STL vector�p
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

#if 0
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
	//�o�[�W�����N���X
	template<unsigned short MAJOR, unsigned short MINOR>
	class CVersionDefBase;
	class CVersion
	{
	public:
		//�萔
		static const unsigned int VER_FIGURE = 1000000;//�����o�[�W�����v�Z�p���グ��
	public:
		//�A�N�Z�b�T
		unsigned int getMajor() const { return m_majorVer; };//���W���[�o�[�W����
		unsigned int getMinor() const { return m_minorVer; };//�}�C�i�[�o�[�W����
		unsigned int getVer()const { return m_majorVer * VER_FIGURE + m_minorVer; };//�����o�[�W����
	public:
		//�f�t�H���g�R���X�g���N�^
		CVersion() :
			m_majorVer(0),
			m_minorVer(0)
		{}
		//�R���X�g���N�^
		CVersion(const unsigned short major, const unsigned short minor) :
			m_majorVer(major),
			m_minorVer(minor)
		{}
		template<unsigned short MAJOR, unsigned short MINOR>
		CVersion(CVersionDefBase<MAJOR, MINOR>&) :
			CVersion(MAJOR, MINOR)
		{}
	private:
		//�t�B�[���h
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
	//�f�[�^���ڊ��N���X
	class CItemBase
	{
	public:
		//�L���X�g�I�y���[�^
		operator crc32_t() const { return m_nameCrc; }
		operator const char*() const { return m_name; }
		operator const std::type_info& () const { return m_itemType; }
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
	public:
		//�R���X�g���N�^
		CItemBase(const char* name, const void* item_p, const std::type_info& item_type, const std::size_t item_size, const std::size_t arr_num = 0) :
			m_nameCrc(calcCRC32(name)),
			m_name(name),
			m_itemP(item_p),
			m_itemType(item_type),
			m_itemSize(item_size),
			m_arrNum(arr_num)
		{}
		//�f�X�g���N�^
		~CItemBase()
		{}
	public://�t�B�[���h�����J���Ē��ڑ���
		//�t�B�[���h
		const crc32_t m_nameCrc;//�f�[�^���ږ�CRC
		const char* m_name;//�f�[�^���ږ�
		const void* m_itemP;//�f�[�^�̎Q�ƃ|�C���^
		const std::type_info& m_itemType;//�f�[�^�̌^���
		const std::size_t m_itemSize;//�f�[�^�T�C�Y
		const std::size_t m_arrNum;//�f�[�^�̔z��T�C�Y
	};
	//--------------------
	//�f�[�^���ڃe���v���[�g�N���X
	template<typename T>
	class CItem : public CItemBase
	{
	public:
		//�R���X�g���N�^
		CItem(const char* name, const T& item, const std::size_t arr_num) :
			CItemBase(name, &item, typeid(T), sizeof(T), arr_num)
		{}
		CItem(const char* name, const std::size_t size) :
			CItemBase(name, nullptr, typeid(T), size, 0)
		{}
		//�f�X�g���N�^
		~CItem()
		{}
	};
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐�
	template<class T>
	CItem<T> pair(const char* name, const T& item)
	{
		CItem<T> item_obj(name, item, 0);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i�z��p�j
	template<class T, std::size_t N>
	CItem<T> pair(const char* name, const T(&item)[N])
	{
		CItem<T> item_obj(name, item[0], N);
		return item_obj;
	}
	//--------------------
	//�f�[�^���ڏ��쐬�e���v���[�g�֐��i�o�C�i���p�j
	template<class T>
	CItem<char> pairBin(const char* name, const T& item)
	{
		const std::size_t size = sizeof(T);
		const char* item_p = reinterpret_cast<const char*>(&item);
		CItem<char> item_obj(name, *item_p, size);
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
	//�A�C�e�����o�͌��ʃN���X
	class CIOResult
	{
	public:
		//�^
		struct Output{};//�o�͎��w��p�\����
		struct Input{};//���͎��w��p�\����
	public:
		//�R���X�g���N�^
		CIOResult() :
			m_isInput(false),
			m_hasFatalError(false),
			m_hasSrc(false),
			m_hasDst(false),
			m_srcSize(0),
			m_dstSize(0),
			m_copiedSize(0)
		{}
		//�o�͎��p�R���X�g���N�^
		CIOResult(const Output&, const CItemBase& item) :
			m_isInput(false),
			m_hasFatalError(false),
			m_hasSrc(true),
			m_hasDst(false),
			m_srcSize(item.m_itemSize),
			m_dstSize(0),
			m_copiedSize(0)
		{}
		//���͎��p�R���X�g���N�^
		CIOResult(const Input&, const CItemBase& item) :
			m_isInput(true),
			m_hasFatalError(false),
			m_hasSrc(false),
			m_hasDst(true),
			m_srcSize(0),
			m_dstSize(item.m_itemSize),
			m_copiedSize(0)
		{}
		//�f�X�g���N�^
		~CIOResult()
		{}
	public://�t�B�[���h�����J���Ē��ڑ���
		//�t�B�[���h
		bool m_isInput;//���͏������H
		bool m_hasFatalError;//�v���I�ȃG���[����
		bool m_hasSrc;//�R�s�[������
		bool m_hasDst;//�R�s�[�悠��
		std::size_t m_srcSize;//�R�s�[���T�C�Y
		std::size_t m_dstSize;//�R�s�[��T�C�Y
		std::size_t m_copiedSize;//�R�s�[�ς݃T�C�Y
	};
	
	//--------------------
	//���[�h�O�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct beforeLoad {
		typedef beforeLoad<Arc, T> IS_UNDEFINED;//SFINAE:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`�i���g�Ɠ����^���`�j
		void operator()(Arc& arc, T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//�V���A���C�Y�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���V���A���C�Y�ƃf�V���A���C�Y���p���ʏ���
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct serialize {
		typedef serialize<Arc, T> IS_UNDEFINED;//SFINAE:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`�i���g�Ɠ����^���`�j
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//�Z�[�u�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct save	{
		typedef save<Arc, T> IS_UNDEFINED;//SFINAE:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`�i���g�Ɠ����^���`�j
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
		typedef load<Arc, T> IS_UNDEFINED;//SFINAE:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`�i���g�Ɠ����^���`�j
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//���[�h�㏈���p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct afterLoad {
		typedef afterLoad<Arc, T> IS_UNDEFINED;//SFINAE:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`�i���g�Ɠ����^���`�j
		void operator()(Arc& arc, T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//�f�[�^���W�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct gatherer	{
		typedef gatherer<Arc, T> IS_UNDEFINED;//SFINAE:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`�i���g�Ɠ����^���`�j
		void operator()(Arc& arc, const T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//�f�[�^���z�����p�֐��I�u�W�F�N�g�e���v���[�g�N���X
	//���f�V���A���C�Y��p����
	//�����ꉻ�ɂ�胆�[�U�[����������
	//���W���ł͉������Ȃ�
	template<class Arc, class T>
	struct distributor {
		typedef distributor<Arc, T> IS_UNDEFINED;//SFINAE:�֐��I�u�W�F�N�g�̖���`�`�F�b�N�p�̌^��`�i���g�Ɠ����^���`�j
		void operator()(Arc& arc, T& obj, const CVersion& ver)
		{}
	};
	//--------------------
	//�֐��I�u�W�F�N�g��`�ς݃`�F�b�N�֐�
	//��SFINAE�ɂ��AIS_UNDEFINED ����`����Ă���^�̃I�[�o�[���[�h�֐����I�΂ꂽ�疢��`�Ƃ݂Ȃ�
	template<class F>
	bool isDefinedFunctor(const typename  F::IS_UNDEFINED& o)
	{
		return false;//����`
	}
	template<class F>
	bool isDefinedFunctor(const F& o)
	{
		return true;//��`�ς�
	}
	
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
		typedef std::vector<CItemBase> itemList_t;//�f�[�^���ڃ��X�g�^
		typedef std::map<crc32_t, const CItemBase*> itemSearch_t;//�f�[�^�������X�g�^
	public:
		//�A�N�Z�b�T
		const byte* getBuffPtr() const { return m_buff; }//�Z�[�u�f�[�^�o�b�t�@
		const std::size_t getBuffSize() const { return m_buffSize; }//�Z�[�u�f�[�^�o�b�t�@�̃T�C�Y
		const std::size_t getBuffPos() const { return m_buffPos; }//�Z�[�u�f�[�^�o�b�t�@�̏����ʒu
	public:
		//���\�b�h
		//���X�g�Ƀf�[�^���ڒǉ�
		void addItem(const CItemBase& item)
		{
			//���[�N�̈��ݒ�i�O���[�o�����ԃA���P�[�^�j
			//���֐��𔲂���Ǝ����I�Ɍ��ɖ߂�
			CTempPolyStackAllocator alloc(m_workBuff);

			//�f�[�^���ڂ�ǉ�
			assert(m_itemSearch->find(item) == m_itemSearch->end());
			m_itemList->push_back(item);
			const CItemBase& rec = m_itemList->at(m_itemList->size() - 1);
			m_itemSearch->emplace(item.m_nameCrc, &rec);
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

			//�f�[�^�������X�g�𐶐�
			m_itemSearch = new itemSearch_t;
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
			//�f�[�^�������X�g��j��
			if (m_itemSearch)
			{
				delete m_itemSearch;
				m_itemSearch = nullptr;
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
			m_itemList(nullptr),
			m_itemSearch(nullptr)
		{
			//�f�[�^���X�g�쐬
			createItemList();
		}
		//�R���X�g���N�^
		CIOArchiveBase(CIOArchiveBase& src, const std::size_t buff_size) :
			m_style(src.m_style),
			m_nestLevel(src.m_nestLevel + 1),
			m_buff(src.m_buff + src.m_buffPos),
			m_buffSize(buff_size),
			m_buffPos(0),
			m_workBuff(const_cast<IStackAllocator::byte*>(src.m_workBuff.getNowPtrN()), src.m_workBuff.getRemain()),
			m_itemList(nullptr),
			m_itemSearch(nullptr)
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
		int m_nestLevel;//�f�[�^�̃l�X�g���x��
		byte* m_buff;//�Z�[�u�f�[�^�o�b�t�@
		const std::size_t m_buffSize;//�Z�[�u�f�[�^�o�b�t�@�̃T�C�Y
		std::size_t m_buffPos;//�Z�[�u�f�[�^�o�b�t�@�̏����ʒu
		CStackAllocator m_workBuff;//���[�N�o�b�t�@�p�X�^�b�N�A���P�[�^
		itemList_t* m_itemList;//�f�[�^���ڃ��X�g
		itemSearch_t* m_itemSearch;//�f�[�^�������X�g
	};
	//--------------------
	//�A�[�J�C�u�`�����N���X
	class CArchiveStyleBase
	{
	public:
		//���\�b�h
		virtual bool outputSignature(CIOResult& result, CIOArchiveBase& arc) = 0;//�V�O�l�`���o��
		virtual bool inputSignature(CIOResult& result, CIOArchiveBase& arc) = 0;//�V�O�l�`�����́i�������f�[�^���`�F�b�N�j
		virtual bool outputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;//�u���b�N�J�n���o��
		virtual bool inputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;//�u���b�N�J�n������
		virtual bool outputVersion(CIOResult& result, CIOArchiveBase& arc, const CVersion& ver) = 0;//�o�[�W�����o��
		virtual bool inputVersion(CIOResult& result, CIOArchiveBase& arc, CVersion& ver) = 0;//�o�[�W��������
		virtual bool output(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;//�o��
		virtual bool input(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) = 0;//����
		virtual bool outputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) = 0;//�u���b�N�I�����o��
		virtual bool inputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) = 0;//�u���b�N�I��������
		virtual bool outputTerminator(CIOResult& result, CIOArchiveBase& arc) = 0;//�^�[�~�l�[�^�o��
		virtual bool inputTerminator(CIOResult& result, CIOArchiveBase& arc) = 0;//�^�[�~�l�[�^���́i�������f�[�^���`�F�b�N�j
	public:
		//�R���X�g���N�^
		CArchiveStyleBase()
		{}
		//�f�X�g���N�^
		~CArchiveStyleBase()
		{}
	};
	//--------------------
	//���o�̓A�[�J�C�u�_�~�[�N���X�i�Ȃɂ����Ȃ��j
	class CIOArchiveDummy
	{
	public:
		//�I�y���[�^
		//�u&�v�I�y���[�^
		//���f�[�^���ڎw�聕�f�[�^�o�͗p����
		template<class T>
		CIOArchiveDummy& operator&(const CItem<T> item_obj)
		{
			return *this;
		}
		//�u<<�v�I�y���[�^
		//���f�[�^�o��
		template<class T>
		CIOArchiveDummy& operator<<(const CItem<T> item_obj)
		{
			return *this;
		}
		//�u>>�v�I�y���[�^
		//���f�[�^����
		template<class T>
		CIOArchiveDummy& operator>>(CItem<T> item_obj)
		{
			return *this;
		}
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
			//printf("[operator&] name=%s, typeName=%s, item=0x%p [%d]\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP, item_obj.m_arrNum);
			
			//�f�[�^���ڂ��L�^
			addItem(item_obj);
			
			//��p�V���A���C�Y���������邩�`�F�b�N
			bool is_obj = false;

			//�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j���݊m�F
			if (!is_obj)
			{
				serialize<CIOArchiveDummy, T> functor;
				is_obj = isDefinedFunctor(functor);
			}
			
			//�Z�[�u�����i�V���A���C�Y��p�����j���݊m�F
			if (!is_obj)
			{
				save<CIOArchiveDummy, T> functor;
				is_obj = isDefinedFunctor(functor);
			}
			
			//�o��
			if (is_obj)
			{
				//�I�u�W�F�N�g�Ȃ̂� operator<<() �ŏo��
				*this << item_obj;
			}
			else
			{
				//�f�[�^���A�[�J�C�u�ɋL�^
				CIOResult result(CIOResult::Output(), item_obj);
				m_style.output(result, *this, item_obj);
			}
			
			return *this;
		}
		//�u<<�v�I�y���[�^
		//���f�[�^�o��
		template<class T>
		COArchive& operator<<(const CItem<T> item_obj)
		{
			//printf("[operator<<] name=%s, typeName=%s, item=0x%p\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP);
			
			//�l�X�g���x����0�Ȃ�V�O�l�`���[����������
			if (m_nestLevel == 0)
			{
				CIOResult result;
				m_style.outputSignature(result, *this);
			}
			
			//�u���b�N�J�n��񏑂�����
			{
				CIOResult result;
				m_style.outputBeginBlock(result, *this, item_obj);
			}
			
			//�u���b�N�J�n
			std::size_t block_size = 0;
			{
				//�V�����A�[�J�C�u�I�u�W�F�N�g�𐶐�
				COArchive new_arc(*this, m_buffSize - m_buffPos);
				
				//�o�[�W�����擾
				CVersionDef<T> ver_def;
				CVersion ver(ver_def);
				
				//�o�[�W������������
				{
					CIOResult result;
					m_style.outputVersion(result, new_arc, ver);
				}
				
				//�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j�Ăяo��
				{
					serialize<COArchive, T> functor;
					functor(new_arc, item_obj.template getConst<T>(), ver);
				}
				
				//�Z�[�u�����i�V���A���C�Y��p�����j�Ăяo��
				{
					save<COArchive, T> functor;
					functor(new_arc, item_obj.template getConst<T>(), ver);
				}
				
				//�f�[�^���W�����i�V���A���C�Y��p�����j�Ăяo��
				{
					gatherer<COArchive, T> functor;
					functor(new_arc, item_obj.template getConst<T>(), ver);
				}
				
				//�u���b�N�I��
				block_size = new_arc.m_buffPos;
			}
			
			//�u���b�N�I����񏑂�����
			{
				CIOResult result;
				m_style.outputEndBlock(result, *this, item_obj, block_size);
			}
			
			//�l�X�g���x����0�Ȃ�^�[�~�l�[�^����������
			if (m_nestLevel == 0)
			{
				CIOResult result;
				m_style.outputTerminator(result, *this);
			}
			
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
		COArchive(COArchive& src, const std::size_t size) :
			CIOArchiveBase(src, size)
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
		//�I�y���[�^
		//�u&�v�I�y���[�^
		//���f�[�^���ڎw��p����
		template<class T>
		CIArchive& operator&(const CItem<T> item_obj)
		{
			//printf("[operator&] name=%s, typeName=%s, item=0x%p [%d]\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP, item_obj.m_arrNum);
			//�f�[�^���ڂ��L�^
			addItem(item_obj);
			return *this;
		}
		
		//�u>>�v�I�y���[�^
		//���f�[�^����
		template<class T>
		CIArchive& operator>>(CItem<T> item_obj)
		{
			//printf("[operator>>] name=%s, typeName=%s, item=0x%p\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP);
			
			//�l�X�g���x����0�Ȃ�V�O�l�`���[��ǂݍ���
			if (m_nestLevel == 0)
			{
				CIOResult result;
				m_style.inputSignature(result, *this);
			}
			
			//�u���b�N�J�n���ǂݍ���
			{
				CIOResult result;
				m_style.inputBeginBlock(result, *this, item_obj);
			}
			
			//�u���b�N�J�n
			std::size_t block_size = 0;
			{
				//�V�����A�[�J�C�u�I�u�W�F�N�g�𐶐�
				CIArchive new_arc(*this, m_buffSize - m_buffPos);
				
				//�o�[�W�����ǂݍ���
				CVersion ver;
				{
					CIOResult result;
					m_style.inputVersion(result, new_arc, ver);
				}
				
				//���[�h�O�����i�f�V���A���C�Y��p�����j�Ăяo��
				{
					beforeLoad<CIArchive, T> functor;
					functor(new_arc, item_obj.template get<T>(), ver);
				}
				
				//�f�V���A���C�Y�����i�V���A���C�Y���f�V���A���C�Y���p�����j�Ăяo��
				{
					serialize<CIArchive, T> functor;
					functor(new_arc, item_obj.template getConst<T>(), ver);
				}
				
				//���[�h�����i�f�V���A���C�Y��p�����j�Ăяo��
				{
					load<CIArchive, T> functor;
					functor(new_arc, item_obj.template get<T>(), ver);
				}
				
				//���ۂ̃��[�h����
				for (auto item : *m_itemList)
				{
					CIOResult result(CIOResult::Input(), item);
					m_style.input(result, new_arc, item);
				}
				
				//���[�h�㏈���i�f�V���A���C�Y��p�����j�Ăяo��
				{
					afterLoad<CIArchive, T> functor;
					functor(new_arc, item_obj.template get<T>(), ver);
				}
				
				//�f�[�^���z�����i�f�V���A���C�Y��p�����j�Ăяo��
				{
					distributor<CIArchive, T> functor;
					functor(new_arc, item_obj.template get<T>(), ver);
				}
				
				//�u���b�N�I��
				block_size = new_arc.m_buffPos;
			}
			
			//�u���b�N�I�����ǂݍ���
			{
				CIOResult result;
				m_style.inputEndBlock(result, *this, item_obj, block_size);
			}
			
			//�l�X�g���x����0�Ȃ�^�[�~�l�[�^��ǂݍ���
			if (m_nestLevel == 0)
			{
				CIOResult result;
				m_style.inputTerminator(result, *this);
			}
			
			return *this;
		}
	public:
		//�R���X�g���N�^
		CIArchive(CArchiveStyleBase& style, const void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			CIOArchiveBase(style, const_cast<void*>(buff), buff_size, work_buff, work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(CArchiveStyleBase& style, const BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, const_cast<BUFF_T*>(&buff[0]), BUFF_SIZE, work_buff, WORK_SIZE)
		{}
		template<typename WORK_T, std::size_t WORK_SIZE>
		CIArchive(CArchiveStyleBase& style, const void* buff, const std::size_t buff_size, WORK_T(&work_buff)[WORK_SIZE]) :
			CIOArchiveBase(style, const_cast<void*>(buff), buff_size, work_buff, WORK_SIZE)
		{}
		CIArchive(CIArchive& src, const std::size_t size) :
			CIOArchiveBase(src, size)
		{}
		//�f�X�g���N�^
		~CIArchive()
		{}
	};
	//--------------------
	//�o�C�i���`���A�[�J�C�u�N���X
	class CBinaryArchive : public CArchiveStyleBase
	{
	public:
		//�萔
		static const char SIGNATURE[];//�V�O�l�`��
	public:
		//���\�b�h
		//�V�O�l�`���o��
		bool outputSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//�V�O�l�`�����́i�������f�[�^���`�F�b�N�j
		bool inputSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//�u���b�N�J�n���o��
		bool outputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//�u���b�N�J�n������
		bool inputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//�o�[�W�����o��
		bool outputVersion(CIOResult& result, CIOArchiveBase& arc, const CVersion& ver) override
		{
			return true;
		}
		//�o�[�W��������
		bool inputVersion(CIOResult& result, CIOArchiveBase& arc, CVersion& ver) override
		{
			return true;
		}
		//�o��
		bool output(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//����
		bool input(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//�u���b�N�I�����o��
		bool outputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			return true;
		}
		//�u���b�N�I��������
		bool inputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			return true;
		}
		//�^�[�~�l�[�^�o��
		bool outputTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//�^�[�~�l�[�^���́i�������f�[�^���`�F�b�N�j
		bool inputTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
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
	const char CBinaryArchive::SIGNATURE[] = "";//�V�O�l�`��
	//--------------------
	//�e�L�X�g�`���A�[�J�C�u�N���X
	class CTextArchive : public CArchiveStyleBase
	{
	public:
		//���\�b�h
		//�V�O�l�`���o��
		bool outputSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//�V�O�l�`�����́i�������f�[�^���`�F�b�N�j
		bool inputSignature(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//�u���b�N�J�n���o��
		bool outputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//�u���b�N�J�n������
		bool inputBeginBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//�o�[�W�����o��
		bool outputVersion(CIOResult& result, CIOArchiveBase& arc, const CVersion& ver) override
		{
			return true;
		}
		//�o�[�W��������
		bool inputVersion(CIOResult& result, CIOArchiveBase& arc, CVersion& ver) override
		{
			return true;
		}
		//�o��
		bool output(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//����
		bool input(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item) override
		{
			return true;
		}
		//�u���b�N�I�����o��
		bool outputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			return true;
		}
		//�u���b�N�I��������
		bool inputEndBlock(CIOResult& result, CIOArchiveBase& arc, const CItemBase& item, const std::size_t block_size) override
		{
			return true;
		}
		//�^�[�~�l�[�^�o��
		bool outputTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
		}
		//�^�[�~�l�[�^���́i�������f�[�^���`�F�b�N�j
		bool inputTerminator(CIOResult& result, CIOArchiveBase& arc) override
		{
			return true;
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
	friend struct serial::afterLoad; \
	template<class Arc, class T> \
	friend struct serial::gatherer; \
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
	STRUCT& getData4(){ return m_data4; }//�f�[�^4�擾
	const STRUCT& getData4() const { return m_data4; }//�f�[�^4�擾
	bool getData5(const int index) const { return m_data5[index]; }//�f�[�^5�擾
	void setData5(const int index, const bool value){ m_data5[index] = value; }//�f�[�^5�X�V
public:
	//�R���X�g���N�^
	CTest1() :
		m_data1(0),
		m_data2(0.f),
		m_data4(),
		m_data5()
	{
		m_data3[0] = 0;
		m_data3[1] = 0;
		m_data5.reset();
	}
private:
	//�t�B�[���h
	int m_data1;//�f�[�^1
	float m_data2;//�f�[�^2
	char m_data3[3];//�f�[�^3
	STRUCT m_data4;//�f�[�^4
	std::bitset<8192> m_data5;//�t���O�p
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
static CTest1 s_saveData;

//�Z�[�u�f�[�^������
void initSaveData()
{
	//�Z�[�u�f�[�^�擾
	CTest1& data = s_saveData;
	//�f�[�^��������
	data.setData1(1);
	data.setData2(2.34f);
	data.setData3(0, 5);
	data.setData3(1, 6);
	data.setData3(2, 7);
	data.getData4().m_a = 8;
	data.getData4().m_b = 9;
	data.getData4().m_c = 10;
	data.setData5(0, true);
	data.setData5(1, true);
	data.setData5(8191, true);
}

//�Z�[�u�f�[�^���e�\��
void printSaveData()
{
	//�Z�[�u�f�[�^�擾
	CTest1& data = s_saveData;
	//�f�[�^�\��
	printf("data1=%d\n", data.getData1());
	printf("data2=%.2f\n", data.getData2());
	printf("data3={%d, %d, %d}\n", data.getData3(0), data.getData3(1), data.getData3(2));
	printf("data4:a=%d,b=%d,c=%d\n", data.getData4().m_a, data.getData4().m_b, data.getData4().m_c);
	printf("data5:[0]=%d,[1]=%d,[2]=%d,[8190]=%d,[8191]=%d\n", data.getData5(0), data.getData5(1), data.getData5(2), data.getData5(8190), data.getData5(8191));
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
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver)
		{
			printf("beforeLoad(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//�V���A���C�Y�����p�֐��I�u�W�F�N�g
	//���V���A���C�Y�ƃf�V���A���C�Y���p���ʏ���
	template<class Arc>
	struct serialize<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver)
		{
			printf("serialize(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			arc & pair("data1", obj.m_data1);
			arc & pair("data2", obj.m_data2);
			arc & pair("data3", obj.m_data3);
			arc & pair("data4", obj.m_data4);
			arc & pairBin("data5", obj.m_data5);
		}
	};
	template<class Arc>
	struct serialize<Arc, CTest1::STRUCT> {
		void operator()(Arc& arc, const CTest1::STRUCT& obj, const CVersion& ver)
		{
			printf("serialize::STRUCT(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			arc & pair("data1", obj.m_a);
			arc & pair("data2", obj.m_b);
			arc & pair("data3", obj.m_c);
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
			printf("save(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//���[�h�����p�֐��I�u�W�F�N�g�N���X
	//���f�V���A���C�Y��p����
	template<class Arc>
	struct load<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver)
		{
			printf("load(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//���[�h�㏈���p�֐��I�u�W�F�N�g�N���X
	//���f�V���A���C�Y��p����
	template<class Arc>
	struct afterLoad<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver)
		{
			printf("afterLoad(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//�f�[�^���W�����p�֐��I�u�W�F�N�g�N���X
	//���V���A���C�Y��p����
	template<class Arc>
	struct gatherer<Arc, CTest1> {
		void operator()(Arc& arc, const CTest1& obj, const CVersion& ver)
		{
			printf("gatherer(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//�f�[�^���z�����p�֐��I�u�W�F�N�g�N���X
	//���f�V���A���C�Y��p����
	template<class Arc>
	struct distributor<Arc, CTest1> {
		void operator()(Arc& arc, CTest1& obj, const CVersion& ver)
		{
			printf("distributor(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
		}
	};
#endif
#if 1
	//--------------------
	//�f�[�^���W�����p�֐��I�u�W�F�N�g�N���X
	//���V���A���C�Y��p����
	template<class Arc>
	struct gatherer<Arc, CSaveDataSerializer> {
		void operator()(Arc& arc, const CSaveDataSerializer& obj, const CVersion& ver)
		{
			printf("CSaveDataSerializer::gatherer(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			//�Ώۃf�[�^�擾
			CTest1& data = s_saveData;
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
		void operator()(Arc& arc, CSaveDataSerializer& obj, const CVersion& ver)
		{
			printf("CSaveDataSerializer::distributor(ver=%d,%d)\n", ver.getMajor(), ver.getMinor());
			//�Ώۃf�[�^�擾
			CTest1& data = s_saveData;
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
	//�Z�[�u�f�[�^������
	initSaveData();
	//�Z�[�u�f�[�^�\��
	printSaveData();
	//�o�b�t�@����
	char buff[16 * 1024];//�Z�[�u�f�[�^�p�o�b�t�@
	char work[16 * 1024];//���[�N�p�o�b�t�@
	//�V���A���C�Y
	serial::COBinaryArchive oa(buff, work);//�o�̓A�[�J�C�u�쐬�F�e�L�X�g�A�[�J�C�u
	oa << serial::pair<CSaveDataSerializer>("SaveData");//�V���A���C�Y
	//�t�@�C���ɏ����o��
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "wb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "wb");
#endif//USE_STRCPY_S
	fwrite(buff, 1, oa.getBuffPos(), fp);
	fclose(fp);
	fp = NULL;
}
//--------------------
//�f�V���A���C�Y�e�X�g�P�F�o�C�i���A�[�J�C�u
void deserializeTest1(const char* file_path)
{
	printf("--------------------\n");
	printf("�f�V���A���C�Y�F�o�C�i���A�[�J�C�u\n");
	//�o�b�t�@����
	char buff[16 * 1024];//�Z�[�u�f�[�^�p�o�b�t�@
	char work[16 * 1024];//���[�N�p�o�b�t�@
	//�t�@�C������ǂݍ���
#ifdef USE_STRCPY_S
	FILE* fp = nullptr;
	fopen_s(&fp, file_path, "rb");
#else//USE_STRCPY_S
	FILE* fp = fopen(file_path, "rb");
#endif//USE_STRCPY_S
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	fread(buff, 1, file_size, fp);
	fclose(fp);
	fp = NULL;
	//�f�V���A���C�Y
	serial::CIBinaryArchive ia(buff, file_size, work);
	ia >> serial::pair<CSaveDataSerializer>("CTest1", file_size);
	//�Z�[�u�f�[�^�\��
	printSaveData();
}
//--------------------
//�V���A���C�Y���f�V���A���C�Y�e�X�g�P�F�o�C�i���A�[�J�C�u
void test1()
{
	static const char* file_path = "test1.bin";
	//�V���A���C�Y
	serializeTest1(file_path);
	//�f�V���A���C�Y
	deserializeTest1(file_path);
}

//--------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	test1();

	return EXIT_SUCCESS;
}

// End of file
