#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t�p
#include <assert.h>//assert�p

//--------------------------------------------------------------------------------
//�ԍ��؁ired-black tree�j
namespace rbtree
{
	//--------------------
	//�ԍ��؃m�[�h�\���̃e���v���[�g
	//��CRTP�����p���A���L�̂悤�Ȕh���\���́^�N���X���쐬���Ďg�p����
	//��rbtree::node_t<�h���\���́^�N���X��, �l�^>
	//	struct OriginalData : public rbtree::node_t<OriginalData, int>
	//	{
	//		//�萔
	//		static const int DEPTH_MAX = 128;//�ő�̐[���i�X�^�b�N�����p�j
	//		
	//		//���i���j���̃m�[�h�擾
	//		data_t* getNodeS(){ return const_cast<data_t*>(m_nodeS); }
	//		const data_t* getNodeS() const { return m_nodeS; }
	//		//�E�i��j���̃m�[�h�擾
	//		data_t* getNodeL(){ return const_cast<data_t*>(m_nodeL); }
	//		const data_t* getNodeL() const { return m_nodeL; }
	//		//���i���j���̃m�[�h���Z�b�g
	//		void setNodeS(const data_t* node){ m_nodeS = node; }
	//		//�E�i��j���̃m�[�h���Z�b�g
	//		void setNodeL(const data_t* node){ m_nodeL = node; }
	//		
	//		//�m�[�h�̐F���`�F�b�N
	//		bool isBlack() const { return m_isBlack; }//�����H
	//		bool isRed() const { return !m_isBlack; }//�Ԃ��H
	//		//�m�[�h�̐F��ύX
	//		void setIsBlack() { m_isBlack = true; }//���ɂ���
	//		void setIsRed() { m_isBlack = false; }//�Ԃɂ���
	//		
	//		value_t getVal() const { return m_val; }//�l��Ԃ�
	//	}
	template<class T, typename V>
	struct node_t
	{
		//�^
		typedef T data_t;//�f�[�^�^
		typedef V value_t;//�l�^

		//�L���X�g�I�y���[�^
		//���l��Ԃ�
		inline operator value_t() const { return static_cast<const data_t*>(this)->getVal(); }

		//��r�I�y���[�^
		inline bool operator==(const value_t rhs) const { return static_cast<value_t>(*this) == rhs; }
		inline bool operator!=(const value_t rhs) const { return static_cast<value_t>(*this) != rhs; }
		inline bool operator<(const value_t rhs) const { return static_cast<value_t>(*this) < rhs; }
		inline bool operator>(const value_t rhs) const { return static_cast<value_t>(*this) > rhs; }
		inline bool operator<=(const value_t rhs) const { return static_cast<value_t>(*this) <= rhs; }
		inline bool operator>=(const value_t rhs) const { return static_cast<value_t>(*this) >= rhs; }

