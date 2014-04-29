//--------------------------------------------------------------------------------
//ハッシュテーブルテスト用設定とコンパイラスイッチ
static const int TABLE_SIZE = 20;//テーブルサイズ

#include <stdio.h>
#include <stdlib.h>

//#define FOR_UNIX//UNIX版でコンパイルするときは、このマクロを有効化する
#ifdef FOR_UNIX
#include "../StaticCRC32_unix/constexpr.h"
#else//FOR_UNIX
#include "../../StaticCRC32/StaticCRC32/src/constexpr/constexpr.h"
#endif//FOR_UNIX

#include <bitset>//std::bitset用
#include <cstddef>//srd::size_t用
#include <iterator>//std::iterator用
#include <utility>//std::move用

//--------------------------------------------------------------------------------
//素数計算
//--------------------------------------------------------------------------------

//----------------------------------------
//【ランタイム版】
//----------------------------------------

//----------------------------------------
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
//----------------------------------------
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
//----------------------------------------
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
//----------------------------------------
//【ランタイム版】指定の値と同じか、前の素数を生成
std::size_t makePrimeEqPrev(const std::size_t n)
{
	return isPrime(n) ? n : makePrimePrev(n);
}
//----------------------------------------
//【ランタイム版】指定の値と同じか、次の素数を生成
std::size_t makePrimeEqNext(const std::size_t n)
{
	return isPrime(n) ? n : makePrimeNext(n);
}

//----------------------------------------
//【メタプログラミング版】
//----------------------------------------
//【注意】
// メタプログラミング版では、コンパイラに応じてテンプレートの再帰レベルの限界がある。
// このため、実質 100001 ぐらいまでの素数しか扱えない点に注意。
// 他のテンプレート内で使うと、もっと制約を受ける点にも注意。
// また、コンパイル時間に影響がある点にも注意。
//----------------------------------------

//----------------------------------------
//【メタプログラミング版：共通処理】固定値を返すクラス
template<typename T, T V>
struct _primeMeta_Fixed{//固定値(V)のためのクラス ※演算クラスの結果を得るときと一様の用法（class_name::value）が必要なため
	static const T value = V;
};

//----------------------------------------
//【メタプログラミング版：共通処理】三項演算子代わりに条件判定に基づいて値を返すクラス
template <typename T, bool COND, class TRUE_VALUE, class FALSE_VALUE>
struct _primeMeta_EnalbeIf{
	static const T value = FALSE_VALUE::value;
};
template <typename T, class TRUE_VALUE, class FALSE_VALUE>//※判定結果がtrueの時用の特殊化
struct _primeMeta_EnalbeIf<T, true, TRUE_VALUE, FALSE_VALUE>{
	static const T value = TRUE_VALUE::value;
};

//----------------------------------------
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

//----------------------------------------
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

//----------------------------------------
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
			_makePrimeNextMeta<N + 1>,
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

//----------------------------------------
//【メタプログラミング版】指定の値と同じか、前の素数を生成
template<std::size_t N>
struct makePrimeEqPrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			makePrimePrevMeta<N>
		>::value;
};

//----------------------------------------
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
//　代わりに、文字列キーは自動的にcrc32変換を行い、文字列は保持しない。
//・処理効率化のために、データの削除時は実際に削除せず、
//　削除済みフラグを用いるものとする。
//　※検索処理は、削除済みのデータを検出しても続行する。
//・STL（std::unodered_map）との違いは下記の通り
//    - 固定長配列である。（STLは自動拡張する）
//    - キーと値のペアで扱わない。
//　　- insert/erase時のイテレータに対応しない。
//    - 赤黒木コンテナ（rb_tree）の実装と合わせた構造にしており、
//　　  操作用テンプレート構造体を用いる。
//--------------------------------------------------------------------------------

