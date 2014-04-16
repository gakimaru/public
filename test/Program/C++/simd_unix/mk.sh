#!/bin/sh
g++ -O3 -std=c++11 -msse4.1    main.cpp sub.cpp -o simd     2>&1 | tee mk.log
g++ -O3 -std=c++11 -msse4.1 -S main.cpp         -o main.asm
g++ -O3 -std=c++11 -msse4.1 -S          sub.cpp -o sub.asm
