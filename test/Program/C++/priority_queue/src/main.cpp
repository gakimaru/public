//--------------------------------------------------------------------------------
//�񕪃q�[�v�e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
static const int TEST_DATA_PRIOR_MIN = 1;//�e�X�g�f�[�^�̍ŏ��v���C�I���e�B
static const int TEST_DATA_PRIOR_MAX = 5;//�e�X�g�f�[�^�̍ő�v���C�I���e�B
static const int TEST_DATA_MAX = 128;//�e�X�g�f�[�^�̍ő�o�^�\��
static const int TEST_DATA_REG_NUM = 60;//�e�X�g�f�[�^�̓o�^��
#define PRINT_TEST_DATA_DETAIL//�e�X�g�f�[�̏ڍ׃^��\������ꍇ�́A���̃}�N����L��������

#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//std::size_t�p
#include <cstdint>//C++11 intptr_t�p

//--------------------------------------------------------------------------------
//�񕪃q�[�v
//--------------------------------------------------------------------------------
//�f�[�^�\���ƃA���S���Y��
//�y�����z
//�E�񕪖؂ł���B
//	  - �m�[�h�̎q�i���E�����j�ɂ́A���g���L�[���������m�[�h��A���B
//	  - �Z��m�[�h�Ԃ̃L�[�̑召�͕s��B
//�E���t�؂ł���B
//	  - �؂̃o�����X�͏�ɕۂ����B
//�E�ȏ�̓����ɂ��A�ł��L�[���傫���m�[�h�̒T�����Ԃ��A���O(1)�ɕۂ����B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y�{�v���O�����ɂ���������v���z
//�E�Œ�z��Ŏ������A��؃������m�ہE�폜�����Ȃ��B
//�E�m�[�h�A���̃|�C���^���g�p���Ȃ��B
//�@��ʓI�ȓ񕪃q�[�v�Ɠ������A�z��̏����Ɋ�Â��ĘA������B
//�E�R���e�i�ɂ͑Ή����邪�A�C�e���[�^�ɂ͑Ή����Ȃ��B
//�@�������A�z��̃|�C���^�����̂܂ܕԂ������� begin(), end() �֐��͎�������B
//�E���̓񕪃q�[�v���v���C�I���e�B�L���[�ɗ��p�����ꍇ�A
//�@�f�L���[�ipop�j���ɁA�L���[�C���O�ipush�j�̏������͕ۏ؂���Ȃ��B
//�@�����̋�����STL�Ɠ����B
//�E�������A�i�񕪃q�[�v������j�v���C�I���e�B�L���[�ł́A�L�[�̔�r��
//�@�v���C�I���e�B�ƃV�[�P���X�ԍ��𕹗p���邱�ƂŁA��������ۏ؂���B
//�ESTL�istd::priority_queue�j�Ƃ̈Ⴂ�͉��L�̒ʂ�
//    - �Œ蒷�z��ł���B�iSTL�͓�����std::vector���g�p���Ă���A�����g������j
//    - �ԍ��؃R���e�i�irb_tree�j�̎����ƍ��킹���\���ɂ��Ă���A
//�@�@  ����p�e���v���[�g�\���̂�p����B
//�@�@  ��STL�Ŏg�p�����r�p�̊֐��I�u�W�F�N�g�N���X(less)�͗p���Ȃ��B
//�@�@- C++11�́u�͈͂Ɋ�Â�for���[�v�v�ƁASTL�́ustd::for_each()�v���g�p�\�B
//�@�@  �P���ɔz��̓��e��񋓂���B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y��̓I�Ȋ��p�̑z��z
//�E�C�ӂ̍\���̃v���C�I���e�B�L���[�ɓK�p�B
//--------------------------------------------------------------------------------

namespace bin_heap
{
	//--------------------
	//�񕔃q�[�v����p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename NODE_TYPE>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public bin_heap::base_ope_t<�h���\����, �m�[�h�^>
	//	struct ope_t : public bin_heap::ope_t<ope_t, data_t>
	//	{
	//		//�L�[���r
	//		//��lhs�̕�������������� true ��Ԃ�
	//		inline static bool less(const node_type& lhs, const node_type& rhs)
	//		{
	//			return lhs.m_key < rhs.m_key;
	//		}
	//	};
	template<class OPE_TYPE, typename NODE_TYPE>
	struct base_ope_t
	{
		//�^
		typedef OPE_TYPE ope_type;//�m�[�h����^
		typedef NODE_TYPE node_type;//�m�[�h�^
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type;

