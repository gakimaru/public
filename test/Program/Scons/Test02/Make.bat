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

rem --- Python �̃p�X��ʂ� ---
SET PYTHON_DIR=D:\Python\27\x64
SET PATH=%PYTHON_DIR%\;%PYTHON_DIR%\Scripts\;%PATH%

rem --- TEMP ���� ---
rem �����ϐ� TEMP �� TMP �ɓ��{�ꂪ�����Ă����Scons�����삵�Ȃ��̂Œ��ӁB
rem   ���[�U�[���ɓ��{�ꂪ�܂܂�Ă���Ƃ��̂悤�ȏ�ԂɂȂ�
rem   �΍�Ƃ��āA���ϐ��̓��e�������ɏ��������Ă���
SET TEMP=%~dp0_temp
SET TMP=%~dp0_temp
MKDIR %TEMP%

rem --- �J�n ---
ECHO.
ECHO ********** �e�X�g�J�n **********

rem --- Scons �����s ---
CALL :RUN_CMD CALL scons.bat

rem �y���s���I�v�V�����z
rem   -c �I�v�V������t����ƁA�^�[�Q�b�g�t�@�C�����폜���Ă����imake clean �Ɠ�������j
rem   --debug=explain �I�v�V������t����ƁA�r���h���s���̗��R���\�������B
rem   --tree=all �I�v�V������t����ƁA�^�[�Q�b�g�̈ˑ��֌W���\�������B

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
