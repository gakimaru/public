#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//ミューテックスハンドル
static HANDLE s_hMutex = INVALID_HANDLE_VALUE;

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__declspec(thread) int s_tlsData = 0;

//スレッド
unsigned int WINAPI threadFunc(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);

	//開始
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//処理
	for (int i = 0; i < 3; ++i)
	{
		//ミューテックス取得
		WaitForSingleObject(s_hMutex, INFINITE);//取得できない時に他の処理を行いたい場合はタイムアウト値を指定する
		
		//データ表示（前）
		printf("%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//データ更新
		++common_data;
		++tls_data;

		//若干ランダムでスリープ（0〜4 msec）
		Sleep(rand() % 5);

		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//ミューテックス解放
		ReleaseMutex(s_hMutex);
		
		//スレッド切り替えのためのスリープ
		Sleep(0);
	//	//スレッド切り替え
	//	SwitchToThread();//OSに任せて再スケジューリング
	//	Yield();//廃止
	}

	//終了
	printf("- end:%s -\n", name);
	fflush(stdout);
	return 0;
}

//テスト
int main(const int argc, const char* argv[])
{
	//ミューテックス生成
	{
		s_hMutex = CreateMutex(nullptr, false, nullptr);
		
	//	//属性を指定して生成する場合
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, true };//子プロセスにハンドルを継承する
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, false };//子プロセスにハンドルを継承しない　※デフォルト
	//	s_hMutex = CreateMutex(&attr, false, nullptr);
	}

	//スレッド作成
	static const int THREAD_NUM = 3;
	unsigned int tid[THREAD_NUM] = {};
	HANDLE hThread[THREAD_NUM] =
	{
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "太郎", 0, &tid[0]),
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "次郎", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "三郎", 0, &tid[2])
	};
	
	//スレッド終了待ち
	WaitForMultipleObjects(THREAD_NUM, hThread, true, INFINITE);

	//スレッドハンドルクローズ
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		CloseHandle(hThread[i]);
	}

	//ミューテックスの取得と解放を大量に実行して時間を計測
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			WaitForSingleObject(s_hMutex, INFINITE);
			ReleaseMutex(s_hMutex);
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Mutex * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//ミューテックス破棄
	CloseHandle(s_hMutex);
	s_hMutex = INVALID_HANDLE_VALUE;

	return EXIT_SUCCESS;
}

// End of file
