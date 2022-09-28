#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>

/*
	citeste un cuvant (caracter cu caracter)
	intr-un singur char
	il afiseaza atat normal cat si in ordine inversa
*/

void Invers(void)
{
	char c = NULL;
	c = getchar();
	putchar(c);
	(c != ' ') ? Invers() : 1;
	putchar(c);
}

int main(int argc, char** argv)
{
	puts("Introduceti un cuvant, pentru a-l afisa in ordine inversa: \n");
	Invers();

	_getch();
	return 0;
}