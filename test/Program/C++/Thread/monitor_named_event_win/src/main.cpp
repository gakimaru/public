#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//スレッド情報
static const int FOLLOW_THREAD_MAX = 10;          //後続スレッド最大数
static volatile LONG s_followThreadNum = 0;       //後続スレッド数
static volatile LONG s_followThreadNo = 0;        //後続スレッド番号発番用
static volatile bool s_IsQuirProiorThread = false;//先行スレッド終了フラグ

//イベント名
static const char* PRIOR_EVENT_NAME[FOLLOW_THREAD_MAX] =  //先行スレッド処理完了イベント
{
	"Prior Event 01",
	"Prior Event 02",
	"Prior Event 03",
	"Prior Event 04",
	"Prior Event 05",
	"Prior Event 06",
	"Prior Event 07",
	"Prior Event 08",
	"Prior Event 09",
	"Prior Event 10",
};
static const char* FOLLOW_EVENT_NAME[FOLLOW_THREAD_MAX] =//後続スレッド処理完了イベント
{
	"Follow Event 01",
	"Follow Event 02",
	"Follow Event 03",
	"Follow Event 04",
	"Follow Event 05",
	"Follow Event 06",
	"Follow Event 07",
	"Follow Event 08",
	"Follow Event 09",
	"Follow Event 10",
};

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__declspec(thread) int s_tlsData = 0;

//【処理説明】
//先行スレッドが共有データを作成し、それが完了したら
//複数の後続スレッドがスタート。
//後続スレッドは共有データを読み込むだけのため、並列で動作。
//後続スレッドの処理が全て完了したら、また先行スレッドが稼働。
//以上を何度か繰り返し、先行スレッドが終了したら全スレッド終了。
//※メインループ⇒描画スレッドのようなリレー処理への応用を想定。

//先行スレッド
unsigned int WINAPI priorThreadFunc(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);

	//開始
	printf("- begin:(P)%s -\n", name);
	fflush(stdout);

	//名前付きイベントオープン
	HANDLE hPriorEvent[FOLLOW_THREAD_MAX];
	HANDLE hFollowEvent[FOLLOW_THREAD_MAX];
	for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
	{
	 	hPriorEvent[i] = OpenEvent(EVENT_MODIFY_STATE, false, PRIOR_EVENT_NAME[i]);//先行スレッド処理完了イベント：SetEvetn, ResetEvent許可
		hFollowEvent[i] = OpenEvent(SYNCHRONIZE, false, FOLLOW_EVENT_NAME[i]);//後続スレッド処理完了イベント：Wait許可
	}
	
	//初期化
	s_IsQuirProiorThread = false;//先行処理終了フラグ

	//処理
	static const int LOOP_COUNT_MAX = 3;
	int loop_counter = 0;
	while (1)
	{
		//全後続スレッド処理完了待ち
		WaitForMultipleObjects(s_followThreadNum, hFollowEvent, true, INFINITE);

		//ループカウンタ進行＆終了判定
		if (loop_counter++ == LOOP_COUNT_MAX)
		{
			//処理終了
			printf("(P)%s: [QUIT]\n", name);
			fflush(stdout);
			
			//先行スレッド終了フラグ
			s_IsQuirProiorThread = true;
			
			//先行スレッド処理完了イベントセット
			for (int i = 0; i < s_followThreadNum; ++i)
				SetEvent(hPriorEvent[i]);

			break;
		}

		//データ表示（前）
		printf("(P)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//データ更新
		++common_data;
		++tls_data;

		//若干ランダムでスリープ（0～499 msec）
		Sleep(rand() % 500);

		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("(P)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//先行スレッド処理完了イベントセット
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			SetEvent(hPriorEvent[i]);
		}
		//※PulseEvent() は SetEvent() のように、先行してシグナル状態を作るようなことができず、
		//　PulseEvent() 実行のタイミングで待機しているものを開放するだけしかできない。
		//　なので、PulseEvent() を使用せず、子の数分のイベントを使用する。

		//スレッド切り替えのためのスリープ
		Sleep(0);
	//	//スレッド切り替え
	//	SwitchToThread();//OSに任せて再スケジューリング
	//	Yield();//廃止
	}

	//名前付きイベントクローズ
	for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
	{
		CloseHandle(hPriorEvent[i]);
		CloseHandle(hFollowEvent[i]);
	}

	//終了
	printf("- end:(P)%s -\n", name);
	fflush(stdout);
	return 0;
}

