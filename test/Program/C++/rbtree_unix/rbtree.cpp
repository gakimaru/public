#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t用
#include <memory.h>//memcpy用
#include <assert.h>//assert用
#include <iterator>//std::iterator用
#include <algorithm>//algorithm用

//#define DISABLE_ROTATE_FOR_ADD//ノード追加時の回転処理を無効化する場合は、このマクロを有効化する
#define DISABLE_ROTATE_FOR_REMOVE//ノード削除時の回転処理を無効化する場合は、このマクロを有効化する

//--------------------------------------------------------------------------------
//赤黒木（red-black tree）
//※メモリ節約のために、親ノードへのリンクを持たないデータ構造とする。
//※代わりに、検索等の関数実行時に外部からスタックを渡す事で親を辿ることが可能。
//※テンプレートにより、アルゴリズムを汎用化。
//※キー重複（同キーのノードが複数ある状態）を許容するアルゴリズムとする。
//※リンクの方法に柔軟性を持たせ、かつ、virtualを避けるために、
//　CRTPを活用して、派生クラスで幾つか既定のメソッドを実装するスタイルとする。
//　（これにより、ポインタ変数によるリンクの保持以外のスタイルにも対応可能。
//　　例えば、配列のインデックスでリンクを持つようなスタイルにも対応できる。）
//※std::mapを模したコンテナとイテレータを利用可能。
//----------------------------------------
//【具体的な活用の想定：メモリ管理での活用】
//・メモリマネージャの管理情報の連結に使用することを想定。
//・空きメモリサイズ順の連結を行うため、キー重複を許容する必要がある。
//・また、連結リストが肥大化することを避けるため、親ノードへのリンク情報は
//　持たない。
//・必要量以上の空きメモリのノードを検索したのち、アラインメントを加味した
//　上で利用可能なノードかを確認し、一つずつ大きなノードを辿って最適な
//　ノードを探し出す。
//・ノード間のリンク情報は、64bitポインタ変数による肥大化が起こらないように、
//　メモリ空間の先頭からオフセットされた32bitの相対ポインタを扱う。
//・一つのメモリ管理情報を、2種類のツリーに振り分けて使用する。
//　削除済みメモリノードのツリーはサイズをキーにし、
//　使用中メモリノードのツリーはポインタをキーにする。
//　このような利用を可能とするために、データ構造とアルゴリズムを完全に
//　切り離した構成にする。
namespace rbtree
{
	//--------------------
	//赤黒木のデータ構造とアルゴリズム
	//【特徴】
	//・二分木である。
	//	- ノードの左側には、キーの値が自ノードより小さいノードを連結。
	//	- ノードの右側には、キーの値が自ノードより大きいノードを連結。
	//・平衡木である。
	//	- 常に左右の木のバランスを保ち、探索時間の大きな劣化がない木構造。
	//【条件】
	//・条件①：各ノードは「赤」か「黒」の「色」を持つ。
	//・条件②：「根」（root）は必ず「黒」。
	//・条件③：「赤」の子は必ず「黒」。
	//	        - 待遇により、「赤」の親は必ず「黒」。
	//	        - 「黒」の子は「赤」でも「黒」でも良い。
	//・条件④：すべての「根」から「葉」までの経路上にある「黒」の数は、あらゆる経路で一定。
	//--------------------
	//赤黒木ノード操作構造体テンプレート
	//※CRTPを活用し、下記のような派生構造体／クラスを作成して使用する
	//  //template<class IMPL_OPE_TYPE, typename NODE_TYPE, typename KEY_TYPE, int STACK_DEPTH_MAX = 32>
	//  //struct base_ope_t;
	//  //struct 派生構造体名 : public rbtree::base_ope_t<派生構造体, ノード型, キー型, スタックの最大の深さ = 32>
	//	struct ope_t : public rbtree::ope_t<ope_t, data_t, int>
	//	{
	//		//子ノードを取得
	//		inline static const node_type* getNodeS(const node_type& node){ return ???; }//小（左）側
	//		inline static const node_type* getNodeL(const node_type& node){ return ???; }//大（右）側
	//		//子ノードを変更
	//		inline static void setNodeS(node_type& node, const node_type* node_s){ ??? = node; }//小（左）側
	//		inline static void setNodeL(node_type& node, const node_type* node_l){ ??? = node; }//大（右）側
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
	//		inline static int compare_key(const key_type lhs, const key_type rhs)
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

