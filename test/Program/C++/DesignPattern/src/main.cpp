#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <vector>
#include <iterator>
//#include <algorithm>

#include <glm/glm.hpp>

//================================================================================
//Observerパターン

//----------------------------------------
//【準備】C++11非対応のコンパイラなら、override, final キーワードを何もしないマクロで代用
//#define override
//#define final

//----------------------------------------

//--------------------
//【ライブラリ側】委譲インターフェース
template<class T>
class IDelegate
{
public:
	//更新処理
	virtual void update(T& target) = 0;
};

//--------------------
//【ライブラリ側】委譲オブジェクト登録クラス
template<class T>
class CDelegateRegister
{
public:
	//委譲オブジェクト登録
	void registDelegate(IDelegate<T>* delegate){ m_delegate = delegate; }
	//更新処理
	void update()
	{
		printf("CDelegateRegister<T>::update() : m_delete->update()\n");
		if (m_delegate)
		{
			m_delegate->update(m_target);
		}
	}
public:
	//コンストラクタ
	CDelegateRegister(T& target) : m_target(target), m_delegate(nullptr) {}
private:
	//フィールド
	T& m_target;//対象オブジェクト
	IDelegate<T>* m_delegate;//委譲オブジェクト
};

//--------------------
//【ライブラリ側】共通システム１クラス
class CCommonSystem1
{
public:
	//委譲オブジェクト登録
	void registDelegate(IDelegate<CCommonSystem1>* delegate){ m_delegateRegister.registDelegate(delegate); }
	//更新処理
	void update()
	{
		printf("CCommonSystem1::update()\n");

		//更新処理の委譲
		m_delegateRegister.update();
	}
	//メッセージ取得
	const char* getMessage() const{ return "CCommonSystem1's message";  }
public:
	//コンストラクタ
	CCommonSystem1() : m_delegateRegister(*this) {}
private:
	//フィールド
	CDelegateRegister<CCommonSystem1> m_delegateRegister;//委譲オブジェクト
};

//--------------------
//【ライブラリ側】共通システム２クラス
class CCommonSystem2
{
public:
	//委譲オブジェクト登録
	void registDelegate(IDelegate<CCommonSystem2>* delegate){ m_delegateRegister.registDelegate(delegate); }
	//更新処理
	void update()
	{
		printf("CCommonSystem2::update()\n");

		//更新処理の委譲
		m_delegateRegister.update();
	}
	//システム名取得
	const char* getSystemName() const{ return "Common System 2"; }
public:
	//コンストラクタ
	CCommonSystem2() : m_delegateRegister(*this) {}
private:
	//フィールド
	CDelegateRegister<CCommonSystem2> m_delegateRegister;//委譲オブジェクト
};

//----------------------------------------

//--------------------
//【タイトル側】独自システム
class CMySystem
{
public:
	//共通処理１向けの拡張更新処理
	void updateSystem1(CCommonSystem1& target)
	{
		printf("CMySystem::updateSystem1() : target.getMessage()=\"%s\"\n", target.getMessage());
	}
	//共通処理２向けの拡張更新処理
	void updateSystem2(CCommonSystem2& target)
	{
		printf("CMySystem::updateSystem2() : target.getSystemName()=\"%s\"\n", target.getSystemName());
	}
private:
	//共通処理システム１向けのオブザーバー（委譲オブジェクト）
	class CObserver1 : public IDelegate<CCommonSystem1>
	{
	public:
		//更新処理
		void update(CCommonSystem1& target) override
		{
			m_this.updateSystem1(target);
		}
	public:
		CObserver1(CMySystem& me) : m_this(me) {}
	private:
		CMySystem& m_this;
	};
	//共通処理システム２向けのオブザーバー（委譲オブジェクト）
	class CObserver2 : public IDelegate<CCommonSystem2>
	{
	public:
		//更新処理
		void update(CCommonSystem2& target) override
		{
			m_this.updateSystem2(target);
		}
	public:
		CObserver2(CMySystem& me) : m_this(me) {}
	private:
		CMySystem& m_this;
	};
public:
	//コンストラクタ
	CMySystem(CCommonSystem1& sys1, CCommonSystem2& sys2) :
		m_observer1(*this),
		m_observer2(*this)
	{
		//オブザーバー登録
		sys1.registDelegate(&m_observer1);
		sys2.registDelegate(&m_observer2);
	}
private:
	//フィールド
	CObserver1 m_observer1;//共通処理システム１向けのオブザーバー
	CObserver2 m_observer2;//共通処理システム２向けのオブザーバー
};

