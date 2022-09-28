#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>


/*
	Varatic Alexandru
	Rand 1
	Grupa 3.2

	fisier "poezie.in" (contine litere, cifre, semne de punctuatie, newline)
	scrieti un program care din poezie in fisierul "text.out" sa elimineze
	semne de punctuatie, spatii (>=2), newline(\n)

	afisam daca citirea s-a facut cu succes
	afisam nr. caractere la citire (intrare)
	afisam nr. caractere scrie in text.out (iesire)
*/


void EroareDeschidereFisier(void)
{
	printf("Eroare la deschidere fisierului !\n");
	exit(EXIT_FAILURE);
}

void SuccesCitireFisier(void)
{
	printf("\nCitire din fisier cu succes !\n");
}

void SuccesScriereFisier(void)
{
	printf("\nScriere in fisier cu succes !\n");
}

int IsSpace(char* c)
{
	return ((*c) == ' ') ? 1 : 0;
}

int IsSign(char* c)
{
	return ((*c) == '.' || (*c) == ',' || (*c) == ':' ||  (*c) == '!' || (*c) == '?') ? 1 : 0;
}


void Poezie(void)
{
	FILE* f1 = NULL;
	FILE* f2 = NULL;
	char* p = NULL, * p2 = NULL, *aux = NULL, buffer[30], c;
	int n_in = 0, n_out = 0;

	if (!(f1 = fopen("poezie.in", "rt")))
		EroareDeschidereFisier();

	if (!(f2 = fopen("text.out", "wt")))
		EroareDeschidereFisier();

	while (!feof(f1)) {
		fgets(buffer, 30, f1);
		buffer[strcspn(buffer, "\r\n")] = 0;	// eliminam newline / setam terminatorul de sir

		printf("%s", buffer);
		printf("  || %d caractere\n", strlen(buffer));
		n_in += strlen(buffer);

		aux = buffer;

		while (*aux) {

			p = aux;
			if (IsSign(p)) {
				for (p2 = p; (*p2); p2++)
					*p2 = *(p2 + 1);
			}

			if (IsSpace(p) && IsSpace(p + 1)) {
				for (p2 = p + 1; (*p2); p2++)
					*p2 = *(p2 + 1);
			}

			aux++;
		}

		fprintf(f2, "%s", buffer);
		n_out += strlen(buffer);
		
		
	}
	
	SuccesCitireFisier();
	SuccesScriereFisier();
	printf("Nr. caractere la citire:  %d\n", n_in);
	printf("Nr. caractere la scriere:  %d\n", n_out);

	fclose(f1);
	fclose(f2);
}

int main(int argc, char** argv)
{

	Poezie();

	printf("\n");
	_getch();
	return 0;
}