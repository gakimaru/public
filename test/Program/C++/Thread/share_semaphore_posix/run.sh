echo $ ./share > share.log
./share | tee -a share.log &
sleep 1
