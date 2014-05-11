#!/bin/sh
g++ -O3 -std=c++11 cpu_cache_test.cpp sub.cpp -o cpu_cache_test 2>&1 | tee mk.log
#g++ -std=c++11 -S cpu_cache_test.cpp         -o cpu_cache_test.asm
#g++ -std=c++11 -S                    sub.cpp -o sub.asm
