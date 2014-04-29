#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//std::size_t用
#include <bitset>//std::bitset用

#define FOR_UNIX//UNIX版でコンパイルするときは、このマクロを有効化する
#ifdef FOR_UNIX
#include "../StaticCRC32_unix/constexpr.h"
#else//FOR_UNIX
#include "../../StaticCRC32/StaticCRC32/src/constexpr/constexpr.h"
#endif//FOR_UNIX

//--------------------------------------------------------------------------------
//【ランタイム版】素数計算

//【ランタイム版】素数判定
bool isPrime(const std::size_t n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if ((n & 0x1) == 0x0)//偶数判定
		return false;
	for (std::size_t div = 3; div <= n / div; div += 2)
	{
		if (n % div == 0)
			return false;
	}
	return true;
}
//【ランタイム版】前の素数を生成
std::size_t makePrimePrev(const std::size_t n)
{
	if (n <= 2)
		return 0;
	else if (n == 3)
		return 2;
	for (std::size_t nn = n - ((n & 0x1) == 0x0 ? 1 : 2);; nn -= 2)//※偶数は判定しない
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//【ランタイム版】次の素数を生成
std::size_t makePrimeNext(const std::size_t n)
{
	if (n < 2)
		return 2;
	for (std::size_t nn = n + ((n & 0x1) == 0x0 ? 1 : 2);; nn += 2)//※偶数は判定しない
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//【ランタイム版】指定の値と同じか、前の素数を生成
std::size_t makePrimeEqPrev(const std::size_t n)
{
	return isPrime(n) ? n : makePrimePrev(n);
}
//【ランタイム版】指定の値と同じか、次の素数を生成
std::size_t makePrimeEqNext(const std::size_t n)
{
	return isPrime(n) ? n : makePrimeNext(n);
}

//--------------------------------------------------------------------------------
//【メタプログラミング版】素数計算

//【注意】
// メタプログラミング版では、コンパイラに応じてテンプレートの再帰レベルの限界がある。
// このため、実質 100001 ぐらいまでの素数しか扱えない点に注意。
// 他のテンプレート内で使うと、もっと制約を受ける点にも注意。
// また、コンパイル時間に影響がある点にも注意。

//【メタプログラミング版：共通処理】固定値を返すクラス
template<typename T, T V>
struct _primeMeta_Fixed{//固定値(V)のためのクラス ※演算クラスの結果を得るときと一様の用法（class_name::value）が必要なため
	static const T value = V;
};

//【メタプログラミング版：共通処理】三項演算子代わりに条件判定に基づいて値を返すクラス
template <typename T, bool COND, class TRUE_VALUE, class FALSE_VALUE>
struct _primeMeta_EnalbeIf;
template <typename T, class TRUE_VALUE, class FALSE_VALUE>//※判定結果がtrueの時用の特殊化
struct _primeMeta_EnalbeIf<T, true, TRUE_VALUE, FALSE_VALUE>{
	static const T value = TRUE_VALUE::value;
};
template <typename T, class TRUE_VALUE, class FALSE_VALUE>//※判定結果がfalseの時用の特殊化
struct _primeMeta_EnalbeIf<T, false, TRUE_VALUE, FALSE_VALUE>{
	static const T value = FALSE_VALUE::value;
};

//【メタプログラミング版】素数判定
//※偶数の判定を避けるために階層化する
template <std::size_t N, std::size_t DIV>//再帰クラス
struct _isPrimeMeta{
	static const bool value =
			_primeMeta_EnalbeIf<bool, (DIV > N / DIV),
				_primeMeta_Fixed<bool, true>,
				_primeMeta_EnalbeIf<bool, (N % DIV == 0),
					_primeMeta_Fixed<bool, false>,
					_isPrimeMeta<N, DIV + 2>
			>
		>::value;
};
template <std::size_t N>//素数判定クラス
struct isPrimeMeta{
	static const bool value =
		_primeMeta_EnalbeIf<bool, (N & 0x1) == 0x0,
			_primeMeta_Fixed<bool, false>,
			_isPrimeMeta<N, 3>
		>::value;
};
template <>
struct isPrimeMeta<0>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<1>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<2>{
	static const bool value = true;
};

//【メタプログラミング版】前の素数を生成
//※偶数の判定を避けるために階層化する
template<std::size_t N>//再帰クラス
struct _makePrimePrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			_makePrimePrevMeta<N - 2>
		>::value;
};
template<std::size_t N>//前の素数生成クラス
struct makePrimePrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, (N & 0x1) == 0x0,
			_makePrimePrevMeta<N - 1>,
			_makePrimePrevMeta<N - 2>
		>::value;
};
template<>
struct makePrimePrevMeta<0>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<1>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<2>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<3>{
	static const std::size_t value = 2;
};

//【メタプログラミング版】次の素数を生成
//※偶数の判定を避けるために階層化する
template<std::size_t N>//再帰クラス
struct _makePrimeNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			_makePrimeNextMeta<N + 2>
		>::value;
};
template<std::size_t N>//次の素数生成クラス
struct makePrimeNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, (N & 0x1) == 0x0,
			_primeMeta_Fixed<std::size_t, N + 1>,
			_makePrimeNextMeta<N + 2>
		>::value;
};
template<>
struct makePrimeNextMeta<0>{
	static const std::size_t value = 2;
};
template<>
struct makePrimeNextMeta<1>{
	static const std::size_t value = 2;
};

