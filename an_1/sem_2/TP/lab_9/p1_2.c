#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void BitwiseDisplay(int n)
{
	int i;

	for (i = 31; i >= 0; i--)
		((n >> i) & 1) ? printf("1") : printf("0");
}

int _2powb(int b)
{
	return (1 << b);
}

// n <= 15
// sa se afiseze val. 2^n

int main(int argc, char** argv)
{
	int n;

	do
	{
		printf("Introduceti n: ");
		scanf("%d", &n);

	} while (n > 15 || n < 0);

	

	printf("\n2 ^ %d : %d\n", n, _2powb(n));
	BitwiseDisplay(_2powb(n));

	printf("\n");
	_getch();
	return 0;
}