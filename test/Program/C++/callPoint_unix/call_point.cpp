#define TLS_IS_POSIX//【GCC用】TLSの宣言をPOSIXスタイルにする時はこのマクロを有効にする
//#define USE_WINDOWS_CONSOLE_COLOR//【Windows用】Windowsスタイルのコンソールカラーを使用

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>//assert用
#include <memory.h>//memcpy用
#include <limits.h>//UCHAR_MAX用
#include <bitset>//std::bitset用
#include <iterator>//std::iterator用
#include <algorithm>//std::move用

#include <atomic>//C++11アトミック型

//スレッドローカルストレージ修飾子
//※C++11仕様偽装
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX仕様
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows仕様
#endif//TLS_IS_POSIX

//Windowsスタイルカラー用
#ifdef USE_WINDOWS_CONSOLE_COLOR
#include <windows.h>
#include <conio.h> 
#endif//USE_WINDOWS_CONSOLE_COLOR

//--------------------------------------------------------------------------------
//デバッグログ
namespace dbgLog
{
	//----------------------------------------
	//コンソールカラー
	class color
	{
	public:
		//型
		//ハンドル型
	#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
		typedef HANDLE handle_t;
	#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
		typedef FILE* handle_t;
	#endif//USE_WINDOWS_CONSOLE_COLOR
	public:
		//定数
		//カラー値
		enum color_t : unsigned char
		{
			reset = 0x10,//リセット
			through = 0x20,//スルー（現状維持：何もしない）

		#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
			R = 0x04,//Red:赤
			G = 0x02,//Green:緑
			B = 0x01,//Blue:青
			I = 0x08,//Intensity:鮮やか
			BG_SHIFT = 4,//背景色指定時のビットシフト数
		#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
			R = 0x01,//Red:赤
			G = 0x02,//Green:緑
			B = 0x04,//Blue:青
			I = 0x08,//high Intensity:鮮やか
		#endif//USE_WINDOWS_CONSOLE_COLOR

			RGB = 0x07,//RGBマスク
			RGBI = 0x0f,//RGB+Iマスク

			//標準カラー
			black = 0,//黒
			blue = B,//青
			red = R,//赤
			magenta = R | B,//紫
			green = G,//緑
			cyan = G | B,//水
			yellow = G | R,//黄
			white = G | R | B,//白

			//鮮やかなカラー
			iBlack = I | black,//黒
			iBlue = I | blue,//青
			iRed = I | red,//赤
			iMagenta = I | magenta,//紫
			iGreen = I | green,//緑
			iCyan = I | cyan,//水
			iYellow = I | yellow ,//黄
			iWhite = I | white,//白
		};
		//対象
		enum target_t : unsigned char
		{
			stdOut = 0,//対象：標準出力
			stdErr = 1,//対象：標準エラー
		};
		static const int targetNum = 2;
	public:
		//アクセッサ
		target_t getTarget() const { return m_target; }//対象
		color_t getForeColor() const { return m_foreColor; }//カラー：前面
		color_t getBackColor() const { return m_backColor; }//カラー：背面
		color_t getPrevForeColor() const { return m_prevForeColor; }//前のカラー:前面
		color_t getPrevBackColor() const { return m_prevBackColor; }//前のカラー:背面
		bool isAutoRestore() const { return m_isAutoRestore; }//自動カラー復元実行指定
	public:
		//キャストオペレータ
		operator int() const { return static_cast<int>(m_target); }//対象
		operator target_t() const { return m_target; }//対象
	public:
		//メソッド
		//カラー変更
		//※実際にコンソールに反映させる
		void changeColor()
		{
			if (m_foreColor == through)
				return;
			changeColor(m_target, m_foreColor, m_backColor);
		}
		void changeColor(const target_t target, const color_t fore_color, const color_t back_color = black)
		{
			//対象ハンドル取得
			const handle_t target_h = m_handle[target];

			//カラー変更
			if (fore_color == reset)
			{
			#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
				SetConsoleTextAttribute(target_h, m_ConsoleScreenBufferInfo[target].wAttributes);
			#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
				fprintf(target_h, "\x1b[39m\x1b[49m");//"\x1b[0m"
			#endif//USE_WINDOWS_CONSOLE_COLOR
			}
			else
			{
			#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
				SetConsoleTextAttribute(target_h, ((back_color & RGBI) << BG_SHIFT) | (fore_color & RGBI));
			#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
				fprintf(target_h, "\x1b[%dm\x1b[%dm", (fore_color & I ? 90 : 30) + (fore_color & RGB), (back_color & I ? 100 : 40) + (back_color & RGB));
			#endif//USE_WINDOWS_CONSOLE_COLOR
			}
		}
	public:
		//カラー初期化（一回限り）
		static void initializeOnce();
	public:
		//デフォルトコンストラクタ
		color() :
			m_target(stdOut),//対象
			m_foreColor(reset),//カラー：前面
			m_backColor(reset),//カラー：背面
			m_prevForeColor(reset),//前のカラー：前面を記憶
			m_prevBackColor(reset),//前のカラー：背面を記憶
			m_isAutoRestore(false)//自動カラー復元実行指定
		{
			initializeOnce();
		}
		//ムーブコンストラクタ
		color(color&& src) :
			m_target(src.m_target),//対象
			m_foreColor(src.m_foreColor),//カラー：前面
			m_backColor(src.m_backColor),//カラー：背面
			m_prevForeColor(src.m_prevForeColor),//前のカラー：前面を記憶
			m_prevBackColor(src.m_prevBackColor),//前のカラー：背面を記憶
			m_isAutoRestore(src.m_isAutoRestore)//自動カラー復元実行指定
		{
			//ムーブコンストラクタにつき、移動元の内容を改変し、デストラクタが機能しないようにする
			*const_cast<bool*>(&src.m_isAutoRestore) = false;//自動カラー復元実行指定を無効化
		}
		//コンストラクタ
		color(const target_t target, const color_t fore_color, const color_t back_color = black, const bool is_auto_restore = true) :
			m_target(target),//対象
			m_foreColor(fore_color),//カラー：前面
			m_backColor(back_color),//カラー：背面
			m_prevForeColor(m_nowForeColor[m_target]),//前のカラー：前面を記憶
			m_prevBackColor(m_nowBackColor[m_target]),//前のカラー：背面を記憶
			m_isAutoRestore(is_auto_restore)//自動カラー復元実行指定
		{
			if (m_foreColor == through || !m_isAutoRestore)
				return;
			m_nowForeColor[m_target] = m_foreColor;//現在のカラー：前面（記憶用）を更新
			m_nowBackColor[m_target] = m_backColor;//現在のカラー：背面（記憶用）を更新
			changeColor();
		}
		//デストラクタ
		~color()
		{
			if (m_foreColor == through || !m_isAutoRestore)
				return;
			m_nowForeColor[m_target] = m_prevForeColor;//現在のカラー：前面を前のカラーに戻す
			m_nowBackColor[m_target] = m_prevBackColor;//現在のカラー：背面を前のカラーに戻す
			changeColor(m_target, m_prevForeColor, m_prevBackColor);
		}
	private:
		//フィールド
		const target_t m_target;//対象
		const color_t m_foreColor;//カラー：前面
		const color_t m_backColor;//カラー：背面
		const color_t m_prevForeColor;//前のカラー：前面
		const color_t m_prevBackColor;//前のカラー：背面
		const bool m_isAutoRestore;//自動カラー復元実行指定
		static bool m_isInitialized;//初期化済み
		static color_t m_nowForeColor[color::targetNum];//現在のカラー：前面（記憶用）
		static color_t m_nowBackColor[color::targetNum];//現在のカラー：背面（記憶用）
	#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
		static handle_t m_handle[color::targetNum];//ハンドル
		static CONSOLE_SCREEN_BUFFER_INFO m_ConsoleScreenBufferInfo[color::targetNum];//コンソールスクリーンバッファ（リセット用）
	#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用	
		static const handle_t m_handle[color::targetNum];//ハンドル
	#endif//USE_WINDOWS_CONSOLE_COLOR
	};
	//----------------------------------------
	//カラーの静的変数をインスタンス化
	bool color::m_isInitialized = false;
	color::color_t color::m_nowForeColor[color::targetNum] =//現在のカラー：前面（記憶用）
	{
		color::reset,//標準出力用
		color::reset,//標準エラー用
	};
	color::color_t color::m_nowBackColor[color::targetNum] =//現在のカラー：背面（記憶用）
	{
		color::reset,//標準出力用
		color::reset,//標準エラー用
	};
#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
	color::handle_t color::m_handle[color::targetNum];
	CONSOLE_SCREEN_BUFFER_INFO color::m_ConsoleScreenBufferInfo[color::targetNum];//Windows用のリセット用カラー情報
#else//USE_WINDOWS_CONSOLE_COLOR//エスケープシーケンス用
	const color::handle_t color::m_handle[] =
	{
		stdout,//標準出力ハンドル
		stderr,//標準エラーハンドル
	};
#endif//USE_WINDOWS_CONSOLE_COLOR
	//----------------------------------------
	//コンソールカラー初期化（一回限り）
	void color::initializeOnce()
	{
		//初期化済みチェック
		if (m_isInitialized)
			return;
		//静的変数を初期化
		m_isInitialized = true;
#ifdef USE_WINDOWS_CONSOLE_COLOR//Windows用
		//ハンドル
		m_handle[stdOut] = GetStdHandle(STD_OUTPUT_HANDLE);//標準出力ハンドル
		m_handle[stdErr] = GetStdHandle(STD_ERROR_HANDLE);//標準エラーハンドル
		//カラー変更開始
		GetConsoleScreenBufferInfo(m_handle[stdOut], &m_ConsoleScreenBufferInfo[stdOut]);
		GetConsoleScreenBufferInfo(m_handle[stdErr], &m_ConsoleScreenBufferInfo[stdErr]);
#endif//USE_WINDOWS_CONSOLE_COLOR
	}
	//----------------------------------------
	//コンソールカラー用変数
	static color s_colorForInitialize;//初期化処理実行のためのインスタンス

