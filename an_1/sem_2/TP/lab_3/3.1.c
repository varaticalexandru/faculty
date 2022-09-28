#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// 3.1
// numele variabilei care se afla la adresa cea mai mica de memorie

int main(void)
{
	double a, b;

	printf("a: ");
	scanf("%lf", &a);

	printf("b: ");
	scanf("%lf", &b);

	if (&a < &b)
		printf("\na se afla la cea mai mica adresa de memorie\n");
	else if (&a > &b)
		printf("\nb se afla la cea mai mica adresa de memorie\n");

	_getch();
	return 0;
}