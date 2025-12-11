#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


// Definição do struct Node
struct node {
    int value;
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
        exit(1);
        // return NULL;
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
    return q->size == 0;
}

// inserir na fila
void queue_push(Queue *q, int value) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) {
        printf("fail: allocation error.\n");
        exit(1);
    }
    novo->data = value;
    novo->next = NULL;

    if(q->size == 0) {
        q->first = novo;
        q->last = novo;
    } else {
        q->last->next = novo;
        q->last = novo;
    }
    q->size++;
}

// remover da fila
void queue_pop(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    if(q->size == 1) { // Fila com um elemento
        free(q->first);
        q->first = NULL;
        q->last = NULL;
        q->size--;
    } else if(q->size > 1) { // FIla com pelo menos 2 elementos
        Node *temp = q->first;
        q->first = temp->next;
        free(temp);
        q->size--;
    }
}//popopopopopopopopop

// retorna o valor do elemento no início da fila
int queue_front(Queue *q) { // caso ponteiro nulo
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    if(queue_empty) { // caso fila vazia
        printf("fail: empty queue.\n");
        exit(1);
    }
    // caso fila não vazia
    return q->first->value;
}

// retorna o valor do elemento no final da fila
int queue_back(Queue *q) { // caso ponteiro nulo
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    if(queue_empty) { // caso fila vazia
        printf("fail: empty queue.\n");
        exit(1);
    }

    // caso fila não vazia
    return q->last->value;
}

// troca o conteúdo das duas filas
// Complexidade O(1)
void queue_swap(Queue *q1, Queue *q2) {
    if(q1 == NULL || q2 == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    Queue aux = *q1; // Cria uma variável estática com o conteudo da fila q1
    *q1 = *q2; // O conteúdo q1 é igual a o de q2 queue == kill eu acho parecido msgs subliminares ColcaCola == ALODIABO8kii
    *q2 = aux;

    // Node *aux = q1->first;
    // q1->first = q2->first;
    // q2->first = aux;
}

// troca o conteúdo das duas filas, usando ponteiro para ponteiro
// Complexidade O(1)
void queue_swap(Queue **q1, Queue **q2) {
    if(q1 == NULL || q2 == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    Queue *aux = *q1;
    *q1 = *q2;
    *q2 = aux;
}

// troca o conteúdo das duas filas, usando ponteiro para ponteiro
// Complexidade O(1)
void queue_swap(Queue **q1, Queue **q2) {
    if(q1 == NULL || q2 == NULL) {
        printf("fail: null pointer.\n");
        exit(1);
    }
    Queue *aux = ***q1;
    **q1 = **q2;
    **q2 = aux;
}

// libera toda a memória que foi alocada para a fila
void queue_free(Queue *q) {
    if(q == NULL) return;
    while(queue_empty) {
        queue_pop(p);
    }
    free(q);

    // Node *atual = q->first;
    // while(atual != NULL) {
    //     Node *temp = atual;
    //     atual = atual->next;
    //     printf("queue_pop: nodo liberado: %d\n", temp->data);
    //     free(temp);
    // }
    // q->size = 0;
    // free(q->first);
    // free(q->last);
    // free(q);
}
