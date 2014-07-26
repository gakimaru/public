#include "sub.h"
#include "sub2.h"

#include <random>//C++11 std::random用

//----------------------------------------
//最適化①：メモリアクセスの抑制：一時変数の活用

//初期化
void initOpt01(dataOpt01_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt01_t::elem_t::VALUE_RANGE - 1);
	data.sum = 0;
	for (auto& elem : data.elems)
	{
		elem.value = rnd_dist(rnd_engine);
	}
}

//【タイプ１】最適化前
//※単純な配列ループアクセス
void testOpt01_Type1_Before(dataOpt01_t& data)
{
	data.sum = 0;
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
//※「最適化後１」＋register指定子
void testOpt01_Type1_After2(dataOpt01_t& data)
{
	register int sum_tmp = 0;
	for (register std::size_t i = 0; i < extentof(data.elems); ++i)
		sum_tmp += data.elems[i].value;
	data.sum = sum_tmp;
}

//【タイプ１】最適化後３
//※ポインタ計算に置き換えてループカウンタを無くす
void testOpt01_Type1_After3(dataOpt01_t& data)
{
	int sum_tmp = 0;
	const dataOpt01_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum_tmp += elem_p->value;
	data.sum = sum_tmp;
}

//【タイプ１】最適化後４
//※「最適化後３」＋register指定子
void testOpt01_Type1_After4(dataOpt01_t& data)
{
	register int sum_tmp = 0;
	register const dataOpt01_t::elem_t* end = data.elems + extentof(data.elems);
	for (register dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum_tmp += elem_p->value;
	data.sum = sum_tmp;
}

//【タイプ１】【参考】C++11でもっとも簡潔な記述（遅い）
//※C++11 範囲に基づくforループ
void testOpt01_Type1_Appendix(dataOpt01_t& data)
{
	data.sum = 0;
	for (auto elem : data.elems)
		data.sum += elem.value;
}

//----------------------------------------
//最適化②：メモリアクセスの抑制：アドレス計算の削減

//初期化
void initOpt02(dataOpt02_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt02_t::elem_t::VALUE_RANGE - 1);
	for (auto& elem : data.elems)
	{
		elem.value = rnd_dist(rnd_engine);
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
	{
		int value = 0;
		const dist_t* dist_end = dist + dataOpt02_t::elem_t::VALUE_RANGE;
		for (dist_t* dist_p = dist; dist_p < dist_end; ++dist_p)
		{
			dist_p->value = value++;
			dist_p->count = 0;
		}
	}
	//分布集計
	{
		const dataOpt02_t::elem_t* elem_end = data.elems + extentof(data.elems);
		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < elem_end; ++elem_p)
			++dist[elem_p->value].count;
	}
	//最大分布取得
	const dist_t* top_dist_p = dist;
	{
		const dist_t* dist_end = dist + dataOpt02_t::elem_t::VALUE_RANGE;
		for (const dist_t* dist_p = top_dist_p + 1; dist_p < dist_end; ++dist_p)
		{
			if (top_dist_p->count < dist_p->count)
				top_dist_p = dist_p;
		}
	}
	return (top_dist_p->count << 16) | top_dist_p->value;
}

//【タイプ１】最適化後３
//※徹底的にポインタ計算に変更
int testOpt02_Type1_After3(dataOpt02_t& data)
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
		dist_t* dist_p = &dist[value];
		dist_p->value = value;
		dist_p->count = 0;
	}
	//分布集計
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		const dataOpt02_t::elem_t* elem_p = &data.elems[i];
		++dist[elem_p->value].count;
	}
	//最大分布取得
	const dist_t* top_dist_p = &dist[0];
	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
	{
		dist_t* dist_p = &dist[i];
		if (top_dist_p->count < dist_p->count)
			top_dist_p = dist_p;
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

//【タイプ３】コールバック関数
//配列内の値を検索して別の値に置き換えるコールバック関数と静的変数
static int s_exchange_value = 0;
 static void _exchangeDataCB(int& value)
{
	value = s_exchange_value;
}
//配列内の値を検索して出現数を算出するコールバック関数と静的変数
static int s_count_value = 0;
inline static void _countDataCB(int& value)
{
	++s_count_value;
}

//【タイプ３】最適化前
//※最適化前の共通関数とコールバック関数を使用
//配列内の値を検索して別の値に置き換える
inline static void _exchangeData_Before(dataOpt03_t& data, const int find, const int exchange)
{
	s_exchange_value = exchange;
	commonProc_testOpt03_Type3_Before(data.values, extentof(data.values), find, _exchangeDataCB);
}
//配列内の値を検索して出現数を算出する
inline static int _countData_Before(dataOpt03_t& data, const int find)
{
	s_count_value = 0;
	commonProc_testOpt03_Type3_Before(data.values, extentof(data.values), find, _countDataCB);
	return s_count_value;
}
//関数本体
int testOpt03_Type3_Before(dataOpt03_t& data)
{
	//値の置き換え：0→1
	_exchangeData_Before(data, 0, 1);
	//値の置き換え：4→3
	_exchangeData_Before(data, 4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData_Before(data, 1) + _countData_Before(data, 2) + _countData_Before(data, 3);
}

//【タイプ３】最適化後1
//※共通テンプレート関数とコールバック関数を使用
//配列内の値を検索して別の値に置き換える
inline static void _exchangeData_After1(dataOpt03_t& data, const int find, const int exchange)
{
	s_exchange_value = exchange;
	commonProc_testOpt03_Type3_After(data.values, find, _exchangeDataCB);
}
//配列内の値を検索して出現数を算出する
inline static int _countData_After1(dataOpt03_t& data, const int find)
{
	s_count_value = 0;
	commonProc_testOpt03_Type3_After(data.values, find, _countDataCB);
	return s_count_value;
}
//関数本体
int testOpt03_Type3_After1(dataOpt03_t& data)
{
	//値の置き換え：0→1
	_exchangeData_After1(data, 0, 1);
	//値の置き換え：4→3
	_exchangeData_After1(data, 4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData_After1(data, 1) + _countData_After1(data, 2) + _countData_After1(data, 3);
}

//【タイプ３】最適化後2
//※共通テンプレート関数と関数オブジェクトを使用
int testOpt03_Type3_After2(dataOpt03_t& data)
{
	//配列内の値を検索して別の値に置き換える関数オブジェクト
	struct functor_exchangeData {
		dataOpt03_t& m_data;
		inline void operator()(const int find, const int exchange)
		{
			//コールバック用の関数オブジェクト
			struct functor{
				const int m_exchange;
				inline void operator()(int& value)
				{
					value = m_exchange;
				}
				inline functor(const int exchange) :
					m_exchange(exchange)
				{}
			};
			commonProc_testOpt03_Type3_After(m_data.values, find, functor(exchange));
		}
		inline functor_exchangeData(dataOpt03_t& data) :
			m_data(data)
		{}
	};
	functor_exchangeData _exchangeData(data);//関数オブジェクトを実体化
	
	//配列内の値を検索して出現数を算出する関数オブジェクト
	//※変数dataをキャプチャしたクロ―ジャとして振る舞う
	struct functor_countData {
		dataOpt03_t& m_data;
		inline auto operator()(const int find) -> int
		{
			int count = 0;
			//コールバック用の関数オブジェクト
			struct functor{
				int& m_count;
				inline void operator()(int& value)
				{
					++m_count;
				}
				inline functor(int& count) :
					m_count(count)
				{}
			};
			commonProc_testOpt03_Type3_After(m_data.values, find, functor(count));
			return count;
		}
		inline functor_countData(dataOpt03_t& data) :
			m_data(data)
		{}
	};
	functor_countData _countData(data);//関数オブジェクトを実体化

	//値の置き換え：0→1
	_exchangeData(0, 1);
	//値の置き換え：4→3
	_exchangeData(4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData(1) + _countData(2) + _countData(3);
}

//【タイプ３】最適化後3
//※共通テンプレート関数とラムダ式を使用
int testOpt03_Type3_After3(dataOpt03_t& data)
{
	//配列内の値を検索して別の値に置き換えるラムダ式
	//※変数data/exchangeをキャプチャしたクロ―ジャとして振る舞う
	auto _exchangeData = [&data](const int find, const int exchange)
	{
		commonProc_testOpt03_Type3_After(data.values, find,
			[exchange](int& value)
			{
				value = exchange;
			}
		);
	};
	
	//配列内の値を検索して出現数を算出するラムダ式
	//※変数data/countをキャプチャしたクロ―ジャとして振る舞う
	auto _countData = [&data](const int find) -> int
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

	//値の置き換え：0→1
	_exchangeData(0, 1);
	//値の置き換え：4→3
	_exchangeData(4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData(1) + _countData(2) + _countData(3);
}

//【タイプ３】【参考】A-1
//※std::function型を受け取る共通テンプレート関数とコールバック関数を使用
//配列内の値を検索して別の値に置き換える
inline static void _exchangeData_AppendixA1(dataOpt03_t& data, const int find, const int exchange)
{
	s_exchange_value = exchange;
	commonProc_testOpt03_Type3_AppendixA(data.values, find, _exchangeDataCB);
}
//配列内の値を検索して出現数を算出する
inline static int _countData_AppendixA1(dataOpt03_t& data, const int find)
{
	s_count_value = 0;
	commonProc_testOpt03_Type3_AppendixA(data.values, find, _countDataCB);
	return s_count_value;
}
//関数本体
int testOpt03_Type3_AppendixA1(dataOpt03_t& data)
{
	//値の置き換え：0→1
	_exchangeData_AppendixA1(data, 0, 1);
	//値の置き換え：4→3
	_exchangeData_AppendixA1(data, 4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData_AppendixA1(data, 1) + _countData_AppendixA1(data, 2) + _countData_AppendixA1(data, 3);
}

//【タイプ３】【参考】A-2
//※std::function型を受け取る共通テンプレート関数と関数オブジェクトを使用
int testOpt03_Type3_AppendixA2(dataOpt03_t& data)
{
	//配列内の値を検索して別の値に置き換える関数オブジェクト
	struct functor_exchangeData {
		dataOpt03_t& m_data;
		inline void operator()(const int find, const int exchange)
		{
			//コールバック用の関数オブジェクト
			struct functor{
				const int m_exchange;
				inline void operator()(int& value)
				{
					value = m_exchange;
				}
				inline functor(const int exchange) :
					m_exchange(exchange)
				{}
			};
			commonProc_testOpt03_Type3_AppendixA(m_data.values, find, functor(exchange));
		}
		inline functor_exchangeData(dataOpt03_t& data) :
			m_data(data)
		{}
	};
	functor_exchangeData _exchangeData(data);//関数オブジェクトを実体化
	
	//配列内の値を検索して出現数を算出する関数オブジェクト
	//※変数dataをキャプチャしたクロ―ジャとして振る舞う
	struct functor_countData {
		dataOpt03_t& m_data;
		inline auto operator()(const int find) -> int
		{
			int count = 0;
			//コールバック用の関数オブジェクト
			struct functor{
				int& m_count;
				inline void operator()(int& value)
				{
					++m_count;
				}
				inline functor(int& count) :
					m_count(count)
				{}
			};
			commonProc_testOpt03_Type3_AppendixA(m_data.values, find, functor(count));
			return count;
		}
		inline functor_countData(dataOpt03_t& data) :
			m_data(data)
		{}
	};
	functor_countData _countData(data);//関数オブジェクトを実体化

	//値の置き換え：0→1
	_exchangeData(0, 1);
	//値の置き換え：4→3
	_exchangeData(4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData(1) + _countData(2) + _countData(3);
}

//【タイプ３】【参考】A-3
//※std::function型を受け取る共通テンプレート関数とラムダ式を使用
int testOpt03_Type3_AppendixA3(dataOpt03_t& data)
{
	//配列内の値を検索して別の値に置き換えるラムダ式
	//※変数data/exchangeをキャプチャしたクロ―ジャとして振る舞う
	auto _exchangeData = [&data](const int find, const int exchange)
	{
		commonProc_testOpt03_Type3_AppendixA(data.values, find,
			[exchange](int& value)
			{
				value = exchange;
			}
		);
	};
	
	//配列内の値を検索して出現数を算出するラムダ式
	//※変数data/countをキャプチャしたクロ―ジャとして振る舞う
	auto _countData = [&data](const int find) -> int
	{
		int count = 0;
		commonProc_testOpt03_Type3_AppendixA(data.values, find,
			[&count](int& value)
			{
				++count;
			}
		);
		return count;
	};

	//値の置き換え：0→1
	_exchangeData(0, 1);
	//値の置き換え：4→3
	_exchangeData(4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData(1) + _countData(2) + _countData(3);
}

//【タイプ３】【参考】B-1
//※std::function型を受け取る共通関数とコールバック関数を使用
//配列内の値を検索して別の値に置き換える
inline static void _exchangeData_AppendixB1(dataOpt03_t& data, const int find, const int exchange)
{
	s_exchange_value = exchange;
	commonProc_testOpt03_Type3_AppendixB(data.values, extentof(data.values), find, _exchangeDataCB);
}
//配列内の値を検索して出現数を算出する
inline static int _countData_AppendixB1(dataOpt03_t& data, const int find)
{
	s_count_value = 0;
	commonProc_testOpt03_Type3_AppendixB(data.values, extentof(data.values), find, _countDataCB);
	return s_count_value;
}
//関数本体
int testOpt03_Type3_AppendixB1(dataOpt03_t& data)
{
	//値の置き換え：0→1
	_exchangeData_AppendixB1(data, 0, 1);
	//値の置き換え：4→3
	_exchangeData_AppendixB1(data, 4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData_AppendixB1(data, 1) + _countData_AppendixB1(data, 2) + _countData_AppendixB1(data, 3);
}

//【タイプ３】【参考】B-2
//※std::function型を受け取る共通関数と関数オブジェクトを使用
int testOpt03_Type3_AppendixB2(dataOpt03_t& data)
{
	//配列内の値を検索して別の値に置き換える関数オブジェクト
	struct functor_exchangeData {
		dataOpt03_t& m_data;
		inline void operator()(const int find, const int exchange)
		{
			//コールバック用の関数オブジェクト
			struct functor{
				const int m_exchange;
				inline void operator()(int& value)
				{
					value = m_exchange;
				}
				inline functor(const int exchange) :
					m_exchange(exchange)
				{}
			};
			commonProc_testOpt03_Type3_AppendixB(m_data.values, extentof(m_data.values), find, functor(exchange));
		}
		inline functor_exchangeData(dataOpt03_t& data) :
			m_data(data)
		{}
	};
	functor_exchangeData _exchangeData(data);//関数オブジェクトを実体化

	//配列内の値を検索して出現数を算出する関数オブジェクト
	//※変数dataをキャプチャしたクロ―ジャとして振る舞う
	struct functor_countData {
		dataOpt03_t& m_data;
		inline auto operator()(const int find) -> int
		{
			int count = 0;
			//コールバック用の関数オブジェクト
			struct functor{
				int& m_count;
				inline void operator()(int& value)
				{
					++m_count;
				}
				inline functor(int& count) :
					m_count(count)
				{}
			};
			commonProc_testOpt03_Type3_AppendixB(m_data.values, extentof(m_data.values), find, functor(count));
			return count;
		}
		inline functor_countData(dataOpt03_t& data) :
			m_data(data)
		{}
	};
	functor_countData _countData(data);//関数オブジェクトを実体化

	//値の置き換え：0→1
	_exchangeData(0, 1);
	//値の置き換え：4→3
	_exchangeData(4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData(1) + _countData(2) + _countData(3);
}

//【タイプ３】【参考】B-3
//※std::function型を受け取る共通関数とラムダ式を使用
int testOpt03_Type3_AppendixB3(dataOpt03_t& data)
{
	//配列内の値を検索して別の値に置き換えるラムダ式
	//※変数data/exchangeをキャプチャしたクロ―ジャとして振る舞う
	auto _exchangeData = [&data](const int find, const int exchange)
	{
		commonProc_testOpt03_Type3_AppendixB(data.values, extentof(data.values), find,
			[exchange](int& value)
			{
				value = exchange;
			}
		);
	};

	//配列内の値を検索して出現数を算出するラムダ式
	//※変数data/countをキャプチャしたクロ―ジャとして振る舞う
	auto _countData = [&data](const int find) -> int
	{
		int count = 0;
		commonProc_testOpt03_Type3_AppendixB(data.values, extentof(data.values), find,
			[&count](int& value)
			{
				++count;
			}
		);
		return count;
	};

	//値の置き換え：0→1
	_exchangeData(0, 1);
	//値の置き換え：4→3
	_exchangeData(4, 3);
	//値1,2,3の出現数を計上して返す
	return _countData(1) + _countData(2) + _countData(3);
}

//----------------------------------------
//最適化④：除算の抑制：乗算に変更

//初期化
void initOpt04(dataOpt04_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt04_t::elem_t::VALUE_RANGE - 1);
	for (auto& elem : data.elems)
	{
		elem.value = rnd_dist(rnd_engine);
		elem.ratio = 0.f;
	}
}

#if 0//インライン関数化
//【タイプ１】最適化前
//※定数による除算
float testOpt04_Type1_Before(const float value)
{
	//...
}

//【タイプ１】最適化後
//※定数による除算を乗算に変更
float testOpt04_Type1_After(const float value)
{
	//...
}
#endif

//【タイプ２】最適化前
//※素直な浮動小数点データ演算、および、除算
void testOpt04_Type2_Before(dataOpt04_t& data)
{
	//合計値算出
	float sum = 0.f;
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		dataOpt04_t::elem_t* elem_p = &data.elems[i];
		sum += static_cast<float>(elem_p->value);
	}
	//各要素の分布比率を算出
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		dataOpt04_t::elem_t* elem_p = &data.elems[i];
		elem_p->ratio = static_cast<float>(elem_p->value) / sum;
	}
}

//【タイプ２】最適化後１
//※除算を乗算に変更
void testOpt04_Type2_After1(dataOpt04_t& data)
{
	//合計値算出
	float sum = 0.f;
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		dataOpt04_t::elem_t* elem_p = &data.elems[i];
		sum += static_cast<float>(elem_p->value);
	}
	//各要素の分布比率を算出
	const float mul = 1.f / sum;
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		dataOpt04_t::elem_t* elem_p = &data.elems[i];
		elem_p->ratio = static_cast<float>(elem_p->value) * mul;
	}
}

//【タイプ２】最適化後２
//※浮動小数点演算の数を減らす（整数演算のままでよいところは整数演算にする）
void testOpt04_Type2_After2(dataOpt04_t& data)
{
	//合計値算出
	int sum = 0;
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		dataOpt04_t::elem_t* elem_p = &data.elems[i];
		sum += elem_p->value;
	}
	//各要素の分布比率を算出
	const float mul = 1.f / static_cast<float>(sum);
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		dataOpt04_t::elem_t* elem_p = &data.elems[i];
		elem_p->ratio = static_cast<float>(elem_p->value) * mul;
	}
}

#if 0//インライン関数化
//【タイプ３】最適化前
//※変数による除算
float testOpt04_Type3_Before(const float value, const float div)
{
	//...
}

//【タイプ３】最適化後1
//※変数による除算を乗算に変更
float testOpt04_Type3_After1(const float value, const float div)
{
	//...
}

//【タイプ３】最適化後2
//※変数による除算を乗算に変更
//※ニュートン法で逆数の精度を高める
float testOpt04_Type3_After2(const float value, const float div)
{
	//...
}

//【タイプ３】最適化後3
//※変数による除算を乗算に変更
//※ニュートン法を2回繰り返し、より逆数の精度を高める
float testOpt04_Type3_After3(const float value, const float div)
{
	//...
}
#endif

#if 0//インライン関数化
//【タイプ４】最適化前
//※平方根
float testOpt04_Type4_Before(const float value)
{
	//...
}

//【タイプ４】最適化後1
//※平方根の逆数を使用した平方根
float testOpt04_Type4_After1(const float value)
{
	//...
}

//【タイプ４】最適化後2
//※平方根の逆数を使用した平方根
//※ニュートン法で逆数の精度を高める
float testOpt04_Type4_After2(const float value)
{
	//...
}

//【タイプ４】最適化後3
//※平方根の逆数を使用した平方根
//※ニュートン法を2回繰り返し、より逆数の精度を高める
float testOpt04_Type4_After3(const float value)
{
	//...
}
#endif

//----------------------------------------
//最適化⑤：乗算／除算の抑制：シフト演算や加減算に変更

//【タイプ１】最適化前
template<int N>
inline int intMul(const int val){ return val * N; }
template<int N>
inline int intDiv(const int val){ return val / N; }
template<int N>
inline int intMod(const int val){ return val % N; }
int testOpt05_Type1_Before(int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						   int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						   int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
{
	m2  = intMul< 2>(m2 );//val *  2
	m3  = intMul< 3>(m3 );//val *  3
	m4  = intMul< 4>(m4 );//val *  4
	m5  = intMul< 5>(m5 );//val *  5
	m10 = intMul<10>(m10);//val * 10
	m16 = intMul<16>(m16);//val * 16
	m24 = intMul<24>(m24);//val * 24
	d2  = intDiv< 2>(d2 );//val /  2
	d3  = intDiv< 3>(d3 );//val /  3
	d4  = intDiv< 4>(d4 );//val /  4
	d5  = intDiv< 5>(d5 );//val /  5
	d10 = intDiv<10>(d10);//val / 10
	d16 = intDiv<16>(d16);//val / 16
	d24 = intDiv<24>(d24);//val / 24
	r2  = intMod< 2>(r2 );//val %  2
	r3  = intMod< 3>(r3 );//val %  3
	r4  = intMod< 4>(r4 );//val %  4
	r5  = intMod< 5>(r5 );//val %  5
	r10 = intMod<10>(r10);//val % 10
	r16 = intMod<16>(r16);//val % 16
	r24 = intMod<24>(r24);//val % 24
	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
	       d2 + d3 + d4 + d5 + d10 + d16 + d24 + 
	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
}
//【タイプ１】最適化後
#include <iostream>
#include <exception>
//※乗算のレイテンシを5と仮定し、シフト演算を1、加算を1として、計5未満ならシフト演算と加算に展開した特殊化を適用する
template<int N> inline int intMulOpt(const int val){ return val * N; }
template<>      inline int intMulOpt<   0>(const int val){ return 0; }
template<>      inline int intMulOpt<   1>(const int val){ return val; }
template<>      inline int intMulOpt<   2>(const int val){ return val << 1; }
template<>      inline int intMulOpt<   3>(const int val){ return (val << 1) + val; }
template<>      inline int intMulOpt<   4>(const int val){ return val << 2; }
template<>      inline int intMulOpt<   5>(const int val){ return (val << 2) + val; }
template<>      inline int intMulOpt<   6>(const int val){ return (val << 2) + (val << 1); }
template<>      inline int intMulOpt<   7>(const int val){ return (val << 2) + (val << 1) + val; }
template<>      inline int intMulOpt<   8>(const int val){ return val << 3; }
template<>      inline int intMulOpt<   9>(const int val){ return (val << 3) + val; }
template<>      inline int intMulOpt<  10>(const int val){ return (val << 3) + (val << 1); }
template<>      inline int intMulOpt<  11>(const int val){ return (val << 3) + (val << 1) + val; }
template<>      inline int intMulOpt<  12>(const int val){ return (val << 3) + (val << 2); }
template<>      inline int intMulOpt<  13>(const int val){ return (val << 3) + (val << 2) + val; }
template<>      inline int intMulOpt<  16>(const int val){ return val << 4; }
template<>      inline int intMulOpt<  20>(const int val){ return (val << 4) + (val << 2); }
template<>      inline int intMulOpt<  24>(const int val){ return (val << 4) + (val << 3); }
template<>      inline int intMulOpt<  32>(const int val){ return val << 5; }
template<>      inline int intMulOpt<  64>(const int val){ return val << 6; }
template<>      inline int intMulOpt< 128>(const int val){ return val << 7; }
template<>      inline int intMulOpt< 256>(const int val){ return val << 8; }
template<>      inline int intMulOpt< 512>(const int val){ return val << 9; }
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
template<>      inline int intDivOpt<   0>(const int val){ throw std::overflow_error("Integer division by zero");	return 0; }
template<>      inline int intDivOpt<   1>(const int val){ return val; }
template<>      inline int intDivOpt<   2>(const int val){ return val >>  1; }
template<>      inline int intDivOpt<   4>(const int val){ return val >>  2; }
template<>      inline int intDivOpt<   8>(const int val){ return val >>  3; }
template<>      inline int intDivOpt<  16>(const int val){ return val >>  4; }
template<>      inline int intDivOpt<  32>(const int val){ return val >>  5; }
template<>      inline int intDivOpt<  64>(const int val){ return val >>  6; }
template<>      inline int intDivOpt< 128>(const int val){ return val >>  7; }
template<>      inline int intDivOpt< 256>(const int val){ return val >>  8; }
template<>      inline int intDivOpt< 512>(const int val){ return val >>  9; }
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
template<>      inline int intModOpt<   0>(const int val){ throw std::overflow_error("Integer division by zero");	return 0; }
template<>      inline int intModOpt<   1>(const int val){ return 0; }
template<>      inline int intModOpt<   2>(const int val){ return val & (   2 - 1); }
template<>      inline int intModOpt<   4>(const int val){ return val & (   4 - 1); }
template<>      inline int intModOpt<   8>(const int val){ return val & (   8 - 1); }
template<>      inline int intModOpt<  16>(const int val){ return val & (  16 - 1); }
template<>      inline int intModOpt<  32>(const int val){ return val & (  32 - 1); }
template<>      inline int intModOpt<  64>(const int val){ return val & (  64 - 1); }
template<>      inline int intModOpt< 128>(const int val){ return val & ( 128 - 1); }
template<>      inline int intModOpt< 256>(const int val){ return val & ( 256 - 1); }
template<>      inline int intModOpt< 512>(const int val){ return val & ( 512 - 1); }
template<>      inline int intModOpt<1024>(const int val){ return val & (1024 - 1); }
int testOpt05_Type1_After(int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						  int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						  int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
{
	m2  = intMulOpt< 2>(m2 );//val *  2
	m3  = intMulOpt< 3>(m3 );//val *  3
	m4  = intMulOpt< 4>(m4 );//val *  4
	m5  = intMulOpt< 5>(m5 );//val *  5
	m10 = intMulOpt<10>(m10);//val * 10
	m16 = intMulOpt<16>(m16);//val * 16
	m24 = intMulOpt<24>(m24);//val * 24
	d2  = intDivOpt< 2>(d2 );//val /  2
	d3  = intDivOpt< 3>(d3 );//val /  3
	d4  = intDivOpt< 4>(d4 );//val /  4
	d5  = intDivOpt< 5>(d5 );//val /  5
	d10 = intDivOpt<10>(d10);//val / 10
	d16 = intDivOpt<16>(d16);//val / 16
	d24 = intDivOpt<24>(d24);//val / 24
	r2  = intModOpt< 2>(r2 );//val %  2
	r3  = intModOpt< 3>(r3 );//val %  3
	r4  = intModOpt< 4>(r4 );//val %  4
	r5  = intModOpt< 5>(r5 );//val %  5
	r10 = intModOpt<10>(r10);//val % 10
	r16 = intModOpt<16>(r16);//val % 16
	r24 = intModOpt<24>(r24);//val % 24
	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
	       d2 + d3 + d4 + d5 + d10 + d16 + d24 +
	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
}

//----------------------------------------
//最適化⑥：乗算／除算の抑制：計算結果の共通利用

//初期化
void initOpt06(dataOpt06_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_real_distribution<float> rnd_dist(0.f, static_cast<float>(dataOpt06_t::elem_t::VALUE_RANGE));
	for (auto& elem : data.elems)
	{
		elem.value_a = rnd_dist(rnd_engine);
		elem.value_b = rnd_dist(rnd_engine);
		elem.value_b = 0.f;
	}
}

//【タイプ１】最適化前
//※毎ループ複雑な演算を行う
float testOpt06_Type1_Before(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	//各要素を計算
	float sum = 0.f;
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		dataOpt06_t::elem_t* elem_p = &data.elems[i];
		elem_p->value_c = (elem_p->value_a * mul1 * mul2 / div) * 2.f + 
		                  (elem_p->value_b * mul1 * mul2 / div) * 3.f;
		sum += elem_p->value_c;
	}
	return sum;
}

//【タイプ１】最適化後
//※一部の演算を共通化する
float testOpt06_Type1_After(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	//各要素を計算
	float sum = 0.f;
	const float calc = mul1 * mul2 / div;
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
	{
		dataOpt06_t::elem_t* elem_p = &data.elems[i];
		elem_p->value_c = (elem_p->value_a * calc) * 2.f +
		                  (elem_p->value_b * calc) * 3.f;
		sum += elem_p->value_c;
	}
	return sum;
}

//----------------------------------------
//最適化⑦：SIMD演算の活用
#include <memory.h>//memset用

//【タイプ１】最適化前

//----------
//行列の加算
//※単純ループ版
template<std::size_t N, std::size_t M>
void addMatrix(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) + mat2(n, m);
}
//----------
//行列のスカラー倍
//※単純ループ版
template<std::size_t N, std::size_t M>
void mulMatrixScalar(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) * scalar;
}
//----------
//行列の乗算
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
//行列の加算
#if 0
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
#include <xmmintrin.h>//SSE1用
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
//行列のスカラー倍
#if 0
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
#include <xmmintrin.h>//SSE1用
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
//行列の乗算
#if 0
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
#include <smmintrin.h>//SSE4.1用 ※内積計算用命令の _mm_dp_ps を利用
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
	//行列を乗算してmat0にストア（SSE4.1の内積命令使用）※ベタな処理
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
	//行列を乗算してmat0にストア（SSE4.1の内積命令使用）※シャッフル活用
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
#include <string.h>//strlen, strcmp, strncmp, strchr, strrchr, strcpy, strncpy用
std::size_t testOpt07_Type2_strlen_Before(const int dummy, const char* str)
{
	return strlen(str);
}
int testOpt07_Type2_strcmp_Before(const int dummy, const char* str1, const char* str2)
{
	return strcmp(str1, str2);
}
int testOpt07_Type2_strncmp_Before(const int dummy, const char* str1, const char* str2, const std::size_t max_len)
{
	return strncmp(str1, str2, max_len);
}
const char* testOpt07_Type2_strchr_Before(const int dummy, const char* str, const char c)
{
	return strchr(str, c);
}
const char* testOpt07_Type2_strrchr_Before(const int dummy, const char* str, const char c)
{
	return strrchr(str, c);
}
const char* testOpt07_Type2_strstr_Before(const int dummy, const char* str1, const char* str2)
{
	return strstr(str1, str2);
}
const char* testOpt07_Type2_strcpy_Before(const int dummy, char* dst, const char* src)
{
	return strcpy(dst, src);
}
const char* testOpt07_Type2_strncpy_Before(const int dummy, char* dst, const char* src, const std::size_t max_len)
{
	return strncpy(dst, src, max_len);
}
//【タイプ２】最適化後
#include <nmmintrin.h>//SSE4.2用
#include <cstdint>//intptr_t用
//----------
//SSE版strlen
std::size_t _strlen_fast(const char* str)
{
//nullチェックしない
//	if (!str)
//		return 0;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(str) & 0xf;
	if (str_over != 0)
	{
		//非16バイトアランイメント時
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
			return pos;
		p += (16 - str_over);
	}
	//16バイトアランイメント時
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
			return (reinterpret_cast<const char*>(p128) - str) + pos;
		++p128;
	}
	return 0;//dummy
}
//----------
//SSE版strnlen
std::size_t _strnlen_fast(const char* str, const std::size_t max_len)
{
//nullチェックしない
//	if (!str)
//		return 0;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	const char* p_end = str + max_len;
	const char* p_end_16 = p_end - 16;
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(str)& 0xf;
	if (str_over != 0)
	{
		//非16バイトアランイメント時
		const __m128i str16   = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			if (pos < max_len)
				return pos;
			return max_len;
		}
		p += (16 - str_over);
	}
	//16バイトアランイメント時
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (reinterpret_cast<const char*>(p128) <= p_end_16)
	{
		const __m128i str16   = _mm_load_si128(p128);
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
			return (reinterpret_cast<const char*>(p128) - str) + pos;
		++p128;
	}
	if (reinterpret_cast<const char*>(p128) < p_end)
	{
		const __m128i str16   = _mm_load_si128(p128);
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			const std::size_t len = (reinterpret_cast<const char*>(p128) - str) + pos;
			if (len <= max_len)
				return len;
		}
	}
	return max_len;
}
//----------
//SSE版strcmp補助関数
//アラインメント判定
//戻り値:
//  0 ... 16バイトアラインメント＋16バイトアラインメント
//  1 ... 16バイトアラインメント＋非16バイトアラインメント
//  2 ... 非16バイトアラインメント＋16バイトアラインメント
//  3 ... 非16バイトアラインメント＋非16バイトアラインメント
inline static int _str_case(const char* str1, const char* str2)
{
	return (((reinterpret_cast<intptr_t>(str1) & 0xf) != 0) << 0) |
	       (((reinterpret_cast<intptr_t>(str2) & 0xf) != 0) << 1);
}
//文字の大小判定
//戻り値: 0 ... 一致、1 ... val1の方が大きい、-1 ... val2の方が大きい
inline static int _strcmp_compare(const int val1, const int val2)
{
	const int val = val1 - val2;
	return (val >> 31) | (val != 0);
}
//SSE版strcmp:16バイトアランイメント＋16バイトアランイメント時
static int _strcmp_fast_case0(const char* str1, const char* str2)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
	const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
	while (true)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		++p1;
		++p2;
	}
	return 0;//dummy
}
//SSE版strcmp:非16バイトアランイメント＋16バイトアランイメント時
static int _strcmp_fast_case1(const char* str1, const char* str2)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p1 = str1;
	const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
	while (true)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(p1 + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		p1 += 16;
		++p2;
	}
	return 0;//dummy
}
//SSE版strcmp:16バイトアランイメント＋非16バイトアランイメント時
static int _strcmp_fast_case2(const char* str1, const char* str2)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
	const char* p2 = str2;
	while (true)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(p2 + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		++p1;
		p2 += 16;
	}
	return 0;//dummy
}
//SSE版strcmp:非16バイトアランイメント＋非16バイトアランイメント時
static int _strcmp_fast_case3(const char* str1, const char* str2)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p1 = str1;
	const char* p2 = str2;
	while (true)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		p1 += 16;
		p2 += 16;
	}
	return 0;//dummy
}
//SSE版strcmp:関数テーブル
typedef int (*_strcmp_fast_casex_t)(const char* str1, const char* str2);
static const _strcmp_fast_casex_t _strcmp_fast_casex[] =
{
	_strcmp_fast_case0,
	_strcmp_fast_case1,
	_strcmp_fast_case2,
	_strcmp_fast_case3
};
//SSE版strcmp
int _strcmp_fast(const char* str1, const char* str2)
{
//nullチェックしない
//	if (!str1) if (!str2) return 0;
//	           else       return -1;
//	else       if (!str2) return 1;
//	//         else       continue...
	return _strcmp_fast_casex[_str_case(str1, str2)](str1, str2);
}
//----------
//SSE版strncmp:16バイトアランイメント＋16バイトアランイメント時
static int _strncmp_fast_case0(const char* str1, const char* str2, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
	const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
	const char* p1_end = str1 + max_len;
	const char* p1_end_16 = p1_end - 16;
	while (reinterpret_cast<const char*>(p1) <= p1_end_16)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		++p1;
		++p2;
	}
	{
		const std::size_t remain = p1_end - reinterpret_cast<const char*>(p1);
		if (remain > 0)
		{
			const __m128i str16_1 = _mm_load_si128(p1);
			const __m128i str16_2 = _mm_load_si128(p2);
			const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
			//const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
			if (cf)
			{
				if (pos >= remain)
					return 0;
				const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
				const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
				return _strcmp_compare(c1, c2);
			}
			//if (zf)
			//	return 0;
		}
	}
	return 0;
}
//SSE版strncmp:非16バイトアランイメント＋16バイトアランイメント時
static int _strncmp_fast_case1(const char* str1, const char* str2, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	const char* p1 = str1;
	const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
	const char* p1_end = str1 + max_len;
	const char* p1_end_16 = p1_end - 16;
	while (p1 <= p1_end_16)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(p1 + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		p1 += 16;
		++p2;
	}
	{
		const std::size_t remain = p1_end - p1;
		if (remain > 0)
		{
			const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
			const __m128i str16_2 = _mm_load_si128(p2);
			const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
			//const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
			if (cf)
			{
				if (pos >= remain)
					return 0;
				const char c1 = *(p1 + pos);
				const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
				return _strcmp_compare(c1, c2);
			}
			//if (zf)
			//	return 0;
		}
	}
	return 0;
}
//SSE版strncmp:16バイトアランイメント＋非16バイトアランイメント時
static int _strncmp_fast_case2(const char* str1, const char* str2, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
	const char* p2 = str2;
	const char* p1_end = str1 + max_len;
	const char* p1_end_16 = p1_end - 16;
	while (reinterpret_cast<const char*>(p1) <= p1_end_16)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
			const char c2 = *(p2 + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		++p1;
		p2 += 16;
	}
	{
		const std::size_t remain = p1_end - reinterpret_cast<const char*>(p1);
		if (remain > 0)
		{
			const __m128i str16_1 = _mm_load_si128(p1);
			const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
			const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
			//const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
			if (cf)
			{
				if (pos >= remain)
					return 0;
				const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
				const char c2 = *(p2 + pos);
				return _strcmp_compare(c1, c2);
			}
			//if (zf)
			//	return 0;
		}
	}
	return 0;
}
//SSE版strncmp:非16バイトアランイメント＋非16バイトアランイメント時
static int _strncmp_fast_case3(const char* str1, const char* str2, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	const char* p1 = str1;
	const char* p2 = str2;
	const char* p1_end = str1 + max_len;
	const char* p1_end_16 = p1_end - 16;
	while (p1 <= p1_end_16)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(p1 + pos);
			const char c2 = *(p2 + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		p1 += 16;
		p2 += 16;
	}
	{
		const std::size_t remain = p1_end - p1;
		if (remain > 0)
		{
			const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
			const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
			const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
			//const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
			if (cf)
			{
				if (pos >= remain)
					return 0;
				const char c1 = *(p1 + pos);
				const char c2 = *(p2 + pos);
				return _strcmp_compare(c1, c2);
			}
			//if (zf)
			//	return 0;
		}
	}
	return 0;
}
//SSE版strncmp:関数テーブル
typedef int (*_strncmp_fast_casex_t)(const char* str1, const char* str2, const std::size_t max_len);
static const _strncmp_fast_casex_t _strncmp_fast_casex[] =
{
	_strncmp_fast_case0,
	_strncmp_fast_case1,
	_strncmp_fast_case2,
	_strncmp_fast_case3
};
//SSE版strncmp
int _strncmp_fast(const char* str1, const char* str2, const std::size_t max_len)
{
//nullチェックしない
//	if (!str1) if (!str2) return 0;
//	           else       return -1;
//	else       if (!str2) return 1;
//	//         else       continue...
	return _strncmp_fast_casex[_str_case(str1, str2)](str1, str2, max_len);
}
//----------
//SSE版strchr
const char* _strchr_fast(const char* str, const char c)
{
//nullチェックしない
//	if (!str)
//		return 0;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i c16 = _mm_set1_epi8(c);
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(str) & 0xf;
	if (str_over != 0)
	{
		//非16バイトアランイメント時
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int cf          = _mm_cmpistrc(c16, str16, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(c16, str16, flags);
		const std::size_t pos = _mm_cmpistri(c16, str16, flags);
		if (cf)
			return reinterpret_cast<const char*>(p) + pos;
		if (zf)
			return nullptr;
		p += (16 - str_over);
	}
	//16バイトアランイメント時
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int cf          = _mm_cmpistrc(c16, str16, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(c16, str16, flags);
		const std::size_t pos = _mm_cmpistri(c16, str16, flags);
		if (cf)
			return reinterpret_cast<const char*>(p128) + pos;
		if (zf)
			return nullptr;
		++p128;
	}
	return nullptr;//dummy
}
//----------
//SSE版strrchr
const char* _strrchr_fast(const char* str, const char c)
{
//nullチェックしない
//	if (!str)
//		return 0;
	const char* found_p = nullptr;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_MOST_SIGNIFICANT;
	const __m128i c16 = _mm_set1_epi8(c);
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(str) & 0xf;
	if (str_over != 0)
	{
		//非16バイトアランイメント時
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int cf          = _mm_cmpistrc(c16, str16, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(c16, str16, flags);
		const std::size_t pos = _mm_cmpistri(c16, str16, flags);
		if (cf)
			found_p = p + pos;
		if (zf)
			return found_p;
		p += (16 - str_over);
	}
	//16バイトアランイメント時
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int cf          = _mm_cmpistrc(c16, str16, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(c16, str16, flags);
		const std::size_t pos = _mm_cmpistri(c16, str16, flags);
		if (cf)
			found_p = reinterpret_cast<const char*>(p128) + pos;
		if (zf)
			return found_p;
		++p128;
	}
	return nullptr;//dummy
}
//----------
//SSE版strstr用補助関数:パターンが2文字専用
static const char* _strstr_fast_2(const char* str, const char* pattern)
{
//	if (*str == '\0' || *(str + 1) == '\0')//←この判定は呼び出し元で行っている
//		return nullptr;
	const char pattern_top_c = *pattern;//先頭の文字
	const char pattern_2nd_c = *(pattern + 1);//2文字目の文字
	const __m128i pattern_top_c16 = _mm_set1_epi8(pattern_top_c);
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(p) & 0xf;
	if (str_over != 0)
	{
		//非16バイトアランイメント時
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int zf = _mm_cmpistrz(pattern_top_c16, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const int cf = _mm_cmpistrc(pattern_top_c16, str16, flags);
		if (cf)
		{
			const __m128i mask = _mm_cmpistrm(pattern_top_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = p;
			while (found_bits)
			{
				if ((found_bits & 1) && *_p == pattern_top_c && *(_p + 1) == pattern_2nd_c)
					return _p;
				found_bits >>= 1;
				++_p;
			}
		}
		if (zf)
			return nullptr;
		p += (16 - str_over);
	}
	//16バイトアランイメント時
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int zf = _mm_cmpistrz(pattern_top_c16, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const int cf = _mm_cmpistrc(pattern_top_c16, str16, flags);
		if (cf)
		{
			const __m128i mask = _mm_cmpistrm(pattern_top_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = reinterpret_cast<const char*>(p128);
			while (found_bits)
			{
				if ((found_bits & 1) && *_p == pattern_top_c && *(_p + 1) == pattern_2nd_c)
					return _p;
				found_bits >>= 1;
				++_p;
			}
		}
		if (zf)
			return nullptr;
		++p128;
	}
	return nullptr;//dummy
}
//SSE版strstr補助関数:16バイトアランイメント＋16バイトアランイメント時
//戻り値: 0 ... 不一致, 1 ... 一致, 2 ... strの方が短い
static int _strstr_fast_cmp_case0(const char* str, const char* pattern)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str);
	const __m128i* p2 = reinterpret_cast<const __m128i*>(pattern);
	while (true)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
			return (c2 == '\0') | ((c1 == '\0') << 1);
		}
		if (zf)
			return 1;
		++p1;
		++p2;
	}
	return 0;//dummy
}
//SSE版strstr補助関数:非16バイトアランイメント＋16バイトアランイメント時
//戻り値: 0 ... 不一致, 1 ... 一致, 2 ... strの方が短い
static int _strstr_fast_cmp_case1(const char* str, const char* pattern)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p1 = str;
	const __m128i* p2 = reinterpret_cast<const __m128i*>(pattern);
	while (true)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(p1 + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return (c2 == '\0') | ((c1 == '\0') << 1);
		}
		if (zf)
			return 1;
		p1 += 16;
		++p2;
	}
	return 0;//dummy
}
//SSE版strstr補助関数:16バイトアランイメント＋非16バイトアランイメント時
//戻り値: 0 ... 不一致, 1 ... 一致, 2 ... strの方が短い
static int _strstr_fast_cmp_case2(const char* str, const char* pattern)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str);
	const char* p2 = pattern;
	while (true)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(p2 + pos);
			return (c2 == '\0') | ((c1 == '\0') << 1);
		}
		if (zf)
			return 1;
		++p1;
		p2 += 16;
	}
	return 0;//dummy
}
//SSE版strstr補助関数:非16バイトアランイメント＋非16バイトアランイメント時
//戻り値: 0 ... 不一致, 1 ... 一致, 2 ... strの方が短い
static int _strstr_fast_cmp_case3(const char* str, const char* pattern)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p1 = str;
	const char* p2 = pattern;
	while (true)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//※この三行は、コンパイル後は1回の cmpistri になる（はず）
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return (c2 == '\0') | ((c1 == '\0') << 1);
		}
		if (zf)
			return 1;
		p1 += 16;
		p2 += 16;
	}
	return 0;//dummy
}
//SSE版strstr:補助関数テーブル
typedef int(*_strstr_fast_cmp_casex_t)(const char* str, const char* pattern);
static const _strstr_fast_cmp_casex_t _strstr_fast_cmp_casex[] =
{
	_strstr_fast_cmp_case0,
	_strstr_fast_cmp_case1,
	_strstr_fast_cmp_case2,
	_strstr_fast_cmp_case3
};
//SSE版strstr補助関数
//戻り値: 0 ... 不一致, 1 ... 一致, 2 ... strの方が短い
inline static int _strstr_fast_cmp(const char* str, const char* pattern)
{
	return _strstr_fast_cmp_casex[_str_case(str, pattern)](str, pattern);
}
//SSE版strstr
const char* _strstr_fast(const char* str, const char* pattern)
{
//nullチェックしない
//	if (!str || !pattern)
//		return 0;
#if 0//strchr_fast()とstrncmp_fast()を活用した単純な処理（遅いのでNG）
	const std::size_t pattern_len = strlen_fast(pattern);
	const char pattern_c = *pattern;
	const char* p = str;
	while(true)
	{
		const char* found = strchr_fast(p, pattern_c);
		if (!found)
			return nullptr;
		if(strncmp_fast(found, pattern, pattern_len) == 0)
			return found;
		p = found + 1;
	}
	return nullptr;//dummy
#else//SSE命令使用 ※このやり方がベストだが、VC++のstrstrよりもはるかに遅い（GCCのstrstrよりは速い）
	//patternの長さに基づいて、処理を振り分ける
	if (*pattern == '\0')//パターンが0文字の時
		return str;
	if (*(pattern + 1) == '\0')//パターンが1文字の時
	{
		if (*str == '\0')
			return nullptr;
		return strchr(str, *pattern);
	}
	if (*(pattern + 2) == '\0')//パターンが2文字の時
	{
		if (*str == '\0' || *(str + 1) == '\0')
			return nullptr;
		return _strstr_fast_2(str, pattern);
	}
	const char pattern_top_c = *pattern;//先頭の文字
	const char pattern_2nd_c = *(pattern + 1);//2文字目の文字
	const __m128i pattern_top_c16 = _mm_set1_epi8(pattern_top_c);
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(p)& 0xf;
	if (str_over != 0)
	{
		//非16バイトアランイメント時
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int zf = _mm_cmpistrz(pattern_top_c16, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const int cf = _mm_cmpistrc(pattern_top_c16, str16, flags);
		if (cf)
		{
			const __m128i mask = _mm_cmpistrm(pattern_top_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = p;
			while (found_bits)
			{
				if (found_bits & 1)
				{
					if (*_p == pattern_top_c && *(_p + 1) == pattern_2nd_c)
					{
						const int cmp = _strstr_fast_cmp(_p, pattern);
						if (cmp != 0)
						{
							if (cmp == 1)
								return _p;
							else
								return nullptr;
						}
					}
				}
				found_bits >>= 1;
				++_p;
			}
		}
		if (zf)
			return nullptr;
		p += (16 - str_over);
	}
	//16バイトアランイメント時
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int zf = _mm_cmpistrz(pattern_top_c16, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const int cf = _mm_cmpistrc(pattern_top_c16, str16, flags);
		if (cf)
		{
			const __m128i mask = _mm_cmpistrm(pattern_top_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = reinterpret_cast<const char*>(p128);
			while (found_bits)
			{
				if (found_bits & 1)
				{
					if (*_p == pattern_top_c && *(_p + 1) == pattern_2nd_c)
					{
						const int cmp = _strstr_fast_cmp(_p, pattern);
						if (cmp != 0)
						{
							if (cmp == 1)
								return _p;
							else
								return nullptr;
						}
					}
				}
				found_bits >>= 1;
				++_p;
			}
		}
		if (zf)
			return nullptr;
		++p128;
	}
	return nullptr;//dummy
#endif
}
//SSE版strstr_bm
//※BM法（Boyer-Moore法）バージョン
//※文字列が長い時（とくにパターンが長い時）には有利なアルゴリズムだが、
//　短い場合は、スキップ文字数を事前計算する分遅くなる。
//※コールバック処理を追加し、見つかったパターンを順次通知するような
//　処理にすると、長いテキストの検索に威力を発揮する。
const char* _strstrbm_fast(const char* str, const char* pattern)
{
//nullチェックしない
//	if (!str || !pattern)
//		return 0;
#if 0//※SSE命令未使用版
	//patternの長さに基づいて、処理を振り分ける
	if (*pattern == '\0')//パターンが0文字の時
		return str;
	if (*(pattern + 1) == '\0')//パターンが1文字の時
	{
		if (*str == '\0')
			return nullptr;
		return strchr(str, *pattern);
	}
	const std::size_t pattern_len = strlen_fast(pattern);
	const std::size_t str_len = strlen_fast(str);
	if (str_len < pattern_len)
		return nullptr;
	//パターン内の文字ごとに、照合失敗時のスキップ文字数を記録
	int skip[256];
	for (std::size_t i = 0; i < 256; ++i)
		skip[i] = pattern_len;
	for (std::size_t i = 0; i < pattern_len; ++i)
		skip[static_cast<unsigned char>(pattern[i])] = pattern_len - i - 1;
	//検索開始
	const std::size_t pattern_term = pattern_len - 1;
	const char* pattern_term_p = pattern + pattern_term;
	const char* pattern_term_1_p = pattern_term_p - 1;
	const char pattern_term_c = *pattern_term_p;
	const char* str_end_p = str + str_len;
	const char* str_p = str + pattern_len - 1;
	while (str_p < str_end_p)
	{
		const char str_c = *str_p;
		if (str_c == pattern_term_c)
		{
			//パターンの末尾の文字が一致 ... パターンを照合する
			const char* _str_p = str_p - 1;
			const char* _pattern_p = pattern_term_1_p;
			char _str_c = *_str_p;
			while (true)
			{
				if (_str_c != *_pattern_p)//パターン不一致
					break;
				if (_pattern_p == pattern)//パターン検出
					return _str_p;
				--_pattern_p;
				--_str_p;
				_str_c = *_str_p;
			}
		#if 0
			//パターンの途中の文字が不一致 ... パターンの中に _str_c が見つかる位置まで移動
			--_pattern_p;
			++str_p;
			while (_pattern_p > pattern)
			{
				if (*_pattern_p == _str_c)
					break;
				--_pattern_p;
				++str_p;
			}
		#else
			//パターンの途中の文字が不一致 ... パターンの中に次の文字が見つかる位置まで移動
			_str_c = *(++str_p);
			const int _skip = skip[static_cast<unsigned char>(_str_c)];
			str_p += _skip;
		#endif
		}
		else
		{
			//パターンの末尾の文字が不一致 ... パターンの中に str_c が見つかる位置まで移動
			const int _skip = skip[static_cast<unsigned char>(str_c)];
			str_p += _skip;
		}
	}
	return nullptr;
#else//※SSE命令使用版
	if (*pattern == '\0')//パターンが0文字の時
		return str;
	if (*(pattern + 1) == '\0')//パターンが1文字の時
	{
		if (*str == '\0')
			return nullptr;
		return strchr(str, *pattern);
	}
	const std::size_t pattern_len = strlen_fast(pattern);
	const std::size_t str_len = strnlen_fast(str, pattern_len);
	if (str_len < pattern_len)
		return nullptr;
	//パターン内の文字ごとに、照合失敗時のスキップ文字数を記録
	int skip[256];
	for (std::size_t i = 0; i < 256; ++i)
		skip[i] = pattern_len;
	for (std::size_t i = 0; i < pattern_len; ++i)
		skip[pattern[i]] = pattern_len - i - 1;
	//検索開始
	const std::size_t pattern_term = pattern_len - 1;
	const char* pattern_term_p = pattern + pattern_term;
	const char* pattern_term_1_p = pattern_term_p - 1;
	const char pattern_term_c = *pattern_term_p;
	const __m128i pattern_term_c16 = _mm_set1_epi8(pattern_term_c);
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* str_p = str + pattern_len - 1;
	while (true)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(str_p));
		const int zf = _mm_cmpistrz(pattern_term_c16, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const int cf = _mm_cmpistrc(pattern_term_c16, str16, flags);
		if (cf)
		{
			//パターンの末尾の文字が一致（16文字まとめて照合） ... パターンを照合する
			const __m128i mask = _mm_cmpistrm(pattern_term_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = str_p;
			while (found_bits)
			{
				if (found_bits & 1)
				{
					const char* _str_p = str_p - 1;
					const char* _pattern_p = pattern_term_1_p;
					char _str_c = *_str_p;
					while (true)
					{
						if (_str_c != *_pattern_p)//パターン不一致
							break;
						if (_pattern_p == pattern)//パターン検出
							return _str_p;
						--_pattern_p;
						--_str_p;
						_str_c = *_str_p;
					}
				#if 0
					//パターンの途中の文字が不一致 ... パターンの中に _str_c が見つかる位置まで移動
					--_pattern_p;
					++str_p;
					found_bits >>= 1;
					while (_pattern_p > pattern)
					{
						if (*_pattern_p == _str_c)
							break;
						--_pattern_p;
						++str_p;
						found_bits >>= 1;
					}
				#else
					//パターンの途中の文字が不一致 ... パターンの中に次の文字が見つかる位置まで移動
					_str_c = *(++str_p);
					found_bits >>= 1;
					const int _skip = skip[static_cast<unsigned char>(_str_c)];
					str_p += _skip;
					found_bits >>= _skip;
				#endif
				}
				else
				{
					found_bits >>= 1;
					++str_p;
				}
			}
			if (zf)
				return nullptr;
		}
		else
		{
			if (zf)
				return nullptr;
			//パターンの末尾の文字が不一致 ... パターンの中に次の文字が見つかる位置まで移動
			const char str_c = *(str_p += 16);
			const int _skip = skip[static_cast<unsigned char>(str_c)];
		}
	}
	return nullptr;
#endif
}
//----------
//SSE版strstr0
//※strの先頭からのみpatternを照合する
const char* _strstr0_fast(const char* str, const char* pattern)
{
	const int ret = _strstr_fast_cmp(str, pattern);
	if (ret == 1)
		return str;
	return nullptr;
}
//----------
//SSE版strcpy用補助関数
#define _MEMCPY_M128I_TYPE 2// 0 ... memcpy() 使用
                            // 1 ... コピーサイズとアラインメントごとの関数
                            // 2 ... コピーサイズごとの関数（アラインメント無視／16バイトの時だけアランイメントで振り分け）
                            // 3 ... _mm_maskmoveu_si128() 使用
//SSE版strcpy用補助関数:_m128iからメモリへのコピー用関数
//【OK】コピーサイズごとの関数を用意するやり方は、memcpy()を使うよりも速かった
static void _memcpy_m128i_00_a(char* dst, const __m128i src)
{
	//なにもしない
}
static void _memcpy_m128i_00_u(char* dst, const __m128i src)
{
	//なにもしない
}
static void _memcpy_m128i_01_a(char* dst, const __m128i src)
{
	*dst = *reinterpret_cast<const char*>(&src);
}
static void _memcpy_m128i_01_u(char* dst, const __m128i src)
{
	*dst = *reinterpret_cast<const char*>(&src);
}
static void _memcpy_m128i_02_a(char* dst, const __m128i src)
{
	*reinterpret_cast<short*>(dst) = *reinterpret_cast<const short*>(&src);
}
static void _memcpy_m128i_02_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_03_a(char* dst, const __m128i src)
{
	*reinterpret_cast<short*>(dst) = *reinterpret_cast<const short*>(&src);
	*reinterpret_cast<char*>(reinterpret_cast<short*>(dst)+1) = *reinterpret_cast<const char*>(reinterpret_cast<const short*>(&src) + 1);
}
static void _memcpy_m128i_03_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_04_a(char* dst, const __m128i src)
{
	*reinterpret_cast<int*>(dst) = *reinterpret_cast<const int*>(&src);
}
static void _memcpy_m128i_04_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_05_a(char* dst, const __m128i src)
{
	*reinterpret_cast<int*>(dst) = *reinterpret_cast<const int*>(&src);
	*reinterpret_cast<char*>(reinterpret_cast<int*>(dst)+1) = *reinterpret_cast<const char*>(reinterpret_cast<const int*>(&src) + 1);
}
static void _memcpy_m128i_05_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_06_a(char* dst, const __m128i src)
{
	*reinterpret_cast<int*>(dst) = *reinterpret_cast<const int*>(&src);
	*reinterpret_cast<short*>(reinterpret_cast<int*>(dst)+1) = *reinterpret_cast<const short*>(reinterpret_cast<const int*>(&src) + 1);
}
static void _memcpy_m128i_06_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_07_a(char* dst, const __m128i src)
{
	*reinterpret_cast<int*>(dst) = *reinterpret_cast<const int*>(&src);
	*reinterpret_cast<short*>(reinterpret_cast<int*>(dst)+1) = *reinterpret_cast<const short*>(reinterpret_cast<const int*>(&src) + 1);
	*reinterpret_cast<char*>(reinterpret_cast<short*>(reinterpret_cast<int*>(dst)+1) + 1) = *reinterpret_cast<const char*>(reinterpret_cast<const short*>(reinterpret_cast<const int*>(&src) + 1) + 1);
}
static void _memcpy_m128i_07_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_08_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
}
static void _memcpy_m128i_08_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_09_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<char*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const char*>(reinterpret_cast<const long long*>(&src) + 1);
}
static void _memcpy_m128i_09_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_10_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<short*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const short*>(reinterpret_cast<const long long*>(&src) + 1);
}
static void _memcpy_m128i_10_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_11_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<short*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const short*>(reinterpret_cast<const long long*>(&src) + 1);
	*reinterpret_cast<char*>(reinterpret_cast<short*>(reinterpret_cast<long long*>(dst)+1) + 1) = *reinterpret_cast<const char*>(reinterpret_cast<const short*>(reinterpret_cast<const long long*>(&src) + 1) + 1);
}
static void _memcpy_m128i_11_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_12_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1);
}
static void _memcpy_m128i_12_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_13_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1);
	*reinterpret_cast<char*>(reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) + 1) = *reinterpret_cast<const char*>(reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1) + 1);
}
static void _memcpy_m128i_13_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_14_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1);
	*reinterpret_cast<short*>(reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) + 1) = *reinterpret_cast<const short*>(reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1) + 1);
}
static void _memcpy_m128i_14_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_15_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1);
	*reinterpret_cast<short*>(reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) + 1) = *reinterpret_cast<const short*>(reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1) + 1);
	*reinterpret_cast<char*>(reinterpret_cast<short*>(reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) + 1) + 1) = *reinterpret_cast<const char*>(reinterpret_cast<const short*>(reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1) + 1) + 1);
}
static void _memcpy_m128i_15_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_16_a(char* dst, const __m128i src)
{
	_mm_store_si128(reinterpret_cast<__m128i*>(dst), src);
}
static void _memcpy_m128i_16_u(char* dst, const __m128i src)
{
	_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), src);
}
//SSE版strcpy用補助関数:_m128iからメモリへのコピー用関数テーブル
typedef void(*_memcpy_m128i_x_t)(char* dst, const __m128i src);
static const _memcpy_m128i_x_t _memcpy_m128i_a_x[17] =
{
	_memcpy_m128i_00_a,
	_memcpy_m128i_01_a,
	_memcpy_m128i_02_a,
	_memcpy_m128i_03_a,
	_memcpy_m128i_04_a,
	_memcpy_m128i_05_a,
	_memcpy_m128i_06_a,
	_memcpy_m128i_07_a,
	_memcpy_m128i_08_a,
	_memcpy_m128i_09_a,
	_memcpy_m128i_10_a,
	_memcpy_m128i_11_a,
	_memcpy_m128i_12_a,
	_memcpy_m128i_13_a,
	_memcpy_m128i_14_a,
	_memcpy_m128i_15_a,
	_memcpy_m128i_16_a,
};
#if _MEMCPY_M128I_TYPE == 1
static const _memcpy_m128i_x_t _memcpy_m128i_u_x[17] =
{
	_memcpy_m128i_00_u,
	_memcpy_m128i_01_u,
	_memcpy_m128i_02_u,
	_memcpy_m128i_03_u,
	_memcpy_m128i_04_u,
	_memcpy_m128i_05_u,
	_memcpy_m128i_06_u,
	_memcpy_m128i_07_u,
	_memcpy_m128i_08_u,
	_memcpy_m128i_09_u,
	_memcpy_m128i_10_u,
	_memcpy_m128i_11_u,
	_memcpy_m128i_12_u,
	_memcpy_m128i_13_u,
	_memcpy_m128i_14_u,
	_memcpy_m128i_15_u,
	_memcpy_m128i_16_u,
};
#elif _MEMCPY_M128I_TYPE == 2
static const _memcpy_m128i_x_t _memcpy_m128i_u_x[17] =
{
	_memcpy_m128i_00_a,
	_memcpy_m128i_01_a,
	_memcpy_m128i_02_a,
	_memcpy_m128i_03_a,
	_memcpy_m128i_04_a,
	_memcpy_m128i_05_a,
	_memcpy_m128i_06_a,
	_memcpy_m128i_07_a,
	_memcpy_m128i_08_a,
	_memcpy_m128i_09_a,
	_memcpy_m128i_10_a,
	_memcpy_m128i_11_a,
	_memcpy_m128i_12_a,
	_memcpy_m128i_13_a,
	_memcpy_m128i_14_a,
	_memcpy_m128i_15_a,
	_memcpy_m128i_16_u,
};
#elif _MEMCPY_M128I_TYPE == 3
//SSE版strcpy用補助関数:_m128iからメモリへのコピー用定数：_mm_maskmoveu_si128()用
//【NG】_mm_maskmoveu_si128()を使用したやり方は、memcpy()を使うよりも遅かった
static const __m128i _memcpy_m128i_flags[17] =
{
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
};
#endif
//SSE版strcpy用補助関数:_m128iからメモリへのコピー用関数
inline static void _memcpy_m128i_a(__m128i* dst, const __m128i src, const std::size_t len)
{
#if _MEMCPY_M128I_TYPE == 1//↓速い
	_memcpy_m128i_a_x[len](reinterpret_cast<char*>(dst), src);
#elif _MEMCPY_M128I_TYPE == 2//↓最速
	_memcpy_m128i_a_x[len](reinterpret_cast<char*>(dst), src);
#elif _MEMCPY_M128I_TYPE == 3//↓かなり遅い
	_mm_maskmoveu_si128(src, _memcpy_m128i_flags[len], reinterpret_cast<const char*>(dst));
#else//_MEMCPY_M128I_TYPE == 0//↓割と速い
	memcpy(reinterpret_cast<const char*>(dst), reinterpret_cast<const char*>(&src), len);
#endif
}
inline static void _memcpy_m128i_u(char* dst, const __m128i src, const std::size_t len)
{
#if _MEMCPY_M128I_TYPE == 1//↓速い
	_memcpy_m128i_u_x[len](dst, src);
#elif _MEMCPY_M128I_TYPE == 2//↓最速
	_memcpy_m128i_u_x[len](dst, src);
#elif _MEMCPY_M128I_TYPE == 4//↓かなり遅い
	_mm_maskmoveu_si128(src, _memcpy_m128i_flags[len], dst);
#else//_MEMCPY_M128I_TYPE == 0//↓割と速い
	memcpy(dst, reinterpret_cast<const char*>(&src), len);
#endif
}
//SSE版strcpy:16バイトアランイメント＋16バイトアランイメント時
static const char* _strcpy_fast_case0(char* dst, const char* src)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
	const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(src_p);
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			_memcpy_m128i_a(dst_p, str16, pos + 1);
			return dst;
		}
		_mm_store_si128(dst_p, str16);
		++dst_p;
		++src_p;
	}
	return nullptr;//dummy
}
//SSE版strcpy:非16バイトアランイメント＋16バイトアランイメント時
static const char* _strcpy_fast_case1(char* dst, const char* src)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	char* dst_p = dst;
	const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(src_p);
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			_memcpy_m128i_u(dst_p, str16, pos + 1);
			return dst;
		}
		_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
		dst_p += 16;
		++src_p;
	}
	return nullptr;//dummy
}
//SSE版strcpy:16バイトアランイメント＋非16バイトアランイメント時
static const char* _strcpy_fast_case2(char* dst, const char* src)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
	const char* src_p = src;
	while (true)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			_memcpy_m128i_a(dst_p, str16, pos + 1);
			return dst;
		}
		_mm_store_si128(dst_p, str16);
		++dst_p;
		src_p += 16;
	}
	return nullptr;//dummy
}
//SSE版strcpy:非16バイトアランイメント＋非16バイトアランイメント時
static const char* _strcpy_fast_case3(char* dst, const char* src)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	char* dst_p = dst;
	const char* src_p = src;
	while (true)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			_memcpy_m128i_u(dst_p, str16, pos + 1);
			return dst;
		}
		_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
		dst_p += 16;
		src_p += 16;
	}
	return nullptr;//dummy
}
//SSE版strcpy:関数テーブル
typedef const char* (*_strcpy_fast_casex_t)(char* dst, const char* src);
static const _strcpy_fast_casex_t _strcpy_fast_casex[] =
{
	_strcpy_fast_case0,
	_strcpy_fast_case1,
	_strcpy_fast_case2,
	_strcpy_fast_case3
};
//SSE版strcpy
const char* _strcpy_fast(char* dst, const char* src)
{
#if 0//strlen_fastを活用して単純化した処理（遅いのでNG）
	//※もし、memcpyがsseのストアよりも高速であるならこの方が速い（かもしれない）
	memcpy(dst, src, strlen_fast(src));
	return dst;
#else
//nullチェックしない
//	if (!dst || !src)
//		return nullptr;
	return _strcpy_fast_casex[_str_case(dst, src)](dst, src);
#endif
}
//----------
//SSE版strncpy用補助関数
//※前提：この処理は、max_len > len の時にしか呼び出されないものとする。
//　　　　max_len >= len の時は、_memcpy_m128i() を使用する。
#ifdef STRNCPY_PADDING_ZERO
inline static void _memncpy_m128i_a(__m128i* dst, const __m128i src, const std::size_t len, const std::size_t max_len)
{
	_memcpy_m128i_a(dst, src, len);
	memset(reinterpret_cast<char*>(dst) + len, '\0', max_len - len);
}
inline static void _memncpy_m128i_u(char* dst, const __m128i src, const std::size_t len, const std::size_t max_len)
{
	_memcpy_m128i_u(dst, src, len);
	memset(dst + len, '\0', max_len - len);
}
#else//STRNCPY_PADDING_ZERO
inline static void _memncpy_m128i_a(__m128i* dst, const __m128i src, const std::size_t len)
{
	_memcpy_m128i_a(dst, src, len);
	*(reinterpret_cast<char*>(dst) + len) = '\0';
}
inline static void _memncpy_m128i_u(char* dst, const __m128i src, const std::size_t len)
{
	_memcpy_m128i_u(dst, src, len);
	dst[len] = '\0';
}
#endif//STRNCPY_PADDING_ZERO
//SSE版strncpy:16バイトアランイメント＋16バイトアランイメント時
static const char* _strncpy_fast_case0(char* dst, const char* src, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
	const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
	const char* src_end = src + max_len;
	const char* src_end_16 = src_end - 16;
	while (reinterpret_cast<const char*>(src_p) <= src_end_16)
	{
		const __m128i str16 = _mm_load_si128(src_p);
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
		#ifdef STRNCPY_PADDING_ZERO
			const std::size_t remain = src_end - reinterpret_cast<const char*>(src_p);
			_memncpy_m128i_a(dst_p, str16, pos, remain);
		#else//STRNCPY_PADDING_ZERO
			_memncpy_m128i_a(dst_p, str16, pos);
		#endif//STRNCPY_PADDING_ZERO
			return dst;
		}
		_mm_store_si128(dst_p, str16);
		++dst_p;
		++src_p;
	}
	{
		const std::size_t remain = src_end - reinterpret_cast<const char*>(src_p);
		if (remain > 0)
		{
			const __m128i str16 = _mm_load_si128(src_p);
			_memcpy_m128i_a(dst_p, str16, remain);
		}
	}
	return dst;
}
//SSE版strncpy:非16バイトアランイメント＋16バイトアランイメント時
static const char* _strncpy_fast_case1(char* dst, const char* src, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	char* dst_p = dst;
	const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
	const char* src_end = src + max_len;
	const char* src_end_16 = src_end - 16;
	while (reinterpret_cast<const char*>(src_p) <= src_end_16)
	{
		const __m128i str16 = _mm_load_si128(src_p);
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
		#ifdef STRNCPY_PADDING_ZERO
			const std::size_t remain = src_end - reinterpret_cast<const char*>(src_p);
			_memncpy_m128i_u(dst_p, str16, pos, remain);
		#else//STRNCPY_PADDING_ZERO
			_memncpy_m128i_u(dst_p, str16, pos);
		#endif//STRNCPY_PADDING_ZERO
			return dst;
		}
		_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
		dst_p += 16;
		++src_p;
	}
	{
		const std::size_t remain = src_end - reinterpret_cast<const char*>(src_p);
		if (remain > 0)
		{
			const __m128i str16 = _mm_load_si128(src_p);
			_memcpy_m128i_u(dst_p, str16, remain);
		}
	}
	return dst;
}
//SSE版strncpy:16バイトアランイメント＋非16バイトアランイメント時
static const char* _strncpy_fast_case2(char* dst, const char* src, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
	const char* src_p = src;
	const char* src_end = src + max_len;
	const char* src_end_16 = src_end - 16;
	while (src_p <= src_end_16)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
		#ifdef STRNCPY_PADDING_ZERO
			const std::size_t remain = src_end - src_p;
			_memncpy_m128i_a(dst_p, str16, pos, remain);
		#else//STRNCPY_PADDING_ZERO
			_memncpy_m128i_a(dst_p, str16, pos);
		#endif//STRNCPY_PADDING_ZERO
			return dst;
		}
		_mm_store_si128(dst_p, str16);
		++dst_p;
		src_p += 16;
	}
	{
		const std::size_t remain = src_end - src_p;
		if (remain > 0)
		{
			const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
			_memcpy_m128i_a(dst_p, str16, remain);
		}
	}
	return dst;
}
//SSE版strncpy:非16バイトアランイメント＋非16バイトアランイメント時
static const char* _strncpy_fast_case3(char* dst, const char* src, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i null = _mm_setzero_si128();
	char* dst_p = dst;
	const char* src_p = src;
	const char* src_end = src + max_len;
	const char* src_end_16 = src_end - 16;
	while (src_p <= src_end_16)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//※この二行は、コンパイル後は1回の cmpistri になる（はず）
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
		#ifdef STRNCPY_PADDING_ZERO
			const std::size_t remain = src_end - src_p;
			_memncpy_m128i_u(dst_p, str16, pos, remain);
		#else//STRNCPY_PADDING_ZERO
			_memncpy_m128i_u(dst_p, str16, pos);
		#endif//STRNCPY_PADDING_ZERO
			return dst;
		}
		_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
		dst_p += 16;
		src_p += 16;
	}
	{
		const std::size_t remain = src_end - src_p;
		if (remain > 0)
		{
			const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
			_memcpy_m128i_u(dst_p, str16, remain);
		}
	}
	return dst;
}
//SSE版strncpy:関数テーブル
typedef const char* (*_strncpy_fast_casex_t)(char* dst, const char* src, const std::size_t max_len);
static const _strncpy_fast_casex_t _strncpy_fast_casex[] =
{
	_strncpy_fast_case0,
	_strncpy_fast_case1,
	_strncpy_fast_case2,
	_strncpy_fast_case3
};
//SSE版strncpy
const char* _strncpy_fast(char* dst, const char* src, const std::size_t max_len)
{
#if 0//strlen_fastを活用して単純化した処理（遅いのでNG）
	//※もし、memcpyがsseのストアよりも高速であるならこの方が速い（かもしれない）
	const std::size_t len = strlen_fast(src);
	if (len >= max_len)
	{
		memcpy(dst, src, max_len);
		return dst;
	}
	else
	{
		memcpy(dst, src, len);
		//memset(dst + len, '\0', max_len - len);//strncpy本来の仕様
		dst[len] = '\0';//これでも十分
		return dst;
	}
	return nullptr;//dummy
#else
//nullチェックしない
//	if (!dst || !src)
//		return nullptr;
	return _strncpy_fast_casex[_str_case(dst, src)](dst, src, max_len);
#endif
}
//テスト
void testOpt07_Type2_After_1time()
{
#if 1
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
#if 1
	{
		#define NLEN(s, n) printf("nlen(\"%s\", %d)=%d(%d)\n", s, n, strnlen_fast(s, n), strlen(s));
		NLEN("", 0);
		NLEN("a", 0);
		NLEN("ab", 0);
		NLEN("abc", 0);
		NLEN("abcd", 0);
		NLEN("abcde", 0);
		NLEN("a\0b", 0);
		NLEN("\0a", 0);
		NLEN("1234567890abcde", 0);
		NLEN("1234567890abcdef", 0);
		NLEN("1234567890abcdefg", 0);
		NLEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", 0);
		NLEN("", 1);
		NLEN("a", 1);
		NLEN("ab", 1);
		NLEN("abc", 1);
		NLEN("abcd", 1);
		NLEN("abcde", 1);
		NLEN("a\0b", 1);
		NLEN("\0a", 1);
		NLEN("1234567890abcde", 1);
		NLEN("1234567890abcdef", 1);
		NLEN("1234567890abcdefg", 1);
		NLEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", 1);
		NLEN("", 2);
		NLEN("a", 2);
		NLEN("ab", 2);
		NLEN("abc", 2);
		NLEN("abcd", 2);
		NLEN("abcde", 2);
		NLEN("a\0b", 2);
		NLEN("\0a", 2);
		NLEN("1234567890abcde", 2);
		NLEN("1234567890abcdef", 2);
		NLEN("1234567890abcdefg", 2);
		NLEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", 2);
		NLEN("", 15);
		NLEN("a", 15);
		NLEN("ab", 15);
		NLEN("abc", 15);
		NLEN("abcd", 15);
		NLEN("abcde", 15);
		NLEN("a\0b", 15);
		NLEN("\0a", 15);
		NLEN("1234567890abcde", 15);
		NLEN("1234567890abcdef", 15);
		NLEN("1234567890abcdefg", 15);
		NLEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", 15);
		NLEN("", 16);
		NLEN("a", 16);
		NLEN("ab", 16);
		NLEN("abc", 16);
		NLEN("abcd", 16);
		NLEN("abcde", 16);
		NLEN("a\0b", 16);
		NLEN("\0a", 16);
		NLEN("1234567890abcde", 16);
		NLEN("1234567890abcdef", 16);
		NLEN("1234567890abcdefg", 16);
		NLEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", 16);
		NLEN("", 17);
		NLEN("a", 17);
		NLEN("ab", 17);
		NLEN("abc", 17);
		NLEN("abcd", 17);
		NLEN("abcde", 17);
		NLEN("a\0b", 17);
		NLEN("\0a", 17);
		NLEN("1234567890abcde", 17);
		NLEN("1234567890abcdef", 17);
		NLEN("1234567890abcdefg", 17);
		NLEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", 17);
		NLEN("", 999);
		NLEN("a", 999);
		NLEN("ab", 999);
		NLEN("abc", 999);
		NLEN("abcd", 999);
		NLEN("abcde", 999);
		NLEN("a\0b", 999);
		NLEN("\0a", 999);
		NLEN("1234567890abcde", 999);
		NLEN("1234567890abcdef", 999);
		NLEN("1234567890abcdefg", 999);
		NLEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", 999);
		#undef LEN
}
#endif
#if 1
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
		CMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcdef");
		CMP("1234567890abcdef1234567890abcde0", "1234567890abcdef1234567890abcdef");
		CMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcde0");
		CMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcde");
		CMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcdef1");
		CMP("1234567890abcdef1234567890abcde", "1234567890abcdef1234567890abcdef");
		CMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef");
		CMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef1");
		CMP("1234567890abcdef1234567890abcdef0", "1234567890abcdef1234567890abcdef1");
		CMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef0");
		CMP("\0a", "\0b");
		#undef CMP
	}
