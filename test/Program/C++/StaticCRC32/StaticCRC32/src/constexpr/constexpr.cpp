#define MAKE_CRC_INSTANCE//"constexpr.h"���ɒ�`����Ă���֐������̉�
#include "constexpr.h"

#include <stdio.h>//printf�p

#ifdef USE_SSE
#include <nmmintrin.h>//SSE4.2
#endif//USE_SSE

//--------------------------------------------------------------------------------
//CRC�Z�o

#ifdef ENABLE_RUNTIME_FUNC
//--------------------
//�y�ʏ�֐��Łz�����񂩂�CRC�Z�o
crc32_t calcCRC32(const char* str)
{
	crc32_t crc = ~0u;
	const char* p = str;
	while (*p)
	{
	#ifndef USE_SSE
	#ifndef USE_STATIC_TABLE
		crc = crc_sub::calcPoly(static_cast<crc32_t>((crc ^ *(p++)) & 0xffu)) ^ (crc >> 8);//CRC������(��������������v�Z)������
	#else//USE_STATIC_TABLE
		crc = crc_sub::s_polyTable[(crc ^ *(p++)) & 0xffu] ^ (crc >> 8);//CRC������(�v�Z�ς݃e�[�u���̒l)������
	#endif//USE_STATIC_TABLE
	#else//USE_SSE
		crc = _mm_crc32_u8(crc, *(p++));//CRC������(SSE4.2�ɂ��v�Z)������
	#endif//USE_SSE
	}
	return ~crc;
}
//--------------------
//�y�ʏ�֐��Łz�f�[�^�����w�肵��CRC�Z�o
crc32_t calcCRC32(const char* data, const std::size_t len)
{
	crc32_t crc = ~0u;
	const char* p = data;
	for (std::size_t pos = 0; pos < len; ++pos)
	{
	#ifndef USE_SSE
	#ifndef USE_STATIC_TABLE
		crc = crc_sub::calcPoly(static_cast<crc32_t>((crc ^ *(p++)) & 0xffu)) ^ (crc >> 8);//CRC������(��������������v�Z)������
	#else//USE_STATIC_TABLE
		crc = crc_sub::s_polyTable[(crc ^ *(p++)) & 0xffu] ^ (crc >> 8);//CRC������(�v�Z�ς݃e�[�u���̒l)������
	#endif//USE_STATIC_TABLE
	#else//USE_SSE
		crc = _mm_crc32_u8(crc, *(p++));//CRC������(SSE4.2�ɂ��v�Z)������
	#endif//USE_SSE
	}
	return ~crc;
}
#endif//ENABLE_RUNTIME_FUNC
#ifdef ENABLE_MAKE_STATIC_TABLE
//--------------------
//CRC�������e�[�u�����쐬
void makePolyTable()
{
	printf("\tCONSTEXPR crc32_t s_polyTable[256] =\n");
	printf("\t{\n");
	for (int i = 0; i < 256; ++i)
	{
		if (i > 0)
		{
			printf(",");
			if (i % 8 == 0)
				printf("\n");
			else
				printf(" ");
		}
		if (i % 8 == 0)
			printf("\t\t");
		printf("0x%08xu", crc_sub::calcPoly(i));
	}
	printf("\n\t};\n");
}
#endif//ENABLE_MAKE_STATIC_TABLE

// End of file
