#pragma once
#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

//プロジェクト設定の［C/C++］→［プリプロセッサ］→［プリプロセッサの定義］にて定義されるマクロ
//#define UT_ENABLED       ... ユニットテストの処理コードが有効になる。
//
//#define UT_AUTO          ... ユニットテストの自動実行を有効にする。
//                             ※main処理の冒頭で「UT_RUN_MAIN();」と記述しておく。
//                               以後の処理は実行せずに return する。この return 値を main 関数の戻り値にするように。
//                               メモリ管理などの基本的な初期化処理が終わった後で実行するように。
//#define UT_TARGET_MODULE ... UT_AUTO で自動実行時に、指定のモジュール名を対象に限定して実行する。省略した場合は全て対象。
//#define UT_TARGET_GROUP  ... UT_AUTO で自動実行時に、指定のグループIDを対象に限定して実行する。省略した場合は全て対象。
//
//※これらのマクロを使用せずとも、「UT_RUN_ALL();」「UT_RUN_MODULE();」「UT_RUN_GROUP();」のいずれかを直接呼び出せば、いつでもユニットテストを実行可能。
//　戻り値はテストにミスした数。これは常に 0 でなければならない。

#ifdef UT_ENABLED

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <string>
#include <sstream>
#include <exception>
#include <assert.h>

#ifndef ASSERT
#define ASSERT(expr) assert(expr)
#endif//ASSERT

namespace UnitTest
{
	//ユニットテストメインクラス
	class CCollection
	{
	private:
	//	explicit CUnitTestMain(){}
		explicit CCollection(CCollection&){}
	public:
		typedef int(*UNIT_TEST_FUNC_P)(int& passed, int& missed);
		typedef int(*UNIT_TEST_OUTPUT_FUNC_P)(const char* fmt, va_list list);
		struct UNIT_TEST_FUNC_INFO
		{
			CCollection::UNIT_TEST_FUNC_P m_func;
			const char* m_moduleName;
			int m_groupId;
			int passed;
			int missed;
		};
	public:
		//コンストラクタ
		explicit CCollection(){}
		//デストラクタ
		~CCollection(){}

	public:
		//アクセッサ
		static int getFuncInfoListNum();
		static const UNIT_TEST_FUNC_INFO* getFuncInfoListTop();
		static const UNIT_TEST_FUNC_INFO* getFuncInfo(const int index);
		static const UNIT_TEST_FUNC_INFO* getFuncInfo(const char* module_name);
		
		//前回の結果
		static int getLastPassedTotal();
		static int getLastMissedTotal();

	public:
		//前回の実行結果をリセット
		static void resetLastResult();

	public:
		//ユニットテスト実行
		static int runUnitTest(const char* target_module_name = nullptr, const int target_group_id = 0);
		static int runUnitTestStandard();

	public:
		//ユニットテスト登録
		static bool addFuncInfo(UNIT_TEST_FUNC_P func, const char* module_name, const int group_id);

		//ユニットテスト結果表示
		static void setOutputFunc(UNIT_TEST_OUTPUT_FUNC_P func);
		static int output(const char* fmt, ...);
		static void outputRunUTBegin(const char* target_module_name, const int target_group_id);
		static void outputRunUTEnd(const char* target_module_name, const int target_group_id, const int total_passed, const int total_missed);
		static void outputRunUTModuleBegin(const char* module_name, const int group_id);
		static void outputRunUTModuleEnd(const char* module_name, const int group_id, const int passed, const int missed);
		class CExprCResultObjBase
		{
		public:
			CExprCResultObjBase() : m_result(true), m_hasResult(false), m_hasException(false), m_hasExprStr(false), m_hasValueStr(false), m_hasOpeStr(false), m_hasExpectStr(false), m_exprStr(), m_valuieStr(), m_opeStr(), m_expectStr(), m_exceptionStr(){}
			~CExprCResultObjBase(){}

