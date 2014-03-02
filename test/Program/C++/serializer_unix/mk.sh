#!/bin/sh
g++ -std=c++11 serializer.cpp -o serializer -Wno-non-template-friend 2>&1 | tee mk.log
#g++ -std=c++11 -S serializer.cpp -o serializer.asm -Wno-non-template-friend
