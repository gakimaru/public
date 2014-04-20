#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t用
#include <assert.h>//assert用

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
//----------------------------------------
//【具体的な活用の想定】
//・メモリマネージャの管理情報の連結に使用することを想定。
//・空きメモリサイズ順の連結を行うため、キー重複を許容する必要がある。
//・また、連結リストが肥大化することを避けるため、親ノードへのリンク情報は
//　持たない。
//・必要量以上の空きメモリのノードを検索したのち、アラインメントを加味した
//　上で利用可能なノードかを確認し、一つずつ大きなノードを辿って最適な
//　ノードを探し出す。
//・ノード間のリンク情報は、64bitポインタ変数による肥大化が起こらないように、
//　メモリ空間の先頭からオフセットされた32bitの相対ポインタを扱う。
namespace rbtree
{
	//--------------------
	//赤黒木ノード構造体テンプレート
	//※CRTPを活用し、下記のような派生構造体／クラスを作成して使用する
	//  //struct 派生構造体／クラス名 : public rbtree::node_t<派生構造体／クラス名, キー型>
	//	struct Derived : public rbtree::node_t<Derived, int>
	//	{
	//		//定数
	//		static const int DEPTH_MAX = ???;//最大の深さ（スタック処理用）
	//		
	//		//子ノードの取得
	//		const data_t* getNodeS() const { return ???; }//小（左）側の子ノード取得
	//		const data_t* getNodeL() const { return ???; }//大（右）側の子ノード取得
	//		//子ノードを変更
	//		void setNodeS(const data_t* node){ ??? = node; }//小（左）側の子ノードを変更
	//		void setNodeL(const data_t* node){ ??? = node; }//大（右）側の子ノードを変更
	//		
	//		//ノードの色をチェック
	//		bool isBlack() const { return ???; }//黒か？
	//		bool isRed() const { return !???; }//赤か？
	//		//ノードの色を変更
	//		void setIsBlack() { ??? = true; }//黒に変更
	//		void setIsRed() { ??? = false; }//赤に変更
	//		
	//		//キーを返す
	//		key_t getKey() const { return ???; }
	//	}
	template<class T, typename V>
	struct node_t
	{
		//型
		typedef T impl_t;//実装型（struct impl_t : public rbtree::node_t<impl_t, int>）
		typedef V key_t;//キー型

		//キャストオペレータ
		//※キーを返す
		inline operator key_t() const { return static_cast<const impl_t*>(this)->getKey(); }

		//比較オペレータ
		inline bool operator==(const key_t rhs) const { return static_cast<key_t>(*this) == rhs; }
		inline bool operator!=(const key_t rhs) const { return static_cast<key_t>(*this) != rhs; }
		inline bool operator<(const key_t rhs) const { return static_cast<key_t>(*this) < rhs; }
		inline bool operator>(const key_t rhs) const { return static_cast<key_t>(*this) > rhs; }
		inline bool operator<=(const key_t rhs) const { return static_cast<key_t>(*this) <= rhs; }
		inline bool operator>=(const key_t rhs) const { return static_cast<key_t>(*this) >= rhs; }

