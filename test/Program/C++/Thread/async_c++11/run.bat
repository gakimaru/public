@ECHO OFF
CD /D %~dp0
Release\async_c++11.exe > async_c++11.log
TYPE async_c++11.log
PAUSE
