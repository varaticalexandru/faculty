#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>

typedef long double ld;

ld fibonacci(ld n)
{
	return (!n || n == 1) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}



int main(int argc, char** argv)
{
	ld n;
	size_t i;

	printf("Introduceti n: ");
	scanf("%lf", &n);

	printf("\nPrimele %.0lf numere din sirul lui Fibonacci : \n", n);
	for (i = 0; i <= n; i++)
		printf("fib[%d]: %.0lf \t\t ratio = %.6lf\n", i, fibonacci(i), fibonacci(i + 1) / fibonacci(i));


	

	_getch();
	return 0;
}