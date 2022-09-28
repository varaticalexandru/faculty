#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// genereaza toate combinarile de r elemente a unei multimi de n elemente (arr[n])

int k;	// combinations counter

int Factorial(int n)
{
    return (!n)
        ? 1
        : n * Factorial(n-1);
}

void ErrorDynamicAllocation(void)
{
	printf("Eroare la alocarea dinamica de memorie!\n");
	exit(EXIT_FAILURE);
}

void PrintArray(char*a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%c ", a[i]);
    printf("\n");
}

char* ReadStr(int* n, int* r)
{
	char buffer[100];
	char *arr = NULL;

	printf("Intoduceti elementele multimii:\n");
	fgets(buffer, 100, stdin);
	buffer[strcspn(buffer, "\n")] = 0;
	*n = strlen(buffer);

	printf("Introduceti r: ");
	scanf("%d", r);

	arr = (char*)calloc(*n, sizeof(char));
	if (!arr)
		ErrorDynamicAllocation();

	for (int i = 0; i < *n; i++)
        arr[i] = buffer[i];

	return arr;
}

void CombinationUtil(char arr[], char data[], int start, int end, int index, int r)
{
	// check if combination is ready to be printed
	if (index == r) {
		k++;
		PrintArray(data, r);
	}

	// replace index with all elements possible from arr
	for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
		data[index] = arr[i];
		CombinationUtil(arr, data, i + 1, end, index + 1, r);
	}
}

void PrintCombinations(char arr[], int n, int r)
{
	char data[r+1];

	CombinationUtil(arr, data, 0, n - 1, 0, r);
}


int main(int argc, char** argv)
{
	char* str = NULL;
	int n, r;

	str = ReadStr(&n, &r);



	printf("\nToate combinatiile de %d elemente luate cate %d:\n", n, r);
	PrintCombinations(str, n, r);
	printf("\nNumarul de combinari: %d\n", k);
	printf("\nNumarul teoretic de combinari: C(%d, %d) = %d!/[%d!*(%d-%d)!] = %d\n",
            n, r, n, r, n, r, Factorial(n)/(Factorial(r)*Factorial(n-r))
    );



	_getch();
	return 0;
}

