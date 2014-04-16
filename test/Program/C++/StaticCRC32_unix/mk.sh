#!/bin/sh
g++ -std=c++11 -msse4.2    constexpr.cpp constexpr_test.cpp constexpr_performance.cpp -o constexpr
g++ -std=c++11 -msse4.2 -S constexpr.cpp                                              -o constexpr.asm
g++ -std=c++11 -msse4.2 -S               constexpr_test.cpp                           -o constexpr_test.asm
g++ -std=c++11 -msse4.2 -S                                  constexpr_performance.cpp -o constexpr_performance.asm
