#!/bin/sh
g++ -O3 -std=c++11 sort.cpp sub.cpp -o sort 2>&1 | tee mk.log
#g++ -std=c++11 -S sort.cpp -o sort.asm
#g++ -std=c++11 -S sub.cpp -o sub.asm