	//----------------------------------------
	//レベル
	class level
	{
	public:
		//型
		typedef unsigned char value_t;//値（レベル）
		typedef unsigned char byte;//バッファ用
	private:
		//定数（計算用）
		#define calcAsOutput(value) ((value) >> 1)//値を出力レベルに変換
		#define calcAsValue(value) ((value) << 1)//出力レベルを値に変換
	public:
		//定数
		static const value_t NORMAL_NUM = 11;//通常レベル数
		static const value_t SPECIAL_NUM = 2;//特殊レベル数
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;//レベル総数
		static const value_t MIN = 0;//レベル最小値
		static const value_t MAX = NUM - 1;//レベル最大値
		static const value_t NORMAL_MIN = MIN;//通常レベル最小値
		static const value_t NORMAL_MAX = NORMAL_MIN + NORMAL_NUM - 1;//通常レベル最大値
		static const value_t SPECIAL_MIN = NORMAL_MAX + 1;//特殊レベル最小値
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//特殊レベル最大値
		static const value_t BEGIN = MIN;//レベル開始値（イテレータ用）
		static const value_t END = NUM;//レベル終端値（イテレータ用）
		static const value_t POOL_NUM = NUM + 1;//レベル記録数
		static const value_t OUTPUT_LEVEL_MIN = calcAsOutput(NORMAL_MIN);//出力レベル最小値
		static const value_t OUTPUT_LEVEL_MAX = calcAsOutput(NORMAL_MAX);//出力レベル最大値
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");//定数チェック
	public:
		//型
		//--------------------
		//イテレータ
		class iterator : public std::iterator<std::bidirectional_iterator_tag, level>//双方向イテレータとして実装
		{
		public:
			//オペレータ
			const level* operator->() const { return &container::get(m_value); }
			const level& operator*() const { return container::get(m_value); }
			bool operator==(const iterator rhs) const { return m_value == rhs.m_value; }
			bool operator!=(const iterator rhs) const { return m_value != rhs.m_value; }
			const level& operator++() const { return m_value >= container::endValue() ? container::getEnd() : container::get(++m_value); }
			const level& operator++(int) const { return m_value >= container::endValue() ? container::getEnd() : container::get(m_value++); }
			const level& operator--() const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getEnd(); } return container::get(--m_value); }
			const level& operator--(int) const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getBegin(); } return container::get(m_value--); }
		public:
			//キャストオペレータ
			operator const level&() const { return container::get(m_value); }//値（レベル）
		public:
			//コンストラクタ
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
			//デストラクタ
			~iterator()
			{}
		private:
			//フィールド
			value_t mutable m_value;//値（レベル）
		};
		//--------------------
		//constイテレータ
		typedef const iterator const_iterator;
		//--------------------
		//コンテナ（イテレータ用）
		class container
		{
			friend class level;
		public:
			//メソッド
			static const value_t beginValue(){ return BEGIN; }//開始値取得
			static const value_t endValue(){ return END; }//終端値取得
			static const level& get(const value_t value){ return m_poolPtr[value]; }//要素を取得
			static const level& getBegin(){ return m_poolPtr[beginValue()]; }//開始要素を取得
			static const level& getEnd(){ return m_poolPtr[endValue()]; }//終端要素を取得
		private:
			static void set(const value_t value, const level& obj)//要素を更新
			{
				if (!container::m_isAlreadyPool[value])
				{
					container::m_poolPtr[value] = obj;
					container::m_isAlreadyPool[value] = true;
				}
			}
		public:
			static const iterator begin(){ return iterator(beginValue()); }//開始イテレータを取得
			static const iterator end()	{ return iterator(endValue()); }//終端イテレータを取得
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//開始constイテレータを取得
			static const_iterator cend(){ return const_iterator(endValue()); }//終端constイテレータを取得
			//※reverse_iterator非対応
			//メソッド
			//初期化（一回限り）
			static void initializeOnce();
		private:
			//フィールド
			static bool m_isInitialized;//初期化済み
			static level* m_poolPtr;//要素のプール（ポインタ）
			static byte m_pool[];//要素のプール（バッファ）※バッファとポインタを分けているのは、コンストラクタの実行を防止するため
			static std::bitset<POOL_NUM> m_isAlreadyPool;//要素の初期化済みフラグ
		};
	public:
		//オペレータ
		//※出力レベルで比較する
		bool operator ==(const level& rhs) const { return valueAsOutput() == rhs.valueAsOutput(); }
		bool operator !=(const level& rhs) const { return valueAsOutput() != rhs.valueAsOutput(); }
		bool operator >(const level& rhs) const { return valueAsOutput() > rhs.valueAsOutput(); }
		bool operator >=(const level& rhs) const { return valueAsOutput() >= rhs.valueAsOutput(); }
		bool operator <(const level& rhs) const { return valueAsOutput() < rhs.valueAsOutput(); }
		bool operator <=(const level& rhs) const { return valueAsOutput() <= rhs.valueAsOutput(); }
	private:
		//コピーオペレータ
		level& operator=(const level& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//キャストオペレータ
		operator int() const { return static_cast<int>(m_value); }//値（レベル）
		operator value_t() const { return m_value; }//値（レベル）
		operator const char*() const { return m_name; }//名前
	public:
		//アクセッサ
		value_t value() const { return m_value; }//値（レベル）取得
		const char* name() const { return m_name; }//名前取得
		value_t valueAsOutput() const { return calcAsOutput(m_value); }//出力レベル取得
		bool forOutput() const { return m_forOutput; }//出力レベルとして使用可能か？
		bool forOutputMask() const { return m_forOutputMask; }//出力レベルマスクとして使用可能か？
		color getColor() const { return std::move(changeColor(true)); }//カラー取得
		color getColorForNotice() const { return std::move(changeColorForNotice(true)); }//カラー取得（画面通知用）
	public:
		//メソッド
		//カラー変更
		//※戻り値受け取り必須
		//　戻り値を受け取らないとすぐにデストラクタが実行されて元のカラーに戻るので実際に反映されない
		color changeColor(const bool is_only_get = false) const
		{
			return std::move(color(color::stdOut, m_foreColor, m_backColor, !is_only_get));
		}
		//カラー変更（画面通知用）
		//※戻り値受け取り必須
		//　戻り値を受け取らないとすぐにデストラクタが実行されて元のカラーに戻るので実際に反映されない
		color changeColorForNotice(const bool is_only_get = false) const
		{
			return std::move(color(color::stdErr, m_foreColorForNotice, m_backColorForNotice, !is_only_get));
		}
		//コンテナ要素を取得（ショートカット用）
		static const level& get(const value_t value){ return container::get(value); }
		//前のレベルを取得
		const level& prev() const
		{
			if (valueAsOutput() <= OUTPUT_LEVEL_MIN || valueAsOutput() > OUTPUT_LEVEL_MAX || !m_forOutput)
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcAsValue(calcAsOutput(m_value) - 1)];
		}
		//次のレベルを取得
		const level& next() const
		{
			if (valueAsOutput() < OUTPUT_LEVEL_MIN || valueAsOutput() >= OUTPUT_LEVEL_MAX || !m_forOutput)
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcAsValue(calcAsOutput(m_value) + 1)];
		}
	public:
		//デフォルトコンストラクタ
		level() :
			m_name(nullptr),
			m_value(UCHAR_MAX),
			m_forOutput(false),
			m_forOutputMask(false),
			m_foreColor(color::through),
			m_backColor(color::through),
			m_foreColorForNotice(color::through),
			m_backColorForNotice(color::through)
		{
			container::initializeOnce();//コンテナ初期化（一回限り）
		}
		//コピーコンストラクタ
		level(const level& src) :
			m_name(src.m_name),
			m_value(src.m_value),
			m_forOutput(src.m_forOutput),
			m_forOutputMask(src.m_forOutputMask),
			m_foreColor(src.m_foreColor),
			m_backColor(src.m_backColor),
			m_foreColorForNotice(src.m_foreColorForNotice),
			m_backColorForNotice(src.m_backColorForNotice)
		{
		}
		//コンストラクタ
		level(const value_t value, const char* name, const bool for_output, const bool for_output_mask, const color::color_t fore_color, const color::color_t back_color, const color::color_t fore_color_for_notice, const color::color_t back_color_for_notice) :
			m_name(name),
			m_value(value),
			m_forOutput(for_output),
			m_forOutputMask(for_output_mask),
			m_foreColor(fore_color),
			m_backColor(back_color),
			m_foreColorForNotice(fore_color_for_notice),
			m_backColorForNotice(back_color_for_notice)
		{
			assert(value >= BEGIN && value <= END);
			container::set(m_value, *this);//コンテナに登録
		}
		level(const value_t value) :
			m_name(nullptr),
			m_value(value),
			m_forOutput(false),
			m_forOutputMask(false),
			m_foreColor(color::through),
			m_backColor(color::through),
			m_foreColorForNotice(color::through),
			m_backColorForNotice(color::through)
		{
			assert(value >= BEGIN && value <= END);
			*this = container::get(m_value);//コンテナから取得して自身にコピー
		}
		//デストラクタ
		~level()
		{}
	private:
		const char* m_name;//名前
		const value_t m_value;//値（レベル）
		const bool m_forOutput;//出力レベルとして使用可能か？
		const bool m_forOutputMask;//出力レベルマスクとして使用可能か？
		const color::color_t m_foreColor;//カラー：前面
		const color::color_t m_backColor;//カラー：背面
		const color::color_t m_foreColorForNotice;//カラー：前面（画面通知用）
		const color::color_t m_backColorForNotice;//カラー：背面（画面通知用）
	private:
		//マクロ消去
