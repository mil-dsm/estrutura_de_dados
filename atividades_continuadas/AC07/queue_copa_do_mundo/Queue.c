#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

struct node {
    char data;
    struct node *next;
};

struct queue {
    size_t size;
    struct node *first;
    struct node *last;
};

// cria fila vazia
Queue* queue_create(void) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    q->size = 0;
    q->first = NULL;
    q->last = NULL;
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
void queue_push(Queue *q, char value) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
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
        exit(EXIT_FAILURE);
    }
    if(q->size == 0) {
        printf("fail: empty queue.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = q->first;
    q->first = temp->next;
    free(temp);
    if(q->first == NULL) {
        q->last = NULL;
    }
    q->size--;
}

// retorna o valor do elemento no início da fila
char queue_front(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(q->size == 0) {
        printf("fail: empty queue.\n");
        exit(EXIT_FAILURE);
    }
    return q->first->data;
}

// retorna o valor do elemento no final da fila
char queue_back(Queue *q) {
    if(q == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(q->size == 0) {
        printf("fail: empty queue.\n");
        exit(EXIT_FAILURE);
    }
    return q->last->data;
}

// troca o conteúdo das duas filas
void queue_swap(Queue *q1, Queue *q2) {
    if(q1 == NULL || q2 == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Queue aux = *q1;
    *q1 = *q2;
    *q2 = aux;
}

// libera toda a memória que foi alocada para a fila
void queue_free(Queue *q) {
    if(q != NULL) {
        Node *aux = q->first;
        while(aux != NULL) {
            Node *temp = aux->next;
            free(aux);
            aux = temp;
        }
        free(q);
    }
}