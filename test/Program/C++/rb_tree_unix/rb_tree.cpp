//--------------------------------------------------------------------------------
//赤黒木テスト用設定とコンパイラスイッチ
static const int TEST_DATA_KEY_MIN = 0;//テストデータの最小キー
static const int TEST_DATA_KEY_MAX = 99;//テストデータの最大キー
static const int TEST_DATA_REG_NUM = 100;//テストデータの登録数
static const int TEST_DATA_STACK_DEPTH_MAX = 32;//テストデータの赤黒木操作用スタックの最大の深さ（デフォルトは32で、平衡木なら10万件は扱える）
//#define REGIST_TEST_DATA_SEQUENTIALLY//データをシーケンシャルに登録する場合は、このマクロを有効化する（無効化時はランダム）
#define PRINT_TEST_DATA_TREE//テストデータの木を表示する場合は、このマクロを有効化する（表示しなくても検索は実行する）
#define PRINT_TEST_DATA_SEARCH//テストデーたの検索結果を表示する場合は、このマクロを有効化する（表示しなくても検索は実行する）
#define PRINT_TEST_DATA_COLOR_COUNT//テストデータの赤黒カウント数計測を表示する場合は、このマクロを有効化する
#define PRINT_TEST_DATA_DETAIL//テストデーの詳細タを表示する場合は、このマクロを有効化する

//テストデータを固定順に登録する場合は、このマクロを有効化する（無効時はランダム、ただし、REGIST_TEST_DATA_SEQUENTIALLYが優先）
//#define TEST_DATA_REGISTRATION_LIST { 54, 59, 71, 84, 60, 85, 54, 84, 42, 62, 64, 38, 43, 29, 89, 5, 96, 27, 38, 47, 79, 81, 52, 47, 56, 39, 92, 83, 7, 33, 8, 64, 2, 36, 83, 95, 77, 14, 87, 87, 97, 47, 79, 80, 46, 52, 78, 67, 11, 72, 63, 58, 14, 53, 94, 75, 52, 10, 41, 47, 26, 18, 77, 73, 45, 21, 56, 13, 1, 32, 61, 14, 61, 22, 61, 38, 94, 90, 68, 44, 35, 61, 43, 90, 69, 9, 6, 96, 66, 65, 67, 17, 21, 35, 12, 75, 31, 60, 36, 32}

//テストデータを固定順に削除する場合は、このマクロを有効化する（無効時はランダム）
//#define TEST_DATA_REMOVING_LIST { 41, 72, 12, 14, 9, 39, 18, 38, 66, 53, 84, 31, 68, 52, 44, 87 }

//--------------------------------------------------------------------------------
//赤黒木アルゴリズム用コンパイラスイッチ
//#define DISABLE_COLOR_FOR_ADD//ノード追加時のカラー操作と回転処理を無効化する場合は、このマクロを有効化する
//#define DISABLE_COLOR_FOR_REMOVE//ノード削除時のカラー操作と回転処理を無効化する場合は、このマクロを有効化する
//#define DEBUG_PRINT_FOR_ADD//ノード追加時のデバッグ情報表示を有効化する場合は、このマクロを有効化する
//#define DEBUG_PRINT_FOR_REMOVE//ノード削除時のデバッグ情報表示を有効化する場合は、このマクロを有効化する

#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t用
#include <memory.h>//memcpy用
#include <assert.h>//assert用
#include <iterator>//std::iterator用


//--------------------------------------------------------------------------------
//赤黒木（red-black tree）
//--------------------------------------------------------------------------------
//データ構造とアルゴリズム
//【特徴】
//・二分探索木である。
//	  - ノードの左側の子には、キーの値が小さいノードを連結。
//	  - ノードの右側の子には、キーの値が大きいか等しいノードを連結。
//・平衡木である。
//	  - 常に左右の木のバランスを保つ。
//・以上の特徴により、探索・追加・削除の時間が、常にO(log n)に保たれる。
//【条件】
//・条件①：各ノードは「赤」か「黒」の「色」を持つ。
//・条件②：「根」（root）は必ず「黒」。
//・条件③：「赤」の子は必ず「黒」。
//	          - 待遇により、「赤」の親は必ず「黒」。
//	          - 「黒」の子は「赤」でも「黒」でも良い。
//・条件④：すべての「根」から「葉」までの経路上にある「黒」の数は、
//　　　　　あらゆる経路で一定。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【本プログラムにおける実装要件】
//・メモリ節約のために、親ノードへのリンクを持たないデータ構造とする。
//・代わりに、検索等の関数実行時に外部からスタックを渡す事で親を辿ることが可能。
//・テンプレートにより、アルゴリズムを汎用化。
//・キー重複（同キーのノードが複数ある状態）を許容するアルゴリズムとする。
//・リンクの方法に柔軟性を持たせ、かつ、virtualを必須としないように、
//　データ構造は自由とする。
//　（リンクの変数をポインタにしようがインデックスにしようが自由）
//・代わりに、データ操作専用のクラスをユーザー定義することで、
//　処理に汎用性を持たせる。
//・一切メモリ操作は行わず、ノードのオブジェクトを受け取って操作する
//　アルゴリズムのみを提供する。
//・std::mapを模したコンテナとイテレータを利用可能とする。
//・コンテナは、根ノードのみを保持し、一切メモリ操作しないものとする。
//・イテレータは、上述のスタック操作を隠ぺいする。
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【具体的な活用の想定】※以下、メモリ管理処理に適用することを想定した要件。
//・メモリマネージャの管理情報の連結に使用することを想定。
//・空きメモリサイズ順の連結を行うため、キー重複を許容する必要がある。
//・また、連結リストが肥大化することを避けるため、親ノードへのリンク情報は
//　持たない。
//・必要量以上の空きメモリのノードを検索したのち、アラインメントを加味した
//　上で利用可能なノードかを確認し、一つずつ大きなノードを辿って最適な
//　ノードを探し出す。
//・ノード間のリンク情報は、64bitポインタ変数による肥大化が起こらないように、
//　メモリ空間の先頭からオフセットされた32bitの相対ポインタを扱う。
//・一つのメモリ管理情報を、2種類の木に振り分けて使用する。
//　削除済みメモリノードの二分探索木はサイズをキーにし、
//　使用中メモリノードの二分探索木はポインタをキーにする。
//・このような利用を可能とするために、データ構造とアルゴリズムを完全に
//　切り離した構成にする。
//--------------------------------------------------------------------------------

namespace rb_tree
{
	//--------------------
	//赤黒木ノード操作用テンプレート構造体
	//※CRTPを活用し、下記のような派生構造体を作成して使用する
	//  //template<class OPE_TYPE, typename NODE_TYPE, typename KEY_TYPE, int STACK_DEPTH_MAX = 32>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public rb_tree::base_ope_t<派生構造体, ノード型, キー型, スタックの最大の深さ = 32>
	//	struct ope_t : public rb_tree::ope_t<ope_t, data_t, int>
	//	{
	//		//子ノードを取得
	//		inline static const node_type* getChildL(const node_type& node){ return ???; }//大（右）側
	//		inline static const node_type* getChildS(const node_type& node){ return ???; }//小（左）側
	//		//子ノードを変更
	//		inline static void setChildL(node_type& node, const node_type* child){ ??? = child; }//大（右）側
	//		inline static void setChildS(node_type& node, const node_type* child){ ??? = child; }//小（左）側
	//		
	//		//ノードの色を取得
	//		inline static color_t getColor(const node_type& node){ return ??? ? BLACK : RED; }
	//		//ノードの色を変更
	//		inline static void setColor(node_type& node, const color_t color){ ??? = color == BLACK; }
	//		
	//		//キーを取得
	//		inline static key_type getKey(const node_type& node){ return ???; }
	//		
	//		//キーを比較
	//		//Return value:
	//		//  0 ... lhs == rhs
	//		//  1 ... lhs > rhs
	//		// -1 ... lhs < rhs
	//		inline static int compareKey(const key_type lhs, const key_type rhs)
	//		{
	//			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
	//		}
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, typename KEY_TYPE, int _STACK_DEPTH_MAX = 32>
	struct base_ope_t
	{
		//定数
		static const int STACK_DEPTH_MAX = _STACK_DEPTH_MAX;//スタックの最大の深さ
		enum color_t//カラー
		{
			RED = 0,//赤
			BLACK = 1,//黒
		};

		//型
		typedef OPE_TYPE ope_type;//ノード操作型
		typedef NODE_TYPE node_type;//ノード型
		typedef KEY_TYPE key_type;//キー型
		
		//子ノードを取得
		inline static const node_type* getChild(const node_type& node, const bool child_is_large)
		{
			return child_is_large ?
				ope_type::getChildL(node) ://大（右）側
				ope_type::getChildS(node); //小（左）側
		}
		//子ノードを変更
		inline static void setChild(node_type& node, const bool child_is_large, const node_type* child)
		{
			if (child_is_large)
				ope_type::setChildL(node, child);//大（右）側
			else
				ope_type::setChildS(node, child);//小（左）側
		}

		//キーを比較
		//※デフォルト
		//Return value:
		//  0 ... lhs == rhs
		//  1 ... lhs > rhs
		// -1 ... lhs < rhs
		inline static int compareKey(const key_type lhs, const key_type rhs)
		{
			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
		}

