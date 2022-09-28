#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <math.h>

typedef long double ld;

// a(0) = 1
// a(n+1) = (a(n) + x/a(n))/2
// sqrt(x) = a(n)

ld RadacinaPatrata(ld x, ld an)
{
	return (x < 0) ? 0 : 
		fabs((x/an - an)/2) < 0.0001 ? an : RadacinaPatrata(x, (an + x/an)/2);
}




int main(int argc, char** argv)
{
	ld x;

	printf("Radacina patrata din : ");
	scanf("%lf", &x);

	printf("\nsqrt(%.2lf) = %.6lf\n",x,  RadacinaPatrata(x, 1.0));

	_getch();
	return 0;
}
