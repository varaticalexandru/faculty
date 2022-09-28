#define _CRT_SECURE_NO_WARNINGS

/* Generarea aranjamentelor de n elemente luate cate m, cu repetitie. */
#include <stdio.h>
#include <string.h>
int n, m;
char caractere[20];
int indici[20];
/* Functia de tiparire a solutiei in care se face asociere dintre pozitia generata si caracter. */
void tipareste() {
	int i;
	/* Tiparirea indicilor se realizeaza "de la m la 1" deoarece si generarea lor a început de pe pozitia m.
	 for (i = m - 1; i >= 0; i--)
	 printf("%c", caractere[indici[i]]);
	 printf("\n");
	}
	void aranj_r(int k){
	 int j;
	 /* Cand submultimea de prelucrat este vida, se tipareste solutia gasita pana in acest moment. */
	if (k == -1) {
		tipareste();
	else {
		/* Variabila j substituie caracterele pentru o mai usoara iterare. Pe pozitia data de indicele k
		 punem pe rand fiecare caracter. */
		for (j = 0; j < n; j++) {
			indici[k] = j;
			/* Generarea submultimii se reduce la generarea unei alte submultimi avand un element mai
			 putin decat in etapa curenta. */
			aranj_r(k - 1);
		}
	}
	}
	int main() {
		int i;
		char buffer[21];
		/* Citire tablou de n caractere, unice si a m<=n. */
		printf("Caracterele? (unice, toate pe o linie, fara spatii) ");
		fgets(buffer, 21, stdin);
		buffer[strlen(buffer) - 1] = 0;
		n = strlen(buffer);
		for (i = 0; i < n; i++)
			caractere[i] = buffer[i];
		printf("am citit %d caractere: ", n);
		for (i = 0; i < n; i++)
			printf("%c", caractere[i]);
		printf("\n");
		do {
			printf("m? ");
			scanf("%d", &m);
		} while ((m <= 0) || (m > n));
		3
			/* Apelul functiei recursive. Pornim de la ultima pozitie (indice m-1). Apelurile recursive ne vor
			duce spre indicii mai mici. */
			aranj_r(m - 1);
		return 0;
	}