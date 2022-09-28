#include <stdio.h>
#define tip_intreg 1
#define tip_real 2
union intreg_real
{
	int i;
	double r;
};
// definesc un struct care grupeaza o uniune cu variabila auxiliara
2
struct uniune_auxiliar
{
	char aux;
	union intreg_real u;
};
int main()
{
	struct uniune_auxiliar uaux;
	//dau valoare campului intreg "i" din uniune si actualizez campul “aux” iar apoi lui “r”
	uaux.u.i = 100;
	uaux.aux = tip_intreg;
	printf("%d %lf\n", uaux.u.i, uaux.u.r);
	uaux.u.r = 12.12;
	uaux.aux = tip_real;
	printf("%d %lf\n", uaux.u.i, uaux.u.r);
	return 0;
}