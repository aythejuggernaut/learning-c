#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// individual node in the chain
typedef struct node_t {
    int data;
    struct node_t* next;
} node_t;

// Linked list data struture, which always holds the first node in our chain
typedef struct linkedlist {
    node_t* head;
} linkedlist_t;

// malloc a new linked list, and then returns a pointer to that linked list.
linkedlist_t* CreateLinkedListOfNItems(int length);

// create an empty linked list
linkedlist_t* CreateLinkedList();

// walk through linked list, and print all nodes
void PrintLinkedList(linkedlist_t* list);

// walk through linked list, and delete all nodes
void FreeLinkedList(linkedlist_t* list);

// create a new node_t, and add to the end of the linked list
void AppendToLinkedList(linkedlist_t* list, int data);

#endif