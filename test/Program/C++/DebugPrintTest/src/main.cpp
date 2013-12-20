#define ___FILE __FILE__
#define ___LINE __LINE__
#define ___TIMESTAMP __TIMESTAMP__
#define ___FUNC __FUNCTION__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdargs.h>

#define DEBUG_MODE

#ifdef DEBUG_MODE
namespace debug
{
	static const char* RANK_MARK[] = { "", "C", "B", "A" };
	int curr_call_level = 0;
	int curr_call_rank = 0;
	int call_point_level = 0;
	int call_point_rank = 0;
	const char* call_point_msg = "(NULL)";
	const char* call_point_file = "(NULL)";
	const char* call_point_timestamp = "(NULL)";
	int call_point_line = -1;
	const char* call_point_func = "(NULL)";
	
	const char* const getFileName(const char* const path)
	{
		int len = strlen(path);
		const char* p = path + len - 1;
		for (int pos = len - 1; pos >= 0; --pos, --p)
		{
			const char c = *p;
			if (c == '/' || c == '\\')
			{
				return p + 1;
			}
		}
		return path;
	}
	void print(const char* func, const char* file, const int line, const char* timestamp, const char* msg, ...)
	{
		printf("------------------------------------------------------------------------------\n");
		if (debug::call_point_level > 0){
			printf(">CallPoint:[%d%s]\"%s\" %s() %s[%d](%s)", debug::call_point_level, RANK_MARK[debug::call_point_rank], debug::call_point_msg, debug::call_point_func, getFileName(debug::call_point_file), debug::call_point_line, debug::call_point_timestamp);
			if (debug::call_point_level != debug::curr_call_level)
				printf(" [LastSkip:%d%s]", debug::curr_call_level, RANK_MARK[debug::curr_call_rank]);
			printf("\n");
		}
		printf("*\"%s\" %s() %s[%d](%s)\n", msg, func, getFileName(file), line, timestamp);
	}
	class CCallPoint
	{
	private:
		const bool is_update;
		const int mem_curr_call_level = 0;
		const int mem_curr_call_rank = 0;
		const int mem_call_point_level = 0;
		const int mem_call_point_rank;
		const char* const mem_call_point_msg;
		const char* const mem_call_point_file;
		const char* const mem_call_point_timestamp;
		const int mem_call_point_line;
		const char* const mem_call_point_func;
	public:
		explicit CCallPoint(const int rank, const char* const file, const char* const timestamp, const int line, const char* const func, const char* const msg, ...) :
			is_update(debug::curr_call_level == 0 || rank >= debug::call_point_rank),
			mem_curr_call_level(debug::curr_call_level),
			mem_curr_call_rank(debug::curr_call_rank),
			mem_call_point_level(debug::call_point_level),
			mem_call_point_rank(debug::call_point_rank),
			mem_call_point_msg(debug::call_point_msg),
			mem_call_point_file(debug::call_point_file),
			mem_call_point_timestamp(debug::call_point_timestamp),
			mem_call_point_line(debug::call_point_line),
			mem_call_point_func(debug::call_point_func)
		{
			++debug::curr_call_level;
			debug::curr_call_rank = rank;
			if (is_update)
			{
				debug::call_point_level = debug::curr_call_level;
				debug::call_point_rank = rank;
				debug::call_point_msg = msg;
				debug::call_point_file = file;
				debug::call_point_timestamp = timestamp;
				debug::call_point_line = line;
				debug::call_point_func = func;
			}
		}
		~CCallPoint()
		{
			debug::curr_call_level = mem_curr_call_level;
			debug::curr_call_rank = mem_curr_call_rank;
			if (is_update)
			{
				debug::call_point_level = mem_call_point_level;
				debug::call_point_rank = mem_call_point_rank;
				debug::call_point_msg = mem_call_point_msg;
				debug::call_point_file = mem_call_point_file;
				debug::call_point_timestamp = mem_call_point_timestamp;
				debug::call_point_line = mem_call_point_line;
				debug::call_point_func = mem_call_point_func;
			}
		}
	};
};

