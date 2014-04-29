//--------------------------------------------------------------------------------
//�n�b�V���e�[�u���e�X�g�p�ݒ�ƃR���p�C���X�C�b�`
static const int TABLE_SIZE = 20;//�e�[�u���T�C�Y

#include <stdio.h>
#include <stdlib.h>

//#define FOR_UNIX//UNIX�łŃR���p�C������Ƃ��́A���̃}�N����L��������
#ifdef FOR_UNIX
#include "../StaticCRC32_unix/constexpr.h"
#else//FOR_UNIX
#include "../../StaticCRC32/StaticCRC32/src/constexpr/constexpr.h"
#endif//FOR_UNIX

#include <bitset>//std::bitset�p
#include <cstddef>//srd::size_t�p
#include <iterator>//std::iterator�p
#include <utility>//std::move�p

//--------------------------------------------------------------------------------
//�f���v�Z
//--------------------------------------------------------------------------------

//----------------------------------------
//�y�����^�C���Łz
//----------------------------------------

//----------------------------------------
//�y�����^�C���Łz�f������
bool isPrime(const std::size_t n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if ((n & 0x1) == 0x0)//��������
		return false;
	for (std::size_t div = 3; div <= n / div; div += 2)
	{
		if (n % div == 0)
			return false;
	}
	return true;
}
//----------------------------------------
//�y�����^�C���Łz�O�̑f���𐶐�
std::size_t makePrimePrev(const std::size_t n)
{
	if (n <= 2)
		return 0;
	else if (n == 3)
		return 2;
	for (std::size_t nn = n - ((n & 0x1) == 0x0 ? 1 : 2);; nn -= 2)//�������͔��肵�Ȃ�
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//----------------------------------------
//�y�����^�C���Łz���̑f���𐶐�
std::size_t makePrimeNext(const std::size_t n)
{
	if (n < 2)
		return 2;
	for (std::size_t nn = n + ((n & 0x1) == 0x0 ? 1 : 2);; nn += 2)//�������͔��肵�Ȃ�
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//----------------------------------------
//�y�����^�C���Łz�w��̒l�Ɠ������A�O�̑f���𐶐�
std::size_t makePrimeEqPrev(const std::size_t n)
{
	return isPrime(n) ? n : makePrimePrev(n);
}
//----------------------------------------
//�y�����^�C���Łz�w��̒l�Ɠ������A���̑f���𐶐�
std::size_t makePrimeEqNext(const std::size_t n)
{
	return isPrime(n) ? n : makePrimeNext(n);
}

//----------------------------------------
//�y���^�v���O���~���O�Łz
//----------------------------------------
//�y���Ӂz
// ���^�v���O���~���O�łł́A�R���p�C���ɉ����ăe���v���[�g�̍ċA���x���̌��E������B
// ���̂��߁A���� 100001 ���炢�܂ł̑f�����������Ȃ��_�ɒ��ӁB
// ���̃e���v���[�g���Ŏg���ƁA�����Ɛ�����󂯂�_�ɂ����ӁB
// �܂��A�R���p�C�����Ԃɉe��������_�ɂ����ӁB
//----------------------------------------

//----------------------------------------
//�y���^�v���O���~���O�ŁF���ʏ����z�Œ�l��Ԃ��N���X
template<typename T, T V>
struct _primeMeta_Fixed{//�Œ�l(V)�̂��߂̃N���X �����Z�N���X�̌��ʂ𓾂�Ƃ��ƈ�l�̗p�@�iclass_name::value�j���K�v�Ȃ���
	static const T value = V;
};

//----------------------------------------
//�y���^�v���O���~���O�ŁF���ʏ����z�O�����Z�q����ɏ�������Ɋ�Â��Ēl��Ԃ��N���X
template <typename T, bool COND, class TRUE_VALUE, class FALSE_VALUE>
struct _primeMeta_EnalbeIf{
	static const T value = FALSE_VALUE::value;
};
template <typename T, class TRUE_VALUE, class FALSE_VALUE>//�����茋�ʂ�true�̎��p�̓��ꉻ
struct _primeMeta_EnalbeIf<T, true, TRUE_VALUE, FALSE_VALUE>{
	static const T value = TRUE_VALUE::value;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz�f������
//�������̔��������邽�߂ɊK�w������
template <std::size_t N, std::size_t DIV>//�ċA�N���X
struct _isPrimeMeta{
	static const bool value =
			_primeMeta_EnalbeIf<bool, (DIV > N / DIV),
				_primeMeta_Fixed<bool, true>,
				_primeMeta_EnalbeIf<bool, (N % DIV == 0),
					_primeMeta_Fixed<bool, false>,
					_isPrimeMeta<N, DIV + 2>
			>
		>::value;
};
template <std::size_t N>//�f������N���X
struct isPrimeMeta{
	static const bool value =
		_primeMeta_EnalbeIf<bool, (N & 0x1) == 0x0,
			_primeMeta_Fixed<bool, false>,
			_isPrimeMeta<N, 3>
		>::value;
};
template <>
struct isPrimeMeta<0>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<1>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<2>{
	static const bool value = true;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz�O�̑f���𐶐�
//�������̔��������邽�߂ɊK�w������
template<std::size_t N>//�ċA�N���X
struct _makePrimePrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			_makePrimePrevMeta<N - 2>
		>::value;
};
template<std::size_t N>//�O�̑f�������N���X
struct makePrimePrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, (N & 0x1) == 0x0,
			_makePrimePrevMeta<N - 1>,
			_makePrimePrevMeta<N - 2>
		>::value;
};
template<>
struct makePrimePrevMeta<0>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<1>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<2>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<3>{
	static const std::size_t value = 2;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz���̑f���𐶐�
//�������̔��������邽�߂ɊK�w������
template<std::size_t N>//�ċA�N���X
struct _makePrimeNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			_makePrimeNextMeta<N + 2>
		>::value;
};
template<std::size_t N>//���̑f�������N���X
struct makePrimeNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, (N & 0x1) == 0x0,
			_makePrimeNextMeta<N + 1>,
			_makePrimeNextMeta<N + 2>
		>::value;
};
template<>
struct makePrimeNextMeta<0>{
	static const std::size_t value = 2;
};
template<>
struct makePrimeNextMeta<1>{
	static const std::size_t value = 2;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz�w��̒l�Ɠ������A�O�̑f���𐶐�
template<std::size_t N>
struct makePrimeEqPrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			makePrimePrevMeta<N>
		>::value;
};

//----------------------------------------
//�y���^�v���O���~���O�Łz�w��̒l�Ɠ������A���̑f���𐶐�
template<std::size_t N>
struct makePrimeEqNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			makePrimeNextMeta<N>
		>::value;
};

