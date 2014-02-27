//----- CRC32���� -----
//�ycrc32.h�z

#pragma once
#ifndef __CRC32_H_
#define __CRC32_H_

//CRC32�^
typedef unsigned int CRC32T;

//CRC32�����֐�
CRC32T CalcCRC32(const char* str);

//�ÓICRC32��`�Q�Ɨp�}�N��
#define REF_CRC32_BY_STR(NAME) \
	extern const char* NAME; \
	extern const CRC32T NAME##_CRC;

#endif//__CRC32_H_

// End of file