#ifndef ENABLE_CONSTEXPR
#undef calcAsOutput
#undef calcAsValue
#endif//ENABLE_CONSTEXPR
	};
	//----------------------------------------
	//レベル定義用テンプレートクラス：通常レベル用
	template<unsigned char V, color::color_t fore_color, color::color_t back_color, color::color_t fore_color_for_notice, color::color_t back_color_for_notice>
	class level_normal : public level
	{
	public:
		//定数
		static const value_t VALUE = V;//値（レベル）
		static_assert(VALUE >= NORMAL_MIN && VALUE <= NORMAL_MAX, "out of range of level");//値の範囲チェック
		static const bool FOR_OUTPUT = true;//出力レベルとして使用可能か？
		static const bool FOR_OUTPUT_MASK = true;//出力レベルマスクとして使用可能か？
		static const color::color_t FORE_COLOR = fore_color;//カラー：前面
		static const color::color_t BACK_COLOR = back_color;//カラー：背面
		static const color::color_t FORE_COLOR_FOR_NOTICE = fore_color_for_notice;//カラー：前面（画面通知用）
		static const color::color_t BACK_COLOR_FOR_NOTICE = back_color_for_notice;//カラー：背面（画面通知用）
	public:
		//コンストラクタ
		level_normal(const char* name) :
			level(VALUE, name, FOR_OUTPUT, FOR_OUTPUT_MASK, FORE_COLOR, BACK_COLOR, FORE_COLOR_FOR_NOTICE, BACK_COLOR_FOR_NOTICE)
		{}
	};
	//----------------------------------------
	//レベル定義用テンプレートクラス：特殊レベル用
	template<unsigned char V>
	class level_special : public level
	{
	public:
		//定数
		static const value_t VALUE = V;//値（レベル）
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of level");//値の範囲チェック
		static const bool FOR_OUTPUT = false;//出力レベルとして使用可能か？
		static const bool FOR_OUTPUT_MASK = true;//出力レベルマスクとして使用可能か？
	public:
		//コンストラクタ
		level_special(const char* name) :
			level(VALUE, name, FOR_OUTPUT, FOR_OUTPUT_MASK, color::through, color::through, color::through, color::through)
		{}
	};
	//----------------------------------------
	//レベル定義クラス：終端用
	class level_end : public level
	{
	public:
		//定数
		static const value_t VALUE = END;//値（レベル）
		static const bool FOR_OUTPUT = false;//出力レベルとして使用可能か？
		static const bool FOR_OUTPUT_MASK = false;//出力レベルマスクとして使用可能か？
	public:
		//コンストラクタ
		level_end() :
			level(VALUE, "(END)", FOR_OUTPUT, FOR_OUTPUT_MASK, color::through, color::through, color::through, color::through)
		{}
	};
	//----------------------------------------
	//レベル定数
