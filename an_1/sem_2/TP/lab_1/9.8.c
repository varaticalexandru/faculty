#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int Ackermann(int m, int n)
{
	if (m == 0) return n + 1;
	if (m > 0 && n == 0) return Ackermann(m - 1, 1);
	if (m > 0 && n > 0) return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main(void)
{
	int a, b;

	printf("Introduceti valori pentru 2 intregi:\n");
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);

	printf("Ackermann(%d, %d): %d\n", a, b, Ackermann(a, b));


	return 0;
}