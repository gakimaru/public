#include "sub.h"

#include <random>//C++11 std::random用

//----------------------------------------
//最適化①：メモリアクセスの抑制：一時変数の活用

//初期化
void initOpt01(dataOpt01_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt01_t::elem_t::VALUE_RANGE - 1);
	data.sum = 0;
	for (auto& elems : data.elems)
	{
		elems.value = rnd_dist(rnd_engine);
	}
}

//【タイプ１】最適化前
//※単純な配列ループアクセス
void testOpt01_Type1_Before(dataOpt01_t& data)
{
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
		data.sum += data.elems[i].value;
}

//【タイプ１】最適化後１
//※一時変数を用意してループ中のメンバー変数へのアクセスを減らす
void testOpt01_Type1_After1(dataOpt01_t& data)
{
	int sum_tmp = 0;
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
		sum_tmp += data.elems[i].value;
	data.sum = sum_tmp;
}

//【タイプ１】最適化後２
//※ポインタ計算に置き換えてループカウンタを無くす
void testOpt01_Type1_After2(dataOpt01_t& data)
{
	int sum_tmp = 0;
	const dataOpt01_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum_tmp += elem_p->value;
	data.sum = sum_tmp;
}

//【タイプ１】【参考】C++11でもっとも簡潔な記述
//※C++11の範囲に基づくforループを使用し、最も簡潔に記述したコード（遅い）
void testOpt01_Type1_Appendix(dataOpt01_t& data)
{
	for (auto elems : data.elems)
		data.sum += elems.value;
}

//----------------------------------------
//最適化②：メモリアクセスの抑制：アドレス計算の削減

//初期化
void initOpt02(dataOpt02_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt02_t::elem_t::VALUE_RANGE - 1);
	for (auto& elems : data.elems)
	{
		elems.value = rnd_dist(rnd_engine);
	}
}

//【タイプ１】最適化前
//※ループ処理で配列要素を直接指定
int testOpt02_Type1_Before(dataOpt02_t& data)
{
	//分布集計用構造体
	struct dist_t
	{
		int value;
		int count;
	};
	//分布集計用変数初期化
	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
	{
		dist[value].value = value;
		dist[value].count = 0;
	}
	//分布集計
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
		++dist[data.elems[i].value].count;
	//最大分布取得
	const dist_t* top_dist_p = &dist[0];
	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
	{
		if (top_dist_p->count < dist[i].count)
			top_dist_p = &dist[i];
	}
	return (top_dist_p->count << 16) | top_dist_p->value;
}

//【タイプ１】最適化後１
//※分布集計だけポインタ計算に変更
int testOpt02_Type1_After1(dataOpt02_t& data)
{
	//分布集計用構造体
	struct dist_t
	{
		int value;
		int count;
	};
	//分布集計用変数初期化
	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
	{
		dist[value].value = value;
		dist[value].count = 0;
	}
	//分布集計
	{
		const dataOpt02_t::elem_t* end = data.elems + extentof(data.elems);
		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
			++dist[elem_p->value].count;
	}
	//最大分布取得
	const dist_t* top_dist_p = &dist[0];
	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
	{
		if (top_dist_p->count < dist[i].count)
			top_dist_p = &dist[i];
	}
	return (top_dist_p->count << 16) | top_dist_p->value;
}

//【タイプ１】最適化後２
//※徹底的にポインタ計算に変更
int testOpt02_Type1_After2(dataOpt02_t& data)
{
	//分布集計用構造体
	struct dist_t
	{
		int value;
		int count;
	};
	//分布集計用変数初期化
	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
	const dist_t* dist_end = dist + dataOpt02_t::elem_t::VALUE_RANGE;
	{
		int value = 0;
		for (dist_t* dist_p = dist; dist_p < dist_end; ++dist_p)
		{
			dist_p->value = value++;
			dist_p->count = 0;
		}
	}
	//分布集計
	{
		const dataOpt02_t::elem_t* end = data.elems + extentof(data.elems);
		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
			++dist[elem_p->value].count;
	}
	//最大分布取得
	const dist_t* top_dist_p = dist;
	{
		for (const dist_t* dist_p = top_dist_p + 1; dist_p < dist_end; ++dist_p)
		{
			if (top_dist_p->count < dist_p->count)
				top_dist_p = dist_p;
		}
	}
	return (top_dist_p->count << 16) | top_dist_p->value;
}

