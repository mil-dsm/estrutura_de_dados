#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
    Node *head = dList_create();

    for(int i = 9; i >= 1; i--) {
        dList_push_front(head, i);
    }

    dList_print(head);
    return 0;
}