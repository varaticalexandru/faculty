#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef enum options {
    iesire = 0,
    adaugare = 1,
    stergere = 2,
    afisare = 3
} options;


int n = 0;

char keys[N];   // parintele fiecarui nod
char arr[N];    // cheia fiecarui nod

void Menu()
{
    printf("\n----------------- Meniu Interactiv -----------------\n"
            "0. Iesire\n"
            "1. Adaugare nod\n"
            "2. Stergere nod\n"
            "3. Afisare array-uri\n"
            "-----------------------------------------------------\n"
            "Intorduceti optiunea: "
    );
}

void Init_arrays()
{
    int i;

    for (i = 0; i < N; i++) {
        keys[i] = '-';
        arr[i] = -1;
    }
}

void Print_arrays()
{
    int i;

    // arr
    printf("\nArr:\n");
    for (i = 0; i < N; i++)
        printf("%4d", i);

    printf("\n");

    for (i = 0; i < N; i++)
        printf("%4d", arr[i]);

    printf("\n\n");

    // keys
    printf("\nKeys:\n");
    for (i = 0; i < N; i++)
        printf("%4d", i);

    printf("\n");

    for (i = 0; i < N; i++)
        printf("%4c", keys[i]);

    printf("\n");

}

int KeyExist(char key)
{
    for (int i=0; i<n; i++)
        if (keys[i] == key)
            return i;

    return -1;
}



void Add_node()
{
    int id;
    char c;

    if (!n) {
        printf("Parintele radacinii este implicit -1.\n");
        printf("Inserati cheia radacinii: ");
        scanf(" %c", &keys[0]);
        n++;
    }
    else {
        printf("Inserati cheia parintelui: ");
        do {
            scanf(" %c", &c);
        }while ((id = KeyExist(c)) == -1);

        arr[n] = id;

        do {
            printf("Inserati cheia nodului: ");
            scanf(" %c", &c);
        } while(KeyExist(c) != -1);

        keys[n] = c;
        
        n++;
    }
}

void Del(int id)
{

    for (int i=0; i<n; i++) {
            if (arr[i] == id) {
                arr[i] = -1;
                keys[i] = '-';
                Del(i);
            }
    }
}

void Del_node()
{
    char c;
    int id;

   
    do
    {
        printf("Introduceti cheia nodului sters: ");
        scanf(" %c", &c);
    } while ((id = KeyExist(c)) == -1);

    keys[id] = '-';
    arr[id] = -1;
    printf("id: %d\n", id);
    

    for (int i=0; i>n; i++) {
        if (arr[i] == id) {
            arr[i] = -1;
        }
    }

    Del(id);

}

int main(int argc, char** argv)
{
    int i;
    options opt;

    system("cls");

    Init_arrays();
    Print_arrays();

    do {
        Menu();
        scanf("%d", &opt);
        printf("\n");

        switch (opt)
        {
            case iesire:
                exit(EXIT_SUCCESS);
            break;

            case adaugare:
                Add_node();
            break;

            case stergere:
                Del_node();
            break;

            case afisare:
                Print_arrays();
            break;
            
            default:
                printf("Eroare. Optiune nedefinita.\n\n");
            break;
        }
    } while(opt);


    return 0;
}