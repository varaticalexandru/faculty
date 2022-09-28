#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void citire(int st, int dr, int v[]) {
	int mij;
	if (st == dr)
		f >> v[st];
	else
	{
		mij = (st + dr) / 2;
		citire(st, mij, v);
		citire(mij + 1, dr, v);
	}
}
void afisare(int st, int dr, int v[]) {
	int mij;
	if (st == dr)
		g << v[st];
	else
	{
		mij = (st + dr) / 2;
		afisare(st, mij, v);
		afisare(mij + 1, dr, v);
	}
}int main(int argc, char* argv[])
{
	//
	return 0;
}