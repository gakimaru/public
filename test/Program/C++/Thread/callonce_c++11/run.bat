@ECHO OFF
CD /D %~dp0
Release\callonce_c++11.exe > callonce_c++11.log
TYPE callonce_c++11.log
PAUSE