//--------------------------------------------------------------------------------
//�n�b�V���e�[�u��
//--------------------------------------------------------------------------------
//�f�[�^�\���ƃA���S���Y��
//�y�����z
//�E�_�u���n�b�V���A���S���Y�����̗p�B
//�@  - �n�b�V���@ ... �ŏ��̃C���f�b�N�X�B�L�[�ɉ����Đ����B
//�@  - �n�b�V���A ... �Փ˂̍ۂ̃C���f�b�N�X�̕����B�L�[�ɉ����Đ����B
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//�y�{�v���O�����ɂ���������v���z
//�E�Œ�z��Ŏ������A��؃������m�ہE�폜�����Ȃ��B
//�E�L�[�d�������e���Ȃ��A���S���Y���Ƃ���B
//�E������istd::string/char*�j�̃L�[���T�|�[�g���Ȃ��B
//�@����ɁA������L�[�͎����I��crc32�ϊ����s���A������͕ێ����Ȃ��B
//�E�����������̂��߂ɁA�f�[�^�̍폜���͎��ۂɍ폜�����A
//�@�폜�ς݃t���O��p������̂Ƃ���B
//�@�����������́A�폜�ς݂̃f�[�^�����o���Ă����s����B
//�ESTL�istd::unodered_map�j�Ƃ̈Ⴂ�͉��L�̒ʂ�
//    - �Œ蒷�z��ł���B�iSTL�͎����g������j
//    - �L�[�ƒl�̃y�A�ň���Ȃ��B
//�@�@- insert/erase���̃C�e���[�^�ɑΉ����Ȃ��B
//    - �ԍ��؃R���e�i�irb_tree�j�̎����ƍ��킹���\���ɂ��Ă���A
//�@�@  ����p�e���v���[�g�\���̂�p����B
//--------------------------------------------------------------------------------

