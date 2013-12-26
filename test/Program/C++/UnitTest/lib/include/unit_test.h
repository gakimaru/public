#pragma once
#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

//�v���W�F�N�g�ݒ�́mC/C++�n���m�v���v���Z�b�T�n���m�v���v���Z�b�T�̒�`�n�ɂĒ�`�����}�N��
//#define UT_ENABLED       ... ���j�b�g�e�X�g�̏����R�[�h���L���ɂȂ�B
//
//#define UT_AUTO          ... ���j�b�g�e�X�g�̎������s��L���ɂ���B
//                             ��main�����̖`���ŁuUT_RUN_MAIN();�v�ƋL�q���Ă����B
//                               �Ȍ�̏����͎��s������ return ����B���� return �l�� main �֐��̖߂�l�ɂ���悤�ɁB
//                               �������Ǘ��Ȃǂ̊�{�I�ȏ������������I�������Ŏ��s����悤�ɁB
//#define UT_TARGET_MODULE ... UT_AUTO �Ŏ������s���ɁA�w��̃��W���[������ΏۂɌ��肵�Ď��s����B�ȗ������ꍇ�͑S�đΏہB
//#define UT_TARGET_GROUP  ... UT_AUTO �Ŏ������s���ɁA�w��̃O���[�vID��ΏۂɌ��肵�Ď��s����B�ȗ������ꍇ�͑S�đΏہB
//
//�������̃}�N�����g�p�����Ƃ��A�uUT_RUN_ALL();�v�uUT_RUN_MODULE();�v�uUT_RUN_GROUP();�v�̂����ꂩ�𒼐ڌĂяo���΁A���ł����j�b�g�e�X�g�����s�\�B
//�@�߂�l�̓e�X�g�Ƀ~�X�������B����͏�� 0 �łȂ���΂Ȃ�Ȃ��B

#ifdef UT_ENABLED

#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <sstream>

#ifndef ASSERT
#include <assert.h>
#define ASSERT(expr) assert(expr)
#endif//ASSERT

namespace UnitTest
{
	//���j�b�g�e�X�g���C���N���X
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
		//�R���X�g���N�^
		explicit CCollection(){}
		//�f�X�g���N�^
		~CCollection(){}

	public:
		//�A�N�Z�b�T
		static int getFuncInfoListNum();
		static const UNIT_TEST_FUNC_INFO* getFuncInfoListTop();
		static const UNIT_TEST_FUNC_INFO* getFuncInfo(const int index);
		static const UNIT_TEST_FUNC_INFO* getFuncInfo(const char* module_name);
		
		//�O��̌���
		static int getLastPassedTotal();
		static int getLastMissedTotal();

	public:
		//�O��̎��s���ʂ����Z�b�g
		static void resetLastResult();

	public:
		//���j�b�g�e�X�g���s
		static int runUnitTest(const char* target_module_name = nullptr, const int target_group_id = 0);
		static int runUnitTestStandard();

	public:
		//���j�b�g�e�X�g�o�^
		static bool addFuncInfo(UNIT_TEST_FUNC_P func, const char* module_name, const int group_id);

		//���j�b�g�e�X�g���ʕ\��
		static void setOutputFunc(UNIT_TEST_OUTPUT_FUNC_P func);
		static int output(const char* fmt, ...);
		static void outputRunUTBegin(const char* target_module_name, const int target_group_id);
		static void outputRunUTEnd(const char* target_module_name, const int target_group_id, const int total_passed, const int total_missed);
		static void outputRunUTModuleBegin(const char* module_name, const int group_id);
		static void outputRunUTModuleEnd(const char* module_name, const int group_id, const int passed, const int missed);
		static void outputUTResult(const bool is_child, int* passed, int* missed, const bool result, const char* expr, const char* value, const char* ope, const char* expect);
		template<typename T, typename S, std::size_t S_SIZE>
		static T calcResult(T value, S (&str)[S_SIZE])
		{
			std::ostringstream os;
			os << value;
			strcpy_s(str, S_SIZE, os.str().c_str());
			return value;
		}
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
		char __value_str[64]; \
		UnitTest::CCollection::outputRunUTModuleBegin(__module_name, __group_id);
#define UT_END() \
		UnitTest::CCollection::outputRunUTModuleEnd(__module_name, __group_id, __passed, __missed); \
		return __missed; \
	} \
}; \
	static __CUnitTestModle __unit_test_obj; \
}; //namespace __UnitTest_##module_name
#define UT_PRINT_RESULT(is_child, expr, value) UnitTest::CCollection::outputUTResult(is_child, nullptr, nullptr, true, #expr, __value_str, nullptr, nullptr)
#define UT_PRINT_EXPR(is_child, expr) expr; UnitTest::CCollection::outputUTResult(is_child, nullptr, nullptr, true, #expr, nullptr, nullptr, nullptr)
#define UT_PRINT_EXPR_WITH_RET(is_child, expr, value) value; UnitTest::CCollection::outputUTResult(is_child, nullptr, nullptr, true, #expr, __value_str, nullptr, nullptr)
#define UT_CLAC_AND_PRINT_RESULT(is_child, expr, value, ope, expect) UnitTest::CCollection::outputUTResult(is_child, &__passed, &__missed, ((value) ope (expect)), #expr, __value_str, #ope, #expect)
#define UT_EXPECT(expr, ope, expect) UT_CLAC_AND_PRINT_RESULT(false, expr, UnitTest::CCollection::calcResult(expr, __value_str), ope, expect)
#define UT_EXPECT_CHILD(expr, ope, expect) UT_CLAC_AND_PRINT_RESULT(true, expr, UnitTest::CCollection::calcResult(expr, __value_str), ope, expect)
#define UT_EXPR(expr) UT_PRINT_EXPR(false, expr)
#define UT_EXPR_CHILD(expr) UT_PRINT_EXPR(true, expr)
#define UT_EXPR_WITH_RET(expr) UT_PRINT_EXPR_WITH_RET(false, expr, UnitTest::CCollection::calcResult(expr, __value_str))
#define UT_EXPR_WITH_RET_CHILD(expr) UT_PRINT_EXPR_WITH_RET(true, expr, UnitTest::CCollection::calcResult(expr, __value_str))

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