//----------------------------------------
//Observerパターンテストメイン関数
void testObserver()
{
	printf("\n- testObserver() -\n\n");

	CCommonSystem1 sys1; //共通システム１
	CCommonSystem2 sys2; //共通システム２
	CMySystem my_sys(sys1, sys2); //独自システム

	//共通システムの更新処理
	sys1.update();
	sys2.update();
	//※共通システム側の処理実行時に、「独自システム」のオブザーバーに処理が委譲される
}

//================================================================================
//Adapterパターン

//----------------------------------------
//【準備】C++11非対応のコンパイラなら、override, final キーワードを何もしないマクロで代用
//#define override
//#define final

//----------------------------------------
//【準備】ベクトル演算型定義
typedef glm::vec3 vec3;//GLM利用

//----------------------------------------
//【準備】共通関数
template<typename T, std::size_t N1> std::size_t lengthOfArray(const T(&var)[N1]){ return N1; } //配列の要素数を返す（型安全版）
//template<typename T> T max(T var1, Tvar2){ return var1 > var2 ? var1 : var2; }                //大きい方の値を返す（型安全版）
//#define lengthOfArray(var) (sizeof(var1) / sizeof(var1[0])                                    //配列の要素数を返す
#define max(var1, var2) (var1 > var2 ? var1 : var2)                                             //大きい方の値を返す

//----------------------------------------

//--------------------
//NPC
class CNPC //※何の共通インターフェースも実装していない
{
public:
	const char* getName() const { return m_name; }       //名前を取得
	const vec3& getPos() const { return m_pos; }         //位置を取得
	void setPos(const vec3 pos) { m_pos = pos; }         //位置を更新
	float getRotY() const { return m_rot_y; }            //Y軸の向きを取得
	void setRotY(const float rot_y) { m_rot_y = rot_y; } //Y軸の向きを更新
public:
	//コンストラクタ
	CNPC(const char* name, const vec3 pos, const float rot_y) :
		m_name(name),
		m_pos(pos),
		m_rot_y(rot_y)
	{}
private:
	//フィールド
	const char* m_name;//名前
	vec3 m_pos;        //位置
	float m_rot_y;     //Y軸の向き
};

//--------------------
//宝箱
class CTBox //※何の共通インターフェースも実装していない
{
public:
	int getID() const { return m_id; }           //IDを取得
	const vec3& getPos() const { return m_pos; } //位置を取得
	float getRotY() const { return m_rot_y; }    //Y軸の向きを取得
public:
	//コンストラクタ
	CTBox(const int id, const vec3 pos, const float rot_y) :
		m_id(id),
		m_pos(pos),
		m_rot_y(rot_y)
	{}
private:
	//フィールド
	const int m_id;     //ID
	const vec3 m_pos;   //位置
	const float m_rot_y;//Y軸の向き
};

//----------------------------------------

//--------------------
//外部システム１
namespace other_system1
{
	//変数
	static int s_npc_num = 0;
	static CNPC* s_npc[10];
	
	//初期化
	void init()
	{
		s_npc[s_npc_num++] = new CNPC("太郎", vec3(10.f, 11.f, 12.f), 0.1f);
		s_npc[s_npc_num++] = new CNPC("次郎", vec3(20.f, 21.f, 22.f), 0.2f);
		s_npc[s_npc_num++] = new CNPC("三郎", vec3(30.f, 31.f, 32.f), 0.3f);
		s_npc[s_npc_num++] = new CNPC("四朗", vec3(40.f, 41.f, 42.f), 0.4f);
		s_npc[s_npc_num++] = new CNPC("五朗", vec3(50.f, 51.f, 52.f), 0.5f);
	}
	
	//周辺のNPC情報を収集
	int findAroundNPC(CNPC* ref_npc[], const int ref_max)
	{
		int ref_num = 0;
		for (int index = 0; index < s_npc_num && index < ref_max; ++index)
		{
			ref_npc[ref_num++] = s_npc[index];
		}
		return ref_num;
	}
}

//--------------------
//外部システム２
namespace other_system2
{
	//変数
	static int s_tbox_num = 0;
	static CTBox* s_tbox[10];

	//初期化
	void init()
	{
		s_tbox[s_tbox_num++] = new CTBox(101, vec3(15.f, 15.f, 15.f), 1.1f);
		s_tbox[s_tbox_num++] = new CTBox(102, vec3(25.f, 25.f, 25.f), 1.2f);
		s_tbox[s_tbox_num++] = new CTBox(103, vec3(35.f, 35.f, 35.f), 1.3f);
		s_tbox[s_tbox_num++] = new CTBox(104, vec3(45.f, 45.f, 45.f), 1.4f);
		s_tbox[s_tbox_num++] = new CTBox(105, vec3(55.f, 55.f, 55.f), 1.5f);
	}

