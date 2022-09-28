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
            printf(" %d  ", M[i][j]);
        }
        printf("\n");
    }
}

int VMult(int* v1, int* v2, int n)
{
    int i, res = 0;

    for (i = 0; i < n; i++)
        res += v1[i] * v2[i];

    return res;
}

int* Column(int** M, int m, int c)
{
    int i, * V = NULL;

    V = AlocareVector(m);

    for (i = 0; i < m; i++)
        V[i] = M[i][c];

    return V;

}

int** MMult(int** M1, int** M2, int m, int n, int x, int y)
{
    int** M = NULL, i, j;

    M = AlocareMatrice(m, y);

    for (i = 0; i < m; i++)
        for (j = 0; j < y; j++)
        {
            //printf("%d\n", VMult(M1[i], Column(M2, x, j), x));
            M[i][j] = VMult(M1[i], Column(M2, x, j), x);
        }

    return M;
}


int main(void)
{
    int** M1 = NULL, ** M2 = NULL, ** M = NULL, m, n, x, y, * V = NULL, ok;

    printf("Programul face inmultirea a 2 matrici M1(m,n) si M2(x,y), rezultand M(m,y)\n");

    do
    {
        ok = 0;
        printf("\nIntroduceti dimensiunile matricei M1: \n");
        printf("m: ");
        scanf("%d", &m);
        printf("n: ");
        scanf("%d", &n);

        printf("\nIntroduceti dimensiunile matricei M2: \n");
        printf("x: ");
        scanf("%d", &x);
        printf("y: ");
        scanf("%d", &y);

        if (n == x)
            ok = 1;
    } while (!ok);

    M1 = AlocareMatrice(m, n);
    printf("\nIntroduceti elementele matricii M1: \n");
    CitireMatrice(M1, m, n);

    printf("\n");

    M2 = AlocareMatrice(x, y);
    printf("Introduceti elementele matricii M2: \n");
    CitireMatrice(M2, x, y);

    printf("\nMatricea M1:\n");
    AfisareMatrice(M2, x, y);

    printf("\nMatricea M1:\n");
    AfisareMatrice(M1, m, n);

    printf("\n");

    M = MMult(M1, M2, m, n, x, y);
    printf("M1(%d,%d) x M2(%d,%d) = M(%d,%d) :\n", m, n, x, y, m, y);
    AfisareMatrice(M, m, y);

    _getch();
    return 0;
}
