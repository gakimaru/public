@ECHO OFF

rem --- �o�b�`�t�@�C���̑��݂���p�X�i�h���C�u���f�B���N�g���j�ɃJ�����g�f�B���N�g����ύX ---
CD /D %~dp0

rem --- ���݂̃R�[�h�y�[�W���m�F ---
rem CHCP
rem --- �R�[�h�y�[�W�w��F�p�� ---
rem CHCP 437 >NUL
rem --- �R�[�h�y�[�W�w��FUTF-8 ---
rem CHCP 65001 >NUL
rem --- �R�[�h�y�[�W�w��FUTF-16(Unicode) ---
rem CHCP 1200 >NUL
rem --- �R�[�h�y�[�W�w��F���{��i�V�t�gJIS�j ---
CHCP 932 >NUL

rem --- �K�C�h�t���v���t�@�C���̃C���X�g�������g�����s����ׂ� VC++ �̃p�X��ʂ� ---
CALL "D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"

rem --- ���s�Ώۃr���h ---
rem SET BUILD_TARGET=Debug
SET BUILD_TARGET=Release

rem --- �J�n ---
ECHO.
ECHO ********** �e�X�g�J�n **********

rem --- �e�X�g����(1) ---
rem ECHO.
rem CALL :RUN_CMD %BUILD_TARGET%\UnitTest.exe
rem SET RESULT=%ERRORLEVEL%
rem ECHO ���s����=%RESULT%

rem --- �e�X�g����(2) ---
rem ECHO.
rem CALL :RUN_CMD %BUILD_TARGET%_UT_ENABLED\UnitTest.exe
rem SET RESULT=%ERRORLEVEL%
rem ECHO ���s����=%RESULT%

rem --- �e�X�g����(3) ---
ECHO.
CALL :RUN_CMD %BUILD_TARGET%_UT_ENABLED_AUTO\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO ���s����=%RESULT%

rem --- �e�X�g����(4) ---
rem ECHO.
rem CALL :RUN_CMD %BUILD_TARGET%_UT_ENABLED_AUTO_TARGET_MODULE\UnitTest.exe
rem SET RESULT=%ERRORLEVEL%
rem ECHO ���s����=%RESULT%

rem --- �e�X�g����(5) ---
rem ECHO.
rem CALL :RUN_CMD %BUILD_TARGET%_UT_ENABLED_AUTO_TARGET_GROUP\UnitTest.exe
rem SET RESULT=%ERRORLEVEL%
rem ECHO ���s����=%RESULT%

rem --- �I�� ---
ECHO.
CALL :PAUSE_MSG ********** �e�X�g�I�� **********
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
