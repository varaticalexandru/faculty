#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>	
#include <conio.h>

/*
Se citeste un numar n<=10 de produse si pentru fiecare produs vanzarile lui trimestriale pe un an
(4 valori). Se cere sa se afiseze care produse au inregistrat o crestere continua a vanzarilor in decurs de un an.
*/

int CrestereContinua(int* a)
{
	return *a < *(a + 1) && *(a + 1) < *(a + 2) && *(a + 2) < *(a + 3);
}

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
		printf("Introduceti vanzarile trimestriale ale produsului [%d]: ", i);
		scanf("%d %d %d %d", &M[i][0], &M[i][0+1], &M[i][0+2], &M[i][0+3]);
		printf("\n");
	}

}

void AfisareMatrice(int** M, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		printf("Vanzarile trimestriale ale produsului [%d]: ", i);
		for (j = 0; j < n; j++)
			printf("%4d", M[i][j]);
		if (CrestereContinua(&M[i][0]))
			printf("\tAu inregistrat o crestere continua !");
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
	int n, **M;

	printf("Introduceti numarul de produse: ");
	scanf("%d", &n);

	M = AlocareMatrice(n, 4);
	CitireMatrice(M, n, 4);
	AfisareMatrice(M, n, 4);
	EliberareMatrice(M, n);
	
	_getch();
	return 0;
}