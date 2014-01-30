#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <atomic>

#include <chrono> //時間計測用
#include <random> //乱数生成用

//スレッド情報
static const int FOLLOW_THREAD_MAX = 10;          //後続スレッド最大数
static volatile int s_followThreadNum = 0;        //後続スレッド数
static std::atomic<int> s_followThreadNo = 0;     //後続スレッド番号発番用
static volatile bool s_IsQuirProiorThread = false;//先行スレッド終了フラグ

//モニター用変数
enum E_PROCESS
{
	PRIOR_RUNNING, //先行処理実行中
	PRIOR_IDLE,    //先行処理アイドル状態
	FOLLOW_RUNNING,//後続処理実行中
	FOLLOW_IDLE,   //後続処理アイドル状態
};
static std::atomic<E_PROCESS> s_followFinished[FOLLOW_THREAD_MAX];//後続スレッド処理完了フラグ

//共有データ
static int s_commonData = 0;

//スレッド固有データ
__declspec(thread) int s_tlsData = 0;
//thread_local int s_tlsData = 0;//Visual C++ 2013 では thread_local キーワードが使えない

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

	//乱数
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time(0, 499);

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
			E_PROCESS prev = E_PROCESS::FOLLOW_IDLE;
			while (!s_followFinished[i].compare_exchange_weak(prev, E_PROCESS::PRIOR_RUNNING)){ prev = E_PROCESS::FOLLOW_IDLE; }
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
				s_followFinished[i].store(E_PROCESS::PRIOR_IDLE);
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
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

		//データ書き戻し
		s_commonData = common_data;
		s_tlsData = tls_data;

		//データ表示（後）
		printf("(P)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//先行スレッド処理完了：全待機スレッドを起床
		for (int i = 0; i < s_followThreadNum; ++i)
		{
			s_followFinished[i].store(E_PROCESS::PRIOR_IDLE);
		}

		//スレッド切り替えのためのスリープ
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	//	//スレッド切り替え
	//	std::this_thread::yield();//OSに任せて再スケジューリング
	}

	//終了
	printf("- end:(P)%s -\n", name);
	fflush(stdout);
}

