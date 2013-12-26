#include <stdio.h>
#include <stdlib.h>

#include "game_main.h"

//�Q�[�����C���N���X

//�R���X�g���N�^
CGameMain::CGameMain(const int argc, const char* argv[]):
	m_argc(argc),
	m_argv(argv),
	m_initializeResult(EXIT_SUCCESS),
	m_finalizeResult(EXIT_SUCCESS),
	m_mainResult(EXIT_SUCCESS)
{
}

//�f�X�g���N�^
CGameMain::~CGameMain()
{
}

//����������
int CGameMain::initialize()
{
	printf("- CGameMain::initialize()...\n");
	this->m_initializeResult = EXIT_SUCCESS;
	return this->m_initializeResult;
}

//�I������
int CGameMain::finalize()
{
	printf("- CGameMain::finalize()...\n");
	this->m_finalizeResult = EXIT_SUCCESS;
	return this->m_finalizeResult;
}

//���C������
int CGameMain::main()
{
	printf("- CGameMain::main()...\n");
	this->m_mainResult = EXIT_SUCCESS;
	return this->m_mainResult;
}

#ifdef UNIT_TEST_ENABLED
//���j�b�g�e�X�g���C������
int CGameMain::unitTestMain()
{
	printf("- CGameMain::unitTestMain()...\n");

	//���j�b�g�e�X�g�������s
	UnitTest::CMain unit_test;
	this->m_mainResult = unit_test.runUnitTest();
	
	return this->m_mainResult;
}
#endif//UNIT_TEST_ENABLED

// End of file
