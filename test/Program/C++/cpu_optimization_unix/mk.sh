#!/bin/sh
g++ -O3 -std=c++11 cpu_optimization.cpp sub.cpp -o cpu_optimization 2>&1 | tee mk.log
g++ -std=c++11 -S  cpu_optimization.cpp         -o cpu_optimization.asm
g++ -std=c++11 -S                       sub.cpp -o sub.asm
