#include <stdio.h>

int main(){
    int vetor[3] = {1, 2, 3};
    int *ponteiro = vetor;
    printf("Elementos do vetor: 1, 2, 3\n");
    // Note que, quando muda o elemento, sobe 4 bits
    printf("Endereco de v[0]: %p\n", ponteiro);
    ponteiro = &vetor[1];
    printf("Endereco de v[1]: %p\n", ponteiro);
    ponteiro = &vetor[2];
    printf("Endereco de v[2]: %p\n", ponteiro);

    // Operacoes com ponteiros
    ponteiro = vetor;
    printf("Valor apontado pelo ponteiro: %d\n", *ponteiro);
    printf("Valor apontado pelo ponteiro: %d\n", *(ponteiro + 1));
    printf("Valor apontado pelo ponteiro: %d\n", *(ponteiro + 2));
    printf("Valor de vetor[1] (antes): %d\n", vetor[1]);
    *(ponteiro + 1) = 10;
    printf("Valor de vetor[1] (depois): %d\n", vetor[1]);
}