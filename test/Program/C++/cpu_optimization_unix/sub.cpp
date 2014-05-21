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
//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更

//【タイプ１】最適化前
template<int N>
inline int intMul(const int val){ return val * N; }
template<int N>
inline int intDiv(const int val){ return val / N; }
template<int N>
inline int intMod(const int val){ return val % N; }
int testOpt05_Type1_Before(const int val, 
                           int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						   int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						   int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
{
	m2 = intMul<2>(val);
	m3 = intMul<3>(val);
	m4 = intMul<4>(val);
	m5 = intMul<5>(val);
	m10 = intMul<10>(val);
	m16 = intMul<16>(val);
	m24 = intMul<24>(val);
	d2 = intDiv<2>(val);
	d3 = intDiv<3>(val);
	d4 = intDiv<4>(val);
	d5 = intDiv<5>(val);
	d10 = intDiv<10>(val);
	d16 = intDiv<16>(val);
	d24 = intDiv<24>(val);
	r2 = intMod<2>(val);
	r3 = intMod<3>(val);
	r4 = intMod<4>(val);
	r5 = intMod<5>(val);
	r10 = intMod<10>(val);
	r16 = intMod<16>(val);
	r24 = intMod<24>(val);
	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
	       d2 + d3 + d4 + d5 + d10 + d16 + d24 + 
	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
}
//【タイプ１】最適化後
#include <iostream>
#include <exception>
//※乗算のレイテンシを5と仮定し、シフト演算を1加算を1として、計5未満ならシフト演算と加算に展開した特殊化を適用する
template<int N> inline int intMulOpt(const int val){ return val * N; }
template<>      inline int intMulOpt<0>(const int val){ return 0; }
template<>      inline int intMulOpt<1>(const int val){ return val; }
template<>      inline int intMulOpt<2>(const int val){ return val << 1; }
template<>      inline int intMulOpt<3>(const int val){ return (val << 1) + val; }
template<>      inline int intMulOpt<4>(const int val){ return val << 2; }
template<>      inline int intMulOpt<5>(const int val){ return (val << 2) + val; }
template<>      inline int intMulOpt<6>(const int val){ return (val << 2) + (val << 1); }
template<>      inline int intMulOpt<7>(const int val){ return (val << 2) + (val << 1) + val; }
template<>      inline int intMulOpt<8>(const int val){ return val << 3; }
template<>      inline int intMulOpt<9>(const int val){ return (val << 3) + val; }
template<>      inline int intMulOpt<10>(const int val){ return (val << 3) + (val << 1); }
template<>      inline int intMulOpt<11>(const int val){ return (val << 3) + (val << 1) + val; }
template<>      inline int intMulOpt<12>(const int val){ return (val << 3) + (val << 2); }
template<>      inline int intMulOpt<13>(const int val){ return (val << 3) + (val << 2) + val; }
template<>      inline int intMulOpt<16>(const int val){ return val << 4; }
template<>      inline int intMulOpt<20>(const int val){ return (val << 4) + (val << 2); }
template<>      inline int intMulOpt<24>(const int val){ return (val << 4) + (val << 3); }
template<>      inline int intMulOpt<32>(const int val){ return val << 5; }
template<>      inline int intMulOpt<64>(const int val){ return val << 6; }
template<>      inline int intMulOpt<128>(const int val){ return val << 7; }
template<>      inline int intMulOpt<256>(const int val){ return val << 8; }
template<>      inline int intMulOpt<512>(const int val){ return val << 9; }
template<>      inline int intMulOpt<1024>(const int val){ return val << 10; }
//template<int N> inline int intDivOpt(const int val){ return (static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) >> 32; }//逆数を定数化して整数演算
//template<int N> constexpr int getReciprocalDivisor(){ return static_cast<int>(0xffffffffll / static_cast<long long>(N)); }
//template<int N> inline int intDivOpt(const int val)//逆数を定数化して整数演算（インラインアセンブラ版）
//{
//	//return (static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) >> 32;
//	const int rec = getReciprocalDivisor<N>();
//	__asm
//	{
//		mov     eax, rec	//eax ← rec
//		mul     val			//edx:eax ← eax * val
//		add     eax, 32		//eax ← eax + 32
//		adc     edx, 0		//edx ← edx + 0 + キャリーフラグ
//		mov     eax, edx	//eax ← edx ※戻り値
//	}
//}
//template<int N> inline int intDivOpt(const int val){ return static_cast<int>(static_cast<float>(val) * (1.f / (static_cast<float>(N)))); }//逆数を定数化して浮動小数点演算した後に整数化
template<int N> inline int intDivOpt(const int val){ return val / N; }//そのまま演算
template<>      inline int intDivOpt<0>(const int val){ throw std::overflow_error("Integer division by zero");	return 0; }
template<>      inline int intDivOpt<1>(const int val){ return val; }
template<>      inline int intDivOpt<2>(const int val){ return val >> 1; }
template<>      inline int intDivOpt<4>(const int val){ return val >> 2; }
template<>      inline int intDivOpt<8>(const int val){ return val >> 3; }
template<>      inline int intDivOpt<16>(const int val){ return val >> 4; }
template<>      inline int intDivOpt<32>(const int val){ return val >> 5; }
template<>      inline int intDivOpt<64>(const int val){ return val >> 6; }
template<>      inline int intDivOpt<128>(const int val){ return val >> 7; }
template<>      inline int intDivOpt<256>(const int val){ return val >> 8; }
template<>      inline int intDivOpt<512>(const int val){ return val >> 9; }
template<>      inline int intDivOpt<1024>(const int val){ return val >> 10; }
//template<int N> inline int intModOpt(const int val){ return (((static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) & 0xffffffffll) * static_cast<long long>(N)) >> 32; }//逆数を定数化して整数演算
//template<int N> inline int intModOpt(const int val)//逆数を定数化して整数演算（インラインアセンブラ版）
//{
//	//return (((static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) & 0xffffffffll) * static_cast<long long>(N)) >> 32;
//	const int rec = getReciprocalDivisor<N>();
//	const int n = N;
//	__asm
//	{
//		mov     eax, rec	//eax ← rec
//		mul     val			//edx:eax ← eax * val
//		add     eax, 32		//eax ← eax + 32
//		mul     n           //edx:eax ← eax * N
//		mov     eax, edx	//eax ← edx ※戻り値
//	}
//}
//template<int N> inline int intModOpt(const int val){ return val - static_cast<int>(static_cast<float>(val)* (1.f / (static_cast<float>(N)))) * N; }//逆数を定数化して浮動小数点演算した後に整数化
template<int N> inline int intModOpt(const int val){ return val % N; }//そのまま演算
template<>      inline int intModOpt<0>(const int val){ throw std::overflow_error("Integer division by zero");	return 0; }
template<>      inline int intModOpt<1>(const int val){ return 0; }
template<>      inline int intModOpt<2>(const int val){ return val & (2 - 1); }
template<>      inline int intModOpt<4>(const int val){ return val & (4 - 1); }
template<>      inline int intModOpt<8>(const int val){ return val & (8 - 1); }
template<>      inline int intModOpt<16>(const int val){ return val & (16 - 1); }
template<>      inline int intModOpt<32>(const int val){ return val & (32 - 1); }
template<>      inline int intModOpt<64>(const int val){ return val & (64 - 1); }
template<>      inline int intModOpt<128>(const int val){ return val & (128 - 1); }
template<>      inline int intModOpt<256>(const int val){ return val & (256 - 1); }
template<>      inline int intModOpt<512>(const int val){ return val & (512 - 1); }
template<>      inline int intModOpt<1024>(const int val){ return val & (1024 - 1); }
int testOpt05_Type1_After(const int val,
                          int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						  int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						  int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
{
	m2 = intMulOpt<2>(val);
	m3 = intMulOpt<3>(val);
	m4 = intMulOpt<4>(val);
	m5 = intMulOpt<5>(val);
	m10 = intMulOpt<10>(val);
	m16 = intMulOpt<16>(val);
	m24 = intMulOpt<24>(val);
	d2 = intDivOpt<2>(val);
	d3 = intDivOpt<3>(val);
	d4 = intDivOpt<4>(val);
	d5 = intDivOpt<5>(val);
	d10 = intDivOpt<10>(val);
	d16 = intDivOpt<16>(val);
	d24 = intDivOpt<24>(val);
	r2 = intModOpt<2>(val);
	r3 = intModOpt<3>(val);
	r4 = intModOpt<4>(val);
	r5 = intModOpt<5>(val);
	r10 = intModOpt<10>(val);
	r16 = intModOpt<16>(val);
	r24 = intModOpt<24>(val);
	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
	       d2 + d3 + d4 + d5 + d10 + d16 + d24 +
	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
}

//----------------------------------------
//最適化⑥：乗算／除算の抑制：演算の共通化

//初期化
void initOpt06(dataOpt06_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_real_distribution<float> rnd_dist(0.f, static_cast<float>(dataOpt06_t::elem_t::VALUE_RANGE));
	for (auto& elems : data.elems)
	{
		elems.value = rnd_dist(rnd_engine);
		elems.result = 0.f;
	}
}

//【タイプ１】最適化前
//※素直な乗除算
void testOpt06_Type1_Before(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	//各要素を計算
	const dataOpt06_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt06_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->result = elem_p->value * mul1 * mul2 / div;
}

//【タイプ１】最適化後
//※演算を共通化する
void testOpt06_Type1_After(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	//各要素を計算
	const float calc = mul1 * mul2 / div;
	const dataOpt06_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt06_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->result = elem_p->value * calc;
}

//----------------------------------------
//最適化⑦：SIMD演算を活用する
#include <memory.h>//memset用

//【タイプ１】最適化前

//----------
//行列加算
//※単純ループ版
template<std::size_t N, std::size_t M>
void addMatrix(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) + mat2(n, m);
}
//----------
//行列スカラー乗算
//※単純ループ版
template<std::size_t N, std::size_t M>
void mulMatrixScalar(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) * scalar;
}
//----------
//行列積算
//※単純ループ版
template<std::size_t N, std::size_t M, std::size_t NM>
void mulMatrix(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
{
	memset(mat0.value, 0, sizeof(mat0.value));
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			for (int nm = 0; nm < NM; ++nm)
				mat0(n, m) += (mat1(n, nm) * mat2(nm, m));
}
//----------
//テスト
template<std::size_t N, std::size_t M, std::size_t NM>
void testOpt07_Type1_Before(const int dummy, matrix<N, M>& add0, matrix<N, M>& mul0a, matrix<N, M>& mul0b, const matrix<N, M>& add1, const matrix<N, M>& add2, const matrix<N, M>& mul1a, const float mul2a, const matrix<N, NM>& mul1b, const matrix<NM, M>& mul2b)
{
	addMatrix(add0, add1, add2);
	mulMatrixScalar(mul0a, mul1a, mul2a);
	mulMatrix(mul0b, mul1b, mul2b);
}

//【タイプ１】最適化後

//----------
//行列加算
#if 1
//※単純ループ版
template<std::size_t N, std::size_t M>
void addMatrixOpt(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) + mat2(n, m);
}
#else
//※再帰テンプレート版
//　完全なインライン展開によるループ処理以上の最適化を期待するコードなので、展開されないと遅い
template<std::size_t N, std::size_t M, std::size_t NOW_N, std::size_t NOW_M>
struct _addMatrixOpt{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
	{
		mat0(NOW_N, NOW_M) = mat1(NOW_N, NOW_M) + mat2(NOW_N, NOW_M);
		_addMatrixOpt<N, M, NOW_N, NOW_M - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NOW_N>
struct _addMatrixOpt<N, M, NOW_N, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
	{
		mat0(NOW_N, 0) = mat1(NOW_N, 0) + mat2(NOW_N, 0);
		_addMatrixOpt<N, M, NOW_N - 1, M - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NOW_M>
struct _addMatrixOpt<N, M, 0, NOW_M>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
	{
		mat0(0, NOW_M) = mat1(0, NOW_M) + mat2(0, NOW_M);
		_addMatrixOpt<N, M, N - 1, NOW_M - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M>
struct _addMatrixOpt<N, M, 0, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
	{
		mat0(0, 0) = mat1(0, 0) + mat2(0, 0);
	}
};
template<std::size_t N, std::size_t M>
void addMatrixOpt(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
{
	_addMatrixOpt<N, M, N - 1, M - 1>::calc(mat0, mat1, mat2);
}
#endif
#if 1
//※4×4行列用特殊化
#include <smmintrin.h>//SSE4.1用
template<>
void addMatrixOpt<4, 4>(matrix<4, 4>& mat0, const matrix<4, 4>& mat1, const matrix<4, 4>& mat2)
{
	//mat1をロード
	//※16バイトアラインメントされていることを前提に、_mm_load_ps を使用（_mm_loadu_ps は使わない）
	const __m128 _mat1[4] = { _mm_load_ps(mat1.value[0]), _mm_load_ps(mat1.value[1]), _mm_load_ps(mat1.value[2]), _mm_load_ps(mat1.value[3]) };
	//mat2をロード
	const __m128 _mat2[4] = { _mm_load_ps(mat2.value[0]), _mm_load_ps(mat2.value[1]), _mm_load_ps(mat2.value[2]), _mm_load_ps(mat2.value[3]) };
	//行列を加算してmat0にストア
	_mm_store_ps(mat0.value[0], _mm_add_ps(_mat1[0], _mat2[0]));
	_mm_store_ps(mat0.value[1], _mm_add_ps(_mat1[1], _mat2[1]));
	_mm_store_ps(mat0.value[2], _mm_add_ps(_mat1[2], _mat2[2]));
	_mm_store_ps(mat0.value[3], _mm_add_ps(_mat1[3], _mat2[3]));
}
#endif

//----------
//行列スカラー乗算
#if 1
//※単純ループ版
template<std::size_t N, std::size_t M>
void mulMatrixScalarOpt(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) * scalar;
}
#else
//※再帰テンプレート版
//　完全なインライン展開によるループ処理以上の最適化を期待するコードなので、展開されないと遅い
template<std::size_t N, std::size_t M, std::size_t NOW_N, std::size_t NOW_M>
struct _mulMatrixScalarOpt{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
	{
		mat0(NOW_N, NOW_M) = mat1(NOW_N, NOW_M) * scalar;
		_mulMatrixScalarOpt<N, M, NOW_N, NOW_M - 1>::calc(mat0, mat1, scalar);
	}
};
template<std::size_t N, std::size_t M, std::size_t NOW_N>
struct _mulMatrixScalarOpt<N, M, NOW_N, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
	{
		mat0(NOW_N, 0) = mat1(NOW_N, 0) * scalar;
		_mulMatrixScalarOpt<N, M, NOW_N - 1, M - 1>::calc(mat0, mat1, scalar);
	}
};
template<std::size_t N, std::size_t M, std::size_t NOW_M>
struct _mulMatrixScalarOpt<N, M, 0, NOW_M>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
	{
		mat0(0, NOW_M) = mat1(0, NOW_M) * scalar;
		_mulMatrixScalarOpt<N, M, N - 1, NOW_M - 1>::calc(mat0, mat1, scalar);
	}
};
template<std::size_t N, std::size_t M>
struct _mulMatrixScalarOpt<N, M, 0, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
	{
		mat0(0, 0) = mat1(0, 0) * scalar;
	}
};
template<std::size_t N, std::size_t M>
void mulMatrixScalarOpt(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
{
	_mulMatrixScalarOpt<N, M, N - 1, M - 1>::calc(mat0, mat1, scalar);
}
#endif
#if 1
//※4×4行列用特殊化
#include <smmintrin.h>//SSE4.1用
template<>
void mulMatrixScalarOpt<4, 4>(matrix<4, 4>& mat0, const matrix<4, 4>& mat1, const float scalar)
{
	//mat1をロード
	//※16バイトアラインメントされていることを前提に、_mm_load_ps を使用（_mm_loadu_ps は使わない）
	const __m128 _mat1[4] = { _mm_load_ps(mat1.value[0]), _mm_load_ps(mat1.value[1]), _mm_load_ps(mat1.value[2]), _mm_load_ps(mat1.value[3]) };
	//mat2をロード
	const __m128 _mat2 = _mm_set1_ps(scalar);
	//行列を乗算してmat0にストア
	_mm_store_ps(mat0.value[0], _mm_mul_ps(_mat1[0], _mat2));
	_mm_store_ps(mat0.value[1], _mm_mul_ps(_mat1[1], _mat2));
	_mm_store_ps(mat0.value[2], _mm_mul_ps(_mat1[2], _mat2));
	_mm_store_ps(mat0.value[3], _mm_mul_ps(_mat1[3], _mat2));
}
#endif

//----------
//行列積算
#if 1
//※単純ループ版
template<std::size_t N, std::size_t M, std::size_t NM>
void mulMatrixOpt(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
{
	memset(mat0.value, 0, sizeof(mat0.value));
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			for (int nm = 0; nm < NM; ++nm)
				mat0(n, m) += (mat1(n, nm) * mat2(nm, m));
}
#else
//※再帰テンプレート版
//　完全なインライン展開によるループ処理以上の最適化を期待するコードなので、展開されないと遅い
template<std::size_t N, std::size_t M, std::size_t NM, std::size_t NOW_N, std::size_t NOW_M, std::size_t NOW_NM>
struct _mulMatrixOpt{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
	{
		mat0(NOW_N, NOW_M) += (mat1(NOW_N, NOW_NM) * mat2(NOW_NM, NOW_M));
		_mulMatrixOpt<N, M, NM, NOW_N, NOW_M, NOW_NM - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NM, std::size_t NOW_N, std::size_t NOW_M>
struct _mulMatrixOpt<N, M, NM, NOW_N, NOW_M, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
	{
		mat0(NOW_N, NOW_M) += (mat1(NOW_N, 0) * mat2(0, NOW_M));
		_mulMatrixOpt<N, M, NM, NOW_N, NOW_M - 1, NM - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NM, std::size_t NOW_N>
struct _mulMatrixOpt<N, M, NM, NOW_N, 0, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
	{
		mat0(NOW_N, 0) += (mat1(NOW_N, 0) * mat2(0, 0));
		_mulMatrixOpt<N, M, NM, NOW_N - 1, M - 1, NM - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NM>
struct _mulMatrixOpt<N, M, NM, 0, 0, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
	{
		mat0(0, 0) += (mat1(0, 0) * mat2(0, 0));
	}
};
template<std::size_t N, std::size_t M, std::size_t NM>
void mulMatrixOpt(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
{
	memset(mat0.value, 0, sizeof(mat0.value));
	_mulMatrixOpt<N, M, NM, N - 1, M - 1, NM - 1>::calc(mat0, mat1, mat2);
}
#endif
#if 1
//※4×4行列用特殊化
#include <smmintrin.h>//SSE4.1用
template<>
void mulMatrixOpt<4, 4, 4>(matrix<4, 4>& mat0, const matrix<4, 4>& mat1, const matrix<4, 4>& mat2)
{
	//mat1をロード
	//※16バイトアラインメントされていることを前提に、_mm_load_ps を使用（_mm_loadu_ps は使わない）
	const __m128 _mat1[4] = { _mm_load_ps(mat1.value[0]), _mm_load_ps(mat1.value[1]), _mm_load_ps(mat1.value[2]), _mm_load_ps(mat1.value[3]) };
#if 0
	//mat2をロードして転置（SIMD演算し易いように）※ベタな処理
	const float alignas(16) _mat2t_tmp[4][4] =
	{
		{ mat2.value[0][0], mat2.value[1][0], mat2.value[2][0], mat2.value[3][0] },
		{ mat2.value[0][1], mat2.value[1][1], mat2.value[2][1], mat2.value[3][1] },
		{ mat2.value[0][2], mat2.value[1][2], mat2.value[2][2], mat2.value[3][2] },
		{ mat2.value[0][3], mat2.value[1][3], mat2.value[2][3], mat2.value[3][3] },
	};
	const __m128 _mat2t[4] = { _mm_load_ps(_mat2t_tmp[0]), _mm_load_ps(_mat2t_tmp[1]), _mm_load_ps(_mat2t_tmp[2]), _mm_load_ps(_mat2t_tmp[3]) };
#else
	//mat2をロードして転置（SIMD演算し易いように）※シャッフル活用
	const __m128 _mat2t_tmp1[4] =
	{
		_mm_load_ps(mat2.value[0]),
		_mm_load_ps(mat2.value[1]),
		_mm_load_ps(mat2.value[2]),
		_mm_load_ps(mat2.value[3])
	};
	const __m128 _mat2t_tmp2[4] =
	{
		_mm_unpacklo_ps(_mat2t_tmp1[0], _mat2t_tmp1[1]),
		_mm_unpacklo_ps(_mat2t_tmp1[2], _mat2t_tmp1[3]),
		_mm_unpackhi_ps(_mat2t_tmp1[0], _mat2t_tmp1[1]),
		_mm_unpackhi_ps(_mat2t_tmp1[2], _mat2t_tmp1[3])
	};
	const __m128 _mat2t[4] =
	{
		_mm_shuffle_ps(_mat2t_tmp2[0], _mat2t_tmp2[1], 0x44),
		_mm_shuffle_ps(_mat2t_tmp2[0], _mat2t_tmp2[1], 0xee),
		_mm_shuffle_ps(_mat2t_tmp2[2], _mat2t_tmp2[3], 0x44),
		_mm_shuffle_ps(_mat2t_tmp2[2], _mat2t_tmp2[3], 0xee)
	};
#endif
#if 0
	//行列を積算してmat0にストア（SSE4.1の内積命令使用）※ベタな処理
	_mm_store_ss(&mat0.value[0][0], _mm_dp_ps(_mat1[0], _mat2t[0], 0xf1));
	_mm_store_ss(&mat0.value[0][1], _mm_dp_ps(_mat1[0], _mat2t[1], 0xf1));
	_mm_store_ss(&mat0.value[0][2], _mm_dp_ps(_mat1[0], _mat2t[2], 0xf1));
	_mm_store_ss(&mat0.value[0][3], _mm_dp_ps(_mat1[0], _mat2t[3], 0xf1));
	_mm_store_ss(&mat0.value[1][0], _mm_dp_ps(_mat1[1], _mat2t[0], 0xf1));
	_mm_store_ss(&mat0.value[1][1], _mm_dp_ps(_mat1[1], _mat2t[1], 0xf1));
	_mm_store_ss(&mat0.value[1][2], _mm_dp_ps(_mat1[1], _mat2t[2], 0xf1));
	_mm_store_ss(&mat0.value[1][3], _mm_dp_ps(_mat1[1], _mat2t[3], 0xf1));
	_mm_store_ss(&mat0.value[2][0], _mm_dp_ps(_mat1[2], _mat2t[0], 0xf1));
	_mm_store_ss(&mat0.value[2][1], _mm_dp_ps(_mat1[2], _mat2t[1], 0xf1));
	_mm_store_ss(&mat0.value[2][2], _mm_dp_ps(_mat1[2], _mat2t[2], 0xf1));
	_mm_store_ss(&mat0.value[2][3], _mm_dp_ps(_mat1[2], _mat2t[3], 0xf1));
	_mm_store_ss(&mat0.value[3][0], _mm_dp_ps(_mat1[3], _mat2t[0], 0xf1));
	_mm_store_ss(&mat0.value[3][1], _mm_dp_ps(_mat1[3], _mat2t[1], 0xf1));
	_mm_store_ss(&mat0.value[3][2], _mm_dp_ps(_mat1[3], _mat2t[2], 0xf1));
	_mm_store_ss(&mat0.value[3][3], _mm_dp_ps(_mat1[3], _mat2t[3], 0xf1));
#else
	//行列を積算してmat0にストア（SSE4.1の内積命令使用）※シャッフル活用
	_mm_store_ps(mat0.value[0], _mm_shuffle_ps(_mm_unpacklo_ps(_mm_dp_ps(_mat1[0], _mat2t[0], 0xf1),
	                                                           _mm_dp_ps(_mat1[0], _mat2t[1], 0xf1)),
	                                           _mm_unpacklo_ps(_mm_dp_ps(_mat1[0], _mat2t[2], 0xf1),
	                                                           _mm_dp_ps(_mat1[0], _mat2t[3], 0xf1)), 0x44));
	_mm_store_ps(mat0.value[1], _mm_shuffle_ps(_mm_unpacklo_ps(_mm_dp_ps(_mat1[1], _mat2t[0], 0xf1),
	                                                           _mm_dp_ps(_mat1[1], _mat2t[1], 0xf1)),
	                                           _mm_unpacklo_ps(_mm_dp_ps(_mat1[1], _mat2t[2], 0xf1),
	                                                           _mm_dp_ps(_mat1[1], _mat2t[3], 0xf1)), 0x44));
	_mm_store_ps(mat0.value[2], _mm_shuffle_ps(_mm_unpacklo_ps(_mm_dp_ps(_mat1[2], _mat2t[0], 0xf1),
	                                                           _mm_dp_ps(_mat1[2], _mat2t[1], 0xf1)),
	                                           _mm_unpacklo_ps(_mm_dp_ps(_mat1[2], _mat2t[2], 0xf1),
	                                                           _mm_dp_ps(_mat1[2], _mat2t[3], 0xf1)), 0x44));
	_mm_store_ps(mat0.value[3], _mm_shuffle_ps(_mm_unpacklo_ps(_mm_dp_ps(_mat1[3], _mat2t[0], 0xf1),
	                                                           _mm_dp_ps(_mat1[3], _mat2t[1], 0xf1)),
	                                           _mm_unpacklo_ps(_mm_dp_ps(_mat1[3], _mat2t[2], 0xf1),
	                                                           _mm_dp_ps(_mat1[3], _mat2t[3], 0xf1)), 0x44));
#endif
}
#endif

//----------
//テスト
template<std::size_t N, std::size_t M, std::size_t NM>
void testOpt07_Type1_After(const int dummy, matrix<N, M>& add0, matrix<N, M>& mul0a, matrix<N, M>& mul0b, const matrix<N, M>& add1, const matrix<N, M>& add2, const matrix<N, M>& mul1a, const float mul2a, const matrix<N, NM>& mul1b, const matrix<NM, M>& mul2b)
{
	addMatrixOpt(add0, add1, add2);
	mulMatrixScalarOpt(mul0a, mul1a, mul2a);
	mulMatrixOpt(mul0b, mul1b, mul2b);
}

//----------
//テスト関数をインスタンス化
template
void testOpt07_Type1_Before<4, 4, 4>(const int dummy, matrix4x4& add0, matrix4x4& mul0a, matrix4x4& mul0b, const matrix4x4& add1, const matrix4x4& add2, const matrix4x4& mul1a, const float mul2a, const matrix4x4& mul1b, const matrix4x4& mul2b);
template
void testOpt07_Type1_After<4, 4, 4>(const int dummy, matrix4x4& add0, matrix4x4& mul0a, matrix4x4& mul0b, const matrix4x4& add1, const matrix4x4& add2, const matrix4x4& mul1a, const float mul2a, const matrix4x4& mul1b, const matrix4x4& mul2b);
template
void testOpt07_Type1_Before<1, 4, 3>(const int dummy, matrix1x4& add0, matrix1x4& mul0a, matrix1x4& mul0b, const matrix1x4& add1, const matrix1x4& add2, const matrix1x4& mul1a, const float mul2a, const matrix1x3& mul1b, const matrix3x4& mul2b);
template
void testOpt07_Type1_After<1, 4, 3>(const int dummy, matrix1x4& add0, matrix1x4& mul0a, matrix1x4& mul0b, const matrix1x4& add1, const matrix1x4& add2, const matrix1x4& mul1a, const float mul2a, const matrix1x3& mul1b, const matrix3x4& mul2b);

//【タイプ２】最適化前
#pragma warning(disable: 4996)//strcpy, strncpy用
#include <string.h>
std::size_t testOpt07_Type2_Before(const int dummy, char* str0, const char* str1, const char* str2, const char* str3, const char c)
{
	const std::size_t result1 = strlen(str1);
	const int result2 = strcmp(str1, str2);
	const int result3 = strncmp(str1, str2, 18);
	const char* result4 = strchr(str1, c);
	const char* result5 = strrchr(str1, c);
	const char* result6 = strstr(str1, str3);
	const char* result7 = strcpy(str0, str1);
	const char* result8 = strncpy(str0, str1, 18);
	return result1;
}
//【タイプ２】最適化後
#include <nmmintrin.h>//SSE4.2用
#include <cstdint>//intptr_t用
#define SSESTR_BRANCH_FOR_ALIGN16//16バイトアラインメントで処理を振り分ける場合はこのマクロを有効にする
//SSE版strlen
std::size_t strlen_fast(const char* str)
{
#if 0
	return strlen(str);
#else
//nullチェックしない
//	if (!str)
//		return 0;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
#ifdef SSESTR_BRANCH_FOR_ALIGN16
	if ((reinterpret_cast<intptr_t>(str)& 0xf) == 0)
	{
		//16バイトアライメント時
		const __m128i* p = reinterpret_cast<const __m128i*>(str);
		while (!_mm_cmpistrz(null, *p, flags))
			++p;
		return (reinterpret_cast<const char*>(p) - str) + _mm_cmpistri(null, *p, flags);
	}
	else//if ((reinterpret_cast<intptr_t>(str) & 0xf) != 0)
#endif//SSESTR_BRANCH_FOR_ALIGN16
	{
		//非16バイトアライメント時
		const char* p = str;
		__m128i str16;
		while (true)
		{
			str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
			if (_mm_cmpistrz(null, str16, flags))
				break;
			p += 16;
		}
		return (p - str) + _mm_cmpistri(null, str16, flags);
	}
#endif
}
//SSE版strcmp
int strcmp_fast(const char* str1, const char* str2)
{
#if 1
	return strcmp(str1, str2);
#else
	//nullチェックしない
//	if (!str1) if (!str2) return 0;
//	           else       return -1;
//	else       if (!str2) return 1;
//	//         else       continue...
	static const int flags1 = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const int flags2 = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
#ifdef SSESTR_BRANCH_FOR_ALIGN16
	const int case_val = (((reinterpret_cast<intptr_t>(str1)& 0xf) == 0 ? 0 : 1) * 1) +
	                     (((reinterpret_cast<intptr_t>(str2)& 0xf) == 0 ? 0 : 1) * 2);
	switch (case_val)
	{
	case 0://16バイトアライメント＋16バイトアライメント時
		{
		   const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
		   const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
		   while (true)
		   {
			   if (_mm_cmpistrc(*p1, *p2, flags2) ||
				   _mm_cmpistrz(null, *p1, flags1))
				   break;
			   ++p1;
			   ++p2;
		   }
		   const std::size_t pos = _mm_cmpistri(*p1, *p2, flags2);
		   if (pos == 16)
			   return 0;
		   const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
		   const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
		   if (c1 < c2) return -1;
		   else if (c1 > c2) return 1;
		   return 0;
		}
		break;
	case 1://非16バイトアライメント＋16バイトアライメント時
		{
		   const char* p1 = str1;
		   const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
		   __m128i str16_1;
		   while (true)
		   {
			   str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
			   if (_mm_cmpistrc(str16_1, *p2, flags2) ||
				   _mm_cmpistrz(null, str16_1, flags1))
				   break;
			   p1 += 16;
			   ++p2;
		   }
		   const std::size_t pos = _mm_cmpistri(str16_1, *p2, flags2);
		   if (pos == 16)
			   return 0;
		   const char c1 = *(p1 + pos);
		   const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
		   if (c1 < c2) return -1;
		   else if (c1 > c2) return 1;
		   return 0;
		}
		break;
	case 2://16バイトアライメント＋非16バイトアライメント時
		{
		   const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
		   const char* p2 = str2;
		   __m128i str16_2;
		   while (true)
		   {
			   str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
			   if (_mm_cmpistrc(*p1, str16_2, flags2) ||
				   _mm_cmpistrz(null, *p1, flags1))
				   break;
			   ++p1;
			   p2 += 16;
		   }
		   const std::size_t pos = _mm_cmpistri(*p1, str16_2, flags2);
		   if (pos == 16)
			   return 0;
		   const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
		   const char c2 = *(p2 + pos);
		   if (c1 < c2) return -1;
		   else if (c1 > c2) return 1;
		   return 0;
		}
		break;
	default://case 3://16バイトアライメント＋非16バイトアライメント時
#endif//SSESTR_BRANCH_FOR_ALIGN16
		{
			const char* p1 = str1;
			const char* p2 = str2;
			__m128i str16_1;
			__m128i str16_2;
			while (true)
			{
				str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
				str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
				if (_mm_cmpistrc(str16_1, str16_2, flags2) ||
					_mm_cmpistrz(null, str16_1, flags1))
					break;
				p1 += 16;
				p2 += 16;
			}
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags2);
			if (pos == 16)
				return 0;
			const char c1 = *(p1 + pos);
			const char c2 = *(p2 + pos);
			if (c1 < c2) return -1;
			else if (c1 > c2) return 1;
			return 0;
		}
#ifdef SSESTR_BRANCH_FOR_ALIGN16
		break;
	}
#endif//SSESTR_BRANCH_FOR_ALIGN16
#endif
}
//SSE版strncmp
int strncmp_fast(const char* str1, const char* str2, const std::size_t max_len)
{
#if 1
	return strncmp(str1, str2, max_len);
#else
//nullチェックしない
//	if (!str1) if (!str2) return 0;
//	           else       return -1;
//	else       if (!str2) return 1;
//	//         else       continue...
	static const int flags1 = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const int flags2 = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
#ifdef SSESTR_BRANCH_FOR_ALIGN16
	const int case_val = (((reinterpret_cast<intptr_t>(str1)& 0xf) == 0 ? 0 : 1) * 1) +
	                     (((reinterpret_cast<intptr_t>(str2)& 0xf) == 0 ? 0 : 1) * 2);
	switch (case_val)
	{
	case 0://16バイトアライメント＋16バイトアライメント時
		{
			std::size_t remain = max_len;
			const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
			const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
			while (remain >= 16)
			{
				if (_mm_cmpistrc(*p1, *p2, flags2) ||
					_mm_cmpistrz(null, *p1, flags1))
					break;
				++p1;
				++p2;
				remain -= 16;
			}
			const std::size_t pos = _mm_cmpistri(*p1, *p2, flags2);
			if (pos == 16 || pos >= remain)
				return 0;
			const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
			if (c1 < c2) return -1;
			else if (c1 > c2) return 1;
			return 0;
		}
		break;
	case 1://非16バイトアライメント＋16バイトアライメント時
		{
			std::size_t remain = max_len;
			const char* p1 = str1;
			const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
			__m128i str16_1;
			while (true)
			{
				str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
				if (remain < 16)
					break;
				if (_mm_cmpistrc(str16_1, *p2, flags2) ||
					_mm_cmpistrz(null, str16_1, flags1))
					break;
				p1 += 16;
				++p2;
				remain -= 16;
			}
			const std::size_t pos = _mm_cmpistri(str16_1, *p2, flags2);
			if (pos == 16 || pos >= remain)
				return 0;
			const char c1 = *(p1 + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			if (c1 < c2) return -1;
			else if (c1 > c2) return 1;
			return 0;
		}
		break;
	case 2://16バイトアライメント＋非16バイトアライメント時
		{
			std::size_t remain = max_len;
			const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
			const char* p2 = str2;
			__m128i str16_2;
			while (true)
			{
				str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
				if (remain < 16)
					break;
				if (_mm_cmpistrc(*p1, str16_2, flags2) ||
					_mm_cmpistrz(null, *p1, flags1))
					break;
				++p1;
				p2 += 16;
				remain -= 16;
			}
			const std::size_t pos = _mm_cmpistri(*p1, str16_2, flags2);
			if (pos == 16 || pos >= remain)
				return 0;
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(p2 + pos);
			if (c1 < c2) return -1;
			else if (c1 > c2) return 1;
			return 0;
		}
		break;
	default://case 3://16バイトアライメント＋非16バイトアライメント時
#endif//SSESTR_BRANCH_FOR_ALIGN16
		{
			std::size_t remain = max_len;
			const char* p1 = str1;
			const char* p2 = str2;
			__m128i str16_1;
			__m128i str16_2;
			while (true)
			{
				str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
				str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
				if (remain < 16)
					break;
				if (_mm_cmpistrc(str16_1, str16_2, flags2) ||
					_mm_cmpistrz(null, str16_1, flags1))
					break;
				p1 += 16;
				p2 += 16;
				remain -= 16;
			}
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags2);
			if (pos == 16 || pos >= remain)
				return 0;
			const char c1 = *(p1 + pos);
			const char c2 = *(p2 + pos);
			if (c1 < c2) return -1;
			else if (c1 > c2) return 1;
			return 0;
		}
#ifdef SSESTR_BRANCH_FOR_ALIGN16
		break;
	}
#endif//SSESTR_BRANCH_FOR_ALIGN16
#endif
}
//SSE版strchr
const char* strchr_fast(const char* str, const char c)
{
#if 1
	return strchr(str, c);
#else
	//nullチェックしない
	//	if (!str)
	//		return 0;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i _c = _mm_set1_epi8(c);
	const __m128i null = _mm_setzero_si128();
#ifdef SSESTR_BRANCH_FOR_ALIGN16
	if ((reinterpret_cast<intptr_t>(str)& 0xf) == 0)
	{
		//16バイトアライメント時
		const __m128i* p = reinterpret_cast<const __m128i*>(str);
		int pos;
		while (true)
		{
			pos = _mm_cmpistri(_c, *p, flags);
			if (pos != 16)
				break;
			if (_mm_cmpistrz(null, *p, flags))
				break;
			++p;
		}
		if (pos != 16)
			return reinterpret_cast<const char*>(p) + pos;
		return nullptr;
	}
	else//if ((reinterpret_cast<intptr_t>(str) & 0xf) != 0)
#endif//SSESTR_BRANCH_FOR_ALIGN16
	{
		//非16バイトアライメント時
		const char* p = str;
		__m128i str16;
		int pos;
		while (true)
		{
			str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
			pos = _mm_cmpistri(_c, str16, flags);
			if (pos != 16)
				break;
			if (_mm_cmpistrz(null, str16, flags))
				break;
			p += 16;
		}
		if (pos != 16)
			return reinterpret_cast<const char*>(p) + pos;
		return nullptr;
	}
#endif
}
//SSE版strrchr
const char* strrchr_fast(const char* str, const char c)
{
#if 1
	return strrchr(str, c);
#else
	//nullチェックしない
	//	if (!str)
	//		return 0;
	static const int flags1 = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const int flags2 = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_MOST_SIGNIFICANT;
	const __m128i _c = _mm_set1_epi8(c);
	const __m128i null = _mm_setzero_si128();
#ifdef SSESTR_BRANCH_FOR_ALIGN16
	if ((reinterpret_cast<intptr_t>(str)& 0xf) == 0)
	{
		//16バイトアライメント時
		const __m128i* p = reinterpret_cast<const __m128i*>(str);
		const char* found_p = nullptr;
		while (true)
		{
			const int pos = _mm_cmpistri(_c, *p, flags2);
			if (pos != 16)
				found_p = reinterpret_cast<const char*>(p) + pos;
			if (_mm_cmpistrz(null, *p, flags1))
				break;
			++p;
		}
		if (found_p)
			return found_p;
		return nullptr;
	}
	else//if ((reinterpret_cast<intptr_t>(str) & 0xf) != 0)
#endif//SSESTR_BRANCH_FOR_ALIGN16
	{
		//非16バイトアライメント時
		const char* p = str;
		__m128i str16;
		const char* found_p = nullptr;
		while (true)
		{
			str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
			const int pos = _mm_cmpistri(_c, str16, flags2);
			if (pos != 16)
				found_p = p + pos;
			if (_mm_cmpistrz(null, str16, flags1))
				break;
			p += 16;
		}
		if (found_p)
			return found_p;
		return nullptr;
	}
#endif
}
//SSE版strstr
const char* strstr_fast(const char* str1, const char* str2)
{
#if 1
	return strstr(str1, str2);
#else
//nullチェックしない
//	if (!str1 || !str2)
//		return nullptr;
	const std::size_t str2_len = strlen_fast(str2);
	const char* p = str1;
	const char c = *str2;
	const char* found = nullptr;
	while(true)
	{
		found = strchr_fast(p, c);
		if (!found)
			break;
		if (strncmp_fast(found, str2, str2_len) == 0)
			break;;
		p = found + 1;
	}
	return found;
#endif
}
//SSE版strcpy用補助関数
inline void _memcpy_m128i(char* dst, const __m128i src, const std::size_t len)
{
#if 1
	memcpy(dst, reinterpret_cast<const char*>(&src), len);
#else//このやり方では遅かった
	static const __m128i ALL_ON = _mm_set1_epi8(0x80u);
	switch (len)
	{
	case  0: break;
	case  1: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON, 15), 15), dst); break;
	case  2: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON, 14), 14), dst); break;
	case  3: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON, 13), 13), dst); break;
	case  4: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON, 12), 12), dst); break;
	case  5: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON, 11), 11), dst); break;
	case  6: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON, 10), 10), dst); break;
	case  7: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  9),  9), dst); break;
	case  8: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  8),  8), dst); break;
	case  9: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  7),  7), dst); break;
	case 10: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  6),  6), dst); break;
	case 11: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  4),  5), dst); break;
	case 12: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  3),  4), dst); break;
	case 13: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  3),  3), dst); break;
	case 14: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  2),  2), dst); break;
	case 15: _mm_maskmoveu_si128(src, _mm_srli_si128(_mm_slli_si128(ALL_ON,  1),  1), dst); break;
	case 16: _mm_storeu_si128(reinterpret_cast<__m128i*>(dst), src); break;
	default: break;
	}
