#include <stdio.h>
#include <stdbool.h>

// Retorna true se e somenete se a sequência for bem formada;
boolena eh_bemformada(char seq[]) {
    Stack *p = stack_create();
    for(int i = 0; seq[i] != '\0'; i++) {
        if(seq[i] == '[' || seq[i] == '(') {
            stack_push(p, '[');
        } else if(seq[i] == ']') {
            if(stack_empty(p) == false) {
                stack_pop(p);
            } else {
                return false;
            }
        } else if(seq[i] == ')') {
            stack_
        }
    }
}