@ECHO OFF

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

rem --- �e�X�g����(1) ---
ECHO.
CALL :RUN_CMD Debug\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO ���s����=%RESULT%

rem --- �e�X�g����(2) ---
ECHO.
CALL :RUN_CMD Debug_UT_ENABLED\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO ���s����=%RESULT%

rem --- �e�X�g����(3) ---
ECHO.
CALL :RUN_CMD Debug_UT_ENABLED_AUTO\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO ���s����=%RESULT%

rem --- �e�X�g����(4) ---
ECHO.
CALL :RUN_CMD Debug_UT_ENABLED_AUTO_TARGET_MODULE\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO ���s����=%RESULT%

rem --- �e�X�g����(5) ---
ECHO.
CALL :RUN_CMD Debug_UT_ENABLED_AUTO_TARGET_GROUP\UnitTest.exe
SET RESULT=%ERRORLEVEL%
ECHO ���s����=%RESULT%

rem --- �I�� ---
ECHO.
CALL :PAUSE_MSG ���s�I��
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
