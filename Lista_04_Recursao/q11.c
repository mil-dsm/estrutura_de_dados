#include <stdio.h>

// Função potencia, com o propósito de calcular o valor de 'k' elevado a n
// Caso base: se n for igual a 0, retorna 1
// Caso geral: retorna 'k' multiplicado a recursão de 'k' e 'n-1'
// Entrada: base 'k' e potência 'n'
// Saída: o resultado da potência
int potencia(int k, int n){
    if(n == 0){
        return 1;
    }
    return k * potencia(k, n-1);
}

int main(){
    int k, n;
    printf("Digite a base: ");
    scanf("%d", &k);
    printf("Digite o expoente: ");
    scanf("%d", &n);
    printf("Resultado: %d\n", potencia(k, n));
}