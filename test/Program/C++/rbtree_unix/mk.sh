#!/bin/sh
g++ -std=c++11 rbtree.cpp -o rbtree -Wno-non-template-friend 2>&1 | tee mk.log
#g++ -std=c++11 -S rbtree.cpp -o rbtree.asm -Wno-non-template-friend
