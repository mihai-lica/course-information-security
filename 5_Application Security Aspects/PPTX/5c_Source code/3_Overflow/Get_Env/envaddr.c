#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[]) 
{   
	char addr[100];
	sprintf(addr, "%s is at %p\n", argv[1], getenv(argv[1]));
}

//int main(int argc, char *argv[]) {
//	char *ptr;
//	if (argc < 3) {
//		printf("Usage: %s <environment var> <target program name>\n", argv[0]); exit(0);
//	}
//
//	ptr = getenv(argv[1]); /* Get env var location. */
//
//	ptr += (strlen(argv[0]) - strlen(argv[2])) * 2; /* Adjust for program name. */ 
//	
//	char addr[100];
//	sprintf(addr, "%s will be at %p\n", argv[1], ptr);
//}
