#pragma once
#include <stdio.h>

char *binfuck_decode(char *ptr, int len);
char *binfuck_encode(char *ptr, int len);
char *asmfuck_decode(char *ptr, int len);
char *asmfuck_encode(char *ptr, int len);
