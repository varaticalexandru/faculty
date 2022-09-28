#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

float* AlocareVector(int n)
{
	float* v = (float*)calloc(n, sizeof(float));
	return v;
}

void CitireVector(float* V, int k)
{
	int i;

	printf("Introduceti valorile vectorului V:\n");
	for (i = 0; i < k; i++)
	{
		printf("V[%d]: ", i);
		scanf("%f", &V[i]);
	}

	printf("\n");
}

void AfisareVector(float* V, int k)
{
	int i;

	for (i = 0; i < k; i++)
		printf("%.2f ", V[i]);
	printf("\n");
}

void EliberareVector(int* V)
{
	free(V);
}

// returneaza indecsul elementului minim din vector
int Min(int* V, int n)
{
	int i, min, min_id;

	min_id = 0;
	min = V[0];
	for (i = 1; i < n; i++)
		if (V[i] < min)
		{
			min = V[i];
			min_id = i;
		}
			
	return min_id;
}

// returneaza indecsul elementului maxim din vector
int Max(int* V, int n)
{
	int i, max, max_id;

	max_id = 0;
	max = V[0];
	for (i = 1; i < n; i++)
		if (V[i] > max)
		{
			max = V[i];
			max_id = i;
		}

	return max_id;
}

int main(void)
{
	int i, n;
	float* V;

	printf("Introduceti dimensiunea vectorului n: ");
	scanf("%d", &n);

	V = AlocareVector(n);
	CitireVector(V, n);

	printf("Index-ul elementului minim din vector: %d\n", Min(V, n));
	printf("Index-ul elementului maxim din vector: %d\n", Max(V, n));

	EliberareVector(V);

	_getch();
	return 0;
}