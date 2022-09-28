#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef enum {mamifer,insecta,peste,pasare} tip_vietuitoare;
const char* nume_tip_v[] = {"mamifer", "insecta", "peste", "pasare"};

typedef enum {sarata,dulce} tip_apa;
const char* nume_tip_a[] = {"apa sarata", "apa dulce"};

typedef struct {
	char nume[30];
	tip_vietuitoare tip_v : 4;	// selector
	float t_viata;
	short unsigned aux;

	union {						// uniune
		struct {
			unsigned t_gestatie : 8;
			unsigned nr_pui : 8;
		} mam;

		struct {
			unsigned nr_picioare : 6;
			unsigned zbor : 1;
			unsigned periculos : 1;
		} ins;

		struct {
			tip_apa tip_a : 2;
			unsigned viteza_max_inot : 7;
			float adancime;
		} pes;

		struct {
			unsigned anvergura : 8;
			unsigned viteza_max_zbor : 8;
			float alt_max;
		}pas;

	} caracter;								// caracteristici

} vietuitoare;

void EroareAlocare(void)
{
	printf("Eroare la alocarea dinamica de memorie !\n");
	exit(EXIT_FAILURE);
}

vietuitoare* AlocareStruct(int n)
{
	vietuitoare* a = NULL;

	a = (vietuitoare*)calloc(n, sizeof(vietuitoare));
	if (!a)
		EroareAlocare();
	
	return a;
}

void EliberareStruct(vietuitoare* a)
{
	free(a);
}

void CitireStruct(vietuitoare* a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("\nVietuitoare[%d]: \n", i);

		// nume
		printf("Nume : ");
		getchar();
		gets(a[i].nume);

		// perioada medie de viata
		printf("Perioada medie de viata: ");
		scanf("%f", &a[i].t_viata);

		// tip
		printf("Tip : (0-mamifer,1-insecta,2-peste,3-pasare) : ");
		scanf("%d", &a[i].aux);
		a[i].tip_v = a[i].aux;

		switch (a[i].tip_v)
		{
		case mamifer:
		{
			printf("Perioada de gestatie: ");
			scanf("%d", &a[i].aux);
			a[i].caracter.mam.t_gestatie = a[i].aux;

			printf("Numarul mediu de pui nascuti: ");
			scanf("%d", &a[i].aux);
			a[i].caracter.mam.nr_pui = a[i].aux;
		}
		break;

		case insecta:
		{
			printf("Numar de picioare: ");
			scanf("%d", &a[i].aux);
			a[i].caracter.ins.nr_picioare = a[i].aux;

			printf("Poate zbura (0/1) : ");
			scanf("%d", &a[i].aux);
			a[i].caracter.ins.zbor = a[i].aux;

			printf("Periculoasa pentru om (0/1) : ");
			scanf("%d", &a[i].aux);
			a[i].caracter.ins.periculos = a[i].aux;
		}
		break;

		case peste:
		{
			printf("Tipul de apa (0-sarata, 1-dulce) : ");
			scanf("%d", &a[i].aux);
			a[i].caracter.pes.tip_a = a[i].aux;

			printf("Adancimea maxima : ");
			scanf("%f", &a[i].caracter.pes.adancime);

			printf("Viteza max. de inot : ");
			scanf("%d", &a[i].aux);
			a[i].caracter.pes.viteza_max_inot = a[i].aux;
		}
		break;

		case pasare:
		{
			printf("Anvergura aripilor: ");
			scanf("%d", &a[i].aux);
			a[i].caracter.pas.anvergura = a[i].aux;

			printf("Altitudinea maxima de zbor: ");
			scanf("%f", &a[i].caracter.pas.alt_max);

			printf("Viteza maxima de zbor: ");
			scanf("%d", &a[i].aux);
			a[i].caracter.pas.viteza_max_zbor = a[i].aux;
		}
		break;

		default:
		break;
		}
	}
}

void AfisareStruct(vietuitoare* a, int n)
{
	int i;

	printf("\n\n");

	for (i = 0; i < n; i++) {
		printf("[%d] : %10s  %5.2f ani  %10s ", i, a[i].nume, a[i].t_viata, nume_tip_v[a[i].tip_v]);

		switch (a[i].tip_v)
		{
			case mamifer:
			{
				printf("%3d zile  %3d pui\n", a[i].caracter.mam.t_gestatie, a[i].caracter.mam.nr_pui);
			}
			break;

			case insecta:
			{
				printf("%3d picioare  zbor:%3d  periculos:%3d\n", a[i].caracter.ins.nr_picioare, a[i].caracter.ins.zbor, a[i].caracter.ins.periculos);
			}
			break;

			case peste:
			{
				printf("%10s  %5d km/h  %6.2f m\n", nume_tip_a[a[i].caracter.pes.tip_a], a[i].caracter.pes.viteza_max_inot, a[i].caracter.pes.adancime);
			}
			break;

			case pasare:
			{
				printf("%5d gr.  %5d km/h  %6.2f km\n", a[i].caracter.pas.anvergura, a[i].caracter.pas.viteza_max_zbor, a[i].caracter.pas.alt_max);
			}
			break;

			default:
			break;
		}

	}
}


int main(int argc, char** argv)
{
	int n;
	vietuitoare* a = NULL;

	printf("Introduceti nr. de vietuitoare: ");
	scanf("%d", &n);

	a = AlocareStruct(n);
	CitireStruct(a, n);
	AfisareStruct(a, n);

	_getch();
	return 0;
}