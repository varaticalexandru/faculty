#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// cautari
// 
//	    s              m                d
//		0  1  2  3  4  5  6  7  8  9 10 11
//		0 12 15 23 25 30 45 46 48 50 60 99
// 
// s = 0
// d = 11
// m = s+d/2 = 0+11/2 = 5
// cautam 6

// cautare interpolara
int CautareInterpolara(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	if (x >= a[s] && x <= a[d])
	{
		do {
			m = s + (x - a[s]) * (d - s) / (a[d] - a[s]);
			if (x > a[m])
				s = m + 1;
			else
				d = m - 1;
		} while (s < d && a[m] != x && x <= a[d] && x >= a[s] && a[d] != a[s]);
	}
	return m;
}

// cautare binara performanta
int CautareBinaraP(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	do {
		m = (s + d) / 2;
		if (x > a[m])
			s = m + 1;
		else
			d = m;

	} while (s <= d && a[m] != x);
	return d;
}


// cautare binara
int CautareBinara(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	do {
		m = (s + d) / 2;
		if (x > a[m])
			s = m + 1;
		else
			d = m - 1;

	} while (s <= d && a[m] != x);
	return m;
}


// tehnica fanionului
int TehnicaFanionului(int a[], int x, int n)
{
	int i = 0;	// index de parcurgere

	a[n] = x;
	while (a[i] != x)
		i++;

	return i;

}

// cautare liniara
int CautareLiniara(int a[], int x, int n)
{
	int i = 0;	// index de parcurgere

	while (a[i] != x && i < n)
		i++;

	return i;
}



// apel functie citire fisier
// afisati continutul lui a
// citire sau initializare pt x

int CitireFisier(int a[])
{
	FILE* f = NULL;
	int i = 0;

	if ((f = fopen("nr.txt", "rt")) == NULL)
		printf("Fisierul nu exista !\n");
	else
	while (!feof(f))
	{
		fscanf(f, "%d", &a[i]);
		i++;
	}

	fclose(f);

	return i;
}

int main(void)
{
	int a[20], n, x, p, i;
	
	n = CitireFisier(a);

	printf("Vectorul citit: \n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n\nLungimea vectorului: %d\n", n);

	printf("\nIntroduceti elementul cautat: ");
	scanf("%d", &x);

	printf("\nCautare Liniara");
	p = CautareLiniara(a, x, n);
	if (p < n)
		printf("\nPozitie: %d\n", p);
	else
		printf("Elementul nu exista in tablou\n");

	printf("\nTehnica Fanionului:");
	p = TehnicaFanionului(a, x, n);
	if (p < n)
		printf("\nPozitie: %d\n\n", p);
	else
		printf("Elementul nu exista in tablou\n");

	printf("Cautare Binara:");
	p = CautareBinara(a, x, n);
	if (p < n)
		printf("\nPozitie: %d\n\n", p);
	else
		printf("Elementul nu exista in tablou\n");

	printf("Cautare Binara Performanta:");
	p = CautareBinaraP(a, x, n);
	if (p < n)
		printf("\nPozitie: %d\n\n", p);
	else
		printf("Elementul nu exista in tablou\n");

	printf("Cautare Interpolara:");
	p = CautareInterpolara(a, x, n);
	if (p < n)
		printf("\nPozitie: %d\n\n", p);
	else
		printf("Elementul nu exista in tablou\n");

	return 0;
}