//#define TLS_IS_POSIX//�yGCC�p�zTLS�̐錾��POSIX�X�^�C���ɂ��鎞�͂��̃}�N����L���ɂ���
#define USE_FUNCSIG//�yMS�ŗL�d�l�z�֐�����__FUNCSIG__���g�p���鎞�ɂ��̃}�N����L���ɂ���
#define USE_STRCPY_S//�yMS�ŗL�d�l�zstrcpy_s���g�p���鎞�ɂ��̃}�N����L���ɂ���
#define USE_WINDOWS_CONSOLE_COLOR//�yMS�ŗL�d�l�zWindows�X�^�C���̃R���\�[���J���[���g�p

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>//valist�p
#include <assert.h>//assert�p
#include <memory.h>//memcpy�p
#include <limits.h>//UCHAR_MAX�p
#include <bitset>//std::bitset�p
#include <iterator>//std::iterator�p
#include <algorithm>//std::move�p
#include <atomic>//C++11�A�g�~�b�N����
#include <unordered_map>//C++11�n�b�V���e�[�u��
#include <chrono>//C++11����

//�X���b�h���[�J���X�g���[�W�C���q
//��C++11�d�l�U��
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX�d�l
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows�d�l
#endif//TLS_IS_POSIX

//�֐����擾�}�N��
#ifdef USE_FUNCSIG
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif//USE_FUNCSIG

//�\�[�X�t�@�C�������֐����擾�}�N��
#define TO_STRING(s) #s//__LINE__�𕶎��񉻂��邽�߂̓�d�}�N��
#define TO_STRING_EX(s) TO_STRING(s)//__LINE__�𕶎��񉻂��邽�߂̃}�N��
#define GET_CONCATENATED_SOURCE_FILE_NAME() __FILE__ "(" TO_STRING_EX(__LINE__) ")  [" __TIMESTAMP__ "]"//�t�@�C�����������擾�}�N��
#define GET_FUNC_NAME() __PRETTY_FUNCTION__//�֐����擾�}�N��

//Windows�X�^�C���J���[�p
#ifdef USE_WINDOWS_CONSOLE_COLOR
#include <windows.h>
#include <conio.h> 
#endif//USE_WINDOWS_CONSOLE_COLOR

//--------------------
//���ʊ֐�
#include <string.h>
//�t�@�C�����擾�֐��i�f�B���N�g�������������������Ԃ��j
const char* getFileName(const char* str)
{
	std::size_t len = strlen(str);
	const char* p = str + len;
	for (; len > 0; --len, --p)
	{
		const char c = *(p - 1);
		if (c == '\\' || c == '/')
			return p;
	}
	return str;
}

//--------------------------------------------------------------------------------
//�f�o�b�O���b�Z�[�W
namespace dbg
{
	//----------------------------------------
	//�R���\�[���J���[�N���X
	class color
	{
	public:
		//�^
		//�n���h���^
	#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
		typedef HANDLE handle_t;
	#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
		typedef FILE* handle_t;
	#endif//USE_WINDOWS_CONSOLE_COLOR
	public:
		//�萔
		//�J���[�l
		enum color_t : unsigned char
		{
			reset = 0x10,//���Z�b�g
			through = 0x20,//�X���[�i����ێ��F�������Ȃ��j

		#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
			R = 0x04,//Red:��
			G = 0x02,//Green:��
			B = 0x01,//Blue:��
			I = 0x08,//Intensity:�N�₩
			BG_SHIFT = 4,//�w�i�F�w�莞�̃r�b�g�V�t�g��
		#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
			R = 0x01,//Red:��
			G = 0x02,//Green:��
			B = 0x04,//Blue:��
			I = 0x08,//high Intensity:�N�₩
		#endif//USE_WINDOWS_CONSOLE_COLOR

			RGB = 0x07,//RGB�}�X�N
			RGBI = 0x0f,//RGB+I�}�X�N

			//�W���J���[
			black = 0,//��
			blue = B,//��
			red = R,//��
			magenta = R | B,//��
			green = G,//��
			cyan = G | B,//��
			yellow = G | R,//��
			white = G | R | B,//��

			//�N�₩�ȃJ���[
			iBlack = I | black,//��
			iBlue = I | blue,//��
			iRed = I | red,//��
			iMagenta = I | magenta,//��
			iGreen = I | green,//��
			iCyan = I | cyan,//��
			iYellow = I | yellow ,//��
			iWhite = I | white,//��
		};
		//�Ώ�
		enum target_t : unsigned char
		{
			stdOut = 0,//�ΏہF�W���o��
			stdErr = 1,//�ΏہF�W���G���[
		};
		static const int targetNum = 2;
	public:
		//�A�N�Z�b�T
		target_t getTarget() const { return m_target; }//�Ώ�
		color_t getForeColor() const { return m_foreColor; }//�J���[�F�O��
		color_t getBackColor() const { return m_backColor; }//�J���[�F�w��
		color_t getPrevForeColor() const { return m_prevForeColor; }//�O�̃J���[:�O��
		color_t getPrevBackColor() const { return m_prevBackColor; }//�O�̃J���[:�w��
		bool isAutoRestore() const { return m_isAutoRestore; }//�����J���[�������s�w��
	public:
		//�L���X�g�I�y���[�^
		operator int() const { return static_cast<int>(m_target); }//�Ώ�
		operator target_t() const { return m_target; }//�Ώ�
	public:
		//���\�b�h
		//�J���[�ύX
		//�����ۂɃR���\�[���ɔ��f������
		void changeColor()
		{
			if (m_foreColor == through)
				return;
			changeColor(m_target, m_foreColor, m_backColor);
		}
		void changeColor(const target_t target, const color_t fore_color, const color_t back_color = black)
		{
			//�Ώۃn���h���擾
			const handle_t target_h = m_handle[target];

			//�J���[�ύX
			if (fore_color == reset)
			{
			#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
				SetConsoleTextAttribute(target_h, m_ConsoleScreenBufferInfo[target].wAttributes);
			#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
				fprintf(target_h, "\x1b[39m\x1b[49m");//"\x1b[0m"
			#endif//USE_WINDOWS_CONSOLE_COLOR
			}
			else
			{
			#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
				SetConsoleTextAttribute(target_h, ((back_color & RGBI) << BG_SHIFT) | (fore_color & RGBI));
			#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
				fprintf(target_h, "\x1b[%dm\x1b[%dm", (fore_color & I ? 90 : 30) + (fore_color & RGB), (back_color & I ? 100 : 40) + (back_color & RGB));
			#endif//USE_WINDOWS_CONSOLE_COLOR
			}
		}
	public:
		//�J���[�������i������j
		static void initializeOnce();
	public:
		//�f�t�H���g�R���X�g���N�^
		color() :
			m_target(stdOut),//�Ώ�
			m_foreColor(reset),//�J���[�F�O��
			m_backColor(reset),//�J���[�F�w��
			m_prevForeColor(reset),//�O�̃J���[�F�O�ʂ��L��
			m_prevBackColor(reset),//�O�̃J���[�F�w�ʂ��L��
			m_isAutoRestore(false)//�����J���[�������s�w��
		{
			initializeOnce();
		}
		//���[�u�R���X�g���N�^
		color(color&& src) :
			m_target(src.m_target),//�Ώ�
			m_foreColor(src.m_foreColor),//�J���[�F�O��
			m_backColor(src.m_backColor),//�J���[�F�w��
			m_prevForeColor(src.m_prevForeColor),//�O�̃J���[�F�O�ʂ��L��
			m_prevBackColor(src.m_prevBackColor),//�O�̃J���[�F�w�ʂ��L��
			m_isAutoRestore(src.m_isAutoRestore)//�����J���[�������s�w��
		{
			//���[�u�R���X�g���N�^�ɂ��A�ړ����̓��e�����ς��A�f�X�g���N�^���@�\���Ȃ��悤�ɂ���
			*const_cast<bool*>(&src.m_isAutoRestore) = false;//�����J���[�������s�w��𖳌���
		}
		//�R���X�g���N�^
		color(const target_t target, const color_t fore_color, const color_t back_color = black, const bool is_auto_restore = true) :
			m_target(target),//�Ώ�
			m_foreColor(fore_color),//�J���[�F�O��
			m_backColor(back_color),//�J���[�F�w��
			m_prevForeColor(m_nowForeColor[m_target]),//�O�̃J���[�F�O�ʂ��L��
			m_prevBackColor(m_nowBackColor[m_target]),//�O�̃J���[�F�w�ʂ��L��
			m_isAutoRestore(is_auto_restore)//�����J���[�������s�w��
		{
			if (m_foreColor == through || !m_isAutoRestore)
				return;
			m_nowForeColor[m_target] = m_foreColor;//���݂̃J���[�F�O�ʁi�L���p�j���X�V
			m_nowBackColor[m_target] = m_backColor;//���݂̃J���[�F�w�ʁi�L���p�j���X�V
			changeColor();
		}
		//�f�X�g���N�^
		~color()
		{
			if (m_foreColor == through || !m_isAutoRestore)
				return;
			m_nowForeColor[m_target] = m_prevForeColor;//���݂̃J���[�F�O�ʂ�O�̃J���[�ɖ߂�
			m_nowBackColor[m_target] = m_prevBackColor;//���݂̃J���[�F�w�ʂ�O�̃J���[�ɖ߂�
			changeColor(m_target, m_prevForeColor, m_prevBackColor);
		}
	private:
		//�t�B�[���h
		const target_t m_target;//�Ώ�
		const color_t m_foreColor;//�J���[�F�O��
		const color_t m_backColor;//�J���[�F�w��
		const color_t m_prevForeColor;//�O�̃J���[�F�O��
		const color_t m_prevBackColor;//�O�̃J���[�F�w��
		const bool m_isAutoRestore;//�����J���[�������s�w��
		static bool m_isInitialized;//�������ς�
		static color_t m_nowForeColor[color::targetNum];//���݂̃J���[�F�O�ʁi�L���p�j
		static color_t m_nowBackColor[color::targetNum];//���݂̃J���[�F�w�ʁi�L���p�j
	#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
		static handle_t m_handle[color::targetNum];//�n���h��
		static CONSOLE_SCREEN_BUFFER_INFO m_ConsoleScreenBufferInfo[color::targetNum];//�R���\�[���X�N���[���o�b�t�@�i���Z�b�g�p�j
	#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p	
		static const handle_t m_handle[color::targetNum];//�n���h��
	#endif//USE_WINDOWS_CONSOLE_COLOR
	};
	//----------------------------------------
	//�J���[�̐ÓI�ϐ����C���X�^���X��
	bool color::m_isInitialized = false;
	color::color_t color::m_nowForeColor[color::targetNum] =//���݂̃J���[�F�O�ʁi�L���p�j
	{
		color::reset,//�W���o�͗p
		color::reset,//�W���G���[�p
	};
	color::color_t color::m_nowBackColor[color::targetNum] =//���݂̃J���[�F�w�ʁi�L���p�j
	{
		color::reset,//�W���o�͗p
		color::reset,//�W���G���[�p
	};
#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
	color::handle_t color::m_handle[color::targetNum];
	CONSOLE_SCREEN_BUFFER_INFO color::m_ConsoleScreenBufferInfo[color::targetNum];//Windows�p�̃��Z�b�g�p�J���[���
#else//USE_WINDOWS_CONSOLE_COLOR//�G�X�P�[�v�V�[�P���X�p
	const color::handle_t color::m_handle[] =
	{
		stdout,//�W���o�̓n���h��
		stderr,//�W���G���[�n���h��
	};
#endif//USE_WINDOWS_CONSOLE_COLOR
	//----------------------------------------
	//�R���\�[���J���[�������i������j
	void color::initializeOnce()
	{
		//�������ς݃`�F�b�N
		if (m_isInitialized)
			return;
		//�ÓI�ϐ���������
		m_isInitialized = true;
#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows�p
		//�n���h��
		m_handle[stdOut] = GetStdHandle(STD_OUTPUT_HANDLE);//�W���o�̓n���h��
		m_handle[stdErr] = GetStdHandle(STD_ERROR_HANDLE);//�W���G���[�n���h��
		//�J���[�ύX�J�n
		GetConsoleScreenBufferInfo(m_handle[stdOut], &m_ConsoleScreenBufferInfo[stdOut]);
		GetConsoleScreenBufferInfo(m_handle[stdErr], &m_ConsoleScreenBufferInfo[stdErr]);
#endif//USE_WINDOWS_CONSOLE_COLOR
	}
	//----------------------------------------
	//�R���\�[���J���[�p�ϐ�
	static color s_colorForInitialize;//�������������s�̂��߂̃C���X�^���X

