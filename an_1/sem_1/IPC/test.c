#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void Menu(void);
int Valid(char*);
void Afisare_Inversa(char*, int);
void Sterge2(char*, int);


int main()
{
	int opt, i, n;
	char c;
	char* str = NULL;
	
	do
	{
		

		Menu();
		printf("\nOptiunea dvs : ");
		scanf("%d", &opt);

		switch (opt)
		{

		case 1:
		{
			printf("Introduceti numarul de elemente a multimii A : ");
			scanf("%d", &n);

			str = (char*)calloc(n+1, sizeof(char));
			if (str == NULL) {
				printf("Eroare la alocarea dinamica a memoriei !\n");
				exit(EXIT_FAILURE);
			}
				
			for (i = 0; i < n; i++) {
				do {
					getchar();
					printf("A[%d] : ", i);
					str[i] = getchar();
				} while (!Valid(&str[i]));
			}
			str[i] = '\0';

			str[strlen(str) - 2] = str[0];

			printf("Multimea A : %s\n\n", str);
		}
		break;

		case 2:
		{
			Afisare_Inversa(str, n);

			printf("\n");
		}
		break;

		case 3:
		{
			Sterge2(str, n);

			printf("\n");
		}
		break;


		default:
			if (opt != 0)
				printf("Eroare ! Optiune nedefinita !\n");
			break;
		}
	} while
		(opt != 0);

	
	free(str);

	return 0;
}


void Menu(void)
{
	printf("------------- Meniu Interactiv -------------\n\n"
		"0. Iesire\n"
		"1. Citirea elementelor multimii A de la tastatura\n"
		// validare : litera mica sau cifra
		// penult. elem. : dat automat (= primul elem. introdus)
		"2. Afisarea elementelor multimii A in ordine inversa alfabetica\n"
		"3. Stergerea elementului secund al multimii, apoi afisarea noii multimi\n"
		// fiecare optiune -> functie
		// variabilele - transmise prin adresa
		// fara variabile globale
	);
}


int Valid(char* c)
{
	if ((*c) >= 'a' && (*c) <= 'z' || (*c) >= '0' && (*c) <= '9')
		return 1;
	else 
		return 0;
}

void Afisare_Inversa(char* str, int len)
{
	int i, ok;
	char aux;

	char* inv_str = calloc(len+1, sizeof(char));
	if (inv_str == NULL) {
		printf("Eroare la alocarea dinamica a memoriei !\n");
		exit(EXIT_FAILURE);
	}
	strcpy(inv_str, str);

	do {
		ok = 1;
		for (i = 0; i < len; i++)
			if (inv_str[i] < inv_str[i + 1]) {
				ok = 0;
				aux = inv_str[i]; 
				inv_str[i] = inv_str[i + 1];
				inv_str[i + 1] = aux;
			}
	} while (ok == 0);

	inv_str[len] = '\0';		
	
	printf("Multimea A in ordine aflabetica inversa : %s\n", inv_str);
	free(inv_str);
	inv_str = NULL;
}


void Sterge2(char* str, int len)
{
	int i;

	for (i = 1; i < len - 1; i++) {
		str[i] = str[i + 1];
	}

	str[len - 1] = '\0';
	len--;

	printf("Multimea A dupa stergerea elementului secund : %s\n", str);
}