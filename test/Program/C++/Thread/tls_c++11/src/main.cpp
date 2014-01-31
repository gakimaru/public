#include <stdio.h>
#include <stdlib.h>

#include <thread>

#define thread_local __declspec(thread)

static volatile int s_data = 0;//通常変数
static thread_local int s_tlsData = 0;//TLS変数

//スレッド関数
void threadFunc(const char* name)
{
	++s_data;
	++s_tlsData;
	printf("[%s] s_data=%d, s_tlsData=%d\n", name, s_data, s_tlsData);
}

//C++11 thread テスト
int main(const int argc, const char* argv[])
{
	std::thread th1(threadFunc, "スレッド1");
	std::thread th2(threadFunc, "スレッド2");
	std::thread th3(threadFunc, "スレッド3");
	th1.join();
	th2.join();
	th3.join();
	return EXIT_SUCCESS;
}

// End of file
