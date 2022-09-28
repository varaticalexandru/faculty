#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>

#define N 5

int a[N + 1];

void IntSwap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void Tipareste(void)
{
	int i;

	for (i = 1; i <= N; i++)
		printf("%d", a[i]);
	printf("\n");
}


void Permutare(int k)
{
	int i;

	if (k == 1)
		Tipareste();
	else {
		Permutare(k - 1);
		for (i = 1; i < k; i++)
		{
			IntSwap(&a[i], &a[k]);
			Permutare(k - 1);
			IntSwap(&a[i], &a[k]);
		}
	}
}



int main(int argc, char** argv)
{
	int i;

	for (i = 1; i <= N; i++)
		a[i] = i;
	Permutare(N);


	_getch();
	return 0;
}