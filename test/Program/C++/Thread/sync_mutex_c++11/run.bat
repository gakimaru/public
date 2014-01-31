@ECHO OFF
CD /D %~dp0
Release\sync_mutex_c++11.exe > sync_mutex_c++11.log
TYPE sync_mutex_c++11.log
PAUSE
