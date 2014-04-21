#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t�p
#include <memory.h>//memcpy�p
#include <assert.h>//assert�p
#include <iterator>//std::iterator�p
#include <algorithm>//algorithm�p

//--------------------------------------------------------------------------------
//�ԍ��؁ired-black tree�j
//���������ߖ�̂��߂ɁA�e�m�[�h�ւ̃����N�������Ȃ��f�[�^�\���Ƃ���B
//������ɁA�������̊֐����s���ɊO������X�^�b�N��n�����Őe��H�邱�Ƃ��\�B
//���e���v���[�g�ɂ��A�A���S���Y����ėp���B
//���L�[�d���i���L�[�̃m�[�h�����������ԁj�����e����A���S���Y���Ƃ���B
//�������N�̕��@�ɏ_����������A���Avirtual������邽�߂ɁA
//�@CRTP�����p���āA�h���N���X�Ŋ������̃��\�b�h����������X�^�C���Ƃ���B
//�@�i����ɂ��A�|�C���^�ϐ��ɂ�郊���N�̕ێ��ȊO�̃X�^�C���ɂ��Ή��\�B
//�@�@�Ⴆ�΁A�z��̃C���f�b�N�X�Ń����N�����悤�ȃX�^�C���ɂ��Ή��ł���B�j
//��std::map��͂����R���e�i�ƃC�e���[�^�𗘗p�\�B
//----------------------------------------
//�y��̓I�Ȋ��p�̑z��z
//�E�������}�l�[�W���̊Ǘ����̘A���Ɏg�p���邱�Ƃ�z��B
//�E�󂫃������T�C�Y���̘A�����s�����߁A�L�[�d�������e����K�v������B
//�E�܂��A�A�����X�g����剻���邱�Ƃ�����邽�߁A�e�m�[�h�ւ̃����N����
//�@�����Ȃ��B
//�E�K�v�ʈȏ�̋󂫃������̃m�[�h�����������̂��A�A���C�������g����������
//�@��ŗ��p�\�ȃm�[�h�����m�F���A����傫�ȃm�[�h��H���čœK��
//�@�m�[�h��T���o���B
//�E�m�[�h�Ԃ̃����N���́A64bit�|�C���^�ϐ��ɂ���剻���N����Ȃ��悤�ɁA
//�@��������Ԃ̐擪����I�t�Z�b�g���ꂽ32bit�̑��΃|�C���^�������B
namespace rbtree
{
	//--------------------
	//�ԍ��؃m�[�h�\���̃e���v���[�g
	//��CRTP�����p���A���L�̂悤�Ȕh���\���́^�N���X���쐬���Ďg�p����
	//  //struct �h���\���́^�N���X�� : public rbtree::node_t<�h���\���́^�N���X��, �L�[�^>
	//	struct Derived : public rbtree::node_t<Derived, int>
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
	//		//�L�[��Ԃ�
	//		key_t getKey() const { return ???; }
	//	}
	template<class T, typename V>
	struct node_t
	{
		//�^
		typedef T impl_t;//�����^�istruct impl_t : public rbtree::node_t<impl_t, int>�j
		typedef V key_t;//�L�[�^

		//�L���X�g�I�y���[�^
		//���L�[��Ԃ�
		inline operator key_t() const { return static_cast<const impl_t*>(this)->getKey(); }

		//��r�I�y���[�^
		inline bool operator==(const key_t rhs) const { return static_cast<key_t>(*this) == rhs; }
		inline bool operator!=(const key_t rhs) const { return static_cast<key_t>(*this) != rhs; }
		inline bool operator<(const key_t rhs) const { return static_cast<key_t>(*this) < rhs; }
		inline bool operator>(const key_t rhs) const { return static_cast<key_t>(*this) > rhs; }
		inline bool operator<=(const key_t rhs) const { return static_cast<key_t>(*this) <= rhs; }
		inline bool operator>=(const key_t rhs) const { return static_cast<key_t>(*this) >= rhs; }

