#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


// reprezentare in binar
void Bin_Display(int n)
{
    for (int i = 31; i >= 0; i--)
        printf("%d", (n>>i) & 1);
    printf("\n");
}

// inmulteste cu 2^(log2(k))
int Multiply(int n, int k)
{
    return (int)(n << (int)log2(k));
}

// imparte la 2^log2(k)
int Divide(int n, int k)
{
    return (int)(n >> (int)log2(k));
}

// verifica paritatea nr. (1 - impar , 0 - par)
int Odd(int n)
{
    return (n & 1)
        ? 1
        : 0;
}

// verifica daca bitul i din n este impar (1) sau par(0)
int Odd_bit(int n, int i)
{
    return (n & (1 << i)) >> i;
}

// reseteaza bitul i (pune pe 0)
int Reset_bit(int n, int i)
{
    return (n & ~(1 << i));
}

// seteaza bitul i (pune pe 1)
int Set_bit(int n, int i)
{
    return (n | (1 << i));
}

// schimba bitul i (switch/flip/invert)
int Schimba_bit(int n, int i)
{
    return (n ^ (1 << i));

}

void Menu(void)
{
    printf(
           "------------ Meniu Interactiv ------------\n"
           "0. Iesire\n"
           "1. Introducere\n"
           "2. Afisare\n"
           "3. Inmultire\n"
           "4. Impartire\n"
           "5. Paritate\n"
           "6. Paritate bit\n"
           "7. Resetare bit\n"
           "8. Setare bit\n"
           "9. Schimba bit\n"
           "-------------------------------------------\n"
           "Optiunea dvs: "
    );
}



typedef enum menu {
    iesire,
    introducere,
    afisare,
    inmultire,
    impartire,
    paritate,
    paritate_bit,
    resetare_bit,
    setare_bit,
    schimba_bit
} menu;

int main(int argc, char* argv[])
{
    int n, k, i;
    menu opt;


    do {
        Menu();
        scanf("%d", &opt);
        printf("\n");

        switch(opt)
        {

            case iesire:
            {
                exit(EXIT_SUCCESS);
            }
            break;

            case introducere:
            {
                printf("Introduceti un numar intreg: ");
                scanf("%d", &n);
                printf("\n");
            }
            break;

            case afisare:
            {
                printf("\nReprezentarea binara a numarului introdus:\n\n");
                Bin_Display(n);
                printf("\n");
            }
            break;

            case inmultire:
            {
                printf("Cu ce numar intreg (putere a lui) sa inmultim %d ? : ", n);
                scanf("%d", &k);
                printf("\n%d * %d = %d << log2(%d) = %d << %d = %d\n", n, k, n, k, n, (int)log2(k), Multiply(n, k));
                printf("\n");
            }
            break;

            case impartire:
            {
                printf("La ce numar intreg (putere a lui) sa impartim %d ? : ", n);
                scanf("%d", &k);
                printf("\n%d / %d = %d >> log2(%d) = %d >> %d = %d\n", n, k, n, k, n, (int)log2(k), Divide(n, k));
                printf("\n");
            }
            break;

            case paritate:
            {
                switch(Odd(n))
                {
                    case 1:
                        printf("\nNumarul %d este impar\n", n);
                    break;

                    default:
                        printf("\nNumarul %d este par\n", n);
                    break;
                }
                printf("\n");
            }
            break;

            case paritate_bit:
            {
                printf("Introduceti rangul bitului: ");
                scanf("%d", &i);

                switch(Odd_bit(n, i))
                {
                    case 1:
                        printf("\nBitul %d este 1\n", i);
                    break;

                    default:
                        printf("\nBitul %d este 0\n", i);
                    break;
                }
                printf("\n");
            }
            break;

            case resetare_bit:
            {
                printf("Introduceti rangul bitului i:");
                scanf("%d", &i);
                n = Reset_bit(n, i);
                printf("\n");
            }
            break;

            case setare_bit:
            {
                printf("Introduceti rangul bitului i:");
                scanf("%d", &i);
                n = Set_bit(n, i);
                printf("\n");
            }
            break;

            case schimba_bit:
            {
                printf("Introduceti rangul bitului: ");
                scanf("%d", &i);

                n = Schimba_bit(n, i);
                printf("\n");
            }
            break;

            default:
            {
                printf("Eroare! Optiune nedefinita!\n");
            }
            break;
        }

    } while (opt);


    printf("\n");
    _getch();
    return 0;
}
