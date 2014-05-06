//--------------------------------------------------------------------------------
//二分ヒープテスト用設定とコンパイラスイッチ
static const int TEST_DATA_PRIOR_MIN = 1;//テストデータの最小プライオリティ
static const int TEST_DATA_PRIOR_MAX = 5;//テストデータの最大プライオリティ
static const int TEST_DATA_MAX = 128;//テストデータの最大登録可能数
static const int TEST_DATA_REG_NUM = 60;//テストデータの登録数

#define PRINT_TEST_DATA_DETAIL//テストデーの詳細タを表示する場合は、このマクロを有効化する
//#define TEST_DATA_WATCH_CONSTRUCTOR//コンストラクタ／デストラクタ／代入演算子の動作を確認する場合、このマクロを有効化する

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------
//共通処理
//--------------------------------------------------------------------------------

#include <type_traits>//C++11 std::is_class, std::conditional用
#include <utility>//C++11 std::move用

//----------------------------------------
//データの入れ替え
template<class T>
struct _swapArithmetic{
	inline static void exec(T& val1, T& val2)
	{
		T tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapArithmetic<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		T* tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapObjects{
	inline static void exec(T& val1, T& val2)
	{
#if 1//ムーブオペレータを使用して入れ替え（#include <utility> の std::swap() と同じ）
		T tmp = std::move(std::move(val2));
		val2 = std::move(val1);
		val1 = std::move(tmp);
#else//コンストラクタ／オペレータの呼び出しを避けて単純なメモリコピー
		char tmp[sizeof(T)];
		memcpy(tmp, &val2, sizeof(T));
		memcpy(&val2, &val1, sizeof(T));
		memcpy(&val1, tmp, sizeof(T));
#endif
	}
};
template<class T>
struct _swapObjects<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		_swapArithmetic<T*>::exec(val1, val2);
	}
};
template<class T>
inline void swapValues(T& val1, T& val2)
{
	std::conditional<std::is_arithmetic<T>::value,
		_swapArithmetic<T>,
		_swapObjects<T>
	>::type::exec(val1, val2);
}

//--------------------------------------------------------------------------------
//二分ヒープ
//--------------------------------------------------------------------------------
//データ構造とアルゴリズム
//【特徴】
//・二分木である。
//	  - ノードの子（左右両方）には、自身よりキーが小さいノードを連結。
//	  - 兄弟ノード間のキーの大小は不定。
//・平衡木である。
//	  - 木のバランスは常に保たれる。
//・以上の特徴により、最もキーが大きいノードの探索時間が、常にO(1)に保たれる。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【本プログラムにおける実装要件】
//・固定配列で実装し、一切メモリ確保・削除をしない。
//・ノード連結のポインタを使用しない。
//　一般的な二分ヒープと同じく、配列の順序に基づいて連結する。
//・コンテナには対応するが、イテレータには対応しない。
//　ただし、配列のポインタをそのまま返すだけの begin(), end() 関数は実装する。
//・この二分ヒープをプライオリティキューに利用した場合、
//　デキュー（pop）時に、エンキュー（push）の順序性は保証されない。
//　※この挙動はSTLと同じ。
//・ただし、（二分ヒープを内包する）プライオリティキューでは、キーの比較に
//　プライオリティとシーケンス番号を併用することで、順序性を保証する。
//・STL（std::priority_queue）との違いは下記の通り
//    - 固定長配列である。（STLは内部にstd::vectorを使用しており、自動拡張する）
//    - 赤黒木コンテナ（rb_tree）の実装と合わせた構造にしており、
//　　  操作用テンプレート構造体を用いる。
//　　  ※STLで使用する比較用の関数オブジェクトクラス(less)は用いない。
//　　- C++11の「範囲に基づくforループ」と、STLの「std::for_each()」が使用可能。
//　　  単純に配列の内容を列挙する。
//    - 効率化のために、オブジェクトのコピーを伴う操作を、
//      明示的なメソッド（pushCoping/ popCoping）にしている。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【具体的な活用の想定】
//・任意の構造のプライオリティキューに適用。
//--------------------------------------------------------------------------------

#include <cstddef>//std::size_t用

namespace bin_heap
{
	//--------------------
	//二分ヒープ操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename NODE_TYPE>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public bin_heap::base_ope_t<派生構造体, ノード型>
	//	struct ope_t : public bin_heap::ope_t<ope_t, data_t>
	//	{
	//		//キーを比較
	//		//※lhsの方が小さいければ true を返す
	//		inline static bool less(const node_type& lhs, const node_type& rhs)
	//		{
	//			return lhs.m_key < rhs.m_key;
	//		}
	//	};
	template<class OPE_TYPE, typename NODE_TYPE>
	struct base_ope_t
	{
		//型
		typedef OPE_TYPE ope_type;//ノード操作型
		typedef NODE_TYPE node_type;//ノード型

		//デストラクタ呼び出し
		static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type;

