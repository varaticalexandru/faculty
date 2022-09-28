#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

/*
*     2. functie care primeste ca parametru un vector de n numere intregi, si pune in vectorul initial pe primele pozitii toate numerele prime
*		 pe care le gaseste in vector. functia returneaza nr. de numere prime gasite. numerele prime le stabiliti printr-o functie
*
*		citim de la tastatura in main un vector, si vizualizam vectorul transformat
*/


int* citire(int* n)
{
	int i, *v = NULL;

	printf("Introduceti numarul de elemente ale vectorului: ");
	scanf("%d", n);
	printf("\n");

	v = calloc(*n, sizeof(int));

	for (i = 0; i < *n; i++)
	{
		printf("vector[%d]: ", i);
		scanf("%d", &v[i]);
	}

	return v;
}

void afisare(int* v, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	
}

int prime_check(int n)
{
	int i;

	if (n == 0)
		return 0;

	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;

	return 1;
}

void int_swap(int* n1, int* n2)
{
	int aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

int transform(int* v, int n)
{
	int k = 0, j = 0, i;

	for (i = 0; i < n; i++) {
		if (prime_check(v[i])) {
			k++;
			int_swap(&v[i], &v[j]);
			j++;
		}
		
	}

	return k;

}

int main(void)
{
	int* tab = NULL, n, i;
	tab = citire(&n);

	printf("\nVectorul initial: \n");
	afisare(tab, n);

	printf("\n");

	printf("\nVectorul final/transformat: \n");
	transform(tab, n);
	afisare(tab, n);

	printf("\n\nIn vectorul introdus sunt %d numere prime!\n", transform(tab, n));

	free(tab);
	return 0;
}