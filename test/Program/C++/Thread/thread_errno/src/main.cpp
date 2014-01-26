#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <process.h>

//スレッド関数１：errnoにエラー値が入る処理を実行
unsigned int WINAPI threadFunc1(void* param_p)
{
	printf("[THREAD1](begin) errno=%d\n", errno);
	FILE* fp = nullptr;
	fopen_s(&fp, "Dummy file name for errno", "rb");
	printf("[THREAD1](error) errno=%d\n", errno);
	Sleep(1000);
	printf("[THREAD1](end)   errno=%d\n", errno);
	return 0;
}

//スレッド関数２：何もせず errno を表示するだけ
unsigned int WINAPI threadFunc2(void* param_p)
{
	printf("[THREAD2](begin) errno=%d\n", errno);
	Sleep(1000);
	printf("[THREAD2](end)   errno=%d\n", errno);
	return 0;
}

//スレッド関数３：errnoにエラー値が入る処理を実行
DWORD WINAPI threadFunc3(LPVOID param_p)
{
	printf("[THREAD3](begin) errno=%d\n", errno);
	FILE* fp = nullptr;
	fopen_s(&fp, "Dummy file name for errno", "rb");
	printf("[THREAD3](error) errno=%d\n", errno);
	Sleep(1000);
	printf("[THREAD3](end)   errno=%d\n", errno);
	return 0;
}

//スレッド関数４：何もせず errno を表示するだけ
DWORD WINAPI threadFunc4(LPVOID param_p)
{
	printf("[THREAD4](begin) errno=%d\n", errno);
	Sleep(1000);
	printf("[THREAD4](end)   errno=%d\n", errno);
	return 0;
}

int main(const int argc, const char* argv[])
{
	printf("[MAIN](begin) errno=%d\n", errno);
	
	//スレッド実行前にerrnoにエラー値が入る処理を実行
	FILE* fp = nullptr;
	fopen_s(&fp, "Dummy file name for errno", "rb");
	printf("[MAIN](error) errno=%d\n", errno);
	
	{
		unsigned int tid_a[2] = {};
		DWORD tid_b[2] = {};
		HANDLE hthread[4] = {};
		hthread[0] = (HANDLE)_beginthreadex(NULL, 0, threadFunc1, nullptr, 0, &tid_a[0]);
		hthread[1] = (HANDLE)_beginthreadex(NULL, 0, threadFunc2, nullptr, 0, &tid_a[1]);
		hthread[2] = CreateThread(NULL, 0, threadFunc3, NULL, 0, &tid_b[0]);
		hthread[3] = CreateThread(NULL, 0, threadFunc4, NULL, 0, &tid_b[1]);
		WaitForMultipleObjects(4, hthread, true, INFINITE);
	}

	printf("[MAIN](end)   errno=%d\n", errno);

	return EXIT_SUCCESS;
}

// End of file
