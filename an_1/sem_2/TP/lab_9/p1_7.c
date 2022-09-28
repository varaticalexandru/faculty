#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


// n1, n2 - nr. naturale (0..255)
// n - unsigned short
// n = n1*256 + n2




int main(int argc, char** argv)
{
	unsigned int n, n1, n2;

	printf("Introduceti n1: ");
	scanf("%d", &n1);

	printf("Introduceti n2: ");
	scanf("%d", &n2);

	n = n1 * 256 + n2;

	printf("\nn: %d\n", n);
	printf("\nn1: %d\n", n >> 8);
	printf("\nn2: %d\n", n % 256);
	
	printf("\n");

	_getch();
	return 0;
}