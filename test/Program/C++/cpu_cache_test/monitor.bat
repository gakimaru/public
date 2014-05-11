@ECHO OFF

SET CUR_DIR=%~dp0

CALL "D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"

CALL :MONITOR Case1B cpu_cache_test_1B.exe 1 B
CALL :MONITOR Case1I cpu_cache_test_1I.exe 1 I
CALL :MONITOR Case2B cpu_cache_test_2B.exe 2 B
CALL :MONITOR Case2I cpu_cache_test_2I.exe 2 I
CALL :MONITOR Case3B cpu_cache_test_3B.exe 3 B
CALL :MONITOR Case3I cpu_cache_test_3I.exe 3 I
CALL :MONITOR Case3B_dmy cpu_cache_test_3B_dmy.exe 3 B
CALL :MONITOR Case3I_dmy cpu_cache_test_3I_dmy.exe 3 I

PAUSE
GOTO :EOF
EXIT

:MONITOR
PUSHD %CUR_DIR%%1
ECHO %CD%
IF EXIST VSPerf.vspx DEL VSPerf.vspx
IF EXIST %2.orig IF EXIST %2 DEL %2
IF EXIST %2.orig REN %2.orig %2
rem VSPerfCmd /QueryCounters
rem VSPerfCmd /Start:TRACE /Output:%2.vsp /Counter:DCULinesIn /Counter:DCUModifiedLinesIn /Counter:DCULinesOut /Counter:L2LinesIn /Counter:L2ModifiedLinesIn /Counter:L2LinesOut /Counter:L2ModifiedLinesOut
rem VSPerfCmd /Start:SAMPLE /Output:%2.vsp /Counter:DCULinesIn /Counter:DCUModifiedLinesIn /Counter:DCULinesOut /Counter:L2LinesIn /Counter:L2ModifiedLinesIn /Counter:L2LinesOut /Counter:L2ModifiedLinesOut
rem VSPerfCmd /Launch:%2 /Args:"%3 %4"
rem %2 %3 %4
rem VSPerfCmd /Shutdown
rem VSPerfCmd /Start:SAMPLE /Output:%2.vsp
rem VSPerfCmd /Launch:%CUR_DIR%%1\%2 /Args:"%3 %4" /Counter:DCULinesIn
rem VSPerfCmd /Shutdown
rem VSPerf /launch:%CUR_DIR%%1\%2 /args:"%3 %4"
VSINSTR %2
rem START /REALTIME VSPerfMon /TRACE /OUTPUT:%2.vsp /COUNTER:DCUModifiedLinesIn /COUNTER:InstructionsRetired /COUNTER:NonHaltedCycles /COUNTER:L2Misses /COUNTER:L2References /COUNTER:ITLBMisses /COUNTER:BranchesRetired /COUNTER:MispredictedBranches
START /REALTIME VSPerfMon /TRACE /OUTPUT:%2.vsp /COUNTER:L2Misses
TIMEOUT 2 >NUL
%2 %3 %4 > %2.log
TYPE %2.log
VSPerfCmd /Shutdown
TIMEOUT 2 >NUL
POPD
GOTO :EOF

:RUN_CMD
ECHO %*
%*
GOTO :EOF
