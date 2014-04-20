#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t用
#include <assert.h>//assert用

//--------------------------------------------------------------------------------
//赤黒木（red-black tree）
//※メモリ節約のために、親ノードへのリンクを持たないデータ構造とする
//※代わりに、検索等の関数実行時に外部からスタックを渡す事で親を辿ることが可能
//※テンプレートにより、アルゴリズムを汎用化
//※キー重複（同値のキーのノードが複数ある状態）を許容するアルゴリズムとする
namespace rbtree
{
	//--------------------
	//赤黒木ノード構造体テンプレート
	//※CRTPを活用し、下記のような派生構造体／クラスを作成して使用する
	//※rbtree::node_t<派生構造体／クラス名, 値型>
	//	struct OriginalData : public rbtree::node_t<OriginalData, int>
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
	//		value_t getVal() const { return ???; }//値を返す
	//	}
	template<class T, typename V>
	struct node_t
	{
		//型
		typedef T data_t;//データ型
		typedef V value_t;//値型

		//キャストオペレータ
		//※値を返す
		inline operator value_t() const { return static_cast<const data_t*>(this)->getVal(); }

		//比較オペレータ
		inline bool operator==(const value_t rhs) const { return static_cast<value_t>(*this) == rhs; }
		inline bool operator!=(const value_t rhs) const { return static_cast<value_t>(*this) != rhs; }
		inline bool operator<(const value_t rhs) const { return static_cast<value_t>(*this) < rhs; }
		inline bool operator>(const value_t rhs) const { return static_cast<value_t>(*this) > rhs; }
		inline bool operator<=(const value_t rhs) const { return static_cast<value_t>(*this) <= rhs; }
		inline bool operator>=(const value_t rhs) const { return static_cast<value_t>(*this) >= rhs; }

