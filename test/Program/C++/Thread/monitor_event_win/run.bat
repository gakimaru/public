@ECHO OFF
CD /D %~dp0
Release\monitor_event_win.exe > monitor_event_win.log
TYPE monitor_event_win.log
PAUSE
