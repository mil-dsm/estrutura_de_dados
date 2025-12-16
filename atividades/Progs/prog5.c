#include <stdio.h>

int main(){
    int v[3] = {10, 20, 30};
    printf("Tamanho do vetor 1 v[3] = {10, 20, 30}: %d\n", sizeof(v));
    printf("Endereco do primeiro elemento: %p\n", v); // Endereco do primeiro elemento
    printf("Valor apontado pelo vetor: %d\n", *v);

    // Apontar para o endereco de memoria de um vetor
    int vetor[3] = {1, 2, 3};
    int *ptr = vetor; // Nao precisa colocar o operador (&)
    // Isso faz que o ponteiro aponte para o endereco do primeiro elemento
    printf("Valor apontado pelo ponteiro ptr: %d\n", *ptr);
    int *ptr1 = &vetor[0]; // Isso eh o mesmo, forca ao resultado esperado
    printf("Valor apontado pelo ponteiro ptr1: %d\n", *ptr1);
}