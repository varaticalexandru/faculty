#include <bits/stdc++.h>

using namespace std;

const int N = 123;

// check uppercase
int isUpper(char c)
{
    return (c >= 65 && c <= 90) ? 1 : 0;
}

// check vowel (lower)
int isVowel(char c)
{
    return (c == 97 ||c == 101 ||c == 105 ||c == 111 ||c == 117 ||c == 121) ? 1 : 0;

}

// check lower consonant
int isLowerCons(char c)
{
    return (!isUpper(c) && !isVowel(c)) ? 1 : 0;
}

// check letter
int isLetter(char c)
{
    return (c < 65 && c > 90 && c < 97 && c > 122) ? 0 : 1;
}

// initializare graf
void initGraph(int graph[N][N])
{
    for (int i = 'A'; i <= 'Z'; i++)
        for (int j = 'a'; j <= 'z'; j++) {

            if (isLetter(i) && isLetter(j) && isUpper(i) && isLowerCons(j)) {   // i - majuscula, j - consoana mica
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
}

// afisare graf (matrice de adiacenta)
void printGraph(int graph[N][N])
{
    printf("\n");

    for (int i = 'A'; i <= 'Z'; i++) {
        for (int j = 'a'; j <= 'z'; j++)
            printf("%3d", graph[i][j]);

        printf("\n");
    }

    printf("\n");
}

// min key idx
int minKey(int key[], int visit[])
{
    int min = INT16_MAX;
    int min_idx;

    for (int v = 'A'; v <= 'z'; v++)
        if (!visit[v] && key[v] < min) {
            min = key[v];
            min_idx = v;
        }

    return min_idx;
}

// print MST
void printMST(int graph[N][N], int parent[])
{
    int sum = 0;

    printf("\n");

    for (int i = 'A'+1; i <= 'z'; i++) {
        printf("%c - %c : %d\n", i, parent[i], graph[parent[i]][i]);
        sum += graph[parent[i]][i];
    }

    printf("\nSuma: %d\n", sum);
}

// prim's MST
void primMST(int graph[N][N])
{
    int parent[N] = { 0 };
    int visit[N];
    int key[N];

    for (int i = 'A'; i < 'z'; i++) {
        key[i] = INT16_MAX;
        visit[i] = 0;
    }

    key['A'] = 0;
    parent['A'] = -1;

    for (int k = 'A'; k <= 'z'; k++) {
        int u = minKey(key, visit);

        visit[u] = 1;

        for (int v = 'A'; v <= 'z'; v++)
            if (graph[u][v] && !visit[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    printMST(graph, parent);
}


int main(int argc, char** argv)
{
    int graph[N][N] = { 0 };

    initGraph(graph);
    printGraph(graph);
    primMST(graph);

    return 0;
}