		//ノードとキーを比較
		inline static int compare(const node_type& lhs, const node_type& rhs)
		{
			return ope_type::compare_key(ope_type::getKey(lhs), ope_type::getKey(rhs));
		}
		inline static int compare(const node_type& lhs, const key_type rhs)
		{
			return ope_type::compare_key(ope_type::getKey(lhs), rhs);
		}
		inline static int compare(const key_type lhs, const node_type& rhs)
		{
			return ope_type::compare_key(lhs, ope_type::getKey(rhs));
		}
		inline static int compare(const key_type lhs, const key_type rhs)
		{
			return ope_type::compare_key(lhs, rhs);
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
		typedef stack_t<ope_type> stack_type; \
		typedef typename stack_type::info_t stack_info_type;
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
		int calcBreadth()
		{
			int breadth = 0;
			for (int depth = 0; depth < m_depth; ++depth)
			{
				breadth *= 2;
				breadth += (m_array[depth].m_isLarge ? 1 : 0);
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
			const node_type* child_node = ope_type::getNodeS(*curr_node);//小（左）側の子ノードを取得
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
			const node_type* child_node = ope_type::getNodeL(*curr_node);//大（右）側の子ノードを取得
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
		const node_type* node_l = ope_type::getNodeL(*curr_node);//大（右）側の子ノードを取得
		if (node_l)//子がある場合
		{
			stack.push(curr_node, true);//親ノードをスタックに記録
			return getSmallestNode<ope_type>(node_l, stack);//子から一番小さい子孫ノードを取得
		}
		else//if(!node_l)//子がない場合
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
		const node_type* node_s = ope_type::getNodeS(*curr_node);//小（左）側の子ノードを取得
		if (node_s)//子がある場合
		{
			stack.push(curr_node, false);//親ノードをスタックに記録
			return getLargestNode<ope_type>(node_s, stack);//子から一番大きい子孫ノードを取得
		}
		else//if(!node_s)//子がない場合
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
	//赤黒木操作関数：ツリーの最大の深さを計測
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
				curr_node = ope_type::getNodeS(*curr_node);//小（左）側の子の方に検索を続行
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
				const node_type* child_node = ope_type::getNodeL(*curr_node);//大（右）側の子ノードを取得
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
				const node_type* child_node = ope_type::getNodeS(*curr_node);//小（左）側の子ノードを取得
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
	//赤黒木操作関数：ツリーのノード数を計測
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type* node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		return !node ? 0 :
			1 + countNodes<ope_type>(ope_type::getNodeS(*node)) +
			countNodes<ope_type>(ope_type::getNodeL(*node));
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
	//赤黒木操作関数：【汎用処理】ノード左回転処理
	//         .--------[node]---------.   
	//      [node_s]             .--[node_l]
	//                        [node_ls]     
	//
	//                    ↓【左回転】
	//
	//         .-------[node_l]
	//    .--[node]--.          
	// [node_s]  [node_ls]      
	template<class OPE_TYPE>
	inline typename OPE_TYPE::node_type* rotateL(typename OPE_TYPE::node_type* node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		node_type* node_l = const_cast<node_type*>(ope_type::getNodeL(*node));
		node_type* node_ls = const_cast<node_type*>(ope_type::getNodeS(*node_l));
		ope_type::setNodeS(*node_l, node);
		ope_type::setNodeL(*node, node_ls);
		return node_l;
	};
	//--------------------
	//赤黒木操作関数：【汎用処理】ノード右回転処理
	//    .---------[node]-------.   
	// [node_s]--.           [node_l]
	//       [node_sl]              
	//
	//                ↓【右回転】
	//
	//             [node_s]-------.         
	//                      .---[node]--.   
	//                   [node_sl]  [node_l]
	template<class OPE_TYPE>
	inline typename OPE_TYPE::node_type* rotateR(typename OPE_TYPE::node_type* node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		node_type* node_s = const_cast<node_type*>(ope_type::getNodeS(*node));
		node_type* node_sl = const_cast<node_type*>(ope_type::getNodeL(*node_s));
		ope_type::setNodeL(*node_s, node);
		ope_type::setNodeS(*node, node_sl);
		return node_s;
	};
	//--------------------
	//赤黒木操作関数：遡って赤黒バランス調整
	//※ノード追加時用
	template<class OPE_TYPE>
	void balanceForAdd(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* curr_node, bool child_is_large, typename OPE_TYPE::node_type* child_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (curr_node && child_node)
		{
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
					if (curr_is_large)
						ope_type::setNodeL(*parent_node, curr_node);
					else
						ope_type::setNodeS(*parent_node, curr_node);
					is_rotated = false;//回転処理済み状態リセット
				}
				if (ope_type::isRed(*curr_node) && ope_type::isRed(*child_node))//赤ノードが二つ連結していたら回転処理
				{
					//【共通処理】親ノードを軸にした左回転処理
					//             .-------[parent_node:B]--------.                
					//           [(S)]                    .--[curr_node:R]--.      
					//                                  [(LS)]       [child_node:R]
					// 
					//                          ↓【左回転】
					//
					//          .-----------[curr_node:R]---------.        
					//   .--[parent_node:B]--.               [child_node:R]
					// [(S)]              [(LS)]                           
					// 
					//                          ↓【変数と色を調整】
					//                                                 黒に
					//            .--------[parent_node:R]--------.     ↓ 
					//   .------[(S):B]------.                [curr_node:B]
					// [(SS)]             [(SL)]                           
					auto rotateParentL = [&]() -> const node_type*
					{
					parent_node = rotateL<ope_type>(parent_node);//左回転処理
					curr_is_large = true;
					curr_node = child_node;
					ope_type::setIsBlack(*curr_node);//ノードを黒にする
					//child_is_large = true;
					//child_node = nullptr;
					return parent_node;
				};
					//【共通処理】親ノードを軸にした右回転処理
					//               .-----[parent_node:B]-----.  
					//       .--[curr_node:R]--.             [(L)]
					// [child_node:R]       [(SL)]                
					//
					//                            ↓【右回転】
					//
					//               .-------[curr_node:R]-------.            
					//          [child_node:R]         .--[parent_node:B]--.  
					//                               [(SL)]              [(L)]
					//
					//                            ↓【変数と色を調整】
					//
					//               .-------[parent_node:R]-----.            
					//           [curr_node:B]         .------[(L):B]------.  
					//                     ↑        [(LS)]             [(LL)]
					//                    黒に
					auto rotateParentR = [&]() -> const node_type*
					{
						parent_node = rotateR<ope_type>(parent_node);//右回転処理
						curr_is_large = false;
						curr_node = child_node;
						ope_type::setIsBlack(*curr_node);//ノードを黒にする
						//child_is_large = false;
						//child_node = nullptr;
						return parent_node;
					};
					//【共通処理】現在のノードを軸にした左回転処理
					//           .-------[curr_node:R]-------.        
					//         [(S)]                .--[child_node:R]
					//                            [(LS)]              
					// 
					//                          ↓【左回転】
					//
					//           .-------[child_node:R]
					//   .--[curr_node:R]--.           
					// [(S)]            [(LS)]         
					// 
					//                          ↓【変数を調整】※色の調整はしない
					//
					//           .--------[curr_node:R]
					//   .--[child_node:R]--.          
					// [(SS)]            [(SL)]        
					auto rotateCurrL = [&]() -> const node_type*
					{
						node_type* curr_node_old = curr_node;
						curr_node = rotateL<ope_type>(curr_node);//左回転処理
						child_is_large = false;
						child_node = curr_node_old;
						return curr_node;
					};
					//【共通処理】現在のノードを軸にした右回転処理
					//       .--------[curr_node:R]--------.   
					// [child_node:R]--.                 [(L)] 
					//              [(SS)]               
					// 
					//                     ↓【右回転】
					//
					//               [child_node:R]-------.           
					//                           .--[curr_node:R]--.  
					//                         [(SS)]            [(L)]
					// 
					//                     ↓【変数を調整】※色の調整はしない
					//
					//                [curr_node:R]-------.           
					//                          .--[child_node:R]--.  
					//                        [(LS)]            [(LL)]
					auto rotateCurrR = [&]() -> const node_type*
					{
						node_type* curr_node_old = curr_node;
						curr_node = rotateR<ope_type>(curr_node);//回転処理
						child_is_large = true;
						child_node = curr_node_old;
						return curr_node;
					};
					//各状態に合わせた回転処理
					if (!curr_is_large && !child_is_large)
					{
						//【小（左）：赤】→【小（左）：赤】
						//               .-----[parent_node:B]-----.  
						//       .--[curr_node:R]--.             [(L)]
						// [child_node:R]       [(SL)]                
						//
						//                            ↓【親ノードを右回転】
						//
						//               .-------[curr_node:R]-------.            
						//          [child_node:R]         .--[parent_node:B]--.  
						//                               [(SL)]              [(L)]
						//
						//                            ↓【変数と色を調整】
						//
						//               .-------[parent_node:R]-----.            
						//           [curr_node:B]         .------[(L):B]------.  
						//                     ↑        [(LS)]             [(LL)]
						//                    黒に
						rotateParentR();
					}
					else if (!curr_is_large &&  child_is_large)
					{
						//【小（左）：赤】→【大（右）：赤】
						//                       .-----------------[parent_node:B]-------.  
						//               .--[curr_node:R]--.                           [(L)]
						//             [(SS)]        .--[child_node:R]--.
						//                        [(SLS)]          [(SLL)]
						//
						//                                               ↓【現在ノードを左回転】
						//
						//                        .----------------[parent_node:B]-------.  
						//           .------[child_node:R]------.                      [(L)]
						//   .--[curr_node:R]--.            [(SLL)]                
						// [(SS)]          [(SLS)]
						//
						//                                               ↓【親ノードを右回転】
						//
						//                        .-----------------[child_node:R]-------.            
						//                .--[curr_node:R]--.               .--[parent_node:B]--.  
						//              [(SS)]           [(SLS)]          [(SLL)]             [(L)]
						//
						//                                               ↓【変数と色を調整】
						//
						//                        .-----------------[parent_node:R]-----.            
						//                .--[curr_node:B]--.                   .-----[(L):B]---.  
						//               [(SS)])        ↑[(SL)]              [(LS)]         [(LL)]
						//                             黒に
						ope_type::setNodeS(*parent_node, rotateCurrL());
						rotateParentR();
					}
					else if (curr_is_large && !child_is_large)
					{
						//【大（右）：赤】→【小（左）：赤】
						//             .-------[parent_node:B]----------------.                  
						//           [(S)]                       .-------[curr_node:R]-------.   
						//                               .--[child_node:R]--.              [(LL)]
						//                             [(LSS)]          [(LSL)]               
						// 
						//                          ↓【現在ノードを右回転】
						//
						//             .-------[parent_node:B]-----------------.                           
						//           [(S)]                       .-------[child_node:R]-------.            
						//                                     [(LSS)]                .--[curr_node:R]--.  
						//                                                          [(LSL)]          [(LL)]
						// 
						//                          ↓【親ノードを左回転】
						//
						//           .----------[child_node:R]---------.            
						//   .--[parent_node:B]--.             .--[curr_node:R]--.  
						// [(S)]             [(LSS)]         [(LSL)]          [(LL)]
						// 
						//                          ↓【変数と色を調整】
						//                                                  黒に
						//            .--------[parent_node:R]--------.      ↓      
						//   .------[(S):B]------.              .--[curr_node:B]--.  
						// [(SS)]             [(SL)]          [(LSL)]          [(LL)]
						ope_type::setNodeL(*parent_node, rotateCurrR());
						rotateParentL();
					}
					else//if (!curr_is_large && !child_is_large)
					{
						//【大（右）：赤】→【大（右）：赤】
						//             .-------[parent_node:B]--------.                
						//           [(S)]                    .--[curr_node:R]--.      
						//                                  [(LS)]       [child_node:R]
						// 
						//                          ↓【親ノードを左回転】
						//
						//          .-----------[curr_node:R]---------.        
						//   .--[parent_node:B]--.               [child_node:R]
						// [(S)]              [(LS)]                           
						// 
						//                          ↓【変数と色を調整】
						//                                                 黒に
						//            .--------[parent_node:R]--------.     ↓ 
						//   .------[(S):B]------.                [curr_node:B]
						// [(SS)]             [(SL)]                           
						rotateParentL();
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
	}
	//--------------------
	//赤黒木操作関数：遡って赤黒バランス調整
	//※ノード削除時用
	template<class OPE_TYPE>
	void balanceForRemove(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* remove_node, typename OPE_TYPE::node_type* replace_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		bool is_necessary_rotate = false;//回転必要？
		bool remove_node_is_black = ope_type::isBlack(*remove_node);
		bool replace_node_is_black = replace_node ? ope_type::isBlack(*replace_node) : false;
		//回転操作必要判定
		if (!remove_node_is_black)//削除ノードが赤の場合
		{
			if (!replace_node)//置き換えノードがない場合
			{
				//is_necessary_rotate = false;//回転不要
				printf("([R]←[n]:OK )");
			}
			else//if(replace_node)//置き換えノードがある場合
			{
				if (!replace_node_is_black)//置き換えノードが赤の場合
				{
					//is_necessary_rotate = false;//回転不要
					printf("([R]←[R]:OK )");
				}
				else//if (replace_node_is_black)//置き換えノードが黒の場合
				{
					is_necessary_rotate = true;//回転必要
					printf("([R]←[B]:ROT)");
					ope_type::setIsRed(*replace_node);//置き換えノードを赤にする
					//remove_node_is_black = true;//削除ノードは黒
					//                            //※置き換え元のノードが削除されたものとして処理する
				}
			}
		}
		else//if (remove_node_is_black)//削除ノードが黒の場合
		{
			if (!replace_node)//置き換えノードがない場合
			{
				is_necessary_rotate = true;//回転必要
				printf("([B]←[n]:ROT)");
			}
			else//if(replace_node)//置き換えノードがある場合
			{
				if (!replace_node_is_black)//置き換えノードが赤の場合
				{
					//is_necessary_rotate = false;//回転不要
					printf("([B]←[R]:OK )");
					ope_type::setIsBlack(*replace_node);//置き換えノードを黒にする
					//remove_node_is_black = false;//削除ノードは赤
					//                             //※置き換え元のノードが削除されたものとして処理する
				}
				else//if (replace_node_is_black)//置き換えノードが黒の場合
				{
					is_necessary_rotate = true;//回転必要
					printf("([B]←[B]:ROT)");
				}
			}
		}
		//回転操作
		//※黒ノードが削除された時のみ回転を行う
		if (is_necessary_rotate)
		{
			node_type* parent_node = nullptr;
			bool curr_is_large = false;
			while (true)
			{
				stack_info_type* parent_info = stack.pop();
				if (!parent_info)
					break;
				parent_node = const_cast<node_type*>(parent_info->m_nodeRef);
				curr_is_large = parent_info->m_isLarge;
				if (is_necessary_rotate)
				{
					node_type* curr_node = parent_node ?//現在のノード取得 ※この側で黒ノードが一つ減少している
						curr_is_large ?
							const_cast<node_type*>(ope_type::getNodeL(*parent_node)) :
							const_cast<node_type*>(ope_type::getNodeS(*parent_node)) :
						nullptr;
					node_type* sibling_node = parent_node ?//兄弟ノード取得
						curr_is_large ?
							const_cast<node_type*>(ope_type::getNodeS(*parent_node)) :
							const_cast<node_type*>(ope_type::getNodeL(*parent_node)) :
						nullptr;
					node_type* sibling_node_s = sibling_node ?//兄弟ノードの小（左）側の子ノード取得
						const_cast<node_type*>(ope_type::getNodeS(*sibling_node)) :
						nullptr;
					node_type* sibling_node_l = sibling_node ?//兄弟ノードの大（右）側の子ノード取得
						const_cast<node_type*>(ope_type::getNodeL(*sibling_node)) :
						nullptr;
					if (sibling_node)
					{
						if (!curr_is_large)//削除ノード：【小（左）:黒】
						{
							if (ope_type::isBlack(*sibling_node))//兄弟ノード：【大（右）：黒】
							{
								if (sibling_node_s && ope_type::isRed(*sibling_node_s))//→【小（左）：赤】
								{
									is_necessary_rotate = false;//調整完了
									printf("(ROT:SIB→L=B→S=R,OK)");
								}
								else if (sibling_node_l && ope_type::isRed(*sibling_node_l))//→【大（右）：赤】
								{
									is_necessary_rotate = false;//調整完了
									printf("(ROT:SIB→L=B→L=R,OK)");
								}
								else//→【小（左）：黒orなし】かつ【大（右）：黒orなし】
								{
									if (ope_type::isRed(*parent_node))
									{
										is_necessary_rotate = false;//調整完了
										printf("(ROT:SIB→L=B→SL!=R,P=R,OK)");
									}
									else//if (ope_type::isBlack(*parent_node))
									{
										is_necessary_rotate = true;//調整続行
										printf("(ROT:SIB→L:B→SL!=R,P=B,MORE)");
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//兄弟ノード：【大（右）：赤】
							{
								//※必然的に親ノードは黒
								is_necessary_rotate = true;//調整続行
								printf("(ROT:SIB→L=R,MORE)");
							}
						}
						else//if (curr_is_large)//削除ノード：【大（右）:黒】
						{
							if (ope_type::isBlack(*sibling_node))//兄弟ノード：【小（左）：黒】
							{
								if (sibling_node_s && ope_type::isRed(*sibling_node_s))//→【小（左）：赤】
								{
									is_necessary_rotate = false;//調整完了
									printf("(ROT:SIB→S=B→S=R,OK)");
								}
								else if (sibling_node_l && ope_type::isRed(*sibling_node_l))//→【大（右）：赤】
								{
									is_necessary_rotate = false;//調整完了
									printf("(ROT:SIB→S=B→L=R,OK)");
								}
								else//→【小（左）：黒orなし】かつ【大（右）：黒orなし】
								{
									if (ope_type::isRed(*parent_node))
									{
										is_necessary_rotate = false;//調整完了
										printf("(ROT:SIB→S=B→SL!=R,P=R,OK)");
									}
									else//if (ope_type::isBlack(*parent_node))
									{
										is_necessary_rotate = true;//調整続行
										printf("(ROT:SIB→S=B→SL!=R,P=B,MORE)");
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//兄弟ノード：【小（左）：赤】
							{
								//※必然的に親ノードは黒
								is_necessary_rotate = true;//調整続行
								printf("(ROT:SIB→S=R,MORE)");
							}
						}
					}
				}
			}
			if (parent_node)
			{
				root = parent_node;
				ope_type::setIsBlack(*root);
			}
		}
	}
	//--------------------
	//赤黒木操作関数：ノードを追加
	//※関数内でスタックを使用
	template<class OPE_TYPE>
	bool addNode(typename OPE_TYPE::node_type* new_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!new_node)
			return false;
		if (!root)//根ノードが未登録の場合
		{
			root = new_node;//根ノードに登録
			ope_type::setIsBlack(*root);//根ノードは黒
			return true;
		}
		ope_type::setIsRed(*new_node);//新規ノードは暫定で赤
		key_type new_key = ope_type::getKey(*new_node);//新規ノードのキーを取得
		stack_type stack;//スタックを用意
		node_type* curr_node = root;//現在の探索ノード
		bool child_is_large = false;
		node_type* child_node = nullptr;
		while (true)
		{
			child_is_large = ope_type::le(*curr_node, new_key);//指定のキーと一致もしくは指定のキーより小さければtrue
			child_node = child_is_large ?
				const_cast<node_type*>(ope_type::getNodeL(*curr_node)) ://大（右）側の子ノードを取得
				const_cast<node_type*>(ope_type::getNodeS(*curr_node));//小（左）側の子ノードを取得
			if (!child_node)//子が無ければそこに新規ノードを追加して終了
			{
				child_node = new_node;
				if (child_is_large)
					ope_type::setNodeL(*curr_node, child_node);//大（右）側の子ノードとして新規ノードを追加
				else
					ope_type::setNodeS(*curr_node, child_node);//小（左）側の子ノードとして新規ノードを追加
				break;
			}
			stack.push(curr_node, child_is_large);//親ノードをスタックに記録
			curr_node = child_node;
		}
	#ifndef DISABLE_ROTATE_FOR_ADD
		//赤黒バランス調整
		balanceForAdd<ope_type>(root, stack, curr_node, child_is_large, child_node);
	#endif//DISABLE_ROTATE_FOR_ADD
		return true;
	}
	//--------------------
	//赤黒木操作関数：ノードを削除
	//※関数内でスタックを二つ使用
	template<class OPE_TYPE>
	bool removeNode(const typename OPE_TYPE::node_type* target_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!target_node || !root)
			return false;
		stack_type stack;//スタックを用意
		node_type* remove_node = const_cast<node_type*>(searchNode<ope_type>(root, target_node, stack));//削除ノードを検索してスタックを作る
		if (!remove_node)//検索に失敗したら終了
			return false;
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
		node_type* node_s = const_cast<node_type*>(ope_type::getNodeS(*remove_node));//小（左）側の子ノードを取得
		node_type* node_l = const_cast<node_type*>(ope_type::getNodeL(*remove_node));//大（右）側の子ノードを取得
		node_type* node_sl = nullptr;//削除ノードの最大子孫ノード（削除ノードの次に小さいノード）
		node_type* replace_node =//削除ノードと置き換えるノード
			( node_s && !node_l) ? node_s ://小（左）側の子ノード
			(!node_s &&  node_l) ? node_l ://大（右）側の子ノード
			                       nullptr;//ノード削除 or 最大子孫ノード
		if (node_s && node_l)//大小両方の子がある場合、最大子孫ノード検索
		{
			stack_info_type* remove_info = stack.push(remove_node, false);//スタックに削除ノードを追加
			node_sl = const_cast<node_type*>(getLargestNode<ope_type>(node_s, stack));//最大子孫ノードを取得
			stack_info_type* parent_info_sl = stack.top();//最大子孫ノードの親ノードを取得
			node_type* parent_node_sl = const_cast<node_type*>(parent_info_sl->m_nodeRef);//最大子孫ノードの親ノードを取得
			ope_type::setNodeL(*parent_node_sl, ope_type::getNodeS(*node_sl));//最大子孫ノードを親ノードから切り離し
			ope_type::setNodeL(*node_sl, node_l);//最大子孫ノードの大側の子を変更
			if (node_sl != node_s)
				ope_type::setNodeS(*node_sl, node_s);//最大子孫ノードの小側の子を変更
			replace_node = node_sl;//削除ノードと置き換えるノードをセット
			remove_info->m_nodeRef = node_sl;//スタックの情報を書き換え
		}
		if (!parent_node)//親ノードがない場合 → 根ノードが削除
		{
			root = replace_node;//根ノードを置き換え
			if (!root)//根ノードなければ、その時点で終了
				return true;
		}
		else//if(parent_node)//親ノードがある場合
		{
			if (curr_is_large)
				ope_type::setNodeL(*parent_node, replace_node);//親ノードの大（右）側の子ノードを置き換え
			else//if (!curr_is_large)
				ope_type::setNodeS(*parent_node, replace_node);//親ノードの小（左）側の子ノードを置き換え
		}
	#ifndef DISABLE_ROTATE_FOR_REMOVE
		//赤黒バランス調整
		balanceForRemove<ope_type>(root, stack, remove_node, replace_node);
	#endif//DISABLE_ROTATE_FOR_REMOVE
		return true;
	}
	//--------------------
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
		bool empty() const { return m_root == nullptr; }
		std::size_t size() const { return countNodes<ope_type>(m_root); }
		//std::size_t max_size() const { return countNodes<ope_type>(m_root); }
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
		bool insert(const node_type& node){ return addNode<ope_type>(const_cast<node_type*>(&node), m_root); }
		bool erase(const node_type& node){ return removeNode<ope_type>(&node, m_root); }
		bool erase(const key_type key){ return removeNode<ope_type>(at(key), m_root); }
		void clear(){ m_root = nullptr; }
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
}//namespace rbtree

//--------------------------------------------------------------------------------
//赤黒木テスト

#include <algorithm>//std::max用
#include <random>//C++11 std::random用

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
struct ope_t : public rbtree::base_ope_t<ope_t, data_t, int>
{
	//子ノードを取得
	inline static const node_type* getNodeS(const node_type& node){ return node.m_nodeS; }//小（左）側
	inline static const node_type* getNodeL(const node_type& node){ return node.m_nodeL; }//大（右）側
	//子ノードを変更
	inline static void setNodeS(node_type& node, const data_t* node_s){ node.m_nodeS = node_s; }//小（左）側
	inline static void setNodeL(node_type& node, const data_t* node_l){ node.m_nodeL = node_l; }//大（右）側
		
	//ノードの色を取得
	inline static color_t getColor(const node_type& node){ return node.m_isBlack ? BLACK : RED; }
	//ノードの色を変更
	inline static void setColor(node_type& node, const color_t color){ node.m_isBlack = color == BLACK; }
	
	//キーを取得
	inline static key_type getKey(const node_type& node){ return node.m_key; }

	//キーを比較
	inline static int compare_key(const key_type lhs, const key_type rhs)
	{
		return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
	}
};

//----------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	static const int key_min = 0;//最小キー
	static const int key_max = 99;//最大キー
	static const int reg_num = 100;//登録数

	//赤黒木コンテナ
	typedef rbtree::container<ope_t> container_t;
	typedef container_t::iterator iterator;
	typedef container_t::const_iterator const_iterator;
	typedef container_t::reverse_iterator reverse_iterator;
	typedef container_t::const_reverse_iterator const_reverse_iterator;
	container_t con;

	//データを登録
	auto regList = [&con]()
	{
		printf("--- make table ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(key_min, key_max);
		for (int i = 0; i < reg_num; ++i)
		{
			data_t* new_node = new data_t(rand_dist(rand_engine));
			printf("[%2d] ", new_node->m_key);
			con.insert(*new_node);
		}
		printf("\n");
	};
	regList();

	//ツリーを表示
	auto showTree = [&con]()
	{
		printf("--- show tree ---\n");
		static const int depth_limit = 5;
		const int _depth_max = con.depth_max();
		printf("depth_max=%d (show limit=%d)\n", _depth_max, depth_limit);
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
					node = (breath_tmp & (0x1 << depth_tmp)) ?
						ope_t::getNodeL(*node) :
						ope_t::getNodeS(*node);
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (ope_t::getNodeS(*node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(ope_t::getNodeS(*node) ? "-" : " ");
					}
					printf("%s%2d:%c%s", ope_t::getNodeS(*node) ? "{" : "[", node->m_key, ope_t::isBlack(*node) ? 'B' : 'R', ope_t::getNodeL(*node) ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(ope_t::getNodeL(*node) ? "-" : " ");
						if (ope_t::getNodeL(*node) && c < print_indent)
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

	//各枝までのノード数を表示
	auto showNodesCount = [&con]()
	{
		printf("--- show nodes count ---\n");
		const int depth_max = con.depth_max();
		const int width_max = static_cast<int>(std::pow(2, depth_max));
		printf("depth_max=%d, width_max=%d\n", depth_max, width_max);
		const data_t* prev_node = nullptr;
		int blacks_min = 0;
		int blacks_max = 0;
		int reds_min = 0;
		int reds_max = 0;
		int total_min = 0;
		int total_max = 0;
		for (int breath = 0; breath < width_max; ++breath)
		{
			int blacks = 0;
			int reds = 0;
			const data_t* last_node = nullptr;
			int breath_tmp = breath;
			const data_t* node = con.root();
			for (int depth_tmp = depth_max - 1; node; --depth_tmp)
			{
				last_node = node;
				if (ope_t::isBlack(*node))
					++blacks;
				else
					++reds;
				if (depth_tmp < 0)
					break;
				node = (breath_tmp & (0x1 << depth_tmp)) ?
					ope_t::getNodeL(*node) :
					ope_t::getNodeS(*node);
			}
			int total = blacks + reds;
			blacks_min = blacks_min > blacks || blacks_min == 0 ? blacks : blacks_min;
			blacks_max = blacks_max < blacks || blacks_max == 0 ? blacks : blacks_max;
			reds_min = reds_min > reds || reds_min == 0 ? reds : reds_min;
			reds_max = reds_max < reds || reds_max == 0 ? reds : reds_max;
			total_min = total_min > total || total_min == 0 ? total : total_min;
			total_max = total_max < total || total_max == 0 ? total : total_max;
			if (prev_node != last_node)
				printf("%5d:[%2d] blacks=%d, reds=%d, total=%d\n", breath, last_node->m_key, blacks, reds, total);
			prev_node = last_node;
		}
		printf("max: blacks=%d, reds=%d, total=%d\n", blacks_max, reds_max, total_max);
		printf("min: blacks=%d, reds=%d, total=%d\n", blacks_min, reds_min, total_min);
		printf("diff:blacks=%d, reds=%d, total=%d\n", blacks_max - blacks_min, reds_max - reds_min, total_max - total_min);
	};
	showNodesCount();

	//一番小さいノードから昇順に全ノードをリストアップ
	auto showListAsc = [&con]()
	{
		printf("--- get smallest node -> get next node (count=%d) ---\n", con.size());
		bool is_found = false;
		for (const data_t& obj : con)//C++11形式の範囲に基づくforループ
		{
			if (!is_found)
				is_found = true;
			printf("[%2d] ", obj.m_key);
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
			printf("\n");
		else
			printf("(nothing)\n");
	};
	showListAsc();

	//一番大きいノードから降順に全ノードをリストアップ
	auto showListDesc = [&con]()
	{
		printf("--- get largest node -> get previous node (count=%d) ---\n", con.size());
		bool is_found = false;
		std::for_each(con.rbegin(), con.rend(),
			[&is_found](const data_t& obj)
			{
				if (!is_found)
					is_found = true;
				printf("[%2d] ", obj.m_key);
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
			printf("\n");
		else
			printf("(nothing)\n");
	};
	showListDesc();

	//指定のキーのノードを検索し、同じキーのノードをリストアップ
	auto searchData = [&con]()
	{
		printf("--- search node ---\n");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			rbtree::stack_t<ope_t> stack;
			bool is_found = false;
			std::for_each(con.find(search_key), con.equal_range(search_key),
				[&con, &is_found, &search_key](const data_t& obj)
				{
					if (!is_found)
					{
						printf("%2d(%d):", search_key, con.count(search_key));
						is_found = true;
					}
					printf("[%2d] ", obj.m_key);
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
				printf("\n");
		}
	};
	searchData();

	//指定のキーと同じか内輪で一番近いノードを検索
	//※一致ノードは表示を省略
	//※最近ノードから数ノードを表示
	auto searchNearestData = [&con](const rbtree::match_type_t search_type)
	{
		printf("--- search nearest node for %s ---\n", search_type == rbtree::FOR_NEAREST_SMALLER ? "smaller" : search_type == rbtree::FOR_NEAREST_LARGER ? "larger" : "same");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			rbtree::stack_t<ope_t> stack;
			bool is_found = false;
			const_iterator ite(con.find(search_key, search_type));
			const_iterator end(con.end());
			for (int i = 0; ite != end && ite->m_key != search_key && i < 4; ++i, ++ite)
			{
				const data_t& obj = *ite;
				if (!is_found)
				{
					printf("%2d:", search_key);
					is_found = true;
				}
				printf("[%2d] ", obj.m_key);
			}
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key, search_type);
			//const_iterator end;con._end(end);
			//...
			if (is_found)
				printf("\n");
		}
	};
	searchNearestData(rbtree::FOR_NEAREST_SMALLER);

	//指定のキーと同じかそれより大きい最近ノードを検索
	//searchNearestData(rbtree::FOR_NEAREST_LARGER);

	//ノードを削除
	//※特定のキーを削除
	auto removeNodes = [&con]()
	{
		printf("--- remove nodes ---\n");
		auto removeNode = [&con](const int remove_key)
		{
			const bool result = con.erase(remove_key);
			if (result)
				printf("[%2d] \n", remove_key);
		};
		removeNode(1);
		removeNode(54);
		removeNode(68);
		//removeNode(78);
		printf("\n");
	};
	removeNodes();

	//ツリーを表示
	showTree();

	//黒ノード数を表示
	showNodesCount();

	//ノードを削除
	//※すべての値のキーを一つずつ削除
	auto removeEachKeyNodes = [&con]()
	{
		printf("--- remove each-key nodes ---\n");
		for (int remove_key = key_min; remove_key <= key_max; ++remove_key)
		{
			const_iterator ite(con.find(remove_key));
			const bool result = con.erase(*ite);
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (result)
				printf("[%2d] \n", remove_key);
		}
		printf("\n");
	};
	removeEachKeyNodes();

	//ツリーを表示
	showTree();

	//黒ノード数を表示
	showNodesCount();
	
	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();

	//ノードを全削除
	//※すべての値のキーに対して、削除が失敗するまで削除を実行
	auto removeAllNodes = [&con]()
	{
		printf("--- remove all nodes ---\n");
		for (int remove_key = key_min; remove_key <= key_max;)
		{
			const_iterator ite(con.find(remove_key));
			const bool result = con.erase(*ite);
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (result)
				printf("[%2d] \n", remove_key);
			else
				++remove_key;
		}
		printf("\n");
	};
	removeAllNodes();

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();

	return EXIT_SUCCESS;
}

// End of file
