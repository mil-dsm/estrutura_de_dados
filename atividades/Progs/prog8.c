#include <stdio.h>

int somaVetor(int [], int);

int main(){
    int v[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    int n = sizeof(v) / 4;
    int result = somaVetor(v, n);
    printf("A soma dos termos do vetor eh: %d\n", result);
}

int somaVetor(int v[], int n){
    int soma = 0;
    int *p;
    int *const finalVetor = v + n;
    for(p = v; p < finalVetor; p++){
        soma += *p;
    }
    return soma;
}