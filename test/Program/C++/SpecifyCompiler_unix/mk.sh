#!/bin/sh
g++ -O3 -std=c++11 specify.cpp -o specify 2>&1 | tee mk.log
#g++ -std=c++11 -S specify.cpp -o specify.asm -Wno-non-template-friend
