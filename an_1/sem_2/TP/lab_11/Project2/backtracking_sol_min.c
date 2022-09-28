#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <limits.h>

// cautarea solutiei de lungime minima

// definire labirint
#define LMAX 100
char lab[LMAX][LMAX];
int nLab;
int startI, startJ;

// definire traseu
#define TMAX 100
int traseuI[TMAX];
int traseuJ[TMAX];
int nTraseu;
int nSol;

// definire traseu min.
int traseuIMin[TMAX], traseuJMin[TMAX];
int nTraseuMin = INT_MAX;

// cant. de adaugat la poz. cur. (i, j) pentru o deplasare in alta celula
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void CitesteLabirint(const char* nume_fisier)
{
	int i, j;
	char linie[LMAX + 1];
	FILE* f = fopen(nume_fisier, "rt");
	if (!f) {
		printf("Eroare la deschiderea fisierului !\n");
		exit(EXIT_FAILURE);
	}

	fscanf(f, "%d", &nLab);
	fscanf(f, "%d %d", &startI, &startJ);

	
	fgets(linie, LMAX, f);		// consuma '\n' dupa startJ

	for (i = 0; i < nLab; i++) {
		fgets(linie, LMAX, f);
		for (j = 0; j < nLab; j++)
			lab[i][j] = linie[j];
	}

	fclose(f);
}

void AfiseazaLabirint(void)
{
	int i, j;

	for (i = 0; i < nLab; i++) {
		for (j = 0; j < nLab; j++)
			printf("%c", lab[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void Solutie(void)
{
	// copiaza traseu in traseuMin

	int k;
	
	for (k = 0; k < nTraseu; k++) {
		traseuIMin[k] = traseuI[k];
		traseuJMin[k] = traseuJ[k];
	}
	
	nTraseuMin = nTraseu;
}

void Cauta(int i, int j)		// (i, j) - poz. cur.
{
	int k;

	// verifica daca e posibila o solutie mai buna decat cea gasita deja
	if (nTraseuMin == nTraseu)
		return;

	// verifica daca poz. cur este valida si disponibila
	if (i < 0 || i >= nLab || j < 0 || j >= nLab)
		return;
	if (lab[i][j] != '.')
		return;

	// adauga poz. cur. la traseu (calea cur.)
	traseuI[nTraseu] = i;
	traseuJ[nTraseu] = j;
	lab[i][j] = '0' + nTraseu % 10;

	nTraseu++;

	// test. daca e sol.
	if (i == 0 || i == nLab - 1 || j == 0 || j == nLab - 1)
		Solutie();
	else {
		for (k = 0; k < 4; k++)
			Cauta(i + di[k], j + dj[k]);
	}

	// eliminare poz. cur din traseu
	nTraseu--;
	lab[i][j] = '.';
}


int main(int argc, char** argv)
{
	CitesteLabirint("labirint.txt");

	printf("Labirint initial: \n");
	AfiseazaLabirint();
	putchar('\n');
	
	Cauta(startI, startJ);

	if (nTraseuMin == INT_MAX)
		printf("Nu exista solutie !\n");
	else {
		int k;
		printf("Solutia minima\nLungime : %d\nTraseu : ", nTraseuMin);
		for (k = 0; k < nTraseuMin; k++) {
			printf("(%d %d) ", traseuIMin[k], traseuJMin[k]);
			// refacerea traseului in labirint (matrice)
			lab[traseuIMin[k]][traseuJMin[k]] = '0' + k % 10;
		}
		printf("\n\n");
		AfiseazaLabirint();
	}

	_getch();
	return 0;
}