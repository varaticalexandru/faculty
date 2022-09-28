#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct {
	char letter;
	int app_num;
} letter;

void EroareDeschidereFisier(void)
{
	printf("Eroare la deschiderea fisierului !\n");
	exit(EXIT_FAILURE);
}

void EroareAlocareDinamica(void)
{
	printf("Eroare la alocarea dinamica !\n");
	exit(EXIT_FAILURE);
}

letter* Initializare(letter* a)
{
	int i, n;

	a = (letter*)calloc(26, sizeof(letter));
	if (!a)
		EroareAlocareDinamica();

	for (i = 0, n = 65; i < 26; i++, n++) {
		a[i].letter = n;
		a[i].app_num = 0;
	}

	return a;
}

void AfisareStruct(letter* a)
{
	int i;

	printf("\n");
	for (i = 0; i < 26; i++)
		if (a[i].app_num != 0)
			printf("%c : %d\n", a[i].letter, a[i].app_num);
	printf("\n");
}

void EliberareStruct(letter* a)
{
	free(a);
}


int main(int argc, char** argv)
{
	letter* a = NULL;
	char name[10];
	FILE* f = NULL;
	char c = NULL;

	a = Initializare(a);

	printf("Introduceti numele fisierului : ");
	gets(name);

	if ((f = fopen(name, "rt")) == NULL)
		EroareDeschidereFisier(f);

	while (!feof(f)) {
		c = fgetc(f);
		a[toupper(c) - 65].app_num++;
	}

	AfisareStruct(a);

	fclose(f);
	EliberareStruct(a);

	_getch();
	return 0;
}