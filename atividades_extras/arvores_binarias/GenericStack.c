#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "GenericStack.h"

struct node {
    void* value;
    struct node *next;
};

struct stack {
    Node *top;
    size_t size;
    DestroyFunction destroy;
};

// cria uma pilha vazia
Stack* stack_create(DestroyFunction function) {
    Stack *p = (Stack*) malloc(sizeof(Stack));
    if(p == NULL) {
        printf("fail: allocation failed.\n");
        return NULL;
    }
    p->top = NULL;
    p->size = 0;
    if(function != NULL) {
        p->destroy = function;
    } else {
        p->destroy = NULL;
    }
    return p;
}

// devolve o tamanho da pilha
size_t stack_size(Stack *p) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return p->size;
}

// retorna true se a pilha estiver vazia; ou false caso contrário
bool stack_empty(Stack *p) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return (p->top == NULL);
}

// Empilha um elemento na pilha
void stack_push(Stack *p, void* value) {
    if(p == NULL) {
        printf("error: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *novo = (Node*) malloc(sizeof(Node));
    if(novo == NULL) {
        printf("error: allocation error.\n");
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
        Node *aux = p->top;
        p->top = p->top->next;
        if(p->destroy != NULL) {
            p->destroy(aux->value);
        }
        free(aux);
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
    free(p);
}