		public:
			void setResult(const bool result){ this->m_result = result; }
			bool getResult() const { return this->m_result; }
			void setHasResult(const bool has_result){ this->m_hasResult = has_result; }
			bool hasResult() const { return this->m_hasResult; }
			void setException(std::exception const& e){ this->m_hasException = true; this->m_exceptionStr = e.what(); }
			bool hasException() const { return this->m_hasException; }
			bool hasExprStr() const { return this->m_hasExprStr; }
			bool hasValueStr() const { return this->m_hasValueStr; }
			bool hasOpeStr() const { return this->m_hasOpeStr; }
			bool hasExpectStr() const { return this->m_hasExpectStr; }
			void setExprStr(const char* expr){ if (expr){ this->m_exprStr = expr; this->m_hasExprStr = true; } }
			const char* getExprStr() const { return m_exprStr.c_str(); }
			void setValueStr(const char* value){ if (value){ this->m_valuieStr = value; this->m_hasValueStr = true; } }
			const char* getValueStr() const { return m_valuieStr.c_str(); }
			void setOpeStr(const char* ope){ if (ope){ this->m_opeStr = ope; this->m_hasOpeStr = true; } }
			const char* getOpeStr() const { return this->m_opeStr.c_str(); }
			void setExpectStr(const char* expect){ if (expect){ this->m_expectStr = expect; this->m_hasExpectStr = true; } }
			const char* getExpectStr() const { return this->m_expectStr.c_str(); }
			const char* getExceptionStr() const { return this->m_exceptionStr.c_str(); }
			void setStrSet(const char* expr, const char* ope, const char* expect){ this->setExprStr(expr); this->setOpeStr(ope); this->setExpectStr(expect); }

		private:
			bool m_result;
			bool m_hasResult;
			bool m_hasException;
			bool m_hasExprStr;
			bool m_hasValueStr;
			bool m_hasOpeStr;
			bool m_hasExpectStr;
			std::string m_exprStr;
			std::string m_valuieStr;
			std::string m_opeStr;
			std::string m_expectStr;
			std::string m_exceptionStr;
		};
		template<typename T>
		class CExprCResultObj : public CExprCResultObjBase
		{
		public:
			CExprCResultObj(const T value, const char* ope, const T expect) : m_hasValue(false), m_hasExpect(false), m_value(0), m_expect(0), CExprCResultObjBase()
			{
				this->setValue(value);
				this->setOpeStr(ope);
				this->setExpect(expect);
				this->setResult(false);
				this->setHasResult(false);
				if (ope)
				{
					if (strcmp(ope, "==") == 0){ this->setResult(this->m_value == this->m_expect); this->setHasResult(true); }
					else if (strcmp(ope, "!=") == 0){ this->setResult(this->m_value != this->m_expect); this->setHasResult(true); }
					else if (strcmp(ope, "<") == 0){ this->setResult(this->m_value < this->m_expect); this->setHasResult(true); }
					else if (strcmp(ope, "<=") == 0){ this->setResult(this->m_value <= this->m_expect); this->setHasResult(true); }
					else if (strcmp(ope, ">") == 0){ this->setResult(this->m_value > this->m_expect); this->setHasResult(true); }
					else if (strcmp(ope, ">=") == 0){ this->setResult(this->m_value >= this->m_expect); this->setHasResult(true); }
				}
			}
			CExprCResultObj(const T value) : m_hasValue(false), m_hasExpect(false), m_value(0), m_expect(0), CExprCResultObjBase(){ this->setValue(value); }
			CExprCResultObj() : m_hasValue(false), m_hasExpect(false), m_value(0), m_expect(0), CExprCResultObjBase(){}
			~CExprCResultObj(){ this->~CExprCResultObjBase(); }

		public:
			void setValue(const T value){ this->m_value = value; this->m_hasValue = true; std::ostringstream os; os << value; this->setValueStr(os.str().c_str()); }
			T getValue() const { return this->m_value; }
			void setExpect(const T expect){ this->m_expect = expect; this->m_hasExpect = true; }
			T getExpect() const { return this->m_expectStr; }
		private:
			T m_value;
			T m_expect;
			bool m_hasValue;
			bool m_hasExpect;
		};
		template<typename T>
		static CExprCResultObj<T>* makeResultObj2(const T value, const char* ope, const T expect){ return new CExprCResultObj<T>(value, ope, expect); }
		template<typename T>
		static CExprCResultObj<T>* makeResultObj1(const T value){ return new CExprCResultObj<T>(value); }
		static CExprCResultObj<int>* makeResultObj0(){ return new CExprCResultObj<int>(); }
		static void outputUTResult(const bool is_child, int* passed, int* missed, CExprCResultObjBase* result_obj);
	};
}; //namespace UnitTest

