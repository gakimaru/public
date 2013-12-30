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

rem --- �J�n ---
ECHO.
ECHO ********** �e�X�g�J�n **********

rem --- Scons �����s ---
CALL :RUN_CMD CALL scons.bat --tree=all --debug=explain

rem �y���s���I�v�V�����z
rem   -c �I�v�V������t����ƁA�^�[�Q�b�g�t�@�C�����폜���Ă����imake clean �Ɠ�������j
rem   --debug=explain �I�v�V������t����ƁA�r���h���s���̗��R���\�������B
rem   --tree=all �I�v�V������t����ƁA�^�[�Q�b�g�̈ˑ��֌W���\�������B
rem   -Q �I�v�V����������� scons ���Â��ɂȂ��� gcc �̃��b�Z�[�W���\������܂��B
rem   install �I�v�V����������� make install �̐U�镑�������܂��B

rem --- C++�v���v���Z�b�T�e�X�g ---
rem ��MinGW��GCC���g�p����
rem   http://www3.u-toyama.ac.jp/kihara/pgm/gcc.html

rem SET SCRIPT_BASE=%~dp0
rem SET CCFLAGS=-x c++ -E -I "%SCRIPT_BASE%include00" -I "%SCRIPT_BASE%include01" -I "%SCRIPT_BASE%include02" -include "script_header_common01.h" -include "script_header_common02.h" -DXXX -DYYY
rem CALL :RUN_CMD g++.exe %CCFLAGS% -c %SCRIPT_BASE%src\test00.script -M -MF %SCRIPT_BASE%preprocess\test00.script.d -o %SCRIPT_BASE%preprocess\test00.script.i
rem CALL :RUN_CMD g++.exe %CCFLAGS% -c %SCRIPT_BASE%src\test01\test01.script -M -MF %SCRIPT_BASE%preprocess\test01\test01.script.d -o %SCRIPT_BASE%preprocess\test01\test01.script.i
rem CALL :RUN_CMD g++.exe %CCFLAGS% -c %SCRIPT_BASE%src\test02\test02a.script -M -MF %SCRIPT_BASE%preprocess\test02\test02a.script.d -o %SCRIPT_BASE%preprocess\test02\test02a.script.i
rem CALL :RUN_CMD g++.exe %CCFLAGS% -c %SCRIPT_BASE%src\test02\test02b.script -M -MF %SCRIPT_BASE%preprocess\test02\test02b.script.d -o %SCRIPT_BASE%preprocess\test02\test02b.script.i

rem �yg++.exe �v���v���Z�b�T���o�͂Ɋ֌W�����ȃI�v�V�����z �u���v�͎g�p�I�v�V����
rem ��-c  ... �\�[�X�E�t�@�C���̃R���p�C���A �܂��́A �A�Z���u�����s���܂����A
rem           �����N�͍s���܂���B �����N�����i�K�͎��s����܂���B �ŏI�I��
rem           �o�͌`�Ԃ́A �X�̃\�[�X�E�t�@�C���ɑΉ�����I�u�W�F�N�g�E
rem           �t�@�C���ƂȂ�܂��B �f�t�H���g�ł́A �\�[�X�E�t�@�C���ɑΉ�����
rem           �I�u�W�F�N�g�E�t�@�C���̖��O�́A �\�[�X�E�t�@�C������
rem           �ڔ���`.c'�A `.i'�A `.s'����`.o'�ɒu�������邱�Ƃɂ���č���܂��B
rem           �ڔ��ꂪ�F������Ȃ����̓t�@�C���́A �R���p�C�����A�Z���u�����K�v��
rem           ����Ȃ��̂ŁA ��������܂��B 
rem ��-o file 
rem       ... file�ɂ���Ďw�肳���t�@�C�����o�͐�Ƃ��܂��B ����́A ����
rem           �����o�͂̎�ނɊ֌W�Ȃ��K�p����܂��B �o�͂��A ���s�\
rem           �t�@�C���A �I�u�W�F�N�g�E�t�@�C���A �A�Z���u���E�t�@�C���A
rem           �O�����ς݂�C�R�[�h�̂�����ł����Ă��A ���֌W�ɓK�p����܂��B
rem           �o�̓t�@�C����1�����w��ł��Ȃ��̂ŁA �����̓��̓t�@�C����
rem           �R���p�C������ۂ�`-o'���g���̂́A �o�͂Ƃ��Ď��s�\�t�@�C����
rem           �������悤�Ƃ��Ă���ꍇ�������΁A �Ӗ��̂Ȃ����Ƃł��B `-o'��
rem           �w�肳��Ȃ��ƁA �f�t�H���g�ł́A ���s�\�t�@�C����`a.out'�ɁA
rem           `source.suffix'�ɑΉ�����I�u�W�F�N�g�E�t�@�C����`source.o'�ɁA
rem           `source.suffix'�ɑΉ�����A�Z���u���E�t�@�C����`source.s'�ɁA
rem           �܂��A ���ׂĂ̑O�����ς݂�C�̃\�[�X�͕W���o�͂ɁA ���ꂼ��
rem           �o�͂���܂��B 
rem ��-x language
rem       ... �㑱�̓��̓t�@�C���̌�����A �i�t�@�C�����̐ڔ���ɂ���Č��܂�
rem           �f�t�H���g�̌�����R���p�C���ɑI��������̂ł͂Ȃ��j language��
rem           ����Ė����I�Ɏw�肵�܂��B ���̃I�v�V�����́A �㑱�̓��̓t�@�C����
rem           �����A ����`-x'�I�v�V���������O�Ɏw�肳�ꂽ���̂��ׂĂɑ΂���
rem           �K�p����܂��B language�Ɏw�肷�邱�Ƃ̂ł���l�͈ȉ��̂Ƃ���ł��B
rem               c  objective-c  c++
rem               c-header  cpp-output  c++-cpp-output
rem               assembler  assembler-with-cpp
rem ��-include file
rem       ... �ʏ�̓��̓t�@�C������������O�ɁA file�ɂ��w�肳���t�@�C����
rem           ���͂Ƃ��ď������܂��B ������A file�̓��e���ŏ��ɃR���p�C��
rem           ����邱�ƂɂȂ�܂��B �R�}���h���C����ɂ���`-D'�I�v�V������
rem           `-U'�I�v�V�����́A ����炪�w�肳�ꂽ�����Ɋ֌W�Ȃ��A 
rem           ���`-include file'�����O�ɏ�������܂��B ���ׂĂ�`-include'
rem           �I�v�V������`-imacros'�I�v�V�����́A �w�肳�ꂽ�����ɏ�������܂��B 
rem   -imacros file
rem       ... �ʏ�̓��̓t�@�C������������O�ɁA file�ɂ��w�肳���t�@�C����
rem           ���͂Ƃ��ď������܂����A ���̏o�͌��ʂ͔j�����܂��B file����
rem           ���������o�͔͂j�������̂ŁA `-imacros file'�̗B��̌��ʂ́A
rem           file�̒��Œ�`����Ă���}�N�����A ��v�ȓ��̓t�@�C���̒���
rem           �g�p�\�ɂ��邱�Ƃɂ���܂��B �R�}���h���C����ɂ���
rem           `-D'�I�v�V������`-U'�I�v�V�����́A ����炪�w�肳�ꂽ������
rem           �֌W�Ȃ��A ���`-imacros file'�����O�ɏ�������܂��B ���ׂĂ�
rem           `-include'�I�v�V������`-imacros'�I�v�V�����́A �w�肳�ꂽ������
rem           ��������܂��B
rem ��-Idir
rem       ... �w�b�_�E�t�@�C���������邽�߂ɒT������f�B���N�g���̈ꗗ��
rem           �擪�Ƀf�B���N�g��dir��ǉ����܂��B �����̃f�B���N�g����
rem           �V�X�e���E�w�b�_�E�t�@�C���̃f�B���N�g�������O�ɒT�������̂ŁA
rem           ���̃I�v�V�������g���āA �V�X�e���E�w�b�_�E�t�@�C���𖳌��ɂ��āA
rem           ���[�U���Ǝ��ɍ쐬�����w�b�_�E�t�@�C���Œu�������邱�Ƃ��ł��܂��B
rem           `-I'�I�v�V�����𕡐���g�p����ƁA �w�肳�ꂽ�f�B���N�g���͍�����
rem           �E�̏����Œ��ׂ��܂��B �W���V�X�e���E�f�B���N�g���͂��̂��Ƃ�
rem           ���ׂ��܂��B 
rem   -idirafter dir
rem       ... �f�B���N�g��dir���2�̃C���N���[�h�E�p�X�ɒǉ����܂��B ��2��
rem           �C���N���[�h�E�p�X�Ɋ܂܂��f�B���N�g���́A ����w�b�_�E�t�@�C����
rem           ���C���E�C���N���[�h�E�p�X �i`-I'�I�v�V�����͂����Ƀf�B���N�g����
rem           �ǉ����܂��j �Ɋ܂܂��ǂ̃f�B���N�g���̒��ɂ�������Ȃ��ꍇ��
rem           �T������܂��B
rem   -iprefix prefix
rem       ... �㑱��`-iwithprefix'�I�v�V�����̂��߂̐ړ���Ƃ���prefix���w��
rem           ���܂��B
rem   -iwithprefix dir
rem       ... �f�B���N�g�����2�̃C���N���[�h�E�p�X�ɒǉ����܂��B �f�B���N�g����
rem           ���O�́A ���O��`-iprefix'�ɂ��w�肳�ꂽ�ړ���prefix��dir��
rem           �A�����邱�Ƃɂ���č���܂��B �ړ��ꂪ���O�Ɏw�肳��Ă��Ȃ�
rem           �ꍇ�ɂ́A �R���p�C�����C���X�g�[�����ꂽ�f�B���N�g�����f�t�H���g��
rem           �ړ���Ƃ��Ďg���܂��B
rem   -iwithprefixbefore dir
rem       ... ���C���E�C���N���[�h�E�p�X�Ƀf�B���N�g����ǉ����܂��B
rem           `-iwithprefix'�̏ꍇ�Ɠ��l�A �f�B���N�g���̖��O�́A prefix��dir��
rem           �A�����邱�Ƃɂ���č���܂��B
rem   -isystem dir
rem       ... �f�B���N�g�����2�̃C���N���[�h�E�p�X�̐擪�ɒǉ����A �W����
rem           �V�X�e���E�f�B���N�g���ɓK�p�����̂Ɠ����̓���Ȏ�舵����
rem           �󂯂���悤�ɂ��邽�߂ɁA �V�X�e���E�f�B���N�g���Ƃ��ă}�[�N
rem           ���܂��B
rem   -nostdinc
rem       ... �w�b�_�E�t�@�C����T���ۂɁA �W���̃V�X�e���E�f�B���N�g����
rem           �T�����܂���B`-I'�I�v�V�����ɂ��w�肳�ꂽ�f�B���N�g�� �i����сA
rem           �J�����g�E�f�B���N�g����T�����邱�Ƃ��K�؂ł���ꍇ�ɂ́A
rem           �J�����g�E�f�B���N�g���j �������T������܂��B `-I'�Ɋւ������
rem           ���ẮA �f�B���N�g���T���̂��߂̃I�v�V�������Q�Ƃ��Ă��������B
rem           `-nostdinc'��`-I-'�𗼕��g�p���邱�Ƃɂ��A �C���N���[�h�E�t�@�C����
rem           �T���p�X���A �����I�Ɏw�肵���f�B���N�g�������Ɍ��肷�邱�Ƃ�
rem           �ł��܂��B 
rem ��-E  ... C�v���v���Z�b�T���������s���܂��B �w�肳�ꂽ���ׂĂ�C�\�[�X�E
rem           �t�@�C����O�������āA ���̌��ʂ�W���o�́A �������́A �w�肳�ꂽ
rem           �o�̓t�@�C���ɏo�͂��܂��B 
rem   -C  ... �v���v���Z�b�T�ɑ΂��āA �R�����g��j�����Ȃ��悤�w�����܂��B
rem           `-E'�I�v�V�����ƂƂ��Ɏg���܂��B
rem   -P  ... �v���v���Z�b�T�ɑ΂��āA `#line'�w���q�𐶐����Ȃ��悤�w�����܂��B
rem           `-E'�I�v�V�����ƂƂ��Ɏg���܂��B
rem ��-M  ... �v���v���Z�b�T�ɑ΂��āA make�R�}���h�Ŏg���̂ɓK�����A �X��
rem           �I�u�W�F�N�g�E�t�@�C���̈ˑ��֌W���L�q�������[�������o��
rem           ����悤�w�����܂��B �v���v���Z�b�T�́A �X�̃\�[�X�E�t�@�C����
rem           �΂��āA ���̃\�[�X�E�t�@�C���ɑΉ�����I�u�W�F�N�g�E�t�@�C������
rem           �ˑ��֌W�̃^�[�Q�b�g�ł���A ���̃\�[�X�E�t�@�C����#include�ɂ��
rem           ��荞�ނ��ׂẴw�b�_�E�t�@�C�����ˑ��֌W�̃\�[�X�ł���悤��
rem           make���[�����o�͂��܂��B(5) ���̃��[���͒P��s�̏ꍇ������܂����A
rem           �����ꍇ�ɂ́A ���s�̒��O��`\'��u�����Ƃɂ�蕡���s�Ɍp������
rem           ���Ƃ�����܂��B ���[���̈ꗗ�́A �O�������ꂽC�v���O�����̒���
rem           �ł͂Ȃ��A �W���o�͂ɕ\������܂��B `-M'�͈Öق̂�����`-E'��
rem           �w�肵�܂��B make���[�����o�͂���悤�w�肷��ʂ̕��@�ɁA 
rem           ���ϐ�DEPENDENCIES_OUTPUT �iGCC�ɉe����^������ϐ����Q�Ɓj ��
rem           �ݒ肷����@������܂��B
rem   -MM ... `-M'�Ǝ��Ă��܂����A �o�͂̒��ɂ́A `#include "file"'�ɂ��
rem           ��荞�܂ꂽ���[�U�E�w�b�_�E�t�@�C���������L�q����܂��B 
rem           `#include <file>'�ɂ���荞�܂ꂽ�V�X�e���E�w�b�_�E�t�@�C����
rem           �Ȃ���܂��B -MD `-M'�Ǝ��Ă��܂����A �ˑ��֌W�̏��́A ����
rem           �t�@�C�����̖�����".c"��".d"�ɒu�����������O�̃t�@�C���ɏ������܂�
rem           �܂��B �w�肳�ꂽ�t�@�C���̓R���p�C������A ����ɉ����āA 
rem           ���̂悤�ȏ������s���܂��B `-MD'�́A `-M'�̂悤�ɒʏ��
rem           �R���p�C���������֎~���邱�Ƃ����܂���B Mach�ł́A ���[�e�B���e�B
rem           md���g�����Ƃɂ��A �����̈ˑ��֌W�t�@�C�����}�[�W���āA
rem           `make'�R�}���h�Ŏg���̂ɓK�����P��̈ˑ��֌W�t�@�C�����쐬����
rem           ���Ƃ��ł��܂��B
rem   -MMD... `-MD'�Ǝ��Ă��܂����A ���[�U�E�w�b�_�E�t�@�C���������ΏۂƂȂ�A 
rem           �V�X�e���E�w�b�_�E�t�@�C�����Ȃ����_���Ⴂ�܂��B -MG ������Ȃ�
rem           �w�b�_�E�t�@�C���͐��������t�@�C���Ƃ��Ď�舵���A �\�[�X�E
rem           �t�@�C���Ɠ����f�B���N�g���ɑ��݂�����̂Ƒz�肵�܂��B `-MG'��
rem           �w�肷��ꍇ�ɂ́A `-M'��`-MM'�̂����ꂩ�����킹�Ďw�肵�Ȃ����
rem           �Ȃ�܂���B `-MD'��`-MMD'���w�肳��Ă���ꍇ�ɂ́A `-MG'��
rem           �T�|�[�g����܂���B
rem ��-MF file
rem       ... When used with '-M' or '-MM', specifies a file to write the
rem           dependencies to. If no '-MF' switch is given the preprocessor
rem           sends the rules to the same place it would have sent preprocessed
rem           output. 
rem           When used with the driver options '-MD' or '-MMD', '-MF' overrides
rem           the default dependency output file. 
rem   -H  ... �ʏ�̏����ɉ����āA �g�p�����X�̃w�b�_�E�t�@�C���̖��O��
rem           �\�����܂��B 
rem   -Aquestion(answer)
rem       ... `#if #question(answer)'�̂悤�ȑO�����̏������Ńe�X�g�����ꍇ��
rem           �����āA question�ɑ΂��铚��answer��f�f���܂��B `-A-'�́A
rem           �ʏ�ł���΃^�[�Q�b�g�E�}�V�����L�q����W���̐f�f���A �g�p�s��
rem           ���܂��B
rem ��-Dmacro
rem       ... �}�N��macro�𕶎���`1'�Ƃ��Ē�`���܂��B
rem   -Dmacro=defn
rem       ... �}�N��macro��defn�Ƃ��Ē�`���܂��B �R�}���h���C����ɂ���
rem           ���ׂĂ�`-D'�I�v�V�����́A �ǂ�`-U'�I�v�V���������O�ɏ���
rem           ����܂��B
rem   -Umacro
rem       ... �}�N��macro�̒�`���������܂��B `-U'�I�v�V�����́A ���ׂĂ�
rem           `-D'�I�v�V�����̕]�����I��������Ƃŕ]������܂����A �ǂ�
rem           `-include'�I�v�V������`-imacros'�I�v�V���������O�ɕ]������܂��B
rem   -dM ... �v���v���Z�b�T�ɑ΂��āA �O�����̏I�����_�ɂ����ėL���ȃ}�N����`��
rem           �ꗗ�������o�͂���悤�w�����܂��B `-E'�I�v�V�����ƂƂ��Ɏg���܂��B
rem   -dD ... �v���v���Z�b�T�ɑ΂��āA �}�N���̐������o�������ŁA ���ׂĂ�
rem           �}�N����`���o�͂֓n���悤�w�����܂��B
rem   -dN ... `-dD'�Ǝ��Ă��܂����A �}�N�������ƃ}�N����`�̓��e���Ȃ����_��
rem           �Ⴂ�܂��B `#define name'�Ƃ����`���̏�񂾂����o�͂Ɋ܂܂�܂��B 

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
