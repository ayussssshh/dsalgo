#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

typedef struct Node
{
   
    int data;
    struct Node *next;

} Node;


Node *create_node(int value);

void push_front(Node **head, int value);

void push_back(Node **head, int value);

void print_list(Node *head);




#endif // LINKEDLIST_H