#define define_normalLevel(print_level, sub) (level::NORMAL_MIN + print_level * 2 + sub)
#define define_specialLevel(value) (level::SPECIAL_MIN + value)
	enum levelEnum : level::value_t
	{
		asNormal = define_normalLevel(1, 0),//通常メッセージ
		asVerbose = define_normalLevel(0, 0),//冗長メッセージ
		asDetail = define_normalLevel(0, 1),//詳細メッセージ
		asImportant = define_normalLevel(2, 0),//重要メッセージ
		asWarning = define_normalLevel(3, 0),//警告メッセージ
		asCritical = define_normalLevel(4, 0),//重大メッセージ
		asAbsolute = define_normalLevel(5, 0),//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
		//以下、ログレベル／画面通知レベル変更用
		asSilent = define_specialLevel(0),//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
		asSilentAbsolutely = define_specialLevel(1),//絶対静寂（全てのメッセージを出力しない）
	};
	//----------------------------------------
	//レベル定義
#define declare_normalLevel(value, fore_color, back_color, fore_color_for_notice, back_color_for_notice) struct level_##value : public level_normal<value, fore_color, back_color, fore_color_for_notice, back_color_for_notice>{ level_##value () :level_normal<value, fore_color, back_color, fore_color_for_notice, back_color_for_notice>(#value){} }
#define declare_specialLevel(value) struct level_##value : public level_special<value>{ level_##value () :level_special<value>(#value){} }
	//※以下、ヘッダーで公開する必要なし
	declare_normalLevel(asNormal, color::reset, color::reset, color::black, color::iWhite);//通常メッセージ
	declare_normalLevel(asVerbose, color::iBlack, color::black, color::iBlack, color::iWhite);//冗長メッセージ
	declare_normalLevel(asDetail, color::iBlack, color::black, color::iBlack, color::iWhite);//詳細メッセージ
	declare_normalLevel(asImportant, color::iBlue, color::black, color::iBlue, color::iWhite);//重要メッセージ
	declare_normalLevel(asWarning, color::iMagenta, color::black, color::black, color::iMagenta);//警告メッセージ
	declare_normalLevel(asCritical, color::iRed, color::black, color::iYellow, color::iRed);//重大メッセージ
	declare_normalLevel(asAbsolute, color::through, color::through, color::through, color::through);//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
	//以下、ログレベル／画面通知レベル変更用
	declare_specialLevel(asSilent);//静寂（絶対メッセ―ジ以外出力しない）
	declare_specialLevel(asSilentAbsolutely);//絶対静寂（全てのメッセージを出力しない）

	//----------------------------------------
	//レベルコンテナの静的変数をインスタンス化
	bool level::container::m_isInitialized = false;
	level* level::container::m_poolPtr = nullptr;
	level::byte level::container::m_pool[(POOL_NUM)* sizeof(level)];
	std::bitset<level::POOL_NUM> level::container::m_isAlreadyPool;
	//----------------------------------------
	//レベルコンテナ初期化（一回限り）
	void level::container::initializeOnce()
	{
		//初期化済みチェック
		if (m_isInitialized)
			return;
		//静的変数を初期化
		m_isInitialized = true;
		m_isAlreadyPool.reset();
		memset(m_pool, 0, sizeof(m_pool));
		m_poolPtr = reinterpret_cast<level*>(m_pool);
		//要素を初期化
		for (level::value_t value = 0; value < level::NUM; ++value)
		{
			level(value, "(undefined)", false, false, color::through, color::through, color::through, color::through);
			m_isAlreadyPool[value] = false;
		}
		//割り当て済みレベルを設定（コンストラクタで要素を登録）
		level_asNormal();//通常メッセージ
		level_asVerbose();//冗長メッセージ
		level_asDetail();//詳細メッセージ
		level_asImportant();//重要メッセージ
		level_asWarning();//警告メッセージ
		level_asCritical();//重大メッセージ
		level_asAbsolute();//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
		level_asSilent();//静寂（絶対メッセ―ジ以外出力しない）
		level_asSilentAbsolutely();//絶対静寂（全てのメッセージを出力しない）
		level_end();//終端
	}
	//----------------------------------------
	//レベル用変数
	static level s_levelForInitialize;//初期化処理実行のためのインスタンス
	//----------------------------------------
	//レベルコンテナ列挙
	void printLevelAll()
	{
		for (auto& obj : level::container())//C++11スタイル
		//for (auto ite = level::container::begin(); ite != level::container::end(); ++ite)//旧来のスタイル
		//for (auto ite = level::container::cbegin(); ite != level::container::cend(); ++ite)//旧来のスタイル
		{
			//const level& obj = ite;//イテレータを変換（イテレータのままでもアロー演算子で直接値操作可能）
			color col(obj.changeColor());
			fprintf(stdout, "level=%d, name=\"%s\", valueAsOutput=%d, forOutput=%d, forOutputMask=%d\n", obj.value(), obj.name(), obj.valueAsOutput(), obj.forOutput(), obj.forOutputMask());
			auto& prev = obj.prev();
			auto& next = obj.next();
			fprintf(stdout, "           prev=%s(%d)\n", prev.name(), prev.value());
			fprintf(stdout, "           next=%s(%d)\n", next.name(), next.value());
		}
	}

	//----------------------------------------
	//カテゴリ
	class category
	{
	public:
		//型
		typedef unsigned char value_t;//値（カテゴリ）
		typedef unsigned char byte;//バッファ用
	public:
		//定数
		static const value_t NORMAL_NUM = 64;//通常カテゴリ数
		static const value_t ASSIGNED_NUM = 8;//割り当て済みカテゴリ数
		static const value_t RESERVED_NUM = NORMAL_NUM - ASSIGNED_NUM;//予約カテゴリ数
		static const value_t SPECIAL_NUM = 3;//特殊カテゴリ数
		static const value_t NUM = NORMAL_NUM + SPECIAL_NUM;//カテゴリ総数
		static const value_t MIN = 0;//カテゴリ最小値
		static const value_t MAX = NUM - 1;//カテゴリ最大値
		static const value_t NORMAL_MIN = MIN;//通常カテゴリ最小値
		static const value_t NORMAL_MAX = NORMAL_MIN + NORMAL_NUM - 1;//通常カテゴリ最大値
		static const value_t ASSIGNED_MIN = NORMAL_MIN;//割り当て済みカテゴリ最小値
		static const value_t ASSIGNED_MAX = ASSIGNED_MIN + ASSIGNED_NUM - 1;//割り当て済みカテゴリ最大値
		static const value_t RESERVED_MIN = ASSIGNED_MAX + 1;//予約カテゴリ最小値
		static const value_t RESERVED_MAX = RESERVED_MIN + RESERVED_NUM - 1;//予約カテゴリ最大値
		static const value_t SPECIAL_MIN = NORMAL_MAX + 1;//特殊カテゴリ最小値
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//特殊カテゴリ最大値
		static const value_t BEGIN = MIN;//カテゴリ開始値（イテレータ用）
		static const value_t END = NUM;//カテゴリ終端値（イテレータ用）
		static const value_t POOL_NUM = NUM + 1;//カテゴリ記録数
		static_assert(NORMAL_MAX == RESERVED_MAX, "invalid category numbers.");//定数チェック
		static_assert(SPECIAL_MAX == MAX, "invalid category numbers.");//定数チェック
	public:
		//型
		//--------------------
		//イテレータ
		class iterator : public std::iterator<std::bidirectional_iterator_tag, category>//双方向イテレータとして実装
		{
		public:
			//オペレータ
			const category* operator->() const { return &container::get(m_value); }
			const category& operator*() const { return container::get(m_value); }
			bool operator==(const iterator rhs) const { return m_value == rhs.m_value; }
			bool operator!=(const iterator rhs) const { return m_value != rhs.m_value; }
			const category& operator++() const { return m_value >= container::endValue() ? container::getEnd() : container::get(++m_value); }
			const category& operator++(int) const { return m_value >= container::endValue() ? container::getEnd() : container::get(m_value++); }
			const category& operator--() const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getEnd(); } return container::get(--m_value); }
			const category& operator--(int) const { if (m_value == container::beginValue()){ m_value = container::endValue(); return container::getBegin(); } return container::get(m_value--); }
		public:
			//キャストオペレータ
			operator const category&() const { return container::get(m_value); }//値（カテゴリ）
		public:
			//コンストラクタ
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
			//デストラクタ
			~iterator()
			{}
		private:
			//フィールド
			value_t mutable m_value;//値（カテゴリ）
		};
		//--------------------
		//constイテレータ
		typedef const iterator const_iterator;
		//--------------------
		//コンテナ（イテレータ用）
		class container
		{
			friend class category;
		public:
			//メソッド
			static const value_t beginValue(){ return BEGIN; }//開始値取得
			static const value_t endValue(){ return END; }//終端値取得
			static const category& get(const value_t value){ return m_poolPtr[value]; }//要素を取得
			static const category& getBegin(){ return m_poolPtr[beginValue()]; }//開始要素を取得
			static const category& getEnd(){ return m_poolPtr[endValue()]; }//終端要素を取得
		private:
			static void set(const value_t value, const category& obj)//要素を更新
			{
				if (!container::m_isAlreadyPool[value])
				{
					container::m_poolPtr[value] = obj;
					container::m_isAlreadyPool[value] = true;
				}
			}
		public:
			static const iterator begin(){ return iterator(beginValue()); }//開始イテレータを取得
			static const iterator end()	{ return iterator(endValue()); }//終端イテレータを取得
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//開始constイテレータを取得
			static const_iterator cend(){ return const_iterator(endValue()); }//終端constイテレータを取得
			//※reverse_iterator非対応
			//メソッド
			//初期化（一回限り）
			static void initializeOnce();
		private:
			//フィールド
			static bool m_isInitialized;//初期化済み
			static category* m_poolPtr;//要素のプール（ポインタ）
			static byte m_pool[];//要素のプール（バッファ）※バッファとポインタを分けているのは、コンストラクタの実行を防止するため
			static std::bitset<POOL_NUM> m_isAlreadyPool;//要素の初期化済みフラグ
		};
	public:
		//オペレータ
		bool operator ==(const category& rhs) const { return m_value == rhs.m_value; }
		bool operator !=(const category& rhs) const { return m_value != rhs.m_value; }
	private:
		//コピーオペレータ
		category& operator=(const category& rhs)
		{
			memcpy(this, &rhs, sizeof(*this));
			return *this;
		}
	public:
		//キャストオペレータ
		operator int() const { return static_cast<int>(m_value); }//値（カテゴリ）
		operator value_t() const { return m_value; }//値（カテゴリ）
		operator const char*() const { return m_name; }//名前
	public:
		//アクセッサ
		value_t value() const { return m_value; }//値（カテゴリ）取得
		const char* name() const { return m_name; }//名前取得
		bool isAssigned() const { return m_isAssigned; }//割り当て済みカテゴリか？
		bool isReserved() const { return !m_isAssigned; }//予約カテゴリか？
		bool forOutput() const { return m_forOutput; }//出力カテゴリとして使用可能か？
		bool forSetLevel() const { return m_forSetLevel; }//レベル変更の指定に使用可能か？
	public:
		//メソッド
		//コンテナ要素を取得（ショートカット用）
		static const category& get(const value_t value){ return container::get(value); }
	public:
		//デフォルトコンストラクタ
		category() :
			m_name(nullptr),
			m_value(UCHAR_MAX),
			m_isAssigned(false),
			m_forOutput(false),
			m_forSetLevel(false)
		{
			container::initializeOnce();//コンテナ初期化（一回限り）
		}
		//コピーコンストラクタ
		category(const category& src) :
			m_name(src.m_name),
			m_value(src.m_value),
			m_isAssigned(src.m_isAssigned),
			m_forOutput(src.m_forOutput),
			m_forSetLevel(src.m_forSetLevel)
		{
		}
		//コンストラクタ
		category(const value_t value, const char* name, const bool is_assigned, const bool for_output, const bool for_set_level) :
			m_name(name),
			m_value(value),
			m_isAssigned(is_assigned),
			m_forOutput(for_output),
			m_forSetLevel(for_set_level)
		{
			assert(value >= BEGIN && value <= END);
			container::set(m_value, *this);//コンテナに登録
		}
		category(const value_t value) :
			m_name(nullptr),
			m_value(value),
			m_isAssigned(false),
			m_forOutput(false),
			m_forSetLevel(false)
		{
			assert(value >= BEGIN && value <= END);
			*this = container::get(m_value);//コンテナから取得して自身にコピー
		}
		//デストラクタ
		~category()
		{}
	private:
		const char* m_name;//名前
		const value_t m_value;//値（カテゴリ）
		const bool m_isAssigned;//割り当て済みカテゴリか？
		const bool m_forOutput;//出力カテゴリとして使用可能か？
		const bool m_forSetLevel;//レベル変更の指定に使用可能か？
	};
	//----------------------------------------
	//カテゴリ定義用テンプレートクラス：割り当て済みカテゴリ用
	template<unsigned char V>
	class category_assigned : public category
	{
	public:
		//定数
		static const value_t VALUE = V;//値（カテゴリ）
		static_assert(VALUE >= ASSIGNED_MIN && VALUE <= ASSIGNED_MAX, "out of range of category");//値の範囲チェック
		static const bool IS_ASSIGNED = true;//割り当て済みカテゴリか？
		static const bool FOR_OUTPUT = true;//出力カテゴリとして使用可能か？
		static const bool FOR_SET_LEVEL = true;//レベル変更の指定に使用可能か？
	public:
		//コンストラクタ
		category_assigned(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_OUTPUT, FOR_SET_LEVEL)
		{}
	};
	//----------------------------------------
	//カテゴリ定義用テンプレートクラス：予約カテゴリ用
	template<unsigned char V>
	class category_reserved: public category
	{
	public:
		//定数
		static const value_t VALUE = V;//値（カテゴリ）
		static_assert(VALUE >= RESERVED_MIN && VALUE <= RESERVED_MAX, "out of range of category");//値の範囲チェック
		static const bool IS_ASSIGNED = false;//割り当て済みカテゴリか？
		static const bool FOR_OUTPUT = true;//出力カテゴリとして使用可能か？
		static const bool FOR_SET_LEVEL = true;//レベル変更の指定に使用可能か？
	public:
		//コンストラクタ
		category_reserved(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_OUTPUT, FOR_SET_LEVEL)
		{}
	};
	//----------------------------------------
	//カテゴリ定義用テンプレートクラス：特殊カテゴリ用
	template<unsigned char V, bool for_output, bool for_set_level>
	class category_special : public category
	{
	public:
		//定数
		static const value_t VALUE = V;//値（カテゴリ）
		static_assert(VALUE >= SPECIAL_MIN && VALUE <= SPECIAL_MAX, "out of range of category");//値の範囲チェック
		static const bool IS_ASSIGNED = true;//割り当て済みカテゴリか？
		static const bool FOR_OUTPUT = for_output;//出力カテゴリとして使用可能か？
		static const bool FOR_SET_LEVEL = for_set_level;//レベル変更の指定に使用可能か？
	public:
		//コンストラクタ
		category_special(const char* name) :
			category(VALUE, name, IS_ASSIGNED, FOR_OUTPUT, FOR_SET_LEVEL)
		{}
	};
	//----------------------------------------
	//カテゴリ定義クラス：終端用
	class category_end : public category
	{
	public:
		//定数
		static const value_t VALUE = END;//値（カテゴリ）
		static const bool IS_ASSIGNED = true;//割り当て済みカテゴリか？
		static const bool FOR_OUTPUT = false;//出力カテゴリとして使用可能か？
		static const bool FOR_SET_LEVEL = false;//レベル変更の指定に使用可能か？
	public:
		//コンストラクタ
		category_end() :
			category(VALUE, "(END)", IS_ASSIGNED, FOR_OUTPUT, FOR_SET_LEVEL)
		{}
	};
	//----------------------------------------
	//カテゴリ定数
