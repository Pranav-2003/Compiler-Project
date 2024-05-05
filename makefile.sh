#!/bin/bash
lex lexer.l
yacc -d parser.y
gcc y.tab.c lex.yy.c
./a.out < quicksort.py > output3.txt
