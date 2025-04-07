// Lian Zhu
// CS205 Lab 1

// Compile:
// gcc -g3 -O0 -Wall -Werror -o to-num to-num.c
// Execute:
// ./to-num

#include <stdio.h>

#define MAX 1025 // max amount of chars


int main ( int argc, char* argv[] ) 
{
	char str1[MAX] = {'\0'};	
	// get input until ctrl + d is pressed
	while (fgets(str1, sizeof(str1), stdin) != NULL)
	{
	
		printf("character output\n");
		for (int i = 0; str1[i] != '\0'; ++i)
		{
			if (str1[i] == '\n') continue;
			printf("%c ", str1[i]);
		}
		printf("\n");

		printf("octal output\n");
		for (int i = 0; str1[i] != '\0'; ++i)
		{
			if (str1[i] == '\n') continue;
			printf("%#o ", str1[i]);
		}	
		printf("\n");

		printf("decimal output\n");
		for (int i = 0; str1[i] != '\0'; ++i)
		{
			if (str1[i] == '\n') continue;
			printf("%.0f ", (float)str1[i]);
		}	
		printf("\n");

		printf("hexadecimal output\n");
		for (int i = 0; str1[i] != '\0'; ++i)
		{
			if (str1[i] == '\n') continue;
			printf("%#x ", str1[i]);
		}	
		printf("\n");
	}

	return 0;
}
