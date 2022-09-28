#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef long double ld;

// a^n
// a^0 = 1

ld Putere(ld a, unsigned int n)
{
	return (!n) ? 1 : a * Putere(a, n - 1);
}


int main(int argc, char** argv)
{
	ld a, t_total;
	unsigned int n;
	clock_t t1, t2;

	printf("Introduceti a,n : ");
	scanf("%lf %d", &a, &n);

	t1 = clock();

	printf("%.2lf ^ %d = %.2lf\n", a, n, Putere(a, n));

	t2 = clock();

	t_total = (double)(t2 - t1) / (double)CLOCKS_PER_SEC;
	printf("\nTimpul de executie: %.20lf sec\n", t_total);


	_getch();
	return 0;
}