#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void IntSwap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main(void)
{
	int a, b, * ptr = NULL;

	printf("Initial: \n");
	printf("a: ");
	scanf("%d", &a);

	printf("b: ");
	scanf("%d", &b);

	IntSwap(&a, &b);
	printf("Dupa interschimbare: \n");
	printf("a: %d\n", a);
	printf("b: %d\n", b);

	_getch();
	return 0;
}