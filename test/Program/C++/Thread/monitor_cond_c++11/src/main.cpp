#include <stdio.h>
#include <stdlib.h>

#include <condition_variable>
#include <mutex>
#include <thread>

#include <Windows.h> //時間計測用

//スレッド情報
static const int FOLLOW_THREAD_MAX = 10;          //後続スレッド最大数
static volatile LONG s_followThreadNum = 0;       //後続スレッド数
static volatile LONG s_followThreadNo = 0;        //後続スレッド番号発番用
static volatile bool s_IsQuirProiorThread = false;//先行スレッド終了フラグ

//条件変数
//※条件変数は、必ず条件変数＋ミューテックス＋変数のセットで扱う
static std::condition_variable s_followCond[FOLLOW_THREAD_MAX];//後続スレッド処理完了条件変数
static std::mutex s_followCondMutex[FOLLOW_THREAD_MAX];        //後続スレッド処理完了条件変数ミューテックス
static volatile bool s_followFinished[FOLLOW_THREAD_MAX];      //後続スレッド処理完了フラグ

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
void priorThreadFunc(const char* name)
{
	//開始
	printf("- begin:(P)%s -\n", name);
	fflush(stdout);

	//初期化
	s_IsQuirProiorThread = false;//先行処理終了フラグ

	//処理
	static const int LOOP_COUNT_MAX = 3;
	int loop_counter = 0;
	while (1)
	{
		//全後続スレッド処理完了待ち
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			{
				std::unique_lock<std::mutex> lock(s_followCondMutex[i]);//ロック取得（ブロックから抜ける時に自動解放）
				while (!s_followFinished[i])//待機終了条件を満たしていない場合
					s_followCond[i].wait(lock);//待機（ロック開放→待機→待機終了→ロック取得が行われる）
			}
		}

		//ループカウンタ進行＆終了判定
		if (loop_counter++ == LOOP_COUNT_MAX)
		{
			//処理終了
			printf("(P)%s: [QUIT]\n", name);
			fflush(stdout);
			
			//先行スレッド終了フラグ
			s_IsQuirProiorThread = true;
			
			//先行スレッド処理完了：全待機スレッドを起床
			for (int i = 0; i < s_followThreadNum; ++i)
			{
				{
					std::unique_lock<std::mutex> lock(s_followCondMutex[i]);//ロック取得（ブロックから抜ける時に自動解放）
					s_followFinished[i] = false;//後続スレッドの処理完了状態を解除
					s_followCond[i].notify_one();//解除待ちしているスレッドに通知
				}
			}

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

		//先行スレッド処理完了：全待機スレッドを起床
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			{
				std::unique_lock<std::mutex> lock(s_followCondMutex[i]);//ロック取得（ブロックから抜ける時に自動解放）
				s_followFinished[i] = false;//後続スレッドの処理完了状態を解除
				s_followCond[i].notify_one();//解除待ちしているスレッドに通知
			}
		}

		//スレッド切り替えのためのスリープ
		Sleep(0);
	//	//スレッド切り替え
	//	SwitchToThread();//OSに任せて再スケジューリング
	//	Yield();//廃止
	}

	//終了
	printf("- end:(P)%s -\n", name);
	fflush(stdout);
}

//後続スレッド
void followThreadFunc(const char* name)
{
	//後続スレッド数カウントアップ
	LONG thread_no = InterlockedIncrement(&s_followThreadNo) - 1;

	//開始
	printf("- begin:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);

	//継続スレッド処理完了：待機スレッドを起床
	{
		std::unique_lock<std::mutex> lock(s_followCondMutex[thread_no]);//ロック取得（ブロックから抜ける時に自動解放）
		s_followFinished[thread_no] = true;//後続スレッドの処理完了状態をON
		s_followCond[thread_no].notify_one();//解除待ちしているスレッドに通知
	}

	//処理
	while (1)
	{
		//先行スレッド処理完了待ち
		{
			std::unique_lock<std::mutex> lock(s_followCondMutex[thread_no]);//ロック取得（ブロックから抜ける時に自動解放）
			while (s_followFinished[thread_no])//待機終了条件を満たしていない場合
				s_followCond[thread_no].wait(lock);//待機（ロック開放→待機→待機終了→ロック取得が行われる）
		}

		//終了確認
		if (s_IsQuirProiorThread)
		{
			//処理終了
			printf("(F)[%d]%s: [QUIT]\n", thread_no, name);
			fflush(stdout);
			
			//継続スレッド処理完了：待機スレッドを起床
			{
				std::unique_lock<std::mutex> lock(s_followCondMutex[thread_no]);//ロック取得（ブロックから抜ける時に自動解放）
				s_followFinished[thread_no] = true;//後続スレッドの処理完了状態をON
				s_followCond[thread_no].notify_one();//解除待ちしているスレッドに通知
			}
			
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
		
		//継続スレッド処理完了：待機スレッドを起床
		{
			std::unique_lock<std::mutex> lock(s_followCondMutex[thread_no]);//ロック取得（ブロックから抜ける時に自動解放）
			s_followFinished[thread_no] = true;//後続スレッドの処理完了状態をON
			s_followCond[thread_no].notify_one();//解除待ちしているスレッドに通知
		}

		//スレッド切り替えのためのスリープ
		Sleep(0);
	//	//スレッド切り替え
	//	SwitchToThread();//OSに任せて再スケジューリング
	//	Yield();//廃止
	}

	//終了
	printf("- end:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);
}

//テスト
int main(const int argc, const char* argv[])
{
	//スレッド作成
	static const int FOLLOW_THREAD_NUM = 5;
	static const int THREAD_NUM = 1 + FOLLOW_THREAD_NUM;
	static_assert(FOLLOW_THREAD_NUM <= FOLLOW_THREAD_MAX, "THREAD_NUM is over.");
	s_followThreadNum = FOLLOW_THREAD_NUM;
	for (int i = 0; i < THREAD_NUM - 1; ++i)
		s_followFinished[i] = true;
	static_assert(THREAD_NUM - 1 <= FOLLOW_THREAD_MAX, "THREAD_NUM is over.");
	std::thread thread_obj00 = std::thread(priorThreadFunc, "先行");
	std::thread thread_obj01 = std::thread(followThreadFunc, "後続01");
	std::thread thread_obj02 = std::thread(followThreadFunc, "後続02");
	std::thread thread_obj03 = std::thread(followThreadFunc, "後続03");
	std::thread thread_obj04 = std::thread(followThreadFunc, "後続04");
	std::thread thread_obj05 = std::thread(followThreadFunc, "後続05");

	//スレッド終了待ち
	thread_obj00.join();
	thread_obj01.join();
	thread_obj02.join();
	thread_obj03.join();
	thread_obj04.join();
	thread_obj05.join();

	//イベントの取得と解放を大量に実行して時間を計測
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			{
				std::unique_lock<std::mutex> lock(s_followCondMutex[0]);
				s_followFinished[0] = true;
				s_followCond[0].notify_one();
			}
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float time = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Event * %d = %.6f sec\n", TEST_TIMES, time);
	}

	return EXIT_SUCCESS;
}

// End of file
