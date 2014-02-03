@ECHO OFF
CD /D %~dp0
Release\sync_rwlock_c++11.exe > sync_rwlock_c++11.log
TYPE sync_rwlock_c++11.log
PAUSE
