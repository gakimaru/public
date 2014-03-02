#define TLS_IS_WINDOWS//�yMS�ŗL�d�l�zTLS�̐錾��Windows�X�^�C���ɂ��鎞�͂��̃}�N����L���ɂ���
#define USE_WINDOWS_DEBUG_BREAK//�yMS�ŗL�d�l�zWindow��DebugBreak���g�p
#define USE_ALIGNED_MALLOC//�yMS�ŗL�d�l�z_aligned_malloc���g�p���鎞�͂��̃}�N����L���ɂ���
#define USE_FRIEND_WITH_NEW_OPERATOR//�yMS�ŗL�d�l�H�zoperator new()���N���X���Ńt�����h�����鎞�͂��̃}�N����L���ɂ���

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

//--------------------
//lib
namespace serializer
{
	//�o�[�W�����N���X
	template<int MAJOR, int MINOR>
	struct versionDefBase;
	struct version
	{
		static const int VER_FIGURE = 1000000;
		int majorVer() const { return m_majorVer; };
		int minorVer() const { return m_majorVer; };
		int ver()const { return m_majorVer * VER_FIGURE + m_minorVer; };
		template<int MAJOR, int MINOR>
		version(versionDefBase<MAJOR, MINOR>&) :
			m_majorVer(MAJOR),
			m_minorVer(MINOR)
		{}
	private:
		const int m_majorVer;
		const int m_minorVer;
	};
	template<int MAJOR, int MINOR>
	struct versionDefBase
	{
		static const int MAJOR_VER = MAJOR;
		static const int MINOR_VER = MINOR;
		static const int VER = MAJOR_VER * version::VER_FIGURE + MINOR_VER;
		int majorVer() const { return MAJOR_VER; };
		int minorVer() const { return MINOR_VER; };
		int ver() const { return VER; };
	};
	template<class T>
	struct versionDef : public versionDefBase<0, 0>{};

	struct ITEM_BASE
	{
		const crc32_t m_nameCrc;
		const char* m_name;
		const void* m_itemP;
		const std::type_info& m_itemType;
		const std::size_t m_itemSize;
		const std::size_t m_arrNum;
		template<typename T>
		T& get(){ return *static_cast<T*>(const_cast<void*>(m_itemP)); }
		template<typename T>
		T& get(const int index){ return static_cast<T*>(const_cast<void*>(m_itemP))[index]; }
		template<typename T>
		const T& get() const { return *static_cast<const T*>(m_itemP); }
		template<typename T>
		const T& get(const int index) const { return static_cast<const T*>(m_itemP)[index]; }
		template<typename T>
		const T& getConst() const { return *static_cast<const T*>(m_itemP); }
		template<typename T>
		const T& getConst(const int index) const { return static_cast<const T*>(m_itemP)[index]; }
		ITEM_BASE(const char* name, const void* item_p, const std::type_info& item_type, const std::size_t item_size, const std::size_t arr_num = 0) :
			m_nameCrc(calcCRC32(name)),
			m_name(name),
			m_itemP(item_p),
			m_itemType(item_type),
			m_itemSize(item_size),
			m_arrNum(arr_num)
		{}
	};
	template<typename T>
	struct ITEM : ITEM_BASE
	{
		ITEM(const char* name, const T& item, const std::size_t arr_num = 0) :
			ITEM_BASE(name, &item, typeid(item), sizeof(item), arr_num)
		{}
	};
	template<class T>
	ITEM<T> makeItem(const char* name, const T& item)
	{
		ITEM<T> item_obj(name, item);
		return item_obj;
	}
	template<class T, std::size_t N>
	ITEM<T> makeItem(const char* name, const T(&item)[N])
	{
		ITEM<T> item_obj(name, item[0], N);
		return item_obj;
	}

	template<class Arc, class T>
	struct beforeLoad
	{
		void operator()(Arc& arc, T& obj)
		{}
	};
	template<class Arc, class T>
	struct serialize
	{
		void operator()(Arc& arc, const T& obj)
		{}
	};
	template<class Arc, class T>
	struct save
	{
		void operator()(Arc& arc, const T& obj)
		{}
	};
	template<class Arc, class T>
	struct load
	{
		void operator()(Arc& arc, const T& obj)
		{}
	};
	template<class Arc, class T>
	struct afterLoad
	{
		void operator()(Arc& arc, T& obj)
		{}
	};
	template<class Arc, class T>
	struct gatherer
	{
		void operator()(Arc& arc, const T& obj)
		{}
	};
	template<class Arc, class T>
	struct distributor
	{
		void operator()(Arc& arc, T& obj)
		{}
	};

