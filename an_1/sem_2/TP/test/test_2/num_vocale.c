#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void EroareDeschidereFisier(void)
{
	printf("Eroare deschidere fisier !\n");
	exit(EXIT_FAILURE);
}

void EroareAlocare(void)
{
	printf("Eroare alocare dinamica de memorie !\n");
	exit(EXIT_FAILURE);
}

void EliberareVector(int* v)
{
	free(v);
}

int* AlocareVector(int n)
{
	int* v = NULL;
	v = (int*)calloc(n, sizeof(int));
	if (!v) {
		EroareAlocare();
		exit(EXIT_FAILURE);
	}
		
}

int Vowel(char* c)
{
	if (*c == 'a' || *c == 'A') return 0;
	if (*c == 'e' || *c == 'E') return 1;
	if (*c == 'i' || *c == 'I') return 2;
	if (*c == 'o' || *c == 'O') return 3;
	if (*c == 'u' || *c == 'U') return 4;
	return -1;
}

int* Num_Vocale(char* nume_fisier)
{
	FILE* f = NULL;
	char c, *ptr = NULL;
	int* vocale = NULL;

	vocale = AlocareVector(5);

	if (!(f = fopen(nume_fisier, "rt")))
		EroareDeschidereFisier();

	while (!feof(f)) {
		c = fgetc(f);
		putchar(c);
		vocale[Vowel(&c)]++;
	}

	fclose(f);
	return vocale;
}

void AfisareVocale(int* v)
{
	int i;

	printf("\n\nNumarul de aparitii a fiecarei vocale !\n");
	for (i = 0; i < 5; i++) {
		if (!i) printf("a: %d\n", v[i]);
		if (i == 1) printf("e: %d\n", v[i]);
		if (i == 2) printf("i: %d\n", v[i]);
		if (i == 3) printf("o: %d\n", v[i]);
		if (i == 4) printf("u: %d\n", v[i]);
	}

	printf("\n");
}


// numara de cate ori apare fiecare vocala intr-un fisier text

int main(int argc, char** argv)
{
	int* vocale = NULL;
	char nume_fisier[20];

	printf("Introduceti numele fisierului text: ");
	scanf("%s", nume_fisier);

	printf("\n");

	vocale = Num_Vocale(nume_fisier);
	AfisareVocale(vocale);


	_getch();
	return 0;
}
