#include <stdio.h>

void imprimir(int n){
    if(n == 0){
        printf("0\n");
        return;
    }
    if(n % 2 == 0){
        printf("%d ", n);
    }
    imprimir(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    imprimir(n);
}