@ECHO OFF

rem --- バッチファイルの存在するパス（ドライブ＆ディレクトリ）にカレントディレクトリを変更 ---
CD /D %~dp0

rem --- Python のパスを通す ---
SET PYTHON_DIR=D:\Python\27\x64
SET PATH=%PYTHON_DIR%\;%PYTHON_DIR%\Scripts\;%PATH%

rem --- MinGW(GCC)のパスを通す ---
SET MINGW_BIN_DIR=D:\MinGW\bin
SET PATH=%MINGW_BIN_DIR%;%PATH%

rem --- TEMP 調整 ---
rem ★環境変数 TEMP と TMP に日本語が入っているとSconsが動作しないので注意。
rem   ユーザー名に日本語が含まれているとそのような状態になる
rem   対策として、環境変数の内容を強引に書き換えておく
SET TEMP=%~dp0_temp
SET TMP=%~dp0_temp
IF NOT EXIST %TEMP% MKDIR %TEMP%

rem --- Scons を実行 ---
CALL :RUN_CMD CALL scons.bat --tree=all --debug=explain
SET RESULT=%ERRORLEVEL%

rem --- 終了 ---
ECHO.
PAUSE
EXIT /B %RESULT%

rem --- 標準サブルーチン：コマンドラインを表示して実行 ---
:RUN_CMD
ECHO ^> %*
%*
EXIT /B %ERRORLEVEL%
