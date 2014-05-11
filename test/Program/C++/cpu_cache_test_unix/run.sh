#!/bin/sh
g++ -O3 -std=c++11 cpu_cache_test.cpp sub.cpp -o cpu_cache_test
./cpu_cache_test 1 C | tee    cpu_cache_test.log
./cpu_cache_test 1 B | tee -a cpu_cache_test.log
./cpu_cache_test 1 I | tee -a cpu_cache_test.log
./cpu_cache_test 2 C | tee -a cpu_cache_test.log
./cpu_cache_test 2 B | tee -a cpu_cache_test.log
./cpu_cache_test 2 I | tee -a cpu_cache_test.log
./cpu_cache_test 3 C | tee -a cpu_cache_test.log
./cpu_cache_test 3 B | tee -a cpu_cache_test.log
./cpu_cache_test 3 I | tee -a cpu_cache_test.log
g++ -O3 -std=c++11 cpu_cache_test.cpp sub.cpp -o cpu_cache_test -DENABLE_DUMMY
./cpu_cache_test 3 C | tee -a cpu_cache_test.log
./cpu_cache_test 3 B | tee -a cpu_cache_test.log
./cpu_cache_test 3 I | tee -a cpu_cache_test.log

#with performance counter
#perf stat -e cache-misses,cache-references ./cpu_cache_test
