#include <math.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>



// fix the processing for files <- done

void print_help ( void );
void print_settings ( char file_name[], int bits, int frac_bits, int frac_add, int exp_bits, int exp_bias );
void hex_to_float ( unsigned long hex_value, char* file_name, int bits, int frac_bits, int frac_add, int exp_bits, int exp_bias );


int main ( int argc, char* argv[] ) 
{
	// Variables
	int opt;
	int verbose_flag = 0;
	// defaults for c 32-bit type float
	int bits = 32;
	int exp_bits = 8;
	double exp_bias = 127;
	int frac_bits = 23;
	int frac_add = 0;
	double e = 0;
 	char *file_name = NULL;
	FILE *ifile = stdin;
	char input[1024]; 
	unsigned long exp_mask = 0;
	unsigned long frac_mask = 0;
	unsigned long hex_value = 0;
	unsigned long mask = 0;
	double exp_val = 0;
	unsigned long sign_mask = 0;
	unsigned long sign = 0;
	unsigned long fraction = 0; 
	double value = 0;
	double m = 0;
	double fraction_value = 0;

	while ((opt = getopt(argc, argv, "i:dhbme:E:f:F:vH")) != -1)
	{
		switch (opt)
		{
			case 'i':
				file_name = optarg;
				break;
			case 'd':
				//bits = 64;
				exp_bits = 11;
				exp_bias = 1023;
				frac_bits = 52;
				break;
			case 'h':
				//bits = 16;
				exp_bits = 5;
				exp_bias = 15;
				frac_bits = 10;
				break;
			case 'b':
				//bits = 16;
				exp_bits = 8;
				exp_bias = 127;
				frac_bits = 7;
				break;
			case 'm':
				//bits = 8;
				exp_bits = 4;
				exp_bias = -2;
				frac_bits = 3;
				break;
			case 'e':
				//      typecast,       arg,    endp, base
				exp_bits = (int)strtol(optarg, NULL, 10);
				//bits = 1 + exp_bits + frac_bits;
				exp_bias = (1 << (exp_bits - 1)) - 1;
				break;
			case 'E':
				exp_bias = (int)strtol(optarg, NULL, 10);
				break;
			case 'f':
				frac_bits = (int)strtol(optarg, NULL, 10);
				//bits = 1 + exp_bits + frac_bits;
				break;
			case 'F':
				frac_add = (int)strtol(optarg, NULL, 10);
				break;
			case 'v':
				verbose_flag = 1;
				break;
			case 'H':
				print_help();
				return EXIT_SUCCESS;
				break;
			default:
				printf("\nsomething strange has happened\n");
				break;

		}
	}
	bits = 1 + exp_bits + frac_bits;


	if (file_name)
	{
		ifile = fopen(file_name, "r");
		if (!ifile)
		{
			return EXIT_FAILURE;
		}
	}

	if (verbose_flag)
	{
		print_settings(file_name, bits, frac_bits, frac_add, exp_bits, exp_bias); 
	}




	// WHATEVER IS HAPPENING HERE ITS WORKING.................
	while (fgets(input, sizeof(input), ifile) != NULL)
	{
		// get first input only
		sscanf(input, "%lx", &hex_value);
		// build sign mask
		printf("%s", input);
		sign_mask = 0x1L << (frac_bits + exp_bits);


		// build exp mask
		exp_mask = 0x1Lu;
		for(int i = 0; i < exp_bits - 1; i++)
		{
			exp_mask <<= 1L; // build the mask
			exp_mask |= 0x1Lu; // one bit at a time
		}
		exp_mask <<= frac_bits;// shift into place

		// build frac mask
		frac_mask = 0x1Lu;  // Start with 0x1, which is a binary '000...0001'


		for(int i = 0; i < frac_bits - 1; i++)
		{
    			frac_mask <<= 1L;  // Shift left by 1
    			frac_mask |= 0x1Lu;  // Set the least significant bit
		}


		mask = 0x1Lu << (frac_bits + exp_bits);
		
		// extract the representing bits
		sign = (hex_value & sign_mask) ? 1 : 0;
		exp_val = (hex_value & exp_mask) >> frac_bits;
		fraction = hex_value & frac_mask;
		fraction_value = (double)fraction / (1UL << frac_bits);

		// print bits
		printf("\t%d ", (hex_value &mask) ? 1 : 0);
		for (int i = exp_bits; i > 0; i--)
		{
			mask >>= 1;
			printf("%d", (hex_value &mask) ? 1 : 0);
		}
		printf(" ");
		for (int i = frac_bits; i > 0; i--)
		{
			mask >>= 1;
			printf("%d", (hex_value &mask) ? 1 : 0);
		}
		printf("\n");
		// print s ee... ff.....
		printf("\ts ");
		for (int i = exp_bits; i > 0; i--)
		{
			printf("e");
		}
		printf(" ");
		for (int i = frac_bits; i > 0; i--)
		{
			printf("f");
		}
		printf("\n");

		// cases: if denormalized nromalized or special
		if (exp_val == 0)
		{
			// calcualte E, mantissa & value
			e = 1 - exp_bias;
			m = fraction_value + frac_add;

			value = m * pow(2,e);
			if (sign) value*=-1;
			printf("\tdenormalized value\n");
			printf("\tsign:\t\t%s\n", (sign) ? "negative" : "positive");
			printf("\tbias:\t\t%-10.0lf\n", exp_bias);
			printf("\tunbiased exp:\t%-10.0lf\n", exp_val);
			printf("\tE:\t\t%-10.0lf\n", e);
			printf("\tfrac:\t\t%-.20lf\n", fraction_value); 
			printf("\tM:\t\t%-.20lf\n", m);
			printf("\tvalue:\t\t%-.20lf\n", value);
			printf("\tvalue:\t\t%-.20le\n\n", value);

		}
		else if (exp_val == (1UL << exp_bits) - 1)
		{
    			printf("\tspecial value\n");
			// cases: frac all 0 : infinity -- frac non all 0: NaN
			if (fraction_value) printf("\tNaN\n\n");
			else
			{
				if (sign) printf("\tnegative infinity\n\n");
				else if (!sign) printf("\tpositive infinity\n\n");
			}

		}
		else
		{
			// calculate the E, mantissa, and value
			e = exp_val - exp_bias;
			m = 1 + fraction_value + frac_add;

			value = m * pow(2,e);
			if (sign) value*=-1;
    			printf("\tnormalized value\n");
			printf("\tsign:\t\t%s\n", (sign) ? "negative" : "positive");
			printf("\tbias:\t\t%-10.0lf\n", exp_bias);
			printf("\tunbiased exp:\t%-10.0lf\n", exp_val);
			printf("\tE:\t\t%-10.0lf\n", e);
			printf("\tfrac:\t\t%-.20lf\n", fraction_value); 
			printf("\tM:\t\t%-.20lf\n", m);
			printf("\tvalue:\t\t%-.20lf\n", value);
			printf("\tvalue:\t\t%-.20le\n\n", value);
		}

		



	}
	
	if (file_name)
	{
		fclose(ifile);
	}


	return EXIT_SUCCESS;
}


