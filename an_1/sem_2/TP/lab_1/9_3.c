#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

//  returneaza doua valori pe care le citeste de la tastatura, sortate in mod crescator
void Crescator(int* a1, int* a2)
{
	int max;

	if (*a1 > *a2)
	{
		max = *a1;
		*a1 = *a2;
		*a2 = max;
	}
}

int main(void)
{
	int a, b;

	printf("Introduceti 2 intregi: \n");
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);

	Crescator(&a, &b);
	printf("Variabilele in ordine crescatoare: %d %d\n", a, b);
	
	return 0;
}