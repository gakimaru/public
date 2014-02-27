//#define TLS_IS_POSIX//�yGCC�p�zTLS�̐錾��POSIX�X�^�C���ɂ��鎞�͂��̃}�N����L���ɂ���
//#define ENABLE_CONSTEXPR//�yC++11�p�zconstexpr��L���ɂ��鎞�͂��̃}�N����L���ɂ���

#include <stdio.h>
#include <stdlib.h>

#include <limits.h>//UCHAR_MAX�p
#include <bitset>//std::bitset�p
#include <iterator>//std::iterator�p

#include <atomic>//C++11�A�g�~�b�N�^

//�X���b�h���[�J���X�g���[�W�C���q
//��C++11�d�l�U��
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX�d�l
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows�d�l
#endif//TLS_IS_POSIX

//constexpr�Ή�
#ifdef ENABLE_CONSTEXPR
#define CONSTEXPR constexpr
#else//ENABLE_CONSTEXPR
#define CONSTEXPR const
#endif//ENABLE_CONSTEXPR

//--------------------------------------------------------------------------------
//�f�o�b�O���O
namespace dbgLog
{
	//----------------------------------------
	//���x��
	class level
	{
	public:
		//�^
		typedef unsigned char value_t;//�l�i���x���j
		typedef unsigned char byte;//�o�b�t�@�p
	public:
		//�萔�i�v�Z�p�j
	#ifdef ENABLE_CONSTEXPR
		CONSTEXPR value_t calcPrintLevel(const value_t value){ return value >> 1; }//�l���o�̓��x���ɕϊ�
		CONSTEXPR value_t calcFromPrintLevel(const value_t value){ return value << 1; }//�o�̓��x����l�ɕϊ�
	#else//ENABLE_CONSTEXPR
		#define calcPrintLevel(value) ((value) >> 1)//�l���o�̓��x���ɕϊ�
		#define calcFromPrintLevel(value) ((value) << 1)//�o�̓��x����l�ɕϊ�
	#endif//ENABLE_CONSTEXPR
	public:
		//�萔
		static const value_t ASSIGNED_NUM = 11;//���蓖�čς݃��x����
		static const value_t SPECIAL_NUM = 2;//���ꃌ�x����
		static const value_t NUM = ASSIGNED_NUM + SPECIAL_NUM;//���x������
		static const value_t MIN = 0;//���x���ŏ��l
		static const value_t MAX = NUM - 1;//���x���ő�l
		static const value_t ASSIGNED_MIN = MIN;//���蓖�čς݃��x���ŏ��l
		static const value_t ASSIGNED_MAX = ASSIGNED_MIN + ASSIGNED_NUM - 1;//���蓖�čς݃��x���ő�l
		static const value_t SPECIAL_MIN = ASSIGNED_MAX + 1;//���ꃌ�x���ŏ��l
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//���ꃌ�x���ő�l
		static const value_t BEGIN = MIN;//���x���J�n�l�i�C�e���[�^�p�j
		static const value_t END = NUM;//���x���I���l�i�C�e���[�^�p�j
		static const value_t POOL_NUM = NUM + 1;//���x���L�^��
		static const value_t PRINT_LEVEL_MIN = calcPrintLevel(ASSIGNED_MIN);//�o�̓��x���ŏ��l
		static const value_t PRINT_LEVEL_MAX = calcPrintLevel(ASSIGNED_MAX);//�o�̓��x���ő�l
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");//�萔�`�F�b�N
	public:
		//�^
		//--------------------
		//�C�e���[�^
		class iterator : public std::iterator<std::bidirectional_iterator_tag, level>//�o�����C�e���[�^�Ƃ��Ď���
		{
		public:
			//�I�y���[�^
			const level* operator->() const { return &container::get(m_value); }
			const level& operator*() const { return container::get(m_value); }
			bool operator==(const iterator rhs) const { return m_value == rhs.m_value; }
			bool operator!=(const iterator rhs) const { return m_value != rhs.m_value; }
			const level& operator++() const { return m_value >= container::endValue() ? container::getEnd() : container::get(++m_value); }
			const level& operator++(int) const { return m_value >= container::endValue() ? container::getEnd() : container::get(m_value++); }
			const level& operator--() const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getEnd(); } return container::get(--m_value); }
			const level& operator--(int) const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getBegin(); } return container::get(m_value--); }
		public:
			//�L���X�g�I�y���[�^
			operator const level&() const { return container::get(m_value); }
		public:
			//�R���X�g���N�^
			iterator(const value_t value) :
				m_value(value)
			{}
			iterator(const value_t value, int) :
				m_value(container::endValue())
			{}
			iterator(const level& obj) :
				m_value(obj.value())
			{}
			iterator(const level& obj, int) :
				m_value(container::endValue())
			{}
			iterator() :
				m_value(container::endValue())
			{}
			//�f�X�g���N�^
			~iterator()
			{}
		private:
			//�t�B�[���h
			value_t mutable m_value;//�l�i���x���j
		};
		//--------------------
		//const�C�e���[�^
		typedef const iterator const_iterator;
		//--------------------
		//�R���e�i�i�C�e���[�^�p�j
		class container
		{
			friend class level;
		public:
			//���\�b�h
			static const value_t beginValue(){ return BEGIN; }//�J�n�l�擾
			static const value_t endValue(){ return END; }//�I���l�擾
			static const level& get(const value_t value){ return m_poolPtr[value]; }//�v�f���擾
			static const level& getBegin(){ return m_poolPtr[beginValue()]; }//�J�n�v�f���擾
			static const level& getEnd(){ return m_poolPtr[endValue()]; }//�I���v�f���擾
		private:
			static void set(const value_t value, const level& obj)//�v�f���X�V
			{
				if (!container::m_isAlreadyPool[value])
				{
					container::m_poolPtr[value] = obj;
					container::m_isAlreadyPool[value] = true;
				}
			}
		public:
			static const iterator begin(){ return iterator(beginValue()); }//�J�n�C�e���[�^���擾
			static const iterator end()	{ return iterator(endValue()); }//�I���C�e���[�^���擾
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//�J�nconst�C�e���[�^���擾
			static const_iterator cend(){ return const_iterator(endValue()); }//�I��const�C�e���[�^���擾
			//��reverse_iterator��Ή�
		private:
			//���\�b�h
			//�������i������j
			static void initializeOnce();
		private:
			//�t�B�[���h
			static bool m_isInitialized;//�������ς�
			static level* m_poolPtr;//�v�f�̃v�[���i�|�C���^�j
			static byte m_pool[];//�v�f�̃v�[���i�o�b�t�@�j���o�b�t�@�ƃ|�C���^�𕪂��Ă���̂́A�R���X�g���N�^�̎��s��h�~���邽��
			static std::bitset<POOL_NUM> m_isAlreadyPool;//�v�f�̏������ς݃t���O
		};
	public:
		//�I�y���[�^
		//���o�̓��x���Ŕ�r����
		bool operator ==(const level& rhs) const { return printLevel() == rhs.printLevel(); }
		bool operator !=(const level& rhs) const { return printLevel() != rhs.printLevel(); }
		bool operator >(const level& rhs) const { return printLevel() > rhs.printLevel(); }
		bool operator >=(const level& rhs) const { return printLevel() >= rhs.printLevel(); }
		bool operator <(const level& rhs) const { return printLevel() < rhs.printLevel(); }
		bool operator <=(const level& rhs) const { return printLevel() <= rhs.printLevel(); }
	private:
		level& operator=(const level& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//�L���X�g�I�y���[�^
		operator int() const { return static_cast<int>(m_value); }
		operator value_t() const { return m_value; }
		operator const char*() const { return m_name; }
	public:
		//�A�N�Z�b�T
		value_t value() const { return m_value; }//�l�i���x���j�擾
		const char* name() const { return m_name; }//���O�擾
		value_t printLevel() const { return calcPrintLevel(m_value); }//�o�̓��x���擾
		bool isPrintLevel() const { return m_isPrintLevel; }//�o�̓��x���Ƃ��Ďg�p�\���H
		bool isPrintLevelMask() const { return m_isPrintLevelMask; }//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	public:
		//���\�b�h
		//�R���e�i�v�f���擾�i�V���[�g�J�b�g�p�j
		static const level& get(const value_t value){ return container::get(value); }
		//�O�̃��x�����擾
		const level& prev() const
		{
			if (printLevel() <= PRINT_LEVEL_MIN || printLevel() > PRINT_LEVEL_MAX || !m_isPrintLevel)
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcFromPrintLevel(calcPrintLevel(m_value) - 1)];
		}
		//���̃��x�����擾
		const level& next() const
		{
			if (printLevel() < PRINT_LEVEL_MIN || printLevel() >= PRINT_LEVEL_MAX || !m_isPrintLevel)
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcFromPrintLevel(calcPrintLevel(m_value) + 1)];
		}
	public:
		//�f�t�H���g�R���X�g���N�^
		level() :
			m_value(UCHAR_MAX),
			m_name(nullptr),
			m_isPrintLevel(false),
			m_isPrintLevelMask(false)
		{
			container::initializeOnce();//�R���e�i�������i������j
		}
		//�R���X�g���N�^
		level(const level& src) :
			m_value(src.m_value),
			m_name(src.m_name),
			m_isPrintLevel(src.m_isPrintLevel),
			m_isPrintLevelMask(src.m_isPrintLevelMask)
		{
		}
		level(const value_t value, const char* name, const bool is_print_level, const bool is_print_level_mask) :
			m_value(value),
			m_name(name),
			m_isPrintLevel(is_print_level),
			m_isPrintLevelMask(is_print_level_mask)
		{
			container::initializeOnce();//�R���e�i�������i������j
			container::set(m_value, *this);//�R���e�i�ɓo�^
		}
		level(const value_t value) :
			m_value(value),
			m_name(nullptr),
			m_isPrintLevel(false),
			m_isPrintLevelMask(false)
		{
			*this = container::get(m_value);//�R���e�i����擾���Ď��g�ɃR�s�[
		}
		//�f�X�g���N�^
		~level()
		{}
	private:
		const value_t m_value;//�l�i���x���j
		const char* m_name;//���O
		const bool m_isPrintLevel;//�o�̓��x���Ƃ��Ďg�p�\���H
		const bool m_isPrintLevelMask;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	};
	//----------------------------------------
	//���x����`�p�e���v���[�g�N���X�F���蓖�čς݃��x���p
	template<unsigned char V>
	class level_assigned : public level
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i���x���j
		static_assert(VALUE >= ASSIGNED_MIN && VALUE <= ASSIGNED_MAX, "out of range of level");//�l�͈̔̓`�F�b�N
		static const bool IS_PRINT_LEVEL = true;//�o�̓��x���Ƃ��Ďg�p�\���H
		static const bool IS_PRINT_LEVEL_MASK = true;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	public:
		//�R���X�g���N�^
		level_assigned(const char* name) :
			level(VALUE, name, IS_PRINT_LEVEL, IS_PRINT_LEVEL_MASK)
		{}
	};
	//----------------------------------------
	//���x����`�p�e���v���[�g�N���X�F���ꃌ�x���p
	template<unsigned char V>
	class level_special : public level
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i���x���j
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of level");//�l�͈̔̓`�F�b�N
		static const bool IS_PRINT_LEVEL = false;//�o�̓��x���Ƃ��Ďg�p�\���H
		static const bool IS_PRINT_LEVEL_MASK = true;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	public:
		//�R���X�g���N�^
		level_special(const char* name) :
			level(VALUE, name, IS_PRINT_LEVEL, IS_PRINT_LEVEL_MASK)
		{}
	};
	//----------------------------------------
	//���x����`�N���X�F�I���p
	class level_end : public level
	{
	public:
		//�萔
		static const value_t VALUE = END;//�l�i���x���j
		static const bool IS_PRINT_LEVEL = false;//�o�̓��x���Ƃ��Ďg�p�\���H
		static const bool IS_PRINT_LEVEL_MASK = false;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	public:
		//�R���X�g���N�^
		level_end() :
			level(VALUE, "(END)", IS_PRINT_LEVEL, IS_PRINT_LEVEL_MASK)
		{}
	};
	//----------------------------------------
	//���x���萔
