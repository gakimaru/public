#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t用
#include <assert.h>//assert用

//赤黒木（red-black tree）
namespace rbtree
{
	template<class T, typename V>
	struct node_t
	{
		typedef V value_t;
		
		inline operator V() const { return static_cast<const T*>(this)->getVal(); }
		inline bool operator==(const V rhs) const
		{
			return static_cast<V>(*this) == rhs;
		}
		inline bool operator!=(const V rhs) const
		{
			return static_cast<V>(*this) != rhs;
		}
		inline bool operator<(const V rhs) const
		{
			return static_cast<V>(*this) < rhs;
		}
		inline bool operator>(const V rhs) const
		{
			return static_cast<V>(*this) > rhs;
		}
		inline bool operator<=(const V rhs) const
		{
			return static_cast<V>(*this) <= rhs;
		}
		inline bool operator>=(const V rhs) const
		{
			return static_cast<V>(*this) >= rhs;
		}
		inline int compare(const V rhs) const
		{
			const V lhs = static_cast<V>(*this);
			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
		}
	};
	template<class T>
	struct stackNode_t
	{
		const T* m_node;
		bool m_isLarge;
	};
	template<class T>
	class stack_t
	{

	public:
		static const std::size_t STACK_SIZE = T::STACK_SIZE;
		typedef stackNode_t<T> node_t;
		void push(const T* node, const bool is_large)
		{
			assert(m_curr < STACK_SIZE);
			stackNode_t<T>* stack_node = &m_array[m_curr++];
			stack_node->m_node = node;
			stack_node->m_isLarge = is_large;
		}
		stackNode_t<T>* pop()
		{
			if (m_curr == 0)
				return nullptr;
			return &m_array[--m_curr];
		}
		stack_t() :
			m_curr(0)
		{}
	private:
		stackNode_t<T> m_array[STACK_SIZE];
		std::size_t m_curr;
	};
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
			stackNode_t<T>* stack_node = nullptr;
			while (stack_node = stack.pop())
			{
				if (stack_node->m_isLarge == false)
				{
					node_l = stack_node->m_node;
					break;
				}
			}
		}
		return node_l;
	}
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
			stackNode_t<T>* stack_node = nullptr;
			while (stack_node = stack.pop())
			{
				if (stack_node->m_isLarge == true)
				{
					node_s = stack_node->m_node;
					break;
				}
			}
		}
		return node_s;
	}
	template<class T>
	const T* searchNode(const T* top_node, const typename T::value_t val, stack_t<T>& stack)
	{
		if (!top_node)
			return nullptr;
		const T* found_node = nullptr;
		const T* last_node = nullptr;
		const T* curr_node = top_node;
		while (curr_node)
		{
			const int cmp = curr_node->compare(val);
			if(cmp == 0)
			{
				found_node = curr_node;
				stack.push(curr_node, false);
				last_node = curr_node;
				curr_node = curr_node->getNodeS();
			}
			else if (cmp < 0)
			{
				const T* child_node = curr_node->getNodeL();
				if (!child_node)
					break;
				stack.push(curr_node, true);
				last_node = curr_node;
				curr_node = child_node;
			}
			else//if (cmp > 0)
			{
				const T* child_node = curr_node->getNodeS();
				if (!child_node)
					break;
				stack.push(curr_node, false);
				last_node = curr_node;
				curr_node = child_node;
			}
		}
		if (!found_node)
			return nullptr;
		if (found_node == last_node)
			stack.pop();
		return found_node;
	}
	template<class T>
	const T* searchNearestNode(const T* top_node, const typename T::value_t val, stack_t<T>& stack)
	{
		if (!top_node)
			return nullptr;
		const T* found_node = nullptr;
		const T* nearest_node = nullptr;
		const T* last_node = nullptr;
		const T* curr_node = top_node;
		while (curr_node)
		{
			const int cmp = curr_node->compare(val);
			if (cmp == 0)
			{
				found_node = curr_node;
				stack.push(curr_node, false);
				last_node = curr_node;
				curr_node = curr_node->getNodeS();
			}
			else if (cmp < 0)
			{
				if (!nearest_node || nearest_node && *nearest_node <= *curr_node)
					nearest_node = curr_node;
				const T* child_node = curr_node->getNodeL();
				if (!child_node)
					break;
				stack.push(curr_node, true);
				last_node = curr_node;
				curr_node = child_node;
			}
			else//if (cmp > 0)
			{
				const T* child_node = curr_node->getNodeS();
				if (!child_node)
					break;
				stack.push(curr_node, false);
				last_node = curr_node;
				curr_node = child_node;
			}
		}
		if (!found_node && !nearest_node)
			return nullptr;
		const T* ret_node = found_node ? found_node : nearest_node;
		if (ret_node == last_node)
			stack.pop();
		return ret_node;
	}
	template<class T>
	void addNode(T* new_node, T*& top_node)
	{
		if (!new_node)
			return;
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
		if (!curr_node)
		{
			new_node->setIsBlack();
			top_node = new_node;
			return;
		}
	}
}

