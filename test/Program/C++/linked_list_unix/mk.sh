#!/bin/sh
g++ -O3 -std=c++11 linked_list.cpp -o linked_list 2>&1 | tee mk.log
#g++ -std=c++11 -S linked_list.cpp -o linked_list.asm -Wno-non-template-friend
