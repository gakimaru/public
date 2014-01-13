@ECHO OFF

rem --- バッチファイルの存在するパス（ドライブ＆ディレクトリ）にカレントディレクトリを変更 ---
CD /D %~dp0

rem --- MinGW(GCC)のパスを通す ---
SET MINGW_BIN_DIR=D:\MinGW\bin
SET PATH=%MINGW_BIN_DIR%;%PATH%

rem --- プリプロセッサオプション ---
SET PP_FLAGS=-x c++ -E -P
SET PP_INC_DIRS=-I . -I "lib/common"
rem SET PP_INCLUDES=-include "common.hjson"
SET PP_INCLUDES=

rem --- データ変換オプション ---
SET GD_FLAGS=--le --p32 --sp8 --dbgcrc -dbgexpr --utf8 --dbgutf8
SET GD_MKSRC_FLAGS=--makesrc --srcutf8

SET GD_TYPE_FILE01=settings/common_type
SET GD_TYPE_FILE02=settings/ext_type

SET GD_FUNC_FILE01=settings/ext_func01
SET GD_FUNC_FILE02=settings/ext_func02

SET GD_FORMAT_FILE=settings/chara_fomat
SET GD_FORMAT_INC_FILE=include/chara_format.h
SET GD_FORMAT_SRC_FILE=src/chara_format.cpp

rem --- 開始 ---
ECHO ***** データ変換開始 *****
ECHO.
SET RESULT_TOTAL=0

rem --- 型定義リストのプリプロセッサ実行 ---
CALL :PREPROCESSOR %GD_TYPE_FILE01%
CALL :PREPROCESSOR %GD_TYPE_FILE02%

rem --- 拡張関数定義リストのプリプロセッサ実行 ---
CALL :PREPROCESSOR %GD_FUNC_FILE01%
CALL :PREPROCESSOR %GD_FUNC_FILE02%

rem --- フォーマット定義JSONのプリプロセッサ実行 ---
CALL :PREPROCESSOR %GD_FORMAT_FILE%

rem --- ソースファイル作成 ---
CALL :GDSRCCONV %GD_FORMAT_FILE% 

rem --- データ変換実行 ---
CALL :GDCONV %GD_FORMAT_FILE% data/data01 bin/data01
CALL :GDCONV %GD_FORMAT_FILE% data/data02 bin/data02
CALL :GDCONV %GD_FORMAT_FILE% data/data03 bin/data03

rem --- 終了 ---
ECHO.
ECHO エラー数: %RESULT_TOTAL%
CALL :PAUSE_MSG ***** データ変換終了 *****
EXIT /B %RESULT_TOTAL%

rem ========== プリプロセッサ実行 ==========
:PREPROCESSOR
SET JSON_FILE=%1.json
SET JSON_PP_FILE=%2
IF "%JSON_PP_FILE%" == "" SET JSON_PP_FILE=%1
SET JSON_PP_FILE=%JSON_PP_FILE%.i.json
ECHO.
ECHO ----------------------------------------
ECHO プリプロセッサ実行: "%JSON_FILE%" to "%JSON_PP_FILE%"
CALL :RESET_ERRORLEVEL
CALL :RUN_CMD g++.exe %PP_FLAGS% %PP_INC_DIRS% %PP_INCLUDES% -c "%JSON_FILE%" -o "%JSON_PP_FILE%"
SET RESULT=%ERRORLEVEL%
IF NOT "%RESULT%" == "0" ECHO エラー！
IF NOT "%RESULT%" == "0" SET /A RESULT_TOTAL=RESULT_TOTAL+1
EXIT /B %RESULT%

rem ========== ソースファイル生成実行 ==========
:GDSRCCONV
SET FORMAT_FILE=%1.i.json
ECHO.
ECHO ----------------------------------------
ECHO ソースファイル生成: "%FORMAT_FILE%"
CALL :RESET_ERRORLEVEL
CALL :RUN_CMD gdconv.exe %GD_MKSRC_FLAGS% -t "%GD_TYPE_FILE01%.i.json" -t "%GD_TYPE_FILE02%.i.json" -f "%GD_FUNC_FILE01%.i.json" -f "%GD_FUNC_FILE02%.i.json" -d "%FORMAT_FILE%"
SET RESULT=%ERRORLEVEL%
IF NOT "%RESULT%" == "0" ECHO エラー！
IF NOT "%RESULT%" == "0" SET /A RESULT_TOTAL=RESULT_TOTAL+1
EXIT /B %RESULT%

rem ========== データ変換実行 ==========
:GDCONV
SET FORMAT_FILE=%1.i.json
SET JSON_FILE=%2.json
SET JSON_PP_FILE=%2.i.json
SET JSON_MID_FILE=%2.m.json
SET JSON_CHECK_FILE=%2.c.json
SET BIN_FILE=%3.bin
ECHO.
ECHO ----------------------------------------
ECHO データ変換: "%JSON_FILE%" to "%BIN_FILE%"
CALL :RESET_ERRORLEVEL
CALL :RUN_CMD g++.exe %PP_FLAGS% %PP_INC_DIRS% %PP_INCLUDES% -c "%JSON_FILE%" -o "%JSON_PP_FILE%"
SET RESULT=%ERRORLEVEL%
IF NOT "%RESULT%" == "0" ECHO エラー！
IF NOT "%RESULT%" == "0" SET /A RESULT_TOTAL=RESULT_TOTAL+1
CALL :RUN_CMD gdconv.exe %GD_FLAGS% -t "%GD_TYPE_FILE01%.i.json" -t "%GD_TYPE_FILE02%.i.json" -f "%GD_FUNC_FILE01%.i.json" -f "%GD_FUNC_FILE02%.i.json" -d "%FORMAT_FILE%" -i "%JSON_PP_FILE%" -o "%BIN_FILE%" -c "%JSON_CHECK_FILE%" -m "%JSON_MID_FILE%"
SET RESULT=%ERRORLEVEL%
IF NOT "%RESULT%" == "0" ECHO エラー！
IF NOT "%RESULT%" == "0" SET /A RESULT_TOTAL=RESULT_TOTAL+1
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

rem --- ERRORLEVELリセット ---
:RESET_ERRORLEVEL
DATE /t >NUL
EXIT /B
