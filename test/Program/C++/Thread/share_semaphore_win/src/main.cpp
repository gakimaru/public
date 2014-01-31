#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//セマフォハンドル
static HANDLE s_hSemaphore = INVALID_HANDLE_VALUE;

//クリティカルセクション
static CRITICAL_SECTION s_lock;

//共有リソース
static const int COMMON_RESOURCE_NUM = 2;
static int s_commonResource[COMMON_RESOURCE_NUM]       = {};//複数の共有リソース
static bool s_usingCommonResource[COMMON_RESOURCE_NUM] = {};//共有リソース使用中フラグ

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
		//セマフォ取得
		WaitForSingleObject(s_hSemaphore, INFINITE);//取得できない時に他の処理を行いたい場合はタイムアウト値を指定する

		//共有リソースを獲得
		int index = 0;
		EnterCriticalSection(&s_lock);//クリティカルセクション取得
		for (; index < COMMON_RESOURCE_NUM; ++index)
		{
			if (!s_usingCommonResource[index])
				break;
		}
		s_usingCommonResource[index] = true;
		LeaveCriticalSection(&s_lock);//クリティカルセクション解放

		//データ表示（前）
		printf("%s: [BEFORE] commonResource[%d]=%d, tlsData=%d\n", name, index, s_commonResource[index], s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonResource[index];
		int tls_data = s_tlsData;

		//データ更新
		++common_data;
		++tls_data;

		//若干ランダムでスリープ（0～4 msec）
		Sleep(rand() % 5);

		//データ書き戻し
		s_commonResource[index] = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("%s: [AFTER]  commonResource[%d]=%d, tlsData=%d\n", name, index, s_commonResource[index], s_tlsData);
		fflush(stdout);

		//共有リソースを解放
		s_usingCommonResource[index] = false;
		
		//セマフォ解放
		LONG prev_count;
		ReleaseSemaphore(s_hSemaphore, 1, &prev_count);

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
	//セマフォ生成
	{
		s_hSemaphore = CreateSemaphore(nullptr, 0, COMMON_RESOURCE_NUM, nullptr);//初期状態はセマフォを全て使用中にする
		
	//	//属性を指定して生成する場合
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, true };//子プロセスにハンドルを継承する
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, false };//子プロセスにハンドルを継承しない　※デフォルト
	//	s_hSemaphore = CreateSemaphore(&attr, 0, COMMON_RESOURCE_NUM, nullptr);//初期状態はセマフォを全て使用中にする
	}

	//クリティカルセクション生成
	InitializeCriticalSectionAndSpinCount(&s_lock, 100);

	//スレッド作成
	static const int THREAD_NUM = 4;
	unsigned int tid[THREAD_NUM] = {};
	HANDLE hThread[THREAD_NUM] =
	{
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "太郎", 0, &tid[0]),
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "次郎", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "三郎", 0, &tid[2]),
		(HANDLE)_beginthreadex(nullptr, 1024, threadFunc, "四郎", 0, &tid[3])
	};

	//若干スリープ
	Sleep(10);

	//共有リソース初期化
	for (int i = 0; i < COMMON_RESOURCE_NUM; ++i)
	{
		s_commonResource[i] = 1000 * (i + 1);
	}

	//若干スリープ
	Sleep(10);

	//共有リソースの使用を許可（全セマフォ解放）
	{
		LONG prev_count;
		ReleaseSemaphore(s_hSemaphore, COMMON_RESOURCE_NUM, &prev_count);
		printf("Common-resources have been prepared. (num=%d -> %d)\n", prev_count, COMMON_RESOURCE_NUM);
		fflush(stdout);
	}

	//スレッド終了待ち
	WaitForMultipleObjects(THREAD_NUM, hThread, true, INFINITE);

	//スレッドハンドルクローズ
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		CloseHandle(hThread[i]);
	}

	//セマフォの取得と解放を大量に実行して時間を計測
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			WaitForSingleObject(s_hSemaphore, INFINITE);
			ReleaseSemaphore(s_hSemaphore, 1, nullptr);
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Semaphore * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//クリティカルセクション破棄
	DeleteCriticalSection(&s_lock);
	
	//セマフォ破棄
	CloseHandle(s_hSemaphore);
	s_hSemaphore = INVALID_HANDLE_VALUE;

	return EXIT_SUCCESS;
}

// End of file
