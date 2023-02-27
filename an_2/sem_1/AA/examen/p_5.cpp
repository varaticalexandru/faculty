#include <bits/stdc++.h>

using namespace std;

vector <int> numNegative;

// tip de date (struct) - arbore binar ordonat (ABO / BST)
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// creeaza si returneaza un nou nod cu cheia data ca argument
Node* newNode(int key)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// returneaza predecesorul unui nod
Node* predecesor(Node* node)
{
    Node* temp = node->left;

    if (!temp)
        return NULL;
    
    while (temp->right)
        temp = temp->right;

    return temp;
}

// insereaza un nod(key) in arbore
Node* insert(Node* node, int key)
{
    // daca arborele e vid
    if (!node)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    return node;
}

// afiseaza arborele in inordine
void inOrder(Node* node)
{
    if (node) {
        inOrder(node->left);
        printf("%d ", node->key);
        inOrder(node->right);
    }
}

// gaseste toate numerele negative din arbore
void findNegative(Node* node)
{
    if (node) {
        findNegative(node->left);
        if (node->key < 0)
            numNegative.push_back(node->key);
        findNegative(node->right);
    }
}

// sterge un nod(key) din arbore
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
        if (!node->left) {
            Node* temp = node->right;
            free(node);
            return temp;
        }

        if (!node->right) {
            Node* temp = node->left;
            free(node);
            return temp;
        }

        // 2 fii
        Node* pred = predecesor(node);

        node->key = pred->key;
        deleteNode(node->left, pred->key);
    }

    return node;
}

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

    return 1 + max(height(node->left), height(node->right));
}

// verifica daca arborele este echilibrat in sens AVL
int isEch(Node* node)
{
    if (!node)
        return 1;
    
    int lh = height(node->left);
    int rh = height(node->right);

    if (abs(lh - rh) <= 1 && isEch(node->left) && isEch(node->right))
        return 1;
    
    return 0;
}

int main(int argc, char** argv)
{
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, -9);
    root = insert(root, 7);
    root = insert(root, -17);
    root = insert(root, 21);
    root = insert(root, 23);
    root = insert(root, 22);
    root = insert(root, 0);
    root = insert(root, 45);
    root = insert(root, -8);

    inOrder(root);

    printf("\n\n");

    findNegative(root);

    for (auto i : numNegative)
        printf("%d ", i);

    printf("\n\n");

    
    for (auto i : numNegative)
        deleteNode(root, i);

    inOrder(root);

    printf("\nEchilibrat in sens AVL: %d\n", isEch(root));

    return 0;
}