#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// copiaza continutul unui fisier sursa intr-un fisier destinatie
// numele fisierelor se citesc din linia de comanda
// citeste cate un bloc de maxim 4096 octeti

void EroareDeschidereFisier(void)
{
	printf("Eroare deschidere fisier!\n");
	exit(EXIT_FAILURE);
}

void EroareCitireFisier(void)
{
	printf("Eroare citire din fisier !\n");
	exit(EXIT_FAILURE);
}

void EroareAlocareDinamica(void)
{
	printf("Eroare alocare dinamica !\n");
	exit(EXIT_FAILURE);
}

void EroareScriereFisier(void)
{
	printf("Eroare scriere in fisier!\n");
	exit(EXIT_FAILURE);
}

void Copy(char* src, char* dest)
{
	FILE* s = NULL, * d = NULL;
	char buff[4096];
	size_t n, m;

	if (!(s = fopen(src, "rb")) || !(d = fopen(dest, "wb")))
		EroareDeschidereFisier();

	do {
		n = fread(buff, 1, 4096, s);
		if (n) m = fwrite(buff, 1, n, d);
		else m = 0;
	} while ((n > 0) && (n == m));

	fclose(s);
	fclose(d);
}


int main(int argc, char** argv)
{
	int i;
	char* src= "src.dat", * dest = "dest.dat";

	Copy(src, dest);


	_getch();
	return 0;
}