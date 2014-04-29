#!/bin/sh
g++ -O3 -msse4.2 -std=c++11 hash_table.cpp ../StaticCRC32_unix/constexpr.cpp -I../StaticCRC32_unix -o hash_table 2>&1 | tee mk.log
#g++ -msse4.2 -std=c++11 -S hash_table.cpp -o hash_table.asm -Wno-non-template-friend
