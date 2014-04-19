#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t用
#include <assert.h>//assert用

//--------------------------------------------------------------------------------
//赤黒木（red-black tree）
namespace rbtree
{
	//--------------------
	//赤黒木ノード構造体テンプレート
	//※CRTPを活用し、下記のような派生構造体／クラスを作成して使用する
	//※rbtree::node_t<派生構造体／クラス名, 値型>
	//	struct OriginalData : public rbtree::node_t<OriginalData, int>
	//	{
	//		//定数
	//		static const int DEPTH_MAX = 128;//最大の深さ（スタック処理用）
	//		
	//		//左（小）側のノード取得
	//		data_t* getNodeS(){ return const_cast<data_t*>(m_nodeS); }
	//		const data_t* getNodeS() const { return m_nodeS; }
	//		//右（大）側のノード取得
	//		data_t* getNodeL(){ return const_cast<data_t*>(m_nodeL); }
	//		const data_t* getNodeL() const { return m_nodeL; }
	//		//左（小）側のノードをセット
	//		void setNodeS(const data_t* node){ m_nodeS = node; }
	//		//右（大）側のノードをセット
	//		void setNodeL(const data_t* node){ m_nodeL = node; }
	//		
	//		//ノードの色をチェック
	//		bool isBlack() const { return m_isBlack; }//黒か？
	//		bool isRed() const { return !m_isBlack; }//赤か？
	//		//ノードの色を変更
	//		void setIsBlack() { m_isBlack = true; }//黒にする
	//		void setIsRed() { m_isBlack = false; }//赤にする
	//		
	//		value_t getVal() const { return m_val; }//値を返す
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
			bool m_isLarge;//右（大）側に連結
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
		const T* curr_node = top_node;
		while (curr_node)
		{
			const T* child_node = curr_node->getNodeS();
			if (!child_node)
				return  curr_node;
			stack.push(curr_node, false);
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：一番大きいノードを取得
	template<class T>
	const T* getBiggestNode(const T* top_node, stack_t<T>& stack)
	{
		if (!top_node)
			return nullptr;
		const T* curr_node = top_node;
		while (curr_node)
		{
			const T* child_node = curr_node->getNodeL();
			if (!child_node)
				return  curr_node;
			stack.push(curr_node, true);
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：次に大きいノードを取得
	template<class T>
	const T* getNextNode(const T* curr_node, stack_t<T>& stack)
	{
		if (!curr_node)
			return nullptr;
		const T* node_l = curr_node->getNodeL();
		if (node_l)
		{
			stack.push(curr_node, true);
			while (node_l)
			{
				const T* node_s = node_l->getNodeS();
				if (!node_s)
					break;
				stack.push(node_l, false);
				node_l = node_s;
			}
		}
		else
		{
			typename stack_t<T>::info_t* stack_node = nullptr;
			while (stack_node = stack.pop())
			{
				if (stack_node->m_isLarge == false)
				{
					node_l = stack_node->m_nodeRef;
					break;
				}
			}
		}
		return node_l;
	}
	//--------------------
	//赤黒木操作関数：次に小さいノードを取得
	template<class T>
	const T* getPrevNode(const T* curr_node, stack_t<T>& stack)
	{
		if (!curr_node)
			return nullptr;
		const T* node_s = curr_node->getNodeS();
		if (node_s)
		{
			stack.push(curr_node, false);
			while (node_s)
			{
				const T* node_l = node_s->getNodeL();
				if (!node_l)
					break;
				stack.push(node_s, true);
				node_s = node_l;
			}
		}
		else
		{
			typename stack_t<T>::info_t* stack_node = nullptr;
			while (stack_node = stack.pop())
			{
				if (stack_node->m_isLarge == true)
				{
					node_s = stack_node->m_nodeRef;
					break;
				}
			}
		}
		return node_s;
	}
	//--------------------
	//赤黒木操作関数：指定の値のノードを検索
	//※同値のノードが複数ある場合、その先頭ノードを返す
	//※みつからなかった場合は nullptr を返す
	template<class T>
	const T* searchNode(const T* top_node, const typename T::value_t val, stack_t<T>& stack)
	{
		if (!top_node)
			return nullptr;
		const T* found_node = nullptr;
		const T* curr_node = top_node;
		int stack_curr = -1;
		while (curr_node)
		{
			const int cmp = curr_node->compare(val);
			if (cmp == 0)
			{
				found_node = curr_node;
				stack_curr = stack.getCurr();
				stack.push(curr_node, false);
				curr_node = curr_node->getNodeS();
			}
			else if (cmp < 0)
			{
				const T* child_node = curr_node->getNodeL();
				if (!child_node)
					break;
				stack.push(curr_node, true);
				curr_node = child_node;
			}
			else//if (cmp > 0)
			{
				const T* child_node = curr_node->getNodeS();
				if (!child_node)
					break;
				stack.push(curr_node, false);
				curr_node = child_node;
			}
		}
		if (!found_node)
			return nullptr;
		stack.setCurr(stack_curr);
		return found_node;
	}
	//--------------------
	//赤黒木操作関数：指定の値に最も近いノードを検索
	//※指定の値と同じか、内輪で最も近いノードを返す
	//※同値のノードが複数ある場合、その先頭ノードを返す
	//※内輪で最も近いノードと同値のノードが複数ある場合、その末尾ノードを返す
	template<class T>
	const T* searchNearestNode(const T* top_node, const typename T::value_t val, stack_t<T>& stack)
	{
		if (!top_node)
			return nullptr;
		const T* found_node = nullptr;
		const T* nearest_node = nullptr;
		int stack_curr = -1;
		int stack_nearest = -1;
		const T* curr_node = top_node;
		while (curr_node)
		{
			const int cmp = curr_node->compare(val);
			if (cmp == 0)
			{
				found_node = curr_node;
				stack_curr = stack.getCurr();
				stack.push(curr_node, false);
				curr_node = curr_node->getNodeS();
			}
			else if (cmp < 0)
			{
				if (!nearest_node || nearest_node && *nearest_node <= *curr_node)
				{
					nearest_node = curr_node;
					stack_nearest = stack.getCurr();
				}
				const T* child_node = curr_node->getNodeL();
				if (!child_node)
					break;
				stack.push(curr_node, true);
				curr_node = child_node;
			}
			else//if (cmp > 0)
			{
				const T* child_node = curr_node->getNodeS();
				if (!child_node)
					break;
				stack.push(curr_node, false);
				curr_node = child_node;
			}
		}
		if (!found_node && !nearest_node)
			return nullptr;
		const T* ret_node = found_node ? found_node : nearest_node;
		if (found_node)
			stack.setCurr(stack_curr);
		else if (nearest_node)
			stack.setCurr(stack_nearest);
		return ret_node;
	}
	//--------------------
	//赤黒木操作関数：ノードを追加
	template<class T>
	bool addNode(T* new_node, T*& top_node)
	{
		if (!new_node)
			return false;
		if (!top_node)
		{
			new_node->setIsBlack();
			top_node = new_node;
			return true;
		}
		stack_t<T> stack;
		T* curr_node = top_node;
		while (curr_node)
		{
			if (*curr_node <= *new_node)
			{
				T* child_node = curr_node->getNodeL();
				if (!child_node)
				{
					new_node->setIsRed();
					curr_node->setNodeL(new_node);
					break;
				}
				stack.push(curr_node, true);
				curr_node = child_node;
			}
			else//if (*curr_node > *new_node)
			{
				T* child_node = curr_node->getNodeS();
				if (!child_node)
				{
					new_node->setIsRed();
					curr_node->setNodeS(new_node);
					break;
				}
				stack.push(curr_node, false);
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
		stack_t<T> stack;
		const typename T::value_t target_value = *target_node;
		const T* remove_node = searchNode(top_node, target_value, stack);
		while (remove_node && remove_node != target_node && *remove_node == target_value)
		{
			remove_node = getNextNode(remove_node, stack);
		}
		if (!remove_node)
			return false;
		//削除
		T* node_s = const_cast<T*>(target_node->getNodeS());
		T* node_l = const_cast<T*>(target_node->getNodeL());
		const typename stack_t<T>::info_t* parent_info = stack.pop();
		if (!parent_info)
		{
			if (node_s && !node_l)
			{
				top_node = node_s;
			}
			else if (!node_s && node_l)
			{
				top_node = node_l;
			}
			else if (node_s && node_l)
			{
				stack.reset();
				T* node_sl = const_cast<T*>(getBiggestNode(node_s, stack));
				const typename stack_t<T>::info_t* sl_parent_info = stack.pop();
				if (sl_parent_info)
				{
					T* sl_parent_node = const_cast<T*>(sl_parent_info->m_nodeRef);
					sl_parent_node->setNodeL(node_sl->getNodeS());
				}
				top_node = node_sl;
				node_sl->setNodeL(node_l);
				if (node_sl != node_s)
					node_sl->setNodeS(node_s);
				else
					node_sl->setNodeS(nullptr);
			}
			else//if (!node_s && !node_l)
			{
				top_node = nullptr;
			}
		}
		else//if(parent_node)
		{
			T* parent_node = const_cast<T*>(parent_info->m_nodeRef);
			if (parent_info->m_isLarge)
			{
				if (node_s && !node_l)
				{
					parent_node->setNodeL(node_s);
				}
				else if (!node_s && node_l)
				{
					parent_node->setNodeL(node_l);
				}
				else if (node_s && node_l)
				{
					stack.reset();
					T* node_sl = const_cast<T*>(getBiggestNode(node_s, stack));
					const typename stack_t<T>::info_t* sl_parent_info = stack.pop();
					if (sl_parent_info)
					{
						T* sl_parent_node = const_cast<T*>(sl_parent_info->m_nodeRef);
						sl_parent_node->setNodeL(node_sl->getNodeS());
					}
					parent_node->setNodeL(node_sl);
					node_sl->setNodeL(node_l);
					if (node_sl != node_s)
						node_sl->setNodeS(node_s);
					else
						node_sl->setNodeS(nullptr);
				}
				else//if (!node_s && !node_l)
				{
					parent_node->setNodeL(nullptr);
				}
			}
			else//if (!parent_info->m_isLarge)
			{
				if (node_s && !node_l)
				{
					parent_node->setNodeS(node_s);
				}
				else if (!node_s && node_l)
				{
					parent_node->setNodeS(node_l);
				}
				else if (node_s && node_l)
				{
					stack.reset();
					T* node_sl = const_cast<T*>(getBiggestNode(node_s, stack));
					const typename stack_t<T>::info_t* sl_parent_info = stack.pop();
					if (sl_parent_info)
					{
						T* sl_parent_node = const_cast<T*>(sl_parent_info->m_nodeRef);
						sl_parent_node->setNodeL(node_sl->getNodeS());
					}
					parent_node->setNodeL(node_sl);
					node_sl->setNodeL(node_l);
					if (node_sl != node_s)
						node_sl->setNodeS(node_s);
					else
						node_sl->setNodeS(nullptr);
				}
				else//if (!node_s && !node_l)
				{
					parent_node->setNodeS(nullptr);
				}
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

	//左（小）側のノード取得
	data_t* getNodeS(){ return const_cast<data_t*>(m_nodeS); }
	const data_t* getNodeS() const { return m_nodeS; }
	//右（大）側のノード取得
	data_t* getNodeL(){ return const_cast<data_t*>(m_nodeL); }
	const data_t* getNodeL() const { return m_nodeL; }
	//左（小）側のノードをセット
	void setNodeS(const data_t* node){ m_nodeS = node; }
	//右（大）側のノードをセット
	void setNodeL(const data_t* node){ m_nodeL = node; }

	//ノードの色をチェック
	bool isBlack() const { return m_isBlack; }//黒か？
	bool isRed() const { return !m_isBlack; }//赤か？
	//ノードの色を変更
	void setIsBlack() { m_isBlack = true; }//黒にする
	void setIsRed() { m_isBlack = false; }//赤にする

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
	const data_t* m_nodeS;//左（小）側のノード
	const data_t* m_nodeL;//右（大）側のノード
	bool m_isBlack;//ノードの色
	value_t m_val;//値
};

//----------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	//赤黒木のトップノード
	data_t* top_node = nullptr;

	//データを登録
	{
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(0, 99);
		printf("--- make table ---\n");
		for (int i = 0; i < 100; ++i)
		{
			data_t* new_node = new data_t(rand_dist(rand_engine));
			printf("[%d] ", new_node->getVal());
			rbtree::addNode(new_node, top_node);
		}
		printf("\n");
	}

	//一番小さいノードから順に全ノードをリストアップ
	{
		printf("--- get smallest node -> get next node ---\n");
		rbtree::stack_t<data_t> stack;
		const data_t* node = rbtree::getSmallestNode(top_node, stack);
		while (node)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getNextNode(node, stack);
		}
		printf("\n");
	}

	//ノードを削除
	{
		const data_t::value_t search_val = 44;
		printf("--- remove node (%d) ---\n", search_val);
		const data_t* target_node = nullptr;
		{
			rbtree::stack_t<data_t> stack;
			target_node = rbtree::searchNode(top_node, search_val, stack);
		}
		rbtree::removeNode(target_node, top_node);
	}

	//一番大きいノードから順に全ノードをリストアップ
	{
		printf("--- get biggest node -> get previous node ---\n");
		rbtree::stack_t<data_t> stack;
		const data_t* node = rbtree::getBiggestNode(top_node, stack);
		while (node)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getPrevNode(node, stack);
		}
		printf("\n");
	}

	//指定の値のノードを検索し、同じ値のノードをリストアップ（成功パターン）
	{
		const data_t::value_t search_val = 63;
		printf("--- search node (%d) *in case of success ---\n", search_val);
		rbtree::stack_t<data_t> stack;
		const data_t* node = rbtree::searchNode(top_node, search_val, stack);
		while (node && *node == search_val)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getNextNode(node, stack);
		}
		printf("\n");
	}

	//指定の値のノードを検索（失敗パターン）
	{
		const data_t::value_t search_val = 64;
		printf("--- search node (%d) *in case of failure ---\n", search_val);
		rbtree::stack_t<data_t> stack;
		const data_t* node = rbtree::searchNode(top_node, search_val, stack);
		while (node && *node == search_val)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getNextNode(node, stack);
		}
		printf("\n");
	}

	//指定の値と同じか内輪で一番近いノードを検索
	{
		const data_t::value_t search_val = 64;
		printf("--- search nearest node (%d) ---\n", search_val);
		rbtree::stack_t<data_t> stack;
		const data_t * node = rbtree::searchNearestNode(top_node, search_val, stack);
		for (int i = 0; i < 4 && node; ++i)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getNextNode(node, stack);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}

// End of file