		//��r���\�b�h
		inline int compare(const value_t rhs) const
		{
			const value_t lhs = static_cast<value_t>(*this);
			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
		}
	};
	//--------------------
	//�ԍ��ؑ��쏈���p�X�^�b�N�N���X
	template<class T>
	class stack_t
	{
	public:
		//�萔
		static const int DEPTH_MAX = T::DEPTH_MAX;//�ő�̐[���i�X�^�b�N�����p�j
	public:
		//�^
		//�m�[�h���^
		struct info_t
		{
			const T* m_nodeRef;//�m�[�h�Q��
			bool m_isLarge;//�E�i��j���ɘA��
		};
	public:
		//�X�^�b�N�Ƀm�[�h�����L�^
		void push(const T* node, const bool is_large)
		{
			assert(m_curr < DEPTH_MAX);
			info_t* stack_node = &m_array[m_curr++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
		}
		//�X�^�b�N����m�[�h�����擾
		info_t* pop()
		{
			if (m_curr == 0)
				return nullptr;
			return &m_array[--m_curr];
		}
		//�X�^�b�N�ʒu���擾
		int getCurr() const { return m_curr; }
		//�X�^�b�N�ʒu���X�V
		void setCurr(const int new_curr)
		{
			if (m_curr > new_curr && new_curr >= 0)
				m_curr = new_curr;
		}
		//���Z�b�g
		void reset()
		{
			m_curr = 0;
		}
		//�R���X�g���N�^
		stack_t() :
			m_curr(0)
		{}
	private:
		//�t�B�[���h
		info_t m_array[DEPTH_MAX];//�m�[�h���̔z��i�X�^�b�N�j
		int m_curr;//�X�^�b�N�̃J�����g�ʒu
	};
	//--------------------
	//�ԍ��ؑ���֐��F��ԏ������m�[�h���擾
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
	//�ԍ��ؑ���֐��F��ԑ傫���m�[�h���擾
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
	//�ԍ��ؑ���֐��F���ɑ傫���m�[�h���擾
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
	//�ԍ��ؑ���֐��F���ɏ������m�[�h���擾
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
	//�ԍ��ؑ���֐��F�w��̒l�̃m�[�h������
	//�����l�̃m�[�h����������ꍇ�A���̐擪�m�[�h��Ԃ�
	//���݂���Ȃ������ꍇ�� nullptr ��Ԃ�
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
	//�ԍ��ؑ���֐��F�w��̒l�ɍł��߂��m�[�h������
	//���w��̒l�Ɠ������A���ւōł��߂��m�[�h��Ԃ�
	//�����l�̃m�[�h����������ꍇ�A���̐擪�m�[�h��Ԃ�
	//�����ւōł��߂��m�[�h�Ɠ��l�̃m�[�h����������ꍇ�A���̖����m�[�h��Ԃ�
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
	//�ԍ��ؑ���֐��F�m�[�h��ǉ�
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
	//�ԍ��ؑ���֐��F�m�[�h���폜
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
		//�폜
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
//�ԍ��؃e�X�g

#include <random>//C++11 random�p
#include <stdint.h>//intptr_t�p

//----------------------------------------
//�e�X�g�f�[�^
struct data_t : public rbtree::node_t<data_t, int>
{
	//�萔
	static const int DEPTH_MAX = 128;//�ő�̐[���i�X�^�b�N�����p�j

	//���i���j���̃m�[�h�擾
	data_t* getNodeS(){ return const_cast<data_t*>(m_nodeS); }
	const data_t* getNodeS() const { return m_nodeS; }
	//�E�i��j���̃m�[�h�擾
	data_t* getNodeL(){ return const_cast<data_t*>(m_nodeL); }
	const data_t* getNodeL() const { return m_nodeL; }
	//���i���j���̃m�[�h���Z�b�g
	void setNodeS(const data_t* node){ m_nodeS = node; }
	//�E�i��j���̃m�[�h���Z�b�g
	void setNodeL(const data_t* node){ m_nodeL = node; }

	//�m�[�h�̐F���`�F�b�N
	bool isBlack() const { return m_isBlack; }//�����H
	bool isRed() const { return !m_isBlack; }//�Ԃ��H
	//�m�[�h�̐F��ύX
	void setIsBlack() { m_isBlack = true; }//���ɂ���
	void setIsRed() { m_isBlack = false; }//�Ԃɂ���

	value_t getVal() const { return m_val; }//�l��Ԃ�

	//�R���X�g���N�^
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

	//�t�B�[���h
	const data_t* m_nodeS;//���i���j���̃m�[�h
	const data_t* m_nodeL;//�E�i��j���̃m�[�h
	bool m_isBlack;//�m�[�h�̐F
	value_t m_val;//�l
};

//----------------------------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	//�ԍ��؂̃g�b�v�m�[�h
	data_t* top_node = nullptr;

	//�f�[�^��o�^
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

	//��ԏ������m�[�h���珇�ɑS�m�[�h�����X�g�A�b�v
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

	//�m�[�h���폜
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

	//��ԑ傫���m�[�h���珇�ɑS�m�[�h�����X�g�A�b�v
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

	//�w��̒l�̃m�[�h���������A�����l�̃m�[�h�����X�g�A�b�v�i�����p�^�[���j
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

	//�w��̒l�̃m�[�h�������i���s�p�^�[���j
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

	//�w��̒l�Ɠ��������ւň�ԋ߂��m�[�h������
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
