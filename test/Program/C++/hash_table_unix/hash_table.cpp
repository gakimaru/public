//--------------------------------------------------------------------------------
//ハッシュテーブルテスト用設定とコンパイラスイッチ
//static const int TEST_DATA_TABLE_SIZE = 500000;//テストデータテーブルサイズ
static const int TEST_DATA_TABLE_SIZE = 20;//テストデータテーブルサイズ

#define PRINT_TEST_DATA_DETAIL//テストデータの詳細を表示する場合は、このマクロを有効化する
//#define TEST_DATA_WATCH_CONSTRUCTOR//コンストラクタ／デストラクタ／代入演算子の動作を確認する場合、このマクロを有効化する

#define USE_GCC//GCC版でコンパイルするときは、このマクロを有効化する

#include <cstddef>//sｔd::size_t用

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------
//素数計算
//--------------------------------------------------------------------------------

#include <cstddef>//srd::size_t用
#include <type_traits>//C++11 std::conditional, std:integral_constant用

//----------------------------------------
//【ランタイム版】
//----------------------------------------

//----------------------------------------
//【ランタイム版】素数判定
bool isPrime(const std::size_t n)
{
	if (n < 2)//2未満は素数ではない
		return false;
	else if (n == 2)//2は素数
		return true;
	else if ((n & 1) == 0)//偶数は素数ではない
		return false;
	for (std::size_t div = 3; div <= n / div; div += 2)//div = 3～n/div の範囲で割り切れる値があるか判定
	{
		if (n % div == 0)//割り切れる値がみつかったら素数ではない
			return false;
	}
	return true;//素数と判定
}

//----------------------------------------
//【ランタイム版】指定の値より小さい最初の素数を算出
std::size_t makePrimeLT(const std::size_t n)
{
	if (n <= 2)//2より小さい素数はない
		return 0;
	else if (n == 3)//3の次に小さい素数は2
		return 2;
	for (std::size_t nn = n - ((n & 1) == 0 ? 1 : 2);; nn -= 2)//素数がみつかるまでループ ※偶数は判定しない
	{
		if (isPrime(nn))//素数判定
			return nn;
	}
	return 0;//dummy
}
//----------------------------------------
//【ランタイム版】指定の値と同じか、それより小さい最初の素数を算出
std::size_t makePrimeLE(const std::size_t n)
{
	return isPrime(n) ? n : makePrimeLT(n);
}

//----------------------------------------
//【ランタイム版】指定の値より大きい最初の素数を算出
std::size_t makePrimeGT(const std::size_t n)
{
	if (n < 2)//2未満の値より大きい最初の素数は2
		return 2;
	for (std::size_t nn = n + ((n & 1) == 0 ? 1 : 2);; nn += 2)//素数がみつかるまでループ ※偶数は判定しない
	{
		if (isPrime(nn))//素数判定
			return nn;
	}
	return 0;//dummy
}
//----------------------------------------
//【ランタイム版】指定の値と同じか、それより大きい最初の素数を算出
std::size_t makePrimeGE(const std::size_t n)
{
	return isPrime(n) ? n : makePrimeGT(n);
}

//----------------------------------------
//【メタプログラミング版】
//----------------------------------------

//----------------------------------------
//【メタプログラミング版】静的素数判定
//※偶数の判定を避けるために階層化する
//静的素数判定用の再帰クラス（直接使用しない）
template <std::size_t N, std::size_t DIV>
struct _isStaticPrime{
	typedef
		typename std::conditional<
			(DIV > N / DIV),//DIV = ～N/DIVの範囲で割り切れる値があるか判定
			std::integral_constant<bool, true>,//範囲を超えたので素数と判定
			typename std::conditional<
				(N % DIV == 0),//割り切れる値か判定
				std::integral_constant<bool, false>,//割り切れたので素数ではない
				_isStaticPrime<N, DIV + 2>//再帰で次の値が割り切れるか探索 ※偶数は判定しない
			>::type
		>::type
		type;
	static const bool value = type::value;
};
//静的素数判定クラス
template <std::size_t N>
struct isStaticPrime{
	typedef
		typename std::conditional<
			(N & 1) == 0,//偶数判定
			std::integral_constant<bool, false>,//偶数は素数ではない
			typename _isStaticPrime<N, 3>::type//素数判定ループ（再帰処理）呼び出し
		>::type
		type;
	static const bool value = type::value;
};
//特殊化：0は素数ではない
template <>
struct isStaticPrime<0>{
	static const bool value = false;
};
//特殊化：1は素数ではない
template <>
struct isStaticPrime<1>{
	static const bool value = false;
};
//特殊化：2は素数
template <>
struct isStaticPrime<2>{
	static const bool value = true;
};

//----------------------------------------
//【メタプログラミング版】指定の値より小さい最初の素数を静的に算出
//※偶数の判定を避けるために階層化する
//静的素数算出用の再帰クラス（直接使用しない）
template<std::size_t N>
struct _makeStaticPrimeLT{
	typedef
		typename std::conditional<
			isStaticPrime<N>::value,//素数判定
			std::integral_constant<std::size_t, N>,//素数が見つかった
			_makeStaticPrimeLT<N - 2>//再帰で次に小さい値を探索 ※偶数は判定しない
		>::type
		type;
	static const std::size_t value = type::value;
};
//静的素数算出クラス
template<std::size_t N>
struct makeStaticPrimeLT{
	typedef
		typename std::conditional<
			(N & 1) == 0,//素数判定ループの初期値を奇数にするための判定
			_makeStaticPrimeLT<N - 1>,//素数判定ループ（再帰処理）呼び出し
			_makeStaticPrimeLT<N - 2>//素数判定ループ（再帰処理）呼び出し
		>::type
		type;
	static const std::size_t value = type::value;
};
//特殊化：0より小さい素数はなし
template<>
struct makeStaticPrimeLT<0>{
	static const std::size_t value = 0;
};
//特殊化：1より小さい素数はなし
template<>
struct makeStaticPrimeLT<1>{
	static const std::size_t value = 0;
};
//特殊化：2より小さい素数はなし
template<>
struct makeStaticPrimeLT<2>{
	static const std::size_t value = 0;
};
//特殊化：3より小さい素数は2
template<>
struct makeStaticPrimeLT<3>{
	static const std::size_t value = 2;
};
//----------------------------------------
//【メタプログラミング版】指定の値と同じか、それより小さい最初の素数を静的に算出
//静的素数算出クラス
template<std::size_t N>
struct makeStaticPrimeLE{
	typedef
		typename std::conditional<
			isStaticPrime<N>::value,//指定の値が素数か？
			std::integral_constant<std::size_t, N>,//素数が見つかった
			makeStaticPrimeLT<N>//次に小さい値を探索
		>::type
	type;
	static const std::size_t value = type::value;
};

//----------------------------------------
//【メタプログラミング版】指定の値より大きい最初の素数を静的に算出
//※偶数の判定を避けるために階層化する
//静的素数算出用の再帰クラス（直接使用しない）
template<std::size_t N>
struct _makeStaticPrimeGT{
	typedef
		typename std::conditional<
			isStaticPrime<N>::value,//素数判定
			std::integral_constant<std::size_t, N>,//素数が見つかった
			_makeStaticPrimeGT<N + 2>//再帰で次に大きい値を探索 ※偶数は判定しない
		>::type
		type;
	static const std::size_t value = type::value;
};
//静的素数算出クラス
template<std::size_t N>
struct makeStaticPrimeGT{
	typedef
		typename std::conditional<
			(N & 1) == 0,//素数判定ループの初期値を奇数にするための判定
			_makeStaticPrimeGT<N + 1>,//素数判定ループ（再帰処理）呼び出し
			_makeStaticPrimeGT<N + 2>//素数判定ループ（再帰処理）呼び出し
		>::type
		type;
	static const std::size_t value = type::value;
};
//特殊化：0より大きい素数は2
template<>
struct makeStaticPrimeGT<0>{
	static const std::size_t value = 2;
};
//特殊化：1より大きい素数は2
template<>
struct makeStaticPrimeGT<1>{
	static const std::size_t value = 2;
};

//----------------------------------------
//【メタプログラミング版】指定の値と同じか、それより大きい最初の素数を静的に算出
//静的素数算出クラス
template<std::size_t N>
struct makeStaticPrimeGE{
	typedef
		typename std::conditional<
			isStaticPrime<N>::value,//指定の値が素数か？
			std::integral_constant<std::size_t, N>,//素数が見つかった
			makeStaticPrimeGT<N>//次に小さい値を探索
		>::type
		type;
	static const std::size_t value = type::value;
};

//--------------------------------------------------------------------------------
//【メタプログラミングの使用上の注意】
// メタプログラミング版では、コンパイラにより、テンプレートの
// インスタンス化の深度に限界がある。
// そのため、静的素数判定・算出では、扱える値に上限がある。
// VC++による実測では、上限は下記の通り。
//
//     static const bool        _is_prime = isStaticPrime<1262477>::value;   //限界OK ※次の isStaticPrime<1262479>    はコンパイルエラー
//     static const std::size_t _prime_gt = makeStaticPrimeGT<952788>::value;//限界OK ※次の makeStaticPrimeGT<952789> はコンパイルエラー
//
// makeStaticPrimeGTの結果からも分かるとおり、テンプレートをネストすると
// この限界値は更に下がっていく。
// また、大きな素数を指定すると、コンパイル時間が長くなっていく点にも注意。
// なお、単純に深度限界をチェックするテンプレートクラスを作ってテストした
// 結果は下記のとおり。
//
//     template<int N> struct recursive{ static const int value = recursive<N - 1>::value; };
//     template<>      struct recursive<0>{ static const int value = 1; };
//     static const int _n = recursive<499>::value;//VC++2013では限界OK ※次の recursive<500> はコンパイルエラー
//     static const int _n = recursive<900>::value;//GCC4.8.2では限界OK ※次の recursive<901> はコンパイルエラー
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//自作ロッククラス
//--------------------------------------------------------------------------------

#include <atomic>//C++11 std::atomic用
#include <thread>//C++11 std::this_thread::sleep_for用
#include <chrono>//C++11 std::chrono::milliseconds用

//--------------------------------------------------------------------------------
//スピンロック
//--------------------------------------------------------------------------------

