#!/bin/sh
g++ -O3 -std=c++11 priority_queue.cpp -o priority_queue 2>&1 | tee mk.log
#g++ -std=c++11 -S priority_queue.cpp -o priority_queue.asm -Wno-non-template-friend
