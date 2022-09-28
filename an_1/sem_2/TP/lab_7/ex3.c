#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct persoana{
	char nume[30];
	int varsta;
} persoana;

int main(int argc, char** argv)
{
	persoana* ptr = NULL;

	ptr = calloc(50, sizeof(persoana));
	if (!ptr) {
		printf("Eroare la alocarea dinamica de memorie !\n");
		exit(EXIT_FAILURE);
	}

	strcpy(ptr->nume, "Nikita\n");
	ptr->varsta = 30;

	printf("Nume: %s", ptr->nume);
	printf("Varsta: %d", ptr->varsta);

	return 0;
}