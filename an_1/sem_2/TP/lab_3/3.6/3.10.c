#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void EliberareVector(float* v)
{
	free(v);
}

float* RealocareVector(float* v, int* n)
{
	float* p = NULL;

	(*n)++;
	p = (float*)realloc(v, (*n+1) * sizeof(float));

	return p;
}

void CitireElementVector(float* v, int n)
{
	printf("\nv[%d] : ", n-1);
	scanf("%f", v + n - 1);
}

void AfisareVector(float* v, int n)
{
	float* i = NULL;

	for (i = v; i < v + n; i++)
		printf("%.2f  \t", *i);
	printf("\n");
}

void Stergere(float* v, int* n)
{
	float* i = NULL, nr, *j = NULL, k;

	printf("Introduceti valorea elementelor sterse: ");
	scanf("%f", &nr);

	k = 0;
	for (i = v; i < v + *n; i++)
		if (*i == nr) {
			k++;
			for (j = i; j < v + *n; j++)
				*j = *(j+1);
			i--;
		}

	if (!k)
		printf("Nu s-a gasit valoarea introduse in tablou !\n");

	(*n) -= k;
}

void Menu(void)
{
	printf(
		"\n----------------------------------- Meniu Interactiv -----------------------------------\n"
		"1. Citire - citeste o valoare reala si o adauga intr-un vector cu maxim 100 de elemente\n"
		"2. Afisare - afiseaza toate valorile din vector\n"
		"3. Stergere - citeste o valoare si sterge toate elementele egale cu valoarea citita\n"
		"4. Iesire\n"
		"----------------------------------------------------------------------------------------\n"
		"Optiunea dvs: "
	);
}


/*
	1. Citire - citeste o valoare reala si o adauga intr-un vector cu maxim 100 de elemente
	2. Afisare - afiseaza toate valorile din vector
	3. Stergere - citeste o valoare si sterge toate elementele egale cu valoarea citita
	4. Iesire
*/

typedef enum menu{
	citire = 1, afisare = 2, stergere = 3, iesire = 4
} menu;

int main(void)
{
	menu opt;
	float *v = NULL;
	int n = 0;

	do
	{
		Menu();
		scanf("%d", &opt);

		switch (opt)
		{
			case citire:
			{
				v = RealocareVector(v, &n);
				CitireElementVector(v, n);
			}
			break;

			case afisare:
			{
				AfisareVector(v, n);
			}
			break;

			case stergere:
			{
				Stergere(v, &n);
			}
			break;
			
			case iesire:
				exit(0);
			break;

			default:
				printf("Eroare ! Optiunea nedefinita !\n");
			break;
		}

		
	} while (opt != 4);

		
	EliberareVector(v);

	_getch();
	return 0;
}