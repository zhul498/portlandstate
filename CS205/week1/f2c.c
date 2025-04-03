#include <stdio.h>

int main ( void )
{
#ifdef WRONG
	int fahrenheit = 0;
	int celsius = 0;

	printf("Enter temperature in Fahrenheit: ");
	scanf("%d" &fahrenheit);

	celsius = (fahrenheit - 32) * 5 / 9;
	printf("\nCelsius = %d\n", celsius);
#else // WRONG
	float fahrenheit = 0.0;
	float celsius = 0.0;

	printf("Enter temperature in Fahrenheit: ");
	scanf("%f", &fahrenheit);

	celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
	printf("\nCelsius = %.4f\n", celsius);
#endif
	
	return 0;
}
