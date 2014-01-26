@ECHO OFF
CD /D %~dp0
Release\share_named_semaphore_win.exe > share_named_semaphore_win.log
TYPE share_named_semaphore_win.log
PAUSE
