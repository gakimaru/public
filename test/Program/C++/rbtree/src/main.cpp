#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t�p
#include <assert.h>//assert�p

//--------------------------------------------------------------------------------
//�ԍ��؁ired-black tree�j
//���������ߖ�̂��߂ɁA�e�m�[�h�ւ̃����N�������Ȃ��f�[�^�\���Ƃ���
//������ɁA�������̊֐����s���ɊO������X�^�b�N��n�����Őe��H�邱�Ƃ��\
//���e���v���[�g�ɂ��A�A���S���Y����ėp��
//���L�[�d���i���l�̃L�[�̃m�[�h�����������ԁj�����e����A���S���Y���Ƃ���
namespace rbtree
{
	//--------------------
	//�ԍ��؃m�[�h�\���̃e���v���[�g
	//��CRTP�����p���A���L�̂悤�Ȕh���\���́^�N���X���쐬���Ďg�p����
	//��rbtree::node_t<�h���\���́^�N���X��, �l�^>
	//	struct OriginalData : public rbtree::node_t<OriginalData, int>
	//	{
	//		//�萔
	//		static const int DEPTH_MAX = ???;//�ő�̐[���i�X�^�b�N�����p�j
	//		
	//		//�q�m�[�h�̎擾
	//		const data_t* getNodeS() const { return ???; }//���i���j���̎q�m�[�h�擾
	//		const data_t* getNodeL() const { return ???; }//��i�E�j���̎q�m�[�h�擾
	//		//�q�m�[�h��ύX
	//		void setNodeS(const data_t* node){ ??? = node; }//���i���j���̎q�m�[�h��ύX
	//		void setNodeL(const data_t* node){ ??? = node; }//��i�E�j���̎q�m�[�h��ύX
	//		
	//		//�m�[�h�̐F���`�F�b�N
	//		bool isBlack() const { return ???; }//�����H
	//		bool isRed() const { return !???; }//�Ԃ��H
	//		//�m�[�h�̐F��ύX
	//		void setIsBlack() { ??? = true; }//���ɕύX
	//		void setIsRed() { ??? = false; }//�ԂɕύX
	//		
	//		value_t getVal() const { return ???; }//�l��Ԃ�
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
			bool m_isLarge;//��i�E�j���ɘA��
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
		const T* curr_node = top_node;//���݂̒T���m�[�h
		while (true)
		{
			const T* child_node = curr_node->getNodeS();//���i���j���̎q�m�[�h���擾
			if (!child_node)//�q��������ΏI��
				return  curr_node;
			stack.push(curr_node, false);//�e�m�[�h���X�^�b�N�ɋL�^
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//�ԍ��ؑ���֐��F��ԑ傫���m�[�h���擾
	template<class T>
	const T* getLargestNode(const T* top_node, stack_t<T>& stack)
	{
		if (!top_node)
			return nullptr;
		const T* curr_node = top_node;//���݂̒T���m�[�h
		while (true)
		{
			const T* child_node = curr_node->getNodeL();//��i�E�j���̎q�m�[�h���擾
			if (!child_node)//�q��������ΏI��
				return  curr_node;
			stack.push(curr_node, true);//�e�m�[�h���X�^�b�N�ɋL�^
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�J�����g�m�[�h�̎��ɑ傫���m�[�h���擾
	template<class T>
	const T* getNextNode(const T* curr_node, stack_t<T>& stack)
	{
		if (!curr_node)
			return nullptr;
		const T* node_l = curr_node->getNodeL();//��i�E�j���̎q�m�[�h���擾
		if (node_l)//�q������ꍇ
		{
			stack.push(curr_node, true);//�e�m�[�h���X�^�b�N�ɋL�^
			return getSmallestNode(node_l, stack);//�q�����ԏ������q���m�[�h���擾
		}
		else//if(!node_l)//�q���Ȃ��ꍇ
		{
			typename stack_t<T>::info_t* stack_node = nullptr;
			while (stack_node = stack.pop())//�e�m�[�h���擾
			{
				if (stack_node->m_isLarge == false)//���i���j���̎q�̐e�Ȃ�I��
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//�ԍ��ؑ���֐��F���ɏ������m�[�h���擾
	template<class T>
	const T* getPrevNode(const T* curr_node, stack_t<T>& stack)
	{
		if (!curr_node)
			return nullptr;
		const T* node_s = curr_node->getNodeS();//���i���j���̎q�m�[�h���擾
		if (node_s)//�q������ꍇ
		{
			stack.push(curr_node, false);//�e�m�[�h���X�^�b�N�ɋL�^
			return getLargestNode(node_s, stack);//�q�����ԑ傫���q���m�[�h���擾
		}
		else//if(!node_s)//�q���Ȃ��ꍇ
		{
			typename stack_t<T>::info_t* stack_node = nullptr;
			while (stack_node = stack.pop())//�e�m�[�h���擾
			{
				if (stack_node->m_isLarge == true)//��i�E�j���̎q�̐e�Ȃ�I��
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�w��̒l�ƈ�v����m�[�h�A�������́A�w��̒l�ɍł��߂��m�[�h������
	//����v�m�[�h����������ꍇ�A���̐擪�m�[�h��Ԃ�
	//���w��̒l�̓��ւōł��߂��m�[�h�Ɠ��l�̃m�[�h����������ꍇ�A���̖����m�[�h��Ԃ�
	//���w��̒l���傫���ł��߂��m�[�h�Ɠ��l�̃m�[�h����������ꍇ�A���̐擪�m�[�h��Ԃ�
	enum E_SEARCH_TYPE
	{
		FOR_SAME = 0,//��v�m�[�h������
		FOR_NEAREST_SMALLER,//��v�m�[�h�������͓��ւōł��߂��m�[�h������
		FOR_NEAREST_LARGER,//��v�m�[�h�������͂�����傫���ł��߂��m�[�h������
	};
	template<class T>
	const T* searchNode(const T* top_node, const typename T::value_t val, stack_t<T>& stack, const E_SEARCH_TYPE search_type = FOR_SAME)
	{
		if (!top_node)
			return nullptr;
		const T* same_node = nullptr;//��v�m�[�h
		int same_stack_curr = -1;//��v�m�[�h���o���̃X�^�b�N�ʒu
		const T* nearest_node = nullptr;//�ŋ߃m�[�h
		int nearest_stack_curr = -1;//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu
		const T* curr_node = top_node;//���݂̒T���m�[�h
		while (true)
		{
			const int cmp = curr_node->compare(val);//�w��̒l�Ƒ召��r
			if (cmp == 0)//�w��̒l�ƈ�v
			{
				//���L�[�d�������e����A���S���Y���̂��߁A
				//�@��v�m�[�h���L�^������Ō����𑱍s����
				same_node = curr_node;//��v�m�[�h���L�^
				same_stack_curr = stack.getCurr();//��v�m�[�h���o���̃X�^�b�N�ʒu���L�^
				stack.push(curr_node, false);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = curr_node->getNodeS();//���i���j���̎q�̕��Ɍ����𑱍s
				if (!curr_node)//�q��������ΏI��
					break;
			}
			else if (cmp < 0)//�w��̒l��菬����
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && *nearest_node <= *curr_node))
				{
					nearest_node = curr_node;//�ŋ߃m�[�h���L�^
					nearest_stack_curr = stack.getCurr();//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu���L�^
				}
				const T* child_node = curr_node->getNodeL();//��i�E�j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
					break;
				stack.push(curr_node, true);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = child_node;
			}
			else//if (cmp > 0)//�w��̒l���傫��
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && *nearest_node >= *curr_node))
				{
					nearest_node = curr_node;//�ŋ߃m�[�h���L�^
					nearest_stack_curr = stack.getCurr();//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu���L�^
				}
				const T* child_node = curr_node->getNodeS();//���i���j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
					break;
				stack.push(curr_node, false);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = child_node;
			}
		}
		if (same_node)//��v�m�[�h���o��
		{
			stack.setCurr(same_stack_curr);//��v�m�[�h���o���̃X�^�b�N�ʒu�ɖ߂�
			return same_node;//��v�m�[�h��Ԃ�
		}
		else//if (!same_node)
		{
			if (nearest_node)//�ŋ߃m�[�h���o��
			{
				stack.setCurr(nearest_stack_curr);//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu�ɖ߂�
				return nearest_node;//�ŋ߃m�[�h��Ԃ�
			}
		}
		return nullptr;//�������s
	}
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h��ǉ�
	template<class T>
	bool addNode(T* new_node, T*& top_node)
	{
		if (!new_node)
			return false;
		if (!top_node)//�擪�m�[�h�����o�^�̏ꍇ
		{
			new_node->setIsBlack();//���m�[�h��
			top_node = new_node;//�擪�m�[�h�ɓo�^
			return true;
		}
		typename T::value_t new_val = *new_node;//�V�K�m�[�h�̒l���擾
		stack_t<T> stack;//�X�^�b�N��p��
		const T* curr_node = top_node;//���݂̒T���m�[�h
		while (true)
		{
			const int cmp = curr_node->compare(new_val);//�w��̒l�Ƒ召��r
			if (cmp <= 0)//�w��̒l�ƈ�v�������͎w��̒l��菬����
			{
				const T* child_node = curr_node->getNodeL();//��i�E�j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
				{
					new_node->setIsRed();//�ԃm�[�h��
					const_cast<T*>(curr_node)->setNodeL(new_node);//��i�E�j���̎q�m�[�h�Ƃ��ĐV�K�m�[�h��ǉ�
					break;
				}
				stack.push(curr_node, true);//�e�m�[�h���X�^�b�N�ɋL�^
				curr_node = child_node;
			}
			else//if (cmp > 0)//�w��̒l���傫��
			{
				const T* child_node = curr_node->getNodeS();//���i���j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
				{
					new_node->setIsRed();//�ԃm�[�h��
					const_cast<T*>(curr_node)->setNodeS(new_node);//��i�E�j���̎q�m�[�h�Ƃ��ĐV�K�m�[�h��ǉ�
					break;
				}
				stack.push(curr_node, false);//�e�m�[�h���X�^�b�N�ɋL�^
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
		stack_t<T> stack;//�X�^�b�N��p��
		const typename T::value_t target_value = *target_node;//�폜�m�[�h�̒l���擾
		T* remove_node = const_cast<T*>(searchNode(top_node, target_value, stack));//�폜�m�[�h�Ɠ��l�̃m�[�h����
		if (!remove_node)//�폜�m�[�h�Ɠ��l�̃m�[�h���Ȃ���ΏI��
			return false;
		while (remove_node != target_node && *remove_node == target_value)//�폜�m�[�h����
		{
			remove_node = const_cast<T*>(getNextNode(remove_node, stack));
		}
		if (remove_node != target_node)//�폜�m�[�h���Ȃ���ΏI��
			return false;
		//�폜
		T* parent_node = nullptr;//�폜�m�[�h�̐e�m�[�h
		bool parent_is_large = false;//�폜�m�[�h�̐e�m�[�h����̘A������
		{
			const typename stack_t<T>::info_t* parent_info = stack.pop();
			if (parent_info)
			{
				parent_node = const_cast<T*>(parent_info->m_nodeRef);//�e�m�[�h���擾
				parent_is_large = parent_info->m_isLarge;//�e�m�[�h����̘A������
			}
		}
		T* node_s = const_cast<T*>(remove_node->getNodeS());//���i���j���̎q�m�[�h���擾
		T* node_l = const_cast<T*>(remove_node->getNodeL());//��i�E�j���̎q�m�[�h���擾
		T* node_sl = nullptr;//�폜�m�[�h�̍ő�q���m�[�h�i�폜�m�[�h�̎��ɏ������m�[�h�j
		if (node_s && node_l)//�召�����̎q������ꍇ�A�ő�q���m�[�h����
		{
			stack.reset();//�X�^�b�N�����Z�b�g
			node_sl = const_cast<T*>(getLargestNode(node_s, stack));//�ő�q���m�[�h���擾
			const typename stack_t<T>::info_t* sl_parent_info = stack.pop();//�ő�q���m�[�h�̐e�m�[�h���擾
			if (sl_parent_info)
			{
				T* sl_parent_node = const_cast<T*>(sl_parent_info->m_nodeRef);//�ő�q���m�[�h�̐e�m�[�h���擾
				sl_parent_node->setNodeL(node_sl->getNodeS());//�ő�q���m�[�h��e�m�[�h����؂藣��
			}
			node_sl->setNodeL(node_l);//�ő�q���m�[�h�̑呤�̎q��ύX
			if (node_sl != node_s)
				node_sl->setNodeS(node_s);//�ő�q���m�[�h�̏����̎q��ύX
		}
		T* replace_node =//�폜�m�[�h�ƒu��������m�[�h
		    ( node_s && !node_l) ? node_s ://���i���j���̎q�m�[�h
		    (!node_s &&  node_l) ? node_l ://��i�E�j���̎q�m�[�h
		    ( node_s &&  node_l) ? node_sl://�ő�q���m�[�h
		  //(!node_s && !node_l) ?
			                       nullptr;//�m�[�h�폜
		if (!parent_node)//�e�m�[�h���Ȃ��ꍇ �� �擪�m�[�h���폜�m�[�h
			top_node = replace_node;//�擪�m�[�h��u������
		else//if(parent_node)//�e�m�[�h������ꍇ
		{
			if (parent_is_large)
				parent_node->setNodeL(replace_node);//�e�m�[�h�̑�i�E�j���̎q�m�[�h��u������
			else//if (!parent_is_large)
				parent_node->setNodeS(replace_node);//�e�m�[�h�̏��i���j���̎q�m�[�h��u������
		}
		return true;
	}
}//namespace rbtree

//--------------------------------------------------------------------------------
//�ԍ��؃e�X�g

#include <random>//C++11 random�p
//#include <stdint.h>//intptr_t�p

//----------------------------------------
//�e�X�g�f�[�^
struct data_t : public rbtree::node_t<data_t, int>
{
	//�萔
	static const int DEPTH_MAX = 128;//�ő�̐[���i�X�^�b�N�����p�j

	//�q�m�[�h�̎擾
	const data_t* getNodeS() const { return m_nodeS; }//���i���j���̎q�m�[�h�擾
	const data_t* getNodeL() const { return m_nodeL; }//��i�E�j���̎q�m�[�h�擾
	//�q�m�[�h��ύX
	void setNodeS(const data_t* node){ m_nodeS = node; }//���i���j���̎q�m�[�h��ύX
	void setNodeL(const data_t* node){ m_nodeL = node; }//��i�E�j���̎q�m�[�h��ύX

	//�m�[�h�̐F���`�F�b�N
	bool isBlack() const { return m_isBlack; }//�����H
	bool isRed() const { return !m_isBlack; }//�Ԃ��H
	//�m�[�h�̐F��ύX
	void setIsBlack() { m_isBlack = true; }//���ɕύX
	void setIsRed() { m_isBlack = false; }//�ԂɕύX

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
	const data_t* m_nodeL;//��i�E�j���̃m�[�h
	bool m_isBlack;//�m�[�h�̐F
	value_t m_val;//�l
};

//----------------------------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	static const int val_min = 0;//�l�̍ŏ��l
	static const int val_max = 99;//�l�̍ő�l
	static const int reg_num = 100;//�o�^��

	//�ԍ��؂̃g�b�v�m�[�h
	data_t* top_node = nullptr;

	//�f�[�^��o�^
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

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
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

	//��ԑ傫���m�[�h����~���ɑS�m�[�h�����X�g�A�b�v
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

	//�w��̒l�̃m�[�h���������A�����l�̃m�[�h�����X�g�A�b�v
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

	//�w��̒l�Ɠ��������ւň�ԋ߂��m�[�h������
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

	//�w��̒l�Ɠ�����������傫���ŋ߃m�[�h������
	searchNearestData(rbtree::FOR_NEAREST_LARGER);

	//�m�[�h���폜
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

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();

	//�m�[�h���폜
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

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();

	return EXIT_SUCCESS;
}

// End of file
