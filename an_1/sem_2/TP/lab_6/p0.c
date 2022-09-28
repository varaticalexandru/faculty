#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef enum {
	iesire, introducere, afisare
} optiune;

typedef struct produs {
	char nume[50];
	float pret;
} produs;

void Menu(void)
{
	printf("------------ Meniu Interactiv ------------\n"
		   "0. Iesire\n"
		   "1. Introducere\n"
		   "2. Afisare\n"
			"------------------------------------------\n"
		    "Optiunea dvs: "
	);
}

produs* RealocareStruct(produs* v, int n)
{
	produs* v1 = NULL;

	v1 = (produs*)realloc(v, (n + 1) * sizeof(produs));
	if (!v1) {
		printf("Eroare la alocarea dinamica de memorie\n");
		exit("EXIT_FAILURE");
	}
	return v1;
}

produs* Introducere(produs* v, int* n)
{
	produs* vn = NULL;
	char nume[20];
	int i, flag = 0;

	vn = RealocareStruct(v, *n);

	printf("Nume: "); scanf("%s", nume);

	for (i = 0; vn, i < *n; i++)
		if (!strcmp(vn[i].nume, nume)) {
			printf("Pret: "); scanf("%f", &vn[i].pret);
			flag = 1;
			break;
		}

	
	if (!flag) {
		strcpy(vn[*n].nume, nume);

		printf("Pret: "); scanf("%f", &vn[*n].pret);
		printf("\n");

		(*n)++;
	}

	return vn;
}

void Afisare(produs* v, int i)
{
	printf("%s \t %.2f\n", v[i].nume, v[i].pret);
}


int main(int argc, char** argv)
{
	optiune opt;
	int i, n = 0;
	produs* arr = NULL;

	do
	{
		Menu();
		scanf("%d", &opt);
		printf("\n");
		switch (opt)
		{
			case iesire:
				exit(0);
			break;

			case introducere:
			{
				arr = Introducere(arr, &n);
			}
			break;

			case afisare:
			{
				for (i = 0; i < n; i++)
					Afisare(arr, i);
				printf("\n");
			}
			break;

			default:
				printf("Eroare. Optiune nedefinita\n");
			break;
		}

	} while (opt);





	_getch();
	return 0;
}