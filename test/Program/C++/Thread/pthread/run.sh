echo $ ./pthread.exe > pthread.log
./pthread.exe | tee -a pthread.log &
sleep 6
echo $ ./ps -ef > pthread_ps.log
ps -ef | grep pthread >> pthread_ps.log
