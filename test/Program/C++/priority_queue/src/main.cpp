//--------------------------------------------------------------------------------
//�񕪃q�[�v�e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
static const int TEST_DATA_PRIOR_MIN = 1;//�e�X�g�f�[�^�̍ŏ��v���C�I���e�B
static const int TEST_DATA_PRIOR_MAX = 5;//�e�X�g�f�[�^�̍ő�v���C�I���e�B
static const int TEST_DATA_MAX = 128;//�e�X�g�f�[�^�̍ő�o�^�\��
static const int TEST_DATA_REG_NUM = 60;//�e�X�g�f�[�^�̓o�^��

#define PRINT_TEST_DATA_DETAIL//�e�X�g�f�[�̏ڍ׃^��\������ꍇ�́A���̃}�N����L��������
//#define TEST_DATA_WATCH_CONSTRUCTOR//�R���X�g���N�^�^�f�X�g���N�^�^������Z�q�̓�����m�F����ꍇ�A���̃}�N����L��������

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------
//���ʏ���
//--------------------------------------------------------------------------------

#include <type_traits>//C++11 std::is_class, std::conditional�p
#include <utility>//C++11 std::move�p

//----------------------------------------
//�f�[�^�̓���ւ�
template<class T>
struct _swapArithmetic{
	inline static void exec(T& val1, T& val2)
	{
		T tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapArithmetic<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		T* tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapObjects{
	inline static void exec(T& val1, T& val2)
	{
#if 1//���[�u�I�y���[�^���g�p���ē���ւ��i#include <utility> �� std::swap() �Ɠ����j
		T tmp = std::move(std::move(val2));
		val2 = std::move(val1);
		val1 = std::move(tmp);
#else//�R���X�g���N�^�^�I�y���[�^�̌Ăяo��������ĒP���ȃ������R�s�[
		char tmp[sizeof(T)];
		memcpy(tmp, &val2, sizeof(T));
		memcpy(&val2, &val1, sizeof(T));
		memcpy(&val1, tmp, sizeof(T));
#endif
	}
};
template<class T>
struct _swapObjects<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		_swapArithmetic<T*>::exec(val1, val2);
	}
};
template<class T>
inline void swapValues(T& val1, T& val2)
{
	std::conditional<std::is_arithmetic<T>::value,
		_swapArithmetic<T>,
		_swapObjects<T>
	>::type::exec(val1, val2);
}

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
//�@�f�L���[�ipop�j���ɁA�G���L���[�ipush�j�̏������͕ۏ؂���Ȃ��B
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
//    - �������̂��߂ɁA�I�u�W�F�N�g�̃R�s�[�𔺂�������A
//      �����I�ȃ��\�b�h�ipushCoping/ popCoping�j�ɂ��Ă���B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y��̓I�Ȋ��p�̑z��z
//�E�C�ӂ̍\���̃v���C�I���e�B�L���[�ɓK�p�B
//--------------------------------------------------------------------------------

#include <cstddef>//std::size_t�p

namespace bin_heap
{
	//--------------------
	//�񕪃q�[�v����p�e���v���[�g�\����
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