#endif
#if 1
	{
		#define NCMP(s1, s2, n) printf("ncmp(\"%s\", \"%s\", %d)=%d(%d)\n", s1, s2, n, strncmp_fast(s1, s2, n), strncmp(s1, s2, n));
		NCMP("a", "a", 16);
		NCMP("a", "b", 16);
		NCMP("b", "a", 16);
		NCMP("aaa", "aaa", 16);
		NCMP("aab", "aaa", 16);
		NCMP("aaa", "aab", 16);
		NCMP("aba", "aaa", 16);
		NCMP("aaa", "aba", 16);
		NCMP("abc", "acb", 16);
		NCMP("acb", "abc", 16);
		NCMP("a", "a", 2);
		NCMP("a", "b", 2);
		NCMP("b", "a", 2);
		NCMP("aaa", "aaa", 2);
		NCMP("aab", "aaa", 2);
		NCMP("aaa", "aab", 2);
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
#if 1
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
		CHR("1234567890abcdef", 'f');
		CHR("1234567890abcdef", 'x');
		CHR("1234567890abcdefx", 'f');
		CHR("1234567890abcdefx", 'x');
		CHR("1234567890abcdefx", 'z');
		CHR("1234567890abcdefxy", 'x');
		CHR("1234567890abcdefxy", 'z');
		#undef CHR
	}
