#!/bin/sh
g++ -O3 -msse4.2 -std=c++11    lock_free_algorithm.cpp -o lock_free_algorithm     2>&1 | tee mk.log
g++ -O3 -msse4.2 -std=c++11 -S lock_free_algorithm.cpp -o lock_free_algorithm.asm
