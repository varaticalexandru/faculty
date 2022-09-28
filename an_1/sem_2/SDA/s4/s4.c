#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// sortare prin insertie
// sortare prin selectie

#define N 9

typedef struct persoana {
	char prenume[20];
} persoana;


void AfisareVector(int* a, int n)
{
	int i;
	
	for (i = 0; i < n; i++)
		printf("% 3d ", a[i]);
	printf("\n");
}

void Insertie(int* a, int n)	// n - 1 parcurgeri
{
	int i, j, aux; // elem. auxiliar pe care il inseram (cautat - a[i])

	for (i = 1; i < n; i++)	// incepem nu de la 0, pt ca e secventa ordonata
	{
		j = i - 1;
		aux = a[i];
		while (a[j] > aux && j >= 0)
		{
			// deplasam elementele spre deapta
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = aux;
	}
}

void InsertieS(char* a, int n)	// n - 1 parcurgeri
{
	int i, j; 
	char aux; // elem. auxiliar pe care il inseram (cautat - a[i])

	for (i = 1; i < n; i++)	// incepem nu de la 0, pt ca e secventa ordonata
	{
		j = i - 1;
		aux = a[i];
		while (a[j] > aux && j >= 0)
		{
			// deplasam elementele spre deapta
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = aux;
	}
}

void Selectie(int* a, int n)	// n - 1 parcurgeri
{
	int i, j, k_min, min;

	for (i = 0; i < n - 1; i++)
	{
		k_min = i;	// id
		min = a[i];  // val

		// cautam minimul
		for (j = i; j < n; j++)
			if (min > a[j])
			{
				k_min = j;
				min = a[j];
			}
		a[k_min] = a[i];
		a[i] = min;
	}
}

void SelectieP(int* a, int n)	// n - 1 parcurgeri
{
	int i, j, k_min, aux;

	for (i = 0; i < n - 1; i++)
	{
		k_min = i;	// i

		// cautam minimul
		for (j = i; j < n; j++)
			if (a[k_min] > a[j])
			{
				k_min = j;
			}
		aux = a[k_min];
		a[k_min] = a[i];
		a[i] = aux;
	}
}

void Interschimbare(int* a, int n)
{
	int i, j, aux;

	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i ; j--)
			if (a[j] < a[j - 1])
			{
				// interschimbare
				aux = a[j];
				a[j] = a[j - 1];
				a[j - 1] = aux;
			}
}

int CitireFisier(persoana *v)
{
	FILE* f = NULL;
	char garbage[10];
	int i = 0;


	if ((f = fopen("file.txt", "rt")) == NULL)
	{
		printf("Fisier inexistent !\n");
		exit(EXIT_FAILURE);
	}
	else
	while (!feof(f))
	{
		fscanf(f, "%s %s", garbage, v[i].prenume);
		i++;
	}

	fclose(f);
	return i;
}

void Afisare(persoana *v, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%10s %10s\n", v[i].prenume);

	printf("\n");
}

int main(void)
{
	int a[N] = { 10, 3, 1, 9, 7, 22, 0, 16, 17 };
	persoana v[20];
	int n, i;

	//Afisare(a, N);
	Insertie(a, N);
	//Selectie(a, N);
	//SelectieP(a, N);
	//Interschimbare(a, N);
	//Afisare(a, N);

	//n = CitireFisier(v);
	Afisare(a, N);
	
	

	printf("\n");
	_getch();
	return 0;
}