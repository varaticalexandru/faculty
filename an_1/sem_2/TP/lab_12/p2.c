#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void stelute(int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("*");
}
void spatii(int n) {
	int i;
	for (i = 0; i < n; i++)
		printf(" ");
}
void linie3(int n1, int n2, int n3) {
	stelute(n1);
	spatii(n2);
	stelute(n3);
	printf("\n");
}
void linie5(int n1, int n2, int n3, int n4, int n5) {
	stelute(n1);
	spatii(n2);
	stelute(n3);
	spatii(n4);
	stelute(n5);
	printf("\n");
}
void linie7(int n1, int n2, int n3, int n4, int n5, int n6, int n7) {
	stelute(n1);
	spatii(n2);
	4
		stelute(n3);
	spatii(n4);
	stelute(n5);
	spatii(n6);
	stelute(n7);
	printf("\n");
}
int main(int argc, char* argv[])
{
	linie3(7, 3, 5);
	linie7(0, 3, 1, 6, 1, 4, 1);
	linie7(0, 3, 1, 6, 1, 5, 1);
	linie7(0, 3, 1, 6, 1, 5, 1);
	linie7(0, 3, 1, 6, 1, 4, 1);
	linie5(0, 3, 1, 6, 5);
	linie5(0, 3, 1, 6, 1);
	linie5(0, 3, 1, 6, 1);
	linie5(0, 3, 1, 6, 1);
	linie5(0, 3, 1, 6, 1);
	linie5(0, 3, 1, 6, 1);
	linie5(0, 3, 1, 6, 1);
	return 0;
}