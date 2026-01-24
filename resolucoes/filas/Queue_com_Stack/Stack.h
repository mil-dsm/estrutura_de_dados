#ifndef STACK_H
#define STACK_H

// declaração dos tipos opacos
typedef struct node Node;
typedef struct stack Stack;

// Criar pilha vazia.
Stack* stack_create(void);

// devolve o tamanho da pilha
size_t stack_size(Stack *p);

// retorna true se a pilha estiver vazia; ou false caso contrário
bool stack_empty(Stack *p);

// Inserir um elemento no topo.
void stack_push(Stack *p, int val);

// Remover o elemento do topo.
void stack_pop(Stack *p);

// Retorna o valor do elemento no topo da pilha
int stack_top(Stack *p);

// Libera toda a memória que foi alocada
void stack_free(Stack *p);

// Troca o conteudo das duas pilhas
void stack_swap(Stack *p1, Stack *p2);

#endif