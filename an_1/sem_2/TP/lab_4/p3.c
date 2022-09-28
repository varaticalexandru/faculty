#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int StrCmp(char* sir1, char* sir2)
{
	for (; *sir1 == *sir2; sir1++, sir2++)
		if (!(*sir1))
			return 0;
	return *sir1 - *sir2;
}


// functie care compara 2 siruri de caractere

int main(void)
{
	char sir1[30], sir2[30];

	printf("Introduceti sir1: ");
	gets(sir1);

	printf("Introduceti sir2: ");
	gets(sir2);

	printf("%d\n", StrCmp(sir1, sir2));

	if (!StrCmp(sir1, sir2))
		printf("Sirurile sunt egale\n");
	if (StrCmp(sir1, sir2) > 0)
		printf("Sir1 > Sir2\n");
	if (StrCmp(sir1, sir2) < 0)
		printf("Sir2 > Sir1\n");


	return 0;
}