#define define_assignedCategory(value) (category::ASSIGNED_MIN + value)
#define define_revervedCategory(value) (category::RESERVED_MIN + value)
#define define_specialCategory(value) (category::SPECIAL_MIN + value)
	enum categoryEnum : category::value_t
	{
		forAny = define_assignedCategory(0),//なんでも（カテゴリなし）
		forLogic = define_assignedCategory(1),//プログラム関係
		forResource = define_assignedCategory(2),//リソース関係
		for3D = define_assignedCategory(3),//3Dグラフィックス関係
		for2D = define_assignedCategory(4),//2Dグラフィックス関係
		forSound = define_assignedCategory(5),//サウンド関係
		forScript = define_assignedCategory(6),//スクリプト関係
		forGameData = define_assignedCategory(7),//ゲームデータ関係
		//ログレベル／画面通知レベル変更用
		forEvery = define_specialCategory(0),//全部まとめて変更
		//特殊なカテゴリ（プリント時専用）
		forCallppoint = define_specialCategory(1),//直近のコールポイントのカテゴリに合わせる（なければforAny扱い）
		forCriticalCallppoint = define_specialCategory(2),//直近の重大コールポイントのカテゴリに合わせる（なければforAny扱い）
	};
	//----------------------------------------
	//カテゴリ定義