	//----------------------------------------
	//�񕔃q�[�v�R���e�i
	//���Œ�z��Ǝg�p���̗v�f��������
	//��std::priority_queue�Ƃ͂��܂�݊������Ȃ��A�C�e���[�^�ɂ��Ή����Ȃ�
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	class container
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//�萔
		static const std::size_t TABLE_SIZE = _TABLE_SIZE;//�z��v�f��
	public:
		//�A�N�Z�b�T
		const node_type& at(const int index) const { return *ref_node(index); }
		node_type& at(const int index){ return *ref_node(index); }
		const node_type& operator[](const int index) const { return *ref_node(index); }
		node_type& operator[](const int index){ return *ref_node(index); }
	public:
		//���\�b�h
		std::size_t max_size() const { return TABLE_SIZE; }//�ő�v�f�����擾
		std::size_t capacity() const { return TABLE_SIZE; }//�ő�v�f�����擾
		std::size_t size() const { return m_used; }//�g�p���̗v�f�����擾
		bool empty() const { return m_used == 0; }//�󂩁H
	private:
		int _calc_depth_max(int depth) const { depth >>= 1; return depth == 0 ? 0 : 1 + _calc_depth_max(depth); }//�ő�̐[�����v�Z
	public:
		int depth_max() const { return m_used == 0 ? -1 : _calc_depth_max(m_used + 1); }//�ő�̐[�����擾
		void clear(){ m_used = 0; }//�N���A
		inline const node_type* ref_node(const int index) const { return index >= 0 && index < static_cast<int>(m_used) ? &m_array[index] : nullptr; }//�m�[�h�Q��
		inline const node_type* ref_top() const { return m_used == 0 ? nullptr : &m_array[0]; }//�擪�m�[�h�Q��
		inline const node_type* ref_bottom() const { return m_used == 0 ? nullptr : &m_array[m_used - 1]; }//�I�[�m�[�h�Q��
		inline const node_type* ref_new() const { return m_used == TABLE_SIZE ? nullptr : &m_array[m_used]; }//�V�K�m�[�h�Q��
		inline const node_type* begin() const { return m_used == 0 ? nullptr : &m_array[0]; }//�J�n�m�[�h
		inline const node_type* end() const { return m_used == 0 ? nullptr : &m_array[m_used]; }//�I���m�[�h
		inline node_type* ref_node(const int index){ return  const_cast<node_type*>(const_cast<const container*>(this)->ref_node()); }//�m�[�h�Q��
		inline node_type* ref_top(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_top()); }//�擪�m�[�h�Q��
		inline node_type* ref_bottom(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_bottom()); }//�I�[�m�[�h�Q��
		inline node_type* ref_new(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_new()); }//�V�K�m�[�h�Q��
		inline node_type* begin(){ return const_cast<node_type*>(const_cast<const container*>(this)->begin()); }//�J�n�m�[�h
		inline node_type* end(){ return const_cast<node_type*>(const_cast<const container*>(this)->end()); }//�I���m�[�h
	private:
		inline int _adj_index(const int index) const { return index >= 0 && index < TABLE_SIZE ? index : -1; }//�C���f�b�N�X��͈͓��ɕ␳
		inline int _ref_index(const node_type* node) const{ return node - m_array; }//�m�[�h���C���f�b�N�X�ɕϊ� ���͈̓`�F�b�N�Ȃ�
		inline int _calc_parent(const int index) const { return (index - 1) >> 1; }//�e�C���f�b�N�X�v�Z ���͈̓`�F�b�N�Ȃ�
		inline int _calc_child_l(const int index) const { return (index << 1) + 1; }//�����̎q�C���f�b�N�X�v�Z ���͈̓`�F�b�N�Ȃ�
		inline int _calc_child_r(const int index) const { return _calc_child_l(index) + 1; }//�E���̎q�C���f�b�N�X�v�Z ���͈̓`�F�b�N�Ȃ�
	public:
		inline int ref_index(const node_type* node) const{ return _adj_index(_ref_index(node)); }//�m�[�h���C���f�b�N�X�ɕϊ�
		inline int calc_parent(const int index) const { return _adj_index(_calc_parent(index)); }//�e�C���f�b�N�X�v�Z
		inline int calc_child_l(const int index) const { return _adj_index(_calc_child_l(index)); }//�����̎q�C���f�b�N�X�v�Z
		inline int calc_child_r(const int index) const { return _adj_index(_calc_child_r(index)); }//�E���̎q�C���f�b�N�X�v�Z
		inline int calc_child(const int index, const bool is_right) const { return is_right ? calc_child_r(index) : calc_child_l(index); }//�q�C���f�b�N�X�v�Z
		inline const node_type* ref_parent(const node_type* node) const { return ref_node(_calc_parent(_ref_index(node))); }//�e�m�[�h�Q��
		inline const node_type* ref_child_l(const node_type* node) const { return ref_node(_calc_child_l(_ref_index(node))); }//�����̎q�m�[�h�Q��
		inline const node_type* ref_child_r(const node_type* node) const { return ref_node(_calc_child_r(_ref_index(node))); }//�����̎q�m�[�h�Q��
		inline const node_type* ref_child(const node_type* node, const bool is_right) const { return is_right ? ref_child_r(node) : ref_child_l(node); }//�q�m�[�h�Q��
		inline node_type* ref_parent(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_parent(index)); }//�e�m�[�h�Q��
		inline node_type* ref_child_l(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child_l(index)); }//�����̎q�m�[�h�Q��
		inline node_type* ref_child_r(const int index){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child_r(index)); }//�����̎q�m�[�h�Q��
		inline node_type* ref_child(const int index, const bool is_right){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_child(index, is_right)); }//�q�m�[�h�Q��
	private:
		inline bool _less(const bool result) const { return m_isReverse ? !result : result; }//�L�[��r
	public:
		inline bool less(const node_type& lhs, const node_type& rhs) const { return _less(ope_type::less(lhs, rhs)); }//�L�[��r
		//�v�b�V��
		const node_type* push(const node_type& obj)
		{
			node_type* dst = push_begin();
			if (!dst)
				return nullptr;
			*dst = obj;
			return push_end();
		}
		//�v�b�V���J�n
		//���󂫃m�[�h�擾
		node_type* push_begin(){ return &m_array[m_used]; }
		//�v�b�V���I��
		//���ǉ������V�K�m�[�h����Ɉړ�
		const node_type* push_end()
		{
			if (m_used == TABLE_SIZE)
				return nullptr;
			//���[�̗t�m�[�h�Ƃ��ēo�^���ꂽ�V�K�m�[�h������Ɉړ�
			std::size_t index = m_used++;
			node_type* obj = &m_array[index];
			while (index != 0)
			{
				index = _calc_parent(index);
				node_type* parent = &m_array[index];
				if (less(*parent, *obj))
				{
					node_type tmp;
					tmp = *obj;
					*obj = *parent;
					*parent = tmp;
					obj = parent;
				}
			}
			return obj;
		}
		//�|�b�v
		bool pop(node_type& dst)
		{
			const node_type* obj = pop_begin();
			if (!obj)
				return false;
			dst = *obj;
			return pop_end();
		}
		//�|�b�v�J�n
		//�����m�[�h�擾
		const node_type* pop_begin(){ return &m_array[0]; }
		//�|�b�v�I��
		//���폜�������m�[�h�̌��Ԃ𖄂߂邽�߂ɁA�ȍ~�̃m�[�h����Ɉړ�
		bool pop_end()
		{
			if (m_used == 0)
				return false;
			//���m�[�h���|�b�v���ꂽ�̂ŁA���[�̗t�m�[�h�����m�[�h�ɏ㏑��������ŁA����������Ɉړ�
			std::size_t index = 0;
			node_type* obj = &m_array[0];
			*obj = m_array[--m_used];
			while (true)
			{
				index = _calc_child_l(index);
				if (index >= m_used)
					break;
				node_type* child = &m_array[index];
				node_type* child_r = index + 1 < m_used ? child + 1 : nullptr;
				bool is_swap = false;
				if (child_r && !less(*child_r, *child) && !less(*child_r, *obj))
				{
					is_swap = true;
					child = child_r;
					++index;
				}
				else if (!less(*child, *obj))
				{
					is_swap = true;
				}
				if (is_swap)
				{
					node_type tmp;
					tmp = *obj;
					*obj = *child;
					*child = tmp;
				}
				obj = child;
			}
			return true;
		}
	public:
		//�R���X�g���N�^
		//���L�[��r������n��
		container(const bool is_reverse = false) :
			m_used(0),
			m_isReverse(is_reverse)
		{}
		//�f�X�g���N�^
		~container()
		{}
	private:
		//�t�B�[���h
		node_type m_array[TABLE_SIZE];//�z��
		std::size_t m_used;//�g�p��
		const bool m_isReverse;//�L�[��r�𔽓]���邩�H
	};
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace bin_heap

