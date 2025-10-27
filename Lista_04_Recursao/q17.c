#include <stdio.h>

// Função com o propósito de retorna o resultado da soma de todos os elementos de um vetor
// Caso base: se o tamanho for 0, logo, um vetor vazio, retorne 0
// Caso geral: retorne a soma entre o último elemento e a recursão entre o vetor 'A[0...n-1]' com tamanho reduzido de 'n-1'
// Entrada: vetor 'A[0...n-1]' e tamanho 'n'
// Saída: resultado da soma dos elementos do vetor
int soma(int A[], int n){
    if(n == 0){
        return 0;
    }
    return A[n-1] + soma(A, n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    printf("%d\n", soma(A, n));
}