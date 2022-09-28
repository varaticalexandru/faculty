#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void IntSwap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int* AlocareVector(int n)
{
	int* p = NULL;

	p = (int*)calloc(n, sizeof(int));
	if (p == NULL) {
		printf("Eroare la alocarea dinamica de memorie!\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

void AfisareVector(int* v, int n)
{
	int* i = NULL;

	for (i = v; i < v + n; i++)
		printf("%4d", *i);
	printf("\n");
}

void CitireVector(int* v, int n)
{
	int* i = NULL, *j = NULL, k;

	for (i = v, k = 0; i < v + n; i++, k++) {
		printf("v[%d]: ", k);
		scanf("%d", i);
	}
	printf("\n");
}

int* Sortare(int* v, int n)
{
	int* v_sortat = NULL, sortat, *i = NULL;

	v_sortat = AlocareVector(n, sizeof(int));
	memcpy(v_sortat, v, n * sizeof(int));


	do
	{
		sortat = 1;
		for (i = v_sortat; i < v_sortat + n; i++)
		{
			if ((*i) < *(i + 1)) {
				IntSwap(i, i + 1);
				sortat = 0;
			}

		}
	} while (!sortat);

	return v_sortat;
}

// sortare descrescatoare cu pointeri

int main(void)
{
	int* v = NULL, *v_sortat = NULL, n;

	printf("Introduceti n: ");
	scanf("%d", &n);

	v = AlocareVector(n);

	printf("Introduceti n numere: \n");
	CitireVector(v, n);

	v_sortat = Sortare(v, n);

	printf("Vectorul introdus: \n");
	AfisareVector(v, n);

	printf("Vectorul sortat descrescator: \n");
	AfisareVector(v_sortat, n);

	_getch();
	return 0;
}