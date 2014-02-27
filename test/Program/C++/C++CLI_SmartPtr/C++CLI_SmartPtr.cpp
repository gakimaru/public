#include "stdafx.h"

#if 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

//----------------------------------------
//テスト用クラス
//※マネージクラスのため「ref」を付ける
//※マネージクラスは、「IDisposable」インターフェース実装を暗黙的に行い、デストラクタに対応付ける
public ref class CTest// : public IDisposable//IDisposableを明示的に宣言する必要なし
{
public:
	//メソッド
	//名前表示
	void showName()//const//マネージクラスのメソッドにこの修飾子は使えない
	{
		System::Console::WriteLine(L"名前=\"{0}\"", m_name);//.Net Framework式の文字列標準出力
	}
public:
	//コンストラクタ
	CTest(System::String^ name):
		m_name(name)
	{
		msclr::interop::marshal_context context;//マネージ型の文字列をネイティブ型に変換（マーシャリング）
		printf("コンストラクタ(%s)\n", context.marshal_as<const char*>(m_name));//C言語標準ライブラリ式の文字列標準出力
	}
	//デストラクタ
	//※IDisposable::Dispose()の実装として解釈される
	//※C#ではこの関数がファイナライザで、デストラクタは
	//　明示的な IDisposable::Dispose() 呼び出しの必要があるので注意
	~CTest()
	{
		msclr::interop::marshal_context context;//マネージ型の文字列をネイティブ型に変換（マーシャリング）
		std::cout << "デストラクタ(" << context.marshal_as<std::string>(m_name) << ")" << std::endl;//C++言語の標準ライブラリ式の文字列標準出力
	}
protected:
	//ファイナライザ
	//※ガベージコレクション時にオブジェクトを削除する際に実行
	!CTest()
	{
		System::Console::WriteLine(L"ファイナライザ({0})", m_name);//.Net Framework式の文字列標準出力
	}
private:
	//フィールド
	System::String^ m_name;//名前
};

//----------------------------------------
//メイン関数
int main(array<System::String^>^ args)//.Net Frameworkスタイル
//int main(const int argc, const char* argv[])//C/C++言語スタイル（これもOK）
{
	{
		CTest^ obj1 = gcnew CTest(L"テスト1");//gcnewでインスタンス生成
		obj1->showName();//アロー演算子でメンバーアクセス
		CTest^% obj1ex = obj1;//ハンドルの参照
		delete obj1;//deleteはそのまま
	}
	{
		CTest obj2(L"テスト2");//直接ローカル変数としてインスタンス化も問題なし
		obj2.showName();
	}
	{
		CTest^ obj3 = gcnew CTest(L"テスト3");//gcnewでインスタンス生成
		obj3->showName();
		//delete obj3;//deleteしない
	}
	//明示的なガベージコレクション呼び出し
	//※即時ゴミ回収するが、ゴミと認識されるまで時間がかかることがある
	System::Console::WriteLine(L"ToralMemory={0}", System::GC::GetTotalMemory(false));//確保済みメモリ表示
	System::GC::Collect();
	System::Console::WriteLine(L"ToralMemory={0}", System::GC::GetTotalMemory(false));//確保済みメモリ表示
	//終了
	System::Console::WriteLine(L"終了");
	return EXIT_SUCCESS;
}

#else

#include <stdio.h>
#include <stdlib.h>

//----------------------------------------
//簡易版スマートポインターのテンプレートクラス
//Boost C++ の smart_ptr のように、削除処理を指定するような機能はなし
template<class T>
class CSmartPtr
{
private:
	//参照情報型
	struct T_REF_INFO
	{
		//フィールド
		T* m_realObj;  //本当のオブジェクト
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
	//参照カウンタカウントアップ
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
class CTest
{
public:
	//メソッド
	//名前表示
	void showName() const
	{
		printf("名前=\"%s\"\n", m_name);
	}
public:
	//コンストラクタ
	CTest(const char* name) :
		m_name(name)
	{
		printf("コンストラクタ(%s)\n", m_name);
	}
	//デストラクタ
	~CTest()
	{
		printf("デストラクタ(%s)\n", m_name);
	}
private:
	//フィールド
	const char* m_name;//名前
};

//----------------------------------------
//テストメイン関数
int main(const int argc, const char* argv[])
{
	{
		CSmartPtr<CTest> obj1 = new CTest("テスト1");//インスタンスを生成してスマートポインタで扱う
		obj1->showName();//アロー演算子でメンバーアクセス
		obj1 = nullptr;//deleteは使用せず、nullptrの代入で破棄
	}
	{
		CTest obj2("テスト2");//直接ローカル変数としてインスタンス化も問題なし
		obj2.showName();
	}
	{
		CSmartPtr<CTest> obj3 = new CTest("テスト3");//インスタンスを生成してスマートポインタで扱う
		obj3->showName();
		//obj1 = nullptr;//明示的に破棄しない
	}
	
	//終了
	return EXIT_SUCCESS;
}

#endif

// End of file
