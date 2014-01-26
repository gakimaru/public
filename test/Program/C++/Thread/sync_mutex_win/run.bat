@ECHO OFF
CD /D %~dp0
Release\sync_mutex_win.exe > sync_mutex_win.log
TYPE sync_mutex_win.log
PAUSE
