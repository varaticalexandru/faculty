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

// suma elem. pare deasupra diagonalei principale
int Suma(int** M, int m, int n)
{
	int i, j, s = 0;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (i < j && (M[i][j] % 2 == 0))
				s += M[i][j];

	return s;
}

int main(void)
{
	int** M = NULL, m, n, ok;

	ok = 0;
	do
	{
		printf("Introduceti n (<= 25): \n");
		printf("n: ");
		scanf("%d", &n);
		if (n <= 25)
			ok = 1;
	} while (!ok);

	printf("\n");

	M = AlocareMatrice(n, n);
	CitireMatrice(M, n, n);
	printf("\nMatricea introdusa:\n\n");
	AfisareMatrice(M, n, n);

	printf("\nSuma elementelor matricii deasupra diagonalei principale: %d\n", Suma(M, n, n));

	EliberareMatrice(M, n);

	_getch();
	return 0;
}
