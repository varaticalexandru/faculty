#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdint.h>

using namespace std;

/*
    2. Sa se genereze un graf orientat ponderat avand pe post de chei numerice codurile ASCII ale literelor 
din alfabet. Arcele se vor introduce automat de la fiecare vocala spre fiecare consoana.

    a) ponderea asociata fiecarui arc este data de suma codurilor ASCII ale nodurilor conectatede 
    acesta
    b) sa se afiseze suma tuturor arcelor care constituie arborele de acoperire minima din graf
*/

const int N = 90+1;

// print adjiacency matrix
void printMat(int M[N][N])
{
    printf("\n");

    for (int i = 'A'; i <= 'Z'; i++) {
        for (int j = 'A'; j <= 'Z'; j++)
            printf("%5d", M[i][j]);

        printf("\n");
    }    

    printf("\n");     
}

//
void printVec(int v[N])
{
    printf("\n");

    for (int j = 0; j < N; j++)
        printf("%d ", v[j]);

    printf("\n");
}


// min unvisited key idx
int minKey(int key[], int visit[])
{
    int min = INT16_MAX, min_idx;

    for (int v = 'A'; v <= 'Z'; v++)
        if (!visit[v] && key[v] < min) {
            min = key[v];
            min_idx = v;
        }

    return min_idx;
}

// print function
void printMST(int graph[N][N], int parent[])
{
    int sum = 0;

    printf("\n  Arc    Pondere\n");

    for (int i = 'A'+1; i <= 'Z'; i++) {
        printf("%c - %c : %d\n", parent[i], i, graph[parent[i]][i]);
        sum += graph[parent[i]][i];
    }

    printf("\nSuma: %d\n", sum);
}

// Prim's MST
void primMST(int graph[N][N])
{
    int key[N]; // keys 
    int parent[N] = { 0 };  // parents (constucted MST set)
    int visit[N];  // visits

    // init keys & visits
    for (int i = 'A'; i <= 'Z'; i++) {
        key[i] = INT16_MAX;
        visit[i] = 0;
    }

    key[0+'A'] = 0;
    parent[0+'A'] = -1;

    for (int k = 'A'; k <= 'Z'; k++) {

        int u = minKey(key, visit);     // min key
        visit[u] = 1;   // mark node visited
        
        // upd keys of all adjiacent unvisited nodes of u
        for (int v = 'A'; v <= 'Z'; v++)
            if (graph[u][v] && !visit[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        
    }
    
    printMST(graph, parent);

}



// return 1 if c is a vowel, 0 otherwise (consonant)
int isVowel(char c)
{
    return (c == 65 || c == 69 || c == 73 || c == 79 || c == 85 || c == 89) ? 1 : 0;  
}


// initializare graph
void initGraph(int graph[N][N])
{
    for (int i = 'A'; i <= 'Z'; i++)
        for (int j = 'A'; j <= 'Z'; j++)
            if (isVowel(i) && !isVowel(j))  // i - vocala, j - consoana
                graph[i][j] = i+j;
}

int main(int argc, char* argv[])
{
    int graph[N][N] = { 0 };

    initGraph(graph);

    primMST(graph);

    printMat(graph);

    return 0;
}