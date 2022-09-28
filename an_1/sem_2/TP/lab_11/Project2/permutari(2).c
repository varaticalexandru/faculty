#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// print all permutations (int array)


int n;	// array size
int k;	// counter

void ErrorDynamicAllocation(void)
{
	printf("Eroare la alocarea dinamica de memorie!\n");
	exit(EXIT_FAILURE);
}

int* ReadArray(void)
{
	int* a = NULL, i;

	printf("Introduceti dimensiunea vectorului: ");
	scanf("%d", &n);

	a = (int*)calloc(n, sizeof(int));
	if (!a)
		ErrorDynamicAllocation();

	printf("\nIntroduceti elmentele vectorului:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	return a;
}

void PrintArray(int* a)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

void IntSwap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void Permute(int* a, int l, int r)
{
	int i;

	if (l == r) {
		PrintArray(a);
		k++;
	}
	else {
		for (i = l; i <= r; i++) {
			IntSwap(a + l, a + i);
			Permute(a, l + 1, r);
			IntSwap(a + l, a + i);
		}
	}
}

int main(int argc, char** argv)
{
	int *a = NULL;

	a = ReadArray();

	printf("\nToate permutarile cu elementele vectorului:\n");
	Permute(a, 0, n - 1);

	printf("\nNumarul de permutari: %d\n", k);



	_getch();
	return 0;
}