#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

// TDA multime
/*
....dcba
00000001 M = {'a'}
00000011 M = { 'a', 'b'}

masca = ...00001 << litera - 'a' ---> M = M | masca
*/



// TDA enumeratie
typedef enum studii {
	medii,
	superioare,
	doctorat
} studii;

typedef enum profil_doctorat {
	economic,
	tehnic
} profil_doctorat;


// TDA articol --> structura
typedef struct data_nasterii {
	int zi, luna, an;
} data_nasterii;

typedef struct inf_medii {
	float medie_bac, medie_4_ani;
} inf_medii;


// TDA articol cu variante --> structura ce include (obligator) camp uniune, camp selector

// uniune
typedef union informatii {
	inf_medii i_m;			// articol
	float nota_l;			// float
	profil_doctorat p;		// enum
} informatii;

	// articol cu variante (angajat)
typedef struct ang {
	char nume[20], prenume[20];
	data_nasterii d_n;
	float salariu;
	studii s;		// camp selector
	informatii inf;		// camp uniune
} ang;

int Citire(ang a[])
{
	int i = 0;
	FILE* f = NULL;

	if ((f = fopen("angajati.txt", "rt")) == NULL)
		printf("Nu exista fisierul !");
	else
		while (!feof(f))
		{
			fscanf(f, "%s %s %d.%d.%d %f %d", a[i].nume, a[i].prenume, &a[i].d_n.zi, &a[i].d_n.luna, &a[i].d_n.an, &a[i].salariu, &a[i].s);

			switch (a[i].s)
			{
				case medii:
				{
					fscanf(f, "%f %f", &a[i].inf.i_m.medie_bac, &a[i].inf.i_m.medie_4_ani);
				}
				break;

				case superioare:
				{
					fscanf(f, "%f", &a[i].inf.nota_l);
				}
				break;

				case doctorat:
				{
					fscanf(f, "%d", &a[i].inf.p);
				}
				break;

				default:
					break;
			}
			i++;
		}
		fclose(f);
		
	return i;
}

void Afisare(ang a[], int n)
{
	int i;

	printf("Angajatii cititi din fisier:\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%s  %s  %d  %d  %d  %.2f   ", a[i].nume, a[i].prenume, a[i].d_n.zi, a[i].d_n.luna, a[i].d_n.an, a[i].salariu);
		switch (a[i].s)
		{
		case medii:
		{
			printf("studii medii   %.2f    %.2f\n", a[i].inf.i_m.medie_bac, a[i].inf.i_m.medie_4_ani);
		}
		break;

		case superioare:
		{
			printf("studii superioare   %.2f\n", a[i].inf.nota_l);
		}
		break;

		case doctorat:
		{
			switch (a[i].inf.p)
			{
				case 0:
					printf("doctorat: profil economic\n");
					break;

				case 1:
					printf("doctorat: profil tehnic\n");
					break;

				default:
				break;
			}
		}
		break;

		default:
			break;
		}

	}
}






int main(void)
{
	ang a[20];
	int n;


	n = Citire(a) - 1;
	Afisare(a, n);


	
	_getch();
	return 0;
}