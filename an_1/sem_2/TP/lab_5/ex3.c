#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*
struct Data {
	int zi;
	int luna;
	int an;
};
*/

// Structura cu campuri pe biti

typedef enum {paine, covrig, corn} tip_produs;

typedef struct {
	tip_produs tip : 2;			// 0-paine, 1-covrig, 2-corn
	float greutate;
	unsigned nr_cereale : 8;	// 0..7 nr.cereale ce intra in compozitie
} panificatie;




int main(int argc, char** argv)
{
	panificatie p;

	p.tip = 1;
	p.greutate = 0.5;
	p.nr_cereale = 2;

	printf("%hhd %.2f %hhd\n", p.tip, p.greutate, p.nr_cereale);
	


	_getch();
	return 0;
}