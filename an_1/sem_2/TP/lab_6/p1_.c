#include <stdio.h>
union intreg_real
{
	int i;
	double r;
};
int main()
{
	// declar o variabila de tipul uniunii definite anterior ce va avea ca dimensiune maximul dintre dimens 
	campurilor
		union intreg_real u;
	printf(" un intreg va ocupa: %d\n", sizeof(int));
	printf("un real va ocupa: %d\n", sizeof(double));
	printf("un union va ocupa: %d\n", sizeof(union intreg_real));
	// Putem da valoare campului intreg dar valoarea campului real va ramane nespecificata, sau invers
	u.i = 100;
	printf("%d %lf\n", u.i, u.r);
	u.r = 12.12;
	printf("%d %lf\n", u.i, u.r);
	return 0;
}