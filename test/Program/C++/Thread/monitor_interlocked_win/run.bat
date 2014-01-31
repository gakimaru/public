@ECHO OFF
CD /D %~dp0
Release\monitor_interlocked_win.exe > monitor_interlocked_win.log
TYPE monitor_interlocked_win.log
PAUSE