	//周辺の宝箱情報を収集
	int findAroundTBox(CTBox* ref_tbox[], const int ref_max)
	{
		int ref_num = 0;
		for (int index = 0; index < s_tbox_num && index < ref_max; ++index)
		{
			ref_tbox[ref_num++] = s_tbox[index];
		}
		return ref_num;
	}
}

//----------------------------------------

//--------------------
//ターゲット用アダプターインターフェース
class ITargetAdapter
{
public:
	virtual void getIdentifier(char* buff, const size_t buff_size) const = 0;//識別情報を取得
	virtual const vec3& getPos() const = 0;                                  //位置を取得
	virtual float getRotY() const = 0;                                       //Y軸の向きを取得
};

//--------------------
//NPC向けターゲット用アダプター
class CTargetAdapterNPC : public ITargetAdapter
{
public:
	//識別情報を取得
	void getIdentifier(char* buff, const size_t buff_size) const override
	{
		sprintf_s(buff, buff_size, "NPC\"%s\"", m_npc.getName());
	}
	//位置を取得
	const vec3& getPos() const override
	{ 
		return m_npc.getPos();
	}
	//Y軸の向きを取得
	float getRotY() const override
	{
		return m_npc.getRotY();
	}
public:
	//コンストラクタ
	CTargetAdapterNPC(CNPC& npc) :
		m_npc(npc)
	{}
private:
	//フィールド
	CNPC& m_npc;//NPC
};

//--------------------
//宝箱向けターゲット用アダプター
class CTargetAdapterTBox : public ITargetAdapter
{
public:
	//識別情報を取得
	void getIdentifier(char* buff, const size_t buff_size) const override
	{
		sprintf_s(buff, buff_size, "宝箱(%d)", m_tbox.getID());
	}
	//位置を取得
	const vec3& getPos() const override
	{
		return m_tbox.getPos();
	}
	//Y軸の向きを取得
	float getRotY() const override
	{
		return m_tbox.getRotY();
	}
public:
	//コンストラクタ
	CTargetAdapterTBox(CTBox& tbox) :
		m_tbox(tbox)
	{}
private:
	//フィールド
	CTBox& m_tbox;//宝箱
};

//----------------------------------------

//--------------------
//ターゲット処理用配置new
class CTargetCollector;
void* operator new(std::size_t size, const CTargetCollector*, void* buff){ return buff; }//コンストラクタ実行用に与えられたポインターをそのまま返すだけ
void operator delete(void* mem, const CTargetCollector*, void* buff){}//ダミー：なにしない（配置newとdeleteは一対で登録しないとダメ）

//--------------------
//ターゲット収集処理クラス
class CTargetCollector
{
public:
	//周辺のターゲット情報を収集
	void findAroundTarget()
	{
		//周辺のNPC情報を収集
		CNPC* ref_npc[4];
		const int ref_npc_num = other_system1::findAroundNPC(ref_npc, lengthOfArray(ref_npc));

		//周辺の宝箱情報を収集
		CTBox* ref_tbox[3];
		const int ref_tbox_num = other_system2::findAroundTBox(ref_tbox, lengthOfArray(ref_tbox));

		//ターゲット情報に置き換え
		m_numTargets = 0;
		{
			//NPC情報をターゲット情報に置き換え
			for (int index = 0; index < ref_npc_num; ++index)
			{
				if (m_numTargets < MAX_TARGETS)
				{
					try
					{
						m_target[m_numTargets] = new(this, m_targetBuff[m_numTargets]) CTargetAdapterNPC(*ref_npc[index]);
						++m_numTargets;
					}
					catch (...)
					{
						fprintf(stderr, "CTargetAdapterNPC allocation failure.\n");
					}
				}
			}
			//宝箱情報をターゲット情報に置き換え
			for (int index = 0; index < ref_tbox_num; ++index)
			{
				if (m_numTargets < MAX_TARGETS)
				{
					try
					{
						m_target[m_numTargets] = new(this, m_targetBuff[m_numTargets]) CTargetAdapterTBox(*ref_tbox[index]);
						++m_numTargets;
					}
					catch (...)
					{
						fprintf(stderr, "CTargetAdapterTBox allocation failure.\n");
					}
				}
			}
			//ターゲット情報のソート（スクリーン座標で横並びに）
			//...の代わりにシャッフル
			srand(static_cast<unsigned int>(time(nullptr)));
			const int shuffle_num = rand() % 20;
			for (int num = 0; num < shuffle_num; ++num)
			{
				const int index1 = rand() % m_numTargets;
				const int index2 = rand() % m_numTargets;
				ITargetAdapter* target_temp = m_target[index1];
				m_target[index1] = m_target[index2];
				m_target[index2] = target_temp;
			}
		}
	}
	//ターゲット情報を取得
	ITargetAdapter* getTarget(const int index)
	{
		if (index < 0 || index >= m_numTargets)
			return nullptr;
		return m_target[index];
	}
	//ターゲット情報数を取得
	int getTargetNum() const{ return m_numTargets; }
public:
	//コンストラクタ
	CTargetCollector() :
		m_numTargets(0)
	{}
private:
	//フィールド
	static const std::size_t MAX_TARGETS = 10;                                                                       //ターゲット情報の最大数
	static const std::size_t MAX_SIZE_OF_TARGET_ADAPTER = max(sizeof(CTargetAdapterNPC), sizeof(CTargetAdapterTBox));//ターゲット情報用バッファのサイズ
	char m_targetBuff[MAX_TARGETS][MAX_SIZE_OF_TARGET_ADAPTER];//ターゲット情報用のバッファ
	ITargetAdapter* m_target[MAX_TARGETS];                     //ターゲット情報
	int m_numTargets;                                          //ターゲット数
};