#define declare_assignedCategory(value) struct category_##value : public category_assigned<value>{ category_##value () :category_assigned<value>(#value){} }
#define declare_reservedCategory(value) struct category_##value : public category_reserved<value>{ category_##value () :category_reserved<value>(#value){} }
#define declare_specialCategory(value, for_output, for_set_level) struct category_##value : public category_special<value, for_output, for_set_level>{ category_##value () :category_special<value, for_output, for_set_level>(#value){} }
	//※以下、ヘッダーで公開する必要なし
	declare_assignedCategory(forAny);//なんでも（カテゴリなし）
	declare_assignedCategory(forLogic);//プログラム関係
	declare_assignedCategory(forResource);//リソース関係
	declare_assignedCategory(for3D);//3Dグラフィックス関係
	declare_assignedCategory(for2D);//2Dグラフィックス関係
	declare_assignedCategory(forSound);//サウンド関係
	declare_assignedCategory(forScript);//スクリプト関係
	declare_assignedCategory(forGameData);//ゲームデータ関係
	//ログレベル／画面通知レベル変更用
	declare_specialCategory(forEvery, false, true);//全部まとめて変更
	//特殊なカテゴリ（プリント時専用）
	declare_specialCategory(forCallppoint, true, false);//直近のコールポイントのカテゴリに合わせる（なければforAny扱い）
	declare_specialCategory(forCriticalCallppoint, true, false);//直近の重大コールポイントのカテゴリに合わせる（なければforAny扱い）

	//----------------------------------------
	//カテゴリコンテナの静的変数をインスタンス化
	bool category::container::m_isInitialized = false;
	category* category::container::m_poolPtr = nullptr;
	category::byte category::container::m_pool[(POOL_NUM)* sizeof(category)];
	std::bitset<category::POOL_NUM> category::container::m_isAlreadyPool;
	//----------------------------------------
	//カテゴリコンテナ初期化（一回限り）
	void category::container::initializeOnce()
	{
		//初期化済みチェック
		if (m_isInitialized)
			return;
		//静的変数を初期化
		m_isInitialized = true;
		m_isAlreadyPool.reset();
		memset(m_pool, 0, sizeof(m_pool));
		m_poolPtr = reinterpret_cast<category*>(m_pool);
		//要素を初期化
		for (category::value_t value = 0; value < category::NUM; ++value)
		{
			category(value, "(undefined)", false, false, false);
			m_isAlreadyPool[value] = false;
		}
		//割り当て済みカテゴリを設定（コンストラクタで要素を登録）
		category_forAny();//なんでも（カテゴリなし）
		category_forLogic();//プログラム関係
		category_forResource();//リソース関係
		category_for3D();//3Dグラフィックス関係
		category_for2D();//2Dグラフィックス関係
		category_forSound();//サウンド関係
		category_forScript();//スクリプト関係
		category_forGameData();//ゲームデータ関係
		//ログレベル／画面通知レベル変更用
		category_forEvery();//全部まとめて変更
		//特殊なカテゴリ（プリント時専用）
		category_forCallppoint();//直近のコールポイントのカテゴリに合わせる（なければforAny扱い）
		category_forCriticalCallppoint();//直近の重大コールポイントのカテゴリに合わせる（なければforAny扱い）
		category_end();//終端
	}
	//----------------------------------------
	//カテゴリ用変数
	static category s_categoryForInitialize;//初期化処理実行のためのインスタンス
	//----------------------------------------
	//カテゴリコンテナ列挙
	void printCategoryAll()
	{
		for (auto& obj : category::container())//C++11スタイル
		//for (auto ite = category::container::begin(); ite != category::container::end(); ++ite)//旧来のスタイル
		//for (auto ite = category::container::cbegin(); ite != category::container::cend(); ++ite)//旧来のスタイル
		{
			//const category& obj = ite;//イテレータを変換（イテレータのままでもアロー演算子で直接値操作可能）
			printf("category=%d, name=\"%s\", isAssigned=%d, isReserved=%d, forOutput=%d, forSetLevel=%d\n", obj.value(), obj.name(), obj.isAssigned(), obj.isReserved(), obj.forOutput(), obj.forSetLevel());
		}
	}

	//----------------------------------------
	//ログ
	class log
	{
	public:
		//定数
		static const level::value_t DEFAULT_LOG_LEVEL = asNormal;//デフォルトログレベル
		static const level::value_t DEFAULT_NOTOICE_LEVEL = asCritical;//デフォルト画面通知レベル
	public:
		//メソッド
		//ログレベルを全てリセット
		static void resetLogLevelAll()
		{
			for (level::value_t& value : m_logLevel)
				value = DEFAULT_LOG_LEVEL;
		}
		//画面通知レベルを全てリセット
		static void resetNoticeLevelAll()
		{
			for (level::value_t& value : m_noticeLevel)
				value = DEFAULT_NOTOICE_LEVEL;
		}
		//ログレベル初期化（一回限り）
		static void initializeOnce();
		//現在のログレベルを取得
		static level::value_t getLogLv(const category::value_t category)
		{
			assert(category >= category::NORMAL_MIN && category <= category::NORMAL_MAX);
			return m_logLevel[category];
		}
		//現在のログレベルを変更
		//※指定の値以上のレベルのメッセージのみをログ出力する
		void setLogLv(const category::value_t category, const level::value_t level)
		{
			assert(category >= category::NORMAL_MIN && category <= category::NORMAL_MAX || category == forEvery);
			if (category == forEvery)
			{
				for (level::value_t& value : m_logLevel)
					value = level;
				return;
			}
			m_logLevel[category] = level;
		}
		//現在の画面通知レベルを取得
		static level::value_t getNoticeLv(const category::value_t category)
		{
			assert(category >= category::NORMAL_MIN && category <= category::NORMAL_MAX);
			return m_noticeLevel[category];
		}
		//現在の画面通知レベルを変更
		//※指定の値以上のレベルのメッセージのみをログ出力する
		static void seNoticeLv(const category::value_t category, const level::value_t level)
		{
			assert(category >= category::NORMAL_MIN && category <= category::NORMAL_MAX || category == forEvery);
			if (category == forEvery)
			{
				for (level::value_t& value : m_noticeLevel)
					value = level;
				return;
			}
			m_noticeLevel[category] = level;
		}
	public:
		//デフォルトコンストラクタ
		log()
		{
			initializeOnce();
		}
		//コンストラクタ
		log(const char* name):
			m_name(name)
		{
			memcpy(m_tempLogLevel, m_logLevel, sizeof(m_tempLogLevel));//一時ログレベル
			memcpy(m_tempNoticeLevel, m_noticeLevel, sizeof(m_tempNoticeLevel));//一時画面通知レベル
		}
		//デストラクタ
		~log()
		{}
	private:
		//フィールド
		const char* m_name;//処理名
		level::value_t m_tempLogLevel[category::NORMAL_NUM];//一時ログレベル
		level::value_t m_tempNoticeLevel[category::NORMAL_NUM];//一時画面通知レベル
		static bool m_isInitialized;//初期化済みフラグ
		static level::value_t m_logLevel[category::NORMAL_NUM];//現在のログレベル
		static level::value_t m_noticeLevel[category::NORMAL_NUM];//現在の画面通知レベル
	};
	//----------------------------------------
	//ログの静的変数をインスタンス化
	bool log::m_isInitialized;//初期化済みフラグ
	level::value_t log::m_logLevel[category::NORMAL_NUM];//現在のログレベル
	level::value_t log::m_noticeLevel[category::NORMAL_NUM];//現在の画面通知レベル
	//----------------------------------------
	//ログ初期化（一回限り）
	void log::initializeOnce()
	{
		//初期化済みチェック
		if (m_isInitialized)
			return;
		//静的変数を初期化
		m_isInitialized = true;
		resetLogLevelAll();
		resetNoticeLevelAll();
	}
	//----------------------------------------
	//カテゴリ用変数
	static log s_logForInitialize;//初期化処理実行のためのインスタンス
}//namespce dbgLog

