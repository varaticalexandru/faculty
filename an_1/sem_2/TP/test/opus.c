#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void Opus(int* v, int n)
{
	int* p1 = NULL, * p2 = NULL;
	int aux;

	for (p1 = v; p1 < v + n; p1+=2)
	{
		for (p2 = v+n-1; p2 > p1; p2--)
		{
			*p2 = *(p2 - 1);
		}

		*p1 = -*(p1);
			
	}

}




int main(void)
{
	int* v = NULL;	
	int i;
	
	v = (int*)calloc(14, sizeof(int));

	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 4;
	v[4] = 5;
	v[5] = 6;
	v[6] = 7;

	Opus(v, 14);

	for (i = 0; i < 14; i++)
		printf("%d ", v[i]);

	_getch();
	return 0;
}