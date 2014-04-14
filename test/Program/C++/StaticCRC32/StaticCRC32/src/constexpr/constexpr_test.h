//C++11�p�� constexpr / ���[�U�[��`���e�������g�����R���p�C����CRC�v�Z�����SSE4.2���g�p����CRC�v�Z�e�X�g

//--------------------
#include "constexpr.h"

//--------------------
//�R���p�C���X�C�b�`�p�}�N��
//#define ENABLE_MAIN//���C���֐���L���ɂ��鎞�͂��̃}�N����L���ɂ���

//#define USE_MAKE_STATIC_TABLE//CRC�������e�[�u���쐬���g�p���鎞�͂��̃}�N����L���ɂ���
#define ENABLE_CONSTEXPR_TEST//constexpr�e�X�g��L���ɂ��鎞�͂��̃}�N����L���ɂ���
#define ENABLE_USER_DEFINED_LITERALS_TEST//���[�U�[��`���e�����e�X�g��L���ɂ��鎞�͂��̃}�N����L���ɂ���
#define ENABLE_RUNTIME_TEST//�����^�C����CRC�v�Z�e�X�g��L���ɂ��鎞�͂��̃}�N����L���ɂ���
//#define ENABLE_MORE_TEST//�ǉ��e�X�g��L���ɂ��鎞�͂��̃}�N����L���ɂ���
//#define ENABLE_PERFORMANCE_TEST//�p�t�H�[�}���X�e�X�g��L���ɂ��鎞�͂��̃}�N����L���ɂ���

//#define USE_STATIC_ASSERT//static_assert���g�p���鎞�͂��̃}�N����L���ɂ���

#define CONST_TO_CONST//CONST�}�N����const�ɂ��鎞�͂��̃}�N����L���ɂ���
//#define NOCONST_TO_CONST//NOCONST�}�N����const�ɂ��鎞�͂��̃}�N����L���ɂ���

//���u�����^�C����CRC�v�Z�e�X�g�v�Ɓu�ǉ��e�X�g�v�A�u�p�t�H�[�}���X�e�X�g�v�𖳌�������ƁA
//�@constexpr�ƃ��[�U�[��`���e�����̂ɂ��A�����񃊃e���� "1234567890" ��
//�@�R���p�C�����ɏ��ł��āACRC�̃��e�����l�ň����邱�Ƃ��A�A�Z���u���R�[�h����m�F�ł���B
//�@�Ȃ��Aconst�^�Ōv�Z���ʂ��󂯂Ȃ��ƁA�R���p�C�����Ɍv�Z���ꂸ�A�����^�C�����̏����ɂȂ��Ă��܂��̂Œ��ӁB

//--------------------
//�R���p�C���X�C�b�`����
#ifndef ENABLE_MAKE_STATIC_TABLE
#ifdef USE_MAKE_STATIC_TABLE
#undef USE_MAKE_STATIC_TABLE//��CRC�������e�[�u�����쐬�������Ȃ�A�Ăяo���Ȃ�
#endif//USE_MAKE_STATIC_TABLE
#endif//ENABLE_MAKE_STATIC_TABLE

#ifndef ENABLE_USER_DEFINED_LITERALS
#ifdef ENABLE_USER_DEFINED_LITERALS_TEST
#undef ENABLE_USER_DEFINED_LITERALS_TEST//�����[�U�[��`���e�����������Ȃ�A�e�X�g�ł��Ȃ�
#endif//ENABLE_USER_DEFINED_LITERALS_TEST
#endif//ENABLE_USER_DEFINED_LITERALS

#ifndef ENABLE_RUNTIME_FUNC
#ifdef ENABLE_RUNTIME_TEST
#undef ENABLE_RUNTIME_TEST//�������^�C���֐��������Ȃ�A�e�X�g�ł��Ȃ�
#endif//ENABLE_RUNTIME_TEST
#ifdef ENABLE_PERFORMANCE_TEST
#undef ENABLE_PERFORMANCE_TEST//�������^�C���֐��������Ȃ�A�p�t�H�[�}���X�e�X�g�ł��Ȃ�
#endif//ENABLE_PERFORMANCE_TEST
#endif//ENABLE_RUNTIME_FUNC

//--------------------
//CONST�}�N��
#ifdef CONST_TO_CONST
#define CONST const//��CONST��const�Ƃ��Ĉ���
#else//CONST_TO_CONST
#define CONST//��CONST���const�Ƃ��Ĉ���
#endif//CONST_TO_CONST
//NOCONST�}�N��
#ifdef NOCONST_TO_CONST
#define NOCONST const//��NOCONST��const�Ƃ��Ĉ���
#else//NOCONST_TO_CONST
#define NOCONST//��NOCONST���const�Ƃ��Ĉ���
#endif//NOCONST_TO_CONST

// End of file
