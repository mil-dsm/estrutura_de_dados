#include <stdio.h>
#include <stdlib.h>

// Uso da funcao free()

int main(){
    int *ptr;
    ptr = (int *) malloc(50 * sizeof(int));
    if(ptr == NULL){
        printf("Erro : memoria insuficiente.\n");
        exit(1);
    }
    for(int i=0; i<50; i++){
        ptr[i] = i + 1;
    }
    for(int i=0; i<50; i++){
        printf("%d\n", i[ptr]);
    }
    free(ptr); // Libera a memoria alocada
    return 0;
}