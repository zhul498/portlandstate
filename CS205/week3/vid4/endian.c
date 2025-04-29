#include <stdio.h>
#include <stdlib.h>


// Compile:
// gcc -Wall -g -o endian endian.c
// Execute:
// ./endian

int main ( void ) 
{
	unsigned short endian = 1;
	char* ecp = (char*) &endian;

	if (ecp[0] == '\0')
	{
		// 0000 0000 0000 0001
		printf("This is a big endian architecture\n");	
	}
	else 
	{
		// 0000 0001 0000 0000
		printf("This is a little endian architecture\n");	
	}

	return EXIT_SUCCESS; // << lives in stdlib.h
}