//----------------------------------------
//最適化③：メモリアクセスの抑制：関数呼び出しの削減

//【タイプ１】最適化前
//※通常関数
int testOpt03_Type1_Before(int a, int b, int c)
{
	return a * b + c;
}

//【タイプ１】最適化後
//※インライン関数
//inline int testOpt03_Type1_Before(int a, int b, int c)
//※sub.hに定義

//【タイプ２】最適化前
//※引数の多い通常関数
int testOpt03_Type2_Before(int a, int b, int c, int d, int e, int f, int g, int h)
{
	return a * b + c - d * e + f - g * h;
}

//【タイプ２】最適化後
//※インライン関数
//inline int testOpt03_Type2_Before(int a, int b, int c, int d, int e, int f, int g, int h)
//※sub.hに定義

//【タイプ３】初期化
void initOpt03_Type3(dataOpt03_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt03_t::VALUE_RANGE - 1);
	for (auto& value : data.values)
	{
		value = rnd_dist(rnd_engine);
	}
}

//【タイプ３】最適化前：共通関数
//※オブザーバー（コールバック）を std::function 型で受け取る
#include <functional>//C++11 std::function用
template <typename T, std::size_t N>
void commonProc_testOpt03_Type3_Before(T(&values)[N], const T find, std::function<void(int&)> observer)
{
	//配列から値を検索し、見つけたらオブザーバーを呼び出す
	const T* end = values + N;
	for (T* value_p = values; value_p < end; ++value_p)
	{
		if (*value_p == find)
			observer(*value_p);
	}
}

//【タイプ３】最適化後：共通関数
//※オブザーバー（コールバック）をテンプレートで型展開して受け取る（std::sort などと同じやり方）
template < typename T, std::size_t N, class OBSERVER>
void commonProc_testOpt03_Type3_After(T(&values)[N], const T find, OBSERVER observer)
{
	//配列から値を検索し、見つけたらオブザーバーを呼び出す
	const T* end = values + N;
	for (T* value_p = values; value_p < end; ++value_p)
	{
		if (*value_p == find)
			observer(*value_p);
	}
}

//【タイプ３】最適化前
//※最適化前の共通関数を使用
int testOpt03_Type3_Before(dataOpt03_t& data)
{
	//配列内の値を検索して別の値に置き換えるラムダ式
	//※変数data/exchangeをキャプチャしたクロ―ジャとして振る舞う
	auto exchangeData = [&data](const int find, const int exchange)
	{
		commonProc_testOpt03_Type3_Before(data.values, 0,
			[&exchange](int& value)
			{
				value = exchange;
			}
		);
	};
	//配列内の値を検索して出現数を算出するラムダ式
	//※変数data/countをキャプチャしたクロ―ジャとして振る舞う
	auto countData = [&data](const int find) -> int
	{
		int count = 0;
		commonProc_testOpt03_Type3_Before(data.values, find,
			[&count](int& value)
			{
				++count;
			}
		);
		return count;
	};
	//値の置き換え
	exchangeData(0, 1);
	//値の出現数の合計を返す
	return countData(1) + countData(2) + countData(3);
}

//【タイプ３】最適化後
//※最適化後の共通関数を使用
int testOpt03_Type3_After(dataOpt03_t& data)
{
	//配列内の値を検索して別の値に置き換えるラムダ式
	//※変数data/exchangeをキャプチャしたクロ―ジャとして振る舞う
	auto exchangeData = [&data](const int find, const int exchange)
	{
		commonProc_testOpt03_Type3_After(data.values, 0,
			[&exchange](int& value)
			{
				value = exchange;
			}
		);
	};
	//配列内の値を検索して出現数を算出するラムダ式
	//※変数data/countをキャプチャしたクロ―ジャとして振る舞う
	auto countData = [&data](const int find) -> int
	{
		int count = 0;
		commonProc_testOpt03_Type3_After(data.values, find,
			[&count](int& value)
			{
				++count;
			}
		);
		return count;
	};
	//値の置き換え
	exchangeData(0, 1);
	//値の出現数の合計を返す
	return countData(1) + countData(2) + countData(3);
}

