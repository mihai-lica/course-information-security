#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_something(char* Buffer)
{
	char MyVar[128];
	strcpy(MyVar, Buffer);
}

void main(int argc, char* argv[])
{
	do_something(argv[1]);
}
