#include <stdio.h>
#include <stdlib.h>

#include <string.h>//strcmp用
#include <chrono>//C++11 時間計測用

#ifdef _DEBUG
static const int CASE1_LOOP_COUNT = 1000;
static const int CASE2_LOOP_COUNT = 2000;
static const int CASE3_LOOP_COUNT = 10000;
#else//_DEBUG
static const int CASE1_LOOP_COUNT = 2000;
static const int CASE2_LOOP_COUNT = 10000;
static const int CASE3_LOOP_COUNT = 20000;
#endif//_DEBUG

//----------------------------------------
//メイン
int main(const int argc, const char* argv[])
{
	auto begin_time = std::chrono::system_clock::now();
	struct printElapsedTime{
		auto operator()(const std::chrono::system_clock::time_point& prev_time) -> std::chrono::system_clock::time_point
		{
			const auto now_time = std::chrono::system_clock::now();
			const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - prev_time);
			const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
			printf("*elapsed time=%.9lf sec\n", elapsed_time);
			return now_time;
		}
	};
	auto prev_time = std::chrono::system_clock::now();

	if (argc == 1 || argc >= 2 && strcmp(argv[1], "1") == 0)
	{
		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "C") == 0)
		{
			printf("\n");
			printf("--- Test: Case 1 ---\n");
			extern void initCase1();
			initCase1();
			printf("test: x%d times.\n", CASE1_LOOP_COUNT);
		}

		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "B") == 0)
		{
			printf("[Bad]      ");
			extern void testCase1Bad(int);
			prev_time = std::chrono::system_clock::now();
			for (int loop = 0; loop < CASE1_LOOP_COUNT; ++loop)
				testCase1Bad(loop);
			prev_time = printElapsedTime()(prev_time);
		}

		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "I") == 0)
		{
			printf("[Improved] ");
			extern void testCase1Improved(int);
			prev_time = std::chrono::system_clock::now();
			for (int loop = 0; loop < CASE1_LOOP_COUNT; ++loop)
				testCase1Improved(loop);
			prev_time = printElapsedTime()(prev_time);
		}
	}

	if (argc == 1 || argc >= 2 && strcmp(argv[1], "2") == 0)
	{
		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "C") == 0)
		{
			printf("\n");
			printf("--- Test: Case 2 ---\n");
			extern void initCase2();
			initCase2();
			printf("test: x%d times.\n", CASE2_LOOP_COUNT);
		}

		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "B") == 0)
		{
			printf("[Bad]      ");
			extern void testCase2Bad(int);
			prev_time = std::chrono::system_clock::now();
			for (int loop = 0; loop < CASE2_LOOP_COUNT; ++loop)
				testCase2Bad(loop);
			prev_time = printElapsedTime()(prev_time);
		}

		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "I") == 0)
		{
			printf("[Improved] ");
			extern void testCase2Improved(int);
			prev_time = std::chrono::system_clock::now();
			for (int loop = 0; loop < CASE2_LOOP_COUNT; ++loop)
				testCase2Improved(loop);
			prev_time = printElapsedTime()(prev_time);
		}
	}

	if (argc == 1 || argc >= 2 && strcmp(argv[1], "3") == 0)
	{
		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "C") == 0)
		{
			printf("\n");
			printf("--- Test: Case 3 ---\n");
		#ifdef ENABLE_DUMMY
			printf("*Buffer is adjusted location for cahce-line address.\n");
		#endif//ENABLE_DUMMY
			extern void initCase3();
			initCase3();
			printf("test: x%d times.\n", CASE3_LOOP_COUNT);
		}

		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "B") == 0)
		{
			printf("[Bad]      ");
			extern void testCase3Bad(int);
			prev_time = std::chrono::system_clock::now();
			for (int loop = 0; loop < CASE3_LOOP_COUNT; ++loop)
				testCase3Bad(loop);
			prev_time = printElapsedTime()(prev_time);
		}

		if (argc <= 2 || argc >= 3 && strcmp(argv[2], "I") == 0)
		{
			printf("[Improved] ");
			extern void testCase3Improved(int);
			prev_time = std::chrono::system_clock::now();
			for (int loop = 0; loop < CASE3_LOOP_COUNT; ++loop)
				testCase3Improved(loop);
			prev_time = printElapsedTime()(prev_time);
		}
	}

	return EXIT_SUCCESS;
}

// End of file
