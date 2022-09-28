#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int k;  // counter

int Factorial(int n)
{
    return (!n)
        ? 1
        : n * Factorial(n - 1);
}

void CombinationUtil(int arr[], int data[], int start, int end,
    int index, int r)
{
    int i;

    // check if a combination is ready to be printed, 
    if (index == r) {
        k++;
        for (i = 0; i < r; i++)
            printf("%d ", data[i]);
        printf("\n");
    }

    // replace index with all possible elements
    for (i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        CombinationUtil(arr, data, i + 1, end, index + 1, r);
    }
}

// print all combinations of r elements from arr[n]
void PrintCombination(int arr[], int n, int r)
{
    // temp. array to store all combinations one by one
    int* data = (int*)calloc(r, sizeof(int));
    if (!data) {
        printf("Eroare la alocarea dinamica de memmorie!\n");
        exit(EXIT_FAILURE);
    }

    CombinationUtil(arr, data, 0, n - 1, 0, r);
}

int main()
{
    int data[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(data) / sizeof(data[0]);
    int r = 3;
        

    PrintCombination(data, n, r);
    printf("\nNumarul de combinatii: %d\n", k);
    printf("C(%d, %d) = %d!/[%d!*(%d-%d)!] = %d\n",
        n, r, n, r, n, r, Factorial(n) / (Factorial(r) * Factorial(n - r)));



    return 0;
}
