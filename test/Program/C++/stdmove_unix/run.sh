echo '$ ./stdmove > stdmove.log'
echo '---------- -O3 ----------' > stdmove.log
./stdmove_opt.exe >> stdmove.log
echo '---------- -O0 ----------' >> stdmove.log
./stdmove.exe >> stdmove.log
cat stdmove.log
