@ECHO OFF

rem Build for boost Ver.1.55.0
rem �Q�l�Fhttps://sites.google.com/site/boostjp/howtobuild
rem �Q�l�Fhttp://d.hatena.ne.jp/mintsu123/20130629/1372516484

rem ����� bootstrap_start.bat �����s���āAb2.exe �� bjam.exe ���쐬���Ă����B

SET TARGET_VER=1_55

SET BASE_DIR=E:\lib\boost
SET PREFIX_DIR=%BASE_DIR%\install\%TARGET_VER%

SET PREFIX_DIR_x86=%PREFIX_DIR%\x86
SET TARGET_DIR_x86=%BASE_DIR%\boost-%TARGET_VER%\x86
SET INCLUDE_DIR_x86=%TARGET_DIR_x86%\boost
SET LIB_DIR_x86=%TARGET_DIR_x86%\lib

rem SET STAGE_DIR_x86=%PREFIX_DIR_x86%\stage\lib
rem SET BUILD_DIR_x86=%PREFIX_DIR_x86%\build

SET PREFIX_DIR_x64=%PREFIX_DIR%\x64
SET TARGET_DIR_x64=%BASE_DIR%\boost-%TARGET_VER%\x64
SET INCLUDE_DIR_x64=%TARGET_DIR_x64%\boost
SET LIB_DIR_x64=%TARGET_DIR_x64%\lib

rem SET STAGE_DIR_x64=%PREFIX_DIR_x64%\stage\lib
rem SET BUILD_DIR_x64=%PREFIX_DIR_x64%\build

SET BUILD_x86="%~dp0b2.exe" install toolset=msvc-12.0 link=static threading=multi variant=debug,release runtime-link=static,shared architecture=x86 address-model=32 --prefix="%PREFIX_DIR_x86%" -j8

SET BUILD_x64="%~dp0b2.exe" install toolset=msvc-12.0 link=static threading=multi variant=debug,release runtime-link=static,shared architecture=x86 address-model=64 --prefix="%PREFIX_DIR_x64%" -j8

rem �ȉ��A�O�����I�v�V�����i���ϐ����������j
rem �g���Ɛ���ɓ��삵�Ȃ��Ȃ�I�v�V�����F --build-dir="%BUILD_DIR_x**%"
rem ����ɋ@�\���Ȃ��I�v�V�����F           --stagedir="%STAGE_DIR_x**%"

ECHO ********** CLEAN:x86 **********

rem %BUILD_x86% --clean

ECHO ********** CLEAN:x64 **********

rem %BUILD_x64% --clean

ECHO ********** BUILD:x86 **********

ECHO Building x86 ...
%BUILD_x86% > b2_x86.log
ECHO Finished. Build log is b2_x86.log.

IF NOT EXIST %TARGET_DIR_x86% MKDIR %TARGET_DIR_x86%
MOVE %PREFIX_DIR_x86%/include/boost-%TARGET_VER%/boost %TARGET_DIR_x86%\.
MOVE %PREFIX_DIR_x86%/lib %TARGET_DIR_x86%\.

ECHO ********** BUILD:x64 **********

ECHO Building x64 ...
%BUILD_x64% > b2_x64.log
ECHO Finished. Build log is b2_x64.log.

IF NOT EXIST %TARGET_DIR_x64% MKDIR %TARGET_DIR_x64%
MOVE %PREFIX_DIR_x64%/include/boost-%TARGET_VER%/boost %TARGET_DIR_x64%\.
MOVE %PREFIX_DIR_x64%/lib %TARGET_DIR_x64%\.

PAUSE
