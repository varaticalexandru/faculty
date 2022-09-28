#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// problema 2
// grupa 3.2
// rand 1

#define n 10

int* Transform(int *v)
{
	int* i = NULL, *v1 = NULL, k, aux;

	v1 = (int*)calloc(n*2, sizeof(int));

	k = 0;
	for (i = &v1[0]; i < &v1[0] + n*2; i += 2, k++) {
		*i = v[k];
	}

	for (i = &v1[0] + 1; i < &v1[0] + n * 2; i += 2) {
		*i = *(i-1) * 3;
	}
		
	return v1;
		
}


int main(void)
{
	int v[n] = { 2, -3, 4, 24, -15, 0, 12, 10, -5, 11 };
	int i, *v1 = NULL;

	v1 = Transform(v);

	for (i = 0; i < n * 2; i++)
		printf("%d ", v1[i]);

	_getch();
	return 0;
}