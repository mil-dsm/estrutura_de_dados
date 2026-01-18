#include <stdio.h>

int main(){
    void *pp;
    int p2 = 10;

    // Ponteiro generico recebe o endereco de um inteiro
    pp = & p2;

    // Tenta acessar o conteudo do ponteiro generico
    printf("Conteudo: %d\n", *pp); // Erro

    // Converte o ponteiro generico pp para (int *)
    // antes de acessar o conteudo
    printf("Conteudo: %d\n", *(int *) pp); // Correto
}