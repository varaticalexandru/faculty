// cautarea primei solutii
void solutie() // nu mai afiseaza numarul solutiei, fiindca acum va fi gasita doar prima solutie
{
	int k;
	printf("Lungime %d:", nTraseu);
	for (k = 0; k < nTraseu; k++)printf(" (%d,%d)", traseuI[k], traseuJ[k]);
	putchar('\n');
	afisare();
	putchar('\n');
}
// daca s-a gasit o solutie returneaza 1, altfel 0
int cauta(int i, int j)
{
	// in caz ca nu se trece de testele de validitate, inseamna ca inca nu s-a gasit o solutie => return 0
	if (i < 0 || i >= nLab || j < 0 || j >= nLab)return 0;
	if (lab[i][j] != '.')return 0;
	traseuI[nTraseu] = i;
	traseuJ[nTraseu] = j;
	lab[i][j] = '0' + nTraseu % 10;
	nTraseu++;
	if (i == 0 || i == nLab - 1 || j == 0 || j == nLab - 1) { // testare daca este solutie
		solutie();
		return 1; // s-a gasit o solutie => return 1
	}
	else {
		int k;
		for (k = 0; k < 4; k++) {
			// daca pentru oricare dintre variante s-a gasit o solutie => return 1
			if (cauta(i + di[k], j + dj[k]))return 1;
		}
	}
	nTraseu--;
	lab[i][j] = '.';
	// inca nu s-a gasit nicio solutie, fiindca altfel s-ar fi executat return 1
	// ori pe ramura if-ului de testare solutie, ori pe ramura else
	return 0;
}
int main()
{
	citire("lab.txt");
	if (!cauta(startI, startJ)) {
		printf("nu s-a gasit nicio solutie\n");
	}
	return 0;
}