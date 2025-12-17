#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

// Definição do struct Node
struct node {
    char value;
    struct node *next;
};

// Definição do struct queue
struct queue {
    struct node *first;
    struct node *last;
    size_t size;
};

// cria fila vazia
Queue* queue_create(void) {
    Queue *nova_fila = (Queue*)malloc(sizeof(Queue));
    if(nova_fila == NULL) {
        printf("fail: empty queue.\n");
        return NULL;
    }
    nova_fila->first = NULL;
    nova_fila->last = NULL;
    nova_fila->size = 0;
    return nova_fila;
}

// retorna o tamanho da fila
size_t queue_size(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    return q->size;
}

// retorna true se e somente se a fila estiver vazia
bool queue_empty(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    return (q->size == 0) ? true : false;
}

// inserir na fila
void queue_push(Queue *q, char value) {
    if(q == NULL){
        printf("fail: null pointer.\n");
        exit(1);
    }
    Node* node = malloc(sizeof(*node));
    if(node == NULL){
        printf("fail: allocation error.\n");
        exit(1);
    }
    node->value = value;
    node->next = NULL;
    if(queue_empty(q)){
        q->last = node;
        q->first = q->last;
    }else{
        q->last->next = node;
        q->last = node;
    }
    q->size++;
}

// remover da fila: FIFO: first-in first-out
void queue_pop(Queue *q) {
    if(q == NULL){
        printf("fail: null pointer.\n");
        exit(1);
    }
    if(q->size == 1) { // Fila com 1 elemento
        free(q->first);
        q->first = NULL;
        q->last = NULL;
        q->size--;
    } else if(q->size > 1) { // Fila com pelo menos 2 elementos
        Node *x = q->first;
        q->first = x->next;
        free(x);
        q->size--;
    }
}

// retorna o valor do elemento no início da fila
char queue_front(Queue *q) {
    if(q == NULL){ // caso ponteiro nulo
        printf("fail: null pointer.\n");
        exit(1);
    }
    if(queue_empty(q)) { // caso fila vazia
        printf("fail: empty queue.\n");
        exit(1);
    } 
    // caso fila não vazia
    return q->first->value;
}

// retorna o valor do elemento no final da fila
char queue_back(Queue *q) {
    if(q == NULL){ // caso ponteiro nulo
        printf("fail: null pointer.\n");
        exit(1);
    }
    if(queue_empty(q)) { // caso fila vazia
        printf("fail: empty queue.\n");
        exit(1);
    } 
    // caso fila não vazia
    return q->last->value;
}

// troca o conteúdo das duas filas
// Complexidade: O(1)
void queue_swap_v1(Queue *q1, Queue *q2) {
    Queue aux = *q1;
    *q1 = *q2;
    *q2 = aux;
}

void queue_swap_v2(Queue **q1, Queue **q2) {
    Queue aux = **q1;
    **q1 = **q2;
    **q2 = aux;
}

void queue_swap_v3(Queue **q1, Queue **q2) {
    Queue *aux = *q1;
    *q1 = *q2;
    *q2 = aux;
}

// libera toda a memória que foi alocada para a fila
void queue_free(Queue *q) {
    if(q == NULL) return;
    while(!queue_empty(q)) {
        char v = queue_front(q);
        queue_pop(q);
    }
    free(q);
}