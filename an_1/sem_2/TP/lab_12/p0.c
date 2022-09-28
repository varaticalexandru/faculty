#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
int main() {
	long i, j;
	double timp_total;
	/* Tipul clock_t reprezinta un numar de cicluri de ceas al procesorului */
	clock_t t1, t2;
	/* Functia clock() returneaza numarul de cicluri de ceas scurse de la un moment arbitrar fix. */
	t1 = clock();
	/* Aici se efectueaza operatiile pentru care dorim sa masuram timpul de executie. Pentru acest
	exemplu nu facem decat sa parcurgem doua bucle for, pentru a consuma ceva timp. */
	for (i = 0; i < 25000; i++)
		for (j = 0; j < 25000; j++);
	/* Citim din nou numarul de cicluri de ceas ale procesorului, fata de acelasi moment arbitrar fix. */
	t2 = clock();
	/* Valoarea returnata de macroul CLOCKS_PER_SEC este frecventa de ceas a procesorului. In
   functie de aceasta valoare si de diferenta celor doua valori
   pastrate in t1 si t2 calculam timpul total de executie in secunde. */
	timp_total = (double)(t2 - t1) / (double)CLOCKS_PER_SEC;
	printf("timpul de executie = %.3lf secunde\n", timp_total);
	return 0;
}
