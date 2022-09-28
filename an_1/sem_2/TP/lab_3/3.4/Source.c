#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int v[] = { 7, -5, 4, 3, -9, 2, -8 }, * ptr = NULL, k = 0;

	for (ptr = v; ptr < v + 7; ptr++)
		if (*ptr < 0)
			k++;

	printf("In vector sunt %d elmenete negative\n", k);

	_getch();
	return 0;
}