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

// Cria uma Stack vazia
Stack* stack_create(void) {
    Stack *nova_pilha = (Stack*)malloc(sizeof(Stack));
    if(nova_pilha == NULL) {
        printf("fail: allocation error.\n");
        return NULL;
    }
    nova_pilha->top = NULL;
    nova_pilha->size = 0;
    return nova_pilha;
}

// Retorna o tamanho da Stack
size_t stack_size(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return p->size;
}

// Retorna verdadeiro caso a Stack esteja vazia, e falso caso contrário
bool stack_empty(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return p->size == 0;
}

// Adiciona um elemento ao topo da Stack
void stack_push(Stack *p, int value) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    novo->data = value;
    novo->next = p->top;
    p->top = novo;
    p->size++;
}

// Remove o elemento no topo da Stack
void stack_pop(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = p->top;
    p->top = p->top->next;
    p->size--;
    free(temp);
}

// Retorna o valor que vai ser retiradp e retira da pilha
int stack_out(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = p->top;
    p->top = p->top->next;
    int data = temp->data;
    free(temp);
    p->size--;
    return data;
}

// Retorna o valor do elemento que esta no topo da Stack
int stack_top(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(p->size == 0) {
        printf("fail: empty stack.\n");
        return(EXIT_FAILURE);
    }
    return p->top->data;
}

// Libera a Stack
void stack_free(Stack *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    while(p->top != NULL) {
        Node *temp = p->top;
        p->top = p->top->next;
        free(temp);
    }
    free(p);
}

// Troca o conteudo de duas Stacks
void stack_swap(Stack *p1, Stack *p2) {
    if(p1 == NULL || p2 == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Stack aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}