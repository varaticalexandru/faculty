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

void EroareAlocare(void)
{
    printf("Eroare la alocarea dinamica de memorie! \n");
    exit(EXIT_FAILURE);
}

int Partition(int* a, int low, int high)
{
    int i, j, pivot;

    pivot = a[high];
    i = low - 1;

    for (j = low; j < high; j++)
        if (a[j] <= pivot) {
            i++;
            IntSwap(&a[i], &a[j]);
        }

    IntSwap(&a[i + 1], &a[high]);

    return (i + 1);
}

void QuickSort(int* a, int low, int high)
{
    int pi; // partition id 

    if (low < high) {
        pi = Partition(a, low, high);

        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

void Merge(int* a, int l, int m, int r)
{
    int n1, n2, i, j, k;
    int* L = NULL, * R = NULL;   // L[], R[] subarrays

    n1 = m - l + 1;
    n2 = r - m;

    L = (int*)calloc(n1, sizeof(int));
    if (!L)
        EroareAlocare();
    R = (int*)calloc(n2, sizeof(int));
    if (!R)
        EroareAlocare();

    // copy data to subarrays L[], R[]
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];

    for (j = 0; j < n2; j++)
        R[j] = a[m + j + 1];


    // merge subarrays L[], R[] back to a[l..r]
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements from L[], R[], if there are any
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

}

void MergeSort(int* a, int l, int r)
{
    int m;  // mean

    if (l < r) {
        m = l + (r - l) / 2;

        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);

        Merge(a, l, m, r);
    }
}


int main()
{
    int n = 7, a[] = { 2,1,0,8,3,4,5 };

    AfisareVector(a, n);
    MergeSort(a, 0, n - 1);
    AfisareVector(a, n);

    return 0;
}
