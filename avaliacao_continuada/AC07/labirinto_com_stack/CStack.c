#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "CStack.h"

struct cnode {
    Posicao value;
    struct cnode *next;
};

struct cstack {
    CNode *top;
    size_t size;
};

// cria uma pilha vazia
CStack* cstack_create(void) {
    CStack *p = (CStack*) malloc(sizeof(CStack));
    if(p == NULL) {
        printf("erro: falha na alocação.\n");
        return NULL;
    }
    p->size = 0;
    p->top = NULL;
    return p;
}

// devolve o tamanho da pilha
size_t cstack_size(CStack *p) {
    if(p == NULL) {
        printf("erro: falha na alocação.\n");
        exit(EXIT_FAILURE);
    }
    return p->size;
}

// retorna true se a pilha estiver vazia; ou false caso contrário
bool cstack_empty(CStack *p) {
    if(p == NULL) {
        printf("erro: falha na alocação.\n");
        exit(EXIT_FAILURE);
    }
    return (p->size == 0) ? true : false;
}

// Empilha um elemento no topo da pilha
void cstack_push(CStack *p, Posicao value) {
    if(p == NULL) {
        printf("erro: falha na alocação.\n");
        exit(EXIT_FAILURE);
    }
    CNode *novo = (CNode*) malloc(sizeof(CNode));
    if(novo == NULL) {
        printf("erro: falha de alocação.\n");
        return;
    }
    novo->value = value;
    novo->next = p->top;
    p->top = novo;
    p->size++;
}

// Desempilha o elemento no topo da pilha
void cstack_pop(CStack *p) {
    if(p == NULL) {
        printf("erro: falha na alocação.\n");
        exit(EXIT_FAILURE);
    }
    if(!cstack_empty(p)) {
        CNode *aux = p->top;
        p->top = p->top->next;
        free(aux);
        p->size--;
    }
}

// Retorna o valor do elemento no topo da pilha
Posicao cstack_top(CStack *p) {
    if(p == NULL) {
        printf("erro: falha na alocação.\n");
        exit(EXIT_FAILURE);
    }
    if(cstack_empty(p) == true) {
        printf("erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    return p->top->value;
}

// Libera toda a memória que foi alocada
void cstack_free(CStack *p) {
    if(p == NULL) return;
    while(cstack_empty(p) == false) {
        cstack_pop(p);
    }
    free(p);
}