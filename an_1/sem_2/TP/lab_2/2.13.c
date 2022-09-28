#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>]
#include <conio.h>

/*
* Se citeste un numar n<=10 de orase si apoi pentru fiecare 2 orase se citeste distanta directa 
dintre ele. DacA distanta este 0, Inseamna ca intre acele orase nu exista drum direct. Sa se afiseze perechea de 
orase cele mai apropiate intre ele in mod direct.
*/

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

void CitireMatrice(int** M, int m, int n, int *min, int *min_i, int *min_j)
{
	int i, j;
	*min = INT_MAX, * min_i = -1, * min_j = -1;

	for (i = 0; i < m; i++)
	{
		for (j = i + 1; j < n; j++) {
			printf("Introduceti distanta dintre orasele [%d] si [%d]: ", i, j);
			scanf("%d", &M[i][j]);
			if (M[i][j] < *min && M[i][j] != 0) {
				*min = M[i][j];
				*min_i = i;
				*min_j = j;
			}
		}
		printf("\n");
	}

}

void AfisareMatrice(int** M, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = i + 1; j < n; j++)
			printf("Distanta dintre orasele [%d] si [%d]: %d\n", i, j, M[i][j]);
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


int main(void)
{
	int n; // nr. de orase
	int min, min_i, min_j;
	int** M = NULL;

	printf("Introduceti nr. de orase: ");
	scanf("%d", &n);

	M = AlocareMatrice(n, n);
	CitireMatrice(M, n, n, &min, &min_i, &min_j);
	AfisareMatrice(M, n, n);

	printf("\nOrasele [%d] si [%d] sunt cele mai apropiate, distanta : %d\n", min_i, min_j, min);


	_getch();
	return 0;
}