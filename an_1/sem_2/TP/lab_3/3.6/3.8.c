#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// sa se insereze inainte de fiecare valoare negativul ei
// {7, -5, 4, 3, -9, 2, -8}

int* Inserare(int* v, int n)
{
	int* v_new = NULL, *p1 = NULL, *p2 = NULL;

	v_new = (int*)calloc(2*n, sizeof(int));

	for (p1 = v_new + 1, p2 = v; p1 < v_new + 2 * n; p1 += 2, p2++) {
		*p1 = *p2;
		*(p1 - 1) = -(*p1);
	}

	return v_new;
}

void AfisareVector(int* v, int n)
{
	for (int* p = v; p < v + n; p++)
		printf("%4d ", *p);
	printf("\n");
}


int main(void)
{
	int* v = NULL, * v_new = NULL, n = 7;

	v = (int*)calloc(n, sizeof(int));
	
	*v = 7;
	*(v + 1) = -5;
	*(v + 2) = 4;
	*(v + 3) = 3;
	*(v + 4) = -9;
	*(v + 5) = 2;
	*(v + 6) = -8;

	AfisareVector(v, n);
	v_new = Inserare(v, n);
	AfisareVector(v_new, 2*n);





	return 0;
}