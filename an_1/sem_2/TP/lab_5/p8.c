#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct elev {
	char nume[30];
	int data_nasterii[3];
} elev;

void EroareAlocare(void)
{
	printf("Eroare la alocara dinamica de memorie!\n");
	exit(EXIT_FAILURE);
}

void StructSwap(elev* s1, elev* s2)
{
	elev aux = *s1;
	*s1 = *s2;
	*s2 = aux;
}

elev* AlocareStruct(int n)
{
	elev* v = NULL;

	v = (elev*)calloc(n, sizeof(elev));
	if (!v)
		EroareAlocare();

	return v;
}

void AfisareStruct(elev* v, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("[%d] : %10s \t %d/%d/%d\n", i, v[i].nume, v[i].data_nasterii[0], v[i].data_nasterii[1], v[i].data_nasterii[2]);
	}
	printf("\n");
}

void CitireStruct(elev* v, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("\nElev[%d]:\n", i);
		printf("Nume: "); 
		getchar();
		gets(v[i].nume);
		printf("Data nasterii: "); scanf("%d %d %d", &v[i].data_nasterii[0], &v[i].data_nasterii[1], &v[i].data_nasterii[2]);
	}
	printf("\n");
}

void EliberareStruct(elev* v)
{
	free(v);
}

void BubbleSort(elev* v, int n)
{
	int i, ok;

	do
	{
		ok = 1;
		for (i = 1; i < n; i++)
			if (strcmp(v[i - 1].nume, v[i].nume) > 0) {
				ok = 0;
				StructSwap(&v[i - 1], &v[i]);
			}
	} while (!ok);
	
}

void SelectionSort(elev* v, int n)
{
	int i, j, k_min;
	elev aux;

	for (i = 0; i < n - 1; i++)
	{
		k_min = i;

		for (j = i + 1; j < n; j++)
			if (strcmp(v[j].nume, v[i].nume) < 0)
				k_min = j;

		StructSwap(&v[i], &v[k_min]);
	}
}

void InsertionSort(elev* v, int n)
{
	int i, j;
	elev aux;

	for (i = 1; i < n; i++)
	{
		j = i - 1;
		aux = v[i];

		// shift la dreapta toate elem > aux
		while (j >= 0 && strcmp(v[j].nume, aux.nume) > 0) {
			v[j + 1] = v[j];
			j--;
		}

		v[j + 1] = aux;
	}
}

int Partition(elev* v, int low, int high)
{
	int i, j;
	elev pivot;

	pivot = v[high];
	i = low - 1;		// greater elem.

	for (j = low; j < high; j++)
		if (strcmp(pivot.nume, v[j].nume) >= 0) {
			i++;
			StructSwap(&v[i], &v[j]);
		}

	StructSwap(&v[i + 1], &v[high]);

	return i + 1;	// partition position
}

void QuickSort(elev* v, int low, int high)
{
	int pi;	// partition index

	if (low < high) {
		pi = Partition(v, low, high);
		QuickSort(v, low, pi - 1);
		QuickSort(v, pi + 1, high);
	}
}

void CocktailSort(elev* v, int n)
{
	int i, s, d, k;
	
	s = 1;
	d = n - 1;

	do
	{
		// la stanga
		for (i = d; i >= s; i--)
			if (strcmp(v[i - 1].nume, v[i].nume) > 0) {
				StructSwap(&v[i - 1], &v[i]);
				k = i;	// retinem ultima interschimbare
			}

		s = k + 1;

		// la dreapta
		for (i = s; i <= d; i++)
			if (strcmp(v[i - 1].nume, v[i].nume) > 0) {
				StructSwap(&v[i], &v[i - 1]);
				k = i;	// retinem ultima interschimbare
			}

		d = k - 1;

	} while (s <= d);
		
}

void Merge(elev* v, int l, int m, int r)
{
	int i, j, k, n1, n2;
	elev* L = NULL, * R = NULL;

	n1 = m - l + 1;		// NumEl(L)
	n2 = r - m;			// NumeEl(R)

	// temp arrays
	L = AlocareStruct(n1);
	R = AlocareStruct(n2);

	// copy data to temp arrays L[], R[]
	for (i = 0; i < n1; i++)
		L[i] = v[l + i];

	for (j = 0; j < n2; j++)
		R[j] = v[m + j + 1];

	// merge L[], R[] back to v[l..r]
	j = 0;
	i = 0;
	k = l;
	
	while (i < n1 && j < n2) {
		if (strcmp(L[i].nume, R[j].nume) <= 0) {
			v[k] = L[i];
			i++;
		}
		else {
			v[k] = R[j];
			j++;
		}
		k++;
	}

	// copy the remaining elem. of L[], if there are any
	while (i < n1) {
		v[k] = L[i];
		i++;
		k++;
	}

	// copy the remaining elem. of R[], if there are any
	while (j < n2) {
		v[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(elev* v, int l, int r)
{
	int m;

	if (l < r) {
		m = l + (r - l) / 2;

		QuickSort(v, l, m);
		QuickSort(v, m + 1, r);

		Merge(v, l, m, r);
	}
}

int main(int argc, char** argv)
{
	int i, n;
	elev* v = NULL;

	printf("Introduceti nr. de elevi: "); scanf("%d", &n);
	v = AlocareStruct(n);
	
	CitireStruct(v, n);

	printf("\nStrucura de elevi initiala: \n");
	AfisareStruct(v, n);

	printf("\nStrucura de elevi sortata lexicografic: \n");
	MergeSort(v, 0, n - 1);
	AfisareStruct(v, n);


	EliberareStruct(v);

	_getch();
	return 0;
}