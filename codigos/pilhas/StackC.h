#ifndef STACKC_H
#define STACKC_H

// declaração dos tipos opacos
typedef struct node Node;
typedef struct stack Stackc;

// Criar pilha vazia.
Stackc* stack_create(void);

// devolve o tamanho da pilha
size_t stack_size(Stackc *p);

// retorna true se a pilha estiver vazia; ou false caso contrário
bool stack_empty(Stackc *p);

// Inserir um elemento no topo.
void stack_push(Stackc *p, char val);

// Remover o elemento do topo.
void stack_pop(Stackc *p);

// Retorna o valor do elemento no topo da pilha
char stack_top(Stackc *p);

// Libera toda a memória que foi alocada
void stack_free(Stackc *p);

// Troca o conteudo das duas pilhas
void stack_swap(Stackc *p1, Stackc *p2);

#endif