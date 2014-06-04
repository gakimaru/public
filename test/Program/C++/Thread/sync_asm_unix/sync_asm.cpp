//コンパイラスイッチ
#define CODE_TYPE 6// 0 ... CMPXCHG操作
                   // 1 ... CMPXCHG操作＋ウェイトループ
                   // 2 ... XCHG操作
                   // 3 ... XCHG操作＋ウェイトループ
                   // 4 ... BTS操作
                   // 5 ... BTS操作＋ウェイトループ
                   // 6 ... C++11 atomic
                   //-1 ... ロックなし

//#define thread_local __declspec(thread)//VC++版
#define thread_local __thread//GCC版

#include <stdio.h>
#include <stdlib.h>

#include <thread>//C++11 スレッド用
#include <chrono>//C++11 時間計測用

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
thread_local int s_tlsData = 0;

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
										//[s_lock] == EAX(0）なら、EAX ← [s_lock], [s_lock] ← EDX(1)
		jnz				lock_loop		//EAX == [s_lock]（交換が成功）ならロック取得成功なので終了
										//EAX != [s_lock]なら、他のスレッドに先を越されてしまったので、戻ってループする
	}
#elif CODE_TYPE == 1//CMPXCHG操作＋ウェイトループ
	__asm								//インラインアセンブラ（VC++形式)
	{
	lock_loop:							//ループ用ラベル
		//ロック取得可能状態確認
		mov				eax, [s_lock]	//EAX ← [s_lock]
		test			eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz				lock_loop		//EAX == 0 なら、次の実際のロック取得処理に移る
										//（次で失敗する可能性もある）
										//EAX != 0 なら、他のスレッドがロック取得中なので、戻ってループする
										//実際のロック取得処理
		mov				edx, 1			//EDX ← 1（ロック取得中のフラグの値）
		lock cmpxchg	[s_lock], edx	//LOCKプレフィックスでアトミック操作指定
										//[s_lock] == EAX(0）なら、EAX ← [s_lock], [s_lock] ← EDX(1)
		jnz				lock_loop		//EAX == [s_lock]（交換が成功）ならロック取得成功なので終了
										//EAX != [s_lock]なら、他のスレッドがロック取得中なので、戻ってループする
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
								//EAX != [s_lock]なら、他のスレッドがロック取得中なので、戻ってループする
	}
#elif CODE_TYPE == 3//XCHG操作＋ウェイトループ
	__asm						//インラインアセンブラ（VC++形式)
	{
	lock_loop:					//ループ用ラベル
		//ロック取得可能状態確認
		mov		eax, [s_lock]	//EAX ← [s_lock]
		test	eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz		lock_loop		//EAX == 0 なら、次の実際のロック取得処理に移る
								//（次で失敗する可能性もある）
								//EAX != 0 なら、他のスレッドがロック取得中なので、戻ってループする
		//実際のロック取得処理
		mov		eax, 1			//EAX ← 1（ロック取得中のフラグの値）
		xchg	eax, [s_lock]	//XCHG命令は暗黙的なLOCKプレフィックスでアトミック操作指定
								//EAX ←→ [s_lock] （交換）
								//※EAX ← [s_lock], [s_lock] ← 1 になる
		test	eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz		lock_loop		//EAX == 0 なら、ロック取得成功なので終了
								//EAX != 0なら、他のスレッドに先を越されてしまったので、戻ってループする
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
		jnz			lock_loop		//EAX == 0 なら、ロック取得成功なので終了
									//EAX != 0なら、他のスレッドに先を越されてしまったので、戻ってループする
	}
#elif CODE_TYPE == 5//BTS操作＋ウェイトループ
	__asm						//インラインアセンブラ（VC++形式)
	{
	lock_loop:					//ループ用ラベル
		//ロック取得可能状態確認
		mov			eax, [s_lock]	//EAX ← [s_lock]
		test		eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz			lock_loop		//EAX == 0 なら、次の実際のロック取得処理に移る
									//（次で失敗する可能性もある）
									//EAX != 0 なら、他のスレッドがロック取得中なので、戻ってループする
		//実際のロック取得処理
		lock bts[s_lock], 0			//LOCKプレフィックスでアトミック操作指定
									//CF ← [s_lock:0], [s_lock:0] ← 1
		setb		al				//AL ← CF
		movzx		eax, al			//EAX ← AL
		test		eax, eax		//EAX & EAX ? ※EAX == 0 かチェック
		jnz			lock_loop		//EAX == 0 なら、ロック取得成功なので終了
									//EAX != 0なら、他のスレッドに先を越されてしまったので、戻ってループする
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
unsigned int threadFunc(const char* param_p)
{
	//パラメータ受け取り
	const char* name = param_p;

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
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 5));

		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//ロック解放
		unlock();

		//スレッド切り替えのためのスリープ
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
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
	std::thread* hThread[THREAD_NUM] =
	{
		new std::thread(threadFunc, "太郎"),
		new std::thread(threadFunc, "次郎"),
		new std::thread(threadFunc, "三郎")
	};
	
	//スレッド終了待ち
	for (int i = 0; i < THREAD_NUM; ++i)
	{
		hThread[i]->join();
	}

	//インラインアセンブラでロックの取得と解放を大量に実行して時間を計測
	{
		auto begin_time = std::chrono::system_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			//ロック取得
			lock();
			//ロック解放
			unlock();
		}
		const auto now_time = std::chrono::system_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - begin_time);
		const double elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		printf("Assembler * %d = %.6f sec\n", TEST_TIMES, elapsed_time);
	}

	return EXIT_SUCCESS;
}

// End of file
