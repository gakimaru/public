#!/bin/sh
g++ -std=c++11 allocator.cpp -o allocator -Wno-non-template-friend -fcheck-new
#g++ -std=c++11 allocator.cpp -o allocator -Wno-non-template-friend
g++ -std=c++11 -S allocator.cpp -o allocator.asm -Wno-non-template-friend -fcheck-new
