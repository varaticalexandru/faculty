#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*
* evidenta.txt
* nume disciplina nota
* 
* a. afisati evidenta ordonata alfabetic
* b. afisati evidenta orodonata dupa disciplina
* c. afisati evidenta orodonata pt. o anumita disciplina
* d. afisati evidenta orodonata dupa nota
*/

typedef struct node {
	char nume[20];
	char disciplina[20];
	float nota;

	struct node* urm1;
	struct node* urm2;
	struct node* urm3;
} node;

node* r1 = NULL;
node* r2 = NULL;
node* r3 = NULL;

// functie de adaugare in lista - returneaza radacina (tehnica celor 2 p)
// genereaza inlatuiri ordonate dupa nume
node* ad1(node* lista, node* aux)
{
	// ptr folositi in traversare
	node* q1, * q2;
	
	// for-ul cauta locul de inserare
	for (q1 = q2 = lista; q1 != NULL && strcmp(aux->nume, q1->nume) > 0; q2 = q1, q1 = q1->urm1);

	if (q1 == q2) {
		// adaugarea se face in capul listei
		aux->urm1 = lista;
		lista = aux;
	}
	else {
		// adaugarea se face pe parcurs
		q2->urm1 = aux;
		aux->urm1 = q1;
	}
	
	return lista;
}

// functie de adaugare in lista - returneaza radacina (tehnica celor 2 p)
// genereaza inlatuiri ordonate dupa disciplina
node* ad2(node* lista, node* aux)
{
	// ptr folositi in traversare
	node* q1, * q2;

	// for-ul cauta locul de inserare
	for (q1 = q2 = lista; q1 != NULL && strcmp(aux->disciplina, q1->disciplina) > 0; q2 = q1, q1 = q1->urm2);

	if (q1 == q2) {
		// adaugarea se face in capul listei
		aux->urm2 = lista;
		lista = aux;
	}
	else {
		// adaugarea se face pe parcurs
		q2->urm2 = aux;
		aux->urm2 = q1;
	}

	return lista;
}

// functie de adaugare in lista - returneaza radacina (tehnica celor 2 p)
// genereaza inlatuiri ordonate dupa nota
node* ad3(node* lista, node* aux)
{
	// ptr folositi in traversare
	node* q1, * q2;

	// for-ul cauta locul de inserare
	for (q1 = q2 = lista; q1 != NULL && aux->nota < q1->nota; q2 = q1, q1 = q1->urm3);

	if (q1 == q2) {
		// adaugarea se face in capul listei
		aux->urm3 = lista;
		lista = aux;
	}
	else {
		// adaugarea se face pe parcurs
		q2->urm3 = aux;
		aux->urm3 = q1;
	}

	return lista;
}

// functii de afisare
void af1(node* lista) {
	node* q = lista;

	while (q != NULL) {
		printf("\n%s %s %2.f\n", q->nume, q->disciplina, q->nota);
		q = q->urm1;
	}	
}

void af2(node* lista) {
	node* q = lista;

	while (q != NULL) {
		printf("\n%s %s %2.f\n", q->nume, q->disciplina, q->nota);
		q = q->urm2;
	}
}

void af3(node* lista, char* disciplina) {
	node* q = lista;

	while (q != NULL) {
		if (strcmp(q->disciplina, disciplina) == 0) 
			printf("\n%s %s %2.f\n", q->nume, q->disciplina, q->nota);
		q = q->urm3;
	}
}

node* sterge1(node* lista, char* nume, char* disciplina)
{
	node* q1,* q2;

	for (q1 = q2 = lista; q1 != NULL && (strcmp(q1->nume, nume) != 0 || strcmp(q1->disciplina, disciplina) != 0); q2 = q1, q1 = q1->urm1);
	if (q1 != NULL) {
		// nodul a fost gasit
		
		// stergerea se face din capul listei
		if (q1 == q2)
			lista = lista->urm1;
		else
			// stergerea se face pe parcurs
			q2->urm1 = q1->urm1;
	}
}

node* sterge2(node* lista, char* nume, int nota)
{
	node* q1, * q2;

	for (q1 = q2 = lista; q1 != NULL && (strcmp(q1->nume, nume) != 0 || q1->nota != nota); q2 = q1, q1 = q1->urm2);
	if (q1 != NULL) {
		// nodul a fost gasit

		// stergerea se face din capul listei
		if (q1 == q2)
			lista = lista->urm2;
		else
			// stergerea se face pe parcurs
			q2->urm2 = q1->urm2;
	}
}

node* sterge3(node* lista, char* disciplina, int nota)
{
	node* q1, * q2;

	for (q1 = q2 = lista; q1 != NULL && (strcmp(q1->disciplina, disciplina) != 0 || q1->nota != nota); q2 = q1, q1 = q1->urm3);
	if (q1 != NULL) {
		// nodul a fost gasit

		// stergerea se face din capul listei
		if (q1 == q2)
			lista = lista->urm3;
		else
			// stergerea se face pe parcurs
			q2->urm3 = q1->urm3;
	}
}

void citire(void)
{
	FILE* f = NULL;
	node* aux = NULL;

	f = fopen("evidenta.txt", "rt");
	while (!feof(f)) {
		aux = (node*)malloc(sizeof(node));
		fscanf(f, "%s %s %f", aux->nume, aux->disciplina, &aux->nota);

		r1 = ad1(r1, aux);
		r2 = ad2(r2, aux);
		r3 = ad3(r3, aux);
	}

	r1 = sterge1(r1, "N1", "D2");
	r2 = sterge2(r2, "N2", 3);
	r3 = sterge3(r3, "D1", 8);

	af1(r1);
	printf("\n--------------------\n");

	af2(r2);
	printf("\n--------------------\n");

	af3(r3, "D2");
	printf("\n--------------------\n");
}





int main(int argc, char** argv)
{
	citire();


	return 0;
}