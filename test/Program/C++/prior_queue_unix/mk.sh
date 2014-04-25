#!/bin/sh
g++ -O3 -std=c++11 prior_queue.cpp -o prior_queue 2>&1 | tee mk.log
#g++ -std=c++11 -S prior_queue.cpp -o prior_queue.asm -Wno-non-template-friend
