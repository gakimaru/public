//----- �ÓICRC32�����e���v���[�g�p�w�b�_�[ -----
//�ycrc32_template.h�z

//#pragma once
#ifndef __CRC32_TEMPLATE_H_
#define __CRC32_TEMPLATE_H_

//�R���p�C���X�C�b�`
//#define USE_CRC32_CALC_LEN //CRC32�v�Z�ł̕����񒷌v�Z�L����
//#define USE_CRC32_TABLE_CLASS //CRC32�������v�Z�e�[�u���N���X�g�p�L�����@�����������͒��ڔz����g�p

//�C���N���[�h
#include <stddef.h>
#include "common/size.h"
#include "crc/crc32.h"
#include "crc/crc32_table.h"

//�ÓICRC32�����e���v���[�g�֐�
template<typename T, size_t SIZE>
CRC32T CalcCRC32Static(const T (&arr)[SIZE])
{
#ifdef USE_CRC32_CALC_LEN
	const size_t LEN = StaticGetArrayLen(arr); //���{���͂�����̏����ŕ����񒷂����߂������A�R�[�h�T�C�Y���傫���Ȃ�̂Œf�O
#else//USE_CRC32_CALC_LEN
	const size_t LEN = SIZE - 1;               //������ɁA�z��̗v�f�T�C�Y����P���������Ƃ���
#endif//USE_CRC32_CALC_LEN
	
	CALC_CRC32_DEF(crc32);
	for(size_t pos = 0; pos < LEN; ++ pos)
	{
		const CRC32T val = arr[pos];
	#ifdef USE_CRC32_TABLE_CLASS
		//�y�ł���΂�����̋����ł����Ăق����z
		//�����瑤�̏�����L���ɂ����ۂɁA�e���v���[�g�֐����C���X�^���X�����ꂸ�A�R���p�C������CRC�𐶐����鋓���ɂȂ�Ȃ�A�����瑤�̏�����L���ɂ���
		// �� �~�����́A�e���v���[�g�֐����C���X�^���X������āA���s����CRC����������Ă����iVisual Studio 2012�j
		static CRC32T crc32_table[] = CRC32_TABLE_VALUES;
		CALC_CRC32_VALUE(crc32, val, crc32_table[index]);
	#else//USE_CRC32_TABLE_CLASS
		//�y�����Ȃ�d���Ȃ��z
		//��L���̏�����L���ɂ��Ă��A�e���v���[�g�֐����C���X�^���X������āA���s����CRC�𐶐����鋓���ɂȂ�Ȃ�A�����瑤�̏�����L���ɂ���
		// �� �������́A�e���v���[�g�֐����C���X�^���X������āA���s����CRC����������Ă����iVisual Studio 2012�j
		static CCRC32Table crc32_table;
		CALC_CRC32_VALUE(crc32, val, crc32_table.GetTable(index));
	#endif//USE_CRC32_TABLE_CLASS
	}
	CALC_CRC32_END(crc32);
	return crc32;
}

//�ÓICRC32��`�p�}�N��
#define DEF_CRC32_BY_STR(NAME, STR) \
	const char* NAME = STR; \
	const char NAME##_ARRAY[] = {STR}; \
	const CRC32T NAME##_CRC = CalcCRC32Static(NAME##_ARRAY);
//#define DEF_CRC32_BY_STR(NAME, STR) \
//	const char* NAME = STR; \
//	const char NAME##_ARRAY[] = {STR}; \
//	const CRC32T NAME##_CRC = CalcCRC32(NAME##_ARRAY);

#endif//__CRC32_TEMPLATE_H_

// End of file