namespace dbgLog
{
	//ユーザー拡張
	namespace ext
	{
		//----------------------------------------
		//カテゴリ定数
		enum categoryEnum : category::value_t
		{
			forReserved01 = define_revervedCategory(0),//(予約01)
			forReserved02 = define_revervedCategory(1),//(予約01)
			forReserved03 = define_revervedCategory(2),//(予約01)
		};
		//----------------------------------------
		//カテゴリ定義
		//※ヘッダーで公開する必要なし
		declare_reservedCategory(forReserved01);//(予約01)
		declare_reservedCategory(forReserved02);//(予約02)
		declare_reservedCategory(forReserved03);//(予約03)
		//----------------------------------------
		//カテゴリコンテナ拡張初期化
		struct categoryContainerExt
		{
			categoryContainerExt()
			{
				category::container::initializeOnce();
				category_forReserved01();//(予約01) 
				category_forReserved02();//(予約02)
				category_forReserved03();//(予約03)
			}
		};
		//----------------------------------------
		//変数
		static categoryContainerExt s_categoryForInitialize;//初期化処理実行のためのインスタンス
	}//namespace ext
}//namespace dbgLog
#if 0
};

	//ログレベル取得
	getLoglv(forAny);//戻り値としてログレベルが返る
	
	//Lv.1：通常メッセージ
	printAsNormal(forAny, "通常メッセージ by %s\n", name);
	//Lv.0：冗長メッセージ
	printAsVerbose(forAny, "冗長メッセージ by %s\n", name);
	//Lv.0：詳細メッセージ
	printAsDetail(forAny, "詳細メッセージ by %s\n", name);
	//Lv.2：重要メッセージ
	printAsImportant(forAny, "重要メッセージ by %s\n", name);
	//Lv.3：警告メッセージ
	printAsWarning(forAny, "警告メッセージ by %s\n", name);
	//LV.4：重大（問題）メッセージ
	printAsCritical(forAny, "重大メッセージ by %s\n", name);
	//Lv.5：絶対（必須）メッセージ
	printAsAbsolute(forAny, "絶対メッセージ by %s\n", name);

	//レベルを引数指定
	printLv(asNormal, forAny, "通常メッセージ by %s\n", name);
	//※数字で指定しても可
	//※Lv.0～5以外を指定した場合、ログレベルによらず何も出力されない
	printLv(2, forAny, "重要メッセージ by %s\n", name);
}


//----------------------------------------
//画面通知レベル

//画面通知レベル変更
//※ログレベルより低いレベルを設定しても通知されない
setNoticeLv(asCritical, forAny);//重大メッセージのみ画面通知
//※各レベルの推奨表示カラー
//　Lv.1：通常      ... 黒
//　Lv.0：冗長/詳細 ... （表示されない）
//　Lv.2：重要      ... 青
//　Lv.3：警告      ... 紫
//　Lv.4：重大      ... 赤
//　Lv.5：絶対      ... （表示されない）

//画面通知レベル取得
getNoticeLvAs(forAny);//戻り値として画面通知レベルが返る
#endif



//----------------------------------------
//コールポイント
class callPoint
{

};

//テスト
int main(const int argc, const char* argv[])
{
	//レベルを列挙
	dbgLog::printLevelAll();
	//カテゴリを列挙
	dbgLog::printCategoryAll();
	return EXIT_SUCCESS;
}

// End of file
