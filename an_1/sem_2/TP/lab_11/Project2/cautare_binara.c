#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>

int IntSwap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int Partition(int a[], int l, int r)
{
	int j, i = l - 1;
	int pivot = a[r];

	for (j = l; j < r; j++)
		if (a[j] <= pivot) {
			i++;
			IntSwap(&a[i], &a[j]);
		}

	IntSwap(&a[r], &a[i + 1]);
	return (i + 1);
}

void QuickSort(int a[], int l, int r)
{
	int pi;		// partition index

	if (l < r) {
		pi = Partition(a, l, r);

		QuickSort(a, l, pi - 1);
		QuickSort(a, pi + 1, r);
	}
}

void PrintArray(int a[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", a[i]);

	printf("\n");
}

// cautare binara recursiva (vectorul - sortat)
int BinarySearch(int a[], int l, int r, int x)
{
	int mid;

	if (l <= r) {
		mid = l + (r - l) / 2;

		if (a[mid] == x)
			return mid;

		if (x < a[mid])
			return BinarySearch(a, l, mid - 1, x);

		return BinarySearch(a, mid + 1, r, x);
	}

	return -1;
}


int main(int argc, char** argv)
{
	int data[] = {8, 3, 7, 1, 9, 2, 3};
	int n = sizeof(data) / sizeof(data[0]);
	int nr, id;

	printf("Unsorted array: \n");
	PrintArray(data, n);

	printf("Sorted array: \n");
	QuickSort(data, 0, n - 1);

	PrintArray(data, n);

	printf("Introduceti elementul cautat: ");
	scanf("%d", &nr);

	id = BinarySearch(data, 0, n - 1, nr);
	(id == -1)
		? printf("Elementul nu exista in vector !\n")
		: printf("Elementul exista la index-ul : %d\n", id);

	_getch();
	return 0;
}