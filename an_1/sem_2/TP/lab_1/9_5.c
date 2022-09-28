#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void CitireSiValidare(int* m, int* n, int* k)
{
	int ok = 0;

	do
	{
		printf("Introduceti m: ");
		scanf("%d", m);

		printf("Introduceti n: ");
		scanf("%d", n);

		printf("Introduceti k: ");
		scanf("%d", k);

		if (*m < 10 && *n < 10 && *n > 3 && *k < 5 && *k > 0 )
			ok = 1;

		printf("\n");

	} while (ok != 1);
}

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

	printf("Matricea introdusa: \n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%.2f ", M[i][j]);
		}
		printf("\n");
	}
}

float* AlocareVector(int n)
{
	float* v = (float*)calloc(n, sizeof(float));
	return v;
}

void CitireVector(float* V, int k)
{
	int i;

	printf("Introduceti valorile vectorului V:\n");
	for (i = 0; i < k; i++)
	{
		printf("V[%d]: ", i);
		scanf("%f", &V[i]);
	}

	printf("\n");
}

void AfisareVector(float* V, int k)
{
	int i;

	for (i = 0; i < k; i++)
		printf("%.2f ", V[i]);
	printf("\n");
}

void EliberareVector(int* V)
{
	free(V);
}

int Egal(float* v1, float* v2, int n)
{
	int i;

	for (i = 0; i < n; i++)
		if (v1[i] != v2[i])
			return 0;

	return 1;
}

// afiseaza pozitiile unde se gaseste un vector in matrice
void EgalM(float** M, float* V, int m, int n, int k)
{
	int i, j, ok = 0;
	printf("\n");

	printf("Pozitiile unde vectorul V se gaseste in matricea M:\n ");
	for (i = 0; i < m; i++)
		for (j = 0; j <= n - k; j++)
		{
			if (Egal(&M[i][j], V, k))
			{
				ok = 1;
				printf("(%d, %d) ", i, j);
			}
				
		}

	if (!ok)
		printf("Nu s-a gasit vectorul V in nici o linie a matricii M\n");		
}


int main(void)
{
	int m, n, i, k;
	float** M;
	float* V;

	CitireSiValidare(&m, &n, &k);
	M = AlocareMatrice(m, n);
	V = AlocareVector(k);

	CitireMatrice(M, m, n);
	AfisareMatrice(M, m, n);

	CitireVector(V, k);

	EgalM(M, V, m, n, k);

	EliberareMatrice(M, m, n);
	EliberareVector(V);

	_getch();
	return 0;
}