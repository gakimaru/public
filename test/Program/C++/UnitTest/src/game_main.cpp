#include <stdio.h>
#include <stdlib.h>

#include "game_main.h"

//ゲームメインクラス

//コンストラクタ
CGameMain::CGameMain(const int argc, const char* argv[]):
	m_argc(argc),
	m_argv(argv),
	m_initializeResult(EXIT_SUCCESS),
	m_finalizeResult(EXIT_SUCCESS),
	m_mainResult(EXIT_SUCCESS)
{
}

//デストラクタ
CGameMain::~CGameMain()
{
}

//初期化処理
int CGameMain::initialize()
{
	printf("- CGameMain::initialize()...\n");
	this->m_initializeResult = EXIT_SUCCESS;
	return this->m_initializeResult;
}

//終了処理
int CGameMain::finalize()
{
	printf("- CGameMain::finalize()...\n");
	this->m_finalizeResult = EXIT_SUCCESS;
	return this->m_finalizeResult;
}

//メイン処理
int CGameMain::main()
{
	printf("- CGameMain::main()...\n");
	this->m_mainResult = EXIT_SUCCESS;
	return this->m_mainResult;
}

#ifdef UNIT_TEST_ENABLED
//ユニットテストメイン処理
int CGameMain::unitTestMain()
{
	printf("- CGameMain::unitTestMain()...\n");

	//ユニットテスト処理実行
	UnitTest::CMain unit_test;
	this->m_mainResult = unit_test.runUnitTest();
	
	return this->m_mainResult;
}
#endif//UNIT_TEST_ENABLED

// End of file