#endif
#if 1
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
		CHRR("1234567890abcdef", 'f');
		CHRR("1234567890abcdef", 'x');
		CHRR("1234567890abcdefx", 'f');
		CHRR("1234567890abcdefx", 'x');
		CHRR("1234567890abcdefx", 'z');
		CHRR("1234567890abcdefxy", 'x');
		CHRR("1234567890abcdefxy", 'z');
		#undef CHRR
	}
#endif
#if 1
	{
		#define STR(s1, s2) printf("str(\"%s\", \"%s\")=\"%s\"(\"%s\")\n", s1, s2, strstr_fast(s1, s2), strstr(s1, s2));
		STR("1", "23");
		STR("12", "23");
		STR("123", "23");
		STR("1234", "23");
		STR("12341", "23");
		STR("123412", "23");
		STR("1234123", "23");
		STR("12341234", "12x");
		STR("12341234", "x23");
		STR("12312312313132132123x23123132", "12x");
		STR("12312312313132132123x23123132", "x23");
		STR("12341234", "4");
		STR("12341234", "");
		STR("123a123b123c123d123e123f123x123h123i123j", "x");
		STR("123a123b123c123d123e123f123x123h123i123j", "");
		STR("a123b1123c2123d3123e1123f2123g3123x123h1123i2123jk", "123x123");
		STR("123aあ123bあい123cあいう123dあいうえ123eいうえお123fあいうえおか123x", "あいうえお");
		STR("1234567890abcdef1234567890abcdefx234567890abcdef", "x234567890abcdef");
		STR("1234567890abcdef1234567890abcdefx234567890abcdef", "x234567890abcdefg");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefg", "x234567890abcdefg");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefgh", "x234567890abcdefg");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefg", "x234567890abcdefx");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefx", "x234567890abcdefx");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefxy", "x234567890abcdefx");
		STR("1234567890abcde!!234567890abcdef", "!!");
		STR("!1234567890!abcdef!!1234567890!abcdef!", "!!");
		STR("1234567890abcd!!!!34567890abcdef", "!!!!");
		STR("1234567890abcdef!!!!1234567890abcdef", "!!!!");
		STR("!12345678!90abcdef!!!!12345678!90abcdef!", "!!!!");
		STR("!!12345678!!90abcdef!!!!12345678!!90abcdef!!", "!!!!");
		STR("!!!12345678!!!90abcdef!!!!12345678!!!90abcdef!!!", "!!!!");
		STR("!!!12345678!!!90abcdef!!!12345678!!!90abcdef!!!", "!!!!");
		STR("!!!12345678!!!90abcdef!!!12345678!!!90abcdef!!!!", "!!!!");
		STR("1234567890abcdef", "1234567890abcdef");
		STR("1234567890abcdefgh", "1234567890abcdefg");
		STR("1234567890abcdef1234567890abcdefgh", "1234567890abcdefg");
		STR("10234567890abcdefgh1234567890abcdefgh", "1234567890abcdefg");
		STR("aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
		STR("abcdefghijklmnopqrstuvwxyzaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz", "bbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabc");
		#undef STR
	}
