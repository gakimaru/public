#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <Process.h>

//スレッドローカルストレージ(TLS)
#define   _TLS __declspec(thread)//Visual C++固有版TLS指定
//#define _TLS thread_local      //C++11仕様版TLS指定：Visual C++ 2013 では未対応

//ファイバースレッド管理情報
static const int FIBER_MAX = 3;      //ファイバースレッドの最大数
_TLS LPVOID s_pFiler[FIBER_MAX] = {};//ファイバースレッドのインスタンスのポインター
_TLS int s_fiberNum = 0;             //稼働中のファイバースレッド数
_TLS int s_fiberNow = 0;             //現在のファイバースレッド

//ファイバースレッドが存在するか？
//※管理用のスレッドは数に含めない
bool isExistFiberThread()
{
	return s_fiberNum > 1;
}

//ファイバースレッド切り替え
void switchNextFiber()
{
	if (s_fiberNum == 0)
	{
		fprintf(stdout, "Fiber thread is nothing.\n");
		return;
	}
	s_fiberNow = (s_fiberNow + 1) % s_fiberNum;
	fprintf(stdout, "Fiber thread No.%d is switched.\n", s_fiberNow);
	SwitchToFiber(s_pFiler[s_fiberNow]);
}

//ファイバースレッドを追加
template<typename T>
bool addFiber(LPFIBER_START_ROUTINE func, const size_t stack_size, T param_p)
{
	if (s_fiberNum >= FIBER_MAX)
	{
		fprintf(stderr, "Fiber thread was not more added.\n");
		return false;
	}
	fprintf(stdout, "Fiber thread No.%d was added.\n", s_fiberNum);
	s_pFiler[s_fiberNum++] = CreateFiber(stack_size, func, (LPVOID)param_p);
	return true;
}

//現在のファイバースレッドを削除
void removeCurrentFiber()
{
	for (int i = s_fiberNow; i < s_fiberNum - 1; ++i)
	{
		s_pFiler[i] = s_pFiler[i + 1];
	}
	--s_fiberNum;
	fprintf(stdout, "Fiber thread No.%d was removed.\n", s_fiberNow);
	if (s_fiberNum == 0)
	{
		s_fiberNow = 0;
	}
	else
	{
		s_fiberNow = (s_fiberNum + s_fiberNow - 1) % s_fiberNum;
		switchNextFiber();//自身を削除したらすぐに次のファイバースレッドを実行する
	}
}

//ファイバースレッド関数
void WINAPI fiberFunc(LPVOID param_p)
{
	//パラメータ受け取り
	const char* fiber_name = reinterpret_cast<const char*>(param_p);

	//テスト処理
	for (int i = 0; i < 3; ++i)
	{
		printf("fiberFunc(): [%s](%d)\n", fiber_name, i);
		
		switchNextFiber();//次のスレッドに制御を移す
	}

	//最後に自身を削除する（同時に次のスレッドに制御を移す）
	removeCurrentFiber();
	
	//※関数を return すると、その時点でスレッド（fiberMain）が
	//　終了するので注意！
	//  （ファイバースレッドの切り替えは、関数呼び出しと違って
	//  単純なプログラムカウンターの切り替えなので、return すると、
	//  fiberMain() の return とみなされてしまう）
}

//ファイバースレッド管理用スレッド　※必須
unsigned int WINAPI fiberMain(void* param_p)
{
	//スレッドをファイバースレッドとして登録
	//※他のファイバースレッドと処理を切り替える必要があるため
	//　管理スレッドもファイバースレッドの一つにする。
	//※main() から見たら、普通のスレッドであることに変わりはない。
	s_pFiler[s_fiberNum++] = ConvertThreadToFiber(NULL);
	
	//ファイバースレッドを追加
	addFiber(fiberFunc, 1024, "太郎");
	addFiber(fiberFunc, 1024, "次郎");
	
	//ファイバースレッドを切り替えながら、全て完了するのを待つ
	fprintf(stdout, "- loop: start -\n");
	while (isExistFiberThread())
	{
		switchNextFiber();//ファイバースレッドの切り替え
		fprintf(stdout, "- loop -\n");
		Sleep(0);//他のスレッドに切り替え
	}
	fprintf(stdout, "- loop: end -\n");

	//ファイバースレッドを削除
	removeCurrentFiber();
	
	return 0;
}

//メイン
int main(const int argc, const char* argv[])
{
	fprintf(stdout, "- Fiber Thread Test: BEGIN -\n");

	//ファイバースレッド管理用のスレッドを生成
	unsigned int tid = 0;
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, fiberMain, nullptr, 0, &tid);

	//ファイバースレッド管理スレッド終了待ち
	WaitForSingleObject(hThread, INFINITE);
	
	fprintf(stdout, "- Fiber Thread Test: END -\n");

	return EXIT_SUCCESS;
}

// End of file