//----------------------------------------
//Adapterパターンテストメイン関数
void testAdapter()
{
	printf("\n- testAdapter() -\n\n");
	
	//外部システム１初期化
	other_system1::init();

	//外部システム２初期化
	other_system2::init();

	//周辺のターゲット情報を収集
	CTargetCollector target_coll;
	target_coll.findAroundTarget();

	//ターゲット情報を表示
	//※ターゲットがNPCか宝箱か気にせず一律の処理を行っている
	for (int index = 0; index < target_coll.getTargetNum(); ++index)
	{
		ITargetAdapter* target = target_coll.getTarget(index);
		if (target)
		{
			//アダプターの作用により、実際にはNPCと宝箱のそれぞれ固有の処理が実行されている
			char identifier[128];
			target->getIdentifier(identifier, sizeof(identifier));
			const vec3& pos = target->getPos();
			const float rot_y = target->getRotY();
			printf("[%d] \"%s\" pos=(%.1f, %.1f, %.1f) rot=(%.1f)\n", index, identifier, pos[0], pos[1], pos[2], rot_y);
		}
	}
}

//================================================================================
//Proxyパターン(1)

//----------------------------------------
//【準備】C++11非対応のコンパイラなら、override, final キーワードを何もしないマクロで代用
//#define override
//#define final

//----------------------------------------

//--------------------
//キャラクターインターフェースクラス
class CCharacter;
class ICharacter
{
public:
	//処理更新
	virtual void update() = 0;
	//描画処理
	virtual void draw() = 0;
	//構築済みフラグ取得
	virtual bool isBuilt() const = 0;
	//本体取得
	virtual const CCharacter* getReal() const = 0;
};

//--------------------
//キャラクタークラス
class CCharacter : public ICharacter
{
public:
	//処理更新
	void update() override
	{
		//処理経過
		++m_step;
		
		//2ステップ以上経過したら、1/4の確率で構築完了ということにする
		if (m_step > 2 && rand() % 4 == 0)
		{
			m_isBuilt = true;
		}
	}
	//描画処理
	void draw() override
	{
		printf("This is real \"%s\"!\n", m_name);
	}
	//構築済みフラグ取得
	bool isBuilt() const override
	{
		return m_isBuilt;
	}
	//本体取得
	const CCharacter* getReal() const override
	{
		return this;
	}
public:
	//アクセッサ
	const char* getName() const { return m_name; }//名前取得
	int getStep() const { return m_step; }        //処理ステップ取得
public:
	//コンストラクタ
	CCharacter(const char* name) :
		m_name(name),
		m_step(0),
		m_isBuilt(false)
	{}
private:
	//フィールド
	const char* m_name;//名前
	int m_step;//処理ステップ
	bool m_isBuilt;//構築済みフラグ
};

//----------------------------------------

//--------------------
//ローディング中のキャラクター代理クラス
class CCharacterProxy : public ICharacter
{
public:
	//処理更新
	virtual void update() override
	{
		m_realObj->update();//委譲
	}
	//描画処理
	virtual void draw()
	{
		printf("Now is loading \"%s\"... (step=%d)\n", m_realObj->getName(), m_realObj->getStep());
	}
	//構築済みフラグ取得
	bool isBuilt() const override
	{
		return false;
	}
	//本体取得
	const CCharacter* getReal() const override
	{
		return m_realObj;
	}
public:
	//本来の実体をセット
	void setRealObj(CCharacter* real_obj)
	{
		m_realObj = real_obj;
	}
public:
	//コンストラクタ
	CCharacterProxy() :
		m_realObj(nullptr)
	{}
private:
	//フィールド
	CCharacter* m_realObj;//本来の実体
};

