#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(){
    int *p1, *p2;
    p1 = (int *) malloc(MAX * sizeof(int)); // malloc
    p2 = (int *) calloc(MAX, sizeof(int)); // calloc
    if(p1 != NULL && p2 != NULL){
        printf("MALLOC: [ ");
        for(int i=0; i<MAX; i++){
            printf("%d ", *(p1 + i));
        }
        printf("]\n");
        printf("CALLOC: [ ");
        for(int i=0; i<MAX; i++){
            printf("%d ", *(p2 + i));
        }
        printf("]\n");
    }
    else {
        printf("Erro: memoria insuficiente.\n");
    }
    free(p1);
    free(p2);
    return 0;
}