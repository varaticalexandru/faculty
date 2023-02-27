#include<stdio.h> 
#include<stdlib.h> 
#include <conio.h>
#include <limits.h>

#define maxint 1000

#define N 9

int mat[N][N];  // matrice de adiacenta
int noduri[N];  // vector noduri

int culoare[N]; // vector culori pt. fiecare nod
int i[N];       // vector timpi initiali
int f[N];       // vector timpi finali
int timp = 0;   // pas de timp
int sp[N];      // graf de precedente


int viz[N];     // vector noduri vizitate
int D[N];       // vector distante minime (pana la fiecare nod)
int T[N];       // vector tati (ultimul nod vizitat) 

// meniu
void Menu()
{
    printf("\n---------------- Meniu ----------------\n"
            "0) Iesire\n"
            "1) Initializare graf \n"
            "2) Introducere nod (i) \n"
            "3) Introdurere arc ponderat(i,j) \n"
            "4) Stergere nod (i) \n"
            "5) Stergere arc(i, j) \n"
            "6) Afisare noduri + matrice de adiacenta \n"
            "7) Parcurgere DFS\n"
            "8) Algoritmul lui Prim\n"
            "----------------------------------------\n"
            "Optiunea: ");
}

// initializare matrice de adiacenta
void InitMat()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = 0;
}

// initializare vector noduri
void InitNoduri()
{
    for (int i = 0; i < N; i++)
        noduri[i] = -1;   
}

//initializare vector noduri vizitate
void InitViz()
{
    for (int i = 0; i < N; i++)
        viz[i] = 0;
}

// initializare vectori D si T
void InitDijkstra()
{
    for (int i = 0; i < N; i++){
        D[i] = -1;
        T[i] = -1;
    }
}

// afisare matrice adiacenta
void AfisareMat()
{
    printf("\n\nMatrice de adiacenta: \n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
           printf("%d  ",  mat[i][j]);
        
        printf("\n");
    }
}

// afisare vector noduri
void AfisareNoduri()
{
    printf("\nNoduri: \n");

    for (int i = 0; i < N; i++)
        printf("%d  ", noduri[i]);

    printf("\nVizitate: \n");

    for (int i = 0; i < N; i++)
        printf("%d  ", viz[i]);

    printf("\nD: \n");

    for (int i = 0; i < N; i++)
        printf("%d  ", D[i]);

    printf("\nT: \n");

    for (int i = 0; i < N; i++)
        printf("%d  ", T[i]);
}

// afisare vectori timpi initiali, timpi finali, vector de precedenta
void AfisareTimpi()
{
    int j;

    printf("\nTimpi initiali: \n");
    for (j = 0; j < N; j++)
        printf("%d ", i[j]);

    printf("\nTimpi finali: \n");
    for (j = 0; j < N; j++)
        printf("%d ", f[j]);

    printf("\nSP: \n");
    for (j = 0; j < N; j++)
        printf("%d ", sp[j]);

}

// inserare nod i
void InsertNode()
{
    int aux;

    printf("Introduceti nodul: ");
    scanf("%d", &aux);

    noduri[aux] = 1;

}

// inserare arc ponderat (i -> j)
void InsertArc()
{
    int i, j, cost;

    printf("\ni: ");
    scanf("%d", &i);

    printf("j: ");
    scanf("%d", &j);

    printf("Cost: ");
    scanf("%d", &cost);

    // introducem costul in matricea de adiacenta
    mat[i][j] = cost;
}

// stergere nod i
void DelNode()
{
    int aux;

    printf("nod sters: ");
    scanf("%d", &aux);

    noduri[aux] = -1;


    // anulam randul aferent nodului sters din matricea de adiacenta
    for (int j = 0; j < N; j++) {
        mat[aux][j] = 0;
        mat[j][aux] = 0;
    }
        

    // anulam coloana aferenta nodului sters din matricea de adiacenta
    for (int i = 0; i < N; i++) {
        mat[i][aux] = 0;
        mat[aux][i] = 0; 
    }
       
    
    
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < N; j++)
    //         if (i == aux || j == aux)
    //             mat[i][j] = 0;
}

// stergere arc (i, j)
void DelArc()
{
    int i, j;

    printf("i: ");
    scanf("%d", &i);

    printf("j: ");
    scanf("%d", &j);

    mat[i][j] = 0;
    mat[j][i] = 0;
}




// algoritmul lui Dijkstra (drumul minim de la un nod la toate celelalte noduri)
void Dijkstra()
{
    // A(0) - nodul de start - marcat ca vizitat
    viz[0] = 1;

    // initializare D si T
    for (int j = 0; j < N; j++) {
        if (mat[0, j])
            D[j] = mat[0, j];
        
        T[j] = 0;
    }

    // se alege nodul minim din cele nevizitate
    int min = INT_MAX;
    for (int j = 1; j < N; j++)
        if (!viz[j])    // daca nodul e nevizitat
            if (mat[0, j] < min)
                min = mat[0, j];

    // se marcheaza C(1) -  vizitat
    viz[min] = 1;

    // 
    





        


}


// functie principala
int main(int argc, char** argv)
{
    int opt;
    int v;  

    do
    {
        Menu();
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            exit(EXIT_SUCCESS);
        break;

        case 1:     // initializare
        {
            InitMat();
            InitNoduri();
            InitViz();
            InitDijkstra();
        }
        break;

        case 2:     // introducere nod (i)
        {
            InsertNode();
        }
        break;

        case 3:     // introducere arc ponderat (i, j) in matricea de adiacenta
        {
            InsertArc();
        }
        break;

        case 4:     // stergere nod
        {
            DelNode();
        }
        break;

        case 5:     // stergere arc
        {
            DelArc();
        }
        break;

        case 6:     // afisare
        {
            AfisareNoduri();
            AfisareMat();
        }
        break;

        case 7:     // algoritmul lui Dijkstra
        {
           Dijkstra();
        }
        break;
        
        default:    // afisare eroare
        {
            printf("Eroare. Optiune nedefinita. \n");
        }
        break;
        }
        
    } while (opt);
    


    return 0;
}


// parcurgerea prin cuprindere
// trece prin toate nodurile, dar nu-i sigur ca trece prin toate arcurile