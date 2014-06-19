#!/bin/sh
g++ -O0 -std=c++11 main.cpp sub.cpp -o stdmove 2>&1 | tee mk.log
g++ -O3 -std=c++11 main.cpp sub.cpp -o stdmove_opt 2>&1 | tee -a mk.log
