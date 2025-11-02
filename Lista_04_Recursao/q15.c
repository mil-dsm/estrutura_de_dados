#include <stdio.h>

// Função com o propósito de verificar se existem no mínimo 2 termos de um vetor 'A[0...n-1]' em que a sua soma seja igual a um inteiro 'x'
// Caso base: se 'n' for igual a 1, ou seja, o vetor tem tamanho 1, retorne falso
// Caso geral: se o último número do vetor/subvetor somado ao número apontado pelo índice 'i' for igual a x, retorne verdadeiro
// Se o índice 'i' co seguir chegar ao primeiro número do vetor/subvetor mesmo após as comparações, terá uma recursão entre o
// vetor 'A[0...n-1]' de tamanho reduzido 'n-1', o número 'x' e o índice 'i' para começar as interações.
// Se 
int soma(int A[], int n, int x, int i){
    if(n == 1){
        return 0;
    }
    if(A[n-1] + A[i] == x){
        return 1;
    }
    if(i == 0){
        return soma(A, n-1, x, n-2);
    }
    return soma(A, n, x, i-1);
}

int main(){
    int n, x;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int A[n];
    printf("Digite o vetor: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    printf("Digite o x: ");
    scanf("%d", &x);
    if(soma(A, n, x, n-2))
        printf("\nExiste par com soma %d\n", x);
    else
        printf("\nNao existe par com soma %d\n", x);
}