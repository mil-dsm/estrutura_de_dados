#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
    Node *p = list_create();
    list_print(p);

    for(int i = 1; i <= 10; i++) {
        p = list_push_back(p, i);
    }
    for(int i = 33; i <= 35; i++) {
        p = list_push_front(p, i);
    }
    list_print(p);
    list_free_rec(p);

    return 0;
}