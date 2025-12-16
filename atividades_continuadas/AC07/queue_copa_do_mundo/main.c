#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

int main(void) {
    Queue *q = queue_create();
    Queue *aux = queue_create();
    for(int i = 0; i < 16; i++) {
        queue_push(q, 'A'+ i);
    }
    for(int i = 0; i < 15; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        queue_push(aux, x);
        queue_push(aux, y);
    }
    while(!queue_empty(q)) {
        int x = queue_front(aux);
        queue_pop(aux);
        int y = queue_front(aux);
        queue_pop(aux);
        if(x > y) {
        }
    }
}