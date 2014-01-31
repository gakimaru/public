@ECHO OFF
CD /D %~dp0
Release\monitor_named_event_win.exe > monitor_named_event_win.log
TYPE monitor_named_event_win.log
PAUSE
