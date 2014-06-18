#!/bin/sh
g++ -O3 -std=c++11 -msse4.2     cpu_optimization.cpp sub.cpp sub2.cpp -o cpu_optimization 2>&1 | tee mk.log
g++ -O3 -std=c++11 -msse4.2 -S  cpu_optimization.cpp                  -o cpu_optimization.asm
g++ -O3 -std=c++11 -msse4.2 -S                       sub.cpp          -o sub.asm
g++ -O3 -std=c++11 -msse4.2 -S                               sub2.cpp -o sub2.asm
