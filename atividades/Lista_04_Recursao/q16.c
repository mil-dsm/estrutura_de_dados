#include <stdio.h>

// Função com o propósito de retornar a soma dos digitos de um número
// Caso base: se o tamanho 'n' for igual à 0, retorne
// Caso geral: somar o resto da divisão de 'n' por 10 com a resursão de 'n/10'
// Entrada: número 'n'
// Saída: soma dos dígitos do número 'n'
int somaDigitos(int n){
    if(n == 0){
        return 0;
    }
    return (n%10) + somaDigitos(n/10);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", somaDigitos(n));
    return 0;
}