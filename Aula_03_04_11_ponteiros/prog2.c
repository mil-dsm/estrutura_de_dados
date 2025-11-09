#include <stdio.h>

// Manipulando ponteiros

int main(){
    int count = 10;
    int *p;
    p = &count;
    printf("Conteudo de p: %p\n", p);
    printf("Conteudo apontado por p: %d\n", *p);
    *p = 12;
    printf("Conteudo apontado por p: %d\n", *p);
    printf("Conteudo apontado de count: %d\n", count);
}