//--------------------
//キャラクターコレクション
class CCharacterCollection
{
public:
	//--------------------
	//イテレータクラス
	class CIterator
	{
	public:
		//イテレータ用型宣言
		typedef CIterator type;
		typedef ICharacter* value_type;
	public:
		//イテレータ用オペレータ
		operator value_type() { return m_chara; }            //キャスト
		operator const value_type() const { return m_chara; }//キャスト
		value_type operator->() { return m_chara; }             //参照
		const value_type operator->() const { return m_chara; } //const参照
		ICharacter& operator*() { return *m_chara; }            //実体化
		const ICharacter& operator*() const { return *m_chara; }//const実体化
		type& operator++() { ++m_index; m_chara = m_coll[m_index]; return *this; }//前置インクリメント
		type operator++(int) { type prev = *this; ++(*this); return prev; }       //後置インクリメント
		type& operator--() { --m_index; m_chara = m_coll[m_index]; return *this; }//前置デクリメント
		type operator--(int) { type prev = *this; --(*this); return prev; }       //後置デクリメント
		bool operator==(const type& ite) const//比較
		{
			if (m_chara == nullptr && ite.m_chara == nullptr)
				return true;
			if (m_chara == nullptr || ite.m_chara == nullptr)
				return false;
			return m_chara->getReal() == ite->getReal();
		}
		bool operator!=(const type& ite) const//比較
		{
			return !(*this == ite);
		}
	public:
		//コンストラクタ
		CIterator(CCharacterCollection& coll, const int index) :
			m_coll(coll),
			m_index(index)
		{
			m_chara = m_coll[index];
		}
	private:
		//フィールド
		CCharacterCollection& m_coll;//キャラクターコレクション
		int m_index;                 //コレクションのカレントインデックス
		ICharacter* m_chara;         //キャラクターオブジェクト
	};

public:
	//イテレータ―用メソッド
	CIterator begin() { CIterator ite(*this, 0); return ite; }       //先頭イテレータを返す
	CIterator end() { CIterator ite(*this, m_charaNum); return ite; }//終端イテレータを返す
	bool empty() const { return m_charaNum == 0; }                   //要素が空か？
	int size() const { return m_charaNum; }                          //要素数を返す
	ICharacter* operator[](const int index)                          //要素を返す　※ここでプロキシーに対応
	{
		if (index < 0 || index >= m_charaNum)
			return nullptr;
		CCharacter* realChara = m_chara[index];
		ICharacter* chara = realChara;
		if (!realChara->isBuilt())
		{
			//構築が済んでいない場合、プロキシ―を返す
			static CCharacterProxy proxy;//プロキシーのインスタンス（再利用する：一種のFlyweightパターン）
			proxy.setRealObj(realChara);
			chara = &proxy;
		}
		return chara;
	}
public:
	//キャラ追加
	void addChara(const char* name)
	{
		if (m_charaNum >= CHARA_MAX)
			return;
		CCharacter* chara = new CCharacter(name);
		if (chara)
		{
			m_chara[m_charaNum++] = chara;
		}
	}
public:
	//コンストラクタ
	CCharacterCollection() :
		m_charaNum(0)
	{}
	//デストラクタ
	~CCharacterCollection()
	{
		//全て削除
		for (int index = 0; index < m_charaNum; ++index)
		{
			if (m_chara[index])
			{
				delete m_chara[index];
				m_chara[index] = nullptr;
			}
		}
	}
private:
	//フィールド
	static const int CHARA_MAX = 32;//キャラ情報の最大数
	CCharacter* m_chara[CHARA_MAX]; //キャラ情報
	int m_charaNum;                 //キャラ情報数
};
//自作for_each
template<class T, class F>
void my_for_each(T ite, T end, F functor)
{
	for (; ite != end; ++ite)
	{
		functor(ite);
	}
}
template<class T, class F, class P1>
void my_for_each(T ite, T end, F functor, P1& param1)
{
	for (; ite != end; ++ite)
	{
		functor(ite, param1);
	}
}

//----------------------------------------

//--------------------
//共通処理システム
namespace common_system
{
	//キャラクター更新処理（関数オブジェクト）
	struct Update
	{
		void operator()(ICharacter* chara)
		{
			chara->update();
		}
	};
	
	//キャラクター描画処理（関数オブジェクト）
	struct Draw
	{
		void operator()(ICharacter* chara)
		{
			chara->draw();
		}
	};

	//キャラクター構築完了チェック
	struct isBuiltAll
	{
		void operator()(ICharacter* chara, bool& is_built_all)
		{
			if (!chara->isBuilt())
			{
				is_built_all = false;
			}
		}
	};
};

