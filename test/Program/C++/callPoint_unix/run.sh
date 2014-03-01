#echo $ ./call_point > call_point.log 2> call_point_err.log
#./call_point > call_point.log 2> call_point_err.log
#cat call_point.log
#cat call_point_err.log

echo '$ ./call_point > call_point.log 2>&1'
./call_point > call_point.log 2>&1
cat call_point.log