	//----------------------------------------
	//二分ヒープコンテナ
	//※固定配列と使用中の要素数を持つ
	//※std::priority_queueとはあまり互換性がなく、イテレータにも対応しない
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//定数
		static const std::size_t TABLE_SIZE = _TABLE_SIZE;//配列要素数
		enum state_t//ステート
		{
			IDLE = 0,//アイドル
			PUSH_BEGINNING,//プッシュ開始中
			PUSH_ENDED,//プッシュ終了した
			PUSH_CANCELLED,//プッシュ取り消した
			POP_BEGINNING,//ポップ開始中
			POP_ENDED,//ポップ終了した
			POP_CANCELLED,//ポップ取り消した
		};
	public:
		//アクセッサ
		inline const node_type* at(const int index) const { return ref_node(index); }
		inline node_type* at(const int index){ return ref_node(index); }
		inline const node_type* operator[](const int index) const { return ref_node(index); }
		inline node_type* operator[](const int index){ return ref_node(index); }
		inline state_t state() const { return m_state; }
	public:
		//メソッド
		inline std::size_t max_size() const { return TABLE_SIZE; }//最大要素数を取得
		inline std::size_t capacity() const { return TABLE_SIZE; }//最大要素数を取得
		inline std::size_t size() const { return m_used; }//使用中の要素数を取得
		inline bool empty() const { return m_used == 0; }//空か？
	public:
		int depth_max() const//最大の深さを取得
		{
			if (m_used == 0)
				return -1;
			int depth = 0;
			int used = m_used >> 1;
			while (used != 0)
			{
				++depth;
				used >>= 1;
			}
			return depth;
		}
	private:
		inline const node_type* _ref_node(const int index) const { return reinterpret_cast<const node_type*>(&m_table[index]); }//ノード参照
		inline const node_type* _ref_top() const { return _ref_node(0); }//先頭ノード参照
		inline const node_type* _ref_bottom() const { return _ref_node(m_used - 1); }//終端ノード参照
		inline const node_type* _ref_new() const { return _ref_node(m_used); }//新規ノード参照
		inline node_type* _ref_node(const int index){ return reinterpret_cast<node_type*>(&m_table[index]); }//ノード参照
		inline node_type* _ref_top(){ return _ref_node(0); }//先頭ノード参照
		inline node_type* _ref_bottom(){ return _ref_node(m_used - 1); }//終端ノード参照
		inline node_type* _ref_new(){ return _ref_node(m_used); }//新規ノード参照
	public:
		inline const node_type* ref_node(const int index) const { return index >= 0 && index < static_cast<int>(m_used) ? _ref_node(index) : nullptr; }//ノード参照
		inline const node_type* ref_top() const { return m_used == 0 ? nullptr : _ref_top(); }//先頭ノード参照
		inline const node_type* ref_bottom() const { return m_used == 0 ? nullptr : _ref_bottom(); }//終端ノード参照
		inline const node_type* ref_new() const { return m_used == TABLE_SIZE ? nullptr : _ref_new(); }//新規ノード参照
		inline const node_type* begin() const { return m_used == 0 ? nullptr : _ref_top(); }//開始ノード
		inline const node_type* end() const { return m_used == 0 ? nullptr : _ref_new(); }//終了ノード
		inline node_type* ref_node(const int index){ return  const_cast<node_type*>(const_cast<const container*>(this)->ref_node()); }//ノード参照
		inline node_type* ref_top(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_top()); }//先頭ノード参照
		inline node_type* ref_bottom(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_bottom()); }//終端ノード参照
		inline node_type* ref_new(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_new()); }//新規ノード参照
		inline node_type* begin(){ return const_cast<node_type*>(const_cast<const container*>(this)->begin()); }//開始ノード
		inline node_type* end(){ return const_cast<node_type*>(const_cast<const container*>(this)->end()); }//終了ノード
	private:
		inline int _adj_index(const int index) const { return index >= 0 && index < TABLE_SIZE ? index : -1; }//インデックスを範囲内に補正
		inline int _ref_index(const node_type* node) const{ return node - _ref_top(); }//ノードをインデックスに変換 ※範囲チェックなし
		inline int _calc_parent(const int index) const { return (index - 1) >> 1; }//親インデックス計算 ※範囲チェックなし
		inline int _calc_child_l(const int index) const { return (index << 1) + 1; }//左側の子インデックス計算 ※範囲チェックなし
		inline int _calc_child_r(const int index) const { return _calc_child_l(index) + 1; }//右側の子インデックス計算 ※範囲チェックなし
	public:
		inline int ref_index(const node_type* node) const{ return _adj_index(_ref_index(node)); }//ノードをインデックスに変換
		inline int calc_parent(const int index) const { return _adj_index(_calc_parent(index)); }//親インデックス計算
		inline int calc_child_l(const int index) const { return _adj_index(_calc_child_l(index)); }//左側の子インデックス計算
		inline int calc_child_r(const int index) const { return _adj_index(_calc_child_r(index)); }//右側の子インデックス計算
		inline int calc_child(const int index, const bool is_right) const { return is_right ? calc_child_r(index) : calc_child_l(index); }//子インデックス計算
		inline const node_type* ref_parent(const node_type* node) const { return ref_node(_calc_parent(_ref_index(node))); }//親ノード参照
		inline const node_type* ref_child_l(const node_type* node) const { return ref_node(_calc_child_l(_ref_index(node))); }//左側の子ノード参照
		inline const node_type* ref_child_r(const node_type* node) const { return ref_node(_calc_child_r(_ref_index(node))); }//左側の子ノード参照
		inline const node_type* ref_child(const node_type* node, const bool is_right) const { return is_right ? ref_child_r(node) : ref_child_l(node); }//子ノード参照
		inline node_type* ref_parent(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_parent(index)); }//親ノード参照
		inline node_type* ref_child_l(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child_l(index)); }//左側の子ノード参照
		inline node_type* ref_child_r(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child_r(index)); }//左側の子ノード参照
		inline node_type* ref_child(const int index, const bool is_right){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child(index, is_right)); }//子ノード参照
	public:
		inline bool less(const node_type& lhs, const node_type& rhs) const { return ope_type::less(lhs, rhs); }//キー比較
		//プッシュ
		//※オブジェクト渡し
		//※オブジェクトのコピーが発生する点に注意（少し遅くなる）
		node_type* pushCopying(const node_type& src)
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			*obj = src;
			m_state = PUSH_BEGINNING;
			return pushEnd();
		}
		//プッシュ
		//※パラメータ渡し
		//※オブジェクトのコンストラクタが呼び出される
		template<typename... Tx>
		node_type* push(Tx... args)
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = pushBegin(args...);
			if (!obj)
				return nullptr;
			return pushEnd();
		}
		//プッシュ開始
		//※空きノードを取得し、コンストラクタが呼び出される
		template<typename... Tx>
		node_type* pushBegin(Tx... args)
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			obj = new(obj)node_type(args...);//コンストラクタ呼び出し
			if (obj)
				m_state = PUSH_BEGINNING;
			return obj;
		}
		//プッシュ終了
		//※追加した新規ノードを上に移動
		node_type* pushEnd()
		{
			if (m_state != PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			++m_used;
			m_state = PUSH_ENDED;
			//末端の葉ノードとして登録された新規ノードを上方に移動
			return upHeap(obj);
		}
		//プッシュ取り消し
		bool pushCancel()
		{
			if (m_state != PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return false;
			m_state = PUSH_CANCELLED;
			return true;
		}
		//ポップ
		//※オブジェクトのコピーを受け取る領域を渡す
		//※オブジェクトのデストラクタが呼び出される ※コピー後に実行
		bool popCopying(node_type& dst)
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return false;
			const node_type* obj = popBegin();
			if (!obj)
				return false;
			dst = *obj;
			return popEnd();
		}
		//ポップ開始
		//※根ノード取得
		node_type* popBegin()
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* obj = ref_top();
			if (obj)
				m_state = POP_BEGINNING;
			return obj;
		}
		//ポップ終了
		//※オブジェクトのデストラクタが呼び出される
		//※削除した根ノードの隙間を埋めるために、以降のノードを上に移動
		bool popEnd()
		{
			if (m_state != POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			node_type* obj = ref_bottom();
			if (!obj)
				return false;
			ope_type::callDestructor(obj);//デストラクタ呼び出し
			operator delete(obj, obj);//（作法として）deleteオペレータ呼び出し
			m_state = POP_ENDED;
			//根ノードがポップされたので、末端の葉ノードを根ノードに上書きした上で、それを下方に移動
			node_type* top_obj = _ref_top();
			*top_obj = *obj;
			--m_used;
			downHeap(top_obj);
			return true;
		}
		//ポップ取り消し
		bool popCancel()
		{
			if (m_state != POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			m_state = POP_CANCELLED;
			return true;
		}
		//ノードを上方に移動
		node_type* upHeap(node_type* obj)
		{
			int index = ref_index(obj);
			if (index < 0)
				return nullptr;
			while (index != 0)
			{
				index = _calc_parent(index);
				node_type* parent = _ref_node(index);
				if (less(*parent, *obj))
				{
					swapValues(*parent, *obj);
					obj = parent;
				}
				else
					break;
			}
			return obj;
		}
		//ノードを下方に移動
		node_type* downHeap(node_type* obj)
		{
			int index = ref_index(obj);
			if (index < 0)
				return nullptr;
			while (true)
			{
				index = _calc_child_l(index);
				if (index >= m_used)
					break;
				node_type* child = _ref_node(index);
				node_type* child_r = index + 1 < m_used ? child + 1 : nullptr;
				bool is_swap = false;
				if (child_r && !less(*child_r, *child) && !less(*child_r, *obj))
				{
					is_swap = true;
					child = child_r;
					++index;
				}
				else if (!less(*child, *obj))
				{
					is_swap = true;
				}
				if (is_swap)
					swapValues(*child, *obj);
				else
					break;
				obj = child;
			}
			return obj;
		}
		//クリア
		void clear()
		{
			node_type* obj_end = end();
			for (node_type* obj = begin(); obj < obj_end; ++obj)
			{
				ope_type::callDestructor(obj);//デストラクタ呼び出し
				operator delete(obj, obj);//（作法として）deleteオペレータ呼び出し
			}
			m_used = 0;
		}
	public:
		//コンストラクタ
		//※キー比較処理を渡す
		container() :
			m_used(0),
			m_state(IDLE)
		{}
		//デストラクタ
		~container()
		{
			pushCancel();//プッシュ取り消し
			popCancel();//ポップ取り消し
		}
	private:
		//フィールド
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//データテーブル
		int m_used;//使用数
		state_t m_state;//ステート
	};
	//--------------------
	//安全なプッシュ／ポップ操作クラス
	template<class CON>
	class operation_guard
	{
	public:
		//型
		typedef CON container_type;//コンテナ型
		typedef typename CON::node_type node_type;//ノード型
		typedef typename CON::state_t state_t;//ステート型
	public:
		//アクセッサ
		state_t state() const { return m_state; }//ステートを取得
	public:
		//プッシュ開始
		template<typename... Tx>
		node_type* pushBegin(Tx... args)
		{
			if (m_state == state_t::PUSH_BEGINNING || m_state == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_container.pushBegin(args...);//プッシュ開始
			if (node)
				m_state = state_t::PUSH_BEGINNING;//ステート変更
			return node;
		}
		//プッシュ終了
		node_type* pushEnd()
		{
			if (m_state != state_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			node_type* node = m_container.pushEnd();//プッシュ終了
			m_state = state_t::PUSH_ENDED;//ステート変更
			return node;
		}
		//プッシュ取り消し
		bool pushCancel()
		{
			if (m_state != state_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return false;
			m_container.pushCancel();//プッシュ取り消し
			m_state = state_t::PUSH_CANCELLED;//ステート変更
			return true;
		}
		//ポップ開始
		node_type* popBegin()
		{
			if (m_state == state_t::PUSH_BEGINNING || m_state == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_container.popBegin();//ポップ開始
			if (node)
				m_state = state_t::POP_BEGINNING;//ステート変更
			return node;
		}
		//ポップ終了
		bool popEnd()
		{
			if (m_state != state_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			const bool result = m_container.popEnd();//ポップ終了
			m_state = state_t::POP_ENDED;//ステート変更
			return result;
		}
		//ポップ取り消し
		bool popCancel()
		{
			if (m_state != state_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			m_container.popCancel();//ポップ取り消し
			m_state = state_t::POP_CANCELLED;//ステート変更
			return true;
		}
	public:
		//コンストラクタ
		operation_guard(container_type& container) :
			m_container(container),
			m_state(state_t::IDLE)
		{}
		//デストラクタ
		~operation_guard()
		{
			pushEnd();//プッシュ終了
			popEnd();//ポップ終了
		}
	private:
		//フィールド
		container_type& m_container;//コンテナ
		state_t m_state;//ステート
	};
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace bin_heap

//--------------------------------------------------------------------------------
//プライオリティキュー
//※プライオリティとともに、シーケンス番号を扱うことで、キューイングの順序性を保証する。
//--------------------------------------------------------------------------------

#include <utility>//C++11 std::move用
#include <mutex>//C++11 std::mutex用

namespace priority_queue
{
	//--------------------
	//プライオリティキュー操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename NODE_TYPE, int _NODES_MAX>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public priority_queue::base_ope_t<派生構造体, ノード型, 優先度型, シーケンス番号型>
	//	struct ope_t : public priority_queue::ope_t<ope_t, data_t, int, unsigned int>
	//	{
	//		//優先度を取得
	//		inline static priority_type getPrior(const node_type& node){ return node.m_priority; }
	//		//優先度を更新
	//		inline static void setPrior(node_type& node, const priority_type priority){ node.m_priority = priority; }
	//		
	//		//シーケンス番号を取得
	//		inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//		//シーケンス番号を更新
	//		inline static void setSeqNo(node_type& node, const seq_type seq_no) const { node.m_seqNo = seq_no; }
	//		
	//		//優先度を比較
	//		//Return value:
	//		//  0 ... lhs == rhs
	//		//  1 ... lhs > rhs
	//		// -1 ... lhs < rhs
	//		inline static int compareProior(const priority_type lhs, const priority_type rhs)
	//		{
	//			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
	//		}
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, typename PRIOR_TYPE = int, typename SEQ_TYPE = unsigned int>
	struct base_ope_t
	{
		//型
		typedef OPE_TYPE ope_type;//ノード操作型
		typedef NODE_TYPE node_type;//ノード型
		typedef PRIOR_TYPE priority_type;//優先度型
		typedef SEQ_TYPE seq_type;//シーケンス番号型

		//シーケンス番号を比較
		inline static bool lessSeqNo(const seq_type lhs, const seq_type rhs)
		{
			return lhs > rhs;
		}

		//優先度を比較
		//※デフォルト
		//Return value:
		//  0 ... lhs == rhs
		//  1 ... lhs > rhs
		// -1 ... lhs < rhs
		inline static int comparePriority(const priority_type lhs, const priority_type rhs)
		{
			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
		}

		//キーを比較
		//※lhsの方が小さいければ true を返す
		inline static bool _lessSeqNo(const int compare_priority, const seq_type lhs, const seq_type rhs)
		{
			return compare_priority < 0 ? true : compare_priority > 0 ? false : ope_type::lessSeqNo(lhs, rhs);
		}
		inline static bool less(const node_type& lhs, const node_type& rhs)
		{
			return _lessSeqNo(ope_type::comparePriority(ope_type::getPrior(lhs), ope_type::getPrior(rhs)), ope_type::getSeqNo(lhs), ope_type::getSeqNo(rhs));
		}

		//STLのstd::priority_queueと共用するための関数オブジェクト
		inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return less(lhs, rhs); }

		//デストラクタ呼び出し
		static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef typename ope_type::priority_type priority_type; \
		typedef typename ope_type::seq_type seq_type;

	//----------------------------------------
	//プライオリティキューコンテナ用定数
	enum auto_lock_attr_t : unsigned char//自動ロック属性
	{
		NEVER_LOCK,//ロックしない
		AUTO_LOCK,//自動ロック
	};
	//----------------------------------------
	//プライオリティキューコンテナ
	//※内部に二分ヒープを持つ
	//※std::priority_queueとはあまり互換性がなく、イテレータにも対応しない
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
		typedef bin_heap::container<ope_type, _TABLE_SIZE> bin_heap_type;//二分ヒープ型
		typedef typename bin_heap_type::state_t state_t;//ステート型
	public:
		//アクセッサ
		inline const bin_heap_type& getHeap() const { return m_heap; }//二分ヒープ取得
		inline bin_heap_type& getHeap(){ return m_heap; }//二分ヒープ取得
	public:
		//キャストオペレータ
		inline operator const bin_heap_type() const{ return m_heap; }//二分ヒープを返す
		inline operator bin_heap_type(){ return m_heap; }//二分ヒープを返す
		inline operator std::mutex(){ return m_lock; }//ミューテックスを返す
	public:
		//メソッド
		inline std::size_t max_size() const { return m_heap.max_aize(); }//最大要素数を取得
		inline std::size_t capacity() const { return m_heap.capacity(); }//最大要素数を取得
		inline std::size_t size() const { return m_heap.size(); }//使用中の要素数を取得
		inline bool empty() const { return m_heap.empty(); }//空か？
	public:
		inline const node_type* begin() const { return m_heap.begin(); }//開始ノード
		inline const node_type* end() const { return m_heap.end(); }//終了ノード
		inline node_type* begin(){ return m_heap.begin(); }//開始ノード
		inline node_type* end(){ return m_heap.end(); }//終了ノード
	private:
		//シーケンス番号発行
		inline seq_type getNextSeqNo(){ return m_seqNo++; }
		//可能ならシーケンス番号をリセット
		inline void checkAndResetSeqNo()
		{
			if (m_heap.empty())
				m_seqNo = 0;
		}
	private:
		//エンキュー（本体）
		node_type* _enqueueCopying(const node_type& obj)
		{
			if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type obj_tmp(std::move(obj));
			ope_type::setSeqNo(obj_tmp, getNextSeqNo());//シーケンス番号をセット
			return m_heap.pushCopying(obj_tmp);//二分ヒープにプッシュ
		}
	public:
		//エンキュー
		//※オブジェクト渡し
		//※オブジェクトには、あらかじめ優先度を設定しておく必要がある
		//※オブジェクトのコピーが２回発生する点に注意（少し遅くなる）
		//　（シーケンス番号をセットするために1回テンポラリにコピーし、プッシュ時にさらにコピーする。）
		inline node_type* enqueueCopying(const node_type& obj)
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//関数終了時に自動的にロック解放
				return _enqueueCopying(obj);
			}
			return _enqueueCopying(obj);
		}
	private:
		//エンキュー（本体）
		template<typename... Tx>
		node_type* _enqueue(const priority_type priority, Tx... args)
		{
			//if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_heap.pushBegin(args...);//二分ヒープにプッシュ開始
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//優先度を設定
			ope_type::setSeqNo(*obj, getNextSeqNo());//シーケンス番号をセット
			obj = m_heap.pushEnd();//二分ヒープにプッシュ終了
			return obj;
		}
	public:
		//エンキュー
		//※パラメータ渡し
		//※オブジェクトのコンストラクタが呼び出される
		//※オブジェクトには、シーケンス番号が書き込まれる
		template<typename... Tx>
		inline node_type* enqueue(const priority_type priority, Tx... args)
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//関数終了時に自動的にロック解放
				return _enqueue(priority, args...);
			}
			return _enqueue(priority, args...);
		}
	private:
		//エンキュー開始（本体）
		template<typename... Tx>
		node_type* _enqueueBegin(const priority_type priority, Tx... args)
		{
			//if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_heap.pushBegin(args...);//二分ヒープにプッシュ開始
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//優先度を設定
			ope_type::setSeqNo(*obj, getNextSeqNo());//シーケンス番号を設定
			return obj;
		}
	public:
		//エンキュー開始
		//※空きキュー取得
		//※エンキュー完了時に enqueueEnd を呼び出す必要あり
		//※この時点で、優先度とシーケンス番号が書き込まれる
		template<typename... Tx>
		inline node_type* enqueueBegin(const priority_type priority, Tx... args)
		{
			if (m_autoLockAttr == AUTO_LOCK)
				m_lock.lock();//ロックを取得したまま関数を抜ける
			node_type* obj = _enqueueBegin(args...);//エンキュー開始
			if (!obj && m_autoLockAttr == AUTO_LOCK)
					m_lock.unlock();//プッシュ失敗時はロック解放
			return obj;
		}
	private:
		//エンキュー終了（本体）
		inline node_type* _enqueueEnd()
		{
			return m_heap.pushEnd();//二分ヒープにプッシュ終了
		}
	public:
		//エンキュー終了
		inline node_type* enqueueEnd()
		{
			const bool unlock = (m_autoLockAttr == AUTO_LOCK && m_heap.state() == state_t::PUSH_BEGINNING);//プッシュ開始中ならアンロックする
			node_type* new_obj = _enqueueEnd();//エンキュー終了
			if (unlock)
				m_lock.unlock();//ロック解放
			return new_obj;
		}
	private:
		//エンキュー取り消し（本体）
		inline bool _enqueueCancel()
		{
			//if (m_heap.state() != state_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
			//	return;
			return m_heap.pushCancel();//プッシュ取り消し
		}
	public:
		//エンキュー取り消し
		inline bool enqueueCancel()
		{
			const bool unlock = (m_autoLockAttr == AUTO_LOCK && m_heap.state() == state_t::PUSH_BEGINNING);//プッシュ開始中ならアンロックする
			const bool result = m_heap.pushCancel();//プッシュ取り消し
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	private:
		//デキュー（本体）
		bool _dequeueCopying(node_type& dst)
		{
			//if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			const bool result = m_heap.popCopying(dst);//二分ヒープからポップ
			if (!result)
				return false;
			checkAndResetSeqNo();//キューが空になったらシーケンス番号をリセットする
			return true;
		}
	public:
		//デキュー
		//※オブジェクトのコピーを受け取る領域を渡す
		//※オブジェクトのデストラクタが呼び出される ※コピー後に実行
		inline bool dequeueCopying(node_type& dst)
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//関数終了時に自動的にロック解放
				return _dequeueCopying(dst);
			}
			return _dequeueCopying(dst);
		}
	private:
		//デキュー開始（本体）
		//※デキュー完了時に dequeueEnd を呼び出す必要あり
		node_type* _dequeueBegin()
		{
			//if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
			//	return nullptr;
			node_type* obj = m_heap.popBegin();//二分ヒープからポップ開始
			if (!obj)
				return nullptr;
			return obj;
		}
	public:
		//デキュー開始
		//※デキュー完了時に dequeueEnd を呼び出す必要あり
		inline node_type* dequeueBegin()
		{
			if (m_autoLockAttr == AUTO_LOCK)
				m_lock.lock();//ロックを取得したまま関数を抜ける
			node_type* obj = _dequeueBegin();//デキュー開始
			if (!obj && m_autoLockAttr == AUTO_LOCK)
				m_lock.unlock();//プッシュ失敗時はロック解放
			return obj;
		}
	private:
		//デキュー終了（本体）
		bool _dequeueEnd()
		{
			//if (m_heap.state() != state_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
			//	return false;
			const bool result = m_heap.popEnd();//二分ヒープからポップ終了
			checkAndResetSeqNo();//キューが空になったらシーケンス番号をリセットする
			return result;
		}
	public:
		//デキュー終了
		//※オブジェクトのデストラクタが呼び出される
		inline bool dequeueEnd()
		{
			const bool unlock = (m_autoLockAttr == AUTO_LOCK && m_heap.state() == state_t::POP_BEGINNING);//ポップ開始中ならアンロックする
			const bool result = _dequeueEnd();//デキュー終了
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
	private:
		//デキュー取り消し（本体）
		bool _dequeueCancel()
		{
			//if (m_heap.state() != state_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
			//	return false;
			return m_heap.popCancel();//ポップ取り消し
		}
	public:
		//デキュー取り消し
		inline bool dequeueCancel()
		{
			const bool unlock = (m_autoLockAttr == AUTO_LOCK && m_heap.state() == state_t::POP_BEGINNING);//ポップ開始中ならアンロックする
			const bool result = _dequeueCancel();//デキュー取り消し
			if (unlock)
				m_lock.unlock();//ロック解放
			return result;
		}
		//先頭（根）キューを参照
		//※デキューしない
		inline const node_type* top() const
		{
			return m_heap.ref_top();//二分ヒープの先頭（根）ノードを取得
		}
	private:
		//先頭（根）キューのプライオリティ変更（本体）
		node_type* _changePriorityOnTop(const priority_type priority)
		{
			node_type* obj = m_heap.ref_top();
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//優先度を更新
			ope_type::setSeqNo(*obj, getNextSeqNo());//シーケンス番号を更新
			return m_heap.downHeap(obj);//ダウンヒープ
		}
	public:
		//先頭（根）キューのプライオリティ変更
		//※プライオリティを変更した時点でキューの位置が入れ替わる
		//※シーケンス番号を再更新する
		//※同じプライオリティに変更した場合、同じプライオリティのキューの一番最後に回される
		inline node_type* changePriorityOnTop(const priority_type priority)
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//関数終了時に自動的にロック解放
				return _changePriorityOnTop(priority);
			}
			return _changePriorityOnTop(priority);
		}
	private:
		//クリア（本体）
		inline void _clear()
		{
			m_heap.clear();
		}
	public:
		//クリア
		inline void clear()
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//関数終了時に自動的にロック解放
				_clear();
			}
			_clear();
		}
	public:
		//コンストラクタ
		//※キー比較処理を渡す
		container(const auto_lock_attr_t auto_lock_attr = NEVER_LOCK) :
			m_heap(),
			m_seqNo(0),
			m_autoLockAttr(auto_lock_attr),
			m_lock()
		{}
		//デストラクタ
		~container()
		{
			enqueueCancel();//エンキュー取り消し
			dequeueCancel();//デキュー取り消し
		}
	private:
		//フィールド
		bin_heap_type m_heap;//二分ヒープ
		int m_dummy;
		seq_type m_seqNo;//シーケンス番号 ※mutable修飾子
		auto_lock_attr_t m_autoLockAttr;//属性
		std::mutex m_lock;//ミューテックス
	};
	//--------------------
	//安全なエンキュー／デキュー操作クラス
	template<class CON>
	class operation_guard
	{
	public:
		//型
		typedef CON container_type;//コンテナ型
		typedef typename CON::node_type node_type;//ノード型
		typedef typename CON::state_t state_t;//ステート型
	public:
		//アクセッサ
		state_t state() const { return m_state; }//ステートを取得
	public:
		//エンキュー開始
		template<typename... Tx>
		node_type* enqueueBegin(const typename CON::priority_type priority, Tx... args)
		{
			if (m_state == state_t::PUSH_BEGINNING || m_state == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_container.enqueueBegin(priority, args...);//エンキュー開始
			if (node)
				m_state = state_t::PUSH_BEGINNING;//ステート変更
			return node;
		}
		//エンキュー終了
		node_type* enqueueEnd()
		{
			if (m_state != state_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			node_type* node = m_container.enqueueEnd();//エンキュー終了
			m_state = state_t::PUSH_ENDED;//ステート変更
			return node;
		}
		//エンキュー取り消し
		bool enqueueCancel()
		{
			if (m_state != state_t::PUSH_BEGINNING)//プッシュ開始中以外なら処理しない
				return nullptr;
			m_container.enqueueCancel();//エンキュー取り消し
			m_state = state_t::PUSH_CANCELLED;//ステート変更
			return true;
		}
		//デキュー開始
		node_type* dequeueBegin()
		{
			if (m_state == state_t::PUSH_BEGINNING || m_state == state_t::POP_BEGINNING)//プッシュ／ポップ開始中なら処理しない
				return nullptr;
			node_type* node = m_container.dequeueBegin();//デキュー開始
			if (node)
				m_state = state_t::POP_BEGINNING;//ステート変更
			return node;
		}
		//デキュー終了
		bool dequeueEnd()
		{
			if (m_state != state_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			const bool result = m_container.dequeueEnd();//デキュー終了
			m_state = state_t::POP_ENDED;//ステート変更
			return result;
		}
		//デキュー取り消し
		bool dequeueCancel()
		{
			if (m_state != state_t::POP_BEGINNING)//ポップ開始中以外なら処理しない
				return false;
			m_container.dequeueCancel();//デキュー取り消し
			m_state = state_t::POP_CANCELLED;//ステート変更
			return true;
		}
	public:
		//コンストラクタ
		operation_guard(container_type& container) :
			m_container(container),
			m_state(state_t::IDLE)
		{}
		//デストラクタ
		~operation_guard()
		{
			enqueueEnd();//エンキュー終了
			dequeueEnd();//デキュー終了
		}
	private:
		//フィールド
		container_type& m_container;//コンテナ
		state_t m_state;//ステート
	};
	//--------------------
	//基本型定義マクロ消去
	#undef DECLARE_OPE_TYPES
}//namespace priority_queue

//--------------------------------------------------------------------------------
//プライオリティキューテスト
//--------------------------------------------------------------------------------

#include <memory.h>//memcpy用
#include <random>//C++11 std::random用
#include <algorithm>//std::for_each用
#include <queue>//std::priority_queue用※比較テスト用

//----------------------------------------
//テストデータ
enum PRIORITY : short
{
	HIGHEST = 5,
	HIGHER = 4,
	NORMAL = 3,
	LOWER = 2,
	LOWEST = 1,
};
struct data_t
{
	PRIORITY m_priority;//優先度
	int m_seqNo;//シーケンス番号
	int m_val;//データ

	//コンストラクタ
	data_t(const PRIORITY priority, const int val) :
		m_priority(priority),
		m_seqNo(0),
		m_val(val)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d, %d)\n", priority, val);
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	data_t(const int val) :
		m_priority(NORMAL),
		m_seqNo(0),
		m_val(val)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d)\n", val);
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
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
#endif//TEST_DATA_WATCH_CONSTRUCTOR
	//デフォルトコンストラクタ
	data_t() :
		m_priority(NORMAL),
		m_seqNo(0),
		m_val(0)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor\n");
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	//デストラクタ
	~data_t()
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::destructor\n");
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
};
//----------------------------------------
//テストデータ操作クラス
struct ope_t : public priority_queue::base_ope_t<ope_t, data_t, PRIORITY, int>
{
	//優先度を取得
	inline static priority_type getPrior(const node_type& node){ return node.m_priority; }
	//優先度を更新
	inline static void setPrior(node_type& node, const priority_type priority){ node.m_priority = priority; }
	