		//�L�[��r���\�b�h
		inline int compare(const key_t rhs) const
		{
			const key_t lhs = static_cast<key_t>(*this);
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
			assert(m_depth < DEPTH_MAX);
			info_t* stack_node = &m_array[m_depth++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
		}
		//�X�^�b�N����m�[�h�����擾
		info_t* pop()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[--m_depth];
		}
		//�X�^�b�N�̌��݂̐[�����擾
		int getDepth() const { return m_depth; }
		//�X�^�b�N�̌��݂̐[�����X�V
		void setDepth(const int depth)
		{
			if (depth < 0)
				m_depth = 0;
			else if (depth < m_depth)
				m_depth = depth;
		}
		//�X�^�b�N�̌��݂̐[�������Z�b�g
		void reset()
		{
			m_depth = 0;
		}
		//�X�^�b�N�̌��݂̕����Z�o
		//���u���v���X�^�b�N�̌��݂̐[���܂ł̑召�A���̍��v�l���Z�o
		//��������-1�A�呤��+1�Ƃ��Čv�Z
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
		//�R�s�[�I�y���[�^
		stack_t& operator=(const stack_t rhs)
		{
			m_depth = rhs.m_depth;
			memcpy(m_array, rhs.m_array, sizeof(info_t)* m_depth);
		}
		//�R�s�[�R���X�g���N�^
		stack_t(const stack_t& obj) :
			m_depth(obj.m_depth)
		{
			memcpy(m_array, obj.m_array, sizeof(info_t)* m_depth);
		}
		//�R���X�g���N�^
		stack_t() :
			m_depth(0)
		{}
	private:
		//�t�B�[���h
		info_t m_array[DEPTH_MAX];//�m�[�h���̔z��i�X�^�b�N�j
		int m_depth;//�X�^�b�N�̃J�����g�̐[��
	};
	//--------------------
	//�ԍ��ؑ���֐��F��ԏ������m�[�h���擾
	//���ォ��get**Node()��searchNode()�����s�ł���悤�ɁA�X�^�b�N��n���K�v����
	template<class T>
	const T* getSmallestNode(const T* root, stack_t<T>& stack)
	{
		if (!root)
			return nullptr;
		const T* curr_node = root;//���݂̒T���m�[�h
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
	//���ォ��get**Node()��searchNode()�����s�ł���悤�ɁA�X�^�b�N��n���K�v����
	template<class T>
	const T* getLargestNode(const T* root, stack_t<T>& stack)
	{
		if (!root)
			return nullptr;
		const T* curr_node = root;//���݂̒T���m�[�h
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
	//��get**Node()��searchNode()�ŃJ�����g�m�[�h���擾�����ۂ̃X�^�b�N��n���K�v����
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
	//�ԍ��ؑ���֐��F�J�����g�m�[�h�̎��ɏ������m�[�h���擾
	//��get**Node()��searchNode()�ŃJ�����g�m�[�h���擾�����ۂ̃X�^�b�N��n���K�v����
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
	//�ԍ��ؑ���֐��F�c���[�̍ő�̐[�����v��
	//�������ŃX�^�b�N���쐬
	//��-1�Ń��X�g�Ȃ�
	template<class T>
	int getDepthMax(const T* root)
	{
		if (!root)
			return -1;
		int depth_max = 0;//�ő�̐[��
		rbtree::stack_t<T> stack;//�X�^�b�N���쐬
		const T* node = rbtree::getSmallestNode(root, stack);//�ŏ��m�[�h�擾
		while (node)
		{
			const int depth = stack.getDepth();//�[�����擾
			depth_max = depth_max >= depth ? depth_max : depth;//�ő�̐[�����X�V
			node = rbtree::getNextNode(node, stack);//���̃m�[�h�擾
		}
		return depth_max;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�w��̃L�[�ƈ�v����m�[�h�A�������́A�w��̃L�[�ɍł��߂��m�[�h������
	//���ォ��get**Node()��searchNode()�����s�ł���悤�ɁA�X�^�b�N��n���K�v����
	//����v�m�[�h����������ꍇ�A���̍ŏ��̃m�[�h��Ԃ�
	//���w��̃L�[�̓��ւōł��߂��m�[�h�Ɠ��L�[�̃m�[�h����������ꍇ�A���̍Ō�̃m�[�h��Ԃ�
	//���w��̃L�[���傫���ł��߂��m�[�h�Ɠ��L�[�̃m�[�h����������ꍇ�A���̍ŏ��̃m�[�h��Ԃ�
	enum MATCH_TYPE_T
	{
		FOR_MATCH = 0,//��v�m�[�h������
		FOR_NEAREST_SMALLER,//��v�m�[�h�A�������́A���ւōł��߂��m�[�h������
		FOR_NEAREST_LARGER,//��v�m�[�h�A�������́A������傫���ł��߂��m�[�h������
	};
	template<class T>
	const T* searchNode(const T* root, const typename T::key_t key, stack_t<T>& stack, const MATCH_TYPE_T search_type = FOR_MATCH)
	{
		if (!root)
			return nullptr;
		const T* match_node = nullptr;//��v�m�[�h
		int match_stack_depth = -1;//��v�m�[�h���o���̃X�^�b�N�ʒu
		const T* nearest_node = nullptr;//�ŋ߃m�[�h
		int nearest_stack_depth = -1;//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu
		const T* curr_node = root;//���݂̒T���m�[�h
		while (true)
		{
			const int cmp = curr_node->compare(key);//�w��̃L�[�Ƒ召��r
			if (cmp == 0)//�w��̃L�[�ƈ�v
			{
				//���L�[�d�������e����A���S���Y���̂��߁A
				//�@��v�m�[�h���L�^������Ō����𑱍s����
				match_node = curr_node;//��v�m�[�h���L�^
				match_stack_depth = stack.getDepth();//��v�m�[�h���o���̃X�^�b�N�ʒu���L�^
				stack.push(curr_node, false);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = curr_node->getNodeS();//���i���j���̎q�̕��Ɍ����𑱍s
				if (!curr_node)//�q��������ΏI��
					break;
			}
			else if (cmp < 0)//�w��̃L�[��菬����
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && *nearest_node <= *curr_node))
				{
					nearest_node = curr_node;//�ŋ߃m�[�h���L�^
					nearest_stack_depth = stack.getDepth();//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu���L�^
				}
				const T* child_node = curr_node->getNodeL();//��i�E�j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
					break;
				stack.push(curr_node, true);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = child_node;
			}
			else//if (cmp > 0)//�w��̃L�[���傫��
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && *nearest_node >= *curr_node))
				{
					nearest_node = curr_node;//�ŋ߃m�[�h���L�^
					nearest_stack_depth = stack.getDepth();//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu���L�^
				}
				const T* child_node = curr_node->getNodeS();//���i���j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
					break;
				stack.push(curr_node, false);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = child_node;
			}
		}
		if (match_node)//��v�m�[�h���o��
		{
			stack.setDepth(match_stack_depth);//��v�m�[�h���o���̃X�^�b�N�ʒu�ɖ߂�
			return match_node;//��v�m�[�h��Ԃ�
		}
		else//if (!match_node)
		{
			if (nearest_node)//�ŋ߃m�[�h���o��
			{
				stack.setDepth(nearest_stack_depth);//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu�ɖ߂�
				return nearest_node;//�ŋ߃m�[�h��Ԃ�
			}
		}
		return nullptr;//�������s
	}
	//--------------------
	//�ԍ��ؑ���֐��F�c���[�̃m�[�h�����v��
	template<class T>
	std::size_t countNodes(const T* node)
	{
		if (!node)
			return 0;
		int count = 0;//�m�[�h��
		++count;
		const T* node_s = node->getNodeS();
		const T* node_l = node->getNodeL();
		if (node_s)
			count += getNodeCount(node_s);
		if (node_l)
			count += getNodeCount(node_l);
		return count;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�w��̃L�[�̃m�[�h�����v��
	//�������ŃX�^�b�N���쐬
	template<class T>
	std::size_t countNodes(const T* root, const typename T::key_t key)
	{
		if (!root)
			return 0;
		stack_t<T> stack;
		const T* node = searchNode(root, key, stack, FOR_MATCH);
		if (!node)
			return 0;
		int count = 0;//�m�[�h��
		while (node)
		{
			++node;
			node = getNextNode(node, stack);
		}
		return count;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h��ǉ�
	template<class T>
	bool addNode(T* new_node, T*& root)
	{
		if (!new_node)
			return false;
		if (!root)//���[�g�m�[�h�����o�^�̏ꍇ
		{
			root = new_node;//���[�g�m�[�h�ɓo�^
			return true;
		}
		typename T::key_t new_key = *new_node;//�V�K�m�[�h�̃L�[���擾
		stack_t<T> stack;//�X�^�b�N��p��
		const T* curr_node = root;//���݂̒T���m�[�h
		while (true)
		{
			const int cmp = curr_node->compare(new_key);//�w��̃L�[�Ƒ召��r
			if (cmp <= 0)//�w��̃L�[�ƈ�v�������͎w��̃L�[��菬����
			{
				const T* child_node = curr_node->getNodeL();//��i�E�j���̎q�m�[�h���擾
				if (!child_node)//�q��������΂����ɐV�K�m�[�h��ǉ����ďI��
				{
					const_cast<T*>(curr_node)->setNodeL(new_node);//��i�E�j���̎q�m�[�h�Ƃ��ĐV�K�m�[�h��ǉ�
					break;
				}
				stack.push(curr_node, true);//�e�m�[�h���X�^�b�N�ɋL�^
				curr_node = child_node;
			}
			else//if (cmp > 0)//�w��̃L�[���傫��
			{
				const T* child_node = curr_node->getNodeS();//���i���j���̎q�m�[�h���擾
				if (!child_node)//�q��������΂����ɐV�K�m�[�h��ǉ����ďI��
				{
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
	bool removeNode(const T* target_node, T*& root)
	{
		if (!target_node || !root)
			return false;
		stack_t<T> stack;//�X�^�b�N��p��
		const typename T::key_t remove_key = *target_node;//�폜�m�[�h�̃L�[���擾
		T* remove_node = const_cast<T*>(searchNode(root, remove_key, stack));//�폜�m�[�h�Ɠ��L�[�̃m�[�h����
		if (!remove_node)//�폜�m�[�h�Ɠ��L�[�̃m�[�h���Ȃ���ΏI��
			return false;
		while (remove_node != target_node && *remove_node == remove_key)//�폜�m�[�h����
		{
			remove_node = const_cast<T*>(getNextNode(remove_node, stack));
		}
		if (remove_node != target_node)//�폜�m�[�h���Ȃ���ΏI��
			return false;
		//�폜�J�n
		T* parent_node = nullptr;//�폜�m�[�h�̐e�m�[�h
		bool parent_is_large = false;//�폜�m�[�h�̐e�m�[�h����̘A������
		{
			const typename stack_t<T>::info_t* parent_info = stack.pop();//�e�m�[�h�Q�Ə����擾
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
			(node_s && !node_l) ? node_s ://���i���j���̎q�m�[�h
			(!node_s &&  node_l) ? node_l ://��i�E�j���̎q�m�[�h
			(node_s &&  node_l) ? node_sl ://�ő�q���m�[�h
			//(!node_s && !node_l) ?
			nullptr;//�m�[�h�폜
		if (!parent_node)//�e�m�[�h���Ȃ��ꍇ �� ���[�g�m�[�h���폜�m�[�h
			root = replace_node;//���[�g�m�[�h��u������
		else//if(parent_node)//�e�m�[�h������ꍇ
		{
			if (parent_is_large)
				parent_node->setNodeL(replace_node);//�e�m�[�h�̑�i�E�j���̎q�m�[�h��u������
			else//if (!parent_is_large)
				parent_node->setNodeS(replace_node);//�e�m�[�h�̏��i���j���̎q�m�[�h��u������
		}
		return true;
	}
	//--------------------
	//�ԍ��؃R���e�i
	//�����[�g�̃����N�����̂�
	//��std::map��͂����\��
	template<class T>
	class container
	{
	public:
		//�^
		typedef stack_t<T> stack_type;
		typedef T node_type;
		typedef typename T::key_t key_type;
		typedef std::size_t size_type;
	public:
		//--------------------
		//�C�e���[�^
		class iterator;
		typedef const iterator const_iterator;
		//typedef public std::reverse_iterator<iterator> reverse_iterator;//����͎g��Ȃ�
		class reverse_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
			friend class container;
		public:
			//�L���X�g�I�y���[�^
			operator const node_type() const { return *m_node; }
			operator node_type(){ return *m_node; }
			operator key_type() const { return static_cast<key_type>(*m_node); }
		public:
			//�I�y���[�^
			const node_type& operator*() const { return *m_node; }
			node_type& operator*(){ return *m_node; }
			const node_type* operator->() const { return m_node; }
			node_type* operator->(){ return m_node; }
			//��r�I�y���[�^
			bool operator==(const_iterator& rhs) const
			{
				return m_node == nullptr && rhs.m_node == nullptr ? true :
					m_node == nullptr || rhs.m_node == nullptr ? false :
					m_node->getKey() == rhs.m_node->getKey();
			}
			bool operator!=(const_iterator& rhs) const
			{
				return m_node == nullptr && rhs.m_node == nullptr ? false :
					m_node == nullptr || rhs.m_node == nullptr ? true :
					m_node->getKey() != rhs.m_node->getKey();
			}
			bool operator<(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
					m_node->getKey() < rhs.m_node->getKey();
			}
			bool operator>(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
					m_node->getKey() > rhs.m_node->getKey();
			}
			bool operator<=(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
					m_node->getKey() <= rhs.m_node->getKey();
			}
			bool operator>=(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
					m_node->getKey() >= rhs.m_node->getKey();
			}
			//���Z�q�I�y���[�^
			const_iterator& operator++() const
			{
				m_node = const_cast<node_type*>(getNextNode(m_node, m_stack));
				return *this;
			}
			const_iterator& operator--() const
			{
				m_node = const_cast<node_type*>(getPrevNode(m_node, m_stack));
				return *this;
			}
			iterator& operator++()
			{
				m_node = const_cast<node_type*>(getNextNode(m_node, m_stack));
				return *this;
			}
			iterator& operator--()
			{
				m_node = const_cast<node_type*>(getPrevNode(m_node, m_stack));
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
			//�R�s�[�I�y���[�^
			iterator& operator=(const_iterator& rhs)
			{
				m_stack = rhs.m_stack;
				m_node = rhs.m_node;
			}
		public:
			//���Z�b�g
			void reset() const
			{
				m_stack.reset();
				m_node = nullptr;
			}
		public:
			//�R�s�[�R���X�g���N�^
			iterator(const_iterator& obj) :
				m_stack(obj.m_stack),
				m_node(obj.m_node)
			{}
			//�R���X�g���N�^
			iterator() :
				m_stack(),
				m_node(nullptr)
			{}
			iterator(const node_type* node, const stack_type& stack) :
				m_stack(*const_cast<stack_type*>(&stack)),
				m_node(const_cast<node_type*>(node))
			{}
			//�f�X�g���N�^
			~iterator()
			{}
		protected:
			//�t�B�[���h
			mutable stack_type m_stack;//�X�^�b�N
			mutable node_type* m_node;//���݂̃m�[�h
		};
		//--------------------
		//���o�[�X�C�e���[�^
		//��begin(), end() �̗v�����኱����Ȃ̂ŁA
		//�@std::reverse_iterator<iterator>���g�킸�Ɏ����i�U���j�B
		//�@���g��operator��+��-���t�]���Ă��邾���ŁA
		//�@�ʏ�̃C�e���[�^�Ɠ����B
		class reverse_iterator : public iterator
		{
		public:
			//���Z�q�I�y���[�^
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
			//�R�s�[�R���X�g���N�^
			reverse_iterator(const_iterator& obj) :
				iterator(obj)
			{}
			//�R���X�g���N�^
			reverse_iterator() :
				iterator()
			{}
			reverse_iterator(const node_type* node, const stack_type& stack) :
				iterator(node, stack)
			{}
			//�f�X�g���N�^
			~reverse_iterator()
			{}
		};
	public:
		//���\�b�h�F�C�e���[�^�n
		const_iterator& _begin(const_iterator& ite) const
		{
			ite.m_node = const_cast<node_type*>(getSmallestNode(m_root, ite.m_stack));
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
		const_reverse_iterator& _rbegin(const_reverse_iterator& ite) const
		{
			ite.m_node = const_cast<node_type*>(getLargestNode(m_root, ite.m_stack));
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
		//���\�b�h�F�e�ʌn
		bool empty() const { return m_root == nullptr; }
		size_type size() const { return countNodes(m_root); }
		//size_type max_size() const { return getNodeCount(m_root); }
		int depth_max() const { return getDepthMax(m_root); }
		//���\�b�h�F�v�f�A�N�Z�X�n
		//��std::map�ƈقȂ�A�m�[�h�̃|�C���^��Ԃ�
		inline const node_type* _at(const key_type key) const
		{
			stack_type stack;
			return searchNode(m_root, key, stack, FOR_MATCH);
		}
		const node_type* at(const key_type key) const { return _at(key); }
		node_type* at(const key_type key){ return const_cast<node_type*>(_at(key)); }
		const node_type* operator[](const key_type key) const { return _at(key); }
		node_type* operator[](const key_type key){ return const_cast<node_type*>(_at(key)); }
		//���\�b�h�F�ǉ��^�폜�n
		//��std::map�ƈقȂ�A�m�[�h�𒼐ڎw�肵�A���ʂ�bool�^�Ŏ󂯎��
		//���v�f�̃������m�ہ^�폜���s��Ȃ��_�ɒ���
		bool insert(const node_type& node){ return addNode(const_cast<node_type*>(&node), m_root); }
		bool erase(const node_type& node){ return removeNode(&node, m_root); }
		void clear(){ m_root = nullptr; }
		//���\�b�h�F�����n
		//��lower_bound(), upper_bound()�ɂ͔�Ή�
		//������ɁAfind_nearest�ɑΉ�
		const_iterator& _find(const_iterator& ite, const key_type key, const MATCH_TYPE_T type = FOR_MATCH) const
		{
			ite.m_node = const_cast<node_type*>(searchNode(m_root, key, ite.m_stack, type));
			return ite;
		}
		const_iterator find(const key_type key, const MATCH_TYPE_T type = FOR_MATCH) const
		{
			const_iterator ite;
			return _find(ite, key, type);
		}
		iterator find(const key_type key, const MATCH_TYPE_T type = FOR_MATCH)
		{
			iterator ite;
			return _find(ite, key, type);
		}
		size_type count(const key_type key) const { return countNodes(m_root, key, FOR_MATCH); }
		const_iterator& _equal_range(const_iterator& ite, const key_type key) const
		{
			ite.m_node = const_cast<node_type*>(searchNode(m_root, key, ite.m_stack, FOR_MATCH));
			while (ite.m_node && *ite == key)
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
		//���̑�
		const node_type* root() const { return m_root; }
		node_type*& root_ref(){ return m_root; }
	public:
		//�R�s�[�R���X�g���N�^
		container(const container& con) :
			m_root(con.m_root)
		{}
		//�R���X�g���N�^
		container() :
			m_root(nullptr)
		{}
		//�f�X�g���N�^
		~container()
		{}
	private:
		//�t�B�[���h
		node_type* m_root;//���[�g�m�[�h
	};
}//namespace rbtree

//--------------------------------------------------------------------------------
//�ԍ��؃e�X�g

#include <algorithm>//std::max�p
#include <random>//C++11 std::random�p

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

	//�L�[��Ԃ�
	key_t getKey() const { return m_key; }

	//�R���X�g���N�^
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

	//�t�B�[���h
	const data_t* m_nodeS;//���i���j���̃m�[�h
	const data_t* m_nodeL;//��i�E�j���̃m�[�h
	bool m_isBlack;//�m�[�h�̐F
	key_t m_key;//�L�[
};

//----------------------------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	static const int key_min = 0;//�ŏ��L�[
	static const int key_max = 99;//�ő�L�[
	static const int reg_num = 100;//�o�^��

	//�ԍ��؃R���e�i
	typedef rbtree::container<data_t> container_t;
	typedef container_t::iterator iterator;
	typedef container_t::const_iterator const_iterator;
	typedef container_t::reverse_iterator reverse_iterator;
	typedef container_t::const_reverse_iterator const_reverse_iterator;
	container_t con;

	//�f�[�^��o�^
	auto regList = [&con]()
	{
		printf("--- make table ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(key_min, key_max);
		for (int i = 0; i < reg_num; ++i)
		{
			data_t* new_node = new data_t(rand_dist(rand_engine));
			printf("[%d] ", new_node->getKey());
			con.insert(*new_node);
		}
		printf("\n");
	};
	regList();

	//�c���[��\��
	auto showTree = [&con]()
	{
		printf("--- show tree ---\n");
		static const int depth_limit = 3;
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
				for (int depth_tmp = 0; node && depth_tmp < depth; ++depth_tmp)
				{
					node = (breath_tmp & (0x1 << depth_tmp)) ?
						node->getNodeL() :
						node->getNodeS();
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (node->getNodeS() && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(node->getNodeS() ? "-" : " ");
					}
					printf("%s%2d:%c%s", node->getNodeS() ? "{" : "[", node->getKey(), node->isBlack() ? 'B' : 'R', node->getNodeL() ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(node->getNodeL() ? "-" : " ");
						if (node->getNodeL() && c < print_indent)
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

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	auto showListAsc = [&con]()
	{
		printf("--- get smallest node -> get next node ---\n");
		bool is_found = false;
		for (const data_t& obj : con)//C++11�`���͈̔͂Ɋ�Â�for���[�v
		{
			if (!is_found)
				is_found = true;
			printf("[%d] ", obj.getKey());
		}
		if (is_found)
			printf("\n");
		else
			printf("(nothing)\n");
	};
	showListAsc();

	//��ԑ傫���m�[�h����~���ɑS�m�[�h�����X�g�A�b�v
	auto showListDesc = [&con]()
	{
		printf("--- get largest node -> get previous node ---\n");
		bool is_found = false;
		std::for_each(con.rbegin(), con.rend(),
			[&is_found](const data_t& obj)
			{
				if (!is_found)
					is_found = true;
				printf("[%d] ", obj.getKey());
			}
		);
		//���C�e���[�^�̕ϐ��錾�ƒl�̍X�V�𕪂������������I
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

	//�w��̃L�[�̃m�[�h���������A�����L�[�̃m�[�h�����X�g�A�b�v
	auto searchData = [&con]()
	{
		printf("--- search node ---\n");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			rbtree::stack_t<data_t> stack;
			bool is_found = false;
			std::for_each(con.find(search_key), con.equal_range(search_key),
				[&is_found, &search_key](const data_t& obj)
				{
					if (!is_found)
					{
						printf("%d=", search_key);
						is_found = true;
					}
					printf("[%d] ", obj.getKey());
				}
			);
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂������������I
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

	//�w��̃L�[�Ɠ��������ւň�ԋ߂��m�[�h������
	auto searchNearestData = [&con](const rbtree::MATCH_TYPE_T search_type)
	{
		printf("--- search nearest node for %s ---\n", search_type == rbtree::FOR_NEAREST_SMALLER ? "smaller" : search_type == rbtree::FOR_NEAREST_LARGER ? "larger" : "same");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			rbtree::stack_t<data_t> stack;
			bool is_found = false;
			const_iterator ite(con.find(search_key, search_type));
			const_iterator end(con.end());
			for (int i = 0; ite != end && *ite != search_key && i < 4; ++i, ++ite)
			{
				if (!is_found)
				{
					printf("%d=", search_key);
					is_found = true;
				}
				printf("[%d] ", ite->getKey());
			}
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂��������኱�����I
			//const_iterator ite;con._find(ite, search_key, search_type);
			//const_iterator end;con._end(end);
			//...
			if (is_found)
				printf("\n");
		}
	};
	searchNearestData(rbtree::FOR_NEAREST_SMALLER);

	//�w��̃L�[�Ɠ�����������傫���ŋ߃m�[�h������
	searchNearestData(rbtree::FOR_NEAREST_LARGER);

	//�m�[�h���폜
	auto removeNodes = [&con]()
	{
		printf("--- remove nodes ---\n");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			const_iterator ite(con.find(search_key));
			const bool result = con.erase(*ite);
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂��������኱�����I
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (result)
				printf("[%d] ", search_key);
		}
		printf("\n");
	};
	removeNodes();

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();

	//�m�[�h���폜
	auto removeAllNodes = [&con]()
	{
		printf("--- remove all nodes ---\n");
		for (int search_key = key_min; search_key <= key_max;)
		{
			const_iterator ite(con.find(search_key));
			const bool result = con.erase(*ite);
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂��������኱�����I
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (result)
				printf("[%d] ", search_key);
			else
				++search_key;
		}
		printf("\n");
	};
	removeAllNodes();

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();

	return EXIT_SUCCESS;
}

// End of file
