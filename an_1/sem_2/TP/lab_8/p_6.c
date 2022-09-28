#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void EroareDeschidereFisier(void)
{
	printf("Eroare la deschiderea fisierului !\n");
	exit(EXIT_FAILURE);
}

void EroareAlocareDinamica(void)
{
	printf("Eroare la alocarea dinamica !\n");
	exit(EXIT_FAILURE);
}

void AfisareVector(float* a, int n)
{
	printf("\n");

	for (int i = 0; i < n; i++)
		printf("%.2f\n", a[i]);
	
	printf("\n");
}

void EliberareVector(float* a)
{
	free(a);
}

float* RealocareVector(float* a, int n)
{
	float* aux = NULL;
	
	aux = (float*)realloc(a, (n + 1) * sizeof(float));
	if (!aux)
		EroareAlocareDinamica();

	return aux;
}

float Indexare(float x)
{
	return (1.15 * x);
}

int main(int argc, char** argv)
{
	FILE* in = NULL, * out = NULL;
	float* a = NULL;
	int n = 0;
	float buffer;

	if((in = fopen("in.txt", "rt")) == NULL)
		EroareDeschidereFisier();

	if ((out = fopen("indexate.txt", "wt")) == NULL)
		EroareDeschidereFisier();

	while ((fscanf(in, "%f", &buffer)) != EOF) {
		a = RealocareVector(a, &n);
		if (buffer < 1000)
			a[n] = Indexare(buffer);
		else
			a[n] = buffer;
		fprintf(out, "%.2f\n", a[n]);
		n++;
	}

	fclose(in);
	fclose(out);

	AfisareVector(a, n);
	EliberareVector(a);

	_getch();
	return 0;
}