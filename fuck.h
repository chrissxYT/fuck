#pragma once
#include <stdio.h>

typedef char brfop;
typedef char bifop;
typedef char *afop;
typedef struct { brfop *p; size_t l; } brfcode;
typedef struct { bifop *p; size_t l; } bifcode;

char  binfuck2brainfuck(char  bif);
bifcode binfuck_decode   (char *ptr, int len);
char *binfuck_encode   (bifcode c);
char  asmfuck2brainfuck(char  c1,  char c2, char c3);
char *asmfuck_decode   (char *ptr, int len);
char *asmfuck_encode   (char *ptr, int len);
