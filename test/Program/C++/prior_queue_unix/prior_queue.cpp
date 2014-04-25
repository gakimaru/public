//--------------------------------------------------------------------------------
//二分ヒープテスト用設定とコンパイラスイッチ
static const int TEST_DATA_PRIOR_MIN = 1;//テストデータの最小プライオリティ
static const int TEST_DATA_PRIOR_MAX = 5;//テストデータの最大プライオリティ
static const int TEST_DATA_MAX = 128;//テストデータの最大登録可能数
static const int TEST_DATA_REG_NUM = 60;//テストデータの登録数
#define PRINT_TEST_DATA_DETAIL//テストデーの詳細タを表示する場合は、このマクロを有効化する

#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//std::size_t用
#include <cstdint>//C++11 intptr_t用

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
//　デキュー（pop）時に、キューイング（push）の順序性は保証されない。
//　※この強度はSTLと同じ。
//・STL（std::priority_queue）との違いは下記の通り
//    - 固定長配列である。（STLは内部にstd::vectorを使用しており、自動拡張する）
//    - 赤黒木コンテナ（rb_tree）の実装と合わせた構造にしており、
//　　  操作用テンプレート構造体を用いる。
//　　  ※STLで使用する比較用の関数オブジェクトクラス(less)は用いない。
//　　- C++11の「範囲に基づくforループ」と、STLの「std::for_each()」が使用可能。
//　　  単純に配列の内容を列挙する。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【具体的な活用の想定】
//・任意の構造のプライオリティキューに適用。
//--------------------------------------------------------------------------------

namespace bin_heap
{
	//--------------------
	//二部ヒープ操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename NODE_TYPE, int _NODES_MAX>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public bin_heap::base_ope_t<派生構造体, ノード型, 最大ノード数>
	//	struct ope_t : public bin_heap::ope_t<ope_t, data_t, 1024>
	//	{
	//		//キーを比較
	//		//※lhsの方が小さいければ true を返す
	//		inline static bool less(const node_type& lhs, const node_type& rhs)
	//		{
	//			return lhs.m_key < rhs.m_key;
	//		}
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, int _NODES_MAX>
	struct base_ope_t
	{
		//定数
		static const int NODES_MAX = _NODES_MAX;//最大ノード数

