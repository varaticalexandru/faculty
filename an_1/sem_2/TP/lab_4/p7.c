#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void AfisareVector(int* v, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void EliberareVector(int* v)
{
	free(v);
}

int* AddToArr(int *v, int *n, int value)
{
	int* p = NULL;

	p = (int*)realloc(v, (*n + 1) * sizeof(int));
	if (!p) {
		printf("Eroare la alocarea dinamica de memorie !\n");
		exit(EXIT_FAILURE);
	}
	p[*n] = value;
	(*n)++;

	return p;
}

int IntLen(int n)
{
	return (int)floor(log10(n) + 1);
}

int IsDigit(char* c)
{
	return (*c <= 57 && *c >= 48) ? 1 : 0;
}

int* ConstanteZecimale(char* s, int *v, int *n)
{
	char* p = NULL;
	int aux;

	for (p = s; *p; p++) {
		if (IsDigit(p)) {
			sscanf(p, "%d", &aux);
			v = AddToArr(v, n, aux);
			p += IntLen(aux);
		}
	}

	return v;
}

int Suma(int* v, int n)
{
	int i, s = 0;

	for (i = 0; i < n; i++)
		s += v[i];

	return s;
}


// se separa constantele zecimale intregi si se calculeaza suma acestora

int main(void)
{
	char sir[250];
	int* v = NULL, n = 0;

	printf("Introduceti un sir de caractere: \n");
	gets(sir);

	v = ConstanteZecimale(sir, v, &n);
	printf("\nConstantele zecimale intregi din sirul introdus: \n");
	AfisareVector(v, n);

	printf("\nSuma constantelor zecimale din sir: %d\n", Suma(v, n));


	EliberareVector(v);
	_getch();
	return 0;
}