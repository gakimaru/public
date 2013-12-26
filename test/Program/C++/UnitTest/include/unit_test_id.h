#pragma once
#ifndef __UNIT_TEST_ID_H__
#define __UNIT_TEST_ID_H__

#include "unit_test.h"

#ifdef UT_ENABLED
//ユニットテストグループID
enum E_UT_GROUP
{
	UT_GROUP_NONE = 0,
	UT_GROUP_USER_A = 1,
	UT_GROUP_USER_B = 2,
};
#endif//UT_ENABLED

#endif//__UNIT_TEST_ID_H__

// End of file
