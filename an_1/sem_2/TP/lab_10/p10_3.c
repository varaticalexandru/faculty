#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*
* se citesc m, n de la tastatura
* o matrice a[m][n] de tip intreg
* sa se scrie matricea intr-un fisier binar
* mai intai scriindu-se m,n
* apoi elementele, asa cum sunt ele dispuse in memorie
* 
* sa se citeasca matricea din fisier intr-o variabila b
* sa se afiseze
*/

typedef enum optiune {
	iesire = 0,
	introducere = 1,
	citire = 2,
	scriere = 3,
	afisare = 4
} optiune;

void Menu(void)
{
	printf("\n----------------------- Meniu Interactiv -----------------------\n"
			"0. Iesire\n"
			"1. Introducere matrice de la tastatura\n"
			"2. Citire matrice din fisier\n"
			"3. Scriere matrice in fisier\n"
			"4. Afisare matrice curenta\n"
			"-----------------------------------------------------------------\n"
			"Optiunea dvs: "
	);
}

void EroareMatriceVida(void)
{
	printf("Eroare ! Matrice vida/nedefinita !\n");
}

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

int* AlocareMatrice(int* m, int* n)
{
	int* a = NULL;

	printf("m: "); scanf("%d", m);
	printf("n: "); scanf("%d", n);
	printf("\n");

	a = (int*)calloc((*m) * (*n), sizeof(int));
	if (!a)
		EroareAlocareDinamica();

	return a;
}

void AfisareMatrice(int* a, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf(" %d ", a[i * n + j]);
		printf("\n");
	}
	printf("\n");
}

void CitireMatrice(int* a, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("a[%d][%d]: ", i, j);
			scanf("%d", &a[i * n + j]);
		}
		printf("\n");
	}
		
	printf("\n");
}

void EliberareMatrice(int* a)
{
	free(a);
}

void ScriereMatriceF(int* a, int m, int n)
{
	FILE* f = NULL;
	int* ptr = NULL, i;

	if (!(f = fopen("matrice.dat", "wb")))
		EroareDeschidereFisier();

	if ((fwrite(&m, sizeof(int), 1, f)) != 1)
		EroareScriereFisier();
	
	if ((fwrite(&n, sizeof(int), 1, f)) != 1)
		EroareScriereFisier();

	if ((fwrite(a, sizeof(int), m * n, f)) < m * n)
		EroareScriereFisier();

	fclose(f);

	fprintf(stdout, "\nScriere cu succes in fisier!\n");
}

int* CitireMatriceF(int* a, int* m, int* n)
{
	FILE* f = NULL;

	if (!(f = fopen("matrice.dat", "rb")))
		// nu exista fisierul
		return;

	// citire m
	if ((fread(m, sizeof(int), 1, f)) != 1)
		EroareCitireFisier();

	// citire n
	if ((fread(n, sizeof(int), 1, f)) != 1)
		EroareCitireFisier();

	// alocare matrice
	a = calloc((*m) * (*n), sizeof(int));
	if (!a)
		EroareAlocareDinamica();

	// citire elemente matrice
	if (fread(a, sizeof(int), (*m) * (*n), f) != (*m) * (*n))
		EroareCitireFisier();
	
	fclose(f);
	printf("Citire din fisier cu succes !\n");

	return a;
}



int main(int argc, char** argv)
{
	int m, n, *a = NULL, i, j;
	optiune opt;



	do
	{
		Menu();
		scanf("%d", &opt);

		switch (opt)
		{
		case iesire:
			// eliberare matrice alocata
			if (a)
				EliberareMatrice(a);
			// iesire program
			exit(EXIT_SUCCESS);
		break;

		case introducere:
		{
			// citire matrice de la tastatura
			a = AlocareMatrice(&m, &n);
			CitireMatrice(a, m, n);
		}
		break;

		case citire:
		{
			// citire matrice din fisier
			a = CitireMatriceF(a, &m, &n);
		}
		break;

		case scriere:
		{
			// scriere matrice in fisier
			ScriereMatriceF(a, m, n);
		}
		break;

		case afisare:
		{
			// afisara matrice curenta
			if (!a) {
				EroareMatriceVida();
				break;
			}
				
			AfisareMatrice(a, m, n);
		}
		break;

		default:
			printf("Eroare ! Optiune nedefinita !\n");
		break;
		}

	} while (1);
	

	

	_getch();
	return 0;
}