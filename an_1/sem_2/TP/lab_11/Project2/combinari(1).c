#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// genereaza toate combinarile de r elemente unei multimi de n elemente arr[n]

int n;	// dimensiune multime
int k;	// counter

void ErrorDynamicAllocation(void)
{
	printf("Eroare la alocarea dinamica de memorie!\n");
	exit(EXIT_FAILURE);
}

char* ReadStr(void)
{
	char buffer[100], *str = NULL;

	printf("Intoduceti elementele multimii:\n");
	fgets(buffer, 100, stdin);
	buffer[strlen(buffer) - 1] = 0;

	str = (char*)calloc(strlen(buffer), sizeof(char));
	if (!str)
		ErrorDynamicAllocation();

	strcpy(str, buffer);
	n = strlen(str);

	return str;
}

void CombinationUtil(char arr[], char data[], int start, int end, int index, int r)
{
	// check if combination is ready to be printed
	if (index == r) {
		k++;
		for (int j = 0; j < r; j++)
			printf("%c ", data[j]);
		printf("\n");
	}

	// replace index with all elements possible from arr
	for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
		data[index] = arr[i];
		CombinationUtil(arr, data, i + i, end, index + 1, r);
	}
}

void PrintCombinations(char arr[], int n, int r)
{
	char data[r];

	CombinationUtil(arr, data, 0, n - 1, 0, r);
}


int main(int argc, char** argv)
{
	char* str = NULL;

	str = ReadStr();

	_getch();
	return 0;
}