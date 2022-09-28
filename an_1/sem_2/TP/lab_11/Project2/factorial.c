#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef long double ld;


ld factorial(ld n)
{
	return (!n) ? 1 : n * factorial(n - 1);
}


int main(int argc, char** argv)
{
	ld n;

	printf("Introduceti n: ");
	scanf("%lf", &n);

	printf("\n%.0lf ! = %.0lf\n", n, factorial(n));

	_getch();
	return 0;
}