#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


typedef struct Drept {
	int l;	// latime
	int h;	// inaltime
} Drept;

int main(void)
{
	int nr, i, *arr_s = NULL, max_id = -1, max_s = -1;
	Drept* arr = NULL;

	printf("Introduceti nr : "); scanf("%d", &nr);

	arr = (Drept*)calloc(nr, sizeof(Drept));
	if (!arr) {
		printf("Eroare la alocarea dinamica de memorie !\n");
		exit(EXIT_FAILURE);
	}

	arr_s = (int*)calloc(nr, sizeof(int));
	if (!arr_s) {
		printf("Eroare la alocarea dinamica de memorie !\n");
		exit(EXIT_FAILURE);
	}

	printf("\n");
	for (i = 0; i < nr; i++)
	{
		printf("Dreptunghiul %d:\n", i);
		printf("Latime: "); scanf("%d", &(arr[i].l));
		printf("Inaltime: "); scanf("%d", &(arr[i].h));
		arr_s[i] = arr[i].l * arr[i].h;
		printf("Arie[%d]:  %d\n", i, arr_s[i]);
		if (arr_s[i] > max_s) {
			max_s = arr_s[i];
			max_id = i;
		}

		printf("\n");
	}

	printf("Componentele triunghiului cu arie maxima:\n");
	printf("Indexul: %d\n", max_id);
	printf("Latimea: %d\n", arr[max_id].l);
	printf("Inaltimea: %d\n", arr[max_id].h);

	_getch();
	return 0;
}