		//ノードとキーを比較
		inline static int compare(const node_type& lhs, const node_type& rhs)
		{
			return ope_type::compareKey(ope_type::getKey(lhs), ope_type::getKey(rhs));
		}
		inline static int compare(const node_type& lhs, const key_type rhs)
		{
			return ope_type::compareKey(ope_type::getKey(lhs), rhs);
		}
		inline static int compare(const key_type lhs, const node_type& rhs)
		{
			return ope_type::compareKey(lhs, ope_type::getKey(rhs));
		}
		inline static int compare(const key_type lhs, const key_type rhs)
		{
			return ope_type::compareKey(lhs, rhs);
		}
		inline static bool eq(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) == 0; }
		inline static bool eq(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) == 0; }
		inline static bool eq(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) == 0; }
		inline static bool ne(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) != 0; }
		inline static bool ne(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) != 0; }
		inline static bool ne(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) != 0; }
		inline static bool gt(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) > 0; }
		inline static bool gt(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) > 0; }
		inline static bool gt(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) > 0; }
		inline static bool ge(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool ge(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool ge(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) >= 0; }
		inline static bool lt(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) < 0; }
		inline static bool lt(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) < 0; }
		inline static bool lt(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) < 0; }
		inline static bool le(const node_type& lhs, const node_type& rhs){ return compare(lhs, rhs) <= 0; }
		inline static bool le(const node_type& lhs, const key_type rhs){ return compare(lhs, rhs) <= 0; }
		inline static bool le(const key_type lhs, const key_type rhs){ return compare(lhs, rhs) <= 0; }

		//カラー判定
		inline static bool isBlack(const node_type& node){ return ope_type::getColor(node) == BLACK; }
		inline static bool isRed(const node_type& node){ return ope_type::getColor(node) == RED; }
		//カラー更新
		inline static void setIsBlack(node_type& node){ ope_type::setColor(node, BLACK); }
		inline static void setIsRed(node_type& node){ ope_type::setColor(node, RED); }
	};
	//--------------------
	//基本型定義マクロ
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef typename ope_type::key_type key_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef stack_t<ope_type> stack_type; \
		typedef typename stack_type::info_t stack_info_type;
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
	//--------------------
	//赤黒木操作処理用スタッククラス
	//※赤黒木のノード情報を扱う
	template<class OPE_TYPE>
	class stack_t
	{
	public:
		//基本型
		typedef OPE_TYPE ope_type;
		typedef typename OPE_TYPE::node_type node_type;
	public:
		//定数
		static const int DEPTH_MAX = ope_type::STACK_DEPTH_MAX;//最大の深さ（スタック処理用）
	public:
		//型
		//ノード情報型
		struct info_t
		{
			const node_type* m_nodeRef;//ノード参照
			bool m_isLarge;//大（右）側に連結か？
		};
	public:
		//スタックにノード情報を記録
		info_t* push(const node_type* node, const bool is_large)
		{
			assert(m_depth < DEPTH_MAX);
			info_t* stack_node = &m_array[m_depth++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
			return stack_node;
		}
		//スタックからノード情報を取得
		info_t* pop()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[--m_depth];
		}
		//スタックの先頭のノード情報を参照
		//※要素が減らない
		info_t* top()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[m_depth - 1];
		}
		//スタックの現在の深さを取得
		int getDepth() const { return m_depth; }
		//スタックの現在の深さを更新
		void setDepth(const int depth)
		{
			if (depth < 0)
				m_depth = 0;
			else if (depth < m_depth)
				m_depth = depth;
		}
		//スタックの現在の深さをリセット
		void reset()
		{
			m_depth = 0;
		}
		//スタックの現在の幅を算出
		//※「幅」＝スタックの現在の深さまでの大小連結の合計値を算出
		//※小側を-1、大側を+1として計算
		long long calcBreadth()
		{
			long long breadth = 0;
			for (int depth = 0; depth < m_depth; ++depth)
			{
				breadth *= 2ll;
				breadth += (m_array[depth].m_isLarge ? 1ll : 0ll);
			}
			return breadth;
		}
		//コピーオペレータ
		stack_t& operator=(const stack_t rhs)
		{
			m_depth = rhs.m_depth;
			if (m_depth > 0)
				memcpy(m_array, rhs.m_array, sizeof(info_t)* m_depth);
			return *this;
		}
		//コピーコンストラクタ
		stack_t(const stack_t& obj) :
			m_depth(obj.m_depth)
		{
			if (m_depth > 0)
				memcpy(m_array, obj.m_array, sizeof(info_t)* m_depth);
		}
		//コンストラクタ
		stack_t() :
			m_depth(0)
		{}
	private:
		//フィールド
		info_t m_array[DEPTH_MAX];//ノード情報の配列（スタック）
		int m_depth;//スタックのカレントの深さ
	};
	//--------------------
	//赤黒木操作関数：一番小さいノードを取得
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getSmallestNode(const typename OPE_TYPE::node_type* root, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* curr_node = root;//現在の探索ノード
		while (true)
		{
			const node_type* child_node = ope_type::getChildS(*curr_node);//小（左）側の子ノードを取得
			if (!child_node)//子が無ければ終了
				return  curr_node;
			stack.push(curr_node, false);//親ノードをスタックに記録
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：一番大きいノードを取得
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getLargestNode(const typename OPE_TYPE::node_type* root, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* curr_node = root;//現在の探索ノード
		while (true)
		{
			const node_type* child_node = ope_type::getChildL(*curr_node);//大（右）側の子ノードを取得
			if (!child_node)//子が無ければ終了
				return  curr_node;
			stack.push(curr_node, true);//親ノードをスタックに記録
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：カレントノードの次に大きいノードを取得
	//※get**Node()やsearchNode()でカレントノードを取得した際のスタックを渡す必要あり
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getNextNode(const typename OPE_TYPE::node_type* curr_node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!curr_node)
			return nullptr;
		const node_type* child_node_l = ope_type::getChildL(*curr_node);//大（右）側の子ノードを取得
		if (child_node_l)//子がある場合
		{
			stack.push(curr_node, true);//親ノードをスタックに記録
			return getSmallestNode<ope_type>(child_node_l, stack);//子から一番小さい子孫ノードを取得
		}
		else//if(!child_node_l)//子がない場合
		{
			const stack_info_type* stack_node = nullptr;
			while (stack_node = stack.pop())//親ノードを取得
			{
				if (stack_node->m_isLarge == false)//小（左）側の子の親なら終了
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：カレントノードの次に小さいノードを取得
	//※get**Node()やsearchNode()でカレントノードを取得した際のスタックを渡す必要あり
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getPrevNode(const typename OPE_TYPE::node_type* curr_node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!curr_node)
			return nullptr;
		const node_type* child_node_s = ope_type::getChildS(*curr_node);//小（左）側の子ノードを取得
		if (child_node_s)//子がある場合
		{
			stack.push(curr_node, false);//親ノードをスタックに記録
			return getLargestNode<ope_type>(child_node_s, stack);//子から一番大きい子孫ノードを取得
		}
		else//if(!child_node_s)//子がない場合
		{
			const stack_info_type* stack_node = nullptr;
			while (stack_node = stack.pop())//親ノードを取得
			{
				if (stack_node->m_isLarge == true)//大（右）側の子の親なら終了
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：木の最大の深さを計測
	//※内部でスタックを作成
	//※-1でリストなし
	template<class OPE_TYPE>
	int getDepthMax(const typename OPE_TYPE::node_type* root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return -1;
		int depth_max = 0;//最大の深さ
		stack_type stack;//スタックを作成
		const node_type* node = getSmallestNode<ope_type>(root, stack);//最小ノード取得
		while (node)
		{
			const int depth = stack.getDepth();//深さを取得
			depth_max = depth_max >= depth ? depth_max : depth;//最大の深さを更新
			node = getNextNode<ope_type>(node, stack);//次のノード取得
		}
		return depth_max;
	}
	//--------------------
	//赤黒木操作関数：指定のキーと一致するノード、もしくは、指定のキーに最も近いノードを検索
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	//※一致ノードが複数ある場合、その最初のノードを返す
	//※指定のキーの内輪で最も近いノードと同キーのノードが複数ある場合、その最後のノードを返す
	//※指定のキーより大きく最も近いノードと同キーのノードが複数ある場合、その最初のノードを返す
	enum match_type_t
	{
		FOR_MATCH = 0,//一致ノードを検索
		FOR_NEAREST_SMALLER,//一致ノード、もしくは、内輪で最も近いノードを検索
		FOR_NEAREST_LARGER,//一致ノード、もしくは、それより大きく最も近いノードを検索
	};
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* searchNode(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::key_type key, stack_t<OPE_TYPE>& stack, const match_type_t search_type = FOR_MATCH)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* match_node = nullptr;//一致ノード
		int match_stack_depth = -1;//一致ノード検出時のスタック位置
		const node_type* nearest_node = nullptr;//最近ノード
		int nearest_stack_depth = -1;//最近ノード検出時のスタック位置
		const node_type* curr_node = root;//現在の探索ノード
		while (true)
		{
			const int cmp = ope_type::compare(*curr_node, key);//指定のキーと大小比較
			if (cmp == 0)//指定のキーと一致
			{
				//※キー重複を許容するアルゴリズムのため、
				//　一致ノードを記録した上で検索を続行する
				match_node = curr_node;//一致ノードを記録
				match_stack_depth = stack.getDepth();//一致ノード検出時のスタック位置を記録
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = ope_type::getChildS(*curr_node);//小（左）側の子の方に検索を続行
				if (!curr_node)//子が無ければ終了
					break;
			}
			else if (cmp < 0)//指定のキーより小さい
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && ope_type::le(*nearest_node, *curr_node)))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_depth = stack.getDepth();//最近ノード検出時のスタック位置を記録
				}
				const node_type* child_node = ope_type::getChildL(*curr_node);//大（右）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, true);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
			else//if (cmp > 0)//指定のキーより大きい
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && ope_type::ge(*nearest_node, *curr_node)))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_depth = stack.getDepth();//最近ノード検出時のスタック位置を記録
				}
				const node_type* child_node = ope_type::getChildS(*curr_node);//小（左）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
		}
		if (match_node)//一致ノード検出時
		{
			stack.setDepth(match_stack_depth);//一致ノード検出時のスタック位置に戻す
			return match_node;//一致ノードを返す
		}
		else//if (!match_node)
		{
			if (nearest_node)//最近ノード検出時
			{
				stack.setDepth(nearest_stack_depth);//最近ノード検出時のスタック位置に戻す
				return nearest_node;//最近ノードを返す
			}
		}
		return nullptr;//検索失敗
	}
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* searchNode(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::node_type* node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const key_type key = ope_type::getKey(*node);//キーを取得
		node_type* target_node = const_cast<node_type*>(searchNode<ope_type>(root, key, stack));//キーが一致するノードを検索
		if (!target_node)//キーが一致するノードがなければ終了
			return nullptr;
		while (target_node != node && ope_type::eq(*target_node, key))//指定ノード（と同じアドレス）を検索
			target_node = const_cast<node_type*>(getNextNode<ope_type>(target_node, stack));
		if (target_node != node)
			return nullptr;
		return target_node;
	}
	//--------------------
	//赤黒木操作関数：木のノード数を計測
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type* node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		return !node ? 0 : 1 + countNodes<ope_type>(ope_type::getChildL(*node)) +
		                       countNodes<ope_type>(ope_type::getChildS(*node));
	}
	//--------------------
	//赤黒木操作関数：指定のキーのノード数を計測
	//※関数内でスタックを使用
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::key_type key)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return 0;
		stack_type stack;
		const node_type* node = searchNode<ope_type>(root, key, stack, FOR_MATCH);
		if (!node)
			return 0;
		int count = 0;//ノード数
		while (node && ope_type::eq(*node, key))
		{
			++count;
			node = getNextNode<ope_type>(node, stack);
		}
		return count;
	}
	//--------------------
	//赤黒木操作関数：ノード追加時の赤黒バランス調整
	template<class OPE_TYPE>
	void _balanceForAdd(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* curr_node, bool child_is_large, typename OPE_TYPE::node_type* child_node);
	//--------------------
	//赤黒木操作関数：ノードを追加
	//※関数内でスタックを使用
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* addNode(typename OPE_TYPE::node_type* new_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!new_node)
			return nullptr;
		ope_type::setChildL(*new_node, nullptr);//新規ノードはリンクをクリア：大（右）側
		ope_type::setChildS(*new_node, nullptr);//新規ノードはリンクをクリア：小（左）側
		if (!root)//根ノードが未登録の場合
		{
			root = new_node;//根ノードに登録
		#ifndef DISABLE_COLOR_FOR_ADD
			ope_type::setIsBlack(*root);//根ノードは黒
		#endif//DISABLE_COLOR_FOR_ADD
			return new_node;//この時点で処理終了
		}
	#ifndef DISABLE_COLOR_FOR_ADD
		ope_type::setIsRed(*new_node);//新規ノードは暫定で赤
	#endif//DISABLE_COLOR_FOR_ADD
		key_type new_key = ope_type::getKey(*new_node);//新規ノードのキーを取得
		stack_type stack;//スタックを用意
		node_type* curr_node = root;//現在の探索ノード
		bool new_key_is_large = false;
		while (true)
		{
			new_key_is_large = ope_type::ge(new_key, *curr_node);//指定のキーと一致もしくは指定のキーの方が大きければtrue
			node_type* child_node = const_cast<node_type*>(ope_type::getChild(*curr_node, new_key_is_large));//子ノードを取得
			if (!child_node)//子ノードが無ければそこに新規ノードを追加して終了
			{
				ope_type::setChild(*curr_node, new_key_is_large, new_node);//子ノードとして新規ノードを追加
				break;
			}
			stack.push(curr_node, new_key_is_large);//親ノードをスタックに記録
			curr_node = child_node;
		}
	#ifndef DISABLE_COLOR_FOR_ADD
		//赤黒バランス調整
		_balanceForAdd<ope_type>(root, stack, curr_node, new_key_is_large, new_node);
	#endif//DISABLE_COLOR_FOR_ADD
		return new_node;
	}
	//--------------------
	//赤黒木操作関数：ノード削除時の赤黒バランス調整
	template<class OPE_TYPE>
	void _balanceForRemove(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* removing_node, typename OPE_TYPE::node_type* replacing_node);
	//--------------------
	//赤黒木操作関数：ノードを削除
	//※関数内でスタックを二つ使用
	template<class OPE_TYPE>
	typename OPE_TYPE::node_type* removeNode(const typename OPE_TYPE::node_type* target_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!target_node || !root)
			return nullptr;
		stack_type stack;//スタックを用意
		node_type* removing_node = const_cast<node_type*>(searchNode<ope_type>(root, target_node, stack));//削除ノードを検索してスタックを作る
		if (!removing_node)//検索に失敗したら終了
			return nullptr;
		//削除開始
		node_type* parent_node = nullptr;//削除ノードの親ノード
		bool curr_is_large = false;//削除ノードの親ノードからの連結方向
		{
			stack_info_type* parent_info = stack.top();//親ノード参照情報を取得
			if (parent_info)
			{
				parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//親ノードを取得
				curr_is_large = parent_info->m_isLarge;//親ノードからの連結方向
			}
		}
		node_type* child_node_l = const_cast<node_type*>(ope_type::getChildL(*removing_node));//大（右）側の子ノードを取得
		node_type* child_node_s = const_cast<node_type*>(ope_type::getChildS(*removing_node));//小（左）側の子ノードを取得
		node_type* descendant_node = nullptr;//削除ノードの最大子孫ノード（削除ノードの次に小さいノード）
		node_type* replacing_node = nullptr;//削除ノードと置き換えるノード
		//削除ノードと置き換えるノードの選出処理
		//-------------------------------------------------------------------------
		//【木の説明の凡例】
		//・「(S)」は、小（左）側のノードを示す。
		//・「(L)」は、大（右）側のノードを示す。
		//・「(SL)」は、小（左）側の子の大（右）側のノードを示す。
		//　（「(LS)」[(SS)」「(SSL)」などのパターンも同様）
		//・「(null)」は、ノードがないことを示す。
		//-------------------------------------------------------------------------
		if (child_node_s && !child_node_l)
		{
			//削除ノードの小（左）側にのみ子ノードがある場合、それを置き換えノードとする
			//-------------------------------------------------------------------------
			//            .-------[removing_node]------.                               
			//   .--[replacing_node]--.             (null)                             
			// [(SS)]              [(SL)]                                              
			//-------------------------------------------------------------------------
			//                          ↓【置き換え】                                 
			//                 .--[replacing_node]--.                                  
			//               [(SS)]              [(SL)]                                
			//-------------------------------------------------------------------------
			replacing_node = child_node_s;//削除ノードと置き換えるノードをセット
		}
		else if (!child_node_s && child_node_l)
		{
			//削除ノードの大（右）側にのみ子ノードがある場合、それを置き換えノードとする
			//-------------------------------------------------------------------------
			//            .-------[removing_node]------.                               
			//          (null)              .--[replacing_node]--.                     
			//                            [(LS)]              [(LL)]                   
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                          ↓【置き換え】                                 
			//                 .--[replacing_node]--.                                  
			//               [(LS)]              [(LL)]                                
			//-------------------------------------------------------------------------
			replacing_node = child_node_l;//削除ノードと置き換えるノードをセット
		}
		else if (child_node_s && child_node_l)
		{
			//削除ノードの小（左）側と大（右）側の両方の子ノードがある場合、最大子孫ノードを置き換えノードとする
			//-------------------------------------------------------------------------
			//【ケース①】                                                             
			//            .---------------[removing_node]---------------.              
			//          [(S)]----.                                    [(L)]            
			//                   .(最大子孫)                                           
			//           .--[replacing_node]--.                                        
			//         [(SLS)]             (null)                                      
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                                 ↓【置き換え】                          
			//            .---------------[replacing_node]--------------.              
			//          [(S)]----.                                    [(L)]            
			//                   .(最大子孫)                                           
			//                [(SLS)]                                                  
			//-------------------------------------------------------------------------
			//【ケース②】                                                             
			//            .---------------[removing_node]---------------.              
			//    .--[replacing_node]--.                              [(L)]            
			//  [(SLS)]             (null)                                             
			//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			//                                 ↓【置き換え】                          
			//            .---------------[replacing_node]--------------.              
			//         [(SLS)]                                        [(L)]            
			//-------------------------------------------------------------------------
			stack_info_type* remove_info = stack.push(removing_node, false);//スタックに削除ノードを追加
			descendant_node = const_cast<node_type*>(getLargestNode<ope_type>(child_node_s, stack));//最大子孫ノードを取得
			replacing_node = descendant_node;//削除ノードと置き換えるノードをセット
			if (replacing_node != child_node_s)
			{
				//【ケース①：最大子孫ノードが削除ノードの小（左）側の子ではなく、その子孫】
				stack_info_type* descendant_parent_info = stack.top();//最大子孫ノードの親ノードを取得
				node_type* descendant_parent_node = const_cast<node_type*>(descendant_parent_info->m_nodeRef);//最大子孫ノードの親ノードを取得
				ope_type::setChildL(*descendant_parent_node, ope_type::getChildS(*replacing_node));//最大子孫ノードの親ノードの大（右）側の子ノードを変更
				ope_type::setChildS(*replacing_node, child_node_s);//置き換えノードの小（左）側の子ノードを変更
			}
			else//if (descendant_node == child_node_s)
			{
				//【ケース②：最大子孫ノードが削除ノードの小（左）側の子】
				//なにもしない
			}
			ope_type::setChildL(*replacing_node, child_node_l);//置き換えノードの大（右）側の子ノードを変更
			remove_info->m_nodeRef = replacing_node;//スタック上の削除ノード参照を置き換えノード参照に書き換え
		}
		//else//if (!child_node_s && !child_node_l)
		//{
		//	//削除ノードの小（左）側と大（右）側の両方の子ノードがない場合、置き換えノードはnullptr
		//	replacing_node = nullptr;//削除ノードと置き換えるノードをセット
		//}
		//削除ノードの置き換え処理
		ope_type::setChildL(*removing_node, nullptr);
		ope_type::setChildS(*removing_node, nullptr);
		if (!parent_node)//親ノードがない場合 → 根ノードが削除された場合である
		{
			root = replacing_node;//根ノードを置き換え
			if (!root)//根ノードがなくなったら、この時点で処理終了
				return removing_node;
		}
		else//if(parent_node)//親ノードがある場合
		{
			ope_type::setChild(*parent_node, curr_is_large, replacing_node);//親ノードの子ノードを置き換え
		}
	#ifndef DISABLE_COLOR_FOR_REMOVE
		//赤黒バランス調整
		_balanceForRemove<ope_type>(root, stack, removing_node, replacing_node);
	#endif//DISABLE_COLOR_FOR_REMOVE
		return removing_node;
	}
	//--------------------
	//赤黒木操作関数：【汎用処理】ノード左回転処理
	//-------------------------------------------------------------------------
	//              .--------------[curr_node]--------------.                  
	//       [child_node_s]                     .----[child_node_l]            
	//                                    [child_node_ls]                      
	//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	//                               ↓【左回転】                              
	//              .-------------[child_node_l]                               
	//      .-----[curr_node]----.                                             
	// [child_node_s]  [child_node_ls]                                         
	//-------------------------------------------------------------------------
	template<class OPE_TYPE>
	inline typename OPE_TYPE::node_type* _rotateL(typename OPE_TYPE::node_type* curr_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		node_type* child_node_l = const_cast<node_type*>(ope_type::getChildL(*curr_node));
		node_type* child_node_ls = const_cast<node_type*>(ope_type::getChildS(*child_node_l));
		ope_type::setChildS(*child_node_l, curr_node);
		ope_type::setChildL(*curr_node, child_node_ls);
		return child_node_l;
	};
	//--------------------
	//赤黒木操作関数：【汎用処理】ノード右回転処理
	//-------------------------------------------------------------------------
	//        .--------------[curr_node]--------------.                        
	// [child_node_s]----.                       [child_node_l]                
	//          [child_node_sl]                                                
	//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	//                            ↓【右回転】                                 
	//                      [child_node_s]------------.                        
	//                                      .----[curr_node]----.              
	//                                 [child_node_sl]  [child_node_l]         
	//-------------------------------------------------------------------------
	template<class OPE_TYPE>
	inline typename OPE_TYPE::node_type* _rotateR(typename OPE_TYPE::node_type* curr_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		node_type* child_node_s = const_cast<node_type*>(ope_type::getChildS(*curr_node));
		node_type* child_node_sl = const_cast<node_type*>(ope_type::getChildL(*child_node_s));
		ope_type::setChildL(*child_node_s, curr_node);
		ope_type::setChildS(*curr_node, child_node_sl);
		return child_node_s;
	};
	//--------------------
	//赤黒木操作関数：ノード追加時の赤黒バランス調整
	template<class OPE_TYPE>
	void _balanceForAdd(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* curr_node, bool child_is_large, typename OPE_TYPE::node_type* child_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		bool is_rotated = false;//回転処理済みフラグ
		while (true)
		{
			stack_info_type* parent_info = stack.pop();//スタックから親ノード情報取得
			if (!parent_info)
				break;
			node_type* parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//親ノード取得
			bool curr_is_large = parent_info->m_isLarge;//親ノードからの大小連結情報取得
			if (is_rotated)//前回回転処理済みなら親ノードの子ノードを連結し直す
			{
				ope_type::setChild(*parent_node, curr_is_large, curr_node);
				is_rotated = false;//回転処理済み状態リセット
			}
			//回転処理
			//-------------------------------------------------------------------------
			//【木の説明の凡例】
			//・「:B」は、黒を示す。
			//・「:R」は、赤を示す。
			//・「:+B」は、黒に変更することを示す。
			//・「:+R」は、赤に変更することを示す。
			//・「(S)」は、小（左）側のノードを示す。
			//・「(L)」は、大（右）側のノードを示す。
			//・「(SL)」は、小（左）側の子の大（右）側のノードを示す。
			//　（「(LS)」[(SS)」「(SSL)」などのパターンも同様）
			//・「(null)」は、ノードがないことを示す。
			//-------------------------------------------------------------------------
			if (ope_type::isRed(*curr_node) && ope_type::isRed(*child_node))//赤ノードが二つ連結していたら回転処理
			{
				//【共通処理】親ノードを左回転処理
				//-------------------------------------------------------------------------
				//             .-------[parent_node:B]--------.                            
				//           [(S)]                    .--[curr_node:R]--.                  
				//                                  [(LS)]       [child_node:R]            
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ↓【左回転】                                   
				//          .-----------[curr_node:R]---------.                            
				//   .--[parent_node:B]--.               [child_node:R]                    
				// [(S)]              [(LS)]                                               
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ↓【変数と色を調整】                           
				//                                                  黒に                   
				//            .--------[parent_node:R]--------.      ↓                    
				//   .------[(S):B]------.                [curr_node:+B]                   
				// [(SS)]             [(SL)]                                               
				//-------------------------------------------------------------------------
				auto rotateParentL = [&]() -> const node_type*
				{
					parent_node = _rotateL<ope_type>(parent_node);//左回転処理
					curr_is_large = true;
					curr_node = child_node;
					ope_type::setIsBlack(*curr_node);//ノードを黒にする
					//child_is_large = true;
					//child_node = nullptr;
					return parent_node;
				};
				//【共通処理】親ノードを右回転処理
				//-------------------------------------------------------------------------
				//               .-----[parent_node:B]-----.                               
				//       .--[curr_node:R]--.             [(L)]                             
				// [child_node:R]       [(SL)]                                             
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                            ↓【右回転】                                 
				//               .-------[curr_node:R]-------.                             
				//          [child_node:R]         .--[parent_node:B]--.                   
				//                               [(SL)]              [(L)]                 
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                            ↓【変数と色を調整】                         
				//               .-------[parent_node:R]-----.                             
				//           [curr_node:+B]        .------[(L):B]------.                   
				//                      ↑       [(LS)]             [(LL)]                 
				//                     黒に                                                
				//-------------------------------------------------------------------------
				auto rotateParentR = [&]() -> const node_type*
				{
					parent_node = _rotateR<ope_type>(parent_node);//右回転処理
					curr_is_large = false;
					curr_node = child_node;
					ope_type::setIsBlack(*curr_node);//ノードを黒にする
					//child_is_large = false;
					//child_node = nullptr;
					return parent_node;
				};
				//【共通処理】現在のノードを左回転処理
				//-------------------------------------------------------------------------
				//           .-------[curr_node:R]-------.                                 
				//         [(S)]                .--[child_node:R]                          
				//                            [(LS)]                                       
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ↓【左回転】                                   
				//           .-------[child_node:R]                                        
				//   .--[curr_node:R]--.                                                   
				// [(S)]            [(LS)]                                                 
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                          ↓【変数を調整】※色の調整はしない             
				//           .--------[curr_node:R]                                        
				//   .--[child_node:R]--.                                                  
				// [(SS)]            [(SL)]                                                
				//-------------------------------------------------------------------------
				auto rotateCurrL = [&]() -> const node_type*
				{
					node_type* curr_node_tmp = curr_node;
					curr_node = _rotateL<ope_type>(curr_node);//左回転処理
					child_is_large = false;
					child_node = curr_node_tmp;
					return curr_node;
				};
				//【共通処理】現在のノードを右回転処理
				//-------------------------------------------------------------------------
				//       .--------[curr_node:R]--------.                                   
				// [child_node:R]--.                 [(L)]                                 
				//              [(SS)]                                                     
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                     ↓【右回転】                                        
				//               [child_node:R]-------.                                    
				//                           .--[curr_node:R]--.                           
				//                         [(SS)]            [(L)]                         
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//                     ↓【変数を調整】※色の調整はしない                  
				//                [curr_node:R]-------.                                    
				//                          .--[child_node:R]--.                           
				//                        [(LS)]            [(LL)]                         
				//-------------------------------------------------------------------------
				auto rotateCurrR = [&]() -> const node_type*
				{
					node_type* curr_node_tmp = curr_node;
					curr_node = _rotateR<ope_type>(curr_node);//右回転処理
					child_is_large = true;
					child_node = curr_node_tmp;
					return curr_node;
				};
				//各状態に合わせた回転処理
				if (!curr_is_large && !child_is_large)
				{
					//【回転ケース[S-S]：［小（左）側の子：赤］→［小（左）側の子：赤］】
					//-------------------------------------------------------------------------
					//               .-----[parent_node:B]-----.                               
					//       .--[curr_node:R]--.             [(L)]                             
					// [child_node:R]       [(SL)]                                             
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                            ↓【親ノードを右回転】                       
					//               .-------[curr_node:R]-------.                             
					//          [child_node:R]         .--[parent_node:B]--.                   
					//                               [(SL)]              [(L)]                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                            ↓【変数と色を調整】                         
					//               .-------[parent_node:R]-----.                             
					//           [curr_node:+B]         .------[(L):B]------.                  
					//                      ↑        [(LS)]             [(LL)]                
					//                     黒に                                                
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-SS-[%d:B]→[%d:R]→[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					rotateParentR();//親ノードを右回転処理
				}
				else if (!curr_is_large &&  child_is_large)
				{
					//【回転ケース[S-L]：［小（左）側の子：赤］→［大（右）側の子：赤］】
					//-------------------------------------------------------------------------
					//                       .-----------------[parent_node:B]-------.         
					//               .--[curr_node:R]--.                           [(L)]       
					//             [(SS)]        .--[child_node:R]--.                          
					//                        [(SLS)]          [(SLL)]                         
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ↓【現在ノードを左回転】  
					//                        .----------------[parent_node:B]-------.         
					//           .------[child_node:R]------.                      [(L)]       
					//   .--[curr_node:R]--.            [(SLL)]                                
					// [(SS)]          [(SLS)]                                                 
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ↓【親ノードを右回転】    
					//                        .-----------------[child_node:R]-------.         
					//                .--[curr_node:R]--.               .--[parent_node:B]--.  
					//              [(SS)]           [(SLS)]          [(SLL)]             [(L)]
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                               ↓【変数と色を調整】      
					//                        .-----------------[parent_node:R]-----.          
					//                .--[curr_node:+B]--.                  .-----[(L):B]---.  
					//               [(SS)])        ↑ [(SL)]             [(LS)]         [(LL)]
					//                             黒に                                        
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-SL-[%d:B]→[%d:R]→[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					ope_type::setChildS(*parent_node, rotateCurrL());//現在のノードを左回転処理
					rotateParentR();//親ノードを右回転処理
				}
				else if (curr_is_large && !child_is_large)
				{
					//【回転ケ－ス[L-S]：［大（右）側の子：赤］→［小（左）側の子：赤］】
					//---------------------------------------------------------------------------------
					//             .-------[parent_node:B]----------------.                            
					//           [(S)]                       .-------[curr_node:R]-------.             
					//                               .--[child_node:R]--.              [(LL)]          
					//                             [(LSS)]          [(LSL)]                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【現在ノードを右回転】                               
					//             .-------[parent_node:B]-----------------.                           
					//           [(S)]                       .-------[child_node:R]-------.            
					//                                     [(LSS)]                .--[curr_node:R]--.  
					//                                                          [(LSL)]          [(LL)]
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【親ノードを左回転】                                 
					//           .----------[child_node:R]---------.                                   
					//   .--[parent_node:B]--.             .--[curr_node:R]--.                         
					// [(S)]             [(LSS)]         [(LSL)]          [(LL)]                       
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【変数と色を調整】                                   
					//            .--------[parent_node:R]--------.       ↓黒に                       
					//   .------[(S):B]------.              .--[curr_node:+B]--.                       
					// [(SS)]             [(SL)]          [(LSL)]           [(LL)]                     
					//---------------------------------------------------------------------------------
					printf_dbg_add("<ADD-LS-[%d:B]→[%d:R]→[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					ope_type::setChildL(*parent_node, rotateCurrR());//現在のノードを右回転処理
					rotateParentL();//親ノードを左回転処理
				}
				else//if (!curr_is_large && !child_is_large)
				{
					//【回転ケース[L-L]：［大（右）側の子：赤］→［大（右）側の子：赤］】
					//-------------------------------------------------------------------------
					//             .-------[parent_node:B]--------.                            
					//           [(S)]                    .--[curr_node:R]--.                  
					//                                  [(LS)]       [child_node:R]            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【親ノードを左回転】                         
					//          .-----------[curr_node:R]---------.                            
					//   .--[parent_node:B]--.               [child_node:R]                    
					// [(S)]              [(LS)]                                               
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【変数と色を調整】                           
					//            .--------[parent_node:R]--------.      ↓ 黒に               
					//   .------[(S):B]------.                [curr_node:+B]                   
					// [(SS)]             [(SL)]                                               
					//-------------------------------------------------------------------------
					printf_dbg_add("<ADD-LL-[%d:B]→[%d:R]→[%d:R]>", ope_type::getKey(*parent_node), ope_type::getKey(*curr_node), ope_type::getKey(*child_node));
					rotateParentL();//親ノードを左回転処理
				}
				is_rotated = true;
			}
			//親ノードに処理を移す
			child_is_large = curr_is_large;
			child_node = curr_node;
			curr_node = parent_node;
		}
		if (curr_node)
		{
			root = curr_node;//根ノードを更新
			ope_type::setIsBlack(*root);//根ノードは黒
		}
	}
	//--------------------
	//赤黒木操作関数：ノード削除時の赤黒バランス調整
	template<class OPE_TYPE>
	void _balanceForRemove(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* removing_node, typename OPE_TYPE::node_type* replacing_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		bool is_necessary_rotate = false;//回転処理必要？
		bool remove_node_is_black = ope_type::isBlack(*removing_node);
		bool replace_node_is_black = replacing_node ? ope_type::isBlack(*replacing_node) : false;
		//回転処理必要判定
		//-------------------------------------------------------------------------
		//【木の説明の凡例】
		//・「:B」は、黒を示す。
		//・「:R」は、赤を示す。
		//・「:+B」は、黒に変更することを示す。
		//・「:+R」は、赤に変更することを示す。
		//・「(S)」は、小（左）側のノードを示す。
		//・「(L)」は、大（右）側のノードを示す。
		//・「(SL)」は、小（左）側の子の大（右）側のノードを示す。
		//　（「(LS)」[(SS)」「(SSL)」などのパターンも同様）
		//・「(null)」は、ノードがないことを示す。
		//-------------------------------------------------------------------------
		if (!remove_node_is_black)//削除ノードが赤の場合
		{
			if (!replacing_node)//置き換えノードがない場合
			{
				//【判定ケース[R-n]：削除ノードが赤、置き換えノードがない】：回転処理不要
				//-------------------------------------------------------------------------
				//    .--[removing_node:R]--.                                              
				// (null)                 (null)                                           
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//             ↓【削除】                                                  
				//           (null)                                                        
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//※黒が減らないので、木に影響がない。                                     
				//-------------------------------------------------------------------------
				//【最終状態の特徴】                                                       
				//・赤黒の位置関係（条件③）も                                             
				//　黒のバランス（条件④）も崩れない。                                     
				//-------------------------------------------------------------------------
				printf_dbg_remove("<DEL-Rn-[%d:R]←(null)=END", ope_type::getKey(*removing_node));
				//is_necessary_rotate = false;//回転処理不要
			}
			else//if(replacing_node)//置き換えノードがある場合
			{
				if (!replace_node_is_black)//置き換えノードが黒の場合
				{
					//【判定ケース[R-R]：削除ノードが赤、置き換えノードが赤】：回転処理不要
					//-------------------------------------------------------------------------
					//     .---------------------[removing_node:R]-----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//        .--[replacing_node:R]--.                                         
					//     [(SLS)]                 (null)                                      
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//     .---------------------[replacing_node:R]----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※黒が減らないので、木に影響がない。                                     
					//-------------------------------------------------------------------------
					//【他のケース】                                                           
					//※置き換えノードが削除ノードの子であるケースはない。                     
					//　（赤の子が赤であってはいけないルールのため）                           
					//-------------------------------------------------------------------------
					//【最終状態の特徴】                                                       
					//・赤黒の位置関係（条件③）も                                             
					//　黒のバランス（条件④）も崩れない。                                     
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-RR-[%d:R]←[%d:R]=END>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					//is_necessary_rotate = false;//回転処理不要
				}
				else//if (replace_node_is_black)//置き換えノードが黒の場合
				{
					//【判定ケース[R-B]：削除ノードが赤、置き換えノードが黒】：回転処理必要
					//-------------------------------------------------------------------------
					//【ケース①】                                                             
					//              .-----[removing_node:R]-----.                              
					//   .--[replacing_node:B]--.             (null)                           
					// [(SS)]                [(SL)]                                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【置き換え】                                 
					//              .-----[replacing_node:B]-----.                             
					//            [(SS)]                      [(SL)]                           
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【色を調整】                                 
					//              .-----[replacing_node:+R]----.                             
					//            [(SS)]                ↑    [(SL)]                           
					//                                 赤に                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(SS)」と「(SL)」の黒のバランスは保たれるが、                         
					//　部分木全体で黒が一つ減るので、                                         
					//　親に遡って木の調整（回転処理）が必要。                                 
					//-------------------------------------------------------------------------
					//【ケース②】                                                             
					//      .-----[removing_node:R]-----.                                      
					//    (null)           .--[replacing_node:B]--.                            
					//                   [(LS)]                [(LL)]                          
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ↓【置き換え】                                       
					//      .-----[replacing_node:B]-----.                                     
					//    [(LS)]                      [(LL)]                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ↓【色を調整】                                       
					//      .-----[replacing_node:+R]----.                                     
					//    [(LS)]                ↑    [(LL)]                                   
					//                         赤に                                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(LS)」と「(LL)」の黒のバランスは保たれるが、                         
					//　部分木全体で黒が一つ減るので、                                         
					//　親に遡って木の調整（回転処理）が必要。                                 
					//-------------------------------------------------------------------------
					//【ケース③】                                                             
					//     .---------------------[removing_node:R]-----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//        .--[replacing_node:B]--.                                         
					//     [(SLS)]                 (null)                                      
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//     .---------------------[replacing_node:B]----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【色を調整】                         
					//     .---------------------[replacing_node:+R]----.                      
					//   [(S)]---------.                       ↑     [(L)]                    
					//                 .(最大子孫)            赤に                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(SLS)」とその兄弟で黒のバランスが崩れるので、                        
					//　「(SLS)」から調整（回転処理）が必要。                                  
					//-------------------------------------------------------------------------
					//【最終状態の特徴】                                                       
					//・赤黒の位置関係（条件③）は保たれるが、                                 
					//　黒のバランス（条件④）が崩れる。                                       
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-RB-[%d:R]←[%d:B]=ROT>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					is_necessary_rotate = true;//回転処理必要
					ope_type::setIsRed(*replacing_node);//置き換えノードを赤にする
					//remove_node_is_black = true;//削除ノードは黒
					//                            //※置き換え元のノードが削除されたものとして処理する
				}
			}
		}
		else//if (remove_node_is_black)//削除ノードが黒の場合
		{
			if (!replacing_node)//置き換えノードがない場合
			{
				//【判定ケース[B-n]：削除ノードが黒、置き換えノードがない】：回転処理必要
				//-------------------------------------------------------------------------
				//    .--[removing_node:B]--.                                              
				// (null)                 (null)                                           
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//             ↓【削除】                                                  
				//           (null)                                                        
				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				//※黒が一つ減るので、                                                     
				//　親に遡って木の調整（回転処理）が必要。                                 
				//-------------------------------------------------------------------------
				//【最終状態の特徴】                                                       
				//・赤黒の位置関係（条件③）は保たれるが、                                 
				//　黒のバランス（条件④）が崩れる。                                       
				//-------------------------------------------------------------------------
				printf_dbg_remove("<DEL-Bn-[%d:B]←(null)=ROT>", ope_type::getKey(*removing_node));
				is_necessary_rotate = true;//回転処理必要
			}
			else//if(replacing_node)//置き換えノードがある場合
			{
				if (!replace_node_is_black)//置き換えノードが赤の場合
				{
					//【判定ケース[B-R]：削除ノードが黒、置き換えノードが赤】：回転処理不要
					//-------------------------------------------------------------------------
					//【ケース①】                                                             
					//              .-----[removing_node:B]-----.                              
					//   .--[replacing_node:R]--.             (null)                           
					// [(SS)]                [(SL)]                                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【置き換え】                                 
					//              .-----[replacing_node:R]-----.                             
					//            [(SS)]                      [(SL)]                           
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【色を調整】                                 
					//              .-----[replacing_node:+B]----.                             
					//            [(SS)]                ↑    [(SL)]                           
					//                                 黒に                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※結果的に黒が減らないので、木に影響がない。                             
					//-------------------------------------------------------------------------
					//【ケース②】                                                             
					//      .-----[removing_node:B]-----.                                      
					//    (null)           .--[replacing_node:R]--.                            
					//                   [(LS)]                [(LL)]                          
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ↓【置き換え】                                       
					//      .-----[replacing_node:R]-----.                                     
					//    [(LS)]                      [(LL)]                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ↓【色を調整】                                       
					//      .-----[replacing_node:+B]----.                                     
					//    [(LS)]                ↑    [(LL)]                                   
					//                         黒に                                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※結果的に黒が減らないので、木に影響がない。                             
					//-------------------------------------------------------------------------
					//【ケース③】                                                             
					//     .---------------------[removing_node:B]-----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//        .--[replacing_node:R]--.                                         
					//     [(SLS)]                (null)                                       
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//     .---------------------[replacing_node:R]----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【色を調整】                         
					//     .---------------------[replacing_node:+B]----.                      
					//   [(S)]---------.                       ↑     [(L)]                    
					//                 .(最大子孫)            黒に                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※結果的に黒が減らないので、木に影響がない。                             
					//-------------------------------------------------------------------------
					//【最終状態の特徴】                                                       
					//・赤黒の位置関係（条件③）も                                             
					//　黒のバランス（条件④）も崩れない。                                     
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-BR-[%d:B]←[%d:R]=END>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					//is_necessary_rotate = false;//回転処理不要
					ope_type::setIsBlack(*replacing_node);//置き換えノードを黒にする
					//remove_node_is_black = false;//削除ノードは赤
					//                             //※置き換え元のノードが削除されたものとして処理する
				}
				else//if (replace_node_is_black)//置き換えノードが黒の場合
				{
					//【範囲ケース[B-B]：削除ノードが黒、置き換えノードが黒】：回転処理必要
					//-------------------------------------------------------------------------
					//【ケース①】                                                             
					//              .-----[removing_node:B]-----.                              
					//   .--[replacing_node:B]--.             (null)                           
					// [(SS)]                [(SL)]                                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                          ↓【置き換え】                                 
					//              .-----[replacing_node:B]-----.                             
					//            [(SS)]                      [(SL)]                           
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(SS)」と「(SL)」の黒のバランスは保たれるが、                         
					//　部分木全体で黒が一つ減るので、                                         
					//　親に遡って木の調整（回転処理）が必要。                                 
					//-------------------------------------------------------------------------
					//【ケース②】                                                             
					//      .-----[removing_node:B]-----.                                      
					//    (null)           .--[replacing_node:B]--.                            
					//                   [(LS)]              [(LL)]                            
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                    ↓【置き換え】                                       
					//      .-----[replacing_node:B]-----.                                     
					//    [(LS)]                      [(LL)]                                   
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(LS)」と「(LL)」の黒のバランスは保たれるが、                         
					//　部分木全体で黒が一つ減るので、                                         
					//　親に遡って木の調整（回転処理）が必要。                                 
					//-------------------------------------------------------------------------
					//【ケース③】                                                             
					//     .---------------------[removing_node:B]-----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//        .--[replacing_node:B]--.                                         
					//     [(SLS)]              (null)                                         
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//                                  ↓【置き換え】                         
					//     .---------------------[replacing_node:B]----.                       
					//   [(S)]---------.                             [(L)]                     
					//                 .(最大子孫)                                             
					//              [(SLS)]                                                    
					//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
					//※「(SLS)」とその兄弟で黒のバランスが崩れるので、                        
					//　「(SLS)」から調整（回転処理）が必要。                                  
					//-------------------------------------------------------------------------
					//【最終状態の特徴】                                                       
					//・赤黒の位置関係（条件③）は保たれるが、                                 
					//　黒のバランス（条件④）が崩れる。                                       
					//-------------------------------------------------------------------------
					printf_dbg_remove("<DEL-BB-[%d:B]←[%d:B]=ROT>", ope_type::getKey(*removing_node), ope_type::getKey(*replacing_node));
					is_necessary_rotate = true;//回転処理必要
				}
			}
		}
		//回転処理
		//※黒ノードが削除された時のみ回転を行う
		//-------------------------------------------------------------------------
		//【木の説明の凡例】
		//・「:B」は、黒を示す。
		//・「:R」は、赤を示す。
		//・「:?」は、黒もしくは赤を示す。
		//・「:?/n」は、黒もしくは赤、もしくは、ノードがないことを示す。
		//・「:B/n」は、黒、もしくは、ノードがないことを示す。
		//・「:-B」は、そのノード、もしくは、その子孫で、黒ノードの削除があったことを示す。
		//・「:+B」は、黒に変更することを示す。
		//・「:+R」は、赤に変更することを示す。
		//・「:+?」は、元の位置と同じ色に変更することを示す。
		//・「(S)」は、小（左）側のノードを示す。
		//・「(L)」は、大（右）側のノードを示す。
		//・「(SL)」は、小（左）側の子の大（右）側のノードを示す。
		//　（「(LS)」[(SS)」「(SSL)」などのパターンも同様）
		//・「(null)」は、ノードがないことを示す。
		//-------------------------------------------------------------------------
		if (is_necessary_rotate)
		{
			node_type* parent_node = nullptr;//親ノード
			node_type* parent_node_prev = nullptr;//前回のループ処理での親ノード
			bool curr_is_large = false;//親ノードからの連結方向
			while (true)
			{
				stack_info_type* parent_info = stack.pop();//親ノード情報を取得
				if (!parent_info)
					break;
				parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//親ノードを取得
				curr_is_large = parent_info->m_isLarge;///親ノードからの連結方向を取得
				if (parent_node_prev)//前回のループ処理での親ノードを親子連結
				{
					ope_type::setChild(*parent_node, curr_is_large, parent_node_prev);
					parent_node_prev = nullptr;//前回のループ処理での親ノードをクリア
				}
				if (is_necessary_rotate)//回転処理が必要
				{
					node_type* curr_node =//現在のノード取得 ※この側で黒ノードが一つ減少している
						parent_node ?
							const_cast<node_type*>(ope_type::getChild(*parent_node, curr_is_large)) :
							nullptr;
					node_type* sibling_node =//兄弟ノード取得
						parent_node ?
							const_cast<node_type*>(ope_type::getChild(*parent_node, !curr_is_large)) :
							nullptr;
					node_type* sibling_node_s =//兄弟ノードの小（左）側の子ノード取得
						sibling_node ?
							const_cast<node_type*>(ope_type::getChildS(*sibling_node)) :
							nullptr;
					node_type* sibling_node_l =//兄弟ノードの大（右）側の子ノード取得
						sibling_node ?
							const_cast<node_type*>(ope_type::getChildL(*sibling_node)) :
							nullptr;
					if (sibling_node)//兄弟ノードが存在する場合
					{
						if (!curr_is_large)//【ケース：［小（左）側：黒］が削除】
						{
							if (ope_type::isBlack(*sibling_node))//【ケース：削除側の兄弟が［大（右）側：黒］】
							{
								if (sibling_node_s && ope_type::isRed(*sibling_node_s))//【ケース：兄弟の子が［小（左）側の子：赤］】
								{
									//【回転ケース[S①]：［削除：小（左）側：黒］→［兄弟：大（右）側：黒］→［小（左）側の子：赤］】
									//-------------------------------------------------------------------------------------------------
									//              .----------[parent_node:?]-------------------.                                     
									//        [curr_node:-B]                      .------[sibling_node:B]------.                       
									//                                   .--[sibling_node_s:R]--.      [sibling_node_l:?/n]            
									//                                [(LSS)]                [(LSL)]                                   
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【兄弟ノードを右回転】                                          
									//              .----------[parent_node:?]-------------------.                                     
									//        [curr_node:-B]                      .------[sibling_node_s:R]------.                     
									//                                         [(LSS)]                .--[sibling_node:B]--.           
									//                                                             [(LSL)]         [sibling_node_l:?/n]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【親ノードを左回転】                                            
									//              .----------[sibling_node_s:R]----------------.                                     
									//     .--[parent_node:?]--.                   .------[sibling_node:B]------.                      
									// [curr_node:-B]       [(LSS)]             [(LSL)]                 [sibling_node_l:?/n]           
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【色を調整】                                                    
									//                                         ↓元のparent_nodeと同じ色に                             
									//              .----------[sibling_node_s:+?]----------------.                                    
									//     .--[parent_node:+B]--.                   .------[sibling_node:B]------.                     
									// [curr_node:?]       ↑[(LSS)]             [(LSL)]                 [sibling_node_l:?/n]          
									//           ↑       黒に                                                                         
									//          上の「+B」により、この「-B」が解消                                                     
									//-------------------------------------------------------------------------------------------------
									//【最終状態の特徴】                                                                               
									//・赤黒の位置関係（条件③）は保たれる。                                                           
									//・部分木の小（左）側に黒が一つ増えることで、                                                     
									//　木全体のバランス（条件④）が回復し、木の調整は完了する。                                       
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//【初期状態の考察】                                                                               
									//・「curr_node」以下の黒の数は、                                                                  
									//　「sibling_node」以下の黒の数より一つ少ない。                                                   
									//・「(LSS)」以下と「(LSL)」以下と「sibling_node_l」以下の黒の数は、それぞれ                       
									//　「sibling_node」以下の黒の数より一つ少ない。                                                   
									//・「curr_node」以下と「(LSS)」以下と「(LSL)」以下と「sibling_node_l」以下の                      
									//　黒の数は、すべて同じ。                                                                         
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//【最終状態の考察】                                                                               
									//・部分木の大（右）側の黒の数は変化しない。                                                       
									//・部分木の小（左）側の黒の数は一つ増える。                                                       
									//・木全体の黒の数は変化しない。                                                                   
									//-------------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-S1-[%d:?]→[%d:B]→[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_s));
									ope_type::setChildL(*parent_node, _rotateR<ope_type>(sibling_node));//兄弟ノードを右回転処理
									_rotateL<ope_type>(parent_node);//親ノードを左回転処理
									ope_type::setColor(*sibling_node_s, ope_type::getColor(*parent_node));//親ノードを元のparent_nodeと同じカラーに
									ope_type::setIsBlack(*parent_node);//削除側ノードを黒に
									parent_node_prev = sibling_node_s;//親ノードを記録（次のループ処理の親の子に連結する）
									is_necessary_rotate = false;//調整完了
								}
								else if (sibling_node_l && ope_type::isRed(*sibling_node_l))//【ケース：兄弟の子が［大（右）側の子：赤］】
								{
									//【回転ケース[S②]：［削除：小（左）側：黒］→［兄弟：大（右）側：黒］→［大（右）側の子：赤］】
									//-----------------------------------------------------------------------------------------
									//              .----------[parent_node:?]-------------------.                             
									//        [curr_node:-B]                      .------[sibling_node:B]------.               
									//                                      [sibling_node_s:B/n]    .--[sibling_node_l:R]--.   
									//                                                           [(LLS)]                [(LLL)]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【親ノードを左回転】                                    
									//              .-----------[sibling_node:B]----------------.                              
									//     .--[parent_node:?]--.                  .------[sibling_node_l:R]------.             
									// [curr_node:-B] [sibling_node_s:B/n]     [(LLS)]                        [(LLL)]          
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                               ↓【色を調整】                                            
									//                                        ↓元のparent_nodeと同じ色に                      
									//              .-----------[sibling_node:+?]----------------.                             
									//     .--[parent_node:+B]--.                 .------[sibling_node_l:+B]-----.             
									// [curr_node:?]  [sibling_node_s:B/n]     [(LLS)]                   ↑   [(LLL)]          
									//           ↑       ↑黒に                                        黒に                   
									//          上の「+B」により、この「-B」が解消                                             
									//-----------------------------------------------------------------------------------------
									//【最終状態の特徴】                                                                       
									//・赤黒の位置関係（条件③）は保たれる。                                                   
									//・部分木の小（左）側に黒が一つ増えることで、                                             
									//　木全体のバランス（条件④）が回復し、木の調整は完了する。                               
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//【初期状態の考察】                                                                       
									//・「curr_node」以下の黒の数は、                                                          
									//　「sibling_node」以下の黒の数より一つ少ない。                                           
									//・「(LLS)」以下と「(LLL)」以下と「sibling_node_s」以下の黒の数は、それぞれ               
									//　「sibling_node」以下の黒の数より一つ少ない。                                           
									//・「curr_node」以下と「(LLS)」以下と「(LLL)」以下と「sibling_node_s」以下の              
									//　黒の数は、すべて同じ。                                                                 
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//【最終状態の考察】                                                                       
									//・部分木の大（右）側の黒の数は変化しない。                                               
									//・部分木の小（左）側の黒の数は一つ増える。                                               
									//・木全体の黒の数は変化しない。                                                           
									//-----------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-S2-[%d:?]→[%d:B]→[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_l));
									_rotateL<ope_type>(parent_node);//親ノードを左回転処理
									ope_type::setColor(*sibling_node, ope_type::getColor(*parent_node));//親ノードを元のparent_nodeと同じカラーに
									ope_type::setIsBlack(*parent_node);//削除側ノードを黒に
									ope_type::setIsBlack(*sibling_node_l);//兄弟ノードを黒に
									parent_node_prev = sibling_node;//親ノードを記録（次のループ処理の親の子に連結する）
									is_necessary_rotate = false;//調整完了
								}
								else//【ケース：兄弟の子が大小（左右）両方とも黒もしくはヌル】
								{
									if (ope_type::isRed(*parent_node))//【ケース：削除ノードの親が赤】
									{
										//【回転ケース[S③a]：［削除：小（左）側：黒］→［親：赤］→［兄弟：大（右）側：黒］→［大小（左右）両側の子：赤以外］】
										//------------------------------------------------------------------------------
										//       .----------[parent_node:R]-------------------.                         
										// [curr_node:-B]                      .------[sibling_node:B]------.           
										//                               [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ------
										//                        ↓【色を調整】                                        
										//       .----------[parent_node:+B]-------------------.   ↓赤に               
										// [curr_node:?]             黒に↑   .------[sibling_node:+R]------.           
										//           ↑                  [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//           上の「+B」により、この「-B」が解消                                 
										//------------------------------------------------------------------------------
										//【最終状態の特徴】                                                            
										//・赤黒の位置関係（条件③）は保たれる。                                        
										//・部分木の大（右）側の黒が一つ減ることで、                                    
										//　部分木のバランスが回復し、                                                  
										//　更に、部分木の根に黒が一つ増えることで、                                    
										//　木全体のバランス（条件④）が回復し、木の調整は完了する。                    
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
										//【初期状態の考察】                                                            
										//・「curr_node」以下の黒の数は、                                               
										//　「sibling_node」以下の黒の数より一つ少ない。                                
										//・「sibling_node_s」以下と「sibling_node_l」以下の黒の数は、                  
										//　それぞれ「sibling_node」以下の黒の数より一つ少ない。                        
										//・「curr_node」以下と「sibling_node_s」以下と「sibling_node_l」以下の         
										//　黒の数は、すべて同じ。                                                      
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
										//【最終状態の考察】                                                            
										//・部分木の大（右）側の黒の数は±０。                                          
										//・部分木の小（左）側の黒の数は一つ増える。                                    
										//・木全体の黒の数は変化しない。                                                
										//------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-S3a-[%d:R]→[%d:B]→[*:B/n]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setIsBlack(*parent_node);//親ノードを黒に
										ope_type::setIsRed(*sibling_node);//兄弟ノードを赤に
										parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
										is_necessary_rotate = false;//調整完了
									}
									else//if (ope_type::isBlack(*parent_node))//【ケース：削除ノードの親が黒】
									{
										//【回転ケース[S③b]：［削除：小（左）側：黒］→［親：黒］→［兄弟：大（右）側：黒］→［大小（左右）両側の子：赤以外］】
										//-------------------------------------------------------------------------------------
										//              .----------[parent_node:B]-------------------.                         
										//        [curr_node:-B]                      .------[sibling_node:B]------.           
										//                                      [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                               ↓【色を調整】                                        
										//              .----------[parent_node:B]--------------------.   ↓赤に               
										//        [curr_node:?]                      .------[sibling_node:+R]------.           
										//                  ↑                  [sibling_node_s:B/n]    .--[sibling_node_l:B/n]
										//                  右の「+R」により、この「-B」が解消（右側も黒が減ったので）         
										//-------------------------------------------------------------------------------------
										//【最終状態の特徴】                                                                   
										//・赤黒の位置関係（条件③）は保たれる。                                               
										//・部分木の大（右）側の黒が一つ減ることで、                                           
										//　部分木のバランスが回復するが、                                                     
										//　部分木全体では黒が一つ減った状態のため、                                           
										//　親に遡って木の調整が必要。                                                         
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//【初期状態の考察】                                                                   
										//・「curr_node」以下の黒の数は、                                                      
										//　「sibling_node」以下の黒の数より一つ少ない。                                       
										//・「sibling_node_s」以下と「sibling_node_l」以下の黒の数は、                         
										//　それぞれ「sibling_node」以下の黒の数より一つ少ない。                               
										//・「curr_node」以下と「sibling_node_s」以下と「sibling_node_l」以下の                
										//　黒の数は、すべて同じ。                                                             
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//【最終状態の考察】                                                                   
										//・部分木の大（右）側の黒の数は一つ減る。                                             
										//・部分木の小（左）側の黒の数は変わらない。                                           
										//・部分木のバランスは取れるが、                                                       
										//　部分木全体で黒の数が一つ少ない。                                                   
										//-------------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-S3b-[%d:B]→[%d:B]→[*:B/n]=NEXT>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setIsRed(*sibling_node);//兄弟ノードを赤に
										parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
										//is_necessary_rotate = true;//調整続行
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//【ケース：削除側の兄弟が［大（右）側：赤］】
							{
								//※兄弟が赤であるため、「条件③」により、必然的に親は黒になる
								//【回転ケース[S④]：［削除：小（左）側：黒］→［親：黒］→［兄弟：大（右）側：赤］】
								//--------------------------------------------------------------------------------------
								//                 .--------------[parent_node:B]---------------.                       
								//        [curr_node:-B]                         .------[sibling_node:R]------.         
								//                                         [sibling_node_s:B/n]     [sibling_node_l:B/n]
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                      ↓【親ノードを左回転】                          
								//                 .--------------[sibling_node:R]--------------.                       
								//      .----[parent_node:B]----.                      [sibling_node_l:B/n]             
								// [curr_node:-B]   [sibling_node_s:B/n]                                                
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                      ↓【色を調整】                                  
								//                 .--------------[sibling_node:+B]-------------.                       
								//      .----[parent_node:+R]----.              ↑黒に [sibling_node_l:B/n]             
								// [curr_node:-B]   [sibling_node_s:B/n]                                                
								//            ↑          ↑赤に（curr_nodeが赤だと、「条件③」が崩れる）               
								//            この「-B」は解消されない                                                  
								//--------------------------------------------------------------------------------------
								//【最終状態の特徴】                                                                    
								//・赤黒の位置関係（条件③）が崩れる可能性があるが、                                    
								//　この後の処理で必ずcurr_nodeの親が黒になるので問題ない。                             
								//・部分木のバランスは回復しない。                                                      
								//・この状態のparent_nodeとcurr_node部分木に対して、                                    
								//　再帰的に【ケース[①～③]】を実行すると、部分木の                                    
								//　バランスが保たれる。                                                                
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//【初期状態の考察】                                                                    
								//・「curr_node」以下の黒の数は、                                                       
								//　「sibling_node_s」／「sibling_node_l」以下の黒の数より一つ少ない。                  
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//【最終状態の考察】                                                                    
								//・部分木の大（右）側の黒の数は変化しない。                                            
								//・部分木の小（左）側はバランスが崩れるため、                                          
								//　さらにその部分木でバランスを調整する。                                              
								//--------------------------------------------------------------------------------------
								printf_dbg_remove("<ROT-S4-[%d:B]→[%d:R]→[*:B/n]=RETRY>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
								_rotateL<ope_type>(parent_node);//親ノードを左回転処理
								ope_type::setIsRed(*parent_node);//削除側ノードを赤に
								ope_type::setIsBlack(*sibling_node);//親ノードを黒に
								stack_info_type* ancestor_info = stack.top();//スタックから現在の親情報を取得
								const bool parent_is_large = ancestor_info ? ancestor_info->m_isLarge : false;//親の親からの連結方向
								if (ancestor_info)
								{
									node_type* ancestor_node = const_cast<node_type*>(ancestor_info->m_nodeRef);
									ope_type::setChild(*ancestor_node, parent_is_large, sibling_node);//親の親に新しい親を連結
								}
								stack.push(sibling_node, false);//もう一度同じ部分木を回転操作するために、親ノードをスタックにプッシュ
								stack.push(parent_node, false);//もう一度同じ部分木を回転操作するために、親ノードをスタックにプッシュ
								parent_node_prev = curr_node;//親ノードを記録（次のループ処理の親の子に連結する）
								//is_necessary_rotate = true;//再帰的に調整続行
							}
						}
						else//if (curr_is_large)//【ケース：［大（右）側：黒］が削除】
						{
							if (ope_type::isBlack(*sibling_node))//【ケース：削除側の兄弟が［小（左）側：黒］】
							{
								if (sibling_node_l && ope_type::isRed(*sibling_node_l))//【ケース：兄弟の子が［大（右）側の子：赤］】
								{
									//【回転ケース[L①]：［削除：大（右）側：黒］→［兄弟：小（左）側：黒］→［大（右）側の子：赤］】
									//--------------------------------------------------------------------------------------------
									//                               .-------------------[parent_node:?]----------.               
									//                 .------[sibling_node:B]------.                      [curr_node:-B]         
									//       [sibling_node_s:?/n]      .--[sibling_node_l:R]--.                                   
									//                              [(SLS)]                [(SLL)]                                
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ↓【兄弟ノードを左回転】           
									//                               .-------------------[parent_node:?]----------.               
									//                 .------[sibling_node_l:R]------.                    [curr_node:-B]         
									//           .--[sibling_node:B]--.            [(SLL)]                                        
									// [sibling_node_s:?/n]        [(SLS)]                                                        
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ↓【親ノードを右回転】             
									//                               .-----------------[sibling_node_l:R]---------.               
									//                 .------[sibling_node:B]------.                .--[parent_node:?]--.        
									//           [sibling_node_s:?/n]            [(SLS)]          [(SLL)]          [curr_node:-B] 
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
									//                                                         ↓【色を調整】                     
									//                                                                 ↓元のparent_nodeと同じ色に
									//                               .-----------------[sibling_node_l:+?]--------.  ↓黒に       
									//                 .------[sibling_node:B]------.                .--[parent_node:+B]--.       
									//           [sibling_node_s:?/n]            [(SLS)]          [(SLL)]          [curr_node:?]  
									//                                                     上の「+B」により、この「-B」が解消↑   
									//--------------------------------------------------------------------------------------------
									//※調整完了。                                                                                
									//※説明は省略。【ケース[S①]】と同じ                                                         
									//--------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-L1-[%d:?]→[%d:B]→[%d:R]=END>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_l));
									ope_type::setChildS(*parent_node, _rotateL<ope_type>(sibling_node));//兄弟ノードを左回転処理
									_rotateR<ope_type>(parent_node);//親ノードを右回転処理
									ope_type::setColor(*sibling_node_l, ope_type::getColor(*parent_node));//親ノードを元のparent_nodeと同じカラーに
									ope_type::setIsBlack(*parent_node);//削除側ノードを黒に
									parent_node_prev = sibling_node_l;//親ノードを記録（次のループ処理の親の子に連結する）
									is_necessary_rotate = false;//調整完了
								}
								else if (sibling_node_s && ope_type::isRed(*sibling_node_s))//【ケース：兄弟の子が［小（左）側の子：赤］】
								{
									//【回転ケース[L②]：［削除：大（右）側：黒］→［兄弟：小（左）側：黒］→［小（左）側の子：赤］】
									//---------------------------------------------------------------------------------------------
									//                               .-------------------[parent_node:?]----------.                
									//                 .------[sibling_node:B]------.                      [curr_node:-B]          
									//    .--[sibling_node_s:R]--.      [sibling_node_l:B/n]                                       
									// [(SLS)]                [(SLL)]                                                              
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
									//                                                        ↓【親ノードを右回転】               
									//                               .------------------[sibling_node:R]----------.                
									//                 .------[sibling_node_s:R]------.                .--[parent_node:?]--.       
									//              [(SLS)]                        [(SLL)]    [sibling_node_l:B/n]   [curr_node:-B]
									//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -                    
									//                                                        ↓【色を調整】                       
									//                                                                ↓元のparent_nodeと同じ色に  
									//                               .------------------[sibling_node:+?]---------.   ↓黒に       
									//                 .------[sibling_node_s:+B]-----.               .--[parent_node:+B]--.       
									//              [(SLS)]                   ↑   [(SLL)]    [sibling_node_l:B/n]   [curr_node:?] 
									//                                       黒に            上の「+B」により、この「-B」が解消↑  
									//---------------------------------------------------------------------------------------------
									//※調整完了。                                                                                 
									//※説明は省略。【ケース[S②]】と同じ                                                          
									//---------------------------------------------------------------------------------------------
									printf_dbg_remove("<ROT-L2-[%d:?]→[%d:B]→[%d:R]=OK>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node), ope_type::getKey(*sibling_node_s));
									_rotateR<ope_type>(parent_node);//親ノードを右回転処理
									ope_type::setColor(*sibling_node, ope_type::getColor(*parent_node));//親ノードを元のparent_nodeと同じカラーに
									ope_type::setIsBlack(*parent_node);//削除側ノードを黒に
									ope_type::setIsBlack(*sibling_node_s);//兄弟ノードを黒に
									parent_node_prev = sibling_node;//親ノードを記録（次のループ処理の親の子に連結する）
									is_necessary_rotate = false;//調整完了
								}
								else//【ケース：兄弟の子が大小（左右）両方とも黒もしくはヌル】
								{
									if (ope_type::isRed(*parent_node))//【ケース：削除ノードの親が赤】
									{
										//【回転ケース[L③a]：［削除：大（右）側：黒］→［親：赤］→［兄弟：小（左）側：黒］→［大小（左右）両側の子：赤以外］】
										//---------------------------------------------------------------------------------
										//                       .-------------------[parent_node:R]----------.            
										//         .------[sibling_node:B]------.                      [curr_node:-B]      
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]                                   
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                                                 ↓【色を調整】                  
										//                       .-------------------[parent_node:+B]---------.            
										//         .------[sibling_node:+B]-----.                 ↑   [curr_node:?]       
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]         黒に			 ↑        
										//                              ↑赤に                         上の「 + B」により、
										//                                                             この「 - B」が解消  
										//---------------------------------------------------------------------------------
										//※調整完了。                                                                     
										//※説明は省略。【ケース[S③a]】と同じ                                             
										//---------------------------------------------------------------------------------
										printf_dbg_remove("<ROT-L3a-[%d:R]→[%d:B]→[*:B/n]=OK>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setIsBlack(*parent_node);//親ノードを黒に
										ope_type::setIsRed(*sibling_node);//兄弟ノードを赤に
										parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
										is_necessary_rotate = false;//調整完了
									}
									else//if (ope_type::isBlack(*parent_node))//【ケース：削除ノードの親が黒】
									{
										//【回転ケース[L③b]：［削除：大（右）側：黒］→［親：黒］→［兄弟：小（左）側：黒］→［大小（左右）両側の子：赤以外］】
										//---------------------------------------------------------------------------
										//                       .-------------------[parent_node:B]----------.      
										//         .------[sibling_node:B]------.                      [curr_node:-B]
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]                             
										//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
										//                                                 ↓【色を調整】            
										//                       .-------------------[parent_node:B]---------.       
										//         .------[sibling_node:+R]-----.                      [curr_node:?] 
										// [sibling_node_s:B/n]     [sibling_node_l:B/n]       左の「+R」により、↑  
										//                              ↑赤に                 この「-B」が解消      
										//                                                   （左側も黒が減ったので）
										//---------------------------------------------------------------------------
										//※調整続行。                                                               
										//※説明は省略。【ケース[S③b]】と同じ                                       
										//---------------------------------------------------------------------------
										printf_dbg_remove("<ROT-L3b-[%d:B]→[%d:B]→[*:B/n]=NEXT>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
										ope_type::setIsRed(*sibling_node);//兄弟ノードを赤に
										parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
										//is_necessary_rotate = true;//調整続行
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//【ケース：削除側の兄弟が［小（左）側：赤］】
							{
								//※兄弟が赤であるため、「条件③」により、必然的に親は黒になる
								//【回転ケース[L④]：［削除：大（右）側：黒］→［親：黒］→［兄弟：小（左）側：赤］】
								//--------------------------------------------------------------------------------------------------------
								//                         .-------------------[parent_node:B]----------.                                 
								//           .------[sibling_node:R]------.                      [curr_node:-B]                           
								// [sibling_node_s:B/n]        [sibling_node_l:B/n]                                                       
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                                   ↓【親ノードを右回転】                               
								//                         .------------------[sibling_node:R]----------.                                 
								//                 [sibling_node_s:B/n]                       .--[parent_node:B]--.                       
								//                                                    [sibling_node_l:B/n]   [curr_node:-B]               
								//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
								//                                                   ↓【色を調整】                                       
								//                         .-----------------[sibling_node:+B]----------.     ↓赤に（curr_nodeが赤だと、 
								//                 [sibling_node_s:B/n]                黒に↑ .--[parent_node:+R]--.  「条件③」が崩れる）
								//                                                    [sibling_node_l:B/n]   [curr_node:-B]               
								//                                                                                      ↑                
								//                                                                 この「-B」は解消されない               
								//--------------------------------------------------------------------------------------------------------
								//※再帰的に調整続行。                                                                                    
								//※説明は省略。【ケース[S④]】と同じ                                                                     
								//--------------------------------------------------------------------------------------------------------
								printf_dbg_remove("<ROT-L4-[%d:B]→[%d:R]→[*:B/n]=RETRY>", ope_type::getKey(*parent_node), ope_type::getKey(*sibling_node));
								_rotateR<ope_type>(parent_node);//親ノードを右回転処理
								ope_type::setIsRed(*parent_node);//削除側ノードを赤に
								ope_type::setIsBlack(*sibling_node);//親ノードを黒に
								stack_info_type* ancestor_info = stack.top();//スタックから現在の親情報を取得
								const bool parent_is_large = ancestor_info ? ancestor_info->m_isLarge : false;//親の親からの連結方向
								if (ancestor_info)
								{
									node_type* ancestor_node = const_cast<node_type*>(ancestor_info->m_nodeRef);
									ope_type::setChild(*ancestor_node, parent_is_large, sibling_node);//親の親に新しい親を連結
								}
								stack.push(sibling_node, true);//もう一度同じ部分木を回転操作するために、親ノードをスタックにプッシュ
								stack.push(parent_node, true);//もう一度同じ部分木を回転操作するために、親ノードをスタックにプッシュ
								parent_node_prev = curr_node;//親ノードを記録（次のループ処理の親の子に連結する）
								//is_necessary_rotate = true;//再帰的に調整続行
							}
						}
					}
					else//if (!sibling_node)//兄弟ノードが存在しない場合
					{
						//黒ノード（削除対象ノード）の兄弟ノードが存在しないことは本来ありえない
						//※「条件④」により、根から葉までのあらゆる経路で黒の数は一定のため、
						//　黒ノードを削除した場合、必ず兄弟ノードもしくはその子孫に黒がいる。
						printf_dbg_remove("【赤黒木にバグあり！】黒ノード（削除）の兄弟ノードが存在しない\n");
						assert(sibling_node != nullptr);
						parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
					}
				}
				else//if (!is_necessary_rotate)//回転処理が不要
				{
					parent_node_prev = parent_node;//親ノードを記録（次のループ処理の親の子に連結する）
				}
			}
			if (parent_node_prev)
			{
				root = parent_node_prev;
				ope_type::setIsBlack(*root);
			}
		}
	}

	//----------------------------------------
	//赤黒木コンテナ
	//※根ノードを持つのみ
	//※std::mapを模した構造
	template<class OPE_TYPE>
	class container
	{
	public:
		//型
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//--------------------
		//イテレータ
		class iterator;
		typedef const iterator const_iterator;
		class iterator : public std::iterator<std::bidirectional_iterator_tag, node_type>
		{
			friend class container;
		public:
			//キャストオペレータ
			operator const node_type() const { return *m_node; }
			operator node_type&(){ return *m_node; }
			operator key_type() const { return ope_type::getKey(*m_node); }
		public:
			//オペレータ
			const node_type& operator*() const { return *m_node; }
			node_type& operator*(){ return *m_node; }
			const node_type* operator->() const { return m_node; }
			node_type* operator->(){ return m_node; }
			//比較オペレータ
			bool operator==(const_iterator& rhs) const
			{
				return m_node == nullptr && rhs.m_node == nullptr ? true :
				       m_node == nullptr || rhs.m_node == nullptr ? false :
				       ope_type::eq(*m_node, *rhs);
			}
			bool operator!=(const_iterator& rhs) const
			{
				return m_node == nullptr && rhs.m_node == nullptr ? false :
				       m_node == nullptr || rhs.m_node == nullptr ? true :
					   ope_type::ne(*m_node, *rhs);
			}
			bool operator>(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
				       ope_type::gt(*m_node, *rhs);
			}
			bool operator>=(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
				       ope_type::ge(*m_node, *rhs);
			}
			bool operator<(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
				       ope_type::lt(*m_node, *rhs);
			}
			bool operator<=(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
				       ope_type::le(*m_node, *rhs);
			}
			//演算オペレータ
			const_iterator& operator++() const
			{
				m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
				return *this;
			}
			const_iterator& operator--() const
			{
				m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
				return *this;
			}
			iterator& operator++()
			{
				m_node = const_cast<node_type*>(getNextNode<ope_type>(m_node, m_stack));
				return *this;
			}
			iterator& operator--()
			{
				m_node = const_cast<node_type*>(getPrevNode<ope_type>(m_node, m_stack));
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
			//コピーオペレータ
			iterator& operator=(const_iterator& rhs)
			{
				m_stack = rhs.m_stack;
				m_node = rhs.m_node;
			}
		public:
			//リセット
			void reset() const
			{
				m_stack.reset();
				m_node = nullptr;
			}
		public:
			//コピーコンストラクタ
			iterator(const_iterator& obj) :
				m_stack(obj.m_stack),
				m_node(obj.m_node)
			{}
			//コンストラクタ
			iterator() :
				m_stack(),
				m_node(nullptr)
			{}
			iterator(const node_type* node, const stack_type& stack) :
				m_stack(*const_cast<stack_type*>(&stack)),
				m_node(const_cast<node_type*>(node))
			{}
			//デストラクタ
			~iterator()
			{}
		protected:
			//フィールド
			mutable stack_type m_stack;//スタック
			mutable node_type* m_node;//現在のノード
		};
		//--------------------
		//リバースイテレータ
		//※begin(), end() の要件が若干特殊なので、
		//　std::reverse_iterator<iterator>を使わずに実装（偽装）する。
		//　中身はoperatorの+と-を逆転しているだけで、通常のイテレータと同じ。
		class reverse_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		class reverse_iterator : public iterator
		{
		public:
			//演算オペレータ
			const_reverse_iterator& operator++() const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator--());
			}
			const_reverse_iterator& operator--() const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator++());
			}
			reverse_iterator& operator++()
			{
				return static_cast<reverse_iterator&>(iterator::operator--());
			}
			reverse_iterator& operator--()
			{
				return static_cast<reverse_iterator&>(iterator::operator++());
			}
			const_reverse_iterator operator++(int) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator--(0));
			}
			const_reverse_iterator operator--(int) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator++(0));
			}
			reverse_iterator operator++(int)
			{
				return static_cast<reverse_iterator&>(iterator::operator--(0));
			}
			reverse_iterator operator--(int)
			{
				return static_cast<reverse_iterator&>(iterator::operator++(0));
			}
			const_reverse_iterator& operator+=(const int val) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator-=(val));
			}
			const_reverse_iterator& operator-=(const int val) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator+=(val));
			}
			reverse_iterator& operator+=(const int val)
			{
				return static_cast<reverse_iterator&>(iterator::operator-=(val));
			}
			reverse_iterator& operator-=(const int val)
			{
				return static_cast<reverse_iterator&>(iterator::operator+=(val));
			}
			const_reverse_iterator operator+(const int val) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator-(val));
			}
			const_reverse_iterator operator-(const int val) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator+(val));
			}
			reverse_iterator operator+(const int val)
			{
				return static_cast<reverse_iterator&>(iterator::operator-(val));
			}
			reverse_iterator operator-(const int val)
			{
				return static_cast<reverse_iterator&>(iterator::operator+(val));
			}
		public:
			//コピーコンストラクタ
			reverse_iterator(const_iterator& obj) :
				iterator(obj)
			{}
			//コンストラクタ
			reverse_iterator() :
				iterator()
			{}
			reverse_iterator(const node_type* node, const stack_type& stack) :
				iterator(node, stack)
			{}
			//デストラクタ
			~reverse_iterator()
			{}
		};
	public:
		//メソッド：イテレータ系
		const_iterator& _begin(const_iterator& ite) const
		{
			ite.m_node = const_cast<node_type*>(getSmallestNode<ope_type>(m_root, ite.m_stack));
			return ite;
		}
		const_iterator& _end(const_iterator& ite) const
		{
			ite.reset();
			return ite;
		}
		const_iterator cbegin() const
		{
			iterator ite;
			return _begin(ite);
		}
		const_iterator cend() const
		{
			iterator ite;
			return _end(ite);
		}
		const_iterator begin() const
		{
			iterator ite;
			return _begin(ite);
		}
		const_iterator end() const
		{
			iterator ite;
			return _end(ite);
		}
		iterator begin()
		{
			iterator ite;
			return _begin(ite);
		}
		iterator end()
		{
			iterator ite;
			return _end(ite);
		}
		//メソッド：リバースイテレータ系
		const_reverse_iterator& _rbegin(const_reverse_iterator& ite) const
		{
			ite.m_node = const_cast<node_type*>(getLargestNode<ope_type>(m_root, ite.m_stack));
			return ite;
		}
		const_reverse_iterator& _rend(const_reverse_iterator& ite) const
		{
			ite.reset();
			return ite;
		}
		const_reverse_iterator crbegin() const
		{
			reverse_iterator ite;
			return _rbegin(ite);
		}
		const_reverse_iterator crend() const
		{
			reverse_iterator ite;
			return _rend(ite);
		}
		const_reverse_iterator rbegin() const
		{
			reverse_iterator ite;
			return _rbegin(ite);
		}
		const_reverse_iterator rend() const
		{
			reverse_iterator ite;
			return _rend(ite);
		}
		reverse_iterator rbegin()
		{
			reverse_iterator ite;
			return _rbegin(ite);
		}
		reverse_iterator rend()
		{
			reverse_iterator ite;
			return _rend(ite);
		}
		//メソッド：容量系
		//std::size_t max_size() const { return (不定); }
		//std::size_t capacity() const { return (不定); }
		std::size_t size() const { return countNodes<ope_type>(m_root); }
		bool empty() const { return m_root == nullptr; }
		int depth_max() const { return getDepthMax<ope_type>(m_root); }
		//メソッド：要素アクセス系
		//※std::mapと異なり、ノードのポインタを返す
		inline const node_type* _at(const key_type key) const
		{
			stack_type stack;
			return searchNode<ope_type>(m_root, key, stack, FOR_MATCH);
		}
		const node_type* at(const key_type key) const { return _at(key); }
		node_type* at(const key_type key){ return const_cast<node_type*>(_at(key)); }
		const node_type* operator[](const key_type key) const { return _at(key); }
		node_type* operator[](const key_type key){ return const_cast<node_type*>(_at(key)); }
		//メソッド：追加／削除系
		//※std::mapと異なり、ノードを直接指定し、結果をbool型で受け取る
		//※要素のメモリ確保／削除を行わない点に注意
		node_type* insert(const node_type& node){ return addNode<ope_type>(const_cast<node_type*>(&node), m_root); }
		node_type* erase(const node_type& node){ return removeNode<ope_type>(&node, m_root); }
		node_type* erase(const key_type key){ return removeNode<ope_type>(at(key), m_root); }
		node_type* clear(){ node_type* root = m_root; m_root = nullptr; return root; }
		//メソッド：検索系
		//※lower_bound(), upper_bound()には非対応
		//※代わりに、find_nearestに対応
		const_iterator& _find(const_iterator& ite, const key_type key, const match_type_t type = FOR_MATCH) const
		{
			ite.m_node = const_cast<node_type*>(searchNode<ope_type>(m_root, key, ite.m_stack, type));
			return ite;
		}
		const_iterator find(const key_type key, const match_type_t type = FOR_MATCH) const
		{
			const_iterator ite;
			return _find(ite, key, type);
		}
		iterator find(const key_type key, const match_type_t type = FOR_MATCH)
		{
			iterator ite;
			return _find(ite, key, type);
		}
		std::size_t count(const key_type key) const { return countNodes<ope_type>(m_root, key); }
		const_iterator& _equal_range(const_iterator& ite, const key_type key) const
		{
			ite.m_node = const_cast<node_type*>(searchNode<ope_type>(m_root, key, ite.m_stack, FOR_MATCH));
			while (ite.m_node && ope_type::getKey(*ite) == key)
				++ite;
			return ite;
		}
		const_iterator equal_range(const key_type key) const
		{
			const_iterator ite;
			return _equal_range(ite, key);
		}
		iterator equal_range(const key_type key)
		{
			iterator ite;
			return _equal_range(ite, key);
		}
		//その他
		const node_type* root() const { return m_root; }//根ノードを取得
		node_type*& root_ref(){ return m_root; }//根ノードの参照を取得
	public:
		//コピーコンストラクタ
		container(const container& con) :
			m_root(con.m_root)
		{}
		//コンストラクタ
		container() :
			m_root(nullptr)
		{}
		//デストラクタ
		~container()
		{}
	private:
		//フィールド
		node_type* m_root;//根ノード
	};
}//namespace rb_tree