//----------------------------------------
//スピンロッククラス
//※サイズは4バイト(std::atomic_flag一つ分のサイズ)
class spin_lock
{
public:
	//定数
	static const int DEFAULT_SPIN_COUNT = 1000;//スピンロックカウントのデフォルト値
public:
	//ロック取得
	void lock(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (true)
		{
			if (!m_lock.test_and_set())
				return;
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//ロック取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	inline bool try_lock()
	{
		return m_lock.test_and_set() == false;
	}
	//ロック解放
	inline void unlock()
	{
		m_lock.clear();
	}
public:
	//コンストラクタ
	inline spin_lock()
	{
		m_lock.clear();
	}
	//デストラクタ
	inline ~spin_lock()
	{}
private:
	//フィールド
	std::atomic_flag m_lock;//ロック用フラグ
};

//----------------------------------------
//スピンロッククラス（軽量版）
//※サイズは1バイト
//※spin_lockの方が速い
class lw_spin_lock
{
public:
	//ロック取得
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (true)
		{
			bool prev = false;
			if (!m_lock.compare_exchange_weak(prev, true))
				return;
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//ロック取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	inline bool try_lock()
	{
		bool prev = false;
		return m_lock.compare_exchange_weak(prev, true) == false;
	}
	//ロック解放
	inline void unlock()
	{
		m_lock.store(false);
	}
public:
	//コンストラクタ
	inline lw_spin_lock()
	{
		m_lock.store(false);//ロック用フラグ
	}
	//デストラクタ
	inline ~lw_spin_lock()
	{}
private:
	//フィールド
	std::atomic_bool m_lock;//ロック用フラグ
};

//----------------------------------------
//共有（リード・ライト）スピンロッククラス
//※サイズは4バイト
//※排他ロック（ライトロック）を優先する
//※読み込み操作（共有ロック）が込み合っている途中で割り込んで
//　書き込み操作（排他ロック）を行いたい時に用いる
//※排他ロックが常に最優先されるわけではない。
//　共有ロックがロックを開放する前に排他ロックがロックを
//　取得することを許可する仕組みで実装する。その場合、
//　共有ロックが全て解放されるのを待ってから処理を続行する。
//　そのため、別の排他ロックが待ち状態になっても、
//　共有ロックより先にロックを取得することは保証しない。
class shared_spin_lock
{
public:
	//定数
	static const int DEFAULT_COUNTER = 0x01000000;//ロックが取得されていない時のデフォルトのカウンタ

public:
	//共有ロック（リードロック）取得
	void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(1);//カウンタを更新
			if (lock_counter > 0)
				return;//ロック取得成功
			m_lockCounter.fetch_add(1);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//共有ロック（リードロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	bool try_lock_shared()
	{
		const int lock_counter = m_lockCounter.fetch_sub(1);//カウンタを更新
		if (lock_counter >= 0)
			return true;//ロック取得成功
		m_lockCounter.fetch_add(1);//カウンタを戻す
		return false;//ロック取得失敗
	}
	//排他ロック（ライトロック）取得
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(DEFAULT_COUNTER);//カウンタを更新
			if (lock_counter == DEFAULT_COUNTER)
				return;//ロック取得成功
			if (lock_counter > 0)	//他が排他ロックを取得していないので、現在の共有ロックが全て解放されるのを待つ
			{						//※カウンタを更新したままなので、後続の共有ロック／排他ロックは取得できない。
				while (m_lockCounter.load() != 0)//カウンタが0になるのを待つ
				{
					if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
					{
						std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
						spin_count_now = spin_count;
					}
				}
				return;//ロック取得成功
			}
			m_lockCounter.fetch_add(DEFAULT_COUNTER);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//排他ロック（ライトロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	bool try_lock()
	{
		const int lock_counter = m_lockCounter.fetch_sub(DEFAULT_COUNTER);//カウンタを更新
		if (lock_counter == DEFAULT_COUNTER)
			return true;//ロック取得成功
		m_lockCounter.fetch_add(DEFAULT_COUNTER);//カウンタを戻す
		return false;//ロック取得失敗
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		m_lockCounter.fetch_add(1);//カウンタを戻す
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		m_lockCounter.fetch_add(DEFAULT_COUNTER);//カウンタを戻す
	}
public:
	//コンストラクタ
	inline shared_spin_lock() :
		m_lockCounter(DEFAULT_COUNTER)
	{}
	//デストラクタ
	inline ~shared_spin_lock()
	{}
private:
	//フィールド
	std::atomic<int> m_lockCounter;//ロックカウンタ
};

//----------------------------------------
//共有（リード・ライト）スピンロッククラス（軽量版）
//※サイズは4バイト
//※排他ロック（ライトロック）を優先しない
//※読み込み操作（共有ロック）が込み合っていると、
//　書き込み操作（排他ロック）が待たされるので注意。
class lw_shared_spin_lock
{
public:
	//共有ロック（リードロック）取得
	void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(1);//カウンタを更新
			if (lock_counter > 0)
				return;//ロック取得成功
			m_lockCounter.fetch_add(1);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//共有ロック（リードロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	bool try_lock_shared()
	{
		const int lock_counter = m_lockCounter.fetch_sub(1);//カウンタを更新
		if (lock_counter >= 0)
			return true;//ロック取得成功
		m_lockCounter.fetch_add(1);//カウンタを戻す
		return false;//ロック取得失敗
	}
	//排他ロック（ライトロック）取得
	void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		int spin_count_now = spin_count;
		while (1)
		{
			const int lock_counter = m_lockCounter.fetch_sub(shared_spin_lock::DEFAULT_COUNTER);//カウンタを更新
			if (lock_counter == shared_spin_lock::DEFAULT_COUNTER)
				return;//ロック取得成功
			m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//カウンタを戻してリトライ
			if (spin_count == 1 || spin_count > 1 && --spin_count_now == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(0));//コンテキストスイッチ（ゼロスリープ）
				spin_count_now = spin_count;
			}
		}
	}
	//排他ロック（ライトロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	bool try_lock()
	{
		const int lock_counter = m_lockCounter.fetch_sub(shared_spin_lock::DEFAULT_COUNTER);//カウンタを更新
		if (lock_counter == shared_spin_lock::DEFAULT_COUNTER)
			return true;//ロック取得成功
		m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//カウンタを戻す
		return false;//ロック取得失敗
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		m_lockCounter.fetch_add(1);//カウンタを戻す
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		m_lockCounter.fetch_add(shared_spin_lock::DEFAULT_COUNTER);//カウンタを戻す
	}
public:
	//コンストラクタ
	inline lw_shared_spin_lock() :
		m_lockCounter(shared_spin_lock::DEFAULT_COUNTER)
	{}
	//デストラクタ
	inline ~lw_shared_spin_lock()
	{}
private:
	//フィールド
	std::atomic<int> m_lockCounter;//ロックカウンタ
};

//----------------------------------------
//非共有（排他）スピンロッククラス
//※サイズは4バイト
//※共有ロッククラスと同一のインターフェースで、
//　共有ロックを行わないクラス
//※共有ロックのヘルパークラスやロックガードを使用する処理に対して、
//　完全な排他制御を行いたい時に使用する。
class unshared_spin_lock
{
public:
	//共有ロック（リードロック）取得
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//共有ロック（リードロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	inline bool try_lock_shared()
	{
		return m_lock.try_lock();
	}
	//排他ロック（ライトロック）取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//排他ロック（ライトロック）取得を試行
	//※取得に成功した場合、trueが返るので、ロックを解放する必要がある
	inline bool try_lock()
	{
		return m_lock.try_lock();
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		m_lock.unlock();
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//コンストラクタ
	unshared_spin_lock() :
		m_lock()
	{}
	//デストラクタ
	~unshared_spin_lock()
	{}
private:
	//フィールド
	spin_lock m_lock;//ロックオブジェクト
};

//--------------------------------------------------------------------------------
//ダミーロック
//--------------------------------------------------------------------------------

//----------------------------------------
//ダミーロッククラス
//※spin_lockやstd::mutexと同様のロックインターフェースを持つが、実際には何もしないクラス
class dummy_lock
{
public:
	//ロック取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//何もしない
	}
	//ロック取得を試行
	inline bool try_lock()
	{
		//何もしない
		return true;
	}
	//ロック解放
	inline void unlock()
	{
		//何もしない
	}
public:
	//コンストラクタ
	inline dummy_lock()
	{}
	//デストラクタ
	~dummy_lock()
	{}
};

//----------------------------------------
//ダミー共有（リード・ライト）ロッククラス
//※shared_spin_lockやstd::shared_lockと同様のロックインターフェースを持つが、実際には何もしないクラス
class dummy_shared_lock
{
public:
	//共有ロック（リードロック）取得
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//何もしない
	}
	//共有ロック（リードロック）取得を試行
	inline bool try_lock_shared()
	{
		//何もしない
		return true;
	}
	//排他ロック（ライトロック）取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		//何もしない
	}
	//排他ロック（ライトロック）取得を試行
	inline bool try_lock()
	{
		//何もしない
		return true;
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		//何もしない
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		//何もしない
	}
public:
	//コンストラクタ
	inline dummy_shared_lock()
	{}
	//デストラクタ
	~dummy_shared_lock()
	{}
};

//--------------------------------------------------------------------------------
//ロックヘルパー
//--------------------------------------------------------------------------------

//----------------------------------------
//ロックヘルパークラス
//※実装を隠ぺいしてロックを操作するためのヘルパークラス
template<class T>
class lock_helper
{
public:
	typedef T lock_type;//ロックオブジェクト型
public:
	//メソッド

	//ロック取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//ロック取得を試行
	inline bool try_lock()
	{
		return m_lock.try_lock();
	}
	//ロック解放
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//コンストラクタ
	inline lock_helper(lock_type& lock) :
		m_lock(lock)
	{}
	//デストラクタ
	inline ~lock_helper()
	{}
private:
	//フィールド
	lock_type& m_lock;//ロックオブジェクトの参照
};

//----------------------------------------
//共有（リード・ライト）ロックヘルパークラス
//※実装を隠ぺいして共有（リード・ライト）ロックを操作するためのヘルパークラス
template<class T>
class shared_lock_helper
{
public:
	typedef T lock_type;//ロックオブジェクト型
public:
	//メソッド

	//共有ロック（リードロック）取得
	inline void lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock_shared(spin_count);
	}
	//共有ロック（リードロック）取得を試行
	inline bool try_lock_shared(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		return m_lock.try_lock_shared(spin_count);
	}
	//排他ロック（ライトロック）取得
	inline void lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		m_lock.lock(spin_count);
	}
	//排他ロック（ライトロック）取得を試行
	inline bool try_lock(const int spin_count = spin_lock::DEFAULT_SPIN_COUNT)
	{
		return m_lock.try_lock(spin_count);
	}
	//共有ロック（リードロック）解放
	inline void unlock_shared()
	{
		m_lock.unlock_shared();
	}
	//排他ロック（ライトロック）解放
	inline void unlock()
	{
		m_lock.unlock();
	}
public:
	//コンストラクタ
	inline shared_lock_helper(lock_type& lock) :
		m_lock(lock)
	{}
	//デストラクタ
	inline ~shared_lock_helper()
	{}
private:
	//フィールド
	lock_type& m_lock;//ロックオブジェクトの参照
};

//--------------------------------------------------------------------------------
//ロックガード（スコープロック）
//--------------------------------------------------------------------------------

//----------------------------------------
//ロックガードクラス（スコープロック）
//※スコープロックで通常ロックもしくは排他ロック（ライトロック）のロック取得と解放を行う
template<class T>
class lock_guard
{
public:
	typedef T lock_type;//ロックオブジェクト型
public:
	//コンストラクタ
	inline lock_guard(lock_type& lock, const int spin_count = spin_lock::DEFAULT_SPIN_COUNT) :
		m_lock(lock)
	{
		m_lock.lock(spin_count);
	}
	//デストラクタ
	inline ~lock_guard()
	{
		m_lock.unlock();
	}
private:
	//フィールド
	lock_type& m_lock;//ロックオブジェクトの参照
};

//----------------------------------------
//共有（リード・ライト）ロックガードクラス（スコープロック）
//※スコープロックで共有ロック（リードロック）のロック取得と解放を行う
template<class T>
class shared_lock_guard
{
public:
	typedef T lock_type;//ロックオブジェクト型
public:
	//コンストラクタ
	inline shared_lock_guard(lock_type& lock, const int spin_count = spin_lock::DEFAULT_SPIN_COUNT) :
		m_lock(lock)
	{
		m_lock.lock_shared(spin_count);
	}
	//デストラクタ
	inline ~shared_lock_guard()
	{
		m_lock.unlock_shared();
	}
private:
	//フィールド
	lock_type& m_lock;//ロックオブジェクトの参照
};

//--------------------------------------------------------------------------------
//ハッシュテーブル
//--------------------------------------------------------------------------------
//データ構造とアルゴリズム
//【特徴】
//・ダブルハッシュアルゴリズムを採用。
//　  - ハッシュ① ... 最初のインデックス。キーに応じて生成。
//　  - ハッシュ② ... 衝突の際のインデックスの歩幅。キーに応じて生成。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【本プログラムにおける実装要件】
//・固定配列で実装し、一切メモリ確保・削除をしない。
//・キー重複を許容しないアルゴリズムとする。
//・文字列（std::string/char*）のキーをサポートしない。
//・代わりに、文字列キーは自動的にcrc32変換を行う。（文字列は保持しない）
//・処理効率化のために、データの削除時は実際に削除せず、
//　削除済みフラグを用いるものとする。
//　※検索処理は、削除済みのデータを検出しても打ち切らないことで効率化する。
//　※このため、頻繁に登録／削除を繰り返すと、未登録データ検索時の
//　　速度が劣化する可能性がある。
//・STL（std::unodered_map）との違いは下記の通り
//    - 固定長配列である。（STLは自動拡張する）
//    - 衝突時は開番地方を用いて処理し、メモリ操作を行わない。
//        ※STLは（おそらく）連鎖法。STLの方が速いが、より多くのメモリを必要とする。
//    - リハッシュは削除済みデータを掃除するのみ。
//    - キーと値のペア（std::pair）で扱わず、基本的にキーと値を直接扱う。
//      その代わり、イテレータにはインデックスやキーなどの情報を含む。
//　　- insert/erase時のイテレータ指定に対応しない。
//    - 赤黒木コンテナ（rb_tree）の実装と合わせた構造にしており、
//　　  操作用テンプレート構造体を用いる。
//--------------------------------------------------------------------------------

#include <bitset>//std::bitset用
#include <cstddef>//srd::size_t用
#include <iterator>//std::iterator用
#include <utility>//std::move用
#include <string>//std::string用

#ifdef USE_GCC
#include "../StaticCRC32_unix/constexpr.h"
#else//USE_GCC
#include "../../StaticCRC32/StaticCRC32/src/constexpr/constexpr.h"
#endif//USE_GCC

