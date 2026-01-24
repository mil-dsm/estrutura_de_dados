/**
 * @file Stack.c
 * @author your name (you@domain.com)
 * @brief Implementação da estrutuda de dados Stack com a finalidade de usá-la para 
 * desenvolver a estrutura de dados Queue.
 * @version 0.1
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

struct node {
    int data;
    struct node *next;
};

struct stack {
    size_t size;
    struct node *top;
};

// Criar pilha vazia.
Stack* stack_create(void) {
    Stack *p = (Stack*)malloc(sizeof(Stack));
    if(p == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    p->top = NULL;
    p->size = 0;
    return p;
}

// devolve o tamanho da pilha
size_t stack_size(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return p->size;
}

// retorna true se a pilha estiver vazia; ou false caso contrário
bool stack_empty(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return p->size == 0;
}

// Inserir um elemento no topo.
void stack_push(Stack *p, int val) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    novo->data = val;
    novo->next = p->top;
    p->top = novo;
    p->size++;
}

// Remover o elemento do topo.
void stack_pop(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(p->size == 0) {
        printf("fail: empty stack.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = p->top;
    p->top = p->top->next;
    free(temp);
    p->size--;
}

// Retorna o valor do elemento no topo da pilha
int stack_top(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(p->size == 0) {
        printf("fail: empty stack.\n");
        exit(EXIT_FAILURE);
    }
    return p->top->data;
}

// Libera toda a memória que foi alocada
void stack_free(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    while(p->top != NULL) {
        Node *temp = p->top;
        p->top = temp->next;
        free(temp);
    }
    free(p);
}

// Troca o conteudo das duas pilhas
void stack_swap(Stack *p1, Stack *p2) {
    if(p1 == NULL || p2 == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Stack temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}