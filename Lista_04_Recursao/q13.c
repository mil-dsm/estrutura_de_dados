#include <stdio.h>

// Função com propósito de calcular o resultado da multiplicação entre dois inteiros
// Caso base: se n2 for igual a 1, retorne 1
// Caso geral: calcule a soma de 'n1' e a recursão de 'n1' e 'n2-1'
// Entrada: dois númeoros inteiros 'n1' e 'n2'
// Saída: o resultado da multiplicação entre 'n1' e 'n2'
int multRec(int n1, int n2){
    if(n2 == 1){
        return n1;
    }
    return n1 + multRec(n1, n2-1);
}

int main(){
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    printf("%d\n", multRec(n1, n2));
}