//--------------------------------------------------------------------------------
//�v���C�I���e�B�L���[
//���v���C�I���e�B�ƂƂ��ɁA�V�[�P���X�ԍ����������ƂŁA�L���[�C���O�̏�������ۏ؂���B
//���ŏI�I�ɂ́A�X���b�h�Z�[�t�ȍ\���ɂ���B
namespace prior_queue
{
	//--------------------
	//�v���C�I���e�B�L���[����p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename NODE_TYPE, int _NODES_MAX>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public prior_queue::base_ope_t<�h���\����, �m�[�h�^, �D��x�^, �V�[�P���X�ԍ��^>
	//	struct ope_t : public prior_queue::ope_t<ope_t, data_t, int, unsigned int>
	//	{
	//		//�D��x���擾
	//		inline static prior_type getPrior(const node_type& node){ return node.m_prior; }
	//		//�D��x���X�V
	//		inline static void setPrior(node_type& node, const prior_type prior){ node.m_prior = prior; }
	//		
	//		//�V�[�P���X�ԍ����擾
	//		inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//		//�V�[�P���X�ԍ����X�V
	//		inline static void setSeqNo(node_type& node, const seq_type seq_no) const { node.m_seqNo = seq_no; }
	//		
	//		//�D��x���r
	//		//Return value:
	//		//  0 ... lhs == rhs
	//		//  1 ... lhs > rhs
	//		// -1 ... lhs < rhs
	//		inline static int compareProior(const prior_type lhs, const prior_type rhs)
	//		{
	//			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
	//		}
	//	};
	template<class OPE_TYPE, typename NODE_TYPE, typename PRIOR_TYPE = int, typename SEQ_TYPE = unsigned int>
	struct base_ope_t
	{
		//�^
		typedef OPE_TYPE ope_type;//�m�[�h����^
		typedef NODE_TYPE node_type;//�m�[�h�^
		typedef PRIOR_TYPE prior_type;//�D��x�^
		typedef SEQ_TYPE seq_type;//�V�[�P���X�ԍ��^

