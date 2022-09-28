
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// genereaza toate permutarile unei multimi de n elemente


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
	char buffer[100], *str = NULL;

	printf("\nIntroduceti elmentele vectorului:\n");
	fgets(buffer, 100, stdin);

	buffer[strlen(buffer) - 1] = 0;
	str = (char*)calloc(strlen(buffer), sizeof(char));
	strcpy(str, buffer);

	n = strlen(str);

	a = (int*)calloc(n, sizeof(int));
	if (!a)
		ErrorDynamicAllocation();

	for (i = 0; i < n; i++)
		a[i] = str[i] - 48;

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
		k++;
		PrintArray(a);
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
	int* a = NULL;

	a = ReadArray();

	printf("\nToate permutarile elementelor introduse:\n");
	Permute(a, 0, n - 1);

	printf("\nNumarul de permutari: %d! = %d\n", n, k);

	_getch();
	return 0;
}
