#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void PrintList(node* q)
{
    while (q != NULL) {
        printf(" %d ", q->data);
        q = q->next;
    }
}

void Push(node** head, int new_data)
{
    node* q = NULL;

    q = (node*)malloc(sizeof(node));
   
    q->data = new_data;
    q->next = (*head);
    (*head) = q;
}

void InsertAfter(node* prev_node, int new_data)
{
    node* q = NULL;

    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL\n");
        return;
    }

    q = malloc(sizeof(node));
    q->data = new_data;
    q->next = prev_node->next;
    prev_node->next = q;
}

void Append(node** head, int new_data)
{
    node* q = NULL;
    node* z = NULL;

    q = (node*)malloc(sizeof(node));

    q->data = new_data;
    q->next = NULL;

    if (*head == NULL) {
        *head = q;
        return;
    }
        

    z = *head;
    while (z->next != NULL) {
        z = z->next;
    }

    z->next = q;
    return;
}

void loh(node* lista)
{
    node* q = lista;
    int n;

    while (q->next)
    {
        q = q->next;
        n = q->data;
        q->data = lista->data;
        lista->data = n;
    }

    PrintList(lista);
}

node* function(node* lista) {
    node* q1 = NULL, * q2 = NULL, * q3 = NULL, * q4 = NULL;
    int m = lista->data;
    for (q1 = q2 = lista; q1 != NULL; q2 = q1, q1 = q1->next) {
        if (m <= q1->data) {
            m = q1->data;
            q3 = q2;
            q4 = q1;
        }
    }
    if (q3 != q4) {
        q3->next = q4->next;
        q4->next = lista;
    }
    return q4;
}


int main()
{
    node* head = NULL;
    node* q4 = NULL;

    Push(&head, 39);
    Push(&head, 8);
    Push(&head, 13);
    Push(&head, 46);
    Push(&head, 23);
    Push(&head, 30);
    Push(&head, 19);
    Push(&head, 2);
    Push(&head, 43);
    Push(&head, 12);
   

    q4 = function(head);
    PrintList(q4);


    _getch();
    return 0;
}
