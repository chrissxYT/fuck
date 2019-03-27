#include "fuck.h"
#include <stdlib.h>

char binfuck2brainfuck(char bif)
{
	switch(bif)
	{
		case 0:  return '+';
		case 1:  return '-';
		case 2:  return '<';
		case 3:  return '>';
		case 4:  return '[';
		case 5:  return ']';
		case 6:  return ',';
		case 7:  return '.';
		default: return  -1;
	}
}

char *binfuck_decode(char *ptr, int len)
{
	char *out = malloc(len * 2);
	char *c = out;
	char *end = ptr + len;
	while(ptr < end)
		*c++ = *ptr >> 4, *c++ = *ptr++ & 0xf;
	return out;
}

char *binfuck_encode(char *ptr, int len)
{

}

char asmfuck2brainfuck(char c1, char c2, char c3)
{
}

char *asmfuck_decode(char *ptr, int len)
{
	char *out = malloc(len);
	//read until \n, decode
	return out;
}

char *asmfuck_encode(char *ptr, int len)
{

}