		//型
		typedef OPE_TYPE ope_type;//ノード操作型
		typedef NODE_TYPE node_type;//ノード型
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
	//二部ヒープコンテナ
	//※固定配列と使用中の要素数を持つ
	//※std::priority_queueとはあまり互換性がなく、イテレータにも対応しない
	template<class OPE_TYPE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//定数
		static const std::size_t ARRAY_NUM = ope_type::NODES_MAX;//配列要素数
	public:
		//メソッド
		std::size_t max_size() const { return ARRAY_NUM; }//最大要素数を取得
		std::size_t capacity() const { return ARRAY_NUM; }//最大要素数を取得
		std::size_t size() const { return m_used; }//使用中の要素数を取得
		bool empty() const { return m_used == 0; }//空か？
	private:
		int _calc_depth_max(int depth) const { depth >>= 1; return depth == 0 ? 0 : 1 + _calc_depth_max(depth); }//最大の深さを計算
	public:
		int depth_max() const { return m_used == 0 ? -1 : _calc_depth_max(m_used + 1); }//最大の深さを取得
		void clear(){ m_used = 0; }//クリア
		inline const node_type* ref_node(const int index) const { return index >= 0 && index < static_cast<int>(m_used) ? &m_array[index] : nullptr; }//ノード参照
		inline const node_type* ref_top() const { return m_used == 0 ? nullptr : &m_array[0]; }//先頭ノード参照
		inline const node_type* ref_bottom() const { return m_used == 0 ? nullptr : &m_array[m_used - 1]; }//終端ノード参照
		inline const node_type* ref_new() const { return m_used == ARRAY_NUM ? nullptr : &m_array[m_used]; }//新規ノード参照
		inline const node_type* begin() const { return m_used == 0 ? nullptr : &m_array[0]; }//開始ノード
		inline const node_type* end() const { return m_used == 0 ? nullptr : &m_array[m_used]; }//終了ノード
		inline node_type* ref_node(const int index){ return  const_cast<node_type*>(const_cast<const container*>(this)->ref_node()); }//ノード参照
		inline node_type* ref_top(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_top()); }//先頭ノード参照
		inline node_type* ref_bottom(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_bottom()); }//終端ノード参照
		inline node_type* ref_new(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_new()); }//新規ノード参照
		inline node_type* begin(){ return const_cast<node_type*>(const_cast<const container*>(this)->begin()); }//開始ノード
		inline node_type* end(){ return const_cast<node_type*>(const_cast<const container*>(this)->end()); }//終了ノード
	private:
		inline int _adj_index(const int index) const { return index >= 0 && index < ARRAY_NUM ? index : -1; }//インデックスを範囲内に補正
		inline int _ref_index(const node_type* node) const{ return node - m_array; }//ノードをインデックスに変換 ※範囲チェックなし
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
	private:
		inline bool _less(const bool result) const { return m_isReverse ? !result : result; }//キー比較
	public:
		inline bool less(const node_type& lhs, const node_type& rhs) const { return _less(ope_type::less(lhs, rhs)); }//キー比較
		//プッシュ
		const node_type* push(const node_type& obj)
		{
			node_type* dst = push_begin();
			if (!dst)
				return nullptr;
			*dst = obj;
			return push_end();
		}
		//プッシュ開始
		//※空きノード取得
		node_type* push_begin(){ return &m_array[m_used]; }
		//プッシュ終了
		//※追加した新規ノードを上に移動
		const node_type* push_end()
		{
			if (m_used == ARRAY_NUM)
				return nullptr;
			//末端の葉ノードとして登録された新規ノードを上方に移動
			std::size_t index = m_used++;
			node_type* obj = &m_array[index];
			while (index != 0)
			{
				index = _calc_parent(index);
				node_type* parent = &m_array[index];
				if (less(*parent, *obj))
				{
					node_type tmp;
					tmp = *obj;
					*obj = *parent;
					*parent = tmp;
					obj = parent;
				}
			}
			return obj;
		}
		//ポップ
		bool pop(node_type& dst)
		{
			const node_type* obj = pop_begin();
			if (!obj)
				return false;
			dst = *obj;
			return pop_end();
		}
		//ポップ開始
		//※根ノード取得
		const node_type* pop_begin(){ return &m_array[0]; }
		//ポップ終了
		//※削除した根ノードの隙間を埋めるために、以降のノードを上に移動
		bool pop_end()
		{
			if (m_used == 0)
				return false;
			//根ノードがポップされたので、末端の葉ノードを根ノードに上書きした上で、それを下方に移動
			std::size_t index = 0;
			node_type* obj = &m_array[0];
			*obj = m_array[--m_used];
			while (true)
			{
				index = _calc_child_l(index);
				if (index >= m_used)
					break;
				node_type* child = &m_array[index];
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
				{
					node_type tmp;
					tmp = *obj;
					*obj = *child;
					*child = tmp;
				}
				obj = child;
			}
			return true;
		}
	public:
		//コンストラクタ
		//※キー比較処理を渡す
		container(const bool is_reverse = false) :
			m_used(0),
			m_isReverse(is_reverse)
		{}
		//デストラクタ
		~container()
		{}
	private:
		//フィールド
		node_type m_array[ARRAY_NUM];//配列
		std::size_t m_used;//使用数
		const bool m_isReverse;//キー比較を反転するか？
	};
}//namespace bin_heap

//--------------------------------------------------------------------------------
//プライオリティキュー
//※二分ヒープをそのまま使用しているのみ。
//※最終的には、二分ヒープを内部に保持し、委譲を行う構造にした上で、
//　スレッドセーフな構造にする。
//　（逆に、二分ヒープのような基本的なアルゴリズムのレベルでは、
//　　汎用性を重視し、スレッドセーフ化はすべきでない。）
namespace prior_queue
{
	template<class OPE_TYPE, typename NODE_TYPE, int _NODES_MAX>
	using base_ope_t = bin_heap::base_ope_t<OPE_TYPE, NODE_TYPE, _NODES_MAX>;
	
