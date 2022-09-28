#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// functie care returneaza maximul dintre 3 valori de tip float
// nu foloseste nici o variabila, cu exceptia parametrilor sai


float maxim(float n1, float n2, float n3)
{
	return (n1 > n2 && n1 > n3) ? n1 : ((n2 > n3 && n2 > n1) ? n2 : n3);
}

int main(void)
{
	float n1, n2, n3;

	printf("Introduceti valori pentru 3 float-uri:\n");
	printf("n1: ");
	scanf("%f", &n1);
	printf("n2: ");
	scanf("%f", &n2);
	printf("n3: ");
	scanf("%f", &n3);

	printf("Valoare maxima: %.2f\n", maxim(n1, n2, n3));


	return 0;
}