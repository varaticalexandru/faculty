#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int Min(int* v, int n)
{
	int* ptr = NULL, min = *v;

	for (ptr = v; ptr < v + n; ptr++)
	{
		if (*ptr < min)
			min = *ptr;
	}

	return min;
}

int main(void)
{
	int v[] = { 7, -5, 4, 3, -9, 2, -8 };

	printf("Minimul din tablou: %d\n", Min(v, 7));

	_getch();
	return 0;
}