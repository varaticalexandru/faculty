#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>

// cautarea tuturor solutiilor posibile

// definirea labirintului
#define LMAX 100    // dimens. max. pe o coordonata

/*
    semnificatiile unei celule:
    '.' - locatie libera
    '#' - zid
    alte caractere - locatii de pe traseu
*/

char lab[LMAX][LMAX];   // labirint
int nLab;               // latimea, lungime
int startI, startJ;     // p. de pornire

// citeste labirint
void CitireLabirint(const char* nume_fisier)
{
    char linie[LMAX + 1];
    int i, j;

    FILE* fis = fopen(nume_fisier, "rt");
    if (!fis) {
        printf("\nFisierul %s nu poate fi deschis !\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fis, "%d", &nLab);
    fscanf(fis, "%d %d", &startI, &startJ);

    fgets(linie, LMAX, fis);    // consuma \n de dupa startJ
    for (i = 0; i < nLab; i++) {
        fgets(linie, LMAX, fis);
        for (j = 0; j < nLab; j++)
            lab[i][j] = linie[j];
    }
    fclose(fis);
}

// afiseaza labirint
void AfiseazaLabirint(void)
{
    int i, j;
    for (i = 0; i < nLab; i++) {
        for (j = 0; j < nLab; j++)
            putchar(lab[i][j]);
        putchar('\n');
    }
}

#define TMAX 1000   // lungime maxima traseu
int traseuI[TMAX], traseuJ[TMAX];   // coord. (i, j) ale punctelor de pe traseu
int nTraseu;                        // lungime traseu
int nSolutii;                       // nr. sol.

// delta i, j = cant. de adaugat la poz. cur. (i, j) pentru a obtine noua poz.
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

// afiseaza solutia
void Solutie(void)
{
    int k;
    FILE* f = fopen("solutii.txt", "a");
    if (!f) {
        printf("Eroare la deschiderea fisierului !\n");
        exit(EXIT_FAILURE);
    }
    fputc('\n', f);


    nSolutii++;
    printf("Solutia %d, lungime %d: ", nSolutii, nTraseu);
    fprintf(f, "Solutia %d, lungime %d: ", nSolutii, nTraseu);
    for (k = 0; k < nTraseu; k++) {
        printf("(%d, %d) ", traseuI[k], traseuJ[k]);
        fprintf(f, "(%d, %d) ", traseuI[k], traseuJ[k]);
    }

    fputc('\n', f);

    putchar('\n');
    AfiseazaLabirint();
    putchar('\n');

    fclose(f);
}

// cauta toate solutiile
void Cauta(int i, int j)        // (i, j) - poz. cur.
{
    // revenire daca poz. cur. nu e valida
    if (i < 0 || i >= nLab || j < 0 || j >= nLab)     // daca e in afara labirintului
        return;
    if (lab[i][j] != '.')                           // daca nu e libera (e in calea curenta)
        return;

    // adauga poz. cur. la traseu
    traseuI[nTraseu] = i;
    traseuJ[nTraseu] = j;
    lab[i][j] = '0' + nTraseu % 10;                 // setare poz. ocupata
    nTraseu++;

    if (!i || i == nLab - 1 || !j || j == nLab - 1) {   // test. daca e sol.
        Solutie();
    }
    else {                                          // daca nu e sol., incearca toate var. posibile
        int k;
        for (k = 0; k < 4; k++)
            Cauta(i + di[k], j + dj[k]);
    }

    // sterge poz. cur. din traseu
    nTraseu--;
    lab[i][j] = '.';
}




/*
    Backtracking (pseudocode) :

    functie cauta (poz_cur)
    {
        daca (poz_cur != valid || poz_cur in calea_cur)
            revenire;

        adauga poz_cur la calea_cur;

        daca (poz_cur = solutie)
            afiseaza_solutie();
        altfel
            pentru fiecare poz_urm la care se poate ajunge din poz_cur
                cauta(poz_urm);

        sterge poz_cur din calea_cur;
    }
*/




int main(int argc, char** argv)
{

    CitireLabirint("labirint.txt");
    printf("Labirint initial:\n");
    AfiseazaLabirint();
    printf("\n\n");

    Cauta(startI, startJ);
    printf("\nNr. de solutii: %d\n", nSolutii);

    _getch();
    return 0;
}