#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef enum tip_motor {
	benzina,
	motorina,
	electric
} tip_motor;

typedef enum tip_vehicul {
	persoane,
	marfa,
	special
} tip_vehicul;


typedef struct {
	char nume[30];
	tip_motor tm;
	tip_vehicul tv;						// selector

	union {

		struct {						// persoane
			int nr_locuri;
			int nr_airbag;
		} pers;

		struct {						// marfa
			double capacitate;
			char frigorific;
		} mrf;

		struct {
			char nume_intrebuintare[30]; // special
		} spec;

	} caracter;								// caracteristici
} vehicul;

void EroareAlocare(void)
{
	printf("Eroare la alocarea dinamica de memorie !\n");
	exit(EXIT_FAILURE);
}

void EliberareStruct(vehicul* a)
{
	free(a);
}

vehicul* AlocareStruct(int n)
{
	int* a = NULL;

	a = (vehicul*)calloc(n, sizeof(vehicul));
	if (!a)
		EroareAlocare();
	
	return a;

}

void CitireStruct(vehicul* a, int n)
{
	int i;

	for (i = 0; i < n; i++) {

		// id
		printf("\n\nVehicul[%d]: \n", i);

		// nume
		printf("Nume: ");
		getchar();
		gets(a[i].nume);

		// tip motor
		printf("Tip motor (0 - benzina, 1 - motorina, 2 - electric) : ");
		scanf("%d", &a[i].tm);

		// tip vehicul
		printf("Tip vehicul (0 - persoane, 1 - marfuri, 2 - special) : ");
		scanf("%d", &a[i].tv);

		switch (a[i].tv)
		{
		case persoane:
		{
			printf("Nr. locuri: ");
			scanf("%d", &a[i].caracter.pers.nr_locuri);

			printf("Nr. airbag-uri: ");
			scanf("%d", &a[i].caracter.pers.nr_airbag);
		}
		break;

		case marfa:
		{
			printf("Capacitate : ");
			scanf("%lf", &a[i].caracter.mrf.capacitate);

			printf("Frigorific (0/1) : ");
			scanf("%hhd", &a[i].caracter.mrf.frigorific);
		}
		break;

		case special:
		{
			printf("Nume intrebuintare speciala: ");
			getchar();
			gets(a[i].caracter.spec.nume_intrebuintare);
		}
		break;

		default:
			printf("Tip vehicul nedefinit !\n");
		break;
		}

	}

}

void AfisareStruct(vehicul* a, int n)
{
	int i;

	printf("\n");

	for (i = 0; i < n; i++) {
		// nume
		printf("[%d]: %12s ", i, a[i].nume);

		// tip motor
		switch (a[i].tm)
		{
			case benzina:
				printf(" Motor cu benzina ");
			break;

			case motorina:
				printf(" Motor cu motorina ");
			break;

			case electric:
				printf(" Motor electric ");
			break;

			default:
				break;
		}

		// tip vehicul
		switch (a[i].tv)
		{
		case persoane:
			printf(" %5d %5d ", a[i].caracter.pers.nr_locuri, a[i].caracter.pers.nr_airbag);
		break;

		case marfa:
			printf(" %7.2f %5hhd ", a[i].caracter.mrf.capacitate, a[i].caracter.mrf.frigorific);
		break;

		case special:
			printf(" %7s ", a[i].caracter.spec.nume_intrebuintare);
		break;

		default:
			break;
		}

		printf("\n");
	}
}


int main(int argc, char* argv[])
{
	int n;
	vehicul *a = NULL;

	printf("Introduceti numarul de vehicule: ");
	scanf("%d", &n);

	a = AlocareStruct(n);
	CitireStruct(a, n);
	AfisareStruct(a, n);
	
	EliberareStruct(a);
	
	_getch();
	return 0;
}