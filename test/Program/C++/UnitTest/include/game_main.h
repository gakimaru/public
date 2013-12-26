#pragma once
#ifndef __GAME_MAIN_H__
#define __GAME_MAIN_H__

#include "unit_test.h"

//ゲームメインクラス
class CGameMain
{
public:
	//コンストラクタ
	explicit CGameMain(const int argc, const char* argv[]);
	//■explicit宣言の解説
	//  「explicit」宣言は、「CClass obj = 1;」のような暗黙的なキャストを禁止する。
	//  例えば、誤って書いた「obj = func();//int値を返す」といった処理がコンパイル時にエラーになるようにできる。
	//  通常は、パラメータの型が一致するコンストラクタが自動的に呼び出されるので、
	//  この挙動を意図する場合以外は explicit を付けておいた方が安全。
	//  本来はパラメータが一つのコンストラクタの為の宣言だが、それ以外のコンストラクタに適用しても問題はないので、
	//  習慣としてexplicit宣言を付ける事にしておいても良い。

private:
	explicit CGameMain() :m_argc(0), m_argv(nullptr){}//デフォルトコンストラクタ無効化（private化）
	//■デフォルトコンストラクタの解説
	//  「CClass obj;」のような、パラメータを指定しないコンストラクタの挙動を定義する。
	//  コンストラクタが一切定義されていない場合か、デフォルトコンストラクタが定義されている場合に限り、
	//  パラメータを与えずにオブジェクトを生成できる。
	
	explicit CGameMain(CGameMain&) : m_argc(0), m_argv(nullptr){}//コピーコンストラクタ無効化（private化）
	//■コピーコンストラクタの解説
	//  「CClass obj1(obj2);」や「CClass obj1 = obj2;」のような、自身と同じオブジェクトが渡された時の挙動を定義する。
	//  コピーコンストラクタの定義が無い場合、コンパイラが暗黙的にコピーコンストラクタを作成し、単純なメモリコピーを行う。
	//  なお、「CClass obj1 = obj2;」のような代入操作を禁止して、「CClass obj1(obj2);」のような明示的なパラメータ指定だけ許可したい場合は、
	//  コピーコンストラクタを public にして explicit 宣言を付ける。
	//  また、変数宣言時以外の代入操作が必要な場合は、「CClass& operator=(CClass& r)」のように、
	//  代入演算子のオーバーロード関数を定義する。

public:
	//デストラクタ
	~CGameMain();
	//■デストラクタとvirtual宣言の解説
	//  デストラクタの記述は「virtual ~CClass();」のように、「virtual」宣言を付ける事を習慣にしている事が多いが、
	//  これは推奨しない。
	//  クラス内に一つでも「virtual」宣言があると、「vtable」という「virtual」関数のポインターのリストが作られ、
	//  クラスは暗黙的にその参照を保持する構造に拡張される。つまり、少しだけサイズが大きくなる。
	//  また、「CClass obj;」や「CClass* obj = new CClass();」のようにきちんとオブジェクトを生成しないと、
	//  「vtable」の参照（ポインター）が正しく格納されず、「virtual」関数呼び出し時に正常に処理されなくなる。
	//  以上の事から、意図したケース以外では極力「virtual」の使用を控える事を推奨する。
	//  「意図したケース」とは、親クラスのポインターとしてオブジェクトを受け渡して処理を呼び出す必要がある場合。
	//  親クラスのポインターに対して delete を実行した際に、子クラスのデストラクタを呼び出す必要がある場合は
	//  「virtual」を付けなければならない。
	//  このようなクラスの多態性の仕組みを随所で使用しているようなプロジェクトでは、デストラクタの呼び出しを
	//  確実にする為にも、「全てのクラスのデストラクタにはvirtual宣言を付ける事」といった単純なルールを
	//  敷いた方がコーディングミスを軽減できるが、ゲーム制作の場合は可能な限り「virtual」の使用を控え、
	//  意図して使う所にだけ気を遣うようにする事を推奨する。
	//  「virutal」を濫用してパフォーマンスの低下を招いたり、誤ったオーバーライドに気が付きにくいといった問題の方を
	//  重視する。特に、親クラスの「virtual」関数の引数を変更したりすると、コンパイルエラーも出ずに
	//  オーバーライドが外れて、挙動が変わってしまう事がある。
	//  クラスの設計は、本当に継承や多態性が必要かどうかを十分に吟味し、必要なら「template」を駆使した
	//  多態性の実装方法（少し面倒）を取り入れるなど工夫して、できる限り virtual の使用を控えるようにする。

public:
	//アクセッサ
	int getArgc() const { return this->m_argc; }
//	const char** getArgv() const { return this->m_argv; }
	const char* getArgv(const int index) const { return index >= 0 && index < this->m_argc ? this->m_argv[index] : nullptr; }
	int getInitializeResult() const { return this->m_initializeResult; }
	int getFinalizeResult() const { return this->m_finalizeResult; }
	int getMainResult() const { return this->m_mainResult; }
	operator int() const { return this->m_mainResult; }//キャスト演算子オーバーロード

public:
	//初期化処理
	int initialize();
	
	//終了処理
	int finalize();

	//メイン処理
	int main();

#ifdef UNIT_TEST_ENABLED
	//ユニットテストメイン処理
	int unitTestMain();
#endif//UNIT_TEST_ENABLED

private:
	//実行時パラメータ
	const int m_argc;
	const char** m_argv;
	
	//処理結果
	int m_initializeResult;
	int m_finalizeResult;
	int m_mainResult;
};

#endif//__GAME_MAIN_H__

// End of file
