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

void Menu(void)
{
	printf("\n------------------ Meniu Interactiv ---------------------\n"
		"1. Adaugare produs\n"
		"2. Afisare produse\n"
		"3. Iesire\n"
		"---------------------------------------------------------\n"
		"Optiunea dvs: "
	);
}

typedef enum optiune{
	adaugare=1,
	afisare=2,
	iesire=3
} optiune;

typedef struct produs {
	char nume[28];
	float pret;
} produs;

void Adaugare(produs* produse, int* n)
{
	produs p;

	printf("Nume: ");
	getchar();
	fgets(p.nume, 28, stdin);
	p.nume[strcspn(p.nume, "\r\n")] = 0;
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

	if ((fwrite(&n, sizeof(int), 1, f)) < 1)
		EroareScriereFisier();

	if (fwrite(produse, sizeof(produs), n, f) < n)
		EroareScriereFisier();
	fclose(f);
}



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
		case adaugare:
		{
			Adaugare(produse, &n);
		}
		break;

		case afisare:
		{
			Afisare(produse, n);
		}
		break;

		case iesire:
		{
			Scriere(produse, n);
		}
		break;
		
		default:
			printf("Optiune nedefinita!\n");
		break;
		}

	} while (opt != 3);




	return 0;
}