		//�f�X�g���N�^�Ăяo��
		static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
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
	//�񕪃q�[�v�R���e�i
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
		enum state_t//�X�e�[�g
		{
			IDLE = 0,//�A�C�h��
			PUSH_BEGINNING,//�v�b�V���J�n��
			PUSH_ENDED,//�v�b�V���I������
			PUSH_CANCELLED,//�v�b�V����������
			POP_BEGINNING,//�|�b�v�J�n��
			POP_ENDED,//�|�b�v�I������
			POP_CANCELLED,//�|�b�v��������
		};
	public:
		//�A�N�Z�b�T
		inline const node_type* at(const int index) const { return ref_node(index); }
		inline node_type* at(const int index){ return ref_node(index); }
		inline const node_type* operator[](const int index) const { return ref_node(index); }
		inline node_type* operator[](const int index){ return ref_node(index); }
		inline state_t state() const { return m_state; }
	public:
		//���\�b�h
		inline std::size_t max_size() const { return TABLE_SIZE; }//�ő�v�f�����擾
		inline std::size_t capacity() const { return TABLE_SIZE; }//�ő�v�f�����擾
		inline std::size_t size() const { return m_used; }//�g�p���̗v�f�����擾
		inline bool empty() const { return m_used == 0; }//�󂩁H
	public:
		int depth_max() const//�ő�̐[�����擾
		{
			if (m_used == 0)
				return -1;
			int depth = 0;
			int used = m_used >> 1;
			while (used != 0)
			{
				++depth;
				used >>= 1;
			}
			return depth;
		}
	private:
		inline const node_type* _ref_node(const int index) const { return reinterpret_cast<const node_type*>(&m_table[index]); }//�m�[�h�Q��
		inline const node_type* _ref_top() const { return _ref_node(0); }//�擪�m�[�h�Q��
		inline const node_type* _ref_bottom() const { return _ref_node(m_used - 1); }//�I�[�m�[�h�Q��
		inline const node_type* _ref_new() const { return _ref_node(m_used); }//�V�K�m�[�h�Q��
		inline node_type* _ref_node(const int index){ return reinterpret_cast<node_type*>(&m_table[index]); }//�m�[�h�Q��
		inline node_type* _ref_top(){ return _ref_node(0); }//�擪�m�[�h�Q��
		inline node_type* _ref_bottom(){ return _ref_node(m_used - 1); }//�I�[�m�[�h�Q��
		inline node_type* _ref_new(){ return _ref_node(m_used); }//�V�K�m�[�h�Q��
	public:
		inline const node_type* ref_node(const int index) const { return index >= 0 && index < static_cast<int>(m_used) ? _ref_node(index) : nullptr; }//�m�[�h�Q��
		inline const node_type* ref_top() const { return m_used == 0 ? nullptr : _ref_top(); }//�擪�m�[�h�Q��
		inline const node_type* ref_bottom() const { return m_used == 0 ? nullptr : _ref_bottom(); }//�I�[�m�[�h�Q��
		inline const node_type* ref_new() const { return m_used == TABLE_SIZE ? nullptr : _ref_new(); }//�V�K�m�[�h�Q��
		inline const node_type* begin() const { return m_used == 0 ? nullptr : _ref_top(); }//�J�n�m�[�h
		inline const node_type* end() const { return m_used == 0 ? nullptr : _ref_new(); }//�I���m�[�h
		inline node_type* ref_node(const int index){ return  const_cast<node_type*>(const_cast<const container*>(this)->ref_node()); }//�m�[�h�Q��
		inline node_type* ref_top(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_top()); }//�擪�m�[�h�Q��
		inline node_type* ref_bottom(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_bottom()); }//�I�[�m�[�h�Q��
		inline node_type* ref_new(){ return const_cast<node_type*>(const_cast<const container*>(this)->ref_new()); }//�V�K�m�[�h�Q��
		inline node_type* begin(){ return const_cast<node_type*>(const_cast<const container*>(this)->begin()); }//�J�n�m�[�h
		inline node_type* end(){ return const_cast<node_type*>(const_cast<const container*>(this)->end()); }//�I���m�[�h
	private:
		inline int _adj_index(const int index) const { return index >= 0 && index < TABLE_SIZE ? index : -1; }//�C���f�b�N�X��͈͓��ɕ␳
		inline int _ref_index(const node_type* node) const{ return node - _ref_top(); }//�m�[�h���C���f�b�N�X�ɕϊ� ���͈̓`�F�b�N�Ȃ�
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
	public:
		inline bool less(const node_type& lhs, const node_type& rhs) const { return ope_type::less(lhs, rhs); }//�L�[��r
		//�v�b�V��
		//���I�u�W�F�N�g�n��
		//���I�u�W�F�N�g�̃R�s�[����������_�ɒ��Ӂi�����x���Ȃ�j
		node_type* pushCopying(const node_type& src)
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			*obj = src;
			m_state = PUSH_BEGINNING;
			return pushEnd();
		}
		//�v�b�V��
		//���p�����[�^�n��
		//���I�u�W�F�N�g�̃R���X�g���N�^���Ăяo�����
		template<typename... Tx>
		node_type* push(Tx... args)
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = pushBegin(args...);
			if (!obj)
				return nullptr;
			return pushEnd();
		}
		//�v�b�V���J�n
		//���󂫃m�[�h���擾���A�R���X�g���N�^���Ăяo�����
		template<typename... Tx>
		node_type* pushBegin(Tx... args)
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			obj = new(obj)node_type(args...);//�R���X�g���N�^�Ăяo��
			if (obj)
				m_state = PUSH_BEGINNING;
			return obj;
		}
		//�v�b�V���I��
		//���ǉ������V�K�m�[�h����Ɉړ�
		node_type* pushEnd()
		{
			if (m_state != PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_new();
			if (!obj)
				return nullptr;
			++m_used;
			m_state = PUSH_ENDED;
			//���[�̗t�m�[�h�Ƃ��ēo�^���ꂽ�V�K�m�[�h������Ɉړ�
			return upHeap(obj);
		}
		//�v�b�V��������
		bool pushCancel()
		{
			if (m_state != PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_state = PUSH_CANCELLED;
			return true;
		}
		//�|�b�v
		//���I�u�W�F�N�g�̃R�s�[���󂯎��̈��n��
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo����� ���R�s�[��Ɏ��s
		bool popCopying(node_type& dst)
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return false;
			const node_type* obj = popBegin();
			if (!obj)
				return false;
			dst = *obj;
			return popEnd();
		}
		//�|�b�v�J�n
		//�����m�[�h�擾
		node_type* popBegin()
		{
			if (m_state == PUSH_BEGINNING || m_state == POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* obj = ref_top();
			if (obj)
				m_state = POP_BEGINNING;
			return obj;
		}
		//�|�b�v�I��
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo�����
		//���폜�������m�[�h�̌��Ԃ𖄂߂邽�߂ɁA�ȍ~�̃m�[�h����Ɉړ�
		bool popEnd()
		{
			if (m_state != POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			node_type* obj = ref_bottom();
			if (!obj)
				return false;
			ope_type::callDestructor(obj);//�f�X�g���N�^�Ăяo��
			operator delete(obj, obj);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			m_state = POP_ENDED;
			//���m�[�h���|�b�v���ꂽ�̂ŁA���[�̗t�m�[�h�����m�[�h�ɏ㏑��������ŁA����������Ɉړ�
			node_type* top_obj = _ref_top();
			*top_obj = *obj;
			--m_used;
			downHeap(top_obj);
			return true;
		}
		//�|�b�v������
		bool popCancel()
		{
			if (m_state != POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_state = POP_CANCELLED;
			return true;
		}
		//�m�[�h������Ɉړ�
		node_type* upHeap(node_type* obj)
		{
			int index = ref_index(obj);
			if (index < 0)
				return nullptr;
			while (index != 0)
			{
				index = _calc_parent(index);
				node_type* parent = _ref_node(index);
				if (less(*parent, *obj))
				{
					swapValues(*parent, *obj);
					obj = parent;
				}
				else
					break;
			}
			return obj;
		}
		//�m�[�h�������Ɉړ�
		node_type* downHeap(node_type* obj)
		{
			int index = ref_index(obj);
			if (index < 0)
				return nullptr;
			while (true)
			{
				index = _calc_child_l(index);
				if (index >= m_used)
					break;
				node_type* child = _ref_node(index);
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
					swapValues(*child, *obj);
				else
					break;
				obj = child;
			}
			return obj;
		}
		//�N���A
		void clear()
		{
			node_type* obj_end = end();
			for (node_type* obj = begin(); obj < obj_end; ++obj)
			{
				ope_type::callDestructor(obj);//�f�X�g���N�^�Ăяo��
				operator delete(obj, obj);//�i��@�Ƃ��ājdelete�I�y���[�^�Ăяo��
			}
			m_used = 0;
		}
	public:
		//�R���X�g���N�^
		//���L�[��r������n��
		container() :
			m_used(0),
			m_state(IDLE)
		{}
		//�f�X�g���N�^
		~container()
		{
			pushCancel();//�v�b�V��������
			popCancel();//�|�b�v������
		}
	private:
		//�t�B�[���h
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//�f�[�^�e�[�u��
		int m_used;//�g�p��
		state_t m_state;//�X�e�[�g
	};
	//--------------------
	//���S�ȃv�b�V���^�|�b�v����N���X
	template<class CON>
	class operation_guard
	{
	public:
		//�^
		typedef CON container_type;//�R���e�i�^
		typedef typename CON::node_type node_type;//�m�[�h�^
		typedef typename CON::state_t state_t;//�X�e�[�g�^
	public:
		//�A�N�Z�b�T
		state_t state() const { return m_state; }//�X�e�[�g���擾
	public:
		//�v�b�V���J�n
		template<typename... Tx>
		node_type* pushBegin(Tx... args)
		{
			if (m_state == state_t::PUSH_BEGINNING || m_state == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.pushBegin(args...);//�v�b�V���J�n
			if (node)
				m_state = state_t::PUSH_BEGINNING;//�X�e�[�g�ύX
			return node;
		}
		//�v�b�V���I��
		node_type* pushEnd()
		{
			if (m_state != state_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.pushEnd();//�v�b�V���I��
			m_state = state_t::PUSH_ENDED;//�X�e�[�g�ύX
			return node;
		}
		//�v�b�V��������
		bool pushCancel()
		{
			if (m_state != state_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_container.pushCancel();//�v�b�V��������
			m_state = state_t::PUSH_CANCELLED;//�X�e�[�g�ύX
			return true;
		}
		//�|�b�v�J�n
		node_type* popBegin()
		{
			if (m_state == state_t::PUSH_BEGINNING || m_state == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.popBegin();//�|�b�v�J�n
			if (node)
				m_state = state_t::POP_BEGINNING;//�X�e�[�g�ύX
			return node;
		}
		//�|�b�v�I��
		bool popEnd()
		{
			if (m_state != state_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			const bool result = m_container.popEnd();//�|�b�v�I��
			m_state = state_t::POP_ENDED;//�X�e�[�g�ύX
			return result;
		}
		//�|�b�v������
		bool popCancel()
		{
			if (m_state != state_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_container.popCancel();//�|�b�v������
			m_state = state_t::POP_CANCELLED;//�X�e�[�g�ύX
			return true;
		}
	public:
		//�R���X�g���N�^
		operation_guard(container_type& container) :
			m_container(container),
			m_state(state_t::IDLE)
		{}
		//�f�X�g���N�^
		~operation_guard()
		{
			pushEnd();//�v�b�V���I��
			popEnd();//�|�b�v�I��
		}
	private:
		//�t�B�[���h
		container_type& m_container;//�R���e�i
		state_t m_state;//�X�e�[�g
	};
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace bin_heap

//--------------------------------------------------------------------------------
//�v���C�I���e�B�L���[
//���v���C�I���e�B�ƂƂ��ɁA�V�[�P���X�ԍ����������ƂŁA�L���[�C���O�̏�������ۏ؂���B
//--------------------------------------------------------------------------------

#include <utility>//C++11 std::move�p
#include <mutex>//C++11 std::mutex�p

namespace priority_queue
{
	//--------------------
	//�v���C�I���e�B�L���[����p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename NODE_TYPE, int _NODES_MAX>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public priority_queue::base_ope_t<�h���\����, �m�[�h�^, �D��x�^, �V�[�P���X�ԍ��^>
	//	struct ope_t : public priority_queue::ope_t<ope_t, data_t, int, unsigned int>
	//	{
	//		//�D��x���擾
	//		inline static priority_type getPrior(const node_type& node){ return node.m_priority; }
	//		//�D��x���X�V
	//		inline static void setPrior(node_type& node, const priority_type priority){ node.m_priority = priority; }
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
	//		inline static int compareProior(const priority_type lhs, const priority_type rhs)
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
		typedef PRIOR_TYPE priority_type;//�D��x�^
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
		inline static int comparePriority(const priority_type lhs, const priority_type rhs)
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

		//�f�X�g���N�^�Ăяo��
		static void callDestructor(node_type* obj){ obj->~NODE_TYPE(); }
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
		typedef typename ope_type::priority_type priority_type; \
		typedef typename ope_type::seq_type seq_type;

	//----------------------------------------
	//�v���C�I���e�B�L���[�R���e�i�p�萔
	enum auto_lock_attr_t : unsigned char//�������b�N����
	{
		NEVER_LOCK,//���b�N���Ȃ�
		AUTO_LOCK,//�������b�N
	};
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
		typedef bin_heap::container<ope_type, _TABLE_SIZE> bin_heap_type;//�񕪃q�[�v�^
		typedef typename bin_heap_type::state_t state_t;//�X�e�[�g�^
	public:
		//�A�N�Z�b�T
		inline const bin_heap_type& getHeap() const { return m_heap; }//�񕪃q�[�v�擾
		inline bin_heap_type& getHeap(){ return m_heap; }//�񕪃q�[�v�擾
	public:
		//�L���X�g�I�y���[�^
		inline operator const bin_heap_type() const{ return m_heap; }//�񕪃q�[�v��Ԃ�
		inline operator bin_heap_type(){ return m_heap; }//�񕪃q�[�v��Ԃ�
		inline operator std::mutex(){ return m_lock; }//�~���[�e�b�N�X��Ԃ�
	public:
		//���\�b�h
		inline std::size_t max_size() const { return m_heap.max_aize(); }//�ő�v�f�����擾
		inline std::size_t capacity() const { return m_heap.capacity(); }//�ő�v�f�����擾
		inline std::size_t size() const { return m_heap.size(); }//�g�p���̗v�f�����擾
		inline bool empty() const { return m_heap.empty(); }//�󂩁H
	public:
		inline const node_type* begin() const { return m_heap.begin(); }//�J�n�m�[�h
		inline const node_type* end() const { return m_heap.end(); }//�I���m�[�h
		inline node_type* begin(){ return m_heap.begin(); }//�J�n�m�[�h
		inline node_type* end(){ return m_heap.end(); }//�I���m�[�h
	private:
		//�V�[�P���X�ԍ����s
		inline seq_type getNextSeqNo(){ return m_seqNo++; }
		//�\�Ȃ�V�[�P���X�ԍ������Z�b�g
		inline void checkAndResetSeqNo()
		{
			if (m_heap.empty())
				m_seqNo = 0;
		}
	private:
		//�G���L���[�i�{�́j
		node_type* _enqueueCopying(const node_type& obj)
		{
			if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type obj_tmp(std::move(obj));
			ope_type::setSeqNo(obj_tmp, getNextSeqNo());//�V�[�P���X�ԍ����Z�b�g
			return m_heap.pushCopying(obj_tmp);//�񕪃q�[�v�Ƀv�b�V��
		}
	public:
		//�G���L���[
		//���I�u�W�F�N�g�n��
		//���I�u�W�F�N�g�ɂ́A���炩���ߗD��x��ݒ肵�Ă����K�v������
		//���I�u�W�F�N�g�̃R�s�[���Q�񔭐�����_�ɒ��Ӂi�����x���Ȃ�j
		//�@�i�V�[�P���X�ԍ����Z�b�g���邽�߂�1��e���|�����ɃR�s�[���A�v�b�V�����ɂ���ɃR�s�[����B�j
		inline node_type* enqueueCopying(const node_type& obj)
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//�֐��I�����Ɏ����I�Ƀ��b�N���
				return _enqueueCopying(obj);
			}
			return _enqueueCopying(obj);
		}
	private:
		//�G���L���[�i�{�́j
		template<typename... Tx>
		node_type* _enqueue(const priority_type priority, Tx... args)
		{
			//if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
			//	return nullptr;
			node_type* obj = m_heap.pushBegin(args...);//�񕪃q�[�v�Ƀv�b�V���J�n
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//�D��x��ݒ�
			ope_type::setSeqNo(*obj, getNextSeqNo());//�V�[�P���X�ԍ����Z�b�g
			obj = m_heap.pushEnd();//�񕪃q�[�v�Ƀv�b�V���I��
			return obj;
		}
	public:
		//�G���L���[
		//���p�����[�^�n��
		//���I�u�W�F�N�g�̃R���X�g���N�^���Ăяo�����
		//���I�u�W�F�N�g�ɂ́A�V�[�P���X�ԍ����������܂��
		template<typename... Tx>
		inline node_type* enqueue(const priority_type priority, Tx... args)
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//�֐��I�����Ɏ����I�Ƀ��b�N���
				return _enqueue(priority, args...);
			}
			return _enqueue(priority, args...);
		}
	private:
		//�G���L���[�J�n�i�{�́j
		template<typename... Tx>
		node_type* _enqueueBegin(const priority_type priority, Tx... args)
		{
			//if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
			//	return nullptr;
			node_type* obj = m_heap.pushBegin(args...);//�񕪃q�[�v�Ƀv�b�V���J�n
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//�D��x��ݒ�
			ope_type::setSeqNo(*obj, getNextSeqNo());//�V�[�P���X�ԍ���ݒ�
			return obj;
		}
	public:
		//�G���L���[�J�n
		//���󂫃L���[�擾
		//���G���L���[�������� enqueueEnd ���Ăяo���K�v����
		//�����̎��_�ŁA�D��x�ƃV�[�P���X�ԍ����������܂��
		template<typename... Tx>
		inline node_type* enqueueBegin(const priority_type priority, Tx... args)
		{
			if (m_autoLockAttr == AUTO_LOCK)
				m_lock.lock();//���b�N���擾�����܂܊֐��𔲂���
			node_type* obj = _enqueueBegin(args...);//�G���L���[�J�n
			if (!obj && m_autoLockAttr == AUTO_LOCK)
					m_lock.unlock();//�v�b�V�����s���̓��b�N���
			return obj;
		}
	private:
		//�G���L���[�I���i�{�́j
		inline node_type* _enqueueEnd()
		{
			return m_heap.pushEnd();//�񕪃q�[�v�Ƀv�b�V���I��
		}
	public:
		//�G���L���[�I��
		inline node_type* enqueueEnd()
		{
			const bool unlock = (m_autoLockAttr == AUTO_LOCK && m_heap.state() == state_t::PUSH_BEGINNING);//�v�b�V���J�n���Ȃ�A�����b�N����
			node_type* new_obj = _enqueueEnd();//�G���L���[�I��
			if (unlock)
				m_lock.unlock();//���b�N���
			return new_obj;
		}
	private:
		//�G���L���[�������i�{�́j
		inline bool _enqueueCancel()
		{
			//if (m_heap.state() != state_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
			//	return;
			return m_heap.pushCancel();//�v�b�V��������
		}
	public:
		//�G���L���[������
		inline bool enqueueCancel()
		{
			const bool unlock = (m_autoLockAttr == AUTO_LOCK && m_heap.state() == state_t::PUSH_BEGINNING);//�v�b�V���J�n���Ȃ�A�����b�N����
			const bool result = m_heap.pushCancel();//�v�b�V��������
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
	private:
		//�f�L���[�i�{�́j
		bool _dequeueCopying(node_type& dst)
		{
			//if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
			//	return nullptr;
			const bool result = m_heap.popCopying(dst);//�񕪃q�[�v����|�b�v
			if (!result)
				return false;
			checkAndResetSeqNo();//�L���[����ɂȂ�����V�[�P���X�ԍ������Z�b�g����
			return true;
		}
	public:
		//�f�L���[
		//���I�u�W�F�N�g�̃R�s�[���󂯎��̈��n��
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo����� ���R�s�[��Ɏ��s
		inline bool dequeueCopying(node_type& dst)
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//�֐��I�����Ɏ����I�Ƀ��b�N���
				return _dequeueCopying(dst);
			}
			return _dequeueCopying(dst);
		}
	private:
		//�f�L���[�J�n�i�{�́j
		//���f�L���[�������� dequeueEnd ���Ăяo���K�v����
		node_type* _dequeueBegin()
		{
			//if (m_heap.state() == state_t::PUSH_BEGINNING || m_heap.state() == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
			//	return nullptr;
			node_type* obj = m_heap.popBegin();//�񕪃q�[�v����|�b�v�J�n
			if (!obj)
				return nullptr;
			return obj;
		}
	public:
		//�f�L���[�J�n
		//���f�L���[�������� dequeueEnd ���Ăяo���K�v����
		inline node_type* dequeueBegin()
		{
			if (m_autoLockAttr == AUTO_LOCK)
				m_lock.lock();//���b�N���擾�����܂܊֐��𔲂���
			node_type* obj = _dequeueBegin();//�f�L���[�J�n
			if (!obj && m_autoLockAttr == AUTO_LOCK)
				m_lock.unlock();//�v�b�V�����s���̓��b�N���
			return obj;
		}
	private:
		//�f�L���[�I���i�{�́j
		bool _dequeueEnd()
		{
			//if (m_heap.state() != state_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
			//	return false;
			const bool result = m_heap.popEnd();//�񕪃q�[�v����|�b�v�I��
			checkAndResetSeqNo();//�L���[����ɂȂ�����V�[�P���X�ԍ������Z�b�g����
			return result;
		}
	public:
		//�f�L���[�I��
		//���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo�����
		inline bool dequeueEnd()
		{
			const bool unlock = (m_autoLockAttr == AUTO_LOCK && m_heap.state() == state_t::POP_BEGINNING);//�|�b�v�J�n���Ȃ�A�����b�N����
			const bool result = _dequeueEnd();//�f�L���[�I��
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
	private:
		//�f�L���[�������i�{�́j
		bool _dequeueCancel()
		{
			//if (m_heap.state() != state_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
			//	return false;
			return m_heap.popCancel();//�|�b�v������
		}
	public:
		//�f�L���[������
		inline bool dequeueCancel()
		{
			const bool unlock = (m_autoLockAttr == AUTO_LOCK && m_heap.state() == state_t::POP_BEGINNING);//�|�b�v�J�n���Ȃ�A�����b�N����
			const bool result = _dequeueCancel();//�f�L���[������
			if (unlock)
				m_lock.unlock();//���b�N���
			return result;
		}
		//�擪�i���j�L���[���Q��
		//���f�L���[���Ȃ�
		inline const node_type* top() const
		{
			return m_heap.ref_top();//�񕪃q�[�v�̐擪�i���j�m�[�h���擾
		}
	private:
		//�擪�i���j�L���[�̃v���C�I���e�B�ύX�i�{�́j
		node_type* _changePriorityOnTop(const priority_type priority)
		{
			node_type* obj = m_heap.ref_top();
			if (!obj)
				return nullptr;
			ope_type::setPrior(*obj, priority);//�D��x���X�V
			ope_type::setSeqNo(*obj, getNextSeqNo());//�V�[�P���X�ԍ����X�V
			return m_heap.downHeap(obj);//�_�E���q�[�v
		}
	public:
		//�擪�i���j�L���[�̃v���C�I���e�B�ύX
		//���v���C�I���e�B��ύX�������_�ŃL���[�̈ʒu������ւ��
		//���V�[�P���X�ԍ����čX�V����
		//�������v���C�I���e�B�ɕύX�����ꍇ�A�����v���C�I���e�B�̃L���[�̈�ԍŌ�ɉ񂳂��
		inline node_type* changePriorityOnTop(const priority_type priority)
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//�֐��I�����Ɏ����I�Ƀ��b�N���
				return _changePriorityOnTop(priority);
			}
			return _changePriorityOnTop(priority);
		}
	private:
		//�N���A�i�{�́j
		inline void _clear()
		{
			m_heap.clear();
		}
	public:
		//�N���A
		inline void clear()
		{
			if (m_autoLockAttr == AUTO_LOCK)
			{
				std::lock_guard<std::mutex> lock(m_lock);//�֐��I�����Ɏ����I�Ƀ��b�N���
				_clear();
			}
			_clear();
		}
	public:
		//�R���X�g���N�^
		//���L�[��r������n��
		container(const auto_lock_attr_t auto_lock_attr = NEVER_LOCK) :
			m_heap(),
			m_seqNo(0),
			m_autoLockAttr(auto_lock_attr),
			m_lock()
		{}
		//�f�X�g���N�^
		~container()
		{
			enqueueCancel();//�G���L���[������
			dequeueCancel();//�f�L���[������
		}
	private:
		//�t�B�[���h
		bin_heap_type m_heap;//�񕪃q�[�v
		int m_dummy;
		seq_type m_seqNo;//�V�[�P���X�ԍ� ��mutable�C���q
		auto_lock_attr_t m_autoLockAttr;//����
		std::mutex m_lock;//�~���[�e�b�N�X
	};
	//--------------------
	//���S�ȃG���L���[�^�f�L���[����N���X
	template<class CON>
	class operation_guard
	{
	public:
		//�^
		typedef CON container_type;//�R���e�i�^
		typedef typename CON::node_type node_type;//�m�[�h�^
		typedef typename CON::state_t state_t;//�X�e�[�g�^
	public:
		//�A�N�Z�b�T
		state_t state() const { return m_state; }//�X�e�[�g���擾
	public:
		//�G���L���[�J�n
		template<typename... Tx>
		node_type* enqueueBegin(const typename CON::priority_type priority, Tx... args)
		{
			if (m_state == state_t::PUSH_BEGINNING || m_state == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.enqueueBegin(priority, args...);//�G���L���[�J�n
			if (node)
				m_state = state_t::PUSH_BEGINNING;//�X�e�[�g�ύX
			return node;
		}
		//�G���L���[�I��
		node_type* enqueueEnd()
		{
			if (m_state != state_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.enqueueEnd();//�G���L���[�I��
			m_state = state_t::PUSH_ENDED;//�X�e�[�g�ύX
			return node;
		}
		//�G���L���[������
		bool enqueueCancel()
		{
			if (m_state != state_t::PUSH_BEGINNING)//�v�b�V���J�n���ȊO�Ȃ珈�����Ȃ�
				return nullptr;
			m_container.enqueueCancel();//�G���L���[������
			m_state = state_t::PUSH_CANCELLED;//�X�e�[�g�ύX
			return true;
		}
		//�f�L���[�J�n
		node_type* dequeueBegin()
		{
			if (m_state == state_t::PUSH_BEGINNING || m_state == state_t::POP_BEGINNING)//�v�b�V���^�|�b�v�J�n���Ȃ珈�����Ȃ�
				return nullptr;
			node_type* node = m_container.dequeueBegin();//�f�L���[�J�n
			if (node)
				m_state = state_t::POP_BEGINNING;//�X�e�[�g�ύX
			return node;
		}
		//�f�L���[�I��
		bool dequeueEnd()
		{
			if (m_state != state_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			const bool result = m_container.dequeueEnd();//�f�L���[�I��
			m_state = state_t::POP_ENDED;//�X�e�[�g�ύX
			return result;
		}
		//�f�L���[������
		bool dequeueCancel()
		{
			if (m_state != state_t::POP_BEGINNING)//�|�b�v�J�n���ȊO�Ȃ珈�����Ȃ�
				return false;
			m_container.dequeueCancel();//�f�L���[������
			m_state = state_t::POP_CANCELLED;//�X�e�[�g�ύX
			return true;
		}
	public:
		//�R���X�g���N�^
		operation_guard(container_type& container) :
			m_container(container),
			m_state(state_t::IDLE)
		{}
		//�f�X�g���N�^
		~operation_guard()
		{
			enqueueEnd();//�G���L���[�I��
			dequeueEnd();//�f�L���[�I��
		}
	private:
		//�t�B�[���h
		container_type& m_container;//�R���e�i
		state_t m_state;//�X�e�[�g
	};
	//--------------------
	//��{�^��`�}�N������
	#undef DECLARE_OPE_TYPES
}//namespace priority_queue

//--------------------------------------------------------------------------------
//�v���C�I���e�B�L���[�e�X�g
//--------------------------------------------------------------------------------

#include <memory.h>//memcpy�p
#include <random>//C++11 std::random�p
#include <algorithm>//std::for_each�p
#include <queue>//std::priority_queue�p����r�e�X�g�p

//----------------------------------------
//�e�X�g�f�[�^
enum PRIORITY : short
{
	HIGHEST = 5,
	HIGHER = 4,
	NORMAL = 3,
	LOWER = 2,
	LOWEST = 1,
};
struct data_t
{
	PRIORITY m_priority;//�D��x
	int m_seqNo;//�V�[�P���X�ԍ�
	int m_val;//�f�[�^

	//�R���X�g���N�^
	data_t(const PRIORITY priority, const int val) :
		m_priority(priority),
		m_seqNo(0),
		m_val(val)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d, %d)\n", priority, val);
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	data_t(const int val) :
		m_priority(NORMAL),
		m_seqNo(0),
		m_val(val)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor(%d)\n", val);
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
#ifdef TEST_DATA_WATCH_CONSTRUCTOR
	//���[�u�I�y���[�^
	data_t& operator=(const data_t&& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::move_operator\n");
		return *this;
	}
	//�R�s�[�I�y���[�^
	data_t& operator=(const data_t& rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
		printf("data_t::copy_operator\n");
		return *this;
	}
	//���[�u�R���X�g���N�^
	data_t(const data_t&& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::move_constructor\n");
	}
	//�R�s�[�R���X�g���N�^
	data_t(const data_t& src)
	{
		memcpy(this, &src, sizeof(*this));
		printf("data_t::copy_constructor\n");
	}
#endif//TEST_DATA_WATCH_CONSTRUCTOR
	//�f�t�H���g�R���X�g���N�^
	data_t() :
		m_priority(NORMAL),
		m_seqNo(0),
		m_val(0)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::constructor\n");
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
	//�f�X�g���N�^
	~data_t()
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("data_t::destructor\n");
		//printf("    m_priority=%d, m_seqNo=%d, m_val=%d\n", m_priority, m_seqNo, m_val);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
	}
};
//----------------------------------------
//�e�X�g�f�[�^����N���X
struct ope_t : public priority_queue::base_ope_t<ope_t, data_t, PRIORITY, int>
{
	//�D��x���擾
	inline static priority_type getPrior(const node_type& node){ return node.m_priority; }
	//�D��x���X�V
	inline static void setPrior(node_type& node, const priority_type priority){ node.m_priority = priority; }
	
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
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//�v���C�I���e�B�L���[�R���e�i����
	typedef priority_queue::container<ope_t, TEST_DATA_MAX> container_type;
	typedef container_type::bin_heap_type bin_heap_type;
	container_type con(priority_queue::AUTO_LOCK);

	//--------------------
	//�v���C�I���e�B�L���[�̃e�X�g
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)]\n");
	printf("\n");

	//�G���L���[
	auto enqueue = [&con]()
	{
		printf("--- Enqueue ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj = con.enqueue(NORMAL, 0);
			printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			#define USE_ENQUEUE_TYPE 2
			//�y�G���L���[���@�@�z�I�u�W�F�N�g���󂯓n�����@
			//���I�u�W�F�N�g�̃R�s�[����������̂ŏ����x���B
			#if USE_ENQUEUE_TYPE == 1
			{
				data_t new_obj(priority, val);
				data_t* obj = con.enqueueCopying(new_obj);
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//�y�����z�y�G���L���[���@�A�z�R���X�g���N�^�p�����[�^��n���ēo�^������@
			//���I�u�W�F�N�g�̃R�s�[�͔������Ȃ��B
			//���R���X�g���N�^���Ăяo�����B
			#elif USE_ENQUEUE_TYPE == 2
			{
				data_t* obj = con.enqueue(priority, val);//�D��x�ƃR���X�g���N�^�p�����[�^��n���ēo�^
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
			}
			//�y�G���L���[���@�B�z�V�K�L���[�i�I�u�W�F�N�g�j�̎Q�Ƃ��󂯎���Ēl���Z�b�g������@
			//���I�u�W�F�N�g�̃R�s�[�͔������Ȃ��B
			//���ŏ��ɃR���X�g���N�^���Ăяo�����B
			//�������I�ɏI���������Ăяo���A���b�N��������Ȃ���΂Ȃ�Ȃ��_�ɒ��ӁB
			//�@�i�G���L���[�^�f�L���[����p�N���X���g�p���邱�ƂŁA�����u���b�N�𔲂��鎞�Ɏ����G�Ƀ��b�N����������j
			//���G���L���[�I�����ɂ̓|�C���^���ς��_�ɂ����ӁB
			#elif USE_ENQUEUE_TYPE == 3
			{
				priority_queue::operation_guard<container_type> ope(con);//�G���L���[�^�f�L���[����p�N���X
				data_t* obj = ope.enqueueBegin(priority);//���̎��_�ŗD��x�ƃV�[�P���X�ԍ����Z�b�g����A���b�N���擾�����
				                                         //���Ԃ�l�́A�����u���b�N���ł����ienqueueEnd/enqueueCancel�Ăяo���܂ł����j�L���ł͂Ȃ��|�C���^�Ȃ̂Œ���
				obj->m_val = val;
				printf_detail("[%d:%2d(seq=%d)]\n", obj->m_priority, obj->m_val, obj->m_seqNo);
				//�����u���b�N�𔲂��鎞�Ɏ����I�Ƀf�L���[���I�����A���b�N����������B
				//���󂯎�����|�C���^�������u���b�N�̊O�ŎQ�Ƃ���ƁA����������Q�Ƃ��邱�ƂɂȂ�̂Œ��ӁB
				//�������I�ɃG���L���[�I���^�����������s���邱�Ƃ��\�B
				//obj = ope.enqueueEnd();//�����I�ȃG���L���[�I�����s���ƁA�������I�u�W�F�N�g�̎Q�Ƃ��擾�ł���
				//ope.enqueueCancel();
			}
			#endif//USE_ENQUEUE_TYPE
		}
		printf_detail("\n");
	};
	enqueue();

#if 0
	//�͈͂Ɋ�Â�for���[�v�e�X�g
	auto printNodesTest1 = [&con]()
	{
		printf("--- Test for C++11 for(:) ---\n");
		for (const data_t& o : con)
			printf("[%1d:%2d] ", o.m_priority, o.m_val);
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
				printf("[%1d:%2d] ", o.m_priority, o.m_val);
			}
		);
		printf("\n");
	};
	printNodesTest2();
#endif

	//�؂�\��
	auto showTree = [](const bin_heap_type& heap)
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
					printf("%s%1d:%2d%s", heap.ref_child_l(node) ? "{" : "[", node->m_priority, node->m_val, heap.ref_child_r(node) ? "}" : "]");
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

	//�f�L���[
	auto dequeue = [&con](const int pop_limit)
	{
		printf("--- Dequeue ---\n");
		for (int i = 0; i < pop_limit; ++i)
		{
			#define USE_DEQUEUE_TYPE 2
			//�y�f�L���[���@�@�z���擾�p�̃I�u�W�F�N�g���󂯓n��
			//���I�u�W�F�N�g�̃R�s�[����������B
			//���f�X�g���N�^���Ăяo�����B�i�R�s�[��Ɏ��s�j
			#if USE_DEQUEUE_TYPE == 1
			{
				data_t node;
				const bool result = con.dequeueCopying(node);
				if (!result)
					break;
				printf("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//�y�����z�y�f�L���[���@�A�z�L���[�i�I�u�W�F�N�g�j�̎Q�Ƃ��󂯎����@
			//���I�u�W�F�N�g�̃R�s�[�͔������Ȃ��B
			//�������I�ɏI���������Ăяo���A���b�N��������Ȃ���΂Ȃ�Ȃ��_�ɒ��ӁB
			//�@�i�G���L���[�^�f�L���[����p�N���X���g�p���邱�ƂŁA�����u���b�N�𔲂��鎞�Ɏ����G�Ƀ��b�N����������j
			//���Ō�Ƀf�X�g���N�^���Ăяo�����B
			#elif USE_DEQUEUE_TYPE == 2
			{
				priority_queue::operation_guard<container_type> ope(con);//�G���L���[�^�f�L���[����p�N���X
				data_t* obj = ope.dequeueBegin();//���̎��_�Ń��b�N���擾�����
				                                 //���Ԃ�l�́A�����u���b�N���ł����idequeueEnd/dequeueCancel�Ăяo���܂ł����j�L���ł͂Ȃ��|�C���^�Ȃ̂Œ���
				if (!obj)
					break;
				printf("[%1d:%2d] ", obj->m_priority, obj->m_val);
				//�����u���b�N�𔲂��鎞�Ɏ����I�Ƀf�L���[���I�����A���b�N����������B
				//���󂯎�����|�C���^�������u���b�N�̊O�ŎQ�Ƃ���ƁA����������Q�Ƃ��邱�ƂɂȂ�̂Œ��ӁB
				//�������I�Ƀf�L���[�I���^�����������s���邱�Ƃ��\�B
				//ope.dequeueEnd();
				//ope.dequeueCancel();
			}
			#endif//USE_DEQUEUE_TYPE
		}
		printf("\n");
	};
	dequeue(3);
	showTree(con);//�؂�\��

	//�擪�i���j�m�[�h�̗D��x��ύX
	auto changePriorityOnTop = [&con](const PRIORITY new_priority)
	{
		printf("--- Change Priority ---\n");
		const data_t* node = con.top();//�擪�m�[�h���擾�i�|�b�v����Ȃ��j
		printf("[%1d:%2d(seq=%d)]", node->m_priority, node->m_val, node->m_seqNo);
		node = con.changePriorityOnTop(new_priority);//�D��x��ύX�i�ύX��A�L���[���Ĕz�u�����j
		printf(" -> [%1d:%2d(seq=%d)]\n", node->m_priority, node->m_val, node->m_seqNo);
	};
	changePriorityOnTop(HIGHEST);
	changePriorityOnTop(LOWER);
	changePriorityOnTop(HIGHER);
	showTree(con);//�؂�\��
	
	//�f�L���[
	dequeue(TEST_DATA_REG_NUM / 2);
	showTree(con);//�؂�\��

	//�f�L���[
	dequeue(TEST_DATA_REG_NUM);
	showTree(con);//�؂�\��

	//--------------------
	//�y������r�p�z�񕪃q�[�v�̃e�X�g
	//���v���C�I���e�B�L���[�ƈقȂ�A�|�b�v���ɁA�v�b�V�����i�G���L���[���j�̏��������ۏ؂���Ă��Ȃ����Ƃ��m�F�ł���
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for bin_heap::container(Binary Heap)]\n");
	printf("\n");

	bin_heap_type heap;

	//�񕪃q�[�v�Ńm�[�h���v�b�V��
	auto pushNodesBinHeap = [&heap]()
	{
		printf("--- Push nodes(Binary Heap) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t* obj =heap.push(NORMAL, 0);
			printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			//����L�v���C�I���e�B�L���[�Ő��������A�R��ނ̃v�b�V�����@���g����
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			#define USE_PUSH_TYPE 2
			//�y�v�b�V�����@�@�z
			#if USE_PUSH_TYPE == 1
			{
				data_t new_obj(priority, val);
				data_t* obj = heap.pushCopying(new_obj);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//�y�����z�y�v�b�V�����@�A�z
			#elif USE_PUSH_TYPE == 2
			{
				data_t* obj = heap.push(priority, val);
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
			}
			//�y�v�b�V�����@�B�z
			#elif USE_PUSH_TYPE == 3
			{
				bin_heap::operation_guard<bin_heap_type> ope(heap);
				data_t* obj = ope.pushBegin(priority, val);//���Ԃ�l�́A�����u���b�N���ł����ipushEnd/pushCancel�Ăяo���܂ł����j�L���ł͂Ȃ��|�C���^�Ȃ̂Œ���
				printf_detail("[%d:%2d]\n", obj->m_priority, obj->m_val);
				//obj = ope.popEnd();//�����I�ȃ|�b�v�I�����s���ƁA�������I�u�W�F�N�g�̎Q�Ƃ��擾�ł���
			}
			#endif//USE_PUSH_TYPE
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
			//����L�v���C�I���e�B�L���[�Ő��������A�Q��ނ̃|�b�v���@���g����
			#define USE_POP_TYPE 2
			//�y�|�b�v���@�@�z
			#if USE_POP_TYPE == 1
			{
				data_t node;
				const bool result = heap.popCopying(node);
				if (!result)
					break;
				printf("[%1d:%2d] ", node.m_priority, node.m_val);
			}
			//�y�����z�y�|�b�v���@�A�z
			#elif USE_POP_TYPE == 2
			{
				bin_heap::operation_guard<bin_heap_type> ope(heap);
				data_t* obj = ope.popBegin();//���Ԃ�l�́A�����u���b�N���ł����ipopEnd/popCancel�Ăяo���܂ł����j�L���ł͂Ȃ��|�C���^�Ȃ̂Œ���
				if (!obj)
					break;
				printf("[%1d:%2d] ", obj->m_priority, obj->m_val);
			}
			#endif//USE_POP_TYPE
		}
		printf("\n");
	};
	popNodesBinHeap(TEST_DATA_REG_NUM / 2);
	showTree(heap);//�؂�\��

	//�m�[�h���|�b�v
	popNodesBinHeap(TEST_DATA_REG_NUM);
	showTree(heap);//�؂�\��

	//--------------------
	//�y������r�p�zSTL��std::priority_queue�e�X�g
	//���v���C�I���e�B�L���[�ƈقȂ�A�|�b�v���ɁA�v�b�V�����i�G���L���[���j�̏��������ۏ؂���Ă��Ȃ����Ƃ��m�F�ł���
	//��STL�Ɠ񕪃q�[�v�̋����i�|�b�v�����j���S���������Ƃ��m�F�ł���
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for std::priority_queue(STL)]\n");
	printf("\n");
	
	std::priority_queue<data_t, std::vector<data_t>, ope_t> stl;

	//STL�Ńm�[�h���v�b�V��
	auto pushNodesSTL = [&stl]()
	{
		printf("--- Push nodes(STL) ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(TEST_DATA_PRIOR_MIN, TEST_DATA_PRIOR_MAX);
		{
			data_t obj(NORMAL, 0);
			stl.push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
		}
		for (int val = 1; val < TEST_DATA_REG_NUM; ++val)
		{
			const PRIORITY priority = static_cast<PRIORITY>(rand_dist(rand_engine));
			data_t obj(priority, val);
			stl.push(obj);
			printf_detail("[%d:%2d]\n", obj.m_priority, obj.m_val);
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
			printf("[%1d:%2d] ", node.m_priority, node.m_val);
			stl.pop();
		}
		printf("\n");
	};
	popNodesSTL(TEST_DATA_REG_NUM / 2);
	popNodesSTL(TEST_DATA_REG_NUM);

	//--------------------
	//�y������r�p�z�v���C�I���e�B�L���[�̍ăe�X�g
	//����L�̓񕪃q�[�v�^STL�̃e�X�g�Ɠ���̗���̃e�X�g�����{
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)] *Second time\n");
	printf("\n");

	enqueue();//�G���L���[
	showTree(con);//�؂�\��
	dequeue(TEST_DATA_REG_NUM / 2);//�f�L���[
	showTree(con);//�؂�\��
	dequeue(TEST_DATA_REG_NUM);//�f�L���[
	showTree(con);//�؂�\��

	//--------------------
	//�v���C�I���e�B�L���[�̃N���A�̃e�X�g
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[Test for priority_queue::container(Priority Queue)] *Clear\n");
	printf("\n");

	enqueue();//�G���L���[
	showTree(con);//�؂�\��
	printf("--- Clear ---\n");
	con.clear();//�N���A
	printf("OK\n");
	showTree(con);//�؂�\��

	//--------------------
	//�|�C���^�ϐ����L���[�C���O����ꍇ�̃e�X�g
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("[Test for priority_queue::container(Priority Queue)] *Pointer\n");
		
		//����^
		struct p_ope_t : public priority_queue::base_ope_t<p_ope_t, data_t*, PRIORITY, int>
		{
			inline static priority_type getPrior(const node_type& node){ return node->m_priority; }
			inline static void setPrior(node_type& node, const priority_type priority){ node->m_priority = priority; }
			inline static seq_type getSeqNo(const node_type& node){ return node->m_seqNo; }
			inline static void setSeqNo(node_type& node, const seq_type seq_no){ node->m_seqNo = seq_no; }
		};
		
		//�v���C�I���e�B�L���[
		priority_queue::container<p_ope_t, TEST_DATA_MAX> p_con;
		
		//�G���L���[
		data_t obj1(NORMAL, 1);
		data_t obj2(HIGHER, 2);
		data_t obj3(LOWER, 3);
		data_t obj4(HIGHEST, 4);
		data_t obj5(LOWEST, 5);
		p_con.enqueueCopying(&obj1);
		p_con.enqueueCopying(&obj2);
		p_con.enqueueCopying(&obj3);
		p_con.enqueueCopying(&obj4);
		p_con.enqueueCopying(&obj5);

		//�f�L���[
		auto dequeuObj = [&p_con]()
		{
			data_t* obj_p = nullptr;
			p_con.dequeueCopying(obj_p);
			printf("pop: [%1d:%2d](seq=%d)\n", obj_p->m_priority, obj_p->m_val, obj_p->m_seqNo);
		};
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
		dequeuObj();
	}

	return EXIT_SUCCESS;
}

// End of file
