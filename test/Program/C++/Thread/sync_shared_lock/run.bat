@ECHO OFF
CD /D %~dp0
Release\sync_shared_lock.exe > sync_shared_lock.log
TYPE sync_shared_lock.log
PAUSE
