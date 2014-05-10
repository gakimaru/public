#!/bin/sh
g++ -O3 -msse4.2 -std=c++11 cpu_cache_test.cpp -o cpu_cache_test 2>&1 | tee mk.log
#g++ -msse4.2 -std=c++11 -S cpu_cache_test.cpp -o cpu_cache_test.asm -Wno-non-template-friend
