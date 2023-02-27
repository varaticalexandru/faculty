#include<stdio.h> 
#include<stdlib.h> 
#include <conio.h>

#define alb 0
#define gri 1
#define negru 2

#define N 7

int mat[N][N];  // matrice de adiacenta
int noduri[N];  // vector noduri

int culoare[N]; // vector culori pt. fiecare nod
int i[N];       // vector timpi initiali
int f[N];       // vector timpi finali
int timp = 0;   // pas de timp
int sp[N];      // graf de precedente


int viz[N];     // vector noduri vizitate
// int q[N];       // coada

// int f = -1;     // index cap coada
// int r = -1;     // index coada


// meniu
void Menu()
{
    printf("\n---------------- Meniu ----------------\n"
            "0) Iesire\n"
            "1) Initializare graf \n"
            "2) Introducere nod (i) \n"
            "3) Introdurere arc (i,j) \n"
            "4) Stergere nod (i) \n"
            "5) Stergere arc(i, j) \n"
            "6) Afisare noduri + matrice de adiacenta \n"
            "7) Parcurgere DFS\n"
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

// inserare arc (i, j)
void InsertArc()
{
    int i, j;

    printf("\ni: ");
    scanf("%d", &i);

    printf("\nj: ");
    scanf("%d", &j);

    mat[i][j] = 1;
    mat[j][i] = 1;

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

// // Breadth First Search (parcurgere prin cuprindere)
// void BFS(int v)
// {
//     int i;

//    for (i = 0; i < N; i++)                                // itereaza toate nodurile din graf
//        {
//             if(mat[v][i] && !viz[i])                // daca nodul - adiacent la v si nevizitat
//             {
//                     r++;                            // inc. index pt. coada q
//                     q[r] = i;                       // insereaza i in coada
//                     viz[i] = 1;                     // marcheaza i vizitat
//                     printf("%d  ",i);
//             }
//       }

//       f++;                               // inc. index. pt. capul cozii q

//       if(f<=r)                           // atat timp cat coada nu e vida
//             BFS(q[f]);                   // apeleaza bfs recursiv pentru capul cozii
// }



// cautare in adancime
void CautareInAdancime(int u)
{   
    int v;

    culoare[u] = gri;   // 1
    timp++;             // inc. pas de timp

    

    i[u] = timp;        // timp initial u

    
    for (v = 0; v < N; v++)
        if (mat[u][v])    // pt. fiecare nod v adiacent lui u
            if (culoare[v] == alb) {
                sp[v] = u;
                printf("%d ", v);
                CautareInAdancime(v);
            }

    culoare[u] = negru;
    timp++;
    f[u] = timp;
}

// traversare in adancime
void TraversareInAdancime()
{
    int u;

    // initializare vectori culoare
    for (u = 0; u < N; u++) {
        culoare[u] = alb;   // 0
        sp[u] = -1;
    }

    timp = 0;

    for (u = 0; u < N; u++)
        if (culoare[u] == alb)
            CautareInAdancime(u);

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
        }
        break;

        case 2:     // introducere nod (i)
        {
            InsertNode();
        }
        break;

        case 3:     // introducere arc (i, j) in matricea de adiacenta
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

        case 7:     // BFS (parcurgere prin cuprindere)
        {
            // printf("\nNodul de start: ");
            // scanf("%d", &v);
            // f = r = 0;
            // printf("\n traversare BFS:\n");
            // viz[v]=1;                                     // marchraza nodul de start ca vizitat
            // printf("%d   ",v);
        
            // BFS(v);                                       // apel BFS

            printf("\n");
            TraversareInAdancime();
            printf("\n");
            AfisareTimpi();
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