#include <stdio.h>

// Função com propósito de calcular a multiplicação russa entre os números 'A' e 'B'
// Caso base: se 'A' for igual a 1, retorna B
// Caso geral: se 'A' for ímpar retorne a soma de 'B' com a recursão de multRussa de 'A/2' e 'B*2'
// Se 'A' for par, retorne a recursão de multRussa de 'A/2' e 'B*2'
// Entrada: inteiros 'A' e 'B'
// Saída: resultado da multiplicação russa entre 'A' e 'B'
int multRussa(int A, int B){
    if(A == 1){
        return B;
    }
    if(A % 2 != 0){
        return B + multRussa(A/2, B*2);
    }
    return multRussa(A/2, B*2);
}

int main(){
    int A, B;
    scanf("%d%d", &A, &B);
    printf("%d\n", multRussa(A, B));
}