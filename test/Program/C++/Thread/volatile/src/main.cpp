#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//処理終了フラグ
bool s_isFinished = false;
//volatile bool s_isFinished = false;

//スレッド１
unsigned int WINAPI func1(void* param_p)
{
	//開始
	printf("- func1(): start -\n");
	fflush(stdout);

	//処理...
	printf("func1(): process ...\n");
	fflush(stdout);
	Sleep(1000);

	//処理終了通知
	s_isFinished = true;
	
	//終了
	printf("- func1(): end -\n");
	fflush(stdout);
	return 0;
}

//スレッド２
unsigned int WINAPI func2(void* param_p)
{
	//開始
	printf("- func2(): start -\n");
	fflush(stdout);

	//処理終了待ち
	printf("func2(): wait ...\n");
	fflush(stdout);
	while (!s_isFinished){}
//	while (!s_isFinished){ Yield(); }
//	while (!s_isFinished){ Sleep(); }
	printf("func2(): ok!\n");
	fflush(stdout);

	//処理...
	printf("func2(): process ...\n");
	fflush(stdout);
	Sleep(1000);

	//終了
	printf("- func2(): end -\n");
	fflush(stdout);
	return 0;
}

//テスト
int main(const int argc, const char* argv[])
{
	//開始
	printf("- main(): start -\n");
	fflush(stdout);

	//スレッド開始
	HANDLE hThread[2] =
	{
		(HANDLE)_beginthreadex(nullptr, 0, func1, nullptr, 0, nullptr),
		(HANDLE)_beginthreadex(nullptr, 0, func2, nullptr, 0, nullptr)
	};

	//スレッドプライオリティテスト
//	SetPriorityClass(hThread[0], REALTIME_PRIORITY_CLASS);
//	SetPriorityClass(hThread[1], REALTIME_PRIORITY_CLASS);

	//スレッド終了待ち
	WaitForMultipleObjects(2, hThread, true, INFINITE);


	//終了
	printf("- main(): end -\n");
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
