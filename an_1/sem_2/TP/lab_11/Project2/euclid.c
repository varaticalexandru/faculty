#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>

/*
	Daca unul dintre numere este 0, cmmdc al lor este celalalt numar
	Daca nici unul dintre numere nu este 0, cmmdc nu se modifica daca se inlocuieste
	unul dintre numere cu restul impartirii sale cu celalalt
*/

int CmmdcEuclid(int m, int n)
{
	return (!n) ? m : CmmdcEuclid(n, m % n);
}

int main(int argc, char** argv)
{
	int m, n;

	printf("Introduceti m,n: ");
	scanf("%d %d", &m, &n);

	printf("\nCel mai mare divizor comun al %d, %d : %d\n", m, n, CmmdcEuclid(m, n));




	_getch();
	return 0;
}