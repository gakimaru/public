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
	class CCollection;
	class CElapsedTime;
	
	//ユニットテスト実行属性
	typedef unsigned int T_UT_ATTR;
	enum E_UT_ATTR
	{
		UT_ATTR_NONE = 0x00000000, //属性無し
		UT_ATTR_ANY = 0xffffffff,  //全て
		UT_ATTR_AUTO = 0x00000001, //自動実行用
		UT_ATTR_NOAUTO = 0x00000002, //非自動実行用
	};
	
	//ユニットテスト比較演算子指定用定数
	enum E_UT_OPE
	{
		UT_OPE_UNKNOWN = 0, //??
		UT_OPE_EQ, //== 
		UT_OPE_NE, //!=
		UT_OPE_GT, //>
		UT_OPE_GE, //>=
		UT_OPE_LT, //<
		UT_OPE_LE, //<=
		UT_OPE_NUM,
	};
	struct T_UT_OPE_UNKNOWN_DUMMY{};
	struct T_UT_OPE_EQ_DUMMY{};
	struct T_UT_OPE_NE_DUMMY{};
	struct T_UT_OPE_GT_DUMMY{};
	struct T_UT_OPE_GE_DUMMY{};
	struct T_UT_OPE_LT_DUMMY{};
	struct T_UT_OPE_LE_DUMMY{};

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
			T_UT_ATTR m_attr;
			int passed;
			int missed;
			double elapsed_time;
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
		static int runUnitTest(const char* target_module_name = nullptr, const int target_group_id = 0, const T_UT_ATTR target_attr = UT_ATTR_ANY);
		static int runUnitTestStandard(const T_UT_ATTR target_attr = UT_ATTR_ANY);

	public:
		//ユニットテスト登録
		static bool addFuncInfo(UNIT_TEST_FUNC_P func, const char* module_name, const int group_id, const T_UT_ATTR attr);

		//ユニットテスト結果表示
		static void setOutputFunc(UNIT_TEST_OUTPUT_FUNC_P func);
		static int output(const char* fmt, ...);
		static void outputRunUTBegin(const char* target_module_name, const int target_group_id, const T_UT_ATTR target_attr);
		static void outputRunUTEnd(const char* target_module_name, const int target_group_id, const T_UT_ATTR target_attr, const int total_passed, const int total_missed, const double elapsed_time);
		static void outputRunUTModuleBegin(const char* module_name, const int group_id, const T_UT_ATTR attr);
		static void outputRunUTModuleEnd(const char* module_name, const int group_id, const T_UT_ATTR attr, const int passed, const int missed, const double elapsed_time);
		
		//ユニットテスト結果格納クラス
		class CExprCResultObjBase
		{
		public:
			CExprCResultObjBase();
			~CExprCResultObjBase();

		public:
			void setResult(const bool result){ this->m_result = result; }
			bool getResult() const { return this->m_result; }
			void setHasResult(const bool has_result){ this->m_hasResult = has_result; }
			bool hasResult() const { return this->m_hasResult; }
			void setException(std::exception const& e);
			bool hasException() const { return this->m_hasException; }
			bool hasExprStr() const { return this->m_hasExprStr; }
			bool hasValueStr() const { return this->m_hasValueStr; }
			bool hasOpeStr() const { return this->m_hasOpeStr; }
			bool hasExpectStr() const { return this->m_hasExpectStr; }
			void setExprStr(const char* expr);
			const char* getExprStr() const { return m_exprStr.c_str(); }
			void setValueStr(const char* value);
			const char* getValueStr() const { return m_valuieStr.c_str(); }
			void setOpeStr(const char* ope);
			const char* setOpeStrFromId(const E_UT_OPE ope);
			const char* getOpeStr() const { return this->m_opeStr.c_str(); }
			void setExpectStr(const char* expect);
			const char* getExpectStr() const { return this->m_expectStr.c_str(); }
			const char* getExceptionStr() const { return this->m_exceptionStr.c_str(); }

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
			CExprCResultObj(const T value, const T expect) :
				m_hasValue(true),
				m_hasExpect(true),
				m_value(value),
				m_expect(expect),
				CExprCResultObjBase()
			{
			}
			CExprCResultObj(const T value) :
				m_hasValue(false),
				m_hasExpect(false),
				m_value(0),
				m_expect(0), CExprCResultObjBase()
			{
				this->setValue(value);
			}
			CExprCResultObj() : 
				m_hasValue(false), 
				m_hasExpect(false), 
				m_value(0),
				m_expect(0),
				CExprCResultObjBase()
			{
			}
			~CExprCResultObj()
			{
				this->~CExprCResultObjBase(); 
			}

		public:
			void setValue(const T value)
			{
				this->m_value = value;
				this->m_hasValue = true;
				std::ostringstream os;
				os << value;
				this->setValueStr(os.str().c_str());
			}
			T getValue() const { return this->m_value; }
			void setExpect(const T expect)
			{
				this->m_expect = expect;
				this->m_hasExpect = true;
			}
			T getExpect() const { return this->m_expectStr; }
			
		public:
			void setOpeStrFromType(T_UT_OPE_UNKNOWN_DUMMY ope)
			{
				this->setOpeStrFromId(UT_OPE_UNKNOWN);
			}
			void setOpeStrFromType(T_UT_OPE_EQ_DUMMY ope)
			{
				this->setOpeStrFromId(UT_OPE_EQ);
			}
			void setOpeStrFromType(T_UT_OPE_NE_DUMMY ope)
			{
				this->setOpeStrFromId(UT_OPE_NE);
			}
			void setOpeStrFromType(T_UT_OPE_GT_DUMMY ope)
			{
				this->setOpeStrFromId(UT_OPE_GT);
			}
			void setOpeStrFromType(T_UT_OPE_GE_DUMMY ope)
			{
				this->setOpeStrFromId(UT_OPE_GE);
			}
			void setOpeStrFromType(T_UT_OPE_LT_DUMMY ope)
			{
				this->setOpeStrFromId(UT_OPE_LT);
			}
			void setOpeStrFromType(T_UT_OPE_LE_DUMMY ope)
			{
				this->setOpeStrFromId(UT_OPE_LE);
			}
			void calcResult(T_UT_OPE_UNKNOWN_DUMMY ope)
			{
				this->setOpeStrFromType(ope);
				obj.setResult(false);
				obj.setHasResult(false);
			}
			void calcResult(T_UT_OPE_EQ_DUMMY ope)
			{
				this->setOpeStrFromType(ope);
				this->setResult(this->m_value == this->m_expect);
				this->setHasResult(true);
			}
			void calcResult(T_UT_OPE_NE_DUMMY ope)
			{
				this->setOpeStrFromType(ope);
				this->setResult(this->m_value != this->m_expect);
				this->setHasResult(true);
			}
			void calcResult(T_UT_OPE_GT_DUMMY ope)
			{
				this->setOpeStrFromType(ope);
				this->setResult(this->m_value > this->m_expect);
				this->setHasResult(true);
			}
			void calcResult(T_UT_OPE_GE_DUMMY ope)
			{
				this->setOpeStrFromType(ope);
				this->setResult(this->m_value >= this->m_expect);
				this->setHasResult(true);
			}
			void calcResult(T_UT_OPE_LT_DUMMY ope)
			{
				this->setOpeStrFromType(ope);
				this->setResult(this->m_value < this->m_expect);
				this->setHasResult(true);
			}
			void calcResult(T_UT_OPE_LE_DUMMY ope)
			{
				this->setOpeStrFromType(ope);
				this->setResult(this->m_value <= this->m_expect);
				this->setHasResult(true);
			}
		
		private:
			T m_value;
			T m_expect;
			bool m_hasValue;
			bool m_hasExpect;
		};
		template<typename T, typename OPE>
		static CExprCResultObj<T>* makeResultObj2(const T value, typename T expect, OPE ope, const char* expr_str, const char* expect_str)
		{
			CExprCResultObj<T>* obj = new CExprCResultObj<T>(value, expect);
			obj->setValue(value);
			obj->setExpect(expect);
			obj->setExprStr(expr_str);
			obj->setExpectStr(expect_str);
			obj->calcResult(ope);
			return obj;
		}
		template<typename OPE>
		static CExprCResultObj<int>* makeResultObj2ex(OPE ope, const char* expr_str, const char* expect_str)
		{
			CExprCResultObj<int>* obj = new CExprCResultObj<int>();
			obj->setExprStr(expr_str);
			obj->setExpectStr(expect_str);
			obj->setOpeStrFromType(ope);
			obj->setResult(false);
			obj->setHasResult(false);
			return obj;
		}
		template<typename T>
		static CExprCResultObj<T>* makeResultObj1(const T value, const char* expr_str)
		{
			CExprCResultObj<T>* obj = new CExprCResultObj<T>(value);
			obj->setExprStr(expr_str);
			obj->setResult(false);
			obj->setHasResult(false);
			return obj;
		}
		static CExprCResultObj<int>* makeResultObj1ex(const char* expr_str)
		{
			CExprCResultObj<int>* obj = new CExprCResultObj<int>();
			obj->setExprStr(expr_str);
			obj->setResult(false);
			obj->setHasResult(false);
			return obj;
		}
		static void outputUTResult(const bool is_child, int* passed, int* missed, CElapsedTime* elapsed_time, CExprCResultObjBase* result_obj);
	};
	
	//処理時間計測
	class CElapsedTime
	{
	public:
		typedef double TIMERCOUNT;
	public:
		CElapsedTime();
		~CElapsedTime();
	public:
		TIMERCOUNT getBeginTime() const { return this->m_beginTime; }
		TIMERCOUNT getEndTime() const { return this->m_endTime; }
		TIMERCOUNT getElapsedTime() const { return this->m_elapsedTime; }
		double getResult() const { return static_cast<double>(this->m_elapsedTime); }
	public:
		TIMERCOUNT finish();
	private:
		TIMERCOUNT getTimer();
	private:
		TIMERCOUNT m_beginTime;
		TIMERCOUNT m_endTime;
		TIMERCOUNT m_elapsedTime;
	};
}; //namespace UnitTest

