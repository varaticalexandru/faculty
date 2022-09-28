#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef enum {gram,metru,litru} unit_m;
const char* nume_unit_m[] = {"grame","metri","litri"};

typedef enum {_,deca,hecto,kilo,mega,giga} mult;
const char* nume_mult[] = {"_","deca","hecto","kilo","mega","giga"};

typedef struct {
	unsigned long long val;
	unit_m um;
	mult mu;
} masuratoare;

int NumOf10s(unsigned long long* n)
{
	int k = 0;

	while (*n % 10 == 0) {
		k++;
		*n /= 10;
	}

	return k;
}


int main(int argc, char** argv)
{
	masuratoare m;
	unsigned long long n;
	
	printf("Introduceti o valoare: ");
	scanf("%lld", &m.val);
	n = m.val;

	printf("Introduceti o unitate de masura (gram-0, metru-1, litru-2) : ");
	scanf("%d", &m.um);

	m.mu = NumOf10s(&n);

	printf("\nValoare: %lld\nUnitate: %s\nMultiplicator: %s\n", m.val, nume_unit_m[m.um], nume_mult[m.mu]);
	
	printf("\nEchivalent : %lld %s %s", n, nume_mult[m.mu], nume_unit_m[m.um]);

	printf("\n");
	_getch();
	return 0;
}