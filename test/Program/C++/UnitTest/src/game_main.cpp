#include <stdio.h>
#include <stdlib.h>

#include "game_main.h"
#include "unit_test.h"
#include "unit_test_id.h"

//ゲームメインクラス

//コンストラクタ
CGameMain::CGameMain(const int argc, const char* argv[]):
	m_argc(argc),
	m_argv(argv),
	m_initializeResult(EXIT_SUCCESS),
	m_finalizeResult(EXIT_SUCCESS),
	m_mainResult(EXIT_SUCCESS)
{
	printf("- CGameMain::CGameMain()\n");
}

//デストラクタ
CGameMain::~CGameMain()
{
	printf("- CGameMain::~CGameMain()\n");
}

//初期化処理
int CGameMain::initialize()
{
	printf("- CGameMain::initialize() [BEGIN] ...\n");
	this->m_initializeResult = EXIT_SUCCESS;
	printf("- CGameMain::initialize() [END]\n");
	return this->m_initializeResult;
}

//終了処理
int CGameMain::finalize()
{
	printf("- CGameMain::finalize() [BEGIN] ...\n");
	this->m_finalizeResult = EXIT_SUCCESS;
	printf("- CGameMain::finalize() [END]\n");
	return this->m_finalizeResult;
}

//メイン処理
int CGameMain::main()
{
	printf("- CGameMain::main() [BEGIN] ...\n");

	//自動ユニットテスト
	//※UT_ENABLED と UT_AUTO が定義されている時だけ処理が有効化される
	//　UT_TARGET_MODULE と UT_TARGET_GROUP の定義の影響を受けて、実行されるユニットテストが限定される。
	//　メイン処理の最初に実行されるようにしておく。メモリ管理などの基本的な初期化処理が終わった後が良い。
	//※ユニットテストの結果に一つでもミスがあったら return する。return 値はミス数。
	//　この return 値を main関数の return 値にする。
	//　これにより、jenkins などのツールからユニットテストの結果をハンドリングできる。
	UT_RUN_MAIN();
	
#if 1
	//手動ユニットテスト
	//※UT_ENABLED が定義されている時だけ処理が有効化される
	//　プログラム中の任意の場所から呼び出せる。
	UT_OUTPUT("手動ユニットテスト:ALL\n");
	UT_RUN_ALL();             //UT_AUTO と無関係に全モジュールのテストを実行するマクロ
	UT_OUTPUT("手動ユニットテスト:MODULE(\"CModuleB\")\n");
	UT_RUN_MODULE("CModuleB");//UT_AUTO と無関係に指定のモジュールのテストを実行するマクロ
	UT_OUTPUT("手動ユニットテスト:GROUP(2)\n");
	UT_RUN_GROUP(2);          //UT_AUTO と無関係に指定のグループのテストを実行するマクロ
	UT_OUTPUT("手動ユニットテスト:STANDARD\n");
	UT_RUN_STANDARD();        //UT_AUTO と無関係にモジュールのテストを実行するマクロ
	                          //※UT_TARGET_MODULE と UT_TARGET_GROUP の定義の影響を受けて、実行されるユニットテストが限定される。
#endif

#if 1
	//前回のユニットテストの結果を確認／リセット／結果に基づいて終了
	UT_OUTPUT("手動ユニットテスト結果：passed=%d, missed=%d\n", UT_LAST_PASSED_TOTAL(), UT_LAST_MISSED_TOTAL());//前回のユニットテストの結果を取得
	UT_RESET_LAST_RESULT();   //前回のユニットテストの結果をリセット
	UT_OUTPUT("結果をリセット：passed=%d, missed=%d\n", UT_LAST_PASSED_TOTAL(), UT_LAST_MISSED_TOTAL());
	UT_RETURN_WHEN_MISSED();  //前回のユニットテストの結果に一つでもミスがあったら return する
	UT_EXIT_WHEN_MISSED();    //前回のユニットテストの結果に一つでもミスがあったら exit する
	UT_ABORT_WHEN_MISSED();   //前回のユニットテストの結果に一つでもミスがあったら abort する
	UT_ASSERT_WHEN_MISSED();  //前回のユニットテストの結果に一つでもミスがあったらアサーション違反とする
#endif

#if 1
	//ユニットテストのサポート処理
	UT_OUTPUT("UT_SET_OUTPUT_FUNC()：実行前\n");
	UT_SET_OUTPUT_FUNC(nullptr); //ユニットテストの表示用関数を変更する（ターゲットプラットフォームに合わせた関数にするなど）
	                             //※型:int(*UNIT_TEST_OUTPUT_FUNC_P)(const char* fmt, va_list list)
	                             //　nullptr を指定すると一切何も表示されなくなる。
	UT_OUTPUT("UT_SET_OUTPUT_FUNC()：実行後\n");
	UT_WITH_(printf("UT_WITH_()マクロを使ってプリント\n")); //※UT_WITH_()マクロ内に書いた処理は、UT_ENABLED 有効時のみ実行される。
#endif
	
	//以下、本来のゲームメイン処理
	printf("本来のゲームメイン処理 ...\n");

	this->m_mainResult = EXIT_SUCCESS;
	printf("- CGameMain::main() [END]\n");
	return this->m_mainResult;
}

// End of file
