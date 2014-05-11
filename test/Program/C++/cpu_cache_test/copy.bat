@ECHO OFF

IF NOT EXIST Case1B CALL :RUN_CMD MKDIR Case1B
IF NOT EXIST Case1I CALL :RUN_CMD MKDIR Case1I
IF NOT EXIST Case2B CALL :RUN_CMD MKDIR Case2B
IF NOT EXIST Case2I CALL :RUN_CMD MKDIR Case2I
IF NOT EXIST Case3B CALL :RUN_CMD MKDIR Case3B
IF NOT EXIST Case3I CALL :RUN_CMD MKDIR Case3I
IF NOT EXIST Case3B_dmy CALL :RUN_CMD MKDIR Case3B_dmy
IF NOT EXIST Case3I_dmy CALL :RUN_CMD MKDIR Case3I_dmy

CALL :RUN_CMD COPY Release\cpu_cache_test.exe Case1B\cpu_cache_test_1B.exe
CALL :RUN_CMD COPY Release\cpu_cache_test.exe Case1I\cpu_cache_test_1I.exe
CALL :RUN_CMD COPY Release\cpu_cache_test.exe Case2B\cpu_cache_test_2B.exe
CALL :RUN_CMD COPY Release\cpu_cache_test.exe Case2I\cpu_cache_test_2I.exe
CALL :RUN_CMD COPY Release\cpu_cache_test.exe Case3B\cpu_cache_test_3B.exe
CALL :RUN_CMD COPY Release\cpu_cache_test.exe Case3I\cpu_cache_test_3I.exe
CALL :RUN_CMD COPY Release_WithDummy\cpu_cache_test.exe Case3B_dmy\cpu_cache_test_3B_dmy.exe
CALL :RUN_CMD COPY Release_WithDummy\cpu_cache_test.exe Case3I_dmy\cpu_cache_test_3I_dmy.exe

PAUSE
GOTO :EOF
EXIT

:RUN_CMD
ECHO %*
%*
GOTO :EOF