namespace hash_table
{
	//--------------------
	//ハッシュテーブルデータ操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public hash_table::base_ope_t<派生構造体, キー型, 値型, キーの最小値= 0u, キーの最大値 = 0xffffffffu, 不正なキー = 0xffffffffu>
	//	struct ope_t : public hash_table::base_ope_t<ope_t, crc32_t, data_t, 500>
	//	{
	//		//データ置換属性 ※必要に応じて定義
	//		static const replace_attr_t REPLACE_ATTR = REPLACE;//キーが重複するデータは置換して登録する
	//
	//		//キーを取得 ※必要に応じて定義
	//		inline static key_type getKey(const value_type& value){ return ???; }
	//		
	//		//ロック型 ※必要に応じて定義
	//		//※共有ロック（リード・ライトロック）でコンテナ操作をスレッドセーフにしたい場合は、
	//		//　有効な共有ロック型（shared_spin_lockなど）を lock_type 型として定義する。
	//		typedef shared_spin_lock lock_type;//ロックオブジェクト型
	//	};
	template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	struct base_ope_t
	{
		//定数
		static const KEY_TYPE KEY_MIN = _KEY_MIN;//キーの最小値
		static const KEY_TYPE KEY_MAX = _KEY_MAX;//キーの最大値
		static const KEY_TYPE INVALID_KEY = _INVALID_KEY;//不正なキー
		
		//データ置換属性
		enum replace_attr_t
		{
			NEVER_REPLACE,//キーが重複するデータは登録できない（置換しない）
			REPLACE,//キーが重複するデータは置換して登録する
		};
		static const replace_attr_t REPLACE_ATTR = NEVER_REPLACE;//キーが重複するデータは登録できない（置換しない）

		//型
		typedef OPE_TYPE ope_type;//データ操作型
		typedef VALUE_TYPE value_type;//値型
		typedef KEY_TYPE key_type;//キー型

		//ロック型
		typedef dummy_shared_lock lock_type;//ロックオブジェクト型
		//※デフォルトはダミーのため、一切ロック制御しない。
		//※共有ロック（リード・ライトロック）でコンテナ操作をスレッドセーフにしたい場合は、
		//　base_ope_tの派生クラスにて、有効な共有ロック型（shared_spin_lock など）を
		//　lock_type 型として再定義する。
		//【補足①】コンテナには、あらかじめロック制御のための仕組みがソースコードレベルで
		//　　　　　仕込んであるが、有効な型を与えない限りは、実行時のオーバーヘッドは一切ない。
		//【補足②】スレッドセーフ化した場合、書き込み時の排他ロックは行われるようになるが、
		//　　　　　読み込み時の共有ロックは行っていない。読み込み時のロックは局所的なロックで
		//　　　　　済まないため、ユーザーが任意に対応しなければならない。
		//　　　　　（例）
		//　　　　　    {
		//　　　　　        shared_lock_guard lock(container);//コンテナオブジェクトを渡して共有ロック
		//　　　　　                                          //※コンテナオブジェクトはロック
		//　　　　　                                          //　オブジェクト（lock_type）として振る舞える
		//　　　　　        //...
		//　　　　　        //一連のイテレータ操作など
		//　　　　　        //...
		//　　　　　    }//スコープを抜ける時に自動的にロック解放

		//デストラクタ呼び出し
		static void callDestructor(value_type* obj){ obj->~VALUE_TYPE(); }
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::value_type value_type; \
		typedef typename ope_type::key_type key_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef std::size_t index_type; \
		typedef typename ope_type::lock_type lock_type;
	//----------------------------------------
	//ハッシュテーブルコンテナ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _AUTO_REHASH_RATIO = 25, int _FINDING_CYCLE_LIMIT = 0, std::size_t _INDEX_STEP_BASE = 5>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//定数
		static const size_type ORIGINAL_TABLE_SIZE = _TABLE_SIZE;//テーブルサイズ（元々指定されたサイズ）
		static const size_type TABLE_SIZE = makeStaticPrimeGE<ORIGINAL_TABLE_SIZE>::value;//テーブルサイズ（指定サイズと同じか、それより大きい素数）
		static const size_type TABLE_SIZE_EXTENDED = TABLE_SIZE - ORIGINAL_TABLE_SIZE;//指定サイズから拡張したサイズ
		static const size_type  AUTO_REHASH_RATIO = _AUTO_REHASH_RATIO;//自動リハッシュ実行の基準割合 ※削除済み件数が全体サイズの一定割合以上になったら自動リハッシュ ※0で自動リハッシュなし
		static const size_type  AUTO_REHASH_SIZE = AUTO_REHASH_RATIO == 0 ? 0 : TABLE_SIZE * AUTO_REHASH_RATIO / 100;//自動リハッシュ実行の基準サイズ ※割合とテーブルサイズから計算
		static const int FINDING_CYCLE_LIMIT = _FINDING_CYCLE_LIMIT;//検索時の巡回回数の制限 ※0で無制限
		static const key_type KEY_MIN = ope_type::KEY_MIN;//キーの最小値
		static const key_type KEY_MAX = ope_type::KEY_MAX;//キーの最大値
		static const index_type INDEX_STEP_BASE = _INDEX_STEP_BASE;//検索巡回時のインデックスのス歩幅の基準値 ※必ず素数でなければならない
		static const index_type INVALID_INDEX = 0xffffffffu;//無効なインデックス
	public:
		//メタ関数
		//キー範囲定数計算（２バリエーション）
		template <bool COND, typename size_type, typename key_type, key_type KEY_MIN, key_type KEY_MAX>
		struct calcKeyRangeImpl{
			static const key_type value = KEY_MAX - KEY_MIN + 1;
		};
		template <typename size_type, typename key_type, key_type KEY_MIN, key_type KEY_MAX>
		struct calcKeyRangeImpl<true, size_type, key_type, KEY_MIN, KEY_MAX>{
			static const key_type value = 0;
		};
		//インデックス計算関数（２バリエーション）
		template <bool COND, typename size_type, typename index_type, typename key_type, size_type TABLE_SIZE, key_type KEY_MIN, key_type KEY_RANGE>
		struct calcIndexImpl{
			inline static index_type calc(const key_type key){ return (key - KEY_MIN) % TABLE_SIZE; }//キーからインデックスを計算 ※キーの範囲がテーブルサイズより大きい場合
		};
		template <typename size_type, typename index_type, typename key_type, size_type TABLE_SIZE, key_type KEY_MIN, key_type KEY_RANGE>
		struct calcIndexImpl<true, size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE>{
			inline static index_type calc(const key_type key){ return (key - KEY_MIN) * (TABLE_SIZE / KEY_RANGE) % TABLE_SIZE; }//キーからインデックスを計算 ※キーの範囲がテーブルサイズ以下の場合
		};
	public:
		//定数
		static const key_type KEY_RANGE = calcKeyRangeImpl<((KEY_MIN == 0u && KEY_MAX == 0xffffffffu) || KEY_MIN >= KEY_MAX), size_type, key_type, KEY_MIN, KEY_MAX>::value;//キーの範囲
		//静的アサーション
		static_assert(TABLE_SIZE > INDEX_STEP_BASE, "hash_table::container: TABLE_SIZE is required larger than INDEX_STEP_BASE.");
		static_assert(isStaticPrime<INDEX_STEP_BASE>::value == true, "hash_table::container: INDEX_STEP_BASE is required prime.");
	public:
		//--------------------
		//イテレータ用の型
		struct set
		{
			//フィールド
			index_type m_index;//（実際の）インデックス
			index_type m_primaryIndex;//本来のインデックス
			key_type m_key;//現在のキー
			value_type* m_value;//現在の値
			bool m_isDeleted;//削除済み

			//オペレータ
			inline const value_type& operator*() const { return m_value; }
			inline value_type& operator*(){ return m_value; }
			inline const value_type* operator->() const { return m_value; }
			inline value_type* operator->(){ return m_value; }

			//ムーブオペレータ
			inline set& operator=(const set&& rhs)
			{
				m_index = rhs.m_index;
				m_primaryIndex = rhs.m_primaryIndex;
				m_key = rhs.m_key;
				m_value = rhs.m_value;
				m_isDeleted = rhs.m_isDeleted;
				return *this;
			}
			//コピーオペレータ
			inline set& operator=(const set& rhs)
			{
				//return operator=(std::move(rhs));
				m_index = rhs.m_index;
				m_primaryIndex = rhs.m_primaryIndex;
				m_key = rhs.m_key;
				m_value = rhs.m_value;
				m_isDeleted = rhs.m_isDeleted;
				return *this;
			}
			
			//メソッド
			inline bool isPrimaryIndex() const { return m_index == m_primaryIndex; }//実際のインデックスは、本来のインデックスと一致するか？
			inline void update(const index_type index, const index_type primary_index, const key_type key, const value_type* value, const bool is_deleted)
			{
				m_index = index;
				m_primaryIndex = primary_index;
				m_key = key;
				m_value = const_cast<value_type*>(value);
				m_isDeleted = is_deleted;
			}

			//ムーブコンストラクタ
			inline set(const set&& obj) :
				m_index(obj.m_index),
				m_primaryIndex(obj.m_primaryIndex),
				m_key(obj.m_key),
				m_value(obj.m_value),
				m_isDeleted(obj.m_isDeleted)
			{}
			//コピーコンストラクタ
			inline set(const set& obj) :
				m_index(obj.m_index),
				m_primaryIndex(obj.m_primaryIndex),
				m_key(obj.m_key),
				m_value(obj.m_value),
				m_isDeleted(obj.m_isDeleted)
			{}
			//コストラクタ
			inline set(const index_type index, const index_type primary_index, const key_type key, const value_type* value, const bool is_deleted) :
				m_index(index),
				m_primaryIndex(primary_index),
				m_key(key),
				m_value(const_cast<value_type*>(value)),
				m_isDeleted(is_deleted)
			{}
		};
	public:
		//--------------------
		//イテレータ宣言
		class iterator;
		class reverse_iterator;
		typedef const iterator const_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		//--------------------
		//イテレータ
		//class iterator : public std::iterator<std::forward_iterator_tag, value_type>//本来は std::forward_iterator_tag で十分
		class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
		{
			friend class container;
			friend class reverse_iterator;
		public:
			//キャストオペレータ
			inline operator bool() const { return isExist(); }
			inline operator const set&() const { return getSet(); }
			inline operator set&(){ return getSet(); }
			inline operator const value_type&() const { return *getValue(); }
			inline operator value_type&(){ return *getValue(); }
			inline operator const value_type*() const { return getValue(); }
			inline operator value_type*(){ return getValue(); }
			inline operator key_type() const { return getKey(); }
		public:
			//オペレータ
			inline const set& operator*() const { return getSet(); }
			inline set& operator*(){ return getSet(); }
			inline const_pointer operator->() const { return getValue(); }
			inline pointer operator->(){ return getValue(); }
		#if 1//std::forward_iterator_tag, std::bidirectional_iterator_tag には本来必要ではない
			inline const_iterator operator[](const int index) const
			{
				iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
			inline iterator operator[](const int index)
			{
				iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
		#endif
			//比較オペレータ
			inline bool operator==(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       m_set.m_index == rhs.index;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? false :
				       m_isEnd || rhs.m_isEnd ? true :
				       m_set.m_index != rhs.m_set.m_index;
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && !rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       m_set.m_index > rhs.m_set.m_index;
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd && !rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       m_set.m_index >= rhs.m_set.m_index;
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       !m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       m_set.m_index < rhs.m_set.m_index;
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return !isEnabled() || !rhs.isEnabled() ? false :
				       m_isEnd && rhs.m_isEnd ? true :
				       !m_isEnd && rhs.m_isEnd ? true :
				       m_isEnd || rhs.m_isEnd ? false :
				       m_set.m_index <= rhs.m_set.m_index;
			}
			//演算オペレータ
			inline const_iterator& operator++() const
			{
				updateNext();
				return *this;
			}
			inline const_iterator& operator--() const
			{
				updatePrev();
				return *this;
			}
			inline iterator& operator++()
			{
				updateNext();
				return *this;
			}
			inline iterator& operator--()
			{
				updatePrev();
				return *this;
			}
			inline const_iterator operator++(int) const
			{
				iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline const_iterator& operator+=(const typename iterator::difference_type rhs) const
			{
				updateForward(rhs);
				return *this;
			}
			inline const_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline const_iterator& operator-=(const typename iterator::difference_type rhs) const
			{
				updateBackward(rhs);
				return *this;
			}
			inline const_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator+=(const typename iterator::difference_type rhs)
			{
				updateForward(rhs);
				return *this;
			}
			inline iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline iterator& operator-=(const typename iterator::difference_type rhs)
			{
				updateBackward(rhs);
				return *this;
			}
			inline iterator& operator-=(const std::size_t rhs)
			{
				return operator-=(static_cast<typename iterator::difference_type>(rhs));
			}
			inline const_iterator operator+(const typename iterator::difference_type rhs) const
			{
				iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline const_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline const_iterator operator-(const typename iterator::difference_type rhs) const
			{
				iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline const_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator+(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename iterator::difference_type>(rhs)));
			}
			inline iterator operator-(const typename iterator::difference_type rhs)
			{
				iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename iterator::difference_type>(rhs)));
			}
			//inline typename iterator::difference_type operator-(const iterator rhs)
			//{
			//	return ???;
			//}
		public:
			//ムーブオペレータ
			inline iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_set = std::move(rhs.m_set);
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
		#if 1//std::forward_iterator_tag には本来必要ではない
			iterator& operator=(const_reverse_iterator&& rhs);
		#endif
			//コピーオペレータ
			inline iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_set = rhs.m_set;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
		#if 1//std::forward_iterator_tag には本来必要ではない
			iterator& operator=(const_reverse_iterator& rhs);
		#endif
		public:
			//アクセッサ
			inline bool isExist() const { return m_set.m_index != INVALID_INDEX; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_set.m_index != INVALID_INDEX || m_isEnd; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_isEnd; }//終端か？
			inline const set& getSet() const { return m_set; }//現在のセット
			inline set& getSet(){ return m_set; }//現在のセット
			inline index_type getIndex() const { return m_set.m_index; }//（実際の）インデックス
			inline index_type getPrimaryIndex() const { return m_set.m_primaryIndex; }//本来のインデックス
			inline key_type getKey() const { return m_set.m_key; }//現在のキー
			inline const value_type* getValue() const { return m_set.m_value; }//現在の値
			inline value_type* getValue(){ return m_set.m_value; }//現在の値
			inline bool isDeleted() const { return m_set.m_isDeleted; }//削除済み
			inline bool isPrimaryIndex() const { return m_set.isPrimaryIndex(); }//本来のインデックスか？
		private:
			//メソッド
			index_type update(const index_type index) const
			{
				//if (index == INVALID_INDEX || index < 0 || index >= static_cast<index_type>(m_con->m_size))
				if (index >= static_cast<index_type>(TABLE_SIZE))
					m_set.update(INVALID_INDEX, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
				else
					m_set.update(index, m_con->calcIndex(m_con->m_keyTable[index]), m_con->m_keyTable[index], reinterpret_cast<const value_type*>(m_con->m_table[index]), m_con->m_deleted[index]);
				return m_set.m_index;
			}
			inline void updateNext() const
			{
				const index_type prev_index = m_set.m_index;
				const index_type index = update(m_con->getNextIndex(prev_index));
				m_isEnd = (prev_index != INVALID_INDEX && index == INVALID_INDEX);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					update(m_con->getLastIndex());
					m_isEnd = false;
					return;
				}
				update(m_con->getPrevIndex(m_set.m_index));
				m_isEnd = false;
			}
			void updateForward(const int step) const
			{
				int _step = step;
				const index_type prev_index = m_set.m_index;
				index_type index = prev_index;
				while (_step > 0 && index != INVALID_INDEX)
				{
					index = m_con->getNextIndex(index);
					--_step;
				}
				update(index);
				m_isEnd = (index != INVALID_INDEX && index == INVALID_INDEX && _step == 0);
			}
			void updateBackward(const int step) const
			{
				int _step = step;
				index_type index = m_set.m_index;
				if (_step > 0 && m_isEnd)
				{
					index = m_con->getLastIndex();
					--_step;
				}
				while (_step > 0 && index != INVALID_INDEX)
				{
					index = m_con->getPrevIndex(index);
					--_step;
				}
				update(index);
				m_isEnd = false;
			}
		public:
			//ムーブコンストラクタ
			iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_set(std::move(obj.m_set)),
				m_isEnd(obj.m_isEnd)
			{}
		#if 1//std::forward_iterator_tag には本来必要ではない
			iterator(const_reverse_iterator&& obj);
		#endif
			//コピーコンストラクタ
			inline iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_set(obj.m_set),
				m_isEnd(obj.m_isEnd)
			{}
		#if 1//std::forward_iterator_tag には本来必要ではない
			iterator(const_reverse_iterator& obj);
		#endif
			//コンストラクタ
			inline iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_set(INVALID_INDEX, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false),
				m_isEnd(is_end)
			{
				if (!is_end)
					update(m_con->getFirstIndex());//先頭インデックス
			}
			inline iterator() :
				m_con(nullptr),
				m_set(INVALID_INDEX, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false),
				m_isEnd(false)
			{}
			//デストラクタ
			inline ~iterator()
			{}
		protected:
			//フィールド
			const container* m_con;//コンテナ
			mutable set m_set;//現在のキー/値/削除済みフラグ
			mutable bool m_isEnd;//終端か？
		};
	#if 1//std::forward_iterator_tag には本来必要ではない
		//--------------------
		//リバースイテレータ
		//class reverse_iterator : public std::reverse_iterator<iterator>
		class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
		{
			friend class container;
			friend class iterator;
		public:
			//キャストオペレータ
			inline operator bool() const { return isExist(); }
			inline operator const set&() const { return getSet(); }
			inline operator set&(){ return getSet(); }
			inline operator const value_type&() const { return *getValue(); }
			inline operator value_type&(){ return *getValue(); }
			inline operator const value_type*() const { return getValue(); }
			inline operator value_type*(){ return getValue(); }
			inline operator key_type() const { return getKey(); }
		public:
			//オペレータ
			inline const set& operator*() const { return getSet(); }
			inline set& operator*(){ return getSet(); }
			inline const_pointer operator->() const { return getValue(); }
			inline pointer operator->(){ return getValue(); }
		#if 1//std::forward_iterator_tag, std::bidirectional_iterator_tag には本来必要ではない
			inline const_reverse_iterator operator[](const int index) const
			{
				reverse_iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
			inline reverse_iterator operator[](const int index)
			{
				reverse_iterator ite(*m_con, false);
				ite += index;
				return std::move(ite);
			}
		#endif
		public:
			//比較オペレータ
			inline bool operator==(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       rhs.m_set.m_index == m_set.m_index;
			}
			inline bool operator!=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? false :
				       rhs.m_isEnd || m_isEnd ? true :
				       rhs.m_set.m_index != m_set.m_index;
			}
			inline bool operator>(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && !m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       rhs.m_set.m_index > m_set.m_index;
			}
			inline bool operator>=(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd && !m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       rhs.m_set.m_index >= m_set.m_index;
			}
			inline bool operator<(const_reverse_iterator& rhs) const
			{
				return !rhs.isEnabled() || !isEnabled() ? false :
				       !rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       rhs.m_set.m_index < m_set.m_index;
			}
			inline bool operator<=(const_reverse_iterator& rhs) const
			{
				return !isEnabled() || !isEnabled() ? false :
				       rhs.m_isEnd && m_isEnd ? true :
				       !rhs.m_isEnd && m_isEnd ? true :
				       rhs.m_isEnd || m_isEnd ? false :
				       rhs.m_set.m_index <= m_set.m_index;
			}
			//演算オペレータ
			inline const_reverse_iterator& operator++() const
			{
				updateNext();
				return *this;
			}
			inline const_reverse_iterator& operator--() const
			{
				updatePrev();
				return *this;
			}
			inline reverse_iterator& operator++()
			{
				updateNext();
				return *this;
			}
			inline reverse_iterator& operator--()
			{
				updatePrev();
				return *this;
			}
			inline const_reverse_iterator operator++(int) const
			{
				reverse_iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline const_reverse_iterator operator--(int) const
			{
				reverse_iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline reverse_iterator operator++(int)
			{
				reverse_iterator ite(*this);
				++(*this);
				return std::move(ite);
			}
			inline reverse_iterator operator--(int)
			{
				reverse_iterator ite(*this);
				--(*this);
				return std::move(ite);
			}
			inline const_reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs) const
			{
				updateForward(rhs);
				return *this;
			}
			inline const_reverse_iterator& operator+=(const std::size_t rhs) const
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline const_reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs) const
			{
				updateBackward(rhs);
				return *this;
			}
			inline const_reverse_iterator& operator-=(const std::size_t rhs) const
			{
				return operator-=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator+=(const typename reverse_iterator::difference_type rhs)
			{
				updateForward(rhs);
				return *this;
			}
			inline reverse_iterator& operator+=(const std::size_t rhs)
			{
				return operator+=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline reverse_iterator& operator-=(const typename reverse_iterator::difference_type rhs)
			{
				updateBackward(rhs);
				return *this;
			}
			inline reverse_iterator& operator-=(const std::size_t rhs)
			{
				return operator-=(static_cast<typename reverse_iterator::difference_type>(rhs));
			}
			inline const_reverse_iterator operator+(const typename reverse_iterator::difference_type rhs) const
			{
				reverse_iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline const_reverse_iterator operator+(const std::size_t rhs) const
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline const_reverse_iterator operator-(const typename reverse_iterator::difference_type rhs) const
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline const_reverse_iterator operator-(const std::size_t rhs) const
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator+(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite += rhs;
				return std::move(ite);
			}
			inline reverse_iterator operator+(const std::size_t rhs)
			{
				return std::move(operator+(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			inline reverse_iterator operator-(const typename reverse_iterator::difference_type rhs)
			{
				reverse_iterator ite(*this);
				ite -= rhs;
				return std::move(ite);
			}
			inline reverse_iterator operator-(const std::size_t rhs)
			{
				return std::move(operator-(static_cast<typename reverse_iterator::difference_type>(rhs)));
			}
			//inline typename reverse_iterator::difference_type operator-(const reverse_iterator rhs)
			//{
			//	return ???;
			//}
		public:
			//ムーブオペレータ
			inline reverse_iterator& operator=(const_reverse_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_set = std::move(rhs.m_set);
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator&& rhs)
			{
				m_con = rhs.m_con;
				m_set = std::move(rhs.m_set);
				m_isEnd = false;
				if (m_set.m_index != INVALID_INDEX)
					++(*this);
				else
				{
					if (rhs.m_isEnd)
						update(m_con->getLastIndex());//末尾インデックス
				}
				return *this;
			}
			//コピーオペレータ
			inline reverse_iterator& operator=(const_reverse_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_set = rhs.m_set;
				m_isEnd = rhs.m_isEnd;
				return *this;
			}
			inline reverse_iterator& operator=(const_iterator& rhs)
			{
				m_con = rhs.m_con;
				m_set = rhs.m_set;
				m_isEnd = false;
				if (m_set.m_index != INVALID_INDEX)
					++(*this);
				else
				{
					if (rhs.m_isEnd)
						update(m_con->getLastIndex());//末尾インデックス
				}
				return *this;
			}
		public:
			//アクセッサ
			inline bool isExist() const { return m_set.m_index != INVALID_INDEX; }
			inline bool isNotExist() const { return !isExist(); }
			inline bool isEnabled() const { return m_set.m_index != INVALID_INDEX || m_isEnd; }
			inline bool isNotEnabled() const { return !isEnabled(); }
			inline bool isEnd() const { return m_isEnd; }//終端か？
			inline const set& getSet() const { return m_set; }//現在のセット
			inline set& getSet(){ return m_set; }//現在のセット
			inline index_type getIndex() const { return m_set.m_index; }//（実際の）インデックス
			inline index_type getPrimaryIndex() const { return m_set.m_primaryIndex; }//本来のインデックス
			inline key_type getKey() const { return m_set.m_key; }//現在のキー
			inline const value_type* getValue() const { return m_set.m_value; }//現在の値
			inline value_type* getValue(){ return m_set.m_value; }//現在の値
			inline bool isDeleted() const { return m_set.m_isDeleted; }//削除済み
			inline bool isPrimaryIndex() const { return m_set.isPrimaryIndex(); }//本来のインデックスか？
		private:
			//メソッド
			index_type update(const index_type index) const
			{
				//if (index == INVALID_INDEX || index < 0 || index >= static_cast<index_type>(m_con->m_size))
				if (index >= static_cast<index_type>(TABLE_SIZE))
					m_set.update(INVALID_INDEX, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
				else
					m_set.update(index, m_con->calcIndex(m_con->m_keyTable[index]), m_con->m_keyTable[index], reinterpret_cast<const value_type*>(m_con->m_table[index]), m_con->m_deleted[index]);
				return m_set.m_index;
			}
			inline void updateNext() const
			{
				const index_type prev_index = m_set.m_index;
				const index_type index = update(m_con->getPrevIndex(prev_index));
				m_isEnd = (prev_index != INVALID_INDEX && index == INVALID_INDEX);
			}
			inline void updatePrev() const
			{
				if (m_isEnd)
				{
					update(m_con->getFirstIndex());
					m_isEnd = false;
					return;
				}
				update(m_con->getNextIndex(m_set.m_index));
				m_isEnd = false;
			}
			void updateForward(const int step) const
			{
				int _step = step;
				const index_type prev_index = m_set.m_index;
				index_type index = prev_index;
				while (_step > 0 && index != INVALID_INDEX)
				{
					index = m_con->getPrevIndex(index);
					--_step;
				}
				update(index);
				m_isEnd = (index != INVALID_INDEX && index == INVALID_INDEX && _step == 0);
			}
			void updateBackward(const int step) const
			{
				int _step = step;
				index_type index = m_set.m_index;
				if (_step > 0 && m_isEnd)
				{
					index = m_con->getFirstIndex();
					--_step;
				}
				while (_step > 0 && index != INVALID_INDEX)
				{
					index = m_con->getNextIndex(index);
					--_step;
				}
				update(index);
				m_isEnd = false;
			}
		public:
			//ベースを取得
			inline const_iterator base() const
			{
				iterator ite(*this);
				return std::move(ite);
			}
			inline iterator base()
			{
				iterator ite(*this);
				return std::move(ite);
			}
		public:
			//ムーブコンストラクタ
			inline reverse_iterator(const_reverse_iterator&& obj) :
				m_con(obj.m_con),
				m_set(std::move(obj.m_set)),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_set(std::move(obj.m_set)),
				m_isEnd(false)
			{
				if (m_set.m_index != INVALID_INDEX)
					++(*this);
				else
				{
					if (obj.m_isEnd)
						update(m_con->getLastIndex());//末尾インデックス
				}
			}
			//コピーコンストラクタ
			inline reverse_iterator(const_reverse_iterator& obj) :
				m_con(obj.m_con),
				m_set(obj.m_set),
				m_isEnd(obj.m_isEnd)
			{}
			inline reverse_iterator(const_iterator& obj) :
				m_con(obj.m_con),
				m_set(obj.m_set),
				m_isEnd(false)
			{
				if (m_set.m_index != INVALID_INDEX)
					++(*this);
				else
				{
					if (obj.m_isEnd)
						update(m_con->getLastIndex());//末尾インデックス
				}
			}
			//コンストラクタ
			inline reverse_iterator(const container& con, const bool is_end) :
				m_con(&con),
				m_set(INVALID_INDEX, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false),
				m_isEnd(is_end)
			{
				if (!is_end)
					update(m_con->getLastIndex());//末尾インデックス
			}
			inline reverse_iterator() :
				m_con(nullptr),
				m_set(INVALID_INDEX, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false),
				m_isEnd(false)
			{}
			//デストラクタ
			inline ~reverse_iterator()
			{}
		protected:
			//フィールド
			const container* m_con;//コンテナ
			mutable set m_set;//現在のキー/値/削除済みフラグ
			mutable bool m_isEnd;//終端か？
		};
	#endif
	public:
		//アクセッサ
		inline size_type getOriginalTableSize() const { return ORIGINAL_TABLE_SIZE; }//指定されたテーブルサイズを取得
		inline size_type getTableSize() const { return TABLE_SIZE; }//（実際の）テーブルサイズを取得
		inline size_type getTableSizeExtended() const { return TABLE_SIZE_EXTENDED; }//指定のテーブルサイズからの増分を取得
		inline size_type getAutoRehashRatio() const { return AUTO_REHASH_RATIO; }//自動リハッシュ実行の基準割合
		inline size_type getAutoRehashSize() const { return AUTO_REHASH_SIZE; }//自動リハッシュ実行の基準サイズ
		inline int getFindingCycleLimit() const { return FINDING_CYCLE_LIMIT; }//検索時の巡回回数の制限を取得
		inline key_type getKeyMin() const { return KEY_MIN; }//キーの最小値を取得
		inline key_type getKeyMax() const { return KEY_MAX; }//キーの最大値を取得
		inline key_type getKeyRange() const { return KEY_RANGE; }//キーの範囲を取得
		inline index_type getIndexStepBase() const { return INDEX_STEP_BASE; }//検索巡回時のインデックスの歩幅の基準値（実際のステップ数は、この値を係数にキーから算出する）
		inline int getUsingCount() const { return m_usingCount; }//使用中データ数を取得
		inline int getDeletedCount() const { return m_deletedCount; }//削除済みデータ数を取得
		inline int getMaxFindingCycle() const { return m_maxFindingCycle; }//検索時の最大巡回回数を取得
		int getNotOptimizedCount() const//最適化されていないデータ件数を取得 ※検索の際に2回以上の巡回が必要なデータ = 本来のインデックスと実際のインデックスが異なるデータ
		{
			int count = 0;
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || m_deleted[index])
					continue;
				if (index != calcIndex(m_keyTable[index]))
					++count;
			}
			return count;
		}
	public:
		inline size_type max_size() const { return TABLE_SIZE; }//最大要素数を取得
		inline size_type capacity() const { return TABLE_SIZE; }//最大要素数を取得
		inline size_type size() const { return m_usingCount - m_deletedCount; }//使用中の要素数を取得
		inline size_type remain() const { return TABLE_SIZE - size(); }//残りの要素数を取得
		inline bool empty() const { return size() == 0; }//空か？
		inline bool full() const { return size() == TABLE_SIZE; }//満杯か？
		inline size_type bucket_count() const { return TABLE_SIZE; }//最大要素数を取得
		inline size_type max_bucket_count() const { return TABLE_SIZE; }//最大要素数を取得
		inline size_type bucket(const key_type key) const { return _findIndex(key); }//キーに対応するインデックスを取得
		inline size_type bucket(const char* key) const { return _findIndex(key); }//キーに対応するインデックスを取得
		inline size_type bucket(const std::string key) const { return _findIndex(key); }//キーに対応するインデックスを取得
		inline size_type bucket(const value_type& value) const { return _findIndex(value); }//キーに対応するインデックスを取得
		inline size_type bucket_size(const index_type index) const { return m_using[index] && !m_deleted[index] ? 1 : 0; }//特定バケット内の要素数を取得
	public:
		//検索系アクセッサ：キーで検索して値を返す
		//※マルチスレッドで処理する際は、一連の処理ブロック全体の前後で
		//　リードロックの取得を行うようにすること。
		value_type* at(const key_type key){ return findValue(key); }
		value_type* at(const char* key){ return findValue(key); }
		value_type* at(const std::string& key){ return findValue(key); }
		value_type* at(const value_type& value){ return findValue(value); }
		const value_type* at(const key_type key) const { return findValue(key); }
		const value_type* at(const char* key) const { return findValue(key); }
		const value_type* at(const std::string& key) const { return findValue(key); }
		const value_type* at(const value_type& value) const { return findValue(value); }
		value_type* operator[](const key_type key){ return findValue(key); }
		value_type* operator[](const char* key){ return findValue(key); }
		value_type* operator[](const std::string& key){ return findValue(key); }
		value_type* operator[](const value_type& value){ return findValue(value); }
		const value_type* operator[](const key_type key) const { return findValue(key); }
		const value_type* operator[](const char* key) const { return findValue(key); }
		const value_type* operator[](const std::string& key) const { return findValue(key); }
		const value_type* operator[](const value_type& value) const { return findValue(value); }
	public:
		//キャストオペレータ
		inline operator lock_type&(){ return m_lock; }//共有ロックオブジェクト
		inline operator lock_type&() const { return m_lock; }//共有ロックオブジェクト ※mutable
	public:
		//メソッド
		inline index_type calcIndexStep(const key_type key) const { return INDEX_STEP_BASE - key % INDEX_STEP_BASE; }//キーからインデックスの歩幅（第二ハッシュ）を計算
		inline index_type calcIndex(const key_type key) const { return calcIndexImpl<(TABLE_SIZE >= KEY_RANGE && KEY_RANGE > 0), size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE >::calc(key); }//キーからインデックス（第一ハッシュ）を計算
		inline index_type calcNextIndex(const key_type key, const index_type index) const { return (index + calcIndexStep(key)) % TABLE_SIZE; }//次のインデックスを計算（指定のインデックスに歩幅を加算）
	public:
		//インデックスを取得
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
		index_type getFirstIndex() const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (m_using[index])
					return index;
			}
			return INVALID_INDEX;
		}
		index_type getLastIndex() const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (index_type index = TABLE_SIZE; index > 0; --index)
			{
				if (m_using[index - 1])
					return index - 1;
			}
			return INVALID_INDEX;
		}
		index_type getNextIndex(const index_type index) const
		{
			index_type next_index = index == INVALID_INDEX ? 0 : index + 1;
			if (index < 0 || index >= TABLE_SIZE - 1 || m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (; next_index < TABLE_SIZE; ++next_index)
			{
				if (m_using[next_index])
					return next_index;
			}
			return INVALID_INDEX;
		}
		index_type getPrevIndex(const index_type index) const
		{
			index_type now_index = index == INVALID_INDEX ? TABLE_SIZE : index;
			if (index <= 0 || index >= TABLE_SIZE || m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (; now_index > 0; --now_index)
			{
				if (m_using[now_index - 1])
					return now_index - 1;
			}
			return INVALID_INDEX;
		}
		//イテレータを取得
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
		inline const_iterator cbegin() const
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_iterator cend() const
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
		inline const_iterator begin() const
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_iterator end() const
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
		inline iterator begin()
		{
			iterator ite(*this, false);
			return std::move(ite);
		}
		inline iterator end()
		{
			iterator ite(*this, true);
			return std::move(ite);
		}
	#if 1//std::forward_iterator_tag には本来必要ではない
		//リバースイテレータを取得
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
		inline const_reverse_iterator crbegin() const
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_reverse_iterator crend() const
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
		inline const_reverse_iterator rbegin() const
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline const_reverse_iterator rend() const
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
		inline reverse_iterator rbegin()
		{
			reverse_iterator ite(*this, false);
			return std::move(ite);
		}
		inline reverse_iterator rend()
		{
			reverse_iterator ite(*this, true);
			return std::move(ite);
		}
	#endif
	private:
		//キーで検索してインデックスを取得（共通）
		index_type _findIndexCommon(const key_type key) const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			const index_type index_first = calcIndex(key);//キーからインデックス（ハッシュ）を計算
			index_type index = index_first;
			do
			{
				if (!m_using[index])//未使用インデックスなら検索失敗
					break;
				if (!m_deleted[index] && m_keyTable[index] == key)//キーが一致するインデックスなら検索成功
					return index;
				index = calcNextIndex(key, index);//次のインデックスへ
			} while (index != index_first);//最初のインデックスに戻ったら終了（検索失敗）
			return INVALID_INDEX;
		}
		//キーで検索してインデックスを取得
		inline index_type _findIndex(const key_type key) const{ return _findIndexCommon(key); }
		inline index_type _findIndex(const char* key) const{ return _findIndexCommon(calcCRC32(key)); }
		inline index_type _findIndex(const std::string& key) const{ return _findIndexCommon(key.c_str()); }
		inline index_type _findIndex(const value_type& value) const{ return _findIndexCommon(ope_type::getKey(value)); }
	private:
		//キーで検索して値を取得（本体）
		inline const value_type* _findValue(const key_type key) const
		{
			const index_type index = _findIndex(key);//検索してインデックスを取得
			if (index == INVALID_INDEX)
				return nullptr;
			return reinterpret_cast<const value_type*>(&m_table[index]);
		}
	public:
		//キーで検索して値を取得
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
		inline const value_type* findValue(const key_type key) const { return _findValue(key); }
		inline const value_type* findValue(const char* key) const { return _findValue(calcCRC32(key)); }
		inline const value_type* findValue(const std::string& key) const { return _findValue(key.c_str()); }
		inline const value_type* findValue(const value_type& value) const { return _findValue(ope_type::getKey(value)); }
		inline value_type* findValue(const key_type key){ return const_cast<value_type*>(_findValue(key)); }
		inline value_type* findValue(const char* key){ return const_cast<value_type*>(_findValue(calcCRC32(key))); }
		inline value_type* findValue(const std::string& key){ return const_cast<value_type*>(_findValue(key.c_str())); }
		inline value_type* findValue(const value_type& value){ return const_cast<value_type*>(_findValue(ope_type::getKey(value))); }
		//キーで検索してイテレータを取得
		//※自動的な共有ロック取得は行わないので、マルチスレッドで利用する際は、
		//　一連の処理ブロック全体の前後で共有ロック（リードロック）の取得と解放を行う必要がある
		const_iterator find(const key_type key) const
		{
			const index_type index = _findIndex(key);
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, index, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator find(const char* key) const { return find(calcCRC32(key)); }
		inline const_iterator find(const std::string& key) const { return find(key.c_str()); }
		inline const_iterator find(const value_type& value) const { return find(ope_type::getKey(value)); }
		inline iterator find(const key_type key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const char* key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const std::string& key){ return const_cast<const container*>(this)->find(key); }
		inline iterator find(const value_type value){ return const_cast<const container*>(this)->find(value); }
	private:
		//キー割り当て（本体）
		//※割り当てた配列要素（データテーブル）のポインタを返す
		value_type* _assign(const key_type key)
		{
			if (m_usingCount == TABLE_SIZE && m_deletedCount == 0)
				return nullptr;
			index_type index = _findIndexCommon(key);
			if (ope_type::REPLACE_ATTR == ope_type::NEVER_REPLACE && index != INVALID_INDEX)//同じキーが既に割り当て済みなら割り当て失敗
				return nullptr;
			int find_cycle = 0;
			if (index != INVALID_INDEX)
			{
				//置換
				_eraseByIndex(index);//デストラクタの呼び出しあり
			}
			else
			{
				//新規登録
				const index_type index_first = calcIndex(key);//キーからインデックス（ハッシュ）を計算
				index = index_first;
				do
				{
					++find_cycle;
					if (!m_using[index] || m_deleted[index])//未使用／削除済みインデックスなら割り当て成功
						break;
					if (FINDING_CYCLE_LIMIT > 0 && find_cycle == FINDING_CYCLE_LIMIT)//巡回回数が制限に達したら割り当て失敗
						return nullptr;
					index = calcNextIndex(key, index);//次のインデックスへ
				} while (index != index_first);//最初のインデックスに戻ったら終了（割り当て失敗）
			}
			m_keyTable[index] = key;//キーテーブルにキー登録
			if (!m_using[index])//未使用インデックスの割り当てなら使用中数を調整
			{
				m_using[index] = true;//使用中フラグをセット
				++m_usingCount;//使用中数をカウントアップ
			}
			if (m_deleted[index])//削除済みインデックスの再割り当てなら削除数を調整
			{
				m_deleted[index] = false;//削除済みフラグをリセット
				--m_deletedCount;//削除済み数をカウントダウン
			}
			m_maxFindingCycle = m_maxFindingCycle >= find_cycle ? m_maxFindingCycle : find_cycle;//最大巡回回数を更新
			return reinterpret_cast<value_type*>(&m_table[index]);
		}
	public:
		//キー割り当て
		//※割り当てた配列要素（データテーブル）のポインタを返す
		//※処理中、排他ロック（ライトロック）を取得する
		inline value_type* assign(const key_type key)
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			return _assign(key);
		}
		inline value_type* assign(const char* key){ return assign(calcCRC32(key)); }
		inline value_type* assign(const std::string& key){ return assign(key.c_str()); }
		inline value_type* assign(const value_type& value){ return assign(ope_type::getKey(value)); }
	private:
		//キー割り当てして値を挿入（コピー）（本体）
		//※オブジェクトのコピーが発生する点に注意
		value_type* _insert(const key_type key, const value_type& value)
		{
			value_type* assigned_value = _assign(key);
			if (!assigned_value)
				return nullptr;
			*assigned_value = value;
			return assigned_value;
		}
	public:
		//キー割り当てして値を挿入（コピー）
		//※オブジェクトのコピーが発生する点に注意
		//※処理中、排他ロック（ライトロック）を取得する
		inline value_type* insert(const key_type key, const value_type& value)
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			return _insert(key, value);
		}
		inline value_type* insert(const char* key, const value_type& value){ return insert(calcCRC32(key), value); }
		inline value_type* insert(const std::string& key, const value_type& value){ return insert(key.c_str(), value); }
		//値を挿入（コピー）し、キーは自動割り当て
		//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
		//※オブジェクトのコピーが発生する点に注意
		inline value_type* insertAuto(const value_type& value){ return insert(ope_type::getKey(value), value); }
	private:
		//キー割り当てして値を初期化（本体）
		//※コンストラクタが呼び出される
		template<typename... Tx>
		value_type* _emplace(const key_type key, Tx... args)//const Tx&... args とも書ける
		{
			value_type* assigned_value = _assign(key);
			if (!assigned_value)
				return nullptr;
			assigned_value = new(assigned_value) value_type(args...);//コンストラクタ呼び出し
			return assigned_value;
		}
	public:
		//キー割り当てして値を初期化
		//※コンストラクタが呼び出される
		//※処理中、排他ロック（ライトロック）を取得する
		template<typename... Tx>
		inline value_type* emplace(const key_type key, Tx... args)//const Tx&... args とも書ける
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			return _emplace(key, args...);
		}
		template<typename... Tx>
		inline value_type* emplace(const char* key, Tx... args){ return emplace(calcCRC32(key), args...); }
		template<typename... Tx>
		inline value_type* emplace(const std::string& key, Tx... args){ return emplace(key.c_str(), args...); }
		//値を初期化して自動的にキー割り当て
		//※オブジェクトのコピーが発生する点に注意
		//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
		//※処理中、ライトロックを取得する
		template<typename... Tx>
		inline value_type* emplaceAuto(Tx... args)
		{
			value_type value(args...);
			return insertAuto(value);
		}
	private:
		//インデックスを指定して削除
		void _eraseByIndex(const index_type index)
		{
			value_type* data_p = reinterpret_cast<value_type*>(&m_table[index]);
			ope_type::callDestructor(data_p);//デストラクタ呼び出し
			operator delete(data_p, data_p);//（作法として）deleteオペレータ呼び出し
			m_deleted[index] = true;//削除済みインデックスを更新
			++m_deletedCount;//削除済み数をカウントアップ
		}
		//キーを削除（本体）
		bool _erase(const key_type key)
		{
			const index_type index = _findIndex(key);//検索してインデックスを取得
			if (index == INVALID_INDEX)//検索失敗なら削除失敗
				return false;
			_eraseByIndex(index);
			if (m_usingCount == m_deletedCount || m_deletedCount == AUTO_REHASH_SIZE)//自動リハッシュ
				_rehash();
			return true;
		}
	public:
		//キーを削除
		//※処理中、排他ロック（ライトロック）を取得する
		inline bool erase(const key_type key)
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			return _erase(key);
		}
		inline bool erase(const char* key){ return erase(calcCRC32(key)); }
		inline bool erase(const std::string& key){ return erase(key.c_str()); }
		//キーを削除
		//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
		inline bool eraseAuto(const value_type& value){ return erase(ope_type::getKey(value)); }
	private:
		//リハッシュ（本体）
		bool _rehash()
		{
			if (m_usingCount == 0 || m_deletedCount == 0)
				return false;
			if (m_usingCount == m_deletedCount)
			{
				_clear();
				return true;
			}
			m_maxFindingCycle = 1;//最大巡回回数を1にリセット
			//値の移動
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || m_deleted[index])//未使用インデックスまたは削除済みインデックスは処理をスキップ
					continue;
				const key_type key = m_keyTable[index];//キーを取得
				if (calcIndex(key) == index)//キーが本来のインデックスと異なる場合、移動を試みる
					continue;
				value_type* value = reinterpret_cast<value_type*>(m_table[index]);//現在の値を記憶
				m_deleted[index] = true;//一旦削除済みにする
				++m_deletedCount;       //（同上）
				value_type* value_new = _assign(key);//改めてキーを割り当て
				if (value_new != value)//インデックスが違っていたなら値を移動
				{
				#if 1
					*value_new = std::move(*value);//ムーブ演算子で移動
				#else
					memcpy(value_new, value, sizeof(value_type));//memcpyで移動
				#endif
				}
			}
			//削除済みインデックスのクリア
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (!m_using[index] || !m_deleted[index])//未使用インデックスまたは未削除インデックスは処理をスキップ
					continue;
				m_deleted[index] = false;//削除済みを解消する
				--m_deletedCount;       //（同上）
				m_using[index] = false;//使用中を解消する
				--m_usingCount;        //（同上）
			}
			return true;
		}
	public:
		//リハッシュ
		//※テーブルを拡大・再構築するのではなく、削除済みデータを完全に削除するだけ。
		//　そのために、削除済みデータの位置に移動可能なデータを移動する。
		//※処理中、排他ロック（ライトロック）を取得する
		inline bool rehash()
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			return _rehash();
		}
	private:
		//クリア（本体）
		void _clear()
		{
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (m_using[index] && !m_deleted[index])//使用中データはデストラクタ呼び出し
					_eraseByIndex(index);
			}
			m_using.reset();
			m_deleted.reset();
			m_usingCount = 0;
			m_deletedCount = 0;
			m_maxFindingCycle = 0;
		}
	public:
		//クリア
		//※処理中、排他ロック（ライトロック）を取得する
		inline void clear()
		{
			lock_guard<lock_type> lock(m_lock);//排他ロック（ライトロック）取得（関数を抜ける時に自動開放）
			_clear();
		}
	public:
		//コンストラクタ
		container() :
			m_using(),
			m_deleted(),
			m_usingCount(0),
			m_deletedCount(0),
			m_maxFindingCycle(0)
		{}
		//デストラクタ
		~container()
		{}
	private:
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//データテーブル（バケット）
		key_type m_keyTable[TABLE_SIZE];//キーテーブル
		std::bitset<TABLE_SIZE> m_using;//キー設定済みフラグ ※登録を削除してもfalseにならない（リハッシュ時には調整される）
		std::bitset<TABLE_SIZE> m_deleted;//削除済みフラグ
		int m_usingCount;//使用中データ数 ※登録を削除しても減らない（リハッシュ時には調整される）
		int m_deletedCount;//削除済みデータ数
		int m_maxFindingCycle;//検索時の最大巡回回数 ※登録を削除しても減らない（リハッシュ時には調整される）
		mutable lock_type m_lock;//ロックオブジェクト
	};
