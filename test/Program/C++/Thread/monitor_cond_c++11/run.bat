@ECHO OFF
CD /D %~dp0
Release\monitor_cond_c++11.exe > monitor_cond_c++11.log
TYPE monitor_cond_c++11.log
PAUSE
