#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


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

void EliberareVector(int* v)
{
	free(v);
}

int* _AlocareMatrice(int m, int n)
{
	int* M = NULL;

	M = (int*)calloc(m * n, sizeof(int));

	return M;
}

void _CitireMatrice(int* M, int m, int n)
{
	int* ptr = NULL, i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("M[%d][%d]: ", i, j);
			scanf("%d", &M[i * n + j]); // M + i*n + j
		}
		printf("\n");
	}

}

void _AfisareMatrice(int* M, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", M[i * n + j]);
		printf("\n");
	}

}

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

int* Column(int** M, int m, int c)
{
	int i, * V = NULL;

	V = AlocareVector(m);

	for (i = 0; i < m; i++)
		*(V + i) = *(*(M + i) + c);

	return V;

}

int* SumaL(int** M, int m, int n)
{
	int i, j, *v = NULL;

	v = AlocareVector(m);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			*(v + i) += *(*(M + i) + j);
	
	return v;
}

int* SumaC(int** M, int m, int n)
{
	int i, j, k, s, *v = NULL, *v1 = NULL;

	v = AlocareVector(n);
	v1 = AlocareVector(n);
	
	for (j = 0; j < n; j++)
	{
		s = 0;
		v = Column(M, m, j);
		for (k = 0; k < m; k++)
			*(v1 + j) += *(v + k);
	}
		
	return v1;
}

// 2.11
// sa se memoreze intr-un vector suma elementelor de pe fiecare linie
//												  de pe fiecare coloana

int main(void)
{
	int ok, m, n, **M = NULL, *v = NULL;


	printf("Introduceti dimensiunile pentru o matrice patratica: \n");
	printf("Introduceti n(<=20): \n");

	// validare
	do
	{
		ok = 0;
		printf("n: ");
		scanf("%d", &n);
		if (n <= 20)
			ok = 1;
	} while (!ok);

	printf("\n");

	// alocare
	M = AlocareMatrice(n, n);

	// citire
	CitireMatrice(M, n, n);

	// afisare
	printf("Matricea introdusa: \n");
	AfisareMatrice(M, n, n);

	// suma elementelor de pe fiecare linie
	v = SumaL(M, n, n);
	printf("\nSuma elementelor de pe fiecare linie: \n");
	AfisareVector(v, n);

	// eliberare
	EliberareVector(v);

	// suma elementelor de pe fiecare coloana
	v = SumaC(M, n, n);
	printf("\nSuma elementelor de pe fiecare coloana: \n");
	AfisareVector(v, n);

	// eliberare
	EliberareVector(v);
	EliberareMatrice(M, n);

	return 0;
}