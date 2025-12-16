#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include "QueueStack.h"

int main() {
    Queue *fila = queue_create();
    int q, x, opc;

    scanf("%d", &q);
    while(q > 0) {
        scanf("%d", &opc);
        switch(opc) {
            case 1:
                scanf("%d", &x);
                queue_enfileirar(fila, x);
                break;
            case 2:
                queue_desenfileirar(fila);
                break;
            case 3:
                printf("%d\n", queue_get(fila));
                break;
        }
        q--;
    }

    queue_free(fila);
    return 0;
}