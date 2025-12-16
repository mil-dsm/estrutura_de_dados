/**
 * @file prog1.c
 * @author your name (you@domain.com)
 * @brief Implementações da estrutura de dados Queue usando seu TAD.
 * @version 0.1
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

// Função que recebe duas filas f1 e f2, e transfere
// alternadamente os elementos de f1 e f2 para uma nova fila f_res.
// Ao final da função, as filas f1 e f2 vão estar vazias, e a fila.
// f_res vai conter todos os valores originalmente em f1 e f2.
void combina_filas(Queue *f1, Queue *f2, Queue *f_res) {
    while(!queue_empty(f1) && !queue_empty(f2)) {
        queue_push(f_res, queue_front(f1));
        queue_pop(f1);
        
        queue_push(f_res, queue_front(f2));
        queue_pop(f2);
    }
    while(!queue_empty(f1)) {
        queue_push(f_res, queue_front(f1));
        queue_pop(f1);
    }
    while(!queue_empty(f2)) {
        queue_push(f_res, queue_front(f2));
        queue_pop(f2);
    }
}

// Função que recebe um fila q e imprime seus valores.
// Ao final da função, a fila q estará vazia.
void queue_print(Queue *q) {
    printf("[ ");
    while(!queue_empty(q)) {
        printf("%d ", queue_front(q));
        queue_pop(q);
    }
    printf("]\n");
}

int main() {
    Queue *f1 = queue_create();
    Queue *f2 = queue_create();
    Queue *f3 = queue_create();
    for(int i = 0; i < 5; i++) {
        queue_push(f1, i + 1);
    }
    for(int i = 0; i < 6; i++) {
        queue_push(f2, (i + 1) * 10);
    }
    queue_print(f1);
    queue_print(f2);
    queue_print(f3);
    
    return 0;
}  