		//比較メソッド
		inline int compare(const value_t rhs) const
		{
			const value_t lhs = static_cast<value_t>(*this);
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
			assert(m_curr < DEPTH_MAX);
			info_t* stack_node = &m_array[m_curr++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
		}
		//スタックからノード情報を取得
		info_t* pop()
		{
			if (m_curr == 0)
				return nullptr;
			return &m_array[--m_curr];
		}
		//スタック位置を取得
		int getCurr() const { return m_curr; }
		//スタック位置を更新
		void setCurr(const int new_curr)
		{
			if (m_curr > new_curr && new_curr >= 0)
				m_curr = new_curr;
		}
		//リセット
		void reset()
		{
			m_curr = 0;
		}
		//コンストラクタ
		stack_t() :
			m_curr(0)
		{}
	private:
		//フィールド
		info_t m_array[DEPTH_MAX];//ノード情報の配列（スタック）
		int m_curr;//スタックのカレント位置
	};
	//--------------------
	//赤黒木操作関数：一番小さいノードを取得
	template<class T>
	const T* getSmallestNode(const T* top_node, stack_t<T>& stack)
	{
		if (!top_node)
			return nullptr;
		const T* curr_node = top_node;//現在の探索ノード
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
	template<class T>
	const T* getLargestNode(const T* top_node, stack_t<T>& stack)
	{
		if (!top_node)
			return nullptr;
		const T* curr_node = top_node;//現在の探索ノード
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
	//赤黒木操作関数：次に小さいノードを取得
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
	//赤黒木操作関数：指定の値と一致するノード、もしくは、指定の値に最も近いノードを検索
	//※一致ノードが複数ある場合、その先頭ノードを返す
	//※指定の値の内輪で最も近いノードと同値のノードが複数ある場合、その末尾ノードを返す
	//※指定の値より大きく最も近いノードと同値のノードが複数ある場合、その先頭ノードを返す
	enum E_SEARCH_TYPE
	{
		FOR_SAME = 0,//一致ノードを検索
		FOR_NEAREST_SMALLER,//一致ノードもしくは内輪で最も近いノードを検索
		FOR_NEAREST_LARGER,//一致ノードもしくはそれより大きく最も近いノードを検索
	};
	template<class T>
	const T* searchNode(const T* top_node, const typename T::value_t val, stack_t<T>& stack, const E_SEARCH_TYPE search_type = FOR_SAME)
	{
		if (!top_node)
			return nullptr;
		const T* same_node = nullptr;//一致ノード
		int same_stack_curr = -1;//一致ノード検出時のスタック位置
		const T* nearest_node = nullptr;//最近ノード
		int nearest_stack_curr = -1;//最近ノード検出時のスタック位置
		const T* curr_node = top_node;//現在の探索ノード
		while (true)
		{
			const int cmp = curr_node->compare(val);//指定の値と大小比較
			if (cmp == 0)//指定の値と一致
			{
				//※キー重複を許容するアルゴリズムのため、
				//　一致ノードを記録した上で検索を続行する
				same_node = curr_node;//一致ノードを記録
				same_stack_curr = stack.getCurr();//一致ノード検出時のスタック位置を記録
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = curr_node->getNodeS();//小（左）側の子の方に検索を続行
				if (!curr_node)//子が無ければ終了
					break;
			}
			else if (cmp < 0)//指定の値より小さい
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && *nearest_node <= *curr_node))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_curr = stack.getCurr();//最近ノード検出時のスタック位置を記録
				}
				const T* child_node = curr_node->getNodeL();//大（右）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, true);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
			else//if (cmp > 0)//指定の値より大きい
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && *nearest_node >= *curr_node))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_curr = stack.getCurr();//最近ノード検出時のスタック位置を記録
				}
				const T* child_node = curr_node->getNodeS();//小（左）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
		}
		if (same_node)//一致ノード検出時
		{
			stack.setCurr(same_stack_curr);//一致ノード検出時のスタック位置に戻す
			return same_node;//一致ノードを返す
		}
		else//if (!same_node)
		{
			if (nearest_node)//最近ノード検出時
			{
				stack.setCurr(nearest_stack_curr);//最近ノード検出時のスタック位置に戻す
				return nearest_node;//最近ノードを返す
			}
		}
		return nullptr;//検索失敗
	}
	//--------------------
	//赤黒木操作関数：ノードを追加
	template<class T>
	bool addNode(T* new_node, T*& top_node)
	{
		if (!new_node)
			return false;
		if (!top_node)//先頭ノードが未登録の場合
		{
			new_node->setIsBlack();//黒ノード化
			top_node = new_node;//先頭ノードに登録
			return true;
		}
		typename T::value_t new_val = *new_node;//新規ノードの値を取得
		stack_t<T> stack;//スタックを用意
		const T* curr_node = top_node;//現在の探索ノード
		while (true)
		{
			const int cmp = curr_node->compare(new_val);//指定の値と大小比較
			if (cmp <= 0)//指定の値と一致もしくは指定の値より小さい
			{
				const T* child_node = curr_node->getNodeL();//大（右）側の子ノードを取得
				if (!child_node)//子が無ければ終了
				{
					new_node->setIsRed();//赤ノード化
					const_cast<T*>(curr_node)->setNodeL(new_node);//大（右）側の子ノードとして新規ノードを追加
					break;
				}
				stack.push(curr_node, true);//親ノードをスタックに記録
				curr_node = child_node;
			}
			else//if (cmp > 0)//指定の値より大きい
			{
				const T* child_node = curr_node->getNodeS();//小（左）側の子ノードを取得
				if (!child_node)//子が無ければ終了
				{
					new_node->setIsRed();//赤ノード化
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
	bool removeNode(const T* target_node, T*& top_node)
	{
		if (!target_node || !top_node)
			return false;
		stack_t<T> stack;//スタックを用意
		const typename T::value_t target_value = *target_node;//削除ノードの値を取得
		T* remove_node = const_cast<T*>(searchNode(top_node, target_value, stack));//削除ノードと同値のノード検索
		if (!remove_node)//削除ノードと同値のノードがなければ終了
			return false;
		while (remove_node != target_node && *remove_node == target_value)//削除ノード検索
		{
			remove_node = const_cast<T*>(getNextNode(remove_node, stack));
		}
		if (*remove_node != target_value)//削除ノードがなければ終了
			return false;
		//削除
		T* parent_node = nullptr;//削除ノードの親ノード
		bool parent_is_large = false;//削除ノードの親ノードからの連結方向
		{
			const typename stack_t<T>::info_t* parent_info = stack.pop();
			if (parent_info)
			{
				parent_node = const_cast<T*>(parent_info->m_nodeRef);//親ノードを取得
				parent_is_large = parent_info->m_isLarge;//親ノードからの連結方向
			}
		}
		T* node_s = const_cast<T*>(remove_node->getNodeS());//小（左）側の子ノードを取得
		T* node_l = const_cast<T*>(remove_node->getNodeL());//大（右）側の子ノードを取得
		T* node_sl = nullptr;//削除ノードの小（左）側の子の最大子孫ノード（削除ノードの次に小さいノード）
		if (node_s && node_l)//小ノードも大ノードもある場合
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
		if (!parent_node)//親ノードがない場合 → 先頭ノードが削除ノード
		{
			top_node =
				(node_s && !node_l) ?//小ノードがあり、大ノードがない場合
					node_s ://小ノードを先頭ノードに変更
				(!node_s && node_l) ?//小ノードがなく、大ノードがある場合
					node_l ://大ノードを先頭ノードに変更
				(node_s && node_l) ?//小ノードも大ノードもある場合
					node_sl ://最大子孫ノードを先頭ノードに変更
				//(!node_s && !node_l) ?//小ノードも、大ノードもない場合
					nullptr//先頭ノードをクリア
				;
		}
		else//if(parent_node)//親ノードがある場合
		{
			if (parent_is_large)//削除ノードが親ノードの大側の子だった場合
			{
				parent_node->setNodeL(
					(node_s && !node_l) ?//小ノードがあり、大ノードがない場合
						node_s ://小ノードを親ノードの大側の子に変更
					(!node_s && node_l) ?//小ノードがなく、大ノードがある場合
						node_l ://大ノードを親ノードの大側の子に変更
					(node_s && node_l) ?//小ノードも大ノードもある場合
						node_sl ://最大子孫ノードを親ノードの大側の子に変更
					//(!node_s && !node_l) ?//小ノードも、大ノードもない場合
						nullptr//親ノードの大側の子をクリア
				);
			}
			else//if (!parent_is_large)//削除ノードが親ノードの小側の子だった場合
			{
				parent_node->setNodeS(
					(node_s && !node_l) ?//小ノードがあり、大ノードがない場合
						node_s ://小ノードを親ノードの小側の子に変更
					(!node_s && node_l) ?//小ノードがなく、大ノードがある場合
						node_l ://大ノードを親ノードの小側の子に変更
					(node_s && node_l) ?//小ノードも大ノードもある場合
						node_sl ://最大子孫ノードを親ノードの小側の子に変更
					//(!node_s && !node_l)//小ノードも、大ノードもない場合
						nullptr//親ノードの小側の子をクリア
				);
			}
		}
		return true;
	}
}//namespace rbtree

//--------------------------------------------------------------------------------
//赤黒木テスト

#include <random>//C++11 random用
#include <stdint.h>//intptr_t用

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

	value_t getVal() const { return m_val; }//値を返す

	//コンストラクタ
	data_t(const value_t val) :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_val(val)
	{}
	data_t() :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_val(0)
	{}

	//フィールド
	const data_t* m_nodeS;//小（左）側のノード
	const data_t* m_nodeL;//大（右）側のノード
	bool m_isBlack;//ノードの色
	value_t m_val;//値
};

//----------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	static const int val_min = 0;//値の最小値
	static const int val_max = 99;//値の最大値
	static const int reg_num = 100;//登録数

	//赤黒木のトップノード
	data_t* top_node = nullptr;

	//データを登録
	auto regList = [&top_node]()
	{
		printf("--- make table ---\n");
		{
			std::mt19937 rand_engine;
			rand_engine.seed(0);
			std::uniform_int_distribution<int> rand_dist(val_min, val_max);
			for (int i = 0; i < reg_num; ++i)
			{
				data_t* new_node = new data_t(rand_dist(rand_engine));
				printf("[%d] ", new_node->getVal());
				rbtree::addNode(new_node, top_node);
			}
		}
		printf("\n");
	};
	regList();

	//一番小さいノードから昇順に全ノードをリストアップ
	auto showListAsc = [&top_node]()
	{
		printf("--- get smallest node -> get next node ---\n");
		{
			rbtree::stack_t<data_t> stack;
			const data_t* node = rbtree::getSmallestNode(top_node, stack);
			bool is_found = false;
			while (node)
			{
				if (!is_found)
					is_found = true;
				printf("[%d] ", node->getVal());
				node = rbtree::getNextNode(node, stack);
			}
			if (is_found)
				printf("\n");
			else
				printf("(nothing)\n");
		}
	};
	showListAsc();

	//一番大きいノードから降順に全ノードをリストアップ
	auto showListDesc = [&top_node]()
	{
		printf("--- get largest node -> get previous node ---\n");
		{
			rbtree::stack_t<data_t> stack;
			const data_t* node = rbtree::getLargestNode(top_node, stack);
			bool is_found = false;
			while (node)
			{
				if (!is_found)
					is_found = true;
				printf("[%d] ", node->getVal());
				node = rbtree::getPrevNode(node, stack);
			}
			if (is_found)
				printf("\n");
			else
				printf("(nothing)\n");
		}
	};
	showListDesc();

	//指定の値のノードを検索し、同じ値のノードをリストアップ
	auto searchData = [&top_node]()
	{
		printf("--- search node ---\n");
		for (int search_val = val_min; search_val <= val_max; ++search_val)
		{
			rbtree::stack_t<data_t> stack;
			const data_t* node = rbtree::searchNode(top_node, search_val, stack);
			bool is_found = false;
			while (node && *node == search_val)
			{
				if (!is_found)
				{
					printf("%d=", search_val);
					is_found = true;
				}
				printf("[%d] ", node->getVal());
				node = rbtree::getNextNode(node, stack);
			}
			if (is_found)
				printf("\n");
		}
	};
	searchData();

	//指定の値と同じか内輪で一番近いノードを検索
	auto searchNearestData = [&top_node](const rbtree::E_SEARCH_TYPE search_type)
	{
		printf("--- search nearest node for %s ---\n", search_type == rbtree::FOR_NEAREST_SMALLER ? "smaller" : search_type == rbtree::FOR_NEAREST_LARGER ? "larger" : "same");
		for (int search_val = val_min; search_val <= val_max; ++search_val)
		{
			rbtree::stack_t<data_t> stack;
			const data_t * node = rbtree::searchNode(top_node, search_val, stack, search_type);
			bool is_found = false;
			for (int i = 0; node && *node != search_val && i < 4; ++i)
			{
				if (!is_found)
				{
					printf("%d=", search_val);
					is_found = true;
				}
				printf("[%d] ", node->getVal());
				node = rbtree::getNextNode(node, stack);
			}
			if (is_found)
				printf("\n");
		}
	};
	searchNearestData(rbtree::FOR_NEAREST_SMALLER);

	//指定の値と同じかそれより大きい最近ノードを検索
	searchNearestData(rbtree::FOR_NEAREST_LARGER);

	//ノードを削除
	auto removeNodes = [&top_node]()
	{
		printf("--- remove nodes ---\n");
		for (int search_val = val_min; search_val <= val_max; ++search_val)
		{
			const data_t* target_node = nullptr;
			{
				rbtree::stack_t<data_t> stack;
				target_node = rbtree::searchNode(top_node, search_val, stack);
			}
			const bool result = rbtree::removeNode(target_node, top_node);
			if (result)
				printf("[%d] ", search_val);
		}
		printf("\n");
	};
	removeNodes();

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();

	//ノードを削除
	auto removeAllNodes = [&top_node]()
	{
		printf("--- remove all nodes ---\n");
		for (int search_val = val_min; search_val <= val_max;)
		{
			const data_t* target_node = nullptr;
			{
				rbtree::stack_t<data_t> stack;
				target_node = rbtree::searchNode(top_node, search_val, stack);
			}
			const bool result = rbtree::removeNode(target_node, top_node);
			if (result)
				printf("[%d] ", search_val);
			else
				++search_val;
		}
		printf("\n");
	};
	removeAllNodes();

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();

	return EXIT_SUCCESS;
}

// End of file