#endif
}
//SSE版strcpy
const char* strcpy_fast(char* dst, const char* src)
{
#if 1
	return strcpy(dst, src);
#else
//nullチェックしない
//	if (!dst || !src)
//		return nullptr;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
#ifdef SSESTR_BRANCH_FOR_ALIGN16
	const int case_val = (((reinterpret_cast<intptr_t>(dst)& 0xf) == 0 ? 0 : 1) * 1) +
		                 (((reinterpret_cast<intptr_t>(src)& 0xf) == 0 ? 0 : 1) * 2);
	switch (case_val)
	{
	case 0://16バイトアライメント＋16バイトアライメント時
		{
			__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
			const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
			while (true)
			{
				if (_mm_cmpistrz(null, *src_p, flags))
					break;
				*dst_p = *src_p;
				++dst_p;
				++src_p;
			}
			_memcpy_m128i(reinterpret_cast<char*>(dst_p), *src_p, _mm_cmpistri(null, *src_p, flags) + 1);
			return dst;
		}
		break;
	case 1://非16バイトアライメント＋16バイトアライメント時
		{
			char* dst_p = dst;
			const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
			while (true)
			{
				if (_mm_cmpistrz(null, *src_p, flags))
					break;
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), *src_p);
				dst_p += 16;
				++src_p;
			}
			_memcpy_m128i(dst_p, *src_p, _mm_cmpistri(null, *src_p, flags) + 1);
			return dst;
		}
		break;
	case 2://16バイトアライメント＋非16バイトアライメント時
		{
			__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
			const char* src_p = src;
			__m128i str16;
			while (true)
			{
				str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
				if (_mm_cmpistrz(null, str16, flags))
					break;
				*dst_p = str16;
				++dst_p;
				src_p += 16;
			}
			_memcpy_m128i(reinterpret_cast<char*>(dst_p), str16, _mm_cmpistri(null, str16, flags) + 1);
			return dst;
		}
		break;
	default://case 3://16バイトアライメント＋非16バイトアライメント時
