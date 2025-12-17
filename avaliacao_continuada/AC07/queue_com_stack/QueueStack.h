#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H

typedef struct queue Queue;

/*Ideia geral
in recebe todos os enqueue
out fornece todos os dequeue
só transfere in → out quando out está vazia
o topo da out é sempre a frente da fila*/

// Cria fila vazia
Queue* queue_create(void);

// Libera a memória da fila.
void queue_free(Queue *q) ;

// Retorna o tamanho da fila
size_t queue_size(Queue *q);

// Retorna true se e somente se a fila estiver vazia
bool queue_empty(Queue *q);

// 1 x: Enfileirar o elemento x no final da fila.
void queue_enfileirar(Queue *q, int x);

// 2: Retirar da fila o elemento na frente da fila.
void queue_desenfileirar(Queue *q);

// 3: Mostre o elemento na frente da fila.
int queue_get(Queue *q);

#endif