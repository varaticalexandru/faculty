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

int* RealocareVector(int* v, int* n)
{
	(*n)++;

	v = (int*)realloc(v, (*n) * sizeof(int));
	if (v == NULL) {
		printf("Eroare la realocarea dinamica de memorie!\n");
		exit(EXIT_FAILURE);
	}

	return v;
}

void AfisareVector(int* v, int n)
{
	int* i = NULL;

	for (i = v; i < v + n; i++)
		printf("%5d", *i);
	printf("\n\n");
}

void CitireElementVector(int* v, int n)
{
	int n_read;

	printf("v[%d]: ", n-1);
	scanf("%d", &n_read);

	if (!n_read)
		exit(0);
	*(v + n - 1) = n_read;
}

void Sortare(int* v, int n)
{
	int sortat, *i = NULL;

	do
	{
		sortat = 1;
		for (i = v; i < v + n - 1; i++)
			if (*i > *(i + 1)) {
				sortat = 0;
				IntSwap(i, i + 1);
			}

	} while (!sortat);
}


/*
	se citeste pe rand cate o  valoare intreaga si se insereaza intr-un vector, astfel încat vectorul sa fie mereu sortat crescator
	dupa fiecare  inserare se va afisa noul vector. Programul se termina la citirea valorii 0
*/

int main(void)
{
	int n = 0, *v = NULL;

	printf("Introduceti elementele unui vector, pana la citirea valorii '0': \n\n");

	do
	{
		v = RealocareVector(v, &n);
		CitireElementVector(v, n);
		printf("n: %d\n", n);
		Sortare(v, n);
		printf("Vectorul sortat: ");
		AfisareVector(v, n);
	} while (1);

	_getch();
	return 0;
}