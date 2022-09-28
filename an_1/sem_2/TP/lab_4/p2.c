#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// functie care returneaza numarul de caractere c dintr-un sir 
// (c, sir) - parametri

int CharNum(char* s, char c)
{
	int k;

	for (k = 0; *s; s++)
		if (*s == c)
			k++;

	return k;
}

int main(void)
{
	char sir[30], caracter;

	printf("Introduceti un sir: ");
	gets(sir);

	printf("Introduceti un caracter: ");
	caracter = getchar();

	printf("Numarul de aparitii a '%c' in sir: %d\n", caracter, CharNum(sir, caracter));

	_getch();
	return 0;
}