//----------------------------------------
//Proxyパターン(2)テストメイン関数
void testProxy1()
{
	printf("\n- testProxy1() -\n\n");

	//キャラクター生成
	CCharacterCollection chara_coll;
	chara_coll.addChara("太郎");
	chara_coll.addChara("次郎");
	chara_coll.addChara("三郎");
	chara_coll.addChara("四郎");
	chara_coll.addChara("五郎");

	//全キャラクターの構築が完了するまで処理
	for (int step = 0; ; ++step)
	{
		printf("- step: %d -\n", step);
		my_for_each(chara_coll.begin(), chara_coll.end(), common_system::Update());
		my_for_each(chara_coll.begin(), chara_coll.end(), common_system::Draw());
		bool is_built_all = true;
		my_for_each(chara_coll.begin(), chara_coll.end(), common_system::isBuiltAll(), is_built_all);
		if (is_built_all)
		{
			printf("- finish. -\n");
			break;
		}
	}
}

//================================================================================
//Proxyパターン(2)：簡易版スマートポインター

//----------------------------------------
//簡易版スマートポインターのテンプレートクラス
template<class T>
class CSmartPtr
{
private:
	//参照情報型
	struct T_REF_INFO
	{
		T* m_realObj;//本当のオブジェクト
		int m_refCount;//参照カウンタ
		//コンストラクタ
		T_REF_INFO(T* real_obj, const int ref_count) :
			m_realObj(real_obj),
			m_refCount(ref_count)
		{}
		T_REF_INFO(T_REF_INFO& info) :
			m_realObj(info.m_realObj),
			m_refCount(info.m_refCount)
		{}
	};
public:
	//オペレータを実装して本来のオブジェクトを偽装（代理）
	T* operator->(){ return m_refInfo ? m_refInfo->m_realObj : nullptr; }
	const T* operator->() const { return m_refInfo ? m_refInfo->m_realObj : nullptr; }
	T& operator*(){ return *m_refInfo->m_realObj; }
	const T& operator*() const { return *m_refInfo->m_realObj; }
	//代入演算子：スマートポインターを代入
	CSmartPtr<T>& operator=(CSmartPtr<T>& obj)
	{
		//すでに参照しているならなにもしない
		if (m_refInfo == obj.m_refInfo)
			return *this;
		
		//参照カウンタをカウントダウン
		release();
			
		//参照情報をコピー
		m_refInfo = obj.m_refInfo;
			
		//参照カウンタをカウントアップ
		addRef();
		
		return *this;
	}
	//代入演算子：ポインターを代入
	CSmartPtr<T>& operator=(T* real_obj)
	{
		//すでに参照しているならなにもしない
		if (m_refInfo && m_refInfo->m_realObj == real_obj)
			return *this;
		
		//参照カウンタをカウントダウン
		release();
		
		if (real_obj)//nullptr 代入時はなにもしない
		{
			//参照情報を生成
			m_refInfo = new T_REF_INFO(real_obj, 1);
		}
		return *this;
	}
private:
	//参照カウンタをカウントアップ
	void addRef()
	{
		if (!m_refInfo)
			return;
		++m_refInfo->m_refCount;
	}
	//参照カウンタをカウントダウン
	void release()
	{
		if (!m_refInfo)
			return;
		if (m_refInfo->m_refCount > 0)
		{
			--m_refInfo->m_refCount;
			if (m_refInfo->m_refCount == 0)
			{
				//参照カウンタが0になったらオブジェクトを削除
				if (m_refInfo->m_realObj)
				{
					delete m_refInfo->m_realObj;//本当のオブジェクトを削除
					m_refInfo->m_realObj = nullptr;
				}
				delete m_refInfo;//参照情報も削除
			}
		}
		m_refInfo = nullptr;
	}
public:
	//コンストラクタ
	CSmartPtr(T* real_obj)
	{
		//参照情報を生成
		m_refInfo = new T_REF_INFO(real_obj, 1);
	}
	//コピーコンストラクタ
	CSmartPtr(CSmartPtr<T>& smart_ptr)
	{
		//参照情報をコピー
		m_refInfo = smart_ptr.m_refInfo;
		
		//参照カウンタをカウントアップ
		addRef();
	}
	//デストラクタ
	~CSmartPtr()
	{
		//参照カウンタをカウントダウン
		release();
	}
private:
	//フィールド
	T_REF_INFO* m_refInfo;//参照情報
};

//----------------------------------------
//テスト用クラス
//※これ自体は何のインターフェースも持たない普通のクラス
//　このクラスをスマートポインターで扱う
class CTest
{
public:
	//アクセッサ
	const char* getName() const { return m_name; }
public:
	//コンストラクタ
	CTest(const char* name)
	{
		printf("CTest::Ctest(\"%s\")\n", name);
		m_name = name;
	}
	//デストラクタ
	~CTest()
	{
		printf("CTest::~Ctest() : m_name=\"%s\"\n", m_name);
	}
private:
	//フィールド
	const char* m_name;//名前
};

