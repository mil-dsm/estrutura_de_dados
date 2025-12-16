#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackcC.h"

struct node {
    char data;
    struct node *next;
};

struct stackc {
    size_t size;
    struct node *top;
};

// Criar pilha vazia.
Stackc* stackc_create(void) {
    Stackc *p = (Stackc*)malloc(sizeof(stackc));
    if(p == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    p->top = NULL;
    p->size = 0;
    return p;
}

// devolve o tamanho da pilha
size_t stackc_size(Stackc *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return p->size;
}

// retorna true se a pilha estiver vazia; ou false caso contrário
bool stackc_empty(Stackc *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return p->size == 0;
}

// Inserir um elemento no topo.
void stackc_push(Stackc *p, char val) {
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
void stackc_pop(Stackc *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(p->size == 0) {
        printf("fail: empty stackc.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = p->top;
    p->top = p->top->next;
    free(temp);
    p->size--;
}

// Retorna o valor do elemento no topo da pilha
char stackc_top(Stackc *p) {
    if(p == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(p->size == 0) {
        printf("fail: empty stackc.\n");
        exit(EXIT_FAILURE);
    }
    return p->top->data;
}

// Libera toda a memória que foi alocada
void stackc_free(Stackc *p) {
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
void stackc_swap(Stackc *p1, Stackc *p2) {
    if(p1 == NULL || p2 == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    stackc temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}