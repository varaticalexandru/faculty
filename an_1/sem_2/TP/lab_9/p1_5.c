#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void BitwiseDisplay(int n)
{
	int i;

	printf("\n");

	for (i = 31; i >= 0; i--)
		((n >> i) & 1) ? printf("1") : printf("0");

	printf("\n");
}

int PowOf2(int n)
{
	return (!(n & (n - 1)) && n) ? 1 : 0;
}

int NumOf1s(int n)
{
	int i, k = 0;

	for (i = 31; i >= 0; i--)
		if ((n >> i) & 1)
		k++;

	return k;
}


// sa se verifice daca o valoare intreaga este putere a lui 2

int main(int argc, char** argv)
{
	int n;

	printf("Introduceti o valoare intreaga: ");
	scanf("%d", &n);

	printf("\nReprezentarea binara a nr. introdus: \n");
	BitwiseDisplay(n);

	switch (PowOf2(n))
	{
	case 1:
		printf("\nNumarul introdus este putere a lui 2\n");
	break;

	default:
		printf("\nNumarul introdus nu este putere a lui 2\n");
	break;
	}

	printf("\nNr. de biti pe 1: %d\n", NumOf1s(n));

	printf("\n");
	_getch();

	return 0;
}