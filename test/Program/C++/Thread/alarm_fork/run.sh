#!/bin/sh
echo "output alarm.log"
echo "input 'sec message' or 'quit'"
./alarm_fork.exe alarm.log
echo "result: alarm.log"
tail alarm.log
