#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void EroareDeschidereFisier(void)
{
	printf("Eroare deschidere fisier!\n");
	exit(EXIT_FAILURE);
}

void EroareScriereFisier(void)
{
	printf("Eroare scriere in fisier!\n");
	exit(EXIT_FAILURE);
}

void EroareAlocareMemorie(void)
{
	printf("Eroare alocare memorie!\n");
	exit(EXIT_FAILURE);
}

void EroareCitireFisier(void)
{
	printf("Eroare citire fisier !\n");
	exit(EXIT_FAILURE);
}

void Menu(void)
{
	printf("\n------------------ Meniu Interactiv ---------------------\n"
		"0. Citire din fisier\n"
		"1. Adaugare produs\n"
		"2. Afisare produse\n"
		"3. Scriere in fisier + Iesire\n"
		"---------------------------------------------------------\n"
		"Optiunea dvs: "
	);
}

typedef enum optiune {
	citire = 0,
	adaugare = 1,
	afisare = 2,
	iesire = 3
} optiune;

typedef struct produs {
	char* nume;
	float pret;
} produs;

void Citire(produs* produse, int* n)
{
	FILE* f = NULL;
	unsigned short len_nume;
	char* pnume = NULL;
	int i;

	if (!(f = fopen("produse.dat", "rb")))
		// nu exista baza de date
		return produse;

	if ((fread(n, sizeof(int), 1, f)) != 1)
		EroareCitireFisier();


	
	for (i = 0; i < *n; i++) {
		fread(&len_nume, sizeof(unsigned short), 1, f);
		pnume = (char*)malloc((len_nume + 1) * sizeof(char));
		if (!pnume)
			EroareAlocareMemorie();

		fread(pnume, sizeof(char), len_nume, f);	// citire nume
		pnume[len_nume] = 0;

		produse[i].nume = pnume;

		fread(&produse[i].pret, sizeof(float), 1, f);		// citire pret
	}

	return produse;
}

void Adaugare(produs* produse, int* n)
{
	produs p;
	char nume[1000];

	printf("Nume: ");
	getchar();
	fgets(nume, 1000, stdin);
	nume[strcspn(nume, "\r\n")] = 0;
	if (!(p.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char))))
		EroareAlocareMemorie();

	strcpy(p.nume, nume);

	printf("Pret: ");
	scanf("%g", &(p.pret));

	produse[*n] = p;
	(*n)++;
}

void Afisare(produs* produse, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%s: %g\n", produse[i].nume, produse[i].pret);
	}

	printf("\n");
}

void Scriere(produs* produse, int n)
{
	FILE* f;
	int i;
	unsigned short len_nume;	// nr. caractere nume

	if (!(f = fopen("produse.dat", "wb")))
		EroareDeschidereFisier();

	if ((fwrite(&n, sizeof(int), 1, f)) != 1)
		EroareScriereFisier();

	for (i = 0; i < n; i++) {
		len_nume = (unsigned short)strlen(produse[i].nume);
		fwrite(&len_nume, sizeof(unsigned short), 1, f);	// scriere lungime sir in fisier
		fwrite(produse[i].nume, sizeof(char), len_nume, f);	// scriere sir, fara terminator
		fwrite(&produse[i].pret, sizeof(float), 1, f);		// scriere pret
	}

	fclose(f);
	printf("Scriere in fisier cu succes !\n");
}

void Eliberare(produs* produse, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(produse[i].nume);
}

/*
* sa se modifice ex.4
* la inceputul fisierului sa fie scris nr. de produse
* citirea va fi modificata pentru a folosi aceasta informatie
*/


int main(int argc, char** argv)
{
	optiune opt;
	produs produse[10];
	int n = 0;


	do
	{
		Menu();
		scanf("%d", &opt);

		switch (opt)
		{
		case citire:
		{
			// citire din fisier
			Citire(produse, &n);
		}
		break;

		case adaugare:
		{
			// adaugare in array curent
			Adaugare(produse, &n);
		}
		break;

		case afisare:
		{
			// afisare produse din array curent
			Afisare(produse, n);
		}
		break;

		case iesire:
		{
			// scriere in fisier + iesire program
			Scriere(produse, n);
			Eliberare(produse, n);
		}
		break;

		default:
			printf("Optiune nedefinita!\n");
			break;
		}

	} while (opt != 3);

	return 0;
}