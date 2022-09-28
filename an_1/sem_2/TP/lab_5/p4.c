#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


float Distanta(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}


typedef struct Punct {
	float a;	
	float b;	
} Punct;

int main(void)
{
	int nr, i, j;
	Punct* arr = NULL;
	float dist = -1, dist_min = +INT_MAX;

	printf("Introduceti nr : "); scanf("%d", &nr);

	arr = (Punct*)calloc(nr, sizeof(Punct));
	if (!arr) {
		printf("Eroare la alocarea dinamica de memorie !\n");
		exit(EXIT_FAILURE);
	}

	printf("\n");
	for (i = 0; i < nr; i++)
	{
		printf("Punctul %d:\n", i);
		printf("a: "); scanf("%f", &(arr[i].a));
		printf("b: "); scanf("%f", &(arr[i].b));

		if (i>=1)
			for (j = i; j > 0; j--) {
				dist = Distanta(arr[i].a, arr[i].b, arr[i - 1].a, arr[i - 1].b);
				if (dist < dist_min)
					dist_min = dist;
			}
		printf("\n");
	}

	printf("Distanta minima dintre cele mai apropiate 2 puncte: %2.f\n", dist_min);

		
	_getch();
	return 0;
}