#if 1//std::forward_iterator_tag には本来必要ではない
	//イテレータのムーブオペレータ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _AUTO_REHASH_RATIO, int _FINDING_CYCLE_LIMIT, std::size_t _INDEX_STEP_BASE>
	//typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator& container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator::operator=(typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::const_reverse_iterator&& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator& container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator::operator=(const typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::reverse_iterator&& rhs)//VC++もOK
	{
		m_con = rhs.m_con;
		m_set = std::move(rhs.m_set);
		m_isEnd = false;
		if (m_set.m_index != INVALID_INDEX)
			++(*this);
		else
		{
			if (rhs.m_isEnd)
				update(m_con->getFirstIndex());//先頭インデックス
		}
		return *this;
	}
	//イテレータのコピーオペレータ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _AUTO_REHASH_RATIO, int _FINDING_CYCLE_LIMIT, std::size_t _INDEX_STEP_BASE>
	//typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator& container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator::operator=(typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::const_reverse_iterator& rhs)//GCCはOK, VC++はNG
	typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator& container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator::operator=(const typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::reverse_iterator& rhs)//VC++もOK
	{
		m_con = rhs.m_con;
		m_set = rhs.m_set;
		m_isEnd = false;
		if (m_set.m_index != INVALID_INDEX)
			++(*this);
		else
		{
			if (rhs.m_isEnd)
				update(m_con->getFirstIndex());//先頭インデックス
		}
		return *this;
	}
	//イテレータのムーブコンストラクタ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _AUTO_REHASH_RATIO, int _FINDING_CYCLE_LIMIT, std::size_t _INDEX_STEP_BASE>
	//container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator::iterator(typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::const_reverse_iterator&& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator::iterator(const typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::reverse_iterator&& obj) ://VC++もOK
		m_con(obj.m_con),
		m_set(std::move(obj.m_set)),
		m_isEnd(false)
	{
		if (m_set.m_index != INVALID_INDEX)
			++(*this);
		else
		{
			if (obj.m_isEnd)
				update(m_con->getFirstIndex());//先頭インデックス
		}
	}
	//イテレータのコピーコンストラクタ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _AUTO_REHASH_RATIO, int _FINDING_CYCLE_LIMIT, std::size_t _INDEX_STEP_BASE>
	//container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator::iterator(typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::const_reverse_iterator& obj) ://GCCはOK, VC++はNG
	container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::iterator::iterator(const typename container<OPE_TYPE, _TABLE_SIZE, _AUTO_REHASH_RATIO, _FINDING_CYCLE_LIMIT, _INDEX_STEP_BASE>::reverse_iterator& obj) ://VC++もOK
		m_con(obj.m_con),
		m_set(obj.m_set),
		m_isEnd(false)
	{
		if (m_set.m_index != INVALID_INDEX)
			++(*this);
		else
		{
			if (obj.m_isEnd)
				update(m_con->getFirstIndex());//先頭インデックス
		}
	}
