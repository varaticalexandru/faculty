#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// 1<<b <=> 2^b
// ~(1<<b) are doar bitul b pe 0, restul 1
// n & (1<<b) verifica daca bitul b din nr are val. 1
// n & ~(1<<b) pune pe 0 bitul in rezultat
// n | (1<<b) pune pe 1 bitul b in rezultat
// n ^ (1<<b) schimba val. bitului b in rezultat

void BitwiseDisplay(int n)
{
	int i;

	printf("\n");

	for (i = 31; i >= 0; i--)
		if (n >> i & 1)
			printf("1");
		else
			printf("0");

	printf("\n");
}

int _2powb(int b)
{
	return (1 << b);
}

int BitCheck(int n, int b)
{
	switch (n & (1 << b))
	{
	case 0:
		return 0;
	break;

	default:
		return 1;
	break;
	}
}

int EvenCheck(int n)
{
	switch (n & 1)
	{
	case 0:
		return 1;
	break;

	default:
		return 0;
	break;
	}
}

int SetZero(int n, int b)
{
	n = n & ~(1 << b);
	return n;
}

int SetOne(int n, int b)
{
	n = n | (1 << b);
	return n;
}

int SwitchBit(int n, int b)
{
	n = n ^ (1 << b);
}

int main(int argc, char** argv)
{
	int n, i = 1, b;

	printf("Numarul n: ");
	scanf("%d", &n);
	
	BitwiseDisplay(n);

	printf("Pozitia bitului ce urmeaza a fi switch-uit: ");
	scanf("%d", &b);

	n = SwitchBit(n, b);

	BitwiseDisplay(n);

	_getch();
	return 0;
}