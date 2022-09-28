#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void AfisareVector(int* v, int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void Deplasare(int* a, int s, int d)
{
	int i, j, test, x;
	
	i = s;
	j = 2 * i;
	x = a[i]; // x - elem. pe care dorim sa-l inseram
	test = 1;	// acoperim cazurile in care nu facem vreo interschimbare

	while (j <= d && test)
	{
		if (j < d)
			if (a[j] < a[j + 1])
				j++;
		if (x < a[j]) {
			a[i] = a[j]; 
			i = j; 
			j = 2 * i;
		}
			
		else
			test = 0;
	}

	a[i] = x;
}

void HeapSort(int* a, int n)
{
	int s, d, aux;

	s = n + 2 / 1;
	d = n - 1;
	while (s > 1)
	{
		s--;
		Deplasare(a, s, d);
	}
	
	while (d > 0) {
		aux = a[1];
		a[1] = a[d];
		a[d] = aux;
		d--;
		Deplasare(a, 1, d);
	}
}


int main(void)
{
	int n = 11;
	int t[11] = { 0, 6, 3 , 10, 9, 8, 7, 1, 2, 13, 11 };

	AfisareVector(t, n - 1);
	HeapSort(t, 11);

	AfisareVector(t, n - 1);

	return 0;
}