	template<class OPE_TYPE>
	using container = bin_heap::container<OPE_TYPE>;
}

//--------------------------------------------------------------------------------
//プライオリティキューテスト

#include <memory.h>//memcpy用
#include <random>//C++11 std::random用
#include <algorithm>//std::for_each用
#include <queue>//std::priority_queue用※比較テスト用

//----------------------------------------
//テストデータ
struct data_t
{
	int m_key;//キー
	int m_val;//データ
};
//----------------------------------------
//テストデータ操作クラス
struct ope_t : public prior_queue::base_ope_t<ope_t, data_t, TEST_DATA_MAX>
{
	//キーを比較
	//※lhsの方が小さいければ true を返す
	inline static bool less(const node_type& lhs, const node_type& rhs)
	{
		return lhs.m_key < rhs.m_key;
	}

	//STLのstd::priority_queueと共用するための関数オブジェクト
	inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return less(lhs, rhs); }
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
//テスト
int main(const int argc, const char* argv[])
{
	//コンテナ生成
	prior_queue::container<ope_t> con;

	//ノードをプッシュ
	auto pushNodes = [&con]()
	{
		printf("--- Push nodes ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		for (int val = 0; val < TEST_DATA_REG_NUM; ++val)
		{
			const int key = rand_dist(rand_engine);
			printf_detail("[%d:%2d] ", key, val);
			con.push({ key, val });
		}
		printf_detail("\n");
	};
	pushNodes();

#if 0
	//範囲に基づくforループテスト
	auto printNodesTest1 = [&con]()
	{
		printf("--- Test for C++11 for(:) ---\n");
		for (const data_t& o : con)
			printf("[%1d:%2d] ", o.m_key, o.m_val);
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
				printf("[%1d:%2d] ", o.m_key, o.m_val);
			}
		);
		printf("\n");
	};
	printNodesTest2();
#endif

	//木を表示
	auto showTree = [&con]()
	{
		printf("--- Show tree (count=%d) ---\n", con.size());
		static const int depth_limit = 5;//最大でも5段階目までを表示（0段階目から数えるので最大で6段階表示される→最大：1+2+4+8+16+32個）
		const int _depth_max = con.depth_max();
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
				const data_t* node = con.ref_top();
				int breath_tmp = breath;
				for (int depth_tmp = depth - 1; node; --depth_tmp)
				{
					if (depth_tmp < 0)
						break;
					node = con.ref_child(node, (breath_tmp & (0x1 << depth_tmp)) != 0x0);
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (con.ref_child_l(node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(con.ref_child_l(node) ? "-" : " ");
					}
					printf("%s%1d:%2d%s", con.ref_child_l(node) ? "{" : "[", node->m_key, node->m_val, con.ref_child_r(node) ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(con.ref_child_r(node) ? "-" : " ");
						if (con.ref_child_r(node) && c < print_indent)
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
	showTree();

	//ノードをポップ
	auto popNodes = [&con](const int pop_limit)
	{
		printf("--- Pop nodes ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			data_t node;
			const bool result = con.pop(node);
			if (!result)
				break;
			printf("[%1d:%2d] ", node.m_key, node.m_val);
		}
		printf("\n");
	};
	popNodes(TEST_DATA_REG_NUM / 2);
	showTree();//木を表示

	//ノードをポップ
	popNodes(TEST_DATA_REG_NUM);
	showTree();//木を表示

	//以下、STLとの挙動比較
	std::priority_queue<data_t, std::vector<data_t>, ope_t> stl;

	//STLでノードをプッシュ
	auto pushNodesSTL = [&stl]()
	{
		printf("--- Push nodes(STL) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		for (int val = 0; val < TEST_DATA_REG_NUM; ++val)
		{
			const int key = rand_dist(rand_engine);
			printf_detail("[%1d:%2d] ", key, val);
			stl.push({ key, val });
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
			printf("[%1d:%2d] ", node.m_key, node.m_val);
			stl.pop();
		}
		printf("\n");
	};
	popNodesSTL(TEST_DATA_REG_NUM / 2);
	popNodesSTL(TEST_DATA_REG_NUM);

	return EXIT_SUCCESS;
}

// End of file
