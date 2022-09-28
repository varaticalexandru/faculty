#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*
    un fisier text contine, pe fiecare linie, numele candidatului (maxim 15 caractere)
    si media la examen (valore reala)

    fisierul contine maxim 35 linii

    a) sa se afiseze continutul fisierului
    b) sa se caute in fisier numele unui candidat. daca este gasit,
       sa se afiseze numele si media. in caz contrar se afiseaza un mesaj
    c) sa se salveze intr-un tablou continutul fisierului
    d) sa se sorteze descrescator, dupa medie, candidatii care au promovat examenul
    e) sa se salveze intr-un alt fisier candidatii reusiti
    f) sa se salveze sub forma de tabel numele si media candidatilor promovati

    numele fisierelor se vor citi de la tastatura
*/


typedef struct student{
    char nume[16];
    float nota;
} student;


void ErrorOpenFile(void)
{
    printf("Eroare la deschiderea fisierului !\n");
    exit(EXIT_FAILURE);
}

void ErrorDynamicAllocation(void)
{
    printf("Eroare la alocarea dinamica de memorie !\n");
    exit(EXIT_FAILURE);
}

student* ArrRealloc(student* arr, int n)
{
    student* aux = NULL;

    aux = (student*)realloc(arr, (n+2)*sizeof(student));
    if (!aux)
        ErrorDynamicAllocation();

    return aux;
}

void RecDisp(student* arr, int i)
{
    printf("[%d]: \t%10s\t%5.2f\n", i, arr[i].nume, arr[i].nota);
}

void ArrDisp(student* arr, int n)
{
    printf("\n");

    for (int i = 0; i < n; i++)
        RecDisp(arr, i);

    printf("\n");
}

student* FileRead(char in_name[], student* arr, int* n, char* nume_cautat[])
{
    FILE* in = NULL;
    char buffer[100];
    int found = 0, found_id;
    student temp;

    if (!(in = fopen(in_name, "rt")))
        ErrorOpenFile();

    arr = (student*)calloc(1, sizeof(student));
    if (!arr)
        ErrorDynamicAllocation();

    printf("\nContinutul fisierului: \n\n");
    while (fgets(buffer, 100, in)) {
        fputs(buffer, stdout);

        sscanf(buffer, "%s %f", arr[*n].nume, &arr[*n].nota);

        if (!(strcmp(nume_cautat, arr[*n].nume)) && !found) {
            found = 1;
            found_id = *n;
            temp = arr[*n];
        }

        arr = ArrRealloc(arr, *n);
        (*n)++;
    }

    fclose(in);

    if (!found)
        printf("\nInregistrarea cu numele cautat nu a fost gasita :\n");
    else {
        printf("\nInregistrarea cu numele cautat a fost gasita :\n");
        RecDisp(arr, found_id);
    }

    return arr;
}

void StructSwap(student* s1, student* s2)
{
    student aux = *s1;
    *s1 = *s2;
    *s2 = aux;
}

void RecDel(student* arr, int* n, int j)
{
    int i;

    for (i = j; i < *n; i++)
        arr[i] = arr[i+1];

    (*n)--;
}

void ArrClear(student* arr, int* n)
{
    int i;

    for (i = 0; i <= *n; i++)
        if (arr[i].nota < 5) {
            RecDel(arr, n, i);
            i--;
        }

}

void BubbleSort(student* arr, int n)
{
    int i, ok;

    do {
        ok = 1;
        for (i = 0; i < n-1; i++)
            if (arr[i].nota < arr[i+1].nota) {
                ok = 0;
                StructSwap(&arr[i], &arr[i+1]);
            }
    }
    while (!ok);
}

int Partition(student* arr, int l, int r)
{
    int i, j;
    student pivot;

    i = l - 1;
    pivot = arr[r];

    for (j = l; j < r; j++)
        if (arr[j].nota <= pivot.nota) {
            i++;
            StructSwap(&arr[i], &arr[j]);
        }

    StructSwap(&arr[i+1], &arr[r]);
    return (i+1);
}

void QuickSort(student* arr, int l, int r)
{
    int pi;

    if (l < r) {
        pi = Partition(arr, l, r);
        QuickSort(arr, l, pi-1);
        QuickSort(arr, pi+1, r);
    }
}

void FileWrite(char* out_name, student* arr, int n)
{
    FILE* out = NULL;
    int i;

    if (!(out = fopen(out_name, "wt")))
        ErrorOpenFile();

    for (i = 0; i < n; i++) {
        fprintf(out, "%s %.2f\n", arr[i].nume, arr[i].nota);
    }

    fclose(out);

}

int main(int argc, char* argv[])
{
    char in_name[20], out_name[20], nume_cautat[20];
    student* arr = NULL;
    int n = 0;

    printf("Introduceti numele fisierului de intrare: ");
    fgets(in_name, 20, stdin);
    in_name[strcspn(in_name, "\n")] = 0;

    printf("Introduceti numele fisierului de iesire: ");
    fgets(out_name, 20, stdin);
    out_name[strcspn(out_name, "\n")] = 0;

    printf("Introduceti numele studetului cautat: ");
    fgets(nume_cautat, 20, stdin);
    nume_cautat[strcspn(nume_cautat, "\n")] = 0;

    arr = FileRead(in_name, arr, &n, nume_cautat);

    printf("\nContinutul tabelului: \n");
    ArrDisp(arr, n);

    ArrClear(arr, &n);
    printf("\nContinutul tabelului dupa stergerea studentilor picati: \n");
    ArrDisp(arr, n);

    BubbleSort(arr, n);

    printf("\nContinutul tabelului sortat descrescator dupa nota a studentilor reusiti: \n");
    ArrDisp(arr, n);

    FileWrite(out_name, arr, n);

    _getch();
    return 0;
}
