
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>


// genereza toate permutarile unei multimi de n elemente

void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%c ", a[i]);
    printf("\n");
}

void ErrorAlloc(void)
{
    printf("\nEroare la alocarea dinamica de memorie!\n");
    exit(EXIT_FAILURE);
}

int* ArrayRead(int* n)
{
    int* arr = NULL;
    char buffer[100];

    printf("Introduceti elementele multimii:");
    fgets(buffer, 100, stdin);

    buffer[strcspn(buffer, "\n")] = 0;

    *n = strlen(buffer);

    arr = (int*)calloc(*n, sizeof(int));
    if (!arr)
        ErrorAlloc();


    for (int i = 0; i < *n; i++)
        arr[i] = buffer[i];

    return arr;
}

void IntSwap(int*a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void Permute(int*a, int l, int r, int n, int* k)
{

    // check base case
    if (l == r) {
        (*k)++;
        PrintArray(a, n);
    }
    else {
        for (int j = l; j <= r; j++) {
            IntSwap(a+l, a+j);
            Permute(a, l+1, r, n, k);
            IntSwap(a+l, a+j);
        }
    }
}

int Factorial(int n)
{


    return (!n)
        ? 1
        : n * Factorial(n-1);
}


int main(int argc, char* argv[])
{
    int* arr = NULL;
    int n;              // array size
    int k = 0;      // permutations counter


    arr = ArrayRead(&n);

    printf("\nMultimea introdusa:\n");
    PrintArray(arr, n);

    printf("\nToate permutarile multimii:\n");
    Permute(arr, 0, n-1, n, &k);

    printf("\nNumarul de perumtari: %d\n", k);
    printf("\nNumarul teoretic de permutari: %d! = %d\n", n, Factorial(n));

    _getch();
    return 0;
}