namespace hash_table
{
	//--------------------
	//�n�b�V���e�[�u���f�[�^����p�e���v���[�g�\����
	//��CRTP�����p���A���L�̂悤�Ȕh���\���̂��쐬���Ďg�p����
	//  //template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	//  //struct base_ope_t;
	//  //struct �h���\���̖� : public hash_table::base_ope_t<�h���\����, �L�[�^, �l�^, �L�[�̍ŏ��l= 0u, �L�[�̍ő�l = 0xffffffffu, �s���ȃL�[ = 0xffffffffu>
	//	struct ope_t : public hash_table::ope_t<ope_t, crc32_t, data_t, 500>
	//	{
	//		//�L�[���擾
	//		inline static key_type getKey(const value_type& value){ return ???; }
	//	};
	template<class OPE_TYPE, typename KEY_TYPE, typename VALUE_TYPE, KEY_TYPE _KEY_MIN = 0u, KEY_TYPE _KEY_MAX = 0xffffffffu, KEY_TYPE _INVALID_KEY = 0xffffffffu>
	struct base_ope_t
	{
		//�萔
		static const KEY_TYPE KEY_MIN = _KEY_MIN;//�L�[�̍ŏ��l
		static const KEY_TYPE KEY_MAX = _KEY_MAX;//�L�[�̍ő�l
		static const KEY_TYPE INVALID_KEY = _INVALID_KEY;//�s���ȃL�[

		//�^
		typedef OPE_TYPE ope_type;//�f�[�^����^
		typedef VALUE_TYPE value_type;//�l�^
		typedef KEY_TYPE key_type;//�L�[�^

		//���\�b�h
		static void call_destructor(value_type* obj){ obj->~VALUE_TYPE(); }//�f�X�g���N�^�Ăяo��
	};
	//--------------------
	//��{�^��`�}�N��
#define DECLARE_OPE_TYPES(OPE_TYPE) \
	typedef OPE_TYPE ope_type; \
	typedef typename ope_type::value_type value_type; \
	typedef typename ope_type::key_type key_type; \
	typedef value_type& reference; \
	typedef const value_type& const_reference; \
	typedef value_type* pointer; \
	typedef const value_type* const_pointer; \
	typedef std::size_t size_type; \
	typedef std::size_t index_type;
	//----------------------------------------
	//�f�o�b�O�p�⏕�֐�
#ifdef DEBUG_PRINT_FOR_ADD
	template<typename... Tx>
	inline int printf_dbg_add(const char* fmt, Tx... args)
	{
		return printf(fmt, args...);
	}
#else//DEBUG_PRINT_FOR_ADD
	inline int printf_dbg_add(const char* fmt, ...){ return 0; }
#endif//DEBUG_PRINT_FOR_ADD
#ifdef DEBUG_PRINT_FOR_REMOVE
	template<typename... Tx>
	inline int printf_dbg_remove(const char* fmt, Tx... args)
	{
		return printf(fmt, args...);
	}
#else//DEBUG_PRINT_FOR_REMOVE
	inline int printf_dbg_remove(const char* fmt, ...){ return 0; }
#endif//DEBUG_PRINT_FOR_REMOVE

