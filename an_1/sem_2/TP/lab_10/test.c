#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdint.h>

void EroareDeschidereFisier(void)
{
	printf("Eroare deschidere fisier!\n");
	exit(EXIT_FAILURE);
}

void EroareScriereFisier(void)
{
	printf("Eroare scriere in fisier!\n");
	exit(EXIT_FAILURE);
}

void EroareAlocareMemorie(void)
{
	printf("Eroare alocare memorie!\n");
	exit(EXIT_FAILURE);
}

void EroareCitireFisier(void)
{
	printf("Eroare citire fisier !\n");
	exit(EXIT_FAILURE);
}

void _HexDump(const void* data, size_t size) {
	char ascii[17];
	size_t i, j;
	ascii[16] = '\0';
	for (i = 0; i < size; ++i) {
		printf("%02X ", ((unsigned char*)data)[i]);
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
			ascii[i % 16] = ((unsigned char*)data)[i];
		}
		else {
			ascii[i % 16] = '.';
		}
		if ((i + 1) % 8 == 0 || i + 1 == size) {
			printf(" ");
			if ((i + 1) % 16 == 0) {
				printf("|  %s \n", ascii);
			}
			else if (i + 1 == size) {
				ascii[(i + 1) % 16] = '\0';
				if ((i + 1) % 16 <= 8) {
					printf(" ");
				}
				for (j = (i + 1) % 16; j < 16; ++j) {
					printf("   ");
				}
				printf("|  %s \n", ascii);
			}
		}
	}
}

void HexDump(char* filename)
{
	FILE* f = NULL;
	int n_read, n;
	int* ptr = &n;
	int i = 1;

	if (!(f = fopen(filename, "rb")))
		EroareDeschidereFisier();

	do
	{
		n_read = fread(ptr, sizeof(int*), 1, f);
		*ptr = _byteswap_ulong(*ptr);
		printf("%p ", *ptr);
		!(i % 4) ? printf("\n") : 1;
		i++;
	} while (n_read);

	fclose(f);
	printf("\n\nCitire din fisier cu succes !\n");
}

/*
* citeste cate 16B si afiseaza pe cate o linie
* fiecare linie incepe cu offset-ul ei in sir (afisat in hexa pe 8 cifre)
* valorile hexa ale celor 16 B pe cate 2 cifre
* in final caracterele
* daca codul unui caracter este in 32-255, ca atare
* daca nu, un punct in locul sau
*
*/

int main(int argc, char** argv)
{
	char* filename = argv[1];

	HexDump(filename);



	_getch();
	return 0;
}