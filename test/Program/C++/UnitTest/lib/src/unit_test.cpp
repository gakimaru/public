#include "unit_test.h"

#ifdef UT_ENABLED

#include <stdio.h>

#include <windows.h>
#include <conio.h>

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
	bool CCollection::addFuncInfo(UNIT_TEST_FUNC_P func, const char* module_name, const int group_id, const T_UT_ATTR attr)
	{
		if (s_funcListNum >= UNIT_TEST_FUNC_LIST_NUM_MAX)
		{
			return false;
		}
		UNIT_TEST_FUNC_INFO* info = &s_funcList[s_funcListNum++];
		info->m_func = func;
		info->m_moduleName = module_name;
		info->m_groupId = group_id;
		info->m_attr = attr;
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
	int CCollection::runUnitTest(const char* target_module_name, const int target_group_id, const T_UT_ATTR target_attr)
	{
		int passed_total = 0;
		int missed_total = 0;
		outputRunUTBegin(target_module_name, target_group_id, target_attr);
		UNIT_TEST_FUNC_INFO* info = s_funcList;
		for (int i = 0; i < s_funcListNum; ++i, ++info)
		{
			if ((target_module_name == nullptr || (target_module_name != nullptr && info->m_moduleName != nullptr && strcmp(target_module_name, info->m_moduleName) == 0)) &&
				(target_group_id == 0 || (target_group_id != 0 && target_group_id == info->m_groupId)) &&
				(target_attr == UT_ATTR_ANY || (target_attr != UT_ATTR_ANY && (target_attr & info->m_attr) != UT_ATTR_NONE)))
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
		outputRunUTEnd(target_module_name, target_group_id, target_attr, passed_total, missed_total);
		return missed_total;
	}
	int CCollection::runUnitTestStandard(const T_UT_ATTR target_attr)
	{
		return runUnitTest(UT_TARGET_MODULE, UT_TARGET_GROUP, target_attr);
	}

	//ユニットテスト結果表示
#if 0
	//for Unix
	#define _COLOR_BEGIN()
	#define _COLOR_RESET() output("\x1b[0m")
	#define _COLOR_NORMAL() output("\x1b[40m\x1b[37m")
	#define _COLOR_OK() output("\x1b[40m\x1b[34m")
	#define _COLOR_NG() output("\x1b[41m\x1b[37m")
	#define _COLOR_UNKNOWN() output("\x1b[44m\x1b[31m")
	#define _COLOR_EXPR() output("\x1b[40m\x1b[32m")
	#define _COLOR_OPE() output("\x1b[40m\x1b[37m")
	#define _COLOR_EXPECT() output("\x1b[40m\x1b[32m")
	#define _COLOR_VALUE() output("\x1b[40m\x1b[32m")
	#define _COLOR_EXCEPTION() output("\x1b[41m\x1b[37m")
	#define _COLOR_END()
#else
	//for Windows
	CONSOLE_SCREEN_BUFFER_INFO _csb_info_backuped;
	HANDLE 	_hStdout = INVALID_HANDLE_VALUE;
	#define _COLOR_BEGIN(){_hStdout = GetStdHandle(STD_OUTPUT_HANDLE); GetConsoleScreenBufferInfo(_hStdout, &_csb_info_backuped);}
	#define _COLOR_RESET(){SetConsoleTextAttribute(_hStdout, _csb_info_backuped.wAttributes);}
	#define _COLOR_NORMAL(){SetConsoleTextAttribute(_hStdout, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);}
	#define _COLOR_OK(){SetConsoleTextAttribute(_hStdout, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);}
	#define _COLOR_NG(){SetConsoleTextAttribute(_hStdout, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_INTENSITY);}
	#define _COLOR_UNKOWN(){SetConsoleTextAttribute(_hStdout, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);}
	#define _COLOR_EXPR(){SetConsoleTextAttribute(_hStdout, FOREGROUND_GREEN|FOREGROUND_INTENSITY);}
	#define _COLOR_OPE(){SetConsoleTextAttribute(_hStdout, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);}
	#define _COLOR_EXPECT(){SetConsoleTextAttribute(_hStdout, FOREGROUND_GREEN|FOREGROUND_INTENSITY);}
	#define _COLOR_VALUE(){SetConsoleTextAttribute(_hStdout, FOREGROUND_GREEN|FOREGROUND_INTENSITY);}
	#define _COLOR_EXCEPTION(){SetConsoleTextAttribute(_hStdout, BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);}
	#define _COLOR_END(){SetConsoleTextAttribute(_hStdout, _csb_info_backuped.wAttributes); _hStdout = INVALID_HANDLE_VALUE;}
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
	void CCollection::outputRunUTBegin(const char* target_module_name, const int target_group_id, const UnitTest::T_UT_ATTR target_attr)
	{
		_COLOR_BEGIN();
		_COLOR_RESET();
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
		if (target_attr != UT_ATTR_ANY)
		{
			output("[Attr=0x%08x]", target_attr);
		}
		else
		{
			output("[Attr=ANY]");
		}
		output("\n");
		output("============================================================\n");
		_COLOR_END();
	}
	void CCollection::outputRunUTEnd(const char* target_module_name, const int target_group_id, const UnitTest::T_UT_ATTR target_attr, const int passed_total, const int missed_total)
	{
		_COLOR_BEGIN();
		_COLOR_RESET();
		_COLOR_NORMAL();
		output("\n");
		output("============================================================\n");
		output("Finish unit test: Total [test=%d, passed=", passed_total + missed_total);
		if (passed_total > 0)
		{
			_COLOR_OK();
			output("%d", passed_total);
		}
		else
		{
			_COLOR_NORMAL();
			output("%d", passed_total);
		}
		_COLOR_NORMAL();
		output(", missed=");
		if (missed_total > 0)
		{
			_COLOR_NG();
			output("%d", missed_total);
		}
		else
		{
			_COLOR_NORMAL();
			output("%d", missed_total);
		}
		_COLOR_NORMAL();
		output("] -----\n");
		output("\n");
		_COLOR_END();
	}
	void CCollection::outputRunUTModuleBegin(const char* module_name, const int group_id, const UnitTest::T_UT_ATTR attr)
	{
		_COLOR_BEGIN();
		_COLOR_RESET();
		_COLOR_NORMAL();
		output("\n");
		output("----- Start unit test module: \"%s\" (Group=%d,Attr=0x%08x) -----\n", module_name, group_id, attr);
		_COLOR_END();
	}
	void CCollection::outputRunUTModuleEnd(const char* module_name, const int group_id, const UnitTest::T_UT_ATTR attr, const int passed, const int missed)
	{
		_COLOR_BEGIN();
		_COLOR_RESET();
		_COLOR_NORMAL();
		output("----- Finish unit test module: [test=%d, passed=", passed + missed);
		if (passed > 0)
		{
			_COLOR_OK();
			output("%d", passed);
		}
		else
		{
			_COLOR_NORMAL();
			output("%d", passed);
		}
		_COLOR_NORMAL();
		output(", missed=");
		if (missed > 0)
		{
			_COLOR_NG();
			output("%d", missed);
		}
		else
		{
			_COLOR_NORMAL();
			output("%d", missed);
		}
		_COLOR_NORMAL();
		output("] -----\n");
		_COLOR_END();
	}
	void CCollection::outputUTResult(const bool is_child, int* passed, int* missed, CExprCResultObjBase* result_obj)
	{
		_COLOR_BEGIN();
		_COLOR_RESET();
		_COLOR_NORMAL();
		bool is_count_passed = false;
		bool is_count_missed = false;
		if (result_obj->hasOpeStr() && result_obj->hasExpectStr())
		{
			if (result_obj->hasResult())
			{
				if (result_obj->getResult())
				{
					is_count_passed = true;
					_COLOR_NORMAL();
					output(" ");
					_COLOR_OK();
					output("[OK]");
					_COLOR_NORMAL();
					output(" ");
				}
				else
				{
					is_count_missed = true;
					_COLOR_NG();
					output("*[NG!]");
				}
			}
			else
			{
				is_count_missed = true;
				_COLOR_UNKOWN();
				output("*[??]");
				_COLOR_NORMAL();
				output(" ");
			}
			_COLOR_NORMAL();
			output(" <-- ");
		}
		else
		{
			_COLOR_NORMAL();
			output("      ");
			output("     ");
		}
		if (is_child)
		{
			_COLOR_NORMAL();
			output("    ");
		}
		if (result_obj->hasExprStr())
		{
			_COLOR_EXPR();
			output("%s", result_obj->getExprStr());
		}
		if (result_obj->hasOpeStr())
		{
			_COLOR_NORMAL();
			output(" ");
			_COLOR_OPE();
			output("%s", result_obj->getOpeStr());
			_COLOR_NORMAL();
			output(" ");
		}
		if (result_obj->hasExpectStr())
		{
			_COLOR_EXPECT();
			output("%s", result_obj->getExpectStr());
		}
		if (result_obj->hasValueStr())
		{
			_COLOR_NORMAL();
			output(" (ret=");
			_COLOR_VALUE();
			output("%s", result_obj->getValueStr());
			_COLOR_NORMAL();
			output(")");
		}
		if (result_obj->hasException())
		{
			is_count_missed = true;
			_COLOR_NORMAL();
			output(" ");
			_COLOR_EXCEPTION();
			output("<EXCEPTION!!");
			const char* msg = result_obj->getExceptionStr();
			if (msg)
			{
				output(":%s", msg);
			}
			output(">");
		}
		_COLOR_RESET();
		output("\n");
		_COLOR_END();
		
		if (is_count_passed && passed)
		{
			++(*passed);
		}
		if (is_count_missed && missed)
		{
			++(*missed);
		}
	}
};

#endif//UT_ENABLED

// End of file
