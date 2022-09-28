#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void StringSwap(char* s, char* t)
{
	char* aux = NULL;
	aux = (char*)calloc(10, sizeof(char));
	
	strcpy(aux, s);
	strcpy(s, t);
	strcpy(t, aux);
}

int** AlocareMatrice(int m, int n)
{
	int** M = NULL, i;

	M = (int**)calloc(m, sizeof(int*));
	if (!M) {
		printf("Eroare la alocarea dinamica de memorie! \n");
		exit(1);
	}
	for (i = 0; i < m; i++)
		M[i] = (int*)calloc(n, sizeof(int));

	return M;
}

void EliberareMatrice(int** M, int m)
{
	int i;
	for (i = 0; i < m; i++)
		free(M[i]);
	free(M);
}

int AfisareMatrice(char** M, int m, int n)
{
	int i, j, k;

	k = 0;
	for (i = 0; i < m; i++)
		if (M[i][0]) {
			printf("%s\n", M[i]);
			k++;
		}
		
	return k;
}

int Delimit(char* c)
{
	return (*c == ',' || *c == '.' || *c == ';' || *c == '!') ? 1 : 0;
}

int** Words(char* s, char** M)
{
	char* p = NULL, * k = NULL;
	int i, j;

	M = AlocareMatrice(10, 10);

	for (i = 0, j = 0, p = s; *p; p++) {

		if (!Delimit(p)) {
			M[i][j] = *p;
			j++;
		}
		else {
			M[i][j] = '\0';
			j = 0;
			i++;
		}

	}
	return M;
}

int** RealocareMatrice(char** M, int m_new)
{
	int i;
	char** M_new = NULL;

	M_new = (char**)realloc(M, m_new * sizeof(char*));

	return M_new;
}

void Sortare(char** M, int m, int n)
{
	int i, j, sortat;

	do
	{
		sortat = 1;
		for (i = 0; i < m - 1; i++)
			if (strcmp(M[i], M[i + 1]) > 0) {
				sortat = 0;
				StringSwap(M[i], M[i + 1]);
		}
	} while (!sortat);
}


// extrage cuvintele din text si le ordoneaza alfabetic
// , .  ; !



int main(void)
{
	int** M = NULL, k;
	char sir[100];

	printf("Introduceti un text: ");
	gets(sir);

	M = Words(sir, M);

	printf("\nCuvintele introduse: \n");
	k = AfisareMatrice(M, 10, 10);
	M = RealocareMatrice(M, k);

	Sortare(M, k, 10);
	printf("\nCuvintele introduse sortate alfabetic: \n");
	AfisareMatrice(M, k, 10);

	_getch();
	return 0;
}