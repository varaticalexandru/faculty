#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct student {
	char nume[30];
	int nr_matricol;
} student;

void StructSwap(student* a, student* b)
{
	student aux = *a;
	*a = *b;
	*b = aux;
}

void MeniuInteractiv(void)
{
	printf("--------------------------- Meniu Interactiv ----------------------------\n"
		"0. Iesire\n"
		"1. Citirea datelor studentilor\n"
		"2. Afisarea datelor tuturor studentilor\n"
		"3. Sortarea listei in ordine alfabetica a numelor\n"
		"4. Sortarea listei in ordine crescatoare a nr. matricole\n"
		"5. Cautarea unui student dupa nume\n"
		"6. Cautarea unui student dupa nr. matricol\n"

		"--------------------------------------------------------------------------\n"
		"Optiunea dvs: "
	);
}

void EroareAlocare(void)
{
	printf("Eroare la alocarea dinamica de memorie !\n");
	exit(EXIT_FAILURE);
}

student* AlocareStruct(int* n)
{
	student* v = NULL;

	printf("Introduceti numarul de studenti: ");
	scanf("%d", n);

	v = calloc(*n, sizeof(student));
	if (!v)
		EroareAlocare();

	return v;
}

void CitireStruct(student* v, int n)
{
	int i;

	printf("\nIntroduceti datele studentilor : \n\n");
	for (i = 0; i < n; i++)
	{
		printf("student[%d] :\n", i);
		printf("Nume: ");
		getchar();
		gets(v[i].nume);
		printf("Nr. matricol: ");
		scanf("%d", &v[i].nr_matricol);
		printf("\n");
	}

	printf("\n");
}

void AfisareElemStruct(student* v, int i)
{
	printf("student[%d] : %10s %7d\n", i, v[i].nume, v[i].nr_matricol);
}

void SortareAlf(student* v, int n)
{
	int i, ok;

	do
	{
		ok = 1;
		for (i = 1; i < n; i++)
			if (strcmp(v[i].nume, v[i - 1].nume) < 0)
			{
				ok = 0;
				StructSwap(&v[i], &v[i - 1]);
			}
	} while (!ok);
}

void SortareNum(student* v, int n)
{
	int i, ok;

	do
	{
		ok = 1;
		for (i = 1; i < n; i++)
			if (v[i].nr_matricol < v[i - 1].nr_matricol)
			{
				ok = 0;
				StructSwap(&v[i], &v[i - 1]);
			}
	} while (!ok);
}

void CautareAlf(student* v, int n)
{
	char nume_cautat[30];
	int i, id = -1;

	printf("Introduceti numele studentului cautat: ");
	getchar();
	gets(nume_cautat);

	SortareAlf(v, n);

	for (i = 0; i < n; i++)
		if (!(strcmp(v[i].nume, nume_cautat))) {
			id = i;
			break;
		}

	if (id == -1) {
		printf("Nu s-a gasit nici un student in lista cu acest nume !\n");
		exit(EXIT_SUCCESS);
	}

	printf("Pozitia studentului in lista ordonata alfabetic : %d\n\n", id);
}

void CautareNum(student* v, int n)
{
	int i, nr_cautat, id = -1;

	printf("Introduceti nr. matricol al studentului cautat: ");
	scanf("%d", &nr_cautat);

	SortareNum(v, n);

	for (i = 0; i < n; i++)
		if (v[i].nr_matricol == nr_cautat) {
			id = i;
			break;
		}

	if (id == -1) {
		printf("Nu s-a gasit nici un student in lista cu acest nr. matricol !\n");
		exit(EXIT_SUCCESS);
	}

	printf("Pozitia studentului in lista ordonata numeric : %d\n\n", id);
}

typedef enum optiune {
	iesire, citire, afisare, sortare_alf, sortare_num, cautare_alf, cautare_num
} optiune;

int main(int argc, char** argv)
{
	student* v = NULL;
	int i, n;
	optiune opt;

	do
	{
		MeniuInteractiv();
		scanf("%d", &opt);
		printf("\n");

		switch (opt)
		{
		case iesire:
			exit(EXIT_SUCCESS);
			break;

		case citire:
		{
			v = AlocareStruct(&n);
			CitireStruct(v, n);
		}
		break;

		case afisare:
		{
			printf("Datele studentilor introdusi: \n");
			for (i = 0; i < n; i++)
				AfisareElemStruct(v, i);
			printf("\n");
		}
		break;

		case sortare_alf:
		{
			SortareAlf(v, n);
		}
		break;

		case sortare_num:
		{
			SortareNum(v, n);
		}
		break;

		case cautare_alf:
		{
			CautareAlf(v, n);
		}
		break;

		case cautare_num:
		{
			CautareNum(v, n);
		}
		break;

		default:
			printf("Eroare ! Optiune nedefinita !\n");
			break;
		}

	} while (opt);








	_getch();
	return 0;
}