#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int* AlocareVector(int n)
{
	int* v = NULL;

	v = (int*)calloc(n, sizeof(int));
	if (v == NULL)
	{
		printf("Eroare la alocarea dinamica de memorie!");
		exit(EXIT_FAILURE);
	}

	return v;
}

void Citire(int* v, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("v[%d]: ", i);
		scanf("%d", &v[i]);
	}

	printf("\n");
}

void AfisareVector(int* v, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
}

void EliberareVector(int* v)
{
	free(v);
}

void IntSwap(int* a, int* b)
{
	int aux;

	aux = *b;
	*b = *a;
	*a = aux;
}

void SortareVector(int* v, int n)
{
	int i, ok;

	do
	{
		ok = 1;
		for (i = 0; i < n - 1; i++)
			if (v[i] > v[i + 1])
			{
				IntSwap(&v[i], &v[i + 1]);
				ok = 0;
			}

	} while (!ok);
}

int main(void)
{
	int ok, n, *v = NULL;

	ok = 0;
	do
	{
		printf("Introduceti nr. de elemente a vectorului n (<= 110): ");
		scanf("%d", &n);
		if (n <= 110)
			ok = 1;
	} while (!ok);

	v = AlocareVector(n);
	Citire(v, n);
	puts("Vectorul introdus: ");
	AfisareVector(v, n);
	SortareVector(v, n);
	puts("\n\nVectorul sortat: ");
	AfisareVector(v, n);

	EliberareVector(v);
	_getch();
	return 0;
}