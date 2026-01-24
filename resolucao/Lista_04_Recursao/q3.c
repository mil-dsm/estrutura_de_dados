#include <stdio.h>

// Função do cálculo do fatorial duplo de um número n
// Entrada: inteiro n
// Saída: fatorial duplo de n
// Caso base: retorna 1 quando n é igual a 1
// Caso geral: retorna a multiplicação de n e a múlpicação dos números anteriores a esse
int fatorial_duplo(int n){
    if(n == 1){
        return 1;
    }
    if(n % 2 != 0){
        return n * fatorial_duplo(n-1);
    }
    return fatorial_duplo(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", fatorial_duplo(n));
}