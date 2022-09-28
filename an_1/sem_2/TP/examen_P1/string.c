#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// lungimea sirului de caractere
int LenStr(char* str)
{
    for (int i = 0; )

    return i;
}

int main(int argc, char** argv)
{

    char buffer[100];

    puts("Introduceti un sir de caractere: \n");
    fgets(buffer, 100, stdin);

    buffer[strcspn(buffer, "\n")] = 0;

    printf("Lungimea sirului de caractere: %d\n", LenStr(buffer));


    _getch();
    return 0;
}
