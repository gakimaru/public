#!/bin/sh
g++ -O3 -std=c++11 singly_linked_list.cpp -o singly_linked_list 2>&1 | tee mk.log
#g++ -std=c++11 -S singly_linked_list.cpp -o singly_linked_list.asm -Wno-non-template-friend
