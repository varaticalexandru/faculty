#include <iostream>

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <vector>

using namespace std;

/*
    1. Se va introduce urmatoarea secventa de chei numerice intr-un arbore binar ordonat (ABO): 12, -7, 
45, 32, 2, 22, 1, 2, 3, 4, 9, 90, 89, 225, 0. Se va respecta ordinea din secventa.

    a) sa se determine daca arborele binar ordonat obtinut in urma insertiilor este echilibrat in sens 
AVL sau nu.
    b) se vor sterge din ABO toate numerele pare si se va afisa rezultatul folosind parcurgerea 
inordine.

*/

// vector de numere pare
vector <int> numPare;

// tipul de date nod (struct)
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// returneaza predecesorul nodului/arborelui
Node* pred(Node* node)
{
    Node* temp = node->left;

    if (!temp)
        return NULL;

    while (temp->right)
        temp = temp->right;

    return temp;
}

// returneaza predecesorul nodului/arborelui
Node* succ(Node* node)
{
    Node* temp = node->right;

    if (!temp)
        return NULL;

    while (temp->left)
        temp = temp->left;
    
    return temp;
}


// returneaza maximum din 2 numere
int max(int a, int b)
{
    return (a >= b) ? a : b;
}

// aloca si returneaza un nod nou, cu cheia transmisa ca argument
Node* newNode(int key)
{
    Node* node = NULL;

    node = (Node*)malloc(sizeof(Node));
    
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// insereaza un nod la arbore, returneaza noul root al arborelui
Node* insert(Node* node, int key)
{
    // daca root-ul e NULL, returnam noul nod creat
    if (!node)
        return newNode(key);
    
    // in caz contrar parcurgem recursiv arborele
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    // returnam node ptr-ul (neschimbat)
    return node;
}

// parcurge arborere in ordine
void inOrder(Node* node)
{
    if (node) {
        inOrder(node->left);
        printf("%d ", node->key);
        inOrder(node->right);
    }
}

// returneaza inaltimea arborelui (numarul de noduri pe cel mai lung drum in jos)
int getHeight(Node* node)
{
    if (!node)
        return 0;
    
    // daca arborele nu e vid, inaltimea = 1 + max(inaltimea subarborelui stang si drept)
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

// 1 - echilibrat, 0 - neechilibrat (AVL)
int isBalanced(Node* node)
{   
    // daca arborele e vid
    if (!node)
        return 1;   // echilibrat

    // inaltimile subarborilor stang si drept
    int lh = getHeight(node->left);
    int rh = getHeight(node->right);

    if (abs(lh - rh) <= 1 && isBalanced(node->left) && isBalanced(node->right))
        return 1;
    
    // daca se ajunge aici - neechilibrat
    return 0;
}

// gaseste toate nr. pare
void getNumPare(Node* node)
{
    if (node) {
        getNumPare(node->left);
        if (node->key % 2 == 0)
            numPare.push_back(node->key);
        getNumPare(node->right);
    }
}

// sterge un numar din arbore
Node* deleteNode(Node* node, int key)
{
    // base case (daca nodul e NULL, returnam nodul)
    if (!node)
        return node;
    
    // daca cheia < cheia nodului
    if (key < node->key)
        node->left = deleteNode(node->left, key);

    // daca cheia > cheia nodului
    else if (key > node->key)
        node->right = deleteNode(node->right, key);

    // cheia == cheia nodului
    else {
        // 1 fiu sau 0 fii
        if (!node->left) {  // nu are fiu stanga
            Node* temp = node->right;
            free(node);
            return temp;
        }
        else if (!node->right) {    // nu are fiu dreapta
            Node* temp = node->left;
            free(node);
            return temp;
        }

        // 2 fii

        // predecesor
        Node* predecesor = pred(node);
        
        // copiem continutul predecesorului in nod
        node->key = predecesor->key;

        // stegem predecesorul recursiv (setam)
        node->left = deleteNode(node->left, predecesor->key);
    }

    return node;
}

int main (int argc, char** argv)
{
    Node* root = NULL;

    root = insert(root, 12);
    root = insert(root, -7);
    root = insert(root, 45);
    root = insert(root, 32);
    root = insert(root, 2);
    root = insert(root, 22);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 90);
    root = insert(root, 89);
    root = insert(root, 225);
    root = insert(root, 0);

    inOrder(root);

    printf("\n%d", isBalanced(root));

    getNumPare(root);

    if (numPare.empty())
        printf("\nNu exista numere pare in arbore\n");
    else {
        printf("\nNumerele pare din arbore: \n");
        for (auto i : numPare)
            printf("%d ", i);
    }

    printf("\n");

    for (auto i : numPare) {
        root = deleteNode(root, i);
    }

    inOrder(root);

    return 0;
}