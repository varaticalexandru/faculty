// C program to insert a node in AVL tree 
#include<stdio.h> 
#include<stdlib.h> 
  
// An AVL tree node 
typedef struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    struct Node* parent;
    int height;
    int balance; // -2 -1 0 1 2 (valori posibile)
} Node; 
  
// A utility function to get maximum of two integers 
int max(int a, int b); 
  
// A utility function to get the height of the tree 
int height(Node *N) 
{ 
    if (N == NULL) 
        return 0; 

    return N->height;
} 

// int getHeight(Node* N)
// {
//     if (!N)
//         return 0;
//     else {
//         return max(height(N->left)
//     }
// }

// A utility function to get the ech factor of the node
int getEch(Node *N)
{

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
    node->parent = NULL;    // doar init

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
        node->left->parent = node;      // set parent
    }
        
    
    else if (key > node->key) {
        node->right = insert(node->right, key); 
        node->right->parent = node;     // set parent
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
        printf("%d ", root->key); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
  

void inOrder(Node *root) 
{ 
    if(root != NULL) 
    { 
        inOrder(root->left); 
	    printf("%d ", root->key); 
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

// suprimare din topor (sterge tot subarborele)
// pornind de la postordine
void sterge_subarbore(Node* root)
{   
    if (root != NULL)
    {
        sterge_subarbore(root->left);
        sterge_subarbore(root->right);

        if (root->parent) {     // daca nu e radacina
            if (root->key > root->parent->key)
            root->parent->right = NULL;

            if (root->key < root->parent->key)
            root->parent->left = NULL;
        }

        // daca e radacina
        free(root);
    }
    else return;
}

// void sterge(Node* root)
// {
//     if (!root->left && !root->right) {
//         if (root->parent->key > root->key)
//         root->parent->right = NULL;
    
//     else
//         root->parent->left = NULL;

//     free(root);
//     }

//     if (root->left && root->right) 
//         if (root->parent->key > root->key)
//             root->parent->right = predecesor(root ;
//         else
//             parent->left = predecesor->root;
    

//     // cazul cand unul singur din fii este nenul
//     if (root->left && root->right) {
//         // se substituie cu primul fiu
//     }

    
    
// }

// sterge doar nodul solicitat, nu tot subarborele
// void sterge_nod(Node* root)
// {


//     if (root != NULL)
//     {
//        Node* p = NULL;

//        if (p = predecesor(root)) {
//             root = p;

//        }

//     }

//     return;
// }



Node* predecesor(Node* root)
{
    // if (root) {
    //     return predecesor(root->right);
    // }

    Node* crt = root->left;

    if (!root || !root->left)
        return NULL;

    //return predecesor(crt->right);

    while (crt->right)
        crt = crt->right;

    return crt;
}

Node* cauta(Node* root, int key)
{
    if (root == NULL)
        return root;
    if (key > root->key)
        return cauta(root->right, key);
    if (key < root->key)
        return cauta(root->left, key);
    if (key == root->key)
        return root;
    else
        return NULL;
}

void suprima_key(Node* root, int key)
{
    sterge_subarbore(cauta(root, key));
}

/* Driver program to test above function*/
int main() 
{ 
  Node *root = NULL;
  Node* p = NULL;

  system("cls");
  
  /* Constructing tree given in the above figure */
  root = insert(root, 10); 
  root = insert(root, 20); 
  root = insert(root, 30); 
  root = insert(root, 40); 
  root = insert(root, 50); 
  root = insert(root, 25);
  root = insert(root, 73);
  
  /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */

  printf("Inorder traversal of the constructed AVL"
         " tree is \n"); 
  inOrder(root);
  printf("\n");

  printf("Preorder traversal of the constructed AVL"
         " tree is \n"); 
  preOrder(root);
  printf("\n");

  printf("Postorder traversal of the constructed AVL"
         " tree is \n"); 
  postOrder(root);
  printf("\n");

//  p = predecesor(root->left->left);
//  printf("\npredecesor: %d\n", p->key);


    //   suprima_key(root, 50);

    //   printf("\n\nInorder traversal of the constructed AVL"
    //          " tree is \n"); 
    //   inOrder(root);
    //   printf("\n");


  //p = predecesor(root);
  //printf("\npredecesorul lui %d: %d\n", root->key, p->key);

  return 0; 
} 


// parcurgere postordine
// suprimare
// in loc de height : factor de echilibru

// functie getHeight() : returneaza height-ul din nod / pe subarbore

// insertia modific: indicator spre parinte
