#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void BinDisp(int n)
{
    printf("\n");

    for (int i = 31; i >= 0; i--)
        printf("%d", (n>>i) & 1);

    printf("\n");
}

int NumOf1s(int n)
{
    int k = 0;

    for (int i = 31; i >= 0; i--)
        if ((n >> i) & 1)
            k++;

    return k;
}


int main(int argc, char** argv)
{
    int n;
    char out_name[20];
    FILE* out = NULL;
    int temp;

    printf("Introduceti numele fisierului binar de iesire: ");
    fgets(out_name, 100, stdin);
    out_name[strcspn(out_name, "\n")] = 0;

    if (!(out = fopen(out_name, "wb"))) {
        printf("Eroare la deschiderea fisierului binar !\n");
        exit(EXIT_FAILURE);
    }


    printf("Introduceti numere, terminati prin introducerea lui EOF: \n");

    while ((scanf("%d", &n)) != EOF) {
        printf("\nReprezentarea binara a numarului %d :\n", n);
        BinDisp(n);
        printf("\nNumarul de biti de 1: %d\n\n", NumOf1s(n));

        if ((NumOf1s(n) % 2) != 0) {
            fprintf(out,"%d\n", n);
        }
    }

    fclose(out);



    if (!(out = fopen(out_name, "rb"))) {
        printf("Eroare la deschiderea fisierului binar !\n");
        exit(EXIT_FAILURE);
    }

    printf("\n\nContinutul fisierului binar (citit):\n");
    while (!feof(out)) {
        fscanf(out, "%d\n", &temp);
        printf("%d\n", temp);
    }

    fclose(out);


    _getch();
    return 0;
}
