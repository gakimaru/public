//----- �T�C�Y�v�Z -----
//�ysize.h�z

#pragma once
#ifndef __SIZE_H_
#define __SIZE_H_

//�z��̃T�C�Y�i�v�f���j���擾
//���œK���ɂ��A�֐������ł��ăv���O�����R�[�h��Œ��l��������
template<typename T, size_t SIZE>
size_t GetArraySize(const T (&)[SIZE])
{
	return SIZE;
}

//�i��������́j�z��T�C�Y�擾�}�N��
#define GET_ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

//�z��̒������擾
//��'\0'���^�[�~�l�[�^�[�Ƃ���v�f���ŁA�^�[�~�l�[�^�[���܂܂Ȃ�����
//���^�[�~�l�[�^�[��������Ȃ��ꍇ�A�z��̗v�f�����Ԃ�
//���œK���ɂ��A�֐������ڏ����R�[�h��ɓW�J�����
template<typename T, size_t SIZE>
size_t GetArrayLen(const T (&arr)[SIZE])
{
	size_t len = 0;
	for(; arr[len] && len < SIZE; ++ len){}
	return len;
}

//������Ɋ�Â��āA������ƕ����񒷂���ѕ�����T�C�Y�̒萔���`
//�������񒷂͎����v�Z
#define DEF_STR_AND_LEN_COMMON(STATIC, NAME, STR) \
	STATIC const char* NAME = STR; \
	STATIC const char NAME##_ARRAY[] = {STR}; \
	STATIC const size_t NAME##_LEN = GetArrayLen(NAME##_ARRAY); \
	STATIC const size_t NAME##_SIZE = GetArraySize(NAME##_ARRAY);
#define DEF_STATIC_STR_AND_LEN(NAME, STR) \
	DEF_STR_AND_LEN_COMMON(static, NAME, STR)
#define DEF_STR_AND_LEN(NAME, STR) \
	DEF_STR_AND_LEN_COMMON(, NAME, STR)

//������Ɋ�Â��āA������ƕ����񒷂���ѕ�����T�C�Y�̒萔���Q��
#define REF_STR_AND_LEN_COMMON(STATIC, NAME) \
	extern STATIC const char* NAME; \
	extern STATIC const char NAME##_ARRAY_[]; \
	extern STATIC const size_t NAME##_LEN; \
	extern STATIC const size_t NAME##_SIZE;
#define REF_STATIC_STR_AND_LEN(NAME) \
	REF_STR_AND_LEN_COMMON(, NAME)
#define REF_STR_AND_LEN(NAME) \
	REF_STR_AND_LEN_COMMON(, NAME)

#endif//__SIZE_H_

// End of file
