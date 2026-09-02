#include <stdio.h>
#include <stdlib.h> // malloc/free and NULL
#include <string.h>
#include "linkedlist.h"

// malloc a new linked list, and then returns a pointer to that linked list.
linkedlist_t* CreateLinkedListOfNItems(int length) {
    // create my list
    linkedlist_t* newList = CreateLinkedList();

    node_t* current = NULL;

    for (int i = 1; i < length; i++) {
        node_t* newNode = malloc(sizeof(node_t));
        newNode->data = i;
        newNode->next = NULL;

        if (newList->head == NULL) {
          newList->head = newNode;
        } else {
            current->next = newNode;
        } 
        current = newNode;
    }
    
    return newList;
}

// create an empty linked list
linkedlist_t* CreateLinkedList() {
    linkedlist_t* newList = (linkedlist_t *)malloc(sizeof(linkedlist_t));
    newList->head = NULL;
    return newList;
}

// walk through linked list, and print all nodes
void PrintLinkedList(linkedlist_t* list) {
    node_t* iter = list->head;

    while (iter != NULL) {
        printf("data: %d\n", iter->data);
        iter = iter->next;
    }
}

// walk through linked list, and delete all nodes
void FreeLinkedList(linkedlist_t* list) {
    if (list == NULL)
        return;

    node_t* current = list->head; // current, points to the current node.
    if (current == NULL) {
        free(list);
        return;
    }

    node_t* next = current->next; // list->head->next
    while (current != NULL) {
        free(current);
        current = next;
        // ensure, that we're not at the end and then try to access 
        // (dereference) current->head
        if (current != NULL)
            next = current->next;
    }

    // last step is to free our linkedlist_t
    free(list);
}

// create a new node_t, and add to the end of the linked list
void AppendToLinkedList(linkedlist_t* list, int data) {
    // case 1: singly linked list is empty
    if (list->head == NULL) {
        node_t* newNode = malloc(sizeof(node_t));
        newNode->data = data;
        newNode->next = NULL;

        list->head = newNode;
    } else {
        // case 2: singly linked list is not empty
        node_t* iter = list->head; // iterator
        // advance our iterator, until we find the node, 
        // that has a 'next' of NULL
        while (iter->next != NULL) {
            // this will assign our iterator node to point to whatever its next 
            // 'node_t' is. this advances our iterator node, one node forward.
            iter = iter->next; 
        }
        // once we find the end of our singly linked list, create a new 
        // node here.
        node_t* newNode = malloc(sizeof(node_t));
        newNode->data = data;
        newNode->next = NULL;

        iter->next = newNode;
    }
}
