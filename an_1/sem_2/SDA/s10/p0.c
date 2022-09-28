#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>


// nodul sublistei
typedef struct sl {
	char disciplina[20];
	float nota;
	struct sl* urm;		// camp de inlatuire asociat subl.
} sl;

// nodul listei
typedef struct node {
	char nume[20];
	char prenume[20];
	struct node* urm;	// camp de inlatuire asociat listei principale
	sl* prim;			
} node;

node* rad = NULL;		// radacina



//  ! generam folosind adaugarea la inceput !

// adauga un nod in sublista
sl* add_sl(sl* lista, sl* aux_sl)
{
	aux_sl->urm = lista;
	lista = aux_sl;

	return lista;
}

// adaugare un nod in lista principala
node* add_l(node* lista, char nume[], char prenume[], char disciplina[], float nota)
{
	// test: este numele adaugat deja in lista principala?
	node* q = lista;
	node* aux;
	sl* aux_sl;

	for (q = lista; q && strcmp(q->nume, nume); q = q->urm);
	if (!q) {
		aux = (node*)malloc(sizeof(node));
		strcpy(aux->nume, nume);
		strcpy(aux->prenume, prenume);
		aux->prim = NULL;

		aux->urm = lista;	// realizam inlantuirea
		lista = aux;
		q = aux;
	}

	aux_sl = (sl*)malloc(sizeof(sl));
	strcpy(aux_sl->disciplina, disciplina);
	aux_sl->nota = nota;

	aux_sl->urm = q->prim;	// realizam inlantuirea
	q->prim = aux_sl;

	return lista;
}

// citirea info. din fisier
void citire(void)
{
	FILE* f = NULL;
	char nume[20], prenume[20], disciplina[20];
	float nota;

	f = fopen("ev.txt", "rt");
	while (!feof(f))
	{
		fscanf(f, "%s %s %s %f", nume, prenume, disciplina, &nota);
		rad = add_l(rad, nume, prenume, disciplina, nota);
	}

	fclose(f);
}

void afisare(node* lista)
{
	node* q;
	sl* r;

	for (q = lista; q; q = q->urm) {
		printf("\n%s %s\n", q->nume, q->prenume);
		for (r = q->prim; r; r = r->urm)
			printf("\t%s %f\n", r->disciplina, r->nota);
	}
		
}

// ordonarea in l : default
// ordonarea in sl : in f. de disciplina/nota

int main(int argc, char** argv)
{
	citire();
	afisare(rad);


	_getch();
	return 0;
}