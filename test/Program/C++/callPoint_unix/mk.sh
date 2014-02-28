#!/bin/sh
g++ -std=c++11 call_point.cpp -o call_point -Wno-non-template-friend
g++ -std=c++11 -S call_point.cpp -o call_point.asm -Wno-non-template-friend
