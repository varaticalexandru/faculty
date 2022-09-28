// cautarea solutiei de lungime minima
#include <limits.h>
...
int traseuIMin[TMAX], traseuJMin[TMAX]; // coordonatele (i,j) ale punctelor de pe traseul minim
int nTraseuMin = INT_MAX; // lungimea traseului minim
void solutie()
{
	int k;
	for (k = 0; k < nTraseu; k++) {
		traseuIMin[k] = traseuI[k];
		traseuJMin[k] = traseuJ[k];
	}
	nTraseuMin = nTraseu;
}
// cauta toate solutiile
void cauta(int i, int j) // (i,j) - pozitia curenta
{
	if (nTraseu == nTraseuMin)return; // daca nu mai sunt sanse pentru o solutie mai buna, revenire
	...
}
int main()
{
	citire("lab.txt");
	cauta(startI, startJ);
	if (nTraseuMin == INT_MAX) {
		printf("nu exista solutie");
	}
	else {
		int k;
		printf("Solutia minima are lungimea %d si este compusa din:", nTraseuMin);
		for (k = 0; k < nTraseuMin; k++) {
			printf(" (%d,%d)", traseuIMin[k], traseuJMin[k]);
			lab[traseuIMin[k]][traseuJMin[k]] = '0' + k % 10;
		}
		putchar('\n');
		afisare();
		putchar('\n');
	}
	return 0;
}