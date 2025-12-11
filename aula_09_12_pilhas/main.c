#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
    Stack *p = stack_create(); // Cria pilha vazia

    for(int i = 0; i <= 9; i++) {
        stack_push(p, 'a'+i);
    }

    while(!stack_empty(p)) {
        char t = stack_top(p);
        printf("%c\n", t);
        stack_pop(p);
    }

    stack_free(p);
}
// gcc -Wall -Wextra -std=c11 main.c Stack.c Stack.h