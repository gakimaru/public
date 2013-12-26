#include "unit_test.h"

#ifdef UT_ENABLED

#include <stdio.h>

namespace UnitTest
{
	//ユニットテスト情報
	static const int UNIT_TEST_FUNC_LIST_NUM_MAX = 1024;
	static int s_funcListNum = 0;
	static CCollection::UNIT_TEST_FUNC_INFO s_funcList[UNIT_TEST_FUNC_LIST_NUM_MAX];
	static int s_lastPassedTotal = 0;
	static int s_lastMissedTotal = 0;
	static int outputFuncDefault(const char* fmt, va_list list)
	{
		return vfprintf(stdout, fmt, list);
	}
	static CCollection::UNIT_TEST_OUTPUT_FUNC_P s_outputFunc = outputFuncDefault;

	//ユニットテストメインクラス

	//ユニットテスト登録
	bool CCollection::addFuncInfo(UNIT_TEST_FUNC_P func, const char* module_name, const int group_id)
	{
		if (s_funcListNum >= UNIT_TEST_FUNC_LIST_NUM_MAX)
		{
			return false;
		}
		UNIT_TEST_FUNC_INFO* info = &s_funcList[s_funcListNum++];
		info->m_func = func;
		info->m_moduleName = module_name;
		info->m_groupId = group_id;
		info->passed = 0;
		info->missed = 0;
		return true;
	}

	//アクセッサ
	int CCollection::getFuncInfoListNum()
	{
		return s_funcListNum;
	}
	const CCollection::UNIT_TEST_FUNC_INFO* CCollection::getFuncInfoListTop()
	{
		return s_funcList;
	}
	const CCollection::UNIT_TEST_FUNC_INFO* CCollection::getFuncInfo(const int index)
	{
		return index >= 0 && index < s_funcListNum ? &s_funcList[index] : nullptr;
	}
	const CCollection::UNIT_TEST_FUNC_INFO* CCollection::getFuncInfo(const char* module_name)
	{
		UNIT_TEST_FUNC_INFO* info = s_funcList;
		for (int i = 0; i < s_funcListNum; ++i, ++info)
		{
			if (strcmp(module_name, info->m_moduleName) == 0)
			{
				return  &s_funcList[i];
			}
		}
		return nullptr;
	}
	int CCollection::getLastPassedTotal()
	{
		return s_lastPassedTotal;
	}
	int CCollection::getLastMissedTotal()
	{
		return s_lastMissedTotal;
	}
	
	//前回の実行結果をリセット
	void CCollection::resetLastResult()
	{
		s_lastPassedTotal = 0;
		s_lastMissedTotal = 0;
		UNIT_TEST_FUNC_INFO* info = s_funcList;
		for (int i = 0; i < s_funcListNum; ++i, ++info)
		{
			info->passed = 0;
			info->missed = 0;
		}
	}

	//ユニットテスト実行
	int CCollection::runUnitTest(const char* target_module_name, const int target_group_id)
	{
		int passed_total = 0;
		int missed_total = 0;
		outputRunUTBegin(target_module_name, target_group_id);
		UNIT_TEST_FUNC_INFO* info = s_funcList;
		for (int i = 0; i < s_funcListNum; ++i, ++info)
		{
			if ((target_module_name == nullptr || (target_module_name != nullptr && info->m_moduleName != nullptr && strcmp(target_module_name, info->m_moduleName) == 0)) &&
				(target_group_id == 0 || (target_group_id != 0 && target_group_id == info->m_groupId)))
			{
				int passed = 0;
				int missed = 0;
				info->m_func(passed, missed);
				passed_total += passed;
				missed_total += missed;
				info->passed = passed;
				info->missed = missed;
			}
		}
		s_lastPassedTotal = passed_total;
		s_lastMissedTotal = missed_total;
		outputRunUTEnd(target_module_name, target_group_id, passed_total, missed_total);
		return missed_total;
	}
	int CCollection::runUnitTestStandard()
	{
		return runUnitTest(UT_TARGET_MODULE, UT_TARGET_GROUP);
	}

	//ユニットテスト結果表示
#if 0
	//for Unix
#define _COLOR_RESET() output("\x1b[0m")
#define _COLOR_NORMAL() output("\x1b[40m\x1b[37m")
#define _COLOR_OK() output("\x1b[40m\x1b[34m")
#define _COLOR_NG() output("\x1b[41m\x1b[37m")
#define _COLOR_EXPR() output("\x1b[40m\x1b[32m")
#define _COLOR_OPE() output("\x1b[40m\x1b[37m")
#define _COLOR_EXPECT() output("\x1b[40m\x1b[32m")
#define _COLOR_VALUE() output("\x1b[40m\x1b[32m")
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
	void CCollection::setOutputFunc(UNIT_TEST_OUTPUT_FUNC_P func)
	{
		s_outputFunc = func;
	}
	int CCollection::output(const char* fmt, ...)
	{
		if (!s_outputFunc)
			return 0;
		va_list list;
		va_start(list, fmt);
		const int ret = s_outputFunc(fmt, list);
		va_end(list);
		return ret;
	}
	void CCollection::outputRunUTBegin(const char* target_module_name, const int target_group_id)
	{
		_COLOR_NORMAL();
		output("\n");
		output("Start unit test: ");
		if (target_module_name)
		{
			output("[Target module=\"%s\"]", target_module_name);
		}
		if (target_group_id != 0)
		{
			output("[Target group=%d]", target_group_id);
		}
		if (!target_module_name && target_group_id == 0)
		{
			output("[Target=All]");
		}
		output("\n");
		output("============================================================\n");
	}
	void CCollection::outputRunUTEnd(const char* target_module_name, const int target_group_id, const int passed_total, const int missed_total)
	{
		output("\n");
		output("============================================================\n");
		output("Finish unit test: Total [test=%d, passed=%d, missed=%d]\n", passed_total + missed_total, passed_total, missed_total);
		output("\n");
		_COLOR_NORMAL();
	}
	void CCollection::outputRunUTModuleBegin(const char* module_name, const int group_id)
	{
		output("\n");
		output("----- Start unit test module: \"%s\" (Group=%d) -----\n", module_name, group_id);
	}
	void CCollection::outputRunUTModuleEnd(const char* module_name, const int group_id, const int passed, const int missed)
	{
		output("----- Finish unit test module: [test=%d, passed=%d, missed=%d] -----\n", passed + missed, passed, missed);
	}
	void CCollection::outputUTResult(const bool is_child, int* passed, int* missed, const bool result, const char* expr, const char* value, const char* ope, const char* expect)
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
				output(" [OK] ");
			}
			else
			{
				++(*missed);
				_COLOR_NG();
				output("*[NG!]");
			}
			_COLOR_NORMAL();
			output(" <-- ");
		}
		else
		{
			print_expect = false;
			_COLOR_NORMAL();
			output("      ");
			output("     ");
		}
		if (is_child)
		{
			output("    ");
		}
		if (expr)
		{
			_COLOR_EXPR();
			output("%s", expr);
		}
		if (print_expect)
		{
			if (ope)
			{
				_COLOR_OPE();
				output(" %s ", ope);
			}
			if (expect)
			{
				_COLOR_EXPECT();
				output("%s", expect);
			}
		}
		if (value)
		{
			_COLOR_VALUE();
			output(" (%s)", value);
		}
		_COLOR_RESET();
		output("\n");
	}
};

#endif//UT_ENABLED

// End of file