//--------------------------------------------------------------------------------
//赤黒木テスト

#include <algorithm>//for_each用
#include <random>//C++11 std::random用
#include <chrono>//C++11 時間計測用
#include <type_traits>//C++11 時間計測用

//----------------------------------------
//テストデータ
struct data_t
{
	//コンストラクタ
	data_t(const int key) :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_key(key)
	{}
	data_t() :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_key(0)
	{}

	//フィールド
	const data_t* m_nodeS;//小（左）側のノード
	const data_t* m_nodeL;//大（右）側のノード
	bool m_isBlack;//ノードの色
	int m_key;//キー
};
//----------------------------------------
//テストデータ操作クラス
struct ope_t : public rb_tree::base_ope_t<ope_t, data_t, int, TEST_DATA_STACK_DEPTH_MAX>
{
	//子ノードを取得
	inline static const node_type* getChildL(const node_type& node){ return node.m_nodeL; }//大（右）側
	inline static const node_type* getChildS(const node_type& node){ return node.m_nodeS; }//小（左）側
	//子ノードを変更
	inline static void setChildL(node_type& node, const node_type* child){ node.m_nodeL = child; }//大（右）側
	inline static void setChildS(node_type& node, const node_type* child){ node.m_nodeS = child; }//小（左）側

	//ノードの色を取得
	inline static color_t getColor(const node_type& node){ return node.m_isBlack ? BLACK : RED; }
	//ノードの色を変更
	inline static void setColor(node_type& node, const color_t color){ node.m_isBlack = color == BLACK; }
	