#define define_assignedLevel(print_level, sub) (level::ASSIGNED_MIN + print_level * 2 + sub)
#define define_specialLevel(value) (level::SPECIAL_MIN + value)
	enum levelEnum : level::value_t
	{
		asNormal = define_assignedLevel(1, 0),//�ʏ탁�b�Z�[�W
		asVerbose = define_assignedLevel(0, 0),//�璷���b�Z�[�W
		asDetail = define_assignedLevel(0, 1),//�ڍ׃��b�Z�[�W
		asImportant = define_assignedLevel(2, 0),//�d�v���b�Z�[�W
		asWarning = define_assignedLevel(3, 0),//�x�����b�Z�[�W
		asCritical = define_assignedLevel(4, 0),//�d�僁�b�Z�[�W
		asAbsolute = define_assignedLevel(5, 0),//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
		//�ȉ��A���O���x���^��ʒʒm���x���ύX�p
		asSilent = define_specialLevel(0),//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
		asSilentAbsolutely = define_specialLevel(1),//��ΐÎ�i�S�Ẵ��b�Z�[�W���o�͂��Ȃ��j
	};
	//----------------------------------------
	//���x����`
#define declare_assignedLevel(value) struct level_##value : public level_assigned<value>{ level_##value () :level_assigned<value>(#value){} }
#define declare_specialLevel(value) struct level_##value : public level_special<value>{ level_##value () :level_special<value>(#value){} }
	declare_assignedLevel(asNormal);//�ʏ탁�b�Z�[�W
	declare_assignedLevel(asVerbose);//�璷���b�Z�[�W
	declare_assignedLevel(asDetail);//�ڍ׃��b�Z�[�W
	declare_assignedLevel(asImportant);//�d�v���b�Z�[�W
	declare_assignedLevel(asWarning);//�x�����b�Z�[�W
	declare_assignedLevel(asCritical);//�d�僁�b�Z�[�W
	declare_assignedLevel(asAbsolute);//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
	//�ȉ��A���O���x���^��ʒʒm���x���ύX�p
	declare_specialLevel(asSilent);//�Î�i��΃��b�Z�\�W�ȊO�o�͂��Ȃ��j
	declare_specialLevel(asSilentAbsolutely);//��ΐÎ�i�S�Ẵ��b�Z�[�W���o�͂��Ȃ��j
	
	//----------------------------------------
	//���x���R���e�i�̐ÓI�ϐ����C���X�^���X��
	bool level::container::m_isInitialized = false;
	level* level::container::m_poolPtr = nullptr;
	level::byte level::container::m_pool[(POOL_NUM)* sizeof(level)];
	std::bitset<level::POOL_NUM> level::container::m_isAlreadyPool;
	//----------------------------------------
	//���x���R���e�i�������i������j
	void level::container::initializeOnce()
	{
		//�������ς݃`�F�b�N
		if (m_isInitialized)
			return;
		//�ÓI�ϐ���������
		m_isInitialized = true;
		m_isAlreadyPool.reset();
		memset(m_pool, 0, sizeof(m_pool));
		m_poolPtr = reinterpret_cast<level*>(m_pool);
		//�v�f��������
		for (level::value_t value = 0; value < level::NUM; ++value)
		{
			level(value, "(undefined)", false, false);
			m_isAlreadyPool[value] = false;
		}
		//���蓖�čς݃��x����ݒ�i�R���X�g���N�^�ŗv�f��o�^�j
		level_asNormal();//�ʏ탁�b�Z�[�W
		level_asVerbose();//�璷���b�Z�[�W
		level_asDetail();//�ڍ׃��b�Z�[�W
		level_asImportant();//�d�v���b�Z�[�W
		level_asWarning();//�x�����b�Z�[�W
		level_asCritical();//�d�僁�b�Z�[�W
		level_asAbsolute();//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
		level_asSilent();//�Î�i��΃��b�Z�\�W�ȊO�o�͂��Ȃ��j
		level_asSilentAbsolutely();//��ΐÎ�i�S�Ẵ��b�Z�[�W���o�͂��Ȃ��j
		level_end();//�I�[
	}
	//----------------------------------------
	//�ϐ�
	static level s_levelForInitialize;//�������������s�̂��߂̃C���X�^���X
	//----------------------------------------
	//���x���R���e�i��
	void printLevelAll()
	{
		for (auto& lv : level::container())//C++11�X�^�C��
		//for (auto ite = level::container::begin(); ite != level::container::end(); ++ite)//�����̃X�^�C��
		//for (auto ite = level::container::cbegin(); ite != level::container::cend(); ++ite)//�����̃X�^�C��
		{
			//const level& lv = ite;//�C�e���[�^��ϊ��i�C�e���[�^�̂܂܂ł��A���[���Z�q�Œ��ڒl����\�j
			printf("level=%d, name=\"%s\", printLevel=%d, isPrintLevel=%d, isPrintLevelMask=%d\n", lv.value(), lv.name(), lv.printLevel(), lv.isPrintLevel(), lv.isPrintLevelMask());
			auto& prev = lv.prev();
			auto& next = lv.next();
			printf("           prev=%s(%d)\n", prev.name(), prev.value());
			printf("           next=%s(%d)\n", next.name(), next.value());
		}
	}

	//--------------------
	//�J�e�S���萔
	//������X�^�b�t�ɂƂ��ĕ�����Ղ��A
	//�@���b�Z�[�W���d���ރv���O���}�[�ɂƂ���
	//�@������Ղ����x�̕��ނɂ���
	//��forReserved**��C�ӂ̗p�r�Ɋ��蓖�ĂĎg�p��
	struct category
	{
		typedef unsigned char value_t;
		static const value_t NORMAL_NUM = 64;
		static const value_t ASIGNED_NUM = 8;
		static const value_t RESERVED_NUM = NORMAL_NUM - ASIGNED_NUM;
		static const value_t SPECIAL_NUM = 3;
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;
		static const value_t MIN = 0;
		static const value_t MAX = NUM - 1;
		static const value_t ASSIGNED_MIN = MIN;
		static const value_t ASSIGNED_MAX = ASSIGNED_MIN + ASIGNED_NUM - 1;
		static const value_t RESERVED_MIN = ASSIGNED_MAX + 1;
		static const value_t RESERVED_MAX = RESERVED_MIN + RESERVED_NUM - 1;
		static const value_t SPECIAL_MIN = RESERVED_MAX + 1;
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");
		bool operator ==(const category& rhs) const { return m_value == rhs.m_value; }
		bool operator !=(const category& rhs) const { return m_value != rhs.m_value; }
		operator int() const { return static_cast<int>(m_value); }
		operator value_t() const { return m_value; }
		operator const char*() const { return m_name; }
		value_t val() const { return m_value; }
		const char* str() const { return m_name; }
		category(const value_t value, const char* name) :
			m_value(value),
			m_name(name)
		{}
	private:
		const value_t m_value;
		const char* m_name;
	};
	template<unsigned char V>
	struct assignedCategory : public category
	{
		static const value_t VALUE = ASSIGNED_MIN + V;
		static_assert(VALUE >= ASSIGNED_MIN && VALUE <= ASSIGNED_MAX, "out of range of category");
		assignedCategory(const char* name) :
			category(VALUE, name)
		{}
	};
	template<unsigned char V>
	struct reservedCategory : public category
	{
		static const value_t VALUE = RESERVED_MIN + V;
		static_assert(VALUE >= RESERVED_MIN && VALUE <= RESERVED_MAX, "out of range of category");
		reservedCategory(const char* name) :
			category(VALUE, name)
		{}
	};
	template<unsigned char V>
	struct specialCategory : public category
	{
		static const value_t VALUE = SPECIAL_MIN + V;
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of category");
		specialCategory(const char* name) :
			category(VALUE, name)
		{}
	};
