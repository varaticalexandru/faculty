#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int* AddToArray(int* v, int* n, int value)
{
	int* p = NULL;

	p = (int*)realloc(v, (*n + 1) * sizeof(int));
	p[*n] = value;
	(*n)++;

	return p;
}

void AfisareVector(int* v, int n)
{
	int i;
	for (i = 0; i < n; i++, v++)
		printf("%d ", *v);

	printf("\n");
}

void EliberareVector(int* v)
{
	free(v);
}

int StrLen(char* s)
{
	char* p = s;
	while (*p++);
	return p - s - 1;
}

int StrCmp(char* s, char* t)
{
	int i, diff;

	for (i = 0; i < StrLen(t); i++, s++, t++)
		if (*s != *t) {
			return *s - *t;
		}

	return 0;
}

int* SubString(char* s1, char* s2, int* n)
{
	char *c1 = NULL, *c2 = NULL;
	int* v = NULL;
	
	c1 = s1;
	c2 = s2;

	for (; *c1; c1++) {
		if (*c1 == *c2 && !(StrCmp(c1, c2)))
			v = AddToArray(v  , n, c1 - s1);
	}

	return v;
}


// cautarea unui subsir intr-un sir

int main(void)
{
	char sir[30], subsir[30];
	int* v = NULL, n = 0;

	printf("Introduceti sirul: ");
	gets(sir);

	printf("Introduceti subsirul: ");
	gets(subsir);

	v = SubString(sir, subsir, &n);
	
	if (!v)
		printf("Subsirul nu apare in sir !\n");
	else {
		printf("Subsirul apare in sir de %d ori,  la pozitiile : ", n);
		AfisareVector(v, n);
	}


	EliberareVector(v);
	_getch();
	return 0;
}