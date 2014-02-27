#!/bin/sh
g++ -std=c++11 constexpr.cpp -o constexpr
g++ -std=c++11 -S constexpr.cpp -o constexpr.asm
