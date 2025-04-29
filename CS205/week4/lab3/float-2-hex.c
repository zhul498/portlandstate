#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>

// Compile individually using
// make float-2-hex
// Execute using
// ./float-2-hex

void print_help ( void );
void float_to_hex ( void );
void double_to_hex ( void );


int main ( int argc, char* argv[] )
{
	int opt; 
	int no_flags = 1;

	while ((opt = getopt(argc, argv, "fdH")) != -1)
	{
		no_flags = 0;
		switch (opt) 
		{
			case 'f':
				float_to_hex();
				break;
			case 'd':
				double_to_hex();
				break;
			case 'H':
				print_help();
				break;
			default:
				printf("\nsomething strange has happened\n");
				break;

		}

	}


	if (no_flags)
	{
		float_to_hex();
	}

	return EXIT_SUCCESS;

}



void print_help ( void ) 
{
	printf("Usage: ./float-2-hex [OPTION ...]\n");
	printf("\t-f convert the input into floats for hex output (this is the default)\n");
	printf("\t-d convert the input into doubles for hex output\n");
	printf("\t-H display this help message and exit\n");
}


void float_to_hex ( void ) 
{
	char buffer[1024]; 
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		// remove newline
		char* endptr; // Points to the end of a token
		float value = strtof(buffer, &endptr);
	        buffer[strcspn(buffer, "\n")] = 0;
		printf("%-40s\t%.10e\t%.10f\t0x%08x\n", buffer, value, value, *(unsigned int *)&value);
	}

}

void double_to_hex ( void )
{
	char buffer[1024]; 
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		// remove newline
		char* endptr; // Points to the end of a token
		double value = strtod(buffer, &endptr);
	        buffer[strcspn(buffer, "\n")] = 0;
		printf("%-40s\t%.16le\t%.16lf\t0x%016lx\n", buffer, value, value, *(long unsigned int *)&value);
	}

}
