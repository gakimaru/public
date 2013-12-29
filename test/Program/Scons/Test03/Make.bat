@ECHO OFF

rem --- バッチファイルの存在するパス（ドライブ＆ディレクトリ）にカレントディレクトリを変更 ---
CD /D %~dp0

rem --- 現在のコードページを確認 ---
rem CHCP
rem --- コードページ指定：英語 ---
rem CHCP 437 >NUL
rem --- コードページ指定：UTF-8 ---
rem CHCP 65001 >NUL
rem --- コードページ指定：UTF-16(Unicode) ---
rem CHCP 1200 >NUL
rem --- コードページ指定：日本語（シフトJIS） ---
CHCP 932 >NUL

rem --- Python のパスを通す ---
SET PYTHON_DIR=D:\Python\27\x64
SET PATH=%PYTHON_DIR%\;%PYTHON_DIR%\Scripts\;%PATH%

rem --- Microsoft Visual C++ 2008 Express Edition のパスを通す ---
SET VS90DIR=D:\Program Files (x86)\Microsoft Visual Studio 9.0\
IF "%VS90COMNTOOLS%" == "%VS90COMNTOOLS%" SET VS90COMNTOOLS=%VS90DIR%Common7\Tools\
CALL "%VS90DIR%VC\vcvarsall.bat" >NUL

rem --- TEMP 調整 ---
rem ★環境変数 TEMP と TMP に日本語が入っているとSconsが動作しないので注意。
rem   ユーザー名に日本語が含まれているとそのような状態になる
rem   対策として、環境変数の内容を強引に書き換えておく
SET TEMP=%~dp0_temp
SET TMP=%~dp0_temp
IF NOT EXIST %TEMP% MKDIR %TEMP%

rem --- 開始 ---
ECHO.
ECHO ********** テスト開始 **********

rem --- Scons を実行 ---
CALL :RUN_CMD CALL scons.bat --tree=all

rem 【実行時オプション】
rem   -c オプションを付けると、ターゲットファイルを削除してくれる（make clean と同じ動作）
rem   --debug=explain オプションを付けると、ビルド実行時の理由が表示される。
rem   --tree=all オプションを付けると、ターゲットの依存関係が表示される。

rem --- C++プリプロセッサテスト ---
rem ※商用利用可能な無償コンパイラ Microsoft Visual C++ 2008 Express を使用する
rem   http://homepage2.nifty.com/nonnon/Chinamini/20110001/20110307.html

rem SET SCRIPT_BASE=%~dp0
rem SET CL_OPT=/nologo /TP /E /I "%SCRIPT_BASE%include00" /I "%SCRIPT_BASE%include01" /I "%SCRIPT_BASE%include02" /FI "script_header_common01.h" /FI "script_header_common02.h" /D=XXX /D=YYY
rem CL.exe %CL_OPT% %SCRIPT_BASE%src\test00.script > %SCRIPT_BASE%preprocess\test00.script.i
rem CL.exe %CL_OPT% %SCRIPT_BASE%src\test01\test01.script > %SCRIPT_BASE%preprocess\test01.script.i
rem CL.exe %CL_OPT% %SCRIPT_BASE%src\test02\test02a.script > %SCRIPT_BASE%preprocess\test02a.script.i
rem CL.exe %CL_OPT% %SCRIPT_BASE%src\test02\test02b.script > %SCRIPT_BASE%preprocess\test02b.script.i

rem 【CL.exe プリプロセッサ入出力に関係する主なオプション】 「★」は使用オプション
rem   /P  ... ファイルを前処理する (.iファイルに出力)
rem ★/E  ... stdout に前処理する
rem   /EP ... stdout に前処理する、#line なし
rem   /C  ... コメントを削除しない
rem   /Fx ... 挿入コードをファイルにマージする
rem ★/I<dir>   ... インクルード検索パスに追加する
rem ★/FI<File> ... 必ず使用されるインクルード ファイル名を指定する
rem ★/D<name>{=|#}<text> ... マクロを定義する
rem ★/nologo ... 著作権メッセージを表示しない
rem   /showIncludes ... インクルード ファイル名を表示する
rem   /Tc<source file> ... ファイルを .c としてコンパイルする
rem   /Tp<source file> ... ファイルを .cpp としてコンパイルする
rem   /TC ... すべてのファイルを .c としてコンパイルする
rem ★/TP ... すべてのファイルを .cpp としてコンパイルする

rem --- 終了 ---
ECHO.
CALL :PAUSE_MSG ********** テスト終了 **********
EXIT /B %RESULT%



rem ========== 標準サブルーチン ==========

rem --- 標準サブルーチン：コマンドラインを表示して実行 ---
:RUN_CMD
ECHO ^> %*
%*
EXIT /B %ERRORLEVEL%

rem --- 標準サブルーチン：メッセージ付きポーズ ---
:PAUSE_MSG
SET MSG=%*
IF "%MSG%" == "" SET MSG=続行するには何かキーを押してください．．．
ECHO.%MSG%
PAUSE >NUL
EXIT /B
