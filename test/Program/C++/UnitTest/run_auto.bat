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

rem --- ガイド付きプロファイルのインストルメントを実行する為に VC++ のパスを通す ---
CALL "D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"

rem --- 実行対象ビルド ---
rem SET BUILD_TARGET=Debug
SET BUILD_TARGET=Release

rem --- 開始 ---
ECHO.
ECHO ********** テスト開始 **********

rem --- テスト処理(1) ---
rem ECHO.
rem CALL :RUN_CMD %BUILD_TARGET%\UnitTest.exe
rem SET RESULT=%ERRORLEVEL%
rem ECHO 実行結果=%RESULT%

rem --- テスト処理(2) ---
rem ECHO.
rem CALL :RUN_CMD %BUILD_TARGET%_UT_ENABLED\UnitTest.exe
rem SET RESULT=%ERRORLEVEL%
rem ECHO 実行結果=%RESULT%

rem --- テスト処理(3) ---
ECHO.
CALL :RUN_CMD %BUILD_TARGET%_UT_ENABLED_AUTO\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO 実行結果=%RESULT%

rem --- テスト処理(4) ---
rem ECHO.
rem CALL :RUN_CMD %BUILD_TARGET%_UT_ENABLED_AUTO_TARGET_MODULE\UnitTest.exe
rem SET RESULT=%ERRORLEVEL%
rem ECHO 実行結果=%RESULT%

rem --- テスト処理(5) ---
rem ECHO.
rem CALL :RUN_CMD %BUILD_TARGET%_UT_ENABLED_AUTO_TARGET_GROUP\UnitTest.exe
rem SET RESULT=%ERRORLEVEL%
rem ECHO 実行結果=%RESULT%

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
