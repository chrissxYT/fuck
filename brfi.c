#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int  p = TAPE_START;
char a[TAPE_LEN], b, c;

void die(char *msg, int code)
{
	system("stty cooked");
	puts(msg);
	exit(code);
}

void interpret(FILE *f)
{
	while((c = fgetc(f)) != EOF) {
		switch(c) {
		case '<': p--;        break;
		case '>': p++;        break;
		case '+': a[p]++;     break;
		case '-': a[p]--;     break;
		case '.': putchar(a[p]); fflush(stdout); break;
		case ',': a[p]=getchar();fflush(stdout); break;
		case '[':
			  while(fgetc(f) != ']')
				  fseek(f, -1, SEEK_CUR), interpret(f);
			  break;
		case ']': die("YOU FUCKED IT UP!1", 1);
		}
	}
}

int main(int argc, char **argv)
{
	system("stty raw");
	FILE *z;
	if(argc < 2) die("not enough args", 1);
	z = fopen(argv[1], "r");
	if(!z) die("cant open file", 1);
	interpret(z);
	die("", 0);
}
