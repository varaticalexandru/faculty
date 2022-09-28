#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdarg.h>
void stelute(int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("*");
}
void spatii(int n) {
	int i;
	for (i = 0; i < n; i++)
		printf(" ");
	5
}
/* Functia are numar variabil de parametri. Putem avea si parametri ficsi, important este ca dupa
ultimul parametru fix sa apara caracterele '...'. In acest caz concret avem un singur parametru fix,
care va spune de fiecare data cati parametri variabili urmeaza. Parametri variabili vor fi numerele in
functie de care se afiseaza stelute sau spatii. */
void linie(int nr_param, ...) {
	/* Pentru a avea acces la parametri functiei, avem nevoie de o variabila de tipul "va_list". E
   necesar sa includem <stdarg.h> pentru asta. Practic aceasta variabila este un pointer care va indica
   rand pe rand catre parametri variabili ai functiei. */
	va_list ap;
	int i, n;
	/* Primul pas este sa initializam variabila de mai sus folosind macro-ul "va_start". Varibila se
	initializeaza relativ la ultimul parametru fix. In cazul nostru avem un singur parametru fix, deci
   nu avem de ales. */
	va_start(ap, nr_param);
	/* Parametri ficsi pot fi accesati direct, asa cum suntem obisnuiti. Noi folosim singurul parametru
   fix pentru a parcurge intr-o bucla parametri variabili. */
	for (i = 0; i < nr_param; i++) {
		/* Pentru a afla valoarea unui parametru variabil, folosim macro-ul "va_arg". La fiecare apel al
		acestui macro se returneaza un parametru variabil (cel spre care indica pointer-ul "ap" definit
	   mai sus). Dupa apel, in mod automat variabila "ap" este setata sa indice spre urmatorul parametru
	   variabil. */ n = va_arg(ap, int);
	   /* In functie de pozitiile pare sau impare afisam stelute sau spatii. */
	   if (i % 2 == 0)
		   stelute(n);
	   else
		   spatii(n);
	}
	/* Dupa ce am parcurs toti parametri variabili, apelam macro-ul "va_end". Acesta face operatii
   necesar pentru curatarea memoriei. */
	va_end(ap);
	printf("\n");
}
int main() {
	linie(3, 7, 3, 5);
	linie(7, 0, 3, 1, 6, 1, 4, 1);
	linie(7, 0, 3, 1, 6, 1, 5, 1);
	linie(7, 0, 3, 1, 6, 1, 5, 1);
	linie(7, 0, 3, 1, 6, 1, 4, 1);
	linie(5, 0, 3, 1, 6, 5);
	linie(5, 0, 3, 1, 6, 1);
	linie(5, 0, 3, 1, 6, 1);
	linie(5, 0, 3, 1, 6, 1);
	linie(5, 0, 3, 1, 6, 1);
	linie(5, 0, 3, 1, 6, 1);
	linie(5, 0, 3, 1, 6, 1);
	return 0;
}