#!/bin/sh
#objcopy --readonly-text -I binary -O elf32-i386 -B i386 test.txt test_txt.o
#objcopy --set-section-flags=section=readonly -I binary -O pe-i386 -B i386 test.txt test_txt.o
objcopy -I binary -O elf32-i386 -B i386 test.txt test_txt.o
objdump -t -s -h test_txt.o
g++ -c main.cpp
objdump -t -s -h main.o
g++ main.o test_txt.o -o main
