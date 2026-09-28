#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>




// create_node(int value) 
// creates a single node which has a data = value and next = null 
// it returns a address of the node 

Node *create_node(int value) {

    Node *node;

    node = malloc(sizeof(Node));

    node->data = value;
    node->next = NULL;

    return node;

}




// push_front() inserts a new node containing the supplied value at the beginning of the linked list 
// and updates head to point to the new first node.




void push_front(Node **head, int value){

    Node *new_node = create_node(value);

    new_node->next = *head;

    *head = new_node;

}




//push_back() inserts a new node containing the supplied value at the end of the linked list and
// makes the new node the last node by setting its next pointer to NULL

// push_back(head, value)

// 1. Check whether the list is empty.

// 2. If empty:
//        create a node
//        make head point to it
//        return

// 3. Otherwise:
//        start at the first node

// 4. Traverse while current->next != NULL

// 5. current is now the last node

// 6. Create the new node

// 7. Set current->next to the new node

// 8. New node's next is already NULL


void push_back(Node **head, int value){

    if (*head == NULL){
        
        *head = create_node(value);

    }

    else {

        Node *current;

        current = *head;

        while (current->next != NULL)
        {
           current = current->next;
        }

        Node *new_last_node = create_node(value);

        current->next = new_last_node;
        
    }

}






