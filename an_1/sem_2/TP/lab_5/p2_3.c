#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef enum {numar,caracter,sir} tip_var;

typedef struct {
	char* nume_var;
	tip_var tip;		// selector

	union {				// uniune
		float numar;
		char caracter;
		char* sir;
	} t;
} variabila;

char* Linie(void)
{
	char c = NULL, *s = NULL;
	int i = 0;

	while ((c = getchar()) != "\n") {
		if (c == '\n')
			break;
		s = (char*)realloc(s, (i + 1) * sizeof(char));
		s[i] = c;
		i++;
	}

	s[i] = 0;

	return s;
}

int IsDigit(char* c)
{
	return (*c <= 57 && *c >= 48) ? 1 : 0;
}

void EroareAlocare(void)
{
	printf("Eroare la alocarea dinamica de memorie!\n");
	exit(EXIT_FAILURE);
}

variabila* Transform(char* s)
{
	variabila* v = NULL;
	char* p = NULL, *nume = NULL;


	if(!(v = calloc(1, sizeof(variabila))))
		EroareAlocare();
	

	p = s;
	while (p) {
		if (*p == '=') {
			// nume
			if(!(v->nume_var = calloc(p - s + 1, sizeof(char))))
				EroareAlocare();
			strncpy(v->nume_var, s, p - s);

			// numar
			if (IsDigit(p + 1)) {
				v->tip = 0;
				sscanf(p + 1, "%f", &v->t.numar);
				break;
			}

			// caracter
			else if (*(p + 1) == '\'') {
				v->tip = 1;
				v->t.caracter = *(p + 2);
				break;
			}

			// sir
			else if (*(p + 1) == '\"') {
				v->tip = 2;
				if(!(v->t.sir = (char*)calloc(s + strlen(s) - p - 2, sizeof(char))))
					EroareAlocare();

				strncpy(v->t.sir, p + 2, s + strlen(s) - p - 3);
				break;
				
			}
		}
				
		p++;
	}

	return v;
}

void AfisareStruct(variabila* v)
{
	printf("\nNume variabila: %s\n", v->nume_var);

	switch (v->tip)
	{
	case numar:
		printf("Valoare numerica: %.2f\n", v->t.numar);
	break;

	case caracter:
		printf("Valoare caracter: %c\n", v->t.caracter);
	break;

	case sir:
		printf("Valoare sir: %s\n", v->t.sir);
		break;
	

	default:
		break;
	}

	printf("\n");
}


int main(int argc, char** argv)
{
	char* s = NULL;
	variabila* v = NULL;


	s = Linie();
	printf("\nSirul introdus: %s\n", s);
	printf("Len: %d\n", strlen(s));

	v = Transform(s);
	AfisareStruct(v);

	_getch();
	return 0;
}