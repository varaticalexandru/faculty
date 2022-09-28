#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int Vowel(char* c)
{
	if (*c == 'a' || *c == 'A') return 0;
	if (*c == 'e' || *c == 'E') return 1;
	if (*c == 'i' || *c == 'I') return 2;
	if (*c == 'o' || *c == 'O') return 3;
	if (*c == 'u' || *c == 'U') return 4;
	return -1;
}

int* AlocareVector(int n)
{
	int* p = NULL;
	p = (int*)calloc(n, sizeof(int));
	if (!p) {
		printf("Eroare la alocarea dinamica de memorie !\n");
		exit(1);
	}

	return p;
}

int* VowelCount(char* s)
{
	int* v = NULL;
	v = AlocareVector(5, sizeof(int));

	for (; *s; s++) {
		if (Vowel(s) != -1)
			v[Vowel(s)]++;
	}

	return v;
}

void AfisareVector(int* v, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		if (!i) printf("a: %d\n", v[i]);
		if (i == 1) printf("e: %d\n", v[i]);
		if (i == 2) printf("i: %d\n", v[i]);
		if (i == 3) printf("o: %d\n", v[i]);
		if (i == 4) printf("u: %d\n", v[i]);
	}

	printf("\n");
}

int* Suma(int* v1, int* v2, int n)
{
	int* v_suma = NULL, i;

	v_suma = AlocareVector(n);
	for (i = 0; i < n; i++)
		v_suma[i] = v1[i] + v2[i];

	return v_suma;
}

void Max(int* v, int n)
{
	int i, max = v[0], max_id = 0;

	for (i = 0; i < n; i++)
		if (v[i] > max) {
			max = v[i];
			max_id = i;
		}

	if (!max_id) printf("Cea mai des intalnita vocala in ambele texte: a, cu %d aparitii\n", max);
	if (max_id == 1) printf("Cea mai des intalnita vocala in ambele texte: e, cu %d aparitii\n", max);
	if (max_id == 2) printf("Cea mai des intalnita vocala in ambele texte: i, cu %d aparitii\n", max);
	if (max_id == 3) printf("Cea mai des intalnita vocala in ambele texte: o, cu %d aparitii\n", max);
	if (max_id == 4) printf("Cea mai des intalnita vocala in ambele texte: u, cu %d aparitii\n", max);

}

// vocala/vocalele care apar de cele mai multe ori in 2 texte citite de la tastatura

int main(void)
{
	char t1[100], t2[100];
	int* v1 = NULL, * v2 = NULL, *v_suma = NULL;

	printf("Introduceti textul 1: \n");
	gets(t1);
	v1 = VowelCount(t1);
	printf("\nVectorul distribuitiei vocalelor: \n");
	AfisareVector(v1, 5);

	printf("Introduceti textul 2: \n");
	gets(t2);
	v2 = VowelCount(t2);
	printf("\nVectorul distribuitiei vocalelor: \n");
	AfisareVector(v2, 5);

	v_suma = Suma(v1, v2, 5);
	printf("\nVectorul distribuitiei totale a vocalelor: \n");
	AfisareVector(v_suma, 5);

	Max(v_suma, 5);

	_getch();
	return 0;
}