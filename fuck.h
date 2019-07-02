#pragma once

char  binfuck2brainfuck(char  bif);
char *binfuck_decode   (char *ptr, int len);
char *binfuck_encode   (char *ptr, int len);
char  asmfuck2brainfuck(char  c1,  char c2, char c3);
char *asmfuck_decode   (char *ptr, int len);
char *asmfuck_encode   (char *ptr, int len);
