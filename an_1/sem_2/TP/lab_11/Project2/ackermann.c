#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdint.h>


typedef long double ld;

ld ackermann(ld m, ld n)
{
	return (!m) ? (n + 1) : (!n) ? ackermann(m - 1, 1) : ackermann(m - 1, ackermann(m, n - 1));
}


int main(int argc, char** argv)
{

	ld i, j;

	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			printf("Ackermann(%.0lf, %.0lf): %.0lf\n", i, j, ackermann(i, j));

	return 0;
}