#include <stdio.h>
#include <stdlib.h>

#include <thread>

#define thread_local __declspec(thread)

static volatile int s_data = 0;//�ʏ�ϐ�
static thread_local int s_tlsData = 0;//TLS�ϐ�

//�X���b�h�֐�
void threadFunc(const char* name)
{
	++s_data;
	++s_tlsData;
	printf("[%s] s_data=%d, s_tlsData=%d\n", name, s_data, s_tlsData);
}

//C++11 thread �e�X�g
int main(const int argc, const char* argv[])
{
	std::thread th1(threadFunc, "�X���b�h1");
	std::thread th2(threadFunc, "�X���b�h2");
	std::thread th3(threadFunc, "�X���b�h3");
	th1.join();
	th2.join();
	th3.join();
	return EXIT_SUCCESS;
}

// End of file
