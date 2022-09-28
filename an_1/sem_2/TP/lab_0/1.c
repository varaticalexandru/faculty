#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
*     1. creati o functie care sa returneze numarul de aparitii a unui caracter ce se regaseste intr-un sir de caractere
*		 caracterul cautat se ia de la tastatura, iar sirul - la alegere
*/


int str_length(char* s, char* c)
{
	int i, n = 0;

	for (i = 0; i < strlen(s); i++)
		if (c == s[i]) {
			n++;
		}
			
	return n;

}

int main(void)
{
	char sir[30], caracter;

	printf("Introduceti un sir de caractere: \n");
	getchar();
	gets(sir);

	printf("\n");

	printf("Introduceti caracterul cautat: \n");
	scanf(" %c", &caracter);

	printf("Numarul de apartii a caracterului '%c': %d !\n", caracter, str_length(sir, caracter));


	return 0;
}