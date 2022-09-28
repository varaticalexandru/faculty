#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
    se da o matrice cu n linii si m coloane
    elementele matricii sunt numere naturale

    a) sa se citeasca elem. matricei si sa ne se memoreze intr-o zona alocata dinamic
    b) sa se afiseze matricea data
    c) sa se scrie o functie recursiva care sa determine suma cifrelor unui nr. natural
    d) sa se adauge, dupa ultima coloana, o noua coloana care sa contina suma cifrelor elem. maxim
       de pe fiecare linie a matricei initiale
    e) sa se afiseze noua matrice
*/

int s;

void ErrorAlloc(void)
{
    printf("Eroare la alocarea dinamica de memorie!\n");
    exit(EXIT_FAILURE);

}

int MatrixAlloc(int n, int m)
{
    int** M = NULL;

    M = (int**)calloc(n, sizeof(int*));
    if (!M)
        ErrorAlloc();

    for (int i = 0; i < n; i++) {
        M[i] = (int*)calloc(m, sizeof(int));
        if (!M[i])
            ErrorAlloc();
    }

    return M;
}

void MatrixDisp(int** M, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", M[i][j]);

        printf("\n");
    }
    printf("\n");
}

void MatrixRead(int** M, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
             printf("M[%d][%d]: ", i, j);
             scanf("%d", &M[i][j]);
        }
        printf("\n");
    }
}

int Sum(int n)
{
    int d;

    if (!n)
        return s;
    else
        while (n) {
            d = n % 10;
            s += d;
            n /= 10;
            return Sum(n);
        }
}

int Max(int* arr, int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}


int** MatrixRealloc(int** M, int n, int m)
{

    for (int i = 0; i < n; i++) {

        M[i] = (int*)realloc(M[i], (m+1)*sizeof(int));
        if (!M[i])
            ErrorAlloc();

        s = 0;
        M[i][m] = Sum(Max(M[i], m));
    }

    return M;
}

int main(int argc, char* argv[])
{
    int** M = NULL, n, m;

    printf("Introduceti numarul de linii: ");
    scanf("%d", &n);

    printf("\mIntroduceti numarul de coloane: ");
    scanf("%d", &m);

    M = MatrixAlloc(n, m);

    printf("\nIntroduceti elementele matricii:\n\n");
    MatrixRead(M, n, m);

    printf("\nMatricea introdusa:\n");
    MatrixDisp(M, n, m);

    M = MatrixRealloc(M, n, m);
    m++;

    printf("\nMatricea finala:\n");
    MatrixDisp(M, n, m);


    _getch();
    return 0;
}
