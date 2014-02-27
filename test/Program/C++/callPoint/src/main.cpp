//#define TLS_IS_POSIX//【GCC用】TLSの宣言をPOSIXスタイルにする時はこのマクロを有効にする
//#define ENABLE_CONSTEXPR//【C++11用】constexprを有効にする時はこのマクロを有効にする

#include <stdio.h>
#include <stdlib.h>

#include <limits.h>//UCHAR_MAX用
#include <bitset>//std::bitset用
#include <iterator>//std::iterator用

#include <atomic>//C++11アトミック型

//スレッドローカルストレージ修飾子
//※C++11仕様偽装
#ifdef TLS_IS_POSIX
#define thread_local __thread//POSIX仕様
#else//TLS_IS_POSIX
#define thread_local __declspec(thread)//Windows仕様
#endif//TLS_IS_POSIX

//constexpr対応
#ifdef ENABLE_CONSTEXPR
#define CONSTEXPR constexpr
#else//ENABLE_CONSTEXPR
#define CONSTEXPR const
#endif//ENABLE_CONSTEXPR

//--------------------------------------------------------------------------------
//デバッグログ
namespace dbgLog
{
	//----------------------------------------
	//レベル
	class level
	{
	public:
		//型
		typedef unsigned char value_t;//値（レベル）
		typedef unsigned char byte;//バッファ用
	public:
		//定数（計算用）
	#ifdef ENABLE_CONSTEXPR
		CONSTEXPR value_t calcPrintLevel(const value_t value){ return value >> 1; }//値を出力レベルに変換
		CONSTEXPR value_t calcFromPrintLevel(const value_t value){ return value << 1; }//出力レベルを値に変換
	#else//ENABLE_CONSTEXPR
		#define calcPrintLevel(value) ((value) >> 1)//値を出力レベルに変換
		#define calcFromPrintLevel(value) ((value) << 1)//出力レベルを値に変換
	#endif//ENABLE_CONSTEXPR
	public:
		//定数
		static const value_t ASSIGNED_NUM = 11;//割り当て済みレベル数
		static const value_t SPECIAL_NUM = 2;//特殊レベル数
		static const value_t NUM = ASSIGNED_NUM + SPECIAL_NUM;//レベル総数
		static const value_t MIN = 0;//レベル最小値
		static const value_t MAX = NUM - 1;//レベル最大値
		static const value_t ASSIGNED_MIN = MIN;//割り当て済みレベル最小値
		static const value_t ASSIGNED_MAX = ASSIGNED_MIN + ASSIGNED_NUM - 1;//割り当て済みレベル最大値
		static const value_t SPECIAL_MIN = ASSIGNED_MAX + 1;//特殊レベル最小値
		static const value_t SPECIAL_MAX = SPECIAL_MIN + SPECIAL_NUM - 1;//特殊レベル最大値
		static const value_t BEGIN = MIN;//レベル開始値（イテレータ用）
		static const value_t END = NUM;//レベル終了値（イテレータ用）
		static const value_t POOL_NUM = NUM + 1;//レベル記録数
		static const value_t PRINT_LEVEL_MIN = calcPrintLevel(ASSIGNED_MIN);//出力レベル最小値
		static const value_t PRINT_LEVEL_MAX = calcPrintLevel(ASSIGNED_MAX);//出力レベル最大値
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
			operator const level&() const { return container::get(m_value); }
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
			static const value_t endValue(){ return END; }//終了値取得
			static const level& get(const value_t value){ return m_poolPtr[value]; }//要素を取得
			static const level& getBegin(){ return m_poolPtr[beginValue()]; }//開始要素を取得
			static const level& getEnd(){ return m_poolPtr[endValue()]; }//終了要素を取得
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
			static const iterator end()	{ return iterator(endValue()); }//終了イテレータを取得
			static const_iterator cbegin(){ return const_iterator(beginValue()); }//開始constイテレータを取得
			static const_iterator cend(){ return const_iterator(endValue()); }//終了constイテレータを取得
			//※reverse_iterator非対応
		private:
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
		//キャストオペレータ
		operator int() const { return static_cast<int>(m_value); }
		operator value_t() const { return m_value; }
		operator const char*() const { return m_name; }
	public:
		//アクセッサ
		value_t value() const { return m_value; }//値（レベル）取得
		const char* name() const { return m_name; }//名前取得
		value_t printLevel() const { return calcPrintLevel(m_value); }//出力レベル取得
		bool isPrintLevel() const { return m_isPrintLevel; }//出力レベルとして使用可能か？
		bool isPrintLevelMask() const { return m_isPrintLevelMask; }//出力レベルマスクとして使用可能か？
	public:
		//メソッド
		//コンテナ要素を取得（ショートカット用）
		static const level& get(const value_t value){ return container::get(value); }
		//前のレベルを取得
		const level& prev() const
		{
			if (printLevel() <= PRINT_LEVEL_MIN || printLevel() > PRINT_LEVEL_MAX || !m_isPrintLevel)
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcFromPrintLevel(calcPrintLevel(m_value) - 1)];
		}
		//次のレベルを取得
		const level& next() const
		{
			if (printLevel() < PRINT_LEVEL_MIN || printLevel() >= PRINT_LEVEL_MAX || !m_isPrintLevel)
				return container::m_poolPtr[m_value];
			return container::m_poolPtr[calcFromPrintLevel(calcPrintLevel(m_value) + 1)];
		}
	public:
		//デフォルトコンストラクタ
		level() :
			m_value(UCHAR_MAX),
			m_name(nullptr),
			m_isPrintLevel(false),
			m_isPrintLevelMask(false)
		{
			container::initializeOnce();//コンテナ初期化（一回限り）
		}
		//コンストラクタ
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
			container::initializeOnce();//コンテナ初期化（一回限り）
			container::set(m_value, *this);//コンテナに登録
		}
		level(const value_t value) :
			m_value(value),
			m_name(nullptr),
			m_isPrintLevel(false),
			m_isPrintLevelMask(false)
		{
			*this = container::get(m_value);//コンテナから取得して自身にコピー
		}
		//デストラクタ
		~level()
		{}
	private:
		const value_t m_value;//値（レベル）
		const char* m_name;//名前
		const bool m_isPrintLevel;//出力レベルとして使用可能か？
		const bool m_isPrintLevelMask;//出力レベルマスクとして使用可能か？
	};
	//----------------------------------------
	//レベル定義用テンプレートクラス：割り当て済みレベル用
	template<unsigned char V>
	class level_assigned : public level
	{
	public:
		//定数
		static const value_t VALUE = V;//値（レベル）
		static_assert(VALUE >= ASSIGNED_MIN && VALUE <= ASSIGNED_MAX, "out of range of level");//値の範囲チェック
		static const bool IS_PRINT_LEVEL = true;//出力レベルとして使用可能か？
		static const bool IS_PRINT_LEVEL_MASK = true;//出力レベルマスクとして使用可能か？
	public:
		//コンストラクタ
		level_assigned(const char* name) :
			level(VALUE, name, IS_PRINT_LEVEL, IS_PRINT_LEVEL_MASK)
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
		static const bool IS_PRINT_LEVEL = false;//出力レベルとして使用可能か？
		static const bool IS_PRINT_LEVEL_MASK = true;//出力レベルマスクとして使用可能か？
	public:
		//コンストラクタ
		level_special(const char* name) :
			level(VALUE, name, IS_PRINT_LEVEL, IS_PRINT_LEVEL_MASK)
		{}
	};
	//----------------------------------------
	//レベル定義クラス：終了用
	class level_end : public level
	{
	public:
		//定数
		static const value_t VALUE = END;//値（レベル）
		static const bool IS_PRINT_LEVEL = false;//出力レベルとして使用可能か？
		static const bool IS_PRINT_LEVEL_MASK = false;//出力レベルマスクとして使用可能か？
	public:
		//コンストラクタ
		level_end() :
			level(VALUE, "(END)", IS_PRINT_LEVEL, IS_PRINT_LEVEL_MASK)
		{}
	};
	//----------------------------------------
	//レベル定数
