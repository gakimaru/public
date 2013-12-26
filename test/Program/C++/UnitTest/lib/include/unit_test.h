#pragma once
#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

//���j�b�g�L�����}�N���̒���
#if defined(RUN_UNIT_TEST_ALL) || defined(RUN_UNIT_TEST_ESPECIALLY)
//���j�b�g�e�X�g�L����
#define UNIT_TEST_ENABLED
#elif defined(RUN_UNIT_TEST)
//���j�b�g�e�X�g�L���������[�h�ݒ�
#define UNIT_TEST_ENABLED
#define RUN_UNIT_TEST_ALL
#elif defined(UNIT_TEST_ENABLED)
//���j�b�g�e�X�g���[�h�ݒ�
#define RUN_UNIT_TEST_ALL
#endif//RUN_UNIT_TEST

//���j�b�g�e�X�g�������}�N���̒���
#ifdef UNIT_TEST_ENABLED
#ifdef UNIT_TEST_DISABLED
#undef UNIT_TEST_DISABLED
#endif//UNIT_TEST_DISABLED
#else//UNIT_TEST_ENABLED
#define UNIT_TEST_DISABLED
#endif//UNIT_TEST_ENABLED

#ifdef UNIT_TEST_ENABLED

#include <stdio.h>
#include <string>
#include <sstream>

namespace UnitTest
{
	//���j�b�g�e�X�g���C���N���X
	class CMain
	{
	private:
		//	explicit CUnitTestMain(){}
		explicit CMain(CMain&){}
	public:
		//�R���X�g���N�^
		explicit CMain();
		//�f�X�g���N�^
		~CMain();

	public:
		//���j�b�g�e�X�g���s
#if defined(RUN_UNIT_TEST_ESPECIALLY)
		int runUnitTest(const bool especially_only = true);
#else//if defined(RUN_UNIT_TEST_ALL)
		int runUnitTest(const bool especially_only = false);
#endif//RUN_UNIT_TEST_***
		int runUnitTestAll();
		int runUnitTestEspecially();

	public:
		//���j�b�g�e�X�g�o�^
		typedef int(*T_UNIT_TEST_FUNC)(int& passed, int& missed);
		static bool addFuncInfo(T_UNIT_TEST_FUNC func, const bool is_especially);

		//���j�b�g�e�X�g���ʕ\��
		static void printResult(const bool is_child, int* passed, int* missed, const bool result, const char* expr, const char* value, const char* ope, const char* expect);
		template<typename T, typename S, std::size_t S_SIZE>
		static T calcResult(T value, S (&str)[S_SIZE])
		{
			std::ostringstream os;
			os << value;
			strcpy_s(str, S_SIZE, os.str().c_str());
			return value;
		}

	private:
		//���j�b�g�e�X�g���
	//	static const int UNIT_TEST_FUNC_LIST_NUM_MAX;
		struct T_UNIT_TEST_FUNC_INFO
		{
			T_UNIT_TEST_FUNC m_func;
			bool m_isEspecially;
		};
		static int m_funcListNum;
		static T_UNIT_TEST_FUNC_INFO m_funcList[];//[UNIT_TEST_FUNC_LIST_NUM_MAX];
	};
}; //namespace UnitTest

#define UT_BEGIN(module_name, is_especially) \
namespace __UnitTest_##module_name \
{ \
class __CUnitTestModle \
	{ \
	public: \
		__CUnitTestModle() \
		{ \
			UnitTest::CMain::addFuncInfo(runUnitTest, is_especially); \
		} \
			~__CUnitTestModle() \
		{ \
		} \
	public: \
		static int runUnitTest(int& __passed, int& __missed) \
		{ \
			printf("----- Start unit test:"## #module_name ##" -----\n"); \
			__passed = 0; \
			__missed = 0; \
			char __value_str[64];
#define UT_END() \
			printf("----- End unit test(test=%d, passed=%d, missed=%d) -----\n", __passed + __missed, __passed, __missed); \
			return __missed; \
		} \
	}; \
	static __CUnitTestModle __unit_test_obj; \
}; //namespace __UnitTest_##module_name
#define UT_PRINT_RESULT(is_child, expr, value) UnitTest::CMain::printResult(is_child, nullptr, nullptr, true, #expr, __value_str, nullptr, nullptr)
#define UT_PRINT_EXPR(is_child, expr) expr; UnitTest::CMain::printResult(is_child, nullptr, nullptr, true, #expr, nullptr, nullptr, nullptr)
#define UT_PRINT_EXPR_WITH_RET(is_child, expr, value) value; UnitTest::CMain::printResult(is_child, nullptr, nullptr, true, #expr, __value_str, nullptr, nullptr)
#define UT_CLAC_AND_PRINT_RESULT(is_child, expr, value, ope, expect) UnitTest::CMain::printResult(is_child, &__passed, &__missed, ((value) ope (expect)), #expr, __value_str, #ope, #expect)
#define UT_EXPECT(expr, ope, expect) UT_CLAC_AND_PRINT_RESULT(false, expr, UnitTest::CMain::calcResult(expr, __value_str), ope, expect)
#define UT_EXPECT_CHILD(expr, ope, expect) UT_CLAC_AND_PRINT_RESULT(true, expr, UnitTest::CMain::calcResult(expr, __value_str), ope, expect)
#define UT_EXPR(expr) UT_PRINT_EXPR(false, expr)
#define UT_EXPR_CHILD(expr) UT_PRINT_EXPR(true, expr)
#define UT_EXPR_WITH_RET(expr) UT_PRINT_EXPR_WITH_RET(false, expr, UnitTest::CMain::calcResult(expr, __value_str))
#define UT_EXPR_WITH_RET_CHILD(expr) UT_PRINT_EXPR_WITH_RET(true, expr, UnitTest::CMain::calcResult(expr, __value_str))

#else//UNIT_TEST_ENABLED

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

#endif//UNIT_TEST_ENABLED

#endif//__UNIT_TEST_H__

// End of file
