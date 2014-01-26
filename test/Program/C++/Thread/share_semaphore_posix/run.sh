echo $ ./share.exe > share.log
./share.exe | tee -a share.log &
sleep 1
echo $ ipcs > share_ipcs.log
ipcs | tee -a share_ipcs.log &
