#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void EroareDeschidereFisier(void)
{
	printf("Eroare deschidere fisier!\n");
	exit(EXIT_FAILURE);
}

void EroareScriereFisier(void)
{
	printf("Eroare de scriere in fisier !\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
	FILE* f = NULL;
	int n = 0x1177AFCB;

	if (!(f = fopen("1.dat", "wb")))
		EroareDeschidereFisier();

	if(fwrite(&n, sizeof(int), 1, f)<1)
		EroareScriereFisier();

	fclose(f);

	_getch();
	return 0;
}