#endif
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace hash_table

//--------------------------------------------------------------------------------
//ハッシュテーブル＆素数計算テスト
//--------------------------------------------------------------------------------

#include <chrono>//C++11 時間計測用
#include <unordered_map>//C++11 std::unordered_map
#include <map>//C++11 std::map
#include <string.h>//strcpy用

//----------------------------------------
//テスト用補助関数
#ifdef PRINT_TEST_DATA_DETAIL
template<typename... Tx>
inline int printf_detail(const char* fmt, Tx... args)
{
	return printf(fmt, args...);
}
#else//PRINT_TEST_DATA_DETAIL
inline int printf_detail(const char* fmt, ...){ return 0; }
#endif//PRINT_TEST_DATA_DETAIL

//----------------------------------------
//文字列操作関数
#ifdef USE_GCC
inline char* strcpy_s(char* dst, const std::size_t size, const char* src)
{
	return strcpy(dst, src);
}
inline char* strncpy_s(char* dst, const std::size_t size, const char* src, const std::size_t max)
{
	return strncpy(dst, src, max);
}
template<typename... Tx>
inline int sprintf_s(char* dst, const std::size_t size, const char* fmt, Tx... args)
{
	return sprintf(dst, fmt, args...);
}
#endif//USE_GCC

//----------------------------------------
//【ランタイム版】素数判定／算出テスト
void printPrime(const std::size_t min, const std::size_t max)
{
	if (max > min)
		printPrime(min, max - 1);
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", max, isPrime(max) ? "PRIME.    " : "NOT prime.", makePrimeLT(max), makePrimeLE(max), makePrimeGT(max), makePrimeGE(max));
}

