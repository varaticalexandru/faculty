#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// functie ce returneaza unghiul in grade dintre segmentul(x0, y0) - (x1, y1) si axa OX

float Unghi(float x0, float y0, float x1, float y1)
{
	float deltaX, deltaY;

	// diferenta p.start - p.sfarsit
	deltaY = y1 - y0;
	deltaX = x1 - x0;

	// calculul unghiului
	return atan(deltaY, deltaX) * 180 / M_PI;
}

int main(void)
{
	float x0, y0, x1, y1;

	printf("Introduceti coordonatele reale a 2 puncte x si y:\n");
	printf("x0: ");
	scanf("%f", &x0);
	printf("y0: ");
	scanf("%f", &y0);
	printf("\nx1: ");
	scanf("%f", &x1);
	printf("y1: ");
	scanf("%f", &y1);
	
	printf("Unghiul dintre [XY] si Ox: %.2f grade\n", Unghi(x0, y0, x1, y1));

	getchar();
	return 0;
}