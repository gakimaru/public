@ECHO OFF
CD /D %~dp0
Release\sync_nosync_win.exe > sync_nosync_win.log
TYPE sync_nosync_win.log
PAUSE
