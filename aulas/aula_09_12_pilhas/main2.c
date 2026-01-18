#include <stdio.h>
#include <stdlib.h>
#include "StackVoid.h"

int main() {
    Stack *p = stack_create();

    for(int i = 1; i <=9; i++) {
        int *valor = (int*)malloc(sizeof(int));
        *valor = i;
        stack_push(p, valor);
    }

    while(!stack_empty(p)) {
        int *top = (int)stack_top(p);
        printf("%d\n", top);
        stack_pop(p);
    }
    stack_free(p);
    return 0;
}