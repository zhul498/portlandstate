#include <stdio.h>
#include <stdlib.h>

#ifndef M
# define M 10000
#endif // M

#ifndef N
# define N 10000
#endif // N

#define MOD_VALUE 10

int array1[M][N];

void int_array_rows( int a[M][N] );
long sum_array_rows( int a[M][N] );

int main ( void )
{
	long sum = 0;

	int_array_rows(array1);
	sum = sum_array_rows(array1);
	printf("sum = %ld\n", sum);


	return EXIT_SUCCESS;
}

void int_array_rows( int a[M][N] ) {
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < M; ++i) {
			a[i][j] = (i + j) % MOD_VALUE;
		}
	}
}

long sum_array_rows ( int a[M][N] ) {
	long sum = 0;	

	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < M; ++i) {
			sum += a[i][j];
		}
	}
	return sum;
}
