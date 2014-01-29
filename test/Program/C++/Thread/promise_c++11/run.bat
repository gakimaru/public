@ECHO OFF
CD /D %~dp0
Release\promise_c++11.exe > promise_c++11.log
TYPE promise_c++11.log
PAUSE
