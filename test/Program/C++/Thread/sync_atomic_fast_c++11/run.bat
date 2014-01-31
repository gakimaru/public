@ECHO OFF
CD /D %~dp0
Release\sync_atomic_fast_c++11.exe > sync_atomic_fast_c++11.log
TYPE sync_atomic_fast_c++11.log
PAUSE
