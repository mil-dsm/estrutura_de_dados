#include <stdio.h>
#include "Queue.h"

int main() {
    // cria fila vazia
    Queue *fila = queue_create(); 
    Queue *q = queue_create();

    // insere elementos na fila
    for(int i = 10; i <= 23; i++) {
        queue_push(fila, i);
    }

    // insere elementos na fila
    for(int i = 70; i <= 77; i++) {
        queue_push(q, i);
    }

    // faz o swap(troca) das filas
    queue_swap_v3(&fila, &q);

    // remove os elementos um a um e imprime na tela
    while(!queue_empty(fila)) {
        int valor = queue_front(fila);
        printf("%d ", valor);
        queue_pop(fila);
    }
    printf("\n");

    queue_free(fila); // libera memória
    queue_free(q); // libera memória
    return 0;
}