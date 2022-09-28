#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>



int* AlocareVector(int n)
{
	int* p = NULL;
	
	p = (int*)calloc(n, sizeof(int));
	if (p == NULL) {
		printf("Eroare la alocarea dinamica de memorie!\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

void AfisareVector(int* v, int n)
{
	int* i = NULL;

	for (i = v; i < v + n; i++)
		printf("%4d", *i);
	printf("\n");
}

int CitireVector(int* v, int n)
{
	int* i, *j, k, *v_dup = NULL;

	v_dup = (int*)calloc(n, sizeof(int));

	for (i = v, k = 0; i < v + n; i++, k++) {
		printf("v[%d]: ", k);
		scanf("%d", i);

		for (j = v; j < i; j++)
			if (*j == *i) {
				v_dup[k] = 1;
			}
	}
	printf("\n");


	return v_dup;
}

// sa se afiseze toate valorile care au cel putin un duplicat

int main(void)
{
	int n, i, *v = NULL, *v_dup = NULL;

	printf("Introduceti n: "); 
	scanf("%d", &n);
	v = AlocareVector(n);

	printf("\nIntroduceti n numere intregi\n");
	v_dup = CitireVector(v, n);

	printf("Vectorul introdus: \n");
	AfisareVector(v, n);

	printf("Vectorul duplicatelor: \n");
	AfisareVector(v_dup, n);

	printf("Elementele care se repeta cel putin 1 data: \n");
	for (i = 0; i < n; i++)
		if (v_dup[i] == 1)
			printf("%d ", v[i]);

	_getch();
	return 0;
}