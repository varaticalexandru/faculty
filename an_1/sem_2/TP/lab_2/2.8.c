#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

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
            printf("%6d", M[i][j]);
        }
        printf("\n");
    }
}

// construieste o matrice patratica cu primele n*n patrate perfecte
int** MPP(int n)
{
    int **M = NULL, i, j, k;

    M = AlocareMatrice(n, n);

    k = 0;
    for (i = 0; i < n; i++, k++)
        for (j = 0; j < n; j++, k++)
            M[i][j] = k * k;

    return M;
}

int main(void)
{
    int **M = NULL, m, n;

    printf("Programul construieste o matrice patratica cu primele n*n patrate perfecte\n");
    printf("\nIntroduceti n: \n");
    scanf("%d", &n);
        
    M = MPP(n);

    printf("\nMatricea M:\n");
    AfisareMatrice(M, n, n);
    EliberareMatrice(M, n);

    _getch();
    return 0;
}