//後続スレッド
unsigned int WINAPI followThreadFunc(void* param_p)
{
	//パラメータ受け取り
	const char* name = static_cast<const char*>(param_p);

	//後続スレッド数カウントアップ
	LONG thread_no = InterlockedIncrement(&s_followThreadNo) - 1;

	//開始
	printf("- begin:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);

	//名前付きイベントオープン
	HANDLE hPriorEvent[FOLLOW_THREAD_MAX];
	HANDLE hFollowEvent[FOLLOW_THREAD_MAX];
	for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
	{
		hPriorEvent[i] = OpenEvent(SYNCHRONIZE, false, PRIOR_EVENT_NAME[i]);//先行スレッド処理完了イベント：Wait許可
		hFollowEvent[i] = OpenEvent(EVENT_MODIFY_STATE, false, FOLLOW_EVENT_NAME[i]);//後続スレッド処理完了イベント：SetEvetn, ResetEvent許可
	}

	//後続スレッド処理完了イベントセット
	SetEvent(hFollowEvent[thread_no]);

	//処理
	while (1)
	{
		//先行スレッド処理完了イベント待ち
		WaitForSingleObject(hPriorEvent[thread_no], INFINITE);//取得できない時に他の処理を行いたい場合はタイムアウト値を指定する

		//終了確認
		if (s_IsQuirProiorThread)
		{
			//処理終了
			printf("(F)[%d]%s: [QUIT]\n", thread_no, name);
			fflush(stdout);
			
			break;
		}

		//データ表示（前）
		printf("(F)[%d]%s: [BEFORE] commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//データ更新
		++tls_data;

		//若干ランダムでスリープ（0～500 msec）
		Sleep(rand() % 500);

		//データ書き戻し
		s_tlsData = tls_data;

		//データ表示（後）
		printf("(F)[%d]%s: [AFTER]  commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);
		
		//後続スレッド処理完了イベントセット
		SetEvent(hFollowEvent[thread_no]);

		//スレッド切り替えのためのスリープ
		Sleep(0);
	//	//スレッド切り替え
	//	SwitchToThread();//OSに任せて再スケジューリング
	//	Yield();//廃止
	}

	//名前付きイベントクローズ
	for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
	{
		CloseHandle(hPriorEvent[i]);
		CloseHandle(hFollowEvent[i]);
	}

	//終了
	printf("- end:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);
	return 0;
}

//テスト
int main(const int argc, const char* argv[])
{
	//イベント生成
	HANDLE hPriorEvent[FOLLOW_THREAD_MAX];
	HANDLE hFollowEvent[FOLLOW_THREAD_MAX];
	{
		//名前付きイベント
		for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
		{
			hPriorEvent[i] = CreateEvent(nullptr, false, false, PRIOR_EVENT_NAME[i]);//手動リセット=false（自動リセット）, 初期状態=false（リセット状態）
			hFollowEvent[i] = CreateEvent(nullptr, false, false, FOLLOW_EVENT_NAME[i]);//手動リセット=false（自動リセット）, 初期状態=false（リセット状態）
		}
		
	//	//属性を指定して生成する場合
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, true };//子プロセスにハンドルを継承する
	//	SECURITY_ATTRIBUTES attr = { sizeof(SECURITY_ATTRIBUTES), nullptr, false };//子プロセスにハンドルを継承しない　※デフォルト
	//	for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
	//	{
	//		hPriorEvent[i] = CreateEvent(&attr, false, false, PRIOR_EVENT_NAME[i]);//手動リセット=false（自動リセット）, 初期状態=false（リセット状態）
	//		hFollowEvent[i] = CreateEvent(&attr, false, false, FOLLOW_EVENT_NAME[i]);//手動リセット=false（自動リセット）, 初期状態=false（リセット状態）
	//	}
	}

	//スレッド作成
	static const int FOLLOW_THREAD_NUM = 5;
	static const int THREAD_NUM = 1 + FOLLOW_THREAD_NUM;
	static_assert(FOLLOW_THREAD_NUM <= FOLLOW_THREAD_MAX, "FOLLOW_THREAD_NUM is over.");
	s_followThreadNum = FOLLOW_THREAD_NUM;
	unsigned int tid[THREAD_NUM] = {};
	HANDLE hThread[THREAD_NUM] =
	{
		(HANDLE)_beginthreadex(nullptr, 0, priorThreadFunc, "先行", 0, &tid[0]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "後続01", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "後続02", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "後続03", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "後続04", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, followThreadFunc, "後続05", 0, &tid[1]),
	};
	
	//スレッド終了待ち
	WaitForMultipleObjects(THREAD_NUM, hThread, true, INFINITE);

	//スレッドハンドルクローズ
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		CloseHandle(hThread[i]);
	}

	//イベントの取得と解放を大量に実行して時間を計測
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			SetEvent(hPriorEvent[0]);
		//	WaitForSingleObject(hPriorEvent[0], INFINITE);
		//	ResetEvent(hPriorEvent[0]);
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Event * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//名前付きイベントクローズ
	for (int i = 0; i < FOLLOW_THREAD_MAX; ++i)
	{
		CloseHandle(hPriorEvent[i]);
		CloseHandle(hFollowEvent[i]);
	}

	return EXIT_SUCCESS;
}

// End of file