	//----------------------------------------
	//���x���N���X
	class level
	{
	public:
		//�^
		typedef unsigned char value_t;//�l�i���x���j
		typedef unsigned char byte;//�o�b�t�@�p
	private:
		//�萔�i�v�Z�p�j
		#define calcAsOutput(value) ((value) >> 1)//�l���o�̓��x���ɕϊ�
		#define calcAsValue(value) ((value) << 1)//�o�̓��x����l�ɕϊ�
	public:
		//�萔
		static const value_t NORMAL_NUM = 11;//�ʏ탌�x����
		static const value_t SPECIAL_NUM = 2;//���ꃌ�x����
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;//���x������
		static const value_t MIN = 0;//���x���ŏ��l
		static const value_t MAX = NUM - 1;//���x���ő�l
		static const value_t NORMAL_MIN = MIN;//�ʏ탌�x���ŏ��l
		static const value_t NORMAL_MAX = NORMAL_MIN + NORMAL_NUM - 1;//�ʏ탌�x���ő�l
		static const value_t SPECIAL_MIN = NORMAL_MAX + 1;//���ꃌ�x���ŏ��l
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//���ꃌ�x���ő�l
		static const value_t BEGIN = MIN;//���x���J�n�l�i�C�e���[�^�p�j
		static const value_t END = NUM;//���x���I�[�l�i�C�e���[�^�p�j
		static const value_t POOL_NUM = NUM + 1;//���x���L�^��
		static const value_t OUTPUT_LEVEL_MIN = calcAsOutput(NORMAL_MIN);//�o�̓��x���ŏ��l
		static const value_t OUTPUT_LEVEL_MAX = calcAsOutput(NORMAL_MAX);//�o�̓��x���ő�l
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
			operator const level&() const { return container::get(m_value); }//�l�i���x���j
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
			static const value_t endValue(){ return END; }//�I�[�l�擾
			static const level& get(const value_t value){ return m_poolPtr[value]; }//�v�f���擾
			static const level& getBegin(){ return m_poolPtr[beginValue()]; }//�J�n�v�f���擾
			static const level& getEnd(){ return m_poolPtr[endValue()]; }//�I�[�v�f���擾
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
			static const iterator end()	{ return iterator(endValue()); }//�I�[�C�e���[�^���擾
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//�J�nconst�C�e���[�^���擾
			static const_iterator cend(){ return const_iterator(endValue()); }//�I�[const�C�e���[�^���擾
			//��reverse_iterator��Ή�
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
		bool operator ==(const level& rhs) const { return valueAsOutput() == rhs.valueAsOutput(); }
		bool operator !=(const level& rhs) const { return valueAsOutput() != rhs.valueAsOutput(); }
		bool operator >(const level& rhs) const { return valueAsOutput() > rhs.valueAsOutput(); }
		bool operator >=(const level& rhs) const { return valueAsOutput() >= rhs.valueAsOutput(); }
		bool operator <(const level& rhs) const { return valueAsOutput() < rhs.valueAsOutput(); }
		bool operator <=(const level& rhs) const { return valueAsOutput() <= rhs.valueAsOutput(); }
	private:
		//�R�s�[�I�y���[�^
		level& operator=(const level& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//�L���X�g�I�y���[�^
		operator int() const { return static_cast<int>(m_value); }//�l�i���x���j
		operator value_t() const { return m_value; }//�l�i���x���j
		operator const char*() const { return m_name; }//���O
	public:
		//�A�N�Z�b�T
		value_t value() const { return m_value; }//�l�i���x���j�擾
		const char* name() const { return m_name; }//���O�擾
		static value_t calcValueAsOutput(const value_t value){ return calcAsOutput(value); }//�o�̓��x���v�Z
		value_t valueAsOutput() const { return calcAsOutput(m_value); }//�o�̓��x���擾
		bool forLog() const { return m_forLog; }//���O���x���Ƃ��Ďg�p�\���H
		bool forNotice() const { return m_forNotice; }//��ʒʒm���x���Ƃ��Ďg�p�\���H
		bool forMask() const { return m_forMask; }//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
		color getColor() const { return std::move(changeColor(true)); }//�J���[�擾
		color getColorForNotice() const { return std::move(changeColorForNotice(true)); }//�J���[�擾�i��ʒʒm�p�j
	public:
		//���\�b�h
		//�J���[�ύX
		//���߂�l�󂯎��K�{
		//�@�߂�l���󂯎��Ȃ��Ƃ����Ƀf�X�g���N�^�����s����Č��̃J���[�ɖ߂�̂Ŏ��ۂɔ��f����Ȃ�
		color changeColor(const bool is_only_get = false) const
		{
			return std::move(color(color::stdOut, m_foreColor, m_backColor, !is_only_get));
		}
		//�J���[�ύX�i��ʒʒm�p�j
		//���߂�l�󂯎��K�{
		//�@�߂�l���󂯎��Ȃ��Ƃ����Ƀf�X�g���N�^�����s����Č��̃J���[�ɖ߂�̂Ŏ��ۂɔ��f����Ȃ�
		color changeColorForNotice(const bool is_only_get = false) const
		{
			return std::move(color(color::stdErr, m_foreColorForNotice, m_backColorForNotice, !is_only_get));
		}
		//�R���e�i�v�f���擾�i�V���[�g�J�b�g�p�j
		static const level& get(const value_t value){ return container::get(value); }
		//�O�̃��x�����擾
		const level& prev() const
		{
			if (valueAsOutput() <= OUTPUT_LEVEL_MIN || valueAsOutput() > OUTPUT_LEVEL_MAX || !(m_forLog || m_forNotice))
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcAsValue(calcAsOutput(m_value) - 1)];
		}
		//���̃��x�����擾
		const level& next() const
		{
			if (valueAsOutput() < OUTPUT_LEVEL_MIN || valueAsOutput() >= OUTPUT_LEVEL_MAX || !(m_forLog || m_forNotice))
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcAsValue(calcAsOutput(m_value) + 1)];
		}
	public:
		//�f�t�H���g�R���X�g���N�^
		level() :
			m_name(nullptr),
			m_value(UCHAR_MAX),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false),
			m_foreColor(color::through),
			m_backColor(color::through),
			m_foreColorForNotice(color::through),
			m_backColorForNotice(color::through)
		{
			container::initializeOnce();//�R���e�i�������i������j
		}
		//�R�s�[�R���X�g���N�^
		level(const level& src) :
			m_name(src.m_name),
			m_value(src.m_value),
			m_forLog(src.m_forLog),
			m_forNotice(src.m_forNotice),
			m_forMask(src.m_forMask),
			m_foreColor(src.m_foreColor),
			m_backColor(src.m_backColor),
			m_foreColorForNotice(src.m_foreColorForNotice),
			m_backColorForNotice(src.m_backColorForNotice)
		{
		}
		//�R���X�g���N�^
		level(const value_t value, const char* name, const bool for_log, const bool for_notice, const bool for_mask, const color::color_t fore_color, const color::color_t back_color, const color::color_t fore_color_for_notice, const color::color_t back_color_for_notice) :
			m_name(name),
			m_value(value),
			m_forLog(for_log),
			m_forNotice(for_notice),
			m_forMask(for_mask),
			m_foreColor(fore_color),
			m_backColor(back_color),
			m_foreColorForNotice(fore_color_for_notice),
			m_backColorForNotice(back_color_for_notice)
		{
			assert(value >= BEGIN && value <= END);
			container::set(m_value, *this);//�R���e�i�ɓo�^
		}
		level(const value_t value) :
			m_name(nullptr),
			m_value(value),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false),
			m_foreColor(color::through),
			m_backColor(color::through),
			m_foreColorForNotice(color::through),
			m_backColorForNotice(color::through)
		{
			assert(value >= BEGIN && value <= END);
			*this = container::get(m_value);//�R���e�i����擾���Ď��g�ɃR�s�[
		}
		//�f�X�g���N�^
		~level()
		{}
	private:
		const char* m_name;//���O
		const value_t m_value;//�l�i���x���j
		const bool m_forLog;//���O�o�̓��x���Ƃ��Ďg�p�\���H
		const bool m_forNotice;//��ʒʒm���x���Ƃ��Ďg�p�\���H
		const bool m_forMask;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
		const color::color_t m_foreColor;//�J���[�F�O��
		const color::color_t m_backColor;//�J���[�F�w��
		const color::color_t m_foreColorForNotice;//�J���[�F�O�ʁi��ʒʒm�p�j
		const color::color_t m_backColorForNotice;//�J���[�F�w�ʁi��ʒʒm�p�j
	private:
		//�}�N������
