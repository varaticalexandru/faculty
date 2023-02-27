#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct node {
    int info;
    struct node* left;
    struct node* right;
} node;

node* CreateNode(int x)
{
    node* n = (node*)malloc(sizeof(node));

    n->info = x;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

node* AddNode(node* n, int x)
{
    if (!n)
        return CreateNode(x);

    if (x < n->info)
        n->left = AddNode(n->left, x);

    if (x > n->info)
        n->right = AddNode(n->right, x);
    
    return n;
}

void PreOrder(node* n)
{
    if (n) {
        printf("%d ", n->info);
        PreOrder(n->left);
        PreOrder(n->right);
    }
}

void InOrder(node* n)
{
    if (n) {
        InOrder(n->left);
        printf("%d ", n->info);
        InOrder(n->right);
    }
}

void PostOrder(node* n)
{
    if (n) {
        PostOrder(n->left);
        PostOrder(n->right);
        printf("%d ", n->info);
    }
}

node* Search(node* n, int x)
{
    int found;

    found = 0;
    while (n && !found) {
        if (n->info == x)
            found = 1;
        else if (x < n->info)
            n = n->left;
        else
            n = n->right;
    }

    return n;
}

node* Search_(node* n, int x)
{
    if (!n)
        return n;

    if (x < n->info)
        n = Search_(n->left, x);
    else if (x > n->info)
        n = Search_(n->right, x);
    else
        return n;
}

void DelNode(node* n, int x)
{
    node* q = Search(n, x);

    if (!q) {
        printf("Eroare. Nod inexistent in arbore.\n");
        return;
    }

    if (!q->left){
        
    }

}

void DelMin(node* n)
{
    node* temp;

    if (n)
        if (n->left->left)
            DelMin(n->left);
        else {
            temp = n->left;
            n->left = n->left->right;

            free(temp);
        }

    return;
}

void DelMax(node* n)
{
    node* temp;

    if (n)
        if (n->right->right)
            DelMin(n->right);
        else {
            temp = n->right;
            n->right = n->right->right;

            free(temp);
        }

    return;
}

int main()
{
    node* root = NULL;
    int h;

    system("cls");

    root = AddNode(root, 4);
    root = AddNode(root, 2);
    root = AddNode(root, 3);
    root = AddNode(root, 5);
    root = AddNode(root, 0);
    root = AddNode(root, 1);

    printf("InOrder:\n");
    InOrder(root);

    //printf("\n%d\n", DelMin(root));
    DelMax(root);

    printf("\nInOrder:\n");
    InOrder(root);


    getchar();
    return 0;
}