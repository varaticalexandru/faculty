#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// genereaza toate combinatiile de k elemente ale unei multimi de n elemente


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

int* ArrRealloc(int* arr, int* nr)
{
    int* aux = NULL;

    aux = (int*)realloc(arr, ((*nr) + 2) * sizeof(int));
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

int* ReadArray(int* n, int* k, int* nr, int* c)
{
    int aux, * arr = NULL, scanned_count;
    char temp;

    arr = (int*)calloc(1, sizeof(int));
    if (!arr)
        ErrorAlloc();

    printf("Introduceti elementele unei multimi (separate de Enter):\n\n");

    while ((scanf("%d", &aux)) != EOF)
    {
        arr = ArrRealloc(arr, nr);
        arr[*nr] = aux;
        (*nr)++;
    }

    printf("\nMultimea introdusa: \n");
    PrintArray(arr, *nr);
    printf("\nn = %d\n", *nr);

    return arr;
}



int main(int argc, char** argv)
{
    int n, k, nr = 0, c = 0, * arr = NULL;

    arr = ReadArray(&n, &k, &nr, &c);






    _getch();
    return 0;
}
