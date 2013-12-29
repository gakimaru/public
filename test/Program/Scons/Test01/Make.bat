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

rem --- TEMP 調整 ---
rem ★環境変数 TEMP と TMP に日本語が入っているとSconsが動作しないので注意。
rem   ユーザー名に日本語が含まれているとそのような状態になる
rem   対策として、環境変数の内容を強引に書き換えておく
SET TEMP=%~dp0_temp
SET TMP=%~dp0_temp
MKDIR %TEMP%

rem --- 開始 ---
ECHO.
ECHO ********** テスト開始 **********

rem --- Scons を実行 ---
CALL :RUN_CMD CALL scons.bat

rem 【実行時オプション】
rem   -c オプションを付けると、ターゲットファイルを削除してくれる（make clean と同じ動作）
rem   --debug=explain オプションを付けると、ビルド実行時の理由が表示される。
rem   --tree=all オプションを付けると、ターゲットの依存関係が表示される。

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
