#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


int* _AlocareMatrice(int m, int n)
{
	int* M = NULL;

	M = (int*)calloc(m * n, sizeof(int));
	
	return M;
}

void _CitireMatrice(int *M, int m, int n)
{
	int *ptr = NULL;
	
	printf("Introduceti valori pentru matrice: \n");
	for (ptr = M; ptr < M + m * n; ptr++)
		scanf("%d", M);

}

void _AfisareMatrice(int *M, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%6d", *(M + i * n + j));
		printf("\n");
	}
}

void Generare(int *M, int m, int n)
{
	int *ptr = NULL, k;

	k = 1;
	for (ptr = M; ptr < M + m * n; ptr++)
		*ptr = k++;
}

void EliberareVector(int *v)
{
	free(v);
}

// 2.9
// genereaza o matrice cu m linii si n coloane, in care sunt puse toate numerele de la 1, 2, 3, ..., m*n
// cu pointeri

int main(void)
{
	int n, m, ok, *M = NULL, k, *ptr = NULL;

	printf("Introduceti dimensiunile pentru o matrice: \n");
	printf("Introduceti m (<=20) si n(<=10): \n");

	// validare
	do
	{
		ok = 0;
		printf("m: ");
		scanf("%d", &m);
		printf("n: ");
		scanf("%d", &n);
		if (m <= 20 && n <= 10)
			ok = 1;
	} while (!ok);

	printf("\n");

	// alocare
	M = _AlocareMatrice(m, n);

	// generare
	Generare(M, m, n);

	// afisare
	printf("Matricea generata, cu elemente de la 1 .. %d*%d :\n\n", m, n);
	_AfisareMatrice(M, m, n);
	
	// eliberare
	EliberareVector(M);

	_getch();
	return 0;
}