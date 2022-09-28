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

void EroareAlocare(void)
{
	printf("Eroare la alocarea dinamica de memorie! \n");
	exit(EXIT_FAILURE);
}

int* RealocareVector(int* a, int n)
{
	int* aux = NULL;

	aux = (int*)realloc(a, (n + 1) * sizeof(int));
	if (!aux)
		EroareAlocare();

	return aux;
}

int* CitireVector(int* a, int* n)
{
	int aux, *a1 = NULL;

	a1 = a;

	do
	{
		printf("[%d] : ", *n);
		scanf("%d", &aux);
		if (!aux)
			break;
		a1 = RealocareVector(a1, *n);
		a1[*n] = aux;
		(*n)++;

	} while (aux);
	
	return a1;
}

void AfisareVector(int* a, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

void InversareVector(int* a, int n)
{
	int i;

	for (i = 0; i <= n / 2 - 1; i++)
		IntSwap(&a[i], &a[n - i - 1]);
		
}

void EliberareVector(int* a)
{
	free(a);
}


int main(int argc, char* argv[])
{
	int* a = NULL, n = 0;

	a = CitireVector(a, &n);

	printf("\nVectorul introdus: \n");
	AfisareVector(a, n);

	InversareVector(a, n);
	printf("\nVectorul inversat: \n");
	AfisareVector(a, n);

	EliberareVector(a);

	_getch();
	return 0;
}