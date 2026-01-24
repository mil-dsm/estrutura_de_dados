#include <stdio.h>

int fibonacci(int);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}

int fibonacci(int n){
    int ant = 0, atual = 1;
    for(int i = 2; i <= n; i++){
        int prox = ant + atual;
        ant = atual;
        atual = prox;
    }
    return n == 0 ? 0 : atual;
}