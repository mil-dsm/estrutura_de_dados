#ifndef STACK_H
#define STACK_H

typedef struct node Node;
typedef struct stack Stack;

// Cria uma Stack vazia
Stack* stack_create(void);

// Retorna o tamanho da Stack
size_t stack_size(Stack *p);

// Retorna verdadeiro caso a Stack esteja vazia, e falso caso contrário
bool stack_empty(Stack *p);

// Adiciona um elemento ao topo da Stack
void stack_push(Stack *p, int value);

// Remove o elemento no topo da Stack
void stack_pop(Stack *p);

// Retorna o valor que vai ser retiradp e retira da pilha
int stack_out(Stack *p);

// Retorna o valor do elemento que esta no topo da Stack
int stack_top(Stack *p);

// Libera a Stack
void stack_free(Stack *p);

// Troca o conteudo de duas Stacks
void stack_swap(Stack *p1, Stack *p2);

#endif