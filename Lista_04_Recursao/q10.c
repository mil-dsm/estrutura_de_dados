#include <stdio.h>
#include <math.h>

// Função de conversão de decimal para binário recursiva
// Entrada: número 'n', índice 'i' do caracter do binário, vetor 'A' de caracteres do binário e tamanho 'm' de bits desse vetor para o binário
// Saída número binário já construído 'num'
void bin(int n, int i, int A[]){
    if(n == 0){
        return;
    }
    A[i] = n % 2;
    bin(n/2, i-1, A);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int A[m];
    for(int i=0; i<m; i++){
        A[i] = 0;
    }
    bin(n, m-1, A);
    for(int i=0; i<m; i++){
        printf("%d", A[i]);
    }
}