#pragma once
#ifndef __GAME_MAIN_H__
#define __GAME_MAIN_H__

#include "unit_test.h"

//�Q�[�����C���N���X
class CGameMain
{
public:
	//�R���X�g���N�^
	explicit CGameMain(const int argc, const char* argv[]);
	//��explicit�錾�̉��
	//  �uexplicit�v�錾�́A�uCClass obj = 1;�v�̂悤�ȈÖٓI�ȃL���X�g���֎~����B
	//  �Ⴆ�΁A����ď������uobj = func();//int�l��Ԃ��v�Ƃ������������R���p�C�����ɃG���[�ɂȂ�悤�ɂł���B
	//  �ʏ�́A�p�����[�^�̌^����v����R���X�g���N�^�������I�ɌĂяo�����̂ŁA
	//  ���̋������Ӑ}����ꍇ�ȊO�� explicit ��t���Ă������������S�B
	//  �{���̓p�����[�^����̃R���X�g���N�^�ׂ̈̐錾�����A����ȊO�̃R���X�g���N�^�ɓK�p���Ă����͂Ȃ��̂ŁA
	//  �K���Ƃ���explicit�錾��t���鎖�ɂ��Ă����Ă��ǂ��B

private:
	explicit CGameMain() :m_argc(0), m_argv(nullptr){}//�f�t�H���g�R���X�g���N�^�������iprivate���j
	//���f�t�H���g�R���X�g���N�^�̉��
	//  �uCClass obj;�v�̂悤�ȁA�p�����[�^���w�肵�Ȃ��R���X�g���N�^�̋������`����B
	//  �R���X�g���N�^����ؒ�`����Ă��Ȃ��ꍇ���A�f�t�H���g�R���X�g���N�^����`����Ă���ꍇ�Ɍ���A
	//  �p�����[�^��^�����ɃI�u�W�F�N�g�𐶐��ł���B
	
	explicit CGameMain(CGameMain&) : m_argc(0), m_argv(nullptr){}//�R�s�[�R���X�g���N�^�������iprivate���j
	//���R�s�[�R���X�g���N�^�̉��
	//  �uCClass obj1(obj2);�v��uCClass obj1 = obj2;�v�̂悤�ȁA���g�Ɠ����I�u�W�F�N�g���n���ꂽ���̋������`����B
	//  �R�s�[�R���X�g���N�^�̒�`�������ꍇ�A�R���p�C�����ÖٓI�ɃR�s�[�R���X�g���N�^���쐬���A�P���ȃ������R�s�[���s���B
	//  �Ȃ��A�uCClass obj1 = obj2;�v�̂悤�ȑ��������֎~���āA�uCClass obj1(obj2);�v�̂悤�Ȗ����I�ȃp�����[�^�w�肾�����������ꍇ�́A
	//  �R�s�[�R���X�g���N�^�� public �ɂ��� explicit �錾��t����B
	//  �܂��A�ϐ��錾���ȊO�̑�����삪�K�v�ȏꍇ�́A�uCClass& operator=(CClass& r)�v�̂悤�ɁA
	//  ������Z�q�̃I�[�o�[���[�h�֐����`����B

public:
	//�f�X�g���N�^
	~CGameMain();
	//���f�X�g���N�^��virtual�錾�̉��
	//  �f�X�g���N�^�̋L�q�́uvirtual ~CClass();�v�̂悤�ɁA�uvirtual�v�錾��t���鎖���K���ɂ��Ă��鎖���������A
	//  ����͐������Ȃ��B
	//  �N���X���Ɉ�ł��uvirtual�v�錾������ƁA�uvtable�v�Ƃ����uvirtual�v�֐��̃|�C���^�[�̃��X�g������A
	//  �N���X�͈ÖٓI�ɂ��̎Q�Ƃ�ێ�����\���Ɋg�������B�܂�A���������T�C�Y���傫���Ȃ�B
	//  �܂��A�uCClass obj;�v��uCClass* obj = new CClass();�v�̂悤�ɂ�����ƃI�u�W�F�N�g�𐶐����Ȃ��ƁA
	//  �uvtable�v�̎Q�Ɓi�|�C���^�[�j���������i�[���ꂸ�A�uvirtual�v�֐��Ăяo�����ɐ���ɏ�������Ȃ��Ȃ�B
	//  �ȏ�̎�����A�Ӑ}�����P�[�X�ȊO�ł͋ɗ́uvirtual�v�̎g�p���T���鎖�𐄏�����B
	//  �u�Ӑ}�����P�[�X�v�Ƃ́A�e�N���X�̃|�C���^�[�Ƃ��ăI�u�W�F�N�g���󂯓n���ď������Ăяo���K�v������ꍇ�B
	//  �e�N���X�̃|�C���^�[�ɑ΂��� delete �����s�����ۂɁA�q�N���X�̃f�X�g���N�^���Ăяo���K�v������ꍇ��
	//  �uvirtual�v��t���Ȃ���΂Ȃ�Ȃ��B
	//  ���̂悤�ȃN���X�̑��Ԑ��̎d�g�݂𐏏��Ŏg�p���Ă���悤�ȃv���W�F�N�g�ł́A�f�X�g���N�^�̌Ăяo����
	//  �m���ɂ���ׂɂ��A�u�S�ẴN���X�̃f�X�g���N�^�ɂ�virtual�錾��t���鎖�v�Ƃ������P���ȃ��[����
	//  �~���������R�[�f�B���O�~�X���y���ł��邪�A�Q�[������̏ꍇ�͉\�Ȍ���uvirtual�v�̎g�p���T���A
	//  �Ӑ}���Ďg�����ɂ����C�������悤�ɂ��鎖�𐄏�����B
	//  �uvirutal�v�𗔗p���ăp�t�H�[�}���X�̒ቺ����������A������I�[�o�[���C�h�ɋC���t���ɂ����Ƃ��������̕���
	//  �d������B���ɁA�e�N���X�́uvirtual�v�֐��̈�����ύX�����肷��ƁA�R���p�C���G���[���o����
	//  �I�[�o�[���C�h���O��āA�������ς���Ă��܂���������B
	//  �N���X�̐݌v�́A�{���Ɍp���⑽�Ԑ����K�v���ǂ������\���ɋᖡ���A�K�v�Ȃ�utemplate�v����g����
	//  ���Ԑ��̎������@�i�����ʓ|�j���������ȂǍH�v���āA�ł������ virtual �̎g�p���T����悤�ɂ���B

public:
	//�A�N�Z�b�T
	int getArgc() const { return this->m_argc; }
//	const char** getArgv() const { return this->m_argv; }
	const char* getArgv(const int index) const { return index >= 0 && index < this->m_argc ? this->m_argv[index] : nullptr; }
	int getInitializeResult() const { return this->m_initializeResult; }
	int getFinalizeResult() const { return this->m_finalizeResult; }
	int getMainResult() const { return this->m_mainResult; }
	operator int() const { return this->m_mainResult; }//�L���X�g���Z�q�I�[�o�[���[�h

public:
	//����������
	int initialize();
	
	//�I������
	int finalize();

	//���C������
	int main();

#ifdef UNIT_TEST_ENABLED
	//���j�b�g�e�X�g���C������
	int unitTestMain();
#endif//UNIT_TEST_ENABLED

private:
	//���s���p�����[�^
	const int m_argc;
	const char** m_argv;
	
	//��������
	int m_initializeResult;
	int m_finalizeResult;
	int m_mainResult;
};

#endif//__GAME_MAIN_H__

// End of file
