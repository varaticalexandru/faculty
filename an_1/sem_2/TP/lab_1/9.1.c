#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// aplicatia 9.1
// se cere n > 4, n - impar
// sa se deseneze cifra "8" ca un patrat cu o linie orizontala in mijloc
// pe verticala si orizontala - cate n stelute
// nu sunt admise duplicari

void Linie(int n, int orientare)
{
	int i, j;
	
	switch (orientare)
	{
		// orizontal
		case 0:
		{
			for (i = 0; i < n; i++)
				printf("* ");
			printf("\n");
		}
		break;

		// vertical
		case 1:
		{
			for (i = 0; i < (n/2)-1; i++)
			{
				printf("* ");
				for (j = 0; j < n - 2; j++)
					printf("  ");
				printf("*\n");
			}
		}
		break;

		default:
		break;
	}


	printf("\n");
}



int main(void)
{
	int n, ok;

	ok = 0;
	do
	{
		printf("Introduceti nr. de stelute : ");
		scanf("%d", &n);
		if (n > 4 && ((n % 2) != 0)) {
			ok = 1;
		}
		printf("\n");
	} while (ok != 1);

	Linie(n, 0);
	Linie(n, 1);
	Linie(n, 0);
	Linie(n, 1);
	Linie(n, 0);

	_getch();
	return 0;
}