@ECHO OFF
CD /D %~dp0
Release\share_semaphore_win.exe > share_semaphore_win.log
TYPE share_semaphore_win.log
PAUSE
