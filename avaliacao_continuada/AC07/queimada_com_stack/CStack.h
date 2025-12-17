#ifndef CSTACK_H
#define CSTACK_H

// declaração dos tipos opacos
typedef struct {
    int l;
    int c;
} Posicao;

typedef struct cnode CNode;
typedef struct cstack CStack;

// cria uma pilha vazia
CStack* cstack_create(void);

// devolve o tamanho da pilha
size_t cstack_size(CStack *p);

// retorna true se a pilha estiver vazia; ou false caso contrário
bool cstack_empty(CStack *p);

// Empilha um elemento no topo da pilha
void cstack_push(CStack *p, Posicao value);

// Desempilha o elemento no topo da pilha
void cstack_pop(CStack *p);

// Retorna o valor do elemento no topo da pilha
Posicao cstack_top(CStack *p);

// Libera toda a memória que foi alocada
void cstack_free(CStack *p);

#endif