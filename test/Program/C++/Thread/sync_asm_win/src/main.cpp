//コンパイラスイッチ
#define CODE_TYPE 4// 0 ... CMPXCHG操作
                   // 1 ... CMPXCHG操作＋ウェイトループ
                   // 2 ... XCHG操作
                   // 3 ... XCHG操作＋ウェイトループ
                   // 4 ... BTS操作
                   // 5 ... BTS操作＋ウェイトループ
                   // 6 ... C++11 atomic
                   //-1 ... ロックなし

#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

#if CODE_TYPE != 6//C++11 std::atomic操作
//ロック取得用変数
static int s_lock = 0;
#else//CODE_TYPE == 6//C++11 std::atomic操作
#include <atomic>//C++11 アトミック型
std::atomic_flag s_lock;//ロック用変数
#endif//CODE_TYPE

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__declspec(thread) int s_tlsData = 0;

//ロック取得
//※CAS操作版
void lock()
{
#if CODE_TYPE == 0//CMPXCHG操作
	__asm								//インラインアセンブラ（VC++形式)
	{
	lock_loop:							//ループ用ラベル
		//ロック取得処理
		mov				eax, 0			//EAX ← 0（期待するフラグの値）
		mov				edx, 1			//EDX ← 1（ロック取得中のフラグの値）
		lock cmpxchg	[s_lock], edx	//LOCKプレフィックスでアトミック操作指定
										//[s_lock] == EAX(0）なら [s_lock] ← EDX(1)
										//[s_lock] != EAX(0）なら EAX ← [s_lock]
		jnz				lock_loop		//NZ(Non Zero)は [s_lock] != EAX であった場合に該当
										//他のスレッドがロック取得中ということなので、
										//ループ位置にジャンプしてやり直す
	}
#elif CODE_TYPE == 1//CMPXCHG操作＋ウェイトループ
	__asm								//インラインアセンブラ（VC++形式)
	{
	lock_loop:							//ループ用ラベル
		//ロック取得可能状態確認
		mov				eax, [s_lock]	//EAX ← [s_lock]
		test			eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz				lock_loop		//EAX != 0 なら、他のスレッドがロック取得中ということなので、
										//ループ位置にジャンプしてやり直す
		//実際のロック取得処理
		mov				edx, 1			//EDX ← 1（ロック取得中のフラグの値）
		lock cmpxchg	[s_lock], edx	//LOCKプレフィックスでアトミック操作指定
										//[s_lock] == EAX(0）なら [s_lock] ← EDX(1)
										//[s_lock] != EAX(0）なら EAX ← [s_lock]
		jnz				lock_loop		//NZ(Non Zero)は [s_lock] != EAX であった場合に該当
										//他のスレッドに先を越されてしまったので、
										//ループ位置にジャンプしてやり直す
	}
#elif CODE_TYPE == 2//XCHG操作
	__asm						//インラインアセンブラ（VC++形式)
	{
	lock_loop:					//ループ用ラベル
		//ロック取得処理
		mov		eax, 1			//EAX ← 1（ロック取得中のフラグの値）
		xchg	eax, [s_lock]	//XCHG命令は暗黙的なLOCKプレフィックスでアトミック操作指定
								//EAX ←→ [s_lock] （交換）
								//※EAX ← [s_lock], [s_lock] ← 1 になる
		test	eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz		lock_loop		//EAX == 0 なら、ロック取得成功なので終了
								//EAX != 0なら、他のスレッドがロック取得中ということなので、
								//ループ位置にジャンプしてやり直す
	}
#elif CODE_TYPE == 3//XCHG操作＋ウェイトループ
	__asm						//インラインアセンブラ（VC++形式)
	{
	lock_loop:					//ループ用ラベル
		//ロック取得可能状態確認
		mov		eax, [s_lock]	//EAX ← [s_lock]
		test	eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz		lock_loop		//EAX != 0 なら、他のスレッドがロック取得中ということなので、
								//ループ位置にジャンプしてやり直す
		//実際のロック取得処理
		mov		eax, 1			//EAX ← 1（ロック取得中のフラグの値）
		xchg	eax, [s_lock]	//XCHG命令は暗黙的なLOCKプレフィックスでアトミック操作指定
								//EAX ←→ [s_lock] （交換）
								//※EAX ← [s_lock], [s_lock] ← 1 になる
		test	eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz		lock_loop		//EAX != 0なら、他のスレッドに先を越されてしまったので、
								//ループ位置にジャンプしてやり直す
	}
#elif CODE_TYPE == 4//BTS操作
	__asm						//インラインアセンブラ（VC++形式)
	{
	lock_loop:					//ループ用ラベル
		//ロック取得処理
		lock bts	[s_lock], 0		//LOCKプレフィックスでアトミック操作指定
									//CF ← [s_lock:0], [s_lock:0] ← 1
		setb		al				//AL ← CF
		movzx		eax, al			//EAX ← AL
		test		eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz			lock_loop		//EAX != 0なら、他のスレッドがロック取得中ということなので、
									//ループ位置にジャンプしてやり直す
	}
#elif CODE_TYPE == 5//BTS操作＋ウェイトループ
	__asm						//インラインアセンブラ（VC++形式)
	{
	lock_loop:					//ループ用ラベル
		//ロック取得可能状態確認
		mov			eax, [s_lock]	//EAX ← [s_lock]
		test		eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz			lock_loop		//EAX != 0 なら、他のスレッドがロック取得中ということなので、
									//ループ位置にジャンプしてやり直す
		//実際のロック取得処理
		lock bts[s_lock], 0			//LOCKプレフィックスでアトミック操作指定
									//CF ← [s_lock:0], [s_lock:0] ← 1
		setb		al				//AL ← CF
		movzx		eax, al			//EAX ← AL
		test		eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz			lock_loop		//EAX != 0なら、他のスレッドに先を越されてしまったので、
									//ループ位置にジャンプしてやり直す
	}
#elif CODE_TYPE == 6//C++11 std::atomic操作
	while (s_lock.test_and_set());//ロックを取得するまで待機
#endif//CODE_TYPE
}