		//�V�[�P���X�ԍ����r
		inline static bool lessSeqNo(const seq_type lhs, const seq_type rhs)
		{
			return lhs > rhs;
		}

		//�D��x���r
		//���f�t�H���g
		//Return value:
		//  0 ... lhs == rhs
		//  1 ... lhs > rhs
		// -1 ... lhs < rhs
		inline static int comparePriority(const prior_type lhs, const prior_type rhs)
		{
			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
		}

		//�L�[���r
		//��lhs�̕�������������� true ��Ԃ�
		inline static bool _lessSeqNo(const int compare_priority, const seq_type lhs, const seq_type rhs)
		{
			return compare_priority < 0 ? true : compare_priority > 0 ? false : ope_type::lessSeqNo(lhs, rhs);
		}
		inline static bool less(const node_type& lhs, const node_type& rhs)
		{
			return _lessSeqNo(ope_type::comparePriority(ope_type::getPrior(lhs), ope_type::getPrior(rhs)), ope_type::getSeqNo(lhs), ope_type::getSeqNo(rhs));
		}

		//STL��std::priority_queue�Ƌ��p���邽�߂̊֐��I�u�W�F�N�g
		inline bool operator()(const node_type& lhs, const node_type& rhs) const{ return less(lhs, rhs); }
	};
	//--------------------
	//��{�^��`�}�N��
	#define DECLARE_OPE_TYPES(OPE_TYPE) \
		typedef OPE_TYPE ope_type; \
		typedef typename ope_type::node_type node_type; \
		typedef node_type value_type; \
		typedef value_type& reference; \
		typedef const value_type& const_reference; \
		typedef value_type* pointer; \
		typedef const value_type* const_pointer; \
		typedef std::size_t size_type; \
		typedef typename ope_type::prior_type prior_type; \
		typedef typename ope_type::seq_type seq_type;