#endif//SSESTR_BRANCH_FOR_ALIGN16
		{
			char* dst_p = dst;
			const char* src_p = src;
			__m128i str16;
			while (true)
			{
				str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
				if (_mm_cmpistrz(null, str16, flags))
					break;
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
				dst_p += 16;
				src_p += 16;
			}
			_memcpy_m128i(dst_p, str16, _mm_cmpistri(null, str16, flags) + 1);
			return dst;
		}
#ifdef SSESTR_BRANCH_FOR_ALIGN16
		break;
	}
#endif//SSESTR_BRANCH_FOR_ALIGN16
#endif
}
//SSE版strncpy用補助関数
inline void _memcpy_m128i(char* dst, const __m128i src, const std::size_t len, const std::size_t remain)
{
#if 1
	memcpy(dst, reinterpret_cast<const char*>(&src), len);
	memset(dst + len, '\0', remain - len);
#else//このやり方では遅かった
	switch (len)
	{
	case  0: break;
	case  1: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src, 15), 15), remain); break;
	case  2: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src, 14), 14), remain); break;
	case  3: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src, 13), 13), remain); break;
	case  4: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src, 12), 12), remain); break;
	case  5: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src, 11), 11), remain); break;
	case  6: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src, 10), 10), remain); break;
	case  7: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  9),  9), remain); break;
	case  8: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  8),  8), remain); break;
	case  9: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  7),  7), remain); break;
	case 10: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  6),  6), remain); break;
	case 11: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  5),  5), remain); break;
	case 12: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  4),  4), remain); break;
	case 13: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  3),  3), remain); break;
	case 14: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  2),  2), remain); break;
	case 15: _memcpy_m128i(dst, _mm_srli_si128(_mm_slli_si128(src,  1),  1), remain); break;
	case 16: _mm_storeu_si128(reinterpret_cast<__m128i*>(dst), src); break;
	default: break;
	}
