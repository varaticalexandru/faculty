#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int** AlocareMatrice(int m, int n)
{
	int **M = NULL, i;

	M = (int**)calloc(m, sizeof(int*));

	if (M == NULL)
	{
		printf("Eroare la alocarea dinamica de memorie !\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < m; i++)
		M[i] = (int*)calloc(n, sizeof(int));

	return M;
}

void CitireMatrice(int** M, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("M[%d][%d]: ", i, j);
			scanf("%d", &M[i][j]);
		}
		printf("\n");
	}

	
}

void AfisareMatrice(int** M, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf(" %d  ", M[i][j]);
		}
		printf("\n");
	}
}

void Eliberare(int** M, int m)
{
	int i;
	
	for (i = 0; i < m; i++)
		free(M[i]);

	free(M);
}

int* AlocareVector(int n)
{
	int* v = NULL;

	v = (int*)calloc(n, sizeof(int));
	if (v == NULL)
	{
		printf("Eroare la alocarea dinamica de memorie!\n");
		exit(EXIT_FAILURE);
	}

	return v;
}

void AfisareVector(int* v, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void Interschimbare(int** M, int m, int n)
{
	int i, j, aux;

	for (i = 0; i < n; i++)
		for (j = i + 1, j != i; j < n; j++)
		{
			aux = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = aux;
		}
}


// 2.10
// se citeste o matrice cu n <= 50 linii si coloane
// interschimbarea el. de deasupra diag. principale cu el. de sub ea
// el. de pe diag. principala raman la fel


int main(void)
{
	int** M = NULL, n, ok;

	printf("Programul interschimba el. de deasupra diag. principale cu el. de sub ea\n");
	
	do
	{
		ok = 0;
		printf("\nIntroduceti dimensiunile matricei M: \n");

		printf("n: ");
		scanf("%d", &n);


		if (n <= 50)
			ok = 1;
	} while (!ok);

	M = AlocareMatrice(n, n);
	CitireMatrice(M, n, n);
	printf("Matricea introdusa: \n");
	AfisareMatrice(M, n, n);

	printf("\n");
	Interschimbare(M, n, n);
	printf("Matricea transformata: \n");
	AfisareMatrice(M, n, n);
	Eliberare(M, n);

	return 0;
}