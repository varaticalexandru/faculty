#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int MatrixSize(int len)
{
	return (int)(ceil(sqrt(len)));
}




// plaseaza caracterele din sir intr-o matrice patratica
// pe linii de sus -> jos si dreapta -> stanga

int main(void)
{
	char sir[30];
	int n;

	printf("Introduceti un sir de caractere: ");
	gets(sir);
	n = MatrixSize(strlen(sir));


	_getch();
	return 0;
}