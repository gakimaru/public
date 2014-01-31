echo $ ./callonce > callonce.log
./callonce | tee -a callonce.log &
