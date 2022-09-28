#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


// cititi coord. unui punct de la tastatura (x, y)
// rotiti punctul la 90 de grade, utilizand O(0, 0) ca centru de rotatie
// folositi o matrice de rotatie pe care o veti initializa cu valori constante precalculate

int** AlocareMatrice(int m, int n)
{
	int* p = NULL;

	p = (int**)calloc(m, sizeof(int*));
	if (p == NULL) {
		printf("Eroare la alocarea dinamica de memorie !\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < m; i++)
		p[i] = (int*)calloc(n, sizeof(int));

	return p;
}

void CitireMatrice(int** M, int m, int n)
{
	int i, j;

	printf("\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
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
			printf("%4d", M[i][j]);
		printf("\n");
	}
}

void EliberareMatrice(int** M, int m)
{
	int i;

	for (i = 0; i < m; i++)
		free(M[i]);
	free(M);
}

int** Multiply(int** First, int** Second, int RowsFirst, int ColumnsFirst, int RowsSecond, int ColumnsSecond)
{
	int** M = NULL, i, j, k;
	M = AlocareMatrice(RowsFirst, ColumnsSecond);

	for (i = 0; i < RowsFirst; i++)
		for (j = 0; j < ColumnsSecond; j++)
			for (k = 0; k < RowsSecond; k++)	// RowsSecond = ColumnsFirst
			{
				M[i][j] += First[i][k] * Second[k][j];
			}

	return M;
}

void Rotate(int** M, int** v)
{
	int i;


}



int main(void)
{
	int** M = NULL, **v = NULL, **Mres = NULL;

	M = AlocareMatrice(2, 2);
	v = AlocareMatrice(2, 1);

	M[0][0] = cos(90 * (M_PI /  180));
	M[0][1] = -sin(90 * (M_PI / 180));
	M[1][0] = sin(90 * (M_PI / 180));
	M[1][2] = cos(90 * (M_PI / 180));

	printf("Introduceti coordonatele unui punct (x, y) :\n");
	scanf("%d %d", &v[0][0], &v[1][0]);

	Mres = Multiply(M, v, 2, 2, 2, 1);

	AfisareMatrice(Mres, 2, 1);


	




	return 0;
}