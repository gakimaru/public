#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t�p
#include <memory.h>//memcpy�p
#include <assert.h>//assert�p
#include <iterator>//std::iterator�p
#include <algorithm>//algorithm�p

//#define DISABLE_ROTATE_FOR_ADD//�m�[�h�ǉ����̉�]�����𖳌�������ꍇ�́A���̃}�N����L��������
#define DISABLE_ROTATE_FOR_REMOVE//�m�[�h�폜���̉�]�����𖳌�������ꍇ�́A���̃}�N����L��������

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
//�y��̓I�Ȋ��p�̑z��F�������Ǘ��ł̊��p�z
//�E�������}�l�[�W���̊Ǘ����̘A���Ɏg�p���邱�Ƃ�z��B
//�E�󂫃������T�C�Y���̘A�����s�����߁A�L�[�d�������e����K�v������B
//�E�܂��A�A�����X�g����剻���邱�Ƃ�����邽�߁A�e�m�[�h�ւ̃����N����
//�@�����Ȃ��B
//�E�K�v�ʈȏ�̋󂫃������̃m�[�h�����������̂��A�A���C�������g����������
//�@��ŗ��p�\�ȃm�[�h�����m�F���A����傫�ȃm�[�h��H���čœK��
//�@�m�[�h��T���o���B
//�E�m�[�h�Ԃ̃����N���́A64bit�|�C���^�ϐ��ɂ���剻���N����Ȃ��悤�ɁA
//�@��������Ԃ̐擪����I�t�Z�b�g���ꂽ32bit�̑��΃|�C���^�������B
//�E��̃������Ǘ������A2��ނ̃c���[�ɐU�蕪���Ďg�p����B
//�@�폜�ς݃������m�[�h�̃c���[�̓T�C�Y���L�[�ɂ��A
//�@�g�p���������m�[�h�̃c���[�̓|�C���^���L�[�ɂ���B
//�@���̂悤�ȗ��p���\�Ƃ��邽�߂ɁA�f�[�^�\���ƃA���S���Y�������S��
//�@�؂藣�����\���ɂ���B
namespace rbtree
{
	//--------------------
	//�ԍ��؂̃f�[�^�\���ƃA���S���Y��
	//�y�����z
	//�E�񕪖؂ł���B
	//	- �m�[�h�̍����ɂ́A�L�[�̒l�����m�[�h��菬�����m�[�h��A���B
	//	- �m�[�h�̉E���ɂ́A�L�[�̒l�����m�[�h���傫���m�[�h��A���B
	//�E���t�؂ł���B
	//	- ��ɍ��E�̖؂̃o�����X��ۂ��A�T�����Ԃ̑傫�ȗ򉻂��Ȃ��؍\���B
	//�y�����z
	//�E�����@�F�e�m�[�h�́u�ԁv���u���v�́u�F�v�����B
	//�E�����A�F�u���v�iroot�j�͕K���u���v�B
	//�E�����B�F�u�ԁv�̎q�͕K���u���v�B
	//	        - �ҋ��ɂ��A�u�ԁv�̐e�͕K���u���v�B
	//	        - �u���v�̎q�́u�ԁv�ł��u���v�ł��ǂ��B
	//�E�����C�F���ׂẮu���v����u�t�v�܂ł̌o�H��ɂ���u���v�̐��́A������o�H�ň��B
	//--------------------
	//�ԍ��؃m�[�h����\���̃e���v���[�g
	//��CRTP�����p���A���L�̂悤�Ȕh���\���́^�N���X���쐬���Ďg�p����
	//  //template<class IMPL_OPE_TYPE, typename NODE_TYPE, typename KEY_TYPE, int STACK_DEPTH_MAX = 32>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public rbtree::base_ope_t<�h���\����, �m�[�h�^, �L�[�^, �X�^�b�N�̍ő�̐[�� = 32>
	//	struct ope_t : public rbtree::ope_t<ope_t, data_t, int>
	//	{
	//		//�q�m�[�h���擾
	//		inline static const node_type* getNodeS(const node_type& node){ return ???; }//���i���j��
	//		inline static const node_type* getNodeL(const node_type& node){ return ???; }//��i�E�j��
	//		//�q�m�[�h��ύX
	//		inline static void setNodeS(node_type& node, const node_type* node_s){ ??? = node; }//���i���j��
	//		inline static void setNodeL(node_type& node, const node_type* node_l){ ??? = node; }//��i�E�j��
	//		
	//		//�m�[�h�̐F���擾
	//		inline static color_t getColor(const node_type& node){ return ??? ? BLACK : RED; }
	//		//�m�[�h�̐F��ύX
	//		inline static void setColor(node_type& node, const color_t color){ ??? = color == BLACK; }
	//		
	//		//�L�[���擾
	//		inline static key_type getKey(const node_type& node){ return ???; }
	//		
	//		//�L�[���r
	//		inline static int compare_key(const key_type lhs, const key_type rhs)
	//		{
	//			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
	//		}
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, typename KEY_TYPE, int _STACK_DEPTH_MAX = 32>
	struct base_ope_t
	{
		//�萔
		static const int STACK_DEPTH_MAX = _STACK_DEPTH_MAX;//�X�^�b�N�̍ő�̐[��
		enum color_t//�J���[
		{
			RED = 0,//��
			BLACK = 1,//��
		};

		//�^
		typedef OPE_TYPE ope_type;//�m�[�h����^
		typedef NODE_TYPE node_type;//�m�[�h�^
		typedef KEY_TYPE key_type;//�L�[�^

		//�m�[�h�ƃL�[���r
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