//----------------------------------------
//最適化④：除算の抑制：乗算に変更

//初期化
void initOpt04(dataOpt04_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt04_t::elem_t::VALUE_RANGE - 1);
	for (auto& elems : data.elems)
	{
		elems.value = rnd_dist(rnd_engine);
		elems.ratio = 0.f;
	}
}

//【タイプ１】最適化前
//※素直な浮動小数点データ演算、および、除算
void testOpt04_Type1_Before(dataOpt04_t& data)
{
	//合計値算出
	float sum = 0.f;
	const dataOpt04_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum += static_cast<float>(elem_p->value);
	//各要素の分布比率を算出
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->ratio = static_cast<float>(elem_p->value) / sum;
}

//【タイプ１】最適化後１
//※除算を乗算に変更
void testOpt04_Type1_After1(dataOpt04_t& data)
{
	//合計値算出
	float sum = 0.f;
	const dataOpt04_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum += static_cast<float>(elem_p->value);
	//各要素の分布比率を算出
	const float base_ratio = 1.f / sum;
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->ratio = static_cast<float>(elem_p->value) * base_ratio;
}

//【タイプ１】最適化後２
//※浮動小数点演算の数を減らす（整数演算のままでよいところは整数演算する）
void testOpt04_Type1_After2(dataOpt04_t& data)
{
	//合計値算出
	int sum = 0;
	const dataOpt04_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum += elem_p->value;
	//各要素の分布比率を算出
	const float base_ratio = 1.f / static_cast<float>(sum);
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->ratio = static_cast<float>(elem_p->value) * base_ratio;
}

//----------------------------------------
//追加テスト：ラダムダ式のキャプチャーテスト（クロージャとしてどこまで使えるか？）
#include <stdio.h>//printf用
#include <functional>//C++11 std::function用
std::function<int()> s_lambda1 = nullptr;
std::function<int()> s_lambda2 = nullptr;
std::function<int()> s_lambda3 = nullptr;
void callLambda123()
{
	printf("lambda1()=%d, lambda2()=%d, lambda3()=%d\n", s_lambda1(), s_lambda2(), s_lambda3());
}
void callLambda13()
{
	printf("lambda1()=%d, lambda2()=NG!, lambda3()=%d\n", s_lambda1(), s_lambda3());
}
void setLambda(int& external_counter)
//external_counter ... 外部変数（上位のローカル変数の可能性あり）：lambda1でキャプチャ／クロージャのレキシカル変数
{
	if (!s_lambda1 || !s_lambda2)
	{
		int local_counter = 0;//ローカル変数：lambda2でキャプチャ／クロージャのレキシカル変数
		static int static_counter = 0;//ローカル静的変数：lambda3で使用（キャプチャ不要）／クロージャのレキシカル変数と呼んで差し支えない？
		printf("for lambda1: external_counter=%d\n", external_counter);
		printf("for lambda2: local_counter=%d\n", local_counter);
		printf("for lambda3: static_counter=%d\n", static_counter);
		s_lambda1 = [&external_counter]() -> int { return ++external_counter; };
		s_lambda2 = [&local_counter]() -> int { return ++local_counter; };
		s_lambda3 = []() -> int { return ++static_counter; };
		printf("Call lambda in block with counter in setLambda().\n");
		callLambda123();
		callLambda123();
		callLambda123();
	}
	{
		int dummy = 999;
		printf("dummy=%d\n", dummy);
		printf("Call lambda in block without counter in setLambda().\n");
		callLambda123();
		callLambda123();
		callLambda123();
	}
}
auto getLambda1() -> decltype(s_lambda1)
{
	return s_lambda1;
}
auto getLambda2() -> decltype(s_lambda2)
{
	return s_lambda1;
}

// End of file
