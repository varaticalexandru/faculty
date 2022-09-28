#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// p1
// functie care returneaza numarul de caractere dintr-un sir

int StrLen_0(char* s)
{
	char* p = s;

	while (*p)
		p++;

	return p - s;
}

int StrLen_1(char* s)
{
	int i;

	for (i = 0; *s; s++)
		i++;

	return i;
}

int StrLen_2(char* s)
{
	char* p = s;
	while (*p++);
	return  p - s - 1;
}

void StrCpy_0(char* s, char* t)
{
	int i = 0;
	while (s[i] = t[i])
		i++;
}

void StrCpy_1(char* s, char* t)
{
	while (*s == *t) {
		s++;
		t++;
	}
}

void StrCpy_2(char* s, char* t)
{
	for (; *s = *t; s++, t++);
}

int StrCmp_0(char* s, char* t)
{
	int i;
	for (i = 0; s[i] == t[i]; i++)
		if (!s[i])
			return 0;
	return s[i] - t[i];
}

int StrCmp_1(char* s, char* t)
{
	for (; *s == *t; s++, t++)
		if (!(*s))
			return 0;
	return *s - *t;
}

int main(void)
{
	char s[30];

	printf("Introduceti un sir de caractere: ");
	scanf("%[^\n]s", s);

	printf("Lungimea sirului '%s': %d caractere\n", s, StrLen_2(s));

	_getch();
	return 0;
}