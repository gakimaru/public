@ECHO OFF
CD /D %~dp0
Release\sync_named_mutex_win.exe > sync_named_mutex_win.log
TYPE sync_named_mutex_win.log
PAUSE
