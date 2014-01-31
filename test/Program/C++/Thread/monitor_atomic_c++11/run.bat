@ECHO OFF
CD /D %~dp0
Release\monitor_atomic_c++11.exe > monitor_atomic_c++11.log
TYPE monitor_atomic_c++11.log
PAUSE