#endif
}
//SSE版strncpy
const char* strncpy_fast(char* dst, const char* src, const std::size_t max_len)
{
#if 1
	return strncpy(dst, src, max_len);
#else
	//nullチェックしない
	//	if (!dst || !src)
	//		return nullptr;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
#ifdef SSESTR_BRANCH_FOR_ALIGN16
	const int case_val = (((reinterpret_cast<intptr_t>(dst)& 0xf) == 0 ? 0 : 1) * 1) +
	                     (((reinterpret_cast<intptr_t>(src)& 0xf) == 0 ? 0 : 1) * 2);
	switch (case_val)
	{
	case 0://16バイトアライメント＋16バイトアライメント時
		{
			std::size_t remain = max_len;
			__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
			const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
			while (remain >= 16)
			{
				if (_mm_cmpistrz(null, *src_p, flags))
					break;
				*dst_p = *src_p;
				++dst_p;
				++src_p;
				remain -= 16;
			}
			const std::size_t len = _mm_cmpistri(null, *src_p, flags) + 1;
			if (len >= remain)
				_memcpy_m128i(reinterpret_cast<char*>(dst_p), *src_p, remain);
			else
				_memcpy_m128i(reinterpret_cast<char*>(dst_p), *src_p, len, remain);
			return dst;
		}
		break;
	case 1://非16バイトアライメント＋16バイトアライメント時
		{
			std::size_t remain = max_len;
			char* dst_p = dst;
			const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
			while (remain >= 16)
			{
				if (_mm_cmpistrz(null, *src_p, flags))
					break;
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), *src_p);
				dst_p += 16;
				++src_p;
				remain -= 16;
			}
			const std::size_t len = _mm_cmpistri(null, *src_p, flags) + 1;
			if (len >= remain)
				_memcpy_m128i(dst_p, *src_p, remain);
			else
				_memcpy_m128i(dst_p, *src_p, len, remain);
			return dst;
		}
		break;
	case 2://16バイトアライメント＋非16バイトアライメント時
		{
			std::size_t remain = max_len;
			__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
			const char* src_p = src;
			__m128i str16;
			while (true)
			{
				str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
				if (remain < 16)
					break;
				if (_mm_cmpistrz(null, str16, flags))
					break;
				*dst_p = str16;
				++dst_p;
				src_p += 16;
				remain -= 16;
			}
			const std::size_t len = _mm_cmpistri(null, str16, flags) + 1;
			if (len >= remain)
				_memcpy_m128i(reinterpret_cast<char*>(dst_p), str16, remain);
			else
				_memcpy_m128i(reinterpret_cast<char*>(dst_p), str16, len, remain);
			return dst;
		}
		break;
	default://case 3://16バイトアライメント＋非16バイトアライメント時
