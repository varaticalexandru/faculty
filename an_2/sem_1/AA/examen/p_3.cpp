#include <bits/stdc++.h>

using namespace std;

/*
    1. Se va introduce urmatoarea secventa de chei numerice intr-un arbore binar ordonat (ABO): 1, -7, 4, 
32, 2, 22, -21, 2, 3, 45, 9, 90, 89, -22, 0. Se va respecta ordinea din secventa.

    a) sa se determine daca arborele binar ordonat obtinut in urma insertiilor este perfect echilibrat 
    sau nu.

    b) se vor sterge din ABO toate numerele impare si se va afisa rezultatul folosind parcurgerea 
    postordine
*/

// tip de date nod (struct)
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

vector <int> numImpare;


// returneaza maximum din 2 numere
int max(int a, int b)
{
    return (a >= b) ? a : b;
}

// returneaza inaltimea nodului
int height(Node* node)
{
    if (!node)
        return 0;
    
    return (1 + max(height(node->left), height(node->right)));
}

// creaza si returneaza un nod nou, cu cheia data ca argument
Node* newNode(int key)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// insereaza o cheie (nod) in arbore
Node* insert(Node* node, int key)
{
    // daca arborele este vid
    if (!node)
        return newNode(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // returnam nodul (neschimbat)
    return node;
}

// returneaza predecesorul unui nod (arbore)
Node* pred(Node* node)
{
    Node* temp = node->left;

    if (!temp)
        return NULL;
    
    while (temp->right)
        temp = temp->right;
    
    return temp;
}

// afiseaza toate numerele din arbore in inordine
void inOrder(Node* node)
{
    if (node) {
        inOrder(node->left);
        printf("%d ", node->key);
        inOrder(node->right);
    }
}

// verifica daca arborele este echilibrat AVL
int isEch(Node* node)
{
    // daca arborele e vid, returnam 1
    if (!node)
        return 1;

    // inaltimile subarborilor stand si drept
    int lh = height(node->left);
    int rh = height(node->right);

    if (abs(lh - rh) <= 1 && isEch(node->left) && isEch(node->right))
        return 1;

    // daca se ajunge aici, arborele nu este echilibrat
    return 0;
}


// gaseste toate numerele impare din arbore
void getNumImpare(Node* node)
{
    if (node) {
        getNumImpare(node->left);
        if (node->key % 2)
            numImpare.push_back(node->key);
        getNumImpare(node->right);
    }
}

// sterge un nod din arbore
Node* deleteNode(Node* node, int key)
{
    if (!node)
        return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);

    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {  // key == node->key

        // 1 fiu sau 0 fii
        if (!node->left) {  // n-are fiu stanga
            Node* temp = node->right;
            free(node);
            return temp;
        }
        else if (!node->right) {    // n-are fiu dreapta
            Node* temp = node->left;
            free(node);
            return temp;
        }

        // 2 fii

        // predecesor
        Node* predecesor = pred(node);

        // copiem continutul predecesorului in nod
        node->key = predecesor->key;

        // stergem predecesorul
        node->left = deleteNode(node->left, predecesor->key);
    }

    return node;
}

// returneaza adancimea celui mai din stanga nod-frunza
int findADepth(Node* node)
{
    int d = 0;

    while (node) {
        d++;
        node = node->left;
    }

    return d;
}


// verifica daca arborele este perfect echilibrat:
// 1) toate nodurile-frunza sunt la acelasi nivel
// 2) toate nodurile interne au cate 2 fii
int _isPerfect(Node* node, int d, int level=0)
{
    // daca arborele e vid
    if (!node)
        return 1;   // e perfect echilibrat

    // daca e nod-frunza
    if (!node->left && !node->right) {
        return (d == level+1);  // adancimea nodului trebuie sa fie ca si la celelalte frunze
    }

    // daca e nod interior si nu are un fiu
    if (!node->left || !node->right) {
        return 0;   // nu e echilibrat
    }

    // daca e nod interior si are ambii fii
    if (node->left && node->right) {
        // subarborele stand si drept trebuie sa fie perfect echilibrati
        return _isPerfect(node->left, d, level+1) &&
               _isPerfect(node->right, d, level+1);
    }
}

// wrapper a func. _isPerfect
int isPerfect(Node* node)
{
    int d = findADepth(node);
    return _isPerfect(node, d);
}



int main(int argc, char** argv)
{
    Node* root = NULL;

    root = insert(root, 1);
    root = insert(root, -7);
    root = insert(root, 4);
    root = insert(root, 32);
    root = insert(root, 2);
    root = insert(root, 22);
    root = insert(root, -21);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 45);
    root = insert(root, 9);
    root = insert(root, 90);
    root = insert(root, 89);
    root = insert(root, -22);
    root = insert(root, 0);

    inOrder(root);

    printf("\n");

    printf("\nEchilibru AVL: %d\n", isEch(root));
    printf("\nEchilibru perfect: %d\n", isPerfect(root));

    getNumImpare(root);

    printf("\nNumerele impare din arbore:\n");
    for (auto i : numImpare)
        printf("%d ", i);
    
    printf("\n\n");

    for (auto i : numImpare)
        root = deleteNode(root, i);

    inOrder(root);
    printf("\n");

    printf("\nEchilibru AVL: %d\n", isEch(root));
    printf("\nEchilibru perfect: %d\n", isPerfect(root));


    return 0;
}