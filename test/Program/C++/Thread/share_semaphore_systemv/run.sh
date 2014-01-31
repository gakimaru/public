echo $ ./share > share.log
./share | tee -a share.log &
echo $ ipcs > share_ipcs.log
ipcs | tee -a share_ipcs.log &