#endif//SSESTR_BRANCH_FOR_ALIGN16
		{
			std::size_t remain = max_len;
			char* dst_p = dst;
			const char* src_p = src;
			__m128i str16;
			while (true)
			{
				str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
				if (remain < 16)
					break;
				if (_mm_cmpistrz(null, str16, flags))
					break;
				_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
				dst_p += 16;
				src_p += 16;
				remain -= 16;
			}
			const std::size_t len = _mm_cmpistri(null, str16, flags) + 1;
			if (len >= remain)
				_memcpy_m128i(dst_p, str16, remain);
			else
				_memcpy_m128i(dst_p, str16, len, remain);
			return dst;
		}
#ifdef SSESTR_BRANCH_FOR_ALIGN16
		break;
	}
#endif//SSESTR_BRANCH_FOR_ALIGN16
#endif
}
//テスト
std::size_t testOpt07_Type2_After(const int dummy, char* str0, const char* str1, const char* str2, const char* str3, const char c)
{
#if 0
{
#define LEN(s) printf("len(\"%s\")=%d(%d)\n", s, strlen_fast(s), strlen(s));
LEN("");
LEN("a");
LEN("ab");
LEN("abc");
LEN("abcd");
LEN("abcde");
LEN("a\0b");
LEN("\0a");
LEN("1234567890abcde");
LEN("1234567890abcdef");
LEN("1234567890abcdefg");
LEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
#undef LEN
}
#endif
#if 0
{
#define CMP(s1, s2) printf("cmp(\"%s\", \"%s\")=%d(%d)\n", s1, s2, strcmp_fast(s1, s2), strcmp(s1, s2));
CMP("a", "a");
CMP("a", "b");
CMP("b", "a");
CMP("aba", "aaa");
CMP("aaa", "aba");
CMP("abc", "acb");
CMP("acb", "abc");
CMP("1234567890abcdef", "1234567890abcdef");
CMP("1234567890abcdef", "1234567890abcdefg");
CMP("1234567890abcdefg", "1234567890abcdef");
CMP("1234567890abcde", "1234567890abcdef");
CMP("1234567890abcdef", "1234567890abcde");
CMP("\0a", "\0b");
#undef CMP
}
#endif
#if 0
{
#define NCMP(s1, s2, n) printf("ncmp(\"%s\", \"%s\", %d)=%d(%d)\n", s1, s2, n, strncmp_fast(s1, s2, n), strncmp(s1, s2, n));
NCMP("a", "a", 16);
NCMP("a", "b", 16);
NCMP("b", "a", 16);
NCMP("aba", "aaa", 16);
NCMP("aaa", "aba", 16);
NCMP("abc", "acb", 16);
NCMP("acb", "abc", 16);
NCMP("a", "a", 2);
NCMP("a", "b", 2);
NCMP("b", "a", 2);
NCMP("aba", "aaa", 2);
NCMP("aaa", "aba", 2);
NCMP("abc", "acb", 2);
NCMP("acb", "abc", 2);
NCMP("1234567890abcdef", "1234567890abcdef", 16);
NCMP("1234567890abcdef", "1234567890abcdefg", 16);
NCMP("1234567890abcdefg", "1234567890abcdef", 16);
NCMP("1234567890abcde", "1234567890abcdef", 16);
NCMP("1234567890abcdef", "1234567890abcde", 16);
NCMP("\0a", "\0b", 16);
NCMP("1234567890abcdef", "1234567890abcdef", 15);
NCMP("1234567890abcdef", "1234567890abcdefg", 15);
NCMP("1234567890abcdefg", "1234567890abcdef", 15);
NCMP("1234567890abcde", "1234567890abcdef", 15);
NCMP("1234567890abcdef", "1234567890abcde", 15);
NCMP("\0a", "\0b", 15);
NCMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef1", 33);
NCMP("1234567890abcdef1234567890abcdef12", "1234567890abcdef1234567890abcdef1", 33);
NCMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef12", 33);
NCMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef", 33);
NCMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcdef1", 33);
NCMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef2", 33);
NCMP("1234567890abcdef1234567890abcdef2", "1234567890abcdef1234567890abcdef1", 33);
NCMP("1034567890abcdef1234567890abcdef1", "0234567890abcdef1234567890abcdef1", 33);
NCMP("0234567890abcdef1234567890abcdef1", "1034567890abcdef1234567890abcdef1", 33);
NCMP("1234567890abcdef1034567890abcdef1", "1234567890abcdef0234567890abcdef1", 33);
NCMP("1234567890abcdef0234567890abcdef1", "1234567890abcdef1034567890abcdef1", 33);
#undef NCMP
}
#endif
#if 0
{
#define CHR(s, c) printf("chr(\"%s\", \'%c\')=\"%s\"(\"%s\")\n", s, c, strchr_fast(s, c), strchr(s, c));
CHR("1", '1');
CHR("12", '1');
CHR("123", '1');
CHR("1234", '1');
CHR("12341", '1');
CHR("123412", '1');
CHR("123132", '1');
CHR("123132", '2');
CHR("123132", '3');
CHR("123132", '4');
CHR("123x\0x123", 'x');
CHR("1234567890abcdef1234567890abcdef", '0');
#undef CHR
}
#endif
#if 0
{
#define CHRR(s, c) printf("rchr(\"%s\", \'%c\')=\"%s\"(\"%s\")\n", s, c, strrchr_fast(s, c), strrchr(s, c));
CHRR("1", '1');
CHRR("12", '1');
CHRR("123", '1');
CHRR("1234", '1');
CHRR("12341", '1');
CHRR("123412", '1');
CHRR("123132", '1');
CHRR("123132", '2');
CHRR("123132", '3');
CHRR("123132", '4');
CHRR("123x\0x123", 'x');
CHRR("1234567890abcdef1234567890abcdef", '0');
#undef CHRR
}
#endif
#if 0
{
#define STR(s1, s2) printf("str(\"%s\", \"%s\")=\"%s\"(\"%s\")\n", s1, s2, strstr_fast(s1, s2), strstr(s1, s2));
STR("1", "23");
STR("12", "23");
STR("123", "23");
STR("1234", "23");
STR("12341", "23");
STR("123412", "23");
STR("1234123", "23");
STR("12341234", "23");
STR("1234567890abcde!!234567890abcdef", "!!");
STR("!1234567890!abcdef!!1234567890!abcdef!", "!!");
#undef STR
}
#endif
#if 0
{
char alignas(16) buff1[32] = { 0 };
char dummy_for_align = 123;
char buff2[32] = { 0 };
#define CPY(d, s) printf("cpy(%p, \"%s\")=\"%s\"\n", d, s, strcpy_fast(d, s));
printf("(dummy_for_align=%d)\n", dummy_for_align);
CPY(buff1, "");
CPY(buff1, "a");
CPY(buff1, "ab");
CPY(buff1, "abc");
CPY(buff1, "abcd");
CPY(buff1, "abcde");
CPY(buff1, "a\0b");
CPY(buff1, "\0a");
CPY(buff1, "1234567890abcde");
CPY(buff1, "1234567890abcdef");
CPY(buff1, "1234567890abcdefg");
CPY(buff1, "1234567890abcdef1234567890abcde");
CPY(buff2, "1234567890abcde");
CPY(buff2, "1234567890abcdef");
CPY(buff2, "1234567890abcdefg");
CPY(buff2, "1234567890abcdef1234567890abcde");
#undef CPY
}
#endif
#if 0
{
char alignas(16) buff1[34] = { 0 };
char dummy_for_align = 123;
char buff2[34] = { 0 };
#define NCPY(d, s, n) printf("ncpy(%p, \"%s\", %d)=\"%s\"\n", d, s, n, strncpy_fast(d, s, n));
printf("(dummy_for_align=%d)\n", dummy_for_align);
NCPY(buff1, "", 16);
NCPY(buff1, "a", 16);
NCPY(buff1, "ab", 16);
NCPY(buff1, "abc", 16);
NCPY(buff1, "abcd", 16);
NCPY(buff1, "abcde", 16);
NCPY(buff1, "a\0b", 16);
NCPY(buff1, "\0a", 16);
NCPY(buff1, "", 2);
NCPY(buff1, "a", 2);
NCPY(buff1, "ab", 2);
NCPY(buff1, "abc", 2);
NCPY(buff1, "abcd", 2);
NCPY(buff1, "abcde", 2);
NCPY(buff1, "a\0b", 2);
NCPY(buff1, "\0a", 2);
NCPY(buff1, "1234567890abcde", 16);
NCPY(buff1, "1234567890abcdef", 16);
NCPY(buff1, "1234567890abcdefg", 16);
NCPY(buff1, "1234567890abcdef1234567890abcde", 16);
NCPY(buff2, "1234567890abcde", 16);
NCPY(buff2, "1234567890abcdef", 16);
NCPY(buff2, "1234567890abcdefg", 16);
NCPY(buff2, "1234567890abcdef1234567890abcde", 16);
NCPY(buff1, "1234567890abcdef1234567890abcdef", 33);
NCPY(buff1, "1234567890abcdef1234567890abcdef1", 33);
NCPY(buff1, "1234567890abcdef1234567890abcdef12", 33);
NCPY(buff1, "abc", 1);
NCPY(buff2, "1234567890abcdef1234567890abcdef", 33);
NCPY(buff2, "1234567890abcdef1234567890abcdef1", 33);
NCPY(buff2, "1234567890abcdef1234567890abcdef12", 33);
NCPY(buff2, "abc", 1);
#undef NCPY
}
#endif
	const std::size_t result1 = strlen_fast(str1);
	const int result2 = strcmp_fast(str1, str2);
	const int result3 = strncmp_fast(str1, str2, 18);
	const char* result4 = strchr_fast(str1, c);
	const char* result5 = strrchr_fast(str1, c);
	const char* result6 = strstr_fast(str1, str3);
	const char* result7 = strcpy_fast(str0, str1);
	const char* result8 = strncpy_fast(str0, str1, 18);
	return result1;
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
