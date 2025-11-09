#include <stdio.h>

int main(){
    // Declara uma variavel int contendo o valor 10
    int count = 10;
     
    // Declara um ponteiro para int e atribui ao ponteiro
    // o endereco da variavel int
    int *p;
    p = &count;
    printf("Conteudo de p: %p\n", p);
    //Imprime 10
    printf("Conteudo apontado por p: %d\n", *p);
    
    // Atribui um novo valor a posicao de memoria apontada por p
    *p = 12;

    // As duas linhas abaixo imprimem o numero 12 na tela
    printf("Conteudo apontado por p: %d\n", *p);
    printf("Conteudo de count: %d\n", count);

    return 0;
}