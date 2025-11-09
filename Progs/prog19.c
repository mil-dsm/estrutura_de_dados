#include <stdio.h>
#include <stdlib.h>

void preencher(int *, int);

int main(){
    int *p1;
    p1 = (int *) calloc(5, sizeof(int));
    *(p1+3) = 10;
    for(int i=0; i<5; i++){ // Imprimi apenas 0s
        printf("Endereco de p%d: %p. Valor de p%d: %d\n", i+1, (p1+i), i+1, *(p1+i));
        // printf("Endereco de p%d: %p. Valor de p%d: %d\n", i+1, p1[i], i+1, p1[i]);
    }
    free(p1);
    
}

void preencher(int *vet, int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = i * 10;
    }
}


/*int *p2;
    p2 = (int *) malloc(5 * sizeof(int));
    free(p2);
    for(int i=0; i<5; i++){ // Imprimi apenas 0s
        printf("Endereco de p%d: %p. Valor de p%d: %d\n", i+1, (p1+i), i+1, *(p1+i));
        // printf("Endereco de p%d: %p. Valor de p%d: %d\n", i+1, p1[i], i+1, p1[i]);
    }*/