namespace hash_table
{
	//--------------------
	//ハッシュテーブルデータ操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public hash_table::base_ope_t<派生構造体, キー型, 値型, キーの最小値= 0u, キーの最大値 = 0xffffffffu, 不正なキー = 0xffffffffu>
	//	struct ope_t : public hash_table::ope_t<ope_t, crc32_t, data_t, 500>
	//	{
	//		//キーを取得
	//		inline static key_type getKey(const value_type& value){ return ???; }
	//	};
	template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	struct base_ope_t
	{
		//定数
		static const KEY_TYPE KEY_MIN = _KEY_MIN;//キーの最小値
		static const KEY_TYPE KEY_MAX = _KEY_MAX;//キーの最大値
		static const KEY_TYPE INVALID_KEY = _INVALID_KEY;//不正なキー

		//型
		typedef OPE_TYPE ope_type;//データ操作型
		typedef VALUE_TYPE value_type;//値型
		typedef KEY_TYPE key_type;//キー型

		//メソッド
		static void call_destructor(value_type* obj){ obj->~VALUE_TYPE(); }//デストラクタ呼び出し
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
	typedef std::size_t index_type;
	//----------------------------------------
	//デバッグ用補助関数
#ifdef DEBUG_PRINT_FOR_ADD
	template<typename... Tx>
	inline int printf_dbg_add(const char* fmt, Tx... args)
	{
		return printf(fmt, args...);
	}
#else//DEBUG_PRINT_FOR_ADD
	inline int printf_dbg_add(const char* fmt, ...){ return 0; }
#endif//DEBUG_PRINT_FOR_ADD
#ifdef DEBUG_PRINT_FOR_REMOVE
	template<typename... Tx>
	inline int printf_dbg_remove(const char* fmt, Tx... args)
	{
		return printf(fmt, args...);
	}
#else//DEBUG_PRINT_FOR_REMOVE
	inline int printf_dbg_remove(const char* fmt, ...){ return 0; }
#endif//DEBUG_PRINT_FOR_REMOVE

	//----------------------------------------
	//ハッシュテーブルコンテナ
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _INDEX_STEP_BASE = 5>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//定数
		static const size_type ORIGINAL_TABLE_SIZE = _TABLE_SIZE;//テーブルサイズ（元々指定されたサイズ）
		static const size_type TABLE_SIZE = makePrimeEqNextMeta<ORIGINAL_TABLE_SIZE>::value;//テーブルサイズ（指定サイズと同じか、それより大きい素数）
		static const size_type TABLE_SIZE_OVERED = TABLE_SIZE - ORIGINAL_TABLE_SIZE;//指定サイズからオーバーしたサイズ
		static const key_type KEY_MIN = ope_type::KEY_MIN;//キーの最小値
		static const key_type KEY_MAX = ope_type::KEY_MAX;//キーの最大値
		static const index_type INDEX_STEP_BASE = _INDEX_STEP_BASE;//インデックスの歩幅の基準値 ※必ず素数でなければならない
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
		static_assert(isPrimeMeta<INDEX_STEP_BASE>::value == true, "hash_table::container: INDEX_STEP_BASE is required prime.");
	public:
		//--------------------
		//イテレータ
		class iterator;
		typedef const iterator const_iterator;
		class iterator : public std::iterator<std::forward_iterator_tag, value_type>
		{
			friend class container;
		public:
			//型
			struct set
			{
				//フィールド
				index_type index;//インデックス
				key_type key;//現在のキー
				value_type* value;//現在の値
				bool is_deleted;//削除済み
				
				//オペレータ
				inline const value_type& operator*() const { return value; }
				inline value_type& operator*(){ return value; }
				inline const value_type* operator->() const { return value; }
				inline value_type* operator->(){ return value; }

				//メソッド
				void update(const index_type _index, const key_type _key, const value_type* _value, const bool _is_deleted)
				{
					index = _index;
					key = _key;
					value = const_cast<value_type*>(_value);
					is_deleted = _is_deleted;
				}

				//コストラクタ
				set(const index_type _index, const key_type _key, const value_type* _value, const bool _is_deleted):
					index(_index),
					key(_key),
					value(const_cast<value_type*>(_value)),
					is_deleted(_is_deleted)
				{}
			};
		public:
			//キャストオペレータ
			inline operator const set() const { return *m_set; }
			inline operator set&(){ return *m_set; }
			inline operator const value_type() const { return *m_set.value; }
			inline operator value_type&(){ return *m_set.value; }
			inline operator key_type() const { return m_set.key; }
		public:
			//オペレータ
			inline const set& operator*() const { return m_set; }
			inline set& operator*(){ return m_set; }
			inline const value_type* operator->() const { return m_set.value; }
			inline value_type* operator->(){ return m_set.value; }
			//比較オペレータ
			inline bool operator==(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX && rhs.m_set.index == INVALID_INDEX ? true :
				       m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index == rhs.m_set.index;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX && rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? true :
				       m_set.index != rhs.m_set.index;
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index > rhs.m_set.index;
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index >= rhs.m_set.index;
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index < rhs.m_set.index;
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index <= rhs.m_set.index;
			}
			//演算オペレータ
			inline const_iterator& operator++() const
			{
				setSet(m_con.getNextIndex(m_set.index));
				return *this;
			}
			inline const_iterator& operator--() const
			{
				setSet(m_con.getPrevIndex(m_set.index));
				return *this;
			}
			inline iterator& operator++()
			{
				setSet(m_con.getNextIndex(m_set.index));
				return *this;
			}
			inline iterator& operator--()
			{
				setSet(m_con.getPrevIndex(m_set.index));
				return *this;
			}
			const_iterator operator++(int) const
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			const_iterator& operator+=(const int val) const
			{
				for (int i = 0; i < val; ++i)
					++(*this);
				return *this;
			}
			const_iterator& operator-=(const int val) const
			{
				for (int i = 0; i < val; ++i)
					--(*this);
				return *this;
			}
			iterator& operator+=(const int val)
			{
				for (int i = 0; i < val; ++i)
					++(*this);
				return *this;
			}
			iterator& operator-=(const int val)
			{
				for (int i = 0; i < val; ++i)
					--(*this);
				return *this;
			}
			const_iterator operator+(const int val) const
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			const_iterator operator-(const int val) const
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
			iterator operator+(const int val)
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			iterator operator-(const int val)
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
		public:
			//ムーブオペレータ
			iterator& operator=(const_iterator&& rhs)
			{
				m_set = rhs.m_set;
				return *this;
			}
			//コピーオペレータ
			inline iterator& operator=(const_iterator& rhs)
			{
				return operator=(std::move(rhs));
			}
		private:
			//メソッド
			void setSet(const index_type index) const
			{
				if (index == INVALID_INDEX)
					m_set.update(INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
				else
					m_set.update(index, m_con.m_keyTable[index], reinterpret_cast<const value_type*>(m_con.m_table[index]), m_con.m_deleted[index]);
			}
		public:
			//ムーブコンストラクタ
			iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_set(obj.m_set)
			{}
			//コピーコンストラクタ
			inline iterator(const_iterator& obj) :
				iterator(std::move(obj))
			{}
			//コンストラクタ
			iterator(const container& con) :
				m_con(con),
				m_set(0, nullptr, false)
			{}
			iterator(const container& con, const index_type index, const key_type key, const value_type* value, const bool is_deleted) :
				m_con(con),
				m_set(index, key, value, is_deleted)
			{}
			//デストラクタ
			inline ~iterator()
			{}
		protected:
			//フィールド
			const container& m_con;//コンテナ
			mutable set m_set;//現在のキー/値/削除済みフラグ
		};
	public:
		//アクセッサ
		inline size_type getOriginalTableSize() const { return ORIGINAL_TABLE_SIZE; }//指定されたテーブルサイズを取得
		inline size_type getTableSize() const { return TABLE_SIZE; }//（実際の）テーブルサイズを取得
		inline size_type getTableSizeOvered() const { return TABLE_SIZE_OVERED; }//指定のテーブルサイズからの増分を取得
		inline key_type getKeyMin() const { return KEY_MIN; }//キーの最小値を取得
		inline key_type getKeyMax() const { return KEY_MAX; }//キーの最大値を取得
		inline key_type getKeyRange() const { return KEY_RANGE; }//キーの範囲を取得
		inline int getUsingCount() const { return m_usingCount; }//使用中データ数を取得
		inline int getDeletedCount() const { return m_deletedCount; }//削除済みデータ数を取得
		inline int getMaxFindCycle() const { return m_maxFindCycle; }//検索時の最大巡回回数を取得
		value_type& at(const key_type key){ return *findValue(key); }
		value_type& at(const char* key){ return *findValue(key); }
		value_type& at(const value_type& value){ return *findValue(value); }
		const value_type& at(const key_type key) const { return *findValue(key); }
		const value_type& at(const char* key) const { return *findValue(key); }
		const value_type& at(const value_type& value) const { return *findValue(value); }
		value_type& operator[](const key_type key){ return *findValue(key); }
		value_type& operator[](const char* key){ return *findValue(key); }
		value_type& operator[](const value_type& value){ return *findValue(value); }
		const value_type& operator[](const key_type key) const { return *findValue(key); }
		const value_type& operator[](const char* key) const { return *findValue(key); }
		const value_type& operator[](const value_type& value) const { return *findValue(value); }
	public:
		//メソッド
		inline index_type calcIndexStep(const key_type key) const { return INDEX_STEP_BASE - key % INDEX_STEP_BASE; }//キーからインデックスの歩幅を計算
		inline index_type calcIndex(const key_type key) const { return calcIndexImpl<(TABLE_SIZE >= KEY_RANGE && KEY_RANGE > 0), size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE >::calc(key); }//キーからインデックスを計算
		inline index_type calcNextIndex(const key_type key, const index_type index) const { return (index + calcIndexStep(key)) % TABLE_SIZE; }//次のインデックスを計算
		std::size_t max_size() const { return TABLE_SIZE; }//最大要素数を取得
		std::size_t capacity() const { return TABLE_SIZE; }//最大要素数を取得
		std::size_t size() const { return m_usingCount - m_deletedCount; }//使用中の要素数を取得
		bool empty() const { return size() == 0; }//空か？
		void clear()//クリア
		{
			m_using.reset();
			m_deleted.reset();
			m_usingCount = 0;
			m_deletedCount = 0;
			m_maxFindCycle = 0;
		}
		//インデックスを取得
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
		//インデックスを検索
		index_type findIndex(const key_type key) const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			const index_type index_first = calcIndex(key);
			index_type index = index_first;
			do
			{
				if (!m_using[index])
					break;
				if (!m_deleted[index] && m_keyTable[index] == key)
					return index;
				index = calcNextIndex(key, index);
			} while (index != index_first);
			return INVALID_INDEX;
		}
		inline index_type findIndex(const char* key){ return findIndex(calcCRC32(key)); }
		inline index_type findIndex(const value_type& value){ return findIndex(ope_type::getKey(value)); }
		//値を検索
		value_type* findValue(const key_type key) const
		{
			const index_type index = findIndex(key);
			if (index == INVALID_INDEX)
				return nullptr;
			return &m_table[index];
		}
		inline value_type* findValue(const char* key){ return findValue(calcCRC32(key)); }
		inline value_type* findValue(const value_type& value){ return findValue(ope_type::getKey(value)); }
		//検索 ※イテレータを返す
		inline const_iterator begin() const
		{
			const index_type index = getFirstIndex();
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, index, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator end() const
		{
			return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
		}
		inline iterator begin(){ return const_cast<const container*>(this)->begin(); }
		inline iterator end(){ return const_cast<const container*>(this)->end(); }
		inline const_iterator cbegin() const { return this->begin(); }
		inline const_iterator cend() const { return this->end(); }
		const_iterator find(const key_type key) const
		{
			const index_type index = findIndex(key);
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator find(const char* key) const { return find(calcCRC32(key)); }
		const_iterator find(const value_type& value) const { return find(ope_type::getKey(value)); }
		iterator find(const key_type key){ return const_cast<const container*>(this)->find(key); }
		iterator find(const char* key){ return const_cast<const container*>(this)->find(key); }
		iterator find(const value_type value){ return const_cast<const container*>(this)->find(value); }
		//キー割り当て
		//※値の領域の先頭ポインタを返す
		value_type* assign(const key_type key)
		{
			if (m_usingCount == TABLE_SIZE && m_deletedCount == 0)
				return nullptr;
			int find_cycle = 0;
			const index_type index_first = calcIndex(key);
			index_type index = index_first;
			do
			{
				++find_cycle;
				if (!m_using[index] || m_deleted[index])
					break;
				if (m_keyTable[index] == key)
					return nullptr;
				index = calcNextIndex(key, index);
			} while (index != index_first);
			m_keyTable[index] = key;
			++m_usingCount;
			m_using[index] = true;
			if (m_deleted[index])
				--m_deletedCount;
			m_deleted[index] = false;
			m_maxFindCycle = m_maxFindCycle >= find_cycle ? m_maxFindCycle : find_cycle;
			return reinterpret_cast<value_type*>(&m_table[index]);
		}
		inline value_type* assign(const char* key){ return assign(calcCRC32(key)); }
		inline value_type* assign(const value_type& value){ return assign(ope_type::getKey(value)); }
		//キー割り当てして値を挿入（コピー）
		value_type* insert(const key_type key, const value_type& value)
		{
			value_type* assigned_value = assign(key);
			if (!assigned_value)
				return nullptr;
			*assigned_value = value;
			return assigned_value;
		}
		inline value_type* insert(const char* key, const value_type& value){ return insert(calcCRC32(key), value); }
		inline value_type* insert(const value_type& value){ return insert(ope_type::getKey(value), value); }
		//キー割り当てして値を初期化
		template<typename... Tx>
		value_type* emplace(const key_type key, const Tx&... args)
		{
			value_type* assigned_value = assign(key);
			if (!assigned_value)
				return nullptr;
			assigned_value = new(assigned_value) value_type(args...);
			return assigned_value;
		}
		template<typename... Tx>
		inline value_type* emplace(const char* key, const Tx&... args){ return emplace(calcCRC32(key), args...); }
		template<typename... Tx>
		value_type* emplaceAuto(const Tx&... args)
		{
			value_type value(args...);
			return insert(value);
		}
		//キーを削除
		bool erase(const key_type key)
		{
			const index_type index = findIndex(key);
			if (index == INVALID_INDEX)
				return false;
			value_type* data_p = reinterpret_cast<value_type*>(&m_table[index]);
			ope_type::call_destructor(data_p);
			operator delete(data_p, data_p);
			m_deleted[index] = true;
			--m_usingCount;
			++m_deletedCount;
			return true;
		}
		bool erase(const char* key){ return erase(calcCRC32(key)); }
	public:
		//コンストラクタ
		container() :
			m_using(),
			m_deleted(),
			m_usingCount(0),
			m_deletedCount(0),
			m_maxFindCycle(0)
		{}
		//デストラクタ
		~container()
		{}
	private:
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//データテーブル
		key_type m_keyTable[TABLE_SIZE];//キーテーブル
		std::bitset<TABLE_SIZE> m_using;//キー設定済みフラグ ※登録を削除してもfalseにならない
		std::bitset<TABLE_SIZE> m_deleted;//削除済みフラグ
		int m_usingCount;//使用中データ数 ※登録を削除しても減らない
		int m_deletedCount;//削除済みデータ数
		int m_maxFindCycle;//検索時の最大巡回回数 ※登録を削除しても減らない
	};
}//namespace hash_table

//--------------------------------------------------------------------------------
//テスト

//【ランタイム版】素数表示
void printPrime(const std::size_t min, const std::size_t max)
{
	if (max > min)
		printPrime(min, max - 1);
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", max, isPrime(max) ? "PRIME.    " : "not prime.", makePrimePrev(max), makePrimeEqPrev(max), makePrimeNext(max), makePrimeEqNext(max));
}

//【メタプログラミング版】素数表示
template<std::size_t N>
void _printPrimeCommon()
{
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", N, isPrimeMeta<N>::value ? "PRIME.    " : "not prime.", makePrimePrevMeta<N>::value, makePrimeEqPrevMeta<N>::value, makePrimeNextMeta<N>::value, makePrimeEqNextMeta<N>::value);
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

//--------------------------------------------------------------------------------
//ハッシュテーブルテスト

//----------------------------------------
//テストデータ
struct data_t
{
	crc32_t m_nameHash;//名前のハッシュ値
	const char* m_name;//名前
	int m_value;//値

	//コンストラクタ
	data_t(const char* name, const int value) :
		m_nameHash(calcCRC32(name)),
		m_name(name),
		m_value(value)
	{
		printf("contructor: data_t [%s]\n", m_name);
	}
	//デストラクタ
	~data_t()
	{
		printf("destructor: ~data_t [%s]\n", m_name);
	}
};
static const std::size_t TEST_DATA_TABLE_SIZE = 10;
//----------------------------------------
//テストデータ操作クラス
struct ope_t : public hash_table::base_ope_t<ope_t, crc32_t, data_t>
{
	//キーを取得
	inline static key_type getKey(const value_type& value){ return value.m_nameHash; }
};

//----------------------------------------
//メイン
int main(const int argc, const char* argv[])
{
#if 0
	//素数コンパイル時計算の再帰レベル限界チェック
	static const std::size_t x = 9999;
	printf("x=%d\n", x);
	printf("  isPrime=%s\n", isPrimeMeta<x>::value ? "true" : "False");
	printf("  prev=%d\n", makePrimePrevMeta<x>::value);
	printf("  next=%d\n", makePrimeNextMeta<x>::value);
	printf("  equalPrev=%d\n", makePrimeEqPrevMeta<x>::value);
	printf("  equalNext=%d\n", makePrimeEqNextMeta<x>::value);
#endif
#if 0
	//素数計算のテスト
	static const std::size_t MIN = 1020;
	static const std::size_t MAX = 1030;
	
	printf("----- Check and Make Prime for Runtime -----\n");
	printPrime(MIN, MAX);
	
	printf("----- Check and Make Prime for Meta-Programming -----\n");
	printPrimeMeta<MIN, MAX>()();
#endif
	
	//ハッシュテーブルのテスト
	printf("----- Hash Table -----\n");
	hash_table::container<ope_t, TABLE_SIZE> table;
	printf("hash_table:\n");
	printf(".getOriginalTableSize()=%u\n", table.getOriginalTableSize());
	printf(".getTableSize()=%u\n", table.getTableSize());
	printf(".getTableSizeOvered()=%u\n", table.getTableSizeOvered());
	printf(".getKeyMin()=%u\n", table.getKeyMin());
	printf(".getKeyMax()=%u\n", table.getKeyMax());
	printf(".getKeyRange()=%u\n", table.getKeyRange());
	
#if 0
	//ハッシュテーブルのインデックス計算ロジックテスト
	//※全てのインデックスが、正確にテーブルサイズ（素数）回の再計算を行う事で、元のインデックスに戻ることを確認。
	int ng_count = 0;
	for (crc32_t key = table.getKeyMin(); key < table.getKeyMax(); ++key)//'<='で判定すると無限ループになるので'<'で判定
	{
		if (key % (1024 * 1024) == 0)
			printf("pass ... Key:%d\n", key);
		std::size_t count = 0;
		std::size_t first_index = table.calcIndex(key);
		std::size_t index = first_index;
		do
		{
			index = table.calcNextIndex(key, index);
			++count;
		} while (index != first_index && count < table.getTableSize());
		if (count != table.getTableSize())
		{
			printf("%u is OUT! (count=%d)\n", key, count);
			++ng_count;
		}
	}
	printf("Chek Hash Table: NG=%d/%d\n", ng_count, table.getTableSize());
	for (std::size_t key = 10; key <= 30; key += 1)
	{
		printf("Key:%u -> Index;%u\n", key, table.calcIndex(key));
	}
#endif
#if 1
	//ハッシュテーブルテスト
	data_t* result;
	result = table.emplace(110, "123", 123);
	result = table.emplace(220, "456", 456);
	result = table.emplace(330, "789", 789);
	result = table.emplace(110, "123", 123);
	table.erase(220);
	table.erase(330);
	result = table.emplace(220, "456!", 4567);
	result = table.emplace("123", "123!!", 12345);
	result = table.emplaceAuto("456!!", 45679);
	result = table.emplace("789", "789!!", 78901);
	for (auto& o : table)
	{
		printf("index=%d, key=%08x, name=%s, value=%d, is_deleted=%s\n", o.index, o.key, o->m_name, o->m_value, o.is_deleted ? "TRUE" : "false");
	}
	printf(".size()=%d\n", table.size());
	printf(".getUsingCount()=%d\n", table.getUsingCount());
	printf(".getDeletedCount()=%d\n", table.getDeletedCount());
	printf(".getMaxFindCycle()=%d\n", table.getMaxFindCycle());
#endif
	return EXIT_SUCCESS;
}

// End of file
