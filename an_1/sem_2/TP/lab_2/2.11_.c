#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

int* AlocareVector(int n)
{
    int* v = NULL;

    v = (int*)calloc(n, sizeof(n));
    if (v == NULL)
    {
        printf("Eroare la alocarea dinamica de memorie !\n");
        exit(EXIT_FAILURE);
    }

    return v;
}

int SumaVector(int* v, int n)
{
    int s = 0, * ptr = NULL;

    for (ptr = v; ptr < v + n; ptr++)
        s += *ptr;

    return s;
}

void CitireVector(int* v, int n)
{
    int* ptr = NULL;

    for (ptr = v; ptr < v + n; ptr++)
        scanf("%d", ptr);
    printf("\n");
}

void AfisareVector(int* v, int n)
{
    int* ptr = NULL;

    for (ptr = v; ptr < v + n; ptr++)
        printf("%d ", *ptr);
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
    if (M == NULL)
    {
        printf("Eroare la alocarea dinamica de memorie! \n");
        exit(EXIT_FAILURE);
    }

    return M;
}

void _CitireMatrice(int* M, int m, int n)
{
    int* ptr = NULL;

    printf("Introduceti elementele matricei: \n");
    for (ptr = M; ptr < M + m * n; ptr++)
        scanf("%d", ptr);

}

void _AfisareMatrice(int* M, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", *(M + i * n + j));
        printf("\n");
    }
}

void IntSwap(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int* SumaL(int* M, int m, int n)
{
    int* s = NULL, * ptr = NULL, k = 0;

    s = AlocareVector(m);

    for (ptr = M; ptr <= M + (m - 1) * n; ptr += n, k++)
        *(s + k) = SumaVector(ptr, n);

    return s;
}

int* SumaC(int* M, int m, int n)
{
    int* ptr1 = NULL, * ptr2 = NULL, * s = NULL, k = 0, sum = 0;

    s = AlocareVector(n);

    for (ptr1 = M; ptr1 < M + n; ptr1++)
    {
        sum = 0;
        for (ptr2 = ptr1; ptr2 <= ptr1 + (m - 1) * n; ptr2 += n)
            sum += *ptr2;
        *(s + k) = sum;
        k++;
    }

    return s;
}


// SumaL : vector suma elementelor de pe fiecare linie
// SumaC : vector cu suma elementelor de pe fiecare coloana

int main()
{
    int n, * M = NULL, * sc = NULL, * sl = NULL;

    printf("Programul afiseaza cate un vector cu suma elementelor de pe fiecare linie/coloana\n\n");
    printf("Introduceti dimensiunea matricei patratice\n");
    printf("n : ");
    scanf("%d", &n);

    M = _AlocareMatrice(n, n);
    printf("\n");
    _CitireMatrice(M, n, n);
    printf("\n");
    sl = SumaL(M, n, n);
    sc = SumaC(M, n, n);

    printf("Matricea introdusa: \n");
    _AfisareMatrice(M, n, n);

    printf("\nSuma elementelor de pe fiecare linie: \n");
    AfisareVector(sl, n);

    printf("\nSuma elementelor de pe fiecare coloana: \n");
    AfisareVector(sc, n);

    EliberareVector(M);
    EliberareVector(sl);
    EliberareVector(sc);

    _getch();
    return 0;
}