//後続スレッド
void followThreadFunc(const char* name)
{
	//後続スレッド数カウントアップ
	const int thread_no = s_followThreadNo++;

	//開始
	printf("- begin:(F)[%d]%s -\n", thread_no, name);
	fflush(stdout);

	//乱数
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time(0, 499);

	//後続スレッド処理完了：待機スレッドを起床
	s_followFinished[thread_no].store(E_PROCESS::FOLLOW_IDLE);

	//処理
	while (1)
	{
		//先行スレッド処理完了待ち
		E_PROCESS prev = E_PROCESS::PRIOR_IDLE;
		while (!s_followFinished[thread_no].compare_exchange_weak(prev, E_PROCESS::FOLLOW_RUNNING)){ prev = E_PROCESS::PRIOR_IDLE; }

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
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

		//データ書き戻し
		s_tlsData = tls_data;

		//データ表示（後）
		printf("(F)[%d]%s: [AFTER]  commonData=%d, tlsData=%d\n", thread_no, name, s_commonData, s_tlsData);
		fflush(stdout);
		
		//後続スレッド処理完了：待機スレッドを起床
		s_followFinished[thread_no].store(E_PROCESS::FOLLOW_IDLE);

		//スレッド切り替えのためのスリープ
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	//	//スレッド切り替え
	//	std::this_thread::yield();//OSに任せて再スケジューリング
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
	static_assert(FOLLOW_THREAD_NUM <= FOLLOW_THREAD_MAX, "FOLLOW_THREAD_NUM is over.");
	s_followThreadNum = FOLLOW_THREAD_NUM;
	for (int i = 0; i < THREAD_NUM - 1; ++i)
		s_followFinished[i] = E_PROCESS::FOLLOW_IDLE;
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

	//アトミック変数の取得と解放を大量に実行して時間を計測
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		s_followFinished[0] = E_PROCESS::FOLLOW_IDLE;
		E_PROCESS prev = E_PROCESS::FOLLOW_IDLE;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::PRIOR_RUNNING)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::PRIOR_IDLE)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::FOLLOW_RUNNING)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::FOLLOW_IDLE)){}
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Watch-atomic * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//アトミック操作を大量に実行して時間を計測(2)
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		s_followFinished[0] = E_PROCESS::FOLLOW_IDLE;
		E_PROCESS prev = E_PROCESS::FOLLOW_IDLE;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::PRIOR_RUNNING, std::memory_order_relaxed, std::memory_order_relaxed)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::PRIOR_IDLE, std::memory_order_relaxed, std::memory_order_relaxed)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::FOLLOW_RUNNING, std::memory_order_relaxed, std::memory_order_relaxed)){}
			while (!s_followFinished[0].compare_exchange_weak(prev, E_PROCESS::FOLLOW_IDLE, std::memory_order_relaxed, std::memory_order_relaxed)){}
			
			//http://www.justsoftwaresolutions.co.uk/threading/intel-memory-ordering-and-c++-memory-model.html
			//【メモリオーダーの意味】（x86命令相当の場合）
			//Memory Ordering,           Store,         Load
			//------------------------- --------------- --------------
			//std::memory_order_relaxed  MOV[mem],reg   MOV reg,[mem]                             ←メモリバリアなし：メモリ更新と読み込みの順序性を保証しない
			//std::memory_order_consume  (n/a)          MOV reg,[mem]  (Data-Dependency Ordering) ←読み込み専用のメモリバリア（少し弱い）※ストア処理で使うとエラー（交換可）
			//std::memory_order_acquire  (n/a)          MOV reg,[mem]                             ←読み込み専用のメモリバリア　　　　　　※ストア処理で使うとエラー（交換可）
			//std::memory_order_release  MOV[mem],reg   (n/a)                                     ←書き込み専用のメモリバリア　　　　　　※ロード処理で使うとエラー（交換可）
			//std::memory_order_acq_rel  MOV[mem],reg   MOV reg,[mem] (acquire & release)         ←交換専用のメモリバリア　　　　　　　　※ロード／ストア処理で使うとエラー
			//std::memory_order_seq_cst  XCHG[mem],reg  MOV reg,[mem] (Sequential consistency)    ←読み書きメモリバリア（強力）　　　　　※デフォルト（必ずしも低速というわけでではない）
			//・Load  ... レジスタ ← メモリ
			//・Store ... レジスタ → メモリ
			
			//【処理サンプル】
			//std::atomic<int> o(1);
			//int v = 0;
			//v = o.load(std::memory_order_relaxed);//OK
			//v = o.load(std::memory_order_consume);//OK
			//v = o.load(std::memory_order_acquire);//OK
			////v = o.load(std::memory_order_release);//例外：Invalid Memory Order
			////v = o.load(std::memory_order_acq_rel);//例外：Invalid Memory Order
			//v = o.load(std::memory_order_seq_cst);//OK
			//o.store(v, std::memory_order_relaxed);//OK
			////o.store(v, std::memory_order_consume);//例外：Invalid Memory Order
			////o.store(v, std::memory_order_acquire);//例外：Invalid Memory Order
			//o.store(v, std::memory_order_release);//OK
			////o.store(v, std::memory_order_acq_rel);//例外：Invalid Memory Order
			//o.store(v, std::memory_order_seq_cst);//OK
			//o.exchange(2, std::memory_order_relaxed);//OK
			//o.exchange(3, std::memory_order_consume);//OK
			//o.exchange(4, std::memory_order_acquire);//OK
			//o.exchange(5, std::memory_order_release);//OK
			//o.exchange(6, std::memory_order_acq_rel);//OK
			//o.exchange(7, std::memory_order_seq_cst);//OK
			//v = 7;
			//v = o.compare_exchange_weak(v, 7, std::memory_order_relaxed, std::memory_order_relaxed);//条件成立時：OK
			//v = o.compare_exchange_weak(v, 7, std::memory_order_consume, std::memory_order_consume);//条件成立時：OK
			//v = o.compare_exchange_weak(v, 7, std::memory_order_acquire, std::memory_order_acquire);//条件成立時：OK
			////v = o.compare_exchange_weak(v, 7, std::memory_order_release, std::memory_order_release);//条件成立時：Assertion failed! _Order2 != memory_order_release
			////v = o.compare_exchange_weak(v, 7, std::memory_order_acq_rel, std::memory_order_acq_rel);//条件成立時：Assertion failed! _Order2 != memory_order_acq_rel
			//v = o.compare_exchange_weak(v, 7, std::memory_order_seq_cst, std::memory_order_seq_cst);//条件成立時：OK
			//v = o.compare_exchange_weak(v, 8, std::memory_order_relaxed, std::memory_order_relaxed);//条件不成立時：OK
			//v = o.compare_exchange_weak(v, 8, std::memory_order_consume, std::memory_order_consume);//条件不成立時：OK
			//v = o.compare_exchange_weak(v, 8, std::memory_order_acquire, std::memory_order_acquire);//条件不成立時：OK
			////v = o.compare_exchange_weak(v, 8, std::memory_order_release, std::memory_order_release);//条件不成立時：Assertion failed! _Order2 != memory_order_release
			////v = o.compare_exchange_weak(v, 8, std::memory_order_acq_rel, std::memory_order_acq_rel);//条件不成立時：Assertion failed! _Order2 != memory_order_acq_rel
			//v = o.compare_exchange_weak(v, 8, std::memory_order_seq_cst, std::memory_order_seq_cst);//条件不成立時：OK

			//【メモリ更新と読み込みの順序性保証】
			//CPUのメモリバリアを使うかどうか？
			//（例）下記のような処理で、スレッドＢは変数 b をチェックしているにもか関わらず、
			//      先に更新されたはずの変数 a の値が 12 と表示されないようなことが起こりえる。
			//      これは、CPUにメモリバリア命令が出されて順序性を保証しないと、CPUの最適化により、
			//      更新の順序が入れ替わることがあるため。（「アウト・オブ・オーダー実行」と呼ばれる最適化）
			//[グローバル変数]
			//volatile bool flg_a;
			//volatile bool flg_b;
			//volatile int val_a;
			//volatile int val_b;
			//[スレッドA]
			//val_a = 123;
			//flg_a = true;
			//if(flg_b)
			//    std::cout << val_b;
			//[スレッドB]
			//val_b = 789;
			//flg_b = true;
			//if(flg_a)
			//    std::cout << val_a;
			//※この問題は、必要な箇所で必要なメモリバリアを明示することで対処できる
			//[グローバル変数]
			//std::atmic<bool> flg_a;
			//std::atmic<bool> flg_b;
			//volatile int val_a;
			//volatile int val_b;
			//[スレッドA]
			//val_a = 123;
			//flg_a.store(true, std::memory_order_release);
			//if(flg_b.load(std::memory_order_acquire))
			//    std::cout << val_b;
			//[スレッドB]
			//val_b = 789;
			//flg_b.store(true, std::memory_order_release );
			//if(flg_a.load(std::memory_order_acquire))
			//    std::cout << val_a;

			//http://msdn.microsoft.com/ja-jp/library/hh874684.aspx
			//template<class Ty>
			//bool std::atomic::compare_exchange_***(Ty& Expected, Ty NewValue, std::memory_order SuccessOrder, std::memory_order FailureOrder) _NOEXCEPT;
			//・std::atomic::compare_exchange_weak()   ... *this  で弱いアトミックの比較および交換操作を実行します。 
			//・std::atomic::compare_exchange_strong() ... *this  に対してアトミックの比較および交換の操作を実行します。 
			//【共通】
			//    このアトミックの比較および交換の操作では、*this に格納されている値と Expected を比較します。
			//    値が等しい場合、操作は read-modify-write 操作を使用して、
			//    SuccessOrder によって指定されたメモリ順序制約を適用して、
			//    *this に格納された値を NewValue と置き換えます。
			//    値が等しくない場合、操作は *this に格納されている値を使用して Expected を置き換え、
			//    FailureOrder によって指定されたメモリ順序制約を適用します。 
			//
			//    2 番目の memory_order がないオーバーロードは、SuccessOrder の値に基づく暗黙の FailureOrder を使用します。
			//    SuccessOrder が memory_order_acq_rel の場合、FailureOrder は memory_order_acquire です。
			//    SuccessOrder が memory_order_release の場合、FailureOrder は memory_order_relaxed です。
			//    他のすべての場合、FailureOrder は SuccessOrder と等しくなります。
			//
			//    2 つの memory_order パラメーターを受け取るオーバーロードの場合、
			//    FailureOrder の値は memory_order_release または memory_order_acq_rel ではない必要があり、
			//    かつ SuccessOrder の値よりも強い値ではない必要があります。
			//
			//【compare_exchange_weak() のみの解説】
			//    比較された値が同一の場合、弱いアトミック比較および交換操作は交換を実行します。
			//    値が同じでない場合、操作による交換の実行は保証されません。
			//
			//【メソッドの使い分け】  http://d.hatena.ne.jp/yohhoy/20120725/p1
			//・アルゴリズム上、CAS操作をループで括る必要があれば compare_exchange_weak を利用する。
			//　（例：一般的なLock-Freeアルゴリズム実装など）
			//・アルゴリズム上の制約が無く、かつspurious failureを許容しない場合は compare_exchange_strong を利用する。
			//　（例：pthread spinlock相当のtrylock操作実装 * 2）
			//【メソッドの使い分け要約】
			//・ループ処理は compare_exchange_weak でOK。
			//・ループ処理以外の（交換の取りこぼしがあってはならない）場面では compare_exchange_strong を使用。
			//【SuccessOrderとFailureOrderの使い分け要約】
			//・SuccessOrderは、条件成立時の *this ← NewValue に用いられる。「読み書き可能」なメモリオーダーである必要がある。
			//・FailureOrderは、条件不成立時の Expected ← *this に用いられる。「書き込み可能」なメモリオーダーである必要がある。
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Watch-atomic * %d (memory barrier free) = %.6f sec\n", TEST_TIMES, duration);
	}

	return EXIT_SUCCESS;
}

// End of file
