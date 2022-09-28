#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

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
            printf("%6d", *(M + i * n + j));
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

    return M;
}

void EliberareMatrice(int** M, int m)
{
    int i;

    for (i = 0; i < m; i++)
        free(M[i]);

    free(M);
}

int IsDigit(int n)
{
    return (n <= 9 && n >= 0) ? 1 : 0;
}

void CitireMatrice(int** M, int m, int n)
{
    int i, j, aux, N, flag, *dig = NULL, k, c;
    char s[3];

    k = 0;
    for (i = 0; i < m; i++)
    {
        dig = AlocareVector(n, sizeof(int));
        c = 1;

        printf("\nIntroduceti prietenii persoanei [%d]: \n", i);
        
        j = 0;
        do
        {
            flag = 0;
            
            while (!k)
            {
                getchar();
                k++;
            }
                
            gets(s);

            N = s[0] - 48;
            if (!IsDigit(N)) {
                break;
            }
            
            // daca se repeta N sau coincide cu J
            if (dig[N] || N == i)
                do
                {
                    printf("Repetitie sau valoare incorecta ! Reintroduceti sau terminati: \n");
                    gets(s);
                    N = s[0] - 48;

                    if (!IsDigit(N)) {
                        flag = 1;
                        break;
                    }

                } while (dig[N] || N == i);

                if (flag) {
                    break;
                }

                M[i] = (int*)realloc(M[i], sizeof(int) * c++);
                M[i][j] = N;

                dig[N] = 1;

        j++;
        } while (j < n);

        EliberareVector(dig);


        printf("\n");
    }
}

void AfisareMatrice(int** M, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        printf("Prietenii persoanei %d : ", i);
        for (j = 0; j < n; j++)
            if (M[i][j] >= 0 && M[i][j] <= 9) printf("%4d", M[i][j]);
        printf("\n");
    }
}

void IntSwap(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// n <= 10 (nr. pers.)
// fiecare pers. - id. printr-un nr. intre 0..n-1
// o pers. poate fi prietena cu oricare alte persoane
// se citesc pt. fiecare pers. prietenii ei pe rand
// sa se afiseze cati prieteni are fiecare pers

int main(void)
{
    int ok, n, **M = NULL, *v = NULL;

    printf("Programul afiseaza cati prieteni are fiecare persoana\n\n");
    printf("Introduceti dimensiunile pentru o matrice patratica: \n");
    printf("Introduceti n(<=10): \n");

    do
    {
        ok = 0;
        printf("n: ");
        scanf("%d", &n);
        if (n <= 10)
            ok = 1;
    } while (!ok);

    printf("\n");

    M = AlocareMatrice(n, n - 1);
    CitireMatrice(M, n, n - 1);


    printf("Prietenii fiecarei persoane: \n\n");
    AfisareMatrice(M, n, n - 1);

	return 0;
}