#define UT_BEGIN(module_name, group_id) \
namespace __UnitTest_##module_name \
{ \
class __CUnitTestModle \
{ \
public: \
	__CUnitTestModle() \
	{ \
		UnitTest::CCollection::addFuncInfo(runUnitTest, #module_name, group_id); \
	} \
	~__CUnitTestModle() \
	{ \
	} \
public: \
	static int runUnitTest(int& __passed, int& __missed) \
	{ \
		const char* __module_name = #module_name; \
		const int __group_id = group_id; \
		__passed = 0; \
		__missed = 0; \
		UnitTest::CCollection::outputRunUTModuleBegin(__module_name, __group_id);
#define UT_END() \
		UnitTest::CCollection::outputRunUTModuleEnd(__module_name, __group_id, __passed, __missed); \
		return __missed; \
	} \
}; \
	static __CUnitTestModle __unit_test_obj; \
}; //namespace __UnitTest_##module_name
#define _UT_PRINT_EXPR_AND_RESULT(is_child, expr, ope, expect) { UnitTest::CCollection::CExprCResultObjBase* ___result_obj = nullptr; try { ___result_obj = UnitTest::CCollection::makeResultObj2(expr, #ope, expect); ___result_obj->setExprStr(#expr); ___result_obj->setExpectStr(#expect);                                 UnitTest::CCollection::outputUTResult(is_child, &__passed, &__missed, ___result_obj); } catch(std::exception const &e) { if(!___result_obj) ___result_obj = UnitTest::CCollection::makeResultObj0(); ___result_obj->setExprStr(#expr); ___result_obj->setOpeStr(#ope); ___result_obj->setExpectStr(#expect); ___result_obj->setResult(false); ___result_obj->setException(e); UnitTest::CCollection::outputUTResult(is_child, nullptr, &__missed, ___result_obj); } if(___result_obj){delete ___result_obj; } }
#define _UT_PRINT_EXPR_AND_VALUE(is_child, expr)               { UnitTest::CCollection::CExprCResultObjBase* ___result_obj = nullptr; try { ___result_obj = UnitTest::CCollection::makeResultObj1(expr);               ___result_obj->setExprStr(#expr);                                       ___result_obj->setResult(true); UnitTest::CCollection::outputUTResult(is_child, nullptr,   nullptr,   ___result_obj); } catch(std::exception const &e) { if(!___result_obj) ___result_obj = UnitTest::CCollection::makeResultObj0();                                                                                                         ___result_obj->setResult(false); ___result_obj->setException(e); UnitTest::CCollection::outputUTResult(is_child, nullptr, &__missed, ___result_obj); } if(___result_obj){delete ___result_obj; } }
#define _UT_PRINT_EXPR(is_child, expr)                         { UnitTest::CCollection::CExprCResultObjBase* ___result_obj = nullptr; try { ___result_obj = UnitTest::CCollection::makeResultObj0();                   ___result_obj->setExprStr(#expr);                                       ___result_obj->setResult(true); UnitTest::CCollection::outputUTResult(is_child, nullptr,   nullptr,   ___result_obj); } catch(std::exception const &e) { if(!___result_obj) ___result_obj = UnitTest::CCollection::makeResultObj0();                                                                                                         ___result_obj->setResult(false); ___result_obj->setException(e); UnitTest::CCollection::outputUTResult(is_child, nullptr, &__missed, ___result_obj); } if(___result_obj){delete ___result_obj; } }

#define UT_EXPECT(expr, ope, expect)       _UT_PRINT_EXPR_AND_RESULT(false, expr, ope, expect);
#define UT_EXPECT_CHILD(expr, ope, expect) _UT_PRINT_EXPR_AND_RESULT(true,  expr, ope, expect);
#define UT_EXPR_WITH_RET(expr)             _UT_PRINT_EXPR_AND_VALUE(false, expr)
#define UT_EXPR_WITH_RET_CHILD(expr)       _UT_PRINT_EXPR_AND_VALUE(true,  expr)
#define UT_EXPR(expr)                      _UT_PRINT_EXPR(false, expr)
#define UT_EXPR_CHILD(expr)                _UT_PRINT_EXPR(true, expr)

#ifndef UT_TARGET_MODULE
#define UT_TARGET_MODULE nullptr
#endif//UT_TARGET_MODULE
#ifndef UT_TARGET_GROUP
#define UT_TARGET_GROUP 0
#endif//UT_TARGET_GROUP
#define UT_RUN_ALL() UnitTest::CCollection::runUnitTest()
#define UT_RUN_MODULE(module_name) UnitTest::CCollection::runUnitTest(module_name)
#define UT_RUN_GROUP(group_id) UnitTest::CCollection::runUnitTest(nullptr, group_id)
#define UT_RUN_STANDARD() UnitTest::CCollection::runUnitTestStandard()
#define UT_RETURN_WHEN_MISSED() {if(UnitTest::CCollection::getLastMissedTotal() > 0) return UnitTest::CCollection::getLastMissedTotal();}
#define UT_EXIT_WHEN_MISSED() {if(UnitTest::CCollection::getLastMissedTotal() > 0) exit(UnitTest::CCollection::getLastMissedTotal());}
#define UT_ABORT_WHEN_MISSED() {if(UnitTest::CCollection::getLastMissedTotal() > 0) abort();}
#define UT_ASSERT_WHEN_MISSED() ASSERT(UnitTest::CCollection::getLastMissedTotal() == 0)
#ifdef UT_AUTO
#define UT_RUN_MAIN() UnitTest::CCollection::runUnitTestStandard(); UT_RETURN_WHEN_MISSED()
#else//UT_AUTO
#define UT_RUN_MAIN()
#endif//UT_AUTO
#define UT_RESET_LAST_RESULT() UnitTest::CCollection::resetLastResult()
#define UT_LAST_PASSED_TOTAL() UnitTest::CCollection::getLastPassedTotal()
#define UT_LAST_MISSED_TOTAL() UnitTest::CCollection::getLastMissedTotal()
#define UT_SET_OUTPUT_FUNC(func) UnitTest::CCollection::setOutputFunc(func)
#define UT_OUTPUT(fmt, ...) UnitTest::CCollection::output(fmt, __VA_ARGS__)
#define UT_WITH_(statement) statement

#else//UT_ENABLED

#define UT_BEGIN(class_name, is_especially) \
namespace __UnitTest_##class_name \
{ \
	template<class T> \
	class __CUnitTestModle_dummy \
	{ \
	private: \
		void __dummy(T dummy) \
		{ \
			if (false) \
			{
#define UT_END() \
			} \
		} \
	}; \
}; //namespace __UnitTest_##module_name
#define UT_PRINT_RESULT(is_child, expr, value)
#define UT_PRINT_EXPR(is_child, expr)
#define UT_PRINT_EXPR_WITH_RET(is_child, expr)
#define UT_CLAC_AND_PRINT_RESULT(is_child, expr, value, ope, expect)
#define UT_EXPECT(expr, ope, expect)
#define UT_EXPECT_CHILD(expr, ope, expect)
#define UT_EXPR(expr)
#define UT_EXPR_CHILD(expr)
#define UT_EXPR_WITH_RET(expr)
#define UT_EXPR_WITH_RET_CHILD(expr)
#define UT_RUN_ALL()
#define UT_RUN_MODULE(module_name)
#define UT_RUN_GROUP(group_id)
#define UT_RUN_STANDARD()
#define UT_RETURN_WHEN_MISSED()
#define UT_EXIT_WHEN_MISSED()
#define UT_ABORT_WHEN_MISSED()
#define UT_ASSERT_WHEN_MISSED()
#define UT_RUN_MAIN()
#define UT_RESET_LAST_RESULT()
#define UT_LAST_PASSED_TOTAL() 0
#define UT_LAST_MISSED_TOTAL() 0
#define UT_SET_OUTPUT_FUNC(func)
#define UT_OUTPUT(fmt, ...)
#define UT_WITH_(statement)

#endif//UT_ENABLED

#endif//__UNIT_TEST_H__

// End of file
