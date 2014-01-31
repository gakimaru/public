#include <stdio.h>
#include <stdlib.h>

#include <future>
#include <thread>
#include <chrono>

//結果表示スレッド
void threadFunc(const char* name, std::shared_future<int> value)
{
	printf("%s: [BEFORE]\n", name);
	fflush(stdout);

	printf("%s: [AFTER] value=%d\n", name, value.get());//future::get() は、結果が格納されるまで処理がブロックされる
	fflush(stdout);
}

//テスト
int main(const int argc, const char* argv)
{
	//処理開始
	printf("main: [START]\n");
	fflush(stdout);

	//先物変数の用意
	//※後で値を格納する変数
	std::promise<int> p_val;

	//結果待機オブジェクトを用意
	//※先物変数や非同期関数の結果を待機するオブジェクト。
	//※結果を受け取る側がスレッドの場合、shared_futureクラスを使用。
	std::shared_future<int> f_val = p_val.get_future().share();

	//スレッド生成
	static const char* names[] = { "太郎", "次郎", "三郎" };
	for(auto name : names)
	{
		//スレッド生成
		std::thread th = std::thread(threadFunc, name, f_val);
			
		//スレッドの完了を待たないので、切り離しておく
		th.detach();
	}

	//1秒スリープ
	printf("main: [sleep ...]\n");
	fflush(stdout);
	std::this_thread::sleep_for(std::chrono::seconds(1));

	//値を格納
	//※この時、スレッド側の future::get() が反応する
	printf("main: [set_value()]\n");
	fflush(stdout);
	p_val.set_value(123);

	//1ミリ秒スリープ
	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	//処理終了
	printf("main: [END]\n");
	fflush(stdout);
	
	return EXIT_SUCCESS;
}

// End of file
