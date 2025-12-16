#include <stdio.h>

void incrementoVar(int);
void incrementoPtr(int *);

int main(){
    int a = 1, aux = a;
    incrementoVar(a);
    printf("Valor de a:\nAntes: %d\nDepois: %d\n", aux, a); // Saida: 1 e 1
    incrementoPtr(&a);
    printf("Valor de a: %d\nAntes: %d\nDepois: %d\n", aux, a); // Saida: 1 e 2
    int *pA;
    pA = &a;
    incrementoPtr(pA);
    printf("Valor de a:\nAntes: %d\nDepois: %d\n", aux, a); // Saida: 1 e 3
}

void incrementoVar(int x){
    x++;
}

void incrementoPtr(int *pX){
    (*pX)++;
}