#ifndef ENABLE_CONSTEXPR
#undef calcAsOutput
#undef calcAsValue
#endif//ENABLE_CONSTEXPR
	};
	//----------------------------------------
	//���x����`�p�e���v���[�g�N���X�F�ʏ탌�x���p
	template<unsigned char V, bool for_log, bool for_notice, color::color_t fore_color, color::color_t back_color, color::color_t fore_color_for_notice, color::color_t back_color_for_notice>
	class level_normal : public level
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i���x���j
		static_assert(VALUE >= NORMAL_MIN && VALUE <= NORMAL_MAX, "out of range of level");//�l�͈̔̓`�F�b�N
		static const bool FOR_LOG = for_log;//���O���x���Ƃ��Ďg�p�\���H
		static const bool FOR_NOTICE = for_notice;//��ʒʒm���x���Ƃ��Ďg�p�\���H
		static const bool FOR_MASK = true;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
		static const color::color_t FORE_COLOR = fore_color;//�J���[�F�O��
		static const color::color_t BACK_COLOR = back_color;//�J���[�F�w��
		static const color::color_t FORE_COLOR_FOR_NOTICE = fore_color_for_notice;//�J���[�F�O�ʁi��ʒʒm�p�j
		static const color::color_t BACK_COLOR_FOR_NOTICE = back_color_for_notice;//�J���[�F�w�ʁi��ʒʒm�p�j
	public:
		//�R���X�g���N�^
		level_normal(const char* name) :
			level(VALUE, name, FOR_LOG, FOR_NOTICE, FOR_MASK, FORE_COLOR, BACK_COLOR, FORE_COLOR_FOR_NOTICE, BACK_COLOR_FOR_NOTICE)
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
		static const bool FOR_LOG = false;//���O���x���Ƃ��Ďg�p�\���H
		static const bool FOR_NOTICE = false;//��ʒʒm���x���Ƃ��Ďg�p�\���H
		static const bool FOR_MASK = true;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	public:
		//�R���X�g���N�^
		level_special(const char* name) :
			level(VALUE, name, FOR_LOG, FOR_NOTICE, FOR_MASK, color::through, color::through, color::through, color::through)
		{}
	};
	//----------------------------------------
	//���x����`�N���X�F�I�[�p
	class level_end : public level
	{
	public:
		//�萔
		static const value_t VALUE = END;//�l�i���x���j
		static const bool FOR_LOG = false;//���O���x���Ƃ��Ďg�p�\���H
		static const bool FOR_NOTICE = false;//��ʒʒm���x���Ƃ��Ďg�p�\���H
		static const bool FOR_MASK = false;//�o�̓��x���}�X�N�Ƃ��Ďg�p�\���H
	public:
		//�R���X�g���N�^
		level_end() :
			level(VALUE, "(END)", FOR_LOG, FOR_NOTICE, FOR_MASK, color::through, color::through, color::through, color::through)
		{}
	};
	//----------------------------------------
	//���x���萔
#define define_normalLevel(print_level, sub) (level::NORMAL_MIN + print_level * 2 + sub)
#define define_specialLevel(value) (level::SPECIAL_MIN + value)
	enum levelEnum : level::value_t
	{
		asNormal = define_normalLevel(1, 0),//�ʏ탁�b�Z�[�W
		asVerbose = define_normalLevel(0, 0),//�璷���b�Z�[�W
		asDetail = define_normalLevel(0, 1),//�ڍ׃��b�Z�[�W
		asImportant = define_normalLevel(2, 0),//�d�v���b�Z�[�W
		asWarning = define_normalLevel(3, 0),//�x�����b�Z�[�W
		asCritical = define_normalLevel(4, 0),//�d�僁�b�Z�[�W
		asAbsolute = define_normalLevel(5, 0),//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
		//�ȉ��A���O���x���^��ʒʒm���x���ύX�p
		asSilent = define_specialLevel(0),//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
		asSilentAbsolutely = define_specialLevel(1),//��ΐÎ�i�S�Ẵ��b�Z�[�W���o�͂��Ȃ��j
	};
	//----------------------------------------
	//���x����`
