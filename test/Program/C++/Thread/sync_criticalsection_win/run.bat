@ECHO OFF
CD /D %~dp0
Release\sync_criticalsection_win.exe > sync_criticalsection_win.log
TYPE sync_criticalsection_win.log
PAUSE