	//シーケンス番号を取得
	inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//シーケンス番号を更新
	inline static void setSeqNo(node_type& node, const seq_type seq_no){ node.m_seqNo = seq_no; }
};

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
//テストメイン
int main(const int argc, const char* argv[])
{
	//プライオリティキューコンテナ生成
	typedef priority_queue::container<ope_t, TEST_DATA_MAX> container_type;
	typedef container_type::bin_heap_type bin_heap_type;
	container_type con(priority_queue::AUTO_LOCK);

	//--------------------
	//プライオリティキューのテスト
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)]\n");
	printf("\n");

	//エンキュー
	auto enqueue = [&con]()
	{
		printf("--- Enqueue ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj = con.enqueue(NORMAL, 0);
			printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			#define USE_ENQUEUE_TYPE 2
			//【エンキュー方法①】オブジェクトを受け渡す方法
			//※オブジェクトのコピーが発生するので少し遅い。
			#if USE_ENQUEUE_TYPE == 1
			{
				data_t new_obj(priority, val);
				data_t* obj = con.enqueueCopying(new_obj);
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//【推奨】【エンキュー方法②】コンストラクタパラメータを渡して登録する方法
			//※オブジェクトのコピーは発生しない。
			//※コンストラクタが呼び出される。
			#elif USE_ENQUEUE_TYPE == 2
			{
				data_t* obj = con.enqueue(priority, val);//優先度とコンストラクタパラメータを渡して登録
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//【エンキュー方法③】新規キュー（オブジェクト）の参照を受け取って値をセットする方法
			//※オブジェクトのコピーは発生しない。
			//※最初にコンストラクタが呼び出される。
			//※明示的に終了処理を呼び出し、ロックを解放しなければならない点に注意。
			//　（エンキュー／デキュー操作用クラスを使用することで、処理ブロックを抜ける時に自動敵にロックが解放される）
			//※エンキュー終了時にはポインタが変わる点にも注意。
			#elif USE_ENQUEUE_TYPE == 3
			{
				priority_queue::operation_guard<container_type> ope(con);//エンキュー／デキュー操作用クラス
				data_t* obj = ope.enqueueBegin(priority);//この時点で優先度とシーケンス番号がセットされ、ロックが取得される
				                                         //※返り値は、処理ブロック内でしか（enqueueEnd/enqueueCancel呼び出しまでしか）有効ではないポインタなので注意
				obj->m_val = val;
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
				//処理ブロックを抜ける時に自動的にデキューが終了し、ロックが解放される。
				//※受け取ったポインタを処理ブロックの外で参照すると、誤った情報を参照することになるので注意。
				//※明示的にエンキュー終了／取り消しを実行することも可能。
				//obj = ope.enqueueEnd();//明示的なエンキュー終了を行うと、正しいオブジェクトの参照を取得できる
				//ope.enqueueCancel();
			}
			#endif//USE_ENQUEUE_TYPE
		}
		printf_detail("\n");
	};
	enqueue();

#if 0
	//範囲に基づくforループテスト
	auto printNodesTest1 = [&con]()
	{
		printf("--- Test for C++11 for(:) ---\n");
		for (const data_t& o : con)
			printf("[%1d:%2d] ", o.m_priority, o.m_val);
		printf("\n");
	};
	printNodesTest1();
#endif

#if 0
	//std::for_eachテスト
	auto printNodesTest2 = [&con]()
	{
		printf("--- Test for std::for_each() ---\n");
		std::for_each(con.begin(), con.end(), [](data_t& o)
			{
				printf("[%1d:%2d] ", o.m_priority, o.m_val);
			}
		);
		printf("\n");
	};
	printNodesTest2();
#endif

	//木を表示
	auto showTree = [](const bin_heap_type& heap)
	{
		printf("--- Show tree (count=%d) ---\n", heap.size());
		static const int depth_limit = 5;//最大でも5段階目までを表示（0段階目から数えるので最大で6段階表示される→最大：1+2+4+8+16+32個）
		const int _depth_max = heap.depth_max();
		printf("depth_max=%d (limit for showing=%d)\n", _depth_max, depth_limit);
		const int depth_max = _depth_max <= depth_limit ? _depth_max : depth_limit;
		const int width_max = static_cast<int>(std::pow(2, depth_max));
		for (int depth = 0; depth <= depth_max; ++depth)
		{
			const int width = static_cast<int>(std::pow(2, depth));
			static const int label_len = 6;
			const int print_width = (width_max * label_len) / width;
			const int print_indent = (print_width - label_len) / 2;
			for (int breath = 0; breath < width; ++breath)
			{
				const data_t* node = heap.ref_top();
				int breath_tmp = breath;
				for (int depth_tmp = depth - 1; node; --depth_tmp)
				{
					if (depth_tmp < 0)
						break;
					node = heap.ref_child(node, (breath_tmp & (0x1 << depth_tmp)) != 0x0);
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (heap.ref_child_l(node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(heap.ref_child_l(node) ? "-" : " ");
					}
					printf("%s%1d:%2d%s", heap.ref_child_l(node) ? "{" : "[", node->m_priority, node->m_val, heap.ref_child_r(node) ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(heap.ref_child_r(node) ? "-" : " ");
						if (heap.ref_child_r(node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(" ");
					}
				}
				else
				{
					for (int c = 0; c < print_width; ++c)
						printf(" ");
				}
			}
			printf("\n");
		}
	};
	showTree(con);

	//デキュー
	auto dequeue = [&con](const int pop_limit)
	{
		printf("--- Dequeue ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			#define USE_DEQUEUE_TYPE 2
			//【デキュー方法①】情報取得用のオブジェクトを受け渡す
			//※オブジェクトのコピーが発生する。
			//※デストラクタが呼び出される。（コピー後に実行）
			#if USE_DEQUEUE_TYPE == 1
			{
				data_t node;
				const bool result = con.dequeueCopying(node);
				if (!result)
					break;
				printf("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//【推奨】【デキュー方法②】キュー（オブジェクト）の参照を受け取る方法
			//※オブジェクトのコピーは発生しない。
			//※明示的に終了処理を呼び出し、ロックを解放しなければならない点に注意。
			//　（エンキュー／デキュー操作用クラスを使用することで、処理ブロックを抜ける時に自動敵にロックが解放される）
			//※最後にデストラクタが呼び出される。
			#elif USE_DEQUEUE_TYPE == 2
			{
				priority_queue::operation_guard<container_type> ope(con);//エンキュー／デキュー操作用クラス
				data_t* obj = ope.dequeueBegin();//この時点でロックが取得される
				                                 //※返り値は、処理ブロック内でしか（dequeueEnd/dequeueCancel呼び出しまでしか）有効ではないポインタなので注意
				if (!obj)
					break;
				printf("[%1d:%2d] ", obj->m_priority, obj->m_val);
				//処理ブロックを抜ける時に自動的にデキューが終了し、ロックが解放される。
				//※受け取ったポインタを処理ブロックの外で参照すると、誤った情報を参照することになるので注意。
				//※明示的にデキュー終了／取り消しを実行することも可能。
				//ope.dequeueEnd();
				//ope.dequeueCancel();
			}
			#endif//USE_DEQUEUE_TYPE
		}
		printf("\n");
	};
	dequeue(3);
	showTree(con);//木を表示

	//先頭（根）ノードの優先度を変更
	auto changePriorityOnTop = [&con](const PRIORITY new_priority)
	{
		printf("--- Change Priority ---\n");
		const data_t* node = con.top();//先頭ノードを取得（ポップされない）
		printf("[%1d:%2d(seq=%d)]", node->m_priority, node->m_val, node->m_seqNo);
		node = con.changePriorityOnTop(new_priority);//優先度を変更（変更後、キューが再配置される）
		printf(" -> [%1d:%2d(seq=%d)]\n", node->m_priority, node->m_val, node->m_seqNo);
	};
	changePriorityOnTop(HIGHEST);
	changePriorityOnTop(LOWER);
	changePriorityOnTop(HIGHER);
	showTree(con);//木を表示
	
	//デキュー
	dequeue(TEST_DATA_REG_NUM / 2);
	showTree(con);//木を表示

	//デキュー
	dequeue(TEST_DATA_REG_NUM);
	showTree(con);//木を表示

	//--------------------
	//【挙動比較用】二分ヒープのテスト
	//※プライオリティキューと異なり、ポップ時に、プッシュ時（エンキュー時）の順序性が保証されていないことが確認できる
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for bin_heap::container(Binary Heap)]\n");
	printf("\n");

	bin_heap_type heap;

	//二分ヒープでノードをプッシュ
	auto pushNodesBinHeap = [&heap]()
	{
		printf("--- Push nodes(Binary Heap) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj =heap.push(NORMAL, 0);
			printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			//※上記プライオリティキューで説明した、３種類のプッシュ方法が使える
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			#define USE_PUSH_TYPE 2
			//【プッシュ方法①】
			#if USE_PUSH_TYPE == 1
			{
				data_t new_obj(priority, val);
				data_t* obj = heap.pushCopying(new_obj);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//【推奨】【プッシュ方法②】
			#elif USE_PUSH_TYPE == 2
			{
				data_t* obj = heap.push(priority, val);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//【プッシュ方法③】
			#elif USE_PUSH_TYPE == 3
			{
				bin_heap::operation_guard<bin_heap_type> ope(heap);
				data_t* obj = ope.pushBegin(priority, val);//※返り値は、処理ブロック内でしか（pushEnd/pushCancel呼び出しまでしか）有効ではないポインタなので注意
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
				//obj = ope.popEnd();//明示的なポップ終了を行うと、正しいオブジェクトの参照を取得できる
			}
			#endif//USE_PUSH_TYPE
		}
		printf_detail("\n");
	};
	pushNodesBinHeap();

	//木を表示
	showTree(heap);
	
	//二分ヒープでノードをポップ
	auto popNodesBinHeap  = [&heap](const int pop_limit)
	{
		printf("--- Pop nodes(Binary Heap) ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			//※上記プライオリティキューで説明した、２種類のポップ方法が使える
			#define USE_POP_TYPE 2
			//【ポップ方法①】
			#if USE_POP_TYPE == 1
			{
				data_t node;
				const bool result = heap.popCopying(node);
				if (!result)
					break;
				printf("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//【推奨】【ポップ方法②】
			#elif USE_POP_TYPE == 2
			{
				bin_heap::operation_guard<bin_heap_type> ope(heap);
				data_t* obj = ope.popBegin();//※返り値は、処理ブロック内でしか（popEnd/popCancel呼び出しまでしか）有効ではないポインタなので注意
				if (!obj)
					break;
				printf("[%1d:%2d] ", obj->m_priority, obj->m_val);
			}
			#endif//USE_POP_TYPE
		}
		printf("\n");
	};
	popNodesBinHeap(TEST_DATA_REG_NUM / 2);
	showTree(heap);//木を表示

	//ノードをポップ
	popNodesBinHeap(TEST_DATA_REG_NUM);
	showTree(heap);//木を表示

	//--------------------
	//【挙動比較用】STLのstd::priority_queueテスト
	//※プライオリティキューと異なり、ポップ時に、プッシュ時（エンキュー時）の順序性が保証されていないことが確認できる
	//※STLと二分ヒープの挙動（ポップ順序）が全く同じことを確認できる
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for std::priority_queue(STL)]\n");
	printf("\n");
	
	std::priority_queue<data_t, std::vector<data_t>, ope_t> stl;

	//STLでノードをプッシュ
	auto pushNodesSTL = [&stl]()
	{
		printf("--- Push nodes(STL) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t obj(NORMAL, 0);
			stl.push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			data_t obj(priority, val);
			stl.push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
		printf_detail("\n");
	};
	pushNodesSTL();

	//STLでノードをポップ
	auto popNodesSTL = [&stl](const int pop_limit)
	{
		printf("--- Pop nodes(STL) ---\n");
		for (int i = 0; i < pop_limit && !stl.empty(); ++i)
		{
			data_t node = stl.top();
			printf("[%1d:%2d] ", node.m_priority, node.m_val);
			stl.pop();
		}
		printf("\n");
	};
	popNodesSTL(TEST_DATA_REG_NUM / 2);
	popNodesSTL(TEST_DATA_REG_NUM);

	//--------------------
	//【挙動比較用】プライオリティキューの再テスト
	//※上記の二分ヒープ／STLのテストと同一の流れのテストを実施
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)] *Second time\n");
	printf("\n");

	enqueue();//エンキュー
	showTree(con);//木を表示
	dequeue(TEST_DATA_REG_NUM / 2);//デキュー
	showTree(con);//木を表示
	dequeue(TEST_DATA_REG_NUM);//デキュー
	showTree(con);//木を表示

	//--------------------
	//プライオリティキューのクリアのテスト
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)] *Clear\n");
	printf("\n");

	enqueue();//エンキュー
	showTree(con);//木を表示
	printf("--- Clear ---\n");
	con.clear();//クリア
	printf("OK\n");
	showTree(con);//木を表示

	//--------------------
	//ポインタ変数をキューイングする場合のテスト
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for priority_queue::container(Priority Queue)] *Pointer\n");
		
		//操作型
		struct p_ope_t : public priority_queue::base_ope_t<p_ope_t, data_t*, PRIORITY, int>
		{
			inline static priority_type getPrior(const node_type& node){ return node->m_priority; }
			inline static void setPrior(node_type& node, const priority_type priority){ node->m_priority = priority; }
			inline static seq_type getSeqNo(const node_type& node){ return node->m_seqNo; }
			inline static void setSeqNo(node_type& node, const seq_type seq_no){ node->m_seqNo = seq_no; }
		};
		
		//プライオリティキュー
		priority_queue::container<p_ope_t, TEST_DATA_MAX> p_con;
		
		//エンキュー
		data_t obj1(NORMAL, 1);
		data_t obj2(HIGHER, 2);
		data_t obj3(LOWER, 3);
		data_t obj4(HIGHEST, 4);
		data_t obj5(LOWEST, 5);
		p_con.enqueueCopying(&obj1);
		p_con.enqueueCopying(&obj2);
		p_con.enqueueCopying(&obj3);
		p_con.enqueueCopying(&obj4);
		p_con.enqueueCopying(&obj5);

		//デキュー
		auto dequeuObj = [&p_con]()
		{
			data_t* obj_p = nullptr;
			p_con.dequeueCopying(obj_p);
			printf("pop: [%1d:%2d](seq=%d)\n", obj_p->m_priority, obj_p->m_val, obj_p->m_seqNo);
		};
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
	}

	return EXIT_SUCCESS;
}

// End of file
