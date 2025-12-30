#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "StackVoid.h"

struct node {
    void* value;
    struct node *next;
};

struct stack {
    Node *top;
    size_t size;
};

// cria uma pilha vazia
Stack* stack_create(void) {
    Stack *nova_pilha = (Stack*)malloc(sizeof(Stack));
    if(nova_pilha == NULL) {
        printf("fail: allocation failed.\n");
        return NULL;
    }
    nova_pilha->top = NULL;
    nova_pilha->size = 0;
    return nova_pilha;
}

// devolve o tamanho da pilha
size_t stack_size(Stack *p) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
        // Como pede o tamanho e não há inteiros válidos para indicar isso, acaba o programa
        // EXIT_FAILURE = 1
    }
    return p->size;
}

// retorna true se a pilha estiver vazia; ou false caso contrario
bool stack_empty(Stack *p) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return p->size == 0; // Retorna o resultado da comparacao
    // return (p->top == NULL); // NULL == 0, logo, o contrario de NULL eh porque tem elementos
}

// Empilha um elemento na pilha
void stack_push(Stack *p, void *value) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) {
        printf("fail: allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    novo->value = value;
    novo->next = p->top;
    p->top = novo;
    p->size++;
}

// Desempilha um elemento da pilha
void stack_pop(Stack *p) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(!stack_empty(p)) {
        Node *temp = p->top;
        p->top = temp->next;
        free(temp);
        p->size--;
    }
}

// Retorna o valor do elemento no topo da pilha
void* stack_top(Stack *p) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(stack_empty(p)) {
        printf("fail: empty stack.\n");
        exit(EXIT_FAILURE);
    }
    return p->top->value;
}

// Libera toda a memória que foi alocada
void stack_free(Stack *p) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    while(!stack_empty(p)) {
        stack_pop(p);
    }
    // while(p->top != NULL) {
    //     Node *temp = p->top;
    //     p = temp->next;
    //     free(temp);
    // }
    free(p);
}