#define declare_normalLevel(value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice) struct level_##value : public level_normal<value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice>{ level_##value () :level_normal<value, for_log, for_notice, fore_color, back_color, fore_color_for_notice, back_color_for_notice>(#value){} }
#define declare_specialLevel(value) struct level_##value : public level_special<value>{ level_##value () :level_special<value>(#value){} }
	//���ȉ��A�w�b�_�[�Ō��J����K�v�Ȃ�
	declare_normalLevel(asNormal, true, true, color::reset, color::reset, color::black, color::iWhite);//�ʏ탁�b�Z�[�W
	declare_normalLevel(asVerbose, true, false, color::iBlack, color::black, color::iBlack, color::iWhite);//�璷���b�Z�[�W
	declare_normalLevel(asDetail, true, false, color::iBlack, color::black, color::iBlack, color::iWhite);//�ڍ׃��b�Z�[�W
	declare_normalLevel(asImportant, true, true, color::iBlue, color::black, color::iBlue, color::iWhite);//�d�v���b�Z�[�W
	declare_normalLevel(asWarning, true, true, color::iMagenta, color::black, color::black, color::iMagenta);//�x�����b�Z�[�W
	declare_normalLevel(asCritical, true, true, color::iRed, color::black, color::iYellow, color::iRed);//�d�僁�b�Z�[�W
	declare_normalLevel(asAbsolute, true, false, color::through, color::through, color::through, color::through);//��΃��b�Z�[�W�i���O���x���Ɋ֌W�Ȃ��o�͂��������b�Z�[�W�j
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
			level(value, "(undefined)", false, false, false, color::through, color::through, color::through, color::through);
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
	//���x���p�ϐ�
	static level s_levelForInitialize;//�������������s�̂��߂̃C���X�^���X
	//----------------------------------------
	//���x���R���e�i��
	void printLevelAll()
	{
		for (auto& obj : level::container())//C++11�X�^�C��
		//for (auto ite = level::container::begin(); ite != level::container::end(); ++ite)//�����̃X�^�C��
		//for (auto ite = level::container::cbegin(); ite != level::container::cend(); ++ite)//�����̃X�^�C��
		{
			//const level& obj = ite;//�C�e���[�^��ϊ��i�C�e���[�^�̂܂܂ł��A���[���Z�q�Œ��ڒl����\�j
			color col(obj.changeColor());
			fprintf(stdout, "level=%d, name=\"%s\", valueAsOutput=%d, forLog=%d, forNotice=%d, forMask=%d\n", obj.value(), obj.name(), obj.valueAsOutput(), obj.forLog(), obj.forNotice(), obj.forMask());
			auto& prev = obj.prev();
			auto& next = obj.next();
			fprintf(stdout, "           prev=%s(%d)\n", prev.name(), prev.value());
			fprintf(stdout, "           next=%s(%d)\n", next.name(), next.value());
		}
	}

	//----------------------------------------
	//�J�e�S���N���X
	class category
	{
	public:
		//�^
		typedef unsigned char value_t;//�l�i�J�e�S���j
		typedef unsigned char byte;//�o�b�t�@�p
	public:
		//�萔
		static const value_t NORMAL_NUM = 64;//�ʏ�J�e�S����
		static const value_t ASSIGNED_NUM = 8;//���蓖�čς݃J�e�S����
		static const value_t RESERVED_NUM = NORMAL_NUM - ASSIGNED_NUM;//�\��J�e�S����
		static const value_t SPECIAL_NUM = 3;//����J�e�S����
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;//�J�e�S������
		static const value_t MIN = 0;//�J�e�S���ŏ��l
		static const value_t MAX = NUM - 1;//�J�e�S���ő�l
		static const value_t NORMAL_MIN = MIN;//�ʏ�J�e�S���ŏ��l
		static const value_t NORMAL_MAX = NORMAL_MIN + NORMAL_NUM - 1;//�ʏ�J�e�S���ő�l
		static const value_t ASSIGNED_MIN = NORMAL_MIN;//���蓖�čς݃J�e�S���ŏ��l
		static const value_t ASSIGNED_MAX = ASSIGNED_MIN + ASSIGNED_NUM - 1;//���蓖�čς݃J�e�S���ő�l
		static const value_t RESERVED_MIN = ASSIGNED_MAX + 1;//�\��J�e�S���ŏ��l
		static const value_t RESERVED_MAX = RESERVED_MIN + RESERVED_NUM - 1;//�\��J�e�S���ő�l
		static const value_t SPECIAL_MIN = NORMAL_MAX + 1;//����J�e�S���ŏ��l
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//����J�e�S���ő�l
		static const value_t BEGIN = MIN;//�J�e�S���J�n�l�i�C�e���[�^�p�j
		static const value_t END = NUM;//�J�e�S���I�[�l�i�C�e���[�^�p�j
		static const value_t POOL_NUM = NUM + 1;//�J�e�S���L�^��
		static_assert(NORMAL_MAX == RESERVED_MAX, "invalid category numbers.");//�萔�`�F�b�N
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");//�萔�`�F�b�N
	public:
		//�^
		//--------------------
		//�C�e���[�^
		class iterator : public std::iterator<std::bidirectional_iterator_tag, category>//�o�����C�e���[�^�Ƃ��Ď���
		{
		public:
			//�I�y���[�^
			const category* operator->() const { return &container::get(m_value); }
			const category& operator*() const { return container::get(m_value); }
			bool operator==(const iterator rhs) const { return m_value == rhs.m_value; }
			bool operator!=(const iterator rhs) const { return m_value != rhs.m_value; }
			const category& operator++() const { return m_value >= container::endValue() ? container::getEnd() : container::get(++m_value); }
			const category& operator++(int) const { return m_value >= container::endValue() ? container::getEnd() : container::get(m_value++); }
			const category& operator--() const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getEnd(); } return container::get(--m_value); }
			const category& operator--(int) const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getBegin(); } return container::get(m_value--); }
		public:
			//�L���X�g�I�y���[�^
			operator const category&() const { return container::get(m_value); }//�l�i�J�e�S���j
		public:
			//�R���X�g���N�^
			iterator(const value_t value) :
				m_value(value)
			{}
			iterator(const value_t value, int) :
				m_value(container::endValue())
			{}
			iterator(const category& obj) :
				m_value(obj.value())
			{}
			iterator(const category& obj, int) :
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
			value_t mutable m_value;//�l�i�J�e�S���j
		};
		//--------------------
		//const�C�e���[�^
		typedef const iterator const_iterator;
		//--------------------
		//�R���e�i�i�C�e���[�^�p�j
		class container
		{
			friend class category;
		public:
			//���\�b�h
			static const value_t beginValue(){ return BEGIN; }//�J�n�l�擾
			static const value_t endValue(){ return END; }//�I�[�l�擾
			static const category& get(const value_t value){ return m_poolPtr[value]; }//�v�f���擾
			static const category& getBegin(){ return m_poolPtr[beginValue()]; }//�J�n�v�f���擾
			static const category& getEnd(){ return m_poolPtr[endValue()]; }//�I�[�v�f���擾
		private:
			static void set(const value_t value, const category& obj)//�v�f���X�V
			{
				if (!container::m_isAlreadyPool[value])
				{
					container::m_poolPtr[value] = obj;
					container::m_isAlreadyPool[value] = true;
				}
			}
		public:
			static const iterator begin(){ return iterator(beginValue()); }//�J�n�C�e���[�^���擾
			static const iterator end()	{ return iterator(endValue()); }//�I�[�C�e���[�^���擾
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//�J�nconst�C�e���[�^���擾
			static const_iterator cend(){ return const_iterator(endValue()); }//�I�[const�C�e���[�^���擾
			//��reverse_iterator��Ή�
			//���\�b�h
			//�������i������j
			static void initializeOnce();
		private:
			//�t�B�[���h
			static bool m_isInitialized;//�������ς�
			static category* m_poolPtr;//�v�f�̃v�[���i�|�C���^�j
			static byte m_pool[];//�v�f�̃v�[���i�o�b�t�@�j���o�b�t�@�ƃ|�C���^�𕪂��Ă���̂́A�R���X�g���N�^�̎��s��h�~���邽��
			static std::bitset<POOL_NUM> m_isAlreadyPool;//�v�f�̏������ς݃t���O
		};
	public:
		//�I�y���[�^
		bool operator ==(const category& rhs) const { return m_value == rhs.m_value; }
		bool operator !=(const category& rhs) const { return m_value != rhs.m_value; }
	private:
		//�R�s�[�I�y���[�^
		category& operator=(const category& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//�L���X�g�I�y���[�^
		operator int() const { return static_cast<int>(m_value); }//�l�i�J�e�S���j
		operator value_t() const { return m_value; }//�l�i�J�e�S���j
		operator const char*() const { return m_name; }//���O
	public:
		//�A�N�Z�b�T
		value_t value() const { return m_value; }//�l�i�J�e�S���j�擾
		const char* name() const { return m_name; }//���O�擾
		bool isAssigned() const { return m_isAssigned; }//���蓖�čς݃J�e�S�����H
		bool isReserved() const { return !m_isAssigned; }//�\��J�e�S�����H
		bool forLog() const { return m_forLog; }//���O�o�͉\���H
		bool forNotice() const { return m_forNotice; }//��ʒʒm�\���H
		bool forMask() const { return m_forMask; }//�o�̓��x���}�X�N�\���H
	public:
		//���\�b�h
		//�R���e�i�v�f���擾�i�V���[�g�J�b�g�p�j
		static const category& get(const value_t value){ return container::get(value); }
	public:
		//�f�t�H���g�R���X�g���N�^
		category() :
			m_name(nullptr),
			m_value(UCHAR_MAX),
			m_isAssigned(false),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false)
		{
			container::initializeOnce();//�R���e�i�������i������j
		}
		//�R�s�[�R���X�g���N�^
		category(const category& src) :
			m_name(src.m_name),
			m_value(src.m_value),
			m_isAssigned(src.m_isAssigned),
			m_forLog(src.m_forLog),
			m_forNotice(src.m_forNotice),
			m_forMask(src.m_forMask)
		{
		}
		//�R���X�g���N�^
		category(const value_t value, const char* name, const bool is_assigned, const bool for_log, const bool for_notice, const bool for_mask) :
			m_name(name),
			m_value(value),
			m_isAssigned(is_assigned),
			m_forLog(for_log),
			m_forNotice(for_notice),
			m_forMask(for_mask)
		{
			assert(value >= BEGIN && value <= END);
			container::set(m_value, *this);//�R���e�i�ɓo�^
		}
		category(const value_t value) :
			m_name(nullptr),
			m_value(value),
			m_isAssigned(false),
			m_forLog(false),
			m_forNotice(false),
			m_forMask(false)
		{
			assert(value >= BEGIN && value <= END);
			*this = container::get(m_value);//�R���e�i����擾���Ď��g�ɃR�s�[
		}
		//�f�X�g���N�^
		~category()
		{}
	private:
		const char* m_name;//���O
		const value_t m_value;//�l�i�J�e�S���j
		const bool m_isAssigned;//���蓖�čς݃J�e�S�����H
		const bool m_forLog;//���O�o�͉\���H
		const bool m_forNotice;//��ʒʒm�\���H
		const bool m_forMask;//�o�̓��x���}�X�N�\���H
	};
	//----------------------------------------
	//�J�e�S����`�p�e���v���[�g�N���X�F���蓖�čς݃J�e�S���p
	template<unsigned char V, bool for_log, bool for_notice>
	class category_assigned : public category
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i�J�e�S���j
		static_assert(VALUE >= ASSIGNED_MIN && VALUE <= ASSIGNED_MAX, "out of range of category");//�l�͈̔̓`�F�b�N
		static const bool IS_ASSIGNED = true;//���蓖�čς݃J�e�S�����H
		static const bool FOR_LOG = for_log;//���O�o�͉\���H
		static const bool FOR_NOTICE = for_notice;//��ʒʒm�\���H
		static const bool FOR_MASK = true;//�o�̓��x���}�X�N�\���H
	public:
		//�R���X�g���N�^
		category_assigned(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//�J�e�S����`�p�e���v���[�g�N���X�F�\��J�e�S���p
	template<unsigned char V, bool for_log, bool for_notice>
	class category_reserved: public category
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i�J�e�S���j
		static_assert(VALUE >= RESERVED_MIN && VALUE <= RESERVED_MAX, "out of range of category");//�l�͈̔̓`�F�b�N
		static const bool IS_ASSIGNED = false;//���蓖�čς݃J�e�S�����H
		static const bool FOR_LOG = for_log;//���O�o�͉\���H
		static const bool FOR_NOTICE = for_notice;//��ʒʒm�\���H
		static const bool FOR_MASK = true;//�o�̓��x���}�X�N�\���H
	public:
		//�R���X�g���N�^
		category_reserved(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//�J�e�S����`�p�e���v���[�g�N���X�F����J�e�S���p
	template<unsigned char V, bool for_log, bool for_notice, bool for_mask>
	class category_special : public category
	{
	public:
		//�萔
		static const value_t VALUE = V;//�l�i�J�e�S���j
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of category");//�l�͈̔̓`�F�b�N
		static const bool IS_ASSIGNED = true;//���蓖�čς݃J�e�S�����H
		static const bool FOR_LOG = for_log;//���O�o�͉\���H
		static const bool FOR_NOTICE = for_notice;//��ʒʒm�\���H
		static const bool FOR_MASK = for_mask;//�o�̓��x���}�X�N�\���H
	public:
		//�R���X�g���N�^
		category_special(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//�J�e�S����`�N���X�F�I�[�p
	class category_end : public category
	{
	public:
		//�萔
		static const value_t VALUE = END;//�l�i�J�e�S���j
		static const bool IS_ASSIGNED = true;//���蓖�čς݃J�e�S�����H
		static const bool FOR_LOG = false;//���O�o�͉\���H
		static const bool FOR_NOTICE = false;//��ʒʒm�\���H
		static const bool FOR_MASK = false;//�o�̓��x���}�X�N�\���H
	public:
		//�R���X�g���N�^
		category_end() :
			category(VALUE, "(END)", IS_ASSIGNED, FOR_LOG, FOR_NOTICE, FOR_MASK)
		{}
	};
	//----------------------------------------
	//�J�e�S���萔
#define define_assignedCategory(value) (category::ASSIGNED_MIN + value)
#define define_revervedCategory(value) (category::RESERVED_MIN + value)
#define define_specialCategory(value) (category::SPECIAL_MIN + value)
	enum categoryEnum : category::value_t
	{
		forAny = define_assignedCategory(0),//�Ȃ�ł��i�J�e�S���Ȃ��j
		forLogic = define_assignedCategory(1),//�v���O�����֌W
		forResource = define_assignedCategory(2),//���\�[�X�֌W
		for3D = define_assignedCategory(3),//3D�O���t�B�b�N�X�֌W
		for2D = define_assignedCategory(4),//2D�O���t�B�b�N�X�֌W
		forSound = define_assignedCategory(5),//�T�E���h�֌W
		forScript = define_assignedCategory(6),//�X�N���v�g�֌W
		forGameData = define_assignedCategory(7),//�Q�[���f�[�^�֌W
		//���O���x���^��ʒʒm���x���ύX�p
		forEvery = define_specialCategory(0),//�S���܂Ƃ߂ĕύX
		//����ȃJ�e�S���i�v�����g����p�j
		forCallPoint = define_specialCategory(1),//���߂̃R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
		forCriticalCallPoint = define_specialCategory(2),//���߂̏d��R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
	};
	//----------------------------------------
	//�J�e�S����`
#define declare_assignedCategory(value, for_log, for_notice) struct category_##value : public category_assigned<value, for_log, for_notice>{ category_##value () :category_assigned<value, for_log, for_notice>(#value){} }
#define declare_reservedCategory(value, for_log, for_notice) struct category_##value : public category_reserved<value, for_log, for_notice>{ category_##value () :category_reserved<value, for_log, for_notice>(#value){} }
#define declare_specialCategory(value, for_log, for_notice, for_mask) struct category_##value : public category_special<value, for_log, for_notice, for_mask>{ category_##value () :category_special<value, for_log, for_notice, for_mask>(#value){} }
	//���ȉ��A�w�b�_�[�Ō��J����K�v�Ȃ�
	declare_assignedCategory(forAny, true, true);//�Ȃ�ł��i�J�e�S���Ȃ��j
	declare_assignedCategory(forLogic, true, true);//�v���O�����֌W
	declare_assignedCategory(forResource, true, true);//���\�[�X�֌W
	declare_assignedCategory(for3D, true, true);//3D�O���t�B�b�N�X�֌W
	declare_assignedCategory(for2D, true, true);//2D�O���t�B�b�N�X�֌W
	declare_assignedCategory(forSound, true, true);//�T�E���h�֌W
	declare_assignedCategory(forScript, true, true);//�X�N���v�g�֌W
	declare_assignedCategory(forGameData, true, true);//�Q�[���f�[�^�֌W
	//���O���x���^��ʒʒm���x���ύX�p
	declare_specialCategory(forEvery, false, false, true);//�S���܂Ƃ߂ĕύX
	//����ȃJ�e�S���i�v�����g����p�j
	declare_specialCategory(forCallPoint, true, true, false);//���߂̃R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
	declare_specialCategory(forCriticalCallPoint, true, true, false);//���߂̏d��R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j

	//----------------------------------------
	//�J�e�S���R���e�i�̐ÓI�ϐ����C���X�^���X��
	bool category::container::m_isInitialized = false;
	category* category::container::m_poolPtr = nullptr;
	category::byte category::container::m_pool[(POOL_NUM)* sizeof(category)];
	std::bitset<category::POOL_NUM> category::container::m_isAlreadyPool;
	//----------------------------------------
	//�J�e�S���R���e�i�������i������j
	void category::container::initializeOnce()
	{
		//�������ς݃`�F�b�N
		if (m_isInitialized)
			return;
		//�ÓI�ϐ���������
		m_isInitialized = true;
		m_isAlreadyPool.reset();
		memset(m_pool, 0, sizeof(m_pool));
		m_poolPtr = reinterpret_cast<category*>(m_pool);
		//�v�f��������
		for (category::value_t value = 0; value < category::NUM; ++value)
		{
			category(value, "(undefined)", false, false, false, false);
			m_isAlreadyPool[value] = false;
		}
		//���蓖�čς݃J�e�S����ݒ�i�R���X�g���N�^�ŗv�f��o�^�j
		category_forAny();//�Ȃ�ł��i�J�e�S���Ȃ��j
		category_forLogic();//�v���O�����֌W
		category_forResource();//���\�[�X�֌W
		category_for3D();//3D�O���t�B�b�N�X�֌W
		category_for2D();//2D�O���t�B�b�N�X�֌W
		category_forSound();//�T�E���h�֌W
		category_forScript();//�X�N���v�g�֌W
		category_forGameData();//�Q�[���f�[�^�֌W
		//���O���x���^��ʒʒm���x���ύX�p
		category_forEvery();//�S���܂Ƃ߂ĕύX
		//����ȃJ�e�S���i�v�����g����p�j
		category_forCallPoint();//���߂̃R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
		category_forCriticalCallPoint();//���߂̏d��R�[���|�C���g�̃J�e�S���ɍ��킹��i�Ȃ����forAny�����j
		category_end();//�I�[
	}
	//----------------------------------------
	//�J�e�S���p�ϐ�
	static category s_categoryForInitialize;//�������������s�̂��߂̃C���X�^���X
	//----------------------------------------
	//�J�e�S���R���e�i��
	void printCategoryAll()
	{
		for (auto& obj : category::container())//C++11�X�^�C��
		//for (auto ite = category::container::begin(); ite != category::container::end(); ++ite)//�����̃X�^�C��
		//for (auto ite = category::container::cbegin(); ite != category::container::cend(); ++ite)//�����̃X�^�C��
		{
			//const category& obj = ite;//�C�e���[�^��ϊ��i�C�e���[�^�̂܂܂ł��A���[���Z�q�Œ��ڒl����\�j
			printf("category=%d, name=\"%s\", isAssigned=%d, isReserved=%d, forLog=%d, forNotice=%d, forMask=%d\n", obj.value(), obj.name(), obj.isAssigned(), obj.isReserved(), obj.forLog(), obj.forNotice(), obj.forMask());
		}
	}

	//----------------------------------------
	//���b�Z�[�W�N���X
	class message
	{
	public:
		//�萔
		static const level::value_t DEFAULT_LOG_LEVEL = asNormal;//�f�t�H���g���O���x��
		static const level::value_t DEFAULT_NOTOICE_LEVEL = asCritical;//�f�t�H���g��ʒʒm���x��
	public:
		//�A�N�Z�b�T
		level::value_t getLevel() const { return m_level; }//���x���擾
		category::value_t getCategory() const { return m_category; }//�J�e�S���擾
		const char* getName() const { return m_name; }//�������擾
		const char* getSrcFileName() const { return getFileName(m_srcFilename); }//�\�[�X�t�@�C�����擾
		const char* getFuncname() const { return m_funcName; }//�֐����擾
	public:
		//���\�b�h
		//���O���x���������i������j
		static void initializeOnce();
		//�K�؂ȃJ�e�S���ɒ���
		//��forCallPoint, forCriticalCallPoint�Ɋ�Â��ϊ�
		static category::value_t adjustProperCategory(const category::value_t category_)
		{
			if (category_ == forCallPoint)//���O�̃R�[���|�C���g�̃J�e�S��
			{
				if (m_callPointStackHead)
					return m_callPointStackHead->getCategory();
				return forAny;//�R�[���|�C���g���Ȃ���� forAny ����
			}
			else if (category_ == forCriticalCallPoint)//���߂̃N���e�B�J���R�[���|�C���g�̃J�e�S��
			{
				message* node = m_callPointStackHead;
				while (node)
				{
					if (node->getLevel() == asCritical)
						return node->getCategory();
					node = node->m_callPointStackNext;
				}
				return forAny;//�R�[���|�C���g���Ȃ���� forAny ����
			}
			return category_;
		}
		//���݂̃��O���x�����擾
		static level::value_t getLogLevelG(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true);
			return m_logLevelG[category_];
		}
		//�y�ꎞ���O���x���Łz
		level::value_t getLogLevel(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forLog() == true);
			return level::calcValueAsOutput(m_logLevelG[category_]) > level::calcValueAsOutput(m_logLevel[category_]) ?
				m_logLevelG[category_] ://�{���̃��x�����Ⴂ���x���͈����Ȃ�
				m_logLevel[category_];
		}
		//�y�R�[���|�C���g�Łz
		static level::value_t getLogLevelCP(const category::value_t category_)
		{
			if (!m_callPointStackHead)
				return getLogLevelG(category_);//�R�[���|�C���g����������ʏ�̃��O���x��
			return m_callPointStackHead->getLogLevel(category_);
		}
		//���݂̃��O���x����ύX
		//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
		//���ύX�O�̃��O���x����Ԃ��iforEvery�w�莞��forAny�̃��O���x����Ԃ��j
		static level::value_t setLogLevelG(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			if (category_ == forEvery)
			{
				const level::value_t prev = m_logLevelG[forAny];
				for (level::value_t& value : m_logLevelG)
					value = level_;
				return prev;
			}
			assert(o_category.forLog() == true);
			const level::value_t prev = m_logLevelG[category_];
			m_logLevelG[category_] = level_;
			return prev;
		}
		//�y�ꎞ���O���x���Łz
		level::value_t setLogLevel(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			if (category_ == forEvery)
			{
				const level::value_t prev = m_logLevel[forAny];
				for (int category_tmp = category::NORMAL_MIN; category_tmp <= category::NORMAL_MAX; ++category_tmp)
				{
					m_logLevel[category_tmp] =
						level::calcValueAsOutput(m_logLevelG[category_tmp]) > level::calcValueAsOutput(level_) ?
							m_logLevelG[category_tmp] ://�{���̃��x�����Ⴍ���邱�Ƃ͂ł��Ȃ�
							level_;
				}
				return prev;
			}
			assert(o_category.forLog() == true);
			const level::value_t prev = m_logLevel[category_];
			m_logLevel[category_] =
				level::calcValueAsOutput(m_logLevelG[category_]) > level::calcValueAsOutput(level_) ?
					m_logLevelG[category_] ://�{���̃��x�����Ⴍ���邱�Ƃ͂ł��Ȃ�
					level_;
			return prev;
		}
		//���݂̃��O���x�������Z�b�g
		static void resetLogLevelG(const category::value_t category_)
		{
			setLogLevelG(DEFAULT_LOG_LEVEL, category_);
		}
		//�y�ꎞ���O���x���Łz
		void resetLogLevel(const category::value_t category_)
		{
			setLogLevel(DEFAULT_LOG_LEVEL, category_);
		}
		//���݂̃��O���x����S�ă��Z�b�g
		static void resetLogLevelAllG()
		{
			//resetLogLevelG(forEvery);//�����������ł��Ăяo�����̂ŁA���ʏ������g�킸�P���ɍX�V
			for (level::value_t& value : m_logLevelG)
				value = DEFAULT_LOG_LEVEL;
		}
		//�y�ꎞ���O���x���Łz
		void resetLogLevelAll()
		{
			resetLogLevel(forEvery);
		}
		//���݂̉�ʒʒm���x�����擾
		static level::value_t getNoticeLevelG(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forNotice() == true);
			return m_noticeLevelG[category_];
		}
		//�y�ꎞ��ʒʒm���x���Łz
		level::value_t getNoticeLevel(const category::value_t category_)
		{
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			assert(o_category.forNotice() == true);
			return level::calcValueAsOutput(m_noticeLevelG[category_]) > level::calcValueAsOutput(m_noticeLevel[category_]) ?
				m_noticeLevelG[category_] ://�{���̃��x�����Ⴂ���x���͈����Ȃ�
				m_noticeLevel[category_];
		}
		//�y�R�[���|�C���g�Łz
		static level::value_t getNoticeLevelCP(const category::value_t category_)
		{
			if (!m_callPointStackHead)
				return getNoticeLevelG(category_);//�R�[���|�C���g����������ʏ�̉�ʒʒm���x��
			return m_callPointStackHead->getNoticeLevel(category_);
		}
		//���݂̉�ʒʒm���x����ύX
		//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
		//���ύX�O�̉�ʒʒm���x����Ԃ��iforEvery�w�莞��forAny�̉�ʒʒm���x����Ԃ��j
		static level::value_t setNoticeLevelG(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			if (category_ == forEvery)
			{
				const level::value_t prev = m_noticeLevelG[forAny];
				for (level::value_t& value : m_noticeLevelG)
					value = level_;
				return prev;
			}
			assert(o_category.forNotice() == true);
			const level::value_t prev = m_noticeLevelG[category_];
			m_noticeLevelG[category_] = level_;
			return prev;
		}
		//�y�ꎞ��ʒʒm���x���Łz
		level::value_t setNoticeLevel(const level::value_t level_, const category::value_t category_)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forMask() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forMask() == true);
			if (category_ == forEvery)
			{
				const level::value_t prev = m_noticeLevel[forAny];
				for (int category_tmp = category::NORMAL_MIN; category_tmp <= category::NORMAL_MAX; ++category_tmp)
				{
					m_noticeLevel[category_tmp] =
						level::calcValueAsOutput(m_noticeLevelG[category_tmp]) > level::calcValueAsOutput(level_) ?
						m_noticeLevelG[category_tmp] ://�{���̃��x�����Ⴍ���邱�Ƃ͂ł��Ȃ�
						level_;
				}
				return prev;
			}
			assert(o_category.forNotice() == true);
			const level::value_t prev = m_noticeLevel[category_];
			m_noticeLevel[category_] =
				level::calcValueAsOutput(m_noticeLevelG[category_]) > level::calcValueAsOutput(level_) ?
				m_noticeLevelG[category_] ://�{���̃��x�����Ⴍ���邱�Ƃ͂ł��Ȃ�
				level_;
			return prev;
		}
		//���݂̉�ʒʒm���x�������Z�b�g
		static void resetNoticeLevelG(const category::value_t category_)
		{
			setNoticeLevelG(DEFAULT_NOTOICE_LEVEL, category_);
		}
		//�y�ꎞ��ʒʒm���x���Łz
		void resetNoticeLevel(const category::value_t category_)
		{
			setNoticeLevel(DEFAULT_NOTOICE_LEVEL, category_);
		}
		//���݂̉�ʒʒm���x����S�ă��Z�b�g
		static void resetNoticeLevelAllG()
		{
			//resetNoticeLevelG(forEvery);//�����������ł��Ăяo�����̂ŁA���ʏ������g�킸�P���ɍX�V
			for (level::value_t& value : m_noticeLevelG)
				value = DEFAULT_NOTOICE_LEVEL;
		}
		//�y�ꎞ��ʒʒm���x���Łz
		void resetNoticeLevelAll()
		{
			resetNoticeLevel(forEvery);
		}
	private:
		//���b�Z�[�W�o�́F���x���������w��
		//��va_list�������ɂƂ�o�[�W����
		static int vprintCommon(const level::value_t log_level, const level::value_t notice_level, const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const level& o_level = level::get(level_);
			assert(o_level.forLog() == true || o_level.forNotice() == true);
			const category& o_category = category::get(category_);
			assert(o_category.forLog() == true || o_category.forNotice() == true);
			int ret1 = 0;
			int ret2 = 0;
			const level& o_log_level = level::get(log_level);
			const level& o_notice_level = level::get(notice_level);
			if (o_level >= o_log_level && o_level.forLog() && o_category.forLog())
			{
				{
					color col(o_level.changeColor());
					fprintf(stdout, "[%s,%s]", o_level.name(), o_category.name());
				}
				fprintf(stdout, " ");
				ret1 = vfprintf(stdout, fmt, args);
			}
			if (o_level >= o_notice_level && o_level.forNotice() && o_category.forNotice())
			{
				color col(o_level.changeColorForNotice());
				ret2 = vfprintf(stderr, fmt, args);
			}
			return ret1 > ret2 ? ret1 : ret2;
		}
	public:
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h�F���x���������w��
		//��vprint***/vlog***/vnotice***
		//��va_list�������ɂƂ�o�[�W����
		static int vprintG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const level::value_t log_level = getLogLevelCP(category_adj);
			const level::value_t notice_level = getNoticeLevelCP(category_adj);
			return vprintCommon(log_level, notice_level, level_, category_, fmt, args);
		}
		int vprint(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const level::value_t log_level = getLogLevel(category_adj);
			const level::value_t notice_level = getNoticeLevel(category_adj);
			return vprintCommon(log_level, notice_level, level_, category_, fmt, args);
		}
		int vprint(const level::value_t level_, const char* fmt, va_list args)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			return vprint(level_, m_category, fmt, args);
		}
		int vprint(const char* fmt, va_list args)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			return vprint(m_level, m_category, fmt, args);
		}
		static int vlogG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const level::value_t log_level = getLogLevelCP(category_adj);
			const level::value_t notice_level = asSilentAbsolutely;
			return vprintCommon(log_level, notice_level, level_, category_, fmt, args);
		}
		int vlog(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//�y�ꎞ���O���x���Łz
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const level::value_t log_level = getLogLevel(category_adj);
			const level::value_t notice_level = asSilentAbsolutely;
			return vprintCommon(log_level, notice_level, level_, category_, fmt, args);
		}
		int vlog(const level::value_t level_, const char* fmt, va_list args)//�y�ꎞ���O���x���Łz
		{
			return vlog (level_, m_category, fmt, args);
		}
		int vlog(const char* fmt, va_list args)//�y�ꎞ���O���x���Łz
		{
			return vlog(m_level, m_category, fmt, args);
		}
		static int vnoticeG(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const level::value_t log_level = asSilentAbsolutely;
			const level::value_t notice_level = getNoticeLevelCP(category_adj);
			return vprintCommon(log_level, notice_level, level_, category_, fmt, args);
		}
		int vnotice(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)//�y�ꎞ��ʒʒm���x���Łz
		{
			const category::value_t category_adj = adjustProperCategory(category_);
			const level::value_t log_level = asSilentAbsolutely;
			const level::value_t notice_level = getNoticeLevel(category_adj);
			return vprintCommon(log_level, notice_level, level_, category_, fmt, args);
		}
		int vnotice(const level::value_t level_, const char* fmt, va_list args)//�y�ꎞ��ʒʒm���x���Łz
		{
			return vnotice(level_, m_category, fmt, args);
		}
		int vnotice(const char* fmt, va_list args)//�y�ꎞ��ʒʒm���x���Łz
		{
			return vnotice(m_level, m_category, fmt, args);
		}
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h�F���x���������w��
		//��print***/log***/notice***
		//���ϒ������o�[�W����
		static int printG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprintG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const level::value_t level_, const char* fmt, ...)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int print(const char* fmt, ...)//�y�ꎞ���O�^��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vprint(fmt, args);
			va_end(args);
			return ret;
		}
		static int logG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlogG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//�y�ꎞ���O���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const level::value_t level_, const char* fmt, ...)//�y�ꎞ���O���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int log(const char* fmt, ...)//�y�ꎞ���O���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vlog(fmt, args);
			va_end(args);
			return ret;
		}
		static int noticeG(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnoticeG(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const level::value_t level_, const category::value_t category_, const char* fmt, ...)//�y�ꎞ��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(level_, category_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const level::value_t level_, const char* fmt, ...)//�y�ꎞ��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(level_, fmt, args);
			va_end(args);
			return ret;
		}
		int notice(const char* fmt, ...)//�y�ꎞ��ʒʒm���x���Łz
		{
			va_list args;
			va_start(args, fmt);
			const int ret = vnotice(fmt, args);
			va_end(args);
			return ret;
		}
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h��`�}�N��
		//��vprint***/vlog***/vnotice***
		//��va_list�������ɂƂ�o�[�W����
	#define declare_vprintMethods(level_) \
		static int vprintAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vprintG(as##level_, category_, fmt, args); \
		} \
		int vprintAs##level_(const category::value_t category_, const char* fmt, va_list args)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			return vprint(as##level_, category_, fmt, args); \
		} \
		int vprintAs##level_(const char* fmt, va_list args)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			return vprint(as##level_, fmt, args); \
		} \
		static int vlogAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vlogG(as##level_, category_, fmt, args); \
		} \
		int vlogAs##level_(const category::value_t category_, const char* fmt, va_list args)/*�y�ꎞ���O���x���Łz*/ \
		{ \
			return vlog(as##level_, category_, fmt, args); \
		} \
		int vlogAs##level_(const char* fmt, va_list args)/*�y�ꎞ���O���x���Łz*/ \
		{ \
			return vlog(as##level_, fmt, args); \
		} \
		static int vnoticeAs##level_##G(const category::value_t category_, const char* fmt, va_list args) \
		{ \
			return vnoticeG(as##level_, category_, fmt, args); \
		} \
		int vnoticeAs##level_(const category::value_t category_, const char* fmt, va_list args)/*�y�ꎞ��ʒʒm���x���Łz*/ \
		{ \
			return vnotice(as##level_, category_, fmt, args); \
		} \
		int vnoticeAs##level_(const char* fmt, va_list args)/*�y�ꎞ��ʒʒm���x���Łz*/ \
		{ \
			return vnotice(as##level_, fmt, args); \
		}
			//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h��`�}�N��
		//��print***/log***/notice***
		//���ϒ������o�[�W����
	#define declare_printMethods(level_) \
		static int printAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int printAs##level_(const category::value_t category_, const char* fmt, ...)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int printAs##level_(const char* fmt, ...)/*�y�ꎞ���O�^��ʒʒm���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vprintAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		} \
		static int logAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int logAs##level_(const category::value_t category_, const char* fmt, ...)/*�y�ꎞ���O���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int logAs##level_(const char* fmt, ...)/*�y�ꎞ���O���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vlogAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		} \
		static int noticeAs##level_##G(const category::value_t category_, const char* fmt, ...) \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_##G(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int noticeAs##level_(const category::value_t category_, const char* fmt, ...)/*�y�ꎞ��ʒʒm���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_(category_, fmt, args); \
			va_end(args); \
			return ret; \
		} \
		int noticeAs##level_(const char* fmt, ...)/*�y�ꎞ��ʒʒm���x���Łz*/ \
		{ \
			va_list args; \
			va_start(args, fmt); \
			const int ret = vnoticeAs##level_(fmt, args); \
			va_end(args); \
			return ret; \
		}
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h��`
		//��vprint***/vlog***/vnotice***
		//��va_list�������ɂƂ�o�[�W����
		declare_vprintMethods(Normal);//�ʏ탁�b�Z�[�W
		declare_vprintMethods(Verbose);//�璷���b�Z�[�W
		declare_vprintMethods(Detail);//�ڍ׃��b�Z�[�W
		declare_vprintMethods(Important);//�d�v���b�Z�[�W
		declare_vprintMethods(Warning);//�x�����b�Z�[�W
		declare_vprintMethods(Critical);//�d��i���j���b�Z�[�W
		declare_vprintMethods(Absolute);//��΁i�K�{�j���b�Z�[�W
		//���b�Z�[�W�o�́^���O�o�́^��ʒʒm���\�b�h��`
		//��print***/log***/notice***
		//���ϒ������o�[�W����
		declare_printMethods(Normal);//�ʏ탁�b�Z�[�W
		declare_printMethods(Verbose);//�璷���b�Z�[�W
		declare_printMethods(Detail);//�ڍ׃��b�Z�[�W
		declare_printMethods(Important);//�d�v���b�Z�[�W
		declare_printMethods(Warning);//�x�����b�Z�[�W
		declare_printMethods(Critical);//�d��i���j���b�Z�[�W
		declare_printMethods(Absolute);//��΁i�K�{�j���b�Z�[�W
	protected:
		//�R�[���|�C���g�X�^�b�N�Ɏ��g���v�b�V��
		void pushCallPoint()
		{
			assert(m_callPointStackHead != this);
			m_callPointStackNext = m_callPointStackHead;
			m_callPointStackHead = this;
		}
		//�R�[���|�C���g�X�^�b�N����i���g���j�|�b�v
		void popCallPoint()
		{
			assert(m_callPointStackHead == this);
			m_callPointStackHead = m_callPointStackNext;
			m_callPointStackNext = nullptr;
		}
	public:
		//�R�[���|�C���g�X�^�b�N�����X�g�\��
		static void printCallPointStack(const level::value_t level_,  category::value_t category_, const char* name)
		{
		}
	public:
		//�f�t�H���g�R���X�g���N�^
		message():
			m_level(asNormal),
			m_category(forAny),
			m_name(nullptr),
			m_srcFilename(nullptr),
			m_funcName(nullptr),
			m_callPointStackNext(nullptr)
		{
			initializeOnce();
		}
		//�R���X�g���N�^
		message(const level::value_t level_, const category::value_t category_, const char* name, const char* src_file_name, const char* func_name) :
			m_level(level_),
			m_category(category_),
			m_name(name),
			m_srcFilename(src_file_name),
			m_funcName(func_name),
			m_callPointStackNext(nullptr)
		{
			assert(category_ >= category::NORMAL_MIN && category_ <= category::NORMAL_MAX);
			memcpy(m_logLevel, m_logLevelG, sizeof(m_logLevel));//�ꎞ���O���x��
			memcpy(m_noticeLevel, m_noticeLevelG, sizeof(m_noticeLevel));//�ꎞ��ʒʒm���x��
		}
		//�f�X�g���N�^
		~message()
		{}
	protected:
		//�t�B�[���h
		const level::value_t m_level;//���x��
		const category::value_t m_category;//�J�e�S��
		const char* m_name;//������
		const char* m_srcFilename;//�\�[�X�t�@�C����
		const char* m_funcName;//�֐���
		message* m_callPointStackNext;//���̃R�[���|�C���g�X�^�b�N
	private:
		level::value_t m_logLevel[category::NORMAL_NUM];//�ꎞ���O���x��
		level::value_t m_noticeLevel[category::NORMAL_NUM];//�ꎞ��ʒʒm���x��
		static bool m_isInitialized;//�������ς݃t���O
		static level::value_t m_logLevelG[category::NORMAL_NUM];//���݂̃��O���x��
		static level::value_t m_noticeLevelG[category::NORMAL_NUM];//���݂̉�ʒʒm���x��
		static thread_local message* m_callPointStackHead;//�R�[���|�C���g�X�^�b�N�̐擪
	};
	//----------------------------------------
	//���b�Z�[�W�̐ÓI�ϐ����C���X�^���X��
	bool message::m_isInitialized = false;//�������ς݃t���O
	level::value_t message::m_logLevelG[category::NORMAL_NUM];//���݂̃��O���x��
	level::value_t message::m_noticeLevelG[category::NORMAL_NUM];//���݂̉�ʒʒm���x��
	thread_local message* message::m_callPointStackHead = nullptr;//�R�[���|�C���g�X�^�b�N�̐擪
	//----------------------------------------
	//���b�Z�[�W�������i������j
	void message::initializeOnce()
	{
		//�������ς݃`�F�b�N
		if (m_isInitialized)
			return;
		//�ÓI�ϐ���������
		m_isInitialized = true;
		resetLogLevelAllG();
		resetNoticeLevelAllG();
	}
	//----------------------------------------
	//���b�Z�[�W�p�ϐ�
	static message s_messageForInitialize;//�������������s�̂��߂̃C���X�^���X
	//----------------------------------------
	//�R�[���|�C���g�N���X
	class callPoint : public message
	{
	};
	//----------------------------------------
	//�֐�
	//���\�b�h
	//���݂̃��O���x�����擾
	level::value_t getLogLevel(const category::value_t category_)
	{
		return message::getLogLevelG(category_);
	}
	//���݂̃��O���x����ύX
	//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
	level::value_t setLogLevel(const level::value_t level_, const category::value_t category_)
	{
		return message::setLogLevelG(level_, category_);
	}
	//���݂̃��O���x�������Z�b�g
	void resetLogLevel(const category::value_t category_)
	{
		message::resetLogLevelG(category_);
	}
	//���݂̃��O���x����S�ă��Z�b�g
	void resetLogLevelAll()
	{
		message::resetLogLevelAllG();
	}
	//���݂̉�ʒʒm���x�����擾
	level::value_t getNoticeLevel(const category::value_t category_)
	{
		return message::getNoticeLevelG(category_);
	}
	//���݂̉�ʒʒm���x����ύX
	//���w��̒l�ȏ�̃��x���̃��b�Z�[�W�݂̂����O�o�͂���
	level::value_t setNoticeLevel(const level::value_t level_, const category::value_t category_)
	{
		return message::setNoticeLevelG(level_, category_);
	}
	//���݂̉�ʒʒm���x�������Z�b�g
	void resetNoticeLevel(const category::value_t category_)
	{
		message::resetNoticeLevelG(category_);
	}
	//���݂̉�ʒʒm���x����S�ă��Z�b�g
	void resetNoticeLevelAll()
	{
		message::resetNoticeLevelAllG();
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐��F���x���������w��
	//��vprint***/vlog***/vnotice***
	//��va_list�������ɂƂ�o�[�W����
	static int vprint(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vprintG(level_, category_, fmt, args);
	}
	static int vlog(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vlogG(level_, category_, fmt, args);
	}
	static int vnotice(const level::value_t level_, const category::value_t category_, const char* fmt, va_list args)
	{
		return message::vnoticeG(level_, category_, fmt, args);
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐��F���x���������w��
	//��print***/log***/notice***
	//���ϒ������o�[�W����
	static int print(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vprintG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	static int log(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vlogG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	static int notice(const level::value_t level_, const category::value_t category_, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const int ret = message::vnoticeG(level_, category_, fmt, args);
		va_end(args);
		return ret;
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐���`�}�N��
	//��vprint***/vlog***/vnotice***
	//��va_list�������ɂƂ�o�[�W����
#define declare_vprintFuncs(level_) \
	static int vprintAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vprintAs##level_##G(category_, fmt, args); \
	} \
	static int vlogAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vlogAs##level_##G(category_, fmt, args); \
	} \
	static int vnoticeAs##level_(const category::value_t category_, const char* fmt, va_list args) \
	{ \
		return message::vnoticeAs##level_##G(category_, fmt, args); \
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐���`�}�N��
	//��print***/log***/notice***
	//���ϒ������o�[�W����
#define declare_printFuncs(level_) \
	static int printAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vprintAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	} \
	static int logAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vlogAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	} \
	static int noticeAs##level_(const category::value_t category_, const char* fmt, ...) \
	{ \
		va_list args; \
		va_start(args, fmt); \
		const int ret = message::vnoticeAs##level_##G(category_, fmt, args); \
		va_end(args); \
		return ret; \
	}
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐���`
	//��vprint***/vlog***/vnotice***
	//��va_list�������ɂƂ�o�[�W����
	declare_vprintFuncs(Normal);//�ʏ탁�b�Z�[�W
	declare_vprintFuncs(Verbose);//�璷���b�Z�[�W
	declare_vprintFuncs(Detail);//�ڍ׃��b�Z�[�W
	declare_vprintFuncs(Important);//�d�v���b�Z�[�W
	declare_vprintFuncs(Warning);//�x�����b�Z�[�W
	declare_vprintFuncs(Critical);//�d��i���j���b�Z�[�W
	declare_vprintFuncs(Absolute);//��΁i�K�{�j���b�Z�[�W
	//���b�Z�[�W�o�́^���O�o�́^��ʒʒm�֐���`
	//��print***/log***/notice***
	//���ϒ������o�[�W����
	declare_printFuncs(Normal);//�ʏ탁�b�Z�[�W
	declare_printFuncs(Verbose);//�璷���b�Z�[�W
	declare_printFuncs(Detail);//�ڍ׃��b�Z�[�W
	declare_printFuncs(Important);//�d�v���b�Z�[�W
	declare_printFuncs(Warning);//�x�����b�Z�[�W
	declare_printFuncs(Critical);//�d��i���j���b�Z�[�W
	declare_printFuncs(Absolute);//��΁i�K�{�j���b�Z�[�W
}//namespce dbg

//----------------------------------------
//�f�o�b�O���b�Z�[�W�̃��[�U�[�g��
namespace dbg
{
	//���[�U�[�g��
	namespace ext
	{
		//----------------------------------------
		//�J�e�S���萔
		enum categoryEnum : category::value_t
		{
			forReserved01 = define_revervedCategory(0),//(�\��01)
			forReserved02 = define_revervedCategory(1),//(�\��01)
			forReserved03 = define_revervedCategory(2),//(�\��01)
		};
		//----------------------------------------
		//�J�e�S����`
		//���w�b�_�[�Ō��J����K�v�Ȃ�
		declare_reservedCategory(forReserved01, true, true);//(�\��01)
		declare_reservedCategory(forReserved02, true, true);//(�\��02)
		declare_reservedCategory(forReserved03, true, true);//(�\��03)
		//----------------------------------------
		//�J�e�S���R���e�i�g��������
		struct categoryContainerExt
		{
			categoryContainerExt()
			{
				category::container::initializeOnce();
				category_forReserved01();//(�\��01) 
				category_forReserved02();//(�\��02)
				category_forReserved03();//(�\��03)
			}
		};
		//----------------------------------------
		//�ϐ�
		static categoryContainerExt s_categoryForInitialize;//�������������s�̂��߂̃C���X�^���X
	}//namespace ext
}//namespace dbg



//----------------------------------------
//�e�X�g

//�l�[���X�[�y�[�X�\�L�ȗ��p
using namespace dbg;
using namespace dbg::ext;

//--------------------
//�e�X�g�i���ʊ֐��j
void printCommon()
{
	printf("---------- printCommon() ----------\n");
	level log_level(getLogLevel(forAny));
	level notice_level(getNoticeLevel(forAny));
	printf("logLevel=%s, noticeLevel=%s\n", log_level.name(), notice_level.name());
	
	//�v�����g��
	const char* name = "�e�X�g";
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
	print(asNormal, forAny, "�ʏ탁�b�Z�[�W by %s\n", name);
	//���O�o�͐�p�֐�
	logAsCritical(forAny, "�y���O�o�͐�p�z�d�僁�b�Z�[�W by %s\n", name);
	//��ʒʒm��p�֐�
	noticeAsCritical(forAny, "�y��ʒʒm��p�z�d�僁�b�Z�[�W by %s\n", name);
}
//--------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	//���x�����
	printLevelAll();
	//�J�e�S�����
	printCategoryAll();

	//�v�����g
	printCommon();

	//���O���x���ύX
	setLogLevel(asDetail, forEvery);
	setNoticeLevel(asDetail, forEvery);
	
	//�v�����g
	printCommon();

	{
		message msg(asCritical, forReserved01, "�e�X�g����", GET_CONCATENATED_SOURCE_FILE_NAME(), GET_FUNC_NAME());
		msg.printAsNormal("print:�e�X�g�i%d�j\n", 1);
		msg.resetLogLevelAll();
		msg.resetNoticeLevelAll();
		msg.printAsNormal("print:�e�X�g�i%d�j\n", 2);
		msg.log("log:�e�X�g�i%d�j\n", 3);
		msg.notice("notice:�e�X�g�i%d�j\n", 4);
		msg.logAsNormal("name=\"%s\", srcFile=\"%s\", funcName=\"%s\"\n", msg.getName(), msg.getSrcFileName(), msg.getFuncname());
	}

	//���O���x���ύX
	setLogLevel(asSilentAbsolutely, forEvery);
	setNoticeLevel(asSilentAbsolutely, forEvery);

	//�v�����g
	printCommon();

	//���O���x�����Z�b�g
	resetLogLevelAll();
	resetNoticeLevelAll();

	//�v�����g
	printCommon();

	message msg;
	msg.getLogLevelG(for2D);
	msg.getLogLevel(for2D);

	return EXIT_SUCCESS;
}

// End of file
