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

int IntMax(int a, int b)
{
	return (a > b) ? a : b;
}

void MaxIndex(int** M, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			M[i][j] = IntMax(i, j);
}

int main(void)
{
	int** M = NULL, m, n, ok;

	ok = 0;
	do
	{
		printf("Introduceti m si n (<= 10): \n");
		printf("m: ");
		scanf("%d", &m);
		printf("n: ");
		scanf("%d", &n);
		if (m <= 10 && n <= 10)
			ok = 1;
	} while (!ok);

	printf("\n");

	M = AlocareMatrice(m, n);

	MaxIndex(M, m, n);
	printf("\nMatricea %d x %d, unde fiecare element este maximul indecsilor respectivi :\n\n", m, n);
	AfisareMatrice(M, m, n);

	EliberareMatrice(M, m);

	_getch();
	return 0;
}
