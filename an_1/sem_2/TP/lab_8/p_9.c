#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct {
	float x;
	float y;
	float distanta;
} punct;

void EroareDeschidereFisier(void)
{
	printf("Eroare la deschiderea fisierului !\n");
	exit(EXIT_FAILURE);
}

void EroareAlocareDinamica(void)
{
	printf("Eroare la alocarea dinamica !\n");
	exit(EXIT_FAILURE);
}

punct* RealocareStruct(punct* a, int n)
{
	punct* aux = NULL;

	aux = (punct*)realloc(a, (n + 1) * sizeof(punct));
	if (!aux)
		EroareAlocareDinamica();

	return aux;
}

void AfisareStruct(punct* a, int n) 
{
	int i;

	printf("\n");

	for (i = 0; i < n; i++)
		printf("(%.2f  %.2f) : %.2f\n", a[i].x, a[i].y, a[i].distanta);
	
	printf("\n");
}

void EliberareStruct(punct* a)
{
	free(a);
}

float Distanta(float x, float y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

punct* CitireFisier(FILE* f, punct* a, int* n)
{
	while (!feof(f)) {
		a = RealocareStruct(a, *n);
		fscanf(f, "%f %f", &a[*n].x, &a[*n].y);
		a[*n].distanta = Distanta(a[*n].x, a[*n].y);
		(*n)++;
	}

	return a;
}

void StructSwap(punct* a, punct* b)
{
	punct aux = *a;
	*a = *b;
	*b = aux;
}

int Position(punct* a, int low, int high)
{
	int i = low - 1, j;
	punct pivot = a[high];
	
	for (j = low; j < high; j++)
		if (a[j].distanta <= pivot.distanta) {
			i++;
			StructSwap(&a[i], &a[j]);
		}

	StructSwap(&a[i + 1], &a[high]);

	return (i + 1);
}

void QuickSort(punct* a, int low, int high)
{
	int pi;

	if (low < high) {
		pi = Position(a, low, high);
		QuickSort(a, low, pi - 1);
		QuickSort(a, pi + 1, high);
	}
}

int main(int argc, char** argv)
{
	FILE* in = NULL;
	punct* a = NULL;
	int n = 0;

	if ((in = fopen("puncte.txt", "rt")) == NULL)
		EroareDeschidereFisier();

	a = CitireFisier(in, a, &n);
	printf("Perechile de coordonate, si distantele pana la origine aferente:\n");
	AfisareStruct(a, n);

	printf("\nPerechile de coordonate, sortate dupa distanta pana la origine\n");
	QuickSort(a, 0, n - 1);
	AfisareStruct(a, n);

	EliberareStruct(a);
	fclose(in);

	_getch();
	return 0;
}