	//----------------------------------------
	//�n�b�V���e�[�u���R���e�i
	template<class OPE_TYPE, std::size_t _TABLE_SIZE, std::size_t _INDEX_STEP_BASE = 5>
	class container
	{
	public:
		//�^
		DECLARE_OPE_TYPES(OPE_TYPE);
	public:
		//�萔
		static const size_type ORIGINAL_TABLE_SIZE = _TABLE_SIZE;//�e�[�u���T�C�Y�i���X�w�肳�ꂽ�T�C�Y�j
		static const size_type TABLE_SIZE = makePrimeEqNextMeta<ORIGINAL_TABLE_SIZE>::value;//�e�[�u���T�C�Y�i�w��T�C�Y�Ɠ������A������傫���f���j
		static const size_type TABLE_SIZE_OVERED = TABLE_SIZE - ORIGINAL_TABLE_SIZE;//�w��T�C�Y����I�[�o�[�����T�C�Y
		static const key_type KEY_MIN = ope_type::KEY_MIN;//�L�[�̍ŏ��l
		static const key_type KEY_MAX = ope_type::KEY_MAX;//�L�[�̍ő�l
		static const index_type INDEX_STEP_BASE = _INDEX_STEP_BASE;//�C���f�b�N�X�̕����̊�l ���K���f���łȂ���΂Ȃ�Ȃ�
		static const index_type INVALID_INDEX = 0xffffffffu;//�����ȃC���f�b�N�X
	public:
		//���^�֐�
		//�L�[�͈͒萔�v�Z�i�Q�o���G�[�V�����j
		template <bool COND, typename size_type, typename key_type, key_type KEY_MIN, key_type KEY_MAX>
		struct calcKeyRangeImpl{
			static const key_type value = KEY_MAX - KEY_MIN + 1;
		};
		template <typename size_type, typename key_type, key_type KEY_MIN, key_type KEY_MAX>
		struct calcKeyRangeImpl<true, size_type, key_type, KEY_MIN, KEY_MAX>{
			static const key_type value = 0;
		};
		//�C���f�b�N�X�v�Z�֐��i�Q�o���G�[�V�����j
		template <bool COND, typename size_type, typename index_type, typename key_type, size_type TABLE_SIZE, key_type KEY_MIN, key_type KEY_RANGE>
		struct calcIndexImpl{
			inline static index_type calc(const key_type key){ return (key - KEY_MIN) % TABLE_SIZE; }//�L�[����C���f�b�N�X���v�Z ���L�[�͈̔͂��e�[�u���T�C�Y���傫���ꍇ
		};
		template <typename size_type, typename index_type, typename key_type, size_type TABLE_SIZE, key_type KEY_MIN, key_type KEY_RANGE>
		struct calcIndexImpl<true, size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE>{
			inline static index_type calc(const key_type key){ return (key - KEY_MIN) * (TABLE_SIZE / KEY_RANGE) % TABLE_SIZE; }//�L�[����C���f�b�N�X���v�Z ���L�[�͈̔͂��e�[�u���T�C�Y�ȉ��̏ꍇ
		};
	public:
		//�萔
		static const key_type KEY_RANGE = calcKeyRangeImpl<((KEY_MIN == 0u && KEY_MAX == 0xffffffffu) || KEY_MIN >= KEY_MAX), size_type, key_type, KEY_MIN, KEY_MAX>::value;//�L�[�͈̔�
		//�ÓI�A�T�[�V����
		static_assert(TABLE_SIZE > INDEX_STEP_BASE, "hash_table::container: TABLE_SIZE is required larger than INDEX_STEP_BASE.");
		static_assert(isPrimeMeta<INDEX_STEP_BASE>::value == true, "hash_table::container: INDEX_STEP_BASE is required prime.");
	public:
		//--------------------
		//�C�e���[�^
		class iterator;
		typedef const iterator const_iterator;
		class iterator : public std::iterator<std::forward_iterator_tag, value_type>
		{
			friend class container;
		public:
			//�^
			struct set
			{
				//�t�B�[���h
				index_type index;//�C���f�b�N�X
				key_type key;//���݂̃L�[
				value_type* value;//���݂̒l
				bool is_deleted;//�폜�ς�
				
				//�I�y���[�^
				inline const value_type& operator*() const { return value; }
				inline value_type& operator*(){ return value; }
				inline const value_type* operator->() const { return value; }
				inline value_type* operator->(){ return value; }

				//���\�b�h
				void update(const index_type _index, const key_type _key, const value_type* _value, const bool _is_deleted)
				{
					index = _index;
					key = _key;
					value = const_cast<value_type*>(_value);
					is_deleted = _is_deleted;
				}

