#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>

#include <stdio.h>

#include <conio.h>

int main()
{
    int x, i, dim = sizeof(i) * 8, masca = 1;

    printf("Introduceti numarul\n");
    scanf("%d", & x);
    printf("reprezentarea in binar este:\n");
    for (i = dim - 1; i >= 0; i--)
      putchar(x & masca << i ? '1' : '0');
    // << are precedenta mai mare decat &

    printf("\n");
    system("pause");
    return 0;

}
