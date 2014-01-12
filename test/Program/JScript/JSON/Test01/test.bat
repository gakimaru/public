@ECHO OFF
CD /D %dp~0
rem CHCP 65001
CHCP 932
CScript.exe //Nologo %~dp0test.js
PAUSE