#include <stdint.h>//intptr_t用

//テストデータ
struct data_t : public rbtree::node_t<data_t, int>
{
	static const std::size_t STACK_SIZE = 128;
	
	data_t* getNodeS(){ return const_cast<data_t*>(m_nodeS); }
	const data_t* getNodeS() const { return m_nodeS; }
	data_t* getNodeL(){ return const_cast<data_t*>(m_nodeL); }
	const data_t* getNodeL() const { return m_nodeL; }
	void setNodeS(const data_t* node){ m_nodeS = node; }
	void setNodeL(const data_t* node){ m_nodeL = node; }
	
	bool isBlack() const { return m_isBlack; }
	bool isRed() const { return !m_isBlack; }
	void setIsBlack() { m_isBlack = true; }
	void setIsRed() { m_isBlack = false; }
	
	value_t getVal() const { return m_val; }

	const data_t* m_nodeS;
	const data_t* m_nodeL;
	bool m_isBlack;
	value_t m_val;

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
};

//テスト
int main(const int argc, const char* argv[])
{
	data_t* top_node = nullptr;
	{
		printf("--- make table ---\n");
		for (int i = 0; i < 100; ++i)
		{
			data_t* new_node = new data_t(rand() % 100);
			rbtree::addNode(new_node, top_node);
		}
		printf("\n");
	}
	{
		printf("--- get smallest node ---\n");
		rbtree::stack_t<data_t> stack;
		const data_t* node = rbtree::getSmallestNode(top_node, stack);
		while (node)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getNextNode(node, stack);
		}
		printf("\n");
	}
	{
		printf("--- get biggest node ---\n");
		rbtree::stack_t<data_t> stack;
		const data_t* node = rbtree::getBiggestNode(top_node, stack);
		while (node)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getPrevNode(node, stack);
		}
		printf("\n");
	}
	{
		rbtree::stack_t<data_t> stack;
		const data_t::value_t search_val = 29;
		printf("--- search node (%d) *in case of success ---\n", search_val);
		const data_t* node = rbtree::searchNode(top_node, search_val, stack);
		while (node && *node == search_val)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getNextNode(node, stack);
		}
		printf("\n");
	}
	{
		rbtree::stack_t<data_t> stack;
		const data_t::value_t search_val = 30;
		printf("--- search node (%d) *in case of failure ---\n", search_val);
		const data_t* node = rbtree::searchNode(top_node, search_val, stack);
		while (node && *node == search_val)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getNextNode(node, stack);
		}
		printf("\n");
	}
	{
		rbtree::stack_t<data_t> stack;
		const data_t::value_t search_val = 30;
		printf("--- search nearest node (%d) ---\n", search_val);
		const data_t * node = rbtree::searchNearestNode(top_node, search_val, stack);
		while (node)
		{
			printf("[%d] ", node->getVal());
			node = rbtree::getNextNode(node, stack);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}

// End of file
