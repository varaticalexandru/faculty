#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
	citeste un fisier text si inlocuieste secventele de mai multe spatii consecutive printr-un singur spatiu
*/


void EroareDeschidereFisier(void)
{
	printf("Eroare deschidere fisier !\n");
	exit(EXIT_FAILURE);
}

int IsSpace(char* c)
{
	if ((*c) == ' ') return 1;
	return 0;
}

void Spaces(void)
{
	FILE* f = NULL;
	char buffer[100], *ptr = NULL, *ptr2 = NULL;

	f = fopen("file.txt", "rt");
	fgets(buffer, 100, f);
	printf("%s\n", buffer);

	buffer[strlen(buffer)] = 0;

	ptr = buffer;
	while (*ptr)
	{
		if (IsSpace(ptr) && IsSpace(ptr + 1)) {
			for (ptr2 = ptr + 1; (*ptr2); ptr2++)
				*ptr2 = *(ptr2 + 1);
		}

		ptr++;
	}

	printf("\n%s\n", buffer);

	fclose(f);

}

int main(int argc, char** argv)
{

	Spaces();


	_getch();
	return 0;
}