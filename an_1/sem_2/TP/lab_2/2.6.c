#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int** AlocareMatrice(int m, int n)
{
	int i;

	int** M = (int**)calloc(m, sizeof(int*));

	if (M == NULL)
	{
		printf("Eroare la alocarea dinamica de memorie!\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < m; i++)
	{
		M[i] = (int*)calloc(n, sizeof(int));
	}

	return M;
}

void EliberareMatrice(int** M, int m)
{
	int i;

	for (i = 0; i < m; i++)
		free(M[i]);

	free(M);
}

void CitireMatrice(int** M, int m, int n)
{
	int i, j;

	printf("Introduceti elementele matricii: \n");
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
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

// adauga o linie nula dupa linia cu indice 2 (a 3-a linie)
int** Linie(int** M, int m, int n)
{
	int i, j, **M2 = NULL;

	M2 = AlocareMatrice(m + 1, n);

	for (i = 0; i < 3; i++)
		for (j = 0; j < n; j++)
			M2[i][j] = M[i][j];

	for (i = 3, j = 0; j < n; j++)
		M2[i][j] = 0;

	for (i = 4; i < m + 1; i++)
		for (j = 0; j < n; j++)
			M2[i][j] = M[i-1][j];

	EliberareMatrice(M, m);

	return M2;
}

int main(void)
{
	int** M = NULL, ** M2 = NULL, m, n, ok;

	printf("Introduceti dimensiunile pentru o matrice: \n");
	printf("Introduceti m (<=26) si n(<=25): \n");

	ok = 0;
	do
	{
		printf("m: ");
		scanf("%d", &m);
		printf("n: ");
		scanf("%d", &n);
		if (m <= 26 && n <= 25)
			ok = 1;
	} while (!ok);

	printf("\n");

	M = AlocareMatrice(m, n);
	CitireMatrice(M, m, n);
	printf("\nMatricea introdusa:\n");
	AfisareMatrice(M, m, n);
	printf("\n");
	M2 = Linie(M, m, n);
	AfisareMatrice(M2, m+1, n);

	EliberareMatrice(M2, m+1);
	_getch();
	return 0;
}
