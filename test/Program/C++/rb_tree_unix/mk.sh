#!/bin/sh
g++ -O3 -std=c++11 rb_tree.cpp -o rb_tree 2>&1 | tee mk.log
#g++ -std=c++11 -S rb_tree.cpp -o rb_tree.asm -Wno-non-template-friend
