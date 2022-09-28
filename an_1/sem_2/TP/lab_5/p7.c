#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

typedef struct factor {
	int f;
	int p;
} factor;

void EroareAlocare(void)
{
	printf("Eroare la alocara dinamica de memorie!\n");
	exit(EXIT_FAILURE);
}

factor* RealocareStruct(factor* v, int n)
{
	factor* aux = NULL;
	
	aux = (factor*)realloc(v, (n+1)*sizeof(factor));
	if (!aux)
		EroareAlocare();

	return aux;
}

factor* PrimeFactors(factor* v,int n, int* nr)
{
	int i, c, flag;
	factor* aux = NULL;

	aux = v;

	c = 2;
	while (n > 1) {
		flag = 0;
		if (n % c == 0) {

			//printf("%d ", c);
			for (i = 0; i < *nr; i++)
				if (aux[i].f == c) {
					aux[i].p += 1;
					flag = 1;
					break;
				}
					
			if (flag) {
				n /= c;
				continue;
			}
				
			
			aux = RealocareStruct(aux, *nr);
			aux[*nr].f = c;
			aux[*nr].p = 1;
			n /= c;
			(*nr)++;
		}
		else
			c++;
	}

	return aux;
}

void AfisareStruct(factor* v, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("[%d] : %d ^ %d\n", i, v[i].f, v[i].p);
	}
	printf("\n");
}


int main(int argc, char** argv)
{
	int i, n, nr = 0;
	factor* v = NULL;

	printf("n : "); scanf("%d", &n);

	v = PrimeFactors(v, n, &nr);

	printf("\nFactorizarea prima a nr. '%d' : \n", n);
	AfisareStruct(v, nr);


	_getch();
	return 0;
}