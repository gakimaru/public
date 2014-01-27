echo $ ./signal > signal.log
#./signal | tee -a signal.log &
./signal &
sleep 1
kill -USR1 %1
sleep 1
kill -USR2 %1
sleep 1
kill -TSTP %1
sleep 1
kill -CONT %1
sleep 1
kill -QUIT %1
sleep 1
kill -INT %1
