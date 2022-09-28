#include <stdio.h>
// o uniune care poate pastra fie un int fie un double
union int_sau_double {
	int n;
	double d;
};
int main(void)
{
	// O variabila de tipul uniunii definite mai sus.
	union int_sau_double u;
	// dimensiunea ocupata de uniune este maximul dintre dimensiunile campurilor sale.
	printf("dimensiune int: %d\n", sizeof(int));
	printf("dimensiune double: %d\n", sizeof(double));
	printf("dimensiune union: %d\n", sizeof(union int_sau_double));
	// daca atribuim valoare campului int, valoarea campului double devine nespecificata.
	u.n = -101;
	printf("%d %lg\n", u.n, u.d);
	// daca atribuim valoare campului double, valoarea campului int devine nespecificata.
	u.d = 77.12;
	printf("%d %lf\n", u.n, u.d);
	return 0;
}