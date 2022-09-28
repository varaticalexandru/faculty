#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// print all permutations with duplicates allowed (string/char array)

int n;	// array size
int k;	// counter

void EroareAlocareDinamica(void)
{
	printf("Eroare la alocarea dinamica de memorie!\n");
	exit(EXIT_FAILURE);
}

char* ReadStr(void)
{
	char buffer[10], *str = NULL;

	printf("Introduceti un sir de caractere : ");
	fgets(buffer, 10, stdin);

	buffer[strlen(buffer) - 1] = 0;

	str = calloc(strlen(buffer) + 1, sizeof(char));
	if (!str)
		EroareAlocareDinamica();

	strcpy(str, buffer);

	return str;
}

void CharSwap(char* a, char* b)
{
	char aux = *a;
	*a = *b;
	*b = aux;
}

void PrintArray(char* a, int n)
{
	int i;

	for (i = 0; i < n; i++)
		putchar(a[i]);
	printf("\n");
}

void Permute(char* a, int l, int r)
{
	int i;
	if (l == r) {
		PrintArray(a, n);
		k++;
	}
		
	else {
		for (i = l; i <= r; i++) {
			CharSwap(a + l, a + i);
			Permute(a, l + 1, r);
			CharSwap(a + l, a + i);
		}
	}
}

int Factorial(int k)
{
	return (!k)
		? 1
		: Factorial(k - 1) * k;
}

void FreeArray(char* str)
{
	free(str);
}

int main(int argc, char** argv)
{
	char* str = NULL;

	str = ReadStr();
	n = strlen(str);

	printf("Toate permutarile sirului introdus:\n\n");
	Permute(str, 0, n - 1);


	printf("\nNumarul de permutari teoretic: %d! = %d\nNumarul de permutari factual: %d\n", n, Factorial(n), k);

	FreeArray(str);

	_getch();
	return 0;
}