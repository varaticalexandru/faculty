#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define N 3

void IntSwap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void EroareAlocareDinamica(void)
{
	printf("Eroare la alocarea dinamica de memorie !\n");
	exit(EXIT_FAILURE);
}

int* AlocareVector(int n)
{
	int* a = NULL, i;
	
	if (!(a = (int*)calloc(n, sizeof(int))))
		EroareAlocareDinamica();

	for (i = 1; i <= n; i++)
		a[i] = i;

	return a;
}

void EliberareVector(int* a)
{
	free(a);
}

void Tipareste(int* a, int n)
{
	int i;

	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

void Permutare(int k, int* a)
{	
	int i;

	if (k == 1)
		Tipareste(a, N);
	else {
		Permutare(k - 1, a);
		for (i = 1; i <= k-1; i++)
		{
			IntSwap(&a[i], &a[k]);
			Permutare(k - 1, a);
			IntSwap(&a[i], &a[k]);
		}
	}
}



int main(int argc, char** argv)
{
	int n, *a = NULL;

	printf("Introduceti n: ");
	scanf("%d", &n);

	a = AlocareVector(n+1);

	Permutare(n, a);


	_getch();
	return 0;
}