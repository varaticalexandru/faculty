#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void EroareAlocare(void)
{
	printf("Eroare la alocarea dinamica de memorie !\n");
	exit(EXIT_FAILURE);
}

void IntSwap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int* AlocareVector(int* n)
{
	int* v = NULL;

	printf("Introduceti numarul de numere: ");
	scanf("%d", n);

	v = calloc(*n, sizeof(int));
	if (!v)
		EroareAlocare();

	return v;
}

void CitireVector(int* v, int n)
{
	int i;

	printf("\nIntroduceti numerele : \n\n");
	for (i = 0; i < n; i++)
	{
		printf("[%d] : ", i);
		scanf("%d", &v[i]);
	}

	printf("\n");
}

void AfisareVector(int* v, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);

	printf("\n");
}

void ArrInv(int* v, int n)
{
	int i;

	for (i = 0; i <= n / 2 - 1; i++)
		IntSwap(&v[i], &v[n - 1 - i]);
}

void EliberareVector(int* v)
{
	free(v);
}

typedef enum optiune {
	iesire, citire, afisare, sortare_alf, sortare_num, cautare_alf, cautare_num
} optiune;

int main(int argc, char** argv)
{
	int n, *v = NULL;

	v = AlocareVector(&n);

	CitireVector(v, n);

	printf("Vectorul initial: \n");
	AfisareVector(v, n);

	printf("Vectorul inversat: \n");
	ArrInv(v, n);
	AfisareVector(v, n);

	EliberareVector(v);

	_getch();
	return 0;
}