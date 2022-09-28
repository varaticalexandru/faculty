#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

typedef struct sfera {
            float r;
        } sfera;


typedef struct con {
            float r;
            float h;
        } con;

typedef union dimensiuni {

    sfera S;
    con C;

} dimensiuni;


typedef struct {
    char tip_figura;    // S - sfera (raza), C - con (raza, inaltime)

    dimensiuni d;

    float v;

} figura;


float VolumSfera(float r)
{
    return (float)(4*M_PI*r*r*r)/(float)3;
}

float VolumCon(float r, float h)
{
    return (float)(M_PI*r*r*h)/(float)3;
}

int main(int argc, char** argv)
{
    figura arr[10];
    int i, n;
    char c;

    printf("Introduceti numarul de figuri geometrice: ");
    scanf("%d", &n);

    printf("\n\nIntroduceti datele pentru cele %d figuri:\n\n");
    for (i = 0; i < n; i++) {
        printf("[%d]:\n", i);
        printf("\tTip figura: ");
        getchar();
        c = getchar();
        if (c == 'S') {
            printf("\ttRaza sferei : ");
            scanf("%f", &arr[i].d.S.r);
            arr[i].v = VolumSfera(arr[i].d.S.r);
            printf("\tVolumul sferei : %.2f\n\n", arr[i].v);
        }
        else if (c == 'C') {
            printf("\tRaza conului : ");
            scanf("%f", &arr[i].d.C.r);
            printf("\tInaltimea conului : ");
            scanf("%f", &arr[i].d.C.h);
            arr[i].v = VolumCon(arr[i].d.C.r, arr[i].d.C.h);
            printf("\tVolumul conului : %.2f\n\n", arr[i].v);
        }
        else {
            printf("\nEroare ! Tip nedefinit !\n");
            i--;
        }
    }







    _getch();
    return 0;
}
