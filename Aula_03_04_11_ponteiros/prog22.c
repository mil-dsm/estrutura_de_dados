#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(){
    int *ptr;
    ptr = (int *) malloc(MAX * sizeof(int));

    // Verifica se a alocao foi bem sucedida
    if(ptr == NULL){
        printf("Nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE); // Aborta o programa
    }

    free(ptr);
    return 0;
}