#include "fuck.h"
#include <stdlib.h>
#include <string.h>

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

static const struct {
	char *a;
	char b;
} af2brf_lookup[FUCK_INSTRUCTIONS] = {
	{"inc", '+'},
	{"dec", '-'},
	{"tsl", '<'},
	{"tsr", '>'},
	{"sjp", '['},
	{"jpb", ']'},
	{"rac", ','},
	{"wac", '.'},
};

char asmfuck2brainfuck(char c1, char c2, char c3)
{
	char s[4] = {c1, c2, c3, '\0'};
	for(int i = 0; i < FUCK_INSTRUCTIONS; i++)
		if(!strcmp(s, af2brf_lookup[i].a))
			return af2brf_lookup[i].b;
	return '\0';
}

char *asmfuck_decode(char *ptr, int len)
{
	char *outraw = malloc(len);
	char *ororgn = outraw;
	char *end = ptr + len;
	ptr--;
	while(ptr < end)
	{
		char c[3];
		for(int i = 0; i < 3 && *++ptr != '\n'; i++)
			c[i] = *ptr;
		while(*ptr != '\n') ptr++;
		char ch = asmfuck2brainfuck(c[0], c[1], c[2]);
		if(ch) *outraw++ = ch;
	}
	size_t outlen = outraw - ororgn;
	char *out = malloc(outlen);
	memcpy(out, ororgn, outlen);
	free(ororgn);
	out[outlen] = '\0';
	return out;
}

char *asmfuck_encode(char *ptr, int len)
{

}
