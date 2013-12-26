@ECHO OFF

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

rem --- テスト処理(1) ---
ECHO.
CALL :RUN_CMD Debug\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO 実行結果=%RESULT%

rem --- テスト処理(2) ---
ECHO.
CALL :RUN_CMD Debug_UT_ENABLED\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO 実行結果=%RESULT%

rem --- テスト処理(3) ---
ECHO.
CALL :RUN_CMD Debug_UT_ENABLED_AUTO\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO 実行結果=%RESULT%

rem --- テスト処理(4) ---
ECHO.
CALL :RUN_CMD Debug_UT_ENABLED_AUTO_TARGET_MODULE\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO 実行結果=%RESULT%

rem --- テスト処理(5) ---
ECHO.
CALL :RUN_CMD Debug_UT_ENABLED_AUTO_TARGET_GROUP\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO 実行結果=%RESULT%

rem --- 終了 ---
ECHO.
CALL :PAUSE_MSG 実行終了
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
