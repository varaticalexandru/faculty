#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdint.h>

#include <iostream>

using namespace std;

const int N = 90+1;   // 65 (A) - 90 (Z) : majuscule ASCII

/*
    2. Sa se genereze un graf orientat ponderat avand pe post de chei numerice codurile ASCII ale literelor 
din alfabet. Arcele se vor introduce automat de la fiecare consoana spre fiecare vocala.

    a) ponderea asociata fiecarui arc este data de suma codurilor ASCII ale nodurilor conectate de 
    acesta

    b) sa se afiseze suma tuturor arcelor care constituie arborele de acoperire minima din graf
*/


// returneaza 1, daca c - vocala, 0, daca c - consoana
int isVowel(char c)
{
    return (c == 65 || c == 69 || c == 73 || c == 79 || c == 85 || c == 89 ) ? 1 : 0; 
}

// initializeaza graful
void initGraph(int graph[N][N])
{
    for (int i = 'A'; i <= 'Z'; i++)
        for (int j = 'A'; j <= 'Z'; j++)
            if (!isVowel(i) && isVowel(j))  // i - consoana, j - vocala
                graph[i][j] = i + j;
}

// afiseaza graful (matricea de adiacenta a grafului)
void printGraph(int graph[N][N])
{
    printf("\n");

    for (int i = 'A'; i <= 'Z'; i++) {
        for (int j = 'A'; j <= 'Z'; j++)
            printf("%5d", graph[i][j]);

        printf("\n");
    }

    printf("\n");
}

// indexul cheii minime
int minKey(int key[], int visited[])
{
    int min = INT16_MAX, min_idx;
    
    for (int v = 'A'; v <= 'Z'; v++)
        if (!visited[v] && key[v] < min) {
            min = key[v];
            min_idx = v;
        }

    return min_idx;
}

// afiseaza MST
void printMST(int parent[], int graph[N][N])
{
    int suma = 0;

    printf("\nArborele de acoperire minima (MST) a grafului : \n\n");
    printf("  Arc    Pondere\n");

    for (int i = 'A'; i <= 'Z'; i++) {
        printf("%c - %c : %d\n", parent[i], i, graph[parent[i]][i]);
        suma += graph[parent[i]][i];
    }

    printf("\nSuma: %d\n", suma);
}

// prim's MST
void primMST(int graph[N][N])
{
    int parent[N] = { 0 };
    int key[N];
    int visited[N];

    // initializare vectori
    for (int v = 'A'; v <= 'Z'; v++) {
        visited[v] = 0;
        key[v] = INT16_MAX;
    }

    key['B'] = 0;   // nodul de start
    parent['B'] = -1;   // primul nod al MST nu are radacina

    // atata timp cat set-ul MST nu include toate nodurile
    for (int k = 'A'; k <= 'Z'; k++) {

        // alegem un nod nevizitat (nu e in setul MST), cu cheia minima
        int u = minKey(key, visited);

        // marcam nodul u - vizitat
        visited[u] = 1;

        // includem u in setul MST
        // actualizam cheile nodurilor adiacente si nevizitate a lui u (toate v)
        for (int v = 'A'; v <= 'Z'; v++)
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    // afisam MST
    printMST(parent, graph);

}

int main(int argc, char* argv[])
{
    int graph[N][N] = { 0 };    // graful ponderat orientat

    printGraph(graph);

    initGraph(graph);

    printGraph(graph);

    primMST(graph);
    
    return 0;
}