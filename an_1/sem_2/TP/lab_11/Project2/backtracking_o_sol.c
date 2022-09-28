#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <limits.h>

// cautarea unei singure solutii

// definirea labirintului
#define LMAX 1000
int lab[LMAX][LMAX];
int nLab;
int startI, startJ;


// definire traseu
#define TMAX 100
int traseuI[TMAX], traseuJ[TMAX];
int nTraseu;


// definire delta i, delta j
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void AfisareLabirint(void)
{
	int i, j;

	for (i = 0; i < nLab; i++)
	{
		for (j = 0; j < nLab; j++)
			printf("%c", lab[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void CitireLabirint(const char* nume_fisier)
{
	char linie[LMAX + 1];
	int i, j;

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

void Solutie(void)
{
	int k;

	printf("Solutie\nLungime : %d\nTraseu : \n", nTraseu);
	for (k = 0; k < nTraseu; k++) {
		printf("(%d %d) ", traseuI[k], traseuJ[k]);
	}

	AfisareLabirint();

	putchar('\n');
}

int Cauta(int i, int j)		// (i, j) - poz. cur.
{
	// daca nu trece testele de validitate, inseamna ca inca nu s-a gasit o solutie => return 0
	if (i < 0 || i >= nLab || j < 0 || j >= nLab)
		return 0;
	if (lab[i][j] != '.')
		return 0;

	// adaugare poz. cur. in traseu
	traseuI[nTraseu] = i;
	traseuJ[nTraseu] = j;
	lab[i][j] = '0' + nTraseu % 10;
	nTraseu++;

	// test daca e sol.
	if (i == 0 || i == nLab - 1 || j == 0 || j == nLab - 1) {
		Solutie();
		return 1;
	}
	else {
		int k;
		for (k = 0; k < 4; k++)
			// daca pt. oricare din variante s-a gasit o sol. => return 1
			if (Cauta(i + di[k], j + dj[k]))
				return 1;
	}

	// stergere poz. cur. din traseu
	nTraseu--;
	lab[i][j] = '.';

	return 0;
}


int main(int argc, char** argv)
{
	CitireLabirint("labirint.txt");
	printf("Labirint initial :\n");
	AfisareLabirint();

	putchar('\n');

	if (!Cauta(startI, startJ))
		printf("Nu s-a gasit nici o solutie !\n");

	_getch();
	return 0;
}