	class ArchiveBase
	{
	public:
		typedef unsigned char byte;
		typedef std::map<crc32_t, const ITEM_BASE> itemList_t;

	};
	class OArchive : public ArchiveBase
	{
	public:
		template<class T>
		OArchive& operator&(const ITEM<T> item_obj)
		{
			printf("[operator&] name=%s, typeName=%s, item=0x%p [%d]\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP, item_obj.m_arrNum);
			assert(m_itemList.find(item_obj.m_nameCrc) == m_itemList.end());
			m_itemList.emplace(item_obj.m_nameCrc, item_obj);
			return *this;
		}
		template<class T>
		OArchive& operator<<(const ITEM<T> item_obj)
		{
			printf("[operator<<] name=%s, typeName=%s, item=0x%p\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP);
			serializer::versionDef<T> ver;
			printf("T::ver=%d.%d\n", ver.majorVer(), ver.minorVer());
			
			itemList_t item_list_mem;
			item_list_mem.swap(m_itemList);

			{
				serialize<OArchive, T> functor;
				functor(*this, item_obj.template getConst<T>());
			}

			{
				save<OArchive, T> functor;
				functor(*this, item_obj.template getConst<T>());
			}

			{
				gatherer<OArchive, T> functor;
				functor(*this, item_obj.template getConst<T>());
			}
			
			m_itemList.swap(item_list_mem);

			return *this;
		}
	public:
		OArchive(void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_buff(reinterpret_cast<byte*>(buff)),
			m_buffSize(buff_size),
			m_buffPos(0),
			m_workBuff(reinterpret_cast<byte*>(work_buff)),
			m_workBuffSize(work_buff_size)
		{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		OArchive(BUFF_T (&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			OArchive(buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
	private:
		byte* m_buff;
		const std::size_t m_buffSize;
		std::size_t m_buffPos;
		byte* m_workBuff;
		const std::size_t m_workBuffSize;
		itemList_t m_itemList;
	};
	class IArchive : public ArchiveBase
	{
	public:
		template<class T>
		IArchive& operator&(const ITEM<T> item_obj)
		{
			printf("[operator&] name=%s, typeName=%s, item=0x%p [%d]\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP, item_obj.m_arrNum);
			assert(m_itemList.find(item_obj.m_nameCrc) == m_itemList.end());
			m_itemList.emplace(item_obj.m_nameCrc, item_obj);
			return *this;
		}
		template<class T>
		IArchive& operator>>(ITEM<T> item_obj)
		{
			printf("[operator>>] name=%s, typeName=%s, item=0x%p\n", item_obj.m_name, item_obj.m_itemType.name(), item_obj.m_itemP);
			serializer::versionDef<T> ver;
			printf("T::ver=%d.%d\n", ver.majorVer(), ver.minorVer());
			
			itemList_t item_list_mem;
			item_list_mem.swap(m_itemList);
			
			{
				beforeLoad<IArchive, T> functor;
				functor(*this, item_obj.template get<T>());
			}
			
			{
				serialize<IArchive, T> functor;
				functor(*this, item_obj.template getConst<T>());
			}

			{
				load<IArchive, T> functor;
				functor(*this, item_obj.template get<T>());
			}

			for (auto ite : m_itemList)
			{
				ITEM_BASE& item = const_cast<ITEM_BASE&>(ite.second);
				if (item.m_arrNum == 0)
				{
					if (item.m_itemType == typeid(int))
						item.get<int>() = 123;
					else if (item.m_itemType == typeid(float))
						item.get<float>() = 1.23f;
				}
				else
				{
					for (std::size_t i = 0; i < item.m_arrNum; ++i)
					{
						if (item.m_itemType == typeid(char))
							item.get<char>(i) = 123;
					}
				}
			}

			{
				afterLoad<IArchive, T> functor;
				functor(*this, item_obj.template get<T>());
			}

			{
				distributor<IArchive, T> functor;
				functor(*this, item_obj.template get<T>());
			}
			
			m_itemList.swap(item_list_mem);
			
			return *this;
		}
	public:
		IArchive(const void* buff, const std::size_t buff_size, void* work_buff, std::size_t work_buff_size) :
			m_buff(reinterpret_cast<const byte*>(buff)),
			m_buffSize(buff_size),
			m_buffPos(0),
			m_workBuff(reinterpret_cast<byte*>(work_buff)),
			m_workBuffSize(work_buff_size)
			{}
		template<typename BUFF_T, std::size_t BUFF_SIZE, typename WORK_T, std::size_t WORK_SIZE>
		IArchive(const BUFF_T(&buff)[BUFF_SIZE], WORK_T(&work_buff)[WORK_SIZE]) :
			IArchive(buff, BUFF_SIZE, work_buff, WORK_SIZE)
		{}
	private:
		const byte* m_buff;
		const std::size_t m_buffSize;
		std::size_t m_buffPos;
		byte* m_workBuff;
		const std::size_t m_workBuffSize;
		itemList_t m_itemList;
	};
}

#define SERIALIZE_VERSION_DEF(T, MAJOR, MINOR) \
	namespace serializer \
	{ \
		template<> \
		struct versionDef<CTest1> : public versionDefBase<MAJOR, MINOR>{}; \
	}

#define FRIEND_SERIALIZE(T) \
	template<class Arc, class T> \
	friend struct serializer::beforeLoad; \
	template<class Arc, class T> \
	friend struct serializer::serialize; \
	template<class Arc, class T> \
	friend struct serializer::save; \
	template<class Arc, class T> \
	friend struct serializer::load; \
	template<class Arc, class T> \
	friend struct serializer::afterLoad; \
	template<class Arc, class T> \
	friend struct serializer::gatherer; \
	template<class Arc, class T> \
	friend struct serializer::distributor;

//user
class CTest1
{
	FRIEND_SERIALIZE(CTest1);
private:
	int m_data1;
	float m_data2;
	char m_data3[3];
};
//user
SERIALIZE_VERSION_DEF(CTest1, 123, 456);
namespace serializer
{
#if 1
	template<class Arc>
	struct beforeLoad<Arc, CTest1>
	{
		void operator()(Arc& arc, CTest1& obj)
		{
		}
	};
#endif
#if 1
	template<class Arc>
	struct serialize<Arc, CTest1>
	{
		void operator()(Arc& arc, const CTest1& obj)
		{
			printf("serialize\n");
			printf("obj.m_data1=0x%p\n", &obj.m_data1);
			printf("obj.m_data2=0x%p\n", &obj.m_data2);
			printf("obj.m_data3=0x%p\n", &obj.m_data3);
			arc & makeItem("data1", obj.m_data1);
			arc & makeItem("data2", obj.m_data2);
			arc & makeItem("data3", obj.m_data3);
		}
	};
#endif
#if 1
	template<class Arc>
	struct save<Arc, CTest1>
	{
		void operator()(Arc& arc, const CTest1& obj)
		{
		}
	};
#endif
#if 1
	template<class Arc>
	struct load<Arc, CTest1>
	{
		void operator()(Arc& arc, CTest1& obj)
		{
		}
	};
#endif
#if 1
	template<class Arc>
	struct afterLoad<Arc, CTest1>
	{
		void operator()(Arc& arc, CTest1& obj)
		{
		}
	};
#endif
#if 1
	template<class Arc>
	struct gatherer<Arc, CTest1>
	{
		void operator()(Arc& arc, const CTest1& obj)
		{
		}
	};
#endif
#if 1
	template<class Arc>
	struct distributor<Arc, CTest1>
	{
		void operator()(Arc& arc, CTest1& obj)
		{
		}
	};
#endif
}//namespace serializer

//�e�X�g
int main(const int argc, const char* argv[])
{
	CTest1 obj;
	printf("&obj=0x%p\n", &obj);
	
	char buff[1024];
	char work[1024];
	serializer::OArchive oa(buff, work);
	oa << serializer::makeItem("CTest1", obj);
	
	serializer::IArchive ia(buff, work);
	ia >> serializer::makeItem("CTest1", obj);
	
	return EXIT_SUCCESS;
}

// End of file
