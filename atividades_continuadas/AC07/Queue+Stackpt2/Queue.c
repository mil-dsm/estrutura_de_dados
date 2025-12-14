#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include "Queue.h"

struct node {
    int data;
    struct node *next;
};

/*Ideia geral
in recebe todos os enqueue
out fornece todos os dequeue
só transfere in → out quando out está vazia
o topo da out é sempre a frente da fila*/

struct queue {
    size_t size;
    Stack *in; // Contem a fila invertida
    Stack *out; // Começa vazia, serve como pilha para ordenar a pilha in
};

// Cria fila vazia
Queue* queue_create(void) {
    Queue *nova_fila = (Queue*)malloc(sizeof(Queue));
    if(nova_fila == NULL) {
        printf("fail: allocation error.\n");
        return NULL;
    }
    nova_fila->in = stack_create();
    nova_fila->out = stack_create();;
    if(nova_fila->in == NULL || nova_fila->out == NULL) {
        printf("fail: allocation error.\n");
        return NULL;
    }
    return nova_fila;
}

// Libera a memória da fila.
void queue_free(Queue *q) {
    if(q != NULL) {
        stack_free(q->in);
        stack_free(q->out);
        free(q);
    }
}

// Retorna o tamanho da fila
size_t queue_size(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return q->size;
}

// Retorna true se e somente se a fila estiver vazia
bool queue_empty(Queue *q){
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    return q->size == 0;
}

// 1 x: Enfileirar o elemento x no final da fila.
void queue_enfileirar(Queue *q, int x) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    // Armazena de forma desordenada o elemento na pilha q->in
    stack_push(q->in, x);
    q->size++;
}

// 2: Retirar da fila o elemento na frente da fila.
void queue_desenfileirar(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(stack_empty(q->in) && stack_empty(q->out)) { // caso fila vazia
        printf("fail: empty queue.\n");
        exit(1);
    }
    if(stack_empty(q->out) == true) {
        // Enquanto a fila desordenada tem elementos, tira um elemento de in e ordena em outra fila
        while(stack_empty(q->in) == false) {
            int v = stack_out(q->in);
            stack_push(q->out, v);
        }
    }
    stack_pop(q->out);
    q->size--;
}

// 3: Mostre o elemento na frente da fila.
int queue_get(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    if(stack_empty(q->in) && stack_empty(q->out)) { // caso fila vazia
        printf("fail: empty queue.\n");
        exit(1);
    }
    // Se q->out for vazia e q->in não, faz a ordenação da fila
    if(stack_empty(q->out) == true) {
        while(stack_empty(q->in) == false) {
            int data = stack_out(q->in);
            stack_push(q->out, data);
        }
    }
    // Quando q->out não for vazia, devolve o elemento no topo da pilha
    return stack_top(q->out);
}