#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>


// genereza toate permutarile unei multimi de n elemente


void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int* ArrayRead(int* n)
{
    int* arr = NULL;
    char buffer[100];

    printf("Introduceti elementele multimii:");
    fgets(buffer, 100, stdin);

    buffer[strcspn(buffer, "\n")] = 0;

    *n = strlen(buffer);

    for (int i = 0; i < *n; i++)
        arr[i] = buffer[i];

    return arr;
}

int main(int argc, char* argv[])
{
    int* arr = NULL, n;


    arr = ArrayRead(&n);

    PrintArray(arr, n);





    _getch();
    return 0;
}
