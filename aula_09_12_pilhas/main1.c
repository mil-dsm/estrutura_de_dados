#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Usar funcods dessa biblioteca como exercicio
#include "Stack.h"

// Funcao que recebe como entrada uma String e 
// inverte cada palavra da String
// e imprime as palavras invertidas no terminal
// Atencao: use uma pilha para resolver o problema
void inverter_string(char palavra[]) {
    Stack *p = stack_create();
    for(int i = 0; palavra[i] != '\0'; i++) {
        if(palavra[i] == ' ') {
            while(!stack_empty(p)) {
                char top = stack_top(p);
                stack_pop(p);
                printf("%c", top);
            }
            printf(" ");
        } else { // caso 2: palavra[i] eh um caracter diferente de vazio
            stack_push(p, palavra[i]);
        }
    }
    while(!stack_empty(p)) {
        char top = stack_top(p);
        stack_pop(p);
        printf("%c", top);
    }
    printf("\n");
}

// void inverter_string(char palavra[]) {
//     Stack *p = stack_create();
//     for(int i = 0; s[i] != '\0'; i++) {
//         if(palavra[i] == ' ') {
//             while(!stack_empty(p)) {
//                 char top = stack_top(p);
//                 stack_pop(p);
//                 printf("%c", top);
//             }
//             printf(" ");
//         } 
//         if(palavr[i+1] == '\0) {
//         }

//         else { // caso 2: palavra[i] eh um caracter diferente de vazio
//             stack_push(p, palavra[i]);
//         }
//     }
//     printf("\n");
// }

int main() {
    char palavra[] = "AMU ASAC";
    inverter_string(palavra);
}