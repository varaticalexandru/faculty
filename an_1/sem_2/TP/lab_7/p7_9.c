#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void EroareAlocare(void)
{
	printf("Eroare la alocarea dinamica !\n");
	exit(EXIT_FAILURE);
}

void EliberareMatrice(char** M, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(M[i]);
	free(M);
}

void EliberareVector(char* a)
{
	free(a);
}

void AfisareMatrice(char** M, int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		printf("%s\n", M[i]);

	}
}

char** RealocareMatrice(char** M, int n, int len)
{
	char** aux = NULL;
	int i;

	aux = (char**)realloc(M, (n + 1) * sizeof(char*));
	if (!aux)
		EroareAlocare();
	
	aux[n] = (char*)calloc(len, sizeof(char));
	if (!aux[n])
		EroareAlocare();

	return aux;
}

char** CitireSir(char** M, int* n)
{
	char c = NULL, *s = NULL;
	int i = 0;

	while ((c = getchar()) != EOF) {
		s = (char*)realloc(s, (i + 2) * sizeof(char));

		if (c == '\n' || c == '\t' || c == ' ') {
			M = RealocareMatrice(M, *n, i);	
			strcpy(M[*n], s);
			(*n)++;
			i = 0;
			continue;
		}
		else
			s[i] = c;

		s[i + 1] = 0;
		i++;
	}

	EliberareVector(s);

	return M;
}

char* Merge(char** M, int n)
{
	int i;
	char* s = NULL, *aux = NULL;

	// inseram primul cuvant
	s = (char*)realloc(s, strlen(M[0])  + 2);
	aux = (char*)calloc(strlen(M[0]) + 2, sizeof(char));
	strcpy(aux, M[0]);
	strcat(aux, "-");
	strcpy(s, aux);

	for (i = 1; i < n; i++)
	{
		// daca ultimele 2 litere din sir = primele 2 litere din cuvant
		if (s[strlen(s) - 3] == M[i][0] && s[strlen(s) - 2] == M[i][1]) {
			s = (char*)realloc(s, strlen(s) + strlen(M[i]) + 2);
			strcat(s, M[i]);
			strcat(s, "-");
		}
	}

	EliberareVector(aux);

	return s;
}

int main(int argc, char** argv)
{
	char **M = NULL, *s = NULL;
	int n = 0;

	M = CitireSir(M, &n);

	printf("\nCuvintele introduse in sir:\n");
	AfisareMatrice(M, n);

	s = Merge(M, n);
	printf("\nSirul format: \n%s\n", s);

	EliberareMatrice(M, n);
	EliberareVector(s);

	_getch();
	return 0;
}