#define DEBUG_CALL_POINT(critical_level, msg, ...) debug::CCallPoint DebugCallPoint(critical_level, ___FILE, ___TIMESTAMP, ___LINE, ___FUNC, msg, __VA_ARGS__)
#define DEBUG_CALL_POINT_CRITICAL(msg, ...) debug::CCallPoint DebugCallPoint(1, ___FILE, ___TIMESTAMP, ___LINE, ___FUNC, msg, __VA_ARGS__)
#define DEBUG_CALL_POINT_CRITICAL_C(msg, ...) debug::CCallPoint DebugCallPoint(1, ___FILE, ___TIMESTAMP, ___LINE, ___FUNC, msg, __VA_ARGS__)
#define DEBUG_CALL_POINT_CRITICAL_B(msg, ...) debug::CCallPoint DebugCallPoint(2, ___FILE, ___TIMESTAMP, ___LINE, ___FUNC, msg, __VA_ARGS__)
#define DEBUG_CALL_POINT_CRITICAL_A(msg, ...) debug::CCallPoint DebugCallPoint(3, ___FILE, ___TIMESTAMP, ___LINE, ___FUNC, msg, __VA_ARGS__)
#define DEBUG_CALL_POINT_NORMAL(msg, ...) debug::CCallPoint DebugCallPoint(0, ___FILE, ___TIMESTAMP, ___LINE, ___FUNC, msg, __VA_ARGS__)

#define PRINT_DEBUG(msg, ...) debug::print(___FUNC, ___FILE, ___LINE, ___TIMESTAMP, msg, __VA_ARGS__);
//#define PRINT_DEBUG(msg, ...) printf("PRINT_DEBUG:__FILE__=\"%s\", __TIMESTAMP__=\"%s\", __DATE__=\"%s\", __TIME__=\"%s\", __LINE__=%d, __FUNCDNAME__=\"%s\", __FUNCSIdebug::_=\"%s\", __FUNCTION__=\"%s\", msg=\"%s\"\n", __FILE__, __TIMESTAMP__, __DATE__, __TIME__, __LINE__, __FUNCDNAME__, __FUNCSIdebug::_, __FUNCTION__, msg);

#else//DEBUG_MODE

#define DEBUG_CALL_POINT(critical_level, msg, ...)
#define DEBUG_CALL_POINT_CRITICAL(msg, ...)
#define DEBUG_CALL_POINT_CRITICAL_C(msg, ...)
#define DEBUG_CALL_POINT_CRITICAL_B(msg, ...)
#define DEBUG_CALL_POINT_CRITICAL_A(msg, ...)
#define DEBUG_CALL_POINT_NORMAL(msg, ...)

#define PRINT_DEBUG(msg, ...)

#endif//DEBUG_MODE

class CTest
{
public:
	void test()
	{
		PRINT_DEBUG("TEST");
	}
};

void common_func()
{
	PRINT_DEBUG("COMMON");
}

void sub()
{
	DEBUG_CALL_POINT_CRITICAL("TEST1_1");
	PRINT_DEBUG("TEST1_1:START");
	common_func();
	{
		DEBUG_CALL_POINT_CRITICAL_B("TEST1_2");
		PRINT_DEBUG("TEST1_2:START");
		common_func();
		{
			DEBUG_CALL_POINT_NORMAL("TEST1_3");
			PRINT_DEBUG("TEST1_3:START");
			common_func();
			{
				DEBUG_CALL_POINT_CRITICAL("TEST1_4");
				PRINT_DEBUG("TEST1_4:START");
				common_func();
				{
					DEBUG_CALL_POINT_CRITICAL_B("TEST1_5");
					PRINT_DEBUG("TEST1_5:START");
					common_func();
					{
						DEBUG_CALL_POINT_CRITICAL_A("TEST1_6");
						PRINT_DEBUG("TEST1_6:START");
						common_func();
						{
							DEBUG_CALL_POINT_CRITICAL_B("TEST1_7");
							PRINT_DEBUG("TEST1_7:START");
							common_func();
							PRINT_DEBUG("TEST1_7:END");
						}
						common_func();
						PRINT_DEBUG("TEST1_6:END");
					}
					common_func();
					PRINT_DEBUG("TEST1_5:END");
				}
				common_func();
				PRINT_DEBUG("TEST1_4:END");
			}
			common_func();
			PRINT_DEBUG("TEST1_3:END");
		}
		common_func();
		PRINT_DEBUG("TEST1_2:END");
	}
	common_func();
	PRINT_DEBUG("TEST1_1:END");
}
void sub(const char* const msg)
{
	DEBUG_CALL_POINT_NORMAL(msg);
	PRINT_DEBUG("sub(msg):START");
	common_func();
	PRINT_DEBUG("sub(msg):END");
}

void special_sub()
{
	DEBUG_CALL_POINT_NORMAL("SPECIAL!");
	PRINT_DEBUG("special_sub:START");
	common_func();
	CTest test;
	test.test();
	PRINT_DEBUG("special_sub:END");
}

int main(const int argc, const char* argv[])
{
	printf("- Test : Start -\n");
	PRINT_DEBUG("<START>");
	common_func();
	sub();
	sub("TEST2-A");
	sub("TEST2-B");
	special_sub();
	common_func();
	PRINT_DEBUG("<END>");
	printf("- Test : End -\n");
	return EXIT_SUCCESS;
}

// End of file
