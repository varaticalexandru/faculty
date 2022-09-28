#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int HeapSpace(void)
{
	long double* ptr = NULL;
	int k = 0;

	// 8 * 10^6 bytes = 8 MB
	while ((ptr = (long double*)calloc(pow(10, 6), sizeof(long double))))
		k += 8;	// 8 MB
	free(ptr);
	
	return k;
}

int main(int argc, char** argv)
{
	printf("Capacitatea estimativa a zonei de memorie dinamica: %d bytes\n", HeapSpace());

	_getch();
	return 0;
}
