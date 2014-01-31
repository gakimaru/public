@ECHO OFF
CD /D %~dp0
Release\sync_asm_win.exe > sync_asm_win.log
TYPE sync_asm_win.log
PAUSE
