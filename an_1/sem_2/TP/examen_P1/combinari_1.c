
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// genereaza toate combinatiile de k elemente ale unei multimi de n elemente

void IntSwap(int*a, int* b)
{
    int aux = *a;
    *a = *b;
    aux = *b;
}

void ErrorRealloc(void)
{
    printf("Eroare la realocarea dinamica de memorie!\n");
    exit(EXIT_FAILURE);
}

void ErrorAlloc(void)
{
    printf("Eroare la alocarea dinamica de memorie!\n");
    exit(EXIT_FAILURE);
}

int* ArrRealloc(int* arr, int* n)
{
    int* aux = NULL;

    aux = (int*)realloc(arr, ((*n) + 2)*sizeof(int));
    if (!aux)
        ErrorRealloc();

    return aux;
}

void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int* ReadArray(int* n, int* k)
{
    int aux, * arr = NULL;

    arr = (int*)calloc(1, sizeof(int));
    if (!arr)
        ErrorAlloc();

    printf("Introduceti elementele unei multimi (separate de Enter):\n\n");

    while ( (scanf("%d", &aux)) != EOF )
    {
        arr = ArrRealloc(arr, n);
        arr[*n] = aux;
        (*n)++;
    }

   printf("\nIntroduceti k: ");
   scanf("%d", k);

    return arr;
}

void CombinationUtil(int a[], int data[], int start, int end, int index, int k, int* c)
{
    // if combination is printable, print it
    if (k == index) {
        (*c)++;
        for (int i = 0; i < k; i++)
            printf("%d ", data[i]);
        printf("\n");
    }

    // replace index with all possible elements from arr
    for (int i = start; i <= end && end-i+1 >= k-index; i++) {
        data[index] = a[i];
        CombinationUtil(a, data, i+1, end, index+1, k, c);
    }
}

void Combinations(int a[], int n, int k, int* c)
{
    int data[k];

    CombinationUtil(a, data, 0, n-1, 0, k, c);

}

int main(int argc, char** argv)
{
    int n = 0, k, c = 0, * arr = NULL;

    arr = ReadArray(&n, &k);


    printf("\nToate (%d, %d) combinarile multimii introduse: \n", n, k);
    Combinations(arr, n, k, &c);

    printf("\nNumarul de combinari: %d\n", c);

    _getch();
    return 0;
}
