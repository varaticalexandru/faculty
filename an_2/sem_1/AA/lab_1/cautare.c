#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int bin_count = 0;

int linear_search(int arr[N], int val)
{
    int i;
    for (i=0; i<N; i++)
        if (arr[i] == val)
            return i;

    return -1;
}

int binary_search(int arr[N], int val)
{
    int rc=-1, low=0, high=N-1, mid;

    while(low<=high && rc==-1) {
        mid = (low+high)/2;
        bin_count++;
        if (val < arr[mid])
            high = mid-1;
        else if (val > arr[mid])
            low = mid+1;
        else
            rc = mid;
    }
    return rc;
}

void int_swap(int*a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;

}

void bubble_sort(int arr[N])
{
    int i, ok;

    do {
    ok = 1;
    for (i=0; i<N-1; i++)
        if (arr[i] > arr[i+1]) {
            ok = 0;
            int_swap(&arr[i], &arr[i+1]);
        }
    } while(!ok);
}

void disp_arr(int arr[N])
{
    printf("\n");
    for (int i=0; i<N; i++)
        printf("[%d] ", arr[i]);
    printf("\n");
}

int in(int arr[N], int n)
{
    int i;

    for (i=0; i<N; i++)
        if (arr[i] == n)
            return 1;
    
    return 0;
}

void populate_array(int arr[N])
{
    int i, nr;

    srand(time(NULL));
    for (i=0; i<N; i++) {
        do
        {
            nr = rand()%1000;
        } while (in(arr, nr));
        
        arr[i] = nr;
    }
}

int main()
{
int i, arr[N], val, index;

populate_array(arr);
disp_arr(arr);


printf("\n\nIntrodu valoarea cautata: ");
scanf("%d", &val);

index = linear_search(arr, val);
printf("\nindex = %d", index);
switch (index)
{
    case -1:
        printf("\nAlgoritmul a facut %d pas(i)", N);
    break;

    default:
        printf("\nAlgoritmul a facut %d pas(i)", index);
    break;
}

bubble_sort(arr);
disp_arr(arr);
index = binary_search(arr, val);
printf("\nindex = %d", index);
printf("\nAlgoritmul a facut %d pas(i)", bin_count);


    printf("\n");
    return 0;
}