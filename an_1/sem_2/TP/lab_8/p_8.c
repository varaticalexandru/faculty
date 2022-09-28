#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


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


int main(int argc, char** argv)
{
	FILE* in = NULL;
	FILE* out = NULL;
	char buffer[30];

	if (!(in = fopen("in(1).txt", "rt")))
		EroareDeschidereFisier();

	if (!(out = fopen("out(1).txt", "wt")))
		EroareDeschidereFisier();

	while (!feof(in)) {
		fgets(buffer, 30, in);
		buffer[strlen(buffer) - 1] = buffer[strlen(buffer)];
		fprintf(out, "\" %s \"\n", buffer);
	}

	fclose(in);
	fclose(out);

	_getch();
	return 0;
}