//----------------------------------------
//【メタプログラミング版】素数判定／算出テスト
template<std::size_t N>
void _printPrimeCommon()
{
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", N, isStaticPrime<N>::value ? "PRIME.    " : "NOT prime.", makeStaticPrimeLT<N>::value, makeStaticPrimeLE<N>::value, makeStaticPrimeGT<N>::value, makeStaticPrimeGE<N>::value);
}
template<std::size_t MIN, std::size_t MAX>
struct printStaticPrime{
	void operator()()
	{
		printStaticPrime<MIN, MAX - 1>()();
		_printPrimeCommon<MAX>();
	}
};
template<std::size_t MIN>
struct printStaticPrime<MIN, MIN>{
	void operator()()
	{
		_printPrimeCommon<MIN>();
	}
};

//----------------------------------------
//ハッシュテーブル用テストデータ
struct data_t
{
	crc32_t m_key;//キー ※名前のハッシュ値
	int m_value;//値
	char m_name[20];//名前

	//コンストラクタ
	data_t(const char* name, const int value) :
		m_key(calcCRC32(name)),
		m_value(value)
	{
		strncpy_s(m_name, sizeof(m_name), name, sizeof(m_name) - 1);
		m_name[sizeof(m_name)-1] = '\0';
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(\"%s\", value)\n", name, value);
		//printf("    m_key=%d, m_name=[%s], m_value=%d\n", m_key, m_name, m_value);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
#ifdef TEST_DATA_WATCH_CONSTRUCTOR
	//ムーブオペレータ
	data_t& operator=(const data_t&& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::move_operator\n");
		return *this;
	}
	//コピーオペレータ
	data_t& operator=(const data_t& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::copy_operator\n");
		return *this;
	}
	//ムーブコンストラクタ
	data_t(const data_t&& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::move_constructor\n");
	}
	//コピーコンストラクタ
	data_t(const data_t& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::copy_constructor\n");
	}
	//デフォルトコンストラクタ
	data_t():
		m_key(0),
		m_value(0)
	{
		m_name[0] = '\0';
		printf("data_t::constructor\n");
	}
	//デストラクタ
	~data_t()
	{
		printf("data_t::destructor\n");
		//printf("  m_key=%d, m_name=[%s]\n", m_key, m_name);
	}
#endif//TEST_DATA_WATCH_CONSTRUCTOR
};

//----------------------------------------
//テストデータ操作クラス
#include <functional>//C++11 std::function用
#include <algorithm>//C++11 std::for_each用
struct ope_t : public hash_table::base_ope_t<ope_t, crc32_t, data_t>
{
	//データ置換属性
	//※デフォルト（NEVER_REPLACE）のままとする
	//static const replace_attr_t REPLACE_ATTR = REPLACE;//キーが重複するデータは置換して登録する
	
	//キーを取得
	inline static key_type getKey(const value_type& value){ return value.m_key; }

	//ロック型
	//※デフォルト（dummy_shared_lock）のままとする
	//typedef shared_spin_lock lock_type;//ロックオブジェクト型
};

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
	//時間計測
	auto begin_time = std::chrono::system_clock::now();
	auto prev_time = begin_time;

	//処理時間計測
	auto calcElapsedTime = [](const std::chrono::system_clock::time_point& now_time, const std::chrono::system_clock::time_point& prev_time) -> double
	{
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - prev_time);
		const auto elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		return elapsed_time;
	};
	auto getElapsedTime = [&calcElapsedTime](const std::chrono::system_clock::time_point& prev_time) -> double
	{
		return calcElapsedTime(std::chrono::system_clock::now(), prev_time);
	};

	//処理時間表示
	auto printElapsedTimeDirect = [&calcElapsedTime](const double elapsed_time, const bool is_preint) -> std::chrono::system_clock::time_point
	{
		if (is_preint)
			printf("*elapsed time=%.9llf sec.\n", elapsed_time);
		return std::chrono::system_clock::now();
	};
	auto printElapsedTime = [&calcElapsedTime, &printElapsedTimeDirect](const std::chrono::system_clock::time_point& prev_time, const bool is_print) -> std::chrono::system_clock::time_point
	{
		const auto now_time = std::chrono::system_clock::now();
		const auto elapsed_time = calcElapsedTime(now_time, prev_time);
		return printElapsedTimeDirect(elapsed_time, is_print);
	};

#if 0
	//--------------------
	//素数コンパイル時計算の再帰レベル限界チェック
	static const std::size_t x = 9999;
	printf("x=%d\n", x);
	printf("  isPrime=%s\n", isStaticPrime<x>::value ? "true" : "False");
	printf("  prev=%d\n", makeStaticPrimeLT<x>::value);
	printf("  next=%d\n", makeStaticPrimeGT<x>::value);
	printf("  equalPrev=%d\n", makeStaticPrimeLE<x>::value);
	printf("  equalNext=%d\n", makeStaticPrimeGE<x>::value);
#endif

#if 0
	//--------------------
	//素数計算のテスト
	static const std::size_t MIN = 0;
	static const std::size_t MAX = 10;
	
	printf("----- Check and Make Prime for Runtime -----\n");
	printPrime(MIN, MAX);
	
	printf("----- Check and Make Prime for Meta-Programming -----\n");
	printStaticPrime<MIN, MAX>()();
#endif

#if 0
	//--------------------
	//ハッシュテーブルのインデックス計算ロジックテスト
	//※全てのインデックスが、正確にテーブルサイズ（素数）回の再計算を行う事で、元のインデックスに戻ることを確認。
	{
		int ng_count = 0;
		const ope_t::key_type key_min = 0;// con.getKeyMin();
		const ope_t::key_type key_max = 100000;// con.getKeyMax();
		const ope_t::key_type key_step = 1;
		for (ope_t::key_type key = key_min; key <= key_max; key += key_step)
		{
			if (key % (1024 * 1024) == 0)
				printf("pass ... Key:%d\n", key);
			std::size_t count = 0;
			std::size_t first_index = con.calcIndex(key);
			std::size_t index = first_index;
			do
			{
				index = con.calcNextIndex(key, index);
				++count;
			} while (index != first_index && count < con.getTableSize());
			if (count != con.getTableSize())
			{
				printf("%u is OUT! (count=%d)\n", key, count);
				++ng_count;
			}
		}
		printf("Chek Hash Table: NG=%d/%d\n", ng_count, con.getTableSize());
		for (std::size_t key = 10; key <= 30; key += 1)
		{
			printf("Key:%u -> Index;%u\n", key, con.calcIndex(key));
		}
	}
#endif

#if 0
	//--------------------
	//ハッシュテーブルテスト（旧）
	{
		hash_table::container<ope_t, 20> con(hash_table::AUTO_WRITE_LOCK);
		
		data_t* result;
		printf("- emplace -\n");
		result = con.emplace(110, "123", 123);
		data_t* obj = con[110];
		obj->m_value = 1234567;
		result = con.emplace(220, "456", 456);
		result = con.emplace(330, "789", 789);
		result = con.emplace(110, "123", 123);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".size()=%d\n", con.size());
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- erase -\n");
		con.erase(220);
		con.erase(330);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- emplace -\n");
		result = con.emplace(220, "456!", 4567);
		result = con.emplace("123", "123!!", 12345);
		result = con.emplaceAuto("456!!", 45679);
		result = con.emplace("789", "789!!", 78901);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- erase -\n");
		con.erase(220);
		con.erase(110);
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
		printf("- rehash -\n");
		con.rehash();
		for (auto& o : con)
		{
			printf("index=%d(%d), key=%08x, name=%s, value=%d, is_deleted=%s\n", o.m_index, con.calcIndex(o.m_key), o.m_key, o->m_name, o->m_value, o.m_isDeleted ? "TRUE" : "false");
		}
		printf(".getUsingCount()=%d\n", con.getUsingCount());
		printf(".getDeletedCount()=%d\n", con.getDeletedCount());
		printf(".getMaxFindingCycle()=%d\n", con.getMaxFindingCycle());
	}
