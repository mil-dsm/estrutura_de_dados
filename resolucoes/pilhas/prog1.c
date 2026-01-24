/**
 * @file prog1.c
 * @author your name (you@domain.com)
 * @brief Implementações da estrutura de dados Stack usando seu TAD correspondente.
    Usando inteiros como tipo de dados.
 * @version 0.1
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackI.h"

// Função que recebe duas pilhas e coloca todos os valores da pilha 2, em ordem, para o início da pilha 1.
Stack* stack_concatena(Stack *p1, Stack *p2) {
    Stack *aux = stack_create();
    while(!stack_empty(p2)) {
        stack_push(aux, stack_top(p2));
        stack_pop(p2);
    }
    while(!stack_empty(aux)) {
        stack_push(p1, stack_top(aux));
        stack_pop(aux);
    }
    stack_free(aux);
    return p1;
}

// Função que recebe uma pilha como parâmetro e retorna uma cópia dessa pilha.
// Ao final da função, a pilha p recebida como parâmetro deve ter seu conteúdo original.
Stack* stack_clone(Stack *p) {
    Stack *p_clone = stack_create();
    Stack *aux = stack_create();

    while(!stack_empty(p)) {
        stack_push(aux, stack_top(p));
        stack_pop(p);
    }
    while(!stack_empty(aux)) {
        stack_push(p, stack_top(aux));
        stack_push(p_clone, stack_top(aux));
        stack_pop(aux);
    }

    stack_free(aux);
    return p_clone;
}

// Função para imprimir a pilha sem perder os elementos
void stack_print(Stack *p) {
    Stack *aux = stack_create();
    printf("[ ");
    while(!stack_empty(p)) {
        int val = stack_top(p);
        printf("%d ", val);
        stack_push(aux, val);
        stack_pop(p);
    }
    printf("]\n");
    while(!stack_empty(aux)) {
        stack_push(p, stack_top(aux));
        stack_pop(aux);
    }
    stack_free(aux);
}

// Testando implementações de Stack
int main(void) {
    Stack *p1 = stack_create();
    Stack *p2 = stack_create();

    // Inserindo valores em p1
    stack_push(p1, 1);
    stack_push(p1, 2);
    stack_push(p1, 3);

    // Inserindo valores em p2
    stack_push(p2, 4);
    stack_push(p2, 5);
    stack_push(p2, 6);

    printf("Pilha 1 antes da concatenação: ");
    stack_print(p1);
    printf("Pilha 2 antes da concatenação: ");
    stack_print(p2);

    // Testa stack_concatena
    stack_concatena(p1, p2);
    printf("Pilha 1 após concatenação com Pilha 2: ");
    stack_print(p1);

    // Testa stack_clone
    Stack *p1_clone = stack_clone(p1);
    printf("Clone da Pilha 1: ");
    stack_print(p1_clone);

    // Liberar memória
    stack_free(p1);
    stack_free(p2);
    stack_free(p1_clone);

    return 0;
}