

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int CeaMaiMareCifraPara(int n)
{
    int aux, max;

    max = -1;

    do
    {
        aux = n % 10;
        if (aux % 2 == 0 && aux > max)
            max = aux;
        n /= 10;
    } while (n != 0);

    if (max == -1) return -1;
    else return max;
}

int main()
{
    int n;

    printf("Introduceti valoarea nr. : ");
    scanf("%d", &n);

    switch (CeaMaiMareCifraPara(n))
    {
    case -1:
        printf("Numarul introdus nu are nici o cifra para !\n");
        break;

    default:
        printf("Cea mai mare cifra para: %d\n", CeaMaiMareCifraPara(n));
        break;
    }

    getchar();
    return 0;
}
