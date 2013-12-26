#include <stdio.h>

#include "unit_test.h"

#ifdef UNIT_TEST_ENABLED

namespace UnitTest
{
	static const int UNIT_TEST_FUNC_LIST_NUM_MAX = 1024;

	int CMain::m_funcListNum = 0;
	CMain::T_UNIT_TEST_FUNC_INFO CMain::m_funcList[UNIT_TEST_FUNC_LIST_NUM_MAX];

	//ユニットテストメインクラス

	//コンストラクタ
	CMain::CMain()
	{
	}

	//デストラクタ
	CMain::~CMain()
	{
	}

	//ユニットテスト登録
	bool CMain::addFuncInfo(T_UNIT_TEST_FUNC func, const bool is_especially)
	{
		if (m_funcListNum >= UNIT_TEST_FUNC_LIST_NUM_MAX)
		{
			return false;
		}
		T_UNIT_TEST_FUNC_INFO* info = &m_funcList[m_funcListNum++];
		info->m_func = func;
		info->m_isEspecially = is_especially;
		return true;
	}

	//ユニットテスト結果表示
#if 0
	//for Unix
#define _COLOR_RESET() printf("\x1b[0m")
#define _COLOR_NORMAL() printf("\x1b[40m\x1b[37m")
#define _COLOR_OK() printf("\x1b[40m\x1b[34m")
#define _COLOR_NG() printf("\x1b[41m\x1b[37m")
#define _COLOR_EXPR() printf("\x1b[40m\x1b[32m")
#define _COLOR_OPE() printf("\x1b[40m\x1b[37m")
#define _COLOR_EXPECT() printf("\x1b[40m\x1b[32m")
#define _COLOR_VALUE() printf("\x1b[40m\x1b[32m")
#else
	//for Windows
#define _COLOR_RESET()
#define _COLOR_NORMAL()
#define _COLOR_OK()
#define _COLOR_NG()
#define _COLOR_EXPR()
#define _COLOR_OPE()
#define _COLOR_EXPECT()
#define _COLOR_VALUE()
#endif
	void CMain::printResult(const bool is_child, int* passed, int* missed, const bool result, const char* expr, const char* value, const char* ope, const char* expect)
	{
		_COLOR_RESET();
		_COLOR_NORMAL();
		bool print_expect = true;
		if (passed && missed && ope && expect)
		{
			print_expect = true;
			if (result)
			{
				++(*passed);
				_COLOR_OK();
				printf(" [OK] ");
			}
			else
			{
				++(*missed);
				_COLOR_NG();
				printf("*[NG!]");
			}
			_COLOR_NORMAL();
			printf(" <-- ");
		}
		else
		{
			print_expect = false;
			_COLOR_NORMAL();
			printf("      ");
			printf("     ");
		}
		if (is_child)
		{
			printf("    ");
		}
		if (expr)
		{
			_COLOR_EXPR();
			printf("%s", expr);
		}
		if (print_expect)
		{
			if (ope)
			{
				_COLOR_OPE();
				printf(" %s ", ope);
			}
			if (expect)
			{
				_COLOR_EXPECT();
				printf("%s", expect);
			}
		}
		if (value)
		{
			_COLOR_VALUE();
			printf(" (%s)", value);
		}
		_COLOR_RESET();
		printf("\n");
	}

	//ユニットテスト実行
	int CMain::runUnitTest(const bool especially_only)
	{
		int passed_total = 0;
		int missed_total = 0;
		_COLOR_NORMAL();
		printf("Unit Test: ");
		if (especially_only)
			printf("[Especially Only]");
		else
			printf("[All]");
		printf("\n");
		printf("============================================================\n");
		T_UNIT_TEST_FUNC_INFO* info = m_funcList;
		for (int i = 0; i < m_funcListNum; ++i, ++info)
		{
			if (!especially_only || (especially_only && info->m_isEspecially))
			{
				int passed = 0;
				int missed = 0;
				printf("\n");
				info->m_func(passed, missed);
				passed_total += passed;
				missed_total += missed;
			}
		}
		printf("\n");
		printf("============================================================\n");
		printf("Total(test=%d, passed=%d, missed=%d)\n", passed_total + missed_total, passed_total, missed_total);
		printf("\n");
		_COLOR_NORMAL();
		return missed_total;
	}
	int CMain::runUnitTestAll()
	{
		return runUnitTest(false);
	}
	int CMain::runUnitTestEspecially()
	{
		return runUnitTest(true);
	}
};

#endif//UNIT_TEST_ENABLED

// End of file
