@ECHO OFF
IF EXIST cpu_cache_test.log DEL cpu_cache_test.log
@ECHO ON
@rem Debug\cpu_cache_test.exe >> cpu_cache_test.log
Release\cpu_cache_test.exe 1 C >> cpu_cache_test.log
Release\cpu_cache_test.exe 1 B >> cpu_cache_test.log
Release\cpu_cache_test.exe 1 I >> cpu_cache_test.log
Release\cpu_cache_test.exe 2 C >> cpu_cache_test.log
Release\cpu_cache_test.exe 2 B >> cpu_cache_test.log
Release\cpu_cache_test.exe 2 I >> cpu_cache_test.log
Release\cpu_cache_test.exe 3 C >> cpu_cache_test.log
Release\cpu_cache_test.exe 3 B >> cpu_cache_test.log
Release\cpu_cache_test.exe 3 I >> cpu_cache_test.log
Release_WithDummy\cpu_cache_test.exe 3 C >> cpu_cache_test.log
Release_WithDummy\cpu_cache_test.exe 3 B >> cpu_cache_test.log
Release_WithDummy\cpu_cache_test.exe 3 I >> cpu_cache_test.log
TYPE cpu_cache_test.log
PAUSE