//ロック解放
void unlock()
{
#if CODE_TYPE == 0 || CODE_TYPE == 1 || CODE_TYPE == 2 || CODE_TYPE == 3//CMPXCHG操作 or XCHG操作
	__asm						//インラインアセンブラ（VC++形式)
	{
		mov		eax, 0			//EAX ← 0（ロック解放時のフラグの値）
		xchg	eax, [s_lock]	//XCHG命令は暗黙的なLOCKプレフィックスでアトミック操作指定
								//EAX ←→ [s_lock] （交換）
								//※EAX ← [s_lock], [s_lock] ← 0 になる
	}
#elif CODE_TYPE == 4 || CODE_TYPE == 5//BTS操作
	__asm						//インラインアセンブラ（VC++形式)
	{
		mov		eax, 0			//EAX ← 0（ロック解放時のフラグの値）
		xchg	eax, [s_lock]	//XCHG命令は暗黙的なLOCKプレフィックスでアトミック操作指定
								//EAX ←→ [s_lock] （交換）
								//※EAX ← [s_lock], [s_lock] ← 0 になる
	}
#elif CODE_TYPE == 6//C++11 std::atomic操作
	s_lock.clear();//ロック解放
#endif//CODE_TYPE
}

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
		//ロック取得
		lock();

		//データ表示（前）
		printf("%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//データ取得
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//データ更新
		++common_data;
		++tls_data;

		//若干ランダムでスリープ（0～4 msec）
		Sleep(rand() % 5);

		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//ロック解放
		unlock();

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
#if CODE_TYPE == 6//C++11 std::atomic操作
	s_lock.clear();//ロック状態を初期化
#endif//CODE_TYPE

	//スレッド作成
	static const int THREAD_NUM = 3;
	unsigned int tid[THREAD_NUM] = {};
	HANDLE hThread[THREAD_NUM] =
	{
		(HANDLE)_beginthreadex(nullptr, 0, threadFunc, "太郎", 0, &tid[0]),
		(HANDLE)_beginthreadex(nullptr, 0, threadFunc, "次郎", 0, &tid[1]),
		(HANDLE)_beginthreadex(nullptr, 0, threadFunc, "三郎", 0, &tid[2])
	};
	
	//スレッド終了待ち
	WaitForMultipleObjects(THREAD_NUM, hThread, true, INFINITE);

	//スレッドハンドルクローズ
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		CloseHandle(hThread[i]);
	}

	//インラインアセンブラでロックの取得と解放を大量に実行して時間を計測
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER begin;
		QueryPerformanceCounter(&begin);
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			//ロック取得
			lock();
			//ロック解放
			unlock();
		}
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		float duration = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
		printf("Assembler * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	return EXIT_SUCCESS;
}

// End of file
