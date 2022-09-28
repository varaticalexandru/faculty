#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct stat {
	int h;
	float t;
} stat;

void EroareAlocare(void)
{
	printf("Eroare la alocarea dinamica de memorie !\n");
	exit(EXIT_FAILURE);
}

stat* AlocareStruct(int n)
{
	stat* v = NULL;
	int i;
	
	v = calloc(n, sizeof(stat));
	if (!v)
		EroareAlocare();

	return v;
}

void CitireStruct(stat* v, int n)
{
	int i;

	for (i = 0; i < n; i++)
		v[i].h = i;
	
	for (i = 0; i < n; i++) {
		printf("temperatura[%d]: ", i);
		scanf("%f", &v[i].t);
	}

	printf("\n");
}

void AfisareStruct(stat* v, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("ora [%d] : %4d  %4.2f\n", i, v[i].h, v[i].t);
	
	printf("\n");
}

void EliberareStruct(stat* v)
{
	free(v);
}

float TempMed(stat* v, int h1, int h2)
{
	int i;
	float sum = 0.0;

	for (i = h1; i <= h2; i++)
		sum += v[i].t;

	return sum / (float)(h2 - h1 + 1);
}

int main(int argc, char** argv)
{
	int i, n, h1, h2;
	stat* v = NULL;

	printf("Introduceti nr. de ore: ");
	scanf("%d", &n);

	printf("Introduceti ora de start: "); scanf("%d", &h1);
	printf("Introduceti ora de finis: "); scanf("%d", &h2);

	v = AlocareStruct(v);
	
	CitireStruct(v, n);

	AfisareStruct(v, n);

	printf("Temperatura media in intervalul orar h1-h2 : %.2f\n", TempMed(v, h1, h2));

	//EliberareStruct(v);

	_getch();
	return 0;
}