@ECHO OFF

rem --- �o�b�`�t�@�C���̑��݂���p�X�i�h���C�u���f�B���N�g���j�ɃJ�����g�f�B���N�g����ύX ---
CD /D %~dp0

rem --- Python �̃p�X��ʂ� ---
SET PYTHON_DIR=D:\Python\27\x64
SET PATH=%PYTHON_DIR%\;%PYTHON_DIR%\Scripts\;%PATH%

rem --- MinGW(GCC)�̃p�X��ʂ� ---
SET MINGW_BIN_DIR=D:\MinGW\bin
SET PATH=%MINGW_BIN_DIR%;%PATH%

rem --- TEMP ���� ---
rem �����ϐ� TEMP �� TMP �ɓ��{�ꂪ�����Ă����Scons�����삵�Ȃ��̂Œ��ӁB
rem   ���[�U�[���ɓ��{�ꂪ�܂܂�Ă���Ƃ��̂悤�ȏ�ԂɂȂ�
rem   �΍�Ƃ��āA���ϐ��̓��e�������ɏ��������Ă���
SET TEMP=%~dp0_temp
SET TMP=%~dp0_temp
IF NOT EXIST %TEMP% MKDIR %TEMP%

rem --- Scons �����s ---
CALL :RUN_CMD CALL scons.bat --tree=all --debug=explain
SET RESULT=%ERRORLEVEL%

rem --- �I�� ---
ECHO.
PAUSE
EXIT /B %RESULT%

rem --- �W���T�u���[�`���F�R�}���h���C����\�����Ď��s ---
:RUN_CMD
ECHO ^> %*
%*
EXIT /B %ERRORLEVEL%