#endif
	
	//--------------------
	//ハッシュテーブルテスト
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("Hash Table Test\n");
	printf("--------------------------------------------------------------------------------\n");
	typedef hash_table::container<ope_t, TEST_DATA_TABLE_SIZE, 0, 0> container_t;//自動リハッシュなし, 検索巡回回数制限なし
	container_t* con = new container_t();

	//ハッシュテーブルの基本情報表示
	auto printTableParameter = [&con]()
	{
		printf("\n");
		printf("--- Table Parameter ---\n");
		printf(".max_size()=%u\n", con->max_size());
		//printf(".capacity()=%u\n", con->capacity());
		printf(".getOriginalTableSize()=%u\n", con->getOriginalTableSize());
		printf(".getTableSize()=%u\n", con->getTableSize());
		printf(".getTableSizeExtended()=%u\n", con->getTableSizeExtended());
		printf(".getAutoRehashRatio()=%u\n", con->getAutoRehashRatio());
		printf(".getAutoRehashSize()=%u\n", con->getAutoRehashSize());
		printf(".getFindingCycleLimit()=%u\n", con->getFindingCycleLimit());
		printf(".getKeyMin()=%u\n", con->getKeyMin());
		printf(".getKeyMax()=%u\n", con->getKeyMax());
		printf(".getKeyRange()=%u\n", con->getKeyRange());
	};
	printTableParameter();

	//テーブル状態表示
	auto printTableStatus = [&con]()
	{
		printf("\n");
		printf("--- Table Status ---\n");
		printf(".bucket_count()=%u\n", con->bucket_count());
		printf(".max_bucket_count()=%u\n", con->max_bucket_count());
		printf(".size()=%u\n", con->size());
		printf(".empty()=%u\n", con->empty());
		printf(".getUsingCount()=%u\n", con->getUsingCount());
		printf(".getDeletedCount()=%u\n", con->getDeletedCount());
		printf(".getMaxFindingCycle()=%u\n", con->getMaxFindingCycle());
		printf(".getNotOptimizedCount()=%u\n", con->getNotOptimizedCount());
	};
	printTableStatus();

	//ハッシュテーブルへのデータ登録
	auto insertData = [&con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- Insert Data ---\n");
		int insert_success = 0;
		int insert_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t* obj = nullptr;
			#define USE_INSERT_TYPE 1
			//【推奨】【登録方法①】emplace()メソッドにキーとコンストラクタパラメータを渡して登録する方法
			//※オブジェクトのコピーは発生しない
			#if USE_INSERT_TYPE == 1
			{
				obj = con->emplace(calcCRC32(name), name, i);//キーとコンストラクタパラメータを渡して登録
			}
			//【登録方法②】emplaceAuto()メソッドにコンストラクタパラメータを渡して登録する方法
			//※オブジェクトのコピーが発生するので少し遅い
			#elif USE_INSERT_TYPE == 2
			{
				obj = con->emplaceAuto(name, i);//コンストラクタパラメータを渡して登録
			}
			//【登録方法③】insert()メソッドにキーとオブジェクトを渡して登録する方法
			//※オブジェクトのコピーが発生するので少し遅い
			//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
			#elif USE_INSERT_TYPE == 3
			{
				data_t new_obj(name, i);
				obj = con->insert(calcCRC32(name), new_obj);
			}
			//【登録方法④】insertAuto()メソッドにオブジェクトを渡して登録する方法
			//※オブジェクトのコピーが発生するので少し遅い
			//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
			#elif USE_INSERT_TYPE == 4
			{
				data_t new_obj(name, i);
				obj = con->insertAuto(new_obj);
			}
			//【登録方法⑤】assign()メソッドでデータのポインタを取得し、そこに値を書き込む
			//※コンストラクタのないオブジェクトを扱う場合に有効
			#elif USE_INSERT_TYPE == 5
			{
				const crc32_t key = calcCRC32(name);
				obj = con->assign(key);
				if(obj)
				{
					obj->m_key = key;
					strncpy_s(obj->m_name, sizeof(obj->m_name), name, sizeof(obj->m_name) - 1);
					obj->m_name[sizeof(obj->m_name) - 1] = '\0';
					obj->m_value = i;
				}
			}
			#endif//USE_INSERT_TYPE
			if (obj)
			{
				++insert_success;
				printf_detail("OK\n");
			}
			else
			{
				++insert_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", insert_success, insert_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	insertData(0, TEST_DATA_TABLE_SIZE / 2, 1);

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	auto printTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf_detail("\n");
		printf_detail("--- Print Table ---\n");
		//for (container_t::set& set : *con)
		for (auto& set : *con)
		{
			printf_detail("%c[%6d](%6d) key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)%s\n", set.isPrimaryIndex() ? ' ' : '*', set.m_index, set.m_primaryIndex, set.m_key, set->m_name, set->m_value, con->bucket(set.m_key), con->bucket_size(set.m_index), set.m_isDeleted ? " <DELETED>" : "");
		}
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	printTable();

#if 0//イテレータとロック取得のテスト
	{
		printf_detail("--- Reverse Iterator ---\n");
		std::for_each(con->rbegin(), con->rend(), [&con](container_t::set& set)
			{
				printf_detail("%c[%6d](%6d) key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)%s\n", set.isPrimaryIndex() ? ' ' : '*', set.m_index, set.m_primaryIndex, set.m_key, set->m_name, set->m_value, con->bucket(set.m_key), con->bucket_size(set.m_index), set.m_isDeleted ? " <DELETED>" : "");
			}
		);
	}
	{
		shared_lock_guard<container_t::lock_type> lock(*con);
		container_t::iterator ite = con->begin();
		container_t::reverse_iterator rite = con->rbegin();
		container_t::iterator ite_end = con->end();
		container_t::reverse_iterator rite_end = con->rend();
		container_t::iterator ite2 = con->rbegin();
		container_t::reverse_iterator rite2 = con->begin();
		container_t::iterator ite2_end = con->rend();
		container_t::reverse_iterator rite2_end = con->end();
		printf("constructor\n");
		if (ite.isExist()) printf("ite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite.isDeleted() ? '*' : ' ', ite.getIndex(), ite.getPrimaryIndex(), ite->m_key, ite->m_name, ite->m_value);
		if (rite.isExist()) printf("rite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite.isDeleted() ? '*' : ' ', rite.getIndex(), rite.getPrimaryIndex(), rite->m_key, rite->m_name, rite->m_value);
		if (ite_end.isExist()) printf("ite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite_end.isDeleted() ? '*' : ' ', ite_end.getIndex(), ite_end.getPrimaryIndex(), ite_end->m_key, ite_end->m_name, ite_end->m_value);
		if (rite_end.isExist()) printf("rite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite_end.isDeleted() ? '*' : ' ', rite_end.getIndex(), rite_end.getPrimaryIndex(), rite_end->m_key, rite_end->m_name, rite_end->m_value);
		if (ite2.isExist()) printf("ite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2.isDeleted() ? '*' : ' ', ite2.getIndex(), ite2.getPrimaryIndex(), ite2->m_key, ite2->m_name, ite2->m_value);
		if (rite2.isExist()) printf("rite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2.isDeleted() ? '*' : ' ', rite2.getIndex(), rite2.getPrimaryIndex(), rite2->m_key, rite2->m_name, rite2->m_value);
		if (ite2_end.isExist()) printf("ite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2_end.isDeleted() ? '*' : ' ', ite2_end.getIndex(), ite2_end.getPrimaryIndex(), ite2_end->m_key, ite2_end->m_name, ite2_end->m_value);
		if (rite2_end.isExist()) printf("rite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2_end.isDeleted() ? '*' : ' ', rite2_end.getIndex(), rite2_end.getPrimaryIndex(), rite2_end->m_key, rite2_end->m_name, rite2_end->m_value);
		printf("copy operator\n");
		ite = con->begin();
		rite = con->rbegin();
		ite_end = con->end();
		rite_end = con->rend();
		ite2 = con->rbegin();
		rite2 = con->begin();
		ite2_end = con->rend();
		rite2_end = con->end();
		if (ite.isExist()) printf("ite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite.isDeleted() ? '*' : ' ', ite.getIndex(), ite.getPrimaryIndex(), ite->m_key, ite->m_name, ite->m_value);
		if (rite.isExist()) printf("rite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite.isDeleted() ? '*' : ' ', rite.getIndex(), rite.getPrimaryIndex(), rite->m_key, rite->m_name, rite->m_value);
		if (ite_end.isExist()) printf("ite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite_end.isDeleted() ? '*' : ' ', ite_end.getIndex(), ite_end.getPrimaryIndex(), ite_end->m_key, ite_end->m_name, ite_end->m_value);
		if (rite_end.isExist()) printf("rite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite_end.isDeleted() ? '*' : ' ', rite_end.getIndex(), rite_end.getPrimaryIndex(), rite_end->m_key, rite_end->m_name, rite_end->m_value);
		if (ite2.isExist()) printf("ite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2.isDeleted() ? '*' : ' ', ite2.getIndex(), ite2.getPrimaryIndex(), ite2->m_key, ite2->m_name, ite2->m_value);
		if (rite2.isExist()) printf("rite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2.isDeleted() ? '*' : ' ', rite2.getIndex(), rite2.getPrimaryIndex(), rite2->m_key, rite2->m_name, rite2->m_value);
		if (ite2_end.isExist()) printf("ite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2_end.isDeleted() ? '*' : ' ', ite2_end.getIndex(), ite2_end.getPrimaryIndex(), ite2_end->m_key, ite2_end->m_name, ite2_end->m_value);
		if (rite2_end.isExist()) printf("rite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2_end.isDeleted() ? '*' : ' ', rite2_end.getIndex(), rite2_end.getPrimaryIndex(), rite2_end->m_key, rite2_end->m_name, rite2_end->m_value);
		for (int i = 0; i <= 3; ++i)
		{
			printf("[%d]\n", i);
			ite = ite[i];
			rite = rite[i];
			ite_end = ite_end[i];
			rite_end = rite_end[i];
			ite2 = ite2[i];
			rite2 = rite2[i];
			ite2_end = ite2_end[i];
			rite2_end = rite2_end[i];
			if (ite.isExist()) printf("ite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite.isDeleted() ? '*' : ' ', ite.getIndex(), ite.getPrimaryIndex(), ite->m_key, ite->m_name, ite->m_value);
			if (rite.isExist()) printf("rite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite.isDeleted() ? '*' : ' ', rite.getIndex(), rite.getPrimaryIndex(), rite->m_key, rite->m_name, rite->m_value);
			if (ite_end.isExist()) printf("ite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite_end.isDeleted() ? '*' : ' ', ite_end.getIndex(), ite_end.getPrimaryIndex(), ite_end->m_key, ite_end->m_name, ite_end->m_value);
			if (rite_end.isExist()) printf("rite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite_end.isDeleted() ? '*' : ' ', rite_end.getIndex(), rite_end.getPrimaryIndex(), rite_end->m_key, rite_end->m_name, rite_end->m_value);
			if (ite2.isExist()) printf("ite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2.isDeleted() ? '*' : ' ', ite2.getIndex(), ite2.getPrimaryIndex(), ite2->m_key, ite2->m_name, ite2->m_value);
			if (rite2.isExist()) printf("rite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2.isDeleted() ? '*' : ' ', rite2.getIndex(), rite2.getPrimaryIndex(), rite2->m_key, rite2->m_name, rite2->m_value);
			if (ite2_end.isExist()) printf("ite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2_end.isDeleted() ? '*' : ' ', ite2_end.getIndex(), ite2_end.getPrimaryIndex(), ite2_end->m_key, ite2_end->m_name, ite2_end->m_value);
			if (rite2_end.isExist()) printf("rite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2_end.isDeleted() ? '*' : ' ', rite2_end.getIndex(), rite2_end.getPrimaryIndex(), rite2_end->m_key, rite2_end->m_name, rite2_end->m_value);
		}
		printf("+= 3\n");
		ite += 3;
		rite += 3;
		ite_end += 3;
		rite_end += 3;
		ite2 += 3;
		rite2 += 3;
		ite2_end += 3;
		rite2_end += 3;
		if (ite.isExist()) printf("ite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite.isDeleted() ? '*' : ' ', ite.getIndex(), ite.getPrimaryIndex(), ite->m_key, ite->m_name, ite->m_value);
		if (rite.isExist()) printf("rite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite.isDeleted() ? '*' : ' ', rite.getIndex(), rite.getPrimaryIndex(), rite->m_key, rite->m_name, rite->m_value);
		if (ite_end.isExist()) printf("ite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite_end.isDeleted() ? '*' : ' ', ite_end.getIndex(), ite_end.getPrimaryIndex(), ite_end->m_key, ite_end->m_name, ite_end->m_value);
		if (rite_end.isExist()) printf("rite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite_end.isDeleted() ? '*' : ' ', rite_end.getIndex(), rite_end.getPrimaryIndex(), rite_end->m_key, rite_end->m_name, rite_end->m_value);
		if (ite2.isExist()) printf("ite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2.isDeleted() ? '*' : ' ', ite2.getIndex(), ite2.getPrimaryIndex(), ite2->m_key, ite2->m_name, ite2->m_value);
		if (rite2.isExist()) printf("rite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2.isDeleted() ? '*' : ' ', rite2.getIndex(), rite2.getPrimaryIndex(), rite2->m_key, rite2->m_name, rite2->m_value);
		if (ite2_end.isExist()) printf("ite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2_end.isDeleted() ? '*' : ' ', ite2_end.getIndex(), ite2_end.getPrimaryIndex(), ite2_end->m_key, ite2_end->m_name, ite2_end->m_value);
		if (rite2_end.isExist()) printf("rite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2_end.isDeleted() ? '*' : ' ', rite2_end.getIndex(), rite2_end.getPrimaryIndex(), rite2_end->m_key, rite2_end->m_name, rite2_end->m_value);
		printf("-= 3\n");
		ite -= 3;
		rite -= 3;
		ite_end -= 3;
		rite_end -= 3;
		ite2 -= 3;
		rite2 -= 3;
		ite2_end -= 3;
		rite2_end -= 3;
		if (ite.isExist()) printf("ite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite.isDeleted() ? '*' : ' ', ite.getIndex(), ite.getPrimaryIndex(), ite->m_key, ite->m_name, ite->m_value);
		if (rite.isExist()) printf("rite:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite.isDeleted() ? '*' : ' ', rite.getIndex(), rite.getPrimaryIndex(), rite->m_key, rite->m_name, rite->m_value);
		if (ite_end.isExist()) printf("ite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite_end.isDeleted() ? '*' : ' ', ite_end.getIndex(), ite_end.getPrimaryIndex(), ite_end->m_key, ite_end->m_name, ite_end->m_value);
		if (rite_end.isExist()) printf("rite_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite_end.isDeleted() ? '*' : ' ', rite_end.getIndex(), rite_end.getPrimaryIndex(), rite_end->m_key, rite_end->m_name, rite_end->m_value);
		if (ite2.isExist()) printf("ite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2.isDeleted() ? '*' : ' ', ite2.getIndex(), ite2.getPrimaryIndex(), ite2->m_key, ite2->m_name, ite2->m_value);
		if (rite2.isExist()) printf("rite2:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2.isDeleted() ? '*' : ' ', rite2.getIndex(), rite2.getPrimaryIndex(), rite2->m_key, rite2->m_name, rite2->m_value);
		if (ite2_end.isExist()) printf("ite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", ite2_end.isDeleted() ? '*' : ' ', ite2_end.getIndex(), ite2_end.getPrimaryIndex(), ite2_end->m_key, ite2_end->m_name, ite2_end->m_value);
		if (rite2_end.isExist()) printf("rite2_end:%c[%d](%d) key=0x%08x, name=\"%s\", value=%d\n", rite2_end.isDeleted() ? '*' : ' ', rite2_end.getIndex(), rite2_end.getPrimaryIndex(), rite2_end->m_key, rite2_end->m_name, rite2_end->m_value);
	}
#endif

	//ハッシュテーブルアクセス
	auto findTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Find Data ---\n");
		int find_success = 0;
		int find_failure = 0;
		for (int i = 0; i < TEST_DATA_TABLE_SIZE; ++i)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t* obj;
			crc32_t key;
			int index;
			int primary_index;
			bool is_primary_index;
			bool is_deleted;
			#define USE_FIND_TYPE 1
			//【推奨】【検索方法①】[]オペレータにキーを渡して検索する方法
			//※値を返す
			#if USE_FIND_TYPE == 1
			{
				obj = (*con)[name];
				if(obj)
				{
					key = obj->m_key;
					index = con->bucket(key);
					primary_index = con->calcIndex(key);
					is_primary_index = (index == primary_index);
					is_deleted = false;
				}
			}
			//【検索方法②】at()メソッドにキーを渡して検索する方法
			//※値を返す（[]オペレータと同じ）
			#elif USE_FIND_TYPE == 2
			{
				obj = con->at(name);
				if(obj)
				{
					key = obj->m_key;
					index = con->bucket(key);
					primary_index = con->calcIndex(key);
					is_primary_index = (index == primary_index);
					is_deleted = false;
				}
			}
			//【検索方法③】find()メソッドにキーを渡して検索する方法
			//※イテレータを返す
			#elif USE_FIND_TYPE == 3
			{
				container_t::iterator ite = con->find(name);
				obj = ite;
				if (obj)
				{
					key = ite.getKey();
					index = ite.getIndex();
					primary_index = ite.getPrimaryIndex();
					is_primary_index = ite.isPrimaryIndex();
					is_deleted = ite.isDeleted();
				}
			}
			#endif//USE_FIND_TYPE
			if (obj)
			{
				printf_detail("OK  %c[%6d](%6d) key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)%s\n", is_primary_index ? ' ' : '*', index, primary_index, key, obj->m_name, obj->m_value, con->bucket(key), con->bucket_size(index), is_deleted ? " <DELETED>" : "");
				++find_success;
			}
			else
			{
				printf_detail("NG\n");
				++find_failure;
			}
		}
		printf("success=%d, failure=%d\n", find_success, find_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	findTable();

	//ハッシュテーブルからのデータ削除
	auto eraseData = [&con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- Erase Data ---\n");
		int erase_success = 0;
		int erase_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			bool result = false;
			#define USE_ERASE_TYPE 1
			//【推奨】【削除方法①】erase()メソッドにキーを渡して削除する方法
			#if USE_ERASE_TYPE == 1
			{
				result = con->erase(calcCRC32(name));//キーを渡して削除
			}
			//【削除方法②】eraseAuto()メソッドにオブジェクトを渡して削除する方法
			//※操作用クラス base_ope_t の派生クラスで、getKey() を実装する必要あり
			#elif USE_INSERT_TYPE == 2
			{
				data_t obj(name, i);
				result = con->eraseAuto(obj);//オブジェクトを渡して削除
			}
			#endif//USE_ERASETYPE
			if (result)
			{
				++erase_success;
				printf_detail("OK\n");
			}
			else
			{
				++erase_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", erase_success, erase_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	eraseData(0, TEST_DATA_TABLE_SIZE, 2);
	
	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//ハッシュテーブルへのデータ登録
	insertData(1, TEST_DATA_TABLE_SIZE, 2);

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//リハッシュ
	auto rehashTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Rehash Table ---\n");
		con->rehash();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	rehashTable();

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//クリア
	auto clearTable = [&con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- Clear Table ---\n");
		con->clear();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	clearTable();

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//ハッシュテーブルへのデータ登録
	insertData(0, TEST_DATA_TABLE_SIZE, 1);

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();

	//ハッシュテーブルからのデータ削除
	eraseData(0, TEST_DATA_TABLE_SIZE, 1);

	//ハッシュテーブル状態表示
	printTableStatus();

	//ハッシュテーブル表示
	printTable();

	//ハッシュテーブルアクセス
	findTable();
	
	//--------------------
	//ハッシュテーブル削除
	delete con;
	con = nullptr;

	printf("\n");
	printf("End\n");
	printf("============================================================\n");
	begin_time = printElapsedTime(begin_time, true);//処理時間表示

	//----------------------------------------------------------------------------------------------------
	//【比較用】【STL版】ハッシュテーブルテスト
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[STL] Hash Table Test\n");
	printf("--------------------------------------------------------------------------------\n");
	typedef std::unordered_map<crc32_t, data_t> stl_container_t;
	stl_container_t* stl_con = new stl_container_t();
	stl_con->reserve(TEST_DATA_TABLE_SIZE);

	//ハッシュテーブルの基本情報表示
	auto printSTLTableParameter = [&stl_con]()
	{
		printf("\n");
		printf("--- [STL] Table Parameter ---\n");
		printf(".max_size()=%u\n", stl_con->max_size());
	};
	printSTLTableParameter();

	//テーブル状態表示
	auto printSTLTableStatus = [&stl_con]()
	{
		printf("\n");
		printf("--- [STL] Table Status ---\n");
		printf(".size()=%u\n", stl_con->size());
		printf(".empty()=%u\n", stl_con->empty());
		printf(".bucket_count()=%u\n", stl_con->bucket_count());
		printf(".max_bucket_count()=%u\n", stl_con->max_bucket_count());
		printf(".load_factor()=%u\n", stl_con->load_factor());
		printf(".max_load_factor()=%u\n", stl_con->max_load_factor());
	};
	printSTLTableStatus();

	//ハッシュテーブルへのデータ登録
	auto insertSTLData = [&stl_con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- [STL] Insert Data ---\n");
		int insert_success = 0;
		int insert_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			data_t obj(name, i);
			auto ite = stl_con->emplace(calcCRC32(name), obj);//キーとコンストラクタパラメータを渡して登録
			if (ite.second)
			{
				++insert_success;
				printf_detail("OK\n");
			}
			else
			{
				++insert_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", insert_success, insert_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	insertSTLData(0, TEST_DATA_TABLE_SIZE / 2, 1);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	auto printSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf_detail("\n");
		printf_detail("--- [STL] Print Table ---\n");
		//for (container_t::set& set : +con)
		for (auto& pair : *stl_con)
		{
			const crc32_t key = pair.first;
			const stl_container_t::size_type index = stl_con->bucket(key);
			printf_detail("[%6d] key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)\n", index, key, pair.second.m_name, pair.second.m_value, index, stl_con->bucket_size(index));
		}
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	printSTLTable();

	//ハッシュテーブルアクセス
	auto findSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Find Data ---\n");
		int find_success = 0;
		int find_failure = 0;
		for (int i = 0; i < TEST_DATA_TABLE_SIZE; ++i)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			crc32_t key = calcCRC32(name);
			auto ite = stl_con->find(key);
			if (ite != stl_con->end())
			{
				const crc32_t key = ite->first;
				const stl_container_t::size_type index = stl_con->bucket(key);
				printf_detail("OK  key=%08x, name=\"%s\", value=%d (bucket=%d, bucket_size=%d)\n", key, ite->second.m_name, ite->second.m_value, index, stl_con->bucket_size(index));
				++find_success;
			}
			else
			{
				printf_detail("NG\n");
				++find_failure;
			}
		}
		printf("success=%d, failure=%d\n", find_success, find_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	findSTLTable();

	//ハッシュテーブルからのデータ削除
	auto eraseSTLData = [&stl_con, &printElapsedTime, &prev_time](const int begin, const int end, const int step)
	{
		printf("\n");
		printf("--- [STL] Erase Data ---\n");
		int erase_success = 0;
		int erase_failure = 0;
		for (int i = begin; i < end; i += step)
		{
			char name[20];
			sprintf_s(name, sizeof(name), "Name_%06d", i);
			printf_detail("name=\"%s\" ... ", name);
			crc32_t key = calcCRC32(name);
			bool result = stl_con->erase(key) == 1;
			if (result)
			{
				++erase_success;
				printf_detail("OK\n");
			}
			else
			{
				++erase_failure;
				printf_detail("NG\n");
			}
		}
		printf("success=%d, failure=%d\n", erase_success, erase_failure);
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	eraseSTLData(0, TEST_DATA_TABLE_SIZE, 2);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//ハッシュテーブルへのデータ登録
	insertSTLData(1, TEST_DATA_TABLE_SIZE, 2);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//リハッシュ
	auto rehashSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Rehash Table ---\n");
		stl_con->rehash(TEST_DATA_TABLE_SIZE);
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	rehashSTLTable();

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//クリア
	auto clearSTLTable = [&stl_con, &printElapsedTime, &prev_time]()
	{
		printf("\n");
		printf("--- [STL] Clear Table ---\n");
		stl_con->clear();
		printf("OK.\n");
		const bool is_print = true;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	clearSTLTable();

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//ハッシュテーブルへのデータ登録
	insertSTLData(0, TEST_DATA_TABLE_SIZE, 1);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//ハッシュテーブルからのデータ削除
	eraseSTLData(0, TEST_DATA_TABLE_SIZE, 1);

	//ハッシュテーブル状態表示
	printSTLTableStatus();

	//ハッシュテーブル表示
	printSTLTable();

	//ハッシュテーブルアクセス
	findSTLTable();

	//--------------------
	//ハッシュテーブル削除
	delete stl_con;
	stl_con = nullptr;
	
	printf("\n");
	printf("End\n");
	printf("============================================================\n");
	printElapsedTime(begin_time, true);//処理時間表示

	//----------------------------------------------------------------------------------------------------
	//ポインタ型のハッシュテーブルテスト
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Hash Table Test for Pointer\n");
		printf("--------------------------------------------------------------------------------\n");

		//操作型
		struct p_ope_t : public hash_table::base_ope_t<p_ope_t, int, data_t*>
		{
			//データ置換属性
			//※デフォルト（NEVER_REPLACE）のままとする
			//static const replace_attr_t REPLACE_ATTR = REPLACE;//キーが重複するデータは置換して登録する
			
			//キーを取得
			inline static key_type getKey(const value_type& value){ return value->m_key; }

			//ロック型
			//※デフォルト（dummy_shared_lock）のままとする
			//typedef shared_spin_lock lock_type;//ロックオブジェクト型
		};

		//ハッシュテーブル
		hash_table::container<p_ope_t, 100> p_con;

		//登録
		data_t obj1("0010", 123);
		data_t obj2("0020", 456);
		data_t obj3("0030", 789);
		p_con.insert(10, &obj1);
		p_con.insert(20, &obj2);
		p_con.insert(30, &obj3);

		//検索して表示
		auto printObj = [&p_con](const int key)
		{
			printf("[%2d] ... ", key);
			data_t** p = p_con[key];
			if (p && *p)
				printf("OK  name=\"%s\", val=%d\n", (*p)->m_name, (*p)->m_value);
			else
				printf("NG\n");
		};
		printObj(10);
		printObj(20);
		printObj(30);
		printObj(40);

		//ロック取得テスト
		{
			shared_lock_guard<p_ope_t::lock_type> lock(p_con);//共有ロック（リードロック）取得（処理ブロックを抜ける時に自動開放）
			printObj(20);
		}
	}

	//----------------------------------------------------------------------------------------------------
	//関数型のハッシュテーブルテスト
	//※スクリプトなどから関数名（文字列）で関数を実行するような用途を想定
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Hash Table Test for Function\n");
		printf("--------------------------------------------------------------------------------\n");
		
		//操作型 ※単純な関数呼び出し用
		struct func_ope_t : public hash_table::base_ope_t<func_ope_t, crc32_t, std::function<int(int, int)>>
		{
		};
		
		//オブジェクトメンバー関数呼び出しテスト用
		struct data_t
		{
			int calc(int a, int b)
			{
				return (a + b) * m_val;
			}
			data_t(const int val) :
				m_val(val)
			{}
		private:
			int m_val;
		};

		//操作型 ※オブジェクトメンバー関数呼び出し用
		struct obj_ope_t : public hash_table::base_ope_t<func_ope_t, crc32_t, std::function<int(data_t&, int, int)>>
		{
		};

		//ハッシュテーブル
		hash_table::container<func_ope_t, 100> func_con;
		hash_table::container<obj_ope_t, 100> obj_con;

		//関数型ハッシュテーブルテスト用関数：通常関数
		extern int func_add(int a, int b);

		//関数型ハッシュテーブルテスト用関数：関数オブジェクト
		struct func_sub{
			int operator()(int a, int b)
			{
				return a - b;
			};
		};

		//関数型ハッシュテーブルテスト用関数：ラムダ関数
		auto func_mul = [](int a, int b) -> int
		{
			return a * b;
		};

		//関数型ハッシュテーブルテスト用関数：ラムダ関数
		auto func_div = [](int a, int b) -> int
		{
			return a / b;
		};

		//登録
		func_con.emplace("+", func_add);
		func_con.emplace("-", func_sub());
		func_con.emplace("*", func_mul);
		func_con.emplace("/", std::bind(func_div, 50, 4));//std::bindを使用
		obj_con.emplace("calc", std::mem_fn(&data_t::calc));//クラスメンバー関数の場合

		//検索して実行
		printf("50 + 4 = %d\n", (*func_con["+"])(50, 4));
		printf("50 - 4 = %d\n", (*func_con["-"])(50, 4));
		printf("50 * 4 = %d\n", (*func_con["*"])(50, 4));
		printf("50 / 4 = %d\n", (*func_con["/"])(0, 0));//std::bind()で事前にパラメータがセット済み
		data_t obj(3);
		printf("obj.calc(1, 2) = %d\n", (*obj_con["calc"])(obj, 1, 2));//クラスメンバー関数の場合、オブジェクトを渡す必要がある
	}

	return EXIT_SUCCESS;
}

//関数型ハッシュテーブルテスト用関数：通常関数
int func_add(int a, int b)
{
	return a + b;
};

// End of file
