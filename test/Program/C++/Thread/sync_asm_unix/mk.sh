#!/bin/sh
g++ -O3 -std=c++11 -msse4.2     sync_asm.cpp -o sync_asm 2>&1 | tee mk.log
g++ -O3 -std=c++11 -msse4.2 -S  sync_asm.cpp -o sync_asm.asm