		//キー比較メソッド
		inline int compare(const key_t rhs) const
		{
			const key_t lhs = static_cast<key_t>(*this);
			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
		}
	};
	//--------------------
	//赤黒木操作処理用スタッククラス
	template<class T>
	class stack_t
	{
	public:
		//定数
		static const int DEPTH_MAX = T::DEPTH_MAX;//最大の深さ（スタック処理用）
	public:
		//型
		//ノード情報型
		struct info_t
		{
			const T* m_nodeRef;//ノード参照
			bool m_isLarge;//大（右）側に連結
		};
	public:
		//スタックにノード情報を記録
		void push(const T* node, const bool is_large)
		{
			assert(m_depth < DEPTH_MAX);
			info_t* stack_node = &m_array[m_depth++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
		}
		//スタックからノード情報を取得
		info_t* pop()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[--m_depth];
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
	template<class T>
	const T* getSmallestNode(const T* root, stack_t<T>& stack)
	{
		if (!root)
			return nullptr;
		const T* curr_node = root;//現在の探索ノード
		while (true)
		{
			const T* child_node = curr_node->getNodeS();//小（左）側の子ノードを取得
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
	template<class T>
	const T* getLargestNode(const T* root, stack_t<T>& stack)
	{
		if (!root)
			return nullptr;
		const T* curr_node = root;//現在の探索ノード
		while (true)
		{
			const T* child_node = curr_node->getNodeL();//大（右）側の子ノードを取得
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
	template<class T>
	const T* getNextNode(const T* curr_node, stack_t<T>& stack)
	{
		if (!curr_node)
			return nullptr;
		const T* node_l = curr_node->getNodeL();//大（右）側の子ノードを取得
		if (node_l)//子がある場合
		{
			stack.push(curr_node, true);//親ノードをスタックに記録
			return getSmallestNode(node_l, stack);//子から一番小さい子孫ノードを取得
		}
		else//if(!node_l)//子がない場合
		{
			typename stack_t<T>::info_t* stack_node = nullptr;
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
	template<class T>
	const T* getPrevNode(const T* curr_node, stack_t<T>& stack)
	{
		if (!curr_node)
			return nullptr;
		const T* node_s = curr_node->getNodeS();//小（左）側の子ノードを取得
		if (node_s)//子がある場合
		{
			stack.push(curr_node, false);//親ノードをスタックに記録
			return getLargestNode(node_s, stack);//子から一番大きい子孫ノードを取得
		}
		else//if(!node_s)//子がない場合
		{
			typename stack_t<T>::info_t* stack_node = nullptr;
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
	template<class T>
	int getDepthMax(const T* root)
	{
		if (!root)
			return -1;
		int depth_max = 0;//最大の深さ
		rbtree::stack_t<T> stack;//スタックを作成
		const T* node = rbtree::getSmallestNode(root, stack);//最小ノード取得
		while (node)
		{
			const int depth = stack.getDepth();//深さを取得
			depth_max = depth_max >= depth ? depth_max : depth;//最大の深さを更新
			node = rbtree::getNextNode(node, stack);//次のノード取得
		}
		return depth_max;
	}
	//--------------------
	//赤黒木操作関数：指定のキーと一致するノード、もしくは、指定のキーに最も近いノードを検索
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	//※一致ノードが複数ある場合、その最初のノードを返す
	//※指定のキーの内輪で最も近いノードと同キーのノードが複数ある場合、その最後のノードを返す
	//※指定のキーより大きく最も近いノードと同キーのノードが複数ある場合、その最初のノードを返す
	enum E_SEARCH_TYPE
	{
		FOR_SAME = 0,//一致ノードを検索
		FOR_NEAREST_SMALLER,//一致ノード、もしくは、内輪で最も近いノードを検索
		FOR_NEAREST_LARGER,//一致ノード、もしくは、それより大きく最も近いノードを検索
	};
	template<class T>
	const T* searchNode(const T* root, const typename T::key_t key, stack_t<T>& stack, const E_SEARCH_TYPE search_type = FOR_SAME)
	{
		if (!root)
			return nullptr;
		const T* match_node = nullptr;//一致ノード
		int match_stack_depth = -1;//一致ノード検出時のスタック位置
		const T* nearest_node = nullptr;//最近ノード
		int nearest_stack_depth = -1;//最近ノード検出時のスタック位置
		const T* curr_node = root;//現在の探索ノード
		while (true)
		{
			const int cmp = curr_node->compare(key);//指定のキーと大小比較
			if (cmp == 0)//指定のキーと一致
			{
				//※キー重複を許容するアルゴリズムのため、
				//　一致ノードを記録した上で検索を続行する
				match_node = curr_node;//一致ノードを記録
				match_stack_depth = stack.getDepth();//一致ノード検出時のスタック位置を記録
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = curr_node->getNodeS();//小（左）側の子の方に検索を続行
				if (!curr_node)//子が無ければ終了
					break;
			}
			else if (cmp < 0)//指定のキーより小さい
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && *nearest_node <= *curr_node))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_depth = stack.getDepth();//最近ノード検出時のスタック位置を記録
				}
				const T* child_node = curr_node->getNodeL();//大（右）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, true);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
			else//if (cmp > 0)//指定のキーより大きい
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && *nearest_node >= *curr_node))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_depth = stack.getDepth();//最近ノード検出時のスタック位置を記録
				}
				const T* child_node = curr_node->getNodeS();//小（左）側の子ノードを取得
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
	//--------------------
	//赤黒木操作関数：ノードを追加
	template<class T>
	bool addNode(T* new_node, T*& root)
	{
		if (!new_node)
			return false;
		if (!root)//ルートノードが未登録の場合
		{
			root = new_node;//ルートノードに登録
			return true;
		}
		typename T::key_t new_key = *new_node;//新規ノードのキーを取得
		stack_t<T> stack;//スタックを用意
		const T* curr_node = root;//現在の探索ノード
		while (true)
		{
			const int cmp = curr_node->compare(new_key);//指定のキーと大小比較
			if (cmp <= 0)//指定のキーと一致もしくは指定のキーより小さい
			{
				const T* child_node = curr_node->getNodeL();//大（右）側の子ノードを取得
				if (!child_node)//子が無ければそこに新規ノードを追加して終了
				{
					const_cast<T*>(curr_node)->setNodeL(new_node);//大（右）側の子ノードとして新規ノードを追加
					break;
				}
				stack.push(curr_node, true);//親ノードをスタックに記録
				curr_node = child_node;
			}
			else//if (cmp > 0)//指定のキーより大きい
			{
				const T* child_node = curr_node->getNodeS();//小（左）側の子ノードを取得
				if (!child_node)//子が無ければそこに新規ノードを追加して終了
				{
					const_cast<T*>(curr_node)->setNodeS(new_node);//大（右）側の子ノードとして新規ノードを追加
					break;
				}
				stack.push(curr_node, false);//親ノードをスタックに記録
				curr_node = child_node;
			}
		}
		return true;
	}
	//--------------------
	//赤黒木操作関数：ノードを削除
	template<class T>
	bool removeNode(const T* target_node, T*& root)
	{
		if (!target_node || !root)
			return false;
		stack_t<T> stack;//スタックを用意
		const typename T::key_t remove_key = *target_node;//削除ノードのキーを取得
		T* remove_node = const_cast<T*>(searchNode(root, remove_key, stack));//削除ノードと同キーのノード検索
		if (!remove_node)//削除ノードと同キーのノードがなければ終了
			return false;
		while (remove_node != target_node && *remove_node == remove_key)//削除ノード検索
		{
			remove_node = const_cast<T*>(getNextNode(remove_node, stack));
		}
		if (remove_node != target_node)//削除ノードがなければ終了
			return false;
		//削除開始
		T* parent_node = nullptr;//削除ノードの親ノード
		bool parent_is_large = false;//削除ノードの親ノードからの連結方向
		{
			const typename stack_t<T>::info_t* parent_info = stack.pop();//親ノード参照情報を取得
			if (parent_info)
			{
				parent_node = const_cast<T*>(parent_info->m_nodeRef);//親ノードを取得
				parent_is_large = parent_info->m_isLarge;//親ノードからの連結方向
			}
		}
		T* node_s = const_cast<T*>(remove_node->getNodeS());//小（左）側の子ノードを取得
		T* node_l = const_cast<T*>(remove_node->getNodeL());//大（右）側の子ノードを取得
		T* node_sl = nullptr;//削除ノードの最大子孫ノード（削除ノードの次に小さいノード）
		if (node_s && node_l)//大小両方の子がある場合、最大子孫ノード検索
		{
			stack.reset();//スタックをリセット
			node_sl = const_cast<T*>(getLargestNode(node_s, stack));//最大子孫ノードを取得
			const typename stack_t<T>::info_t* sl_parent_info = stack.pop();//最大子孫ノードの親ノードを取得
			if (sl_parent_info)
			{
				T* sl_parent_node = const_cast<T*>(sl_parent_info->m_nodeRef);//最大子孫ノードの親ノードを取得
				sl_parent_node->setNodeL(node_sl->getNodeS());//最大子孫ノードを親ノードから切り離し
			}
			node_sl->setNodeL(node_l);//最大子孫ノードの大側の子を変更
			if (node_sl != node_s)
				node_sl->setNodeS(node_s);//最大子孫ノードの小側の子を変更
		}
		T* replace_node =//削除ノードと置き換えるノード
			(node_s && !node_l) ? node_s ://小（左）側の子ノード
			(!node_s &&  node_l) ? node_l ://大（右）側の子ノード
			(node_s &&  node_l) ? node_sl ://最大子孫ノード
			//(!node_s && !node_l) ?
			nullptr;//ノード削除
		if (!parent_node)//親ノードがない場合 → ルートノードが削除ノード
			root = replace_node;//ルートノードを置き換え
		else//if(parent_node)//親ノードがある場合
		{
			if (parent_is_large)
				parent_node->setNodeL(replace_node);//親ノードの大（右）側の子ノードを置き換え
			else//if (!parent_is_large)
				parent_node->setNodeS(replace_node);//親ノードの小（左）側の子ノードを置き換え
		}
		return true;
	}
}//namespace rbtree

//--------------------------------------------------------------------------------
//赤黒木テスト

#include <algorithm>//std::max用
#include <random>//C++11 std::random用

//----------------------------------------
//テストデータ
struct data_t : public rbtree::node_t<data_t, int>
{
	//定数
	static const int DEPTH_MAX = 128;//最大の深さ（スタック処理用）

	//子ノードの取得
	const data_t* getNodeS() const { return m_nodeS; }//小（左）側の子ノード取得
	const data_t* getNodeL() const { return m_nodeL; }//大（右）側の子ノード取得
	//子ノードを変更
	void setNodeS(const data_t* node){ m_nodeS = node; }//小（左）側の子ノードを変更
	void setNodeL(const data_t* node){ m_nodeL = node; }//大（右）側の子ノードを変更

	//ノードの色をチェック
	bool isBlack() const { return m_isBlack; }//黒か？
	bool isRed() const { return !m_isBlack; }//赤か？
	//ノードの色を変更
	void setIsBlack() { m_isBlack = true; }//黒に変更
	void setIsRed() { m_isBlack = false; }//赤に変更

	//キーを返す
	key_t getKey() const { return m_key; }

	//コンストラクタ
	data_t(const key_t key) :
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
	key_t m_key;//キー
};

//----------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	static const int key_min = 0;//最小キー
	static const int key_max = 99;//最大キー
	static const int reg_num = 100;//登録数

	//赤黒木のトップノード
	data_t* root = nullptr;

	//データを登録
	auto regList = [&root]()
	{
		printf("--- make table ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(key_min, key_max);
		for (int i = 0; i < reg_num; ++i)
		{
			data_t* new_node = new data_t(rand_dist(rand_engine));
			printf("[%d] ", new_node->getKey());
			rbtree::addNode(new_node, root);
		}
		printf("\n");
	};
	regList();

	//ツリーを表示
	auto showTree = [&root]()
	{
		printf("--- show tree ---\n");
		static const int depth_limit = 4;
		int depth_max = rbtree::getDepthMax(root);
		printf("depth_max=%d (show limit=%d)\n", depth_max, depth_limit);
		depth_max = depth_max <= depth_limit ? depth_max : depth_limit;
		const int width_max = static_cast<int>(std::pow(2, depth_max));
		for (int depth = 0; depth <= depth_max; ++depth)
		{
			const int depth_rev = depth_max - depth;
			const int width = static_cast<int>(std::pow(2, depth));
			static const int label_len = 6;
			const int print_width = (width_max * label_len) / width;
			const int print_width_h = (print_width - label_len) / 2;
			rbtree::stack_t<data_t> stack;
			const data_t* node = rbtree::getSmallestNode(root, stack);
			int prev_breath = -1;
			while (node)
			{
				const int depth_curr = stack.getDepth();
				if (depth_curr == depth)
				{
					const int breath = stack.calcBreadth();
					const int skip_width = breath - prev_breath - 1;
					for (int skip = 0; skip < skip_width; ++skip)
					{
						for (int c = 0; c < print_width; ++c)
							printf(" ");
					}
					{
						int c = 0;
						for (; c < print_width_h / 2; ++c)
							printf(" ");
						if (node->getNodeS() && c < print_width_h)
						{
							printf(".");
							++c;
						}
						for (; c < print_width_h; ++c)
							printf(node->getNodeS() ? "-" : " ");
					}
					printf("%s%2d:%c%s", node->getNodeS() ? "{" : "[", node->getKey(), node->isBlack() ? 'B' : 'R', node->getNodeL() ? "}" : "]");
					{
						int c = 0;
						for (; c < print_width_h / 2; ++c)
							printf(node->getNodeL() ? "-" : " ");
						if (node->getNodeL() && c < print_width_h)
						{
							printf(".");
							++c;
						}
						for (; c < print_width_h; ++c)
							printf(" ");
					}
					prev_breath = breath;
				}
				node = rbtree::getNextNode(node, stack);
			}
			{
				const int skip_width = width - prev_breath - 1;
				for (int skip = 0; skip < skip_width; ++skip)
				{
					for (int c = 0; c < print_width; ++c)
						printf(" ");
				}
			}
			printf("\n");
		}
	};
	showTree();

	//一番小さいノードから昇順に全ノードをリストアップ
	auto showListAsc = [&root]()
	{
		printf("--- get smallest node -> get next node ---\n");
		rbtree::stack_t<data_t> stack;
		const data_t* node = rbtree::getSmallestNode(root, stack);
		bool is_found = false;
		while (node)
		{
			if (!is_found)
				is_found = true;
			printf("[%d] ", node->getKey());
			node = rbtree::getNextNode(node, stack);
		}
		if (is_found)
			printf("\n");
		else
			printf("(nothing)\n");
	};
	showListAsc();

	//一番大きいノードから降順に全ノードをリストアップ
	auto showListDesc = [&root]()
	{
		printf("--- get largest node -> get previous node ---\n");
		rbtree::stack_t<data_t> stack;
		const data_t* node = rbtree::getLargestNode(root, stack);
		bool is_found = false;
		while (node)
		{
			if (!is_found)
				is_found = true;
			printf("[%d] ", node->getKey());
			node = rbtree::getPrevNode(node, stack);
		}
		if (is_found)
			printf("\n");
		else
			printf("(nothing)\n");
	};
	showListDesc();

	//指定のキーのノードを検索し、同じキーのノードをリストアップ
	auto searchData = [&root]()
	{
		printf("--- search node ---\n");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			rbtree::stack_t<data_t> stack;
			const data_t* node = rbtree::searchNode(root, search_key, stack);
			bool is_found = false;
			while (node && *node == search_key)
			{
				if (!is_found)
				{
					printf("%d=", search_key);
					is_found = true;
				}
				printf("[%d] ", node->getKey());
				node = rbtree::getNextNode(node, stack);
			}
			if (is_found)
				printf("\n");
		}
	};
	searchData();

	//指定のキーと同じか内輪で一番近いノードを検索
	auto searchNearestData = [&root](const rbtree::E_SEARCH_TYPE search_type)
	{
		printf("--- search nearest node for %s ---\n", search_type == rbtree::FOR_NEAREST_SMALLER ? "smaller" : search_type == rbtree::FOR_NEAREST_LARGER ? "larger" : "same");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			rbtree::stack_t<data_t> stack;
			const data_t * node = rbtree::searchNode(root, search_key, stack, search_type);
			bool is_found = false;
			for (int i = 0; node && *node != search_key && i < 4; ++i)
			{
				if (!is_found)
				{
					printf("%d=", search_key);
					is_found = true;
				}
				printf("[%d] ", node->getKey());
				node = rbtree::getNextNode(node, stack);
			}
			if (is_found)
				printf("\n");
		}
	};
	searchNearestData(rbtree::FOR_NEAREST_SMALLER);

	//指定のキーと同じかそれより大きい最近ノードを検索
	searchNearestData(rbtree::FOR_NEAREST_LARGER);

	//ノードを削除
	auto removeNodes = [&root]()
	{
		printf("--- remove nodes ---\n");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			const data_t* target_node = nullptr;
			{
				rbtree::stack_t<data_t> stack;
				target_node = rbtree::searchNode(root, search_key, stack);
			}
			const bool result = rbtree::removeNode(target_node, root);
			if (result)
				printf("[%d] ", search_key);
		}
		printf("\n");
	};
	removeNodes();

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();

	//ノードを削除
	auto removeAllNodes = [&root]()
	{
		printf("--- remove all nodes ---\n");
		for (int search_key = key_min; search_key <= key_max;)
		{
			const data_t* target_node = nullptr;
			{
				rbtree::stack_t<data_t> stack;
				target_node = rbtree::searchNode(root, search_key, stack);
			}
			const bool result = rbtree::removeNode(target_node, root);
			if (result)
				printf("[%d] ", search_key);
			else
				++search_key;
		}
		printf("\n");
	};
	removeAllNodes();

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();

	return EXIT_SUCCESS;
}

// End of file
