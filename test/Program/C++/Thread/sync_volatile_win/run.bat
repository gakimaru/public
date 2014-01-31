@ECHO OFF
CD /D %~dp0
Release\sync_volatile_win.exe > sync_volatile_win.log
TYPE sync_volatile_win.log
PAUSE