#endif
#if 1
	{
		#define STRBM(s1, s2) printf("strbm(\"%s\", \"%s\")=\"%s\"(\"%s\")\n", s1, s2, strstrbm_fast(s1, s2), strstr(s1, s2));
		STRBM("1", "23");
		STRBM("12", "23");
		STRBM("123", "23");
		STRBM("1234", "23");
		STRBM("12341", "23");
		STRBM("123412", "23");
		STRBM("1234123", "23");
		STRBM("12341234", "12x");
		STRBM("12341234", "x23");
		STRBM("12312312313132132123x23123132", "12x");
		STRBM("12312312313132132123x23123132", "x23");
		STRBM("12341234", "4");
		STRBM("12341234", "");
		STRBM("123a123b123c123d123e123f123x123h123i123j", "x");
		STRBM("123a123b123c123d123e123f123x123h123i123j", "");
		STRBM("a123b1123c2123d3123e1123f2123g3123x123h1123i2123jk", "123x123");
		STRBM("123aあ123bあい123cあいう123dあいうえ123eいうえお123fあいうえおか123x", "あいうえお");
		STRBM("1234567890abcdef1234567890abcdefx234567890abcdef", "x234567890abcdef");
		STRBM("1234567890abcdef1234567890abcdefx234567890abcdef", "x234567890abcdefg");
		STRBM("1234567890abcdef1234567890abcdefx234567890abcdefg", "x234567890abcdefg");
		STRBM("1234567890abcdef1234567890abcdefx234567890abcdefgh", "x234567890abcdefg");
		STRBM("1234567890abcdef1234567890abcdefx234567890abcdefg", "x234567890abcdefx");
		STRBM("1234567890abcdef1234567890abcdefx234567890abcdefx", "x234567890abcdefx");
		STRBM("1234567890abcdef1234567890abcdefx234567890abcdefxy", "x234567890abcdefx");
		STRBM("1234567890abcde!!234567890abcdef", "!!");
		STRBM("!1234567890!abcdef!!1234567890!abcdef!", "!!");
		STRBM("1234567890abcd!!!!34567890abcdef", "!!!!");
		STRBM("1234567890abcdef!!!!1234567890abcdef", "!!!!");
		STRBM("!12345678!90abcdef!!!!12345678!90abcdef!", "!!!!");
		STRBM("!!12345678!!90abcdef!!!!12345678!!90abcdef!!", "!!!!");
		STRBM("!!!12345678!!!90abcdef!!!!12345678!!!90abcdef!!!", "!!!!");
		STRBM("!!!12345678!!!90abcdef!!!12345678!!!90abcdef!!!", "!!!!");
		STRBM("!!!12345678!!!90abcdef!!!12345678!!!90abcdef!!!!", "!!!!");
		STRBM("1234567890abcdef", "1234567890abcdef");
		STRBM("1234567890abcdefgh", "1234567890abcdefg");
		STRBM("1234567890abcdef1234567890abcdefgh", "1234567890abcdefg");
		STRBM("10234567890abcdefgh1234567890abcdefgh", "1234567890abcdefg");
		STRBM("aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
		STRBM("abcdefghijklmnopqrstuvwxyzaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz", "bbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabc");
		#undef STRBM
	}
#endif
#if 1
	{
		#define STR0(s1, s2) printf("str0(\"%s\", \"%s\")=\"%s\"(\"%s\")\n", s1, s2, strstr0_fast(s1, s2), strstr(s1, s2));
		STR0("1", "123");
		STR0("12", "123");
		STR0("123", "123");
		STR0("1234", "123");
		STR0("12341", "123");
		STR0("123412", "123");
		STR0("1234123", "123");
		STR0("12341234", "123");
		STR0("x12341234", "123");
		STR0("1234567890abcdef", "1234567890abcdef");
		STR0("1234567890abcdefg", "1234567890abcdef");
		STR0("1234567890abcdef", "1234567890abcdefg");
		STR0("1234567890abcdefg", "1234567890abcdefg");
		STR0("1234567890abcdefgh", "1234567890abcdefg");
		STR0("x1234567890abcdefgh", "1234567890abcdefg");
		STR0("1234567890abcdefghijklmnopqrstuvwxyz", "1234567890abcdefghijklmnopqrstuvwxyz");
		STR0("1234567890abcdefghijklmnopqrstuvwxyz!", "1234567890abcdefghijklmnopqrstuvwxyz");
		STR0("1234567890abcdefghijklmnopqrstuvwxyz", "1234567890abcdefghijklmnopqrstuvwxyz!");
		STR0("1234567890abcdefghijklmnopqrstuvwxyz!", "1234567890abcdefghijklmnopqrstuvwxyz!");
		STR0("1234567890abcdefghijklmnopqrstuvwxyz!!", "1234567890abcdefghijklmnopqrstuvwxyz!");
		STR0("x1234567890abcdefghijklmnopqrstuvwxyz!!", "1234567890abcdefghijklmnopqrstuvwxyz!");
		#undef STR0
	}
#endif
#if 1
	{
		char alignas(16) buff[20];
		char dummy_for_align = 123;
		char buffu[20];
		const __m128i str16 = _mm_setr_epi8('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f');
		printf("(dummy_for_align=%d)\n", dummy_for_align);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  0); printf("_memcpy_m128i_a(buff, str16,  0)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  1); printf("_memcpy_m128i_a(buff, str16,  1)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  2); printf("_memcpy_m128i_a(buff, str16,  2)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  3); printf("_memcpy_m128i_a(buff, str16,  3)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  4); printf("_memcpy_m128i_a(buff, str16,  4)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  5); printf("_memcpy_m128i_a(buff, str16,  5)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  6); printf("_memcpy_m128i_a(buff, str16,  6)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  7); printf("_memcpy_m128i_a(buff, str16,  7)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  8); printf("_memcpy_m128i_a(buff, str16,  8)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  9); printf("_memcpy_m128i_a(buff, str16,  9)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 10); printf("_memcpy_m128i_a(buff, str16, 10)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 11); printf("_memcpy_m128i_a(buff, str16, 11)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 12); printf("_memcpy_m128i_a(buff, str16, 12)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 13); printf("_memcpy_m128i_a(buff, str16, 13)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 14); printf("_memcpy_m128i_a(buff, str16, 14)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 15); printf("_memcpy_m128i_a(buff, str16, 15)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 16); printf("_memcpy_m128i_a(buff, str16, 16)=\"%s\"\n", buff);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  0); printf("_memcpy_m128i_u(buffu, str16,  0)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  1); printf("_memcpy_m128i_u(buffu, str16,  1)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  2); printf("_memcpy_m128i_u(buffu, str16,  2)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  3); printf("_memcpy_m128i_u(buffu, str16,  3)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  4); printf("_memcpy_m128i_u(buffu, str16,  4)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  5); printf("_memcpy_m128i_u(buffu, str16,  5)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  6); printf("_memcpy_m128i_u(buffu, str16,  6)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  7); printf("_memcpy_m128i_u(buffu, str16,  7)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  8); printf("_memcpy_m128i_u(buffu, str16,  8)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  9); printf("_memcpy_m128i_u(buffu, str16,  9)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 10); printf("_memcpy_m128i_u(buffu, str16, 10)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 11); printf("_memcpy_m128i_u(buffu, str16, 11)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 12); printf("_memcpy_m128i_u(buffu, str16, 12)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 13); printf("_memcpy_m128i_u(buffu, str16, 13)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 14); printf("_memcpy_m128i_u(buffu, str16, 14)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 15); printf("_memcpy_m128i_u(buffu, str16, 15)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 16); printf("_memcpy_m128i_u(buffu, str16, 16)=\"%s\"\n", buffu);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_00_a(buff, str16); printf("_memcpy_m128i_00_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_01_a(buff, str16); printf("_memcpy_m128i_01_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_02_a(buff, str16); printf("_memcpy_m128i_02_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_03_a(buff, str16); printf("_memcpy_m128i_03_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_04_a(buff, str16); printf("_memcpy_m128i_04_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_05_a(buff, str16); printf("_memcpy_m128i_05_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_06_a(buff, str16); printf("_memcpy_m128i_06_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_07_a(buff, str16); printf("_memcpy_m128i_07_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_08_a(buff, str16); printf("_memcpy_m128i_08_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_09_a(buff, str16); printf("_memcpy_m128i_09_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_10_a(buff, str16); printf("_memcpy_m128i_10_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_11_a(buff, str16); printf("_memcpy_m128i_11_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_12_a(buff, str16); printf("_memcpy_m128i_12_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_13_a(buff, str16); printf("_memcpy_m128i_13_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_14_a(buff, str16); printf("_memcpy_m128i_14_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_15_a(buff, str16); printf("_memcpy_m128i_15_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_16_a(buff, str16); printf("_memcpy_m128i_16_a(buff, str16) =\"%s\"\n", buff);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_00_u(buffu, str16); printf("_memcpy_m128i_00_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_01_u(buffu, str16); printf("_memcpy_m128i_01_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_02_u(buffu, str16); printf("_memcpy_m128i_02_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_03_u(buffu, str16); printf("_memcpy_m128i_03_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_04_u(buffu, str16); printf("_memcpy_m128i_04_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_05_u(buffu, str16); printf("_memcpy_m128i_05_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_06_u(buffu, str16); printf("_memcpy_m128i_06_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_07_u(buffu, str16); printf("_memcpy_m128i_07_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_08_u(buffu, str16); printf("_memcpy_m128i_08_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_09_u(buffu, str16); printf("_memcpy_m128i_09_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_10_u(buffu, str16); printf("_memcpy_m128i_10_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_11_u(buffu, str16); printf("_memcpy_m128i_11_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_12_u(buffu, str16); printf("_memcpy_m128i_12_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_13_u(buffu, str16); printf("_memcpy_m128i_13_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_14_u(buffu, str16); printf("_memcpy_m128i_14_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_15_u(buffu, str16); printf("_memcpy_m128i_15_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_16_u(buffu, str16); printf("_memcpy_m128i_16_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_00_a(buffu, str16); printf("_memcpy_m128i_00_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_01_a(buffu, str16); printf("_memcpy_m128i_01_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_02_a(buffu, str16); printf("_memcpy_m128i_02_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_03_a(buffu, str16); printf("_memcpy_m128i_03_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_04_a(buffu, str16); printf("_memcpy_m128i_04_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_05_a(buffu, str16); printf("_memcpy_m128i_05_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_06_a(buffu, str16); printf("_memcpy_m128i_06_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_07_a(buffu, str16); printf("_memcpy_m128i_07_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_08_a(buffu, str16); printf("_memcpy_m128i_08_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_09_a(buffu, str16); printf("_memcpy_m128i_09_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_10_a(buffu, str16); printf("_memcpy_m128i_10_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_11_a(buffu, str16); printf("_memcpy_m128i_11_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_12_a(buffu, str16); printf("_memcpy_m128i_12_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_13_a(buffu, str16); printf("_memcpy_m128i_13_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_14_a(buffu, str16); printf("_memcpy_m128i_14_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_15_a(buffu, str16); printf("_memcpy_m128i_15_a(buffu, str16)=\"%s\"\n", buffu);
		//memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_16_a(buffu, str16); printf("_memcpy_m128i_16_a(buffu, str16)=\"%s\"\n", buffu);//←エラー
	}
#endif
#if 1
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
#if 1
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
		NCPY(buff1, "z", 2);
		NCPY(buff1, "zy", 2);
		NCPY(buff1, "zyx", 2);
		NCPY(buff1, "zyxw", 2);
		NCPY(buff1, "zyxwv", 2);
		NCPY(buff1, "A\0B", 2);
		NCPY(buff1, "\0C", 2);
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
}
std::size_t testOpt07_Type2_strlen_After(const int dummy, const char* str)
{
	return strlen_fast(str);
}
int testOpt07_Type2_strcmp_After(const int dummy, const char* str1, const char* str2)
{
	return strcmp_fast(str1, str2);
}
int testOpt07_Type2_strncmp_After(const int dummy, const char* str1, const char* str2, const std::size_t max_len)
{
	return strncmp_fast(str1, str2, max_len);
}
const char* testOpt07_Type2_strchr_After(const int dummy, const char* str, const char c)
{
	return strchr_fast(str, c);
}
const char* testOpt07_Type2_strrchr_After(const int dummy, const char* str, const char c)
{
	return strrchr_fast(str, c);
}
const char* testOpt07_Type2_strstr_After1(const int dummy, const char* str1, const char* str2)
{
	return strstr_fast(str1, str2);
}
const char* testOpt07_Type2_strstr_After2(const int dummy, const char* str1, const char* str2)
{
	return strstrbm_fast(str1, str2);
}
const char* testOpt07_Type2_strcpy_After(const int dummy, char* dst, const char* src)
{
	return strcpy_fast(dst, src);
}
const char* testOpt07_Type2_strncpy_After(const int dummy, char* dst, const char* src, const std::size_t max_len)
{
	return strncpy_fast(dst, src, max_len);
}

//----------------------------------------
//最適化⑧：条件分岐の削減

//【タイプ１】最適化前
//※if文を使った分かり易い処理
int testOpt08_Type1_Before(const int value)
{
	//前提：value = 0 ～ 499
	if (value >= 400)
		return 4;
	else if (value >= 300)
		return 3;
	else if (value >= 200)
		return 2;
	else if (value >= 100)
		return 1;
	return 0;
}
//【タイプ１】最適化後１
//※分岐を計算式に変更
int testOpt08_Type1_After1(const int value)
{
	//前提：value = 0 ～ 499
	return value >= 400 ? 4 :
				value >= 300 ? 3 :
					value >= 200 ? 2 :
						value >= 100 ? 1 :
							0;
}
//【タイプ１】最適化後２
//※分岐を更に最適化した計算式に変更
int testOpt08_Type1_After2(const int value)
{
	//前提：value = 0 ～ 499
	return value / 100;
}
//【タイプ１】最適化後３
//※分岐を更に最適化した計算式に変更
int testOpt08_Type1_After3(const int value)
{
	//前提：value = 0 ～ 499
	return (value >= 100) +
	       (value >= 200) +
		   (value >= 300) +
		   (value >= 400);
}

//【タイプ２】最適化前
//※if文を使った分かり易い処理
int testOpt08_Type2_Before(const int value)
{
	//前提：value = 0 ～ 299
	if (value >= 200)
		return 2;
	else if (value >= 100)
		return 1;
	return 0;
}
//【タイプ２】最適化後１
//※分岐を計算式に変更
int testOpt08_Type2_After1(const int value)
{
	//前提：value = 0 ～ 299
	return value >= 200 ? 2 :
				value >= 100 ? 1 :
					0;
}
//【タイプ２】最適化後２
//※分岐を更に最適化した計算式に変更
int testOpt08_Type2_After2(const int value)
{
	//前提：value = 0 ～ 299
	return value / 100;
}
//【タイプ２】最適化後３
//※分岐を更に最適化した計算式に変更
int testOpt08_Type2_After3(const int value)
{
	//前提：value = 0 ～ 299
	return (value >= 100) +
		(value >= 200);
}

//【タイプ３】最適化前
//※論理演算
bool testOpt08_Type3_Before(const int value1, const int value2)
{
	return (value1 >= 100) && (value2 >= 100);
}
//【タイプ３】最適化後
//※ビット演算
bool testOpt08_Type3_After(const int value1, const int value2)
{
	return (value1 >= 100) & (value2 >= 100);
}

//【タイプ４】最適化前
//※if文による64バイトアラインメント計算
int testOpt08_Type4_Before(const int value)
{
	if (value % 64 == 0)
		return value;
	return value + (64 - (value % 64));
}
//【タイプ４】最適化後１
//※三項演算子によるアラインメント計算
int testOpt08_Type4_After1(const int value)
{
	const int over = value % 64;
	return (over == 0) ? value : value + (64 - over);
}
//【タイプ４】最適化後２
//※計算式のみによるアラインメント計算
int testOpt08_Type4_After2(const int value)
{
	return (value + 63) & ~63;
}

//【タイプ５】最適化前
//※ループとif文によるビット数計測
int testOpt08_Type5_Before(const int value)
{
	int bits = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (value & (1 << i))
			++bits;
	}
	return bits;
}
//【タイプ５】最適化後１
//※ベタ書きでビット数計測
int testOpt08_Type5_After1(const int value)
{
	unsigned int bits =
		((value & 0x00000001) != 0) +
		((value & 0x00000002) != 0) +
		((value & 0x00000004) != 0) +
		((value & 0x00000008) != 0) +
		((value & 0x00000010) != 0) +
		((value & 0x00000020) != 0) +
		((value & 0x00000040) != 0) +
		((value & 0x00000080) != 0) +
		((value & 0x00000100) != 0) +
		((value & 0x00000200) != 0) +
		((value & 0x00000400) != 0) +
		((value & 0x00000800) != 0) +
		((value & 0x00001000) != 0) +
		((value & 0x00002000) != 0) +
		((value & 0x00004000) != 0) +
		((value & 0x00008000) != 0) +
		((value & 0x00010000) != 0) +
		((value & 0x00020000) != 0) +
		((value & 0x00040000) != 0) +
		((value & 0x00080000) != 0) +
		((value & 0x00100000) != 0) +
		((value & 0x00200000) != 0) +
		((value & 0x00400000) != 0) +
		((value & 0x00800000) != 0) +
		((value & 0x01000000) != 0) +
		((value & 0x02000000) != 0) +
		((value & 0x04000000) != 0) +
		((value & 0x08000000) != 0) +
		((value & 0x10000000) != 0) +
		((value & 0x20000000) != 0) +
		((value & 0x40000000) != 0) +
		((value & 0x80000000) != 0);
	return bits;
}
//【タイプ５】最適化後２
//※計算式のみによるビット数計測
inline int countBits(const int value)
{
	unsigned int bits = static_cast<unsigned int>(value);
	bits = ((bits >>  1) & 0x55555555) + (bits & 0x55555555);//1ビットずつ16個の加算
	bits = ((bits >>  2) & 0x33333333) + (bits & 0x33333333);//2ビットずつ8個の加算
	bits = ((bits >>  4) & 0x0f0f0f0f) + (bits & 0x0f0f0f0f);//4ビットずつ4個の加算
	bits = ((bits >>  8) & 0x00ff00ff) + (bits & 0x00ff00ff);//8ビットずつ2個の加算
	bits = ((bits >> 16) & 0x0000ffff) + (bits & 0x0000ffff);//最終加算
	return static_cast<int>(bits);
}
int testOpt08_Type5_After2(const int value)
{
	return countBits(value);
}
//【タイプ５】最適化後３
//※更に最適化
inline int countBits2(const int value)
{
	unsigned int bits = static_cast<unsigned int>(value);
	bits = bits - ((bits >> 1) & 0x55555555);//2ビットずつ16個の減算 ※1ビットずつ16個の加算と同じ結果になる
	bits = ((bits >> 2) & 0x33333333) + (bits & 0x33333333);//2ビットずつ8個の加算
	bits = (((bits >> 4) + bits) & 0x0f0f0f0f);//4ビットずつ4個の加算 ※加算の繰り上げが隣の値まで及ばないのでマスクなしで加算可能
	bits *= 0x01010101;//8ビットずつ4個の値をまとめて加算
	                   //※上位から8ビットごとに [ 4個の加算値, 3個の加算値, 2個の加算値, 1個の値 ] という値ができ上がる
	bits >>= 24;//上位8ビットを取り出す
	return static_cast<int>(bits);
}
int testOpt08_Type5_After3(const int value)
{
	return countBits2(value);
}

//【タイプ６】最適化前
//※ループとif文によるMSB(Most Significant Bit)数計測
int testOpt08_Type6_Before(const int value)
{
	for (int i = 31; i >= 0; --i)
	{
		if (value & (1 << i))
			return i;
	}
	return -1;
}
//【タイプ６】最適化後１
//※ベタ書きでMSB(Most Significant Bit)計測
int testOpt08_Type6_After1(const int value)
{
	if (value & 0x80000000) return 31;
	if (value & 0x40000000) return 30;
	if (value & 0x20000000) return 29;
	if (value & 0x10000000) return 28;
	if (value & 0x08000000) return 27;
	if (value & 0x04000000) return 26;
	if (value & 0x02000000) return 25;
	if (value & 0x01000000) return 24;
	if (value & 0x00800000) return 23;
	if (value & 0x00400000) return 22;
	if (value & 0x00200000) return 21;
	if (value & 0x00100000) return 20;
	if (value & 0x00080000) return 19;
	if (value & 0x00040000) return 18;
	if (value & 0x00020000) return 17;
	if (value & 0x00010000) return 16;
	if (value & 0x00008000) return 15;
	if (value & 0x00004000) return 14;
	if (value & 0x00002000) return 13;
	if (value & 0x00001000) return 12;
	if (value & 0x00000800) return 11;
	if (value & 0x00000400) return 10;
	if (value & 0x00000200) return 9;
	if (value & 0x00000100) return 8;
	if (value & 0x00000080) return 7;
	if (value & 0x00000040) return 6;
	if (value & 0x00000020) return 5;
	if (value & 0x00000010) return 4;
	if (value & 0x00000008) return 3;
	if (value & 0x00000004) return 2;
	if (value & 0x00000002) return 1;
	if (value & 0x00000001) return 0;
	return -1;
}
//【タイプ６】最適化後２
//※計算式のみによるMSB(Most Significant Bit)計測
int testOpt08_Type6_After2(const int value)
{
	unsigned int bits = static_cast<unsigned int>(value);
	bits |= (bits >> 16);//上位16ビットのビット数を倍にする
	bits |= (bits >>  8);//上位24ビットのビット数を倍にする
	bits |= (bits >>  4);//上位28ビットのビット数を倍にする
	bits |= (bits >>  2);//上位30ビットのビット数を倍にする
	bits |= (bits >>  1);//上位31ビットのビット数を倍にする
	int bit = countBits2(static_cast<int>(bits));//ビット数を計測
	--bit;//-1～31の値に調整
	return bit;
}
//【タイプ６】最適化後３
//※より少ない判定量でMSB(Most Significant Bit)計測
int testOpt08_Type6_After3(const int value)
{
	int bit = 0;
	unsigned int _value = static_cast<unsigned int>(value);
	if (_value & 0xffff0000){ bit += 16; _value >>= 16; }//上位16ビット分のビット位置を計上
	if (_value & 0x0000ff00){ bit +=  8; _value >>=  8; }//上位24ビット分のビット位置を計上
	if (_value & 0x000000f0){ bit +=  4; _value >>=  4; }//上位28ビット分のビット位置を計上
	if (_value & 0x0000000c){ bit +=  2; _value >>=  2; }//上位30ビット分のビット位置を計上
	if (_value & 0x00000002){ ++bit;     _value >>=  1; }//上位31ビット分のビット位置を計上
	if (_value & 0x00000001){ ++bit;                    }//全ビット分のビット位置を計上
	--bit;//-1～31の値に調整
	return bit;
}
//【タイプ６】最適化後４
//※より少ない判定量でMSB(Most Significant Bit)計測
int testOpt08_Type6_After4(const int value)
{
	int bit = 0;
	unsigned int _value = static_cast<unsigned int>(value);
	int shift;
	shift = ((_value & 0xffff0000) != 0) << 4; bit += shift; _value >>= shift;//上位16ビット分のビット位置を計上
	shift = ((_value & 0x0000ff00) != 0) << 3; bit += shift; _value >>= shift;//上位24ビット分のビット位置を計上
	shift = ((_value & 0x000000f0) != 0) << 2; bit += shift; _value >>= shift;//上位28ビット分のビット位置を計上
	shift = ((_value & 0x0000000c) != 0) << 1; bit += shift; _value >>= shift;//上位30ビット分のビット位置を計上
	shift = ((_value & 0x00000002) != 0) << 0; bit += shift; _value >>= shift;//上位31ビット分のビット位置を計上
	shift = ((_value & 0x00000001) != 0) << 0; bit += shift;                  //全ビット分のビット位置を計上
	--bit;//-1～31の値に調整
	return bit;
}
//【タイプ６】最適化後５
//※より少ない判定量でMSB(Most Significant Bit)計測
int testOpt08_Type6_After5(const int value)
{
	if (value != 0)
		if (value & 0xffff0000)
			if (value & 0xff000000)
				if (value & 0xf0000000)
					if (value & 0xc0000000)
						if (value & 0x80000000)
							return 31;
						else//if(value & 0x40000000)
							return 30;
					else//if(value & 0x30000000)
						if (value & 0x20000000)
							return 29;
						else//if(value & 0x10000000)
							return 28;
				else//if(value & 0x0f000000)
					if (value & 0x0c000000)
						if (value & 0x08000000)
							return 27;
						else//if(value & 0x04000000)
							return 26;
					else//if(value & 0x03000000)
						if (value & 0x02000000)
							return 25;
						else//if(value & 0x01000000)
							return 24;
			else//if(value & 0x00ff0000)
				if (value & 0x00f00000)
					if (value & 0x00c00000)
						if (value & 0x00800000)
							return 23;
						else//if(value & 0x00400000)
							return 22;
					else//if(value & 0x00300000)
						if (value & 0x00200000)
							return 21;
						else//if(value & 0x00100000)
							return 20;
				else//if(value & 0x000f0000)
					if (value & 0x000c0000)
						if (value & 0x00080000)
							return 19;
						else//if(value & 0x00040000)
							return 18;
					else//if(value & 0x00030000)
						if (value & 0x00020000)
							return 17;
						else//if(value & 0x00010000)
							return 16;
		else//if(value & 0x0000ffff)
			if (value & 0x0000ff00)
				if (value & 0x0000f000)
					if (value & 0x0000c000)
						if (value & 0x00008000)
							return 15;
						else//if(value & 0x00004000)
							return 14;
					else//if(value & 0x00003000)
						if (value & 0x00002000)
							return 13;
						else//if(value & 0x00001000)
							return 12;
				else//if(value & 0x00000f00)
					if (value & 0x00000c00)
						if (value & 0x00000800)
							return 11;
						else//if(value & 0x00000400)
							return 10;
					else//if(value & 0x00000300)
						if (value & 0x00000200)
							return 9;
						else//if(value & 0x00000100)
							return 8;
			else//if(value & 0x000000ff)
				if (value & 0x000000f0)
					if (value & 0x000000c0)
						if (value & 0x00000080)
							return 7;
						else//if(value & 0x00000040)
							return 6;
					else//if(value & 0x00000030)
						if (value & 0x00000020)
							return 5;
						else//if(value & 0x00000010)
							return 4;
				else//if(value & 0x0000000f)
					if (value & 0x0000000c)
						if (value & 0x00000008)
							return 3;
						else//if(value & 0x00000004)
							return 2;
					else//if(value & 0x00000003)
						if (value & 0x00000002)
							return 1;
						else//if(value & 0x00000001)
							return 0;
	//else//if(value == 0)
	return -1;
}

//【タイプ７】最適化前
//※ループとif文によるLSB(Last Significant Bit)数計測
int testOpt08_Type7_Before(const int value)
{
	for (int i = 0; i < 32; ++i)
	{
		if (value & (1 << i))
			return i;
	}
	return -1;
}
//【タイプ７】最適化後１
//※計算式のみによるLSB(Last Significant Bit)計測
int testOpt08_Type7_After1(const int value)
{
	if (value & 0x00000001) return 0;
	if (value & 0x00000002) return 1;
	if (value & 0x00000004) return 2;
	if (value & 0x00000008) return 3;
	if (value & 0x00000010) return 4;
	if (value & 0x00000020) return 5;
	if (value & 0x00000040) return 6;
	if (value & 0x00000080) return 7;
	if (value & 0x00000100) return 8;
	if (value & 0x00000200) return 9;
	if (value & 0x00000400) return 10;
	if (value & 0x00000800) return 11;
	if (value & 0x00001000) return 12;
	if (value & 0x00002000) return 13;
	if (value & 0x00004000) return 14;
	if (value & 0x00008000) return 15;
	if (value & 0x00010000) return 16;
	if (value & 0x00020000) return 17;
	if (value & 0x00040000) return 18;
	if (value & 0x00080000) return 19;
	if (value & 0x00100000) return 20;
	if (value & 0x00200000) return 21;
	if (value & 0x00400000) return 22;
	if (value & 0x00800000) return 23;
	if (value & 0x01000000) return 24;
	if (value & 0x02000000) return 25;
	if (value & 0x04000000) return 26;
	if (value & 0x08000000) return 27;
	if (value & 0x10000000) return 28;
	if (value & 0x20000000) return 29;
	if (value & 0x40000000) return 30;
	if (value & 0x80000000) return 31;
	return -1;
}
//【タイプ７】最適化後２
//※計算式のみによるLSB(Last Significant Bit)計測
int testOpt08_Type7_After2(const int value)
{
	unsigned int bits = static_cast<unsigned int>(value);
	bits |= (bits << 16);//下位16ビットのビット数を倍にする
	bits |= (bits <<  8);//下位24ビットのビット数を倍にする
	bits |= (bits <<  4);//下位28ビットのビット数を倍にする
	bits |= (bits <<  2);//下位30ビットのビット数を倍にする
	bits |= (bits <<  1);//下位31ビットのビット数を倍にする
	int bit = countBits2(static_cast<int>(bits));//ビット数を計測
	--bit;//-1～31の値に調整
	const int sign = bit >> 31;//符号（-1か0）を取得
	bit = 31 - bit;//ビット番号反転（0～32の値になる）
	bit |= sign;//符号を合成して -1～31の値に調整
	return bit;
}
//【タイプ７】最適化後３
//※より少ない判定量でLSB(Last Significant Bit)計測
int testOpt08_Type7_After3(const int value)
{
	int bit = 0;
	unsigned int _value = static_cast<unsigned int>(value);
	if (_value & 0x0000ffff){ bit -= 16; _value <<= 16; }//下位16ビット分のビット位置を計上
	if (_value & 0x00ff0000){ bit -=  8; _value <<=  8; }//下位24ビット分のビット位置を計上
	if (_value & 0x0f000000){ bit -=  4; _value <<=  4; }//下位28ビット分のビット位置を計上
	if (_value & 0x30000000){ bit -=  2; _value <<=  2; }//下位30ビット分のビット位置を計上
	if (_value & 0x40000000){ --bit;     _value <<=  1; }//下位31ビット分のビット位置を計上
	if (_value & 0x80000000){ --bit;                    }//全ビット分のビット位置を計上
	int sign = (bit ^ 0x80000000);//符号ビットを取得
	sign >>= 31;//符号を-1か0に拡張
	bit += 32;//ビット番号を調整（0～32の値になる）
	bit |= sign;//符号を合成して -1～31の値に調整
	return bit;
}
//【タイプ７】最適化後４
//※より少ない判定量でLSB(Last Significant Bit)計測
int testOpt08_Type7_After4(const int value)
{
	int bit = 0;
	unsigned int _value = static_cast<unsigned int>(value);
	int shift;
	shift = ((_value & 0x0000ffff) != 0) << 4; bit -= shift; _value <<= shift;//下位16ビット分のビット位置を計上
	shift = ((_value & 0x00ff0000) != 0) << 3; bit -= shift; _value <<= shift;//下位24ビット分のビット位置を計上
	shift = ((_value & 0x0f000000) != 0) << 2; bit -= shift; _value <<= shift;//下位28ビット分のビット位置を計上
	shift = ((_value & 0x30000000) != 0) << 1; bit -= shift; _value <<= shift;//下位30ビット分のビット位置を計上
	shift = ((_value & 0x40000000) != 0) << 0; bit -= shift; _value <<= shift;//下位31ビット分のビット位置を計上
	shift = ((_value & 0x80000000) != 0) << 0; bit -= shift;                  //全ビット分のビット位置を計上
	int sign = (bit ^ 0x80000000);//符号ビットを取得
	sign >>= 31;//符号を-1か0に拡張
	bit += 32;//ビット番号を調整（0～32の値になる）
	bit |= sign;//符号を合成して -1～31の値に調整
	return bit;
}
//【タイプ７】最適化後５
//※より少ない判定量でLSB(Last Significant Bit)計測
int testOpt08_Type7_After5(const int value)
{
	if (value != 0)
		if (value & 0x0000ffff)
			if (value & 0x000000ff)
				if (value & 0x0000000f)
					if (value & 0x00000003)
						if (value & 0x00000001)
							return 0;
						else//if(value & 0x00000002)
							return 1;
					else//if(value & 0x0000000c)
						if (value & 0x00000004)
							return 2;
						else//if(value & 0x00000008)
							return 3;
				else//if(value & 0x000000f0)
					if (value & 0x00000030)
						if (value & 0x00000010)
							return 4;
						else//if(value & 0x00000020)
							return 5;
					else//if(value & 0x000000c0)
						if (value & 0x00000040)
							return 6;
						else//if(value & 0x00000080)
							return 7;
			else//if(value & 0x0000ff00)
				if (value & 0x00000f00)
					if (value & 0x00000300)
						if (value & 0x00000100)
							return 8;
						else//if(value & 0x00000200)
							return 9;
					else//if(value & 0x00000c00)
						if (value & 0x00000400)
							return 10;
						else//if(value & 0x00000800)
							return 11;
				else//if(value & 0x0000f000)
					if (value & 0x00003000)
						if (value & 0x00001000)
							return 12;
						else//if(value & 0x00002000)
							return 13;
					else//if(value & 0x0000c000)
						if (value & 0x00004000)
							return 14;
						else//if(value & 0x00008000)
							return 15;
		else//if(value & 0xffff0000)
			if (value & 0x00ff0000)
				if (value & 0x000f0000)
					if (value & 0x00030000)
						if (value & 0x00010000)
							return 16;
						else//if(value & 0x00020000)
							return 17;
					else//if(value & 0x000c0000)
						if (value & 0x00040000)
							return 18;
						else//if(value & 0x00080000)
							return 19;
				else//if(value & 0x00f00000)
					if (value & 0x00300000)
						if (value & 0x00100000)
							return 20;
						else//if(value & 0x00200000)
							return 21;
					else//if(value & 0x00c00000)
						if (value & 0x00400000)
							return 22;
						else//if(value & 0x00800000)
							return 23;
			else//if(value & 0xff000000)
				if (value & 0x0f000000)
					if (value & 0x03000000)
						if (value & 0x01000000)
							return 24;
						else//if(value & 0x02000000)
							return 25;
					else//if(value & 0x0c000000)
						if (value & 0x04000000)
							return 26;
						else//if(value & 0x08000000)
							return 27;
				else//if(value & 0xf0000000)
					if (value & 0x30000000)
						if (value & 0x10000000)
							return 28;
						else//if(value & 0x20000000)
							return 29;
					else//if(value & 0xc0000000)
						if (value & 0x40000000)
							return 30;
						else//if(value & 0x80000000)
							return 31;
	//else//if (value == 0x0)
	return -1;
}

#if 0//インライン関数化
//【タイプ８】最適化前
//※if文による絶対値計算
int testOpt08_Type8_Before(const int value)
{
	if (value < 0)
		return -value;
	return value;
}
//【タイプ８】最適化後
//※計算式のみによる絶対値計算
int testOpt08_Type8_After(const int value)
{
#if 1
	const int sign = value >> 31;//符号（-1か0）を取得
	return (sign ^ value) - sign;//正の数の時: (0x00000000 ^ value) -  0 => value
	                             //負の数の時: (0xffffffff ^ value) - -1 => ~value + 1
#elif 1
	//インラインアセンブラ：パターン１
	__asm
	{
		mov    eax, value
		cdq
		xor    eax, edx
		sub    eax, edx
	}
#else
	//インラインアセンブラ：パターン２
	__asm
	{
		mov    eax, value
		mov    ecx, eax
		neg    ecx
		cmovns eax, ecx
	}
#endif
}
//【タイプ８】【参考１】
//※三項演算子による絶対値計算
int testOpt08_Type8_Appendix1(const int value)
{
	return value < 0 ? -value : value;
}
//【タイプ８】【参考２】
//※標準ライブラリによる絶対値算出
#include <stdlib.h>
int testOpt08_Type8_Appendix2(const int value)
{
	return abs(value);
}
#endif

#if 0//インライン関数化
//【タイプ９】最適化前
//※if文による符号取得
int testOpt08_Type9_Before(const int value)
{
	if (value < 0)
		return -1;
	else if (value > 0)
		return 1;
	return 0;
}
//【タイプ９】最適化後
//※計算式のみによる符号取得
int testOpt08_Type9_After(const int value)
{
#if 1
	const int sign = value >> 31;//符号（-1か0）を取得
	const int nz = value != 0;//非ゼロ判定
	return sign | nz;
#else
	//インラインアセンブラ
	__asm
	{
		mov    eax, value
		xor    ecx, ecx
		test   eax, eax
		setne  cl
		cdq
		mov    eax, edx
		or     eax, ecx
	}
#endif
}
//【タイプ９】【参考】
//※三項演算子による符号取得
int testOpt08_Type9_Appendix(const int value)
{
	return value < 0 ? -1 : value > 0 ? 1 : 0;
}
#endif

//----------------------------------------
//最適化⑨：ループ回数の削減：ループアンローリング

//【タイプ１】初期化
void initOpt09_t1(dataOpt09_t1& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt09_t1::elem_t::VALUE_RANGE - 1);
	for (auto& elem : data.elems)
	{
		elem.value = rnd_dist(rnd_engine);
	}
}
//【タイプ１】最適化前
//※加算ループ
int testOpt09_Type1_Before(dataOpt09_t1& data)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); ++i)
	{
		sum += data.elems[i].value;
	}
	return sum;
}
//【タイプ１】最適化後１
//※減算ループ
int testOpt09_Type1_After1(dataOpt09_t1& data)
{
	int sum = 0;
	for (int i = static_cast<int>(extentof(data.elems)) - 1; i >= 0; --i)
	{
		sum += data.elems[i].value;
	}
	return sum;
}
//【タイプ１】最適化後２
//※ポインタループ展開
int testOpt09_Type1_After2(dataOpt09_t1& data)
{
	int sum = 0;
	const dataOpt09_t1::elem_t* elem_end = data.elems + extentof(data.elems);
	for (const dataOpt09_t1::elem_t* elem = data.elems; elem < elem_end; ++elem)
	{
		sum += elem->value;
	}
	return sum;
}
//【タイプ１】最適化後３
//※自前ループアンローリング×２
int testOpt09_Type1_After3(dataOpt09_t1& data)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); i += 2)
	{
		const dataOpt09_t1::elem_t* _elem0 = &data.elems[i];
		const dataOpt09_t1::elem_t* _elem1 = _elem0 + 1;
		sum += _elem0->value;
		sum += _elem1->value;
	}
	return sum;
}
//【タイプ１】最適化後４
//※自前ループアンローリング×４
int testOpt09_Type1_After4(dataOpt09_t1& data)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); i += 4)
	{
		const dataOpt09_t1::elem_t* _elem0 = &data.elems[i];
		const dataOpt09_t1::elem_t* _elem1 = _elem0 + 1;
		const dataOpt09_t1::elem_t* _elem2 = _elem1 + 1;
		const dataOpt09_t1::elem_t* _elem3 = _elem2 + 1;
		sum += _elem0->value;
		sum += _elem1->value;
		sum += _elem2->value;
		sum += _elem3->value;
	}
	return sum;
}
//【タイプ１】最適化後５
//※自前ループアンローリング×２０
int testOpt09_Type1_After5(dataOpt09_t1& data)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); i += 20)
	{
		const dataOpt09_t1::elem_t* _elem0 = &data.elems[i];
		const dataOpt09_t1::elem_t* _elem1 = _elem0 + 1;
		const dataOpt09_t1::elem_t* _elem2 = _elem1 + 1;
		const dataOpt09_t1::elem_t* _elem3 = _elem2 + 1;
		const dataOpt09_t1::elem_t* _elem4 = _elem3 + 1;
		const dataOpt09_t1::elem_t* _elem5 = _elem4 + 1;
		const dataOpt09_t1::elem_t* _elem6 = _elem5 + 1;
		const dataOpt09_t1::elem_t* _elem7 = _elem6 + 1;
		const dataOpt09_t1::elem_t* _elem8 = _elem7 + 1;
		const dataOpt09_t1::elem_t* _elem9 = _elem8 + 1;
		const dataOpt09_t1::elem_t* _elem10 = _elem9 + 1;
		const dataOpt09_t1::elem_t* _elem11 = _elem10 + 1;
		const dataOpt09_t1::elem_t* _elem12 = _elem11 + 1;
		const dataOpt09_t1::elem_t* _elem13 = _elem12 + 1;
		const dataOpt09_t1::elem_t* _elem14 = _elem13 + 1;
		const dataOpt09_t1::elem_t* _elem15 = _elem14 + 1;
		const dataOpt09_t1::elem_t* _elem16 = _elem15 + 1;
		const dataOpt09_t1::elem_t* _elem17 = _elem16 + 1;
		const dataOpt09_t1::elem_t* _elem18 = _elem17 + 1;
		const dataOpt09_t1::elem_t* _elem19 = _elem18 + 1;
		sum += _elem0->value;
		sum += _elem1->value;
		sum += _elem2->value;
		sum += _elem3->value;
		sum += _elem4->value;
		sum += _elem5->value;
		sum += _elem6->value;
		sum += _elem7->value;
		sum += _elem8->value;
		sum += _elem9->value;
		sum += _elem10->value;
		sum += _elem11->value;
		sum += _elem12->value;
		sum += _elem13->value;
		sum += _elem14->value;
		sum += _elem15->value;
		sum += _elem16->value;
		sum += _elem17->value;
		sum += _elem18->value;
		sum += _elem19->value;
	}
	return sum;
}
//【タイプ１】【参考】C++11でもっとも簡潔な記述（遅い）
//※C++11 範囲に基づくforループ
int testOpt09_Type1_Appendix(dataOpt09_t1& data)
{
	int sum = 0;
	for (const dataOpt09_t1::elem_t& elem : data.elems)
	{
		sum += elem.value;
	}
	return sum;
}

//【タイプ２】初期化
void initOpt09_t2(dataOpt09_t2& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt09_t2::elem_t::VALUE_RANGE - 1);
	for (auto& elem : data.elems)
	{
		elem.value1 = rnd_dist(rnd_engine);
		elem.value2 = rnd_dist(rnd_engine);
		for(auto& other : elem.others)
			other = rnd_dist(rnd_engine);
	}
}
//【タイプ２】最適化前
//※加算ループ
int testOpt09_Type2_Before(dataOpt09_t2& data)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); ++i)
	{
		sum += (data.elems[i].value2 - data.elems[i].value1);
	}
	return sum;
}
//【タイプ２】最適化後２
//※減算ループ
int testOpt09_Type2_After1(dataOpt09_t2& data)
{
	int sum = 0;
	for (int i = static_cast<int>(extentof(data.elems)) - 1; i >= 0; --i)
	{
		sum += (data.elems[i].value2 - data.elems[i].value1);
	}
	return sum;
}
//【タイプ２】最適化後２
//※ポインタループ展開
int testOpt09_Type2_After2(dataOpt09_t2& data)
{
	int sum = 0;
	const dataOpt09_t2::elem_t* elem_end = data.elems + extentof(data.elems);
	for (const dataOpt09_t2::elem_t* elem = data.elems; elem < elem_end; ++elem)
	{
		sum += (elem->value2 - elem->value1);
	}
	return sum;
}
//【タイプ２】最適化後３
//※自前ループアンローリング×２
int testOpt09_Type2_After3(dataOpt09_t2& data)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); i += 2)
	{
		const dataOpt09_t2::elem_t* _elem0 = &data.elems[i];
		const dataOpt09_t2::elem_t* _elem1 = _elem0 + 1;
		sum += (_elem0->value2 - _elem0->value1);
		sum += (_elem1->value2 - _elem1->value1);
	}
	return sum;
}
//【タイプ２】最適化後４
//※自前ループアンローリング×４
int testOpt09_Type2_After4(dataOpt09_t2& data)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); i += 4)
	{
		const dataOpt09_t2::elem_t* _elem0 = &data.elems[i];
		const dataOpt09_t2::elem_t* _elem1 = _elem0 + 1;
		const dataOpt09_t2::elem_t* _elem2 = _elem1 + 1;
		const dataOpt09_t2::elem_t* _elem3 = _elem2 + 1;
		sum += (_elem0->value2 - _elem0->value1);
		sum += (_elem1->value2 - _elem1->value1);
		sum += (_elem2->value2 - _elem2->value1);
		sum += (_elem3->value2 - _elem3->value1);
	}
	return sum;
}
//【タイプ２】最適化後５
//※自前ループアンローリング×２０
int testOpt09_Type2_After5(dataOpt09_t2& data)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); i += 20)
	{
		const dataOpt09_t2::elem_t* _elem0 = &data.elems[i];
		const dataOpt09_t2::elem_t* _elem1 = _elem0 + 1;
		const dataOpt09_t2::elem_t* _elem2 = _elem1 + 1;
		const dataOpt09_t2::elem_t* _elem3 = _elem2 + 1;
		const dataOpt09_t2::elem_t* _elem4 = _elem3 + 1;
		const dataOpt09_t2::elem_t* _elem5 = _elem4 + 1;
		const dataOpt09_t2::elem_t* _elem6 = _elem5 + 1;
		const dataOpt09_t2::elem_t* _elem7 = _elem6 + 1;
		const dataOpt09_t2::elem_t* _elem8 = _elem7 + 1;
		const dataOpt09_t2::elem_t* _elem9 = _elem8 + 1;
		const dataOpt09_t2::elem_t* _elem10 = _elem9 + 1;
		const dataOpt09_t2::elem_t* _elem11 = _elem10 + 1;
		const dataOpt09_t2::elem_t* _elem12 = _elem11 + 1;
		const dataOpt09_t2::elem_t* _elem13 = _elem12 + 1;
		const dataOpt09_t2::elem_t* _elem14 = _elem13 + 1;
		const dataOpt09_t2::elem_t* _elem15 = _elem14 + 1;
		const dataOpt09_t2::elem_t* _elem16 = _elem15 + 1;
		const dataOpt09_t2::elem_t* _elem17 = _elem16 + 1;
		const dataOpt09_t2::elem_t* _elem18 = _elem17 + 1;
		const dataOpt09_t2::elem_t* _elem19 = _elem18 + 1;
		sum += (_elem0->value2 - _elem0->value1);
		sum += (_elem1->value2 - _elem1->value1);
		sum += (_elem2->value2 - _elem2->value1);
		sum += (_elem3->value2 - _elem3->value1);
		sum += (_elem4->value2 - _elem4->value1);
		sum += (_elem5->value2 - _elem5->value1);
		sum += (_elem6->value2 - _elem6->value1);
		sum += (_elem7->value2 - _elem7->value1);
		sum += (_elem8->value2 - _elem8->value1);
		sum += (_elem9->value2 - _elem9->value1);
		sum += (_elem10->value2 - _elem10->value1);
		sum += (_elem11->value2 - _elem11->value1);
		sum += (_elem12->value2 - _elem12->value1);
		sum += (_elem13->value2 - _elem13->value1);
		sum += (_elem14->value2 - _elem14->value1);
		sum += (_elem15->value2 - _elem15->value1);
		sum += (_elem16->value2 - _elem16->value1);
		sum += (_elem17->value2 - _elem17->value1);
		sum += (_elem18->value2 - _elem18->value1);
		sum += (_elem19->value2 - _elem19->value1);
	}
	return sum;
}
//【タイプ２】最適化後６
//※自前ループアンローリング×４をSIMD演算
#include <xmmintrin.h>//SSE1用
int testOpt09_Type2_After6(dataOpt09_t2& data)
{
	__m128i sum = _mm_setzero_si128();
	for (int i = 0; i < static_cast<int>(extentof(data.elems)); i += 4)
	{
		const dataOpt09_t2::elem_t* _elem0 = &data.elems[i];
		const dataOpt09_t2::elem_t* _elem1 = _elem0 + 1;
		const dataOpt09_t2::elem_t* _elem2 = _elem1 + 1;
		const dataOpt09_t2::elem_t* _elem3 = _elem2 + 1;
		const __m128i _sub = _mm_sub_epi32(_mm_set_epi32(_elem0->value2, _elem1->value2, _elem2->value2, _elem3->value2),
		                                   _mm_set_epi32(_elem0->value1, _elem1->value1, _elem2->value1, _elem3->value1));
		sum = _mm_add_epi32(sum, _sub);
	}
	sum = _mm_add_epi32(sum, _mm_srli_si128(sum, 8));
	sum = _mm_add_epi32(sum, _mm_srli_si128(sum, 4));
	return *reinterpret_cast<int*>(&sum);
}
//【タイプ２】【参考】C++11でもっとも簡潔な記述（遅い）
//※C++11 範囲に基づくforループ
int testOpt09_Type2_Appendix(dataOpt09_t2& data)
{
	int sum = 0;
	for (const dataOpt09_t2::elem_t& elem : data.elems)
	{
		sum += (elem.value2 - elem.value1);
	}
	return sum;
}