	//----------------------------------------
	//�v���C�I���e�B�L���[�R���e�i
	//�������ɓ񕪃q�[�v������
	//��std::priority_queue�Ƃ͂��܂�݊������Ȃ��A�C�e���[�^�ɂ��Ή����Ȃ�
	template<class OPE_TYPE, std::size_t _TABLE_SIZE>
	class container
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
		typedef bin_heap::container<ope_type, _TABLE_SIZE> bin_heap;
	public:
		//�A�N�Z�b�T
		const bin_heap& getHeap() const { return m_heap; }//�񕪃q�[�v�擾
		bin_heap& getHeap(){ return m_heap; }//�񕪃q�[�v�擾
	public:
		//�L���X�g�I�y���[�^
		operator const bin_heap() const{ return m_heap; }//�񕪃q�[�v��Ԃ�
		operator bin_heap(){ return m_heap; }//�񕪃q�[�v��Ԃ�
	public:
		//���\�b�h
		std::size_t max_size() const { return m_heap.max_aize(); }//�ő�v�f�����擾
		std::size_t capacity() const { return m_heap.capacity(); }//�ő�v�f�����擾
		std::size_t size() const { return m_heap.size(); }//�g�p���̗v�f�����擾
		bool empty() const { return m_heap.empty(); }//�󂩁H
	public:
		void clear(){ m_heap.clear(); }//�N���A
		inline const node_type* begin() const { return m_heap.begin(); }//�J�n�m�[�h
		inline const node_type* end() const { return m_heap.end(); }//�I���m�[�h
		inline node_type* begin(){ return m_heap.begin(); }//�J�n�m�[�h
		inline node_type* end(){ return m_heap.end(); }//�I���m�[�h
	private:
		//�V�[�P���X�ԍ����s
		seq_type getNextSeqNo(){ return m_seqNo++; }
		//�\�Ȃ�V�[�P���X�ԍ������Z�b�g
		void checkAndResetSeqNo()
		{
			if (m_heap.empty())
				m_seqNo = 0;
		}
	public:
		//�L���[�C���O
		const node_type* enqueue(node_type& obj)
		{
			ope_type::setSeqNo(obj, getNextSeqNo());
			return m_heap.push(obj);
		}
		//�L���[�C���O�J�n
		//���󂫃m�[�h�擾
		node_type* enqueueBegin(const prior_type prior)
		{
			node_type* node = m_heap.push_begin();
			if (!node)
				return nullptr;
			ope_type::setPrior(*node, prior);
			ope_type::setSeqNo(*node, getNextSeqNo());
			return node;
		}
		//�L���[�C���O�I��
		const node_type* push_end(){ return m_heap.push_end(); }
		//�f�L���[
		bool dequeue(node_type& dst)
		{
			const bool result = m_heap.pop(dst);
			if (!result)
				return false;
			checkAndResetSeqNo();
			return true;
		}
		//�f�L���[�J�n
		const node_type* dequeueBegin(){ return m_heap.pop_begin(); }
		//�f�L���[�I��
		bool dequeueEnd()
		{
			const bool result = m_heap.pop_end();
			checkAndResetSeqNo();
			return result;
		}
	public:
		//�R���X�g���N�^
		//���L�[��r������n��
		container(const bool is_reverse = false) :
			m_heap(is_reverse),
			m_seqNo(0)
		{}
		//�f�X�g���N�^
		~container()
		{}
	private:
		//�t�B�[���h
		bin_heap m_heap;//�񕪃q�[�v
		seq_type m_seqNo;//�V�[�P���X�ԍ�
	};
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace prior_queue

