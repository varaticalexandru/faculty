#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void BitwiseDisplay(int n)
{
	int i;

	printf("\n");

	for (i = 31; i >= 0; i--)
		((n >> i) & 1) ? printf("1") : printf("0");
	
	printf("\n");
}

// reprezentarea unui nr. natural in baza 2

int main(int argc, char** argv)
{
	int n;

	printf("Introduceti valoarea lui n: ");
	scanf("%d", &n);

	printf("\nReprezentarea binara a nr introdus:\n");
	BitwiseDisplay(n);

	printf("\n");
	_getch();

	return 0;
}