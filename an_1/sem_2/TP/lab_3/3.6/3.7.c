#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void StergeElPare(int* v, int *n)
{
	int* ptr = NULL, *ptr1 = NULL, i;

	for (ptr = v; ptr < v + *n; ptr++)
	{
		if (*ptr % 2 == 0) {
			(*n)--;
			for (ptr1 = ptr; ptr1 < v + *n; ptr1++)
				*ptr1 = *(ptr1 + 1);
			ptr--;
		}
			
	}

}

void AfisareVector(int* v, int n)
{
	for (int* p = v; p < v + n; p++)
		printf("%d ", *p);
	printf("\n");
}

int main(void)
{
	int *v = NULL, i, n = 7;

	v = (int*)calloc(7, sizeof(int));

	*(v + 0) = 5;
	*(v + 1) = 8;
	*(v + 2) = 1;
	*(v + 3) = 4;
	*(v + 4) = 2;
	*(v + 5) = 6;
	*(v + 6) = 9;

	printf("Vectorul initial: ");
	AfisareVector(v, n);

	StergeElPare(v, &n);
	printf("Vectorul dupa stergerea elementelor pare: ");
	AfisareVector(v, n);

	free(v);
	_getch();
	return 0;
}