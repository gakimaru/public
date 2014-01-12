CD /D %~dp0
SET PATH=D:\MinGW\bin;%PATH%
g++.exe -x c++ -E -P -c dataFormatTest.json -o dataFormatTest.i.json
PAUSE
