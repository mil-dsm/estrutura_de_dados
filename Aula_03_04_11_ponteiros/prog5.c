#include <stdio.h>

int main(){
    int *ptr = NULL;
    *ptr = 2023; // Erro: falha de segmentacao
    printf("Valor apontado por ptr = %d\n", *ptr);

    if(ptr != NULL){
        *ptr = 2023; // ptr nao eh nulo
        printf("Valor apontado por ptr = %d\n", *ptr);
    }else{
        printf("Ponteiro nulo.\n");
    }
}