#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int n, i, *v = NULL;
	int* p1 = NULL, *p2 = NULL;
	int k;

	printf("n: ");
	scanf("%d", &n);

	v = (int*)calloc(n, sizeof(int));


	// citire / introducere
	printf("\nIntroduceti un sir de %d numere:\n", n);
	for (i = 0; i < n; i++)
	{
		printf("v[%d]: ", i);
		scanf("%d", &v[i]);
		printf("\n");
	}

	// eliminarea din sir a numerelor pare

	for (p1 = v; p1 < v + n; p1++)
	{
		if ((*p1) % 2 == 0)
		{
			// shift la stanga
			for (p2 = p1; p2 < v + n; p2++)
			{
				*p2 = *(p2 + 1);
			}
		}
	}


	// inserarea dupa fiecare 0 a unui 1
	for (p1 = v; p1 < v + n; p1 += 2)
	{
		if (*p1 == 0)
		{

			for (p2 = v + n - 1; p2 > p1; p2--)
			{
				*p2 = *(p2 - 1);
			}

			*(p1 + 1) = 1;
		}

	}



	// cea mai lunga secventa de elemente egale
	k = 0;
	for (p1 = v; p1 < v + n; p1++)
	{
		if (*p1 == *(p1 + 1))
		{
			k++;
		}

	}

	printf("\n\nNumarul de elemente care se repeta: %d\n", k);

	// afisare
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("v[%d]: %d\n", i, v[i]);
	}

	return 0;
}