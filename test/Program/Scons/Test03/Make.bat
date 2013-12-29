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

rem --- Microsoft Visual C++ 2008 Express Edition �̃p�X��ʂ� ---
SET VS90DIR=D:\Program Files (x86)\Microsoft Visual Studio 9.0\
IF "%VS90COMNTOOLS%" == "%VS90COMNTOOLS%" SET VS90COMNTOOLS=%VS90DIR%Common7\Tools\
CALL "%VS90DIR%VC\vcvarsall.bat" >NUL

rem --- TEMP ���� ---
rem �����ϐ� TEMP �� TMP �ɓ��{�ꂪ�����Ă����Scons�����삵�Ȃ��̂Œ��ӁB
rem   ���[�U�[���ɓ��{�ꂪ�܂܂�Ă���Ƃ��̂悤�ȏ�ԂɂȂ�
rem   �΍�Ƃ��āA���ϐ��̓��e�������ɏ��������Ă���
SET TEMP=%~dp0_temp
SET TMP=%~dp0_temp
IF NOT EXIST %TEMP% MKDIR %TEMP%

rem --- �J�n ---
ECHO.
ECHO ********** �e�X�g�J�n **********

rem --- Scons �����s ---
CALL :RUN_CMD CALL scons.bat --tree=all

rem �y���s���I�v�V�����z
rem   -c �I�v�V������t����ƁA�^�[�Q�b�g�t�@�C�����폜���Ă����imake clean �Ɠ�������j
rem   --debug=explain �I�v�V������t����ƁA�r���h���s���̗��R���\�������B
rem   --tree=all �I�v�V������t����ƁA�^�[�Q�b�g�̈ˑ��֌W���\�������B

rem --- C++�v���v���Z�b�T�e�X�g ---
rem �����p���p�\�Ȗ����R���p�C�� Microsoft Visual C++ 2008 Express ���g�p����
rem   http://homepage2.nifty.com/nonnon/Chinamini/20110001/20110307.html

rem SET SCRIPT_BASE=%~dp0
rem SET CL_OPT=/nologo /TP /E /I "%SCRIPT_BASE%include00" /I "%SCRIPT_BASE%include01" /I "%SCRIPT_BASE%include02" /FI "script_header_common01.h" /FI "script_header_common02.h" /D=XXX /D=YYY
rem CL.exe %CL_OPT% %SCRIPT_BASE%src\test00.script > %SCRIPT_BASE%preprocess\test00.script.i
rem CL.exe %CL_OPT% %SCRIPT_BASE%src\test01\test01.script > %SCRIPT_BASE%preprocess\test01.script.i
rem CL.exe %CL_OPT% %SCRIPT_BASE%src\test02\test02a.script > %SCRIPT_BASE%preprocess\test02a.script.i
rem CL.exe %CL_OPT% %SCRIPT_BASE%src\test02\test02b.script > %SCRIPT_BASE%preprocess\test02b.script.i

rem �yCL.exe �v���v���Z�b�T���o�͂Ɋ֌W�����ȃI�v�V�����z �u���v�͎g�p�I�v�V����
rem   /P  ... �t�@�C����O�������� (.i�t�@�C���ɏo��)
rem ��/E  ... stdout �ɑO��������
rem   /EP ... stdout �ɑO��������A#line �Ȃ�
rem   /C  ... �R�����g���폜���Ȃ�
rem   /Fx ... �}���R�[�h���t�@�C���Ƀ}�[�W����
rem ��/I<dir>   ... �C���N���[�h�����p�X�ɒǉ�����
rem ��/FI<File> ... �K���g�p�����C���N���[�h �t�@�C�������w�肷��
rem ��/D<name>{=|#}<text> ... �}�N�����`����
rem ��/nologo ... ���쌠���b�Z�[�W��\�����Ȃ�
rem   /showIncludes ... �C���N���[�h �t�@�C������\������
rem   /Tc<source file> ... �t�@�C���� .c �Ƃ��ăR���p�C������
rem   /Tp<source file> ... �t�@�C���� .cpp �Ƃ��ăR���p�C������
rem   /TC ... ���ׂẴt�@�C���� .c �Ƃ��ăR���p�C������
rem ��/TP ... ���ׂẴt�@�C���� .cpp �Ƃ��ăR���p�C������

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