//----------------------------------------
//Proxyパターン(2)テストメイン関数
void testProxy2()
{
	printf("\n- testProxy2() -\n\n");

	//スマートポインターで CTest のインスタンスを生成
	//自由にコピーしても、適切な開放を行ってくれる
	//【注意】
	//関数にスマートポインターを渡す時は、値渡しにしないと
	//関数内でdeleteが発生する事に注意。

	printf("(begin function)\n");
	CSmartPtr<CTest> obj1 = new CTest("太郎");
	printf("[01] obj1->getName()=\"%s\"\n", obj1->getName());
	printf("     (*obj1).getName()=\"%s\"\n", (*obj1).getName());
	CSmartPtr<CTest> obj2 = new CTest("次郎");
	printf("[02] obj2->getName()=\"%s\"\n", obj2->getName());
	CSmartPtr<CTest> obj3 = new CTest("三郎");
	printf("[03] obj3->getName()=\"%s\"\n", obj3->getName());
	{
		printf("(begin block)\n");
		CSmartPtr<CTest> obj4 = new CTest("四朗");
		printf("[04] obj4->getName()=\"%s\"\n", obj4->getName());
		CSmartPtr<CTest> obj5 = new CTest("五郎");
		printf("[05] obj5->getName()=\"%s\"\n", obj5->getName());
		printf("obj2 = obj4\n");
		obj2 = obj4;//スマートポインターの代入：「次郎」の delete が行われる
		printf("[06] obj1->getName()=\"%s\"\n", obj1->getName());
		printf("     obj2->getName()=\"%s\"\n", obj2->getName());
		printf("     obj3->getName()=\"%s\"\n", obj3->getName());
		printf("     obj4->getName()=\"%s\"\n", obj4->getName());
		printf("     obj5->getName()=\"%s\"\n", obj5->getName());
		printf("obj1 = obj2\n");
		obj1 = obj2;//スマートポインターの代入：「太郎」の delete が行われる
		printf("[07] obj1->getName()=\"%s\"\n", obj1->getName());
		printf("     obj2->getName()=\"%s\"\n", obj2->getName());
		printf("     obj3->getName()=\"%s\"\n", obj3->getName());
		printf("     obj4->getName()=\"%s\"\n", obj4->getName());
		printf("     obj5->getName()=\"%s\"\n", obj5->getName());
		//ブロック終了：「五郎」のdelete が行われる
		printf("(end block)\n");
	}
	printf("[08] obj1->getName()=\"%s\"\n", obj1->getName());
	printf("     obj2->getName()=\"%s\"\n", obj2->getName());
	printf("     obj3->getName()=\"%s\"\n", obj3->getName());
	printf("obj3 = nullptr\n");
	obj3 = nullptr;//obj3を明示的に解放：「三郎」のdelete が行われる
	printf("[09] obj1->getName()=\"%s\"\n", obj1->getName());
	printf("     obj2->getName()=\"%s\"\n", obj2->getName());
//	printf("     obj3->getName()=\"%s\"\n", obj3->getName());//エラー
	printf("obj2 = nullptr\n");
	obj2 = nullptr;//obj2を明示的に解放：「四朗」のdelete は行われない
	printf("[10] obj1->getName()=\"%s\"\n", obj1->getName());
//	printf("     obj2->getName()=\"%s\"\n", obj2->getName());//エラー
//	printf("     obj3->getName()=\"%s\"\n", obj3->getName());//エラー
	//obj1は明示的な解放しない
	printf("(end function)\n");
	//関数終了：関数を抜ける時に「四朗」の delete が行われる
}

//================================================================================
void testSTLvector()
{
	printf("\n- testSTLvector() -\n\n");

	class MyClass
	{
	public:
		MyClass(const char* name) :
			m_name(name)
		{}
		~MyClass(){}
	private:
		const char* m_name;
	};
	printf("std::vector<MyClass> array;\n");
	std::vector<MyClass> array;
	printf("array.reserve(3);\n");
	array.reserve(3);
	printf("array.push_back(MyClass(\"太郎\"));\n");
	array.push_back(MyClass("太郎"));
	printf("array.size()=%d\n", array.size());
	printf("array.capacity()=%d\n", array.capacity());
	printf("array.push_back(MyClass(\"次郎\"));\n");
	array.push_back(MyClass("次郎"));
	printf("array.push_back(MyClass(\"三郎\"));\n");
	array.push_back(MyClass("三郎"));
	printf("array.push_back(MyClass(\"四朗\"));\n");
	array.push_back(MyClass("四郎"));
	printf("array.size()=%d\n", array.size());
	printf("array.capacity()=%d\n", array.capacity());
	printf("array.erase(array.begin());\n");
	array.erase(array.begin());
	printf("array.size()=%d\n", array.size());
	printf("array.capacity()=%d\n", array.capacity());
	printf("std::vector<MyClass>(array).swap(array);\n");
	std::vector<MyClass>(array).swap(array);
	printf("array.size()=%d\n", array.size());
	printf("array.capacity()=%d\n", array.capacity());
	printf("std::vector<MyClass>().swap(array);\n");
	std::vector<MyClass>().swap(array);
	printf("array.size()=%d\n", array.size());
	printf("array.capacity()=%d\n", array.capacity());
}

