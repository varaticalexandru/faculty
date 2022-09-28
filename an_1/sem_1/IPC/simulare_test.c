#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


/*
* gestionarea unui magazin de legume
* 
* caracterizarea legumelor : 
* - nume
* - cantitate
* - pret
* 
* meniu interactiv :
* 1. citeste o noua leguma de la tastatura. daca se citeste o leguma existenta i se va incrementa doar cantitatea,
*	 si i se modifica pretul daca e diferit de cel initial
* 2. afisarea legumelor din magazin
* 3. transforma toate vocalele litere mici -> litere mari
* 4. iesire
*/ 

typedef struct leguma
{
	char nume[20];
	unsigned int cantitate;
	unsigned int pret;
} L;

void _meniu(void)
{
	printf("\n------------- Meniu Interactiv -------------\n"
		   "1. citeste o noua leguma de la tastatura\n"
		   "2. afisarea legumelor din magazin\n"
		   "3. transforma vocalele mici -> litere mari\n"
		   "4. iesire\n\n"
		   "Optiunea dvs : ");
}

void _citeste(L* leg, int* n)
{
	int i, cantitate_aux;
	char aux[20];

	printf("Nume: ");
	scanf("%s", (leg + *n)->nume);

	strcpy(aux, (leg + *n)->nume);

	if (*n > 0)
	{
		for (i = 0; i < *n; i++)
			if (strcmp((leg + i)->nume, aux) == 0)
			{
				printf("Ati introdus deja acest produs ! Cantitatea se va cumula !\n");
				printf("Cantitate: ");
				scanf("%d", &cantitate_aux);
				(leg + i)->cantitate += cantitate_aux;
				printf("Pret: ");
				scanf("%d", &((leg + i)->pret));
				*n--;
			}
			else
			{
				printf("Cantitate: ");
				scanf("%d", &((leg + *n)->cantitate));

				printf("Pret: ");
				scanf("%d", &((leg + *n)->pret));
			}
	}
	else
	{
		printf("Cantitate: ");
		scanf("%d", &((leg + *n)->cantitate));

		printf("Pret: ");
		scanf("%d", &((leg + *n)->pret));
	}

	(*n)++;
		
	printf("\n");
}

void _afisare(L* leg, int* i)
{
	printf("[%d] : %10s %4d %4d\n", *i, (leg + *i)->nume, (leg + *i)->pret, (leg + *i)->cantitate);
}

int main(void)
{
	L leg[50];
	int opt, n = 0, i;
	
	do
	{
		_meniu();
		scanf("%d", &opt);
		printf("\n");

		switch (opt)
		{
		case 1:
		{
			_citeste(leg, &n);
		}
		break;

		case 2:
		{
			for (i = 0; i <= n; i++)
				_afisare(leg, &i);
		}
		break;

		case 3:
		{
				
		}
		break;

		case 4:
		{
			exit(0);
		}
		break;


		default:
			printf("Eroare ! Optiune nedefinita !\n");
		break;
		}
	} while (opt != 4);

	
	return 0;
}