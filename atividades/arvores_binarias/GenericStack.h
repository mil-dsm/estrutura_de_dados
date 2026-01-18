#ifndef GENERIC_STACK_H
#define GENERIC_STACK_H
#include <stdio.h>
#include <stdbool.h>

// declaração dos tipos opacos
typedef struct node Node;
typedef struct stack Stack;

// declaração de um ponteiro para função que destrói o dado
typedef void (*DestroyFunction)(void*);

// cria uma pilha vazia
Stack* stack_create(DestroyFunction function);

// devolve o tamanho da pilha
size_t stack_size(Stack *p);

// retorna true se a pilha estiver vazia; ou false caso contrário
bool stack_empty(Stack *p);

// Empilha um elemento na pilha
void stack_push(Stack *p, void* value);

// Desempilha um elemento da pilha
void stack_pop(Stack *p);

// Retorna o valor do elemento no topo da pilha
void* stack_top(Stack *p);

// Libera toda a memória que foi alocada
void stack_free(Stack *p);

#endif