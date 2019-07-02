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
} af2brf_lookup[8] = {
	{"inc", '+'},
	{"dec", '-'},
	{"tsl", '<'},
	{"tsr", '>'},
	{"sjp", '['},
	{"jpb", ']'},
	{"rac", ','},
	{"wac", '.'},
};

#define lower(c) (c >= 0x41 && c <= 0x5a ? c + 0x20 : c)

char asmfuck2brainfuck(char c1, char c2, char c3)
{
	char s[4] = {lower(c1), lower(c2), lower(c3), '\0'};
	for(int i = 0; i < 8; i++)
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