//================================================================================
//自作イテレータテスト

#include <iterator>
#include <algorithm>
#include <stdio.h>

//テストクラス
class MyClass
{
public:
	//アクセッサ
	const char* getName() const { return m_name; }//名前
public:
	//コンストラクタ
	MyClass(const char* name) :
		m_name(name)
	{}
private:
	//フィールド
	const char* m_name;//名前
};

//自作コンテナ用配置new
class MyContainer;
void* operator new(size_t size, MyContainer& con, void* buff){ return buff; }
void operator delete(void* p, MyContainer& con, void* buff){}

//自作コンテナ
class MyContainer
{
public:
	//自作イテレータ
	class Iterator : public std::iterator<std::forward_iterator_tag, MyClass>
	{
	public:
		//コンテナ要素アクセスオペレータ
		MyClass& operator*() { return *m_obj; }
		MyClass* operator->() { return m_obj; }
		const MyClass& operator*() const { return *m_obj; }
		const MyClass* operator->() const { return m_obj; }
		//イテレータのインクリメント
		Iterator& operator++() { m_obj = m_cont[++m_index]; return *this; }
		Iterator operator++(int) { Iterator prev = *this; m_obj = m_cont[++m_index]; return prev; }
		//イテレータの比較
		bool operator==(const Iterator& ite) const { return m_obj == ite.m_obj; }
		bool operator!=(const Iterator& ite) const { return m_obj != ite.m_obj; }
		//コンストラクタ
		Iterator(MyContainer& coll, int index) :
			m_cont(coll),
			m_index(index),
			m_obj(nullptr)
		{
			m_obj = m_cont[m_index];
		}
	private:
		//フィールド
		MyContainer& m_cont;//コンテナ
		int m_index;        //参照要素インデックス
		MyClass* m_obj;     //コンテナ要素の参照
	};
public:
	//イテレータ―取得
	Iterator begin(){ return Iterator(*this, 0); }  //先頭
	Iterator end(){ return Iterator(*this, m_num); }//末尾
	//要素情報取得
	bool empty() const { return m_num == 0; }//要素が空？
	int size() const { return m_num; }       //要素数
	//要素取得
	MyClass* operator[](const int index)
	{
		if (index < 0 || index >= m_num)
			return nullptr;
		return reinterpret_cast<MyClass*>(m_buff[index]);
	}
	//要素追加
	MyClass* add(const char* name)
	{
		if (m_num >= ELEM_MAX)
			return nullptr;
		return new(*this, m_buff[m_num++])MyClass(name);//既存のバッファにオブジェクト構築（解放不要）
	}
public:
	//コンストラクタ
	MyContainer() :
		m_num(0)
	{}
	//デストラクタ
	~MyContainer()
	{}
private:
	//フィールド
	static const int ELEM_MAX = 8;         //最大要素数
	char m_buff[ELEM_MAX][sizeof(MyClass)];//要素用のバッファ
	int m_num;                             //要素数
};

//自作イテレータテスト
void testMyIterator()
{
	printf("\n- testMyIterator() -\n\n");

	//コンテナ作成
	MyContainer cont;
	cont.add("太郎");
	cont.add("次郎");
	cont.add("三郎");
	
	//for_each用関数オブジェクト（ファンクタ）
	struct MyFunctor{
		void operator()(MyClass& obj){ printf("name=\"%s\"\n", obj.getName()); }
	};
	
	//全コンテナ要素処理
	for_each(cont.begin(), cont.end(), MyFunctor());
}

//================================================================================
//テストメイン関数
void testMain()
{
	//Observerテスト
	testObserver();
	
	//Adapterテスト
	testAdapter();

	//Proxyテスト(1)
	testProxy1();

	//Proxyテスト(2)
	testProxy2();

	//std::vectorテスト
	testSTLvector();

	//自作イテレータテスト
	testMyIterator();
}

//================================================================================
int main(const int argc, const char* argv[])
{
	testMain();

	return EXIT_SUCCESS;
}

// End of file
