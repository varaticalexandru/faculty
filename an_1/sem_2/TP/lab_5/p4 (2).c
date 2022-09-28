#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define tpers 1
#define tmarfa 2


typedef struct autovehicul
{
    char aux;
    union
    {
        int locuri;
        double tonaj;
    } capacitate;
    float km;
    char diesel;
    char marca[];
} autovehicul;

void Linii(void)
{
    int car;
    while ((car = getchar()) != EOF && car != '\n');
}


int main(int argc, char** argv)
{
    autovehicul* a = NULL;
    char buffer[100];

    // citire date
    printf("Marca: ");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = 0;

    a = (autovehicul*)malloc(sizeof(autovehicul) + strlen(buffer) + 1);
    if (!a) {
        printf("Eroare la alocarea dinamica de memorie !\n");
        exit(EXIT_FAILURE);
    }

    strcpy(a->marca, buffer);
    printf("Tip (P - persoane, altceva - marfa) : ");
    fgets(buffer, 100, stdin);
    if (toupper(buffer[0]) == 'P') {
        a->aux = tpers;
        printf("Nr. locuri : ");
        scanf("%d", &a->capacitate.locuri);
    }
    else {
        a->aux = tmarfa;
        printf("Tonaj : ");
        scanf("%lf", &a->capacitate.tonaj);
    }

    printf("Kilometri parcursi: ");
    scanf("%f", &a->km);

    Linii();

    printf("Diesel (D - da, altceva - nu) : ");
    fgets(buffer, 100, stdin);
    if (buffer[0] == 'D')
        a->diesel = 1;
    else
        a->diesel = 0;


    // afisare date
    printf("\n\nMarca: ");
    puts(a->marca);

    switch (a->aux)
    {
    case tpers:
        printf("Tipul : transport persoane\n");
        printf("Locuri: %d\n", a->capacitate.locuri);
    break;

    case tmarfa:
        printf("Tipul : transport marfa\n");
        printf("Tonaj: %2.f\n", a->capacitate.tonaj);
    default:
        break;
    }

    printf("Kilometri: %2.f\n", a->km);

    switch (a->diesel)
    {
    case 1:
        printf("Diesel\n");
    break;

    case 0:
        printf("Benzina\n");
    break;

    default:
        break;
    }

    free(a);

    getchar();
    return 0;
}
