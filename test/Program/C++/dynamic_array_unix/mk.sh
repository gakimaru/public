#!/bin/sh
g++ -O3 -std=c++11 dynamic_array.cpp -o dynamic_array 2>&1 | tee mk.log
#g++ -std=c++11 -S dynamic_array.cpp -o dynamic_array.asm -Wno-non-template-friend
