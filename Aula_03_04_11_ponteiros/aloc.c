#include <stdio.h>
#include <stdlib.h>

void preencherArray(int *, int);
void imprimeArray(int *, int);

int main(){
    int n, *p;
    printf("Tamanho do array: ");
    scanf("%d", &n);
    p = (int *) malloc(n * sizeof(int));
    if(p == NULL){
        printf("Erro: sem memoria disponivel.\n");
    }
    printf("Valores do array: ");
    preencherArray(p, n);
    printf("Array formatado: ");
    imprimeArray(p, n);
    free(p);
    return 0;
}

void preencherArray(int *A, int n){
    for(int i=0; i<n; i++){
        scanf("%d", A + i);
    }
}

void imprimeArray(int *A, int n){
    printf("[ ");
    for(int i=0; i<n; i++){
        printf("%d ", *(A + i));
    }
    printf("]\n");
}