#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void IntSwap(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void AfisareVector(int* a, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

// ShakerSort / CocktailSort / Amestecare
void CocktailSort(int* a, int n)
{
    int i, k, s, d;

    s = 1;
    d = n - 1;

    do {
        // s <- d
        for (i = d; i >= s; i--)
            if (a[i - 1] > a[i]) {
                IntSwap(&a[i - 1], &a[i]);
                k = i;  // ultima interschimbare
            }

        s = k + 1;

        // s -> d
        for (i = s; i <= d; i++)
            if (a[i - 1] > a[i]) {
                IntSwap(&a[i - 1], &a[i]);
                k = i;  // ultima interschimbare
            }

        d = k - 1;

    } while (s <= d);
}

// SelectionSort / Selectie
void Selection(int* a, int n)
{
    int i, j, k_min, min;

    for (i = 0; i < n - 1; i++) {
        k_min = i;
        min = a[i];

        for (j = i + 1; j < n; j++)
            if (a[j] < min) {
                k_min = j;
                min = a[j];
            }

        IntSwap(&a[i], &a[k_min]);

    }

}

void SelectionP(int* a, int n)
{
    int i, j, k_min;

    for (i = 0; i < n - 1; i++) {
        k_min = i;

        for (j = i + 1; j < n; j++)
            if (a[j] < a[k_min])
                k_min = j;

        IntSwap(&a[k_min], &a[i]);
    }
}

// InsertionSort / Inseertie
void Insertion(int* a, int n)
{
    int i, j, aux;

    for (i = 1; i < n; i++) {
        j = i - 1;
        aux = a[i];

        // shiftam la dreapta toate elem. < aux,  a[0..i-1]
        while (j >= 0 && a[j] > aux)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = aux;
    }

}

// finds pi (partition index)
int Partition(int a[], int low, int high)
{
    int i, j, pivot;

    pivot = a[high];
    i = (low - 1);    // pointer for greater elem.

    for (j = low; j < high; j++)
        if (a[j] <= pivot) {
            i++;
            IntSwap(&a[j], &a[i]);
        }

    IntSwap(&a[i + 1], &a[high]);

    return (i + 1); // partition point
}

// QuickSort
void QuickSort(int a[], int low, int high)
{
    int pi; // partition position

    if (low < high) {
        pi = Partition(a, low, high);
        
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

int main()
{
    int n = 7, v[7] = { 2, 5, 1, 9 ,7, 0, 3 };

    AfisareVector(v, n);
    QuickSort(v, 0, n-1);
    AfisareVector(v, n);

    _getch();
    return 0;
}
