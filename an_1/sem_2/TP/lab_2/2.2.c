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

	printf("Matricea introdusa: \n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

int MatriceUnitate(int** M, int m, int n)
{
	int i, j, ok;

	ok = 1;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (i == j)
				if (M[i][j] != 1)
					ok = 0;
			if (i != j)
				if (M[i][j] != 0)
					ok = 0;
		}

	return ok;
		
}

int main(void)
{
	int** M = NULL, n, ok;

	ok = 0;
	do
	{
		printf("Introduceti n (<= 10): ");
		scanf("%d", &n);
		if (n <= 10)
			ok = 1;
	} while (!ok);
	
	printf("\n");

	M = AlocareMatrice(n, n);
	CitireMatrice(M, n, n);
	AfisareMatrice(M, n, n);

	
	switch (MatriceUnitate(M, n, n))
	{
	case 0:
	{
		printf("\nMatricea nu este unitate !\n");
	}
	break;

	case 1:
	{
		printf("\nMatricea este unitate !\n");
	}
	break;

	default:
		break;
	}

	EliberareMatrice(M, n);

	_getch();
	return 0;


}