#define declare_assignedCategory(name, value) struct name : public assignedCategory<value>{ name () :assignedCategory<value>(#name){} }
#define declare_reservedCategory(name, value) struct name : public reservedCategory<value>{ name () :reservedCategory<value>(#name){} }
#define declare_specialCategory(name, value) struct name : public specialCategory<value>{ name () :specialCategory<value>(#name){} }
	declare_assignedCategory(forAny, 0);//�Ȃ�ł��i�J�e�S���Ȃ��j
	declare_assignedCategory(forLogic, 1);//�v���O�����֌W
	declare_assignedCategory(forResource, 2);//���\�[�X�֌W
	declare_assignedCategory(for3D, 3);//3D�O���t�B�b�N�X�֌W
	declare_assignedCategory(for2D, 4);//2D�O���t�B�b�N�X�֌W
	declare_assignedCategory(forSound, 5);//�T�E���h�֌W
	declare_assignedCategory(forScript, 6);//�X�N���v�g�֌W
	declare_assignedCategory(forGameData, 7);//�Q�[���f�[�^�֌W
	//�\��p�i���[�U�[��`�p�j
	declare_reservedCategory(forReserved01, 0);//(�\��01)
	declare_reservedCategory(forReserved02, 1);//(�\��02)
	declare_reservedCategory(forReserved03, 2);//(�\��03)
	//���O���x���^��ʒʒm���x���ύX�p
	declare_specialCategory(forEvery, 0);//�S���܂Ƃ߂ĕύX
	//����ȃJ�e�S���i�v�����g����p�j
	declare_specialCategory(forCallppoint, 1);//���߂̃R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
	declare_specialCategory(forCriticalCallppoint, 2);//���߂̏d��R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
}
#if 0
	//----------------------------------------
	//���O���x������
	//--------------------
	//���O���x����S�ă��Z�b�g
	static void resetLogLevelAll()
	{
		for (E_MESSAGE_LV& level : m_logLevel)
			level = asNormal;
	}
	//--------------------
	//��ʒʒm���x����S�ă��Z�b�g
	static void resetNoticeLevelAll()
	{
		for (E_MESSAGE_LV& level : m_noticeLevel)
			level = asCritical;
	}
	//--------------------
	//���O���x���Ɖ�ʒʒm���x�����܂����������Ă��Ȃ���Ώ�����
	static void initializeLogLevelAll()
	{
		if (m_logLevelIsInitialized)
			return;
		resetLogLevelAll();
		resetNoticeLevelAll();
		m_logLevelIsInitialized = true;
	}
	//--------------------
	//���݂̃��O���x�����擾
	static E_MESSAGE_LV getLogLv(const E_MESSAGE_CATEGOY category)
	{
		return m_logLevel[category];
	}
	//--------------------
	//���݂̃��O���x����ύX
	//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
	void setLogLv(const E_MESSAGE_CATEGOY category, const E_MESSAGE_LV level)
	{
		m_logLevel[category] = level;
	}
	//--------------------
	//���݂̉�ʒʒm���x�����擾
	static E_MESSAGE_LV getLogLv(const E_MESSAGE_CATEGOY category)
	{
		return m_logLevel[category];
	}
	//--------------------
	//���݂̉�ʒʒm���x����ύX
	//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
	static void setLogLv(const E_MESSAGE_CATEGOY category, const E_MESSAGE_LV level)
	{
		m_logLevel[category] = level;
	}
