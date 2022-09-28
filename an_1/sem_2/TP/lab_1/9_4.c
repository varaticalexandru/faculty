#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int* AlocareVector(int n)
{	
	int i;
	int* ptr = NULL;

	ptr = (int*)calloc(n, sizeof(int));
	return ptr;
}

void CitireVector(int* v, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("v[%d]: ", i);
		scanf("%d", &v[i]);
	}
}

void EliberareVector(int* v)
{
	free(v);
}

// testeaza daca elementele a doi vectori sunt egale
int Egal(int* v1, int* v2, int n)
{
	int i;

	for (i = 0; i < n; i++)
		if (v1[i] != v2[i])
			return 0;

	return 1;
}


int main(void)
{
	int n;
	int* v1, v2;

	printf("Introduceti n: ");
	scanf("%d", &n);

	v1 = AlocareVector(n);
	v2 = AlocareVector(n);

	printf("\nIntroduceti elementele lui v1: \n");
	CitireVector(v1, n);

	printf("\nIntroduceti elementele lui v2: \n");
	CitireVector(v2, n);

	if (Egal(v1, v2, n))
		printf("\nElementele din v1 si v2 sunt egale !\n\n");
	else
		printf("\nElementele din v1 si v2 nu sunt egale !\n\n");

	EliberareVector(v1);
	EliberareVector(v2);

	_getch();
	return 0;
}
