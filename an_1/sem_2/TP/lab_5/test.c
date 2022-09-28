#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

void AfisareVector(long* a, long n)
{
    long i;

    printf("\n");

    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    printf("\n");
}

void IntSwap(long* a, long* b)
{
    long aux = *a;
    *a = *b;
    *b = aux;
}

void Merge(long* a, long l, long m, long r)
{
    long i, j, k, n1, n2;

    n1 = m - l + 1;
    n2 = r - m;

    // int L[n1], R[n2];   // temp array
    long* L = (long*)calloc(n1, sizeof(long));
    long* R = (long*)calloc(n2, sizeof(long));

    // copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[j + m + 1];

    // merge the arrays back into a[l..r]
    i = 0;  // 1st subarray id
    j = 0;  // 2nd subarray id
    k = l;  // merged subarray id

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

    // copy the remaining elem. of L[], if there are any
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elem. of R[], if there are any
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(long* a, long l, long r)
{
    int m;

    if (l < r) {
        m = l + (r - l) / 2;

        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);

        Merge(a, l, m, r);
    }
}

long Partition(long* a, long low, long high)
{
    long j, i, pivot;

    pivot = a[high];
    i = low - 1;

    for (j = low; j < high; j++)
        if (a[j] <= pivot) {
            i++;
            IntSwap(&a[i], &a[j]);
        }

    IntSwap(&a[i + 1], &a[high]);

    return i + 1;

}

void QuickSort(long* a, long low, long high)
{
    long pi; // partition id

    if (low < high) {
        pi = Partition(a, low, high);

        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

long* RandArr(long n)
{
    long* randArray = (long*)calloc(n, sizeof(long));
    long i;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        randArray[i] = rand() % (2*n);

    return randArray;
}

long SortCheck(long* a, long n)
{
    long i;

    for (i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return 0;

    return 1;
}

int main()
{
    long n = 10000, *arr1 = RandArr(n), *arr2 = RandArr(n);

    //AfisareVector(arr, n);

    long double t = 0.0;
    clock_t begin = clock();
    MergeSort(arr1, 0, n - 1);
    switch (SortCheck(arr1, n))
    {
    case 1:
    {
        printf("Array-ul e sortat !\n");
    }
    break;

    case 0:
    {
        printf("Array-ul nu e sortat !\n");
    }

    default:
        break;
    }
    clock_t end = clock();
    t += ((long double)end - (long double)begin) / CLOCKS_PER_SEC;
    printf("MergeSort: %.10lf\n", t);

    printf("\n");

    t = 0.0;
    begin = clock();
    QuickSort(arr2, 0, n - 1);
    switch (SortCheck(arr2, n))
    {
    case 1:
    {
        printf("Array-ul e sortat !\n");
    }
    break;

    case 0:
    {
        printf("Array-ul nu e sortat !\n");
    }

    default:
        break;
    }
    end = clock();
    t += ((long double)end - (long double)begin) / CLOCKS_PER_SEC;
    printf("QuickSort: %.10lf\n", t);

    //AfisareVector(arr, n);

    _getch();
    return 0;
}
