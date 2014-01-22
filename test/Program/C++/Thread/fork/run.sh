echo $ ./fork.exe > fork.log
./fork.exe | tee -a fork.log &
sleep 6
echo $ ./ps -ef > fork_ps.log
ps -ef | grep fork >> fork_ps.log
