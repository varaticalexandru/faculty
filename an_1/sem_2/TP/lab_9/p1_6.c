#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int SetOne(int n, int b)
{
	return (n | (1 << b));
}

void BitwiseDisplay(int n)
{
	int i;

	printf("\n");

	for (i = 31; i >= 0; i--)
		((n >> i) & 1) ? printf("1") : printf("0");

	printf("\n");
}

// sa se marcheze cu 1 bitul b al nr. n

int main(int argc, char** argv)
{
	int n, b;

	printf("Introduceti un numar natural: ");
	scanf("%d", &n);

	printf("\nIntroduceti pozitia bitului care sa fie setata pe 1: ");
	scanf("%d", &b);

	printf("\nReprezentarea binara a nr. introdus:\n");
	BitwiseDisplay(n);

	n = SetOne(n, b);

	printf("\nReprezentarea binara a nr. dupa setare:\n");
	BitwiseDisplay(n);

	printf("\n");
	_getch();
	return 0;
}