	//キーを取得
	inline static key_type getKey(const node_type& node){ return node.m_key; }

	//キーを比較
	//※デフォルトのままとする
	//Return value:
	//  0 ... lhs == rhs
	//  1 ... lhs > rhs
	// -1 ... lhs < rhs
	//inline static int compareKey(const key_type lhs, const key_type rhs);
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
#ifdef PRINT_TEST_DATA_SEARCH
template<typename... Tx>
inline int printf_dbg_search(const char* fmt, Tx... args)
{
	return printf(fmt, args...);
}
#else//PRINT_TEST_DATA_SEARCH
inline int printf_dbg_search(const char* fmt, ...){ return 0; }
#endif//PRINT_TEST_DATA_SEARCH

//----------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	//型
	typedef rb_tree::container<ope_t> container_t;
	typedef container_t::iterator iterator;
	typedef container_t::const_iterator const_iterator;
	typedef container_t::reverse_iterator reverse_iterator;
	typedef container_t::const_reverse_iterator const_reverse_iterator;
	
	//赤黒木コンテナ
	container_t con;

	//処理時間計測開始
	const std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point prev_time = begin_time;

	//データを登録
	auto regList = [&con]()
	{
		printf("--- Make table ---\n");
		auto insert = [&con](const int key)
		{
			data_t* new_node = new data_t(key);
			printf_detail("[%2d] ", new_node->m_key);
			con.insert(*new_node);
			rb_tree::printf_dbg_add("\n");
		};
	#ifdef REGIST_TEST_DATA_SEQUENTIALLY
		//シーケンシャルにデータ登録
		for (int i = 0; i < TEST_DATA_REG_NUM; ++i)
		{
			const int key = TEST_DATA_KEY_MIN + i % (TEST_DATA_KEY_MAX - TEST_DATA_KEY_MIN + 1);
			insert(key);
		}
	#else//REGIST_TEST_DATA_SEQUENTIALLY
	#ifndef TEST_DATA_REGISTRATION_LIST
		//ランダムにデータ登録
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_KEY_MIN, TEST_DATA_KEY_MAX);
		for (int i = 0; i < TEST_DATA_REG_NUM; ++i)
			insert(rand_dist(rand_engine));
	#else//TEST_DATA_REGISTRATION_LIST
		//固定順にデータ登録
		const int key_list[] = TEST_DATA_REGISTRATION_LIST;
		for (int key : key_list)
			insert(key);
	#endif//TEST_DATA_REGISTRATION_LIST
	#endif//REGIST_TEST_DATA_SEQUENTIALLY
		printf_detail("\n");
		printf("%d registered.\n", TEST_DATA_REG_NUM);
	};
	regList();

	//経過時間を表示
	auto printElapsedTime = [](const std::chrono::system_clock::time_point& prev_time) -> std::chrono::system_clock::time_point
	{
		//最終経過時間表示
		const auto now_time = std::chrono::system_clock::now();
		const auto duration = now_time - prev_time;
		const double elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()) / 1000000000.;
		printf("*elapsed_time=%.9llf sec\n", elapsed_time);
		return now_time;
	};
	prev_time = printElapsedTime(prev_time);

	//木を表示
	auto showTree = [&con]()
	{
		printf("--- Show tree (count=%d) ---\n", con.size());
		static const int depth_limit = 5;//最大でも5段階目までを表示（0段階目から数えるので最大で6段階表示される→最大：1+2+4+8+16+32個）
		const int _depth_max = con.depth_max();
		printf("depth_max=%d (limit for showing=%d)\n", _depth_max, depth_limit);
	#ifdef PRINT_TEST_DATA_TREE
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
				const data_t* node = con.root();
				int breath_tmp = breath;
				for (int depth_tmp = depth - 1; node; --depth_tmp)
				{
					if (depth_tmp < 0)
						break;
					node = ope_t::getChild(*node, (breath_tmp & (0x1 << depth_tmp)) != 0x0);
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (ope_t::getChildS(*node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(ope_t::getChildS(*node) ? "-" : " ");
					}
					printf("%s%2d:%c%s", ope_t::getChildS(*node) ? "{" : "[", node->m_key, ope_t::isBlack(*node) ? 'B' : 'R', ope_t::getChildL(*node) ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(ope_t::getChildL(*node) ? "-" : " ");
						if (ope_t::getChildL(*node) && c < print_indent)
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
	#endif//PRINT_TEST_DATA_TREE
	};
	showTree();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//各枝までのノード数を表示
	auto showNodesCount = [&con]()
	{
		printf("--- Show nodes count (count=%d) ---\n", con.size());
		const int depth_max = con.depth_max();
		const long long width_max = static_cast<long long>(std::pow(2, static_cast<long long>(depth_max)));
		printf("depth_max=%d, width_max=%lld\n", depth_max, width_max);
		if(depth_max > 63)
		{
			printf("'depth_max' is over 63. aborting therefor.\n");
			return;
		}
	#ifdef PRINT_TEST_DATA_COLOR_COUNT
		const data_t* prev_node = nullptr;
		int blacks_min = -1;
		int blacks_max = -1;
		int reds_min = -1;
		int reds_max = -1;
		int total_min = -1;
		int total_max = -1;
		for (long long breath = 0; breath < width_max; ++breath)
		{
			int blacks = 0;
			int reds = 0;
			const data_t* last_node = nullptr;
			long long breath_tmp = breath;
			const data_t* node = con.root();
			for (long long depth_tmp = depth_max - 1; node; --depth_tmp)
			{
				last_node = node;
				if (ope_t::isBlack(*node))
					++blacks;
				else
					++reds;
				if (depth_tmp < 0)
					break;
				node = ope_t::getChild(*node, (breath_tmp & (0x1ll << depth_tmp)) != 0x0ll);
			}
			int total = blacks + reds;
			blacks_min = blacks_min > blacks || blacks_min == -1 ? blacks : blacks_min;
			blacks_max = blacks_max < blacks || blacks_max == -1 ? blacks : blacks_max;
			reds_min = reds_min > reds || reds_min == -1 ? reds : reds_min;
			reds_max = reds_max < reds || reds_max == -1 ? reds : reds_max;
			total_min = total_min > total || total_min == -1 ? total : total_min;
			total_max = total_max < total || total_max == -1 ? total : total_max;
			if (prev_node != last_node)
			{
			#ifdef PRINT_TEST_DATA_DETAIL
				printf("%5lld:[%2d] blacks=%d, reds=%d, total=%d\n", breath, last_node->m_key, blacks, reds, total);
			#endif//PRINT_TEST_DATA_DETAIL
			}
			prev_node = last_node;
		}
		blacks_min = blacks_min >= 0 ? blacks_min : 0;
		blacks_max = blacks_max >= 0 ? blacks_max : 0;
		reds_min = reds_min >= 0 ? reds_min : 0;
		reds_max = reds_max >= 0 ? reds_max : 0;
		total_min = total_min >= 0 ? total_min : 0;
		total_max = total_max >= 0 ? total_max : 0;
		printf("max: blacks=%d, reds=%d, total=%d\n", blacks_max, reds_max, total_max);
		printf("min: blacks=%d, reds=%d, total=%d\n", blacks_min, reds_min, total_min);
		printf("diff:blacks=%d, reds=%d, total=%d\n", blacks_max - blacks_min, reds_max - reds_min, total_max - total_min);
	#endif//PRINT_TEST_DATA_COLOR_COUNT
	};
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番小さいノードから昇順に全ノードをリストアップ
	auto showListAsc = [&con]()
	{
		printf("--- Show nodes ascending (count=%d) ---\n", con.size());
		bool is_found = false;
		for (const data_t& obj : con)//C++11形式の範囲に基づくforループ
		{
			if (!is_found)
				is_found = true;
			printf_detail("[%2d] ", obj.m_key);
		}
		//※イテレータの変数宣言と値の更新を分けた方が若干効率的
		//const_reverse_iterator ite;con._begin(ite);
		//const_reverse_iterator end;con._end(end);
		//for (; ite != end; ++ite)
		//{
		//	const data_t& obj = *ite;
		//	...
		//}
		if (is_found)
			printf_detail("\n");
		else
			printf("(nothing)\n");
	};
	showListAsc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番大きいノードから降順に全ノードをリストアップ
	auto showListDesc = [&con]()
	{
		printf("--- Show nodes descending (count=%d) ---\n", con.size());
		bool is_found = false;
		std::for_each(con.rbegin(), con.rend(),
			[&is_found](const data_t& obj)
			{
				if (!is_found)
					is_found = true;
				printf_detail("[%2d] ", obj.m_key);
		}
		);
		//※イテレータの変数宣言と値の更新を分けた方が効率的
		//const_reverse_iterator ite;con._rbegin(ite);
		//const_reverse_iterator end;con._rend(end);
		//for (; ite != end; ++ite)
		//{
		//	const data_t& obj = *ite;
		//	...
		//}
		if (is_found)
			printf_detail("\n");
		else
			printf("(nothing)\n");
	};
	showListDesc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//指定のキーのノードを検索し、同じキーのノードをリストアップ
	auto searchData = [&con]()
	{
		printf("--- Search node ---\n");
		for (int search_key = TEST_DATA_KEY_MIN; search_key <= TEST_DATA_KEY_MAX; ++search_key)
		{
			rb_tree::stack_t<ope_t> stack;
			static const int print_count_limit = 10;
			int print_count = 0;
			bool is_found = false;
			std::for_each(con.find(search_key), con.equal_range(search_key),
				[&con, &is_found, &search_key, &print_count](const data_t& obj)
				{
					if (!is_found)
					{
						printf_dbg_search("%2d(%d):", search_key, con.count(search_key));
						is_found = true;
					}
					if (print_count < print_count_limit)
						printf_dbg_search("[%2d] ", obj.m_key);
					else if (print_count == print_count_limit)
						printf_dbg_search("...");
					++print_count;
				}
			);
			//※イテレータの変数宣言と検索を分けた方が効率的
			//const_iterator ite;con._find(ite, search_key);
			//const_iterator end;con._equal_range(end, search_key);
			//for (; ite != end; ++ite)
			//{
			//	const data_t& obj = *ite;
			//	...
			//}
			if (is_found)
				printf_dbg_search("\n");
		}
	};
	searchData();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//指定のキーと同じか内輪で一番近いノードを検索
	//※一致ノードは表示を省略
	//※最近ノードから数ノードを表示
	auto searchNearestData = [&con](const rb_tree::match_type_t search_type)
	{
		printf("--- Search nearest node for %s ---\n", search_type == rb_tree::FOR_NEAREST_SMALLER ? "smaller" : search_type == rb_tree::FOR_NEAREST_LARGER ? "larger" : "same");
		for (int search_key = TEST_DATA_KEY_MIN; search_key <= TEST_DATA_KEY_MAX; ++search_key)
		{
			rb_tree::stack_t<ope_t> stack;
			bool is_found = false;
			const_iterator ite(con.find(search_key, search_type));
			const_iterator end(con.end());
			for (int i = 0; ite != end && ite->m_key != search_key && i < 4; ++i, ++ite)
			{
				const data_t& obj = *ite;
				if (!is_found)
				{
					printf_dbg_search("%2d:", search_key);
					is_found = true;
				}
				printf_dbg_search("[%2d] ", obj.m_key);
			}
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key, search_type);
			//const_iterator end;con._end(end);
			//...
			if (is_found)
				printf_dbg_search("\n");
		}
	};
	searchNearestData(rb_tree::FOR_NEAREST_SMALLER);
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//指定のキーと同じかそれより大きい最近ノードを検索
	searchNearestData(rb_tree::FOR_NEAREST_LARGER);
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//ノードを削除
	//※特定のキーを削除
	auto removeNodes = [&con]()
	{
		printf("--- Remove nodes ---\n");
		auto erase = [&con](const int remove_key) -> bool
		{
			data_t* removed_node = con.erase(remove_key);
			if (removed_node)
			{
				delete removed_node;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
				return true;
			}
			return false;
		};
		int removed_count = 0;
	#ifndef TEST_DATA_REMOVING_LIST
		//ランダムにデータ削除
		std::mt19937 rand_engine;
		rand_engine.seed(1);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_KEY_MIN, TEST_DATA_KEY_MAX);
		const int removed_count_max = TEST_DATA_REG_NUM / 4;
		while (removed_count < removed_count_max)
		{
			const bool result = erase(rand_dist(rand_engine));
			if (result)
				++removed_count;
		}
	#else//TEST_DATA_REMOVING_LIST
		//固定順にデータ削除
		const int key_list[] = TEST_DATA_REMOVING_LIST;
		for (int key : key_list)
		{
			const bool result = erase(key);
			if (result)
				++removed_count;
		}
	#endif//TEST_DATA_REMOVING_LIST
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeNodes();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//木を表示
	showTree();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//各枝までのノード数を表示
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//ノードを削除
	//※すべての値のキーを一つずつ削除
	auto removeEachKeyNodes = [&con]()
	{
		printf("--- Remove each-key nodes ---\n");
		int removed_count = 0;
		for (int remove_key = TEST_DATA_KEY_MIN; remove_key <= TEST_DATA_KEY_MAX; ++remove_key)
		{
			const_iterator ite(con.find(remove_key));
			data_t* removed_node = con.erase(*ite);
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (removed_node)
			{
				delete removed_node;
				++removed_count;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
			}
		}
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeEachKeyNodes();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//木を表示
	showTree();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//各枝までのノード数を表示
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//ノードを全削除
	//※すべての値のキーに対して、削除が失敗するまで削除を実行
	auto removeAllNodes = [&con]()
	{
		printf("--- Remove all nodes ---\n");
		int removed_count = 0;
		for (int remove_key = TEST_DATA_KEY_MIN; remove_key <= TEST_DATA_KEY_MAX;)
		{
			const_iterator ite(con.find(remove_key));
			data_t* removed_node = con.erase(*ite);
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (removed_node)
			{
				delete removed_node;
				++removed_count;
				printf_detail("[%2d] ", remove_key);
				rb_tree::printf_dbg_remove("\n");
			}
			else
				++remove_key;
		}
		rb_tree::printf_dbg_remove("\n");
		printf("%d removed.\n", removed_count);
	};
	removeAllNodes();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//木を表示
	showTree();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//各枝までのノード数を表示
	showNodesCount();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();
	prev_time = printElapsedTime(prev_time);//経過時間を表示

	//終了
	printf("--- end ---\n");
	printElapsedTime(begin_time);//経過時間を表示

	return EXIT_SUCCESS;
}

// End of file
