#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int EvenCheck(int n)
{
	return (n & 1) ? 0 : 1;
}

void BitwiseDisplay(int n)
{
	int i;

	printf("\n");

	for (i = 31; i >= 0; i--)
		((n >> i) & 1) ? printf("1") : printf("0");

	printf("\n");

}

// sa se verifice daca n are val. para sau impara

int main(int argc, char** argv)
{
	int n;

	printf("Introduceti o valoare pentru n: ");
	scanf("%d", &n);

	BitwiseDisplay(n);

	EvenCheck(n) ? printf("\nNumarul %d este par\n", n) : printf("\nNumarul %d nu este par\n", n);

	_getch();
	return 0;
}