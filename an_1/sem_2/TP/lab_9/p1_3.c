#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// se citeste val. unui nr. natural n
// sa se determine catul si restul impartirii n la 8
// general (la o putere a lui 2)

// cat : n >> p <=> n >> 3
// rest : n & (2^p - 1) <=> n & 7

void BitwiseDisplay(int n)
{
	int i;

	printf("\n");

	for (i = 31; i >= 0; i--)
		((n >> i) & 1) ? printf("1") : printf("0");

	printf("\n");
}

int pow2(int n)
{
	return (1 << n);
}

float log2(int n)
{
	float ans = 0;
	while (n >>= 1)
		ans++;

	return ans;
}

int cat(int n, int p)
{
	return (n >> (int)log2(p));
}

int rest(int n, int p)
{
	return (n & (p-1));
}

int main(int argc, char** argv)
{
	int n, p;

	printf("Introduceti numarul n: ");
	scanf("%d", &n);

	printf("Introduceti divizorul p (putere a lui 2): ");
	scanf("%d", &p);

	printf("\n%d / %d :\ncat: %d\nrest:%d\n", n, p, cat(n, p), rest(n, p));

	printf("\n");
	_getch();
	return 0;
}