//【メタプログラミング版】指定の値と同じか、前の素数を生成
template<std::size_t N>
struct makePrimeEqPrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			makePrimePrevMeta<N>
		>::value;
};

//【メタプログラミング版】指定の値と同じか、次の素数を生成
template<std::size_t N>
struct makePrimeEqNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			makePrimeNextMeta<N>
		>::value;
};

//--------------------------------------------------------------------------------
//ハッシュテーブル
template <class T, typename KEY_TYPE, std::size_t N>
class hash_table
{
public:
	static const std::size_t ORIGINAL_TABLE_SIZE = N;//テーブルサイズ（元々指定されたサイズ）
	static const std::size_t TABLE_SIZE = makePrimeEqNextMeta<N>::value;//テーブルサイズ（指定サイズと同じか、それより大きい素数）
	static const std::size_t PRIME = makePrimePrevMeta<N>::value;//ハッシュキー生成用素数（指定サイズより小さい素数）
public:
	//フィールド
	std::size_t getOriginalTableSize() const { return ORIGINAL_TABLE_SIZE; }
	std::size_t getTableSize() const { return TABLE_SIZE; }
	std::size_t getPrime() const { return PRIME; }
public:
	//メソッド
	inline std::size_t calcNextHash(const std::size_t hash) const { return (hash + PRIME) % TABLE_SIZE; }//次のハッシュ値を計算
public:
	//コンストラクタ
	hash_table():
		m_deleted(),
		m_used(0),
		m_maxSearch(0)
	{}
	//デストラクタ
	~hash_table()
	{}
private:
	T m_table[TABLE_SIZE];//データテーブル
	KEY_TYPE m_keyTable[TABLE_SIZE];//キーテーブル
	std::bitset<TABLE_SIZE> m_deleted;//削除済みフラグ
	std::size_t m_used;//使用中データ数
	std::size_t m_maxSearch;//最大検索回数 ※登録を削除しても減らない
};

//--------------------------------------------------------------------------------
//テスト

//【ランタイム版】素数表示
void printPrime(const std::size_t min, const std::size_t max)
{
	if (max > min)
		printPrime(min, max - 1);
	printf("%3d is %s [prev=%d(%d), next=%d(%d)]\n", max, isPrime(max) ? "PRIME.    " : "not prime.", makePrimePrev(max), makePrimeEqPrev(max), makePrimeNext(max), makePrimeEqNext(max));
}

//【メタプログラミング版】素数表示
template<std::size_t N>
void _printPrimeCommon()
{
	printf("%3d is %s [prev=%d(%d), next=%d(%d)]\n", N, isPrimeMeta<N>::value ? "PRIME.    " : "not prime.", makePrimePrevMeta<N>::value, makePrimeEqPrevMeta<N>::value, makePrimeNextMeta<N>::value, makePrimeEqNextMeta<N>::value);
}
template<std::size_t MIN, std::size_t MAX>
struct printPrimeMeta{
	void operator()()
	{
		printPrimeMeta<MIN, MAX - 1>()();
		_printPrimeCommon<MAX>();
	}
};
template<std::size_t MIN>
struct printPrimeMeta<MIN, MIN>{
	void operator()()
	{
		_printPrimeCommon<MIN>();
	}
};

//----------------------------------------
//テストメイン
int main(const int argc, const char* argv[])
{
#if 0
	//再帰レベル限界チェック
	static const std::size_t x = 9999;
	printf("x=%d\n", x);
	printf("  isPrime=%s\n", isPrimeMeta<x>::value ? "true" : "False");
	printf("  prev=%d\n", makePrimePrevMeta<x>::value);
	printf("  next=%d\n", makePrimeNextMeta<x>::value);
	printf("  equalPrev=%d\n", makePrimeEqPrevMeta<x>::value);
	printf("  equalNext=%d\n", makePrimeEqNextMeta<x>::value);
#endif
#if 1
	static const std::size_t MIN = 9970;
	static const std::size_t MAX = 10020;
	
	printf("----- Check and Make Prime for Runtime -----\n");
	printPrime(MIN, MAX);
	
	printf("----- Check and Make Prime for Meta-Programming -----\n");
	printPrimeMeta<MIN, MAX>()();
	
	printf("----- Hash Table -----\n");
	static const size_t TABLE_SIZE = 1024;//1031;
	hash_table<int, int, TABLE_SIZE> table;
	printf("hash_table: .getOriginalTableSize()=%u, .getTableSize()=%u, .getPrime()=%u\n", table.getOriginalTableSize(), table.getTableSize(), table.getPrime());
	
	//ハッシュテーブルテスト
	//※全てのハッシュ値が、正確にテーブルサイズ（素数）回の再計算（ハッシュ値を変更する）を行う事で、元のハッシュ値に戻ることをチェックする。
	int ng_count = 0;
	for (int hash = 0; hash < TABLE_SIZE; ++hash)
	{
		std::size_t count = 0;
		int next_hash = hash;
		do
		{
			next_hash = table.calcNextHash(next_hash);
			++count;
		} while (next_hash != hash && count < table.getTableSize());
		if (count != table.getTableSize())
		{
			printf("%d is OUT! (count=%d)\n", hash, count);
			++ng_count;
		}
	}
	printf("Chek Hash Table: NG=%d/%d\n", ng_count, TABLE_SIZE);
#endif
	return EXIT_SUCCESS;
}

// End of file
