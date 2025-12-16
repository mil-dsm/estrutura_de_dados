/**
 * @file QueueStack.c
 * @author your name (you@domain.com)
 * @brief Implementação da estrutura de dados Queue com duas Stacks com dados inteiros.
 Não é um TAD aplicado corretamente. Quando ocorrre um erro, o programa é encerrado.
 Para testes.
 * @version 0.1
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include "QueueStack.h"

struct Queue {
    size_t size; // Apenas um número. Eu gosto de coisas simples. Meu professor me dá ansiedade, por isso
    // estou fazendo muitos exercício, mais do que o normal...
    // ...
    // ...
    // Continuando.
    Stack *in; // Deposito: usada para armazenar elementos
    Stack *out; // Prateleira: usada para tirar elementos
    // Se a prateleira estiver vazia, retiramos tudo do depósito e colocamos na prateleira
};

// cria fila vazia
Queue* queue_create(void) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    q->size = 0;
    q->in = stack_create();
    q->out = stack_create();
    return q;
}

// retorna o tamanho da fila
size_t queue_size(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return q->size;
}

// retorna true se e somente se a fila estiver vazia
bool queue_empty(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return q->size == 0;
}

// inserir na fila
/**
 * @brief Para inserir na fila, usaremos q->in. Essa pilha armazenará todos os valores da fila
 * na ordem inversa. Aqui usamos o depósito.
 * @param q 
 * @param value 
 */
void queue_push(Queue *q, int value) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    stack_push(q->in, value);
    q->size++;
}

// remover da fila
/**
 * @brief Aqui será usado a lógica da prateleira.
 * Caso a prateleira não estiver vázia, retiramos normalmente.
 * Como só é possível retirar o primeiro elemento de uma fila,
 * precisamos ter acesso ao primeiro elemento. Mas, o primeiro
 * elemento está na última posição de q->in e só temos acesso
 * ao início da fila.
 * Portanto, vamos inverter a ordem colocando tudo que está no
 * depósito na prateleira, isto é, q->out. Lá, o topo da lista
 * será o primeiro elemento, o qual estávamos querendo retirar.
 * @param q 
 */
void queue_pop(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(q->size == 0) {
        printf("fail: empty queue.\n");
        exit(EXIT_FAILURE);
    }
    if(stack_empty(q->out)) {
        while(!stack_empty(q->in)) {
            stack_push(q->out, stack_top(q->in));
            stack_pop(q->in);
        }
    }
    stack_pop(q->out); // Finalmente, retiramos o primeiro elemento que entrou na fila.
    q->size--;
}

// retorna o valor do elemento no início da fila
int queue_front(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(stack_empty(q->in) && stack_empty(q->out)) {
        printf("fail: empty queue.\n");
        exit(EXIT_FAILURE);
    }
    if(stack_empty(q->out)) {
        while(!stack_empty(q->in)) {
            stack_push(q->out, stack_top(q->in));
            stack_pop(q->in);
        }
    }
    return stack_top(q->out);
}

// retorna o valor do elemento no final da fila
int queue_back(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(stack_empty(q->in) && stack_empty(q->out)) {
        printf("fail: empty queue.\n");
        exit(EXIT_FAILURE);
    }
    if(stack_empty(q->in)) {
        while(!stack_empty(q->out)) {
            stack_push(q->in, stack_top(q->out));
            stack_pop(q->out);
        }
    }
    return stack_top(q->in);
}

// troca o conteúdo das duas filas
void queue_swap(Queue *q1, Queue *q2) {
    if(q1 == NULL || q2 == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    size_t size_aux = q1->size;
    q1->size = q2->size;
    q2->size = size_aux;

    Stack *aux = q1->in;
    q1->in = q2->in;
    q2->in = aux;

    aux = q1->out;
    q1->out = q2->out;
    q2->out = aux;
}

// libera toda a memória que foi alocada para a fila
void queue_free(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    
    stack_free(q->in);
    stack_free(q->out);
    free(q);
}