				//�R�X�g���N�^
				set(const index_type _index, const key_type _key, const value_type* _value, const bool _is_deleted):
					index(_index),
					key(_key),
					value(const_cast<value_type*>(_value)),
					is_deleted(_is_deleted)
				{}
			};
		public:
			//�L���X�g�I�y���[�^
			inline operator const set() const { return *m_set; }
			inline operator set&(){ return *m_set; }
			inline operator const value_type() const { return *m_set.value; }
			inline operator value_type&(){ return *m_set.value; }
			inline operator key_type() const { return m_set.key; }
		public:
			//�I�y���[�^
			inline const set& operator*() const { return m_set; }
			inline set& operator*(){ return m_set; }
			inline const value_type* operator->() const { return m_set.value; }
			inline value_type* operator->(){ return m_set.value; }
			//��r�I�y���[�^
			inline bool operator==(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX && rhs.m_set.index == INVALID_INDEX ? true :
				       m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index == rhs.m_set.index;
			}
			inline bool operator!=(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX && rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? true :
				       m_set.index != rhs.m_set.index;
			}
			inline bool operator>(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index > rhs.m_set.index;
			}
			inline bool operator>=(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index >= rhs.m_set.index;
			}
			inline bool operator<(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index < rhs.m_set.index;
			}
			inline bool operator<=(const_iterator& rhs) const
			{
				return m_set.index == INVALID_INDEX || rhs.m_set.index == INVALID_INDEX ? false :
				       m_set.index <= rhs.m_set.index;
			}
			//���Z�I�y���[�^
			inline const_iterator& operator++() const
			{
				setSet(m_con.getNextIndex(m_set.index));
				return *this;
			}
			inline const_iterator& operator--() const
			{
				setSet(m_con.getPrevIndex(m_set.index));
				return *this;
			}
			inline iterator& operator++()
			{
				setSet(m_con.getNextIndex(m_set.index));
				return *this;
			}
			inline iterator& operator--()
			{
				setSet(m_con.getPrevIndex(m_set.index));
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
			//���[�u�I�y���[�^
			iterator& operator=(const_iterator&& rhs)
			{
				m_set = rhs.m_set;
				return *this;
			}
			//�R�s�[�I�y���[�^
			inline iterator& operator=(const_iterator& rhs)
			{
				return operator=(std::move(rhs));
			}
		private:
			//���\�b�h
			void setSet(const index_type index) const
			{
				if (index == INVALID_INDEX)
					m_set.update(INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
				else
					m_set.update(index, m_con.m_keyTable[index], reinterpret_cast<const value_type*>(m_con.m_table[index]), m_con.m_deleted[index]);
			}
		public:
			//���[�u�R���X�g���N�^
			iterator(const_iterator&& obj) :
				m_con(obj.m_con),
				m_set(obj.m_set)
			{}
			//�R�s�[�R���X�g���N�^
			inline iterator(const_iterator& obj) :
				iterator(std::move(obj))
			{}
			//�R���X�g���N�^
			iterator(const container& con) :
				m_con(con),
				m_set(0, nullptr, false)
			{}
			iterator(const container& con, const index_type index, const key_type key, const value_type* value, const bool is_deleted) :
				m_con(con),
				m_set(index, key, value, is_deleted)
			{}
			//�f�X�g���N�^
			inline ~iterator()
			{}
		protected:
			//�t�B�[���h
			const container& m_con;//�R���e�i
			mutable set m_set;//���݂̃L�[/�l/�폜�ς݃t���O
		};
	public:
		//�A�N�Z�b�T
		inline size_type getOriginalTableSize() const { return ORIGINAL_TABLE_SIZE; }//�w�肳�ꂽ�e�[�u���T�C�Y���擾
		inline size_type getTableSize() const { return TABLE_SIZE; }//�i���ۂ́j�e�[�u���T�C�Y���擾
		inline size_type getTableSizeOvered() const { return TABLE_SIZE_OVERED; }//�w��̃e�[�u���T�C�Y����̑������擾
		inline key_type getKeyMin() const { return KEY_MIN; }//�L�[�̍ŏ��l���擾
		inline key_type getKeyMax() const { return KEY_MAX; }//�L�[�̍ő�l���擾
		inline key_type getKeyRange() const { return KEY_RANGE; }//�L�[�͈̔͂��擾
		inline int getUsingCount() const { return m_usingCount; }//�g�p���f�[�^�����擾
		inline int getDeletedCount() const { return m_deletedCount; }//�폜�ς݃f�[�^�����擾
		inline int getMaxFindCycle() const { return m_maxFindCycle; }//�������̍ő叄��񐔂��擾
		value_type& at(const key_type key){ return *findValue(key); }
		value_type& at(const char* key){ return *findValue(key); }
		value_type& at(const value_type& value){ return *findValue(value); }
		const value_type& at(const key_type key) const { return *findValue(key); }
		const value_type& at(const char* key) const { return *findValue(key); }
		const value_type& at(const value_type& value) const { return *findValue(value); }
		value_type& operator[](const key_type key){ return *findValue(key); }
		value_type& operator[](const char* key){ return *findValue(key); }
		value_type& operator[](const value_type& value){ return *findValue(value); }
		const value_type& operator[](const key_type key) const { return *findValue(key); }
		const value_type& operator[](const char* key) const { return *findValue(key); }
		const value_type& operator[](const value_type& value) const { return *findValue(value); }
	public:
		//���\�b�h
		inline index_type calcIndexStep(const key_type key) const { return INDEX_STEP_BASE - key % INDEX_STEP_BASE; }//�L�[����C���f�b�N�X�̕������v�Z
		inline index_type calcIndex(const key_type key) const { return calcIndexImpl<(TABLE_SIZE >= KEY_RANGE && KEY_RANGE > 0), size_type, index_type, key_type, TABLE_SIZE, KEY_MIN, KEY_RANGE >::calc(key); }//�L�[����C���f�b�N�X���v�Z
		inline index_type calcNextIndex(const key_type key, const index_type index) const { return (index + calcIndexStep(key)) % TABLE_SIZE; }//���̃C���f�b�N�X���v�Z
		std::size_t max_size() const { return TABLE_SIZE; }//�ő�v�f�����擾
		std::size_t capacity() const { return TABLE_SIZE; }//�ő�v�f�����擾
		std::size_t size() const { return m_usingCount - m_deletedCount; }//�g�p���̗v�f�����擾
		bool empty() const { return size() == 0; }//�󂩁H
		void clear()//�N���A
		{
			m_using.reset();
			m_deleted.reset();
			m_usingCount = 0;
			m_deletedCount = 0;
			m_maxFindCycle = 0;
		}
		//�C���f�b�N�X���擾
		index_type getFirstIndex() const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (index_type index = 0; index < TABLE_SIZE; ++index)
			{
				if (m_using[index])
					return index;
			}
			return INVALID_INDEX;
		}
		index_type getLastIndex() const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (index_type index = TABLE_SIZE; index > 0; --index)
			{
				if (m_using[index - 1])
					return index - 1;
			}
			return INVALID_INDEX;
		}
		index_type getNextIndex(const index_type index) const
		{
			index_type next_index = index == INVALID_INDEX ? 0 : index + 1;
			if (index < 0 || index >= TABLE_SIZE - 1 || m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (; next_index < TABLE_SIZE; ++next_index)
			{
				if (m_using[next_index])
					return next_index;
			}
			return INVALID_INDEX;
		}
		index_type getPrevIndex(const index_type index) const
		{
			index_type now_index = index == INVALID_INDEX ? TABLE_SIZE : index;
			if (index <= 0 || index >= TABLE_SIZE || m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			for (; now_index > 0; --now_index)
			{
				if (m_using[now_index - 1])
					return now_index - 1;
			}
			return INVALID_INDEX;
		}
		//�C���f�b�N�X������
		index_type findIndex(const key_type key) const
		{
			if (m_usingCount == 0 || m_deletedCount == m_usingCount)
				return INVALID_INDEX;
			const index_type index_first = calcIndex(key);
			index_type index = index_first;
			do
			{
				if (!m_using[index])
					break;
				if (!m_deleted[index] && m_keyTable[index] == key)
					return index;
				index = calcNextIndex(key, index);
			} while (index != index_first);
			return INVALID_INDEX;
		}
		inline index_type findIndex(const char* key){ return findIndex(calcCRC32(key)); }
		inline index_type findIndex(const value_type& value){ return findIndex(ope_type::getKey(value)); }
		//�l������
		value_type* findValue(const key_type key) const
		{
			const index_type index = findIndex(key);
			if (index == INVALID_INDEX)
				return nullptr;
			return &m_table[index];
		}
		inline value_type* findValue(const char* key){ return findValue(calcCRC32(key)); }
		inline value_type* findValue(const value_type& value){ return findValue(ope_type::getKey(value)); }
		//���� ���C�e���[�^��Ԃ�
		inline const_iterator begin() const
		{
			const index_type index = getFirstIndex();
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, index, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator end() const
		{
			return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
		}
		inline iterator begin(){ return const_cast<const container*>(this)->begin(); }
		inline iterator end(){ return const_cast<const container*>(this)->end(); }
		inline const_iterator cbegin() const { return this->begin(); }
		inline const_iterator cend() const { return this->end(); }
		const_iterator find(const key_type key) const
		{
			const index_type index = findIndex(key);
			if (index == INVALID_INDEX)
				return iterator(*this, INVALID_INDEX, ope_type::INVALID_KEY, nullptr, false);
			return iterator(*this, m_keyTable[index], reinterpret_cast<const value_type*>(m_table[index]), m_deleted[index]);
		}
		inline const_iterator find(const char* key) const { return find(calcCRC32(key)); }
		const_iterator find(const value_type& value) const { return find(ope_type::getKey(value)); }
		iterator find(const key_type key){ return const_cast<const container*>(this)->find(key); }
		iterator find(const char* key){ return const_cast<const container*>(this)->find(key); }
		iterator find(const value_type value){ return const_cast<const container*>(this)->find(value); }
		//�L�[���蓖��
		//���l�̗̈�̐擪�|�C���^��Ԃ�
		value_type* assign(const key_type key)
		{
			if (m_usingCount == TABLE_SIZE && m_deletedCount == 0)
				return nullptr;
			int find_cycle = 0;
			const index_type index_first = calcIndex(key);
			index_type index = index_first;
			do
			{
				++find_cycle;
				if (!m_using[index] || m_deleted[index])
					break;
				if (m_keyTable[index] == key)
					return nullptr;
				index = calcNextIndex(key, index);
			} while (index != index_first);
			m_keyTable[index] = key;
			++m_usingCount;
			m_using[index] = true;
			if (m_deleted[index])
				--m_deletedCount;
			m_deleted[index] = false;
			m_maxFindCycle = m_maxFindCycle >= find_cycle ? m_maxFindCycle : find_cycle;
			return reinterpret_cast<value_type*>(&m_table[index]);
		}
		inline value_type* assign(const char* key){ return assign(calcCRC32(key)); }
		inline value_type* assign(const value_type& value){ return assign(ope_type::getKey(value)); }
		//�L�[���蓖�Ă��Ēl��}���i�R�s�[�j
		value_type* insert(const key_type key, const value_type& value)
		{
			value_type* assigned_value = assign(key);
			if (!assigned_value)
				return nullptr;
			*assigned_value = value;
			return assigned_value;
		}
		inline value_type* insert(const char* key, const value_type& value){ return insert(calcCRC32(key), value); }
		inline value_type* insert(const value_type& value){ return insert(ope_type::getKey(value), value); }
		//�L�[���蓖�Ă��Ēl��������
		template<typename... Tx>
		value_type* emplace(const key_type key, const Tx&... args)
		{
			value_type* assigned_value = assign(key);
			if (!assigned_value)
				return nullptr;
			assigned_value = new(assigned_value) value_type(args...);
			return assigned_value;
		}
		template<typename... Tx>
		inline value_type* emplace(const char* key, const Tx&... args){ return emplace(calcCRC32(key), args...); }
		template<typename... Tx>
		value_type* emplaceAuto(const Tx&... args)
		{
			value_type value(args...);
			return insert(value);
		}
		//�L�[���폜
		bool erase(const key_type key)
		{
			const index_type index = findIndex(key);
			if (index == INVALID_INDEX)
				return false;
			value_type* data_p = reinterpret_cast<value_type*>(&m_table[index]);
			ope_type::call_destructor(data_p);
			operator delete(data_p, data_p);
			m_deleted[index] = true;
			--m_usingCount;
			++m_deletedCount;
			return true;
		}
		bool erase(const char* key){ return erase(calcCRC32(key)); }
	public:
		//�R���X�g���N�^
		container() :
			m_using(),
			m_deleted(),
			m_usingCount(0),
			m_deletedCount(0),
			m_maxFindCycle(0)
		{}
		//�f�X�g���N�^
		~container()
		{}
	private:
		unsigned char m_table[TABLE_SIZE][sizeof(value_type)];//�f�[�^�e�[�u��
		key_type m_keyTable[TABLE_SIZE];//�L�[�e�[�u��
		std::bitset<TABLE_SIZE> m_using;//�L�[�ݒ�ς݃t���O ���o�^���폜���Ă�false�ɂȂ�Ȃ�
		std::bitset<TABLE_SIZE> m_deleted;//�폜�ς݃t���O
		int m_usingCount;//�g�p���f�[�^�� ���o�^���폜���Ă�����Ȃ�
		int m_deletedCount;//�폜�ς݃f�[�^��
		int m_maxFindCycle;//�������̍ő叄��� ���o�^���폜���Ă�����Ȃ�
	};
}//namespace hash_table

//--------------------------------------------------------------------------------
//�e�X�g

//�y�����^�C���Łz�f���\��
void printPrime(const std::size_t min, const std::size_t max)
{
	if (max > min)
		printPrime(min, max - 1);
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", max, isPrime(max) ? "PRIME.    " : "not prime.", makePrimePrev(max), makePrimeEqPrev(max), makePrimeNext(max), makePrimeEqNext(max));
}

//�y���^�v���O���~���O�Łz�f���\��
template<std::size_t N>
void _printPrimeCommon()
{
	printf("%6d is %s [prev=%6d(%6d), next=%6d(%6d)]\n", N, isPrimeMeta<N>::value ? "PRIME.    " : "not prime.", makePrimePrevMeta<N>::value, makePrimeEqPrevMeta<N>::value, makePrimeNextMeta<N>::value, makePrimeEqNextMeta<N>::value);
}
template<std::size_t MIN, std::size_t MAX>
struct printPrimeMeta{
	void operator()()
	{
		printPrimeMeta<MIN, MAX - 1>()();
		_printPrimeCommon<MAX>();
	}
};
template<std::size_t MIN>
struct printPrimeMeta<MIN, MIN>{
	void operator()()
	{
		_printPrimeCommon<MIN>();
	}
};

//--------------------------------------------------------------------------------
//�n�b�V���e�[�u���e�X�g

//----------------------------------------
//�e�X�g�f�[�^
struct data_t
{
	crc32_t m_nameHash;//���O�̃n�b�V���l
	const char* m_name;//���O
	int m_value;//�l

	//�R���X�g���N�^
	data_t(const char* name, const int value) :
		m_nameHash(calcCRC32(name)),
		m_name(name),
		m_value(value)
	{
		printf("contructor: data_t [%s]\n", m_name);
	}
	//�f�X�g���N�^
	~data_t()
	{
		printf("destructor: ~data_t [%s]\n", m_name);
	}
};
static const std::size_t TEST_DATA_TABLE_SIZE = 10;
//----------------------------------------
//�e�X�g�f�[�^����N���X
struct ope_t : public hash_table::base_ope_t<ope_t, crc32_t, data_t>
{
	//�L�[���擾
	inline static key_type getKey(const value_type& value){ return value.m_nameHash; }
};

//----------------------------------------
//���C��
int main(const int argc, const char* argv[])
{
#if 0
	//�f���R���p�C�����v�Z�̍ċA���x�����E�`�F�b�N
	static const std::size_t x = 9999;
	printf("x=%d\n", x);
	printf("  isPrime=%s\n", isPrimeMeta<x>::value ? "true" : "False");
	printf("  prev=%d\n", makePrimePrevMeta<x>::value);
	printf("  next=%d\n", makePrimeNextMeta<x>::value);
	printf("  equalPrev=%d\n", makePrimeEqPrevMeta<x>::value);
	printf("  equalNext=%d\n", makePrimeEqNextMeta<x>::value);
#endif
#if 0
	//�f���v�Z�̃e�X�g
	static const std::size_t MIN = 1020;
	static const std::size_t MAX = 1030;
	
	printf("----- Check and Make Prime for Runtime -----\n");
	printPrime(MIN, MAX);
	
	printf("----- Check and Make Prime for Meta-Programming -----\n");
	printPrimeMeta<MIN, MAX>()();
#endif
	
	//�n�b�V���e�[�u���̃e�X�g
	printf("----- Hash Table -----\n");
	hash_table::container<ope_t, TABLE_SIZE> table;
	printf("hash_table:\n");
	printf(".getOriginalTableSize()=%u\n", table.getOriginalTableSize());
	printf(".getTableSize()=%u\n", table.getTableSize());
	printf(".getTableSizeOvered()=%u\n", table.getTableSizeOvered());
	printf(".getKeyMin()=%u\n", table.getKeyMin());
	printf(".getKeyMax()=%u\n", table.getKeyMax());
	printf(".getKeyRange()=%u\n", table.getKeyRange());
	
#if 0
	//�n�b�V���e�[�u���̃C���f�b�N�X�v�Z���W�b�N�e�X�g
	//���S�ẴC���f�b�N�X���A���m�Ƀe�[�u���T�C�Y�i�f���j��̍Čv�Z���s�����ŁA���̃C���f�b�N�X�ɖ߂邱�Ƃ��m�F�B
	int ng_count = 0;
	for (crc32_t key = table.getKeyMin(); key < table.getKeyMax(); ++key)//'<='�Ŕ��肷��Ɩ������[�v�ɂȂ�̂�'<'�Ŕ���
	{
		if (key % (1024 * 1024) == 0)
			printf("pass ... Key:%d\n", key);
		std::size_t count = 0;
		std::size_t first_index = table.calcIndex(key);
		std::size_t index = first_index;
		do
		{
			index = table.calcNextIndex(key, index);
			++count;
		} while (index != first_index && count < table.getTableSize());
		if (count != table.getTableSize())
		{
			printf("%u is OUT! (count=%d)\n", key, count);
			++ng_count;
		}
	}
	printf("Chek Hash Table: NG=%d/%d\n", ng_count, table.getTableSize());
	for (std::size_t key = 10; key <= 30; key += 1)
	{
		printf("Key:%u -> Index;%u\n", key, table.calcIndex(key));
	}
#endif
#if 1
	//�n�b�V���e�[�u���e�X�g
	data_t* result;
	result = table.emplace(110, "123", 123);
	result = table.emplace(220, "456", 456);
	result = table.emplace(330, "789", 789);
	result = table.emplace(110, "123", 123);
	table.erase(220);
	table.erase(330);
	result = table.emplace(220, "456!", 4567);
	result = table.emplace("123", "123!!", 12345);
	result = table.emplaceAuto("456!!", 45679);
	result = table.emplace("789", "789!!", 78901);
	for (auto& o : table)
	{
		printf("index=%d, key=%08x, name=%s, value=%d, is_deleted=%s\n", o.index, o.key, o->m_name, o->m_value, o.is_deleted ? "TRUE" : "false");
	}
	printf(".size()=%d\n", table.size());
	printf(".getUsingCount()=%d\n", table.getUsingCount());
	printf(".getDeletedCount()=%d\n", table.getDeletedCount());
	printf(".getMaxFindCycle()=%d\n", table.getMaxFindCycle());
#endif
	return EXIT_SUCCESS;
}

// End of file