private:
	//--------------------
	//�ÓI�ϐ�
	static E_MESSAGE_LV m_logLevel[categoryNum];//���݂̃��O���x��
	static E_MESSAGE_LV m_noticeLevel[categoryNum];//���݂̉�ʒʒm���x��
	static bool m_logLevelIsInitialized;//���݂̃��O���x���Ɖ�ʒʒm���x���������ς݃t���O
};

	//���O���x���擾
	getLoglv(forAny);//�߂�l�Ƃ��ă��O���x�����Ԃ�
	
	//Lv.1�F�ʏ탁�b�Z�[�W
	printAsNormal(forAny, "�ʏ탁�b�Z�[�W by %s\n", name);
	//Lv.0�F�璷���b�Z�[�W
	printAsVerbose(forAny, "�璷���b�Z�[�W by %s\n", name);
	//Lv.0�F�ڍ׃��b�Z�[�W
	printAsDetail(forAny, "�ڍ׃��b�Z�[�W by %s\n", name);
	//Lv.2�F�d�v���b�Z�[�W
	printAsImportant(forAny, "�d�v���b�Z�[�W by %s\n", name);
	//Lv.3�F�x�����b�Z�[�W
	printAsWarning(forAny, "�x�����b�Z�[�W by %s\n", name);
	//LV.4�F�d��i���j���b�Z�[�W
	printAsCritical(forAny, "�d�僁�b�Z�[�W by %s\n", name);
	//Lv.5�F��΁i�K�{�j���b�Z�[�W
	printAsAbsolute(forAny, "��΃��b�Z�[�W by %s\n", name);

	//���x���������w��
	printLv(asNormal, forAny, "�ʏ탁�b�Z�[�W by %s\n", name);
	//�������Ŏw�肵�Ă���
	//��Lv.0�`5�ȊO���w�肵���ꍇ�A���O���x���ɂ�炸�����o�͂���Ȃ�
	printLv(2, forAny, "�d�v���b�Z�[�W by %s\n", name);
}


//----------------------------------------
//��ʒʒm���x��

//��ʒʒm���x���ύX
//�����O���x�����Ⴂ���x����ݒ肵�Ă��ʒm����Ȃ�
setNoticeLv(asCritical, forAny);//�d�僁�b�Z�[�W�̂݉�ʒʒm
//���e���x���̐����\���J���[
//�@Lv.1�F�ʏ�      ... ��
//�@Lv.0�F�璷/�ڍ� ... �i�\������Ȃ��j
//�@Lv.2�F�d�v      ... ��
//�@Lv.3�F�x��      ... ��
//�@Lv.4�F�d��      ... ��
//�@Lv.5�F���      ... �i�\������Ȃ��j

//��ʒʒm���x���擾
getNoticeLvAs(forAny);//�߂�l�Ƃ��ĉ�ʒʒm���x�����Ԃ�
#endif



//----------------------------------------
//�R�[���|�C���g
class callPoint
{

};

//�e�X�g
int main(const int argc, const char* argv[])
{
	//���x�����
	dbgLog::printLevelAll();
	return EXIT_SUCCESS;
}

// End of file
