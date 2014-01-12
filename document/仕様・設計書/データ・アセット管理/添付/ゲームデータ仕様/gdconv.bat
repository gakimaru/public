@ECHO OFF

rem --- �o�b�`�t�@�C���̑��݂���p�X�i�h���C�u���f�B���N�g���j�ɃJ�����g�f�B���N�g����ύX ---
CD /D %~dp0

rem --- MinGW(GCC)�̃p�X��ʂ� ---
SET MINGW_BIN_DIR=D:\MinGW\bin
SET PATH=%MINGW_BIN_DIR%;%PATH%

rem --- �v���v���Z�b�T�I�v�V���� ---
SET PP_FLAGS=-x c++ -E -P
SET PP_INC_DIRS=-I . -I "lib/common"
rem SET PP_INCLUDES=-include "common.hjson"
SET PP_INCLUDES=

rem --- �f�[�^�ϊ��I�v�V���� ---
SET GD_FLAGS=--le --p32 --sp8 --dbgcrc -dbgexpr --utf8 --dbgutf8
SET GD_MKSRC_FLAGS=--makesrc --srcutf8

SET GD_TYPE_FILE01=settings/common_type
SET GD_TYPE_FILE02=settings/ext_type

SET GD_FUNC_FILE01=settings/ext_func01
SET GD_FUNC_FILE02=settings/ext_func02

SET GD_FORMAT_FILE=settings/chara_fomat
SET GD_FORMAT_INC_FILE=include/chara_format.h
SET GD_FORMAT_SRC_FILE=src/chara_format.cpp

rem --- �J�n ---
ECHO ***** �f�[�^�ϊ��J�n *****
ECHO.
SET RESULT_TOTAL=0

rem --- �^��`���X�g�̃v���v���Z�b�T���s ---
CALL :PREPROCESSOR %GD_TYPE_FILE01%
CALL :PREPROCESSOR %GD_TYPE_FILE02%

rem --- �g���֐���`���X�g�̃v���v���Z�b�T���s ---
CALL :PREPROCESSOR %GD_FUNC_FILE01%
CALL :PREPROCESSOR %GD_FUNC_FILE02%

rem --- �t�H�[�}�b�g��`JSON�̃v���v���Z�b�T���s ---
CALL :PREPROCESSOR %GD_FORMAT_FILE%

rem --- �\�[�X�t�@�C���쐬 ---
CALL :GDSRCCONV %GD_FORMAT_FILE% 

rem --- �f�[�^�ϊ����s ---
CALL :GDCONV %GD_FORMAT_FILE% data/data01 bin/data01
CALL :GDCONV %GD_FORMAT_FILE% data/data02 bin/data02
CALL :GDCONV %GD_FORMAT_FILE% data/data03 bin/data03

rem --- �I�� ---
ECHO.
ECHO �G���[��: %RESULT_TOTAL%
CALL :PAUSE_MSG ***** �f�[�^�ϊ��I�� *****
EXIT /B %RESULT_TOTAL%

rem ========== �v���v���Z�b�T���s ==========
:PREPROCESSOR
SET JSON_FILE=%1.json
SET JSON_PP_FILE=%2
IF "%JSON_PP_FILE%" == "" SET JSON_PP_FILE=%1
SET JSON_PP_FILE=%JSON_PP_FILE%.i.json
ECHO.
ECHO ----------------------------------------
ECHO �v���v���Z�b�T���s: "%JSON_FILE%" to "%JSON_PP_FILE%"
CALL :RESET_ERRORLEVEL
CALL :RUN_CMD g++.exe %PP_FLAGS% %PP_INC_DIRS% %PP_INCLUDES% -c "%JSON_FILE%" -o "%JSON_PP_FILE%"
SET RESULT=%ERRORLEVEL%
IF NOT "%RESULT%" == "0" ECHO �G���[�I
IF NOT "%RESULT%" == "0" SET /A RESULT_TOTAL=RESULT_TOTAL+1
EXIT /B %RESULT%

rem ========== �\�[�X�t�@�C���������s ==========
:GDSRCCONV
SET FORMAT_FILE=%1.i.json
ECHO.
ECHO ----------------------------------------
ECHO �\�[�X�t�@�C������: "%FORMAT_FILE%"
CALL :RESET_ERRORLEVEL
CALL :RUN_CMD gdconv.exe %GD_MKSRC_FLAGS% -t "%GD_TYPE_FILE01%.i.json" -t "%GD_TYPE_FILE02%.i.json" -f "%GD_FUNC_FILE01%.i.json" -f "%GD_FUNC_FILE02%.i.json" -d "%FORMAT_FILE%"
SET RESULT=%ERRORLEVEL%
IF NOT "%RESULT%" == "0" ECHO �G���[�I
IF NOT "%RESULT%" == "0" SET /A RESULT_TOTAL=RESULT_TOTAL+1
EXIT /B %RESULT%

rem ========== �f�[�^�ϊ����s ==========
:GDCONV
SET FORMAT_FILE=%1.i.json
SET JSON_FILE=%2.json
SET JSON_PP_FILE=%2.i.json
SET JSON_MID_FILE=%2.m.json
SET JSON_CHECK_FILE=%2.c.json
SET BIN_FILE=%3.bin
ECHO.
ECHO ----------------------------------------
ECHO �f�[�^�ϊ�: "%JSON_FILE%" to "%BIN_FILE%"
CALL :RESET_ERRORLEVEL
CALL :RUN_CMD g++.exe %PP_FLAGS% %PP_INC_DIRS% %PP_INCLUDES% -c "%JSON_FILE%" -o "%JSON_PP_FILE%"
SET RESULT=%ERRORLEVEL%
IF NOT "%RESULT%" == "0" ECHO �G���[�I
IF NOT "%RESULT%" == "0" SET /A RESULT_TOTAL=RESULT_TOTAL+1
CALL :RUN_CMD gdconv.exe %GD_FLAGS% -t "%GD_TYPE_FILE01%.i.json" -t "%GD_TYPE_FILE02%.i.json" -f "%GD_FUNC_FILE01%.i.json" -f "%GD_FUNC_FILE02%.i.json" -d "%FORMAT_FILE%" -i "%JSON_PP_FILE%" -o "%BIN_FILE%" -c "%JSON_CHECK_FILE%" -m "%JSON_MID_FILE%"
SET RESULT=%ERRORLEVEL%
IF NOT "%RESULT%" == "0" ECHO �G���[�I
IF NOT "%RESULT%" == "0" SET /A RESULT_TOTAL=RESULT_TOTAL+1
EXIT /B %RESULT%

rem ========== �W���T�u���[�`�� ==========

rem --- �W���T�u���[�`���F�R�}���h���C����\�����Ď��s ---
:RUN_CMD
ECHO ^> %*
%*
EXIT /B %ERRORLEVEL%

rem --- �W���T�u���[�`���F���b�Z�[�W�t���|�[�Y ---
:PAUSE_MSG
SET MSG=%*
IF "%MSG%" == "" SET MSG=���s����ɂ͉����L�[�������Ă��������D�D�D
ECHO.%MSG%
PAUSE >NUL
EXIT /B

rem --- ERRORLEVEL���Z�b�g ---
:RESET_ERRORLEVEL
DATE /t >NUL
EXIT /B
