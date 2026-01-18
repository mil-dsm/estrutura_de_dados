#include <stdio.h>

int main(){
    void *pp; // Ponteiro generico
    float x = 23.45;

    // Recebe o endereco em float
    pp = &x;
    printf("Endereco em pp: %p\n", pp);

    // Imprime o valor apontado por pp
    printf("Valor apontado: %.2f\n", *((float*)pp));
}