//【タイプ３】最適化前
//※加算ループ
int testOpt09_Type3_Before(dataOpt09_t2::elem_t* elems, const std::size_t num)
{
	int sum = 0;
	for (int i = 0; i < static_cast<int>(num); ++i)
	{
		sum += (elems[i].value2 - elems[i].value1);
	}
	return sum;
}
//【タイプ３】最適化後３
//※減算ループ
int testOpt09_Type3_After1(dataOpt09_t2::elem_t* elems, const std::size_t num)
{
	int sum = 0;
	for (int i = static_cast<int>(num) - 1; i >= 0; --i)
	{
		sum += (elems[i].value2 - elems[i].value1);
	}
	return sum;
}
//【タイプ３】最適化後３
//※ポインタループ展開
int testOpt09_Type3_After2(dataOpt09_t2::elem_t* elems, const std::size_t num)
{
	int sum = 0;
	const dataOpt09_t2::elem_t* elem = elems;
	for (int i = static_cast<int>(num) - 1; i >= 0; --i, ++elem)
	{
		sum += (elem->value2 - elem->value1);
	}
	return sum;
}
//【タイプ３】最適化後３
//※自前ループアンローリング×３
int testOpt09_Type3_After3(dataOpt09_t2::elem_t* elems, const std::size_t num)
{
	int sum = 0;
	const dataOpt09_t2::elem_t* elem = elems;
	for (int i = static_cast<int>(num)-1; i >= 0; i -= 2, elem += 2)
	{
		const dataOpt09_t2::elem_t* _elem0 = elem;
		const dataOpt09_t2::elem_t* _elem1 = _elem0 + 1;
		sum += (_elem0->value2 - _elem0->value1);
		sum += (_elem1->value2 - _elem1->value1);
	}
	return sum;
}
//【タイプ３】最適化後４
//※自前ループアンローリング×４
int testOpt09_Type3_After4(dataOpt09_t2::elem_t* elems, const std::size_t num)
{
	int sum = 0;
	const dataOpt09_t2::elem_t* elem = elems;
	for (int i = static_cast<int>(num)-1; i >= 0; i -= 4, elem += 4)
	{
		const dataOpt09_t2::elem_t* _elem0 = elem;
		const dataOpt09_t2::elem_t* _elem1 = _elem0 + 1;
		const dataOpt09_t2::elem_t* _elem2 = _elem1 + 1;
		const dataOpt09_t2::elem_t* _elem3 = _elem2 + 1;
		sum += (_elem0->value2 - _elem0->value1);
		sum += (_elem1->value2 - _elem1->value1);
		sum += (_elem2->value2 - _elem2->value1);
		sum += (_elem3->value2 - _elem3->value1);
	}
	return sum;
}
//【タイプ３】最適化後５
//※自前ループアンローリング×２０
int testOpt09_Type3_After5(dataOpt09_t2::elem_t* elems, const std::size_t num)
{
	int sum = 0;
	const dataOpt09_t2::elem_t* elem = elems;
	for (int i = static_cast<int>(num) - 1; i >= 0; i -= 20, elem += 20)
	{
		const dataOpt09_t2::elem_t* _elem0 = elem;
		const dataOpt09_t2::elem_t* _elem1 = _elem0 + 1;
		const dataOpt09_t2::elem_t* _elem2 = _elem1 + 1;
		const dataOpt09_t2::elem_t* _elem3 = _elem2 + 1;
		const dataOpt09_t2::elem_t* _elem4 = _elem3 + 1;
		const dataOpt09_t2::elem_t* _elem5 = _elem4 + 1;
		const dataOpt09_t2::elem_t* _elem6 = _elem5 + 1;
		const dataOpt09_t2::elem_t* _elem7 = _elem6 + 1;
		const dataOpt09_t2::elem_t* _elem8 = _elem7 + 1;
		const dataOpt09_t2::elem_t* _elem9 = _elem8 + 1;
		const dataOpt09_t2::elem_t* _elem10 = _elem9 + 1;
		const dataOpt09_t2::elem_t* _elem11 = _elem10 + 1;
		const dataOpt09_t2::elem_t* _elem12 = _elem11 + 1;
		const dataOpt09_t2::elem_t* _elem13 = _elem12 + 1;
		const dataOpt09_t2::elem_t* _elem14 = _elem13 + 1;
		const dataOpt09_t2::elem_t* _elem15 = _elem14 + 1;
		const dataOpt09_t2::elem_t* _elem16 = _elem15 + 1;
		const dataOpt09_t2::elem_t* _elem17 = _elem16 + 1;
		const dataOpt09_t2::elem_t* _elem18 = _elem17 + 1;
		const dataOpt09_t2::elem_t* _elem19 = _elem18 + 1;
		sum += (_elem0->value2 - _elem0->value1);
		sum += (_elem1->value2 - _elem1->value1);
		sum += (_elem2->value2 - _elem2->value1);
		sum += (_elem3->value2 - _elem3->value1);
		sum += (_elem4->value2 - _elem4->value1);
		sum += (_elem5->value2 - _elem5->value1);
		sum += (_elem6->value2 - _elem6->value1);
		sum += (_elem7->value2 - _elem7->value1);
		sum += (_elem8->value2 - _elem8->value1);
		sum += (_elem9->value2 - _elem9->value1);
		sum += (_elem10->value2 - _elem10->value1);
		sum += (_elem11->value2 - _elem11->value1);
		sum += (_elem12->value2 - _elem12->value1);
		sum += (_elem13->value2 - _elem13->value1);
		sum += (_elem14->value2 - _elem14->value1);
		sum += (_elem15->value2 - _elem15->value1);
		sum += (_elem16->value2 - _elem16->value1);
		sum += (_elem17->value2 - _elem17->value1);
		sum += (_elem18->value2 - _elem18->value1);
		sum += (_elem19->value2 - _elem19->value1);
	}
	return sum;
}
//【タイプ３】最適化後６
//※自前ループアンローリング×４をSIMD演算
#include <xmmintrin.h>//SSE1用
int testOpt09_Type3_After6(dataOpt09_t2::elem_t* elems, const std::size_t num)
{
	__m128i sum = _mm_setzero_si128();
	const dataOpt09_t2::elem_t* elem = elems;
	for (int i = static_cast<int>(num)-1; i >= 0; i -= 4, elem += 4)
	{
		const dataOpt09_t2::elem_t* _elem0 = elem;
		const dataOpt09_t2::elem_t* _elem1 = _elem0 + 1;
		const dataOpt09_t2::elem_t* _elem2 = _elem1 + 1;
		const dataOpt09_t2::elem_t* _elem3 = _elem2 + 1;
		const __m128i _sub = _mm_sub_epi32(_mm_set_epi32(_elem0->value2, _elem1->value2, _elem2->value2, _elem3->value2),
		                                   _mm_set_epi32(_elem0->value1, _elem1->value1, _elem2->value1, _elem3->value1));
		sum = _mm_add_epi32(sum, _sub);
	}
	sum = _mm_add_epi32(sum, _mm_srli_si128(sum, 8));
	sum = _mm_add_epi32(sum, _mm_srli_si128(sum, 4));
	return *reinterpret_cast<int*>(&sum);
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
