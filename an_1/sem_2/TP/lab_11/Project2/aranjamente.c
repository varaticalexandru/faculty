#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <math.h>


// generarea aranjamentelor de n luate cate m, cu repetitie

int m, n;
char caractere[20];
int indici[20];

void Tipareste()
{
	int i;
	for (i = m - 1; i >= 0; i--)
		printf("%c", caractere[indici[i]]);
	printf("\n");
}

void Aranj_r(int k)
{
	int j;
	if (k == -1)
		Tipareste();
	else {
		for (j = 0; j < n; j++) {
			indici[k] = j;
			Aranj_r(k - 1);
		}
	}
}

int main(int argc, char** argv)
{
	int i;
	char buffer[21];

	printf("Caracterele? (unice, toate pe o linie, fara spatii) : ");
	fgets(buffer, 21, stdin);
	buffer[strlen(buffer) - 1] = 0;
	n = strlen(buffer);
	
	for (i = 0; i < n; i++)
		caractere[i] = buffer[i];

	printf("Am citit %d caractere: \n", n);

	for (i = 0; i < n; i++)
		printf("%c", caractere[i]);
	printf("\n");

	do {
		printf("Introduceti m: ");
		scanf("%d", &m);
	} while (m <= 0 || m > n);



	Aranj_r(m - 1);

	_getch();
	return 0;
}