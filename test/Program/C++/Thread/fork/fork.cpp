#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#include <unistd.h>
#include <sys/wait.h>

//fork テスト
int main(const int argc, const char* argv[])
{
	//プログラム実行開始
	printf("- Start Fork Test -\n");
	fflush(stdout);
	
	//テスト用変数
	const char* test_text = "TEST";
	int test_value = 1000;
	int test_loop_max = 1;
	
	//プロセス名を作成
	// P + 子プロセスのレベル + ( 自プロセスID , 親プロセスID )
	char process_name[32];
	sprintf(process_name, "P0(%5d,%5d)", getpid(), getppid());
	int level = 0;
	
	//大元のプロセス判定用フラグ（初期値は true）
	bool is_root_process = true;
	
	//子プロセス生成ループ
	const int CHILD_THREAD_NUM = 3;
	pid_t pid[CHILD_THREAD_NUM];//生成した子プロセスのプロセスID
	for(int i = 0; i < CHILD_THREAD_NUM; ++i)
	{
		//子プロセス生成
		pid_t pid_tmp = fork();
		//※fork()が実行された瞬間に子プロセスが生成される。
		//※子プロセスは、親プロセスの静的変数やスタック（自動変数）、実行位置（プログラムカウンタ）、
		//　および、オープン中のファイルディスクリプタをコピーして、新しいプロセスを作る。
		//※実行位置もコピーされるため、子プロセスはこの位置からスタートする。
		//　すべての変数の値も引き継がられるが、メモリを共有するわけではない。
		//　あくまでもその時点の内容がコピーされるだけ。
		
		//生成結果確認
		switch(pid_tmp)
		{
		//fork 成功：自プロセスが「生成された子プロセス」の場合
		case 0:
			//大元のプロセス判定用フラグをOFF
			is_root_process = false;
			
			//プロセス名を作成
			++ level;
			sprintf(process_name, "C%d(%5d,%5d)", level, getpid(), getppid());
			// C + 子プロセスのレベル + ( 自プロセスID , 親プロセスID )
			
			//子プロセス開始メッセージ
			printf("START: %s\n", process_name);
			fflush(stdout);
			
			//テスト用変数を更新
			++test_value;
			++test_loop_max;
			
			//親プロセスが生成した子プロセスのIDのコピーされてしまっているのでクリアする
			for(int ii = 0; ii <= i; ++ ii)
				pid[ii] = -1;
			
			//1秒スリープ
			sleep(1);
			
			break;
		
		//fork 失敗
		case -1:
			//エラーメッセージ
			if(is_root_process)
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", process_name, i, errno);
			else
				fprintf(stderr, "%s -> [%d] FAILED (errno=%d)\n", process_name, i, errno);
			fflush(stderr);
			
			//1秒スリープ
			sleep(1);
			
			break;
		
		//fork 成功：子プロセスの生成に成功し、子プロセスのプロセスIDを取得
		default:
			//子プロセスのプロセスIDを記録（最後の終了待ち用）
			pid[i] = pid_tmp;
			
			//子プロセス生成メッセージ
			if(is_root_process)
				printf("%s -> [%d] CREATED:C%d(%5d,%5d)\n", process_name, i, level + 1, pid_tmp, getpid());
			else
				printf("%s -> [%d] CREATED:C%d(%5d,%5d)\n", process_name, i, level + 1, pid_tmp, getpid());
			fflush(stdout);
			
			//2秒スリープ
			sleep(2);
			
			break;
		}
	}
	
	//ダミー処理
	for(int i = 0; i < test_loop_max; ++i)
	{
		//ダミーメッセージ表示
		printf("[%s] ... Process(%d/%d): text=\"%s\",value=%d\n", process_name, i + 1, test_loop_max, test_text, test_value);
		fflush(stdout);
		test_value += 10;
		
		//1秒スリープ
		sleep(1);
	}
	
	//子プロセスの終了待ち
	for(int i = 0; i < CHILD_THREAD_NUM; ++i)
	{
		pid_t pid_tmp = pid[i];
		if(pid_tmp > 0)
		{
			//ウェイト開始メッセージ
			printf("[%s] ... Wait(%5d) ...\n", process_name, pid_tmp);
			fflush(stdout);
			
			//ウェイト
			int status = -1;
			waitpid(pid_tmp, &status, WUNTRACED);
			
			//ウェイト完了メッセージ
			printf("[%s] ... Wait(%5d) End status=%d\n", process_name, pid_tmp, status);
			fflush(stdout);
		}
	}
	
	//自プロセスが子プロセスならこの時点で実行終了
	if(!is_root_process)
	{
		//子プロセス終了メッセージ
		printf("END: %s\n", process_name);
		fflush(stdout);
		
		//プロセス終了
		exit(0);
	}
	
	//プログラム実行終了
	printf("- End Fork Test -\n");
	fflush(stdout);
	return EXIT_SUCCESS;
}

// End of file
