// Lian Zhu
// Lab 4
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>
// for read
#include <unistd.h>
// for open()
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
// isprint()
#include <ctype.h>
// uint8_t
#include <stdint.h>

void print_help ( void );
void vhex ( int input, char* out_file, bool ascii_flag, int output_mode, const char* format, int format_width );
void verbose ( char* out_file, bool ascii_flag, int output_mode );
// in the case that we want binary output
char* print_binary (char byte, char* output);


int main ( int argc, char* argv[] ) 
{
	//char* in_file = NULL;
	char* out_file = NULL;
	int verbose_flag = 0;	
	bool ascii_flag = true;
	int output_mode = 0;
	int format_width = 0;

	int opt;
	char format[100] = {'\0'};
	while ((opt = getopt(argc, argv, "O:xdobAvh")) != -1)
	{
		switch (opt)
		{
			// output file
			case 'O':
				out_file = optarg;
				break;
			case 'x': // HEX OUTPUT
				output_mode = 1;
				format_width = 3;
				strcpy(format, "%02hhx ");
				break;
			case 'd': // DECIMAL OUTPUT
				output_mode = 2;
				format_width = 4;
				strcpy(format, "%3hhu ");
				break;
			case 'o': // OCTAL OUTPUT
				output_mode = 3;
				format_width = 4;
				strcpy(format, "%03hho ");
				break;
			case 'b': // BINARY OUTPUT
				output_mode = 4;
				format_width = 9;
				strcpy(format, "%8s ");
				break;
			case 'A':
				ascii_flag = false;
				break;
			case 'v':
				++verbose_flag;
				break;
			case 'h':
				print_help();
				return EXIT_SUCCESS;
				break;
			default:
				fprintf(stderr, "snarky message 17\n");
				exit(EXIT_FAILURE);
		}
	}
	// if no optarg, make sure to set format to %02hhx
	if (output_mode == 0)
	{
		strcpy(format, "%02hhx ");
		format_width = 3;
	}
	// Print verbose
	for (int i = 0; i < verbose_flag; ++i)
	{
		verbose(out_file, ascii_flag, output_mode);
	}
	// Now process binary file using reads() and lock in.
	// we need to do it such that we have multiple file arguments...
	if (optind == argc)
	{
		vhex (STDIN_FILENO, out_file, ascii_flag, output_mode, format, format_width);
	}
	else
	{
		for (int i = optind; i < argc; ++i)
		{
			int input = open(argv[i], O_RDONLY);
			if (input == -1)
			{
				perror("input open");
				continue;
			}
			vhex (input, out_file, ascii_flag, output_mode, format, format_width);
			close(input);
		}
	}



	return EXIT_SUCCESS;
}


void verbose (char * out_file, bool ascii_flag, int output_mode)
{
	const char* output = "";
	if (output_mode == 1) output = "hex";
	if (output_mode == 2) output = "decimal";
	if (output_mode == 3) output = "octal";
	if (output_mode == 4) output = "binary";

	fprintf(stderr, "Configuration:\n");
	fprintf(stderr, "\tOutput to: %s\n", out_file ? out_file : "stdout");
	fprintf(stderr, "\tSkip ASCII: %s\n", ascii_flag ? "false" : "true");
	fprintf(stderr, "\tOutput mode: %s\n", output);
	fprintf(stderr, "\n");

}

char* print_binary (char byte, char* output)
{
	// 10000000
	uint8_t mask = 1 << 7; // <- # of bits in a char - 1
	for (int i = 0; i < 8; ++i)
	{
		output[i] = (byte & mask) ? '1' : '0';
		mask >>= 1;
	}
	output[8] = '\0';

	return output;
}

void vhex ( int input, char* out_file, bool ascii_flag, int output_mode, const char* format, int format_width )
{
	char buffer[16];
	unsigned long offset = 0;
	FILE* output_destination = stdout;
	ssize_t bytes_read = 0;


	// output  destination
	if (out_file) 
	{
		static bool first_file = true;
		output_destination = fopen(out_file, first_file ? "w" : "a");
		first_file = false;
		if (!output_destination)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
	}


	// read from stdin and display
	while ((bytes_read = read(input, buffer, sizeof(buffer))) > 0)
	{
		// keep track of difference for last line
		//int difference = 16 - bytes_read;
		
		// print offset
		fprintf(output_destination, "%08lx  ", offset);
		

		// print byte values 
		for (int i = 0; i < 16; ++i)
		{
			if (i < bytes_read)
			{
				// binary mode
				if (output_mode == 4)
				{
					char bin[9];
					fprintf(output_destination, format, print_binary(buffer[i], bin));
				}
				else
				{
					fprintf(output_destination, format, buffer[i]);
				}
			}
			if (i == 7)
				fputc(' ', output_destination);

		}

		if (bytes_read < 16) 
		{
            		int missing_bytes = 16 - bytes_read;
            		int extra_space = bytes_read <= 8 ? 0 : 1;
			
			// add spaces to align 
            		for (int i = 0; i < missing_bytes * format_width + extra_space; i++)
			{
                		fputc(' ', output_destination);
			}
        	}

		if (ascii_flag)
		{
			fprintf(output_destination, " |");
			for (int i = 0; i < bytes_read; ++i)
			{
				if (isprint(buffer[i]))
					fputc(buffer[i], output_destination);
				else
					fputc('.', output_destination);
			}
			fprintf(output_destination, "|");
		}
		
		fputc('\n', output_destination);
		offset += bytes_read;
	}

	if (output_destination != stdout)
	{
		fclose(output_destination);	
	}


}



void print_help ( void ) 
{
	printf("vhex [O:xdobAhv]\n");
	printf(" -O <ofile>: Name of output file.\n");
	printf("             If not specified, stdout is used.\n");
	printf(" -x        : Output is in hex (default).\n");
	printf(" -d        : Output is in decimal.\n");
	printf(" -o        : Output is in octal.\n");
	printf(" -b        : Output is in binary.\n");
	printf(" -A        : Don't show ASCII output.\n");
	printf(" -v        : Enable verbose level (can be given more than once).\n");
	printf(" -h        : Show this amazing help.\n");
}
