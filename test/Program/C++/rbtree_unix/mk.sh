#!/bin/sh
g++ -O3 -std=c++11 rbtree.cpp -o rbtree 2>&1 | tee mk.log
#g++ -std=c++11 -S rbtree.cpp -o rbtree.asm -Wno-non-template-friend
