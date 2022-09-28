#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a, b, * ptr = NULL;

	printf("a: ");
	scanf("%d", &a);

	printf("b: ");
	scanf("%d", &b);

	ptr = (a > b) ? &a : &b;

	printf("Adresa variabilei cu valoarea maxima: %p\n", ptr);
	printf("Valoarea pointata de adresa: %d\n", *ptr);

	_getch();
	return 0;
}