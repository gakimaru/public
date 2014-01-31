@ECHO OFF
CD /D %~dp0
Release\sync_interlocked_win.exe > sync_interlocked_win.log
TYPE sync_interlocked_win.log
PAUSE
