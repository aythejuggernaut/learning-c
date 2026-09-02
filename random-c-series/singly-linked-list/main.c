#include <stdio.h>
#include "linkedlist.h"

void unitTest1(void)
{
    linkedlist_t* mylist = CreateLinkedListOfNItems(7);

    PrintLinkedList(mylist);

    FreeLinkedList(mylist);
}

void unitTest2(void)
{
    linkedlist_t* mylist = CreateLinkedList();
    FreeLinkedList(mylist);
}

int main(void)
{
    unitTest1();
    unitTest2();
    return 0;
}