#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef enum {scazuta,medie,mare} grad_pericol;
const char* nume_grad_pericol[] = {"scazuta","medie","mare"};
const char* nume_reteta[] = {"fara reteta","cu reteta"};


typedef struct {
	unsigned char pericol : 2;
	unsigned char reteta : 1;
	unsigned char varsta_min : 5;
} medicament;


int main(int argc, char** argv)
{
	medicament m;
	unsigned aux;

	printf("Grad de periculozitate (0-scazuta, 1-medie, 2-mare) : ");
	scanf("%d", &aux);
	m.pericol = aux;

	printf("Eliberarea pe reteta (0/1) :");
	scanf("%d", &aux);
	m.reteta = aux;

	printf("Varsta minima de administrare (1..18) : ");
	scanf("%d", &aux);
	m.varsta_min = aux;

	printf("\npericulozitate %s\t\t%s\tvarsta minima %d\n", nume_grad_pericol[m.pericol], nume_reteta[m.reteta], m.varsta_min);


	printf("\nsizeof(medicament) : %d byte(s)\n", sizeof(medicament));

	_getch();
	return 0;
}