#!/bin/sh
g++ -O3 -std=c++11 ring_buffer.cpp -o ring_buffer 2>&1 | tee mk.log
#g++ -std=c++11 -S ring_buffer.cpp -o ring_buffer.asm -Wno-non-template-friend