#define UT_BEGIN(module_name, group_id, attr) \
namespace __UnitTest_module_##module_name##__ \
{ \
	class __CUnitTestModle \
	{ \
	public: \
	__CUnitTestModle() \
		{ \
			UnitTest::CCollection::addFuncInfo(runUnitTest, #module_name, group_id, attr); \
		} \
	~__CUnitTestModle() \
		{ \
		} \
	public: \
		static int runUnitTest(int& __passed, int& __missed) \
		{ \
			const char* __module_name = #module_name; \
			const int __group_id = group_id; \
			UnitTest::CElapsedTime __elapsed_time; \
			const UnitTest::T_UT_ATTR __attr = attr; \
			__passed = 0; \
			__missed = 0; \
			UnitTest::CCollection::outputRunUTModuleBegin(__module_name, __group_id, __attr);
#define UT_END() \
			__elapsed_time.finish(); \
			UnitTest::CCollection::outputRunUTModuleEnd(__module_name, __group_id, __attr, __passed, __missed, __elapsed_time.getResult()); \
			return __missed; \
		} \
	}; \
	static __CUnitTestModle __unit_test_obj; \
}; //namespace __UnitTest_##module_name
#define _UT_PRINT_EXPR_AND_RESULT(is_child, expr, ope, expect) { UnitTest::CCollection::CExprCResultObjBase* ___result_obj = nullptr; try { UnitTest::CElapsedTime ___elapsed_time; ___result_obj = UnitTest::CCollection::makeResultObj2(expr, expect, ope, #expr, #expect); ___elapsed_time.finish();                                 UnitTest::CCollection::outputUTResult(is_child, &__passed, &__missed, &___elapsed_time, ___result_obj); } catch(std::exception const &e) { if(!___result_obj) ___result_obj = UnitTest::CCollection::makeResultObj2ex(ope, #expr, #expect); ___result_obj->setException(e); UnitTest::CCollection::outputUTResult(is_child, nullptr, &__missed, nullptr, ___result_obj); } if(___result_obj){delete ___result_obj; } }
#define _UT_PRINT_EXPR_AND_VALUE(is_child, expr)               { UnitTest::CCollection::CExprCResultObjBase* ___result_obj = nullptr; try { UnitTest::CElapsedTime ___elapsed_time; ___result_obj = UnitTest::CCollection::makeResultObj1(expr,              #expr);          ___elapsed_time.finish(); ___result_obj->setResult(true); UnitTest::CCollection::outputUTResult(is_child, nullptr,   nullptr,   &___elapsed_time, ___result_obj); } catch(std::exception const &e) { if(!___result_obj) ___result_obj = UnitTest::CCollection::makeResultObj1ex(     #expr);          ___result_obj->setException(e); UnitTest::CCollection::outputUTResult(is_child, nullptr, &__missed, nullptr, ___result_obj); } if(___result_obj){delete ___result_obj; } }
#define _UT_PRINT_EXPR(is_child, expr)                         { UnitTest::CCollection::CExprCResultObjBase* ___result_obj = nullptr; try {                                         ___result_obj = UnitTest::CCollection::makeResultObj1ex(                 #expr);                                    ___result_obj->setResult(true); UnitTest::CCollection::outputUTResult(is_child, nullptr,   nullptr,   nullptr,          ___result_obj); } catch(std::exception const &e) { if(!___result_obj) ___result_obj = UnitTest::CCollection::makeResultObj1ex(     #expr);          ___result_obj->setException(e); UnitTest::CCollection::outputUTResult(is_child, nullptr, &__missed, nullptr, ___result_obj); } if(___result_obj){delete ___result_obj; } }

#define UT_EXPECT(expr, ope, expect)       _UT_PRINT_EXPR_AND_RESULT(false, expr, ope, expect);
#define UT_EXPECT_CHILD(expr, ope, expect) _UT_PRINT_EXPR_AND_RESULT(true,  expr, ope, expect);
#define UT_EXPR_WITH_RET(expr)             _UT_PRINT_EXPR_AND_VALUE(false, expr)
#define UT_EXPR_WITH_RET_CHILD(expr)       _UT_PRINT_EXPR_AND_VALUE(true,  expr)
#define UT_EXPR(expr)                      _UT_PRINT_EXPR(false, expr)
#define UT_EXPR_CHILD(expr)                _UT_PRINT_EXPR(true, expr)

#define UT_EXPECT_EQ(expr, expect)       UT_EXPECT(expr, UnitTest::T_UT_OPE_EQ_DUMMY(), expect)
#define UT_EXPECT_NE(expr, expect)       UT_EXPECT(expr, UnitTest::T_UT_OPE_NE_DUMMY(), expect)
#define UT_EXPECT_GT(expr, expect)       UT_EXPECT(expr, UnitTest::T_UT_OPE_GT_DUMMY(), expect)
#define UT_EXPECT_GE(expr, expect)       UT_EXPECT(expr, UnitTest::T_UT_OPE_GE_DUMMY(), expect)
#define UT_EXPECT_LT(expr, expect)       UT_EXPECT(expr, UnitTest::T_UT_OPE_LT_DUMMY(), expect)
#define UT_EXPECT_LE(expr, expect)       UT_EXPECT(expr, UnitTest::T_UT_OPE_LE_DUMMY(), expect)
#define UT_EXPECT_EQ_CHILD(expr, expect) UT_EXPECT_CHILD(expr, UnitTest::T_UT_OPE_EQ_DUMMY(), expect);
#define UT_EXPECT_NE_CHILD(expr, expect) UT_EXPECT_CHILD(expr, UnitTest::T_UT_OPE_NE_DUMMY(), expect);
#define UT_EXPECT_GT_CHILD(expr, expect) UT_EXPECT_CHILD(expr, UnitTest::T_UT_OPE_GT_DUMMY(), expect);
#define UT_EXPECT_GE_CHILD(expr, expect) UT_EXPECT_CHILD(expr, UnitTest::T_UT_OPE_GE_DUMMY(), expect);
#define UT_EXPECT_LT_CHILD(expr, expect) UT_EXPECT_CHILD(expr, UnitTest::T_UT_OPE_LT_DUMMY(), expect);
#define UT_EXPECT_LE_CHILD(expr, expect) UT_EXPECT_CHILD(expr, UnitTest::T_UT_OPE_LE_DUMMY(), expect);

#ifndef UT_TARGET_MODULE
#define UT_TARGET_MODULE nullptr
#endif//UT_TARGET_MODULE
#ifndef UT_TARGET_GROUP
#define UT_TARGET_GROUP 0
#endif//UT_TARGET_GROUP
#define UT_RUN_ALL(attr) UnitTest::CCollection::runUnitTest(nullptr, 0, attr)
#define UT_RUN_MODULE(module_name, attr) UnitTest::CCollection::runUnitTest(module_name, 0, attr)
#define UT_RUN_GROUP(group_id, attr) UnitTest::CCollection::runUnitTest(nullptr, group_id, attr)
#define UT_RUN_STANDARD(attr) UnitTest::CCollection::runUnitTestStandard(attr)
#define UT_RETURN_WHEN_MISSED() {if(UnitTest::CCollection::getLastMissedTotal() > 0) return UnitTest::CCollection::getLastMissedTotal();}
#define UT_EXIT_WHEN_MISSED() {if(UnitTest::CCollection::getLastMissedTotal() > 0) exit(UnitTest::CCollection::getLastMissedTotal());}
#define UT_ABORT_WHEN_MISSED() {if(UnitTest::CCollection::getLastMissedTotal() > 0) abort();}
#define UT_ASSERT_WHEN_MISSED() ASSERT(UnitTest::CCollection::getLastMissedTotal() == 0)
#ifdef UT_AUTO
#define UT_RUN_MAIN(result_var) UnitTest::CCollection::runUnitTestStandard(UnitTest::UT_ATTR_AUTO); result_var = UnitTest::CCollection::getLastMissedTotal(); UT_RETURN_WHEN_MISSED()
#else//UT_AUTO
#define UT_RUN_MAIN(result_var)
#endif//UT_AUTO
#define UT_RESET_LAST_RESULT() UnitTest::CCollection::resetLastResult()
#define UT_LAST_PASSED_TOTAL() UnitTest::CCollection::getLastPassedTotal()
#define UT_LAST_MISSED_TOTAL() UnitTest::CCollection::getLastMissedTotal()
#define UT_SET_OUTPUT_FUNC(func) UnitTest::CCollection::setOutputFunc(func)
#define UT_OUTPUT(fmt, ...) UnitTest::CCollection::output(fmt, __VA_ARGS__)
#define UT_WITH_(statement) statement

#else//UT_ENABLED

#define UT_BEGIN(module_name, group_id, attr) \
namespace __UnitTest_module_##module_name##__ \
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
#define UT_EXPECT_EQ(expr, expect)
#define UT_EXPECT_NE(expr, expect)
#define UT_EXPECT_GT(expr, expect)
#define UT_EXPECT_GE(expr, expect)
#define UT_EXPECT_LT(expr, expect)
#define UT_EXPECT_LE(expr, expect)
#define UT_EXPECT_EQ_CHILD(expr, expect)
#define UT_EXPECT_NE_CHILD(expr, expect)
#define UT_EXPECT_GT_CHILD(expr, expect)
#define UT_EXPECT_GE_CHILD(expr, expect)
#define UT_EXPECT_LT_CHILD(expr, expect)
#define UT_EXPECT_LE_CHILD(expr, expect)
#define UT_RUN_ALL(attr)
#define UT_RUN_MODULE(module_name, attr)
#define UT_RUN_GROUP(group_id, attr)
#define UT_RUN_STANDARD(attr)
#define UT_RETURN_WHEN_MISSED()
#define UT_EXIT_WHEN_MISSED()
#define UT_ABORT_WHEN_MISSED()
#define UT_ASSERT_WHEN_MISSED()
#define UT_RUN_MAIN(result_var)
#define UT_RESET_LAST_RESULT()
#define UT_LAST_PASSED_TOTAL() 0
#define UT_LAST_MISSED_TOTAL() 0
#define UT_SET_OUTPUT_FUNC(func)
#define UT_OUTPUT(fmt, ...)
#define UT_WITH_(statement)

#endif//UT_ENABLED

#endif//__UNIT_TEST_H__

// End of file