//--------------------------------------------------------------------------------
//�v���C�I���e�B�L���[�e�X�g

#include <memory.h>//memcpy�p
#include <random>//C++11 std::random�p
#include <algorithm>//std::for_each�p
#include <queue>//std::priority_queue�p����r�e�X�g�p

//----------------------------------------
//�e�X�g�f�[�^
enum PRIORITY : short
{
	HIGHEST = 5,
	HIGHER = 2,
	NORMAL = 3,
	LOWER = 2,
	LOWEST = 1,
};
struct data_t
{
	PRIORITY m_prior;//�D��x
	int m_seqNo;//�V�[�P���X�ԍ�
	int m_val;//�f�[�^

	//�R���X�g���N�^
	data_t(const PRIORITY prior, const int val) :
		m_prior(prior),
		m_seqNo(0),
		m_val(val)
	{}
	data_t(const int val) :
		m_prior(NORMAL),
		m_seqNo(0),
		m_val(val)
	{}
	data_t() :
		m_prior(NORMAL),
		m_seqNo(0),
		m_val(0)
	{}
};
//----------------------------------------
//�e�X�g�f�[�^����N���X
struct ope_t : public prior_queue::base_ope_t<ope_t, data_t, PRIORITY, int>
{
	//�D��x���擾
	inline static prior_type getPrior(const node_type& node){ return node.m_prior; }
	//�D��x���X�V
	inline static void setPrior(node_type& node, const prior_type prior){ node.m_prior = prior; }
	
	//�V�[�P���X�ԍ����擾
	inline static seq_type getSeqNo(const node_type& node){ return node.m_seqNo; }
	//�V�[�P���X�ԍ����X�V
	inline static void setSeqNo(node_type& node, const seq_type seq_no){ node.m_seqNo = seq_no; }
};

//----------------------------------------
//�e�X�g�p�⏕�֐�
#ifdef PRINT_TEST_DATA_DETAIL
template<typename... Tx>
inline int printf_detail(const char* fmt, Tx... args)
{
	return printf(fmt, args...);
}
#else//PRINT_TEST_DATA_DETAIL
inline int printf_detail(const char* fmt, ...){ return 0; }
#endif//PRINT_TEST_DATA_DETAIL

//----------------------------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	//�v���C�I���e�B�L���[�R���e�i����
	typedef prior_queue::container<ope_t, TEST_DATA_MAX> contaier_type;
	typedef contaier_type::bin_heap bin_heap;
	contaier_type con;

	//�L���[�C���O
	auto pushNodes = [&con]()
	{
		printf("--- Push nodes ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		for (int val = 0; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			printf_detail("[%d:%2d] ", priority, val);
			data_t obj(priority, val);
			con.enqueue(obj);
		}
		printf_detail("\n");
	};
	pushNodes();

#if 0
	//�͈͂Ɋ�Â�for���[�v�e�X�g
	auto printNodesTest1 = [&con]()
	{
		printf("--- Test for C++11 for(:) ---\n");
		for (const data_t& o : con)
			printf("[%1d:%2d] ", o.m_prior, o.m_val);
		printf("\n");
	};
	printNodesTest1();
#endif

#if 0
	//std::for_each�e�X�g
	auto printNodesTest2 = [&con]()
	{
		printf("--- Test for std::for_each() ---\n");
		std::for_each(con.begin(), con.end(), [](data_t& o)
			{
				printf("[%1d:%2d] ", o.m_prior, o.m_val);
			}
		);
		printf("\n");
	};
	printNodesTest2();
