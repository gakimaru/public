ECHO ---------- Release ---------- > stdmove.log
Release\stdmove.exe >> stdmove.log
ECHO ---------- Debug ---------- >> stdmove.log
Debug\stdmove.exe >> stdmove.log
TYPE stdmove.log