void print_settings ( char* file_name, int bits, int frac_bits, int frac_add, int exp_bits, int exp_bias )
{
	if (!file_name) file_name = "stdin";
	fprintf(stderr, "\tinput file\t: %s\n", file_name);
	fprintf(stderr, "\tnumber of bits\t: %d\n", bits);
	fprintf(stderr, "\tfraction bits\t: %d\n", frac_bits);
	fprintf(stderr, "\tfraction add\t: %d\n", frac_add);
	fprintf(stderr, "\texponent bits\t: %d\n", exp_bits);
	fprintf(stderr, "\texponent bias\t: %d\n", exp_bias);
	fprintf(stderr, "\tverbose \t: yes\n\n");
}

void print_help ( void )
{
	printf("Usage: ./hex-2-float [OPTION ...]\n");
	printf("\t-i <file_name> specify the name of the input file (defaults to stdin)\n");
	printf("\t     Settings default to single prcesision (float, 32-bits, 1-8-23)\n");
        printf("\t-d   use settings for double precision (double, 64-bits, 1-11-52)\n");
        printf("\t-h   use settings for half precision (binary16, 16-bits, 1-5-10)\n");
        printf("\t-b   use settings for half precision (bfloat16, 16-bits, 1-8-7)\n");
        printf("\t-m   use settings for quarter precision (minifloat, 16-bits, 1-4-3 bias -2)\n");
	printf("\t-e # set the number of bits to use for the exponent\n");
	printf("\t-E # set the value used for the exponent bias\n");
	printf("\t-f # set the number of bits to use for the fraction\n");
	printf("\t-F # set the value to add to the fraction (unstored fraction bits)\n");
	printf("\t-v   display the settings (to stderr) before reading input\n");
	printf("\t-H   display this help message and exit\n");
 }
