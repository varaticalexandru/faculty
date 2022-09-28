#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// cel mai mare divizor comun (recursiv)
int Cmmdc_recursiv(int a, int b)
{
	if (a == b) return a;
	else if (a > b) return Cmmdc(a - b, b);
	else if (b > a) return Cmmdc(a, b - a);
}

// cel mai mare divizor comun
int Cmmdc(int a, int b)
{
	int rest;

	rest = a % b;
	while (rest != 0)
	{
		a = b;
		b = rest;
		rest = a % b;
	}

	return b;
}


int main(void)
{
	int a, b;

	printf("Introduceti valori pentru 2 intregi:\n");
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);

	printf("Cel mai mare divizor comun al %d si %d: %d\n", a, b, Cmmdc(a, b));

	_getch();
	return 0;
}