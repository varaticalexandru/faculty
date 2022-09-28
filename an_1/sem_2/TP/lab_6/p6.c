#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct s{
	int ora;
	float temp;
} s;

s* AlocareStruct(int n)
{
	int* v = NULL;

	v = calloc(n, sizeof(s));
	if (!v) {
		printf("Eroare la alocarea dinamica de memorie!\n");
		exit(EXIT_FAILURE);
	}
	return v;
}

void Introducere(s* v, int n)
{
	int i;
}

// media temp. masurate in intervalul orar, inclusiv la capetele interv.

int main(int argc, char** argv)
{
	int n = 0;
	s* arr = NULL;

	printf("Introduceti n: ");
	scanf("%d", &n);

	arr = AlocareStruct(n);


	return 0;
}