#define define_assignedLevel(print_level, sub) (level::ASSIGNED_MIN + print_level * 2 + sub)
#define define_specialLevel(value) (level::SPECIAL_MIN + value)
	enum levelEnum : level::value_t
	{
		asNormal = define_assignedLevel(1, 0),//通常メッセージ
		asVerbose = define_assignedLevel(0, 0),//冗長メッセージ
		asDetail = define_assignedLevel(0, 1),//詳細メッセージ
		asImportant = define_assignedLevel(2, 0),//重要メッセージ
		asWarning = define_assignedLevel(3, 0),//警告メッセージ
		asCritical = define_assignedLevel(4, 0),//重大メッセージ
		asAbsolute = define_assignedLevel(5, 0),//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
		//以下、ログレベル／画面通知レベル変更用
		asSilent = define_specialLevel(0),//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
		asSilentAbsolutely = define_specialLevel(1),//絶対静寂（全てのメッセージを出力しない）
	};
	//----------------------------------------
	//レベル定義
#define declare_assignedLevel(value) struct level_##value : public level_assigned<value>{ level_##value () :level_assigned<value>(#value){} }
#define declare_specialLevel(value) struct level_##value : public level_special<value>{ level_##value () :level_special<value>(#value){} }
	declare_assignedLevel(asNormal);//通常メッセージ
	declare_assignedLevel(asVerbose);//冗長メッセージ
	declare_assignedLevel(asDetail);//詳細メッセージ
	declare_assignedLevel(asImportant);//重要メッセージ
	declare_assignedLevel(asWarning);//警告メッセージ
	declare_assignedLevel(asCritical);//重大メッセージ
	declare_assignedLevel(asAbsolute);//絶対メッセージ（ログレベルに関係なく出力したいメッセージ）
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
			level(value, "(undefined)", false, false);
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
	//変数
	static level s_levelForInitialize;//初期化処理実行のためのインスタンス
	//----------------------------------------
	//レベルコンテナ列挙
	void printLevelAll()
	{
		for (auto& lv : level::container())//C++11スタイル
		//for (auto ite = level::container::begin(); ite != level::container::end(); ++ite)//旧来のスタイル
		//for (auto ite = level::container::cbegin(); ite != level::container::cend(); ++ite)//旧来のスタイル
		{
			//const level& lv = ite;//イテレータを変換（イテレータのままでもアロー演算子で直接値操作可能）
			printf("level=%d, name=\"%s\", printLevel=%d, isPrintLevel=%d, isPrintLevelMask=%d\n", lv.value(), lv.name(), lv.printLevel(), lv.isPrintLevel(), lv.isPrintLevelMask());
			auto& prev = lv.prev();
			auto& next = lv.next();
			printf("           prev=%s(%d)\n", prev.name(), prev.value());
			printf("           next=%s(%d)\n", next.name(), next.value());
		}
	}

	//--------------------
	//カテゴリ定数
	//※制作スタッフにとって分かり易く、
	//　メッセージを仕込むプログラマーにとって
	//　分かり易い程度の分類にする
	//※forReserved**を任意の用途に割り当てて使用可
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
	declare_assignedCategory(forAny, 0);//なんでも（カテゴリなし）
	declare_assignedCategory(forLogic, 1);//プログラム関係
	declare_assignedCategory(forResource, 2);//リソース関係
	declare_assignedCategory(for3D, 3);//3Dグラフィックス関係
	declare_assignedCategory(for2D, 4);//2Dグラフィックス関係
	declare_assignedCategory(forSound, 5);//サウンド関係
	declare_assignedCategory(forScript, 6);//スクリプト関係
	declare_assignedCategory(forGameData, 7);//ゲームデータ関係
	//予約用（ユーザー定義用）
	declare_reservedCategory(forReserved01, 0);//(予約01)
	declare_reservedCategory(forReserved02, 1);//(予約02)
	declare_reservedCategory(forReserved03, 2);//(予約03)
	//ログレベル／画面通知レベル変更用
	declare_specialCategory(forEvery, 0);//全部まとめて変更
	//特殊なカテゴリ（プリント時専用）
	declare_specialCategory(forCallppoint, 1);//直近のコールポイントのカテゴリに合わせる（なければforAny扱い）
	declare_specialCategory(forCriticalCallppoint, 2);//直近の重大コールポイントのカテゴリに合わせる（なければforAny扱い）
}
#if 0
	//----------------------------------------
	//ログレベル操作
	//--------------------
	//ログレベルを全てリセット
	static void resetLogLevelAll()
	{
		for (E_MESSAGE_LV& level : m_logLevel)
			level = asNormal;
	}
	//--------------------
	//画面通知レベルを全てリセット
	static void resetNoticeLevelAll()
	{
		for (E_MESSAGE_LV& level : m_noticeLevel)
			level = asCritical;
	}
	//--------------------
	//ログレベルと画面通知レベルをまだ初期化していなければ初期化
	static void initializeLogLevelAll()
	{
		if (m_logLevelIsInitialized)
			return;
		resetLogLevelAll();
		resetNoticeLevelAll();
		m_logLevelIsInitialized = true;
	}
	//--------------------
	//現在のログレベルを取得
	static E_MESSAGE_LV getLogLv(const E_MESSAGE_CATEGOY category)
	{
		return m_logLevel[category];
	}
	//--------------------
	//現在のログレベルを変更
	//※指定の値以上のレベルのメッセージのみをログ出力する
	void setLogLv(const E_MESSAGE_CATEGOY category, const E_MESSAGE_LV level)
	{
		m_logLevel[category] = level;
	}
	//--------------------
	//現在の画面通知レベルを取得
	static E_MESSAGE_LV getLogLv(const E_MESSAGE_CATEGOY category)
	{
		return m_logLevel[category];
	}
	//--------------------
	//現在の画面通知レベルを変更
	//※指定の値以上のレベルのメッセージのみをログ出力する
	static void setLogLv(const E_MESSAGE_CATEGOY category, const E_MESSAGE_LV level)
	{
		m_logLevel[category] = level;
	}
private:
	//--------------------
	//静的変数
	static E_MESSAGE_LV m_logLevel[categoryNum];//現在のログレベル
	static E_MESSAGE_LV m_noticeLevel[categoryNum];//現在の画面通知レベル
	static bool m_logLevelIsInitialized;//現在のログレベルと画面通知レベル初期化済みフラグ
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
	return EXIT_SUCCESS;
}

// End of file