#endif

	//�؂�\��
	auto showTree = [](const bin_heap& heap)
	{
		printf("--- Show tree (count=%d) ---\n", heap.size());
		static const int depth_limit = 5;//�ő�ł�5�i�K�ڂ܂ł�\���i0�i�K�ڂ��琔����̂ōő��6�i�K�\������遨�ő�F1+2+4+8+16+32�j
		const int _depth_max = heap.depth_max();
		printf("depth_max=%d (limit for showing=%d)\n", _depth_max, depth_limit);
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
				const data_t* node = heap.ref_top();
				int breath_tmp = breath;
				for (int depth_tmp = depth - 1; node; --depth_tmp)
				{
					if (depth_tmp < 0)
						break;
					node = heap.ref_child(node, (breath_tmp & (0x1 << depth_tmp)) != 0x0);
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (heap.ref_child_l(node) && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(heap.ref_child_l(node) ? "-" : " ");
					}
					printf("%s%1d:%2d%s", heap.ref_child_l(node) ? "{" : "[", node->m_prior, node->m_val, heap.ref_child_r(node) ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(heap.ref_child_r(node) ? "-" : " ");
						if (heap.ref_child_r(node) && c < print_indent)
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
	showTree(con);

	//�m�[�h���|�b�v
	auto popNodes = [&con](const int pop_limit)
	{
		printf("--- Pop nodes ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			data_t node;
			const bool result = con.dequeue(node);
			if (!result)
				break;
			printf("[%1d:%2d] ", node.m_prior, node.m_val);
		}
		printf("\n");
	};
	popNodes(TEST_DATA_REG_NUM / 2);
	showTree(con);//�؂�\��

	//�m�[�h���|�b�v
	popNodes(TEST_DATA_REG_NUM);
	showTree(con);//�؂�\��

	//�ȉ��A�񕪃q�[�v�Ƃ̋�����r
	bin_heap heap;

	//�񕪃q�[�v�Ńm�[�h���v�b�V��
	auto pushNodesBinHeap = [&heap]()
	{
		printf("--- Push nodes(Binary Heap) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		for (int val = 0; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			printf_detail("[%d:%2d] ", priority, val);
			data_t obj(priority, val);
			heap.push(obj);
		}
		printf_detail("\n");
	};
	pushNodesBinHeap();

	//�؂�\��
	showTree(heap);
	
	//�񕪃q�[�v�Ńm�[�h���|�b�v
	auto popNodesBinHeap  = [&heap](const int pop_limit)
	{
		printf("--- Pop nodes(Binary Heap) ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			data_t node;
			const bool result = heap.pop(node);
			if (!result)
				break;
			printf("[%1d:%2d] ", node.m_prior, node.m_val);
		}
		printf("\n");
	};
	popNodesBinHeap(TEST_DATA_REG_NUM / 2);
	showTree(heap);//�؂�\��

	//�m�[�h���|�b�v
	popNodesBinHeap(TEST_DATA_REG_NUM);
	showTree(heap);//�؂�\��

	//�ȉ��ASTL�Ƃ̋�����r
	std::priority_queue<data_t, std::vector<data_t>, ope_t> stl;

	//STL�Ńm�[�h���v�b�V��
	auto pushNodesSTL = [&stl]()
	{
		printf("--- Push nodes(STL) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		for (int val = 0; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			printf_detail("[%1d:%2d] ", priority, val);
			data_t obj(priority, val);
			stl.push(obj);
		}
		printf_detail("\n");
	};
	pushNodesSTL();

	//STL�Ńm�[�h���|�b�v
	auto popNodesSTL = [&stl](const int pop_limit)
	{
		printf("--- Pop nodes(STL) ---\n");
		for (int i = 0; i < pop_limit && !stl.empty(); ++i)
		{
			data_t node = stl.top();
			printf("[%1d:%2d] ", node.m_prior, node.m_val);
			stl.pop();
		}
		printf("\n");
	};
	popNodesSTL(TEST_DATA_REG_NUM / 2);
	popNodesSTL(TEST_DATA_REG_NUM);

	//�v���C�I���e�B�L���[���Ď��s
	pushNodes();//�L���[�C���O
	showTree(con);//�؂�\��
	popNodes(TEST_DATA_REG_NUM);//�m�[�h���|�b�v

	return EXIT_SUCCESS;
}

// End of file
