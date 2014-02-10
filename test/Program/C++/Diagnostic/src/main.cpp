#include <stdlib.h>
#include <windows.h>

int main(const int argc, const char* argv[])
{
	//プロセス優先度変更
	HANDLE hProcess = GetCurrentProcess();//現在のプロセスハンドルを取得
	SetPriorityClass(hProcess, REALTIME_PRIORITY_CLASS);//優先度をリアルタイム（最高）に変更
	
	//スレッド優先度変更
	HANDLE hThread = GetCurrentThread();//現在のスレッドハンドルを取得
	SetThreadPriority(hThread, THREAD_PRIORITY_TIME_CRITICAL);//相対優先順位を最高に変更

	//無限ループ
	while (1);

	return EXIT_SUCCESS;
}

// End of file
