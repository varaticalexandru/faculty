#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct node {
    char* nume;
    float nota;
    struct node* urm;
} node;

node* radacina = NULL;

node* AdaugaInceput(node* lista, node* aux)
{
    aux->urm = lista;
    lista = aux;

    return lista;
}

void Afisare(node* lista)
{
    node* q;

    for (q = lista; q != NULL; q = q->urm)
        printf("\n%s %2.f", q->nume, q->nota);
}

// tehnica celor 2 ptr
node* AdaugareOrdonata(node* lista, node* aux)
{
    node* q1, *q2;  // pointeri de parcurgere

    for (q1 = q2 = lista; q1 != NULL && aux->nota > q1->nota; q2 = q1, q1 = q1->urm);
    // inserarea se face intre q2 si q1

    // testam daca s-a gasit locul de inserare
    if (q1 == q2) {
        // inserarea se face in capul listei
        aux->urm = lista;
        lista = aux;
    }
    else {
        q2->urm = aux;
        aux->urm = q1;
    }

    return lista;
}

node* Sterge(node* lista, float nota)
{
    node* q1,*q2;

    for (q1 = q2 = lista; q1 != NULL && q1->nota != nota; q2 = q1, q1 = q1->urm);
    // daca exista nodul cautat
    if (q1 != NULL)
        if (q1 == q2) 
            lista = lista->urm;
        else {
            q2->urm = q1->urm;
            free(q1->nume);
            free(q1);
        }

    return lista;
}

void Citire(void)
{
    FILE* f = NULL;
    char nume[20];
    float nota;
    node* aux = NULL;

    f = fopen("ev.txt", "rt");

    while (!feof(f)) {
        fscanf(f, "%s %f", &nume, &nota);
        aux = (node*)malloc(sizeof(node));
        aux->nume = (char*)malloc(strlen(nume)+1);
        strcpy(aux->nume, nume);
        aux->nota = nota;
        aux->urm = NULL;
        // radacina = AdaugaInceput(radacina, aux);
        radacina = AdaugareOrdonata(radacina, aux);
    }

    Afisare(radacina);
}




int main(int argc, char** argv)
{
    Citire();
    radacina = Sterge(radacina, 5);

    printf("\n\n------------------------------------\n");
    Afisare(radacina);

    printf("\n");
    _getch();
    return 0;
}