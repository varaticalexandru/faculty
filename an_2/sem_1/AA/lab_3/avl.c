// C program to insert a node in AVL tree 
#include<stdio.h> 
#include<stdlib.h> 
#include <conio.h>

// An AVL tree node 
typedef struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height;
    int balance; // -2 -1 0 1 2 (valori posibile)
} Node; 

Node* root_ = NULL;
  
// A utility function to get maximum of two integers 
int max(int a, int b); 
  
// A utility function to get the height of the tree 
int height(Node *N) 
{ 
    if (N == NULL) 
        return 0; 

    return N->height;
} 
  
// A utility function to get maximum of two integers 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
/* Helper function that allocates a new node with the given key and 
    NULL left and right pointers. */
Node* newNode(int key) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 

    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL;

    node->height = 1;  // new node is initially added at leaf
    node->balance = 0;
    
    return(node); 
} 
  
// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
Node *rightRotate(Node *y) 
{ 
    Node *x = y->left; 
    Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
Node *leftRotate(Node *x)
{ 
    Node *y = x->right; 
    Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance(Node *N) 
{ 
    if (N == NULL) 
        return 0;

    return height(N->left) - height(N->right); 
} 
  
// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
Node* insert(Node* node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) {
        node->left  = insert(node->left, key);
    }
        
    
    else if (key > node->key) {
        node->right = insert(node->right, key); 
    }
        
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node);
    node->balance = balance;
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (node->balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (node->balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (node->balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (node->balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// A utility function to print preorder traversal 
// of the tree. 
// The function also prints height of every node 
void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d  ", root->key); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
  

void inOrder(Node *root) 
{ 
    if(root != NULL) 
    { 
        inOrder(root->left); 
	    printf("%d  ", root->key);
        inOrder(root->right); 
    } 
}

void postOrder(Node *root) 
{ 
    if(root != NULL) 
    { 
        postOrder(root->left);  
        postOrder(root->right);
        printf("%d ", root->key); 
    } 
}



Node* predecesor(Node* node)
{
    Node* aux = NULL;

    aux = node->left;

    if (!aux)
        return NULL;
    
    while (aux->right) {
        aux = aux->right;
    }

    return aux;
}

Node* succesor(Node* node)
{
    Node* aux = NULL;

    aux = node->right;

    if (!aux)
        return NULL;
    
    while (aux->left) {
        aux = aux->left;
    }

    return aux;
}


Node* cauta(Node* node, int key)
{

    if (node) {
        if (key > node->key)
            return cauta(node->right, key);
        if (key < node->key)
            return cauta(node->left, key);
        if (key == node->key)
            return node;
    }
    
    return NULL;
}

Node* parent(Node* node, int key)
{
    if (node->left)
        if (node->left->key == key)
            return node;

    if (node->right)
        if (node->right->key == key)
            return node;

    if (key < node->key)
        return parent(node->left, key);
    if (key > node->key)
        return parent(node->right, key);
        
    // return NULL;
}



// suprimare din topor (sterge tot subarborele)
// pornind de la postordine
void sterge_subarbore(Node* node)
{   
    Node* p = NULL;


    if (node)
    {
        p = parent(root_, node->key);

        sterge_subarbore(node->left);
        sterge_subarbore(node->right);

        if (p) {     // daca nu e radacina
            if (node->key < p->key)
                p->left = NULL;

            if (node->key > p->key)
                p->right = NULL; 
        }

        free(node);
    }
}

// topor
void suprima_key(Node* root, int key)
{
    sterge_subarbore(cauta(root, key));
}




// inlocuieste nodul sters cu succesorul
Node* suprima(Node* node, int key)
{
    // base case
    if (!node)
        return NULL;

    if (key < node->key)
        node->left = suprima(node->left, key);

    else if (key > node->key)
        node->right = suprima(node->right, key);

    else {  // key == node->key

        // 1 fiu sau 0 fii
        if (!node->left) {
            Node* aux = node->right;
            free(node);
            return aux;
        }
        else if (!node->right) {
            Node* aux = node->left;
            free(node);
            return aux;
        }

        // 2 fii
        // succesor
        Node* pred = predecesor(node);

        // copie key predecesor  -> node
        node->key = pred->key;

        // sterge predecesor 
        node->left = suprima(node->left, pred->key);
    }

    // daca nodul avea doar 1 fiu
    if (node == NULL)
      return NULL;
  
    // actualizeaza inaltime
    node->height = 1 + max(height(node->left),
                           height(node->right));
  
    // factorul de echilibru
    int balance = getBalance(node);
  
    // daca nodul este dezechilibrat, sunt 4 cazuri
  
    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
  
    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
  
    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
  
    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

/* Driver program to test above function*/
int main() 
{ 
  
  Node* p = NULL;
  Node *root = NULL;

  system("cls");
  
  /* Constructing tree given in the above figure */
    // root = insert(root, 10); 
    // root = insert(root, 20); 
    // root = insert(root, 30); 
    // root = insert(root, 40); 
    // root = insert(root, 50); 
    // root = insert(root, 25);
  
  /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */

   /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /        
       10      
  */

    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 10); 


  root_ = root;

  preOrder(root);
  printf("\n");

  root = suprima(root, 40);

  printf("\n");
  preOrder(root);
  printf("\n");


  return 0; 
} 


// parcurgere postordine
// suprimare
// in loc de height : factor de echilibru

// functie getHeight() : returneaza height-ul din nod / pe subarbore

// insertia modific: indicator spre parinte