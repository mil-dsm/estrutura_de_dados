#include <stdio.h>

int somaVetor(int *, int);

int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    int *p;
    p = v;
    printf("%d\n", somaVetor(p, n));
}

int somaVetor(int *p, int n){
    int soma = 0;
    for(int i=0; i<n; i++){
        soma += *(p + i);
    }
    return soma;
}