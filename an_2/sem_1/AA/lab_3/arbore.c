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
char pfiu[N];   // primul fiu al fiecarui nod
char frdr[N];   // fratele din dreapta a fiecarui nod

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
        pfiu[i] = -1;
        frdr[i] = -1;
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

    // prim fiu
    printf("\nPrim fiu:\n");
    for (i = 0; i < N; i++)
        printf("%4d", i);

    printf("\n");

    for (i = 0; i < N; i++)
        printf("%4d", pfiu[i]);

     printf("\n");

    // frate dreapta
    printf("\nFrate dreapta:\n");
    for (i = 0; i < N; i++)
        printf("%4d", i);

    printf("\n");

    for (i = 0; i < N; i++)
        printf("%4d", frdr[i]);

    printf("\n");

}

// returneaza id-ul nodului dupa cheie
int KeyId(char key)
{
    for (int i=0; i<n; i++)
        if (keys[i] == key)
            return i;

    return -1;
}

void Add_node()
{
    int id, mod;
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
        }while ((id = KeyId(c)) == -1);

        arr[n] = id;    // id-ul parintelui nodului curent (n)

        do {
            printf("Inserati cheia nodului: ");
            scanf(" %c", &c);
        } while(KeyId(c) != -1);

        keys[n] = c;

        // daca nodul este prim fiu (al parintelui sau)
        if (pfiu[id] == -1) {
            pfiu[id] = n;
        }
        else {
        // daca nodul este frate dreapta (al nodului care are acelasi parinte si frate dreapta nul)
            for (int i=0; i<n; i++)
                if (arr[i] == id && frdr[i] == -1) {
                    frdr[i] = n;
                }
        }
        n++;
    }
}

void Del(int id)
{
    for (int i = id+1; i < n; i++) {
        if ((frdr[i] == -1) && (arr[i] == -1))
                return;
        
        // daca id este parintele nodului i
        if  (arr[i] == id)  {

            // stergem totii fratii dreata ai lui i
            int temp = frdr[i];

            frdr[i] = -1;
            arr[i] = -1;
            pfiu[i] = -1;
            keys[i] = '-';

            Del(temp);  // fratele dre
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
    } while ((id = KeyId(c)) == -1);

    // id - indexul nodului pe care dorim sa il stergem

    int parent = arr[id];

    if (pfiu[parent] == id) {
        // daca nodul este primul fiu al parintelui sau
        pfiu[parent] = frdr[id];
        frdr[id] = -1;
    }

    Del(id);

    pfiu[id] = -1;
    arr[id] = -1;
    keys[id] = '-';

    for (int i = 0; i < n; i++)
        if (frdr[i] == id){
            // daca vreun nod il are ca frdr pe id
            frdr[i] = frdr[id];
            frdr[id] = -1;
        }  
}

int main(int argc, char** argv)
{
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

    getchar();
    return 0;
}



// init()
// {
//     for (i = 0; i < N; i++)
//     {
//         table[i][0] = -1;
//         table[i][1] = -1;
//         table[i][2] = -1;
//         table[i][3] = -1;
//     }
    
// }

// insert(int key, int father);

// suprima(int key);

// print_tables();


// insert(int key, )

// int prim_fiu(node) - returneaza primul fiu al unui nod, daca il are

// int frate_dreapta(node) - returneaza primul fiu al unui nod, daca il are