		//�J���[����
		inline static bool isBlack(const node_type& node){ return ope_type::getColor(node) == BLACK; }
		inline static bool isRed(const node_type& node){ return ope_type::getColor(node) == RED; }
		//�J���[�X�V
		inline static void setIsBlack(node_type& node){ ope_type::setColor(node, BLACK); }
		inline static void setIsRed(node_type& node){ ope_type::setColor(node, RED); }
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef typename ope_type::key_type key_type; \
		typedef stack_t<ope_type> stack_type; \
		typedef typename stack_type::info_t stack_info_type;
	//--------------------
	//�ԍ��ؑ��쏈���p�X�^�b�N�N���X
	//���ԍ��؂̃m�[�h��������
	template<class OPE_TYPE>
	class stack_t
	{
	public:
		//��{�^
		typedef OPE_TYPE ope_type;
		typedef typename OPE_TYPE::node_type node_type;
	public:
		//�萔
		static const int DEPTH_MAX = ope_type::STACK_DEPTH_MAX;//�ő�̐[���i�X�^�b�N�����p�j
	public:
		//�^
		//�m�[�h���^
		struct info_t
		{
			const node_type* m_nodeRef;//�m�[�h�Q��
			bool m_isLarge;//��i�E�j���ɘA�����H
		};
	public:
		//�X�^�b�N�Ƀm�[�h�����L�^
		info_t* push(const node_type* node, const bool is_large)
		{
			assert(m_depth < DEPTH_MAX);
			info_t* stack_node = &m_array[m_depth++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
			return stack_node;
		}
		//�X�^�b�N����m�[�h�����擾
		info_t* pop()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[--m_depth];
		}
		//�X�^�b�N�̐擪�̃m�[�h�����Q��
		//���v�f������Ȃ�
		info_t* top()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[m_depth - 1];
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
			if (m_depth > 0)
				memcpy(m_array, rhs.m_array, sizeof(info_t)* m_depth);
			return *this;
		}
		//�R�s�[�R���X�g���N�^
		stack_t(const stack_t& obj) :
			m_depth(obj.m_depth)
		{
			if (m_depth > 0)
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
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getSmallestNode(const typename OPE_TYPE::node_type* root, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* curr_node = root;//���݂̒T���m�[�h
		while (true)
		{
			const node_type* child_node = ope_type::getNodeS(*curr_node);//���i���j���̎q�m�[�h���擾
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
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getLargestNode(const typename OPE_TYPE::node_type* root, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* curr_node = root;//���݂̒T���m�[�h
		while (true)
		{
			const node_type* child_node = ope_type::getNodeL(*curr_node);//��i�E�j���̎q�m�[�h���擾
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
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getNextNode(const typename OPE_TYPE::node_type* curr_node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!curr_node)
			return nullptr;
		const node_type* node_l = ope_type::getNodeL(*curr_node);//��i�E�j���̎q�m�[�h���擾
		if (node_l)//�q������ꍇ
		{
			stack.push(curr_node, true);//�e�m�[�h���X�^�b�N�ɋL�^
			return getSmallestNode<ope_type>(node_l, stack);//�q�����ԏ������q���m�[�h���擾
		}
		else//if(!node_l)//�q���Ȃ��ꍇ
		{
			const stack_info_type* stack_node = nullptr;
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
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* getPrevNode(const typename OPE_TYPE::node_type* curr_node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!curr_node)
			return nullptr;
		const node_type* node_s = ope_type::getNodeS(*curr_node);//���i���j���̎q�m�[�h���擾
		if (node_s)//�q������ꍇ
		{
			stack.push(curr_node, false);//�e�m�[�h���X�^�b�N�ɋL�^
			return getLargestNode<ope_type>(node_s, stack);//�q�����ԑ傫���q���m�[�h���擾
		}
		else//if(!node_s)//�q���Ȃ��ꍇ
		{
			const stack_info_type* stack_node = nullptr;
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
	template<class OPE_TYPE>
	int getDepthMax(const typename OPE_TYPE::node_type* root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return -1;
		int depth_max = 0;//�ő�̐[��
		stack_type stack;//�X�^�b�N���쐬
		const node_type* node = getSmallestNode<ope_type>(root, stack);//�ŏ��m�[�h�擾
		while (node)
		{
			const int depth = stack.getDepth();//�[�����擾
			depth_max = depth_max >= depth ? depth_max : depth;//�ő�̐[�����X�V
			node = getNextNode<ope_type>(node, stack);//���̃m�[�h�擾
		}
		return depth_max;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�w��̃L�[�ƈ�v����m�[�h�A�������́A�w��̃L�[�ɍł��߂��m�[�h������
	//���ォ��get**Node()��searchNode()�����s�ł���悤�ɁA�X�^�b�N��n���K�v����
	//����v�m�[�h����������ꍇ�A���̍ŏ��̃m�[�h��Ԃ�
	//���w��̃L�[�̓��ւōł��߂��m�[�h�Ɠ��L�[�̃m�[�h����������ꍇ�A���̍Ō�̃m�[�h��Ԃ�
	//���w��̃L�[���傫���ł��߂��m�[�h�Ɠ��L�[�̃m�[�h����������ꍇ�A���̍ŏ��̃m�[�h��Ԃ�
	enum match_type_t
	{
		FOR_MATCH = 0,//��v�m�[�h������
		FOR_NEAREST_SMALLER,//��v�m�[�h�A�������́A���ւōł��߂��m�[�h������
		FOR_NEAREST_LARGER,//��v�m�[�h�A�������́A������傫���ł��߂��m�[�h������
	};
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* searchNode(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::key_type key, stack_t<OPE_TYPE>& stack, const match_type_t search_type = FOR_MATCH)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!root)
			return nullptr;
		const node_type* match_node = nullptr;//��v�m�[�h
		int match_stack_depth = -1;//��v�m�[�h���o���̃X�^�b�N�ʒu
		const node_type* nearest_node = nullptr;//�ŋ߃m�[�h
		int nearest_stack_depth = -1;//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu
		const node_type* curr_node = root;//���݂̒T���m�[�h
		while (true)
		{
			const int cmp = ope_type::compare(*curr_node, key);//�w��̃L�[�Ƒ召��r
			if (cmp == 0)//�w��̃L�[�ƈ�v
			{
				//���L�[�d�������e����A���S���Y���̂��߁A
				//�@��v�m�[�h���L�^������Ō����𑱍s����
				match_node = curr_node;//��v�m�[�h���L�^
				match_stack_depth = stack.getDepth();//��v�m�[�h���o���̃X�^�b�N�ʒu���L�^
				stack.push(curr_node, false);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = ope_type::getNodeS(*curr_node);//���i���j���̎q�̕��Ɍ����𑱍s
				if (!curr_node)//�q��������ΏI��
					break;
			}
			else if (cmp < 0)//�w��̃L�[��菬����
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && ope_type::le(*nearest_node, *curr_node)))
				{
					nearest_node = curr_node;//�ŋ߃m�[�h���L�^
					nearest_stack_depth = stack.getDepth();//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu���L�^
				}
				const node_type* child_node = ope_type::getNodeL(*curr_node);//��i�E�j���̎q�m�[�h���擾
				if (!child_node)//�q��������ΏI��
					break;
				stack.push(curr_node, true);//���̐e�m�[�h�Ƃ��ăX�^�b�N�ɋL�^
				curr_node = child_node;
			}
			else//if (cmp > 0)//�w��̃L�[���傫��
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && ope_type::ge(*nearest_node, *curr_node)))
				{
					nearest_node = curr_node;//�ŋ߃m�[�h���L�^
					nearest_stack_depth = stack.getDepth();//�ŋ߃m�[�h���o���̃X�^�b�N�ʒu���L�^
				}
				const node_type* child_node = ope_type::getNodeS(*curr_node);//���i���j���̎q�m�[�h���擾
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
	template<class OPE_TYPE>
	const typename OPE_TYPE::node_type* searchNode(const typename OPE_TYPE::node_type* root, const typename OPE_TYPE::node_type* node, stack_t<OPE_TYPE>& stack)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		const key_type key = ope_type::getKey(*node);//�L�[���擾
		node_type* target_node = const_cast<node_type*>(searchNode<ope_type>(root, key, stack));//�L�[����v����m�[�h������
		if (!target_node)//�L�[����v����m�[�h���Ȃ���ΏI��
			return nullptr;
		while (target_node != node && ope_type::eq(*target_node, key))//�w��m�[�h�i�Ɠ����A�h���X�j������
			target_node = const_cast<node_type*>(getNextNode<ope_type>(target_node, stack));
		if (target_node != node)
			return nullptr;
		return target_node;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�c���[�̃m�[�h�����v��
	template<class OPE_TYPE>
	std::size_t countNodes(const typename OPE_TYPE::node_type* node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		return !node ? 0 :
			1 + countNodes<ope_type>(ope_type::getNodeS(*node)) +
			countNodes<ope_type>(ope_type::getNodeL(*node));
	}
	//--------------------
	//�ԍ��ؑ���֐��F�w��̃L�[�̃m�[�h�����v��
	//���֐����ŃX�^�b�N���g�p
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
		int count = 0;//�m�[�h��
		while (node && ope_type::eq(*node, key))
		{
			++count;
			node = getNextNode<ope_type>(node, stack);
		}
		return count;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�y�ėp�����z�m�[�h����]����
	//         .--------[node]---------.   
	//      [node_s]             .--[node_l]
	//                        [node_ls]     
	//
	//                    ���y����]�z
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
	//�ԍ��ؑ���֐��F�y�ėp�����z�m�[�h�E��]����
	//    .---------[node]-------.   
	// [node_s]--.           [node_l]
	//       [node_sl]              
	//
	//                ���y�E��]�z
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
	//�ԍ��ؑ���֐��F�k���Đԍ��o�����X����
	//���m�[�h�ǉ����p
	template<class OPE_TYPE>
	void balanceForAdd(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* curr_node, bool child_is_large, typename OPE_TYPE::node_type* child_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (curr_node && child_node)
		{
			bool is_rotated = false;//��]�����ς݃t���O
			while (true)
			{
				stack_info_type* parent_info = stack.pop();//�X�^�b�N����e�m�[�h���擾
				if (!parent_info)
					break;
				node_type* parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//�e�m�[�h�擾
				bool curr_is_large = parent_info->m_isLarge;//�e�m�[�h����̑召�A�����擾
				if (is_rotated)//�O���]�����ς݂Ȃ�e�m�[�h�̎q�m�[�h��A��������
				{
					if (curr_is_large)
						ope_type::setNodeL(*parent_node, curr_node);
					else
						ope_type::setNodeS(*parent_node, curr_node);
					is_rotated = false;//��]�����ςݏ�ԃ��Z�b�g
				}
				if (ope_type::isRed(*curr_node) && ope_type::isRed(*child_node))//�ԃm�[�h����A�����Ă������]����
				{
					//�y���ʏ����z�e�m�[�h�����ɂ�������]����
					//             .-------[parent_node:B]--------.                
					//           [(S)]                    .--[curr_node:R]--.      
					//                                  [(LS)]       [child_node:R]
					// 
					//                          ���y����]�z
					//
					//          .-----------[curr_node:R]---------.        
					//   .--[parent_node:B]--.               [child_node:R]
					// [(S)]              [(LS)]                           
					// 
					//                          ���y�ϐ��ƐF�𒲐��z
					//                                                 ����
					//            .--------[parent_node:R]--------.     �� 
					//   .------[(S):B]------.                [curr_node:B]
					// [(SS)]             [(SL)]                           
					auto rotateParentL = [&]() -> const node_type*
					{
					parent_node = rotateL<ope_type>(parent_node);//����]����
					curr_is_large = true;
					curr_node = child_node;
					ope_type::setIsBlack(*curr_node);//�m�[�h�����ɂ���
					//child_is_large = true;
					//child_node = nullptr;
					return parent_node;
				};
					//�y���ʏ����z�e�m�[�h�����ɂ����E��]����
					//               .-----[parent_node:B]-----.  
					//       .--[curr_node:R]--.             [(L)]
					// [child_node:R]       [(SL)]                
					//
					//                            ���y�E��]�z
					//
					//               .-------[curr_node:R]-------.            
					//          [child_node:R]         .--[parent_node:B]--.  
					//                               [(SL)]              [(L)]
					//
					//                            ���y�ϐ��ƐF�𒲐��z
					//
					//               .-------[parent_node:R]-----.            
					//           [curr_node:B]         .------[(L):B]------.  
					//                     ��        [(LS)]             [(LL)]
					//                    ����
					auto rotateParentR = [&]() -> const node_type*
					{
						parent_node = rotateR<ope_type>(parent_node);//�E��]����
						curr_is_large = false;
						curr_node = child_node;
						ope_type::setIsBlack(*curr_node);//�m�[�h�����ɂ���
						//child_is_large = false;
						//child_node = nullptr;
						return parent_node;
					};
					//�y���ʏ����z���݂̃m�[�h�����ɂ�������]����
					//           .-------[curr_node:R]-------.        
					//         [(S)]                .--[child_node:R]
					//                            [(LS)]              
					// 
					//                          ���y����]�z
					//
					//           .-------[child_node:R]
					//   .--[curr_node:R]--.           
					// [(S)]            [(LS)]         
					// 
					//                          ���y�ϐ��𒲐��z���F�̒����͂��Ȃ�
					//
					//           .--------[curr_node:R]
					//   .--[child_node:R]--.          
					// [(SS)]            [(SL)]        
					auto rotateCurrL = [&]() -> const node_type*
					{
						node_type* curr_node_old = curr_node;
						curr_node = rotateL<ope_type>(curr_node);//����]����
						child_is_large = false;
						child_node = curr_node_old;
						return curr_node;
					};
					//�y���ʏ����z���݂̃m�[�h�����ɂ����E��]����
					//       .--------[curr_node:R]--------.   
					// [child_node:R]--.                 [(L)] 
					//              [(SS)]               
					// 
					//                     ���y�E��]�z
					//
					//               [child_node:R]-------.           
					//                           .--[curr_node:R]--.  
					//                         [(SS)]            [(L)]
					// 
					//                     ���y�ϐ��𒲐��z���F�̒����͂��Ȃ�
					//
					//                [curr_node:R]-------.           
					//                          .--[child_node:R]--.  
					//                        [(LS)]            [(LL)]
					auto rotateCurrR = [&]() -> const node_type*
					{
						node_type* curr_node_old = curr_node;
						curr_node = rotateR<ope_type>(curr_node);//��]����
						child_is_large = true;
						child_node = curr_node_old;
						return curr_node;
					};
					//�e��Ԃɍ��킹����]����
					if (!curr_is_large && !child_is_large)
					{
						//�y���i���j�F�ԁz���y���i���j�F�ԁz
						//               .-----[parent_node:B]-----.  
						//       .--[curr_node:R]--.             [(L)]
						// [child_node:R]       [(SL)]                
						//
						//                            ���y�e�m�[�h���E��]�z
						//
						//               .-------[curr_node:R]-------.            
						//          [child_node:R]         .--[parent_node:B]--.  
						//                               [(SL)]              [(L)]
						//
						//                            ���y�ϐ��ƐF�𒲐��z
						//
						//               .-------[parent_node:R]-----.            
						//           [curr_node:B]         .------[(L):B]------.  
						//                     ��        [(LS)]             [(LL)]
						//                    ����
						rotateParentR();
					}
					else if (!curr_is_large &&  child_is_large)
					{
						//�y���i���j�F�ԁz���y��i�E�j�F�ԁz
						//                       .-----------------[parent_node:B]-------.  
						//               .--[curr_node:R]--.                           [(L)]
						//             [(SS)]        .--[child_node:R]--.
						//                        [(SLS)]          [(SLL)]
						//
						//                                               ���y���݃m�[�h������]�z
						//
						//                        .----------------[parent_node:B]-------.  
						//           .------[child_node:R]------.                      [(L)]
						//   .--[curr_node:R]--.            [(SLL)]                
						// [(SS)]          [(SLS)]
						//
						//                                               ���y�e�m�[�h���E��]�z
						//
						//                        .-----------------[child_node:R]-------.            
						//                .--[curr_node:R]--.               .--[parent_node:B]--.  
						//              [(SS)]           [(SLS)]          [(SLL)]             [(L)]
						//
						//                                               ���y�ϐ��ƐF�𒲐��z
						//
						//                        .-----------------[parent_node:R]-----.            
						//                .--[curr_node:B]--.                   .-----[(L):B]---.  
						//               [(SS)])        ��[(SL)]              [(LS)]         [(LL)]
						//                             ����
						ope_type::setNodeS(*parent_node, rotateCurrL());
						rotateParentR();
					}
					else if (curr_is_large && !child_is_large)
					{
						//�y��i�E�j�F�ԁz���y���i���j�F�ԁz
						//             .-------[parent_node:B]----------------.                  
						//           [(S)]                       .-------[curr_node:R]-------.   
						//                               .--[child_node:R]--.              [(LL)]
						//                             [(LSS)]          [(LSL)]               
						// 
						//                          ���y���݃m�[�h���E��]�z
						//
						//             .-------[parent_node:B]-----------------.                           
						//           [(S)]                       .-------[child_node:R]-------.            
						//                                     [(LSS)]                .--[curr_node:R]--.  
						//                                                          [(LSL)]          [(LL)]
						// 
						//                          ���y�e�m�[�h������]�z
						//
						//           .----------[child_node:R]---------.            
						//   .--[parent_node:B]--.             .--[curr_node:R]--.  
						// [(S)]             [(LSS)]         [(LSL)]          [(LL)]
						// 
						//                          ���y�ϐ��ƐF�𒲐��z
						//                                                  ����
						//            .--------[parent_node:R]--------.      ��      
						//   .------[(S):B]------.              .--[curr_node:B]--.  
						// [(SS)]             [(SL)]          [(LSL)]          [(LL)]
						ope_type::setNodeL(*parent_node, rotateCurrR());
						rotateParentL();
					}
					else//if (!curr_is_large && !child_is_large)
					{
						//�y��i�E�j�F�ԁz���y��i�E�j�F�ԁz
						//             .-------[parent_node:B]--------.                
						//           [(S)]                    .--[curr_node:R]--.      
						//                                  [(LS)]       [child_node:R]
						// 
						//                          ���y�e�m�[�h������]�z
						//
						//          .-----------[curr_node:R]---------.        
						//   .--[parent_node:B]--.               [child_node:R]
						// [(S)]              [(LS)]                           
						// 
						//                          ���y�ϐ��ƐF�𒲐��z
						//                                                 ����
						//            .--------[parent_node:R]--------.     �� 
						//   .------[(S):B]------.                [curr_node:B]
						// [(SS)]             [(SL)]                           
						rotateParentL();
					}
					is_rotated = true;
				}
				//�e�m�[�h�ɏ������ڂ�
				child_is_large = curr_is_large;
				child_node = curr_node;
				curr_node = parent_node;
			}
			if (curr_node)
			{
				root = curr_node;//���m�[�h���X�V
				ope_type::setIsBlack(*root);//���m�[�h�͍�
			}
		}
	}
	//--------------------
	//�ԍ��ؑ���֐��F�k���Đԍ��o�����X����
	//���m�[�h�폜���p
	template<class OPE_TYPE>
	void balanceForRemove(typename OPE_TYPE::node_type*& root, stack_t<OPE_TYPE>& stack, typename OPE_TYPE::node_type* remove_node, typename OPE_TYPE::node_type* replace_node)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		bool is_necessary_rotate = false;//��]�K�v�H
		bool remove_node_is_black = ope_type::isBlack(*remove_node);
		bool replace_node_is_black = replace_node ? ope_type::isBlack(*replace_node) : false;
		//��]����K�v����
		if (!remove_node_is_black)//�폜�m�[�h���Ԃ̏ꍇ
		{
			if (!replace_node)//�u�������m�[�h���Ȃ��ꍇ
			{
				//is_necessary_rotate = false;//��]�s�v
				printf("([R]��[n]:OK )");
			}
			else//if(replace_node)//�u�������m�[�h������ꍇ
			{
				if (!replace_node_is_black)//�u�������m�[�h���Ԃ̏ꍇ
				{
					//is_necessary_rotate = false;//��]�s�v
					printf("([R]��[R]:OK )");
				}
				else//if (replace_node_is_black)//�u�������m�[�h�����̏ꍇ
				{
					is_necessary_rotate = true;//��]�K�v
					printf("([R]��[B]:ROT)");
					ope_type::setIsRed(*replace_node);//�u�������m�[�h��Ԃɂ���
					//remove_node_is_black = true;//�폜�m�[�h�͍�
					//                            //���u���������̃m�[�h���폜���ꂽ���̂Ƃ��ď�������
				}
			}
		}
		else//if (remove_node_is_black)//�폜�m�[�h�����̏ꍇ
		{
			if (!replace_node)//�u�������m�[�h���Ȃ��ꍇ
			{
				is_necessary_rotate = true;//��]�K�v
				printf("([B]��[n]:ROT)");
			}
			else//if(replace_node)//�u�������m�[�h������ꍇ
			{
				if (!replace_node_is_black)//�u�������m�[�h���Ԃ̏ꍇ
				{
					//is_necessary_rotate = false;//��]�s�v
					printf("([B]��[R]:OK )");
					ope_type::setIsBlack(*replace_node);//�u�������m�[�h�����ɂ���
					//remove_node_is_black = false;//�폜�m�[�h�͐�
					//                             //���u���������̃m�[�h���폜���ꂽ���̂Ƃ��ď�������
				}
				else//if (replace_node_is_black)//�u�������m�[�h�����̏ꍇ
				{
					is_necessary_rotate = true;//��]�K�v
					printf("([B]��[B]:ROT)");
				}
			}
		}
		//��]����
		//�����m�[�h���폜���ꂽ���̂݉�]���s��
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
					node_type* curr_node = parent_node ?//���݂̃m�[�h�擾 �����̑��ō��m�[�h����������Ă���
						curr_is_large ?
							const_cast<node_type*>(ope_type::getNodeL(*parent_node)) :
							const_cast<node_type*>(ope_type::getNodeS(*parent_node)) :
						nullptr;
					node_type* sibling_node = parent_node ?//�Z��m�[�h�擾
						curr_is_large ?
							const_cast<node_type*>(ope_type::getNodeS(*parent_node)) :
							const_cast<node_type*>(ope_type::getNodeL(*parent_node)) :
						nullptr;
					node_type* sibling_node_s = sibling_node ?//�Z��m�[�h�̏��i���j���̎q�m�[�h�擾
						const_cast<node_type*>(ope_type::getNodeS(*sibling_node)) :
						nullptr;
					node_type* sibling_node_l = sibling_node ?//�Z��m�[�h�̑�i�E�j���̎q�m�[�h�擾
						const_cast<node_type*>(ope_type::getNodeL(*sibling_node)) :
						nullptr;
					if (sibling_node)
					{
						if (!curr_is_large)//�폜�m�[�h�F�y���i���j:���z
						{
							if (ope_type::isBlack(*sibling_node))//�Z��m�[�h�F�y��i�E�j�F���z
							{
								if (sibling_node_s && ope_type::isRed(*sibling_node_s))//���y���i���j�F�ԁz
								{
									is_necessary_rotate = false;//��������
									printf("(ROT:SIB��L=B��S=R,OK)");
								}
								else if (sibling_node_l && ope_type::isRed(*sibling_node_l))//���y��i�E�j�F�ԁz
								{
									is_necessary_rotate = false;//��������
									printf("(ROT:SIB��L=B��L=R,OK)");
								}
								else//���y���i���j�F��or�Ȃ��z���y��i�E�j�F��or�Ȃ��z
								{
									if (ope_type::isRed(*parent_node))
									{
										is_necessary_rotate = false;//��������
										printf("(ROT:SIB��L=B��SL!=R,P=R,OK)");
									}
									else//if (ope_type::isBlack(*parent_node))
									{
										is_necessary_rotate = true;//�������s
										printf("(ROT:SIB��L:B��SL!=R,P=B,MORE)");
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//�Z��m�[�h�F�y��i�E�j�F�ԁz
							{
								//���K�R�I�ɐe�m�[�h�͍�
								is_necessary_rotate = true;//�������s
								printf("(ROT:SIB��L=R,MORE)");
							}
						}
						else//if (curr_is_large)//�폜�m�[�h�F�y��i�E�j:���z
						{
							if (ope_type::isBlack(*sibling_node))//�Z��m�[�h�F�y���i���j�F���z
							{
								if (sibling_node_s && ope_type::isRed(*sibling_node_s))//���y���i���j�F�ԁz
								{
									is_necessary_rotate = false;//��������
									printf("(ROT:SIB��S=B��S=R,OK)");
								}
								else if (sibling_node_l && ope_type::isRed(*sibling_node_l))//���y��i�E�j�F�ԁz
								{
									is_necessary_rotate = false;//��������
									printf("(ROT:SIB��S=B��L=R,OK)");
								}
								else//���y���i���j�F��or�Ȃ��z���y��i�E�j�F��or�Ȃ��z
								{
									if (ope_type::isRed(*parent_node))
									{
										is_necessary_rotate = false;//��������
										printf("(ROT:SIB��S=B��SL!=R,P=R,OK)");
									}
									else//if (ope_type::isBlack(*parent_node))
									{
										is_necessary_rotate = true;//�������s
										printf("(ROT:SIB��S=B��SL!=R,P=B,MORE)");
									}
								}
							}
							else//if (ope_type::isRed(*sibling_node))//�Z��m�[�h�F�y���i���j�F�ԁz
							{
								//���K�R�I�ɐe�m�[�h�͍�
								is_necessary_rotate = true;//�������s
								printf("(ROT:SIB��S=R,MORE)");
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
	//�ԍ��ؑ���֐��F�m�[�h��ǉ�
	//���֐����ŃX�^�b�N���g�p
	template<class OPE_TYPE>
	bool addNode(typename OPE_TYPE::node_type* new_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!new_node)
			return false;
		if (!root)//���m�[�h�����o�^�̏ꍇ
		{
			root = new_node;//���m�[�h�ɓo�^
			ope_type::setIsBlack(*root);//���m�[�h�͍�
			return true;
		}
		ope_type::setIsRed(*new_node);//�V�K�m�[�h�͎b��Ő�
		key_type new_key = ope_type::getKey(*new_node);//�V�K�m�[�h�̃L�[���擾
		stack_type stack;//�X�^�b�N��p��
		node_type* curr_node = root;//���݂̒T���m�[�h
		bool child_is_large = false;
		node_type* child_node = nullptr;
		while (true)
		{
			child_is_large = ope_type::le(*curr_node, new_key);//�w��̃L�[�ƈ�v�������͎w��̃L�[��菬�������true
			child_node = child_is_large ?
				const_cast<node_type*>(ope_type::getNodeL(*curr_node)) ://��i�E�j���̎q�m�[�h���擾
				const_cast<node_type*>(ope_type::getNodeS(*curr_node));//���i���j���̎q�m�[�h���擾
			if (!child_node)//�q��������΂����ɐV�K�m�[�h��ǉ����ďI��
			{
				child_node = new_node;
				if (child_is_large)
					ope_type::setNodeL(*curr_node, child_node);//��i�E�j���̎q�m�[�h�Ƃ��ĐV�K�m�[�h��ǉ�
				else
					ope_type::setNodeS(*curr_node, child_node);//���i���j���̎q�m�[�h�Ƃ��ĐV�K�m�[�h��ǉ�
				break;
			}
			stack.push(curr_node, child_is_large);//�e�m�[�h���X�^�b�N�ɋL�^
			curr_node = child_node;
		}
	#ifndef DISABLE_ROTATE_FOR_ADD
		//�ԍ��o�����X����
		balanceForAdd<ope_type>(root, stack, curr_node, child_is_large, child_node);
	#endif//DISABLE_ROTATE_FOR_ADD
		return true;
	}
	//--------------------
	//�ԍ��ؑ���֐��F�m�[�h���폜
	//���֐����ŃX�^�b�N���g�p
	template<class OPE_TYPE>
	bool removeNode(const typename OPE_TYPE::node_type* target_node, typename OPE_TYPE::node_type*& root)
	{
		DECLARE_OPE_TYPES(OPE_TYPE);
		if (!target_node || !root)
			return false;
		stack_type stack;//�X�^�b�N��p��
		node_type* remove_node = const_cast<node_type*>(searchNode<ope_type>(root, target_node, stack));//�폜�m�[�h���������ăX�^�b�N�����
		if (!remove_node)//�����Ɏ��s������I��
			return false;
		//�폜�J�n
		node_type* parent_node = nullptr;//�폜�m�[�h�̐e�m�[�h
		bool curr_is_large = false;//�폜�m�[�h�̐e�m�[�h����̘A������
		{
			stack_info_type* parent_info = stack.top();//�e�m�[�h�Q�Ə����擾
			if (parent_info)
			{
				parent_node = const_cast<node_type*>(parent_info->m_nodeRef);//�e�m�[�h���擾
				curr_is_large = parent_info->m_isLarge;//�e�m�[�h����̘A������
			}
		}
		node_type* node_s = const_cast<node_type*>(ope_type::getNodeS(*remove_node));//���i���j���̎q�m�[�h���擾
		node_type* node_l = const_cast<node_type*>(ope_type::getNodeL(*remove_node));//��i�E�j���̎q�m�[�h���擾
		node_type* node_sl = nullptr;//�폜�m�[�h�̍ő�q���m�[�h�i�폜�m�[�h�̎��ɏ������m�[�h�j
		node_type* replace_node =//�폜�m�[�h�ƒu��������m�[�h
			( node_s && !node_l) ? node_s ://���i���j���̎q�m�[�h
			(!node_s &&  node_l) ? node_l ://��i�E�j���̎q�m�[�h
			                       nullptr;//�m�[�h�폜 or �ő�q���m�[�h
		if (node_s && node_l)//�召�����̎q������ꍇ�A�ő�q���m�[�h����
		{
			stack_info_type* remove_info = stack.push(remove_node, false);//�X�^�b�N�ɍ폜�m�[�h��ǉ�
			node_sl = const_cast<node_type*>(getLargestNode<ope_type>(node_s, stack));//�ő�q���m�[�h���擾
			stack_info_type* parent_info_sl = stack.top();//�ő�q���m�[�h�̐e�m�[�h���擾
			node_type* parent_node_sl = const_cast<node_type*>(parent_info_sl->m_nodeRef);//�ő�q���m�[�h�̐e�m�[�h���擾
			ope_type::setNodeL(*parent_node_sl, ope_type::getNodeS(*node_sl));//�ő�q���m�[�h��e�m�[�h����؂藣��
			ope_type::setNodeL(*node_sl, node_l);//�ő�q���m�[�h�̑呤�̎q��ύX
			if (node_sl != node_s)
				ope_type::setNodeS(*node_sl, node_s);//�ő�q���m�[�h�̏����̎q��ύX
			replace_node = node_sl;//�폜�m�[�h�ƒu��������m�[�h���Z�b�g
			remove_info->m_nodeRef = node_sl;//�X�^�b�N�̏�����������
		}
		if (!parent_node)//�e�m�[�h���Ȃ��ꍇ �� ���m�[�h���폜
		{
			root = replace_node;//���m�[�h��u������
			if (!root)//���m�[�h�Ȃ���΁A���̎��_�ŏI��
				return true;
		}
		else//if(parent_node)//�e�m�[�h������ꍇ
		{
			if (curr_is_large)
				ope_type::setNodeL(*parent_node, replace_node);//�e�m�[�h�̑�i�E�j���̎q�m�[�h��u������
			else//if (!curr_is_large)
				ope_type::setNodeS(*parent_node, replace_node);//�e�m�[�h�̏��i���j���̎q�m�[�h��u������
		}
	#ifndef DISABLE_ROTATE_FOR_REMOVE
		//�ԍ��o�����X����
		balanceForRemove<ope_type>(root, stack, remove_node, replace_node);
	#endif//DISABLE_ROTATE_FOR_REMOVE
		return true;
	}
	//--------------------
	//�ԍ��؃R���e�i
	//�����m�[�h�����̂�
	//��std::map��͂����\��
	template<class OPE_TYPE>
	class container
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//--------------------
		//�C�e���[�^
		class iterator;
		typedef const iterator const_iterator;
		class iterator : public std::iterator<std::bidirectional_iterator_tag, node_type>
		{
			friend class container;
		public:
			//�L���X�g�I�y���[�^
			operator const node_type() const { return *m_node; }
			operator node_type&(){ return *m_node; }
			operator key_type() const { return ope_type::getKey(*m_node); }
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
			//���Z�I�y���[�^
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
		//�@std::reverse_iterator<iterator>���g�킸�Ɏ����i�U���j����B
		//�@���g��operator��+��-���t�]���Ă��邾���ŁA�ʏ�̃C�e���[�^�Ɠ����B
		class reverse_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		class reverse_iterator : public iterator
		{
		public:
			//���Z�I�y���[�^
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
		//���\�b�h�F���o�[�X�C�e���[�^�n
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
		//���\�b�h�F�e�ʌn
		bool empty() const { return m_root == nullptr; }
		std::size_t size() const { return countNodes<ope_type>(m_root); }
		//std::size_t max_size() const { return countNodes<ope_type>(m_root); }
		int depth_max() const { return getDepthMax<ope_type>(m_root); }
		//���\�b�h�F�v�f�A�N�Z�X�n
		//��std::map�ƈقȂ�A�m�[�h�̃|�C���^��Ԃ�
		inline const node_type* _at(const key_type key) const
		{
			stack_type stack;
			return searchNode<ope_type>(m_root, key, stack, FOR_MATCH);
		}
		const node_type* at(const key_type key) const { return _at(key); }
		node_type* at(const key_type key){ return const_cast<node_type*>(_at(key)); }
		const node_type* operator[](const key_type key) const { return _at(key); }
		node_type* operator[](const key_type key){ return const_cast<node_type*>(_at(key)); }
		//���\�b�h�F�ǉ��^�폜�n
		//��std::map�ƈقȂ�A�m�[�h�𒼐ڎw�肵�A���ʂ�bool�^�Ŏ󂯎��
		//���v�f�̃������m�ہ^�폜���s��Ȃ��_�ɒ���
		bool insert(const node_type& node){ return addNode<ope_type>(const_cast<node_type*>(&node), m_root); }
		bool erase(const node_type& node){ return removeNode<ope_type>(&node, m_root); }
		bool erase(const key_type key){ return removeNode<ope_type>(at(key), m_root); }
		void clear(){ m_root = nullptr; }
		//���\�b�h�F�����n
		//��lower_bound(), upper_bound()�ɂ͔�Ή�
		//������ɁAfind_nearest�ɑΉ�
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
		//���̑�
		const node_type* root() const { return m_root; }//���m�[�h���擾
		node_type*& root_ref(){ return m_root; }//���m�[�h�̎Q�Ƃ��擾
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
		node_type* m_root;//���m�[�h
	};
}//namespace rbtree

//--------------------------------------------------------------------------------
//�ԍ��؃e�X�g

#include <algorithm>//std::max�p
#include <random>//C++11 std::random�p

//----------------------------------------
//�e�X�g�f�[�^
struct data_t
{
	//�R���X�g���N�^
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

	//�t�B�[���h
	const data_t* m_nodeS;//���i���j���̃m�[�h
	const data_t* m_nodeL;//��i�E�j���̃m�[�h
	bool m_isBlack;//�m�[�h�̐F
	int m_key;//�L�[
};
//----------------------------------------
//�e�X�g�f�[�^����N���X
struct ope_t : public rbtree::base_ope_t<ope_t, data_t, int>
{
	//�q�m�[�h���擾
	inline static const node_type* getNodeS(const node_type& node){ return node.m_nodeS; }//���i���j��
	inline static const node_type* getNodeL(const node_type& node){ return node.m_nodeL; }//��i�E�j��
	//�q�m�[�h��ύX
	inline static void setNodeS(node_type& node, const data_t* node_s){ node.m_nodeS = node_s; }//���i���j��
	inline static void setNodeL(node_type& node, const data_t* node_l){ node.m_nodeL = node_l; }//��i�E�j��
		
	//�m�[�h�̐F���擾
	inline static color_t getColor(const node_type& node){ return node.m_isBlack ? BLACK : RED; }
	//�m�[�h�̐F��ύX
	inline static void setColor(node_type& node, const color_t color){ node.m_isBlack = color == BLACK; }
	
	//�L�[���擾
	inline static key_type getKey(const node_type& node){ return node.m_key; }

	//�L�[���r
	inline static int compare_key(const key_type lhs, const key_type rhs)
	{
		return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
	}
};

//----------------------------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	static const int key_min = 0;//�ŏ��L�[
	static const int key_max = 99;//�ő�L�[
	static const int reg_num = 100;//�o�^��

	//�ԍ��؃R���e�i
	typedef rbtree::container<ope_t> container_t;
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
			printf("[%2d] ", new_node->m_key);
			con.insert(*new_node);
		}
		printf("\n");
	};
	regList();

	//�c���[��\��
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

	//�e�}�܂ł̃m�[�h����\��
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

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	auto showListAsc = [&con]()
	{
		printf("--- get smallest node -> get next node (count=%d) ---\n", con.size());
		bool is_found = false;
		for (const data_t& obj : con)//C++11�`���͈̔͂Ɋ�Â�for���[�v
		{
			if (!is_found)
				is_found = true;
			printf("[%2d] ", obj.m_key);
		}
		//���C�e���[�^�̕ϐ��錾�ƒl�̍X�V�𕪂��������኱�����I
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

	//��ԑ傫���m�[�h����~���ɑS�m�[�h�����X�g�A�b�v
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
	//����v�m�[�h�͕\�����ȗ�
	//���ŋ߃m�[�h���琔�m�[�h��\��
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
	//searchNearestData(rbtree::FOR_NEAREST_LARGER);

	//�m�[�h���폜
	//������̃L�[���폜
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

	//�c���[��\��
	showTree();

	//���m�[�h����\��
	showNodesCount();

	//�m�[�h���폜
	//�����ׂĂ̒l�̃L�[������폜
	auto removeEachKeyNodes = [&con]()
	{
		printf("--- remove each-key nodes ---\n");
		for (int remove_key = key_min; remove_key <= key_max; ++remove_key)
		{
			const_iterator ite(con.find(remove_key));
			const bool result = con.erase(*ite);
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂��������኱�����I
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (result)
				printf("[%2d] \n", remove_key);
		}
		printf("\n");
	};
	removeEachKeyNodes();

	//�c���[��\��
	showTree();

	//���m�[�h����\��
	showNodesCount();
	
	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();

	//�m�[�h��S�폜
	//�����ׂĂ̒l�̃L�[�ɑ΂��āA�폜�����s����܂ō폜�����s
	auto removeAllNodes = [&con]()
	{
		printf("--- remove all nodes ---\n");
		for (int remove_key = key_min; remove_key <= key_max;)
		{
			const_iterator ite(con.find(remove_key));
			const bool result = con.erase(*ite);
			//���C�e���[�^�̕ϐ��錾�ƌ����𕪂��������኱�����I
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

	//��ԏ������m�[�h���珸���ɑS�m�[�h�����X�g�A�b�v
	showListAsc();

	return EXIT_SUCCESS;
}

// End of file
