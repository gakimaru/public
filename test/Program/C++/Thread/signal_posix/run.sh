echo $ ./signal > signal.log
#./signal | tee -a signal.log &
./signal.exe &
sleep 1
kill -USR1 %1
#この処理をLinuxで実行するとプログラムが停止する
#sleep 1
#kill -USR2 %1
sleep 1
kill -TSTP %1
sleep 1
kill -CONT %1
sleep 1
kill -QUIT %1
#この処理をLinuxで実行するとプログラムが停止する
#Cygwinで実行すると同期シグナルハンドラ―スレッドのみが停止する
#sleep 1
#kill -TRAP %1
sleep 1
kill -INT %1
