#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float** AlocareMatrice(int m, int n)
{
	int i;

	float** M = (float**)calloc(m, sizeof(float*));

	if (M == NULL)
	{
		printf("Eroare la alocarea dinamica de memorie!\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < m; i++)
	{
		M[i] = (float*)calloc(n, sizeof(float));
	}

	return M;
}

void EliberareMatrice(float** M, int m, int n)
{
	int i;

	for (i = 0; i < m; i++)
		free(M[i]);

	free(M);
}

void CitireMatrice(float** M, int m, int n)
{
	int i, j;

	printf("Introduceti elementele matricii: \n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("M[%d][%d]: ", i, j);
			scanf("%f", &M[i][j]);
		}
		printf("\n");
	}
}

void AfisareMatrice(float** M, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%.2f ", M[i][j]);
		}
		printf("\n");
	}
}

// transpusa unei matrici cu elemente nr. reale
float** Transpusa(float** M, int m, int n)
{
	int i, j;
	float** Mtrans = NULL;

	Mtrans = AlocareMatrice(n, m);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			Mtrans[j][i] = M[i][j];
	}
	
	return Mtrans;

	printf("\n");
}

int main(void)
{
	int** M = NULL, **Mtrans = NULL, m, n, ok;

	printf("Introduceti dimensiunile pentru o matrice: \n");
	printf("Introduceti m (<=20) si n(<=30): \n");

	ok = 0;
	do
	{
		printf("m: ");
		scanf("%d", &m);
		printf("n: ");
		scanf("%d", &n);
		if (m <= 20 && n <= 30)
			ok = 1;
	} while (!ok);

	printf("\n");

	M = AlocareMatrice(m, n);
	CitireMatrice(M, m, n);
	printf("\nMatricea introdusa:\n");
	AfisareMatrice(M, m, n);
	printf("\n");
	Mtrans = Transpusa(M, m, n);
	printf("\nMatricea transpusa: \n");
	AfisareMatrice(Mtrans, n, m);

	EliberareMatrice(M, m, n);
	EliberareMatrice(Mtrans, n, m);

	_getch();
	return 0;
}
